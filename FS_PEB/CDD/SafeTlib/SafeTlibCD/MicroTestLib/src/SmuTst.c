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
**  $FILENAME   : SmuTst.c $                                                 **
**                                                                            **
**  $CC VERSION : \main\45 $                                                 **
**                                                                            **
**  $DATE       : 2015-11-04 $                                               **
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
**                 SMU test.                                                  **
**                                                                            **
**  REFERENCE(S) : Aurix_SafeTlib_DS_Smu_Test.docm                            **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "SmuTst.h"
#include "Mcal.h"
#include "SmuInt.h"
#include "Sl_Ipc.h"
#include "Mtl_Trap.h"
#include "ChipId.h"
#include "IfxCpu_reg.h"
#include "IfxSmu_bf.h"
#include "IfxSmu_reg.h"
#include "IfxScu_bf.h"
#include "IfxScu_reg.h"
#include "IfxSrc_bf.h"
#include "IfxSrc_reg.h"

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
#define SMUTST_ZERO                  (0x00U)
#define SMUTST_ONE                   (0x01U)
#define SMUTST_TWO                   (0x02U)

/* no trap is expected */
#define SMUTST_NO_TRAP               (0U)

#define SMUTST_NMI_TRAP_CLASS        (7U)

/* Size of Alarm action back up array */
#define SMUTST_RT_BKUP_SIZE          (6U)

/* SMU configuration unlock lock value */
#define SMU_CFG_KEY_UNLOCK           ((SMU_KEYS.U & \
                                        (unsigned_int)(0xFFFFFF00U)) | \
                                        ((unsigned_int)0xBCU))

#define SMU_CFG_KEY_TEMPLOCK         (0U)

/* Type of Service (TOS) in SRC_SMU register */
#define SRS_SMU_TOS                  ((uint8)IFX_SRC_SRCR_TOS_OFF)

/*SMU Interrupt Set flag */
#define SMUTST_INT_SET               (1U)

/*SMU Interrupt clear flag */
#define SMUTST_INT_CLEAR             (1U)

/* Configured to trigger SMU Interrupt Request 0*/
#define SMUTST_AGC_IGCS              (0x00000001U)

#define SMUTST_RT0ALARM_GRP          ((uint8)SMU_ALARM_GROUP2)
#define SMUTST_RT0ALARM_INDEX        ((uint8)SMU_ALARM_29)
#define SMUTST_RT0ALARM              (((uint32)0x01U << SMUTST_RT0ALARM_INDEX))

#define SMUTST_RT1ALARM_GRP          ((uint8)SMU_ALARM_GROUP2)
#define SMUTST_RT1ALARM_INDEX        ((uint8)SMU_ALARM_30)
#define SMUTST_RT1ALARM              (((uint32)0x01U << SMUTST_RT1ALARM_INDEX))

#define SMUTST_RTXALARM              ((uint32)SMUTST_RT0ALARM | \
                                                    (uint32)SMUTST_RT1ALARM)

#define SMUTST_SW_ALARM0             ((uint32)0x01U << SMU_ALARM_0)
#define SMUTST_SW_ALARM1             ((uint32)0x01U << SMU_ALARM_1)
#define SMUTST_SW_ALARM2             ((uint32)0x01U << SMU_ALARM_2)
#define SMUTST_SW_ALARM3             ((uint32)0x01U << SMU_ALARM_3)
#define SMUTST_SW_ALARMS             (SMUTST_SW_ALARM0 | SMUTST_SW_ALARM1 | \
                                      SMUTST_SW_ALARM2 | SMUTST_SW_ALARM3)

#define SMUTST_RTACX_GID0            (SMU_ALARM_GROUP5)
#define SMUTST_RTACX_GID1            (SMU_ALARM_GROUP5)
#define SMUTST_RTACX_GID2            (SMU_ALARM_GROUP5)
#define SMUTST_RTACX_GID3            (SMU_ALARM_GROUP5)

#define SMUTST_RTACX_ALID0           (SMU_ALARM_0)
#define SMUTST_RTACX_ALID1           (SMU_ALARM_1)
#define SMUTST_RTACX_ALID2           (SMU_ALARM_2)
#define SMUTST_RTACX_ALID3           (SMU_ALARM_3)

#define SMUTST_RTC_RT0E_ENABLE       0x01U
#define SMUTST_RTC_RT1E_ENABLE       0x01U

/* Maximum value fo RTD(recovery timer duration) */
#define SMUTST_RTC_RTD_MAX           0xFFFFFFU

/* SMU alarm timeout. The value was chosen based on following considerations:
 * The worst case number of SMU cycles before an alarm gets visible is
 * n * 2 + 20 (with n = max. number of simultaneous alarms). With a maximum
 * of 32 * 7 alarms and maximum clock ratio fSPB/fSRI = 1/4 this evaluates to
 * 1872 CPU clock cycles. To avoid the counting the number of instructions per
 * loop cycle, it is assumed that only one instruction is executed per loop
 * cycle and thus the number of CPU clock cycles is directly used as timeout
 * value:
 */
#define SMUTST_ALARM_TIMEOUT         2000U

/* - SMU_STS.B.RTS will be set on an alarm event and will be reset
     upon reception of SMU_RTStop or the timer expiry.
   - Allowed ratio of fSRI: fSPB is 1:4.
   - By default, fSRI = 100 Mhz, fSPB = 50 Mhz, i.e the ratio is 1:2
   - As per measurement, when the RTD(recovery timer duration)was set
     to 0x1F, the set status of the bit RTS can be observed.
   - When fSRI is minimum w.r.t fSRI i.e fSRI:fSPB = 1:1,
     the value of RTD has to be 2 times the default i.e 2*0x1F ~ 0x3F
   - Considering the safe factor of 5, 5*0x3F ~ 0x13F
*/
#define SMUTST_RTC_RTD_LOW           0x13FU

/* Considering safe factor of 5 i.e (5 * SMUTST_RTC_RTD_LOW)*/
#define SMUTST_RT_ALARM_TIMEOUT      0x63FU

/* Delay count to allow other cores to get the trap */
#define SMUTST_TRAP_DELAY_COUNT      0x15U

/* Offset for SRC_SMU0, bit 31 - Reserved */
#define SMUTST_SRC_SRCR_RES_OFF      (31U)
/* Mask for SRC_SMU0, bit 31 - Reserved */
#define SMUTST_SRC_SRCR_RES_MSK      (0x1U)

/* To Enable Recovery timer 0 and 1 with Low time out value */
#define SMUTST_RTC_RT01EN_RTDLOW                                               \
            (((uint32)SMUTST_RTC_RT0E_ENABLE << (uint8)IFX_SMU_RTC_RT0E_OFF) | \
             ((uint32)SMUTST_RTC_RT1E_ENABLE << (uint8)IFX_SMU_RTC_RT1E_OFF) | \
             ((uint32)SMUTST_RTC_RTD_LOW << (uint8)IFX_SMU_RTC_RTD_OFF))

/* To Enable Recovery timer 0 and 1 with Max time out value */
#define SMUTST_RTC_RT01EN_RTDMAX                                               \
            (((uint32)SMUTST_RTC_RT0E_ENABLE << (uint8)IFX_SMU_RTC_RT0E_OFF) | \
             ((uint32)SMUTST_RTC_RT1E_ENABLE << (uint8)IFX_SMU_RTC_RT1E_OFF) | \
             ((uint32)SMUTST_RTC_RTD_MAX << (uint8)IFX_SMU_RTC_RTD_OFF))

/* Configure Recovery timer 0 for Sofware alarms Group 5: 0,1,2,3 */
#define SMUTST_RTAC0                                                          \
            (((uint32)SMUTST_RTACX_GID0 << (uint8)IFX_SMU_RTAC0_GID0_OFF) |   \
             ((uint32)SMUTST_RTACX_ALID0 << (uint8)IFX_SMU_RTAC0_ALID0_OFF) | \
             ((uint32)SMUTST_RTACX_GID1 << (uint8)IFX_SMU_RTAC0_GID1_OFF) |   \
             ((uint32)SMUTST_RTACX_ALID1 << (uint8)IFX_SMU_RTAC0_ALID1_OFF) | \
             ((uint32)SMUTST_RTACX_GID2 << (uint8)IFX_SMU_RTAC0_GID2_OFF) |   \
             ((uint32)SMUTST_RTACX_ALID2 << (uint8)IFX_SMU_RTAC0_ALID2_OFF) | \
             ((uint32)SMUTST_RTACX_GID3 << (uint8)IFX_SMU_RTAC0_GID3_OFF) |   \
             ((uint32)SMUTST_RTACX_ALID3 << (uint8)IFX_SMU_RTAC0_ALID3_OFF))

