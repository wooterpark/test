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
**   $FILENAME   : PmuEccEdcTst.c $                                           **
**                                                                            **
**   $CC VERSION : \main\72 $                                                 **
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


#include "PmuEccEdcTst.h"
#include "ChipId.h"
#include "SmuInt.h"
#include "Mcal.h"
#include "IfxCpu_reg.h"
#include "IfxCpu_bf.h"
#include "IfxFlash_reg.h"
#include "IfxScu_reg.h"
#include "IfxSmu_reg.h"

/*******************************************************************************
**                      Local Macro Definitions                               **
*******************************************************************************/

/* Indices of test patterns within a pattern set array: */
#define PMUT_VCW_PTRN_IDX               ( 0 )
#define PMUT_SBE_PTRN_IDX               ( 1 )
#define PMUT_DBE_PTRN_IDX               ( 2 )
#define PMUT_MBE_PTRN_IDX               ( 3 )

/* FSI Commands */
#define PMUT_FSI_CMD_FA                 ( (uint32)0x000000FAU )

/* Data Flash Base Address for Flash commands */
#define PMUT_PMU0_DF0_BASE              ( (uint32)0xAF000000U )

/* Relative address of flash command interface: */
#define PMUT_FLS_CMD_ADDR               ( (uint32)0x00005554U )

/* Bit mask for all PMU related SMU alarms */
#define PMUT_SMU_ALARM_SETALL           ( 0x000001BCU )

/* bit masks for PMU related SMU alarms */
#define PMUT_SMU_ALARM2                 ( ((uint32)1U << SMU_ALARM_2) )
#define PMUT_SMU_ALARM3                 ( ((uint32)1U << SMU_ALARM_3) )
#define PMUT_SMU_ALARM4                 ( ((uint32)1U << SMU_ALARM_4) )
#define PMUT_SMU_ALARM7                 ( ((uint32)1U << SMU_ALARM_7) )
#define PMUT_SMU_ALARM8                 ( ((uint32)1U << SMU_ALARM_8) )

/* SMU clear alarm status timeout: */
#define PMUT_SMU_AGSTATUS_TIMEOUT       ( (uint32)1000U )


/* *** Constants required for trap handling: *** */

/* - Invalid BTV value: */
#define PMUT_INVALID_BTV_VALUE          ((uint32)0xFFFFFFFFU)

/* - Trap vector size in bytes: */
#define PMUT_TRAP_VECTOR_SIZE           ((uint32)32U)

/* - Core ID mask, extracting only the valid first two bits: */
#define PMUT_CORE_ID_MASK               ((uint32)0x00000003U)

/* - CPU core definitions: */
#if (CHIP_ID == 21U) || (CHIP_ID == 22U) || (CHIP_ID == 23U) || (CHIP_ID == 24U)
#define PMUT_NO_OF_CORES                ((uint8)1U)
#elif (CHIP_ID == 26U)
#define PMUT_NO_OF_CORES                ((uint8)2U)
#elif (CHIP_ID == 27U) || (CHIP_ID == 29U)
#define PMUT_NO_OF_CORES                ((uint8)3U)
#endif /* (CHIP_ID == 27) || (CHIP_ID == 29) */
#define PMUT_CPU_CORE0                  ((uint32)0U)
#define PMUT_CPU_CORE1                  ((uint32)1U)
#define PMUT_CPU_CORE2                  ((uint32)2U)

/* Number of cache lines in DCACHEs: */
#define PMUT_DCACHE_LINE_COUNT          ((uint32)256U)

/* Local DSPR base address: */
#define PMUT_LOCAL_DSPR_BASE            ((uint32)0xD0000000U)

/* Cache way mask for CACHEI.* instruction: */
#define PMUT_CACHE_WAY_MASK             ((uint32)0x00000001U)

/* Mask to extract cache index from bits 7:1 of a counter: */
#define PMUT_CACHE_IDX_MASK             ((uint32)0x000000FEU)

/* Bit shift count to convert bits 7:1 of a counter to a cache index for the
 * CACHEI.* instruction:
 */
#define PMUT_CACHE_IDX_SHIFT            ((uint32)4U)

/* Timeout for PCACHE invalidation. PCACHE invalidation takes 64 cycles, so a
 * timeout of 0x100 loop iterations is sufficient:
 */
#define PMUT_PCACHE_INV_TIMEOUT         ((uint32)0x100U)

/* *** Constants required for Reset / Set ENDINIT functionality in trap
 *     handler ***
 */

/* - Mask for password Bits 2-7 */
#define PMUT_WDT_PASSWORD_LOWER_MASK    (0x000000FCu)

/* - Mask for password Bits 8-15 */
#define PMUT_WDT_PASSWORD_UPPER_MASK    (0x0000FF00u)

/* - Mask for password bits */
#define PMUT_WDT_PASSWORD_MASK          (PMUT_WDT_PASSWORD_LOWER_MASK | \
                                         PMUT_WDT_PASSWORD_UPPER_MASK)
/* - Mask for reload bits */
#define PMUT_WDT_RELOAD_MASK            (0xFFFF0000u)

/* - Mask for LCK and ENDINIT status bits */
#define PMUT_WDT_STATUS_MASK            (0x00000003u)

/* - Reload value for watch dog in timeout mode */
#define SDWT_TIMEOUT_MODE_RELOAD        (0xFFFC0000u)


/*******************************************************************************
**                           Config check                                     **
*******************************************************************************/
#if (PMU_ECC_EDC_TST_MAX_FLASHBANKS < 1U)
 #error "number of configured flash banks is too small!"
#endif

#if (PMU_ECC_EDC_TST_MAX_FLASHBANKS > 4U)
 #error "number of configured flash banks is too large!"
#endif

/*******************************************************************************
**                      Local Type Definitions                                **
*******************************************************************************/

/* Container for backup data of SMU Alarm Actions modified by the tests */
typedef struct PmuEccEdcTst_BackupDataType
{
  Smu_AlarmActionType AlmActionSbe;
  Smu_AlarmActionType AlmActionDbe;
  Smu_AlarmActionType AlmActionMbe;
  Smu_AlarmActionType AlmActionEccMon;
  Smu_AlarmActionType AlmActionEdcCmp;
  Std_ReturnType      GetAlmActionResult;

  uint32              CbabCfg0Backup;
#if (PMU_ECC_EDC_TST_MAX_FLASHBANKS > 1U)
  uint32              CbabCfg1Backup;
#if (PMU_ECC_EDC_TST_MAX_FLASHBANKS > 2U)
  uint32              CbabCfg2Backup;
#if (PMU_ECC_EDC_TST_MAX_FLASHBANKS > 3U)
  uint32              CbabCfg3Backup;
#endif /* PMU_ECC_EDC_TST_MAX_FLASHBANKS > 3U */  
#endif /* PMU_ECC_EDC_TST_MAX_FLASHBANKS > 2U */
#endif /* PMU_ECC_EDC_TST_MAX_FLASHBANKS > 1U */

  uint32              UbabCfg0Backup;
#if (PMU_ECC_EDC_TST_MAX_FLASHBANKS > 1U)
  uint32              UbabCfg1Backup;
#if (PMU_ECC_EDC_TST_MAX_FLASHBANKS > 2U)
  uint32              UbabCfg2Backup;
#if (PMU_ECC_EDC_TST_MAX_FLASHBANKS > 3U)
  uint32              UbabCfg3Backup;
#endif /* PMU_ECC_EDC_TST_MAX_FLASHBANKS > 3U */  
#endif /* PMU_ECC_EDC_TST_MAX_FLASHBANKS > 2U */
#endif /* PMU_ECC_EDC_TST_MAX_FLASHBANKS > 1U */
} PmuEccEdcTst_BackupDataType;

/* Container for a given test set */
typedef struct PmuEccEdcTst_TestDataType
{
  /* Pointer to test signature, location is updated after each test: */
  uint32*                       Signature;
  /* Pointer to test patterns of current flash bank: */
  PmuEccEdcTst_TestPatternType* FlashPattern;
  /* Pointer to Flash ECCRPx SFR, depends on used bank: */
  volatile Ifx_FLASH_ECCRP*     FlashEccrpPtr;
  /* Flash command interface: */
  volatile uint32*              FlashCmd;

} PmuEccEdcTst_TestDataType;

/* Container for parameter set used for ECC helper call */
typedef struct PmuEccEdcTst_EccHlprType
{
  /* SMU command address: */
  volatile Ifx_SMU_CMD*                 SmuCmd;
  /* SMU alarm address: */
  volatile Ifx_SMU_AG*                  SmuAlm;
  /* Access pointer to flash MARP for trap disable/enable: */
  volatile Ifx_FLASH_MARP*              FlashTrapDis;
  /* Pointer to Flash ECCRPx SFR, depends on used bank: */
  volatile Ifx_FLASH_ECCRP*             EccrpPtr;
  /* Data read address A: */
  const PmuEccEdcTst_FlashPageType*     DataAddrA;
  /* Data read address B: */
  const PmuEccEdcTst_FlashPageType*     DataAddrB;
  /* Reference data address: */
  const PmuEccEdcTst_FlashRefPageType*  DataAddrRef;
  /* Alarm value before: */
  uint32                                SmuAlmBefore;
  /* Alarm value after: */
  uint32                                SmuAlmAfter;
  /* Mask of relevant SMU alarms: */
  uint32                                SmuAlmMask;
  /* Flash command interface: */
  volatile uint32*                      FlashCmd;
  /* Result of compare operation (only used for compare page helper): */
  boolean                               PageEqual;
} PmuEccEdcTst_EccHlprType;

/******************************************************************************
**                        Exported object definitions                         *
******************************************************************************/


/******************************************************************************
**                        Imported object definitions                         *
******************************************************************************/


/******************************************************************************
**                        Local object definitions                            *
******************************************************************************/

#define IFX_PMUECCEDCTST_START_SEC_VAR_UNSPECIFIED_ASIL_B 
#include "Ifx_MemMap.h"

/* Counters for unexpected alarms during test execution */
static PmuEccEdcTst_UnexpAlmType PmuEccEdcTst_UnexpAlm;

#define IFX_PMUECCEDCTST_STOP_SEC_VAR_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"

#define IFX_PMUECCEDCTST_START_SEC_VAR_32BIT_ASIL_B
#include "Ifx_MemMap.h"

/* Backup of application trap vector base: */
static uint32   PmuEccEdcTst_BtvBackup;

/* Backup of FLASH0_MARP to restore it in case of an unexpected trap: */
static uint32   PmuEccEdcTst_Flash0MarpBackup;

/* Variable to hold the CRC32 value of PFLASH_MON_ECCEDC_RAMCODE section
   functions in PFlash*/
static uint32   PmuEccEdcTst_PFlashFnCrc32;

/* Variable to hold the CRC32 value of PMUECCEDCTST_TVT_RAMCODE section
   functions in PFlash*/
static uint32   PmuEccEdcTst_TvtCrc32;

#define IFX_PMUECCEDCTST_STOP_SEC_VAR_32BIT_ASIL_B
#include "Ifx_MemMap.h"
/******************************************************************************
**                        Imported function declarations                      *
******************************************************************************/

/******************************************************************************
**                        Local function prototypes                           *
******************************************************************************/
#define IFX_PMUECCEDCTST_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"

static Sl_TstRsltType PmuEccEdcTst_lTestFlsBank
(
  const PmuEccEdcTst_TestDataType* TestData
);

static Sl_TstRsltType PmuEccEdcTst_lTestEccSmuSgnl
(
  const PmuEccEdcTst_TestDataType* TestData
);

static Sl_TstRsltType PmuEccEdcTst_lTestEccSmuSgnlVcw
(
  const PmuEccEdcTst_TestDataType* TestData
);

static Sl_TstRsltType PmuEccEdcTst_lTestEccSmuSgnlSbe
(
  const PmuEccEdcTst_TestDataType* TestData
);

static Sl_TstRsltType PmuEccEdcTst_lTestEccSmuSgnlDbe
(
  const PmuEccEdcTst_TestDataType* TestData
);

static Sl_TstRsltType PmuEccEdcTst_lTestEccSmuSgnlMbe
(
  const PmuEccEdcTst_TestDataType* TestData
);

static Sl_TstRsltType PmuEccEdcTst_lTestEdcCmp
(
  const PmuEccEdcTst_TestDataType* TestData
);

static Sl_TstRsltType PmuEccEdcTst_lTestEccOnlnMon
(
  const PmuEccEdcTst_TestDataType* TestData
);

static Sl_TstRsltType PmuEccEdcTst_lTestEccCorruption
(
  const PmuEccEdcTst_TestDataType* TestData
);

static Sl_TstRsltType PmuEccEdcTst_lTestSbeCorrection
(
  const PmuEccEdcTst_TestDataType* TestData
);

static Sl_TstRsltType PmuEccEdcTst_lTestDbeCorrection
(
  const PmuEccEdcTst_TestDataType* TestData
);

static Sl_TstRsltType PmuEccEdcTst_lTestEccMonAlarm
(
  const PmuEccEdcTst_TestDataType* TestData
);

static Sl_TstRsltType PmuEccEdcTst_lInit
(
  PmuEccEdcTst_BackupDataType* const AlmBackup
);

static Sl_TstRsltType PmuEccEdcTst_lRestore
(
  const PmuEccEdcTst_BackupDataType* const AlmBackup
);

static void PmuEccEdcTst_lCountUnExpectAlm
(
  uint32 CurrAlmStatus
);

LOCAL_INLINE uint32 PmuEccEdcTst_lCalcAlmCounterCrc
(
  void
);

static Sl_TstRsltType PmuEccEdcTst_lSetupTrapHandling
(
  void
);

static void PmuEccEdcTst_lRestoreTrapHandling
(
  void
);

static Sl_TstRsltType PmuEccEdcTst_lRamCalculateandVerifyCrc32
(
  uint32 type
);
#define IFX_PMUECCEDCTST_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"

#define IFX_PMUECCEDCTST_START_SEC_RAM_CODE_ASIL_B
#include "Ifx_MemMap.h"

/* Functions that are copied and executed in SPRAM */
static Sl_TstRsltType PmuEccEdcTst_lComparePageHelper
(
  PmuEccEdcTst_EccHlprType* EccHlprPtr
);

static Sl_TstRsltType PmuEccEdcTst_lEccHelper
(
  PmuEccEdcTst_EccHlprType* EccHlprPtr
);

static Sl_TstRsltType PmuEccEdcTst_lEdcCmpHelper
(
  PmuEccEdcTst_EccHlprType* EccHlprPtr
);
static Sl_TstRsltType PmuEccEdcTst_lEccMonHelper
(
  const PmuEccEdcTst_TestDataType* TestData,
  PmuEccEdcTst_EccHlprType* EccHlprPtr
);

void PmuEccEdcTst_lUnexpTrapHandler
(
  const uint32 TrapClass,
  const uint32 TrapId
);

#define IFX_PMUECCEDCTST_STOP_SEC_RAM_CODE_ASIL_B
#include "Ifx_MemMap.h"

#define IFX_PMUECCEDCTST_START_SEC_TVT_CODE_ASIL_B
#include "Ifx_MemMap.h"
/* Trap table and handlers: */
#ifdef __GNUC__
void PmuEccEdcTst_lTrapVectors
(
  void
);/* __attribute__ ((section(".PMUECCEDCTST_TVT_RAMCODE"))); */
#else
static void PmuEccEdcTst_lTrapVectors
(
  void
);
#endif
#define IFX_PMUECCEDCTST_STOP_SEC_TVT_CODE_ASIL_B
#include "Ifx_MemMap.h"




/******************************************************************************
**                    Local inline function definitions                       *
******************************************************************************/

#define INVOKE_APPL_TRAP_HANDLER(VECTOR, TRAP_ID)                             \
      INVOKE_APPL_TRAP_HANDLER1(VECTOR);                                      \
      INVOKE_APPL_TRAP_HANDLER2(TRAP_ID);                                     

#ifdef __TASKING__
#define INVOKE_APPL_TRAP_HANDLER1(VECTOR)                                     \
    __asm("mov.a a12,%0" : : "d"(VECTOR));

#define INVOKE_APPL_TRAP_HANDLER2(TRAP_ID)                                    \
    __asm("mov d15,%0" : : "d"(TRAP_ID));    /* Restore TIN to D15 */         \
    __asm("rslcx");                          /* Restore Lower Context */      \
    __asm("ji16 a12")               /* Jump to the applications Trap Vector */
#endif

#ifdef __GNUC__
#define INVOKE_APPL_TRAP_HANDLER1(VECTOR)                                     \
    __asm("mov.a %%a12,%0" : : "d"(VECTOR));
#define INVOKE_APPL_TRAP_HANDLER2(TRAP_ID)                                    \
    __asm("mov %%d15,%0" : : "d"(TRAP_ID));  /* Restore TIN to D15 */         \
    __asm("rslcx");                          /* Restore Lower Context */      \
    __asm("ji %a12")                /* Jump to the applications Trap Vector */
#endif

#ifdef _DIABDATA_C_TRICORE_
#if (_DIABDATA_C_TRICORE_ == 1U)
asm volatile void INVOKE_APPL_TRAP_HANDLER1(void *VectorAddress)
{
% reg VectorAddress
  mov.aa %a12, VectorAddress
}

asm volatile void INVOKE_APPL_TRAP_HANDLER2(uint32 TrapId)
{
% reg TrapId
! "%d15"
  mov %d15,TrapId   /* Copy TIN to D15          */  
  rslcx             /* Restore Lower Context    */   
  ji %a12           /* Jump to the applications */
}
#endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
#endif

