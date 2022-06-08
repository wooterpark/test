/*******************************************************************************
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
**   $FILENAME   : Smu.c $                                                    **
**                                                                            **
**   $CC VERSION : \main\61 $                                                 **
**                                                                            **
**   $DATE       : 2018-02-22 $                                               **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon AURIX                                                **
**                                                                            **
**  COMPILER  : Tasking                                                       **
**                                                                            **
**  AUTHOR    : SafeTlib Team                                                 **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  TRACEABILITY:                                                             **
**                                                                            **
**  DESCRIPTION  : This file contains                                         **
**                 - functionality of SMU Driver                              **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [Yes/No]: No                                       **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Mcal.h"
#include "IfxSmu_bf.h"
#include "IfxSmu_reg.h"
#include "Sl_Ipc.h"
#include "SmuInt.h"
#include "Sl_Timeout.h"

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
/* Driver initialization flag */
#define SMU_INITIALIZED      ((uint8)1)
#define SMU_NOT_INITIALIZED  ((uint8)0)

/* Error Pin  initialization flag */
#define SMU_ERRPIN_SET       ((uint8)1)
#define SMU_ERRPIN_NOTSET    ((uint8)0)

/* SMU Driver status */
#define SMU_FAILED           ((uint8)1)
#define SMU_NOT_FAILED       ((uint8)0)

/* SMU Configuration registers lock flag */
#define SMU_LOCKED           ((uint8)1)
#define SMU_NOT_LOCKED       ((uint8)0)

/* SMU maximum alarms to validate API input parameters */
#define SMU_MAX_ALARM_GROUP  (6U)
#define SMU_MAX_ALARM_POS    (31U)

/* SMU SW alarm to validate API input parameter */
#define SMU_SW_ALARM_GROUP   (5U)
#define SMU_SW_ALARM_MAX_POS (15U)

/* SMU Command Argument bit position in the CMD register */
#define SMU_CMD_ARG_BIT_POS  (4U)

/* SMU maximum recovery timers */
#define SMU_MAX_RECOV_TIM    (0x2U)

/* SMU configuration - permanent lock value on and cfg(temp) lock on*/
#define SMU_CFG_PERLCK_ON_CFGLCK_ON  (0x0000FF00U)

/* SMU configuration - permanent lock value off and cfg(temp) lock off*/
#define SMU_CFG_PERLCK_OFF_CFGLCK_OFF  (0x000000BCU)

#define SMU_CFG_PERLCK_VALUE (0xFFU)

/* SMU configuration unlock lock value */
#define SMU_CFG_KEY_UNLOCK  ((SMU_KEYS.U & (unsigned_int)(0xFFFFFF00U)) | \
                              ((unsigned_int)0xBCU) \
                             )

#define SMU_CFG_KEY_TEMPLOCK (0U)

/* Status of SMU CMD esecution sucess value in SMU_STS.B.RES bit*/
#define SMU_COMMAND_SUCESS  (0U)

/* Expected value on checking the integrity of global variable with its backup*/
#define UINT8_MAX            ((uint8)0xFFU)

/* Mapping starting location of register set(SMU_AlarmGroupRegMapType)
 * - Alarm group registers.
 */
#define SMU_ALARM_GROUP     ((volatile SMU_AlarmGroupRegMapType *)(volatile void *)(&SMU_AGCF0_0))

/* The mask for the Alarm group configuration from 3 bit value for
 * each CFG registers
 */
#define SMU_ALMGRP_CFG0_MASK (0x1U)
#define SMU_ALMGRP_CFG1_MASK (0x2U)
#define SMU_ALMGRP_CFG2_MASK (0x4U)

/* SMU registers  Reset values */
#define SMU_FSP_RESET_VAL       (0x003FFF00U)

#define SMU_AGC_RESET_VAL       (0x0U)

#define SMU_RTC_RESET_VAL       (0x003FFF01U)

#define SMU_RTAC0_RESET_VAL     (0xA39B938BU)

#define SMU_RTAC1_RESET_VAL     (0x0U)

#define SMU_ALARM_CFG_RESET_VAL (0x0U)

#define SMU_AG2CF1_AG2CF2_RESET_VAL  (0x20000000U)

#define SMU_AG3CF0_AG3CF2_RESET_VAL  (0x001E0000U)

#define SMU_ALARM_FSP_RESET_VAL (0x0U)

#define SMU_AG2FSP_RESET_VAL  (0x20000000U)

/* Mask for SMU permanent lock */
#define SMU_KEY_PERLOCK_MASK    (0xFF00U)

#define SMU_AG_SET_ALL          (0xFFFFFFFFU)

/* Mask for extracting the FSP action from Register after shift */
#define SMU_ALARM_FSP_MASK      ((uint8)0x1U)

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
#if (IFX_SAFETLIB_USED == STD_ON)
#define IFX_SMU_START_SEC_VAR_NONZERO_INIT_8BIT_ASIL_B
#include "Ifx_MemMap.h"
#else
#define SMU_START_SEC_VAR_INIT_8BIT
#include "MemMap.h"
#endif
/* Driver Init status global variable */
static uint8 Smu_InitStatus = SMU_NOT_INITIALIZED;
#if (IFX_SAFETLIB_USED == STD_ON)
#define IFX_SMU_STOP_SEC_VAR_NONZERO_INIT_8BIT_ASIL_B
#include "Ifx_MemMap.h"
#else
#define SMU_STOP_SEC_VAR_INIT_8BIT
#include "MemMap.h"
#endif

#if (IFX_SAFETLIB_USED == STD_ON)
#define IFX_SMU_START_SEC_BACKUPVAR_NONZERO_INIT_8BIT_ASIL_B
#include "Ifx_MemMap.h"
#else
#define SMU_START_SEC_BACKUP_VAR_INIT_8BIT
#include "MemMap.h"
#endif
/* Driver Init status global variable backup */
static uint8 Smu_InitStatusBackup = (uint8)(~(SMU_NOT_INITIALIZED));
#if (IFX_SAFETLIB_USED == STD_ON)
#define IFX_SMU_STOP_SEC_BACKUPVAR_NONZERO_INIT_8BIT_ASIL_B
#include "Ifx_MemMap.h"
#else
#define SMU_STOP_SEC_BACKUP_VAR_INIT_8BIT
#include "MemMap.h"
#endif

#if (IFX_SAFETLIB_USED == STD_ON)
#define IFX_SMU_START_SEC_VAR_8BIT_ASIL_B
#include "Ifx_MemMap.h"
#else
#define SMU_START_SEC_VAR_8BIT
#include "MemMap.h"
#endif
/* SMU Error Pin status global variable*/
static uint8 Smu_ErrPinStatus;

/* Driver state global variable */
static uint8 Smu_DriverState;

/* SMU config registers lock status global variable */
static uint8 Smu_LockState;
#if (IFX_SAFETLIB_USED == STD_ON)
#define IFX_SMU_STOP_SEC_VAR_8BIT_ASIL_B
#include "Ifx_MemMap.h"
#else
#define SMU_STOP_SEC_VAR_8BIT
#include "MemMap.h"
#endif


#if (IFX_SAFETLIB_USED == STD_ON)
#define IFX_SMU_START_SEC_BACKUPVAR_8BIT_ASIL_B
#include "Ifx_MemMap.h"
#else
#define SMU_START_SEC_BACKUP_VAR_8BIT
#include "MemMap.h"
#endif
/* SMU Error Pin status global variable backup */
static uint8 Smu_ErrPinStatusBackup;

/* Driver state global variable backup */
static uint8 Smu_DriverStateBackup;

/* SMU config registers lock status global variable backup */
static uint8 Smu_LockStateBackup;
#if (IFX_SAFETLIB_USED == STD_ON)
#define IFX_SMU_STOP_SEC_BACKUPVAR_8BIT_ASIL_B
#include "Ifx_MemMap.h"
#else
#define SMU_STOP_SEC_BACKUP_VAR_8BIT
#include "MemMap.h"
#endif
/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

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

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
#if (IFX_SAFETLIB_USED == STD_ON)
#define IFX_SMU_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
#else
#define SMU_START_SEC_CODE
#include "MemMap.h"
#endif
/* Local function - to set the driver initialization status */
static void Smu_lSetSmuInitStatus(const uint8 InitStatus);
/* Local function - to get the driver initialization status */
static Std_ReturnType Smu_lGetSmuInitStatus(void);
/* Local function - to check the driver initialization status */
static Std_ReturnType Smu_lChkSmuInitState(void);

/* Local function - to set the SMU Error pin initialization status */
static void Smu_lSetErrPinStatus(const uint8 ErrPinStatus);
/* Local function - to get the SMU Error pin initialization status */
static Std_ReturnType Smu_lGetErrPinStatus(void);

/* Local function - to set the Driver fail / not-fail state */
static void Smu_lSetSmuDriverState(const uint8 DriverState);
/* Local function - to get the Driver fail / not-fail state */
static Std_ReturnType Smu_lGetSmuDriverState(void);
/* Local function - to check the Driver fail state */
static Std_ReturnType Smu_lChkSmuDriverState(void);

