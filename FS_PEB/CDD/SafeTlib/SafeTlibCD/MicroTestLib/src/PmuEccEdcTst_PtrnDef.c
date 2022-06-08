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
**   $FILENAME   : PmuEccEdcTst_PtrnDef.c $                                   **
**                                                                            **
**   $CC VERSION : \main\19 $                                                 **
**                                                                            **
**   $DATE       : 2016-05-16 $                                               **
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
**  REFERENCE(S) : Aurix-HE_SafeTlib_DS_PmuEccEdcTest.docm, v1.5              **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

#include "Mcal.h"
#include "PmuEccEdcTst_PtrnDef.h"
#include "PmuEccEdcTst_Cfg.h"

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

#if (PMU_ECC_EDC_TST_PF0_SELECT == 1U)
#define IFX_PMUECCEDCTST_START_SEC_CONST_PF0_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"

/* Test pattern in PFLASH BANK0; these are included into the binary image
 * without ECC errors, first. The ECC errors within these patterns need to be
 * created once, via a separate API:
 */
#ifdef __TASKING__
const PmuEccEdcTst_TestPatternType
      PmuEccTst_TestPatternB0 __attribute__((used)) =
#else
const PmuEccEdcTst_TestPatternType
      PmuEccTst_TestPatternB0 =
#endif
{
  /* Dummy pages: */
  {
    /* Dummy page 0: */
    {
      {
        0x00000000U, 0x00000000U, 0x00000000U, 0x00000000U,
        0x00000000U, 0x00000000U, 0x00000000U, 0x00000000U
      }
    },
    /* Dummy page 1: */
    {
      {
        0x00000000U, 0x00000000U, 0x00000000U, 0x00000000U,
        0x00000000U, 0x00000000U, 0x00000000U, 0x00000000U
      }
    }
  },
  { /* Pattern sets: */
    { /* SET 1: */
      { /* Pattern: */
        { /* Valid code word page: */
          {
            0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU,
            0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU
          }
        },
        { /* Single bit error page: */
          {
            0x0145ABEEU, 0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU,
            0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU
          }
        },
        { /* Double bit error page: */
          {
            0x0145ABECU, 0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU,
            0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU
          }
        },
        { /* Multi bit error page: */
          {
            0x0145ABE8U, 0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU,
            0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU
          }
        }
      }
    },
    { /* SET 2: */
      { /* Pattern: */
        { /* Valid code word page: */
          {
            0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U,
            0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U
          }
        },
        { /* Single bit error page: */
          { /* Data: */
            0xEEBA5410U, 0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U,
            0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U
          }
        },
        { /* Double bit error page: */
          {
            0xCEBA5410U, 0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U,
            0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U
          }
        },
        { /* Multi bit error page: */
          {
            0x8EBA5410U, 0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U,
            0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U
          }
        }
      }
    },
    { /* SET 3: */
      { /* Pattern: */
        { /* Valid code word page: */
          {
            0x7698DC32U, 0x7698DC32U, 0x7698DC32U, 0x7698DC32U,
            0x7698DC32U, 0x7698DC32U, 0x7698DC32U, 0x7698DC32U
          }
        },
        { /* Single bit error page: */
          {
            0x6698DC32U, 0x7698DC32U, 0x7698DC32U, 0x7698DC32U,
            0x7698DC32U, 0x7698DC32U, 0x7698DC32U, 0x7698DC32U
          }
        },
        { /* Double bit error page: */
          {
            0x4698DC32U, 0x7698DC32U, 0x7698DC32U, 0x7698DC32U,
            0x7698DC32U, 0x7698DC32U, 0x7698DC32U, 0x7698DC32U
          }
        },
        { /* Multi bit error page: */
          {
            0x0698DC32U, 0x7698DC32U, 0x7698DC32U, 0x7698DC32U,
            0x7698DC32U, 0x7698DC32U, 0x7698DC32U, 0x7698DC32U
          }
        }
      }
    },
    { /* SET 4: */
      { /* Pattern: */
        { /* Valid code word page: */
          {
            0x896723CDU, 0x896723CDU, 0x896723CDU, 0x896723CDU,
            0x896723CDU, 0x896723CDU, 0x896723CDU, 0x896723CDU
          }
        },
        { /* Single bit error page: */
          {
            0x896723CCU, 0x896723CDU, 0x896723CDU, 0x896723CDU,
            0x896723CDU, 0x896723CDU, 0x896723CDU, 0x896723CDU
          }
        },
        { /* Double bit error page: */
          {
            0x896723C8U, 0x896723CDU, 0x896723CDU, 0x896723CDU,
            0x896723CDU, 0x896723CDU, 0x896723CDU, 0x896723CDU
          }
        },
        { /* Multi bit error page: */
          {
            0x896723C0U, 0x896723CDU, 0x896723CDU, 0x896723CDU,
            0x896723CDU, 0x896723CDU, 0x896723CDU, 0x896723CDU
          }
        }
      }
    }
  },
#ifdef PFLASH_FIFO_BUFFERFULL_TEST_ENABLE	
  /* Double Bit Error pages: */
  {
    /* DBE page 0: */
    {
      {
        0x0145ABECU, 0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU,
        0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU
      }
    },
    /* DBE page 1: */
    {
      {
        0xCEBA5410U, 0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U,
        0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U
      }
    },
    /* DBE page 2: */
    {
      {
        0x4698DC32U, 0x7698DC32U, 0x7698DC32U, 0x7698DC32U,
        0x7698DC32U, 0x7698DC32U, 0x7698DC32U, 0x7698DC32U
      }
    },
    /* DBE page 3: */
    {
      {
        0x896723C8U, 0x896723CDU, 0x896723CDU, 0x896723CDU,
        0x896723CDU, 0x896723CDU, 0x896723CDU, 0x896723CDU
      }
    },
    /* DBE page 4: */
    {
      {
        0x0145ABECU, 0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU,
        0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU
      }
    },
    /* DBE page 5: */
    {
      {
        0xCEBA5410U, 0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U,
        0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U
      }
    },
    /* DBE page 6: */
    {
      {
        0x4698DC32U, 0x7698DC32U, 0x7698DC32U, 0x7698DC32U,
        0x7698DC32U, 0x7698DC32U, 0x7698DC32U, 0x7698DC32U
      }
    },
    /* DBE page 7: */
    {
      {
        0x896723C8U, 0x896723CDU, 0x896723CDU, 0x896723CDU,
        0x896723CDU, 0x896723CDU, 0x896723CDU, 0x896723CDU
      }
    },
        /* DBE page 8: */
    {
      {
        0x0145ABECU, 0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU,
        0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU
      }
    },
    /* DBE page 9: */
    {
      {
        0xCEBA5410U, 0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U,
        0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U
      }
    }
  }
#endif
};

