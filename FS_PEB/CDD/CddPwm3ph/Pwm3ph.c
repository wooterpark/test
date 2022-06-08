/*******************************************************************************
**----------------------------------------------------------------------------**
** Copyright (c) 2018 by JEE.		All rights reserved.
** This software is copyright protected and proprietary to JEE.
** JEE grants to you only those rights as set out in the license conditions.
** All other rights remain with JEE.
**----------------------------------------------------------------------------**
**
* Administrative Information
* $Namespace_: \CddDrv\Pwm3ph$
* $Class_____: C$
* $Name______: Pwm3ph.c$
* $Variant___: 0.0.0$
* $Revision__: 0$
* $Author____: LQ$
**
**----------------------------------------------------------------------------**
** MAY BE CHANGED BY USER [Yes/No]: No
**----------------------------------------------------------------------------**
** DESCRIPTION:
** Three - phase six - channel PWM output drive
*******************************************************************************
* $History__:$
* V0.0.0;      2018.08.01 LQ
*  1�� new created
* V1.0.1;      2018.09.25 LQ
*  1��Previously, there was a hard pin +VAR_Pwm_Mode_u8 to control the PWM output state respectively. Now, the state machine is unified into the Pwm3ph module.
* V1.0.2;      2018.10.15 LQ
*  1��The Pwm3ph_SetOutput function, the unwanted state is commented out as a macro definition
*  * V1.0.3;      2020.03.06 WTH
*  1��modify the UI16_PWM_ADC_TRIGGER_OFFSET to calibration variable.
*  * V1.0.4;      2020.11.02 LQ
*  1��Delete dead zone time Settings.
*******************************************************************************/


/*******************************************************************************
**                      Other Header File Inclusion                           **
*******************************************************************************/
#include "Pwm3ph.h"
#include "Cpld_Drv.h"
#if (_CDD_SIMULATION == STD_OFF)
#include "Gtm.h"
#include "Dio.h"
#include "L2Sample_FS.h"
#include "L2SOP_FS.h"
#endif
//#include "TLF35584Bist.h"
/*******************************************************************************
**                          Macro Definition                         		  **
*******************************************************************************/
#define U16_REGISTER_OFFSET_VALUE    1U			/* register offset */

/*******************************************************************************
**                          Typedef Definition                         		  **
*******************************************************************************/

/*******************************************************************************
**                   Static Local Variables Definition              		  **
*******************************************************************************/
/* �ڲ����� */
static uint16 ui16_Pwm_Period_SR0;		 /* PWM period TICK */

static uint16 ui16_Pwm_OnEdge_UT_SR1;	 /* U_H_ON(rising edge),SR1 */
static uint16 ui16_Pwm_OffEdge_UT_SR0;	 /* U_H_OFF(falling edge),SR0 */
static uint16 ui16_Pwm_OnEdge_UB_SR0;	 /* U_L_ON(falling edge),SR0 */
static uint16 ui16_Pwm_OffEdge_UB_SR1;	 /* U_L_OFF(rising edge),SR1 */

static uint16 ui16_Pwm_OnEdge_VT_SR1;
static uint16 ui16_Pwm_OffEdge_VT_SR0;
static uint16 ui16_Pwm_OnEdge_VB_SR0;
static uint16 ui16_Pwm_OffEdge_VB_SR1;

static uint16 ui16_Pwm_OnEdge_WT_SR1;
static uint16 ui16_Pwm_OffEdge_WT_SR0;
static uint16 ui16_Pwm_OnEdge_WB_SR0;
static uint16 ui16_Pwm_OffEdge_WB_SR1;

static uint8 ui8_Pwm_Mode_Last;				/* last PWM Mode */
static uint16 VAR_Pwm_Fault_Flag_u16;		/* Input parameter error flag */
static uint16 ui16_Pwm_Period_Tick_Last;

#if(UI8_PWM3PH_PARAMETER_TYPE == 3U)
static uint16 ui16_Pwm_Ticks_OnEdge_UT;
static uint16 ui16_Pwm_Ticks_OffEdge_UT;
static uint16 ui16_Pwm_Ticks_OnEdge_UB;
static uint16 ui16_Pwm_Ticks_OffEdge_UB;

static uint16 ui16_Pwm_Ticks_OnEdge_VT;
static uint16 ui16_Pwm_Ticks_OffEdge_VT;
static uint16 ui16_Pwm_Ticks_OnEdge_VB;
static uint16 ui16_Pwm_Ticks_OffEdge_VB;

static uint16 ui16_Pwm_Ticks_OnEdge_WT;
static uint16 ui16_Pwm_Ticks_OffEdge_WT;
static uint16 ui16_Pwm_Ticks_OnEdge_WB;
static uint16 ui16_Pwm_Ticks_OffEdge_WB;
 

#endif

/*******************************************************************************
**                     Global Variables Definition              		      **
*******************************************************************************/
/*JEE_MISRA_RULES_1_01&8_04 It's Allowed*/
#pragma section ".rodata.Calib_32"
const  volatile float32 CAL_PWM_Set_DeadTime_us_f32 =	 2.6F;	/* Default dead zone time ,2.6Us */
/*
 *	0.94 <  x_Duty <= 0.999 
 *	0.06 =< x_Duty <= 0.94   
 *	0.001<  x_Duty <  0.06  
 * */
const volatile float32 CAL_Pwm3phB_ClosedThreshold_f32 	=	 0.94F;
const volatile float32 CAL_Pwm3phT_ClosedThreshold_f32 	=	 0.06F;
const volatile float32 CAL_Pwm3ph_DutyMax_f32 			=	 0.999F;
const volatile float32 CAL_Pwm3ph_DutyMin_f32 			=	 0.001F;

const volatile uint16 CAL_Pwm3ph_AdcTriggleOffset_u16 	=	 100U;

#pragma section
/*JEE_MISRA_RULES_1_01&8_04 It's Allowed*/
#pragma section ".data.CPU2_32" aw 4

#if(UI8_PWM3PH_PARAMETER_TYPE == 3U)
uint8  VAR_Pwm_Mode_u8=0;					/* PWM Mode */
uint16 VAR_Pwm_Freq_u16;					/* PWM Fre */
float32 VAR_Pwm_DeadTime_In_f32;			/* PWM DeadTime(uS)*/

float32 VAR_PwmDutyCyclePhaseU_f32=0.0;
float32 VAR_PwmDutyCyclePhaseV_f32=0.0;
float32 VAR_PwmDutyCyclePhaseW_f32=0.0;

uint16 ui16_Pwm_Fault_Flag_Last;
uint32 ui32_Pwm_Fault_Counter;
#endif
uint8 VAR_PWM3phUDuty_ERR_u8;
uint8 VAR_PWM3phVDuty_ERR_u8;
uint8 VAR_PWM3phWDuty_ERR_u8;

#if (UI8_PWM3PH_PARAMETER_TYPE == 12U)
uint8 VAR_Pwm_Mode_u8;
uint16 ui16_Pwm_Period_Tick;
uint16 ui16_Pwm_Ticks_OnEdge_UT;
uint16 ui16_Pwm_Ticks_OffEdge_UT;
uint16 ui16_Pwm_Ticks_OnEdge_UB;
uint16 ui16_Pwm_Ticks_OffEdge_UB;

uint16 ui16_Pwm_Ticks_OnEdge_VT;
uint16 ui16_Pwm_Ticks_OffEdge_VT;
uint16 ui16_Pwm_Ticks_OnEdge_VB;
uint16 ui16_Pwm_Ticks_OffEdge_VB;

uint16 ui16_Pwm_Ticks_OnEdge_WT;
uint16 ui16_Pwm_Ticks_OffEdge_WT;
uint16 ui16_Pwm_Ticks_OnEdge_WB;
uint16 ui16_Pwm_Ticks_OffEdge_WB;

uint16 ui16_Pwm_Fault_Flag_Last;
uint32 ui32_Pwm_Fault_Counter;
#endif
#pragma section
/*******************************************************************************
**                  Static Local Function Declaration            		      **
*******************************************************************************/
static void Pwm3ph_Set_ShadowValSr0(uint8 Moudle,uint8 Channel,uint32 Sr0Value);
static void Pwm3ph_Set_ShadowValSr1(uint8 Moudle,uint8 Channel,uint32 Sr1Value);
static void Pwm3ph_Enable_OutputChannel(uint8 Moudle,uint8 Channel);
static void Pwm3ph_Disable_OutputChannel(uint8 Moudle,uint8 Channel);
static void Pwm3ph_Set_CN0(uint8 Moudle,uint8 Channel,uint32 CnoValue);
static void Pwm3ph_Output_UpOff_DownOff(void);		/* all shundown */
static void Pwm3ph_Output_Normal(void);				/* normal mode */
static void Pwm3ph_Output_UpOff_DownOn(void);		/* ASC */
#if (PWM3PH_PWM_MODE == 1U)
static void Pwm3ph_Output_UpOn_DownOff(void);
static void Pwm3ph_Output_UpOn_DownUOn(void);
static void Pwm3ph_Output_UpUOn_DownOn(void);
#endif
static void Pwm3ph_ChangePeriod(uint16 ui16_Period);
#if(UI8_PWM3PH_PARAMETER_TYPE == 3U)
static void Pwm3ph_GetDataConversion(void);
#endif

static volatile uint8 VAR_SS1_OC_u8;
/*******************************************************************************
**                 		  Function Source Code            		              **
*******************************************************************************/

