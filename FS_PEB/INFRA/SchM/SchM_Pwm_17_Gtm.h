/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2013)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  $FILENAME   : SchM_Pwm_17_Gtm.h $                                        **
**                                                                           **
**  $CC VERSION : \main\5 $                                                  **
**                                                                           **
**  $DATE       : 2017-11-03 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This header file exports the exclusive area                **
**                  functions.                                               **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: Yes                                     **
**                                                                           **
******************************************************************************/
#ifndef SCHM_PWM_17_GTM_H
#define SCHM_PWM_17_GTM_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

#include "Std_Types.h"
/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/

/*******************************************************************************
** Syntax           : void SchM_Enter_Pwm_StartChannel(void)                  **
**                                                                            **
** Service ID       : 0x03                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - Reentrant                                         **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : Enters Module exclusive area                            **
**                                                                            **
*******************************************************************************/
extern void SchM_Enter_Pwm_StartChannel(void);


/*******************************************************************************
** Syntax           : void SchM_Exit_Pwm_StartChannel(void)                   **
**                                                                            **
** Service ID       : 0x04                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - Reentrant                                         **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : Exits Module exclusive area                             **
**                                                                            **
*******************************************************************************/
extern void SchM_Exit_Pwm_StartChannel(void);


/*******************************************************************************
** Syntax           : void SchM_Enter_Pwm_SyncDuty(void)                      **
**                                                                            **
** Service ID       : 0x03                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - Reentrant                                         **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : Enters Module exclusive area                            **
**                                                                            **
*******************************************************************************/
extern void SchM_Enter_Pwm_SyncDuty(void);


/*******************************************************************************
** Syntax           : void SchM_Exit_Pwm_SyncDuty(void)                       **
**                                                                            **
** Service ID       : 0x04                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - Reentrant                                         **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : Exits Module exclusive area                             **
**                                                                            **
*******************************************************************************/
extern void SchM_Exit_Pwm_SyncDuty(void);


#endif /* SCHM_PWM_17_GTM_H */

