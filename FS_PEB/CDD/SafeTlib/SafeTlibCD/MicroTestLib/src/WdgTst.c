

/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2015)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**   $FILENAME   : WdgTst.c $                                                 **
**                                                                            **
**   $CC VERSION : \main\49 $                                                 **
**                                                                            **
**   $DATE       : 2018-03-12 $                                               **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  AUTHOR    : DL-BLR-ATV-STC                                                **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : This file contains watchdog latent fault metric tests      **
**                                                                            **
**  REFERENCE(S) :                                                            **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

#include "WdgTst.h"
#include "SmuInt.h"
#include "Mcal.h"
#include "Mtl_Trap.h"
#include "Sl_Ipc.h"
#include "IfxScu_reg.h"
#include "IfxCpu_reg.h"
#include "IfxSbcu_reg.h"
#include "IfxSrc_reg.h"
#include "IfxSrc_bf.h"
/*******************************************************************************
**                      Local Macro Definitions                               **
*******************************************************************************/

/* number of timeout ticks used for watchdog timeout test
This count is sufficient irrespective of the frequency, compiler
and its optimization options
*/
#define WDG_TST_TICKS               ( 20u )

#define WDG_SBE_TRAP_CLASS          ( 4u )     /* trap class for SBE */
#define WDG_SBE_TRAP_TIN            ( 3u )     /* trap TIN for SBE */
#define WDG_NO_TRAP                 ( 0u )     /* no trap is expected */

#define WDG_STATIC_PASSWORD         ( (uint8)0u  )  /* Static Password */
#define WDG_AUTOMATIC_PASSWORD      ( (uint8)1u  )  /* Automatic Password Sequencing */

/* SMU Alarm Group Index, Alarm Index and Status Bit definitions:  */
#define SMU_SCU_WDT_GRP             ( ((uint8)SMU_ALARM_GROUP3)  )

#define SMU_SCU_WDT_WDTALL          ( (uint8)SMU_ALARM_21 )
#define SMU_SCU_WDT_WDTCPU0         ( (uint8)SMU_ALARM_18 )
#define SMU_SCU_WDT_WDTS            ( (uint8)SMU_ALARM_17 )
#define SMU_SCU_SPB_SPBERR          ( (uint8)SMU_ALARM_31 )

#define SMU_SCU_WDT_WDTS_STS        ( (uint32)1u << SMU_SCU_WDT_WDTS )
#define SMU_SCU_WDT_WDTALL_STS      ( (uint32)1u << SMU_SCU_WDT_WDTALL )
#define SMU_SCU_SCU_SPB_SPBERR      ( (uint32)1u << SMU_SCU_SPB_SPBERR )

#define SMU_SCU_ALM_COMBINED_STS    ( SMU_SCU_WDT_WDTS_STS | \
                              SMU_SCU_WDT_WDTALL_STS | SMU_SCU_SCU_SPB_SPBERR)

#define WDG_CON1_DISABLEWDG_FREQPRESCALER256  ( 0x0000000Cu )
#define WDG_CON1_ENABLEWDG_FREQPRESCALER256   ( 0x00000004u )
#define WDG_CON1_DISBALEWDGBIT_MASK           ( 0x00000008u )

/* Clear SRC_BCUSPBSBSRC Service Request Flag */
#define WDGTST_BCUSPBSBSRC_MASK            ((unsigned_int)0x293F1CFFU)
#define WDGTST_BCUSPBSBSRC_CLEAR_BITS      ((unsigned_int)0x02000000U)

/*******************************************************************************
**                      Local Type Definitions                                 *
*******************************************************************************/

/* container for backup data and test data shared among several sub tests */
typedef struct WdgTst_DataType
{
    Smu_AlarmActionType     CpuWdgAlrmBackup;       /* backup storage */
    Smu_AlarmActionType     AllWdgAlrmBackup;
    Smu_AlarmActionType     SpbAccAlrmBackup;
    uint32                  WdtxCon1Backup;
    uint32                  WdtxCon0Backup;
    /* working storage throughout the tests */
    uint32*                 TstSignature;
    Ifx_SCU_WDTCPU*         WdtPtr;
    uint32                  AlarmMask;
    uint8                   AlarmId;
    sint8                   WdgType;
} WdgTst_DataType;


/*******************************************************************************
**                        Exported object definitions                          *
*******************************************************************************/

/*******************************************************************************
**                        Local object definitions                             *
*******************************************************************************/

#define IFX_WDG_START_SEC_VAR_32BIT_ASIL_B
#include "Ifx_MemMap.h"

static uint32 WdgTst_ExpectedTrap;
static uint32 WdgTst_SbeTrapSeen;

#define IFX_WDG_STOP_SEC_VAR_32BIT_ASIL_B
#include "Ifx_MemMap.h"

/*******************************************************************************
**                        Imported function declarations                       *
*******************************************************************************/

/*******************************************************************************
**                        Local function prototypes                            *
*******************************************************************************/
#define IFX_WDG_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
 static Sl_TstRsltType  WdgTst_lInit                ( WdgTst_DataType* const TestDataPtr, uint32 TestId );
 static Sl_TstRsltType  WdgTst_lRestore             ( const WdgTst_DataType* const TestDataPtr, uint32 TestId  );
 static Sl_TstRsltType  WdgTst_lEndinitTst          ( const WdgTst_DataType* const TestDataPtr, uint32 TestId  );
 static Sl_TstRsltType  WdgTst_lProgFlowTst         ( const WdgTst_DataType* const TestDataPtr, uint32 TestId  );

 static Sl_TstRsltType  WdgTst_lWdgPfTimeoutTst     ( const WdgTst_DataType* const TestDataPtr, uint32 TestId  );
 static Sl_TstRsltType  WdgTst_lWdgPfNoErrorTst     ( const WdgTst_DataType* const TestDataPtr, uint32 TestId  );
 static Sl_TstRsltType  WdgTst_lWdgPfWrongAccTimeTst( const WdgTst_DataType* const TestDataPtr, uint32 TestId  );
 static Sl_TstRsltType  WdgTst_lWdgPfWrongPwdTst    ( const WdgTst_DataType* const TestDataPtr, uint32 TestId, uint8 PasswordType );

 static boolean         WdgTst_lDAETrap             (const uint32 TIN);

/*******************************************************************************
**                    Local inline function definitions                        *
*******************************************************************************/

 /* local small inline helper functions to access proper watchdog
  *                                                (CPU or safety watchdog) */

 /*----------------------------------------------------------------------------*/
 LOCAL_INLINE void WdgTst_lResetEndinit( sint8 WdgType )
 {
    (WdgType == -1) ?
        Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT) :
        Mcal_ResetENDINIT();
 }

 /*----------------------------------------------------------------------------*/
 LOCAL_INLINE void WdgTst_lSetEndinit( sint8 WdgType )
 {
    (WdgType == -1) ?
        Mcal_SetSafetyENDINIT_Timed() :
        Mcal_SetENDINIT();
 }

 /*----------------------------------------------------------------------------*/
 LOCAL_INLINE void WdgTst_lWdtModifyAccess( sint8 WdgType, const uint32 NewPassword, const uint32 NewReload )
 {
    (WdgType == -1) ?
        Mcal_SafetyModifyAccess (NewPassword, NewReload) :
        Mcal_CpuWdtModifyAccess (NewPassword, NewReload);
 }

 /*----------------------------------------------------------------------------*/
 LOCAL_INLINE void WdgTst_lWdtCheckAccess( sint8 WdgType, const uint32 CheckPassword, const uint32 CheckReload )
 {
    (WdgType == -1) ?
        Mcal_SafetyCheckAccess (CheckPassword, CheckReload) :
        Mcal_CpuWdtCheckAccess (CheckPassword, CheckReload);
 }

 /*----------------------------------------------------------------------------*/
 LOCAL_INLINE uint32 WdgTst_lWdtPwSequence( sint8 WdgType, const uint32 Password )
 {
    return ((WdgType == -1) ?
                Mcal_SafetyPwSequence (Password) :
                Mcal_CpuWdtPwSequence (Password)
            );
 }


/*******************************************************************************
**                    Configuration error checking                            *
*******************************************************************************/

