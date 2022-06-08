/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2016)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**   $FILENAME   : SpbTst.c $                                                 **
**                                                                            **
**   $CC VERSION : \main\44 $                                                 **
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
**  DESCRIPTION  : This file provides latent fault metric test routines for   **
**                 the System Peripheral Bus Test.                            **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Mcal.h"
#include "SpbTst.h"
#include "IfxCpu_reg.h"
#include "IfxSbcu_reg.h"
#include "IfxMtu_reg.h"
#include "IfxMc_reg.h"
#include "Mtl_Trap.h"
#include "SmuInt.h"
#include "IfxInt_reg.h"
#include "IfxCpu_bf.h"
#include "IfxXbar_reg.h"
#include "IfxSrc_reg.h"

/*******************************************************************************
**                      Local Macro Definitions                               **
*******************************************************************************/

/* ACCEN bitmasks for CPU0 DMI.NonSafe and CPU0 DMI.Safe Master TAG IDs:      */
#define SPBTST_RAP_CPU0_NONSAFE_DMI        ( 0x00000001U )
#define SPBTST_RAP_CPU0_SAFE_DMI           ( 0x00000002U )

/* ACCEN bitmasks for CPU1 DMI.NonSafe and CPU1 DMI.Safe Master TAG IDs:      */
#define SPBTST_RAP_CPU1_NONSAFE_DMI        ( 0x00000004U )
#define SPBTST_RAP_CPU1_SAFE_DMI           ( 0x00000008U )

/* ACCEN bitmasks for CPU2 DMI.NonSafe and CPU2 DMI.Safe Master TAG IDs:      */
#define SPBTST_RAP_CPU2_NONSAFE_DMI        ( 0x00000010U )
#define SPBTST_RAP_CPU2_SAFE_DMI           ( 0x00000020U )

/* SBCU_ECON Expected */
/* Expected value of SBCU_ECON = 0x10594001 (CPU0),0x10D94001 (CPU1),0x11594001U(CPU2) 
   0x10594001 can be segregated as below:
	 Errcnt - Bitfield is (0to13)- Expected value is 1 (Error Count)
	 TOUT   - Bitfield is (14)   - Expected value is 1 (Time-out has Occurred)
	 RDY    - Bitfield is (15)   - Expected value is 0 (Wait state(s) have been inserted. Ready signal
   was active)
	 ABT    - Bitfield is (16)   - Expected value is 1 (Abort signal was inactive)
	 ACK    - Bitfield is (17,18)- Expected value is 0 (NSC: No Special Condition)
	 SVM    - Bitfield is (19)   - Expected value is 1 (Transfer was initiated in Supervisor Mode)
	 WRN    - Bitfield is (20)   - Expected value is 1 (FPI Bus error occurred at a read cycle of a single transfer.)
	 RDN    - Bitfield is (21)   - Expected value is 0 (FPI Bus error occurred at a read cycle of a single transfer.)
	 TAG    - Bitfield is (22 to 27)- Expected value is 1 (CPU0), 2(CPU1),5(CPU2) (DMI.Safe TAG ID)
	 OPC    - Bitfield is (28 to 31)- Expected value is 1 (Single Half-Word Transfer (16-bit))
*/
#define SPBTST_TIMEOUT_CPU0_SBCU_ECON_VAL  ( 0x10594001U )
#define SPBTST_TIMEOUT_CPU1_SBCU_ECON_VAL  ( 0x10D94001U )
#define SPBTST_TIMEOUT_CPU2_SBCU_ECON_VAL  ( 0x11594001U )

/* Bitmask for setting / clearing the S bit (Safety Task Identifier)
 *  in the PSW:        */
#define SPBTST_PSW_SAFETY_BIT         ((uint32)((uint32)IFX_CPU_PSW_S_MSK << IFX_CPU_PSW_S_OFF ))

/* SMU alarm timeout. The value was chosen based on following considerations:
 * The worst case number of SMU cycles before an alarm gets visible is
 * n * 2 + 20 (with n = max. number of simultaneous alarms). With a maximum
 * of 32 * 7 alarms and maximum clock ratio fSPB/fSRI = 1/4 this evaluates to
 * 1872 CPU clock cycles. To avoid the counting the number of instructions per
 * loop cycle, it is assumed that only one instruction is executed per loop
 * cycle and thus the number of CPU clock cycles is directly used as timeout
 * value:
 */
#define SPBTST_SMU_ALM_TIMEOUT             ( 2000U )

/* Timeout for enabling the MTU clock. As there is no information available
 * about how much time is required to enable the MTU clock, this value was
 * arbitrarily chosen to a relatively high value:
 */
#define SPBTST_TIMEOUT_MTU_ENABLE_TIMEOUT  ( 0x100U )

/* Timeout for SPB Error. As there is no information available
 * about how much time is required to get the timeout error, this value was
 * arbitrarily chosen to a relatively low value
 */
#define SPBTST_TIMEOUT_ERROR_TIMEOUT       ( 0x00000005U )

/* SPB TRAP */
#define SPBTST_TRAP_CLASS                  ( 0x04U )

/* Peripheral Enable */
#define SPBTST_MODULE_ENABLE               ((uint32)0x00000000U)

/* Enable Peripherals having RMC bitfield */
#define SPBTST_MODULE_ENABLE_RMC           ((uint32)0x00000100U)

/* Address of  INT_ACCEN00 and INT_ACCEN10 */
#define SPBTST_INT_ACCEN00_ADD             ((uint32)(&INT_ACCEN00))
#define SPBTST_INT_ACCEN10_ADD             ((uint32)(&INT_ACCEN10))

/* Address of  MTU_ACCEN0 */
#define SPBTST_MTU_ACCEN0_ADD              ((uint32)(&MTU_ACCEN0))


#define SPBTST_RAP_SAFE                    (0U)
#define SPBTST_RAP_NON_SAFE                (1U)

/* Expected traps: */
#define SPBTST_NO_TRAP                     (0U)
#define SPBTST_REGISTER_ACCESS_TRAP        (3U)
#define SPBTST_TIMEOUT_TRAP                (2U)

#define SPBTST_MINIMUM_DELAY               (25U)
#define SPBTST_CLC_DISS_MASK               (0x2U)

/* Macros to restore XBAR register bits which are changed during SPB test execution */
#define SPBTST_ARBCON6_CLEAR               ((unsigned_int)0x10U)
#define SPBTST_ARBCOND_CLEAR               ((unsigned_int)0x10U)
#define SPBTST_INTSAT_CLEAR                ((unsigned_int)0x80400000U)

/* SBCU CON mask value */
#define SPBTST_SBCU_CON_MASK               ((unsigned_int)0xFF01FFFFU)
#define SPBTST_SBCU_CON_MASK_TOUT_ZERO     ((unsigned_int)0xFF010000U)
#define SPBTST_TOUT_VALUE                  ((unsigned_int)0x0004U)

/* Clear SRC_BCUSPBSBSRC, XBARSRC Service Request Flag */
#define SPBTST_BCUSPBSBSRC_MASK            ((unsigned_int)0x293F1CFFU)
#define SPBTST_BCUSPBSBSRC_CLEAR_BITS      ((unsigned_int)0x02000000U)
#define SPBTST_XBARSRC_MASK                (SPBTST_BCUSPBSBSRC_MASK)
#define SPBTST_XBARSRC_CLEAR_BITS          (SPBTST_BCUSPBSBSRC_CLEAR_BITS)

/* Macros defined with Core numbers*/
#define SPBTST_CORE0                       (0U)
#if (MCAL_NO_OF_CORES > 1U)
#define SPBTST_CORE1                       (1U)
#if (MCAL_NO_OF_CORES == 3U)
#define SPBTST_CORE2                       (2U)
#endif /* #if (MCAL_NO_OF_CORES == 3U)*/
#endif /* #if (MCAL_NO_OF_CORES > 1U)*/
 
/*******************************************************************************
**                      Local Type Definitions                                **
*******************************************************************************/

/*******************************************************************************
**                        Exported object definitions                         **
*******************************************************************************/

/*******************************************************************************
**                        Local object definitions                            **
*******************************************************************************/
#define IFX_SPBTST_START_SEC_VAR_32BIT_ASIL_B
#include "Ifx_MemMap.h"

static volatile uint32  SpbRegAccProtTst_DaeTrapCount;
static volatile uint32  SpbRegAccProtTst_ExpectedTrap;
static volatile uint32  SpbTimeoutTst_DseTrapCount;
static volatile uint32  SpbTimeoutTst_ExpectedTrap;

