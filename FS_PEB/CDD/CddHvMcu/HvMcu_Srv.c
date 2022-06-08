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
* $Name______: HvMCU_Srv.c$
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
#include "Platform_Types.h"
#include "HvMcu_Drv.h"
#include "HvMcu_Srv.h"

#include "IfxSrc_reg.h"
#include "Uart.h"
#include "Dio.h"

/*JEE_MISRA_RULES_1_01 It's Allowed*/
#pragma section ".rodata.Calib_32" a 4
/*JEE_MISRA_RULES_8_04 It's Allowed*/
const volatile float32 CAL_HardComp_f32 = 8.0F;
/*JEE_MISRA_RULES_1_01 It's Allowed*/
#pragma section

static Prv_PosCal_S Prv_PosCal;
typedef void(*Self_Status)(Prv_PosCal_S* a);

static void Prv_Shake_Hand(Prv_PosCal_S* mPrvPtr);
static void Prv_State_Switch(Prv_PosCal_S* mPrvPtr);
static void Prv_Self_Learning(Prv_PosCal_S* mPrvPtr);
static void Prv_State_Return(Prv_PosCal_S* mPrvPtr);
static void Prv_Stop_Learning(Prv_PosCal_S* mPrvPtr);
static void Prv_Idle_Waiting(Prv_PosCal_S* mPrvPtr);
/*JEE_MISRA_RULES_8_09 It's Allowed*/
static const Self_Status Mode_Table[]=
	{
		Prv_Shake_Hand,
		Prv_State_Switch,
		Prv_Self_Learning,
		Prv_State_Return,
		Prv_Stop_Learning,
		Prv_Idle_Waiting,
	};

/*******************************************************************************
** Function Name : Prv_Shake_Hand
** Parameter[in] : Prv_PosCal_S* mPub
** Parameter[out]: Prv_PosCal_S* mPub
** Return Value  : void
** Note          : static
** Description   : Shake_Hand
*******************************************************************************/
static void Prv_Shake_Hand(Prv_PosCal_S* mPrvPtr)
{
	HvMcu_Com.Uart_Tx.SelfLearingFlg = TRUE;

	if(HvMcu_Com.Uart_Rx.RspMode == (uint8)ANGLE_MODE)
	{
		HvMcu_Com.Enable = FALSE;
		mPrvPtr->Index = State_Switch;
	}
}

/*******************************************************************************
** Function Name : Prv_State_Switch
** Parameter[in] : Prv_PosCal_S* mPrvPtr
** Parameter[out]: Prv_PosCal_S* mPrvPtr
** Return Value  : void
** Note          : static
** Description   : Prv_PosCal_S
*******************************************************************************/
static void Prv_State_Switch(Prv_PosCal_S* mPrvPtr)
{	/*JEE_MISRA_RULES_11_04&4_09 It's Allowed*/	
	ASCLIN1_TO_GPIO();
	Dio_WriteChannel(DIO_CHANNEL_15_0,STD_LOW);
	/*JEE_MISRA_RULES_11_04&4_09 It's Allowed*/
	ASCLIN1_RX_DISABLE();
	GTM_TIM2_CH4_ENABLE();

	mPrvPtr->Count = (mPrvPtr->Count + 1u)&0x07u;
	if(mPrvPtr->Count == 0u)
	{
		mPrvPtr->Index = Self_Learn;
		mPrvPtr->Inter_Begin = TRUE;
	}
}

/*******************************************************************************
** Function Name : Prv_Self_Learning
** Parameter[in] : Prv_PosCal_S Ptr
** Parameter[out]: void
** Return Value  : void
** Note          : static
** Description   : Self_Learning.
*******************************************************************************/
static void Prv_Self_Learning(Prv_PosCal_S* mPrvPtr)
{
	if(mPrvPtr->Inter_Begin == FALSE)
	{	/*JEE_MISRA_RULES_11_04&4_09 It's Allowed*/
		GTM_TIM2_CH4_DISABLE();
		mPrvPtr->Index = State_Return;
	}
}

/*******************************************************************************
** Function Name : Prv_State_Return
** Parameter[in] : Prv_PosCal_S Ptr
** Parameter[out]: void
** Return Value  : void
** Note          : static
** Description   : State_Return
*******************************************************************************/
static void Prv_State_Return(Prv_PosCal_S* mPrvPtr)
{
	Dio_WriteChannel(DIO_CHANNEL_15_0,STD_HIGH);

	mPrvPtr->Count = (mPrvPtr->Count+1u)&0x03u;
	if(mPrvPtr->Count == 0u)
	{
		mPrvPtr->Index = Stop_Learn;
	}
}

/*******************************************************************************
** Function Name : Prv_Stop_Learning
** Parameter[in] : Prv_PosCal_S* mPub
** Parameter[out]: Prv_PosCal_S* mPub
** Return Value  : void
** Note          : static
** Description   : Stop_Learning
*******************************************************************************/
static void Prv_Stop_Learning(Prv_PosCal_S* mPrvPtr)
{	/*JEE_MISRA_RULES_11_04&4_09 It's Allowed*/
	GPIO_TO_ASCLIN1();
	Uart_Init(&Uart_ConfigRoot[0]);

	HvMcu_Com_Init();
	/*JEE_MISRA_RULES_11_04&4_09 It's Allowed*/
	ASCLIN1_RX_ENABLE();

	PosLearn_Init();

	mPrvPtr->Task_Begin = FALSE;
}

