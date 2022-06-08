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
**   $FILENAME   : Sl_FlsErrPtrn.c $                                          **
**                                                                            **
**   $CC VERSION : \main\57 $                                                 **
**                                                                            **
**   $DATE       : 2018-02-22 $                                               **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon AURIX                                                **
**                                                                            **
**  COMPILER  : Tasking                                                       **
**                                                                            **
**  AUTHOR    : DL-BLR-ATV-STC                                                **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  TRACEABILITY:                                                             **
**                                                                            **
**  DESCRIPTION  : This file contains                                         **
**                 - Support routines for programming erroneous FLASH pages   **
**                   to be used for the PMU EDC ECC test.                     **
**                                                                            **
**                                                                            **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [Yes/No]: No                                       **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

#include "Sl_FlsErrPtrn.h"
#include "Mcal_Compiler.h"
#include "Mcal.h"
#include "IfxCpu_reg.h"
#include "IfxCpu_bf.h"
#include "IfxFlash_reg.h"
#include "ChipId.h"

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
/* Number of erroneous patterns per pattern set (single-, double-, multi-bit
 * errors => 3 ):
 */
#define SLFLS_ERR_PTRN_PER_SET          ( 3U )

/* Index of first error pattern page (after the valid code word page): */
#define SLFLS_ERR_PTRN_OFFSET           ( 1U )

/* Index of multi bit error pattern within the pattern set: */
#define SLFLS_MBE_PTRN_IDX              ( 3U )

/* Index of valid code word pattern within the pattern set: */
#define SLFLS_VCW_PTRN_IDX              ( 0U )

/* Data Flash Base Address for Flash commands */
#define SLFLS_PMU0_DF0_BASE             ( 0xAF000000U )

/* FSI Commands */
#define SLFLS_FSI_CMD_00                ( 0x00000000U )
#define SLFLS_FSI_CMD_50                ( 0x00000050U )
#define SLFLS_FSI_CMD_A0                ( 0x000000A0U )
#define SLFLS_FSI_CMD_AA                ( 0x000000AAU )
#define SLFLS_FSI_CMD_F0                ( 0x000000F0U )
#define SLFLS_FSI_CMD_FA                ( 0x000000FAU )

/* Flash status masks: */
/*  -Pagemode or busy flags to be checked: */
#define SLFLS_FLASH_FSR_BUSY_MASK       ( 0x00000278U )
/*  -SQER and PROER errors checked: */
#define SLFLS_FLASH_FSR_ERROR2_MASK     ( 0x00003000U )
/*  -SQER, PROER and OPER errors checked: */
#define SLFLS_FLASH_FSR_ERROR3_MASK     ( 0x00003800U )
/*Bit mask to clear the FSR*/
#define SLFLS_FLASH_FSR_ERROR_MASK4     ( 0x0E7FF980U )

/* Bit mask to extract all 22 ECC bits from an uint32 */
#define SLFLS_ECC_MASK                  ( (uint32)0x003FFFFFU )

/* Number bytes per PFLASH page */
#define SLFLS_BYTES_PER_WORDLINE        ( 32U )



/*For clearing the Pflash uncorrectable error flag*/
#define FLASH0_FSR_PFMBER                   (16U)
#ifdef PFLASH_FIFO_BUFFERFULL_TEST_ENABLE
/*Bit mask for creating double-bit errors*/
#define DBE_ERROR_MASK                     (0x30000000U)
#endif
/*******************************************************************************
**                   Function like macro definitions                          **
*******************************************************************************/


/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/* Container to provide access addresses to Flash machine */
typedef struct SlFls_FlashProgType
{
  volatile uint32*    FlashCmd;               /* Flash command interface  */
  volatile uint32*    LoadPage0;              /* Load page first word     */
  volatile uint32*    LoadPage1;              /* Load page second word    */
  volatile uint32*    WritePage0;             /* Write page sequence...   */
  volatile uint32*    WritePage1;
  volatile uint32*    WritePage2;
  volatile uint32*    WritePage3;
} SlFls_FlashProgType;

/* Container for parameter set used to program a flash page */
typedef struct SlFls_ProgDataType
{
  /* Page to be programmed: */
  void*                       PageAddr;

  /* Data to be programmed: */
  PmuEccEdcTst_FlashPageType  PageData;

  /* ECC data of flash page: */
  uint32                      EccData;

  /* Pointer to Flash status register: */
  volatile Ifx_FLASH_FSR*     FlashFsrPtr;

  /* Pointer to Flash ECCRPx SFR, depends on used bank: */
  volatile Ifx_FLASH_ECCRP*   FlashEccrpPtr;

} SlFls_ProgDataType;


/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
#define IFX_PMU_APPL_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
LOCAL_INLINE Sl_FlsPrgRsltType Sl_lGetCheckFailErr
(
  const uint8 FlashBank
);

LOCAL_INLINE Sl_FlsPrgRsltType Sl_lGetProgFailErr
(
  const uint8 FlashBank
);

static Std_ReturnType Sl_lCheckErrorPattern
(
  const uint8 FlashBank,
  boolean* const PatternOk
);
#define IFX_PMU_APPL_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
#define IFX_PMU_APPL_START_SEC_RAM_CODE_ASIL_B
#include "Ifx_MemMap.h"

/* Functions that are copied and executed in SPRAM */
static void Sl_lReadFlashPage
(
  SlFls_ProgDataType* const ProgData
);

static boolean Sl_lChkErrPtrnHelper
(
  const PmuEccEdcTst_TestPatternType* const TestPattern
);

