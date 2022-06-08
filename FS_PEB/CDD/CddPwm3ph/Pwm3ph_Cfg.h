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
* $Name______: Pwm3ph_Cfg.c$
* $Variant___: 0.0.0$
* $Revision__: 0$
* $Author____: LQ$
**
**----------------------------------------------------------------------------**
** MAY BE CHANGED BY USER [Yes/No]: Yes
**----------------------------------------------------------------------------**
** DESCRIPTION:
** Three - phase six - channel PWM output drive source file
*******************************************************************************
* $History__:$
* V0.0.0;      2018.08.01 LQ
*  1�� new created
* V1.0.1;      2018.09.25 LQ
*  1��Previously, there was a hard pin +VAR_Pwm_Mode_u8 to control the PWM output state respectively. Now, the state machine is unified into the Pwm3ph module.
* V1.0.2;      2018.10.15 LQ
*  1��The Pwm3ph_SetOutput function, the unwanted state is commented out as a macro definition
*******************************************************************************/
#ifndef PWM3PH_CFG_H_
#define PWM3PH_CFG_H_

/*******************************************************************************
**                      Other Header File Inclusion                           **
*******************************************************************************/
#include "Std_Types.h"
#include "Cdd_Infra_Cfg.h"
/*******************************************************************************
**                          Macro Definition                         		  **
*******************************************************************************/
/*PWM�������ͣ�12�����ص���� OR 3��ռ�ձȲ���*/
#define UI8_PWM3PH_PARAMETER_TYPE	 3U

/*PWM��� ģʽ*/
#define UI8_MODE_UP_ON_DOWN_UON		 5U		/* 		���Ž���U�����ȫ�� */
#define UI8_MODE_UP_UON_DOWN_ON		 4U		/* 		���Ž���U�����ȫ�� */
#define UI8_MODE_NORMAL				 3U		/*Run �������� */
#define UI8_MODE_UP_ON_DOWN_OFF	 	 2U	    /* 		���ſ������Ź� */
#define UI8_MODE_UP_OFF_DOWN_ON	 	 1U	    /*ASC   ���Źء����ſ� */
#define UI8_MODE_UP_OFF_DOWN_OFF	 0U		/*FreeWheel �����Ŷ��أ�IDLEģʽ */
/* PWM������� */
#define U16_PWM_MAX_FREQ_VALUE		 15000U		/* ���Ƶ�� */
#define U16_PWM_MIN_FREQ_VALUE		 1000U		/* ��СƵ�� */
#define U16_PWM_DEF_FREQ_VALUE		 10000U		/* Ĭ��Ƶ�� */
#define	U16_PWM_MIN_TICKS_VALUE		 10U		/* PWM��СTICKS(��ͨʱ��) */
#define	U16_PWM_MIN_DEADTIME_VALUE	 10U		/* PWM��С����ʱ��TICKS */


/* PWM��ʵ��Ӳ����Դ��� */
#define PWM3PH_TOM_ATOM_SEL					 0U		/*0:TOM;1:ATOM*/

#define UI8_PWM_TOM_ATOM_MOUDLE_SEL		 	 0U		/*TOM/ATOMģ��ѡ��;0ѡ��Tomģ�飬1ѡ��Atomģ��*/
#define UI8_PWM_TOM_ATOM_CHANNEL_SEL_UT		 9U		/*UT TOM/ATOM ͨ��ѡ��*/
#define UI8_PWM_TOM_ATOM_CHANNEL_SEL_UB		 10U		/*UB TOM/ATOM ͨ��ѡ��*/
#define UI8_PWM_TOM_ATOM_CHANNEL_SEL_VT		 11U		/*VT TOM/ATOM ͨ��ѡ��*/
#define UI8_PWM_TOM_ATOM_CHANNEL_SEL_VB		 12U		/*VB TOM/ATOM ͨ��ѡ��*/
#define UI8_PWM_TOM_ATOM_CHANNEL_SEL_WT		 13U		/*WT TOM/ATOM ͨ��ѡ��*/
#define UI8_PWM_TOM_ATOM_CHANNEL_SEL_WB		 14U		/*WB TOM/ATOM ͨ��ѡ��*/

/*PERIOD TOM/ATOM ͨ��ѡ��*/
#define UI8_PWM_TOM_ATOM_CHANNEL_SEL_PERIOD_REF		8U
/*ADC TRIGGER TOM/ATOM ͨ��ѡ��*/
#define UI8_PWM_TOM_ATOM_CHANNEL_SEL_ADC_TRIG		15U

/*0:��β���ȡƽ��,����TC23x;1:ͬ������,����TC27x/TC29x*/
#define UI8_PWM_ADC_MOUDLE_SEL					1U

#define U16_PWM_MAX_PERIOD_VALUE	 50000U 	/* PWM�������TICKS */
#define U32_PWM_GTM_CLOCK_VALUE		 100000000U	/* GTM ����,100M */

#define PWM3PH_PWM_MODE              0U/*����PWM_Mode,���ڽ�ʹ��Run��ASC��Freewheel״̬*/
/*******************************************************************************
**                          Typedef Definition                         		  **
*******************************************************************************/

/*******************************************************************************
**                  Global Variables With Extern Linkage               		  **
*******************************************************************************/

/*******************************************************************************
**                        Global Function Prototypes              	    	  **
*******************************************************************************/

#endif /* PWM3PH_CFG_H_ */


/*******************************************************************************

*******************************************************************************/
