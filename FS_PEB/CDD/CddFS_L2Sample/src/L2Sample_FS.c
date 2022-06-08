/*
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
#include "L2Sample_FS.h"
#include "Gtm.h"
#include "Dma.h"
#include "IfxVadc_reg.h"
#include "Dsadc.h"
#include "Dio.h"
#include "Irq_Cfg.h"
#include "Irq.h"
#include "IfxCan_reg.h"
#include "IoHwAb_ICU.h"
#include "Dsadc.h"
#include "Icu_17_GtmCcu6_Cfg.h"
#include "Adc_Cfg.h"
#include "IoHwAb_Adc.h"
#include "HvMcu_Drv.h"
#include "ComStack_Types.h"
#include "CanIf.h"
#include "Snapshot_Can_PBCfg.h"
#include "set_get_data.h"
//#include "SWC_TPC.h"
#include "RDC.h"
#include "SWC_TRSP.h"
#include "IgbtDrv.h"
//#include "SWC_PhC.h"
//#include "SWC_MCF.h"
#include "Pwm3ph.h"


/*******************************************************************************
 **                          Macro Definition                         		  **
 *******************************************************************************/




#define FIXME_GET_PWM_PERIOD_DUTYCYCLE		1U
#define FS_AN3_UBRWIDE_G0_3_GAIN            0.00714F
#define FS_AN7_UBRNARR_G0_7_GAIN            0.00244F
#define FS_AN33_UB_SBC_G4_1_GAIN            0.0069F
#define FS_AN27_18VHS_G3_3_GAIN             0.00878F
#define FS_AN11_3V3CPLD_G3_3_GAIN           0.00122F
#define FS_AN19_1V8CPLD_G2_3_GAIN           0.00122F


/*******************************************************************************
 **                          Typedef Definition                         		  **
 *******************************************************************************/


/*******************************************************************************
 **                   Static Local Variables Definition              		  **
 *******************************************************************************/

/*******************************************************************************
 **                     Global Variables Definition              		      **
 *******************************************************************************/

static uint16 VAR_ui16_Adc_RES_Buffer_Cos[32U] __attribute__ ((asection(".data.FIFO_RDC_COS_BUFFER","f=aw")));
static uint16 VAR_ui16_Adc_RES_Buffer_CosLo[32U] __attribute__ ((asection(".data.FIFO_RDC_COSLo_BUFFER","f=aw")));
static uint16 VAR_ui16_Adc_RES_Buffer_Sin[32U] __attribute__ ((asection(".data.FIFO_RDC_SIN_BUFFER","f=aw")));
static uint16 VAR_ui16_Adc_RES_Buffer_SinLo[32U] __attribute__ ((asection(".data.FIFO_RDC_SINLo_BUFFER","f=aw")));

extern uint8 Uart_Rx_Buffer[UARTx_RXDATA_NUM];

extern sint16 VAR_TpcMot_tSttrTempFlt_u16;


#pragma section ".data.CPU1_32"
uint32 ui32_Cos_RegAddr,ui32_CosLo_RegAddr,ui32_Sin_RegAddr,ui32_SinLo_RegAddr;


uint8  DMA_buffer_flag=0;
boolean VAR_L2_Sample_flag_b=0;
uint8  DMA_Read_Buffer_Count=0;
sint16 DMA_Cos_buffer[64];
sint32 VAR_DMA_Cos_Max_u16[64];
sint16 DMA_Cos_Min[64];
sint16 DMA_Sin_buffer[64];
sint32 VAR_DMA_Sin_Max_u16[64];
sint16 DMA_Sin_Min[64];
uint16 VAR_FS_DMA_Cos_u16;
uint16 VAR_FS_DMA_Sin_u16;
float32 FS_NvM_AngOfst_f32;
FSOutType L2Sampling;

#if (USE_RSLVEXC_ADC_RAW == 1)
Adc_ValueGroupType VAR_FS_VADC_RSLVEXC_u16[2];
#else
float32 VAR_FS_RSLVEXC_P_f32;
float32 VAR_FS_RSLVEXC_N_f32;
float32 VAR_FS_RSLVEXC_f32;
#endif

uint8 VAR_FS_React_u8;
uint8 L2_FS_Count;
uint8 Port_Crash_Signal;
uint8 VAR_FS_RDC_Counter_u8=0;
uint8 VAR_FS_RDC_Quadrant_u8;
uint16 VAR_DMA_Buffer_Cos[32U];
uint16 VAR_DMA_Buffer_CosLo[32U];
uint16 VAR_DMA_Buffer_Sin[32U];
uint16 VAR_DMA_Buffer_SinLo[32U];
uint16 VAR_VADC_RDC_ISR_offset_u16=900;
sint16 VAR_DMA_Buffer_SinAdd[32U];
sint16 VAR_DMA_Buffer_CosAdd[32U];
sint32 DMA_Cos_Total;
sint32 DMA_Sin_Total;
uint8  RDC_RD_Count;
uint16 VADC_RDC_offset_old=0;
uint16 VADC_RDC_ISR_offset_old=0;
uint8 DMA_Buffer_Reset_flag=0;
sint16 FS_Dsadc_Buffer_Cur[3] = {0};
uint32 VCU04_Data_H;
uint32 VCU04_Data_L;
float32 VCU04_Singnal_TrqSetP;
float32 VCU04_Singnal_NSetP;
uint16 VCU04_Singnal_ModeReq;
uint16 VCU04_Singnal_DchgRq;
uint16 VCU04_Singnal_Crash;
uint32 BMS01_Data_L;
uint16 BMS01_Singnal_BattVolt;
uint16 FS_AN43_18VLS_G5_3;
uint16 FS_VDD5_EPP_G5_6;
float32 FS_HvMcu_H_Udc_Value;
uint8 FS_HvMcu_L_Udc_Value;
float32 FS_AN3_UBRWIDE_G0_3;
float32 FS_AN7_UBRNARR_G0_7;
float32 FS_AN33_UB_SBC_G4_1;
float32 FS_AN27_18VHS_G3_3;
float32 FS_AN11_3V3CPLD_G3_3;
float32 FS_AN19_1V8CPLD_G2_3;

FSINType rtb_BusConversion_InsertedFor;
FSOutType SWC_L2Sampling;

#if (FIXME_GET_PWM_PERIOD_DUTYCYCLE == 1)
Icu_17_GtmCcu6_DutyCycleType FS_3phPWMUL_Duty;
Icu_17_GtmCcu6_DutyCycleType FS_3phPWMVL_Duty;
Icu_17_GtmCcu6_DutyCycleType FS_3phPWMWL_Duty;
#else
float32 VAR_FS_3phPWMUH_Duty_f32;		/* PWM Duty signal */
float32 VAR_FS_3phPWMUL_Duty_f32;		/* PWM Duty signal */
float32 VAR_FS_3phPWMVH_Duty_f32;		/* PWM Duty signal */
float32 VAR_FS_3phPWMVL_Duty_f32;		/* PWM Duty signal */
float32 VAR_FS_3phPWMWH_Duty_f32;		/* PWM Duty signal */
float32 VAR_FS_3phPWMWL_Duty_f32;		/* PWM Duty signal */
float32 VAR_FS_3phPWMUH_Period_f32;		/* PWM Period signal */
float32 VAR_FS_3phPWMUL_Period_f32;		/* PWM Period signal */
float32 VAR_FS_3phPWMVH_Period_f32;		/* PWM Period signal */
float32 VAR_FS_3phPWMVL_Period_f32;		/* PWM Period signal */
float32 VAR_FS_3phPWMWH_Period_f32;		/* PWM Period signal */
float32 VAR_FS_3phPWMWL_Period_f32;		/* PWM Period signal */
#endif