#define IFX_PMUECCEDCTST_STOP_SEC_CONST_PF0_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"
#endif /* (PMU_ECC_EDC_TST_PF0_SELECT == 1U) */

#if (PMU_ECC_EDC_TST_PF1_SELECT == 1U)
#define IFX_PMUECCEDCTST_START_SEC_CONST_PF1_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"

/* Test pattern in PFLASH BANK1; these are included into the binary image
 * without ECC errors, first. The ECC errors within these patterns need to be
 * created once, via a separate API:
 */
#ifdef __TASKING__
const PmuEccEdcTst_TestPatternType
      PmuEccTst_TestPatternB1 __attribute__((used)) = 
#else
const PmuEccEdcTst_TestPatternType
      PmuEccTst_TestPatternB1 = 
#endif
{
  /* Dummy pages: */
  {
    /* Dummy page 0: */
    {
      {
        0x00000000U, 0x00000000U, 0x00000000U, 0x00000000U,
        0x00000000U, 0x00000000U, 0x00000000U, 0x00000000U
      }
    },
    /* Dummy page 1: */
    {
      {
        0x00000000U, 0x00000000U, 0x00000000U, 0x00000000U,
        0x00000000U, 0x00000000U, 0x00000000U, 0x00000000U
      }
    }
  },
  { /* Pattern sets: */
    { /* SET 1: */
      { /* Pattern: */
        { /* Valid code word page: */
          {
            0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU,
            0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU
          }
        },
        { /* Single bit error page: */
          {
            0x0145ABEEU, 0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU,
            0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU
          }
        },
        { /* Double bit error page: */
          {
            0x0145ABECU, 0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU,
            0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU
          }
        },
        { /* Multi bit error page: */
          {
            0x0145ABE8U, 0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU,
            0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU
          }
        }
      }
    },
    { /* SET 2: */
      { /* Pattern: */
        { /* Valid code word page: */
          {
            0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U,
            0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U
          }
        },
        { /* Single bit error page: */
          { /* Data: */
            0xEEBA5410U, 0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U,
            0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U
          }
        },
        { /* Double bit error page: */
          {
            0xCEBA5410U, 0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U,
            0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U
          }
        },
        { /* Multi bit error page: */
          {
            0x8EBA5410U, 0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U,
            0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U
          }
        }
      }
    },
    { /* SET 3: */
      { /* Pattern: */
        { /* Valid code word page: */
          {
            0x7698DC32U, 0x7698DC32U, 0x7698DC32U, 0x7698DC32U,
            0x7698DC32U, 0x7698DC32U, 0x7698DC32U, 0x7698DC32U
          }
        },
        { /* Single bit error page: */
          {
            0x6698DC32U, 0x7698DC32U, 0x7698DC32U, 0x7698DC32U,
            0x7698DC32U, 0x7698DC32U, 0x7698DC32U, 0x7698DC32U
          }
        },
        { /* Double bit error page: */
          {
            0x4698DC32U, 0x7698DC32U, 0x7698DC32U, 0x7698DC32U,
            0x7698DC32U, 0x7698DC32U, 0x7698DC32U, 0x7698DC32U
          }
        },
        { /* Multi bit error page: */
          {
            0x0698DC32U, 0x7698DC32U, 0x7698DC32U, 0x7698DC32U,
            0x7698DC32U, 0x7698DC32U, 0x7698DC32U, 0x7698DC32U
          }
        }
      }
    },
    { /* SET 4: */
      { /* Pattern: */
        { /* Valid code word page: */
          {
            0x896723CDU, 0x896723CDU, 0x896723CDU, 0x896723CDU,
            0x896723CDU, 0x896723CDU, 0x896723CDU, 0x896723CDU
          }
        },
        { /* Single bit error page: */
          {
            0x896723CCU, 0x896723CDU, 0x896723CDU, 0x896723CDU,
            0x896723CDU, 0x896723CDU, 0x896723CDU, 0x896723CDU
          }
        },
        { /* Double bit error page: */
          {
            0x896723C8U, 0x896723CDU, 0x896723CDU, 0x896723CDU,
            0x896723CDU, 0x896723CDU, 0x896723CDU, 0x896723CDU
          }
        },
        { /* Multi bit error page: */
          {
            0x896723C0U, 0x896723CDU, 0x896723CDU, 0x896723CDU,
            0x896723CDU, 0x896723CDU, 0x896723CDU, 0x896723CDU
          }
        }
      }
    }
  },
#ifdef PFLASH_FIFO_BUFFERFULL_TEST_ENABLE
  /* Double Bit Error pages: */
  {
    /* DBE page 0: */
    {
      {
        0x0145ABECU, 0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU,
        0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU
      }
    },
    /* DBE page 1: */
    {
      {
        0xCEBA5410U, 0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U,
        0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U
      }
    },
    /* DBE page 2: */
    {
      {
        0x4698DC32U, 0x7698DC32U, 0x7698DC32U, 0x7698DC32U,
        0x7698DC32U, 0x7698DC32U, 0x7698DC32U, 0x7698DC32U
      }
    },
    /* DBE page 3: */
    {
      {
        0x896723C8U, 0x896723CDU, 0x896723CDU, 0x896723CDU,
        0x896723CDU, 0x896723CDU, 0x896723CDU, 0x896723CDU
      }
    },
    /* DBE page 4: */
    {
      {
        0x0145ABECU, 0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU,
        0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU
      }
    },
    /* DBE page 5: */
    {
      {
        0xCEBA5410U, 0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U,
        0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U
      }
    },
    /* DBE page 6: */
    {
      {
        0x4698DC32U, 0x7698DC32U, 0x7698DC32U, 0x7698DC32U,
        0x7698DC32U, 0x7698DC32U, 0x7698DC32U, 0x7698DC32U
      }
    },
    /* DBE page 7: */
    {
      {
        0x896723C8U, 0x896723CDU, 0x896723CDU, 0x896723CDU,
        0x896723CDU, 0x896723CDU, 0x896723CDU, 0x896723CDU
      }
    },
        /* DBE page 8: */
    {
      {
        0x0145ABECU, 0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU,
        0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU
      }
    },
    /* DBE page 9: */
    {
      {
        0xCEBA5410U, 0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U,
        0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U
      }
    }
  }
#endif
};

