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
**   $FILENAME   : CpuMpuTst.c $                                              **
**                                                                            **
**   $CC VERSION : \main\58 $                                                 **
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
#include "IfxCpu_reg.h"
#include "IfxCpu_bf.h"
#include "Mcal.h"
#include "CpuMpuTst.h"
#include "Mtl_Trap.h"

/*******************************************************************************
**                      Local Macro Definitions                               **
*******************************************************************************/

/* Granularity of the Memory Protection Unit in units of 32bit words:       */
#define MPU_GRANULARITY_32BIT  ( 2U )

/* PROTEN bit of the SYSCON CSFR:                                           */
#define SYSCON_PROT_EN_BIT     ((uint32)IFX_CPU_SYSCON_PROTEN_MSK << IFX_CPU_SYSCON_PROTEN_OFF)

/* Mask for extracting the PSW.PRS:                                         */
#define PSW_PRS_MASK  ((uint32)IFX_CPU_PSW_PRS_MSK << IFX_CPU_PSW_PRS_OFF)

/* Bit-position of the PSW.PRS bitfield:                                    */
#define PSW_PRS_BIT_POS  ((uint32)IFX_CPU_PSW_PRS_OFF )

/* Start and end address of the address space (with respect to the
   granularity of the memory protection system):
*/
#define ADDRESS_SPACE_START         ( 0x00000000U )
#define ADDRESS_SPACE_END           ( 0xFFFFFFF8U )

/* Bit mask for selecting CPR0 in the CPXE_x:                               */
#define CPR0_SELECTION_MASK         ( 0x00000001U )

/* Bit mask for selecting DPR0 in DPRE_x and DPWE_x:                        */
#define DPR0_SELECTION_MASK         ( 0x00000001U )

/* Trap Identification Numbers (TINs) of the traps expected by the CPU MPU
   test:
*/
#define PROT_ERROR_READ_TIN         ( 2U )
#define PROT_ERROR_WRITE_TIN        ( 3U )
#define PROT_ERROR_EXECUTE_TIN      ( 4U )

/* Invalid trap counter value (used to prevent overflow):                   */
#define INVALID_TRAP_COUNTER_VAL    ( 0xFFFFFFFFU )

/* Expected number of traps triggered during a data range test:             */
#define DATA_TST_EXP_TRAPS     ( 4U )

/* Expected number of traps triggered during a code range test:             */
#define CODE_TST_EXP_TRAPS     ( 1U )

/* Size of CpuMpuTst_lTestExecuteAccess function in bytes:                  */
#define EXEC_HELPER_ROUTINE_SIZE    ( 8U )

/* CPXE_x values for enabling execution access to the whole address space
   including the code range under test:
*/
#define CODE_RANGE00_ENABLE_VAL     ( 0x00000007U )
#define CODE_RANGE01_ENABLE_VAL     ( 0x00000007U )
#define CODE_RANGE02_ENABLE_VAL     ( 0x00000007U )
#define CODE_RANGE03_ENABLE_VAL     ( 0x0000000BU )
#define CODE_RANGE04_ENABLE_VAL     ( 0x00000013U )
#define CODE_RANGE05_ENABLE_VAL     ( 0x00000023U )
#define CODE_RANGE06_ENABLE_VAL     ( 0x00000043U )
#define CODE_RANGE07_ENABLE_VAL     ( 0x00000083U )

/* CPXE_x values for enabling execution access to the whole address space
   excluding the code range under test:
*/
#define CODE_RANGE00_DISABLE_VAL    ( 0x00000006U )
#define CODE_RANGE01_DISABLE_VAL    ( 0x00000005U )
#define CODE_RANGE02_DISABLE_VAL    ( 0x00000003U )
#define CODE_RANGE03_DISABLE_VAL    ( 0x00000003U )
#define CODE_RANGE04_DISABLE_VAL    ( 0x00000003U )
#define CODE_RANGE05_DISABLE_VAL    ( 0x00000003U )
#define CODE_RANGE06_DISABLE_VAL    ( 0x00000003U )
#define CODE_RANGE07_DISABLE_VAL    ( 0x00000003U )

/* values for enabling data access to the whole address space
   including the data range under test :
*/
#define DATA_RANGE00_ENABLE_VAL     ( 0x00000007U )
#define DATA_RANGE01_ENABLE_VAL     ( 0x00000007U )
#define DATA_RANGE02_ENABLE_VAL     ( 0x00000007U )
#define DATA_RANGE03_ENABLE_VAL     ( 0x0000000BU )
#define DATA_RANGE04_ENABLE_VAL     ( 0x00000013U )
#define DATA_RANGE05_ENABLE_VAL     ( 0x00000023U )
#define DATA_RANGE06_ENABLE_VAL     ( 0x00000043U )
#define DATA_RANGE07_ENABLE_VAL     ( 0x00000083U )
#define DATA_RANGE08_ENABLE_VAL     ( 0x00000103U )
#define DATA_RANGE09_ENABLE_VAL     ( 0x00000203U )
#define DATA_RANGE10_ENABLE_VAL     ( 0x00000403U )
#define DATA_RANGE11_ENABLE_VAL     ( 0x00000803U )
#define DATA_RANGE12_ENABLE_VAL     ( 0x00001003U )
#define DATA_RANGE13_ENABLE_VAL     ( 0x00002003U )
#define DATA_RANGE14_ENABLE_VAL     ( 0x00004003U )
#define DATA_RANGE15_ENABLE_VAL     ( 0x00008003U )

/* values for enabling dta access to the whole address space
   excluding the data range under test :
*/
#define DATA_RANGE00_DISABLE_VAL    ( 0x00000006U )
#define DATA_RANGE01_DISABLE_VAL    ( 0x00000005U )
#define DATA_RANGE02_DISABLE_VAL    ( 0x00000003U )
#define DATA_RANGE03_DISABLE_VAL    ( 0x00000003U )
#define DATA_RANGE04_DISABLE_VAL    ( 0x00000003U )
#define DATA_RANGE05_DISABLE_VAL    ( 0x00000003U )
#define DATA_RANGE06_DISABLE_VAL    ( 0x00000003U )
#define DATA_RANGE07_DISABLE_VAL    ( 0x00000003U )
#define DATA_RANGE08_DISABLE_VAL    ( 0x00000003U )
#define DATA_RANGE09_DISABLE_VAL    ( 0x00000003U )
#define DATA_RANGE10_DISABLE_VAL    ( 0x00000003U )
#define DATA_RANGE11_DISABLE_VAL    ( 0x00000003U )
#define DATA_RANGE12_DISABLE_VAL    ( 0x00000003U )
#define DATA_RANGE13_DISABLE_VAL    ( 0x00000003U )
#define DATA_RANGE14_DISABLE_VAL    ( 0x00000003U )
#define DATA_RANGE15_DISABLE_VAL    ( 0x00000003U )

/* Macros for Expected traps */
#define PROT_ERROR_NO_TRAP          (0x0U)
#define PROT_ERROR_READ_TRAP        (0x1U)
#define PROT_ERROR_WRITE_TRAP       (0x2U)
#define PROT_ERROR_EXECUTE_TRAP     (0x3U)

/* DPRE, DPWE and CPXE registers of the Data Protection Set selected for
   testing:
*/
#if (CPU_MPU_TST_PROT_REGISTER_SET == 0U)
#define CPU_MPU_TST_DPRE            (CPU_DPRE0)
#define CPU_MPU_TST_DPWE            (CPU_DPWE0)
#define CPU_MPU_TST_CPXE            (CPU_CPXE0)
#elif (CPU_MPU_TST_PROT_REGISTER_SET == 1U)
#define CPU_MPU_TST_DPRE            (CPU_DPRE1)
#define CPU_MPU_TST_DPWE            (CPU_DPWE1)
#define CPU_MPU_TST_CPXE            (CPU_CPXE1)
#elif (CPU_MPU_TST_PROT_REGISTER_SET == 2U)
#define CPU_MPU_TST_DPRE            (CPU_DPRE2)
#define CPU_MPU_TST_DPWE            (CPU_DPWE2)
#define CPU_MPU_TST_CPXE            (CPU_CPXE2)
#else
#define CPU_MPU_TST_DPRE            (CPU_DPRE3)
#define CPU_MPU_TST_DPWE            (CPU_DPWE3)
#define CPU_MPU_TST_CPXE            (CPU_CPXE3)
#endif

/* Fixed test pattern */
#define CPU_MPU_TST_PATTERN         ((uint32)(0x9ABCDEF0U))

/* Class 1 trap for MPU */
#define CPUMPUTST_TRAPCLASS1    ( TRAP_CLASS1 )

/*******************************************************************************
**                      Local Type Definitions                                **
*******************************************************************************/

/* Type definition of Data Protection Ranges:                               */
typedef enum CpuMpuTst_DataRange
{
  MPU_DATA_RANGE00 =  0U,
  MPU_DATA_RANGE01 =  1U,
  MPU_DATA_RANGE02 =  2U,
  MPU_DATA_RANGE03 =  3U,
  MPU_DATA_RANGE04 =  4U,
  MPU_DATA_RANGE05 =  5U,
  MPU_DATA_RANGE06 =  6U,
  MPU_DATA_RANGE07 =  7U,
  MPU_DATA_RANGE08 =  8U,
  MPU_DATA_RANGE09 =  9U,
  MPU_DATA_RANGE10 = 10U,
  MPU_DATA_RANGE11 = 11U,
  MPU_DATA_RANGE12 = 12U,
  MPU_DATA_RANGE13 = 13U,
  MPU_DATA_RANGE14 = 14U,
  MPU_DATA_RANGE15 = 15U
} CpuMpuTst_DataRangeType;

/* Type definition of Code Protection Ranges:                               */
typedef enum CpuMpuTst_CodeRange
{
  MPU_CODE_RANGE00 =  0U,
  MPU_CODE_RANGE01 =  1U,
  MPU_CODE_RANGE02 =  2U,
  MPU_CODE_RANGE03 =  3U,
  MPU_CODE_RANGE04 =  4U,
  MPU_CODE_RANGE05 =  5U,
  MPU_CODE_RANGE06 =  6U,
  MPU_CODE_RANGE07 =  7U
} CpuMpuTst_CodeRangeType;

/* Type definition of structure for counting the number of traps handled
   by the CPU MPU test:
*/
typedef volatile struct CpuMpuTst_TrapData
{
  volatile uint32    TrapCount;
  volatile uint32    ExpectedTrap;
  volatile uint32    Crc;
} CpuMpuTst_TrapDataType;

