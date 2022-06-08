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
**  $FILENAME   : SmuTst.h $                                                 **
**                                                                            **
**  $CC VERSION : \main\17 $                                                 **
**                                                                            **
**  $DATE       : 2018-02-22 $                                               **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  AUTHOR    : DL-BLR-ATV-STC                                                **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : This file provides latent fault metric test routines for   **
**                 SMU test.                                                  **
**                                                                            **
**  REFERENCE(S) : Aurix_SafeTlib_DS_Smu_Test.docm                            **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/

#ifndef SMUTST_H
#define SMUTST_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Std_Types.h"
#include "Sl_ErrorCodes.h"
#include "Mcal_Compiler.h"
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

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/
#define IFX_SMUTST_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/
extern Sl_TstRsltType SmuTst_NmiTst
(
  const Sl_ParamSetType ParamSetIndex,
  const uint8 TstSeed,
  uint32* const TstSignature
);

extern Sl_TstRsltType SmuTst_IrqTst
(
  const Sl_ParamSetType ParamSetIndex,
  const uint8 TstSeed,
  uint32* const TstSignature
);

extern Sl_TstRsltType SmuTst_RtTst
(
  const Sl_ParamSetType ParamSetIndex,
  const uint8 TstSeed,
  uint32* const TstSignature
);
#define IFX_SMUTST_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"

#endif
