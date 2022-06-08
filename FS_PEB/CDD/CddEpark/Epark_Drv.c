/*******************************************************************************
**----------------------------------------------------------------------------**
** Copyright (c) 2018 by JEE.		All rights reserved.
** This software is copyright protected and proprietary to JEE.
** JEE grants to you only those rights as set out in the license conditions.
** All other rights remain with JEE.
**----------------------------------------------------------------------------**
**
* Administrative Information
* $Namespace_: \xx\xx$
* $Class_____: C$
* $Name______: Epark_Drv.c$
* $Variant___: 0.0.0$
* $Revision__: 0$
* $Author____: xuwenliao$
**
**----------------------------------------------------------------------------**
** MAY BE CHANGED BY USER [Yes/No]: No
**----------------------------------------------------------------------------**
** DESCRIPTION:


**----------------------------------------------------------------------------**
** HISTORY:
V1.0.0:


*******************************************************************************/

/*******************************************************************************
**                      Other Header File Inclusion                           **
*******************************************************************************/
#include "Epark_Drv.h"

#if (_CDD_SIMULATION == STD_OFF)
#include "Pwm_17_Gtm.h"
#include "IfxVadc_reg.h"
#include "Dem.h"
#include "Rte_SWC_Epark.h"
#include "Dio.h"
#include "Adc.h"
#include "LvPower_Drv.h"
#endif
/*******************************************************************************
**                          Macro Definition                         		  **
*******************************************************************************/
#define   EPPOC_P0_3_CHANNEL   		DIO_CHANNEL_0_3
#define   Epark_DEM_flase          (0u)
#define   Epark_DEM_ture           (1u)
/*******************************************************************************
**                          Typedef Definition                         		  **
*******************************************************************************/


/*******************************************************************************
**                   Static Local Variables Definition              		  **
*******************************************************************************/
uint16 		CddEpark_ADC_au16[4];            /*EPP_ADC sample AD data*/
boolean 	VAR_CddEpark_Direction_b;		/*Epp Direction signal */
float32 	VAR_CddEpark_Con_Duty_f32;		/*PWM Duty signal */

/*******************************************************************************
**                     Global Variables Definition              		      **
*******************************************************************************/
#pragma section ".rodata.Calib_32"

const volatile boolean CAL_CddEparkTEST_ManualSwitch_b = 0;
const volatile boolean CAL_CddEparkTEST_ManualMosDir_b = 0;
const volatile float32 CAL_CddEparkTEST_ManualMosduty_f32 = 0;

#pragma section

/*******************************************************************************
**                  Static Local Function Declaration            		      **
*******************************************************************************/
static  void Epark_FaultHand(void);


/*******************************************************************************
**                 		  Function Source Code            		              **
*******************************************************************************/
/*******************************************************************************
** Function Name	: Epp_AdcApi_Init
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: EPP Module initialization function
*******************************************************************************/
void Epp_AdcApi_Init(void)
{
#if (_CDD_SIMULATION == STD_OFF)
	 Adc_SetupResultBuffer(AdcConf_AdcGroup_EPP_AdcGroup, &CddEpark_ADC_au16[0]);
	 Adc_EnableHardwareTrigger(AdcConf_AdcGroup_EPP_AdcGroup);
#endif
}




/*******************************************************************************
** Function Name	: Epark_FaultHand
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: EPP Module Fault Hand
*******************************************************************************/
static void Epark_FaultHand(void)
{
	boolean DI_EPPOC_P0_3_b;
#if (_CDD_SIMULATION == STD_OFF)
	if( LV_PowerFinish() == PWR_LV_POWERSETUP_OK )
	{
	DI_EPPOC_P0_3_b=(boolean) Dio_ReadChannel((Dio_ChannelType) EPPOC_P0_3_CHANNEL);
	if(DI_EPPOC_P0_3_b==Epark_DEM_ture)
	{
		(void)Dem_SetEventStatus(DemConf_DemEventParameter_Epark_OverCurFail,DEM_EVENT_STATUS_PREFAILED);
	}
	}
	if( (CddEpark_ADC_au16[0]<EPARK_CURRADC_LOWER_LIMITING_VALUE)||(CddEpark_ADC_au16[0]>EPARK_CURRADC_HIGH_LIMITING_VALUE )  )
	{
		(void)Dem_SetEventStatus(DemConf_DemEventParameter_Epark_SampFail,DEM_EVENT_STATUS_PREFAILED);
	}
	if( (CddEpark_ADC_au16[1]<EPARK_LOCATIONADC_LOWER_LIMITING_VALUE)||(CddEpark_ADC_au16[1]>EPARK_LOCATIONADC_HIGH_LIMITING_VALUE )  )
	{
		(void)Dem_SetEventStatus(DemConf_DemEventParameter_Epark_PosMonSampFail,DEM_EVENT_STATUS_PREFAILED);
	}
	if( (CddEpark_ADC_au16[2]<EPARK_LOCATIONADC_LOWER_LIMITING_VALUE)||(CddEpark_ADC_au16[2]>EPARK_LOCATIONADC_HIGH_LIMITING_VALUE )  )
	{
		(void)Dem_SetEventStatus(DemConf_DemEventParameter_Epark_PosSampFail,DEM_EVENT_STATUS_PREFAILED);
	}
#endif
}