/* Type definition of backup data structure for CSFR backup:                */
typedef struct CpuMpuTst_BackupData
{
  uint32    Syscon;
  uint32    Compat;
  uint32    Dpre;
  uint32    Dpwe;
  uint32    Cpxe;
#if (CPU_MPU_TST_PROT_REGISTER_SET != 0U)
  uint32    Dpre0;
  uint32    Dpwe0;  
  uint32    Cpxe0;
#endif /* (CPU_MPU_TST_PROT_REGISTER_SET != 0) */
  uint32    Dpr0L;
  uint32    Dpr0U;
  uint32    Dpr1L;
  uint32    Dpr1U;
  uint32    Dpr2L;
  uint32    Dpr2U;
  uint32    Dpr3L;
  uint32    Dpr3U;
  uint32    Dpr4L;
  uint32    Dpr4U;
  uint32    Dpr5L;
  uint32    Dpr5U;
  uint32    Dpr6L;
  uint32    Dpr6U;
  uint32    Dpr7L;
  uint32    Dpr7U;
  uint32    Dpr8L;
  uint32    Dpr8U;
  uint32    Dpr9L;
  uint32    Dpr9U;
  uint32    Dpr10L;
  uint32    Dpr10U;
  uint32    Dpr11L;
  uint32    Dpr11U;
  uint32    Dpr12L;
  uint32    Dpr12U;
  uint32    Dpr13L;
  uint32    Dpr13U;
  uint32    Dpr14L;
  uint32    Dpr14U;
  uint32    Dpr15L;
  uint32    Dpr15U;
  uint32    Cpr0L;
  uint32    Cpr0U;
  uint32    Cpr1L;
  uint32    Cpr1U;
  uint32    Cpr2L;
  uint32    Cpr2U;
  uint32    Cpr3L;
  uint32    Cpr3U;
  uint32    Cpr4L;
  uint32    Cpr4U;
  uint32    Cpr5L;
  uint32    Cpr5U;
  uint32    Cpr6L;
  uint32    Cpr6U;
  uint32    Cpr7L;
  uint32    Cpr7U;
} CpuMpuTst_BackupDataType;

/* Type defintion of test data in RAM:                                      */
typedef struct CpuMpuTst_TestData
{
  volatile uint32 ExcludedMemory[MPU_GRANULARITY_32BIT];
  volatile uint32 IncludedMemory[MPU_GRANULARITY_32BIT];
} CpuMpuTst_TestDataType;

/* Type definition of the scratchpad data for a single code range test:     */
typedef struct CpuMpuTst_CodeRangeCtx
{
  uint32    AccessEnableValue;
  uint32    AccessDisableValue;
} CpuMpuTst_CodeRangeCtxType;

/* Type definition of the scratchpad data for data range test:     */
typedef struct CpuMpuTst_DataRangeCtx
{
  uint32    AccessEnableValue;
  uint32    AccessDisableValue;
} CpuMpuTst_DataRangeCtxType;


/******************************************************************************
**                        Exported obejct definitions                         *
******************************************************************************/

/******************************************************************************
**                        Local object definitions                            *
******************************************************************************/

#define IFX_CPUMPUTST_START_SEC_VAR_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"

/* Trap counters of traps handled by the CPU MPU Test:                      */
static CpuMpuTst_TrapDataType  CpuMpuTst_TrapData[MCAL_NO_OF_CORES];

#define IFX_CPUMPUTST_STOP_SEC_VAR_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"


/* Test memory that is used to check the data memory protection:            */
#define IFX_CPUMPUTST_START_SEC_VAR_8BYTE_ALIGN_ASIL_B
#include "Ifx_MemMap.h"

static CpuMpuTst_TestDataType  CpuMpuTst_lTestData[MCAL_NO_OF_CORES];

#define IFX_CPUMPUTST_STOP_SEC_VAR_8BYTE_ALIGN_ASIL_B
#include "Ifx_MemMap.h"

/******************************************************************************
**                        Imported function declarations                      *
******************************************************************************/

/******************************************************************************
**                        Local function prototypes                           *
******************************************************************************/
#define IFX_CPUMPUTST_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
/* Local function definitions:                                              */
static void CpuMpuTst_lInit(CpuMpuTst_BackupDataType* const BackupData);
static void CpuMpuTst_lRestore(const CpuMpuTst_BackupDataType*
                                 const BackupData);
static Sl_TstRsltType   CpuMpuTst_lTestDataRange
(
  const CpuMpuTst_DataRangeType DataRange,
  const Sl_ParamSetType ParamSetIndex,
  uint32* const TstSignature
);
static Sl_TstRsltType   CpuMpuTst_lTestCodeRange
(
  const CpuMpuTst_CodeRangeType CodeRange,
  uint32* const TstSignature
);
static Sl_TstRsltType   CpuMpuTst_lSetupDataRange
(
  const CpuMpuTst_DataRangeType DataRange,
  CpuMpuTst_DataRangeCtxType* const DpMask
);
static Sl_TstRsltType   CpuMpuTst_lSetupCodeRange
(
  const CpuMpuTst_CodeRangeType CodeRange,
  CpuMpuTst_CodeRangeCtxType* const Context
);

LOCAL_INLINE uint32 CpuMpuTst_lCalcCounterCrc(void);
#define IFX_CPUMPUTST_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
#define IFX_CPUMPUTST_START_SEC_CODE_8BYTE_ALIGN_ASIL_B
#include "Ifx_MemMap.h"
/* Small helper function for testing execution access; this is marked as local
   ("l"), because it is expected to be used solely by the CPU MPU test and
   not exported by any header: */
#if ((defined __TASKING__)  || (defined __GNUC__))
  static void CpuMpuTst_lTestExecuteAccess(void);
#elif defined _DIABDATA_C_TRICORE_  
  #if (_DIABDATA_C_TRICORE_ == 1U)
    static void CpuMpuTst_lTestExecuteAccess(void) __attribute__((noinline));
  #endif /*  _DIABDATA_C_TRICORE_ == 1U 	*/
#endif
#define IFX_CPUMPUTST_STOP_SEC_CODE_8BYTE_ALIGN_ASIL_B
#include "Ifx_MemMap.h"
#define IFX_CPUMPUTST_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
static boolean CpuMpuTst_ProtectionTrapHandler(const uint32 TrapId);
#define IFX_CPUMPUTST_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
/******************************************************************************
**                    Configuration error checking                            *
******************************************************************************/

#ifndef CPU_MPU_TST_PROT_REGISTER_SET
  #error "CPU MPU test configuration error: CPU_MPU_TST_PROT_REGISTER_SET is undefined."
#else
  #if (CPU_MPU_TST_PROT_REGISTER_SET < 0U) || (CPU_MPU_TST_PROT_REGISTER_SET > 3U)
    #error "CPU MPU test configuration error: CPU_MPU_TST_PROT_REGISTER_SET is out of range [0..3]."
  #endif /* (CPU_MPU_TST_PROT_REGISTER_SET < 0) || (CPU_MPU_TST_PROT_REGISTER_SET > 3) */
#endif /* defined(CPU_MPU_TST_PROT_REGISTER_SET) */
#ifndef CPU_MPU_TST_DATA_RANGE_COUNT
  #error "CPU MPU test configuration error: CPU_MPU_TST_DATA_RANGE_COUNT is undefined."
#else
  #if (CPU_MPU_TST_DATA_RANGE_COUNT < 1U) || (CPU_MPU_TST_DATA_RANGE_COUNT > 16U)
    #error "CPU MPU test configuration error: CPU_MPU_TST_DATA_RANGE_COUNT is out of range [1..16]."
  #endif /* (CPU_MPU_TST_DATA_RANGE_COUNT < 1) || (CPU_MPU_TST_DATA_RANGE_COUNT > 16) */
#endif /* defined(CPU_MPU_TST_DATA_RANGE_COUNT) */
#ifndef CPU_MPU_TST_CODE_RANGE_COUNT
  #error "CPU MPU test configuration error: CPU_MPU_TST_CODE_RANGE_COUNT is undefined."
#else
  #if (CPU_MPU_TST_CODE_RANGE_COUNT < 1U) || (CPU_MPU_TST_CODE_RANGE_COUNT > 8U)
    #error "CPU MPU test configuration error: CPU_MPU_TST_CODE_RANGE_COUNT is out of range [1..16]."
  #endif /* (CPU_MPU_TST_CODE_RANGE_COUNT < 1) || (CPU_MPU_TST_CODE_RANGE_COUNT > 16) */
#endif /* defined(CPU_MPU_TST_CODE_RANGE_COUNT) */
#ifndef CPU_MPU_TST_CFG_PARAM_COUNT
  #error "CPU MPU test configuration error: CPU_MPU_TST_CFG_PARAM_COUNT is undefined."
#else
  #if (CPU_MPU_TST_CFG_PARAM_COUNT < 1U)
    #error "CPU MPU test configuration error: CPU_MPU_TST_CFG_PARAM_COUNT is out of range (must be > 0)."
  #endif /* (CPU_MPU_TST_CFG_PARAM_COUNT < 1) */
#endif /* defined(CPU_MPU_TST_CFG_PARAM_COUNT) */


/******************************************************************************
**                    Local inline function definitions                       *
******************************************************************************/

/******************************************************************************
**                         Function definitions                               *
******************************************************************************/

#define IFX_CPUMPUTST_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"


