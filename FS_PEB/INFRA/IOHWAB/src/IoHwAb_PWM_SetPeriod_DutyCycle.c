/*******************************************************************************
**----------------------------------------------------------------------------**
** Copyright (c) 2018 by JEE.		All rights reserved.
** This software is copyright protected and proprietary to JEE.
** JEE grants to you only those rights as set out in the license conditions.
** All other rights remain with JEE.
**----------------------------------------------------------------------------**
**
* Administrative Information
* $Namespace_: \ArCfg\IOHWAB$
* $Class_____: C$
* $Name______: IoHwAb_PWM_SetPeriod_DutyCycle.c$
* $Variant___: 0.0.0$
* $Revision__: 0$
* $Author____: xuwenliao$
**
**----------------------------------------------------------------------------**
** MAY BE CHANGED BY USER [Yes/No]: YES
**----------------------------------------------------------------------------**
** DESCRIPTION:

**----------------------------------------------------------------------------**
** HISTORY:
V1.0.0:

*******************************************************************************/

/*******************************************************************************
**                      Other Header File Inclusion                           **
*******************************************************************************/
#include "Rte_IoHwAbW.h"
#include "Pwm_17_Gtm.h"
#include "IoHwAb_PWM.h"
#include "Pwm_17_Gtm.h"

/*******************************************************************************
**                          Macro Definition                         		  **
*******************************************************************************/
#define IoHwAbW_START_SEC_CODE
#include "IoHwAbW_Cfg_MemMap.h"

#define IoHwAbW_STOP_SEC_CODE
#include "IoHwAbW_Cfg_MemMap.h"

/*******************************************************************************
**                          Typedef Definition                         		  **
*******************************************************************************/

/*******************************************************************************
**                   Static Local Variables Definition              		  **
*******************************************************************************/

/*******************************************************************************
**                     Global Variables Definition              		      **
*******************************************************************************/

/*******************************************************************************
**                  Static Local Function Declaration            		      **
*******************************************************************************/

/*******************************************************************************
**                 		  Function Source Code            		              **
*******************************************************************************/

/*******************************************************************************
** Function Name	: IoHwAb_PWM_SetPeriod_DutyCycle
** Parameter[in] 	: channel
**                  : period
**                  : dutycycle
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: PWM module  Set PWM dutyCycle and period fuction
*******************************************************************************/
FUNC (void , IoHwAbW_CODE) IoHwAb_PWM_SetPeriod_DutyCycle/* return value & FctID */
(
		VAR(uint16, AUTOMATIC) channel,
		VAR(uint32, AUTOMATIC) period,
		VAR(float32, AUTOMATIC) dutycycle
)
{
	float32 HAL_PWM_Duty_Tick_f32;
	uint16 HAL_PWM_Duty_Tick_u16;
	HAL_PWM_Duty_Tick_f32=dutycycle*10000.0f;
	HAL_PWM_Duty_Tick_u16=(uint16)HAL_PWM_Duty_Tick_f32;
	Pwm_17_Gtm_SetPeriodAndDuty(channel, period, HAL_PWM_Duty_Tick_u16);
}