/*******************************************************************************
**                         Function definitions                                *
*******************************************************************************/



 /******************************************************************************************
 ** Traceability: [cover parentID= <id_1>, <id_2>]                                        **
 **                                                                                       **
 ** Syntax : Sl_TstRsltType WdgTst_WdgCpuTst(Sl_ParamSetIndex ParamSetIndex,              **
 **                                          uint8            TstSeed,                    **
 **                                          uint32*          TstSignature)               **
 **                                                                                       **
 ** Description : Latent fault metric tests for the Cpu watchdog                          **
 **                                                                                       **
 ** [/cover]                                                                              **
 **                                                                                       **
 ** Service ID: None                                                                      **
 **                                                                                       **
 ** Sync/Async: Synchronous                                                               **
 **                                                                                       **
 ** Reentrancy: Non reentrant                                                             **
 **                                                                                       **
 ** Parameters (in) : ParamSetIndex - Identifies the parameter set to be used             **
 **                                   for test execution                                  **
 **                   TstSeed - Seed to be used for generating the signature              **
 **                                                                                       **
 ** Parameters (out): TstSignature - Test signature generated by the test                 **
 **                                                                                       **
 ** Return value    :  Sl_TstRsltType                                                     **
 **                    CPU_WDG_SUCCESS              - no error occurred                   **
 **                    CPU_WDG_INVPARAMETER         - test index out of range             **
 **                    CPU_WDG_NOTEXECUTED          - test not fully executed             **
 **                    CPU_WDG_SMU_STATEERR         - SMU not in RUN state                **
 **                    CPU_WDG_SMU_GETALMSTSERR     - get SMU alarm status failed         **
 **                    CPU_WDG_SMU_ALMSTSERR        - already an SMU alarm pending        **
 **                    CPU_WDG_SMU_GETALMACTIONERR  - get SMU alarm action failed         **
 **                    CPU_WDG_SMU_SETALMACTIONERR  - set SMU alarm action failed         **
 **                    CPU_WDG_SMU_CLRALMSTSERR     - clear SMU alarm status failed       **
 **                    CPU_WDG_ENDINIT_NOBLOCK      - protected write not blocked         **
 **                    CPU_WDG_ENDINIT_NOWRITE      - readback of written register failed **
 **                    CPU_WDG_ENDINIT_NOTIMEOUT    - no endinit timeout alert signaled   **
 **                    CPU_WDG_PF_NOTIMEOUTALERT    - no timeout overflow signaled by HW  **
 **                    CPU_WDG_PF_UNEXPERROR        - unexpected access error signaled    **
 **                    CPU_WDG_PF_UNEXPALARM        - unexpected SMU alarm signaled       **
 **                    CPU_WDG_PF_TIMEIGNORED       - wrong access not signaled           **
 **                                                                                       **
 ******************************************************************************************/
Sl_TstRsltType  WdgTst_WdgCpuTst(const   Sl_ParamSetType ParamSetIndex,
                                 const   uint8 TstSeed,
                                 uint32* const TstSignature)

{
    Sl_TstRsltType Result = CPU_WDG_INVPARAMETER;

    /* Initialize Test Signature  */
    *TstSignature = (uint32) CRC32((uint32)TEST_ID_CPU_WDG_TST, (uint32)TstSeed);

    /* check valid parameter set index */
    if ( ParamSetIndex < WDGCPU_TST_CFG_PARAM_COUNT )
    {
        Result = CPU_WDG_SMU_STATEERR;

        /* Check whether SMU is in RUN state */
        if (SMU_RUN_STATE == Smu_GetSmuState())
        {
            Sl_TstRsltType ResultTmp;
            WdgTst_DataType WdgTst_CtrlSet;
            uint8 CurrCpu  = (uint8)MFCR(CPU_CORE_ID) & 0x7u;      /* get my current running core (0,1,2) */

            /* initialize Test data set */
            WdgTst_CtrlSet.TstSignature = TstSignature;
            WdgTst_CtrlSet.WdgType      = (sint8) CurrCpu;
            WdgTst_CtrlSet.WdtPtr       = (volatile Ifx_SCU_WDTCPU*) &((volatile Ifx_SCU_WDTCPU*)((volatile void *)&SCU_WDTCPU0_CON0))[CurrCpu];
            WdgTst_CtrlSet.AlarmId      = (SMU_SCU_WDT_WDTCPU0 + CurrCpu);
            WdgTst_CtrlSet.AlarmMask    = (uint32)1u << WdgTst_CtrlSet.AlarmId;

            /* Save SMU alarm and watchdog settings */
            Result = WdgTst_lInit( &WdgTst_CtrlSet, (uint32)TEST_ID_CPU_WDG_TST );

            /* execute Endinit test */
            if ( CPU_WDG_SUCCESS == Result )
            {
                Result = WdgTst_lEndinitTst( &WdgTst_CtrlSet, (uint32)TEST_ID_CPU_WDG_TST );

                /* start program flow test only if ENDINIT test was successful and program flow test is enabled */
                if ( (CPU_WDG_SUCCESS == Result)  &&
                   ( WdgTstCpu_ConfigRoot[ParamSetIndex].WdgTstPflowMonEn == TRUE) )
                {
                    Result = WdgTst_lProgFlowTst( &WdgTst_CtrlSet, (uint32)TEST_ID_CPU_WDG_TST );
                }
            }

            if (CPU_WDG_SMU_RESOURCELOCKED != Result)
            {
              /* restore SMU alarm and watchdog settings */
              ResultTmp = WdgTst_lRestore( &WdgTst_CtrlSet, (uint32)TEST_ID_CPU_WDG_TST );
              if ( CPU_WDG_SUCCESS != ResultTmp )
              {
                Result = ResultTmp;
              }
            }
        }
    }

    /* add final test result to signature */
    *TstSignature = (uint32) CRC32(*TstSignature, Result);

    return (Result);
}


/**********************************************************************************************
 ** Traceability: [cover parentID= <id_1>, <id_2>]                                           **
 **                                                                                          **
 ** Syntax : Sl_TstRsltType WdgTst_WdgSafetyTst(Sl_ParamSetIndex ParamSetIndex,              **
 **                                          uint8            TstSeed,                       **
 **                                          uint32*          TstSignature)                  **
 **                                                                                          **
 ** Description : Latent fault metric tests for the safety watchdog                          **
 **                                                                                          **
 ** [/cover]                                                                                 **
 **                                                                                          **
 ** Service ID: None                                                                         **
 **                                                                                          **
 ** Sync/Async: Synchronous                                                                  **
 **                                                                                          **
 ** Reentrancy: Non reentrant                                                                **
 **                                                                                          **
 ** Parameters (in) : ParamSetIndex - Identifies the parameter set to be used                **
 **                                   for test execution                                     **
 **                   TstSeed - Seed to be used for generating the signature                 **
 **                                                                                          **
 ** Parameters (out): TstSignature - Test signature generated by the test                    **
 **                                                                                          **
 ** Return value    :  Sl_TstRsltType                                                        **
 **                    SAFETY_WDG_SUCCESS              - no error occurred                   **
 **                    SAFETY_WDG_INVPARAMETER         - test index out of range             **
 **                    SAFETY_WDG_NOTEXECUTED          - test not fully executed             **
 **                    SAFETY_WDG_SMU_STATEERR         - SMU not in RUN state                **
 **                    SAFETY_WDG_SMU_GETALMSTSERR     - get SMU alarm status failed         **
 **                    SAFETY_WDG_SMU_ALMSTSERR        - already an SMU alarm pending        **
 **                    SAFETY_WDG_SMU_GETALMACTIONERR  - get SMU alarm action failed         **
 **                    SAFETY_WDG_SMU_SETALMACTIONERR  - set SMU alarm action failed         **
 **                    SAFETY_WDG_SMU_CLRALMSTSERR     - clear SMU alarm status failed       **
 **                    SAFETY_WDG_ENDINIT_NOBLOCK      - protected write not blocked         **
 **                    SAFETY_WDG_ENDINIT_NOWRITE      - readback of written register failed **
 **                    SAFETY_WDG_ENDINIT_NOTIMEOUT    - no endinit timeout alert signaled   **
 **                    SAFETY_WDG_PF_NOTIMEOUTALERT    - no timeout overflow signaled by HW  **
 **                    SAFETY_WDG_PF_UNEXPERROR        - unexpected access error signaled    **
 **                    SAFETY_WDG_PF_UNEXPALARM        - unexpected SMU alarm signaled       **
 **                    SAFETY_WDG_PF_TIMEIGNORED       - wrong access not signaled           **
 **                                                                                          **
 *********************************************************************************************/
