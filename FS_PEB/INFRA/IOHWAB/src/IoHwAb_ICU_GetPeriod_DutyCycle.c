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
* $Name______: IOHWAB_ICU_GetPeriod_DutyCycle.c$
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
#include "IoHwAb_ICU.h"
#include "Icu_17_GtmCcu6.h"
/*PROTECTED REGION ID(FileHeaderUserDefinedIncludes :IoHwAb_ICU_GetPeriod_DutyCycle) ENABLED START */
/* Start of user defined includes  - Do not remove this comment */
/* End of user defined includes - Do not remove this comment */
/*PROTECTED REGION END */

/*PROTECTED REGION ID(FileHeaderUserDefinedConstants :IoHwAb_ICU_GetPeriod_DutyCycle) ENABLED START */
/* Start of user defined constant definitions - Do not remove this comment */
/* End of user defined constant definitions - Do not remove this comment */
/*PROTECTED REGION END */

/*PROTECTED REGION ID(FileHeaderUserDefinedVariables :IoHwAb_ICU_GetPeriod_DutyCycle) ENABLED START */
/* Start of user variable defintions - Do not remove this comment  */
/* End of user variable defintions - Do not remove this comment  */
/*PROTECTED REGION END */

/*******************************************************************************
**                          Macro Definition                         		  **
*******************************************************************************/
#define IoHwAbW_START_SEC_CODE
#include "IoHwAbW_Cfg_MemMap.h"

#define IoHwAbW_STOP_SEC_CODE
#include "IoHwAbW_Cfg_MemMap.h"

#define TimeClock_period     (1000000.0f)

/*******************************************************************************
**                          Typedef Definition                         		  **
*******************************************************************************/

/*******************************************************************************
**                   Static Local Variables Definition              		  **
*******************************************************************************/
float32 	VAR_3phPWMUH_Duty_f32;		/*PWM Duty signal */
float32 	VAR_3phPWMUL_Duty_f32;		/*PWM Duty signal */
float32 	VAR_3phPWMVH_Duty_f32;		/*PWM Duty signal */
float32 	VAR_3phPWMVL_Duty_f32;		/*PWM Duty signal */
float32 	VAR_3phPWMWH_Duty_f32;		/*PWM Duty signal */
float32 	VAR_3phPWMWL_Duty_f32;		/*PWM Duty signal */
float32 	VAR_3phPWMUH_Period_f32;		/*PWM Period signal */
float32 	VAR_3phPWMUL_Period_f32;		/*PWM Period signal */
float32 	VAR_3phPWMVH_Period_f32;		/*PWM Period signal */
float32 	VAR_3phPWMVL_Period_f32;		/*PWM Period signal */
float32 	VAR_3phPWMWH_Period_f32;		/*PWM Period signal */
float32 	VAR_3phPWMWL_Period_f32;		/*PWM Period signal */

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
** Function Name	: IoHwAb_ICU_GetPeriod_DutyCycle
** Parameter[in] 	: channel
** Parameter[out] 	: Period
**                  : Dutycycle
** Return Value	  	: None
** Note	  			: None
** Description	  	: IoHwAb Obtain the cycle and duty cycle of PWM captured by ICU module
*******************************************************************************/
FUNC (void , IoHwAbW_CODE) IoHwAb_ICU_GetPeriod_DutyCycle/* return value & FctID */
(
		VAR(uint8, AUTOMATIC) channel,
		CONSTP2VAR(float32, AUTOMATIC, RTE_APPL_DATA) Period,
		CONSTP2VAR(float32, AUTOMATIC, RTE_APPL_DATA) Dutycycle
)
{
	Icu_17_GtmCcu6_DutyCycleType ICU_Result;
	Icu_17_GtmCcu6_InputStateType ICU_State;
	ICU_State = Icu_17_GtmCcu6_GetInputState(channel);
	if(ICU_State == ICU_ACTIVE)
	{
	Icu_17_GtmCcu6_GetDutyCycleValues(channel, &ICU_Result);
	*Period = ((float32)ICU_Result.PeriodTime)/TimeClock_period;
	*Dutycycle = (float32)ICU_Result.ActiveTime/(float32)ICU_Result.PeriodTime;
	}
}

/*******************************************************************************
** Function Name	: IoHwAb_ICU_Get_3phPWMPeriod_DutyCycle
** Parameter[in] 	: channel
** Parameter[out] 	: Period
**                  : Dutycycle
** Return Value	  	: None
** Note	  			: None
** Description	  	: IoHwAb Obtain the cycle and duty cycle of PWM captured by ICU module
*******************************************************************************/
void IoHwAb_ICU_Get_3phPWMPeriod_DutyCycle (void)
{
    IoHwAb_ICU_GetPeriod_DutyCycle(IcuConf_IcuChannel_H3phPWMUH_VGE_P01_7,&VAR_3phPWMUH_Period_f32,&VAR_3phPWMUH_Duty_f32);
	IoHwAb_ICU_GetPeriod_DutyCycle(IcuConf_IcuChannel_H3phPWMUL_VGE_P11_0,&VAR_3phPWMUL_Period_f32,&VAR_3phPWMUL_Duty_f32);
	IoHwAb_ICU_GetPeriod_DutyCycle(IcuConf_IcuChannel_H3phPWMVH_VGE_P02_9,&VAR_3phPWMVH_Period_f32,&VAR_3phPWMVH_Duty_f32);
	IoHwAb_ICU_GetPeriod_DutyCycle(IcuConf_IcuChannel_H3phPWMVL_VGE_P10_7,&VAR_3phPWMVL_Period_f32,&VAR_3phPWMVL_Duty_f32);
	IoHwAb_ICU_GetPeriod_DutyCycle(IcuConf_IcuChannel_H3phPWMWH_VGE_P11_8,&VAR_3phPWMWH_Period_f32,&VAR_3phPWMWH_Duty_f32);
	IoHwAb_ICU_GetPeriod_DutyCycle(IcuConf_IcuChannel_H3phPWMWL_VGE_P00_4,&VAR_3phPWMWL_Period_f32,&VAR_3phPWMWL_Duty_f32);
}
