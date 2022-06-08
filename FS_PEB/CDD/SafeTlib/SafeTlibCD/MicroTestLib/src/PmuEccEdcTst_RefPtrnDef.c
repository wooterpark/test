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
**   $FILENAME   : PmuEccEdcTst_RefPtrnDef.c $                                **
**                                                                            **
**   $CC VERSION : \main\6 $                                                  **
**                                                                            **
**   $DATE       : 2016-06-02 $                                               **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  AUTHOR    : DL-BLR-ATV-STC                                                **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : This file contains the test pattern descriptors for the    **
**                 PMU ECC/EDC test in the different flash banks.             **
**                                                                            **
**  REFERENCE(S) : Aurix_SafeTlib_DS_Pflash_ECC_Test.docm, v3.1               **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "PmuEccEdcTst_PtrnDef.h"
/*******************************************************************************
**                      Extern  Definitions                                   **
*******************************************************************************/

/*******************************************************************************
**                      Local Macro Definitions                               **
*******************************************************************************/


/*******************************************************************************
**                      Local Type Definitions                                **
*******************************************************************************/
 

/******************************************************************************
**                        Local object definitions                            *
******************************************************************************/

#define IFX_PMUECCEDCTST_START_SEC_CONST_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"

/* Pointer to the test patterns of all FLASH BANKs: */
const PmuEccEdcTst_TestPatternType* const
      PmuEccEdcTst_TestPattern[PMU_ECC_EDC_TST_MAX_FLASHBANKS] =
{
#if (PMU_ECC_EDC_TST_PF0_SELECT == 1U)
   (PmuEccEdcTst_TestPatternType*)LOC_START_PF0_PATTERNS,
#else /* (PMU_ECC_EDC_TST_PF0_SELECT == 1U) */
  (PmuEccEdcTst_TestPatternType*)NULL_PTR,
#endif /* (PMU_ECC_EDC_TST_PF0_SELECT != 1U) */
#if (PMU_ECC_EDC_TST_MAX_FLASHBANKS > 1U)
#if (PMU_ECC_EDC_TST_PF1_SELECT == 1U)
   (PmuEccEdcTst_TestPatternType*)LOC_START_PF1_PATTERNS,
#else /* (PMU_ECC_EDC_TST_PF1_SELECT == 1U) */
  (PmuEccEdcTst_TestPatternType*)NULL_PTR,
#endif /* (PMU_ECC_EDC_TST_PF1_SELECT != 1U) */
#if (PMU_ECC_EDC_TST_MAX_FLASHBANKS > 2U)
#if (PMU_ECC_EDC_TST_PF2_SELECT == 1U)
   (PmuEccEdcTst_TestPatternType*)LOC_START_PF2_PATTERNS,
#else /* (PMU_ECC_EDC_TST_PF2_SELECT == 1U) */
  (PmuEccEdcTst_TestPatternType*)NULL_PTR,
#endif /* (PMU_ECC_EDC_TST_PF2_SELECT != 1U) */
#if (PMU_ECC_EDC_TST_MAX_FLASHBANKS > 3U)
#if (PMU_ECC_EDC_TST_PF3_SELECT == 1U)
   (PmuEccEdcTst_TestPatternType*)LOC_START_PF3_PATTERNS
#else /* (PMU_ECC_EDC_TST_PF3_SELECT == 1U) */
  (PmuEccEdcTst_TestPatternType*)NULL_PTR
#endif /* (PMU_ECC_EDC_TST_PF3_SELECT != 1U) */
#endif /* (PMU_ECC_EDC_TST_MAX_FLASHBANKS > 3U) */
#endif /* (PMU_ECC_EDC_TST_MAX_FLASHBANKS > 2U) */
#endif /* (PMU_ECC_EDC_TST_MAX_FLASHBANKS > 1U) */
};

#define IFX_PMUECCEDCTST_STOP_SEC_CONST_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"


#define IFX_PMUECCEDCTST_START_SEC_CONST_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"

/* Array of valid code word patterns of all 4 pattern sets. These are used
 * as reference to check that good data is not actively corrupted:
 */
const PmuEccEdcTst_FlashRefPageType
  PmuEccEdcTst_VcwRefPtrn[PMUT_TEST_PATTERN_COUNT] =
{
  { /* Valid code word page (SET 1): */
    {
      0x0145ABEFU, 0x0145ABEFU
    }
  },
  { /* Valid code word page (SET 2): */
    {
      0xFEBA5410U, 0xFEBA5410U
    }
  },
  { /* Valid code word page (SET 3): */
    {
      0x7698DC32U, 0x7698DC32U
    }
  },
  { /* Valid code word page (SET 4): */
    {
      0x896723CDU, 0x896723CDU
    }
  }
};

/* Array of single bit error patterns of all 4 pattern sets. These are used as
 * reference to check that single bit errors are corrected correctly:
 */
const PmuEccEdcTst_FlashRefPageType
  PmuEccEdcTst_SbeRefPtrn[PMUT_TEST_PATTERN_COUNT] =
{
  { /* Single bit error page (SET 1): */
    {
      0x0145ABEEU, 0x0145ABEFU
    }
  },
  { /* Single bit error page (SET 2): */
    {
      0xEEBA5410U, 0xFEBA5410U
    }
  },
  { /* Single bit error page (SET 3): */
    {
      0x6698DC32U, 0x7698DC32U
    }
  },
  { /* Single bit error page (SET 4): */
    {
      0x896723CCU, 0x896723CDU
    }
  }
};

/* Array of double bit error patterns of all 4 pattern sets. These are used as
 * reference to check that double bit errors are corrected correctly:
 */
const PmuEccEdcTst_FlashRefPageType
  PmuEccEdcTst_DbeRefPtrn[PMUT_TEST_PATTERN_COUNT] =
{
  { /* Double bit error page (SET 1): */
    {
      0x0145ABECU, 0x0145ABEFU
    }
  },
  { /* Double bit error page (SET 2): */
    {
      0xCEBA5410U, 0xFEBA5410U
    }
  },
  { /* Double bit error page (SET 3): */
    {
      0x4698DC32U, 0x7698DC32U
    }
  },
  { /* Double bit error page: */
    {
      0x896723C8U, 0x896723CDU
    }
  }
};

#define IFX_PMUECCEDCTST_STOP_SEC_CONST_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"