Sl_TstRsltType  WdgTst_WdgSafetyTst(const Sl_ParamSetType ParamSetIndex,
                                    const uint8 TstSeed,
                                    uint32* const TstSignature)
{
    Sl_TstRsltType Result = SAFETY_WDG_INVPARAMETER;

    /* Initialize Test Signature */
    *TstSignature = (uint32) CRC32((uint32)TEST_ID_SAFETY_WDG_TST, (uint32)TstSeed);

    /* check valid parameter set index */
    if ( ParamSetIndex < WDGSAFETY_TST_CFG_PARAM_COUNT )
    {
        Result = SAFETY_WDG_SMU_STATEERR;

        /* Check whether SMU is in RUN state */
        if (SMU_RUN_STATE == Smu_GetSmuState())
        {
            Sl_TstRsltType ResultTmp;
            WdgTst_DataType WdgTst_CtrlSet;

            /* initialize Test data set */
            WdgTst_CtrlSet.TstSignature = TstSignature;
            WdgTst_CtrlSet.WdgType      = -1;
            WdgTst_CtrlSet.WdtPtr       = (volatile Ifx_SCU_WDTCPU*)((volatile void *)&SCU_WDTS_CON0);
            WdgTst_CtrlSet.AlarmId      = SMU_SCU_WDT_WDTS;
            WdgTst_CtrlSet.AlarmMask    = SMU_SCU_WDT_WDTS_STS;


            /* Save SMU alarm settings */
            Result = WdgTst_lInit( &WdgTst_CtrlSet, (uint32)TEST_ID_SAFETY_WDG_TST );

            /* execute Endinit test */
            if ( SAFETY_WDG_SUCCESS == Result )
            {
                Result = WdgTst_lEndinitTst( &WdgTst_CtrlSet, (uint32)TEST_ID_SAFETY_WDG_TST );

                /* start program flow test only if ENDINIT test was successful and program flow test is enabled */
                if ( (SAFETY_WDG_SUCCESS == Result)  &&
                     (WdgTstSafety_ConfigRoot[ParamSetIndex].WdgTstPflowMonEn == TRUE) )
                {
                    Result = WdgTst_lProgFlowTst( &WdgTst_CtrlSet, (uint32)TEST_ID_SAFETY_WDG_TST );
                }
            }

            if (SAFETY_WDG_SMU_RESOURCELOCKED != Result)
            {
              /* restore SMU alarm settings */
              ResultTmp = WdgTst_lRestore( &WdgTst_CtrlSet, (uint32)TEST_ID_SAFETY_WDG_TST );
              if ( SAFETY_WDG_SUCCESS != ResultTmp )
              {
                  Result = ResultTmp;
              }
            }
        }
    }

    /* add final test result to signature */
    *TstSignature = (uint32) CRC32(*TstSignature, Result);

    return (Result);
}


 /**************************************************************************************
 ** Traceability: [cover parentID= <id_1>, <id_2>]                                    **
 **                                                                                   **
 ** Syntax : WdgTst_lInit (WdgTst_DataType* const TestDataPtr )                       **
 **                                                                                   **
 **                                                                                   **
 ** Description :   save SMU and watchdog status during tests for later restore       **
 **                                                                                   **
 ** [/cover]                                                                          **
 **                                                                                   **
 ** Service ID: None                                                                  **
 **                                                                                   **
 ** Sync/Async: Synchronous                                                           **
 **                                                                                   **
 ** Reentrancy: Non reentrant                                                         **
 **                                                                                   **
 ** Parameters (in) :  TestDataPtr: pointer to test data set                          **
 **                                                                                   **
 ** Parameters (out):  None                                                           **
 **                                                                                   **
 ** Return value    :  Sl_TstRsltType                                                 **
 **                    CPU_WDG_SUCCESS              - no error occurred               **
 **                    CPU_WDG_SMU_GETALMSTSERR     - get SMU alarm status failed     **
 **                    CPU_WDG_SMU_ALMSTSERR        - already an SMU alarm pending    **
 **                    CPU_WDG_SMU_GETALMACTIONERR  - get SMU alarm action failed     **
 **                    CPU_WDG_SMU_SETALMACTIONERR  - set SMU alarm action failed     **
 **                    or                                                             **
 **                    SAFETY_WDG_SUCCESS              - no error occurred            **
 **                    SAFETY_WDG_SMU_GETALMSTSERR     - get SMU alarm status failed  **
 **                    SAFETY_WDG_SMU_ALMSTSERR        - already an SMU alarm pending **
 **                    SAFETY_WDG_SMU_GETALMACTIONERR  - get SMU alarm action failed  **
 **                    SAFETY_WDG_SMU_SETALMACTIONERR  - set SMU alarm action failed  **
 **                                                                                   **
 **                                                                                   **
 **************************************************************************************/
static Sl_TstRsltType    WdgTst_lInit(WdgTst_DataType* const TestDataPtr, uint32 TestId)
{
    Sl_TstRsltType      Result;
    Smu_FSPActionType   FspDummy;         /* fsp action will not be overwritten, doesn't need to be saved */
    Std_ReturnType      SmuResultTemp1 = E_NOT_OK, SmuResultTemp2 = E_NOT_OK, SmuResultTemp3 = E_NOT_OK;
    uint32              AlarmStatus = 0u;
    Ifx_SCU_WDTCPU*     ThisWdt     = TestDataPtr->WdtPtr;

    if (TestId == (uint32)TEST_ID_CPU_WDG_TST)
    {
      Result = CPU_WDG_SMU_RESOURCELOCKED;
    }
    else
    {
      Result = SAFETY_WDG_SMU_RESOURCELOCKED;
    }

    /* claim spinlock for SMU alarms (watchdog / SPB) */
    if (Sl_GetSpinLock( SL_SMUALRMGRP3_SPNLCK_ID, SL_SMUALRMGRP3_TIMEOUT) == E_OK)
    {
        /* save current wdtcon0/1 settings */
        TestDataPtr->WdtxCon0Backup = ThisWdt->CON0.U;
        TestDataPtr->WdtxCon1Backup = ThisWdt->CON1.U;

        if (TestId == (uint32)TEST_ID_CPU_WDG_TST)
        {
          Result = CPU_WDG_SMU_GETALMSTSERR;
        }
        else
        {
          Result = SAFETY_WDG_SMU_GETALMSTSERR;
        }

        /* check for pending SMU alarms */
        if (Smu_GetAlarmStatus(SMU_SCU_WDT_GRP, &AlarmStatus) == E_OK)
        {
            if (TestId == (uint32)TEST_ID_CPU_WDG_TST)
            {
              Result = CPU_WDG_SMU_ALMSTSERR;
            }
            else
            {
              Result = SAFETY_WDG_SMU_ALMSTSERR;
            }

            /* any alarm pending already? */
            AlarmStatus  &= (SMU_SCU_ALM_COMBINED_STS | TestDataPtr->AlarmMask);
            if (AlarmStatus == 0u)
            {
                /* Invalidate all Alarm Actions in the backup structure to be able to later restore only    */
                /* those Alarm Actions, that have been backed up                                            */
                TestDataPtr->AllWdgAlrmBackup    = SMU_INVALID_ALARM_ACTION;
                TestDataPtr->CpuWdgAlrmBackup    = SMU_INVALID_ALARM_ACTION;
                TestDataPtr->SpbAccAlrmBackup    = SMU_INVALID_ALARM_ACTION;

                if (TestId == (uint32)TEST_ID_CPU_WDG_TST)
                {
                  Result = CPU_WDG_SMU_GETALMACTIONERR;
                }
                else
                {
                  Result = SAFETY_WDG_SMU_GETALMACTIONERR;
                }

                /*Backup current SMU actions that will be overwritten by this test */
                SmuResultTemp1 = Smu_GetAlarmAction(SMU_SCU_WDT_GRP, SMU_SCU_WDT_WDTALL,  &(TestDataPtr->AllWdgAlrmBackup), &FspDummy);
                SmuResultTemp2 = Smu_GetAlarmAction(SMU_SCU_WDT_GRP, TestDataPtr->AlarmId,&(TestDataPtr->CpuWdgAlrmBackup), &FspDummy);
                SmuResultTemp3 = Smu_GetAlarmAction(SMU_SCU_WDT_GRP, SMU_SCU_SPB_SPBERR,  &(TestDataPtr->SpbAccAlrmBackup), &FspDummy);
                if ((E_OK == SmuResultTemp1)  && (E_OK == SmuResultTemp2) && (E_OK == SmuResultTemp3))
                {
                    if (TestId == (uint32)TEST_ID_CPU_WDG_TST)
                    {
                      Result = CPU_WDG_SMU_SETALMACTIONERR;
                    }
                    else
                    {
                      Result = SAFETY_WDG_SMU_SETALMACTIONERR;
                    }

                    /* Set SMU Alarm Action for Watchdog timeout errors and bus access error to "No Action":            */
                    SmuResultTemp1 = Smu_SetAlarmAction(SMU_SCU_WDT_GRP, SMU_SCU_WDT_WDTALL,   SMU_ALARM_ACTION_NONE);
                    SmuResultTemp2 = Smu_SetAlarmAction(SMU_SCU_WDT_GRP, TestDataPtr->AlarmId, SMU_ALARM_ACTION_NONE);
                    SmuResultTemp3 = Smu_SetAlarmAction(SMU_SCU_WDT_GRP, SMU_SCU_SPB_SPBERR,   SMU_ALARM_ACTION_NONE);
                     if ((E_OK == SmuResultTemp1)  && (E_OK == SmuResultTemp2) && (E_OK == SmuResultTemp3))
                    {
                        if (TestId == (uint32)TEST_ID_CPU_WDG_TST)
                        {
                          Result = CPU_WDG_SUCCESS;
                        }
                        else
                        {
                          Result = SAFETY_WDG_SUCCESS;
                        }
                    }
                }
            }
        }
    }

    return (Result);
}