#define IFX_SPBTST_STOP_SEC_VAR_32BIT_ASIL_B
#include "Ifx_MemMap.h"
#define IFX_SPBTST_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
/*******************************************************************************
**                        Imported function declarations                      **
*******************************************************************************/

/*******************************************************************************
**                        Local function prototypes                           **
*******************************************************************************/

static Sl_TstRsltType SpbTst_lInit
(
  SpbRegAccProtTst_BackupDataType* const SpbRegAccProt_BackupData,
  const Sl_ParamSetType ParamSetIndex, 
  uint8 PeriCount
);

static Sl_TstRsltType SpbTst_lRestore
(
  const SpbRegAccProtTst_BackupDataType* SpbRegAccProt_BackupData,
  const Sl_ParamSetType ParamSetIndex,
  uint8 PeriCount
);

static Sl_TstRsltType SpbTst_lDenyAccTst
(
  const Sl_ParamSetType ParamSetIndex, 
  uint32* const TstSignature, 
  uint8 PeriCount,
  boolean CpuPsw
);

static Sl_TstRsltType SpbTst_lWaitForSmuAlarm
(
  const Sl_ParamSetType ParamSetIndex, 
  uint8 PeriCount
);

static Sl_TstRsltType SpbTst_lTimeoutInit
(
  SpbTimeoutTst_BackupDataType* const SpbTimeoutTst_BackupData
);

static Sl_TstRsltType SpbTst_lTimeoutExecute(void);

static Sl_TstRsltType SpbTst_lTimeoutRestore
(
  const SpbTimeoutTst_BackupDataType* SpbTimeoutTst_BackupData
);

static boolean SpbTst_ProtectionTrapHandler(const uint32 TrapId);

/*******************************************************************************
**                    Local inline function definitions                        *
*******************************************************************************/

/*******************************************************************************
**                    Configuration error checking                             *
*******************************************************************************/

/*******************************************************************************
**                         Function definitions                                *
*******************************************************************************/



/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : Sl_TstRsltType SpbTst_TimeoutTst                                  **
**          (                                                                 **
**             const  Sl_ParamSetIndex ParamSetIndex,                         **
**             const  uint8 TstSeed,                                          **
**             uint32* const TstSignature                                     **
**          )                                                                 **
**                                                                            **
** Description : This test checks the timeout of SPB bus.                     **
**               To verify this, the following actions are being executed:    **
**               • Choose the peripheral as MTU.                              **
**                 Enable the module by setting clock.                        **
**               • Set the TOUT as 0x01 in SBCU_CON register.                 **
**               • Read the MTU DSPR0 ECCD data.                               **
**               • Verify the content of SBCU_ECON register and Alarm 3[31]   **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) : ParamSetIndex - Identifies the parameter set to be used  **
**                                   for test execution                       **
**                   Note: This parameter is ignored because no configuration **
**                   is required for this test. It is only defined for        **
**                   reasons of compatibility with APIs of other MTL tests.   **
**                                                                            **
**                   TstSeed - Seed to be used for generating the signature   **
**                                                                            **
** Parameters (out): TstSignature - Test signature generated by the test      **
**                                                                            **
** Return value : SPBTST_TIMEOUT_SUCCESS     - Test succeeded                 **
**                                                                            **
**                SPBTST_TIMEOUT_NOTEXECUTED - The test has not been executed **
**                or at least was interrupted before a valid result could be  **
**                generated                                                   **
**                                                                            **
**                SPBTST_TIMEOUT_SMU_STATEERR - The test cannot be executed   **
**                because the SMU is in the wrong state                       **
**                                                                            **
**                SPBTST_TIMEOUT_SMU_GETALMSTSERR - Test failed because       **
**                getting the SMU alarm status failed                         **
**                                                                            **
**                SPBTST_TIMEOUT_SMU_CLRALMSTSERR - The test failed because   **
**                clearing the SMU alarm failed.                              **
**                                                                            **
**                SPBTST_TIMEOUT_SMU_ALMSTSERR - Test failed because there is **
**                no alarm raised within the SMU.                             **
**                                                                            **
**                SPBTST_TIMEOUT_SMU_SETALMACTIONERR - Test failed because    **
**                setting the SMU alarm action failed.                        **
**                                                                            **
**                SPBTST_TIMEOUT_SMU_GETALMACTIONERR - Test failed because    **
**                getting the SMU alarm action failed.                        **
**                                                                            **
**                SPBTST_TIMEOUT_TRAP_FAILURE - Test failed because of        **
**                TRAP action failed.                                         **
**                                                                            **
**                SPBTST_TIMEOUT_BUSERROR_TIMEOUT - Test failed because       **
**                getting the SPB Error timeout                               **
*******************************************************************************/
Sl_TstRsltType SpbTst_TimeoutTst
(
 const Sl_ParamSetType ParamSetIndex,
 const uint8 TstSeed,
 uint32* const TstSignature
)
{
  Sl_TstRsltType Result = (Sl_TstRsltType)SPBTST_TIMEOUT_NOTEXECUTED;
  Sl_TstRsltType TmpRes1 = (Sl_TstRsltType)SPBTST_TIMEOUT_NOTEXECUTED;
  Sl_TstRsltType TmpRes2 = (Sl_TstRsltType)SPBTST_TIMEOUT_NOTEXECUTED;

  SpbTimeoutTst_BackupDataType SpbTimeoutTst_BackupData;

  UNUSED_PARAMETER(ParamSetIndex)
  
  /* Initialize Test Signature:   */
  *TstSignature = (uint32)CRC32(TEST_ID_SPB_TST_TIMEOUT, TstSeed);

  /* Check if SMU is in RUN state   */
  if(SMU_RUN_STATE == Smu_GetSmuState())
  {
    /*Backup SMU alarms and SFR configs that will be modified*/
    TmpRes1 = SpbTst_lTimeoutInit(&SpbTimeoutTst_BackupData);

    if(TmpRes1 == (Sl_TstRsltType)SPBTST_TIMEOUT_SUCCESS)
    {
      /* SPB Timeout Test */
      TmpRes1 = SpbTst_lTimeoutExecute();
    }
    
    TmpRes2 = SpbTst_lTimeoutRestore(&SpbTimeoutTst_BackupData);
    
    if(TmpRes1 != (Sl_TstRsltType)SPBTST_TIMEOUT_SUCCESS)
    {
      Result = TmpRes1;
    }
    else
    {
      Result = TmpRes2;
    }     

  }
  else
  {
      Result = (Sl_TstRsltType)SPBTST_TIMEOUT_SMU_STATEERR;
  }

  /* Calculate final test signature */
  *TstSignature = (uint32)CRC32(*TstSignature,Result);

  return Result;

}

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : Sl_TstResultType SpbTst_lTimeoutInit(                             **
**           SpbTimeoutTst_BackupDataType* const SpbTimeoutTst_BackupData)    **
**                                                                            **
** Description : Does a backup of the current SMU alarm actions and the SFR-  **
**               registers that will be overwritten by this test.             **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): SpbTimeoutTst_BackupData - Holds a backup of the         **
**                   current SMU alarm action configuration of the SMU alarms **
**                   and the SFR configuration that will be changed by this   **
**                   test                                                     **
**                                                                            **
** Return value : SPBTST_TIMEOUT_SUCCESS     - Test succeeded                 **
**                                                                            **
**                SPBTST_TIMEOUT_NOTEXECUTED - The test has not been executed **
**                or at least was interrupted before a valid result could be  **
**                generated                                                   **
**                                                                            **
**                SPBTST_TIMEOUT_SMU_GETALMSTSERR - Test failed because       **
**                getting the SMU alarm status failed                         **
**                                                                            **
**                SPBTST_TIMEOUT_TRAP_FAILURE - Test failed because of        **
**                TRAP action failed.                                         **
**                                                                            **
**                SPBTST_TIMEOUT_SMU_ALMSTSERR - Test failed because there is **
**                already an  alarm present within the SMU.                   **
**                                                                            **
**                SPBTST_TIMEOUT_SMU_SETALMACTIONERR - Test failed because    **
**                setting the SMU alarm action failed.                        **
**                                                                            **
**                SPBTST_TIMEOUT_SMU_GETALMACTIONERR - Test failed because    **
**                getting the SMU alarm action failed.                        **
*******************************************************************************/
static Sl_TstRsltType SpbTst_lTimeoutInit
(
  SpbTimeoutTst_BackupDataType* const SpbTimeoutTst_BackupData
)
{

  Sl_TstRsltType Result = SPBTST_TIMEOUT_NOTEXECUTED;
  uint32 AlmStatus = 0U;
  Smu_FSPActionType FspActionDummy = 0U;

  SpbTimeoutTst_ExpectedTrap = SPBTST_NO_TRAP;

  /* Backed-up MTU_CLC value:                    */
  SpbTimeoutTst_BackupData->MtuClcBU = (uint32)MTU_CLC.U;  

  /* Backed-up SBCU_ECON value:                  */
  SpbTimeoutTst_BackupData->SbcuEconBU = (uint32)SBCU_ECON.U; 

  /* Backed-up SBCU_EADD value:                  */
  SpbTimeoutTst_BackupData->SbcuEaddBU = (uint32)SBCU_EADD.U; 

  /* Backed-up SBCU_EDAT value:                  */
  SpbTimeoutTst_BackupData->SbcuEdatBU = (uint32)SBCU_EDAT.U; 

  /* Backed-up PSW value:                        */
  SpbTimeoutTst_BackupData->PswBU= (uint32)MFCR(CPU_PSW); 

  /* Get the SMU alarm action for Group 3 alarm 31 */
  if(E_OK != (Smu_GetAlarmAction(SPBTST_BUSERR_GRP, SMU_ALARM_31,
           &SpbTimeoutTst_BackupData->AlmActionBUSpbBusError, &FspActionDummy)))
  {
    Result = SPBTST_TIMEOUT_SMU_GETALMACTIONERR;
    /* Set to Invalid Alarm Action */
    SpbTimeoutTst_BackupData->AlmActionBUSpbBusError = SMU_INVALID_ALARM_ACTION;
  }

  /* Get SMU Alarm Status and check operation was done properly */
  else if(E_OK != (Smu_GetAlarmStatus(SPBTST_BUSERR_GRP, &AlmStatus)))
  {
    Result = SPBTST_TIMEOUT_SMU_GETALMSTSERR;
  }

  /* Check if the SMU Alarm is present or not */
  else if(0U != (AlmStatus & SPBTST_SPB_BUS_ERR_STS)) 
  {
    Result = SPBTST_TIMEOUT_SMU_ALMSTSERR;
  }

  else
  {
    /* Set the SPB BUS ERROR alarm action to none and 
       check if setting was fine */
    if(E_OK != Smu_SetAlarmAction(SPBTST_BUSERR_GRP, SMU_ALARM_31,
                                  SMU_ALARM_ACTION_NONE))
    {
      Result = SPBTST_TIMEOUT_SMU_SETALMACTIONERR;
    }
    else
    {
      Result = TRAP_RegisterTrapHandler(SPBTST_TRAP_CLASS, 
                                        &SpbTst_ProtectionTrapHandler);
      if(TRAP_E_SUCCESS == Result)
      {
        SpbTimeoutTst_DseTrapCount = 0x0U;
        Result = SPBTST_TIMEOUT_SUCCESS;
      }
      else
      {
        Result = SPBTST_TIMEOUT_TRAP_FAILURE;       
      }
    }
  }

  return Result;
  
}

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : SpbTst_lTimeoutExecute ( void)                                    **
**                                                                            **
** Description : Test the SPB Timeout feature                                 **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in):  None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value : SPBTST_TIMEOUT_SUCCESS     - Test succeeded                 **
**                                                                            **
**                SPBTST_TIMEOUT_NOTEXECUTED - The test has not been executed **
**                or at least was interrupted before a valid result could be  **
**                generated                                                   **
**                                                                            **
**                SPBTST_TIMEOUT_SMU_CLRALMSTSERR - The test failed because   **
**                clearing the SMU alarm failed.                              **
**                                                                            **
**                SPBTST_TIMEOUT_SMU_GETALMSTSERR - Test failed because       **
**                getting the SMU alarm status failed.                        **
**                                                                            **
**                SPBTST_TIMEOUT_BUSERROR_TIMEOUT - Test failed because       **
**                getting the SPB Error timeout                               **
**                                                                            **
**                SPBTST_TIMEOUT_TRAP_FAILURE - Test failed because of        **
**                TRAP action failed.                                         **
**                                                                            **
**                SPBTST_TIMEOUT_SMU_ALMSTSERR - Test failed because there is **
**                no alarm raised within the SMU.                             **
*******************************************************************************/