/*******************************************************************************
** Function Name	: Pwm3ph_Init
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	��
** Description	  	: initialize
*******************************************************************************/
void Pwm3ph_Init(void)
{
	Pwm3phInIFType pwm3phInIF_Ptr;
	pwm3phInIF_Ptr.PwmDutyCyclePhaseU1_f32 = 0.0f;
	pwm3phInIF_Ptr.PwmDutyCyclePhaseV1_f32 =  0.0f;
	pwm3phInIF_Ptr.PwmDutyCyclePhaseW1_f32 =  0.0f;
	pwm3phInIF_Ptr.Pwm_Freq_u16 =  U16_PWM_DEF_FREQ_VALUE;
	pwm3phInIF_Ptr.Pwm_Mode_u8 =  0;

	/*����������ʼ��(GLOBAL)*/
#if (UI8_PWM3PH_PARAMETER_TYPE == 3U)
	VAR_Pwm_DeadTime_In_f32 = CAL_PWM_Set_DeadTime_us_f32;
	VAR_Pwm_Mode_u8 = UI8_MODE_UP_OFF_DOWN_OFF;
	VAR_Pwm_Freq_u16 = U16_PWM_DEF_FREQ_VALUE;
	VAR_PwmDutyCyclePhaseU_f32 = 0.0f;
	VAR_PwmDutyCyclePhaseV_f32 = 0.0f;
	VAR_PwmDutyCyclePhaseW_f32 = 0.0f;
	ui16_Pwm_Fault_Flag_Last = PWM_FAULT_NONE;
	ui32_Pwm_Fault_Counter = 0U;


	ui8_Pwm_Mode_Last = UI8_MODE_UP_OFF_DOWN_OFF;
	VAR_Pwm_Fault_Flag_u16 = PWM_FAULT_NONE;
	ui16_Pwm_Period_Tick_Last = 0U;
#endif

#if (UI8_PWM3PH_PARAMETER_TYPE == 12U)
	VAR_Pwm_Mode_u8 = UI8_MODE_UP_OFF_DOWN_OFF;
	ui16_Pwm_Period_Tick = 10000U;
	ui16_Pwm_Fault_Flag_Last = PWM_FAULT_NONE;
	ui32_Pwm_Fault_Counter = 0U;

	ui8_Pwm_Mode_Last = UI8_MODE_UP_OFF_DOWN_OFF;
	VAR_Pwm_Fault_Flag_u16 = PWM_FAULT_NONE;
	ui16_Pwm_Period_Tick_Last = 0U;
#endif

	/*Disable_OutputChannel*/
 #if (_CDD_SIMULATION == STD_OFF)
	Pwm3ph_Disable_OutputChannel(UI8_PWM_TOM_ATOM_MOUDLE_SEL,\
			UI8_PWM_TOM_ATOM_CHANNEL_SEL_PERIOD_REF);
	Pwm3ph_Set_CN0(UI8_PWM_TOM_ATOM_MOUDLE_SEL,\
			UI8_PWM_TOM_ATOM_CHANNEL_SEL_PERIOD_REF,0U);

	Pwm3ph_Disable_OutputChannel(UI8_PWM_TOM_ATOM_MOUDLE_SEL,\
			UI8_PWM_TOM_ATOM_CHANNEL_SEL_ADC_TRIG);


	Pwm3ph_SetOutput(&pwm3phInIF_Ptr);


	Pwm3ph_Enable_OutputChannel(UI8_PWM_TOM_ATOM_MOUDLE_SEL,\
	UI8_PWM_TOM_ATOM_CHANNEL_SEL_PERIOD_REF);
#endif
}

/*******************************************************************************
** Function Name	: Pwm3ph_EnableIsrTrigger
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	:
** Description	  	: EnableIsrTrigger
*******************************************************************************/
void Pwm3ph_EnableIsrTrigger(void)
{
	Pwm3ph_Enable_OutputChannel(UI8_PWM_TOM_ATOM_MOUDLE_SEL,\
						UI8_PWM_TOM_ATOM_CHANNEL_SEL_ADC_TRIG);
}

/*******************************************************************************
** Function Name	: Pwm3ph_SetOutput
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	:
**
** Description	  	:
*******************************************************************************/
#if ( (_CDD_SIMULATION == STD_OFF)||(_CDD_INTEGRATION == STD_ON) ) 
void Pwm3ph_SetOutput(const Pwm3phInIFType* in)
#else
void Pwm3ph_SetOutput(const Pwm3phInIFType* in, Pwm3phOutIFType* out )
#endif
{
	if(VAR_SS1_OC_u8 == 0U)
	{
		if((VAR_Cpld_Normal_Work_u8 == 1U) && (VAR_Shut_Of_Path_State_u16 == 1U))
		{
	VAR_Pwm_Freq_u16 = in->Pwm_Freq_u16;
	VAR_Pwm_Mode_u8 = in->Pwm_Mode_u8;
	VAR_PwmDutyCyclePhaseU_f32 = in->PwmDutyCyclePhaseU1_f32;
	VAR_PwmDutyCyclePhaseV_f32 = in->PwmDutyCyclePhaseV1_f32;
	VAR_PwmDutyCyclePhaseW_f32 = in->PwmDutyCyclePhaseW1_f32;
		}
		else
		{
			VAR_Pwm_Mode_u8 = UI8_MODE_UP_OFF_DOWN_OFF;
		}

	#if (UI8_PWM3PH_PARAMETER_TYPE == 3U)
	Pwm3ph_GetDataConversion();
	#endif

/*	
*	if(ui16_Pwm_Period_Tick_Last != ui16_Pwm_Period_Tick)
*	{Pwm3ph_ChangePeriod(ui16_Pwm_Period_Tick);}
*/
	switch(VAR_Pwm_Mode_u8)	/* CHECK MODE */
	{
		case UI8_MODE_UP_OFF_DOWN_OFF:	/*FreeWheel */
		{

			Pwm3ph_Output_UpOff_DownOff();


			ui8_Pwm_Mode_Last = UI8_MODE_UP_OFF_DOWN_OFF;
			break;
		}
		case UI8_MODE_NORMAL:
		{

			if((ui8_Pwm_Mode_Last == UI8_MODE_NORMAL) \
			 ||(ui8_Pwm_Mode_Last == UI8_MODE_UP_OFF_DOWN_OFF))
			{
				Pwm3ph_Output_Normal();

			}
			else
			{
				Pwm3ph_Output_UpOff_DownOff();
			}


			ui8_Pwm_Mode_Last = UI8_MODE_NORMAL;
			break;
		}
		case UI8_MODE_UP_OFF_DOWN_ON:
		{

			if((ui8_Pwm_Mode_Last == UI8_MODE_UP_OFF_DOWN_ON) \
			||(ui8_Pwm_Mode_Last == UI8_MODE_UP_OFF_DOWN_OFF))
			{
				Pwm3ph_Output_UpOff_DownOn();
				
			}
			else
			{
				Pwm3ph_Output_UpOff_DownOff();
			}


			ui8_Pwm_Mode_Last = UI8_MODE_UP_OFF_DOWN_ON;
			break;
		}
		#if (PWM3PH_PWM_MODE == 1U)
		case UI8_MODE_UP_ON_DOWN_OFF:
		{
			if((ui8_Pwm_Mode_Last == UI8_MODE_UP_ON_DOWN_OFF) \
			||(ui8_Pwm_Mode_Last == UI8_MODE_UP_OFF_DOWN_OFF))
			{
				Pwm3ph_Output_UpOn_DownOff();
			}
			else
			{
				Pwm3ph_Output_UpOff_DownOff();
			}


			ui8_Pwm_Mode_Last = UI8_MODE_UP_ON_DOWN_OFF;
			break;
		}
		case UI8_MODE_UP_UON_DOWN_ON:
		{
			if((ui8_Pwm_Mode_Last == UI8_MODE_UP_UON_DOWN_ON) \
						||(ui8_Pwm_Mode_Last == UI8_MODE_UP_OFF_DOWN_ON))
			{
				Pwm3ph_Output_UpUOn_DownOn();
			}
			else
			{
				Pwm3ph_Output_UpOff_DownOff();
			}
			ui8_Pwm_Mode_Last = UI8_MODE_UP_UON_DOWN_ON;
			break;
		}
		case UI8_MODE_UP_ON_DOWN_UON:
		{
			if((ui8_Pwm_Mode_Last == UI8_MODE_UP_ON_DOWN_UON) \
									||(ui8_Pwm_Mode_Last == UI8_MODE_UP_OFF_DOWN_ON))
			{
				Pwm3ph_Output_UpOn_DownUOn();
			}
			else
			{
				Pwm3ph_Output_UpOff_DownOff();
			}
			ui8_Pwm_Mode_Last = UI8_MODE_UP_ON_DOWN_UON;
			break;
		}
		#endif
		default:
		{
			Pwm3ph_Output_UpOff_DownOff();


			ui8_Pwm_Mode_Last = UI8_MODE_UP_OFF_DOWN_OFF;
			break;
		}
	}

    #if ( (_CDD_SIMULATION == STD_OFF)||(_CDD_INTEGRATION == STD_ON) )
	Pwm3ph_Set_ShadowValSr1(UI8_PWM_TOM_ATOM_MOUDLE_SEL,\
							UI8_PWM_TOM_ATOM_CHANNEL_SEL_UT,ui16_Pwm_OnEdge_UT_SR1);
	Pwm3ph_Set_ShadowValSr0(UI8_PWM_TOM_ATOM_MOUDLE_SEL,\
							UI8_PWM_TOM_ATOM_CHANNEL_SEL_UT,ui16_Pwm_OffEdge_UT_SR0);
	Pwm3ph_Set_ShadowValSr1(UI8_PWM_TOM_ATOM_MOUDLE_SEL,\
							UI8_PWM_TOM_ATOM_CHANNEL_SEL_UB,ui16_Pwm_OffEdge_UB_SR1);
	Pwm3ph_Set_ShadowValSr0(UI8_PWM_TOM_ATOM_MOUDLE_SEL,\
							UI8_PWM_TOM_ATOM_CHANNEL_SEL_UB,ui16_Pwm_OnEdge_UB_SR0);

	Pwm3ph_Set_ShadowValSr1(UI8_PWM_TOM_ATOM_MOUDLE_SEL,\
							UI8_PWM_TOM_ATOM_CHANNEL_SEL_VT,ui16_Pwm_OnEdge_VT_SR1);
	Pwm3ph_Set_ShadowValSr0(UI8_PWM_TOM_ATOM_MOUDLE_SEL,\
							UI8_PWM_TOM_ATOM_CHANNEL_SEL_VT,ui16_Pwm_OffEdge_VT_SR0);
	Pwm3ph_Set_ShadowValSr1(UI8_PWM_TOM_ATOM_MOUDLE_SEL,\
							UI8_PWM_TOM_ATOM_CHANNEL_SEL_VB,ui16_Pwm_OffEdge_VB_SR1);
	Pwm3ph_Set_ShadowValSr0(UI8_PWM_TOM_ATOM_MOUDLE_SEL,\
							UI8_PWM_TOM_ATOM_CHANNEL_SEL_VB,ui16_Pwm_OnEdge_VB_SR0);

	Pwm3ph_Set_ShadowValSr1(UI8_PWM_TOM_ATOM_MOUDLE_SEL,\
							UI8_PWM_TOM_ATOM_CHANNEL_SEL_WT,ui16_Pwm_OnEdge_WT_SR1);
	Pwm3ph_Set_ShadowValSr0(UI8_PWM_TOM_ATOM_MOUDLE_SEL,\
							UI8_PWM_TOM_ATOM_CHANNEL_SEL_WT,ui16_Pwm_OffEdge_WT_SR0);
	Pwm3ph_Set_ShadowValSr1(UI8_PWM_TOM_ATOM_MOUDLE_SEL,\
							UI8_PWM_TOM_ATOM_CHANNEL_SEL_WB,ui16_Pwm_OffEdge_WB_SR1);
	Pwm3ph_Set_ShadowValSr0(UI8_PWM_TOM_ATOM_MOUDLE_SEL,\
							UI8_PWM_TOM_ATOM_CHANNEL_SEL_WB,ui16_Pwm_OnEdge_WB_SR0);
	#else
	out->Pwm_Ticks_OnEdge_UT_ui16 = ui16_Pwm_OnEdge_UT_SR1;
	out->Pwm_Ticks_OffEdge_UT_ui16 = ui16_Pwm_OffEdge_UT_SR0;
	out->Pwm_Ticks_OnEdge_UB_ui16 = ui16_Pwm_OnEdge_UB_SR0;
	out->Pwm_Ticks_OffEdge_UB_ui16 = ui16_Pwm_OffEdge_UB_SR1;

	out->Pwm_Ticks_OnEdge_VT_ui16 = ui16_Pwm_OnEdge_VT_SR1;
	out->Pwm_Ticks_OffEdge_VT_ui16 = ui16_Pwm_OffEdge_VT_SR0;
	out->Pwm_Ticks_OnEdge_VB_ui16 = ui16_Pwm_OnEdge_VB_SR0;
	out->Pwm_Ticks_OffEdge_VB_ui16 = ui16_Pwm_OffEdge_VB_SR1;

	out->Pwm_Ticks_OnEdge_WT_ui16 = ui16_Pwm_OnEdge_WT_SR1;
	out->Pwm_Ticks_OffEdge_WT_ui16 = ui16_Pwm_OffEdge_WT_SR0;
	out->Pwm_Ticks_OnEdge_WB_ui16 = ui16_Pwm_OnEdge_WB_SR0;
	out->Pwm_Ticks_OffEdge_WB_ui16 = ui16_Pwm_OffEdge_WB_SR1;
	#endif
	}
}
/*******************************************************************************
** Function Name	: Pwm3ph_Set_ShadowValSr0
** Parameter[in] 	: uint8 Moudle,uint8 Channel,uint32 Sr0Value
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	��None
** Description	  	: Set_ShadowValSr0
*******************************************************************************/
static void Pwm3ph_Set_ShadowValSr0(uint8 Moudle,uint8 Channel,uint32 Sr0Value)
{
#if (_CDD_SIMULATION == STD_OFF)
	#if (PWM3PH_TOM_ATOM_SEL == 0U)
	Gtm_SetTomShadowValSr0(Moudle,Channel,(uint16)Sr0Value);
	#elif (PWM3PH_TOM_ATOM_SEL == 1U)
	Gtm_SetAtomShadowValSr0(Moudle,Channel,Sr0Value);
	#endif
#endif
}