/****************************************************************************************
 ** Traceability: [cover parentID= <id_1>, <id_2>]                                     **
 **                                                                                    **
 ** Syntax : Sl_TstRsltType  WdgTst_lRestore(const WdgTst_DataType* const TestDataPtr) **
 **                                                                                    **
 **                                                                                    **
 ** Description :    Restore Watchdog and SMU settings                                 **
 **                                                                                    **
 ** [/cover]                                                                           **
 **                                                                                    **
 ** Service ID: None                                                                   **
 **                                                                                    **
 ** Sync/Async: Synchronous                                                            **
 **                                                                                    **
 ** Reentrancy: Non reentrant                                                          **
 **                                                                                    **
 ** Parameters (in) :   TestDataPtr:  pointer to test data set                         **
 **                                                                                    **
 **                                                                                    **
 **                                                                                    **
 ** Parameters (out):   None                                                           **
 **                                                                                    **
 ** Return value    :  Sl_TstRsltType                                                  **
 **                    CPU_WDG_SUCCESS              - no error occurred                **
 **                    CPU_WDG_SMU_SETALMACTIONERR  - set SMU alarm action failed      **
 **                       or                                                           **
 **                    SAFETY_WDG_SUCCESS              - no error occurred             **
 **                    SAFETY_WDG_SMU_SETALMACTIONERR  - set SMU alarm action failed   **
 **                                                                                    **
 **                                                                                    **
 ***************************************************************************************/
 static Sl_TstRsltType   WdgTst_lRestore(const WdgTst_DataType* const TestDataPtr, uint32 TestId)
 {
    Sl_TstRsltType Result;
    Std_ReturnType SmuResultTemp1 = E_NOT_OK, SmuResultTemp2 = E_NOT_OK, SmuResultTemp3 = E_NOT_OK;
    Ifx_SCU_WDTCPU* ThisWdt  = TestDataPtr->WdtPtr;
    volatile uint32 TempRegRead=0U;


    if (TestId == (uint32)TEST_ID_CPU_WDG_TST)
    {
       Result = CPU_WDG_SMU_SETALMACTIONERR;
    }
    else
    {
       Result = SAFETY_WDG_SMU_SETALMACTIONERR;
    }

    /* restore SMU Alarm Actions  */
    if ( SMU_INVALID_ALARM_ACTION != TestDataPtr->AllWdgAlrmBackup)
    {
        SmuResultTemp1 = Smu_SetAlarmAction( SMU_SCU_WDT_GRP, SMU_SCU_WDT_WDTALL, TestDataPtr->AllWdgAlrmBackup );
    }

    if ( SMU_INVALID_ALARM_ACTION != TestDataPtr->CpuWdgAlrmBackup)
    {
        SmuResultTemp2 = Smu_SetAlarmAction( SMU_SCU_WDT_GRP, TestDataPtr->AlarmId, TestDataPtr->CpuWdgAlrmBackup );
    }

    if ( SMU_INVALID_ALARM_ACTION != TestDataPtr->SpbAccAlrmBackup)
    {
        SmuResultTemp3 = Smu_SetAlarmAction( SMU_SCU_WDT_GRP, SMU_SCU_SPB_SPBERR, TestDataPtr->SpbAccAlrmBackup );
    }

    /* Dummy read of SBCU_ECON register, to clear to value of ERRCNT */
	TempRegRead = (uint32)SBCU_ECON.U;
	 /* Clear the SRR bit of SRC_BCUSPBSBSRC register*/
    SRC_BCUSPBSBSRC.U = ((SRC_BCUSPBSBSRC.U & WDGTST_BCUSPBSBSRC_MASK) | (WDGTST_BCUSPBSBSRC_CLEAR_BITS));
 
    /* restore wdtcon1 settings */
    WdgTst_lResetEndinit(TestDataPtr->WdgType);
    ThisWdt->CON1.U = TestDataPtr->WdtxCon1Backup;
    WdgTst_lSetEndinit(TestDataPtr->WdgType);

    /*  restore timer reload value, Password restore */
    WdgTst_lWdtModifyAccess( TestDataPtr->WdgType,
                             TestDataPtr->WdtxCon0Backup & MCAL_WDT_PASSWORD_MAX,
                             TestDataPtr->WdtxCon0Backup >> 16 );


    /* release spinlock for SMU alarms (watchdog / SPB) */
    Sl_ReleaseSpinLock(SL_SMUALRMGRP3_SPNLCK_ID);

    if ((E_OK == SmuResultTemp1) && (E_OK == SmuResultTemp2) && (E_OK == SmuResultTemp3))
    {
        if (TestId == (uint32)TEST_ID_CPU_WDG_TST)
        {
          Result = CPU_WDG_SUCCESS;
        }
        else
        {
          Result = SAFETY_WDG_SUCCESS;
        }
    }
    
    /* Required to avoid compiler warning   */
    UNUSED_PARAMETER(TempRegRead)

    return (Result);
 }



/*****************************************************************************************
 ** Traceability: [cover parentID= <id_1>, <id_2>]                                      **
 **                                                                                     **
 ** Syntax : Sl_TstRsltType    WdgTst_lEndinitTst(                                      **
 **                                const WdgTst_DataType* const TestDataPtr)            **
 **                                                                                     **
 **                                                                                     **
 **                                                                                     **
 ** Description : This function tests the correct working of the Watchdog's ENDINIT     **
 **               protection feature.                                                   **
 **                                                                                     **
 ** [/cover]                                                                            **
 **                                                                                     **
 ** Service ID: None                                                                    **
 **                                                                                     **
 ** Sync/Async: Synchronous                                                             **
 **                                                                                     **
 ** Reentrancy: Non reentrant                                                           **
 **                                                                                     **
 ** Parameters (in) : TestDataPtr : Pointer to Test data set                            **
 **                                                                                     **
 ** Parameters (out): TstSignature - Test signature generated by the test               **
 **                                                                                     **
 ** Return value    :  Sl_TstRsltType                                                   **
 **                    CPU_WDG_SUCCESS            - no error occurred                   **
 **                    CPU_WDG_ENDINIT_NOBLOCK    - protected write not blocked         **
 **                    CPU_WDG_ENDINIT_NOWRITE    - readback of written register failed **
 **                    CPU_WDG_ENDINIT_NOTIMEOUT  - no endinit timeout alert signaled   **
 **                    CPU_WDG_SMU_GETALMSTSERR   - get SMU alarm status failed         **
 **                    CPU_WDG_SMU_CLRALMSTSERR   - clear SMU alarm status failed       **
 **                        or                                                           **
 **                    SAFETY_WDG_SUCCESS            - no error occurred                **
 **                    SAFETY_WDG_ENDINIT_NOBLOCK    - protected write not blocked      **
 **                    SAFETY_WDG_ENDINIT_NOWRITE  - readback of written register failed**
 **                    SAFETY_WDG_ENDINIT_NOTIMEOUT  - no endinit timeout alert signaled**
 **                    SAFETY_WDG_SMU_GETALMSTSERR   - get SMU alarm status failed      **
 **                    SAFETY_WDG_SMU_CLRALMSTSERR   - clear SMU alarm status failed    **
 **                                                                                     **
*****************************************************************************************/

