
/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2014)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  :  SfrTst_LCfg.c                                                **
**                                                                            **
**  DATE, TIME: 2021-09-18, 15:12:41                                          **
**                                                                            **
**  GENERATOR : Build b141014-0350                                            **
**                                                                            **
**  BSW MODULE DECRIPTION : SfrTst.bmd/xdm                                    **
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
**  DESCRIPTION  : This file contains configuration settings for SFR test     **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "SfrTst_Cfg.h"
#include "Ifx_reg.h"

#define IFX_SFRTST_START_SEC_LINKTIMECFG_ASIL_B
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


/* SfrTest configuration  */
const SfrTst_ConfigType RegisterConfig1[1] =
{
  /* Register Address,  Value,  Mask , BitWidth        */
  {&SCU_OSCCON.U, 0x7011aU,  0xffffffffU, STL_BIT_32}, 
};

/* The index given in the API function is used to choose which */
/* configuration is used from AllAvailableSets                 */
const SfrTst_ParamSetType AllAvailableSets[SFR_TST_CFG_PARAM_COUNT] =
{

  {1U,  0x1ec92141U, RegisterConfig1}
};
#define IFX_SFRTST_STOP_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"    