float32 VAR_FS_DycU_f32 = 0;
float32 VAR_FS_DycV_f32 = 0;
float32 VAR_FS_DycW_f32 = 0;
uint32 FS_DycU_Peroid = 0;
uint32 FS_DycV_Peroid = 0;
uint32 FS_DycW_Peroid = 0;
uint32 FS_DycU_Peroid_Pre = 0;
uint32 FS_DycV_Peroid_Pre = 0;
uint32 FS_DycW_Peroid_Pre = 0;
uint8 FS_DycU_Level_Pre = 0;
uint8 FS_DycV_Level_Pre = 0;
uint8 FS_DycW_Level_Pre = 0;
float32 FS_PwrTrq_iU_f32 = 0;
float32 FS_PwrTrq_iV_f32 = 0;
float32 FS_PwrTrq_iW_f32 = 0;
float32 FS_PwrTrq_DycU_f32 = 0;
float32 FS_PwrTrq_DycV_f32 = 0;
float32 FS_PwrTrq_DycW_f32 = 0;
float32 FS_PwrTrq_HighVol_f32 = 0;

#pragma section


#pragma section ".rodata.Calib_32"

const volatile uint8 CAL_DMA_buffer_flag_u8 = 0U;
const volatile uint16 CAL_VADC_RDC_offset_u16=40;
const volatile uint16 CAL_VADC_RDC_ISR_offset_u16=900;

#pragma section

/*******************************************************************************
 **                  Static Local Function Declaration            		      **
 *******************************************************************************/

/*******************************************************************************
 **                 		  Function Source Code            		              **
 *******************************************************************************/

/*******************************************************************************
 ** Function Name	: Rdc_FS_init
 ** Parameter[in] 	: None
 ** Parameter[out] 	: None
 ** Return Value	  	: None
 ** Note	  			: None
 ** Description	  	: Rdc Function safety initialize
 *******************************************************************************/
void Rdc_FS_init (void)
{


	/*use DMA to transport resolver AD data*/
	ui32_Cos_RegAddr = \
			(uint32)&MODULE_VADC.G[ADC_Cos_ADC_HW_SEL].RES[ADC_Cos_ADC_CH_SEL].U;
	ui32_CosLo_RegAddr = \
			(uint32)&MODULE_VADC.G[ADC_CosLo_ADC_HW_SEL].RES[ADC_CosLo_ADC_CH_SEL].U;
	ui32_Sin_RegAddr = \
			(uint32)&MODULE_VADC.G[ADC_Sin_ADC_HW_SEL].RES[ADC_Sin_ADC_CH_SEL].U;
	ui32_SinLo_RegAddr= \
			(uint32)&MODULE_VADC.G[ADC_SinLo_ADC_HW_SEL].RES[ADC_SinLo_ADC_CH_SEL].U;

	/*Enable the lowest priority DMA channel to interrupt*/
	Mcal_DmaEnableIntr(ADC_Sin_DMA_CHANNEL);

	/*start HW trigger DMA transport*/
	Dma_StartHwTransaction(ADC_CosLo_DMA_CHANNEL,(uint32*)ui32_CosLo_RegAddr,\
			(uint32*)&VAR_ui16_Adc_RES_Buffer_CosLo[0U],ADC_DMA_CHANNEL_TCOUNT);
	Dma_StartHwTransaction(ADC_Cos_DMA_CHANNEL,(uint32*)ui32_Cos_RegAddr,\
			(uint32*)&VAR_ui16_Adc_RES_Buffer_Cos[0U],ADC_DMA_CHANNEL_TCOUNT);
	Dma_StartHwTransaction(ADC_Sin_DMA_CHANNEL,(uint32*)ui32_Sin_RegAddr,\
			(uint32*)&VAR_ui16_Adc_RES_Buffer_Sin[0U],ADC_DMA_CHANNEL_TCOUNT);
	Dma_StartHwTransaction(ADC_SinLo_DMA_CHANNEL,(uint32*)ui32_SinLo_RegAddr,\
			(uint32*)&VAR_ui16_Adc_RES_Buffer_SinLo[0U],ADC_DMA_CHANNEL_TCOUNT);

	//	Adc_SetupResultBuffer(AdcConf_AdcGroup_RslvExc_Group,&VAR_FS_VADC_RSLVEXC_u16[0U]);
	//	Adc_EnableHardwareTrigger(AdcConf_AdcGroup_RslvExc_Group);
	//	Adc_EnableGroupNotification(AdcConf_AdcGroup_RslvExc_Group);
}

/*******************************************************************************
 ** Function Name	: FS_SetTimerTrigger_init
 ** Parameter[in] 	: None
 ** Parameter[out] 	: None
 ** Return Value	  	: None
 ** Note	  			: None
 ** Description	  	: Rdc Function safety initialize
 *******************************************************************************/