static Sl_TstRsltType    WdgTst_lEndinitTst( const WdgTst_DataType* const TestDataPtr, uint32 TestId )
{
    Sl_TstRsltType  Result;
    Std_ReturnType  SmuResultTemp1 = E_NOT_OK, SmuResultTemp2 = E_NOT_OK, SmuResultTemp3 = E_NOT_OK;
    Ifx_SCU_WDTCPU* ThisWdt = TestDataPtr->WdtPtr;
    sint8           WdgId   = TestDataPtr->WdgType;
    uint32*         TestSig = TestDataPtr->TstSignature;
    uint32          TestDataAlarmMask = ((TestDataPtr->AlarmMask) | SMU_SCU_WDT_WDTALL_STS) ;

	WdgTst_ExpectedTrap = WDG_NO_TRAP;
	
    /* setup defined value to WDTCON1 to achieve defined CRC32 values for test signature */
    WdgTst_lResetEndinit(WdgId);
    /* set Disable request and use fastest prescaler */
    ThisWdt->CON1.U = WDG_CON1_DISABLEWDG_FREQPRESCALER256;
    WdgTst_lSetEndinit(WdgId);

    /* part 1: change an ENDINIT protected register without removing the protection
    *         -> Write should be ignored and a bus error occurs                 */
    if (TestId == (uint32)TEST_ID_CPU_WDG_TST)
    {
      Result = CPU_WDG_ENDINIT_NOBLOCK;               /* assume failure */
    }
    else
    {
      Result = SAFETY_WDG_ENDINIT_NOBLOCK;               /* assume failure */
    }

    WdgTst_SbeTrapSeen = 0u;                    /* trap not seen */

    /* register handler for expected trap */
    if (TRAP_E_SUCCESS == TRAP_RegisterTrapHandler(WDG_SBE_TRAP_CLASS, &WdgTst_lDAETrap))
    {
        volatile TRAP_ErrorType dummy;

        /* Set expected trap TIN: */
        WdgTst_ExpectedTrap = WDG_SBE_TRAP_TIN;

        /* do an illegal change of protected register, must result in DAE.SBE trap */
        ThisWdt->CON1.U ^= WDG_CON1_DISBALEWDGBIT_MASK;

        /* no traps expected any more */
        dummy = TRAP_UnregisterTrapHandler(WDG_SBE_TRAP_CLASS);     /* result intentionally ignored */
        UNUSED_PARAMETER(dummy)
    }

    /* Check that the register did not change  */
    if (ThisWdt->CON1.U == WDG_CON1_DISABLEWDG_FREQPRESCALER256)
    {
        if (WdgTst_SbeTrapSeen == 1u)               /* trap must have been seen exactly once!! */
        {
            /* now do an allowed access */
            if (TestId == (uint32)TEST_ID_CPU_WDG_TST)
            {
              Result = CPU_WDG_ENDINIT_NOWRITE;           /* assume failure */
            }
            else
            {
              Result = SAFETY_WDG_ENDINIT_NOWRITE;        /* assume failure */
            }

            WdgTst_lResetEndinit(WdgId);
            /* legally toggle DR bit -> enable watchdog */
            ThisWdt->CON1.U ^= WDG_CON1_DISBALEWDGBIT_MASK;
            WdgTst_lSetEndinit(WdgId);

            /* Read back and compare the register contents (wdg is enabled back) */
            if (ThisWdt->CON1.U == WDG_CON1_ENABLEWDG_FREQPRESCALER256)
            {
                if (TestId == (uint32)TEST_ID_CPU_WDG_TST)
                {
                  Result = CPU_WDG_SUCCESS;
                }
                else
                {
                  Result = SAFETY_WDG_SUCCESS;
                }
            }

            WdgTst_lResetEndinit(WdgId);
            /* legally toggle DR bit back -> disable watchdog again */
            ThisWdt->CON1.U ^= WDG_CON1_DISBALEWDGBIT_MASK;
            WdgTst_lSetEndinit(WdgId);

            *TestSig = (uint32) CRC32(*TestSig, (uint32) ThisWdt->CON1.U);        /* in case of success: 0x00000004 */
        }
    }

    /* part 2: clear ENDINIT protection and do not set it up again within the required time-frame */
    if ((CPU_WDG_SUCCESS == Result) || (SAFETY_WDG_SUCCESS == Result))
    {
        uint32  AlarmStatus = 0u;
        uint32  TimeOut     = WDG_NO_OVERFLOW_TIMEOUT;

        WdgTst_lResetEndinit(WdgId);

        if (TestId == (uint32)TEST_ID_CPU_WDG_TST)
        {
          Result = CPU_WDG_ENDINIT_NOTIMEOUT;                     /* assume timeout */
        }
        else
        {
          Result = SAFETY_WDG_ENDINIT_NOTIMEOUT;                     /* assume timeout */
        }

        while (TimeOut > 0u)
        {
            TimeOut -= 1u;

            if (E_OK != Smu_GetAlarmStatus(SMU_SCU_WDT_GRP, &AlarmStatus))
            {
                if (TestId == (uint32)TEST_ID_CPU_WDG_TST)
                {
                  Result = CPU_WDG_SMU_GETALMSTSERR;
                }
                else
                {
                  Result = SAFETY_WDG_SMU_GETALMSTSERR;
                }

                TimeOut = 0u;
            }
            else
            {
                if ((AlarmStatus & TestDataAlarmMask) == TestDataAlarmMask)
                {
                    if (TestId == (uint32)TEST_ID_CPU_WDG_TST)
                    {
                      Result = CPU_WDG_SUCCESS;                   /* set success, finish loop with break */
                    }
                    else
                    {
                      Result = SAFETY_WDG_SUCCESS;                /* set success, finish loop with break */
                    }

                    break;
                }
            }
        }
        WdgTst_lSetEndinit(WdgId);

        *TestSig = (uint32) CRC32(*TestSig, (AlarmStatus & (TestDataAlarmMask | SMU_SCU_SCU_SPB_SPBERR)));        /* Alarmstatus in case of success: 0x80220000u SafetyWdg
                                                         *                                 0x80240000u CPU0 watchdog
                                                         *                                 0x80280000u CPU1 watchdog
                                                         *                                 0x80300000u CPU2 watchdog */
    }

    SmuResultTemp1 = Smu_ClearAlarmStatus(SMU_SCU_WDT_GRP, SMU_SCU_SPB_SPBERR);
    SmuResultTemp2 = Smu_ClearAlarmStatus(SMU_SCU_WDT_GRP, TestDataPtr->AlarmId);
    SmuResultTemp3 = Smu_ClearAlarmStatus(SMU_SCU_WDT_GRP, SMU_SCU_WDT_WDTALL);

    if ((E_OK != SmuResultTemp1) || (E_OK != SmuResultTemp2) || (E_OK != SmuResultTemp3))
    {
        if (TestId == (uint32)TEST_ID_CPU_WDG_TST)
        {
          Result = CPU_WDG_SMU_CLRALMSTSERR;
        }
        else
        {
          Result = SAFETY_WDG_SMU_CLRALMSTSERR;
        }
    }

    return (Result);
}

/***********************************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                                             **
**                                                                                            **
** Syntax : Sl_TstRsltType    WdgTst_lProgFlowTst(                                            **
**                               const WdgTst_DataType* const TestDataPtr)                    **
**                                                                                            **
**                                                                                            **
**                                                                                            **
** Description : Watchdog program flow monitoring test consisting of four sub tests           **
**                                                                                            **
** [/cover]                                                                                   **
**                                                                                            **
** Service ID: None                                                                           **
**                                                                                            **
** Sync/Async: Synchronous                                                                    **
**                                                                                            **
** Reentrancy: Non reentrant                                                                  **
**                                                                                            **
** Parameters (in) : TestDataPtr : Pointer to Test data set                                   **
**                                                                                            **
** Parameters (out): TstSignature - Test signature generated by the test                      **
**                                                                                            **
** Return value    :  Sl_TstRsltType                                                          **
**                    CPU_WDG_SUCCESS               - no error occurred                       **
**                    CPU_WDG_NOTEXECUTED           - test not fully executed                 **
**                    CPU_WDG_PF_NOTIMEOUTALERT     - no timeout overflow signaled by HW      **
**                    CPU_WDG_PF_UNEXPERROR         - unexpected access error signaled        **
**                    CPU_WDG_PF_UNEXPALARM         - unexpected SMU alarm signaled           **
**                    CPU_WDG_PF_TIMEIGNORED        - wrong time check access not signaled    **
**                    CPU_WDG_SMU_GETALMSTSERR      - read SMU alarm status failed            **
**                    CPU_WDG_SMU_CLRALMSTSERR      - clear SMU alarm status failed           **
**                    or                                                                      **
**                    SAFETY_WDG_SUCCESS               - no error occurred                    **
**                    SAFETY_WDG_NOTEXECUTED           - test not fully executed              **
**                    SAFETY_WDG_PF_NOTIMEOUTALERT     - no timeout overflow signaled by HW   **
**                    SAFETY_WDG_PF_UNEXPERROR         - unexpected access error signaled     **
**                    SAFETY_WDG_PF_UNEXPALARM         - unexpected SMU alarm signaled        **
**                    SAFETY_WDG_PF_TIMEIGNORED        - wrong time check access not signaled **
**                    SAFETY_WDG_SMU_GETALMSTSERR      - read SMU alarm status failed         **
**                    SAFETY_WDG_SMU_CLRALMSTSERR      - clear SMU alarm status failed        **
**                                                                                            **
***********************************************************************************************/
static Sl_TstRsltType    WdgTst_lProgFlowTst(const WdgTst_DataType* const TestDataPtr, uint32 TestId)
{
    Sl_TstRsltType  Result;
    Ifx_SCU_WDTCPU* ThisWdt = TestDataPtr->WdtPtr;
    sint8   WdgId           = TestDataPtr->WdgType;

    /* setup defined value to WDTCON1 */
    WdgTst_lResetEndinit(WdgId);
    /* set disable request and use fastest prescaler */
    ThisWdt->CON1.U = WDG_CON1_DISABLEWDG_FREQPRESCALER256;
    WdgTst_lSetEndinit(WdgId);

    /* time-out Test */
    Result = WdgTst_lWdgPfTimeoutTst( TestDataPtr, TestId );

    if ((CPU_WDG_SUCCESS == Result) || (SAFETY_WDG_SUCCESS == Result))
    {
        /* no failure test */
        Result = WdgTst_lWdgPfNoErrorTst( TestDataPtr, TestId );
        if ((CPU_WDG_SUCCESS == Result) || (SAFETY_WDG_SUCCESS == Result))
        {
            /* wrong access time failure */
            Result = WdgTst_lWdgPfWrongAccTimeTst( TestDataPtr, TestId );
            if ((CPU_WDG_SUCCESS == Result) || (SAFETY_WDG_SUCCESS == Result))
            {
                /* wrong password failure - automatic password sequencing */
                Result = WdgTst_lWdgPfWrongPwdTst( TestDataPtr, TestId, WDG_AUTOMATIC_PASSWORD );
                if ((CPU_WDG_SUCCESS == Result) || (SAFETY_WDG_SUCCESS == Result))
                {
                    /* wrong password failure - static password */
                    Result = WdgTst_lWdgPfWrongPwdTst( TestDataPtr, TestId, WDG_STATIC_PASSWORD );
                }
            }
        }
    }

    return (Result);
}


