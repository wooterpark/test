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
*  1、 new created
* V1.0.1;      2018.09.25 LQ
*  1、Previously, there was a hard pin +VAR_Pwm_Mode_u8 to control the PWM output state respectively. Now, the state machine is unified into the Pwm3ph module.
* V1.0.2;      2018.10.15 LQ
*  1、The Pwm3ph_SetOutput function, the unwanted state is commented out as a macro definition
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
/*PWM参数类型，12个开关点参数 OR 3个占空比参数*/
#define UI8_PWM3PH_PARAMETER_TYPE	 3U

/*PWM输出 模式*/
#define UI8_MODE_UP_ON_DOWN_UON		 5U		/* 		下桥仅开U项，上桥全开 */
#define UI8_MODE_UP_UON_DOWN_ON		 4U		/* 		上桥仅开U项，下桥全开 */
#define UI8_MODE_NORMAL				 3U		/*Run 正常控制 */
#define UI8_MODE_UP_ON_DOWN_OFF	 	 2U	    /* 		上桥开、下桥关 */
#define UI8_MODE_UP_OFF_DOWN_ON	 	 1U	    /*ASC   上桥关、下桥开 */
#define UI8_MODE_UP_OFF_DOWN_OFF	 0U		/*FreeWheel 上下桥都关，IDLE模式 */
/* PWM参数相关 */
#define U16_PWM_MAX_FREQ_VALUE		 15000U		/* 最大频率 */
#define U16_PWM_MIN_FREQ_VALUE		 1000U		/* 最小频率 */
#define U16_PWM_DEF_FREQ_VALUE		 10000U		/* 默认频率 */
#define	U16_PWM_MIN_TICKS_VALUE		 10U		/* PWM最小TICKS(导通时间) */
#define	U16_PWM_MIN_DEADTIME_VALUE	 10U		/* PWM最小死区时间TICKS */


/* PWM与实际硬件资源相关 */
#define PWM3PH_TOM_ATOM_SEL					 0U		/*0:TOM;1:ATOM*/

#define UI8_PWM_TOM_ATOM_MOUDLE_SEL		 	 0U		/*TOM/ATOM模块选择;0选择Tom模块，1选择Atom模块*/
#define UI8_PWM_TOM_ATOM_CHANNEL_SEL_UT		 9U		/*UT TOM/ATOM 通道选择*/
#define UI8_PWM_TOM_ATOM_CHANNEL_SEL_UB		 10U		/*UB TOM/ATOM 通道选择*/
#define UI8_PWM_TOM_ATOM_CHANNEL_SEL_VT		 11U		/*VT TOM/ATOM 通道选择*/
#define UI8_PWM_TOM_ATOM_CHANNEL_SEL_VB		 12U		/*VB TOM/ATOM 通道选择*/
#define UI8_PWM_TOM_ATOM_CHANNEL_SEL_WT		 13U		/*WT TOM/ATOM 通道选择*/
#define UI8_PWM_TOM_ATOM_CHANNEL_SEL_WB		 14U		/*WB TOM/ATOM 通道选择*/

/*PERIOD TOM/ATOM 通道选择*/
#define UI8_PWM_TOM_ATOM_CHANNEL_SEL_PERIOD_REF		8U
/*ADC TRIGGER TOM/ATOM 通道选择*/
#define UI8_PWM_TOM_ATOM_CHANNEL_SEL_ADC_TRIG		15U

/*0:多次采样取平均,适用TC23x;1:同步采样,适用TC27x/TC29x*/
#define UI8_PWM_ADC_MOUDLE_SEL					1U

#define U16_PWM_MAX_PERIOD_VALUE	 50000U 	/* PWM周期最大TICKS */
#define U32_PWM_GTM_CLOCK_VALUE		 100000000U	/* GTM 周期,100M */

#define PWM3PH_PWM_MODE              0U/*控制PWM_Mode,现在仅使用Run、ASC、Freewheel状态*/
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
