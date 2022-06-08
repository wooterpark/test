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
* $Name______: IOHWAB_Adc.c$
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
#include "IoHwAb_ADC.h"
#include "Adc.h"
#include "Adc_Cfg.h"

/*******************************************************************************
**                          Macro Definition                         		  **
*******************************************************************************/
#define IoHwAbW_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "IoHwAbW_Cfg_MemMap.h"

#define IoHwAbW_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "IoHwAbW_Cfg_MemMap.h"

#define IoHwAbW_START_SEC_VAR_INIT_UNSPECIFIED
#include "IoHwAbW_Cfg_MemMap.h"

#define IoHwAbW_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "IoHwAbW_Cfg_MemMap.h"

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
uint32 AdcGroupNotification0_u32;
uint32 AdcGroupNotification1_u32;
uint32 AdcGroupNotification2_u32;
uint32 AdcGroupRslvExcNotification_32;
uint32 AdcGroupNotification3_u32;
uint32 AdcGroupNotification4_u32;
uint32 AdcGroupNotification5_u32;

//uint16 IoHwAb_Buf_Adc_u16[IOHWAB_NUM_ADCCHANNEL];

/*******************************************************************************
**                  Static Local Function Declaration            		      **
*******************************************************************************/

/*******************************************************************************
**                 		  Function Source Code            		              **
*******************************************************************************/

/*******************************************************************************
** Function Name	: IoHwAb_Adc_Init
** Parameter[in] 	: Configptr
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: IoHwAb Adc Initialization
*******************************************************************************/
void IoHwAb_Adc_Init(const Adc_ConfigType *ConfigPtr)
{
	Adc_Init(ConfigPtr);
}

/*******************************************************************************
** Function Name	: AdcGroup0_Notification
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: Adc Group0 conversion success notification fuction
*******************************************************************************/
void AdcGroup0_Notification(void)
{
	AdcGroupNotification0_u32++;
	Adc_ReadGroup(AdcConf_AdcGroup_AdcGroup_0,&Adc_RawData[0U]);
}

/*******************************************************************************
** Function Name	: AdcGroup1_Notification
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: Adc Group1 conversion success notification fuction
*******************************************************************************/
void AdcGroup1_Notification(void)
{
	AdcGroupNotification1_u32++;
	Adc_ReadGroup(AdcConf_AdcGroup_AdcGroup_1,&Adc_RawData[4U]);
}

/*******************************************************************************
** Function Name	: AdcGroup2_Notification
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: Adc Group2 conversion success notification fuction
*******************************************************************************/
void AdcGroup2_Notification(void)
{
	AdcGroupNotification2_u32++;
	Adc_ReadGroup(AdcConf_AdcGroup_AdcGroup_2,&Adc_RawData[8U]);
}

/*******************************************************************************
** Function Name	: AdcGroup3_Notification
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: Adc Group3 conversion success notification fuction
*******************************************************************************/
void AdcGroup3_Notification(void)
{
	AdcGroupNotification3_u32++;
	Adc_ReadGroup(AdcConf_AdcGroup_AdcGroup_3,&Adc_RawData[13U]);
}

/*******************************************************************************
** Function Name	: AdcGroup4_Notification
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: Adc Group4 conversion success notification fuction
*******************************************************************************/
void AdcGroup4_Notification(void)
{
	AdcGroupNotification4_u32++;
	Adc_ReadGroup(AdcConf_AdcGroup_AdcGroup_4,&Adc_RawData[19U]);
}

/*******************************************************************************
** Function Name	: AdcGroup5_Notification
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: Adc Group5 conversion success notification fuction
*******************************************************************************/
void AdcGroup5_Notification(void)
{
	AdcGroupNotification5_u32++;
	Adc_ReadGroup(AdcConf_AdcGroup_AdcGroup_5,&Adc_RawData[23U]);
}









