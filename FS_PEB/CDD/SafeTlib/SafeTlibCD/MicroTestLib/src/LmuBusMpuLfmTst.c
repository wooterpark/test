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
**   $FILENAME   : LmuBusMpuLfmTst.c $                                        **
**                                                                            **
**   $CC VERSION : \main\54 $                                                 **
**                                                                            **
**   $DATE       : 2018-02-22 $                                               **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  AUTHOR    : DL-BLR-ATV-STC                                                **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : This file contains a latent fault metric test for the LMU  **
**                 Bus Memory Protection Unit.                                **
**                                                                            **
**  SPECIFICATION(S) : Aurix_SafeTlib_DS_LMU_BusMpuTest.docm                  **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

#include "IfxCpu_reg.h"
#include "IfxLmu_reg.h"
#include "Mcal_TcLib.h"
#include "LmuBusMpuLfmTst.h"
#include "LmuBusMpuLfmTst_Cfg.h"
#include "Sl_Ipc.h"
#include "Mcal.h"
#include "IfxScu_reg.h"
#include "Smu.h"
#include "Mtl_Trap.h"
#include "IfxStm_reg.h"
#include "IfxSmu_reg.h"
#include "IfxXbar_reg.h"
#include "IfxXbar_bf.h"
#include "IfxSrc_reg.h"
#include "IfxSrc_bf.h"

/*******************************************************************************
**                      Local Macro Definitions                               **
*******************************************************************************/

/* mask for password Bits 2-7 */
#define LBM_WDT_PASSWORD_LOWER_MASK    (0x000000FCu)

/* mask for password Bits 8-15 */
#define LBM_WDT_PASSWORD_UPPER_MASK    (0x0000FF00u)

/* mask for password bits */
#define LBM_WDT_PASSWORD_MASK          (LBM_WDT_PASSWORD_LOWER_MASK | \
                                         LBM_WDT_PASSWORD_UPPER_MASK)
/* mask for reload bits */
#define LBM_WDT_RELOAD_MASK            (0xFFFF0000u)

/* mask for LCK and ENDINIT status bits */
#define LBM_WDT_STATUS_MASK            (0x00000003u)

/* Reload value for watch dog in timeout mode */
#define LBM_SDWT_TIMEOUT_MOD_RELOAD        (0xFFFC0000u)

/* Definition of SMU alarm groups, alarm IDs and alarm status bits required
   by the Bus MPU test:
*/
#define LBM_SMU_LMU_MPU_ERROR_STS   \
    (uint32)((uint32)1U << (uint32)(uint8)SMU_ALARM_16)

#define LBM_SMU_SRI_BUS_ERROR_STS   \
    (uint32)((uint32)1U << (uint32)(uint8)SMU_ALARM_30)

#define LBM_SMU_ALM_NOT_SET             ((uint32)0U)

/* ACCEN bit masks for CPUx DMI.NonSafe and CPUx DMI.Safe Master TAG IDs */
#define LBM_CPU0_NON_SAFE_DMI_ACCEN     ( 0x00000001U )
#define LBM_CPU1_NON_SAFE_DMI_ACCEN     ( 0x00000004U )
#define LBM_CPU2_NON_SAFE_DMI_ACCEN     ( 0x00000010U )

#define LBM_CPU0_SAFE_DMI_ACCEN         ( 0x00000002U )
#define LBM_CPU1_SAFE_DMI_ACCEN         ( 0x00000008U )
#define LBM_CPU2_SAFE_DMI_ACCEN         ( 0x00000020U )


/* Bit mask for setting / clearing the S bit(Safety Task Identifier) 
   in the PSW */
#define LBM_PSW_S_BIT                   ( 0x00004000U )


#define LBM_CBM_SIZEOFWORD                  (4U)

/* Timeout value for trap generation */
#define LBM_ENABLE_TIMEOUT                        (0x100U)

/* Mapping starting location of register set(SMU_AlarmGroupRegMapType)
 * - Alarm group registers.
 */
#define LBM_SMU_ALARM_GROUP   \
   ((volatile SMU_AlarmGroupRegMapType *)(volatile void *)(&SMU_AGCF0_0))

/* Trap classes and IDs: */
#define LBM_TRAP_CLASS_NONE             ( 0x00U )
#define LBM_TRAP_CLASS4                 ( 0x04U )
#define LBM_TRAP_ID_NONE                ( 0x00U )
#define LBM_TRAP_ID3                    ( 0x03U )

/* Clear SRC_XBARSRC Service Request Flag */
#define LBMTST_XBARSRC_MASK                ((unsigned_int)0x293F1CFFU)
#define LBMTST_XBARSRC_CLEAR_BITS          ((unsigned_int)0x02000000U)

/* LMU_RGNUAx */
#define LBMTST_RGNUAX_MASK            ((unsigned_int)0x1FFFFFE0U)

/* Disable bit 28 so that upper addr is not set to 0xB0007FFFF in LMURAM*/
#define LBMTST_RGNUAX_BIT28_DISABLE_MASK   ((unsigned_int)0x0FFFFFE0U)

/* LMU_RGNLAx */
#define LBMTST_RGNLAX_MASK            ((unsigned_int)0x0FFFFFE0U)

/*******************************************************************************
**                      Local Type Definitions                                **
*******************************************************************************/

/* Type definition LmuBusMpuLfmTst_WdtContextType -
 * This structure holds all data that is stored during
 * LmuBusMpuLfmTst_lResetXXXENDINIT call and is required by the
 * subsequent call of LmuBusMpuLfmTst_lSetXXXENDINIT. It is a replacement for the
 * global static data of Mcal_Lib.
 */
typedef struct LmuBusMpuLfmTst_WdtContextType
{
  /* Backup of watchdog timer reload value and password: */
  uint32  WdtTimAndPw;
}LmuBusMpuLfmTst_WdtContextType;

/* Type definition LmuBusMpuLfmTst_ScuWdtPtrListType -
 * This structure holds pointers to a watchdog control and status SFR.
 */
typedef struct LmuBusMpuLfmTst_ScuWdtPtrListType
{
  volatile Ifx_SCU_WDTCPU_CON0* const Wdtcon0Ptr;
  volatile Ifx_SCU_WDTCPU_SR* const   WdtssrPtr;
}LmuBusMpuLfmTst_ScuWdtPtrListType;


/* Type:SMU_AlarmGroupRegMap - SMU Alarm group specific registers is listed
according to their order in hardware Memory.   */
typedef struct SMU_AlarmGroupRegMap
{  
  volatile Ifx_SMU_AGCF CfgReg[SMU_TOTAL_ALARM_CONFIG_REG];
  uint32 Reserved0[11];
  volatile Ifx_SMU_AGFSP FSPCfgReg[SMU_TOTAL_ALARM_GROUPS];
  uint32 Reserved1[9];
  volatile Ifx_SMU_AG AGStatusReg[SMU_TOTAL_ALARM_GROUPS];
  uint32 Reserved2[9];
  volatile Ifx_SMU_AD ADStatusReg[SMU_TOTAL_ALARM_GROUPS];
}SMU_AlarmGroupRegMapType;

/* Type definition LmuBusMpuLfmTst_BackupDataType to store all
   register backup values */
typedef struct LmuBusMpuLfmTst_BackupDataType
{
  uint32 LMURGNLA0;
  uint32 LMURGNUA0;
  uint32 LMURGNLA1;
  uint32 LMURGNUA1;
  uint32 LMURGNLA2;
  uint32 LMURGNUA2;
  uint32 LMURGNLA3;
  uint32 LMURGNUA3;
  uint32 LMURGNLA4;
  uint32 LMURGNUA4;
  uint32 LMURGNLA5;
  uint32 LMURGNUA5;
  uint32 LMURGNLA6;
  uint32 LMURGNUA6;
  uint32 LMURGNLA7;
  uint32 LMURGNUA7;
  uint32 LMURGNACCENA0;
  uint32 LMURGNACCENA1;
  uint32 LMURGNACCENA2;
  uint32 LMURGNACCENA3;
  uint32 LMURGNACCENA4;
  uint32 LMURGNACCENA5;
  uint32 LMURGNACCENA6;
  uint32 LMURGNACCENA7;
  uint32 LmuBusMpuLfmTst_BackupMemory[LBM_TEST_RANGE_COUNT];  
  Smu_AlarmActionType AlmActionLmuMpu;
  Smu_AlarmActionType AlmActionSriBus;  
  boolean ProtectionTrapRegistered;  
}LmuBusMpuLfmTst_BackupDataType;


/******************************************************************************
**                        Exported object definitions                         *
******************************************************************************/

/******************************************************************************
**                        Local object definitions                            *
******************************************************************************/


#define IFX_LMUBUSMPULFM_START_SEC_CONST_32BIT_ASIL_B
#include "Ifx_MemMap.h"
/* Constant Test pattern for all memory sets */
static const uint32 LBM_kTestPattern[LBM_TEST_RANGE_SIZE/4U] =
{
  0x12345678U,  /* [0] */
  0x23456789U,  /* [1] */
  0x3456789aU,  /* [2] */
  0x456789abU,  /* [3] */
  0x56789abcU,  /* [4] */
  0x6789abcdU,  /* [5] */
  0x789abcdeU,  /* [6] */
  0x89abcdefU   /* [7] */
};
#define IFX_LMUBUSMPULFM_STOP_SEC_CONST_32BIT_ASIL_B
#include "Ifx_MemMap.h"

#define IFX_LMUBUSMPULFM_START_SEC_VAR_8BIT_CPU0_DSPR
#include "Ifx_MemMap.h"
static volatile uint8 Lmu_DaeTrapCount;
#define IFX_LMUBUSMPULFM_STOP_SEC_VAR_8BIT_CPU0_DSPR
#include "Ifx_MemMap.h"

#define IFX_LMUBUSMPULFM_START_SEC_VAR_32BIT_CPU0_DSPR
#include "Ifx_MemMap.h"
static uint32  Lmu_ExpectedTrapClass;
static uint32  Lmu_ExpectedTrapId;
#define IFX_LMUBUSMPULFM_STOP_SEC_VAR_32BIT_CPU0_DSPR
#include "Ifx_MemMap.h"