static Sl_TstRsltType SpbTst_lTimeoutExecute()
{
  Sl_TstRsltType Result = SPBTST_TIMEOUT_NOTEXECUTED;
  uint32 SmuAlrmTimeout = SPBTST_SMU_ALM_TIMEOUT;
  uint32 Timeout = SPBTST_TIMEOUT_MTU_ENABLE_TIMEOUT;
  volatile uint32 dummy;
  uint32 AlmStatus = 0U;
  uint8 CoreId;
  unsigned_int SpbTst_SbcuConBU;
  uint32 Temp;
  volatile uint32 Delay = 0U;
  uint32 ExpectSbcuEadd = 0U;
  uint32 ExpectSbcuEdat = 0U;

  /* Expected SBCU_ECON register values */
  const uint32 SpbTimeoutTst_kSbcuEconVal[] =
  {
    SPBTST_TIMEOUT_CPU0_SBCU_ECON_VAL,
    SPBTST_TIMEOUT_CPU1_SBCU_ECON_VAL,
    SPBTST_TIMEOUT_CPU2_SBCU_ECON_VAL
  };

  /* Read the core Id  */
  CoreId = Mcal_GetCoreId(); 

  /* Switch processor status to safe task */
  Temp = (uint32)MFCR(CPU_PSW);
  Temp |= SPBTST_PSW_SAFETY_BIT;
  MTCR(CPU_PSW, Temp);
 
  /* Check if MTU module is enabled. If not enable it.  */
  if (MTU_CLC.B.DISS != 0U)
  {
    Mcal_ResetENDINIT();
    /* MTU clock control register.        */
    MTU_CLC.B.DISR   = 0x0U; 
    Mcal_SetENDINIT();
    do
    {
      Timeout = Timeout - 1U;
      /* wait until module is enabled */
    }while ((MTU_CLC.B.DISS == 1U) && (0U < Timeout));
  }
   
 if(MTU_CLC.B.DISS == 0U)
 {
  /* Stored SBCU_CON value:   */  
  SpbTst_SbcuConBU = SBCU_CON.U;
  
  /* Clear DSE TrapCounter  */
  SpbTimeoutTst_DseTrapCount = 0U;

  /* Set the SBCU_ECON as 0x0 (reset value) */
  SBCU_ECON.U = 0x0U;

  /* Set expected trap: */
  SpbTimeoutTst_ExpectedTrap = SPBTST_TIMEOUT_TRAP;
  switch (CoreId)
  {
    /* Read the DSPR0 ECCD Register data */
    case SPBTST_CORE0:
    {
      /*backup expected ECON and EDAT values*/
      ExpectSbcuEadd = (uint32)(&MC14_ECCD);
      ExpectSbcuEdat = MC14_ECCD.U;
      
      /* Set the TOUT as 0x04 in SBCU_CON register */
      SBCU_CON.U = ((SBCU_CON.U & SPBTST_SBCU_CON_MASK_TOUT_ZERO) | 
                                           (SPBTST_TOUT_VALUE));
      dummy = MC14_ECCD.U;
    }    
    break;
    #if (MCAL_NO_OF_CORES > 1U)
    /* Read the DSPR1 ECCD Register data */
    case SPBTST_CORE1:
    {
      /*backup expected ECON and EDAT values*/
      ExpectSbcuEadd = (uint32)(&MC6_ECCD);
      ExpectSbcuEdat = MC6_ECCD.U;
      
      /* Set the TOUT as 0x04 in SBCU_CON register */
      SBCU_CON.U = ((SBCU_CON.U & SPBTST_SBCU_CON_MASK_TOUT_ZERO) | 
                                           (SPBTST_TOUT_VALUE));
      dummy = MC6_ECCD.U;
    }    
    break;
    #if (MCAL_NO_OF_CORES == 3U)
    /* Read the DSPR2 ECCD Register data */
    case SPBTST_CORE2:
    {
      /*backup expected ECON and EDAT values*/
      ExpectSbcuEadd = (uint32)(&MC0_ECCD);
      ExpectSbcuEdat = MC0_ECCD.U;
      
      /* Set the TOUT as 0x04 in SBCU_CON register */
      SBCU_CON.U = ((SBCU_CON.U & SPBTST_SBCU_CON_MASK_TOUT_ZERO) | 
                                           (SPBTST_TOUT_VALUE));
      dummy = MC0_ECCD.U;
    }    
    break;
    #endif  /*#if (MCAL_NO_OF_CORES == 3U)*/
    #endif  /*#if (MCAL_NO_OF_CORES > 1U)*/
    default:
    {
      /* Do nothing*/
    }
    break;
  }

  /*Introducing delay of 25 cycles*/
  while (Delay < SPBTST_MINIMUM_DELAY) 
  {
    Delay++;
  } 
  
  /* Check if SPB time-out has occurred or not */
  if(ExpectSbcuEadd == SBCU_EADD.U)
  {
    if(ExpectSbcuEdat == SBCU_EDAT.U)
    {
      if(SpbTimeoutTst_kSbcuEconVal[CoreId] != SBCU_ECON.U)
      {
        Result = SPBTST_TIMEOUT_BUSERROR_TIMEOUT;
      }
    }
    else
    {
      Result = SPBTST_TIMEOUT_BUSERROR_TIMEOUT;
    }
  }
  else
  {
    Result = SPBTST_TIMEOUT_BUSERROR_TIMEOUT;
  }
	
  /* Restored SBCU_CON value:   */  
  SBCU_CON.U = (SPBTST_SBCU_CON_MASK & SpbTst_SbcuConBU);    

  /* Clear the Bus error count */
  dummy = (uint32)SBCU_ECON.U;

  if(Result == SPBTST_TIMEOUT_NOTEXECUTED)
  {  
    /* Check that DSE trap has occurred */
    if((SpbTimeoutTst_DseTrapCount == 1U))
    {
      /* Clear DSE Trap request */
      MTCR(CPU_DSTR, 0x0U);
      
      /* Clear DEADD Trap request */
      MTCR(CPU_DEADD, 0x0U);
      
      /* Clear DSE TrapCounter */
      SpbTimeoutTst_DseTrapCount = 0U;
      
      Result = SPBTST_TIMEOUT_SUCCESS;
    }
    else
    {
      Result = SPBTST_TIMEOUT_TRAP_FAILURE;
    }
  }  

  if(Result == SPBTST_TIMEOUT_SUCCESS)
  {  
    /* Wait till the Alarm is set */
    while((SmuAlrmTimeout > 0U) && (0U ==(AlmStatus & SPBTST_SPB_BUS_ERR_STS)))
    {   
      if (E_OK != Smu_GetAlarmStatus(SPBTST_BUSERR_GRP, &AlmStatus))
      {
        AlmStatus = 0U;
        Result = SPBTST_TIMEOUT_SMU_GETALMSTSERR;
        break;
      }
      SmuAlrmTimeout--;
    }

    if(Result == SPBTST_TIMEOUT_SUCCESS)
    {
      /* Check if Alarm is set */
      if (0U != (AlmStatus & SPBTST_SPB_BUS_ERR_STS))
      {
        /* If Alarm 31 was set, then clear the alarm 31 */
        if(E_OK == Smu_ClearAlarmStatus(SPBTST_BUSERR_GRP, SMU_ALARM_31))
        {
          Result = SPBTST_TIMEOUT_SUCCESS;
        }
        else
        {
          Result = SPBTST_TIMEOUT_SMU_CLRALMSTSERR;
        }
      } 
      else
      {
        Result = SPBTST_TIMEOUT_SMU_ALMSTSERR;
      } /* end of else */
    } /* end of (Result == SPBTST_TIMEOUT_SUCCESS) */
  }

  /* Required to avoid compiler warning   */
  UNUSED_PARAMETER(dummy)     
}
  return Result;
}

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : Sl_TstResultType SpbTst_lTimeoutRestore(                          **
**           const SpbTimeoutTst_BackupDataType* SpbTimeoutTst_BackupData)    **
**                                                                            **
** Description : Restores the SMU alarm actions and the SFR register          **
**               configuration  that have been changed during this test       **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in):  SpbTimeoutTst_BackupData - Holds a backup of the         **
**                   SMU alarm action configuration of the SMU alarms         **
**                   and the SFR configuration that got overwritten by this   **
**                   test                                                     **
**                                                                            **
** Return value : SPBTST_TIMEOUT_SUCCESS - Test succeeded                     **
**                                                                            **
**                SPBTST_TIMEOUT_NOTEXECUTED - The test has not been executed **
**                or at least was interrupted before a valid result could be  **
**                generated                                                   **
**                                                                            **
**                SPBTST_TIMEOUT_SMU_SETALMACTIONERR - Test failed because    **
**                setting the SMU alarm action failed.                        **
**                                                                            **
**                SPBTST_TIMEOUT_TRAP_FAILURE - Test failed because of        **
**                TRAP action failed.                                         **
*******************************************************************************/

