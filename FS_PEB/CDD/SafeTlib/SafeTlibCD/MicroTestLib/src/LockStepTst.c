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
**  $FILENAME   : LockStepTst.c $                                            **
**                                                                            **
**  $CC VERSION : \main\23 $                                                 **
**                                                                            **
**  $DATE       : 2018-02-22 $                                               **
**                                                                            **
**  VARIANT     : VariantPB                                                   **
**                                                                            **
**  PLATFORM    : Infineon Aurix                                              **
**                                                                            **
**  AUTHOR      : DL-BLR-ATV-STC                                              **
**                                                                            **
**  VENDOR      : Infineon Technologies                                       **
**                                                                            **
**  DESCRIPTION : This file contains functionality of LockStep Test           **
**                                                                            **
**  REFERENCE(S): Aurix-HE_SafeTlib_DS_LockStep_Test                          **
**                                                                            **
**  MAY BE CHANGED BY USER [Yes/No]: No                                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "LockStepTst.h"
#include "SmuInt.h"

/*******************************************************************************
**                      Local Macro Definitions                             **
*******************************************************************************/

/* LCL SMU alarm is Bit 0 of SMU group x                                      */
#define LOCKSTEP_ERR_SMU_ALARM          ((uint8)SMU_ALARM_0 )

/* LockStep Comparator Error SMU alarm                                        */
#define LOCKSTEP_SMU_LCE_ALARM          ( 1U )

/* SMU alarm timeout. The value was chosen based on following considerations:
 * The worst case number of SMU cycles before an alarm gets visible is
 * n * 2 + 20 (with n = max. number of simultaneous alarms). With a maximum
 * of 32 * 7 alarms and maximum clock ratio fSPB/fSRI = 1/4 this evaluates to
 * 1872 CPU clock cycles. To avoid the counting the number of instructions per
 * loop cycle, it is assumed that only one instruction is executed per loop
 * cycle and thus the number of CPU clock cycles is directly used as timeout
 * value:
 */
#define LOCKSTEP_SMU_ALM_TIMEOUT       ( 2000U )

/* LockStep test does not support any configuration                           */
#define LOCKSTEP_CFG_PARAM_COUNT       ( (uint32)(0))

/* LockStep Enabled                                                           */
#define LOCKSTEP_ENABLED               ( 1U )

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Local Type Definitions                                **
*******************************************************************************/


/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/
/*******************************************************************************
**                        Local object definitions                            **
*******************************************************************************/

/* SEC CONST UNSPECIFIED                                                      */
#define IFX_LOCKSTEP_START_SEC_CONST_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"

static const LockStepTst_RegMapType *
                           const LockStepTst_kLockStepEnable[MCAL_NO_OF_CORES] =
{
#if ( ( CHIP_ID == 22U ) || ( CHIP_ID == 23U ) || ( CHIP_ID == 27U ) || ( CHIP_ID == 21U ) )

  CPU0_SCU_LCLCON0,
#else
  /* Placeholder to get proper index to access the element using core id      */
  DUMMY_PLACEHOLDER,
#endif /*  CPU0 LockStep */

#if ( MCAL_NO_OF_CORES > 1U )

  CPU1_SCU_LCLCON1,
#endif

#if ( MCAL_NO_OF_CORES > 2U )
  /* There is no device yet available with core2 checker core                 */
  DUMMY_PLACEHOLDER
#endif
};

#define IFX_LOCKSTEP_STOP_SEC_CONST_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"

/* SEC CONST 32BIT                                                            */
#define IFX_LOCKSTEP_START_SEC_CONST_32BIT_ASIL_B
#include "Ifx_MemMap.h"

static const uint32 LockStepTst_kFaultInjectionEnable[MCAL_NO_OF_CORES] =
{
  CPU0_LOCKSTEP_FAULT_INJ,

#if ( MCAL_NO_OF_CORES > 1U )
  CPU1_LOCKSTEP_FAULT_INJ,
#endif

  /* There is no device yet available with core2 checker core                 */
#if ( MCAL_NO_OF_CORES > 2U )
  DUMMY_PLACEHOLDER
#endif

};

#define IFX_LOCKSTEP_STOP_SEC_CONST_32BIT_ASIL_B
#include "Ifx_MemMap.h"