/******************************************************************************
**                         Function definitions                               *
******************************************************************************/
#define IFX_PMUECCEDCTST_START_SEC_RAM_CODE_ASIL_B
#include "Ifx_MemMap.h"
/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : Sl_TstRsltType PmuEccEdcTst_lEdcCmpHelper                         **
**          (                                                                 **
**            const PmuEccEdcTst_EccHlprType* EccHlprPtr                      **
**          )                                                                 **
**                                                                            **
** Description : Helper routine for the EDC Comparator test. This routine     **
**               must be copied to and executed from RAM! It temporarily      **
**               enables the EDC Comparator Error Injection and performs a    **
**               read access to a given PFLASH location.                      **
**          ENDINIT must have been reset before calling this routine.         **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (int): EccHlprPtr - Pointer test set data                       **
**                                                                            **
** Parameters (out) :                                                         **
**                                                                            **
** Return value :                                                             **
**      PMUECCEDC_SUCCESS           - Test succeeded                          **
**      PMUECCEDC_SMU_CLRALMSTSERR  - Clearing SMU alarm status failed        **
**                                                                            **
*******************************************************************************/
#ifdef __TASKING__
PRAGMA_ALL(OPTIMIZE_0)
#endif
static Sl_TstRsltType PmuEccEdcTst_lEdcCmpHelper
(
  PmuEccEdcTst_EccHlprType* EccHlprPtr
)
{
  volatile uint32 Temp;
  uint32          FlashMarpSave = EccHlprPtr->FlashTrapDis->U;
  uint32          Timeout;
  uint32          AlarmStatusReadback;
  Sl_TstRsltType  Result = PMUECCEDC_NOTEXECUTED;

  /* ECC trap disable */
  EccHlprPtr->FlashTrapDis->B.TRAPDIS = 1U;

  /* get current alarm status before access */
  EccHlprPtr->SmuAlmBefore = EccHlprPtr->SmuAlm->U;

  /* Send an ALARM CLEAR command to the SMU Control Interface   */
  EccHlprPtr->SmuCmd->U = 5U;

  /* Clear all SMU Group 2, Alarms */
  EccHlprPtr->SmuAlm->U = PMUT_SMU_ALARM_SETALL;

  /* Check if SMU alarms were really cleared: */
  Timeout = 0U;
  do
  {
    AlarmStatusReadback = 
  (uint32)(EccHlprPtr->SmuAlm->U & PMUT_SMU_ALARM_SETALL);
    Timeout++;
  } while ((Timeout < PMUT_SMU_AGSTATUS_TIMEOUT) &&
           (AlarmStatusReadback != 0U));
  if (0U != AlarmStatusReadback)
  {
    Result = PMUECCEDC_SMU_CLRALMSTSERR;
  } /* if (0U != AlarmStatusReadback) */
  else
  {
    /* Enable PFLASH0 ECC Comparator Error Injection */
    EccHlprPtr->EccrpPtr->B.EDCERRINJ = 1U;

    /* Read back value to ensure error injection is switched on when  
     * reading from flash */
    Temp = EccHlprPtr->EccrpPtr->U;

    /* Read Access to PFLASH to set comparator alarm reason */
    Temp = EccHlprPtr->DataAddrA->Data[0U];

    /* Give a short delay */
    Temp = PMUT_SMU_ALM_TIMEOUT2;
    while (Temp > 0U)
    {
      Temp--;
      if (((EccHlprPtr->SmuAlm->U) & (EccHlprPtr->SmuAlmMask)) != 0U)
      {
        break;              /* any alarm seen */
      } /* if ((EccHlprPtr->SmuAlm->U && EccHlprPtr->SmuAlmMask) != 0U) */
    } /* while (Temp > 0U) */

    /* Get current alarm status after access */
    EccHlprPtr->SmuAlmAfter = EccHlprPtr->SmuAlm->U;

    /* Disable PFLASH0 ECC Comparator Error Injection */
    EccHlprPtr->EccrpPtr->B.EDCERRINJ = 0U;

    /* Read back value to ensure error injection is switched off when reading
     * again from flash */
    Temp = EccHlprPtr->EccrpPtr->U;

    /* Read Access to different location in PFLASH (to avoid cache access) to
     * clear comparator alarm reason */
    Temp = EccHlprPtr->DataAddrB->Data[0U];

    /* flash clear status */
    *EccHlprPtr->FlashCmd = PMUT_FSI_CMD_FA;

    /* Send an ALARM CLEAR command to the SMU Control Interface   */
    EccHlprPtr->SmuCmd->U = 5U;

    /* Clear all SMU Group 2, Alarms */
    EccHlprPtr->SmuAlm->U = PMUT_SMU_ALARM_SETALL;

    /* Check if SMU alarms were really cleared: */
    Timeout = 0U;
    do
    {
      AlarmStatusReadback = 
    (uint32)(EccHlprPtr->SmuAlm->U & PMUT_SMU_ALARM_SETALL);
      Timeout++;
    } while ((Timeout < PMUT_SMU_AGSTATUS_TIMEOUT) &&
             (AlarmStatusReadback != 0U));
    if (0U != AlarmStatusReadback)
    {
      Result = PMUECCEDC_SMU_CLRALMSTSERR;
    } /* if (0U != AlarmStatusReadback) */
    else
    {
      Result = PMUECCEDC_SUCCESS;
    } /* if (0U == AlarmStatusReadback) */
  } /* if (0U == AlarmStatusReadback) */

  /* restore ECC trap handling */
  EccHlprPtr->FlashTrapDis->U = FlashMarpSave;

  return Result;
} /* PmuEccEdcTst_lEdcCmpHelper */
#ifdef __TASKING__
PRAGMA_ALL(OPTIMIZE_RESTORE)
#endif

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : Sl_TstRsltType PmuEccEdcTst_lEccMonHelper                         **
**          (                                                                 **
**            const PmuEccEdcTst_TestDataType* TestData,                      **
**            PmuEccEdcTst_EccHlprType* EccHlprPtr                            **
**          )                                                                 **
**                                                                            **
** Description : Helper routine for the EDC Online Monitor test. This routine **
**               must be copied to and executed from RAM! It temporarily      **
**               disables the PFLASH ECC correction and reads the single bit  **
**               error pages from all pattern sets.                           **
**                                                                            **
**          ENDINIT must have been reset before calling this routine.         **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (int): TestData - Pointer to test data set                      **
**                   EccHlprPtr - Pointer test set data                       **
** Parameters (out) :                                                         **
**                                                                            **
** Return value :                                                             **
**      PMUECCEDC_SUCCESS           - Test succeeded                          **
**      PMUECCEDC_SMU_CLRALMSTSERR  - Clearing SMU alarm status failed        **
**                                                                            **
*******************************************************************************/
#ifdef __TASKING__
PRAGMA_ALL(OPTIMIZE_0)
#endif
static Sl_TstRsltType PmuEccEdcTst_lEccMonHelper
(
  const PmuEccEdcTst_TestDataType* TestData,
  PmuEccEdcTst_EccHlprType* EccHlprPtr
)
{
  volatile uint32           Temp;
  volatile Ifx_FLASH_ECCRP* EccrpPtr      = TestData->FlashEccrpPtr;
  uint32                    FlashMarpSave = EccHlprPtr->FlashTrapDis->U;
  uint32                    Timeout;
  uint32                    AlarmStatusReadback;
  Sl_TstRsltType            Result = PMUECCEDC_NOTEXECUTED;

  /* ECC trap disable */
  EccHlprPtr->FlashTrapDis->B.TRAPDIS = 1U;

  /* get current alarm status before access */
  EccHlprPtr->SmuAlmBefore = EccHlprPtr->SmuAlm->U;

  /* Send an ALARM CLEAR command to the SMU Control Interface   */
  EccHlprPtr->SmuCmd->U = 5U;

  /* Clear all SMU Group 2, Alarms */
  EccHlprPtr->SmuAlm->U = PMUT_SMU_ALARM_SETALL;

  /* Check if SMU alarms were really cleared: */
  Timeout = 0U;
  do
  {
    AlarmStatusReadback = 
  (uint32)(EccHlprPtr->SmuAlm->U & PMUT_SMU_ALARM_SETALL);
    Timeout++;
  } while ((Timeout < PMUT_SMU_AGSTATUS_TIMEOUT) &&
           (AlarmStatusReadback != 0U));
  if (0U != AlarmStatusReadback)
  {
    Result = PMUECCEDC_SMU_CLRALMSTSERR;
  } /* if (0U != AlarmStatusReadback) */
  else
  {
    /* Disable PFLASH0 ECC Error Correction */
    EccrpPtr->B.ECCORDIS = 1U;

    /* Read back to ensure properly in effect */
    Temp = EccrpPtr->U;

    /* Read selected Single Bit Error FLASH Page: */
    Temp = EccHlprPtr->DataAddrA->Data[0U];

    /* Give a short delay */
    Temp = PMUT_SMU_ALM_TIMEOUT2;
    while (Temp > 0U)
    {
      Temp--;
      if (((EccHlprPtr->SmuAlm->U) & (EccHlprPtr->SmuAlmMask)) != 0U)
      {
        break;              /* any alarm seen */
      } /* if ((EccHlprPtr->SmuAlm->U && EccHlprPtr->SmuAlmMask) != 0U) */
    } /* while (Temp > 0U) */

    /* Re-enable PFLASH0 ECC Error Correction */
    EccrpPtr->B.ECCORDIS = 0U;

    /* Read back to ensure properly switched back on return */
    Temp = EccrpPtr->U;

    /* Read again from test pattern to clear PMU internal error flag which is
     * only updated after the next flash access; this prevents the SMU alarm
     * being set again after it is cleared.
     * Read from different page ensure value is not cached in the flash internal
     * cache line: */
    Temp = EccHlprPtr->DataAddrB->Data[0U];

    /* Get current alarm status after access */
    EccHlprPtr->SmuAlmAfter = EccHlprPtr->SmuAlm->U;

    /* Flash clear status */
    *EccHlprPtr->FlashCmd = PMUT_FSI_CMD_FA;

    /* Send an ALARM CLEAR command to the SMU Control Interface   */
    EccHlprPtr->SmuCmd->U = 5U;

    /* Clear all SMU Group 2, Alarms */
    EccHlprPtr->SmuAlm->U = PMUT_SMU_ALARM_SETALL;

    /* Check if SMU alarms were really cleared: */
    Timeout = 0U;
    do
    {
      AlarmStatusReadback = 
    (uint32)(EccHlprPtr->SmuAlm->U & PMUT_SMU_ALARM_SETALL);
      Timeout++;
    } while ((Timeout < PMUT_SMU_AGSTATUS_TIMEOUT) &&
             (AlarmStatusReadback != 0U));
    if (0U != AlarmStatusReadback)
    {
      Result = PMUECCEDC_SMU_CLRALMSTSERR;
    } /* if (0U != AlarmStatusReadback) */
    else
    {
      Result = PMUECCEDC_SUCCESS;
    } /* if (0U == AlarmStatusReadback) */
  } /* if (0U == AlarmStatusReadback) */

  /* ECC trap restore  */
  EccHlprPtr->FlashTrapDis->U = FlashMarpSave;

  return Result;
} /* PmuEccEdcTst_lEccMonHelper */
#ifdef __TASKING__
PRAGMA_ALL(OPTIMIZE_RESTORE)
#endif

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : Sl_TstRsltType PmuEccEdcTst_lEccHelper                            **
**          (                                                                 **
**            PmuEccEdcTst_EccHlprType* EccHlprPtr                            **
**          )                                                                 **
**                                                                            **
** Description : Helper routine for the ECC->SMU signaling test. This         **
**               routine must be copied to and executed from RAM! It          **
**               executes a read access to the given code word in PFLASH      **
**          Keep OPTIMIZE(0) to disable common sub expression optimization    **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (int): EccHlprPtr - Pointer test set data                       **
**                                                                            **
** Parameters (out) :  None                                                   **
**                                                                            **
** Return value :                                                             **
**      PMUECCEDC_SUCCESS           - Test succeeded                          **
**      PMUECCEDC_SMU_CLRALMSTSERR  - Clearing SMU alarm status failed        **
**                                                                            **
*******************************************************************************/
#ifdef __TASKING__
PRAGMA_ALL(OPTIMIZE_0)
#endif
static Sl_TstRsltType PmuEccEdcTst_lEccHelper
(
  PmuEccEdcTst_EccHlprType* EccHlprPtr
)
{
  volatile uint32 Temp;
  uint32          AlarmStatusReadback;
  uint32          Timeout;
  uint32          FlashMarpSave = EccHlprPtr->FlashTrapDis->U;
  Sl_TstRsltType  Result = PMUECCEDC_NOTEXECUTED;

  /* ECC trap disable */
  EccHlprPtr->FlashTrapDis->B.TRAPDIS = 1U;

  /* get current alarm status before access */
  EccHlprPtr->SmuAlmBefore = EccHlprPtr->SmuAlm->U;

  /* Send an ALARM CLEAR command to the SMU Control Interface   */
  EccHlprPtr->SmuCmd->U = 5U;

  /* Clear all SMU Group 2, Alarms */
  EccHlprPtr->SmuAlm->U = PMUT_SMU_ALARM_SETALL;

  /* Check if SMU alarms were really cleared: */
  Timeout = 0U;
  do
  {
    AlarmStatusReadback = 
  (uint32)(EccHlprPtr->SmuAlm->U & PMUT_SMU_ALARM_SETALL);
    Timeout++;
  } while ((Timeout < PMUT_SMU_AGSTATUS_TIMEOUT) &&
           (AlarmStatusReadback != 0U));
  if (0U != AlarmStatusReadback)
  {
    Result = PMUECCEDC_SMU_CLRALMSTSERR;
  } /* if (0U != AlarmStatusReadback) */
  else
  {
    /* Read access to Pattern */
    Temp = EccHlprPtr->DataAddrA->Data[0U];

    /* Give a short delay */
    Temp = PMUT_SMU_ALM_TIMEOUT2;
    while (Temp > 0U)
    {
      Temp--;
      if ((EccHlprPtr->SmuAlm->U & EccHlprPtr->SmuAlmMask) != 0U)
      {
        break;              /* any alarm seen */
      } /* if ((EccHlprPtr->SmuAlm->U & EccHlprPtr->SmuAlmMask) != 0u) */
    } /* while (Temp > 0u) */

    /* get current alarm status after access */
    EccHlprPtr->SmuAlmAfter = EccHlprPtr->SmuAlm->U;

    /* flash clear status */
    *EccHlprPtr->FlashCmd = PMUT_FSI_CMD_FA;

    /* Send an ALARM CLEAR command to the SMU Control Interface   */
    EccHlprPtr->SmuCmd->U = 5U;

    /* Clear all SMU Group 2, Alarms */
    EccHlprPtr->SmuAlm->U = PMUT_SMU_ALARM_SETALL;

    /* Check if SMU alarms were really cleared: */
    Timeout = 0U;
    do
    {
      AlarmStatusReadback = 
    (uint32)(EccHlprPtr->SmuAlm->U & PMUT_SMU_ALARM_SETALL);
      Timeout++;
    } while ((Timeout < PMUT_SMU_AGSTATUS_TIMEOUT) &&
             (AlarmStatusReadback != 0U));
    if (0U != AlarmStatusReadback)
    {
      Result = PMUECCEDC_SMU_CLRALMSTSERR;
    } /* if (0U != AlarmStatusReadback) */
    else
    {
      Result = PMUECCEDC_SUCCESS;
    } /* if (0U != AlarmStatusReadback) */
  } /* if (0U == AlarmStatusReadback) */

  /* restore ECC trap handling */
  EccHlprPtr->FlashTrapDis->U = FlashMarpSave;

  return Result;
} /* PmuEccEdcTst_lEccHelper */
#ifdef __TASKING__
PRAGMA_ALL(OPTIMIZE_RESTORE)
#endif

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : Sl_TstRsltType PmuEccEdcTst_lComparePageHelper                    **
**          (                                                                 **
**            PmuEccEdcTst_EccHlprType* EccHlprPtr                            **
**          )                                                                 **
**                                                                            **
** Description : Checks if the content of a given PFLASH page is equal to     **
**               an expected content (usally in RAM).                         **
** Note(s): PmuEccEdcTst_lCompareWordline compares PMUT_WORDS_PER_PAGE number **
**          of 32bit words (using 32bit accesses).                            **
**          This routine shall be copied to RAM before being executed to      **
**          avoid additional SMU alarms caused by instruction fetches from    **
**          PFLASH.                                                           **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) : EccHlprPtr - Test data containing the page addresses to  **
**                                compare                                     **
**                                                                            **
** Parameters (out) : EccHlpPtr - The result of comparison is stored to       **
**                                EccHlprPtr->PageEqual in case PMUECCEDC_    **
**                                SUCCESS is returned                         **
**                                                                            **
** Return value :                                                             **
**      PMUECCEDC_SUCCESS           - Test succeeded                          **
**      PMUECCEDC_SMU_CLRALMSTSERR  - Clearing SMU alarm status failed        **
**                                                                            **
*******************************************************************************/
#ifdef __TASKING__
PRAGMA_ALL(OPTIMIZE_0)
#endif
static Sl_TstRsltType PmuEccEdcTst_lComparePageHelper
(
  PmuEccEdcTst_EccHlprType* EccHlprPtr
)
{
  uint32          i;
  uint32          RefIdx = 0U;
  uint32          Timeout;
  uint32          AlarmStatusReadback;
  boolean         CmpResult = TRUE;
  Sl_TstRsltType  Result = PMUECCEDC_NOTEXECUTED;
  volatile uint32 Temp;
  uint32          FlashMarpSave = EccHlprPtr->FlashTrapDis->U;

  /* ECC trap disable */
  EccHlprPtr->FlashTrapDis->B.TRAPDIS = 1U;

  /* Get current alarm status before access */
  EccHlprPtr->SmuAlmBefore = EccHlprPtr->SmuAlm->U;

  /* Send an ALARM CLEAR command to the SMU Control Interface   */
  EccHlprPtr->SmuCmd->U = 5U;

  /* Clear all SMU Group 2, Alarms */
  EccHlprPtr->SmuAlm->U = PMUT_SMU_ALARM_SETALL;

  /* Check if SMU alarms were really cleared: */
  Timeout = 0U;
  do
  {
    AlarmStatusReadback = 
  (uint32)(EccHlprPtr->SmuAlm->U & PMUT_SMU_ALARM_SETALL);
    Timeout++;
  } while ((Timeout < PMUT_SMU_AGSTATUS_TIMEOUT) &&
           (AlarmStatusReadback != 0U));
  if (0U != AlarmStatusReadback)
  {
    Result = PMUECCEDC_SMU_CLRALMSTSERR;
  } /* if (0U != AlarmStatusReadback) */
  else
  {
    /* Read data set and compare */
    for (i = 0U; i < PMUT_WORDS_PER_PAGE; i++)
    {
      if (EccHlprPtr->DataAddrA->Data[i] !=
          EccHlprPtr->DataAddrRef->Data[RefIdx])
      {
        CmpResult = FALSE;
        break;
      } /* if (EccHlprPtr->DataAddrA->Data[i] !=
               EccHlprPtr->DataAddrRef->Data[RefIdx]) */
      RefIdx = 1U;
    } /* for (i = 0u; i < PMUT_WORDS_PER_PAGE; i++) */

    /* Give a short delay */
    Temp = PMUT_SMU_ALM_TIMEOUT2;
    while (Temp > 0U)
    {
      Temp--;
      if (((EccHlprPtr->SmuAlm->U) & (EccHlprPtr->SmuAlmMask)) != 0U)
      {
        break;              /* any alarm seen */
      } /* if ((EccHlprPtr->SmuAlm->U && EccHlprPtr->SmuAlmMask) != 0U) */
    } /* while (Temp > 0U) */

    /* Get current alarm status after access */
    EccHlprPtr->SmuAlmAfter = EccHlprPtr->SmuAlm->U;

    /* Flash clear status */
    *EccHlprPtr->FlashCmd = PMUT_FSI_CMD_FA;

    /* Send an ALARM CLEAR command to the SMU Control Interface   */
    EccHlprPtr->SmuCmd->U = 5U;

    /* Clear all SMU Group 2, Alarms */
    EccHlprPtr->SmuAlm->U = PMUT_SMU_ALARM_SETALL;

    /* Check if SMU alarms were really cleared: */
    Timeout = 0U;
    do
    {
      AlarmStatusReadback = 
    (uint32)(EccHlprPtr->SmuAlm->U & PMUT_SMU_ALARM_SETALL);
      Timeout++;
    } while ((Timeout < PMUT_SMU_AGSTATUS_TIMEOUT) &&
             (AlarmStatusReadback != 0U));
    if (0U != AlarmStatusReadback)
    {
      Result = PMUECCEDC_SMU_CLRALMSTSERR;
    } /* if (0U != AlarmStatusReadback) */
    else
    {
      Result = PMUECCEDC_SUCCESS;
      EccHlprPtr->PageEqual = CmpResult;
    } /* if (0U == AlarmStatusReadback) */
  } /* if (0U == AlarmStatusReadback) */

  /* Restore ECC trap handling */
  EccHlprPtr->FlashTrapDis->U = FlashMarpSave;

  return Result;
} /* PmuEccEdcTst_lComparePageHelper */
#ifdef __TASKING__
PRAGMA_ALL(OPTIMIZE_RESTORE)
#endif