/******************************************************************************
**                        Imported function declarations                      *
******************************************************************************/

/******************************************************************************
**                        Local function prototypes                           *
******************************************************************************/
#define IFX_LMUBUSMPULFM_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"

LOCAL_INLINE Sl_TstRsltType  LmuBusMpuLfmTst_lCheckConfig
(
 const Sl_ParamSetType ParamSetIndex
);

static Sl_TstRsltType LmuBusMpuLfmTst_lCheckStatus(void);


static Sl_TstRsltType LmuBusMpuLfmTst_lInit
(
 const Sl_ParamSetType ParamSetIndex, 
 LmuBusMpuLfmTst_BackupDataType* LmuBusMpuLfmTst_BackupData
);

static Sl_TstRsltType LmuBusMpuLfmTst_lCheckNonSafeAcc
(
  const Sl_ParamSetType ParamSetIndex,
  const uint8 CoreId,
  uint32* const TstSignature
);

static Sl_TstRsltType LmuBusMpuLfmTst_lCheckSafeAcc
(
  const Sl_ParamSetType ParamSetIndex,
  const uint8 CoreId,
  uint32* const TstSignature
);

static void LmuBusMpuLfmTst_lSetupAccEn
(
  const uint32 AccEnable  
);

static Sl_TstRsltType LmuBusMpuLfmTst_lRestore
(
  const Sl_ParamSetType ParamSetIndex,
  LmuBusMpuLfmTst_BackupDataType* LmuBusMpuLfmTst_BackupData
);

static Sl_TstRsltType LmuBusMpuLfmTst_lCheckRangeError
(  
  uint8 AccessExpected,
  uint32* const TstSignature
);

static Sl_TstRsltType LmuBusMpuLfmTst_lFillAndCmpRanges
(
  const Sl_ParamSetType ParamSetIndex,
  uint32* const TstSignature
);

static Sl_TstRsltType LmuBusMpuLfmTst_lFillAndCmpRange
(
  const Sl_ParamSetType ParamSetIndex,
  uint32* const TstSignature
);

static Sl_TstRsltType LmuBusMpuLfmTst_lClrAndCmpRanges
(
  const Sl_ParamSetType ParamSetIndex,
  uint32* const TstSignature
);

static Sl_TstRsltType LmuBusMpuLfmTst_lClrAndCmpRange
(
  const Sl_ParamSetType ParamSetIndex,
  uint32* const TstSignature
);

static Sl_TstRsltType LmuBusMpuLfmTst_lCheckUnauthorizedAddr
(
  const Sl_ParamSetType ParamSetIndex,
  uint32* const TstSignature
);

static void LmuBusMpuLfmTst_lResetSafetyENDINIT
(
  LmuBusMpuLfmTst_WdtContextType* const WdtContext
);

static void LmuBusMpuLfmTst_lSetSafetyENDINIT
(
  const LmuBusMpuLfmTst_WdtContextType* const WdtContext
);

static Std_ReturnType LmuBusSmu_lClearAlarmStatus
(
  uint8 AlarmGroup,
  uint8 AlarmPos
);

static boolean LmuBusMpuLfmTst_lProtectionTrapHandler
(
  const uint32 TrapId
);



/******************************************************************************
**                         Function definitions                               *
******************************************************************************/
/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : Sl_TstRsltType LmuBusMpuLfmTst_LmuBusMpuLfmTest         **
**                    ( const Sl_ParamSetType ParamSetIndex,                  **
**                      const uint8 TstSeed,                                  **
**                      uint32* const TstSignature                            **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters(in)   : ParamSetIndex - Identifies the configuration parameter  **
**                    set to be used for test execution                       **
**                    TstSeed - Seed to be used for generating the signature  **
**                                                                            **
** Parameters (out) : TstSignature - Test signature generated by the Test     **
**                                                                            **
** Return value     : Error information                                       **
**                                                                            **
** Description      : Test API performs the latent fault metric test of the   **
**                    LMU Bus Memory Protection Unit. It performs the         **
**                    necessary test initialization, performs the actual test **
**                    and cleans up resources used by the test.               **
*******************************************************************************/
Sl_TstRsltType LmuBusMpuLfmTst_LmuBusMpuLfmTst
( const Sl_ParamSetType ParamSetIndex,
  const uint8 TstSeed,
  uint32* const TstSignature
)
{

  /* Backup of registers which are modified for test purpose */
  LmuBusMpuLfmTst_BackupDataType  LmuBusMpuLfmTst_BackupData;
  uint8             CoreId;  
  Sl_TstRsltType    Result    = LMUBUSMPULFM_NOTEXECUTED;
  Sl_TstRsltType    ResultTmp1 = LMUBUSMPULFM_NOTEXECUTED;
  Sl_TstRsltType    ResultTmp2 = LMUBUSMPULFM_NOTEXECUTED;

  /* Initialize Test Signature:                                             */
  *TstSignature = 
     (uint32)CRC32((uint32)TEST_ID_BUS_LMU_MPU_LFM_TST,(uint32)TstSeed);

  /* Read the core Id */
  CoreId = Mcal_GetCoreId();
  
  /* Checks whether the ParamSetIndex parameter is valid */
  ResultTmp1 = LmuBusMpuLfmTst_lCheckConfig(ParamSetIndex);

  if(ResultTmp1 != LMUBUSMPULFM_SUCCESS)
  {
    Result = ResultTmp1;
  }
  else
  {
    /* checks that the SMU is in RUN state and that the Memory Protection SMU
       alarm and SRI Bus SMU alarm not already set */
    ResultTmp1 = LmuBusMpuLfmTst_lCheckStatus();
    if(ResultTmp1 != LMUBUSMPULFM_SUCCESS)
    {
      Result = ResultTmp1;
    }
    else
    {    
      /* Backs up the status of all SFRs and SMU alarm actions  */
      ResultTmp1 = 
      LmuBusMpuLfmTst_lInit(ParamSetIndex,&LmuBusMpuLfmTst_BackupData);
      if(ResultTmp1 == LMUBUSMPULFM_SUCCESS)
      {
        /* Enables access to test memory in LMURAM for the DMI non-safe master
        and checks that access is granted to the DMI.non-safe master,
      denied to the DMI.safe master and that the reported error
      information is consistent. */
        ResultTmp1 = LmuBusMpuLfmTst_lCheckNonSafeAcc(ParamSetIndex,
                                                      CoreId,
                                                      TstSignature
                                                      ); 

        if(ResultTmp1 == LMUBUSMPULFM_SUCCESS)
        {
          /* Enables access to test memory in LMURAM for the DMI.Safe master and
         checks that access is granted to the DMI.safe master, denied to the
       DMI.non-safe master and that the reported error information is
       consistent. 
      */
          ResultTmp1 = LmuBusMpuLfmTst_lCheckSafeAcc(ParamSetIndex,
                                                     CoreId,
                                                     TstSignature
                                                    ); 

              
        }
      } /* lInit failed */
      /* Restores SFRs and SMU alarm actions that have been backed up and 
       modified by test */
      ResultTmp2 = 
      LmuBusMpuLfmTst_lRestore(ParamSetIndex,&LmuBusMpuLfmTst_BackupData);
        
      if((LMUBUSMPULFM_SUCCESS == ResultTmp1) && 
              (LMUBUSMPULFM_SUCCESS == ResultTmp2) )
      {
        Result = LMUBUSMPULFM_SUCCESS;
      }
      else
      {
        if(LMUBUSMPULFM_SUCCESS != ResultTmp1)
        {
          Result = ResultTmp1 ;
        }
        else
        {
          Result = ResultTmp2 ;
        }
      }
    } /* CheckStatus failed */
  } /* CheckConfig failed */

  *TstSignature = (uint32)CRC32(*TstSignature,Result);

  return Result;

}/* LmuBusMpuLfmTst_LmuBusMpuLfmTest */

/******************************************************************************
**                    Trap Handlers                                           *
******************************************************************************/
/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : static boolean                                                    **
**             LmuBusMpuLfmTst_lProtectionTrapHandler(const uint32 TrapId)    **
**                                                                            **
** Description : Handles Class 5, Data Asynchronous Traps which are generated **
**               by the test                                                  **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) : TrapId - Trap Identification Number (TIN) of the trap    **
**                            that is to be handled                           **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value : None                                                        **
**                                                                            **
*******************************************************************************/
static boolean LmuBusMpuLfmTst_lProtectionTrapHandler(const uint32 TrapId)
{
  
  boolean TrapExpected = (boolean)FALSE;
  
   /* Check if TIN = 3 and this trap is currently expected: */
  if ((LBM_TRAP_ID3 == TrapId) &&
      (LBM_TRAP_CLASS4 == Lmu_ExpectedTrapClass) &&
      (LBM_TRAP_ID3 == Lmu_ExpectedTrapId))
  {
    TrapExpected = (boolean)TRUE;

    /* Clear expected trap class and ID: */
    Lmu_ExpectedTrapClass = LBM_TRAP_CLASS_NONE;
    Lmu_ExpectedTrapId = LBM_TRAP_ID_NONE;

    if (Lmu_DaeTrapCount < (uint8)0xFF)
    {
      Lmu_DaeTrapCount += 1U;
    } /* if (Lmu_DaeTrapCount < (uint8)0xFF) */

    /* Clear DAE Trap request                          */
    MTCR(CPU_DATR, 0x0U);
  } /* if ((LBM_TRAP_ID3 == TrapId) &&
           (LBM_TRAP_CLASS4 == Lmu_ExpectedTrapClass) &&
           (LBM_TRAP_ID3 == Lmu_ExpectedTrapId)) */
  else
  {
    Lmu_DaeTrapCount = 0U;
  } /* if ((LBM_TRAP_ID3 != TrapId) ||
           (LBM_TRAP_CLASS4 != Lmu_ExpectedTrapClass) ||
           (LBM_TRAP_ID3 != Lmu_ExpectedTrapId)) */

  return TrapExpected;
  
}

