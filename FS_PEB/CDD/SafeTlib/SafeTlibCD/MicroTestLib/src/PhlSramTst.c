/*******************************************************************************
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
**   $FILENAME   : PhlSramTst.c $                                             **
**                                                                            **
**   $CC VERSION : \main\23 $                                                 **
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
**                 - functionality of the Peripheral SRAM test                **
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
#include "PhlSramTst.h"
#include "PhlSramTst_MemDef.h"
#include "SmuInt.h"
#include "Sl_Ipc.h"
#include "IfxCpu_bf.h"
#include "IfxCpu_reg.h"
#include "IfxMtu_reg.h"
#include "IfxMc_bf.h"
#include "IfxMc_reg.h"
#include "IfxFlash_reg.h"
#include "IfxGtm_reg.h"
#include "IfxScu_reg.h"
#include "IfxSmu_reg.h"
#if((CHIP_ID != 22U)&&(CHIP_ID != 21U))
#include "IfxEth_reg.h"
#include "IfxEmem_reg.h"
#endif
#include "IfxDma_reg.h"
#include "IfxDma_bf.h"
/*******************************************************************************
**                      Local Macro Definitions                               **
*******************************************************************************/

/* MCx_CONNFIG0 values: */
#define PHSR_CONFIG0_NUMACCS_1              (1U)
#define PHSR_CONFIG0_ACCSTYPE_RD            (1U)
#define PHSR_CONFIG0_ACCSTYPE_WR            (0U)

/* Invalid backup value, indicating that nothing is to be restored: */
#define PHSR_INV_BACKUP_VALUE               ((uint32)0xFFFFFFFFU)

/* Size of address range of each memory controller in bytes: */
#define PHSR_MC_ADDR_RANGE_SIZE             ((uint32)&MODULE_MC1 -            \
                                             (uint32)&MODULE_MC0)

/* Maximum number of RDBFL registers per memory controller: */
#define PHSR_MAX_RDBFL_REGS                 (40U)

/* Maximum number of wordlines used by the test:
 * ATTENTION: If the Peripheral SRAM memory definition file gets updated,
 *            the maximum number of wordlines needs to be set to the maximum
 *            number of ETRR registers specified in that file + 1.
 */
#define PHSR_MAX_NR_OF_WORDLINES            (2U)

/* Number of bits per RDBFLx SFR: */
#define PHSR_RDBFL_REG_WIDTH                (16U)

/* SMU alarm timeout. The value was chosen based on following considerations:
 * The worst case number of SMU cycles before an alarm gets visible is
 * n * 2 + 20 (with n = max. number of simultaneous alarms). With a maximum
 * of 32 * 7 alarms and maximum clock ratio fSPB/fSRI = 1/4 this evaluates to
 * 1872 CPU clock cycles. To avoid the counting the number of instructions per
 * loop cycle, it is assumed that only one instruction is executed per loop
 * cycle and thus the number of CPU clock cycles is directly used as timeout
 * value:
 */
#define PHSR_SMU_ALM_TIMEOUT                (2000U)

/* Timeout for enabling the MTU clock. As there is no information available
 * about how much time is required to enable the MTU clock, this value was
 * arbitrarily chosen to a relatively high value:
 */
#define PHSR_CLK_EN_TIMEOUT                 (0x100U)

/* Timeout for reading or writing a wordline via the MBIST.
 * The actual value was calculated as follows:
 * - Reading / writing a wordline takes a maximum of 9 SRAM clocks
 * - The minimum SRAM clock supported by this test is 1MHz (CoU)
 * - The maximum CPU clock is 300MHz
 * => Maximum waiting time is (300/1)*9 = 2700 CPU cycles
 */
#define PHSR_MBIST_RW_OP_TIMEOUT            (2700U)

/* Timeout when waiting for a SFR (e.g. CCUCONx) to become unlocked: */
#define PHSR_SFR_LOCK_TIMEOUT               (0x100U)

/* MCONTROL.USERED bit: */
#define PHSR_MC_MCONTROL_USERED_MSK         (1U)
#define PHSR_MC_MCONTROL_USERED             (14U)

#define PHSR_EMEM_LOWER_ADDRESS             (0xBF000000U)


#if(CHIP_ID == 29U)
#define PHSR_EMEM_UPPER_ADDRESS             (0xBF100000U)
#define PHL_SRAM_EMEM_LOWER_CONTROLLERS     (16U)
#define PHL_SRAM_EMEM_UPPER_CONTROLLERS     (16U)
#elif(CHIP_ID == 23U)
#define PHL_SRAM_EMEM_LOWER_CONTROLLERS     (4U)
#endif

#define PHL_SRAM_RANGE_UPLIMIT               (7U)
#define PHL_SRAM_RANGE_RAEN                  (0x8000U)
#define PHL_SRAM_MAX_WORDLINES               (64U)
#define PHL_SRAM_DEPTH_OFFSET                (8U)

#define MC_MCONTROL_USERED_MSK               (1U)
#define MC_MCONTROL_USERED                   (14U)

#define PHL_EMEM_ADDRESS_OFFSET              (0x10000U)
/*******************************************************************************
**                      Local Type Definitions                                **
*******************************************************************************/

/* Type definition PhlSramTst_BackupDataType -
 * This structure contains the backup values of SFRs, memory content and SMU
 * alarm action modified by the SramEccTst: */
typedef struct PhlSramTst_BackupDataType
{
  /* SMU alarm action backup for ECC error correction: */
  Smu_AlarmActionType   AlmActionBackupSbeCorr;
  /* SMU alarm action backup for uncorrectable ECC errors: */
  Smu_AlarmActionType   AlmActionBackupUcErr;
  /* SMU alarm action backup for address errors: */
  Smu_AlarmActionType   AlmActionBackupAdrErr;
  /* SMU alarm action backup for address buffer overflows: */
  Smu_AlarmActionType   AlmActionBackupAdrBufFull;

  /* Combined result of the alarm action backup operations: */
  Std_ReturnType        GetAlmActionResult;

  /* Storage for backup of memory controller enable status: */
  uint32                MemTest;

  /* Storage for memory content backup: */
  uint16                MemContentBackup[PHSR_MAX_RDBFL_REGS *
                                         PHSR_MAX_NR_OF_WORDLINES];
  boolean               MemBackupValid;

  /* Backup of the MTU clock gating: */
  uint8                 MtuClcDisr;

  /* Backup of clock settings: */
  uint32                ClockBackup;
  /* Backup of Mbist Enable Status: */
  boolean               MbistEnable;  

  /* Backup of MCx_ECCS: */
  uint16                Eccs;

  /* Backup of MCx_RANGE: */
  uint16                Range;
  /* CRC over previous members: */
  uint32                Crc;
} PhlSramTst_BackupDataType;


/*******************************************************************************
**                        Exported object definitions                          *
*******************************************************************************/


/*******************************************************************************
**                        Local object definitions                             *
*******************************************************************************/

#define IFX_PHL_SRAM_START_SEC_VAR_NONZERO_INIT_32BIT_ASIL_B
#include "Ifx_MemMap.h"

static PhlSramTst_UnexpAlarmType PhlSramTst_UnexpAlm =
{
  .Correctable = 0U,
  .Uncorrectable = 0U,
  .Address = 0U,
  .ErrTrkOvf = 0U,
  .Crc = 0U
};

#define IFX_PHL_SRAM_STOP_SEC_VAR_NONZERO_INIT_32BIT_ASIL_B
#include "Ifx_MemMap.h"


/*******************************************************************************
**                        Imported function declarations                       *
*******************************************************************************/
#define IFX_PHL_SRAM_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"

/*******************************************************************************
**                        Local function prototypes                            *
*******************************************************************************/

static Sl_TstRsltType PhlSramTst_lTestMemory
(
  const uint8 MemIdx,
  const Sl_ParamSetType ParamSetIndex,
  uint32* const TstSignature,
  PhlSramTst_BackupDataType* const BackupData
);

static Ifx_MC* PhlSramTst_lGetMc
(
  const uint8 MemIdx
);

static Sl_TstRsltType PhlSramTst_lInit
(
  const uint8 MemIdx,
  const Sl_ParamSetType ParamSetIndex,
  PhlSramTst_BackupDataType* const BackupData
);

static Sl_TstRsltType PhlSramTst_lInitSmuAlarms
(
  const uint8 MemIdx,
  PhlSramTst_BackupDataType* const BackupData
);

static Sl_TstRsltType PhlSramTst_lRestore
(
  const uint8 MemIdx,
  const Sl_ParamSetType ParamSetIndex,
  const PhlSramTst_BackupDataType* const BackupData
);

static Sl_TstRsltType PhlSramTst_lRestoreSmuAlarms
(
  const uint8 MemIdx,
  const PhlSramTst_BackupDataType* const BackupData
);

static Sl_TstRsltType PhlSramTst_lBackupSmuAlmActions
(
  const uint8 MemIdx,
  PhlSramTst_BackupDataType* const BackupData
);

static Sl_TstRsltType PhlSramTst_lCountClearUnexpAlm
(
  const uint8 MemIdx
);

static uint8 PhlSramTst_lCalcRdbflRegCount
(
  const uint8 MemIdx
);

static void PhlSramTst_lCreateZeroPattern
(
  const uint8 MemIdx
);

LOCAL_INLINE void PhlSramTst_lFlipBits
(
  const uint8 MemIdx,
  const uint8 WordIdx,
  const uint8 BitIdx,
  const uint8 BitCount
);

static Sl_TstRsltType PhlSramTst_lReadWordline
(
  const uint8 MemIdx,
  const uint16 WordlineIdx
);

static Sl_TstRsltType PhlSramTst_lWriteWordline
(
  const uint8 MemIdx,
  const uint16 WordlineIdx
);

static Sl_TstRsltType PhlSramTst_lCheckEccLogic
(
  const uint8 MemIdx,
  uint32* const TstSignature
);

static Sl_TstRsltType PhlSramTst_lChkAddressMon
(
  const uint8 MemIdx,
  uint32* const TstSignature
);

static Sl_TstRsltType PhlSramTst_lChkSmuSignaling
(
  const uint8 MemIdx,
  uint32* const TstSignature
);

static Sl_TstRsltType PhlSramTst_lChkSbeSignaling
(
  const uint8 MemIdx,
  uint32* const TstSignature,
  uint16* const WordlineIdx
);

static Sl_TstRsltType PhlSramTst_lChkDbeSignaling
(
  const uint8 MemIdx,
  uint32* const TstSignature,
  uint16* const WordlineIdx
);

static Sl_TstRsltType PhlSramTst_lChkSramMonEov
(
  const uint8 MemIdx,
  uint32* const TstSignature,
  const uint16 WordlineIdx
);

static Sl_TstRsltType PhlSramTst_lEnableMbist
(
  const uint8 MemIdx,
  PhlSramTst_BackupDataType* const BackupData
);

static Sl_TstRsltType PhlSramTst_lRestoreMbist
(
  const uint8 MemIdx,
  const PhlSramTst_BackupDataType* const BackupData
);

static Sl_TstRsltType PhlSramTst_lWaitForSmuAlarm
(
  const uint8 SmuGrp,
  const uint8 SmuAlarmNr,
  uint32* const TstSignature
);

static Sl_TstRsltType PhlSramTst_lBackupMemContent
(
  const uint8 MemIdx,
  PhlSramTst_BackupDataType* const BackupData
);

static Sl_TstRsltType PhlSramTst_lRestoreMemContent
(
  const uint8 MemIdx,
  const Sl_ParamSetType ParamSetIndex,  
  const PhlSramTst_BackupDataType* const BackupData
);

static Sl_TstRsltType PhlSramTst_lEnableMtuClock
(
  PhlSramTst_BackupDataType* const BackupData
);

static Sl_TstRsltType PhlSramTst_lRestoreMtuClock
(
  const PhlSramTst_BackupDataType* const BackupData
);

static Sl_TstRsltType PhlSramTst_lEnableSramClock
(
  const uint8 MemIdx,
  PhlSramTst_BackupDataType* const BackupData
);

static Sl_TstRsltType PhlSramTst_lRestoreSramClock
(
  const uint8 MemIdx,
  const PhlSramTst_BackupDataType* const BackupData
);

LOCAL_INLINE uint32 PhlSramTst_lCalcAlmCounterCrc
(
  void
);

static uint32 PhlSramTst_lCalcBackupCrc
(
  const PhlSramTst_BackupDataType* const BackupData
);

static Sl_TstRsltType PhlSramTst_lClearSram
(
  const uint8 MemIdx,
  const uint16 Range,
  const uint16 Delay
);


/*******************************************************************************
**                    Local in-line function definitions                       *
*******************************************************************************/


/*******************************************************************************
**                    Configuration error checking                             *
*******************************************************************************/


/*******************************************************************************
**                         Function definitions                                *
*******************************************************************************/



