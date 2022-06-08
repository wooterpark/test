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
* $Name______: Pwm3ph.h$
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
*  1锟斤拷 new created
* V1.0.1;      2018.09.25 LQ
*  1锟斤拷Previously, there was a hard pin +VAR_Pwm_Mode_u8 to control the PWM output state respectively. Now, the state machine is unified into the Pwm3ph module.
* V1.0.2;      2018.10.15 LQ
*  1锟斤拷The Pwm3ph_SetOutput function, the unwanted state is commented out as a macro definition
*******************************************************************************/
#ifndef PWM_3PH_H_
#define PWM_3PH_H_

/*******************************************************************************
**                      Other Header File Inclusion                           **
*******************************************************************************/
#include "Pwm3ph_Cfg.h"
#include "TLF35584.h"

/*******************************************************************************
**                          Macro Definition                         		  **
*******************************************************************************/
#define PWM_FAULT_NONE				0x0000U
#define PWM_FAULT_FIRST_EDGE_U		0x0001U
#define PWM_FAULT_SECOND_EDGE_U		0x0002U
#define PWM_FAULT_FIRST_EDGE_V		0x0004U
#define PWM_FAULT_SECOND_EDGE_V		0x0008U
#define PWM_FAULT_FIRST_EDGE_W		0x0010U
#define PWM_FAULT_SECOND_EDGE_W		0x0020U
#define PWM_FAULT_SR0_SR1_UT		0x0040U
#define PWM_FAULT_SR0_SR1_UB		0x0080U
#define PWM_FAULT_SR0_SR1_VT		0x0100U
#define PWM_FAULT_SR0_SR1_VB		0x0200U
#define PWM_FAULT_SR0_SR1_WT		0x0400U
#define PWM_FAULT_SR0_SR1_WB		0x0800U

/*******************************************************************************
**                          Typedef Definition                         		  **
*******************************************************************************/

typedef struct {
	float32 PwmDutyCyclePhaseU1_f32;
	float32 PwmDutyCyclePhaseV1_f32;
	float32 PwmDutyCyclePhaseW1_f32;
	uint16  Pwm_Freq_u16;
	uint8   Pwm_Mode_u8;
} Pwm3phInIFType;

#if (_CDD_SIMULATION == STD_ON)
typedef struct {
	uint16 Pwm_Ticks_OnEdge_UT_ui16;
	uint16 Pwm_Ticks_OffEdge_UT_ui16;
	uint16 Pwm_Ticks_OnEdge_UB_ui16;
	uint16 Pwm_Ticks_OffEdge_UB_ui16;
	uint16 Pwm_Ticks_OnEdge_VT_ui16;
	uint16 Pwm_Ticks_OffEdge_VT_ui16;
	uint16 Pwm_Ticks_OnEdge_VB_ui16;
	uint16 Pwm_Ticks_OffEdge_VB_ui16;
	uint16 Pwm_Ticks_OnEdge_WT_ui16;
	uint16 Pwm_Ticks_OffEdge_WT_ui16;
	uint16 Pwm_Ticks_OnEdge_WB_ui16;
	uint16 Pwm_Ticks_OffEdge_WB_ui16;
} Pwm3phOutIFType;
#endif
/*******************************************************************************
**                  Global Variables With Extern Linkage               		  **
*******************************************************************************/
/*锟接口憋拷锟�*/
#if(UI8_PWM3PH_PARAMETER_TYPE == 3U)
extern	uint8 VAR_Pwm_Mode_u8;
extern	uint16 VAR_Pwm_Freq_u16;
extern	float32 VAR_Pwm_DeadTime_In_f32;

extern	float32 VAR_PwmDutyCyclePhaseU_f32;
extern	float32 VAR_PwmDutyCyclePhaseV_f32;
extern	float32 VAR_PwmDutyCyclePhaseW_f32;

extern	uint16 ui16_Pwm_Fault_Flag_Last;
extern	uint32 ui32_Pwm_Fault_Counter;
#endif

#if(UI8_PWM3PH_PARAMETER_TYPE == 12U)
extern	uint8 VAR_Pwm_Mode_u8;
extern	uint16 ui16_Pwm_Period_Tick;
extern	uint16 ui16_Pwm_Ticks_OnEdge_UT;
extern	uint16 ui16_Pwm_Ticks_OffEdge_UT;
extern	uint16 ui16_Pwm_Ticks_OnEdge_UB;
extern	uint16 ui16_Pwm_Ticks_OffEdge_UB;

extern	uint16 ui16_Pwm_Ticks_OnEdge_VT;
extern	uint16 ui16_Pwm_Ticks_OffEdge_VT;
extern	uint16 ui16_Pwm_Ticks_OnEdge_VB;
extern	uint16 ui16_Pwm_Ticks_OffEdge_VB;

extern	uint16 ui16_Pwm_Ticks_OnEdge_WT;
extern	uint16 ui16_Pwm_Ticks_OffEdge_WT;
extern	uint16 ui16_Pwm_Ticks_OnEdge_WB;
extern	uint16 ui16_Pwm_Ticks_OffEdge_WB;

extern	uint16 ui16_Pwm_Fault_Flag_Last;
extern	uint32 ui32_Pwm_Fault_Counter;
#endif

/*******************************************************************************
**                        Global Function Prototypes              	    	  **
*******************************************************************************/

/*******************************************************************************
** Function Name	: Pwm3ph_Init
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	锟斤拷
** Description	  	: inital
*******************************************************************************/
extern	void Pwm3ph_Init(void);

/*******************************************************************************
** Function Name	: Pwm3ph_EnableIsrTrigger
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	:
** Description	  	: EnableIsrTrigger
*******************************************************************************/
extern	void Pwm3ph_EnableIsrTrigger(void);

extern	void Pwm3ph_ShunDownallChannelImmediately(void);

/*******************************************************************************
** Function Name	: Pwm3ph_SetOutput
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	:
**
** Description	  	: SetOutput
*******************************************************************************/
#if ( (_CDD_SIMULATION == STD_OFF)||(_CDD_INTEGRATION == STD_ON) )
extern void Pwm3ph_SetOutput(const Pwm3phInIFType* in);
#else
extern void Pwm3ph_SetOutput(const Pwm3phInIFType* in, Pwm3phOutIFType* out );
#endif

/*******************************************************************************

*******************************************************************************/
#endif /* PWM_3PH_H_ */
