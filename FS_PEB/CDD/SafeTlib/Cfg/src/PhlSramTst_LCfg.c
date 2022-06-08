
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
**  FILENAME  :  PhlSramTst_LCfg.c                                            **
**                                                                            **
**  DATE, TIME: 2021-09-16, 09:33:13                                      **
**                                                                            **
**  GENERATOR : Build b141014-0350                                          **
**                                                                            **
**  BSW MODULE DECRIPTION : PhlSramTst.bmd/xdm                                **
**                                                                            **
**  VARIANT   : VariantLT                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  COMPILER  : Tasking / HighTec                                             **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : PhlSramTst configuration                                   **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "PhlSramTst.h"

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
**                      Global Function Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
 
/* Memory mapping of the SRAMECC configuration */
#define IFX_PHL_SRAM_START_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"
/* SramEccTst Module Configuration */
const PhlSramTst_ConfigType PhlSramTst_ConfigRoot[PHLSRAM_TST_CFG_PARAM_COUNT] = 
{
  {
    {
    /* Memory select: */
                    
	
	    0X000006FCU,

    0X00000000U,    
    
    },
    /* Backup Memory: */
    (boolean)FALSE,       
  }  
};
#define IFX_PHL_SRAM_STOP_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"
