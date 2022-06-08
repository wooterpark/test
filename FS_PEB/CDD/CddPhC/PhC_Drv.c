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
* $Name______: Adc_Drv.c$
* $Variant___: 0.0.0$
* $Revision__: 0$
* $Author____: XM$
**
**----------------------------------------------------------------------------**
** MAY BE CHANGED BY USER [Yes/No]: No
**----------------------------------------------------------------------------**
** DESCRIPTION:
				ADC current and Udc Sample.
**----------------------------------------------------------------------------**
** HISTORY:
V1.0.0:   initial version

*******************************************************************************/


/*******************************************************************************
**                      Other Header File Inclusion                           **
*******************************************************************************/
#include "PhC_Drv.h"
#include "Gtm.h"
#include "IfxVadc_reg.h"
#include "Dem.h"
/*******************************************************************************
**                          Macro Definition                         		  **
*******************************************************************************/
#define	ADC_UVW_WAIT_RESULT_MAXDELAY	(200U)
#define	ADC_UVW_WAIT_RESULT_OFFSETDELAY	(5U)

#pragma section ".rodata.Calib_32"

const volatile float CAL_ADC_DClink_Sample_gain_f32 = 0.15326f;

#pragma section
/*******************************************************************************
**                          Typedef Definition                         		  **
*******************************************************************************/

/*******************************************************************************
**                   Static Local Variables Definition              		  **
*******************************************************************************/

/*******************************************************************************
**                     Global Variables Definition              		      **
*******************************************************************************/
/*HW ADC Result Buffers */

Adc_ValueGroupType VAR_Adc_RES_Buffer_CUR_MCU_u16[9U];

PhCDiagType PhC_DEM_count;
/*******************************************************************************
**                  Static Local Function Declaration            		      **
*******************************************************************************/

/*******************************************************************************
**                 		  Function Source Code            		              **
*******************************************************************************/

/*******************************************************************************
** Function Name	: PhC_Init
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: GP ADC initialize
*******************************************************************************/
void PhC_Init(void)
{
	/*three phase current*/
#if(ADC_HW_TRIGGER_USE_DMA == 0U) /*not use DMA*/

	Adc_SetupResultBuffer(PHC_GROUP_U_CUR,&VAR_Adc_RES_Buffer_CUR_MCU_u16[0U]);/*Setup*/

	Adc_EnableHardwareTrigger(PHC_GROUP_U_CUR);

	Adc_EnableGroupNotification(PHC_GROUP_U_CUR);/*enable notification program*/

#elif(ADC_HW_TRIGGER_USE_DMA == 1) /*use DMA*/
	uint32 ui32_U_RegAddr,ui32_V_RegAddr,ui32_W_RegAddr;

	/*use DMA to transport three-phase current AD data*/
	ui32_U_RegAddr = \
	   (uint32)&MODULE_VADC.G[ADC_U_CUR_ADC_HW_SEL].RES[ADC_U_CUR_ADC_CH_SEL].U;
	ui32_V_RegAddr = \
	   (uint32)&MODULE_VADC.G[ADC_V_CUR_ADC_HW_SEL].RES[ADC_V_CUR_ADC_CH_SEL].U;
	ui32_W_RegAddr = \
	   (uint32)&MODULE_VADC.G[ADC_W_CUR_ADC_HW_SEL].RES[ADC_W_CUR_ADC_CH_SEL].U;

	/*Enable the lowest priority DMA channel to interrupt*/
	Mcal_DmaEnableIntr(ADC_W_CUR_DMA_CHANNEL);

	/*start HW trigger DMA transport*/
	Dma_StartHwTransaction(ADC_U_CUR_DMA_CHANNEL,(uint32*)ui32_U_RegAddr,\
				(uint32*)&VAR_ui16_Adc_RES_Buffer_U_CUR_MCU[0U],ADC_DMA_CHANNEL_TCOUNT);
	Dma_StartHwTransaction(ADC_V_CUR_DMA_CHANNEL,(uint32*)ui32_V_RegAddr,\
				(uint32*)&VAR_ui16_Adc_RES_Buffer_V_CUR_MCU[0U],ADC_DMA_CHANNEL_TCOUNT);
	Dma_StartHwTransaction(ADC_W_CUR_DMA_CHANNEL,(uint32*)ui32_W_RegAddr,\
				(uint32*)&VAR_ui16_Adc_RES_Buffer_W_CUR_MCU[0U],ADC_DMA_CHANNEL_TCOUNT);

	/*enable three-phase current HW trigger ATOM channel (The trigger point is set in pwm3ph)*/
//	Gtm_EnableAtomChannel(ADC_HW_TRIGGER_GTM_MODULE,\
//								ADC_HW_TRIGGER_GTM_CHANNEL_CH0);
	/*Enable HW trigger ADC*/
	Adc_EnableHardwareTrigger(PHC_GROUP_U_CUR);
	#if(ADC_SUNCHRONIZATION_MODE_SEL == 0U)
	Adc_EnableHardwareTrigger(PHC_GROUP_V_CUR);
	Adc_EnableHardwareTrigger(PHC_GROUP_W_CUR);
	#endif/*ADC_SUNCHRONIZATION_MODE_SEL*/
#endif/*ADC_HW_TRIGGER_USE_DMA*/
}


