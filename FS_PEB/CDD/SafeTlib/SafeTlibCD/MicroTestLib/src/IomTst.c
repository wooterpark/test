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
**  $FILENAME   : IomTst.c $                                                 **
**                                                                            **
**  $CC VERSION : \main\20 $                                                 **
**                                                                            **
**  $DATE       : 2018-02-22 $                                               **
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
**                 IOM Input/Output monitor test.                             **
**                                                                            **
**  REFERENCE(S) : Aurix_SafeTlib_DS_Iom_Test.docm                            **
**                                                                            **
*  MAY BE CHANGED BY USER : no                                                **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "IomTst.h"
#include "SmuInt.h"
#include "Mcal.h"
#include "IfxIom_reg.h"
#include "IfxIom_bf.h"
#include "IfxPort_reg.h"
#include "IfxPort_bf.h"

/*******************************************************************************
**                      Local Macro Definitions                               **
*******************************************************************************/
#define IOMTST_ZERO                         (0x00U)
#define IOMTST_ONE                          (0x01U)

/* Alarm group index in IOM alarm */
#define IOMTST_ALARM_GRP                    ((uint8)SMU_ALARM_GROUP2)

/* Alarm index of IOM alarm */
#define IOMTST_ALARM_INDEX                  (SMU_ALARM_26)
#define IOMTST_ALARM                        ((uint32)(0x01U) << \
                                                            IOMTST_ALARM_INDEX)

#define IOMTST_ACCEN0_EN_WRITE              (0xFFFFFFFFU)

#define IOMTST_CLC_DISR_DISABLE             (0x00U)
#define IOMTST_CLC_EDIS_DISABLE             (0x00U)
#define IOMTST_CLC_RMC_ONE                  (0x01U)

#define IOMTST_ECMCCFG_COUNTERS_DISABLE     (0x00U)
#define IOMTST_ECMSELR_CESX_SELECTED        (0x01U)
#define IOMTST_ECMSELR_CESX_DISABLE         (0x00U)

#define IOMTST_FPCCTR_CMP_THR_MIN           (0x00U)
#define IOMTST_FPCCTR_MOD_IMM_DEBOUNCE      (0x01U)
#define IOMTST_FPCCTR_ISM_PORT_IN           (0x00U)
#define IOMTST_FPCCTR_RTG_TIM_DEC_GLITCH    (0x00U)
#define IOMTST_FPCCTR_ISR_PORT_IN           (0x00U)

#define IOMTST_LAMEWS_THR_MAX               (0xFFFFFFU)
#define IOMTST_LAMEWS_THR_DISABLE           (0x0U)

#define IOMTST_LAMCFG_IVR_NO_INVERT         (0x00U)
#define IOMTST_LAMCFG_IVM_NO_INVERT         (0x00U)
#define IOMTST_LAMCFG_MOS_MON_DIR           (0x00U)
#define IOMTST_LAMCFG_RMS_FREE_RUNNING      (0x00U)
#define IOMTST_LAMCFG_EWS_EVT_MON           (0x01U)
#define IOMTST_LAMCFG_EDS_EGATE_ECLR_EVT    (0x0FU)
#define IOMTST_LAMCFG_IVW_INVERT_WDW        (0x01U)

#define IOMTST_LAMCFG_RESET_VAL             (0x0U)

#define IOMTST_P_IOCRX_PCX_IN_PULLDOWN      (0x01U)
#define IOMTST_P_IOCRX_PCX_IN_PULLUP        (0x02U)
#define IOMTST_MODULE                       (MODULE_IOM)
#define IOMTST_PORT_MODULE                  ((volatile Ifx_P *)\
                                             ((volatile void *) &(MODULE_P00)))

/* SMU alarm timeout. The value was chosen based on following considerations:
 * The worst case number of SMU cycles before an alarm gets visible is
 * n * 2 + 20 (with n = max. number of simultaneous alarms). With a maximum
 * of 32 * 7 alarms and maximum clock ratio fSPB/fSRI = 1/4 this evaluates to
 * 1872 CPU clock cycles. To avoid the counting the number of instructions per
 * loop cycle, it is assumed that only one instruction is executed per loop
 * cycle and thus the number of CPU clock cycles is directly used as timeout
 * value:
 */
#define IOMTST_ALARM_TIMEOUT                 2000U

/* Timeout calculation for Port Rise of Fall time
   Rise/Fall time for LP pad considering weak driver = 203ns
   Maximum fspb clock is fspb max = 100Mhz
   Wait Clock cycles = 203ns/10ns ~= 21, Safe factor = 5
*/
#define IOMTST_PORT_RISE_FALL_TIMEOUT        120U

