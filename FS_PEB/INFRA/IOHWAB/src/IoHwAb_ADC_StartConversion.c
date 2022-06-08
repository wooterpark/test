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
* $Name______: IOHWAB_ADC_StartConversion.c$
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
V1.0.0:   Note Use English

*******************************************************************************/

/*******************************************************************************
**                      Other Header File Inclusion                           **
*******************************************************************************/
#include "Dio.h"
#include "Rte_IoHwAbW.h"
#include "IoHwAb_ADC.h"
#include "Gtm.h"

/*******************************************************************************
**                          Macro Definition                         		  **
*******************************************************************************/
#define IoHwAbW_START_SEC_CODE
#include "IoHwAbW_Cfg_MemMap.h"

#define IoHwAbW_STOP_SEC_CODE
#include "IoHwAbW_Cfg_MemMap.h"

#define		PRV_HW_BIT0		DioConf_DioChannel_DI_HardVersion_11_13        //HW version number bit0
#define		PRV_HW_BIT1		DioConf_DioChannel_DI_HardVersion_11_14        //HW version number bit1
#define		PRV_HW_BIT2		DioConf_DioChannel_DI_HardVersion_11_15        //HW version number bit2
#define		PRV_HW_BIT3		DioConf_DioChannel_DI_HardVersion_12_0        //HW version number bit2

/*******************************************************************************
**                          Typedef Definition                         		  **
*******************************************************************************/

/*******************************************************************************
**                   Static Local Variables Definition              		  **
*******************************************************************************/

/*******************************************************************************
**                     Global Variables Definition              		      **
*******************************************************************************/
uint16 Adc_Sin_Cos[4];
/*******************************************************************************
**                  Static Local Function Declaration            		      **
*******************************************************************************/

/*******************************************************************************
**                 		  Function Source Code            		              **
*******************************************************************************/

/*******************************************************************************
** Function Name	: IoMcu_SetTimerTrigger
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: IoMcu set Timer Trigger
*******************************************************************************/
static void IoMcu_SetTimerTrigger(void )
{
	/*disable Timer Trigger ATOM channel output*/
	Gtm_DisableAtomChannel(IOHWAB_ADC_TIMER_TRIGGER_GTM_MODULE,\
			IOHWAB_ADC_TIMER_TRIGGER_GTM_CHANNEL_CH0);
	Gtm_DisableAtomChannel(IOHWAB_ADC_TIMER_TRIGGER_GTM_MODULE,\
			IOHWAB_ADC_TIMER_TRIGGER_GTM_CHANNEL_CH1);
	Gtm_DisableAtomChannel(IOHWAB_ADC_TIMER_TRIGGER_GTM_MODULE,\
			IOHWAB_ADC_TIMER_TRIGGER_GTM_CHANNEL_CH2);
	Gtm_DisableAtomChannel(IOHWAB_ADC_TIMER_TRIGGER_GTM_MODULE,\
			IOHWAB_ADC_TIMER_TRIGGER_GTM_CHANNEL_CH3);

	/*reset Timer Trigger ATOM channel CN0*/
	Gtm_SetAtomCounterCn0(IOHWAB_ADC_TIMER_TRIGGER_GTM_MODULE,\
			IOHWAB_ADC_TIMER_TRIGGER_GTM_CHANNEL_CH0,0U);
	Gtm_SetAtomCounterCn0(IOHWAB_ADC_TIMER_TRIGGER_GTM_MODULE,\
			IOHWAB_ADC_TIMER_TRIGGER_GTM_CHANNEL_CH1,0U);
	Gtm_SetAtomCounterCn0(IOHWAB_ADC_TIMER_TRIGGER_GTM_MODULE,\
			IOHWAB_ADC_TIMER_TRIGGER_GTM_CHANNEL_CH2,0U);
	Gtm_SetAtomCounterCn0(IOHWAB_ADC_TIMER_TRIGGER_GTM_MODULE,\
			IOHWAB_ADC_TIMER_TRIGGER_GTM_CHANNEL_CH3,0U);


	/*set 10ms reset Timer Trigger ATOM channel SR0¡¢SR1*/
	Gtm_SetAtomShadowValSr1(IOHWAB_ADC_TIMER_TRIGGER_GTM_MODULE,\
			IOHWAB_ADC_TIMER_TRIGGER_GTM_CHANNEL_CH0,IOHWAB_ADC_TIMER_TRIGGER_GROUP0_TIME/2u);
	Gtm_SetAtomShadowValSr0(IOHWAB_ADC_TIMER_TRIGGER_GTM_MODULE,\
			IOHWAB_ADC_TIMER_TRIGGER_GTM_CHANNEL_CH0,IOHWAB_ADC_TIMER_TRIGGER_GROUP0_TIME);

	Gtm_SetAtomShadowValSr1(IOHWAB_ADC_TIMER_TRIGGER_GTM_MODULE,\
			IOHWAB_ADC_TIMER_TRIGGER_GTM_CHANNEL_CH1,IOHWAB_ADC_TIMER_TRIGGER_GROUP1_TIME/2u);
	Gtm_SetAtomShadowValSr0(IOHWAB_ADC_TIMER_TRIGGER_GTM_MODULE,\
			IOHWAB_ADC_TIMER_TRIGGER_GTM_CHANNEL_CH1,IOHWAB_ADC_TIMER_TRIGGER_GROUP1_TIME);

	Gtm_SetAtomShadowValSr1(IOHWAB_ADC_TIMER_TRIGGER_GTM_MODULE,\
			IOHWAB_ADC_TIMER_TRIGGER_GTM_CHANNEL_CH2,IOHWAB_ADC_TIMER_TRIGGER_GROUP2_TIME/2u);
	Gtm_SetAtomShadowValSr0(IOHWAB_ADC_TIMER_TRIGGER_GTM_MODULE,\
			IOHWAB_ADC_TIMER_TRIGGER_GTM_CHANNEL_CH2,IOHWAB_ADC_TIMER_TRIGGER_GROUP2_TIME);

	Gtm_SetAtomShadowValSr1(IOHWAB_ADC_TIMER_TRIGGER_GTM_MODULE,\
			IOHWAB_ADC_TIMER_TRIGGER_GTM_CHANNEL_CH3,IOHWAB_ADC_TIMER_TRIGGER_GROUP3_TIME/2u);
	Gtm_SetAtomShadowValSr0(IOHWAB_ADC_TIMER_TRIGGER_GTM_MODULE,\
			IOHWAB_ADC_TIMER_TRIGGER_GTM_CHANNEL_CH3,IOHWAB_ADC_TIMER_TRIGGER_GROUP3_TIME);

	/*enable Timer Trigger ATOM channel output*/
	Gtm_EnableAtomChannel(IOHWAB_ADC_TIMER_TRIGGER_GTM_MODULE,\
			IOHWAB_ADC_TIMER_TRIGGER_GTM_CHANNEL_CH0);
	Gtm_EnableAtomChannel(IOHWAB_ADC_TIMER_TRIGGER_GTM_MODULE,\
			IOHWAB_ADC_TIMER_TRIGGER_GTM_CHANNEL_CH1);
	Gtm_EnableAtomChannel(IOHWAB_ADC_TIMER_TRIGGER_GTM_MODULE,\
			IOHWAB_ADC_TIMER_TRIGGER_GTM_CHANNEL_CH2);
	Gtm_EnableAtomChannel(IOHWAB_ADC_TIMER_TRIGGER_GTM_MODULE,\
			IOHWAB_ADC_TIMER_TRIGGER_GTM_CHANNEL_CH3);

	/*enable hardware trigger*/
	Adc_EnableHardwareTrigger(AdcConf_AdcGroup_AdcGroup_0);
	Adc_EnableHardwareTrigger(AdcConf_AdcGroup_AdcGroup_1);
	Adc_EnableHardwareTrigger(AdcConf_AdcGroup_AdcGroup_2);
	Adc_EnableHardwareTrigger(AdcConf_AdcGroup_AdcGroup_3);
	Adc_EnableHardwareTrigger(AdcConf_AdcGroup_AdcGroup_4);
	Adc_EnableHardwareTrigger(AdcConf_AdcGroup_AdcGroup_5);
	Adc_EnableHardwareTrigger(AdcConf_AdcGroup_AdcGroup_Cos);
	Adc_EnableHardwareTrigger(AdcConf_AdcGroup_AdcGroup_Sin);
}

