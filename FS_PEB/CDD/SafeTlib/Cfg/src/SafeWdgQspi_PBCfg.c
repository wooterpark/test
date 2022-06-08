
/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2013)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  :  SafeWdgQspi_PBCfg.c                                        **
**                                                                            **
**  VERSION   : 0.0.1                                                         **
**                                                                            **
**  DATE, TIME: 2016-08-03, 17:35:23                                          **
**                                                                            **
**  GENERATOR : Build b141014-0350                                            **
**                                                                            **
**  BSW MODULE DECRIPTION : SafeWdgQspi.bmd/xdm                             **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  COMPILER  : Tasking/HighTec/WindRiver                                     **
**                                                                            **
**  AUTHOR    : DL-BLR-ATV-STC                                                **
**                                                                            **                                                                      
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : SafeWdgQspi configuration generated file                 **
**                                                                            **
**  SPECIFICATION(S) :Aurix-HE_SafeTlib_DS_SafeWdgQspi.docm, Ver 0.1        **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "SafeWdgIf.h"
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
**                      Global Constant Definitions                           **
*******************************************************************************/
#define IFX_SWDG_START_SEC_POSTBUILDCFG_ASIL_B
#include "Ifx_MemMap.h"



/* QSPI Module configuration */
const SafeWdgQspi_ModuleConfigType SafeWdgQspi_ModuleConfigRoot =
{
		&MODULE_QSPI0,/* QSPI module 0selected*/
		&SRC_QSPI0TX,/*SRC register for Tx interrut*/
		&SRC_QSPI0RX,/*SRC register for Rx interrut*/
		14U,/* DMA Tx channel */ 
		15U,/* DMA Rx channel */ 
		0U,/* Receive input selection*/
		0U, /*SafeWdgQspiModuleTQLen*/
		NULL_PTR/* No User callback fucntion for SafeWdgQspi_CustomerTxRx()*/
    	};  

const SafeWdgQspi_ChannelConfigType SafeWdgQspi_ChannelConfigRoot[] = 
{
 {
		8U,/* Channel 8  slected */
		0U,/* Slave select SSOC.AOL*/
		
		0U,/*SafeWdgQspiChannelTQLen*/
		2U,/*SafeWdgQspiECONzBitSeg1*/
		2U,/*SafeWdgQspiECONzBitSeg2*/
		1U,/*SafeWdgQspiECONzBitSeg3*/
		0U,/*Clock Phase (ECONz.CPH)*/
		0U,/*Clock Polarity (ECONz.CPOL)*/
		1U,/*Parity Enable (ECONz.PAREN)*/
		0U,/*Even parity (BACON.PARTYP)*/
		1U,/*MSB first (BACON.MSB)*/
		14U,/*15bits data length (BACON.DL)*/
		3U,/*Idle delay prescaler (BACON.IPRE)*/
		0U,/*Idle delay length (BACON.IDLE)*/
		2U,/*Leading delay prescaler (BACON.LPRE)*/
		3U,/*Leading delay length (BACON.LEAD)*/
		2U,/*Trailing delay prescaler (BACON.TPRE)*/
		7U/* Trailing delay length (BACON.TRAIL)*/

 },

};
#define IFX_SWDG_STOP_SEC_POSTBUILDCFG_ASIL_B
#include "Ifx_MemMap.h"

/*******************************************************************************
**                      Global Funtion Declarations                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
