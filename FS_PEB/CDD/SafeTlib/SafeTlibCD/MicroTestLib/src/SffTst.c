/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2014)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  $FILENAME   : SffTst.c $                                                 **
**                                                                            **
**  $CC VERSION : \main\11 $                                                 **
**                                                                            **
**  $DATE       : 2018-02-22 $                                               **
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
**                 Safety flip-flop register monitor mechanism.               **
**                                                                            **
**  REFERENCE(S) : Aurix-HE_SafeTlib_DS_SffTst                                **
**                                                                            **
*  MAY BE CHANGED BY USER : no                                                **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "IfxSmu_reg.h"
#include "SffTst.h"
#include "SmuInt.h"
#include "Mcal.h"
#include "IfxScu_reg.h"
#include "ChipId.h"

/*******************************************************************************
**                      Local Macro Definitions                               **
*******************************************************************************/
#define SFF_ZERO                 ((uint8)(0x00U))
#define SFF_ONE                  ((uint8)(0x01U))

/* Register monitor control - Enable/Disable */
/* SMU_RMCTL.TE = 1: Test mode enabled */
#define SFF_RMCTL_TESTMODE_EN    ((uint32)(0x01U))
/* SMU_RMCTL.TE = 0: Test mode enabled */
#define SFF_RMCTL_TESTMODE_DIS   ((uint32)(0x00U))

/* Timeout of the Safety flip-flop self-test */
/*
Result is available after 12 spb clock cycles for MTU/SCU/SMU
       2 local clocks for synchronization of test enable,
       8 clocks for testing phases,
       2 spb clocks for re-synchronisation of flags to spb clock
fSRI = 2 * fSPB = 2 * 12 = 24 fSRI clock cycles
Timeout = Safe factor * Clock cycles = 5 * 24 = 120 = 0x78
fBACKUP = fPLL = fSRI = 2 * fSPB
*/
#define SFF_RM_TIMEOUT           ((uint8)(0x80U))

/* SMU configuration temporary lock and unlock key */
#define SMU_CFG_KEY_UNLOCK       ((uint32)(0xBCU))
#define SMU_CFG_KEY_TEMPLOCK     ((uint32)(0x00U))

/* SMU Alarm Group IndexBit definitions:      */
#define SMU_REG_MON_ED_ALARM_GRP ((uint8)SMU_ALARM_GROUP3)
#define SMU_REG_MON_ED_ALARM     ((uint8)SMU_ALARM_27)
#define SMU_REG_MON_ED_ALARM_STS ((uint32)(0x01U) << SMU_REG_MON_ED_ALARM)

/* SFF register monitor error states */
#define SFF_RM_SMU_ERROR_CONDITION         ((uint8)(0x01U))
#define SFF_RM_SCU_ERROR_CONDITION         ((uint8)(0x02U))
#define SFF_RM_SMU_SCU_ERROR_CONDITION     ((uint8)(0x03U))
#define SFF_RM_MTU_ERROR_CONDITION         ((uint8)(0x04U))
#define SFF_RM_MTU_SMU_ERROR_CONDITION     ((uint8)(0x05U))
#define SFF_RM_MTU_SCU_ERROR_CONDITION     ((uint8)(0x06U))
#define SFF_RM_MTU_SCU_SMU_ERROR_CONDITION ((uint8)(0x07U))

/* Register monitor is implemented in SMU, SCU and MTU which are mapped to
   Bit 0, 1 and 2 respectively
*/
#define SFF_RM_ACTIVEBITS_MTU_SCU_SMU    ((uint32)(0x07U))
#define SFF_RM_ACTIVEBITS_DEFAULT        ((uint32)SFF_RM_ACTIVEBITS_MTU_SCU_SMU)


#if (CHIP_ID == 27U)
/*
CHREV in CHIPID register: Bits[5:0]
Bits [5:4] define major silicon design steps(A,B,C,D...)
*/
#define CHIPID_CHREV_MAJOR_STEP_OFFSET     ((uint8)(0x04U))
#define SFF_RM_ACTIVEBITS_MTU_SCU          ((uint32)(0x06U))

