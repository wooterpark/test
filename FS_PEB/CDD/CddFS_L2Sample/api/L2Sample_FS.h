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
* $Name______: Rdc_FS.h$
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
#ifndef L2Sample_FS_H_
#define L2Sample_FS_H_

/*******************************************************************************
**                      Other Header File Inclusion                           **
*******************************************************************************/
#include "Dma.h"
#include "Mcal_DmaLib.h"
#include "IfxVadc_reg.h"
#include "LvPower_Drv.h"
#include "IoHwAb_ADC.h"
#include "PhC_Drv.h"
#include "IoHwAb_ICU.h"


/*******************************************************************************
**                          Macro Definition                         		  **
*******************************************************************************/
#define USE_DSADC_MON_CUR				1U
#define USE_RSLVEXC_ADC_RAW				1U


#define ADC_Cos_ADC_HW_SEL			5U
#define ADC_CosLo_ADC_HW_SEL		5U
#define ADC_Sin_ADC_HW_SEL			3U
#define ADC_SinLo_ADC_HW_SEL	    3U
#define ADC_Cos_ADC_CH_SEL			2U
#define ADC_CosLo_ADC_CH_SEL		5U
#define ADC_Sin_ADC_CH_SEL			4U
#define ADC_SinLo_ADC_CH_SEL		7U

#define	ADC_Cos_DMA_CHANNEL			DMA_CH45
#define	ADC_CosLo_DMA_CHANNEL		DMA_CH44
#define	ADC_Sin_DMA_CHANNEL			DMA_CH43
#define	ADC_SinLo_DMA_CHANNEL		DMA_CH42

#if (USE_RSLVEXC_ADC_RAW == 0)
#define FS_AN20_RSLVEXC_P_CHANNEL     12U
#define FS_AN21_RSLVEXC_N_CHANNEL     13U
#endif

#define	ADC_DMA_CHANNEL_TCOUNT			1U

#define	IOHWAB_ADC_RDC_ISR_TIMER_TRIGGER_GTM_MODULE			    2U
#define	IOHWAB_ADC_RDC_ISR_TIMER_TRIGGER_GTM_CHANNEL_Ref_CH12	12U
#define	IOHWAB_L2_FS_ISR_TIMER_TRIGGER_GTM_MODULE			    0U
#define	IOHWAB_L2_FS_ISR_TIMER_TRIGGER_GTM_CHANNEL_Ref_CH1	    1U
#define	IOHWAB_L2_FS_ISR_TIMER_TRIGGER_GTM_CHANNEL_Ref_CH2	    2U
#define	IOHWAB_ADC_RDC_ISR_TIMER_TRIGGER_GTM_CHANNEL_CH13	    13U
#define	IOHWAB_ADC_RDC_TIMER_TRIGGER_GTM_MODULE			        0U
#define	IOHWAB_ADC_RDC_TIMER_TRIGGER_GTM_CHANNEL_Ref_CH3	    3U
#define	IOHWAB_ADC_RDC_TIMER_TRIGGER_GTM_CHANNEL_CH4	        4U

/*******************************************************************************
**                          Typedef Definition                         		  **
*******************************************************************************/
typedef struct {
	boolean stL2BSWinit;
	float32 iU_MON;
	float32 iV_MON;
	float32 iW_MON;
	float32 DycU_MON;
	float32 DycV_MON;
	float32 DycW_MON;
	float32 RslvSin_MON;
	float32 RslvCos_MON;
#if (USE_RSLVEXC_ADC_RAW == 1)
	Adc_ValueGroupType ExciBackP;
	Adc_ValueGroupType ExciBackN;
#else
	float32 ExciBack;
#endif
	Adc_ValueGroupType Exci18VLS_MON;
	Adc_ValueGroupType LEM5V_MON;
	uint16 EmergSupVol_MON;
	uint16 DriLSVol_MON;
	uint16 TrqSetP;
	uint16 NSetP;
	uint16 ModeReq;
	uint16 Crash;
	float32 HiPrec_Udc_Value;
	float32 AngOfst_f32;
	uint16 BMSVolt;
} FSOutType;

typedef struct {
	uint8 TOM_FaultReact;
}FSINType;
#pragma section ".data.CPU1_32"

/*******************************************************************************
**                  Global Variables With Extern Linkage               		  **
*******************************************************************************/
extern FSINType rtb_BusConversion_InsertedFor;
extern FSOutType SWC_L2Sampling;
extern boolean VAR_L2_Sample_flag_b;
extern uint8  DMA_Read_Buffer_Count;

extern float32 VAR_FS_DycU_f32;
extern float32 VAR_FS_DycV_f32;
extern float32 VAR_FS_DycW_f32;
extern float32 FS_PwrTrq_iU_f32;
extern float32 FS_PwrTrq_iV_f32;
extern float32 FS_PwrTrq_iW_f32;
extern float32 FS_PwrTrq_DycU_f32;
extern float32 FS_PwrTrq_DycV_f32;
extern float32 FS_PwrTrq_DycW_f32;
extern float32 FS_PwrTrq_HighVol_f32;

#pragma section
/*******************************************************************************
**                        Global Function Prototypes              	    	  **
*******************************************************************************/
#pragma section ".text.CPU1_Code" ax
/*******************************************************************************
** Function Name	: Rdc_FS_init
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: Rdc Function safety initialize
*******************************************************************************/
extern void Rdc_FS_init (void);

/*******************************************************************************
** Function Name	: Rdc_FS_ISR_init
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: Rdc SinLo buffer interrupt init
*******************************************************************************/
extern void Rdc_FS_ISR_init (void);

/*******************************************************************************
** Function Name	: FS_Dsadc_SampleVW_Init
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: Dsadc SampleVW Function safety initialize
*******************************************************************************/
extern void FS_Dsadc_SampleVW_Init (void);

/*******************************************************************************
** Function Name	: FS_Dsadc_SampleVW_Get
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: Dsadc SampleVW Function safety Get
*******************************************************************************/
extern void FS_Dsadc_SampleVW_Get (void);

/*******************************************************************************
** Function Name	: FS_GetResult_L2Sample
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: L2 Function safety get MCU Hardware ADC sample
*******************************************************************************/
extern void FS_GetResult_L2Sample(const FSINType *IN,FSOutType *out);

/*******************************************************************************
** Function Name	: L2Sampling_FS
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: L2 Function safety get MCU Hardware ADC sample
*******************************************************************************/
extern void L2Sampling_FS(void);
/*******************************************************************************
** Function Name	: Rdc_FS_DMA_Buffer_RD_Result
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: Reader DMA buffer and resolve the data
*******************************************************************************/
extern void Rdc_FS_DMA_Buffer_RD_Result (void);

/*******************************************************************************
** Function Name	: FS_VADC_RDC_offset
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: IOHWAB_VADC_RDC_offset
*******************************************************************************/
extern void FS_VADC_RDC_offset(void);

/*******************************************************************************
** Function Name	: FS_SetTimerTrigger_init
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: Rdc Function safety initialize
*******************************************************************************/
extern void FS_SetTimerTrigger_init(void);

/*******************************************************************************
** Function Name	: FS_ICU_Get_3phPWMPeriod_DutyCycle
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: L2 Function safety get 3phPWMPeriod&DutyCycle sample
*******************************************************************************/
extern void FS_ICU_Get_3phPWMPeriod_DutyCycle(void);

/*******************************************************************************
** Function Name	: FS_Shut_Of_Path_L2
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: L2 Function safety get RSLVEXCN sample
*******************************************************************************/

#pragma section


#endif