/*******************************************************************************
** Function Name	: IoHwAb_ADC_StartConversion
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: This function is used for start or stop ADC group which channel belong to
*******************************************************************************/
void IoHwAb_ADC_StartConversion/* return value & FctID */
(
		void
)
{
	/*general ADC*/
		/*Setup*/
		Adc_SetupResultBuffer(AdcConf_AdcGroup_AdcGroup_0,&Adc_RawData[0U]);
		Adc_SetupResultBuffer(AdcConf_AdcGroup_AdcGroup_1,&Adc_RawData[4U]);
		Adc_SetupResultBuffer(AdcConf_AdcGroup_AdcGroup_2,&Adc_RawData[8U]);
		Adc_SetupResultBuffer(AdcConf_AdcGroup_AdcGroup_3,&Adc_RawData[13U]);
		Adc_SetupResultBuffer(AdcConf_AdcGroup_AdcGroup_4,&Adc_RawData[19U]);
		Adc_SetupResultBuffer(AdcConf_AdcGroup_AdcGroup_5,&Adc_RawData[23U]);
		Adc_SetupResultBuffer(AdcConf_AdcGroup_AdcGroup_Cos,&Adc_Sin_Cos[0]);
		Adc_SetupResultBuffer(AdcConf_AdcGroup_AdcGroup_Sin,&Adc_Sin_Cos[2]);
		Adc_RawData[29U]=Dio_ReadChannel(PRV_HW_BIT3)*8+Dio_ReadChannel(PRV_HW_BIT2)*4+Dio_ReadChannel(PRV_HW_BIT1)*2+Dio_ReadChannel(PRV_HW_BIT0); /*HW version number */

		IoMcu_SetTimerTrigger();

		/*enable notification function */
		Adc_EnableGroupNotification(AdcConf_AdcGroup_AdcGroup_0);
		Adc_EnableGroupNotification(AdcConf_AdcGroup_AdcGroup_1);
		Adc_EnableGroupNotification(AdcConf_AdcGroup_AdcGroup_2);
		Adc_EnableGroupNotification(AdcConf_AdcGroup_AdcGroup_3);
		Adc_EnableGroupNotification(AdcConf_AdcGroup_AdcGroup_4);
		Adc_EnableGroupNotification(AdcConf_AdcGroup_AdcGroup_5);

}


