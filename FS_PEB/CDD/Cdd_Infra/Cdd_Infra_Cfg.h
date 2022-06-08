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
*  1¡¢ new created
* V1.0.1;      2018.09.25 LQ
*  1¡¢Previously, there was a hard pin +VAR_Pwm_Mode_u8 to control the PWM output state respectively. Now, the state machine is unified into the Pwm3ph module.
* V1.0.2;      2018.10.15 LQ
*  1¡¢The Pwm3ph_SetOutput function, the unwanted state is commented out as a macro definition
*******************************************************************************/
#ifndef CDD_INFRA_CFG_H_
#define CDD_INFRA_CFG_H_

/*******************************************************************************
**                      Other Header File Inclusion                           **
*******************************************************************************/

/*******************************************************************************
**                          Macro Definition                         		  **
*******************************************************************************/
#define   _CDD_SIMULATION  0u /*set 1 Simulation mode;set 0 Normal mode  */
#define   _CDD_INTEGRATION 0u
/*******************************************************************************
**                          Typedef Definition                         		  **
*******************************************************************************/

/*******************************************************************************
**                  Global Variables With Extern Linkage               		  **
*******************************************************************************/

/*******************************************************************************
**                        Global Function Prototypes              	    	  **
*******************************************************************************/

#endif /* CDD_INFRA_CFG_H_ */


/*******************************************************************************

*******************************************************************************/