/*******************************************************************************
** Function Name	: Pwm3ph_Set_ShadowValSr1
** Parameter[in] 	: uint8 Moudle,uint8 Channel,uint32 Sr1Value
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	��None
** Description	  	: Set_ShadowValSr1
*******************************************************************************/
static void Pwm3ph_Set_ShadowValSr1(uint8 Moudle,uint8 Channel,uint32 Sr1Value)
{
#if (_CDD_SIMULATION == STD_OFF)
	#if (PWM3PH_TOM_ATOM_SEL == 0U)
	Gtm_SetTomShadowValSr1(Moudle,Channel,(uint16)Sr1Value);
	#elif (PWM3PH_TOM_ATOM_SEL == 1U)
	Gtm_SetAtomShadowValSr1(Moudle,Channel,Sr1Value);
	#endif
#endif
}

/*******************************************************************************
** Function Name	: Pwm3ph_Enable_OutputChannel
** Parameter[in] 	: uint8 Moudle,uint8 Channel
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	��None
** Description	  	: Enable_OutputChannel
*******************************************************************************/
static void Pwm3ph_Enable_OutputChannel(uint8 Moudle,uint8 Channel)
{
#if (_CDD_SIMULATION == STD_OFF)
	#if (PWM3PH_TOM_ATOM_SEL == 0U)
	Gtm_EnableTomChannel(Moudle,Channel);
	#elif (PWM3PH_TOM_ATOM_SEL == 1U)
	Gtm_EnableAtomChannel(Moudle,Channel);
	#endif
#endif
}

/*******************************************************************************
** Function Name	: Pwm3ph_Disable_OutputChannel
** Parameter[in] 	: uint8 Moudle,uint8 Channel
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	��None
** Description	  	: Disable_OutputChannel
*******************************************************************************/
static void Pwm3ph_Disable_OutputChannel(uint8 Moudle,uint8 Channel)
{
#if (_CDD_SIMULATION == STD_OFF)
	#if (PWM3PH_TOM_ATOM_SEL == 0U)
	Gtm_DisableTomChannel(Moudle,Channel);
	#elif (PWM3PH_TOM_ATOM_SEL == 1U)
	Gtm_DisableAtomChannel(Moudle,Channel);
	#endif
#endif
}

/*******************************************************************************
** Function Name	: Pwm3ph_Set_CN0
** Parameter[in] 	: uint8 Moudle,uint8 Channel,uint32 CnoValue
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	��None
** Description	  	: Set_CN0
*******************************************************************************/
static void Pwm3ph_Set_CN0(uint8 Moudle,uint8 Channel,uint32 CnoValue)
{
#if (_CDD_SIMULATION == STD_OFF)
	#if (PWM3PH_TOM_ATOM_SEL == 0U)
	Gtm_SetTomCounterCn0(Moudle,Channel,(uint16)CnoValue);
	#elif (PWM3PH_TOM_ATOM_SEL == 1U)
	Gtm_SetAtomCounterCn0(Moudle,Channel,CnoValue);
	#endif
#endif
}

/*******************************************************************************
** Function Name	: Pwm3ph_Output_UpOff_DownOff
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	��None
** Description	  	: UpOff_DownOff
*******************************************************************************/
static void Pwm3ph_Output_UpOff_DownOff(void)
{
	/* U �� */
	ui16_Pwm_OnEdge_UT_SR1 = \
			ui16_Pwm_Period_SR0 + U16_REGISTER_OFFSET_VALUE;  /*SR1*/
	ui16_Pwm_OffEdge_UT_SR0 = U16_REGISTER_OFFSET_VALUE; /*SR0*/
	/* CM0 defines the edge to SL value, CM1 defines the edge to ~SL value */
	ui16_Pwm_OnEdge_UB_SR0 = \
			ui16_Pwm_Period_SR0 + U16_REGISTER_OFFSET_VALUE; /*SR0*/
	ui16_Pwm_OffEdge_UB_SR1 = U16_REGISTER_OFFSET_VALUE; /*SR1*/

	/* V �� */
	ui16_Pwm_OnEdge_VT_SR1 = \
			ui16_Pwm_Period_SR0 + U16_REGISTER_OFFSET_VALUE;  /*SR1*/
	ui16_Pwm_OffEdge_VT_SR0 = U16_REGISTER_OFFSET_VALUE; /*SR0*/
	ui16_Pwm_OnEdge_VB_SR0 = \
			ui16_Pwm_Period_SR0 + U16_REGISTER_OFFSET_VALUE; /*SR0*/
	ui16_Pwm_OffEdge_VB_SR1 = U16_REGISTER_OFFSET_VALUE; /*SR1*/

	/* W �� */
	ui16_Pwm_OnEdge_WT_SR1 = \
			ui16_Pwm_Period_SR0 + U16_REGISTER_OFFSET_VALUE;  /*SR1*/
	ui16_Pwm_OffEdge_WT_SR0 = U16_REGISTER_OFFSET_VALUE; /*SR0*/
	ui16_Pwm_OnEdge_WB_SR0 = \
			ui16_Pwm_Period_SR0 + U16_REGISTER_OFFSET_VALUE; /*SR0*/
	ui16_Pwm_OffEdge_WB_SR1 = U16_REGISTER_OFFSET_VALUE; /*SR1*/
}

