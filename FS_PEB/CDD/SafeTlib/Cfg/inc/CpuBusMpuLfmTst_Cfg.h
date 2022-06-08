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
**  FILENAME  :  CpuBusMpuLfmTst_Cfg.h                                        **
**                                                                            **
**  DATE, TIME: 2021-09-16, 09:33:12                                      **
**                                                                            **
**  GENERATOR : Build b141014-0350                                          **
**                                                                            **
**  BSW MODULE DECRIPTION : CpuBusMpuLfmTst.bmd /xdm                          **
**                                                                            **
**  VARIANT   : VariantLinkTime                                               **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  COMPILER  : Tasking / HighTec /WindRiver                                  **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : CpuBusMpuLfmTst configuration header file                  **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/
#ifndef CPUBUSMPULFMTST_CFG_H
#define CPUBUSMPULFMTST_CFG_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Platform_Types.h"
#include "Compiler_Cfg.h"
#include "CpuBusMpuLfmTst.h"


/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/



/* Number of different test configuration sets */
#define CPUBUSMPU_LFM_TST_CFG_PARAM_COUNT        ( 1 )


/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/
#define IFX_CPUBUSMPULFM_START_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"
/* Exported Bus MPU LFM test configuration:                                 */
extern const CpuBusMpuLfmTst_ConfigType
CpuBusMpuLfmTst_ConfigRoot[CPUBUSMPU_LFM_TST_CFG_PARAM_COUNT];
#define IFX_CPUBUSMPULFM_STOP_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"
/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/
/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/
#endif  /* CPUBUSMPULFMTST_CFG_H */