#endif

/*******************************************************************************
**                      Local Type Definitions                                **
*******************************************************************************/

/*******************************************************************************
**                        Exported object definitions                          *
*******************************************************************************/

/*******************************************************************************
**                        Local object definitions                             *
*******************************************************************************/
/*******************************************************************************
**                        Imported function declarations                       *
*******************************************************************************/
#define IFX_SFFTST_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
/*******************************************************************************
**                        Local function prototypes                            *
*******************************************************************************/
static Sl_TstRsltType SffTst_lCheckPrerequisites(void);

static Sl_TstRsltType SffTst_lInit
(
  Smu_AlarmActionType* const BackupData,
  uint32* const TstSignature
);

static Sl_TstRsltType  SffTst_lTstExecute
(
  uint32* const TstSignature
);

static Sl_TstRsltType SffTst_lRestore
(
  const Smu_AlarmActionType* const BackupData,
  uint32* const TstSignature
);

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
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : Sl_TstRsltType SffTst_SffTst                            **
**                    (                                                       **
**                      const Sl_ParamSetType ParamSetIndex,                  **
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
** Parameters (in)  : ParamSetIndex - Identifies the parameter set to be      **
**                      used for test execution.                              **
**                    TstSeed - Seed to be used for generating the signature  **
**                                                                            **
** Parameters (out) : TstSingature - Test signature generated by the test     **
**                                                                            **
** Return value     : SFF_SUCCESS - Test succeeded                            **
**                    SFF_NOTEXECUTED - This error is never intentionally     **
**                      returned; if it is returned anyway, something         **
**                      very serious must be wrong                            **
**                    SFF_RM_TESTENABLEDERR - Test failed due to a RM test    **
**                      mode is already enabled when SFF test is called.      **
**                    SFF_RM_TIMEOUTERR - Test failed due to timeout in the   **
**                      RM test completion                                    **
**                    SFF_RM_ALARMNOTSETERR - Test failed due to alarm being  **
**                      not set after executing RM safety mechanism           **
**                    SFF_RM_ERRORFLAGERR - Test failed due to fault          **
**                      condition in RM safety mechanism                      **
**                    SFF_RM_SMU_ERROR - Safety flip-flop test failed in      **
**                      SMU module                                            **
**                    SFF_RM_SCU_ERROR - Safety flip-flop test failed in      **
**                      SCU module                                            **
**                    SFF_RM_SMU_SCU_ERROR - Safety flip-flop test failed in  **
**                      SMU and SCU module                                    **
**                    SFF_RM_MTU_ERROR - Safety flip-flop test failed in      **
**                      MTU module                                            **
**                    SFF_RM_MTU_SMU_ERROR - Safety flip-flop test failed in  **
**                      MTU and SMU module                                    **
**                    SFF_RM_MTU_SCU_ERROR - Safety flip-flop test failed in  **
**                      MTU and SCU module                                    **
**                    SFF_RM_MTU_SCU_SMU_ERROR - Safety flip-flop test failed **
**                      in MTU,SCU and SMU module                             **
**                    SFF_SMU_STATEERR - Test initialization failed due to    **
**                      an invalid run state of the SMU                       **
**                    SFF_SMU_ALMSTSERR - Test failed due to a SMU alarm      **
**                      which is expected to be set is already set            **
**                    SFF_SMU_GETALMSTSERR - Test failed because              **
**                      Smu_GetAlarmStatus returned an error                  **
**                    SFF_SMU_CLRALMSTSERR - Test restoration failed due to   **
**                       Smu_ClearAlarmStatus returning an error              **
**                    SFF_SMU_GETALMACTIONERR - Test failed because           **
**                      Smu_GetAlarmAction returned an error                  **
**                    SFF_SMU_SETALMACTIONERR - Test failed due to            **
**                      Smu_SetAlarmAction returning an error                 **
**                                                                            **
** Description      : SffTst_SffTst is the API which is responsible for test  **
**                    preparation, test execution and final test              **
**                    restoration. .                                          **
*******************************************************************************/
Sl_TstRsltType SffTst_SffTst
(
  const Sl_ParamSetType ParamSetIndex,
  const uint8 TstSeed,
  uint32* const TstSignature
)
{
  Sl_TstRsltType  Result = SFF_NOTEXECUTED;
  Sl_TstRsltType  TempResult = SFF_NOTEXECUTED;
  Smu_AlarmActionType  BackupData;

  UNUSED_PARAMETER(ParamSetIndex)

  /* Initialize Test Signature */
  *TstSignature = (uint32)CRC32((uint32)TEST_ID_SFF_TST, (uint32)TstSeed);

  /* Check that all prerequisites are met */
  Result = SffTst_lCheckPrerequisites();

  if (SFF_SUCCESS == Result)
  {
    /* Initialize SFF test */
    Result = SffTst_lInit(&BackupData, TstSignature);

    if (SFF_SUCCESS == Result)
    {
      /* Execute SFF test */
      Result = SffTst_lTstExecute(TstSignature);

      /* Restore the values changed during SFF test */
      TempResult = SffTst_lRestore(&BackupData, TstSignature);

      if (SFF_SUCCESS == Result)
      {
        /* If SffTst_lTstExecute is successful, result of the SffTst_lRestore
           is returned else result of SffTst_lTstExecute takes priority*/
        Result = TempResult;
      }
    }
  }

  *TstSignature = (uint32)CRC32(*TstSignature, (uint32)Result);
  return Result;
}

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : SffTst_lCheckPrerequisites(void)                        **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters (in)  : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : SFF_SUCCESS - Test succeeded                            **
**                    SFF_NOTEXECUTED - This error is never intentionally     **
**                      returned; if it is returned anyway, something         **
**                      very serious must be wrong                            **
**                    SFF_RM_TESTENABLEDERR - Test failed due to a RM test    **
**                      mode is already enabled when SFF test is called.      **
**                    SFF_SMU_STATEERR - Test initialization failed due to    **
**                      an invalid run state of the SMU                       **
**                    SFF_SMU_ALMSTSERR - Test failed due to a SMU alarm      **
**                      which is expected to be set is already set            **
**                    SFF_SMU_GETALMSTSERR - Test failed because              **
**                      Smu_GetAlarmStatus returned an error                  **
**                                                                            **
** Description      : Sff_lCheckPrerequisites performs all checks that are    **
**                    required before test initialization can be done.        **
**                    This includes checking the configuration settings,      **
**                    the run state of the SMU as well as the current state   **
**                    of SMU alarms triggered by the test (which must not be  **
**                    set before the test is executed). .                     **
*******************************************************************************/
static Sl_TstRsltType SffTst_lCheckPrerequisites(void)
{
  Sl_TstRsltType Result = SFF_NOTEXECUTED;
  uint32 AlarmStatus;

  if (SMU_RUN_STATE != Smu_GetSmuState())
  {
    Result = SFF_SMU_STATEERR;
  }
  /* Return error if the Test mode is already enabled */
  else if (SFF_RMCTL_TESTMODE_EN == SMU_RMCTL.B.TE)
  {
    Result = SFF_RM_TESTENABLEDERR;
  }
  else if (E_OK != Smu_GetAlarmStatus(SMU_REG_MON_ED_ALARM_GRP, &AlarmStatus))
  {
    Result = SFF_SMU_GETALMSTSERR;
  }
  /* Return error if alarm is already set */
  else if (AlarmStatus & SMU_REG_MON_ED_ALARM_STS)
  {
    Result = SFF_SMU_ALMSTSERR;
  }
  else
  {
    Result = SFF_SUCCESS;
  }
  return Result;
}


/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : Sl_TstRsltType SffTst_lInit                             **
**                    (                                                       **
**                      Smu_AlarmActionType* const BackupData                 **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters (in)  : None                                                    **
**                                                                            **
** Parameters (out) : *BackupData - Pointer to backed up SMU configuration    **
**                    TstSingature - Test signature generated by the test     **
**                                                                            **
** Return value     : SFF_SUCCESS - Test succeeded                            **
**                    SFF_NOTEXECUTED - This error is never intentionally     **
**                      returned; if it is returned anyway, something         **
**                      very serious must be wrong                            **
**                    SFF_SMU_GETALMACTIONERR - Test failed because           **
**                      Smu_GetAlarmAction returned an error                  **
**                    SFF_SMU_SETALMACTIONERR - Test failed due to            **
**                      Smu_SetAlarmAction returning an error                 **
**                                                                            **
** Description      : Sff_lInit stores a backup copy of SMU configuration     **
**                    settings that will be modified by the test.             **
**                    Additionally it performs all initialization steps       **
**                    required for testing.                                   **
*******************************************************************************/
static Sl_TstRsltType SffTst_lInit
(
  Smu_AlarmActionType* const BackupData,
  uint32* const TstSignature
)
{
  Sl_TstRsltType    Result = SFF_NOTEXECUTED;
  Smu_FSPActionType FspActionDummy;

  if (E_OK != Smu_GetAlarmAction(SMU_REG_MON_ED_ALARM_GRP, \
                                 SMU_REG_MON_ED_ALARM, \
                                 BackupData, \
                                 &FspActionDummy))
  {
    Result = SFF_SMU_GETALMACTIONERR;
    *BackupData = SMU_INVALID_ALARM_ACTION;
  }
  else
  {
    if (E_OK != Smu_SetAlarmAction(SMU_REG_MON_ED_ALARM_GRP, \
                                   SMU_REG_MON_ED_ALARM, \
                                   SMU_ALARM_ACTION_NONE))
    {
      Result = SFF_SMU_SETALMACTIONERR;
      *BackupData = SMU_INVALID_ALARM_ACTION;
    }
    else
    {
      /* Reset the Register monitor Status and error flags
         Both SMU_RMSTS and SMU_RMEF are SE registers
      */
      Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);
      SMU_RMSTS.U = (uint32)SFF_ZERO;
      SMU_RMEF.U = (uint32)SFF_ZERO;
      Mcal_SetSafetyENDINIT_Timed();
      Result = SFF_SUCCESS;
    }
  }

  *TstSignature = (uint32)CRC32(*TstSignature, (uint32)Result);
  return Result;
}

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : Sl_TstRsltType SffTst_lTstExecute                       **
**                    (                                                       **
**                      uint32* const TstSignature                            **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters (in)  : None                                                    **
**                                                                            **
** Parameters (out) : TstSingature - Test signature generated by the test     **
**                                                                            **
** Return value     : SFF_SUCCESS - Test succeeded                            **
**                    SFF_NOTEXECUTED - This error is never intentionally     **
**                      returned; if it is returned anyway, something         **
**                      very serious must be wrong                            **
**                    SFF_RM_TIMEOUTERR - Test failed due to timeout in the   **
**                      RM test completion                                    **
**                    SFF_RM_ALARMNOTSETERR - Test failed due to alarm being  **
**                      not set after executing RM safety mechanism           **
**                    SFF_RM_ERRORFLAGERR - Test failed due to fault          **
**                      condition in RM safety mechanism                      **
**                    SFF_RM_SMU_ERROR - Safety flip-flop test failed in      **
**                      SMU module                                            **
**                    SFF_RM_SCU_ERROR - Safety flip-flop test failed in      **
**                      SCU module                                            **
**                    SFF_RM_SMU_SCU_ERROR - Safety flip-flop test failed in  **
**                      SMU and SCU module                                    **
**                    SFF_RM_MTU_ERROR - Safety flip-flop test failed in      **
**                      MTU module                                            **
**                    SFF_RM_MTU_SMU_ERROR - Safety flip-flop test failed in  **
**                      MTU and SMU module                                    **
**                    SFF_RM_MTU_SCU_ERROR - Safety flip-flop test failed in  **
**                      MTU and SCU module                                    **
**                    SFF_RM_MTU_SCU_SMU_ERROR - Safety flip-flop test failed **
**                      in MTU,SCU and SMU module                             **
**                    SFF_SMU_GETALMSTSERR - Test failed because              **
**                      Smu_GetAlarmStatus returned an error                  **
**                                                                            **
** Description      : SffTst_lTstExecute performs the actual test execution   **
**                    safety flip-flop register monitor safety mechanism.     **
**                    It enables the RM test mode and expects the completion  **
**                    of the self-test and also no error is detected.         **
**                    If not, error is returned                               **
*******************************************************************************/
static Sl_TstRsltType  SffTst_lTstExecute
(
  uint32* const TstSignature
)
{
  Sl_TstRsltType Result = SFF_NOTEXECUTED;
  uint32 AlarmStatus = (uint32)SFF_ZERO;
  uint8 RmTimeout = SFF_ZERO;
  uint32 SffRmActiveBits = SFF_RM_ACTIVEBITS_DEFAULT;
  uint32 SffRmErrorBits = SFF_ZERO;
  #if (CHIP_ID == 27U)
  uint8 ChipRevStep;
  #endif

  /* Enable Register monitor Test mode.
     RMCTL is SE register
     SMU must be unlocked before writing into the register
  */
  Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);
  SMU_KEYS.U = SMU_CFG_KEY_UNLOCK;
  SMU_RMCTL.U = SFF_RMCTL_TESTMODE_EN;
  SMU_KEYS.U = SMU_CFG_KEY_TEMPLOCK;
  Mcal_SetSafetyENDINIT_Timed();

  #if (CHIP_ID == 27U)
  ChipRevStep = (uint8)(((uint8)(SCU_CHIPID.B.CHREV)) \
                                            >> CHIPID_CHREV_MAJOR_STEP_OFFSET);

  /*
    Bits[5:4] of CHREV:
            00b for A-step silicon
            01b for B-step silicon
            10b for C-step silicon
    Due to a limitation in the devices upto/including B-step, safety flip-flops
    located in the SMU are not verifed. Hence the corresponding bit for SMU in
    RMEF and RMSTS registers are ignored
  */
  if (ChipRevStep <= SFF_ONE)
  {
    SffRmActiveBits = SFF_RM_ACTIVEBITS_MTU_SCU;
  }
  #endif

  /* Wait until all the active Status bits are set OR timeout */
  while ((SffRmActiveBits != (SMU_RMSTS.U & SffRmActiveBits)) \
                                            && (RmTimeout <= SFF_RM_TIMEOUT))
  {
    RmTimeout++;
  }

  if (RmTimeout >= SFF_RM_TIMEOUT)
  {
    /* Timeout error has occurred */
    Result = SFF_RM_TIMEOUTERR;
  }
  else
  {
    SffRmErrorBits  = SffRmActiveBits & (SMU_RMEF.U);
	if (SFF_ZERO != SffRmErrorBits)
    {
       /* Self-test has detected fault condition */
       switch (SffRmErrorBits)
       {
          /* Error in SMU */
          case SFF_RM_SMU_ERROR_CONDITION:
            Result = SFF_RM_SMU_ERROR;
            break;
          /* Error in SCU */
          case SFF_RM_SCU_ERROR_CONDITION:
            Result = SFF_RM_SCU_ERROR;
            break;
          /* Error in SMU and SCU */
          case SFF_RM_SMU_SCU_ERROR_CONDITION:
            Result = SFF_RM_SMU_SCU_ERROR;
            break;
          /* Error in MTU */
          case SFF_RM_MTU_ERROR_CONDITION:
            Result = SFF_RM_MTU_ERROR;
            break;
          /* Error in MTU and SMU */
          case SFF_RM_MTU_SMU_ERROR_CONDITION:
            Result = SFF_RM_MTU_SMU_ERROR;
            break;
          /* Error in MTU and SCU */
          case SFF_RM_MTU_SCU_ERROR_CONDITION:
            Result = SFF_RM_MTU_SCU_ERROR;
            break;
          /* Error in MTU, SCU and SMU */
          case SFF_RM_MTU_SCU_SMU_ERROR_CONDITION:
            Result = SFF_RM_MTU_SCU_SMU_ERROR;
            break;
          default:
            Result = SFF_RM_ERRORFLAGERR;
            break;
       }
    }
    else
    {
      if (E_OK != Smu_GetAlarmStatus(SMU_REG_MON_ED_ALARM_GRP, &AlarmStatus))
      {
        Result = SFF_SMU_GETALMSTSERR;
      }
      else
      {
        if (SMU_REG_MON_ED_ALARM_STS != \
                                    (AlarmStatus & SMU_REG_MON_ED_ALARM_STS))
        {
          /* Alarm is not Set, hence return error */
          Result = SFF_RM_ALARMNOTSETERR;
        }
        else
        {
          Result = SFF_SUCCESS;
        }
      }
    }
  }

  /* Update signature with alarm status of SFF */
  *TstSignature = (uint32)CRC32(*TstSignature, \
                            (uint32)(AlarmStatus & SMU_REG_MON_ED_ALARM_STS));


  return (Result);
}

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : Sl_TstRsltType SffTst_lRestore                          **
**                    (                                                       **
**                      const Smu_AlarmActionType* const BackupData           **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters (in)  : *BackupData - Pointer to backed up SMU configuration    **
**                                                                            **
** Parameters (out) : TstSingature - Test signature generated by the test     **
**                                                                            **
** Return value     : SFF_SUCCESS - Test succeeded                            **
**                    SFF_NOTEXECUTED - This error is never intentionally     **
**                      returned; if it is returned anyway, something         **
**                      very serious must be wrong                            **
**                    SFF_SMU_CLRALMSTSERR - Test restoration failed due to   **
**                       Smu_ClearAlarmStatus returning an error              **
**                    SFF_SMU_GETALMACTIONERR - Test failed because           **
**                      Smu_GetAlarmAction returned an error                  **
**                    SFF_SMU_SETALMACTIONERR - Test failed due to            **
**                      Smu_SetAlarmAction returning an error                 **
**                                                                            **
** Description      : Sff_lRestore restores the value of SMU alarm actions    **
**                    that were modified by the test to their original        **
**                    content.                                                **
*******************************************************************************/
static Sl_TstRsltType SffTst_lRestore
(
  const Smu_AlarmActionType* const BackupData,
  uint32* const TstSignature
)
{
  Sl_TstRsltType  Result = SFF_NOTEXECUTED;

  /* Enable Register monitor Test mode. RMCTL is SE register.
     SMU must be unlocked before writing into the register.
     Before clearing the Alarm Status, register test mode(TE) has to be disabled
  */
  Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);
  SMU_KEYS.U = SMU_CFG_KEY_UNLOCK;
  SMU_RMCTL.U = SFF_RMCTL_TESTMODE_DIS;
  SMU_KEYS.U = SMU_CFG_KEY_TEMPLOCK;
  Mcal_SetSafetyENDINIT_Timed();

  /* Clear SMU alarm caused by the Register monitor self-test */
  if (E_OK != Smu_ClearAlarmStatus(SMU_REG_MON_ED_ALARM_GRP, \
                                   SMU_REG_MON_ED_ALARM))
  {
    Result = SFF_SMU_CLRALMSTSERR;
  }
  else if (E_OK != Smu_SetAlarmAction(SMU_REG_MON_ED_ALARM_GRP, \
                                      SMU_REG_MON_ED_ALARM, \
                                      (*BackupData)))
  {
    Result = SFF_SMU_SETALMACTIONERR;
  }
  else
  {
    /* Reset the Register monitor Status and error flags
       Both SMU_RMSTS and SMU_RMEF are SE registers
    */
    Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);
    SMU_RMSTS.U = (uint32)SFF_ZERO;
    SMU_RMEF.U = (uint32)SFF_ZERO;
    Mcal_SetSafetyENDINIT_Timed();
    Result = SFF_SUCCESS;
  }

  *TstSignature = (uint32)CRC32(*TstSignature, (uint32)Result);
  return Result;
}

#define IFX_SFFTST_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"