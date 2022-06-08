/*******************************************************************************
** Copyright (C) Infineon Technologies (2014)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**   $FILENAME   : SramEccTst.c $                                             **
**                                                                            **
**   $CC VERSION : \main\94 $                                                 **
**                                                                            **
**   $DATE       : 2018-02-22 $                                               **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon AURIX                                                **
**                                                                            **
**  COMPILER  : Tasking                                                       **
**                                                                            **
**  AUTHOR    : SafeTlib Team                                                 **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  TRACEABILITY:                                                             **
**                                                                            **
**  DESCRIPTION  : This file contains                                         **
**                 - functionality of the SRAM ECC test                       **
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

#include "ChipId.h"
#include "Mcal.h"
#include "SramEccTst.h"
#include "SramEccTst_MemDef.h"
#include "SmuInt.h"
#include "Sl_Ipc.h"
#include "IfxCpu_bf.h"
#include "IfxCpu_reg.h"
#include "IfxCpu_regdef.h"
#include "IfxMtu_reg.h"
#include "IfxMc_bf.h"
#include "IfxMc_reg.h"
#include "IfxFlash_reg.h"
#include "IfxScu_reg.h"
#include "IfxSmu_reg.h"
#include "IfxXbar_reg.h"
#include "IfxXbar_bf.h"
#include "IfxLmu_reg.h"

/*******************************************************************************
**                      Local Macro Definitions                               **
*******************************************************************************/

/* ADMA_TEST_CTRL SFR definition: */
#define LMU_ECC_FAIL                        (2U)
#define ADMA_TEST_CTRL_REG_ADDRESS          (0xF870093CU)

/* MCx_CONNFIG0 values: */
#define SRAM_CONFIG0_NUMACCS_1              (1U)
#define SRAM_CONFIG0_ACCSTYPE_RD            (1U)
#define SRAM_CONFIG0_ACCSTYPE_WR            (0U)

/* Constants to extract major design step from SCU_CHIPID. Using bit fields is
 * from SFR file is not possible here, as no dedicated bit field for extracting
 * only the major design step exists:
 */
#define SRAM_SCU_CHIPID_DSM_MSK             ((uint32)0x00000030U)
#define SRAM_SCU_CHIPID_DSM_OFF             ((uint32)4U)
#define SRAM_A_STEP                         ((uint32)0U)
#define SRAM_B_STEP                         ((uint32)1U)
#define SRAM_C_STEP                         ((uint32)2U)
#define SRAM_D_STEP                         ((uint32)3U)

/* Invalid value for Clock Backups, indicating that nothing is to be restored:
 */
#define SRAM_INV_BACKUP_VALUE               ((uint32)0xFFFFFFFFU)

/* Size of address range of each memory controller in bytes: */
#define SRAM_MC_ADDR_RANGE_SIZE             ((uint32)&MODULE_MC1 -            \
                                             (uint32)&MODULE_MC0)

/* Maximum number of RDBFL registers per memory controller, this needs to be
 * adjusted if new SRAMs are added: */
#define SRAM_MAX_RDBFL_REGS                 (11U)

/* Minimum and maximum number of wordlines used by the test: */
#define SRAM_MIN_NR_OF_WORDLINES            (2U)
#define SRAM_MAX_NR_OF_WORDLINES            (6U)

/* Number of bits per RDBFLx SFR: */
#define SRAM_RDBFL_REG_WIDTH                (16U)
/*address of all SRAMs to make dummy read access before enabling MBIST*/
#define SRAM_DSPR0_ADDRESS                  (0x70000000U)
#define SRAM_PSPR0_ADDRESS                  (0x70100000U)
#define SRAM_DSPR1_ADDRESS                  (0x60000000U)
#define SRAM_PSPR1_ADDRESS                  (0x60100000U)  
#define SRAM_DSPR2_ADDRESS                  (0x50000000U)
#define SRAM_PSPR2_ADDRESS                  (0x50100000U)    
#define SRAM_LMU_ADDRESS                    (0xB0000000U)  

/* Number of bits per word: */
#define SRAM_BITS_PER_WORD                  ((uint32)32U)

/* Distance between two wrodlines of TC29x CPU1 / 2 DSPR in system address
 * space. Due to interleaving, the distance is 2 wordlines:
 */
#define SRAM_TC29_DSPR2_WORDLINE_STEP       ((uint16)2U)

/* CPU1 / 2 dummy array size for TC29x. This array must span over two
 * interleaved DSPR wordlines, thus it needs to be at least 18 bytes
 * (9 half-words):
 */
#define SRAM_TC29_DSPR2_INTERLEAVE           (16U)

/* MCx_RANGE values selecting the whole DTAG / PTAG SRAM: */
#define SRAM_DTAG_RANGE                     ((uint16)0x8080U)
#if (CHIP_ID == 29U)
#define SRAM_CPU0_PTAG_RANGE                ((uint16)0x8180U)
#define SRAM_CPU1_PTAG_RANGE                ((uint16)0x8380U)
#define SRAM_CPU2_PTAG_RANGE                ((uint16)0x8380U)
#else /* (CHIP_ID == 29) */
#define SRAM_CPU0_PTAG_RANGE                ((uint16)0x8080U)
#define SRAM_CPU1_PTAG_RANGE                ((uint16)0x8180U)
#define SRAM_CPU2_PTAG_RANGE                ((uint16)0x8180U)
#endif /* (CHIP_ID != 29) */

/* Duration of complete memory fill MBIST operation for TAG SRAMs
 * (assuming, the SRAM clock has been set to be equal to the CPU clock):
 */
#define SRAM_DTAG_FILL_DELAY                ((uint16)136U)
#if (CHIP_ID == 29U)
#define SRAM_CPU0_PTAG_FILL_DELAY           ((uint16)264U)
#define SRAM_CPU1_PTAG_FILL_DELAY           ((uint16)520U)
#define SRAM_CPU2_PTAG_FILL_DELAY           ((uint16)520U)
#else /* (CHIP_ID == 29) */
#define SRAM_CPU0_PTAG_FILL_DELAY           ((uint16)136U)
#define SRAM_CPU1_PTAG_FILL_DELAY           ((uint16)264U)
#define SRAM_CPU2_PTAG_FILL_DELAY           ((uint16)264U)
#endif /* (CHIP_ID != 29) */

/* Timeout for memory initialization when MBIST controller is enabled or
 * disabled. The value has been chosen based on following consideration:
 * The time required for enabling a MC depends on the time required for
 * memory initialization. This time is determined by the number of wordlines.
 * The maximum time required per wordline is 9 SRAM clocks. Since the SRAM
 * clock is setup to be at least as fast as the executing CPU clock, SRAM clock
 * cycles can be directly replaced by the number of instructions executed.
 * The deepest memories (wrt no. of wordlines) affected by RAM auto
 * initialization are the CPU PCACHE SRAMs (CPU0: 8kB, 8byte per wordline =>
 * 1024 wordlines, CPU1/2: 16kB, 16byte per wordline => 1024 wordlines).
 * => max. 9216 instructions need to be executed until initialization has
 * completed. To avoid the need of counting the no. of instructions per loop,
 * it is assumed, that at least one instruction per loop is executed. As
 * additional precaution, the actual value is chosen few times greater than
 * required:
 */
#define SRAM_MBIST_MEM_INIT_TIMEOUT         (0x00008000U)

/* SMU alarm timeout. The value was chosen based on following considerations:
 * The worst case number of SMU cycles before an alarm gets visible is
 * n * 2 + 20 (with n = max. number of simultaneous alarms). With a maximum
 * of 32 * 7 alarms and maximum clock ratio fSPB/fSRI = 1/4 this evaluates to
 * 1872 CPU clock cycles. To avoid the counting the number of instructions per
 * loop cycle, it is assumed that only one instruction is executed per loop
 * cycle and thus the number of CPU clock cycles is directly used as timeout
 * value:
 */
#define SRAMECC_SMU_ALM_TIMEOUT             (2000U)

/* Timeout for enabling the MTU clock. As there is no information available
 * about how much time is required to enable the MTU clock, this value was
 * arbitrarily chosen to a relatively high value:
 */
#define SRAM_CLK_EN_TIMEOUT                 (0x100U)

/* Number of address error tests: */
#define SRAM_ADDR_ERR_TEST_COUNT            (4U)
/* Number of address error tests for single core: */
#define SRAM_ADDR_ERR_TEST_COUNT_SINGLECORE (2U)

/* Total number of SMU alarm groups: */
#define SRAM_SMU_ALARM_GROUP_COUNT          (7U)

/* Definition of CPU Core IDs: */
#define SRAM_CPU_CORE0                      ((uint8)0U)
#define SRAM_CPU_CORE1                      ((uint8)1U)
#define SRAM_CPU_CORE2                      ((uint8)2U)

#define SRAM_RAM_INIT_DISABLED              ((uint32)3U)



/* mask for core ID bits */
#define SRAM_CORE_ID_MASK               (3u)

/* mask for password Bits 2-7 */
#define SRAM_WDT_PASSWORD_LOWER_MASK    (0x000000FCu)

/* mask for password Bits 8-15 */
#define SRAM_WDT_PASSWORD_UPPER_MASK    (0x0000FF00u)

/* mask for password bits */
#define SRAM_WDT_PASSWORD_MASK          (SRAM_WDT_PASSWORD_LOWER_MASK | \
                                         SRAM_WDT_PASSWORD_UPPER_MASK)
/* mask for reload bits */
#define SRAM_WDT_RELOAD_MASK            (0xFFFF0000u)

/* mask for LCK and ENDINIT status bits */
#define SRAM_WDT_STATUS_MASK            (0x00000003u)

/* Reload value for watch dog in timeout mode */
#define SDWT_TIMEOUT_MODE_RELOAD        (0xFFFC0000u)

/*------ defines for proprietary SMU implementations: ------*/
/* SMU maximum alarms to validate API input parameters */
#define SRAM_SMU_MAX_ALARM_GROUP        (6U)
#define SRAM_SMU_MAX_ALARM_POS          (31U)

/* Alarm clear timeout; this timeout is set to the same value as
 * SRAMECC_SMU_ALM_TIMEOUT because it is assumed that clearing an SMU alarm
 * takes almost the same time as setting one:
 */
#define SRAM_SMU_AGSTATUS_TIMEOUT       (2000U)

#define MC_MCONTROL_USERED_MSK          (1U)
#define MC_MCONTROL_USERED              (14U)

#define PCACHE_INVALIDATE_TIMEOUT       (0x100U)
/*number of half words(uint16) of memory used during DSPR- testing calculated below*/
/*
num of bits used by testing  = NrOfDataBits * NrOfMemBlocks * NrOfMultiplexers * (NrOfEtrRegisters+1)
                             = 16 * 4 * 2 * (5+1) -> 768 bits 
num of bytes used by testing =  768/8 = 96 bytes                          
num of half words            = 96/2 = 48                                 
for 2 Memory controllers MC14 and MC27 -> 48*2 = 96 half words*/

#define SRAM_DSPR0_MEMORY_TEST_SIZE     (96U)

/*number of rdbfl registers used during DSPR0 testing*/
#define SRAM_RFBFL_REGS_COUNT_DSPR0     (11U)

/*following defines are used as result value for a smaller data type. For single
  DSPR0 test functions single variable is shared for result and another field.
  For that a smaller data type is required to which result can be initialized
  temporarily*/

#define SRAMECC_NOTEXECUTED_LOCAL        ((uint16)(0U))
#define SRAMECC_MBIST_INITIMEOUT_LOCAL   ((uint16)(1U))
#define SRAMECC_ETR_MISSING_LOCAL        ((uint16)(2U))
#define SRAMECC_ETR_DUPLICATE_LOCAL      ((uint16)(3U))
#define SRAMECC_SMU_ALMSTSERR_LOCAL      ((uint16)(4U))
#define SRAMECC_SUCCESS_LOCAL            ((uint16)(5U))

/*Number of memory controllers for DSPR0 on EP*/
#if (CHIP_ID == 23U)
#define SRAMECC_DSPR0_MC_SINGLECORE      2U
#else
#define SRAMECC_DSPR0_MC_SINGLECORE      1U
#endif
#define SRAM_DSPR0_WORDS_PER_WORDLINE    4U
#define SRAM_HALF_WORD_SIZE              16U
#define SRAM_MASK_LOWER_HALFWORD         0x0000FFFFU
#define SRAM_MASK_UPPER_HALFWORD         0xFFFF0000U
#define SRAM_MBIST_OPERATION_WAIT        50U
#define SRAM_ADDMON_ALM_SET              0x00001000U
#define SRAM_ADDMON_ALMAG0_BIT12         12U
#define SRAM_ECCD_VAL_EXPECTED           3U

#define SRAM_DUMMY_ECCD_WRITE            ((uint16)(0x780FU))
#define SRAM_LMU_MEMCON_RMWERR	         ((uint32)(4U))
/*******************************************************************************
**                      Local Type Definitions                                **
*******************************************************************************/

/* Type definition SramEccTst_BackupDataType -
 * This structure contains the backup values of SFRs, memory content and SMU
 * alarm action modified by the SramEccTst: */
typedef struct SramEccTst_BackupDataType
{
  /* SMU alarm action backup for ECC error correction: */
  Smu_AlarmActionType   AlmActionBackupSbeCorr;
  /* SMU alarm action backup for uncorrectable ECC errors: */
  Smu_AlarmActionType   AlmActionBackupUcErr;
  /* SMU alarm action backup for address errors: */
  Smu_AlarmActionType   AlmActionBackupAdrErr;
  /* SMU alarm action backup for address buffer overflows: */
  Smu_AlarmActionType   AlmActionBackupAdrBufFull;
  /* SMU alarm action backup for LMU ECC monitor alarm: */
  Smu_AlarmActionType   AlmActionBackupLmuEccOnlnMon;

  /* Combined result of the alarm action backup operations: */
  Std_ReturnType        GetAlmActionResult;

  /* Storage for memory clock settings (exact usage depends on memory under
   * test): */
  uint32                ClockBackup1;
  /* Storage for MBIST enable status: */
  uint32                MBistEnable;
  /* Storage for backup of memory controller enable status: */
  uint32                MemTest;

  /* Storage for memory content backup: */
#if (CHIP_ID == 21U) || (CHIP_ID == 22U) || (CHIP_ID == 23U) || (CHIP_ID == 24U)
  uint16                MemContentBackup[SRAM_DSPR0_MEMORY_TEST_SIZE];
#else
  uint16                MemContentBackup[SRAM_MAX_RDBFL_REGS *
                                         SRAM_MAX_NR_OF_WORDLINES];
#endif
  boolean               MemBackupValid;

  /* Backup of the MTU clock gating: */
  uint8                 MtuClcDisr;

  /* Backup of MCx_ECCS: */
  uint16                Eccs;

  /* Backup of MCx_RANGE: */
  uint16                Range;
#if (CHIP_ID == 23U)
  /* Backup of MC27_ECCS: */
  uint16                Eccs2;

  /* Backup of MC27_RANGE: */
  uint16                Range2;  
#endif
  /* Backup of ICACHE BYPASS Bit CPU0_PCON0.PCBYP: */
  uint8                 CpuCacheBypass;

  /* CRC over previous members: */
  uint32                Crc;

  /* CRC value of original memory content overwritten and restored by the test:
   */
  uint32                MemContentCrc;

}SramEccTst_BackupDataType;

/* Type definition SramEccTst_WdtContextType -
 * This structure holds all data that is stored during
 * SramEccTst_lResetXXXENDINIT call and is required by the
 * subsequent call of SramEccTst_lSetXXXENDINIT. It is a replacement for the
 * global static data of Mcal_Lib.
 */
typedef struct SramEccTst_WdtContextType
{
  /* Backup of watchdog timer reload value and password: */
  uint32  WdtTimAndPw;
}SramEccTst_WdtContextType;

/* Type definition SramEccTst_ScuWdtPtrListType -
 * This structure holds pointers to a watchdog control and status SFR.
 */
typedef struct SramEccTst_ScuWdtPtrListType
{
  volatile Ifx_SCU_WDTCPU_CON0* const Wdtcon0Ptr;
  volatile Ifx_SCU_WDTCPU_SR* const   WdtssrPtr;
}SramEccTst_ScuWdtPtrListType;




/*******************************************************************************
**                        Exported object definitions                          *
*******************************************************************************/


/*******************************************************************************
**                        Local object definitions                             *
*******************************************************************************/
/*This lookup table is maintained to get mapping for wordline index and expected 
  VAL in ECCD register. upper 16 bit contains expected VAL in ECCD register and 
  lower 16 bit contains wordline index. Such a mapping is done to avoid having
  2 different variables for VAL and wordline index for the loop in function 
  SramEccTst_lChkSramMonUeSingleCore(). It gets value for wordlineindex and VAL
  by giving index to this lookup table located in flash*/
#define IFX_SRAM_START_SEC_CONST_32BIT_ASIL_B
#include "Ifx_MemMap.h"

#if (CHIP_ID == 21U) || (CHIP_ID == 22U) || (CHIP_ID == 23U) || (CHIP_ID == 24U)
static const uint32 SramEccTst_kLukupTblExpValWLIdx[5U]=
{
  0xFFFFFFFFU,
  0x001F0000U,
  0x000F0001U,
  0x00070002U,
  0x00030003U
};
#endif
/* Base addresses of CPU SRAMs: */
static const uint32* const
  SramEccTst_SramBaseAddrList[SRAMECCTST_MEMORY_COUNT] =
{
  (uint32*)0x70000000U,   /* CPU0 DSPR */
  (uint32*)NULL_PTR,      /* CPU0 DTAG */
  (uint32*)0x70100000U,   /* CPU0 PSPR */
  (uint32*)NULL_PTR,      /* CPU0 PTAG */
  (uint32*)0x60000000U,   /* CPU1 DSPR */
  (uint32*)0x60000010U,   /* CPU1 DSPR2 */
  (uint32*)NULL_PTR,      /* CPU1_DTAG */
  (uint32*)0x60100000U,   /* CPU1 PSPR */
  (uint32*)NULL_PTR,      /* CPU1 PTAG */
  (uint32*)0x50000000U,   /* CPU2 DSPR */
  (uint32*)0x50000010U,   /* CPU2 DSPR2 */
  (uint32*)NULL_PTR,      /* CPU2 DTAG */
  (uint32*)0x50100000U,   /* CPU2 PSPR */
  (uint32*)NULL_PTR,      /* CPU2 PTAG */
  (uint32*)0xB0000000U    /* LMU */
};

#if ( (CHIP_ID == 23U) || (CHIP_ID == 22U) || (CHIP_ID == 21U)|| (CHIP_ID == 24U))
static const Sl_TstRsltType SramEccTst_kLocalResultTbl[] =
{
  SRAMECC_NOTEXECUTED,
  SRAMECC_MBIST_INITIMEOUT,
  SRAMECC_ETR_MISSING,
  SRAMECC_ETR_DUPLICATE,
  SRAMECC_SMU_ALMSTSERR,
  SRAMECC_SUCCESS
};
#endif

#define IFX_SRAM_STOP_SEC_CONST_32BIT_ASIL_B
#include "Ifx_MemMap.h"

#define IFX_SRAM_START_SEC_CONST_16BIT_ASIL_B
#include "Ifx_MemMap.h"
#if ( (CHIP_ID == 23U) || (CHIP_ID == 22U) || (CHIP_ID == 21U)|| (CHIP_ID == 24U))
/* patterns to load no errors to the RDBFL registers. Used in Address monitor fn
and also to revoke the ECC errors injected*/
const uint16 SramEccTst_kNoErrPtrn[11] =
{
  0x0000U,
  0x0003U,
  0x00C0U,
  0x3000U,
  0x0000U,
  0x000CU,
  0x0300U,
  0xC000U,
  0x0000U,
  0x0030U,
  0x0C00U
};

/* patterns to load single bit errors to the RDBFL registers */
const uint16 SramEccTst_kSingleBitErrPtrn[SRAM_RFBFL_REGS_COUNT_DSPR0] =
{
  0x0001U,
  0x0003U,
  0x00C0U,
  0x3000U,
  0x0000U,
  0x000CU,
  0x0300U,
  0xC000U,
  0x0000U,
  0x0030U,
  0x0C00U
};
/* patterns to load double bit errors to the RDBFL registers */
const uint16 SramEccTst_kDoubleBitErrPtrn[SRAM_RFBFL_REGS_COUNT_DSPR0] =
{
  0x0003U,
  0x0003U,
  0x00C0U,
  0x3000U,
  0x0000U,
  0x000CU,
  0x0300U,
  0xC000U,
  0x0000U,
  0x0030U,
  0x0C00U
};
#endif

#define IFX_SRAM_STOP_SEC_CONST_16BIT_ASIL_B
#include "Ifx_MemMap.h"
#define IFX_SRAM_START_SEC_CONST_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"

/* access table for watch dog and local timer variables */
static const SramEccTst_ScuWdtPtrListType
             SramEccTst_kScuWdtPtrList[MCAL_NO_OF_CORES+1U] =
{
  {
    .Wdtcon0Ptr = (volatile Ifx_SCU_WDTCPU_CON0*) (void *)&SCU_WDTSCON0,
    .WdtssrPtr = (volatile Ifx_SCU_WDTCPU_SR*) (void *)&SCU_WDTSSR,
  },
  {
    .Wdtcon0Ptr = &SCU_WDTCPU0_CON0,
    .WdtssrPtr = &SCU_WDTCPU0_SR
  },
#if ( MCAL_NO_OF_CORES > 1U )
  {
    .Wdtcon0Ptr = &SCU_WDTCPU1_CON0,
    .WdtssrPtr = &SCU_WDTCPU1_SR
  },
#if ( MCAL_NO_OF_CORES > 2U ) 
  {
    .Wdtcon0Ptr = &SCU_WDTCPU2_CON0,
    .WdtssrPtr = &SCU_WDTCPU2_SR
  }
#endif
#endif
};

#define IFX_SRAM_STOP_SEC_CONST_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"

#define IFX_SRAM_START_SEC_VAR_NONZERO_INIT_32BIT_ASIL_B
#include "Ifx_MemMap.h"

static SramEccTst_UnexpAlarmType SramEccTst_UnexpAlm =
{
  .Correctable = 0U,
  .Uncorrectable = 0U,
  .Address = 0U,
  .ErrTrkOvf = 0U,
  .Crc = 0U
};

#define IFX_SRAM_STOP_SEC_VAR_NONZERO_INIT_32BIT_ASIL_B
#include "Ifx_MemMap.h"


#define IFX_SRAM_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
/*******************************************************************************
**                        Imported function declarations                       *
*******************************************************************************/


/*******************************************************************************
**                        Local function prototypes                            *
*******************************************************************************/

static Sl_TstRsltType SramEccTst_lTestMemory
(
  const uint8 MemIdx,
  const Sl_ParamSetType ParamSetIndex,
  uint32* const TstSignature,
  SramEccTst_BackupDataType* const BackupData
);

static Ifx_MC* SramEccTst_lGetMc
(
  const uint8 MemIdx
);

static Sl_TstRsltType SramEccTst_lInit
(
  const uint8 MemIdx,
  const Sl_ParamSetType ParamSetIndex,
  SramEccTst_BackupDataType* const BackupData
);

static Sl_TstRsltType SramEccTst_lInitSmuAlarms
(
  const uint8 MemIdx,
  SramEccTst_BackupDataType* const BackupData
);

static Sl_TstRsltType SramEccTst_lRestore
(
  const uint8 MemIdx,
  const SramEccTst_ConfigType* const Config,
  const SramEccTst_BackupDataType* const BackupData
);

static Sl_TstRsltType SramEccTst_lRestoreSmuAlarms
(
  const uint8 MemIdx,
  const SramEccTst_BackupDataType* const BackupData
);

static Sl_TstRsltType SramEccTst_lBackupSmuAlmActions
(
  const uint8 MemIdx,
  SramEccTst_BackupDataType* const BackupData
);

static Sl_TstRsltType SramEccTst_lCountClearUnexpAlm
(
  const uint8 MemIdx
);

static Sl_TstRsltType SramEccTst_lCheckSmuAlarms
(
  const uint8 MemIdx
);

#if ((CHIP_ID == 26U) || (CHIP_ID == 27U) || (CHIP_ID == 29U))
static Sl_TstRsltType SramEccTst_lSetupSramClock
(
  const uint8 MemIdx,
  SramEccTst_BackupDataType* const BackupData
);

static Sl_TstRsltType SramEccTst_lRestoreSramClock
(
  const uint8 MemIdx,
  const SramEccTst_BackupDataType* const BackupData
);

static Sl_TstRsltType SramEccTst_lSetupCpuClockDiv
(
  const uint8 TargetCoreId,
  SramEccTst_BackupDataType* const BackupData
);

static void SramEccTst_lRestoreCpuClockDiv
(
  const uint8 TargetCoreId,
  const SramEccTst_BackupDataType* const BackupData
);
#endif /* (CHIP_ID == 26U) || (CHIP_ID == 27U) || (CHIP_ID == 29U) */

static uint8 SramEccTst_lCalcRdbflRegCount
(
  const uint8 MemIdx
);

static void SramEccTst_lCreateZeroPattern
(
  const uint8 MemIdx
);

LOCAL_INLINE void SramEccTst_lFlipBits
(
  const uint8 MemIdx,
  const uint8 WordIdx,
  const uint8 BitIdx,
  const uint8 BitCount
);

static void SramEccTst_lReadWordline
(
  const uint8 MemIdx,
  const uint16 WordlineIdx
);

static Sl_TstRsltType SramEccTst_lReadWordlineSafe
(
  const uint8 MemIdx,
  const uint16 WordlineIdx
);

static void SramEccTst_lWriteWordline
(
  const uint8 MemIdx,
  const uint16 WordlineIdx
);

static Sl_TstRsltType SramEccTst_lWriteWordlineSafe
(
  const uint8 MemIdx,
  const uint16 WordlineIdx
);

#if (CHIP_ID == 26U) || (CHIP_ID == 27U) || (CHIP_ID == 29U)
static Sl_TstRsltType SramEccTst_lClearSram
(
  const uint8 MemIdx,
  const uint16 Range,
  const uint16 Delay
);
#endif /* (CHIP_ID == 26) || (CHIP_ID == 27) || (CHIP_ID == 29) */

static Sl_TstRsltType SramEccTst_lCheckEccLogic
(
  const uint8 MemIdx,
  uint32* const TstSignature
);

static Sl_TstRsltType SramEccTst_lChkAddressMon
(
  const uint8 MemIdx,
  uint32* const TstSignature
);

static Sl_TstRsltType SramEccTst_lChkSramMon
(
  const uint8 MemIdx,
  uint32* const TstSignature
);

static Sl_TstRsltType SramEccTst_lChkSramMonCe
(
  const uint8 MemIdx,
  uint32* const TstSignature,
  uint16* const ValExpected,
  uint16* const WordlineIdx
);

static Sl_TstRsltType SramEccTst_lChkSramMonUe
(
  const uint8 MemIdx,
  uint32* const TstSignature,
  uint16* const ValExpected,
  uint16* const WordlineIdx
);

static Sl_TstRsltType SramEccTst_lChkSramMonEov
(
  const uint8 MemIdx,
  uint32* const TstSignature,
  const uint16 WordlineIdx
);

#if (CHIP_ID != 21U) && (CHIP_ID != 22U) && (CHIP_ID != 23U) && (CHIP_ID != 24U)
static Sl_TstRsltType SramEccTst_lChkLmuOnlnMon
(
  const uint8 MemIdx,
  uint32* const TstSignature
);
#endif

#if ( (CHIP_ID == 24U)||(CHIP_ID == 23U) || (CHIP_ID == 22U) || (CHIP_ID == 21U) )
static void SramEccTst_lDisableCaching
(
  SramEccTst_BackupDataType* const BackupData
);
static void SramEccTst_lRestoreCaching
(
  const SramEccTst_BackupDataType* const BackupData
);
#elif (CHIP_ID == 26U) || (CHIP_ID == 27U) || (CHIP_ID == 29U)
static Sl_TstRsltType SramEccTst_lInvalidateCache
(
  const uint8 MemIdx,
  const SramEccTst_BackupDataType* const BackupData
);

#endif /* (CHIP_ID == 26U) || (CHIP_ID == 27U) || (CHIP_ID == 29U) */

static void SramEccTst_lDummyRamAccess
(
  const uint8 MemIdx
);

static Sl_TstRsltType SramEccTst_lEnableMbist
(
  const uint8 MemIdx,
  uint32* const MemTestBackup
);

static Sl_TstRsltType SramEccTst_lRestoreMbist
(
  const uint8 MemIdx,
  const uint32 MemTestBackup
);

static Sl_TstRsltType SramEccTst_lWaitForSmuAlarm
(
  const uint8 SmuGrp,
  const uint8 SmuAlarmNr,
  uint32* const TstSignature
);

static Sl_TstRsltType SramEccTst_lBackupMemContent
(
  const uint8 MemIdx,
  const Sl_ParamSetType ParamSetIndex,
  SramEccTst_BackupDataType* const BackupData
);

static Sl_TstRsltType SramEccTst_lRestoreMemContent
(
  const uint8 MemIdx,
  const SramEccTst_BackupDataType* const BackupData
);

static Sl_TstRsltType SramEccTst_lCalcMemoryCrc
(
  const uint8 MemIdx,
  uint32* const Crc
);

static Sl_TstRsltType SramEccTst_lCheckMemoryCrc
(
  const uint8 MemIdx,
  const uint32 ExpectedCrc
);

static boolean SramEccTst_lFuncDevMtuTc008Exists
(
  void
);

static Sl_TstRsltType SramEccTst_lEnableMtuClock
(
  SramEccTst_BackupDataType* const BackupData
);

static Sl_TstRsltType SramEccTst_lRestoreMtuClock
(
  const SramEccTst_BackupDataType* const BackupData
);

LOCAL_INLINE uint32  SramEccTst_lCpuPwSequence
(
  const sint8 Wdt,
  const uint32 Password
);

LOCAL_INLINE uint32 SramEccTst_lCpuRelValue
(
  const sint8 Wdt,
  const uint32 TimReload
);

static void SramEccTst_lResetCpuENDINIT
(
  const sint8 Wdt,
  SramEccTst_WdtContextType* const WdtContext
);

static void SramEccTst_lSetCpuENDINIT
(
  const sint8 Wdt,
  const SramEccTst_WdtContextType* const WdtContext
);

static void SramEccTst_lResetENDINIT
(
  SramEccTst_WdtContextType* const WdtContext
);

static void SramEccTst_lResetSafetyENDINIT
(
  SramEccTst_WdtContextType* const WdtContext
);

static void SramEccTst_lSetENDINIT
(
  const SramEccTst_WdtContextType* const WdtContext
);

static void SramEccTst_lSetSafetyENDINIT
(
  const SramEccTst_WdtContextType* const WdtContext
);

static Std_ReturnType SramEccTst_lSmuClearAlarmStatus
(
  uint8 AlarmGroup,
  uint8 AlarmPos
);

LOCAL_INLINE uint32 SramEccTst_lCalcAlmCounterCrc
(
  void
);

static uint32 SramEccTst_lCalcBackupCrc
(
  const uint8 MemIdx,
  const SramEccTst_BackupDataType* const BackupData
);
#define IFX_SRAM_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"



#if ( (CHIP_ID == 23U) || (CHIP_ID == 22U) || (CHIP_ID == 21U)|| (CHIP_ID == 24U))
#define IFX_SRAM_START_SEC_CODE_NO_OPTIMIZED_ASIL_B
#include "Ifx_MemMap.h"
static Sl_TstRsltType SramEccTst_lChkSramMonSingleCore
(
  uint32* const TstSignature
);

static Sl_TstRsltType SramEccTst_lChkSramMonCeSingleCore
(
  uint32* const TstSignature
);

static Sl_TstRsltType SramEccTst_lChkSramMonUeSingleCore
(
  uint32* const TstSignature
);

static Sl_TstRsltType SramEccTst_lChkSramMonEovSingleCore
(
  uint32* const TstSignature
);

static Sl_TstRsltType   SramEccTst_lTestDspr0SingleCore
(
  uint32* const TstSignature, SramEccTst_BackupDataType* const BackupData  
);

static Sl_TstRsltType SramEccTst_lChkAddressMonSingleCore
(
  uint32* const TstSignature
);

static Sl_TstRsltType SramEccTst_lInitSingleCore
(
  SramEccTst_BackupDataType* const BackupData
);

static Sl_TstRsltType SramEccTst_lRestoreSingleCore
(
  const SramEccTst_BackupDataType* const BackupData
);

static uint32 SramEccTst_lCalcBackupCrcSingleCore
(
  const SramEccTst_BackupDataType* const BackupData
);
#define IFX_SRAM_STOP_SEC_CODE_NO_OPTIMIZED_ASIL_B
#include "Ifx_MemMap.h"
#endif
/*******************************************************************************
**                    Local in-line function definitions                       *
*******************************************************************************/


/*******************************************************************************
**                    Configuration error checking                             *
*******************************************************************************/


/*******************************************************************************
**                         Function definitions                                *
*******************************************************************************/

