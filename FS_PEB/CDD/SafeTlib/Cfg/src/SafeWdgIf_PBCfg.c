
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
**  FILENAME  :  SafeWdgIf_PBCfg.c                                            **
**                                                                            **
**  DATE, TIME: 2018-05-02, 11:54:20                                          **
**                                                                            **
**  GENERATOR : Build b141014-0350                                            **
**                                                                            **
**  BSW MODULE DECRIPTION : SafeWdgIf.bmd/xdm                                 **
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
**  DESCRIPTION  : SafeWdgIf configuration generated file.                    **
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

/* configuration(s) for underlying watchdogs used by SafeWdgIf */

const SafeWdgIf_ConfigType SafeWdgIf_ConfigRoot[SAFEWDGIF_CFG_COUNT] = 
{
  {
	/* Internal watchdog configuration*/
		&SafeWdgInt_ConfigRoot[0],
		NULL_PTR
    }
};
#define IFX_SWDG_STOP_SEC_POSTBUILDCFG_ASIL_B
#include "Ifx_MemMap.h"
/*******************************************************************************
**                      Global Funtion Declarations                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