/*******************************************************************************
** Function Name : Prv_Idle_Waiting
** Parameter[in] : Prv_PosCal_S* mPrvPtr
** Parameter[out]: Prv_PosCal_S* mPrvPtr
** Return Value  : void
** Note          : static
** Description   : Idle State.
*******************************************************************************/
static void Prv_Idle_Waiting(Prv_PosCal_S* mPrvPtr)
{
	if(mPrvPtr->Task_Begin==TRUE)
	{
		mPrvPtr->Index = Shank_Hand;
	}
}

/*******************************************************************************
** Function Name : PosLearn_Task_Ctrl
** Parameter[in] : Prv_PosCal_S* mPrvPtr
** Parameter[out]: Prv_PosCal_S* mPrvPtr
** Return Value  : void
** Note          : Task ctrl.
** Description   : PosLearn_Task_Ctrl
*******************************************************************************/
void PosLearn_Task_Ctrl(const PosCal_InPut_S* InPtr)
{
	if(InPtr->App_Ctrl == 1U)
	{
		Prv_PosCal.Task_Begin = TRUE;
	}
	else
	{
		Prv_PosCal.Inter_Begin = FALSE;
	}

	Mode_Table[Prv_PosCal.Index](&Prv_PosCal);
}

/*******************************************************************************
** Function Name : PosLearn_Inter_Ctrl
** Parameter[in] : Prv_PosCal_S* mPub
** Parameter[out]: void
** Return Value  : void
** Note          : Inter_Ctrl
** Description   : PosLearn_Inter_Ctrl
*******************************************************************************/
void PosLearn_Inter_Ctrl(PosCal_OutPut_S* OutPtr)
{
	float32 CompChk;

	if(Prv_PosCal.Inter_Begin==TRUE)
	{
		OutPtr->SampleValid = FALSE;
		/*JEE_MISRA_RULES_11_04 It's Allowed*/
		Prv_PosCal.ADCTimestamp = ADC_TIM_RES;
		Prv_PosCal.CAPTimestamp = CAP_TIM_RES;
		Prv_PosCal.RiseEdgeCntCur = Edge_CNT_RES;
#if FALSE
		Prv_PosCal.InterEdgeCycle = (float64)(Prv_PosCal.ADCTimestamp - Prv_PosCal.ADCTimestampBck)*COMP_TIMES_CONVERT;
		Prv_PosCal.ADCTimestampBck = mPrv->ADCTimestamp;

		if(Prv_PosCal.CAPTimestamp > mPrv->CAPTimestampBck)
		{
			Prv_PosCal.RiseEdgeCycle = (float32)(Prv_PosCal.CAPTimestamp - Prv_PosCal.CAPTimestampBck) * COMP_TIMES_CONVERT;
			Prv_PosCal.RiseEdgeSpeed = 15.0F/Prv_PosCal.RiseEdgeCycle;
		}
		Prv_PosCal.CAPTimestampBck = Prv_PosCal.CAPTimestamp;
#endif
		if((Prv_PosCal.RiseEdgeCntCur - Prv_PosCal.RiseEdgeCntBck) == 1u)
		{
			Prv_PosCal.TimeCompCap= ((float32)Prv_PosCal.ADCTimestamp - (float32)Prv_PosCal.CAPTimestamp) * COMP_TIMEUS_CONVERT;
			/*JEE_MISRA_RULES_4_09 It's Allowed*/	
			CompChk = STD_MF_ABS(Prv_PosCal.TimeCompCap);
			if(CompChk < COMP_TIME_LIMIT)
			{
				OutPtr->SampleValid = TRUE;
				OutPtr->TimeCompAll = Prv_PosCal.TimeCompCap + Prv_PosCal.TimeCompHard + CAL_HardComp_f32;
			}
		}
		Prv_PosCal.RiseEdgeCntBck = Prv_PosCal.RiseEdgeCntCur;
	}
}

/*******************************************************************************
** Function Name : PosLearn_Init
** Parameter[in] : Prv_PosCal_S* mPub
** Parameter[out]: void
** Return Value  : void
** Note          : init
** Description   : Initialization
*******************************************************************************/
void PosLearn_Init(void)
{
	Prv_PosCal.TimeCompCap = 0.0F;
	Prv_PosCal.RiseEdgeCntCur = 0;
	Prv_PosCal.RiseEdgeCntBck = 10;
	Prv_PosCal.RiseEdgeCycle = 0.0F;
	Prv_PosCal.InterEdgeCycle = 0.0F;
	Prv_PosCal.TimeCompHard = COMP_TIME_HARD;

	Prv_PosCal.Index = Idel_Wait;
	Prv_PosCal.RiseEdgeSpeed = 0.0F;
}