/* Macro used to read PCx bits in Pxx_IOCRx register
   Input to the macro
   - FpcPortIndex: Port Index i.e Port group index
   - FpcPortCtrlRegIndex: Port Input/Output Control Register index
     i.e 0 for IOCR0, 1 for IOCR4, 2 for IOCR8, 3 for IOCR12
   - FpcPortCtrlBitsOffset: Port control bits index
*/
#define IOMTST_GPIO_READ(FpcPortIndex, FpcPortCtrlRegIndex, \
                                                       FpcPortCtrlBitsOffset) \
    (((uint32)(((volatile Ifx_P_IOCR0*)((volatile void*)\
    (&(IOMTST_PORT_MODULE[(FpcPortIndex)].IOCR0))))[(FpcPortCtrlRegIndex)].U) \
    >> (FpcPortCtrlBitsOffset))  & ((uint32)IFX_P_IOCR0_PC0_MSK))

/*******************************************************************************
**                      Local Type Definitions                                **
*******************************************************************************/
typedef struct IomTst_BackupData
{
  uint32 IOMTST_CLC_Backup;
  uint32 IOMTST_ACCEN0_Backup;
  uint32 IOMTST_ECMSELR_Backup;
  uint32 IOMTST_ECMCCFG_Backup;
  uint32 IOMTST_FPCCTR_Mon_Backup;
  uint32 IOMTST_LAMEWS_Backup[IOMTST_LAM_BLOCKS_TO_TEST];
  uint32 IOMTST_LAMCFG_Backup[IOMTST_LAM_BLOCKS_TO_TEST];
  uint8 IOMTST_Port_Ctrl_Mon_Backup;
  Smu_AlarmActionType IomTstAlarmAction;
} IomTst_BackupDataType;

/*******************************************************************************
**                        Exported object definitions                          *
*******************************************************************************/

/*******************************************************************************
**                        Local object definitions                             *
*******************************************************************************/
/*******************************************************************************
**                        Imported function declarations                       *
*******************************************************************************/
#define IFX_IOMTST_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
/*******************************************************************************
**                        Local function prototypes                            *
*******************************************************************************/
static Sl_TstRsltType IomTst_lCheckPrerequisites
(
  const Sl_ParamSetType ParamSetIndex,
  uint32* const TstSignature
);

static Sl_TstRsltType IomTst_lInit
(
  IomTst_BackupDataType* const BackupData,
  uint32* const TstSignature
);

static Sl_TstRsltType  IomTst_lTstExecute
(
  const Sl_ParamSetType ParamSetIndex,
  IomTst_BackupDataType* const BackupData,
  uint32* const TstSignature
);

static Sl_TstRsltType IomTst_lRestore
(
  const Sl_ParamSetType ParamSetIndex,
  const IomTst_BackupDataType* const BackupData,
  uint32* const TstSignature
);

static void IomTst_lGpioWrite
(
  const Sl_ParamSetType ParamSetIndex,
  const uint8 FpcPortPullUpPullDown
);

/*******************************************************************************
**                    Local inline function definitions                        *
*******************************************************************************/

/*******************************************************************************
**                    Configuration error checking                             *
*******************************************************************************/

/*******************************************************************************
**                         Function definitions                                *
*******************************************************************************/