/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : Sl_TstRsltType CpuMpuTst_CpuMpuTst                                **
**          (                                                                 **
**              Sl_ParamSetIndex ParamSetIndex,                               **
**              uint8 TstSeed,                                                **
**              uint32* TstSignature                                          **
**          )                                                                 **
**                                                                            **
** Description : Performs a latent fault metric test of the CPU Memory        **
**               Protection Unit.                                             **
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
** Return value : CPUMPU_SUCCESS - Test succeeded                             **
**                CPUMPU_INVPARAMERR - Test failed because an invalid         **
**                                     parameter was supplied                 **
**                CPUMPU_DATAPROTERR - Test failed due to an error in the     **
**                                       Memory Protection System             **
**                CPUMPU_DATACORRUPTION - Global test data was corrupted      **
**                CPUMPU_CONSISTENCYERR - Test failed due to Register/        **
**                                        Unregister of MPU trap              **
**                CPUMPU_DATARANGExxERR  - Data range xx test failed due to   **
**                                        unexpected / missing trap generation**
**                CPUMPU_CONSISTENCYERR - Code range xx test failed due to    **
**                                        unexpected / missing trap generation**
**                                                                            **
*******************************************************************************/
Sl_TstRsltType CpuMpuTst_CpuMpuTst(const Sl_ParamSetType ParamSetIndex,
                                       const uint8 TstSeed,
                                       uint32* const TstSignature)
{
  Sl_TstRsltType            Result = CPUMPU_NOTEXECUTED;
  uint32                    TestEnMask;
  uint32                    i;
  CpuMpuTst_BackupDataType  BackupData;

  /* Initialize Test Signature:                                             */
  *TstSignature = (uint32)(CRC32((uint32)TEST_ID_CPU_MPU_TST,(uint32)TstSeed));

  /* Parameter check:                                                       */
  if (ParamSetIndex >= CPU_MPU_TST_CFG_PARAM_COUNT)
  {
    Result = CPUMPU_INVPARAMERR;
  }
  else
  {
    /* Test initialization:                                                   */
    CpuMpuTst_lInit(&BackupData);
    
    /* Register for MPU Trap Class */
    if (TRAP_RegisterTrapHandler (CPUMPUTST_TRAPCLASS1,
                    &CpuMpuTst_ProtectionTrapHandler)  == TRAP_E_SUCCESS)
    {                
      /* Check data protection ranges:                                          */
      TestEnMask = (uint32)0x00000001U;
      Result = CPUMPU_SUCCESS;
      i = (uint32)0U;
      do
      {
        if ((CpuMpuTst_ConfigRoot[ParamSetIndex].DataRangeEn & TestEnMask) > 0U)
        {
          Result = CpuMpuTst_lTestDataRange((CpuMpuTst_DataRangeType)i,
                                              ParamSetIndex,
                                              TstSignature);
        }

        TestEnMask <<= 1U;

        i++;
      }while ((i < CPU_MPU_TST_DATA_RANGE_COUNT) && (CPUMPU_SUCCESS == Result));
        
      if(CPUMPU_SUCCESS == Result)
      {
        /* Check code protection ranges: */
        TestEnMask = (uint32)0x00000001U;
      
        i = (uint32)0U;
        do
        {
          if((CpuMpuTst_ConfigRoot[ParamSetIndex].CodeRangeEn & TestEnMask)
              > 0U)
          {
            Result = CpuMpuTst_lTestCodeRange((CpuMpuTst_CodeRangeType)i,
                                                TstSignature);
          }
          i++;
      
          TestEnMask <<= 1U;
      
        }while((i < CPU_MPU_TST_CODE_RANGE_COUNT) && 
               (CPUMPU_SUCCESS == Result));
      }
    
      if (TRAP_UnregisterTrapHandler (CPUMPUTST_TRAPCLASS1) != TRAP_E_SUCCESS)
      {
        Result = CPUMPU_CONSISTENCYERR;
      }
    }
    else
    {
      Result = CPUMPU_CONSISTENCYERR;
    }
    /* Test restoration:                                                   */
    CpuMpuTst_lRestore(&BackupData);
  }
  
  *TstSignature = (uint32)(CRC32(*TstSignature,(uint32)Result));
  
  return Result;
}

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : static boolean CpuMpuTst_ProtectionTrapHandler                    **
**          (                                                                 **
**            const uint32 TrapId                                             **
**          )                                                                 **
**                                                                            **
** Description : Handles Class 1, Internal Protection Traps while the CPU MPU **
**               test has switched the BTV to a dedicated trap table.         **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) : TrapId - Trap Identification Number (TIN) of the trap    **
**                            that is to be handled                           **
**                                                                            **
** Parameters (out):                                                          **
**                                                                            **
** Return value : TRUE, if trap was expected and handled, FALSE otherwise     **
**                                                                            **
*******************************************************************************/
static boolean CpuMpuTst_ProtectionTrapHandler(const uint32 TrapId)
{
  uint32                TrapCounterCrc;
  uint8                 CoreId;
  uint32                Temp;
  boolean               ExpectedTrap = (boolean)FALSE;

  /* Disable Memory Protection while Protection Ranges are being set up:    */
  Temp = (uint32)MFCR(CPU_SYSCON);
  Temp = (uint32)Temp & (~((uint32)SYSCON_PROT_EN_BIT));
  MTCR(CPU_SYSCON, Temp);
  
  /* Read the core Id */
  CoreId = Mcal_GetCoreId();

  TrapCounterCrc = CpuMpuTst_TrapData[CoreId].Crc;
  if (TrapCounterCrc == CpuMpuTst_lCalcCounterCrc())
  {
    switch (TrapId)
    {
      case PROT_ERROR_READ_TIN:
        if (CpuMpuTst_TrapData[CoreId].ExpectedTrap ==
            (uint32)PROT_ERROR_READ_TRAP)
        {
          ExpectedTrap = (boolean)TRUE;
          CpuMpuTst_TrapData[CoreId].ExpectedTrap = (uint32)PROT_ERROR_NO_TRAP;

          /* Clear trap register: */
          MTCR(CPU_DSTR, 0x0U);

          /* Increase trap counter with overflow check: */
          if (INVALID_TRAP_COUNTER_VAL != CpuMpuTst_TrapData[CoreId].TrapCount)
          {
            CpuMpuTst_TrapData[CoreId].TrapCount++;
          }
        }
        break;

      case PROT_ERROR_WRITE_TIN:
        if (CpuMpuTst_TrapData[CoreId].ExpectedTrap ==
            (uint32)PROT_ERROR_WRITE_TRAP)
        {
          ExpectedTrap = (boolean)TRUE;
          CpuMpuTst_TrapData[CoreId].ExpectedTrap = (uint32)PROT_ERROR_NO_TRAP;

          /* Clear trap register: */
          MTCR(CPU_DSTR, 0x0U);

          /* Increase trap counter with overflow check: */
          if (INVALID_TRAP_COUNTER_VAL != CpuMpuTst_TrapData[CoreId].TrapCount)
          {
            CpuMpuTst_TrapData[CoreId].TrapCount++;
          }
        }
        break;

      case PROT_ERROR_EXECUTE_TIN:
        if (CpuMpuTst_TrapData[CoreId].ExpectedTrap ==
            (uint32)PROT_ERROR_EXECUTE_TRAP)
        {
          ExpectedTrap = (boolean)TRUE;
          CpuMpuTst_TrapData[CoreId].ExpectedTrap = (uint32)PROT_ERROR_NO_TRAP;

          /* Increase trap counter with overflow check: */
          if (INVALID_TRAP_COUNTER_VAL != CpuMpuTst_TrapData[CoreId].TrapCount)
          {
            CpuMpuTst_TrapData[CoreId].TrapCount++;
          }
        }
        break;

      default:
        /* Nothing to do */
        break;
    }

    /* Update trap counters CRC value */
    CpuMpuTst_TrapData[CoreId].Crc = CpuMpuTst_lCalcCounterCrc();
  }

  return ExpectedTrap;
}

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : static void CpuMpuTst_lInit                                       **
**                      (                                                     **
**                          CpuMpuTst_BackupDataType* const BackupData        **
**                      )                                                     **
**                                                                            **
** Description : Stores a backup of all CSFRs modified by the test and        **
**               performs basic test initialization.                          **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) :                                                          **
**                                                                            **
** Parameters (out): BackupData - Pointer to CpuMpuTst_BackupDataType struct  **
**                                that will receive the backup values of all  **
**                                CSFRs modified by the test                  **
**                                                                            **
** Return value : None                                                        **
**                                                                            **
*******************************************************************************/
static void CpuMpuTst_lInit(CpuMpuTst_BackupDataType* const BackupData)
{
  Ifx_CPU_COMPAT  compat;
  uint8           CoreId;

  /* Read the core Id */
  CoreId = Mcal_GetCoreId();

  /* Initialize the Expected trap to None */
  CpuMpuTst_TrapData[CoreId].ExpectedTrap = (uint32)PROT_ERROR_NO_TRAP;

  /* Store backup copies of CSRFs modified by the test:                     */
  BackupData->Syscon = (uint32)MFCR(CPU_SYSCON);
  BackupData->Compat = (uint32)MFCR(CPU_COMPAT);

  BackupData->Dpre = (uint32)MFCR(CPU_MPU_TST_DPRE);
  BackupData->Dpwe = (uint32)MFCR(CPU_MPU_TST_DPWE);
  BackupData->Cpxe = (uint32)MFCR(CPU_MPU_TST_CPXE);

  /* CPXE_0 is always used in traps, back it up if it is not already backed
     up via CPU_MPU_TST_CPXE:
  */
#if (CPU_MPU_TST_PROT_REGISTER_SET != 0U)
  BackupData->Dpre0 = (uint32)MFCR(CPU_DPRE0);
  BackupData->Dpwe0 = (uint32)MFCR(CPU_DPWE0);
  BackupData->Cpxe0 = (uint32)MFCR(CPU_CPXE0);
#endif /* (CPU_MPU_TST_PROT_REGISTER_SET != 0) */

  BackupData->Dpr0L = (uint32)MFCR(CPU_DPR0_L);
  BackupData->Dpr0U = (uint32)MFCR(CPU_DPR0_U);
  BackupData->Dpr1L = (uint32)MFCR(CPU_DPR1_L);
  BackupData->Dpr1U = (uint32)MFCR(CPU_DPR1_U);
  BackupData->Dpr2L = (uint32)MFCR(CPU_DPR2_L);
  BackupData->Dpr2U = (uint32)MFCR(CPU_DPR2_U);
  BackupData->Dpr3L = (uint32)MFCR(CPU_DPR3_L);
  BackupData->Dpr3U = (uint32)MFCR(CPU_DPR3_U);
  BackupData->Dpr4L = (uint32)MFCR(CPU_DPR4_L);
  BackupData->Dpr4U = (uint32)MFCR(CPU_DPR4_U);
  BackupData->Dpr5L = (uint32)MFCR(CPU_DPR5_L);
  BackupData->Dpr5U = (uint32)MFCR(CPU_DPR5_U);
  BackupData->Dpr6L = (uint32)MFCR(CPU_DPR6_L);
  BackupData->Dpr6U = (uint32)MFCR(CPU_DPR6_U);
  BackupData->Dpr7L = (uint32)MFCR(CPU_DPR7_L);
  BackupData->Dpr7U = (uint32)MFCR(CPU_DPR7_U);
  BackupData->Dpr8L = (uint32)MFCR(CPU_DPR8_L);
  BackupData->Dpr8U = (uint32)MFCR(CPU_DPR8_U);
  BackupData->Dpr9L = (uint32)MFCR(CPU_DPR9_L);
  BackupData->Dpr9U = (uint32)MFCR(CPU_DPR9_U);
  BackupData->Dpr10L = (uint32)MFCR(CPU_DPR10_L);
  BackupData->Dpr10U = (uint32)MFCR(CPU_DPR10_U);
  BackupData->Dpr11L = (uint32)MFCR(CPU_DPR11_L);
  BackupData->Dpr11U = (uint32)MFCR(CPU_DPR11_U);
  BackupData->Dpr12L = (uint32)MFCR(CPU_DPR12_L);
  BackupData->Dpr12U = (uint32)MFCR(CPU_DPR12_U);
  BackupData->Dpr13L = (uint32)MFCR(CPU_DPR13_L);
  BackupData->Dpr13U = (uint32)MFCR(CPU_DPR13_U);
  BackupData->Dpr14L = (uint32)MFCR(CPU_DPR14_L);
  BackupData->Dpr14U = (uint32)MFCR(CPU_DPR14_U);
  BackupData->Dpr15L = (uint32)MFCR(CPU_DPR15_L);
  BackupData->Dpr15U = (uint32)MFCR(CPU_DPR15_U);

  BackupData->Cpr0L = (uint32)MFCR(CPU_CPR0_L);
  BackupData->Cpr0U = (uint32)MFCR(CPU_CPR0_U);
  BackupData->Cpr1L = (uint32)MFCR(CPU_CPR1_L);
  BackupData->Cpr1U = (uint32)MFCR(CPU_CPR1_U);
  BackupData->Cpr2L = (uint32)MFCR(CPU_CPR2_L);
  BackupData->Cpr2U = (uint32)MFCR(CPU_CPR2_U);
  BackupData->Cpr3L = (uint32)MFCR(CPU_CPR3_L);
  BackupData->Cpr3U = (uint32)MFCR(CPU_CPR3_U);
  BackupData->Cpr4L = (uint32)MFCR(CPU_CPR4_L);
  BackupData->Cpr4U = (uint32)MFCR(CPU_CPR4_U);
  BackupData->Cpr5L = (uint32)MFCR(CPU_CPR5_L);
  BackupData->Cpr5U = (uint32)MFCR(CPU_CPR5_U);
  BackupData->Cpr6L = (uint32)MFCR(CPU_CPR6_L);
  BackupData->Cpr6U = (uint32)MFCR(CPU_CPR6_U);
  BackupData->Cpr7L = (uint32)MFCR(CPU_CPR7_L);
  BackupData->Cpr7U = (uint32)MFCR(CPU_CPR7_U);

  /* Disable SAFETY_ENDINIT protection for SYSCON:                          */
  compat.U = BackupData->Compat;
  compat.B.SP = 1U;
  Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);
  MTCR(CPU_COMPAT, compat.U);
  Mcal_SetSafetyENDINIT_Timed();
}

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : static void CpuMpuTst_lRestore                                    **
**                      (                                                     **
**                          const CpuMpuTst_BackupDataType* const BackupData  **
**                      )                                                     **
**                                                                            **
** Description : Restores the value of all CSFRs that were modified by the    **
**               test to their original content.                              **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) : BackupData - Pointer to a CpuMpuTst_BackupDataType       **
**                                structure that holds the backup values of   **
**                                all CSFRs that were modified by the test    **
**                                                                            **
** Parameters (out):                                                          **
**                                                                            **
** Return value : None                                                        **
**                                                                            **
*******************************************************************************/
static void CpuMpuTst_lRestore(const CpuMpuTst_BackupDataType*
                               const BackupData)
{
  MTCR(CPU_DPR0_L, BackupData->Dpr0L);
  MTCR(CPU_DPR0_U, BackupData->Dpr0U);
  MTCR(CPU_DPR1_L, BackupData->Dpr1L);
  MTCR(CPU_DPR1_U, BackupData->Dpr1U);
  MTCR(CPU_DPR2_L, BackupData->Dpr2L);
  MTCR(CPU_DPR2_U, BackupData->Dpr2U);
  MTCR(CPU_DPR3_L, BackupData->Dpr3L);
  MTCR(CPU_DPR3_U, BackupData->Dpr3U);
  MTCR(CPU_DPR4_L, BackupData->Dpr4L);
  MTCR(CPU_DPR4_U, BackupData->Dpr4U);
  MTCR(CPU_DPR5_L, BackupData->Dpr5L);
  MTCR(CPU_DPR5_U, BackupData->Dpr5U);
  MTCR(CPU_DPR6_L, BackupData->Dpr6L);
  MTCR(CPU_DPR6_U, BackupData->Dpr6U);
  MTCR(CPU_DPR7_L, BackupData->Dpr7L);
  MTCR(CPU_DPR7_U, BackupData->Dpr7U);
  MTCR(CPU_DPR8_L, BackupData->Dpr8L);
  MTCR(CPU_DPR8_U, BackupData->Dpr8U);
  MTCR(CPU_DPR9_L, BackupData->Dpr9L);
  MTCR(CPU_DPR9_U, BackupData->Dpr9U);
  MTCR(CPU_DPR10_L, BackupData->Dpr10L);
  MTCR(CPU_DPR10_U, BackupData->Dpr10U);
  MTCR(CPU_DPR11_L, BackupData->Dpr11L);
  MTCR(CPU_DPR11_U, BackupData->Dpr11U);
  MTCR(CPU_DPR12_L, BackupData->Dpr12L);
  MTCR(CPU_DPR12_U, BackupData->Dpr12U);
  MTCR(CPU_DPR13_L, BackupData->Dpr13L);
  MTCR(CPU_DPR13_U, BackupData->Dpr13U);
  MTCR(CPU_DPR14_L, BackupData->Dpr14L);
  MTCR(CPU_DPR14_U, BackupData->Dpr14U);
  MTCR(CPU_DPR15_L, BackupData->Dpr15L);
  MTCR(CPU_DPR15_U, BackupData->Dpr15U);

  MTCR(CPU_CPR0_L, BackupData->Cpr0L);
  MTCR(CPU_CPR0_U, BackupData->Cpr0U);
  MTCR(CPU_CPR1_L, BackupData->Cpr1L);
  MTCR(CPU_CPR1_U, BackupData->Cpr1U);
  MTCR(CPU_CPR2_L, BackupData->Cpr2L);
  MTCR(CPU_CPR2_U, BackupData->Cpr2U);
  MTCR(CPU_CPR3_L, BackupData->Cpr3L);
  MTCR(CPU_CPR3_U, BackupData->Cpr3U);
  MTCR(CPU_CPR4_L, BackupData->Cpr4L);
  MTCR(CPU_CPR4_U, BackupData->Cpr4U);
  MTCR(CPU_CPR5_L, BackupData->Cpr5L);
  MTCR(CPU_CPR5_U, BackupData->Cpr5U);
  MTCR(CPU_CPR6_L, BackupData->Cpr6L);
  MTCR(CPU_CPR6_U, BackupData->Cpr6U);
  MTCR(CPU_CPR7_L, BackupData->Cpr7L);
  MTCR(CPU_CPR7_U, BackupData->Cpr7U);

  /* CPXE_0 is always used in traps, restore it if it is not already restored
     via CPU_MPU_TST_CPXE:
  */
  
#if (CPU_MPU_TST_PROT_REGISTER_SET != 0U)
  MTCR(CPU_DPRE0, BackupData->Dpre0);
  MTCR(CPU_DPWE0, BackupData->Dpwe0);
  MTCR(CPU_CPXE0, BackupData->Cpxe0);
#endif /* (CPU_MPU_TST_PROT_REGISTER_SET != 0) */

  MTCR(CPU_MPU_TST_DPRE, BackupData->Dpre);
  MTCR(CPU_MPU_TST_DPWE, BackupData->Dpwe);
  MTCR(CPU_MPU_TST_CPXE, BackupData->Cpxe);
  MTCR(CPU_SYSCON, BackupData->Syscon);

  Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);
  MTCR(CPU_COMPAT, BackupData->Compat);
  Mcal_SetSafetyENDINIT_Timed();
}


