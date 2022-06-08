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
**   $FILENAME   : Smu.h $                                                    **
**                                                                            **
**   $CC VERSION : \main\22 $                                                 **
**                                                                            **
**   $DATE       : 2016-11-23 $                                               **
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


#ifndef _SMU_H
#define _SMU_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Smu_Cfg.h"
#include "Std_Types.h"
#include "Mcal_Options.h"
#include "Mcal_Compiler.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/* SMU Alarm internal action configuration */
#define SMU_NA_ALARM_CONFIG      (0)
#define SMU_RSVD_ALARM_CONFIG    (1U)
#define SMU_IGCS0_ALARM_CONFIG   (2U)
#define SMU_IGCS1_ALARM_CONFIG   (3U)
#define SMU_IGCS2_ALARM_CONFIG   (4U)
#define SMU_NMI_ALARM_CONFIG     (5U)
#define SMU_RESET_ALARM_CONFIG   (6U)
#define SMU_IDLE_ALARM_CONFIG    (7U)

/* SMU Fault to Run state enable / disable macro */
#define SMU_EFRST_DISABLE        (0U)
#define SMU_EFRST_ENABLE         (1U)

/* SMU RECOVERY TIMERS */
#define SMU_RECOV_TIM0    (0x0U)
#define SMU_RECOV_TIM1    (0x1U)

/* SMU Commands */
#define SMU_RUN_COMMAND         (0x0U)
#define SMU_STOPREC_COMMAND     (0x4U)
#define SMU_ASCE_COMMAND        (0x5U)
#define SMU_ALARM_COMMAND       (0x6U)
#define SMU_RELEASEFSP_COMMAND  (0x2U)
#define SMU_ACTIVATEFSP_COMMAND (0x1U)

/* SMU state as read from hardware register */
#define SMU_START_STATE         ((Smu_StateType)0)
#define SMU_RUN_STATE           ((Smu_StateType)1)
#define SMU_FAULT_STATE         ((Smu_StateType)2)
#define SMU_UNDEFINED_STATE     ((Smu_StateType)3)

/* Invalid alarm action which will not be set in alarm config register */
#define SMU_INVALID_ALARM_ACTION   ((Smu_AlarmActionType)0xFFU)

/* Valid alarm actions which can be set in alarm config registers */
#define SMU_ALARM_ACTION_NONE      ((Smu_AlarmActionType)0x00U)
#define SMU_ALARM_ACTION_IGCS0     ((Smu_AlarmActionType)0x02U)
#define SMU_ALARM_ACTION_IGCS1     ((Smu_AlarmActionType)0x03U)
#define SMU_ALARM_ACTION_IGCS2     ((Smu_AlarmActionType)0x04U)
#define SMU_ALARM_ACTION_NMI       ((Smu_AlarmActionType)0x05U)
#define SMU_ALARM_ACTION_RESET     ((Smu_AlarmActionType)0x06U)
#define SMU_ALARM_ACTION_IDLE      ((Smu_AlarmActionType)0x07U)

/* SMU Alarm Group Id */
#define SMU_ALARM_GROUP0        (0U)
#define SMU_ALARM_GROUP1        (1U)
#define SMU_ALARM_GROUP2        (2U)
#define SMU_ALARM_GROUP3        (3U)
#define SMU_ALARM_GROUP4        (4U)
#define SMU_ALARM_GROUP5        (5U)
#define SMU_ALARM_GROUP6        (6U)

