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
**   $FILENAME   : SriTst.c $                                                 **
**                                                                            **
**   $CC VERSION : \main\113 $                                                **
**                                                                            **
**   $DATE       : 2016-02-17 $                                               **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  AUTHOR    : DL-BLR-ATV-STC                                                **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : This file contains latent fault metric tests for Shared    **
**                 Resource Interconnect error detection codes and bus        **
**                 errors.                                                    **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "SriTst.h"
#include "SriTst_Cfg.h"
#include "SmuInt.h"
#include "Mtl_Trap.h"
#include "IfxCpu_reg.h"
#include "IfxScu_bf.h"
#include "IfxScu_reg.h"
#include "IfxMc_bf.h"
#include "IfxXbar_bf.h"
#include "IfxMc_reg.h"
#include "IfxMtu_reg.h"
#include "IfxLmu_reg.h"
#include "IfxDma_reg.h"
#include "IfxOvc_bf.h"
#include "IfxOvc_reg.h"
#include "IfxFlash_reg.h"
#include "IfxXbar_reg.h"
#include "IfxSrc_reg.h"
/*******************************************************************************
**                      Local Macro Definitions                               **
*******************************************************************************/
/*defines for AMU test*/
#define ADMA_TEST_CTRL_ADDRESS            (0xF870093CU)
#define SRI_INJECT_ITST_ERROR             (1U)

/*Macro to write dummy value for ECCD register as per errata MTU_TC.005 */
#define SRI_DUMMY_ECCD_WRITE            ((uint16)(0x780FU))

/* Mask to set the PSW to USER 0/1 mode                                       */
#define SRI_PSW_IO_MASK                 ( (uint32)0x00000C00 )
#define SRI_PSW_USER0_MODE              ( (uint32)0x00000000 )
#define SRI_PSW_USER1_MODE              ( (uint32)0x00000400 )

/* Number of overlay blocks per overlay module:                               */
#if  ((CHIP_ID == 21U) || (CHIP_ID == 22U) || (CHIP_ID == 23U))
    #define SRI_OVC_BLOCK_COUNT             ( (uint32)8U )
#else
    #define SRI_OVC_BLOCK_COUNT             ( (uint32)32U )
#endif

/* OVCx_OMASKy value for 32byte overlay block size:                           */
#define SRI_OMASK_32BYTE_BLOCK_SIZE     ( (uint32)0x0FFFFFE0U )

/* FLASH0_PROCOND.RAMIN value indicating disabled auto RAM initialization:    */
#define SRI_RAM_INIT_DISABLED           ((uint32)3U)

/* Count is used for walking bit pattern                                      */
#define SRI_ECC_BIT_COUNT               ( 8U )

/* SRI unmapped address */
#define SRI_UNMAPPED_ADDR               ( 0xF8000400U )

/* Error Injection types for injecting errors into the SRI system             */
#define SRI_ERR_INJ_MASTER_ADR_PH       ( 0x80000000U )
#define SRI_ERR_INJ_MASTER_WR_PH        ( 0x80000100U )
#define SRI_ERR_INJ_SLAVE_RD_PH         ( 0x80000200U )

/* MTU_CLC bits: */
#define SRI_MTU_CLC_DISR_BIT            ( 0x00000001U )
#define SRI_MTU_CLC_DISS_BIT            ( (uint32)0x00000002 )

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
#define SRI_MBIST_MEM_INIT_TIMEOUT      ( (uint32)0x00010000U )

/* MTU_MEMTEST bits:                                                          */
#define SRI_MEMTEST_PSPR0_BIT           ( 0x00010000U )
#define SRI_MEMTEST_CPU0PTEN_BIT        ( 0x00020000U )

/* MCx_ECCS bits:                                                             */
#define SRI_ECCS_BFLE_BIT               ( (uint16)0x0020 )

/* CPUx_PCON0 bits: */
#define SRI_CPU_PCON0_PCBYP_BIT         ( (uint32)0x00000002 )

/* CPUx_PCON1 bits: */
#define SRI_CPU_PCON1_PCINV_BIT         ( (uint32)0x00000001 )

/* CPUx_ICR bits:                                                             */
#define CPU_ICR_IE_BIT                  ( (uint32)0x00008000 )

/* Bitflip mask for PSPR0 ECC error injection (used by SRI invalid transaction
 * id test)
 */
#define SRI_TID_BITFLIP_MASK            ( (uint16)0x0003 )

/*
  Mask to clear LMU_MEMCON ECC error bits which may get set during LMU test.
  Bit positions cleared are : INTERR, DATAERR and ADDERR.
*/
#define SRI_LMU_MEMCON_RESTORE_MASK		( (uint32)0xFFFFFF3BU )

/* SRI_XBARSRC_MASK register bit position clearing masks  */
#define SRI_XBARSRC_MASK                ((unsigned_int)0x293F1CFFU)
#define SRI_XBARSRC_CLRR_BIT            ((unsigned_int)0x02000000U)

/* SRI_XBARINTSAT and SRI_XBARIDINTSAT register bit position clearing masks */
#if  ((CHIP_ID == 21U) || (CHIP_ID == 22U) || (CHIP_ID == 23U))
  #define SRI_XBARINTSAT_MASK            ((unsigned_int)0x80D180D1U)
  #define SRI_XBARIDINTSAT_MASK          ((unsigned_int)0x302180D1U)
#elif(CHIP_ID == 26U)
  #define SRI_XBARINTSAT_MASK            ((unsigned_int)0x81D381D3U)
  #define SRI_XBARIDINTSAT_MASK          ((unsigned_int)0x333181D3U)
#elif(CHIP_ID == 27U)
  #define SRI_XBARINTSAT_MASK            ((unsigned_int)0x81D781D7U)
  #define SRI_XBARIDINTSAT_MASK          ((unsigned_int)0x3F7181D7U)
#elif (CHIP_ID == 29U)
  #define SRI_XBARINTSAT_MASK            ((unsigned_int)0x87F787F7U)
  #define SRI_XBARIDINTSAT_MASK          ((unsigned_int)0x3F7187F7U)
#endif


/*DMA channel interrupt status bit clear mask*/
#define SRI_DMACHCSR_MASK              ((unsigned_int)0x04000000U)

/* Test pattern used to inject ECC errors into PSPR0 RAM:                     */
#define SRI_PSPR_TEST_PATTERN           ( (uint32)0xA5A5A5A5U)

/* Total number of RDBFL registers implemented for the PSPR0 RAM:             */
#if  ((CHIP_ID == 21U) || (CHIP_ID == 22U) || (CHIP_ID == 23U) \
      || (CHIP_ID == 26U) || (CHIP_ID == 27U) )
#define SRI_PSPR0_RDBFL_REG_COUNT       ( (uint8)5 )
#elif (CHIP_ID == 29U)
#define SRI_PSPR0_RDBFL_REG_COUNT       ( (uint8)9 )
#endif /* (CHIP_ID == 29U) */

/* SMU Alarm Group Index, Alarm Index and Status Bit definitions:             */
#define SMU_SRI_ECC_ADDR_PHASE_GRP      ( (uint8)SMU_ALARM_GROUP2 )
#define SMU_SRI_ECC_ADDR_PHASE_ALM      ( (uint8)SMU_ALARM_21 )
#define SMU_SRI_ECC_ADDR_PHASE_STS      ( (uint32)1U <<                        \
                                          SMU_SRI_ECC_ADDR_PHASE_ALM )

#define SMU_SRI_ECC_WRITE_PHASE_GRP     ( (uint8)SMU_ALARM_GROUP2 )
#define SMU_SRI_ECC_WRITE_PHASE_ALM     ( (uint8)SMU_ALARM_22 )
#define SMU_SRI_ECC_WRITE_PHASE_STS     ( (uint32)1U <<                        \
                                          SMU_SRI_ECC_WRITE_PHASE_ALM )

#define SMU_SRI_ECC_READ_PHASE_GRP      ( (uint8)SMU_ALARM_GROUP2 )
#define SMU_SRI_ECC_READ_PHASE_ALM      ( (uint8)SMU_ALARM_23 )
#define SMU_SRI_ECC_READ_PHASE_STS      ( (uint32)1U <<                        \
                                          SMU_SRI_ECC_READ_PHASE_ALM )

#define SMU_SRI_BUS_ERR_GRP             ( (uint8)SMU_ALARM_GROUP3 )
#define SMU_SRI_BUS_ERR_ALM             ( (uint8)SMU_ALARM_30 )
#define SMU_SRI_SRI_BUS_ERR_STS         ( (uint32)1U << SMU_SRI_BUS_ERR_ALM )

#define SMU_SRI_CPU0_ERR_GRP            ( (uint8)SMU_ALARM_GROUP0 )
#define SMU_SRI_CPU1_ERR_GRP            ( (uint8)SMU_ALARM_GROUP1 )
#define SMU_SRI_CPU2_ERR_GRP            ( (uint8)SMU_ALARM_GROUP6 )

#define SMU_SRI_CPU_PSPR_ECC_UC_ALM     ( (uint8)SMU_ALARM_7 )
#define SMU_SRI_CPU_PSPR_ECC_UC_ALM_STS ( (uint32)1U <<                        \
                                          SMU_SRI_CPU_PSPR_ECC_UC_ALM )

#define SMU_SRI_CPU_PMI_ERR_ALM         ( (uint8)SMU_ALARM_18)
#define SMU_SRI_CPU_PMI_ERR_STS         ( (uint32)1U <<                        \
                                          SMU_SRI_CPU_PMI_ERR_ALM )

#define SMU_SRI_CPU_DMI_ERR_ALM         ( (uint8)SMU_ALARM_19)
#define SMU_SRI_CPU_DMI_ERR_STS         ( (uint32)1U <<                        \
                                          SMU_SRI_CPU_DMI_ERR_ALM )

/* SMU State                                                                  */
#define SMU_STATE_RUN                   ( 1U )

/* Timeout for enabling the MTU clock: */
#define SRI_MTU_CLK_EN_TIMEOUT          ( 0x100U )

#define OPCODE_VALUE_RETURN             ( 0x9000U )

/* Clear SEQR and SRIADDERR in FLASH0_FSR:                                    */
#define FLASH0FSR_SEQR_SRIADDERR        ( 0x00401000U )

/* Invalid backup value (indicating that respective data has not been backed up:
 */
#define INVALID_BACKUP_VALUE            ( 0xFFFFFFFFU )

/* Trap classes and IDs: */
#define SRI_TRAP_CLASS_NONE             ( 0x00U )
#define SRI_TRAP_CLASS1                 ( 0x01U )
#define SRI_TRAP_CLASS4                 ( 0x04U )
#define SRI_TRAP_ID_NONE                ( 0x00U )
#define SRI_TRAP_ID2                    ( 0x02U )
#define SRI_TRAP_ID3                    ( 0x03U )
#define SRI_TRAP_ID5                    ( 0x05U )
#define SRI_TRAP_ID6                    ( 0x06U )

#ifdef __TASKING__
#define DSPR_ADD_A2(Address)  __asm("mov.a a2, %0 \n": : "d" (Address): "a2")
#endif
#ifdef __GNUC__
#define DSPR_ADD_A2(Address)  __asm("mov.a %%a2, %0 \n": : "d"(Address): "a2")
#endif
#ifdef _DIABDATA_C_TRICORE_
#if (_DIABDATA_C_TRICORE_ == 1U)
asm volatile void DSPR_ADD_A2(void* Address)
{
% reg Address
!
  mov.aa %a2, Address
  calli  %a2
}
#endif
#endif


/*******************************************************************************
**                      Local Type Definitions                                **
*******************************************************************************/

/* Type definition of backup data structure of SMU Alarm Actions
 * modified for the test */
typedef struct SriTst_BackupData
{
  Smu_AlarmActionType AlmActionBackupSRICPUxDMI;
  Smu_AlarmActionType AlmActionBackupSRICPUxPMI;
  Smu_AlarmActionType AlmActionBackupECCAdr;
  Smu_AlarmActionType AlmActionBackupECCWrite;
  Smu_AlarmActionType AlmActionBackupECCRead;
  Smu_AlarmActionType AlmActionBackupSRI;
  Smu_AlarmActionType AlmActionBackupPsprUcErr;
  Std_ReturnType GetAlmActionResult;
  uint32 SegenBackup;
  uint32 OvcRabr0Backup;
  uint32 OvcOtar0Backup;
  uint32 OvcOmask0Backup;
  uint32 OvcOvEnBackup;
  uint32 OvcOselBackup;
  uint32 OvcEnableBackup;
  boolean ProtectionTrapRegistered;
  boolean BusErrorTrapRegistered;
} SriTst_BackupDataType;

/*******************************************************************************
**                        Exported object definitions                         **
*******************************************************************************/

/*******************************************************************************
**                        Local object definitions                            **
*******************************************************************************/

#define IFX_SRI_START_SEC_CONST_8BIT_ASIL_B
#include "Ifx_MemMap.h"
/* Lookup table for current CPU SMU-SRI alarms                                */
static const uint8 SriTst_CurrentCpuSriAlm[] =
{
  (uint8)SMU_SRI_CPU0_ERR_GRP
#if (MCAL_NO_OF_CORES > 1U)
  ,(uint8)SMU_SRI_CPU1_ERR_GRP 
#if (MCAL_NO_OF_CORES == 3U)
  ,(uint8)SMU_SRI_CPU2_ERR_GRP  
#endif /* (MCAL_NO_OF_CORES == 3U) */
#endif /* (MCAL_NO_OF_CORES > 1U) */
};
#define IFX_SRI_STOP_SEC_CONST_8BIT_ASIL_B
#include "Ifx_MemMap.h"

#define IFX_SRI_START_SEC_VAR_8BIT_ASIL_B
#include "Ifx_MemMap.h"
static volatile uint8 Sri_MppTrapCount;
static volatile uint8 Sri_DseTrapCount;
static volatile uint8 Sri_DaeTrapCount;
static volatile uint8 Sri_DietrTrapCount;
static volatile uint8 Sri_PietrTrapCount;
#define IFX_SRI_STOP_SEC_VAR_8BIT_ASIL_B
#include "Ifx_MemMap.h"

#define IFX_SRI_START_SEC_VAR_32BIT_ASIL_B
#include "Ifx_MemMap.h"
static uint32  Sri_ExpectedTrapClass;
static uint32  Sri_ExpectedTrapId;
#define IFX_SRI_STOP_SEC_VAR_32BIT_ASIL_B
#include "Ifx_MemMap.h"

#define IFX_SRI_START_SEC_CONST_32BYTE_ALIGN_ASIL_B
#include "Ifx_MemMap.h"

/* this array is used for PFLash access redirection. During the SRI test      */
/* accesses to the location of dummy (32byte) will be redirected to the DSPR  */
/* to avoid any unintended redirection this array is placed in the PFlash     */
static const uint32 dummy[8] = {0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U};

#define IFX_SRI_STOP_SEC_CONST_32BYTE_ALIGN_ASIL_B
#include "Ifx_MemMap.h"



/*******************************************************************************
**                        Imported function declarations                      **
*******************************************************************************/

#define IFX_SRI_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"

/*******************************************************************************
**                        Local function prototypes                           **
*******************************************************************************/
static Sl_TstRsltType SriTst_lInit
(
  SriTst_BackupDataType* const Sri_BackupData
);

static Sl_TstRsltType SriTst_lRestore
(
  const SriTst_BackupDataType* const Sri_BackupData
);

static void SriTst_lDisableOverlay
(
  uint8 CoreId
);

static void SriTst_lEnableOverlay
(
  uint8 CoreId
);

static Sl_TstRsltType SriTst_lCPUDecodersTst
(
  const Sl_ParamSetType ParamSetIndex,
  uint32* const TstSignature
);

static Sl_TstRsltType SriTst_lAdditionalDecodersTst
(
  const Sl_ParamSetType ParamSetIndex,
  uint32* const TstSignature
);

static Sl_TstRsltType SriTst_lLMUDecoderTst
(
  uint32* const TstSignature,
  uint32* const SriTstLMUTstAdr
);
#if (CHIP_ID == 27U) || (CHIP_ID == 29U)
static Sl_TstRsltType SriTst_lChkAmuErrTst
(
  uint32* const TstSignature
);
#endif /* (CHIP_ID == 27U) || (CHIP_ID == 29U) */

static Sl_TstRsltType SriTst_lPMUDFlashDecoderTst
(
  uint32* const TstSignature,
  uint32* const SriTstPMUDFlashTstAdr
);

static Sl_TstRsltType SriTst_lPMUPFlashDecoderTst
(
  uint32* const TstSignature,
  uint32* const SriTstPMUPFlashTstAdr
);

static Sl_TstRsltType SriTst_lSlaveAddrDecoderTst
(
  uint32* const TstSignature,
  uint32* const SlaveAddress,
  uint8 AlarmGroup,
  uint8 SMUAlarm
);

static Sl_TstRsltType SriTst_lSlaveAddrDecoderXbarTst
(
  uint32* const TstSignature
);

static Sl_TstRsltType SriTst_lSlaveDataDecoderTst
(
  uint32* const TstSignature,
  uint32* const SlaveAddress,
  uint8 AlarmGroup,
  uint8 SMUAlarm
);

static Sl_TstRsltType SriTst_lSlaveDataDecoderXbarTst
(
  uint32* const TstSignature
);

static Sl_TstRsltType SriTst_lMasterDataDecoderTst
(
  uint32* const TstSignature,
  uint32* const SlaveAddress,
  uint8 AlarmGroup,
  uint8 SMUAlarm
);

static Sl_TstRsltType SriTst_lMasterDataDecoderPMITst
(
  uint32* const TstSignature,
  uint32* const SlaveAddress
);

static Sl_TstRsltType SriTst_lDMADecoderTst
(
  const Sl_ParamSetType ParamSetIndex,
  uint32* const TstSignature
);

static Sl_TstRsltType SriTst_lInvalidTransactionIdTst
(
  const Sl_ParamSetType ParamSetIndex,
  uint32* const TstSignature
);

static Sl_TstRsltType SriTst_lInjectPsprError
(
  uint32* const TestAddress,
  const uint8 CoreId
);

static Sl_TstRsltType SriTst_lEnablePspr0Mc
(
  void
);

static Sl_TstRsltType SriTst_lDisablePspr0Mc
(
  void
);

static Sl_TstRsltType SriTst_lEnableMtuClock
(
  uint32* const MtuClcBackup
);

static Sl_TstRsltType SriTst_lDisableMtuClock
(
  void
);

static Sl_TstRsltType SriTst_lDoDMADecoderTst
(
  const Sl_ParamSetType ParamSetIndex,
  uint32* const TstSignature
);

static Sl_TstRsltType SriTst_lSriBusErrorsTst
(
  const Sl_ParamSetType ParamSetIndex,
  uint32* const TstSignature
);
#ifdef _DIABDATA_C_TRICORE_
#if (_DIABDATA_C_TRICORE_ == 1U)
/*
	Use of attribute frame pointer is performed to ensure that DIAB 
	doesnt use FCALL instruction while generating assembly, when this 
	API is called.
	Windriver Ticket No: TCDIAB-13317- Tricore: exception when 
	compiler use fcall
*/
__attribute__ ((use_frame_pointer)) 
#endif
#endif

static Sl_TstRsltType  SriTst_lUser0AccTst
(
  uint32* const TstSignature
);

#ifdef _DIABDATA_C_TRICORE_
#if (_DIABDATA_C_TRICORE_ == 1U)
/*
	Use of attribute frame pointer is performed to ensure that DIAB 
	doesnt use FCALL instruction while generating assembly, when this 
	API is called.
	Windriver Ticket No: TCDIAB-13317- Tricore: exception when 
	compiler use fcall
*/
__attribute__ ((use_frame_pointer)) 
#endif
#endif
static Sl_TstRsltType  SriTst_lUser1AccTst
(
  uint32* const TstSignature
);

static Sl_TstRsltType  SriTst_lUnmappedAdrTst
(
  uint32* const TstSignature
);

static Sl_TstRsltType  SriTst_lUnsupportedOCTst
(
  uint32* const TstSignature
);

static boolean SriTst_lProtectionTrapHandler
(
  const uint32 TrapId
);

static boolean SriTst_lBusErrorTrapHandler
(
  const uint32 TrapId
);

/*******************************************************************************
**                    Local inline function definitions                       **
*******************************************************************************/

/*******************************************************************************
**                    Configuration error checking                            **
*******************************************************************************/