#define IFX_PMUECCEDCTST_STOP_SEC_CONST_PF1_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"
#endif /* (PMU_ECC_EDC_TST_PF1_SELECT == 1U) */


#if (PMU_ECC_EDC_TST_PF2_SELECT == 1U)
#define IFX_PMUECCEDCTST_START_SEC_CONST_PF2_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"

/* Test pattern in PFLASH BANK2; these are included into the binary image
 * without ECC errors, first. The ECC errors within these patterns need to be
 * created once, via a separate API:
 */
#ifdef __TASKING__
const PmuEccEdcTst_TestPatternType
      PmuEccTst_TestPatternB2 __attribute__((used)) = 
#else
const PmuEccEdcTst_TestPatternType
      PmuEccTst_TestPatternB2 =
#endif
{
  /* Dummy pages: */
  {
    /* Dummy page 0: */
    {
      {
        0x00000000U, 0x00000000U, 0x00000000U, 0x00000000U,
        0x00000000U, 0x00000000U, 0x00000000U, 0x00000000U
      }
    },
    /* Dummy page 1: */
    {
      {
        0x00000000U, 0x00000000U, 0x00000000U, 0x00000000U,
        0x00000000U, 0x00000000U, 0x00000000U, 0x00000000U
      }
    }
  },
  { /* Pattern sets: */
    { /* SET 1: */
      { /* Pattern: */
        { /* Valid code word page: */
          {
            0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU,
            0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU
          }
        },
        { /* Single bit error page: */
          {
            0x0145ABEEU, 0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU,
            0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU
          }
        },
        { /* Double bit error page: */
          {
            0x0145ABECU, 0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU,
            0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU
          }
        },
        { /* Multi bit error page: */
          {
            0x0145ABE8U, 0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU,
            0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU
          }
        }
      }
    },
    { /* SET 2: */
      { /* Pattern: */
        { /* Valid code word page: */
          {
            0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U,
            0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U
          }
        },
        { /* Single bit error page: */
          { /* Data: */
            0xEEBA5410U, 0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U,
            0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U
          }
        },
        { /* Double bit error page: */
          {
            0xCEBA5410U, 0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U,
            0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U
          }
        },
        { /* Multi bit error page: */
          {
            0x8EBA5410U, 0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U,
            0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U
          }
        }
      }
    },
    { /* SET 3: */
      { /* Pattern: */
        { /* Valid code word page: */
          {
            0x7698DC32U, 0x7698DC32U, 0x7698DC32U, 0x7698DC32U,
            0x7698DC32U, 0x7698DC32U, 0x7698DC32U, 0x7698DC32U
          }
        },
        { /* Single bit error page: */
          {
            0x6698DC32U, 0x7698DC32U, 0x7698DC32U, 0x7698DC32U,
            0x7698DC32U, 0x7698DC32U, 0x7698DC32U, 0x7698DC32U
          }
        },
        { /* Double bit error page: */
          {
            0x4698DC32U, 0x7698DC32U, 0x7698DC32U, 0x7698DC32U,
            0x7698DC32U, 0x7698DC32U, 0x7698DC32U, 0x7698DC32U
          }
        },
        { /* Multi bit error page: */
          {
            0x0698DC32U, 0x7698DC32U, 0x7698DC32U, 0x7698DC32U,
            0x7698DC32U, 0x7698DC32U, 0x7698DC32U, 0x7698DC32U
          }
        }
      }
    },
    { /* SET 4: */
      { /* Pattern: */
        { /* Valid code word page: */
          {
            0x896723CDU, 0x896723CDU, 0x896723CDU, 0x896723CDU,
            0x896723CDU, 0x896723CDU, 0x896723CDU, 0x896723CDU
          }
        },
        { /* Single bit error page: */
          {
            0x896723CCU, 0x896723CDU, 0x896723CDU, 0x896723CDU,
            0x896723CDU, 0x896723CDU, 0x896723CDU, 0x896723CDU
          }
        },
        { /* Double bit error page: */
          {
            0x896723C8U, 0x896723CDU, 0x896723CDU, 0x896723CDU,
            0x896723CDU, 0x896723CDU, 0x896723CDU, 0x896723CDU
          }
        },
        { /* Multi bit error page: */
          {
            0x896723C0U, 0x896723CDU, 0x896723CDU, 0x896723CDU,
            0x896723CDU, 0x896723CDU, 0x896723CDU, 0x896723CDU
          }
        }
      }
    }
  },
#ifdef PFLASH_FIFO_BUFFERFULL_TEST_ENABLE
  /* Double Bit Error pages: */
  {
    /* DBE page 0: */
    {
      {
        0x0145ABECU, 0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU,
        0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU
      }
    },
    /* DBE page 1: */
    {
      {
        0xCEBA5410U, 0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U,
        0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U
      }
    },
    /* DBE page 2: */
    {
      {
        0x4698DC32U, 0x7698DC32U, 0x7698DC32U, 0x7698DC32U,
        0x7698DC32U, 0x7698DC32U, 0x7698DC32U, 0x7698DC32U
      }
    },
    /* DBE page 3: */
    {
      {
        0x896723C8U, 0x896723CDU, 0x896723CDU, 0x896723CDU,
        0x896723CDU, 0x896723CDU, 0x896723CDU, 0x896723CDU
      }
    },
    /* DBE page 4: */
    {
      {
        0x0145ABECU, 0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU,
        0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU
      }
    },
    /* DBE page 5: */
    {
      {
        0xCEBA5410U, 0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U,
        0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U
      }
    },
    /* DBE page 6: */
    {
      {
        0x4698DC32U, 0x7698DC32U, 0x7698DC32U, 0x7698DC32U,
        0x7698DC32U, 0x7698DC32U, 0x7698DC32U, 0x7698DC32U
      }
    },
    /* DBE page 7: */
    {
      {
        0x896723C8U, 0x896723CDU, 0x896723CDU, 0x896723CDU,
        0x896723CDU, 0x896723CDU, 0x896723CDU, 0x896723CDU
      }
    },
    /* DBE page 8: */
    {
      {
        0x0145ABECU, 0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU,
        0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU
      }
    },
    /* DBE page 9: */
    {
      {
        0xCEBA5410U, 0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U,
        0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U
      }
    }
  }
#endif
};