/* Local function - to set the SMU configuration register lock state */
static void Smu_lSetSmuLockState(const uint8 LockState);
/* Local function - to get the SMU configuration register lock state */
static Std_ReturnType Smu_lGetSmuLockState(void);
/* Local function - to check the SMU configuration register lock state */
static Std_ReturnType Smu_lChkSmuLockState(void);
/* Local function - to clear all SMU alarms on initialization */
static Std_ReturnType Smu_lClearAllAlarms(void);


/*******************************************************************************
**                       Private Function Definitions                         **
*******************************************************************************/

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           :static void Smu_lSetSmuInitStatus(const uint8 InitStatus)**
**                                                                            **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters(in)   : InitStatus - Status of the SMU Driver initialization    **
**                                 to set in global variable                  **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function is called in Initialization and           **
**                    De-Initialization API of the SMU.                       **
**                    This function sets the status in global variable        **
**                    of Smu_InitStatus.                                      **
*******************************************************************************/
static void Smu_lSetSmuInitStatus(const uint8 InitStatus)
{

  Smu_InitStatus = InitStatus;

  Smu_InitStatusBackup = ~(InitStatus);

}/* Smu_SetSmuInitStatus */

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static Std_ReturnType Smu_lGetSmuInitStatus(void)       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : E_OK - On successful read                               **
**                    E_NOT_OK - On read failure                              **
**                                                                            **
** Description      : This function is called to check the Smu_InitStatus     **
**                    value in Initialization API and Smu_lChkSmuInitState    **
**                    function of the SMU.                                    **
*******************************************************************************/
static Std_ReturnType Smu_lGetSmuInitStatus(void)
{
  Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;

  if((Smu_InitStatus ^ Smu_InitStatusBackup) == UINT8_MAX)
  {
    RetVal = (Std_ReturnType)E_OK;
  }

  return RetVal;

}/* Smu_GetSmuInitStatus */

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static Std_ReturnType Smu_lChkSmuInitState(void)        **
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
** Return value     : E_OK - If SMU is initialized                            **
**                    E_NOT_OK - If SMU is not initalized                     **
**                                                                            **
** Description      : This function checks the Smu_InitState.                 **
*******************************************************************************/
static Std_ReturnType Smu_lChkSmuInitState(void)
{
  Std_ReturnType RetVal;
  uint8 InitState;

  RetVal = Smu_lGetSmuInitStatus();

  if(RetVal == (Std_ReturnType)E_OK)
  {
    InitState = Smu_InitStatus;
    if(InitState == SMU_NOT_INITIALIZED)
    {
      RetVal = (Std_ReturnType)E_NOT_OK;
    }
  }
  else
  {
    RetVal = (Std_ReturnType)E_NOT_OK;
  }

  return RetVal;
}/* Smu_lChkSmuInitState */

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static void Smu_lSetErrPinStatus                        **
**                                              (const uint8 ErrPinStatus)    **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters(in)   : ErrPinStatus - Status of the Error pin setup            **
**                                 to set in global variable                  **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function is called in Initialization and           **
**                    De-Initialization APIs for re-setting the               **
**                    Smu_ErrPinStatus variable and its backup to             **
**                    SMU_ERRPIN_NOTSET.                                      **
**                    It is called in Smu_SetupErrorPin() API for setting     **
**                    setting the Smu_ErrPinStatus variable and its backup to **
**                   SMU_ERRPIN_SET on successful set of Error pin by the API.**
**                                                                            **
*******************************************************************************/
static void Smu_lSetErrPinStatus(const uint8 ErrPinStatus)
{

  Smu_ErrPinStatus = ErrPinStatus;

  Smu_ErrPinStatusBackup = ~(ErrPinStatus);

}/* Smu_lSetErrPinStatus */

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static Std_ReturnType Smu_lGetErrPinStatus              **
**                         (void)                                             **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : E_OK - On successful read                               **
**                    E_NOT_OK - On read failure                              **
**                                                                            **
** Description      : This function executes in Smu_SetupErrorPin function    **
**                    for checking if SMU Error Pin  is already set or not.   **
*******************************************************************************/
static Std_ReturnType Smu_lGetErrPinStatus(void)
{
  Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;

  if((Smu_ErrPinStatus ^ Smu_ErrPinStatusBackup) == UINT8_MAX)
  {
    RetVal = (Std_ReturnType)E_OK;
  }

  return RetVal;

}/* Smu_lGetErrPinStatus */