#ifdef __TASKING__
PRAGMA_ALL(OPTIMIZE_0)
#endif
/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : void PmuEccEdcTst_lUnexpTrapHandler                               **
**          (                                                                 **
**            const uint32 TrapClass,                                         **
**            const uint32 TrapId                                             **
**          )                                                                 **
**                                                                            **
** Description : Handles all traps that are raised while the PMU ECC/EDC test **
**               is executing. This function (as well as the trap table) need **
**               to be copied to SPRAM to be able to handle traps even while  **
**               the PFLASH is not accessible due to testing.                 **
**               This trap handler brings the PFLASH into a defined state, so **
**               that it is ensured that code execution from PFLASH is        **
**               possible again, to cover the potential case where a trap is  **
**               raised while the PmuEccEdcTst is executing from SRAM and     **
**               PFLASH is temporarily not accessible. After PFLASH           **
**               accessibility has been restored, program execution is        **
**               transferred to the application trap table. The application   **
**               trap handler must not continue execution of the PmuEccEdc    **
**               test as the PFLASH might be in an invalid state for the test **
**               after the trap was handled.                                  **
**               This function implements only limited error handling (e.g.   **
**               in case an invalid Core ID is read) because there is no      **
**               chance to handle such errors correctly.                      **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) : TrapClass - Trap class of the trap that is to be handled **
**                   TrapId - Trap Identification Number (TIN) of the trap    **
**                            that is to be handled                           **
**                                                                            **
** Parameters (out):                                                          **
**                                                                            **
** Return value : None                                                        **
**                                                                            **
*******************************************************************************/
void PmuEccEdcTst_lUnexpTrapHandler(const uint32 TrapClass,
                                           const uint32 TrapId)
{
  uint32          ApplTrapVector;

  /* Variables for Reset / Set ENDINIT functionality: */
  uint32          CoreId;
  uint32          NewValCon0;
  uint32          NewPw;          /* next password to be used */
  uint32          NewRel;         /* next reload value to be used */
  uint32          ValTemp1;       /* Required due to MISRA */
  uint32          ValTemp2;       /* Required due to MISRA */
  uint32          WdtTimAndPw = 0U;
  volatile uint32 Dummy = 0U;          /* ensure readback */
  volatile Ifx_SCU_WDTCPU_CON0* ScuWdtcon0Ptr;
  volatile Ifx_SCU_WDTCPU_SR*   ScuSsrPtr;

  /* *** Reset ENDINIT without using function calls: *** */

  /* Read the core ID: */
  CoreId = ((uint32)MFCR(CPU_CORE_ID) & (uint32)PMUT_CORE_ID_MASK);
  switch(CoreId)
  {
  case PMUT_CPU_CORE0:
    ScuWdtcon0Ptr = &SCU_WDTCPU0_CON0;
    ScuSsrPtr = &SCU_WDTCPU0_SR;
    break;

#if (CHIP_ID == 26U) || (CHIP_ID == 27U) || (CHIP_ID == 29U)
  case PMUT_CPU_CORE1:
    ScuWdtcon0Ptr = &SCU_WDTCPU1_CON0;
    ScuSsrPtr = &SCU_WDTCPU1_SR;
    break;

#if (CHIP_ID == 27U) || (CHIP_ID == 29U)
  case PMUT_CPU_CORE2:
    ScuWdtcon0Ptr = &SCU_WDTCPU2_CON0;
    ScuSsrPtr = &SCU_WDTCPU2_SR;
    break;
#endif /* (CHIP_ID == 27) || (CHIP_ID == 29) */
#endif /* (CHIP_ID == 26) || (CHIP_ID == 27) || (CHIP_ID == 29) */

  default:
    ScuWdtcon0Ptr = (volatile Ifx_SCU_WDTCPU_CON0*)(volatile void*)NULL_PTR;
    ScuSsrPtr = (volatile Ifx_SCU_WDTCPU_SR*)(volatile void*)NULL_PTR;
    break;
  }

  /* Actual ENDINIT reset: */
  if (NULL_PTR != ScuWdtcon0Ptr)
  {
    /* Save old SCU_WDTCPU_CONx value */
    NewValCon0  = ScuWdtcon0Ptr->U;

    /* Get valid next password */
    NewPw = NewValCon0 & PMUT_WDT_PASSWORD_MASK;

    /* First generate proper password write value
       (include PW Bit8-15 and inverted PW Bit 2-7) */
    NewPw = (NewPw & PMUT_WDT_PASSWORD_UPPER_MASK) |
            ((~(NewPw & PMUT_WDT_PASSWORD_LOWER_MASK)) &
             PMUT_WDT_PASSWORD_LOWER_MASK);

    /* Additionally auto sequence password enabled ? */
    if (ScuSsrPtr->B.PAS != 0u)
    {
       /*  Modify password with expected password by calculating new 14-bit LFSR
        *  with characteristic polynomial x14+x13+x12+x2+1.
        */
      uint32 lfsr = NewValCon0;
      uint32 bit  = ((lfsr>>1) ^ (lfsr>>11) ^ (lfsr>>12) ^ (lfsr>>13)) &
                     0x0004u;
      NewPw       = (((lfsr << 1) | bit) & PMUT_WDT_PASSWORD_MASK);
    } /* if (ScuSsrPtr->B.PAS != 0u) */

    /* get valid next timer reload */
    NewRel = NewValCon0 & PMUT_WDT_RELOAD_MASK;

    /* Timer check enabled ? */
    if (ScuSsrPtr->B.TCS != 0u)
    {
      NewRel = (uint32)((~(uint32)ScuSsrPtr->B.TIM) << 16);
    } /*if (ScuSsrPtr->B.TCS != 0u) */

    /* Build required password WDTCON0 value */
    NewValCon0 =  ((NewRel) |              /* New reload value  */
                   (NewPw)  |              /* New Password */
                   (1u));                  /* Clear LCK, keep ENDINIT set */

    /* Read and save current timer and password to be restored with
     * SetENDINIT
     */
    ValTemp1 = ScuSsrPtr->U & (uint32)PMUT_WDT_RELOAD_MASK;
    ValTemp2 = ScuWdtcon0Ptr->U & (uint32)PMUT_WDT_PASSWORD_MASK;
    WdtTimAndPw = ValTemp1 | ValTemp2;

    ScuWdtcon0Ptr->U  = NewValCon0;        /* Password access to unlock */

    NewValCon0 &= ~PMUT_WDT_STATUS_MASK;   /* Clear ENDINIT and LCK Bit */
    NewValCon0 |= 0x2u;                    /* Set LCK Bit */

    ScuWdtcon0Ptr->U = NewValCon0;  /* Write access and lock for Timeout mode */

    /* Read back to ensure protection release is executed */
    Dummy = ScuWdtcon0Ptr->U;
    
    UNUSED_PARAMETER(Dummy)
  } /* if ((uint32)(Wdt + 1) < SRAM_WDT_MAX_CPUWDT) */

  /* --- End of Reset ENDINIT --- */

  /* Restore FLASH0_MARP: */
  FLASH0_MARP.U = PmuEccEdcTst_Flash0MarpBackup;

  /* Unconditionally disable EDC error injection for all available banks: */
  FLASH0_ECCRP0.B.EDCERRINJ = 0U;
#if (PMU_ECC_EDC_TST_MAX_FLASHBANKS > 1U)
  FLASH0_ECCRP1.B.EDCERRINJ = 0U;
#if (PMU_ECC_EDC_TST_MAX_FLASHBANKS > 2U)
  FLASH0_ECCRP2.B.EDCERRINJ = 0U;
#if (PMU_ECC_EDC_TST_MAX_FLASHBANKS > 3U)
  FLASH0_ECCRP3.B.EDCERRINJ = 0U;
#endif
#endif
#endif

  /* --- Set ENDINIT without using function call: --- */

  if (NULL_PTR != ScuWdtcon0Ptr)
  {
    /* Save old SCU_WDTCPU_CONx value */
    NewValCon0  = ScuWdtcon0Ptr->U;

    /* Get valid next password */
    NewPw = NewValCon0 & PMUT_WDT_PASSWORD_MASK;

    /* First generate proper password write value
       (include PW Bit8-15 and inverted PW Bit 2-7) */
    NewPw = (NewPw & PMUT_WDT_PASSWORD_UPPER_MASK) |
            ((~(NewPw & PMUT_WDT_PASSWORD_LOWER_MASK)) &
             PMUT_WDT_PASSWORD_LOWER_MASK);

    /* Additionally auto sequence password enabled ? */
    if (ScuSsrPtr->B.PAS != 0u)
    {
       /*  Modify password with expected password by calculating new 14-bit LFSR
        *  with characteristic polynomial x14+x13+x12+x2+1.
        */
      uint32 lfsr = NewValCon0;
      uint32 bit  = ((lfsr>>1) ^ (lfsr>>11) ^ (lfsr>>12) ^ (lfsr>>13)) &
                     0x0004u;
      NewPw       = (((lfsr << 1) | bit) & PMUT_WDT_PASSWORD_MASK);
    } /* if (ScuSsrPtr->B.PAS != 0u) */

    /* Get valid next timer reload */
    NewRel = NewValCon0 & PMUT_WDT_RELOAD_MASK;

    /* Timer check enabled ? */
    if (ScuSsrPtr->B.TCS != 0u)
    {
      NewRel = (uint32)((~(uint32)ScuSsrPtr->B.TIM) << 16);
    } /*if (ScuSsrPtr->B.TCS != 0u) */

    /* Build required password WDTCON0 value */
    NewValCon0  =  ((NewRel) |             /* New reload value  */
                    (NewPw)  |             /* New Password */
                    (1u));                 /* Clear LCK, keep ENDINIT set */

    ScuWdtcon0Ptr->U = NewValCon0;         /* Unlock with password access */

    /* Clear timer reload and restore saved and corrected reload value */
    NewValCon0 &= ~PMUT_WDT_RELOAD_MASK;

    /* Set timer value back to prior value and add ticks during timeout mode */
    NewValCon0 |= (WdtTimAndPw +
                   ((ScuSsrPtr->U & (uint32)PMUT_WDT_RELOAD_MASK) -
                   (uint32)SDWT_TIMEOUT_MODE_RELOAD));

    /* Prepare old password to be restored with modify access*/
    NewValCon0 &= ~PMUT_WDT_PASSWORD_MASK;
    NewValCon0 |= (WdtTimAndPw &
                   (uint32)PMUT_WDT_PASSWORD_UPPER_MASK) |
                   ((~(WdtTimAndPw &
                       (uint32)PMUT_WDT_PASSWORD_LOWER_MASK))
                   & (uint32)PMUT_WDT_PASSWORD_LOWER_MASK);

    /* Prepare modify & lock access */
    NewValCon0 |= 3u;                      /* Set LCK and ENDINIT Bit */
    ScuWdtcon0Ptr->U = NewValCon0;         /* Write modify access and lock */

    /* Read back to ensure protection release is executed */
    Dummy = ScuWdtcon0Ptr->U;
  } /* if ((uint32)(Wdt + 1) < SRAM_WDT_MAX_CPUWDT) */

  /* --- End of Set ENDINIT --- */

  /* Code execution from PFLASH is now safe again; jump to application trap
   * handler.
   * Note: The original value of the stack pointer (A10) is not restored because
   *       it is reloaded from ISP at the next occurrence of a trap anyhow.
   */
  /* - Calculate application Trap Vector address:                             */
  ApplTrapVector = PmuEccEdcTst_BtvBackup;
  ApplTrapVector += PMUT_TRAP_VECTOR_SIZE * TrapClass;
  /* - Invoke application trap vector: */
  INVOKE_APPL_TRAP_HANDLER((void *)ApplTrapVector, TrapId);
} /* PmuEccEdcTst_lUnexpTrapHandler */
#ifdef __TASKING__
PRAGMA_ALL(OPTIMIZE_RESTORE)
#endif

#define IFX_PMUECCEDCTST_STOP_SEC_RAM_CODE_ASIL_B
#include "Ifx_MemMap.h"

#define IFX_PMUECCEDCTST_START_SEC_TVT_CODE_ASIL_B
#include "Ifx_MemMap.h"

#ifdef __TASKING__
static void PmuEccEdcTst_lTrapVectors(void)
{
  __asm (".align 256");
  /* Class 0, MMU Traps: */
  __asm("svlcx");           /* Save Lower Context */
  __asm("mov16   d4,#0");   /* Store Trap Class   */
  __asm("mov16   d5,d15");  /* Store Trap ID      */
  /* Load trap handler address: */
  __asm("movh.a  a15, #@HIS(PmuEccEdcTst_lUnexpTrapHandler)");
  __asm("lea     a15,[a15]@LOS(PmuEccEdcTst_lUnexpTrapHandler)");
  /* Jump to the trap handler in SPRAM:           */
  __asm("ji      a15");

  __asm (".align 32");
  /* Class 1, Internal Protection Traps */
  __asm("svlcx");           /* Save Lower Context */
  __asm("mov16   d4,#1");   /* Store Trap Class   */
  __asm("mov16   d5,d15");  /* Store Trap ID      */
  /* Load trap handler address: */
  __asm("movh.a  a15, #@HIS(PmuEccEdcTst_lUnexpTrapHandler)");
  __asm("lea     a15,[a15]@LOS(PmuEccEdcTst_lUnexpTrapHandler)");
  /* Jump to the trap handler in SPRAM:           */
  __asm("ji      a15");

  __asm (".align 32");
  /* Class 2, Instruction Error Traps */
  __asm("svlcx");           /* Save Lower Context */
  __asm("mov16   d4,#2");   /* Store Trap Class   */
  __asm("mov16   d5,d15");  /* Store Trap ID      */
  /* Load trap handler address: */
  __asm("movh.a  a15, #@HIS(PmuEccEdcTst_lUnexpTrapHandler)");
  __asm("lea     a15,[a15]@LOS(PmuEccEdcTst_lUnexpTrapHandler)");
  /* Jump to the trap handler in SPRAM:           */
  __asm("ji      a15");

  __asm (".align 32");
  /* Class 3, Context Management Traps */
  __asm("svlcx");           /* Save Lower Context */
  __asm("mov16   d4,#3");   /* Store Trap Class   */
  __asm("mov16   d5,d15");  /* Store Trap ID      */
  /* Load trap handler address: */
  __asm("movh.a  a15, #@HIS(PmuEccEdcTst_lUnexpTrapHandler)");
  __asm("lea     a15,[a15]@LOS(PmuEccEdcTst_lUnexpTrapHandler)");
  /* Jump to the trap handler in SPRAM:           */
  __asm("ji      a15");

  __asm (".align 32");
  /* Class 4, System Bus and Peripheral Error Traps */
  __asm("svlcx");           /* Save Lower Context */
  __asm("mov16   d4,#4");   /* Store Trap Class   */
  __asm("mov16   d5,d15");  /* Store Trap ID      */
  /* Load trap handler address: */
  __asm("movh.a  a15, #@HIS(PmuEccEdcTst_lUnexpTrapHandler)");
  __asm("lea     a15,[a15]@LOS(PmuEccEdcTst_lUnexpTrapHandler)");
  /* Jump to the trap handler in SPRAM:           */
  __asm("ji      a15");

  __asm (".align 32");
  /* Class 5, Assertion Traps */
  __asm("svlcx");           /* Save Lower Context */
  __asm("mov16   d4,#5");   /* Store Trap Class   */
  __asm("mov16   d5,d15");  /* Store Trap ID      */
  /* Load trap handler address: */
  __asm("movh.a  a15, #@HIS(PmuEccEdcTst_lUnexpTrapHandler)");
  __asm("lea     a15,[a15]@LOS(PmuEccEdcTst_lUnexpTrapHandler)");
  /* Jump to the trap handler in SPRAM:           */
  __asm("ji      a15");

  __asm (".align 32");
  /* Class 6, System Call Trap */
  __asm("svlcx");           /* Save Lower Context */
  __asm("mov16   d4,#6");   /* Store Trap Class   */
  __asm("mov16   d5,d15");  /* Store Trap ID      */
  /* Load trap handler address: */
  __asm("movh.a  a15, #@HIS(PmuEccEdcTst_lUnexpTrapHandler)");
  __asm("lea     a15,[a15]@LOS(PmuEccEdcTst_lUnexpTrapHandler)");
  /* Jump to the trap handler in SPRAM:           */
  __asm("ji      a15");

  __asm (".align 32");
  /* Class 7, Non Maskable Interrupt Traps */
  __asm("svlcx");           /* Save Lower Context */
  __asm("mov16   d4,#7");   /* Store Trap Class   */
  __asm("mov16   d5,d15");  /* Store Trap ID      */
  /* Load trap handler address: */
  __asm("movh.a  a15, #@HIS(PmuEccEdcTst_lUnexpTrapHandler)");
  __asm("lea     a15,[a15]@LOS(PmuEccEdcTst_lUnexpTrapHandler)");
  /* Jump to the trap handler in SPRAM:           */
  __asm("ji      a15");
}
#endif  /* __TASKING__ */