static boolean Sl_lComparePageHelper
(
  const PmuEccEdcTst_FlashPageType* const FlashPage,
  const PmuEccEdcTst_FlashRefPageType* const RefPattern
);

static Std_ReturnType Sl_lProgramPageFcn
(
  const SlFls_ProgDataType* const ProgData
);


#define IFX_PMU_APPL_STOP_SEC_RAM_CODE_ASIL_B
#include "Ifx_MemMap.h"
#define IFX_PMU_APPL_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
static Std_ReturnType Sl_lProgramPage
(
  const SlFls_ProgDataType* const ProgData
);

static Std_ReturnType Sl_lEnterPageMode
(
  void
);

static Std_ReturnType Sl_lRamCalculateandVerifyCrc32
(
  void
);
#define IFX_PMU_APPL_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/


/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/


/******************************************************************************
**                        Local object definitions                            *
******************************************************************************/
#define IFX_PMU_APPL_START_SEC_VAR_32BIT_ASIL_B
#include "Ifx_MemMap.h"
/* Variable to hold the CRC32 value of PFLASH_MON_ECCEDC_RAMCODE section
   functions in PFlash*/
static uint32 SlFls_PFlashFnCrc32;

#define IFX_PMU_APPL_STOP_SEC_VAR_32BIT_ASIL_B
#include "Ifx_MemMap.h"

/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/
#define IFX_PMU_APPL_START_SEC_CONST_32BIT_ASIL_B
#include "Ifx_MemMap.h"

/* Table containing the bits to flip from '0' to '1' to generate the
 * erroneous single-, double- and multi-bit error flash pages for all four
 * pattern sets:
 */
static const uint32
             SlFls_BitFlipTbl[PMUT_TEST_PATTERN_COUNT][SLFLS_ERR_PTRN_PER_SET] =
{
  { /* Pattern set 1: */
    0x00000001U,    /* Single bit error */
    0x00000003U,    /* Double bit error */
    0x00000007U     /* Triple (multi) bit error */
  },
  { /* Pattern set 2: */
    0x10000000U,    /* Single bit error */
    0x30000000U,    /* Double bit error */
    0x70000000U     /* Triple (multi) bit error */
  },
  { /* Pattern set 3: */
    0x10000000U,    /* Single bit error */
    0x30000000U,    /* Double bit error */
    0x70000000U     /* Triple (multi) bit error */
  },
  { /* Pattern set 4: */
    0x00000001U,    /* Single bit error */
    0x00000005U,    /* Double bit error */
    0x0000000DU     /* Triple (multi) bit error */
  }
};
      
#define IFX_PMU_APPL_STOP_SEC_CONST_32BIT_ASIL_B
#include "Ifx_MemMap.h"


/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

#define IFX_PMU_APPL_START_SEC_VAR_NONZERO_INIT_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"

/* Flash programming pointers */
static SlFls_FlashProgType SlFls_FlashProgAccess =
{
    (volatile uint32*)((uint32)SLFLS_PMU0_DF0_BASE + 0x00005554U),
    (volatile uint32*)((uint32)SLFLS_PMU0_DF0_BASE + 0x000055F0u),
    (volatile uint32*)((uint32)SLFLS_PMU0_DF0_BASE + 0x000055F4u),
    (volatile uint32*)((uint32)SLFLS_PMU0_DF0_BASE + 0x0000AA50U),
    (volatile uint32*)((uint32)SLFLS_PMU0_DF0_BASE + 0x0000AA58U),
    (volatile uint32*)((uint32)SLFLS_PMU0_DF0_BASE + 0x0000AAA8U),
    (volatile uint32*)((uint32)SLFLS_PMU0_DF0_BASE + 0x0000AAA8U)
};

#define IFX_PMU_APPL_STOP_SEC_VAR_NONZERO_INIT_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"


/*******************************************************************************
**                      Debug Purpose Definitions                             **
*******************************************************************************/


