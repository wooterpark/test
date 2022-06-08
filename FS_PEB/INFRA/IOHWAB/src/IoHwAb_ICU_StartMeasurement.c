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
* $Name______: IoHwAb_ICU_StartMeasurement.c$
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

/*******************************************************************************
**                      Other Header File Inclusion                           **
*******************************************************************************/
#include "Rte_IoHwAbW.h"
#include "IoHwAb_ICU.h"
#include "Icu_17_GtmCcu6.h"
/*PROTECTED REGION ID(FileHeaderUserDefinedIncludes :IoHwAb_ICU_StartMeasurement) ENABLED START */
/* Start of user defined includes  - Do not remove this comment */
/* End of user defined includes - Do not remove this comment */
/*PROTECTED REGION END */

/*PROTECTED REGION ID(FileHeaderUserDefinedConstants :IoHwAb_ICU_StartMeasurement) ENABLED START */
/* Start of user defined constant definitions - Do not remove this comment */
/* End of user defined constant definitions - Do not remove this comment */
/*PROTECTED REGION END */

/*PROTECTED REGION ID(FileHeaderUserDefinedVariables :IoHwAb_ICU_StartMeasurement) ENABLED START */
/* Start of user variable defintions - Do not remove this comment  */
/* End of user variable defintions - Do not remove this comment  */
/*PROTECTED REGION END */

/*******************************************************************************
**                          Macro Definition                         		  **
*******************************************************************************/
#define IoHwAbW_START_SEC_CODE
#include "IoHwAbW_Cfg_MemMap.h"

#define IoHwAbW_STOP_SEC_CODE
#include "IoHwAbW_Cfg_MemMap.h"

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
FUNC (void, IoHwAbW_CODE) IoHwAb_ICU_StartMeasurement/* return value & FctID */
(
		void
)
{

	/* Local Data Declaration */

	/*PROTECTED REGION ID(UserVariables :IoHwAb_ICU_StartMeasurement) ENABLED START */
	/* Start of user variable defintions - Do not remove this comment  */
	/* End of user variable defintions - Do not remove this comment  */
	/*PROTECTED REGION END */
	Std_ReturnType retValue = RTE_E_OK;
	/*  -------------------------------------- Data Read -----------------------------------------  */
	Icu_17_GtmCcu6_StartSignalMeasurement(IcuConf_IcuChannel_H3phPWMUH_VGE_P01_7);
	Icu_17_GtmCcu6_StartSignalMeasurement(IcuConf_IcuChannel_H3phPWMUL_VGE_P11_0);
	Icu_17_GtmCcu6_StartSignalMeasurement(IcuConf_IcuChannel_H3phPWMVH_VGE_P02_9);
	Icu_17_GtmCcu6_StartSignalMeasurement(IcuConf_IcuChannel_H3phPWMVL_VGE_P10_7);
	Icu_17_GtmCcu6_StartSignalMeasurement(IcuConf_IcuChannel_H3phPWMWH_VGE_P11_8);
	Icu_17_GtmCcu6_StartSignalMeasurement(IcuConf_IcuChannel_H3phPWMWL_VGE_P00_4);
	Icu_17_GtmCcu6_StartSignalMeasurement(IcuConf_IcuChannel_DI_FLYBACKPWM);
//	Icu_17_GtmCcu6_StartSignalMeasurement(IcuConf_IcuChannel_Cpld_Alive_Sig);
	Icu_17_GtmCcu6_StartSignalMeasurement(IcuConf_IcuChannel_H3phPWMUH_P10_3);
	Icu_17_GtmCcu6_StartSignalMeasurement(IcuConf_IcuChannel_H3phPWMUL_P10_8);
	Icu_17_GtmCcu6_StartSignalMeasurement(IcuConf_IcuChannel_H3phPWMVH_P13_1);
	Icu_17_GtmCcu6_StartSignalMeasurement(IcuConf_IcuChannel_H3phPWMVL_P14_10);
	Icu_17_GtmCcu6_StartSignalMeasurement(IcuConf_IcuChannel_H3phPWMWH_P15_7);
	Icu_17_GtmCcu6_StartSignalMeasurement(IcuConf_IcuChannel_H3phPWMWL_P22_5);

	Icu_17_GtmCcu6_EnableEdgeDetection(IcuConf_IcuChannel_IcuChannel_SS1_P32_4);
	Icu_17_GtmCcu6_EnableNotification(IcuConf_IcuChannel_IcuChannel_SS1_P32_4);
	/*  -------------------------------------- Server Call Point  --------------------------------  */

	/*  -------------------------------------- CDATA ---------------------------------------------  */

	/*  -------------------------------------- Data Write ----------------------------------------  */

	/*  -------------------------------------- Trigger Interface ---------------------------------  */

	/*  -------------------------------------- Mode Management -----------------------------------  */

	/*  -------------------------------------- Port Handling -------------------------------------  */

	/*  -------------------------------------- Exclusive Area ------------------------------------  */

	/*  -------------------------------------- Multiple Instantiation ----------------------------  */

	/*PROTECTED REGION ID(User Logic :IoHwAb_ICU_StartMeasurement) ENABLED START */
	/* Start of user code - Do not remove this comment */
	/* End of user code - Do not remove this comment */
	/*PROTECTED REGION END */

}