/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static void Smu_lSetSmuDriverState                      **
**                                                (const uint8 DriverState)   **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters(in)   : DriverState - Status of the SMU Driver state            **
**                                 to set in global variable                  **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function is called in Initialization ,             **
**                    De-Initialization APIs to reset the Smu_DriverState     **
**                    variable and its backup to SMU_NOT_FAILED.              **
**                    It is called in ActivateRunState API to set the         **
**                    Smu_DriverState variable and its backup to SMU_FAILED on**
**                    invalid input parameter 'Cmd'.                          **
**                                                                            **
*******************************************************************************/
static void Smu_lSetSmuDriverState(const uint8 DriverState)
{

  Smu_DriverState = DriverState;

  Smu_DriverStateBackup = ~(DriverState);

}/* Smu_lSetSmuDriverState */

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static Std_ReturnType Smu_lGetSmuDriverState            **
**                          (void)                                            **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : E_OK - On successful read                               **
**                    E_NOT_OK - On read failure                              **
**                                                                            **
** Description      : This function called in Smu_lChkSmuDriverState function **
**                    for reading the Smu_DriverState..                       **
*******************************************************************************/
static Std_ReturnType Smu_lGetSmuDriverState(void)
{
  Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;

  if((Smu_DriverState ^ Smu_DriverStateBackup) == UINT8_MAX)
  {
    RetVal = (Std_ReturnType)E_OK;
  }

  return RetVal;

}/* Smu_lGetSmuDriverState */

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static Std_ReturnType Smu_lChkSmuDriverState(void)      **
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
** Return value     : E_OK - If Driver state is SMU_NOT_FAILED                **
**                    E_NOT_OK - If Driver state is SMU_FAILED                **
**                                                                            **
** Description      : It checks the Smu_DriverState.                          **
*******************************************************************************/
static Std_ReturnType Smu_lChkSmuDriverState(void)
{
  Std_ReturnType RetVal;
  uint8 DriverState;

  RetVal = Smu_lGetSmuDriverState();
  if(RetVal == (Std_ReturnType)E_OK)
  {
    DriverState = Smu_DriverState;
    if(DriverState == SMU_FAILED)
    {
      RetVal = (Std_ReturnType)E_NOT_OK;
    }
  }
  else
  {
    RetVal = (Std_ReturnType)E_NOT_OK;
  }

  return RetVal;
}

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static void Smu_lSetSmuLockState(const uint8 LockState) **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters(in)   : LockState - Status of the SMU Configuration Reg lock    **
**                                 to set in global variable                  **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function is called in Initialization,              **
**                    De-Initialization APIs to reset the Smu_LockState and   **
**                    its backup variables to SMU_NOT_LOCKED.                 **
**                    It is called in Smu_LockConfigRegs() API to set the     **
**                    Smu_LockState and its backup variables to SMU_LOCKED on **
**                    successful execution of the API.                        **
*******************************************************************************/
static void Smu_lSetSmuLockState(const uint8 LockState)
{

  Smu_LockState = LockState;

  Smu_LockStateBackup = ~(LockState);

}/* Smu_lSetSmuLockState */

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static Std_ReturnType Smu_lGetSmuLockState              **
**                          (void)                                            **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : E_OK - On successful read                               **
**                    E_NOT_OK - On read failure                              **
**                                                                            **
** Description      : This function called in Smu_lChkSmuLockState function   **
**                    for reading the Smu_LockState.                          **
*******************************************************************************/
static Std_ReturnType Smu_lGetSmuLockState(void)
{
  Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;

  if((Smu_LockState ^ Smu_LockStateBackup) == UINT8_MAX)
  {
    RetVal = (Std_ReturnType)E_OK;
  }

  return RetVal;

}/* Smu_lGetSmuLockState */

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static Std_ReturnType Smu_lChkSmuLockState(void)        **
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
** Return value     : E_OK - If SMU Cfg reg is not Locked                     **
**                    E_NOT_OK - If SMU Cfg reg is Locked                     **
**                                                                            **
** Description      : This function checks the Smu_LockState.                 **
*******************************************************************************/
static Std_ReturnType Smu_lChkSmuLockState(void)
{
  Std_ReturnType RetVal;
  uint8 LockState;

  RetVal = Smu_lGetSmuLockState();

  if(RetVal == (Std_ReturnType)E_OK)
  {
    LockState = Smu_LockState;
    if(LockState == SMU_LOCKED)
    {
      RetVal = (Std_ReturnType)E_NOT_OK;
    }
  }
  else
  {
    RetVal = (Std_ReturnType)E_NOT_OK;
  }

  return RetVal;
}

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : Std_ReturnType Smu_lClearAllAlarms(void)                **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : E_OK - Operation successfully performed                 **
**                    E_NOT_OK - Operation failed                             **
**                                                                            **
** Description      : The purpose of the function is to clear all the         **
**                    SMU Alarms                                              **
*******************************************************************************/
Std_ReturnType Smu_lClearAllAlarms(void)
{
  Std_ReturnType RetVal;
  uint32 AlarmGroupIndex;

  RetVal = E_OK;

  /* SMU alarm can be cleared in any state */
  /* All SMU Groups (0 to 6) are cleared alarm status */
  /* NOTE: Some of the AlarmPos in some AlarmGroup are reserved i.e.
         not valid even if its with in the maximum range.
         Action on these alarms has no effect on the hardware.
  */
  AlarmGroupIndex = SMU_ALARM_GROUP0;
  do
  {
    /* Call spin lock for SMU Driver usage */
    if(E_OK == Sl_GetSpinLock(SL_SMUDRIVER_SPNLCK_ID, SMU_SPINLOCK_TIMEOUT))
    {

      /* Write SMU_ASCE(0) in CMD register */
      SMU_CMD.U = SMU_ASCE_COMMAND;

      /* disable the write-protection for registers */
      Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);

      /* Write 1 in AG bit to clear alarm */
      SMU_ALARM_GROUP->AGStatusReg[AlarmGroupIndex].U =
                            (unsigned_int)SMU_AG_SET_ALL;

      /* Restore back the write-protection for registers */
      Mcal_SetSafetyENDINIT_Timed();

      Sl_ReleaseSpinLock(SL_SMUDRIVER_SPNLCK_ID);
    }
    else
    {
      RetVal = E_NOT_OK;/*SMU_RESOURCE_TIMEOUT_ERROR;*/
    }

    AlarmGroupIndex++;
  }while((AlarmGroupIndex <= SMU_MAX_ALARM_GROUP) &&
                     (RetVal == E_OK));

  return RetVal;

}/* Smu_lClearAllAlarms */

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : Std_ReturnType Smu_Init(Smu_ConfigType* ConfigPtr)      **
**                                                                            **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters(in)   : ConfigPtr - Pointer to the SMU configuration for        **
**                                  initialization                            **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : E_OK - Operation successfully performed                 **
**                    E_NOT_OK - Operation failed eg. Driver already          **
**                      initialized.                                          **
**                                                                            **
** Description      : The purpose of the API is to setup the SMU peripheral   **
**                      based on configuration.The SMU Driver shall initialize**
**                      the resources of the AURIX SMU peripheral,            **
**                      e.g. regarding the error reaction and the Fault       **
**                      Signaling Protocol(FSP). All possible internal and    **
**                      external reaction mechanisms supported by SMU hardware**
**                      shall be configurable.                                **
*******************************************************************************/
Std_ReturnType Smu_Init
(
  const Smu_ConfigType* const ConfigPtr
)
{
  Std_ReturnType RetVal;
  uint32 Index;
  uint8 InitStatus;

  RetVal = (Std_ReturnType)E_NOT_OK;

  /* Check if SMU driver is already initialized */
  if(Smu_lGetSmuInitStatus() == (Std_ReturnType)E_OK)
  {
    InitStatus = Smu_InitStatus;
    if(InitStatus == SMU_INITIALIZED)
    {
      RetVal = (Std_ReturnType)E_NOT_OK;
    }
    /* Check for input parameter */
    else if( ConfigPtr == NULL_PTR)
    {
      RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
      RetVal = (Std_ReturnType)E_OK;
    }
  }

  /* Initialize SMU Driver if no error */
  if(RetVal == (Std_ReturnType)E_OK)
  {
    /* disable the write-protection for registers */
    Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);

    /*Write Config key to configure the SMU registers. */
    SMU_KEYS.U = (unsigned_int)SMU_CFG_KEY_UNLOCK;

    /* Configure SMU module register as per the requested configuration */
    SMU_FSP.U = ConfigPtr->FSPCfg;

    SMU_AGC.U = ConfigPtr->AGCCfg;

    SMU_RTC.U = ConfigPtr->RTCCfg;

    SMU_RTAC0.U = ConfigPtr->RTAC0Cfg;

    SMU_RTAC1.U = ConfigPtr->RTAC1Cfg;

    for(Index = 0U; Index < SMU_TOTAL_ALARM_CONFIG_REG; Index++)
    {
        SMU_ALARM_GROUP->CfgReg[Index].U = ConfigPtr->AlarmConfig[Index];
    }

    for(Index = 0U; Index < SMU_TOTAL_ALARM_GROUPS; Index++)
    {
        SMU_ALARM_GROUP->FSPCfgReg[Index].U = ConfigPtr->AlarmFspConfig[Index];
    }

    /* After configuration set temporary lock of SMU configuration */
    SMU_KEYS.U = (unsigned_int)SMU_CFG_KEY_TEMPLOCK;

    /* Restore back the write-protection for registers */
    Mcal_SetSafetyENDINIT_Timed();

    /* Clear all SMU Alarms */
    /* Rational: In case an application or system reset(not PORST) is issued,
       the SMU alarm bits are not cleared.
    */
    RetVal = Smu_lClearAllAlarms();

    /* Initialize all global variables and its backup variables */
    Smu_lSetErrPinStatus(SMU_ERRPIN_NOTSET);

    Smu_lSetSmuDriverState(SMU_NOT_FAILED);

    Smu_lSetSmuLockState(SMU_NOT_LOCKED);

    if(RetVal == (Std_ReturnType)E_OK)
    {

      /* Set SMU Driver init status to SMU_INITIALIZED */
      Smu_lSetSmuInitStatus(SMU_INITIALIZED);
    }

  }

  return RetVal;

}/* Smu_Init */

/*******************************************************************************
** Traceability      : [cover parentID=]       [/cover]                       **
**                                                                            **
** Syntax           : Std_ReturnType Smu_DeInit()                             **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : E_OK - Operation successfully performed                 **
**                    E_NOT_OK - Operation failed eg. Driver already          **
**                      reset.                                                **
**                                                                            **
** Description      : De-initialise the SMU module by performing module reset **
**                      (SMU_KRSTx regs) and clearing SMU variables. It shall **
**                      be possible to initialise SMU with a different pre-run**
**                      config, runtime config. Hence the deinitialisation    **
**                      functionality is required                             **
**                                                                            **
*******************************************************************************/
Std_ReturnType Smu_DeInit(void)
{
  Std_ReturnType RetVal;
  uint32 Index;

  /* Check if Driver state is not FAIL */
  RetVal = Smu_lChkSmuDriverState();

  if(RetVal == (Std_ReturnType)E_OK)
  {
    /* Check for Driver init state */
    RetVal = Smu_lChkSmuInitState();
  }

  if(RetVal == (Std_ReturnType)E_OK)
  {
    /* disable the write-protection for registers */
    Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);

    /*Write Config key to configure the SMU registers. */
     SMU_KEYS.U = (unsigned_int)SMU_CFG_KEY_UNLOCK;

     /* Configure SMU module register as per the requested configuration */
     SMU_FSP.U = SMU_FSP_RESET_VAL;

     SMU_AGC.U = SMU_AGC_RESET_VAL;

     SMU_RTC.U = SMU_RTC_RESET_VAL;

     SMU_RTAC0.U = SMU_RTAC0_RESET_VAL;

     SMU_RTAC1.U = SMU_RTAC1_RESET_VAL;

     for(Index = 0U; Index < SMU_TOTAL_ALARM_CONFIG_REG; Index++)
     {
	 
		/*Check if SMU_AG2CF1 or SMU_AG2CF2*/
		if((Index== 7U) || (Index== 8U))
		{
		SMU_ALARM_GROUP->CfgReg[Index].U = SMU_AG2CF1_AG2CF2_RESET_VAL;
		}
		/*Check if SMU_AG3CF0 or SMU_AG3CF2*/
		else if((Index== 9U) || (Index== 11U))
		{
		SMU_ALARM_GROUP->CfgReg[Index].U = SMU_AG3CF0_AG3CF2_RESET_VAL;
		}
		else
		{
         SMU_ALARM_GROUP->CfgReg[Index].U = SMU_ALARM_CFG_RESET_VAL;
		}
     }

     for(Index = 0U; Index < SMU_TOTAL_ALARM_GROUPS; Index++)
     {
		/*Check if SMU_AG2FSP*/
		if(Index == 2U)
		{
		 SMU_ALARM_GROUP->FSPCfgReg[Index].U = SMU_AG2FSP_RESET_VAL;
		}
		else
		{
         SMU_ALARM_GROUP->FSPCfgReg[Index].U = SMU_ALARM_FSP_RESET_VAL;
		}
     }

    /* After configuration set temporary lock of SMU configuration */
    SMU_KEYS.U = (unsigned_int)SMU_CFG_KEY_TEMPLOCK;

    /* Restore back the write-protection for registers */
    Mcal_SetSafetyENDINIT_Timed();

    /* Clear the SMU global variables and its backup variable */
    Smu_lSetErrPinStatus(SMU_ERRPIN_NOTSET);
    Smu_lSetSmuDriverState(SMU_NOT_FAILED);
    Smu_lSetSmuLockState(SMU_NOT_LOCKED);

    /* Set SMU Driver init status to SMU_NOT_INITIALIZED */
    Smu_lSetSmuInitStatus(SMU_NOT_INITIALIZED);
  }

  return RetVal;
}/* Smu_DeInit */