static Sl_TstRsltType SpbTst_lTimeoutRestore
(
  const SpbTimeoutTst_BackupDataType* SpbTimeoutTst_BackupData
)
{
  Sl_TstRsltType Result = SPBTST_TIMEOUT_NOTEXECUTED;
  Std_ReturnType   ResSmuAlmAct;
  /* Restore previously backed-up PSW value:    */
  Mcal_ResetENDINIT();
  MTCR(CPU_PSW, SpbTimeoutTst_BackupData->PswBU);
  Mcal_SetENDINIT();
  
  /* Restored SBCU_ECON value:  */
  SBCU_ECON.U = SpbTimeoutTst_BackupData->SbcuEconBU; 
  
  /* Restored SBCU_EADD value:  */
  SBCU_EADD.U = SpbTimeoutTst_BackupData->SbcuEaddBU;
  
  /* Restored SBCU_EDAT value: */
  SBCU_EDAT.U = SpbTimeoutTst_BackupData->SbcuEdatBU;
  /* Clear the SRR bit of SRC_BCUSPBSBSRC register which is set because of MC14_ECCD register (Due to very less timeout value) */
  SRC_BCUSPBSBSRC.U = ((SRC_BCUSPBSBSRC.U & SPBTST_BCUSPBSBSRC_MASK) | (SPBTST_BCUSPBSBSRC_CLEAR_BITS));
  /* Restore MTU_CLC value:      */
  Mcal_ResetENDINIT();
  MTU_CLC.U = SpbTimeoutTst_BackupData->MtuClcBU;  
  Mcal_SetENDINIT();
  
  /* Restore the stored SMU alarms                                        */
  ResSmuAlmAct = Smu_SetAlarmAction(SPBTST_BUSERR_GRP, SMU_ALARM_31,
                        SpbTimeoutTst_BackupData->AlmActionBUSpbBusError);
  /* Unregister the TrapHandler */                      
  if(TRAP_UnregisterTrapHandler(SPBTST_TRAP_CLASS) != TRAP_E_SUCCESS)
  {
    Result = SPBTST_TIMEOUT_TRAP_FAILURE;
  }
  else
  {
    /* If restore of SMU alarms failed , update result with SETALMACTIONERR*/
    if (E_OK != ResSmuAlmAct)
    {
      Result = SPBTST_TIMEOUT_SMU_SETALMACTIONERR;
    }
    else
    {
      Result = SPBTST_TIMEOUT_SUCCESS;
    }  
  }
 
  return Result;  
}
/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : Sl_TstRsltType SpbTst_PeripheralRegAccProtTst                     **
**          (                                                                 **
**             const  Sl_ParamSetIndex ParamSetIndex,                         **
**             const  uint8 TstSeed,                                          **
**             uint32* const TstSignature                                     **
**          )                                                                 **
**                                                                            **
** Description : This test checks that the register protection scheme does    **
**               work as expected. To verify this, the following actions are  **
**               being executed:                                              **
**               • Use different masters (Current CPU’s DMI safe and non-safe **
**                 master) and alter a protected register. Check that the     **
**                 register contents actually got changed.                    **
**               • Deny all masters, except CPU.DMI, to access                **
**                 the protected registers                                    **
**               • Try to alter protected registers with different masters    **
**                 (Current CPU’s DMI safe and non-safe master) and check     **
**                 that each time a SMU alarm is generated.                   **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) : ParamSetIndex - Identifies the parameter set to be used  **
**                                   for test execution                       **
**                                                                            **
**                   TstSeed - Seed to be used for generating the signature   **
**                                                                            **
** Parameters (out): TstSignature - Test signature generated by the test      **
**                                                                            **
** Return value : SPBTST_RAP_SUCCESS     - Test succeeded                     **
**                                                                            **
**                SPBTST_RAP_NOTEXECUTED - The test has not been executed or  **
**                at least was interrupted before a valid result could be     **
**                generated                                                   **
**                                                                            **
**                SPBTST_RAP_INVPARAMERR - Test failed because an invalid.    **
**                                                                            **
**                SPBTST_RAP_SMU_STATEERR - The test cannot be executed       **
**                because the SMU is in the wrong state                       **
**                                                                            **
**                SPBTST_RAP_SMU_GETALMSTSERR - Test failed because getting   **
**                the SMU alarm status failed                                 **
**                                                                            **
**                SPBTST_RAP_SMU_CLRALMSTSERR - The test failed because       **
**                clearing the SMU alarm failed.                              **
**                                                                            **
**                SPBTST_RAP_SMU_ALMSTSERR - Test failed because there is     **
**                already a watchdog alarm present within the SMU.            **
**                                                                            **
**                SPBTST_RAP_SMU_SETALMACTIONERR - Test failed because        **
**                setting the SMU alarm action failed.                        **
**                                                                            **
**                SPBTST_RAP_SMU_GETALMACTIONERR - Test failed because        **
**                getting the SMU alarm action failed.                        **
**                                                                            **
**                SPBTST_RAP_DENY_NOSMUALRM - Test failed because no SMU      **
**                alarm was generated also a not allowed master tried to      **
**                write to a protected register.                              **
**                                                                            **
**                SPBTST_RAP_STUCKATFAULT - Test failed because there seems   **
**                to be a stuck-at fault within the CPU’s ACCENA register     **
**                                                                            **
**                SPBTST_RAP_TRAP_FAILURE - Test failed because of            **
**                TRAP action failed.                                         **
*******************************************************************************/
Sl_TstRsltType SpbTst_PeripheralRegAccProtTst
(
 const Sl_ParamSetType ParamSetIndex,
 const uint8 TstSeed,
 uint32* const TstSignature
)
{
  volatile Sl_TstRsltType  Result = (Sl_TstRsltType)SPBTST_RAP_NOTEXECUTED;
  Sl_TstRsltType  TmpRes1 = (Sl_TstRsltType)SPBTST_RAP_NOTEXECUTED;
  Sl_TstRsltType  TmpRes2 = (Sl_TstRsltType)SPBTST_RAP_NOTEXECUTED;
  volatile uint8 PeriCount;
  

  SpbRegAccProtTst_BackupDataType SpbRegAccProtTst_BackupData;

  /* Initialize Test Signature:   */
  *TstSignature = (uint32)CRC32(TEST_ID_SPB_TST_RAP, TstSeed);
  
  /* Check for valid input parameters                                         */
  if (ParamSetIndex > (uint32)(SPB_TST_CFG_PARAM_COUNT - 1U))
  {
    Result = SPBTST_RAP_INVPARAMERR;
  }
  else if (SMU_RUN_STATE != Smu_GetSmuState())
  {
    Result = SPBTST_RAP_SMU_STATEERR;
  }
  else
  {
    for (PeriCount= 0U; PeriCount < SpbTst_ConfigRoot[ParamSetIndex].SpbCount; PeriCount++)
    {
        /*Backup SMU alarms and SFR configurations that will be modified*/
        TmpRes1 = 
           SpbTst_lInit(&SpbRegAccProtTst_BackupData, ParamSetIndex, PeriCount);
        
        if(TmpRes1 == (Sl_TstRsltType)SPBTST_RAP_SUCCESS)
        {
          /* Deny access to protected registers except CPUx.DMI safe*/
          TmpRes1 = SpbTst_lDenyAccTst(ParamSetIndex, TstSignature, PeriCount, SPBTST_RAP_SAFE);
          
          if(TmpRes1 == (Sl_TstRsltType)SPBTST_RAP_SUCCESS)
          {
            /*Deny access to protected registers except CPUx.DMI non-safe*/
            TmpRes1 = SpbTst_lDenyAccTst(ParamSetIndex, TstSignature, PeriCount, SPBTST_RAP_NON_SAFE);              
          }
        }
 
        /* Restore stored SMU alarms and SFR configurations */
        TmpRes2 = SpbTst_lRestore(&SpbRegAccProtTst_BackupData,ParamSetIndex,PeriCount);
        
        if(TmpRes1 != (Sl_TstRsltType)SPBTST_RAP_SUCCESS)
        {
          Result = TmpRes1;
        }
        else
        {
          Result = TmpRes2;
        }

        if(Result != (Sl_TstRsltType)SPBTST_RAP_SUCCESS)
        { 
          break;
        }
    }
  }
  
  /* Calculate final test signature */
  *TstSignature = (uint32)CRC32(*TstSignature,Result);
 
  return Result;
}

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : boolean SpbTst_ProtectionTrapHandler(const  uint32 TrapId)        **
**                                                                            **
** Description : Handles Class 4 traps which are generated during illegal     **
**               write to protected Peripheral registers                      **
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
** Return value : TRUE, if trap was expected and handled, FALSE otherwise     **
**                                                                            **
*******************************************************************************/
static boolean SpbTst_ProtectionTrapHandler(const uint32 TrapId)
{
  boolean ExpectedTrap = (boolean)FALSE;
  uint32 Tmp_SpbRegAccProtTst_ExpctdTrap = SpbRegAccProtTst_ExpectedTrap;
  uint32 Tmp_SpbTimeoutTst_ExpctdTrap = SpbTimeoutTst_ExpectedTrap;
	
  if ((SPBTST_REGISTER_ACCESS_TRAP == TrapId) &&
      (Tmp_SpbRegAccProtTst_ExpctdTrap == SPBTST_REGISTER_ACCESS_TRAP))
  {
    SpbRegAccProtTst_DaeTrapCount++;

    ExpectedTrap = (boolean)TRUE;
    SpbRegAccProtTst_ExpectedTrap = SPBTST_NO_TRAP;

    /* Clear DAE Trap request                                             */
    MTCR(CPU_DATR, 0x0U);
  }
  else if ((SPBTST_TIMEOUT_TRAP == TrapId) &&
           (Tmp_SpbTimeoutTst_ExpctdTrap == SPBTST_TIMEOUT_TRAP))
  {
    SpbTimeoutTst_DseTrapCount++;

    ExpectedTrap = (boolean)TRUE;
    SpbTimeoutTst_ExpectedTrap = SPBTST_NO_TRAP;

    /* Clear DSE Trap request                                             */
    MTCR(CPU_DSTR, 0x0U);
  }
  else
  {
    SpbRegAccProtTst_DaeTrapCount = 0U;
    SpbTimeoutTst_DseTrapCount = 0U;
  }

  return ExpectedTrap;
}

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : Sl_TstResultType SpbTst_lInit(                                    **
**           SpbRegAccProtTst_BackupDataType* const SpbRegAccProt_BackupData, **
**           const Sl_ParamSetType ParamSetIndex,                             **
**           uint8 PeriCount)                                                 **
**                                                                            **
** Description : Does a backup of the current SMU alarm actions and the SFR-  **
**               registers that will be overwritten by this test. It also     **
**               sets the SMU actions for the CPUx Mpu alarm to “no action”.  **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) : ParamSetIndex - Identifies the parameter set to be used  **
**                                   for test execution                       **
**                                                                            **
**                   PeriCount - Peripheral number                            **
**                                                                            **
** Parameters (out): SpbRecAccProt_BackupData - Holds a backup of the         **
**                   current SMU alarm action configuration of the SMU alarms **
**                   and the SFR configuration that will be changed by this   **
**                   test                                                     **
**                                                                            **
** Return value : SPBTST_RAP_SUCCESS     - Test succeeded                     **
**                                                                            **
**                SPBTST_RAP_NOTEXECUTED - The test has not been executed or  **
**                at least was interrupted before a valid result could be     **
**                generated                                                   **
**                                                                            **
**                SPBTST_RAP_SMU_GETALMSTSERR - Test failed because getting   **
**                the SMU alarm status failed                                 **
**                                                                            **
**                SPBTST_RAP_SMU_GETALMACTIONERR - Test failed because        **
**                setting the SMU alarm action failed.                        **
**                                                                            **
**                SPBTST_RAP_SMU_ALMSTSERR - Test failed because there is     **
**                already an alarm present within the SMU.                    **
**                                                                            **
**                SPBTST_RAP_TRAP_FAILURE - Test failed because of            **
**                TRAP action failed.                                         **
**                                                                            **
**                SPBTST_RAP_SMU_SETALMACTIONERR - Test failed because        **
**                setting the SMU alarm action failed.                        **
*******************************************************************************/
static Sl_TstRsltType SpbTst_lInit
(
  SpbRegAccProtTst_BackupDataType* const SpbRegAccProt_BackupData,
  const Sl_ParamSetType ParamSetIndex,
  uint8 PeriCount
)
{
  Sl_TstRsltType      Result  = SPBTST_RAP_NOTEXECUTED;
  uint32              AlmStatus = 0U;
  Smu_FSPActionType   FspActionDummy = 0U;
  volatile uint32     SmuAlmChk;
  volatile uint32 Dummy = 0U;
  
  SpbRegAccProtTst_ExpectedTrap = SPBTST_NO_TRAP;

  SmuAlmChk = (SpbTst_ConfigRoot[ParamSetIndex].SmuAlarm[PeriCount]);
  
  /* Backed-up <Peripheral>_CLC value:               */
  if(SpbTst_ConfigRoot[ParamSetIndex].SpbPeripheralCfgPtr[PeriCount][0] != 
     NULL_PTR)
  {
    if (*(SpbTst_ConfigRoot[ParamSetIndex].SpbPeripheralCfgPtr[PeriCount][3]) != 
     0U)
    {
      SpbRegAccProt_BackupData->PeripheralClcBU = 
            *(SpbTst_ConfigRoot[ParamSetIndex].SpbPeripheralCfgPtr[PeriCount][0]);
      Mcal_ResetENDINIT();
      *(SpbTst_ConfigRoot[ParamSetIndex].SpbPeripheralCfgPtr[PeriCount][0]) =
                                                             SPBTST_MODULE_ENABLE_RMC;    
      Mcal_SetENDINIT();
    }
    else
    {
      SpbRegAccProt_BackupData->PeripheralClcBU = 
            *(SpbTst_ConfigRoot[ParamSetIndex].SpbPeripheralCfgPtr[PeriCount][0]);
      Mcal_ResetENDINIT();
      *(SpbTst_ConfigRoot[ParamSetIndex].SpbPeripheralCfgPtr[PeriCount][0]) =
                                                             SPBTST_MODULE_ENABLE;    
      Mcal_SetENDINIT();
    }     
    /*Read the register to ensure write action to CLC register is completed*/
    Dummy =  *(SpbTst_ConfigRoot[ParamSetIndex].SpbPeripheralCfgPtr[PeriCount][0]);
  }
  
  /* Backed-up <Peripheral>_ACCEN0 value:            */
  SpbRegAccProt_BackupData->PeripheralAccen0BU = 
          *(SpbTst_ConfigRoot[ParamSetIndex].SpbPeripheralCfgPtr[PeriCount][1]);


  /* Backed-up <Peripheral>_Kernal value:            */
  SpbRegAccProt_BackupData->PeripheralKernelBU =
          *(SpbTst_ConfigRoot[ParamSetIndex].SpbPeripheralCfgPtr[PeriCount][2]);


  /* Backed-up PSW value:                            */
  SpbRegAccProt_BackupData->PswBU= (uint32)MFCR(CPU_PSW);
  
  /* Get the SMU alarm action for Group 3 alarm 30   */
  if(E_OK != (Smu_GetAlarmAction(SPBTST_BUSERR_GRP, SMU_ALARM_30,
           &SpbRegAccProt_BackupData->AlmActionBUSriBusError, &FspActionDummy)))
  {
    Result = SPBTST_RAP_SMU_GETALMACTIONERR;
    /* Set to Invalid Alarm Action */
    SpbRegAccProt_BackupData->AlmActionBUSriBusError = SMU_INVALID_ALARM_ACTION;
  }
  
  /* Get the SMU alarm action for Group 3 alarm 31   */
  if(E_OK != (Smu_GetAlarmAction(SPBTST_BUSERR_GRP, SMU_ALARM_31,
           &SpbRegAccProt_BackupData->AlmActionBUSpbBusError, &FspActionDummy)))
  {
    Result = SPBTST_RAP_SMU_GETALMACTIONERR;
    /* Set to Invalid Alarm Action */
    SpbRegAccProt_BackupData->AlmActionBUSpbBusError = SMU_INVALID_ALARM_ACTION;
  }

  /* Get the SMU alarm action for Group 3 alarm 22  */
  if(E_OK != (Smu_GetAlarmAction(SPBTST_BUSERR_GRP, SMU_ALARM_22,
    &SpbRegAccProt_BackupData->AlmActionBUSpbAccProtEnbError, &FspActionDummy)))
  {
    Result = SPBTST_RAP_SMU_GETALMACTIONERR;
    /* Set to Invalid Alarm Action */
    SpbRegAccProt_BackupData->AlmActionBUSpbAccProtEnbError = 
                                                       SMU_INVALID_ALARM_ACTION;
  }

  if(Result == SPBTST_RAP_NOTEXECUTED)
  {
    /* Get SMU Alarm Status and check operation was done properly */
    if(E_OK != (Smu_GetAlarmStatus(SPBTST_BUSERR_GRP, &AlmStatus)))
    {
      Result = SPBTST_RAP_SMU_GETALMSTSERR;
    }
    /* Check if the SMU Alarm is present or not */
    else if(0U != (AlmStatus & SmuAlmChk))
    {
      Result = SPBTST_RAP_SMU_ALMSTSERR;
    }
    else
    {
      /*Set the CPU MPU alarm action to none and check if setting was fine */
      if(E_OK != Smu_SetAlarmAction(SPBTST_BUSERR_GRP, SMU_ALARM_30,
                                    SMU_ALARM_ACTION_NONE))
      {
        Result = SPBTST_RAP_SMU_SETALMACTIONERR;
      }
      if(E_OK != Smu_SetAlarmAction(SPBTST_BUSERR_GRP, SMU_ALARM_31,
                                    SMU_ALARM_ACTION_NONE))
      {
        Result = SPBTST_RAP_SMU_SETALMACTIONERR;
      }
      if(E_OK != Smu_SetAlarmAction(SPBTST_BUSERR_GRP, SMU_ALARM_22, 
                                    SMU_ALARM_ACTION_NONE))
      {
        Result = SPBTST_RAP_SMU_SETALMACTIONERR;
      }  
      if(Result == SPBTST_RAP_NOTEXECUTED)
      {
        Result = TRAP_RegisterTrapHandler(SPBTST_TRAP_CLASS, 
                                          &SpbTst_ProtectionTrapHandler);
        if(TRAP_E_SUCCESS == Result)
        {
          SpbRegAccProtTst_DaeTrapCount = 0x0U;
          Result = SPBTST_RAP_SUCCESS;
        }
        else
        {
          Result = SPBTST_RAP_TRAP_FAILURE;       
        }        
      }
    }
  }
  UNUSED_PARAMETER(Dummy)
  return Result;
  
}

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : Sl_TstResultType SpbTst_lRestore(                                 **
**           const SpbRegAccProtTst_BackupDataType* SpbRegAccProt_BackupData, **
**           const Sl_ParamSetType ParamSetIndex,                             **
**           uint8 PeriCount)                                                 **
** Description : Restores the SMU alarm actions and the SFR register          **
**               configuration  that have been changed during this test       **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in):  SpbRecAccProt_BackupData - Holds a backup of the         **
**                   SMU alarm action configuration of the SMU alarms         **
**                   and the SFR configuration that got overwritten by this   **
**                   test                                                     **
**                                                                            **
** Parameters (in) : ParamSetIndex - Identifies the parameter set to be used  **
**                                   for test execution                       **
**                                                                            **
**                   PeriCount - Peripheral number                            **
**                                                                            **
** Return value : SPBTST_RAP_SUCCESS     - Test succeeded                     **
**                                                                            **
**                SPBTST_RAP_NOTEXECUTED - The test has not been executed or  **
**                at least was interrupted before a valid result could be     **
**                generated                                                   **
**                                                                            **
**                SPBTST_RAP_SMU_SETALMACTIONERR - Test failed because        **
**                setting the SMU alarm action failed.                        **
**                                                                            **
**                SPBTST_RAP_TRAP_FAILURE - Test failed because of            **
**                TRAP action failed.                                         **
*******************************************************************************/
static Sl_TstRsltType SpbTst_lRestore
(
  const SpbRegAccProtTst_BackupDataType*  SpbRegAccProt_BackupData,
  const Sl_ParamSetType ParamSetIndex,
  uint8 PeriCount
)
{
  Sl_TstRsltType   Result = SPBTST_RAP_NOTEXECUTED;
  Std_ReturnType   ResSmuAlmAct1;
  Std_ReturnType   ResSmuAlmAct2;
  Std_ReturnType   ResSmuAlmAct3;
  volatile uint32  IntAccEnb;
  
  /* Reading the Access Enable address from configuration structure */  
  IntAccEnb = (uint32)(SpbTst_ConfigRoot[ParamSetIndex].SpbPeripheralCfgPtr[PeriCount][1]);
  
  /* Restore previously backed-up PSW value:    */
  Mcal_ResetENDINIT();
  MTCR(CPU_PSW, SpbRegAccProt_BackupData->PswBU);
  Mcal_SetENDINIT();
  
  /* Restore previously backed-up <Peripheral>_Kernal value:      */  
  if(SPBTST_MTU_ACCEN0_ADD != IntAccEnb)
  {
    Mcal_ResetENDINIT();
    *(SpbTst_ConfigRoot[ParamSetIndex].SpbPeripheralCfgPtr[PeriCount][2]) = 
                                   SpbRegAccProt_BackupData->PeripheralKernelBU;
    Mcal_SetENDINIT();
  }
  else
  {
    Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);
    *(SpbTst_ConfigRoot[ParamSetIndex].SpbPeripheralCfgPtr[PeriCount][2]) = 
                                   SpbRegAccProt_BackupData->PeripheralKernelBU;
    Mcal_SetSafetyENDINIT_Timed();      
  }

  /* Restore previously backed-up <Peripheral>_ACCEN0 value:    */
  Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);
  *(SpbTst_ConfigRoot[ParamSetIndex].SpbPeripheralCfgPtr[PeriCount][1]) = 
                                   SpbRegAccProt_BackupData->PeripheralAccen0BU;  
  Mcal_SetSafetyENDINIT_Timed();

  /* Clear XBAR_INTSAT(PRSCi6, PRSCID), XBAR_ARBCON6(INTACK bit), XBAR_ARBCOND(INTACK bit) register bits(these register bits are changed as part of test execution when SRI bus occurs) */
  XBAR_ARBCON6.U |= SPBTST_ARBCON6_CLEAR;
  XBAR_ARBCOND.U |= SPBTST_ARBCOND_CLEAR;
  XBAR_INTSAT.U = SPBTST_INTSAT_CLEAR;
  /* Restore previously backed-up <Peripheral>_CLC value:         */
  Mcal_ResetENDINIT();
  if(SpbTst_ConfigRoot[ParamSetIndex].SpbPeripheralCfgPtr[PeriCount][0] != 
                                                                       NULL_PTR)
  {
    *(SpbTst_ConfigRoot[ParamSetIndex].SpbPeripheralCfgPtr[PeriCount][0]) = 
                                      SpbRegAccProt_BackupData->PeripheralClcBU;
  }    
  Mcal_SetENDINIT();

  /* Restore the stored SMU alarms                                        */
  ResSmuAlmAct1 = Smu_SetAlarmAction(SPBTST_BUSERR_GRP, SMU_ALARM_30,
                              SpbRegAccProt_BackupData->AlmActionBUSriBusError);
                              
  ResSmuAlmAct2 = Smu_SetAlarmAction(SPBTST_BUSERR_GRP, SMU_ALARM_31,
                              SpbRegAccProt_BackupData->AlmActionBUSpbBusError);                              

  ResSmuAlmAct3 = Smu_SetAlarmAction(SPBTST_BUSERR_GRP, SMU_ALARM_22,
                       SpbRegAccProt_BackupData->AlmActionBUSpbAccProtEnbError);
  /* Unregister the TrapHandler */
  if (TRAP_UnregisterTrapHandler(SPBTST_TRAP_CLASS) != TRAP_E_SUCCESS)
  {
    Result = SPBTST_RAP_TRAP_FAILURE;      
  }
  else
  {
    /* If restore of SMU alarms failed , update result with SETALMACTIONERR*/
    if( (E_OK != ResSmuAlmAct1) || (E_OK != ResSmuAlmAct2) || (E_OK != ResSmuAlmAct3))
    {
      Result = SPBTST_RAP_SMU_SETALMACTIONERR;
    }
    else
    {
      Result = SPBTST_RAP_SUCCESS;
    }  
  }
  
  return Result;
}

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : Sl_TstRsltType SpbTst_lDenyAccTst                             **
**         (const Sl_ParamSetType ParamSetIndex, uint32* const TstSignature,  **
**               uint8 PeriCount, boolean CpuPsw)                             **
**                                                                            **
** Description : This function does deny the access to the protected          **
**               registers except CPUx.DMI non-safe. After that               **
**               it tries to alter a protected register with CPUx.DMI         **
**               safe master and checks that those write access gets          **
**               actually blocked and that an SMU alarm was raised.           **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) : ParamSetIndex - Identifies the parameter set to be used  **
**                                   for test execution                       **
**                                                                            **
**                   PeriCount - Peripheral number                            **
**                   CpuPsw - CPU state to be set safe/Non Safe               **
**                                                                            **
** Parameters (out): TstSignature - Test signature generated by the test      **
**                                                                            **
** Return value : SPBTST_RAP_SUCCESS     - Test succeeded                     **
**                                                                            **
**                SPBTST_RAP_NOTEXECUTED - The test has not been executed or  **
**                at least was interrupted before a valid result could be     **
**                generated                                                   **
**                                                                            **
**                SPBTST_RAP_STUCKATFAULT - Test failed because there seems   **
**                to be a stuck-at fault within the CPU’s ACCENA register     **
**                                                                            **
**                SPBTST_RAP_SMU_CLRALMSTSERR - The test failed because       **
**                clearing the SMU alarm failed.                              **
**                                                                            **
**                SPBTST_RAP_SMU_GETALMACTIONERR - Test failed because        **
**                getting the SMU alarm action failed.                        **
**                                                                            **
**                SPBTST_RAP_DENY_NOSMUALRM - Test failed because no SMU      **
**                alarm was generated also a not allowed master tried to      **
**                write to a protected register.                              **
**                                                                            **
**                SPBTST_RAP_TRAP_FAILURE - Test failed because of            **
**                TRAP action failed.                                         **
*******************************************************************************/
static Sl_TstRsltType SpbTst_lDenyAccTst
(
  const Sl_ParamSetType ParamSetIndex, 
  uint32* const TstSignature, 
  uint8 PeriCount,
  boolean CpuPsw
)
{
  Sl_TstRsltType Result = SPBTST_RAP_NOTEXECUTED;
  uint8 CoreId;
  volatile uint32 IntAccEnb;
  uint32 AccEnable;
  uint32 Temp;
  volatile uint32 Read_Econ_Reg;
  volatile uint32 Dummy = 0U;
  
  /* Constant Safe DMI Tag Id value for each core */
  const uint32 SpbTst_kSafeDMIMasterEnable[] =
  {
    SPBTST_RAP_CPU0_SAFE_DMI,
    SPBTST_RAP_CPU1_SAFE_DMI,
    SPBTST_RAP_CPU2_SAFE_DMI
  };
  
   /* Constant Non safe DMI Tag Id value for each core */
  const uint32 SpbTst_kNonSafeDMIMasterEnable[] =
  {
    SPBTST_RAP_CPU0_NONSAFE_DMI,
    SPBTST_RAP_CPU1_NONSAFE_DMI,
    SPBTST_RAP_CPU2_NONSAFE_DMI
  };
   
  /* Read the core Id  */
  CoreId = Mcal_GetCoreId();


  if(CpuPsw == SPBTST_RAP_NON_SAFE)
  {
    /* Switch processor status to non-safe task */
    Temp = (uint32)MFCR(CPU_PSW);
    Temp &= (uint32)(~SPBTST_PSW_SAFETY_BIT);
    MTCR(CPU_PSW, Temp);
    AccEnable = SpbTst_kNonSafeDMIMasterEnable[CoreId];
  }
  else
  {
    /* Switch processor status to safe task */
    Temp = (uint32)MFCR(CPU_PSW);
    Temp |= SPBTST_PSW_SAFETY_BIT;
    MTCR(CPU_PSW, Temp); 
    AccEnable = SpbTst_kSafeDMIMasterEnable[CoreId];
  }
  
  /* Block all masters except CPUx DMI.Safe/Non Safe depending on CpuPsw   */
  Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);
  IntAccEnb = (uint32)(SpbTst_ConfigRoot[ParamSetIndex].SpbPeripheralCfgPtr[PeriCount][1]);
  *(SpbTst_ConfigRoot[ParamSetIndex].SpbPeripheralCfgPtr[PeriCount][1]) = AccEnable;  
  Mcal_SetSafetyENDINIT_Timed();  
  
  /* Check that ACCENA actually got written:                  */
  if (*(SpbTst_ConfigRoot[ParamSetIndex].SpbPeripheralCfgPtr[PeriCount][1]) == AccEnable)
  {
    if(CpuPsw != SPBTST_RAP_NON_SAFE)
    {
      /* Switch processor status to non-safe task */
      Temp = (uint32)MFCR(CPU_PSW);
      Temp &= (uint32)(~SPBTST_PSW_SAFETY_BIT);
      MTCR(CPU_PSW, Temp);
    }
    else
    {
      /* Switch processor status to safe task */
      Temp = (uint32)MFCR(CPU_PSW);
      Temp |= SPBTST_PSW_SAFETY_BIT;
      MTCR(CPU_PSW, Temp); 
    }    

    /* Clear DAE TrapCounter  */
    SpbRegAccProtTst_DaeTrapCount = 0U;

    /* Write into a Kernel Address */
    if(SPBTST_MTU_ACCEN0_ADD != IntAccEnb)
    {
      Mcal_ResetENDINIT();
      SpbRegAccProtTst_ExpectedTrap = SPBTST_REGISTER_ACCESS_TRAP;
      *(SpbTst_ConfigRoot[ParamSetIndex].SpbPeripheralCfgPtr[PeriCount][2]) = 0xFFFFFFFFU;
      Mcal_SetENDINIT();
    }
    else
    {
      Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);
      SpbRegAccProtTst_ExpectedTrap = SPBTST_REGISTER_ACCESS_TRAP;
      *(SpbTst_ConfigRoot[ParamSetIndex].SpbPeripheralCfgPtr[PeriCount][2]) = 0xFFFFFFFFU;
      Mcal_SetSafetyENDINIT_Timed();      
    }

    if(CpuPsw == SPBTST_RAP_NON_SAFE)
    {
      /* Switch processor status to non-safe task */
      Temp = (uint32)MFCR(CPU_PSW);
      Temp &= (uint32)(~SPBTST_PSW_SAFETY_BIT);
      MTCR(CPU_PSW, Temp);
    }
    else
    {
      /* Switch processor status to safe task */
      Temp = (uint32)MFCR(CPU_PSW);
      Temp |= SPBTST_PSW_SAFETY_BIT;
      MTCR(CPU_PSW, Temp); 
    }
   
    Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);
    *(SpbTst_ConfigRoot[ParamSetIndex].SpbPeripheralCfgPtr[PeriCount][1]) = 0xFFFFFFFFU;
    Mcal_SetSafetyENDINIT_Timed(); 

    Result = SpbTst_lWaitForSmuAlarm(ParamSetIndex, PeriCount);
    /* Clear the SBSC_ECON.B.ERRCNT value by reading SBCU_ECON.U into any temporary register */
    Read_Econ_Reg = (uint32)SBCU_ECON.U;
    /* Required to avoid compiler warning   */
    UNUSED_PARAMETER(Read_Econ_Reg)
    
    if(Result == SPBTST_RAP_SUCCESS)
    {      
      /* Check that DAE trap has occurred */
      if((SpbRegAccProtTst_DaeTrapCount == 1U))
      {
        /* Clear DAE Trap request */
        MTCR(CPU_DATR, 0x0U);
        
        /* Clear DEADD Trap request */
        MTCR(CPU_DEADD, 0x0U);
        
        /* Clear DAE TrapCounter */
        SpbRegAccProtTst_DaeTrapCount = 0U;
      }
      else
      {
        /* IR: A violation of the access protection will not be executed  
        (e.g. a write to a ´Px´/ACCEN protected register from a disabled  
        master). In this case an access protection error is signaled to   
        the SMU and no other error, interrupt or trap is generated.   */
        
        if(SPBTST_INT_ACCEN00_ADD == IntAccEnb)
        {
          Result = SPBTST_RAP_SUCCESS;
        }
        else if (SPBTST_INT_ACCEN10_ADD == IntAccEnb)
        {
          Result = SPBTST_RAP_SUCCESS;
        }
        else
        {
          Result = SPBTST_RAP_TRAP_FAILURE;
        }
      }
    }    
  }
  else
  {
    Result = SPBTST_RAP_STUCKATFAULT;
  }
  /* Clear the SRR bit of SRC_BCUSPBSBSRC register: These registers are getting set when SPB bus error occurs*/
  SRC_BCUSPBSBSRC.U = ((SRC_BCUSPBSBSRC.U & SPBTST_BCUSPBSBSRC_MASK) | (SPBTST_BCUSPBSBSRC_CLEAR_BITS));
  /* Clear the SRR bit of SRC_XBARSRC register: These registers are getting set when SRI bus error occurs */
  SRC_XBARSRC.U = ((SRC_XBARSRC.U & SPBTST_XBARSRC_MASK) | (SPBTST_XBARSRC_CLEAR_BITS));  
  *TstSignature = (uint32)CRC32(*TstSignature,Result);
  UNUSED_PARAMETER(Dummy)
  return Result;
}

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : SpbTst_lWaitForSmuAlarm(const Sl_ParamSetType ParamSetIndex,      **
**                                        uint8 PeriCount)                    **
**                                                                            **
** Description : This function does wait for the SMU SPB/SRI alarm of the     **
**               current tested CPU that is raised if an access to a protected**
**               register is made from a master that is not allowed to do     **
**               such an access. If the SMU alarm is not being                **
**               generated / reported within a given amount of time the       **
**               function returns a fail.                                     **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) : ParamSetIndex - Identifies the parameter set to be used  **
**                                   for test execution                       **
**                                                                            **
**                   PeriCount - Peripheral number                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value : SPBTST_RAP_SUCCESS     - Test succeeded                     **
**                                                                            **
**                SPBTST_RAP_NOTEXECUTED - The test has not been executed or  **
**                at least was interrupted before a valid result could be     **
**                generated                                                   **
**                                                                            **
**                SPBTST_RAP_SMU_CLRALMSTSERR - The test failed because       **
**                clearing the SMU alarm failed.                              **
**                                                                            **
**                SPBTST_RAP_SMU_GETALMSTSERR - Test failed because getting   **
**                the SMU alarm status failed                                 **
**                                                                            **
**                SPBTST_RAP_DENY_NOSMUALRM - Test failed because no SMU      **
**                alarm was generated also a not allowed master tried to      **
**                write to a protected register.                              **
*******************************************************************************/
static Sl_TstRsltType SpbTst_lWaitForSmuAlarm
(
  const Sl_ParamSetType ParamSetIndex, 
  uint8 PeriCount
)
{
  uint32 AlmStatus = 0U;
  uint32 Timeout = SPBTST_SMU_ALM_TIMEOUT;
  Sl_TstRsltType Result = SPBTST_RAP_NOTEXECUTED;
  Std_ReturnType  TmpClrAlmRes1 = E_OK;
  Std_ReturnType  TmpClrAlmRes2 = E_OK;
  Std_ReturnType  TmpClrAlmRes3 = E_OK;  
  volatile uint32  SmuAlmChk;
  
  SmuAlmChk = (SpbTst_ConfigRoot[ParamSetIndex].SmuAlarm[PeriCount]);
  
  /* Wait till the Alarm is set */
  while((0U == (AlmStatus & SmuAlmChk)) && ((Timeout) > 0U))
  {
    Timeout--;
    if (E_OK != Smu_GetAlarmStatus(SPBTST_BUSERR_GRP, &AlmStatus))
    {
      AlmStatus = 0U;
      Timeout = 0U;
      Result = SPBTST_RAP_SMU_GETALMSTSERR;
    }
  }
  
  /* Check if Alarm is set before */
  if (0U != (AlmStatus & SmuAlmChk))
  {
    if (0U != (AlmStatus & (uint32)SPBTST_SPB_ACC_ENB_ERR_STS))
    {
      /* If Alarm 22 was set, then clear the alarm 22 */
      TmpClrAlmRes1 = Smu_ClearAlarmStatus(SPBTST_BUSERR_GRP, SMU_ALARM_22);
    }
    if(0U != (AlmStatus & (uint32)SPBTST_SPB_BUS_ERR_STS))
    {
      /* If Alarm 31 was set, then clear the alarm 31 */
      TmpClrAlmRes2 = Smu_ClearAlarmStatus(SPBTST_BUSERR_GRP, SMU_ALARM_31);
    }
    if(0U != (AlmStatus & (uint32)SPBTST_SRI_BUS_ERR_STS))
    {
      /* If Alarm 30 was set, then clear the alarm 30 */
      TmpClrAlmRes3 = Smu_ClearAlarmStatus(SPBTST_BUSERR_GRP, SMU_ALARM_30);
    }   
    /* Check of Clear Alarm */
    if( (E_OK != TmpClrAlmRes1) || (E_OK != TmpClrAlmRes2) || (E_OK != TmpClrAlmRes3) )
    {
      Result = SPBTST_RAP_SMU_CLRALMSTSERR;
    }
    else
    {
      Result = SPBTST_RAP_SUCCESS;
    }
  }
  /* No alarm was set*/
  else
  {
    if(Result == SPBTST_RAP_NOTEXECUTED)
    {
      Result = SPBTST_RAP_DENY_NOSMUALRM;
    }
  }
  return Result;
}

#define IFX_SPBTST_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
