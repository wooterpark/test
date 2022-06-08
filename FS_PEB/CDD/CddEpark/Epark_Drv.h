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
* $Name______: Epark_Drv.h$
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

#ifndef EPP_DRV_H_
#define EPP_DRV_H_

/*******************************************************************************
**                      Other Header File Inclusion                           **
*******************************************************************************/
#include "Std_Types.h"
#include "Cdd_Infra_Cfg.h"
/*******************************************************************************
**                          Macro Definition                         		  **
*******************************************************************************/
//#define EPP_IDLE		0U
#define CddEpark_FOREWARD	0U
#define CddEpark_INVERSION	1U
#define EPARK_USE_MCAL_MODE 0U	/*Whether to use the standard MCAL method*/

#define EPARK_CURRADC_LOWER_LIMITING_VALUE    25U
#define EPARK_CURRADC_HIGH_LIMITING_VALUE     4070U

#define EPARK_LOCATIONADC_LOWER_LIMITING_VALUE    25U
#define EPARK_LOCATIONADC_HIGH_LIMITING_VALUE     4070U
/*******************************************************************************
**                          Typedef Definition                         		  **
*******************************************************************************/

typedef struct {
	float32 Epark_Con_Duty_f32;
	uint8   Epark_Direction_b;
} EparkInIFType;

typedef struct {
	float32 iEpc;
	float32 posEpc;
	float32 posEpcMon;
} EparkOutIFType;

#if (_CDD_SIMULATION == STD_ON)
typedef struct {
	uint16 EparkH_Duty_Tick_u16;
	uint16 EparkL_Duty_Tick_u16;
} EparkOutSimIFType;
#endif

/*******************************************************************************
**                   Static Local Variables Definition              		  **
*******************************************************************************/
extern uint16  CddEpark_ADC_au16[4];
extern boolean VAR_CddEpark_Direction_b;
extern float32 VAR_CddEpark_Con_Duty_f32;

/*******************************************************************************
**                     Global Variables Definition              		      **
*******************************************************************************/


/*******************************************************************************
**                  Static Local Function Declaration            		      **
*******************************************************************************/


/*******************************************************************************
**                 		  Function Source Code            		              **
*******************************************************************************/


/*******************************************************************************
** Function Name	: Epp_AdcApi_Init
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: EPP Module initialization function
*******************************************************************************/
extern void Epp_AdcApi_Init(void);
/*******************************************************************************
** Function Name	: Epp_ISR_PWM
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: EPP Module interrupt handling function
*******************************************************************************/
#if (_CDD_SIMULATION == STD_OFF)
extern void Epark_SetOutput(const EparkInIFType *in, EparkOutIFType* out);
#else
extern void Epark_SetOutput(const EparkInIFType *in, EparkOutIFType* out);
#endif




#endif /* EPP_Drv_H_ */
