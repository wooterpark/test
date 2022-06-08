#ifndef PMUECCEDCTST_PTRNDEF_H
#define PMUECCEDCTST_PTRNDEF_H

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
**   $FILENAME   : PmuEccEdcTst_PtrnDef.h $                                   **
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
**  DESCRIPTION  : This file contains the test patterns for the PMU ECC/EDC   **
**                 test in the different flash banks.                         **
**                                                                            **
**  REFERENCE(S) : Aurix_Alpha_DDS_PMU_ECC_EDC_Test, v0.1                     **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

#include "Std_Types.h"
#include "PmuEccEdcTst_Cfg.h"
#include "PflashMonTst_Cfg.h"
#include "Mcal_Compiler.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/* Total number of copies of each individual test pattern; multiple copies might
 * be used to prevent the PMU ECC Test from failing due to additional ECC errors
 * arising after a while. A value of 4 is recommended, however even a single
 * copy of each test is sufficient from safety point of view. If this value is
 * changed, also the pattern definitions as well as the bitflip tables in the
 * error programming module need to be adjusted:
 */
#define PMUT_TEST_PATTERN_COUNT         ( 4U )

/* Total number of dummy pages before actual test patterns: */
#define PMUT_DUMMY_PAGE_COUNT           ( 2U )

/* Total number of flash pages used per pattern set: */
#define PMUT_TEST_PAGE_PER_PTRN         ( 4U )

/* Number 32bit words per PFLASH page */
#define PMUT_WORDS_PER_PAGE             ( 8U )

/* Number of different 32bit words per reference page: */
#define PMUT_WORDS_PER_REF_PAGE         ( 2U )

#ifdef PFLASH_FIFO_BUFFERFULL_TEST_ENABLE
/* Total number of double bit error (DBE) pages for testing buffer full alarm*/
#define PMUT_DBE_PAGE_COUNT             ( 10U )
#endif

/*******************************************************************************
**                      Typedefs                                              **
*******************************************************************************/

/* Type definition of a PFLASH page: */
typedef struct PmuEccEdcTst_FlashPageType
{
  uint32 Data[PMUT_WORDS_PER_PAGE];
} PmuEccEdcTst_FlashPageType;

/* Type definition of a reference flash page (i.e words 1 to 7 of that page
 * contain the same value, only word 0 is different):
 */
typedef struct PmuEccEdcTst_FlashRefPageType
{
  uint32 Data[PMUT_WORDS_PER_REF_PAGE];
} PmuEccEdcTst_FlashRefPageType;

/* Type definition of a pattern set: */
typedef struct PmuEccEdcTst_TestPatternSetType
{
  PmuEccEdcTst_FlashPageType  Pattern[PMUT_TEST_PAGE_PER_PTRN];
} PmuEccEdcTst_TestPatternSetType;

/* Type definition of all test patterns for one PFLASH bank: */
typedef struct PmuEccEdcTst_TestPatternType
{
  /* Dummy pages before actual test patterns: */
  PmuEccEdcTst_FlashPageType      DummyPages[PMUT_DUMMY_PAGE_COUNT];

  /* Test pattern sets: */
  PmuEccEdcTst_TestPatternSetType Set[PMUT_TEST_PATTERN_COUNT];
#ifdef PFLASH_FIFO_BUFFERFULL_TEST_ENABLE
  /*DBE patterns for PFlash Monitor Buffer full test*/
  PmuEccEdcTst_FlashPageType      DBEPage[PMUT_DBE_PAGE_COUNT];
#endif
} PmuEccEdcTst_TestPatternType;


/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/
#define IFX_PMUECCEDCTST_START_SEC_CONST_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"
/* Test patterns in PFLASH: */
extern const PmuEccEdcTst_TestPatternType* const
      PmuEccEdcTst_TestPattern[PMU_ECC_EDC_TST_MAX_FLASHBANKS];

/* Array of valid code word patterns of all 4 pattern sets. These are used
 * as reference to check that good data is not actively corrupted:
 */
extern const PmuEccEdcTst_FlashRefPageType
 PmuEccEdcTst_VcwRefPtrn[PMUT_TEST_PATTERN_COUNT];

/* Array of single bit error patterns of all 4 pattern sets. These are used as
 * reference to check that single bit errors are corrected correctly:
 */
extern const PmuEccEdcTst_FlashRefPageType
 PmuEccEdcTst_SbeRefPtrn[PMUT_TEST_PATTERN_COUNT];

/* Array of double bit error patterns of all 4 pattern sets. These are used as
 * reference to check that double bit errors are corrected correctly:
 */
extern const PmuEccEdcTst_FlashRefPageType
 PmuEccEdcTst_DbeRefPtrn[PMUT_TEST_PATTERN_COUNT];

#define IFX_PMUECCEDCTST_STOP_SEC_CONST_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"
 /*Linker variables that reference the location of the patterns*/
#if (PMU_ECC_EDC_TST_PF0_SELECT == 1U)
  extern const uint32 LOC_START_PF0_PATTERNS[];

#endif
#if (PMU_ECC_EDC_TST_MAX_FLASHBANKS > 1U)
#if (PMU_ECC_EDC_TST_PF1_SELECT == 1U)
  extern const uint32 LOC_START_PF1_PATTERNS[];

#endif
#if (PMU_ECC_EDC_TST_MAX_FLASHBANKS > 2U)
#if (PMU_ECC_EDC_TST_PF2_SELECT == 1U)
  extern const uint32 LOC_START_PF2_PATTERNS[];
#endif
#if (PMU_ECC_EDC_TST_MAX_FLASHBANKS > 3U)
#if (PMU_ECC_EDC_TST_PF3_SELECT == 1U)
  extern const uint32 LOC_START_PF3_PATTERNS[];
#endif
#endif
#endif
#endif
/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/


/*******************************************************************************
**                Global Function like macro Definitions                      **
*******************************************************************************/

#endif /* PMUECCEDCTST_PTRNDEF_H */
