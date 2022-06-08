#ifndef LMUBUSMPULFMTST_H
#define LMUBUSMPULFMTST_H

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
**   $FILENAME   : LmuBusMpuLfmTst.h $                                        **
**                                                                            **
**   $CC VERSION : \main\15 $                                                 **
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
**  DESCRIPTION  : This file contains a latent fault metric test for the LMU  **
**                 Bus Memory Protection Unit.                                **
**                                                                            **
**  SPECIFICATION(S) : Aurix_SafeTlib_DS_LMU_BusMpuTest.docm                  **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

#include "Platform_Types.h"
#include "Sl_Timeout.h"
#include "Sl_ErrorCodes.h"
#include "SmuInt.h"
#include "LmuBusMpuLfmTst_Cfg.h"
#include "Mcal_Compiler.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/


/* Total number of memory test ranges (do not change!):                     */
#define LBM_TEST_RANGE_COUNT                    ( 8U )

/* Size of single memory range for testing in bytes (= granularity of the CPU
   Bus Protection; do not change unless the granularity of the MPU has changed):
*/
#define LBM_TEST_RANGE_SIZE                 ( 32U )

/*******************************************************************************
**                      Typedefs                                              **
*******************************************************************************/
typedef struct LmuBusMpuLfmTst_ConfigType
{
  uint32 * TestMemory;
  uint32 * UnauthorizedAddr[1U];

}LmuBusMpuLfmTst_ConfigType;

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/
#define IFX_LMUBUSMPULFM_START_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"
/* Exported Bus MPU LFM test configuration:                                 */
extern const LmuBusMpuLfmTst_ConfigType 
   LmuBusMpuLfmTst_ConfigRoot[LMUBUSMPU_LFM_TST_CFG_PARAM_COUNT];
#define IFX_LMUBUSMPULFM_STOP_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"
/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/
#define IFX_LMUBUSMPULFM_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"

/* Test API:                                                                */
extern Sl_TstRsltType LmuBusMpuLfmTst_LmuBusMpuLfmTst
(
  const Sl_ParamSetType ParamSetIndex,
  const uint8 TstSeed,
  uint32* const TstSignature
);

#define IFX_LMUBUSMPULFM_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
/*******************************************************************************
**                Global Function like macro Definitions                      **
*******************************************************************************/

#endif /* LMUBUSMPULFMTST_H */