#define IFX_SRAM_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static Sl_TstRsltType SramEccTst_lTestMemory            **
**                       (const uint8 MemIdx,                                 **
**                        const Sl_ParamSetType ParamSetIndex,                **
**                        uint32* const TstSignature,                         **
**                        SramEccTst_BackupDataType* const BackupData)        **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : MemIdx - Index of the memory under test; Refer to       **
**                             definition of supported SRAMs in               **
**                             SramEccTst_MemDef.h for a list of supported    **
**                             values                                         **
**                    ParamSetIndex - config Parameter index                  **
**                                                                            **
** Parameters (out) : TstSignature - Test signature generated by the test     **
**                    BackupData - Pointer to backup data struct of SRAM test **
**                                                                            **
** Return value     : SRAMECC_SUCCESS - Memory test succeeded                 **
**                    <Error ID> - Type of error during memory test           **
**                                                                            **
** Description      : This function performs the SRAM ECC test for a single   **
**                    memory. It also takes care about initialization, memory **
**                    content backup and restoration of the memory.           **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType SramEccTst_lTestMemory
(
  const uint8 MemIdx,
  const Sl_ParamSetType ParamSetIndex,
  uint32* const TstSignature,
  SramEccTst_BackupDataType* const BackupData
)
{
  Sl_TstRsltType  Result = SRAMECC_NOTEXECUTED;
  Sl_TstRsltType  ResultTmp;

  /* Initialize the test: */
  ResultTmp = SramEccTst_lInit(MemIdx, ParamSetIndex, BackupData);
  if (SRAMECC_SUCCESS != ResultTmp)
  {
    Result = ResultTmp;
  } /* if (SRAMECC_SUCCESS != ResultTmp) */
  else
  {
    ResultTmp = SramEccTst_lCheckEccLogic(MemIdx, TstSignature);
    if (SRAMECC_SUCCESS != ResultTmp)
    {
      Result = ResultTmp;
    } /* if (SRAMECC_SUCCESS != ResultTmp) */
  } /* if (SRAMECC_SUCCESS == ResultTmp) */

  /* Restore settings changed by the test: */
  ResultTmp = SramEccTst_lRestore(MemIdx,
                                  &SramEccTst_ConfigRoot[ParamSetIndex],
                                  BackupData);
  if (SRAMECC_SUCCESS != ResultTmp)
  {
    Result = ResultTmp;
  } /* if (SRAMECC_SUCCESS != ResultTmp) */

  if (SRAMECC_NOTEXECUTED == Result)
  {
    Result = SRAMECC_SUCCESS;
  } /* if (SRAMECC_NOTEXECUTED == Result) */

  return Result;
} /* SramEccTst_lTestMemory */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static Ifx_MC* SramEccTst_lGetMc                        **
**                       (const uint8 MemIdx)                                 **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : MemIdx - Index of the memory under test; Refer to       **
**                             definition of supported SRAMs in               **
**                             SramEccTst_MemDef.h for a list of supported    **
**                             values                                         **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Pointer to Ifx_MC structure of given memory             **
**                                                                            **
** Description      : This function returns a pointer to the memory           **
**                    controllers SFRs for a given memory.                    **
**                                                                            **
*******************************************************************************/
static Ifx_MC* SramEccTst_lGetMc
(
  const uint8 MemIdx
)
{
  uint8   McIdx;
  Ifx_MC* Result;

  McIdx = SramEccTst_kMcTable[MemIdx];
  Result = (Ifx_MC*)((uint32)&MODULE_MC0 +
                     ((uint32)SRAM_MC_ADDR_RANGE_SIZE * (uint32)McIdx));

  return Result;
} /* SramEccTst_lGetMc */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static Sl_TstRsltType SramEccTst_lInit                  **
**                       (const uint8 MemIdx,                                 **
**                        const Sl_ParamSetType ParamSetIndex,                **
**                        SramEccTst_BackupDataType* const BackupData)        **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : MemIdx - Index of the memory under test; Refer to       **
**                             definition of supported SRAMs in               **
**                             SramEccTst_MemDef.h for a list of supported    **
**                             values                                         **
**                    ParamSetIndex - config Parameter index                  **
**                    BackupData - Pointer to backup data struct of SRAM test **
**                                                                            **
** Parameters (out) : BackupData - Pointer to backup data struct of SRAM test **
**                                                                            **
** Return value     : SRAMECC_SUCCESS - Initialization succeeded              **
**                    <Error ID> - Type of error during test initialization   **
**                                                                            **
** Description      : This function take the backup copy of all SFR values    **
**                    and SMU alarm actions that will be modified by the test.**
**                    Also checks whether the SMU alarms used by the test are **
**                    in the expected state.                                  **
**                    Furthermore it sets up the SMU alarm actions to         **
**                    No action of all SMU alarms triggered by the test.      **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType SramEccTst_lInit
(
  const uint8 MemIdx,
  const Sl_ParamSetType ParamSetIndex,
  SramEccTst_BackupDataType* const BackupData
)
{
  Sl_TstRsltType  Result = SRAMECC_NOTEXECUTED;
  Sl_TstRsltType  ResultTmp;
  Ifx_MC*         Mc;

  /* Invalidate backup values: */
  BackupData->Eccs = (uint16)SRAM_INV_BACKUP_VALUE;
  BackupData->ClockBackup1 = SRAM_INV_BACKUP_VALUE;
  BackupData->MemBackupValid = (boolean)FALSE;
  BackupData->MemTest = SRAM_INV_BACKUP_VALUE;
  BackupData->CpuCacheBypass = (uint8)SRAM_INV_BACKUP_VALUE;
  BackupData->MBistEnable = (boolean)FALSE;
  
  /* Note: There is no invalid value for BackupData->Range, since all values
   * 0x0000 to 0xFFFF are valid. Therefore BackupData->Eccs is used as valid
   * indicator for BackupData->Range. BackupData->Range is only initialized
   * to SRAM_INV_BACKUP_VALUE to have a defined initial value:
   */
  BackupData->Range = (uint16)SRAM_INV_BACKUP_VALUE;

  /* Check SramEccTst_kMcTable for valid MC index: */
  if (SRAM_MC_IDX_INVALID == SramEccTst_kMcTable[MemIdx])
  {
    Result = SRAMECC_CONSISTENCYERR;
  } /* if (SRAM_MC_IDX_INVALID == SramEccTst_kMcTable[MemIdx]) */
  else
  {
    /* Get pointer to memory controller SFRs of RAM under test: */
    Mc = SramEccTst_lGetMc(MemIdx);

    ResultTmp = SramEccTst_lInitSmuAlarms(MemIdx, BackupData);
    if (SRAMECC_SUCCESS != ResultTmp)
    {
      Result = ResultTmp;
    } /* if (SRAMECC_SUCCESS != ResultTmp)*/
    else
    {
#if ((CHIP_ID == 24U)|| (CHIP_ID == 23U) || (CHIP_ID == 22U) || (CHIP_ID == 21U) )
      /* Disable CPU instruction caching: */
      SramEccTst_lDisableCaching(BackupData);
#elif (CHIP_ID == 26U) || (CHIP_ID == 27U) || (CHIP_ID == 29U)
      /* Setup SRAM clock to ensure predefined duration of MBIST read/
       * write operations:
       */
      ResultTmp = SramEccTst_lSetupSramClock(MemIdx, BackupData);
      if (SRAMECC_SUCCESS != ResultTmp)
      {
        Result = ResultTmp;
      } /* if (SRAMECC_SUCCESS != ResultTmp) */
      else
      {
#endif /* (CHIP_ID == 26U) || (CHIP_ID == 27U) || (CHIP_ID == 29U) */
        /* Dummy access to SRAM under test: */
        SramEccTst_lDummyRamAccess(MemIdx);

        /* Calculate CRC over memory used for testing, if device is affected
         * by functional deviation MTU_TC.008:
         */
        if (((boolean)TRUE == SramEccTst_lFuncDevMtuTc008Exists()) &&
            ((boolean)TRUE ==
             SramEccTst_ConfigRoot[ParamSetIndex].BackupMemory))
        {
          ResultTmp = SramEccTst_lCalcMemoryCrc(MemIdx,
                                                &(BackupData->MemContentCrc));
        } /* if ((boolean)TRUE == SramEccTst_lFuncDevMtuTc008Exists()) &&
                ((boolean)TRUE ==
                 SramEccTst_ConfigRoot[ParamSetIndex].BackupMemory)) */
        else
        {
          ResultTmp = SRAMECC_SUCCESS;
        } /* if ((boolean)TRUE != SramEccTst_lFuncDevMtuTc008Exists()) ||
                ((boolean)TRUE !=
                 SramEccTst_ConfigRoot[ParamSetIndex].BackupMemory)) */

        if (SRAMECC_SUCCESS != ResultTmp)
        {
          Result = ResultTmp;
        } /* if (SRAMECC_SUCCESS != ResultTmp) */
        else
        {
          /* Enter MBIST test mode: */
          ResultTmp = SramEccTst_lEnableMbist(MemIdx, &(BackupData->MemTest));
          if (SRAMECC_SUCCESS != ResultTmp)
          {
            Result = ResultTmp;
          } /* if (SRAMECC_SUCCESS != ResultTmp) */
          else
          {
            BackupData->MBistEnable = (boolean)TRUE;
            /* Backup MCx_ECCS: */
            BackupData->Eccs = Mc->ECCS.U;

            /* Backup MCx_RANGE: */
            BackupData->Range = Mc->RANGE.U;

            /* Check whether error correction is enabled: */
            if ((SRAMECCTST_SMU_NONE !=
                 SramEccTst_kMemDef[MemIdx]->SmuNr_SbeCorr)
                && ((BackupData->Eccs & (uint16)((uint32)IFX_MC_ECCS_ECE_MSK <<
                                       (uint32)IFX_MC_ECCS_ECE_OFF)) == 0U))
            {
              Result = SRAMECC_MEM_ECECFG;
            } /* if ((SRAMECCTST_SMU_NONE !=
                      SramEccTst_kMemDef[MemIdx]->SmuNr_SbeCorr) &&
                    ((BackupData->Eccs & (uint16)((uint32)IFX_MC_ECCS_ECE_MSK <<
                                        (uint32)IFX_MC_ECCS_ECE_OFF)) == 0U)) */
            else
            {
              /* Backup memory used by the test: */
              Result = SramEccTst_lBackupMemContent(MemIdx,
                                                    ParamSetIndex,
                                                    BackupData);
            } /* if ((SRAMECCTST_SMU_NONE ==
                      SramEccTst_kMemDef[MemIdx]->SmuNr_SbeCorr) ||
                    ((BackupData->Eccs & (uint16)((uint32)IFX_MC_ECCS_ECE_MSK <<
                                        (uint32)IFX_MC_ECCS_ECE_OFF)) != 0U)) */
          } /* if (SRAMECC_SUCCESS == ResultTmp) */
        } /* if (SRAMECC_SUCCESS == ResultTmp) */
#if (CHIP_ID == 26U) || (CHIP_ID == 27U) || (CHIP_ID == 29U)
      } /* if (SRAMECC_SUCCESS == ResultTmp) */
#endif /* (CHIP_ID == 26U) || (CHIP_ID == 27U) || (CHIP_ID == 29U) */
    } /* if (SRAMECC_SUCCESS != ResultTmp) */
  } /* if (SRAM_MC_IDX_INVALID == SramEccTst_kMcTable[MemIdx]) */

  /* Calculate backup data crc: */
  BackupData->Crc = SramEccTst_lCalcBackupCrc(MemIdx, BackupData);

  return Result;
} /* SramEccTst_lInit */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static Sl_TstRsltType SramEccTst_lInitSmuAlarms         **
**                       (const uint8 MemIdx,                                 **
**                        SramEccTst_BackupDataType* const BackupData)        **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : MemIdx - Index of the memory under test; Refer to       **
**                             definition of supported SRAMs in               **
**                             SramEccTst_MemDef.h for a list of supported    **
**                             values                                         **
**                    BackupData - Pointer to backup data struct of SRAM test **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : SRAMECC_SUCCESS - SMU alarm initialization succeeded    **
**                    <Error ID> - Type of error during SNU alarm             **
**                                 initialization                             **
**                                                                            **
** Description      : This function backs up the alarm action of all SMU      **
**                    alarms used by the test, checks their initial alarm     **
**                    status and sets the alarm action to 'No action'.        **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType SramEccTst_lInitSmuAlarms
(
  const uint8 MemIdx,
  SramEccTst_BackupDataType* const BackupData
)
{
  Sl_TstRsltType  Result = SRAMECC_NOTEXECUTED;
  Sl_TstRsltType  ResultTmp;
  Std_ReturnType  SmuResult1;
  Std_ReturnType  SmuResult2;
  Std_ReturnType  SmuResult3;
  Std_ReturnType  SmuResult4;
  Std_ReturnType  SmuResult5;

  /* Backup SMU alarm actions: */
  ResultTmp = SramEccTst_lBackupSmuAlmActions(MemIdx, BackupData);
  if (SRAMECC_SUCCESS != ResultTmp)
  {
    Result = ResultTmp;
  } /* if (SRAMECC_SUCCESS != ResultTmp) */
  else
  {
    /* Check that none of the SMU alarms used by the test is already set: */
    ResultTmp = SramEccTst_lCheckSmuAlarms(MemIdx);
    if (SRAMECC_SUCCESS != ResultTmp)
    {
      Result = ResultTmp;
    } /* if (SRAMECC_SUCCESS != ResultTmp) */
    else
    {
      /* Set alarm actions of all SMU alarms used by the test to no action: */
      if (SRAMECCTST_SMU_NONE == SramEccTst_kMemDef[MemIdx]->SmuNr_SbeCorr)
      {
        SmuResult1 = E_OK;
      } /* if (SRAMECCTST_SMU_NONE ==
               SramEccTst_kMemDef[MemIdx]->SmuNr_SbeCorr) */
      else
      {
        SmuResult1 = Smu_SetAlarmAction
            (SramEccTst_kMemDef[MemIdx]->SmuAlarmGrp,
             SramEccTst_kMemDef[MemIdx]->SmuNr_SbeCorr,
             SMU_ALARM_ACTION_NONE
            );
      } /* if (SRAMECCTST_SMU_NONE !=
               SramEccTst_kMemDef[MemIdx]->SmuNr_SbeCorr) */
      SmuResult2 = Smu_SetAlarmAction
          (SramEccTst_kMemDef[MemIdx]->SmuAlarmGrp,
           SramEccTst_kMemDef[MemIdx]->SmuNr_UcErr,
           SMU_ALARM_ACTION_NONE
          );
      SmuResult3 = Smu_SetAlarmAction
          (SramEccTst_kMemDef[MemIdx]->SmuAlarmGrp,
           SramEccTst_kMemDef[MemIdx]->SmuNr_AdrErr,
           SMU_ALARM_ACTION_NONE
          );
      SmuResult4 = Smu_SetAlarmAction
          (SramEccTst_kMemDef[MemIdx]->SmuAlarmGrp,
           SramEccTst_kMemDef[MemIdx]->SmuNr_AdrBufFull,
           SMU_ALARM_ACTION_NONE
          );
      /* Set LMU ECC monitor SMU alarm action to none: */
      if (SRAM_DAM == MemIdx)
      {
        SmuResult5 = Smu_SetAlarmAction
            (SramEccTst_kMemDef[MemIdx]->SmuAlarmGrp,
             SMU_ALARM_15,
             SMU_ALARM_ACTION_NONE);
      } /* if (SRAM_DAM == MemIdx) */
      else
      {
        SmuResult5 = E_OK;       
      }

      if ((E_OK != SmuResult1) ||
          (E_OK != SmuResult2) ||
          (E_OK != SmuResult3) ||
          (E_OK != SmuResult4) ||
          (E_OK != SmuResult5)
         )
      {
        Result = SRAMECC_SMU_SETALMACTIONERR;
      } /* if ((E_OK != SmuResult1) || (E_OK != SmuResult2) ||
               (E_OK != SmuResult3) || (E_OK != SmuResult4) ||
               (E_OK != SmuResult5)) */
      else
      {
        Result = SRAMECC_SUCCESS;
      } /* if ((E_OK == SmuResult1) && (E_OK == SmuResult2) &&
               (E_OK == SmuResult3) && (E_OK == SmuResult4) &&
               (E_OK == SmuResult5)) */
    } /* if (SRAMECC_SUCCESS == ResultTmp) */
  } /* if (SRAMECC_SUCCESS == ResultTmp) */

  return Result;
} /* SramEccTst_lInitSmuAlarms */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static Sl_TstRsltType SramEccTst_lRestore               **
**                       (const uint8 MemIdx,                                 **
**                        const SramEccTst_BackupDataType* const BackupData)  **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : MemIdx - Index of the memory under test; Refer to       **
**                             definition of supported SRAMs in               **
**                             SramEccTst_MemDef.h for a list of supported    **
**                             values                                         **
**                    Config - config Parameter index                         **
**                    BackupData - Pointer to backup data struct of SRAM test **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : SRAM_SUCCESS - Test restoration succeeded               **
**                    <Error ID> - Type of error during test restoration      **
**                                                                            **
** Description      : This function restores all SFRs, SMU alarm actions and  **
**                    memory content that has been modified by the test.      **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType SramEccTst_lRestore
(
  const uint8 MemIdx,
  const SramEccTst_ConfigType* const Config,
  const SramEccTst_BackupDataType* const BackupData
)

{
  Sl_TstRsltType            Result = SRAMECC_NOTEXECUTED;
  Sl_TstRsltType            ResultTmp;
  Ifx_MC*                   Mc;
  SramEccTst_WdtContextType WdtContext;
  uint8                     Count, RdbflRegCount;  

  UNUSED_PARAMETER(Config)

  /* Check backup data crc: */
  if (SramEccTst_lCalcBackupCrc(MemIdx, BackupData) != BackupData->Crc)
  {
    Result = SRAMECC_DATACORRUPTION;
  } /* if (SramEccTst_lCalcBackupCrc(BackupData) != BackupData->Crc) */
  else
  {
    /* Get pointer to memory controller SFRs of RAM under test: */
    Mc = SramEccTst_lGetMc(MemIdx);
    /* Backup succeeded? */
    if (E_OK == BackupData->GetAlmActionResult)
    {
      /* Restore memory content overwritten by the test: */
      ResultTmp = SramEccTst_lRestoreMemContent(MemIdx,
                                                BackupData);
                        
      if (SRAMECC_SUCCESS != ResultTmp)
      {
        Result = ResultTmp;
      } /* if (SRAMECC_SUCCESS != ResultTmp) */

      /* Restore MCx_ECCS if its backup value is valid: */
      if (0xFFFFU != BackupData->Eccs)
      {
        SramEccTst_lResetSafetyENDINIT(&WdtContext);
        Mc->ECCS.U = BackupData->Eccs;
        SramEccTst_lSetSafetyENDINIT(&WdtContext);

        /* Restore MCx_RANGE; if BackupData->Eccs is valid, then BackupData->
         * Range is always valid, too:
         */
        Mc->RANGE.U = BackupData->Range;
      } /* if (0xFFFFU != BackupData->Eccs) */

#if (CHIP_ID == 26U) || (CHIP_ID == 27U) || (CHIP_ID == 29U)
      /* Invalidate cache SRAM (if required): */
      ResultTmp = SramEccTst_lInvalidateCache(MemIdx, BackupData);
      if (SRAMECC_SUCCESS != ResultTmp)
      {
        Result = ResultTmp;
      }
#endif /* (CHIP_ID == 26) || (CHIP_ID == 27) || (CHIP_ID == 29) */

      if ((boolean)TRUE == BackupData->MBistEnable)
      {
        RdbflRegCount = SramEccTst_lCalcRdbflRegCount(MemIdx);

        for (Count= 0U;Count < RdbflRegCount; Count++)
        {
          Mc->RDBFL[Count].U = (uint16)0U;
        }
      } 
      
      /* Leave MBIST test mode: */
      ResultTmp = SramEccTst_lRestoreMbist(MemIdx, BackupData->MemTest);
      if (SRAMECC_SUCCESS != ResultTmp)
      {
        Result = ResultTmp;
      } /* if (SRAMECC_SUCCESS != ResultTmp) */

      /* Check CRC of restored memory if device is affected by MTU_TC.008: */
      if (((boolean)TRUE == SramEccTst_lFuncDevMtuTc008Exists()) &&
          ((boolean)TRUE == BackupData->MemBackupValid))
      {
        ResultTmp = SramEccTst_lCheckMemoryCrc(MemIdx,
                                               BackupData->MemContentCrc);
        if (SRAMECC_SUCCESS != ResultTmp)
        {
          Result = ResultTmp;
        } /* if (SRAMECC_SUCCESS != ResultTmp) */
       
      } /* if (((boolean)TRUE == SramEccTst_lFuncDevMtuTc008Exists()) &&
               ((boolean)TRUE == BackupData->MemBackupValid)) */

#if ( (CHIP_ID == 23U) || (CHIP_ID == 22U) || (CHIP_ID == 21U) )
      /* Restore CPU instruction caching: */
      SramEccTst_lRestoreCaching(BackupData);
#elif (CHIP_ID == 26U) || (CHIP_ID == 27U) || (CHIP_ID == 29U)
      /* Restore clock settings: */
      ResultTmp = SramEccTst_lRestoreSramClock(MemIdx, BackupData);
      if (SRAMECC_SUCCESS != ResultTmp)
      {
        Result = ResultTmp;
      } /* if (SRAMECC_SUCCESS != ResultTmp) */
#endif /* (CHIP_ID == 26U) || (CHIP_ID == 27U) || (CHIP_ID == 29U) */

      /* Restore SMU alarm actions: */
      ResultTmp = SramEccTst_lRestoreSmuAlarms(MemIdx, BackupData);
      if (SRAMECC_SUCCESS != ResultTmp)
      {
        Result = ResultTmp;
      } /* if (SRAMECC_SUCCESS != ResultTmp) */

      /* Update result:: */
      if (SRAMECC_NOTEXECUTED == Result)
      {
        Result = SRAMECC_SUCCESS;
      } /* if (SRAMECC_NOTEXECUTED == Result) */
    } /* if (E_OK == BackupData->GetAlmActionResult) */
    else
    {
      /* No backup data available, nothing to do: */
      Result = SRAMECC_SUCCESS;
    } /* if (E_OK != BackupData->GetAlmActionResult) */
    
    if((MemIdx == SRAM_CPU0_PSPR)||(MemIdx == SRAM_CPU0_PTAG))
    {
	  #if ( MCAL_NO_OF_CORES == 1U )
	  MTCR(CPU_PIETR, 0U);
	  #else
      CPU0_PIETR.U = 0U;  
	  #endif
    }
    #if ( MCAL_NO_OF_CORES > 1U )	
    else if((MemIdx == SRAM_CPU1_PSPR0)||(MemIdx == SRAM_CPU1_PTAG))
    {
      CPU1_PIETR.U = 0U;   
    }
	#if ( MCAL_NO_OF_CORES > 2U )	
    else if((MemIdx == SRAM_CPU2_PSPR)||(MemIdx == SRAM_CPU2_PTAG))
    {
      CPU2_PIETR.U = 0U;   
    }
	#endif
	#endif
	else if(MemIdx == SRAM_DAM)
	{
      SramEccTst_lResetENDINIT(&WdtContext);
	  LMU_MEMCON.U&= ~(unsigned_int)((unsigned_int)1U << (unsigned_int)SRAM_LMU_MEMCON_RMWERR);
	  SramEccTst_lSetENDINIT(&WdtContext);
      XBAR_ARBCON4.U |= (unsigned_int)((unsigned_int)IFX_XBAR_ARBCON_INTACK_MSK <<
                                   IFX_XBAR_ARBCON_INTACK_OFF);
      /* Clear all the bits of XBAR_INTSAT and XBAR_IDINTSAT registers */
      XBAR_INTSAT.U = (unsigned_int)((unsigned_int)IFX_XBAR_INTSAT_PRSCI0_MSK <<
                                   IFX_XBAR_INTSAT_PRSCI4_OFF);
	} 
    else
    {
      /*added to avoid MISRA violation*/
    }
  
  } /* if (SramEccTst_lCalcBackupCrc(BackupData) == BackupData->Crc) */

  return Result;
} /* SramEccTst_lRestore */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static Sl_TstRsltType SramEccTst_lRestoreSmuAlarms      **
**                       (const uint8 MemIdx,                                 **
**                        const SramEccTst_BackupDataType* const BackupData)  **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : MemIdx - Index of the memory under test; Refer to       **
**                             definition of supported SRAMs in               **
**                             SramEccTst_MemDef.h for a list of supported    **
**                             values                                         **
**                    BackupData - Pointer to backup data struct of SRAM test **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : SRAM_SUCCESS - SMU alarm restoration succeeded          **
**                    <Error ID> - Type of error during SMU alarm restoration **
**                                                                            **
** Description      : This function restores all SMU alarm actions that have  **
**                    been modified by the test.                              **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType SramEccTst_lRestoreSmuAlarms
(
  const uint8 MemIdx,
  const SramEccTst_BackupDataType* const BackupData
)
{
  Sl_TstRsltType            Result = SRAMECC_NOTEXECUTED;
  Std_ReturnType            SmuResult1;
  Std_ReturnType            SmuResult2;
  Std_ReturnType            SmuResult3;
  Std_ReturnType            SmuResult4;
  Std_ReturnType            SmuResult5;

  /* Restore SMU alarm actions: */
  if (SRAMECCTST_SMU_NONE == SramEccTst_kMemDef[MemIdx]->SmuNr_SbeCorr)
  {
    /* No correctable error SMU alarm for PTAG DED codes: */
    SmuResult1 = E_OK;
  } /* if (SRAMECCTST_SMU_NONE ==
           SramEccTst_kMemDef[MemIdx]->SmuNr_SbeCorr) */
  else
  {
    SmuResult1 = Smu_SetAlarmAction
        (SramEccTst_kMemDef[MemIdx]->SmuAlarmGrp,
         SramEccTst_kMemDef[MemIdx]->SmuNr_SbeCorr,
         BackupData->AlmActionBackupSbeCorr
        );
  } /* if (SRAMECCTST_SMU_NONE !=
           SramEccTst_kMemDef[MemIdx]->SmuNr_SbeCorr) */
  SmuResult2 = Smu_SetAlarmAction
      (SramEccTst_kMemDef[MemIdx]->SmuAlarmGrp,
       SramEccTst_kMemDef[MemIdx]->SmuNr_UcErr,
       BackupData->AlmActionBackupUcErr
      );
  SmuResult3 = Smu_SetAlarmAction
      (SramEccTst_kMemDef[MemIdx]->SmuAlarmGrp,
       SramEccTst_kMemDef[MemIdx]->SmuNr_AdrErr,
       BackupData->AlmActionBackupAdrErr
      );
  SmuResult4 = Smu_SetAlarmAction
      (SramEccTst_kMemDef[MemIdx]->SmuAlarmGrp,
       SramEccTst_kMemDef[MemIdx]->SmuNr_AdrBufFull,
       BackupData->AlmActionBackupAdrBufFull
      );
  /* Restore LMU ECC Monitor SMU alarm action: */
  if (SRAM_DAM == MemIdx)
  {
    SmuResult5 = Smu_SetAlarmAction
        (SramEccTst_kMemDef[MemIdx]->SmuAlarmGrp,
         SMU_ALARM_15,
         BackupData->AlmActionBackupLmuEccOnlnMon);
  } /* if (SRAM_DAM == MemIdx) */
  else
  {
    SmuResult5 = E_OK;       
  }  

      if ((E_OK != SmuResult1) ||
          (E_OK != SmuResult2) ||
          (E_OK != SmuResult3) ||
          (E_OK != SmuResult4) ||
          (E_OK != SmuResult5)
         )
  {
    Result = SRAMECC_SMU_SETALMACTIONERR;
  } /* if ((E_OK != SmuResult1) || (E_OK != SmuResult2) ||
           (E_OK != SmuResult3) || (E_OK != SmuResult4) ||
           (E_OK != SmuResult5)) */
  else
  {
    Result = SRAMECC_SUCCESS;
  } /* if ((E_OK == SmuResult1) && (E_OK == SmuResult2) &&
           (E_OK == SmuResult3) && (E_OK == SmuResult4) &&
           (E_OK == SmuResult5)) */

  return Result;
} /* SramEccTst_lRestoreSmuAlarms */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static Sl_TstRsltType SramEccTst_lBackupSmuAlmActions   **
**                       (const uint8 MemIdx,                                 **
**                        SramEccTst_BackupDataType* const BackupData)        **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : MemIdx - Index of the memory under test; Refer to       **
**                             definition of supported SRAMs in               **
**                             SramEccTst_MemDef.h for a list of supported    **
**                             values                                         **
**                    BackupData - Pointer to backup data struct of SRAM test **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : SRAMECC_SUCCESS - SMU alarm action backup succeeded     **
**                    <Error ID> - Type of error during backup                **
**                                                                            **
** Description      : This function takes backup copy of SMU alarm actions    **
**                    of all SMU alarms triggered by the test.                **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType SramEccTst_lBackupSmuAlmActions
(
  const uint8 MemIdx,
  SramEccTst_BackupDataType* const BackupData
)
{
  Sl_TstRsltType  Result = SRAMECC_NOTEXECUTED;
  Std_ReturnType  SmuResult1;
  Std_ReturnType  SmuResult2;
  Std_ReturnType  SmuResult3;
  Std_ReturnType  SmuResult4;
  Std_ReturnType  SmuResult5;

  /*The value of the FSP action backup will be irrelevant as
   * SMU FSP is not activated during SafeTlib Pre-run phase.
   */
  Smu_FSPActionType SmuAlarmFspAction = 0U;

  /* Backup SMU alarm actions: */
  if (SRAMECCTST_SMU_NONE == SramEccTst_kMemDef[MemIdx]->SmuNr_SbeCorr)
  {
    /* For DED codes there is no correctable error SMU alarm */
    SmuResult1 = E_OK;
  } /* if (SRAMECCTST_SMU_NONE == SramEccTst_kMemDef[MemIdx]->SmuNr_SbeCorr) */
  else
  {
    SmuResult1 = Smu_GetAlarmAction
        (SramEccTst_kMemDef[MemIdx]->SmuAlarmGrp,
         SramEccTst_kMemDef[MemIdx]->SmuNr_SbeCorr,
         &BackupData->AlmActionBackupSbeCorr,
         &SmuAlarmFspAction
        );
  } /* if (SRAMECCTST_SMU_NONE != SramEccTst_kMemDef[MemIdx]->SmuNr_SbeCorr) */
  SmuResult2 = Smu_GetAlarmAction
      (SramEccTst_kMemDef[MemIdx]->SmuAlarmGrp,
       SramEccTst_kMemDef[MemIdx]->SmuNr_UcErr,
       &BackupData->AlmActionBackupUcErr,
       &SmuAlarmFspAction
      );
  SmuResult3 = Smu_GetAlarmAction
      (SramEccTst_kMemDef[MemIdx]->SmuAlarmGrp,
       SramEccTst_kMemDef[MemIdx]->SmuNr_AdrErr,
       &BackupData->AlmActionBackupAdrErr,
       &SmuAlarmFspAction
      );
  SmuResult4 = Smu_GetAlarmAction
      (SramEccTst_kMemDef[MemIdx]->SmuAlarmGrp,
       SramEccTst_kMemDef[MemIdx]->SmuNr_AdrBufFull,
       &BackupData->AlmActionBackupAdrBufFull,
       &SmuAlarmFspAction);

  /* Backup LMU ECC Monitor SMU alarm action: */
  if (SRAM_DAM == MemIdx)
  {
    SmuResult5 = Smu_GetAlarmAction
        (SramEccTst_kMemDef[MemIdx]->SmuAlarmGrp,
         SMU_ALARM_15,
         &BackupData->AlmActionBackupLmuEccOnlnMon,
         &SmuAlarmFspAction);
  } /* if (SRAM_DAM == MemIdx) */
  else
  {
    SmuResult5 = E_OK;       
  } 
  /* Check if SMU alarm action backup was successful: */
      if ((E_OK != SmuResult1) ||
          (E_OK != SmuResult2) ||
          (E_OK != SmuResult3) ||
          (E_OK != SmuResult4) ||
          (E_OK != SmuResult5)
         )

  {
    BackupData->GetAlmActionResult = E_NOT_OK;
    Result = SRAMECC_SMU_GETALMACTIONERR;
  } /* if ((E_OK != SmuResult1) || (E_OK != SmuResult2) ||
           (E_OK != SmuResult3) || (E_OK != SmuResult4) ||
           (E_OK != SmuResult5)) */
  else
  {
    BackupData->GetAlmActionResult = E_OK;
    Result = SRAMECC_SUCCESS;
  } /* if ((E_OK == SmuResult1) && (E_OK == SmuResult2) &&
           (E_OK == SmuResult3) && (E_OK == SmuResult4) &&
           (E_OK == SmuResult5)) */

  return Result;
} /* SramEccTst_lBackupSmuAlmActions */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static Sl_TstRsltType SramEccTst_lCountClearUnexpAlm    **
**                       (const uint8 MemIdx)                                 **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : MemIdx - Index of the memory under test; Refer to       **
**                             definition of supported SRAMs in               **
**                             SramEccTst_MemDef.h for a list of supported    **
**                             values                                         **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : SRAMECC_SUCCESS - Clearing of unexpected alarms         **
**                                      succeeded                             **
**                    <Error ID> - Type of error during alarm clearing        **
**                                                                            **
** Description      : This function counts all unexpected SRAM ECC SMU alarms **
**                    to SramEccTst_UnexpAlm structure and clears all set     **
**                    alarms.                                                 **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType SramEccTst_lCountClearUnexpAlm
(
  const uint8 MemIdx
)
{
  Sl_TstRsltType  Result = SRAMECC_NOTEXECUTED;
  Std_ReturnType  SmuResult;
  Std_ReturnType  SmuResult1 = E_NOT_OK;
  Std_ReturnType  SmuResult2 = E_NOT_OK;
  Std_ReturnType  SmuResult3 = E_NOT_OK;
  Std_ReturnType  SmuResult4 = E_NOT_OK;
  uint32          AlarmStatus;

  /* Check alarm counter CRC value: */
  if (SramEccTst_UnexpAlm.Crc != SramEccTst_lCalcAlmCounterCrc())
  {
    Result = SRAMECC_DATACORRUPTION;
  } /* if (SramEccTst_UnexpAlm.Crc != SramEccTst_lCalcAlmCounterCrc()) */
  else
  {
    /* Check that none of the SMU alarms used by the test is already set: */
    SmuResult = Smu_GetAlarmStatus
        (SramEccTst_kMemDef[MemIdx]->SmuAlarmGrp,
         &AlarmStatus
        );
    if (E_OK != SmuResult)
    {
      Result = SRAMECC_SMU_GETALMSTSERR;
    } /* if (E_OK != SmuResult) */
    else
    {
      /* Check if correctable ECC error SMU alarm already set: */
      if ((SRAMECCTST_SMU_NONE != SramEccTst_kMemDef[MemIdx]->SmuNr_SbeCorr) &&
          ((AlarmStatus &
            ((uint32)1U << SramEccTst_kMemDef[MemIdx]->SmuNr_SbeCorr)) > 0U))
      {
        SramEccTst_UnexpAlm.Correctable++;
        SmuResult1 = Smu_ClearAlarmStatus
            (SramEccTst_kMemDef[MemIdx]->SmuAlarmGrp,
             SramEccTst_kMemDef[MemIdx]->SmuNr_SbeCorr);
      } /* if ((SRAMECCTST_SMU_NONE != SramEccTst_kMemDef[MemIdx]->SmuNr_SbeCorr)
               && (AlarmStatus &
               ((uint32)1U << SramEccTst_kMemDef[MemIdx]->SmuNr_SbeCorr)) > 0U) */
      else
      {
        SmuResult1 = E_OK;
      } /* if ((SRAMECCTST_SMU_NONE == SramEccTst_kMemDef[MemIdx]->SmuNr_SbeCorr)
               || (AlarmStatus &
              ((uint32)1U << SramEccTst_kMemDef[MemIdx]->SmuNr_SbeCorr)) == 0U) */

      /* Check if uncorrectable ECC error SMU alarm already set: */
      if ((AlarmStatus &
           ((uint32)1U << SramEccTst_kMemDef[MemIdx]->SmuNr_UcErr)) > 0U)
      {
        SramEccTst_UnexpAlm.Uncorrectable++;
        SmuResult2 = Smu_ClearAlarmStatus
            (SramEccTst_kMemDef[MemIdx]->SmuAlarmGrp,
             SramEccTst_kMemDef[MemIdx]->SmuNr_UcErr);
      } /* if ((AlarmStatus &
               ((uint32)1U << SramEccTst_kMemDef[MemIdx]->SmuNr_UcErr)) > 0U) */
      else
      {
        SmuResult2 = E_OK;
      } /* if ((AlarmStatus &
               ((uint32)1U << SramEccTst_kMemDef[MemIdx]->SmuNr_UcErr)) == 0U) */

      /* Check if address error SMU alarm already set: */
      if ((AlarmStatus &
           ((uint32)1U << SramEccTst_kMemDef[MemIdx]->SmuNr_AdrErr)) > 0U)
      {
        SramEccTst_UnexpAlm.Address++;
        SmuResult3 = Smu_ClearAlarmStatus
            (SramEccTst_kMemDef[MemIdx]->SmuAlarmGrp,
             SramEccTst_kMemDef[MemIdx]->SmuNr_AdrErr);
      } /* if ((AlarmStatus &
                ((uint32)1U << SramEccTst_kMemDef[MemIdx]->SmuNr_AdrErr)) > 0U) */
      else
      {
        SmuResult3 = E_OK;
      } /* if ((AlarmStatus &
               ((uint32)1U << SramEccTst_kMemDef[MemIdx]->SmuNr_AdrErr)) == 0U) */

      /* Check if error tracking overflow SMU alarm already set: */
      if ((AlarmStatus &
           ((uint32)1U << SramEccTst_kMemDef[MemIdx]->SmuNr_AdrBufFull)) > 0U)
      {
        SramEccTst_UnexpAlm.ErrTrkOvf++;
        SmuResult4 = Smu_ClearAlarmStatus
            (SramEccTst_kMemDef[MemIdx]->SmuAlarmGrp,
             SramEccTst_kMemDef[MemIdx]->SmuNr_AdrBufFull);
      } /* if ((AlarmStatus &
            ((uint32)1U << SramEccTst_kMemDef[MemIdx]->SmuNr_AdrBufFull)) > 0U) */
      else
      {
        SmuResult4 = E_OK;
      } /* if ((AlarmStatus &
           ((uint32)1U << SramEccTst_kMemDef[MemIdx]->SmuNr_AdrBufFull)) == 0U) */

      if ((E_OK != SmuResult1) || (E_OK != SmuResult2) ||
          (E_OK != SmuResult3) || (E_OK != SmuResult4))
      {
        Result = SRAMECC_SMU_CLRALMSTSERR;
      } /* if ((E_OK != SmuResult1) || (E_OK != SmuResult2) ||
               (E_OK != SmuResult3) || (E_OK != SmuResult4)) */
      else
      {
        Result = SRAMECC_SUCCESS;
      } /* if ((E_OK == SmuResult1) && (E_OK == SmuResult2) &&
               (E_OK == SmuResult3) && (E_OK == SmuResult4)) */
    } /* if (E_OK == SmuResult) */

    /* Update unexpected alarm counter CRC: */
    SramEccTst_UnexpAlm.Crc = SramEccTst_lCalcAlmCounterCrc();
  } /* if (SramEccTst_UnexpAlm.Crc != SramEccTst_lCalcAlmCounterCrc()) */

  return Result;
} /* SramEccTst_lCountClearUnexpAlm */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static Sl_TstRsltType SramEccTst_lCheckSmuAlarms        **
**                       (const uint8 MemIdx)                                 **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : MemIdx - Index of the memory under test; Refer to       **
**                             definition of supported SRAMs in               **
**                             SramEccTst_MemDef.h for a list of supported    **
**                             values                                         **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : SRAMECC_SUCCESS - SMU alarm check succeeded             **
**                    <Error ID> - Type of error during alarm check           **
**                                                                            **
** Description      : This function checks that none of the SMU alarms        **
**                    triggered by the test is already set before the test.   **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType SramEccTst_lCheckSmuAlarms
(
  const uint8 MemIdx
)
{
  Sl_TstRsltType  Result = SRAMECC_NOTEXECUTED;
  Sl_TstRsltType  ResultTmp;


  /* Count and clear unexpected SRAM ECC SMU alarms: */
  ResultTmp = SramEccTst_lCountClearUnexpAlm(MemIdx);
  if (SRAMECC_SUCCESS != ResultTmp)
  {
    Result = ResultTmp;
  } /* if (SRAMECC_SUCCESS != ResultTmp) */
  else
  {
    /* If SRAM under test is LMU (DAM) SRAM, also check that LMU ECC
     * Online Monitor Error SMU alarm is not already set:
     */
    Result = SRAMECC_SUCCESS;
      
    if (SRAM_DAM == MemIdx)
    {
      Std_ReturnType  SmuResult;
      uint32          AlarmStatus;	
      SmuResult = Smu_GetAlarmStatus(SramEccTst_kMemDef[MemIdx]->
                                     SmuAlarmGrp,
                                     &AlarmStatus);
      if (E_OK != SmuResult)
      {
        Result = SRAMECC_SMU_GETALMSTSERR;
      } /* if (E_OK != SmuResult) */
      else
      {
        if ((AlarmStatus & ((uint32)1U << SMU_ALARM_15)) > 0U)
        {
          Result = SRAMECC_SMU_ALMSTSERR;
        } /* if ((AlarmStatus & (1U << SMU_ALARM_15)) > 0U) */
        else
        {
          Result = SRAMECC_SUCCESS;
        } /* if ((AlarmStatus & (1U << SMU_ALARM_15)) == 0U) */
      } /* if (E_OK == SmuResult) */
    } /* if (SRAM_DAM == MemIdx) */

  } /* if (SRAMECC_SUCCESS == ResultTmp) */

  return Result;
} /* SramEccTst_lCheckSmuAlarms */


