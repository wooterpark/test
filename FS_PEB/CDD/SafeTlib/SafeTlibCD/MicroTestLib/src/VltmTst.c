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
**  $FILENAME   : VltmTst.c $                                                **
**                                                                            **
**  $CC VERSION : \main\36 $                                                 **
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
**  DESCRIPTION  : This file contains the Voltage Monitor test                **
**                                                                            **
**  REFERENCE(S) : Aurix-HE_SafeTlib_DS_VoltageMonitor, v1.7                  **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/

 
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Mcal.h"
#include "VltmTst.h"
#include "IfxScu_reg.h"
#include "IfxScu_bf.h"

/*******************************************************************************
**                      Local Macro Definitions                               **
*******************************************************************************/
/*******************************************************************************
**                      Local Type Definitions                                **
*******************************************************************************/

/*******************************************************************************
**                        Exported object definitions                         **
*******************************************************************************/

/*******************************************************************************
**                        Local object definitions                            **
*******************************************************************************/

/*******************************************************************************
**                        Local function prototypes                           **
*******************************************************************************/
#define IFX_VLTM_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
static Sl_TstRsltType VltmTst_lInit
(
  VltmTst_BackupDataType* const Vltm_BackupData
);

static Sl_TstRsltType VltmTst_lRestore
(
  const VltmTst_BackupDataType * const Vltm_BackupData
);

static Sl_TstRsltType VltmTst_lClearSMUAlarms(void);

static Sl_TstRsltType VltmTst_lCheckUnderVoltage
(
  uint32* const TstSignature
);

static Sl_TstRsltType VltmTst_lCheckOverVoltage
(
  uint32* const TstSignature
);

/*******************************************************************************
**                        Imported function declarations                      **
*******************************************************************************/


/*******************************************************************************
**                    Local inline function definitions                       **
*******************************************************************************/

/*******************************************************************************
**                    Configuration error checking                            **
*******************************************************************************/


/*******************************************************************************
**                         Function definitions                               **
*******************************************************************************/