/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : LOCAL_INLINE uint32 CpuMpuTst_lCalcCounterCrc                    **
**                      (                                                     **
**                         void                                               **
**                      )                                                     **
**                                                                            **
** Description : calculates the CRC32 checksum over the first three data      **
**               members of the global (file-scope) data structure            **
**               CpuMpuTst_TrapData. The result of this function corresponds  **
**               to the expected value of CpuMpuTst_TrapData.Crc              **
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
**                                                                            **
**                                                                            **
** Parameters (out):                                                          **
**                                                                            **
** Return value : CRC                                                        **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE uint32 CpuMpuTst_lCalcCounterCrc(void)
{
  uint32 Crc = 0U;
  uint8           CoreId;

  /* Read the core Id */
  CoreId = Mcal_GetCoreId();
  
  Crc = (uint32)CRC32(Crc, CpuMpuTst_TrapData[CoreId].TrapCount);
  Crc = (uint32)CRC32(Crc,CpuMpuTst_TrapData[CoreId].ExpectedTrap);
  return Crc;

}
/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : static Sl_TstRsltType CpuMpuTst_lTestDataRange                    **
**                                (                                           **
**                                  const CpuMpuTst_DataRangeType DataRange,  **
**                                  uint32* const DataAccumulated,            **
**                                  uint32* const DataExpected,               **
**                                  uint32* const TstSignature                **
**                                )                                           **
**                                                                            **
** Description : Tests a single data protection range.                        **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) : DataRange - Specifies the data range that is to be       **
**                               tested                                       **
**                                                                            **
** Parameters (out): DataAccumulated - Pointer to an uint32 that holds the    **
**                                     accumulated read back data of all data **
**                                     range tests                            **
**                   DataExpected - Pointer to an uint32 that holds the       **
**                                  expected accumulated read back data of    **
**                                  all data range tests                      **
**                   TstSignature - Pointer to an uint32 that holds the       **
**                                  current program flow monitoring CRC value **
**                                  upon function entry and will be updated   **
**                                  to the new program flow CRC value upon    **
**                                  function exit                             **
**                                                                            **
** Return value : CPUMPU_SUCCESS - Data range test succeeded                  **
**                CPUMPU_DATARANGExxERR  - Test failed due to unexpected /    **
**                                 missing trap generation                    **
**                CPUMPU_DATAPROTERR  - Test failed due to read-back data not **
**                                 matches with expected read-back data       **
**                CPUMPU_DATACORRUPTION  - Global test data was corrupted     **
**                                                                            **
*******************************************************************************/
#ifdef __TASKING__
PRAGMA_ALL(OPTIMIZE_0)
#endif
static Sl_TstRsltType CpuMpuTst_lTestDataRange
(
  const CpuMpuTst_DataRangeType DataRange,
  const Sl_ParamSetType ParamSetIndex,
  uint32* const TstSignature
)
{
#ifdef __TASKING__
  register uint32   Temp;
  register uint32   Dummy;
  register uint32   Dummy2;
#endif

#ifdef __GNUC__
  register uint32   Dummy __asm("d8")= 0U;
  register uint32   Temp __asm("d9")= 0U;
  register uint32   Dummy2 __asm("d10")= 0U;
#endif

#ifdef _DIABDATA_C_TRICORE_
#if (_DIABDATA_C_TRICORE_ == 1U)
  register uint32   Temp;
  register uint32   Dummy;
  register uint32   Dummy2;
#endif
#endif

  Sl_TstRsltType    Result;
  CpuMpuTst_DataRangeCtxType  DpMask;
  uint32            CalcCounterCrc;
  uint32            TrapCount;
  uint8             CoreId;
  uint32            DataRead;
  uint32            DataExpected;

  /* Initialize read data and expected value to 0 */
  DataRead = 0U;
  DataExpected = 0U;
  
  UNUSED_PARAMETER(ParamSetIndex)
  
  /* Read the core Id */
  CoreId = Mcal_GetCoreId();
  /* Initialisation of IncludedMemory[0] : write wrong pattern */
  CpuMpuTst_lTestData[CoreId].IncludedMemory[0] = (~CPU_MPU_TST_PATTERN);
  /* Clear trap counters:                                                   */
  CpuMpuTst_TrapData[CoreId].TrapCount= 0U;

  /* Disable Memory Protection while Protection Ranges are being set up:    */
  Temp = (uint32)MFCR(CPU_SYSCON);
  Temp = (uint32)Temp & (~((uint32)SYSCON_PROT_EN_BIT));
  MTCR(CPU_SYSCON, Temp);

  /* Setup data protection range:                                           */
  Result = CpuMpuTst_lSetupDataRange(DataRange, &DpMask);
  
  if (CPUMPU_SUCCESS == Result)
  {
    /* Setup Protection Register Set for testing. NOTE: This must not be
       moved to any sub-routine because the PSW is part of the upper
       context and would be reset to its initial value by the return
       instruction:
      */
    Temp = ((uint32)(MFCR(CPU_PSW)) & (~((uint32)PSW_PRS_MASK)));
    Temp = ((uint32)Temp | ((uint32)CPU_MPU_TST_PROT_REGISTER_SET << PSW_PRS_BIT_POS));
    MTCR(CPU_PSW, Temp);

    /* Disable read and write access for desired memory ranges:             */
    MTCR(CPU_MPU_TST_DPRE, DpMask.AccessDisableValue);
    MTCR(CPU_MPU_TST_DPWE, DpMask.AccessDisableValue);


    /* Enable Execution access for the whole address space:                 */
    MTCR(CPU_CPR0_L, ADDRESS_SPACE_START);
    MTCR(CPU_CPR0_U, ADDRESS_SPACE_END);
    MTCR(CPU_MPU_TST_CPXE, CPR0_SELECTION_MASK);
#if (CPU_MPU_TST_PROT_REGISTER_SET != 0U)
    /* Disable read and write access for desired memory ranges only, 
     * enable all other regions (On Trap, default protection set is 0 */     
    MTCR(CPU_DPRE0, DpMask.AccessDisableValue);
    MTCR(CPU_DPWE0, DpMask.AccessDisableValue);
    MTCR(CPU_CPXE0, CPR0_SELECTION_MASK);
#endif /* (CPU_MPU_TST_PROT_REGISTER_SET != 0) */

    /* Disable interrupts while memory protection system is turned on:      */
    Mcal_SuspendAllInterrupts();

    /* Initialize the expected trap to be write trap */
    CpuMpuTst_TrapData[CoreId].ExpectedTrap = (uint32)PROT_ERROR_WRITE_TRAP;

    /* Update trap counter crc  */
    CpuMpuTst_TrapData[CoreId].Crc = CpuMpuTst_lCalcCounterCrc();
    
    /* Enable Memory Protection System:                                     */
    Temp = (uint32)MFCR(CPU_SYSCON);
    Temp = (uint32)Temp | (uint32)SYSCON_PROT_EN_BIT;
    MTCR(CPU_SYSCON, Temp);

    /* Try to write to protected memory range:
       After execution expected a write trap
    */
    CpuMpuTst_lTestData[CoreId].IncludedMemory[0] = 0U;

    /* Initialize the expected trap to be Read trap */
    CpuMpuTst_TrapData[CoreId].ExpectedTrap = (uint32)PROT_ERROR_READ_TRAP;

    /* Update trap counter crc  */
    CpuMpuTst_TrapData[CoreId].Crc = CpuMpuTst_lCalcCounterCrc();

    /* Re-Enable Memory Protection System (it is expected to have been
       disabled by the trap handler in order to increase its counter):
    */
    Temp = (uint32)Temp | (uint32)SYSCON_PROT_EN_BIT;
    MTCR(CPU_SYSCON, Temp);

    /* Try to read from protected memory range:
       After execution expected a read trap
    */
    Dummy = (uint32)CpuMpuTst_lTestData[CoreId].IncludedMemory[0];

    /* Initialize the expected trap to be write trap */
    CpuMpuTst_TrapData[CoreId].ExpectedTrap = (uint32)PROT_ERROR_WRITE_TRAP;

    /* Update trap counter crc  */
    CpuMpuTst_TrapData[CoreId].Crc = CpuMpuTst_lCalcCounterCrc();

    /* Re-Enable Memory Protection System (it is expected to have been
       disabled by the trap handler in order to increase its counter):
    */
    Temp = (uint32)Temp | (uint32)SYSCON_PROT_EN_BIT;
    MTCR(CPU_SYSCON, Temp);

    /* Try to write to a memory location not covered by any memory
       protection range:
    */
    CpuMpuTst_lTestData[CoreId].ExcludedMemory[0] = 0U;

    /* Initialize the expected trap to be Read trap */
    CpuMpuTst_TrapData[CoreId].ExpectedTrap = (uint32)PROT_ERROR_READ_TRAP;

    /* Update trap counter crc  */
    CpuMpuTst_TrapData[CoreId].Crc = CpuMpuTst_lCalcCounterCrc();
    
    /* Re-Enable Memory Protection System (it is expected to have been
       disabled by the trap handler in order to increase its counter):
    */
    Temp = (uint32)Temp | (uint32)SYSCON_PROT_EN_BIT;
    MTCR(CPU_SYSCON, Temp);

    /* Try to read from a memory location not covered by any memory
       protection range:
    */
    Dummy = (uint32)CpuMpuTst_lTestData[CoreId].ExcludedMemory[0];
  
    /* Initialize the expected trap to be No trap */
    CpuMpuTst_TrapData[CoreId].ExpectedTrap = (uint32)PROT_ERROR_NO_TRAP;
    
    /* Update trap counter crc  */
    CpuMpuTst_TrapData[CoreId].Crc = CpuMpuTst_lCalcCounterCrc();
    
    /* Disable Memory Protection System:                                    */
    Temp = (uint32)( (uint32)Temp & (uint32)(~((uint32)SYSCON_PROT_EN_BIT)) );
    MTCR(CPU_SYSCON, Temp);
    /* Enable Write Access to the protected memory range:                   */
    MTCR(CPU_MPU_TST_DPWE, DpMask.AccessEnableValue);
  
    /* Preload test pattern to a register hosted variable:                  */
    Dummy = CPU_MPU_TST_PATTERN;

    /* Enable Memory Protection System:                                     */
    Temp = (uint32)Temp | (uint32)SYSCON_PROT_EN_BIT;
    MTCR(CPU_SYSCON, Temp);
    
    /* Write test pattern to the protected memory range:                    */
    CpuMpuTst_lTestData[CoreId].IncludedMemory[0] = (uint32)Dummy;

    /* Disable Memory Protection System:                                    */
    Temp = (uint32)((uint32)Temp & (uint32)(~((uint32)SYSCON_PROT_EN_BIT)));
  
   /*  
     Separate code required for GNU because current implementation of mtcr 
     forces memory access even though the Temp variable is decalred as 
   register. This leads an unexpected memory write access trap.
   */
#ifdef __TASKING__
    MTCR(CPU_SYSCON, Temp);
#endif

#ifdef __GNUC__
    __asm("mtcr 0xfe14, %d9");
    __asm("isync");
#endif

#ifdef _DIABDATA_C_TRICORE_
#if (_DIABDATA_C_TRICORE_ == 1U)
    MTCR(CPU_SYSCON, Temp);
#endif
#endif

    /* Enable Read Access to the protected memory range:                    */
    MTCR(CPU_MPU_TST_DPRE, DpMask.AccessEnableValue);
  
    /* Enable Memory Protection System:                                     */
    Temp = (uint32)Temp | (uint32)SYSCON_PROT_EN_BIT;
    MTCR(CPU_SYSCON, Temp);

    /* Read test pattern back from the protected memory range:              */
    Dummy2 = (uint32)CpuMpuTst_lTestData[CoreId].IncludedMemory[0];

    /* Disable Memory Protection System:                                    */
    Temp = (uint32)((uint32)Temp & (uint32)(~((uint32)SYSCON_PROT_EN_BIT)));
  
   /*  
     Separate code required for GNU because current implementation of mtcr 
     forces memory access even though the Temp variable is decalred as 
   register. This leads an unexpected memory write access trap.
   */
#ifdef __TASKING__
    MTCR(CPU_SYSCON, Temp);
#endif

#ifdef __GNUC__
    __asm("mtcr 0xfe14, %d9");
    __asm("isync");
#endif

#ifdef _DIABDATA_C_TRICORE_
#if (_DIABDATA_C_TRICORE_ == 1U)
    MTCR(CPU_SYSCON, Temp);
#endif
#endif

    /* Restore interrupt enable status:                                     */
    Mcal_ResumeAllInterrupts();

    /* Accumulate read back data and expected accumulated value:            */
    DataRead = (uint32)Dummy2;
    *TstSignature = (uint32)CRC32(*TstSignature, (uint32)Dummy2);
    DataExpected = CPU_MPU_TST_PATTERN;

    /* Update TstSignature with number of trap counter crc */
    *TstSignature = (uint32)CRC32(*TstSignature, CpuMpuTst_TrapData[CoreId].Crc);

    /* Check if the expected number of traps has been triggered:            */
    TrapCount= CpuMpuTst_TrapData[CoreId].TrapCount;

    /* Check if actual read-back data matches expected read-back data: */
    if (DataRead != DataExpected)
    {
      Result = CPUMPU_DATAPROTERR;
    }
    else if ((uint32)DATA_TST_EXP_TRAPS != TrapCount)
    {
      Result = (Sl_TstRsltType)(CPUMPU_DATARANGE_ERR(DataRange));
    }
    else
    {
      CalcCounterCrc = CpuMpuTst_lCalcCounterCrc();
      if(CpuMpuTst_TrapData[CoreId].Crc == CalcCounterCrc)
      {
        Result = CPUMPU_SUCCESS;
      }
      else
      {
        Result = CPUMPU_DATACORRUPTION;
      }
    }
  }

  return Result;
}
#ifdef __TASKING__
PRAGMA_ALL(OPTIMIZE_RESTORE)
#endif

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : static Sl_TstRsltType CpuMpuTst_lTestCodeRange                    **
**                                (                                           **
**                                  const CpuMpuTst_CodeRangeType CodeRange,  **
**                                  uint32* const TstSignature                **
**                                )                                           **
**                                                                            **
** Description : Tests a single code protection range.                        **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) : CodeRange - Specifies the code range that is to be       **
**                               tested                                       **
**                                                                            **
** Parameters (out): TstSignature - Pointer to an uint32 that holds the       **
**                                  current program flow monitoring CRC value **
**                                  upon function entry and will be updated   **
**                                  to the new program flow CRC value upon    **
**                                  function exit                             **
**                                                                            **
** Return value : CPUMPU_SUCCESS - Code range test succeeded                  **
**                CPUMPU_CODERANGExxERR  - Test failed due to unexpected /    **
**                                 missing trap generation                    **
**                CPUMPU_DATACORRUPTION - Global test data was corrupted      **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType CpuMpuTst_lTestCodeRange
(
  const CpuMpuTst_CodeRangeType CodeRange,
  uint32* const TstSignature
)
{
  Sl_TstRsltType                Result;
  CpuMpuTst_CodeRangeCtxType    CodeRangeContext;
  register uint32               Temp;
  uint32                        CalcCounterCrc;
  uint32                        TrapCount;
  uint8                         CoreId;

  /* Read the core Id */
  CoreId = Mcal_GetCoreId();

  /* Clear trap counters:                                                   */
  CpuMpuTst_TrapData[CoreId].TrapCount= 0U;

  /* Disable Memory Protection while Protection Ranges are being set up:    */
  Temp = (uint32)MFCR(CPU_SYSCON);
  Temp &= (~((uint32)SYSCON_PROT_EN_BIT));
  MTCR(CPU_SYSCON, Temp);


  /* Setup data protection range:                                           */
  Result = CpuMpuTst_lSetupCodeRange(CodeRange, &CodeRangeContext);

  if(CPUMPU_SUCCESS == Result)
  {
    /* Setup Protection Register Set for testing. NOTE: This must not be
       moved to any sub-routine because the PSW is part of the upper
       context and would be reset to its initial value by the return
       instruction:
    */
    Temp = ((uint32)(MFCR(CPU_PSW)) & (~((uint32)PSW_PRS_MASK)));
    Temp = (Temp | ((uint32)CPU_MPU_TST_PROT_REGISTER_SET << PSW_PRS_BIT_POS));
    MTCR(CPU_PSW, Temp);

    /* Enable read and write access to the whole address space:             */
    MTCR(CPU_DPR0_L, ADDRESS_SPACE_START);
    MTCR(CPU_DPR0_U, ADDRESS_SPACE_END);
    MTCR(CPU_MPU_TST_DPRE, DPR0_SELECTION_MASK);
    MTCR(CPU_MPU_TST_DPWE, DPR0_SELECTION_MASK);

    /* Enable Execution access for the whole address space except
       CpuMpuTst_lTestExecute:
    */
    MTCR(CPU_MPU_TST_CPXE, CodeRangeContext.AccessDisableValue);
#if (CPU_MPU_TST_PROT_REGISTER_SET != 0U)
    MTCR(CPU_CPXE0, CodeRangeContext.AccessDisableValue);
#endif /* (CPU_MPU_TST_PROT_REGISTER_SET != 0) */

    /* Disable interrupts while memory protection system is turned on:      */
    Mcal_SuspendAllInterrupts();

    /* Initialize the expected trap to be No trap */
    CpuMpuTst_TrapData[CoreId].ExpectedTrap = (uint32)PROT_ERROR_EXECUTE_TRAP;

    /* Update trap counter crc  */
    CpuMpuTst_TrapData[CoreId].Crc = CpuMpuTst_lCalcCounterCrc();
    
    /* Enable Memory Protection System:                                     */
    Temp = (uint32)MFCR(CPU_SYSCON);
    Temp |= (uint32)SYSCON_PROT_EN_BIT;
    MTCR(CPU_SYSCON, Temp);

    /* Try to execute code in a protected memory range:                     */
    CpuMpuTst_lTestExecuteAccess();
    
    /* Initialize the expected trap to be No trap */
    CpuMpuTst_TrapData[CoreId].ExpectedTrap = (uint32)PROT_ERROR_NO_TRAP;

    /* Update trap counter crc  */
    CpuMpuTst_TrapData[CoreId].Crc = CpuMpuTst_lCalcCounterCrc();

    /* Enable Execution Access to the memory protection range under
       test:
    */
    MTCR(CPU_MPU_TST_CPXE, CodeRangeContext.AccessEnableValue);
#if (CPU_MPU_TST_PROT_REGISTER_SET != 0U)
    MTCR(CPU_CPXE0, CodeRangeContext.AccessEnableValue);
#endif /* (CPU_MPU_TST_PROT_REGISTER_SET != 0) */

    /* Re-Enable Memory Protection System (it is expected to have been
       disabled by the trap handler in order to increase its counter):
    */
    Temp |= SYSCON_PROT_EN_BIT;
    MTCR(CPU_SYSCON, Temp);

    /* Try again to execute code in protected memory range (now, no more
       trap should be thrown):
    */
    CpuMpuTst_lTestExecuteAccess();

    /* Disable Memory Protection System:                                    */
    Temp &= ~SYSCON_PROT_EN_BIT;
    MTCR(CPU_SYSCON, Temp);

    /* Restore interrupt enable status:                                     */
    Mcal_ResumeAllInterrupts();

    *TstSignature = (uint32)CRC32(*TstSignature, CpuMpuTst_TrapData[CoreId].Crc);
    /* Check if the expected number of traps has been triggered:            */

    TrapCount= CpuMpuTst_TrapData[CoreId].TrapCount;

    if (CODE_TST_EXP_TRAPS == TrapCount)
    {
      CalcCounterCrc = CpuMpuTst_lCalcCounterCrc();
      if(CpuMpuTst_TrapData[CoreId].Crc == CalcCounterCrc)
      {
        Result = CPUMPU_SUCCESS;
      }
      else
      {
        Result = CPUMPU_DATACORRUPTION;
      }
    }
    else
    {
      Result = CPUMPU_CODERANGE_ERR(CodeRange);
    }
  }

  return Result;
}

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : static Sl_TstRsltType CpuMpuTst_lSetupDataRange                   **
**                                (                                           **
**                                  const CpuMpuTst_DataRangeType DataRange,  **
**                                  uint32* const DpEnableMask                **
**                                )                                           **
**                                                                            **
** Description : Sets up DPRx_L and DPRx_U CSFRs to protect the test memory   **
**               CpuMpuTst_lTestData.IncludedMemory and delivers a bitmask    **
**               for enabling access to that range in the DPRE_x and DPWE_x   **
**               CSFRs as a side product.                                     **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) : DataRange - Specifies the data range that is to be       **
**                               setup                                        **
**                                                                            **
** Parameters (out): DpEnableMask - Returns a bitmask that could be written   **
**                                  to DPRE_x or DPWE_x in order to enable    **
**                                  access to the given memory                **
**                                                                            **
** Return value : CPUMPU_SUCCESS - Requested data protection range was setup  **
**                            successfully                                    **
**                CPUMPU_INVPARAMERR - An invalid parameter was supplied      **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType CpuMpuTst_lSetupDataRange
(
  const CpuMpuTst_DataRangeType DataRange,
  CpuMpuTst_DataRangeCtxType* const DpMask
)
{
  Sl_TstRsltType    Result = CPUMPU_NOTEXECUTED;
  uint8             CoreId;
  uint32            LowerAddress;
  uint32            UpperAddress;

  /* Read the core Id */
  CoreId = Mcal_GetCoreId();

  LowerAddress = (uint32)&CpuMpuTst_lTestData[CoreId].IncludedMemory;
  UpperAddress = LowerAddress + (MPU_GRANULARITY_32BIT * sizeof(uint32));

  switch (DataRange)
  {
  case MPU_DATA_RANGE00:
    MTCR(CPU_DPR0_L, LowerAddress);
    MTCR(CPU_DPR0_U, UpperAddress);
    
    MTCR(CPU_DPR1_L, ADDRESS_SPACE_START);
    MTCR(CPU_DPR1_U, (uint32)&CpuMpuTst_lTestData[CoreId].ExcludedMemory);
    MTCR(CPU_DPR2_L, UpperAddress);
    MTCR(CPU_DPR2_U, ADDRESS_SPACE_END);
    DpMask->AccessDisableValue = DATA_RANGE00_DISABLE_VAL;
    DpMask->AccessEnableValue= DATA_RANGE00_ENABLE_VAL;
    break;
  case MPU_DATA_RANGE01:
    MTCR(CPU_DPR1_L, LowerAddress);
    MTCR(CPU_DPR1_U, UpperAddress);
    
    MTCR(CPU_DPR0_L, ADDRESS_SPACE_START);
    MTCR(CPU_DPR0_U, (uint32)&CpuMpuTst_lTestData[CoreId].ExcludedMemory);
    MTCR(CPU_DPR2_L, UpperAddress);
    MTCR(CPU_DPR2_U, ADDRESS_SPACE_END);
    DpMask->AccessDisableValue = DATA_RANGE01_DISABLE_VAL;
    DpMask->AccessEnableValue= DATA_RANGE01_ENABLE_VAL;
    break;
  case MPU_DATA_RANGE02:
    MTCR(CPU_DPR2_L, LowerAddress);
    MTCR(CPU_DPR2_U, UpperAddress);

    MTCR(CPU_DPR0_L, ADDRESS_SPACE_START);
    MTCR(CPU_DPR0_U, (uint32)&CpuMpuTst_lTestData[CoreId].ExcludedMemory);
    MTCR(CPU_DPR1_L, UpperAddress);
    MTCR(CPU_DPR1_U, ADDRESS_SPACE_END);
    DpMask->AccessDisableValue = DATA_RANGE02_DISABLE_VAL;
    DpMask->AccessEnableValue= DATA_RANGE02_ENABLE_VAL;
    break;
  case MPU_DATA_RANGE03:
    MTCR(CPU_DPR3_L, LowerAddress);
    MTCR(CPU_DPR3_U, UpperAddress);

    MTCR(CPU_DPR0_L, ADDRESS_SPACE_START);
    MTCR(CPU_DPR0_U, (uint32)&CpuMpuTst_lTestData[CoreId].ExcludedMemory);
    MTCR(CPU_DPR1_L, UpperAddress);
    MTCR(CPU_DPR1_U, ADDRESS_SPACE_END);
    DpMask->AccessDisableValue = DATA_RANGE03_DISABLE_VAL;
    DpMask->AccessEnableValue= DATA_RANGE03_ENABLE_VAL;
    break;
  case MPU_DATA_RANGE04:
    MTCR(CPU_DPR4_L, LowerAddress);
    MTCR(CPU_DPR4_U, UpperAddress);

    MTCR(CPU_DPR0_L, ADDRESS_SPACE_START);
    MTCR(CPU_DPR0_U, (uint32)&CpuMpuTst_lTestData[CoreId].ExcludedMemory);
    MTCR(CPU_DPR1_L, UpperAddress);
    MTCR(CPU_DPR1_U, ADDRESS_SPACE_END);
    DpMask->AccessDisableValue = DATA_RANGE04_DISABLE_VAL;
    DpMask->AccessEnableValue= DATA_RANGE04_ENABLE_VAL;
    break;
  case MPU_DATA_RANGE05:
    MTCR(CPU_DPR5_L, LowerAddress);
    MTCR(CPU_DPR5_U, UpperAddress);

    MTCR(CPU_DPR0_L, ADDRESS_SPACE_START);
    MTCR(CPU_DPR0_U, (uint32)&CpuMpuTst_lTestData[CoreId].ExcludedMemory);
    MTCR(CPU_DPR1_L, UpperAddress);
    MTCR(CPU_DPR1_U, ADDRESS_SPACE_END);
    DpMask->AccessDisableValue = DATA_RANGE05_DISABLE_VAL;
    DpMask->AccessEnableValue= DATA_RANGE05_ENABLE_VAL;
    break;
  case MPU_DATA_RANGE06:
    MTCR(CPU_DPR6_L, LowerAddress);
    MTCR(CPU_DPR6_U, UpperAddress);

    MTCR(CPU_DPR0_L, ADDRESS_SPACE_START);
    MTCR(CPU_DPR0_U, (uint32)&CpuMpuTst_lTestData[CoreId].ExcludedMemory);
    MTCR(CPU_DPR1_L, UpperAddress);
    MTCR(CPU_DPR1_U, ADDRESS_SPACE_END);
    DpMask->AccessDisableValue = DATA_RANGE06_DISABLE_VAL;
    DpMask->AccessEnableValue= DATA_RANGE06_ENABLE_VAL;
    break;
  case MPU_DATA_RANGE07:
    MTCR(CPU_DPR7_L, LowerAddress);
    MTCR(CPU_DPR7_U, UpperAddress);

    MTCR(CPU_DPR0_L, ADDRESS_SPACE_START);
    MTCR(CPU_DPR0_U, (uint32)&CpuMpuTst_lTestData[CoreId].ExcludedMemory);
    MTCR(CPU_DPR1_L, UpperAddress);
    MTCR(CPU_DPR1_U, ADDRESS_SPACE_END);
    DpMask->AccessDisableValue = DATA_RANGE07_DISABLE_VAL;
    DpMask->AccessEnableValue= DATA_RANGE07_ENABLE_VAL;
    break;
  case MPU_DATA_RANGE08:
    MTCR(CPU_DPR8_L, LowerAddress);
    MTCR(CPU_DPR8_U, UpperAddress);

    MTCR(CPU_DPR0_L, ADDRESS_SPACE_START);
    MTCR(CPU_DPR0_U, (uint32)&CpuMpuTst_lTestData[CoreId].ExcludedMemory);
    MTCR(CPU_DPR1_L, UpperAddress);
    MTCR(CPU_DPR1_U, ADDRESS_SPACE_END);
    DpMask->AccessDisableValue = DATA_RANGE08_DISABLE_VAL;
    DpMask->AccessEnableValue= DATA_RANGE08_ENABLE_VAL;
    break;
  case MPU_DATA_RANGE09:
    MTCR(CPU_DPR9_L, LowerAddress);
    MTCR(CPU_DPR9_U, UpperAddress);

    MTCR(CPU_DPR0_L, ADDRESS_SPACE_START);
    MTCR(CPU_DPR0_U, (uint32)&CpuMpuTst_lTestData[CoreId].ExcludedMemory);
    MTCR(CPU_DPR1_L, UpperAddress);
    MTCR(CPU_DPR1_U, ADDRESS_SPACE_END);
    DpMask->AccessDisableValue = DATA_RANGE09_DISABLE_VAL;
    DpMask->AccessEnableValue= DATA_RANGE09_ENABLE_VAL;
    break;
  case MPU_DATA_RANGE10:
    MTCR(CPU_DPR10_L, LowerAddress);
    MTCR(CPU_DPR10_U, UpperAddress);

    MTCR(CPU_DPR0_L, ADDRESS_SPACE_START);
    MTCR(CPU_DPR0_U, (uint32)&CpuMpuTst_lTestData[CoreId].ExcludedMemory);
    MTCR(CPU_DPR1_L, UpperAddress);
    MTCR(CPU_DPR1_U, ADDRESS_SPACE_END);
    DpMask->AccessDisableValue = DATA_RANGE10_DISABLE_VAL;
    DpMask->AccessEnableValue= DATA_RANGE10_ENABLE_VAL;
    break;
  case MPU_DATA_RANGE11:
    MTCR(CPU_DPR11_L, LowerAddress);
    MTCR(CPU_DPR11_U, UpperAddress);

     MTCR(CPU_DPR0_L, ADDRESS_SPACE_START);
    MTCR(CPU_DPR0_U, (uint32)&CpuMpuTst_lTestData[CoreId].ExcludedMemory);
    MTCR(CPU_DPR1_L, UpperAddress);
    MTCR(CPU_DPR1_U, ADDRESS_SPACE_END);
    DpMask->AccessDisableValue = DATA_RANGE11_DISABLE_VAL;
    DpMask->AccessEnableValue= DATA_RANGE11_ENABLE_VAL;
    break;
  case MPU_DATA_RANGE12:
    MTCR(CPU_DPR12_L, LowerAddress);
    MTCR(CPU_DPR12_U, UpperAddress);

    MTCR(CPU_DPR0_L, ADDRESS_SPACE_START);
    MTCR(CPU_DPR0_U, (uint32)&CpuMpuTst_lTestData[CoreId].ExcludedMemory);
    MTCR(CPU_DPR1_L, UpperAddress);
    MTCR(CPU_DPR1_U, ADDRESS_SPACE_END);
    DpMask->AccessDisableValue = DATA_RANGE12_DISABLE_VAL;
    DpMask->AccessEnableValue= DATA_RANGE12_ENABLE_VAL;
    break;
  case MPU_DATA_RANGE13:
    MTCR(CPU_DPR13_L, LowerAddress);
    MTCR(CPU_DPR13_U, UpperAddress);

    MTCR(CPU_DPR0_L, ADDRESS_SPACE_START);
    MTCR(CPU_DPR0_U, (uint32)&CpuMpuTst_lTestData[CoreId].ExcludedMemory);
    MTCR(CPU_DPR1_L, UpperAddress);
    MTCR(CPU_DPR1_U, ADDRESS_SPACE_END);
    DpMask->AccessDisableValue = DATA_RANGE13_DISABLE_VAL;
    DpMask->AccessEnableValue= DATA_RANGE13_ENABLE_VAL;
    break;
  case MPU_DATA_RANGE14:
    MTCR(CPU_DPR14_L, LowerAddress);
    MTCR(CPU_DPR14_U, UpperAddress);

    MTCR(CPU_DPR0_L, ADDRESS_SPACE_START);
    MTCR(CPU_DPR0_U, (uint32)&CpuMpuTst_lTestData[CoreId].ExcludedMemory);
    MTCR(CPU_DPR1_L, UpperAddress);
    MTCR(CPU_DPR1_U, ADDRESS_SPACE_END);
    DpMask->AccessDisableValue = DATA_RANGE14_DISABLE_VAL;
    DpMask->AccessEnableValue= DATA_RANGE14_ENABLE_VAL;
    break;
  case MPU_DATA_RANGE15:
    MTCR(CPU_DPR15_L, LowerAddress);
    MTCR(CPU_DPR15_U, UpperAddress);

    MTCR(CPU_DPR0_L, ADDRESS_SPACE_START);
    MTCR(CPU_DPR0_U, (uint32)&CpuMpuTst_lTestData[CoreId].ExcludedMemory);
    MTCR(CPU_DPR1_L, UpperAddress);
    MTCR(CPU_DPR1_U, ADDRESS_SPACE_END);
    DpMask->AccessDisableValue = DATA_RANGE15_DISABLE_VAL;
    DpMask->AccessEnableValue= DATA_RANGE15_ENABLE_VAL;
    break;
  default:
    Result = CPUMPU_INVPARAMERR;
    break;
  }

  if(CPUMPU_NOTEXECUTED == Result)
  {
    Result = CPUMPU_SUCCESS;
  }
  return Result;
}

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : static Sl_TstRsltType CpuMpuTst_lSetupCodeRange                   **
**                                (                                           **
**                                  const CpuMpuTst_DataRangeType DataRange,  **
**                                  CpuMpuTst_CodeRangeCtxType* const Context **
**                                )                                           **
**                                                                            **
** Description : Sets up CPRx_L and CPRx_U CSFRs to protect the test memory   **
**               to which CpuMpuTst_lTestExecuteAccess is located and         **
**               delivers two bitmasks for enabling or disabling access to    **
**               the code range under test in the DPRE_x and DPWE_x CSFRs as  **
**               a side product.                                              **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) : CodeRange - Specifies the code range that is to be       **
**                               setup                                        **
**                                                                            **
** Parameters (out): Context - Returns two bitmasks that could be written to  **
**                             CPRE_x or CPWE_x in order to enable or disable **
**                             access to the code range under test            **
**                                                                            **
** Return value : CPUMPU_SUCCESS - Requested code protection range was setup  **
**                            successfully                                    **
**                CPUMPU_INVPARAMERR - An invalid parameter was supplied      **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType CpuMpuTst_lSetupCodeRange
(
  const CpuMpuTst_CodeRangeType CodeRange,
 CpuMpuTst_CodeRangeCtxType* const Context
)
{
  Sl_TstRsltType    Result = CPUMPU_NOTEXECUTED;

  switch (CodeRange)
  {
  case MPU_CODE_RANGE00:
    MTCR(CPU_CPR0_L, (uint32)&CpuMpuTst_lTestExecuteAccess);
    MTCR(CPU_CPR0_U, (uint32)&CpuMpuTst_lTestExecuteAccess + 
          EXEC_HELPER_ROUTINE_SIZE);
    MTCR(CPU_CPR1_L, ADDRESS_SPACE_START);
    MTCR(CPU_CPR1_U, (uint32)&CpuMpuTst_lTestExecuteAccess);
    MTCR(CPU_CPR2_L, (uint32)&CpuMpuTst_lTestExecuteAccess + 
          EXEC_HELPER_ROUTINE_SIZE);
    MTCR(CPU_CPR2_U, ADDRESS_SPACE_END);
    Context->AccessEnableValue = CODE_RANGE00_ENABLE_VAL;
    Context->AccessDisableValue = CODE_RANGE00_DISABLE_VAL;
    break;
  case MPU_CODE_RANGE01:
    MTCR(CPU_CPR1_L, (uint32)&CpuMpuTst_lTestExecuteAccess);
    MTCR(CPU_CPR1_U, (uint32)&CpuMpuTst_lTestExecuteAccess + 
          EXEC_HELPER_ROUTINE_SIZE);
    MTCR(CPU_CPR0_L, ADDRESS_SPACE_START);
    MTCR(CPU_CPR0_U, (uint32)&CpuMpuTst_lTestExecuteAccess);
    MTCR(CPU_CPR2_L, (uint32)&CpuMpuTst_lTestExecuteAccess + 
          EXEC_HELPER_ROUTINE_SIZE);
    MTCR(CPU_CPR2_U, ADDRESS_SPACE_END);
    Context->AccessEnableValue = CODE_RANGE01_ENABLE_VAL;
    Context->AccessDisableValue = CODE_RANGE01_DISABLE_VAL;
    break;
  case MPU_CODE_RANGE02:
    MTCR(CPU_CPR2_L, (uint32)&CpuMpuTst_lTestExecuteAccess);
    MTCR(CPU_CPR2_U, (uint32)&CpuMpuTst_lTestExecuteAccess + 
          EXEC_HELPER_ROUTINE_SIZE);
    MTCR(CPU_CPR0_L, ADDRESS_SPACE_START);
    MTCR(CPU_CPR0_U, (uint32)&CpuMpuTst_lTestExecuteAccess);
    MTCR(CPU_CPR1_L, (uint32)&CpuMpuTst_lTestExecuteAccess + 
          EXEC_HELPER_ROUTINE_SIZE);
    MTCR(CPU_CPR1_U, ADDRESS_SPACE_END);
    Context->AccessEnableValue = CODE_RANGE02_ENABLE_VAL;
    Context->AccessDisableValue = CODE_RANGE02_DISABLE_VAL;
    break;
  case MPU_CODE_RANGE03:
    MTCR(CPU_CPR3_L, (uint32)&CpuMpuTst_lTestExecuteAccess);
    MTCR(CPU_CPR3_U, (uint32)&CpuMpuTst_lTestExecuteAccess + 
          EXEC_HELPER_ROUTINE_SIZE);
    MTCR(CPU_CPR0_L, ADDRESS_SPACE_START);
    MTCR(CPU_CPR0_U, (uint32)&CpuMpuTst_lTestExecuteAccess);
    MTCR(CPU_CPR1_L, (uint32)&CpuMpuTst_lTestExecuteAccess + 
          EXEC_HELPER_ROUTINE_SIZE);
    MTCR(CPU_CPR1_U, ADDRESS_SPACE_END);
    Context->AccessEnableValue = CODE_RANGE03_ENABLE_VAL;
    Context->AccessDisableValue = CODE_RANGE03_DISABLE_VAL;
    break;
  case MPU_CODE_RANGE04:
    MTCR(CPU_CPR4_L, (uint32)&CpuMpuTst_lTestExecuteAccess);
    MTCR(CPU_CPR4_U, (uint32)&CpuMpuTst_lTestExecuteAccess + 
          EXEC_HELPER_ROUTINE_SIZE);
    MTCR(CPU_CPR0_L, ADDRESS_SPACE_START);
    MTCR(CPU_CPR0_U, (uint32)&CpuMpuTst_lTestExecuteAccess);
    MTCR(CPU_CPR1_L, (uint32)&CpuMpuTst_lTestExecuteAccess + 
          EXEC_HELPER_ROUTINE_SIZE);
    MTCR(CPU_CPR1_U, ADDRESS_SPACE_END);
    Context->AccessEnableValue = CODE_RANGE04_ENABLE_VAL;
    Context->AccessDisableValue = CODE_RANGE04_DISABLE_VAL;
    break;
  case MPU_CODE_RANGE05:
    MTCR(CPU_CPR5_L, (uint32)&CpuMpuTst_lTestExecuteAccess);
    MTCR(CPU_CPR5_U, (uint32)&CpuMpuTst_lTestExecuteAccess + 
          EXEC_HELPER_ROUTINE_SIZE);
    MTCR(CPU_CPR0_L, ADDRESS_SPACE_START);
    MTCR(CPU_CPR0_U, (uint32)&CpuMpuTst_lTestExecuteAccess);
    MTCR(CPU_CPR1_L, (uint32)&CpuMpuTst_lTestExecuteAccess + 
          EXEC_HELPER_ROUTINE_SIZE);
    MTCR(CPU_CPR1_U, ADDRESS_SPACE_END);
    Context->AccessEnableValue = CODE_RANGE05_ENABLE_VAL;
    Context->AccessDisableValue = CODE_RANGE05_DISABLE_VAL;
    break;
  case MPU_CODE_RANGE06:
    MTCR(CPU_CPR6_L, (uint32)&CpuMpuTst_lTestExecuteAccess);
    MTCR(CPU_CPR6_U, (uint32)&CpuMpuTst_lTestExecuteAccess + 
          EXEC_HELPER_ROUTINE_SIZE);
    MTCR(CPU_CPR0_L, ADDRESS_SPACE_START);
    MTCR(CPU_CPR0_U, (uint32)&CpuMpuTst_lTestExecuteAccess);
    MTCR(CPU_CPR1_L, (uint32)&CpuMpuTst_lTestExecuteAccess + 
          EXEC_HELPER_ROUTINE_SIZE);
    MTCR(CPU_CPR1_U, ADDRESS_SPACE_END);
    Context->AccessEnableValue = CODE_RANGE06_ENABLE_VAL;
    Context->AccessDisableValue = CODE_RANGE06_DISABLE_VAL;
    break;
  case MPU_CODE_RANGE07:
    MTCR(CPU_CPR7_L, (uint32)&CpuMpuTst_lTestExecuteAccess);
    MTCR(CPU_CPR7_U, (uint32)&CpuMpuTst_lTestExecuteAccess + 
          EXEC_HELPER_ROUTINE_SIZE);
    MTCR(CPU_CPR0_L, ADDRESS_SPACE_START);
    MTCR(CPU_CPR0_U, (uint32)&CpuMpuTst_lTestExecuteAccess);
    MTCR(CPU_CPR1_L, (uint32)&CpuMpuTst_lTestExecuteAccess + 
          EXEC_HELPER_ROUTINE_SIZE);
    MTCR(CPU_CPR1_U, ADDRESS_SPACE_END);
    Context->AccessEnableValue = CODE_RANGE07_ENABLE_VAL;
    Context->AccessDisableValue = CODE_RANGE07_DISABLE_VAL;
    break;
  default:
    Result = CPUMPU_INVPARAMERR;
    break;
  }

  if(CPUMPU_NOTEXECUTED == Result)
  {
    Result = CPUMPU_SUCCESS;
  }
  return Result;
}

#define IFX_CPUMPUTST_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"

#define IFX_CPUMPUTST_START_SEC_CODE_8BYTE_ALIGN_ASIL_B
#include "Ifx_MemMap.h"

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : void CpuMpuTst_lTestExecuteAccess(void)                           **
**                                                                            **
** Description : CpuMpuTst_lTestExecuteAccess is a small dummy function that  **
**               is called by the Code Protection test routine in order to    **
**               test the code protection. It does do nothing but executing   **
**               a certain number of nop’s and returning.                   **
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
** Parameters (out): None   												  **
**                                                                            **
** Return value : None                                                        **
**                                                                            **
*******************************************************************************/
void CpuMpuTst_lTestExecuteAccess(void)
{
  __asm("nop");
  __asm("nop");
  __asm("nop");
  return ;
}

#define IFX_CPUMPUTST_STOP_SEC_CODE_8BYTE_ALIGN_ASIL_B
#include "Ifx_MemMap.h"


