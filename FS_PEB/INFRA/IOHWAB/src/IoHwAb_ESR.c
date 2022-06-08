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
* $Name______: IOHWAB_ESR.c$
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
#include "IoHwAb_ESR.h"
#include "Mcal_Compiler.h"
#include "Os.h"

/*******************************************************************************
**                          Macro Definition                         		  **
*******************************************************************************/
#define IoHwAbW_START_SEC_VAR_CLEARED_BOOLEAN
#include "IoHwAbW_Cfg_MemMap.h"

#define IoHwAbW_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "IoHwAbW_Cfg_MemMap.h"

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
//boolean CPLD_TO_ARX_1_status;

/*******************************************************************************
**                  Static Local Function Declaration            		      **
*******************************************************************************/

/*******************************************************************************
**                 		  Function Source Code            		              **
*******************************************************************************/

/*******************************************************************************
** Function Name	: IoHwAb_ESR_Init
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: Reset Initialization
*******************************************************************************/
void IoHwAb_ESR_Init(void)
{
	uint32 coreId_u32;
	/* MISRA RULE 1.2, 2,2 VIOLATION:  This is a OS Function*/
	coreId_u32 = GetCoreID() ;
	(void)Mcal_ResetCpuENDINIT(-1);
	(void)Mcal_ResetCpuENDINIT( (sint8)coreId_u32 );

	MODULE_SCU.ESRCFG[1].B.EDCON = 2; 	//end detect falling edge of ESR1 (0: no detect; 1: rising; 2: falling; 3: both)
	MODULE_SCU.ESRCFG[0].B.EDCON = 2;	//end detect falling edge of ESR0 (0: no detect; 1: rising; 2: falling; 3: both)h)

	MODULE_SCU.IOCR.B.PC1 = 0;		//(mode: Input is active and not inverted; Output is inactive) detail: table 7-12 in UM
	MODULE_SCU.IOCR.B.PC0 = 0;

	MODULE_SCU.PDISC.B.PDIS0 = 0;
	MODULE_SCU.PDISC.B.PDIS1 = 0;

	MODULE_SCU.TRAPCLR.U |= 0x0BU;
	//enable NMI trap request
	MODULE_SCU.TRAPDIS.B.ESR0T = 0;	// 0: Enable, 1: Disable
	MODULE_SCU.TRAPDIS.B.ESR1T = 0;


	(void)Mcal_SetCpuENDINIT( (sint8)coreId_u32 );
	(void)Mcal_SetCpuENDINIT(-1);
}

/*******************************************************************************
** Function Name	: NMI_Trap
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	:
*******************************************************************************/
void NMI_Trap(void)
{
	MODULE_SCU.TRAPCLR.U |= 0x0BU; /*clear trap stat*/
}