/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static Sl_TstRsltType VltmTst_lInit                     **
**                    (VltmTst_BackupDataType * const Vltm_BackupData)        **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : Vltm_BackupData - Pointer to VltmTst_BackupDataType     **
**                    struct that holds a backup of the current SMU alarm     **
**                    action configuration and the EVRxMON SFR registers.     **
**                                                                            **
** Return value     : VLTM_SUCCESS - If Initialization succeeded.             **
**                    VLTM_SMU_SETALMACTIONERR - If Initialization failed     **
**                    because setting an SMU alarm action failed.             **
**                    VLTM_SMU_GETALMACTIONERR - If Initialization failed     **
**                    because getting an SMU alarm action failed.             **
**                    VLTM_SMU_ALMSTSERR - If Initialization failed because   **
**                    there is already an SMU alarm present.                  **
**                    VLTM_SMU_GETALMSTSERR - Test failed because getting     **
**                    the SMU alarm status failed.                            **
**                                                                            **
** Description      : This function does a backup of the current SMU voltage  **
**                    alarm actions and the EVRxVMON registers that will be   **
**                    overwritten by this test. It also sets the SMU actions  **
**                    to “no action”.  .                                      **
*******************************************************************************/
static Sl_TstRsltType VltmTst_lInit
(VltmTst_BackupDataType * const Vltm_BackupData)
{
  Sl_TstRsltType Result = VLTM_NOTEXECUTED;
  Std_ReturnType SmuResult1 = E_NOT_OK;
  Std_ReturnType SmuResult2 = E_NOT_OK;
  Std_ReturnType SmuResult3 = E_NOT_OK;
  Std_ReturnType SmuResult4 = E_NOT_OK;
#if (VLTM_VEXT_MONITOR == TRUE)  
  Std_ReturnType SmuResult5 = E_NOT_OK;
  Std_ReturnType SmuResult6 = E_NOT_OK;
#endif

  /* Fsp action will not be overwritten and hence doesn't need to be saved    */
  Smu_FSPActionType FspDummy;
  uint32 AlarmStatus = 0U;

  /* Backup settings for over- and under-voltage monitoring thresholds        */
  Vltm_BackupData->EvrOvMon_Backup = SCU_EVROVMON.U;
  Vltm_BackupData->EvrUvMon_Backup = SCU_EVRUVMON.U;

  /* Backup settings for Monitor control register                             */
  Vltm_BackupData->EvrMonCtrl_Backup = SCU_EVRMONCTRL.U;

  /* Set the EVRMONCTRL with reset value */
  Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT); 
  SCU_EVRMONCTRL.U =  VLTM_EVRMONCTRL_RESET;
  Mcal_SetSafetyENDINIT_Timed();
  
  /* Back up of SMU alarms action which is used for VltmTst 
     (i.e. AG3[11, 12, 13, 14, 15, 16] */  
  SmuResult1 = Smu_GetAlarmAction(SMU_SCU_EVR_GRP, SMU_SCU_EVR_VDD_UV,
                                  &(Vltm_BackupData->AlmActionBackupVDD_UV),
                                  &FspDummy);

  SmuResult2 = Smu_GetAlarmAction(SMU_SCU_EVR_GRP, SMU_SCU_EVR_VDD_OV,
                                  &(Vltm_BackupData->AlmActionBackupVDD_OV),
                                  &FspDummy);

  SmuResult3 = Smu_GetAlarmAction(SMU_SCU_EVR_GRP, SMU_SCU_EVR_VDDP3_UV,
                                  &(Vltm_BackupData->AlmActionBackupVDDP3_UV),
                                  &FspDummy);

  SmuResult4 = Smu_GetAlarmAction(SMU_SCU_EVR_GRP, SMU_SCU_EVR_VDDP3_OV,
                                  &(Vltm_BackupData->AlmActionBackupVDDP3_OV),
                                  &FspDummy);
#if (VLTM_VEXT_MONITOR == TRUE)

  SmuResult5 = Smu_GetAlarmAction(SMU_SCU_EVR_GRP, SMU_SCU_EVR_VEXT_UV,
                                  &(Vltm_BackupData->AlmActionBackupVEXT_UV),
                                  &FspDummy);
  

  SmuResult6 = Smu_GetAlarmAction(SMU_SCU_EVR_GRP, SMU_SCU_EVR_VEXT_OV,
                                  &(Vltm_BackupData->AlmActionBackupVEXT_OV),
                                  &FspDummy);
  
#endif

  /* Check the result of Smu_GetAlarmAction */                                  
#if (VLTM_VEXT_MONITOR == TRUE) 
  if ( (SmuResult1 != E_OK) || (SmuResult2 != E_OK) || (SmuResult3 != E_OK) ||
       (SmuResult4 != E_OK) || (SmuResult5 != E_OK) || (SmuResult6 != E_OK) )
#else
  if ( (SmuResult1 != E_OK) || (SmuResult2 != E_OK) || (SmuResult3 != E_OK) ||
       (SmuResult4 != E_OK) )