/* SEC CONST 8BIT                                                             */
#define IFX_LOCKSTEP_START_SEC_CONST_8BIT_ASIL_B
#include "Ifx_MemMap.h"

static const uint8 LockStepTst_kSmuAlarmGrp[MCAL_NO_OF_CORES] =
{
  CPU0_SMU_LOCKSTEP_CMP_ERROR_GRP,

#if ( MCAL_NO_OF_CORES > 1U )
  CPU1_SMU_LOCKSTEP_CMP_ERROR_GRP,
#endif

  /* There is no device yet available with core2 checker core                 */
#if ( MCAL_NO_OF_CORES > 2U )
  DUMMY_PLACEHOLDER
#endif
};

static const uint8 LockStepTst_LockStepCoreStatus[MCAL_NO_OF_CORES] =
{
  LOCKSTEPCORE_0,

#if ( MCAL_NO_OF_CORES > 1U )
  LOCKSTEPCORE_1,
#endif

#if ( MCAL_NO_OF_CORES > 2U )
  LOCKSTEPCORE_2
#endif
};

#define IFX_LOCKSTEP_STOP_SEC_CONST_8BIT_ASIL_B
#include "Ifx_MemMap.h"

/*******************************************************************************
**                        Local function prototypes                           **
*******************************************************************************/
#define IFX_LOCKSTEP_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
static Sl_TstRsltType LockStepTst_lInit
(
  Smu_AlarmActionType* const AlmActionBackupLockStep
);

static Sl_TstRsltType LockStepTst_lRestore
(
  const Smu_AlarmActionType* const AlmActionBackupLockStep
);

static Sl_TstRsltType LockStepTst_lExecuteTst
(
  uint32* const TstSignature
);

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/



/*******************************************************************************
**                       Private Function Definitions                         **
*******************************************************************************/


/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : Sl_TstRsltType LockStepTst_LockStepTst                  **
**                                      (const Sl_ParamSetType ParamSetIndex, **
**                                       const uint8 TstSeed,                 **
**                                       uint32* const TstSignature);         **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : ParamSetIndex : Identifies the parameter set to be      **
**                                    used for test execution                 **
**                    TstSeed : Seed to be used for generating the signature  **
**                                                                            **
** Parameters (out) : TstSignature : Test signature generated by the test     **
**                                                                            **
** Return value     : LOCKSTEP_SUCCESS - Test succeeded                       **
**                    <Error ID> - Type of error during test                  **
**                                                                            **
** Description      : API provided to check working of LockStep test          **
**                                                                            **
*******************************************************************************/
Sl_TstRsltType LockStepTst_LockStepTst
(
 const Sl_ParamSetType ParamSetIndex,
 const uint8 TstSeed,
 uint32* const TstSignature
)
{
  Sl_TstRsltType Result = LOCKSTEP_NOTEXECUTED;
  Sl_TstRsltType ResultInitExecute = LOCKSTEP_NOTEXECUTED;
  Sl_TstRsltType ResultRestore = LOCKSTEP_NOTEXECUTED;
  /* Storage for backup of the SMU CPUx LockStep Comparator alarm action
   * modified in the test.(SMU Group x Alarm 0)                               */
  Smu_AlarmActionType AlmActionBackupLockStep = 0U;
  uint8 CoreId;

  /* Read the core Id                                                         */
  CoreId = Mcal_GetCoreId();

  /* Initialize Test Signature:                                               */
  *TstSignature = (uint32)CRC32((uint32)TEST_ID_LOCK_STEP_TST, (uint32)TstSeed);

  /* Validate the configuration parameter                                     */
  if(ParamSetIndex > LOCKSTEP_CFG_PARAM_COUNT)
  {
    Result = LOCKSTEP_INVPARAM;
  }
  /* Check for existence of LockStep for executing core.                      */
  else if( CoreId ==   LockStepTst_LockStepCoreStatus[CoreId] )
  { /* Executing core is LockStep enabled                                     */
    if(SMU_RUN_STATE == Smu_GetSmuState())
    {
      /* Backup SMU alarms and SFR configs that will be modified              */
      ResultInitExecute = LockStepTst_lInit(&AlmActionBackupLockStep);

      if(ResultInitExecute == (Sl_TstRsltType)LOCKSTEP_SUCCESS)
      { /* Successful LockStepTst initialization                              */
        /* Inject fault in Lockstep comparator                                */
        ResultInitExecute = LockStepTst_lExecuteTst(TstSignature);
      }

      /* Restore SMU alarms and SFR configs that were modified                */
      ResultRestore = LockStepTst_lRestore(&AlmActionBackupLockStep);

      if(LOCKSTEP_SUCCESS == ResultInitExecute)
      { /* Successful LockStepTst execution                                   */
        if(LOCKSTEP_SUCCESS == ResultRestore)
        { /* Successful LockStepTst restore                                   */
          Result = LOCKSTEP_SUCCESS;
        }
        else
        {/* LockStepTst restore fails                                         */
          Result = ResultRestore;
        }
      }
      else
      {/* Successful LockStepTst execution fails                              */
        Result = ResultInitExecute ;
      }
    }
    else
    { /* SMU is not in RUN state                                              */
      Result = (Sl_TstRsltType)LOCKSTEP_SMU_STATEERR;
    }
  }
  else
  {/* Executing core is not LockStep enabled                                  */
    Result = LOCKSTEP_NON_LOCKSTEP_CORE;
  }

  /* Update TstSignature with final test result                               */
  *TstSignature = (uint32)(CRC32(*TstSignature, Result));

  return(Result);
}

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static Sl_TstRsltType LockStepTst_lInit                 **
**                    (Smu_AlarmActionType*                                   **
**                      const AlmActionBackupLockStep)                        **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : None.                                                   **
**                                                                            **
** Parameters (out) : TstSignature : Test signature generated by the test     **
**                                                                            **
** Return value     : LOCKSTEP_SUCCESS - Test succeeded                       **
**                    <Error ID> - Type of error during test                  **
**                                                                            **
** Description      : Backup SFR and SMU alarm that will be modified.         **
**                                                                            **
*******************************************************************************/

