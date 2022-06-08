
/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2015)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  :  IRTst_LCfg.c                                                **
**                                                                            **
**  VERSION   : 0.0.2                                                         **
**                                                                            **
**  DATE, TIME: 2021-09-16, 09:33:12                                          **
**                                                                            **
**  GENERATOR : Build b141014-0350                                            **
**                                                                            **
**  BSW MODULE DECRIPTION : IRTst.bmd/xdm                                    **
**                                                                            **
**  VARIANT   : VariantLinkTime                                               **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  COMPILER  : Tasking / HighTec /WindRiver                                  **
**                                                                            **
**  AUTHOR    : DL-BLR-ATV-STC                                                **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : This file contains configuration settings for IR test     **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "IRTst.h"


#define IFX_IRTST_START_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"

/*******************************************************************************
**                      Private Macro definition                              **
*******************************************************************************/

/*******************************************************************************
**                      Configuration Options                                 **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/


/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/


/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Funtion Declarations                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/


/* Note: Non-Tresos users: Ensure to configure DMA channel as per below info.

Variant  	Dma_Channel_Range
TC21x    	0 - 15 
TC22x    	0 - 15 
TC23x    	0 - 15 
TC24x    	0 - 23 
TC26x    	0 - 47 
TC27x    	0 - 63 
TC29x   	0 - 127                                                           */

/* IRTest configuration  */
const IRTst_ConfigType IRTst_ConfigRoot[IRTST_CFG_PARAM_COUNT] =
{
/* DMA Select - DMA Channel - Register Set                                    */
{1U, 0U}

};
#define IFX_IRTST_STOP_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"    