/* SMU alarm Id in each group */
#define SMU_ALARM_0             (0U)
#define SMU_ALARM_1             (1U)
#define SMU_ALARM_2             (2U)
#define SMU_ALARM_3             (3U)
#define SMU_ALARM_4             (4U)
#define SMU_ALARM_5             (5U)
#define SMU_ALARM_6             (6U)
#define SMU_ALARM_7             (7U)
#define SMU_ALARM_8             (8U)
#define SMU_ALARM_9             (9U)
#define SMU_ALARM_10            (10U)
#define SMU_ALARM_11            (11U)
#define SMU_ALARM_12            (12U)
#define SMU_ALARM_13            (13U)
#define SMU_ALARM_14            (14U)
#define SMU_ALARM_15            (15U)
#define SMU_ALARM_16            (16U)
#define SMU_ALARM_17            (17U)
#define SMU_ALARM_18            (18U)
#define SMU_ALARM_19            (19U)
#define SMU_ALARM_20            (20U)
#define SMU_ALARM_21            (21U)
#define SMU_ALARM_22            (22U)
#define SMU_ALARM_23            (23U)
#define SMU_ALARM_24            (24U)
#define SMU_ALARM_25            (25U)
#define SMU_ALARM_26            (26U)
#define SMU_ALARM_27            (27U)
#define SMU_ALARM_28            (28U)
#define SMU_ALARM_29            (29U)
#define SMU_ALARM_30            (30U)
#define SMU_ALARM_31            (31U)

/* SMU alarm group used by software */
#define SMU_SW_ALARM_GROUP   (5U)

/* Total number of SMU alarm groups */
#define SMU_TOTAL_ALARM_GROUPS  (7U)

/* Total number of SMU alarm configure registers - 
 * each groups have 3 config reg 
 */
#define SMU_TOTAL_ALARM_CONFIG_REG  (21U)



/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/
/* SMU state as read by hardware register - 2 bit value */
typedef uint8 Smu_StateType;

/* SMU module configuration type - post-build configuration */
typedef struct Smu_ConfigType
{
  uint32 FSPCfg;
  uint32 AGCCfg;
  uint32 RTCCfg;
  uint32 RTAC0Cfg;
  uint32 RTAC1Cfg;
  uint32 AlarmConfig[SMU_TOTAL_ALARM_CONFIG_REG];
  uint32 AlarmFspConfig[SMU_TOTAL_ALARM_GROUPS];
}Smu_ConfigType;

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/
/* Constant array having the Post-build configuration for SMU driver.
 * Can have more than one configuration set.
 */
extern const Smu_ConfigType Smu_ConfigRoot[];

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
extern Std_ReturnType Smu_ClearAlarmStatus
(
  const uint8 AlarmGroup,
  const uint8 AlarmPos
);


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
extern Std_ReturnType Smu_SetAlarmStatus
(
  const uint8 AlarmGroup,
  const uint8 AlarmPos
);


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
extern Std_ReturnType Smu_GetAlarmStatus
(
  const uint8 AlarmGroup,
  uint32* const AlarmStatus
);


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
extern Std_ReturnType Smu_GetAlarmDebugStatus
(
  const uint8 AlarmGroup,
  uint32* const AlarmStatus
);

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
extern Std_ReturnType Smu_SetupErrorPin(void);

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
** Description      : This service enables the SMU to control the error pin.  **
**                    This API switches the error pin from SMU mode           **
**                    to GPIO mode.                                           **
**                                                                            **
*******************************************************************************/
extern Std_ReturnType Smu_ReleaseErrorPin(void);

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
extern Std_ReturnType Smu_ReleaseFSP(void);


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
extern Std_ReturnType Smu_ActivateFSP(void);

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
extern Std_ReturnType Smu_RTStop(const uint8 TimerNum );


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
extern Std_ReturnType Smu_GetRTMissedEvent 
(
  const uint8 TimerNum,
  boolean* const EventMissed
);

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
**                    : SMU_RUN   - SMU is in the RUN state                   **
**                    : SMU_FAULT    - SMU is in the FAULT state              **
**                                                                            **
** Description      : The purpose of the API is to provide the current state  **
**                    of the SMU. This is referred to as the safety status of **
**                    the system as all critical faults will cause the SMU to **
**                    go to the FAIL state as configured by the integrator    **
**                                                                            **
*******************************************************************************/
extern Smu_StateType Smu_GetSmuState(void);

#if (IFX_SAFETLIB_USED == STD_ON)
#define IFX_SMU_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
#else
#define SMU_STOP_SEC_CODE
#include "MemMap.h"
#endif

#endif
