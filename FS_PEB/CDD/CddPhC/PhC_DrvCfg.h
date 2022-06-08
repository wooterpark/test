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
* $Name______: Adc_DrvCfg.h$
* $Variant___: 0.0.0$
* $Revision__: V1.0$
* $Author____: XM$
**
**----------------------------------------------------------------------------**
** MAY BE CHANGED BY USER [Yes/No]: yes
**----------------------------------------------------------------------------**
** DESCRIPTION:
			Adc currnt and udc sample cfg.
**----------------------------------------------------------------------------**
** HISTORY:
V1.0.0:   initial version

*******************************************************************************/
#ifndef PHC_DRVCFG_H_
#define PHC_DRVCFG_H_

/*******************************************************************************
**                      Other Header File Inclusion                           **
*******************************************************************************/
#include "Adc.h"

/*******************************************************************************
**                          Macro Definition                         		  **
*******************************************************************************/
#define ADC_HW_TRIGGER_USE_DMA					0U

#define	ADC_HW_TRIGGER_GTM_MODULE				0U
#define	ADC_HW_TRIGGER_GTM_CHANNEL_CH0			7U

#define	PHC_GROUP_U_CUR		AdcConf_AdcGroup_U1_V2_CUR_Group
#define	PHC_GROUP_V_CUR		AdcConf_AdcGroup_V1_W2_CUR_Group
#define	PHC_GROUP_W_CUR		AdcConf_AdcGroup_W1_U2_CUR_Group


#if(ADC_HW_TRIGGER_USE_DMA == 1)
#include "Dma.h"
#include "Mcal_DmaLib.h"
#include "IfxVadc_reg.h"

#define ADC_U_CUR_ADC_HW_SEL			0U
#define ADC_V_CUR_ADC_HW_SEL			1U
#define ADC_W_CUR_ADC_HW_SEL			2U
#define ADC_U_CUR_ADC_CH_SEL			0U
#define ADC_V_CUR_ADC_CH_SEL			0U
#define ADC_W_CUR_ADC_CH_SEL			0U

#define	ADC_U_CUR_DMA_CHANNEL			DMA_CH52
#define	ADC_V_CUR_DMA_CHANNEL			DMA_CH51
#define	ADC_W_CUR_DMA_CHANNEL			DMA_CH50

#define	ADC_DMA_CHANNEL_TCOUNT			1U

#define	ADC_SUNCHRONIZATION_MODE_SEL	1U
#endif

/*******************************************************************************
**                          Typedef Definition                         		  **
*******************************************************************************/

/*******************************************************************************
**                  Global Variables With Extern Linkage               		  **
*******************************************************************************/

/*******************************************************************************
**                        Global Function Prototypes              	    	  **
*******************************************************************************/

#endif


/*******************************************************************************

*******************************************************************************/
