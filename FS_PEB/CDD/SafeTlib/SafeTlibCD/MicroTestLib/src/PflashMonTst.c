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
**   $FILENAME   : PflashMonTst.c $                                           **
**                                                                            **
**   $CC VERSION : \main\35 $                                                 **
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
**                 the PFLASH monitor, i.e. tracking of PFLASH ECC errors     **
**                 to the CBAB / UBAB registers.                              **
**                                                                            **
**  REFERENCE(S) : Aurix-HE_SafeTlib_DS_PflashMon.docm, v1.0                  **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

#include "PflashMonTst.h"
#include "PmuEccEdcTst.h"
#include "ChipId.h"
#include "Mcal.h"
#include "SmuInt.h"
#include "IfxCpu_bf.h"
#include "IfxCpu_reg.h"
#include "IfxSmu_reg.h"

/*******************************************************************************
**                      Local Macro Definitions                               **
*******************************************************************************/

/* Indices of test patterns within a pattern set array: */
#define PFM_VCW_PTRN_IDX                ( 0U )
#define PFM_SBE_PTRN_IDX                ( 1U )
#define PFM_DBE_PTRN_IDX                ( 2U )
#define PFM_MBE_PTRN_IDX                ( 3U )


/* Flash bank definitions: */
#define PFM_FLASH_BANK0                 ( (uint32)0U )
#define PFM_FLASH_BANK1                 ( (uint32)1U )
#define PFM_FLASH_BANK2                 ( (uint32)2U )
#define PFM_FLASH_BANK3                 ( (uint32)3U )

/* Timeout for an PFLASH ECC error getting pushed into the CBAB / UBAB FIFOs
 * in number of loop cycles:
 */
#define PFM_ERROR_FIFO_TIMEOUT          ( (uint32)0x00000020U )

/* FSI Commands */
#define PFM_FSI_CMD_FA                  ( (uint32)0x000000FAU )

/* Data Flash Base Address for Flash commands */
#define PFM_PMU0_DF0_BASE               ( (uint32)0xAF000000U )

/* Relative address of flash command interface: */
#define PFM_FLS_CMD_ADDR                ( (uint32)0x00005554U )

/* Base address of PMU0 (in non-cachable segment): */
#define PFM_PMU0_BASE_ADDRESS           ( (uint32)0xA0000000U )

/* Number of bits to shift CBAB.ADDR to get the system address: */
#define PFM_CBAB_ADDR_SHIFT             ( (uint32)5U )

/* Number of bits to shift UBAB.ADDR to get the system address: */
#define PFM_UBAB_ADDR_SHIFT             ( (uint32)5U )

/* Error type definitions to be used with C/UBAB_CFG.SEL and C/UBAB_TOP.ERR: */
#define PFM_SINGLE_BIT_ERROR            ( (uint32)1U )
#define PFM_DOUBLE_BIT_ERROR            ( (uint32)2U )
#ifdef PFLASH_FIFO_BUFFERFULL_TEST_ENABLE
#define PFM_SINGLE_AND_DOUBLE_BIT_ERROR ( (uint32)3U )
#endif
#define PFM_MULTI_BIT_ERROR             ( (uint32)4U )

/* SMU alarm group 2 alarm mask for alarms triggered by the test: */
#ifdef PFLASH_FIFO_BUFFERFULL_TEST_ENABLE
#define PFM_SMU_ALARM_MASK              ( (uint32)0x0000005CU )
#else
#define PFM_SMU_ALARM_MASK              ( (uint32)0x0000001CU )
#endif

/* Bit masks for PMU related SMU alarms triggered by the test: */
#define PFM_SMU_ALARM2                  ( ((uint32)1U << SMU_ALARM_2) )
#define PFM_SMU_ALARM3                  ( ((uint32)1U << SMU_ALARM_3) )
#define PFM_SMU_ALARM4                  ( ((uint32)1U << SMU_ALARM_4) )
#ifdef PFLASH_FIFO_BUFFERFULL_TEST_ENABLE
#define PFM_SMU_ALARM6                  ( ((uint32)1U << SMU_ALARM_6) )

/*Bit masks needed for filling CBAB*/
#define PFM_DBE_OFFSET                  ((uint32)0x08U)
#define PFM_NEXT_SBE_OFFSET             ((uint32)0x20U)

/* SMU clear alarm status timeout: */
#define PFM_SMU_AGSTATUS_TIMEOUT       ( (uint32)1000U )
#endif
/*******************************************************************************
**                           Config check                                     **
*******************************************************************************/

/* Number of PFLASH banks must be the same for PmuEccEdcTst and PflashMonTst: */
#if (PFLASH_MON_TST_MAX_FLASHBANKS != PMU_ECC_EDC_TST_MAX_FLASHBANKS)
#error Different number of PFLASH banks for the PmuEccEdcTst and PflashMonTst
#endif /* (PFLASH_MON_TST_MAX_FLASHBANKS != PMU_ECC_EDC_TST_MAX_FLASHBANKS) */


/*******************************************************************************
**                      Local Type Definitions                                **
*******************************************************************************/

/* Type definition PflashMonTst_BackupDataType - container for backup data of
 * SFRs modified by the test:
 */
typedef struct PflashMonTst_BackupDataType
{
  /* PMU single bit error correction SMU alarm action backup: */
  Smu_AlarmActionType AlmActionSbe;

  /* PMU double bit error correction SMU alarm action backup: */
  Smu_AlarmActionType AlmActionDbe;

  /* PMU uncorrectable bit error SMU alarm action backup: */
  Smu_AlarmActionType AlmActionMbe;
#ifdef PFLASH_FIFO_BUFFERFULL_TEST_ENABLE
  /* PFlash Monitor Address Buffer Full alarm action backup: */
  Smu_AlarmActionType AlmActionBufferFull;
#endif
  /* Backup space for FLASH_CBAB_CFGx registers: */
  uint32              CbabCfgBackup[PFLASH_MON_TST_MAX_FLASHBANKS];

  /* Backup space for FLASH_UBAB_CFGx registers: */
  uint32              UbabCfgBackup[PFLASH_MON_TST_MAX_FLASHBANKS];

  /* Value indicating that all backup values are valid and may be restored: */
  boolean             Valid;

  /* CRC: */
  uint32              Crc32;
} PflashMonTst_BackupDataType;

/* Type definition PflashMonTst_TestDataType - container for a given test set:
 */
typedef struct PflashMonTst_TestDataType
{
  /* Pointer to test signature, location is updated after each test: */
  uint32*                       Signature;

  /* Pointer to test patterns of current flash bank: */
  PmuEccEdcTst_TestPatternType* FlashPattern;

  /* Pointer to Flash CBABx SFRs, depends on flash bank under test: */
  volatile Ifx_FLASH_CBAB_CFG*  FlashCbabCfgPtr;
  volatile Ifx_FLASH_CBAB_TOP*  FlashCbabTopPtr;
#ifdef PFLASH_FIFO_BUFFERFULL_TEST_ENABLE
  volatile Ifx_FLASH_CBAB_STAT* FlashCbabStatusPtr;
#endif

  /* Pointer to Flash UBABx SFRs, depends on flash bank under test: */
  volatile Ifx_FLASH_UBAB_CFG*  FlashUbabCfgPtr;
  volatile Ifx_FLASH_UBAB_TOP*  FlashUbabTopPtr;

  /* Access pointer to Flash MARP for trap disable/enable: */
  volatile Ifx_FLASH_MARP*      FlashMarpPtr;

  /* Flash command interface: */
  volatile uint32*              FlashCmd;

  /* Current PFLASH bank: */
  uint32                        FlashBank;
} PflashMonTst_TestDataType;

/* Type definition PflashMonTst_CbabHlprType - container for parameter set used
 * for PFLASH monitor correctable error helper call */
typedef struct PflashMonTst_CbabHlprType
{
  /* Pointer to Flash CBABx SFRs: */
  volatile Ifx_FLASH_CBAB_CFG*          FlashCbabCfgPtr;
  volatile Ifx_FLASH_CBAB_TOP*          FlashCbabTopPtr;
#ifdef PFLASH_FIFO_BUFFERFULL_TEST_ENABLE
  volatile Ifx_FLASH_CBAB_STAT*         FlashCbabStatusPtr;
#endif
  /* Access pointer to flash MARP for trap disable/enable: */
  volatile Ifx_FLASH_MARP*              FlashMarpPtr;
  
  /* SMU command address: */
  volatile Ifx_SMU_CMD*                 SmuCmd;

  /* SMU alarm group address: */
  volatile Ifx_SMU_AG*                  SmuAlm;

  /* CBAB_TOP content after PFLASH access: */
  Ifx_FLASH_CBAB_TOP                    CbabTopAfter;

  /* SMU alarm group 2 alarms already set before PFLASH access: */
  uint32                                SmuAlmBefore;
#ifdef PFLASH_FIFO_BUFFERFULL_TEST_ENABLE  
  /* Alarm value after: */
  uint32                                SmuAlmAfter;
  
  /* Mask of relevant SMU alarms: */
  uint32                                SmuAlmMask;
#endif
  /* Data read address: */
  const PmuEccEdcTst_FlashPageType*     DataAddr;
#ifdef PFLASH_FIFO_BUFFERFULL_TEST_ENABLE
  /* Data read address: */
  const PmuEccEdcTst_TestPatternType*   PatternAddr;
  
  /* Flash command interface: */
  volatile uint32*                      FlashCmd;
#endif
  /* CBAB_CFG.SEL error type to track: */
  uint32                                ErrorType;
#ifdef PFLASH_FIFO_BUFFERFULL_TEST_ENABLE
  /*Counts the number of errors stored in CBAB*/  
  uint32                                FifoErrorCount;
#endif
} PflashMonTst_CbabHlprType;


/* Type definition PflashMonTst_UbabHlprType - container for parameter set used
 * for PFLASH monitor uncorrectable error helper call */
typedef struct PflashMonTst_UbabHlprType
{
  /* Pointer to Flash UBABx SFRs: */
  volatile Ifx_FLASH_UBAB_CFG*          FlashUbabCfgPtr;
  volatile Ifx_FLASH_UBAB_TOP*          FlashUbabTopPtr;

  /* Access pointer to flash MARP for trap disable/enable: */
  volatile Ifx_FLASH_MARP*              FlashMarpPtr;

  /* SMU command address: */
  volatile Ifx_SMU_CMD*                 SmuCmd;

  /* SMU alarm group address: */
  volatile Ifx_SMU_AG*                  SmuAlm;

  /* UBAB_TOP content after PFLASH access: */
  Ifx_FLASH_UBAB_TOP                    UbabTopAfter;

  /* SMU alarm group 2 alarms already set before PFLASH access: */
  uint32                                SmuAlmBefore;

  /* Data read address: */
  const PmuEccEdcTst_FlashPageType*     DataAddr;
} PflashMonTst_UbabHlprType;

/******************************************************************************
**                        Exported object definitions                         *
******************************************************************************/


/******************************************************************************
**                        Imported object definitions                         *
******************************************************************************/


/******************************************************************************
**                        Local object definitions                            *
******************************************************************************/

#define IFX_PFLASHMON_START_SEC_VAR_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"

/* List of CBAB / UBAB entries cleared during test initialization: */
static PflashMonTst_ClearedErrorType  PflashMonTst_ClearedErr;

/* List of unexpected SMU alarms cleared during test execution: */
static PflashMonTst_UnexpAlarmType    PflashMonTst_UnexpAlm;

#define IFX_PFLASHMON_STOP_SEC_VAR_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"

#define IFX_PFLASHMON_START_SEC_VAR_32BIT_ASIL_B
#include "Ifx_MemMap.h"

/* Variable to hold the CRC32 value of PFLASH_MON_ECCEDC_RAMCODE section
   functions in PFlash*/
static uint32   PflashMonTst_PFlashFnCrc32;

#define IFX_PFLASHMON_STOP_SEC_VAR_32BIT_ASIL_B
#include "Ifx_MemMap.h"

/******************************************************************************
**                        Imported function declarations                      *
******************************************************************************/


/******************************************************************************
**                        Local function prototypes                           *
******************************************************************************/
#define IFX_PFLASHMON_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
static Sl_TstRsltType PflashMonTst_lCheckConfig
(
  const Sl_ParamSetType ParamSetIndex
);

static Sl_TstRsltType PflashMonTst_lInit
(
  PflashMonTst_BackupDataType* const BackupData,
  const PflashMonTst_ConfigType* const Config
);

static Sl_TstRsltType PflashMonTst_lRestore
(
  const PflashMonTst_BackupDataType* const BackupData
);

static Sl_TstRsltType PflashMonTst_lTestFlsBank
(
  const PflashMonTst_TestDataType* TestData
);

static Sl_TstRsltType PflashMonTst_lTestSbeTracking
(
  const PflashMonTst_TestDataType* TestData
);

static Sl_TstRsltType PflashMonTst_lTestDbeTracking
(
  const PflashMonTst_TestDataType* TestData
);
#ifdef PFLASH_FIFO_BUFFERFULL_TEST_ENABLE
static Sl_TstRsltType PflashMonTst_lTestFifoBufferFull
(
  const PflashMonTst_TestDataType* TestData
);
#endif
#define IFX_PFLASHMON_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
#define IFX_PFLASHMONTST_START_SEC_RAM_CODE_ASIL_B
#include "Ifx_MemMap.h"

/* Functions that are copied and executed in SPRAM */
static void PflashMonTst_lCbabHelper
(
  PflashMonTst_CbabHlprType* CbabHlprPtr
);