#ifdef __GNUC__

void PmuEccEdcTst_lTrapVectors (void)
{
  __asm (".align 8");
  /* Class 0, MMU Traps: */
  __asm("svlcx");           /* Save Lower Context */
  __asm("mov   %d4,0");     /* Store Trap Class   */
  __asm("mov   %d5,%d15");  /* Store Trap ID      */
  /* Load trap handler address: */
  __asm("movh.a  %a15,hi:PmuEccEdcTst_lUnexpTrapHandler");
  __asm("lea     %a15,[%a15]lo:PmuEccEdcTst_lUnexpTrapHandler");
  /* Jump to the trap handler in SPRAM:           */
  __asm("ji      %a15");

  __asm (".align 5");
  /* Class 1, Internal Protection Traps */
  __asm("svlcx");           /* Save Lower Context */
  __asm("mov   %d4,1");     /* Store Trap Class   */
  __asm("mov   %d5,%d15");  /* Store Trap ID      */
  /* Load trap handler address: */
  __asm("movh.a  %a15,hi:PmuEccEdcTst_lUnexpTrapHandler");
  __asm("lea     %a15,[%a15]lo:PmuEccEdcTst_lUnexpTrapHandler");
  /* Jump to the trap handler in SPRAM:           */
  __asm("ji      %a15");

  __asm (".align 5");
  /* Class 2, Instruction Error Traps */
  __asm("svlcx");           /* Save Lower Context */
  __asm("mov   %d4,2");     /* Store Trap Class   */
  __asm("mov   %d5,%d15");  /* Store Trap ID      */
  /* Load trap handler address: */
  __asm("movh.a  %a15,hi:PmuEccEdcTst_lUnexpTrapHandler");
  __asm("lea     %a15,[%a15]lo:PmuEccEdcTst_lUnexpTrapHandler");
  /* Jump to the trap handler in SPRAM:           */
  __asm("ji      %a15");

  __asm (".align 5");
  /* Class 3, Context Management Traps */
  __asm("svlcx");           /* Save Lower Context */
  __asm("mov   %d4,3");     /* Store Trap Class   */
  __asm("mov   %d5,%d15");  /* Store Trap ID      */
  /* Load trap handler address: */
  __asm("movh.a  %a15,hi:PmuEccEdcTst_lUnexpTrapHandler");
  __asm("lea     %a15,[%a15]lo:PmuEccEdcTst_lUnexpTrapHandler");
  /* Jump to the trap handler in SPRAM:           */
  __asm("ji      %a15");

  __asm (".align 5");
  /* Class 4, System Bus and Peripheral Error Traps */
  __asm("svlcx");           /* Save Lower Context */
  __asm("mov   %d4,4");     /* Store Trap Class   */
  __asm("mov   %d5,%d15");  /* Store Trap ID      */
  /* Load trap handler address: */
  __asm("movh.a  %a15,hi:PmuEccEdcTst_lUnexpTrapHandler");
  __asm("lea     %a15,[%a15]lo:PmuEccEdcTst_lUnexpTrapHandler");
  /* Jump to the trap handler in SPRAM:           */
  __asm("ji      %a15");

  __asm (".align 5");
  /* Class 5, Assertion Traps */
  __asm("svlcx");           /* Save Lower Context */
  __asm("mov   %d4,5");     /* Store Trap Class   */
  __asm("mov   %d5,%d15");  /* Store Trap ID      */
  /* Load trap handler address: */
  __asm("movh.a  %a15,hi:PmuEccEdcTst_lUnexpTrapHandler");
  __asm("lea     %a15,[%a15]lo:PmuEccEdcTst_lUnexpTrapHandler");
  /* Jump to the trap handler in SPRAM:           */
  __asm("ji      %a15");

  __asm (".align 5");
  /* Class 6, System Call Trap */
  __asm("svlcx");           /* Save Lower Context */
  __asm("mov   %d4,6");     /* Store Trap Class   */
  __asm("mov   %d5,%d15");  /* Store Trap ID      */
  /* Load trap handler address: */
  __asm("movh.a  %a15,hi:PmuEccEdcTst_lUnexpTrapHandler");
  __asm("lea     %a15,[%a15]lo:PmuEccEdcTst_lUnexpTrapHandler");
  /* Jump to the trap handler in SPRAM:           */
  __asm("ji      %a15");

  __asm (".align 5");
  /* Class 7, Non Maskable Interrupt Traps */
  __asm("svlcx");           /* Save Lower Context */
  __asm("mov   %d4,7");     /* Store Trap Class   */
  __asm("mov   %d5,%d15");  /* Store Trap ID      */
  /* Load trap handler address: */
  __asm("movh.a  %a15,hi:PmuEccEdcTst_lUnexpTrapHandler");
  __asm("lea     %a15,[%a15]lo:PmuEccEdcTst_lUnexpTrapHandler");
  /* Jump to the trap handler in SPRAM:           */
  __asm("ji      %a15");
}
#endif /* __GNUC__ */

#ifdef _DIABDATA_C_TRICORE_
#if (_DIABDATA_C_TRICORE_ == 1U)
void PmuEccEdcTst_lTrapVectors (void)
{
  __asm (".align 8");
  /* Class 0, MMU Traps: */
  __asm("svlcx");           /* Save Lower Context */
  __asm("mov   %d4,0");     /* Store Trap Class   */
  __asm("mov   %d5,%d15");  /* Store Trap ID      */
  /* Load trap handler address: */
  __asm (" movh.a %a15,PmuEccEdcTst_lUnexpTrapHandler@ha"); \
  __asm (" lea    %a15,[%a15]PmuEccEdcTst_lUnexpTrapHandler@l"); \
  /* Jump to the trap handler in SPRAM:           */
  __asm (" ji     %a15"); \

  __asm (".align 5");
  /* Class 1, Internal Protection Traps */
  __asm("svlcx");           /* Save Lower Context */
  __asm("mov   %d4,1");     /* Store Trap Class   */
  __asm("mov   %d5,%d15");  /* Store Trap ID      */
  /* Load trap handler address: */
  __asm (" movh.a %a15,PmuEccEdcTst_lUnexpTrapHandler@ha"); \
  __asm (" lea    %a15,[%a15]PmuEccEdcTst_lUnexpTrapHandler@l"); \
  /* Jump to the trap handler in SPRAM:           */
  __asm (" ji     %a15"); \

  __asm (".align 5");
  /* Class 2, Instruction Error Traps */
  __asm("svlcx");           /* Save Lower Context */
  __asm("mov   %d4,2");     /* Store Trap Class   */
  __asm("mov   %d5,%d15");  /* Store Trap ID      */
  /* Load trap handler address: */
  __asm (" movh.a %a15,PmuEccEdcTst_lUnexpTrapHandler@ha"); \
  __asm (" lea    %a15,[%a15]PmuEccEdcTst_lUnexpTrapHandler@l"); \
  /* Jump to the trap handler in SPRAM:           */
  __asm (" ji     %a15"); \

  __asm (".align 5");
  /* Class 3, Context Management Traps */
  __asm("svlcx");           /* Save Lower Context */
  __asm("mov   %d4,3");     /* Store Trap Class   */
  __asm("mov   %d5,%d15");  /* Store Trap ID      */
  /* Load trap handler address: */
  __asm (" movh.a %a15,PmuEccEdcTst_lUnexpTrapHandler@ha"); \
  __asm (" lea    %a15,[%a15]PmuEccEdcTst_lUnexpTrapHandler@l"); \
  /* Jump to the trap handler in SPRAM:           */
  __asm (" ji     %a15"); \

  __asm (".align 5");
  /* Class 4, System Bus and Peripheral Error Traps */
  __asm("svlcx");           /* Save Lower Context */
  __asm("mov   %d4,4");     /* Store Trap Class   */
  __asm("mov   %d5,%d15");  /* Store Trap ID      */
  /* Load trap handler address: */
  __asm (" movh.a %a15,PmuEccEdcTst_lUnexpTrapHandler@ha"); \
  __asm (" lea    %a15,[%a15]PmuEccEdcTst_lUnexpTrapHandler@l"); \
  /* Jump to the trap handler in SPRAM:           */
  __asm (" ji     %a15"); \

  __asm (".align 5");
  /* Class 5, Assertion Traps */
  __asm("svlcx");           /* Save Lower Context */
  __asm("mov   %d4,5");     /* Store Trap Class   */
  __asm("mov   %d5,%d15");  /* Store Trap ID      */
  /* Load trap handler address: */
  __asm (" movh.a %a15,PmuEccEdcTst_lUnexpTrapHandler@ha"); \
  __asm (" lea    %a15,[%a15]PmuEccEdcTst_lUnexpTrapHandler@l"); \
  /* Jump to the trap handler in SPRAM:           */
  __asm (" ji     %a15"); \

  __asm (".align 5");
  /* Class 6, System Call Trap */
  __asm("svlcx");           /* Save Lower Context */
  __asm("mov   %d4,6");     /* Store Trap Class   */
  __asm("mov   %d5,%d15");  /* Store Trap ID      */
  /* Load trap handler address: */
  __asm (" movh.a %a15,PmuEccEdcTst_lUnexpTrapHandler@ha"); \
  __asm (" lea    %a15,[%a15]PmuEccEdcTst_lUnexpTrapHandler@l"); \
  /* Jump to the trap handler in SPRAM:           */
  __asm (" ji     %a15"); \

  __asm (".align 5");
  /* Class 7, Non Maskable Interrupt Traps */
  __asm("svlcx");           /* Save Lower Context */
  __asm("mov   %d4,7");     /* Store Trap Class   */
  __asm("mov   %d5,%d15");  /* Store Trap ID      */
  /* Load trap handler address: */
  __asm (" movh.a %a15,PmuEccEdcTst_lUnexpTrapHandler@ha"); \
  __asm (" lea    %a15,[%a15]PmuEccEdcTst_lUnexpTrapHandler@l"); \
  /* Jump to the trap handler in SPRAM:           */
  __asm (" ji     %a15"); \
}
#endif  /* _DIABDATA_C_TRICORE_ == 1U */
#endif  /* _DIABDATA_C_TRICORE_ */

#define IFX_PMUECCEDCTST_STOP_SEC_TVT_CODE_ASIL_B
#include "Ifx_MemMap.h"

#define IFX_PMUECCEDCTST_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : Sl_TstRsltType PmuEccEdcTst_EccEdcTst                             **
**          (                                                                 **
**            const Sl_ParamSetIndex ParamSetIndex,                           **
**            const uint8 TstSeed,                                            **
**            uint32* const TstSignature                                      **
**          )                                                                 **
**                                                                            **
** Description : Performs a latent fault metric test of the PMU Error         **
**               Correction Codes and Error Detection Circuit.                **
** Note(s):      Bit errors in the PFLASH test patterns need to be created    **
**               one-time before this API is executed. The bit errors could   **
**               be created by using the Sl_ErrorPatternProg support API or   **
**               by any other custom error programming code.                  **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) : ParamSetIndex - Identifies the parameter set to be used  **
**                                   for test execution                       **
**                   TstSeed - Seed to be used for generating the signature   **
**                                                                            **
** Parameters (out): TstSignature - Test signature generated by the test      **
**                                                                            **
** Return value :                                                             **
**      PMUECCEDC_SUCCESS           - Test succeeded                          **
**      PMUECCEDC_NOTEXECUTED       - Test unexpectedly aborted               **
**      PMUECCEDC_GENERALHWFAILURE  - Test failed                             **
**      PMUECCEDC_DATACORRUPTION    - valid data corrupted by ECC logic       **
**      PMUECCEDC_SMU_CLRALMSTSERR  - Smu_ClearAlarmStatus reports error      **
**      PMUECCEDC_SMU_GETALMACTIONERR - Smu_GetAlarmAction reports error      **
**      PMUECCEDC_SMU_SETALMACTIONERR - Smu_SetAlarmAction reports error      **
**      PMUECCEDC_TIMEOUT_SBEALARM  - SBE SMU alarm timed out                 **
**      PMUECCEDC_TIMEOUT_DBEALARM  - DBE SMU alarm timed out                 **
**      PMUECCEDC_TIMEOUT_MBEALARM  - MBE SMU alarm timed out                 **
**      PMUECCEDC_TIMEOUT_ECCMONALARM - ECC monitor SMU alarm timed out       **
**      PMUECCEDC_TIMEOUT_EDCCMPALARM - EDC comparator SMU alarm timed out    **
**                                                                            **
*******************************************************************************/
Sl_TstRsltType PmuEccEdcTst_EccEdcTst
(
  const Sl_ParamSetType ParamSetIndex,
  const uint8 TstSeed,
  uint32* const TstSignature
)
{
  Sl_TstRsltType              Result = PMUECCEDC_NOTEXECUTED;
  Sl_TstRsltType              ResultTmp;
  PmuEccEdcTst_BackupDataType SmuAlarms;

  UNUSED_PARAMETER(ParamSetIndex)

  /* Initialize Test Signature */
  *TstSignature = (uint32)CRC32((uint32)TEST_ID_PMU_ECC_EDC_TST,
                                (uint32)TstSeed);

  /* Backup SMU Alarm Actions */
  Result = PmuEccEdcTst_lInit(&SmuAlarms);
  if (PMUECCEDC_SUCCESS == Result)
  {
    volatile Ifx_FLASH_ECCRP* FlashEccrpList[PMU_ECC_EDC_TST_MAX_FLASHBANKS];
    PmuEccEdcTst_TestDataType ThisFlash;
    uint32                    i = 0U;

    /* Create list of FLASH0_ECCRPx pointers: */
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

    /* Initialize test data: */
    ThisFlash.Signature = TstSignature;
    ThisFlash.FlashCmd  = (volatile uint32*)
                          (PMUT_PMU0_DF0_BASE + PMUT_FLS_CMD_ADDR);

    /* Test all configured flash banks: */
#if ((CHIP_ID == 26U) || (CHIP_ID == 27U) || (CHIP_ID == 29U))
    for (i = 0U; i < PMU_ECC_EDC_TST_MAX_FLASHBANKS; i++)
#endif
    {
      if (NULL_PTR != PmuEccEdcTst_TestPattern[i])
      {
        /* Test for PFLASH Bankx */
        ThisFlash.FlashEccrpPtr = FlashEccrpList[i];

        /* Bit Or to support cached / noncached area required */
        ThisFlash.FlashPattern = (PmuEccEdcTst_TestPatternType*)
            ((uint32)(PmuEccEdcTst_TestPattern[i]) | (uint32)0x20000000U);

        Result = PmuEccEdcTst_lTestFlsBank(&ThisFlash);
#if ((CHIP_ID == 26U) || (CHIP_ID == 27U) || (CHIP_ID == 29U))        
        if (PMUECCEDC_SUCCESS != Result)
        {
          break;
        } /* if (PMUECCEDC_SUCCESS != Result) */
#endif
      }
    } /* for (i = 0U; i < PMU_ECC_EDC_TST_MAX_FLASHBANKS; i++) */

    /* Clear flash status flags: */
    *ThisFlash.FlashCmd = PMUT_FSI_CMD_FA;
  } /* if (PMUECCEDC_SUCCESS == Result) */

  /* Restore SMU Alarm Actions */
  ResultTmp = PmuEccEdcTst_lRestore(&SmuAlarms);
  
  if (PMUECCEDC_SUCCESS != ResultTmp)
  {
     if (PMUECCEDC_SUCCESS == Result)
     {
       Result = ResultTmp;
     }/* if (PMUECCEDC_SUCCESS == Result) */
  } /* if (PMUECCEDC_SUCCESS != ResultTmp) */

  /* add final result to Test Signature */
  *TstSignature = (uint32)CRC32(*TstSignature, Result);

  return Result;
} /* PmuEccEdcTst_EccEdcTst */


