/*******************************************************************************
**----------------------------------------------------------------------------**
** Copyright (c) 2018 by JEE.		All rights reserved.
** This software is copyright protected and proprietary to JEE.
** JEE grants to you only those rights as set out in the license conditions.
** All other rights remain with JEE.
**----------------------------------------------------------------------------**
**
* Administrative Information
* $Namespace_: \ArCfg\IOHWAB$
* $Class_____: C$
* $Name______: IOHWAB_ICU.h$
* $Variant___: 0.0.0$
* $Revision__: 0$
* $Author____: xuwenliao$
**
**----------------------------------------------------------------------------**
** MAY BE CHANGED BY USER [Yes/No]: YES
**----------------------------------------------------------------------------**
** DESCRIPTION:

**----------------------------------------------------------------------------**
** HISTORY:
V1.0.0:

*******************************************************************************/

#ifndef IOHWAB_API_IOHWAB_ICU_H_
#define IOHWAB_API_IOHWAB_ICU_H_
/*******************************************************************************
**                      Other Header File Inclusion                           **
*******************************************************************************/
#include "Icu_17_GtmCcu6.h"
/*******************************************************************************
**                          Macro Definition                         		  **
*******************************************************************************/

/*******************************************************************************
**                          Typedef Definition                         		  **
*******************************************************************************/

/*******************************************************************************
**                   Static Local Variables Definition              		  **
*******************************************************************************/

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
** Function Name	: IoHwAb_ICU_StartMeasurement
** Parameter[in] 	: channel
** Parameter[out] 	: Period
**                  : Dutycycle
** Return Value	  	: None
** Note	  			: None
** Description	  	: ICU module starts PWM capture and Measurement
*******************************************************************************/
extern void IoHwAb_ICU_StartMeasurement(void);

/*******************************************************************************
** Function Name	: IoHwAb_ICU_Get_3phPWMPeriod_DutyCycle
** Parameter[in] 	: channel
** Parameter[out] 	: Period
**                  : Dutycycle
** Return Value	  	: None
** Note	  			: None
** Description	  	: IoHwAb Obtain the period and duty cycle of three phase PWM
*******************************************************************************/
extern void IoHwAb_ICU_Get_3phPWMPeriod_DutyCycle (void);

#endif /* IOHWAB_API_IOHWAB_ICU_H_ */