/*******************************************************************************
** Traceability      : [cover parentID=]        [/cover]                      **
**                                                                            **
** Syntax           : Std_ReturnType Smu_ClearAlarmStatus                     **
**                    (                                                       **
**                      const uint8 AlarmGroup,                               **
**                      const uint8 AlarmPos                                  **
**                    )                                                       **
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
Std_ReturnType Smu_ClearAlarmStatus
(
  const uint8 AlarmGroup,
  const uint8 AlarmPos
)
{
  Std_ReturnType RetVal;
  uint32 Timeout;
  uint32 AlarmStatusReadback;

  RetVal = E_OK;

  /* SMU alarm can be cleared in any state */
  /* All SMU Groups (0 to 6) are allowed to clear alarm status */
  /* NOTE: Some of the AlarmPos in some AlarmGroup are reserved i.e.
         not valid even if its with in the maximum range.
         The check of this is not done. Action on these alarms has no effect
         on the hardware.
    */
  if((AlarmGroup > (uint8)SMU_MAX_ALARM_GROUP) ||
     (AlarmPos > (uint8)SMU_MAX_ALARM_POS))
  {
     /* Invalid Alarm Group */
     RetVal = (Std_ReturnType)E_NOT_OK;
  }

  if(RetVal == (Std_ReturnType)E_OK)
  {
    /* Call spin lock for SMU Driver usage */
    if(E_OK == Sl_GetSpinLock(SL_SMUDRIVER_SPNLCK_ID, SMU_SPINLOCK_TIMEOUT))
    {

      /* Write SMU_ASCE(0) in CMD register */
      SMU_CMD.U = SMU_ASCE_COMMAND;

      /* disable the write-protection for registers */
      Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);

      /* Write 1 in AG bit to clear alarm */
      SMU_ALARM_GROUP->AGStatusReg[AlarmGroup].U =
                          (unsigned_int)((unsigned_int)0x1U<<AlarmPos);

      /* Restore back the write-protection for registers */
      Mcal_SetSafetyENDINIT_Timed();

      Sl_ReleaseSpinLock(SL_SMUDRIVER_SPNLCK_ID);
    }
    else
    {
      RetVal = E_NOT_OK;/*SMU_RESOURCE_TIMEOUT_ERROR;*/
    }

    if(RetVal == (Std_ReturnType)E_OK)
    {
      /*Read back AG register to validate the Clear */
      Timeout = 0U;
      do
      {
        /* Read Alarm status */
        AlarmStatusReadback =
           (((uint32)(SMU_ALARM_GROUP->AGStatusReg[AlarmGroup].U) >> AlarmPos) &
            0x1U);

        Timeout++;

      }while((Timeout < SMU_AGSTATUS_TIMEOUT) && (AlarmStatusReadback != 0U) );

      if(AlarmStatusReadback != 0U)
      {
        RetVal = (Std_ReturnType)E_NOT_OK;
      }
    }
  }

  return RetVal;

}/* Smu_ClearAlarmStatus */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : Std_ReturnType Smu_SetAlarmStatus                       **
**                    (                                                       **
**                      const uint8 AlarmGroup,                               **
**                      const uint8 AlarmPos                                  **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
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
** Description      : The purpose of the API is to set the requested alarm    **
**                    This service can be used by the user software to trigger**
**                    SW SMU alarm. During the START state of the SMU, it     **
**                    shall be possible to set any of the alarms. However,    **
**                    during the RUN state, only the SW alarms shall be set   **
**                                                                            **
**                                                                            **
*******************************************************************************/
Std_ReturnType Smu_SetAlarmStatus
(
  const uint8 AlarmGroup,
  const uint8 AlarmPos
)
{
  Std_ReturnType RetVal;
  Smu_StateType SmuState;
  uint32 Timeout;
  uint32 AlarmStatusReadback;

  /* Check if Driver state is not FAIL */
  RetVal = Smu_lChkSmuDriverState();

  if(RetVal == (Std_ReturnType)E_OK)
  {
    /* Check if SMU Driver is initialised */
    RetVal = Smu_lChkSmuInitState();
  }

  if(RetVal == (Std_ReturnType)E_OK)
  {
    /* Call spin lock for SMU Driver usage */
    if(E_OK == Sl_GetSpinLock(SL_SMUDRIVER_SPNLCK_ID, SMU_SPINLOCK_TIMEOUT))
    {
      /* Read the SMU state from module DBG register */
      SmuState = (Smu_StateType)(SMU_DBG.B.SSM);

      if(SMU_START_STATE == SmuState)
      {
        /* SMU is in START state */
        /* All SMU Groups (0 to 6) are allowed to set alarm status */
        /* NOTE: Some of the AlarmPos in some AlarmGroup are reserved i.e.
           not valid even if its with in the maximum range.
           The check of this is not done. Action on these alarms has no effect
           on the hardware.
        */
        if((AlarmGroup > (uint8)SMU_MAX_ALARM_GROUP) ||
            (AlarmPos > (uint8)SMU_MAX_ALARM_POS))
        {
          /* Invalid Alarm Group */
          RetVal = (Std_ReturnType)E_NOT_OK;
        }
        else /* Valid alarm parameter to set */
        {

          /* disable the write-protection for registers */
          Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);

          /* Write 1 in AG bit to set alarm */
          SMU_ALARM_GROUP->AGStatusReg[AlarmGroup].U=
                             ((unsigned_int)0x1U<<AlarmPos);
          /* Restore back the write-protection for registers */
          Mcal_SetSafetyENDINIT_Timed();
        }
      }
      /* Alarm is in RUN state or FAULT state */
      else if ((SMU_RUN_STATE == SmuState) || (SMU_FAULT_STATE == SmuState))
      {
        /* SW Alarm Groups 5 is only allowed to set alarm status */
        if((AlarmGroup != (uint8)SMU_SW_ALARM_GROUP) ||
           (AlarmPos > (uint8)SMU_SW_ALARM_MAX_POS))
        {
          /* Invalid Alarm Group */
          RetVal = (Std_ReturnType)E_NOT_OK;
        }
        else /* Valid alarm parameter to set */
        {

          /* Write SMU_ALARM(ARG)
                    where ARG:AlarmPos in CMD register to set the Alarm
                */
          SMU_CMD.U = ((unsigned_int)SMU_ALARM_COMMAND |
                      ((unsigned_int)AlarmPos << SMU_CMD_ARG_BIT_POS)
                      );

        }
      }
      else
      {
        /* Invalid Smu state */
        RetVal = (Std_ReturnType)E_NOT_OK;
      }

      Sl_ReleaseSpinLock(SL_SMUDRIVER_SPNLCK_ID);
    }
    else
    {
      RetVal = E_NOT_OK;/*SMU_RESOURCE_TIMEOUT_ERROR;*/
    }
  }

  if(RetVal == (Std_ReturnType)E_OK)
  {

    /*Read back AG register to validate the Set */
    Timeout = 0U;
    do
    {
      /* Read Alarm status */
      AlarmStatusReadback =(uint32)
      ((SMU_ALARM_GROUP->AGStatusReg[AlarmGroup].U >> AlarmPos) & 0x1U);

      Timeout++;

    }while((Timeout < SMU_AGSTATUS_TIMEOUT) && (AlarmStatusReadback != 1U) );

    if(AlarmStatusReadback != 1U)
    {
      /* Timeout error */
      RetVal = (Std_ReturnType)E_NOT_OK;
    }
  }

  return RetVal;

}/* Smu_SetAlarmStatus */

/*******************************************************************************
** Traceability      : [cover parentID=]        [/cover]                      **
**                                                                            **
** Syntax           : Std_ReturnType Smu_GetAlarmStatus                       **
**                    (                                                       **
**                      const uint8 AlarmGroup,                               **
**                      uint32* const AlarmStatus                             **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Re-entrant                                              **
**                                                                            **
** Parameters(in)   : AlarmGroup : Alarm group register                       **
**                                                                            **
** Parameters (out) : AlarmStatus: Status of the Alarm register               **
**                                                                            **
** Return value     : E_OK - Operation successfully performed                 **
**                    E_NOT_OK - Operation failed eg. Due to invalid          **
**                      parameters.                                           **
**                                                                            **
** Description      : The purpose of the API is to provide the alarm status   **
**                      requested alarm group.                                **
**                                                                            **
**                                                                            **
*******************************************************************************/
Std_ReturnType Smu_GetAlarmStatus
(
  const uint8 AlarmGroup,
  uint32* const AlarmStatus
)
{
  Std_ReturnType RetVal;

  RetVal = E_OK;

  /* Check if input parameters is in vlaid range */
  if((AlarmGroup > (uint8)SMU_MAX_ALARM_GROUP) || (AlarmStatus == NULL_PTR))
  {
    RetVal = (Std_ReturnType)E_NOT_OK;
  }
  else
  {
      /* On no error:
         Read the alarm status from SMU_AGx (x: 0..6) register
      */
    *AlarmStatus = (SMU_ALARM_GROUP->AGStatusReg[AlarmGroup].U);
  }
  return RetVal;
}/* Smu_GetAlarmStatus */