/*******************************************************************************
** Function Name	: Pwm3ph_Output_Normal
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	��None
** Description	  	: Output_Normal
*******************************************************************************/
static void Pwm3ph_Output_Normal(void)
{
	VAR_Pwm_Fault_Flag_u16 = PWM_FAULT_NONE;

	/* U */
#if 0
	if((ui16_Pwm_Ticks_OnEdge_UT < ui16_Pwm_Ticks_OffEdge_UB)
	 ||(uint16)(ui16_Pwm_Ticks_OnEdge_UT - ui16_Pwm_Ticks_OffEdge_UB)\
	  < U16_PWM_MIN_DEADTIME_VALUE)
	{
//		VAR_Pwm_Fault_Flag_u16 |= PWM_FAULT_FIRST_EDGE_U;
	}

	if((ui16_Pwm_Ticks_OffEdge_UT > ui16_Pwm_Ticks_OnEdge_UB )
	 ||(uint16)(ui16_Pwm_Ticks_OnEdge_UB - ui16_Pwm_Ticks_OffEdge_UT)\
	 < U16_PWM_MIN_DEADTIME_VALUE)
	{
//		VAR_Pwm_Fault_Flag_u16 |= PWM_FAULT_SECOND_EDGE_U;
	}

	if((ui16_Pwm_Ticks_OnEdge_UT >= ui16_Pwm_Ticks_OffEdge_UT)	/*SR1>SR0*/
	 ||(ui16_Pwm_Ticks_OffEdge_UT >= ui16_Pwm_Period_SR0))	/*SR0>Period*/
	{
//		VAR_Pwm_Fault_Flag_u16 |= PWM_FAULT_SR0_SR1_UT;
	}

	if((ui16_Pwm_Ticks_OffEdge_UB >= ui16_Pwm_Ticks_OnEdge_UB)	/*SR1>SR0*/
	 ||(ui16_Pwm_Ticks_OnEdge_UB >= ui16_Pwm_Period_SR0))	/*SR0>Period*/
	{
//		VAR_Pwm_Fault_Flag_u16 |= PWM_FAULT_SR0_SR1_UB;
	}
/********************************************************************************************/
	/* V */
	if((ui16_Pwm_Ticks_OnEdge_VT < ui16_Pwm_Ticks_OffEdge_VB)
	 ||(uint16)(ui16_Pwm_Ticks_OnEdge_VT - ui16_Pwm_Ticks_OffEdge_VB)\
	  < U16_PWM_MIN_DEADTIME_VALUE)
	{
//		VAR_Pwm_Fault_Flag_u16 |= PWM_FAULT_FIRST_EDGE_V;
	}
	if((ui16_Pwm_Ticks_OffEdge_VT > ui16_Pwm_Ticks_OnEdge_VB )
	 ||(uint16)(ui16_Pwm_Ticks_OnEdge_VB - ui16_Pwm_Ticks_OffEdge_VT)\
	 < U16_PWM_MIN_DEADTIME_VALUE)
	{
//		VAR_Pwm_Fault_Flag_u16 |= PWM_FAULT_SECOND_EDGE_V;
	}
	if((ui16_Pwm_Ticks_OnEdge_VT >= ui16_Pwm_Ticks_OffEdge_VT)	/*SR1>SR0*/
	 ||(ui16_Pwm_Ticks_OffEdge_VT >= ui16_Pwm_Period_SR0))	/*SR0>Period*/
	{
//		VAR_Pwm_Fault_Flag_u16 |= PWM_FAULT_SR0_SR1_VT;
	}
	if((ui16_Pwm_Ticks_OffEdge_VB >= ui16_Pwm_Ticks_OnEdge_VB)	/*SR1>SR0*/
	 ||(ui16_Pwm_Ticks_OnEdge_VB >= ui16_Pwm_Period_SR0))	/*SR0>Period*/
	{
//		VAR_Pwm_Fault_Flag_u16 |= PWM_FAULT_SR0_SR1_VB;
	}
/*************************************************************************************************/
	/* W */
	if((ui16_Pwm_Ticks_OnEdge_WT < ui16_Pwm_Ticks_OffEdge_WB)
	 ||(uint16)(ui16_Pwm_Ticks_OnEdge_WT - ui16_Pwm_Ticks_OffEdge_WB)\
	  < U16_PWM_MIN_DEADTIME_VALUE)
	{
//		VAR_Pwm_Fault_Flag_u16 |= PWM_FAULT_FIRST_EDGE_W;
	}
	if((ui16_Pwm_Ticks_OffEdge_WT > ui16_Pwm_Ticks_OnEdge_WB )
	 ||(uint16)(ui16_Pwm_Ticks_OnEdge_WB - ui16_Pwm_Ticks_OffEdge_WT)\
	 < U16_PWM_MIN_DEADTIME_VALUE)
	{
//		VAR_Pwm_Fault_Flag_u16 |= PWM_FAULT_SECOND_EDGE_W;
	}
	if((ui16_Pwm_Ticks_OnEdge_WT >= ui16_Pwm_Ticks_OffEdge_WT)	/*SR1>SR0*/
	 ||(ui16_Pwm_Ticks_OffEdge_WT >= ui16_Pwm_Period_SR0))	/*SR0>Period*/
	{
//		VAR_Pwm_Fault_Flag_u16 |= PWM_FAULT_SR0_SR1_WT;
	}
	if((ui16_Pwm_Ticks_OffEdge_WB >= ui16_Pwm_Ticks_OnEdge_WB)	/*SR1>SR0*/
	 ||(ui16_Pwm_Ticks_OnEdge_WB >= ui16_Pwm_Period_SR0))	/*SR0>Period*/
	{
//		VAR_Pwm_Fault_Flag_u16 |= PWM_FAULT_SR0_SR1_WB;
	}
#endif
/**********************************************************************************************/
	/*JEE_MISRA_RULES_14_03&2_02 It's Allowed*/
	if(VAR_Pwm_Fault_Flag_u16 == PWM_FAULT_NONE)
	{
		ui16_Pwm_OnEdge_UT_SR1 = ui16_Pwm_Ticks_OnEdge_UT;
		ui16_Pwm_OffEdge_UT_SR0 = ui16_Pwm_Ticks_OffEdge_UT;
		ui16_Pwm_OnEdge_UB_SR0 = ui16_Pwm_Ticks_OnEdge_UB;
		ui16_Pwm_OffEdge_UB_SR1 = ui16_Pwm_Ticks_OffEdge_UB;

		ui16_Pwm_OnEdge_VT_SR1 = ui16_Pwm_Ticks_OnEdge_VT;
		ui16_Pwm_OffEdge_VT_SR0 = ui16_Pwm_Ticks_OffEdge_VT;
		ui16_Pwm_OnEdge_VB_SR0 = ui16_Pwm_Ticks_OnEdge_VB;
		ui16_Pwm_OffEdge_VB_SR1 = ui16_Pwm_Ticks_OffEdge_VB;

		ui16_Pwm_OnEdge_WT_SR1 = ui16_Pwm_Ticks_OnEdge_WT;
		ui16_Pwm_OffEdge_WT_SR0 = ui16_Pwm_Ticks_OffEdge_WT;
		ui16_Pwm_OnEdge_WB_SR0 = ui16_Pwm_Ticks_OnEdge_WB;
		ui16_Pwm_OffEdge_WB_SR1 = ui16_Pwm_Ticks_OffEdge_WB;
	}
	else
	{
		/*JEE_MISRA_RULES_14_03&2_02 It's Allowed*/
		ui16_Pwm_Fault_Flag_Last = VAR_Pwm_Fault_Flag_u16;
		ui32_Pwm_Fault_Counter++;
	}
}

