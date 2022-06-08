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
* $Name______: IoHwAb_PWM_SetDutyCycle.c$
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

#define  PWM_CPLD_CLK_IN_period       (20u)
#define  PWM_CPLD_CLK_IN_duty         (10u)
#define  PWM_PUMP_period              (5000u)
#define  PWM_PUMP_duty                (2500u)
#define  PWM_HMcu_330K_period         (302u)
#define  PWM_HMcu_330K_duty           (151u)
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
** Function Name	: IoHwAb_PWM_StartGenerat
** Parameter[in] 	: void
** Parameter[out] 	: void
** Return Value	  	: None
** Note	  			: None
** Description	  	: PWM module Initial
*******************************************************************************/
FUNC(void, IoHwAbW_CODE) IoHwAb_PWM_StartGenerat(void)
{
	Pwm_17_Gtm_SetPeriodAndDuty(Pwm_17_GtmConf_PwmChannel_CPLD_CLK_IN,PWM_CPLD_CLK_IN_period,PWM_CPLD_CLK_IN_duty);
	Pwm_17_Gtm_SetPeriodAndDuty(Pwm_17_GtmConf_PwmChannel_PWM_PUMP,PWM_PUMP_period,PWM_PUMP_duty);
//	Pwm_17_Gtm_SetPeriodAndDuty(Pwm_17_GtmConf_PwmChannel_HMcu_330K_PWM,PWM_HMcu_330K_period,PWM_HMcu_330K_duty);
}

/*******************************************************************************
** Function Name	: IoHwAb_SZTKT_PWM_StartGenerat
** Parameter[in] 	: void
** Parameter[out] 	: void
** Return Value	  	: None
** Note	  			: None
** Description	  	: PWM module Initial
*******************************************************************************/
FUNC(void, IoHwAbW_CODE) IoHwAb_SZTKT_PWM_StartGenerat(void)
{
	Pwm_17_Gtm_SetPeriodAndDuty(Pwm_17_GtmConf_PwmChannel_HMcu_330K_PWM,PWM_HMcu_330K_period,PWM_HMcu_330K_duty);
}

/*******************************************************************************
** Function Name	: IoHwAb_PWM_SetDutyCycle
** Parameter[in] 	: channel
** Parameter[out] 	: Dutycycle
** Return Value	  	: None
** Note	  			: None
** Description	  	: PWM module starts Set PWM dutyCycle
*******************************************************************************/
FUNC (void , IoHwAbW_CODE) IoHwAb_PWM_SetDutyCycle/* return value & FctID */
(
		VAR(uint16, AUTOMATIC) channel,
		VAR(float32, AUTOMATIC) dutycycle
)
{
                float32 PWM_Duty_Tick_f32;
                uint16 PWM_Duty_Tick_u16;
                PWM_Duty_Tick_f32=dutycycle*10000.0f;
                PWM_Duty_Tick_u16=(uint16)PWM_Duty_Tick_f32;
		(void)Pwm_17_Gtm_SetDutyCycle(channel, PWM_Duty_Tick_u16);
}