static void PflashMonTst_lUbabHelper
(
  PflashMonTst_UbabHlprType* UbabHlprPtr
);
#ifdef PFLASH_FIFO_BUFFERFULL_TEST_ENABLE
static Sl_TstRsltType PflashMonTst_lCbabFullHelper
(
  PflashMonTst_CbabHlprType* CbabFullHlprPtr
);

static Sl_TstRsltType PflashMonTst_lClearAlarms
(
  const PflashMonTst_CbabHlprType* CbabFullHlprPtr
);

static void PflashMonTst_lWaitForValidBit
(
  PflashMonTst_CbabHlprType* CbabFullHlprPtr,
  uint32* BitMask
);
#endif
#define IFX_PFLASHMONTST_STOP_SEC_RAM_CODE_ASIL_B
#include "Ifx_MemMap.h"
#define IFX_PFLASHMON_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
static Sl_TstRsltType PflashMonTst_lTestMbeTracking
(
  const PflashMonTst_TestDataType* TestData
);


static void PflashMonTst_lClearClearedErrList
(
  void
);

static void PflashMonTst_lClearUnexpAlmList
(
  void
);

static void PflashMonTst_lClearErrorFifos
(
  const PflashMonTst_ConfigType* const Config
);

static uint32 PflashMonTst_lGetCbabSystemAddress
(
  volatile Ifx_FLASH_CBAB_TOP Cbab
);

static uint32 PflashMonTst_lGetUbabSystemAddress
(
  volatile Ifx_FLASH_UBAB_TOP Ubab
);

static void PflashMonTst_lCountUnexpAlm
(
  uint32 CurrAlmStatus
);

static Sl_TstRsltType PflashMonTst_lGetSbeErrorCode
(
  const uint32 FlashBank
);

static Sl_TstRsltType PflashMonTst_lGetDbeErrorCode
(
  const uint32 FlashBank
);

static Sl_TstRsltType PflashMonTst_lGetMbeErrorCode
(
  const uint32 FlashBank
);

static uint32 PflashMonTst_lCalcClearedErrCrc
(
  void
);

static uint32 PflashMonTst_lCalcUnexpAlmCrc
(
  void
);

static uint32 PflashMonTst_lCalcBackupCrc
(
  const PflashMonTst_BackupDataType* const BackupData
);

static Sl_TstRsltType PflashMonTst_lRamCalculateandVerifyCrc32
(
  void
);
#ifdef PFLASH_FIFO_BUFFERFULL_TEST_ENABLE
static void PflashMonTst_lClearSpecificErrorFifo
(
  const PflashMonTst_TestDataType* TestData
);

static Sl_TstRsltType PflashMonTst_lGetFifoFullErrorCode
(
  const uint32 FlashBank
);
#endif
#define IFX_PFLASHMON_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
/******************************************************************************
**                    Local inline function definitions                       *
******************************************************************************/