/*******************************************************************************
**                      Public Function Definitions                           **
*******************************************************************************/
#define IFX_PMU_APPL_START_SEC_RAM_CODE_ASIL_B
#include "Ifx_MemMap.h"
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : void Sl_lReadFlashPage                                  **
**                    (                                                       **
**                      SlFls_ProgDataType* const ProgData                    **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters (in)  : ProgData - Pointer to a structure holding the page      **
**                               address to read and that will receive the    **
**                               read page data and ECC data                  **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : Reads a single page of Program FLASH and the ECC data   **
**                    of that page.                                           **
** Note(s)          : This routines must first be copied to SPRAM before it   **
**                    is executed. Otherwise a wrong ECC value may be read    **
**                    due to concurrent instruction fetches from PFLASH.      **
**                    ENDINIT protection must be reset before this routine    **
**                    is executed.                                            **
**                                                                            **
*******************************************************************************/
#ifdef __TASKING__
PRAGMA_ALL(OPTIMIZE_0)
#endif
static void Sl_lReadFlashPage
(
  SlFls_ProgDataType* const ProgData
)
{
  uint8   FlashWord;

  /* Read flash page to RAM: */
  for (FlashWord = 0U; FlashWord < PMUT_WORDS_PER_PAGE; FlashWord++)
  {
    ProgData->PageData.Data[FlashWord] =
        ((uint32*)ProgData->PageAddr)[FlashWord];
  } /* for (FlashWord = 0U; FlashWord <= PMUT_WORDS_PER_PAGE; FlashWord++) */

  /* Read ECC data: */
  ProgData->EccData = (uint32) ProgData->FlashEccrpPtr->B.RCODE;
} /* Sl_lReadFlashPage */
#ifdef __TASKING__
PRAGMA_ALL(OPTIMIZE_RESTORE)
#endif


/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : Std_ReturnType Sl_lProgramPageFcn                       **
**                    (                                                       **
**                      const SlFls_ProgDataType* const ProgData              **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters (in)  : ProgData - Pointer to a structure holding all           **
**                               required parameters to program one page      **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : E_OK - Programming flash page succeeded                 **
**                    E_NOT_OK - Programming flash page failed                **
**                                                                            **
** Description      : Programs a single page of Program FLASH.                **
** Note(s)          : This routine must first be copied to SRAM before it     **
**                    could be be used!                                       **
**                                                                            **
*******************************************************************************/
#ifdef __TASKING__
PRAGMA_ALL(OPTIMIZE_0)
#endif
static Std_ReturnType Sl_lProgramPageFcn
(
  const SlFls_ProgDataType* const ProgData
)
{
  Std_ReturnType  Result = E_NOT_OK;
  volatile uint32 Temp;
  /*Clear the FSR*/
  FLASH0_FSR.U = (uint32)SLFLS_FLASH_FSR_ERROR_MASK4;
  /* Execute Write Page command */
  *(SlFls_FlashProgAccess.WritePage0) = (uint32)ProgData->PageAddr;
  *(SlFls_FlashProgAccess.WritePage1) = SLFLS_FSI_CMD_00;
  *(SlFls_FlashProgAccess.WritePage2) = SLFLS_FSI_CMD_A0;
  *(SlFls_FlashProgAccess.WritePage3) = SLFLS_FSI_CMD_AA;

  /* According to application hint */
  DSYNC();

  /* Wait for end of Write Page operation, abort with any flash status error */
  do
  {
    Temp = ProgData->FlashFsrPtr->U;
    if ((0U != (Temp & SLFLS_FLASH_FSR_ERROR3_MASK )))
    {
      break;              /* Abort wait loop in case of failure */
    } /* if ((0U != (Temp & SLFLS_FLASH_FSR_ERROR3_MASK ))) */
  } while ((Temp & SLFLS_FLASH_FSR_BUSY_MASK) != 0U);

  /* Check status of Write Page operation */
  if (0U == (Temp & SLFLS_FLASH_FSR_ERROR3_MASK ))
  {
      Result = E_OK;
  } /* if (0U == (Temp & SLFLS_FLASH_FSR_ERROR3_MASK )) */

  /* Flash reset to read */
  *(SlFls_FlashProgAccess.FlashCmd) = SLFLS_FSI_CMD_F0;

  return Result;
} /* Sl_lProgramPageFcn */
#ifdef __TASKING__
PRAGMA_ALL(OPTIMIZE_RESTORE)
#endif

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : boolean Sl_lChkErrPtrnHelper                            **
**                    (                                                       **
**                      const PmuEccEdcTst_TestPatternType* const             **
**                      TestPattern                                           **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters (in)  : TestPattern - Pointer to the PMU ECC/EDC test pattern   **
**                                  in PFLASH; pointer to pattern of first    **
**                                  PFLASH bank selected for testing          **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : TRUE - Test patterns have already been programmed       **
**                    FALSE - Test patterns have not yet been programmed;     **
**                            Sl_ErrorPatternProg API should be used to       **
**                            program the patterns to PFLASH                  **
**                                                                            **
** Description      : Checks whether the test patterns for the PMU ECC/EDC    **
**                    test have already been programmed to PFLASH, i.e.       **
**                    whether bit errors have already been created.           **
**                                                                            **
** Note(s)          : This function needs to be copied to SPRAM before it is  **
**                    used because it disables trap generation for            **
**                    uncorrectable PFLASH ECC errors.                        **
**                                                                            **
*******************************************************************************/
#ifdef __TASKING__
PRAGMA_ALL(OPTIMIZE_0)
#endif
static boolean Sl_lChkErrPtrnHelper
(
  const PmuEccEdcTst_TestPatternType* const TestPattern
)
{
  uint8           i;
  volatile uint32 Dummy = 0U;
  uint32          FlashMarpBak;
  boolean         Result = (boolean)FALSE;

  UNUSED_PARAMETER(Dummy)
  
  /* Clear uncorrectable PFLASH ECC error flag: */
  FLASH0_FSR.U = (uint32)(((uint32)1U)<<(FLASH0_FSR_PFMBER));
  #ifdef __GNUC__ 
  ISYNC();
  #endif

  /* Disable trap generation on PFLASH uncorrectable ECC errors: */
  FlashMarpBak = FLASH0_MARP.U;
  FLASH0_MARP.B.TRAPDIS = 1U;
  #ifdef __GNUC__   
  ISYNC();
  #endif

  /* Read multi-bit error page of all pattern sets of given flash bank: */
  for (i = 0U; i < PMUT_TEST_PATTERN_COUNT; i++)
  {
    Dummy = TestPattern->Set[i].Pattern[SLFLS_MBE_PTRN_IDX].Data[0U];
  } /* for (i = 0U; i < PMUT_TEST_PATTERN_COUNT; i++) */

  /* Uncorrectable PFLASH ECC error flag should now be set, if patterns have
   * already been programmed:
   */
  if (1U == FLASH0_FSR.B.PFMBER)
  {
    /* Clear error flag: */
    FLASH0_FSR.U = (uint32)(((uint32)1U)<<(FLASH0_FSR_PFMBER));
    #ifdef __GNUC__     
    ISYNC();
    #endif
    Result = (boolean)TRUE;
  } /* if (1U == FLASH0_FSR.B.PFMBER) */

  /* Restore trap generation on uncorrectable PFLASH ECC errors: */
  FLASH0_MARP.U = FlashMarpBak;
  #ifdef __GNUC__   
  ISYNC();
  #endif

  return Result;
} /* Sl_lChkErrPtrnHelper */
#ifdef __TASKING__
PRAGMA_ALL(OPTIMIZE_RESTORE)
#endif

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : boolean Sl_lComparePageHelper                           **
**                    (                                                       **
**                      const PmuEccEdcTst_FlashPageType* const FlashPage,    **
**                      const PmuEccEdcTst_FlashRefPageType* const RefPattern **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters (in)  : FlashPage - Pointer to a PFLASH page to compare         **
**                    RefPattern - Pointer to reference pattern in PFLASH to  **
**                                 compare PFLASH page to                     **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : TRUE - Test pattern and reference pattern are equal     **
**                    FALSE - Test pattern and reference pattern are          **
**                            different                                       **
**                                                                            **
** Description      : This function compares a PFLASH page to a given         **
**                    reference pattern                                       **
**                                                                            **
** Note(s)          : This function needs to be copied to SPRAM before it is  **
**                    used because it disables trap generation for            **
**                    uncorrectable PFLASH ECC errors.                        **
**                                                                            **
*******************************************************************************/
#ifdef __TASKING__
PRAGMA_ALL(OPTIMIZE_0)
#endif
static boolean Sl_lComparePageHelper
(
  const PmuEccEdcTst_FlashPageType* const FlashPage,
  const PmuEccEdcTst_FlashRefPageType* const RefPattern
)
{
  uint32          i;
  uint32          RefIdx = 0U;
  boolean         Result = TRUE;
  uint32          FlashMarpSave = FLASH0_MARP.U;

  /* ECC trap disable */
  FLASH0_MARP.B.TRAPDIS = 1U;

  /* Read data set and compare */
  for (i = 0U; i < PMUT_WORDS_PER_PAGE; i++)
  {
    if (FlashPage->Data[i] != RefPattern->Data[RefIdx])
    {
      Result = FALSE;
      break;
    } /* if (FlashPage->Data[i] != RefPattern->Data[RefIdx]) */
    RefIdx = 1U;
  } /* for (i = 0u; i < PMUT_WORDS_PER_PAGE; i++) */

  /* Restore ECC trap handling */
  FLASH0_MARP.U = FlashMarpSave;

  return Result;
} /* Sl_lComparePageHelper */
#ifdef __TASKING__
PRAGMA_ALL(OPTIMIZE_RESTORE)
#endif

#define IFX_PMU_APPL_STOP_SEC_RAM_CODE_ASIL_B
#include "Ifx_MemMap.h"

#define IFX_PMU_APPL_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : Std_ReturnType Sl_ChkProgErrorPattern                   **
**                    (                                                       **
**                      void                                                  **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters (in)  : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : SL_PROG_DONE - Programming bit errors to the test       **
**                                   patterns succeeded or bit errors were    **
**                                   already programmed earlier               **
**                    SL_PROG_FAIL_PF0 - Programming flash bank 0 failed      **
**                    SL_PROG_FAIL_PF1 - Programming flash bank 1 failed      **
**                    SL_PROG_FAIL_PF2 - Programming flash bank 2 failed      **
**                    SL_PROG_FAIL_PF3 - Programming flash bank 3 failed      **
**                    SL_CHECK_FAIL_PF0 - Checking status of flash bank 0     **
**                                        failed, check if base patterns are  **
**                                        loaded to PFLASH                    **
**                    SL_CHECK_FAIL_PF1 - Checking status of flash bank 1     **
**                                        failed, check if base patterns are  **
**                                        loaded to PFLASH                    **
**                    SL_CHECK_FAIL_PF2 - Checking status of flash bank 2     **
**                                        failed, check if base patterns are  **
**                                        loaded to PFLASH                    **
**                    SL_CHECK_FAIL_PF3 - Checking status of flash bank 3     **
**                                        failed, check if base patterns are  **
**                                        loaded to PFLASH                    **
**                    SL_CORRUPTION_ERR - Internal data was corrupted         **
**                                                                            **
** Description      : Checks whether bit errors have to be programmed to the  **
**                    test patterns of the PMU ECC/EDC test and creates these **
**                    bit errors by re-programming the PFLASH pages           **
**                    containing the error patterns, again.                   **
**                                                                            **
** Note(s)          : It must be ensured that all operating conditions (like  **
**                    temperature, supply voltage, ...) are within the        **
**                    specification for FLASH programming. The device must    **
**                    not be reseted while the programming operation is in   **
**                    progress.                                               **
**                    This API reads PFLASH pages with uncorrectable ECC      **
**                    errors. It is expected that this API is executed before **
**                    the SMU is put into RUN state. If this API is used when **
**                    the SMU is already in RUN state, the caller shall be    **
**                    prepared to receive SMU alarms due to PFLASH ECC        **
**                    errors.                                                 **
**                                                                            **
*******************************************************************************/
Sl_FlsPrgRsltType Sl_ChkProgErrorPattern
(
  void
)
{
  volatile uint8            FlashBank;
  uint8                     PatternSet;
  uint8                     ErrPattern;
#ifdef PFLASH_FIFO_BUFFERFULL_TEST_ENABLE
  uint8                     DBEPatternSet;
#endif
#ifdef VALID_FUNCTION_CALLBACK
  boolean                   SecurityDisabled = FALSE;
#endif
  boolean                   PatternProgrammed = FALSE;
  SlFls_ProgDataType        ProgData;
  Sl_FlsPrgRsltType         Result = SL_PROG_DONE;
  Std_ReturnType            ResultTmp;
  volatile Ifx_FLASH_ECCRP* FlashEccrpList[PMU_ECC_EDC_TST_MAX_FLASHBANKS];

  uint32 baddress,eaddress;

  baddress = (uint32)LOC_START_PflashMon_EccEdc_PFLASHCODE;
  eaddress = (uint32)LOC_END_PflashMon_EccEdc_PFLASHCODE;
  /* Initialize table of FLASH0_ECCRPx register pointers: */
  FlashEccrpList[0U] = &FLASH0_ECCRP0;
#if (PMU_ECC_EDC_TST_MAX_FLASHBANKS > 1U)
  FlashEccrpList[1U] = &FLASH0_ECCRP1;
#if (PMU_ECC_EDC_TST_MAX_FLASHBANKS > 2U)
  FlashEccrpList[2U] = &FLASH0_ECCRP2;
#if (PMU_ECC_EDC_TST_MAX_FLASHBANKS > 3U)
  FlashEccrpList[3U] = &FLASH0_ECCRP3;
#endif
#endif
#endif

  /* Initialize flash programming data struct: */
  ProgData.FlashFsrPtr = &FLASH0_FSR;

/* Calculate Crc of functions in PFlash that have been copied to RAM*/
  SlFls_PFlashFnCrc32 = PmuEccEdcTst_CalculateCrc32(
    LOC_START_PflashMon_EccEdc_PFLASHCODE,
    (eaddress-baddress));
    
  /* Loop through all flash banks: */
  for (FlashBank = 0U; (FlashBank < PMU_ECC_EDC_TST_MAX_FLASHBANKS) &&
                       (SL_PROG_DONE == Result); FlashBank++)
  {
    if (NULL_PTR != PmuEccEdcTst_TestPattern[FlashBank])
    {
      /* Check if bit errors were already programmed: */
      ResultTmp = Sl_lCheckErrorPattern(FlashBank,
                                        &PatternProgrammed);
      if (E_OK != ResultTmp)
      {
        Result = Sl_lGetCheckFailErr(FlashBank);
      } /* if (E_OK != ResultTmp) */
      else if ((boolean)FALSE == PatternProgrammed)
      {
#ifdef VALID_FUNCTION_CALLBACK
        /*Call the application callback function, for security specific 
        operations to be performed before programming the patterns*/
        if(FALSE == SecurityDisabled)
        {
          SECURITYDISABLE();
          
          /*"SecurityDisabled" ensures that disabling security is done only once.*/
          SecurityDisabled = TRUE; 
        }
#endif
        /* Setup FLASH0_ECCRPx pointer according to current flash bank: */
        ProgData.FlashEccrpPtr = FlashEccrpList[FlashBank];

        /* Loop through all pattern sets: */
        for (PatternSet = 0U; (PatternSet < PMUT_TEST_PATTERN_COUNT) &&
                              (SL_PROG_DONE == Result); PatternSet++)
        {
          /* Loop through all different error scenarios (single-, double-,
           * multi-bit):
           */
          for (ErrPattern = 0U; (ErrPattern < SLFLS_ERR_PTRN_PER_SET) &&
                                (SL_PROG_DONE == Result); ErrPattern++)
          {
            ProgData.PageAddr = (void*)
               ((uint32)&(PmuEccEdcTst_TestPattern[FlashBank]->Set[PatternSet].
                  Pattern[SLFLS_ERR_PTRN_OFFSET + ErrPattern].Data[0])
				       |(uint32)0x20000000U);

            /* Calculate and compare Crc of functions in RAM that 
            were copied from PFlash at startup*/
            ResultTmp = Sl_lRamCalculateandVerifyCrc32();

            if (E_OK == ResultTmp)
            {
              /* Read flash page (including ECC data) to RAM: */
              Sl_lReadFlashPage(&ProgData);

              /* Flip bits of flash page in RAM to create bit error: */
              ProgData.PageData.Data[0] |= SlFls_BitFlipTbl[PatternSet]
                                                           [ErrPattern];

              /* Reprogram flash page: */
              ResultTmp = Sl_lProgramPage(&ProgData);
            } /* if (E_OK == ResultTmp) */

            if (E_OK != ResultTmp)
            {
              Result = Sl_lGetProgFailErr(FlashBank);
            } /* if (E_OK != ResultTmp) */
          } /* for (ErrPattern = 0U; (ErrPattern < SLFLS_ERR_PTRN_PER_SET) &&
                                     (SL_PROG_DONE == Result); ErrPattern++) */

        } /* for (PatternSet = 0U; (PatternSet < PMUT_TEST_PATTERN_COUNT) &&
                                   (SL_PROG_DONE == Result); PatternSet++) */
#ifdef PFLASH_FIFO_BUFFERFULL_TEST_ENABLE                            
        for (DBEPatternSet = 0U; (DBEPatternSet < (uint8)PFLASH_MON_CBAB_FIFO_DEPTH) &&
                              (SL_PROG_DONE == Result); DBEPatternSet++)
        {
            ProgData.PageAddr = (void*)
               ((uint32)&(PmuEccEdcTst_TestPattern[FlashBank]->DBEPage[DBEPatternSet].Data[0])
			       |(uint32)0x20000000U);
               

            /* Calculate and compare Crc of functions in RAM that 
            were copied from PFlash at startup*/
            ResultTmp = Sl_lRamCalculateandVerifyCrc32();

            if (E_OK == ResultTmp)
            {
              /* Read flash page (including ECC data) to RAM: */
              Sl_lReadFlashPage(&ProgData);

              /* Flip bits of flash page in RAM to create bit error: */
              ProgData.PageData.Data[0] |= (uint32)DBE_ERROR_MASK;

              /* Reprogram flash page: */
              ResultTmp = Sl_lProgramPage(&ProgData);
            } /* if (E_OK == ResultTmp) */

            if (E_OK != ResultTmp)
            {
              Result = Sl_lGetProgFailErr(FlashBank);
            } /* if (E_OK != ResultTmp) */
        }
#endif
      } /* if ((E_OK == ResultTmp) && ((boolean)FALSE == PatternProgrammed)) */
      else
      {
        /* Pattern already programmed, nothing to do */
      } /* if ((E_OK == ResultTmp) && ((boolean)FALSE != PatternProgrammed)) */
    } /* if (NULL_PTR != TestPattern[FlashBank]) */

  } /* for (FlashBank = 0U; (FlashBank < PMU_ECC_EDC_TST_MAX_FLASHBANKS) &&
                            (SL_PROG_DONE == Result); FlashBank++) */
#ifdef VALID_FUNCTION_CALLBACK
  /*Call the application callback function, for any security specific 
  operations to be performed after programming the patterns*/
  if(TRUE == SecurityDisabled)
  {
    SECURITYENABLE();
  }
#endif

  /* Re-enable automatic FLASH ECC generation: */
  Mcal_ResetENDINIT();
  FLASH0_ECCW.B.PECENCDIS = 0U;
  Mcal_SetENDINIT();

  return Result;
} /* Sl_ChkProgErrorPattern */


/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : Sl_FlsPrgRsltType Sl_lGetCheckFailErr                   **
**                    (                                                       **
**                      const uint8 FlashBank                                 **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters (in)  : FlashBank - Flash bank for which the status check       **
**                                failed                                      **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : SL_CHECK_FAIL_PFx - Check failed for flash bank x       **
**                    SL_CORRUPTION_ERR - Invalid FlashBank parameter         **
**                                                                            **
** Description      : This functions returns the correct error code           **
**                    - depending on flash bank under test - in case the      **
**                    programming status check failed.                        **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE Sl_FlsPrgRsltType Sl_lGetCheckFailErr
(
  const uint8 FlashBank
)
{
  Sl_FlsPrgRsltType Result;

  switch (FlashBank)
  {
  case 0:
    Result = SL_CHECK_FAIL_PF0;
    break;

  case 1:
    Result = SL_CHECK_FAIL_PF1;
    break;

  case 2:
    Result = SL_CHECK_FAIL_PF2;
    break;

  case 3:
    Result = SL_CHECK_FAIL_PF3;
    break;

  default:
    Result = SL_CORRUPTION_ERR;
    break;
  } /* switch (FlashBank) */

  return Result;
} /* Sl_lGetCheckFailErr */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : Sl_FlsPrgRsltType Sl_lGetProgFailErr                    **
**                    (                                                       **
**                      const uint8 FlashBank                                 **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters (in)  : FlashBank - Flash bank for which the flash programming  **
**                                failed                                      **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : SL_PROG_FAIL_PFx - Programming failed for flash bank x  **
**                    SL_CORRUPTION_ERR - Invalid FlashBank parameter         **
**                                                                            **
** Description      : This functions returns the correct error code           **
**                    - depending on flash bank to be programmed - in case    **
**                    the pattern programming failed.                         **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE Sl_FlsPrgRsltType Sl_lGetProgFailErr
(
  const uint8 FlashBank
)
{
  Sl_FlsPrgRsltType Result;

  switch (FlashBank)
  {
  case 0:
    Result = SL_PROG_FAIL_PF0;
    break;

  case 1:
    Result = SL_PROG_FAIL_PF1;
    break;

  case 2:
    Result = SL_PROG_FAIL_PF2;
    break;

  case 3:
    Result = SL_PROG_FAIL_PF3;
    break;

  default:
    Result = SL_CORRUPTION_ERR;
    break;
  } /* switch (FlashBank) */

  return Result;
} /* Sl_lGetProgFailErr */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : boolean Sl_lCheckErrorPattern                           **
**                    (                                                       **
**                      const uint8 FlashBank,                                **
**                      boolean* const PatternOk                              **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters (in)  : FlashBank - Flash bank that is to be checked for the    **
**                                error patterns                              **
**                                                                            **
** Parameters (out) : PatternOk - Programming status of patterns in given     **
**                                flash bank:                                 **
**                                  - TRUE: Patterns already programmed       **
**                                  - FALSE: Patterns not yet programmed      **
**                                                                            **
** Return value     : E_OK - Check succeeded, programming state has been      **
**                           stored to PatternOk parameter                    **
**                    E_NOT_OK - Check failed due to timeout error or because **
**                               no base patterns were found in PFLASH;       **
**                               PatternOk parameter has not been modified    **
**                                                                            **
** Description      : Checks whether the test patterns for the PMU ECC/EDC    **
**                    test have already been programmed to PFLASH, i.e.       **
**                    whether bit errors have already been created.           **
**                    It also checks, whether the PFLASH contains the base    **
**                    patterns required for error pattern programming.        **
**                                                                            **
** Note(s)          : This function reads PFLASH pages with uncorrectable ECC **
**                    errors. It is expected that this API is executed before **
**                    the SMU is put into RUN state. If this API is used when **
**                    the SMU is already in RUN state, the caller shall be    **
**                    prepared to receive SMU alarms due to PFLASH ECC        **
**                    errors.                                                 **
**                                                                            **
*******************************************************************************/
static Std_ReturnType Sl_lCheckErrorPattern
(
  const uint8 FlashBank,
  boolean* const PatternOk
)
{
  Std_ReturnType          Result = E_NOT_OK;
  uint32                  CbabCfgBackup;
  uint32                  UbabCfgBackup;
  uint32                  i;
  boolean                 VcwPatternFound;

  /* Table of FLASH0_CBABCFG registers for each flash bank: */
  volatile Ifx_FLASH_CBAB_CFG* CbabCfgTable[PMU_ECC_EDC_TST_MAX_FLASHBANKS] =
  {
    &FLASH0_CBABCFG0
#if (PMU_ECC_EDC_TST_MAX_FLASHBANKS > 1U)
    ,
    &FLASH0_CBABCFG1
#if (PMU_ECC_EDC_TST_MAX_FLASHBANKS > 2U)
    ,
    &FLASH0_CBABCFG2
#if (PMU_ECC_EDC_TST_MAX_FLASHBANKS > 3U)
	,
    &FLASH0_CBABCFG3
#endif
#endif
#endif
  };

  /* Table of FLASH0_UBABCFG registers for each flash bank: */
  volatile Ifx_FLASH_UBAB_CFG* UbabCfgTable[PMU_ECC_EDC_TST_MAX_FLASHBANKS] =
  {
    &FLASH0_UBABCFG0
#if (PMU_ECC_EDC_TST_MAX_FLASHBANKS > 1U)
    ,
    &FLASH0_UBABCFG1
#if (PMU_ECC_EDC_TST_MAX_FLASHBANKS > 2U)
    ,
    &FLASH0_UBABCFG2
#if (PMU_ECC_EDC_TST_MAX_FLASHBANKS > 3U)
	,
    &FLASH0_UBABCFG3
#endif
#endif
#endif
  };

  /* Backup CBAB / UBAB configuration: */
  CbabCfgBackup = CbabCfgTable[FlashBank]->U;
  UbabCfgBackup = UbabCfgTable[FlashBank]->U;

  /* Disable CBAB / UBAB error tracking: */
  Mcal_ResetENDINIT();
  CbabCfgTable[FlashBank]->B.DIS = 1U;
  UbabCfgTable[FlashBank]->B.DIS = 1U;
  Mcal_SetENDINIT();

  /* Check if base patterns exist in PFLASH, at least one valid code word page
   * of a pattern-set must contain the expected pattern:
   */

  /* Calculate and compare Crc of functions in RAM that 
  were copied from PFlash at startup*/
  Result = Sl_lRamCalculateandVerifyCrc32();

  if (E_OK == Result)
  {
    /* Loop through all VCW pages of the pattern set and check if at least one
     * contains the valid code word:
     */
    VcwPatternFound = FALSE;
    Mcal_ResetENDINIT();
    for (i = 0U;
         (i < PMUT_TEST_PATTERN_COUNT) && (FALSE == VcwPatternFound);
         i++)
    {
      VcwPatternFound = Sl_lComparePageHelper(&PmuEccEdcTst_TestPattern[FlashBank]->
                                      Set[i].Pattern[SLFLS_VCW_PTRN_IDX],
                                     &PmuEccEdcTst_VcwRefPtrn[i]);
    } /* for (i = 0U;
              (i < PMUT_TEST_PATTERN_COUNT) && (FALSE == VcwPatternFound);
              i++) */
    Mcal_SetENDINIT();

    if (FALSE == VcwPatternFound)
    {
      /* No base patterns in PFLASH, programming cannot be done! */
      Result = E_NOT_OK;
    } /* if (FALSE == VcwPatternFound) */
    else
    {
      /* Calculate and compare Crc of functions in RAM that 
      were copied from PFlash at startup*/
      Result = Sl_lRamCalculateandVerifyCrc32();

    } /* if (FALSE != VcwPatternFound) */
  } /* if (E_OK == Result) */

  if (E_OK == Result)
  {
    Mcal_ResetENDINIT();
    *PatternOk = Sl_lChkErrPtrnHelper(PmuEccEdcTst_TestPattern[FlashBank]);

    /* Restore CBAB / UBAB configuration: */
    CbabCfgTable[FlashBank]->U = CbabCfgBackup;
    UbabCfgTable[FlashBank]->U = UbabCfgBackup;
    Mcal_SetENDINIT();
  } /* if (E_OK == Result) */
  else
  {
    /* Restore CBAB / UBAB configuration: */
    Mcal_ResetENDINIT();
    CbabCfgTable[FlashBank]->U = CbabCfgBackup;
    UbabCfgTable[FlashBank]->U = UbabCfgBackup;
    Mcal_SetENDINIT();
  } /* if (E_OK != Result) */

  return Result;
} /* Sl_lCheckErrorPattern */



/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : Std_ReturnType Sl_lProgramPage                          **
**                    (                                                       **
**                      const SlFls_ProgDataType* const ProgData              **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters (in)  : ProgData - Pointer to a structure holding all           **
**                               required parameters to program one page      **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : E_OK - Programming flash page succeeded                 **
**                    E_NOT_OK - Programming flash page failed or page        **
**                               address not aligned on flash page boundary   **
**                                                                            **
** Description      : Programs a single page of Program FLASH by entering     **
**                    flash page mode, copying the actual programming routine **
**                    to SPRAM and executing that routine.                    **
**                                                                            **
*******************************************************************************/
static Std_ReturnType Sl_lProgramPage
(
  const SlFls_ProgDataType* const ProgData
)
{
  Std_ReturnType  Result = E_NOT_OK;

  /* Disable interrupts */
  Mcal_SuspendAllInterrupts();

  /* Enter page mode: */
  if (E_OK == Sl_lEnterPageMode())
  {
    /* Check the alignment of the page address: */
    /* Alignment check requires address calculation with unsigned type */
    if (0U == ((uint32)ProgData->PageAddr % SLFLS_BYTES_PER_WORDLINE))
    {
      uint32  i;

      /* Setup ECC data: */
      Mcal_ResetENDINIT();
      FLASH0_ECCW.B.WCODE = (unsigned_int)((ProgData->EccData) & SLFLS_ECC_MASK);
      FLASH0_ECCW.B.PECENCDIS = 1U;
      Mcal_SetENDINIT();

      /* Load Page Data to the internal write buffer */
      for (i = 0U; i < PMUT_WORDS_PER_PAGE; i += 2U )
      {
        *(SlFls_FlashProgAccess.LoadPage0) = (uint32)(ProgData->PageData.Data[i]);
        *(SlFls_FlashProgAccess.LoadPage1) = (uint32)(ProgData->PageData.Data[i + (uint32)1U]);
      } /* for (i = 0u; i < PMUT_WORDS_PER_PAGE; i += 2u ) */

      /* Check status of Load Page operation */
      if (0U == FLASH0_FSR.B.SQER)
      {
        /* Calculate and compare Crc of functions in RAM that 
        were copied from PFlash at startup*/
        if (E_OK == Sl_lRamCalculateandVerifyCrc32())
        {
          /* Execute Write Page command, this must be done from SPRAM and under
           * safety ENDINIT protection: */
          Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT); 
          Result = Sl_lProgramPageFcn(ProgData);
          Mcal_SetSafetyENDINIT_Timed();
        } /* if (E_OK == Sl_lRamCalculateandVerifyCrc32()) */
      } /* if (0U == FLASH0_FSR.B.SQER) */
    } /* if (0U == ((uint32)ProgData->PageAddr % SLFLS_BYTES_PER_WORDLINE)) */
  } /* if (E_OK == Sl_lEnterPageMode()) */

  /* Clear flash status flags: */
  *SlFls_FlashProgAccess.FlashCmd = SLFLS_FSI_CMD_FA;

  /* enable interrupts */
  Mcal_ResumeAllInterrupts();

  return Result;
} /* Sl_lProgramPage */


/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : Std_ReturnType Sl_lEnterPageMode(void)                  **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : E_OK - Entering Page Mode succeeded                     **
**                    E_NOT_OK - Entering Page Mode failed                    **
**                                                                            **
** Description      : Brings Program FLASH0 FSI into Page Mode.               **
**                                                                            **
*******************************************************************************/
static Std_ReturnType Sl_lEnterPageMode(void)
{
  Std_ReturnType  Result  = E_NOT_OK;
  uint32          Timeout = SLFLS_PAGE_MODE_TIMEOUT;

  /* Enter Page Mode for Program FLASH */
  *(SlFls_FlashProgAccess.FlashCmd) = SLFLS_FSI_CMD_50;

  /* according to application hint */
  DSYNC();

  /* Check if Page Mode has been entered */
  while (Timeout > 0U)
  {
    Timeout--;
    /* fail if SQER / PROER signaled */
    if ((FLASH0_FSR.U & SLFLS_FLASH_FSR_ERROR2_MASK) != 0U)
    {
        Timeout = 0U;
    } /* if ((FLASH0_FSR.U & SLFLS_FLASH_FSR_ERROR2_MASK) != 0U) */

    if (1U == FLASH0_FSR.B.PFPAGE)
    {
      Result = E_OK;
      Timeout = 0U;
    } /* if (1U == FLASH0_FSR.B.PFPAGE) */
  } /* while (Timeout > 0U) */

  return Result;
} /* Sl_lEnterPageMode */


/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static Std_ReturnType Sl_lRamCalculateandVerifyCrc32    **
**                    (                                                       **
**                      void                                                  **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : E_OK - CRC32 value of all the functions that were copied**
**                    to RAM during start up matches the CRC value of the same**
**                    functions in PFlash                                     **
**                    E_NOT_OK - CRC32 value mismatch                         **
**                                                                            **
** Description      : It calculates the CRC32 value of memory area having all **
**                    the functions that were copied to RAM during startup and**
**                    compares it with the CRC32 value of the area in PFLASh  **
**                    that holds these functions                              **
**                                                                            **
*******************************************************************************/
static Std_ReturnType Sl_lRamCalculateandVerifyCrc32(void)
{
  uint32 crcvalue = 0U;
  Std_ReturnType  Result = E_NOT_OK;
  
  uint32 beginaddr, endaddr;
  
  endaddr = (uint32)LOC_END_PflashMon_EccEdc_RAM_RUNCODE;
  beginaddr = (uint32)LOC_START_PflashMon_EccEdc_RAM_RUNCODE;
  
  crcvalue = PmuEccEdcTst_CalculateCrc32(LOC_START_PflashMon_EccEdc_RAM_RUNCODE,
            (endaddr-beginaddr));
            
  if(crcvalue == SlFls_PFlashFnCrc32)
  {
    Result = E_OK;
  }
    
  return Result;
}/*Sl_lRamCalculateandVerifyCrc32*/


#define IFX_PMU_APPL_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"


