#ifndef PMUECCEDCTST_H
#define PMUECCEDCTST_H

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
**   $FILENAME   : PmuEccEdcTst.h $                                           **
**                                                                            **
**   $CC VERSION : \main\24 $                                                 **
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
**  DESCRIPTION  : This file provides latent fault metric test routines for   **
**                 the PMU ECC and EDC error correction and detection         **
**                 mechanisms.                                                **
**                                                                            **
**  REFERENCE(S) : Aurix-HE_SafeTlib_DS_PmuEccEdcTest.docm, v1.5              **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

#include "Std_Types.h"
#include "Compiler_Cfg.h"
#include "PmuEccEdcTst_Cfg.h"
#include "PmuEccEdcTst_PtrnDef.h"
#include "Sl_Timeout.h"
#include "Sl_ErrorCodes.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
#define BITS_IN_BYTE (8U)
#define BYTES_IN_WORD (4U)

/* Macros to differentiate Trap Vector Table related source code from other 
source code*/
#define PMUECCEDC_TVT (1U)
#define PMUECCEDC_CODE (2U)
/*****************************************************************************/
/* Aurix internal timeout values */
/*****************************************************************************/

/* Timeout when waiting for the FLASH to enter page mode */
/* typically the page mode is entered within very less numbers of cycles.
 * the below value represents a loop counter, usually two loop iterations taking
 * already enough cycles to enter page mode
 * With a given safe margin of 5, the timeout shall not be lower than 10u
 */
#define PMUT_PAGE_MODE_TIMEOUT          ( 10U )

/* SMU alarm timeout. The value was chosen based on following considerations:
 * The worst case number of SMU cycles before an alarm gets visible is
 * n * 2 + 20 (with n = max. number of simultaneous alarms). With a maximum
 * of 32 * 7 alarms and maximum clock ratio fSPB/fSRI = 1/4 this evaluates to
 * 1872 CPU clock cycles. With 10 instructions executed in the loops using this
 * value, a value of 200 is appropriate:
 */
#define PMUT_SMU_ALM_TIMEOUT2           ( (uint32)(200U) )


/*******************************************************************************
**                      Typedefs                                              **
*******************************************************************************/

/* PMU ECC EDC unexpected alarms during test code execution */
typedef struct PmuEccEdcTst_UnexpAlarmType
{
    uint32  Sbe;
    uint32  Dbe;
    uint32  Mbe;
    uint32  Mon;
    uint32  Cmp;
    uint32  Crc32;
} PmuEccEdcTst_UnexpAlmType;

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/
/*NOTE: The following linker symbols are common across TASKING and GNU.
 The exact value of these symbols can be checked in the MAP file*/
/* Start and end address of PFLASH_MON_ECCEDC_RAMCODE section in PFlash*/
extern const uint32 LOC_START_PflashMon_EccEdc_PFLASHCODE[];
extern const uint32 LOC_END_PflashMon_EccEdc_PFLASHCODE[];

/* Start and end address of PFLASH_MON_ECCEDC_RAMCODE section in RAM*/
extern const uint32 LOC_START_PflashMon_EccEdc_RAM_RUNCODE[];
extern const uint32 LOC_END_PflashMon_EccEdc_RAM_RUNCODE[];

/* Start and end address of PMUECCEDCTST_TVT_RAMCODE section in PFlash*/
extern const uint32 LOC_START_PmuEccEdcTst_tvt_PFLASHCODE[];
extern const uint32 LOC_END_PmuEccEdcTst_tvt_PFLASHCODE[];

/* Start and end address of PMUECCEDCTST_TVT_CODE section in RAM*/
extern const uint32 LOC_START_PmuEccEdcTst_tvt_RAM_RUNCODE[];
extern const uint32 LOC_END_PmuEccEdcTst_tvt_RAM_RUNCODE[];

/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/
#define IFX_PMUECCEDCTST_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
extern Sl_TstRsltType PmuEccEdcTst_EccEdcTst
(
  const Sl_ParamSetType ParamSetIndex,
  const uint8 TstSeed,
  uint32* const TstSignature
);

extern PmuEccEdcTst_UnexpAlmType* PmuEccEdcTst_GetUnexpEccAlmListPtr
(
  void
);

extern uint32 PmuEccEdcTst_CalculateCrc32
(
  const uint32 StartAddr[], 
  uint32 Size
);
#define IFX_PMUECCEDCTST_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
/*******************************************************************************
**                Global Function like macro Definitions                      **
*******************************************************************************/

#endif /* PMUECCEDCTST_H */
