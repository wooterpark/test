
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
**  FILENAME  :  PflashMonTst_LCfg.c                                               **
**                                                                            **
**  DATE, TIME: 2021-09-16, 09:33:14                                          **
**                                                                            **
**  GENERATOR : Build b141014-0350                                            **
**                                                                            **
**  BSW MODULE DECRIPTION : PmuEccEdcTst.bmd/xdm                              **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  COMPILER  : Tasking / HighTec                                             **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : PflashMonTst configuration                                 **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

#include "PflashMonTst.h"


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

#define IFX_PFLASHMON_START_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"

/* PFLASH monitor test configuration: */
const PflashMonTst_ConfigType
      PflashMonTst_ConfigRoot[PFLASH_MON_TST_CFG_PARAM_COUNT] =
{
  {
  	{
      (uint32)1u,  /* Enable test for PFLASH bank 0 */
      
      (uint32)1u,  /* Enable test for PFLASH bank 1 */
      
      
      
    }
  }

};

#define IFX_PFLASHMON_STOP_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"