void FS_SetTimerTrigger_init (void)
{
	/*  use for VADC sample RDC    */
	Gtm_DisableTomChannel(IOHWAB_ADC_RDC_ISR_TIMER_TRIGGER_GTM_MODULE,\
			IOHWAB_ADC_RDC_ISR_TIMER_TRIGGER_GTM_CHANNEL_Ref_CH12);
	Gtm_DisableTomChannel(IOHWAB_ADC_RDC_ISR_TIMER_TRIGGER_GTM_MODULE,\
			IOHWAB_ADC_RDC_ISR_TIMER_TRIGGER_GTM_CHANNEL_CH13);
	Gtm_DisableTomChannel(IOHWAB_L2_FS_ISR_TIMER_TRIGGER_GTM_MODULE,\
			IOHWAB_L2_FS_ISR_TIMER_TRIGGER_GTM_CHANNEL_Ref_CH1);
	Gtm_DisableTomChannel(IOHWAB_L2_FS_ISR_TIMER_TRIGGER_GTM_MODULE,\
			IOHWAB_L2_FS_ISR_TIMER_TRIGGER_GTM_CHANNEL_Ref_CH2);
	Gtm_DisableAtomChannel(IOHWAB_ADC_RDC_TIMER_TRIGGER_GTM_MODULE,\
			IOHWAB_ADC_RDC_TIMER_TRIGGER_GTM_CHANNEL_Ref_CH3);
	Gtm_DisableAtomChannel(IOHWAB_ADC_RDC_TIMER_TRIGGER_GTM_MODULE,\
			IOHWAB_ADC_RDC_TIMER_TRIGGER_GTM_CHANNEL_CH4);

	Gtm_SetTomCounterCn0(IOHWAB_ADC_RDC_ISR_TIMER_TRIGGER_GTM_MODULE,\
			IOHWAB_ADC_RDC_ISR_TIMER_TRIGGER_GTM_CHANNEL_Ref_CH12,0U);
	Gtm_SetTomCounterCn0(IOHWAB_ADC_RDC_ISR_TIMER_TRIGGER_GTM_MODULE,\
			IOHWAB_ADC_RDC_ISR_TIMER_TRIGGER_GTM_CHANNEL_CH13,0U);

	Gtm_SetAtomCounterCn0(IOHWAB_ADC_RDC_TIMER_TRIGGER_GTM_MODULE,\
			IOHWAB_ADC_RDC_TIMER_TRIGGER_GTM_CHANNEL_Ref_CH3,0U);
	Gtm_SetAtomCounterCn0(IOHWAB_ADC_RDC_TIMER_TRIGGER_GTM_MODULE,\
			IOHWAB_ADC_RDC_TIMER_TRIGGER_GTM_CHANNEL_CH4,0U);

	/*Use for VADC sample RDC and VADC RDC ISR*/
	Gtm_SetTomShadowValSr1(IOHWAB_ADC_RDC_ISR_TIMER_TRIGGER_GTM_MODULE,\
			IOHWAB_ADC_RDC_ISR_TIMER_TRIGGER_GTM_CHANNEL_Ref_CH12,5120);
	Gtm_SetTomShadowValSr1(IOHWAB_L2_FS_ISR_TIMER_TRIGGER_GTM_MODULE,\
			IOHWAB_L2_FS_ISR_TIMER_TRIGGER_GTM_CHANNEL_Ref_CH1,5000);
	Gtm_SetTomShadowValSr1(IOHWAB_L2_FS_ISR_TIMER_TRIGGER_GTM_MODULE,\
			IOHWAB_L2_FS_ISR_TIMER_TRIGGER_GTM_CHANNEL_Ref_CH2,3125);
	Gtm_SetTomShadowValSr0(IOHWAB_ADC_RDC_ISR_TIMER_TRIGGER_GTM_MODULE,\
			IOHWAB_ADC_RDC_ISR_TIMER_TRIGGER_GTM_CHANNEL_Ref_CH12,10240);
	Gtm_SetTomShadowValSr0(IOHWAB_L2_FS_ISR_TIMER_TRIGGER_GTM_MODULE,\
			IOHWAB_L2_FS_ISR_TIMER_TRIGGER_GTM_CHANNEL_Ref_CH1,10000);
	Gtm_SetTomShadowValSr0(IOHWAB_L2_FS_ISR_TIMER_TRIGGER_GTM_MODULE,\
			IOHWAB_L2_FS_ISR_TIMER_TRIGGER_GTM_CHANNEL_Ref_CH2,6250);
	Gtm_SetTomShadowValSr1(IOHWAB_ADC_RDC_ISR_TIMER_TRIGGER_GTM_MODULE,\
			IOHWAB_ADC_RDC_ISR_TIMER_TRIGGER_GTM_CHANNEL_CH13,0);
	Gtm_SetTomShadowValSr0(IOHWAB_ADC_RDC_ISR_TIMER_TRIGGER_GTM_MODULE,\
			IOHWAB_ADC_RDC_ISR_TIMER_TRIGGER_GTM_CHANNEL_CH13,20);
	Gtm_SetAtomShadowValSr1(IOHWAB_ADC_RDC_TIMER_TRIGGER_GTM_MODULE,\
			IOHWAB_ADC_RDC_TIMER_TRIGGER_GTM_CHANNEL_Ref_CH3,160);
	Gtm_SetAtomShadowValSr0(IOHWAB_ADC_RDC_TIMER_TRIGGER_GTM_MODULE,\
			IOHWAB_ADC_RDC_TIMER_TRIGGER_GTM_CHANNEL_Ref_CH3,320);
	Gtm_SetAtomShadowValSr1(IOHWAB_ADC_RDC_TIMER_TRIGGER_GTM_MODULE,\
			IOHWAB_ADC_RDC_TIMER_TRIGGER_GTM_CHANNEL_CH4,0);
	Gtm_SetAtomShadowValSr0(IOHWAB_ADC_RDC_TIMER_TRIGGER_GTM_MODULE,\
			IOHWAB_ADC_RDC_TIMER_TRIGGER_GTM_CHANNEL_CH4,20);

	Gtm_EnableTomChannel(IOHWAB_ADC_RDC_ISR_TIMER_TRIGGER_GTM_MODULE,\
			IOHWAB_ADC_RDC_ISR_TIMER_TRIGGER_GTM_CHANNEL_Ref_CH12);
	Gtm_EnableTomChannel(IOHWAB_ADC_RDC_ISR_TIMER_TRIGGER_GTM_MODULE,\
			IOHWAB_ADC_RDC_ISR_TIMER_TRIGGER_GTM_CHANNEL_CH13);
	Gtm_EnableTomChannel(IOHWAB_L2_FS_ISR_TIMER_TRIGGER_GTM_MODULE,\
			IOHWAB_L2_FS_ISR_TIMER_TRIGGER_GTM_CHANNEL_Ref_CH1);
	Gtm_EnableTomChannel(IOHWAB_L2_FS_ISR_TIMER_TRIGGER_GTM_MODULE,\
			IOHWAB_L2_FS_ISR_TIMER_TRIGGER_GTM_CHANNEL_Ref_CH2);

	Gtm_EnableAtomChannel(IOHWAB_ADC_RDC_TIMER_TRIGGER_GTM_MODULE,\
			IOHWAB_ADC_RDC_TIMER_TRIGGER_GTM_CHANNEL_Ref_CH3);
	Gtm_EnableAtomChannel(IOHWAB_ADC_RDC_TIMER_TRIGGER_GTM_MODULE,\
			IOHWAB_ADC_RDC_TIMER_TRIGGER_GTM_CHANNEL_CH4);

}

/*******************************************************************************
 ** Function Name	: FS_Dsadc_SampleVW_Init
 ** Parameter[in] 	: None
 ** Parameter[out] 	: None
 ** Return Value	  	: None
 ** Note	  			: None
 ** Description	  	: Dsadc SampleVW Function safety initialize
 *******************************************************************************/
void FS_Dsadc_SampleVW_Init (void)
{
	Dsadc_StartChannel(Dsadc_Channel1_RunCt | Dsadc_Channel1_Mod_RunCt);
	Dsadc_StartChannel(Dsadc_Channel2_RunCt | Dsadc_Channel2_Mod_RunCt);
	Dsadc_StartChannel(Dsadc_Channel3_RunCt | Dsadc_Channel3_Mod_RunCt);
}

/*******************************************************************************
 ** Function Name	: FS_Dsadc_SampleVW_Get
 ** Parameter[in] 	: None
 ** Parameter[out] 	: None
 ** Return Value	  	: None
 ** Note	  			: None
 ** Description	  	: Dsadc SampleVW Function safety Get
 *******************************************************************************/
void FS_Dsadc_SampleVW_Get (void)
{
	FS_Dsadc_Buffer_Cur[0] = Dsadc_GetMainResult(Dsadc_ChannelId_1);
	FS_Dsadc_Buffer_Cur[1] = Dsadc_GetMainResult(Dsadc_ChannelId_2);
	FS_Dsadc_Buffer_Cur[2] = Dsadc_GetMainResult(Dsadc_ChannelId_3);
}