/*********************************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                                           **
**                                                                                          **
** Syntax : Sl_TstRsltType WdgTst_lWdgPfTimeoutTst(WdgTst_DataType* const TestDataPtr)      **
**                                                                                          **
**                                                                                          **
** Description :   simple check to verify that a watchdog will overflow,                    **
**                 if not serviced in time.                                                 **
** [/cover]                                                                                 **
**                                                                                          **
** Service ID: None                                                                         **
**                                                                                          **
** Sync/Async: Synchronous                                                                  **
**                                                                                          **
** Reentrancy: Non reentrant                                                                **
**                                                                                          **
** Parameters (in) : TestDataPtr : Pointer to Test data set                                 **
**                                                                                          **
** Parameters (out): TstSignature - Test signature generated by the test                    **
**                                                                                          **
** Return value    :  Sl_TstRsltType                                                        **
**                    CPU_WDG_SUCCESS               - no error occurred                     **
**                    CPU_WDG_PF_NOTIMEOUTALERT     - no timeout overflow signaled by HW    **
**                    CPU_WDG_SMU_GETALMSTSERR      - read SMU alarm status failed          **
**                    CPU_WDG_SMU_CLRALMSTSERR      - clear SMU alarm status failed         **
**                    or                                                                    **
**                    SAFETY_WDG_SUCCESS               - no error occurred                  **
**                    SAFETY_WDG_PF_NOTIMEOUTALERT     - no timeout overflow signaled by HW **
**                    SAFETY_WDG_SMU_GETALMSTSERR      - read SMU alarm status failed       **
**                    SAFETY_WDG_SMU_CLRALMSTSERR      - clear SMU alarm status failed      **
**                                                                                          **
*********************************************************************************************/

static Sl_TstRsltType WdgTst_lWdgPfTimeoutTst( const WdgTst_DataType* const TestDataPtr, uint32 TestId )
{
    Sl_TstRsltType  Result;
    Std_ReturnType  SmuResultTemp1 = E_NOT_OK, SmuResultTemp2 = E_NOT_OK;
    Ifx_SCU_WDTCPU* ThisWdt = TestDataPtr->WdtPtr;
    uint32  TimeOut         = WDG_NO_OVERFLOW_TIMEOUT;
    uint32  AlarmStatus     = 0u;
    sint8   WdgId           = TestDataPtr->WdgType;
    uint32  TestDataAlarmMask = ((TestDataPtr->AlarmMask) | SMU_SCU_WDT_WDTALL_STS);


    /* set short watchdog timeout */
    WdgTst_lWdtModifyAccess( WdgId, MCAL_WDT_PASSWORD_IGNORE, MCAL_WDT_RELOAD_MAX - 3u);

    /* enable the watchdog */
    WdgTst_lResetEndinit(WdgId);
    ThisWdt->CON1.B.DR = 0u;                     /* set watchdog enable */
    WdgTst_lSetEndinit(WdgId);

    /* do not service, check timeout interval */
    if (TestId == (uint32)TEST_ID_CPU_WDG_TST)
    {
      Result = CPU_WDG_PF_NOTIMEOUTALERT;
    }
    else
    {
      Result = SAFETY_WDG_PF_NOTIMEOUTALERT;
    }

    while (TimeOut > 0u)
    {
        TimeOut  -= 1u;
        if (ThisWdt->SR.B.OE == 1u)
        {   /* Wdg overflow happened */
            if (Smu_GetAlarmStatus(SMU_SCU_WDT_GRP, &AlarmStatus) != E_OK)
            {
                if (TestId == (uint32)TEST_ID_CPU_WDG_TST)
                {
                  Result = CPU_WDG_SMU_GETALMSTSERR;
                }
                else
                {
                  Result = SAFETY_WDG_SMU_GETALMSTSERR;
                }
				TimeOut=0U; /* for terminating the loop */
            } 
            else
            {
                if ((AlarmStatus & TestDataAlarmMask) == TestDataAlarmMask)    /* expected alarm signalled? */
                {
                    if (TestId == (uint32)TEST_ID_CPU_WDG_TST)
                    {
                      Result = CPU_WDG_SUCCESS;
                    }
                    else
                    {
                      Result = SAFETY_WDG_SUCCESS;
                    }					
				    TimeOut=0U; /* for terminating the loop */					
                }
				
            }
           
        }
    }

    /* Alarmstatus in case of success:  0x00220000u SafetyWdg,     0x00240000u CPU0 watchdog,
                                        0x00280000u CPU1 watchdog, 0x00300000u CPU2 watchdog */
    *(TestDataPtr->TstSignature) = (uint32) CRC32(*(TestDataPtr->TstSignature), (AlarmStatus & TestDataAlarmMask));

    /* disable the watchdog */
    WdgTst_lResetEndinit(WdgId);
    ThisWdt->CON1.B.DR = 1u;                     /* set watchdog disable */
    WdgTst_lSetEndinit(WdgId);

    SmuResultTemp1 = Smu_ClearAlarmStatus(SMU_SCU_WDT_GRP, TestDataPtr->AlarmId);
    SmuResultTemp2 = Smu_ClearAlarmStatus(SMU_SCU_WDT_GRP, SMU_SCU_WDT_WDTALL);

    if ((E_OK != SmuResultTemp1) || (E_OK != SmuResultTemp2))
    {
        if (TestId == (uint32)TEST_ID_CPU_WDG_TST)
        {
          Result = CPU_WDG_SMU_CLRALMSTSERR;
        }
        else
        {
          Result = SAFETY_WDG_SMU_CLRALMSTSERR;
        }
    }

    return (Result);
}


/********************************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                                          **
**                                                                                         **
** Syntax : Sl_TstRsltType WdgTst_lWdgPfNoErrorTst(                                        **
**                         const WdgTst_DataType* const TestDataPtr)                       **
**                                                                                         **
**                                                                                         **
**                                                                                         **
** Description :   This test checks whether no alarm is generated if watchdog is           **
**                 serviced properly in time window and sequencer password                 **
** [/cover]                                                                                **
**                                                                                         **
** Service ID: None                                                                        **
**                                                                                         **
** Sync/Async: Synchronous                                                                 **
**                                                                                         **
** Reentrancy: Non reentrant                                                               **
**                                                                                         **
** Parameters (in) : TestDataPtr : Pointer to Test data set                                **
**                                                                                         **
** Parameters (out): TstSignature - Test signature generated by the test                   **
**                                                                                         **
** Return value    :  Sl_TstRsltType                                                       **
**                    CPU_WDG_SUCCESS               - no error occurred                    **
**                    CPU_WDG_NOTEXECUTED           - test not fully executed              **
**                    CPU_WDG_PF_UNEXPERROR         - unexpected access error signaled     **
**                    CPU_WDG_PF_UNEXPALARM         - unexpected SMU alarm signaled        **
**                    CPU_WDG_SMU_GETALMSTSERR      - read SMU alarm status failed         **
**                    or                                                                   **
**                    SAFETY_WDG_SUCCESS               - no error occurred                 **
**                    SAFETY_WDG_NOTEXECUTED           - test not fully executed           **
**                    SAFETY_WDG_PF_UNEXPERROR         - unexpected access error signaled  **
**                    SAFETY_WDG_PF_UNEXPALARM         - unexpected SMU alarm signaled     **
**                    SAFETY_WDG_SMU_GETALMSTSERR      - read SMU alarm status failed      **
**                                                                                         **
********************************************************************************************/