#if(ADC_HW_TRIGGER_USE_DMA == 0U) /*not use DMA*/
/*******************************************************************************
** Function Name	: PhC_GetResult_MCUHwAdc
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: PWM interrupt/ADC finish the Notification function call
** Description	  	: GP ADC get three-phase current ADC data
*******************************************************************************/
void PhC_GetResult_MCUHwAdc(PhCOutIFType *out)
{
	Adc_StatusType Adc_Status;
	Adc_Status = Adc_GetGroupStatus(PHC_GROUP_U_CUR);

	if((Adc_Status == ADC_COMPLETED) || (Adc_Status == ADC_STREAM_COMPLETED))
	{
		Adc_ReadGroup(PHC_GROUP_U_CUR,&VAR_Adc_RES_Buffer_CUR_MCU_u16[0U]);
	}

	out->iUNoOff = VAR_Adc_RES_Buffer_CUR_MCU_u16[0U];										/*AN0*/
	out->iVNoOff = VAR_Adc_RES_Buffer_CUR_MCU_u16[3U];										/*AN8*/
	out->iWNoOff = VAR_Adc_RES_Buffer_CUR_MCU_u16[6U];										/*AN16*/
	out->uDcLnkLowMcu = (float32)VAR_Adc_RES_Buffer_CUR_MCU_u16[5U]*CAL_ADC_DClink_Sample_gain_f32;	/*AN15*/
}
#endif/*ADC_HW_TRIGGER_USE_DMA*/


/*******************************************************************************
** Function Name	: CddADC_FaultHand
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: CDD ADC module fault diagnosis
** Description	  	: CDD ADC Fault hand
*******************************************************************************/
void PhC_FaultHand(void)
{
	PhC_Bilateral_Diag((VAR_Adc_RES_Buffer_CUR_MCU_u16[0]),(PHASECURR_ADC_HIGH_LIMITING_VALUE),(PHASECURR_ADC_LOWER_LIMITING_VALUE),(PhC_DEM_count.ADC_UPhaseBISTcnt),\
			(PhC_DEM_count.ADC_UPhaseBISTerrcnt),((void)Dem_SetEventStatus(DemConf_DemEventParameter_ADC_UPhaseBISTFail,DEM_EVENT_STATUS_FAILED)))

	PhC_Bilateral_Diag((VAR_Adc_RES_Buffer_CUR_MCU_u16[3]),(PHASECURR_ADC_HIGH_LIMITING_VALUE),(PHASECURR_ADC_LOWER_LIMITING_VALUE),(PhC_DEM_count.ADC_VPhaseBISTcnt),\
			(PhC_DEM_count.ADC_VPhaseBISTerrcnt),((void)Dem_SetEventStatus(DemConf_DemEventParameter_ADC_VPhaseBISTFail,DEM_EVENT_STATUS_FAILED)))

	PhC_Bilateral_Diag((VAR_Adc_RES_Buffer_CUR_MCU_u16[6]),(PHASECURR_ADC_HIGH_LIMITING_VALUE),(PHASECURR_ADC_LOWER_LIMITING_VALUE),(PhC_DEM_count.ADC_WPhaseBISTcnt),\
			(PhC_DEM_count.ADC_WPhaseBISTerrcnt),((void)Dem_SetEventStatus(DemConf_DemEventParameter_ADC_WPhaseBISTFail,DEM_EVENT_STATUS_FAILED)))

}

/*******************************************************************************

*******************************************************************************/