/*******************************************************************************
**                         Function definitions                               **
*******************************************************************************/

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : Sl_TstRsltType SriTst_SriTst                                      **
**          (                                                                 **
**            Sl_ParamSetIndex ParamSetIndex,                                 **
**            uint8 TstSeed,                                                  **
**            uint32* TstSignature                                            **
**          )                                                                 **
**                                                                            **
** Description : Performs a latent fault metric test of the SRI XBar.         **
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
** Parameters (out): TstSignature - Test signature generated by the test.     **
**                                                                            **
** Return value : SRI_SUCCESS - Test succeeded                                **
**                SRI_NOTEXECUTED - The test has not been executed or at      **
**                                  least was interrupted before a valid      **
**                                  result could be generated.                **
**                SRI_INVPARAMERR - Test failed because an invalid.           **
**                SRI_SMU_STATEERR - The test cannot be executed because the  **
**                                   SMU is in the wrong state.               **
**                SRI_SMU_CLRALMSTSERR - The test failed because clearing the **
**                                       SMU alarm failed.                    **
**                SRI_SMU_ALMSTSERR -  Test failed because there is already   **
**                                      watchdog alarm present within the SMU.**
**                SRI_SMU_SETALMACTIONERR - Test failed because setting the   **
**                                          SMU alarm action failed.          **
**                SRI_SMU_GETALMACTIONERR - Test failed because getting the   **
**                                          SMU alarm action failed.          **
**                SRI_UNSUPP_OCERR - Test failed because although an          **
**                                   unsupported Opcode was used it got not   **
**                                   detected and therefore no trap had been  **
**                                   generated.                               **
**                SRI_UNMAPPED_ACCERR - Test failed because an access to a    **
**                                      memory location that is not mapped to **
**                                      any SRI device did not generate a trap**
**                SRI_USER1_ACCERR - The test has failed because the USER1    **
**                                   mode access to a supervisor-mode-only    **
**                                   register gets not blocked.               **
**                SRI_USER0_ACCERR - Test failed because access to a          **
**                                   supervisor-mode-only register got not    **
**                                   blocked although it was executed in      **
**                                   USER0 mode.                              **
**                SRI_CPU_DMI_ECC_ADR - Test failed because the CPU DMI ECC   **
**                                      logic did not detect a corrupted      **
**                                      address phase                         **
**                SRI_CPU_DMI_ECC_DATA - Test failed because the CPU DMI ECC  **
**                                      logic did not detect a corrupted data **
**                                      write phase in slave data decoder     **
**                SRI_CPU_DMI_ECC_MDATA - Test failed because the CPU DMI ECC **
**                                      logic did not detect a corrupted data **
**                                      write phase in Master data decoder.   **
**                SRI_CPU_PMI_ECC_ADR - Test failed because the CPU PMI ECC   **
**                                      logic did not detect a corrupted      **
**                                      address phase.                        **
**                SRI_CPU_PMI_ECC_DATA - Test failed because the CPU PMI ECC  **
**                                      logic did not detect a corrupted data **
**                                      write phase in slave data decoder.    **
**                SRI_CPU_PMI_ECC_MDATA -	Test failed because the CPU PMI ECC **
**                                      logic did not detect a corrupted data **
**                                      write phase in master data decoder.   **
**               SRI_LMU_ECC_DATA - Test failed because the LMU data decoder  **
**                                 did not recognize a corrupted data phase.  **
**               SRI_LMU_ECC_ADDRESS - Test failed because the LMU address    **
**                                  decoder did not recognize a corrupted     **
**                                  address phase.                            **
**               SRI_PMUDF_ECC_DATA - Test failed because the PMU DFlash data **
**                                  decoder did not recognize a corrupted data**
**                                  phase.                                    **
**               SRI_PMUDF_ECC_ADR - Test failed because the PMU DFlash       **
**                                   address decoder did not recognize a      **
**                                   corrupted address phase.                 **
**               SRI_PMUPF_ECC_ADR - Test failed because the PMU PFlash       **
**                                   address decoder did not recognize a      **
**                                   corrupted address phase.                 **
**               SRI_TRAP_FAILURE - Registering or unregistering a trap       **
**                                  handler failed                            **
**                                                                            **
*******************************************************************************/
Sl_TstRsltType SriTst_SriTst
(
  const Sl_ParamSetType ParamSetIndex,
  const uint8 TstSeed,
  uint32* const TstSignature
)
{
  Sl_TstRsltType         Result     = SRI_NOTEXECUTED;
  Sl_TstRsltType         ResRestore = SRI_NOTEXECUTED;
  SriTst_BackupDataType  Sri_BackupData;

   /* Initialize Test Signature:                                              */
  *TstSignature = (uint32)CRC32(TEST_ID_SRI_TST, TstSeed);


  /* Check for valid input parameters                                         */
  if (ParamSetIndex > (SRI_EDC_BUSERR_TST_CFG_PARAM_COUNT - 1U))
  {
    Result = SRI_INVPARAMERR;
  } /* if (ParamSetIndex > (SRI_EDC_BUSERR_TST_CFG_PARAM_COUNT - 1U)) */
  else if (SMU_RUN_STATE != Smu_GetSmuState())
  {
    Result = SRI_SMU_STATEERR;
  } /* else if (SMU_RUN_STATE != Smu_GetSmuState()) */
  else
  {
    Result = SriTst_lInit(&Sri_BackupData);
    if (SRI_SUCCESS == Result)
    {
      /* Test all Decoders related to the CPU this test is executed on        */
      Result = SriTst_lCPUDecodersTst(ParamSetIndex, TstSignature);

      if (SRI_SUCCESS == Result)
      {

          Result = SriTst_lAdditionalDecodersTst
                   (
                     ParamSetIndex,
                     TstSignature
                   );
        if (SRI_SUCCESS == Result)
        {
          Result = SriTst_lSriBusErrorsTst(ParamSetIndex, TstSignature);
        } /* if (SRI_SUCCESS == TmpResult1) */			
      } /* if (SRI_SUCCESS == TmpResult1) */

    } /* if (SRI_SUCCESS == Result) */
    
    ResRestore = SriTst_lRestore(&Sri_BackupData);

    if(SRI_SUCCESS == Result)
    {
      Result = ResRestore;
    }/* if(SRI_SUCCESS == Result)*/
  } /* if ((ParamSetIndex <= (SRI_EDC_BUSERR_TST_CFG_PARAM_COUNT - 1U)) &&
           (SMU_RUN_STATE == Smu_GetSmuState())) */

  /* Add final test result to test signature: */
  *TstSignature = (uint32)CRC32(*TstSignature, (uint32)Result);

  return Result;
} /* SriTst_SriTst */

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static Sl_TstRsltType SriTst_lInit                      **
**                    (                                                       **
**                      SriTst_BackupDataType * const Sri_BackupData          **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : Sri_BackupData - Pointer to SriTst_BackupDataType       **
**                    structure that Holds a backup of the current SMU alarm  **
**                    action configuration of the SMU alarms and the SFR      **
**                    configuration that will be changed by this test.        **
** Return value     : SRI_NOTEXECUTED - The initialization has not yet been   **
**                                      executed or did for some reason not   **
**                                      generate a valid result.              **
**                    SRI_SUCCESS - Initialization succeeded.                 **
**                    SRI_SMU_SETALMACTIONERR - Initialization failed because **
**                                              setting an SMU alarm action   **
**                                              failed.                       **
**                    SRI_SMU_GETALMACTIONERR - Initialization failed because **
**                                               getting an SMU alarm action  **
**                                               failed.                      **
**                    SRI_SMU_ALMSTSERR -Initialization failed because there  **
**                                         is already an SMU alarm present.   **
**                    SRI_TRAP_FAILURE - Registering a trap handler failed    **
** Description      : This function does a backup of the current SMU alarm    **
**                    actions and the SF- registers that will be overwritten  **
**                    by this test. It also sets the SMU actions for the SRI  **
**                    alarms to “no action”.                                  **
*******************************************************************************/
static Sl_TstRsltType SriTst_lInit
(
  SriTst_BackupDataType * const Sri_BackupData
)
{
  Sl_TstRsltType      Result = SRI_NOTEXECUTED;
  Std_ReturnType      SmuResult1, SmuResult2, SmuResult3, SmuResult4, 
                      SmuResult5, SmuResult6, SmuResult7;
 
  Smu_FSPActionType   FspActionBackup;
  uint32              AlarmStatus1 = 0U;
  uint32              AlarmStatus2 = 0U;
  uint32              AlarmStatus3 = 0U;
  uint32              AlarmStatus4 = 0U;  
  uint32              AlarmStatus  = 0U;
  uint8               CoreId;
  uint32              i;

  /* Read the core Id                                                         */
  CoreId = Mcal_GetCoreId();

  /* No trap expected, yet. Initialize expected trap class and ID:            */
  Sri_ExpectedTrapClass = SRI_TRAP_CLASS_NONE;
  Sri_ExpectedTrapId = SRI_TRAP_ID_NONE;

  /* Initialize status flags for registration of trap handlers:               */
  Sri_BackupData->ProtectionTrapRegistered = (boolean)FALSE;
  Sri_BackupData->BusErrorTrapRegistered = (boolean)FALSE;

  /* Backup overlay control data                                              */
  switch (CoreId)
  {
    case 0:
      Sri_BackupData->OvcRabr0Backup  = OVC0_RABR0.U;
      Sri_BackupData->OvcOtar0Backup  = OVC0_OTAR0.U;
      Sri_BackupData->OvcOmask0Backup = OVC0_OMASK0.U;
      Sri_BackupData->OvcOselBackup   = OVC0_OSEL.U;

      /* Backup range enable: */
      Sri_BackupData->OvcOvEnBackup = 0U;
      for (i = 0U; i < SRI_OVC_BLOCK_COUNT; i++)
      {
        if ((MODULE_OVC0.BLK[i].RABR.U &
             (uint32)((uint32)1U << IFX_OVC_BLK_RABR_OVEN_OFF)) > 0U)
        {
          Sri_BackupData->OvcOvEnBackup |= (uint32)((uint32)1U << (uint32)i);
        } /* if ((MODULE_OVC0.BLK[i].RABR.U &
                  (uint32)((uint32)1U << IFX_OVC_BLK_RABR_OVEN_OFF)) > 0U) */
      } /* for (i = 0U; i < SRI_OVC_BLOCK_COUNT; i++) */

      /* Disable all overlay ranges: */
      SCU_OVCCON.U = (uint32)(((uint32)1U << (uint32)IFX_SCU_OVCCON_CSEL0_OFF) |
                              ((uint32)1U << (uint32)IFX_SCU_OVCCON_OVSTP_OFF));
    break;
#if (MCAL_NO_OF_CORES > 1U)
    case 1:
      Sri_BackupData->OvcRabr0Backup  = OVC1_RABR0.U;
      Sri_BackupData->OvcOtar0Backup  = OVC1_OTAR0.U;
      Sri_BackupData->OvcOmask0Backup = OVC1_OMASK0.U;
      Sri_BackupData->OvcOselBackup   = OVC1_OSEL.U;

      /* Backup range enable: */
      Sri_BackupData->OvcOvEnBackup = 0U;
      for (i = 0U; i < SRI_OVC_BLOCK_COUNT; i++)
      {
        if ((MODULE_OVC1.BLK[i].RABR.U &
             (uint32)((uint32)1U << IFX_OVC_BLK_RABR_OVEN_OFF)) > 0U)
        {
          Sri_BackupData->OvcOvEnBackup |= (uint32)((uint32)1U << (uint32)i);
        } /* if ((MODULE_OVC1.BLK[i].RABR.U &
                  (uint32)((uint32)1U << IFX_OVC_BLK_RABR_OVEN_OFF)) > 0U) */
      } /* for (i = 0U; i < SRI_OVC_BLOCK_COUNT; i++) */

      /* Disable all overlay ranges: */
      SCU_OVCCON.U = (uint32)(((uint32)1U << (uint32)IFX_SCU_OVCCON_CSEL1_OFF) |
                              ((uint32)1U << (uint32)IFX_SCU_OVCCON_OVSTP_OFF));
    break;
#if (MCAL_NO_OF_CORES == 3U)
    case 2:
      Sri_BackupData->OvcRabr0Backup  = OVC2_RABR0.U;
      Sri_BackupData->OvcOtar0Backup  = OVC2_OTAR0.U;
      Sri_BackupData->OvcOmask0Backup = OVC2_OMASK0.U;
      Sri_BackupData->OvcOselBackup   = OVC2_OSEL.U;

      /* Backup range enable: */
      Sri_BackupData->OvcOvEnBackup = 0U;
      for (i = 0U; i < SRI_OVC_BLOCK_COUNT; i++)
      {
        if ((MODULE_OVC2.BLK[i].RABR.U &
             (uint32)((uint32)1U << IFX_OVC_BLK_RABR_OVEN_OFF)) > 0U)
        {
          Sri_BackupData->OvcOvEnBackup |= (uint32)((uint32)1U << (uint32)i);
        } /* if ((MODULE_OVC2.BLK[i].RABR.U &
                  (uint32)((uint32)1U << IFX_OVC_BLK_RABR_OVEN_OFF)) > 0U) */
      } /* for (i = 0U; i < SRI_OVC_BLOCK_COUNT; i++) */

      /* Disable all overlay ranges: */
      SCU_OVCCON.U = (uint32)(((uint32)1U << (uint32)IFX_SCU_OVCCON_CSEL2_OFF) |
                              ((uint32)1U << (uint32)IFX_SCU_OVCCON_OVSTP_OFF));
    break;
#endif /* (MCAL_NO_OF_CORES == 3U) */
#endif /* (MCAL_NO_OF_CORES > 1U) */

    default:
      /* do nothing here as only overlay control registers for core 0,1,2     */
      /* exist. As nothing will be overwritten nothing to backup              */
    break;
  } /* switch (CoreId) */

  /* Backup global overlay system enable (independent from CPU core           */
  Sri_BackupData->OvcEnableBackup = SCU_OVCENABLE.U;

  /* Backup SEGEN register contents                                           */
  Sri_BackupData->SegenBackup = (uint32)MFCR(CPU_SEGEN);


  /* Backup SMU Alarm Action for SRI Address Phase ECC Errors:                */
  SmuResult1 = Smu_GetAlarmAction(SMU_SRI_ECC_ADDR_PHASE_GRP,
                                  SMU_SRI_ECC_ADDR_PHASE_ALM,
                                  &(Sri_BackupData->AlmActionBackupECCAdr),
                                  &(FspActionBackup));
  /* Backup SMU Alarm Action for SRI Write Phase ECC Errors:                  */
  SmuResult2 = Smu_GetAlarmAction(SMU_SRI_ECC_WRITE_PHASE_GRP,
                                  SMU_SRI_ECC_WRITE_PHASE_ALM,
                                  &(Sri_BackupData->AlmActionBackupECCWrite),
                                  &(FspActionBackup));
  /* Backup SMU Alarm Action for SRI Read Phase ECC Errors:                   */
  SmuResult3 = Smu_GetAlarmAction(SMU_SRI_ECC_READ_PHASE_GRP,
                                  SMU_SRI_ECC_READ_PHASE_ALM,
                                  &(Sri_BackupData->AlmActionBackupECCRead),
                                  &(FspActionBackup));
  /* Backup SMU Alarm Action for SRI Bus Errors:                              */
  SmuResult4 = Smu_GetAlarmAction(SMU_SRI_BUS_ERR_GRP,
                                  SMU_SRI_BUS_ERR_ALM,
                                  &(Sri_BackupData->AlmActionBackupSRI),
                                  &(FspActionBackup));
  /* Backup SMU Alarm Action for current CPU DMI SRI Errors:                  */
  SmuResult5 = Smu_GetAlarmAction(SriTst_CurrentCpuSriAlm[CoreId],
                                  SMU_SRI_CPU_DMI_ERR_ALM,
                                  &(Sri_BackupData->AlmActionBackupSRICPUxDMI),
                                  &(FspActionBackup));
  /* Backup SMU Alarm Action for current CPU PMI SRI Errors:                  */
  SmuResult6 = Smu_GetAlarmAction(SriTst_CurrentCpuSriAlm[CoreId],
                                  SMU_SRI_CPU_PMI_ERR_ALM,
                                  &(Sri_BackupData->AlmActionBackupSRICPUxPMI),
                                  &(FspActionBackup));
  /* Backup SMU Alarm Action for CPU0 PSPR uncorrectable ECC errors: */
  SmuResult7 = Smu_GetAlarmAction(SMU_SRI_CPU0_ERR_GRP,
                                  SMU_SRI_CPU_PSPR_ECC_UC_ALM,
                                  &(Sri_BackupData->AlmActionBackupPsprUcErr),
                                  &(FspActionBackup));

  if ( (SmuResult1 != E_OK) || (SmuResult2 != E_OK) || (SmuResult3 != E_OK) ||
       (SmuResult4 != E_OK) || (SmuResult5 != E_OK) || (SmuResult6 != E_OK) ||
       (SmuResult7 != E_OK) )
  {
    Result = SRI_SMU_GETALMACTIONERR;
    Sri_BackupData->GetAlmActionResult = E_NOT_OK;
  } /* if ( (SmuResult1 != E_OK) || (SmuResult2 != E_OK) ||
            (SmuResult3 != E_OK) || (SmuResult4 != E_OK) ||
            (SmuResult5 != E_OK) || (SmuResult6 != E_OK) ||
            (SmuResult7 != E_OK) ) */
  else
  {
    Sri_BackupData->GetAlmActionResult = E_OK;
  } /* if ( (SmuResult1 == E_OK) && (SmuResult2 == E_OK) &&
            (SmuResult3 == E_OK) && (SmuResult4 == E_OK) &&
            (SmuResult5 == E_OK) && (SmuResult6 == E_OK) &&
            (SmuResult7 == E_OK) ) */

  /* Check that no SMU alarm triggered by the test is already set: */
  if (SRI_NOTEXECUTED == Result)
  {
    SmuResult1 = Smu_GetAlarmStatus(SMU_SRI_ECC_ADDR_PHASE_GRP, &AlarmStatus1);
    SmuResult2 = Smu_GetAlarmStatus(SMU_SRI_BUS_ERR_GRP, &AlarmStatus2);
    SmuResult3 = Smu_GetAlarmStatus(SriTst_CurrentCpuSriAlm[CoreId],
                                    &AlarmStatus3);
    SmuResult4 = Smu_GetAlarmStatus(SMU_SRI_CPU0_ERR_GRP, &AlarmStatus4);
    if ( (SmuResult1 != E_OK) || (SmuResult2 != E_OK) || 
         (SmuResult3 != E_OK) || (SmuResult4 != E_OK) )
    {
      Result = SRI_SMU_GETALMSTSERR;
    } /* if ( (SmuResult1 != E_OK) || (SmuResult2 != E_OK) ||
              (SmuResult3 != E_OK) || (SmuResult4 != E_OK) ) */
    else
    {
      AlarmStatus = ( (AlarmStatus3 & SMU_SRI_CPU_PMI_ERR_STS)     |
                      (AlarmStatus3 & SMU_SRI_CPU_DMI_ERR_STS)     |
                      (AlarmStatus1 & SMU_SRI_ECC_ADDR_PHASE_STS)  |
                      (AlarmStatus1 & SMU_SRI_ECC_WRITE_PHASE_STS) |
                      (AlarmStatus1 & SMU_SRI_ECC_READ_PHASE_STS)  |
                      (AlarmStatus2 & SMU_SRI_SRI_BUS_ERR_STS)     |
                      (AlarmStatus4 & SMU_SRI_CPU_PSPR_ECC_UC_ALM_STS) );
      if (0U != AlarmStatus)
      {
        Result = SRI_SMU_ALMSTSERR;
      } /* if (0U != AlarmStatus) */
    } /* if ( (SmuResult1 == E_OK) && (SmuResult2 == E_OK) &&
              (SmuResult3 == E_OK) && (SmuResult4 == E_OK) ) */
  } /* if (SRI_NOTEXECUTED == Result) */

  /* Set alarm action of all SMU alarms triggered by the test to "no action": */
  if (SRI_NOTEXECUTED == Result)
  {
    SmuResult1= Smu_SetAlarmAction(SMU_SRI_ECC_ADDR_PHASE_GRP,
                                   SMU_SRI_ECC_ADDR_PHASE_ALM,
                                   SMU_ALARM_ACTION_NONE);
    SmuResult2= Smu_SetAlarmAction(SMU_SRI_ECC_WRITE_PHASE_GRP,
                                   SMU_SRI_ECC_WRITE_PHASE_ALM,
                                   SMU_ALARM_ACTION_NONE);
    SmuResult3= Smu_SetAlarmAction(SMU_SRI_ECC_READ_PHASE_GRP,
                                   SMU_SRI_ECC_READ_PHASE_ALM,
                                   SMU_ALARM_ACTION_NONE);
    SmuResult4= Smu_SetAlarmAction(SMU_SRI_BUS_ERR_GRP,
                                   SMU_SRI_BUS_ERR_ALM,
                                   SMU_ALARM_ACTION_NONE);
    SmuResult5= Smu_SetAlarmAction(SriTst_CurrentCpuSriAlm[CoreId],
                                   SMU_SRI_CPU_DMI_ERR_ALM,
                                   SMU_ALARM_ACTION_NONE);
    SmuResult6= Smu_SetAlarmAction(SriTst_CurrentCpuSriAlm[CoreId],
                                   SMU_SRI_CPU_PMI_ERR_ALM,
                                   SMU_ALARM_ACTION_NONE);
    SmuResult7= Smu_SetAlarmAction(SMU_SRI_CPU0_ERR_GRP,
                                   SMU_SRI_CPU_PSPR_ECC_UC_ALM,
                                   SMU_ALARM_ACTION_NONE);

    if ( (SmuResult1 != E_OK) || (SmuResult2 != E_OK) || (SmuResult3 != E_OK) ||
         (SmuResult4 != E_OK) || (SmuResult5 != E_OK) || (SmuResult6 != E_OK) ||
         (SmuResult7 != E_OK))
 
    {
      Result = SRI_SMU_SETALMACTIONERR;
    } /* if ( (SmuResult1 != E_OK) || (SmuResult2 != E_OK) ||
              (SmuResult3 != E_OK) || (SmuResult4 != E_OK) ||
              (SmuResult5 != E_OK) || (SmuResult6 != E_OK) ||
              (SmuResult7 != E_OK) ) */
    else
    {
      /* Clear trap counters:                                                 */
      Sri_MppTrapCount        = 0U;
      Sri_DseTrapCount        = 0U;
      Sri_DaeTrapCount        = 0U;
      Sri_DietrTrapCount      = 0U;
      Sri_PietrTrapCount      = 0U;

      /* Register protection error and bus error trap handlers:               */
      Result = TRAP_RegisterTrapHandler(SRI_TRAP_CLASS1,
                                        &SriTst_lProtectionTrapHandler);
      if(TRAP_E_SUCCESS == Result)
      {
        Sri_BackupData->ProtectionTrapRegistered = (boolean)TRUE;
        Result = TRAP_RegisterTrapHandler(SRI_TRAP_CLASS4,
                                          &SriTst_lBusErrorTrapHandler);
        if (TRAP_E_SUCCESS == Result)
        {
          Sri_BackupData->BusErrorTrapRegistered = (boolean)TRUE;
          Result = SRI_SUCCESS;
        } /* if (TRAP_E_SUCCESS == Result) */
        else
        {
          Result = SRI_TRAP_FAILURE;
        } /* if (TRAP_E_SUCCESS != Result) */
      } /* if(TRAP_E_SUCCESS == Result) */
      else
      {
        Result = SRI_TRAP_FAILURE;
      } /* if(TRAP_E_SUCCESS != Result) */
    } /* if ( (SmuResult1 == E_OK) && (SmuResult2 == E_OK) &&
              (SmuResult3 == E_OK) && (SmuResult4 == E_OK) &&
              (SmuResult5 == E_OK) && (SmuResult6 == E_OK) &&
              (SmuResult7 == E_OK) ) */
  } /* if (SRI_NOTEXECUTED == Result) */

  return Result;
} /* SriTst_lInit */

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static Sl_TstRsltType SriTst_lRestore                   **
**                    (                                                       **
**                      const SriTst_BackupDataType * const Sri_BackupData    **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters (in)  : Sri_BackupData - Pointer to SriTst_BackupDataType       **
**                    structure that holds a backup of the SMU alarm action   **
**                    configuration of the SMU alarms and the SFR             **
**                    configuration registers that got overwritten by a test. **
**                                                                            **
** Parameters (out) : None.                                                   **
**                                                                            **
** Return value :     SRI_NOTEXECUTED - Program flow consistency error.This   **
**                                      value should never be returned        **
**                    SRI_SUCCESS - Restore succeeded.                        **
**                    SRI_SMU_SETALMACTIONERR - Restore failed because        **
**                                              setting an SMU alarm action   **
**                                              failed.                       **
**                    SRI_TRAP_FAILURE - Unregistering a trap handler failed  **
**                                                                            **
** Description      : This function restores the SMU alarm actions and the    **
**                    SFR register configuration  that have been changed      **
**                    during this test.                                       **
*******************************************************************************/
static Sl_TstRsltType SriTst_lRestore
(
  const SriTst_BackupDataType * const Sri_BackupData
)
{
  Sl_TstRsltType      Result = SRI_NOTEXECUTED;
  Std_ReturnType      SmuResult1, SmuResult2, SmuResult3, SmuResult4, 
                      SmuResult5, SmuResult6, SmuResult7;
  uint8               CoreId;  

  /* Read the core Id                                                         */
  CoreId = Mcal_GetCoreId();

  /* Clear the REC, SEQR and SRIADDERR */
  FLASH0_FSR.U = FLASH0FSR_SEQR_SRIADDERR;

  /* Restore global overlay system enable (independent from CPU core)         */
  Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);
  SCU_OVCENABLE.U = Sri_BackupData->OvcEnableBackup;
  Mcal_SetSafetyENDINIT_Timed();

  /* Restore overlay control 0 data                                           */
  switch (CoreId)
  {
    case 0:
      /* Disable overlay before changing the configuration: */
      OVC0_RABR0.U = 0U;

      OVC0_OTAR0.U  = Sri_BackupData->OvcOtar0Backup;
      OVC0_OMASK0.U = Sri_BackupData->OvcOmask0Backup;
      OVC0_RABR0.U  = Sri_BackupData->OvcRabr0Backup;

      /* Restore overlay enable for all overlay ranges: */
      OVC0_OSEL.U   = Sri_BackupData->OvcOvEnBackup;
      SCU_OVCCON.U = (uint32)(((uint32)1U << (uint32)IFX_SCU_OVCCON_CSEL0_OFF) |
                              ((uint32)1U <<
                               (uint32)IFX_SCU_OVCCON_OVSTRT_OFF));

      /* Ensure OVSTART command has been executed before again changing OSEL: */
      ISYNC();

      /* Restore OSEL: */
      OVC0_OSEL.U = Sri_BackupData->OvcOselBackup;
    break;

#if (MCAL_NO_OF_CORES > 1U)
    case 1:
      /* Disable overlay before changing the configuration: */
      OVC1_RABR0.U = 0U;

      OVC1_OTAR0.U  = Sri_BackupData->OvcOtar0Backup;
      OVC1_OMASK0.U = Sri_BackupData->OvcOmask0Backup;
      OVC1_RABR0.U  = Sri_BackupData->OvcRabr0Backup;

      /* Restore overlay enable for all overlay ranges: */
      OVC1_OSEL.U   = Sri_BackupData->OvcOvEnBackup;
      SCU_OVCCON.U = (uint32)(((uint32)1U << (uint32)IFX_SCU_OVCCON_CSEL1_OFF) |
                              ((uint32)1U <<
                               (uint32)IFX_SCU_OVCCON_OVSTRT_OFF));

      /* Ensure OVSTART command has been executed before again changing OSEL: */
      ISYNC();

      /* Restore OSEL: */
      OVC1_OSEL.U = Sri_BackupData->OvcOselBackup;
    break;

#if (MCAL_NO_OF_CORES == 3U)
    case 2:
      /* Disable overlay before changing the configuration: */
      OVC2_RABR0.U = 0U;

      OVC2_OTAR0.U  = Sri_BackupData->OvcOtar0Backup;
      OVC2_OMASK0.U = Sri_BackupData->OvcOmask0Backup;
      OVC2_RABR0.U  = Sri_BackupData->OvcRabr0Backup;

      /* Restore overlay enable for all overlay ranges: */
      OVC2_OSEL.U   = Sri_BackupData->OvcOvEnBackup;
      SCU_OVCCON.U = (uint32)(((uint32)1U << (uint32)IFX_SCU_OVCCON_CSEL2_OFF) |
                              ((uint32)1U <<
                               (uint32)IFX_SCU_OVCCON_OVSTRT_OFF));

      /* Ensure OVSTART command has been executed before again changing OSEL: */
      ISYNC();

      /* Restore OSEL: */
      OVC2_OSEL.U = Sri_BackupData->OvcOselBackup;
    break;

#endif /* (MCAL_NO_OF_CORES == 3U)  */
#endif /* (MCAL_NO_OF_CORES > 1U) */

    default:
      /* do nothing here as only overlay control registers for core 0,1,2     */
      /* exist. As nothing has been overwritten nothing to restore here       */
    break;
  } /* switch (CoreId) */

  /* Restore SEGEN register contents                                          */
  Mcal_ResetENDINIT();
  MTCR(CPU_SEGEN, Sri_BackupData->SegenBackup);
  Mcal_SetENDINIT();

  /* Unregister trap handlers:                                                */
  if ((boolean)FALSE != Sri_BackupData->ProtectionTrapRegistered)
  {
    if (TRAP_E_SUCCESS != TRAP_UnregisterTrapHandler(SRI_TRAP_CLASS1))
    {
      Result = SRI_TRAP_FAILURE;
    } /* if (TRAP_E_SUCCESS != TRAP_UnregisterTrapHandler(SRI_TRAP_CLASS1)) */
  } /* if ((boolean)FALSE != Sri_BackupData->ProtectionTrapRegistered) */
  if ((boolean)FALSE != Sri_BackupData->BusErrorTrapRegistered)
  {
    if (TRAP_E_SUCCESS != TRAP_UnregisterTrapHandler(SRI_TRAP_CLASS4))
    {
      Result = SRI_TRAP_FAILURE;
    } /* if (TRAP_E_SUCCESS != TRAP_UnregisterTrapHandler(SRI_TRAP_CLASS4)) */
  } /* if ((boolean)FALSE != Sri_BackupData->BusErrorTrapRegistered) */
  
  /* Clear the XBAR_ARBCONx registers */
  XBAR_ARBCON0.U |= (unsigned_int)((unsigned_int)IFX_XBAR_ARBCON_INTACK_MSK <<
                                   IFX_XBAR_ARBCON_INTACK_OFF);
  #if(CHIP_ID == 26U) ||(CHIP_ID == 27U) || (CHIP_ID == 29U)                                   
  XBAR_ARBCON1.U |= (unsigned_int)((unsigned_int)IFX_XBAR_ARBCON_INTACK_MSK <<
                                   IFX_XBAR_ARBCON_INTACK_OFF);
  #endif
  #if(CHIP_ID == 27U) || (CHIP_ID == 29U)  
  XBAR_ARBCON2.U |= (unsigned_int)((unsigned_int)IFX_XBAR_ARBCON_INTACK_MSK <<
                                   IFX_XBAR_ARBCON_INTACK_OFF);
  #endif                                   
  XBAR_ARBCON4.U |= (unsigned_int)((unsigned_int)IFX_XBAR_ARBCON_INTACK_MSK <<
                                   IFX_XBAR_ARBCON_INTACK_OFF);
  XBAR_ARBCON6.U |= (unsigned_int)((unsigned_int)IFX_XBAR_ARBCON_INTACK_MSK <<
                                   IFX_XBAR_ARBCON_INTACK_OFF);
  XBAR_ARBCON7.U |= (unsigned_int)((unsigned_int)IFX_XBAR_ARBCON_INTACK_MSK <<
                                   IFX_XBAR_ARBCON_INTACK_OFF);
  #if(CHIP_ID == 26U) ||(CHIP_ID == 27U) || (CHIP_ID == 29U)                                   
  XBAR_ARBCON8.U |= (unsigned_int)((unsigned_int)IFX_XBAR_ARBCON_INTACK_MSK <<
                                   IFX_XBAR_ARBCON_INTACK_OFF);
  #endif                                   
  XBAR_ARBCOND.U |= (unsigned_int)((unsigned_int)IFX_XBAR_ARBCON_INTACK_MSK <<
                                   IFX_XBAR_ARBCON_INTACK_OFF);

  /* Clear all the bits of XBAR_INTSAT and XBAR_IDINTSAT registers */
  XBAR_INTSAT.U = ((XBAR_INTSAT.U & SRI_XBARINTSAT_MASK) | (SRI_XBARINTSAT_MASK));
  XBAR_IDINTSAT.U = ((XBAR_IDINTSAT.U & SRI_XBARIDINTSAT_MASK)
                     | (SRI_XBARIDINTSAT_MASK));
  #if(CHIP_ID == 29U)                                   
  XBAR_ARBCON9.U  |= (unsigned_int)((unsigned_int)IFX_XBAR_ARBCON_INTACK_MSK <<
                                   IFX_XBAR_ARBCON_INTACK_OFF);
  XBAR_ARBCON10.U |= (unsigned_int)((unsigned_int)IFX_XBAR_ARBCON_INTACK_MSK <<
                                   IFX_XBAR_ARBCON_INTACK_OFF);
  #endif
  /* Restore SMU alarm actions: */
  if (E_OK == Sri_BackupData->GetAlmActionResult)
  {
    SmuResult1= Smu_SetAlarmAction(SMU_SRI_ECC_ADDR_PHASE_GRP,
                                   SMU_SRI_ECC_ADDR_PHASE_ALM,
                                   Sri_BackupData->AlmActionBackupECCAdr);
    SmuResult2= Smu_SetAlarmAction(SMU_SRI_ECC_WRITE_PHASE_GRP,
                                   SMU_SRI_ECC_WRITE_PHASE_ALM,
                                   Sri_BackupData->AlmActionBackupECCWrite);
    SmuResult3= Smu_SetAlarmAction(SMU_SRI_ECC_READ_PHASE_GRP,
                                   SMU_SRI_ECC_READ_PHASE_ALM,
                                   Sri_BackupData->AlmActionBackupECCRead);
    SmuResult4= Smu_SetAlarmAction(SMU_SRI_BUS_ERR_GRP,
                                   SMU_SRI_BUS_ERR_ALM,
                                   Sri_BackupData->AlmActionBackupSRI);
    SmuResult5= Smu_SetAlarmAction(SriTst_CurrentCpuSriAlm[CoreId],
                                   SMU_SRI_CPU_DMI_ERR_ALM,
                                   Sri_BackupData->AlmActionBackupSRICPUxDMI);
    SmuResult6= Smu_SetAlarmAction(SriTst_CurrentCpuSriAlm[CoreId],
                                   SMU_SRI_CPU_PMI_ERR_ALM,
                                   Sri_BackupData->AlmActionBackupSRICPUxPMI);
    SmuResult7= Smu_SetAlarmAction(SMU_SRI_CPU0_ERR_GRP,
                                   SMU_SRI_CPU_PSPR_ECC_UC_ALM,
                                   Sri_BackupData->AlmActionBackupPsprUcErr);

    if ( (SmuResult1 != E_OK) || (SmuResult2 != E_OK) || (SmuResult3 != E_OK) ||
         (SmuResult4 != E_OK) || (SmuResult5 != E_OK) || (SmuResult6 != E_OK) ||
         (SmuResult7 != E_OK) )
    {      
      Result = SRI_SMU_SETALMACTIONERR;
    } /* if ( (SmuResult1 != E_OK) || (SmuResult2 != E_OK) ||
              (SmuResult3 != E_OK) || (SmuResult4 != E_OK) ||
              (SmuResult5 != E_OK) || (SmuResult6 != E_OK) ||
              (SmuResult7 != E_OK) ) */
  } /* if (E_OK == Sri_BackupData->GetAlmActionResult) */

  if (SRI_NOTEXECUTED == Result)
  {
    Result = SRI_SUCCESS;
  } /* if (SRI_NOT_EXECUTED == Result) */

  return Result;
} /* SriTst_lRestore */

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : boolean SriTst_lProtectionTrapHandler                             **
**          (                                                                 **
**            const  uint32 TrapId                                            **
**          )                                                                 **
**                                                                            **
** Description : Handles Class 1, Internal Protection Traps while the SRI     **
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
** Parameters (out): None                                                     **
**                                                                            **
** Return value : TRUE, if trap was expected and handled, FALSE otherwise     **
**                                                                            **
*******************************************************************************/
static boolean SriTst_lProtectionTrapHandler
(
  const uint32 TrapId
)
{
  boolean TrapExpected = (boolean)FALSE;

  /* Check if TIN = 5 and this trap is currently expected: */
  if ((SRI_TRAP_ID5 == TrapId) &&
      (SRI_TRAP_CLASS1 == Sri_ExpectedTrapClass) &&
      (SRI_TRAP_ID5 == Sri_ExpectedTrapId))
  {
    TrapExpected = (boolean)TRUE;

    /* Clear expected trap class and ID: */
    Sri_ExpectedTrapClass = SRI_TRAP_CLASS_NONE;
    Sri_ExpectedTrapId = SRI_TRAP_ID_NONE;

    if (Sri_MppTrapCount < (uint8)0xFF)
    {
      Sri_MppTrapCount += 1U;
    } /* if (Sri_MppTrapCount < (uint8)0xFF) */

    /* Clear MPE Trap request                                                 */
    MTCR(CPU_DSTR, 0x0U);
  } /* if ((SRI_TRAP_ID5 == TrapId) &&
           (SRI_TRAP_CLASS1 == Sri_ExpectedTrapClass) &&
           (SRI_TRAP_ID5 == Sri_ExpectedTrapId)) */
  else
  {
    Sri_MppTrapCount = 0U;
  } /* if ((SRI_TRAP_ID5 != TrapId) ||
           (SRI_TRAP_CLASS1 != Sri_ExpectedTrapClass) ||
           (SRI_TRAP_ID5 != Sri_ExpectedTrapId)) */

  return TrapExpected;
} /* SriTst_lProtectionTrapHandler */

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : boolean SriTst_lBusErrorTrapHandler                               **
**          (                                                                 **
**            const uint32 TrapId                                             **
**          )                                                                 **
**                                                                            **
** Description : Handles Class 4, System Bus and Peripheral Error, Traps      **
**               while the SRI test has switched the BTV to a dedicated trap  **
**               table.                                                       **
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
** Parameters (out): None                                                     **
**                                                                            **
** Return value : TRUE, if trap was expected and handled, FALSE otherwise     **
**                                                                            **
*******************************************************************************/
static boolean SriTst_lBusErrorTrapHandler
(
  const uint32 TrapId
)
{
  boolean             TrapExpected = (boolean)FALSE;

  switch (TrapId)
  {
    case SRI_TRAP_ID2:  /* Data Access Synchronous Error */
      if ((SRI_TRAP_CLASS4 == Sri_ExpectedTrapClass) &&
          (SRI_TRAP_ID2 == Sri_ExpectedTrapId))
      {
        TrapExpected = (boolean)TRUE;

        /* Increment trap counter with overflow checking: */
        if (Sri_DseTrapCount < (uint8)0xFF)
        {
          Sri_DseTrapCount += 1U;
        } /* if (Sri_DseTrapCount < (uint8)0xFF) */

        /* Clear DSE Trap request                                             */
        MTCR(CPU_DSTR, 0x0U);
      } /* if ((SRI_TRAP_CLASS4 == Sri_ExpectedTrapClass) &&
               (SRI_TRAP_ID2 == Sri_ExpectedTrapId)) */
      break;

    case SRI_TRAP_ID3:  /* Data Access Asynchronous Error */
      if ((SRI_TRAP_CLASS4 == Sri_ExpectedTrapClass) &&
          (SRI_TRAP_ID3 == Sri_ExpectedTrapId))
      {
        TrapExpected = (boolean)TRUE;

        /* Increment trap counter with overflow checking: */
        if (Sri_DaeTrapCount < (uint8)0xFF)
        {
          Sri_DaeTrapCount += 1U;
        } /* if (Sri_DaeTrapCount < (uint8)0xFF) */

        /* Clear DAE Trap request                                             */
        MTCR(CPU_DATR, 0x0U);
      } /* if ((SRI_TRAP_CLASS4 == Sri_ExpectedTrapClass) &&
               (SRI_TRAP_ID3 == Sri_ExpectedTrapId)) */
      break;

    case SRI_TRAP_ID5:  /* Program Memory Integrity Error */
      /* A program memory integrity error is generated when injecting read  */
      /* phase errors to the SRI system and then trying to execute code     */
      /* from the DSPR. -> CPUxPMI data-in decoder test.                    */

      if ((SRI_TRAP_CLASS4 == Sri_ExpectedTrapClass) &&
          (SRI_TRAP_ID5 == Sri_ExpectedTrapId))
      {
        TrapExpected = (boolean)TRUE;

        /* Increment trap counter with overflow checking: */
        if (Sri_PietrTrapCount < (uint8)0xFF)
        {
          Sri_PietrTrapCount += 1U;
        } /* if (Sri_PietrTrapCount < (uint8)0xFF) */

        /* Clear PIETR info                                                   */
        MTCR(CPU_PIETR, 0x0U);
      } /* if ((SRI_TRAP_CLASS4 == Sri_ExpectedTrapClass) &&
               (SRI_TRAP_ID5 == Sri_ExpectedTrapId)) */
      break;

    case SRI_TRAP_ID6:  /* Data Memory Integrity Error */
      /* A data integrity error is generated when injecting read phase      */
      /* errors to the SRI system.                                          */

      if ((SRI_TRAP_CLASS4 == Sri_ExpectedTrapClass) &&
          (SRI_TRAP_ID6 == Sri_ExpectedTrapId))
      {
        TrapExpected = (boolean)TRUE;

        /* Increment trap counter with overflow checking: */
        if (Sri_DietrTrapCount < (uint8)0xFF)
        {
          Sri_DietrTrapCount += 1U;
        } /* if (Sri_DietrTrapCount < (uint8)0xFF) */

        /* Clear Trap request                                                 */
        MTCR(CPU_DIETR, 0x0);
      } /* if ((SRI_TRAP_CLASS4 == Sri_ExpectedTrapClass) &&
               (SRI_TRAP_ID6 == Sri_ExpectedTrapId)) */
      break;

    default:
      Sri_DseTrapCount = 0U;
      Sri_DaeTrapCount = 0U;
      Sri_PietrTrapCount = 0U;
      Sri_DietrTrapCount = 0U;
      break;
  } /* switch (TrapId) */

  if ((boolean)TRUE == TrapExpected)
  {
    /* Clear expected trap class and ID: */
    Sri_ExpectedTrapClass = SRI_TRAP_CLASS_NONE;
    Sri_ExpectedTrapId = SRI_TRAP_ID_NONE;
  } /* if ((boolean)TRUE == TrapExpected) */

  return TrapExpected;
} /* SriTst_lBusErrorTrapHandler */

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static Sl_TstRsltType SriTst_lSriBusErrorsTst           **
**                    (                                                       **
**                      const Sl_ParamSetType ParamSetIndex,                  **
**                      uint32* const TstSignature                            **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters (in)  : ParamSetIndex - Configuration parameter set index used  **
**                                    for testing                             **
**                                                                            **
** Parameters (out) : TstSignature - Test signature generated by the Test     **
**                                                                            **
** Return value     : SRI_SUCCESS - Bus error test succeeded                  **
**                    SRI_NOTEXECUTED - The test has not yet been executed or **
**                          did for some reason not generate a valid result.  **
**                    SRI_USER0_ACCERR - Test failed because access to a      **
**                          supervisor-mode-only register got not blocked     **
**                          although it was executed in  USER0 mode.          **
**                    SRI_USER1_ACCERR - The test has failed because the USER1**
**                          mode access to a supervisor-mode-only register    **
**                          gets not blocked.                                 **
**                    SRI_UNMAPPED_ACCERR - Test failed because an access to  **
**                          a memory location that is not mapped to any SRI   **
**                          device did not generate a trap.                   **
**                    SRI_UNSUPP_OCERR -  Test failed because although an     **
**                          unsupported Op-code was used it got not detected  **
**                          and therefore no trap had been generated.         **
**                    SRI_SMU_CLRALMSTSERR - The test failed because clearing **
**                          the SMU alarm failed.                             **
**                    SRI_LMUSRAM_SRI_INTERFACE_ERROR - The test failed       **
**                          because LMU SRAM and SRI interface error.         **
**                    SRI_SMU_GETALMSTSERR - Test failed because getting the  **
**                          SMU alarm status failed.                          **
**                                                                            **
** Description      : This function does force all possible SRI bus errors    **
**                    and does check whether they are detected and an SMU     **
**                    alarm is generated.                                     **
*******************************************************************************/
static Sl_TstRsltType SriTst_lSriBusErrorsTst
(
  const Sl_ParamSetType ParamSetIndex,
  uint32* const TstSignature
)
{
  Sl_TstRsltType      Result    = SRI_NOTEXECUTED;
  Std_ReturnType      Temp;
  
  #if(CHIP_ID == 27U) || (CHIP_ID == 29U)
    uint8               CoreId;  
    /* Read the core Id, needed for Amu test  */
    CoreId = Mcal_GetCoreId();
  #endif
  /* Check that User-0 mode read access to supervisor-mode accessible register
   * is blocked:
   */
  Result = SriTst_lUser0AccTst(TstSignature);
  if (SRI_SUCCESS == Result)
  {
    /* 1. Check that User-1 mode write access to supervisor-mode accessible
     *    register is blocked:
     */
    Result = SriTst_lUser1AccTst(TstSignature);
	
	/* Clear XBARSRC service request SRR bit*/
	SRC_XBARSRC.U = ((SRC_XBARSRC.U & SRI_XBARSRC_MASK) | (SRI_XBARSRC_CLRR_BIT));
	
    Temp = Smu_ClearAlarmStatus(SMU_SRI_BUS_ERR_GRP, SMU_SRI_BUS_ERR_ALM);
    if(E_OK != Temp)
    {
      /* Retain the User1AccTst failure in case
         ClearAlarmStatus also fails*/
      if (Result == SRI_SUCCESS)
      {
        Result = SRI_SMU_CLRALMSTSERR;
      } /* if (Result == SRI_SUCCESS) */
    } /* if(E_OK != Temp) */

    if (SRI_SUCCESS == Result)
    {
      /* 
	    1. Check that read access to an unmapped address is detected as error: 
	  */
      Result = SriTst_lUnmappedAdrTst(TstSignature);  
	  /* Clear XBARSRC service request SRR bit*/
	  SRC_XBARSRC.U = ((SRC_XBARSRC.U & SRI_XBARSRC_MASK) | (SRI_XBARSRC_CLRR_BIT));
      Temp = Smu_ClearAlarmStatus(SMU_SRI_BUS_ERR_GRP, SMU_SRI_BUS_ERR_ALM);
      if(E_OK != Temp)
      {
        /* Retain the UnmappedAdrTst failure in case
           ClearAlarmStatus also fails*/
        if (Result == SRI_SUCCESS)
        {
          Result = SRI_SMU_CLRALMSTSERR;
        } /* if (Result == SRI_SUCCESS) */
      } /* if(E_OK != Temp) */

      if (SRI_SUCCESS == Result)
      {
        /* 
		   1. Check that unsupported SRI opcodes are detected as errors:
	    */
        Result = SriTst_lUnsupportedOCTst(TstSignature);
        /* Clear XBARSRC service request SRR bit*/
        SRC_XBARSRC.U = ((SRC_XBARSRC.U & SRI_XBARSRC_MASK) | (SRI_XBARSRC_CLRR_BIT));
        Temp = Smu_ClearAlarmStatus(SMU_SRI_BUS_ERR_GRP, SMU_SRI_BUS_ERR_ALM);
        if(E_OK != Temp)
        {
          /* Retain the UnsupportedOCTst failure in case
             ClearAlarmStatus also fails*/
          if (Result == SRI_SUCCESS)
          {
            Result = SRI_SMU_CLRALMSTSERR;
          } /* if (Result == SRI_SUCCESS) */
        } /* if(E_OK != Temp) */
        if (SRI_SUCCESS == Result)
        {
          /* 
		    1. Check that invalid transaction IDs are detected by DMI master: 
			2. Clear XBARSRC service request SRR bit.
		  */
          Result = SriTst_lInvalidTransactionIdTst(ParamSetIndex, TstSignature);
		  SRC_XBARSRC.U = ((SRC_XBARSRC.U & SRI_XBARSRC_MASK) | (SRI_XBARSRC_CLRR_BIT));
        }
        #if(CHIP_ID == 27U) || (CHIP_ID == 29U)
        if (SRI_SUCCESS == Result)
        {
          Temp = Smu_ClearAlarmStatus(SMU_SRI_BUS_ERR_GRP, SMU_SRI_BUS_ERR_ALM);
          if(E_OK != Temp)
          {
            Result = SRI_SMU_CLRALMSTSERR;
          } /* if(E_OK != Temp) */
          else
          {
            if ((uint8)0x1U == SriTst_ConfigRoot[ParamSetIndex].LmuTstEN[CoreId])
            {
              Result = SriTst_lChkAmuErrTst(TstSignature);
            }
          }
        } /* if (SRI_SUCCESS == Result) */
        #endif   /*#if(CHIP_ID == 27U || CHIP_ID == 29U)*/

      } /* if (SRI_SUCCESS == Result) */
    } /* if (SRI_SUCCESS == Result) */
  } /* if (SRI_SUCCESS == Result) */
 
  return Result; 
} /* SriTst_lSriBusErrorsTst */

#if(CHIP_ID == 27U) || (CHIP_ID == 29U)
/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : void SriTst_lChkAmuErrTst                                         **
**          (                                                                 **
**            uint32* const TstSignature                                      **
**          )                                                                 **
**                                                                            **
** Description :A fault is injected into the mechanisms used to verify data   **
**              between the RAM and SRI interface of the LMU by setting ITST  **
**              bitfiled of the ADMA_TEST_CTRL register                       **
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
** Parameters (out): TstSignature                                             **
**                                                                            **
** Return value     : SRI_SUCCESS - AMU ECC error test succeeded              **
**                    SRI_NOTEXECUTED - The test has not yet been executed or **
**                       did for some reason not generate a valid result.     **
**                    SRI_SMU_CLRALMSTSERR - The test failed because clearing **
**                       the SMU alarm failed.                                **
**                    SRI_LMUSRAM_SRI_INTERFACE_ERROR - The test failed       **
**                       because LMU SRAM and SRI interface error.            **
**                    SRI_SMU_GETALMSTSERR - Test failed because getting the  **
**                       SMU alarm status failed.                             **
*******************************************************************************/

static Sl_TstRsltType SriTst_lChkAmuErrTst(uint32* const TstSignature)
{
  Sl_TstRsltType Result       =  SRI_NOTEXECUTED;
  uint32*        AdmaTestCtrl =  (uint32*)ADMA_TEST_CTRL_ADDRESS;
  uint32         Timeout      =  SRI_SMU_ALARM_TIMEOUT;
  uint32         AlarmStatus   =  0U;  
  Std_ReturnType Temp;
  /* Enable Internal ECC Error: */
  *AdmaTestCtrl = (uint32)SRI_INJECT_ITST_ERROR;

  /* Reset AlarmStatus and Timeout: */
  AlarmStatus = 0U;
  Timeout = SRI_SMU_ALARM_TIMEOUT;

  /* Wait for expected SMU alarm: */
  while ((0U == (AlarmStatus & SMU_SRI_ECC_WRITE_PHASE_STS)) &&
         (Timeout > 0U))
  {
    Timeout = Timeout - 1U;
    Temp = Smu_GetAlarmStatus(SMU_SRI_ECC_WRITE_PHASE_GRP, &AlarmStatus);
    if (E_OK != Temp)
    {
      Result = SRI_SMU_GETALMSTSERR;
      AlarmStatus = 0U;
      Timeout = 0U;
    } /* if (E_OK != Temp) */
  } /* while ((0U == (AlarmStatus & SMU_SRI_ECC_WRITE_PHASE_STS)) &&
                (Timeout > 0U)) */
  if(Result == SRI_NOTEXECUTED)
  {
    /* Check if expected SMU alarm was triggered: */
    if (0U == (AlarmStatus & SMU_SRI_ECC_WRITE_PHASE_STS))
    {
      Result = SRI_LMUSRAM_SRI_INTERFACE_ERROR;
    } /* if (0U == (AlarmStatus & SMU_SRI_ECC_WRITE_PHASE_STS)) */
    else
    {
      /* Clear SMU alarm: */
      Temp = Smu_ClearAlarmStatus(SMU_SRI_ECC_WRITE_PHASE_GRP,
                                SMU_SRI_ECC_WRITE_PHASE_ALM);
      if (E_OK != Temp)
      {
        Result = SRI_SMU_CLRALMSTSERR;
      } /* if (E_OK != Temp) */
      else
      {
        Result = SRI_SUCCESS;
        /* Update test signature: */
        *TstSignature = (uint32)CRC32(*TstSignature,
                        (uint32)(AlarmStatus & SMU_SRI_ECC_WRITE_PHASE_STS)); 
      } /* if (E_OK == Temp) */
    } /* if (0U != (AlarmStatus & SMU_SRI_ECC_WRITE_PHASE_STS)) */
  }
  
  /*
	Clear LMU_MEMCON ECC error bits which may get set during LMU test.
    Bit positions cleared are : INTERR, DATAERR and ADDERR.
  */
  Mcal_ResetENDINIT();
  
  LMU_MEMCON.U  &=  (unsigned_int) SRI_LMU_MEMCON_RESTORE_MASK;
  
  Mcal_SetENDINIT();
  return Result;  
}
#endif
/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static Sl_TstRsltType SriTst_lInvalidTransactionIdTst   **
**                    (                                                       **
**                      const Sl_ParamSetType ParamSetIndex                   **
**                      uint32* const TstSignature                            **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters (in)  : ParamSetIndex - Index of used SRI test configuration    **
**                                    parameter set                           **
**                                                                            **
** Parameters (out) : TstSignature - Test signature generated by the Test     **
**                                                                            **
** Return value     : SRI_SUCCESS - SRI invalid transaction ID test passed    **
**                    SRI_INVALID_IDERR - SRI transaction ID error was not    **
**                                        detected as expected                **
**                    SRI_SMU_CLRALMSTSERR - Smu_ClearAlarmStatus reported an **
**                                           error                            **
**                    SRI_MBIST_CLC_TIMEOUT - MTU clock enable or disable     **
**                                            timed out                       **
**                    SRI_MBIST_MC_TIMEOUT - Waiting for RAM auto             **
**                                           initialization to complete timed **
**                                           out during enabling/disabling of **
**                                           CPU0 PSPR memory controller      **
**                    SRI_NOTEXECUTED - Program flow consistency error; this  **
**                                      value should never be returned        **
**                                                                            **
** Description      : This function force an invalid transaction ID SRI error **
**                    by reading from a PSPR SRAM location with an            **
**                    uncorrectable ECC error and checks that the error is    **
**                    correctly detected. The test uses CPU0 PSPR SRAM for    **
**                    transaction ID error generation, independently on       **
**                    which core it is executed.                              **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType SriTst_lInvalidTransactionIdTst
(
  const Sl_ParamSetType ParamSetIndex,
  uint32* const TstSignature
)
{
  Sl_TstRsltType      Result = SRI_NOTEXECUTED;
  Sl_TstRsltType      ResultTmp;
  uint32*             TestAddress;
  uint32              MtuClcBackup;
  uint32              XbarIdIntEnBackup;
  volatile uint32     Dummy = 0U;
  uint8               CoreId;
  uint32              MemoryBackup[2U] = {0U,0U};
  volatile uint16	  DummyW_MtuTc_005;

  /* Table of transaction ID error status bits in XBAR_IDINTSAT for all 3
   * CPU cores:
   */
  const unsigned_int  IdMciBitTbl[MCAL_NO_OF_CORES] =
  {
    SRI_XBAR_IDINTSAT_IDMCI12  /* CPU0.DMI */
#if (MCAL_NO_OF_CORES > 1U)
    ,SRI_XBAR_IDINTSAT_IDMCI8   /* CPU1.DMI */
#if (MCAL_NO_OF_CORES == 3U)
    ,SRI_XBAR_IDINTSAT_IDMCI10   /* CPU2.DMI */
#endif /* (MCAL_NO_OF_CORES == 3U) */
#endif /* (MCAL_NO_OF_CORES > 1U) */
  };

  /* Read the core Id                                                         */
  CoreId = Mcal_GetCoreId();

  /* Store pointer to PSPR test memory and backup memory content (Note: CPU0
   * PSPR SRAM is always used for the test on all CPU cores): */
  TestAddress = SriTst_ConfigRoot[ParamSetIndex].SriTstPSPRTstAdr[0];
  MemoryBackup[0] = TestAddress[0];
  MemoryBackup[1] = TestAddress[1];

  /* Enable MTU clock: */
  ResultTmp = SriTst_lEnableMtuClock(&MtuClcBackup);
  if (SRI_SUCCESS == ResultTmp)
  {
    /* Inject ECC errors into PSPR RAM: */
    ResultTmp = SriTst_lInjectPsprError(TestAddress, CoreId);
    if (SRI_SUCCESS == ResultTmp)
    {
      /* Backup and enable SRI transaction ID error sampling: */
      XbarIdIntEnBackup = XBAR_IDINTEN.U;
      XBAR_IDINTEN.U |= IdMciBitTbl[CoreId];

      /* Set expected trap class and ID: */
      Sri_ExpectedTrapClass = SRI_TRAP_CLASS4;
      Sri_ExpectedTrapId = SRI_TRAP_ID2;

      /* Read corrupt data from PSPR RAM: */
      Dummy = *TestAddress;

      /* Add DSE trap counter to the test signature: */
      *TstSignature = (uint32)CRC32(*TstSignature, (uint32)Sri_DseTrapCount);

      /* Check if DSE trap was triggered: */
      if (1U != Sri_DseTrapCount)
      {
        Result = SRI_INVALID_IDERR;
      } /* if (1U != Sri_DseTrapCount) */

      /* Add transaction ID error flag to the test signature: */
      *TstSignature = (uint32)CRC32(*TstSignature,
                                    (uint32)(XBAR_IDINTSAT.U &
                                             IdMciBitTbl[CoreId]));

      /* Check if respective transaction ID error flag is set: */
      if (0U == (XBAR_IDINTSAT.U & IdMciBitTbl[CoreId]))
      {
        Result = SRI_INVALID_IDERR;
      } /* if (0U == (XBAR_IDINTSAT.U & IdMciBitTbl[CoreId])) */

      /* Clear ECC errors in PSPR RAM.  */
      MEMWRITE64(TestAddress, &MemoryBackup);

      /* Clear transaction ID error flag: */
      XBAR_IDINTSAT.U = IdMciBitTbl[CoreId];

      /* Clear program memory integrity error information: */
      if (0U == CoreId)
      {
        MTCR(CPU_PIETR, (uint32)0U);
      } /* if (0U == CoreId) */
      else
      {
        CPU0_PIETR.U = 0U;
      } /* if (0U != CoreId) */

      /* Clear CPU0 PSPR uncorrectable ECC error SMU alarm: */
      if (E_OK != Smu_ClearAlarmStatus(SMU_SRI_CPU0_ERR_GRP,
                                       SMU_SRI_CPU_PSPR_ECC_UC_ALM))
      {
        Result = SRI_SMU_CLRALMSTSERR;
      } /* if (E_OK != Smu_ClearAlarmStatus(SMU_SRI_CPU0_ERR_GRP,
                                            SMU_SRI_CPU_PSPR_ECC_UC_ALM)) */

      /* Clear SRI bus error SMU alarm: */
      if (E_OK != Smu_ClearAlarmStatus(SMU_SRI_BUS_ERR_GRP,
                                       SMU_SRI_BUS_ERR_ALM))
      {
        Result = SRI_SMU_CLRALMSTSERR;
      } /* if (E_OK != Smu_ClearAlarmStatus(SMU_SRI_BUS_ERR_GRP,
                                            SMU_SRI_BUS_ERR_ALM)) */

      /* Restore SRI transaction ID error sampling: */
      XBAR_IDINTEN.U = XbarIdIntEnBackup;
    } /* if (SRI_SUCCESS == ResultTmp) */
    else
    {
      Result = ResultTmp;
    } /* if (SRI_SUCCESS != ResultTmp) */
    
    if (0U == CoreId)
    {
	     
	  /* 
	    Clear ECCD error flags:
        Since, CPU0 clock is already enabled, perform a dummy write 
	    with to ECCD register before writing intended value. This is 
		to cater Errata MTU_TC.005.
      */
	  MC16_ECCD.U = SRI_DUMMY_ECCD_WRITE;
	  DummyW_MtuTc_005 = MC16_ECCD.U;
      DummyW_MtuTc_005 = DummyW_MtuTc_005 &
                 (uint16)(~(uint16)(((uint32)IFX_MC_ECCD_SERR_MSK <<
                                     (uint32)IFX_MC_ECCD_SERR_OFF) |
                                    ((uint32)IFX_MC_ECCD_CERR_MSK <<
                                     (uint32)IFX_MC_ECCD_CERR_OFF) |
                                    ((uint32)IFX_MC_ECCD_UERR_MSK <<
                                     (uint32)IFX_MC_ECCD_UERR_OFF) |
                                    ((uint32)IFX_MC_ECCD_AERR_MSK <<
                                     (uint32)IFX_MC_ECCD_AERR_OFF)));
									 
	  DummyW_MtuTc_005 |= (uint16)((uint32)IFX_MC_ECCD_TRC_MSK <<
                           (uint32)IFX_MC_ECCD_TRC_OFF);
	  MC16_ECCD.U = SRI_DUMMY_ECCD_WRITE;
      MC16_ECCD.U = DummyW_MtuTc_005;
    }
	else
	{
	   /* 
	     Clear ECCD error flags: 
         Enable MBIST for CPU0 PSPR memory controller before updating ECCD
         to avoid Errata MTU_TC.005.
       */
       Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);
       ResultTmp = SriTst_lEnablePspr0Mc();
       if(SRI_SUCCESS == ResultTmp)
        {
           MC16_ECCD.U = MC16_ECCD.U &
                 (uint16)(~(uint16)(((uint32)IFX_MC_ECCD_SERR_MSK <<
                                     (uint32)IFX_MC_ECCD_SERR_OFF) |
                                    ((uint32)IFX_MC_ECCD_CERR_MSK <<
                                     (uint32)IFX_MC_ECCD_CERR_OFF) |
                                    ((uint32)IFX_MC_ECCD_UERR_MSK <<
                                     (uint32)IFX_MC_ECCD_UERR_OFF) |
                                    ((uint32)IFX_MC_ECCD_AERR_MSK <<
                                     (uint32)IFX_MC_ECCD_AERR_OFF)));
									 
		   MC16_ECCD.U |= (uint16)((uint32)IFX_MC_ECCD_TRC_MSK <<
                           (uint32)IFX_MC_ECCD_TRC_OFF);

           /*Disable Mbist for Cpu0 PSPR memory controller*/
           ResultTmp = SriTst_lDisablePspr0Mc();            
		   if (SRI_SUCCESS != ResultTmp)
           {
              Result = ResultTmp;
           }			
	    }
        else
        {
		   Result = ResultTmp;
        }		  
	    Mcal_SetSafetyENDINIT_Timed();
    } 
    /* Restore MTU clock gating: */
    if (MtuClcBackup > 0U)
    {
      ResultTmp = SriTst_lDisableMtuClock();
      if (SRI_SUCCESS != ResultTmp)
      {
        Result = ResultTmp;
      } /* if (SRI_SUCCESS != ResultTmp) */
    } /* if (MtuClcBackup > 0U) */
  } /* if (SRI_SUCCESS == ResultTmp) */
  else
  {
    Result = ResultTmp;
  } /* if (SRI_SUCCESS != ResultTmp) */

  /* Update test result: */
  if (SRI_NOTEXECUTED == Result)
  {
    Result = SRI_SUCCESS;
  } /* if (SRI_NOTEXECUTED == Result) */

  /* Clear DSE trap counter: */
  Sri_DseTrapCount = 0U;
  UNUSED_PARAMETER(Dummy)
  return Result;
} /* SriTst_lInvalidTransactionIdTst */

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static Sl_TstRsltType SriTst_lInjectPsprError           **
**                    (                                                       **
**                      uint32* const TestAddress,                            **
**                      const uint8 CoreId                                    **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters (in)  : TestAddress - Address in CPU0 PSPR RAM that will be     **
**                                  used to inject an uncorrectable ECC error **
**                    CoreId - ID of the CPU core executing this function     **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : SRI_SUCCESS - Error injection succeeded                 **
**                    SRI_MBIST_MC_TIMEOUT - Waiting for RAM auto             **
**                                           initialization to complete timed **
**                                           out during enabling/disabling of **
**                                           CPU0 PSPR memory controller      **
**                    SRI_NOTEXECUTED - Program flow consistency error; this  **
**                                      value should never be returned        **
**                                                                            **
** Description      : This function injects an uncorrectable ECC error        **
**                    into CPU0 PSPR SRAM.                                    **
**                                                                            **
** Note(s)          : The error is injected using the memory test controller  **
**                    of CPU0 PSPR SRAM. CPU0 ICACHE is temporarily bypassed  **
**                    to avoid problems caused by ICACHE auto initialization  **
**                    (if enabled via FLASH0_PROCOND) when the memory         **
**                    controller is enabled or disabled.                      **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType SriTst_lInjectPsprError
(
  uint32* const TestAddress,
  const uint8 CoreId
)
{
  uint8                   i;
  uint32                  Temp;
  uint32                  CpuCacheBypass = 0U;
  Sl_TstRsltType          Result = SRI_NOTEXECUTED;
  Sl_TstRsltType          ResultTmp;
  volatile Ifx_MC_RDBFL*  McRdbfl = &MC16_RDBFL0;
  uint32                  TestData[2] = {SRI_PSPR_TEST_PATTERN, \
                                         SRI_PSPR_TEST_PATTERN};
  volatile uint32         Dummy;


  /* PCACHE is part of the PSPR SRAM and will become inaccessible when
   * the PSPR memory controller is enabled. Therefore CPU0 PCACHE bypassing
   * needs to be enabled if executing on CPU0:
   */
  if (0U == CoreId)
  {
    Mcal_ResetENDINIT();
    Temp = (uint32)MFCR(CPU_PCON0);

    /* Backup PCBYP bit: */
    CpuCacheBypass = (Temp & SRI_CPU_PCON0_PCBYP_BIT);

    /* Enable instruction cache bypassing: */
    Temp |= SRI_CPU_PCON0_PCBYP_BIT;
    MTCR(CPU_PCON0, Temp);
    Mcal_SetENDINIT();
  } /* if (0U == CoreId) */

  /* Disable all interrupts while MBIST controller is enabled: */
  Mcal_SuspendAllInterrupts();

  /* Dummy read to CPU0 PSPR SRAM to avoid data loss when MBIST is enabled and
   * SRAM contains defective cells, which are replaced by redundancy cells:
   */
  DSYNC();
  Dummy = *TestAddress;

  /* Enable MBIST controller of CPU0 PSPR SRAM: */
  Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);
  ResultTmp = SriTst_lEnablePspr0Mc();
  if (SRI_SUCCESS == ResultTmp)
  {
    /* Set bitflip mask to flip first 2 data bits: */
    McRdbfl[0].U = SRI_TID_BITFLIP_MASK;
    for (i = 1U; i < SRI_PSPR0_RDBFL_REG_COUNT; i++)
    {
      McRdbfl[i].U = 0U;
    } /* for (i = 1U; i < SRI_LMU_RDBFL_REG_COUNT; i++) */

    /* Enable bit flipping according to RDBFL registers: */
    MC16_ECCS.U |= (uint16)SRI_ECCS_BFLE_BIT;

    /* Disable MBIST controller: */
    ResultTmp = SriTst_lDisablePspr0Mc();
    if (SRI_SUCCESS == ResultTmp)
    {
      /* Write test pattern to CPU0 PSPR SRAM: */
      MEMWRITE64(TestAddress, &TestData[0U]);

      /* Dummy read to CPU0 PSPR SRAM to avoid data loss when MBIST is enabled
       * and SRAM contains defective cells, which are replaced by redundancy
       * cells, address without ECC error is read as SRI transaction ID error
       * sampling is not yet enabled and the error shall be triggered later:
       */
      DSYNC();
      Dummy = TestAddress[2U];

      /* Enable MBIST controller of CPU0 PSPR SRAM: */
      ResultTmp = SriTst_lEnablePspr0Mc();
      if (SRI_SUCCESS == ResultTmp)
      {
        /* Disable bit flipping according to RDBFL registers: */
        MC16_ECCS.U &= (uint16)~SRI_ECCS_BFLE_BIT;

        /* Disable MBIST controller: */
        Result = SriTst_lDisablePspr0Mc();
      } /* if (SRI_SUCCESS == ResultTmp) */
      else
      {
        Result = ResultTmp;
      } /* if (SRI_SUCCESS != ResultTmp) */
    } /* if (SRI_SUCCESS == ResultTmp) */
    else
    {
      Result = ResultTmp;
    } /* if (SRI_SUCCESS != ResultTmp) */
  } /* if (SRI_SUCCESS == ResultTmp) */
  else
  {
    Result = ResultTmp;
  } /* if (SRI_SUCCESS != ResultTmp) */

  Mcal_SetSafetyENDINIT_Timed();

  /* Re-enable interrupts: */
  Mcal_ResumeAllInterrupts();

  /* Restore instruction cache bypass: */
  if (0U == CoreId)
  {
    if (0U == CpuCacheBypass)
    {
      Mcal_ResetENDINIT();
      Temp = (uint32)MFCR(CPU_PCON0);
      Temp &= ~SRI_CPU_PCON0_PCBYP_BIT;
      MTCR(CPU_PCON0, Temp);
      Mcal_SetENDINIT();
    } /* if (0U == CpuCacheBypass) */
  } /* if (0U == CoreId) */

  UNUSED_PARAMETER(Dummy)
  return Result;
} /* SriTst_lInjectPsprError */

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static Sl_TstRsltType SriTst_lEnablePspr0Mc             **
**                    (                                                       **
**                      void                                                  **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters (in)  : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : SRI_SUCCESS - Memory controller successfully enabled    **
**                    SRI_MBIST_MC_TIMEOUT - Waiting for RAM auto             **
**                                           initialization to complete timed **
**                                           out                              **
**                    SRI_NOTEXECUTED - Program flow consistency error; this  **
**                                      value should never be returned        **
**                                                                            **
** Description      : Enables the memory controller for CPU0 PSPR SRAM and    **
**                    waits until RAM auto initialization has completed.      **
**                                                                            **
** Notes            : In case RAM auto-initialization is enabled via          **
**                    FLASH0_PROCOND, enabling the CPU0 PSPR SRAM memory      **
**                    controller will clear the CPU0 PCACHE, while the CPU0   **
**                    PTAG SRAM still contains expired references. In order   **
**                    to invalidate the CPU0 PTAG and keep both - the PCACHE  **
**                    and PTAG - consistent, also the CPU0 PTAG memory        **
**                    controller is enabled, to clear it, too.                **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType SriTst_lEnablePspr0Mc
(
  void
)
{
  uint32                  Status;
  uint32                  Timeout;
  uint32                  MemTestMask;
  Sl_TstRsltType          Result = SRI_NOTEXECUTED;

  /* Check if automatic RAM initialization is enabled: */
  if (SRI_RAM_INIT_DISABLED == FLASH0_PROCOND.B.RAMIN)
  {
    MemTestMask = SRI_MEMTEST_PSPR0_BIT;
  }
  else
  {
    MemTestMask = SRI_MEMTEST_PSPR0_BIT | SRI_MEMTEST_CPU0PTEN_BIT;
  }

  /* Enable MBIST controller of CPU0 PSPR and PTAG SRAM.
   * NOTE: The PTAG SRAM MBIST controller is enabled to clear the PTAG in case
   *       RAM auto-initialization is enabled (which also causes the PCACHE to
   *       be cleared), otherwise the PCACHE will not be cleared and thus
   *       cache invalidation is not required:
   */
  MTU_MEMTEST0.U |= (unsigned_int)MemTestMask;

  /* Wait for RAM initialization to complete: */
  Timeout = 0U;
  do
  {
    Timeout++;
    Status = (uint32)(MTU_MEMSTAT0.U & MemTestMask);
  } while ((Timeout < SRI_MBIST_MEM_INIT_TIMEOUT) && (Status > 0U));

  /* RAM initialization completed? */
  if ((MTU_MEMSTAT0.U & MemTestMask) > 0U)
  {
    /* RAM initialization did not complete in time => error: */
    Result = SRI_MBIST_MC_TIMEOUT;

    /* Disable MBIST controller: */
    MTU_MEMTEST0.U &= (unsigned_int)(~MemTestMask);
  } /* if ((MTU_MEMSTAT0.U & MemTestMask) > 0U) */
  else
  {
    Result = SRI_SUCCESS;
  } /* if ((MTU_MEMSTAT0.U & MemTestMask) == 0U) */

  return Result;
} /* SriTst_lEnablePspr0Mc */

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static Sl_TstRsltType SriTst_lDisablePspr0Mc            **
**                    (                                                       **
**                      void                                                  **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters (in)  : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : SRI_SUCCESS - Memory controller successfully disabled   **
**                    SRI_MBIST_MC_TIMEOUT - Waiting for RAM auto             **
**                                           initialization to complete timed **
**                                           out                              **
**                    SRI_NOTEXECUTED - Program flow consistency error; this  **
**                                      value should never be returned        **
**                                                                            **
** Description      : Disables the memory controller for CPU0 PSPR SRAM and   **
**                    waits until RAM auto initialization has completed       **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType SriTst_lDisablePspr0Mc
(
  void
)
{
  uint32                  Status;
  uint32                  Timeout;
  uint32                  MemTestMask;
  Sl_TstRsltType          Result = SRI_NOTEXECUTED;

  /* Check if automatic RAM initialization is enabled: */
  if (SRI_RAM_INIT_DISABLED == FLASH0_PROCOND.B.RAMIN)
  {
    MemTestMask = SRI_MEMTEST_PSPR0_BIT;
  }
  else
  {
    MemTestMask = SRI_MEMTEST_PSPR0_BIT | SRI_MEMTEST_CPU0PTEN_BIT;
  }

  /* Disable MBIST controller of PSPR0 (and PTAG) SRAM: */
  MTU_MEMTEST0.U &= (unsigned_int)(~MemTestMask);
  /* Wait for RAM initialization to complete: */
  Timeout = 0U;
  do
  {
    Timeout++;
    Status = (uint32)(MTU_MEMSTAT0.U & MemTestMask);
  } while ((Timeout < SRI_MBIST_MEM_INIT_TIMEOUT) && (Status > 0U));

  /* RAM initialization completed? */
  if ((MTU_MEMSTAT0.U & MemTestMask) > 0U)
  {
    /* RAM initialization did not complete in time => error: */
    Result = SRI_MBIST_MC_TIMEOUT;
  } /* if ((MTU_MEMSTAT0.U & MemTestMask) > 0U) */
  else
  {
    Result = SRI_SUCCESS;
  } /* if ((MTU_MEMSTAT0.U & MemTestMask) == 0U) */

  return Result;
} /* SriTst_lDisablePspr0Mc */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : Sl_TstRsltType SriTst_lEnableMtuClock                   **
**                    (                                                       **
**                      uint32* const MtuClcBackup                            **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   :                                                         **
** Parameters (out) : MtuClcBackup - Pointer to uint32 that will receive the  **
**                                   previous state of MTU_CLC.DISR bit       **
**                                                                            **
** Return value     : SRI_SUCCESS - MTU clock enable succeeded                **
**                    SRI_MBIST_CLC_TIMEOUT - MTU clock enable timed out      **
**                                                                            **
** Description      : This function enables clock gating for the MTU module   **
**                    and stores the previous status of MTU clock gating to   **
**                    the given backup data.                                  **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType SriTst_lEnableMtuClock
(
  uint32* const MtuClcBackup
)
{
  Sl_TstRsltType  Result = SRI_MBIST_CLC_TIMEOUT;
  uint32          Timeout;

  /* Backup MTU_CLC.DISR bit: */
  *MtuClcBackup = (uint32)(MTU_CLC.U & SRI_MTU_CLC_DISR_BIT);

  /* Enable MTU clock: */
  Mcal_ResetENDINIT();
  MTU_CLC.U &= ~SRI_MTU_CLC_DISR_BIT;
  Mcal_SetENDINIT();
  Timeout = SRI_MTU_CLK_EN_TIMEOUT;
  while(((MTU_CLC.U & SRI_MTU_CLC_DISS_BIT) != 0U) && (Timeout > 0U))
  {
    Timeout--;
  } /* while(((MTU_CLC.U & SRI_MTU_CLC_DISS_BIT) != 0U) && (Timeout > 0U)) */
  if ((MTU_CLC.U & SRI_MTU_CLC_DISS_BIT) == 0U)
  {
    Result = SRI_SUCCESS;
  } /* if ((MTU_CLC.U & SRI_MTU_CLC_DISS_BIT) == 0U) */

  return Result;
} /* SriTst_lEnableMtuClock */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : Sl_TstRsltType SriTst_lDisableMtuClock                  **
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
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : SRI_SUCCESS - Disabling MTU clock succeeded             **
**                    SRI_MBIST_CLC_TIMEOUT - MTU clock disable timed out     **
**                                                                            **
** Description      : This function restores clock gating for the MTU module  **
**                    as it has been before the SRAM ECC test was executed.   **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType SriTst_lDisableMtuClock
(
  void
)
{
  Sl_TstRsltType  Result = SRI_MBIST_CLC_TIMEOUT;
  uint32          Timeout;

  /* Disable MTU clock: */
  Mcal_ResetENDINIT();
  MTU_CLC.U |= SRI_MTU_CLC_DISR_BIT;
  Mcal_SetENDINIT();
  Timeout = SRI_MTU_CLK_EN_TIMEOUT;
  while(((MTU_CLC.U & SRI_MTU_CLC_DISS_BIT) == 0U) && (Timeout > 0U))
  {
    Timeout--;
  } /* while(((MTU_CLC.U & SRI_MTU_CLC_DISS_BIT) == 0U) && (Timeout > 0U)) */
  if ((MTU_CLC.U & SRI_MTU_CLC_DISS_BIT) != 0U)
  {
    Result = SRI_SUCCESS;
  } /* if ((MTU_CLC.U & SRI_MTU_CLC_DISS_BIT) != 0U) */

  return Result;
} /* SriTst_lDisableMtuClock */

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : static Sl_TstRsltType SriTst_lSlaveAddrDecoderTst                 **
**          (                                                                 **
**            uint32* const TstSignature,                                     **
**            uint32* const SlaveAddress,                                     **
**            uint8         AlarmGroup,                                       **
**            uint8         SMUAlarm                                          **
**          )                                                                 **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) : SlaveAddress - SRI slave address to use for the test     **
**                   AlarmGroup - SMU alarm group of the expected alarm       **
**                   SMUAlarm - Expected SMU alarm                            **
**                                                                            **
** Parameters (out): TstSignature - Test signature generated by the test.     **
**                                                                            **
** Return value : SRI_NOTEXECUTED     - The test has not yet been executed or **
**                                      did for some reason not generate a    **
**                                      valid result. This is possible only   **
**                                      from program flow breaks.             **
**                SRI_SUCCESS         - Test succeeded.                       **
**                SRI_ECC_ADRBTRAP_NG - Each ECC error in the SRI address     **
**                                      phase must also generate a DSE-Trap.  **
**                SRI_ECC_ADDRESS     - Waiting for the SMU alarm timed out.  **
**                                      If there is no SMU alarm generated it **
**                                      is most likely that the ECC error got **
**                                      not detected.                         **
**                SRI_SMU_CLRALMSTSERR - The test failed because clearing the **
**                                       SMU alarm failed.                    **
**                                                                            **
** Description : This function does initiate a read from the slave device but **
**               does inject ECC errors during the address phase. The slave   **
**               device must detect an address error and generate an SMU      **
**               alarm. As master CPUx_DMI is used. And also it will clear    **
**               the SMU Alarm3[30] (i.e. SRI Bus Error).                     **
*******************************************************************************/
static Sl_TstRsltType SriTst_lSlaveAddrDecoderTst
(
  uint32* const TstSignature,
  uint32* const SlaveAddress,
  uint8 AlarmGroup,
  uint8 SMUAlarm
)
{

  Sl_TstRsltType      Result = SRI_NOTEXECUTED;
  Std_ReturnType      RetVal1 = E_NOT_OK;
  Std_ReturnType      RetVal2 = E_NOT_OK;  
  uint32              Timeout;
  uint32              AlarmStatus;
  uint32              EccInversion = 1U;
  uint8               LoopCnt = 0U;
  volatile uint32*    PtrTestAddr32 = (volatile uint32*)(void *)SlaveAddress;
  volatile uint32     TestData = 0U;
  uint8               LoopBreak = 0x01U;
  Std_ReturnType      Temp;
  uint32              ErrorInj;

  /* Loop through all ECC bits: */
  while( (LoopCnt < (uint8)SRI_ECC_BIT_COUNT) && (LoopBreak != 0U))
  {
    /* Enable address phase ECC inversion for current bit: */
    Mcal_ResetENDINIT();

    /* Set expected trap class and ID: */
    Sri_ExpectedTrapClass = SRI_TRAP_CLASS4;
    Sri_ExpectedTrapId = SRI_TRAP_ID2;

    ErrorInj = ((uint32)SRI_ERR_INJ_MASTER_ADR_PH | EccInversion);
    MTCR(CPU_SEGEN, ErrorInj);

    /* Read from SRI slave under test: */
    TestData = *PtrTestAddr32;

    Mcal_SetENDINIT();

    /* Reset AlarmStatus and Timeout: */
    AlarmStatus = 0U;
    Timeout = SRI_SMU_ALARM_TIMEOUT;

    /* Wait for expected SMU alarm: */
    while((0U == (AlarmStatus & ((uint32)1U << SMUAlarm))) && (Timeout > 0U))
    {
      Timeout = Timeout - 1U;

      Temp = Smu_GetAlarmStatus(AlarmGroup, &AlarmStatus);
      if (E_OK != Temp)
      {
        AlarmStatus = 0U;
        Timeout = 0U;
      } /* if (E_OK != Temp) */
    } /* while((0U == (AlarmStatus & ((uint32)1U << SMUAlarm))) &&
               (Timeout > 0U)) */

    /* Check if expected SMU alarm was triggered: */
    if (0U == (AlarmStatus & ((uint32)1U << SMUAlarm)))
    {
      Result = SRI_ECC_ADDRESS;
      LoopBreak = 0x00U;
    } /* if (0U == (AlarmStatus & ((uint32)1U << SMUAlarm))) */
    else
    {
      /* Clear SMU alarms: */
      RetVal1 = Smu_ClearAlarmStatus(AlarmGroup, SMUAlarm);
      RetVal2 = Smu_ClearAlarmStatus(SMU_SRI_BUS_ERR_GRP,
                                     SMU_SRI_BUS_ERR_ALM);
      if ((E_OK != RetVal1) || (RetVal2 != E_OK))
      {
        Result = SRI_SMU_CLRALMSTSERR;
        LoopBreak = 0x00U;
      } /* if ((E_OK != RetVal1) || (RetVal2 != E_OK)) */
      else
      {
        /* Go on to next bit pattern: */
        EccInversion <<= 1;
        *TstSignature = (uint32)CRC32(*TstSignature, EccInversion);
      } /* if ((E_OK == RetVal1) && (RetVal2 == E_OK)) */
    } /* if (0U != (AlarmStatus & ((uint32)1U << SMUAlarm))) */
    LoopCnt++;
  } /* while( (LoopCnt < (uint8)SRI_ECC_BIT_COUNT) && (LoopBreak != 0U)) */

  if (SRI_NOTEXECUTED == Result)
  {
    /* Check if a bus trap was thrown for every erroneous access: */
    if (SRI_ECC_BIT_COUNT != Sri_DseTrapCount)
    {
      Result = SRI_ECC_ADRBTRAP_NG;
    } /* if (SRI_ECC_BIT_COUNT != Sri_DseTrapCount) */
    else
    {
      /* test success: */
      Result = SRI_SUCCESS;
    } /* else (SRI_ECC_BIT_COUNT != Sri_DseTrapCount) */
  }/* if (SRI_NOTEXECUTED == Result) */
  /* Clear PIETR info: */
  MTCR(CPU_PIETR, 0x0U);

  /* Clear DSE TrapCounter: */
  Sri_DseTrapCount = 0U;
  UNUSED_PARAMETER(TestData)

  return Result;
} /* SriTst_lSlaveAddrDecoderTst */

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : static Sl_TstRsltType SriTst_lSlaveAddrDecoderXbarTst             **
**          (                                                                 **
**            uint32* const TstSignature                                      **
**          )                                                                 **
**                                                                            **
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
** Parameters (out): TstSignature - Test signature generated by the test.     **
**                                                                            **
** Return value : SRI_NOTEXECUTED     - The test has not yet been executed or **
**                                      did for some reason not generate a    **
**                                      valid result. This is possible only   **
**                                      from program flow breaks.             **
**                SRI_SUCCESS         - Test succeeded.                       **
**                SRI_ECC_ADRBTRAP_NG - Each ECC error in the SRI address     **
**                                      phase must also generate a DSE-Trap.  **
**                SRI_ECC_ADDRESS     - Waiting for the SMU alarm timed out.  **
**                                      If there is no SMU alarm generated it **
**                                      is most likely that the ECC error got **
**                                      not detected.                         **
**                SRI_SMU_CLRALMSTSERR - The test failed because clearing the **
**                                       SMU alarm failed.                    **
**                                                                            **
** Description : This function injects errors into the address phase of an    **
**               SRI transaction and reads a XBAR special function register.  **
**               It then checks that the address phase error was correctly    **
**               detected by the XBAR SRI slave and is reported to the SMU.   **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType SriTst_lSlaveAddrDecoderXbarTst
(
  uint32* const TstSignature
)
{

  Sl_TstRsltType      Result = SRI_NOTEXECUTED;
  Std_ReturnType      RetVal1 = E_NOT_OK;
  Std_ReturnType      RetVal2 = E_NOT_OK;
  uint32              Timeout;
  uint32              AlarmStatus;
  uint32              EccInversion = 1U;
  uint8               LoopCnt = 0U;
  volatile uint32     TestData = 0U;
  uint8               LoopBreak = 0x01U;
  Std_ReturnType      Temp;
  uint32              ErrorInj;  

  while( (LoopCnt < (uint8)SRI_ECC_BIT_COUNT) && (LoopBreak != 0U))
  {
    /* Enable address phase error injection: */
    Mcal_ResetENDINIT();

    /* Set expected trap class and ID: */
    Sri_ExpectedTrapClass = SRI_TRAP_CLASS4;
    Sri_ExpectedTrapId = SRI_TRAP_ID2;

    ErrorInj = ((uint32)SRI_ERR_INJ_MASTER_ADR_PH | EccInversion);
    MTCR(CPU_SEGEN, ErrorInj);
    /* Read XBAR SFR: */
    TestData = XBAR_ID.U;

    Mcal_SetENDINIT();

    /* Reset AlarmStatus and Timeout: */
    AlarmStatus = 0U;
    Timeout = SRI_SMU_ALARM_TIMEOUT;

    /* Wait for expected SMU alarm: */
    while((0U == (AlarmStatus & SMU_SRI_ECC_ADDR_PHASE_STS)) &&
          (Timeout > 0U))
    {
      Timeout = Timeout - 1U;

      Temp = Smu_GetAlarmStatus(SMU_SRI_ECC_ADDR_PHASE_GRP, &AlarmStatus);
      if (E_OK != Temp)
      {
        AlarmStatus = 0U;
        Timeout = 0U;
      } /* if (E_OK != Temp) */
    } /* while((0U == (AlarmStatus & SMU_SRI_ECC_ADDR_PHASE_STS)) &&
               (Timeout > 0U)) */

    /* Check if expected SMU alarm was triggered: */
    if (0U == (AlarmStatus & SMU_SRI_ECC_ADDR_PHASE_STS))
    {
      Result = SRI_ECC_ADDRESS;
      LoopBreak = 0x00U;
    } /* if (0U == (AlarmStatus & SMU_SRI_ECC_ADDR_PHASE_STS)) */
    else
    {
      /* Clear SRI address phase and bus error SMU alarms: */
      RetVal1 = Smu_ClearAlarmStatus(SMU_SRI_ECC_ADDR_PHASE_GRP,
                                     SMU_SRI_ECC_ADDR_PHASE_ALM);
      RetVal2 = Smu_ClearAlarmStatus(SMU_SRI_BUS_ERR_GRP,
                                     SMU_SRI_BUS_ERR_ALM);
      if ((E_OK != RetVal1) || (RetVal2 != E_OK))
      {
        Result = SRI_SMU_CLRALMSTSERR;
        LoopBreak = 0x00U;
      } /* if ((E_OK != RetVal1) || (RetVal2 != E_OK)) */
      else
      {
        /* Go on to next bit pattern: */
        EccInversion <<= 1;
        *TstSignature = (uint32)CRC32(*TstSignature, EccInversion);
      } /* if ((E_OK == RetVal1) && (RetVal2 == E_OK))*/
    } /* if (0U != (AlarmStatus & SMU_SRI_ECC_ADDR_PHASE_STS)) */
    LoopCnt++;
  } /* while( (LoopCnt < (uint8)SRI_ECC_BIT_COUNT) && (LoopBreak != 0U)) */
  
  if (SRI_NOTEXECUTED == Result)
  {
    /* Check if a bus trap was thrown for every erroneous access: */
    if (SRI_ECC_BIT_COUNT != Sri_DseTrapCount)
    {
      Result = SRI_ECC_ADRBTRAP_NG;
    } /* if (SRI_ECC_BIT_COUNT != Sri_DseTrapCount) */
    else
    {
	  /*test succeeded */
      Result = SRI_SUCCESS;
    } /* if (SRI_ECC_BIT_COUNT == Sri_DseTrapCount) */
  }/* if (SRI_NOTEXECUTED == Result) */
  
  /* Clear DSE TrapCounter: */
  Sri_DseTrapCount = 0U;
  UNUSED_PARAMETER(TestData)

  return Result;
} /* SriTst_lSlaveAddrDecoderXbarTst */

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : static Sl_TstRsltType SriTst_lSlaveDataDecoderTst                 **
**          (                                                                 **
**            uint32* const TstSignature,                                     **
**            uint32* const SlaveAddress,                                     **
**            uint8 AlarmGroup,                                               **
**            uint8 SMUAlarm                                                  **
**          )                                                                 **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) : SlaveAddress - SRI slave address to use for the test     **
**                   AlarmGroup - SMU alarm group of the expected alarm       **
**                   SMUAlarm - Expected SMU alarm                            **
**                                                                            **
** Parameters (out): TstSingature - Test signature generated by the test.     **
**                                                                            **
** Return value : SRI_NOTEXECUTED - Program flow consistency error. This      **
**                                      value should never be returned        **
**                SRI_SUCCESS - Test succeeded.                               **
**                SRI_SMU_CLRALMSTSERR - The test failed because clearing the **
**                                       SMU alarm failed.                    **
**                SRI_ECC_WRITE - Waiting for the SMU alarm timed out. If     **
**                                there is no SMU alarm generated it is most  **
**                                likely that the ECC error got not detected. **
**                                                                            **
** Description : This function does initiate a data write to the slave device **
**               but does inject ECC errors during the write phase. The slave **
**               device must detect a data ECC error and generate an SMU      **
**               alarm. As master CPUx_DMI is used.                           **
*******************************************************************************/
static Sl_TstRsltType SriTst_lSlaveDataDecoderTst
(
  uint32* const TstSignature,
  uint32* const SlaveAddress,
  uint8 AlarmGroup,
  uint8 SMUAlarm
)
{
  Sl_TstRsltType      Result = SRI_NOTEXECUTED;
  uint32              Timeout;
  uint32              AlarmStatus;
  uint32              EccInversion = 1U;
  uint8               LoopCnt = 0U;
  volatile uint32*    PtrTestAddr32 = (volatile uint32*)(void *)SlaveAddress;
  volatile uint32     TestData = 0U;
  uint32              TestBackup = *PtrTestAddr32;
  uint8               LoopBreak = 0x01U;
  Std_ReturnType      Temp;
  uint32              ErrorInj;  

  /* Loop through all ECC bits: */
  while((LoopCnt < (uint8)SRI_ECC_BIT_COUNT) && (LoopBreak != 0U))
  {
    /* Enable data write phase ECC inversion for current bit: */
    Mcal_ResetENDINIT();
    ErrorInj = ((uint32)SRI_ERR_INJ_MASTER_WR_PH | EccInversion);
    MTCR(CPU_SEGEN, ErrorInj);

    /* Write to SRI slave under test: */
    *PtrTestAddr32 = TestData;

    Mcal_SetENDINIT();

    /* Reset AlarmStatus and Timeout: */
    AlarmStatus = 0U;
    Timeout = SRI_SMU_ALARM_TIMEOUT;

    /* Wait for expected SMU alarm: */
    while ((0U == (AlarmStatus & ((uint32)1U << SMUAlarm))) &&
           (Timeout > 0U))
    {
      Timeout = Timeout - 1U;
      Temp = Smu_GetAlarmStatus(AlarmGroup, &AlarmStatus);
      if (E_OK != Temp)
      {
        AlarmStatus = 0U;
        Timeout = 0U;
      } /* if (E_OK != Temp) */
    } /* while ((0U == (AlarmStatus & ((uint32)1U << SMUAlarm))) &&
                (Timeout > 0U)) */

    /* Check if expected SMU alarm was triggered: */
    if (0U == (AlarmStatus & ((uint32)1U << SMUAlarm)))
    {
      Result = SRI_ECC_WRITE;
      LoopBreak = 0x00U;
    } /* if (0U == (AlarmStatus & ((uint32)1U << SMUAlarm)))*/
    else
    {
      /* Clear SMU alarms: */
      Temp = Smu_ClearAlarmStatus(AlarmGroup, SMUAlarm);
      if (E_OK != Temp)
      {
        Result = SRI_SMU_CLRALMSTSERR;
        LoopBreak = 0x00U;   
      } /* if (E_OK != Temp) */
      else
      {
        /* Go on to next bit pattern: */
        EccInversion <<= 1U;
        *TstSignature = (uint32)CRC32(*TstSignature, EccInversion);
      } /* if (E_OK == Temp) */
    } /* if (0U != (AlarmStatus & ((uint32)1U << SMUAlarm))) */
    LoopCnt++;     
  } /* while((LoopCnt < (uint8)SRI_ECC_BIT_COUNT) && (LoopBreak != 0U)) */

  /* Restore memory location used for testing: */
  *PtrTestAddr32 = TestBackup;

  /* Update result: */
  if (SRI_NOTEXECUTED == Result)
  {
    Result = SRI_SUCCESS;
  } /* if (SRI_NOTEXECUTED == Result) */

  MTCR(CPU_DIETR, 0x0U);
  MTCR(CPU_PIETR, 0x0U);

  return Result;
} /* SriTst_lSlaveDataDecoderTst */

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : static Sl_TstRsltType SriTst_lSlaveDataDecoderXbarTst             **
**          (                                                                 **
**            uint32* const TstSignature                                      **
**          )                                                                 **
**                                                                            **
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
** Parameters (out): TstSingature - Test signature generated by the test.     **
**                                                                            **
** Return value : SRI_NOTEXECUTED - The test has not yet been executed or     **
**                                  did for some reason not generate a valid  **
**                                  result.                                   **
**                SRI_SUCCESS - Test succeeded.                               **
**                SRI_SMU_CLRALMSTSERR - The test failed because clearing the **
**                                       SMU alarm failed.                    **
**                SRI_ECC_WRITE - Waiting for the SMU alarm timed out. If     **
**                                there is no SMU alarm generated it is most  **
**                                likely that the ECC error got not detected. **
**                                                                            **
** Description : This function injects SRI write phase ECC errors, writes a   **
**               XBAR special function register and checks, that the XBAR SRI **
**               slave detects the ECC error and signals it to the SMU.       **
**               CPUx_DMI SRI interface is used as SRI master.                **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType SriTst_lSlaveDataDecoderXbarTst
(
  uint32* const TstSignature
)
{
  Sl_TstRsltType      Result = SRI_NOTEXECUTED;
  uint32              Timeout;
  uint32              AlarmStatus;
  uint32              EccInversion = 1U;
  uint8               LoopCnt = 0U;
  volatile uint32     TestData;
  uint8               LoopBreak = 0x01U;
  Std_ReturnType      Temp;
  uint32              ErrorInj;
  
  /* Read XBAR_IDINT to ensure that it will not be changed, even in case the
   * error does not get detected and the write access not blocked. The
   * XBAR_IDINTEN SFR has been chosen, because it does not contain any bitfields
   * modified by hardware and so there will not be any side effects in case of
   * a non-blocked write access:
   */
  TestData = XBAR_IDINTEN.U;

  /* Loop through each ECC bit: */
  while( (LoopCnt < (uint8)SRI_ECC_BIT_COUNT) && (LoopBreak != 0U))
  {
    /* Enable write phase ECC inversion for current bit: */
    Mcal_ResetENDINIT();
    ErrorInj = ((uint32)SRI_ERR_INJ_MASTER_WR_PH | EccInversion);
    MTCR(CPU_SEGEN, ErrorInj);
    /* Write access to XBAR SFR: */
    XBAR_IDINTEN.U = TestData;

    Mcal_SetENDINIT();

    /* Reset AlarmStatus and Timeout: */
    AlarmStatus = 0U;
    Timeout = SRI_SMU_ALARM_TIMEOUT;

    /* Wait for expected SMU alarm: */
    while ((0U == (AlarmStatus & SMU_SRI_ECC_WRITE_PHASE_STS)) &&
           (Timeout > 0U))
    {
      Timeout = Timeout - 1U;
      Temp = Smu_GetAlarmStatus(SMU_SRI_ECC_WRITE_PHASE_GRP, &AlarmStatus);
      if (E_OK != Temp)
      {
        AlarmStatus = 0U;
        Timeout = 0U;
      } /* if (E_OK != Temp) */
    } /* while ((0U == (AlarmStatus & SMU_SRI_ECC_WRITE_PHASE_STS)) &&
                (Timeout > 0U)) */

    /* Check if expected SMU alarm was triggered: */
    if (0U == (AlarmStatus & SMU_SRI_ECC_WRITE_PHASE_STS))
    {
      Result = SRI_ECC_WRITE;
      LoopBreak = 0x00U;
    } /* if (0U == (AlarmStatus & SMU_SRI_ECC_WRITE_PHASE_STS)) */
    else
    {
      /* Clear SMU alarm: */
      Temp = Smu_ClearAlarmStatus(SMU_SRI_ECC_WRITE_PHASE_GRP,
                                  SMU_SRI_ECC_WRITE_PHASE_ALM);
      if (E_OK != Temp)
      {
        Result = SRI_SMU_CLRALMSTSERR;
        LoopBreak = 0x00U;
      } /* if (E_OK != Temp) */
      else
      {
        /* Go on to next bit pattern: */
        EccInversion <<= 1U;
        *TstSignature = (uint32)CRC32(*TstSignature, EccInversion);
      } /* if (E_OK == Temp) */
    } /* if (0U != (AlarmStatus & SMU_SRI_ECC_WRITE_PHASE_STS)) */
    LoopCnt++;
  } /* while( (LoopCnt < (uint8)SRI_ECC_BIT_COUNT) && (LoopBreak != 0U)) */

  /* Update test result: */
  if (SRI_NOTEXECUTED == Result)
  {
    Result = SRI_SUCCESS;
  } /* if (SRI_NOTEXECUTED == Result) */

  return Result;
} /* SriTst_lSlaveDataDecoderXbarTst */

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : static Sl_TstRsltType SriTst_lMasterDataDecoderTst                **
**          (                                                                 **
**            uint32* const TstSignature,                                     **
**            uint32* const SlaveAddress,                                     **
**            uint8 AlarmGroup,                                               **
**            uint8 SMUAlarm                                                  **
**          )                                                                 **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) : SlaveAddress - SRI slave address to use for the test     **
**                   AlarmGroup - SMU alarm group of the expected alarm       **
**                   SMUAlarm - Expected SMU alarm                            **
**                                                                            **
** Parameters (out): TstSignature - Test signature generated by the test.     **
**                                                                            **
** Return value : SRI_NOTEXECUTED - Program flow consistency error. This      **
**                                      value should never be returned        **
**                SRI_SUCCESS          - Test succeeded.                      **
**                SRI_SMU_CLRALMSTSERR - The test failed because clearing the **
**                                       SMU alarm failed.                    **
**                SRI_ECC_READ         - Corrupted data sent back to the      **
**                                       master was not recognized as         **
**                                       corrupted and no SMU alarm was       **
**                                       generated                            **
**                SRI_ECC_DATATRAP_NG  - Each ECC error in the SRI data phase **
**                                       must also generate a DIETR-Trap      **
**                                                                            **
** Description : Test the SRI error detection system by injecting an ECC      **
**               error during the SRI Write Phase.                            **
*******************************************************************************/
static Sl_TstRsltType SriTst_lMasterDataDecoderTst
(
  uint32* const TstSignature,
  uint32* const SlaveAddress,
  uint8 AlarmGroup,
  uint8 SMUAlarm
)
{
  Sl_TstRsltType      Result = SRI_NOTEXECUTED;
  uint32              Timeout;
  uint32              AlarmStatus;
  uint32              EccInversion = 1U;
  uint8               LoopCnt = 0U;
  volatile uint32*    PtrTestAddr32 = (volatile uint32*)(void *)SlaveAddress;
  volatile uint32     TestData = 0U;
  uint8               LoopBreak = 0x01U;
  Std_ReturnType      Temp;   
  uint32              ErrorInj;
  
  /* Loop through all ECC bits: */
  while ((LoopCnt < (uint8)SRI_ECC_BIT_COUNT) && (LoopBreak != 0U))
  {
    /* Suspend all interrupts and put remaining CPU cores to IDLE mode in
     * order to prevent interfering DMIx access:
     */
    Mcal_SuspendAllInterrupts();

    /* Enable read phase ECC inversion for current bit: */
    Mcal_ResetENDINIT();

    /* Set expected trap class and ID: */
    Sri_ExpectedTrapClass = SRI_TRAP_CLASS4;
    Sri_ExpectedTrapId = SRI_TRAP_ID6;

    ErrorInj = ((uint32)SRI_ERR_INJ_SLAVE_RD_PH | EccInversion);
    MTCR(CPU_SEGEN, ErrorInj);
    /* Read from some SRI slave: */
    TestData = *PtrTestAddr32;

    Mcal_SetENDINIT();

    Mcal_ResumeAllInterrupts();

    /* Reset AlarmStatus and Timeout: */
    AlarmStatus = 0U;
    Timeout = SRI_SMU_ALARM_TIMEOUT;

    /* Wait for expected SMU alarm: */
    while ((0U == (AlarmStatus & ((uint32)1U << SMUAlarm))) &&
           (Timeout > 0U))
    {
      Timeout = Timeout - 1U;
      Temp = Smu_GetAlarmStatus(AlarmGroup, &AlarmStatus);
      if (E_OK != Temp)
      {
        AlarmStatus = 0U;
        Timeout = 0U;
      } /* if (E_OK != Temp) */
    } /* while ((0U == (AlarmStatus & ((uint32)1U << SMUAlarm))) &&
                (Timeout > 0U)) */

    /* Check if expected SMU alarm was triggered: */
    if (0U == (AlarmStatus & ((uint32)1U << SMUAlarm)))
    {
      Result = SRI_ECC_READ;
      LoopBreak = 0x00U;
    } /* if (0U == (AlarmStatus & ((uint32)1U << SMUAlarm))) */
    else
    {
      /* Clear SMU alarms: */
      Temp = Smu_ClearAlarmStatus(AlarmGroup, SMUAlarm);
      if (E_OK != Temp)
      {
        Result = SRI_SMU_CLRALMSTSERR;
        LoopBreak = 0x00U;
      } /* if (E_OK != Temp) */
      else
      {
        /* Go on to next bit pattern: */
        EccInversion <<= 1U;
        *TstSignature = (uint32)CRC32(*TstSignature, EccInversion);
      } /* if (E_OK == Temp) */
    } /* if (0U != (AlarmStatus & ((uint32)1U << SMUAlarm))) */
    LoopCnt++;
  } /* while ((LoopCnt < (uint8)SRI_ECC_BIT_COUNT) && (LoopBreak != 0U)) */

  /* Update test result: */
  if (SRI_NOTEXECUTED == Result)
  {
    if (SRI_ECC_BIT_COUNT == Sri_DietrTrapCount)
    {
      Result = SRI_SUCCESS;
    }
    else
    {
      Result = SRI_ECC_DATATRAP_NG;
    } /* if (SRI_ECC_BIT_COUNT == Sri_DietrTrapCount) */
  } /* if (SRI_NOTEXECUTED == Result) */

  /* Reset DIETR register: */
  MTCR(CPU_DIETR, 0x0);

  /* Clear expected trap count: */
  Sri_DietrTrapCount = 0x0U;
  UNUSED_PARAMETER(TestData)

  return Result;
} /* SriTst_lMasterDataDecoderTst */

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : static Sl_TstRsltType SriTst_lMasterDataDecoderPMITst             **
**          (                                                                 **
**            uint32* const TstSignature,                                     **
**            uint32* const SlaveAddress                                      **
**          )                                                                 **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) : SlaveAddress - Slave address used for testing            **
**                                                                            **
** Parameters (out): TstSingature - Test signature generated by the test.     **
**                                                                            **
** Return value : SRI_NOTEXECUTED - Program flow consistency error. This      **
**                                      value should never be returned        **
**                SRI_SUCCESS          - Test succeeded.                      **
**                SRI_SMU_CLRALMSTSERR - The test failed because clearing the **
**                                       SMU alarm failed.                    **
**                SRI_ECC_READ         - Corrupted data sent back to the      **
**                                       master was not recognized as         **
**                                       corrupted and no SMU alarm was       **
**                                       generated                            **
**                SRI_ECC_DATATRAP_NG  - Each ECC error in the SRI data phase **
**                                       must also generate a DIETR-Trap      **
**                                                                            **
** Description : This function does try to execute code from the DSPR. As the **
**               CPU fetches instructions only via the PMU, the code that is  **
**               stored in the DSPR will be fetched by the PMI (which acts as **
**               SRI master). During this code fetch an SRI-read-phase ECC    **
**               error will be injected. The PMI must detect this ECC error   **
**               and generate an SMU alarm.                                   **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType SriTst_lMasterDataDecoderPMITst
(
  uint32* const TstSignature,
  uint32* const SlaveAddress
)
{
  Sl_TstRsltType      Result = SRI_NOTEXECUTED;
  uint32              Timeout;
  uint32              AlarmStatus;
  uint32              EccInversion = 1U;
  uint8               LoopCnt = 0U;
  volatile uint16*    PtrTestAddr16 = (volatile uint16*)(void *)SlaveAddress;
  uint32              TestBackup = *SlaveAddress;
  uint8               CoreId;
  uint8               LoopBreak = 0x01U;
  Std_ReturnType      Temp;
  uint32              ErrorInj;

  /* Read the core Id                                                         */
  CoreId = Mcal_GetCoreId(); 

  /* Copy return instruction to SlaveAddress; actually two return instructions
   * are copied. This eliminates the need for patching the return address in
   * the trap handler (if error detection fails, the first return instruction
   * will be executed and no trap generated. If the ECC error is detected,
   * the first return will not be executed, and a trap being generated, instead.
   * The trap handler will in this case continue execution at the second
   * return instruction):                                                     */
  PtrTestAddr16[0] = OPCODE_VALUE_RETURN;
  PtrTestAddr16[1] = OPCODE_VALUE_RETURN;

  /* Loop through all ECC bits: */
  while((LoopCnt < (uint8)SRI_ECC_BIT_COUNT) && (LoopBreak != 0U))
  {
    /* Suspend all interrupts and put remaining CPU cores to IDLE mode in
     * order to prevent interfering DMIx access:
     */
    Mcal_SuspendAllInterrupts();

    Mcal_ResetENDINIT();

    /* Set expected trap class and ID: */
    Sri_ExpectedTrapClass = SRI_TRAP_CLASS4;
    Sri_ExpectedTrapId = SRI_TRAP_ID5;

#ifdef __TASKING__
   DSPR_ADD_A2(SlaveAddress);
#endif
#ifdef __GNUC__
   ISYNC();
   DSPR_ADD_A2(SlaveAddress);
#endif

#ifdef _DIABDATA_C_TRICORE_
#if (_DIABDATA_C_TRICORE_ == 1U)
    DSPR_ADD_A2(SlaveAddress);
#endif
#endif

    ErrorInj = ((uint32)SRI_ERR_INJ_SLAVE_RD_PH | EccInversion);
    MTCR(CPU_SEGEN, ErrorInj);
    /* Call return instruction within DSPR: */
#ifdef __TASKING__
    __asm("calli a2");
#endif
#ifdef __GNUC__
    __asm("calli %a2");
#endif
#ifdef _DIABDATA_C_TRICORE_
#if (_DIABDATA_C_TRICORE_ == 1U)
    __asm("calli %a2");
#endif
#endif

    Mcal_SetENDINIT();

    Mcal_ResumeAllInterrupts();

    /* Reset AlarmStatus and Timeout: */
    AlarmStatus = 0U;
    Timeout = SRI_SMU_ALARM_TIMEOUT;

    /* Wait for expected SMU alarm: */
    while((0U == (AlarmStatus & ((uint32)1U << SMU_SRI_CPU_PMI_ERR_ALM))) &&
           (Timeout > 0U))
    {
      Timeout = Timeout - 1U;
      Temp = Smu_GetAlarmStatus(SriTst_CurrentCpuSriAlm[CoreId],
                                &AlarmStatus);
      if (E_OK != Temp)
      {
        AlarmStatus = 0U;
        Timeout = 0U;
      } /* if (E_OK != Temp) */
    } /* while ((0U == (AlarmStatus &
                        ((uint32)1U << SMU_SRI_CPU_PMI_ERR_ALM))) &&
                (Timeout > 0U)) */

    /* Check if expected SMU alarm was triggered: */
    if (0U == (AlarmStatus & ((uint32)1U << SMU_SRI_CPU_PMI_ERR_ALM)))
    {
      Result = SRI_ECC_READ;
      LoopBreak = 0x00U;
    } /* if (0U == (AlarmStatus & ((uint32)1U << SMU_SRI_CPU_PMI_ERR_ALM))) */
    else
    {
      /* Clear SMU alarms: */
      Temp = Smu_ClearAlarmStatus(SriTst_CurrentCpuSriAlm[CoreId],
                                       SMU_SRI_CPU_PMI_ERR_ALM);
      if (E_OK != Temp)
      {
        Result = SRI_SMU_CLRALMSTSERR;
        LoopBreak = 0x00U;
      } /* if (E_OK != Temp) */
      else
      {
        /* Go on to next bit pattern: */
        EccInversion <<= 1U;
        *TstSignature = (uint32)CRC32(*TstSignature, EccInversion);
      } /* if (E_OK == Temp) */
    } /* if (0U != (AlarmStatus & ((uint32)1U << SMU_SRI_CPU_PMI_ERR_ALM))) */
    LoopCnt++;
  } /* while((LoopCnt < (uint8)SRI_ECC_BIT_COUNT) && (LoopBreak != 0U)) */

  /* Restore memory location used for testing: */
  *SlaveAddress = TestBackup;

  /* Update test result: */
  if (SRI_NOTEXECUTED == Result)
  {
    if (SRI_ECC_BIT_COUNT == Sri_PietrTrapCount)
    {
      Result = SRI_SUCCESS;
    }
    else
    {
      Result = SRI_ECC_DATATRAP_NG;
    }/* if (SRI_ECC_BIT_COUNT == Sri_PietrTrapCount) */
  } /* if (SRI_NOTEXECUTED == Result) */

  /* Clear expected trap counter: */
  Sri_PietrTrapCount = 0x0U;

  return Result;
} /* SriTst_lMasterDataDecoderPMITst */

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static Sl_TstRsltType SriTst_lCPUDecodersTst            **
**                    (                                                       **
**                      const Sl_ParamSetType ParamSetIndex,                  **
**                      uint32* const TstSignature                            **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters (in)  : ParamSetIndex - Current configuration parameter set     **
**                                    index                                   **
**                                                                            **
** Parameters (out) : TstSignature - Test signature generated by the Test     **
**                                                                            **
** Return value     : SRI_SUCCESS           - Test succeeded.                 **
**                    SRI_CPU_DMI_ECC_ADR   - Test failed because the CPU DMI **
**                                            ECC logic did not detect a      **
**                                            corrupted address phase         **
**                    SRI_CPU_DMI_ECC_DATA - Test failed because the CPU DMI  **
**                                            ECC logic did not detect a      **
**                                            corrupted data write phase      **
**                                            in slave data decoder           **
**                    SRI_CPU_DMI_ECC_MDATA - Test failed because the CPU DMI **
**                                            ECC logic did not detect a      **
**                                            corrupted data write phase      **
**                                            in master data decoder          **
**                    SRI_CPU_PMI_ECC_ADR   - Test failed because the CPU PMI **
**                                            ECC logic did not detect a      **
**                                            corrupted address phase         **
**                    SRI_CPU_PMI_ECC_DATA - Test failed because the CPU PMI **
**                                            ECC logic did not detect a      **
**                                            corrupted data write phase      **
**                                            in slave data decoder           **
**                    SRI_CPU_PMI_ECC_MDATA - Test failed because the CPU PMI **
**                                            ECC logic did not detect a      **
**                                            corrupted data write phase      **
**                                            in master data decoder          **
**                    SRI_SMU_CLRALMSTSERR  - The test failed because         **
**                                            clearing the SMU alarm failed   **
**                                                                            **
** Description      : This function does test all SRI EDC decoders related to **
**                    the current CPU (the CPU this test is executed on)      **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType SriTst_lCPUDecodersTst
(
  const Sl_ParamSetType ParamSetIndex,
  uint32* const TstSignature
)
{
  Sl_TstRsltType      Result;
  Sl_TstRsltType      TmpResult;
  uint8               CoreId;
  uint8               SriAlm;

  /* Read the core Id                                                         */
  CoreId = Mcal_GetCoreId();
  
  SriAlm = SriTst_CurrentCpuSriAlm[CoreId];

  SriTst_lEnableOverlay(CoreId);

  /* 
    PMI and DMI do use the same address ecc decoder. However, CPUxPMI and 
	CPUxDMI SMU alarms are checked to detect errors for both cases (PSPR and 
	DSPR addresses).
   */
   
  /* - Check detection of DMI address phase errors: */
  TmpResult = SriTst_lSlaveAddrDecoderTst(TstSignature,
                                   (uint32*)((uint32)(&dummy[0]) | 0x20000000u),
                                   SriAlm,
                                   SMU_SRI_CPU_PMI_ERR_ALM
                                         );
  if (SRI_SUCCESS == TmpResult)
  {
    /* 
	  1. Check detection of DMI write phase errors: 
	  2. Clear XBARSRC service request SRR bit.
	*/
	
    TmpResult = SriTst_lSlaveDataDecoderTst(TstSignature,
                                   (uint32*)((uint32)(&dummy[0]) | 0x20000000u),
                                   SriAlm,
                                   SMU_SRI_CPU_DMI_ERR_ALM
                                           );
	SRC_XBARSRC.U = ((SRC_XBARSRC.U & SRI_XBARSRC_MASK) | (SRI_XBARSRC_CLRR_BIT));
	
    if (SRI_SUCCESS == TmpResult)
    {
      /* - check detection of DMI read phase errors: */
      TmpResult = SriTst_lMasterDataDecoderTst(TstSignature,
                                   (uint32*)((uint32)(&dummy[0]) | 0x20000000u),
                                   SriAlm,
                                   SMU_SRI_CPU_DMI_ERR_ALM
                                              );
      if (SRI_SUCCESS == TmpResult)
      {
        SriTst_lDisableOverlay(CoreId);

        /* - check detection of PMI address phase errors: */
        TmpResult = SriTst_lSlaveAddrDecoderTst(TstSignature,
                   SriTst_ConfigRoot[ParamSetIndex].SriTstPSPRTstAdr[CoreId],
                   SriAlm,
                   SMU_SRI_CPU_PMI_ERR_ALM
                                               );
        if (SRI_SUCCESS == TmpResult)
        {
          /* - check detection of PMI write phase errors: */
          TmpResult = SriTst_lSlaveDataDecoderTst(TstSignature,
                      SriTst_ConfigRoot[ParamSetIndex].SriTstPSPRTstAdr[CoreId],
                      SriAlm,
                      SMU_SRI_CPU_PMI_ERR_ALM
                                                 );
          if (SRI_SUCCESS == TmpResult)
          {
            /* - check detection of PMI read phase errors: */
            TmpResult = SriTst_lMasterDataDecoderPMITst(TstSignature,
                      SriTst_ConfigRoot[ParamSetIndex].SriTstDSPRTstAdr[CoreId]
                                                       );
            if (SRI_SUCCESS == TmpResult)
            {
              Result = TmpResult;
            } /* if (SRI_SUCCESS == TmpResult) */
            else
            {
              Result = SRI_CPU_PMI_ECC_MDATA;
            } /* if (SRI_SUCCESS != TmpResult) */
          } /* if (SRI_SUCCESS == TmpResult) */
          else
          {
            Result = SRI_CPU_PMI_ECC_DATA;
          } /* if (SRI_SUCCESS != TmpResult) */
        } /* if (SRI_SUCCESS == TmpResult) */
        else
        {
          Result = SRI_CPU_PMI_ECC_ADR;
        } /* if (SRI_SUCCESS != TmpResult) */
      } /* if (SRI_SUCCESS == TmpResult) */
      else
      {
        Result = SRI_CPU_DMI_ECC_MDATA;
        SriTst_lDisableOverlay(CoreId);
      } /* if (SRI_SUCCESS != TmpResult) */
    } /* if (SRI_SUCCESS == TmpResult) */
    else
    {
      Result = SRI_CPU_DMI_ECC_DATA;
      SriTst_lDisableOverlay(CoreId);
    } /* if (SRI_SUCCESS != TmpResult) */

  } /* if (SRI_SUCCESS == TmpResult) */
  else
  {
    Result = SRI_CPU_DMI_ECC_ADR;
    SriTst_lDisableOverlay(CoreId);
  } /* if (SRI_SUCCESS != TmpResult) */

  if (SRI_SMU_CLRALMSTSERR == TmpResult)
  {
    Result = TmpResult;
  } /* if (SRI_SMU_CLRALMSTSERR == TmpResult) */

  return Result;
} /* SriTst_lCPUDecodersTst */

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static void SriTst_lEnableOverlay                       **
**                    (                                                       **
**                      uint8 CoreID                                          **
**                    )                                                       **
**                                                                            **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters (in)  : CoreId  - The current CoreID                            **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function configures and enables the overlay system **
**                    so that PFlash accesses to the memory location of       **
**                    dummy are redirected to the DSPR memory.                **
**                                                                            **
*******************************************************************************/
static void SriTst_lEnableOverlay
(
  uint8 CoreId
)
{
  /* get the address of dummy in PFlash                                       */
  volatile uint32 targetBaseAddress = (uint32)&dummy;

  /* extract bits 5...22 of the original target address                       */
  targetBaseAddress = targetBaseAddress & 0x0FFFFFE0U;

  /* discard irrelevant bits                                                  */
  targetBaseAddress = targetBaseAddress >> 5;

  /* enable general overlay system*/
  switch (CoreId)
  {
    case 0:
      OVC0_RABR0.U = 0U;

      /* Select 32byte block size: */
      OVC0_OMASK0.U = SRI_OMASK_32BYTE_BLOCK_SIZE;

      OVC0_OTAR0.B.TBASE = targetBaseAddress;
      Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);
      DSYNC();
      SCU_OVCENABLE.B.OVEN0 = 1U;
      /* Redirection to DSPR core 0*/
      OVC0_RABR0.U = (OVC0_RABR0.U | 0x00000000U);
      /* enable RABR0-Range (block 0) overlay */
      OVC0_RABR0.U = (OVC0_RABR0.U | 0x80000000U);
      Mcal_SetSafetyENDINIT_Timed();
      break;
#if(MCAL_NO_OF_CORES > 1U)
    case 1:
      OVC1_RABR0.U= 0x0U;

      /* Select 32byte block size: */
      OVC1_OMASK0.U = SRI_OMASK_32BYTE_BLOCK_SIZE;

      OVC1_OTAR0.B.TBASE = targetBaseAddress;
      Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);
      DSYNC();
      SCU_OVCENABLE.B.OVEN1 = 1U;
      /* Redirection to DSPR core 1*/
      OVC1_RABR0.U = (OVC1_RABR0.U | 0x01000000U);
      /* enable RABR0-Range (block 0) overlay */
      OVC1_RABR0.U = (OVC1_RABR0.U | 0x80000000U);
      Mcal_SetSafetyENDINIT_Timed();
      break;
#if(MCAL_NO_OF_CORES == 3U)
    case 2:
      OVC2_RABR0.U = 0x0U;

      /* Select 32byte block size: */
      OVC2_OMASK0.U = SRI_OMASK_32BYTE_BLOCK_SIZE;

      OVC2_OTAR0.B.TBASE = targetBaseAddress;
      Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);
      DSYNC();
      SCU_OVCENABLE.B.OVEN2 = 1U;
      /* Redirection to DSPR core 2*/
      OVC2_RABR0.U = (OVC2_RABR0.U | 0x02000000U);
      /* enable RABR0-Range (block 0) overlay */
      OVC2_RABR0.U = (OVC2_RABR0.U | 0x80000000U);
      Mcal_SetSafetyENDINIT_Timed();
      break;
#endif /* (MCAL_NO_OF_CORES == 3U) */
#endif /* (MCAL_NO_OF_CORES > 1U) */

    default:
      /* do nothing here as only overlay control registers for core 0,1,2     */
      /* exist. If nothing is done here test will anyway fail.                */
      break;
  } /* switch (CoreId) */
} /* SriTst_lEnableOverlay */

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static void SriTst_lDisableOverlay                      **
**                    (                                                       **
**                      uint8 CoreId                                          **
**                    )                                                       **
**                                                                            **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters (in)  : CoreId  - Current Core ID                               **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function disables the overlay system so that no    **
**                    access redirection is done any more.                    **
**                                                                            **
*******************************************************************************/
static void SriTst_lDisableOverlay
(
  uint8 CoreId
)
{
  Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT); 
  DSYNC();

  /* disable general overlay system*/
  switch (CoreId)
   {
     case 0:
       /* disable RABR0-Range (block 0) overlay */
       OVC0_RABR0.U = 0x00000000U;
       SCU_OVCENABLE.B.OVEN0 = 0U;
       break;
#if(MCAL_NO_OF_CORES > 1U)

     case 1:
       /* disable RABR0-Range (block 0) overlay */
       OVC1_RABR0.U = 0x00000000U;
       SCU_OVCENABLE.B.OVEN1 = 0U;
       break;
#if(MCAL_NO_OF_CORES == 3U)
     case 2:
       /* disable RABR0-Range (block 0) overlay */
       OVC2_RABR0.U = 0x00000000U;
       SCU_OVCENABLE.B.OVEN2 = 0U;
       break;
#endif /* (MCAL_NO_OF_CORES == 3U) */
#endif /* (MCAL_NO_OF_CORES > 1U) */
     default:
       /* do nothing here as only overlay control registers for core 0,1,2    */
       /* exist. If nothing is done here test will anyway fail.               */
       break;
   } /* switch (CoreId) */

  DSYNC();
  Mcal_SetSafetyENDINIT_Timed();
} /* SriTst_lDisableOverlay */

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static Sl_TstRsltType SriTst_lAdditionalDecodersTst     **
**                    (                                                       **
**                      const Sl_ParamSetType ParamSetIndex,                  **
**                      uint32* const TstSignature                            **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters (in)  : ParamSetIndex - Current configuration parameter set     **
**                                    index                                   **
**                                                                            **
** Parameters (out) : TstSignature - Test signature generated by the Test     **
**                                                                            **
** Return value     : SRI_NOTEXECUTED       - The test has not yet been       **
**                                            executed or did for some reason **
**                                            not generate a valid result.    **
**                    SRI_SUCCESS           - Test succeeded.                 **
**                    SRI_LMU_ECC_ADDRESS   - Test failed because the LMU ECC **
**                                            decoder did not recognize a     **
**                                            corrupted address phase         **
**                    SRI_LMU_ECC_DATA      - Test failed because the LMU ECC **
**                                            decoder did not recognize a     **
**                                            corrupted data phase            **
**                    SRI_PMUDF_ECC_ADDRESS - Test failed because the PMU     **
**                                            DFLASH decoder did not          **
**                                            recognize a corrupted adr phase **
**                    SRI_PMUDF_ECC_DATA    - Test failed because the PMU     **
**                                            DFLASH decoder did not          **
**                                            recognize a corrupted data      **
**                                            phase                           **
**                    SRI_PMUPF_ECC_ADDRESS - Test failed because the PMU     **
**                                            PFLASH decoder did not          **
**                                            recognize a corrupted adr phase **
**                                                                            **
** Description      : This function does test all additional SRI EDC slave    **
**                    decoders that are not CPU related. This includes the    **
**                    LMU, the DMA, PMU-DFlash and PMU-PFlash.                **
*******************************************************************************/
static Sl_TstRsltType SriTst_lAdditionalDecodersTst
(
  const Sl_ParamSetType ParamSetIndex,
  uint32* const TstSignature
)
{
  Sl_TstRsltType      Result    = SRI_NOTEXECUTED;
  uint8               CoreId;

  /* Read the core Id: */
  CoreId = Mcal_GetCoreId();

  /* 
     1. Check the LMU slave decoder
	 2. Clear XBARSRC service request SRR bit.
  */

  if (0x1U == SriTst_ConfigRoot[ParamSetIndex].LmuTstEN[CoreId])
  {
    Result = SriTst_lLMUDecoderTst(TstSignature,
        SriTst_ConfigRoot[ParamSetIndex].SriTstLMUTstAdr[CoreId]);
	SRC_XBARSRC.U = ((SRC_XBARSRC.U & SRI_XBARSRC_MASK) | (SRI_XBARSRC_CLRR_BIT));
  } /* if (0x1U == SriTst_ConfigRoot[ParamSetIndex].LmuTstEN[CoreId]) */

  /* 
     1. Check the DFLASH slave decoder: 
	 2. Clear XBARSRC service request SRR bit.
  */
  if (0x1U == SriTst_ConfigRoot[ParamSetIndex].PmuDFlashTstEN[CoreId])
  {
    if ((SRI_NOTEXECUTED == Result) || (SRI_SUCCESS == Result))
    {
      Result = SriTst_lPMUDFlashDecoderTst(TstSignature,
          SriTst_ConfigRoot[ParamSetIndex].SriTstDFlashTstAdr[CoreId]);
	  SRC_XBARSRC.U = ((SRC_XBARSRC.U & SRI_XBARSRC_MASK) | (SRI_XBARSRC_CLRR_BIT));
    } /* if ((SRI_NOTEXECUTED == Result) || (SRI_SUCCESS == Result)) */
  } /* if (0x1U == SriTst_ConfigRoot[ParamSetIndex].PmuDFlashTstEN[CoreId]) */

  /* 
     1. Check the PFLASH slave decoder: 
	 2. Clear XBARSRC service request SRR bit.
  */
  if (0x1U == SriTst_ConfigRoot[ParamSetIndex].PmuPFlashTstEN[CoreId])
  {
    if ((SRI_NOTEXECUTED == Result) || (SRI_SUCCESS == Result))
    {
      Result = SriTst_lPMUPFlashDecoderTst(TstSignature,
              SriTst_ConfigRoot[ParamSetIndex].SriTstPFlashTstAdr[CoreId]);
	  SRC_XBARSRC.U = ((SRC_XBARSRC.U & SRI_XBARSRC_MASK) | (SRI_XBARSRC_CLRR_BIT));		  
    } /* if ((SRI_NOTEXECUTED == Result) || (SRI_SUCCESS == Result)) */
  } /* if (0x1U == SriTst_ConfigRoot[ParamSetIndex].PmuPFlashTstEN[CoreId]) */

  /* Check the DMA decoder: */
  if (0x1U == SriTst_ConfigRoot[ParamSetIndex].DmaTstEN[CoreId])
  {
    if ((SRI_NOTEXECUTED == Result) || (SRI_SUCCESS == Result))
    {
      Result = SriTst_lDMADecoderTst(ParamSetIndex, TstSignature);
    } /* if ((SRI_NOTEXECUTED == Result) || (SRI_SUCCESS == Result)) */
  } /* if (0x1U == SriTst_ConfigRoot[ParamSetIndex].DmaTstEN[CoreId]) */

  /* Check the XBAR decoder: */
  if (0x1U == SriTst_ConfigRoot[ParamSetIndex].XbarTstEN[CoreId])
  {
    if ((SRI_NOTEXECUTED == Result) || (SRI_SUCCESS == Result))
    {
      /* 1. Test address phase error detection of the XBAR SRI slave: 
	     2. Clear XBARSRC service request SRR bit.
	  */
      Result = SriTst_lSlaveAddrDecoderXbarTst(TstSignature);
	  SRC_XBARSRC.U = ((SRC_XBARSRC.U & SRI_XBARSRC_MASK) | (SRI_XBARSRC_CLRR_BIT));
	  
      if (SRI_SUCCESS == Result)
      {
        /* Test write phase error detection of the XBAR SRI slave: */
        Result = SriTst_lSlaveDataDecoderXbarTst(TstSignature);
      } /* if (SRI_SUCCESS == Result) */
    } /* if ((SRI_NOTEXECUTED == Result) || (SRI_SUCCESS == Result)) */
  } /* if (0x1U == SriTst_ConfigRoot[ParamSetIndex].XbarTstEN[CoreId]) */
  
  if(SRI_NOTEXECUTED == Result)
  {
    Result = SRI_SUCCESS;
  }

  return Result;
} /* SriTst_lAdditionalDecodersTst */

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static Sl_TstRsltType SriTst_lLMUDecoderTst             **
**                    (                                                       **
**                      uint32* const TstSignature,                           **
**                      unit32* const SriTstLMUTstAdr                         **
**                    )                                                       **
**                                                                            **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters (in)  : SriTsLMUTstAdr - The address used to read/write         **
**                                            to during the SRI LMU ECC       **
**                                            decoder test                    **
**                                                                            **
** Parameters (out) : TstSignature - Test signature generated by the Test     **
**                                                                            **
** Return value     : SRI_SUCCESS     - Test succeeded.                       **
**                    SRI_LMU_ECC_ADDRESS - Test failed because the LMU ECC   **
**                                          decoder did not recognize a       **
**                                          corrupted address phase           **
**                    SRI_LMU_ECC_DATA    - Test failed because the LMU ECC   **
**                                          decoder did not recognize a       **
**                                          corrupted data phase              **
**                                                                            **
** Description      : This function does test the SRI EDC decoders            **
**                    (address and data) related to the LMU                   **
*******************************************************************************/
static Sl_TstRsltType SriTst_lLMUDecoderTst
(
  uint32* const TstSignature,
  uint32* const SriTstLMUTstAdr
)
{
  Sl_TstRsltType      Result;

  /* Test detection of address phase errors: */
  Result = SriTst_lSlaveAddrDecoderTst(TstSignature,
                                       SriTstLMUTstAdr,
                                       SMU_SRI_ECC_ADDR_PHASE_GRP,
                                       SMU_SRI_ECC_ADDR_PHASE_ALM);
  if (SRI_SUCCESS == Result)
  {
    /* Test detection of write phase errors: */
    Result = SriTst_lSlaveDataDecoderTst(TstSignature,
                                         SriTstLMUTstAdr,
                                         SMU_SRI_ECC_ADDR_PHASE_GRP,
                                         SMU_SRI_ECC_WRITE_PHASE_ALM);
    if (SRI_SUCCESS != Result)
    {
      Result = SRI_LMU_ECC_DATA;
    } /* if (SRI_SUCCESS != Result) */
  } /* if (SRI_SUCCESS == Result) */
  else
  {
    Result = SRI_LMU_ECC_ADDRESS;
  } /* if (SRI_SUCCESS != Result) */
  
  /*
	Clear LMU_MEMCON ECC error bits which may get set during LMU test.
    Bit positions cleared are : INTERR, DATAERR and ADDERR.
  */
  Mcal_ResetENDINIT();
  
  LMU_MEMCON.U  &=  (unsigned_int) SRI_LMU_MEMCON_RESTORE_MASK;
  
  Mcal_SetENDINIT();

  return Result;
} /* SriTst_lLMUDecoderTst */


/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static Sl_TstRsltType SriTst_lPMUDFlashDecoderTst       **
**                    (                                                       **
**                      uint32* const TstSignature,                           **
**                      unit32* const SriTstPMUDFlashTstAdr                   **
**                    )                                                       **
**                                                                            **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters (in)  : SriTstPMUDFlashTstAdr - The address used to read/write  **
**                                            to during the SRI DFlash ECC    **
**                                            decoder test                    **
**                                                                            **
** Parameters (out) : TstSignature - Test signature generated by the Test     **
**                                                                            **
** Return value     : SRI_SUCCESS          - Test succeeded.                  **
**                    SRI_PMUDF_ECC_ADDRESS - Test failed because the PMU     **
**                                            DFLASH decoder did not          **
**                                            recognize a corrupted adr phase **
**                    SRI_PMUDF_ECC_DATA    - Test failed because the PMU     **
**                                            DFLASH decoder did not          **
**                                            recognize a corrupted data      **
**                                            phase                           **
**                                                                            **
** Description      : This function does test the SRI EDC decoders            **
**                    (address and data) related to the PMU DFlash            **
*******************************************************************************/
static Sl_TstRsltType SriTst_lPMUDFlashDecoderTst
(
  uint32* const TstSignature,
  uint32* const SriTstPMUDFlashTstAdr
)
{
  Sl_TstRsltType      Result;

  /* Check detection of address phase errors: */
  Result = SriTst_lSlaveAddrDecoderTst(TstSignature,
                                       SriTstPMUDFlashTstAdr,
                                       SMU_SRI_ECC_ADDR_PHASE_GRP,
                                       SMU_SRI_ECC_ADDR_PHASE_ALM);
  if (SRI_SUCCESS == Result)
  {
    /* Check detection of write phase errors: */
    Result = SriTst_lSlaveDataDecoderTst(TstSignature,
                                         SriTstPMUDFlashTstAdr,
                                         SMU_SRI_ECC_ADDR_PHASE_GRP,
                                         SMU_SRI_ECC_WRITE_PHASE_ALM);
    if (SRI_SUCCESS != Result)
    {
      Result = SRI_PMUDF_ECC_DATA;
    } /* if (SRI_SUCCESS != Result) */
  } /* if (SRI_SUCCESS == Result) */
  else
  {
    Result = SRI_PMUDF_ECC_ADR;
  } /* if (SRI_SUCCESS != Result) */

  return Result;
} /* SriTst_lPMUDFlashDecoderTst */

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static Sl_TstRsltType SriTst_lPMUPFlashDecoderTst       **
**                    (                                                       **
**                      uint32* const TstSignature,                           **
**                      unit32* const SriTstPMUPFlashTstAdr                   **
**                    )                                                       **
**                                                                            **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters (in)  : SriTstPMUPFlashTstAdr - PFlash address to be read from  **
**                                            during the Pflash ECC address   **
**                                            decoder                         **
**                                                                            **
** Parameters (out) : TstSignature - Test signature generated by the Test     **
**                                                                            **
** Return value     : SRI_SUCCESS           - Test succeeded.                 **
**                    SRI_PMUPF_ECC_ADDRESS - Test failed because the PMU     **
**                                            PFLASH decoder did not recognize**
**                                            a corrupted adrress phase       **
**                                                                            **
** Description      : This function does test the SRI EDC decoders            **
**                    (address and data) related to the PMU PFlash            **
*******************************************************************************/
static Sl_TstRsltType SriTst_lPMUPFlashDecoderTst
(
  uint32* const TstSignature,
  uint32* const SriTstPMUPFlashTstAdr
)
{
  Sl_TstRsltType      Result;

  /* Test detection of address phase errors: */
  Result = SriTst_lSlaveAddrDecoderTst(TstSignature,
                                       SriTstPMUPFlashTstAdr,
                                       SMU_SRI_ECC_ADDR_PHASE_GRP,
                                       SMU_SRI_ECC_ADDR_PHASE_ALM);
  if (SRI_SUCCESS != Result)
  {
    Result = SRI_PMUPF_ECC_ADR;
  } /* if (SRI_SUCCESS != Result) */

  return Result;
} /* SriTst_lPMUPFlashDecoderTst */

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static Sl_TstRsltType SriTst_lDMADecoderTst             **
**                    (                                                       **
**                      const Sl_ParamSetType ParamSetIndex,                  **
**                      uint32* const TstSignature                            **
**                    )                                                       **
**                                                                            **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters (in)  : ParamSetIndex - Identifies the parameter set to be used **
**                                    for test execution                      **
**                                                                            **
** Parameters (out) : TstSignature     - Test signature generated by the Test **
**                                                                            **
** Return value     : SRI_SUCCESS      - Test succeeded.                      **
**                    SRI_DMA_ECC_DATA - Test failed because the DAM data     **
**                                       decoder did not recognize a          **
**                                       corrupted data phase                 **
**                    SRI_DMA_CLC_TIMEOUT - Test failed because the DAM clock **
**                                       is not initialized properly.         **
**                                                                            **
** Description      : This function does test the SRI EDC decoders            **
**                    related to the DMA                                      **
*******************************************************************************/
static Sl_TstRsltType SriTst_lDMADecoderTst
(
  const Sl_ParamSetType ParamSetIndex,
  uint32* const TstSignature
)
{
  Sl_TstRsltType      Result;
  uint32              Timeout   = SRI_DMA_MODENABLE_TIMEOUT;
  uint32              DmaClcBackup = 0U;
  uint32              DmaChBackup;
  uint32              DmaChSourceBackup;
  uint32              DmaChDestBackup;
  uint32              DmaChRdataCrcBackup;
  uint32              DmaChSDaddrCrcBackup;
  uint8               CoreId;
  uint32              backup;
  volatile uint32     Dummy;

  /* Read the core Id                                                         */
  CoreId = Mcal_GetCoreId();

  /* Backup of DSPR Memory used for DMA destination address   */
  backup = *(SriTst_ConfigRoot[ParamSetIndex].SriTstDSPRTstAdr[CoreId] + 1U);

  /* Check if DMA module is enabled. If not enable it.                        */
  if (DMA_CLC.B.DISS != 0U)
  {
    /* Backup DMA CLC: */
    DmaClcBackup = DMA_CLC.U;

    Mcal_ResetENDINIT();
    /* DMA clock control register.        */
    DMA_CLC.B.DISR   = 0x0U;
    Mcal_SetENDINIT();
    do
    {
      Timeout = Timeout - 1U;
      /* wait until module is enabled */
    }
    while ((DMA_CLC.B.DISS != 0U) && (0U < Timeout));
  } /* if (DMA_CLC.B.DISS != 0U) */

  /* Check if DMA clock enable has succeeded: */
  if(DMA_CLC.B.DISS != 0U)
  {
    Result = SRI_DMA_CLC_TIMEOUT;
  } /* if(DMA_CLC.B.DISS != 0U) */
  else
  {
    /* Backup the DMA channel configuration  */
    DmaChBackup          = DMA_CONFIG_SRI.U;
    DmaChSourceBackup    = DMA_SOURCE_SRI.U;
    DmaChDestBackup      = DMA_DESTINATION_SRI.U;
	DmaChRdataCrcBackup  = DMA_RDATA_CRC_SRI.U;
	DmaChSDaddrCrcBackup = DMA_SDADDR_CRC_SRI.U;
  
    /* Configure DMA channel for SRI test   */
    DMA_CONFIG_SRI.B.TREL   = 0x8U;      /* Transfer reload value  */
    DMA_CONFIG_SRI.B.BLKM   = 0x0U;      /* Block mode    */
    DMA_CONFIG_SRI.B.RROAT  = 0x0U;      /* Single Transfer  */
    DMA_CONFIG_SRI.B.CHMODE = 0x0U;      /* Single operation mode   */
    DMA_CONFIG_SRI.B.CHDW   = 0x2U;      /* 32 bit data word selected  */
    DMA_CONFIG_SRI.B.PATSEL = 0x0U;      /* Pattern detection disabled  */
  
    /* Execute DMA Decoder test   */
    Result = SriTst_lDoDMADecoderTst(ParamSetIndex, TstSignature);
  
    /* Restore the DMA channel configuration   */
    DMA_CONFIG_SRI.U      = DmaChBackup;
    DMA_SOURCE_SRI.U      = DmaChSourceBackup;
    DMA_DESTINATION_SRI.U = DmaChDestBackup;
	DMA_RDATA_CRC_SRI.U   = DmaChRdataCrcBackup;
    DMA_SDADDR_CRC_SRI.U  = DmaChSDaddrCrcBackup;
    DMA_CHCONTROL_SRI.U  |= SRI_DMACHCSR_MASK;
    /* restore the DSPR memory  */
    *(SriTst_ConfigRoot[ParamSetIndex].SriTstDSPRTstAdr[CoreId] + 1U) = backup;
  
    /* Restore DMA clock enable: */
    if (0U != DmaClcBackup)
    {
      Mcal_ResetENDINIT();
      DMA_CLC.U = DmaClcBackup;
      Mcal_SetENDINIT();

      /* Dummy read back according to MOD_CLC documentation: */
      Dummy = DMA_CLC.U;
      UNUSED_PARAMETER(Dummy)
    } /* if (0U != DmaClcBackup) */

    /* Update error code: */
    if (SRI_SUCCESS != Result)
    {
      Result = SRI_DMA_ECC_DATA;
    } /* if (SRI_SUCCESS != Result) */
  } /* if(DMA_CLC.B.DISS == 0U) */

  return Result;
} /* SriTst_lDMADecoderTst */

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : static Sl_TstRsltType SriTst_lDoDMADecoderTst                     **
**          (                                                                 **
**            const Sl_ParamSetType ParamSetIndex,                            **
**            uint32* const TstSignature                                      **
**          )                                                                 **
**                                                                            **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in)  : ParamSetIndex - Identifies the parameter set to be used **
**                                    for test execution                      **
**                                                                            **
** Parameters (out): TstSignature - Test signature generated by the test.     **
**                                                                            **
** Return value : SRI_NOTEXECUTED      - The test has not yet been executed   **
**                                       or did for some reason not generate  **
**                                       a valid result.                      **
**                SRI_SUCCESS          - Test succeeded.                      **
**                SRI_SMU_CLRALMSTSERR - The test failed because clearing the **
**                                       SMU alarm failed.                    **
**                SRI_ECC_WRITE        - Waiting for the SMU alarm timed out. **
**                                       If there is no SMU alarm generated   **
**                                       it is most likely that the ECC error **
**                                       got not detected.                    **
**                                                                            **
**                                                                            **
** Description : This function does test the SRI EDC decoders (data) related  **
**               to the DMA.                                                  **
*******************************************************************************/
static Sl_TstRsltType SriTst_lDoDMADecoderTst
(
  const Sl_ParamSetType ParamSetIndex,
  uint32* const TstSignature
)
{
  Sl_TstRsltType      Result = SRI_NOTEXECUTED;
  uint32              Timeout;
  uint32              AlarmStatus;
  uint32              EccInversion = 1U;
  uint8               LoopCnt = 0U;
  uint8               CoreId;
  uint8               LoopBreak = 0x01U;
  Std_ReturnType      Temp;
  uint32              ErrorInj;
  
  /* Read the core Id                                                         */
  CoreId = Mcal_GetCoreId(); 

  /* Loop through all ECC bits: */
  while((LoopCnt < (uint8)SRI_ECC_BIT_COUNT) && (LoopBreak != 0U))
  {
    /* Set DSPR Address as DMA source address                                 */
    DMA_SOURCE_SRI.U =
      (uint32)SriTst_ConfigRoot[ParamSetIndex].SriTstDSPRTstAdr[CoreId];

    /* Set DSPR Address + 4U as DMA destination address                       */
    DMA_DESTINATION_SRI.U =
      (unsigned_int)SriTst_ConfigRoot[ParamSetIndex].SriTstDSPRTstAdr[CoreId] +
      (unsigned_int)4U;

    /* Suspend all interrupts and put remaining CPU cores to IDLE mode in order
     * to prevent interfering DMIx access:
     */
    Mcal_SuspendAllInterrupts();

    Mcal_ResetENDINIT();    
    ErrorInj = ((uint32)SRI_ERR_INJ_SLAVE_RD_PH | EccInversion);
    MTCR(CPU_SEGEN, ErrorInj);
    /* Start DMA transfer: */
    DMA_CHCONTROL_SRI.B.SCH = 0x1U;
    __asm("nop");
    __asm("nop");
     Mcal_SetENDINIT();

    Mcal_ResumeAllInterrupts();

    /* Reset AlarmStatus and Timeout: */
    AlarmStatus = 0U;
    Timeout = SRI_SMU_ALARM_TIMEOUT;

    /* Wait for expected SMU alarm: */
    while ((0U == (AlarmStatus & SMU_SRI_ECC_READ_PHASE_STS)) &&
           (Timeout > 0U))
    {
      Timeout = Timeout - 1U;
      if (E_OK != Smu_GetAlarmStatus(SMU_SRI_ECC_WRITE_PHASE_GRP, &AlarmStatus))
      {
        AlarmStatus = 0U;
        Timeout = 0U;
      } /* if (E_OK != Smu_GetAlarmStatus(SMU_SRI_ECC_WRITE_PHASE_GRP,
                                          &AlarmStatus)) */
    } /* while ((0U == (AlarmStatus & SMU_SRI_ECC_READ_PHASE_STS)) &&
                (Timeout > 0U)) */

    /* Check if expected SMU alarm was triggered: */
    if (0U == (AlarmStatus & SMU_SRI_ECC_READ_PHASE_STS))
    {
      Result = SRI_ECC_WRITE;
      LoopBreak = 0x00U;  
    } /* if (0U == (AlarmStatus & SMU_SRI_ECC_READ_PHASE_STS)) */
    else
    {
      /* Clear SMU alarm: */
      Temp = Smu_ClearAlarmStatus(SMU_SRI_ECC_WRITE_PHASE_GRP,
                                  SMU_SRI_ECC_READ_PHASE_ALM);
      if (E_OK != Temp)
      {
        Result = SRI_SMU_CLRALMSTSERR;
        LoopBreak = 0x00U;  
      } /* if (E_OK != Temp) */
      else
      {
        /* Go on to next bit position: */
        EccInversion <<= 1U;
        *TstSignature = (uint32)CRC32(*TstSignature, EccInversion);
      } /* if (E_OK == Temp) */
    } /* if (0U != (AlarmStatus & SMU_SRI_ECC_READ_PHASE_STS)) */
    LoopCnt++;    
  } /* while((LoopCnt < (uint8)SRI_ECC_BIT_COUNT) && (LoopBreak != 0U)) */

  /* Update test result: */
  if (SRI_NOTEXECUTED == Result)
  {
    Result = SRI_SUCCESS;
  } /* if (SRI_NOTEXECUTED == Result) */

  return Result;
} /* SriTst_lDoDMADecoderTst */

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : static Sl_TstRsltType SriTst_lUser0AccTst                         **
**          (                                                                 **
**            uint32* const TstSignature                                      **
**          )                                                                 **
**                                                                            **
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
** Parameters (out): TstSingature - Test signature generated by the test.     **
**                                                                            **
** Return value : SRI_NOTEXECUTED  - The test has not yet been executed or    **
**                                   did for some reason not generate a valid **
**                                   result.                                  **
**                SRI_SUCCESS      - Test succeeded.                          **
**                SRI_USER0_ACCERR - Test failed because access to a          **
**                                   supervisor-mode-only register got not    **
**                                   blocked although it was executed in      **
**                                   USER0 mode.                              **
**                                                                            **
** Description : Test the SRI I/O Privilege mechanism by performing a read    **
**               access to a Supervisor-Mode-only register from User-0 mode.  **
*******************************************************************************/
#ifdef _DIABDATA_C_TRICORE_
#if (_DIABDATA_C_TRICORE_ == 1U)
__attribute__ ((use_frame_pointer))
#endif
#endif
static Sl_TstRsltType SriTst_lUser0AccTst
(
  uint32* const TstSignature
)
{
  uint32          Psw;
  volatile uint32 Flash0Fcon = 0U;
  Sl_TstRsltType  Result;

  /* Switch to User 0 mode. Supervisor will be automatically re-entered
   * by the return instruction, when the subroutine is left:
   */
  Psw = (uint32)MFCR(CPU_PSW);
  Psw &= ~(SRI_PSW_IO_MASK);
  Psw |= SRI_PSW_USER0_MODE;
  MTCR(CPU_PSW, Psw);

  UNUSED_PARAMETER(Flash0Fcon)
  
  /* Set expected trap class and ID: */
  Sri_ExpectedTrapClass = SRI_TRAP_CLASS1;
  Sri_ExpectedTrapId = SRI_TRAP_ID5;

  /* Try to read from the protected FLASH0_FCON register: */
  Flash0Fcon = FLASH0_FCON.U;
  __asm("nop");
  __asm("nop");

  /* Check if a Memory Protection Peripheral Access trap was thrown: */
  if (1U != Sri_MppTrapCount)
  {
    Result = SRI_USER0_ACCERR;
  } /* if (1U != Sri_MppTrapCount) */
  else
  {
    Result = SRI_SUCCESS;
  } /* if (1U == Sri_MppTrapCount) */

  /* Update test signature: */
  *TstSignature = (uint32)CRC32(*TstSignature, (uint32)Sri_MppTrapCount);

  /* Reset Memory Protection Peripheral Access trap counter: */
  Sri_MppTrapCount = 0U;

  return Result;
} /* SriTst_lUser0AccTst */

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : static Sl_TstRsltType SriTst_lUser1AccTst                         **
**          (                                                                 **
**            uint32* const TstSignature                                      **
**          )                                                                 **
**                                                                            **
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
** Parameters (out): TstSignature  - Test signature generated by the test.    **
**                                                                            **
** Return value : SRI_NOTEXECUTED  - The test has not yet been executed or    **
**                                   did for some reason not generate a valid **
**                                   result.                                  **
**                SRI_SUCCESS      - Test succeeded.                          **
**                SRI_USER1_ACCERR - The test has failed because the USER1    **
**                                   mode access to a supervisor-mode-only    **
**                                   register gets not blocked.               **
**                                                                            **
** Description : Test the SRI I/O Privilege mechanism by performing a write   **
**               access to a Supervisor-Mode-only register from User-1 mode.  **
*******************************************************************************/
#ifdef _DIABDATA_C_TRICORE_
#if (_DIABDATA_C_TRICORE_ == 1U)
__attribute__ ((use_frame_pointer))
#endif
#endif
static Sl_TstRsltType SriTst_lUser1AccTst
(
  uint32* const TstSignature
)
{
  uint32          Psw;
  volatile uint32 Flash0Fcon;
  Sl_TstRsltType  Result;

  /* Switch to User 1 mode. Supervisor will be automatically re-entered
   * by the return instruction, when the subroutine is left:
   */
  Psw = (uint32)MFCR(CPU_PSW);
  Psw &= ~(SRI_PSW_IO_MASK);
  Psw |= SRI_PSW_USER1_MODE;
  MTCR(CPU_PSW, Psw);

  /* Set expected trap class and ID: */
  Sri_ExpectedTrapClass = SRI_TRAP_CLASS4;
  Sri_ExpectedTrapId = SRI_TRAP_ID3;

  /* Try to read and write to the protected FLASH0_FCON 
   * register with same read value.
   */
  Flash0Fcon = FLASH0_FCON.U;
  Mcal_ResetENDINIT();
  FLASH0_FCON.U = Flash0Fcon;
  Mcal_SetENDINIT();

  /* Check if a Data Access Asynchronous Error trap was thrown: */
  if (1U != Sri_DaeTrapCount)
  {
    Result = SRI_USER1_ACCERR;
  } /* if (1U != Sri_DaeTrapCount) */
  else
  {
    Result = SRI_SUCCESS;
  } /* if (1U == Sri_DaeTrapCount) */

  /* Update test signature: */
  *TstSignature = (uint32)CRC32(*TstSignature, (uint32)Sri_DaeTrapCount);

  /* Reset Data Access Asynchronous Error trap counter: */
  Sri_DaeTrapCount = 0U;

  return Result;
} /* SriTst_lUser1AccTst */

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : static Sl_TstRsltType SriTst_lUnmappedAdrTst                      **
**          (                                                                 **
**            uint32* const TstSignature                                      **
**          )                                                                 **
**                                                                            **
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
** Parameters (out): TstSingature - Test signature generated by the test.     **
**                                                                            **
** Return value : SRI_NOTEXECUTED - The test has not yet been executed or     **
**                                  did for some reason not generate a valid  **
**                                  result.                                   **
**                SRI_SUCCESS - Test succeeded.                               **
**                SRI_UNMAPPED_ACCERR - Test failed because an access to a    **
**                                      memory location that is not mapped to **
**                                      any SRI device did not generate a trap**
**                                                                            **
** Description : Test the SRI error detection mechanism by performing a read  **
**               access to an address not mapped to any SRI device.           **
*******************************************************************************/
static Sl_TstRsltType SriTst_lUnmappedAdrTst
(
  uint32* const TstSignature
)
{
  volatile uint32*    PtrTestAddr32 = (volatile uint32*)SRI_UNMAPPED_ADDR;
  volatile uint32     TestData = 0U;
  Sl_TstRsltType      Result = SRI_NOTEXECUTED;

  /* Set expected trap class and ID: */
  Sri_ExpectedTrapClass = SRI_TRAP_CLASS4;
  Sri_ExpectedTrapId = SRI_TRAP_ID2;

  /* Read access to Unmapped address: */
  TestData = *PtrTestAddr32;

  /* Update test signature: */
  *TstSignature = (uint32)CRC32(*TstSignature, (uint32)Sri_DseTrapCount);

  /* Check if a Data Access Synchronous Error trap was thrown: */
  if (1U != Sri_DseTrapCount)
  {
    Result = SRI_UNMAPPED_ACCERR;
  } /* if (1U != Sri_DseTrapCount)*/
  else
  {
    Result = SRI_SUCCESS;
  } /* if (1U == Sri_DseTrapCount) */

  /* Clear Data Access Synchronous Error trap counter: */
  Sri_DseTrapCount = 0U;
  UNUSED_PARAMETER(TestData)

  return Result;
} /* SriTst_lUnmappedAdrTst */

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : static Sl_TstRsltType SriTst_lUnsupportedOCTst                    **
**          (                                                                 **
**            uint32* const TstSignature                                      **
**          )                                                                 **
**                                                                            **
** Description : Test the SRI error detection mechanism of unsupported        **
**               Op-Codes by performing an 8bit access to a 16bit-access-only **
**               register.                                                    **
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
** Parameters (out): TstSingature  - Test signature generated by the test.    **
**                                                                            **
** Return value : SRI_NOTEXECUTED  - The test has not yet been executed or    **
**                                   did for some reason not generate a valid **
**                                   result.                                  **
**                SRI_SUCCESS      - Test succeeded.                          **
**                SRI_UNSUPP_OCERR - Test failed because although an          **
**                                   unsupported Opcode was used it got not   **
**                                   detected and therefore no trap had been  **
**                                   generated.                               **
**                                                                            **
** Description : Test the SRI error detection mechanism of unsupported        **
**               Op-Codes by performing an 8bit access to a 16bit-access-only **
**               register.                                                    **
*******************************************************************************/
static Sl_TstRsltType SriTst_lUnsupportedOCTst
(
  uint32* const TstSignature
)
{
  volatile uint8*     PtrTestAddr8;
  volatile uint8      TestData = 0U;
  Sl_TstRsltType      Result = SRI_NOTEXECUTED;

  /* Set expected trap class and ID: */
  Sri_ExpectedTrapClass = SRI_TRAP_CLASS4;
  Sri_ExpectedTrapId = SRI_TRAP_ID2;

  /* 
      Make an 8bit access to a 16bit access only register: 
	  Trap generation is validated for P and E cores both to cover all devices.
  */
  PtrTestAddr8 = (volatile uint8*)(void *)&CPU0_SPROT_RGN0_LA;
  TestData = *PtrTestAddr8;

  /* Update test signature: */
  *TstSignature = (uint32)CRC32(*TstSignature, (uint32)Sri_DseTrapCount);

  /* Check if a Data Access Synchronous Error trap was thrown: */
  if (1U != Sri_DseTrapCount)
  {
    Result = SRI_UNSUPP_OCERR;
  } /* if (1U != Sri_DseTrapCount) */
  else
  {
    Result = SRI_SUCCESS;
  } /* if (1U == Sri_DseTrapCount) */

  /* Clear Data Access Synchronous Error trap counter:                      */
  Sri_DseTrapCount = 0U;
  UNUSED_PARAMETER(TestData)

  return Result;
} /* SriTst_lUnsupportedOCTst */

#define IFX_SRI_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
