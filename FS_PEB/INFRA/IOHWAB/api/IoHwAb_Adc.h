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
* $Name______: IOHWAB_ADC.h$
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

#ifndef INFRA_STUB_API_IOHWAB_ADC_H_
#define INFRA_STUB_API_IOHWAB_ADC_H_
/*******************************************************************************
**                      Other Header File Inclusion                           **
*******************************************************************************/
#include "Adc_Cfg.h"
#include "Adc.h"
#include "Std_Types.h"
#include "LvPower_Drv.h"
/*******************************************************************************
**                          Macro Definition                         		  **
*******************************************************************************/
#define	IOHWAB_ADC_TIMER_TRIGGER_GTM_MODULE				1U
#define	IOHWAB_ADC_TIMER_TRIGGER_GTM_CHANNEL_CH0		4U
#define	IOHWAB_ADC_TIMER_TRIGGER_GTM_CHANNEL_CH1		5U
#define	IOHWAB_ADC_TIMER_TRIGGER_GTM_CHANNEL_CH2		6U
#define	IOHWAB_ADC_TIMER_TRIGGER_GTM_CHANNEL_CH3		7U

#define	IOHWAB_ADC_TIMER_TRIGGER_GROUP0_TIME			100000U	    /*1MS*/
#define	IOHWAB_ADC_TIMER_TRIGGER_GROUP1_TIME			1000000U	/*10MS*/
#define	IOHWAB_ADC_TIMER_TRIGGER_GROUP2_TIME			1000000U	/*10MS*/
#define	IOHWAB_ADC_TIMER_TRIGGER_GROUP3_TIME			1000000U	/*10MS*/

#define	IOHWAB_ADC_TIMER_TRIGGER_GROUP0_INIT_TIME		10000U	/*100us*/
#define	IOHWAB_ADC_TIMER_TRIGGER_GROUP1_INIT_TIME		10000U	/*100us*/
#define	IOHWAB_ADC_TIMER_TRIGGER_GROUP2_INIT_TIME		10000U	/*100us*/
#define	IOHWAB_ADC_TIMER_TRIGGER_GROUP3_INIT_TIME		10000U	/*100us*/

#define	IOHWAB_ADC_TIMER_TRIGGER_NORMAL_TIMER	    	1U
#define	IOHWAB_ADC_TIMER_TRIGGER_INIT_TIMER	    		0U
#define ADC_NUM                                         30U


#define IOHWAB_AN5_STTRTEMP1_CHANNEL       (2u)                      /*Motor temperature 1 Channel Ad value storage channel  */
#define IOHWAB_AN13_STTRTEMP2_CHANNEL      (6u)                      /*Motor temperature 2 Channel Ad value storage channel */
#define IOHWAB_AN34_WATERTEMP_CHANNEL      (21u)                     /*Water Temperature  Channel Ad value storage channel */
#define IoHwAb_ADC_Min                     (25u)                     /* ADC sampling low limit  */
#define IoHwAb_ADC_Max                     (4070u)                   /* ADC sampling high limit  */
#define IOHWAB_AN19_CPLD_1_8V_CHANNEL      (9u)                     /* ADC CPLD 1.8V sample channel */
#define IOHWAB_AN11_CPLD_3_3V_CHANNEL      (4u)                      /* ADC CPLD 3.3V sample channel */
#define IOHWAB_AN27_IGBT_18V_HS_CHANNEL    (16u)
#define IOHWAB_AN43_IGBT_18V_LS_CHANNEL    (25u)
//#define IOHWAB_AN7_12V_Narr_CHANNEL        (36u)                    /*AN7 AD value is from CddADC*/
#define IOHWAB_AN3_12V_Wide_CHANNEL        (0u)
#define IOHWAB_AN6_5V_Qt1_CHANNEL          (3u)
#define IOHWAB_AN12_5V_Qt2_CHANNEL         (5U)
#define IOHWAB_AN22_5V_Qco_CHANNEL         (11u)
#define IOHWAB_AN35_1V3_CHANNEL            (22u)
#define IOHWAB_AN14_3V3_CHANNEL            (7u)
#define IOHWAB_AN23_5VQUC_CHANNEL          (12u)
#define IOHWAB_AN29_IUVW_P_REF_CHANNEL     (17u)
#define IOHWAB_AN30_IUVW_N_REF_CHANNEL     (18u)
#define IOHWAB_AN24_5V_LEM_CHANNEL         (13u)
#define IOHWAB_AN33_KL30_CHANNEL           (20u)


#define IOHWAB_NUM_ADCCHANNEL 			36U  //Number of Adc channel
#define IoHwAb_Adc_ConfigType 	Adc_ConfigType

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
typedef  struct AdcChannelInfo
{
	/* Position result in Buffer*/
	uint16 bufId;
	/* Id of group which channel belong to*/
	uint16 GroupId;
} AdcChannelInfo;

typedef struct
{
	float32 ConvCoff;
	float32 ConvOffset;
}ADCGen_PBCfg_S;
/*******************************************************************************
**                   Static Local Variables Definition              		  **
*******************************************************************************/

/*******************************************************************************
**                     Global Variables Definition              		      **
*******************************************************************************/
extern uint16 Adc_RawData[ADC_NUM];

extern float32 VAR_IoHwAb_Adc_Phy_IUVW_P_REF_f32;

extern float32 VAR_IoHwAb_Adc_Phy_IUVW_N_REF_f32;

extern float32 VAR_IoHwAb_Adc_Phy_KL30_f32;
extern const ADCGen_PBCfg_S Adc_CfgData[ADC_NUM];

/*******************************************************************************
**                  Static Local Function Declaration            		      **
*******************************************************************************/

/*******************************************************************************
**                 		  Function Source Code            		              **
*******************************************************************************/

/*******************************************************************************
** Function Name	: IOHWAB_Adc_Init
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: IoHwAb_Adc Module initialization function
*******************************************************************************/
extern void IoHwAb_Adc_Init(const Adc_ConfigType *ConfigPtr);
/*******************************************************************************
** Function Name	: IOHWAB_ADC_GetPhyVolate
** Parameter[in] 	: channel
** Parameter[out] 	: None
** Return Value	  	: RawVoltage
** Note	  			: None
** Description	  	: IoHwAb get ADC rawVoltage function
*******************************************************************************/
extern FUNC (void , IoHwAbW_CODE) IoHwAb_ADC_GetPhyVoltage/* return value & FctID */
(
		VAR(uint8, AUTOMATIC) Channel,
		CONSTP2VAR(float32, AUTOMATIC, RTE_APPL_DATA) RawVoltage
);

/*******************************************************************************
** Function Name	: IOHWAB_ADC_DEM
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: Fault diagnosis of ADC sampling in IoHwAb
*******************************************************************************/
extern FUNC (void , IoHwAbW_CODE) IoHwAb_ADC_DEM(void);

/*******************************************************************************
** Function Name	: IOHWAB_ADC_StartConversion
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: StartConversion of ADC sampling in IoHwAb
*******************************************************************************/
extern void IoHwAb_ADC_StartConversion(void);

extern void IoHwAb_Adc_Init(const Adc_ConfigType *ConfigPtr);

extern void AdcGroup0_Notification(void);
extern void AdcGroup1_Notification(void);
extern void AdcGroup2_Notification(void);
extern void AdcGroup3_Notification(void);
extern void AdcGroup4_Notification(void);
extern void AdcGroup5_Notification(void);
#endif /* INFRA_STUB_API_IOHWAB_ADC_H_ */