/*******************************************************************************
** Traceability      : [cover parentID=]        [/cover]                      **
**                                                                            **
** Syntax           : Std_ReturnType Smu_GetAlarmDebugStatus                  **
**                    (                                                       **
**                      const uint8 AlarmGroup,                               **
**                      uint32* const AlarmStatus                             **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Re-entrant                                              **
**                                                                            **
** Parameters(in)   : AlarmGroup : Alarm group register                       **
**                                                                            **
** Parameters (out) : AlarmStatus: Status of the Alarm register               **
**                                                                            **
** Return value     : E_OK - Operation successfully performed                 **
**                    E_NOT_OK - Operation failed eg. Due to invalid          **
**                      parameters.                                           **
**                                                                            **
** Description      : The purpose of the API is to provide the alarm status   **
**                      for the requested alarm group from the stored debug   **
**                      registers.                                            **
**                                                                            **
**                                                                            **
*******************************************************************************/
Std_ReturnType Smu_GetAlarmDebugStatus
(
  const uint8 AlarmGroup,
  uint32* const AlarmStatus
)
{
  Std_ReturnType RetVal;

  /* Check if Driver state is not FAIL */
  RetVal = Smu_lChkSmuDriverState();

  if(RetVal == (Std_ReturnType)E_OK)
  {
    /* Check if SMU Driver is initialised */
    RetVal = Smu_lChkSmuInitState();
  }

  if(RetVal == (Std_ReturnType)E_OK)
  {
    /* Check if input parameter is in valid range */
    if((AlarmGroup > (uint8)SMU_MAX_ALARM_GROUP) || (AlarmStatus == NULL_PTR))
    {
      RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
      /* On no error:
         Read the alarm status from SMU_ADx (x: 0..6) register
      */
      *AlarmStatus = (SMU_ALARM_GROUP->ADStatusReg[AlarmGroup].U);
    }
  }
    return RetVal;

}/* Smu_GetAlarmDebugStatus */