static Sl_TstRsltType WdgTst_lWdgPfNoErrorTst( const WdgTst_DataType* const TestDataPtr, uint32 TestId )
{
    Sl_TstRsltType  Result;
    Ifx_SCU_WDTCPU* ThisWdt = TestDataPtr->WdtPtr;
    uint32  AlarmStatus     = 0u;
    uint32  Password        = MCAL_WDT_PW_FIXPART_READ;
    uint32  TimeOut         = WDG_NO_OVERFLOW_TIMEOUT;
    sint8   WdgId           = TestDataPtr->WdgType;
    uint32  TestDataAlarmMask = ((TestDataPtr->AlarmMask) | SMU_SCU_WDT_WDTALL_STS) ;
    Ifx_SCU_WDTCPU_CON1  con1tmp;

    if (TestId == (uint32)TEST_ID_CPU_WDG_TST)
    {
      Result = CPU_WDG_NOTEXECUTED;
    }
    else
    {
      Result = SAFETY_WDG_NOTEXECUTED;
    }

    /* set initial password */
    WdgTst_lWdtModifyAccess ( WdgId, Password, MCAL_WDT_RELOAD_MAX - WDG_TST_TICKS);        /* set initial password and timer reload value */

    con1tmp.U      = ThisWdt->CON1.U;       /* get old value  */
    con1tmp.B.PAR  = 1U;                    /* set auto sequence password mode    */
    con1tmp.B.TCR  = 1U;                    /* set timer check mode               */
    con1tmp.B.TCTR = (2u*WDG_TST_TICKS)/10u;  /* set Timer tolerance 20%            */
    con1tmp.B.DR   = 0U;                    /* request watchdog service           */

    /* configure the watchdog */
    WdgTst_lResetEndinit(WdgId);
    ThisWdt->CON1.U = con1tmp.U;
    WdgTst_lSetEndinit(WdgId);

    /* service watchdog twice with proper time and password */
    /* calculate first new password */
    Password = WdgTst_lWdtPwSequence( WdgId, (uint32) ThisWdt->CON0.U);

    /* service watchdog  */
    WdgTst_lWdtCheckAccess( WdgId, Password, (~((uint32)ThisWdt->SR.B.TIM)) & MCAL_WDT_RELOAD_MAX );           /* use current timer to properly service watchdog */

    /* calculate next password */
    Password = WdgTst_lWdtPwSequence( WdgId, (uint32) ThisWdt->CON0.U);

    /* wait for second service */
    while (TimeOut > 0u)
    {
        TimeOut -= 1u;

        if (ThisWdt->SR.B.TIM >= (MCAL_WDT_RELOAD_MAX - (WDG_TST_TICKS/2u)))
        {
            /* service watchdog: use current timer to properly service watchdog */
            WdgTst_lWdtCheckAccess( WdgId, Password, (~((uint32)ThisWdt->SR.B.TIM)) & MCAL_WDT_RELOAD_MAX);

            if (TestId == (uint32)TEST_ID_CPU_WDG_TST)
            {
              Result = CPU_WDG_PF_UNEXPERROR;
            }
            else
            {
              Result = SAFETY_WDG_PF_UNEXPERROR;
            }
            break;
        }
    }

    /* disable the watchdog to avoid service timeout */
    WdgTst_lResetEndinit(WdgId);
    ThisWdt->CON1.B.DR = 1u;                     /* set watchdog disable */
    WdgTst_lSetEndinit(WdgId);

    if (ThisWdt->SR.B.AE == 0u)
    {   /* no Wdg access error happened */
        if (Smu_GetAlarmStatus(SMU_SCU_WDT_GRP, &AlarmStatus) != E_OK)
        {
            if (TestId == (uint32)TEST_ID_CPU_WDG_TST)
            {
              Result = CPU_WDG_SMU_GETALMSTSERR;
            }
            else
            {
              Result = SAFETY_WDG_SMU_GETALMSTSERR;
            }
        }
        else
        {
            if (TestId == (uint32)TEST_ID_CPU_WDG_TST)
            {
              Result = CPU_WDG_PF_UNEXPALARM;
            }
            else
            {
              Result = SAFETY_WDG_PF_UNEXPALARM;
            }

            /* no alarm expected ! */
            if ((AlarmStatus & TestDataAlarmMask) == 0u )
            {
                if (TestId == (uint32)TEST_ID_CPU_WDG_TST)
                {
                  Result = CPU_WDG_SUCCESS;
                }
                else
                {
                  Result = SAFETY_WDG_SUCCESS;
                }
            }
        }

        /* Alarmstatus in case of success: 0x00000000u in all cases */
        *(TestDataPtr->TstSignature) = (uint32) CRC32(*(TestDataPtr->TstSignature), (AlarmStatus & TestDataAlarmMask));
    }

    return (Result);
}


/****************************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                                      **
**                                                                                     **
** Syntax : Sl_TstRsltType WdgTst_lWdgPfWrongAccTimeTst(                               **
**                          const WdgTst_DataType* const TestDataPtr)                  **
**                                                                                     **
**                                                                                     **
** Description :   Test, whether an access error is signaled, if watchdog is           **
**                 check access is out of the estimated time window                    **
** [/cover]                                                                            **
**                                                                                     **
** Service ID: None                                                                    **
**                                                                                     **
** Sync/Async: Synchronous                                                             **
**                                                                                     **
** Reentrancy: Non reentrant                                                           **
**                                                                                     **
** Parameters (in) : TestDataPtr : Pointer to Test data set                            **
**                                                                                     **
** Parameters (out): TstSignature - Test signature generated by the test               **
**                                                                                     **
** Return value    :  Sl_TstRsltType                                                   **
**                    CPU_WDG_SUCCESS               - no error occurred                **
**                    CPU_WDG_PF_TIMEIGNORED        - wrong access not signaled        **
**                    CPU_WDG_PF_UNEXPALARM         - unexpected SMU alarm signaled    **
**                    CPU_WDG_SMU_GETALMSTSERR      - read SMU alarm status failed     **
**                    CPU_WDG_SMU_CLRALMSTSERR      - clear SMU alarm status failed    **
**                    or                                                               **
**                    SAFETY_WDG_SUCCESS               - no error occurred             **
**                    SAFETY_WDG_PF_TIMEIGNORED        - wrong access not signaled     **
**                    SAFETY_WDG_PF_UNEXPALARM         - unexpected SMU alarm signaled **
**                    SAFETY_WDG_SMU_GETALMSTSERR      - read SMU alarm status failed  **
**                    SAFETY_WDG_SMU_CLRALMSTSERR      - clear SMU alarm status failed **
**                                                                                     **
*****************************************************************************************/

static Sl_TstRsltType WdgTst_lWdgPfWrongAccTimeTst( const WdgTst_DataType* const TestDataPtr, uint32 TestId )
{
    Sl_TstRsltType  Result;
    Std_ReturnType  SmuResultTemp1 = E_NOT_OK, SmuResultTemp2 = E_NOT_OK;
    Ifx_SCU_WDTCPU* ThisWdt = TestDataPtr->WdtPtr;
    uint32  AlarmStatus     = 0u;
    uint32  Password        = MCAL_WDT_PW_FIXPART_READ;
    sint8   WdgId           = TestDataPtr->WdgType;
    uint32  TestDataAlarmMask = ((TestDataPtr->AlarmMask) | SMU_SCU_WDT_WDTALL_STS);
    boolean WdtAccessError  = FALSE;
    Ifx_SCU_WDTCPU_CON1  con1tmp;

    /* set initial password and timer reload value */
    WdgTst_lWdtModifyAccess ( WdgId, Password , MCAL_WDT_RELOAD_MAX - WDG_TST_TICKS);

    con1tmp.U      = ThisWdt->CON1.U;       /* get old value  */
    con1tmp.B.PAR  = 0U;                    /* set static password mode           */
    con1tmp.B.TCR  = 1U;                    /* set timer check enable             */
    con1tmp.B.TCTR = (2u*WDG_TST_TICKS)/10u;  /* set Timer tolerance 20%            */
    con1tmp.B.DR   = 0U;                    /* request watchdog service           */

    /* configure the watchdog */
    WdgTst_lResetEndinit(WdgId);
    ThisWdt->CON1.U = con1tmp.U;
    WdgTst_lSetEndinit(WdgId);

    /* calculate new password */
    Password = WdgTst_lWdtPwSequence( WdgId, (uint32) ThisWdt->CON0.U);

    /* service watchdog with wrong time estimate (value below initial timer reload) */
    WdgTst_lWdtCheckAccess( WdgId, Password, (~((uint32)(MCAL_WDT_RELOAD_MAX - (4u*WDG_TST_TICKS))) & MCAL_WDT_RELOAD_MAX));

    /* save access error state */
    WdtAccessError = ThisWdt->SR.B.AE;

    /* disable the watchdog to avoid service timeout */
    WdgTst_lResetEndinit(WdgId);
    ThisWdt->CON1.B.DR = 1u;                     /* set watchdog disable */
    WdgTst_lSetEndinit(WdgId);

    if (TestId == (uint32)TEST_ID_CPU_WDG_TST)
    {
      Result = CPU_WDG_PF_TIMEIGNORED;
    }
    else
    {
      Result = SAFETY_WDG_PF_TIMEIGNORED;
    }

    if (WdtAccessError == TRUE)
    {   /* Wdg access error happened */
        if (Smu_GetAlarmStatus(SMU_SCU_WDT_GRP, &AlarmStatus) != E_OK)
        {
            if (TestId == (uint32)TEST_ID_CPU_WDG_TST)
            {
              Result = CPU_WDG_SMU_GETALMSTSERR;
            }
            else
            {
              Result = SAFETY_WDG_SMU_GETALMSTSERR;
            }
        }
        else
        {
            if (TestId == (uint32)TEST_ID_CPU_WDG_TST)
            {
              Result = CPU_WDG_PF_UNEXPALARM;
            }
            else
            {
              Result = SAFETY_WDG_PF_UNEXPALARM;
            }

            if ((AlarmStatus & TestDataAlarmMask) == TestDataAlarmMask)       /* alarm expected ! */
            {
                if (TestId == (uint32)TEST_ID_CPU_WDG_TST)
                {
                  Result = CPU_WDG_SUCCESS;
                }
                else
                {
                  Result = SAFETY_WDG_SUCCESS;
                }
            }
        }

        *(TestDataPtr->TstSignature) = (uint32) CRC32(*(TestDataPtr->TstSignature), (AlarmStatus & TestDataAlarmMask));        /* Alarmstatus in case of success: tbd */
    }

    /* clear alarm */
    SmuResultTemp1 = Smu_ClearAlarmStatus(SMU_SCU_WDT_GRP, TestDataPtr->AlarmId);
    SmuResultTemp2 = Smu_ClearAlarmStatus(SMU_SCU_WDT_GRP, SMU_SCU_WDT_WDTALL);

    if ((E_OK != SmuResultTemp1) || (E_OK != SmuResultTemp2))
    {
        if (TestId == (uint32)TEST_ID_CPU_WDG_TST)
        {
          Result = CPU_WDG_SMU_CLRALMSTSERR;
        }
        else
        {
          Result = SAFETY_WDG_SMU_CLRALMSTSERR;
        }
    }

    return (Result);
}