#if (CHIP_ID == 26U) || (CHIP_ID == 27U) || (CHIP_ID == 29U)
/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static Sl_TstRsltType SramEccTst_lSetupSramClock        **
**                       (const uint8 MemIdx,                                 **
**                        SramEccTst_BackupDataType* const BackupData)        **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : MemIdx - Index of the memory under test; Refer to       **
**                             definition of supported SRAMs in               **
**                             SramEccTst_MemDef.h for a list of supported    **
**                             values                                         **
**                                                                            **
** Parameters (out) : BackupData - Pointer to backup structure that will      **
**                                 receive current clock settings             **
**                                                                            **
** Return value     : SRAMECC_SUCCESS - SRAM clock setup succeeded            **
**                    <Error ID> - Type of error during SRAM clock setup      **
**                                                                            **
** Description      : This function configures the clock driving the SRAM     **
**                    under test to a predefined value. This is done to have  **
**                    a predefined duration of the MBIST read / write         **
**                    operations used during the test. The clock is set to    **
**                    the highest value possible with current PLL settings.   **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType SramEccTst_lSetupSramClock
(
  const uint8 MemIdx,
  SramEccTst_BackupDataType* const BackupData
)
{
  Sl_TstRsltType Result = SRAMECC_NOTEXECUTED;

  switch(MemIdx)
  {
    #if ( MCAL_NO_OF_CORES > 1U )
    #if ( MCAL_NO_OF_CORES > 2U )
    case SRAM_CPU2_DSPR:
    case SRAM_CPU2_DSPR2:
    case SRAM_CPU2_DTAG:
    case SRAM_CPU2_PSPR:
    case SRAM_CPU2_PTAG:
      /* Set CPU clock divider of the CPU SRAM under test to the same value
       * as the executing CPU:
       */
      Result = SramEccTst_lSetupCpuClockDiv(SRAM_CPU_CORE2, BackupData);
      break;
    #endif /* ( MCAL_NO_OF_CORES > 2U ) */

    case SRAM_CPU1_DSPR:
    case SRAM_CPU1_DSPR2:
    case SRAM_CPU1_DTAG:
    case SRAM_CPU1_PSPR0:
    case SRAM_CPU1_PTAG:
      /* Set CPU clock divider of the CPU SRAM under test to the same value
       * as the executing CPU:
       */
      Result = SramEccTst_lSetupCpuClockDiv(SRAM_CPU_CORE1, BackupData);
      break;
    #endif /* ( MCAL_NO_OF_CORES > 1U ) */

    case SRAM_CPU0_DSPR:
    case SRAM_CPU0_PSPR:
    case SRAM_CPU0_PTAG:
    case SRAM_CPU0_DTAG:
      /* Set CPU clock divider of the CPU SRAM under test to the same value
       * as the executing CPU:
       */
      Result = SramEccTst_lSetupCpuClockDiv(SRAM_CPU_CORE0, BackupData);
      break;

    case SRAM_DAM:
      /* Nothing to do */
      Result = SRAMECC_SUCCESS;
      break;

    default:
      Result = SRAMECC_INVPARAMERR;
      break;
  } /* switch(MemIdx) */

  return Result;
} /* SramEccTst_lSetupSramClock */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static Sl_TstRsltType SramEccTst_lRestoreSramClock      **
**                       (const uint8 MemIdx,                                 **
**                        const SramEccTst_BackupDataType* const BackupData)  **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : MemIdx - Index of the memory under test; Refer to       **
**                             definition of supported SRAMs in               **
**                             SramEccTst_MemDef.h for a list of supported    **
**                             values                                         **
**                    BackupData - Pointer to backup structure that contains  **
**                                 the original clock settings as they were   **
**                                 before SramEccTst_lSetupSramClock was      **
**                                 called                                     **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : SRAMECC_SUCCESS - SRAM clock restoration succeeded      **
**                    <Error ID> - Type of error during SRAM clock            **
**                                 restoration                                **
**                                                                            **
** Description      : This function restores the clock settings of the SRAM   **
**                    under test to their original values.                    **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType SramEccTst_lRestoreSramClock
(
  const uint8 MemIdx,
  const SramEccTst_BackupDataType* const BackupData
)
{
  Sl_TstRsltType Result = SRAMECC_NOTEXECUTED;

  switch(MemIdx)
  {
    #if ( MCAL_NO_OF_CORES > 1U )
    #if ( MCAL_NO_OF_CORES > 2U )
    case SRAM_CPU2_DSPR:
    case SRAM_CPU2_DSPR2:
    case SRAM_CPU2_DTAG:
    case SRAM_CPU2_PSPR:
    case SRAM_CPU2_PTAG:
      /* Restore CPU0 clock: */
      SramEccTst_lRestoreCpuClockDiv(SRAM_CPU_CORE2, BackupData);
      Result = SRAMECC_SUCCESS;
      break;
    #endif /* ( MCAL_NO_OF_CORES > 2U ) */

    case SRAM_CPU1_DSPR:
    case SRAM_CPU1_DSPR2:
    case SRAM_CPU1_DTAG:
    case SRAM_CPU1_PSPR0:
    case SRAM_CPU1_PTAG:
      /* Restore CPU1 clock: */
      SramEccTst_lRestoreCpuClockDiv(SRAM_CPU_CORE1, BackupData);
      Result = SRAMECC_SUCCESS;
      break;
    #endif /* ( MCAL_NO_OF_CORES > 1U ) */

    case SRAM_CPU0_DSPR:
    case SRAM_CPU0_PSPR:
    case SRAM_CPU0_PTAG:
    case SRAM_CPU0_DTAG:
      /* Restore CPU2 clock: */
      SramEccTst_lRestoreCpuClockDiv(SRAM_CPU_CORE0, BackupData);
      Result = SRAMECC_SUCCESS;
      break;

    case SRAM_DAM:
      /* Nothing to do */
      Result = SRAMECC_SUCCESS;
      break;

    default:
      Result = SRAMECC_INVPARAMERR;
      break;
  }

  return Result;
} /* SramEccTst_lRestoreSramClock */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static Sl_TstRsltType SramEccTst_lSetupCpuClockDiv      **
**                       (const uint8 TargetCoreId,                           **
**                        SramEccTst_BackupDataType* const BackupData)        **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : TargetCoreId - CPU core ID of which to change the clock **
**                                   divider; Range 0..SRAM_NO_OF_CORES - 1   **
**                                   Values:  0 - CPU0                        **
**                                            1 - CPU1                        **
**                                            2 - CPU2                        **
**                                                                            **
** Parameters (out) : BackupData - Pointer to backup structure that will      **
**                                 receive current clock settings             **
**                                                                            **
** Return value     : SRAMECC_SUCCESS - CPU clock divider setup succeeded     **
**                    SRAMECC_CONSISTENCYERR - CPU_CORE_ID.CORE_ID CSFR held  **
**                                             an invalid value               **
**                    SRAMECC_NOTEXECUTED - Program flow error, this value    **
**                                          should never be returned          **
**                                                                            **
** Description      : This function sets the clock divider of a given CPU     **
**                    core to the same value as the clock divider of the      **
**                    executing CPU core. Nothing is done if both CPU cores   **
**                    are identical.                                          **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType SramEccTst_lSetupCpuClockDiv
(
  const uint8 TargetCoreId,
  SramEccTst_BackupDataType* const BackupData
)
{
  Ifx_CPU_CORE_ID CoreId;
  volatile uint8           ExecutingCoreId;
  Sl_TstRsltType  Result = SRAMECC_NOTEXECUTED;

  /* Table of CCUCON registers containing the clock dividers for the CPU cores:
   */

  volatile uint32* CcuConReg[] =
  {
    (volatile uint32*)(volatile void*)&SCU_CCUCON6,
#if ( MCAL_NO_OF_CORES > 1U )  
    (volatile uint32*)(volatile void*)&SCU_CCUCON7,
#if ( MCAL_NO_OF_CORES > 2U )  
    (volatile uint32*)(volatile void*)&SCU_CCUCON8
#endif /* MCAL_NO_OF_CORES > 1U */
#endif /* MCAL_NO_OF_CORES > 2U */
  };
  /* Get core ID of executing CPU: */
  CoreId.U = (uint32)MFCR(CPU_CORE_ID);
  ExecutingCoreId = (uint8)CoreId.B.CORE_ID;
  if (ExecutingCoreId >= MCAL_NO_OF_CORES)
  {
    Result = SRAMECC_CONSISTENCYERR;
  } /* if (ExecutingCoreId >= SRAM_NO_OF_CORES) */
  else
  {
    /* Nothing to do if SRAM of executing CPU is to be tested: */
    if(ExecutingCoreId != TargetCoreId)
    {
      /* Backup CCUCONx of target CPU: */
      BackupData->ClockBackup1 = *CcuConReg[TargetCoreId];

      /* Set CPUxDIV clock divider of target CPU to the same value as the one
       * of the executing CPU:
       */
    Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT); 
      *CcuConReg[TargetCoreId] = *CcuConReg[ExecutingCoreId];
    Mcal_SetSafetyENDINIT_Timed();
    Result = SRAMECC_SUCCESS;
    } /* if (ExecutingCoreId != TargetCoreId) */
    else
    {
      Result = SRAMECC_CONSISTENCYERR;  
    }

  } /* if (ExecutingCoreId < MCAL_NO_OF_CORES) */

  return Result;
} /* SramEccTst_lSetupCpuClockDiv */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static void SramEccTst_lRestoreCpuClockDiv              **
**                       (const uint8 TargetCoreId,                           **
**                        const SramEccTst_BackupDataType* const BackupData)  **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : TargetCoreId - CPU core ID of which to restore the      **
**                                   clock divider                            **
**                    BackupData - Pointer to backup structure that contains  **
**                                 the original clock settings as they were   **
**                                 before SramEccTst_lSetupCpuClockDiv was    **
**                                 called                                     **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function restores the clock divider of a given CPU **
**                    core.                                                   **
**                                                                            **
*******************************************************************************/
static void SramEccTst_lRestoreCpuClockDiv
(
  const uint8 TargetCoreId,
  const SramEccTst_BackupDataType* const BackupData
)
{
  volatile uint32* CcuConReg[] =
  {
    (volatile uint32*)(volatile void*)&SCU_CCUCON6,
#if ( MCAL_NO_OF_CORES > 1U )  
    (volatile uint32*)(volatile void*)&SCU_CCUCON7,
#if ( MCAL_NO_OF_CORES > 2U )  
    (volatile uint32*)(volatile void*)&SCU_CCUCON8
#endif /* MCAL_NO_OF_CORES > 1U */
#endif /* MCAL_NO_OF_CORES > 2U */
  };

  /* Only restore SRAM clock if it has been changed: */
  if (SRAM_INV_BACKUP_VALUE != BackupData->ClockBackup1)
  {
    /* Restore CCUCONx of target CPU: */
    Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT); 
    *CcuConReg[TargetCoreId] = BackupData->ClockBackup1;
    Mcal_SetSafetyENDINIT_Timed();
  } /* if (SRAM_INV_BACKUP_VALUE != BackupData->ClockBackup1) */
} /* SramEccTst_lRestoreCpuClockDiv */
#endif /* (CHIP_ID == 26U) || (CHIP_ID == 27U) || (CHIP_ID == 29U) */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static uint8 SramEccTst_lCalcRdbflRegCount              **
**                       (const uint8 MemIdx)                                 **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : MemIdx - Memory for which to create the pattern; Refer  **
**                             to definition of supported SRAMs in            **
**                             SramEccTst_MemDef.h for a list of supported    **
**                             values                                         **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : Number of MCx_RDBFLy registers implemented for the      **
**                    given memory                                            **
**                                                                            **
** Description      : Calculates the number of MCx_RDBFLy registers           **
**                    implemented for a given memory                          **
**                                                                            **
*******************************************************************************/
static uint8 SramEccTst_lCalcRdbflRegCount
(
  const uint8 MemIdx
)
{
  uint16 Result;

  Result = ((uint16)SramEccTst_kMemDef[MemIdx]->NrOfDataBits +
            (uint16)SramEccTst_kMemDef[MemIdx]->NrOfEccBits) *
           ((uint16)SramEccTst_kMemDef[MemIdx]->NrOfMemBlocks *
            (uint16)SramEccTst_kMemDef[MemIdx]->NrOfMultiplexers);
  Result += (SRAM_RDBFL_REG_WIDTH - 1U);  /* Round up */
  Result /= SRAM_RDBFL_REG_WIDTH;

  return (uint8)Result;
} /* SramEccTst_lCalcRdbflRegCount */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static void SramEccTst_lCreateZeroPattern               **
**                       (const uint8 MemIdx)                                 **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : MemIdx - Memory for which to create the pattern; Refer  **
**                             to definition of supported SRAMs in            **
**                             SramEccTst_MemDef.h for a list of supported    **
**                             values                                         **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : Writes a pattern of all data bits = 0 and correct ECC   **
**                    bits to the RDBFL registers of a given memory           **
**                                                                            **
*******************************************************************************/
static void SramEccTst_lCreateZeroPattern
(
  const uint8 MemIdx
)
{
  uint8           i;
  uint8           RdbflRegCount;
  uint8           RdbflRegIdx;
  uint8           RdbflBitIdx;
  uint16          BitIdx;
  Ifx_MC*         Mc;

  /* Get number of RDBFL registers: */
  RdbflRegCount = SramEccTst_lCalcRdbflRegCount(MemIdx);

  /* Get pointer to memory controller SFRs of RAM under test: */
  Mc = SramEccTst_lGetMc(MemIdx);

  /* Initialize MCx_RDBFLy registers to zero: */
  for (i = 0U; i < RdbflRegCount; i++)
  {
    Mc->RDBFL[i].U = (uint16)0U;
  } /* for (i = 0U; i < RdbflRegCount; i++) */

  /* Create check bits for each data word: */
  for (i = 0U; i < (SramEccTst_kMemDef[MemIdx]->NrOfMemBlocks *
                    SramEccTst_kMemDef[MemIdx]->NrOfMultiplexers); i++)
  {
    /* Get absolute bit index of first ECC bit: */
    BitIdx = ((uint16)SramEccTst_kMemDef[MemIdx]->NrOfDataBits +
              (uint16)SramEccTst_kMemDef[MemIdx]->NrOfEccBits) * (uint16)i;
    BitIdx += (uint16)SramEccTst_kMemDef[MemIdx]->NrOfDataBits;
    BitIdx += (uint16)SramEccTst_kMemDef[MemIdx]->EccInvPos0;

    /* Get RDBFL register */
    RdbflRegIdx = (uint8)(BitIdx / SRAM_RDBFL_REG_WIDTH);
    /* Get bit index. Modulo operation done through & operation */
    RdbflBitIdx = (uint8)(BitIdx & ((uint16)SRAM_RDBFL_REG_WIDTH - (uint16)1U));

    /* Set first ECC bit: */
    Mc->RDBFL[RdbflRegIdx].U |= (uint16)((uint32)1U << RdbflBitIdx);

    /* Get second register and bit index: */
    BitIdx -= (uint16)SramEccTst_kMemDef[MemIdx]->EccInvPos0;
    BitIdx += (uint16)SramEccTst_kMemDef[MemIdx]->EccInvPos1;
    RdbflRegIdx = (uint8)(BitIdx / SRAM_RDBFL_REG_WIDTH);
    RdbflBitIdx = (uint8)(BitIdx & ((uint16)SRAM_RDBFL_REG_WIDTH - (uint16)1U));

    /* Set second ECC bit: */
    Mc->RDBFL[RdbflRegIdx].U |= (uint16)((uint32)1U << RdbflBitIdx);
  } /* for (i = 0U; i < SramEccTst_kMemDef[MemIdx]->NrOfMemBlocks *
                        SramEccTst_kMemDef[MemIdx]->NrOfMultiplexers; i++) */
} /* SramEccTst_lCreateZeroPattern */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : LOCAL_INLINE void SramEccTst_lFlipBits                  **
**                       (const uint8 MemIdx,                                 **
**                        const uint8 WordIdx,                                **
**                        const uint8 BitIdx,                                 **
**                        const uint8 BitCount)                               **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : MemIdx - Memory for which to flip bits; Refer to        **
**                             definition of supported SRAMs in               **
**                             SramEccTst_MemDef.h for a list of supported    **
**                             values                                         **
**                    WordIdx - Index of data word within the wordline        **
**                    BitIdx - Index of first bit to flip within the data     **
**                             word                                           **
**                    BitCount - Number of bits to flip                       **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : Flips a given number of bits of a data word in the      **
**                    RDBFL registers of a given memory                       **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE void SramEccTst_lFlipBits
(
  const uint8 MemIdx,
  const uint8 WordIdx,
  const uint8 BitIdx,
  const uint8 BitCount
)
{
  uint8   i;
  uint8   RdbflRegIdx;
  uint16  RdbflBitIdx;
  uint16  AbsBitIdx;
  Ifx_MC* Mc;

  /* Get pointer to memory controller SFRs of RAM under test: */
  Mc = SramEccTst_lGetMc(MemIdx);

  /* Get the absolute bit index of the first bit of the selected data word: */
  AbsBitIdx = ((uint16)SramEccTst_kMemDef[MemIdx]->NrOfDataBits +
               (uint16)SramEccTst_kMemDef[MemIdx]->NrOfEccBits) *
              (uint16)WordIdx;
  AbsBitIdx += BitIdx;

  /* Get RDBFL register */
  RdbflRegIdx = (uint8)(AbsBitIdx / (uint16)SRAM_RDBFL_REG_WIDTH);
  /* Get bit index. Modulo operation done through & operation */
  RdbflBitIdx = (AbsBitIdx & ((uint16)SRAM_RDBFL_REG_WIDTH - (uint16)1U));

  /* Flip bits: */
  for (i = 0U; i < BitCount; i++)
  {
    Mc->RDBFL[RdbflRegIdx].U ^= (uint16)((uint32)1U << RdbflBitIdx);
    RdbflBitIdx++;
    if (RdbflBitIdx == SRAM_RDBFL_REG_WIDTH)
	/* polyspace<RTE:UNR:LOW:No action planned> executed in case of invalid parameter */
    {
      RdbflRegIdx++;
      RdbflBitIdx = 0U;
    } /* if (RdbflBitIdx == SRAM_RDBFL_REG_WIDTH) */
  } /* for (i = 0U; i < BitCount; i++) */
} /* SramEccTst_lFlipBits */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static void SramEccTst_lReadWordline                    **
**                       (const uint8 MemIdx,                                 **
**                        const uint16 WordlineIdx)                           **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : MemIdx - Memory from which to read; Refer to            **
**                             definition of supported SRAMs in               **
**                             SramEccTst_MemDef.h for a list of supported    **
**                             values                                         **
**                    WordlineIdx - Memory address to read                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : Reads a single memory location to RDBFL registers       **
**                                                                            **
*******************************************************************************/
static void SramEccTst_lReadWordline
(
  const uint8 MemIdx,
  const uint16 WordlineIdx
)
{
  Ifx_MC*                   Mc;
  SramEccTst_WdtContextType WdtContext;

  /* Get pointer to memory controller SFRs of RAM under test: */
  Mc = SramEccTst_lGetMc(MemIdx);

  /* Select address */
  Mc->RANGE.U = (WordlineIdx & (uint16)IFX_MC_RANGE_ADDR_MSK);

  /* Configure reading of single memory address: */
  Mc->CONFIG0.U = (uint16)(((uint32)SRAM_CONFIG0_NUMACCS_1 <<
                            (uint32)IFX_MC_CONFIG0_NUMACCS_OFF) |
                           ((uint32)SRAM_CONFIG0_ACCSTYPE_RD <<
                            (uint32)IFX_MC_CONFIG0_ACCSTYPE_OFF));
  Mc->CONFIG1.U = 0U;

  /* Start read operation: */
  SramEccTst_lResetSafetyENDINIT(&WdtContext);

  Mc->MCONTROL.U = (uint16)(((uint32)IFX_MC_MCONTROL_DIR_MSK <<
                             (uint32)IFX_MC_MCONTROL_DIR_OFF) |
                            ((uint32)IFX_MC_MCONTROL_START_MSK <<
                             (uint32)IFX_MC_MCONTROL_START_OFF)|
                            ((uint32)MC_MCONTROL_USERED_MSK <<
                             (uint32)MC_MCONTROL_USERED));
  Mc->MCONTROL.U = (uint16)(((uint32)IFX_MC_MCONTROL_DIR_MSK <<
                            (uint32)IFX_MC_MCONTROL_DIR_OFF)|
                            ((uint32)MC_MCONTROL_USERED_MSK <<
                             (uint32)MC_MCONTROL_USERED));
  SramEccTst_lSetSafetyENDINIT(&WdtContext);
} /* SramEccTst_lReadWordline */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static Sl_TstRsltType SramEccTst_lReadWordlineSafe      **
**                       (const uint8 MemIdx,                                 **
**                        const uint16 WordlineIdx)                           **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : MemIdx - Memory from which to read; Refer to            **
**                             definition of supported SRAMs in               **
**                             SramEccTst_MemDef.h for a list of supported    **
**                             values                                         **
**                    WordlineIdx - Memory address to read                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : SRAM_SUCCESS - Single memory read succeeded             **
**                    SRAMECC_MBIST_RWOPTIMEOUT - Waiting for read operation  **
**                                                to complete timed out       **
**                    SRAMECC_MBIST_RWOPFAIL - Failed to start MBIST single   **
**                                             memory read operation          **
**                    SRAMECC_NOTEXECUTED - Program flow consistency error    **
**                                                                            **
** Description      : Reads a single memory location to RDBFL registers and   **
**                    checks for success of the read operation by evaluating  **
**                    MCx_MSTATUS.DONE.                                       **
**                                                                            **
** Note:            : This function must not be used for devices with         **
**                    functional deviation MTU_TC.008!                        **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType SramEccTst_lReadWordlineSafe
(
  const uint8 MemIdx,
  const uint16 WordlineIdx
)
{
  Ifx_MC*                   Mc;
  SramEccTst_WdtContextType WdtContext;
  Sl_TstRsltType            Result = SRAMECC_NOTEXECUTED;

  /* Get pointer to memory controller SFRs of RAM under test: */
  Mc = SramEccTst_lGetMc(MemIdx);

  /* Select address */
  Mc->RANGE.U = (WordlineIdx & (uint16)IFX_MC_RANGE_ADDR_MSK);

  /* Configure reading of single memory address: */
  Mc->CONFIG0.U = (uint16)(((uint32)SRAM_CONFIG0_NUMACCS_1 <<
                            (uint32)IFX_MC_CONFIG0_NUMACCS_OFF) |
                           ((uint32)SRAM_CONFIG0_ACCSTYPE_RD <<
                            (uint32)IFX_MC_CONFIG0_ACCSTYPE_OFF));
  Mc->CONFIG1.U = 0U;

  /* Start read operation: */
  SramEccTst_lResetSafetyENDINIT(&WdtContext);

  Mc->MCONTROL.U = (uint16)(((uint32)IFX_MC_MCONTROL_DIR_MSK <<
                             (uint32)IFX_MC_MCONTROL_DIR_OFF) |
                            ((uint32)IFX_MC_MCONTROL_START_MSK <<
                             (uint32)IFX_MC_MCONTROL_START_OFF)|
                            ((uint32)MC_MCONTROL_USERED_MSK <<
                             (uint32)MC_MCONTROL_USERED));

  /* MSTATUS.DONE = 0 indicates, that the read operation was successfully
   * started:
   */
  if ((Mc->MSTATUS.U & (uint16)(((uint32)IFX_MC_MSTATUS_DONE_MSK <<
                                (uint32)IFX_MC_MSTATUS_DONE_OFF))) > (uint16)0U)
  {
    Result = SRAMECC_MBIST_RWOPFAIL;
  } /* if ((Mc->MSTATUS.U & (uint16)(((uint32)IFX_MC_MSTATUS_DONE_MSK <<
                             (uint32)IFX_MC_MSTATUS_DONE_OFF))) > (uint16)0U) */

  /* Revoke MSTATUS.START: */
  Mc->MCONTROL.U = (uint16)(((uint32)IFX_MC_MCONTROL_DIR_MSK <<
                            (uint32)IFX_MC_MCONTROL_DIR_OFF)|
                            ((uint32)MC_MCONTROL_USERED_MSK <<
                             (uint32)MC_MCONTROL_USERED));
  SramEccTst_lSetSafetyENDINIT(&WdtContext);

  /* Check if read operation completed: */
  if ((Mc->MSTATUS.U & (uint16)(((uint32)IFX_MC_MSTATUS_DONE_MSK <<
                               (uint32)IFX_MC_MSTATUS_DONE_OFF))) == (uint16)0U)
  {
    Result = SRAMECC_MBIST_RWOPTIMEOUT;
  } /* if ((Mc->MSTATUS.U & (uint16)(((uint32)IFX_MC_MSTATUS_DONE_MSK <<
                            (uint32)IFX_MC_MSTATUS_DONE_OFF))) == (uint16)0U) */
  else
  {
    if (SRAMECC_NOTEXECUTED == Result)
    {
      Result = SRAMECC_SUCCESS;
    } /* if (SRAMECC_NOTEXECUTED == Result) */
  } /* if ((MSTATUS.U & (uint16)(((uint32)IFX_MC_MSTATUS_DONE_MSK <<
                            (uint32)IFX_MC_MSTATUS_DONE_OFF))) != (uint16)0U) */

  return Result;
} /* SramEccTst_lReadWordlineSafe */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static void SramEccTst_lWriteWordline                   **
**                       (const uint8 MemIdx,                                 **
**                        const uint16 WordlineIdx)                           **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : MemIdx - Memory to which to write; Refer to             **
**                             definition of supported SRAMs in               **
**                             SramEccTst_MemDef.h for a list of supported    **
**                             values                                         **
**                    WordlineIdx - Memory address to write                   **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : Writes the RDBFL registers to a single memory location  **
**                                                                            **
*******************************************************************************/
static void SramEccTst_lWriteWordline
(
  const uint8 MemIdx,
  const uint16 WordlineIdx
)
{
  Ifx_MC*                   Mc;
  SramEccTst_WdtContextType WdtContext;

  /* Get pointer to memory controller SFRs of RAM under test: */
  Mc = SramEccTst_lGetMc(MemIdx);

  /* Select address */
  Mc->RANGE.U = (WordlineIdx & (uint16)IFX_MC_RANGE_ADDR_MSK);

  /* Configure writing of single memory address: */
  Mc->CONFIG0.U = (uint16)(((uint32)SRAM_CONFIG0_NUMACCS_1 <<
                            (uint32)IFX_MC_CONFIG0_NUMACCS_OFF) |
                           ((uint32)SRAM_CONFIG0_ACCSTYPE_WR <<
                            (uint32)IFX_MC_CONFIG0_ACCSTYPE_OFF));
  Mc->CONFIG1.U = 0U;

  /* Start write operation: */
  SramEccTst_lResetSafetyENDINIT(&WdtContext);
  Mc->MCONTROL.U = (uint16)(((uint32)IFX_MC_MCONTROL_DIR_MSK <<
                             (uint32)IFX_MC_MCONTROL_DIR_OFF) |
                            ((uint32)IFX_MC_MCONTROL_START_MSK <<
                             (uint32)IFX_MC_MCONTROL_START_OFF)|
                             ((uint32)MC_MCONTROL_USERED_MSK <<
                             (uint32)MC_MCONTROL_USERED));
  Mc->MCONTROL.U = (uint16)(((uint32)IFX_MC_MCONTROL_DIR_MSK <<
                            (uint32)IFX_MC_MCONTROL_DIR_OFF)|
                            ((uint32)MC_MCONTROL_USERED_MSK <<
                             (uint32)MC_MCONTROL_USERED));

  SramEccTst_lSetSafetyENDINIT(&WdtContext);
} /* SramEccTst_lWriteWordline */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static Sl_TstRsltType SramEccTst_lWriteWordlineSafe     **
**                       (const uint8 MemIdx,                                 **
**                        const uint16 WordlineIdx)                           **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : MemIdx - Memory to which to write; Refer to             **
**                             definition of supported SRAMs in               **
**                             SramEccTst_MemDef.h for a list of supported    **
**                             values                                         **
**                    WordlineIdx - Memory address to write                   **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : SRAM_SUCCESS - Single memory write succeeded            **
**                    SRAMECC_MBIST_RWOPTIMEOUT - Waiting for write operation **
**                                                to complete timed out       **
**                    SRAMECC_MBIST_RWOPFAIL - Failed to start MBIST single   **
**                                             memory write operation         **
**                    SRAMECC_NOTEXECUTED - Program flow consistency error    **
**                                                                            **
** Description      : Writes the RDBFL registers to a single memory location  **
**                    and checks for success by evaluating MCx_MSTATUS.DONE.  **
**                                                                            **
** Note:            : This function must not be used for devices with         **
**                    functional deviation MTU_TC.008!                        **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType SramEccTst_lWriteWordlineSafe
(
  const uint8 MemIdx,
  const uint16 WordlineIdx
)
{
  Ifx_MC*                   Mc;
  SramEccTst_WdtContextType WdtContext;
  Sl_TstRsltType            Result = SRAMECC_NOTEXECUTED;

  /* Get pointer to memory controller SFRs of RAM under test: */
  Mc = SramEccTst_lGetMc(MemIdx);

  /* Select address */
  Mc->RANGE.U = (WordlineIdx & (uint16)IFX_MC_RANGE_ADDR_MSK);

  /* Configure writing of single memory address: */
  Mc->CONFIG0.U = (uint16)(((uint32)SRAM_CONFIG0_NUMACCS_1 <<
                            (uint32)IFX_MC_CONFIG0_NUMACCS_OFF) |
                           ((uint32)SRAM_CONFIG0_ACCSTYPE_WR <<
                            (uint32)IFX_MC_CONFIG0_ACCSTYPE_OFF));
  Mc->CONFIG1.U = 0U;

  /* Start write operation: */
  SramEccTst_lResetSafetyENDINIT(&WdtContext);
  Mc->MCONTROL.U = (uint16)(((uint32)IFX_MC_MCONTROL_DIR_MSK <<
                             (uint32)IFX_MC_MCONTROL_DIR_OFF) |
                            ((uint32)IFX_MC_MCONTROL_START_MSK <<
                             (uint32)IFX_MC_MCONTROL_START_OFF)|
                             ((uint32)MC_MCONTROL_USERED_MSK <<
                             (uint32)MC_MCONTROL_USERED));

  /* MSTATUS.DONE = 0 indicates, that the read operation was successfully
   * started:
   */
  if ((Mc->MSTATUS.U & (uint16)(((uint32)IFX_MC_MSTATUS_DONE_MSK <<
                                (uint32)IFX_MC_MSTATUS_DONE_OFF))) > (uint16)0U)
  {
    Result = SRAMECC_MBIST_RWOPFAIL;
  } /* if ((Mc->MSTATUS.U & (uint16)(((uint32)IFX_MC_MSTATUS_DONE_MSK <<
                             (uint32)IFX_MC_MSTATUS_DONE_OFF))) > (uint16)0U) */

  /* Revoke MSTATUS.START: */
  Mc->MCONTROL.U = (uint16)(((uint32)IFX_MC_MCONTROL_DIR_MSK <<
                            (uint32)IFX_MC_MCONTROL_DIR_OFF)|
                            ((uint32)MC_MCONTROL_USERED_MSK <<
                             (uint32)MC_MCONTROL_USERED));

  SramEccTst_lSetSafetyENDINIT(&WdtContext);

  /* Check if write operation completed: */
  if ((Mc->MSTATUS.U & (uint16)(((uint32)IFX_MC_MSTATUS_DONE_MSK <<
                               (uint32)IFX_MC_MSTATUS_DONE_OFF))) == (uint16)0U)
  {
    Result = SRAMECC_MBIST_RWOPTIMEOUT;
  } /* if ((Mc->MSTATUS.U & (uint16)(((uint32)IFX_MC_MSTATUS_DONE_MSK <<
                            (uint32)IFX_MC_MSTATUS_DONE_OFF))) == (uint16)0U) */
  else
  {
    if (SRAMECC_NOTEXECUTED == Result)
    {
      Result = SRAMECC_SUCCESS;
    } /* if (SRAMECC_NOTEXECUTED == Result) */
  } /* if ((MSTATUS.U & (uint16)(((uint32)IFX_MC_MSTATUS_DONE_MSK <<
                            (uint32)IFX_MC_MSTATUS_DONE_OFF))) != (uint16)0U) */

  return Result;
} /* SramEccTst_lWriteWordlineSafe */