/*******************************************************************************
 ** Function Name	: DMA_Buffer_Ptr_Reset
 ** Parameter[in] 	: None
 ** Parameter[out] 	: None
 ** Return Value	  	: None
 ** Note	  			: None
 ** Description	  	: Reset the DMA Buffer Address to the start of the VAR_ui16_Adc_RES_Buffer_SinLo
 *******************************************************************************/
void DMA_DstBuffer_Ptr_Reset (void)
{

	/*start HW trigger DMA transport*/
	Dma_StartHwTransaction(ADC_CosLo_DMA_CHANNEL,(uint32*)&MODULE_VADC.G[ADC_CosLo_ADC_HW_SEL].RES[ADC_CosLo_ADC_CH_SEL].U,\
			(uint32*)&VAR_ui16_Adc_RES_Buffer_CosLo[0U],ADC_DMA_CHANNEL_TCOUNT);
	Dma_StartHwTransaction(ADC_Cos_DMA_CHANNEL,(uint32*)&MODULE_VADC.G[ADC_Cos_ADC_HW_SEL].RES[ADC_Cos_ADC_CH_SEL].U,\
			(uint32*)&VAR_ui16_Adc_RES_Buffer_Cos[0U],ADC_DMA_CHANNEL_TCOUNT);
	Dma_StartHwTransaction(ADC_Sin_DMA_CHANNEL,(uint32*)&MODULE_VADC.G[ADC_Sin_ADC_HW_SEL].RES[ADC_Sin_ADC_CH_SEL].U,\
			(uint32*)&VAR_ui16_Adc_RES_Buffer_Sin[0U],ADC_DMA_CHANNEL_TCOUNT);
	Dma_StartHwTransaction(ADC_SinLo_DMA_CHANNEL,(uint32*)&MODULE_VADC.G[ADC_SinLo_ADC_HW_SEL].RES[ADC_SinLo_ADC_CH_SEL].U,\
			(uint32*)&VAR_ui16_Adc_RES_Buffer_SinLo[0U],ADC_DMA_CHANNEL_TCOUNT);

}

/*******************************************************************************
 ** Function Name	: FS_VADC_RDC_offset
 ** Parameter[in] 	: None
 ** Parameter[out] 	: None
 ** Return Value	  	: None
 ** Note	  			: None
 ** Description	  	: FS_VADC_RDC_offset
 *******************************************************************************/
void FS_VADC_RDC_offset(void)
{
	/*
	while(VADC_RDC_ISR_offset_old!=CAL_VADC_RDC_ISR_offset_u16)
    {


    	VADC_RDC_ISR_offset_old=CAL_VADC_RDC_ISR_offset_u16;

//    	SuspendAllInterrupts();

		Gtm_SetTomShadowValSr1(IOHWAB_ADC_RDC_ISR_TIMER_TRIGGER_GTM_MODULE,\
				IOHWAB_ADC_RDC_ISR_TIMER_TRIGGER_GTM_CHANNEL_CH13,0);
		Gtm_SetTomShadowValSr0(IOHWAB_ADC_RDC_ISR_TIMER_TRIGGER_GTM_MODULE,\
				IOHWAB_ADC_RDC_ISR_TIMER_TRIGGER_GTM_CHANNEL_CH13,CAL_VADC_RDC_ISR_offset_u16);
		DMA_Buffer_Reset_flag=0;
		DMA_DstBuffer_Ptr_Reset();

//		ResumeAllInterrupts();
    }
	 */
	while(VADC_RDC_offset_old!=CAL_VADC_RDC_offset_u16)
	{
		VADC_RDC_offset_old=CAL_VADC_RDC_offset_u16;
		Gtm_SetAtomShadowValSr1(IOHWAB_ADC_RDC_TIMER_TRIGGER_GTM_MODULE,\
				IOHWAB_ADC_RDC_TIMER_TRIGGER_GTM_CHANNEL_CH4,0);
		Gtm_SetAtomShadowValSr0(IOHWAB_ADC_RDC_TIMER_TRIGGER_GTM_MODULE,\
				IOHWAB_ADC_RDC_TIMER_TRIGGER_GTM_CHANNEL_CH4,CAL_VADC_RDC_offset_u16);
	}
}

/*******************************************************************************
 ** Function Name	: FS_VADC_RDC_offsetCal
 ** Parameter[in] 	: None
 ** Parameter[out] 	: None
 ** Return Value	  	: None
 ** Note	  			: None
 ** Description	  	: Function safety interrupt offset self calibration
 *******************************************************************************/
uint16 VAR_DMA_Buffer_Sin_Cal[32U];
uint16 VAR_DMA_Buffer_SinLo_Cal[32U];
uint16 Cal_count;
void FS_VADC_RDC_offsetCal(void)
{
	uint8 i;
	Cal_count++;
	for(i=0;i<=31;i++)
	{
		VAR_DMA_Buffer_Sin_Cal[i]=VAR_DMA_Buffer_Sin[i];
		VAR_DMA_Buffer_SinLo_Cal[i]=VAR_DMA_Buffer_SinLo[i];
		VAR_DMA_Buffer_SinAdd[i]=VAR_DMA_Buffer_Sin[i]-VAR_DMA_Buffer_SinLo[i];
		VAR_DMA_Buffer_CosAdd[i]=VAR_DMA_Buffer_Cos[i]-VAR_DMA_Buffer_CosLo[i];
	}

	if((-20<VAR_DMA_Buffer_SinAdd[0])&&(VAR_DMA_Buffer_SinAdd[0]<20)&&\
			(-20<VAR_DMA_Buffer_SinAdd[1])&&(VAR_DMA_Buffer_SinAdd[1]<20)&&\
			(-20<VAR_DMA_Buffer_SinAdd[2])&&(VAR_DMA_Buffer_SinAdd[2]<20))
	{

		if((VAR_FS_RDC_Quadrant_u8==1)||(VAR_FS_RDC_Quadrant_u8==4))
		{
			for(i=0;i<=31;i++)
			{
				if((VAR_DMA_Buffer_CosAdd[i]<0)&&(VAR_DMA_Buffer_CosAdd[i+1]>=0))
				{
					if((-VAR_DMA_Buffer_CosAdd[i])<VAR_DMA_Buffer_CosAdd[i+1])
					{
						VAR_VADC_RDC_ISR_offset_u16=i*320;
					}
					else
					{
						VAR_VADC_RDC_ISR_offset_u16=(i+1)*320;
					}
					break;
				}

			}
		}
		else
		{
			for(i=0;i<=31;i++)
			{
				if((VAR_DMA_Buffer_CosAdd[i]>0)&&(VAR_DMA_Buffer_CosAdd[i+1]<=0))
				{
					if(VAR_DMA_Buffer_CosAdd[i]<(-VAR_DMA_Buffer_CosAdd[i+1]))
					{
						VAR_VADC_RDC_ISR_offset_u16=i*320;
					}
					else
					{
						VAR_VADC_RDC_ISR_offset_u16=(i+1)*320;
					}
					break;
				}

			}
		}
	}
	else
	{
		if((VAR_FS_RDC_Quadrant_u8==1)||(VAR_FS_RDC_Quadrant_u8==2))
		{
			for(i=0;i<=31;i++)
			{
				if((VAR_DMA_Buffer_SinAdd[i]<0)&&(VAR_DMA_Buffer_SinAdd[i+1]>=0))
				{
					if((-VAR_DMA_Buffer_SinAdd[i])<VAR_DMA_Buffer_SinAdd[i+1])
					{
						VAR_VADC_RDC_ISR_offset_u16=i*320;
					}
					else
					{
						VAR_VADC_RDC_ISR_offset_u16=(i+1)*320;
					}
					break;
				}

			}
		}
		else
		{
			for(i=0;i<=31;i++)
			{
				if((VAR_DMA_Buffer_SinAdd[i]>0)&&(VAR_DMA_Buffer_SinAdd[i+1]<=0))
				{
					if(VAR_DMA_Buffer_SinAdd[i]<(-VAR_DMA_Buffer_SinAdd[i+1]))
					{
						VAR_VADC_RDC_ISR_offset_u16=i*320;
					}
					else
					{
						VAR_VADC_RDC_ISR_offset_u16=(i+1)*320;
					}
					break;
				}

			}
		}

	}
	Gtm_SetTomShadowValSr1(IOHWAB_ADC_RDC_ISR_TIMER_TRIGGER_GTM_MODULE,\
			IOHWAB_ADC_RDC_ISR_TIMER_TRIGGER_GTM_CHANNEL_CH13,0);
	Gtm_SetTomShadowValSr0(IOHWAB_ADC_RDC_ISR_TIMER_TRIGGER_GTM_MODULE,\
			IOHWAB_ADC_RDC_ISR_TIMER_TRIGGER_GTM_CHANNEL_CH13,VAR_VADC_RDC_ISR_offset_u16);
}
/*******************************************************************************
 ** Function Name	: Rdc_FS_RslPos_QuaJudge
 ** Parameter[in] 	: None
 ** Parameter[out] 	: None
 ** Return Value	  	: None
 ** Note	  			: None
 ** Description	  	: Motor initial resolver position quadrant judgement
 *******************************************************************************/