/* Configure Recovery timer 1 for Sofware alarms Group 5: 0,1,2,3 */
#define SMUTST_RTAC1                                                          \
            (((uint32)SMUTST_RTACX_GID0 << (uint8)IFX_SMU_RTAC1_GID0_OFF) |   \
             ((uint32)SMUTST_RTACX_ALID0 << (uint8)IFX_SMU_RTAC1_ALID0_OFF) | \
             ((uint32)SMUTST_RTACX_GID1 << (uint8)IFX_SMU_RTAC1_GID1_OFF) |   \
             ((uint32)SMUTST_RTACX_ALID1 << (uint8)IFX_SMU_RTAC1_ALID1_OFF) | \
             ((uint32)SMUTST_RTACX_GID2 << (uint8)IFX_SMU_RTAC1_GID2_OFF) |   \
             ((uint32)SMUTST_RTACX_ALID2 << (uint8)IFX_SMU_RTAC1_ALID2_OFF) | \
             ((uint32)SMUTST_RTACX_GID3 << (uint8)IFX_SMU_RTAC1_GID3_OFF) |   \
             ((uint32)SMUTST_RTACX_ALID3 << (uint8)IFX_SMU_RTAC1_ALID3_OFF))

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
#define IFX_SMUTST_START_SEC_VAR_8BIT_ASIL_B
#include "Ifx_MemMap.h"
/* No redundant storage required, since it is used for short duration to
   ensure NMI trap occurred in SmuTst_NmiTst. */
static uint8 SmuTst_NmiTrapCount[MCAL_NO_OF_CORES];
static uint8 SmuTst_ExpectedTrap;
#define IFX_SMUTST_STOP_SEC_VAR_8BIT_ASIL_B
#include "Ifx_MemMap.h"

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
/* Type definition of backup data structure of SMU Alarm Actions
 * modified for the test */
typedef struct SmuTst_Rt_BkupDataType
{
  /* To backup alarm action for the SmuTst */
  Smu_AlarmActionType AlmActionBackup[SMUTST_RT_BKUP_SIZE];
  /* To indicate whether alarm action backup is successful or not*/
  Std_ReturnType AlmActionBackupResult[SMUTST_RT_BKUP_SIZE];
  /* SMU_RTC */
  uint32 SmuRtcBackup;
  /* SMU_RTAC0 */
  uint32 SmuRtac0Backup;
  /* SMU_RTAC1 */
  uint32 SmuRtac1Backup;
} SmuTst_Rt_BkupDataType;

/* Type definition of Alarm info data structure of SMU Alarms
 * used in test */
typedef struct SmuTst_Rt_AlarmInfoType
{
  /* Alarm group */
  uint8 AlmGrp;
  /* Alarm ID */
  uint8 AlmId;
  /* Dummy variable to ensure even address alignment */
  uint32 Reserved;
}SmuTst_Rt_AlarmInfoType;

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

#define IFX_SMUTST_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
static Sl_TstRsltType SmuTst_lRtInit
(
  SmuTst_Rt_BkupDataType * const RtBkupData,
  const SmuTst_Rt_AlarmInfoType *RtAlarmInfo,
  uint32* const TstSignature
);

static Sl_TstRsltType SmuTst_lRtRestore
(
 const SmuTst_Rt_BkupDataType * const RtBkupData,
 const SmuTst_Rt_AlarmInfoType *RtAlarmInfo,
 uint32* const TstSignature
);

static Sl_TstRsltType SmuTst_lRtTimeoutTst
(
  uint32* const TstSignature
);

static Sl_TstRsltType SmuTst_lRtStopTst
(
  uint32* const TstSignature
);

static Sl_TstRsltType SmuTst_lRtMissedEventTst
(
  uint32* const TstSignature
);

static void SmuTst_lRtInitRtRegs(const uint32 SmuRtcValue);

