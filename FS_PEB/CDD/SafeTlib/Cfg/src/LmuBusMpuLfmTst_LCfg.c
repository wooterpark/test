
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
**  FILENAME  :  LmuBusMpuLfmTst_LCfg.c                                       **
**                                                                            **
**  DATE, TIME: 2021-09-16, 09:33:14                                      **
**                                                                            **
**  GENERATOR : Build b141014-0350                                          **
**                                                                            **
**  BSW MODULE DECRIPTION : LmuBusMpuLfmTst.bmd/xdm                           **
**                                                                            **
**  VARIANT   : VariantLinkTime                                               **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : LmuBusMpuLfmTst configuration                              **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "LmuBusMpuLfmTst.h"

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

#define IFX_LMUBUSMPULFM_START_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"



/* LMU Bus MPU LFM test configuration: */
const LmuBusMpuLfmTst_ConfigType
LmuBusMpuLfmTst_ConfigRoot[LMUBUSMPU_LFM_TST_CFG_PARAM_COUNT] =
{
  
  /* LmuBusMpuLfmTst_ConfigRoot[0]:*/
  {

      /* LmuBusMpuLfmTstTest Memory */
      (uint32*)0xb0000500U,
   
      /* LmuBusMpuLfmTst Unauthorized Address */
      {
        (uint32*)0xb0000100U
      }
      
  
  }
};


#define IFX_LMUBUSMPULFM_STOP_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"
