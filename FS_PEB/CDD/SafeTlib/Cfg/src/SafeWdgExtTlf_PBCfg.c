
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
**  FILENAME  :  SafeWdgExtTlf_PBCfg.c                                        **
**                                                                            **
**  VERSION   : 0.0.1                                                         **
**                                                                            **
**  DATE, TIME: 2016-08-03, 17:35:23                                      **
**                                                                            **
**  GENERATOR : Build b141014-0350                                          **
**                                                                            **
**  BSW MODULE DECRIPTION : SafeWdgExtTlf.bmd/xdm                             **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  COMPILER  : Tasking / GNU / Diab                                          **
**                                                                            **
**  AUTHOR    : DL-BLR-ATV-STC                                                **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : SafeWdgExtTlf configuration generated file                 **
**                                                                            **
**  SPECIFICATION(S) :Aurix-HE_SafeTlib_DS_SafeWdgExtTlf.docm, Ver 0.1        **
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


/* external TLF watchdog configuration */
const SafeWdgExtTlf_ConfigType SafeWdgExtTlf_ConfigRoot[] =
{
	{
		&SafeWdgQspi_ChannelConfigRoot[0],
    TLF_WM_FWD_WWD_SPI,/*Type of Watchdog */
        0U, /*Watchdog cycle time.This value will set "WDCYC" bit in WDCFG0*/
        2U, /*open window time*/
    1U, /*Close window time*/
    4U, /*Functional watchdog time*/
 		9U,				/*Window Watchdog error threshold*/
		9U,				/*Functional Watchdog error threshold*/
 
		&MODULE_P20,		/*DUMMY PORT ,Will not be used since TLF_WM_WWD_WDI ia not selected.*/
		9U,				/*DUMMY PIN ,Will not be used since TLF_WM_WWD_WDI ia not selected.*/
		/* Signature XOR table: */
		{
      /*XOR Mask for sig;     Actual TLF Sig*/
			0xAE2AB4BFU,						  /* FF0FF000*/
			0x7E37E637U,						/* B040BF4F*/
			0x5AE1CD20U,						/* E919E616*/
			0x8AFC9FA8U,						/* A656A959*/
			0x1E27335U,						/* 75857A8A*/
			0xD1FF21BDU,						/* 3ACA35C5*/
			0xF5290AAAU,						/* 63936C9C*/
			0x25345822U,						/* 2CDC23D3*/
			0xEB447996U,						/* D222DD2D*/
			0x3B592B1EU,						/* 9D6D9262*/
			0x1F8F0009U,						/* C434CB3B*/
			0xCF925281U,						/* 8B7B8474*/
			0x448CBE1CU,						/* 58A857A7*/
			0x9491EC94U,						/* 17E718E8*/
			0xB047C783U,						/* 4EBE41B1*/
			0x605A950BU							/* 01F10EFE*/
		}
  }
};

#define IFX_SWDG_STOP_SEC_POSTBUILDCFG_ASIL_B
#include "Ifx_MemMap.h"