/*******************************************************************************
** Function Name	: Epark_SetOutput
** Parameter[in] 	: in
** Parameter[out] 	: out
** Return Value	  	: None
** Note	  			: None
** Description	  	: EPP Module SetOut handling function
*******************************************************************************/
#if (_CDD_SIMULATION == STD_OFF)
void Epark_SetOutput(const EparkInIFType *in, EparkOutIFType* out)
#else
void Epark_SetOutput(const EparkInIFType *in, EparkOutSimIFType* out)
#endif
{
	uint16 CddEpark_Duty_Tick_u16;
        float32 CddEpark_Duty_f32;

	 VAR_CddEpark_Con_Duty_f32 = in->Epark_Con_Duty_f32;
	 VAR_CddEpark_Direction_b  = in->Epark_Direction_b;

	#if (_CDD_SIMULATION == STD_OFF)
		#if EPARK_USE_MCAL_MODE
		Adc_ReadGroup(AdcConf_AdcGroup_EPP_AdcGroup,&CddEpark_ADC_au16[0U]);
		#else
		if( (MODULE_VADC.G[4].RES[7].B.VF ) == 1U )
		{
			CddEpark_ADC_au16[0]= (uint16)(MODULE_VADC.G[4].RES[5].U);	/*Epark Current*/
			CddEpark_ADC_au16[1]= (uint16)(MODULE_VADC.G[4].RES[6].U);	/*Epark Position1*/
			CddEpark_ADC_au16[2]= (uint16)(MODULE_VADC.G[4].RES[7].U);  /*Epark Position2*/

			MODULE_VADC.G[4].VFR.U |= 0x00E0U;
		}
		#endif

	 out->iEpc 		= (float32)CddEpark_ADC_au16[0];
	 out->posEpc 	= (float32)CddEpark_ADC_au16[1];
	 out->posEpcMon = (float32)CddEpark_ADC_au16[2];

	 Epark_FaultHand();/*EPP diagnose*/

	#endif

    if( (VAR_CddEpark_Con_Duty_f32<1.0)||(VAR_CddEpark_Con_Duty_f32>0.0) )
	{
        CddEpark_Duty_f32=VAR_CddEpark_Con_Duty_f32*10000.0f;   /*QAC test modify XWL20210226*/
    	CddEpark_Duty_Tick_u16 = (uint16)CddEpark_Duty_f32;
	}
	else
	{
		CddEpark_Duty_Tick_u16=0;
	}

	if( CAL_CddEparkTEST_ManualSwitch_b==1U )
	{
		VAR_CddEpark_Direction_b = CAL_CddEparkTEST_ManualMosDir_b;
		VAR_CddEpark_Con_Duty_f32 = CAL_CddEparkTEST_ManualMosduty_f32;

	}
	switch (VAR_CddEpark_Direction_b)
	{
		case CddEpark_FOREWARD:
		{
			#if (_CDD_SIMULATION == STD_OFF)
			Pwm_17_Gtm_SetDutyCycle(Pwm_17_GtmConf_PwmChannel_PwmChannel_Epp_H,	0);
			Pwm_17_Gtm_SetDutyCycle(Pwm_17_GtmConf_PwmChannel_PwmChannel_EPP_L,	CddEpark_Duty_Tick_u16);
			#else
			out->EparkH_Duty_Tick_u16 = 0;
			out->EparkL_Duty_Tick_u16 = CddEpark_Duty_Tick_u16;
			#endif
			break;
		}
		case CddEpark_INVERSION:
		{
			#if (_CDD_SIMULATION == STD_OFF)
			Pwm_17_Gtm_SetDutyCycle(Pwm_17_GtmConf_PwmChannel_PwmChannel_Epp_H,CddEpark_Duty_Tick_u16);
			Pwm_17_Gtm_SetDutyCycle(Pwm_17_GtmConf_PwmChannel_PwmChannel_EPP_L,	0);
			#else
			out->EparkH_Duty_Tick_u16 = CddEpark_Duty_Tick_u16;
			out->EparkL_Duty_Tick_u16 = 0;
			#endif
			break;
		}
		default:
		{
			#if (_CDD_SIMULATION == STD_OFF)
			Pwm_17_Gtm_SetDutyCycle(Pwm_17_GtmConf_PwmChannel_PwmChannel_Epp_H,	0);
			Pwm_17_Gtm_SetDutyCycle(Pwm_17_GtmConf_PwmChannel_PwmChannel_EPP_L,	0);
			#else
			out->EparkH_Duty_Tick_u16 = 0;
			out->EparkL_Duty_Tick_u16 = 0;
			#endif
			break;
		}
	}


}


