
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
**  FILENAME  :  CpuMpuTst_LCfg.c                                             **
**                                                                            **
**  DATE, TIME: 2021-09-16, 09:33:12                                          **
**                                                                            **
**  GENERATOR : Build b141014-0350                                            **
**                                                                            **
**  BSW MODULE DECRIPTION : CpuMpuTst.bmd/xdm                                 **
**                                                                            **
**  VARIANT   : VariantLinkTime                                               **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  COMPILER  : Tasking / HighTec /WindRiver                                  **
**                                                                            **
**  AUTHOR    : SafeTlib Team                                                 **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : This file contains configuration settings for CPU MPU test **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Include module header File */ 
#include "CpuMpuTst.h"


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
/* Memory mapping of the CPUMPU configuration */
#define IFX_CPUMPUTST_START_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"



/* CPU MPU test configuration  */
const CpuMpuTst_TestCfgType CpuMpuTst_ConfigRoot[CPU_MPU_TST_CFG_PARAM_COUNT] =
{
    /* CpuMpuTst_ConfigRoot[0]: */
    {
      /*  .DataRangeEn:  */
      (CpuMpuTst_RangeEnType)0xffffU,

      /*  .CodeRangeEn:  */
      (CpuMpuTst_RangeEnType)0xffU
    }};
#define IFX_CPUMPUTST_STOP_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"
