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
* $Name______: xx.c$
* $Variant___: 0.0.0$
* $Revision__: 0$
* $Author____: xuwenliao$
**
**----------------------------------------------------------------------------**
** MAY BE CHANGED BY USER [Yes/No]: yes
**----------------------------------------------------------------------------**
** DESCRIPTION:
				Note Use English

**----------------------------------------------------------------------------**
** HISTORY:
V1.0.0:   Note Use English

V1.0.1:	  Note Use English


*******************************************************************************/
#ifndef DPT_DRV_H_
#define DPT_DRV_H_

/*******************************************************************************
**                      Other Header File Inclusion                           **
*******************************************************************************/
#include "Std_Types.h"

/*******************************************************************************
**                          Macro Definition                         		  **
**              CddDPT_LVTC27x_TEST_MODE------------->0   正式程序
**              CddDPT_LVTC27x_TEST_MODE------------->1   双脉冲程序
**              CddDPT_LVTC27x_TEST_MODE------------->2   EOL测试程序
**
*******************************************************************************/

#define CddDPT_SW_LVTC27x_NORMAL_MODE_SELECT		(0)/*控制是否使能正式程序测试*/
#define CddDPT_SW_LVTC27x_DPT_MODE_SELECT			(1)/*控制是否使能双脉冲程序测试*/
#define CddDPT_SW_LVTC27x_EOL_MODE_SELECT			(2)/*控制是否使能EOL测试程序测试*/

#define CddDPT_LVTC27x_TEST_MODE					(0)
/*******************************************************************************
**                          Typedef Definition                         		  **
*******************************************************************************/

/*******************************************************************************
**                  Global Variables With Extern Linkage               		  **
*******************************************************************************/
//extern uint8 CAL_Pulse_byte_au8[6];
/*******************************************************************************
**                        Global Function Prototypes              	    	  **
*******************************************************************************/



/*******************************************************************************
** Function Name	: DPT_MainFunction
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: Main function of double pulse program
*******************************************************************************/
extern	void DPT_MainFunction(void);
/*******************************************************************************
** Function Name	: DPT_IO_Init
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: Initialization of I / O port in double pulse experiment
*******************************************************************************/
extern	void DPT_IO_Init(void);


#endif /* DPT_DRV_H_ */

/*******************************************************************************

*******************************************************************************/