/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : PmuEccEdcTst_UnexpAlmType*                                        **
**          PmuEccEdcTst_GetUnexpEccAlmListPtr(void)                          **
**                                                                            **
** Description : Returns a pointer to a list that contains the number         **
**               of unexpected ECC alarms happened while executing from flash **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Reentrant                                                  **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value :   PmuEccEdcTst_UnexpAlmType* Pointer to list of unexpected  **
**                                             Ecc alarms during last test    **
**                                             or NULL_PTR if unexpected      **
**                                             alarm counter data was         **
**                                             corrupted (i.e. its CRC is     **
**                                             invalid)                       **
**                                                                            **
*******************************************************************************/
PmuEccEdcTst_UnexpAlmType* PmuEccEdcTst_GetUnexpEccAlmListPtr
(
  void
)
{
  PmuEccEdcTst_UnexpAlmType*  Result = NULL_PTR;

  /* Check if alarm counter CRC is valid: */
  if (PmuEccEdcTst_lCalcAlmCounterCrc() == PmuEccEdcTst_UnexpAlm.Crc32)
  {
    Result = &PmuEccEdcTst_UnexpAlm;
  }

  return Result;
} /* PmuEccEdcTst_GetUnexpEccAlmListPtr */


/******************************************************************************/
/* LOCAL (FILE-SCOPE) IMPLEMENTATION                                          */
/******************************************************************************/

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : Sl_TstRsltType PmuEccEdcTst_lInit                                 **
**          (                                                                 **
**            PmuEccEdcTst_BackupDataType* const AlmBackup                    **
**          )                                                                 **
**                                                                            **
** Description : Saves the current microcontroller state to a given backup    **
**               data structure and initializes hardware settings required    **
**               by the PMU ECC/EDC test.                                     **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in):                                                           **
**                                                                            **
** Parameters (out) : AlmBackup - Pointer to a structure that will receive    **
**                                the backup data of the PMU ECC/EDC test     **
**                                                                            **
** Return value :                                                             **
**      PMUECCEDC_SUCCESS           - Test succeeded                          **
**      PMUECCEDC_NOTEXECUTED       - Test unexpectedly aborted               **
**      PMUECCEDC_SMU_GETALMACTIONERR - Smu_GetAlarmAction reports error      **
**      PMUECCEDC_SMU_SETALMACTIONERR - Smu_SetAlarmAction reports error      **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType PmuEccEdcTst_lInit
(
  PmuEccEdcTst_BackupDataType* const AlmBackup
)
{
  Sl_TstRsltType    Result = PMUECCEDC_NOTEXECUTED;
  Sl_TstRsltType    ResultTmp;
  Smu_FSPActionType FspActionDummy;
  Std_ReturnType    SmuResult1,SmuResult2,SmuResult3,SmuResult4,SmuResult5;
  
  uint32 baddress,eaddress;

  baddress = (uint32)LOC_START_PflashMon_EccEdc_PFLASHCODE;
  eaddress = (uint32)LOC_END_PflashMon_EccEdc_PFLASHCODE;
  
  /* Calculate Crc of functions in PFlash that have been copied to RAM*/
  PmuEccEdcTst_PFlashFnCrc32 = PmuEccEdcTst_CalculateCrc32(LOC_START_PflashMon_EccEdc_PFLASHCODE,
    (eaddress-baddress));
    
  baddress = (uint32)LOC_START_PmuEccEdcTst_tvt_PFLASHCODE;
  eaddress = (uint32)LOC_END_PmuEccEdcTst_tvt_PFLASHCODE;
    
  /* Calculate Crc of Trap Vector Table in PFlash that has been copied to RAM*/
  PmuEccEdcTst_TvtCrc32 = PmuEccEdcTst_CalculateCrc32(LOC_START_PmuEccEdcTst_tvt_PFLASHCODE,
    (eaddress-baddress));

  /* Backup CBAB / UBAB configuration: */
  AlmBackup->CbabCfg0Backup = FLASH0_CBABCFG0.U;
#if (PMU_ECC_EDC_TST_MAX_FLASHBANKS > 1U)
  AlmBackup->CbabCfg1Backup = FLASH0_CBABCFG1.U;
#if (PMU_ECC_EDC_TST_MAX_FLASHBANKS > 2U)
  AlmBackup->CbabCfg2Backup = FLASH0_CBABCFG2.U;
#if (PMU_ECC_EDC_TST_MAX_FLASHBANKS > 3U)
  AlmBackup->CbabCfg3Backup = FLASH0_CBABCFG3.U;
#endif /* PMU_ECC_EDC_TST_MAX_FLASHBANKS > 3U */
#endif /* PMU_ECC_EDC_TST_MAX_FLASHBANKS > 2U */
#endif /* PMU_ECC_EDC_TST_MAX_FLASHBANKS > 1U */
  AlmBackup->UbabCfg0Backup = FLASH0_UBABCFG0.U;
#if (PMU_ECC_EDC_TST_MAX_FLASHBANKS > 1U)
  AlmBackup->UbabCfg1Backup = FLASH0_UBABCFG1.U;
#if (PMU_ECC_EDC_TST_MAX_FLASHBANKS > 2U)
  AlmBackup->UbabCfg2Backup = FLASH0_UBABCFG2.U;
#if (PMU_ECC_EDC_TST_MAX_FLASHBANKS > 3U)
  AlmBackup->UbabCfg3Backup = FLASH0_UBABCFG3.U;
#endif /* PMU_ECC_EDC_TST_MAX_FLASHBANKS > 3U */
#endif /* PMU_ECC_EDC_TST_MAX_FLASHBANKS > 2U */
#endif /* PMU_ECC_EDC_TST_MAX_FLASHBANKS > 1U */

  /* Disable CBAB / UBAB error tracking: */
  Mcal_ResetENDINIT();
  FLASH0_CBABCFG0.B.DIS = 1U;
#if (PMU_ECC_EDC_TST_MAX_FLASHBANKS > 1U)
  FLASH0_CBABCFG1.B.DIS = 1U;
#if (PMU_ECC_EDC_TST_MAX_FLASHBANKS > 2U)
  FLASH0_CBABCFG2.B.DIS = 1U;
#if (PMU_ECC_EDC_TST_MAX_FLASHBANKS > 3U)
  FLASH0_CBABCFG3.B.DIS = 1U;
#endif /* PMU_ECC_EDC_TST_MAX_FLASHBANKS > 3U */
#endif /* PMU_ECC_EDC_TST_MAX_FLASHBANKS > 2U */
#endif /* PMU_ECC_EDC_TST_MAX_FLASHBANKS > 1U */
  FLASH0_UBABCFG0.B.DIS = 1U;
#if (PMU_ECC_EDC_TST_MAX_FLASHBANKS > 1U)
  FLASH0_UBABCFG1.B.DIS = 1U;
#if (PMU_ECC_EDC_TST_MAX_FLASHBANKS > 2U)
  FLASH0_UBABCFG2.B.DIS = 1U;
#if (PMU_ECC_EDC_TST_MAX_FLASHBANKS > 3U)
  FLASH0_UBABCFG3.B.DIS = 1U;
#endif /* PMU_ECC_EDC_TST_MAX_FLASHBANKS > 3U */
#endif /* PMU_ECC_EDC_TST_MAX_FLASHBANKS > 2U */
#endif /* PMU_ECC_EDC_TST_MAX_FLASHBANKS > 1U */
  Mcal_SetENDINIT();

  /* Clear unexpected alarm counters: */
  PmuEccEdcTst_UnexpAlm.Sbe = 0U;
  PmuEccEdcTst_UnexpAlm.Dbe = 0U;
  PmuEccEdcTst_UnexpAlm.Mbe = 0U;
  PmuEccEdcTst_UnexpAlm.Mon = 0U;
  PmuEccEdcTst_UnexpAlm.Cmp = 0U;
  PmuEccEdcTst_UnexpAlm.Crc32 = PmuEccEdcTst_lCalcAlmCounterCrc();

  /* Backup SMU alarm actions: */
  SmuResult1 = Smu_GetAlarmAction(SMU_ALARM_GROUP2,
                                  SMU_ALARM_2,
                                  &(AlmBackup->AlmActionSbe),
                                  &FspActionDummy);
  SmuResult2 = Smu_GetAlarmAction(SMU_ALARM_GROUP2,
                                  SMU_ALARM_3,
                                  &(AlmBackup->AlmActionDbe),
                                  &FspActionDummy);
  SmuResult3 = Smu_GetAlarmAction(SMU_ALARM_GROUP2,
                                  SMU_ALARM_4,
                                  &(AlmBackup->AlmActionMbe),
                                  &FspActionDummy);
  SmuResult4 = Smu_GetAlarmAction(SMU_ALARM_GROUP2,
                                  SMU_ALARM_7,
                                  &(AlmBackup->AlmActionEccMon),
                                  &FspActionDummy);
  SmuResult5 = Smu_GetAlarmAction(SMU_ALARM_GROUP2,
                                  SMU_ALARM_8,
                                  &(AlmBackup->AlmActionEdcCmp),
                                  &FspActionDummy);

  if ((SmuResult1 != E_OK) ||
      (SmuResult2 != E_OK) ||
      (SmuResult3 != E_OK) ||
      (SmuResult4 != E_OK) ||
      (SmuResult5 != E_OK)
     )
  {
      AlmBackup->GetAlmActionResult = E_NOT_OK;
      Result = PMUECCEDC_SMU_GETALMACTIONERR;
  } /* if ((SmuResult1 != E_OK) ||
           (SmuResult2 != E_OK) ||
           (SmuResult3 != E_OK) ||
           (SmuResult4 != E_OK) ||
           (SmuResult5 != E_OK)) */
  else
  {
    AlmBackup->GetAlmActionResult = E_OK;
    /* Set alarm actions to 'None': */
    SmuResult1 = Smu_SetAlarmAction(SMU_ALARM_GROUP2,
                                    SMU_ALARM_2,
                                    SMU_ALARM_ACTION_NONE);
    SmuResult2 = Smu_SetAlarmAction(SMU_ALARM_GROUP2,
                                    SMU_ALARM_3,
                                    SMU_ALARM_ACTION_NONE);
    SmuResult3 = Smu_SetAlarmAction(SMU_ALARM_GROUP2,
                                    SMU_ALARM_4,
                                    SMU_ALARM_ACTION_NONE);
    SmuResult4 = Smu_SetAlarmAction(SMU_ALARM_GROUP2,
                                    SMU_ALARM_7,
                                    SMU_ALARM_ACTION_NONE);
    SmuResult5 = Smu_SetAlarmAction(SMU_ALARM_GROUP2,
                                    SMU_ALARM_8,
                                    SMU_ALARM_ACTION_NONE);

    if ((SmuResult1 != E_OK) ||
        (SmuResult2 != E_OK) ||
        (SmuResult3 != E_OK) ||
        (SmuResult4 != E_OK) ||
        (SmuResult5 != E_OK)
       )
    {
        Result = PMUECCEDC_SMU_SETALMACTIONERR;
    } /* if ((SmuResult1 != E_OK) ||
             (SmuResult2 != E_OK) ||
             (SmuResult3 != E_OK) ||
             (SmuResult4 != E_OK) ||
             (SmuResult5 != E_OK)) */
    else
    {
        Result = PMUECCEDC_SUCCESS;
    } /* if ((SmuResult1 == E_OK) &&
             (SmuResult2 == E_OK) &&
             (SmuResult3 == E_OK) &&
             (SmuResult4 == E_OK) &&
             (SmuResult5 == E_OK)) */

  } /* if ((SmuResult1 == E_OK) &&
           (SmuResult2 == E_OK) &&
           (SmuResult3 == E_OK) &&
           (SmuResult4 == E_OK) &&
           (SmuResult5 == E_OK)) */

  /* Switch trap table to SPRAM: */
  ResultTmp = PmuEccEdcTst_lSetupTrapHandling();
  if (PMUECCEDC_SUCCESS != ResultTmp)
  {
    Result = ResultTmp;
  }

  return Result;
} /* PmuEccEdcTst_lInit */

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : Sl_TstRsltType PmuEccEdcTst_lRestore                              **
**          (                                                                 **
**            const PmuEccEdcTst_BackupDataType* const AlmBackup              **
**          )                                                                 **
**                                                                            **
** Description : Restores the microcontroller state as it has been before the **
**               test was executed.                                           **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) : AlmBackup - Pointer to a structure holding the PMU ECC/  **
**                               EDC test backup data (which has been saved   **
**                               before)                                      **
**                                                                            **
** Parameters (out):                                                          **
**                                                                            **
** Return value :                                                             **
**      PMUECCEDC_SUCCESS           - Test succeeded                          **
**      PMUECCEDC_NOTEXECUTED       - Test unexpectedly aborted               **
**      PMUECCEDC_SMU_SETALMACTIONERR - Smu_SetAlarmAction reports error      **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType PmuEccEdcTst_lRestore
(
  const PmuEccEdcTst_BackupDataType* const AlmBackup
)
{
  Sl_TstRsltType  Result = PMUECCEDC_NOTEXECUTED;
  Std_ReturnType  SmuResult1,SmuResult2,SmuResult3,SmuResult4,SmuResult5;

  /* Restore trap handling: */
  PmuEccEdcTst_lRestoreTrapHandling();

  /* Restore CBAB / UBAB configuration: */
  Mcal_ResetENDINIT();
  FLASH0_CBABCFG0.U = AlmBackup->CbabCfg0Backup;
#if (PMU_ECC_EDC_TST_MAX_FLASHBANKS > 1U)
  FLASH0_CBABCFG1.U = AlmBackup->CbabCfg1Backup;
#if (PMU_ECC_EDC_TST_MAX_FLASHBANKS > 2U)
  FLASH0_CBABCFG2.U = AlmBackup->CbabCfg2Backup;
#if (PMU_ECC_EDC_TST_MAX_FLASHBANKS > 3U)
  FLASH0_CBABCFG3.U = AlmBackup->CbabCfg3Backup;
#endif /* PMU_ECC_EDC_TST_MAX_FLASHBANKS > 3U */
#endif /* PMU_ECC_EDC_TST_MAX_FLASHBANKS > 2U */
#endif /* PMU_ECC_EDC_TST_MAX_FLASHBANKS > 1U */
  FLASH0_UBABCFG0.U = AlmBackup->UbabCfg0Backup;
#if (PMU_ECC_EDC_TST_MAX_FLASHBANKS > 1U)
  FLASH0_UBABCFG1.U = AlmBackup->UbabCfg1Backup;
#if (PMU_ECC_EDC_TST_MAX_FLASHBANKS > 2U)
  FLASH0_UBABCFG2.U = AlmBackup->UbabCfg2Backup;
#if (PMU_ECC_EDC_TST_MAX_FLASHBANKS > 3U)
  FLASH0_UBABCFG3.U = AlmBackup->UbabCfg3Backup;
#endif /* PMU_ECC_EDC_TST_MAX_FLASHBANKS > 3U */
#endif /* PMU_ECC_EDC_TST_MAX_FLASHBANKS > 2U */
#endif /* PMU_ECC_EDC_TST_MAX_FLASHBANKS > 1U */
  Mcal_SetENDINIT();

  if (AlmBackup->GetAlmActionResult == E_OK)
  {
    SmuResult1 = Smu_SetAlarmAction(SMU_ALARM_GROUP2,
                                    SMU_ALARM_2,
                                    AlmBackup->AlmActionSbe);
    SmuResult2 = Smu_SetAlarmAction(SMU_ALARM_GROUP2,
                                    SMU_ALARM_3,
                                    AlmBackup->AlmActionDbe);
    SmuResult3 = Smu_SetAlarmAction(SMU_ALARM_GROUP2,
                                    SMU_ALARM_4,
                                    AlmBackup->AlmActionMbe);
    SmuResult4 = Smu_SetAlarmAction(SMU_ALARM_GROUP2,
                                    SMU_ALARM_7,
                                    AlmBackup->AlmActionEccMon);
    SmuResult5 = Smu_SetAlarmAction(SMU_ALARM_GROUP2,
                                    SMU_ALARM_8,
                                    AlmBackup->AlmActionEdcCmp);

    if ((SmuResult1 != E_OK) ||
        (SmuResult2 != E_OK) ||
        (SmuResult3 != E_OK) ||
        (SmuResult4 != E_OK) ||
        (SmuResult5 != E_OK)
       )
    {
      Result = PMUECCEDC_SMU_SETALMACTIONERR;
    } /* if ((SmuResult1 != E_OK) ||
             (SmuResult2 != E_OK) ||
             (SmuResult3 != E_OK) ||
             (SmuResult4 != E_OK) ||
             (SmuResult5 != E_OK)) */
    else
    {
      Result = PMUECCEDC_SUCCESS;
    } /* if ((SmuResult1 == E_OK) &&
             (SmuResult2 == E_OK) &&
             (SmuResult3 == E_OK) &&
             (SmuResult4 == E_OK) &&
             (SmuResult5 == E_OK)) */
  } /* if (AlmBackup->GetAlmActionResult == E_OK) */
  else
  {
    Result = PMUECCEDC_SUCCESS;
  } /* if (AlmBackup->GetAlmActionResult != E_OK) */

  return Result;
} /* PmuEccEdcTst_lRestore */


