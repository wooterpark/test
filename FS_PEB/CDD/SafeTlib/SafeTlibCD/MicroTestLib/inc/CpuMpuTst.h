#ifndef CPUMPUTST_H
#define CPUMPUTST_H

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
**   $FILENAME   : CpuMpuTst.h $                                              **
**                                                                            **
**   $CC VERSION : \main\13 $                                                 **
**                                                                            **
**   $DATE       : 2018-02-22 $                                               **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  AUTHOR    : DL-BLR-ATV-STC                                                **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : This file contains latent fault metric test for the CPU    **
**                 Memory Protection Unit.                                    **
**                                                                            **
**  REFERENCE(S) : Aurix_Alpha_DDS_CPU_MPU_Test, v0.4                         **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "CpuMpuTst_Cfg.h"
#include "Platform_Types.h"
#include "Sl_Timeout.h"
#include "Sl_ErrorCodes.h"
#include "Mcal_Compiler.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Typedefs                                              **
*******************************************************************************/

  /* type in which each bit signifies enabling/disabling testing of each memory
     protection range:
  */
  typedef uint16 CpuMpuTst_RangeEnType;
  
  /* CPU MPU test configuration structure:                  */
  typedef struct CpuMpuTst_TestCfg
  {
    CpuMpuTst_RangeEnType  DataRangeEn;
    CpuMpuTst_RangeEnType  CodeRangeEn;
  } CpuMpuTst_TestCfgType;

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/
#define IFX_CPUMPUTST_START_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"
/* Exported CPU MPU test configuration:                                     */
extern const CpuMpuTst_TestCfgType CpuMpuTst_ConfigRoot[CPU_MPU_TST_CFG_PARAM_COUNT];
#define IFX_CPUMPUTST_STOP_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"
/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/
#define IFX_CPUMPUTST_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
/* Test API:                                                                */
extern Sl_TstRsltType CpuMpuTst_CpuMpuTst(const Sl_ParamSetType ParamSetIndex,
                                          const uint8 TstSeed,
                                          uint32* const TstSignature);
#define IFX_CPUMPUTST_STOP_SEC_CODE_8BYTE_ALIGN_ASIL_B
#include "Ifx_MemMap.h"
/*******************************************************************************
**                Global Function like macro Definitions                      **
*******************************************************************************/

#endif /* CPUMPUTST_H */