/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : Sl_TstRsltType PhlSramTst_lTestMemory                   **
**                    (                                                       **
**                      const uint8 MemIdx,                                   **
**                      const Sl_ParamSetType ParamSetIndex,                  **
**                      uint32* const TstSignature,                           **
**                      PhlSramTst_BackupDataType* const BackupData           **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : MemIdx - Index of the memory under test; Refer to       **
**                             definition of supported SRAMs in               **
**                             PhlSramTst_MemDef.h for a list of supported    **
**                             values                                         **
**                    ParamSetIndex - config Parameter index                  **
**                                                                            **
** Parameters (out) : TstSignature - Test signature generated by the test     **
**                    BackupData - Pointer to backup data struct of the       **
**                                 Peripheral SRAM test                       **
**                                                                            **
** Return value     : PHLSRAM_SUCCESS - Memory test succeeded                 **
**                    <Error ID> - Type of error during memory test           **
**                                                                            **
** Description      : This function performs the Peripheral SRAM test for a   **
**                    single memory. It also takes care about initialization, **
**                    memory content backup and restoration of the memory.    **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType PhlSramTst_lTestMemory
(
  const uint8 MemIdx,
  const Sl_ParamSetType ParamSetIndex,
  uint32* const TstSignature,
  PhlSramTst_BackupDataType* const BackupData
)
{
  Sl_TstRsltType  Result = PHLSRAM_NOTEXECUTED;
  Sl_TstRsltType  ResultTmp;

  /* Initialize the test: */
  ResultTmp = PhlSramTst_lInit(MemIdx, ParamSetIndex, BackupData);
  if (PHLSRAM_SUCCESS != ResultTmp)
  {
    Result = ResultTmp;
  } /* if (PHLSRAM_SUCCESS != ResultTmp) */
  else
  {
    ResultTmp = PhlSramTst_lCheckEccLogic(MemIdx, TstSignature);
    if (PHLSRAM_SUCCESS != ResultTmp)
    {
      Result = ResultTmp;
    } /* if (PHLSRAM_SUCCESS != ResultTmp) */
  } /* if (PHLSRAM_SUCCESS == ResultTmp) */

  /* Restore settings changed by the test: */
  ResultTmp = PhlSramTst_lRestore(MemIdx, ParamSetIndex,
                                  BackupData);
  if (PHLSRAM_SUCCESS != ResultTmp)
  {
    Result = ResultTmp;
  } /* if (PHLSRAM_SUCCESS != ResultTmp) */

  if (PHLSRAM_NOTEXECUTED == Result)
  {
    Result = PHLSRAM_SUCCESS;
  } /* if (PHLSRAM_NOTEXECUTED == Result) */

  return Result;
} /* PhlSramTst_lTestMemory */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : Ifx_MC* PhlSramTst_lGetMc                               **
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
** Parameters(in)   : MemIdx - Index of the memory under test; Refer to       **
**                             definition of Peripheral SRAMs in              **
**                             PhlSramTst_MemDef.h for a list of supported    **
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
static Ifx_MC* PhlSramTst_lGetMc
(
  const uint8 MemIdx
)
{
  uint8   McIdx;
  Ifx_MC* Result;

  McIdx = PhlSramTst_kMcTable[MemIdx];
  Result = (Ifx_MC*)((uint32)&MODULE_MC0 +
                     ((uint32)PHSR_MC_ADDR_RANGE_SIZE * (uint32)McIdx));

  return Result;
} /* PhlSramTst_lGetMc */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : Sl_TstRsltType PhlSramTst_lInit                         **
**                    (                                                       **
**                      const uint8 MemIdx,                                   **
**                      const Sl_ParamSetType ParamSetIndex,                  **
**                      PhlSramTst_BackupDataType* const BackupData           **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : MemIdx - Index of the memory under test; Refer to       **
**                             definition of Peripheral SRAMs in              **
**                             PhlSramTst_MemDef.h for a list of supported    **
**                             values                                         **
**                    ParamSetIndex - config Parameter index                  **
**                    BackupData - Pointer to backup data struct of the       **
**                                 Peripheral SRAM test                       **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : PHLSRAM_SUCCESS - Initialization succeeded              **
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
static Sl_TstRsltType PhlSramTst_lInit
(
  const uint8 MemIdx,
  const Sl_ParamSetType ParamSetIndex,
  PhlSramTst_BackupDataType* const BackupData
)
{
  Sl_TstRsltType  Result = PHLSRAM_NOTEXECUTED;
  Sl_TstRsltType  ResultTmp;
  Ifx_MC*         Mc;

  #if((CHIP_ID == 29U)||(CHIP_ID == 23U))  
  volatile uint32 dummy = 0U;  
  uint32          AddressOffset = 0U;
  UNUSED_PARAMETER(dummy)  
  #endif


  /* Invalidate backup values: */
  BackupData->Eccs = (uint16)PHSR_INV_BACKUP_VALUE;
  BackupData->MemBackupValid = (boolean)FALSE;
  BackupData->MbistEnable = (boolean)FALSE;
  BackupData->MemTest = PHSR_INV_BACKUP_VALUE;
  BackupData->ClockBackup = PHSR_INV_BACKUP_VALUE;

  /* Note: There is no invalid value for BackupData->Range, since all values
   * 0x0000 to 0xFFFF are valid. Therefore BackupData->Eccs is used as valid
   * indicator for BackupData->Range. BackupData->Range is only initialized
   * to PHSR_INV_BACKUP_VALUE to have a defined initial value:
   */
  BackupData->Range = (uint16)PHSR_INV_BACKUP_VALUE;
  /* Check PhlSramTst_kMcTable for valid MC index: */
  if (PHLSRAMTST_MC_IDX_INVALID == PhlSramTst_kMcTable[MemIdx])
  {
    Result = PHLSRAM_CONSISTENCYERR;
  } /* if (PHLSRAMTST_MC_IDX_INVALID == PhlSramTst_kMcTable[MemIdx]) */
  else
  {
    /* Get pointer to memory controller SFRs of RAM under test: */
    Mc = PhlSramTst_lGetMc(MemIdx);

    ResultTmp = PhlSramTst_lInitSmuAlarms(MemIdx, BackupData);
    if (PHLSRAM_SUCCESS != ResultTmp)
    {
      Result = ResultTmp;
    } /* if (PHLSRAM_SUCCESS != ResultTmp)*/
    else
    {
      /* Enable SRAM clock: */
      ResultTmp = PhlSramTst_lEnableSramClock(MemIdx, BackupData);
      if (PHLSRAM_SUCCESS != ResultTmp)
      {
        Result = ResultTmp;
      } /* if (PHLSRAM_SUCCESS != ResultTmp) */
      else
      {
        /* Enter MBIST test mode: */
        /* Dummy access to EMEM SRAM  */
        #if((CHIP_ID == 29U)||(CHIP_ID == 23U))
        if((MemIdx >=PHL_SRAM_EMEM_LOWER0)&&(MemIdx <=PHL_SRAM_EMEM_LOWER15))
        {
          AddressOffset = PHSR_EMEM_LOWER_ADDRESS +(((uint32)MemIdx - (uint32)PHL_SRAM_EMEM_LOWER0) * (uint32)PHL_EMEM_ADDRESS_OFFSET);
          dummy = *((uint32*)(AddressOffset));

        }
        #endif
        #if(CHIP_ID == 29U)
        if((MemIdx >=PHL_SRAM_EMEM_UPPER0)&&(MemIdx <=PHL_SRAM_EMEM_UPPER15))
        {
          AddressOffset = PHSR_EMEM_UPPER_ADDRESS +(((uint32)MemIdx - (uint32)PHL_SRAM_EMEM_UPPER0) * (uint32)PHL_EMEM_ADDRESS_OFFSET);          
          dummy = *((uint32*)(AddressOffset));  
        }
        #endif

        ResultTmp = PhlSramTst_lEnableMbist(MemIdx, BackupData);
        if (PHLSRAM_SUCCESS != ResultTmp)
        {
          Result = ResultTmp;
        } /* if (PHLSRAM_SUCCESS != ResultTmp) */
        else
        {
          /* Backup MCx_ECCS: */
          BackupData->Eccs = Mc->ECCS.U;
            /* Backup MCx_RANGE: */
            BackupData->Range = Mc->RANGE.U;
          /* Check whether error correction is enabled: */
          if ((PHLSRAMTST_SMU_NONE != PhlSramTst_kMemDef[MemIdx]->SmuNr_SbeCorr)
              && ((BackupData->Eccs & (uint16)((uint32)IFX_MC_ECCS_ECE_MSK <<
                                     (uint32)IFX_MC_ECCS_ECE_OFF)) == 0U))
          {
            Result = PHLSRAM_MEM_ECECFG;
          } /* if ((PHLSRAMTST_SMU_NONE !=
                    PhlSramTst_kMemDef[MemIdx]->SmuNr_SbeCorr) &&
                   ((BackupData->Eccs & (uint16)((uint32)IFX_MC_ECCS_ECE_MSK <<
                                        (uint32)IFX_MC_ECCS_ECE_OFF)) == 0U)) */
          else if ((boolean)FALSE == PhlSramTst_ConfigRoot[ParamSetIndex].ClearMemory)
          {
            /* Backup memory used by the test: */
        
            Result = PhlSramTst_lBackupMemContent(MemIdx,
                                                  BackupData);

          } 
          else
          {
		    BackupData->MemBackupValid = (boolean)TRUE;
			Result = PHLSRAM_SUCCESS;
          }	/* if ((PHLSRAMTST_SMU_NONE ==
                    PhlSramTst_kMemDef[MemIdx]->SmuNr_SbeCorr) ||
                   ((BackupData->Eccs & (uint16)((uint32)IFX_MC_ECCS_ECE_MSK <<
                                        (uint32)IFX_MC_ECCS_ECE_OFF)) != 0U)) */	  
        } /* if (PHLSRAM_SUCCESS == ResultTmp) */
      } /* if (PHLSRAM_SUCCESS != ResultTmp) */
    } /* if (PHLSRAM_SUCCESS != ResultTmp) */
  } /* if (PHLSRAMTST_MC_IDX_INVALID == PhlSramTst_kMcTable[MemIdx]) */
 
  /* Calculate backup data crc: */
  BackupData->Crc = PhlSramTst_lCalcBackupCrc(BackupData);

  return Result;
} /* PhlSramTst_lInit */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : Sl_TstRsltType PhlSramTst_lInitSmuAlarms                **
**                    (                                                       **
**                      const uint8 MemIdx,                                   **
**                      PhlSramTst_BackupDataType* const BackupData           **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : MemIdx - Index of the memory under test; Refer to       **
**                             definition of Peripheral SRAMs in              **
**                             PhlSramTst_MemDef.h for a list of supported    **
**                             values                                         **
**                    BackupData - Pointer to backup data struct of the       **
**                                 Peripheral SRAM test                       **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : PHLSRAM_SUCCESS - SMU alarm initialization succeeded    **
**                    <Error ID> - Type of error during SNU alarm             **
**                                 initialization                             **
**                                                                            **
** Description      : This function backs up the alarm action of all SMU      **
**                    alarms used by the test, checks their initial alarm     **
**                    status and sets the alarm action to 'No action'.        **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType PhlSramTst_lInitSmuAlarms
(
  const uint8 MemIdx,
  PhlSramTst_BackupDataType* const BackupData
)
{
  Sl_TstRsltType  Result = PHLSRAM_NOTEXECUTED;
  Sl_TstRsltType  ResultTmp;
  Std_ReturnType  SmuResult1;
  Std_ReturnType  SmuResult2;
  Std_ReturnType  SmuResult3;
  Std_ReturnType  SmuResult4;

  /* Backup SMU alarm actions: */
  ResultTmp = PhlSramTst_lBackupSmuAlmActions(MemIdx, BackupData);
  if (PHLSRAM_SUCCESS != ResultTmp)
  {
    Result = ResultTmp;
  } /* if (PHLSRAM_SUCCESS != ResultTmp) */
  else
  {
    /* Check that none of the SMU alarms used by the test is already set: */
    ResultTmp = PhlSramTst_lCountClearUnexpAlm(MemIdx);
    if (PHLSRAM_SUCCESS != ResultTmp)
    {
      Result = ResultTmp;
    } /* if (PHLSRAM_SUCCESS != ResultTmp) */
    else
    {
      /* Set alarm actions of all SMU alarms used by the test to no action: */
      if (PHLSRAMTST_SMU_NONE == PhlSramTst_kMemDef[MemIdx]->SmuNr_SbeCorr)
      {
        SmuResult1 = E_OK;
      } /* if (PHLSRAMTST_SMU_NONE ==
               PhlSramTst_kMemDef[MemIdx]->SmuNr_SbeCorr) */
      else
      {
        SmuResult1 = Smu_SetAlarmAction
            (PhlSramTst_kMemDef[MemIdx]->SmuAlarmGrp,
             PhlSramTst_kMemDef[MemIdx]->SmuNr_SbeCorr,
             SMU_ALARM_ACTION_NONE
            );
      } /* if (PHLSRAMTST_SMU_NONE !=
               PhlSramTst_kMemDef[MemIdx]->SmuNr_SbeCorr) */
      SmuResult2 = Smu_SetAlarmAction
          (PhlSramTst_kMemDef[MemIdx]->SmuAlarmGrp,
           PhlSramTst_kMemDef[MemIdx]->SmuNr_UcErr,
           SMU_ALARM_ACTION_NONE
          );
      if(PhlSramTst_kMemDef[MemIdx]->SmuNr_AdrErr != PHLSRAMTST_SMU_NONE)
      {
        SmuResult3 = Smu_SetAlarmAction
            (PhlSramTst_kMemDef[MemIdx]->SmuAlarmGrp,
             PhlSramTst_kMemDef[MemIdx]->SmuNr_AdrErr,
             SMU_ALARM_ACTION_NONE
            );
      }
      else
      {
        SmuResult3 = E_OK;
      }
      SmuResult4 = Smu_SetAlarmAction
          (PhlSramTst_kMemDef[MemIdx]->SmuAlarmGrp,
           PhlSramTst_kMemDef[MemIdx]->SmuNr_AdrBufFull,
           SMU_ALARM_ACTION_NONE
          );

      if ((E_OK != SmuResult1) || (E_OK != SmuResult2) ||
          (E_OK != SmuResult3) || (E_OK != SmuResult4))
      {
        Result = PHLSRAM_SMU_SETALMACTIONERR;
      } /* if ((E_OK != SmuResult1) || (E_OK != SmuResult2) ||
               (E_OK != SmuResult3) || (E_OK != SmuResult4)) */
      else
      {
        Result = PHLSRAM_SUCCESS;
      } /* if ((E_OK == SmuResult1) && (E_OK == SmuResult2) &&
               (E_OK == SmuResult3) && (E_OK == SmuResult4)) */
    } /* if (PHLSRAM_SUCCESS == ResultTmp) */
  } /* if (PHLSRAM_SUCCESS == ResultTmp) */

  return Result;
} /* PhlSramTst_lInitSmuAlarms */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : Sl_TstRsltType PhlSramTst_lRestore                      **
**                    (                                                       **
**                      const uint8 MemIdx,                                   **
**                      const Sl_ParamSetType ParamSetIndex,                  **
**                      const PhlSramTst_BackupDataType* const BackupData     **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : MemIdx - Index of the memory under test; Refer to       **
**                             definition of Peripheral SRAMs in              **
**                             PhlSramTst_MemDef.h for a list of supported    **
**                             values                                         **
**                    ParamSetIndex - config Parameter index                  **
**                    BackupData - Pointer to backup data struct of the       **
**                                 Peripheral SRAM test                       **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : PHLSRAM_SUCCESS - Test restoration succeeded            **
**                    <Error ID> - Type of error during test restoration      **
**                                                                            **
** Description      : This function restores all SFRs, SMU alarm actions and  **
**                    memory content that has been modified by the test.      **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType PhlSramTst_lRestore
(
  const uint8 MemIdx,
  const Sl_ParamSetType ParamSetIndex,
  const PhlSramTst_BackupDataType* const BackupData
)

{
  Sl_TstRsltType            Result = PHLSRAM_NOTEXECUTED;
  Sl_TstRsltType            ResultTmp;
  Ifx_MC*                   Mc;
  uint8                     Count, RdbflRegCount;  
  
  /* Check backup data crc: */
  if (PhlSramTst_lCalcBackupCrc(BackupData) != BackupData->Crc)
  {
    Result = PHLSRAM_DATACORRUPTION;
  } /* if (PhlSramTst_lCalcBackupCrc(BackupData) != BackupData->Crc) */
  else
  {
    /* Get pointer to memory controller SFRs of RAM under test: */
    Mc = PhlSramTst_lGetMc(MemIdx);

    /* Backup succeeded? */
    if (E_OK == BackupData->GetAlmActionResult)
    {
      /* Restore memory content overwritten by the test: */
      ResultTmp = PhlSramTst_lRestoreMemContent(MemIdx,ParamSetIndex,
                                                BackupData);
      if(BackupData->MbistEnable == (boolean)TRUE)
      {
        RdbflRegCount = PhlSramTst_lCalcRdbflRegCount(MemIdx);

        for (Count= 0U;Count < RdbflRegCount; Count++)
        {
          Mc->RDBFL[Count].U = (uint16)0U;
        }        
      }

      if (PHLSRAM_SUCCESS != ResultTmp)
      {
        Result = ResultTmp;
      } /* if (PHLSRAM_SUCCESS != ResultTmp) */

      /* Restore MCx_ECCS if its backup value is valid: */
      if (0xFFFFU != BackupData->Eccs)
      {
        Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);
        Mc->ECCS.U = BackupData->Eccs;

        /* Restore MCx_RANGE; if BackupData->Eccs is valid, then BackupData->
         * Range is always valid, too:
         */
        Mc->RANGE.U = BackupData->Range;
        Mcal_SetSafetyENDINIT_Timed();
      } /* if (0xFFFFU != BackupData->Eccs) */

      /* Leave MBIST test mode: */
      ResultTmp = PhlSramTst_lRestoreMbist(MemIdx, BackupData);
      if (PHLSRAM_SUCCESS != ResultTmp)
      {
        Result = ResultTmp;
      } /* if (PHLSRAM_SUCCESS != ResultTmp) */

      /* Restore SRAM clock: */
      ResultTmp = PhlSramTst_lRestoreSramClock(MemIdx, BackupData);
      if (PHLSRAM_SUCCESS != ResultTmp)
      {
        Result = ResultTmp;
      }

      /* Restore SMU alarm actions: */
      ResultTmp = PhlSramTst_lRestoreSmuAlarms(MemIdx, BackupData);
      if (PHLSRAM_SUCCESS != ResultTmp)
      {
        Result = ResultTmp;
      } /* if (PHLSRAM_SUCCESS != ResultTmp) */

      /* Update result:: */
      if (PHLSRAM_NOTEXECUTED == Result)
      {
        Result = PHLSRAM_SUCCESS;
      } /* if (PHLSRAM_NOTEXECUTED == Result) */
    } /* if (E_OK == BackupData->GetAlmActionResult) */
    else
    {
      /* No backup data available, nothing to do: */
      Result = PHLSRAM_SUCCESS;
    } /* if (E_OK != BackupData->GetAlmActionResult) */

    if(MemIdx == PHL_SRAM_SADMA)
    {
	  Mcal_ResetENDINIT();
	  DMA_MEMCON.U&= ~(unsigned_int)((unsigned_int)IFX_DMA_MEMCON_INTERR_MSK << (unsigned_int)IFX_DMA_MEMCON_INTERR_OFF);
	  Mcal_SetENDINIT();
    }
  } /* if (PhlSramTst_lCalcBackupCrc(BackupData) == BackupData->Crc) */

  return Result;
} /* PhlSramTst_lRestore */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : Sl_TstRsltType PhlSramTst_lRestoreSmuAlarms             **
**                    (                                                       **
**                      const uint8 MemIdx,                                   **
**                      const PhlSramTst_BackupDataType* const BackupData     **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : MemIdx - Index of the memory under test; Refer to       **
**                             definition of Peripheral SRAMs in              **
**                             PhlSramTst_MemDef.h for a list of supported    **
**                             values                                         **
**                    BackupData - Pointer to backup data struct of the       **
**                                 Peripheral SRAM test                       **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : PHLSRAM_SUCCESS - SMU alarm restoration succeeded       **
**                    <Error ID> - Type of error during SMU alarm restoration **
**                                                                            **
** Description      : This function restores all SMU alarm actions that have  **
**                    been modified by the test.                              **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType PhlSramTst_lRestoreSmuAlarms
(
  const uint8 MemIdx,
  const PhlSramTst_BackupDataType* const BackupData
)
{
  Sl_TstRsltType            Result = PHLSRAM_NOTEXECUTED;
  Std_ReturnType            SmuResult1;
  Std_ReturnType            SmuResult2;
  Std_ReturnType            SmuResult3;
  Std_ReturnType            SmuResult4;

  /* Restore SMU alarm actions: */
  if (PHLSRAMTST_SMU_NONE == PhlSramTst_kMemDef[MemIdx]->SmuNr_SbeCorr)
  {
    /* No correctable error SMU alarm for DED codes: */
    SmuResult1 = E_OK;
  } /* if (PHLSRAMTST_SMU_NONE ==
           PhlSramTst_kMemDef[MemIdx]->SmuNr_SbeCorr) */
  else
  {
    SmuResult1 = Smu_SetAlarmAction
        (PhlSramTst_kMemDef[MemIdx]->SmuAlarmGrp,
         PhlSramTst_kMemDef[MemIdx]->SmuNr_SbeCorr,
         BackupData->AlmActionBackupSbeCorr
        );
  } /* if (PHLSRAMTST_SMU_NONE !=
           PhlSramTst_kMemDef[MemIdx]->SmuNr_SbeCorr) */
  SmuResult2 = Smu_SetAlarmAction
      (PhlSramTst_kMemDef[MemIdx]->SmuAlarmGrp,
       PhlSramTst_kMemDef[MemIdx]->SmuNr_UcErr,
       BackupData->AlmActionBackupUcErr
      );
  if(PhlSramTst_kMemDef[MemIdx]->SmuNr_AdrErr != PHLSRAMTST_SMU_NONE)
  {
    SmuResult3 = Smu_SetAlarmAction
        (PhlSramTst_kMemDef[MemIdx]->SmuAlarmGrp,
         PhlSramTst_kMemDef[MemIdx]->SmuNr_AdrErr,
         BackupData->AlmActionBackupAdrErr
        );
  }
  else
  {
    SmuResult3 = E_OK;
  }
  SmuResult4 = Smu_SetAlarmAction
      (PhlSramTst_kMemDef[MemIdx]->SmuAlarmGrp,
       PhlSramTst_kMemDef[MemIdx]->SmuNr_AdrBufFull,
       BackupData->AlmActionBackupAdrBufFull
      );

  if ((E_OK != SmuResult1) || (E_OK != SmuResult2) ||
      (E_OK != SmuResult3) || (E_OK != SmuResult4))
  {
    Result = PHLSRAM_SMU_SETALMACTIONERR;
  } /* if ((E_OK != SmuResult1) || (E_OK != SmuResult2) ||
           (E_OK != SmuResult3) || (E_OK != SmuResult4)) */
  else
  {
    Result = PHLSRAM_SUCCESS;
  } /* if ((E_OK == SmuResult1) && (E_OK == SmuResult2) &&
           (E_OK == SmuResult3) && (E_OK == SmuResult4)) */

  return Result;
} /* PhlSramTst_lRestoreSmuAlarms */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : Sl_TstRsltType PhlSramTst_lBackupSmuAlmActions          **
**                    (                                                       **
**                      const uint8 MemIdx,                                   **
**                      PhlSramTst_BackupDataType* const BackupData           **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : MemIdx - Index of the memory under test; Refer to       **
**                             definition of Peripheral SRAMs in              **
**                             PhlSramTst_MemDef.h for a list of supported    **
**                             values                                         **
**                    BackupData - Pointer to backup data struct of the       **
**                                 Peripheral SRAM test                       **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : PHLSRAM_SUCCESS - SMU alarm action backup succeeded     **
**                    <Error ID> - Type of error during backup                **
**                                                                            **
** Description      : This function takes backup copy of SMU alarm actions    **
**                    of all SMU alarms triggered by the test.                **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType PhlSramTst_lBackupSmuAlmActions
(
  const uint8 MemIdx,
  PhlSramTst_BackupDataType* const BackupData
)
{
  Sl_TstRsltType  Result = PHLSRAM_NOTEXECUTED;
  Std_ReturnType  SmuResult1;
  Std_ReturnType  SmuResult2;
  Std_ReturnType  SmuResult3;
  Std_ReturnType  SmuResult4;

  /*The value of the FSP action backup will be irrelevant as
   * SMU FSP is not activated during SafeTlib Pre-run phase.
   */
  Smu_FSPActionType SmuAlarmFspAction = 0U;

  /* Backup SMU alarm actions: */
  if (PHLSRAMTST_SMU_NONE == PhlSramTst_kMemDef[MemIdx]->SmuNr_SbeCorr)
  {
    /* For DED codes there is no correctable error SMU alarm */
    SmuResult1 = E_OK;
  } /* if (PHLSRAMTST_SMU_NONE == PhlSramTst_kMemDef[MemIdx]->SmuNr_SbeCorr) */
  else
  {
    SmuResult1 = Smu_GetAlarmAction
        (PhlSramTst_kMemDef[MemIdx]->SmuAlarmGrp,
         PhlSramTst_kMemDef[MemIdx]->SmuNr_SbeCorr,
         &BackupData->AlmActionBackupSbeCorr,
         &SmuAlarmFspAction
        );
  } /* if (PHLSRAMTST_SMU_NONE != PhlSramTst_kMemDef[MemIdx]->SmuNr_SbeCorr) */
  SmuResult2 = Smu_GetAlarmAction
      (PhlSramTst_kMemDef[MemIdx]->SmuAlarmGrp,
       PhlSramTst_kMemDef[MemIdx]->SmuNr_UcErr,
       &BackupData->AlmActionBackupUcErr,
       &SmuAlarmFspAction
      );
  if(PhlSramTst_kMemDef[MemIdx]->SmuNr_AdrErr != PHLSRAMTST_SMU_NONE)
  {
    SmuResult3 = Smu_GetAlarmAction
        (PhlSramTst_kMemDef[MemIdx]->SmuAlarmGrp,
         PhlSramTst_kMemDef[MemIdx]->SmuNr_AdrErr,
         &BackupData->AlmActionBackupAdrErr,
         &SmuAlarmFspAction
        );
  }
  else
  {
    SmuResult3 = E_OK;
  }
  SmuResult4 = Smu_GetAlarmAction
      (PhlSramTst_kMemDef[MemIdx]->SmuAlarmGrp,
       PhlSramTst_kMemDef[MemIdx]->SmuNr_AdrBufFull,
       &BackupData->AlmActionBackupAdrBufFull,
       &SmuAlarmFspAction);

  /* Check if SMU alarm action backup was successful: */
  if ((E_OK != SmuResult1) || (E_OK != SmuResult2) ||
      (E_OK != SmuResult3) || (E_OK != SmuResult4))

  {
    BackupData->GetAlmActionResult = E_NOT_OK;
    Result = PHLSRAM_SMU_GETALMACTIONERR;
  } /* if ((E_OK != SmuResult1) || (E_OK != SmuResult2) ||
           (E_OK != SmuResult3) || (E_OK != SmuResult4)) */
  else
  {
    BackupData->GetAlmActionResult = E_OK;
    Result = PHLSRAM_SUCCESS;
  } /* if ((E_OK == SmuResult1) && (E_OK == SmuResult2) &&
           (E_OK == SmuResult3) && (E_OK == SmuResult4)) */

  return Result;
} /* PhlSramTst_lBackupSmuAlmActions */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : Sl_TstRsltType PhlSramTst_lCountClearUnexpAlm           **
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
** Parameters(in)   : MemIdx - Index of the memory under test; Refer to       **
**                             definition of Peripheral SRAMs in              **
**                             PhlSramTst_MemDef.h for a list of supported    **
**                             values                                         **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : PHLSRAM_SUCCESS - Clearing of unexpected alarms         **
**                                      succeeded                             **
**                    <Error ID> - Type of error during alarm clearing        **
**                                                                            **
** Description      : This function counts all unexpected SRAM ECC SMU alarms **
**                    to PhlSramTst_UnexpAlm structure and clears all set     **
**                    alarms.                                                 **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType PhlSramTst_lCountClearUnexpAlm
(
  const uint8 MemIdx
)
{
  Sl_TstRsltType  Result = PHLSRAM_NOTEXECUTED;
  Std_ReturnType  SmuResult;
  Std_ReturnType  SmuResult1 = E_NOT_OK;
  Std_ReturnType  SmuResult2 = E_NOT_OK;
  Std_ReturnType  SmuResult3 = E_NOT_OK;
  Std_ReturnType  SmuResult4 = E_NOT_OK;
  uint32          AlarmStatus;

  /* Check alarm counter CRC value: */
  if (PhlSramTst_UnexpAlm.Crc != PhlSramTst_lCalcAlmCounterCrc())
  {
    Result = PHLSRAM_DATACORRUPTION;
  } /* if (PhlSramTst_UnexpAlm.Crc != PhlSramTst_lCalcAlmCounterCrc()) */
  else
  {
    /* Check that none of the SMU alarms used by the test is already set: */
    SmuResult = Smu_GetAlarmStatus
        (PhlSramTst_kMemDef[MemIdx]->SmuAlarmGrp,
         &AlarmStatus
        );
    if (E_OK != SmuResult)
    {
      Result = PHLSRAM_SMU_GETALMSTSERR;
    } /* if (E_OK != SmuResult) */
    else
    {
      /* Check if correctable ECC error SMU alarm already set: */
      if ((PHLSRAMTST_SMU_NONE != PhlSramTst_kMemDef[MemIdx]->SmuNr_SbeCorr) &&
          ((AlarmStatus &
            ((uint32)1U << PhlSramTst_kMemDef[MemIdx]->SmuNr_SbeCorr)) > 0U))
      {
        PhlSramTst_UnexpAlm.Correctable++;
        SmuResult1 = Smu_ClearAlarmStatus
            (PhlSramTst_kMemDef[MemIdx]->SmuAlarmGrp,
             PhlSramTst_kMemDef[MemIdx]->SmuNr_SbeCorr);
      } /* if ((PHLSRAMTST_SMU_NONE !=
                PhlSramTst_kMemDef[MemIdx]->SmuNr_SbeCorr)
               && (AlarmStatus & ((uint32)1U <<
                   PhlSramTst_kMemDef[MemIdx]->SmuNr_SbeCorr)) > 0U) */
      else
      {
        SmuResult1 = E_OK;
      } /* if ((PHLSRAMTST_SMU_NONE ==
                PhlSramTst_kMemDef[MemIdx]->SmuNr_SbeCorr)
               || (AlarmStatus & ((uint32)1U <<
                   PhlSramTst_kMemDef[MemIdx]->SmuNr_SbeCorr)) == 0U) */

      /* Check if uncorrectable ECC error SMU alarm already set: */
      if ((AlarmStatus &
           ((uint32)1U << PhlSramTst_kMemDef[MemIdx]->SmuNr_UcErr)) > 0U)
      {
        PhlSramTst_UnexpAlm.Uncorrectable++;
        SmuResult2 = Smu_ClearAlarmStatus
            (PhlSramTst_kMemDef[MemIdx]->SmuAlarmGrp,
             PhlSramTst_kMemDef[MemIdx]->SmuNr_UcErr);
      } /* if ((AlarmStatus &
               ((uint32)1U << PhlSramTst_kMemDef[MemIdx]->SmuNr_UcErr)) > 0U) */
      else
      {
        SmuResult2 = E_OK;
      } /* if ((AlarmStatus &
              ((uint32)1U << PhlSramTst_kMemDef[MemIdx]->SmuNr_UcErr)) == 0U) */

      /* Check if address error SMU alarm already set: */
      if ((PHLSRAMTST_SMU_NONE != PhlSramTst_kMemDef[MemIdx]->SmuNr_AdrErr) &&
          ((AlarmStatus &
            ((uint32)1U << PhlSramTst_kMemDef[MemIdx]->SmuNr_AdrErr)) > 0U))              
      {
        PhlSramTst_UnexpAlm.Address++;
        SmuResult3 = Smu_ClearAlarmStatus
            (PhlSramTst_kMemDef[MemIdx]->SmuAlarmGrp,
             PhlSramTst_kMemDef[MemIdx]->SmuNr_AdrErr);
      } /* if ((AlarmStatus &
              ((uint32)1U << PhlSramTst_kMemDef[MemIdx]->SmuNr_AdrErr)) > 0U) */
      else
      {
        SmuResult3 = E_OK;
      } /* if ((AlarmStatus &
             ((uint32)1U << PhlSramTst_kMemDef[MemIdx]->SmuNr_AdrErr)) == 0U) */

      /* Check if error tracking overflow SMU alarm already set: */
      if ((AlarmStatus &
           ((uint32)1U << PhlSramTst_kMemDef[MemIdx]->SmuNr_AdrBufFull)) > 0U)
      {
        PhlSramTst_UnexpAlm.ErrTrkOvf++;
        SmuResult4 = Smu_ClearAlarmStatus
            (PhlSramTst_kMemDef[MemIdx]->SmuAlarmGrp,
             PhlSramTst_kMemDef[MemIdx]->SmuNr_AdrBufFull);
      } /* if ((AlarmStatus &
          ((uint32)1U << PhlSramTst_kMemDef[MemIdx]->SmuNr_AdrBufFull)) > 0U) */
      else
      {
        SmuResult4 = E_OK;
      } /* if ((AlarmStatus &
         ((uint32)1U << PhlSramTst_kMemDef[MemIdx]->SmuNr_AdrBufFull)) == 0U) */

      if ((E_OK != SmuResult1) || (E_OK != SmuResult2) ||
          (E_OK != SmuResult3) || (E_OK != SmuResult4))
      {
        Result = PHLSRAM_SMU_CLRALMSTSERR;
      } /* if ((E_OK != SmuResult1) || (E_OK != SmuResult2) ||
               (E_OK != SmuResult3) || (E_OK != SmuResult4)) */
      else
      {
        Result = PHLSRAM_SUCCESS;
      } /* if ((E_OK == SmuResult1) && (E_OK == SmuResult2) &&
               (E_OK == SmuResult3) && (E_OK == SmuResult4)) */
    } /* if (E_OK == SmuResult) */

    /* Update unexpected alarm counter CRC: */
    PhlSramTst_UnexpAlm.Crc = PhlSramTst_lCalcAlmCounterCrc();
  } /* if (PhlSramTst_UnexpAlm.Crc != PhlSramTst_lCalcAlmCounterCrc()) */

  return Result;
} /* PhlSramTst_lCountClearUnexpAlm */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : uint8 PhlSramTst_lCalcRdbflRegCount                     **
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
** Parameters(in)   : MemIdx - Memory for which to create the pattern; Refer  **
**                             to definition of Peripheral SRAMs in           **
**                             PhlSramTst_MemDef.h for a list of supported    **
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
static uint8 PhlSramTst_lCalcRdbflRegCount
(
  const uint8 MemIdx
)
{
  uint16 Result;

  Result = ((uint16)PhlSramTst_kMemDef[MemIdx]->NrOfDataBits +
            (uint16)PhlSramTst_kMemDef[MemIdx]->NrOfEccBits) *
           ((uint16)PhlSramTst_kMemDef[MemIdx]->NrOfMemBlocks *
            (uint16)PhlSramTst_kMemDef[MemIdx]->NrOfMultiplexers);
  Result += (PHSR_RDBFL_REG_WIDTH - 1U);  /* Round up */
  Result /= PHSR_RDBFL_REG_WIDTH;

  return (uint8)Result;
} /* PhlSramTst_lCalcRdbflRegCount */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : void PhlSramTst_lCreateZeroPattern                      **
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
** Parameters(in)   : MemIdx - Memory for which to create the pattern; Refer  **
**                             to definition of Peripheral SRAMs in           **
**                             PhlSramTst_MemDef.h for a list of supported    **
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
static void PhlSramTst_lCreateZeroPattern
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
  RdbflRegCount = PhlSramTst_lCalcRdbflRegCount(MemIdx);

  /* Get pointer to memory controller SFRs of RAM under test: */
  Mc = PhlSramTst_lGetMc(MemIdx);

  /* Initialize MCx_RDBFLy registers to zero: */
  for (i = 0U; i < RdbflRegCount; i++)
  {
    Mc->RDBFL[i].U = (uint16)0U;
  } /* for (i = 0U; i < RdbflRegCount; i++) */

  /* Create check bits for each data word: */
  for (i = 0U; i < (PhlSramTst_kMemDef[MemIdx]->NrOfMemBlocks *
                    PhlSramTst_kMemDef[MemIdx]->NrOfMultiplexers); i++)
  {
    /* Get absolute bit index of first ECC bit: */
    BitIdx = ((uint16)PhlSramTst_kMemDef[MemIdx]->NrOfDataBits +
              (uint16)PhlSramTst_kMemDef[MemIdx]->NrOfEccBits) * (uint16)i;
    BitIdx += (uint16)PhlSramTst_kMemDef[MemIdx]->NrOfDataBits;
    BitIdx += (uint16)PhlSramTst_kMemDef[MemIdx]->EccInvPos0;

    /* Get RDBFL register */
    RdbflRegIdx = (uint8)(BitIdx / PHSR_RDBFL_REG_WIDTH);
    /* Get bit index. Modulo operation done through & operation */
    RdbflBitIdx = (uint8)(BitIdx & ((uint16)PHSR_RDBFL_REG_WIDTH - (uint16)1U));

    /* Set first ECC bit: */
    Mc->RDBFL[RdbflRegIdx].U |= (uint16)((uint32)1U << RdbflBitIdx);

    /* Get second register and bit index: */
    BitIdx -= (uint16)PhlSramTst_kMemDef[MemIdx]->EccInvPos0;
    BitIdx += (uint16)PhlSramTst_kMemDef[MemIdx]->EccInvPos1;
    RdbflRegIdx = (uint8)(BitIdx / PHSR_RDBFL_REG_WIDTH);
    RdbflBitIdx = (uint8)(BitIdx & ((uint16)PHSR_RDBFL_REG_WIDTH - (uint16)1U));

    /* Set second ECC bit: */
    Mc->RDBFL[RdbflRegIdx].U |= (uint16)((uint32)1U << RdbflBitIdx);
  } /* for (i = 0U; i < PhlSramTst_kMemDef[MemIdx]->NrOfMemBlocks *
                        PhlSramTst_kMemDef[MemIdx]->NrOfMultiplexers; i++) */
} /* PhlSramTst_lCreateZeroPattern */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : void PhlSramTst_lFlipBits                               **
**                    (                                                       **
**                      const uint8 MemIdx,                                   **
**                      const uint8 WordIdx,                                  **
**                      const uint8 BitIdx,                                   **
**                      const uint8 BitCount                                  **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : MemIdx - Memory for which to flip bits; Refer to        **
**                             definition of Peripheral SRAMs in              **
**                             PhlSramTst_MemDef.h for a list of supported    **
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
LOCAL_INLINE void PhlSramTst_lFlipBits
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
  Mc = PhlSramTst_lGetMc(MemIdx);

  /* Get the absolute bit index of the first bit of the selected data word: */
  AbsBitIdx = ((uint16)PhlSramTst_kMemDef[MemIdx]->NrOfDataBits +
               (uint16)PhlSramTst_kMemDef[MemIdx]->NrOfEccBits) *
              (uint16)WordIdx;
  AbsBitIdx += BitIdx;

  /* Get RDBFL register */
  RdbflRegIdx = (uint8)(AbsBitIdx / (uint16)PHSR_RDBFL_REG_WIDTH);
  /* Get bit index. Modulo operation done through & operation */
  RdbflBitIdx = (AbsBitIdx & ((uint16)PHSR_RDBFL_REG_WIDTH - (uint16)1U));

  /* Flip bits: */
  for (i = 0U; i < BitCount; i++)
  {
    Mc->RDBFL[RdbflRegIdx].U ^= (uint16)((uint32)1U << RdbflBitIdx);
    RdbflBitIdx++;
    if (RdbflBitIdx == PHSR_RDBFL_REG_WIDTH)
    {
      RdbflRegIdx++;
      RdbflBitIdx = 0U;
    } /* if (RdbflBitIdx == PHSR_RDBFL_REG_WIDTH) */
  } /* for (i = 0U; i < BitCount; i++) */
} /* PhlSramTst_lFlipBits */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : Sl_TstRsltType PhlSramTst_lReadWordline                 **
**                    (                                                       **
**                      const uint8 MemIdx,                                   **
**                      const uint16 WordlineIdx                              **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : MemIdx - Memory from which to read; Refer to            **
**                             definition of Peripheral SRAMs in              **
**                             PhlSramTst_MemDef.h for a list of supported    **
**                             values                                         **
**                    WordlineIdx - Memory address to read                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : PHLSRAM_SUCCESS - Reading wordline succeeded            **
**                    PHLSRAM_MBIST_RWOPTIMEOUT - Reading wordline timed out  **
**                                                                            **
** Description      : Reads a single memory location to RDBFL registers       **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType PhlSramTst_lReadWordline
(
  const uint8 MemIdx,
  const uint16 WordlineIdx
)
{
  Ifx_MC*         Mc;
  Sl_TstRsltType  Result = PHLSRAM_NOTEXECUTED;

  /* Get pointer to memory controller SFRs of RAM under test: */
  Mc = PhlSramTst_lGetMc(MemIdx);

  /* Select address */
  Mc->RANGE.U = (WordlineIdx & (uint16)IFX_MC_RANGE_ADDR_MSK);

  /* Configure reading of single memory address: */
  Mc->CONFIG0.U = (uint16)(((uint32)PHSR_CONFIG0_NUMACCS_1 <<
                            IFX_MC_CONFIG0_NUMACCS_OFF) |
                           ((uint32)PHSR_CONFIG0_ACCSTYPE_RD <<
                            IFX_MC_CONFIG0_ACCSTYPE_OFF));
  Mc->CONFIG1.U = 0U;

  /* Start read operation: */
  Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);
  Mc->MCONTROL.U = (uint16)(((uint32)IFX_MC_MCONTROL_DIR_MSK <<
                             (uint32)IFX_MC_MCONTROL_DIR_OFF) |
                            ((uint32)IFX_MC_MCONTROL_START_MSK <<
                             (uint32)IFX_MC_MCONTROL_START_OFF)|
                            ((uint32)MC_MCONTROL_USERED_MSK <<
                             (uint32)MC_MCONTROL_USERED));

  /* MSTATUS.DONE = 0 indicates, that the read operation was successfully
   * started:
   */
  if (((Mc->MSTATUS.U)  & (uint16)(((uint32)IFX_MC_MSTATUS_DONE_MSK <<
                                (uint32)IFX_MC_MSTATUS_DONE_OFF))) > (uint16)0U)
  {
    Result = PHLSRAM_MBIST_RWOPFAIL;
  } /* if ((Mc->MSTATUS.U & (uint16)(((uint32)IFX_MC_MSTATUS_DONE_MSK <<
                             (uint32)IFX_MC_MSTATUS_DONE_OFF))) > (uint16)0U) */

  /* Revoke MSTATUS.START: */
  Mc->MCONTROL.U = (uint16)(((uint32)IFX_MC_MCONTROL_DIR_MSK <<
                            (uint32)IFX_MC_MCONTROL_DIR_OFF)|
                            ((uint32)MC_MCONTROL_USERED_MSK <<
                             (uint32)MC_MCONTROL_USERED));

  Mcal_SetSafetyENDINIT_Timed();
  /* Check if read operation completed: */
  if (((Mc->MSTATUS.U)  & (uint16)(((uint32)IFX_MC_MSTATUS_DONE_MSK <<
                               (uint32)IFX_MC_MSTATUS_DONE_OFF))) == (uint16)0U)
  {
    Result = PHLSRAM_MBIST_RWOPTIMEOUT;
  } /* if ((Mc->MSTATUS.U & (uint16)(((uint32)IFX_MC_MSTATUS_DONE_MSK <<
                            (uint32)IFX_MC_MSTATUS_DONE_OFF))) == (uint16)0U) */
  else
  {
    if (PHLSRAM_NOTEXECUTED == Result)
    {
      Result = PHLSRAM_SUCCESS;
    } /* if (PHLSRAM_NOTEXECUTED == Result) */
  } /* if ((MSTATUS.U & (uint16)(((uint32)IFX_MC_MSTATUS_DONE_MSK <<
                            (uint32)IFX_MC_MSTATUS_DONE_OFF))) != (uint16)0U) */
  return Result;
} /* PhlSramTst_lReadWordline */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : Sl_TstRsltType PhlSramTst_lWriteWordline                **
**                    (                                                       **
**                      const uint8 MemIdx,                                   **
**                      const uint16 WordlineIdx                              **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : MemIdx - Memory to which to write; Refer to             **
**                             definition of Peripheral SRAMs in              **
**                             PhlSramTst_MemDef.h for a list of supported    **
**                             values                                         **
**                    WordlineIdx - Memory address to write                   **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : PHLSRAM_SUCCESS - Writing wordline succeeded            **
**                    PHLSRAM_MBIST_RWOPTIMEOUT - Writing wordline timed out  **
**                                                                            **
** Description      : Writes the RDBFL registers to a single memory location  **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType PhlSramTst_lWriteWordline
(
  const uint8 MemIdx,
  const uint16 WordlineIdx
)
{
  Ifx_MC*         Mc;
  Sl_TstRsltType  Result = PHLSRAM_NOTEXECUTED;

  /* Get pointer to memory controller SFRs of RAM under test: */
  Mc = PhlSramTst_lGetMc(MemIdx);

  /* Select address */
  Mc->RANGE.U = (WordlineIdx & (uint16)IFX_MC_RANGE_ADDR_MSK);

  /* Configure writing of single memory address: */
  Mc->CONFIG0.U = (uint16)(((uint32)PHSR_CONFIG0_NUMACCS_1 <<
                            IFX_MC_CONFIG0_NUMACCS_OFF) |
                           ((uint32)PHSR_CONFIG0_ACCSTYPE_WR <<
                            IFX_MC_CONFIG0_ACCSTYPE_OFF));
  Mc->CONFIG1.U = 0U;

  /* Start write operation: */
  Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);

  Mc->MCONTROL.U = (uint16)(((uint32)IFX_MC_MCONTROL_DIR_MSK <<
                             (uint32)IFX_MC_MCONTROL_DIR_OFF) |
                            ((uint32)IFX_MC_MCONTROL_START_MSK <<
                             (uint32)IFX_MC_MCONTROL_START_OFF)|
                             ((uint32)MC_MCONTROL_USERED_MSK <<
                             (uint32)MC_MCONTROL_USERED));
  
  /* MSTATUS.DONE = 0 indicates, that the read operation was successfully
   * started:
   */
  if (((Mc->MSTATUS.U)  & (uint16)(((uint32)IFX_MC_MSTATUS_DONE_MSK <<
                                (uint32)IFX_MC_MSTATUS_DONE_OFF))) > (uint16)0U)
  {
    Result = PHLSRAM_MBIST_RWOPFAIL;
  } /* if ((Mc->MSTATUS.U & (uint16)(((uint32)IFX_MC_MSTATUS_DONE_MSK <<
                             (uint32)IFX_MC_MSTATUS_DONE_OFF))) > (uint16)0U) */

  /* Revoke MSTATUS.START: */
  Mc->MCONTROL.U = (uint16)(((uint32)IFX_MC_MCONTROL_DIR_MSK <<
                            (uint32)IFX_MC_MCONTROL_DIR_OFF)|
                            ((uint32)MC_MCONTROL_USERED_MSK <<
                             (uint32)MC_MCONTROL_USERED));

  Mcal_SetSafetyENDINIT_Timed();

  /* Check if write operation completed: */
  if (((Mc->MSTATUS.U)  & (uint16)(((uint32)IFX_MC_MSTATUS_DONE_MSK <<
                               (uint32)IFX_MC_MSTATUS_DONE_OFF))) == (uint16)0U)
  {
    Result = PHLSRAM_MBIST_RWOPTIMEOUT;
  } /* if ((Mc->MSTATUS.U & (uint16)(((uint32)IFX_MC_MSTATUS_DONE_MSK <<
                            (uint32)IFX_MC_MSTATUS_DONE_OFF))) == (uint16)0U) */
  else
  {
    if (PHLSRAM_NOTEXECUTED == Result)
    {
      Result = PHLSRAM_SUCCESS;
    } /* if (PHLSRAM_NOTEXECUTED == Result) */
  } /* if ((MSTATUS.U & (uint16)(((uint32)IFX_MC_MSTATUS_DONE_MSK <<
                            (uint32)IFX_MC_MSTATUS_DONE_OFF))) != (uint16)0U) */
  return Result;
} /* PhlSramTst_lWriteWordline */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : Sl_TstRsltType PhlSramTst_lCheckEccLogic                **
**                    (                                                       **
**                      const uint8 MemIdx,                                   **
**                      uint32* const TstSignature                            **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : MemIdx - Index of the memory under test; Refer to       **
**                             definition of Peripheral SRAMs in              **
**                             PhlSramTst_MemDef.h for a list of supported    **
**                             values                                         **
**                                                                            **
** Parameters (out) : TstSignature - Will receive the updated program flow    **
**                                   monitoring signature                     **
**                                                                            **
** Return value     : PHLSRAM_SUCCESS - Peripheral SRAM test succeeded        **
**                    <Error ID> - Type of error during Peripheral SRAM test  **
**                                                                            **
** Description      : This function tests the correct signaling of ECC errors **
**                    to the SMU. The following error scenarios are checked:  **
**                      -Signaling of single bit errors                       **
**                      -Signaling of double bit errors                       **
**                      -Signaling of address line errors                     **
**                      -Signaling of address monitor buffer overflow         **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType PhlSramTst_lCheckEccLogic
(
  const uint8 MemIdx,
  uint32* const TstSignature
)
{ 
  Sl_TstRsltType  Result = PHLSRAM_NOTEXECUTED;
  Sl_TstRsltType  ResultTmp;
  Std_ReturnType  SmuResult1;
  Std_ReturnType  SmuResult2;
  Ifx_MC*         Mc;

  /* Get pointer to memory controller SFRs of RAM under test: */
  Mc = PhlSramTst_lGetMc(MemIdx);

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
  if (PHLSRAMTST_SMU_NONE != PhlSramTst_kMemDef[MemIdx]->SmuNr_SbeCorr)
  {
    SmuResult1 = Smu_ClearAlarmStatus(
                    PhlSramTst_kMemDef[MemIdx]->SmuAlarmGrp,
                    PhlSramTst_kMemDef[MemIdx]->SmuNr_SbeCorr);
  } /* if (PHLSRAMTST_SMU_NONE != PhlSramTst_kMemDef[MemIdx]->SmuNr_SbeCorr) */
  else
  {
    SmuResult1 = E_OK;
  } /* if (PHLSRAMTST_SMU_NONE == PhlSramTst_kMemDef[MemIdx]->SmuNr_SbeCorr) */
  SmuResult2 = Smu_ClearAlarmStatus(
                  PhlSramTst_kMemDef[MemIdx]->SmuAlarmGrp,
                  PhlSramTst_kMemDef[MemIdx]->SmuNr_UcErr);
  if ((E_OK != SmuResult1) || (E_OK != SmuResult2))
  {
    Result = PHLSRAM_SMU_CLRALMSTSERR;
  } /* if ((E_OK != SmuResult1) || (E_OK != SmuResult2)) */
  else
  {
    if(PhlSramTst_kMemDef[MemIdx]->SmuNr_AdrErr != PHLSRAMTST_SMU_NONE)
    {
      /* Check signaling of address line errors to the SMU: */
      ResultTmp = PhlSramTst_lChkAddressMon(MemIdx,
                                            TstSignature);
    }
    else
    {
      ResultTmp = PHLSRAM_SUCCESS;
    }
    if (PHLSRAM_SUCCESS != ResultTmp)
    {
      Result = ResultTmp;
    } /* if (PHLSRAM_SUCCESS != ResultTmp) */
    else
    {
      /* Check the SRAM monitor: */
      Result = PhlSramTst_lChkSmuSignaling(MemIdx, TstSignature);
    } /* if (PHLSRAM_SUCCESS == ResultTmp) */
  } /* if ((E_OK == SmuResult1) && (E_OK == SmuResult2)) */

  return Result;
} /* PhlSramTst_lCheckEccLogic */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : Sl_TstRsltType PhlSramTst_lChkAddressMon                **
**                    (                                                       **
**                      const uint8 MemIdx,                                   **
**                      uint32* const TstSignature                            **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : MemIdx - Index of the memory under test; Refer to       **
**                             definition of Peripheral SRAMs in              **
**                             PhlSramTst_MemDef.h for a list of supported    **
**                             values                                         **
**                                                                            **
** Parameters (out) : TstSignature : Test signature generated by the test     **
**                                                                            **
** Return value     : PHLSRAM_SUCCESS - Address line ECC error signaling test **
**                                      succeeded                             **
**                    <Error ID> - Type of error during address line test     **
**                                                                            **
** Description      : This function tests the correct signaling of address    **
**                    line ECC errors to the SMU.                             **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType PhlSramTst_lChkAddressMon
(
    const uint8 MemIdx,
    uint32* const TstSignature
)
{
  Sl_TstRsltType  Result = PHLSRAM_NOTEXECUTED;
  Sl_TstRsltType  ResultTmp;
  Ifx_MC*         Mc;

  /* Get pointer to memory controller SFRs of RAM under test: */
  Mc = PhlSramTst_lGetMc(MemIdx);

  /* Write valid data to the first wordline to avoid correctable and
   * uncorrectable errors during the address error test:
   */
  PhlSramTst_lCreateZeroPattern(MemIdx);
  ResultTmp = PhlSramTst_lWriteWordline(MemIdx, 0U);
  if (PHLSRAM_SUCCESS != ResultTmp)
  {
    Result = ResultTmp;
  } /* if (PHLSRAM_SUCCESS != ResultTmp) */
  else
  {
    /* Set bitline signature bit flip enable: */
    Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);
    Mc->ECCS.U &= ~(uint16)((uint32)IFX_MC_ECCS_SFLE_MSK <<
                            (uint32)IFX_MC_ECCS_SFLE_OFF);
    Mc->ECCS.U |= (uint16)((uint32)1U << IFX_MC_ECCS_SFLE_OFF);
    Mcal_SetSafetyENDINIT_Timed();

    /* Read memory: */
    ResultTmp = PhlSramTst_lReadWordline(MemIdx, 0U);
    if (PHLSRAM_SUCCESS != ResultTmp)
    {
      Result = ResultTmp;
    } /* if (PHLSRAM_SUCCESS != ResultTmp) */
    else
    {
      /* Wait for and clear SMU alarm: */
      Result = PhlSramTst_lWaitForSmuAlarm(
          PhlSramTst_kMemDef[MemIdx]->SmuAlarmGrp,
          PhlSramTst_kMemDef[MemIdx]->SmuNr_AdrErr,
          TstSignature);
    } /* if (PHLSRAM_SUCCESS == ResultTmp) */
    /* Reset signature bit flip enable: */
    Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);
    Mc->ECCS.U &= ~(uint16)((uint32)IFX_MC_ECCS_SFLE_MSK <<
                            (uint32)IFX_MC_ECCS_SFLE_OFF);
    Mcal_SetSafetyENDINIT_Timed();

    /* Clear error flags: */
    Mc->ECCD.U &= ~(uint16)(((uint32)IFX_MC_ECCD_SERR_MSK <<
                             (uint32)IFX_MC_ECCD_SERR_OFF) |
                            ((uint32)IFX_MC_ECCD_AERR_MSK <<
                             (uint32)IFX_MC_ECCD_AERR_OFF));
  } /* if (PHLSRAM_SUCCESS == ResultTmp) */

  return Result;
} /* PhlSramTst_lChkAddressMon */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : Sl_TstRsltType PhlSramTst_lChkSmuSignaling              **
**                    (                                                       **
**                      const uint8 MemIdx,                                   **
**                      uint32* const TstSignature                            **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : MemIdx - Index of the memory under test; Refer to       **
**                             definition of Peripheral SRAMs in              **
**                             PhlSramTst_MemDef.h for a list of supported    **
**                             values                                         **
**                                                                            **
** Parameters (out) : TstSignature : Test signature generated by the test     **
**                                                                            **
** Return value     : PHRSRAM_SUCCESS - SMU signaling test succeeded          **
**                    <Error ID> - Type of error during SMU signaling test    **
**                                                                            **
** Description      : This function tests that correctable ECC errors,        **
**                    uncorrectable ECC errors and an overflow of the error   **
**                    tracking registers is correctly signaled to the SMU.    **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType PhlSramTst_lChkSmuSignaling
(
  const uint8 MemIdx,
  uint32* const TstSignature
)
{
  Sl_TstRsltType            Result = PHLSRAM_NOTEXECUTED;
  Sl_TstRsltType            ResultTmp;
  uint16                    WordlineIdx;
  Ifx_MC*                   Mc;

  /* Get pointer to memory controller SFRs of RAM under test: */
  Mc = PhlSramTst_lGetMc(MemIdx);
  PhlSramTst_lCreateZeroPattern(MemIdx);
  /* Initialize wordline index: */
  WordlineIdx = PhlSramTst_kMemDef[MemIdx]->NrOfEtrRegisters;

  /* Clear error tracking information: */
  Mc->ECCD.U |= (uint16)((uint32)IFX_MC_ECCD_TRC_MSK <<
                         (uint32)IFX_MC_ECCD_TRC_OFF);

  /* Enable error tracking: */
  Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);
  Mc->ECCS.U |= (uint16)((uint32)IFX_MC_ECCS_TRE_MSK <<
                         (uint32)IFX_MC_ECCS_TRE_OFF);
  Mcal_SetSafetyENDINIT_Timed();

  /* Skip correctable error signaling test for DED ECC codes: */
  if (PHLSRAMTST_SMU_NONE == PhlSramTst_kMemDef[MemIdx]->SmuNr_SbeCorr)
  {
    ResultTmp = PHLSRAM_SUCCESS;
  } /* if (PHLSRAMTST_SMU_NONE == PhlSramTst_kMemDef[MemIdx]->SmuNr_SbeCorr) */
  else
  {
    /* Check that single bit errors are correctly reported to the SMU: */
    ResultTmp = PhlSramTst_lChkSbeSignaling(MemIdx,
                                            TstSignature,
                                            &WordlineIdx);
  } /* if (PHLSRAMTST_SMU_NONE != PhlSramTst_kMemDef[MemIdx]->SmuNr_SbeCorr) */

  if (PHLSRAM_SUCCESS != ResultTmp)
  {
    Result = ResultTmp;
  } /* if (PHLSRAM_SUCCESS != ResultTmp) */
  else
  {
    /* Check that double bit errors correctly reported to the SMU and fill all
     * error tracking entries:
     */
    ResultTmp = PhlSramTst_lChkDbeSignaling(MemIdx,
                                            TstSignature,
                                            &WordlineIdx);
    if (PHLSRAM_SUCCESS != ResultTmp)
    {
      Result = ResultTmp;
    } /* if (PHLSRAM_SUCCESS != ResultTmp) */
    else
    {
      /* Check reporting of error tracking overflow to the SMU: */
      Result = PhlSramTst_lChkSramMonEov(MemIdx,
                                         TstSignature,
                                         WordlineIdx);
    } /* if (PHLSRAM_SUCCESS == ResultTmp) */
  } /* if (PHLSRAM_SUCCESS == ResultTmp) */

  /* Clear ECCD error flags: */
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
} /* PhlSramTst_lChkSmuSignaling */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : Sl_TstRsltType PhlSramTst_lChkSbeSignaling              **
**                    (                                                       **
**                      const uint8 MemIdx,                                   **
**                      uint32* const TstSignature,                           **
**                      uint16* const WordlineIdx                             **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : MemIdx - Index of the memory under test; Refer to       **
**                             definition of Peripheral SRAMs in              **
**                             PhlSramTst_MemDef.h for a list of supported    **
**                             values                                         **
**                                                                            **
** Parameters (out) : TstSignature : Test signature generated by the test     **
**                    WordlineIdx : In & out paramater, contains the current  **
**                                  wordline to be used for correctable error **
**                                  test and will be set to wordline that is  **
**                                  to be used for the next test              **
**                                                                            **
** Return value     : PHLSRAM_SUCCESS - SBE signaling test succeeded          **
**                    <Error ID> - Type of error during SBE signaling test    **
**                                                                            **
** Description      : This function tests that correctable ECC errors are     **
**                    correctly reported to the SMU.                          **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType PhlSramTst_lChkSbeSignaling
(
  const uint8 MemIdx,
  uint32* const TstSignature,
  uint16* const WordlineIdx
)
{
  Sl_TstRsltType  Result = PHLSRAM_NOTEXECUTED;
  Sl_TstRsltType  ResultTmp;
  uint16          WordlineIdxBackup = *WordlineIdx;
  Ifx_MC*         Mc;

  /* Get pointer to memory controller SFRs of RAM under test: */
  Mc = PhlSramTst_lGetMc(MemIdx);

  /* Inject single bit error pattern: */
  PhlSramTst_lFlipBits(MemIdx, 0U, 0U, 1U);
  ResultTmp = PhlSramTst_lWriteWordline(MemIdx, *WordlineIdx);
  
  if (PHLSRAM_SUCCESS != ResultTmp)
  {
    Result = ResultTmp;
  } /* if (PHLSRAM_SUCCESS != ResultTmp) */
  else
  {
    /* Read memory back: */
    ResultTmp = PhlSramTst_lReadWordline(MemIdx, *WordlineIdx);
    if (PHLSRAM_SUCCESS != ResultTmp)
    {
      Result = ResultTmp;
    } /* if (PHLSRAM_SUCCESS != ResultTmp) */
    else
    {
      /* Clear error flags: */
      Mc->ECCD.U &= ~(uint16)(((uint32)IFX_MC_ECCD_SERR_MSK <<
                               (uint32)IFX_MC_ECCD_SERR_OFF) |
                              ((uint32)IFX_MC_ECCD_CERR_MSK <<
                               (uint32)IFX_MC_ECCD_CERR_OFF));

      if (PhlSramTst_kMemDef[MemIdx]->NrOfEtrRegisters > 1U)
      {
        (*WordlineIdx)--;
      } /* if (PhlSramTst_kMemDef[MemIdx]->NrOfEtrRegisters > 1U) */
      else
      {
        /* Clear error tracking information: */
        Mc->ECCD.U |= (uint16)((uint32)IFX_MC_ECCD_TRC_MSK <<
                               (uint32)IFX_MC_ECCD_TRC_OFF);
      } /* if (PhlSramTst_kMemDef[MemIdx]->NrOfEtrRegisters <= 1U) */

      /* Revoke single bit error: */
      PhlSramTst_lFlipBits(MemIdx, 0U, 0U, 1U);
      ResultTmp = PhlSramTst_lWriteWordline(MemIdx, WordlineIdxBackup);
      if (PHLSRAM_SUCCESS != ResultTmp)
      {
        Result = ResultTmp;
      } /* if (PHLSRAM_SUCCESS != ResultTmp) */
      else
      {
        /* Check if correctable error SMU alarm was raised: */
        Result = PhlSramTst_lWaitForSmuAlarm(
            PhlSramTst_kMemDef[MemIdx]->SmuAlarmGrp,
            PhlSramTst_kMemDef[MemIdx]->SmuNr_SbeCorr,
            TstSignature);
      } /* if (PHLSRAM_SUCCESS == ResultTmp) */
    } /* if (PHLSRAM_SUCCESS == ResultTmp) */
  } /* if (PHLSRAM_SUCCESS == ResultTmp) */

  return Result;
} /* PhlSramTst_lChkSbeSignaling */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : Sl_TstRsltType PhlSramTst_lChkDbeSignaling              **
**                    (                                                       **
**                      const uint8 MemIdx,                                   **
**                      uint32* const TstSignature,                           **
**                      uint16* const WordlineIdx                             **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : MemIdx - Index of the memory under test; Refer to       **
**                             definition of Peripheral SRAMs in              **
**                             PhlSramTst_MemDef.h for a list of supported    **
**                             values                                         **
**                                                                            **
** Parameters (out) : TstSignature : Test signature generated by the test     **
**                    WordlineIdx : In & out paramater, contains the current  **
**                                  wordline to be used for uncorrectable     **
**                                  error test and will be set to wordline    **
**                                  that is to be used for the next test      **
**                                                                            **
** Return value     : PHLSRAM_SUCCESS - DBE signaling test succeeded          **
**                    <Error ID> - Type of error during DBE signaling test    **
**                                                                            **
** Description      : This function tests that uncorrectable ECC errors are   **
**                    correctly reported to the SMU and fills all error       **
**                    tracking entries as preparation for the following       **
**                    overflow test.                                          **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType PhlSramTst_lChkDbeSignaling
(
  const uint8 MemIdx,
  uint32* const TstSignature,
  uint16* const WordlineIdx
)
{
  Sl_TstRsltType  Result = PHLSRAM_NOTEXECUTED;
  Sl_TstRsltType  ResultTmp;

   /* Fill all error tracking registers with uncorrectable errors: */
  while (((*WordlineIdx) > 0U) && (PHLSRAM_NOTEXECUTED == Result))
  {
    /* Inject double bit error pattern: */
    PhlSramTst_lFlipBits(MemIdx, 0U, 0U, 2U);
    ResultTmp = PhlSramTst_lWriteWordline(MemIdx, *WordlineIdx);
    if (PHLSRAM_SUCCESS != ResultTmp)
    {
      Result = ResultTmp;
    } /* if (PHLSRAM_SUCCESS != ResultTmp) */
    else
    {
      /* Read memory back: */
      ResultTmp = PhlSramTst_lReadWordline(MemIdx, *WordlineIdx);
      if (PHLSRAM_SUCCESS != ResultTmp)
      {
        Result = ResultTmp;
      } /* if (PHLSRAM_SUCCESS != ResultTmp) */

      /* Revoke double bit error by flipping the same bits again: */
      PhlSramTst_lFlipBits(MemIdx, 0U, 0U, 2U);
      ResultTmp = PhlSramTst_lWriteWordline(MemIdx, *WordlineIdx);
      if (PHLSRAM_SUCCESS != ResultTmp)
      {
        Result = ResultTmp;
      } /* if (PHLSRAM_SUCCESS != ResultTmp) */
    } /* if (PHLSRAM_SUCCESS == ResultTmp) */

    /* Go on to next wordline: */
    (*WordlineIdx)--;
  } /* while (((*WordlineIdx) > 0U) && (PHLSRAM_NOTEXECUTED == Result)) */

  /* Check for previous error: */
  if (PHLSRAM_NOTEXECUTED == Result)
  {
    /* Check if uncorrectable error SMU alarm was raised: */
    Result = PhlSramTst_lWaitForSmuAlarm(
        PhlSramTst_kMemDef[MemIdx]->SmuAlarmGrp,
        PhlSramTst_kMemDef[MemIdx]->SmuNr_UcErr,
        TstSignature);
  } /* if (PHLSRAM_NOTEXECUTED == Result) */

  return Result;
} /* PhlSramTst_lChkDbeSignaling */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : Sl_TstRsltType PhlSramTst_lChkSramMonEov                **
**                    (                                                       **
**                      const uint8 MemIdx,                                   **
**                      uint32* const TstSignature,                           **
**                      uint16* const WordlineIdx                             **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : MemIdx - Index of the memory under test; Refer to       **
**                             definition of Peripheral SRAMs in              **
**                             PhlSramTst_MemDef.h for a list of supported    **
**                             values                                         **
**                    WordlineIdx - contains the current wordline to be used  **
**                                  for the error tracking overflow test      **
**                                                                            **
** Parameters (out) : TstSignature - Test signature generated by the test     **
**                                                                            **
** Return value     : PHLSRAM_SUCCESS - SRAM monitor EOV test succeeded       **
**                    <Error ID> - Type of error during SRAM monitor EOV test **
**                                                                            **
** Description      : This function tests that an overflow of the error       **
**                    tracking registers is correctly signaled to the SMU.    **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType PhlSramTst_lChkSramMonEov
(
  const uint8 MemIdx,
  uint32* const TstSignature,
  const uint16 WordlineIdx
)
{
  Sl_TstRsltType  Result = PHLSRAM_NOTEXECUTED;
  Sl_TstRsltType  ResultTmp;

  /* Generate another error to provoke an error tracking overflow: */
  PhlSramTst_lFlipBits(MemIdx, 0U, 0U, 2U);
  ResultTmp = PhlSramTst_lWriteWordline(MemIdx, WordlineIdx);
  if (PHLSRAM_SUCCESS != ResultTmp)
  {
    Result = ResultTmp;
  } /* if (PHLSRAM_SUCCESS != ResultTmp) */
  else
  {
    /* Read memory back: */
    ResultTmp = PhlSramTst_lReadWordline(MemIdx, WordlineIdx);
    if (PHLSRAM_SUCCESS != ResultTmp)
    {
      Result = ResultTmp;
    } /* if (PHLSRAM_SUCCESS != ResultTmp) */
    else
    {
      /* Wait for error tracking overflow SMU alarm: */
      ResultTmp = PhlSramTst_lWaitForSmuAlarm(
          PhlSramTst_kMemDef[MemIdx]->SmuAlarmGrp,
          PhlSramTst_kMemDef[MemIdx]->SmuNr_AdrBufFull,
          TstSignature);
      if (PHLSRAM_SUCCESS != ResultTmp)
      {
        Result = ResultTmp;
      } /* if (PHLSRAM_SUCCESS != ResultTmp) */
    } /* if (PHLSRAM_SUCCESS == ResultTmp) */

    /* Revoke bit error by flipping the same bit again: */
    PhlSramTst_lFlipBits(MemIdx, 0U, 0U, 2U);
    ResultTmp = PhlSramTst_lWriteWordline(MemIdx, WordlineIdx);
    if (PHLSRAM_SUCCESS != ResultTmp)
    {
      Result = ResultTmp;
    } /* if (PHLSRAM_SUCCESS != ResultTmp) */

    /* Clear uncorrectable ECC error SMU alarm: */
    if (E_OK != Smu_ClearAlarmStatus(
                  PhlSramTst_kMemDef[MemIdx]->SmuAlarmGrp,
                  PhlSramTst_kMemDef[MemIdx]->SmuNr_UcErr))
    {
      Result = PHLSRAM_SMU_CLRALMSTSERR;
    } /* if (E_OK != PhlSramTst_lSmuClearAlarmStatus(
                       PhlSramTst_kMemDef[MemIdx]->SmuAlarmGrp,
                       PhlSramTst_kMemDef[MemIdx]->SmuNr_UcErr)) */
    if(MemIdx == PHL_SRAM_SADMA)
    {
      if(E_OK != Smu_ClearAlarmStatus(SMU_ALARM_GROUP2,SMU_ALARM_24))
      {
        Result = PHLSRAM_SMU_CLRALMSTSERR;
      }/*(E_OK != Smu_ClearAlarmStatus(SMU_ALARM_GROUP0,SMU_ALARM_24))*/
    }
  } /* if (PHLSRAM_SUCCESS == ResultTmp) */

  /* Update test result: */
  if (PHLSRAM_NOTEXECUTED == Result)
  {
    Result = PHLSRAM_SUCCESS;
  } /* if (PHLSRAM_NOTEXECUTED == Result) */

  return Result;
} /* PhlSramTst_lChkSramMonEov */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : Sl_TstRsltType PhlSramTst_lEnableMbist                  **
**                    (                                                       **
**                      const uint8 MemIdx,                                   **
**                      PhlSramTst_BackupDataType* const BackupData           **
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
**                             Peripheral SRAMs in PhlSramTst_MemDef.h for a  **
**                             list of supported values                       **
**                                                                            **
** Parameters (out) : BackupData - Pointer to backup data structure that will **
**                                 will receive previous MBIST enable status  **
**                                                                            **
** Return value     : PHLSRAM_SUCCESS - Enabling MBIST succeeded              **
**                    <Error ID> - Type of error while enabling MBIST         **
**                                                                            **
** Description      : This function enables the MBIST memory test mode of a   **
**                    given memory.                                           **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType PhlSramTst_lEnableMbist
(
  const uint8 MemIdx,
  PhlSramTst_BackupDataType* const BackupData
)
{
  Sl_TstRsltType            Result = PHLSRAM_NOTEXECUTED;
  volatile uint32*          MemTestPtr;
  uint32                    BitMask;
  uint8                     McIdx;

  /* Get memory controller index: */
  McIdx = PhlSramTst_kMcTable[MemIdx];

  /* Get pointer to MTU_MEMTESTx and MTU_MEMSTATx SFR and store bit mask: */
  if (McIdx < 32U)
  {
    MemTestPtr = (volatile uint32*)(volatile void *)&MTU_MEMTEST0.U;
    BitMask = (uint32)((uint32)1U << McIdx);
  } /* if (McIdx < 32U) */
  else if (McIdx < 64U)
  {
    MemTestPtr = (volatile uint32*)(volatile void *)&MTU_MEMTEST1.U;
    BitMask = (uint32)((uint32)1U << (McIdx - 32U));
  } /* if (McIdx < 64U) */
  else if (McIdx < PHLSRAMTST_MBIST_CONTROLLER_COUNT)
  {
    MemTestPtr = (volatile uint32*)(volatile void *)&MTU_MEMTEST2.U;
    BitMask = (uint32)((uint32)1U << (McIdx - 64U));
  } /* if (McIdx < PHLSRAMTST_MBIST_CONTROLLER_COUNT) */
  else
  {
    Result = PHLSRAM_INVPARAMERR;

    /* Required to avoid compiler warning: */
    MemTestPtr = 0U;
    BitMask = 0U;
  } /* if (McIdx >= PHLSRAMTST_MBIST_CONTROLLER_COUNT) */

  if (PHLSRAM_NOTEXECUTED == Result)
  {
    /* Store MBIST enable status: */
    BackupData->MemTest = *MemTestPtr & BitMask;

    /* Enable MBIST controller of RAM under test: */
    Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);
    *MemTestPtr |= BitMask;
    Mcal_SetSafetyENDINIT_Timed();

    BackupData->MbistEnable = (boolean)TRUE;

    Result = PHLSRAM_SUCCESS;
  } /* if (PHLSRAM_NOTEXECUTED == Result) */

  return Result;
} /* PhlSramTst_lEnableMbist */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : Sl_TstRsltType PhlSramTst_lRestoreMbist                 **
**                    (                                                       **
**                      const uint8 MemIdx,                                   **
**                      const PhlSramTst_BackupDataType* const BackupData     **
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
**                             Peripheral SRAMs in PhlSramTst_MemDef.h for a  **
**                             list of supported values                       **
**                    BackupData - Pointer to backup data structure that      **
**                                 holds the original MBIST enable status     **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : PHLSRAM_SUCCESS - Restoring MBIST succeeded             **
**                    <Error ID> - Type of error while disabling MBIST        **
**                                                                            **
** Description      : This function restores the MBIST enable status of a     **
**                    given memory.                                           **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType PhlSramTst_lRestoreMbist
(
  const uint8 MemIdx,
  const PhlSramTst_BackupDataType* const BackupData
)
{
  Sl_TstRsltType            Result = PHLSRAM_NOTEXECUTED;
  volatile uint32*          MemTestPtr;
  uint32                    BitMask;
  uint8                     McIdx;

  /* Check if memory controller was disabled: */
  if (0U == BackupData->MemTest)
  {
    /* Get memory controller index: */
    McIdx = PhlSramTst_kMcTable[MemIdx];

    /* Get pointer to MTU_MEMTESTx and MTU_MEMSTATx SFR and store bit mask: */
    if (McIdx < 32U)
    {
      MemTestPtr = (volatile uint32*)(volatile void *)&MTU_MEMTEST0.U;
      BitMask = (uint32)((uint32)1U << McIdx);
    } /* if (McIdx < 32U) */
    else if (McIdx < 64U)
    {
      MemTestPtr = (volatile uint32*)(volatile void *)&MTU_MEMTEST1.U;
      BitMask = (uint32)((uint32)1U << (McIdx - 32U));
    } /* if (McIdx < 64U) */
    else if (McIdx < PHLSRAMTST_MBIST_CONTROLLER_COUNT)
    {
      MemTestPtr = (volatile uint32*)(volatile void *)&MTU_MEMTEST2.U;
      BitMask = (uint32)((uint32)1U << (McIdx - 64U));
    } /* if (McIdx < PHLSRAMTST_MBIST_CONTROLLER_COUNT) */
    else
    {
      Result = PHLSRAM_INVPARAMERR;

      /* Required to avoid compiler warning: */
      MemTestPtr = 0U;
      BitMask = 0U;
    } /* if (McIdx >= PHLSRAMTST_MBIST_CONTROLLER_COUNT) */

    if (PHLSRAM_NOTEXECUTED == Result)
    {
      /* Disable MBIST controller: */
      Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);
      *MemTestPtr &= ~BitMask;
      Mcal_SetSafetyENDINIT_Timed();

      Result = PHLSRAM_SUCCESS;
    } /* if (PHLSRAM_NOTEXECUTED == Result) */
  } /* if (0U == BackupData->MemTest) */
  else
  {
    /* Nothing to do, memory controller was already enabled before the test: */
    Result = PHLSRAM_SUCCESS;
  } /* if (0U != BackupData->MemTest) */

  return Result;
} /* PhlSramTst_lRestoreMbist */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : Sl_TstRsltType PhlSramTst_lWaitForSmuAlarm              **
**                    (                                                       **
**                      const uint8 SmuGrp,                                   **
**                      const uint8 SmuAlarmNr,                               **
**                      uint32* const TstSignature                            **
**                    )                                                       **
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
** Return value     : PHLSRAM_SUCCESS - Waiting for and clearing the SMU      **
**                                      alarm succeeded                       **
**                    <Error ID> - Type of error during waiting/clearing      **
**                                                                            **
** Description      : This function waits for the signaling of a given SMU    **
**                    alarm and afterwards clears this alarm if waiting       **
**                    succeeded.                                              **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType PhlSramTst_lWaitForSmuAlarm
(
  const uint8 SmuGrp,
  const uint8 SmuAlarmNr,
  uint32* const TstSignature
)
{
  Sl_TstRsltType  Result = PHLSRAM_NOTEXECUTED;
  uint32          AlarmStatus = 0U;
  uint32          Timeout = PHSR_SMU_ALM_TIMEOUT;

  /* Wait for the requested SMU alarm to become signaled: */
  while ((Timeout > 0U) &&
         (0U == (((uint32)1U << SmuAlarmNr) & AlarmStatus)))
  {
    Timeout--;
    if (E_OK != Smu_GetAlarmStatus(SmuGrp, &AlarmStatus))
    {
      AlarmStatus = 0U;
      Timeout = 0U;
      Result = PHLSRAM_SMU_GETALMSTSERR;
    } /* if (E_OK != Smu_GetAlarmStatus(SmuGrp, &AlarmStatus)) */
  } /* while ((Timeout > 0U) &&
              (0U == (((uint32)1U << SmuAlarmNr) & AlarmStatus))) */

  /* Update test signature: */
  *TstSignature = (uint32)CRC32(*TstSignature,
                        AlarmStatus & ((uint32)1U << SmuAlarmNr));

  /* Check if expected alarm was signaled: */
  if (0U == (((uint32)1U << SmuAlarmNr) & AlarmStatus))
  {
    if (PHLSRAM_NOTEXECUTED == Result)
    {
      Result = PHLSRAM_SMU_ALMSTSERR;
    } /* if (PHLSRAM_NOTEXECUTED == Result) */
  } /* if (0U == (((uint32)1U << SmuAlarmNr) & AlarmStatus)) */
  else
  {
    /* Clear the SMU alarm: */
    if (E_OK != Smu_ClearAlarmStatus(SmuGrp, SmuAlarmNr))
    {
      Result = PHLSRAM_SMU_CLRALMSTSERR;
    } /* if (E_OK != PhlSramTst_lSmuClearAlarmStatus(SmuGrp, SmuAlarmNr)) */
    else
    {
      Result = PHLSRAM_SUCCESS;
    } /* if (E_OK == PhlSramTst_lSmuClearAlarmStatus(SmuGrp, SmuAlarmNr)) */
  } /* if (0U != (((uint32)1U << SmuAlarmNr) & AlarmStatus)) */

  return Result;
} /* PhlSramTst_lWaitForSmuAlarm */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : Sl_TstRsltType PhlSramTst_lBackupMemContent             **
**                    (                                                       **
**                      const uint8 MemIdx,                                   **
**                      PhlSramTst_BackupDataType* const BackupData           **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : MemIdx - Index of the memory under test; Refer to       **
**                             definition of Peripheral SRAMs in              **
**                             PhlSramTst_MemDef.h for a list of supported    **
**                             values                                         **
**                                                                            **
** Parameters (out) : BackupData - Pointer to backup data structure of the    **
**                                 Peripheral SRAM test                       **
**                                                                            **
** Return value     : PHLSRAM_SUCCESS - Memory backup succeeded or disabled   **
**                                      via configuration setting             **
**                    PHLSRAM_CONSISTENCYERR - Invalid memory definition      **
**                    PHLSRAM_NOTEXECUTED - Program flow consistency error    **
**                                                                            **
** Description      : This function backs up all memory content that will be  **
**                    overwritten by the test to a backup data structure.     **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType PhlSramTst_lBackupMemContent
(
  const uint8 MemIdx,
  PhlSramTst_BackupDataType* const BackupData
)
{
  Sl_TstRsltType  Result = PHLSRAM_NOTEXECUTED;
  Sl_TstRsltType  ResultTmp;
  uint8           RdbflRegIdx;
  uint8           RdbflRegCount;
  uint16          WordlineIdx;
  uint16          WordlineCount;
  Ifx_MC*         Mc;

    /* Get pointer to memory controller SFRs of RAM under test: */
    Mc = PhlSramTst_lGetMc(MemIdx);

    /* Calculate number of wordlines to backup:
     *  -Nr. of error tracking registers + 1 wordlines is required in the
     *   SRAM monitor test to create an overflow of error tracking records
     */
    WordlineCount = (uint16)PhlSramTst_kMemDef[MemIdx]->NrOfEtrRegisters +
                    (uint16)1U;

    /* WordlineCount consistency check: */
    if (WordlineCount > PHSR_MAX_NR_OF_WORDLINES)
    {
      Result = PHLSRAM_CONSISTENCYERR;
    } /* if (WordlineCount > PHSR_MAX_NR_OF_WORDLINES) */
    else
    {
      /* Calculate the total number of RDBFL registers: */
      RdbflRegCount = PhlSramTst_lCalcRdbflRegCount(MemIdx);

      /* Backup memory wordline-wise: */
      for (WordlineIdx = 0U;
           ((WordlineIdx < WordlineCount) && (PHLSRAM_NOTEXECUTED == Result));
           WordlineIdx++)
      {
        ResultTmp = PhlSramTst_lReadWordline(MemIdx, WordlineIdx);
        if (PHLSRAM_SUCCESS != ResultTmp)
        {
          Result = ResultTmp;
        } /* if (PHLSRAM_SUCCESS != ResultTmp) */
        else
        {
          for (RdbflRegIdx = 0U; RdbflRegIdx < RdbflRegCount; RdbflRegIdx++)
          {
            BackupData->MemContentBackup[(WordlineIdx * RdbflRegCount) +
                                        RdbflRegIdx] = Mc->RDBFL[RdbflRegIdx].U;
          } /* for (RdbflRegIdx = 0U;
                    RdbflRegIdx < RdbflRegCount;#
                    RdbflRegIdx++) */
        } /* if (PHLSRAM_SUCCESS != ResultTmp) */
      } /* for (WordlineIdx = 0U;
                ((WordlineIdx < WordlineCount) &&
                 (PHLSRAM_NOTEXECUTED == Result));
                WordlineIdx++) */

      if (PHLSRAM_NOTEXECUTED == Result)
      {
        /* Set memory backup valid: */
        BackupData->MemBackupValid = (boolean)TRUE;

        /* Update Result: */
        Result = PHLSRAM_SUCCESS;
      } /* if (PHLSRAM_NOTEXECUTED == Result) */
    } /* if (WordlineCount <= PHSR_MAX_NR_OF_WORDLINES) */

  return Result;
} /* PhlSramTst_lBackupMemContent */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : Sl_TstRsltType PhlSramTst_lRestoreMemContent            **
**                    (                                                       **
**                      const uint8 MemIdx,                                   **
**                      const Sl_ParamSetType ParamSetIndex,                  **
**                      const PhlSramTst_BackupDataType* const BackupData     **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : MemIdx - Index of the memory under test; Refer to       **
**                             definition of Peripheral SRAMs in              **
**                             PhlSramTst_MemDef.h for a list of supported    **
**                             values                                         **
**                    ParamSetIndex - config Parameter index                  **
**                    BackupData - Pointer to backup data structure of the    **
**                                 Peripheral SRAM test                       **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : PHLSRAM_SUCCESS - Memory restoration succeeded or is    **
**                                      disabled via configuration setting    **
**                    PHLSRAM_CONSISTENCYERR - Invalid memory definition      **
**                    PHLSRAM_NOTEXECUTED - Program flow consistency error    **
**                                                                            **
** Description      : This function restores all memory content that has been **
**                    backed up by PhlSramTst_lBackupMemContent function.     **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType PhlSramTst_lRestoreMemContent
(
  const uint8 MemIdx,
  const Sl_ParamSetType ParamSetIndex,    
  const PhlSramTst_BackupDataType* const BackupData
)
{
  Sl_TstRsltType  Result = PHLSRAM_NOTEXECUTED;
  Sl_TstRsltType  ResultTmp;
  uint8           RdbflRegIdx;
  uint8           RdbflRegCount;
  uint16          WordlineIdx;
  uint16          WordlineCount;
  Ifx_MC*         Mc;
  uint16          Range = (uint16)0U;
  uint16          Delay = (uint16)0U;
  

  if ((boolean)TRUE == BackupData->MemBackupValid)
  { 
    if ((boolean)FALSE == PhlSramTst_ConfigRoot[ParamSetIndex].ClearMemory)
    {   
      /* Get pointer to memory controller SFRs of RAM under test: */
      Mc = PhlSramTst_lGetMc(MemIdx);
  
      /* Calculate number of wordlines to backup:
       *  -Nr. of error tracking registers + 1 wordlines is required in the
       *   SRAM monitor test to create an overflow of error tracking records
       */
      WordlineCount = (uint16)PhlSramTst_kMemDef[MemIdx]->NrOfEtrRegisters +
                      (uint16)1U;
  
      /* WordlineCount consistency check: */
      if (WordlineCount > PHSR_MAX_NR_OF_WORDLINES)
      {
        Result = PHLSRAM_CONSISTENCYERR;
      } /* if (WordlineCount > PHSR_MAX_NR_OF_WORDLINES) */
      else
      {
        /* Calculate the total number of RDBFL registers: */
        RdbflRegCount = PhlSramTst_lCalcRdbflRegCount(MemIdx);
  
        /* Restore memory wordline-wise: */
        for (WordlineIdx = 0U;
             ((WordlineIdx < WordlineCount) && (PHLSRAM_NOTEXECUTED == Result));
             WordlineIdx++)
        {
          for (RdbflRegIdx = 0U; RdbflRegIdx < RdbflRegCount; RdbflRegIdx++)
          {
            Mc->RDBFL[RdbflRegIdx].U = BackupData->MemContentBackup[
                        (WordlineIdx * RdbflRegCount) + RdbflRegIdx];
          } /* for (RdbflRegIdx = 0U;
                    RdbflRegIdx < RdbflRegCount;
                    RdbflRegIdx++) */
          ResultTmp = PhlSramTst_lWriteWordline(MemIdx, WordlineIdx);
          if (PHLSRAM_SUCCESS != ResultTmp)
          {
            Result = ResultTmp;
          } /* if (PHLSRAM_SUCCESS != ResultTmp) */
        } /* for (WordlineIdx = 0U;
                  ((WordlineIdx < WordlineCount) &&
                   (PHLSRAM_NOTEXECUTED == Result));
                  WordlineIdx++) */
        if (PHLSRAM_NOTEXECUTED == Result)
        {
          /* Restoration succeeded: */
          Result = PHLSRAM_SUCCESS;
        } /* if (PHLSRAM_NOTEXECUTED == Result) */
      } /* if (WordlineCount <= PHSR_MAX_NR_OF_WORDLINES) */
    }
    else
    {
      Delay = (PhlSramTst_kMemDef[MemIdx]->TowerDepth)+PHL_SRAM_DEPTH_OFFSET;
      Range = (uint16)(((PhlSramTst_kMemDef[MemIdx]->TowerDepth)/PHL_SRAM_MAX_WORDLINES)-1U);
      Range = ((uint16)(Range << PHL_SRAM_RANGE_UPLIMIT))|PHL_SRAM_RANGE_RAEN;    
      Result = PhlSramTst_lClearSram(MemIdx, Range, Delay);
    }
  }
  else
  {
    /* Nothing to do, return success: */
    Result = PHLSRAM_SUCCESS;
  } /* if ((boolean)TRUE != BackupData->MemBackupValid) */      
  return Result;
} /* PhlSramTst_lRestoreMemContent */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : Sl_TstRsltType PhlSramTst_lEnableMtuClock               **
**                    (                                                       **
**                      PhlSramTst_BackupDataType* const BackupData           **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : BackupData - Pointer to backup data structure of the    **
**                                 Peripheral SRAM test                       **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : PHLSRAM_SUCCESS - MTU clock enable succeeded            **
**                    <Error ID> - Type of error during clock enable          **
**                                                                            **
** Description      : This function enables clock gating for the MTU module   **
**                    and stores the previous status of MTU clock gating to   **
**                    the given backup data structure.                        **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType PhlSramTst_lEnableMtuClock
(
  PhlSramTst_BackupDataType* const BackupData
)
{
  Sl_TstRsltType            Result = PHLSRAM_MBIST_CLCTIMEOUT;
  uint32                    Timeout;

  /* Backup MTU_CLC.DISR bit: */
  BackupData->MtuClcDisr = (uint8)(MTU_CLC.B.DISR);

  /* Enable MTU clock: */
  Mcal_ResetENDINIT();
  MTU_CLC.B.DISR = 0U;
  Mcal_SetENDINIT();
  Timeout = PHSR_CLK_EN_TIMEOUT;
  while((MTU_CLC.B.DISS > 0U) && (Timeout > 0U))
  {
    Timeout--;
  } /* while((MTU_CLC.B.DISS > 0U) && (Timeout > 0U)) */
  if (MTU_CLC.B.DISS == 0U)
  {
    Result = PHLSRAM_SUCCESS;
  } /* if (MTU_CLC.B.DISS == 0U) */

  return Result;
} /* PhlSramTst_lEnableMtuClock */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : Sl_TstRsltType PhlSramTst_lRestoreMtuClock              **
**                    (                                                       **
**                      const PhlSramTst_BackupDataType* const BackupData     **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : BackupData - Pointer to backup data structure of the    **
**                                 Peripheral SRAM test that holds the        **
**                                 previous state of MTU clock gating         **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : PHLSRAM_SUCCESS - MTU clock restoration succeeded       **
**                    <Error ID> - Type of error during clock restoration     **
**                                                                            **
** Description      : This function restores clock gating for the MTU module  **
**                    as it has been before the Peripheral SRAM test was      **
**                    executed.                                               **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType PhlSramTst_lRestoreMtuClock
(
  const PhlSramTst_BackupDataType* const BackupData
)
{
  Sl_TstRsltType            Result = PHLSRAM_MBIST_CLCTIMEOUT;
  uint32                    Timeout;

  /* Restore MTU clock enable setting: */
  if (BackupData->MtuClcDisr > 0U)
  {
    /* Disable MTU clock: */
    Mcal_ResetENDINIT();
    MTU_CLC.B.DISR = 1U;
    Mcal_SetENDINIT();
    Timeout = PHSR_CLK_EN_TIMEOUT;
    while((MTU_CLC.B.DISS == 0U) && (Timeout > 0U))
    {
      Timeout--;
    } /* while((MTU_CLC.B.DISS == 0U) && (Timeout > 0U)) */
    if (MTU_CLC.B.DISS > 0U)
    {
      Result = PHLSRAM_SUCCESS;
    } /* if (MTU_CLC.B.DISS_BIT > 0U) */
  } /* if (BackupData->MtuClcDisr > 0U) */
  else
  {
    Result = PHLSRAM_SUCCESS;
  } /* if (BackupData->MtuClcDisr == 0U) */

  return Result;
} /* PhlSramTst_lRestoreMtuClock */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : Sl_TstRsltType PhlSramTst_lEnableSramClock              **
**                    (                                                       **
**                      const uint8 MemIdx,                                   **
**                      PhlSramTst_BackupDataType* const BackupData           **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : MemIdx - Index of the memory under test; Refer to       **
**                             definition of Peripheral SRAMs in              **
**                             PhlSramTst_MemDef.h for a list of supported    **
**                             values                                         **
**                    BackupData - Pointer to backup data structure of the    **
**                                 Peripheral SRAM test                       **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : PHLSRAM_SUCCESS - Enabling SRAM clock succeeded         **
**                    PHLSRAM_SFR_LOCK - Update failed due to locked CCUCON   **
**                                       register                             **
**                    PHLSRAM_NOTEXECUTED - Program flow consistency error    **
**                                                                            **
** Description      : This function enables clock gating to the SRAM under    **
**                    and stores the previous status of the SRAM clock to the **
**                    given backup data structure.                            **
**                    Enabling the clock is only required for few SRAMs which **
**                    are driven by a certain module clock. Most Peripheral   **
**                    SRAMs are directly driven by f_SPB or f_BBB, in which   **
**                    case no clock enable is required.                       **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType PhlSramTst_lEnableSramClock
(
  const uint8 MemIdx,
  PhlSramTst_BackupDataType* const BackupData
)
{
  uint32          Timeout;
  uint32          Status;
  volatile uint32 Dummy = 0U;
  Sl_TstRsltType  Result = PHLSRAM_NOTEXECUTED;

  UNUSED_PARAMETER(Dummy)  
  switch(MemIdx)
  {
  case PHL_SRAM_GTM_FIFO:
  case PHL_SRAM_GTM_MCS0:
  case PHL_SRAM_GTM_MCS1:
  case PHL_SRAM_GTM_DPLL1A:
  case PHL_SRAM_GTM_DPLL1B:
  case PHL_SRAM_GTM_DPLL2:
    /* Enable GTM module clock: */
    BackupData->ClockBackup = GTM_CLC.U;
    Mcal_ResetENDINIT();
    GTM_CLC.B.DISR = 0U;

    /* Read back to ensure write operation has completed: */
    Dummy = GTM_CLC.U;
    Mcal_SetENDINIT();

    /* Update Result: */
    Result = PHLSRAM_SUCCESS;
    break;
  #if((CHIP_ID != 22U)&&(CHIP_ID != 21U))
  
  case PHL_SRAM_ETHER_MAC:
    /* Enable Ethernet module clock: */
    BackupData->ClockBackup = ETH_CLC.U;
    Mcal_ResetENDINIT();
    ETH_CLC.B.DISR = 0U;

    /* Read back to ensure write operation has completed: */
    Dummy = ETH_CLC.U;
    Mcal_SetENDINIT();

    /* Update Result: */
    Result = PHLSRAM_SUCCESS;
    break;  
	


  case PHL_SRAM_EMEM_LOWER0:
  case PHL_SRAM_EMEM_LOWER1:
  case PHL_SRAM_EMEM_LOWER2:
  case PHL_SRAM_EMEM_LOWER3:
  case PHL_SRAM_EMEM_LOWER4:
  case PHL_SRAM_EMEM_LOWER5:
  case PHL_SRAM_EMEM_LOWER6:
  case PHL_SRAM_EMEM_LOWER7:
  case PHL_SRAM_EMEM_LOWER8:
  case PHL_SRAM_EMEM_LOWER9:
  case PHL_SRAM_EMEM_LOWER10:
  case PHL_SRAM_EMEM_LOWER11:    
  case PHL_SRAM_EMEM_LOWER12:    
  case PHL_SRAM_EMEM_LOWER13:    
  case PHL_SRAM_EMEM_LOWER14:    
  case PHL_SRAM_EMEM_LOWER15:        

    BackupData->ClockBackup = EMEM_CLC.U;
    Mcal_ResetENDINIT();
    /* Enable EMEM module clock: */    
    EMEM_CLC.B.DISR = 0U;

    /* Read back to ensure write operation has completed: */
    Dummy = EMEM_CLC.U;
    Mcal_SetENDINIT();

    /* Update Result: */
    Result = PHLSRAM_SUCCESS;
    break;  
  #endif
    
  case PHL_SRAM_MCAN0:
  case PHL_SRAM_MCAN1:
    /* Wait for CCUCON0 to be writable: */
    Timeout = PHSR_SFR_LOCK_TIMEOUT;
    do
    {
      Timeout--;
      Status = SCU_CCUCON0.B.LCK;
    } while ((Timeout > 0U) && (Status > 0U));

    /* Check if CCUCON0 is still locked: */
    if (1U == SCU_CCUCON0.B.LCK)
    {
      Result = PHLSRAM_SFR_LOCK;
    } /* if (1U == SCU_CCUCON0.B.LCK) */
    else
    {
      /* Ensure MCAN SRAM is clocked by f_SPB by clearing CCUCON0.LPDIV: */
      BackupData->ClockBackup = SCU_CCUCON0.U;
      Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);
      SCU_CCUCON0.B.LPDIV = 0U;
      SCU_CCUCON0.B.UP = 1U;
      Mcal_SetSafetyENDINIT_Timed();

      /* Update Result: */
      Result = PHLSRAM_SUCCESS;
    } /* if (1U != SCU_CCUCON0.B.LCK) */
    break;

  default:
    /* Nothing to do */
    Result = PHLSRAM_SUCCESS;
    break;
  } /* switch(MemIdx) */

  return Result;
} /* PhlSramTst_lEnableSramClock */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : Sl_TstRsltType PhlSramTst_lRestoreSramClock             **
**                    (                                                       **
**                      const uint8 MemIdx,                                   **
**                      const PhlSramTst_BackupDataType* const BackupData     **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : MemIdx - Index of the memory under test; Refer to       **
**                             definition of Peripheral SRAMs in              **
**                             PhlSramTst_MemDef.h for a list of supported    **
**                             values                                         **
**                    BackupData - Pointer to backup data structure of the    **
**                                 Peripheral SRAM test that holds the        **
**                                 previous state of the clock gating         **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : PHLSRAM_SUCCESS - Enabling SRAM clock succeeded         **
**                    PHLSRAM_SFR_LOCK - Update failed due to locked CCUCON   **
**                                       register                             **
**                    PHLSRAM_NOTEXECUTED - Program flow consistency error    **
**                                                                            **
** Description      : This function restores clock gating to the SRAM under   **
**                    test as it has been before the Peripheral SRAM test was **
**                    executed.                                               **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType PhlSramTst_lRestoreSramClock
(
  const uint8 MemIdx,
  const PhlSramTst_BackupDataType* const BackupData
)
{
  uint32          Timeout;
  uint32          Status;
  Sl_TstRsltType  Result = PHLSRAM_NOTEXECUTED;

  switch(MemIdx)
  {
  case PHL_SRAM_GTM_FIFO:
  case PHL_SRAM_GTM_MCS0:
  case PHL_SRAM_GTM_MCS1:
  case PHL_SRAM_GTM_DPLL1A:
  case PHL_SRAM_GTM_DPLL1B:
  case PHL_SRAM_GTM_DPLL2:
    /* Check if value is valid: */
    if (PHSR_INV_BACKUP_VALUE != BackupData->ClockBackup)
    {
      /* Restore GTM module clock: */
      Mcal_ResetENDINIT();
      GTM_CLC.U = BackupData->ClockBackup;
      Mcal_SetENDINIT();
    } /* if (PHSR_INV_BACKUP_VALUE != BackupData->ClockBackup) */

    /* Update Result: */
    Result = PHLSRAM_SUCCESS;
    break;

  case PHL_SRAM_MCAN0:
  case PHL_SRAM_MCAN1:
    /* Check if value is valid: */
    if (PHSR_INV_BACKUP_VALUE != BackupData->ClockBackup)
    {
      /* Wait for CCUCON0 to be writable: */
      Timeout = PHSR_SFR_LOCK_TIMEOUT;
      do
      {
        Timeout--;
        Status = SCU_CCUCON0.B.LCK;
      } while ((Timeout > 0U) && (Status > 0U));

      /* Check if CCUCON0 is still locked: */
      if (1U == SCU_CCUCON0.B.LCK)
      {
        Result = PHLSRAM_SFR_LOCK;
      } /* if (1U == SCU_CCUCON0.B.LCK) */
      else
      {
        /* Restore CCUCON0.LPDIV: */
        Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);
        SCU_CCUCON0.U = BackupData->ClockBackup;
        SCU_CCUCON0.B.UP = 1U;
        Mcal_SetSafetyENDINIT_Timed();

        /* Update Result: */
        Result = PHLSRAM_SUCCESS;
      } /* if (1U != SCU_CCUCON0.B.LCK) */
    } /* if (PHSR_INV_BACKUP_VALUE != BackupData->ClockBackup) */
    else
    {
      /* Nothing to do */
      Result = PHLSRAM_SUCCESS;
    } /* if (PHSR_INV_BACKUP_VALUE == BackupData->ClockBackup) */
    break;

  default:
    /* Nothing to do */
    Result = PHLSRAM_SUCCESS;
    break;
  } /* switch(MemIdx) */

  return Result;
} /* PhlSramTst_lRestoreSramClock */

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : LOCAL_INLINE uint32 PhlSramTst_lCalcAlmCounterCrc                 **
**          (                                                                 **
**            void                                                            **
**          )                                                                 **
**                                                                            **
** Description : Calculates the CRC over all members of the                   **
**               PhlSramTst_UnexpAlm unexpected alarm structure.              **
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
LOCAL_INLINE uint32 PhlSramTst_lCalcAlmCounterCrc
(
  void
)
{
  uint32  Result;

  Result = (uint32)CRC32(PhlSramTst_UnexpAlm.Correctable,
                         PhlSramTst_UnexpAlm.Uncorrectable);
  Result = (uint32)CRC32(Result, PhlSramTst_UnexpAlm.Address);
  Result = (uint32)CRC32(Result, PhlSramTst_UnexpAlm.ErrTrkOvf);

 return Result;
} /* PhlSramTst_lCalcAlmCounterCrc */

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : static uint32 PhlSramTst_lCalcBackupCrc                           **
**          (                                                                 **
**            const PhlSramTst_BackupDataType* const BackupData               **
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
** Parameters (in) : BackupData - Pointer to backup data over which the CRC   **
**                                is to be calculated                         **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value : Requested backup data CRC value                             **
**                                                                            **
*******************************************************************************/
static uint32 PhlSramTst_lCalcBackupCrc
(
  const PhlSramTst_BackupDataType* const BackupData
)
{
  uint32  i;
  uint32  Result;

  Result = (uint32)CRC32((uint32)BackupData->AlmActionBackupSbeCorr,
                         (uint32)BackupData->AlmActionBackupUcErr);
  Result = (uint32)CRC32(Result, (uint32)BackupData->AlmActionBackupAdrErr);
  Result = (uint32)CRC32(Result, (uint32)BackupData->AlmActionBackupAdrBufFull);
  Result = (uint32)CRC32(Result, (uint32)BackupData->GetAlmActionResult);
  Result = (uint32)CRC32(Result, BackupData->MemTest);
  /* Calculate CRC over the whole memory backup storage; even if not all
   * backup storage is actually used, an unintended modification would indicate
   * a problem:
   */
  for (i = 0U; i < (PHSR_MAX_RDBFL_REGS * PHSR_MAX_NR_OF_WORDLINES); i++)
  {
    Result = (uint32)CRC32(Result, (uint32)BackupData->MemContentBackup[i]);
  } /* for (i = 0U;
            i < (PHSR_MAX_RDBFL_REGS * PHSR_MAX_NR_OF_WORDLINES);
            i++) */
  Result = (uint32)CRC32(Result, (uint32)BackupData->MemBackupValid);
  Result = (uint32)CRC32(Result, (uint32)BackupData->MtuClcDisr);
  Result = (uint32)CRC32(Result, (uint32)BackupData->ClockBackup);
  Result = (uint32)CRC32(Result, (uint32)BackupData->Eccs);
  Result = (uint32)CRC32(Result, (uint32)BackupData->Range);

 return Result;
} /* PhlSramTst_lCalcBackupCrc */

/*******************************************************************************
** Traceability      : [cover parentID=]        [/cover]                      **
**                                                                            **
** Syntax           : Sl_TstRsltType PhlSramTst_PhlSramTst                    **
**                    (                                                       **
**                      const Sl_ParamSetType ParamSetIndex,                  **
**                      const uint8 TstSeed,                                  **
**                      uint32* const TstSignature                            **
**                    );                                                      **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : ParamSetIndex : Identifies the parameter set to be      **
**                                    used for test execution, valid range    **
**                                    0..PHLSRAM_TST_CFG_PARAM_COUNT,         **
**                                    depending on configuration              **
**                    TstSeed : Seed to be used for generating the signature  **
**                                                                            **
** Parameters (out) : TstSignature : Test signature generated by the test     **
**                                                                            **
** Return value     : PHLSRAM_SUCCESS - Test succeeded                        **
**                    <Error ID> - Type of error during test                  **
**                                                                            **
** Description      : API provided for the Peripheral SRAM test.              **
**                    It is responsible for test preparation, test execution  **
**                    and final test restoration.                             **
**                    This test checks that correctable ECC errors,           **
**                    uncorrectable ECC errors, address line errors and error **
**                    tracking overflows are correctly signaled to the SMU    **
**                    for all configured Peripheral SRAMs.                    **
**                                                                            **
*******************************************************************************/
Sl_TstRsltType PhlSramTst_PhlSramTst
(
  const Sl_ParamSetType ParamSetIndex,
  const uint8 TstSeed,
  uint32* const TstSignature
)
{
  Sl_TstRsltType            Result = PHLSRAM_NOTEXECUTED;
  Sl_TstRsltType            ResultTmp;
  PhlSramTst_BackupDataType BackupData;
  uint8                     i;
  uint8                     j;
  uint8                     MemIdx;

  /* Initialize test signature: */
  *TstSignature = (uint32)CRC32((uint32)TEST_ID_PHLSRAM_TST, (uint32)TstSeed);

  /* Initialize unexpected alarm counter CRC: */
  PhlSramTst_UnexpAlm.Crc = PhlSramTst_lCalcAlmCounterCrc();

  /* Validate the input parameter */
  if(ParamSetIndex >= (Sl_ParamSetType)PHLSRAM_TST_CFG_PARAM_COUNT)
  {
    Result = PHLSRAM_INVPARAMERR;
  } /* if(ParamSetIndex >= (Sl_ParamSetType)PHLSRAM_TST_CFG_PARAM_COUNT) */
  else
  {
    ResultTmp = PhlSramTst_lEnableMtuClock(&BackupData);
    if (PHLSRAM_SUCCESS != ResultTmp)
    {
      Result = ResultTmp;
    } /* if (PHLSRAM_SUCCESS != ResultTmp) */
    else
    {
      /* Loop through each MemorySelect[] array entry: */
      for (j = 0U;
           ((j < PHLSRAMTST_MEMORY_SELECT_DEPTH) &&
            (PHLSRAM_NOTEXECUTED == Result));
           j++)
      {
        /* Loop through each bit in MemorySelect parameter and check if testing is
         * enabled for the respective SRAM:
         */
        for (i = 0U;
             (i < PHLSRAMTST_MEMORY_SELECT_WIDTH) && (PHLSRAM_NOTEXECUTED == Result);
             i++)
        {
          /* Get memory index: */
          MemIdx = (j * PHLSRAMTST_MEMORY_SELECT_WIDTH) + i;

          /* Check if memory testing is enabled: */
          if ((MemIdx < PHLSRAMTST_MEMORY_COUNT) &&
              ((PhlSramTst_ConfigRoot[ParamSetIndex].MemorySelect[j] &
               ((uint32)1U << i)) > (uint32)0U))
          {
            /* Check if selected memory is a supported SRAM: */
            if (NULL_PTR != PhlSramTst_kMemDef[MemIdx])
            {
              ResultTmp = PhlSramTst_lTestMemory(MemIdx,
                                                 ParamSetIndex,
                                                 TstSignature,
                                                 &BackupData);
              if (PHLSRAM_SUCCESS != ResultTmp)
              {
                Result = ResultTmp;
              } /* if (PHLSRAM_SUCCESS != ResultTmp) */
            } /* (NULL_PTR != PhlSramTst_kMemDef[MemIdx]) */
            else
            {
              Result = PHLSRAM_CONFIGERR;
            } /* (NULL_PTR == PhlSramTst_kMemDef[MemIdx]) */
          } /* if ((MemIdx < PHLSRAMTST_MEMORY_COUNT) &&
                   ((PhlSramTst_ConfigRoot[ParamSetIndex].MemorySelect[j] &
                    ((uint32)1U << i)) > (uint32)0U)) */
        } /* for (i = 0U;
                  (i < PhlSramTst_MEMORY_COUNT) && (PHLSRAM_NOTEXECUTED ==
                   Result);
                  i++) */
      } /* for (j = 0U;
                ((j < PHLSRAMTST_MEMORY_SELECT_DEPTH) &&
                 (PHLSRAM_NOTEXECUTED == Result));
                j++) */

      ResultTmp = PhlSramTst_lRestoreMtuClock(&BackupData);
      if (PHLSRAM_SUCCESS != ResultTmp)
      {
        Result = ResultTmp;
      } /* if (PHLSRAM_SUCCESS != Result) */
      else if (PHLSRAM_NOTEXECUTED == Result)
      {
        Result = PHLSRAM_SUCCESS;
      } /* else if (PHLSRAM_NOTEXECUTED == Result) */
      else
      {
        /* Nothing to do */
      } /* else if (PHLSRAM_NOTEXECUTED != Result) */
	  
    } /* if (PHLSRAM_SUCCESS == ResultTmp) */
  } /* if(ParamSetIndex < (Sl_ParamSetType)PHLSRAM_TST_CFG_PARAM_COUNT) */

  /* Add final test result to test signature: */
  *TstSignature = (uint32)CRC32(*TstSignature, (uint32)Result);

  return Result;
} /* PhlSramTst_SramEccTst */

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : PhlSramTst_UnexpAlmType*                                          **
**          PhlSramTst_GetUnexpEccAlmListPtr                                  **
**          (                                                                 **
**            void                                                            **
**          )                                                                 **
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
** Return value :   PhlSramTst_UnexpAlmType* Pointer to list of unexpected    **
**                                           Ecc alarms cleared before a test **
**                                           run or NULL_PTR if the counters  **
**                                           for unexpected SMU alarms has    **
**                                           been corrupted.                  **
**                                                                            **
*******************************************************************************/
PhlSramTst_UnexpAlarmType* PhlSramTst_GetUnexpEccAlmListPtr
(
  void
)
{
  PhlSramTst_UnexpAlarmType*  Result = NULL_PTR;

  if (PhlSramTst_lCalcAlmCounterCrc() == PhlSramTst_UnexpAlm.Crc)
  {
    Result = &PhlSramTst_UnexpAlm;
  } /* if (PhlSramTst_lCalcAlmCounterCrc() == PhlSramTst_UnexpAlm.Crc) */

  return Result;
} /* PhlSramTst_GetUnexpEccAlmListPtr */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static void PhlSramTst_lClearSram                       **
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
**                             PhlSramTst_MemDef.h for a list of supported    **
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
static Sl_TstRsltType PhlSramTst_lClearSram
(
  const uint8 MemIdx,
  const uint16 Range,
  const uint16 Delay
)
{
  Ifx_MC*                   Mc;
  volatile uint16           DelayCounter;
  Sl_TstRsltType            Result = PHLSRAM_NOTEXECUTED;

  /* Get pointer to memory controller SFRs of RAM under test: */
  Mc = PhlSramTst_lGetMc(MemIdx);

  /* Fill RDBFL registers with all zero data but valid ECC: */
  PhlSramTst_lCreateZeroPattern(MemIdx);

  /* Select address */
  Mc->RANGE.U = Range;

  /* Start write operation: */
  Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);

  Mc->MCONTROL.U = (uint16)(((uint32)IFX_MC_MCONTROL_DINIT_MSK <<
                             (uint32)IFX_MC_MCONTROL_DINIT_OFF) |
                            ((uint32)IFX_MC_MCONTROL_DIR_MSK <<
                             (uint32)IFX_MC_MCONTROL_DIR_OFF) |
                            ((uint32)IFX_MC_MCONTROL_START_MSK <<
                             (uint32)IFX_MC_MCONTROL_START_OFF)|
                             ((uint32)PHSR_MC_MCONTROL_USERED_MSK <<
                             (uint32)PHSR_MC_MCONTROL_USERED));

  Mc->MCONTROL.U = (uint16)(((uint32)IFX_MC_MCONTROL_DINIT_MSK <<
                             (uint32)IFX_MC_MCONTROL_DINIT_OFF) |
                            ((uint32)IFX_MC_MCONTROL_DIR_MSK <<
                             (uint32)IFX_MC_MCONTROL_DIR_OFF)|
                            ((uint32)PHSR_MC_MCONTROL_USERED_MSK <<
                             (uint32)PHSR_MC_MCONTROL_USERED));
  Mcal_SetSafetyENDINIT_Timed();

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
    Result = PHLSRAM_SUCCESS;
  } /* if ((Mc->MSTATUS.U & (uint16)((uint32)IFX_MC_MSTATUS_DONE_MSK <<
                                     (uint32)IFX_MC_MSTATUS_DONE_OFF)) > 0U) */
  else
  {
    Result = PHLSRAM_MBIST_RWOPTIMEOUT;
  } /* if ((Mc->MSTATUS.U & (uint16)((uint32)IFX_MC_MSTATUS_DONE_MSK <<
                                     (uint32)IFX_MC_MSTATUS_DONE_OFF)) == 0U) */

  return Result;
} /* PhlSramTst_lClearSram */

  
#define IFX_PHL_SRAM_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
