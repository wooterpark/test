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
**   $FILENAME   : SmuInt.h $                                                 **
**                                                                            **
**   $CC VERSION : \main\16 $                                                 **
**                                                                            **
**   $DATE       : 2015-12-01 $                                               **
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

#ifndef _SMUINT_H
#define _SMUINT_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Smu.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
/* Time out values */
#define SMU_AGSTATUS_TIMEOUT       (0x1000U)

#define SMU_RESET_TIMEOUT          (0x100U)

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/

/* SMU alarm internal action configuration type */
/* Alarm internal action configuration is a set of 3 registers in hardware.
 * Each with one bit value. Hence, these 3 register values (3 bit alarm
 * configuration) are reflected by the 3 AlarmCfgRegx (x:0 to 2) members.
 * The values are at the least significant bit position.
 */
/* SMU alarm internal action configuration type */
/* Alarm internal action is a 3 bit value. Each bit corresponds to
 * alarm position in AlarmCfgRegx (x:0 to 2) registers.
 */
typedef uint8 Smu_AlarmActionType;
/* SMU external action (FSP) configuration - one bit value (Enable / Disable) */
typedef uint8 Smu_FSPActionType;

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/
/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/

#if (IFX_SAFETLIB_USED == STD_ON)
#define IFX_SMU_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
#else
#define SMU_START_SEC_CODE
#include "MemMap.h"
#endif

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : Std_ReturnType Smu_Init(Smu_ConfigType* ConfigPtr)      **
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

extern Std_ReturnType Smu_Init
(
  const Smu_ConfigType* const ConfigPtr
);



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

extern Std_ReturnType Smu_DeInit(void);



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
extern Std_ReturnType Smu_GetAlarmAction
(
  const uint8 AlarmGroup,
  const uint8 AlarmPos,
  Smu_AlarmActionType* const IntAlarmAction,
  Smu_FSPActionType* const FSPAction
);


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
extern Std_ReturnType Smu_SetAlarmAction
(
  const uint8 AlarmGroup,
  const uint8 AlarmPos,
  const Smu_AlarmActionType AlarmAction
);

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
**                    register content.                                       **
**                                                                            **
**                                                                            **
*******************************************************************************/
extern Std_ReturnType Smu_LockConfigRegs(void);


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
extern Std_ReturnType Smu_ActivateRunState(const uint32 Cmd);

#if (IFX_SAFETLIB_USED == STD_ON)
#define IFX_SMU_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
#else
#define SMU_STOP_SEC_CODE
#include "MemMap.h"
#endif

#endif