/*******************************************************************************
** Function Name	: Pwm3ph_Output_UpOff_DownOn
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	��None
** Description	  	: Output_UpOff_DownOn
*******************************************************************************/
static void Pwm3ph_Output_UpOff_DownOn(void)
{
	/* U  */
	/* 100% SL(SL=LOW)*/
	ui16_Pwm_OnEdge_UT_SR1 = \
			ui16_Pwm_Period_SR0 + U16_REGISTER_OFFSET_VALUE;  /*SR1*/
	ui16_Pwm_OffEdge_UT_SR0 = U16_REGISTER_OFFSET_VALUE; /*SR0*/
	ui16_Pwm_OnEdge_UB_SR0 = U16_REGISTER_OFFSET_VALUE;  /*SR0*/
	ui16_Pwm_OffEdge_UB_SR1 = \
			ui16_Pwm_Period_SR0 + U16_REGISTER_OFFSET_VALUE; /*SR1*/

	/* V  */
	ui16_Pwm_OnEdge_VT_SR1 = \
			ui16_Pwm_Period_SR0 + U16_REGISTER_OFFSET_VALUE;  /*SR1*/
	ui16_Pwm_OffEdge_VT_SR0 = U16_REGISTER_OFFSET_VALUE; /*SR0*/
	ui16_Pwm_OnEdge_VB_SR0 = U16_REGISTER_OFFSET_VALUE;  /*SR0*/
	ui16_Pwm_OffEdge_VB_SR1 = \
			ui16_Pwm_Period_SR0 + U16_REGISTER_OFFSET_VALUE; /*SR1*/

	/* W  */
	ui16_Pwm_OnEdge_WT_SR1 = \
			ui16_Pwm_Period_SR0 + U16_REGISTER_OFFSET_VALUE;  /*SR1*/
	ui16_Pwm_OffEdge_WT_SR0 = U16_REGISTER_OFFSET_VALUE; /*SR0*/
	ui16_Pwm_OnEdge_WB_SR0 = U16_REGISTER_OFFSET_VALUE;  /*SR0*/
	ui16_Pwm_OffEdge_WB_SR1 = \
			ui16_Pwm_Period_SR0 + U16_REGISTER_OFFSET_VALUE; /*SR1*/
}
#if (PWM3PH_PWM_MODE == 1U)
/*******************************************************************************
** Function Name	: Pwm3ph_Output_UpOn_DownOff
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	��None
** Description	  	: Output_UpOn_DownOff
*******************************************************************************/
static void Pwm3ph_Output_UpOn_DownOff(void)
{
	/* U �� */
	/* 0% SL(SL=LOW)*/
	ui16_Pwm_OnEdge_UT_SR1 = U16_REGISTER_OFFSET_VALUE; /*SR1*/
	ui16_Pwm_OffEdge_UT_SR0 = \
			ui16_Pwm_Period_SR0 + U16_REGISTER_OFFSET_VALUE; /*SR0*/
	/* 0% SL(SL=HIGH)*/
	ui16_Pwm_OnEdge_UB_SR0 = \
			ui16_Pwm_Period_SR0 + U16_REGISTER_OFFSET_VALUE; /*SR0*/
	ui16_Pwm_OffEdge_UB_SR1 = U16_REGISTER_OFFSET_VALUE; /*SR1*/

	/* V �� */
	ui16_Pwm_OnEdge_VT_SR1 = U16_REGISTER_OFFSET_VALUE; /*SR1*/
	ui16_Pwm_OffEdge_VT_SR0 = \
			ui16_Pwm_Period_SR0 + U16_REGISTER_OFFSET_VALUE; /*SR0*/
	ui16_Pwm_OnEdge_VB_SR0 = \
			ui16_Pwm_Period_SR0 + U16_REGISTER_OFFSET_VALUE; /*SR0*/
	ui16_Pwm_OffEdge_VB_SR1 = U16_REGISTER_OFFSET_VALUE; /*SR1*/

	/* W �� */
	ui16_Pwm_OnEdge_WT_SR1 = U16_REGISTER_OFFSET_VALUE; /*SR1*/
	ui16_Pwm_OffEdge_WT_SR0 = \
			ui16_Pwm_Period_SR0 + U16_REGISTER_OFFSET_VALUE; /*SR0*/
	ui16_Pwm_OnEdge_WB_SR0 = \
			ui16_Pwm_Period_SR0 + U16_REGISTER_OFFSET_VALUE; /*SR0*/
	ui16_Pwm_OffEdge_WB_SR1 = U16_REGISTER_OFFSET_VALUE; /*SR1*/
}
/*******************************************************************************
** Function Name	: Pwm3ph_Output_UpOn_DownOff
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	��None
** Description	  	: Output_UpOn_DownUOn
*******************************************************************************/
static void Pwm3ph_Output_UpOn_DownUOn(void)
{
	/* U �� */
	/* 0% SL(SL=LOW)*/
	ui16_Pwm_OnEdge_UT_SR1 = U16_REGISTER_OFFSET_VALUE; /*SR1*/
	ui16_Pwm_OffEdge_UT_SR0 = \
			ui16_Pwm_Period_SR0 + U16_REGISTER_OFFSET_VALUE; /*SR0*/
	/* 0% SL(SL=HIGH)*/
	ui16_Pwm_OnEdge_UB_SR0 = ui16_Pwm_Ticks_OnEdge_UB; /*SR0*/

	ui16_Pwm_OffEdge_UB_SR1 = ui16_Pwm_Ticks_OffEdge_UB ; /*SR1*/

	/* V �� */
	ui16_Pwm_OnEdge_VT_SR1 = U16_REGISTER_OFFSET_VALUE; /*SR1*/
	ui16_Pwm_OffEdge_VT_SR0 = \
			ui16_Pwm_Period_SR0 + U16_REGISTER_OFFSET_VALUE; /*SR0*/
	ui16_Pwm_OnEdge_VB_SR0 = \
			ui16_Pwm_Period_SR0 + U16_REGISTER_OFFSET_VALUE; /*SR0*/
	ui16_Pwm_OffEdge_VB_SR1 = U16_REGISTER_OFFSET_VALUE; /*SR1*/

	/* W �� */
	ui16_Pwm_OnEdge_WT_SR1 = U16_REGISTER_OFFSET_VALUE; /*SR1*/
	ui16_Pwm_OffEdge_WT_SR0 = \
			ui16_Pwm_Period_SR0 + U16_REGISTER_OFFSET_VALUE; /*SR0*/
	ui16_Pwm_OnEdge_WB_SR0 = \
			ui16_Pwm_Period_SR0 + U16_REGISTER_OFFSET_VALUE; /*SR0*/
	ui16_Pwm_OffEdge_WB_SR1 = U16_REGISTER_OFFSET_VALUE; /*SR1*/
}


/*******************************************************************************
** Function Name	: Pwm3ph_Output_UpOff_DownUOn
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	��None
** Description	  	: Output_UpUOn_DownOn
*******************************************************************************/
static void Pwm3ph_Output_UpUOn_DownOn(void)
{
	/* U  */
	/* 100% SL(SL=LOW)*/
	ui16_Pwm_OnEdge_UT_SR1 =  ui16_Pwm_Ticks_OnEdge_UT;/*SR1*/
	ui16_Pwm_OffEdge_UT_SR0 = ui16_Pwm_Ticks_OffEdge_UT; /*SR0*/

	ui16_Pwm_OnEdge_UB_SR0 = U16_REGISTER_OFFSET_VALUE;  /*SR0*/
	ui16_Pwm_OffEdge_UB_SR1 = \
			ui16_Pwm_Period_SR0 + U16_REGISTER_OFFSET_VALUE; /*SR1*/

	/* V  */
	ui16_Pwm_OnEdge_VT_SR1 = \
			ui16_Pwm_Period_SR0 + U16_REGISTER_OFFSET_VALUE;  /*SR1*/
	ui16_Pwm_OffEdge_VT_SR0 = U16_REGISTER_OFFSET_VALUE; /*SR0*/
	ui16_Pwm_OnEdge_VB_SR0 = U16_REGISTER_OFFSET_VALUE;  /*SR0*/
	ui16_Pwm_OffEdge_VB_SR1 = \
			ui16_Pwm_Period_SR0 + U16_REGISTER_OFFSET_VALUE; /*SR1*/

	/* W */
	ui16_Pwm_OnEdge_WT_SR1 = \
			ui16_Pwm_Period_SR0 + U16_REGISTER_OFFSET_VALUE;  /*SR1*/
	ui16_Pwm_OffEdge_WT_SR0 = U16_REGISTER_OFFSET_VALUE; /*SR0*/
	ui16_Pwm_OnEdge_WB_SR0 = U16_REGISTER_OFFSET_VALUE;  /*SR0*/
	ui16_Pwm_OffEdge_WB_SR1 = \
			ui16_Pwm_Period_SR0 + U16_REGISTER_OFFSET_VALUE; /*SR1*/
}
#endif

/*******************************************************************************
** Function Name	: Pwm3ph_ChangePeriod
** Parameter[in] 	: uint16 ui16_Period
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	��None
** Description	  	: ChangePeriod
*******************************************************************************/
static	void  Pwm3ph_ChangePeriod(uint16 ui16_Period)
{
	if(ui16_Period <= U16_PWM_MAX_PERIOD_VALUE)
	{
		ui16_Pwm_Period_Tick_Last = ui16_Period;
		ui16_Pwm_Period_SR0 = ui16_Period;

	#if (_CDD_SIMULATION == STD_OFF)
		Pwm3ph_Set_ShadowValSr1(UI8_PWM_TOM_ATOM_MOUDLE_SEL,\
				UI8_PWM_TOM_ATOM_CHANNEL_SEL_PERIOD_REF,((uint32)ui16_Pwm_Period_SR0/2U));

		Pwm3ph_Set_ShadowValSr0(UI8_PWM_TOM_ATOM_MOUDLE_SEL,\
				UI8_PWM_TOM_ATOM_CHANNEL_SEL_PERIOD_REF,ui16_Pwm_Period_SR0);

	#endif
		/*CM0 defines the edge to SL value, CM1 defines the edge to ~SL value*/
#if (UI8_PWM_ADC_MOUDLE_SEL == 0U)

		Pwm3ph_Set_ShadowValSr1(UI8_PWM_TOM_ATOM_MOUDLE_SEL,\
					UI8_PWM_TOM_ATOM_CHANNEL_SEL_ADC_TRIG,\
					(ui16_Pwm_Period_SR0/2U - CAL_Pwm3ph_AdcTriggleOffset_u16));
		Pwm3ph_Set_ShadowValSr0(UI8_PWM_TOM_ATOM_MOUDLE_SEL,\
							UI8_PWM_TOM_ATOM_CHANNEL_SEL_ADC_TRIG,\
							(ui16_Pwm_Period_SR0/2U));
#elif (UI8_PWM_ADC_MOUDLE_SEL == 1U)
	#if (_CDD_SIMULATION == STD_OFF)
		Pwm3ph_Set_ShadowValSr1(UI8_PWM_TOM_ATOM_MOUDLE_SEL,\
			UI8_PWM_TOM_ATOM_CHANNEL_SEL_ADC_TRIG,\
			(0));

		Pwm3ph_Set_ShadowValSr0(UI8_PWM_TOM_ATOM_MOUDLE_SEL,\
					UI8_PWM_TOM_ATOM_CHANNEL_SEL_ADC_TRIG,\
					(CAL_Pwm3ph_AdcTriggleOffset_u16 ) );
	#endif
#endif
	}
}

