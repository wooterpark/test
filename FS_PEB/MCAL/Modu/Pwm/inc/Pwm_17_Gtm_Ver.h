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
**  $FILENAME   : Pwm_17_Gtm_Ver.h                                            **
**                                                                            **
**  $CC VERSION : \main\10 $                                                 **
**                                                                            **
**  $DATE       : 2017-11-03 $                                               **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : This file contains                                         **
**                 - functionality of Pwm driver.                            **
**                                                                            **
**  MAY BE CHANGED BY USER [Yes/No]: No                                       **
**                                                                            **
*******************************************************************************/
/* Traceability : 
                                                                     */



/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#ifndef PWM_17_GTM_VER_H
#define PWM_17_GTM_VER_H

/* Own header file, this includes own configuration file also */
#include "Pwm_17_Gtm.h"
/* Added for definition of IFX_DET_VERSION_CHECK */
#include "Mcal.h"

#define PWM_17_GTM_START_SEC_CODE
#include "MemMap.h"

#if((PWM_SET_PERIOD_AND_DUTY_API == STD_ON) || \
    (PWM_SET_DUTY_CYCLE_API == STD_ON) ||(PWM_SET_OUTPUT_TO_IDLE_API == STD_ON))
/*******************************************************************************
** Syntax           : extern void Pwm_lSchmEnterStartChannel(void)            **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Calls the SchM function to suspend the interrupts       **
**                                                                            **
*******************************************************************************/
extern void Pwm_lSchmEnterStartChannel(void);

/*******************************************************************************
** Syntax           : extern void Pwm_lSchmExitStartChannel(void)             **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Calls the SchM function to resume the interrupts        **
**                                                                            **
*******************************************************************************/
extern void Pwm_lSchmExitStartChannel(void);
#endif

#if (PWM_17_GTM_SYNCGRPUPDATEDUTIES_ENABLE == STD_ON) 
/*******************************************************************************
** Syntax           : extern void Pwm_lSchmEnterSyncDuty(void)                **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Calls the SchM function to suspend the interrupts       **
**                                                                            **
*******************************************************************************/
extern void Pwm_lSchmEnterSyncDuty(void);

/*******************************************************************************
** Syntax           : extern void Pwm_lSchmExitSyncDuty(void)                 **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Calls the SchM function to resume the interrupts        **
**                                                                            **
*******************************************************************************/
extern void Pwm_lSchmExitSyncDuty(void);

#endif

#define PWM_17_GTM_STOP_SEC_CODE
#include "MemMap.h"

#endif 
/* PWM_17_GTMCCU6_VER_H */