/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : Sl_TstRsltType PmuEccEdcTst_lTestFlsBank                          **
**          (                                                                 **
**            const PmuEccEdcTst_TestDataType* TestData                       **
**          )                                                                 **
**                                                                            **
** Description : Carry our all test for one flash bank                        **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) : TestData       - Pointer to test data set                **
**                                                                            **
** Parameters (out): TstSignature - Test signature generated by the test      **
**                                                                            **
** Return value :                                                             **
**      PMUECCEDC_SUCCESS           - Test succeeded                          **
**      PMUECCEDC_NOTEXECUTED       - Test unexpectedly aborted               **
**      PMUECCEDC_GENERALHWFAILURE  - Test failed                             **
**      PMUECCEDC_DATACORRUPTION    - valid data corrupted by ECC logic       **
**      PMUECCEDC_TIMEOUT_SBEALARM  - SBE SMU alarm timed out                 **
**      PMUECCEDC_TIMEOUT_DBEALARM  - DBE SMU alarm timed out                 **
**      PMUECCEDC_TIMEOUT_MBEALARM  - MBE SMU alarm timed out                 **
**      PMUECCEDC_TIMEOUT_ECCMONALARM - ECC monitor SMU alarm timed out       **
**      PMUECCEDC_TIMEOUT_EDCCMPALARM - EDC monitor SMU alarm timed out       **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType PmuEccEdcTst_lTestFlsBank
(
  const PmuEccEdcTst_TestDataType* TestData
)
{
  Sl_TstRsltType  Result = PMUECCEDC_NOTEXECUTED;

  /* Check if ECC errors are correctly signaled to the SMU */
  Result = PmuEccEdcTst_lTestEccSmuSgnl(TestData);
  if (PMUECCEDC_SUCCESS == Result)
  {
    /* Check the ECC Error Detection Supervision Circuit */
    Result = PmuEccEdcTst_lTestEccOnlnMon(TestData);

    if (PMUECCEDC_SUCCESS == Result)
    {
      /* Check the Comparator Logic comparing the outputs of the redundant ECC
       * units: */
      Result = PmuEccEdcTst_lTestEdcCmp(TestData);
    } /* if (PMUECCEDC_SUCCESS == Result) */
  } /* if (PMUECCEDC_SUCCESS == Result)*/

  return Result;
} /* PmuEccEdcTst_lTestFlsBank */


/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : Sl_TstRsltType PmuEccEdcTst_lTestEccSmuSgnl                       **
**          (                                                                 **
**            const PmuEccEdcTst_TestDataType* TestData                       **
**          )                                                                 **
**                                                                            **
** Description : Tests the signaling of Single-, Double- and Multi-Bit        **
**               Errors, Address Errors, "All Zeros" and "All Ones" code      **
**               words from the PMU to the SMU.                               **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) : TestData       - Pointer to test data set                **
** Parameters (out) :                                                         **
**                                                                            **
** Return value :                                                             **
**      PMUECCEDC_SUCCESS           - Test succeeded                          **
**      PMUECCEDC_NOTEXECUTED       - Test unexpectedly aborted               **
**      PMUECCEDC_GENERALHWFAILURE  - Test failed                             **
**      PMUECCEDC_SMU_CLRALMSTSERR  - Smu_ClearAlarmStatus reports error      **
**      PMUECCEDC_TIMEOUT_SBEALARM  - SBE SMU alarm timed out                 **
**      PMUECCEDC_TIMEOUT_DBEALARM  - DBE SMU alarm timed out                 **
**      PMUECCEDC_TIMEOUT_MBEALARM  - MBE SMU alarm timed out                 **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType PmuEccEdcTst_lTestEccSmuSgnl
(
  const PmuEccEdcTst_TestDataType* TestData
)
{
  Sl_TstRsltType  Result = PMUECCEDC_NOTEXECUTED;

  Result = PmuEccEdcTst_lTestEccSmuSgnlVcw(TestData);
  if (PMUECCEDC_SUCCESS == Result)
  {
    Result = PmuEccEdcTst_lTestEccSmuSgnlSbe(TestData);
    if (PMUECCEDC_SUCCESS == Result)
    {
      Result = PmuEccEdcTst_lTestEccSmuSgnlDbe(TestData);
      if (PMUECCEDC_SUCCESS == Result)
      {
        Result = PmuEccEdcTst_lTestEccSmuSgnlMbe(TestData);
      } /* if (PMUECCEDC_SUCCESS == Result) */
    } /* if (PMUECCEDC_SUCCESS == Result) */
  } /* if (PMUECCEDC_SUCCESS == Result) */

  return Result;
} /* PmuEccEdcTst_lTestEccSmuSgnl */

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : Sl_TstRsltType PmuEccEdcTst_lTestEccSmuSgnlVcw                    **
**          (                                                                 **
**            const PmuEccEdcTst_TestDataType* TestData                       **
**          )                                                                 **
**                                                                            **
** Description : Clear all pending SMU alrams and                             **
**               Check valid data access to generate no errors                **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) : TestData       - Pointer to test data set                **
**                                                                            **
** Parameters (out): TstSignature - Test signature generated by the test      **
**                                                                            **
** Return value :                                                             **
**      PMUECCEDC_SUCCESS           - Test succeeded                          **
**      PMUECCEDC_GENERALHWFAILURE  - Test failed                             **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType PmuEccEdcTst_lTestEccSmuSgnlVcw
(
  const PmuEccEdcTst_TestDataType* TestData
)
{
  Sl_TstRsltType                  Result = PMUECCEDC_NOTEXECUTED;
  Sl_TstRsltType                  ResultTmp;
  uint32                          i;
  PmuEccEdcTst_EccHlprType        VcwHlpr;
  boolean                         TestPassed;

  Result               = PMUECCEDC_GENERALHWFAILURE;
  TestPassed           = FALSE;
  VcwHlpr.SmuAlm       = &SMU_AG2;
  VcwHlpr.SmuCmd       = &SMU_CMD;
  VcwHlpr.FlashTrapDis = &FLASH0_MARP;
  VcwHlpr.FlashCmd     = TestData->FlashCmd;
  VcwHlpr.SmuAlmAfter  = 0U;
  VcwHlpr.SmuAlmBefore = 0U;
  VcwHlpr.SmuAlmMask   = PMUT_SMU_ALARM_SETALL;

  /* Calculate and compare Crc of functions in RAM that 
   were copied from PFlash at startup*/   
  ResultTmp = PmuEccEdcTst_lRamCalculateandVerifyCrc32(PMUECCEDC_CODE);
  
  if (PMUECCEDC_SUCCESS != ResultTmp)
  {
    Result = ResultTmp;
  } /* if (PMUECCEDC_SUCCESS != ResultTmp) */
  else
  {
    for (i = 0U;
         ((i < PMUT_TEST_PATTERN_COUNT) && (TestPassed != (boolean)TRUE));
         i++)
    {
      /* Check that access to Vcw word does not generate an SMU alarm */
      VcwHlpr.DataAddrA =
          &(TestData->FlashPattern->Set[i].Pattern[PMUT_VCW_PTRN_IDX]);

      Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);
      Mcal_ResetENDINIT();

      ResultTmp = PmuEccEdcTst_lEccHelper(&VcwHlpr);

      Mcal_SetENDINIT();
      Mcal_SetSafetyENDINIT_Timed();

      /* count unexpected ECC alarms */
      PmuEccEdcTst_lCountUnExpectAlm(VcwHlpr.SmuAlmBefore);

      /* Check for helper routine result: */
      if (PMUECCEDC_SUCCESS != ResultTmp)
      {
        Result = ResultTmp;
        break;
      } /* if (PMUECCEDC_SUCCESS != ResultTmp) */
      else
      {
        /* any alarm signaled? */
        if ((VcwHlpr.SmuAlmAfter & PMUT_SMU_ALARM_SETALL) == 0U)
        {
          Result = PMUECCEDC_SUCCESS;
          TestPassed = TRUE;
        } /* if ((VcwHlpr.SmuAlmAfter & PMUT_SMU_ALARM_SETALL) == 0U) */
      } /* if (PMUECCEDC_SUCCESS == ResultTmp) */
    } /* for (i = 0u; i < PMUT_TEST_PATTERN_COUNT; i++) */
  } /* if (PMUECCEDC_SUCCESS == ResultTmp) */

  *(TestData->Signature) = (uint32)CRC32(*(TestData->Signature),
                                         (uint32)TestPassed);

  return Result;
} /* PmuEccEdcTst_lTestEccSmuSgnlVcw */



/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : Sl_TstRsltType PmuEccEdcTst_lTestEccSmuSgnlSbe                    **
**          (                                                                 **
**            const PmuEccEdcTst_TestDataType* TestData                       **
**          )                                                                 **
**                                                                            **
** Description : Check if Single Bit Errors are correctly signaled to the SMU **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) : TestData       - Pointer to test data set                **
**                                                                            **
** Parameters (out): TstSignature - Test signature generated by the test      **
**                                                                            **
** Return value :                                                             **
**      PMUECCEDC_SUCCESS           - Test succeeded                          **
**      PMUECCEDC_TIMEOUT_SBEALARM  - SBE SMU alarm timed out                 **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType PmuEccEdcTst_lTestEccSmuSgnlSbe
(
  const PmuEccEdcTst_TestDataType* TestData
)
{
  Sl_TstRsltType            Result = PMUECCEDC_NOTEXECUTED;
  Sl_TstRsltType            ResultTmp;
  uint32                    i;
  PmuEccEdcTst_EccHlprType  SbeHlpr;

  Result               = PMUECCEDC_TIMEOUT_SBEALARM;
  SbeHlpr.SmuAlm       = &SMU_AG2;
  SbeHlpr.SmuCmd       = &SMU_CMD;
  SbeHlpr.FlashTrapDis = &FLASH0_MARP;
  SbeHlpr.FlashCmd     = TestData->FlashCmd;
  SbeHlpr.SmuAlmAfter  = 0U;
  SbeHlpr.SmuAlmBefore = 0U;
  SbeHlpr.SmuAlmMask   = PMUT_SMU_ALARM_SETALL;

  /* Calculate and compare Crc of functions in RAM that 
   were copied from PFlash at startup*/   
  ResultTmp = PmuEccEdcTst_lRamCalculateandVerifyCrc32(PMUECCEDC_CODE);
  if (PMUECCEDC_SUCCESS != ResultTmp)
  {
    Result = ResultTmp;
  } /* if (PMUECCEDC_SUCCESS != ResultTmp) */
  else
  {
    for (i = 0U; ((i < PMUT_TEST_PATTERN_COUNT) &&
        (Result != (Sl_TstRsltType)PMUECCEDC_SUCCESS)); i++)
    {
      /* Check that access to sbe word does generate an SMU alarm */
      SbeHlpr.DataAddrA =
          &(TestData->FlashPattern->Set[i].Pattern[PMUT_SBE_PTRN_IDX]);
      Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);
      Mcal_ResetENDINIT();

      ResultTmp = PmuEccEdcTst_lEccHelper(&SbeHlpr);

      Mcal_SetENDINIT();
      Mcal_SetSafetyENDINIT_Timed();

      PmuEccEdcTst_lCountUnExpectAlm(SbeHlpr.SmuAlmBefore);

      /* Check result of helper routine: */
      if (PMUECCEDC_SUCCESS != ResultTmp)
      {
        Result = ResultTmp;
        break;
      } /* if (PMUECCEDC_SUCCESS != ResultTmp) */
      else
      {
        if ((SbeHlpr.SmuAlmAfter & PMUT_SMU_ALARM_SETALL) == PMUT_SMU_ALARM2)
        {
          Result = PMUECCEDC_SUCCESS;
        } /* if ((SbeHlpr.SmuAlmAfter & PMUT_SMU_ALARM_SETALL) ==
                 PMUT_SMU_ALARM2) */
      } /* if (PMUECCEDC_SUCCESS == ResultTmp) */
    } /* for (i = 0U; i < PMUT_TEST_PATTERN_COUNT; i++) */
  } /* if (PMUECCEDC_SUCCESS == ResultTmp) */

  *(TestData->Signature) = (uint32)CRC32(*TestData->Signature,
                                      (SbeHlpr.SmuAlmAfter & PMUT_SMU_ALARM2));

  return Result;
} /* PmuEccEdcTst_lTestEccSmuSgnlSbe */


/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : Sl_TstRsltType PmuEccEdcTst_lTestEccSmuSgnlDbe                    **
**          (                                                                 **
**            const PmuEccEdcTst_TestDataType* TestData                       **
**          )                                                                 **
**                                                                            **
** Description : Check if Double Bit Errors are correctly signaled to the SMU **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) : TestData       - Pointer to test data set                **
**                                                                            **
** Parameters (out): TstSignature - Test signature generated by the test      **
**                                                                            **
** Return value :                                                             **
**      PMUECCEDC_SUCCESS           - Test succeeded                          **
**      PMUECCEDC_SMU_CLRALMSTSERR  - Smu_ClearAlarmStatus reports error      **
**      PMUECCEDC_TIMEOUT_DBEALARM  - DBE SMU alarm timed out                 **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType PmuEccEdcTst_lTestEccSmuSgnlDbe
(
  const PmuEccEdcTst_TestDataType* TestData
)
{
  Sl_TstRsltType            Result = PMUECCEDC_NOTEXECUTED;
  Sl_TstRsltType            ResultTmp;
  uint32                    i;
  PmuEccEdcTst_EccHlprType  DbeHlpr;

  Result               = PMUECCEDC_TIMEOUT_DBEALARM;
  DbeHlpr.SmuAlm       = &SMU_AG2;
  DbeHlpr.SmuCmd       = &SMU_CMD;
  DbeHlpr.FlashTrapDis = &FLASH0_MARP;
  DbeHlpr.FlashCmd     = TestData->FlashCmd;
  DbeHlpr.SmuAlmAfter  = 0U;
  DbeHlpr.SmuAlmBefore = 0U;
  DbeHlpr.SmuAlmMask   = PMUT_SMU_ALARM_SETALL;

  /* Calculate and compare Crc of functions in RAM that 
   were copied from PFlash at startup*/   
  ResultTmp = PmuEccEdcTst_lRamCalculateandVerifyCrc32(PMUECCEDC_CODE);
  if (PMUECCEDC_SUCCESS != ResultTmp)
  {
    Result = ResultTmp;
  } /* if (PMUECCEDC_SUCCESS != ResultTmp) */
  else
  {
    for (i = 0U; ((i < PMUT_TEST_PATTERN_COUNT) &&
        (Result != (Sl_TstRsltType)PMUECCEDC_SUCCESS)); i++)
    {
      /* Check that access to DBE word does generate an SMU alarm */
      DbeHlpr.DataAddrA =
          &(TestData->FlashPattern->Set[i].Pattern[PMUT_DBE_PTRN_IDX]);
      Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);
      Mcal_ResetENDINIT();

      ResultTmp = PmuEccEdcTst_lEccHelper(&DbeHlpr);

      Mcal_SetENDINIT();
      Mcal_SetSafetyENDINIT_Timed();

      PmuEccEdcTst_lCountUnExpectAlm(DbeHlpr.SmuAlmBefore);

      /* Check result of helper routine: */
      if (PMUECCEDC_SUCCESS != ResultTmp)
      {
        Result = ResultTmp;
        break;
      } /* if (PMUECCEDC_SUCCESS != ResultTmp) */
      else
      {
        if ((DbeHlpr.SmuAlmAfter & PMUT_SMU_ALARM_SETALL) == PMUT_SMU_ALARM3)
        {
          Result = PMUECCEDC_SUCCESS;
        } /* if ((DbeHlpr.SmuAlmAfter & PMUT_SMU_ALARM_SETALL) ==
                 PMUT_SMU_ALARM3) */
      } /* if (PMUECCEDC_SUCCESS == ResultTmp) */
    } /* for (i = 0U; i < PMUT_TEST_PATTERN_COUNT; i++) */
  } /* if (PMUECCEDC_SUCCESS == ResultTmp) */

  *(TestData->Signature) = (uint32)CRC32(*(TestData->Signature),
                                      (DbeHlpr.SmuAlmAfter & PMUT_SMU_ALARM3));

  return Result;
} /* PmuEccEdcTst_lTestEccSmuSgnlDbe */


/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : Sl_TstRsltType PmuEccEdcTst_lTestEccSmuSgnlMbe                    **
**          (                                                                 **
**            const PmuEccEdcTst_TestDataType* TestData                       **
**          )                                                                 **
**                                                                            **
** Description : Check Multiple Bit Errors are correctly signaled to the SMU  **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) : TestData       - Pointer to test data set                **
**                                                                            **
** Parameters (out): TstSignature - Test signature generated by the test      **
**                                                                            **
** Return value :                                                             **
**      PMUECCEDC_SUCCESS           - Test succeeded                          **
**      PMUECCEDC_TIMEOUT_MBEALARM  - mbe SMU alarm timed out                 **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType PmuEccEdcTst_lTestEccSmuSgnlMbe
(
  const PmuEccEdcTst_TestDataType* TestData
)
{
  Sl_TstRsltType            Result = PMUECCEDC_NOTEXECUTED;
  Sl_TstRsltType            ResultTmp;
  uint32                    i;
  PmuEccEdcTst_EccHlprType  MbeHlpr;

  Result               = PMUECCEDC_TIMEOUT_MBEALARM;

  MbeHlpr.SmuAlm       = &SMU_AG2;
  MbeHlpr.SmuCmd       = &SMU_CMD;
  MbeHlpr.FlashTrapDis = &FLASH0_MARP;
  MbeHlpr.FlashCmd     = TestData->FlashCmd;
  MbeHlpr.SmuAlmAfter  = 0U;
  MbeHlpr.SmuAlmBefore = 0U;
  MbeHlpr.SmuAlmMask   = PMUT_SMU_ALARM_SETALL;

  /* Calculate and compare Crc of functions in RAM that 
   were copied from PFlash at startup*/   
  ResultTmp = PmuEccEdcTst_lRamCalculateandVerifyCrc32(PMUECCEDC_CODE);
  if (PMUECCEDC_SUCCESS != ResultTmp)
  {
    Result = ResultTmp;
  } /* if (PMUECCEDC_SUCCESS != ResultTmp) */
  else
  {
    for (i = 0U; ((i < PMUT_TEST_PATTERN_COUNT) &&
        (Result != (Sl_TstRsltType)PMUECCEDC_SUCCESS)); i++)
    {
      /* Check that access to Mbe word does generate an SMU alarm */
      MbeHlpr.DataAddrA =
          &(TestData->FlashPattern->Set[i].Pattern[PMUT_MBE_PTRN_IDX]);
      Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);
      Mcal_ResetENDINIT();

      ResultTmp = PmuEccEdcTst_lEccHelper(&MbeHlpr);

      Mcal_SetENDINIT();
      Mcal_SetSafetyENDINIT_Timed();

      PmuEccEdcTst_lCountUnExpectAlm(MbeHlpr.SmuAlmBefore);

      /* Check result of helper routine: */
      if (PMUECCEDC_SUCCESS != ResultTmp)
      {
        Result = ResultTmp;
        break;
      } /* if (PMUECCEDC_SUCCESS != ResultTmp) */
      else
      {
        if ((MbeHlpr.SmuAlmAfter & PMUT_SMU_ALARM_SETALL) == PMUT_SMU_ALARM4)
        {
          Result = PMUECCEDC_SUCCESS;
        } /* if ((MbeHlpr.SmuAlmAfter & PMUT_SMU_ALARM_SETALL) ==
                 PMUT_SMU_ALARM4) */
      } /* if (PMUECCEDC_SUCCESS == ResultTmp) */
    } /* for (i = 0U; i < PMUT_TEST_PATTERN_COUNT; i++) */
  } /* if (PMUECCEDC_SUCCESS == ResultTmp) */

  *(TestData->Signature) = (uint32) CRC32(*(TestData->Signature),
                                      (MbeHlpr.SmuAlmAfter & PMUT_SMU_ALARM4));

  return Result;
} /* PmuEccEdcTst_lTestEccSmuSgnlMbe */