/******************************************************************************
**                         Function definitions                               *
******************************************************************************/
#define IFX_PFLASHMONTST_START_SEC_RAM_CODE_ASIL_B
#include "Ifx_MemMap.h"
#ifdef PFLASH_FIFO_BUFFERFULL_TEST_ENABLE
#ifdef __TASKING__
PRAGMA_ALL(OPTIMIZE_0)
#endif
/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static Sl_TstRsltType PflashMonTst_lClearAlarms         **
**                    (                                                       **
**                      const PflashMonTst_CbabHlprType* CbabFullHlprPtr      **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters(in)   : CbabFullHlprPtr - Pointer to test data structure for    **
**                                  data exchange between the test function   **
**                                  in PFLASH and the helper routine in SRAM  **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Status = 0, if alarms were cleared                      **
**                                                                            **
** Description      : This function clears the SMU Group 2 alarms related to  **
**                    PFlash                                                  **
**                    ATTENTION:                                              **
**                    This function must be executed from SRAM as it is called**
**                    by PflashMonTst_lCbabFullHelper that executes from RAM. **
**                    It must be checked, that no unintended access to PFLASH **
**                    is made, e.g. for constant loading.                     **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType PflashMonTst_lClearAlarms
(
  const PflashMonTst_CbabHlprType* CbabFullHlprPtr
)
{
  uint32             Status=0U;
  uint32             Timeout;
  /* Send an ALARM CLEAR command to the SMU Control Interface   */
  CbabFullHlprPtr->SmuCmd->U = 5U;

  /* Clear all PFlash related SMU Group 2, Alarms */
  CbabFullHlprPtr->SmuAlm->U = PFM_SMU_ALARM_MASK;

  /* Check if SMU alarms were really cleared: */
  Timeout = 0U;
  do
  {
    Status = 
    (uint32)(CbabFullHlprPtr->SmuAlm->U & PFM_SMU_ALARM_MASK);
    Timeout++;
  } while ((Timeout < PFM_SMU_AGSTATUS_TIMEOUT) &&
           (Status != 0U));
  return Status;  
}

#ifdef __TASKING__
PRAGMA_ALL(OPTIMIZE_RESTORE)
#endif

#ifdef __TASKING__
PRAGMA_ALL(OPTIMIZE_0)
#endif
/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static void PflashMonTst_lWaitForValidBit               **
**                    (                                                       **
**                        PflashMonTst_CbabHlprType* CbabFullHlprPtr,         **
**                        uint32* BitMask                                     **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters(in)   : CbabFullHlprPtr - Pointer to test data structure for    **
**                                  data exchange between the test function   **
**                                  in PFLASH and the helper routine in SRAM  **
**                    BitMask - Pointer to bitmask to be used for checking the**
**                                  valid bit in CBAB status register         **
**                                                                            **
** Parameters (out) : FifoErrorCount is incremented. BitMask is updated       **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function checks the Valid bit corresponding to the **
**                    entry in CBAB. If it is set, the FifoErrorCount is      **
**                    incremented and the bitmask for the VLD bit of the next **
**                    Fifo entry is prepared.                                 **
**                    ATTENTION:                                              **
**                    This function must be executed from SRAM as it is called**
**                    by PflashMonTst_lCbabFullHelper that executes from RAM. **
**                    It must be checked, that no unintended access to PFLASH **
**                    is made, e.g. for constant loading.                     **
**                                                                            **
*******************************************************************************/
static void PflashMonTst_lWaitForValidBit
(
  PflashMonTst_CbabHlprType* CbabFullHlprPtr,
  uint32* BitMask
)
{
  uint32             Timeout;
  /* Give a short delay: */
  Timeout = PFM_ERROR_FIFO_TIMEOUT;
  while (Timeout > 0U)
  {
    Timeout--;
    if (0U != ((*BitMask) & CbabFullHlprPtr->FlashCbabStatusPtr->U))
    {
      CbabFullHlprPtr->FifoErrorCount++;  
      (*BitMask) = (*BitMask) << 1U;
      break;
    } 
  } /* while (Timeout > 0U) */  
}

#ifdef __TASKING__
PRAGMA_ALL(OPTIMIZE_RESTORE)
#endif


#ifdef __TASKING__
PRAGMA_ALL(OPTIMIZE_0)
#endif
/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static Sl_TstRsltType PflashMonTst_lCbabFullHelper      **
**                    (                                                       **
**                      PflashMonTst_CbabHlprType* CbabFullHlprPtr            **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters(in)   : CbabFullHlprPtr - Pointer to test data structure for    **
**                                  data exchange between the test function   **
**                                  in PFLASH and the helper routine in SRAM  **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This helper routine enables CBAB buffer full alarm test.**
**                    It reads a correctable double bit error pattern from    **
**                    PFLASH and checks whether the AG2[6] is raised          **
**                                                                            **
**                    ATTENTION:                                              **
**                    This function must be executed from SRAM. It must be    **
**                    checked, that no unintended access to PFLASH is made,   **
**                    e.g. for constant loading.                              **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType PflashMonTst_lCbabFullHelper
(
  PflashMonTst_CbabHlprType* CbabFullHlprPtr
)
{

  uint32             AlarmStatusReadback;
  uint32             Timeout;
  uint32             FlashMarpSave = CbabFullHlprPtr->FlashMarpPtr->U;
  Sl_TstRsltType     Result = PFLASHMON_NOTEXECUTED;
  uint32             i = 0U;
  uint32             j = 0U;
  volatile uint32    Dummy = 0U;
  uint32             ValidBit_Mask = 0x00000001U;
  
  /* ECC trap disable */
  CbabFullHlprPtr->FlashMarpPtr->B.TRAPDIS = 1U;

  /* To remove warning in GNU */
  UNUSED_PARAMETER(Dummy)

  /* get current alarm status before access */
  CbabFullHlprPtr->SmuAlmBefore = CbabFullHlprPtr->SmuAlm->U;
  AlarmStatusReadback = PflashMonTst_lClearAlarms(CbabFullHlprPtr);

  if (0U != AlarmStatusReadback)
  {
    Result = PFLASHMON_SMU_CLRALMSTSERR;
  } /* if (0U != AlarmStatusReadback) */
  else
  {
      
    /* Enable tracking of single and double bit errors: */
    CbabFullHlprPtr->FlashCbabCfgPtr->B.SEL = (uint8)CbabFullHlprPtr->ErrorType;
    CbabFullHlprPtr->FlashCbabCfgPtr->B.DIS = 0U;

    /* Enforce completion of FLASH_CBAB_CFG write: */
    DSYNC();
  
    /* Loop through each of the four redundant test patterns in PFLASH: */
    for (i = 0U;
         (i < PMUT_TEST_PATTERN_COUNT);
         i++)
    {
      j = i*PFM_NEXT_SBE_OFFSET;
      /* Read access to Single Bit Error Pattern */
      Dummy = CbabFullHlprPtr->DataAddr->Data[j];
      PflashMonTst_lWaitForValidBit(CbabFullHlprPtr, &ValidBit_Mask);

      j = j + PFM_DBE_OFFSET;
      /* Read access to Double Bit Error Pattern */
      Dummy = CbabFullHlprPtr->DataAddr->Data[j];
        
      PflashMonTst_lWaitForValidBit(CbabFullHlprPtr, &ValidBit_Mask);
    }

    /* Read DBEs until CBAB full alarm is raised */
    for (i = 0U; i < (uint32)PFLASH_MON_CBAB_FIFO_DEPTH; i++)
    {
      /*Read DBE Error*/
      Dummy = CbabFullHlprPtr->PatternAddr->DBEPage[i].Data[0];
       
      /* Give a short delay: */
      Timeout = PMUT_SMU_ALM_TIMEOUT2;
      while (Timeout > 0U)
      {
        Timeout--;
        /*Check if corresponding valid bit in status register is set*/
        if (0U != (ValidBit_Mask & CbabFullHlprPtr->FlashCbabStatusPtr->U))
        {
          CbabFullHlprPtr->FifoErrorCount++;
          ValidBit_Mask = ValidBit_Mask << 1;
        } 
        /* Check if CBAB full alarm is raised*/
        if ((CbabFullHlprPtr->SmuAlm->U & PFM_SMU_ALARM6) != 0U)
        {
          break;              /* any alarm seen */
        } /* if ((CbabFullHlprPtr->SmuAlm->U & CbabFullHlprPtr->SmuAlmMask) != 0u) */
      } /* while (Timeout > 0U) */
    } /* for (i = 0U; i < (uint32)PFLASH_MON_CBAB_FIFO_DEPTH; i++) */
  
    /* get current alarm status after access */
    CbabFullHlprPtr->SmuAlmAfter = CbabFullHlprPtr->SmuAlm->U;
    
    /* Disable error tracking: */
    CbabFullHlprPtr->FlashCbabCfgPtr->B.DIS = 1U;
    
    DSYNC();

    /* flash clear status */
    *CbabFullHlprPtr->FlashCmd = PFM_FSI_CMD_FA;

    AlarmStatusReadback = PflashMonTst_lClearAlarms(CbabFullHlprPtr);
    if (0U != AlarmStatusReadback)
    {
      Result = PFLASHMON_SMU_CLRALMSTSERR;
    } /* if (0U != AlarmStatusReadback) */
    else
    {
      Result = PFLASHMON_SUCCESS;
    } /* if (0U != AlarmStatusReadback) */
  } /* if (0U == AlarmStatusReadback) */

  /* restore ECC trap handling */
  CbabFullHlprPtr->FlashMarpPtr->U = FlashMarpSave;

  return Result;
} /* PflashMonTst_lCbabFullHelper */
#ifdef __TASKING__
PRAGMA_ALL(OPTIMIZE_RESTORE)
#endif
#endif
/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static void PflashMonTst_lCbabHelper                    **
**                    (                                                       **
**                      PflashMonTst_CbabHlprType* CbabHlprPtr                **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters(in)   : CbabHlprPtr - Pointer to test data structure for        **
**                                  data exchange between the test function   **
**                                  in PFLASH and the helper routine in SRAM  **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This helper routine enables CBAB error tracking, reads  **
**                    a correctable bit error pattern from PFLASH and stores  **
**                    the expected new CBAB FIFO entry to a given data        **
**                    structure.                                              **
**                                                                            **
**                    ATTENTION:                                              **
**                    This function must be executed from SRAM. It must be    **
**                    checked, that no unintended access to PFLASH is made,   **
**                    e.g. for constant loading.                              **
**                                                                            **
*******************************************************************************/
#ifdef __TASKING__
PRAGMA_ALL(OPTIMIZE_0)
#endif
static void PflashMonTst_lCbabHelper
(
  PflashMonTst_CbabHlprType* CbabHlprPtr
)
{
  uint32          Timeout;
  uint32          FlashMarpBackup;
  volatile uint32 Dummy = 0U;

  /* Disable trap generation on uncorrectable PFLASH ECC errors: */
  FlashMarpBackup = CbabHlprPtr->FlashMarpPtr->U;
  CbabHlprPtr->FlashMarpPtr->B.TRAPDIS = 1U;

  /* Get current alarm status before access */
  CbabHlprPtr->SmuAlmBefore = CbabHlprPtr->SmuAlm->U;
  /* To remove warning in GNU */
  UNUSED_PARAMETER(Dummy)
  /* Enable tracking of single / double bit errors: */
  CbabHlprPtr->FlashCbabCfgPtr->B.SEL = (uint8)CbabHlprPtr->ErrorType;
  CbabHlprPtr->FlashCbabCfgPtr->B.DIS = 0U;

  /* Enforce completion of FLASH_CBAB_CFG write: */
  DSYNC();

  /* Read access to bit error pattern: */
  Dummy = CbabHlprPtr->DataAddr->Data[0U];

  /* Give a short delay: */
  Timeout = PFM_ERROR_FIFO_TIMEOUT;
  while (Timeout > 0U)
  {
    Timeout--;
    if (1U == CbabHlprPtr->FlashCbabTopPtr->B.VLD)
    {
      break;
    } 
  } /* while (Timeout > 0U) */
     /* Store CBAB_TOP value: */
    CbabHlprPtr->CbabTopAfter.U = CbabHlprPtr->FlashCbabTopPtr->U;
    
    /* Disable error tracking: */
    CbabHlprPtr->FlashCbabCfgPtr->B.DIS = 1U;
    
    /* Remove top most FIFO entry: */
    CbabHlprPtr->FlashCbabTopPtr->B.CLR = 1U;
    
    /* Restore FLASH0_MARP: */
    CbabHlprPtr->FlashMarpPtr->U = FlashMarpBackup;
    
    /* Send an ALARM CLEAR command to the SMU Control Interface   */
    CbabHlprPtr->SmuCmd->U = 5U;
    
    /* Clear all SMU Group 2, Alarms */
    CbabHlprPtr->SmuAlm->U = (unsigned_int)PFM_SMU_ALARM_MASK;
    
    /* Ensure SFR values have been written before continuing code execution
     * from PFLASH:
     */
    DSYNC();
      
} /* PflashMonTst_lCbabHelper */
#ifdef __TASKING__
PRAGMA_ALL(OPTIMIZE_RESTORE)
#endif

#ifdef __TASKING__
PRAGMA_ALL(OPTIMIZE_0)
#endif
/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static void PflashMonTst_lUbabHelper                    **
**                    (                                                       **
**                      PflashMonTst_UbabHlprType* UbabHlprPtr                **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters(in)   : UbabHlprPtr - Pointer to test data structure for        **
**                                  data exchange between the test function   **
**                                  in PFLASH and the helper routine in SRAM  **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This helper routine enables UBAB error tracking, reads  **
**                    an uncorrectable bit error pattern from PFLASH and      **
**                    stores the expected new UBAB FIFO entry to a given data **
**                    structure.                                              **
**                                                                            **
**                    ATTENTION:                                              **
**                    This function must be executed from SRAM. It must be    **
**                    checked, that no unintended access to PFLASH is made,   **
**                    e.g. for constant loading.                              **
**                                                                            **
*******************************************************************************/
static void PflashMonTst_lUbabHelper
(
  PflashMonTst_UbabHlprType* UbabHlprPtr
)
{
  uint32          Timeout;
  uint32          FlashMarpBackup;
  volatile uint32 Dummy = 0U;

  /* Disable trap generation on uncorrectable PFLASH ECC errors: */
  FlashMarpBackup = UbabHlprPtr->FlashMarpPtr->U;
  UbabHlprPtr->FlashMarpPtr->B.TRAPDIS = 1U;

  /* Get current alarm status before access */
  UbabHlprPtr->SmuAlmBefore = UbabHlprPtr->SmuAlm->U;
  /* To remove warning in GNU */
  UNUSED_PARAMETER(Dummy)
  /* Enable tracking of uncorrectable bit errors: */
  UbabHlprPtr->FlashUbabCfgPtr->B.SEL = (uint8)PFM_MULTI_BIT_ERROR;
  UbabHlprPtr->FlashUbabCfgPtr->B.DIS = 0U;

  /* Enforce completion of FLASH_UBAB_CFG write: */
  DSYNC();

  /* Read access to bit error pattern: */
  Dummy = UbabHlprPtr->DataAddr->Data[0U];

  /* Give a short delay: */
  Timeout = PFM_ERROR_FIFO_TIMEOUT;
  while (Timeout > 0U)
  {
    Timeout--;
    if (1U == UbabHlprPtr->FlashUbabTopPtr->B.VLD)
    {
      break;
    } /* if (1U == UbabHlprPtr->FlashUbabTopPtr->B.VLD) */
  } /* while (Timeout > 0U) */

  /* Store UBAB_TOP value: */
  UbabHlprPtr->UbabTopAfter.U = UbabHlprPtr->FlashUbabTopPtr->U;

  /* Disable error tracking: */
  UbabHlprPtr->FlashUbabCfgPtr->B.DIS = 1U;

  /* Remove top most FIFO entry: */
  UbabHlprPtr->FlashUbabTopPtr->B.CLR = 1U;

  /* Restore FLASH0_MARP: */
  UbabHlprPtr->FlashMarpPtr->U = FlashMarpBackup;

  /* Send an ALARM CLEAR command to the SMU Control Interface   */
  UbabHlprPtr->SmuCmd->U = 5U;

  /* Clear all SMU Group 2, Alarms */
  

   UbabHlprPtr->SmuAlm->U = (unsigned_int)PFM_SMU_ALARM_MASK;

  /* Ensure SFR values have been written before continuing code execution
   * from PFLASH:
   */
  DSYNC();
} /* PflashMonTst_lUbabHelper */
#ifdef __TASKING__
PRAGMA_ALL(OPTIMIZE_RESTORE)
#endif
#define IFX_PFLASHMONTST_STOP_SEC_RAM_CODE_ASIL_B
#include "Ifx_MemMap.h"

#define IFX_PFLASHMON_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : Sl_TstRsltType PflashMonTst_PflashMonTst                **
**                    (                                                       **
**                      const Sl_ParamSetIndex ParamSetIndex,                 **
**                      const uint8 TstSeed,                                  **
**                      uint32* const TstSignature                            **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters(in)   : ParamSetIndex - Identifies the parameter set to be used **
**                                    for test execution                      **
**                    TstSeed - Seed to be used for generating the signature  **
**                                                                            **
** Parameters (out) : TstSignature - Test signature generated by the test     **
**                                                                            **
** Return value     : PFLASHMON_SUCCESS - Test succeeded                      **
**                    PFLASHMON_NOTEXECUTED - Test unexpectedly aborted       **
**                    PFLASHMON_INVPARAMERR - Invalid ParamSetIndex value     **
**                    PFLASHMON_CONFIGERR - Invalid test configuration        **
**                    PFLASHMON_SMU_GETALMACTIONERR - Smu_GetAlarmAction      **
**                                                    failed                  **
**                    PFLASHMON_SMU_SETALMACTIONERR - Smu_SetAlarmAction      **
**                                                    failed                  **
**                    PFLASHMON_SBE_PFx - Single bit error tracking test      **
**                                        failed for PFLASH bank x            **
**                    PFLASHMON_DBE_PFx - Double bit error tracking test      **
**                                        failed for PFLASH bank x            **
**                    PFLASHMON_MBE_PFx - Uncorrectable bit error tracking    **
**                                        test failed for PFLASH bank x       **
**                    PFLASHMON_DATACONSISTENCY - Internal data was corrupted **
**                                                or invalid PFLASH bank      **
**                                                                            **
** Description      : Performs a latent fault metric test of the PFLASH       **
**                    monitor, i.e. correct tracking of correctable and       **
**                    uncorrectable errors to the FLASH_CBAB / FLASH_UBAB     **
**                    registers.                                              **
** Note(s)          : Bit errors in the PFLASH test patterns need to be       **
**                    created one-time before this API is executed. The bit   **
**                    errors could be created by using the                    **
**                    Sl_ErrorPatternProg support API or by any other custom  **
**                    error programming code.                                 **
**                    This test uses the PFLASH test patterns of the          **
**                    PmuEccEdcTst. Therefore this test has some dependencies **
**                    on the PmuEccEdcTst and can also only test error        **
**                    tracking for FLASH banks that are also tested by the    **
**                    PmuEccEdcTst.                                           **
**                                                                            **
*******************************************************************************/
Sl_TstRsltType PflashMonTst_PflashMonTst
(
  const Sl_ParamSetType ParamSetIndex,
  const uint8 TstSeed,
  uint32* const TstSignature
)
{
  Sl_TstRsltType              Result = PFLASHMON_NOTEXECUTED;
  Sl_TstRsltType              ResultTmp;
  PflashMonTst_BackupDataType BackupData;
  PflashMonTst_TestDataType   TestData;
  uint32                      i = 0U;

  /* Initialize Test Signature */
  *TstSignature = (uint32)CRC32((uint32)TEST_ID_PFLASH_MON_TST,
                                (uint32)TstSeed);

  /* Clear list of cleared CBAB / UBAB FIFO entries: */
  PflashMonTst_lClearClearedErrList();

  /* Clear list of unexpected PMU ECC error SMU alarms: */
  PflashMonTst_lClearUnexpAlmList();

  /* Check test configuration: */
  ResultTmp = PflashMonTst_lCheckConfig(ParamSetIndex);
  if (PFLASHMON_SUCCESS != ResultTmp)
  {
    Result = ResultTmp;
  } /* if (PFLASHMON_SUCCESS != ResultTmp) */
  else
  {
    
    /* Perform test initialization: */
    ResultTmp = PflashMonTst_lInit(&BackupData,
                                   &PflashMonTst_ConfigRoot[ParamSetIndex]);
    if (PFLASHMON_SUCCESS != ResultTmp)
    {
      Result = ResultTmp;
    }
    else
    {
      /* Initialize general test data: */
      TestData.Signature = TstSignature;
      TestData.FlashCmd  = (volatile uint32*)
                            (PFM_PMU0_DF0_BASE + PFM_FLS_CMD_ADDR);

      /* Test all configured flash banks: */
#if ((CHIP_ID == 26U) || (CHIP_ID == 27U) || (CHIP_ID == 29U))
      for (i = 0U; i < PFLASH_MON_TST_MAX_FLASHBANKS; i++)
#endif      
      {
        /* Check if test is enabled for current PFLASH bank: */
        if (0U != PflashMonTst_ConfigRoot[ParamSetIndex].BankEnable[i])
        {
          /* Initialize PFLASH bank specific test data: */
          TestData.FlashBank        = i;
          TestData.FlashCbabCfgPtr  = &MODULE_FLASH0.CBAB[i].CFG;
          TestData.FlashCbabTopPtr  = &MODULE_FLASH0.CBAB[i].TOP;
#ifdef PFLASH_FIFO_BUFFERFULL_TEST_ENABLE
          TestData.FlashCbabStatusPtr = &MODULE_FLASH0.CBAB[i].STAT;
#endif
          TestData.FlashUbabCfgPtr  = &MODULE_FLASH0.UBAB[i].CFG;
          TestData.FlashUbabTopPtr  = &MODULE_FLASH0.UBAB[i].TOP;
          TestData.FlashMarpPtr     = &FLASH0_MARP;

          /* Bit Or to enforce usage of test patterns in non-cachable segment:
           */
          TestData.FlashPattern = (PmuEccEdcTst_TestPatternType*)
              ((uint32)(PmuEccEdcTst_TestPattern[i]) | (uint32)0x20000000U);

          /* Actual test of current PFLASH bank: */
          ResultTmp = PflashMonTst_lTestFlsBank(&TestData);            
          if (PFLASHMON_SUCCESS != ResultTmp)
          {
            Result = ResultTmp;
#if ((CHIP_ID == 26U) || (CHIP_ID == 27U) || (CHIP_ID == 29U))
            break;
#endif 
          } /* if (PFLASHMON_SUCCESS != ResultTmp) */
         
        } /* if (0U != PflashMonTst_ConfigRoot[ParamSetIndex].BankEnable[i]) */
      } /* for (i = 0U; i < PFLASH_MON_TST_MAX_FLASHBANKS; i++) */

      /* Clear Flash status flags: */
      *TestData.FlashCmd = PFM_FSI_CMD_FA;
    }

    /* Test restoration */
    ResultTmp = PflashMonTst_lRestore(&BackupData);
    if (PFLASHMON_SUCCESS != ResultTmp)
    {
      Result = ResultTmp;
    } /* if (PFLASHMON_SUCCESS != ResultTmp) */
  } /* if (PFLASHMON_SUCCESS == ResultTmp) */

  /* Update test result: */
  if (PFLASHMON_NOTEXECUTED == Result)
  {
    Result = PFLASHMON_SUCCESS;
  } /* if (PFLASHMON_NOTEXECUTED == Result) */

  /* Add final result to Test Signature */
  *TstSignature = (uint32)CRC32(*TstSignature, Result);

  return Result;
} /* PflashMonTst_PflashMonTst */


/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : PflashMonTst_ClearedErrorType*                          **
**                    PflashMonTst_GetClearedErrListPtr                       **
**                    (                                                       **
**                      void                                                  **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : PflashMonTst_ClearedErrorType* - Pointer to list of     **
**                    cleared CBAB / UBAB registers or NULL_PTR if the        **
**                    cleared error list data was corrupted (i.e. its CRC is  **
**                    invalid)                                                **
**                                                                            **
** Description      : Returns a pointer to a list that contains the values of **
**                    all FLASH_CBAB_TOP and FLASH_UBAB_TOP entries that have **
**                    been cleared before execution of the test.              **
**                    Valid entries can be identified by checking the VLD     **
**                    flag of all entries of the returned list.               **
**                    This list can be used by the application for own        **
**                    diagnostic purpose.                                     **
**                                                                            **
*******************************************************************************/
PflashMonTst_ClearedErrorType* PflashMonTst_GetClearedErrListPtr
(
  void
)
{
  PflashMonTst_ClearedErrorType*  Result = NULL_PTR;

  /* Check if cleared error list CRC is valid: */
  if (PflashMonTst_lCalcClearedErrCrc() == PflashMonTst_ClearedErr.Crc32)
  {
    Result = &PflashMonTst_ClearedErr;
  } /* if (PflashMonTst_lCalcClearedErrorCrc() ==
           PflashMonTst_ClearedErr.Crc32) */

  return Result;
} /* PflashMonTst_GetClearedErrListPtr */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : PflashMonTst_UnexpAlarmType*                            **
**                    PflashMonTst_GetUnexpEccAlmListPtr                      **
**                    (                                                       **
**                      void                                                  **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : PflashMonTst_UnexpAlarmType* - Pointer to list of       **
**                    of unexpected and cleared SMU alarms or NULL_PTR if the **
**                    unexpected alarm list data was corrupted (i.e. its CRC  **
**                    is invalid)                                             **
**                                                                            **
** Description      : Returns a pointer to a list that contains the number of **
**                    unexpected PMU ECC single and double bit error          **
**                    correction and uncorrectable error SMU alarms that were **
**                    already set before or raised during test execution.     **
**                    This list can be used by the application for own        **
**                    diagnostic purpose.                                     **
**                                                                            **
*******************************************************************************/
PflashMonTst_UnexpAlarmType* PflashMonTst_GetUnexpEccAlmListPtr
(
  void
)
{
  PflashMonTst_UnexpAlarmType*  Result = NULL_PTR;

  /* Check if unexpected alarm list CRC is valid: */
  if (PflashMonTst_lCalcUnexpAlmCrc() == PflashMonTst_UnexpAlm.Crc32)
  {
    Result = &PflashMonTst_UnexpAlm;
  } /* if (PflashMonTst_lCalcUnexpAlmCrc() == PflashMonTst_UnexpAlm.Crc32) */

  return Result;
} /* PflashMonTst_GetUnexpEccAlmListPtr */


/******************************************************************************/
/* LOCAL (FILE-SCOPE) IMPLEMENTATION                                          */
/******************************************************************************/

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static Sl_TstRsltType PflashMonTst_lCheckConfig         **
**                    (                                                       **
**                      const Sl_ParamSetType ParamSetIndex                   **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : ParamSetIndex - Configuration parameter set index       **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : PFLASHMON_SUCCESS - Configuration check succeeded       **
**                    PFLASHMON_INVPARAMERR - ParamSetIndex parameter is      **
**                                            invalid                         **
**                    PFLASHMON_CONFIGERR - Invalid test configuration        **
**                                                                            **
** Description      : This function checks the test configuration for         **
**                    validness.                                              **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType PflashMonTst_lCheckConfig
(
  const Sl_ParamSetType ParamSetIndex
)
{
  Sl_TstRsltType  Result = PFLASHMON_NOTEXECUTED;
  uint32          i = 0U;

  /* Check valid range of ParamSetIndex: */
  if (ParamSetIndex >= PFLASH_MON_TST_CFG_PARAM_COUNT)
  {
    Result = PFLASHMON_INVPARAMERR;
  } /* if (ParamSetIndex >= PFLASH_MON_CFG_PARAM_COUNT) */
  else
  {
    /* Loop through each PFLASH bank: */
#if ((CHIP_ID == 26U) || (CHIP_ID == 27U) || (CHIP_ID == 29U))
    for (i = 0U; i < PFLASH_MON_TST_MAX_FLASHBANKS; i++)
#endif
    {
      /* Testing of PFLASH bank x is only allowed if there is a test pattern of
       * the PmuEccEdcTst for this PFLASH bank:
       */
      if ((0U != PflashMonTst_ConfigRoot[ParamSetIndex].BankEnable[i]) &&
          (NULL_PTR == PmuEccEdcTst_TestPattern[i]))
      {
        Result = PFLASHMON_CONFIGERR;
      } /* if ((0U != PflashMonTst_ConfigRoot[ParamSetIndex].BankEnable[i]) &&
               (NULL_PTR == PmuEccEdcTst_TestPattern[i])) */
    } /* for (i = 0U; i < PFLASH_MON_TST_MAX_FLASHBANKS; i++) */

    /* Update result: */
    if (PFLASHMON_NOTEXECUTED == Result)
    {
      Result = PFLASHMON_SUCCESS;
    } /* if (PFLASHMON_NOTEXECUTED == Result) */
  } /* if (ParamSetIndex < PFLASH_MON_CFG_PARAM_COUNT) */

  return Result;
} /* PflashMonTst_lCheckConfig */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static Sl_TstRsltType PflashMonTst_lInit                **
**                    (                                                       **
**                      PflashMonTst_BackupDataType* const BackupData,        **
**                      PflashMonTst_ConfigType* const Config                 **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters(in)   : Config - Pointer to current test configuration          **
**                                                                            **
** Parameters (out) : BackupData - Pointer to structure receiving all backup  **
**                                 values to be restored after test execution **
**                                                                            **
** Return value     : PFLASHMON_SUCCESS - Test initialization succeeded       **
**                    PFLASHMON_SMU_GETALMACTIONERR - Smu_GetAlarmAction      **
**                                                    failed                  **
**                    PFLASHMON_SMU_SETALMACTIONERR - Smu_SetAlarmAction      **
**                                                    failed                  **
**                    PFLASHMON_NOTEXECUTED - Program flow consistency error  **
**                                                                            **
** Description      : This function backs up SFRs modified by the test,       **
**                    disables CBAB / UBAB error tracking and stores and      **
**                    clears the CBAB / UBAB FIFOs.                           **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType PflashMonTst_lInit
(
  PflashMonTst_BackupDataType* const BackupData,
  const PflashMonTst_ConfigType* const Config
)
{
  Sl_TstRsltType    Result = PFLASHMON_NOTEXECUTED;
  Std_ReturnType    SmuResult1;
  Std_ReturnType    SmuResult2;
  Std_ReturnType    SmuResult3;
#ifdef PFLASH_FIFO_BUFFERFULL_TEST_ENABLE
  Std_ReturnType    SmuResult4;
#endif
  Smu_FSPActionType FspActionDummy;
  uint32 baddress,eaddress;

  baddress = (uint32)LOC_START_PflashMon_EccEdc_PFLASHCODE;
  eaddress = (uint32)LOC_END_PflashMon_EccEdc_PFLASHCODE;
  
  /* Invalidate 'backup data valid' indicator: */
  BackupData->Valid = (boolean)FALSE;
  
    /* Calculate Crc of functions in PFlash that have been copied to RAM*/
  PflashMonTst_PFlashFnCrc32 = PmuEccEdcTst_CalculateCrc32(LOC_START_PflashMon_EccEdc_PFLASHCODE,
    (eaddress-baddress));

  /* Backup CBAB configuration: */
  BackupData->CbabCfgBackup[0U] = FLASH0_CBABCFG0.U;
#if (PFLASH_MON_TST_MAX_FLASHBANKS > 1U)
  BackupData->CbabCfgBackup[1U] = FLASH0_CBABCFG1.U;
#if (PFLASH_MON_TST_MAX_FLASHBANKS > 2U)
  BackupData->CbabCfgBackup[2U] = FLASH0_CBABCFG2.U;
#if (PFLASH_MON_TST_MAX_FLASHBANKS > 3U)
  BackupData->CbabCfgBackup[3U] = FLASH0_CBABCFG3.U;
#endif /* PFLASH_MON_TST_MAX_FLASHBANKS > 3U */
#endif /* PFLASH_MON_TST_MAX_FLASHBANKS > 2U */
#endif /* PFLASH_MON_TST_MAX_FLASHBANKS > 1U */

  /* Backup UBAB configuration: */
  BackupData->UbabCfgBackup[0U] = FLASH0_UBABCFG0.U;
#if (PFLASH_MON_TST_MAX_FLASHBANKS > 1U)
  BackupData->UbabCfgBackup[1U] = FLASH0_UBABCFG1.U;
#if (PFLASH_MON_TST_MAX_FLASHBANKS > 2U)
  BackupData->UbabCfgBackup[2U] = FLASH0_UBABCFG2.U;
#if (PFLASH_MON_TST_MAX_FLASHBANKS > 3U)
  BackupData->UbabCfgBackup[3U] = FLASH0_UBABCFG3.U;
#endif /* PFLASH_MON_TST_MAX_FLASHBANKS > 3U */
#endif /* PFLASH_MON_TST_MAX_FLASHBANKS > 2U */
#endif /* PFLASH_MON_TST_MAX_FLASHBANKS > 1U */

  /* Backup PMU ECC error SMU alarm actions: */
  SmuResult1 = Smu_GetAlarmAction(SMU_ALARM_GROUP2,
                                  SMU_ALARM_2,
                                  &(BackupData->AlmActionSbe),
                                  &FspActionDummy);
  SmuResult2 = Smu_GetAlarmAction(SMU_ALARM_GROUP2,
                                  SMU_ALARM_3,
                                  &(BackupData->AlmActionDbe),
                                  &FspActionDummy);
  SmuResult3 = Smu_GetAlarmAction(SMU_ALARM_GROUP2,
                                  SMU_ALARM_4,
                                  &(BackupData->AlmActionMbe),
                                  &FspActionDummy);
#ifdef PFLASH_FIFO_BUFFERFULL_TEST_ENABLE								  
  SmuResult4 = Smu_GetAlarmAction(SMU_ALARM_GROUP2,
                                  SMU_ALARM_6,
                                  &(BackupData->AlmActionBufferFull),
                                  &FspActionDummy);
  /* Check result of SMU alarm action backup: */
  if ((E_OK != SmuResult1) || (E_OK != SmuResult2) || (E_OK != SmuResult3) ||
      (E_OK != SmuResult4))
#else
  if ((E_OK != SmuResult1) || (E_OK != SmuResult2) || (E_OK != SmuResult3))
#endif
  {
    Result = PFLASHMON_SMU_GETALMACTIONERR;

    /* Update backup data CRC to avoid data consistency error in restore
     * function:
     */
    BackupData->Crc32 = PflashMonTst_lCalcBackupCrc(BackupData);
  } /* if ((E_OK != SmuResult1) || (E_OK != SmuResult2) ||
           (E_OK != SmuResult3)) */
  else
  {
    /* Mark backup data as valid: */
    BackupData->Valid = (boolean)TRUE;

    /* Update backup data CRC: */
    BackupData->Crc32 = PflashMonTst_lCalcBackupCrc(BackupData);

    /* Set PMU ECC error SMU alarm actions to 'None': */
    SmuResult1 = Smu_SetAlarmAction(SMU_ALARM_GROUP2,
                                    SMU_ALARM_2,
                                    SMU_ALARM_ACTION_NONE);
    SmuResult2 = Smu_SetAlarmAction(SMU_ALARM_GROUP2,
                                    SMU_ALARM_3,
                                    SMU_ALARM_ACTION_NONE);
    SmuResult3 = Smu_SetAlarmAction(SMU_ALARM_GROUP2,
                                    SMU_ALARM_4,
                                    SMU_ALARM_ACTION_NONE);
#ifdef PFLASH_FIFO_BUFFERFULL_TEST_ENABLE								
    SmuResult4 = Smu_SetAlarmAction(SMU_ALARM_GROUP2,
                                    SMU_ALARM_6,
                                    SMU_ALARM_ACTION_NONE);
    /* Check result of SMU alarm action setup: */
    if ((E_OK != SmuResult1) || (E_OK != SmuResult2) || (E_OK != SmuResult3)
        || (E_OK != SmuResult4))
#else
	if ((E_OK != SmuResult1) || (E_OK != SmuResult2) || (E_OK != SmuResult3))
#endif	
    {
      Result = PFLASHMON_SMU_SETALMACTIONERR;
    } /* if ((E_OK != SmuResult1) || (E_OK != SmuResult2) ||
             (E_OK != SmuResult3)) || (E_OK != SmuResult4)*/
    else
    {
      /* Disable CBAB / UBAB error tracking:
       * Note: Error tracking is disabled during almost the whole test to avoid
       *       interference of unintended ECC errors in the test code. It is
       *       enabled only for short periods of time, while the test is
       *       executing from SRAM.
       */
      Mcal_ResetENDINIT();
      FLASH0_CBABCFG0.B.DIS = 1U;
#if (PFLASH_MON_TST_MAX_FLASHBANKS > 1U)
      FLASH0_CBABCFG1.B.DIS = 1U;
#if (PFLASH_MON_TST_MAX_FLASHBANKS > 2U)
      FLASH0_CBABCFG2.B.DIS = 1U;
#if (PFLASH_MON_TST_MAX_FLASHBANKS > 3U)
      FLASH0_CBABCFG3.B.DIS = 1U;
#endif /* PFLASH_MON_TST_MAX_FLASHBANKS > 3U */
#endif /* PFLASH_MON_TST_MAX_FLASHBANKS > 2U */
#endif /* PFLASH_MON_TST_MAX_FLASHBANKS > 1U */
      FLASH0_UBABCFG0.B.DIS = 1U;
#if (PFLASH_MON_TST_MAX_FLASHBANKS > 1U)
      FLASH0_UBABCFG1.B.DIS = 1U;
#if (PFLASH_MON_TST_MAX_FLASHBANKS > 2U)
      FLASH0_UBABCFG2.B.DIS = 1U;
#if (PFLASH_MON_TST_MAX_FLASHBANKS > 3U)
      FLASH0_UBABCFG3.B.DIS = 1U;
#endif /* PFLASH_MON_TST_MAX_FLASHBANKS > 3U */
#endif /* PFLASH_MON_TST_MAX_FLASHBANKS > 2U */
#endif /* PFLASH_MON_TST_MAX_FLASHBANKS > 1U */
      Mcal_SetENDINIT();

      /* Copy CBAB / UBAB FIFO entries to the list of cleared errors and clear
       * the FIFOs:
       */
      PflashMonTst_lClearErrorFifos(Config);

      Result = PFLASHMON_SUCCESS;
    } /* if ((E_OK != SmuResult1) || (E_OK != SmuResult2) ||
             (E_OK != SmuResult3)) || (E_OK != SmuResult4)*/
  } /* if ((E_OK != SmuResult1) || (E_OK != SmuResult2) ||
           (E_OK != SmuResult3)) || (E_OK != SmuResult4)*/

  return Result;
} /* PflashMonTst_lInit */



/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static Sl_TstRsltType PflashMonTst_lRestore             **
**                    (                                                       **
**                      const PflashMonTst_BackupDataType* const BackupData   **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters(in)   : BackupData - Pointer to structure holding all backup    **
**                                 values to be restored                      **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : PFLASHMON_SUCCESS - Test restoration succeeded          **
**                    PFLASHMON_DATACONSISTENCY - BackupData structure was    **
**                                                corrupted                   **
**                    PFLASHMON_NOTEXECUTED - Program flow consistency error  **
**                                                                            **
** Description      : This function restores all SFRs modified by the test.   **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType PflashMonTst_lRestore
(
  const PflashMonTst_BackupDataType* const BackupData
)
{
  Sl_TstRsltType  Result = PFLASHMON_NOTEXECUTED;
  uint32          CrcExpected;
  Std_ReturnType  SmuResult1;
  Std_ReturnType  SmuResult2;
  Std_ReturnType  SmuResult3;
#ifdef PFLASH_FIFO_BUFFERFULL_TEST_ENABLE
  Std_ReturnType  SmuResult4;
#endif
  /* Check backup data consistency: */
  CrcExpected = PflashMonTst_lCalcBackupCrc(BackupData);
  if (CrcExpected != BackupData->Crc32)
  {
    Result = PFLASHMON_DATACONSISTENCY;
  } /* if (CrcExpected != BackupData->Crc32) */
  else
  {
    /* Check if backup values are valid: */
    if ((boolean)TRUE == BackupData->Valid)
    {
      /* Restore CBAB configuration: */
      Mcal_ResetENDINIT();
      FLASH0_CBABCFG0.U = BackupData->CbabCfgBackup[0U];
#if (PFLASH_MON_TST_MAX_FLASHBANKS > 1U)
      FLASH0_CBABCFG1.U = BackupData->CbabCfgBackup[1U];
#if (PFLASH_MON_TST_MAX_FLASHBANKS > 2U)
      FLASH0_CBABCFG2.U = BackupData->CbabCfgBackup[2U];
#if (PFLASH_MON_TST_MAX_FLASHBANKS > 3U)
      FLASH0_CBABCFG3.U = BackupData->CbabCfgBackup[3U];
#endif /* PFLASH_MON_TST_MAX_FLASHBANKS > 3U */
#endif /* PFLASH_MON_TST_MAX_FLASHBANKS > 2U */
#endif /* PFLASH_MON_TST_MAX_FLASHBANKS > 1U */

      /* Restore UBAB configuration: */
      FLASH0_UBABCFG0.U = BackupData->UbabCfgBackup[0U];
#if (PFLASH_MON_TST_MAX_FLASHBANKS > 1U)
      FLASH0_UBABCFG1.U = BackupData->UbabCfgBackup[1U];
#if (PFLASH_MON_TST_MAX_FLASHBANKS > 2U)
      FLASH0_UBABCFG2.U = BackupData->UbabCfgBackup[2U];
#if (PFLASH_MON_TST_MAX_FLASHBANKS > 3U)
      FLASH0_UBABCFG3.U = BackupData->UbabCfgBackup[3U];
#endif /* PFLASH_MON_TST_MAX_FLASHBANKS > 3U */
#endif /* PFLASH_MON_TST_MAX_FLASHBANKS > 2U */
#endif /* PFLASH_MON_TST_MAX_FLASHBANKS > 1U */
      Mcal_SetENDINIT();

      /* Restore PMU ECC error SMU alarm actions: */
      SmuResult1 = Smu_SetAlarmAction(SMU_ALARM_GROUP2,
                                      SMU_ALARM_2,
                                      BackupData->AlmActionSbe);
      SmuResult2 = Smu_SetAlarmAction(SMU_ALARM_GROUP2,
                                      SMU_ALARM_3,
                                      BackupData->AlmActionDbe);
      SmuResult3 = Smu_SetAlarmAction(SMU_ALARM_GROUP2,
                                      SMU_ALARM_4,
                                      BackupData->AlmActionMbe);
#ifdef PFLASH_FIFO_BUFFERFULL_TEST_ENABLE
      SmuResult4 = Smu_SetAlarmAction(SMU_ALARM_GROUP2,
                                      SMU_ALARM_6,
                                      BackupData->AlmActionBufferFull);
      /* Check result of SMU alarm action restoration: */
      if ((E_OK != SmuResult1) || (E_OK != SmuResult2) || (E_OK != SmuResult3)
        || (E_OK != SmuResult4))
#else
	  if ((E_OK != SmuResult1) || (E_OK != SmuResult2) || (E_OK != SmuResult3))
#endif	
      {
        Result = PFLASHMON_SMU_SETALMACTIONERR;
      } /* if ((E_OK != SmuResult1) || (E_OK != SmuResult2) ||
               (E_OK != SmuResult3)) */
      else
      {
        Result = PFLASHMON_SUCCESS;
      } /* if ((E_OK == SmuResult1) && (E_OK == SmuResult2) &&
               (E_OK == SmuResult3)) */
    } /* if ((boolean)TRUE == BackupData->Valid) */
    else
    {
      /* No values were changed if BackupData->Valid is false; therefore
       * nothing has to be restored:
       */
      Result = PFLASHMON_SUCCESS;
    } /* if ((boolean)TRUE != BackupData->Valid) */
  } /* if (CrcExpected == BackupData->Crc32) */

  return Result;
} /* PflashMonTst_lRestore */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static Sl_TstRsltType PflashMonTst_lTestFlsBank         **
**                    (                                                       **
**                      const PflashMonTst_TestDataType* TestData             **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters(in)   : TestData - Pointer to test data structure for PFLASH    **
**                               bank to be tested                            **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : PFLASHMON_SUCCESS - Testing given PFLASH bank succeeded **
**                    PFLASHMON_SBE_PFx - Single bit error tracking test      **
**                                        failed for PFLASH bank x            **
**                    PFLASHMON_DBE_PFx - Double bit error tracking test      **
**                                        failed for PFLASH bank x            **
**                    PFLASHMON_MBE_PFx - Uncorrectable bit error tracking    **
**                                        test failed for PFLASH bank x       **
**                    PFLASHMON_DATACONSISTENCY - Internal data was corrupted **
**                                                or invalid PFLASH bank      **
**                    PFLASHMON_NOTEXECUTED - Program flow consistency error  **
**                                                                            **
** Description      : This function executes the PFLASH monitor test for a    **
**                    given PFLASH bank. The PFLASH bank to be tested is      **
**                    implicitly encoded in the TestData parameter.           **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType PflashMonTst_lTestFlsBank
(
  const PflashMonTst_TestDataType* TestData
)
{
  Sl_TstRsltType  Result = PFLASHMON_NOTEXECUTED;
  Sl_TstRsltType  ResultTmp;

  /* Check if CBAB address buffer full alarm is raised  */
#ifdef PFLASH_FIFO_BUFFERFULL_TEST_ENABLE
  ResultTmp = PflashMonTst_lTestFifoBufferFull(TestData);
  if (PFLASHMON_SUCCESS == ResultTmp)
  {
#endif
    /* Check if single bit errors are tracked correctly: */
    ResultTmp = PflashMonTst_lTestSbeTracking(TestData);

    if (PFLASHMON_SUCCESS == ResultTmp)
    {
      /* Check if double errors are tracked correctly: */
      ResultTmp = PflashMonTst_lTestDbeTracking(TestData);
      
      if (PFLASHMON_SUCCESS == ResultTmp)
      {
        /* Check if uncorrectable errors are tracked correctly: */
        Result = PflashMonTst_lTestMbeTracking(TestData);
      }
      else
      {
        Result = ResultTmp;       
      }
    } /* if (PFLASHMON_SUCCESS == Result) */
    else
    {
      Result = ResultTmp;
    } /* if (PFLASHMON_SUCCESS != Result) */
#ifdef PFLASH_FIFO_BUFFERFULL_TEST_ENABLE  
  } /* if (PFLASHMON_SUCCESS == Result)*/
  else
  {
    Result = ResultTmp;
  } /* if (PFLASHMON_SUCCESS != Result) */
#endif
  return Result;
} /* PflashMonTst_lTestFlsBank */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static Sl_TstRsltType PflashMonTst_lTestSbeTracking     **
**                    (                                                       **
**                      const PflashMonTst_TestDataType* TestData             **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters(in)   : TestData - Pointer to test data structure for PFLASH    **
**                               bank to be tested                            **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : PFLASHMON_SUCCESS - Testing given PFLASH bank succeeded **
**                    PFLASHMON_SBE_PFx - Single bit error tracking test      **
**                                        failed for PFLASH bank x            **
**                    PFLASHMON_DATACONSISTENCY - Internal data was corrupted **
**                                                or invalid PFLASH bank      **
**                    PFLASHMON_NOTEXECUTED - Program flow consistency error  **
**                                                                            **
** Description      : This function tests correct tracking of single bit      **
**                    errors to the CBAB FIFO for a single PFLASH bank.       **
**                    The error tracking is tested with all four redundant    **
**                    single bit error patterns in PFLASH, until the test     **
**                    returns the expected result. An error is returned if    **
**                    none of the four patterns delivers the expected result. **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType PflashMonTst_lTestSbeTracking
(
  const PflashMonTst_TestDataType* TestData
)
{
  uint32                    i;
  uint32                    TrackedAddress;
  uint32                    PatternAddress;
  Sl_TstRsltType            Result;
  Sl_TstRsltType            ResultTmp;
  PflashMonTst_CbabHlprType CbabHlpr;

  /* Initialize result to appropriate single bit error code for PFLASH bank
   * under test:
   */
  Result = PflashMonTst_lGetSbeErrorCode(TestData->FlashBank);

  /* Initialize test data for helper routine: */
  CbabHlpr.FlashCbabCfgPtr  = TestData->FlashCbabCfgPtr;
  CbabHlpr.FlashCbabTopPtr  = TestData->FlashCbabTopPtr;
  CbabHlpr.FlashMarpPtr     = TestData->FlashMarpPtr;
  CbabHlpr.SmuAlm           = &SMU_AG2;
  CbabHlpr.SmuCmd           = &SMU_CMD;
  CbabHlpr.CbabTopAfter.U   = 0U;
  CbabHlpr.SmuAlmBefore     = 0U;
  CbabHlpr.ErrorType        = PFM_SINGLE_BIT_ERROR;
  CbabHlpr.DataAddr         = 0U;

  /* Check if unexpected alarm structure was corrupted: */
  if (PflashMonTst_lCalcUnexpAlmCrc() != PflashMonTst_UnexpAlm.Crc32)
  {
    Result = PFLASHMON_DATACONSISTENCY;
  } /* if (PflashMonTst_lCalcUnexpAlmCrc() != PflashMonTst_UnexpAlm.Crc32) */
  else
  {
    /* Calculate and compare Crc of functions in RAM that 
     were copied from PFlash at startup*/   
    ResultTmp = PflashMonTst_lRamCalculateandVerifyCrc32();
    if (PFLASHMON_SUCCESS != ResultTmp)
    {
      Result = ResultTmp;
    } /* if (PFLASHMON_SUCCESS != ResultTmp) */
    else
    {
      /* Loop through each of the four redundant test patterns in PFLASH: */
      for (i = 0U;
           ((PFLASHMON_DATACONSISTENCY != Result) &&
		   (i < PMUT_TEST_PATTERN_COUNT) && (PFLASHMON_SUCCESS != Result));
           i++)
      {
        /* Setup test pattern address to current single bit error pattern: */
        CbabHlpr.DataAddr =
            &(TestData->FlashPattern->Set[i].Pattern[PFM_SBE_PTRN_IDX]);

        /* Execute helper routine from SRAM under reset ENDINIT protection: */
        Mcal_ResetENDINIT();
        Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);
        PflashMonTst_lCbabHelper(&CbabHlpr);
        Mcal_SetSafetyENDINIT_Timed();
        Mcal_SetENDINIT();

        /* Count unexpected PMU ECC error SMU alarms before PFLASH access: */
        PflashMonTst_lCountUnexpAlm(CbabHlpr.SmuAlmBefore);

        /* Check if tracked error matches expected error: */
        PatternAddress =
          (uint32)(&(TestData->FlashPattern->Set[i].Pattern[PFM_SBE_PTRN_IDX]));
        TrackedAddress =
          PflashMonTst_lGetCbabSystemAddress(CbabHlpr.CbabTopAfter);
        if ((1U == CbabHlpr.CbabTopAfter.B.VLD) &&
            (PFM_SINGLE_BIT_ERROR == CbabHlpr.CbabTopAfter.B.ERR) &&
            (PatternAddress == TrackedAddress))
        {
          Result = PFLASHMON_SUCCESS;
        } /* if ((1U == CbabHlpr.CbabTopAfter.B.VLD) &&
                 (PFM_SINGLE_BIT_ERROR == CbabHlpr.CbabTopAfter.B.ERR) &&
                 (PatternAddress == SystemAddress)) */
      } /* for (i = 0U;
                ((i < PMUT_TEST_PATTERN_COUNT) &&
                 (PFLASHMON_SUCCESS != Result));
                i++) */
    } /* if (PFLASHMON_SUCCESS == ResultTmp) */
  } /* if (PflashMonTst_lCalcUnexpAlmCrc() == PflashMonTst_UnexpAlm.Crc32) */

  /* Clear ADDR bit-field of the CBAB_TOP to avoid dependency on the
   * pattern address and add it to the test signature:
   */
  CbabHlpr.CbabTopAfter.B.ADDR = 0U;
  *(TestData->Signature) = (uint32)CRC32(*(TestData->Signature),
                                         CbabHlpr.CbabTopAfter.U);

  return Result;
} /* PflashMonTst_lTestSbeTracking */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static Sl_TstRsltType PflashMonTst_lTestDbeTracking     **
**                    (                                                       **
**                      const PflashMonTst_TestDataType* TestData             **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters(in)   : TestData - Pointer to test data structure for PFLASH    **
**                               bank to be tested                            **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : PFLASHMON_SUCCESS - Testing given PFLASH bank succeeded **
**                    PFLASHMON_DBE_PFx - Double bit error tracking test      **
**                                        failed for PFLASH bank x            **
**                    PFLASHMON_DATACONSISTENCY - Internal data was corrupted **
**                                                or invalid PFLASH bank      **
**                    PFLASHMON_NOTEXECUTED - Program flow consistency error  **
**                                                                            **
** Description      : This function tests correct tracking of double bit      **
**                    errors to the CBAB FIFO for a single PFLASH bank.       **
**                    The error tracking is tested with all four redundant    **
**                    double bit error patterns in PFLASH, until the test     **
**                    returns the expected result. An error is returned if    **
**                    none of the four patterns delivers the expected result. **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType PflashMonTst_lTestDbeTracking
(
  const PflashMonTst_TestDataType* TestData
)
{
  uint32                    i;
  uint32                    TrackedAddress;
  uint32                    PatternAddress;
  Sl_TstRsltType            Result;
  Sl_TstRsltType            ResultTmp;
  PflashMonTst_CbabHlprType CbabHlpr;

  /* Initialize result to appropriate double bit error code for PFLASH bank
   * under test:
   */
  Result = PflashMonTst_lGetDbeErrorCode(TestData->FlashBank);

  /* Initialize test data for helper routine: */
  CbabHlpr.FlashCbabCfgPtr  = TestData->FlashCbabCfgPtr;
  CbabHlpr.FlashCbabTopPtr  = TestData->FlashCbabTopPtr;
  CbabHlpr.FlashMarpPtr     = TestData->FlashMarpPtr;
  CbabHlpr.SmuAlm           = &SMU_AG2;
  CbabHlpr.SmuCmd           = &SMU_CMD;
  CbabHlpr.CbabTopAfter.U   = 0U;
  CbabHlpr.SmuAlmBefore     = 0U;
  CbabHlpr.ErrorType        = PFM_DOUBLE_BIT_ERROR;

  /* Check if unexpected alarm structure was corrupted: */
  if (PflashMonTst_lCalcUnexpAlmCrc() != PflashMonTst_UnexpAlm.Crc32)
  {
    Result = PFLASHMON_DATACONSISTENCY;
  } /* if (PflashMonTst_lCalcUnexpAlmCrc() != PflashMonTst_UnexpAlm.Crc32) */
  else
  {
    
    /* Calculate and compare Crc of functions in RAM that 
     were copied from PFlash at startup*/
    ResultTmp = PflashMonTst_lRamCalculateandVerifyCrc32();
    if (PFLASHMON_SUCCESS != ResultTmp)
    {
      Result = ResultTmp;
    } /* if (PFLASHMON_SUCCESS != ResultTmp) */
    else
    {
      /* Loop through each of the four redundant test patterns in PFLASH: */
      for (i = 0U;
           ((PFLASHMON_DATACONSISTENCY != Result) &&
		   (i < PMUT_TEST_PATTERN_COUNT) && (PFLASHMON_SUCCESS != Result));
           i++)
      {
        /* Setup test pattern address to current double bit error pattern: */
        CbabHlpr.DataAddr =
            &(TestData->FlashPattern->Set[i].Pattern[PFM_DBE_PTRN_IDX]);

        /* Execute helper routine from SRAM under reset ENDINIT protection: */
        Mcal_ResetENDINIT();
        Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);
        PflashMonTst_lCbabHelper(&CbabHlpr);
        Mcal_SetSafetyENDINIT_Timed();
        Mcal_SetENDINIT();

        /* Count unexpected PMU ECC error SMU alarms before PFLASH access: */
        PflashMonTst_lCountUnexpAlm(CbabHlpr.SmuAlmBefore);

        /* Check if tracked error matches expected error: */
        PatternAddress =
          (uint32)(&(TestData->FlashPattern->Set[i].Pattern[PFM_DBE_PTRN_IDX]));
        TrackedAddress =
          PflashMonTst_lGetCbabSystemAddress(CbabHlpr.CbabTopAfter);
        if ((1U == CbabHlpr.CbabTopAfter.B.VLD) &&
            (PFM_DOUBLE_BIT_ERROR == CbabHlpr.CbabTopAfter.B.ERR) &&
            (PatternAddress == TrackedAddress))
        {
          Result = PFLASHMON_SUCCESS;
        } /* if ((1U == CbabHlpr.CbabTopAfter.B.VLD) &&
                 (PFM_DOUBLE_BIT_ERROR == CbabHlpr.CbabTopAfter.B.ERR) &&
                 (PatternAddress == SystemAddress)) */
      } /* for (i = 0U;
                ((i < PMUT_TEST_PATTERN_COUNT) &&
                 (PFLASHMON_SUCCESS != Result));
                i++) */
    } /* if (PFLASHMON_SUCCESS == ResultTmp) */
  } /* if (PflashMonTst_lCalcUnexpAlmCrc() == PflashMonTst_UnexpAlm.Crc32) */

  /* Clear ADDR bit-field of the CBAB_TOP to avoid dependency on the
   * pattern address and add it to the test signature:
   */
  CbabHlpr.CbabTopAfter.B.ADDR = 0U;
  *(TestData->Signature) = (uint32)CRC32(*(TestData->Signature),
                                         CbabHlpr.CbabTopAfter.U);

  return Result;
} /* PflashMonTst_lTestDbeTracking */
#ifdef PFLASH_FIFO_BUFFERFULL_TEST_ENABLE
/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static Sl_TstRsltType PflashMonTst_lTestFifoBufferFull  **
**                    (                                                       **
**                       const PflashMonTst_TestDataType* TestData            **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     :                                                         **
** Description      : This routine checks if the Address buffer full alarm is **
**                    raised.                                                 **
*******************************************************************************/

static Sl_TstRsltType PflashMonTst_lTestFifoBufferFull
(
  const PflashMonTst_TestDataType* TestData
)
{
  Sl_TstRsltType              Result;
  Sl_TstRsltType              ResultTmp;
  PflashMonTst_CbabHlprType   FifoFullHlpr;


  
  FifoFullHlpr.SmuAlm                  = &SMU_AG2;
  FifoFullHlpr.SmuCmd                  = &SMU_CMD;
  FifoFullHlpr.FlashMarpPtr            = &FLASH0_MARP;
  FifoFullHlpr.FlashCmd                = TestData->FlashCmd;
  FifoFullHlpr.SmuAlmAfter             = 0U;
  FifoFullHlpr.SmuAlmBefore            = 0U;
  FifoFullHlpr.SmuAlmMask              = PFM_SMU_ALARM_MASK;
  FifoFullHlpr.ErrorType               = PFM_SINGLE_AND_DOUBLE_BIT_ERROR;
  FifoFullHlpr.FlashCbabCfgPtr         = TestData->FlashCbabCfgPtr;
  FifoFullHlpr.FlashCbabTopPtr         = TestData->FlashCbabTopPtr;
  FifoFullHlpr.FlashCbabStatusPtr      = TestData->FlashCbabStatusPtr;
  FifoFullHlpr.FifoErrorCount          = 0U;
  FifoFullHlpr.PatternAddr             = TestData->FlashPattern;
    
    /* Initialize result to appropriate buffer full error code for PFLASH bank
   * under test:
   */
  Result = PflashMonTst_lGetFifoFullErrorCode(TestData->FlashBank);
  if (PFLASHMON_DATACONSISTENCY != Result)
  {   
    /* Check if unexpected alarm structure was corrupted: */
    if (PflashMonTst_lCalcUnexpAlmCrc() != PflashMonTst_UnexpAlm.Crc32)
    {
      Result = PFLASHMON_DATACONSISTENCY;
    } /* if (PflashMonTst_lCalcUnexpAlmCrc() != PflashMonTst_UnexpAlm.Crc32) */
    else
    {
      /* Calculate and compare Crc of functions in RAM that 
         were copied from PFlash at startup*/   
      ResultTmp = PflashMonTst_lRamCalculateandVerifyCrc32();
      if (PFLASHMON_SUCCESS != ResultTmp)
      {
        Result = ResultTmp;
      } /* if (PFLASHMON_SUCCESS != ResultTmp) */
      else
      {

        /* Setup test pattern address to first single bit error pattern: */
        FifoFullHlpr.DataAddr =
            &(TestData->FlashPattern->Set[0].Pattern[PFM_SBE_PTRN_IDX]);

        Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);
        Mcal_ResetENDINIT();

        ResultTmp = PflashMonTst_lCbabFullHelper(&FifoFullHlpr);

        Mcal_SetENDINIT();
        Mcal_SetSafetyENDINIT_Timed();

        /* Count unexpected PMU ECC error SMU alarms before PFLASH access: */
        PflashMonTst_lCountUnexpAlm(FifoFullHlpr.SmuAlmBefore);
      
        /*Clear the CBAB of the flash bank under test*/
        PflashMonTst_lClearSpecificErrorFifo(TestData);

        /* Check result of helper routine: */
        if (PFLASHMON_SUCCESS != ResultTmp)
        {
          Result = ResultTmp;
        } /* if (PFLASHMON_SUCCESS != ResultTmp) */
        else
        {
          if (((FifoFullHlpr.SmuAlmAfter & PFM_SMU_ALARM6) != 0U)
                && (0x0AU == FifoFullHlpr.FifoErrorCount))
          {
            Result = PFLASHMON_SUCCESS;
          } /* if ((FifoFullHlpr.SmuAlmAfter & PMUT_SMU_ALARM_SETALL) ==
                 PMUT_SMU_ALARM3) */
        } /* if (PFLASHMON_SUCCESS == ResultTmp) */
      } /* for (i = 0U; i < PMUT_TEST_PATTERN_COUNT; i++) */
    } /* if (PFLASHMON_SUCCESS == ResultTmp) */
  }
  *(TestData->Signature) = (uint32)CRC32(*(TestData->Signature),
                (FifoFullHlpr.SmuAlmAfter & PFM_SMU_ALARM6));

  return Result;
} /* PflashMonTst_lTestFifoBufferFull */
#endif
/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static Sl_TstRsltType PflashMonTst_lTestMbeTracking     **
**                    (                                                       **
**                      const PflashMonTst_TestDataType* TestData             **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters(in)   : TestData - Pointer to test data structure for PFLASH    **
**                               bank to be tested                            **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : PFLASHMON_SUCCESS - Testing given PFLASH bank succeeded **
**                    PFLASHMON_MBE_PFx - uncorrectable bit error tracking    **
**                                        test failed for PFLASH bank x       **
**                    PFLASHMON_DATACONSISTENCY - Internal data was corrupted **
**                                                or invalid PFLASH bank      **
**                    PFLASHMON_NOTEXECUTED - Program flow consistency error  **
**                                                                            **
** Description      : This function tests correct tracking of uncorrectable   **
**                    bit errors to the UBAB FIFO for a single PFLASH bank.   **
**                    The error tracking is tested with all four redundant    **
**                    triple bit error patterns in PFLASH, until the test     **
**                    returns the expected result. An error is returned if    **
**                    none of the four patterns delivers the expected result. **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType PflashMonTst_lTestMbeTracking
(
  const PflashMonTst_TestDataType* TestData
)
{
  uint32                    i;
  uint32                    TrackedAddress;
  uint32                    PatternAddress;
  Sl_TstRsltType            Result;
  Sl_TstRsltType            ResultTmp;
  PflashMonTst_UbabHlprType UbabHlpr;

  /* Initialize result to appropriate multi bit error code for PFLASH bank
   * under test:
   */
  Result = PflashMonTst_lGetMbeErrorCode(TestData->FlashBank);

  /* Initialize test data for helper routine: */
  UbabHlpr.FlashUbabCfgPtr  = TestData->FlashUbabCfgPtr;
  UbabHlpr.FlashUbabTopPtr  = TestData->FlashUbabTopPtr;
  UbabHlpr.FlashMarpPtr     = TestData->FlashMarpPtr;
  UbabHlpr.SmuAlm           = &SMU_AG2;
  UbabHlpr.SmuCmd           = &SMU_CMD;
  UbabHlpr.UbabTopAfter.U   = 0U;
  UbabHlpr.SmuAlmBefore     = 0U;
  UbabHlpr.DataAddr         = 0U;

  /* Check if unexpected alarm structure was corrupted: */
  if (PflashMonTst_lCalcUnexpAlmCrc() != PflashMonTst_UnexpAlm.Crc32)
  {
    Result = PFLASHMON_DATACONSISTENCY;
  } /* if (PflashMonTst_lCalcUnexpAlmCrc() != PflashMonTst_UnexpAlm.Crc32) */
  else
  {
    /* Calculate and compare Crc of functions in RAM that 
     were copied from PFlash at startup*/
    ResultTmp = PflashMonTst_lRamCalculateandVerifyCrc32();
    if (PFLASHMON_SUCCESS != ResultTmp)
    {
      Result = ResultTmp;
    } /* if (PFLASHMON_SUCCESS != ResultTmp) */
    else
    {
      /* Loop through each of the four redundant test patterns in PFLASH: */
      for (i = 0U;
           ((PFLASHMON_DATACONSISTENCY != Result) &&
           (i < PMUT_TEST_PATTERN_COUNT) && (PFLASHMON_SUCCESS != Result));
           i++)
      {
        /* Setup test pattern address to current multi bit error pattern: */
        UbabHlpr.DataAddr =
            &(TestData->FlashPattern->Set[i].Pattern[PFM_MBE_PTRN_IDX]);

        /* Execute helper routine from SRAM under reset ENDINIT protection: */
        Mcal_ResetENDINIT();
        Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);
        PflashMonTst_lUbabHelper(&UbabHlpr);
        Mcal_SetSafetyENDINIT_Timed();
        Mcal_SetENDINIT();

        /* Count unexpected PMU ECC error SMU alarms before PFLASH access: */
        PflashMonTst_lCountUnexpAlm(UbabHlpr.SmuAlmBefore);

        /* Check if tracked error matches expected error: */
        PatternAddress =
          (uint32)(&(TestData->FlashPattern->Set[i].Pattern[PFM_MBE_PTRN_IDX]));
        TrackedAddress =
          PflashMonTst_lGetUbabSystemAddress(UbabHlpr.UbabTopAfter);
        if ((1U == UbabHlpr.UbabTopAfter.B.VLD) &&
            (PFM_MULTI_BIT_ERROR == UbabHlpr.UbabTopAfter.B.ERR) &&
            (PatternAddress == TrackedAddress))
        {
          Result = PFLASHMON_SUCCESS;
        } /* if ((1U == UbabHlpr.UbabTopAfter.B.VLD) &&
                 (PFM_MULTI_BIT_ERROR == UbabHlpr.UbabTopAfter.B.ERR) &&
                 (PatternAddress == SystemAddress)) */
      } /* for (i = 0U;
                ((i < PMUT_TEST_PATTERN_COUNT) &&
                 (PFLASHMON_SUCCESS != Result));
                i++) */
    } /* if (PFLASHMON_SUCCESS == ResultTmp) */
  } /* if (PflashMonTst_lCalcUnexpAlmCrc() == PflashMonTst_UnexpAlm.Crc32) */

  /* Clear ADDR bit-field of the UBAB_TOP to avoid dependency on the
   * pattern address and add it to the test signature:
   */
  UbabHlpr.UbabTopAfter.B.ADDR = 0U;
  *(TestData->Signature) = (uint32)CRC32(*(TestData->Signature),
                                         UbabHlpr.UbabTopAfter.U);

  return Result;
} /* PflashMonTst_lTestMbeTracking */


/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static void PflashMonTst_lClearClearedErrList           **
**                    (                                                       **
**                      void                                                  **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function clears the list of cleared CBAB / UBAB    **
**                    errors.                                                 **
**                                                                            **
*******************************************************************************/
static void PflashMonTst_lClearClearedErrList
(
  void
)
{
  uint32  Bank = 0U;
  uint32  i;

  /* Loop through each PFLASH bank: */
#if ((CHIP_ID == 26U) || (CHIP_ID == 27U) || (CHIP_ID == 29U))
  for (Bank = 0U; Bank < PFLASH_MON_TST_MAX_FLASHBANKS; Bank++)
#endif
  {
    /* Clear all CBAB entries: */
    for (i = 0U; i < PFLASH_MON_CBAB_FIFO_DEPTH; i++)
    {
      PflashMonTst_ClearedErr.Bank[Bank].Cbab[i].U = 0U;
    } /* for (i = 0U; i < PFLASH_MON_CBAB_FIFO_DEPTH; i++) */

    /* Clear all UBAB entries: */
    PflashMonTst_ClearedErr.Bank[Bank].Ubab[0].U = 0U;
  } /* for (Bank = 0U; Bank < PFLASH_MON_TST_MAX_FLASHBANKS; Bank++) */

  /* Update CRC: */
  PflashMonTst_ClearedErr.Crc32 = PflashMonTst_lCalcClearedErrCrc();
} /* PflashMonTst_lClearClearedErrList */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static void PflashMonTst_lClearUnexpAlmList             **
**                    (                                                       **
**                      void                                                  **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function clears the list of unexpected (and        **
**                    cleared) SMU alarms.                                    **
**                                                                            **
*******************************************************************************/
static void PflashMonTst_lClearUnexpAlmList
(
  void
)
{
  /* Clear unexpected PMU ECC error SMU alarm counters: */
  PflashMonTst_UnexpAlm.Sbe = 0U;
  PflashMonTst_UnexpAlm.Dbe = 0U;
  PflashMonTst_UnexpAlm.Mbe = 0U;
#ifdef PFLASH_FIFO_BUFFERFULL_TEST_ENABLE
  PflashMonTst_UnexpAlm.BufferFullErr = 0U;
#endif

  /* Update CRC: */
  PflashMonTst_UnexpAlm.Crc32 = PflashMonTst_lCalcUnexpAlmCrc();
} /* PflashMonTst_lClearUnexpAlmList */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static void PflashMonTst_lClearErrorFifos               **
**                    (                                                       **
**                      const PflashMonTst_ConfigType* const Config           **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters(in)   : Config - Pointer to current configuration set           **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function copies the content of all valid CBAB /    **
**                    UBAB FIFO entries to the list of cleared CBAB / UBAB    **
**                    errors and clears the FIFOs.                            **
**                                                                            **
*******************************************************************************/
static void PflashMonTst_lClearErrorFifos
(
  const PflashMonTst_ConfigType* const Config
)
{
  uint32  Bank = 0U;
  uint32  i;

  /* Loop through each PFLASH bank: */
#if ((CHIP_ID == 26U) || (CHIP_ID == 27U) || (CHIP_ID == 29U))
  for (Bank = 0U; Bank < PFLASH_MON_TST_MAX_FLASHBANKS; Bank++)
#endif  
  {
    /* Testing of current bank enabled? */
    if (1U == Config->BankEnable[Bank])
    {
      /* Clear all CBAB entries: */
      for (i = 0U; i < (uint32)PFLASH_MON_CBAB_FIFO_DEPTH; i++)
      {
        if (1U == MODULE_FLASH0.CBAB[Bank].TOP.B.VLD)
        {
          /* Copy FIFO entry to list: */
          PflashMonTst_ClearedErr.Bank[Bank].Cbab[i].U =
              MODULE_FLASH0.CBAB[Bank].TOP.U;

          /* Remove top most entry from the FIFO: */
          MODULE_FLASH0.CBAB[Bank].TOP.B.CLR = 1U;
        } /* if (1U == MODULE_FLASH0.CBAB[Bank].TOP.B.VLD) */
        else
        {
          /* No more valid entries left in the FIFO: */
          break;
        } /* if (1U != MODULE_FLASH0.CBAB[Bank].TOP.B.VLD) */
      } /* for (i = 0U; i < (uint32)PFLASH_MON_CBAB_FIFO_DEPTH; i++) */

      /* Clear all UBAB entries: */
      if (1U == MODULE_FLASH0.UBAB[Bank].TOP.B.VLD)
      {
        /* Copy FIFO entry to list: */
        PflashMonTst_ClearedErr.Bank[Bank].Ubab[0].U =
            MODULE_FLASH0.UBAB[Bank].TOP.U;

        /* Remove top most entry from the FIFO: */
        MODULE_FLASH0.UBAB[Bank].TOP.B.CLR = 1U;
      } /* if (1U == MODULE_FLASH0.UBAB[Bank].TOP.B.VLD) */
    } /* if (1U == Config->BankEnable[Bank]) */
  } /* for (Bank = 0U; Bank < PFLASH_MON_TST_MAX_FLASHBANKS; Bank++) */

  /* Update CRC: */
  PflashMonTst_ClearedErr.Crc32 = PflashMonTst_lCalcClearedErrCrc();
} /* PflashMonTst_lClearErrorFifos */

#ifdef PFLASH_FIFO_BUFFERFULL_TEST_ENABLE
/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static void PflashMonTst_lClearSpecificErrorFifo        **
**                    (                                                       **
**                        const PflashMonTst_TestDataType* TestData           **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters(in)   : TestData - Pointer to test data structure for PFLASH    **
**                               bank to be tested                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function clears all valid CBAB FIFO entries of the **
**                    specified flash bank                                    **
**                                                                            **
*******************************************************************************/
static void PflashMonTst_lClearSpecificErrorFifo
(
  const PflashMonTst_TestDataType* TestData
)
{
  uint32 i = 0U;
  for (i = 0U; i < (uint32)PFLASH_MON_CBAB_FIFO_DEPTH; i++)
  {
    /* Clear all entries: */
    if (1U == MODULE_FLASH0.CBAB[TestData->FlashBank].TOP.B.VLD)
    {
      /* Remove top most entry from the FIFO: */
      MODULE_FLASH0.CBAB[TestData->FlashBank].TOP.B.CLR = 1U;
    } /* if (1U == MODULE_FLASH0.CBAB[TestData->FlashBank].TOP.B.VLD) */
  }

} /* PflashMonTst_lClearSpecificErrorFifo */
#endif
/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static uint32 PflashMonTst_lGetCbabSystemAddress        **
**                    (                                                       **
**                      volatile Ifx_FLASH_CBAB_TOP Cbab                      **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : Cbab - CBAB FIFO entry from which to get the system     **
**                           address                                          **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : System address of tracked error                         **
**                                                                            **
** Description      : This function calculates the system address from a      **
**                    given CBAB error entry.                                 **
**                                                                            **
*******************************************************************************/
static uint32 PflashMonTst_lGetCbabSystemAddress
(
  volatile Ifx_FLASH_CBAB_TOP Cbab
)
{
  uint32  SystemAddress = 0U;
  uint32  MemoryAddress = Cbab.B.ADDR;

  SystemAddress = PFM_PMU0_BASE_ADDRESS +
                  (uint32)(MemoryAddress << PFM_CBAB_ADDR_SHIFT);

  return SystemAddress;
} /* PflashMonTst_lGetCbabSystemAddress */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static uint32 PflashMonTst_lGetUbabSystemAddress        **
**                    (                                                       **
**                      volatile Ifx_FLASH_UBAB_TOP Ubab                      **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : Ubab - UBAB FIFO entry from which to get the system     **
**                           address                                          **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : System address of tracked error                         **
**                                                                            **
** Description      : This function calculates the system address from a      **
**                    given UBAB error entry.                                 **
**                                                                            **
*******************************************************************************/
static uint32 PflashMonTst_lGetUbabSystemAddress
(
  volatile Ifx_FLASH_UBAB_TOP Ubab
)
{
  uint32  SystemAddress = 0U;
  uint32  MemoryAddress = Ubab.B.ADDR;

  SystemAddress = PFM_PMU0_BASE_ADDRESS +
                  (uint32)(MemoryAddress << PFM_UBAB_ADDR_SHIFT);

  return SystemAddress;
} /* PflashMonTst_lGetUbabSystemAddress */

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : static void PflashMonTst_lCountUnexpAlm                           **
**          (                                                                 **
**            uint32 CurrAlmStatus                                            **
**          )                                                                 **
**                                                                            **
** Description : Count unexpected ECC alarms                                  **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) : CurrAlmStatus - current status of SMU AG2                **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value : None                                                        **
**                                                                            **
*******************************************************************************/
static void PflashMonTst_lCountUnexpAlm
(
  uint32 CurrAlmStatus
)
{
  if ((CurrAlmStatus & PFM_SMU_ALARM2) != 0U)
  {
    PflashMonTst_UnexpAlm.Sbe++;
  } /* if ((CurrAlmStatus & PFM_SMU_ALARM2) != 0U) */

  if ((CurrAlmStatus & PFM_SMU_ALARM3) != 0U)
  {
    PflashMonTst_UnexpAlm.Dbe++;
  } /* if ((CurrAlmStatus & PFM_SMU_ALARM3) != 0U) */

  if ((CurrAlmStatus & PFM_SMU_ALARM4) != 0U)
  {
    PflashMonTst_UnexpAlm.Mbe++;
  } /* if ((CurrAlmStatus & PFM_SMU_ALARM4) != 0U) */
#ifdef PFLASH_FIFO_BUFFERFULL_TEST_ENABLE
    if ((CurrAlmStatus & PFM_SMU_ALARM6) != 0U)
  {
    PflashMonTst_UnexpAlm.BufferFullErr++;
  } /* if ((CurrAlmStatus & PFM_SMU_ALARM6) != 0U) */
#endif  
  PflashMonTst_UnexpAlm.Crc32 = PflashMonTst_lCalcUnexpAlmCrc();
} /* PflashMonTst_lCountUnexpAlm */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static Sl_TstRsltType PflashMonTst_lGetSbeErrorCode     **
**                    (                                                       **
**                      const uint32 FlashBank                                **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : FlashBank - PFLASH bank for which to get the single bit **
**                                error code; values: 0..3                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : PFLASHMON_SBE_PF0 - Single bit error tracking test      **
**                                        failed for PFLASH bank 0            **
**                    PFLASHMON_SBE_PF1 - Single bit error tracking test      **
**                                        failed for PFLASH bank 1            **
**                    PFLASHMON_SBE_PF2 - Single bit error tracking test      **
**                                        failed for PFLASH bank 2            **
**                    PFLASHMON_SBE_PF3 - Single bit error tracking test      **
**                                        failed for PFLASH bank 3            **
**                    PFLASHMON_DATACONSISTENCY - Invalid FlashBank parameter **
**                                                                            **
** Description      : This function returns the appropriate single bit error  **
**                    code for a given PFLASH bank.                           **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType PflashMonTst_lGetSbeErrorCode
(
  const uint32 FlashBank
)
{
  Sl_TstRsltType  Result;
  switch (FlashBank)
  {
  case PFM_FLASH_BANK0:
    Result = PFLASHMON_SBE_PF0;
    break;

#if (PFLASH_MON_TST_MAX_FLASHBANKS > 1U)
  case PFM_FLASH_BANK1:
    Result = PFLASHMON_SBE_PF1;
    break;

#if (PFLASH_MON_TST_MAX_FLASHBANKS > 2U)
  case PFM_FLASH_BANK2:
    Result = PFLASHMON_SBE_PF2;
    break;

#if (PFLASH_MON_TST_MAX_FLASHBANKS > 3U)
  case PFM_FLASH_BANK3:
    Result = PFLASHMON_SBE_PF3;
    break;

#endif
#endif
#endif
  default:
    Result = PFLASHMON_DATACONSISTENCY;
    break;
  } /* switch (FlashBank) */

  return Result;
} /* PflashMonTst_lGetSbeErrorCode */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static Sl_TstRsltType PflashMonTst_lGetDbeErrorCode     **
**                    (                                                       **
**                      const uint32 FlashBank                                **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : FlashBank - PFLASH bank for which to get the double bit **
**                                error code; values: 0..3                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : PFLASHMON_DBE_PF0 - Double bit error tracking test      **
**                                        failed for PFLASH bank 0            **
**                    PFLASHMON_DBE_PF1 - Double bit error tracking test      **
**                                        failed for PFLASH bank 1            **
**                    PFLASHMON_DBE_PF2 - Double bit error tracking test      **
**                                        failed for PFLASH bank 2            **
**                    PFLASHMON_DBE_PF3 - Double bit error tracking test      **
**                                        failed for PFLASH bank 3            **
**                    PFLASHMON_DATACONSISTENCY - Invalid FlashBank parameter **
**                                                                            **
** Description      : This function returns the appropriate double bit error  **
**                    code for a given PFLASH bank.                           **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType PflashMonTst_lGetDbeErrorCode
(
  const uint32 FlashBank
)
{
  Sl_TstRsltType  Result;
  switch (FlashBank)
  {
  case PFM_FLASH_BANK0:
    Result = PFLASHMON_DBE_PF0;
    break;

#if (PFLASH_MON_TST_MAX_FLASHBANKS > 1U)
  case PFM_FLASH_BANK1:
    Result = PFLASHMON_DBE_PF1;
    break;

#if (PFLASH_MON_TST_MAX_FLASHBANKS > 2U)
  case PFM_FLASH_BANK2:
    Result = PFLASHMON_DBE_PF2;
    break;

#if (PFLASH_MON_TST_MAX_FLASHBANKS > 3U)
  case PFM_FLASH_BANK3:
    Result = PFLASHMON_DBE_PF3;
    break;

#endif
#endif
#endif
  default:
    Result = PFLASHMON_DATACONSISTENCY;
    break;
  } /* switch (FlashBank) */

  return Result;
} /* PflashMonTst_lGetDbeErrorCode */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static Sl_TstRsltType PflashMonTst_lGetMbeErrorCode     **
**                    (                                                       **
**                      const uint32 FlashBank                                **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : FlashBank - PFLASH bank for which to get the multi bit  **
**                                error code; values: 0..3                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : PFLASHMON_MBE_PF0 - Multi bit error tracking test       **
**                                        failed for PFLASH bank 0            **
**                    PFLASHMON_MBE_PF1 - Multi bit error tracking test       **
**                                        failed for PFLASH bank 1            **
**                    PFLASHMON_MBE_PF2 - Multi bit error tracking test       **
**                                        failed for PFLASH bank 2            **
**                    PFLASHMON_MBE_PF3 - Multi bit error tracking test       **
**                                        failed for PFLASH bank 3            **
**                    PFLASHMON_DATACONSISTENCY - Invalid FlashBank parameter **
**                                                                            **
** Description      : This function returns the appropriate multi bit error   **
**                    code for a given PFLASH bank.                           **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType PflashMonTst_lGetMbeErrorCode
(
  const uint32 FlashBank
)
{
  Sl_TstRsltType  Result;
  switch (FlashBank)
  {
  case PFM_FLASH_BANK0:
    Result = PFLASHMON_MBE_PF0;
    break;

#if (PFLASH_MON_TST_MAX_FLASHBANKS > 1U)
  case PFM_FLASH_BANK1:
    Result = PFLASHMON_MBE_PF1;
    break;

#if (PFLASH_MON_TST_MAX_FLASHBANKS > 2U)
  case PFM_FLASH_BANK2:
    Result = PFLASHMON_MBE_PF2;
    break;

#if (PFLASH_MON_TST_MAX_FLASHBANKS > 3U)
  case PFM_FLASH_BANK3:
    Result = PFLASHMON_MBE_PF3;
    break;
#endif
#endif
#endif
  default:
    Result = PFLASHMON_DATACONSISTENCY;
    break;
  } /* switch (FlashBank) */

  return Result;
} /* PflashMonTst_lGetMbeErrorCode */

#ifdef PFLASH_FIFO_BUFFERFULL_TEST_ENABLE
/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static Sl_TstRsltType PflashMonTst_lGetFifoFullErrorCode**
**                    (                                                       **
**                      const uint32 FlashBank                                **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : FlashBank - PFLASH bank for which to get the CBAB       **
**                                prefill error code; values: 0..3            **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : PFLASHMON_BUFF_FILL_FAIL_PF0 - CBAB error filling       **
**                                        failed for PFLASH bank 0            **
**                    PFLASHMON_BUFF_FILL_FAIL_PF1 - CBAB error filling       **
**                                        failed for PFLASH bank 1            **
**                    PFLASHMON_BUFF_FILL_FAIL_PF2 - CBAB error filling       **
**                                        failed for PFLASH bank 2            **
**                    PFLASHMON_BUFF_FILL_FAIL_PF3 - CBAB error filling       **
**                                        failed for PFLASH bank 3            **
**                    PFLASHMON_DATACONSISTENCY - Invalid FlashBank parameter **
**                                                                            **
** Description      : This function returns the appropriate CBAB address      **
**                    filling error code for a given PFLASH bank.             **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType PflashMonTst_lGetFifoFullErrorCode
(
  const uint32 FlashBank
)
{
  Sl_TstRsltType  Result;
  switch (FlashBank)
  {
  case PFM_FLASH_BANK0:
    Result = PFLASHMON_BUFF_FILL_FAIL_PF0;
    break;

#if (PFLASH_MON_TST_MAX_FLASHBANKS > 1U)
  case PFM_FLASH_BANK1:
    Result = PFLASHMON_BUFF_FILL_FAIL_PF1;
    break;

#if (PFLASH_MON_TST_MAX_FLASHBANKS > 2U)
  case PFM_FLASH_BANK2:
    Result = PFLASHMON_BUFF_FILL_FAIL_PF2;
    break;

#if (PFLASH_MON_TST_MAX_FLASHBANKS > 3U)
  case PFM_FLASH_BANK3:
    Result = PFLASHMON_BUFF_FILL_FAIL_PF3;
    break;
#endif
#endif
#endif
  default:
    Result = PFLASHMON_DATACONSISTENCY;
    break;
  } /* switch (FlashBank) */

  return Result;
} /* PflashMonTst_lGetFifoFullErrorCode */
#endif
/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static uint32 PflashMonTst_lCalcClearedErrCrc           **
**                    (                                                       **
**                      void                                                  **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : CRC32 value of the PflashMonTst_ClearedErr structure    **
**                                                                            **
** Description      : This function calculates the CRC32 value over all       **
**                    members of the PflashMonTst_ClearedErr structure.       **
**                                                                            **
*******************************************************************************/
static uint32 PflashMonTst_lCalcClearedErrCrc
(
  void
)
{
  uint32  Bank = 0U;
  uint32  i;
  uint32  Crc = 0U;

  /* Loop through each PFLASH bank: */
#if ((CHIP_ID == 26U) || (CHIP_ID == 27U) || (CHIP_ID == 29U))
  for (Bank = 0U; Bank < (uint32)PFLASH_MON_TST_MAX_FLASHBANKS; Bank++)
#endif
  {
    /* Loop through each CBAB entry: */
    for (i = 0U; i < (uint32)PFLASH_MON_CBAB_FIFO_DEPTH; i++)
    {
      Crc = (uint32)CRC32(Crc, PflashMonTst_ClearedErr.Bank[Bank].Cbab[i].U);
    } /* for (i = 0U; i < (uint32)PFLASH_MON_CBAB_FIFO_DEPTH; i++) */

    Crc = (uint32)CRC32(Crc, PflashMonTst_ClearedErr.Bank[Bank].Ubab[0].U);
  } /* for (Bank = 0U; Bank < (uint32)PFLASH_MON_TST_MAX_FLASHBANKS; Bank++) */

  return Crc;
} /* PflashMonTst_lCalcClearedErrCrc */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static uint32 PflashMonTst_lCalcUnexpAlmCrc             **
**                    (                                                       **
**                      void                                                  **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : CRC32 value of the PflashMonTst_UnexpAlm structure      **
**                                                                            **
** Description      : This function calculates the CRC32 value over all       **
**                    members of the PflashMonTst_UnexpAlm structure.         **
**                                                                            **
*******************************************************************************/
static uint32 PflashMonTst_lCalcUnexpAlmCrc
(
  void
)
{
  uint32  Crc;

  /* Calculate CRC: */
  Crc = (uint32)CRC32(PflashMonTst_UnexpAlm.Sbe, PflashMonTst_UnexpAlm.Dbe);
  Crc = (uint32)CRC32(Crc, PflashMonTst_UnexpAlm.Mbe);
#ifdef PFLASH_FIFO_BUFFERFULL_TEST_ENABLE
  Crc = (uint32)CRC32(Crc, PflashMonTst_UnexpAlm.BufferFullErr);
#endif

  return Crc;
} /* PflashMonTst_lCalcUnexpAlmCrc */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static uint32 PflashMonTst_lCalcBackupCrc               **
**                    (                                                       **
**                      void                                                  **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : CRC32 value of the given PflashMonTst_BackupDataType    **
**                    structure                                               **
**                                                                            **
** Description      : This function calculates the CRC32 value over all       **
**                    members of a given PflashMonTst_BackupDataType          **
**                    structure.                                              **
**                                                                            **
*******************************************************************************/
static uint32 PflashMonTst_lCalcBackupCrc
(
  const PflashMonTst_BackupDataType* const BackupData
)
{
  uint32  Bank = 0U;
  uint32  Crc;

  /* Add SMU alarm action backup values to the CRC: */
  Crc = (uint32)CRC32((uint32)BackupData->AlmActionSbe,
                      (uint32)BackupData->AlmActionDbe);
  Crc = (uint32)CRC32(Crc, (uint32)BackupData->AlmActionMbe);
#ifdef PFLASH_FIFO_BUFFERFULL_TEST_ENABLE
  Crc = (uint32)CRC32(Crc, (uint32)BackupData->AlmActionBufferFull);
#endif

  /* Loop through each PFLASH bank: */
#if ((CHIP_ID == 26U) || (CHIP_ID == 27U) || (CHIP_ID == 29U))
  for (Bank = 0U; Bank < (uint32)PFLASH_MON_TST_MAX_FLASHBANKS; Bank++)
#endif  
  {
    /* Add CBAB / UBAB CFG to the CRC: */
    Crc = (uint32)CRC32(Crc, BackupData->CbabCfgBackup[Bank]);
    Crc = (uint32)CRC32(Crc, BackupData->UbabCfgBackup[Bank]);
  } /* for (Bank = 0U; Bank < (uint32)PFLASH_MON_TST_MAX_FLASHBANKS; Bank++) */

  /* Add backup data valid flag to the CRC: */
  Crc = (uint32)CRC32(Crc, (uint32)BackupData->Valid);

  return Crc;
}

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           :                                                         **
**          static Std_ReturnType PflashMonTst_lRamCalculateandVerifyCrc32    **
**          (                                                                 **
**            void                                                            **
**          )                                                                 **
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
**                    compares it with the CRC32 value of the area in PFLASH  **
**                    that holds these functions                              **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType PflashMonTst_lRamCalculateandVerifyCrc32(void)
{
  uint32 crcvalue = 0U;
  Sl_TstRsltType  Result = PFLASHMON_CRCERROR;
  uint32 beginaddr, endaddr;
  
  endaddr = (uint32)LOC_END_PflashMon_EccEdc_RAM_RUNCODE;
  beginaddr = (uint32)LOC_START_PflashMon_EccEdc_RAM_RUNCODE;
  
  crcvalue = PmuEccEdcTst_CalculateCrc32(LOC_START_PflashMon_EccEdc_RAM_RUNCODE,
            (endaddr-beginaddr));
            
  if(crcvalue == PflashMonTst_PFlashFnCrc32)
  {
    Result = PFLASHMON_SUCCESS;
  }
    
  return Result;
}/*PflashMonTst_lRamCalculateandVerifyCrc32*/

#define IFX_PFLASHMON_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