static Sl_TstRsltType LockStepTst_lInit
(
  Smu_AlarmActionType* const AlmActionBackupLockStep
)
{
  Sl_TstRsltType      Result  = LOCKSTEP_NOTEXECUTED;
  uint32              AlmStatus = 0U;
  Smu_FSPActionType   FspActionDummy = 0U;
  uint8               CoreId;

  /* Read the core Id                                                         */
  CoreId = Mcal_GetCoreId();

  /* Get the SMU alarm action for Group 0/1 alarm 0                           */
  if(E_OK != (Smu_GetAlarmAction(LockStepTst_kSmuAlarmGrp[CoreId], SMU_ALARM_0,
  AlmActionBackupLockStep, &FspActionDummy)))
  {
    /* Set to Invalid Alarm Action                                            */
    *AlmActionBackupLockStep = SMU_INVALID_ALARM_ACTION;

    Result = LOCKSTEP_SMU_GETALMACTIONERR;
  }
  else
  {
    /* Check if LockStep is enabled                                           */
    if(((uint32)(LockStepTst_kLockStepEnable[CoreId]->SCULCLCON.B.LS)) == LOCKSTEP_ENABLED)
    {
      /* Get SMU Alarm Status and check operation was done properly           */
      if(E_OK !=
      (Smu_GetAlarmStatus(LockStepTst_kSmuAlarmGrp[CoreId], &AlmStatus)))
      {/* Getting SMU Alarm status for group CoreId fails                     */
        Result = LOCKSTEP_SMU_GETALMSTSERR;
      }
      else
      {
        /* Check for SMU Alarm state                                          */
        if(0U != (AlmStatus & ((uint32)LOCKSTEP_SMU_LCE_ALARM)))
        {/* Already a SMU Alarm is present                                    */
          Result = LOCKSTEP_SMU_ALMSTSERR;
        }
        else
        { /* Set the alarm action to none and check if setting was fine       */
          if(E_OK !=
          Smu_SetAlarmAction(LockStepTst_kSmuAlarmGrp[CoreId], SMU_ALARM_0,
          SMU_ALARM_ACTION_NONE))
          {/* Setting SMU alarm action fails                                  */
            Result = LOCKSTEP_SMU_SETALMACTIONERR;
          }
          else
          { /* Proper settings done for LockStep test execution               */
            Result = LOCKSTEP_SUCCESS;
          }
        }
      }
    }
    else
    { /* LockStep is not enabled                                              */
      Result = LOCKSTEP_DISABLE;
    }
  }

  return(Result);
}

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static Sl_TstRsltType LockStepTst_lRestore              **
**                   (const Smu_AlarmActionType*                              **
**                    const AlmActionBackupLockStep)                          **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : ParamSetIndex : Identifies the parameter set to be      **
**                                    used for test execution                 **
**                    TstSeed : Seed to be used for generating the signature  **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : LOCKSTEP_SUCCESS - Test succeeded                       **
**                    <Error ID> - Type of error during test                  **
**                                                                            **
** Description      : Restore modified SFR and SMU alarms modified during test**
**                                                                            **
*******************************************************************************/