void Rdc_FS_RslPos_QuaJudge(void)
{
	uint8 sinsdcapval;
	uint8 cossdcapval;
	uint8 sinsdcapstate;
	uint8 cossdcapstate;
	uint8 sdcapstate;
	sinsdcapval=Dsadc_GetSdcapVal(Dsadc_ChannelId_4);
	cossdcapval=Dsadc_GetSdcapVal(Dsadc_ChannelId_5);
	if((sinsdcapval>=1)&&(sinsdcapval<=4))
	{
		sinsdcapstate=1;                 //SinSDCAP is about 3
	}
	else
	{
		sinsdcapstate=2;
	}
	if((cossdcapval>=1)&&(cossdcapval<=4))
	{
		cossdcapstate=1;                //CosSDCAP is about 3
	}
	else
	{
		cossdcapstate=2;
	}
	sdcapstate=(sinsdcapstate|(cossdcapstate<<2));
	switch(sdcapstate)
	{
	case 5:
	{
		VAR_FS_RDC_Quadrant_u8=1;
	}
	break;
	case 9:
	{
		VAR_FS_RDC_Quadrant_u8=2;
	}
	break;
	case 10:
	{
		VAR_FS_RDC_Quadrant_u8=3;
	}
	break;
	case 6:
	{
		VAR_FS_RDC_Quadrant_u8=4;
	}
	break;
	default:
	{
	}
	break;
	}
}


/*******************************************************************************
 ** Function Name	: Rdc_FS_ISR_init
 ** Parameter[in] 	: None
 ** Parameter[out] 	: None
 ** Return Value	  	: None
 ** Note	  			: None
 ** Description	  	: Rdc SinLo buffer interrupt init
 *******************************************************************************/
void Rdc_FS_ISR_init (void)
{
	SRC_VADCG5SR0.U &= ( 0x7FFF0000);
	SRC_VADCG3SR0.U &= ( 0x7FFF0000);
	IRQ_SFR_MODIFY32 (SRC_VADCG5SR0.U,  IRQ_CLEAR_MASK , \
			(IRQ_ADC5_SR0_TOS | IRQ_ADC5_SR0_PRIO));
	IRQ_SFR_MODIFY32 (SRC_VADCG3SR0.U,  IRQ_CLEAR_MASK , \
			(IRQ_ADC3_SR0_TOS | IRQ_ADC3_SR0_PRIO));
}


/*******************************************************************************
 ** Function Name	: Rdc_FS_DMA_ISR_init
 ** Parameter[in] 	: None
 ** Parameter[out] 	: None
 ** Return Value	  	: None
 ** Note	  			: None
 ** Description	  	: Rdc DMA buffer interrupt init
 *******************************************************************************/
void Rdc_FS_DMA_ISR_init (void)
{
	SRC_DMACH42.U &= ( 0x7FFF0000);
	SRC_DMACH43.U &= ( 0x7FFF0000);
	SRC_DMACH44.U &= ( 0x7FFF0000);
	SRC_DMACH45.U &= ( 0x7FFF0000);

	IRQ_SFR_MODIFY32 (SRC_DMACH42.U,  IRQ_CLEAR_MASK , \
			(IRQ_DMA_CHANNEL42_SR_TOS | 0x10));
	IRQ_SFR_MODIFY32 (SRC_DMACH43.U,  IRQ_CLEAR_MASK , \
			(IRQ_DMA_CHANNEL43_SR_TOS | 0x05));
	IRQ_SFR_MODIFY32 (SRC_DMACH44.U,  IRQ_CLEAR_MASK , \
			(IRQ_DMA_CHANNEL44_SR_TOS | 0x12));
	IRQ_SFR_MODIFY32 (SRC_DMACH45.U,  IRQ_CLEAR_MASK , \
			(IRQ_DMA_CHANNEL45_SR_TOS | 0x13));
}

/*******************************************************************************
 ** Function Name	: Rdc_FS_DMA_Buffer_RD_Result
 ** Parameter[in] 	: None
 ** Parameter[out] 	: None
 ** Return Value	  	: None
 ** Note	  			: None
 ** Description	  	: Reader DMA buffer and resolve the data
 *******************************************************************************/
void Rdc_FS_DMA_Buffer_RD_Result (void)
{
	uint8 i;

	if(VAR_FS_RDC_Counter_u8<4)
	{
		VAR_FS_RDC_Counter_u8++;
	}
	if(VAR_FS_RDC_Counter_u8==1)
	{
		Rdc_FS_RslPos_QuaJudge();
		DMA_DstBuffer_Ptr_Reset();
	}

	if((VAR_FS_RDC_Counter_u8==3))
	{
		DMA_DstBuffer_Ptr_Reset();
	}

	Rdc_DMA_Buffer_RD();

	if(VAR_FS_RDC_Counter_u8==2)
	{
		FS_VADC_RDC_offsetCal();
	}

	DMA_Cos_Total=0;
	DMA_Sin_Total=0;

	for(i=0;i<32;i++)
	{
		if(i<16)
		{
			DMA_Cos_Total+=(VAR_DMA_Buffer_Cos[i]-VAR_DMA_Buffer_CosLo[i]);
			DMA_Sin_Total+=(VAR_DMA_Buffer_Sin[i]-VAR_DMA_Buffer_SinLo[i]);
		}
		else
		{
			DMA_Cos_Total+=(VAR_DMA_Buffer_CosLo[i]-VAR_DMA_Buffer_Cos[i]);
			DMA_Sin_Total+=(VAR_DMA_Buffer_SinLo[i]-VAR_DMA_Buffer_Sin[i]);
		}

	}

	/*test code*/
	if(DMA_Read_Buffer_Count<64)
	{
		VAR_DMA_Cos_Max_u16[DMA_Read_Buffer_Count] = DMA_Cos_Total;
		VAR_DMA_Sin_Max_u16[DMA_Read_Buffer_Count] = DMA_Sin_Total;
		DMA_Read_Buffer_Count++;

	}
	set_L2Sampling_RslvSin(DMA_Sin_Total);
	set_L2Sampling_RslvCos(DMA_Cos_Total);
}