/*******************************************************************************
** Traceability      : [cover parentID=]        [/cover]                      **
**                                                                            **
** Syntax           : Std_ReturnType Smu_GetAlarmAction                       **
**                    (                                                       **
**                      const uint8 AlarmGroup,                               **
**                      const uint8 AlarmPos,                                 **
**                      Smu_AlarmActionType* const IntAlarmAction,            **
**                      Smu_FSPActionType* const FSPAction                    **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Re-entrant                                              **
**                                                                            **
** Parameters(in)   : AlarmGroup : Alarm group register                       **
**                    AlarmPos   : Alarm position within the requested group  **
**                                                                            **
** Parameters (out) : AlarmAction: Alarm action for the requested alarm       **
**                    FSPAction  : FSP action for the requested alarm         **
**                                                                            **
** Return value     : E_OK - Operation successfully performed                 **
**                    E_NOT_OK - Operation failed eg. Due to invalid          **
**                      parameters.                                           **
**                                                                            **
** Description      : The purpose of the API is to provide the alarm, FSP     **
**                      action currently configured for the requested alarm.  **
**                      Several fault injection tests in the Testlib rely on  **
**                      the SMU alarm signals to check the integrity of the HW**
**                      safety mechanisms. For this purpose, it needs to      **
**                      ensure that the desired alarms DONOT trigger any      **
**                      internal/external reactions.Since the Testlib is      **
**                      required to restore the current alarm, FSP config     **
**                      after the test execution, it needs to know the alarm  **
**                      action.                                               **
**                                                                            **
*******************************************************************************/
Std_ReturnType Smu_GetAlarmAction
(
  const uint8 AlarmGroup,
  const uint8 AlarmPos,
  Smu_AlarmActionType* const IntAlarmAction,
  Smu_FSPActionType* const FSPAction
)
{
  Std_ReturnType RetVal = E_OK;

  Smu_AlarmActionType AlarmGroupCF2;
  Smu_AlarmActionType AlarmGroupCF1;
  Smu_AlarmActionType AlarmGroupCF0;
  uint32 AlarmGroupCFIndex;

    /* Check for Valid alarm Groups (0 to 6) and alarm position (0 to 31) */
    if((AlarmGroup > (uint8)SMU_MAX_ALARM_GROUP) ||
       (AlarmPos > (uint8)SMU_MAX_ALARM_POS))
    {
      /* Invalid Alarm Group */
      RetVal = (Std_ReturnType)E_NOT_OK;
    }
    /* Check for out parameters being NULL_PTR */
    else if((IntAlarmAction == NULL_PTR) || (FSPAction == NULL_PTR))
    {
      /* Invalid out parameter */
      RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
      /* Get the Register set index */
      AlarmGroupCFIndex = (uint32)((uint32)AlarmGroup * 3U);

      /* Read Alarm configuration from SMU alarm CFx (x=0-2) registers
       * and align them to combine to get 3 bit value
       */
      if(AlarmPos >= 2U)
      {
        AlarmGroupCF0 = (Smu_AlarmActionType)
                        (((SMU_ALARM_GROUP->CfgReg[AlarmGroupCFIndex].U)>>
                          AlarmPos) & SMU_ALMGRP_CFG0_MASK
                        );
        AlarmGroupCF1 = (Smu_AlarmActionType)
                        (((SMU_ALARM_GROUP->CfgReg[(AlarmGroupCFIndex + 1U)].U)>>
                         (AlarmPos-(uint8)1U)) & SMU_ALMGRP_CFG1_MASK
                        );
        AlarmGroupCF2 = (Smu_AlarmActionType)
                        (((SMU_ALARM_GROUP->CfgReg[(AlarmGroupCFIndex + 2U)].U)>>
                         (AlarmPos-(uint8)2U)) & SMU_ALMGRP_CFG2_MASK
                        );
    }
    else if(AlarmPos == 1U)
    {
        AlarmGroupCF0 = (Smu_AlarmActionType)
                        (((SMU_ALARM_GROUP->CfgReg[AlarmGroupCFIndex].U)>>
                          AlarmPos) & SMU_ALMGRP_CFG0_MASK
                        );
        AlarmGroupCF1 = (Smu_AlarmActionType)
                        ((SMU_ALARM_GROUP->CfgReg[(AlarmGroupCFIndex + 1U)].U)
              & SMU_ALMGRP_CFG1_MASK
                        );
        AlarmGroupCF2 = (Smu_AlarmActionType)
                        (((SMU_ALARM_GROUP->CfgReg[(AlarmGroupCFIndex + 2U)].U)<<1U)
              & SMU_ALMGRP_CFG2_MASK
                        );

    }
    else/* for (AlarmPos == 0U)*/
    {
        AlarmGroupCF0 = (Smu_AlarmActionType)
                        ((SMU_ALARM_GROUP->CfgReg[AlarmGroupCFIndex].U)
             & SMU_ALMGRP_CFG0_MASK
                        );
        AlarmGroupCF1 = (Smu_AlarmActionType)
                        (((SMU_ALARM_GROUP->CfgReg[(AlarmGroupCFIndex + 1U)].U)<<1U)
             & SMU_ALMGRP_CFG1_MASK
                        );
        AlarmGroupCF2 = (Smu_AlarmActionType)
                        (((SMU_ALARM_GROUP->CfgReg[(AlarmGroupCFIndex + 2U)].U)<<2U)
              & SMU_ALMGRP_CFG2_MASK
                        );
    }

      /* Combine the alarm actions configured into 3 bit value and
       * assign to out parameter
       */
      *IntAlarmAction = (AlarmGroupCF0 | AlarmGroupCF1 | AlarmGroupCF2);

      /* Assign the FSP action configured to out parameter */
      * FSPAction = (Smu_FSPActionType)
                    (((SMU_ALARM_GROUP->FSPCfgReg[AlarmGroup].U) >> AlarmPos)
                    & SMU_ALARM_FSP_MASK);
    }
  return RetVal;

}/* Smu_GetAlarmAction */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : Std_ReturnType Smu_SetAlarmAction                       **
**                    (                                                       **
**                      const uint8 AlarmGroup,                               **
**                      const uint8 AlarmPos,                                 **
**                      const Smu_AlarmActionType AlarmAction                 **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Re-entrant                                              **
**                                                                            **
** Parameters(in)   : AlarmGroup : Alarm group register                       **
**                    AlarmPos   : Alarm position within the requested group  **
**                    AlarmAction: Alarm action for the requested alarm       **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : E_OK - Operation successfully performed                 **
**                    E_NOT_OK - Operation failed eg. Due to invalid          **
**                      parameters. SMU lock already activated                **
**                                                                            **
** Description      : The purpose of the API is to set the alarm action for   **
**                    the desired alarm. Several fault injection tests in the **
**                    Testlib rely on the SMU alarm signals to check the      **
**                    integrity of the HW safety mechanisms. For this purpose,**
**                    it needs to ensure that the desired alarms DONOT trigger**
**                    any internal/external reactions using this API.         **
**                    Also, after the test execution, the stored configuration**
**                    needs to be restored or SET using this API              **
**                                                                            **
**                                                                            **
*******************************************************************************/
Std_ReturnType Smu_SetAlarmAction
(
  const uint8 AlarmGroup,
  const uint8 AlarmPos,
  const Smu_AlarmActionType AlarmAction
)
{
  Std_ReturnType RetVal=E_OK;

  uint32 AlarmGroupCF2;
  uint32 AlarmGroupCF1;
  uint32 AlarmGroupCF0;
  uint32 AlarmGroupCFIndex;
  uint32 AlarmGroupCFMask;

    /* Check for Valid SMU alarm group (0 to 6) and alarm position (0 to 31) */
    if((AlarmGroup > (uint8)SMU_MAX_ALARM_GROUP) ||
       (AlarmPos > (uint8)SMU_MAX_ALARM_POS))
    {
      /* Invalid Alarm Group */
      RetVal = (Std_ReturnType)E_NOT_OK;
    }
    /* Validate the AlarmAction value to be with in the range */
    /* Configurable alarm action is 0 to 7 but value 1 is reserved */
    else if((AlarmAction > SMU_ALARM_ACTION_IDLE) ||
            (AlarmAction == (Smu_AlarmActionType)SMU_RSVD_ALARM_CONFIG))
    {
      /* Invalid AlarmAction */
      RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if(((uint32)(SMU_KEYS.U & SMU_KEY_PERLOCK_MASK)>> 8U) ==
              (uint32)SMU_CFG_PERLCK_VALUE)
    {
      /* SMU config registers are permanently locked */
      RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
      /* Get the Register set index */
      AlarmGroupCFIndex = (uint32)((uint32)AlarmGroup * 3U);

      /* Get the mask for configuration registers to set the perticular
       * bits
       */
      AlarmGroupCFMask = ~((uint32)0x1U << AlarmPos);

      /* Extract Alarm configuration for 3 CFG registers
       * from input parameter
       */

      if(AlarmPos >= 2U)
      {
        AlarmGroupCF0=(((uint32)AlarmAction & (uint32)SMU_ALMGRP_CFG0_MASK)
                       << AlarmPos);
        AlarmGroupCF1=(((uint32)AlarmAction & (uint32)SMU_ALMGRP_CFG1_MASK)
                       << (AlarmPos -(uint8)1U));
        AlarmGroupCF2=(((uint32)AlarmAction & (uint32)SMU_ALMGRP_CFG2_MASK)
                       << (AlarmPos - (uint8)2U));
      }
      else if(AlarmPos == 1U)
      {
        AlarmGroupCF0=(((uint32)AlarmAction & (uint32)SMU_ALMGRP_CFG0_MASK)
                       << AlarmPos
                      );
        AlarmGroupCF1=((uint32)AlarmAction & (uint32)SMU_ALMGRP_CFG1_MASK);
        AlarmGroupCF2=(((uint32)AlarmAction & (uint32)SMU_ALMGRP_CFG2_MASK) >> 1U);

      }
      else /* for (AlarmPos == 0U)*/
      {
        AlarmGroupCF0=((uint32)AlarmAction & (uint32)SMU_ALMGRP_CFG0_MASK);
        AlarmGroupCF1=(((uint32)AlarmAction & (uint32)SMU_ALMGRP_CFG1_MASK)>>1U);
        AlarmGroupCF2=(((uint32)AlarmAction & (uint32)SMU_ALMGRP_CFG2_MASK)>>2U);
      }

      /* Spinlock required for the use of SMU_KEY registers by multicores */
      if(E_OK == Sl_GetSpinLock(SL_SMUDRIVER_SPNLCK_ID, SMU_SPINLOCK_TIMEOUT))
      {

        /* disable the write-protection for registers */
        Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);


        /*Write Config key to configure the SMU registers. */
        SMU_KEYS.U = (unsigned_int)SMU_CFG_KEY_UNLOCK;

        /* Write Alarm configuration into corresponding
           SMU alarm CFx (x=0-2) registers
        */
        SMU_ALARM_GROUP->CfgReg[AlarmGroupCFIndex].U =
        (((SMU_ALARM_GROUP->CfgReg[AlarmGroupCFIndex].U) &
          (unsigned_int)AlarmGroupCFMask) | (unsigned_int)AlarmGroupCF0
        );
        SMU_ALARM_GROUP->CfgReg[(AlarmGroupCFIndex+1U)].U =
        (((SMU_ALARM_GROUP->CfgReg[(AlarmGroupCFIndex+1U)].U) &
          (unsigned_int)AlarmGroupCFMask) | (unsigned_int)AlarmGroupCF1
        );
        SMU_ALARM_GROUP->CfgReg[(AlarmGroupCFIndex+2U)].U =
        (((SMU_ALARM_GROUP->CfgReg[(AlarmGroupCFIndex+2U)].U) &
          (unsigned_int)AlarmGroupCFMask) | (unsigned_int)AlarmGroupCF2
        );

        /* After configuration set temporary lock of SMU configuration */
        SMU_KEYS.U = (unsigned_int)SMU_CFG_KEY_TEMPLOCK;

        /* Restore back the write-protection for registers */
        Mcal_SetSafetyENDINIT_Timed();

        Sl_ReleaseSpinLock(SL_SMUDRIVER_SPNLCK_ID);
      }
      else
      {
        RetVal = E_NOT_OK;/*SMU_RESOURCE_TIMEOUT_ERROR;*/
      }

    }
  return RetVal;

}/* Smu_SetAlarmAction */

/*******************************************************************************
** Traceability      : [cover parentID=]        [/cover]                      **
**                                                                            **
** Syntax           : Std_ReturnType Smu_ReleaseFSP( )                        **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Re-entrant                                              **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : E_OK - Operation successfully performed                 **
**                    E_NOT_OK - Operation failed eg. Due to invalid          **
**                    conditions i.e.transition from FAULT to RUN is disabled.**
**                                                                            **
** Description      : The purpose of the API is to switch the SMU peripheral  **
**                    from the FAULT state to the RUN state. This also        **
**                    switches the error pin from the FAULT state to          **
**                    FAULT-FREE state. Additionally, this API can be used    **
**                    change the FSP state from the power-on state to the     **
**                    Fault-free state. This is essential to setup the error  **
**                    pin to drive the FSP.It is also required for testing of **
**                    FSP pin                                                 **
**                                                                            **
*******************************************************************************/
Std_ReturnType Smu_ReleaseFSP(void)
{
  Std_ReturnType RetVal;
  Smu_StateType SmuState;
  uint32 SmuEFRST;

  /* Check if Driver state is not FAIL */
  RetVal = Smu_lChkSmuDriverState();

  if(RetVal == (Std_ReturnType)E_OK)
  {
    /* Check if SMU Driver is initialised */
    RetVal = Smu_lChkSmuInitState();
  }

  if(RetVal == (Std_ReturnType)E_OK)
  {
    SmuEFRST = (uint32)(SMU_AGC.B.EFRST);
    SmuState = Smu_GetSmuState();

    /* Check if SMU is in FAULT state and EFRST is enabled*/
    if ((SmuState == SMU_RUN_STATE) || (SmuState == SMU_UNDEFINED_STATE))
    {
      RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if((SmuState == SMU_FAULT_STATE) && (SmuEFRST == SMU_EFRST_DISABLE))
    {
      RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    /* SMU is in START state or (FAULT state with EFRST enabled) */
    {
    /* Release FSP to Fault Free state */
        if(E_OK == Sl_GetSpinLock(SL_SMUDRIVER_SPNLCK_ID, SMU_SPINLOCK_TIMEOUT))
        {

          /* Write SMU_ReleaseFSP(0) in CMD register */
          SMU_CMD.U = SMU_RELEASEFSP_COMMAND;

          /* Check if Release FSP command is accepted
                    by reading the Status reg
                */
          if(SMU_STS.B.RES != SMU_COMMAND_SUCESS)
          {
            RetVal = (Std_ReturnType)E_NOT_OK;
          }

          Sl_ReleaseSpinLock(SL_SMUDRIVER_SPNLCK_ID);

        } /* Sl_GetSpinLock */
        else
        {
          RetVal = E_NOT_OK;/*SMU_RESOURCE_TIMEOUT_ERROR;*/
        }
    }
  }
  return RetVal;

}/* Smu_ReleaseFSP */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : Std_ReturnType Smu_ActivateFSP ( )                      **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Re-entrant                                              **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : E_OK - Operation successfully performed                 **
**                    E_NOT_OK - Operation failed eg. SMU not initialized     **
**                                                                            **
** Description      : This API activates the FSP to indicate a FAULT state on **
**                    the error pin to the safe state switching device. Also, **
**                    In the SMU START state, activation of FSP is only       **
**                    possible using this API as alarms are NOT processed.    **
**                    Additionally, this is required for the testing of the   **
**                    FSP timing                                              **
**                                                                            **
*******************************************************************************/
Std_ReturnType Smu_ActivateFSP(void)
{
  Std_ReturnType RetVal;

  /* Check if Driver state is not FAIL */
  RetVal = Smu_lChkSmuDriverState();

  if(RetVal == (Std_ReturnType)E_OK)
  {
    /* Check if SMU Driver is initialised */
    RetVal = Smu_lChkSmuInitState();
  }

  if(RetVal == (Std_ReturnType)E_OK)
  {
    /* Call spin lock for SMU Driver usage */
    if(E_OK == Sl_GetSpinLock(SL_SMUDRIVER_SPNLCK_ID, SMU_SPINLOCK_TIMEOUT))
    {

      /* Activate FSP by Writing SMU_ActivateFSP(0) in CMD register */
      SMU_CMD.U = SMU_ACTIVATEFSP_COMMAND;

      Sl_ReleaseSpinLock(SL_SMUDRIVER_SPNLCK_ID);

      /* Check if Activate FSP command is successfully accepted */
      if(SMU_STS.B.RES != SMU_COMMAND_SUCESS)
      {
        RetVal = (Std_ReturnType)E_NOT_OK;
      }
    } /* Sl_GetSpinLock */
    else
    {
      RetVal = E_NOT_OK;/*SMU_RESOURCE_TIMEOUT_ERROR;*/
    }
  }

  return RetVal;

}/* Smu_ActivateFSP */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : Std_ReturnType Smu_SetupErrorPin( )                     **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Re-entrant                                              **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : E_OK - Operation successfully performed                 **
**                    E_NOT_OK - Operation failed eg. already in SMU mode     **
**                                                                            **
**                                                                            **
** Description      : This service enables the SMU to control the error pin   **
**                    and hence activate the safe state via the FSP. This API **
**                    switches the error pin from GPIO mode to SMU mode.      **
**                    Only after switching to the SMU mode, SMU can control   **
**                    the error pin (i.e by Alarm, Activate, Release APIs)    **
**                                                                            **
**                                                                            **
*******************************************************************************/
Std_ReturnType Smu_SetupErrorPin(void)
{
  Std_ReturnType RetVal;
  uint8 ErrPinState;

  /* Check if Driver state is not FAIL */
  RetVal = Smu_lChkSmuDriverState();

  if(RetVal == (Std_ReturnType)E_OK)
  {
    /* Check if SMU Driver is initialized */
    RetVal = Smu_lChkSmuInitState();

    if(RetVal == (Std_ReturnType)E_OK)
    {
      /* Check if SMU Cfg registers is not locked */
      RetVal = Smu_lChkSmuLockState();
    }

  }

  if(RetVal == (Std_ReturnType)E_OK)
  {
    /* Check if Error Pin is already setup */
    if(Smu_lGetErrPinStatus() == (Std_ReturnType)E_OK)
    {
      ErrPinState = Smu_ErrPinStatus;
      if(ErrPinState == SMU_ERRPIN_SET)
      {
        RetVal = (Std_ReturnType)E_NOT_OK;
        }
    }
    else
    {
      RetVal = (Std_ReturnType)E_NOT_OK;
    }
  }

  if(RetVal == (Std_ReturnType)E_OK)
  {
    /* disable the write-protection for registers */
    Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);

    /*Write Config key to configure the SMU registers. */
    SMU_KEYS.U = (unsigned_int)SMU_CFG_KEY_UNLOCK;

    /* On No error:
       Set up the Error Pin in SMU mode
    */
    SMU_PCTL.U |= 0x83U;

    /* After configuration set temporary lock of SMU configuration */
    SMU_KEYS.U = (unsigned_int)SMU_CFG_KEY_TEMPLOCK;

    /* Restore back the write-protection for registers */
    Mcal_SetSafetyENDINIT_Timed();

    /* Set the Smu_ErrPinStatus global variable and
       its backup to SMU_ERRPIN_SET
    */
    Smu_lSetErrPinStatus(SMU_ERRPIN_SET);
  }

  return RetVal;

}/* Smu_SetupErrorPin */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : Std_ReturnType Smu_ReleaseErrorPin( )                   **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Re-entrant                                              **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : E_OK - Operation successfully performed                 **
**                    E_NOT_OK - Operation failed eg. Configuration is locked **
**                                                                            **
**                                                                            **
** Description      : This service disables the SMU control of error pin.     **
**                    This API switches the error pin from SMU mode           **
**                    to GPIO mode.                                           **
**                                                                            **
*******************************************************************************/
Std_ReturnType Smu_ReleaseErrorPin(void)
{
  Std_ReturnType RetVal;

  /* Initialize the RetVal to E_NOT_OK */
  RetVal = (Std_ReturnType)E_NOT_OK;

  /* Check if SMU cfg registers is not locked */
  if(SMU_KEYS.B.PERLCK != SMU_CFG_PERLCK_VALUE)
  {
    RetVal = (Std_ReturnType)E_OK;

    /* disable the write-protection for registers */
    Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);

    /*Write Config key to configure the SMU registers. */
    SMU_KEYS.U = (unsigned_int)SMU_CFG_KEY_UNLOCK;

    /* Relase Error Pin from SMU mode */
    SMU_PCTL.U = 0U;

    /* After configuration set temporary lock of SMU configuration */
    SMU_KEYS.U = (unsigned_int)SMU_CFG_KEY_TEMPLOCK;

    /* Restore back the write-protection for registers */
    Mcal_SetSafetyENDINIT_Timed();

    /* Set the Smu_ErrPinStatus global variable and
       its backup to SMU_ERRPIN_NOTSET
    */
    Smu_lSetErrPinStatus(SMU_ERRPIN_NOTSET);

  }

  return RetVal;
}
/*******************************************************************************
** Traceability      : [cover parentID=]        [/cover]                      **
**                                                                            **
** Syntax           : Std_ReturnType Smu_RTStop(const uint8 TimerNum )        **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Re-entrant                                              **
**                                                                            **
** Parameters(in)   : TimerNum : Identifies the Recovery Timer unit to be     **
**                      stopped                                               **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : E_OK - Operation successfully performed                 **
**                    E_NOT_OK - Operation failed eg. Due to invalid          **
**                                 parameters                                 **
**                                                                            **
**                                                                            **
** Description      : The purpose of the API is to stop the requested recovery**
**                    timer unit. Possible usecase: When an fault occurs,     **
**                    error handler might be triggered. However, this error   **
**                    handler should setup a recovery mechanism or error      **
**                    mitigation mechanism within a finite interval of time   **
**                    to prevent the system from failing.                     **
**                                                                            **
*******************************************************************************/
Std_ReturnType Smu_RTStop(const uint8 TimerNum )
{

  Std_ReturnType RetVal;

  /* Check if Driver state is not FAIL */
  RetVal = Smu_lChkSmuDriverState();

  if(RetVal == (Std_ReturnType)E_OK)
  {
    /* Check if SMU Driver is initialised */
    RetVal = Smu_lChkSmuInitState();
  }

  if(RetVal == (Std_ReturnType)E_OK)
  {
    /* Check the input parameter timer index is with in the valid range */
    if(TimerNum >= (uint8)SMU_MAX_RECOV_TIM)
    {
      RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
      /* Call spin lock for SMU Driver usage */
      if(E_OK == Sl_GetSpinLock(SL_SMUDRIVER_SPNLCK_ID, SMU_SPINLOCK_TIMEOUT))
      {

        /* Write CMD for Stop Recovery Timer */
        SMU_CMD.U =((unsigned_int)SMU_STOPREC_COMMAND |
                    ((unsigned_int)TimerNum << SMU_CMD_ARG_BIT_POS)
                   ) ;

        Sl_ReleaseSpinLock(SL_SMUDRIVER_SPNLCK_ID);
      } /* Sl_GetSpinLock */
      else
      {
        RetVal = E_NOT_OK;/*SMU_RESOURCE_TIMEOUT_ERROR*/
      }
    }
  }
  return RetVal;
}/* Smu_RTStop */

/*******************************************************************************
** Traceability      : [cover parentID=]        [/cover]                      **
**                                                                            **
** Syntax           : Std_ReturnType Smu_GetRTMissedEvent                     **
**                    (                                                       **
**                      const uint8 TimerNum,                                 **
**                      boolean* const EventMissed                            **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Re-entrant                                              **
**                                                                            **
** Parameters(in)   : TimerNum : Identifies the Recovery Timer unit to be     **
**                    stopped                                                 **
**                                                                            **
** Parameters (out) : EventMissed                                             **
**                    TRUE: Event has been missed                             **
**                    FALSE: Event has NOT been missed                        **
**                                                                            **
** Return value     : E_OK - Operation successfully performed                 **
**                    E_NOT_OK - Operation failed eg. Due to invalid          **
**                                 parameters                                 **
**                                                                            **
**                                                                            **
** Description      : The purpose of the API is to know if any alarms         **
**                      requiring the requested recovery timer was SET while  **
**                      the recovery timer was running.                       **
**                                                                            **
**                                                                            **
*******************************************************************************/
Std_ReturnType Smu_GetRTMissedEvent
(
  const uint8 TimerNum,
  boolean* const EventMissed
)
{
  Std_ReturnType RetVal;
  const uint32 kTimMissEventPos[2] = {(uint32)0x20000U, (uint32)0x80000U};
  uint32 TimerMissEvent;

  /* Check if Driver state is not FAIL */
  RetVal = Smu_lChkSmuDriverState();

  if(RetVal == (Std_ReturnType)E_OK)
  {
    /* Check if SMU Driver is initialised */
    RetVal = Smu_lChkSmuInitState();
  }

  if(RetVal == (Std_ReturnType)E_OK)
  {
    /* Check the input parameter are with in the valid range */
    if((TimerNum >= (uint8)SMU_MAX_RECOV_TIM) || (EventMissed == NULL_PTR))
    {
      RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else /* TimerNum is valid */
    {
      /*Read the timer event from status register */

      TimerMissEvent = (uint32)(SMU_STS.U & kTimMissEventPos[TimerNum]);
      if(TimerMissEvent > 0U)
      {
        *EventMissed = (boolean)TRUE;
      }
      else
      {
        *EventMissed = (boolean)FALSE;
      }
    }
  }

  return RetVal;

}/* Smu_GetRTMissedEvent */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : Std_ReturnType Smu_LockConfigRegs(void)                 **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Re-entrant                                              **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : E_OK - Operation successfully performed                 **
**                    E_NOT_OK - Operation failed eg. Config registers already**
**                                 locked                                     **
**                                                                            **
**                                                                            **
** Description      : The purpose of the API is to lock the SMU configuration **
**                    registers to prevent any modification to configuration  **
**                    register content. This API also verifies the Lock       **
**                    mechanism by trying to overwrite to SMU_RTC and SMU_AGC **
**                    registers.                                              **
*******************************************************************************/
Std_ReturnType Smu_LockConfigRegs(void)
{
  Std_ReturnType RetVal;
  uint32 RtcValueOld = 0U;
  uint32 RtcValueNew = 0U;
  uint32 AgcValueOld = 0U;
  uint32 AgcValueNew = 0U;


  /* Check if Driver state is not FAIL */
  RetVal = Smu_lChkSmuDriverState();

  if(RetVal == (Std_ReturnType)E_OK)
  {
    /* Check if SMU Driver is initialised */
    RetVal = Smu_lChkSmuInitState();
  }

  if(RetVal == (Std_ReturnType)E_OK)
  {
    /* Check if SMU cfg registers is already locked */
    if(SMU_KEYS.B.PERLCK == SMU_CFG_PERLCK_VALUE)
    {
      RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else /* SMU Cfg Reg not locked */
    {
      RetVal = (Std_ReturnType)E_NOT_OK;

      /* disable the write-protection for registers */
      Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);

      /* Enable permanent lock and enable cfg(temp) lock */
	  #ifndef SMU_NO_PERMANENT_LOCK
      SMU_KEYS.U = (unsigned_int)SMU_CFG_PERLCK_ON_CFGLCK_ON;

      /* Try to disable permanent lock and disable cfg(temp) lock.
         Since permanent lock is already done, this instruction shall 
         not have any effect on SMU_KEYS register */
      SMU_KEYS.U = (unsigned_int)SMU_CFG_PERLCK_OFF_CFGLCK_OFF;

      if ((unsigned_int)SMU_CFG_PERLCK_ON_CFGLCK_ON == SMU_KEYS.U)
      {
	  #endif
        /* To verify lock mechanism, try to ovewrite couple of SMU
           configuration registers that are controlled by SMU_KEYS
           register and ensure register contents remains unchanged.
        */
        RtcValueOld = SMU_RTC.U;
        AgcValueOld = SMU_AGC.U;

        SMU_RTC.U = (unsigned_int)((uint32)RtcValueOld ^ (uint32)IFX_SMU_RTC_RT0E_MSK);
        SMU_AGC.U = (unsigned_int)((uint32)AgcValueOld ^ (uint32)IFX_SMU_AGC_IGCS0_MSK);

        RtcValueNew = SMU_RTC.U;
        AgcValueNew = SMU_AGC.U;

        if ((RtcValueOld == RtcValueNew) && (AgcValueOld == AgcValueNew))
        {
          RetVal = (Std_ReturnType)E_OK;
          /* Set Smu_LockState global variable status
             and its backup to SMU_LOCKED
          */
          Smu_lSetSmuLockState(SMU_LOCKED);
        }
	  #ifndef SMU_NO_PERMANENT_LOCK 	
      }
      #endif 
      /* Restore back the write-protection for registers */
      Mcal_SetSafetyENDINIT_Timed();

    }
  }

  return RetVal;

}/* Smu_LockConfigRegs */

/*******************************************************************************
** Traceability      : [cover parentID=]        [/cover]                      **
**                                                                            **
** Syntax           : Smu_StateType Smu_GetSmuState (void)                    **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Re-entrant                                              **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : SMU_START - SMU is in the START state                   **
**                    SMU_RUN   - SMU is in the RUN state                     **
**                    SMU_FAULT    - SMU is in the FAULT state                **
**                    SMU_UNDEFINED - SMU is in undefined state in hardware   **
**                                                                            **
** Description      : The purpose of the API is to provide the current state  **
**                    of the SMU. This is referred to as the safety status of **
**                    the system as all critical faults will cause the SMU to **
**                    go to the FAIL state as configured by the integrator    **
**                                                                            **
*******************************************************************************/
Smu_StateType Smu_GetSmuState(void)
{
  /* Return SMU state read from DBG register */
  return ((Smu_StateType)(SMU_DBG.B.SSM));
}/* Smu_GetSmuState */


/*******************************************************************************
** Traceability      : [cover parentID=]        [/cover]                      **
**                                                                            **
** Syntax           : Std_ReturnType Smu_ActivateRunState (const uint32 Cmd)  **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Re-entrant                                              **
**                                                                            **
** Parameters(in)   : Cmd       : Command to switch the SMU to the RUN state  **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : E_OK - Operation successfully performed                 **
**                    E_NOT_OK - Operation failed eg. SMU not in START state, **
**                                 invalid command                            **
**                                                                            **
** Description      : This API allows to switch the SMU peripheral into the   **
**                    RUN fault-free state as requested by the caller i.e.    **
**                    application directly or via TestHandler. This is a      **
**                    critical operation. The SMU validates the request based **
**                    on its own integrity checks (i.e. check of the command  **
**                    value). In the negative case the SMU shall be           **
**                    permanently blocked in the fault state and no further   **
**                    action shall be possible. On reaching the RUN state,    **
**                    the processing of the alarms and triggering of the      **
**                    internal/external reactions is enabled and hence the    **
**                    SMU is now able to trigger the safe state/ inform       **
**                    application based on the configuration, in case of an   **
**                    alarm.                                                  **
**                                                                            **
**                                                                            **
*******************************************************************************/
Std_ReturnType Smu_ActivateRunState(const uint32 Cmd)
{
  Std_ReturnType RetVal;
  Smu_StateType SmuState;

  /* Check if Driver state is not FAIL */
  RetVal = Smu_lChkSmuDriverState();

  if(RetVal == (Std_ReturnType)E_OK)
  {
    /* Check if SMU Driver is initialised */
    RetVal = Smu_lChkSmuInitState();
  }

  if(RetVal == (Std_ReturnType)E_OK)
  {

    /* Read the SMU state from DBG register */
    SmuState = (Smu_StateType)(SMU_DBG.B.SSM);

    /* Call spin lock for SMU Driver usage */
    if(E_OK == Sl_GetSpinLock(SL_SMUDRIVER_SPNLCK_ID, SMU_SPINLOCK_TIMEOUT))
    {
      /* Check if SMU is in START state */
      if (SmuState != SMU_START_STATE)
      {
        RetVal = (Std_ReturnType)E_NOT_OK;
      }
      /* Check if input Cmd is RUN Command */
      else if (Cmd != SMU_RUN_COMMAND)
      {
        RetVal = (Std_ReturnType)E_NOT_OK;

        /* Set SMU in Fault state */

        /* Activate FSP by Writting SMU_ActivateFSP(0) in CMD register */
        SMU_CMD.U = SMU_ACTIVATEFSP_COMMAND;

        /* Set SMU Driver as Failed */
        Smu_lSetSmuDriverState(SMU_FAILED);

      }
      else
      {
        /* Write CMD for RUN */
        SMU_CMD.U = Cmd;
      }

      Sl_ReleaseSpinLock(SL_SMUDRIVER_SPNLCK_ID);
    } /* Sl_GetSpinLock */
    else
    {
      RetVal = E_NOT_OK;/*SMU_RESOURCE_TIMEOUT_ERROR;*/
    }
  }

  return RetVal;

}/* Smu_ActivateRunState */

#if (IFX_SAFETLIB_USED == STD_ON)
#define IFX_SMU_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
#else
#define SMU_STOP_SEC_CODE
#include "MemMap.h"
#endif
