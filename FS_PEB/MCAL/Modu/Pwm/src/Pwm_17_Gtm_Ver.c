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
**  $CC VERSION : \main\14 $                                                 **
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

/**  TRACEABILITY: [cover parentID=DS_NAS_PWM_PR730][/cover]            
              [cover parentID=DS_NAS_PWM_PR759_PR760_PR761] [/cover]          */



/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Own header file, this includes own configuration file also */
#include "Pwm_17_Gtm_Ver.h"
#include "SchM_Pwm_17_Gtm.h"


/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/
/* Check for definition of the AS Version */
#ifndef PWM_17_GTM_AR_RELEASE_MAJOR_VERSION
  #error "PWM_17_GTM_AR_RELEASE_MAJOR_VERSION is not defined. "
#endif

#ifndef PWM_17_GTM_AR_RELEASE_MINOR_VERSION
  #error "PWM_17_GTM_AR_RELEASE_MINOR_VERSION is not defined. "
#endif

#ifndef PWM_17_GTM_AR_RELEASE_REVISION_VERSION
  #error "PWM_17_GTM_AR_RELEASE_REVISION_VERSION is not defined. "
#endif

#if ( PWM_17_GTM_AR_RELEASE_MAJOR_VERSION != 4U)
  #error "PWM_17_GTM_AR_RELEASE_MAJOR_VERSION does not match. "
#endif

#if ( PWM_17_GTM_AR_RELEASE_MINOR_VERSION != 0U )
  #error "PWM_17_GTM_AR_RELEASE_MINOR_VERSION does not match. "
#endif

/* PWM029: */
/* Check for definition of SW version Information */
#ifndef PWM_17_GTM_SW_MAJOR_VERSION
  #error "PWM_17_GTM_SW_MAJOR_VERSION is not defined. "
#endif

#ifndef PWM_17_GTM_SW_MINOR_VERSION
  #error "PWM_17_GTM_SW_MINOR_VERSION is not defined. "
#endif

#ifndef PWM_17_GTM_SW_PATCH_VERSION
  #error "PWM_17_GTM_SW_PATCH_VERSION is not defined. "
#endif

#if ( PWM_17_GTM_SW_MAJOR_VERSION != 5U )
  #error "PWM_17_GTM_SW_MAJOR_VERSION does not match. "
#endif
#if ( PWM_17_GTM_SW_MINOR_VERSION != 2U )
  #error "PWM_17_GTM_SW_MINOR_VERSION does not match. "
#endif

/*
  PWM029: Inter Module Checks to avoid integration of incompatible files
*/
#if ( PWM_DEV_ERROR_DETECT == STD_ON)
 #ifndef DET_AR_RELEASE_MAJOR_VERSION
   #error "DET_AR_RELEASE_MAJOR_VERSION is not defined. "
 #endif
  
 #ifndef DET_AR_RELEASE_MINOR_VERSION
     #error "DET_AR_RELEASE_MINOR_VERSION is not defined. "
 #endif
 #if (IFX_DET_VERSION_CHECK == STD_ON)  
 #if ( DET_AR_RELEASE_MAJOR_VERSION != 4U )
     #error "DET_AR_RELEASE_MAJOR_VERSION does not match. "
 #endif
 #if ( DET_AR_RELEASE_MINOR_VERSION != 0U )
   #error "DET_AR_RELEASE_MINOR_VERSION does not match. "
 #endif
 #endif /* (IFX_DET_VERSION_CHECK  == STD_ON) */
#endif 
/* PWM_DEV_ERROR_DETECT == STD_ON) */

#define PWM_17_GTM_START_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is 
  allowed only for MemMap.h*/
#include "MemMap.h"

#if((PWM_SET_PERIOD_AND_DUTY_API == STD_ON) || \
    (PWM_SET_DUTY_CYCLE_API == STD_ON) ||(PWM_SET_OUTPUT_TO_IDLE_API == STD_ON))
/*******************************************************************************
** Syntax           : void Pwm_lSchmEnterStartChannel                         **
**                    (                                                       **
**                       void                                                 **
**                    )                                                       **
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
void Pwm_lSchmEnterStartChannel(void)
{
  SchM_Enter_Pwm_StartChannel();
}
/*******************************************************************************
** Syntax           : void Pwm_lSchmExitStartChannel                          **
**                    (                                                       **
**                       void                                                 **
**                    )                                                       **
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
void Pwm_lSchmExitStartChannel(void)
{
  SchM_Exit_Pwm_StartChannel();
}
#endif

#if (PWM_17_GTM_SYNCGRPUPDATEDUTIES_ENABLE == STD_ON) 
/*******************************************************************************
** Syntax           : void Pwm_lSchmEnterSyncDuty                             **
**                    (                                                       **
**                       void                                                 **
**                    )                                                       **
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
void Pwm_lSchmEnterSyncDuty(void)
{
  SchM_Enter_Pwm_SyncDuty();
}
/*******************************************************************************
** Syntax           : void Pwm_lSchmExitSyncDuty                              **
**                    (                                                       **
**                       void                                                 **
**                    )                                                       **
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
void Pwm_lSchmExitSyncDuty(void)
{
  SchM_Exit_Pwm_SyncDuty();
}

#endif

#define PWM_17_GTM_STOP_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is 
  allowed only for MemMap.h*/
#include "MemMap.h"