/*******************************************************************************
 ** Function Name	: Rdc_DMA_Buffer_RD
 ** Parameter[in] 	: None
 ** Parameter[out] 	: None
 ** Return Value	  	: None
 ** Note	  			: None
 ** Description	  	: Reader DMA buffer
 *******************************************************************************/
void Rdc_DMA_Buffer_RD (void)
{
	uint8 i;
	for(i=0;i<32;i++)
	{
		VAR_DMA_Buffer_Cos[i]=VAR_ui16_Adc_RES_Buffer_Cos[i];
		VAR_DMA_Buffer_CosLo[i]=VAR_ui16_Adc_RES_Buffer_CosLo[i];
		VAR_DMA_Buffer_Sin[i]=VAR_ui16_Adc_RES_Buffer_Sin[i];
		VAR_DMA_Buffer_SinLo[i]=VAR_ui16_Adc_RES_Buffer_SinLo[i];
	}


}


/*******************************************************************************
 ** Function Name	: NvM_AngOfst_Read
 ** Parameter[in] 	: None
 ** Parameter[out] 	: None
 ** Return Value	  	: None
 ** Note	  			: None
 ** Description	  	: Read the RDC AngAutoClbOffset
 *******************************************************************************/
void NvM_AngOfst_Read (void)
{
	FS_NvM_AngOfst_f32 = SnapshotCan_DefConfigType_S.OffsetRamInfoPtr->OffsetValue;
}

/******************************************************************************
 ** Function Name	: Port_Crash_Read
 ** Parameter[in] 	: None
 ** Parameter[out] 	: None
 ** Return Value	  	: None
 ** Note	  			: None
 ** Description	  	: Read the Crash Signal
 ******************************************************************************/
void Port_Crash_Read (void)
{
	Port_Crash_Signal = P23_IN.B.P2;
}

/*******************************************************************************
 ** Function Name	: VCU04_Data_Read
 ** Parameter[in] 	: None
 ** Parameter[out] 	: None
 ** Return Value	  	: None
 ** Note	  			: None
 ** Description	  	: Read the VCU04 signal in Can0
 *******************************************************************************/
void VCU04_Data_Read (void)
{
	VCU04_Data_H= CAN_MODATAH1.U;
	VCU04_Data_L= CAN_MODATAL1.U;

	VCU04_Singnal_TrqSetP = (float32)((((VCU04_Data_L&0xfff00000)>>20)|(VCU04_Data_H&0x0000000f)<<12)-32768)*0.1;
	VCU04_Singnal_NSetP = (float32)((VCU04_Data_L&0x0000ffff)-32768);
	VCU04_Singnal_ModeReq =(uint16)((VCU04_Data_L&0x000f0000)>>16);
	//	VCU04_Singnal_DchgRq = (uint16)(VCU04_Data_L&0x000000ff);



}

/*******************************************************************************
 ** Function Name	: BMS01_Data_Read
 ** Parameter[in] 	: None
 ** Parameter[out] 	: None
 ** Return Value	  	: None
 ** Note	  			: None
 ** Description	  	: Read the BMS01 BattUVolt signal in Can0
 *******************************************************************************/

void BMS01_Data_Read(void)
{
	BMS01_Data_L= CAN_MODATAL3.U;
	BMS01_Singnal_BattVolt = (uint16) ((BMS01_Data_L&0x03ff0000)>>16);
}


/*******************************************************************************
 ** Function Name	: HvMcu_Data_Read
 ** Parameter[in] 	: None
 ** Parameter[out] 	: None
 ** Return Value	  	: None
 ** Note	  			: None
 ** Description	  	: Read the HVMCU Udc value
 *******************************************************************************/
void HvMcu_Data_Read (void)
{
	FS_HvMcu_H_Udc_Value   = ((Uart_Rx_Buffer[1]|(Uart_Rx_Buffer[2]<<7U))&0x0FFF)*0.1507;
	FS_HvMcu_L_Udc_Value   = (Uart_Rx_Buffer[5]|(Uart_Rx_Buffer[6]<<7U))&0x0FFF;

}

/*******************************************************************************
 ** Function Name	: Power_Data_Read
 ** Parameter[in] 	: None
 ** Parameter[out] 	: None
 ** Return Value	  	: None
 ** Note	  			: None
 ** Description	  	: Read the VADC sample Power value
 *******************************************************************************/
void Power_Data_Read (void)
{
	FS_AN43_18VLS_G5_3 = (uint16)(MODULE_VADC.G[5].RES[3].U);
	FS_VDD5_EPP_G5_6   = (uint16)(MODULE_VADC.G[5].RES[6].U);
	FS_AN3_UBRWIDE_G0_3 = ((uint16)(MODULE_VADC.G[0].RES[3].U)*FS_AN3_UBRWIDE_G0_3_GAIN);
	FS_AN7_UBRNARR_G0_7 = ((uint16)(MODULE_VADC.G[0].RES[7].U)*FS_AN7_UBRNARR_G0_7_GAIN);
	FS_AN33_UB_SBC_G4_1 = ((uint16)(MODULE_VADC.G[4].RES[1].U)*FS_AN33_UB_SBC_G4_1_GAIN);
	FS_AN27_18VHS_G3_3 = ((uint16)(MODULE_VADC.G[3].RES[3].U)*FS_AN27_18VHS_G3_3_GAIN);
	FS_AN11_3V3CPLD_G3_3 = ((uint16)(MODULE_VADC.G[1].RES[3].U)*FS_AN11_3V3CPLD_G3_3_GAIN);
	FS_AN19_1V8CPLD_G2_3 = ((uint16)(MODULE_VADC.G[2].RES[3].U)*FS_AN19_1V8CPLD_G2_3_GAIN);

}


/*******************************************************************************
 ** Function Name	: FS_RSLVEXCN_L2Sample
 ** Parameter[in] 	: None
 ** Parameter[out] 	: None
 ** Return Value	  	: None
 ** Note	  			: None
 ** Description	  	: L2 Function safety get RSLVEXCN sample
 *******************************************************************************/