#endif	   
  {
    Vltm_BackupData->GetAlmActionResult = E_NOT_OK;
    Result = VLTM_SMU_GETALMACTIONERR;
  }
  else
  {
    Vltm_BackupData->GetAlmActionResult = E_OK;

    /* Check the result of Smu_GetAlarmStatus() */
    if(E_OK == Smu_GetAlarmStatus(SMU_SCU_EVR_GRP, &AlarmStatus))
    {
      /* Check the SMU Alarm status  */
      if ((AlarmStatus & SMU_VLTM_ALARMS) != 0U)
      {
        Result = VLTM_SMU_ALMSTSERR;
      }
    }
    else
    {
      Result = VLTM_SMU_GETALMSTSERR;
    }
    if(VLTM_NOTEXECUTED == Result)
    {
      /* Set the SMU alarms action as none for which the VltmTst is using 
                      (i.e. AG3[11, 12, 13, 14, 15, 16]   */ 
      SmuResult1 = Smu_SetAlarmAction(SMU_SCU_EVR_GRP,
                                      SMU_SCU_EVR_VDD_UV,
                                      SMU_ALARM_ACTION_NONE);

      SmuResult2 = Smu_SetAlarmAction(SMU_SCU_EVR_GRP,
                                      SMU_SCU_EVR_VDD_OV,
                                      SMU_ALARM_ACTION_NONE);

      SmuResult3 = Smu_SetAlarmAction(SMU_SCU_EVR_GRP,
                                      SMU_SCU_EVR_VDDP3_UV,
                                      SMU_ALARM_ACTION_NONE);

      SmuResult4 = Smu_SetAlarmAction(SMU_SCU_EVR_GRP,
                                      SMU_SCU_EVR_VDDP3_OV,
                                      SMU_ALARM_ACTION_NONE);
#if (VLTM_VEXT_MONITOR == TRUE)	
      SmuResult5 = Smu_SetAlarmAction(SMU_SCU_EVR_GRP,
                                      SMU_SCU_EVR_VEXT_UV,
                                      SMU_ALARM_ACTION_NONE);

      SmuResult6 = Smu_SetAlarmAction(SMU_SCU_EVR_GRP,
                                      SMU_SCU_EVR_VEXT_OV,
                                      SMU_ALARM_ACTION_NONE);
#endif
  
      /* Check the result of Smu_SetAlarmAction */     
#if (VLTM_VEXT_MONITOR == TRUE) 
      if((SmuResult1 != E_OK) || (SmuResult2 != E_OK) || (SmuResult3 != E_OK) ||
         (SmuResult4 != E_OK) || (SmuResult5 != E_OK) || (SmuResult6 != E_OK))
#else
      if((SmuResult1 != E_OK) || (SmuResult2 != E_OK) || (SmuResult3 != E_OK) ||
         (SmuResult4 != E_OK))
#endif      
      {
        Result = VLTM_SMU_SETALMACTIONERR;
      }
      else
      {
        Result = VLTM_SUCCESS;
      }
    }
  }
  return Result;

}

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static Sl_TstRsltType VltmTst_lRestore                  **
**                    (const VltmTst_BackupDataType * const Vltm_BackupData)  **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters (in)  : Vltm_BackupData - Pointer to VltmTst_BackupData_Type    **
**                    struct that holds the saved SFR value and SMU alarm     **
**                    action for the Voltage monitor system.                  **
**                                                                            **
** Parameters (out) : None.                                                   **
**                                                                            **
** Return value     : VLTM_SUCCESS - If Initialization succeeded.             **
**                    VLTM_SMU_SETALMACTIONERR - If Initialization failed     **
**                    because setting an SMU alarm action failed.             **
**                                                                            **
** Description      : This function Restores the SMU alarm actions and the    **
**                    changed SFRs for the voltage monitoring system.         **
*******************************************************************************/
static Sl_TstRsltType VltmTst_lRestore
(const VltmTst_BackupDataType * const Vltm_BackupData)
{
  Sl_TstRsltType  Result;
  Std_ReturnType  SmuResult1 = E_NOT_OK;
  Std_ReturnType  SmuResult2 = E_NOT_OK;
  Std_ReturnType  SmuResult3 = E_NOT_OK;
  Std_ReturnType  SmuResult4 = E_NOT_OK;
#if (VLTM_VEXT_MONITOR == TRUE)  
  Std_ReturnType  SmuResult5 = E_NOT_OK;
  Std_ReturnType  SmuResult6 = E_NOT_OK;
#endif

  /* Restore settings for over-voltage monitoring thresholds   */
  Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT); 
  SCU_EVROVMON.U = Vltm_BackupData->EvrOvMon_Backup;
  Mcal_SetSafetyENDINIT_Timed();  

  /* Restore settings for under-voltage monitoring thresholds  */ 
  Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);  
  SCU_EVRUVMON.U = Vltm_BackupData->EvrUvMon_Backup;
  Mcal_SetSafetyENDINIT_Timed();

  /* Restore settings for Monitor control register             */  
  Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT); 
  SCU_EVRMONCTRL.U = Vltm_BackupData->EvrMonCtrl_Backup;
  Mcal_SetSafetyENDINIT_Timed();
  
  /* Check the status of GetAlmActionResult which is updated in initialization */
  if(E_OK == Vltm_BackupData->GetAlmActionResult)
  {
    SmuResult1 = Smu_SetAlarmAction(SMU_SCU_EVR_GRP, 
                                    SMU_SCU_EVR_VDD_UV,
                                    Vltm_BackupData->AlmActionBackupVDD_UV);

    SmuResult2 = Smu_SetAlarmAction(SMU_SCU_EVR_GRP,
                                    SMU_SCU_EVR_VDD_OV,
                                    Vltm_BackupData->AlmActionBackupVDD_OV);

    SmuResult3 = Smu_SetAlarmAction(SMU_SCU_EVR_GRP,
                                    SMU_SCU_EVR_VDDP3_UV,
                                    Vltm_BackupData->AlmActionBackupVDDP3_UV);

    SmuResult4 = Smu_SetAlarmAction(SMU_SCU_EVR_GRP,
                                    SMU_SCU_EVR_VDDP3_OV,
                                    Vltm_BackupData->AlmActionBackupVDDP3_OV);
#if (VLTM_VEXT_MONITOR == TRUE)										

    SmuResult5 = Smu_SetAlarmAction(SMU_SCU_EVR_GRP,
                                    SMU_SCU_EVR_VEXT_UV,
                                    Vltm_BackupData->AlmActionBackupVEXT_UV);

    SmuResult6 = Smu_SetAlarmAction(SMU_SCU_EVR_GRP,
                                    SMU_SCU_EVR_VEXT_OV,
                                    Vltm_BackupData->AlmActionBackupVEXT_OV);
#endif
     /* Check the result of Smu_SetAlarmAction */     
#if (VLTM_VEXT_MONITOR == TRUE)   
    if((SmuResult1 != E_OK) || (SmuResult2 != E_OK) || (SmuResult3 != E_OK) ||
       (SmuResult4 != E_OK) || (SmuResult5 != E_OK) || (SmuResult6 != E_OK))
#else
    if((SmuResult1 != E_OK) || (SmuResult2 != E_OK) || (SmuResult3 != E_OK) ||
       (SmuResult4 != E_OK))
#endif
    {
      Result = VLTM_SMU_SETALMACTIONERR;
    }
    else
    {
      Result = VLTM_SUCCESS;
    }
  }
  else
  {
    Result = VLTM_SUCCESS;
  }
  return Result;
} 