/******************************************************************************
**                    Configuration error checking                            *
******************************************************************************/
/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : LOCAL_INLINE static Sl_TstRsltType                      **
**                     LmuBusMpuLfmTst_lCheckConfig                           **
**                    (                                                       **
**                     const Sl_ParamSetType ParamSetIndex                    **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters(in)   : ParamSetIndex - Identifies the configuration parameter  **
**                    set to be used for test execution                       **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : Error information                                       **
**                                                                            **
** Description      : Checks whether the ParamSetIndex parameter is valid and **
**                    the configuration settings selected by the ParamSetIndex**
**                    parameter are also valid.                               **
*******************************************************************************/
LOCAL_INLINE Sl_TstRsltType  LmuBusMpuLfmTst_lCheckConfig
(const Sl_ParamSetType ParamSetIndex
)
{
  Sl_TstRsltType Result = LMUBUSMPULFM_NOTEXECUTED;

  /* Input parameter check */
  if(ParamSetIndex >= (Sl_ParamSetType)LMUBUSMPU_LFM_TST_CFG_PARAM_COUNT)
  {
    Result = LMUBUSMPULFM_INVPARAMERR;
  }
  else
  {
    Result = LMUBUSMPULFM_SUCCESS;
  }

  return Result;
} /* LmuBusMpuLfmTst_lCheckConfig */

/******************************************************************************
**                    Local inline function definitions                       *
******************************************************************************/

/******************************************************************************
**                         Local function definitions                         *
******************************************************************************/
/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static Sl_TstRsltType LmuBusMpuLfmTst_lCheckStatus      **
**                                          (void)                            **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : Error information                                       **
**                                                                            **
** Description      : checks that the SMU is in RUN state and that the Memory **
**                    Protection SMU alarm and SRI Bus SMU alarm not already  **
**                    set                                                     **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType LmuBusMpuLfmTst_lCheckStatus(void)
{
  Sl_TstRsltType Result;
  uint32 AlarmStatus = 0x0U;

  if(SMU_RUN_STATE != Smu_GetSmuState())
  {
    Result = LMUBUSMPULFM_SMU_STATEERR;
  }
  else if((Std_ReturnType)E_OK !=
          Smu_GetAlarmStatus(SMU_ALARM_GROUP2,&AlarmStatus))
  {
    Result = LMUBUSMPULFM_SMU_GETALMSTSERR;
  }
  /* Check for Group 2 Alarm 16: LMU MPU Error */
  else if((AlarmStatus & LBM_SMU_LMU_MPU_ERROR_STS) != LBM_SMU_ALM_NOT_SET)
  {
    Result = LMUBUSMPULFM_SMU_ALMSTSERR;
  }
  else if((Std_ReturnType)E_OK !=
          Smu_GetAlarmStatus(SMU_ALARM_GROUP3,&AlarmStatus))
  {
    Result = LMUBUSMPULFM_SMU_GETALMSTSERR;
  }
  /* Check for Group 3 Alarm 30: SRI Bus Error */
  else if((AlarmStatus & LBM_SMU_SRI_BUS_ERROR_STS) != LBM_SMU_ALM_NOT_SET)
  {
    Result = LMUBUSMPULFM_SMU_ALMSTSERR;
  }
  else
  {
    Result = LMUBUSMPULFM_SUCCESS;
  }

  return Result;
} /* LmuBusMpuLfmTst_lCheckStatus */


/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static Sl_TstRsltType LmuBusMpuLfmTst_lInit             **
**                    (                                                       **
**                     const Sl_ParamSetType ParamSetIndex,                   **
**                 LmuBusMpuLfmTst_BackupDataType* LmuBusMpuLfmTst_BackupData **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters(in)   :                                                         **
**                    ParamSetIndex - Identifies the parameter set to be used **
**                    for test execution                                      **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : Error information                                       **
**                                                                            **
** Description      : Backs up the status of all SFRs and SMU alarm actions   **
**                    modified by the test, sets up all eight CPU Bus memory  **
**                    protection ranges to point to the LMU used for testing  **
**                    and sets the LMU Bus MPU and SRI bus alarm action to    **
**                    ‘none’.Furthermore all modified SFRs are read back in   **
**                    order to ensure that the expected value has actually be ** 
**                    written.                                                **
*******************************************************************************/
static Sl_TstRsltType LmuBusMpuLfmTst_lInit
(
 const Sl_ParamSetType ParamSetIndex, 
 LmuBusMpuLfmTst_BackupDataType* LmuBusMpuLfmTst_BackupData 
)
{ 
  LmuBusMpuLfmTst_WdtContextType WdtContext;
  uint32 WordIndex;
  uint32* Source;
  uint32* Dest; 
  volatile uint32 LMURGNUAx = 0x0U;
  volatile uint32 LMURGNLAx = 0x0U;
  
  TRAP_ErrorType TrapRegResult;  
  Sl_TstRsltType Result = LMUBUSMPULFM_NOTEXECUTED;    
  Smu_FSPActionType fspActionDummy = 0x0U;
  
  /* No trap expected yet. Initialize expected trap class and ID:            */
  Lmu_ExpectedTrapClass = LBM_TRAP_CLASS_NONE;
  Lmu_ExpectedTrapId = LBM_TRAP_ID_NONE;

  /* Initialize status flags for registration of trap handlers:               */
  LmuBusMpuLfmTst_BackupData->ProtectionTrapRegistered = (boolean)FALSE;
   
  /* Backup RGNLAx / RGNUAx registers */
  LmuBusMpuLfmTst_BackupData->LMURGNLA0 = LMU_RGNLA0.U;
  LmuBusMpuLfmTst_BackupData->LMURGNUA0 = LMU_RGNUA0.U;

  LmuBusMpuLfmTst_BackupData->LMURGNLA1 = LMU_RGNLA1.U;
  LmuBusMpuLfmTst_BackupData->LMURGNUA1 = LMU_RGNUA1.U;

  LmuBusMpuLfmTst_BackupData->LMURGNLA2 = LMU_RGNLA2.U;
  LmuBusMpuLfmTst_BackupData->LMURGNUA2 = LMU_RGNUA2.U;

  LmuBusMpuLfmTst_BackupData->LMURGNLA3 = LMU_RGNLA3.U;
  LmuBusMpuLfmTst_BackupData->LMURGNUA3 = LMU_RGNUA3.U;

  LmuBusMpuLfmTst_BackupData->LMURGNLA4 = LMU_RGNLA4.U;
  LmuBusMpuLfmTst_BackupData->LMURGNUA4 = LMU_RGNUA4.U;

  LmuBusMpuLfmTst_BackupData->LMURGNLA5 = LMU_RGNLA5.U;
  LmuBusMpuLfmTst_BackupData->LMURGNUA5 = LMU_RGNUA5.U;

  LmuBusMpuLfmTst_BackupData->LMURGNLA6 = LMU_RGNLA6.U;
  LmuBusMpuLfmTst_BackupData->LMURGNUA6 = LMU_RGNUA6.U;

  LmuBusMpuLfmTst_BackupData->LMURGNLA7 = LMU_RGNLA7.U;
  LmuBusMpuLfmTst_BackupData->LMURGNUA7 = LMU_RGNUA7.U;

  /* Backup RGNACCENAx registers */
  LmuBusMpuLfmTst_BackupData->LMURGNACCENA0 = LMU_RGNACCENA0.U;
  LmuBusMpuLfmTst_BackupData->LMURGNACCENA1 = LMU_RGNACCENA1.U;
  LmuBusMpuLfmTst_BackupData->LMURGNACCENA2 = LMU_RGNACCENA2.U;
  LmuBusMpuLfmTst_BackupData->LMURGNACCENA3 = LMU_RGNACCENA3.U;
  LmuBusMpuLfmTst_BackupData->LMURGNACCENA4 = LMU_RGNACCENA4.U;
  LmuBusMpuLfmTst_BackupData->LMURGNACCENA5 = LMU_RGNACCENA5.U;
  LmuBusMpuLfmTst_BackupData->LMURGNACCENA6 = LMU_RGNACCENA6.U;
  LmuBusMpuLfmTst_BackupData->LMURGNACCENA7 = LMU_RGNACCENA7.U;
   
  /* Backup SMU alarm action */
  LmuBusMpuLfmTst_BackupData->AlmActionLmuMpu = SMU_INVALID_ALARM_ACTION;
  LmuBusMpuLfmTst_BackupData->AlmActionSriBus = SMU_INVALID_ALARM_ACTION;

  /* Backup memory given in configuration */
  Dest = &(LmuBusMpuLfmTst_BackupData->LmuBusMpuLfmTst_BackupMemory[0U]);
  Source = LmuBusMpuLfmTst_ConfigRoot[ParamSetIndex].TestMemory;
  for(WordIndex = 0U;
      WordIndex < (LBM_TEST_RANGE_SIZE/LBM_CBM_SIZEOFWORD); WordIndex++)
  {
    Dest[WordIndex] = Source[WordIndex];
  }
  
  if (E_OK != Smu_GetAlarmAction(SMU_ALARM_GROUP2,
                                 (uint8)SMU_ALARM_16,
                                 &LmuBusMpuLfmTst_BackupData->AlmActionLmuMpu,
                                 &fspActionDummy))
  {
    Result = LMUBUSMPULFM_SMU_GETALMACTIONERR;
  }
  else if (E_OK != Smu_GetAlarmAction(SMU_ALARM_GROUP3,
                                  (uint8)SMU_ALARM_30,
                                  &LmuBusMpuLfmTst_BackupData->AlmActionSriBus,
                                  &fspActionDummy))
  {
    Result = LMUBUSMPULFM_SMU_GETALMACTIONERR;
  }
  else
  {
    if(E_OK != Smu_SetAlarmAction(SMU_ALARM_GROUP2,
                                  (uint8)SMU_ALARM_16,
                                  SMU_ALARM_ACTION_NONE)
      )
    {
      Result = LMUBUSMPULFM_SMU_SETALMACTIONERR;
    }

    else if(E_OK != Smu_SetAlarmAction(SMU_ALARM_GROUP3,
                                       (uint8)SMU_ALARM_30,
                                       SMU_ALARM_ACTION_NONE)
           )
    {
      Result = LMUBUSMPULFM_SMU_SETALMACTIONERR;
    }
  else
  {
    /* added for MISRA */
  }
     
  if(LMUBUSMPULFM_NOTEXECUTED == Result)
  { 
    /* Register protection error and bus error trap handlers:               */
    TrapRegResult = TRAP_RegisterTrapHandler(LBM_TRAP_CLASS4,
                                    &LmuBusMpuLfmTst_lProtectionTrapHandler);
    if(TRAP_E_SUCCESS == TrapRegResult)
    {
      LmuBusMpuLfmTst_BackupData->ProtectionTrapRegistered = (boolean)TRUE;
      Result = LMUBUSMPULFM_SUCCESS;
    } /* if (TRAP_E_SUCCESS == Result) */
    else
    {
      Result = LMUBUSMPULFM_TRAPERROR;
    } /* if (TRAP_E_SUCCESS != Result) */   
               
    if(LMUBUSMPULFM_SUCCESS == Result)
    { 
      /* LMU_RGNUAx register Bits[31:29], Bits[4:0] are unused bits read as 0B, */
	  /*   should be written with 0B*/
	  LMURGNUAx = (uint32)((uint32)LmuBusMpuLfmTst_ConfigRoot[ParamSetIndex].TestMemory & \
	                            (uint32)LBMTST_RGNUAX_MASK);
	  LMURGNUAx = (uint32)(LMURGNUAx + (unsigned_int)LBM_TEST_RANGE_SIZE);
	  /* Disable bit 28 so that upper addr is not set to 0xB0007FFFF in LMURAM*/
	  LMURGNUAx = (uint32)((uint32)LMURGNUAx & (uint32)LBMTST_RGNUAX_BIT28_DISABLE_MASK);
	  
	  LMURGNLAx = (((uint32)LmuBusMpuLfmTst_ConfigRoot[ParamSetIndex].TestMemory) & \
	                             (uint32)LBMTST_RGNLAX_MASK);
	  
      /* Setup address ranges for testing */
      LmuBusMpuLfmTst_lResetSafetyENDINIT(&WdtContext);
      LMU_RGNLA0.U = (unsigned_int)LMURGNLAx;
      LMU_RGNUA0.U = (unsigned_int)LMURGNUAx;    
     
      LMU_RGNLA1.U = (unsigned_int)LMURGNLAx;
      LMU_RGNUA1.U = (unsigned_int)LMURGNUAx;
     
      LMU_RGNLA2.U = (unsigned_int)LMURGNLAx;
      LMU_RGNUA2.U = (unsigned_int)LMURGNUAx;
     
      LMU_RGNLA3.U = (unsigned_int)LMURGNLAx;
      LMU_RGNUA3.U = (unsigned_int)LMURGNUAx;
     
      LMU_RGNLA4.U = (unsigned_int)LMURGNLAx;
      LMU_RGNUA4.U = (unsigned_int)LMURGNUAx;
     
      LMU_RGNLA5.U = (unsigned_int)LMURGNLAx;
      LMU_RGNUA5.U = (unsigned_int)LMURGNUAx;
     
      LMU_RGNLA6.U = (unsigned_int)LMURGNLAx;
      LMU_RGNUA6.U = (unsigned_int)LMURGNUAx;
     
      LMU_RGNLA7.U = (unsigned_int)LMURGNLAx;
      LMU_RGNUA7.U = (unsigned_int)LMURGNUAx;
     
      LmuBusMpuLfmTst_lSetSafetyENDINIT(&WdtContext);
     
      Result = LMUBUSMPULFM_SUCCESS;
   } /* if(LMUBUSMPULFM_SUCCESS == Result) */
  } /* if(LMUBUSMPULFM_NOTEXECUTED == Result) */  
  
 } 
  return Result;
} /* LmuBusMpuLfmTst_lInit */

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static Sl_TstRsltType LmuBusMpuLfmTst_lCheckNonSafeAcc  **
**                    (const Sl_ParamSetType ParamSetIndex,                   **
**                     const uint8 CoreId,                                    **
**                     uint32* const TstSignature                             **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters(in)   : CoreId - ID of the CPU core on which the test           **
**                             is executing                                   **
**                    ParamSetIndex - Identifies the parameter set to be used **
**                    for test execution                                      **
**                                                                            **
** Parameters (out) : TstSignature - Test signature generated by the Test     **
**                                                                            **
** Return value     : Error information                                       **
**                                                                            **
** Description      : Enables access to test memory in LMURAM for the DMI-    **
**                    non-safe master and checks that access is granted to the**
**                    DMI.non-safe master, denied to the DMI.safe master and  **
**                    that the reported error information is consistent.      **
*******************************************************************************/
static Sl_TstRsltType LmuBusMpuLfmTst_lCheckNonSafeAcc
(
  const Sl_ParamSetType ParamSetIndex,
  const uint8 CoreId,
  uint32* const TstSignature  
)
{
  
  uint32 Temp;
  volatile uint32 MemFillRange;
  uint32 i;  
  Sl_TstRsltType Result    = LMUBUSMPULFM_NOTEXECUTED;
  Sl_TstRsltType ResultTmp = LMUBUSMPULFM_NOTEXECUTED;    
    
/* Constant Non safe DMI ACCEN value for each core */
  uint32 LBM_kNonSafeDMIAccEn[] =
  {
    LBM_CPU0_NON_SAFE_DMI_ACCEN,
    LBM_CPU1_NON_SAFE_DMI_ACCEN,
    LBM_CPU2_NON_SAFE_DMI_ACCEN
  };
  
  /* Initialize Lmu_DaeTrapCount to zero */
  Lmu_DaeTrapCount = 0x0U;  

  /* Access is granted to CPUx non-safe DMI, no read back of written
     values is done */
  LmuBusMpuLfmTst_lSetupAccEn(LBM_kNonSafeDMIAccEn[CoreId]                               
                               );

  /* Switch processor status to non-safe task:                */
  Temp = (uint32)MFCR(CPU_PSW);
  Temp &= (~((uint32)LBM_PSW_S_BIT));
  MTCR(CPU_PSW, Temp);  

  /* Fill the test memory to value 0 */
  MemFillRange = (uint32)LBM_TEST_RANGE_SIZE / LBM_CBM_SIZEOFWORD;
  MEMFILL64((uint32)LmuBusMpuLfmTst_ConfigRoot[ParamSetIndex].TestMemory,
             0U,
             MemFillRange);
  for(i = 0U; i < ((uint32)LBM_TEST_RANGE_SIZE / LBM_CBM_SIZEOFWORD); i++)
  {
    if((LmuBusMpuLfmTst_ConfigRoot[ParamSetIndex].TestMemory[i])
       != 0x00000000U)
    {
      Result = LMUBUSMPULFM_CLEAR_ERROR;
    }
  }
  
  if(LMUBUSMPULFM_NOTEXECUTED == Result)
  {
    /* Fills all protected memory ranges with test patterns and checks whether 
       or not data has been written by reading back all data and comparing it 
       to the test patterns again */
    ResultTmp = LmuBusMpuLfmTst_lFillAndCmpRanges(ParamSetIndex,
                                                TstSignature
                                                );

    if(LMUBUSMPULFM_SUCCESS != ResultTmp)
    {
      Result = ResultTmp;
    }
    else
    {
      /* Performs a write access to an address not covered by any memory
         protection range and checks that this unauthorized access triggers
       an SMU alarm and trap  */
      ResultTmp = LmuBusMpuLfmTst_lCheckUnauthorizedAddr(ParamSetIndex,
                                                         TstSignature
                                                        );

      if(LMUBUSMPULFM_SUCCESS != ResultTmp)
      {
        Result = ResultTmp;
      }
      else
      {

        /* Switch processor status to safe task:                */
        Temp = (uint32)MFCR(CPU_PSW);
        Temp |= ((uint32)LBM_PSW_S_BIT);
        MTCR(CPU_PSW, Temp);

        /* checks here the access is denied for the DMI safe master and it
           should not clear all protected memory ranges to zero. Furthermore
       it checks that the LMU MPU and SRI Bus alarms are raised.
       Also the DAE trap is raised 
        */
        ResultTmp = LmuBusMpuLfmTst_lClrAndCmpRanges(ParamSetIndex,
                                                     TstSignature
                                                     );
        if(LMUBUSMPULFM_SUCCESS != ResultTmp)
        {
          Result = ResultTmp;
        }
        else
        {
          Result = LMUBUSMPULFM_SUCCESS;
        }
      }
    }
  } 
  return Result;
} /* LmuBusMpuLfmTst_lCheckNonSafeAcc */

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static Sl_TstRsltType LmuBusMpuLfmTst_lCheckSafeAcc     **
**                    (const Sl_ParamSetType ParamSetIndex,                   **
**                     const uint8 CoreId,                                    **
**                     uint32* const TstSignature                             **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters(in)   : CoreId - ID of the CPU core on which the test           **
**                             is executing                                   **
**                    ParamSetIndex - Identifies the parameter set to be used **
**                    for test execution                                      **
**                                                                            **
** Parameters (out) : TstSignature - Test signature generated by the Test     **
**                                                                            **
** Return value     : Error information                                       **
**                                                                            **
** Description      : Enables access to test memory in LMURAM for the DMI.Safe**
**                    master and checks that access is granted to the         **
**                    DMI.safe master, denied to the DMI.non-safe master and  **
**                    that the reported error information is consistent.      **
*******************************************************************************/
static Sl_TstRsltType LmuBusMpuLfmTst_lCheckSafeAcc
(
  const Sl_ParamSetType ParamSetIndex,
  const uint8 CoreId,
  uint32* const TstSignature  
)
{

  uint32 Temp;  
  uint32 i;  
  volatile uint32 MemFillRange;
  Sl_TstRsltType Result    = LMUBUSMPULFM_NOTEXECUTED;
  Sl_TstRsltType ResultTmp = LMUBUSMPULFM_NOTEXECUTED;
   
  /* Constant Safe DMI ACCEN value for each core */
  uint32 LBM_kSafeDMIAccEn[] =
  {
    LBM_CPU0_SAFE_DMI_ACCEN,
    LBM_CPU1_SAFE_DMI_ACCEN,
    LBM_CPU2_SAFE_DMI_ACCEN
  };
  
  /* Initialize Lmu_DaeTrapCount variable to zero */
  Lmu_DaeTrapCount = 0x0U;

  
  
  /* Sets up the access enable registers LMU_RGNy_ACCENA to a caller-supplied
     value and checks that those values have actually be written by reading 
   them back. */
  LmuBusMpuLfmTst_lSetupAccEn(LBM_kSafeDMIAccEn[CoreId]                              
                             );

  /* Switch processor status to safe task:                */
  Temp = (uint32)MFCR(CPU_PSW);
  Temp |= ((uint32)LBM_PSW_S_BIT);
  MTCR(CPU_PSW, Temp);

  /* Fill the test memory to value 0 */
  MemFillRange = (uint32)LBM_TEST_RANGE_SIZE / LBM_CBM_SIZEOFWORD;
  MEMFILL64((uint32)LmuBusMpuLfmTst_ConfigRoot[ParamSetIndex].TestMemory,
             0U,
             MemFillRange);
   
  for(i = 0U; i < ((uint32)LBM_TEST_RANGE_SIZE / LBM_CBM_SIZEOFWORD); i++)
  {
    if((LmuBusMpuLfmTst_ConfigRoot[ParamSetIndex].TestMemory[i])
      != 0x00000000U)
    {
       Result = LMUBUSMPULFM_CLEAR_ERROR;
    }
  }

  if(LMUBUSMPULFM_NOTEXECUTED == Result)
  {
    ResultTmp = LmuBusMpuLfmTst_lFillAndCmpRanges(ParamSetIndex,
                                                TstSignature
                                             );

    if(LMUBUSMPULFM_SUCCESS != ResultTmp)
    {
      Result = ResultTmp;
    }
    else
    {
      /* Performs a write access to an address not covered by any memory
         protection range and checks that this unauthorized access triggers
     an SMU alarm and trap */
      ResultTmp = LmuBusMpuLfmTst_lCheckUnauthorizedAddr(ParamSetIndex,
                                                       TstSignature
                                                       );

      if(LMUBUSMPULFM_SUCCESS != ResultTmp)
      {
        Result = ResultTmp;
      }
      else
      {
        /* Switch processor status to Non safe task:                */
        Temp = (uint32)MFCR(CPU_PSW);
        Temp &= (~((uint32)LBM_PSW_S_BIT));
        MTCR(CPU_PSW, Temp);

        /* checks here the access is denied for the DMI Non safe master and it
           should not clear all protected memory ranges to zero. Furthermore it
       checks that the LMU MPU and SRI Bus alarms are raised. 
       Also the DAE trap is raised 
        */
        ResultTmp = LmuBusMpuLfmTst_lClrAndCmpRanges(ParamSetIndex,
                                                    TstSignature
                                                    );
        if(LMUBUSMPULFM_SUCCESS != ResultTmp)
        {
          Result = ResultTmp;
        }
        else
        {
          Result = LMUBUSMPULFM_SUCCESS;
        }
      }
    }
  }
  return Result;


}/* LmuBusMpuLfmTst_lCheckSafeAcc */

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static void LmuBusMpuLfmTst_lSetupAccEn                 **
**                    (const uint32 AccEnable                                 **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters(in)   :                                                         **
**                    AccEnable - Access enable mask that specifies for which **
**                                masters access is to be enabled; this value **
**                                is directly written to                      **
**                                LMU_RGNy_ACCENA                             **
**                                                                            **
** Parameters (out) : no                                                      **
**                                                                            **
** Return value     : Error information                                       **
**                                                                            **
** Description      : Sets up the access enable registers                     **
**                    LMU_RGNy_ACCENA to a caller-supplied value and          **
**                    checks that those values have actually be written by    **
**                    reading them back.                                      **
*******************************************************************************/
static void LmuBusMpuLfmTst_lSetupAccEn
(
  const uint32 AccEnable 
)
{
  
  LmuBusMpuLfmTst_WdtContextType WdtContext;
 
  LmuBusMpuLfmTst_lResetSafetyENDINIT(&WdtContext);

  /* Access is granted as per caller supplied value of 'AccEnable'
    (and not to CPU0 non-safe DMI) */
  LMU_RGNACCENA0.U = AccEnable;

  LMU_RGNACCENA1.U = AccEnable;

  LMU_RGNACCENA2.U = AccEnable;

  LMU_RGNACCENA3.U = AccEnable;

  LMU_RGNACCENA4.U = AccEnable;

  LMU_RGNACCENA5.U = AccEnable;

  LMU_RGNACCENA6.U = AccEnable;

  LMU_RGNACCENA7.U = AccEnable;

  LmuBusMpuLfmTst_lSetSafetyENDINIT(&WdtContext);
 
 } /* LmuBusMpuLfmTst_lSetupAccEn */

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static Sl_TstRsltType LmuBusMpuLfmTst_lRestore(         **
**                     const Sl_ParamSetType ParamSetIndex,                   **
**                LmuBusMpuLfmTst_BackupDataType* LmuBusMpuLfmTst_BackupData) **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Error information                                       **
**                                                                            **
** Description      : LmuBusMpuLfmTst_lRestore restores SFRs and SMU alarm    **
**                    actions that have been backed up and modified by test.  ** 
*******************************************************************************/
static Sl_TstRsltType LmuBusMpuLfmTst_lRestore
(  
  const Sl_ParamSetType ParamSetIndex,
  LmuBusMpuLfmTst_BackupDataType* LmuBusMpuLfmTst_BackupData  
)
{ 
  LmuBusMpuLfmTst_WdtContextType WdtContext;
  uint32 WordIndex;
  uint32* Source;
  uint32* Dest;  
  
  Sl_TstRsltType    Result = LMUBUSMPULFM_NOTEXECUTED;
  LmuBusMpuLfmTst_lResetSafetyENDINIT(&WdtContext); 

  /* Restore all RGNLAx and RGNUAx registers to the backup values */

  LMU_RGNLA0.U = LmuBusMpuLfmTst_BackupData->LMURGNLA0;
  LMU_RGNUA0.U = LmuBusMpuLfmTst_BackupData->LMURGNUA0;

  LMU_RGNLA1.U = LmuBusMpuLfmTst_BackupData->LMURGNLA1;
  LMU_RGNUA1.U = LmuBusMpuLfmTst_BackupData->LMURGNUA1;

  LMU_RGNLA2.U = LmuBusMpuLfmTst_BackupData->LMURGNLA2;
  LMU_RGNUA2.U = LmuBusMpuLfmTst_BackupData->LMURGNUA2;

  LMU_RGNLA3.U = LmuBusMpuLfmTst_BackupData->LMURGNLA3;
  LMU_RGNUA3.U = LmuBusMpuLfmTst_BackupData->LMURGNUA3;

  LMU_RGNLA4.U = LmuBusMpuLfmTst_BackupData->LMURGNLA4;
  LMU_RGNUA4.U = LmuBusMpuLfmTst_BackupData->LMURGNUA4;

  LMU_RGNLA5.U = LmuBusMpuLfmTst_BackupData->LMURGNLA5;
  LMU_RGNUA5.U = LmuBusMpuLfmTst_BackupData->LMURGNUA5;

  LMU_RGNLA6.U = LmuBusMpuLfmTst_BackupData->LMURGNLA6;
  LMU_RGNUA6.U = LmuBusMpuLfmTst_BackupData->LMURGNUA6;

  LMU_RGNLA7.U = LmuBusMpuLfmTst_BackupData->LMURGNLA7;
  LMU_RGNUA7.U = LmuBusMpuLfmTst_BackupData->LMURGNUA7;

  /* Restore all RGNACCENAx registers to the backup values:  */

  LMU_RGNACCENA0.U = LmuBusMpuLfmTst_BackupData->LMURGNACCENA0;

  LMU_RGNACCENA1.U = LmuBusMpuLfmTst_BackupData->LMURGNACCENA1;

  LMU_RGNACCENA2.U = LmuBusMpuLfmTst_BackupData->LMURGNACCENA2;

  LMU_RGNACCENA3.U = LmuBusMpuLfmTst_BackupData->LMURGNACCENA3;

  LMU_RGNACCENA4.U = LmuBusMpuLfmTst_BackupData->LMURGNACCENA4;

  LMU_RGNACCENA5.U = LmuBusMpuLfmTst_BackupData->LMURGNACCENA5;

  LMU_RGNACCENA6.U = LmuBusMpuLfmTst_BackupData->LMURGNACCENA6;

  LMU_RGNACCENA7.U = LmuBusMpuLfmTst_BackupData->LMURGNACCENA7;
    
  LmuBusMpuLfmTst_lSetSafetyENDINIT(&WdtContext);
  
  /* Clearing the INTACK bit, set by the test in Arbiter Control Register 4  */
  XBAR_ARBCON4.U |=(unsigned_int)((unsigned_int)IFX_XBAR_ARBCON_INTACK_MSK <<
   (unsigned_int)IFX_XBAR_ARBCON_INTACK_OFF);
  
  /* Clearing the PRSCI4 bit, set by the test in Arbiter Interrupt Status 
     Register */
  XBAR_INTSAT.U = ((uint32)1U << IFX_XBAR_INTSAT_PRSCI4_OFF);
 
  /* Clear the SRR bit of SRC_XBARSRC register*/
  SRC_XBARSRC.U = ((SRC_XBARSRC.U & LBMTST_XBARSRC_MASK) | (LBMTST_XBARSRC_CLEAR_BITS));
  
  /* Restore memory given in configuration */    
  Dest = LmuBusMpuLfmTst_ConfigRoot[ParamSetIndex].TestMemory;
  Source = &(LmuBusMpuLfmTst_BackupData->LmuBusMpuLfmTst_BackupMemory[0U]);
  for(WordIndex = 0U; 
      WordIndex < (LBM_TEST_RANGE_SIZE/LBM_CBM_SIZEOFWORD); WordIndex++)
  {
    Dest[WordIndex] = Source[WordIndex];
  }
       
  /* Restore SMU alarm action:                                              */
  if (LmuBusMpuLfmTst_BackupData->AlmActionLmuMpu != SMU_INVALID_ALARM_ACTION)
  {
  
    if (E_OK != Smu_SetAlarmAction(SMU_ALARM_GROUP2,
                                (uint8)SMU_ALARM_16,
                                LmuBusMpuLfmTst_BackupData->AlmActionLmuMpu))
    {
      Result = LMUBUSMPULFM_SMU_SETALMACTIONERR;
    }
  }
  
  if (LmuBusMpuLfmTst_BackupData->AlmActionSriBus != SMU_INVALID_ALARM_ACTION)
  {
    if (E_OK != Smu_SetAlarmAction(SMU_ALARM_GROUP3,
                                  (uint8)SMU_ALARM_30,
                                  LmuBusMpuLfmTst_BackupData->AlmActionSriBus))
    {
      Result = LMUBUSMPULFM_SMU_SETALMACTIONERR;
    }
  } 

  if ((boolean)FALSE != LmuBusMpuLfmTst_BackupData->ProtectionTrapRegistered)
  {
    if (TRAP_E_SUCCESS != TRAP_UnregisterTrapHandler(LBM_TRAP_CLASS4))
    {
      Result = LMUBUSMPULFM_TRAPERROR;
    } /* if (TRAP_E_SUCCESS != TRAP_UnregisterTrapHandler(LBM_TRAP_CLASS4)) */
  } /* if (FALSE != LmuBusMpuLfmTst_BackupData->ProtectionTrapRegistered) */
  
  if (Result == LMUBUSMPULFM_NOTEXECUTED)
  {
    Result = LMUBUSMPULFM_SUCCESS;
  }
  return Result;
} /* LmuBusMpuLfmTst_lRestore */

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           :static Sl_TstRsltType LmuBusMpuLfmTst_lCheckRangeError   **
**                   ( const uint8 AccessExpected,                            **
**                     uint32* const TstSignature                             **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters(in)   :                                                         **
**                    ParamSetIndex - Identifies the parameter set to be      **
**                    used for test execution                                 **
**                    AccessExpected - Specifies whether or not access to the **
**                    memory ranges was expected                              **
**                                                                            **
** Parameters (out) : TstSignature - Test signature generated by the Test     **
**                                                                            **
** Return value     : Error information                                       **
**                                                                            **
** Description      : LmuBusMpuLfmTst_lCheckRangeError checks whether an      **
**                    access to a test memory range was granted or denied as  **
**                    expected. If the access was expected to be granted, it  **
**                    checks that no SMU alarm was triggered and that no      **
**                    trap is raised. If access was indeed expected to be     **
**                    denied, it checks that a SMU alarm was triggered and a  ** 
**                    trap should occur. Furthermore                          **
**                    LmuBusMpuLfmTst_lCheckRangeError clears LMU MPU and     **
**                    SRI Bus SMU alarms.                                     **
*******************************************************************************/
static Sl_TstRsltType LmuBusMpuLfmTst_lCheckRangeError
(  
  uint8 AccessExpected,
  uint32* const TstSignature
)
{
  Sl_TstRsltType Result = LMUBUSMPULFM_NOTEXECUTED;
  uint32 SmuAlarmStatus1 = 0x0U;
  uint32 SmuAlarmStatus2 = 0x0U;
  Sl_TstRsltType Result1 = E_NOT_OK;
  Sl_TstRsltType Result2 = E_NOT_OK;  
  volatile uint32 MaskValue1 = 0U;
  volatile uint32 MaskValue2 = 0U;
  
  Result1 = Smu_GetAlarmStatus(SMU_ALARM_GROUP2,&SmuAlarmStatus1);
  SmuAlarmStatus1 = (SmuAlarmStatus1 & LBM_SMU_LMU_MPU_ERROR_STS);
  
  Result2 = Smu_GetAlarmStatus(SMU_ALARM_GROUP3,&SmuAlarmStatus2);
  SmuAlarmStatus2 = (SmuAlarmStatus2 & LBM_SMU_SRI_BUS_ERROR_STS);
  
  if ((Result1 != E_OK) || (Result2 != E_OK))
  {
    Result = LMUBUSMPULFM_SMU_GETALMSTSERR;
  }
  else
  {
    if(TRUE == AccessExpected)
    {
      MaskValue1 = LBM_SMU_LMU_MPU_ERROR_STS;
      MaskValue2 = LBM_SMU_SRI_BUS_ERROR_STS;
      if (Lmu_DaeTrapCount > 0U)
      {
        Result = LMUBUSMPULFM_TRAPERROR;
      }
    }
    else
    {
      if (Lmu_DaeTrapCount != 1U)
      {
        Result = LMUBUSMPULFM_TRAPERROR;
      } 
    }
      
    if(SmuAlarmStatus1 == MaskValue1)
    {
      /* LMU MPU Alarm is set */
      Result = LMUBUSMPULFM_SMU_ALMSTSERR;
    }
    else if(SmuAlarmStatus2 == MaskValue2)
    {
      /* LMU MPU Alarm is set */
      Result = LMUBUSMPULFM_SMU_ALMSTSERR;
    }
    else
    {
      /* added for MISRA */
    }
  }
  if(Lmu_DaeTrapCount > 0U)
  {
    /* Clear CPU_DATR Trap request */
    MTCR(CPU_DATR, 0x0U);
    /* Clear Lmu_DaeTrapCount Trap counter */      
    Lmu_DaeTrapCount = 0x0U;
  }

  if (0U != (SmuAlarmStatus1 & ((uint32)1U << SMU_ALARM_16)))
  {
    Result1 = LmuBusSmu_lClearAlarmStatus(SMU_ALARM_GROUP2,(uint8)SMU_ALARM_16);
  }
  if (0U != (SmuAlarmStatus2 & ((uint32)1U << SMU_ALARM_30)))
  {
    Result2 = LmuBusSmu_lClearAlarmStatus(SMU_ALARM_GROUP3,(uint8)SMU_ALARM_30);
  }
  if((E_OK != Result1) || (E_OK != Result2))
  {
    if(LMUBUSMPULFM_SMU_GETALMSTSERR != Result)
    {
      Result = LMUBUSMPULFM_SMU_CLRALMSTSERR;
    }
  } 
  if(LMUBUSMPULFM_NOTEXECUTED == Result)
  {
    Result = LMUBUSMPULFM_SUCCESS;
  }
  /* Test Signature */
  *TstSignature = (uint32)CRC32(*TstSignature,Result); 

  return Result;
} /* LmuBusMpuLfmTst_lCheckRangeError */

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           :static Sl_TstRsltType LmuBusMpuLfmTst_lFillAndCmpRanges  **
**                    (const Sl_ParamSetType ParamSetIndex,                   **
**                     uint32* const TstSignature                             **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters(in)   :                                                         **
**                    ParamSetIndex - Identifies the parameter set to be      **
**                    used for test execution                                 **
**                                                                            **
** Parameters (out) : TstSignature - Test signature generated by the Test     **
**                                                                            **
** Return value     : Error information                                       **
**                                                                            **
** Description      : LmuBusMpuLfmTst_lFillAndCmpRanges fills all protected   **
**                    memory ranges with test patterns and checks whether or  **
**                    not data has been written by reading back all data and  **
**                    comparing it to the test patterns again. Furthermore it **
**                    checks that no LMU MPU and SRI Bus alarms are raised    ** 
**                    and no DAE traps are raised.                            **
*******************************************************************************/
static Sl_TstRsltType LmuBusMpuLfmTst_lFillAndCmpRanges
(
  const Sl_ParamSetType ParamSetIndex,
  uint32* const TstSignature
)
{
  Sl_TstRsltType Result    = LMUBUSMPULFM_NOTEXECUTED;
  Sl_TstRsltType ResultTmp = LMUBUSMPULFM_NOTEXECUTED;
 
  ResultTmp = LmuBusMpuLfmTst_lFillAndCmpRange(ParamSetIndex,
                                               TstSignature
                                               );

  if(LMUBUSMPULFM_SUCCESS == ResultTmp)
  {
    ResultTmp = LmuBusMpuLfmTst_lCheckRangeError(TRUE,
                                                  TstSignature
                                                  );
    if(LMUBUSMPULFM_SUCCESS != ResultTmp)
    {
      Result = ResultTmp;
    }
  }
  else
  {
    Result = ResultTmp;
  }
 
   
  if(Result == LMUBUSMPULFM_NOTEXECUTED)
  {
    Result = LMUBUSMPULFM_SUCCESS;
  }

   return Result;
} /* LmuBusMpuLfmTst_lFillAndCmpRanges */

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           :static Sl_TstRsltType LmuBusMpuLfmTst_lFillAndCmpRange   **
**                    (const Sl_ParamSetType ParamSetIndex,                   **
**                     uint32* const TstSignature                             **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters(in)   :                                                         **
**                    ParamSetIndex - Identifies the parameter set to be      **
**                    used for test execution                                 **
**                                                                            **
** Parameters (out) : TstSignature - Test signature generated by the Test     **
**                                                                            **
** Return value     : Error information                                       **
**                                                                            **
** Description      : LmuBusMpuLfmTst_lFillAndCmpRange fills a single         **
**                    protected memory ranges with the test pattern. If       **
**                    access to the memory range is expected to be granted,   **
**                    it afterwards checks that the data got actually         **
**                    written by reading back and comparing the whole memory  **
**                    range to the test pattern.                              **
*******************************************************************************/
Sl_TstRsltType LmuBusMpuLfmTst_lFillAndCmpRange
(
  const Sl_ParamSetType ParamSetIndex,
  uint32* const TstSignature
)
{
  Sl_TstRsltType Result;
  uint32 i;
  
  Result = LMUBUSMPULFM_NOTEXECUTED;

  ISYNC();
  /* Fill memory range with test pattern:                                    */
  MEMCPY64((uint32)LmuBusMpuLfmTst_ConfigRoot[ParamSetIndex].TestMemory,
             (uint32)LBM_kTestPattern,
             LBM_TEST_RANGE_SIZE / LBM_CBM_SIZEOFWORD);
  ISYNC();

  for(i = 0U; i < ((uint32)LBM_TEST_RANGE_SIZE / LBM_CBM_SIZEOFWORD); i++)
  {
    if(LBM_kTestPattern[i]
        != (LmuBusMpuLfmTst_ConfigRoot[ParamSetIndex].TestMemory[i]))
    {
      Result = LMUBUSMPULFM_ACCDENY_RGNERR;
    }
  }
 
  if(LMUBUSMPULFM_NOTEXECUTED == Result)
  {
    Result = LMUBUSMPULFM_SUCCESS;
  }

  *TstSignature = (uint32)CRC32(*TstSignature,Result);
  return Result;
} /* LmuBusMpuLfmTst_lFillAndCmpRange */


/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           :static Sl_TstRsltType LmuBusMpuLfmTst_lClrAndCmpRanges   **
**                    (const Sl_ParamSetType ParamSetIndex,                   **
**                     uint32* const TstSignature                             **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters(in)   :                                                         **
**                    ParamSetIndex - Identifies the parameter set to be      **
**                    used for test execution                                 **
**                                                                            **
** Parameters (out) : TstSignature - Test signature generated by the Test     **
**                                                                            **
** Return value     : Error information                                       **
**                                                                            **
** Description      : LmuBusMpuLfmTst_lClrAndCmpRanges checks, when this func **
**  is called from NonSafeAcc the access is denied for the safe DMI  master   **
**  and it should not  clear all protected memory ranges to zero. when this   **
**  function is called from SafeAcc the access is denied for the Non Safe DMI **
**  master and it should not clear all protected memory ranges to zero.       **
**  Furthermore it checks that  the LMU MPU and SRI Bus alarms are raised.    **
**  Also the DAE trap is raised.                                              **
*******************************************************************************/
Sl_TstRsltType LmuBusMpuLfmTst_lClrAndCmpRanges
(
  const Sl_ParamSetType ParamSetIndex,
  uint32* const TstSignature
)
{
  Sl_TstRsltType  Result    = LMUBUSMPULFM_NOTEXECUTED;
  Sl_TstRsltType  ResultTmp = LMUBUSMPULFM_NOTEXECUTED;
 
  ResultTmp = LmuBusMpuLfmTst_lClrAndCmpRange(ParamSetIndex,
                                              TstSignature);
  if(LMUBUSMPULFM_SUCCESS != ResultTmp)
  {
    Result = ResultTmp;
  }
  else
  {
    ResultTmp = LmuBusMpuLfmTst_lCheckRangeError(FALSE,
                                                 TstSignature);
    if(LMUBUSMPULFM_SUCCESS != ResultTmp)
    {
      Result = ResultTmp;
    }
  }
  
  if(LMUBUSMPULFM_NOTEXECUTED == Result)
  {
    Result = LMUBUSMPULFM_SUCCESS;
  }

  return Result;
} /* LmuBusMpuLfmTst_lClrAndCmpRanges */

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           :static Sl_TstRsltType LmuBusMpuLfmTst_lClrAndCmpRange    **
**                    (const Sl_ParamSetType ParamSetIndex,                   **
**                     uint32* const TstSignature                             **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters(in)   :                                                         **
**                    ParamSetIndex - Identifies the parameter set to be      **
**                    used for test execution                                 **
**                                                                            **
** Parameters (out) : TstSignature - Test signature generated by the Test     **
**                                                                            **
** Return value     : Error information                                       **
**                                                                            **
** Description      : LmuBusMpuLfmTst_lClrAndCmpRange checks, when this func  **
**  is called from NonSafeAcc the access is denied for the safe DMI  master   **
**  and it should not  clear all protected memory ranges to zero. when this   **
**  function is called from SafeAcc the access is denied for the Non Safe DMI **
**  master and it should not clear all protected memory ranges to zero.       **
**  Furthermore it checks that  the LMU MPU and SRI Bus alarms are raised.    **
**  Also the DAE trap is raised.                                              **
*******************************************************************************/
static Sl_TstRsltType LmuBusMpuLfmTst_lClrAndCmpRange
(
  const Sl_ParamSetType ParamSetIndex,
  uint32* const TstSignature
)
{
  Sl_TstRsltType Result;  
  volatile uint32 MemoryVal;
  Result = LMUBUSMPULFM_NOTEXECUTED;
  
  /* Clear the memory range to zero: */      
  /* Trap expected here. expected trap class and ID is updated   */
  Lmu_ExpectedTrapClass = LBM_TRAP_CLASS4;      
  Lmu_ExpectedTrapId = LBM_TRAP_ID3; 
  *((volatile uint32*) (volatile void*)
       (LmuBusMpuLfmTst_ConfigRoot[ParamSetIndex].TestMemory)) = 0U;
  ISYNC();
  DSYNC();
  
  MemoryVal = 
   *((volatile uint32*) (volatile void*) 
       (LmuBusMpuLfmTst_ConfigRoot[ParamSetIndex].TestMemory));
  if(MemoryVal != LBM_kTestPattern[0U])
  {
    Result = LMUBUSMPULFM_ACCGRANT_RGNERR;
  }

  
  if(LMUBUSMPULFM_NOTEXECUTED == Result)
  {
    Result = LMUBUSMPULFM_SUCCESS;
  }
  
  *TstSignature = (uint32)CRC32(*TstSignature,Result);
  
  return Result;
}/* LmuBusMpuLfmTst_lClrAndCmpRange */

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           :static Sl_TstRsltType                                    **
**                                  LmuBusMpuLfmTst_lCheckUnauthorizedAddr    **
**                    (const Sl_ParamSetType ParamSetIndex,                   **
**                     uint32* const TstSignature                             **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters(in)   :                                                         **
**                    ParamSetIndex - Identifies the parameter set to be      **
**                    used for test execution                                 **
**                                                                            **
** Parameters (out) : TstSignature - Test signature generated by the Test     **
**                                                                            **
** Return value     : Error information                                       **
**                                                                            **
** Description      : Performs a write access to an address not covered by    **
**                    any memory protection range and checks that this        **
**                    unauthorized access triggers an SMU alarm and DAE trap  **
*******************************************************************************/
static Sl_TstRsltType LmuBusMpuLfmTst_lCheckUnauthorizedAddr
(
  const Sl_ParamSetType ParamSetIndex,
  uint32* const TstSignature
)
{
  Sl_TstRsltType  Result    = LMUBUSMPULFM_NOTEXECUTED;  
  uint32   AlmStatus1 = 0x0U;
  uint32   AlmStatus2 = 0x0U;
  uint32*         TestAddress;

  Sl_TstRsltType Result1 = E_NOT_OK;
  Sl_TstRsltType Result2 = E_NOT_OK; 
  uint32         Timeout = LBM_ENABLE_TIMEOUT;  
  
  TestAddress = *LmuBusMpuLfmTst_ConfigRoot[ParamSetIndex].UnauthorizedAddr;

  /*  The unauthorised access takes place here */
  Lmu_DaeTrapCount = 0x0U;
  
  /* Trap expected here. expected trap class and ID is updated   */
  Lmu_ExpectedTrapClass = LBM_TRAP_CLASS4;
  Lmu_ExpectedTrapId = LBM_TRAP_ID3;

  /* Invert 32bit value at location TestAddress: Trap is expected here */
  *TestAddress ^= *TestAddress;

  ISYNC();
  
  do
  {
    Timeout = Timeout - 1U;
    /* wait until module is enabled */
  }while ((Lmu_DaeTrapCount != 1U) && (0U < Timeout));  
  
  if(Lmu_DaeTrapCount != 0x1U)
  {
    Result = LMUBUSMPULFM_TRAPERROR;
  }

  else if(E_OK != Smu_GetAlarmStatus(SMU_ALARM_GROUP2, &AlmStatus1))
  {
    Result = LMUBUSMPULFM_SMU_GETALMSTSERR;
    AlmStatus1 = 0U;
  }

  else if((AlmStatus1 & LBM_SMU_LMU_MPU_ERROR_STS) == LBM_SMU_ALM_NOT_SET)
  {
    Result = LMUBUSMPULFM_SMU_ALMSTSERR;
  }

  else if(E_OK != Smu_GetAlarmStatus(SMU_ALARM_GROUP3, &AlmStatus2))
  {
    Result = LMUBUSMPULFM_SMU_GETALMSTSERR;
    AlmStatus2 = 0U;
  }

  else if((AlmStatus2 & LBM_SMU_SRI_BUS_ERROR_STS) == LBM_SMU_ALM_NOT_SET)
  {
    Result = LMUBUSMPULFM_SMU_ALMSTSERR;
  }
  else
  {
    Result1 = LmuBusSmu_lClearAlarmStatus(SMU_ALARM_GROUP2,(uint8)SMU_ALARM_16);
    Result2 = LmuBusSmu_lClearAlarmStatus(SMU_ALARM_GROUP3,(uint8)SMU_ALARM_30);

    /* Clear DAE Trap request                                             */
    MTCR(CPU_DATR, 0x0U);
    /* Clear DAE TrapCounter                                              */    
    Lmu_DaeTrapCount = 0x0U;
    
    if((E_OK != Result1) || (E_OK != Result2))
    {
      Result = LMUBUSMPULFM_SMU_CLRALMSTSERR;
    }
  }

  if(LMUBUSMPULFM_NOTEXECUTED == Result)
  {
    Result = LMUBUSMPULFM_SUCCESS;
  }

  *TstSignature = (uint32)CRC32(*TstSignature,Result);
  return Result;
}

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static void LmuBusMpuLfmTst_lResetSafetyENDINIT         **
**                        (LmuBusMpuLfmTst_WdtContextType* const WdtContext)  **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : WdtContext - Pointer to LmuBusMpuLfmTst_WdtContextType  **
**                                 structure that will receive previous       **
**                                 interrupt enable and timer reload value.   **
**                                 The same pointer must be passed to the     **
**                                 subsequent call to                         **
**                                 LmuBusMpuLfmTst_lSetSafetyENDINIT          **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Clears the ENDINIT bit in the global safety Watchdog.   **
**                    Proper password is calculated and restored on modify    **
**                    access. Disables interrupts and save current Wdt timer  **
**                    reload value.                                           **
**                                                                            **
*******************************************************************************/
static void LmuBusMpuLfmTst_lResetSafetyENDINIT
(
  LmuBusMpuLfmTst_WdtContextType* const WdtContext
)
{
  uint32 NewValCon0;
  uint32 NewPw;                   /* next password to be used */
  uint32 NewRel;                  /* next reload value to be used */
  volatile uint32 dummy;          /* ensure readback */

  /* Save old value */
  NewValCon0  = SCU_WDTSCON0.U;

  /* Get valid next password: */
  NewPw = NewValCon0 & LBM_WDT_PASSWORD_MASK;

  /* - First generate proper password write value
       (include PW Bit8-15 and inverted PW Bit 2-7) */
  NewPw = (NewPw & LBM_WDT_PASSWORD_UPPER_MASK) |
              ((~(NewPw & LBM_WDT_PASSWORD_LOWER_MASK)) &
              LBM_WDT_PASSWORD_LOWER_MASK);

  /* - Additionally auto sequence password enabled ? */
  if (SCU_WDTSSR.B.PAS != 0u)
  {
    /* Modify password with expected password by calculating new 14-bit LFSR
     * with characteristic polynomial x14+x13+x12+x2+1.
     */
    uint32 lfsr = NewPw;
    uint32 bit  = ((lfsr>>1) ^ (lfsr>>11) ^ (lfsr>>12) ^ (lfsr>>13)) & 0x0004u;
    NewPw       = (((lfsr << 1) | bit) & LBM_WDT_PASSWORD_MASK);
  } /* if (SCU_WDTSSR.B.PAS != 0u) */

  /* Get valid next timer reload: */
  /* - Timer check enabled ? */
  if (SCU_WDTSSR.B.TCS != 0u)
  {
    NewRel = (uint32)((~(uint32)SCU_WDTSSR.B.TIM) << 16);
  } /*if (SCU_WDTSSR.B.TCS != 0u) */
  else
  {
    NewRel = NewValCon0 & LBM_WDT_RELOAD_MASK;
  } /*if (SCU_WDTSSR.B.TCS == 0u) */

  /* Build required password WDTCON0 value */
  NewValCon0 =  ((NewRel) |              /* new reload value  */
                 (NewPw)  |              /* new Password */
                 (1u));                  /* Clear LCK, keep ENDINIT set */

  /* Read and save current timer and password to be restored with
   * SetENDINIT
   */
  WdtContext->WdtTimAndPw = SCU_WDTSSR.U & (uint32)LBM_WDT_RELOAD_MASK;
  WdtContext->WdtTimAndPw |= SCU_WDTSCON0.U & (uint32)LBM_WDT_PASSWORD_MASK;

  SCU_WDTSCON0.U  = NewValCon0;        /* password access to unlock */

  NewValCon0 &= ~LBM_WDT_STATUS_MASK;   /* clear ENDINIT and LCK Bit */
  NewValCon0 |= 0x2u;                    /* set LCK Bit */

  SCU_WDTSCON0.U = NewValCon0;  /* write access and lock for Timeout mode */

  /* Read back to ensure protection release is executed */
  dummy = SCU_WDTSCON0.U;
  UNUSED_PARAMETER(dummy)
} /* LmuBusMpuLfmTst_lResetSafetyENDINIT */


/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static void LmuBusMpuLfmTst_lSetSafetyENDINIT           **
**                   (const LmuBusMpuLfmTst_WdtContextType* const WdtContext) **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters(in)   : WdtContext - Pointer to LmuBusMpuLfmTst_WdtContextType  **
**                                 structure that was filled by preceding     **
**                                 LmuBusMpuLfmTst_lResetSafetyENDINIT call.  **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Sets the ENDINIT bit in the global safety watchdog.     **
**                    Proper password is calculated and restored on modify    **
**                    access. Enables interrupts and restores Wdt timer       **
**                    reload value.                                           **
**                                                                            **
*******************************************************************************/
static void LmuBusMpuLfmTst_lSetSafetyENDINIT
(
  const LmuBusMpuLfmTst_WdtContextType* const WdtContext
)
{
  uint32 NewValCon0;
  uint32 NewPw;                   /* next password to be used */
  uint32 NewRel;                  /* next timer reload to be used */
  volatile uint32 dummy;          /* ensure readback */

  /* Save old value */
  NewValCon0  = SCU_WDTSCON0.U;

  /* Get valid next password: */
  NewPw = NewValCon0 & LBM_WDT_PASSWORD_MASK;

  /* - First generate proper password write value
       (include PW Bit8-15 and inverted PW Bit 2-7) */
  NewPw = (NewPw & LBM_WDT_PASSWORD_UPPER_MASK) |
          ((~(NewPw & LBM_WDT_PASSWORD_LOWER_MASK)) &
           LBM_WDT_PASSWORD_LOWER_MASK);

  /* - Additionally auto sequence password enabled ? */
  if (SCU_WDTSSR.B.PAS != 0u)
  {
    /* Modify password with expected password by calculating new 14-bit LFSR
     * with characteristic polynomial x14+x13+x12+x2+1.
     */
    uint32 lfsr = NewPw;
    uint32 bit  = ((lfsr>>1) ^ (lfsr>>11) ^ (lfsr>>12) ^ (lfsr>>13)) & 0x0004u;
    NewPw       = (((lfsr << 1) | bit) & LBM_WDT_PASSWORD_MASK);
  } /* if (SCU_WDTSSR.B.PAS != 0u) */

  /* Get valid next timer reload: */
  /* Timer check enabled ? */
  if (SCU_WDTSSR.B.TCS != 0u)
  {
    NewRel = (uint32)((~(uint32)SCU_WDTSSR.B.TIM) << 16);
  } /*if (SCU_WDTSSR.B.TCS != 0u) */
  else
  {
    NewRel = NewValCon0 & LBM_WDT_RELOAD_MASK;
  } /*if (SCU_WDTSSR.B.TCS == 0u) */

  /* Build required password WDTCON0 value */
  NewValCon0  =  ((NewRel) |             /* new reload value  */
                  (NewPw)  |             /* new Password */
                  (1u));                 /* Clear LCK, keep ENDINIT set */

  SCU_WDTSCON0.U = NewValCon0;         /*  unlock with password access */

  /* Clear timer reload and restore saved and corrected reload value */
  NewValCon0 &= ~LBM_WDT_RELOAD_MASK;

  /* Set timer value back to prior value and add ticks during timeout mode */
  NewValCon0 |= (WdtContext->WdtTimAndPw +
                 ((SCU_WDTSSR.U & (uint32)LBM_WDT_RELOAD_MASK) -
                 (uint32)LBM_SDWT_TIMEOUT_MOD_RELOAD));

  /* Prepare old password to be restored with modify access*/
  NewValCon0 &= ~LBM_WDT_PASSWORD_MASK;
  NewValCon0 |= (WdtContext->WdtTimAndPw &
                 (uint32)LBM_WDT_PASSWORD_UPPER_MASK) |
                 ((~(WdtContext->WdtTimAndPw &
                     (uint32)LBM_WDT_PASSWORD_LOWER_MASK))
                 & (uint32)LBM_WDT_PASSWORD_LOWER_MASK);

  /* Prepare modify & lock access */
  NewValCon0 |= 3u;                    /* set LCK and ENDINIT Bit */
  SCU_WDTSCON0.U = NewValCon0;         /* write modify access and lock */

  /* Read back to ensure protection release is executed */
  dummy = SCU_WDTSCON0.U;
  UNUSED_PARAMETER(dummy)
} /* LmuBusMpuLfmTst_lSetSafetyENDINIT */


/*******************************************************************************
** Traceability      : [cover parentID=]        [/cover]                      **
**                                                                            **
** Syntax           : static Std_ReturnType LmuBusSmu_lClearAlarmStatus       **
**                                                       (uint8 AlarmGroup,   **
**                      uint8 AlarmPos)                                       **
**                                                                            **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Re-entrant                                              **
**                                                                            **
** Parameters(in)   : AlarmGroup : Alarm group register                       **
**                      AlarmPos : Alarm position within the requested group  **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : E_OK - Operation successfully performed                 **
**                    E_NOT_OK - Operation failed eg. Due to invalid          **
**                      parameters.                                           **
**                                                                            **
** Description      : This service clears SMU alarm status of the requested   **
**                    alarm. It needs to be called after alarm status is read.**
**                                                                            **
*******************************************************************************/
static Std_ReturnType LmuBusSmu_lClearAlarmStatus
(
  uint8 AlarmGroup,
  uint8 AlarmPos
)
{
  LmuBusMpuLfmTst_WdtContextType WdtContext;
  Std_ReturnType RetVal;
  uint32 Timeout;
  uint32 AlarmStatusReadback;
  RetVal = E_OK;  

  /* Write SMU_ASCE(0) in CMD register */
  SMU_CMD.U = SMU_ASCE_COMMAND;

  /* disable the write-protection for registers */
  LmuBusMpuLfmTst_lResetSafetyENDINIT(&WdtContext);
    
  /* Write 1 in AG bit to clear alarm */
  LBM_SMU_ALARM_GROUP->AGStatusReg[AlarmGroup].U = 
                       (unsigned_int)((unsigned_int)0x1U<<AlarmPos);

  /* Restore back the write-protection for registers */
  LmuBusMpuLfmTst_lSetSafetyENDINIT(&WdtContext);
     
  /*Read back AG register to validate the Clear */
  Timeout = 0U;
  do
  {
    /* Read Alarm status */
    AlarmStatusReadback =
       (((uint32)(LBM_SMU_ALARM_GROUP->AGStatusReg[AlarmGroup].U) >> AlarmPos) &
        0x1U);
   Timeout++;
  }while((Timeout < SMU_AGSTATUS_TIMEOUT) && (AlarmStatusReadback != 0U) );

  if(AlarmStatusReadback != 0U)
  {
    RetVal = (Std_ReturnType)E_NOT_OK;
  }  

  return RetVal;
  
}/* LmuBusSmu_lClearAlarmStatus */

#define IFX_LMUBUSMPULFM_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"