#if(UI8_PWM3PH_PARAMETER_TYPE == 3U)
/*******************************************************************************
** Function Name	: Pwm3ph_GetDataConversion
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	��None
** Description	  	: GetDataConversion
*******************************************************************************/
static	void Pwm3ph_GetDataConversion(void)
{
	float temp;
	static uint16 ui16_Pwm_Period_Tick; 	 			/* PWM Reference period count */
	static uint16 ui16_DeadTime_Tick = 260U;	/* Dead zone time count value */
	static uint16 ui16_Pwm_DutyU_Tick;			/* U PWM Duty cycle value */
	static uint16 ui16_Pwm_DutyV_Tick;			/* V PWM Duty cycle value */
	static uint16 ui16_Pwm_DutyW_Tick;			/* W PWM Duty cycle value */
	
	temp = CAL_PWM_Set_DeadTime_us_f32*100.0f;
	ui16_DeadTime_Tick = (uint16)( temp );
			


	if((VAR_Pwm_Freq_u16>U16_PWM_MAX_FREQ_VALUE) || \
			(VAR_Pwm_Freq_u16<U16_PWM_MIN_FREQ_VALUE))
	{

		VAR_Pwm_Freq_u16 = U16_PWM_DEF_FREQ_VALUE;
	}
	temp = ((float32)U32_PWM_GTM_CLOCK_VALUE)/((float32)VAR_Pwm_Freq_u16);
	ui16_Pwm_Period_Tick  = (uint16)(temp);

	Pwm3ph_ChangePeriod(ui16_Pwm_Period_Tick);// wth 20210121 change for random pwm
	
	temp = VAR_PwmDutyCyclePhaseU_f32*(float32)ui16_Pwm_Period_Tick;
	ui16_Pwm_DutyU_Tick = (uint16)(temp);
	
	temp = VAR_PwmDutyCyclePhaseV_f32*(float32)ui16_Pwm_Period_Tick;
	ui16_Pwm_DutyV_Tick = (uint16)(temp);
	
	temp = VAR_PwmDutyCyclePhaseW_f32*(float32)ui16_Pwm_Period_Tick;
	ui16_Pwm_DutyW_Tick = (uint16)(temp);


	/* U */
	/*JEE_MISRA_RULES_13_05 It's Allowed*/
	if(  (VAR_PwmDutyCyclePhaseU_f32 > CAL_Pwm3phB_ClosedThreshold_f32)&&(VAR_PwmDutyCyclePhaseU_f32 <= CAL_Pwm3ph_DutyMax_f32 ) )/*0.94 < x <= 0.999  U��������������������ȫ��*/
	{
		/*
		* example: period=100,duty=40,dead_time=2
		* OnEdge=(100-(40-2))/2 = 31,SR1=31(��30��1����)
		*/
		ui16_Pwm_Ticks_OnEdge_UT = (uint16)((ui16_Pwm_Period_Tick - \
				(ui16_Pwm_DutyU_Tick - ui16_DeadTime_Tick))/2U);
		/*example: period=100,duty=40,dead_time=2
		 * OffEdge=(100+(40-2))/2 = 69,SR0=69(��70С1������)*/
		ui16_Pwm_Ticks_OffEdge_UT = (uint16)((ui16_Pwm_Period_Tick + \
				(ui16_Pwm_DutyU_Tick - ui16_DeadTime_Tick))/2U);

		ui16_Pwm_Ticks_OnEdge_UB =  \
				ui16_Pwm_Period_SR0; /*SR0*/

		ui16_Pwm_Ticks_OffEdge_UB = U16_REGISTER_OFFSET_VALUE; /*SR1*/


	}
	else if( (VAR_PwmDutyCyclePhaseU_f32 <= CAL_Pwm3phB_ClosedThreshold_f32)&&(VAR_PwmDutyCyclePhaseU_f32 >= CAL_Pwm3phT_ClosedThreshold_f32) )/*0.06 =< x <=0.94  U����������������������������*/
	{
		/*example: period=100,duty=40,dead_time=2
		 * OnEdge=(100-(40-2))/2 = 31,SR1=31(��30��1����)*/
		ui16_Pwm_Ticks_OnEdge_UT = (uint16)((ui16_Pwm_Period_Tick - \
				(ui16_Pwm_DutyU_Tick - ui16_DeadTime_Tick))/2U);
		/*example: period=100,duty=40,dead_time=2
		 * OffEdge=(100+(40-2))/2 = 69,SR0=69(��70С1������)*/
		ui16_Pwm_Ticks_OffEdge_UT = (uint16)((ui16_Pwm_Period_Tick + \
				(ui16_Pwm_DutyU_Tick - ui16_DeadTime_Tick))/2U);

		/*example: period=100,duty=40,dead_time=2
		 * OnEdge=(100+(40+2))/2 = 71,SR0=71(��70��1����)*/
		ui16_Pwm_Ticks_OnEdge_UB = (uint16)((ui16_Pwm_Period_Tick + \
				(ui16_Pwm_DutyU_Tick + ui16_DeadTime_Tick))/2U);
		/*example: period=100,duty=40,dead_time=2
		 * OffEdge=(100-(40+2))/2 = 29,SR0=29(��30С1������)*/
		ui16_Pwm_Ticks_OffEdge_UB = (uint16)((ui16_Pwm_Period_Tick - \
				(ui16_Pwm_DutyU_Tick + ui16_DeadTime_Tick))/2U);
	}/*JEE_MISRA_RULES_13_05 It's Allowed*/
	else if( (VAR_PwmDutyCyclePhaseU_f32 < CAL_Pwm3phT_ClosedThreshold_f32)&&(VAR_PwmDutyCyclePhaseU_f32>=CAL_Pwm3ph_DutyMin_f32) )/*0.001<x<0.06  U������ȫ�أ�������������*/
	{

		ui16_Pwm_Ticks_OnEdge_UT = \
				ui16_Pwm_Period_SR0 + U16_REGISTER_OFFSET_VALUE;  /*SR1*/

		ui16_Pwm_Ticks_OffEdge_UT = U16_REGISTER_OFFSET_VALUE; /*SR0*/


		/*example: period=100,duty=40,dead_time=2
		 * OnEdge=(100+(40+2))/2 = 71,SR0=71(��70��1����)*/
		ui16_Pwm_Ticks_OnEdge_UB = (uint16)((ui16_Pwm_Period_Tick + \
				(ui16_Pwm_DutyU_Tick + ui16_DeadTime_Tick))/2U);
		/*example: period=100,duty=40,dead_time=2
		 * OffEdge=(100-(40+2))/2 = 29,SR0=29(��30С1������)*/
		ui16_Pwm_Ticks_OffEdge_UB = (uint16)((ui16_Pwm_Period_Tick - \
				(ui16_Pwm_DutyU_Tick + ui16_DeadTime_Tick))/2U);
	}
	else if( VAR_PwmDutyCyclePhaseU_f32<CAL_Pwm3ph_DutyMin_f32 )
	{
		ui16_Pwm_Ticks_OnEdge_UT = ui16_Pwm_Period_SR0+U16_REGISTER_OFFSET_VALUE;  /*SR1*/
		ui16_Pwm_Ticks_OffEdge_UT = U16_REGISTER_OFFSET_VALUE; /*SR0*/

		ui16_Pwm_Ticks_OnEdge_UB =  U16_REGISTER_OFFSET_VALUE; /*SR0*/
		ui16_Pwm_Ticks_OffEdge_UB = ui16_Pwm_Period_SR0+U16_REGISTER_OFFSET_VALUE; /*SR1*/
	}
	else if(VAR_PwmDutyCyclePhaseU_f32>CAL_Pwm3ph_DutyMax_f32)/*VAR_PwmDutyCyclePhaseU_f32>0.999*/
	{
		ui16_Pwm_Ticks_OnEdge_UT = U16_REGISTER_OFFSET_VALUE;  /*SR1*/
		ui16_Pwm_Ticks_OffEdge_UT =ui16_Pwm_Period_SR0; /*SR0*/

		ui16_Pwm_Ticks_OnEdge_UB = ui16_Pwm_Period_SR0; /*SR0*/

		ui16_Pwm_Ticks_OffEdge_UB = U16_REGISTER_OFFSET_VALUE; /*SR1*/
	}
	else
	{
		VAR_PWM3phUDuty_ERR_u8 = 1;
	}




/***********************************************************************************/
	/* V */
	/*JEE_MISRA_RULES_13_05 It's Allowed*/
	if(  (VAR_PwmDutyCyclePhaseV_f32>CAL_Pwm3phB_ClosedThreshold_f32) && (VAR_PwmDutyCyclePhaseV_f32<=CAL_Pwm3ph_DutyMax_f32 ) )
	{
		/*example: period=100,duty=40,dead_time=2
		 * OnEdge=(100-(40-2))/2 = 31,SR1=31(��30��1����)*/
		ui16_Pwm_Ticks_OnEdge_VT = (uint16)((ui16_Pwm_Period_Tick - \
				(ui16_Pwm_DutyV_Tick - ui16_DeadTime_Tick))/2U);
		/*example: period=100,duty=40,dead_time=2
		 * OffEdge=(100+(40-2))/2 = 69,SR0=69(��70С1������)*/
		ui16_Pwm_Ticks_OffEdge_VT = (uint16)((ui16_Pwm_Period_Tick + \
				(ui16_Pwm_DutyV_Tick - ui16_DeadTime_Tick))/2U);

		ui16_Pwm_Ticks_OnEdge_VB =  \
				ui16_Pwm_Period_SR0 ; /*SR0*/

		ui16_Pwm_Ticks_OffEdge_VB = U16_REGISTER_OFFSET_VALUE; /*SR1*/


	}/*JEE_MISRA_RULES_13_05 It's Allowed*/
	else if( (VAR_PwmDutyCyclePhaseV_f32 <= CAL_Pwm3phB_ClosedThreshold_f32)&&(VAR_PwmDutyCyclePhaseV_f32 >= CAL_Pwm3phT_ClosedThreshold_f32) )
	{
		/*example: period=100,duty=40,dead_time=2
		 * OnEdge=(100-(40-2))/2 = 31,SR1=31(��30��1����)*/
		ui16_Pwm_Ticks_OnEdge_VT = (uint16)((ui16_Pwm_Period_Tick - \
				(ui16_Pwm_DutyV_Tick - ui16_DeadTime_Tick))/2U);
		/*example: period=100,duty=40,dead_time=2
		 * OffEdge=(100+(40-2))/2 = 69,SR0=69(��70С1������)*/
		ui16_Pwm_Ticks_OffEdge_VT = (uint16)((ui16_Pwm_Period_Tick + \
				(ui16_Pwm_DutyV_Tick - ui16_DeadTime_Tick))/2U);
		/*example: period=100,duty=40,dead_time=2
		 * OnEdge=(100+(40+2))/2 = 71,SR0=71(��70��1����)*/
		ui16_Pwm_Ticks_OnEdge_VB = (uint16)((ui16_Pwm_Period_Tick + \
				(ui16_Pwm_DutyV_Tick + ui16_DeadTime_Tick))/2U);
		/*example: period=100,duty=40,dead_time=2
		 * OffEdge=(100-(40+2))/2 = 29,SR0=29(��30С1������)*/
		ui16_Pwm_Ticks_OffEdge_VB = (uint16)((ui16_Pwm_Period_Tick - \
				(ui16_Pwm_DutyV_Tick + ui16_DeadTime_Tick))/2U);
	}/*JEE_MISRA_RULES_13_05 It's Allowed*/
	else if((VAR_PwmDutyCyclePhaseV_f32 < CAL_Pwm3phT_ClosedThreshold_f32)&&(VAR_PwmDutyCyclePhaseV_f32>=CAL_Pwm3ph_DutyMin_f32) )
	{

		ui16_Pwm_Ticks_OnEdge_VT = \
				ui16_Pwm_Period_SR0 + U16_REGISTER_OFFSET_VALUE;  /*SR1*/

		ui16_Pwm_Ticks_OffEdge_VT = U16_REGISTER_OFFSET_VALUE; /*SR0*/


		/*example: period=100,duty=40,dead_time=2
		 * OnEdge=(100+(40+2))/2 = 71,SR0=71(��70��1����)*/
		ui16_Pwm_Ticks_OnEdge_VB = (uint16)((ui16_Pwm_Period_Tick + \
				(ui16_Pwm_DutyV_Tick + ui16_DeadTime_Tick))/2U);
		/*example: period=100,duty=40,dead_time=2
		 * OffEdge=(100-(40+2))/2 = 29,SR0=29(��30С1������)*/
		ui16_Pwm_Ticks_OffEdge_VB = (uint16)((ui16_Pwm_Period_Tick - \
				(ui16_Pwm_DutyV_Tick + ui16_DeadTime_Tick))/2U);
	}
	else if( VAR_PwmDutyCyclePhaseV_f32<CAL_Pwm3ph_DutyMin_f32 )
	{
		ui16_Pwm_Ticks_OnEdge_VT = \
				ui16_Pwm_Period_SR0 + U16_REGISTER_OFFSET_VALUE;  /*SR1*/
		ui16_Pwm_Ticks_OffEdge_VT = U16_REGISTER_OFFSET_VALUE; /*SR0*/

		ui16_Pwm_Ticks_OnEdge_VB =  U16_REGISTER_OFFSET_VALUE; /*SR0*/
		ui16_Pwm_Ticks_OffEdge_VB =  \
				ui16_Pwm_Period_SR0+U16_REGISTER_OFFSET_VALUE ; /*SR1*/
	}
	else if(VAR_PwmDutyCyclePhaseV_f32>CAL_Pwm3ph_DutyMax_f32)/*VAR_PwmDutyCyclePhaseV_f32>0.999*/
		{
			ui16_Pwm_Ticks_OnEdge_VT = U16_REGISTER_OFFSET_VALUE;  /*SR1*/
			ui16_Pwm_Ticks_OffEdge_VT =ui16_Pwm_Period_SR0; /*SR0*/

			ui16_Pwm_Ticks_OnEdge_VB = ui16_Pwm_Period_SR0 ; /*SR0*/

			ui16_Pwm_Ticks_OffEdge_VB = U16_REGISTER_OFFSET_VALUE; /*SR1*/

		}
	else
	{
		VAR_PWM3phVDuty_ERR_u8 = 1;
	}



/***********************************************************************************/
	/* W */
	/*JEE_MISRA_RULES_13_05 It's Allowed*/
	if(  (VAR_PwmDutyCyclePhaseW_f32>CAL_Pwm3phB_ClosedThreshold_f32) && (VAR_PwmDutyCyclePhaseW_f32<=CAL_Pwm3ph_DutyMax_f32 ) )
	{
		/*example: period=100,duty=40,dead_time=2
		 * OnEdge=(100-(40-2))/2 = 31,SR1=31(��30��1����)*/
		ui16_Pwm_Ticks_OnEdge_WT = (uint16)((ui16_Pwm_Period_Tick - \
				(ui16_Pwm_DutyW_Tick - ui16_DeadTime_Tick))/2U);
		/*example: period=100,duty=40,dead_time=2
		 * OffEdge=(100+(40-2))/2 = 69,SR0=69(��70С1������)*/
		ui16_Pwm_Ticks_OffEdge_WT = (uint16)((ui16_Pwm_Period_Tick + \
				(ui16_Pwm_DutyW_Tick - ui16_DeadTime_Tick))/2U);

		ui16_Pwm_Ticks_OnEdge_WB =  \
				ui16_Pwm_Period_SR0 ; /*SR0*/

		ui16_Pwm_Ticks_OffEdge_WB = U16_REGISTER_OFFSET_VALUE; /*SR1*/

	}/*JEE_MISRA_RULES_13_05 It's Allowed*/
	else if( (VAR_PwmDutyCyclePhaseW_f32 <= CAL_Pwm3phB_ClosedThreshold_f32)&&(VAR_PwmDutyCyclePhaseW_f32 >= CAL_Pwm3phT_ClosedThreshold_f32) )
	{
		/*example: period=100,duty=40,dead_time=2
		 * OnEdge=(100-(40-2))/2 = 31,SR1=31(��30��1����)*/
		ui16_Pwm_Ticks_OnEdge_WT = (uint16)((ui16_Pwm_Period_Tick - \
				(ui16_Pwm_DutyW_Tick - ui16_DeadTime_Tick))/2U);
		/*example: period=100,duty=40,dead_time=2
		 * OffEdge=(100+(40-2))/2 = 69,SR0=69(��70С1������)*/
		ui16_Pwm_Ticks_OffEdge_WT = (uint16)((ui16_Pwm_Period_Tick + \
				(ui16_Pwm_DutyW_Tick - ui16_DeadTime_Tick))/2U);
		/*example: period=100,duty=40,dead_time=2
		 * OnEdge=(100+(40+2))/2 = 71,SR0=71(��70��1����)*/
		ui16_Pwm_Ticks_OnEdge_WB = (uint16)((ui16_Pwm_Period_Tick + \
				(ui16_Pwm_DutyW_Tick + ui16_DeadTime_Tick))/2U);
		/*example: period=100,duty=40,dead_time=2
		 * OffEdge=(100-(40+2))/2 = 29,SR0=29(��30С1������)*/
		ui16_Pwm_Ticks_OffEdge_WB = (uint16)((ui16_Pwm_Period_Tick - \
				(ui16_Pwm_DutyW_Tick + ui16_DeadTime_Tick))/2U);
	}/*JEE_MISRA_RULES_13_05 It's Allowed*/
	else if( (VAR_PwmDutyCyclePhaseW_f32 < CAL_Pwm3phT_ClosedThreshold_f32)&&(VAR_PwmDutyCyclePhaseW_f32>=CAL_Pwm3ph_DutyMin_f32)  )
	{

		ui16_Pwm_Ticks_OnEdge_WT = \
				ui16_Pwm_Period_SR0 + U16_REGISTER_OFFSET_VALUE;  /*SR1*/

		ui16_Pwm_Ticks_OffEdge_WT = U16_REGISTER_OFFSET_VALUE; /*SR0*/


		/*example: period=100,duty=40,dead_time=2
		 * OnEdge=(100+(40+2))/2 = 71,SR0=71(��70��1����)*/
		ui16_Pwm_Ticks_OnEdge_WB = (uint16)((ui16_Pwm_Period_Tick + \
				(ui16_Pwm_DutyW_Tick + ui16_DeadTime_Tick))/2U);
		/*example: period=100,duty=40,dead_time=2
		 * OffEdge=(100-(40+2))/2 = 29,SR0=29(��30С1������)*/
		ui16_Pwm_Ticks_OffEdge_WB = (uint16)((ui16_Pwm_Period_Tick - \
				(ui16_Pwm_DutyW_Tick + ui16_DeadTime_Tick))/2U);
	}
	else if(VAR_PwmDutyCyclePhaseW_f32<CAL_Pwm3ph_DutyMin_f32)
	{
		ui16_Pwm_Ticks_OnEdge_WT = \
					ui16_Pwm_Period_SR0 + U16_REGISTER_OFFSET_VALUE;  /*SR1*/
		ui16_Pwm_Ticks_OffEdge_WT = U16_REGISTER_OFFSET_VALUE; /*SR0*/

		ui16_Pwm_Ticks_OnEdge_WB =  U16_REGISTER_OFFSET_VALUE; /*SR0*/
		ui16_Pwm_Ticks_OffEdge_WB = \
				ui16_Pwm_Period_SR0+U16_REGISTER_OFFSET_VALUE ;  /*SR1*/
	}
	else if(VAR_PwmDutyCyclePhaseW_f32>CAL_Pwm3ph_DutyMax_f32)/*VAR_PwmDutyCyclePhaseW_f32>0.999*/
	{
		ui16_Pwm_Ticks_OnEdge_WT = U16_REGISTER_OFFSET_VALUE;  /*SR1*/
		ui16_Pwm_Ticks_OffEdge_WT =ui16_Pwm_Period_SR0; /*SR0*/

		ui16_Pwm_Ticks_OnEdge_WB = ui16_Pwm_Period_SR0; /*SR0*/

		ui16_Pwm_Ticks_OffEdge_WB = U16_REGISTER_OFFSET_VALUE; /*SR1*/
	}
	else
	{
		VAR_PWM3phWDuty_ERR_u8 = 1;
	}
}
#endif

