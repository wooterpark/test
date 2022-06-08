
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
**  FILENAME  :  FceTst_LCfg.c                                               **
**                                                                            **
**  DATE, TIME: 2021-09-16, 09:33:12                                          **
**                                                                            **
**  GENERATOR : Build b141014-0350                                            **
**                                                                            **
**  BSW MODULE DECRIPTION : FceTst.bmd/xdm                                   **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : FceTst configuration                                       **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "FceTst.h"

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
 
/* Memory mapping of the FCE configuration */
#define IFX_FCETST_START_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"

/* FceTst Module Configuration */
const FceTst_ConfigType FceTst_ConfigRoot[FCE_TST_CFG_PARAM_COUNT] = 
{
  {
   FCETST_8BIT_KERNEL_TEST
  },  
  {
   FCETST_16BIT_KERNEL_TEST
  },  
  {
   FCETST_32BIT_KERNEL_TEST
  }  
};
#define IFX_FCETST_STOP_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"