void FS_RSLVEXCN_L2Sample(void)
{
#if (USE_RSLVEXC_ADC_RAW == 1)

	//	Adc_StatusType Adc_Status;
	//	Adc_Status = Adc_GetGroupStatus(AdcConf_AdcGroup_RslvExc_Group);
	//
	//	if((Adc_Status == ADC_COMPLETED) || (Adc_Status == ADC_STREAM_COMPLETED))
	//	{
	//		Adc_ReadGroup(AdcConf_AdcGroup_RslvExc_Group,&VAR_FS_VADC_RSLVEXC_u16[0U]);
	//	}
	VAR_FS_VADC_RSLVEXC_u16[0] = (uint16)(MODULE_VADC.G[5].RES[4].U);
	VAR_FS_VADC_RSLVEXC_u16[1] = (uint16)(MODULE_VADC.G[3].RES[2].U);
#else
	IoHwAb_ADC_GetPhyVoltage(FS_AN20_RSLVEXC_P_CHANNEL,&VAR_FS_RSLVEXC_P_f32);
	IoHwAb_ADC_GetPhyVoltage(FS_AN21_RSLVEXC_N_CHANNEL,&VAR_FS_RSLVEXC_N_f32);
	VAR_FS_RSLVEXC_f32=VAR_FS_RSLVEXC_P_f32-VAR_FS_RSLVEXC_N_f32;
#endif
}

/*******************************************************************************
 ** Function Name	: FS_ICU_Get_3phPWMPeriod_DutyCycle
 ** Parameter[in] 	: None
 ** Parameter[out] 	: None
 ** Return Value	  	: None
 ** Note	  			: None
 ** Description	  	: L2 Function safety get 3phPWMPeriod&DutyCycle sample
 *******************************************************************************/
uint16 DutyCnt = 0;
void FS_ICU_Get_3phPWMPeriod_DutyCycle(void)
{
	uint16 DutyTime = (uint16)(1000000.0/(102.4*(float32)VAR_Pwm_Freq_u16));
	if(DutyCnt >= DutyTime)
	{
#if (FIXME_GET_PWM_PERIOD_DUTYCYCLE == 1)
		Icu_17_GtmCcu6_GetDutyCycleValues(IcuConf_IcuChannel_H3phPWMUL_P10_8 ,&FS_3phPWMUL_Duty);
		Icu_17_GtmCcu6_GetDutyCycleValues(IcuConf_IcuChannel_H3phPWMVL_P14_10,&FS_3phPWMVL_Duty);
		Icu_17_GtmCcu6_GetDutyCycleValues(IcuConf_IcuChannel_H3phPWMWL_P22_5 ,&FS_3phPWMWL_Duty);
#else
		IoHwAb_ICU_GetPeriod_DutyCycle(IcuConf_IcuChannel_H3phPWMUH_VCE_P10_3 ,&VAR_FS_3phPWMUH_Period_f32,&VAR_FS_3phPWMUH_Duty_f32);
		IoHwAb_ICU_GetPeriod_DutyCycle(IcuConf_IcuChannel_H3phPWMUL_VCE_P10_8 ,&VAR_FS_3phPWMUL_Period_f32,&VAR_FS_3phPWMUL_Duty_f32);
		IoHwAb_ICU_GetPeriod_DutyCycle(IcuConf_IcuChannel_H3phPWMVH_VCE_P13_1 ,&VAR_FS_3phPWMVH_Period_f32,&VAR_FS_3phPWMVH_Duty_f32);
		IoHwAb_ICU_GetPeriod_DutyCycle(IcuConf_IcuChannel_H3phPWMVL_VCE_P14_10,&VAR_FS_3phPWMVL_Period_f32,&VAR_FS_3phPWMVL_Duty_f32);
		IoHwAb_ICU_GetPeriod_DutyCycle(IcuConf_IcuChannel_H3phPWMWH_VCE_P15_7 ,&VAR_FS_3phPWMWH_Period_f32,&VAR_FS_3phPWMWH_Duty_f32);
		IoHwAb_ICU_GetPeriod_DutyCycle(IcuConf_IcuChannel_H3phPWMWL_VCE_P22_5 ,&VAR_FS_3phPWMWL_Period_f32,&VAR_FS_3phPWMWL_Duty_f32);
#endif

		FS_DycU_Peroid = FS_3phPWMUL_Duty.PeriodTime;
		FS_DycV_Peroid = FS_3phPWMVL_Duty.PeriodTime;
		FS_DycW_Peroid = FS_3phPWMWL_Duty.PeriodTime;

		if(((FS_DycU_Peroid_Pre==0)&&(FS_DycU_Peroid!=0)) || ((FS_DycV_Peroid_Pre==0)&&(FS_DycV_Peroid!=0)) || ((FS_DycW_Peroid_Pre==0)&&(FS_DycW_Peroid!=0)))//前一周期为0，当前不为0，占空比读取的不准，舍弃
		{

		}
		else
		{
			if(FS_DycU_Peroid==0)
			{
				if(FS_DycU_Level_Pre != 0)
				{
					VAR_FS_DycU_f32 = 1;
				}
				else
				{
					VAR_FS_DycU_f32 = 0;
				}

			}
			else
			{
				VAR_FS_DycU_f32 = (float32)FS_3phPWMUL_Duty.ActiveTime/(float32)FS_DycU_Peroid;
			}

			if(FS_DycV_Peroid==0)
			{
				if(FS_DycV_Level_Pre != 0)
				{
					VAR_FS_DycV_f32 = 1;
				}
				else
				{
					VAR_FS_DycV_f32 = 0;
				}

			}
			else
			{
				VAR_FS_DycV_f32 = (float32)FS_3phPWMVL_Duty.ActiveTime/(float32)FS_DycV_Peroid;
			}

			if(FS_DycW_Peroid==0)
			{
				if(FS_DycW_Level_Pre != 0)
				{
					VAR_FS_DycW_f32 = 1;
				}
				else
				{
					VAR_FS_DycW_f32 = 0;
				}

			}
			else
			{
				VAR_FS_DycW_f32 = (float32)FS_3phPWMWL_Duty.ActiveTime/(float32)FS_DycW_Peroid;
			}

			FS_PwrTrq_iU_f32 = get_TRSP_iU();
			FS_PwrTrq_iV_f32 = get_TRSP_iV();
			FS_PwrTrq_iW_f32 = get_TRSP_iW();
			FS_PwrTrq_DycU_f32 = VAR_FS_DycU_f32;
			FS_PwrTrq_DycV_f32 = VAR_FS_DycV_f32;
			FS_PwrTrq_DycW_f32 = VAR_FS_DycW_f32;
			FS_PwrTrq_HighVol_f32 = get_L2Com_HiPrecVolt();
			set_L2Sampling_DycU_Mon(VAR_FS_DycU_f32);
			set_L2Sampling_DycV_Mon(VAR_FS_DycV_f32);
			set_L2Sampling_DycW_Mon(VAR_FS_DycW_f32);
		}

		FS_DycU_Peroid_Pre = FS_DycU_Peroid;
		FS_DycV_Peroid_Pre = FS_DycV_Peroid;
		FS_DycW_Peroid_Pre = FS_DycW_Peroid;
		FS_DycU_Level_Pre = P10_IN.B.P8;
		FS_DycV_Level_Pre = P14_IN.B.P10;
		FS_DycW_Level_Pre = P22_IN.B.P5;
		DutyCnt = 0;
	}
	else
	{
		DutyCnt++;
	}
}

