
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
**  FILENAME  :  WdgTst_LCfg.c                                                **
**                                                                            **
**  DATE, TIME: 2021-09-16, 09:33:14                                          **
**                                                                            **
**  GENERATOR : Build b141014-0350                                            **
**                                                                            **
**  BSW MODULE DECRIPTION : WdgTst.bmd/xdm                                    **
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
**  DESCRIPTION  : WdgTst configuration                                       **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "WdgTst.h"

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
/* Memory mapping of the WDG configuration */
#define IFX_WDG_START_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"


/* WdgTst Module Configuration */
const WdgTst_ConfigType WdgTstCpu_ConfigRoot[WDGCPU_TST_CFG_PARAM_COUNT] =
{
  {
    TRUE,     (uint32)(0x00U)  }
};

const WdgTst_ConfigType WdgTstSafety_ConfigRoot[WDGSAFETY_TST_CFG_PARAM_COUNT] =
{
  {
    TRUE,    (uint32)(0x00U)
  }
};



#define IFX_WDG_STOP_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"
