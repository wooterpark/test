
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
**  FILENAME  :  SramEccTst_LCfg.c                                            **
**                                                                            **
**  DATE, TIME: 2021-09-16, 09:33:13                                          **
**                                                                            **
**  GENERATOR : Build b141014-0350                                            **
**                                                                            **
**  BSW MODULE DECRIPTION : SramEccTst.bmd/xdm                                **
**                                                                            **
**  VARIANT   : VariantLT                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  COMPILER  : Tasking / HighTec                                             **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : SramEccTst configuration                                   **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "SramEccTst.h"

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
#define IFX_SRAM_START_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"
/* SramEccTst Module Configuration */
const SramEccTst_ConfigType SramEccTst_ConfigRoot[SRAMECC_TST_CFG_PARAM_COUNT] = 
{
  {
    /* Memory select: */
                                        0X00007BD0U,
    
    /* Backup Memory: */
    (boolean)TRUE,           
  },  
  {
    /* Memory select: */
                0X0000000DU,
    
    /* Backup Memory: */
    (boolean)TRUE,           
  }  
};
#define IFX_SRAM_STOP_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"