void Pwm3ph_ShunDownallChannelImmediately(void)
{

    if((VAR_TLF35584_InitFinish_Flag_b == TRUE)&&(VAR_TLF35584_SelfTestFinish_Flag_b == TRUE))
    {
		VAR_SS1_OC_u8 = 1;
		/*JEE_MISRA_RULES_11_04 It's Allowed*/
		P02_OUT.B.P1=0x0u;
		P02_OUT.B.P2=0x1u;
		P02_OUT.B.P3=0x0u;
		P02_OUT.B.P4=0x1u;
		P02_OUT.B.P5=0x0u;
		P02_OUT.B.P6=0x1u;

		P02_IOCR0.B.PC1=0x10u;
		P02_IOCR0.B.PC2=0x10u;
		P02_IOCR0.B.PC3=0x10u;
		P02_IOCR4.B.PC4=0x10u;
		P02_IOCR4.B.PC5=0x10u;
		P02_IOCR4.B.PC6=0x10u;






//		P02_OMR.B.PS1=0x0
//		P02_OMR.B.PS2=0x1
//		P02_OMR.B.PS3=0x0
//		P02_OMR.B.PS4=0x1
//		P02_OMR.B.PS5=0x0
//		P02_OMR.B.PS6=0x1
//
//		P02_OMSR.B.PS1=0x0
//		P02_OMSR.B.PS2=0x1
//		P02_OMSR.B.PS3=0x0
//		P02_OMSR.B.PS4=0x1
//		P02_OMSR.B.PS5=0x0
//		P02_OMSR.B.PS6=0x1
		/*JEE_MISRA_RULES_17_03 It's Allowed*/
		(void)Gtm_ModifyOutputCtrl (0, 0, 9, 0);
		(void)Gtm_ModifyOutputCtrl (0, 0, 10, 0);
		(void)Gtm_ModifyOutputCtrl (0, 0, 11, 0);
		(void)Gtm_ModifyOutputCtrl (0, 0, 12, 0);
		(void)Gtm_ModifyOutputCtrl (0, 0, 13, 0);
		(void)Gtm_ModifyOutputCtrl (0, 0, 14, 0);
    }

//		Gtm_SetTomCompareValCm1(UI8_PWM_TOM_ATOM_MOUDLE_SEL,\
//								UI8_PWM_TOM_ATOM_CHANNEL_SEL_UT,10001u);
//		Gtm_SetTomCompareValCm0(UI8_PWM_TOM_ATOM_MOUDLE_SEL,\
//								UI8_PWM_TOM_ATOM_CHANNEL_SEL_UT,1u);
//		Gtm_SetTomCompareValCm1(UI8_PWM_TOM_ATOM_MOUDLE_SEL,\
//								UI8_PWM_TOM_ATOM_CHANNEL_SEL_UB,1u);
//		Gtm_SetTomCompareValCm0(UI8_PWM_TOM_ATOM_MOUDLE_SEL,\
//								UI8_PWM_TOM_ATOM_CHANNEL_SEL_UB,10001u);
//
//		Gtm_SetTomCompareValCm1(UI8_PWM_TOM_ATOM_MOUDLE_SEL,\
//								UI8_PWM_TOM_ATOM_CHANNEL_SEL_VT,10001u);
//		Gtm_SetTomCompareValCm0(UI8_PWM_TOM_ATOM_MOUDLE_SEL,\
//								UI8_PWM_TOM_ATOM_CHANNEL_SEL_VT,1u);
//		Gtm_SetTomCompareValCm1(UI8_PWM_TOM_ATOM_MOUDLE_SEL,\
//								UI8_PWM_TOM_ATOM_CHANNEL_SEL_VB,1u);
//		Gtm_SetTomCompareValCm0(UI8_PWM_TOM_ATOM_MOUDLE_SEL,\
//								UI8_PWM_TOM_ATOM_CHANNEL_SEL_VB,10001u);
//
//		Gtm_SetTomCompareValCm1(UI8_PWM_TOM_ATOM_MOUDLE_SEL,\
//								UI8_PWM_TOM_ATOM_CHANNEL_SEL_WT,10001u);
//		Gtm_SetTomCompareValCm0(UI8_PWM_TOM_ATOM_MOUDLE_SEL,\
//								UI8_PWM_TOM_ATOM_CHANNEL_SEL_WT,1u);
//		Gtm_SetTomCompareValCm1(UI8_PWM_TOM_ATOM_MOUDLE_SEL,\
//								UI8_PWM_TOM_ATOM_CHANNEL_SEL_WB,1u);
//		Gtm_SetTomCompareValCm0(UI8_PWM_TOM_ATOM_MOUDLE_SEL,\
//								UI8_PWM_TOM_ATOM_CHANNEL_SEL_WB,10001u);
//
//
//		Gtm_SetTomShadowValSr1(UI8_PWM_TOM_ATOM_MOUDLE_SEL,\
//										UI8_PWM_TOM_ATOM_CHANNEL_SEL_UT,10001u);
//		Gtm_SetTomShadowValSr0(UI8_PWM_TOM_ATOM_MOUDLE_SEL,\
//										UI8_PWM_TOM_ATOM_CHANNEL_SEL_UT,1u);
//				Gtm_SetTomShadowValSr1(UI8_PWM_TOM_ATOM_MOUDLE_SEL,\
//										UI8_PWM_TOM_ATOM_CHANNEL_SEL_UB,1u);
//				Gtm_SetTomShadowValSr0(UI8_PWM_TOM_ATOM_MOUDLE_SEL,\
//										UI8_PWM_TOM_ATOM_CHANNEL_SEL_UB,10001u);
//
//				Gtm_SetTomShadowValSr1(UI8_PWM_TOM_ATOM_MOUDLE_SEL,\
//										UI8_PWM_TOM_ATOM_CHANNEL_SEL_VT,10001u);
//				Gtm_SetTomShadowValSr0(UI8_PWM_TOM_ATOM_MOUDLE_SEL,\
//										UI8_PWM_TOM_ATOM_CHANNEL_SEL_VT,1u);
//				Gtm_SetTomShadowValSr1(UI8_PWM_TOM_ATOM_MOUDLE_SEL,\
//										UI8_PWM_TOM_ATOM_CHANNEL_SEL_VB,1u);
//				Gtm_SetTomShadowValSr0(UI8_PWM_TOM_ATOM_MOUDLE_SEL,\
//										UI8_PWM_TOM_ATOM_CHANNEL_SEL_VB,10001u);
//
//				Gtm_SetTomShadowValSr1(UI8_PWM_TOM_ATOM_MOUDLE_SEL,\
//										UI8_PWM_TOM_ATOM_CHANNEL_SEL_WT,10001u);
//				Gtm_SetTomShadowValSr0(UI8_PWM_TOM_ATOM_MOUDLE_SEL,\
//										UI8_PWM_TOM_ATOM_CHANNEL_SEL_WT,1u);
//				Gtm_SetTomShadowValSr1(UI8_PWM_TOM_ATOM_MOUDLE_SEL,\
//										UI8_PWM_TOM_ATOM_CHANNEL_SEL_WB,1u);
//				Gtm_SetTomShadowValSr0(UI8_PWM_TOM_ATOM_MOUDLE_SEL,\
//										UI8_PWM_TOM_ATOM_CHANNEL_SEL_WB,10001u);
}
/*******************************************************************************

*******************************************************************************/