/*******************************************************************************
 ** Function Name	: FS_GetResult_L2Sample
 ** Parameter[in] 	: None
 ** Parameter[out] 	: None
 ** Return Value	  	: None
 ** Note	  			: None
 ** Description	  	: L2 Function safety get MCU Hardware ADC sample
 *******************************************************************************/
uint16 FS_100us_cnt = 0;
//PduInfoType VCU_04;
//uint8 VCU04_Message;

void FS_GetResult_L2Sample(const FSINType *IN,FSOutType *out)
{
	//	Rdc_FS_DMA_Buffer_RD_Result();
	FS_Dsadc_SampleVW_Get();
	VCU04_Data_Read();
	BMS01_Data_Read();
	NvM_AngOfst_Read();
	Port_Crash_Read();
	Power_Data_Read();
	HvMcu_Data_Read();

	/*	if(FS_100us_cnt < 99)
	{
		FS_100us_cnt++;
	}
	else
	{*/
	//FS_ICU_Get_3phPWMPeriod_DutyCycle();

	/*		FS_100us_cnt = 0;
	}*/

	//	CanIf_ReadRxPduData(0x100,&VCU_04);
	//	VCU04_Message= Can_RxMessageData[0][]
	out->BMSVolt = BMS01_Singnal_BattVolt;
	out->HiPrec_Udc_Value = FS_HvMcu_H_Udc_Value;
	out->ModeReq = VCU04_Singnal_ModeReq;
	out->Crash = Port_Crash_Signal;
	out->NSetP = VCU04_Singnal_NSetP;
	out->TrqSetP = VCU04_Singnal_TrqSetP;
	out->AngOfst_f32 = FS_NvM_AngOfst_f32;

	FS_RSLVEXCN_L2Sample();

#if (USE_DSADC_MON_CUR == 0U)
	out->iU_MON = VAR_Adc_RES_Buffer_CUR_MCU_u16[5U];										/*AN18*/
	out->iV_MON = VAR_Adc_RES_Buffer_CUR_MCU_u16[1U];										/*AN2 */
	out->iW_MON = VAR_Adc_RES_Buffer_CUR_MCU_u16[3U];                                       /*AN10*/
#else
	out->iU_MON = FS_Dsadc_Buffer_Cur[0];													/*      */
	out->iV_MON = FS_Dsadc_Buffer_Cur[1];													/*DSADC0*/
	out->iW_MON = FS_Dsadc_Buffer_Cur[2];													/*DSADC3*/
#endif

#if (FIXME_GET_PWM_PERIOD_DUTYCYCLE == 1)
	//out->DycU_MON = (float32)FS_3phPWMUL_Duty.ActiveTime/(float32)FS_3phPWMUL_Duty.PeriodTime;
	//out->DycV_MON = (float32)FS_3phPWMVL_Duty.ActiveTime/(float32)FS_3phPWMVL_Duty.PeriodTime;
	//out->DycW_MON = (float32)FS_3phPWMWL_Duty.ActiveTime/(float32)FS_3phPWMWL_Duty.PeriodTime;
#else
	out->DycU_MON = VAR_FS_3phPWMUL_Duty_f32;
	out->DycV_MON = VAR_FS_3phPWMVL_Duty_f32;
	out->DycW_MON = VAR_FS_3phPWMWL_Duty_f32;
#endif

	out->RslvSin_MON = (float32)DMA_Sin_Total;
	out->RslvCos_MON = (float32)DMA_Cos_Total;

#if (USE_RSLVEXC_ADC_RAW == 1)
	out->ExciBackP = VAR_FS_VADC_RSLVEXC_u16[0];
	out->ExciBackN = VAR_FS_VADC_RSLVEXC_u16[1];
#else
	out->ExciBack = VAR_FS_RSLVEXC_f32;
#endif

	out->Exci18VLS_MON = (uint16)(MODULE_VADC.G[5].RES[3].U);
	out->LEM5V_MON = (uint16)(MODULE_VADC.G[5].RES[6].U);
	out->EmergSupVol_MON = Uart_Mux_Data[6];
	out->DriLSVol_MON = Uart_Mux_Data[7];

	out->stL2BSWinit = VAR_L2_Sample_flag_b;
	VAR_FS_React_u8 = IN->TOM_FaultReact;
}
/*******************************************************************************
 ** Function Name	: FS_L2Sample_exchange
 ** Parameter[in] 	: None
 ** Parameter[out] 	: None
 ** Return Value	  	: None
 ** Note	  			: None
 ** Description	  	: L2 Function safety get MCU Hardware ADC sample
 *******************************************************************************/
void L2Sampling_FS(void)
{

	FS_GetResult_L2Sample(&rtb_BusConversion_InsertedFor,
			&L2Sampling);

	set_L2Com_BMSVolt(L2Sampling.BMSVolt);
	set_L2Com_Crash(L2Sampling.Crash);
	set_L2Com_HiPrecVolt(L2Sampling.HiPrec_Udc_Value);

	set_L2Sampling_IsU_Mon(L2Sampling.iU_MON);
	set_L2Sampling_IsV_Mon(L2Sampling.iV_MON);
	set_L2Sampling_IsW_Mon(L2Sampling.iW_MON);
	set_L2Sampling_RslvSinP_VADC(VAR_DMA_Buffer_Sin);
	set_L2Sampling_RslvSinN_VADC(VAR_DMA_Buffer_SinLo);
	set_L2Sampling_RslvCosP_VADC(VAR_DMA_Buffer_Cos);
	set_L2Sampling_RslvCosN_VADC(VAR_DMA_Buffer_CosLo);
	set_L2Sampling_ExciBackP(L2Sampling.ExciBackP);
	set_L2Sampling_ExciBackN(L2Sampling.ExciBackN);
	set_L2Sampling_Exci18VLS_MON(L2Sampling.Exci18VLS_MON);
	set_L2Sampling_LEM5V_MON(L2Sampling.LEM5V_MON);
	/*	set_L2Sampling_RslvSin(L2Sampling.RslvSin_MON);
	set_L2Sampling_RslvCos(L2Sampling.RslvCos_MON);*/
	//	set_TRSP_RslvSin(VAR_RDC_RslvSinCompa_f32);/*L1层cdd积分后的sin*/
	//	set_TRSP_RslvCos(VAR_RDC_RslvCosCompa_f32);/*L1层cdd积分后的cos*/
	//	set_TRSP_RslvSin(VAR_TRSP_RslvSin_f32);//L2
	//	set_TRSP_RslvCos(VAR_TRSP_RslvCos_f32);//L2
	set_NvM_AngAutoClbOffset(L2Sampling.AngOfst_f32);
	set_L2Com_ModeReq(L2Sampling.ModeReq);
	set_L2Com_NSetP(L2Sampling.NSetP);
	set_L2Com_TrqSetP(L2Sampling.TrqSetP);
	//set_L2Sampling_DycU_Mon(L2Sampling.DycU_MON);
	//set_L2Sampling_DycV_Mon(L2Sampling.DycV_MON);
	//set_L2Sampling_DycW_Mon(L2Sampling.DycW_MON);
	set_HSPF_StrrTempFlt((float32)VAR_TpcMot_tSttrTempFlt_u16);
}
#pragma section
