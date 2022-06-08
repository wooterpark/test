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
* $Name______: HvMCU_Srv.h$
* $Variant___: 0.0.0$
* $Revision__: 0$
* $Author____: XM$
**
**----------------------------------------------------------------------------**
** MAY BE CHANGED BY USER [Yes/No]: No
**----------------------------------------------------------------------------**
** DESCRIPTION:
			Angle Selflearning.

**----------------------------------------------------------------------------**
** HISTORY:
V1.0.0:   Initial version.

*******************************************************************************/
#ifndef HVMCU_SERVICE_H_
#define HVMCU_SERVICE_H_

#include "IfxGtm_reg.h"

#define	COMP_POLAR_CTL        (1.0F)
#define	COMP_TIME_HARD        (2.16F)
#define	COMP_TIME_LIMIT       (100.5F)
#define	COMP_TIMEUS_CONVERT   (0.08F)
#define	COMP_TIMES_CONVERT    (0.00000008)

#define	CAP_TIM_RES           (GTM_TIM2_CH4_GPR0.B.GPR0);
#define	ADC_TIM_RES           (GTM_TIM1_CH7_GPR0.B.GPR0);
#define	Edge_CNT_RES          (GTM_TIM2_CH4_CNTS.B.CNTS);

#define	ASCLIN1_TO_GPIO()     (P15_IOCR0.B.PC0 = 0x10)
#define	GPIO_TO_ASCLIN1()     (P15_IOCR0.B.PC0 = 0x12)

#define	ASCLIN1_RX_ENABLE()   (SRC_ASCLIN1RX.B.SRE = 1)
#define	ASCLIN1_RX_DISABLE()  (SRC_ASCLIN1RX.B.SRE = 0)


#define	GTM_TIM2_CH4_ENABLE()   (GTM_TIM2_CH4_CTRL.B.TIM_EN = 1)
#define	GTM_TIM2_CH4_DISABLE()  (GTM_TIM2_CH4_CTRL.B.TIM_EN = 0)

/*******************************************************************************
** Function Name : STD_MF_ADS
** Parameter[in] :
** Parameter[out]:
** Return Value  :
** Note          :
** Description   : ABS
*******************************************************************************/
#define STD_MF_ABS(mVar)        (((mVar) > (0.0f)) ? (mVar) : (-(mVar)))

typedef enum
{
	Shank_Hand = 0,
	State_Switch,
	Self_Learn,
	State_Return,
	Stop_Learn,
	Idel_Wait,
}SelfL_State_E;

typedef struct
{
	uint8 Count;
	uint8 Task_Begin;
	uint8 Inter_Begin;
	float32 RiseEdgeSpeed;
	SelfL_State_E Index;

	uint32 RiseEdgeCntCur;
	uint32 RiseEdgeCntBck;

	uint32 ADCTimestamp;
	uint32 CAPTimestamp;
	uint32 ADCTimestampBck;
	uint32 CAPTimestampBck;

	float32 TimeCompCap;
	float32 TimeCompHard;

	float32 RiseEdgeCycle;
	float32 InterEdgeCycle;
}Prv_PosCal_S;

typedef struct
{
	uint8 SampleValid;
	float32 TimeCompAll;
}PosCal_OutPut_S;

typedef struct
{
	uint8 App_Ctrl;
}PosCal_InPut_S;

extern void PosLearn_Init(void);
extern void PosLearn_Inter_Ctrl(PosCal_OutPut_S* OutPtr);
extern void PosLearn_Task_Ctrl(const PosCal_InPut_S* InPtr);

#endif