/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : Sl_TstRsltType PmuEccEdcTst_lTestEccOnlnMon                       **
**          (                                                                 **
**            const PmuEccEdcTst_TestDataType* TestData                       **
**          )                                                                 **
**                                                                            **
** Description : Check that Edc/ecc Monitors create alarms                    **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) : TestData       - Pointer to test data set                **
**                                                                            **
** Parameters (out): TstSignature - Test signature generated by the test      **
**                                                                            **
** Return value :                                                             **
**      PMUECCEDC_SUCCESS           - Test succeeded                          **
**      PMUECCEDC_TIMEOUT_ECCMONALARM - ECC monitor SMU alarm timed out       **
**      PMUECCEDC_DATACORRUPTION    - valid data corrupted by ECC logic       **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType PmuEccEdcTst_lTestEccOnlnMon
(
  const PmuEccEdcTst_TestDataType* TestData
)
{
  Sl_TstRsltType Result = PMUECCEDC_NOTEXECUTED;

  Result = PmuEccEdcTst_lTestEccCorruption(TestData);
  if (Result == PMUECCEDC_SUCCESS)
  {
    Result = PmuEccEdcTst_lTestSbeCorrection(TestData);
    if (Result == PMUECCEDC_SUCCESS)
    {
      Result = PmuEccEdcTst_lTestDbeCorrection(TestData);
      if (Result == PMUECCEDC_SUCCESS)
      {
        Result = PmuEccEdcTst_lTestEccMonAlarm(TestData);
      } /* if (Result == PMUECCEDC_SUCCESS) */
    } /* if (Result == PMUECCEDC_SUCCESS) */
  } /* if (Result == PMUECCEDC_SUCCESS) */

  return Result;
} /* PmuEccEdcTst_lTestEccOnlnMon */

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : Sl_TstRsltType PmuEccEdcTst_lTestEccCorruption                    **
**          (                                                                 **
**            const PmuEccEdcTst_TestDataType* TestData                       **
**          )                                                                 **
**                                                                            **
** Description : Check that good data is not actively corrupted               **
**               by the ECC logic                                             **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) : TestData       - Pointer to test data set                **
**                                                                            **
** Parameters (out): TstSignature - Test signature generated by the test      **
**                                                                            **
** Return value :                                                             **
**      PMUECCEDC_SUCCESS           - Test succeeded                          **
**      PMUECCEDC_DATACORRUPTION    - valid data corrupted by ECC logic       **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType PmuEccEdcTst_lTestEccCorruption
(
  const PmuEccEdcTst_TestDataType* TestData
)
{
  Sl_TstRsltType                  Result = PMUECCEDC_NOTEXECUTED;
  Sl_TstRsltType                  ResultTmp;
  uint32                          i;
  PmuEccEdcTst_EccHlprType        EccHlpr;

  Result               = PMUECCEDC_DATACORRUPTION;

  EccHlpr.SmuAlm       = &SMU_AG2;
  EccHlpr.SmuCmd       = &SMU_CMD;
  EccHlpr.FlashTrapDis = &FLASH0_MARP;
  EccHlpr.FlashCmd     = TestData->FlashCmd;
  EccHlpr.SmuAlmAfter  = 0U;
  EccHlpr.SmuAlmBefore = 0U;
  EccHlpr.SmuAlmMask   = PMUT_SMU_ALARM_SETALL;
  EccHlpr.PageEqual    = (boolean)FALSE;

  /* Calculate and compare Crc of functions in RAM that 
   were copied from PFlash at startup*/   
  ResultTmp = PmuEccEdcTst_lRamCalculateandVerifyCrc32(PMUECCEDC_CODE);
  if (PMUECCEDC_SUCCESS != ResultTmp)
  {
    Result = ResultTmp;
  } /* if (PMUECCEDC_SUCCESS != ResultTmp) */
  else
  {
    for (i = 0U; ((i < PMUT_TEST_PATTERN_COUNT) &&
        (Result != (Sl_TstRsltType)PMUECCEDC_SUCCESS)); i++)
    {
      /* Check that access to valid words does not do wrong corrections */
      EccHlpr.DataAddrA =
          &(TestData->FlashPattern->Set[i].Pattern[PMUT_VCW_PTRN_IDX]);
      EccHlpr.DataAddrRef = &PmuEccEdcTst_VcwRefPtrn[i];

      Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);
      Mcal_ResetENDINIT();

      ResultTmp = PmuEccEdcTst_lComparePageHelper(&EccHlpr);

      Mcal_SetENDINIT();
      Mcal_SetSafetyENDINIT_Timed();

      PmuEccEdcTst_lCountUnExpectAlm(EccHlpr.SmuAlmBefore);

      /* Check result of helper routine: */
      if (PMUECCEDC_SUCCESS != ResultTmp)
      {
        Result = ResultTmp;
        break;
      } /* if (PMUECCEDC_SUCCESS != ResultTmp) */
      else
      {
        if (TRUE == EccHlpr.PageEqual)
        {
          Result = PMUECCEDC_SUCCESS;
        } /* if (TRUE == EccHlpr.PageEqual) */
      } /* if (PMUECCEDC_SUCCESS == ResultTmp) */
    } /* for (i = 0U; i < PMUT_TEST_PATTERN_COUNT; i++) */
  } /* if (PMUECCEDC_SUCCESS == ResultTmp) */

  *(TestData->Signature) = (uint32)CRC32(*(TestData->Signature),
                                         (uint32)EccHlpr.PageEqual);

  return Result;
} /* PmuEccEdcTst_lTestEccCorruption */

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : Sl_TstRsltType PmuEccEdcTst_lTestSbeCorrection                    **
**          (                                                                 **
**              const PmuEccEdcTst_TestDataType* TestData                     **
**          )                                                                 **
**                                                                            **
** Description : Check that corrupted data is correctly modified              **
**               by the ECC logic                                             **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) : TestData       - Pointer to test data set                **
**                                                                            **
** Parameters (out): TstSignature - Test signature generated by the test      **
**                                                                            **
** Return value :                                                             **
**      PMUECCEDC_SUCCESS           - Test succeeded                          **
**      PMUECCEDC_DATACORRUPTION    - valid data corrupted by ECC logic       **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType PmuEccEdcTst_lTestSbeCorrection
(
  const PmuEccEdcTst_TestDataType* TestData
)
{
  Sl_TstRsltType                  Result = PMUECCEDC_NOTEXECUTED;
  Sl_TstRsltType                  ResultTmp;
  uint32                          i;
  PmuEccEdcTst_EccHlprType        EccHlpr;

  Result               = PMUECCEDC_DATACORRUPTION;

  EccHlpr.SmuAlm       = &SMU_AG2;
  EccHlpr.SmuCmd       = &SMU_CMD;
  EccHlpr.FlashTrapDis = &FLASH0_MARP;
  EccHlpr.FlashCmd     = TestData->FlashCmd;
  EccHlpr.SmuAlmAfter  = 0U;
  EccHlpr.SmuAlmBefore = 0U;
  EccHlpr.SmuAlmMask   = PMUT_SMU_ALARM_SETALL;
  EccHlpr.PageEqual    = (boolean)FALSE;

  /* Calculate and compare Crc of functions in RAM that 
   were copied from PFlash at startup*/   
  ResultTmp = PmuEccEdcTst_lRamCalculateandVerifyCrc32(PMUECCEDC_CODE);
  if (PMUECCEDC_SUCCESS != ResultTmp)
  {
    Result = ResultTmp;
  } /* if (PMUECCEDC_SUCCESS != ResultTmp) */
  else
  {
    for (i = 0U; ((i < PMUT_TEST_PATTERN_COUNT) &&
        (Result != (Sl_TstRsltType)PMUECCEDC_SUCCESS)); i++)
    {
      /* Check that access to valid words does not do wrong corrections */
      EccHlpr.DataAddrA =
          &(TestData->FlashPattern->Set[i].Pattern[PMUT_SBE_PTRN_IDX]);
      EccHlpr.DataAddrRef = &PmuEccEdcTst_SbeRefPtrn[i];

      Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);
      Mcal_ResetENDINIT();

      ResultTmp = PmuEccEdcTst_lComparePageHelper(&EccHlpr);

      Mcal_SetENDINIT();
      Mcal_SetSafetyENDINIT_Timed();

      PmuEccEdcTst_lCountUnExpectAlm(EccHlpr.SmuAlmBefore);

      /* Check result of helper routine: */
      if (PMUECCEDC_SUCCESS != ResultTmp)
      {
        Result = ResultTmp;
        break;
      } /* if (PMUECCEDC_SUCCESS != ResultTmp) */
      else
      {
        if (TRUE == EccHlpr.PageEqual)
        {
          Result = PMUECCEDC_SUCCESS;
        } /* if (TRUE == EccHlpr.PageEqual) */
      } /* if (PMUECCEDC_SUCCESS == ResultTmp) */
    } /* for (i = 0U; i < PMUT_TEST_PATTERN_COUNT; i++) */
  } /* if (PMUECCEDC_SUCCESS == ResultTmp) */

  *(TestData->Signature) = (uint32)CRC32(*(TestData->Signature),
                                         (uint32)EccHlpr.PageEqual);

  return Result;
} /* PmuEccEdcTst_lTestSbeCorrection */


/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : Sl_TstRsltType PmuEccEdcTst_lTestDbeCorrection                    **
**          (                                                                 **
**            const PmuEccEdcTst_TestDataType* TestData                       **
**          )                                                                 **
**                                                                            **
** Description : Check that corrupted data is correctly modified              **
**               by the ECC logic                                             **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) : TestData       - Pointer to test data set                **
**                                                                            **
** Parameters (out): TstSignature - Test signature generated by the test      **
**                                                                            **
** Return value :                                                             **
**      PMUECCEDC_SUCCESS           - Test succeeded                          **
**      PMUECCEDC_DATACORRUPTION    - valid data corrupted by ECC logic       **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType PmuEccEdcTst_lTestDbeCorrection
(
  const PmuEccEdcTst_TestDataType* TestData
)
{
  Sl_TstRsltType                  Result = PMUECCEDC_NOTEXECUTED;
  Sl_TstRsltType                  ResultTmp;
  uint32                          i;
  PmuEccEdcTst_EccHlprType        EccHlpr;

  Result               = PMUECCEDC_DATACORRUPTION;

  EccHlpr.SmuAlm       = &SMU_AG2;
  EccHlpr.SmuCmd       = &SMU_CMD;
  EccHlpr.FlashTrapDis = &FLASH0_MARP;
  EccHlpr.FlashCmd     = TestData->FlashCmd;
  EccHlpr.SmuAlmAfter  = 0U;
  EccHlpr.SmuAlmBefore = 0U;
  EccHlpr.SmuAlmMask   = PMUT_SMU_ALARM_SETALL;
  EccHlpr.PageEqual    = (boolean)FALSE;

  /* Calculate and compare Crc of functions in RAM that 
   were copied from PFlash at startup*/   
  ResultTmp = PmuEccEdcTst_lRamCalculateandVerifyCrc32(PMUECCEDC_CODE);
  if (PMUECCEDC_SUCCESS != ResultTmp)
  {
    Result = ResultTmp;
  } /* if (PMUECCEDC_SUCCESS != ResultTmp) */
  else
  {
    for (i = 0U; ((i < PMUT_TEST_PATTERN_COUNT) &&
        (Result != (Sl_TstRsltType)PMUECCEDC_SUCCESS)); i++)
    {
      /* Check that access to valid words does not do wrong corrections */
      EccHlpr.DataAddrA =
          &(TestData->FlashPattern->Set[i].Pattern[PMUT_DBE_PTRN_IDX]);
      EccHlpr.DataAddrRef = &PmuEccEdcTst_DbeRefPtrn[i];

      Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);
      Mcal_ResetENDINIT();

      ResultTmp = PmuEccEdcTst_lComparePageHelper(&EccHlpr);

      Mcal_SetENDINIT();
      Mcal_SetSafetyENDINIT_Timed();

      PmuEccEdcTst_lCountUnExpectAlm(EccHlpr.SmuAlmBefore);

      /* Check result of helper routine: */
      if (PMUECCEDC_SUCCESS != ResultTmp)
      {
        Result = ResultTmp;
        break;
      } /* if (PMUECCEDC_SUCCESS != ResultTmp) */
      else
      {
        if (TRUE == EccHlpr.PageEqual)
        {
          Result = PMUECCEDC_SUCCESS;
        } /* if (TRUE == EccHlpr.PageEqual) */
      } /* if (PMUECCEDC_SUCCESS == ResultTmp) */
    } /* for (i = 0U; i < PMUT_TEST_PATTERN_COUNT; i++) */
  } /* if (PMUECCEDC_SUCCESS == ResultTmp) */

  *(TestData->Signature) = (uint32)CRC32(*(TestData->Signature),
                                         (uint32)EccHlpr.PageEqual);

  return Result;
} /* PmuEccEdcTst_lTestDbeCorrection */

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : Sl_TstRsltType PmuEccEdcTst_lTestEccMonAlarm                      **
**          (                                                                 **
**            const PmuEccEdcTst_TestDataType* TestData                       **
**          )                                                                 **
**                                                                            **
** Description : Check that Ecc Monitors create alarms                        **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) : TestData       - Pointer to test data set                **
**                                                                            **
** Parameters (out): TstSignature - Test signature generated by the test      **
**                                                                            **
** Return value :                                                             **
**      PMUECCEDC_SUCCESS           - Test succeeded                          **
**      PMUECCEDC_TIMEOUT_ECCMONALARM - ECC monitor SMU alarm timed out       **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType PmuEccEdcTst_lTestEccMonAlarm
(
  const PmuEccEdcTst_TestDataType* TestData
)
{
  Sl_TstRsltType              Result = PMUECCEDC_NOTEXECUTED;
  Sl_TstRsltType              ResultTmp;
  PmuEccEdcTst_EccHlprType    EccHlpr;
  uint32                      i;

  Result               = PMUECCEDC_TIMEOUT_ECCMONALARM;

  EccHlpr.SmuAlm       = &SMU_AG2;
  EccHlpr.SmuCmd       = &SMU_CMD;
  EccHlpr.FlashTrapDis = &FLASH0_MARP;
  EccHlpr.FlashCmd     = TestData->FlashCmd;
  EccHlpr.SmuAlmAfter  = 0U;
  EccHlpr.SmuAlmBefore = 0U;
  EccHlpr.SmuAlmMask   = PMUT_SMU_ALARM_SETALL;

  /* Calculate and compare Crc of functions in RAM that 
   were copied from PFlash at startup*/   
  ResultTmp = PmuEccEdcTst_lRamCalculateandVerifyCrc32(PMUECCEDC_CODE);
  if (PMUECCEDC_SUCCESS != ResultTmp)
  {
    Result = ResultTmp;
  } /* if (PMUECCEDC_SUCCESS != ResultTmp) */
  else
  {
    for (i = 0U; ((i < PMUT_TEST_PATTERN_COUNT) &&
        (Result != (Sl_TstRsltType)PMUECCEDC_SUCCESS)); i++)
    {
      /* Setup flash page that is read to create an alarm: */
      EccHlpr.DataAddrA =
          &(TestData->FlashPattern->Set[i].Pattern[PMUT_SBE_PTRN_IDX]);

      /* Setup flash page that is read to clear the internal error flag in PMU:
       */
      EccHlpr.DataAddrB =
          &(TestData->FlashPattern->Set[i].Pattern[PMUT_VCW_PTRN_IDX]);

      Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);
      Mcal_ResetENDINIT();

      ResultTmp = PmuEccEdcTst_lEccMonHelper(TestData, &EccHlpr);

      Mcal_SetENDINIT();
      Mcal_SetSafetyENDINIT_Timed();

      PmuEccEdcTst_lCountUnExpectAlm(EccHlpr.SmuAlmBefore);

      /* Check result of helper routine: */
      if (PMUECCEDC_SUCCESS != ResultTmp)
      {
        Result = ResultTmp;
        break;
      } /* if (PMUECCEDC_SUCCESS != ResultTmp) */
      else
      {
        if ((EccHlpr.SmuAlmAfter & PMUT_SMU_ALARM_SETALL) ==
            (PMUT_SMU_ALARM2 | PMUT_SMU_ALARM7))
        {
          Result = PMUECCEDC_SUCCESS;
        } /* if ((EccHlpr.SmuAlmAfter & PMUT_SMU_ALARM_SETALL) ==
                 (PMUT_SMU_ALARM2 | PMUT_SMU_ALARM7)) */
      } /* if (PMUECCEDC_SUCCESS == ResultTmp) */
    } /* for (i = 0U; i < PMUT_TEST_PATTERN_COUNT; i++) */
  } /* if (PMUECCEDC_SUCCESS == ResultTmp) */

  *(TestData->Signature) = (uint32) CRC32(*(TestData->Signature),
                                      (EccHlpr.SmuAlmAfter & PMUT_SMU_ALARM7));

  return Result;
} /* PmuEccEdcTst_lTestEccMonAlarm */