#if (CHIP_ID == 26U) || (CHIP_ID == 27U) || (CHIP_ID == 29U)
/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static void SramEccTst_lClearSram                       **
**                    (                                                       **
**                      const uint8 MemIdx,                                   **
**                      const uint16 Range,                                   **
**                      const uint16 Delay                                    **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : MemIdx - Memory that is to be cleared; Refer to         **
**                             definition of supported SRAMs in               **
**                             SramEccTst_MemDef.h for a list of supported    **
**                             values                                         **
**                    Range - Memory range to clear, encoding according to    **
**                            MCx_RANGE register                              **
**                    Delay - Delay to wait for the completion of the memory  **
**                            fill operation in loop cycles                   **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function fills a given memory range with all zero  **
**                    data and valid ECC bits.                                **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType SramEccTst_lClearSram
(
  const uint8 MemIdx,
  const uint16 Range,
  const uint16 Delay
)
{
  Ifx_MC*                   Mc;
  SramEccTst_WdtContextType WdtContext;
  volatile uint16           DelayCounter;
  Sl_TstRsltType            Result = SRAMECC_NOTEXECUTED;

  /* Get pointer to memory controller SFRs of RAM under test: */
  Mc = SramEccTst_lGetMc(MemIdx);

  /* Fill RDBFL registers with all zero data but valid ECC: */
  SramEccTst_lCreateZeroPattern(MemIdx);

  /* Select address */
  Mc->RANGE.U = Range;

  /* Start write operation: */
  SramEccTst_lResetSafetyENDINIT(&WdtContext);
  Mc->MCONTROL.U = (uint16)(((uint32)IFX_MC_MCONTROL_DINIT_MSK <<
                             (uint32)IFX_MC_MCONTROL_DINIT_OFF) |
                            ((uint32)IFX_MC_MCONTROL_DIR_MSK <<
                             (uint32)IFX_MC_MCONTROL_DIR_OFF) |
                            ((uint32)IFX_MC_MCONTROL_START_MSK <<
                             (uint32)IFX_MC_MCONTROL_START_OFF)|
                             ((uint32)MC_MCONTROL_USERED_MSK <<
                             (uint32)MC_MCONTROL_USERED));
  Mc->MCONTROL.U = (uint16)(((uint32)IFX_MC_MCONTROL_DINIT_MSK <<
                             (uint32)IFX_MC_MCONTROL_DINIT_OFF) |
                            ((uint32)IFX_MC_MCONTROL_DIR_MSK <<
                             (uint32)IFX_MC_MCONTROL_DIR_OFF)|
                            ((uint32)MC_MCONTROL_USERED_MSK <<
                             (uint32)MC_MCONTROL_USERED));
  SramEccTst_lSetSafetyENDINIT(&WdtContext);

  /* Delay while memory fill operation is in progress: */
  DelayCounter = Delay;
  do
  {
    DelayCounter--;
  } while (DelayCounter > (uint16)0U);

  /* Check for end of fill operation: */
  if ((Mc->MSTATUS.U & (uint16)((uint32)IFX_MC_MSTATUS_DONE_MSK <<
                                (uint32)IFX_MC_MSTATUS_DONE_OFF)) > 0U)
  {
    Result = SRAMECC_SUCCESS;
  } /* if ((Mc->MSTATUS.U & (uint16)((uint32)IFX_MC_MSTATUS_DONE_MSK <<
                                     (uint32)IFX_MC_MSTATUS_DONE_OFF)) > 0U) */
  else
  {
    Result = SRAMECC_MBIST_RWOPTIMEOUT;
  } /* if ((Mc->MSTATUS.U & (uint16)((uint32)IFX_MC_MSTATUS_DONE_MSK <<
                                     (uint32)IFX_MC_MSTATUS_DONE_OFF)) == 0U) */

  return Result;
} /* SramEccTst_lClearSram */
#endif /* (CHIP_ID == 26) || (CHIP_ID == 27) || (CHIP_ID == 29) */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static Sl_TstRsltType SramEccTst_lCheckEccLogic         **
**                       (const uint8 MemIdx,                                 **
**                        uint32* const TstSignature)                         **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : MemIdx - Index of the memory under test; Refer to       **
**                             definition of supported SRAMs in               **
**                             SramEccTst_MemDef.h for a list of supported    **
**                             values                                         **
**                                                                            **
** Parameters (out) : TstSignature - will receive the updated program flow    **
**                                   monitoring signature                     **
**                                                                            **
** Return value     : SRAM_SUCCESS - ECC logic test succeeded                 **
**                    <Error ID> - Type of error during ECC logic test        **
**                                                                            **
** Description      : This function tests the correct signaling of ECC errors **
**                    to the SMU. The following error scenarios are checked:  **
**                      -Detection of single bit errors                       **
**                      -Detection of double bit errors                       **
**                      -Detection of address line errors                     **
**                      -Tracking of single and double bit errors             **
**                      -LMU ECC monitor (if memory under test is LMU SRAM)   **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType SramEccTst_lCheckEccLogic
(
  const uint8 MemIdx,
  uint32* const TstSignature
)
{
  Sl_TstRsltType  Result = SRAMECC_NOTEXECUTED;
  Sl_TstRsltType  ResultTmp;
  Std_ReturnType  SmuResult1;
  Std_ReturnType  SmuResult2;
  Ifx_MC*         Mc;

  /* Get pointer to memory controller SFRs of RAM under test: */
  Mc = SramEccTst_lGetMc(MemIdx);

  /* Clear ECCD error flags: */
  Mc->ECCD.U &= ~(uint16)(((uint32)IFX_MC_ECCD_SERR_MSK <<
                           (uint32)IFX_MC_ECCD_SERR_OFF) |
                          ((uint32)IFX_MC_ECCD_CERR_MSK <<
                           (uint32)IFX_MC_ECCD_CERR_OFF) |
                          ((uint32)IFX_MC_ECCD_UERR_MSK <<
                           (uint32)IFX_MC_ECCD_UERR_OFF) |
                          ((uint32)IFX_MC_ECCD_AERR_MSK <<
                           (uint32)IFX_MC_ECCD_AERR_OFF));

  /* Clear error correction and uncorrectable error SMU alarms; these might
   * have been raised during memory backup:
   */
  if (SRAMECCTST_SMU_NONE != SramEccTst_kMemDef[MemIdx]->SmuNr_SbeCorr)
  {
    SmuResult1 = SramEccTst_lSmuClearAlarmStatus(
                    SramEccTst_kMemDef[MemIdx]->SmuAlarmGrp,
                    SramEccTst_kMemDef[MemIdx]->SmuNr_SbeCorr);
  } /* if (SRAMECCTST_SMU_NONE != SramEccTst_kMemDef[MemIdx]->SmuNr_SbeCorr) */
  else
  {
    SmuResult1 = E_OK;
  } /* if (SRAMECCTST_SMU_NONE == SramEccTst_kMemDef[MemIdx]->SmuNr_SbeCorr) */
  SmuResult2 = SramEccTst_lSmuClearAlarmStatus(
                  SramEccTst_kMemDef[MemIdx]->SmuAlarmGrp,
                  SramEccTst_kMemDef[MemIdx]->SmuNr_UcErr);
  if ((E_OK != SmuResult1) || (E_OK != SmuResult2))
  {
    Result = SRAMECC_SMU_CLRALMSTSERR;
  } /* if ((E_OK != SmuResult1) || (E_OK != SmuResult2)) */
  else
  {
    /* Check signaling of address line errors to the SMU: */
    ResultTmp = SramEccTst_lChkAddressMon(MemIdx,
                                          TstSignature);
    if (SRAMECC_SUCCESS != ResultTmp)
    {
      Result = ResultTmp;
    } /* if (SRAMECC_SUCCESS != ResultTmp) */
    else
    {
      /* Check the SRAM monitor: */
      ResultTmp = SramEccTst_lChkSramMon(MemIdx,
                                         TstSignature);
      if (SRAMECC_SUCCESS != ResultTmp)
      {
        Result = ResultTmp;
      } /* if (SRAMECC_SUCCESS != ResultTmp) */
	  #if (CHIP_ID != 21U) && (CHIP_ID != 22U) && (CHIP_ID != 23U) && (CHIP_ID != 24U)
      else if (SRAM_DAM == MemIdx)
      {
        /* Check the LMU ECC online monitor: */
        Result = SramEccTst_lChkLmuOnlnMon(MemIdx, TstSignature);
      } /* if ((SRAMECC_SUCCESS == ResultTmp) &&
               (SRAM_DAM == MemIdx)) */
	 #endif
      else
      {
        Result = SRAMECC_SUCCESS;
      } /* if ((SRAMECC_SUCCESS == ResultTmp) &&
               (SRAM_DAM != MemIdx)) */
    } /* if (SRAMECC_SUCCESS == ResultTmp) */
  } /* if ((E_OK == SmuResult1) && (E_OK == SmuResult2)) */

  return Result;
} /* SramEccTst_lCheckEccLogic */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static Sl_TstRsltType SramEccTst_lChkAddressMon         **
**                       (const uint8 MemIdx,                                 **
**                        uint32* const TstSignature)                         **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : MemIdx - Index of the memory under test; Refer to       **
**                             definition of supported SRAMs in               **
**                             SramEccTst_MemDef.h for a list of supported    **
**                             values                                         **
**                                                                            **
** Parameters (out) : TstSignature : Test signature generated by the test     **
**                                                                            **
** Return value     : SRAM_SUCCESS - Address line ECC error signaling test    **
**                                   succeeded                                **
**                    <Error ID> - Type of error during address line test     **
**                                                                            **
** Description      : This function tests the correct signaling of address    **
**                    line ECC errors to the SMU.                             **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType SramEccTst_lChkAddressMon
(
    const uint8 MemIdx,
    uint32* const TstSignature
)
{
  Sl_TstRsltType            Result = SRAMECC_NOTEXECUTED;
  Sl_TstRsltType            ResultTmp;
  uint8                     i;
  Ifx_MC*                   Mc;
  SramEccTst_WdtContextType WdtContext;

  /* Get pointer to memory controller SFRs of RAM under test: */
  Mc = SramEccTst_lGetMc(MemIdx);

  /* Write valid data to the first and second wordline to avoid correctable and
   * uncorrectable errors during the address error test:
   */
  SramEccTst_lCreateZeroPattern(MemIdx);
  SramEccTst_lWriteWordline(MemIdx, 0U);
  SramEccTst_lWriteWordline(MemIdx, 1U);

  /* Test signaling of address errors: */
  for (i = 0U; (i < SRAM_ADDR_ERR_TEST_COUNT) &&
               (SRAMECC_NOTEXECUTED == Result); i++)
  {
    /* Set signature bit flip enable:
     * i = 0: 1 (bitline)
     * i = 1: 1 (bitline)
     * i = 2: 2 (wordline)
     * i = 3: 2 (wordline)
     */
    SramEccTst_lResetSafetyENDINIT(&WdtContext);
    Mc->ECCS.U &= ~(uint16)((uint32)IFX_MC_ECCS_SFLE_MSK <<
                            (uint32)IFX_MC_ECCS_SFLE_OFF);
    Mc->ECCS.U |= (((uint16)i / (uint16)2U) + (uint16)1U) <<
                  IFX_MC_ECCS_SFLE_OFF;
    SramEccTst_lSetSafetyENDINIT(&WdtContext);

    /* Read memory: */
    SramEccTst_lReadWordline(MemIdx, (uint16)i % (uint16)2U);

    /* Wait for and clear SMU alarm: */
    ResultTmp = SramEccTst_lWaitForSmuAlarm(
        SramEccTst_kMemDef[MemIdx]->SmuAlarmGrp,
        SramEccTst_kMemDef[MemIdx]->SmuNr_AdrErr,
        TstSignature);
    if (SRAMECC_SUCCESS != ResultTmp)
    {
      Result = ResultTmp;
    } /* if (SRAMECC_SUCCESS != ResultTmp) */

    /* Reset signature bit flip enable: */
    SramEccTst_lResetSafetyENDINIT(&WdtContext);
    Mc->ECCS.U &= ~(uint16)((uint32)IFX_MC_ECCS_SFLE_MSK <<
                            (uint32)IFX_MC_ECCS_SFLE_OFF);
    SramEccTst_lSetSafetyENDINIT(&WdtContext);


    /* Clear error flags to allow new alarms being reported: */
    Mc->ECCD.U &= ~(uint16)(((uint32)IFX_MC_ECCD_SERR_MSK <<
                             (uint32)IFX_MC_ECCD_SERR_OFF) |
                            ((uint32)IFX_MC_ECCD_AERR_MSK <<
                             (uint32)IFX_MC_ECCD_AERR_OFF));
  } /* for (i = 0U; (i < SRAM_ADDR_ERR_TEST_COUNT) &&
                    (SRAMECC_NOTEXECUTED == Result); i++) */

  /* Update result: */
  if (SRAMECC_NOTEXECUTED == Result)
  {
    Result = SRAMECC_SUCCESS;
  } /* if (SRAMECC_NOTEXECUTED == Result) */

  return Result;
} /* SramEccTst_lChkAddressMon */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static Sl_TstRsltType SramEccTst_lChkSramMon            **
**                       (const uint8 MemIdx,                                 **
**                        uint32* const TstSignature)                         **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : MemIdx - Index of the memory under test; Refer to       **
**                             definition of supported SRAMs in               **
**                             SramEccTst_MemDef.h for a list of supported    **
**                             values                                         **
**                                                                            **
** Parameters (out) : TstSignature : Test signature generated by the test     **
**                                                                            **
** Return value     : SRAM_SUCCESS - SRAM monitor test succeeded              **
**                    <Error ID> - Type of error during SRAM monitor test     **
**                                                                            **
** Description      : This function tests the SRAM monitor, i.e. the that     **
**                    errors are correctly tracked to the error tracking      **
**                    registers, that an error at the same address is not     **
**                    tracked twice and that an error tracking overflow       **
**                    generates a SMU alarm.                                  **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType SramEccTst_lChkSramMon
(
  const uint8 MemIdx,
  uint32* const TstSignature
)
{
  Sl_TstRsltType            Result = SRAMECC_NOTEXECUTED;
  Sl_TstRsltType            ResultTmp;
  uint16                    WordlineIdx;
  uint16                    ValExpected = 1U;
  Ifx_MC*                   Mc;
  SramEccTst_WdtContextType WdtContext;

  /* Get pointer to memory controller SFRs of RAM under test: */
  Mc = SramEccTst_lGetMc(MemIdx);

  /* Initialize wordline index: */
  WordlineIdx = SramEccTst_kMemDef[MemIdx]->NrOfEtrRegisters;



  /* Clear error tracking information: */
  Mc->ECCD.U |= (uint16)((uint32)IFX_MC_ECCD_TRC_MSK <<
                         (uint32)IFX_MC_ECCD_TRC_OFF);

  SramEccTst_lResetSafetyENDINIT(&WdtContext);
  /* Enable error tracking: */
  Mc->ECCS.U |= (uint16)((uint32)IFX_MC_ECCS_TRE_MSK <<
                         (uint32)IFX_MC_ECCS_TRE_OFF);

  /* Clear ECCS.TC_WAY_SEL: */
  Mc->ECCS.U &= ~(uint16)((uint32)IFX_MC_ECCS_TC_WAY_SEL_MSK <<
                          (uint32)IFX_MC_ECCS_TC_WAY_SEL_OFF);
  SramEccTst_lSetSafetyENDINIT(&WdtContext);

  /* Check that correctable errors are tracked and that multiple errors
   * at the same address are not tracked twice:
   */
  ResultTmp = SramEccTst_lChkSramMonCe(MemIdx,
                                       TstSignature,
                                       &ValExpected,
                                       &WordlineIdx);
  if (SRAMECC_SUCCESS != ResultTmp)
  {
    Result = ResultTmp;
  } /* if (SRAMECC_SUCCESS != ResultTmp) */
  else
  {
    /* Check that uncorrectable errors are tracked and fill all tracking
     * entries:
     */
    ResultTmp = SramEccTst_lChkSramMonUe(MemIdx,
                                         TstSignature,
                                         &ValExpected,
                                         &WordlineIdx);
    if (SRAMECC_SUCCESS != ResultTmp)
    {
      Result = ResultTmp;
    } /* if (SRAMECC_SUCCESS != ResultTmp) */
    else
    {
      /* Check reporting of error tracking overflow to the SMU: */
      Result = SramEccTst_lChkSramMonEov(MemIdx,
                                         TstSignature,
                                         WordlineIdx);
    } /* if (SRAMECC_SUCCESS == ResultTmp) */
  } /* if (SRAMECC_SUCCESS == ResultTmp) */

  /* Clear ECCD error flags: */


  /* Clear error flags: */
  Mc->ECCD.U &= ~(uint16)(((uint32)IFX_MC_ECCD_SERR_MSK <<
                           (uint32)IFX_MC_ECCD_SERR_OFF) |
                          ((uint32)IFX_MC_ECCD_CERR_MSK <<
                           (uint32)IFX_MC_ECCD_CERR_OFF) |
                          ((uint32)IFX_MC_ECCD_UERR_MSK <<
                           (uint32)IFX_MC_ECCD_UERR_OFF) |
                          ((uint32)IFX_MC_ECCD_AERR_MSK <<
                           (uint32)IFX_MC_ECCD_AERR_OFF));

  /* Clear error tracking information: */
  Mc->ECCD.U |= (uint16)((uint32)IFX_MC_ECCD_TRC_MSK <<
                         (uint32)IFX_MC_ECCD_TRC_OFF);

  return Result;
} /* SramEccTst_lChkSramMon */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static Sl_TstRsltType SramEccTst_lChkSramMonCe          **
**                       (const uint8 MemIdx,                                 **
**                        uint32* const TstSignature,                         **
**                        uint16* const ValExpected,                          **
**                        uint16* const WordlineIdx)                          **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : MemIdx - Index of the memory under test; Refer to       **
**                             definition of supported SRAMs in               **
**                             SramEccTst_MemDef.h for a list of supported    **
**                             values                                         **
**                                                                            **
** Parameters (out) : TstSignature : Test signature generated by the test     **
**                    ValExpected : in & out parameter, contains the expected **
**                                  ECCD.VAL value and will be set to the     **
**                                  expected ECCD.VAL value for the next test **
**                    WordlineIdx : in & out paramater, contains the current  **
**                                  wordline to be used for correctable error **
**                                  test and will be set to wordline that is  **
**                                  to be used for the next test              **
**                                                                            **
** Return value     : SRAM_SUCCESS - SRAM monitor CE test succeeded           **
**                    <Error ID> - Type of error during SRAM monitor CE test  **
**                                                                            **
** Description      : This function tests that correctable ECC errors are     **
**                    correctly tracked to the error tracking registers,      **
**                    reported to the SMU and that an error at the same       **
**                    address is not tracked twice.                           **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType SramEccTst_lChkSramMonCe
(
  const uint8 MemIdx,
  uint32* const TstSignature,
  uint16* const ValExpected,
  uint16* const WordlineIdx
)
{
  Sl_TstRsltType  Result = SRAMECC_NOTEXECUTED;
  Sl_TstRsltType  ResultTmp;
  uint16          Val;
  uint16          Err;
  uint16          WordlineIdxBackup = *WordlineIdx;
  Ifx_MC*         Mc;

  /* Get pointer to memory controller SFRs of RAM under test: */
  Mc = SramEccTst_lGetMc(MemIdx);

  /* Inject single bit error pattern and check that error tracking registers
   * get updated correctly:
   */
  SramEccTst_lFlipBits(MemIdx, 0U, 0U, 1U);
  SramEccTst_lWriteWordline(MemIdx, *WordlineIdx);

  /* Read memory back: */
  SramEccTst_lReadWordline(MemIdx, *WordlineIdx);



  /* Read ECCD.VAL: */
  Val = (Mc->ECCD.U & (uint16)((uint32)IFX_MC_ECCD_VAL_MSK <<
                               (uint32)IFX_MC_ECCD_VAL_OFF)) >>
                              IFX_MC_ECCD_VAL_OFF;

  /* Update test signature: */
  *TstSignature = (uint32)CRC32(*TstSignature, (uint32)Val);

  /* Get expected type of error: */
  if (SRAMECCTST_SMU_NONE == SramEccTst_kMemDef[MemIdx]->SmuNr_SbeCorr)
  {
    Err = (Mc->ECCD.U & (uint16)((uint32)IFX_MC_ECCD_UERR_MSK <<
                                 (uint32)IFX_MC_ECCD_UERR_OFF)) >>
                                IFX_MC_ECCD_UERR_OFF;
  } /* if (SRAMECCTST_SMU_NONE == SramEccTst_kMemDef[MemIdx]->SmuNr_SbeCorr) */
  else
  {
    Err = (Mc->ECCD.U & (uint16)((uint32)IFX_MC_ECCD_CERR_MSK <<
                                 (uint32)IFX_MC_ECCD_CERR_OFF)) >>
                                IFX_MC_ECCD_CERR_OFF;
  } /* if (SRAMECCTST_SMU_NONE != SramEccTst_kMemDef[MemIdx]->SmuNr_SbeCorr) */

  /* Clear error flags: */
  Mc->ECCD.U &= ~(uint16)(((uint32)IFX_MC_ECCD_SERR_MSK <<
                           (uint32)IFX_MC_ECCD_SERR_OFF) |
                          ((uint32)IFX_MC_ECCD_CERR_MSK <<
                           (uint32)IFX_MC_ECCD_CERR_OFF) |
                          ((uint32)IFX_MC_ECCD_UERR_MSK <<
                           (uint32)IFX_MC_ECCD_UERR_OFF));

  /* Check ECCD.VAL and type of error: */
  if ((Val != *ValExpected) || (1U != Err))
  {
    Result = SRAMECC_ETR_MISSING;
  } /* if ((Val != *ValExpected) || (1U != Err)) */
  else
  {
    if (SramEccTst_kMemDef[MemIdx]->NrOfEtrRegisters > 1U)
    {
      /* Check that reading the same address multiple times will not
       * generate more than one error tracking entries:
       */
      SramEccTst_lReadWordline(MemIdx, *WordlineIdx);



      /* Read ECCD.VAL: */
      Val = (Mc->ECCD.U & (uint16)((uint32)IFX_MC_ECCD_VAL_MSK <<
                                   (uint32)IFX_MC_ECCD_VAL_OFF)) >>
                                  IFX_MC_ECCD_VAL_OFF;

      /* Update test signature: */
      *TstSignature = (uint32)CRC32(*TstSignature, (uint32)Val);

      /* Clear error flags: */
      Mc->ECCD.U &= ~(uint16)(((uint32)IFX_MC_ECCD_SERR_MSK <<
                               (uint32)IFX_MC_ECCD_SERR_OFF) |
                              ((uint32)IFX_MC_ECCD_CERR_MSK <<
                               (uint32)IFX_MC_ECCD_CERR_OFF) |
                              ((uint32)IFX_MC_ECCD_UERR_MSK <<
                               (uint32)IFX_MC_ECCD_UERR_OFF));
      if (Val != *ValExpected)
      {
        Result = SRAMECC_ETR_DUPLICATE;
      } /* if (Val != *ValExpected) */
      else
      {
        (*WordlineIdx)--;
        *ValExpected = (uint16)((uint32)(*ValExpected) << 1) + 1U;
      } /* if (Val == *ValExpected) */
    } /* if (SramEccTst_kMemDef[MemIdx]->NrOfEtrRegisters > 1U) */
    else
    {
      /* Clear error flags: */
      Mc->ECCD.U &= ~(uint16)(((uint32)IFX_MC_ECCD_SERR_MSK <<
                               (uint32)IFX_MC_ECCD_SERR_OFF) |
                              ((uint32)IFX_MC_ECCD_CERR_MSK <<
                               (uint32)IFX_MC_ECCD_CERR_OFF) |
                              ((uint32)IFX_MC_ECCD_UERR_MSK <<
                               (uint32)IFX_MC_ECCD_UERR_OFF));
      /* Clear error tracking information: */
      Mc->ECCD.U |= (uint16)((uint32)IFX_MC_ECCD_TRC_MSK <<
                             (uint32)IFX_MC_ECCD_TRC_OFF);
    } /* if (SramEccTst_kMemDef[MemIdx]->NrOfEtrRegisters <= 1U) */
  } /* if ((Val == *ValExpected) && (1U == Err)) */

  /* Revoke single bit error: */
  SramEccTst_lFlipBits(MemIdx, 0U, 0U, 1U);
  SramEccTst_lWriteWordline(MemIdx, WordlineIdxBackup);

  /* Check if correctable error SMU alarm was raised: */
  if (SRAMECCTST_SMU_NONE != SramEccTst_kMemDef[MemIdx]->SmuNr_SbeCorr)
  {
    ResultTmp = SramEccTst_lWaitForSmuAlarm(
        SramEccTst_kMemDef[MemIdx]->SmuAlarmGrp,
        SramEccTst_kMemDef[MemIdx]->SmuNr_SbeCorr,
        TstSignature);
    if ((SRAMECC_SUCCESS != ResultTmp) && (SRAMECC_NOTEXECUTED == Result))
    {
      Result = ResultTmp;
    } /* if (SRAMECC_SUCCESS != ResultTmp) */
  } /* if (SRAMECCTST_SMU_NONE != SramEccTst_kMemDef[MemIdx]->SmuNr_SbeCorr) */
  else
  {
    ResultTmp = SramEccTst_lWaitForSmuAlarm(
        SramEccTst_kMemDef[MemIdx]->SmuAlarmGrp,
        SramEccTst_kMemDef[MemIdx]->SmuNr_UcErr,
        TstSignature);
    if ((SRAMECC_SUCCESS != ResultTmp) && (SRAMECC_NOTEXECUTED == Result))
    {
      Result = ResultTmp;
    } /* if (SRAMECC_SUCCESS != ResultTmp) */
  } /* if (SRAMECCTST_SMU_NONE == SramEccTst_kMemDef[MemIdx]->SmuNr_SbeCorr) */

  /* Update Result: */
  if (SRAMECC_NOTEXECUTED == Result)
  {
    Result = SRAMECC_SUCCESS;
  }

  return Result;
} /* SramEccTst_lChkSramMonCe */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static Sl_TstRsltType SramEccTst_lChkSramMonUe          **
**                       (const uint8 MemIdx,                                 **
**                        uint32* const TstSignature,                         **
**                        uint16* const ValExpected,                          **
**                        uint16* const WordlineIdx)                          **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : MemIdx - Index of the memory under test; Refer to       **
**                             definition of supported SRAMs in               **
**                             SramEccTst_MemDef.h for a list of supported    **
**                             values                                         **
**                                                                            **
** Parameters (out) : TstSignature : Test signature generated by the test     **
**                    ValExpected : in & out parameter, contains the expected **
**                                  ECCD.VAL value and will be set to the     **
**                                  expected ECCD.VAL value for the next test **
**                    WordlineIdx : in & out paramater, contains the current  **
**                                  wordline to be used for uncorrectable     **
**                                  error test and will be set to wordline    **
**                                  that is to be used for the next test      **
**                                                                            **
** Return value     : SRAM_SUCCESS - SRAM monitor UE test succeeded           **
**                    <Error ID> - Type of error during SRAM monitor UE test  **
**                                                                            **
** Description      : This function tests that uncorrectable ECC errors are   **
**                    correctly tracked and fills all error tracking entries  **
**                    as preparation for the following overflow test.         **
**                    It also checks that uncorrectable ECC errors are        **
**                    reported to the SMU.                                    **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType SramEccTst_lChkSramMonUe
(
  const uint8 MemIdx,
  uint32* const TstSignature,
  uint16* const ValExpected,
  uint16* const WordlineIdx
)
{
  Sl_TstRsltType  Result = SRAMECC_NOTEXECUTED;
  Sl_TstRsltType  ResultTmp;
  uint16          Val;
  uint16          Err;
  Ifx_MC*         Mc;

  /* Get pointer to memory controller SFRs of RAM under test: */
  Mc = SramEccTst_lGetMc(MemIdx);

   /* Check tracking of uncorrectable errors and fill all error tracking
    * registers: */
  while ((*WordlineIdx) > 0U)
  {
    /* Inject double bit error pattern and check that error tracking
     * registers get updated correctly:
     */
    SramEccTst_lFlipBits(MemIdx, 0U, 0U, 2U);
    SramEccTst_lWriteWordline(MemIdx, *WordlineIdx);

    /* Read memory back: */
    SramEccTst_lReadWordline(MemIdx, *WordlineIdx);



    /* Read ECCD.VAL: */
    Val = (Mc->ECCD.U & (uint16)((uint32)IFX_MC_ECCD_VAL_MSK <<
                                 (uint32)IFX_MC_ECCD_VAL_OFF)) >>
                                IFX_MC_ECCD_VAL_OFF;
    Err = (Mc->ECCD.U & (uint16)((uint32)IFX_MC_ECCD_UERR_MSK <<
                         (uint32)IFX_MC_ECCD_UERR_OFF)) >>
                        IFX_MC_ECCD_UERR_OFF;

    /* Update test signature: */
    *TstSignature = (uint32)CRC32(*TstSignature, (uint32)Val);

    /* Clear error flags: */
    Mc->ECCD.U &= ~(uint16)(((uint32)IFX_MC_ECCD_SERR_MSK <<
                             (uint32)IFX_MC_ECCD_SERR_OFF) |
                            ((uint32)IFX_MC_ECCD_UERR_MSK <<
                             (uint32)IFX_MC_ECCD_UERR_OFF));

    /* Revoke double bit error by flipping the same bits again: */
    SramEccTst_lFlipBits(MemIdx, 0U, 0U, 2U);
    SramEccTst_lWriteWordline(MemIdx, *WordlineIdx);

    /* Check that error was tracked: */
    if ((Val != *ValExpected) || (0U == Err))
    {
      Result = SRAMECC_ETR_MISSING;
      (*WordlineIdx) = 0U;
    } /* if ((Val != *ValExpected) || (0U == Err)) */
    else
    {
      (*WordlineIdx)--;
      *ValExpected = (uint16)((uint32)(*ValExpected) << 1) + 1U;
    } /* if ((Val == *ValExpected) && (0U != Err)) */
  } /* while ((*WordlineIdx) > 0U) */

  /* Check if uncorrectable error SMU alarm was raised: */
  ResultTmp = SramEccTst_lWaitForSmuAlarm(
      SramEccTst_kMemDef[MemIdx]->SmuAlarmGrp,
      SramEccTst_kMemDef[MemIdx]->SmuNr_UcErr,
      TstSignature);
  if ((SRAMECC_SUCCESS != ResultTmp) && (SRAMECC_NOTEXECUTED == Result))
  {
    Result = ResultTmp;
  } /* if (SRAMECC_SUCCESS != ResultTmp) */

  /* Update test result: */
  if (SRAMECC_NOTEXECUTED == Result)
  {
    Result = SRAMECC_SUCCESS;
  } /* if (SRAMECC_NOTEXECUTED == Result) */

  return Result;
} /* SramEccTst_lChkSramMonUe */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static Sl_TstRsltType SramEccTst_lChkSramMonEov         **
**                       (const uint8 MemIdx,                                 **
**                        uint32* const TstSignature,                         **
**                        uint16* const WordlineIdx)                          **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : MemIdx - Index of the memory under test; Refer to       **
**                             definition of supported SRAMs in               **
**                             SramEccTst_MemDef.h for a list of supported    **
**                             values                                         **
**                    WordlineIdx - contains the current wordline to be used  **
**                                  for the error tracking overflow test      **
**                                                                            **
** Parameters (out) : TstSignature - Test signature generated by the test     **
**                                                                            **
** Return value     : SRAM_SUCCESS - SRAM monitor EOV test succeeded          **
**                    <Error ID> - Type of error during SRAM monitor EOV test **
**                                                                            **
** Description      : This function tests that overflow of the error tracking **
**                    registers is correctly signaled to the SMU and resp     **
**                    overflow bit is set. In the end, invalid ECC pattern is ** 
**                    written to RDBFL reg but that is not written to memory  **
*******************************************************************************/
static Sl_TstRsltType SramEccTst_lChkSramMonEov
(
  const uint8 MemIdx,
  uint32* const TstSignature,
  const uint16 WordlineIdx
)
{
  Sl_TstRsltType  Result = SRAMECC_NOTEXECUTED;
  Sl_TstRsltType  ResultTmp;
  Ifx_MC*         Mc;

  /* Get pointer to memory controller SFRs of RAM under test: */
  Mc = SramEccTst_lGetMc(MemIdx);

  /* Generate another error to provoke an error tracking overflow: */
  SramEccTst_lFlipBits(MemIdx, 0U, 0U, 2U);
  SramEccTst_lWriteWordline(MemIdx, WordlineIdx);

  /* Read memory back: */
  SramEccTst_lReadWordline(MemIdx, WordlineIdx);
  ResultTmp = SramEccTst_lWaitForSmuAlarm(
      SramEccTst_kMemDef[MemIdx]->SmuAlarmGrp,
      SramEccTst_kMemDef[MemIdx]->SmuNr_AdrBufFull,
      TstSignature);
  if (SRAMECC_SUCCESS != ResultTmp)
  {
    Result = SRAMECC_ETR_EOVMISSING;
  } /* if (SRAMECC_SUCCESS != ResultTmp) */
  else
  {

    if ((Mc->ECCD.U & (uint16)((uint32)IFX_MC_ECCD_EOV_MSK <<
                               (uint32)IFX_MC_ECCD_EOV_OFF)) > 0U)
    {
      Result = SRAMECC_SUCCESS;
    } /* if ((Mc->ECCD.U & (uint16)((uint32)IFX_MC_ECCD_EOV_MSK <<
                                    (uint32)IFX_MC_ECCD_EOV_OFF)) > 0U) */
    else
    {
      Result = SRAMECC_ETR_EOVMISSING;
    } /* if ((Mc->ECCD.U & (uint16)((uint32)IFX_MC_ECCD_EOV_MSK <<
                                    (uint32)IFX_MC_ECCD_EOV_OFF)) == 0U) */
  } /* if (SRAMECC_SUCCESS == ResultTmp) */

  /* Revoke bit error by flipping the same bit again: */
  SramEccTst_lFlipBits(MemIdx, 0U, 0U, 2U);
  SramEccTst_lWriteWordline(MemIdx, WordlineIdx);

  /* Clear uncorrectable ECC error SMU alarm: */
  if (E_OK != SramEccTst_lSmuClearAlarmStatus(
                SramEccTst_kMemDef[MemIdx]->SmuAlarmGrp,
                SramEccTst_kMemDef[MemIdx]->SmuNr_UcErr))
  {
    Result = SRAMECC_SMU_CLRALMSTSERR;
  } /* if (E_OK != SramEccTst_lSmuClearAlarmStatus(
                     SramEccTst_kMemDef[MemIdx]->SmuAlarmGrp,
                     SramEccTst_kMemDef[MemIdx]->SmuNr_UcErr)) */
  return Result;
} /* SramEccTst_lChkSramMonEov */

#if (CHIP_ID != 21U) && (CHIP_ID != 22U) && (CHIP_ID != 23U) && (CHIP_ID != 24U)
/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static Sl_TstRsltType SramEccTst_lChkLmuOnlnMon         **
**                       (uint32* const TstSignature)                         **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : MemIdx:  0..SRAMECCTST_MEMORY_COUNT-1; Only values      ** 
**                      defined in SramEccTst_MemDef.h are valid              **
**                                                                            **
** Parameters (out) : TstSignature - Test signature generated by the test     **
**                                                                            **
** Return value     : SRAM_SUCCESS - LMU online monitor test succeeded        **
**                    <Error ID> - Type of error during LMU online monitor    **
**                                 test                                       **
**                                                                            **
** Description      : This function checks that LMU online monitor errors are **
**                    correctly reported to the SMU.                          **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType SramEccTst_lChkLmuOnlnMon
(
  const uint8 MemIdx,
  uint32* const TstSignature
)
{
  Sl_TstRsltType Result = SRAMECC_NOTEXECUTED;
  uint32* AdmaTestCtrl = (uint32*)ADMA_TEST_CTRL_REG_ADDRESS;

  /* Enable LMU SRAM monitor error injection: */

  *AdmaTestCtrl = (uint32)LMU_ECC_FAIL;
  /* Wait for and clear LMU SRAM monitor SMU alarm: */
  Result = SramEccTst_lWaitForSmuAlarm(
              SramEccTst_kMemDef[MemIdx]->SmuAlarmGrp,
              SMU_ALARM_15,
              TstSignature);

  return Result;
} /* SramEccTst_lChkLmuOnlnMon */
#endif


#if ((CHIP_ID == 24U)|| (CHIP_ID == 23U) || (CHIP_ID == 22U) || (CHIP_ID == 21U) )
/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static void SramEccTst_lDisableCaching                  **
**                       (SramEccTst_BackupDataType* const BackupData)        **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : MemIdx - Index of memory of which to disable caching    **
**                                                                            **
** Parameters (out) : BackupData - Pointer to backup structure of the         **
**                                 SramEccTst                                 **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function disables data or instruction caching in   **
**                    DMI or PMI if the memory under test is a CPU SRAM of    **
**                    the CPU executing the test and stores the previous      **
**                    cache bypass setting to the backup structure.           **
**                                                                            **
*******************************************************************************/
static void SramEccTst_lDisableCaching
(
  SramEccTst_BackupDataType* const BackupData
)
{
  uint32                    Temp;
  SramEccTst_WdtContextType WdtContext;

  SramEccTst_lResetENDINIT(&WdtContext);
  Temp = (uint32)MFCR(CPU_PCON0);

  /* Backup PCBYP bit: */
  BackupData->CpuCacheBypass = (uint8)
  ((Temp & ((uint32)IFX_CPU_PCON0_PCBYP_MSK <<
           (uint32)IFX_CPU_PCON0_PCBYP_OFF)) >>
                   IFX_CPU_PCON0_PCBYP_OFF);

   /* Enable instruction cache bypassing: */
   Temp |= (uint32)IFX_CPU_PCON0_PCBYP_MSK <<
           (uint32)IFX_CPU_PCON0_PCBYP_OFF;
   MTCR(CPU_PCON0, Temp);
   SramEccTst_lSetENDINIT(&WdtContext);

} /* SramEccTst_lDisableCaching */



/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static void SramEccTst_lRestoreCaching                  **
**                       (const SramEccTst_BackupDataType* const BackupData)  **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : MemIdx - Index of memory of which to restore caching    **
**                    BackupData - Pointer to backup structure of the         **
**                                 SramEccTst                                 **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function restores data or instruction caching in   **
**                    DMI or PMI if the memory under test is a CPU SRAM of    **
**                    the CPU executing the test. Additionally it invalidates **
**                    the ICACHE if the memory under test is a PSPR or PTAG   **
**                    SRAM.                                                   **
**                                                                            **
*******************************************************************************/
static void SramEccTst_lRestoreCaching
(
  const SramEccTst_BackupDataType* const BackupData
)
{
  uint32                    Temp;
  SramEccTst_WdtContextType WdtContext;
  
  /* Invalidate instruction cache: */
  Temp = (uint32)MFCR(CPU_PCON1);
  Temp |= (uint32)IFX_CPU_PCON1_PCINV_MSK <<
          (uint32)IFX_CPU_PCON1_PCINV_OFF;
  MTCR(CPU_PCON1, Temp);

  /* Restore instruction cache bypassing: */
  if (0U == BackupData->CpuCacheBypass)
  {
    SramEccTst_lResetENDINIT(&WdtContext);
    Temp = (uint32)MFCR(CPU_PCON0);
    Temp &= ~((uint32)IFX_CPU_PCON0_PCBYP_MSK <<
    (uint32)IFX_CPU_PCON0_PCBYP_OFF);
    MTCR(CPU_PCON0, Temp);
    SramEccTst_lSetENDINIT(&WdtContext);
  } /* if (0U == BackupData->CpuCacheBypass) */

 } /* SramEccTst_lRestoreCaching */

#elif (CHIP_ID == 26U) || (CHIP_ID == 27U) || (CHIP_ID == 29U)
/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static void SramEccTst_lInvalidateCache                 **
**                    (                                                       **
**                      const uint8 MemIdx ,                                  **
**                      const SramEccTst_BackupDataType* const BackupData     **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : MemIdx - Index of memory under test                     **
**                    BackupData - Pointer to backup structure of the         **
**                                 SramEccTst                                 **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function checks if a cache invalidation is         **
**                    required for the current memory under test and - if so  **
**                    - invalidates the according DCACHE or PCACHE.           **
**                    The cache invalidation is done by clearing the          **
**                    respective TAG SRAM, as this method is independent of   **
**                    the CPU core and the current cache enable status.       **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType SramEccTst_lInvalidateCache
(
  const uint8 MemIdx,
  const SramEccTst_BackupDataType* const BackupData  
)
{
  uint8           TargetMemIdx = SRAM_MC_IDX_INVALID;
  uint16          Range = (uint16)0U;
  uint16          Delay = (uint16)0U;
  uint32          MemTestBackup = 0U;
  Sl_TstRsltType  Result = SRAMECC_NOTEXECUTED;
  Sl_TstRsltType  ResultTmp;
  boolean         EnableMbist = (boolean)FALSE;

  switch (MemIdx)
  {
#if (CHIP_ID == 29U)
  case SRAM_CPU0_DSPR:
    EnableMbist = (boolean)TRUE;
    TargetMemIdx = SRAM_CPU0_DTAG;
    Range = SRAM_DTAG_RANGE;
    Delay = SRAM_DTAG_FILL_DELAY;
    break;

  case SRAM_CPU0_DTAG:
    TargetMemIdx = SRAM_CPU0_DTAG;
    Range = SRAM_DTAG_RANGE;
    Delay = SRAM_DTAG_FILL_DELAY;
    break;
#endif /* (CHIP_ID == 29) */

  case SRAM_CPU0_PSPR:
    EnableMbist = (boolean)TRUE;
    TargetMemIdx = SRAM_CPU0_PTAG;
    Range = SRAM_CPU0_PTAG_RANGE;
    Delay = SRAM_CPU0_PTAG_FILL_DELAY;
    break;

  case SRAM_CPU0_PTAG:
    TargetMemIdx = SRAM_CPU0_PTAG;
    Range = SRAM_CPU0_PTAG_RANGE;
    Delay = SRAM_CPU0_PTAG_FILL_DELAY;
    break;

  case SRAM_CPU1_DSPR:
  case SRAM_CPU1_DSPR2:
    EnableMbist = (boolean)TRUE;
    TargetMemIdx = SRAM_CPU1_DTAG;
    Range = SRAM_DTAG_RANGE;
    Delay = SRAM_DTAG_FILL_DELAY;
    break;

  case SRAM_CPU1_DTAG:
    TargetMemIdx = SRAM_CPU1_DTAG;
    Range = SRAM_DTAG_RANGE;
    Delay = SRAM_DTAG_FILL_DELAY;
    break;

  case SRAM_CPU1_PSPR0:
    EnableMbist = (boolean)TRUE;
    TargetMemIdx = SRAM_CPU1_PTAG;
    Range = SRAM_CPU1_PTAG_RANGE;
    Delay = SRAM_CPU1_PTAG_FILL_DELAY;
    break;

  case SRAM_CPU1_PTAG:
    TargetMemIdx = SRAM_CPU1_PTAG;
    Range = SRAM_CPU1_PTAG_RANGE;
    Delay = SRAM_CPU1_PTAG_FILL_DELAY;
    break;

  case SRAM_CPU2_DSPR:
  case SRAM_CPU2_DSPR2:
    EnableMbist = (boolean)TRUE;
    TargetMemIdx = SRAM_CPU2_DTAG;
    Range = SRAM_DTAG_RANGE;
    Delay = SRAM_DTAG_FILL_DELAY;
    break;

  case SRAM_CPU2_DTAG:
    TargetMemIdx = SRAM_CPU2_DTAG;
    Range = SRAM_DTAG_RANGE;
    Delay = SRAM_DTAG_FILL_DELAY;
    break;

  case SRAM_CPU2_PSPR:
    EnableMbist = (boolean)TRUE;
    TargetMemIdx = SRAM_CPU2_PTAG;
    Range = SRAM_CPU2_PTAG_RANGE;
    Delay = SRAM_CPU2_PTAG_FILL_DELAY;
    break;

  case SRAM_CPU2_PTAG:
    TargetMemIdx = SRAM_CPU2_PTAG;
    Range = SRAM_CPU2_PTAG_RANGE;
    Delay = SRAM_CPU2_PTAG_FILL_DELAY;
    break;

  default:
    /* Nothing to do */
    break;
  } /* switch (MemIdx) */

  /* Cache invalidation required? */
  if (SRAM_MC_IDX_INVALID == TargetMemIdx)
  {
    /* Nothing to do */
    Result = SRAMECC_SUCCESS;
  } /* if (SRAM_MC_IDX_INVALID == TargetMemIdx) */
  else
  {
    if ((boolean)TRUE == EnableMbist)
    {
      /* MBIST controller needs to be enabled, first: */
      ResultTmp = SramEccTst_lEnableMbist(TargetMemIdx, &MemTestBackup);
      if (SRAMECC_SUCCESS != ResultTmp)
      {
        Result = ResultTmp;
      } /* if (SRAMECC_SUCCESS != ResultTmp) */
      else
      {
        /* Clear TAG SRAM: */
        Result = SramEccTst_lClearSram(TargetMemIdx, Range, Delay);

        /* Restore MBIST enable status: */
        ResultTmp = SramEccTst_lRestoreMbist(TargetMemIdx, MemTestBackup);
        if (SRAMECC_SUCCESS != ResultTmp)
        {
          Result = ResultTmp;
        } /* if (SRAMECC_SUCCESS != ResultTmp) */
      } /* if (SRAMECC_SUCCESS == ResultTmp) */
    } /* if ((boolean)TRUE == EnableMbist) */
    else if ((boolean)TRUE == BackupData->MBistEnable)
    {
      /* TAG SRAM MBIST already enabled, clear the TAG: */
      Result = SramEccTst_lClearSram(TargetMemIdx, Range, Delay);
    } 
    else
    {
      Result = SRAMECC_MBIST_INITIMEOUT;
    }	/* if ((boolean)TRUE != EnableMbist) */
  } /* if (SRAM_MC_IDX_INVALID != TargetMemIdx) */

  return Result;
} /* SramEccTst_lInvalidateCache */
#endif /* (CHIP_ID == 26U) || (CHIP_ID == 27U) || (CHIP_ID == 29U) */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static void SramEccTst_lDummyRamAccess                  **
**                    (                                                       **
**                      const uint8 MemIdx                                    **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : MemIdx - Index of memory for which to perform a dummy   **
**                             access; Refer to definition of supported SRAMs **
**                             in SramEccTst_MemDef.h for a list of supported **
**                             values                                         **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function performs a dummy write and read access to **
**                    a given memory. This is required before a MBIST         **
**                    controller is enabled to flush internal buffers of      **
**                    SRAM cells replaced by redundancy cells to prevent loss **
**                    of write data when the MBIST is enabled.                **
**                                                                            **
*******************************************************************************/
static void SramEccTst_lDummyRamAccess
(
  const uint8 MemIdx
)
{
  volatile uint32             Dummy = 0U;
  
  UNUSED_PARAMETER(Dummy)

  switch(MemIdx)
  {
    case SRAM_CPU0_DSPR:

    DSYNC();
    Dummy = *(uint32*)(SRAM_DSPR0_ADDRESS);
    break;

    case SRAM_CPU0_PSPR:

    DSYNC();
    Dummy = *(uint32*)(SRAM_PSPR0_ADDRESS);
    break;

#if (CHIP_ID == 26U) || (CHIP_ID == 27U) || (CHIP_ID == 29U)
    case SRAM_CPU1_DSPR:
    case SRAM_CPU1_DSPR2:
#if (CHIP_ID == 29U)
    DSYNC();
    Dummy = *(uint32*)(SRAM_DSPR1_ADDRESS); 
    Dummy = *(uint32*)(SRAM_DSPR1_ADDRESS + SRAM_TC29_DSPR2_INTERLEAVE);
#else /* (CHIP_ID == 29) */
    DSYNC();
    Dummy = *(uint32*)(SRAM_DSPR1_ADDRESS);
#endif /* (CHIP_ID != 29) */
    break;

    case SRAM_CPU1_PSPR0:
 
    DSYNC();
    Dummy = *(uint32*)(SRAM_PSPR1_ADDRESS);
    break;
#endif /* (CHIP_ID == 26) || (CHIP_ID == 27) || (CHIP_ID == 29) */

#if (CHIP_ID == 27U) || (CHIP_ID == 29U)
  case SRAM_CPU2_DSPR:
  case SRAM_CPU2_DSPR2:
#if (CHIP_ID == 29U)
    DSYNC();
    Dummy = *(uint32*)(SRAM_DSPR2_ADDRESS);
    Dummy = *(uint32*)(SRAM_DSPR2_ADDRESS+SRAM_TC29_DSPR2_INTERLEAVE); 
#else /* (CHIP_ID == 29) */
    DSYNC();
    Dummy = *(uint32*)(SRAM_DSPR2_ADDRESS);
#endif /* (CHIP_ID != 29) */
    break;

    case SRAM_CPU2_PSPR:

    DSYNC();
    Dummy = *(uint32*)(SRAM_PSPR2_ADDRESS);
    break;

    case SRAM_DAM:

    DSYNC();
    Dummy = *(uint32*)(SRAM_LMU_ADDRESS);
    break;
#endif /* (CHIP_ID == 27) || (CHIP_ID == 29) */

    default:
    /* Nothing to do */
    break;
  } /* switch(MemIdx) */
} /* SramEccTst_lDummyRamAccess */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static Sl_TstRsltType SramEccTst_lEnableMbist           **
**                    (                                                       **
**                      const uint8 MemIdx,                                   **
**                      uint32* const MemTestBackup                           **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : MemIdx - Index of memory of which to enable the MBIST   **
**                             memory test mode; Refer to definition of       **
**                             supported SRAMs in SramEccTst_MemDef.h for a   **
**                             list of supported values                       **
**                                                                            **
** Parameters (out) : MemTestBackup - Pointer that will receive the previous  **
**                                    MBIST enable status                     **
**                                                                            **
** Return value     : SRAMECC_SUCCESS - Enabling MBIST succeeded              **
**                    <Error ID> - Type of error while enabling MBIST         **
**                                                                            **
** Description      : This function enables the MBIST memory test mode of a   **
**                    given memory.                                           **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType SramEccTst_lEnableMbist
(
  const uint8 MemIdx,
  uint32* const MemTestBackup
)
{
  uint32                    Timeout;
  Sl_TstRsltType            Result = SRAMECC_NOTEXECUTED;
  volatile uint32*          MemTestPtr;
  volatile uint32*          MemStatPtr;
  uint32                    BitMask;
  SramEccTst_WdtContextType WdtContext;
  uint32                    Status;
  uint8                     McIdx;

  /* Get memory controller index: */
  McIdx = SramEccTst_kMcTable[MemIdx];

  /* Get pointer to MTU_MEMTESTx and MTU_MEMSTATx SFR and store bit mask: */
  if (McIdx < 32U)
  {
    MemTestPtr = (volatile uint32*)(volatile void *)&MTU_MEMTEST0.U;
    MemStatPtr = (volatile uint32*)(volatile void *)&MTU_MEMSTAT0.U;
    BitMask = (uint32)((uint32)1U << McIdx);
  } /* if (McIdx < 32U) */
  else if (McIdx < 64U)
  	/* polyspace<RTE:UNR:LOW:No action planned> executed in case of invalid parameter */
  {
    MemTestPtr = (volatile uint32*)(volatile void *)&MTU_MEMTEST1.U;
    MemStatPtr = (volatile uint32*)(volatile void *)&MTU_MEMSTAT1.U;
    BitMask = (uint32)((uint32)1U << (McIdx - 32U));
  } /* if (McIdx < 64U) */
  else if (McIdx < SRAMECCTST_MBIST_CONTROLLER_COUNT)
  {
    MemTestPtr = (volatile uint32*)(volatile void *)&MTU_MEMTEST2.U;
    MemStatPtr = (volatile uint32*)(volatile void *)&MTU_MEMSTAT2.U;
    BitMask = (uint32)((uint32)1U << (McIdx - 64U));
  } /* if (McIdx < SRAMECCTST_MBIST_CONTROLLER_COUNT) */
  else
  {
    Result = SRAMECC_INVPARAMERR;

    /* Required to avoid compiler warning: */
    MemTestPtr = 0U;
    MemStatPtr = 0U;
    BitMask = 0U;
  } /* if (McIdx >= SRAM_ MBIST_CONTROLLER_COUNT) */

  if (SRAMECC_NOTEXECUTED == Result)
  {
    /* Store MBIST enable status: */
    *MemTestBackup = *MemTestPtr & BitMask;

    /* Enable MBIST controller of RAM under test: */
    SramEccTst_lResetSafetyENDINIT(&WdtContext);
    *MemTestPtr |= BitMask;
    SramEccTst_lSetSafetyENDINIT(&WdtContext);

    /* Wait for RAM initialization to complete: */
    Timeout = 0U;
    do
    {
      Timeout++;
      Status = (*MemStatPtr) & BitMask;
    } while ((Timeout < SRAM_MBIST_MEM_INIT_TIMEOUT) && (Status > 0U));

    /* RAM initialization completed? */
    if (((*MemStatPtr) & BitMask) > 0U)
    {
      /* RAM initialization did not complete in time => error: */
      Result = SRAMECC_MBIST_INITIMEOUT;
      /* Disable MBIST controller: */
      SramEccTst_lResetSafetyENDINIT(&WdtContext);
      *MemTestPtr &= ~BitMask;
      SramEccTst_lSetSafetyENDINIT(&WdtContext);
    } /* if (((*MemStatPtr) & BitMask) > 0U) */
    else
    {
      Result = SRAMECC_SUCCESS;
    } /* if (((*MemStatPtr) & BitMask) == 0U) */
  } /* if (SRAMECC_NOTEXECUTED == Result) */

  return Result;
} /* SramEccTst_lEnableMbist */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static Sl_TstRsltType SramEccTst_lRestoreMbist          **
**                    (                                                       **
**                      const uint8 MemIdx,                                   **
**                      const MemTestBackup                                   **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : MemIdx - Index of memory of which to restore the MBIST  **
**                             enable status; Refer to definition of          **
**                             supported SRAMs in SramEccTst_MemDef.h for a   **
**                             list of supported values                       **
**                    MemTestBackup - Backup value of previous MBIST enable   **
**                                    status                                  **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : SRAMECC_SUCCESS - Restoring MBIST succeeded             **
**                    <Error ID> - Type of error while disabling MBIST        **
**                                                                            **
** Description      : This function restores the MBIST enable status of a     **
**                    given memory.                                           **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType SramEccTst_lRestoreMbist
(
  const uint8 MemIdx,
  const uint32 MemTestBackup
)
{
  uint32                    Timeout;
  Sl_TstRsltType            Result = SRAMECC_NOTEXECUTED;
  volatile uint32*          MemTestPtr;
  volatile uint32*          MemStatPtr;
  uint32                    BitMask;
  SramEccTst_WdtContextType WdtContext;
  uint32                    Status;
  uint8                     McIdx;


  /* Check if memory controller was disabled: */
  if (0U == MemTestBackup)
  {
    /* Get memory controller index: */
    McIdx = SramEccTst_kMcTable[MemIdx];

    /* Get pointer to MTU_MEMTESTx and MTU_MEMSTATx SFR and store bit mask: */
    if (McIdx < 32U)
    {
      MemTestPtr = (volatile uint32*)(volatile void *)&MTU_MEMTEST0.U;
      MemStatPtr = (volatile uint32*)(volatile void *)&MTU_MEMSTAT0.U;
      BitMask = (uint32)((uint32)1U << McIdx);
    } /* if (McIdx < 32U) */
    else if (McIdx < 64U)
    {
      MemTestPtr = (volatile uint32*)(volatile void *)&MTU_MEMTEST1.U;
      MemStatPtr = (volatile uint32*)(volatile void *)&MTU_MEMSTAT1.U;
      BitMask = (uint32)((uint32)1U << (McIdx - 32U));
    } /* if (McIdx < 64U) */
    else if (McIdx < SRAMECCTST_MBIST_CONTROLLER_COUNT)
    {
      MemTestPtr = (volatile uint32*)(volatile void *)&MTU_MEMTEST2.U;
      MemStatPtr = (volatile uint32*)(volatile void *)&MTU_MEMSTAT2.U;
      BitMask = (uint32)((uint32)1U << (McIdx - 64U));
    } /* if (McIdx < SRAMECCTST_MBIST_CONTROLLER_COUNT) */
    else
    {
      Result = SRAMECC_INVPARAMERR;

      /* Required to avoid compiler warning: */
      MemTestPtr = 0U;
      MemStatPtr = 0U;
      BitMask = 0U;
    } /* if (McIdx >= SRAMECCTST_MBIST_CONTROLLER_COUNT) */

    if (SRAMECC_NOTEXECUTED == Result)
    {
      /* Disable MBIST controller: */
      SramEccTst_lResetSafetyENDINIT(&WdtContext);
      *MemTestPtr &= ~BitMask;
      SramEccTst_lSetSafetyENDINIT(&WdtContext);

      /* Wait for RAM initialization to complete: */
      Timeout = 0U;
      do
      {
        Timeout++;
        Status = (*MemStatPtr) & BitMask;
      } while ((Timeout < SRAM_MBIST_MEM_INIT_TIMEOUT) && (Status > 0U));

      /* RAM initialization completed? */
      if ((*MemStatPtr & BitMask) > 0U)
      {
        /* RAM initialization did not complete in time => error: */
        Result = SRAMECC_MBIST_INITIMEOUT;
      } /* if ((*MemStatPtr & BitMask) > 0U) */
      else
      {
	    #if(CHIP_ID == 29U)
        volatile uint16                    dummy;		
	    if((MemIdx == SRAM_CPU1_DSPR)||(MemIdx == SRAM_CPU1_DSPR2))
		{
          /* Clear error flags for both memory controllers for CPU1 DSPR */
		  /*dummy write with 0x780F as a workaround for 
		    functional deviation MTU_TC.005*/
		  MC6_ECCD.U = SRAM_DUMMY_ECCD_WRITE;
          dummy = MC6_ECCD.U;
          dummy &= ~(uint16)(((uint32)IFX_MC_ECCD_SERR_MSK <<
                           (uint32)IFX_MC_ECCD_SERR_OFF) |
                          ((uint32)IFX_MC_ECCD_CERR_MSK <<
                           (uint32)IFX_MC_ECCD_CERR_OFF) |
                          ((uint32)IFX_MC_ECCD_UERR_MSK <<
                           (uint32)IFX_MC_ECCD_UERR_OFF) |
                          ((uint32)IFX_MC_ECCD_AERR_MSK <<
                           (uint32)IFX_MC_ECCD_AERR_OFF));
		  MC6_ECCD.U = SRAM_DUMMY_ECCD_WRITE;
		  MC6_ECCD.U = dummy;
          /* Clear error tracking information: */
		  MC6_ECCD.U = SRAM_DUMMY_ECCD_WRITE;
		  dummy = MC6_ECCD.U;
          dummy |= (uint16)((uint32)IFX_MC_ECCD_TRC_MSK <<
                         (uint32)IFX_MC_ECCD_TRC_OFF);
		  MC6_ECCD.U = SRAM_DUMMY_ECCD_WRITE;
          MC6_ECCD.U = dummy;	
						 
		  MC20_ECCD.U = SRAM_DUMMY_ECCD_WRITE;
          dummy = MC20_ECCD.U;
          dummy &= ~(uint16)(((uint32)IFX_MC_ECCD_SERR_MSK <<
                           (uint32)IFX_MC_ECCD_SERR_OFF) |
                          ((uint32)IFX_MC_ECCD_CERR_MSK <<
                           (uint32)IFX_MC_ECCD_CERR_OFF) |
                          ((uint32)IFX_MC_ECCD_UERR_MSK <<
                           (uint32)IFX_MC_ECCD_UERR_OFF) |
                          ((uint32)IFX_MC_ECCD_AERR_MSK <<
                           (uint32)IFX_MC_ECCD_AERR_OFF));
		  MC20_ECCD.U = SRAM_DUMMY_ECCD_WRITE;
		  MC20_ECCD.U = dummy;
          /* Clear error tracking information: */
		  MC20_ECCD.U = SRAM_DUMMY_ECCD_WRITE;
		  dummy = MC20_ECCD.U;
          dummy |= (uint16)((uint32)IFX_MC_ECCD_TRC_MSK <<
                         (uint32)IFX_MC_ECCD_TRC_OFF);
		  MC20_ECCD.U = SRAM_DUMMY_ECCD_WRITE;
          MC20_ECCD.U = dummy;						 
			
		}
		else if((MemIdx == SRAM_CPU2_DSPR)||(MemIdx == SRAM_CPU2_DSPR2))
		{
          /* Clear error flags for both memory controllers for CPU2 DSPR */
		  /*dummy write with 0x780F as a workaround for 
		    functional deviation MTU_TC.005*/
		  MC0_ECCD.U = SRAM_DUMMY_ECCD_WRITE;
          dummy = MC0_ECCD.U;
          dummy &= ~(uint16)(((uint32)IFX_MC_ECCD_SERR_MSK <<
                           (uint32)IFX_MC_ECCD_SERR_OFF) |
                          ((uint32)IFX_MC_ECCD_CERR_MSK <<
                           (uint32)IFX_MC_ECCD_CERR_OFF) |
                          ((uint32)IFX_MC_ECCD_UERR_MSK <<
                           (uint32)IFX_MC_ECCD_UERR_OFF) |
                          ((uint32)IFX_MC_ECCD_AERR_MSK <<
                           (uint32)IFX_MC_ECCD_AERR_OFF));
		  MC0_ECCD.U = SRAM_DUMMY_ECCD_WRITE;
		  MC0_ECCD.U = dummy;
          /* Clear error tracking information: */
		  MC0_ECCD.U = SRAM_DUMMY_ECCD_WRITE;
		  dummy = MC0_ECCD.U;
          dummy |= (uint16)((uint32)IFX_MC_ECCD_TRC_MSK <<
                         (uint32)IFX_MC_ECCD_TRC_OFF);
		  MC0_ECCD.U = SRAM_DUMMY_ECCD_WRITE;
          MC0_ECCD.U = dummy;
			
		  MC21_ECCD.U = SRAM_DUMMY_ECCD_WRITE;
          dummy = MC21_ECCD.U;
          dummy &= ~(uint16)(((uint32)IFX_MC_ECCD_SERR_MSK <<
                           (uint32)IFX_MC_ECCD_SERR_OFF) |
                          ((uint32)IFX_MC_ECCD_CERR_MSK <<
                           (uint32)IFX_MC_ECCD_CERR_OFF) |
                          ((uint32)IFX_MC_ECCD_UERR_MSK <<
                           (uint32)IFX_MC_ECCD_UERR_OFF) |
                          ((uint32)IFX_MC_ECCD_AERR_MSK <<
                           (uint32)IFX_MC_ECCD_AERR_OFF));
		  MC21_ECCD.U = SRAM_DUMMY_ECCD_WRITE;
		  MC21_ECCD.U = dummy;
          /* Clear error tracking information: */
		  MC21_ECCD.U = SRAM_DUMMY_ECCD_WRITE;
		  dummy = MC21_ECCD.U;
          dummy |= (uint16)((uint32)IFX_MC_ECCD_TRC_MSK <<
                         (uint32)IFX_MC_ECCD_TRC_OFF);
		  MC21_ECCD.U = SRAM_DUMMY_ECCD_WRITE;
          MC21_ECCD.U = dummy;					 
		}
		else
		{
		  /*dummy else to avoid misra*/
		}
		#endif
        Result = SRAMECC_SUCCESS;
      } /* if ((*MemStatPtr & BitMask) == 0U) */

    } /* if (SRAMECC_NOTEXECUTED == Result) */
  } /* if (0U == BackupData->MemTest) */
  else
  {
    /* Nothing to do, memory controller was already enabled before the test: */
    Result = SRAMECC_SUCCESS;
  } /* if (0U != BackupData->MemTest) */

  return Result;
} /* SramEccTst_lRestoreMbist */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : Sl_TstRsltType SramEccTst_lWaitForSmuAlarm              **
**                       (const uint8 SmuGrp,                                 **
**                        const uint8 SmuAlarmNr,                             **
**                        uint32* const TstSignature)                         **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : SmuGrp - SMU alarm group containing the alarm to wait   **
**                             for                                            **
**                    SmuAlarmNr - SMU alarm number to wait for               **
**                                                                            **
** Parameters (out) : TstSignature : Test signature generated by the test     **
**                                                                            **
** Return value     : SRAM_SUCCESS - Waiting for and clearing the SMU alarm   **
**                                   succeeded                                **
**                    <Error ID> - Type of error during waiting/clearing      **
**                                                                            **
** Description      : This function waits for the signaling of a given SMU    **
**                    alarm and afterwards clears this alarm if waiting       **
**                    succeeded.                                              **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType SramEccTst_lWaitForSmuAlarm
(
  const uint8 SmuGrp,
  const uint8 SmuAlarmNr,
  uint32* const TstSignature
)
{
  Sl_TstRsltType  Result = SRAMECC_NOTEXECUTED;
  uint32          AlarmStatus = 0U;
  uint32          Timeout = SRAMECC_SMU_ALM_TIMEOUT;

  /* Wait for the requested SMU alarm to become signaled: */
  while ((Timeout > 0U) &&
         (0U == (((uint32)1U << SmuAlarmNr) & AlarmStatus)))
  {
    Timeout--;
    if (E_OK != Smu_GetAlarmStatus(SmuGrp, &AlarmStatus))
    {
      AlarmStatus = 0U;
      Timeout = 0U;
      Result = SRAMECC_SMU_GETALMSTSERR;
    } /* if (E_OK != Smu_GetAlarmStatus(SmuGrp, &AlarmStatus)) */
  } /* while ((Timeout > 0U) &&
              (0U == (((uint32)1U << SmuAlarmNr) & AlarmStatus))) */

  /* Update test signature: */
  *TstSignature = (uint32)CRC32(*TstSignature,
                        AlarmStatus & ((uint32)1U << SmuAlarmNr));

  /* Check if expected alarm was signaled: */
  if (0U == (((uint32)1U << SmuAlarmNr) & AlarmStatus))
  {
    if (SRAMECC_NOTEXECUTED == Result)
    {
      Result = SRAMECC_SMU_ALMSTSERR;
    } /* if (SRAMECC_NOTEXECUTED == Result) */
  } /* if (0U == (((uint32)1U << SmuAlarmNr) & AlarmStatus)) */
  else
  {
    /* Clear the SMU alarm: */
    if (E_OK != SramEccTst_lSmuClearAlarmStatus(SmuGrp, SmuAlarmNr))
    {
      Result = SRAMECC_SMU_CLRALMSTSERR;
    } /* if (E_OK != SramEccTst_lSmuClearAlarmStatus(SmuGrp, SmuAlarmNr)) */
    else
    {
      Result = SRAMECC_SUCCESS;
    } /* if (E_OK == SramEccTst_lSmuClearAlarmStatus(SmuGrp, SmuAlarmNr)) */
  } /* if (0U != (((uint32)1U << SmuAlarmNr) & AlarmStatus)) */

  return Result;
} /* SramEccTst_lWaitForSmuAlarm */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static Sl_TstRsltType SramEccTst_lBackupMemContent      **
**                             (const uint8 MemIdx,                           **
**                              const Sl_ParamSetType ParamSetIndex,          **
**                              SramEccTst_BackupDataType* const BackupData)  **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : MemIdx - Index of the memory under test; Refer to       **
**                             definition of supported SRAMs in               **
**                             SramEccTst_MemDef.h for a list of supported    **
**                             values                                         **
**                    ParamSetIndex - config Parameter index                  **
**                                                                            **
** Parameters (out) : BackupData - Pointer to backup data struct of SRAM test **
**                                                                            **
** Return value     : SRAMECC_SUCCESS - Memory backup succeeded or disabled   **
**                                      via configuration setting             **
**                    SRAMECC_CONSISTENCYERR - Invalid memory definition      **
**                    SRAMECC_NOTEXECUTED - Program flow consistency error    **
**                    SRAMECC_RWOPTIMEOUT - MBIST memory read operation timed **
**                                          out                               **
**                    SRAMECC_RWOPFAIL - MBIST memory read operation failed   **
**                    SRAMECC_PROGRAMFLOWERR - Program flow error in          **
**                                             subroutine                     **
**                                                                            **
** Description      : This function backs up all memory content that will be  **
**                    overwritten by the test to a backup data struct.        **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType SramEccTst_lBackupMemContent
(
  const uint8 MemIdx,
  const Sl_ParamSetType ParamSetIndex,
  SramEccTst_BackupDataType* const BackupData
)
{
  Sl_TstRsltType  Result = SRAMECC_NOTEXECUTED;
  Sl_TstRsltType  ResultTmp;
  uint8           RdbflRegIdx;
  uint8           RdbflRegCount;
  uint16          WordlineIdx;
  uint16          WordlineCount;
  Ifx_MC*         Mc;
  boolean         FuncDevMtuTc008Exists;

  if ((boolean)TRUE == SramEccTst_ConfigRoot[ParamSetIndex].BackupMemory)
  {
    /* Get pointer to memory controller SFRs of RAM under test: */
    Mc = SramEccTst_lGetMc(MemIdx);

    /* Calculate number of wordlines to backup:
     *  -Nr. of error tracking registers + 1 wordlines is required in the
     *   SRAM monitor test to create an overflow of error tracking records
     *  -At least two wordlines are required by the address error SMU signaling
     *   test
     */
    WordlineCount = (uint16)SramEccTst_kMemDef[MemIdx]->NrOfEtrRegisters +
                    (uint16)1U;
    if (SRAM_MIN_NR_OF_WORDLINES > WordlineCount)
	/* polyspace<RTE:UNR:LOW:Justify with annotations> executed in case of invalid parameter*/
    {
      WordlineCount = SRAM_MIN_NR_OF_WORDLINES;
    } /* if (SRAM_MIN_NR_OF_WORDLINES > WordlineCount) */

    /* WordlineCount consistency check: */
    if (WordlineCount > SRAM_MAX_NR_OF_WORDLINES)
	/* polyspace<RTE:UNR:LOW:No action planned> executed in case of invalid parameter */
    {
      Result = SRAMECC_CONSISTENCYERR;
    } /* if (WordlineCount > SRAM_MAX_NR_OF_WORDLINES) */
    else
    {
      /* Calculate the total number of RDBFL registers: */
      RdbflRegCount = SramEccTst_lCalcRdbflRegCount(MemIdx);

      /* Check if device is affected by MTU_TC.008: */
      FuncDevMtuTc008Exists = SramEccTst_lFuncDevMtuTc008Exists();

      /* Backup memory wordline-wise: */
      for (WordlineIdx = 0U;
           ((WordlineIdx < WordlineCount) && (SRAMECC_NOTEXECUTED == Result));
           WordlineIdx++)
      {
        /* Evaluation of MSTATUS.DONE in ReadWordline only possible for devices
         * without functional deviation MTU_TC.008:
         */
        if ((boolean)FALSE == FuncDevMtuTc008Exists)
        {
          /* Read wordline with evaluation of MSTATUS.DONE: */
          ResultTmp = SramEccTst_lReadWordlineSafe(MemIdx, WordlineIdx);
          if (SRAMECC_SUCCESS != ResultTmp)
          {
            Result = ResultTmp;
          } /* if (SRAMECC_SUCCESS != ResultTmp) */
        } /* if ((boolean)FALSE == FuncDevMtuTc008Exists) */
        else
        {
          /* Read wordline without evaluation of MSTATUS.DONE: */
          SramEccTst_lReadWordline(MemIdx, WordlineIdx);
        } /* if ((boolean)FALSE != FuncDevMtuTc008Exists) */

        if (SRAMECC_NOTEXECUTED == Result)
        {
          for (RdbflRegIdx = 0U; RdbflRegIdx < RdbflRegCount; RdbflRegIdx++)
          {
            BackupData->MemContentBackup[(WordlineIdx * RdbflRegCount) +
                                         RdbflRegIdx] = Mc->RDBFL[RdbflRegIdx].U;
          } /* for (RdbflRegIdx = 0U; RdbflRegIdx < RdbflRegCount;
                    RdbflRegIdx++) */
        } /* if (SRAMECC_SUCCESS == ResultTmp) */
      } /* for (WordlineIdx = 0U; ((WordlineIdx < WordlineCount) &&
                (SRAMECC_NOTEXECUTED == Result)); WordlineIdx++) */

      /* Check for success: */
      if (SRAMECC_NOTEXECUTED == Result)
      {
        /* Set memory backup valid: */
        BackupData->MemBackupValid = (boolean)TRUE;

        /* Update Result: */
        Result = SRAMECC_SUCCESS;
      } /* if (SRAMECC_NOTEXECUTED == Result) */
    } /* if (WordlineCount <= SRAM_MAX_NR_OF_WORDLINES) */
  } /* if (TRUE == SramEccTst_ConfigRoot[ParamSetIndex].BackupMemory) */
  else
  {
    /* Nothing to do, return success: */
    Result = SRAMECC_SUCCESS;
  } /* if (TRUE != SramEccTst_ConfigRoot[ParamSetIndex].BackupMemory) */

  return Result;
} /* SramEccTst_lBackupMemContent */


/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static Sl_TstRsltType SramEccTst_lRestoreMemContent     **
**                       (const uint8 MemIdx,                                 **
**                        const SramEccTst_BackupDataType* const BackupData)  **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : MemIdx - Index of the memory under test; Refer to       **
**                             definition of supported SRAMs in               **
**                             SramEccTst_MemDef.h for a list of supported    **
**                             values                                         **
**                    BackupData - Pointer to backup data struct of SRAM test **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : SRAMECC_SUCCESS - Memory restoration succeeded or is    **
**                                      disabled via configuration setting    **
**                    SRAMECC_CONSISTENCYERR - Invalid memory definition      **
**                    SRAMECC_NOTEXECUTED - Program flow consistency error    **
**                    SRAMECC_MBIST_RWOPTIMEOUT - MBIST memory write timed    **
**                                                out                         **
**                    SRAMECC_MBIST_RWOPFAIL - MBIST memory write failed      **
**                    SRAMECC_PROGRAMFLOWERR - Program flow error in          **
**                                             subroutine                     **
**                                                                            **
** Description      : This function restores all memory content that has been **
**                    backed up by SramEccTst_lBackupMemContent function.     **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType SramEccTst_lRestoreMemContent
(
  const uint8 MemIdx,
  const SramEccTst_BackupDataType* const BackupData
)
{
  Sl_TstRsltType  Result = SRAMECC_NOTEXECUTED;
  Sl_TstRsltType  ResultTmp;
  uint8           RdbflRegIdx;
  uint8           RdbflRegCount;
  uint16          WordlineIdx;
  uint16          WordlineCount;
  Ifx_MC*         Mc;
  boolean         FuncDevMtuTc008Exists;

  if ((boolean)TRUE == BackupData->MemBackupValid)
  {
    /* Get pointer to memory controller SFRs of RAM under test: */
    Mc = SramEccTst_lGetMc(MemIdx);

    /* Calculate number of wordlines to backup:
     *  -Nr. of error tracking registers + 1 wordlines is required in the
     *   SRAM monitor test to create an overflow of error tracking records
     *  -At least two wordlines are required by the address error SMU signaling
     *   test
     */
    WordlineCount = (uint16)SramEccTst_kMemDef[MemIdx]->NrOfEtrRegisters +
                    (uint16)1U;
    if (SRAM_MIN_NR_OF_WORDLINES > WordlineCount)
    {
      WordlineCount = SRAM_MIN_NR_OF_WORDLINES;
    } /* if (SRAM_MIN_NR_OF_WORDLINES > WordlineCount) */

    /* WordlineCount consistency check: */
    if (WordlineCount > SRAM_MAX_NR_OF_WORDLINES)
    {
      Result = SRAMECC_CONSISTENCYERR;
    } /* if (WordlineCount > SRAM_MAX_NR_OF_WORDLINES) */
    else
    {
      /* Calculate the total number of RDBFL registers: */
      RdbflRegCount = SramEccTst_lCalcRdbflRegCount(MemIdx);

      /* Check if device is affected by MTU_TC.008: */
      FuncDevMtuTc008Exists = SramEccTst_lFuncDevMtuTc008Exists();

      /* Restore memory wordline-wise: */
      for (WordlineIdx = 0U;
           ((WordlineIdx < WordlineCount) && (SRAMECC_NOTEXECUTED == Result));
           WordlineIdx++)
      {
        for (RdbflRegIdx = 0U; RdbflRegIdx < RdbflRegCount; RdbflRegIdx++)
        {
          Mc->RDBFL[RdbflRegIdx].U = BackupData->MemContentBackup[
                      (WordlineIdx * RdbflRegCount) + RdbflRegIdx];
        } /* for (RdbflRegIdx = 0U; RdbflRegIdx < RdbflRegCount;
                  RdbflRegIdx++) */


        /* Evaluation of MSTATUS.DONE in ReadWordline only possible for devices
         * without functional deviation MTU_TC.008:
         */
        if ((boolean)FALSE == FuncDevMtuTc008Exists)
        {
          /* Write wordline with evaluation of MSTATUS.DONE: */
          ResultTmp = SramEccTst_lWriteWordlineSafe(MemIdx, WordlineIdx);
          if (SRAMECC_SUCCESS != ResultTmp)
          {
            Result = ResultTmp;
          } /* if (SRAMECC_SUCCESS != ResultTmp) */
        } /* if ((boolean)FALSE == FuncDevMtuTc008Exists) */
        else
        {
          /* Write wordline without evaluation of MSTATUS.DONE: */
          SramEccTst_lWriteWordline(MemIdx, WordlineIdx);
        } /* if ((boolean)FALSE == FuncDevMtuTc008Exists) */
      } /* for (WordlineIdx = 0U; ((WordlineIdx < WordlineCount) &&
                (SRAMECC_NOTEXECUTED == Result)); WordlineIdx++) */

      /* Check for success: */
      if (SRAMECC_NOTEXECUTED == Result)
      {
        Result = SRAMECC_SUCCESS;
      }
    } /* if (WordlineCount <= SRAM_MAX_NR_OF_WORDLINES) */
  } /* if ((boolean)TRUE == BackupData->MemBackupValid) */
  else
  {
    /* Nothing to do, return success: */
    Result = SRAMECC_SUCCESS;
  } /* if ((boolean)TRUE != BackupData->MemBackupValid) */

  return Result;
} /* SramEccTst_lRestoreMemContent */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static Sl_TstRsltType SramEccTst_lCalcMemoryCrc         **
**                       (const uint8 MemIdx,                                 **
**                        uint32* const Crc)                                  **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : MemIdx - Index of the memory under test; Refer to       **
**                             definition of supported SRAMs in               **
**                             SramEccTst_MemDef.h for a list of supported    **
**                             values                                         **
**                                                                            **
** Parameters (out) : Crc - Pointer that will receive the CRC value over the  **
**                          whole SRAM area that is used for testing          **
**                                                                            **
** Return value     : SRAMECC_SUCCESS - Calculating memory CRC succeeded      **
**                    SRAMECC_CONSISTENCYERR - Invalid memory definition      **
**                    SRAMECC_NOTEXECUTED - Program flow consistency error    **
**                    SRAMECC_INVPARAMERR - Invalid value of MemIdx parameter **
**                                                                            **
** Description      : This function calculates a CRC over the whole memory    **
**                    area, that is used for testing and thus backed up       **
**                    before and restored after the test.                     **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType SramEccTst_lCalcMemoryCrc
(
  const uint8 MemIdx,
  uint32* const Crc
)
{
  Sl_TstRsltType  Result = SRAMECC_NOTEXECUTED;
  uint16          WordlineIdx;
  uint16          WordlineStep = (uint16)1U;
  uint16          WordlineCount;
  uint32          WordIdx;
  uint32          WordsPerWordline;
  uint32          MemoryWordIdx;

  /* Initialize CRC value: */
  *Crc = 0U;

  /* Parameter check for MemIdx: */
  if (MemIdx >= SRAMECCTST_MEMORY_COUNT)
  /* polyspace<RTE:UNR:LOW:Justify with annotations> executed in case of invalid parameter*/
  {
    Result = SRAMECC_INVPARAMERR;
  } /* if (MemIdx >= SRAMECCTST_MEMROY_COUNT) */
  else
  {
    /* No CRC calculation required for TAG SRAMs: */
    if ((uint32*)NULL_PTR == SramEccTst_SramBaseAddrList[MemIdx])
    {
      Result = SRAMECC_SUCCESS;
    } /* if ((uint32*)NULL_PTR == SramEccTst_SramBaseAddrList[MemIdx]) */
    else
    {
      /* Get number of 32bit words per wordline: */
      WordsPerWordline = ((uint32)SramEccTst_kMemDef[MemIdx]->NrOfDataBits *
                          (uint32)SramEccTst_kMemDef[MemIdx]->NrOfMemBlocks) *
                         (uint32)SramEccTst_kMemDef[MemIdx]->NrOfMultiplexers;
      if (0U != (WordsPerWordline % SRAM_BITS_PER_WORD))
      {
        Result = SRAMECC_CONSISTENCYERR;
      } /* if (0U != (WordsPerWordline % SRAM_BITS_PER_WORD)) */
      else
      {
        WordsPerWordline /= SRAM_BITS_PER_WORD;

        /* TC29x CPU1/2 DSPR and DSPR2 SRAMs are interleaved wordline-wise, thus
         * the wordline step size needs to be increased to two:
         */
#if (CHIP_ID == 29U)
        if ((SRAM_CPU1_DSPR == MemIdx) || (SRAM_CPU1_DSPR2 == MemIdx) ||
            (SRAM_CPU2_DSPR == MemIdx) || (SRAM_CPU2_DSPR2 == MemIdx))
        {
          WordlineStep = SRAM_TC29_DSPR2_WORDLINE_STEP;
        } /* if ((SRAM_CPU1_DSPR == MemIdx) || (SRAM_CPU1_DSPR2 == MemIdx) ||
                 (SRAM_CPU2_DSPR == MemIdx) || (SRAM_CPU2_DSPR2 == MemIdx)) */
#endif /* (CHIP_ID == 29U) */

        /* Calculate number of wordlines: */
        WordlineCount = (uint16)SramEccTst_kMemDef[MemIdx]->NrOfEtrRegisters +
                        (uint16)1U;
        if ((uint16)SRAM_MIN_NR_OF_WORDLINES > WordlineCount)
		/* polyspace<RTE:UNR:LOW:Justify with annotations> executed in case of invalid parameter*/
        {
          WordlineCount = (uint16)SRAM_MIN_NR_OF_WORDLINES;
        } /* if (SRAM_MIN_NR_OF_WORDLINES > WordlineCount) */

        /* WordlineCount consistency check: */
        if (WordlineCount > (uint16)SRAM_MAX_NR_OF_WORDLINES)
		/* polyspace<RTE:UNR:LOW:Justify with annotations> executed in case of invalid parameter*/
        {
          Result = SRAMECC_CONSISTENCYERR;
        } /* if (WordlineCount > SRAM_MAX_NR_OF_WORDLINES) */
        else
        {
          /* Calculate CRC; step through each wordline: */
          for (WordlineIdx = (uint16)0U;
               WordlineIdx < WordlineCount;
               WordlineIdx += WordlineStep)
          {
            /* Step through each word within wordline: */
            for (WordIdx = 0U; WordIdx < WordsPerWordline; WordIdx++)
            {
              /* Calculate index into target SRAM: */
              MemoryWordIdx = ((uint32)WordlineIdx * WordsPerWordline) +
                              WordIdx;

              /* Update CRC: */
              *Crc = CRC32(*Crc,
                           SramEccTst_SramBaseAddrList[MemIdx][MemoryWordIdx]);
            } /* for (WordIdx = 0U; WordIdx < WordsPerWordline; WordIdx++)
               */
          } /* for (WordlineIdx = (uint16)0U;
                    WordlineIdx < WordlineCount;
                    WordlineIdx += WordlineStep) */

          Result = SRAMECC_SUCCESS;
        } /* if (WordlineCount <= SRAM_MAX_NR_OF_WORDLINES) */
      } /* if (0U == (WordsPerWordline % SRAM_BITS_PER_WORD)) */
    } /* if ((uint32*)NULL_PTR != SramEccTst_SramBaseAddrList[MemIdx]) */
  } /* if (MemIdx < SRAMECCTST_MEMROY_COUNT) */

  return Result;
} /* SramEccTst_lCalcMemoryCrc */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : Sl_TstRsltType SramEccTst_lCheckMemoryCrc               **
**                       (const uint8 MemIdx,                                 **
**                        const uint32 ExpectedCrc)                           **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : MemIdx - Index of the memory under test; Refer to       **
**                             definition of supported SRAMs in               **
**                             SramEccTst_MemDef.h for a list of supported    **
**                             values                                         **
**                    ExpectedCrc - Expected CRC value of the memory area     **
**                    used for testing                                        **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : SRAMECC_SUCCESS - Memory CRC check passed               **
**                    SRAMECC_CONSISTENCYERR - Invalid memory definition      **
**                    SRAMECC_NOTEXECUTED - Program flow consistency error    **
**                    SRAMECC_INVPARAMERR - Invalid value of MemIdx parameter **
**                    SRAMECC_DATACORRUPTION - Memory CRC mismatch            **
**                                                                            **
** Description      : This function calculates a CRC over the whole memory    **
**                    area, that is used for testing and thus backed up       **
**                    before and restored after the test. The calculated CRC  **
**                    value is then compared to an expected CRC value.        **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType SramEccTst_lCheckMemoryCrc
(
  const uint8 MemIdx,
  const uint32 ExpectedCrc
)
{
  Sl_TstRsltType  Result = SRAMECC_NOTEXECUTED;
  Sl_TstRsltType  ResultTmp;
  uint32          Crc = 0U;

  /* Calculate CRC over memory range: */
  ResultTmp = SramEccTst_lCalcMemoryCrc(MemIdx, &Crc);
  if (SRAMECC_SUCCESS != ResultTmp)
  {
    Result = ResultTmp;
  } /* if (SRAMECC_SUCCESS != ResultTmp) */
  else
  {
    if (ExpectedCrc == Crc)
    {
      Result = SRAMECC_SUCCESS;
    } /* if (BackupData->MemContentCrc == Crc) */
    else
    {
      Result = SRAMECC_DATACORRUPTION;
    } /* if (BackupData->MemContentCrc != Crc) */
  } /* if (SRAMECC_SUCCESS == ResultTmp) */

  return Result;
} /* SramEccTst_lCheckMemoryCrc */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static boolean SramEccTst_lFuncDevMtuTc008Exists        **
**                       (void)                                               **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : TRUE - Current device affected by MTU_TC.008            **
**                    FALSE - Current device not affected by MTU_TC.008       **
**                                                                            **
** Description      : This function checks whether or not the currently       **
**                    executing device is affected by the functional          **
**                    deviation MTU_TC.008.                                   **
**                                                                            **
*******************************************************************************/
static boolean SramEccTst_lFuncDevMtuTc008Exists
(
  void
)
{
  volatile boolean Result = (boolean)TRUE;
  /* The Errata MTU_TC.008 is not applicable for EP devices. Variable Result is
  made as volatile to avoid the compiler warning for EP devices */ 

  /* Read major silicon design step (only required for TC26x, TC27x and TC29x):
   */
#if (CHIP_ID != 21U) && (CHIP_ID != 22U) && (CHIP_ID != 23U) && (CHIP_ID != 24U)
  uint32  DesignStep = 0U;

  DesignStep = SCU_CHIPID.U;
  DesignStep = (uint32)(DesignStep & SRAM_SCU_CHIPID_DSM_MSK);
  DesignStep = (uint32)(DesignStep >> SRAM_SCU_CHIPID_DSM_OFF);
#endif /* (CHIP_ID != 21U) && (CHIP_ID != 22U) &&
          (CHIP_ID != 23U) && (CHIP_ID != 24U) */

  /* Get derivative: */
#if (CHIP_ID == 21U) || (CHIP_ID == 22U) || (CHIP_ID == 23U)
  /* No deviation for all EP devices: */
  Result = (boolean)FALSE;
#elif (CHIP_ID == 24U)
  /* Functional deviation MTU_TC.008 exists for all TC24x devices: */
  Result = (boolean)TRUE;
#elif (CHIP_ID == 26U)
  /* Functional deviation exists only for TC26x devices with design step < B: */
  if (DesignStep > SRAM_A_STEP)
  {
    Result = (boolean)FALSE;
  } /* if (DesignStep > SRAM_A_STEP) */
  else
  {
    Result = (boolean)TRUE;
  } /* if (DesignStep == SRAM_A_STEP) */
#elif (CHIP_ID == 27U)
  /* Functional deviation exists only for TC27x devices with design step < D: */
  if (DesignStep > SRAM_C_STEP)
  {
    Result = (boolean)FALSE;
  } /* if (DesignStep > SRAM_C_STEP) */
  else
  {
    Result = (boolean)TRUE;
  } /* if (DesignStep <= SRAM_C_STEP) */
#elif (CHIP_ID == 29U)
  /* Functional deviation exists only for TC29x devices with design step < B: */
  if (DesignStep > SRAM_A_STEP)
  {
    Result = (boolean)FALSE;
  } /* if (DesignStep > SRAM_A_STEP) */
  else
  {
    Result = (boolean)TRUE;
  } /* if (DesignStep == SRAM_A_STEP) */
#else
#error "Invalid CHIP_ID."
#endif

  return Result;
} /* SramEccTst_lFuncDevMtuTc008Exists */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static Sl_TstRsltType SramEccTst_lEnableMtuClock        **
**                       (SramEccTst_BackupDataType* const BackupData)        **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : BackupData - Pointer to backup data struct of SRAM test **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : SRAMECC_SUCCESS - MTU clock enable succeeded            **
**                    <Error ID> - Type of error during clock enable          **
**                                                                            **
** Description      : This function enables clock gating for the MTU module   **
**                    and stores the previous status of MTU clock gating to   **
**                    the given backup data structure.                        **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType SramEccTst_lEnableMtuClock
(
    SramEccTst_BackupDataType* const BackupData
)
{
  Sl_TstRsltType            Result = SRAMECC_MBIST_CLCTIMEOUT;
  uint32                    Timeout;
  SramEccTst_WdtContextType WdtContext;

  /* Backup MTU_CLC.DISR bit: */
  BackupData->MtuClcDisr = (uint8)(MTU_CLC.B.DISR);

  /* Enable MTU clock: */
  SramEccTst_lResetENDINIT(&WdtContext);
  MTU_CLC.B.DISR = 0U;
  SramEccTst_lSetENDINIT(&WdtContext);
  Timeout = SRAM_CLK_EN_TIMEOUT;
  while((MTU_CLC.B.DISS > 0U) && (Timeout > 0U))
  {
    Timeout--;
  } /* while((MTU_CLC.B.DISS > 0U) && (Timeout > 0U)) */
  if (MTU_CLC.B.DISS == 0U)
  {
    Result = SRAMECC_SUCCESS;
  } /* if (MTU_CLC.B.DISS == 0U) */

  return Result;
} /* SramEccTst_lEnableMtuClock */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : Sl_TstRsltType SramEccTst_lRestoreMtuClock              **
**                       (const SramEccTst_BackupDataType* const BackupData)  **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : BackupData - Pointer to backup data struct of SRAM test **
**                                 that holds the previous state of MTU clock **
**                                 gating                                     **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : SRAMECC_SUCCESS - MTU clock restoration succeeded       **
**                    <Error ID> - Type of error during clock restoration     **
**                                                                            **
** Description      : This function restores clock gating for the MTU module  **
**                    as it has been before the SRAM ECC test was executed.   **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType SramEccTst_lRestoreMtuClock
(
    const SramEccTst_BackupDataType* const BackupData
)
{
  Sl_TstRsltType            Result = SRAMECC_MBIST_CLCTIMEOUT;
  uint32                    Timeout;
  SramEccTst_WdtContextType WdtContext;

  /* Restore MTU clock enable setting: */
  if (BackupData->MtuClcDisr > 0U)
  {
    /* Disable MTU clock: */
    SramEccTst_lResetENDINIT(&WdtContext);
    MTU_CLC.B.DISR = 1U;
    SramEccTst_lSetENDINIT(&WdtContext);
    Timeout = SRAM_CLK_EN_TIMEOUT;
    while((MTU_CLC.B.DISS == 0U) && (Timeout > 0U))
    {
      Timeout--;
    } /* while(((MTU_CLC.U & SRAM_MTU_CLC_DISS_BIT) == 0U) && (Timeout > 0U)) */
    if (MTU_CLC.B.DISS > 0U)
    {
      Result = SRAMECC_SUCCESS;
    } /* if ((MTU_CLC.U & SRAM_MTU_CLC_DISS_BIT) > 0U) */
  } /* if (BackupData->MtuClcDisr > 0U) */
  else
  {
    Result = SRAMECC_SUCCESS;
  } /* if (BackupData->MtuClcDisr == 0U) */

  return Result;
} /* SramEccTst_lRestoreMtuClock */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : LOCAL_INLINE uint32 SramEccTst_lCpuPwSequence           **
**                    (const sint8 Wdt, const uint32 Password)                **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters(in)   : Wdt - Watchdog timer for which to create a password     **
**                            -1: Safety watchdog                             **
**                             0: CPU0 watchdog                               **
**                             1: CPU1 watchdog                               **
**                             2: CPU2 watchdog                               **
**                    Password - Old WDTCON0 value                            **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : New password for next watchdog access                   **
**                                                                            **
** Description      : Creates expected WDT password reload                    **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE uint32 SramEccTst_lCpuPwSequence
(
  const sint8 Wdt,
  const uint32 Password
)
{
  uint32 Result = Password & SRAM_WDT_PASSWORD_MASK;
  sint8  WdtIdx = Wdt + (sint8)1;

  if ((uint8)WdtIdx < ((uint8)MCAL_NO_OF_CORES+(uint8)1U))
  /* polyspace<RTE:UNR:LOW:Justify with annotations> executed in case of invalid parameter*/
  {
    volatile Ifx_SCU_WDTCPU_SR* ScuSsrPtr =
        SramEccTst_kScuWdtPtrList[WdtIdx].WdtssrPtr;

    /* first generate proper password write value
       (include PW Bit8-15 and inverted PW Bit 2-7) */
    Result = (Result & SRAM_WDT_PASSWORD_UPPER_MASK) |
              ((~(Result & SRAM_WDT_PASSWORD_LOWER_MASK)) &
              SRAM_WDT_PASSWORD_LOWER_MASK);

    /* additionally auto sequence password enabled ? */
    if (ScuSsrPtr->B.PAS != 0u)
    {
       /*  modify password with expected password by calculating new 14-bit LFSR
        *  with characteristic polynomial x14+x13+x12+x2+1.
        */
      uint32 lfsr = Result;
      uint32 bit  = ((lfsr>>1) ^ (lfsr>>11) ^ (lfsr>>12) ^ (lfsr>>13)) &
                     0x0004u;
      Result      = (((lfsr << 1) | bit) & SRAM_WDT_PASSWORD_MASK);
    } /* if (ScuSsrPtr->B.PAS != 0u) */
  } /* if ((uint32)(Wdt + 1) < SRAM_WDT_MAX_CPUWDT) */

  return Result;
} /* SramEccTst_lCpuPwSequence */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : SramEccTs_lCpuRelValue(const sint8 Wdt,                 **
**                                           const uint32 TimReload)          **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters(in)   : Wdt - Watchdog timer for which to create reload value   **
**                            -1: Safety watchdog                             **
**                             0: CPU0 watchdog                               **
**                             1: CPU1 watchdog                               **
**                             2: CPU2 watchdog                               **
**                    TimReload - Old WDTCON0 value                           **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : New watchdog timer reload value                         **
**                                                                            **
** Description      : Creates expected timer reload value                     **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE uint32 SramEccTst_lCpuRelValue
(
  const sint8 Wdt,
  const uint32 TimReload
)
{
  uint32 Result = TimReload & SRAM_WDT_RELOAD_MASK;
  sint8  WdtIdx = Wdt + (sint8)1;

  if ((uint8)WdtIdx < ((uint8)MCAL_NO_OF_CORES+(uint8)1U))
  /* polyspace<RTE:UNR:LOW:Justify with annotations> executed in case of invalid parameter*/
  {
    volatile Ifx_SCU_WDTCPU_SR* ScuSsrPtr =
        SramEccTst_kScuWdtPtrList[WdtIdx].WdtssrPtr;

    /* timer check enabled ? */
    if (ScuSsrPtr->B.TCS != 0u)
    {
      Result = (uint32)((~(uint32)ScuSsrPtr->B.TIM) << 16);
    } /*if (ScuSsrPtr->B.TCS != 0u) */
  } /* if ((uint32)(Wdt + 1) < SRAM_WDT_MAX_CPUWDT) */

  return Result;
} /* SramEccTst_lCpuRelValue */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static void SramEccTst_lResetCpuENDINIT                 **
**                      (const sint8 Wdt,                                     **
**                       SramEccTst_WdtContextType* const WdtContext)         **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters(in)   : Wdt - Watchdog for which to reset ENDINIT bit:          **
**                            -1: Safety watchdog                             **
**                             0: CPU0 watchdog                               **
**                             1: CPU1 watchdog                               **
**                             2: CPU2 watchdog                               **
**                                                                            **
** Parameters (out) : WdtContext - This structure receives all data that is   **
**                                 required by SramEccTst_lSetCpuENDINIT to   **
**                                 restore previous watchdog state            **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Clears the ENDINIT flag for the given CPU or safety     **
**                    watchdog timer.                                         **
**                                                                            **
*******************************************************************************/
static void SramEccTst_lResetCpuENDINIT
(
  const sint8 Wdt,
  SramEccTst_WdtContextType* const WdtContext
)
{
  sint8  WdtIdx = Wdt + (sint8)1;

  if ((uint8)WdtIdx < ((uint8)MCAL_NO_OF_CORES+(uint8)1U))
  /* polyspace<RTE:UNR:LOW:Justify with annotations> executed in case of invalid parameter*/
  {
    uint32 NewValCon0;
    uint32 NewPw;                   /* next password to be used */
    uint32 NewRel;                  /* next reload value to be used */
    uint32 ValTemp1;                /* Required due to MISRA */
    uint32 ValTemp2;                /* Required due to MISRA */
    volatile uint32 dummy;          /* ensure readback */

    volatile Ifx_SCU_WDTCPU_CON0* ScuWdtcon0Ptr =
        SramEccTst_kScuWdtPtrList[WdtIdx].Wdtcon0Ptr;
    volatile Ifx_SCU_WDTCPU_SR*   ScuSsrPtr     =
        SramEccTst_kScuWdtPtrList[WdtIdx].WdtssrPtr;

    /* save old value */
    NewValCon0  = ScuWdtcon0Ptr->U;

    /* get valid next password */
    NewPw  = SramEccTst_lCpuPwSequence(Wdt, NewValCon0);

    /* get valid next timer reload */
    NewRel = SramEccTst_lCpuRelValue(Wdt, NewValCon0);

    /* build required password WDTCON0 value */
    NewValCon0 =  ((NewRel) |              /* new reload value  */
                   (NewPw)  |              /* new Password */
                   (1u));                  /* Clear LCK, keep ENDINIT set */

    /* Read and save current timer and password to be restored with
     * SetENDINIT
     */
    ValTemp1 = ScuSsrPtr->U & (uint32)SRAM_WDT_RELOAD_MASK;
    ValTemp2 = ScuWdtcon0Ptr->U & (uint32)SRAM_WDT_PASSWORD_MASK;
    WdtContext->WdtTimAndPw = ValTemp1 | ValTemp2;

    ScuWdtcon0Ptr->U  = NewValCon0;        /* password access to unlock */

    NewValCon0 &= ~SRAM_WDT_STATUS_MASK;   /* clear ENDINIT and LCK Bit */
    NewValCon0 |= 0x2u;                    /* set LCK Bit */

    ScuWdtcon0Ptr->U = NewValCon0;  /* write access and lock for Timeout mode */

    /* read back to ensure protection release is executed */
    dummy = ScuWdtcon0Ptr->U;
    UNUSED_PARAMETER(dummy)
  } /* if ((uint32)(Wdt + 1) < SRAM_WDT_MAX_CPUWDT) */
} /* SramEccTst_lResetCpuENDINIT */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static void SranEccTst_lSetCpuENDINIT                   **
**                        (const sint8 Wdt,                                   **
**                         const SramEccTst_WdtContextType* const WdtContext) **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters(in)   : Wdt - Watchdog for which to set ENDINIT bit             **
**                            -1: Safety watchdog                             **
**                             0: CPU0 watchdog                               **
**                             1: CPU1 watchdog                               **
**                             2: CPU2 watchdog                               **
**                    WdtContext - Watchdog context received from             **
**                                 SramEccTst_lResetCpuENDINIT call           **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Sets the ENDINIT flag for the given CPU or safety       **
**                    watchdog timer.                                         **
**                                                                            **
*******************************************************************************/
static void SramEccTst_lSetCpuENDINIT
(
  const sint8 Wdt,
  const SramEccTst_WdtContextType* const WdtContext
)
{
  sint8  WdtIdx = Wdt + (sint8)1;

  if ((uint8)WdtIdx < ((uint8)MCAL_NO_OF_CORES+(uint8)1U))
  {
    uint32 NewValCon0;
    uint32 NewPw;                   /* next password to be used */
    uint32 NewRel;                  /* next timer reload to be used */
    volatile uint32 dummy;          /* ensure readback */

    volatile Ifx_SCU_WDTCPU_CON0* ScuWdtcon0Ptr =
        SramEccTst_kScuWdtPtrList[WdtIdx].Wdtcon0Ptr;
    volatile Ifx_SCU_WDTCPU_SR*   ScuSsrPtr     =
        SramEccTst_kScuWdtPtrList[WdtIdx].WdtssrPtr;

    /* save old value */
    NewValCon0  = ScuWdtcon0Ptr->U;

    /* get valid next password */
    NewPw  = SramEccTst_lCpuPwSequence(Wdt, NewValCon0);

    /* get valid next timer reload */
    NewRel = SramEccTst_lCpuRelValue(Wdt, NewValCon0);

    /* build required password WDTCON0 value */
    NewValCon0  =  ((NewRel) |             /* new reload value  */
                    (NewPw)  |             /* new Password */
                    (1u));                 /* Clear LCK, keep ENDINIT set */

    ScuWdtcon0Ptr->U = NewValCon0;         /*  unlock with password access */

    /* clear timer reload and restore saved and corrected reload value */
    NewValCon0 &= ~SRAM_WDT_RELOAD_MASK;

    /* set timer value back to prior value and add ticks during timeout mode */
    NewValCon0 |= (WdtContext->WdtTimAndPw +
                   ((ScuSsrPtr->U & (uint32)SRAM_WDT_RELOAD_MASK) -
                   (uint32)SDWT_TIMEOUT_MODE_RELOAD));

    /* prepare old password to be restored with modify access*/
    NewValCon0 &= ~SRAM_WDT_PASSWORD_MASK;
    NewValCon0 |= (WdtContext->WdtTimAndPw &
                   (uint32)SRAM_WDT_PASSWORD_UPPER_MASK) |
                   ((~(WdtContext->WdtTimAndPw &
                       (uint32)SRAM_WDT_PASSWORD_LOWER_MASK))
                   & (uint32)SRAM_WDT_PASSWORD_LOWER_MASK);

    /* prepare modify & lock access */
    NewValCon0 |= 3u;                      /* set LCK and ENDINIT Bit */
    ScuWdtcon0Ptr->U = NewValCon0;         /* write modify access and lock */

    /* read back to ensure protection release is executed */
    dummy = ScuWdtcon0Ptr->U;
    UNUSED_PARAMETER(dummy)
  } /* if ((uint8)WdtIdx < ((uint8)MCAL_NO_OF_CORES+(uint8)1U)) */
} /* SramEccTst_lSetCpuENDINIT */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : void SramEccTst_lResetENDINIT                           **
**                        (SramEccTst_WdtContextType* const WdtContext)       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : WdtContext - Pointer to SramEccTst_WdtContextType       **
**                                 structure that will receive previous       **
**                                 interrupt enable and timer reload value.   **
**                                 The same pointer must be passed to the     **
**                                 subsequent call to SramEccTst_lSetENDINIT  **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Clears the ENDINIT bit in the appropriate CPU watchdog. **
**                    Available for CPU0, CPU1 and CPU2. Proper password is   **
**                    calculated and restored on modify access.               **
**                    Disables interrupts and save current Wdt timer reload   **
**                    value.                                                  **
**                                                                            **
*******************************************************************************/
static void SramEccTst_lResetENDINIT
(
  SramEccTst_WdtContextType* const WdtContext
)
{
  uint32 CoreID = ((uint32)MFCR(CPU_CORE_ID) & (uint32)SRAM_CORE_ID_MASK);

  SramEccTst_lResetCpuENDINIT((sint8)CoreID, WdtContext);
} /* SramEccTst_lResetENDINIT */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static void SramEccTst_lResetSafetyENDINIT              **
**                        (SramEccTst_WdtContextType* const WdtContext)       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : WdtContext - Pointer to SramEccTst_WdtContextType       **
**                                 structure that will receive previous       **
**                                 interrupt enable and timer reload value.   **
**                                 The same pointer must be passed to the     **
**                                 subsequent call to                         **
**                                 SramEccTst_lSetSafetyENDINIT               **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Clears the ENDINIT bit in the global safety Watchdog.   **
**                    Proper password is calculated and restored on modify    **
**                    access. Disables interrupts and save current Wdt timer  **
**                    reload value.                                           **
**                                                                            **
*******************************************************************************/
static void SramEccTst_lResetSafetyENDINIT
(
  SramEccTst_WdtContextType* const WdtContext
)
{
  uint32 NewValCon0;
  uint32 NewPw;                   /* next password to be used */
  uint32 NewRel;                  /* next reload value to be used */
  volatile uint32 dummy;          /* ensure readback */

  /* Save old value */
  NewValCon0  = SCU_WDTSCON0.U;

  /* Get valid next password: */
  NewPw = NewValCon0 & SRAM_WDT_PASSWORD_MASK;

  /* - First generate proper password write value
       (include PW Bit8-15 and inverted PW Bit 2-7) */
  NewPw = (NewPw & SRAM_WDT_PASSWORD_UPPER_MASK) |
              ((~(NewPw & SRAM_WDT_PASSWORD_LOWER_MASK)) &
              SRAM_WDT_PASSWORD_LOWER_MASK);

  /* - Additionally auto sequence password enabled ? */
  if (SCU_WDTSSR.B.PAS != 0u)
  {
    /* Modify password with expected password by calculating new 14-bit LFSR
     * with characteristic polynomial x14+x13+x12+x2+1.
     */
    uint32 lfsr = NewPw;
    uint32 bit  = ((lfsr>>1) ^ (lfsr>>11) ^ (lfsr>>12) ^ (lfsr>>13)) & 0x0004u;
    NewPw       = (((lfsr << 1) | bit) & SRAM_WDT_PASSWORD_MASK);
  } /* if (SCU_WDTSSR.B.PAS != 0u) */

  /* Get valid next timer reload: */
  /* - Timer check enabled ? */
  if (SCU_WDTSSR.B.TCS != 0u)
  {
    NewRel = (uint32)((~(uint32)SCU_WDTSSR.B.TIM) << 16);
  } /*if (SCU_WDTSSR.B.TCS != 0u) */
  else
  {
    NewRel = NewValCon0 & SRAM_WDT_RELOAD_MASK;
  } /*if (SCU_WDTSSR.B.TCS == 0u) */

  /* Build required password WDTCON0 value */
  NewValCon0 =  ((NewRel) |              /* new reload value  */
                 (NewPw)  |              /* new Password */
                 (1u));                  /* Clear LCK, keep ENDINIT set */

  /* Read and save current timer and password to be restored with
   * SetENDINIT
   */
  WdtContext->WdtTimAndPw = SCU_WDTSSR.U & (uint32)SRAM_WDT_RELOAD_MASK;
  WdtContext->WdtTimAndPw |= SCU_WDTSCON0.U & (uint32)SRAM_WDT_PASSWORD_MASK;

  SCU_WDTSCON0.U  = NewValCon0;        /* password access to unlock */

  NewValCon0 &= ~SRAM_WDT_STATUS_MASK;   /* clear ENDINIT and LCK Bit */
  NewValCon0 |= 0x2u;                    /* set LCK Bit */

  SCU_WDTSCON0.U = NewValCon0;  /* write access and lock for Timeout mode */

  /* Read back to ensure protection release is executed */
  dummy = SCU_WDTSCON0.U;
  UNUSED_PARAMETER(dummy)
} /* SramEccTst_lResetSafetyENDINIT */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static void SramEccTst_lSetENDINIT                      **
**                        (const SramEccTst_WdtContextType* const WdtContext) **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters(in)   : WdtContext - Pointer to SramEccTst_WdtContextType       **
**                                 structure that was filled by preceding     **
**                                 SramEccTst_lResetENDINIT call.             **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Sets the ENDINIT bit in the appropriate CPU watchdog.   **
**                    Available for CPU0, CPU1 and CPU2. Proper password is   **
**                    calculated and restored on modify access.               **
**                    Enables interrupts and restores Wdt timer reload value. **
**                                                                            **
*******************************************************************************/
static void SramEccTst_lSetENDINIT
(
  const SramEccTst_WdtContextType* const WdtContext
)
{
  uint32 CoreID = ((uint32)MFCR(CPU_CORE_ID) & (uint32)SRAM_CORE_ID_MASK);
  SramEccTst_lSetCpuENDINIT((sint8)CoreID, WdtContext);
} /* SramEccTst_lSetENDINIT */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static void SramEccTst_lSetSafetyENDINIT                **
**                        (const SramEccTst_WdtContextType* const WdtContext) **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters(in)   : WdtContext - Pointer to SramEccTst_WdtContextType       **
**                                 structure that was filled by preceding     **
**                                 SramEccTst_lResetSafetyENDINIT call.       **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Sets the ENDINIT bit in the global safety watchdog.     **
**                    Proper password is calculated and restored on modify    **
**                    access. Enables interrupts and restores Wdt timer       **
**                    reload value.                                           **
**                                                                            **
*******************************************************************************/
static void SramEccTst_lSetSafetyENDINIT
(
  const SramEccTst_WdtContextType* const WdtContext
)
{
  uint32 NewValCon0;
  uint32 NewPw;                   /* next password to be used */
  uint32 NewRel;                  /* next timer reload to be used */
  volatile uint32 dummy;          /* ensure readback */

  /* Save old value */
  NewValCon0  = SCU_WDTSCON0.U;

  /* Get valid next password: */
  NewPw = NewValCon0 & SRAM_WDT_PASSWORD_MASK;

  /* - First generate proper password write value
       (include PW Bit8-15 and inverted PW Bit 2-7) */
  NewPw = (NewPw & SRAM_WDT_PASSWORD_UPPER_MASK) |
          ((~(NewPw & SRAM_WDT_PASSWORD_LOWER_MASK)) &
           SRAM_WDT_PASSWORD_LOWER_MASK);

  /* - Additionally auto sequence password enabled ? */
  if (SCU_WDTSSR.B.PAS != 0u)
  {
    /* Modify password with expected password by calculating new 14-bit LFSR
     * with characteristic polynomial x14+x13+x12+x2+1.
     */
    uint32 lfsr = NewPw;
    uint32 bit  = ((lfsr>>1) ^ (lfsr>>11) ^ (lfsr>>12) ^ (lfsr>>13)) & 0x0004u;
    NewPw       = (((lfsr << 1) | bit) & SRAM_WDT_PASSWORD_MASK);
  } /* if (SCU_WDTSSR.B.PAS != 0u) */

  /* Get valid next timer reload: */
  /* Timer check enabled ? */
  if (SCU_WDTSSR.B.TCS != 0u)
  {
    NewRel = (uint32)((~(uint32)SCU_WDTSSR.B.TIM) << 16);
  } /*if (SCU_WDTSSR.B.TCS != 0u) */
  else
  {
    NewRel = NewValCon0 & SRAM_WDT_RELOAD_MASK;
  } /*if (SCU_WDTSSR.B.TCS == 0u) */

  /* Build required password WDTCON0 value */
  NewValCon0  =  ((NewRel) |             /* new reload value  */
                  (NewPw)  |             /* new Password */
                  (1u));                 /* Clear LCK, keep ENDINIT set */

  SCU_WDTSCON0.U = NewValCon0;         /*  unlock with password access */

  /* Clear timer reload and restore saved and corrected reload value */
  NewValCon0 &= ~SRAM_WDT_RELOAD_MASK;

  /* Set timer value back to prior value and add ticks during timeout mode */
  NewValCon0 |= (WdtContext->WdtTimAndPw +
                 ((SCU_WDTSSR.U & (uint32)SRAM_WDT_RELOAD_MASK) -
                 (uint32)SDWT_TIMEOUT_MODE_RELOAD));

  /* Prepare old password to be restored with modify access*/
  NewValCon0 &= ~SRAM_WDT_PASSWORD_MASK;
  NewValCon0 |= (WdtContext->WdtTimAndPw &
                 (uint32)SRAM_WDT_PASSWORD_UPPER_MASK) |
                 ((~(WdtContext->WdtTimAndPw &
                     (uint32)SRAM_WDT_PASSWORD_LOWER_MASK))
                 & (uint32)SRAM_WDT_PASSWORD_LOWER_MASK);

  /* Prepare modify & lock access */
  NewValCon0 |= 3u;                    /* set LCK and ENDINIT Bit */
  SCU_WDTSCON0.U = NewValCon0;         /* write modify access and lock */

  /* Read back to ensure protection release is executed */
  dummy = SCU_WDTSCON0.U;
  UNUSED_PARAMETER(dummy)
} /* SramEccTst_lSetSafetyENDINIT */

/*******************************************************************************
** Traceability      : [cover parentID=]        [/cover]                      **
**                                                                            **
** Syntax           : static Std_ReturnType SramEccTst_lSmuClearAlarmStatus   **
**                        (uint8 AlarmGroup,                                  **
**                         uint8 AlarmPos)                                    **
**                                                                            **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non re-entrant                                          **
**                                                                            **
** Parameters(in)   : AlarmGroup : Alarm group register                       **
**                      AlarmPos : Alarm position within the requested group  **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : E_OK - Operation successfully performed                 **
**                    E_NOT_OK - Operation failed eg. due to invalid          **
**                      parameters.                                           **
**                                                                            **
** Description      : This service clears SMU alarm status of the requested   **
**                    alarm. It needs to be called after alarm status is read.**
**                                                                            **
** Note:            : This function replaces the Smu_ClearAlarmStatus, but    **
**                    without getting the SL_SMUDRIVER_SPNLCK_ID spin lock.   **
**                    It is assumed that this resource is free, because it    **
**                    has already been free at the start of the test and      **
**                    interrupts have to be disabled and remaining CPU cores  **
**                    to be in idle state when this test is executing.        **
**                                                                            **
*******************************************************************************/
static Std_ReturnType SramEccTst_lSmuClearAlarmStatus
(
  uint8 AlarmGroup,
  uint8 AlarmPos
)
{
  Std_ReturnType            RetVal;
  uint32                    Timeout;
  uint32                    AlarmStatusReadback;
  SramEccTst_WdtContextType WdtContext;

  RetVal = E_OK;

  /* SMU alarm can be cleared in any state */
  /* All SMU Groups (0 to 6) are allowed to clear alarm status */
  /* NOTE: Some of the AlarmPos in some AlarmGroup are reserved i.e.
         not valid even if its with in the maximum range.
         The check of this is not done. Action on these alarms has no effect
         on the hardware.
    */
  if((AlarmGroup > (uint8)SRAM_SMU_MAX_ALARM_GROUP) ||
     (AlarmPos > (uint8)SRAM_SMU_MAX_ALARM_POS))
  {
     /* Invalid Alarm Group */
     RetVal = (Std_ReturnType)E_NOT_OK;
  } /* if((AlarmGroup > (uint8)SRAM_SMU_MAX_ALARM_GROUP) ||
          (AlarmPos > (uint8)SRAM_SMU_MAX_ALARM_POS)) */
  else
  {
    /* disable the write-protection for registers */
     SramEccTst_lResetSafetyENDINIT(&WdtContext);

    /* Write SMU_ASCE(0) in CMD register */
    SMU_CMD.U = SMU_ASCE_COMMAND;

    /* Write 1 in AG bit to clear alarm */
    MODULE_SMU.AG[AlarmGroup].U =
                        (unsigned_int)((uint32)0x1U << (uint32)AlarmPos);

    /* Restore back the write-protection for registers */
    SramEccTst_lSetSafetyENDINIT(&WdtContext);

    /*Read back AG register to validate the Clear */
    Timeout = 0U;
    do
    {
      /* Read Alarm status */
      AlarmStatusReadback =
         (((uint32)(MODULE_SMU.AG[AlarmGroup].U) >>
             AlarmPos) & 0x1U);

      Timeout++;

    }while((Timeout < SRAM_SMU_AGSTATUS_TIMEOUT) &&
           (AlarmStatusReadback != 0U));

    if(AlarmStatusReadback != 0U)
    {
      RetVal = (Std_ReturnType)E_NOT_OK;
    } /* if(AlarmStatusReadback != 0U) */
  } /* if((AlarmGroup <= (uint8)SRAM_SMU_MAX_ALARM_GROUP) &&
          (AlarmPos <= (uint8)SRAM_SMU_MAX_ALARM_POS)) */

  return RetVal;

}/* SramEccTst_lSmuClearAlarmStatus */

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : LOCAL_INLINE uint32 SramEccTst_lCalcAlmCounterCrc                 **
**          (                                                                 **
**            void                                                            **
**          )                                                                 **
**                                                                            **
** Description : Calculates the CRC over all members of the                   **
**               SramEccTst_UnexpAlm unexpected alarm structure.              **
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
LOCAL_INLINE uint32 SramEccTst_lCalcAlmCounterCrc
(
  void
)
{
  uint32  Result;

  Result = (uint32)CRC32(SramEccTst_UnexpAlm.Correctable,
                         SramEccTst_UnexpAlm.Uncorrectable);
  Result = (uint32)CRC32(Result, SramEccTst_UnexpAlm.Address);
  Result = (uint32)CRC32(Result, SramEccTst_UnexpAlm.ErrTrkOvf);

 return Result;
} /* SramEccTst_lCalcAlmCounterCrc */

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : static uint32 SramEccTst_lCalcBackupCrc                           **
**          (                                                                 **
**            const uint8 MemIdx,                                             **
**            const SramEccTst_BackupDataType* const BackupData               **
**          )                                                                 **
**                                                                            **
** Description : Calculates the CRC over all members of the backup data       **
**               structure.                                                   **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters(in)   : MemIdx - Index of memory to be tested                   **
**                   BackupData - Pointer to backup data over which the CRC   **
**                                is to be calculated                         **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value : Requested backup data CRC value                             **
**                                                                            **
*******************************************************************************/
static uint32 SramEccTst_lCalcBackupCrc
(
  const uint8 MemIdx,
  const SramEccTst_BackupDataType* const BackupData
)
{
  uint32  i;
  uint32  Result;

  Result = (uint32)CRC32((uint32)BackupData->AlmActionBackupSbeCorr,
                         (uint32)BackupData->AlmActionBackupUcErr);
  Result = (uint32)CRC32(Result, (uint32)BackupData->AlmActionBackupAdrErr);
  Result = (uint32)CRC32(Result, (uint32)BackupData->AlmActionBackupAdrBufFull);

  if (SRAM_DAM == MemIdx)
  {    
    Result = (uint32)CRC32(Result, (uint32)BackupData->AlmActionBackupLmuEccOnlnMon);
  }
  Result = (uint32)CRC32(Result, (uint32)BackupData->GetAlmActionResult);
  Result = (uint32)CRC32(Result, BackupData->ClockBackup1);
  Result = (uint32)CRC32(Result, BackupData->MBistEnable);  
  Result = (uint32)CRC32(Result, BackupData->MemTest);
  /* Calculate CRC over the whole memory backup storage; even if not all
   * backup storage is actually used, an unintended modification would indicate
   * a problem:
   */
  for (i = 0U; i < (SRAM_MAX_RDBFL_REGS * SRAM_MAX_NR_OF_WORDLINES); i++)
  {
    Result = (uint32)CRC32(Result, (uint32)BackupData->MemContentBackup[i]);
  }
  Result = (uint32)CRC32(Result, (uint32)BackupData->MemBackupValid);
  Result = (uint32)CRC32(Result, (uint32)BackupData->MtuClcDisr);
  Result = (uint32)CRC32(Result, (uint32)BackupData->Eccs);
  Result = (uint32)CRC32(Result, (uint32)BackupData->Range);
#if (MCAL_NO_OF_CORES == 1U)
  Result = (uint32)CRC32(Result, (uint32)BackupData->CpuCacheBypass);
#endif /* (MCAL_NO_OF_CORES == 1U) */

 return Result;
} /* SramEccTst_lCalcBackupCrc */
/*******************************************************************************
** Traceability      : [cover parentID=]        [/cover]                      **
**                                                                            **
** Syntax           : Sl_TstRsltType SranEccTst_SramEccTst                    **
**                                      (const Sl_ParamSetType ParamSetIndex, **
**                                       const uint8 TstSeed,                 **
**                                       uint32* const TstSignature);         **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : ParamSetIndex : Identifies the parameter set to be      **
**                                    used for test execution, valid range    **
**                                    0..SRAMECC_TST_CFG_PARAM_COUNT,         **
**                                    depending on configuration              **
**                    TstSeed : Seed to be used for generating the signature  **
**                                                                            **
** Parameters (out) : TstSignature : Test signature generated by the test     **
**                                                                            **
** Return value     : SRAMECC_SUCCESS - Test succeeded                        **
**                    <Error ID> - Type of error during test                  **
**                                                                            **
** Description      : API provided for the SRAM ECC test.                     **
**                    It is responsible for test preparation, test execution  **
**                    and final test restoration.                             **
**                                                                            **
*******************************************************************************/
Sl_TstRsltType SramEccTst_SramEccTst 
(
  const Sl_ParamSetType ParamSetIndex,
  const uint8 TstSeed,
  uint32* const TstSignature
)
{

  Sl_TstRsltType            Result = SRAMECC_NOTEXECUTED;
  Sl_TstRsltType            ResultTmp;
  SramEccTst_BackupDataType BackupData;
  volatile uint8            i;

  /* Initialize test signature: */
  *TstSignature = (uint32)CRC32((uint32)TEST_ID_SRAMECC_TST,(uint32)TstSeed);

  /* Initialize unexpected alarm counter CRC: */
  SramEccTst_UnexpAlm.Crc = SramEccTst_lCalcAlmCounterCrc();

  /* Validate the input parameter */
  if(ParamSetIndex >= (Sl_ParamSetType)SRAMECC_TST_CFG_PARAM_COUNT)
  {
    Result = SRAMECC_INVPARAMERR;
  } /* if(ParamSetIndex >= (Sl_ParamSetType)SRAMECC_TST_CFG_PARAM_COUNT) */
  else
  {
    ResultTmp = SramEccTst_lEnableMtuClock(&BackupData);
    if (SRAMECC_SUCCESS != ResultTmp)
    {
      Result = ResultTmp;
    } /* if (SRAMECC_SUCCESS != ResultTmp) */
    else
    {
      /* Loop through each bit in MemorySelect parameter and check if testing is
       * enabled for the respective SRAM:
       */
      for (i = 0U;
           (i < SRAMECCTST_MEMORY_COUNT) && (SRAMECC_NOTEXECUTED == Result);
           i++)
      {
        /* Check if memory testing is enabled: */
        if ((SramEccTst_ConfigRoot[ParamSetIndex].MemorySelect &
             ((uint32)1U << i)) > (uint32)0U)
        {
          /* Check if selected memory is a supported SRAM: */
          if (NULL_PTR != SramEccTst_kMemDef[i])
          {
            #if (CHIP_ID == 21U) || (CHIP_ID == 22U) || (CHIP_ID == 23U) || (CHIP_ID == 24U)
            if(i == (uint8)SRAM_CPU0_DSPR)
            {
              ResultTmp = SramEccTst_lTestDspr0SingleCore(TstSignature, &BackupData);
            }
            else
            {
            #endif
            ResultTmp = SramEccTst_lTestMemory(i,
                                               ParamSetIndex,
                                               TstSignature,
                                               &BackupData);
            #if (CHIP_ID == 21U) || (CHIP_ID == 22U) || (CHIP_ID == 23U) || (CHIP_ID == 24U)
            }
            #endif            
            if (SRAMECC_SUCCESS != ResultTmp)
            {
              Result = ResultTmp;
            } /* if (SRAMECC_SUCCESS != ResultTmp) */
          } /* if ((SramEccTst_kValidMemMask[i] & (1U << j)) > 0U) */
          else
          {
            Result = SRAMECC_CONFIGERR;
          } /* if ((SramEccTst_kValidMemMask[i] & (1U << j)) == 0U) */
        } /* if ((SramEccTst_ConfigRoot[ParamSetIndex].MemorySelect[i] &
                  (1U << j)) > 0U) */
      } /* for (i = 0U;
                (i < SRAMECCTST_MEMORY_COUNT) && (SRAMECC_NOTEXECUTED ==
                 Result);
                i++) */

      ResultTmp = SramEccTst_lRestoreMtuClock(&BackupData);
      if (SRAMECC_SUCCESS != ResultTmp)
      {
        Result = ResultTmp;
      } /* if (SRAMECC_SUCCESS != Result) */
      else if (SRAMECC_NOTEXECUTED == Result)
      {
        Result = SRAMECC_SUCCESS;
      } /* else if (SRAMECC_NOTEXECUTED == Result) */
      else
      {
        /* Nothing to do */
      } /* else if (SRAMECC_NOTEXECUTED != Result) */
  
    } /* if (SRAMECC_SUCCESS == ResultTmp) */
  } /* if(ParamSetIndex < (Sl_ParamSetType)SRAMECC_TST_CFG_PARAM_COUNT) */

  /* Add final test result to test signature: */
  *TstSignature = (uint32)CRC32(*TstSignature, (uint32)Result);

  return Result;
} /* SramEccTst_SramEccTst */

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : SramEccTst_UnexpAlarmType*                                        **
**          SramEccTst_GetUnexpEccAlmListPtr(void)                            **
**                                                                            **
** Description : Returns a pointer to a list that contains the number         **
**               of unexpected ECC alarms that have been cleared before a     **
**               test run.                                                    **
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
** Return value :   SramEccTst_UnexpAlmType* Pointer to list of unexpected    **
**                                           Ecc alarms cleared before a test **
**                                           run or NULL_PTR if the counters  **
**                                           for unexpected SMU alarms has    **
**                                           been corrupted.                  **
**                                                                            **
*******************************************************************************/
SramEccTst_UnexpAlarmType* SramEccTst_GetUnexpEccAlmListPtr(void)
{
  SramEccTst_UnexpAlarmType*  Result = NULL_PTR;

  if (SramEccTst_lCalcAlmCounterCrc() == SramEccTst_UnexpAlm.Crc)
  {
    Result = &SramEccTst_UnexpAlm;
  } /* if (SramEccTst_lCalcAlmCounterCrc() == SramEccTst_UnexpAlm.Crc) */

  return Result;
} /* SramEccTst_GetUnexpEccAlmListPtr */

#define IFX_SRAM_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"


#if (CHIP_ID == 21U) || (CHIP_ID == 22U) || (CHIP_ID == 23U) || (CHIP_ID == 24U)

#define IFX_SRAM_START_SEC_CODE_NO_OPTIMIZED_ASIL_B
#include "Ifx_MemMap.h"

#ifdef __TASKING__
PRAGMA_ALL(OPTIMIZE_0)
#endif

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : static uint32 SramEccTst_lCalcBackupCrcSingleCore                 **
**          (                                                                 **
**            const SramEccTst_BackupDataType* const BackupData               **
**          )                                                                 **
**                                                                            **
** Description : Calculates the CRC over  members of the backup data          **
**               structure backed up for Single core system DSPR0 testing     **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) : BackupData - Pointer to backup data over which the CRC   **
**                                is to be calculated                         **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value : Requested backup data CRC value                             **
**                                                                            **
*******************************************************************************/
static uint32 SramEccTst_lCalcBackupCrcSingleCore
(
  const SramEccTst_BackupDataType* const BackupData
)
{
  uint32  i;
  uint32  Result;

  Result = (uint32)CRC32((uint32)BackupData->AlmActionBackupSbeCorr,
                         (uint32)BackupData->AlmActionBackupUcErr);
  Result = (uint32)CRC32(Result, (uint32)BackupData->AlmActionBackupAdrErr);
  Result = (uint32)CRC32(Result, (uint32)BackupData->AlmActionBackupAdrBufFull);
  Result = (uint32)CRC32(Result, (uint32)BackupData->GetAlmActionResult);

  /* Calculate CRC over the whole memory backup storage; even if not all
   * backup storage is actually used, an unintended modification would indicate
   * a problem:
   */
  for (i = 0U; i < (uint32)(SRAM_DSPR0_MEMORY_TEST_SIZE); i++)
  {
    Result = (uint32)CRC32(Result, (uint32)BackupData->MemContentBackup[i]);
  }
  Result = (uint32)CRC32(Result, (uint32)BackupData->MemBackupValid);
  Result = (uint32)CRC32(Result, (uint32)BackupData->MtuClcDisr);
  Result = (uint32)CRC32(Result, (uint32)BackupData->Eccs);
  Result = (uint32)CRC32(Result, (uint32)BackupData->Range);
  #if(CHIP_ID == 23U)
  Result = (uint32)CRC32(Result, (uint32)BackupData->Eccs2);
  Result = (uint32)CRC32(Result, (uint32)BackupData->Range2); 
  #endif
  Result = (uint32)CRC32(Result, (uint32)BackupData->CpuCacheBypass);

 return Result;
} /* SramEccTst_lCalcBackupCrcSingleCore */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static Sl_TstRsltType SramEccTst_lInitSingleCore        **
**                    (SramEccTst_BackupDataType* const BackupData)           **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : BackupData - Pointer to backup data struct of SRAM test **
**                                                                            **
** Return value     : SRAMECC_SUCCESS - Initialization succeeded              **
**                    <Error ID> - Type of error during test initialization   **
**                                                                            **
** Description      : This function take the backup copy of all SFR values    **
**                    and SMU alarm actions that will be modified by the test.**
**                    Also checks whether the SMU alarms used by the test are **
**                    in the expected state.                                  **
**                    Furthermore it sets up the SMU alarm actions to         **
**                    No action of all SMU alarms triggered by the test.      **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType SramEccTst_lInitSingleCore
(
  SramEccTst_BackupDataType* const BackupData
)
{
  register uint32            EccsBackup  =    0U;
  register uint32            RangeBackup =    0U;  
  register uint32            Result      =    SRAMECC_NOTEXECUTED; 

  uint8                      Count;
  volatile uint32            Dummy;
  SramEccTst_WdtContextType  WdtContext;  
  
  /* Invalidate backup values: */
  BackupData->MemBackupValid = (boolean)FALSE;
  BackupData->CpuCacheBypass = (uint8)SRAM_INV_BACKUP_VALUE;  
  BackupData->Eccs = (uint16)SRAM_INV_BACKUP_VALUE;
  BackupData->Range = (uint16)SRAM_INV_BACKUP_VALUE;  
  #if(CHIP_ID == 23U)  
  BackupData->Eccs2 = (uint16)SRAM_INV_BACKUP_VALUE;
  BackupData->Range2 = (uint16)SRAM_INV_BACKUP_VALUE;   
  #endif
  Result = SramEccTst_lInitSmuAlarms(SRAM_CPU0_DSPR, BackupData);

  if (SRAMECC_SUCCESS == Result)
  {
    /* Disable CPU instruction caching: */
    SramEccTst_lDisableCaching(BackupData);
    /* Backup memory used by the test: */
    
    for(Count = 0U; Count < SRAM_DSPR0_MEMORY_TEST_SIZE; Count++)
    {
      BackupData->MemContentBackup[Count] = ((uint16*)SRAM_DSPR0_ADDRESS)[Count];
    }
    BackupData->MemBackupValid = (boolean)TRUE;

    /* Enable MBIST controller of RAM under test: */
    SramEccTst_lResetSafetyENDINIT(&WdtContext);
    DSYNC();
    Dummy = *(uint32*)(SRAM_DSPR0_ADDRESS);
    UNUSED_PARAMETER(Dummy)    
    MTU_MEMTEST0.B.CPU0DSEN = 1U;
    #if (CHIP_ID == 23U) 
    Dummy = ((uint32*)SRAM_DSPR0_ADDRESS)[SRAM_DSPR0_WORDS_PER_WORDLINE];        
    MTU_MEMTEST0.B.CPU0DS2EN= 1U;  
    #endif
    /* Wait for RAM initialization to complete: */
    /*no timeout is given for this loop. If memory Initialization fails due any
     reason, code execution further can not proceed as usual as MBist is enabled
     for DSPR0 which means stack and CSA is not available for code execution. In
     this case, we should wait here endlessly and a mechanism should be implemented
     at customer side like resetting through supervisor watchdog to reset the system*/

    do
    {
      __asm("nop");
    } while ((MTU_MEMSTAT0.B.CPU0DSAIU != 0U)
              #if (CHIP_ID == 23U) 
              ||(MTU_MEMSTAT0.B.CPU0DS2AIU != 0U)
              #endif
              );
  
    /*take backup of RANGE and ECCS registers*/
    RangeBackup = MODULE_MC14.RANGE.U;
    #if (CHIP_ID == 23U)     
    RangeBackup|= ((uint32)MODULE_MC27.RANGE.U << SRAM_HALF_WORD_SIZE); 
    #endif
    EccsBackup  = MODULE_MC14.ECCS.U;      
    #if (CHIP_ID == 23U)       
    EccsBackup|= ((uint32)MODULE_MC27.ECCS.U << SRAM_HALF_WORD_SIZE); 
    #endif
     
    MTU_MEMTEST0.B.CPU0DSEN= 0U;
    #if (CHIP_ID == 23U) 
    MTU_MEMTEST0.B.CPU0DS2EN= 0U;  
    #endif    
    /* Wait for RAM initialization to complete: */
    /*no timeout is given for this loop. If memory Initialization fails due any
     reason, code execution further can not proceed as usual as MBist is enabled
     for DSPR0 which means stack and CSA is not available for code execution. In
     this case, we should wait here endlessly and a mechanism should be implemented
     at customer side like resetting through supervisor watchdog to reset the system*/

    do
    {
      __asm("nop");
    } while ((MTU_MEMSTAT0.B.CPU0DSAIU != 0U)
              #if (CHIP_ID == 23U) 
              ||(MTU_MEMSTAT0.B.CPU0DS2AIU != 0U)
              #endif
              );
    

    BackupData->Eccs =  (uint16)(EccsBackup&SRAM_MASK_LOWER_HALFWORD);
    BackupData->Range = (uint16)(RangeBackup&SRAM_MASK_LOWER_HALFWORD); 
    #if(CHIP_ID == 23U)
    BackupData->Eccs2 = (uint16)(EccsBackup>>SRAM_HALF_WORD_SIZE);    
    BackupData->Range2 =(uint16)(RangeBackup>>SRAM_HALF_WORD_SIZE);  
    #endif
    SramEccTst_lSetSafetyENDINIT(&WdtContext);  	
  } /* if (MTU_MEMSTAT0.B.CPU0DSAIU) */      


  /* Calculate backup data crc: */
  BackupData->Crc = SramEccTst_lCalcBackupCrcSingleCore(BackupData);
  

  return Result;
} /* SramEccTst_lInit */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static Sl_TstRsltType SramEccTst_lRestoreSingleCore     **
**                       (const SramEccTst_BackupDataType* const BackupData)  **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : MemIdx - Index of the memory under test; Refer to       **
**                             definition of supported SRAMs in               **
**                             SramEccTst_MemDef.h for a list of supported    **
**                             values                                         **
**                    Config - config Parameter index                         **
**                    BackupData - Pointer to backup data struct of SRAM test **
**                                                                            **
** Parameters (out) : BackupData - Pointer to backup data struct of SRAM test **
**                                                                            **
** Return value     : SRAM_SUCCESS - Test restoration succeeded               **
**                    <Error ID> - Type of error during test restoration      **
**                                                                            **
** Description      : This function restores all SFRs, SMU alarm actions and  **
**                    memory content that has been modified by the test.      **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType SramEccTst_lRestoreSingleCore
(
  const SramEccTst_BackupDataType* const BackupData
)

{
  register uint32            EccsBackup      = 0U;
  register uint32            RangeBackup     = 0U;  
  register uint32            Result          = SRAMECC_NOTEXECUTED;

  uint8                      Count;
  volatile uint32            Dummy;
  SramEccTst_WdtContextType  WdtContext;

  /* Check backup data crc: */
  if (SramEccTst_lCalcBackupCrcSingleCore(BackupData) != BackupData->Crc)
  {
    Result = SRAMECC_DATACORRUPTION;
  } /* if (SramEccTst_lCalcBackupCrc(BackupData) != BackupData->Crc) */
  else
  {
    if(BackupData->Eccs != (uint16)SRAM_INV_BACKUP_VALUE)
    {
      EccsBackup = BackupData->Eccs;
      RangeBackup = BackupData->Range;
      #if(CHIP_ID == 23U)
      EccsBackup|= ((uint32)(BackupData->Eccs2)<<SRAM_HALF_WORD_SIZE);      
      RangeBackup|= ((uint32)(BackupData->Range2)<<SRAM_HALF_WORD_SIZE);
      #endif
      /* Enable MBIST controller of RAM under test: */
      SramEccTst_lResetSafetyENDINIT(&WdtContext);
      DSYNC();
      Dummy = *(uint32*)(SRAM_DSPR0_ADDRESS);
 
      UNUSED_PARAMETER(Dummy)   
      MTU_MEMTEST0.B.CPU0DSEN = 1U;
      #if (CHIP_ID == 23U) 
      Dummy = ((uint32*)SRAM_DSPR0_ADDRESS)[SRAM_DSPR0_WORDS_PER_WORDLINE];       
      MTU_MEMTEST0.B.CPU0DS2EN= 1U;  
      #endif  
      /* Wait for RAM initialization to complete: */
      /*no timeout is given for this loop. If memory Initialization fails due any
       reason, code execution further can not proceed as usual as MBist is enabled
       for DSPR0 which means stack and CSA is not available for code execution. In
       this case, we should wait here endlessly and a mechanism should be implemented
       at customer side like resetting through supervisor watchdog to reset the system*/
  
      do
      {
        __asm("nop");
      } while ((MTU_MEMSTAT0.B.CPU0DSAIU != 0U)
              #if (CHIP_ID == 23U) 
              ||(MTU_MEMSTAT0.B.CPU0DS2AIU != 0U)
              #endif
              );
    
      /* RAM initialization completed? */
      /*Restore values of RANGE and ECCS registers*/    
  
      MODULE_MC14.ECCS.U  = (uint16)(EccsBackup&SRAM_MASK_LOWER_HALFWORD);    
      MODULE_MC14.RANGE.U = (uint16)(RangeBackup&SRAM_MASK_LOWER_HALFWORD);
      #if (CHIP_ID == 23U) 
      MODULE_MC27.ECCS.U  = (uint16)(EccsBackup>>SRAM_HALF_WORD_SIZE);    
      MODULE_MC27.RANGE.U = (uint16)(RangeBackup>>SRAM_HALF_WORD_SIZE);
      #endif
      MTU_MEMTEST0.B.CPU0DSEN= 0U;
      #if (CHIP_ID == 23U) 
      MTU_MEMTEST0.B.CPU0DS2EN= 0U;  
      #endif
      
      /* Wait for RAM initialization to complete: */
      /*no timeout is given for this loop. If memory Initialization fails due any
       reason, code execution further can not proceed as usual as MBist is enabled
       for DSPR0 which means stack and CSA is not available for code execution. In
       this case, we should wait here endlessly and a mechanism should be implemented
       at customer side like resetting through supervisor watchdog to reset the system*/
  
      do
      {
        __asm("nop");
      } while ((MTU_MEMSTAT0.B.CPU0DSAIU != 0U)
              #if (CHIP_ID == 23U) 
              ||(MTU_MEMSTAT0.B.CPU0DS2AIU != 0U)
              #endif
              );
  
      SramEccTst_lSetSafetyENDINIT(&WdtContext);    
    }
    /* Backup succeeded? */
    if (BackupData->MemBackupValid == (boolean)TRUE)
    {
      /* Restore memory content overwritten by the test: */
      for(Count = 0U; Count < SRAM_DSPR0_MEMORY_TEST_SIZE; Count++)
      {
        ((uint16*)SRAM_DSPR0_ADDRESS)[Count] = BackupData->MemContentBackup[Count];
      }   
  
    } /* if (BackupData->MemBackupValid == (boolean)TRUE) */
    if(BackupData->CpuCacheBypass != (uint8)SRAM_INV_BACKUP_VALUE)
    {
      /* Restore CPU instruction caching: */
      SramEccTst_lRestoreCaching(BackupData);
    } /* if (BackupData->CpuCacheBypass != (uint8)SRAM_INV_BACKUP_VALUE) */
    if (E_OK == BackupData->GetAlmActionResult)
    {
      /* Restore SMU alarm actions: */
      Result = SramEccTst_lRestoreSmuAlarms(SRAM_CPU0_DSPR, BackupData);        
    }/*if (E_OK == BackupData->GetAlmActionResult)*/
	
    /* Clear error flags for both memory controllers for CPU0 DSPR */
    /*dummy write with 0x780F as a workaround for 
    functional deviation MTU_TC.005*/
    MC14_ECCD.U = SRAM_DUMMY_ECCD_WRITE;
    MC14_ECCD.U &= ~(uint16)(((uint32)IFX_MC_ECCD_SERR_MSK <<
                           (uint32)IFX_MC_ECCD_SERR_OFF) |
                          ((uint32)IFX_MC_ECCD_CERR_MSK <<
                           (uint32)IFX_MC_ECCD_CERR_OFF) |
                          ((uint32)IFX_MC_ECCD_UERR_MSK <<
                           (uint32)IFX_MC_ECCD_UERR_OFF) |
                          ((uint32)IFX_MC_ECCD_AERR_MSK <<
                           (uint32)IFX_MC_ECCD_AERR_OFF));

    /* Clear error tracking information: */
    MC14_ECCD.U |= (uint16)((uint32)IFX_MC_ECCD_TRC_MSK <<
                         (uint32)IFX_MC_ECCD_TRC_OFF);
	#if(CHIP_ID == 23U)					 
    MC27_ECCD.U = SRAM_DUMMY_ECCD_WRITE;
    MC27_ECCD.U &= ~(uint16)(((uint32)IFX_MC_ECCD_SERR_MSK <<
                           (uint32)IFX_MC_ECCD_SERR_OFF) |
                          ((uint32)IFX_MC_ECCD_CERR_MSK <<
                           (uint32)IFX_MC_ECCD_CERR_OFF) |
                          ((uint32)IFX_MC_ECCD_UERR_MSK <<
                           (uint32)IFX_MC_ECCD_UERR_OFF) |
                          ((uint32)IFX_MC_ECCD_AERR_MSK <<
                           (uint32)IFX_MC_ECCD_AERR_OFF));

    /* Clear error tracking information: */
    MC27_ECCD.U |= (uint16)((uint32)IFX_MC_ECCD_TRC_MSK <<
                         (uint32)IFX_MC_ECCD_TRC_OFF);						 
	#endif
  }

  if(Result == SRAMECC_NOTEXECUTED)
  {
    Result = SRAMECC_SUCCESS; 
  }

  return Result;  

} /* SramEccTst_lRestore */

/*******************************************************************************
** Traceability     :[cover parentID=]        [/cover]                        **
**                                                                            **
** Syntax           :static Sl_TstRsltType SramEccTst_lChkAddressMonSingleCore**
**                       (void)                                               **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : TstSignature - Test signature generated by the test     **
**                                                                            **
** Return value     : SRAM_SUCCESS - Address line ECC error signaling test    **
**                                   succeeded                                **
**                    <Error ID> - Type of error during address line test     **
**                                                                            **
** Description      : This function tests the correct signaling of address    **
**                    line ECC errors to the SMU.                             **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType SramEccTst_lChkAddressMonSingleCore
(
  uint32* const TstSignature
)
{
  /*ResultLoopCount variable is shared for using as counter, timeout and result.
  For writing into rdbfl registers, it is used as counter
  It is used as timeout for waiting for SMU alarms
  Used as result in all other places*/
  register uint32                    ResultLoopCount = 0U;
  register uint32                    TstSignatureTemp = *TstSignature;  
  register Ifx_MC*                   CurrentMC;
  register uint32                    i;
  
  Sl_TstRsltType                     Result = SRAMECC_NOTEXECUTED; 
  uint8                              Count;
  Ifx_MC*                            MemoryController[SRAMECC_DSPR0_MC_SINGLECORE]=
                                     {
                                       &MODULE_MC14, 
                                       #if (CHIP_ID == 23U) 
                                       &MODULE_MC27
                                       #endif
                                     };
  volatile uint32                    Dummy;
  SramEccTst_WdtContextType          WdtContext;

  for(Count = 0U; (Count < SRAMECC_DSPR0_MC_SINGLECORE) &&
                 (SRAMECC_NOTEXECUTED == Result); Count++)
  {  
    CurrentMC = MemoryController[Count];
    /* Enable MBIST controller of RAM under test: */
    SramEccTst_lResetSafetyENDINIT(&WdtContext);
    DSYNC();
    Dummy = ((uint32*)SRAM_DSPR0_ADDRESS)[Count*SRAM_DSPR0_WORDS_PER_WORDLINE];
    UNUSED_PARAMETER(Dummy)    
    
    MTU_MEMTEST0.B.CPU0DSEN = 1U;
    #if (CHIP_ID == 23U) 
    MTU_MEMTEST0.B.CPU0DS2EN= 1U;  
    #endif   
    /* Wait for RAM initialization to complete: */
    /*no timeout is given for this loop. If memory Initialization fails due any
     reason, code execution further can not proceed as usual as MBist is enabled
     for DSPR0 which means stack and CSA is not available for code execution. In
     this case, we should wait here endlessly and a mechanism should be implemented
     at customer side like resetting through supervisor watchdog to reset the system*/
    
    do
    {
      __asm("nop");
    } while ((MTU_MEMSTAT0.B.CPU0DSAIU != 0U)
              #if (CHIP_ID == 23U) 
              ||(MTU_MEMSTAT0.B.CPU0DS2AIU != 0U)
              #endif
              );
  
    /* Clear ECCD error flags: */
    CurrentMC->ECCD.U &= ~(uint16)(((uint32)IFX_MC_ECCD_SERR_MSK <<
                             (uint32)IFX_MC_ECCD_SERR_OFF) |
                            ((uint32)IFX_MC_ECCD_CERR_MSK <<
                             (uint32)IFX_MC_ECCD_CERR_OFF) |
                            ((uint32)IFX_MC_ECCD_UERR_MSK <<
                             (uint32)IFX_MC_ECCD_UERR_OFF) |
                            ((uint32)IFX_MC_ECCD_AERR_MSK <<
                             (uint32)IFX_MC_ECCD_AERR_OFF));  
  
    /* Write valid data to the first wordline to avoid correctable and
           uncorrectable errors during the address error test:
     */
     /*ResultLoopCount is used as count here*/
    for (ResultLoopCount = 0U; ResultLoopCount < SRAM_RFBFL_REGS_COUNT_DSPR0; ResultLoopCount++)
    {
      CurrentMC->RDBFL[ResultLoopCount].U = SramEccTst_kNoErrPtrn[ResultLoopCount];
    } /* for (ResultLoopCount.B = 0U; ResultLoopCount.B < SRAM_RFBFL_REGS_COUNT_DSPR0; ResultLoopCount.B++) */      
    /* Select address */
    CurrentMC->RANGE.U = 0U;
    DSYNC();
  
    /* Configure writing of single memory address: */
    CurrentMC->CONFIG0.U = (uint16)(((uint32)SRAM_CONFIG0_NUMACCS_1 <<
                              (uint32)IFX_MC_CONFIG0_NUMACCS_OFF) |
                             ((uint32)SRAM_CONFIG0_ACCSTYPE_WR <<
                              (uint32)IFX_MC_CONFIG0_ACCSTYPE_OFF));
    CurrentMC->CONFIG1.U = 0U;
  
    /* Start write operation: */
  
    CurrentMC->MCONTROL.U = (uint16)(((uint32)IFX_MC_MCONTROL_DIR_MSK <<
                               (uint32)IFX_MC_MCONTROL_DIR_OFF) |
                              ((uint32)IFX_MC_MCONTROL_START_MSK <<
                               (uint32)IFX_MC_MCONTROL_START_OFF)|
                               ((uint32)MC_MCONTROL_USERED_MSK <<
                               (uint32)MC_MCONTROL_USERED));
    CurrentMC->MCONTROL.U = (uint16)(((uint32)IFX_MC_MCONTROL_DIR_MSK <<
                              (uint32)IFX_MC_MCONTROL_DIR_OFF)|
                              ((uint32)MC_MCONTROL_USERED_MSK <<
                               (uint32)MC_MCONTROL_USERED));
     /*ResultLoopCount is used as count here*/
    for(ResultLoopCount = 0U; ResultLoopCount < SRAM_MBIST_OPERATION_WAIT; ResultLoopCount++)
    {
      __asm("nop");
    }   
    /*ResultLoopCount is used as Result here*/    
    ResultLoopCount = SRAMECC_NOTEXECUTED;
    /* Test signaling of address errors: */
    for (i = 1U; (i <= SRAM_ADDR_ERR_TEST_COUNT_SINGLECORE) &&
                 (SRAMECC_NOTEXECUTED== ResultLoopCount); i++)     
    {
      CurrentMC->ECCS.U &= ~(uint16)((uint32)IFX_MC_ECCS_SFLE_MSK <<
                            (uint32)IFX_MC_ECCS_SFLE_OFF);
      CurrentMC->ECCS.U |= (uint16)(i << IFX_MC_ECCS_SFLE_OFF);
  

      /* Read memory: */
    
      /* Configure reading of single memory address: */
      CurrentMC->CONFIG0.U = (uint16)(((uint32)SRAM_CONFIG0_NUMACCS_1 <<
                                (uint32)IFX_MC_CONFIG0_NUMACCS_OFF) |
                               ((uint32)SRAM_CONFIG0_ACCSTYPE_RD <<
                                (uint32)IFX_MC_CONFIG0_ACCSTYPE_OFF));
      CurrentMC->CONFIG1.U = 0U;
    
      CurrentMC->MCONTROL.U = (uint16)(((uint32)IFX_MC_MCONTROL_DIR_MSK <<
                                 (uint32)IFX_MC_MCONTROL_DIR_OFF) |
                                ((uint32)IFX_MC_MCONTROL_START_MSK <<
                                 (uint32)IFX_MC_MCONTROL_START_OFF)|
                                ((uint32)MC_MCONTROL_USERED_MSK <<
                                 (uint32)MC_MCONTROL_USERED));
      CurrentMC->MCONTROL.U = (uint16)(((uint32)IFX_MC_MCONTROL_DIR_MSK <<
                                (uint32)IFX_MC_MCONTROL_DIR_OFF)|
                                ((uint32)MC_MCONTROL_USERED_MSK <<
                                 (uint32)MC_MCONTROL_USERED));
     /*ResultLoopCount is used as count below*/
      for(ResultLoopCount=0U; ResultLoopCount < SRAM_MBIST_OPERATION_WAIT; ResultLoopCount++)
      {
        __asm("nop");
      }    
     /*ResultLoopCount is used as Timeout below*/      
      ResultLoopCount = SRAMECC_SMU_ALM_TIMEOUT;
      
      /* Wait for expected SMU alarm: */
      while(((SMU_AG0.U & 0x00001000U)== 0U ) && (ResultLoopCount> 0U))
      {
        ResultLoopCount= ResultLoopCount - 1U;
      } /* while(((SMU_AG0.U & 0x00001000)== 0U ) && (LoopCount > 0U)) */  
      
     /*ResultLoopCount is used as Result below*/                        
      if((SMU_AG0.U & 0x00001000U)== 0U )
      {
        ResultLoopCount = SRAMECC_SMU_ALMSTSERR;
      }     
      else
      {
        ResultLoopCount = SRAMECC_NOTEXECUTED;
      }
      /* Clear error flags */
      CurrentMC->ECCD.U &= ~(uint16)(((uint32)IFX_MC_ECCD_SERR_MSK <<
                               (uint32)IFX_MC_ECCD_SERR_OFF) |
                              ((uint32)IFX_MC_ECCD_AERR_MSK <<
                               (uint32)IFX_MC_ECCD_AERR_OFF)); 
      /* Update test signature: */
      TstSignatureTemp = SMU_AG0.U & ((uint32)1U << SRAM_ADDMON_ALMAG0_BIT12);      
      /* Send an ALARM CLEAR command to the SMU Control Interface   */
      SMU_CMD.U = 5U;
  
      /* Clear all SMU Group 2, Alarms */
      SMU_AG0.U = (uint32)((uint32)1U << SRAM_ADDMON_ALMAG0_BIT12);
    }/*for(i = 0; i< SRAM_ADDR_ERR_TEST_COUNT_SINGLECORE; i++)*/
  
    /* Reset signature bit flip enable: */
    CurrentMC->ECCS.U &= ~(uint16)((uint32)IFX_MC_ECCS_SFLE_MSK <<
                           (uint32)IFX_MC_ECCS_SFLE_OFF);

    MTU_MEMTEST0.B.CPU0DSEN= 0U;
    #if (CHIP_ID == 23U) 
    MTU_MEMTEST0.B.CPU0DS2EN= 0U;  
    #endif
    
    /* Wait for RAM initialization to complete: */
    /*no timeout is given for this loop. If memory Initialization fails due any
     reason, code execution further can not proceed as usual as MBist is enabled
     for DSPR0 which means stack and CSA is not available for code execution. In
     this case, we should wait here endlessly and a mechanism should be implemented
     at customer side like resetting through supervisor watchdog to reset the system*/

    do
    {
      __asm("nop");
    } while ((MTU_MEMSTAT0.B.CPU0DSAIU != 0U)
              #if (CHIP_ID == 23U) 
              ||(MTU_MEMSTAT0.B.CPU0DS2AIU != 0U)
              #endif
              );
    
    SramEccTst_lSetSafetyENDINIT(&WdtContext);
    Result = ResultLoopCount;
  }    

  *TstSignature = (uint32)CRC32(*TstSignature , TstSignatureTemp);  
  if(Result == SRAMECC_NOTEXECUTED)
  {
    Result = SRAMECC_SUCCESS;
  }
  return Result;
} /* SramEccTst_lChkAddressMonSingleCore */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static Sl_TstRsltType SramEccTst_lChkSramMonSingleCore  **
**                        uint32* const TstSignature)                         **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : TstSignature : Test signature generated by the test     **
**                                                                            **
** Return value     : SRAM_SUCCESS - SRAM monitor test succeeded              **
**                    <Error ID> - Type of error during the test              **
**                                                                            **
** Description      : This function tests the DSPR 0 SRAM monitor on single   **
**                    core systems, i.e. the that errors are correctly tracked**
**                    to the error tracking registers, that an error at the   **
**                    same address is not tracked twice and that an error     **
**                    tracking overflow generates a SMU alarm.                **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType SramEccTst_lChkSramMonSingleCore
(
  uint32* const TstSignature
)
{
  Sl_TstRsltType            Result = SRAMECC_NOTEXECUTED;

  /* Check that correctable errors are tracked and that multiple errors
   * at the same address are not tracked twice:
   */
  Result = SramEccTst_lChkSramMonCeSingleCore(TstSignature);

  if (SRAMECC_SUCCESS == Result)
  {
    /* Check that uncorrectable errors are tracked and fill all tracking
     * entries:
     */
    Result = SramEccTst_lChkSramMonUeSingleCore(TstSignature);
    if (SRAMECC_SUCCESS == Result)
    {
      /* Check reporting of error tracking overflow to the SMU: */
      Result = SramEccTst_lChkSramMonEovSingleCore(TstSignature);
    } /* if (SRAMECC_SUCCESS == Result) */
  } /* if (SRAMECC_SUCCESS == Result) */

  return Result;
} /* SramEccTst_lChkSramMonSingleCore */


/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static Sl_TstRsltType SramEccTst_lChkSramMonCeSingleCore**
**                       (uint32* const TstSignature)                         **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : TstSignature : Test signature generated by the test     **
** Return value     : SRAM_SUCCESS - SRAM monitor CE test succeeded           **
**                    <Error ID> - Type of error during SRAM monitor CE test  **
**                                                                            **
** Description      : This function tests that correctable ECC errors are     **
**                    correctly tracked to the error tracking registers,      **
**                    reported to the SMU and that an error at the same       **
**                    address is not tracked twice.                           **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType SramEccTst_lChkSramMonCeSingleCore
(
  uint32* const TstSignature
)
{
  register uint32                    ResultLoopCount = 0U;  
  register uint32                    TstSignatureTmp = *TstSignature; 
  register Ifx_MC*                   CurrentMC; 
  
  Sl_TstRsltType                     Result = SRAMECC_NOTEXECUTED;
  uint8                              Count;
  Ifx_MC*                            MemoryController[SRAMECC_DSPR0_MC_SINGLECORE]=
                                     {
                                       &MODULE_MC14, 
                                       #if (CHIP_ID == 23U) 
                                       &MODULE_MC27
                                       #endif
                                     };
  Sl_TstRsltType                     ResultSmu = SRAMECC_NOTEXECUTED;  
  volatile uint32                    Dummy;
  SramEccTst_WdtContextType          WdtContext;

  for(Count = 0U; (Count < SRAMECC_DSPR0_MC_SINGLECORE) &&
                 (SRAMECC_NOTEXECUTED == Result); Count++)
  {
    CurrentMC = MemoryController[Count];

    /* Enable MBIST controller of RAM under test: */
    SramEccTst_lResetSafetyENDINIT(&WdtContext);
    DSYNC();
    Dummy = ((uint32*)SRAM_DSPR0_ADDRESS)[Count*SRAM_DSPR0_WORDS_PER_WORDLINE];
    UNUSED_PARAMETER(Dummy)   
    #if (CHIP_ID == 23U)       
    if(Count == 0U)
    {
      MTU_MEMTEST0.B.CPU0DSEN = 1U;
    }
    else
    {
      MTU_MEMTEST0.B.CPU0DS2EN= 1U;    
    }
    #else
    MTU_MEMTEST0.B.CPU0DSEN = 1U;    
    #endif
    /* Wait for RAM initialization to complete: */
    /*no timeout is given for this loop. If memory Initialization fails due any
     reason, code execution further can not proceed as usual as MBist is enabled
     for DSPR0 which means stack and CSA is not available for code execution. In
     this case, we should wait here endlessly and a mechanism should be implemented
     at customer side like resetting through supervisor watchdog to reset the system*/
    
    do
    {
      __asm("nop");
    } while ((MTU_MEMSTAT0.B.CPU0DSAIU != 0U)
              #if (CHIP_ID == 23U) 
              ||(MTU_MEMSTAT0.B.CPU0DS2AIU != 0U)
              #endif
              );
  
    if(CurrentMC->ECCS.B.ECE  != 0U)
    {
      /* Clear error tracking information: */
      CurrentMC->ECCD.U |= (uint16)((uint32)IFX_MC_ECCD_TRC_MSK <<
                             (uint32)IFX_MC_ECCD_TRC_OFF);
      /* Enable error tracking: */
      CurrentMC->ECCS.U |= (uint16)((uint32)IFX_MC_ECCS_TRE_MSK <<
                             (uint32)IFX_MC_ECCS_TRE_OFF);    
    
      /* Write Single bit error patters       */
      for (ResultLoopCount = 0U; ResultLoopCount < SRAM_RFBFL_REGS_COUNT_DSPR0; ResultLoopCount++)
      {
        CurrentMC->RDBFL[ResultLoopCount].U = SramEccTst_kSingleBitErrPtrn[ResultLoopCount];
      } /* for (LoopCount = 0U; LoopCount < SRAM_RFBFL_REGS_COUNT_DSPR0; LoopCount++) */      
      /* Select Range */
      CurrentMC->RANGE.U = (uint16)(SramEccTst_kMemDef[SRAM_CPU0_DSPR]->NrOfEtrRegisters);
    
      /* Configure writing of single memory address: */
      CurrentMC->CONFIG0.U = (uint16)(((uint32)SRAM_CONFIG0_NUMACCS_1 <<
                                (uint32)IFX_MC_CONFIG0_NUMACCS_OFF) |
                               ((uint32)SRAM_CONFIG0_ACCSTYPE_WR <<
                                (uint32)IFX_MC_CONFIG0_ACCSTYPE_OFF));
      CurrentMC->CONFIG1.U = 0U;
    
      /* Start write operation: */
    
      CurrentMC->MCONTROL.U = (uint16)(((uint32)IFX_MC_MCONTROL_DIR_MSK <<
                                 (uint32)IFX_MC_MCONTROL_DIR_OFF) |
                                ((uint32)IFX_MC_MCONTROL_START_MSK <<
                                 (uint32)IFX_MC_MCONTROL_START_OFF)|
                                 ((uint32)MC_MCONTROL_USERED_MSK <<
                                 (uint32)MC_MCONTROL_USERED));
      CurrentMC->MCONTROL.U = (uint16)(((uint32)IFX_MC_MCONTROL_DIR_MSK <<
                                (uint32)IFX_MC_MCONTROL_DIR_OFF)|
                                ((uint32)MC_MCONTROL_USERED_MSK <<
                                 (uint32)MC_MCONTROL_USERED));
      ResultLoopCount = (uint32)SRAMECC_NOTEXECUTED_LOCAL<<SRAM_HALF_WORD_SIZE;      
      /*wait for MBIST operation to complete*/
      for((ResultLoopCount&=SRAM_MASK_UPPER_HALFWORD); (ResultLoopCount&SRAM_MASK_LOWER_HALFWORD) < SRAM_MBIST_OPERATION_WAIT; ResultLoopCount++)                      
      {
        __asm("nop");
      }
    
      /* Read memory: */
    
      /* Configure reading of single memory address: */
      CurrentMC->CONFIG0.U = (uint16)(((uint32)SRAM_CONFIG0_NUMACCS_1 <<
                                (uint32)IFX_MC_CONFIG0_NUMACCS_OFF) |
                               ((uint32)SRAM_CONFIG0_ACCSTYPE_RD <<
                                (uint32)IFX_MC_CONFIG0_ACCSTYPE_OFF));
      CurrentMC->CONFIG1.U = 0U;
    
      CurrentMC->MCONTROL.U = (uint16)(((uint32)IFX_MC_MCONTROL_DIR_MSK <<
                                 (uint32)IFX_MC_MCONTROL_DIR_OFF) |
                                ((uint32)IFX_MC_MCONTROL_START_MSK <<
                                 (uint32)IFX_MC_MCONTROL_START_OFF)|
                                ((uint32)MC_MCONTROL_USERED_MSK <<
                                 (uint32)MC_MCONTROL_USERED));
      CurrentMC->MCONTROL.U = (uint16)(((uint32)IFX_MC_MCONTROL_DIR_MSK <<
                                (uint32)IFX_MC_MCONTROL_DIR_OFF)|
                                ((uint32)MC_MCONTROL_USERED_MSK <<
                                 (uint32)MC_MCONTROL_USERED)); 
      /*wait for MBIST operation to complete*/
      for((ResultLoopCount&=SRAM_MASK_UPPER_HALFWORD); (ResultLoopCount&SRAM_MASK_LOWER_HALFWORD) < SRAM_MBIST_OPERATION_WAIT; ResultLoopCount++)                
      {
        __asm("nop");
      }      
      TstSignatureTmp = (uint32)(CurrentMC->ECCD.B.VAL);

      /* Check ECCD.VAL and type of error: */
      if (((CurrentMC->ECCD.B.VAL) != 1U) || ((CurrentMC->ECCD.B.CERR) != 1U))
      {
        /* Clear error flags: */
        CurrentMC->ECCD.U &= ~(uint16)(((uint32)IFX_MC_ECCD_SERR_MSK <<
                                 (uint32)IFX_MC_ECCD_SERR_OFF) |
                                ((uint32)IFX_MC_ECCD_CERR_MSK <<
                                 (uint32)IFX_MC_ECCD_CERR_OFF) |
                                ((uint32)IFX_MC_ECCD_UERR_MSK <<
                                 (uint32)IFX_MC_ECCD_UERR_OFF)); 

        ResultLoopCount = (uint32)SRAMECC_ETR_MISSING_LOCAL<<SRAM_HALF_WORD_SIZE;        
      } /* if ((CurrentMC->ECCD.B.VAL != 1U) || (1U != CurrentMC->ECCD.B.CERR))*/ 
      else
      {
        /* Clear error flags: */
        CurrentMC->ECCD.U &= ~(uint16)(((uint32)IFX_MC_ECCD_SERR_MSK <<
                                 (uint32)IFX_MC_ECCD_SERR_OFF) |
                                ((uint32)IFX_MC_ECCD_CERR_MSK <<
                                 (uint32)IFX_MC_ECCD_CERR_OFF) |
                                ((uint32)IFX_MC_ECCD_UERR_MSK <<
                                 (uint32)IFX_MC_ECCD_UERR_OFF));    
        /* Check that reading the same address multiple times will not
           generate more than one error tracking entries:
         */
        CurrentMC->MCONTROL.U = (uint16)(((uint32)IFX_MC_MCONTROL_DIR_MSK <<
                                   (uint32)IFX_MC_MCONTROL_DIR_OFF) |
                                  ((uint32)IFX_MC_MCONTROL_START_MSK <<
                                   (uint32)IFX_MC_MCONTROL_START_OFF)|
                                  ((uint32)MC_MCONTROL_USERED_MSK <<
                                   (uint32)MC_MCONTROL_USERED));
        CurrentMC->MCONTROL.U = (uint16)(((uint32)IFX_MC_MCONTROL_DIR_MSK <<
                                  (uint32)IFX_MC_MCONTROL_DIR_OFF)|
                                  ((uint32)MC_MCONTROL_USERED_MSK <<
                                   (uint32)MC_MCONTROL_USERED)); 
    
        /*wait for MBIST operation to complete*/
        for((ResultLoopCount&=SRAM_MASK_UPPER_HALFWORD); (ResultLoopCount&SRAM_MASK_LOWER_HALFWORD) < SRAM_MBIST_OPERATION_WAIT; ResultLoopCount++)          
        {
          __asm("nop");
        }    
        if(CurrentMC->ECCD.B.VAL != 1U)
        {
          ResultLoopCount = (uint32)SRAMECC_ETR_DUPLICATE_LOCAL<<SRAM_HALF_WORD_SIZE;          
        } /* if(ValDuplicateRead != Val)) */  
    
        /* Clear error flags: */
        CurrentMC->ECCD.U &= ~(uint16)(((uint32)IFX_MC_ECCD_SERR_MSK <<
                                   (uint32)IFX_MC_ECCD_SERR_OFF) |
                                  ((uint32)IFX_MC_ECCD_CERR_MSK <<
                                   (uint32)IFX_MC_ECCD_CERR_OFF) |
                                  ((uint32)IFX_MC_ECCD_UERR_MSK <<
                                   (uint32)IFX_MC_ECCD_UERR_OFF));
        
      }/* else if(SramEccTst_kMemDef[SRAM_CPU0_DSPR]->NrOfEtrRegisters > 1U) */
    
      /* Initialize RDBFL registers to no error pattern: */
      for((ResultLoopCount&=SRAM_MASK_UPPER_HALFWORD); (ResultLoopCount&SRAM_MASK_LOWER_HALFWORD) < SRAM_RFBFL_REGS_COUNT_DSPR0; ResultLoopCount++)          
      {
        CurrentMC->RDBFL[ResultLoopCount&SRAM_MASK_LOWER_HALFWORD].U = SramEccTst_kNoErrPtrn[ResultLoopCount&SRAM_MASK_LOWER_HALFWORD];
      } /* for (LoopCount = 0U; LoopCount < SRAM_RFBFL_REGS_COUNT_DSPR0; LoopCount++) */      
      /* Configure writing of single memory address: */
      CurrentMC->CONFIG0.U = (uint16)(((uint32)SRAM_CONFIG0_NUMACCS_1 <<
                                (uint32)IFX_MC_CONFIG0_NUMACCS_OFF) |
                               ((uint32)SRAM_CONFIG0_ACCSTYPE_WR <<
                                (uint32)IFX_MC_CONFIG0_ACCSTYPE_OFF));
      CurrentMC->CONFIG1.U = 0U;
    
      /* Start write operation: */
    
      CurrentMC->MCONTROL.U = (uint16)(((uint32)IFX_MC_MCONTROL_DIR_MSK <<
                                 (uint32)IFX_MC_MCONTROL_DIR_OFF) |
                                ((uint32)IFX_MC_MCONTROL_START_MSK <<
                                 (uint32)IFX_MC_MCONTROL_START_OFF)|
                                 ((uint32)MC_MCONTROL_USERED_MSK <<
                                 (uint32)MC_MCONTROL_USERED));
      CurrentMC->MCONTROL.U = (uint16)(((uint32)IFX_MC_MCONTROL_DIR_MSK <<
                                (uint32)IFX_MC_MCONTROL_DIR_OFF)|
                                ((uint32)MC_MCONTROL_USERED_MSK <<
                                 (uint32)MC_MCONTROL_USERED));
      for((ResultLoopCount&=SRAM_MASK_UPPER_HALFWORD); (ResultLoopCount&SRAM_MASK_LOWER_HALFWORD) < SRAM_MBIST_OPERATION_WAIT; ResultLoopCount++)          
      {
        __asm("nop");
      }    
      MTU_MEMTEST0.B.CPU0DSEN = 0U;
      #if (CHIP_ID == 23U) 
      MTU_MEMTEST0.B.CPU0DS2EN= 0U;  
      #endif  
    
      /* Wait for RAM initialization to complete: */
    /*no timeout is given for this loop. If memory Initialization fails due any
     reason, code execution further can not proceed as usual as MBist is enabled
     for DSPR0 which means stack and CSA is not available for code execution. In
     this case, we should wait here endlessly and a mechanism should be implemented
     at customer side like resetting through supervisor watchdog to reset the system*/
      
      do
      {
        __asm("nop");
      } while ((MTU_MEMSTAT0.B.CPU0DSAIU != 0U)
              #if (CHIP_ID == 23U) 
              ||(MTU_MEMSTAT0.B.CPU0DS2AIU != 0U)
              #endif
              );
      Result = SramEccTst_kLocalResultTbl[ResultLoopCount>>SRAM_HALF_WORD_SIZE];      
      *TstSignature = CRC32(*TstSignature , TstSignatureTmp);
      /* Wait for and clear SMU alarm: */
      ResultSmu = SramEccTst_lWaitForSmuAlarm(
           SramEccTst_kMemDef[SRAM_CPU0_DSPR]->SmuAlarmGrp,
           SramEccTst_kMemDef[SRAM_CPU0_DSPR]->SmuNr_SbeCorr,
           TstSignature);    
      if((ResultSmu != SRAMECC_SUCCESS) && (Result == SRAMECC_NOTEXECUTED))
      {
        Result = ResultSmu;
      }      
    }/*else if(CurrentMC->ECCS.B.ECE  != 0U)*/
    else
    {
      MTU_MEMTEST0.B.CPU0DSEN = 0U;
      #if (CHIP_ID == 23U) 
      MTU_MEMTEST0.B.CPU0DS2EN= 0U;  
      #endif  
    
      /* Wait for RAM initialization to complete: */
    /*no timeout is given for this loop. If memory Initialization fails due any
     reason, code execution further can not proceed as usual as MBist is enabled
     for DSPR0 which means stack and CSA is not available for code execution. In
     this case, we should wait here endlessly and a mechanism should be implemented
     at customer side like resetting through supervisor watchdog to reset the system*/
      
      do
      {
        __asm("nop");
      } while ((MTU_MEMSTAT0.B.CPU0DSAIU != 0U)
              #if (CHIP_ID == 23U) 
              ||(MTU_MEMSTAT0.B.CPU0DS2AIU != 0U)
              #endif
              );   
      Result = SRAMECC_MEM_ECECFG;              
    }
  
    SramEccTst_lSetSafetyENDINIT(&WdtContext);
  }/*for(Count = 0U; (Count < SRAMECC_DSPR0_MC_SINGLECORE) &&
                 (SRAMECC_NOTEXECUTED == Result); Count++)*/

  if(Result == SRAMECC_NOTEXECUTED)
  {
    Result = SRAMECC_SUCCESS;
  }
  
  return Result;
} /* SramEccTst_lChkSramMonCeSingleCore */


/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static Sl_TstRsltType SramEccTst_lChkSramMonUeSingleCore**
**                       (const uint8 MemIdx,                                 **
**                        uint32* const TstSignature,                         **
**                        uint16* const ValExpected,                          **
**                        uint16* const WordlineIdx)                          **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : MemIdx - Index of the memory under test; Refer to       **
**                             definition of supported SRAMs in               **
**                             SramEccTst_MemDef.h for a list of supported    **
**                             values                                         **
**                                                                            **
** Parameters (out) : TstSignature : Test signature generated by the test     **
**                    ValExpected : in & out parameter, contains the expected **
**                                  ECCD.VAL value and will be set to the     **
**                                  expected ECCD.VAL value for the next test **
**                    WordlineIdx : in & out paramater, contains the current  **
**                                  wordline to be used for uncorrectable     **
**                                  error test and will be set to wordline    **
**                                  that is to be used for the next test      **
**                                                                            **
** Return value     : SRAM_SUCCESS - SRAM monitor UE test succeeded           **
**                    <Error ID> - Type of error during SRAM monitor UE test  **
**                                                                            **
** Description      : This function tests that uncorrectable ECC errors are   **
**                    correctly tracked and fills all error tracking entries  **
**                    as preparation for the following overflow test.         **
**                    It also checks that uncorrectable ECC errors are        **
**                    reported to the SMU.                                    **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType SramEccTst_lChkSramMonUeSingleCore
(
  uint32* const TstSignature

)
{
  /*ResultLoopCount variable is shared for using as counter, timeout and result.
  For writing into rdbfl registers, it is used as counter
  It is used as timeout for waiting for SMU alarms
  Used as result in all other places*/
  register uint32           ResultLoopCount   = 0U;  
  register uint32           WordLineIdxValExp = 0U;  
  register Ifx_MC*          CurrentMC;
  register uint32           TstSignatureTmp   = 0U;
  
  Sl_TstRsltType            Result            = SRAMECC_NOTEXECUTED;
  uint8                     Count;
  Ifx_MC*                   MemoryController[SRAMECC_DSPR0_MC_SINGLECORE]=
                                     {
                                       &MODULE_MC14, 
                                       #if (CHIP_ID == 23U) 
                                       &MODULE_MC27
                                       #endif
                                     };
  volatile uint32           Dummy;
  Sl_TstRsltType            ResultSmu = SRAMECC_NOTEXECUTED;  
  SramEccTst_WdtContextType WdtContext;

  
  for(Count = 0U; (Count < SRAMECC_DSPR0_MC_SINGLECORE) &&
                 (SRAMECC_NOTEXECUTED == Result); Count++)
  {
    CurrentMC = MemoryController[Count];
      
    /* In order to have limited number of variables so that compiler locates
    all variables with attribute register into registers, following single 32-bit
    space is shared and used by two 16-bit values */
    /*lower half word of WordLineIdxValExp is used for WordLineIdx */
    WordLineIdxValExp = ((uint32)(SramEccTst_kMemDef[SRAM_CPU0_DSPR]->NrOfEtrRegisters)-1U);
    /*upper half word of WordLineIdxValExp is used for ValExp */    
    WordLineIdxValExp|= ((uint32)SRAM_ECCD_VAL_EXPECTED << SRAM_HALF_WORD_SIZE);
    
    /* Enable MBIST controller of RAM under test: */
    SramEccTst_lResetSafetyENDINIT(&WdtContext);
    DSYNC();
    Dummy = ((uint32*)SRAM_DSPR0_ADDRESS)[Count*SRAM_DSPR0_WORDS_PER_WORDLINE];
    UNUSED_PARAMETER(Dummy)     
   
    #if (CHIP_ID == 23U)       
    if(Count == 0U)
    {
      MTU_MEMTEST0.B.CPU0DSEN = 1U;
    }
    else
    {
      MTU_MEMTEST0.B.CPU0DS2EN= 1U;    
    }
    #else
    MTU_MEMTEST0.B.CPU0DSEN = 1U;    
    #endif
    /* Wait for RAM initialization to complete: */
    /*no timeout is given for this loop. If memory Initialization fails due any
     reason, code execution further can not proceed as usual as MBist is enabled
     for DSPR0 which means stack and CSA is not available for code execution. In
     this case, we should wait here endlessly and a mechanism should be implemented
     at customer side like resetting through supervisor watchdog to reset the system*/
    
    do
    {
      __asm("nop");
    } while ((MTU_MEMSTAT0.B.CPU0DSAIU != 0U)
              #if (CHIP_ID == 23U) 
              ||(MTU_MEMSTAT0.B.CPU0DS2AIU != 0U)
              #endif
              );
     
    while((WordLineIdxValExp & SRAM_MASK_LOWER_HALFWORD) > 0U)
    {
      /* Initialize RDBFL registers with double bit error patterns */
      for (ResultLoopCount = 0U; ResultLoopCount < SRAM_RFBFL_REGS_COUNT_DSPR0; ResultLoopCount++)     
      {
        CurrentMC->RDBFL[ResultLoopCount].U = SramEccTst_kDoubleBitErrPtrn[ResultLoopCount];
      } /* for (LoopCount = 0U; LoopCount < SRAM_RFBFL_REGS_COUNT_DSPR0; LoopCount++) */        
      CurrentMC->RANGE.U = (uint16)(WordLineIdxValExp & ((uint16)IFX_MC_RANGE_ADDR_MSK));
    
      /* Configure writing of single memory address: */
      CurrentMC->CONFIG0.U = (uint16)(((uint32)SRAM_CONFIG0_NUMACCS_1 <<
                                (uint32)IFX_MC_CONFIG0_NUMACCS_OFF) |
                               ((uint32)SRAM_CONFIG0_ACCSTYPE_WR <<
                                (uint32)IFX_MC_CONFIG0_ACCSTYPE_OFF));
      CurrentMC->CONFIG1.U = 0U;
    
      /* Start write operation: */
    
      CurrentMC->MCONTROL.U = (uint16)(((uint32)IFX_MC_MCONTROL_DIR_MSK <<
                                 (uint32)IFX_MC_MCONTROL_DIR_OFF) |
                                ((uint32)IFX_MC_MCONTROL_START_MSK <<
                                 (uint32)IFX_MC_MCONTROL_START_OFF)|
                                 ((uint32)MC_MCONTROL_USERED_MSK <<
                                 (uint32)MC_MCONTROL_USERED));
      CurrentMC->MCONTROL.U = (uint16)(((uint32)IFX_MC_MCONTROL_DIR_MSK <<
                                (uint32)IFX_MC_MCONTROL_DIR_OFF)|
                                ((uint32)MC_MCONTROL_USERED_MSK <<
                                 (uint32)MC_MCONTROL_USERED));
      /*wait for MBIST operation to complete*/
     /*ResultLoopCount is used as count here*/      
      for (ResultLoopCount = 0U; ResultLoopCount < SRAM_MBIST_OPERATION_WAIT; ResultLoopCount++)       
      {
        __asm("nop");
      }

      /* Read memory: */
    
      /* Configure reading of single memory address: */
      CurrentMC->CONFIG0.U = (uint16)(((uint32)SRAM_CONFIG0_NUMACCS_1 <<
                                (uint32)IFX_MC_CONFIG0_NUMACCS_OFF) |
                               ((uint32)SRAM_CONFIG0_ACCSTYPE_RD <<
                                (uint32)IFX_MC_CONFIG0_ACCSTYPE_OFF));
      CurrentMC->CONFIG1.U = 0U;
    
      CurrentMC->MCONTROL.U = (uint16)(((uint32)IFX_MC_MCONTROL_DIR_MSK <<
                                 (uint32)IFX_MC_MCONTROL_DIR_OFF) |
                                ((uint32)IFX_MC_MCONTROL_START_MSK <<
                                 (uint32)IFX_MC_MCONTROL_START_OFF)|
                                ((uint32)MC_MCONTROL_USERED_MSK <<
                                 (uint32)MC_MCONTROL_USERED));
      CurrentMC->MCONTROL.U = (uint16)(((uint32)IFX_MC_MCONTROL_DIR_MSK <<
                                (uint32)IFX_MC_MCONTROL_DIR_OFF)|
                                ((uint32)MC_MCONTROL_USERED_MSK <<
                                 (uint32)MC_MCONTROL_USERED));
      /*wait for MBIST operation to complete*/
     /*ResultLoopCount is used as count here*/      
      for (ResultLoopCount = 0U; ResultLoopCount < SRAM_MBIST_OPERATION_WAIT; ResultLoopCount++)         
      {
        __asm("nop");
      }
     /*ResultLoopCount is used as count here*/
      /* Initialize RDBFL registers to no error pattern: */
      for (ResultLoopCount = 0U; ResultLoopCount < SRAM_RFBFL_REGS_COUNT_DSPR0; ResultLoopCount++)
      {
        CurrentMC->RDBFL[ResultLoopCount].U = SramEccTst_kNoErrPtrn[ResultLoopCount];
      } /* for (LoopCount = 0U; LoopCount < SRAM_RFBFL_REGS_COUNT_DSPR0; LoopCount++) */      
      /* Configure writing of single memory address: */
      CurrentMC->CONFIG0.U = (uint16)(((uint32)SRAM_CONFIG0_NUMACCS_1 <<
                                (uint32)IFX_MC_CONFIG0_NUMACCS_OFF) |
                               ((uint32)SRAM_CONFIG0_ACCSTYPE_WR <<
                                (uint32)IFX_MC_CONFIG0_ACCSTYPE_OFF));
      CurrentMC->CONFIG1.U = 0U;
    
      /* Start write operation: */
    
      CurrentMC->MCONTROL.U = (uint16)(((uint32)IFX_MC_MCONTROL_DIR_MSK <<
                                 (uint32)IFX_MC_MCONTROL_DIR_OFF) |
                                ((uint32)IFX_MC_MCONTROL_START_MSK <<
                                 (uint32)IFX_MC_MCONTROL_START_OFF)|
                                 ((uint32)MC_MCONTROL_USERED_MSK <<
                                 (uint32)MC_MCONTROL_USERED));
      CurrentMC->MCONTROL.U = (uint16)(((uint32)IFX_MC_MCONTROL_DIR_MSK <<
                                (uint32)IFX_MC_MCONTROL_DIR_OFF)|
                                ((uint32)MC_MCONTROL_USERED_MSK <<
                                 (uint32)MC_MCONTROL_USERED)); 

      /*wait for MBIST operation to complete*/
     /*ResultLoopCount is used as count here*/      
      for (ResultLoopCount = 0U; ResultLoopCount < SRAM_MBIST_OPERATION_WAIT; ResultLoopCount++)        
      {
        __asm("nop");
      }      

      WordLineIdxValExp = SramEccTst_kLukupTblExpValWLIdx[WordLineIdxValExp & 0xFFFFU];

      /* Check that error was tracked: */
      ResultLoopCount = (uint32)SRAMECC_NOTEXECUTED_LOCAL<<SRAM_HALF_WORD_SIZE;
      if ((CurrentMC->ECCD.B.VAL != ((WordLineIdxValExp&SRAM_MASK_UPPER_HALFWORD)>>SRAM_HALF_WORD_SIZE)) || (0U == CurrentMC->ECCD.B.UERR))      
      {
        ResultLoopCount = (uint32)SRAMECC_ETR_MISSING_LOCAL<<SRAM_HALF_WORD_SIZE;        
        WordLineIdxValExp&= SRAM_MASK_UPPER_HALFWORD;
      } /* if ((Val != ValExpected) || (0U == Err)) */
      
      TstSignatureTmp = CurrentMC->ECCD.B.VAL;
      /* Clear ECCD error flags: */
      CurrentMC->ECCD.U &= ~(uint16)(((uint32)IFX_MC_ECCD_SERR_MSK <<
                               (uint32)IFX_MC_ECCD_SERR_OFF) |
                              ((uint32)IFX_MC_ECCD_UERR_MSK <<
                               (uint32)IFX_MC_ECCD_UERR_OFF));       

    }

    MTU_MEMTEST0.B.CPU0DSEN = 0U;
    #if (CHIP_ID == 23U) 
    MTU_MEMTEST0.B.CPU0DS2EN= 0U;  
    #endif   

    /* Wait for RAM initialization to complete: */
    /*no timeout is given for this loop. If memory Initialization fails due any
     reason, code execution further can not proceed as usual as MBist is enabled
     for DSPR0 which means stack and CSA is not available for code execution. In
     this case, we should wait here endlessly and a mechanism should be implemented
     at customer side like resetting through supervisor watchdog to reset the system*/
    
    do
    {
      __asm("nop");
    } while ((MTU_MEMSTAT0.B.CPU0DSAIU != 0U)
              #if (CHIP_ID == 23U) 
              ||(MTU_MEMSTAT0.B.CPU0DS2AIU != 0U)
              #endif
              );
    Result = SramEccTst_kLocalResultTbl[ResultLoopCount>>SRAM_HALF_WORD_SIZE];     
    *TstSignature = (uint32)CRC32(*TstSignature, (uint32)TstSignatureTmp);
    /* Wait for and clear SMU alarm: */
    ResultSmu = SramEccTst_lWaitForSmuAlarm(
           SramEccTst_kMemDef[SRAM_CPU0_DSPR]->SmuAlarmGrp,
           SramEccTst_kMemDef[SRAM_CPU0_DSPR]->SmuNr_UcErr,
           TstSignature);
    if((ResultSmu != SRAMECC_SUCCESS) && (Result == SRAMECC_NOTEXECUTED))
    {
      Result = ResultSmu;
    }      

  
    SramEccTst_lSetSafetyENDINIT(&WdtContext);
  }

  if(Result == SRAMECC_NOTEXECUTED)
  {
    Result = SRAMECC_SUCCESS;
  }  

  return Result;

} /* SramEccTst_lChkSramMonUeSingleCore */


/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static Sl_TstRsltType SramEccTst_lChkSramMonEovSingleCore**
**                       (const uint8 MemIdx,                                 **
**                        uint32* const TstSignature,                         **
**                        uint16* const WordlineIdx)                          **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : MemIdx - Index of the memory under test; Refer to       **
**                             definition of supported SRAMs in               **
**                             SramEccTst_MemDef.h for a list of supported    **
**                             values                                         **
**                    WordlineIdx - contains the current wordline to be used  **
**                                  for the error tracking overflow test      **
**                                                                            **
** Parameters (out) : TstSignature - Test signature generated by the test     **
**                                                                            **
** Return value     : SRAM_SUCCESS - SRAM monitor EOV test succeeded          **
**                    <Error ID> - Type of error during SRAM monitor EOV test **
**                                                                            **
** Description      : This function tests that an overflow of the error       **
**                    tracking registers is correctly signaled to the SMU and **
**                    the respective overflow bit is set.                     **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType SramEccTst_lChkSramMonEovSingleCore
(
  uint32* const TstSignature
)
{
  register Sl_TstRsltType   Result= SRAMECC_NOTEXECUTED;
  register uint32           LoopCount;
  register Ifx_MC*          CurrentMC;   
  
  uint8                     Count;
  Ifx_MC*                   MemoryController[SRAMECC_DSPR0_MC_SINGLECORE]=
                                     {
                                       &MODULE_MC14, 
                                       #if (CHIP_ID == 23U) 
                                       &MODULE_MC27
                                       #endif
                                     };
  SramEccTst_WdtContextType WdtContext;
  volatile uint32           Dummy;
  Sl_TstRsltType            ResultSmuUcrr        = SRAMECC_NOTEXECUTED;
  Sl_TstRsltType            ResultSmuAdrBufFull  = SRAMECC_NOTEXECUTED;  
  
  for(Count = 0U; (Count < SRAMECC_DSPR0_MC_SINGLECORE) &&
                 (SRAMECC_NOTEXECUTED == Result); Count++)
  {
    CurrentMC = MemoryController[Count];
  
    /* Enable MBIST controller of RAM under test: */
    SramEccTst_lResetSafetyENDINIT(&WdtContext);
    DSYNC();
    /*memory is interleaved over 16 bytes i.e first 16 bytes belong to 
      MC14. next 16 words belong to MC 27*/
    Dummy = ((uint32*)SRAM_DSPR0_ADDRESS)[Count*SRAM_DSPR0_WORDS_PER_WORDLINE];
    UNUSED_PARAMETER(Dummy)   
    #if (CHIP_ID == 23U)       
    if(Count == 0U)
    {
      MTU_MEMTEST0.B.CPU0DSEN = 1U;
    }
    else
    {
      MTU_MEMTEST0.B.CPU0DS2EN= 1U;    
    }
    #else
    MTU_MEMTEST0.B.CPU0DSEN = 1U;    
    #endif
    /*no timeout is given for this loop. If memory Initialization fails due any
     reason, code execution further can not proceed as usual as MBist is enabled
     for DSPR0 which means stack and CSA is not available for code execution. In
     this case, we should wait here endlessly and a mechanism should be implemented
     at customer side like resetting through supervisor watchdog to reset the system*/
    do
    {
      __asm("nop");
    } while ((MTU_MEMSTAT0.B.CPU0DSAIU != 0U)
              #if (CHIP_ID == 23U) 
              ||(MTU_MEMSTAT0.B.CPU0DS2AIU != 0U)
              #endif
              );

     
    /* Initialize RDBFL registers for the memory controller to be tested to 0*/
    for (LoopCount = 0U; LoopCount < SRAM_RFBFL_REGS_COUNT_DSPR0; LoopCount++)
    {
      CurrentMC->RDBFL[LoopCount].U = SramEccTst_kDoubleBitErrPtrn[LoopCount];
    } /* for (LoopCount = 0U; LoopCount < SRAM_RFBFL_REGS_COUNT_DSPR0; LoopCount++) */
    /*Initialize Range for the memory controller to be tested*/
    CurrentMC->RANGE.U = 0U;
    
    /* Configure writing of single memory address: */
    CurrentMC->CONFIG0.U = (uint16)(((uint32)SRAM_CONFIG0_NUMACCS_1 <<
                  (uint32)IFX_MC_CONFIG0_NUMACCS_OFF) |
                 ((uint32)SRAM_CONFIG0_ACCSTYPE_WR <<
                  (uint32)IFX_MC_CONFIG0_ACCSTYPE_OFF));
    CurrentMC->CONFIG1.U = 0U;
    
    /* Start write operation: */
    
    CurrentMC->MCONTROL.U = (uint16)(((uint32)IFX_MC_MCONTROL_DIR_MSK <<
                   (uint32)IFX_MC_MCONTROL_DIR_OFF) |
                  ((uint32)IFX_MC_MCONTROL_START_MSK <<
                   (uint32)IFX_MC_MCONTROL_START_OFF)|
                   ((uint32)MC_MCONTROL_USERED_MSK <<
                   (uint32)MC_MCONTROL_USERED));
    CurrentMC->MCONTROL.U = (uint16)(((uint32)IFX_MC_MCONTROL_DIR_MSK <<
                  (uint32)IFX_MC_MCONTROL_DIR_OFF)|
                  ((uint32)MC_MCONTROL_USERED_MSK <<
                   (uint32)MC_MCONTROL_USERED));
    /*give some delay between read and write operation to ensure that MBIST
      write to memory has taken place*/
    for (LoopCount = 0U; LoopCount < SRAM_MBIST_OPERATION_WAIT; LoopCount++)
    {
      __asm("nop");
    }        
    /* Read memory: */
    
    /* Configure reading of single memory address: */
    CurrentMC->CONFIG0.U = (uint16)(((uint32)SRAM_CONFIG0_NUMACCS_1 <<
                  (uint32)IFX_MC_CONFIG0_NUMACCS_OFF) |
                 ((uint32)SRAM_CONFIG0_ACCSTYPE_RD <<
                  (uint32)IFX_MC_CONFIG0_ACCSTYPE_OFF));
    CurrentMC->CONFIG1.U = 0U;
    
    CurrentMC->MCONTROL.U = (uint16)(((uint32)IFX_MC_MCONTROL_DIR_MSK <<
                   (uint32)IFX_MC_MCONTROL_DIR_OFF) |
                  ((uint32)IFX_MC_MCONTROL_START_MSK <<
                   (uint32)IFX_MC_MCONTROL_START_OFF)|
                  ((uint32)MC_MCONTROL_USERED_MSK <<
                   (uint32)MC_MCONTROL_USERED));
    CurrentMC->MCONTROL.U = (uint16)(((uint32)IFX_MC_MCONTROL_DIR_MSK <<
                  (uint32)IFX_MC_MCONTROL_DIR_OFF)|
                  ((uint32)MC_MCONTROL_USERED_MSK <<
                   (uint32)MC_MCONTROL_USERED)); 

    /*give some delay after read operation to ensure that read has taken place*/
    for (LoopCount = 0U; LoopCount < SRAM_MBIST_OPERATION_WAIT; LoopCount++)
    {
      __asm("nop");
    } 

    if (CurrentMC->ECCD.B.EOV != 1U)
    {
      Result = SRAMECC_ETR_EOVMISSING;      
    }
    /* Clear error flags: */
     CurrentMC->ECCD.U &= ~(uint16)(((uint32)IFX_MC_ECCD_SERR_MSK <<
                                       (uint32)IFX_MC_ECCD_SERR_OFF) |
                                      ((uint32)IFX_MC_ECCD_UERR_MSK <<
                                      (uint32)IFX_MC_ECCD_UERR_OFF));    
     /* Clear error tracking information: */
     CurrentMC->ECCD.U |= (uint16)((uint32)IFX_MC_ECCD_TRC_MSK <<
                           (uint32)IFX_MC_ECCD_TRC_OFF); 
    /* Initialize RDBFL registers to zero: */
    for (LoopCount = 0U; LoopCount < SRAM_RFBFL_REGS_COUNT_DSPR0; LoopCount++)
    {
      CurrentMC->RDBFL[LoopCount].U = SramEccTst_kNoErrPtrn[LoopCount];
    } /* for (LoopCount = 0U; LoopCount < SRAM_RFBFL_REGS_COUNT_DSPR0; LoopCount++) */
    
    /* Configure writing of single memory address: */
    CurrentMC->CONFIG0.U = (uint16)(((uint32)SRAM_CONFIG0_NUMACCS_1 <<
                  (uint32)IFX_MC_CONFIG0_NUMACCS_OFF) |
                 ((uint32)SRAM_CONFIG0_ACCSTYPE_WR <<
                  (uint32)IFX_MC_CONFIG0_ACCSTYPE_OFF));
    CurrentMC->CONFIG1.U = 0U;
    
    /* Start write operation: */
    
    CurrentMC->MCONTROL.U = (uint16)(((uint32)IFX_MC_MCONTROL_DIR_MSK <<
                   (uint32)IFX_MC_MCONTROL_DIR_OFF) |
                  ((uint32)IFX_MC_MCONTROL_START_MSK <<
                   (uint32)IFX_MC_MCONTROL_START_OFF)|
                   ((uint32)MC_MCONTROL_USERED_MSK <<
                   (uint32)MC_MCONTROL_USERED));
    CurrentMC->MCONTROL.U = (uint16)(((uint32)IFX_MC_MCONTROL_DIR_MSK <<
                  (uint32)IFX_MC_MCONTROL_DIR_OFF)|
                  ((uint32)MC_MCONTROL_USERED_MSK <<
                   (uint32)MC_MCONTROL_USERED)); 
    
    /*give some delay after MBIST operation to ensure that operation has taken place*/ 
    
    for (LoopCount = 0U; LoopCount < SRAM_MBIST_OPERATION_WAIT; LoopCount++)
    {
      __asm("nop");
    } 
    /* Initialize RDBFL registers with invalid pattern in the end. 
       This is not written to memory*/
    for (LoopCount = 0U; LoopCount < SRAM_RFBFL_REGS_COUNT_DSPR0; LoopCount++)
    {
      CurrentMC->RDBFL[LoopCount].U = SramEccTst_kDoubleBitErrPtrn[LoopCount];
    } /* for (LoopCount = 0U; LoopCount < SRAM_RFBFL_REGS_COUNT_DSPR0; LoopCount++) */    
    /*disable memory controller*/
    
    MTU_MEMTEST0.B.CPU0DSEN = 0U;
    #if (CHIP_ID == 23U) 
    MTU_MEMTEST0.B.CPU0DS2EN= 0U;  
    #endif    

    /* Wait for RAM initialization to complete: */
    /*no timeout is given for this loop. If memory Initialization fails due any
     reason, code execution further can not proceed as usual as MBist is enabled
     for DSPR0 which means stack and CSA is not available for code execution. In
     this case, we should wait here endlessly and a mechanism should be implemented
     at customer side like resetting through supervisor watchdog to reset the system*/

    do
    {
      __asm("nop");
    } while ((MTU_MEMSTAT0.B.CPU0DSAIU != 0U)
              #if (CHIP_ID == 23U) 
              ||(MTU_MEMSTAT0.B.CPU0DS2AIU != 0U)
              #endif
              );
    
    /* Wait for and clear SMU alarm: */
    ResultSmuUcrr = SramEccTst_lWaitForSmuAlarm(
       SramEccTst_kMemDef[SRAM_CPU0_DSPR]->SmuAlarmGrp,
       SramEccTst_kMemDef[SRAM_CPU0_DSPR]->SmuNr_UcErr,
       TstSignature);
    if((ResultSmuUcrr != SRAMECC_SUCCESS) && (Result == SRAMECC_NOTEXECUTED))
    {
      Result = ResultSmuUcrr;
    }/*if((ResultSmuUcrr != SRAMECC_SUCCESS) && (Result == SRAMECC_NOTEXECUTED))*/       

    ResultSmuAdrBufFull = SramEccTst_lWaitForSmuAlarm(
      SramEccTst_kMemDef[SRAM_CPU0_DSPR]->SmuAlarmGrp,
      SramEccTst_kMemDef[SRAM_CPU0_DSPR]->SmuNr_AdrBufFull,
      TstSignature);  
    if((ResultSmuAdrBufFull != SRAMECC_SUCCESS) && (Result == SRAMECC_NOTEXECUTED))
    {
      Result = ResultSmuAdrBufFull;
    }/*if((ResultSmuAdrBufFull != SRAMECC_SUCCESS) && (Result == SRAMECC_NOTEXECUTED))*/ 
    
    SramEccTst_lSetSafetyENDINIT(&WdtContext);
  }
      /*for(Count = 0; (Count < SRAMECC_DSPR0_MC_SINGLECORE) &&
                       (SRAMECC_NOTEXECUTED == Result); Count++)*/
  if(Result == SRAMECC_NOTEXECUTED)
  {
    Result = SRAMECC_SUCCESS;
  }  
  
  return Result;
} /* SramEccTst_lChkSramMonEovSingleCore */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static Sl_TstRsltType   SramEccTst_lTestDspr0SingleCore **
**                       (uint32* const TstSignature,                         **
**                        SramEccTst_BackupDataType* const BackupData)        **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : None
**                                                                            **
** Parameters (out) : TstSignature - Test signature generated by the test     **
**                                                                            **
** Return value     : SRAMECC_SUCCESS - Memory test succeeded                 **
**                    <Error ID> - Type of error during memory test           **
**                                                                            **
** Description      : This function performs the SRAM ECC test for DSPR0      **
**                    memory on single core platform. DSPR0 test for single   **
**                    core platform is done separately as DSPR testing on     **
**                    running core involves special handling because DSPR that**
**                    is used for for stack, CSA will not be available after  **
*                     enabling memory test mode for DSPR0. This restriction is**
**                    taken care                                              **
**                                                                            **
**                    not making any fn call after enabling memory            **
**                    to ensure that CSA is not used after enabling MBIST)    **
**                                                                            **
**                    Having all local variables in registers as no memory is **
**                    available to be used as stack                           **
**                    It also takes care about initialization, memory         **
**                    content backup and restoration of the memory like other **
**                    memory tests                                            **
*******************************************************************************/
static Sl_TstRsltType   SramEccTst_lTestDspr0SingleCore
(
  uint32* const TstSignature, SramEccTst_BackupDataType* const BackupData  
)
{

  Sl_TstRsltType            Result        = SRAMECC_NOTEXECUTED;
  Sl_TstRsltType            ResultRestore = SRAMECC_NOTEXECUTED;  
  
  /* Initialize the test: */
  Result = SramEccTst_lInitSingleCore(BackupData);
  
  if (SRAMECC_SUCCESS == Result)
  {
    /* Check signaling of address line errors to the SMU: */
    Result = SramEccTst_lChkAddressMonSingleCore(TstSignature);
    
    if (SRAMECC_SUCCESS == Result)
    {
      /* Check the SRAM monitor: */
      Result = SramEccTst_lChkSramMonSingleCore(TstSignature);
    }/* if (SRAMECC_SUCCESS == Result) */
  }/* if (SRAMECC_SUCCESS == Result) */
  
  ResultRestore = SramEccTst_lRestoreSingleCore(BackupData);  
  if(Result == SRAMECC_SUCCESS)
  {
    Result = ResultRestore;
  }/* if (SRAMECC_SUCCESS == Result) */

  return Result;
} /*   SramEccTst_lTestDspr0SingleCore */
#ifdef __TASKING__
PRAGMA_ALL(OPTIMIZE_RESTORE)
#endif

#define IFX_SRAM_STOP_SEC_CODE_NO_OPTIMIZED_ASIL_B
#include "Ifx_MemMap.h"



#endif  /*  #if (CHIP_ID == 21U) || 
              (CHIP_ID == 22U) || 
              (CHIP_ID == 23U) || 
              (CHIP_ID == 24U)   */