/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : Sl_TstRsltType IomTst_IomTst                            **
**                    (                                                       **
**                      const Sl_ParamSetType ParamSetIndex,                  **
**                      const uint8 TstSeed,                                  **
**                      uint32* const TstSignature                            **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters (in)  : ParamSetIndex - Identifies the parameter set to be      **
**                      used for test execution.                              **
**                    TstSeed - Seed to be used for generating the signature  **
**                                                                            **
** Parameters (out) : TstSignature - Test signature generated by the test     **
**                                                                            **
** Return value     : IOMTST_SUCCESS - Test succeeded                         **
**                    IOMTST_NOTEXECUTED - This error is never intentionally  **
**                      returned; if it is returned anyway, something         **
**                      very serious must be wrong                            **
**                    IOMTST_INVPARAM - Invalid parameter is sent as an       **
**                      paramter to API                                       **
**                    IOMTST_ALARMNOTSETERR - Test failed as an expected      **
**                      alarm has not occured.                                **
**                    IOMTST_SMU_STATEERR - Test initialization failed due to **
**                      an invalid run state of the SMU                       **
**                    IOMTST_SMU_ALMSTSERR - Test failed due to a SMU alarm   **
**                      which is expected to be set is already set            **
**                    IOMTST_SMU_GETALMSTSERR - Test failed because           **
**                      Smu_GetAlarmStatus returned an error                  **
**                    IOMTST_SMU_CLRALMSTSERR - Test restoration failed due to**
**                       Smu_ClearAlarmStatus returning an error              **
**                    IOMTST_SMU_GETALMACTIONERR - Test failed because        **
**                      Smu_GetAlarmAction returned an error                  **
**                    IOMTST_SMU_SETALMACTIONERR - Test failed due to         **
**                      Smu_SetAlarmAction returning an error                 **
**                                                                            **
** Description      : IomTst_IomTst is the API which is responsible for IOM   **
**                    test preparation execution and restoration. It considers**
**                    a signal(Monitor signal) for monitoring.                **
**                    For any edge on this signal, an alarm (ALM2[26] is      **
**                    expected.. Alarm occurrence is validated for all the    **
**                    configured LAM blocks.                                  **
*******************************************************************************/
Sl_TstRsltType IomTst_IomTst
(
  const Sl_ParamSetType ParamSetIndex,
  const uint8 TstSeed,
  uint32* const TstSignature
)
{
  Sl_TstRsltType Result = IOMTST_NOTEXECUTED;
  Sl_TstRsltType TempResult = IOMTST_NOTEXECUTED;
  IomTst_BackupDataType BackupData;

  /* Initialize Test Signature */
  *TstSignature = (uint32)CRC32((uint32)TEST_ID_IOM_TST, (uint32)TstSeed);

  /* Verify whether all prerequisites are met */
  Result = IomTst_lCheckPrerequisites(ParamSetIndex, TstSignature);

  /* If all the prerequisites are met */
  if (IOMTST_SUCCESS == Result)
  {
    /* Initilize SMU alram and enable IOM peripheral */
    Result = IomTst_lInit(&BackupData, TstSignature);

    /* Initialization is successfull */
    if (IOMTST_SUCCESS == Result)
    {
      /* Execute the IOM test */
      Result = IomTst_lTstExecute(ParamSetIndex, &BackupData, TstSignature);

      /* Restore all the registers which were changed during test execution */
      TempResult = IomTst_lRestore(ParamSetIndex, &BackupData, TstSignature);

      /* Restore is successfull */
      if (IOMTST_SUCCESS == Result)
      {
        /* Result of IomTst_lTstExecute is returned only if restore is
           successful */
        Result = TempResult;
      }
    }
  }

  /* Update signature with the Result */
  *TstSignature = (uint32)CRC32(*TstSignature, (uint32)Result);
  return Result;
}


/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static Sl_TstRsltType IomTst_lCheckPrerequisites        **
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
** Parameters (in)  : ParamSetIndex - Identifies the parameter set to be      **
**                      used for test execution.                              **
**                                                                            **
** Parameters (out) : TstSignature - Test signature generated by the test     **
**                                                                            **
** Return value     : IOMTST_SUCCESS - Test succeeded                         **
**                    IOMTST_NOTEXECUTED - This error is never intentionally  **
**                      returned; if it is returned anyway, something         **
**                      very serious must be wrong                            **
**                    IOMTST_INVPARAM - Invalid parameter is sent as an       **
**                      paramter to API                                       **
**                    IOMTST_SMU_STATEERR - Test initialization failed due to **
**                      an invalid run state of the SMU                       **
**                    IOMTST_SMU_GETALMSTSERR - Test failed because           **
**                      Smu_GetAlarmStatus returned an error                  **
**                    IOMTST_SMU_ALMSTSERR - Test failed due to a SMU alarm   **
**                      which is expected to be set is already set            **
**                                                                            **
** Description      : IomTst_lCheckPrerequisites performs all checks that are **
**                    required before test initialization.                    **
**                    This includes checking the configuration settings,      **
**                    the run state of the SMU as well as the current state   **
**                    of SMU alarms triggered by the test (which must not be  **
**                    set before the test is executed). .                     **
*******************************************************************************/
static Sl_TstRsltType IomTst_lCheckPrerequisites
(
  const Sl_ParamSetType ParamSetIndex,
  uint32* const TstSignature
)
{
  Sl_TstRsltType Result = IOMTST_NOTEXECUTED;
  uint32 AlarmStatus = IOMTST_ZERO;

  /* Verify ParamSetIndex is valid */
  if (ParamSetIndex >= IOMTST_CFG_PARAM_COUNT)
  {
    /* ParamSetIndex is invalid */
    Result = IOMTST_INVPARAM;
  }
  /* Verify SMU is in RUN state */
  else if (SMU_RUN_STATE != Smu_GetSmuState())
  {
    /* SMU is not in RUN state */
    Result = IOMTST_SMU_STATEERR;
  }
  /* Read the alarm status */
  else if (E_OK != Smu_GetAlarmStatus(IOMTST_ALARM_GRP, &AlarmStatus))
  {
    /* Reading of the alarm status failed */
    Result = IOMTST_SMU_GETALMSTSERR;
  }
  /* Verify SMU alarm related to Iom is in reset state */
  else if (IOMTST_ZERO != (AlarmStatus & IOMTST_ALARM))
  {
    /* IOM alarm is already set */
    Result = IOMTST_SMU_ALMSTSERR;
  }
  else
  {
    /* All the prerequisites are met */
    Result = IOMTST_SUCCESS;
  }

  /* Update signature with the Result */
  *TstSignature = (uint32)CRC32(*TstSignature, (uint32)Result);
  return Result;
}

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static Sl_TstRsltType IomTst_lInit                      **
**                    (                                                       **
**                      IomTst_BackupDataType* const BackupData,              **
**                      uint32* const TstSignature                            **
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
** Parameters (out) : *BackupData - Pointer to back up SMU configuration      **
**                    TstSignature - Test signature generated by the test     **
**                                                                            **
** Return value     : IOMTST_SUCCESS - Test succeeded                         **
**                    IOMTST_NOTEXECUTED - This error is never intentionally  **
**                      returned; if it is returned anyway, something         **
**                      very serious must be wrong                            **
**                    IOMTST_SMU_GETALMACTIONERR - Test failed because        **
**                      Smu_GetAlarmAction returned an error                  **
**                    IOMTST_SMU_SETALMACTIONERR - Test failed due to         **
**                      Smu_SetAlarmAction returning an error                 **
**                                                                            **
** Description      : IomTst_lInit stores a backup copy of SMU configuration  **
**                    settings that will be modified by the test.             **
**                    Additionally it performs all initialization steps       **
**                    required before IOM test execution.                     **
*******************************************************************************/
static Sl_TstRsltType IomTst_lInit
(
  IomTst_BackupDataType* const BackupData,
  uint32* const TstSignature
)
{
  Sl_TstRsltType Result = IOMTST_NOTEXECUTED;
  Smu_FSPActionType FspActionDummy;
  uint32 ReadBack = IOMTST_ZERO;

  /* Read the alarm action and take its backup */
  if (E_OK != Smu_GetAlarmAction(IOMTST_ALARM_GRP,
                                 IOMTST_ALARM_INDEX,
                                 &BackupData->IomTstAlarmAction,
                                 &FspActionDummy))
  {
    /* Failure in reading the alarm action */
    Result = IOMTST_SMU_GETALMACTIONERR;
  }
  else
  {
    /* Set the IOM alarm action as SMU_ALARM_ACTION_NONE */
    if (E_OK != Smu_SetAlarmAction(IOMTST_ALARM_GRP,
                                   IOMTST_ALARM_INDEX,
                                   SMU_ALARM_ACTION_NONE))
    {
    /* Failure in setting the alarm action */
      Result = IOMTST_SMU_SETALMACTIONERR;
    }
    else
    {
      /* Backup IOM_CLC register contents */
      BackupData->IOMTST_CLC_Backup = IOM_CLC.U;
      Mcal_ResetENDINIT();
      /* Enable IOM module clock */
      IOM_CLC.U =
            (((uint32)IOMTST_CLC_DISR_DISABLE << (uint8)IFX_IOM_CLC_DISR_OFF) |
             ((uint32)IOMTST_CLC_EDIS_DISABLE << (uint8)IFX_IOM_CLC_EDIS_OFF) |
             ((uint32)IOMTST_CLC_RMC_ONE << (uint8)IFX_IOM_CLC_RMC_OFF));

      Mcal_SetENDINIT();
      /* Read back the CLC register to flush the pipeline effects */
      ReadBack = IOM_CLC.U;
      UNUSED_PARAMETER(ReadBack)

      /* Backup IOM_ACCEN0 register contents */
      BackupData->IOMTST_ACCEN0_Backup = IOM_ACCEN0.U;
      Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);
      /* Enable write access */
      IOM_ACCEN0.U = IOMTST_ACCEN0_EN_WRITE;
      Mcal_SetSafetyENDINIT_Timed();

      Result = IOMTST_SUCCESS;
    }
  }

  /* Update signature with the Result */
  *TstSignature = (uint32)CRC32(*TstSignature, (uint32)Result);
  return Result;
}

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static Sl_TstRsltType  IomTst_lTstExecute               **
**                    (                                                       **
**                      const Sl_ParamSetType ParamSetIndex,                  **
**                      IomTst_BackupDataType* const BackupData,              **
**                      uint32* const TstSignature                            **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters (in)  : ParamSetIndex - Identifies the parameter set to be      **
**                      used for test execution.                              **
**                    *BackupData - Pointer to back up SMU configuration      **
**                                                                            **
** Parameters (out) : TstSignature - Test signature generated by the test     **
**                                                                            **
** Return value     : IOMTST_SUCCESS - Test succeeded                         **
**                    IOMTST_NOTEXECUTED - This error is never intentionally  **
**                      returned; if it is returned anyway, something         **
**                      very serious must be wrong                            **
**                    IOMTST_SMU_GETALMSTSERR - Test failed because           **
**                      Smu_GetAlarmStatus returned an error                  **
**                    IOMTST_ALARMNOTSETERR - Test failed as an expected      **
**                      alarm has not occured.                                **
**                    IOMTST_SMU_CLRALMSTSERR - Test restoration failed due to**
**                       Smu_ClearAlarmStatus returning an error              **
**                                                                            **
** Description      : IomTst_lTstExecute performs the actual test execution   **
**                    of IOM(Input Output Monitor).                           **
**                    The LAM is configured is such a way that any edge on    **
**                    the Monitor input will generate an SMU alarm.           **
**                    A transition is made on the Monitor input to generate   **
**                    a SMU alarm                                             **
*******************************************************************************/
static Sl_TstRsltType  IomTst_lTstExecute
(
  const Sl_ParamSetType ParamSetIndex,
  IomTst_BackupDataType* const BackupData,
  uint32* const TstSignature
)
{
  Sl_TstRsltType Result = IOMTST_NOTEXECUTED;
  uint32 AlarmStatus = IOMTST_ZERO;
  volatile uint32 IomTst_TimeOut = IOMTST_ALARM_TIMEOUT;
  volatile uint8 Temp_LamBlockIndex = (uint8)IOMTST_ZERO;
  volatile uint8 Temp_Loop = (uint8)IOMTST_ZERO;
  uint32 Temp_Var = IOMTST_ZERO;
  uint32 Temp_PCx_Value = IOMTST_ZERO;

  /* Read the configuration data */
  uint8 Temp_FpcMonBlockIndex =
                IomTst_ConfigRoot[ParamSetIndex].IomFpcMonBlockIndex;
  uint8 Temp_FpcMonPortIndex =
                IomTst_ConfigRoot[ParamSetIndex].IomFpcMonPortIndex;
  uint8 Temp_FpcMonPortCtrlRegIndex =
                IomTst_ConfigRoot[ParamSetIndex].IomFpcMonPortCtrlRegIndex;
  uint8 Temp_FpcMonPortCtrlBitsOff =
                IomTst_ConfigRoot[ParamSetIndex].IomFpcMonPortCtrlBitsOff;

  /* Backup the register contents */
  BackupData->IOMTST_ECMSELR_Backup = IOMTST_MODULE.ECMSELR.U;
  BackupData->IOMTST_ECMCCFG_Backup = IOMTST_MODULE.ECMCCFG.U;
  BackupData->IOMTST_FPCCTR_Mon_Backup = 
                                IOMTST_MODULE.FPCCTR[Temp_FpcMonBlockIndex].U;

  BackupData->IOMTST_Port_Ctrl_Mon_Backup =
            (uint8)IOMTST_GPIO_READ(Temp_FpcMonPortIndex,
                    Temp_FpcMonPortCtrlRegIndex, Temp_FpcMonPortCtrlBitsOff);

  for(Temp_Loop = (uint8)IOMTST_ZERO; Temp_Loop < IOMTST_LAM_BLOCKS_TO_TEST; \
                                                                    Temp_Loop++)
  {
    Temp_LamBlockIndex =
                  IomTst_ConfigRoot[ParamSetIndex].IomLamBlockIndex[Temp_Loop];
    BackupData->IOMTST_LAMEWS_Backup[Temp_Loop] =
                  IOMTST_MODULE.LAMEWS[Temp_LamBlockIndex].U;
    BackupData->IOMTST_LAMCFG_Backup[Temp_Loop] =
                  IOMTST_MODULE.LAMCFG[Temp_LamBlockIndex].U;
  }

  /* Configure Monitor port pin as "Input pull-down device connected" i.e
     i.e Port pin is made as LOW
  */
  IomTst_lGpioWrite(ParamSetIndex, (uint8)IOMTST_P_IOCRX_PCX_IN_PULLDOWN);

  /* Disable all the counters in event combine module */
  IOMTST_MODULE.ECMCCFG.U = IOMTST_ECMCCFG_COUNTERS_DISABLE;

  /* Configure Filter and Prescaler block */
  IOMTST_MODULE.FPCCTR[Temp_FpcMonBlockIndex].U =
                (((uint32)IOMTST_FPCCTR_CMP_THR_MIN <<
                                            (uint8)IFX_IOM_FPCCTR_CMP_OFF) |
                 ((uint32)IOMTST_FPCCTR_MOD_IMM_DEBOUNCE <<
                                            (uint8)IFX_IOM_FPCCTR_MOD_OFF) |
                 ((uint32)IOMTST_FPCCTR_ISM_PORT_IN <<
                                            (uint8)IFX_IOM_FPCCTR_ISM_OFF) |
                 ((uint32)IOMTST_FPCCTR_RTG_TIM_DEC_GLITCH <<
                                            (uint8)IFX_IOM_FPCCTR_RTG_OFF) |
                 ((uint32)IOMTST_FPCCTR_ISR_PORT_IN <<
                                            (uint8)IFX_IOM_FPCCTR_ISR_OFF));

  for(Temp_Loop = (uint8)IOMTST_ZERO; Temp_Loop < IOMTST_LAM_BLOCKS_TO_TEST;
                                                                    Temp_Loop++)
  {
    Temp_LamBlockIndex =
                IomTst_ConfigRoot[ParamSetIndex].IomLamBlockIndex[Temp_Loop];

    Temp_Var = (uint32)IOMTST_ECMSELR_CESX_SELECTED << Temp_LamBlockIndex;

    /* Select the configured LAM output for the global event generation */
    IOMTST_MODULE.ECMSELR.U = Temp_Var;

    /* Event window count threshold is set to a minimum value */
    IOMTST_MODULE.LAMEWS[Temp_LamBlockIndex].U =
                (uint32)IOMTST_LAMEWS_THR_MAX << (uint8)IFX_IOM_LAMEWS_THR_OFF;

    /* Configure Logic Analyzer Module block */
    IOMTST_MODULE.LAMCFG[Temp_LamBlockIndex].U =
                (((uint32)IOMTST_LAMCFG_IVR_NO_INVERT <<
                                            (uint8)IFX_IOM_LAMCFG_IVR_OFF) |
                 ((uint32)IOMTST_LAMCFG_IVM_NO_INVERT <<
                                            (uint8)IFX_IOM_LAMCFG_IVM_OFF) |
                 ((uint32)IOMTST_LAMCFG_MOS_MON_DIR <<
                                            (uint8)IFX_IOM_LAMCFG_MOS_OFF) |
                 ((uint32)IOMTST_LAMCFG_RMS_FREE_RUNNING <<
                                            (uint8)IFX_IOM_LAMCFG_RMS_OFF) |
                 ((uint32)IOMTST_LAMCFG_EWS_EVT_MON <<
                                            (uint8)IFX_IOM_LAMCFG_EWS_OFF) |
                 ((uint32)IOMTST_LAMCFG_EDS_EGATE_ECLR_EVT <<
                                            (uint8)IFX_IOM_LAMCFG_EDS_OFF) |
                 ((uint32)IOMTST_LAMCFG_IVW_INVERT_WDW <<
                                            (uint8)IFX_IOM_LAMCFG_IVW_OFF));

    IOMTST_MODULE.LAMCFG[Temp_LamBlockIndex].B.MCS = Temp_FpcMonBlockIndex;

    /* Read the state of the Monitor pin and toggle its state */
    Temp_PCx_Value = IOMTST_GPIO_READ(Temp_FpcMonPortIndex,
                      Temp_FpcMonPortCtrlRegIndex, Temp_FpcMonPortCtrlBitsOff);
    if (IOMTST_P_IOCRX_PCX_IN_PULLDOWN == Temp_PCx_Value)
    {
      IomTst_lGpioWrite(ParamSetIndex, (uint8)IOMTST_P_IOCRX_PCX_IN_PULLUP);
    }
    else
    {
      IomTst_lGpioWrite(ParamSetIndex, (uint8)IOMTST_P_IOCRX_PCX_IN_PULLDOWN);
    }

    /* Reload the time-out value */
    IomTst_TimeOut = IOMTST_ALARM_TIMEOUT;

    while (IomTst_TimeOut > IOMTST_ZERO)
    {
      IomTst_TimeOut = IomTst_TimeOut - IOMTST_ONE;

      if (E_OK != Smu_GetAlarmStatus(IOMTST_ALARM_GRP, &AlarmStatus))
      {
        /* Reading of the alarm status failed */
        Result = IOMTST_SMU_GETALMSTSERR;
        IomTst_TimeOut = IOMTST_ZERO;
      }
      else
      {
        if (IOMTST_ALARM != (AlarmStatus & IOMTST_ALARM))
        {
          /* Expected alarm is not set */
          Result = IOMTST_ALARMNOTSETERR;
        }
        else
        {
          if (E_OK != Smu_ClearAlarmStatus(IOMTST_ALARM_GRP,
                                           IOMTST_ALARM_INDEX))
          {
            /* Failure in alarm clear operation */
            Result = IOMTST_SMU_CLRALMSTSERR;
          }
          else
          {
            /* Alarm in set as expected */
            Result = IOMTST_SUCCESS;
          }
          IomTst_TimeOut = IOMTST_ZERO;
        }
      }
    }

    /* Disable the LAM under test */
    IOMTST_MODULE.ECMSELR.U = IOMTST_ECMSELR_CESX_DISABLE;
    IOMTST_MODULE.LAMEWS[Temp_LamBlockIndex].U = IOMTST_LAMEWS_THR_DISABLE;
    IOMTST_MODULE.LAMCFG[Temp_LamBlockIndex].U = IOMTST_LAMCFG_RESET_VAL;

    if (IOMTST_SUCCESS != Result)
    {
      /* Exit from the loop when the expected alarm is not set for
         LAM under test */
      break;
    }

  }

  /* Update signature with the Alarm Status */
  *TstSignature = (uint32)CRC32(*TstSignature,
                            (uint32)(AlarmStatus & IOMTST_ALARM));

  return (Result);
}

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static Sl_TstRsltType IomTst_lRestore                   **
**                    (                                                       **
**                      const Sl_ParamSetType ParamSetIndex,                  **
**                      const IomTst_BackupDataType* const BackupData,        **
**                      uint32* const TstSignature                            **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters (in)  : ParamSetIndex - Identifies the parameter set to be      **
**                      used for test execution.                              **
**                    *BackupData - Pointer to backed up SMU configuration    **
**                                                                            **
** Parameters (out) : TstSignature - Test signature generated by the test     **
**                                                                            **
** Return value     : IOMTST_SUCCESS - Test succeeded                         **
**                    IOMTST_NOTEXECUTED - This error is never intentionally  **
**                      returned; if it is returned anyway, something         **
**                      very serious must be wrong                            **
**                    IOMTST_SMU_SETALMACTIONERR - Test failed due to         **
**                      Smu_SetAlarmAction returning an error                 **
**                                                                            **
** Description      : IomTst_lRestore restores the value of SMU alarm actions,**
**                    IOM registers and the port register that were modified  **
**                    by the test to their original values.                   **
*******************************************************************************/
static Sl_TstRsltType IomTst_lRestore
(
  const Sl_ParamSetType ParamSetIndex,
  const IomTst_BackupDataType* const BackupData,
  uint32* const TstSignature
)
{
  Sl_TstRsltType Result = IOMTST_SUCCESS;
  uint8 Temp_LamBlockIndex = (uint8)IOMTST_ZERO;
  volatile uint8 Temp_Loop = (uint8)IOMTST_ZERO;
  /* Read the configuration data */
  uint8 Temp_FpcMonBlockIndex =
                        IomTst_ConfigRoot[ParamSetIndex].IomFpcMonBlockIndex;

  /* Restore the IOM register contents */
  IOMTST_MODULE.ECMSELR.U = BackupData->IOMTST_ECMSELR_Backup;
  IOMTST_MODULE.ECMCCFG.U = BackupData->IOMTST_ECMCCFG_Backup;
  IOMTST_MODULE.FPCCTR[Temp_FpcMonBlockIndex].U = 
                                        BackupData->IOMTST_FPCCTR_Mon_Backup;
  IOMTST_MODULE.ECMETH0.U = IOMTST_ZERO;

  for(Temp_Loop = (uint8)IOMTST_ZERO; Temp_Loop < IOMTST_LAM_BLOCKS_TO_TEST;
                                                                    Temp_Loop++)
  {
    Temp_LamBlockIndex =
                IomTst_ConfigRoot[ParamSetIndex].IomLamBlockIndex[Temp_Loop];
    IOMTST_MODULE.LAMEWS[Temp_LamBlockIndex].U =
                BackupData->IOMTST_LAMEWS_Backup[Temp_Loop];
    IOMTST_MODULE.LAMCFG[Temp_LamBlockIndex].U =
                BackupData->IOMTST_LAMCFG_Backup[Temp_Loop];
  }

  /* Restore the Port register contents */
  IomTst_lGpioWrite(ParamSetIndex, BackupData->IOMTST_Port_Ctrl_Mon_Backup);

  /* Restore the IOM register contents */
  Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);
  IOM_ACCEN0.U = BackupData->IOMTST_ACCEN0_Backup;
  Mcal_SetSafetyENDINIT_Timed();

  Mcal_ResetENDINIT();
  IOM_CLC.U = BackupData->IOMTST_CLC_Backup;
  Mcal_SetENDINIT();

  if (E_OK != Smu_SetAlarmAction(IOMTST_ALARM_GRP,
                                 IOMTST_ALARM_INDEX,
                                 BackupData->IomTstAlarmAction))
  {
    /* Failure in setting the alarm action */
    Result = IOMTST_SMU_SETALMACTIONERR;
  }

  /* Update signature with the Result */
  *TstSignature = (uint32)CRC32(*TstSignature, (uint32)Result);
  return Result;
}


/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static void IomTst_lGpioWrite                           **
**                    (                                                       **
**                      const Sl_ParamSetType ParamSetIndex,                  **
**                      const uint8 FpcPortPullUpPullDown                     **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters (in)  : ParamSetIndex - Identifies the parameter set to be      **
**                      used for test execution.                              **
**                    FpcPortPullUpPullDown - Pullup or Pulldown value        **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : IomTst_lGpioWrite write PCx bits in Pxx_IOCRx register  **
**                    based on parameter FpcPortPullUpPullDown                **
*******************************************************************************/
static void IomTst_lGpioWrite
(
  const Sl_ParamSetType ParamSetIndex,
  const uint8 FpcPortPullUpPullDown
)
{
  volatile Ifx_P_IOCR0* Base_Address;
  volatile uint8 Temp_Port_Wait = (uint8)IOMTST_PORT_RISE_FALL_TIMEOUT;
  uint8 Temp_FpcMonPortIndex =
                    IomTst_ConfigRoot[ParamSetIndex].IomFpcMonPortIndex;
  uint8 Temp_FpcMonPortCtrlRegIndex =
                    IomTst_ConfigRoot[ParamSetIndex].IomFpcMonPortCtrlRegIndex;
  uint8 Temp_FpcMonPortCtrlBitsOff =
                    IomTst_ConfigRoot[ParamSetIndex].IomFpcMonPortCtrlBitsOff;
  uint32 Reg_Val = IOMTST_ZERO;
  uint32 Reg_Val_Final = IOMTST_ZERO;
  uint32 Mask_Offset = IOMTST_ZERO;

  /* Get the IOCR0 Address */
  Base_Address = (volatile Ifx_P_IOCR0*)\
        ((volatile void*)(&(IOMTST_PORT_MODULE[Temp_FpcMonPortIndex].IOCR0)));

  /* Fetch the register value of IOCR0/IOCR4/IOCR8/IOCR12 */
  Reg_Val = Base_Address[Temp_FpcMonPortCtrlRegIndex].U;

  Mask_Offset =
            (uint32)IFX_P_IOCR0_PC0_MSK << (uint8)Temp_FpcMonPortCtrlBitsOff;

  /* Reset PCx bits in the buffer variable of IOCR register */
  Reg_Val_Final = Reg_Val & (~Mask_Offset);

  Mask_Offset =
            (uint32)FpcPortPullUpPullDown << (uint8)Temp_FpcMonPortCtrlBitsOff;

  /* Derive to final value which needs to be written into IOCR register */
  Reg_Val_Final = Reg_Val_Final | Mask_Offset;

  /* Configure PCx bits in IOCR register */
  Base_Address[Temp_FpcMonPortCtrlRegIndex].U = Reg_Val_Final;

  /* Wait for Rise/Fall time */
  while(Temp_Port_Wait > (uint8)IOMTST_ZERO)
  {
    Temp_Port_Wait = Temp_Port_Wait - (uint8)IOMTST_ONE;
  }

}

#define IFX_IOMTST_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"