/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : Sl_TstRsltType PmuEccEdcTst_lTestEdcCmp                           **
**          (                                                                 **
**            const PmuEccEdcTst_TestDataType* TestData                       **
**          )                                                                 **
**                                                                            **
** Description : Reads SBE, DBE and MBE patterns with EDC comparator error    **
**               injection enabled and checks that EDC comparator SMU alarms  **
**               are generated.                                               **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) : TestData       - Pointer to test data set                **
**                                                                            **
** Parameters (out): TstSignature - Test signature generated by the test      **
**                                                                            **
** Return value :                                                             **
**      PMUECCEDC_SUCCESS             - Test succeeded                        **
**      PMUECCEDC_TIMEOUT_EDCCMPALARM - Waiting for an SMU alarm timed out    **
**      PMUECCEDC_SMU_CLRALMSTSERR    - Clearing SMU alarm status failed      **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType PmuEccEdcTst_lTestEdcCmp
(
  const PmuEccEdcTst_TestDataType* TestData
)
{
  Sl_TstRsltType              Result = PMUECCEDC_NOTEXECUTED;
  Sl_TstRsltType              ResultTmp;
  PmuEccEdcTst_EccHlprType    CmpHlpr;
  uint32                      AlmSbe = 0U;
  uint32                      AlmDbe = 0U;
  uint32                      AlmMbe = 0U;
  uint32                      i;

  Result                = PMUECCEDC_TIMEOUT_EDCCMPALARM;
  CmpHlpr.SmuAlm        = &SMU_AG2;
  CmpHlpr.SmuCmd        = &SMU_CMD;
  CmpHlpr.FlashTrapDis  = &FLASH0_MARP;
  CmpHlpr.FlashCmd      = TestData->FlashCmd;
  CmpHlpr.SmuAlmAfter   = 0U;
  CmpHlpr.SmuAlmBefore  = 0U;
  CmpHlpr.SmuAlmMask    = PMUT_SMU_ALARM_SETALL;
  CmpHlpr.EccrpPtr      = TestData->FlashEccrpPtr;

  /* Enable EDC Error Injection and read from valid FLASH */

  /* Calculate and compare Crc of functions in RAM that 
   were copied from PFlash at startup*/   
  ResultTmp = PmuEccEdcTst_lRamCalculateandVerifyCrc32(PMUECCEDC_CODE);
  if (PMUECCEDC_SUCCESS != ResultTmp)
  {
    Result = ResultTmp;
  } /* if (PMUECCEDC_SUCCESS != ResultTmp) */
  else
  {
    for (i = 0U; ((i < PMUT_TEST_PATTERN_COUNT) &&
        (Result != (Sl_TstRsltType)PMUECCEDC_SMU_CLRALMSTSERR)); i++)
    {
      /* Use read access to VCW page to clear the PMU internal error flag: */
      CmpHlpr.DataAddrB =
          &(TestData->FlashPattern->Set[i].Pattern[PMUT_VCW_PTRN_IDX]);

      /* Check EDC comparator with reading single bit error page: */
      CmpHlpr.DataAddrA =
          &(TestData->FlashPattern->Set[i].Pattern[PMUT_SBE_PTRN_IDX]);
      Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT); 
      Mcal_ResetENDINIT();  /* interrupts are disabled implicitly */
      ResultTmp = PmuEccEdcTst_lEdcCmpHelper(&CmpHlpr);
      Mcal_SetENDINIT();
      Mcal_SetSafetyENDINIT_Timed();
      AlmSbe = CmpHlpr.SmuAlmAfter;
      PmuEccEdcTst_lCountUnExpectAlm(CmpHlpr.SmuAlmBefore);

      /* Check result of helper routine: */
      if (PMUECCEDC_SUCCESS != ResultTmp)
      {
        Result = ResultTmp;
      } /* if (PMUECCEDC_SUCCESS != ResultTmp) */
      else
      {
        /* Check EDC comparator with reading double bit error page: */
        CmpHlpr.DataAddrA =
            &(TestData->FlashPattern->Set[i].Pattern[PMUT_DBE_PTRN_IDX]);
        Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT); 
        Mcal_ResetENDINIT();  /* interrupts are disabled implicitly */
        ResultTmp = PmuEccEdcTst_lEdcCmpHelper(&CmpHlpr);
        Mcal_SetENDINIT();
        Mcal_SetSafetyENDINIT_Timed();
        AlmDbe = CmpHlpr.SmuAlmAfter;
        PmuEccEdcTst_lCountUnExpectAlm(CmpHlpr.SmuAlmBefore);

        /* Check result of helper routine: */
        if (PMUECCEDC_SUCCESS != ResultTmp)
        {
          Result = ResultTmp;
        } /* if (PMUECCEDC_SUCCESS != ResultTmp) */
        else
        {
          /* Check EDC comparator with reading multi bit error page: */
          CmpHlpr.DataAddrA =
              &(TestData->FlashPattern->Set[i].Pattern[PMUT_MBE_PTRN_IDX]);
          Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);
          Mcal_ResetENDINIT();  /* interrupts are disabled implicitly */
          ResultTmp = PmuEccEdcTst_lEdcCmpHelper(&CmpHlpr);
          Mcal_SetENDINIT();
          Mcal_SetSafetyENDINIT_Timed();
          AlmMbe = CmpHlpr.SmuAlmAfter;
          PmuEccEdcTst_lCountUnExpectAlm(CmpHlpr.SmuAlmBefore);

          /* Check result of helper routine: */
          if (PMUECCEDC_SUCCESS != ResultTmp)
          {
            Result = ResultTmp;
          } /* if (PMUECCEDC_SUCCESS != ResultTmp) */
        } /* if (PMUECCEDC_SUCCESS == ResultTmp) */
      } /* if (PMUECCEDC_SUCCESS == ResultTmp) */

      /* Check if all alarms were triggered: */
      if (((AlmSbe & PMUT_SMU_ALARM_SETALL) ==
          (PMUT_SMU_ALARM2 | PMUT_SMU_ALARM8)) &&
          ((AlmDbe & PMUT_SMU_ALARM_SETALL) ==
          (PMUT_SMU_ALARM3 | PMUT_SMU_ALARM8)) &&
          ((AlmMbe & PMUT_SMU_ALARM_SETALL) ==
          (PMUT_SMU_ALARM4 | PMUT_SMU_ALARM8)))
      {
        Result = PMUECCEDC_SUCCESS;
        break;
      } /* if (((AlmSbe & PMUT_SMU_ALARM_SETALL) ==
               (PMUT_SMU_ALARM2 | PMUT_SMU_ALARM8)) &&
               ((AlmDbe & PMUT_SMU_ALARM_SETALL) ==
               (PMUT_SMU_ALARM3 | PMUT_SMU_ALARM8)) &&
               ((AlmMbe & PMUT_SMU_ALARM_SETALL) ==
               (PMUT_SMU_ALARM4 | PMUT_SMU_ALARM8))) */
    } /* for (i = 0U; i < PMUT_TEST_PATTERN_COUNT; i++) */
  } /* if (PMUECCEDC_SUCCESS == ResultTmp) */

  /* Update test signature: */
  *(TestData->Signature) = (uint32) CRC32(*(TestData->Signature),
                                          (AlmSbe & PMUT_SMU_ALARM_SETALL));
  *(TestData->Signature) = (uint32) CRC32(*(TestData->Signature),
                                          (AlmDbe & PMUT_SMU_ALARM_SETALL));
  *(TestData->Signature) = (uint32) CRC32(*(TestData->Signature),
                                          (AlmMbe & PMUT_SMU_ALARM_SETALL));

  return Result;
} /* PmuEccEdcTst_lTestEdcCmp */



/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : void PmuEccEdcTst_lCountUnExpectAlm                               **
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
static void PmuEccEdcTst_lCountUnExpectAlm
(
  uint32 CurrAlmStatus
)
{
  if ((CurrAlmStatus & PMUT_SMU_ALARM2) != 0U)
  {
    PmuEccEdcTst_UnexpAlm.Sbe++;
  } /* if ((CurrAlmStatus & PMUT_SMU_ALARM2) != 0U) */

  if ((CurrAlmStatus & PMUT_SMU_ALARM3) != 0U)
  {
    PmuEccEdcTst_UnexpAlm.Dbe++;
  } /* if ((CurrAlmStatus & PMUT_SMU_ALARM3) != 0U) */

  if ((CurrAlmStatus & PMUT_SMU_ALARM4) != 0U)
  {
    PmuEccEdcTst_UnexpAlm.Mbe++;
  } /* if ((CurrAlmStatus & PMUT_SMU_ALARM4) != 0U) */

  if ((CurrAlmStatus & PMUT_SMU_ALARM7) != 0U)
  {
    PmuEccEdcTst_UnexpAlm.Mon++;
  } /* if ((CurrAlmStatus & PMUT_SMU_ALARM7) != 0U) */

  if ((CurrAlmStatus & PMUT_SMU_ALARM8) != 0U)
  {
    PmuEccEdcTst_UnexpAlm.Cmp++;
  } /* if ((CurrAlmStatus & PMUT_SMU_ALARM8) != 0U) */

  PmuEccEdcTst_UnexpAlm.Crc32 = PmuEccEdcTst_lCalcAlmCounterCrc();
} /* PmuEccEdcTst_lCountUnExpectAlm */


/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : LOCAL_INLINE uint32 PmuEccEdcTst_lCalcAlmCounterCrc               **
**          (                                                                 **
**            void                                                            **
**          )                                                                 **
**                                                                            **
** Description : Calculates the CRC over all members of the                   **
**               PmuEccEdcTst_UnexpAlm unexpected alarm structure.            **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value : Requested alarm counter CRC value                           **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE uint32 PmuEccEdcTst_lCalcAlmCounterCrc
(
  void
)
{
  uint32  Result;

  Result = (uint32)CRC32(PmuEccEdcTst_UnexpAlm.Sbe, PmuEccEdcTst_UnexpAlm.Dbe);
  Result = (uint32)CRC32(Result, PmuEccEdcTst_UnexpAlm.Mbe);
  Result = (uint32)CRC32(Result, PmuEccEdcTst_UnexpAlm.Mon);
  Result = (uint32)CRC32(Result, PmuEccEdcTst_UnexpAlm.Cmp);

 return Result;
} /* PmuEccEdcTst_lCalcAlmCounterCrc */

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : void PmuEccEdcTst_lSetupTrapHandling                              **
**          (                                                                 **
**            void                                                            **
**          )                                                                 **
**                                                                            **
** Description : Sets the BTV to point to the customized trap table in        **
**               PSPR SRAM                                                    **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value : None                                                        **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType PmuEccEdcTst_lSetupTrapHandling
(
  void
)
{
  Sl_TstRsltType              Result = PMUECCEDC_NOTEXECUTED;
  Sl_TstRsltType              ResultTmp;

  /* Invalidate BTV backup value (to skip restoration in case of error): */
  PmuEccEdcTst_BtvBackup = PMUT_INVALID_BTV_VALUE;

  /* Backup FLASH0_MARP: */
  PmuEccEdcTst_Flash0MarpBackup = FLASH0_MARP.U;

  /* Calculate and compare Crc of functions in RAM that 
   were copied from PFlash at startup*/   
                                          
  ResultTmp = PmuEccEdcTst_lRamCalculateandVerifyCrc32(PMUECCEDC_CODE);
  
  if (PMUECCEDC_SUCCESS != ResultTmp)
  {
    Result = ResultTmp;
  } /* if (PMUECCEDEC_SUCCESS != ResultTmp) */
  else
  {
    
    Result = PmuEccEdcTst_lRamCalculateandVerifyCrc32(PMUECCEDC_TVT);        

    if (PMUECCEDC_SUCCESS == Result)
    {
      /* Backup and switch BTV: */
      PmuEccEdcTst_BtvBackup = (uint32)MFCR(CPU_BTV);
      Mcal_ResetENDINIT();
      MTCR(CPU_BTV, (uint32)&PmuEccEdcTst_lTrapVectors);
      Mcal_SetENDINIT();
    } /* if (PMUECCEDC_SUCCESS == Result) */
  } /* if (PMUECCEDEC_SUCCESS == ResultTmp) */

  return Result;
} /* PmuEccEdcTst_lSetupTrapHandling */

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : void PmuEccEdcTst_lRestoreTrapHandling                            **
**          (                                                                 **
**            void                                                            **
**          )                                                                 **
**                                                                            **
** Description : Restores the original trap vector table as it has been       **
**               before the test.                                             **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value : None                                                        **
**                                                                            **
*******************************************************************************/
static void PmuEccEdcTst_lRestoreTrapHandling
(
  void
)
{
  /* Skip BTV restoration in case trap setup failed: */
  if (PMUT_INVALID_BTV_VALUE != PmuEccEdcTst_BtvBackup)
  {
    /* Restore BTV: */
    Mcal_ResetENDINIT();
    MTCR(CPU_BTV, PmuEccEdcTst_BtvBackup);
    Mcal_SetENDINIT();
  } /* if (PMUT_INVALID_BTV_VALUE != PmuEccEdcTst_BtvBackup) */
} /* PmuEccEdcTst_lRestoreTrapHandling */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : uint32 PmuEccEdcTst_CalculateCrc32              **
**                    (                                                       **
**                      uint32* StartAddr,                                    **
**                      uint32 Size                                           **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : StartAddr - Holds the start address of the memory       **
**                                section                                     **
**                    Size - Size of the memory section in bytes              **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : CRC32 value of the section given as input               **
**                                                                            **
** Description      : It calculates the CRC32 value of all the words in the   **
**                    memory section given as input                           **
**                                                                            **
*******************************************************************************/
uint32 PmuEccEdcTst_CalculateCrc32(const uint32 StartAddr[], uint32 Size)
{
  uint32 i = 0U;
  uint32 crc32 = 0U;
  volatile uint32 temp = 0U, lastword = 0U;
  uint32 tempSize;
  volatile uint32 extrabytes = 0U;
  
  /*tempSize is the number of words*/
  tempSize = Size/(uint32)BYTES_IN_WORD;
  
  crc32 = (uint32)CRC32((uint32)StartAddr[0], (uint32)StartAddr[1]);

  for(i = 2U; i<tempSize; i++)
  {
    crc32 = (uint32)CRC32(crc32, ((uint32)StartAddr[i]));
  }
  /* If Size is not a multiple of 4, then the following code addresses
  the calculation of the final CRC value that includes the missed out 
  bytes*/
  if((Size%(uint32)BYTES_IN_WORD)!=0U)
  {
    /*Calculate number of extra bytes*/
    extrabytes = (Size%(uint32)BYTES_IN_WORD);
    /*Read the last word*/
    temp = ((uint32)StartAddr[i]);
    /*Re-use i for calculating the shift amount*/
    i = (BYTES_IN_WORD - extrabytes)*BITS_IN_BYTE;
    /*Extract exact value by filling MSB with 0*/
    lastword = (uint32)(0xFFFFFFFFU >> i);
    lastword = lastword & temp;

    /*Calculate CRC with last word*/
    crc32 = (uint32)CRC32(crc32, lastword);
  }
  return crc32;
}/*PmuEccEdcTst_CalculateCrc32*/
/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           :                                                         **
**          static Std_ReturnType PmuEccEdcTst_lRamCalculateandVerifyCrc32    **
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
** Parameters(in)   : type -    PMUECCEDC_TVT - Trap vector table source code **
**                              PMUECCEDC_CODE - Other source code            **
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
static Sl_TstRsltType PmuEccEdcTst_lRamCalculateandVerifyCrc32(uint32 type)
{
  uint32 crcvalue = 0U;
  Sl_TstRsltType  Result = PMUECCEDC_CRCERROR;
  
  uint32 beginaddr, endaddr;
  
  if(type == PMUECCEDC_CODE)
  {
    endaddr = (uint32)LOC_END_PflashMon_EccEdc_RAM_RUNCODE;
    beginaddr = (uint32)LOC_START_PflashMon_EccEdc_RAM_RUNCODE;
  
    crcvalue = PmuEccEdcTst_CalculateCrc32(LOC_START_PflashMon_EccEdc_RAM_RUNCODE,
           (endaddr-beginaddr));
            
    if(crcvalue == PmuEccEdcTst_PFlashFnCrc32)
    {
      Result = PMUECCEDC_SUCCESS;
    }
  }
  else if(type == PMUECCEDC_TVT)
  {
    endaddr = (uint32)LOC_END_PmuEccEdcTst_tvt_RAM_RUNCODE;
    beginaddr = (uint32)LOC_START_PmuEccEdcTst_tvt_RAM_RUNCODE;
    
    crcvalue = PmuEccEdcTst_CalculateCrc32(LOC_START_PmuEccEdcTst_tvt_RAM_RUNCODE,
            (endaddr-beginaddr));
            
    if(crcvalue == PmuEccEdcTst_TvtCrc32)
    {
      Result = PMUECCEDC_SUCCESS;
    }
  }
  else
  {
    Result = PMUECCEDC_NOTEXECUTED;
  }
    
  return Result;
}/*PmuEccEdcTst_lRamCalculateandVerifyCrc32*/


#define IFX_PMUECCEDCTST_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"