#define IFX_PMUECCEDCTST_STOP_SEC_CONST_PF2_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"
#endif /* (PMU_ECC_EDC_TST_PF2_SELECT == 1) */

#if (PMU_ECC_EDC_TST_PF3_SELECT == 1U)
#define IFX_PMUECCEDCTST_START_SEC_CONST_PF3_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"

/* Test pattern in PFLASH BANK3; these are included into the binary image
 * without ECC errors, first. The ECC errors within these patterns need to be
 * created once, via a separate API:
 */
#ifdef __TASKING__
const PmuEccEdcTst_TestPatternType
      PmuEccTst_TestPatternB3 __attribute__((used)) =
#else
const PmuEccEdcTst_TestPatternType
      PmuEccTst_TestPatternB3 =
#endif
{
  /* Dummy pages: */
  {
    /* Dummy page 0: */
    {
      {
        0x00000000U, 0x00000000U, 0x00000000U, 0x00000000U,
        0x00000000U, 0x00000000U, 0x00000000U, 0x00000000U
      }
    },
    /* Dummy page 1: */
    {
      {
        0x00000000U, 0x00000000U, 0x00000000U, 0x00000000U,
        0x00000000U, 0x00000000U, 0x00000000U, 0x00000000U
      }
    }
  },
  { /* Pattern sets: */
    { /* SET 1: */
      { /* Pattern: */
        { /* Valid code word page: */
          {
            0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU,
            0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU
          }
        },
        { /* Single bit error page: */
          {
            0x0145ABEEU, 0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU,
            0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU
          }
        },
        { /* Double bit error page: */
          {
            0x0145ABECU, 0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU,
            0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU
          }
        },
        { /* Multi bit error page: */
          {
            0x0145ABE8U, 0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU,
            0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU
          }
        }
      }
    },
    { /* SET 2: */
      { /* Pattern: */
        { /* Valid code word page: */
          {
            0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U,
            0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U
          }
        },
        { /* Single bit error page: */
          { /* Data: */
            0xEEBA5410U, 0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U,
            0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U
          }
        },
        { /* Double bit error page: */
          {
            0xCEBA5410U, 0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U,
            0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U
          }
        },
        { /* Multi bit error page: */
          {
            0x8EBA5410U, 0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U,
            0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U
          }
        }
      }
    },
    { /* SET 3: */
      { /* Pattern: */
        { /* Valid code word page: */
          {
            0x7698DC32U, 0x7698DC32U, 0x7698DC32U, 0x7698DC32U,
            0x7698DC32U, 0x7698DC32U, 0x7698DC32U, 0x7698DC32U
          }
        },
        { /* Single bit error page: */
          {
            0x6698DC32U, 0x7698DC32U, 0x7698DC32U, 0x7698DC32U,
            0x7698DC32U, 0x7698DC32U, 0x7698DC32U, 0x7698DC32U
          }
        },
        { /* Double bit error page: */
          {
            0x4698DC32U, 0x7698DC32U, 0x7698DC32U, 0x7698DC32U,
            0x7698DC32U, 0x7698DC32U, 0x7698DC32U, 0x7698DC32U
          }
        },
        { /* Multi bit error page: */
          {
            0x0698DC32U, 0x7698DC32U, 0x7698DC32U, 0x7698DC32U,
            0x7698DC32U, 0x7698DC32U, 0x7698DC32U, 0x7698DC32U
          }
        }
      }
    },
    { /* SET 4: */
      { /* Pattern: */
        { /* Valid code word page: */
          {
            0x896723CDU, 0x896723CDU, 0x896723CDU, 0x896723CDU,
            0x896723CDU, 0x896723CDU, 0x896723CDU, 0x896723CDU
          }
        },
        { /* Single bit error page: */
          {
            0x896723CCU, 0x896723CDU, 0x896723CDU, 0x896723CDU,
            0x896723CDU, 0x896723CDU, 0x896723CDU, 0x896723CDU
          }
        },
        { /* Double bit error page: */
          {
            0x896723C8U, 0x896723CDU, 0x896723CDU, 0x896723CDU,
            0x896723CDU, 0x896723CDU, 0x896723CDU, 0x896723CDU
          }
        },
        { /* Multi bit error page: */
          {
            0x896723C0U, 0x896723CDU, 0x896723CDU, 0x896723CDU,
            0x896723CDU, 0x896723CDU, 0x896723CDU, 0x896723CDU
          }
        }
      }
    }
  },
#ifdef PFLASH_FIFO_BUFFERFULL_TEST_ENABLE
  /* Double Bit Error pages: */
  {
    /* DBE page 0: */
    {
      {
        0x0145ABECU, 0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU,
        0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU
      }
    },
    /* DBE page 1: */
    {
      {
        0xCEBA5410U, 0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U,
        0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U
      }
    },
    /* DBE page 2: */
    {
      {
        0x4698DC32U, 0x7698DC32U, 0x7698DC32U, 0x7698DC32U,
        0x7698DC32U, 0x7698DC32U, 0x7698DC32U, 0x7698DC32U
      }
    },
    /* DBE page 3: */
    {
      {
        0x896723C8U, 0x896723CDU, 0x896723CDU, 0x896723CDU,
        0x896723CDU, 0x896723CDU, 0x896723CDU, 0x896723CDU
      }
    },
    /* DBE page 4: */
    {
      {
        0x0145ABECU, 0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU,
        0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU
      }
    },
    /* DBE page 5: */
    {
      {
        0xCEBA5410U, 0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U,
        0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U
      }
    },
    /* DBE page 6: */
    {
      {
        0x4698DC32U, 0x7698DC32U, 0x7698DC32U, 0x7698DC32U,
        0x7698DC32U, 0x7698DC32U, 0x7698DC32U, 0x7698DC32U
      }
    },
    /* DBE page 7: */
    {
      {
        0x896723C8U, 0x896723CDU, 0x896723CDU, 0x896723CDU,
        0x896723CDU, 0x896723CDU, 0x896723CDU, 0x896723CDU
      }
    },
    /* DBE page 8: */
    {
      {
        0x0145ABECU, 0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU,
        0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU, 0x0145ABEFU
      }
    },
    /* DBE page 9: */
    {
      {
        0xCEBA5410U, 0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U,
        0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U, 0xFEBA5410U
      }
    }
  }  
#endif  
};

#define IFX_PMUECCEDCTST_STOP_SEC_CONST_PF3_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"
#endif /* (PMU_ECC_EDC_TST_PF3_SELECT == 1) */