static boolean SmuTst_lNmiTrapHandler (const uint32 trapID);

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : Sl_TstRsltType SmuTst_NmiTst                            **
**                    (                                                       **
**                      const Sl_ParamSetType ParamSetIndex,                  **
**                      const uint8 TstSeed,                                  **
**                      uint32* const TstSignature                            **
**                    }                                                       **
**                                                                            **
** Service ID       : None                                                    **
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
** Return value     : SMUTST_NMI_SUCCESS:  Test succeeded                     **
**                    SMUTST_NMI_NOTEXECUTED: This error is never             **
**                      intentionally returned, if it is returned anyway,     **
**                      something must be seriously wrong                     **
**                    SMUTST_NMI_TRAPERR: Test failed due the non-occurrence/ **
**                      multiple-occurrences of trap                          **
**                    SMUTST_NMI_TRAPREGERR:  Test failed due failure in      **
**                      registering trap handler                              **
**                    SMUTST_NMI_TRAPUNREGERR: Test failed due failure in     **
**                      un-registering trap handler                           **
**                    SMUTST_NMI_SMU_STATEERR: Test failed due to invalid     **
**                      state of the SMU                                      **
**                    SMUTST_NMI_SMU_ALMSTSERR: Test failed since a SMU alarm **
**                      is already set                                        **
**                    SMUTST_NMI_SMU_GETALMACTIONERR: Test failed because     **
**                      Smu_GetAlarmAction returned an error                  **
**                    SMUTST_NMI_SMU_SETALMACTIONERR:  Test failed because    **
**                      Smu_SetAlarmAction returned an error                  **
**                    SMUTST_NMI_SMU_SETALMSTSERR:  Test failed because       **
**                      Smu_SetAlarmStatus returned an error                  **
**                    SMUTST_NMI_SMU_GETALMSTSERR:  Test failed because       **
**                      Smu_GetAlarmStatus returned an error                  **
**                    SMUTST_NMI_SMU_CLRALMSTSERR: Test failed because        **
**                      Smu_ClearAlarmStatus returned an error                **
**                                                                            **
** Description      : SmuTst_NmiTst is the API which validates the occurrence **
**                    of NMI on an alarm. A SMU software alarm action is      **
**                    configured to generate an NMI. The software alarm is    **
**                    set and the occurrence of NMI is validated.             **
*******************************************************************************/
Sl_TstRsltType SmuTst_NmiTst
(
  const Sl_ParamSetType ParamSetIndex,
  const uint8 TstSeed,
  uint32* const TstSignature
)
{
  Sl_TstRsltType Result = (Sl_TstRsltType)SMUTST_NMI_NOTEXECUTED;
  Smu_AlarmActionType AlarmActionBkup = (Smu_AlarmActionType)SMUTST_ZERO;
  Smu_FSPActionType FspActionDummy = (Smu_FSPActionType)SMUTST_ZERO;
  uint32 AlarmStatus = SMUTST_ZERO;
  uint8 TrapDisSmutBackup = (uint8)SMUTST_ZERO;
  volatile uint8 TrapDelayCount = SMUTST_TRAP_DELAY_COUNT;

  /* Required to avoid compiler warning */
  UNUSED_PARAMETER(ParamSetIndex)

  /* Initialize Test Signature */
  *TstSignature = (uint32)CRC32((uint32)TEST_ID_SMU_TST_NMI,(uint32)TstSeed);

  /* Verify SMU is in RUN state */
  if (SMU_RUN_STATE != Smu_GetSmuState())
  {
    /* Error condition: SMU state is incorrect */
    Result = (Sl_TstRsltType)SMUTST_NMI_SMU_STATEERR;
  }
  else if (E_OK != Smu_GetAlarmStatus(SMU_ALARM_GROUP5, &AlarmStatus))
  {
    /* Error condition: Reading of the alarm status failed */
    Result = (Sl_TstRsltType)SMUTST_NMI_SMU_GETALMSTSERR;
  }
  else if (AlarmStatus & SMUTST_SW_ALARM2)
  {
    /* Error condition: Alarm already set */
    Result = (Sl_TstRsltType)SMUTST_NMI_SMU_ALMSTSERR;
  }
  else
  {
    /* Trap is not expected at this point of time */
    SmuTst_ExpectedTrap = (uint8)SMUTST_NO_TRAP;

    /* Register trap handler for all cores since NMI gets registered for all
     * available cores irrespective of the core states.
     * Note:
     * 1) Sl_Init should have been done on the other running cores for trap
     *    table to be initialized for these cores
     * 2) A core may not be activated/used at all by user; hence
     *    TRAP_RegisterTrapHandlerAllCores only validates for executing core
     */
    /* Initialize with error condition: Failure in registering trap handler
       on all cores */
    Result = (Sl_TstRsltType)SMUTST_NMI_TRAPREGERR;
    if (TRAP_E_SUCCESS ==
             TRAP_RegisterTrapHandlerAllCores(SMUTST_NMI_TRAP_CLASS,
                                              &SmuTst_lNmiTrapHandler))
    {

      /* Take a backup of SMUT field of TRAPDIS register*/
      TrapDisSmutBackup = (uint8)SCU_TRAPDIS.B.SMUT;

      /* Take a backup of alarm action setting of ALM5[2] */
      if (E_OK != Smu_GetAlarmAction(SMU_ALARM_GROUP5,
                                     SMU_ALARM_2,
                                     &AlarmActionBkup,
                                     &FspActionDummy))
      {
        /* Error condition: SMU get alarm action error */
        Result = (Sl_TstRsltType)SMUTST_NMI_SMU_GETALMACTIONERR;
      }
      /* Configure ALM5[2] to generate NMI trap */
      else if (E_OK != Smu_SetAlarmAction(SMU_ALARM_GROUP5, SMU_ALARM_2, \
                                                      SMU_ALARM_ACTION_NMI))
      {
        /* Error condition: SMU set alarm action error */
        Result = (Sl_TstRsltType)SMUTST_NMI_SMU_SETALMACTIONERR;
      }
      else
      {
        /* Clear SMU Alarm Trap Request flag */
        SCU_TRAPCLR.B.SMUT = SMUTST_ONE;

        Mcal_ResetENDINIT();
        /* Enable SMU Alarm Trap Request */
        SCU_TRAPDIS.B.SMUT = SMUTST_ZERO;
        Mcal_SetENDINIT();

        /* Initialize NMI trap counter for all the cores */
        SmuTst_NmiTrapCount[SMUTST_ZERO] = (uint8)SMUTST_ZERO;
        #if((CHIP_ID == 26U) || (CHIP_ID == 27U) || (CHIP_ID == 29U))
        SmuTst_NmiTrapCount[SMUTST_ONE] = (uint8)SMUTST_ZERO;
        #if((CHIP_ID == 27U) || (CHIP_ID == 29U))
        SmuTst_NmiTrapCount[SMUTST_TWO] = (uint8)SMUTST_ZERO;
        #endif
        #endif

        /* Set the flag that trap is expected */
        SmuTst_ExpectedTrap = SMUTST_NMI_TRAP_CLASS;

        /* Initialize with error condition: SMU set alarm status error */
        Result = (Sl_TstRsltType)SMUTST_NMI_SMU_SETALMSTSERR;

        /* Trigger alarm: ALM5[2] */
        if (E_OK == Smu_SetAlarmStatus(SMU_ALARM_GROUP5, SMU_ALARM_2))
        {
          /* Initialize with error condition: NMI Trap has not occurred */
          Result = (Sl_TstRsltType)SMUTST_NMI_TRAPERR;

          DSYNC();

          /* Delay to allow other cores to get the trap */
          while (TrapDelayCount > (uint8)SMUTST_ZERO)
          {
            TrapDelayCount = TrapDelayCount - (uint8)SMUTST_ONE;
          }

          /* Verify whether trap status indicates trap has occurred and the
             trap counter is set to one for all the cores */
          if ((SMUTST_ONE == SCU_TRAPSTAT.B.SMUT) && \
              ((SMUTST_ONE == SmuTst_NmiTrapCount[SMUTST_ZERO])
               #if((CHIP_ID == 26U) || (CHIP_ID == 27U) || (CHIP_ID == 29U))
               && (SMUTST_ONE == SmuTst_NmiTrapCount[SMUTST_ONE])
               #if((CHIP_ID == 27U) || (CHIP_ID == 29U))
               && (SMUTST_ONE == SmuTst_NmiTrapCount[SMUTST_TWO])
               #endif
               #endif
             ))
          {
            Result = (Sl_TstRsltType)SMUTST_NMI_SUCCESS;
          }

          /* Clear SMU Alarm Trap Request flag */
          SCU_TRAPCLR.B.SMUT = SMUTST_ONE;

          /* Clear alarm status: ALM5[2] */
          if (E_OK != Smu_ClearAlarmStatus(SMU_ALARM_GROUP5, SMU_ALARM_2))
          {
            /* Error condition: SMU clear alarm status error */
            Result = (Sl_TstRsltType)SMUTST_NMI_SMU_CLRALMSTSERR;
          }
        }

        /* Restore the alarm action setting of ALM5[2] */
        if (E_OK != Smu_SetAlarmAction(SMU_ALARM_GROUP5, SMU_ALARM_2, \
                                                        AlarmActionBkup))
        {
          /* Error condition: SMU set alarm action error */
          Result = (Sl_TstRsltType)SMUTST_NMI_SMU_SETALMACTIONERR;
        }
      }

      /* Remove NMI trap handling */
      if (TRAP_E_SUCCESS !=
                  TRAP_UnregisterTrapHandlerAllCores(SMUTST_NMI_TRAP_CLASS))
      {
        /* Error condition: Failure in unregistering trap handler */
        Result = (Sl_TstRsltType)SMUTST_NMI_TRAPUNREGERR;
      }

      /* Clear the flag to indicate that trap is not expected anymore */
      SmuTst_ExpectedTrap = (uint8)SMUTST_NO_TRAP;

      Mcal_ResetENDINIT();
      /* Restore SMU Alarm Trap Request */
      SCU_TRAPDIS.B.SMUT = TrapDisSmutBackup;
      Mcal_SetENDINIT();
    }
  }

  /* Add final test result to test signature */
  *TstSignature = (uint32)CRC32(*TstSignature, (uint32)Result);

  return Result;
}

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : Sl_TstRsltType SmuTst_IrqTst                            **
**                    (                                                       **
**                      const Sl_ParamSetType ParamSetIndex,                  **
**                      const uint8 TstSeed,                                  **
**                      uint32* const TstSignature                            **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
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
** Return value     : SMUTST_IRQ_SUCCESS:  Test succeeded                     **
**                    SMUTST_IRQ_NOTEXECUTED: This error is never             **
**                      intentionally returned, if it is returned anyway,     **
**                      something must be seriously wrong                     **
**                    SMUTST_IRQ_INTNOTSETERR: Test failed due the            **
**                      non-occurrence of interrupt                           **
**                    SMUTST_IRQ_SMU_STATEERR:  Test failed due to invalid    **
**                      state of the SMU                                      **
**                    SMUTST_IRQ_SMU_ALMSTSERR: Test failed since a SMU alarm **
**                      is already set                                        **
**                    SMUTST_IRQ_SMU_GETALMACTIONERR: Test failed because     **
**                      Smu_GetAlarmAction returned an error                  **
**                    SMUTST_IRQ_SMU_SETALMACTIONERR:  Test failed because    **
**                      Smu_SetAlarmAction returned an error                  **
**                    SMUTST_IRQ_SMU_SETALMSTSERR:  Test failed because       **
**                      Smu_SetAlarmStatus returned an error                  **
**                    SMUTST_IRQ_SMU_GETALMSTSERR:  Test failed because       **
**                      Smu_GetAlarmStatus returned an error                  **
**                    SMUTST_IRQ_SMU_CLRALMSTSERR: Test failed because        **
**                      Smu_ClearAlarmStatus returned an error                **
**                                                                            **
** Description      : SmuTst_IrqTst is the API which validates the occurrence **
**                    of interrupt on a alarm. A SMU software alarm action is **
**                    configured to generate an interrupt. The software alarm **
**                    is set and the setting of Service Request Flag(SRR) in  **
**                    the register SRC_SMU0 is validated                      **
*******************************************************************************/
Sl_TstRsltType SmuTst_IrqTst
(
  const Sl_ParamSetType ParamSetIndex,
  const uint8 TstSeed,
  uint32* const TstSignature
)
{
  Sl_TstRsltType Result = (Sl_TstRsltType)SMUTST_IRQ_NOTEXECUTED;
  Smu_AlarmActionType AlarmActionBkup = (Smu_AlarmActionType)SMUTST_ZERO;
  Smu_FSPActionType FspActionDummy = (Smu_FSPActionType)SMUTST_ZERO;
  uint8 CoreId = (uint8)SMUTST_ZERO;
  uint32 SrcSmu0Backup = SMUTST_ZERO;
  uint32 SmuAgcBackup = SMUTST_ZERO;
  uint32 AlarmStatus = SMUTST_ZERO;

  /* Required to avoid compiler warning */
  UNUSED_PARAMETER(ParamSetIndex)

  /* Initialize Test Signature */
  *TstSignature = (uint32)CRC32((uint32)TEST_ID_SMU_TST_IRQ,(uint32)TstSeed);

  /* Verify SMU is in RUN state */
  if (SMU_RUN_STATE != Smu_GetSmuState())
  {
    /* Error condition: SMU state is incorrect */
    Result = (Sl_TstRsltType)SMUTST_IRQ_SMU_STATEERR;
  }
  else if (E_OK != Smu_GetAlarmStatus(SMU_ALARM_GROUP5, &AlarmStatus))
  {
    /* Error condition: Reading of the alarm status failed */
    Result = (Sl_TstRsltType)SMUTST_IRQ_SMU_GETALMSTSERR;
  }
  else if (AlarmStatus & SMUTST_SW_ALARM3)
  {
    /* Error condition: Alarm already set */
    Result = (Sl_TstRsltType)SMUTST_IRQ_SMU_ALMSTSERR;
  }
  else
  {
    /* Take a backup of alarm action setting of ALM5[3] */
    if (E_OK != Smu_GetAlarmAction(SMU_ALARM_GROUP5,
                                   SMU_ALARM_3,
                                   &AlarmActionBkup,
                                   &FspActionDummy))
    {
      /* Error condition: SMU get alarm action error */
      Result = (Sl_TstRsltType)SMUTST_IRQ_SMU_GETALMACTIONERR;
    }
    else
    {
      /* Take a backup of SMU_AGC register */
      SmuAgcBackup = SMU_AGC.U;

      /* Read the current active core Id */
      CoreId = (uint8)MFCR(CPU_CORE_ID);

      /* Take a backup of SRC_SMU0 register */
      SrcSmu0Backup = SRC_SMU0.U;

      /* Clear SMU Interrupts,
         Service request is disabled ,
         Service priority number is set to Zero
         The current running core service is initiated
         Also ensure bit 31, which is reserved is written with 0
      */
      SRC_SMU0.U = \
        (unsigned_int)(((SRC_SMU0.U) &
        (~(((uint32)IFX_SRC_SRCR_SRE_MSK << (uint8)IFX_SRC_SRCR_SRE_OFF) |
        ((uint32)IFX_SRC_SRCR_SRPN_MSK << (uint8)IFX_SRC_SRCR_SRPN_OFF) |
        ((uint32)IFX_SRC_SRCR_TOS_MSK << (uint8)SRS_SMU_TOS) |
        ((uint32)SMUTST_SRC_SRCR_RES_MSK << (uint8)SMUTST_SRC_SRCR_RES_OFF)))) |
        (((uint32)CoreId << (uint8)SRS_SMU_TOS) |
        ((uint32)SMUTST_INT_CLEAR << (uint8)IFX_SRC_SRCR_CLRR_OFF)));

      /* disable the write-protection for registers */
      Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);
      /* Enable SMU configuration */
      SMU_KEYS.U = (unsigned_int)SMU_CFG_KEY_UNLOCK;
      /* Interrupt Generation Configuration Set 0,1,2  */
      SMU_AGC.U = SMUTST_AGC_IGCS;
      /* After configuration set temporary lock of SMU configuration */
      SMU_KEYS.U = (uint32)SMU_CFG_KEY_TEMPLOCK;
      /* Restore back the write-protection for registers */
      Mcal_SetSafetyENDINIT_Timed();

      /* Initialize with error condition: SMU set alarm action error */
      Result = (Sl_TstRsltType)SMUTST_IRQ_SMU_SETALMACTIONERR;

      /* Set the alarm action setting of ALM5[3] to trigger SMU int req 0  */
      if (E_OK == Smu_SetAlarmAction(SMU_ALARM_GROUP5, SMU_ALARM_3, \
                                                      SMU_ALARM_ACTION_IGCS0))
      {
        /* Initialize with error condition: SMU set alarm status error */
        Result = (Sl_TstRsltType)SMUTST_IRQ_SMU_SETALMSTSERR;

        /* Trigger alarm: ALM5[3] */
        if (E_OK == Smu_SetAlarmStatus(SMU_ALARM_GROUP5, SMU_ALARM_3))
        {
          /* Initialize with error condition: Expected interrupt in not set */
          Result = (Sl_TstRsltType)SMUTST_IRQ_INTNOTSETERR;

          /* Check whether Service request flag indicates service is pending*/
          if (SRC_SMU0.B.SRR == SMUTST_INT_SET)
          {
            /* Clear SRR bit field
               Also ensure bit 31, which is reserved is written with 0
            */
            SRC_SMU0.U = (unsigned_int)(((SRC_SMU0.U) |
                         ((uint32)SMUTST_INT_CLEAR << \
                                    (uint8)IFX_SRC_SRCR_CLRR_OFF)) &
                         (~((uint32)SMUTST_SRC_SRCR_RES_MSK << \
                                    (uint8)SMUTST_SRC_SRCR_RES_OFF)));

            Result = (Sl_TstRsltType)SMUTST_IRQ_SUCCESS;
          }

          /* Clear alarm status: ALM5[3] */
          if (E_OK != Smu_ClearAlarmStatus(SMU_ALARM_GROUP5, SMU_ALARM_3))
          {
            /* Error condition: SMU clear alarm status error */
            Result = (Sl_TstRsltType)SMUTST_IRQ_SMU_CLRALMSTSERR;
          }
        }
        /* Restore the alarm action setting of ALM5[3] */
        if (E_OK != Smu_SetAlarmAction(SMU_ALARM_GROUP5, SMU_ALARM_3, \
                                                        AlarmActionBkup))
        {
          /* Error condition: SMU set alarm action error */
          Result = (Sl_TstRsltType)SMUTST_IRQ_SMU_SETALMACTIONERR;
        }
      }

      /* Restore SMU configuration */
      SRC_SMU0.U = SrcSmu0Backup;

      /* disable the write-protection for registers */
      Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);
      /* Enable SMU configuration */
      SMU_KEYS.U = (unsigned_int)SMU_CFG_KEY_UNLOCK;
      SMU_AGC.U = SmuAgcBackup;
       /* After configuration set temporary lock of SMU configuration */
      SMU_KEYS.U = (uint32)SMU_CFG_KEY_TEMPLOCK;
      /* Restore back the write-protection for registers */
      Mcal_SetSafetyENDINIT_Timed();
    }
  }

  /* Add final test result to test signature */
  *TstSignature = (uint32)CRC32(*TstSignature, (uint32)Result);

  return Result;
}

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : Sl_TstRsltType SmuTst_RtTst                             **
**                    (                                                       **
**                      const Sl_ParamSetType ParamSetIndex,                  **
**                      const uint8 TstSeed,                                  **
**                      uint32* const TstSignature                            **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
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
** Return value     : SMUTST_RT_SUCCESS:  Test succeeded                      **
**                    SMUTST_RT_NOTEXECUTED: This error is never              **
**                      intentionally returned, if it is returned anyway,     **
**                      something must be seriously wrong                     **
**                    SMUTST_RT_TIMEOUT_RTRUNERR: RT timeout test failed, as  **
**                      recovery timer status is not set                      **
**                    SMUTST_RT_TIMEOUT_ALMNOTSETERR: RT timeout test failed, **
**                      as alarm is not set on RT timeout                     **
**                    SMUTST_RT_STOP_RTRUNERR: RT stop test failed, as        **
**                      recovery timer status is not set                      **
**                    SMUTST_RT_STOP_RTSTOPERR: RT stop test failed because   **
**                      Smu_RTStop returned an error                          **
**                    SMUTST_RT_STOP_ALMSETERR: RT stop test failed,          **
**                      as alarm is unexpectedly set.                         **
**                    SMUTST_RT_STOP_STOPERR: RT stop test failed, as         **
**                     recovery timer status is not reset                     **
**                    SMUTST_RT_MISSEDEVT_RTRUNERR: RT missed event test      **
**                     failed, recovery timer status is not set               **
**                    SMUTST_RT_MISSEDEVT_RTSTOPERR: RT missed event test     **
**                      failed because Smu_RTStop returned an error           **
**                    SMUTST_RT_MISSEDEVT_ERR: RT missed event test, as the   **
**                     alarm does not trigger missed event                    **
**                    SMUTST_RT_SMU_STATEERR:  Test failed due to invalid     **
**                      state of the SMU                                      **
**                    SMUTST_RT_SMU_ALMSTSERR: Test failed since a SMU alarm  **
**                      is already set                                        **
**                    SMUTST_RT_SMU_GETALMACTIONERR: Test failed because      **
**                      Smu_GetAlarmAction returned an error                  **
**                    SMUTST_RT_SMU_SETALMACTIONERR:  Test failed because     **
**                      Smu_SetAlarmAction returned an error                  **
**                    SMUTST_RT_SMU_SETALMSTSERR:  Test failed because        **
**                      Smu_SetAlarmStatus returned an error                  **
**                    SMUTST_RT_SMU_GETALMSTSERR:  Test failed because        **
**                      Smu_GetAlarmStatus returned an error                  **
**                    SMUTST_RT_SMU_CLRALMSTSERR: Test failed because         **
**                      Smu_ClearAlarmStatus returned an error                **
**                                                                            **
** Description      : SmuTst_RtTst is the API which validates the SMU         **
**                    Recovery Timer (RT) functionality.                      **
**                     - Verifies timeout of RT leads to an alarm             **
**                     - Verifies stopping of RT does not lead to an alarm    **
**                     - Verifies all 4 alarms configured for RT will trigger **
**                       the RT                                               **
**                     - Verifies Missed event is SET if another alarm        **
**                       configured for RT is raised when RT is already active**
*******************************************************************************/
Sl_TstRsltType SmuTst_RtTst
(
  const Sl_ParamSetType ParamSetIndex,
  const uint8 TstSeed,
  uint32* const TstSignature
)
{
  Sl_TstRsltType Result = (Sl_TstRsltType)SMUTST_RT_NOTEXECUTED;
  Sl_TstRsltType TempResult = (Sl_TstRsltType)SMUTST_RT_NOTEXECUTED;
  uint32 AlarmStatusGrp2 = SMUTST_ZERO;
  uint32 AlarmStatusGrp5 = SMUTST_ZERO;
  Std_ReturnType Prerequisites = (Std_ReturnType)E_NOT_OK;
  SmuTst_Rt_BkupDataType RtBkupData;

  /* The structure contains SMU alarm group and index of the alarms used
     by SmuTst */
  const SmuTst_Rt_AlarmInfoType kRtAlarmInfo[SMUTST_RT_BKUP_SIZE] =
                    {
                      { SMU_ALARM_GROUP5, SMU_ALARM_0, SMUTST_ZERO},
                      { SMU_ALARM_GROUP5, SMU_ALARM_1, SMUTST_ZERO},
                      { SMU_ALARM_GROUP5, SMU_ALARM_2, SMUTST_ZERO},
                      { SMU_ALARM_GROUP5, SMU_ALARM_3, SMUTST_ZERO},
                      { SMU_ALARM_GROUP2, SMU_ALARM_29, SMUTST_ZERO},
                      { SMU_ALARM_GROUP2, SMU_ALARM_30, SMUTST_ZERO}
                    };

  /* Required to avoid compiler warning */
  UNUSED_PARAMETER(ParamSetIndex)

  /* Initialize Test Signature */
  *TstSignature = (uint32)CRC32((uint32)TEST_ID_SMU_TST_RT,(uint32)TstSeed);

  /* Verify SMU is in RUN state */
  if (SMU_RUN_STATE != Smu_GetSmuState())
  {
    /* Error condition: SMU state is incorrect */
    Result = (Sl_TstRsltType)SMUTST_RT_SMU_STATEERR;
  }
  else
  {
    /* Initialize with error condition: SMU get alarm status error */
    Result = (Sl_TstRsltType)SMUTST_RT_SMU_GETALMSTSERR;
    if (E_OK == Smu_GetAlarmStatus(SMU_ALARM_GROUP2, &AlarmStatusGrp2))
    {
      /* Initialize with error condition: Alarm already set */
      Result = (Sl_TstRsltType)SMUTST_RT_SMU_ALMSTSERR;
      if (SMUTST_ZERO == (AlarmStatusGrp2 & SMUTST_RTXALARM))
      {
        /* Initialize with error condition: SMU get alarm status error */
        Result = (Sl_TstRsltType)SMUTST_RT_SMU_GETALMSTSERR;
        if (E_OK == Smu_GetAlarmStatus(SMU_ALARM_GROUP5, &AlarmStatusGrp5))
        {
          /* Initialize with error condition: Alarm already set */
          Result = (Sl_TstRsltType)SMUTST_RT_SMU_ALMSTSERR;
          if (SMUTST_ZERO == (AlarmStatusGrp5 & SMUTST_SW_ALARMS))
          {
            Prerequisites = (Std_ReturnType)E_OK;
          }
        }
      }
    }

    /* Proceed further only when prerequisites(alarms used in the test are
       not set) are met */
    if (E_OK == Prerequisites)
    {
      /* Execute Init function for SmuTst_RtTst */
      Result = SmuTst_lRtInit( &RtBkupData,
                               &kRtAlarmInfo[SMUTST_ZERO],
                               TstSignature
                             );

      /* Proceed further only when Init function is successful */
      if (SMUTST_RT_SUCCESS == Result)
      {
        /* Execute Timeout test */
        Result = SmuTst_lRtTimeoutTst(TstSignature);

        /* Proceed further only when Timeout test is successful */
        if (SMUTST_RT_SUCCESS == Result)
        {
          /* Execute RtStop test */
          Result = SmuTst_lRtStopTst(TstSignature);

          /* Proceed further only when RtStop test is successful */
          if (SMUTST_RT_SUCCESS == Result)
          {
            /* Execute Missed event test */
            Result = SmuTst_lRtMissedEventTst(TstSignature);
          }
        }
      }

      /* Execute Restore function for SmuTst_RtTst */
      TempResult = SmuTst_lRtRestore(&RtBkupData,
                                    &kRtAlarmInfo[SMUTST_ZERO],
                                    TstSignature);

      /* If SMU RT tests are successful, result of the SmuTst_lRtRestore
         is returned else result of SMU RT tests takes priority*/
      if (SMUTST_RT_SUCCESS == Result)
      {
        Result = TempResult;
      }
    }
  }

  /* Add final test result to test signature */
  *TstSignature = (uint32)CRC32(*TstSignature, (uint32)Result);

  return Result;
}

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static Sl_TstRsltType SmuTst_lRtInit                    **
**                    (                                                       **
**                      SmuTst_Rt_BkupDataType * const RtBkupData,            **
**                      const SmuTst_Rt_AlarmInfoType *RtAlarmInfo,           **
**                      uint32* const TstSignature                            **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters (in)  : RtAlarmInfo[][] - Alarm information of the              **
**                      of the alarms which needs back up                     **
**                                                                            **
** Parameters (out) : *RtBkupData - Pointer to the backup data                **
**                    TstSignature - Test signature generated by the test     **
**                                                                            **
** Return value     : SMUTST_RT_SUCCESS:  Test succeeded                      **
**                    SMUTST_RT_NOTEXECUTED: This error is never              **
**                      intentionally returned, if it is returned anyway,     **
**                      something must be seriously wrong                     **
**                    SMUTST_RT_SMU_GETALMACTIONERR: Test failed because      **
**                      Smu_GetAlarmAction returned an error                  **
**                    SMUTST_RT_SMU_SETALMACTIONERR:  Test failed because     **
**                      Smu_SetAlarmAction returned an error                  **
**                                                                            **
** Description      : SmuTst_lRtInit takes the backup of the alarm action of  **
**                    the alarms which are modified during the execution of   **
**                    the test                                                **
*******************************************************************************/
static Sl_TstRsltType SmuTst_lRtInit
(
  SmuTst_Rt_BkupDataType * const RtBkupData,
  const SmuTst_Rt_AlarmInfoType *RtAlarmInfo,
  uint32* const TstSignature
)
{
  Sl_TstRsltType Result = (Sl_TstRsltType)SMUTST_RT_NOTEXECUTED;
  Std_ReturnType SmuResult = (Std_ReturnType)E_NOT_OK;
  uint8 SmuAlarmId = (uint8)SMUTST_ZERO;
  Smu_FSPActionType SmuAlarmFspAction = (Smu_FSPActionType)SMUTST_ZERO;

  /* Backup settings for Recovery Timers */
  RtBkupData->SmuRtcBackup = SMU_RTC.U;
  RtBkupData->SmuRtac0Backup = SMU_RTAC0.U;
  RtBkupData->SmuRtac1Backup = SMU_RTAC1.U;

  /* SMU alarm action of all the alarms used by SmuTst are backed up
     and then set as NONE */
  do
  {
    /* Initialize with error condition: Alarm action backup is not successful */
    RtBkupData->AlmActionBackupResult[SmuAlarmId] = (Std_ReturnType)E_NOT_OK;

    /* Take a backup of alarm action setting of alarms in RtAlarmInfo */
    if (E_OK != Smu_GetAlarmAction(RtAlarmInfo[SmuAlarmId].AlmGrp,
                                   RtAlarmInfo[SmuAlarmId].AlmId,
                                   &(RtBkupData->AlmActionBackup[SmuAlarmId]),
                                   &SmuAlarmFspAction))
    {
      SmuResult = (Std_ReturnType)E_NOT_OK;

      /* Error condition: SMU get alarm action error */
      Result = (Sl_TstRsltType)SMUTST_RT_SMU_GETALMACTIONERR;
    }
    /* Set the alarm action setting of alarms in RtAlarmInfo as NONE */
    else if (E_OK != Smu_SetAlarmAction(RtAlarmInfo[SmuAlarmId].AlmGrp,
                                       RtAlarmInfo[SmuAlarmId].AlmId,
                                       SMU_ALARM_ACTION_NONE))
    {
      SmuResult = (Std_ReturnType)E_NOT_OK;

      /* Alarm action backup is successful */
      RtBkupData->AlmActionBackupResult[SmuAlarmId] = (Std_ReturnType)E_OK;

      /* Error condition: SMU set alarm action error */
      Result = (Sl_TstRsltType)SMUTST_RT_SMU_SETALMACTIONERR;

      /* This is an exit point of the loop. Even though the backup action
         result is successful for this element, the backup action result
         has to be E_NOT_OK for the next element in the array so that the
         restoration of the alarm action stops in SmuTst_lRtRestore*/
      if (SmuAlarmId < (uint8)(SMUTST_RT_BKUP_SIZE - SMUTST_ONE))
      {
        SmuAlarmId = SmuAlarmId + (uint8)SMUTST_ONE;
        RtBkupData->AlmActionBackupResult[SmuAlarmId] =
                                                    (Std_ReturnType)E_NOT_OK;
      }
    }
    else
    {
      /* Alarm action backup is successful */
      RtBkupData->AlmActionBackupResult[SmuAlarmId] = (Std_ReturnType)E_OK;

      SmuAlarmId++;
      SmuResult = (Std_ReturnType)E_OK;
      Result = (Sl_TstRsltType)SMUTST_RT_SUCCESS;
    }
  }while((SmuResult == E_OK) && (SmuAlarmId < SMUTST_RT_BKUP_SIZE));

  /* Add SmuResult to test signature
     In case of Success: SmuResult = 0x00 */
  *TstSignature = (uint32)CRC32(*TstSignature, (uint32)SmuResult);

  return Result;
}

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static Sl_TstRsltType SmuTst_lRtRestore                 **
**                    (                                                       **
**                     const SmuTst_Rt_BkupDataType *const RtBkupData,        **
**                     const SmuTst_Rt_AlarmInfoType *RtAlarmInfo,            **
**                     uint32* const TstSignature                             **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters (in)  : *RtBkupData - Pointer to the backup data                **
**                    RtAlarmInfo[][] - Contains Alarm information            **
**                      of the alarms which needs back up                     **
**                                                                            **
** Parameters (out) : TstSignature - Test signature generated by the test     **
**                                                                            **
** Return value     : SMUTST_RT_SUCCESS:  Test succeeded                      **
**                    SMUTST_RT_NOTEXECUTED: This error is never              **
**                      intentionally returned, if it is returned anyway,     **
**                      something must be seriously wrong                     **
**                    SMUTST_RT_SMU_SETALMACTIONERR:  Test failed because     **
**                      Smu_SetAlarmAction returned an error                  **
**                                                                            **
** Description      : SmuTst_lRtRestore restores the alarm action of the      **
**                    alarms which are modified during the execution of test  **
*******************************************************************************/
static Sl_TstRsltType SmuTst_lRtRestore
(
 const SmuTst_Rt_BkupDataType * const RtBkupData,
 const SmuTst_Rt_AlarmInfoType *RtAlarmInfo,
 uint32* const TstSignature
)
{
  Sl_TstRsltType Result = (Sl_TstRsltType)SMUTST_RT_NOTEXECUTED;
  Std_ReturnType SmuResult = (Std_ReturnType)E_NOT_OK;
  uint8 SmuAlarmId = (uint8)SMUTST_ZERO;

  /* Restore the register contents */

  /* disable the write-protection for registers */
  Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);
  /* Enable SMU configuration */
  SMU_KEYS.U = (unsigned_int)SMU_CFG_KEY_UNLOCK;
  SMU_RTC.U = RtBkupData->SmuRtcBackup;
  SMU_RTAC0.U = RtBkupData->SmuRtac0Backup;
  SMU_RTAC1.U = RtBkupData->SmuRtac1Backup;
  /* After configuration set temporary lock of SMU configuration */
  SMU_KEYS.U = (uint32)SMU_CFG_KEY_TEMPLOCK;
  /* Clear SMU status register */
  SMU_STS.U = SMUTST_ZERO;
  /* Restore back the write-protection for registers */
  Mcal_SetSafetyENDINIT_Timed();

  /* SMU alarm action of all the alarms used by SmuTst are restored */
  do
  {
    /* Invalidate SmuResult */
    SmuResult = (Std_ReturnType)E_NOT_OK;

    if (E_OK == (RtBkupData->AlmActionBackupResult[SmuAlarmId]))
    {
      /* Restore the alarm action setting of alarms in RtAlarmInfo */
      if (E_OK != Smu_SetAlarmAction(RtAlarmInfo[SmuAlarmId].AlmGrp,
                                    RtAlarmInfo[SmuAlarmId].AlmId,
                                    RtBkupData->AlmActionBackup[SmuAlarmId]))
      {
        SmuResult = (Std_ReturnType)E_NOT_OK;

        /* Error condition: SMU set alarm action error */
        Result = (Sl_TstRsltType)SMUTST_RT_SMU_SETALMACTIONERR;
      }
      else
      {
        SmuResult = (Std_ReturnType)E_OK;

        Result = (Sl_TstRsltType)SMUTST_RT_SUCCESS;
      }
    }
    SmuAlarmId++;
  }while((E_OK == SmuResult) && (SmuAlarmId < SMUTST_RT_BKUP_SIZE));

  /* Add SmuResult to test signature
     In case of Success: SmuResult = 0x00 */
  *TstSignature = (uint32)CRC32(*TstSignature, (uint32)SmuResult);

  return Result;
}

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static Sl_TstRsltType SmuTst_lRtTimeoutTst              **
**                    (                                                       **
**                      uint32* const TstSignature                            **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters (in)  : None                                                    **
**                                                                            **
** Parameters (out) : TstSignature - Test signature generated by the test     **
**                                                                            **
** Return value     : SMUTST_RT_SUCCESS:  Test succeeded                      **
**                    SMUTST_RT_NOTEXECUTED: This error is never              **
**                      intentionally returned, if it is returned anyway,     **
**                      something must be seriously wrong                     **
**                    SMUTST_RT_TIMEOUT_RTRUNERR: RT timeout test failed, as  **
**                      recovery timer status is not set                      **
**                    SMUTST_RT_TIMEOUT_ALMNOTSETERR: RT timeout test failed  **
**                      as alarm is not set on RT timeout                     **
**                    SMUTST_RT_SMU_SETALMSTSERR:  Test failed because        **
**                      Smu_SetAlarmStatus returned an error                  **
**                    SMUTST_RT_SMU_GETALMSTSERR:  Test failed because        **
**                      Smu_GetAlarmStatus returned an error                  **
**                    SMUTST_RT_SMU_CLRALMSTSERR: Test failed because         **
**                      Smu_ClearAlarmStatus returned an error                **
**                                                                            **
** Description      : SmuTst_lRtTimeoutTst verifies whether the timeout of    **
**                    recovery timer leads to an alarm                        **
*******************************************************************************/
static Sl_TstRsltType SmuTst_lRtTimeoutTst
(
  uint32* const TstSignature
)
{
  Sl_TstRsltType Result = (Sl_TstRsltType)SMUTST_RT_NOTEXECUTED;
  uint32 AlarmStatus = SMUTST_ZERO;
  uint32 Timeout = SMUTST_RT_ALARM_TIMEOUT;
  uint8 RtStatus0 = (uint8)SMUTST_ZERO;
  uint8 RtStatus1 = (uint8)SMUTST_ZERO;
  Std_ReturnType TempResult1 = (Std_ReturnType)E_NOT_OK;
  Std_ReturnType TempResult2 = (Std_ReturnType)E_NOT_OK;
  Std_ReturnType TempResult3 = (Std_ReturnType)E_NOT_OK;

  /* Initialize recovery timer registers */
  SmuTst_lRtInitRtRegs(SMUTST_RTC_RT01EN_RTDLOW);

  /* Initialize with error condition: SMU set alarm status error */
  Result = (Sl_TstRsltType)SMUTST_RT_SMU_SETALMSTSERR;

  /* Trigger alarm: ALM5[0] */
  if (E_OK == Smu_SetAlarmStatus(SMU_ALARM_GROUP5, SMU_ALARM_0))
  {
    /* Read recovery timer 0 and 1 status bit field */
    RtStatus0 = (uint8)SMU_STS.B.RTS0;
    RtStatus1 = (uint8)SMU_STS.B.RTS1;

    /* Initialize with error condition: Recovery timers 0 and/or 1 are not
       running */
    Result = (Sl_TstRsltType)SMUTST_RT_TIMEOUT_RTRUNERR;

    /* Verify whether Recovery timers 0 and 1 are running */
    if ((SMUTST_ONE == RtStatus0) && (SMUTST_ONE == RtStatus1))
    {
      /* Allow recovery timers 0 and 1 to overflow and verify timeout ala
        of Recovery timers are set */
      while (Timeout > SMUTST_ZERO)
      {
        Timeout = Timeout - SMUTST_ONE;

        if (E_OK != Smu_GetAlarmStatus(SMU_ALARM_GROUP2, &AlarmStatus))
        {
          /* Error condition: Reading of the alarm status failed */
          Result = (Sl_TstRsltType)SMUTST_RT_SMU_GETALMSTSERR;

          /* Reset Timeout value to exit the loop */
          Timeout = SMUTST_ZERO;
        }
        else
        {
          if (SMUTST_RTXALARM != ((uint32)AlarmStatus & SMUTST_RTXALARM))
          {
            /* Error condition: Expected alarms ALM2[29] and/or ALM2[30] are
               not set */
            Result = (Sl_TstRsltType)SMUTST_RT_TIMEOUT_ALMNOTSETERR;
          }
          else
          {
            /* Alarms ALM2[29] and ALM2[30] are set as expected */
            Result = (Sl_TstRsltType)SMUTST_RT_SUCCESS;

            /* Reset Timeout value to exit the loop */
            Timeout = SMUTST_ZERO;
          }
        }
      }
    }

    /* Clear alarm status: ALM5[0], ALM2[29] and ALM2[30] */
    TempResult1 = Smu_ClearAlarmStatus(SMU_ALARM_GROUP5, SMU_ALARM_0);
    TempResult2 = \
            Smu_ClearAlarmStatus(SMUTST_RT0ALARM_GRP, SMUTST_RT0ALARM_INDEX);
    TempResult3 = \
            Smu_ClearAlarmStatus(SMUTST_RT1ALARM_GRP, SMUTST_RT1ALARM_INDEX);

    if ((E_OK != TempResult1) || (E_OK != TempResult2) || (E_OK != TempResult3))
    {
      /* Error condition: SMU clear alarm status error */
      Result = (Sl_TstRsltType)SMUTST_RT_SMU_CLRALMSTSERR;
    }
  }

  /* Add (AlarmStatus & SMUTST_RTXALARM) to test signature
     In case of Success: (0x60000000 & 0x60000000) = 0x60000000 */
  *TstSignature = (uint32)CRC32(*TstSignature, \
                            (uint32)((uint32)AlarmStatus & SMUTST_RTXALARM));

  return Result;
}

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static Sl_TstRsltType SmuTst_lRtStopTst                 **
**                    (                                                       **
**                      uint32* const TstSignature                            **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters (in)  : None                                                    **
**                                                                            **
** Parameters (out) : TstSignature - Test signature generated by the test     **
**                                                                            **
** Return value     : SMUTST_RT_SUCCESS:  Test succeeded                      **
**                    SMUTST_RT_NOTEXECUTED: This error is never              **
**                      intentionally returned, if it is returned anyway,     **
**                      something must be seriously wrong                     **
**                    SMUTST_RT_STOP_RTRUNERR: RT stop test failed, as        **
**                      recovery timer status is not set                      **
**                    SMUTST_RT_STOP_RTSTOPERR: RT stop test failed because   **
**                      Smu_RTStop returned an error                          **
**                    SMUTST_RT_STOP_ALMSETERR: RT stop test failed,          **
**                      as alarm is unexpectedly set.                         **
**                    SMUTST_RT_STOP_STOPERR: RT stop test failed, as         **
**                     recovery timer status is not reset                     **
**                    SMUTST_RT_SMU_SETALMSTSERR:  Test failed because        **
**                      Smu_SetAlarmStatus returned an error                  **
**                    SMUTST_RT_SMU_GETALMSTSERR:  Test failed because        **
**                      Smu_GetAlarmStatus returned an error                  **
**                    SMUTST_RT_SMU_CLRALMSTSERR: Test failed because         **
**                      Smu_ClearAlarmStatus returned an error                **
**                                                                            **
** Description      : SmuTst_lRtStopTst verifies the stopping of recovery     **
**                    timer does not lead to an alarm                         **
*******************************************************************************/
static Sl_TstRsltType SmuTst_lRtStopTst
(
  uint32* const TstSignature
)
{
  Sl_TstRsltType Result = (Sl_TstRsltType)SMUTST_RT_NOTEXECUTED;
  uint32 AlarmStatus = SMUTST_ZERO;
  uint32 Timeout = SMUTST_ALARM_TIMEOUT;
  uint8 RtStatus0 = (uint8)SMUTST_ZERO;
  uint8 RtStatus1 = (uint8)SMUTST_ZERO;
  Std_ReturnType TempResult1 = (Std_ReturnType)E_NOT_OK;
  Std_ReturnType TempResult2 = (Std_ReturnType)E_NOT_OK;

  SmuTst_lRtInitRtRegs(SMUTST_RTC_RT01EN_RTDMAX);

  Result = (Sl_TstRsltType)SMUTST_RT_SMU_SETALMSTSERR;

  /* Trigger alarm: ALM5[1] */
  if (E_OK == Smu_SetAlarmStatus(SMU_ALARM_GROUP5, SMU_ALARM_1))
  {
    /* Read recovery timer 0 and 1 status bit field */
    RtStatus0 = (uint8)SMU_STS.B.RTS0;
    RtStatus1 = (uint8)SMU_STS.B.RTS1;

    /* Initialize with error condition: Recovery timers 0 and/or 1 are not
       running */
    Result = (Sl_TstRsltType)SMUTST_RT_STOP_RTRUNERR;

    /* Verify whether Recovery timers 0 and 1 are running */
    if ((SMUTST_ONE == RtStatus0) && (SMUTST_ONE == RtStatus1))
    {
      /* Initialize with error condition: SMU command SMU_RTStop failure */
      Result = (Sl_TstRsltType)SMUTST_RT_STOP_RTSTOPERR;

      /* Issue command to stop recovery timer 0 and 1 */
      TempResult1 = Smu_RTStop(SMU_RECOV_TIM0);
      TempResult2 = Smu_RTStop(SMU_RECOV_TIM1);

      /* Verify if command to stop recovery timer 0 and 1 is successful */
      if ((E_OK == TempResult1) && (E_OK == TempResult2))
      {
        /* Read recovery timer 0 and 1 status bit field */
        RtStatus0 = (uint8)SMU_STS.B.RTS0;
        RtStatus1 = (uint8)SMU_STS.B.RTS1;

        /* Initialize with error condition: Recovery timer 0 and/or 1 are
           still running */
        Result = (Sl_TstRsltType)SMUTST_RT_STOP_STOPERR;

        /* Verify whether Recovery timers 0 and 1 are stopped */
        if ((SMUTST_ZERO == RtStatus0) && (SMUTST_ZERO == RtStatus1))
        {
          /* Wait for the 'Timeout' time and ensure Alarms ALM2[29] or ALM2[30]
             is not set*/
          while (Timeout > SMUTST_ZERO)
          {
            Timeout = Timeout - SMUTST_ONE;

            if (E_OK != Smu_GetAlarmStatus(SMU_ALARM_GROUP2, &AlarmStatus))
            {
              /* Error condition: Reading of the alarm status failed */
              Result = (Sl_TstRsltType)SMUTST_RT_SMU_GETALMSTSERR;

              /* Reset Timeout value to exit the loop */
              Timeout = SMUTST_ZERO;
            }
            else
            {
              /* Verify that Alarms ALM2[29] and/or ALM2[30] is set */
              if (SMUTST_ZERO != (AlarmStatus & SMUTST_RTXALARM))
              {
                /* Error condition: Alarms ALM2[29] and/or ALM2[30] is
                   set unexpectedly */
                Result = (Sl_TstRsltType)SMUTST_RT_STOP_ALMSETERR;

                /* Reset Timeout value to exit the loop */
                Timeout = SMUTST_ZERO;
              }
              else
              {
                Result = (Sl_TstRsltType)SMUTST_RT_SUCCESS;
              }
            }
          }
        }
      }
    }

    /* Clear alarm status: ALM5[0] */
    if (E_OK != Smu_ClearAlarmStatus(SMU_ALARM_GROUP5, SMU_ALARM_1))
    {
      /* Error condition: SMU clear alarm status error */
      Result = (Sl_TstRsltType)SMUTST_RT_SMU_CLRALMSTSERR;
    }
  }

  /* Add (AlarmStatus & SMUTST_RTXALARM) to test signature
     In case of Success: (0x00000000 & 0x60000000) = 0x00 */
  *TstSignature = (uint32)CRC32(*TstSignature, \
                            (uint32)((uint32)AlarmStatus & SMUTST_RTXALARM));

  return Result;
}

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static Sl_TstRsltType SmuTst_lRtMissedEventTst          **
**                    (                                                       **
**                      uint32* const TstSignature                            **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters (in)  : None                                                    **
**                                                                            **
** Parameters (out) : TstSignature - Test signature generated by the test     **
**                                                                            **
** Return value     : SMUTST_RT_SUCCESS:  Test succeeded                      **
**                    SMUTST_RT_NOTEXECUTED: This error is never              **
**                      intentionally returned, if it is returned anyway,     **
**                      something must be seriously wrong                     **
**                    SMUTST_RT_MISSEDEVT_RTRUNERR: RT missed event test      **
**                     failed, recovery timer status is not set               **
**                    SMUTST_RT_MISSEDEVT_RTSTOPERR: RT missed event test     **
**                      failed because Smu_RTStop returned an error           **
**                    SMUTST_RT_MISSEDEVT_ERR: RT missed event test, as the   **
**                     alarm does not trigger missed event                    **
**                    SMUTST_RT_SMU_SETALMSTSERR:  Test failed because        **
**                      Smu_SetAlarmStatus returned an error                  **
**                    SMUTST_RT_SMU_CLRALMSTSERR: Test failed because         **
**                      Smu_ClearAlarmStatus returned an error                **
**                                                                            **
** Description      : SmuTst_lRtMissedEventTst verifies whether missed event  **
**                    is set on an alarm, when the recovery timer is already  **
**                    running due to another configured alarm                 **
*******************************************************************************/
static Sl_TstRsltType SmuTst_lRtMissedEventTst
(
  uint32* const TstSignature
)
{
  Sl_TstRsltType Result = (Sl_TstRsltType)SMUTST_RT_NOTEXECUTED;
  uint8 TempRt0 = (uint8)SMUTST_ZERO;
  uint8 TempRt1 = (uint8)SMUTST_ZERO;
  uint8 MissedEvtStatus0 = (uint8)SMUTST_ZERO;
  uint8 MissedEvtStatus1 = (uint8)SMUTST_ZERO;
  Std_ReturnType TempResult1 = (Std_ReturnType)E_NOT_OK;
  Std_ReturnType TempResult2 = (Std_ReturnType)E_NOT_OK;

  /* Initialize recovery timer registers */
  SmuTst_lRtInitRtRegs(SMUTST_RTC_RT01EN_RTDMAX);

  /* Initialize with error condition: SMU set alarm status error */
  Result = (Sl_TstRsltType)SMUTST_RT_SMU_SETALMSTSERR;

  /* Trigger alarm: ALM5[2] */
  if (E_OK == Smu_SetAlarmStatus(SMU_ALARM_GROUP5, SMU_ALARM_2))
  {
    /* Read recovery timer 0 and 1 status bit field */
    TempRt0 = (uint8)SMU_STS.B.RTS0;
    TempRt1 = (uint8)SMU_STS.B.RTS1;

    /* Initialize with error condition: Recovery timers 0 and/or 1 are not
       running */
    Result = (Sl_TstRsltType)SMUTST_RT_MISSEDEVT_RTRUNERR;

    /* Verify whether Recovery timers 0 and 1 are running */
    if ((SMUTST_ONE == TempRt0) && (SMUTST_ONE == TempRt1))
    {
      /* Initialize with error condition: SMU set alarm status error */
      Result = (Sl_TstRsltType)SMUTST_RT_SMU_SETALMSTSERR;

      /* Trigger alarm: ALM5[3] */
      if (E_OK == Smu_SetAlarmStatus(SMU_ALARM_GROUP5, SMU_ALARM_3))
      {
        /* Read recovery timer 0 and 1 missed status bit field */
        MissedEvtStatus0 = (uint8)SMU_STS.B.RTME0;
        MissedEvtStatus1 = (uint8)SMU_STS.B.RTME1;

        /* Verify whether Recovery timers 0 and 1 missed event bit fields
           are set */
        if ((SMUTST_ONE == MissedEvtStatus0) && \
                                            (SMUTST_ONE == MissedEvtStatus1))
        {
          Result = (Sl_TstRsltType)SMUTST_RT_SUCCESS;
        }
        else
        {
          /* Error condition: Missed event status is not set for
             Recovery timer 0 and/or Recovery timer 1 */
          Result = (Sl_TstRsltType)SMUTST_RT_MISSEDEVT_ERR;
        }

        /* Clear alarm status: ALM5[3] */
        TempResult1 = Smu_ClearAlarmStatus(SMU_ALARM_GROUP5, SMU_ALARM_3);
        if (E_OK != TempResult1)
        {
          /* Error condition: SMU clear alarm status error */
          Result = (Sl_TstRsltType)SMUTST_RT_SMU_CLRALMSTSERR;
        }
      }

      /* Issue command to stop recovery timer 0 and 1 */
      TempResult1 = Smu_RTStop(SMU_RECOV_TIM0);
      TempResult2 = Smu_RTStop(SMU_RECOV_TIM1);

      /* Verify if command to stop recovery timer 0 and 1 is successful */
      if ((E_OK != TempResult1) || (E_OK != TempResult2))
      {
        /* Error condition: SMU command SMU_RTStop failure */
        Result = (Sl_TstRsltType)SMUTST_RT_MISSEDEVT_RTSTOPERR;
      }
    }

    /* Clear alarm status: ALM5[2] */
    TempResult1 = Smu_ClearAlarmStatus(SMU_ALARM_GROUP5, SMU_ALARM_2);
    if (E_OK != TempResult1)
    {
      /* Error condition: SMU clear alarm status error */
      Result = (Sl_TstRsltType)SMUTST_RT_SMU_CLRALMSTSERR;
    }
  }

  /* Add (MissedEvtStatus0 & MissedEvtStatus1) to test signature
     In case of Success: (0x01 & 0x01) = 0x01 */
  *TstSignature = (uint32)CRC32(*TstSignature, \
                        ((uint32)MissedEvtStatus0 & (uint32)MissedEvtStatus1));

  return Result;
}

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static void SmuTst_lRtInitRtRegs                        **
**                    (const uint32 SmuRtcValue)                              **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters (in)  : SmuRtcValue - SMU_RTC value to be configured            **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : SmuTst_lRtInitRtRegs initializes the recovery timer     **
**                    registers.                                              **
*******************************************************************************/
static void SmuTst_lRtInitRtRegs(const uint32 SmuRtcValue)
{
  /* disable the write-protection for registers */
  Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);
  /* Enable SMU configuration */
  SMU_KEYS.U = (unsigned_int)SMU_CFG_KEY_UNLOCK;
  /* Configure SMU_RTC as per the input parameter */
  SMU_RTC.U = SmuRtcValue;
  SMU_RTAC0.U = SMUTST_RTAC0;
  SMU_RTAC1.U = SMUTST_RTAC1;
   /* After configuration set temporary lock of SMU configuration */
  SMU_KEYS.U = (uint32)SMU_CFG_KEY_TEMPLOCK;
  /* Clear SMU status register */
  SMU_STS.U = SMUTST_ZERO;
  /* Restore back the write-protection for registers */
  Mcal_SetSafetyENDINIT_Timed();
}

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static boolean SmuTst_lNmiTrapHandler                   **
**                                     (const uint32 trapID)                  **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters (in)  : trapID : Trap identifier (not used)                     **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : TRUE, if trap was expected and handled, FALSE otherwise **
**                                                                            **
** Description      : NMI trap handler. This is called when SMU alarm is      **
**                    triggered by SMU NMI test.                              **
*******************************************************************************/
static boolean SmuTst_lNmiTrapHandler (const uint32 trapID)
{
  uint8 CoreId = (uint8)SMUTST_ZERO;
  boolean TrapExpected = (boolean)FALSE;

  /* Required to avoid compiler warning */
  UNUSED_PARAMETER(trapID)

  /* Read the current active core Id */
  CoreId = (uint8)MFCR(CPU_CORE_ID);

  /* Verify whether the current trap is expected */
  if (SmuTst_ExpectedTrap == SMUTST_NMI_TRAP_CLASS)
  {
    /* Increment the trap count of the current running core */
    SmuTst_NmiTrapCount[CoreId] = SmuTst_NmiTrapCount[CoreId] + SMUTST_ONE;

    /* Set the trap expected flag */
    TrapExpected = (boolean)TRUE;
  }

  return TrapExpected;
}

#define IFX_SMUTST_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
