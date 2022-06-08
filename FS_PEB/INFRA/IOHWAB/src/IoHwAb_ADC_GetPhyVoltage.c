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
* $Name______: IOHWAB_ADC_GetPhyVoltage.c$
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
#include "IoHwAb_ADC.h"
#include "PhC_Drv.h"
#include "Dem.h"
#include "LvPower_Drv.h"
/*PROTECTED REGION ID(FileHeaderUserDefinedIncludes :IoHwAb_ADC_GetPhyVoltage) ENABLED START */
/* Start of user defined includes  - Do not remove this comment */
/* End of user defined includes - Do not remove this comment */
/*PROTECTED REGION END */

/*PROTECTED REGION ID(FileHeaderUserDefinedConstants :IoHwAb_ADC_GetPhyVoltage) ENABLED START */
/* Start of user defined constant definitions - Do not remove this comment */
/* End of user defined constant definitions - Do not remove this comment */
/*PROTECTED REGION END */

/*PROTECTED REGION ID(FileHeaderUserDefinedVariables :IoHwAb_ADC_GetPhyVoltage) ENABLED START */
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

uint16 Adc_RawData[ADC_NUM];

const ADCGen_PBCfg_S Adc_CfgData[ADC_NUM] =
		{
		    {0.00714F,0.0F},  {0.00714F,0.0F},  {1.0F,0.0F},      {0.00244F,0.0F},   /*AN3,AN4,AN5,AN6*/
		    {0.00122F,0.0F},  {0.00244F,0.0F},  {1.00000F,0.0F},  {0.00122F,0.0F},   /*AN11,AN12,AN13,AN14*/
		    {1.00000F,0.0F},  {0.00122F,0.0F},  {0.00714F,0.0F},  {0.00244F,0.0F},   /*AN17,AN19,AN21,AN22,*/
			{0.00244F,0.0F},  {0.00122F,0.0F},  {0.00122F,0.0F},  {0.00122F,0.0F},   /*AN23,AN24,AN25,AN26*/
			{0.00878F,0.0F},  {0.00122F,0.0F},  {0.00122F,0.0F},  {0.00005F,0.0F},   /*AN27,AN29,AN30,AN32*/
			{0.00690F,0.0F},  {1.00000F,0.0F},  {0.00122F,0.0F},  {0.00861F,0.0F},   /*AN33,AN34,AN35,AN40*/
			{1.00000F,0.0F},  {0.00878F,0.0F},  {0.00122F,0.0F},  {0.00122F,0.0F},   /*AN41,AN43,AN44,AN46,*/
			{1.00000F,0.0F},  {1.00000F,0.0F}                                        /*AN47,HW Version*/
		};
/*******************************************************************************
**                  Static Local Function Declaration            		      **
*******************************************************************************/

/*******************************************************************************
**                 		  Function Source Code            		              **
*******************************************************************************/

/*******************************************************************************
** Function Name	: IOHWAB_ADC_GetPhyVolate
** Parameter[in] 	: channel
** Parameter[out] 	: None
** Return Value	  	: RawVoltage
** Note	  			: None
** Description	  	: IoHwAb get ADC rawVoltage function
*******************************************************************************/
FUNC (void , IoHwAbW_CODE) IoHwAb_ADC_GetPhyVoltage/* return value & FctID */
(
		VAR(uint8, AUTOMATIC) Channel,
		CONSTP2VAR(float32, AUTOMATIC, RTE_APPL_DATA) RawVoltage
)
{
	const ADCGen_PBCfg_S* mAdc = &Adc_CfgData[Channel];

	*RawVoltage = (((float32)Adc_RawData[Channel]) * mAdc->ConvCoff) - (mAdc->ConvOffset);

}

/*******************************************************************************
** Function Name	: IOHWAB_ADC_DEM
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: Fault diagnosis of ADC sampling in IoHwAb
*******************************************************************************/