/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static Sl_TstRsltType VltmTst_lClearSMUAlarms(void)     **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters (in) :  None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : VLTM_SUCCESS - Clearing of all generated SMU alarms     **
**                    are fine.                                               **
**                    VLTM_SMU_CLRALMSTSERR - Clearing of the SMU alarms      **
**                    failed.                                                 **
**                                                                            **
** Description      : This function clears all SMU alarms generated by this   **
**                    test.                                                   **
*******************************************************************************/
static Sl_TstRsltType VltmTst_lClearSMUAlarms(void)
{
  Sl_TstRsltType  Result;
  Std_ReturnType  SmuResult1 = E_NOT_OK;
  Std_ReturnType  SmuResult2 = E_NOT_OK;
  Std_ReturnType  SmuResult3 = E_NOT_OK;
  Std_ReturnType  SmuResult4 = E_NOT_OK;
#if (VLTM_VEXT_MONITOR == TRUE)  
  Std_ReturnType  SmuResult5 = E_NOT_OK;
  Std_ReturnType  SmuResult6 = E_NOT_OK;
#endif

  SmuResult1 = Smu_ClearAlarmStatus(SMU_SCU_EVR_GRP, SMU_SCU_EVR_VDD_UV);
  SmuResult2 = Smu_ClearAlarmStatus(SMU_SCU_EVR_GRP, SMU_SCU_EVR_VDD_OV);
  SmuResult3 = Smu_ClearAlarmStatus(SMU_SCU_EVR_GRP, SMU_SCU_EVR_VDDP3_UV);
  SmuResult4 = Smu_ClearAlarmStatus(SMU_SCU_EVR_GRP, SMU_SCU_EVR_VDDP3_OV);
#if (VLTM_VEXT_MONITOR == TRUE)
  SmuResult5 = Smu_ClearAlarmStatus(SMU_SCU_EVR_GRP, SMU_SCU_EVR_VEXT_UV);
  SmuResult6 = Smu_ClearAlarmStatus(SMU_SCU_EVR_GRP, SMU_SCU_EVR_VEXT_OV);
#endif
  
   /* Check the result of Smu_SetAlarmAction */     
#if (VLTM_VEXT_MONITOR == TRUE) 
  if ( (SmuResult1 != E_OK) || (SmuResult2 != E_OK) || (SmuResult3 != E_OK) ||
       (SmuResult4 != E_OK) || (SmuResult5 != E_OK) || (SmuResult6 != E_OK) )
#else
  if ( (SmuResult1 != E_OK) || (SmuResult2 != E_OK) || (SmuResult3 != E_OK) ||
       (SmuResult4 != E_OK) )
#endif
  {
    Result = VLTM_SMU_CLRALMSTSERR;
  }
  else
  {
    Result = VLTM_SUCCESS;
  }

  return Result;

}

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static Sl_TstRsltType VltmTst_lCheckUnderVoltage        **
**                                              (uint32* const TstSignature); **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters (in) :  TstSingature - Used for generating the Test signature   **
**                                                                            **
** Parameters (out) : TstSingature - Test signature generated by the test.    **
**                                                                            **
** Return value     : VLTM_SUCCESS - Test passed without any errors.          **
**                    VLTM_UNDER_VEXT - VEXT did not fire an under-voltage    **
**                    alarm although it was expected to.                      **
**                    VLTM_UNDER_VDDP3 - VDDP3 did not fire an under-voltage  **
**                    alarm although it was expected to.                      **
**                    VLTM_UNDER_VDD -  VDD did not fire an under-voltage     **
**                    alarm although it was expected to.                      **
**                    VLTM_SMU_GETALMACTIONERR - Test failed because getting  **
**                    the SMU alarm action failed.                            **
**                                                                            **
** Description      : This function Checks that the secondary voltage-        **
**                    monitoring system does detect and report under voltage  **
**                    conditions                                              **
*******************************************************************************/
static Sl_TstRsltType VltmTst_lCheckUnderVoltage
(
  uint32* const TstSignature
)
{
  Sl_TstRsltType  Result = VLTM_NOTEXECUTED;
  uint32  Timeout = 0U;
  boolean EndLoop = FALSE;
  Std_ReturnType  SmuResult = E_OK;
  uint32  AlarmStatus = 0U;

  Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT); 
  /* Setting the under voltage threshold to 0x80 to generate a falling edge 
     monitoring in case the external voltage is 3.3V  */
  SCU_EVRUVMON.B.SWDUVVAL = VLTM_SWDUVVAL_VEXT3V3;
  Mcal_SetSafetyENDINIT_Timed();
  
  /* Set secondary voltage monitoring thresholds to check for a higher        
     voltage than the actual one This will lead to an under-voltage alarm.  */
  Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);      
  SCU_EVRUVMON.U = VLTM_EVRMON_MAX;
  Mcal_SetSafetyENDINIT_Timed();
  
  Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);   
  SCU_EVROVMON.U = VLTM_EVRMON_MAX;
  Mcal_SetSafetyENDINIT_Timed();

  /* Set the Timeout value  and wait for the under-voltage alarm to set */
  Timeout = VLTMTST_TIMEOUT;

  while (Timeout > 0U)
  {
    SmuResult = Smu_GetAlarmStatus(SMU_SCU_EVR_GRP, &AlarmStatus);
    /* Check the return value of Smu_GetAlarmStatus() */
    if (E_OK != SmuResult)
    {
      Result = VLTM_SMU_GETALMACTIONERR;
      EndLoop = TRUE;
      Timeout = 0U;
    }
    else
    {
      /* Check for All Under-voltage alarms */
      if ((AlarmStatus & SMU_VLTM_UV_ALARMS) != SMU_VLTM_UV_ALARMS)
      {
        /* Wait for the under-voltage alarm signals to the SMU   */
        Timeout = Timeout - 1U;
      }
      else
      {
        EndLoop = TRUE;
        Timeout = 0U;
        Result = VLTM_SUCCESS;
      }
    }
  }
  if (EndLoop != TRUE)
  {
    #if (VLTM_VEXT_MONITOR == TRUE)
    /* Check the alarm of Under-voltage alarm  */
    if ((AlarmStatus & SMU_SCU_EVR_VEXT_UV_STS) == 0U)
    {
      Result = VLTM_UNDER_VEXT;
    }
    else
    #endif
    if ((AlarmStatus & SMU_SCU_EVR_VDDP3_UV_STS) == 0U)
    {
      Result = VLTM_UNDER_VDDP3;
    }
    /* Check the alarm of Under-voltage alarm  */
    else if ((AlarmStatus & SMU_SCU_EVR_VDD_UV_STS) == 0U)
    {
      Result = VLTM_UNDER_VDD;
    }
    else
    {
      /* None */
    }
  }
  *TstSignature = (uint32)(CRC32(*TstSignature, 
                                  (AlarmStatus & SMU_VLTM_UV_ALARMS)));

  return Result;
}

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static Sl_TstRsltType VltmTst_lCheckOverVoltage         **
**                                             (uint32* const TstSignature);  **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters (in) :  TstSingature - Used for generating the Test signature   **
**                                                                            **
** Parameters (out) : TstSingature - Test signature generated by the test     **
**                                                                            **
** Return value     : VLTM_SUCCESS - Test passed without any errors           **
**                    VLTM_OVER_VEXT - VEXT did not fire an over-voltage      **
**                    alarm although it was expected to.                      **
**                    VLTM_OVER_VDDP3 - VDDP3 did not fire an over-voltage    **
**                    alarm although it was expected to.                      **
**                    VLTM_OVER_VDD -  VDD did not fire an over-voltage       **
**                    alarm although it was expected to.                      **
**                    VLTM_SMU_GETALMACTIONERR - Test failed because getting  **
**                    the SMU alarm action failed.                            **
**                                                                            **
** Description      : This function Checks that the secondary voltage-        **
**                    monitoring system does detect and report over voltage   **
**                    conditions.                                             **
*******************************************************************************/
static Sl_TstRsltType VltmTst_lCheckOverVoltage
(
  uint32* const TstSignature
)
{
  Sl_TstRsltType  Result = VLTM_NOTEXECUTED;
  uint32  Timeout = 0U;
  boolean EndLoop = FALSE;
  Std_ReturnType  SmuResult = E_OK;
  uint32  AlarmStatus = 0U;

  /* Set secondary voltage monitoring thresholds to check for a lower 
         voltage than the actual one. This will lead to an over-voltage alarm.*/   
  Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);  
  SCU_EVRUVMON.U = VLTM_EVRMON_MIN;
  Mcal_SetSafetyENDINIT_Timed();
  
  Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);   
  SCU_EVROVMON.U = VLTM_EVRMON_MIN;
  Mcal_SetSafetyENDINIT_Timed();

  /* Set the Timeout value  and wait for the over-voltage alarm to set */
  Timeout = VLTMTST_TIMEOUT;

  while (Timeout > 0U)
  {
    SmuResult = Smu_GetAlarmStatus(SMU_SCU_EVR_GRP, &AlarmStatus);
    if (E_OK != SmuResult)
    {
      Result = VLTM_SMU_GETALMACTIONERR;
      Timeout = 0U;
      EndLoop = TRUE;
    }
    else
    {
      /* Check for All Over-voltage alarms */
      if ((AlarmStatus & SMU_VLTM_OV_ALARMS) != SMU_VLTM_OV_ALARMS)
      {
        /* Wait for the under-voltage alarm signals to the SMU     */
        Timeout = Timeout - 1U;
      }
      else
      {
        EndLoop = TRUE;
        Timeout = 0U;
        Result = VLTM_SUCCESS;
      }
    }
  }
  if (EndLoop != TRUE)
  {
    #if (VLTM_VEXT_MONITOR == TRUE)
    /* Check the alarm of Over-voltage alarm  */
    if ((AlarmStatus & SMU_SCU_EVR_VEXT_OV_STS) == 0U)
    {
      Result = VLTM_OVER_VEXT;
    }
    else
    #endif
    if ((AlarmStatus & SMU_SCU_EVR_VDDP3_OV_STS) == 0U)
    {
      Result = VLTM_OVER_VDDP3;
    }
    /* Check the alarm of Over-voltage alarm (i.e. AG3[12] ) */
    else if ((AlarmStatus & SMU_SCU_EVR_VDD_OV_STS) == 0U)
    {
      Result = VLTM_OVER_VDD;
    }
    else
    {
      /* None */
    }
  }
  *TstSignature = (uint32)(CRC32(*TstSignature, 
                                  (AlarmStatus & SMU_VLTM_OV_ALARMS)));


  return Result;
}

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : Sl_TstRsltType VltmTst_VltmTst                          **
**                    (const Sl_ParamSetType ParamSetIndex,                   **
**                     const uint8 TstSeed,                                   **
**                     uint32* const TstSignature)                            **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters (in) :  ParamSetIndex - Identifies the parameter set to be      **
**                    used for test execution.                                **
**                    Note: This parameter is ignored because no configuration**
**                    is required for this test. It is only defined for       **
**                    reasons of compatibility with APIs of other MTL tests.  **
**                    TstSeed : Seed to be used for generating the signature  **
**                                                                            **
** Parameters (out) : TstSingature - Test signature generated by the test     **
**                                                                            **
** Return value     : VLTM_SUCCESS - Test succeeded.                          **
**                    VLTM_SMU_STATEERR - The test cannot be executed because **
**                    the SMU is in the wrong state.                          **
**                    VLTM_SMU_GETALMSTSERR - Test failed because getting     **
**                    the SMU alarm status failed.                            **
**                    VLTM_SMU_CLRALMSTSERR - The test failed because         **
**                    clearing the SMU alarm failed.                          **
**                    VLTM_ SMU_ALMSTSERR - Test failed because there is      **
**                    already a voltage monitor SMU error present.            **
**                    VLTM_SMU_SETALMACTIONERR - Test failed because setting  **
**                    the SMU alarm action failed.                            **
**                    VLTM_SMU_GETALMACTIONERR - Test failed because getting  **
**                    the SMU alarm action failed.                            **
**                    VLTM_OVER_VEXT - VEXT module did not report an over-    **
**                    voltage failure though it was expected to.              **
**                    VLTM_OVER_VDDP3 - VDDP3 module did not report an over-  **
**                    voltage failure though it was expected to.              **
**                    VLTM_OVER_VDD - VDD module did not report an over-      **
**                    voltage failure though it was expected to.              **
**                    VLTM_UNDER_VEXT - VEXT module did not report an under-  **
**                    voltage failure though it was expected to.              **
**                    VLTM_UNDER_VDDP3 - VDDP3 module did not report an under-**
**                    voltage though it was expected to.                      **
**                    VLTM_UNDER_VDD - VDD module did not report an under-    **
**                    voltage though it was expected to.                      **
**                    VLTM_EVRREG_LOCKED - When the EVR registers             **
**                    are locked.                                             **
**                    VLTM_BGPROK_ERROR - When the primary bandgap-           **
**                    status not o.k                                          **
**                                                                            **
** Description      : This function checks the SFRs for unintended            **
**                    configuration changes.                                   **
*******************************************************************************/
Sl_TstRsltType VltmTst_VltmTst 
(
  const Sl_ParamSetType ParamSetIndex,
  const uint8 TstSeed,
  uint32* const TstSignature
)
{
  Sl_TstRsltType  Result;
  Sl_TstRsltType  ResClrSmuAlm = 0U;
  Sl_TstRsltType  ResRestore;
  VltmTst_BackupDataType  Vltm_BackupData;
  #if (CHIP_ID != 26U)
  uint32 EvrMonCtrl = 0U;
  #endif
  uint32 EvruvMon = (uint32)SCU_EVRUVMON.B.LCK;
  uint32 EvrovMon = (uint32)SCU_EVROVMON.B.LCK;  

  UNUSED_PARAMETER(ParamSetIndex)
  
  /* Initialize Test Signature:   */
  *TstSignature = (uint32)CRC32(TEST_ID_VLTM_TST, TstSeed);

  /* Check if the SMU is in RUN state. Otherwise report failure  */
  if (SMU_RUN_STATE == Smu_GetSmuState())
  {
    /* Check for the lock state of EVR register */
    #if (CHIP_ID != 26U)
    EvrMonCtrl = (uint32)
    ((SCU_EVRMONCTRL.U & VLTM_EVRMONCTRL_SLCK) >> IFX_SCU_EVRMONCTRL_SLCK_OFF);

    if( (EvrMonCtrl == 1U)
       || (EvruvMon == 1U)
       || (EvrovMon == 1U) )
    #else
    if( (EvruvMon == 1U) || (EvrovMon == 1U) )
    #endif
    {
      Result = VLTM_EVRREG_LOCKED; 
    }
    /* Check for Primary Band gap status */
    else if(SCU_EVRSTAT.B.BGPROK == 0U)
    {
      Result = VLTM_BGPROK_ERROR;
    }
    else
    {
      /* Test initialization:   */
      Result = VltmTst_lInit(&Vltm_BackupData);
  
      if (Result == VLTM_SUCCESS)
      {
        /* Check Under Voltage     */
        Result = VltmTst_lCheckUnderVoltage(TstSignature);
        if (Result == VLTM_SUCCESS)
        {
          /* Check Over Voltage    */
          Result = VltmTst_lCheckOverVoltage(TstSignature);
        }    
        /* Clear SMU Alarms    */
        ResClrSmuAlm = VltmTst_lClearSMUAlarms();
      }
  
      /* Restore SMU Alarms Action and SFR   */
      ResRestore = VltmTst_lRestore(&Vltm_BackupData);
  
      if(Result == VLTM_SUCCESS)
      {
        /* Check for Clear SMU Alarms */
        if(ResClrSmuAlm != VLTM_SUCCESS)
        {
          Result = ResClrSmuAlm;
        }
        else
        {
          Result = ResRestore;
        }
      }
    }
  }
  else
  {
    Result = VLTM_SMU_STATEERR;
  }

  *TstSignature = (uint32)(CRC32(*TstSignature, Result));
  return Result;
}

#define IFX_VLTM_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