static Sl_TstRsltType LockStepTst_lRestore
(
  const Smu_AlarmActionType* const AlmActionBackupLockStep
)
{
  Sl_TstRsltType      Result  = LOCKSTEP_NOTEXECUTED;
  uint8               CoreId;

  /* Read the core Id                                                         */
  CoreId = Mcal_GetCoreId();

  /* Restore the stored SMU alarms                                            */
  if(E_OK != Smu_SetAlarmAction(LockStepTst_kSmuAlarmGrp[CoreId], SMU_ALARM_0,
     *AlmActionBackupLockStep) )
  {/* Setting SMU alarm action fails                                          */
    Result = LOCKSTEP_SMU_SETALMACTIONERR;
  }
  else
  {/* Setting SMU alarm action and Restore successful                         */
    Result = LOCKSTEP_SUCCESS;
  }

  return(Result);
}

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static Sl_TstRsltType LockStepTst_lExecuteTst           **
**                    ( uint32* const TstSignature)
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : TstSignature : Test signature generated by the test     **
**                                                                            **
** Return value     : LOCKSTEP_SUCCESS - Test succeeded                       **
**                    <Error ID> - Type of error during test                  **
**                                                                            **
** Description      : Inject error in LockStep comparator to test LCL         **
**                    mechanism.                                              **
**                                                                            **
*******************************************************************************/

static Sl_TstRsltType LockStepTst_lExecuteTst
(
  uint32* const TstSignature
)
{
  Sl_TstRsltType      Result = LOCKSTEP_NOTEXECUTED;
  uint32              AlmStatus = 0x0U;
  uint32              Timeout   = LOCKSTEP_SMU_ALM_TIMEOUT;
  uint8               CoreId;

  /* Read the core Id                                                         */
  CoreId = Mcal_GetCoreId();

  /* Inject fault in the CPU with CoreId                                      */
  SCU_LCLTEST.U = LockStepTst_kFaultInjectionEnable[CoreId];

  /* Check SMU Alarm status for CoreId                                        */
  while((0U == (AlmStatus & ((uint32)LOCKSTEP_SMU_LCE_ALARM))) && \
                                                               ((Timeout) > 0U))
  {
    Timeout--;

    /* Get SMU Alarm status for group CoreId                                  */
    if(E_OK != Smu_GetAlarmStatus(LockStepTst_kSmuAlarmGrp[CoreId], &AlmStatus))
    {/* Getting SMU Alarm status for group CoreId fails                       */
      AlmStatus = 0U;
      Timeout = 0U;
      Result = LOCKSTEP_SMU_GETALMSTSERR;
    }
  }

  /* Check if the SMU Alarm is present or not                                 */
  if(0U != (AlmStatus & ((uint32)LOCKSTEP_SMU_LCE_ALARM)))
  {
    /* Clear the Lockstep error SMU alarm                                     */
    if(E_OK != Smu_ClearAlarmStatus(LockStepTst_kSmuAlarmGrp[CoreId],
                                                    LOCKSTEP_ERR_SMU_ALARM))
    {/* Clearing SMU alarm fails                                              */
      Result = LOCKSTEP_SMU_CLRALMSTSERR;
    }
    else
    {/* Successful detection of faulty condition in LockStep mechanism        */
      Result = LOCKSTEP_SUCCESS;
    }
  }
  else
  {/* Detection of faulty condition in LockStep mechanism unsuccessful        */
    if(Result == LOCKSTEP_NOTEXECUTED)
    {
      Result = LOCKSTEP_NO_SMUALRM;
    }
  }

  /* Update signature with LockStep Alarm                                     */
  *TstSignature = (uint32)CRC32(*TstSignature, (AlmStatus & \
                                                       LOCKSTEP_SMU_LCE_ALARM));

  return(Result);
}

#define IFX_LOCKSTEP_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