/********************************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                                          **
**                                                                                         **
** Syntax : Sl_TstRsltType WdgTst_lWdgPfWrongPwdTst(                                       **
**                                const  WdgTst_DataType* const TestDataPtr )              **
**                                                                                         **
**                                                                                         **
** Description :   Test, which verifies whether an access error is signaled,               **
**                  if watchdog check access is done with wron password                    **
** [/cover]                                                                                **
**                                                                                         **
** Service ID: None                                                                        **
**                                                                                         **
** Sync/Async: Synchronous                                                                 **
**                                                                                         **
** Reentrancy: Non reentrant                                                               **
**                                                                                         **
** Parameters (in) : TestDataPtr : Pointer to Test data set                                **
**                                                                                         **
** Parameters (out): TstSignature - Test signature generated by the test                   **
**                                                                                         **
** Return value    :  Sl_TstRsltType                                                       **
**                    CPU_WDG_SUCCESS               - no error occurred                    **
**                    CPU_WDG_PF_UNEXPALARM         - unexpected SMU alarm signaled        **
**                    CPU_WDG_SMU_GETALMSTSERR      - read SMU alarm status failed         **
**                    CPU_WDG_SMU_CLRALMSTSERR      - clear SMU alarm status failed        **
**                    or                                                                   **
**                    SAFETY_WDG_SUCCESS               - no error occurred                 **
**                    SAFETY_WDG_PF_UNEXPALARM         - unexpected SMU alarm signaled     **
**                    SAFETY_WDG_SMU_GETALMSTSERR      - read SMU alarm status failed      **
**                    SAFETY_WDG_SMU_CLRALMSTSERR      - clear SMU alarm status failed     **
**                                                                                         **
********************************************************************************************/
static Sl_TstRsltType WdgTst_lWdgPfWrongPwdTst( const WdgTst_DataType* const TestDataPtr, uint32 TestId, uint8 PasswordType )
{
    Sl_TstRsltType  Result;
    Std_ReturnType  SmuResultTemp1 = E_NOT_OK, SmuResultTemp2 = E_NOT_OK;
    Ifx_SCU_WDTCPU* ThisWdt = TestDataPtr->WdtPtr;
    uint32  AlarmStatus     = 0u;
    uint32  Password        = MCAL_WDT_PW_FIXPART_READ;
    sint8   WdgId           = TestDataPtr->WdgType;
    uint32  TestDataAlarmMask = ((TestDataPtr->AlarmMask) | SMU_SCU_WDT_WDTALL_STS);
    boolean WdtAccessError  = FALSE;
    Ifx_SCU_WDTCPU_CON1  con1tmp;

    if (TestId == (uint32)TEST_ID_CPU_WDG_TST)
    {
       Result = CPU_WDG_NOTEXECUTED;
    }
    else
    {
       Result = SAFETY_WDG_NOTEXECUTED;
    }

    /* set initial password and timer reload value */
    WdgTst_lWdtModifyAccess ( WdgId, Password , MCAL_WDT_RELOAD_MAX - WDG_TST_TICKS);

    con1tmp.U      = ThisWdt->CON1.U;       /* get old value  */
    con1tmp.B.PAR  = PasswordType;          /* set auto sequence password mode    */
    con1tmp.B.TCR  = 0U;                    /* ignore TIM value                   */
    con1tmp.B.DR   = 0U;                    /* request watchdog service           */

    /* configure the watchdog */
    WdgTst_lResetEndinit(WdgId);
    ThisWdt->CON1.U = con1tmp.U;
    WdgTst_lSetEndinit(WdgId);

    /* calculate new password */
    if (WDG_STATIC_PASSWORD == PasswordType)
    {
      Password = WdgTst_lWdtPwSequence( WdgId, (uint32) ThisWdt->CON0.U);
    }

    /* calculate wrong new password */
    Password = ~Password;

    /* service watchdog with wrong password, ignore timer reload */
    WdgTst_lWdtCheckAccess( WdgId, Password, MCAL_WDT_RELOAD_IGNORE );

    /* save access error state */
    WdtAccessError = ThisWdt->SR.B.AE;

    /* disable the watchdog to avoid service timeout */
    WdgTst_lResetEndinit(WdgId);
    ThisWdt->CON1.B.DR = 1u;                     /* set watchdog disable */
    WdgTst_lSetEndinit(WdgId);

    if (WdtAccessError == TRUE)
    {   /* Wdg access error happened */
        if (Smu_GetAlarmStatus(SMU_SCU_WDT_GRP, &AlarmStatus) != E_OK)
        {
            if (TestId == (uint32)TEST_ID_CPU_WDG_TST)
            {
              Result = CPU_WDG_SMU_GETALMSTSERR;
            }
            else
            {
              Result = SAFETY_WDG_SMU_GETALMSTSERR;
            }
        }
        else
        {
            if (TestId == (uint32)TEST_ID_CPU_WDG_TST)
            {
              Result = CPU_WDG_PF_UNEXPALARM;
            }
            else
            {
              Result = SAFETY_WDG_PF_UNEXPALARM;
            }

            if ((AlarmStatus & TestDataAlarmMask) == TestDataAlarmMask)       /* alarm expected ! */
            {
                if (TestId == (uint32)TEST_ID_CPU_WDG_TST)
                {
                  Result = CPU_WDG_SUCCESS;
                }
                else
                {
                  Result = SAFETY_WDG_SUCCESS;
                }
            }
        }

        *(TestDataPtr->TstSignature) = (uint32) CRC32(*(TestDataPtr->TstSignature), (AlarmStatus & TestDataAlarmMask));        /* Alarmstatus in case of success: tbd */
    }

    /* clear alarm */
    SmuResultTemp1 = Smu_ClearAlarmStatus(SMU_SCU_WDT_GRP, TestDataPtr->AlarmId);
    SmuResultTemp2 = Smu_ClearAlarmStatus(SMU_SCU_WDT_GRP, SMU_SCU_WDT_WDTALL);

    if ((E_OK != SmuResultTemp1) || (E_OK != SmuResultTemp2))
    {
        if (TestId == (uint32)TEST_ID_CPU_WDG_TST)
        {
          Result = CPU_WDG_SMU_CLRALMSTSERR;
        }
        else
        {
          Result = SAFETY_WDG_SMU_CLRALMSTSERR;
        }
    }

    return (Result);
}


/****************************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                                      **
**                                                                                     **
** Syntax : static boolean WdgTst_lDAETrap (const uint32 TIN)                          **
**                                                                                     **
**                                                                                     **
** Description :   Temporary handler for expected SBE Trap during endinit test         **
** [/cover]                                                                            **
**                                                                                     **
** Service ID: None                                                                    **
**                                                                                     **
** Sync/Async: Synchronous                                                             **
**                                                                                     **
** Reentrancy: Non reentrant                                                           **
**                                                                                     **
** Parameters (in) : TIN : Trap id number for currently occured trap                   **
**                                                                                     **
** Parameters (out): None                                                              **
**                                                                                     **
** Return value : TRUE, if trap was expected and handled, FALSE otherwise              **
**                                                                                     **
*****************************************************************************************/
static boolean WdgTst_lDAETrap (const uint32 TIN)
{
    boolean TrapExpected = (boolean)FALSE;

    if ((WdgTst_ExpectedTrap == WDG_SBE_TRAP_TIN) && (TIN == WDG_SBE_TRAP_TIN))
    {
        /* expected trap happened  */
        WdgTst_SbeTrapSeen++;

        /* No more traps expected: */
        WdgTst_ExpectedTrap = WDG_NO_TRAP;

        TrapExpected = (boolean)TRUE;

        /* Clear DATR to reset any DAE trap reason */
        MTCR(CPU_DATR, 0x0U);
    }

    return TrapExpected;
}


#define IFX_WDG_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"

