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
**   $FILENAME   : ClkmTst.c $                                                **
**                                                                            **
**   $CC VERSION : \main\45 $                                                 **
**                                                                            **
**   $DATE       : 2018-02-22 $                                               **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon AURIX                                                **
**                                                                            **
**  AUTHOR    : SafeTlib Team                                                 **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : This file contains                                         **
**                 - functionality of Clock monitor test                      **
**                                                                            **
**  MAY BE CHANGED BY USER [Yes/No]: No                                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Mcal.h"
#include "IfxScu_reg.h"
#include "IfxScu_bf.h"
#include "IfxSmu_reg.h"
#include "ClkmTst.h"
#include "SmuInt.h"
#include "Os_DisableInterrupts.h"

/*******************************************************************************
**                      Local Macro Definitions                               **
*******************************************************************************/

/* Mask to get the CCU CON config values */
#define CLKMTST_CCUCON3_CONFIG_MASK  ((uint32)0x00FFFFFFU)
#define CLKMTST_CCUCON4_CONFIG_MASK  ((uint32)0x00FFFFFFU)
#define CLKMTST_CCUCON9_CONFIG_MASK  ((uint32)0x000000FFU)

/* CCUCON: DIV and SEL values */
/* Monitoring frequency = 7.5MHz */
#define CLKM_CCUCON_SEL_LOW_7_5MHZ (0x3U)
/* Monitoring frequency = 6MHz */
#define CLKM_CCUCON_SEL_LOW_6MHZ  (0x1U)
#define CLKM_CCUCON_DIV_LOW  (0x3FU)

/* Monitoring frequency = 5MHz */
#define CLKM_CCUCON_SEL_HIGH  (0x0U)
#define CLKM_CCUCON_DIV_HIGH  (0x1U)

/*
CHREV in CHIPID register: Bits[5:0]
Bits [3:0] define minor silicon design steps(A,B,C,D...)
Bits [5:4] define major silicon design steps(A,B,C,D)
*/
#define CHIPID_CHREV_STEP_OFFSET     (0x3FU)

#define CLKM_CCUCON9_LOWVAL_6MHZ  \
  (((uint32)CLKM_CCUCON_SEL_LOW_6MHZ << IFX_SCU_CCUCON9_ADCSEL_OFF) | \
    (uint32)CLKM_CCUCON_DIV_LOW)
					   
/* configuration settings of too low monitoring frequency of 6MHZ for PLLERAY clock */
#define CLKM_CCUCON3_PLLERAY_LOWVAL_6MHZ  (((uint32)CLKM_CCUCON_SEL_LOW_6MHZ<<14U)|\
                                      ((uint32)CLKM_CCUCON_DIV_LOW<<8U))
									  
/* configuration settings of too low monitoring frequency of 6MHZ for SRI & PLL clocks */									  
#define CLKM_CCUCON3_LOWVAL_6MHZ  (((uint32)CLKM_CCUCON_SEL_LOW_6MHZ<<22U)|\
                                      ((uint32)CLKM_CCUCON_DIV_LOW<<16U)|\
                                      ((uint32)CLKM_CCUCON_SEL_LOW_6MHZ<<6U)|\
                                      ((uint32)CLKM_CCUCON_DIV_LOW))
									  
/* configuration settings of too low monitoring frequency of 6MHZ for GTM clock */
#define CLKM_CCUCON4_GTM_LOWVAL_6MHZ	 (((uint32)CLKM_CCUCON_SEL_LOW_6MHZ<<14U)|\
                                          ((uint32)CLKM_CCUCON_DIV_LOW<<8U))

/* configuration settings of too low monitoring frequency of 6MHZ for STM clock */										  
#define CLKM_CCUCON4_STM_LOWVAL_6MHZ  (((uint32)CLKM_CCUCON_SEL_LOW_6MHZ<<22U)|\
                                      ((uint32)CLKM_CCUCON_DIV_LOW<<16U))

/* configuration settings of too low monitoring frequency of 6MHZ for SPB clock */									  
#define CLKM_CCUCON4_SPB_LOWVAL_6MHZ     (((uint32)CLKM_CCUCON_SEL_LOW_6MHZ<<6U)|\
                                      ((uint32)CLKM_CCUCON_DIV_LOW))

#define CLKM_CCUCON9_LOWVAL_7_5MHZ  \
  (((uint32)CLKM_CCUCON_SEL_LOW_7_5MHZ << IFX_SCU_CCUCON9_ADCSEL_OFF) | \
    (uint32)CLKM_CCUCON_DIV_LOW)
				   
/* configuration settings of too low monitoring frequency of 7.5MHZ for PLLERAY clock */
#define CLKM_CCUCON3_PLLERAY_LOWVAL_7_5MHZ  (((uint32)CLKM_CCUCON_SEL_LOW_7_5MHZ<<14U)|\
                                      ((uint32)CLKM_CCUCON_DIV_LOW<<8U))

/* configuration settings of too low monitoring frequency of 7.5MHZ for SRI & PLL clocks */									  
#define CLKM_CCUCON3_LOWVAL_7_5MHZ  (((uint32)CLKM_CCUCON_SEL_LOW_7_5MHZ<<22U)|\
                                      ((uint32)CLKM_CCUCON_DIV_LOW<<16U)|\
                                      ((uint32)CLKM_CCUCON_SEL_LOW_7_5MHZ<<6U)|\
                                      ((uint32)CLKM_CCUCON_DIV_LOW))
									  
/* configuration settings of too low monitoring frequency of 7.5MHZ for GTM clock */
#define CLKM_CCUCON4_GTM_LOWVAL_7_5MHZ	 (((uint32)CLKM_CCUCON_SEL_LOW_7_5MHZ<<14U)|\
                                          ((uint32)CLKM_CCUCON_DIV_LOW<<8U))

/* configuration settings of too low monitoring frequency of 7.5MHZ for STM clock */										  
#define CLKM_CCUCON4_STM_LOWVAL_7_5MHZ  (((uint32)CLKM_CCUCON_SEL_LOW_7_5MHZ<<22U)|\
                                      ((uint32)CLKM_CCUCON_DIV_LOW<<16U))

/* configuration settings of too low monitoring frequency of 7.5MHZ for SPB clock */									  
#define CLKM_CCUCON4_SPB_LOWVAL_7_5MHZ     (((uint32)CLKM_CCUCON_SEL_LOW_7_5MHZ<<6U)|\
                                      ((uint32)CLKM_CCUCON_DIV_LOW))
									  
#define CLKM_CCUCON9_HIGHVAL \
  (((uint32)CLKM_CCUCON_SEL_HIGH << IFX_SCU_CCUCON9_ADCSEL_OFF) | \
                                       (uint32)CLKM_CCUCON_DIV_HIGH)
									   
/* configuration settings of too high frequency for PLLERAY clock */										  
#define CLKM_CCUCON3_PLLERAY_HIGHVAL (((uint32)CLKM_CCUCON_SEL_HIGH<<14U)|\
                                      ((uint32)CLKM_CCUCON_DIV_HIGH<<8U))
									  
/* configuration settings of too high frequency for SRI & PLL clocks */
#define CLKM_CCUCON3_HIGHVAL  (((uint32)CLKM_CCUCON_SEL_HIGH<<22U)|\
                                      ((uint32)CLKM_CCUCON_DIV_HIGH<<16U)|\
                                      ((uint32)CLKM_CCUCON_SEL_HIGH<<6U)|\
                                      ((uint32)CLKM_CCUCON_DIV_HIGH))

/* configuration settings of too high frequency for GTM clock */									  
#define CLKM_CCUCON4_GTM_HIGHVAL (((uint32)CLKM_CCUCON_SEL_HIGH<<14U)|\
                                      ((uint32)CLKM_CCUCON_DIV_HIGH<<8U))
									  
/* configuration settings of too high frequency for STM clock */									  
#define CLKM_CCUCON4_STM_HIGHVAL (((uint32)CLKM_CCUCON_SEL_HIGH<<22U)|\
                                      ((uint32)CLKM_CCUCON_DIV_HIGH<<16U))	

/* configuration settings of too high frequency for SPB clock */									  
#define CLKM_CCUCON4_SPB_HIGHVAL  (((uint32)CLKM_CCUCON_SEL_HIGH<<6U)|\
                                      ((uint32)CLKM_CCUCON_DIV_HIGH))

/* Value to set the UP bit in CCU CON register */
#define CLKMTST_UPDATE_CCUCON     (1U)

/*PLL_ERAY is in Normal Mode*/
#define CLKM_PLLERAYCON0_PLLPWD  (1U)

/* SMU Alarm Group Index for the clock monitor test modules */
#define SMU_ALARM_GROUP_CLKM        ((uint8)SMU_ALARM_GROUP3)

/* SMU Alarm Index for the clock monitor test modules */
#define SMU_ALARM_SCU_CGU_STM       (SMU_ALARM_3)
#define SMU_ALARM_SCU_CGU_PLLERRAY  (SMU_ALARM_4)
#define SMU_ALARM_SCU_CGU_SYSPLL    (SMU_ALARM_5)
#define SMU_ALARM_SCU_CGU_SRI       (SMU_ALARM_6)
#define SMU_ALARM_SCU_CGU_SPB       (SMU_ALARM_7)
#define SMU_ALARM_SCU_CGU_GTM       (SMU_ALARM_8)
#define SMU_ALARM_SCU_CGU_ADC       (SMU_ALARM_9)

/* Index of the backup array for SMU alarm action in ClkmTst_BackupDataType */
/* Index which are referenced in the code */
#define SMU_ALARM_ACTION_STM_INDEX      (0U)
#define SMU_ALARM_ACTION_ADC_INDEX      (6U)

/* Mask to check the module Alarm status from Alarm group status */
#define SMU_ALARM_STM_STS        (((uint32)1U << SMU_ALARM_SCU_CGU_STM))
#define SMU_ALARM_PLLERRAY_STS   (((uint32)1U << SMU_ALARM_SCU_CGU_PLLERRAY))
#define SMU_ALARM_SYSPLL_STS     (((uint32)1U << SMU_ALARM_SCU_CGU_SYSPLL))
#define SMU_ALARM_SRI_STS        (((uint32)1U << SMU_ALARM_SCU_CGU_SRI))
#define SMU_ALARM_SPB_STS        (((uint32)1U << SMU_ALARM_SCU_CGU_SPB))
#define SMU_ALARM_GTM_STS        (((uint32)1U << SMU_ALARM_SCU_CGU_GTM))
#define SMU_ALARM_ADC_STS        (((uint32)1U << SMU_ALARM_SCU_CGU_ADC))

/* Flag value to restore or not the SMU alarm configurations */
#define CLKMTST_RESTORE_SMUALM_CONIG     ((uint8)1U)
#define CLKMTST_NO_RESTORE_SMUALM_CONIG  ((uint8)0U)

/* Alarm Reset value */
#define CLKM_SMU_ALARM_RESET     (0U)

/* In SCU_CCUCON0 / SCU_CCUCON1, module frequency configured to be disabled */
#define CLKM_MOD_CLK_STOPPED  (0U)

/* Configuration of SCU_CCUCON0.CLKSEL to 1 (fPLL is used as clock source)*/
#define CCUCON0_CLKSEL_FPLL    (1U)

/* Configuration of SCU_CCUCON1.INSEL to 1 (fOSC0 is used as clock source)*/
#define CCUCON1_INSEL_FOSC0    (1U)
/*******************************************************************************
**                      Local Type Definitions                                **
*******************************************************************************/
/* Type for backup of SFRs and Alarm action during ClkmTst */
typedef struct ClkmTst_BackupDataType
{
    /* To backup CCUCON3 register */
    ClkmTst_CCUCONType CCUCON3Backup;
    /* To backup CCUCON4 register */
    ClkmTst_CCUCONType CCUCON4Backup;
#if (CLKMTST_TEST_ADC_CLOCK == TRUE)
    /* To backup CCUCON9 register */
    ClkmTst_CCUCONType CCUCON9Backup;
#endif
    /* To backup CCUCON0 register */
    ClkmTst_CCUCONType CCUCON0Backup;
    /* To backup alarm action for the CLKM modules */
    Smu_AlarmActionType AlmActionBackup[7];
}ClkmTst_BackupDataType;

/*******************************************************************************
**                        Exported object definitions                          *
*******************************************************************************/

/*******************************************************************************
**                        Local object definitions                             *
*******************************************************************************/
#define IFX_CLKM_START_SEC_CONST_8BIT_ASIL_B
#include "Ifx_MemMap.h"

/* Array of clock monitor alarm index */
static const uint8 ClkmTst_kSmuAlarmId[7] =
                               { SMU_ALARM_SCU_CGU_STM,
                                 SMU_ALARM_SCU_CGU_PLLERRAY,
                                 SMU_ALARM_SCU_CGU_SYSPLL,
                                 SMU_ALARM_SCU_CGU_SRI,
                                 SMU_ALARM_SCU_CGU_SPB,
                                 SMU_ALARM_SCU_CGU_GTM,
                                 SMU_ALARM_SCU_CGU_ADC
                               };

#define IFX_CLKM_STOP_SEC_CONST_8BIT_ASIL_B
#include "Ifx_MemMap.h"
/*******************************************************************************
**                        Imported function declarations                       *
*******************************************************************************/

/*******************************************************************************
**                        Local function prototypes                            *
*******************************************************************************/
#define IFX_CLKM_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
static Sl_TstRsltType ClkmTst_lInit 
(
  ClkmTst_BackupDataType * ClkmTst_BackupData,
  uint8 * ClkmTst_RestoreAlmFlag,
  uint32 * Clkm_SmuAlarmMask
);

static Sl_TstRsltType ClkmTst_lExecuteTest
(
  uint32* const TstSignature,
  ClkmTst_BackupDataType ClkmTst_BackupData,
  uint32 Clkm_SmuAlarmMask
);

static Sl_TstRsltType ClkmTst_lCheckSmuAlarm
(
  uint32 AlarmCheck,
  uint32 Clkm_SmuAlarmMask
);

static void ClkmTst_lDisableClockMonitors
(
  ClkmTst_BackupDataType  ClkmTst_BackupData
);

static void ClkmTst_lSetupClockMonitorsTooLow(void);

static void ClkmTst_lSetupClockMonitorsTooHigh(void);

static void ClkmTst_lCalculateSignature
(uint32* const TstSignature);

static Sl_TstRsltType ClkmTst_lClearSmuAlarms(void);

static void ClkmTst_lRestoreClockMonitors
(ClkmTst_BackupDataType ClkmTst_BackupData);

static Sl_TstRsltType ClkmTst_lRestoreSmuAlarmsConfig
(ClkmTst_BackupDataType ClkmTst_BackupData);

static uint32 ClkmTst_lInitAlarmChkVal(void);

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
** Syntax           : Sl_TstRsltType ClkmTst_lInit                            **
**                    (ClkmTst_BackupDataType * ClkmTst_BackupData,           **
**                     uint8 * ClkmTst_RestoreAlmFlag,                        **
**                     uint32 * Clkm_SmuAlarmMask)                            **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : ClkmTst_BackupData - Backup of registers                **
**                    ClkmTst_RestoreAlmFlag - Flag to restore SMU alarms     **
**                    Clkm_SmuAlarmMask - Mask for checking the SMU alarms    **
**                                                                            **
** Return value     : CLKM_SUCCESS - Test succeeded                           **
**                    CLKM_SMU_STATEERR - SMU not in RUN state                **
**                    CLKM_SMU_GETALMSTS_ERR - Error on call to               **
**                    Smu_GetAlarmStatus API                                  **
**                    CLKM_SMU_ALMSTS_ERR - SMU alarm already been set        **
**                    CLKM_SMU_GETALMACTION_ERR - Error on call to            **
**                    Smu_GetAlarmAction API                                  **
**                    CLKM_SMU_SETALMACTION_ERR - Error on call to            **
**                    Smu_SetAlarmAction API                                  **
**                                                                            **
** Description      : This function take the backup copy of all SFR values    **
**                    and SMU alarm actions that will be modified by the test.**
**                    Also checks whether the SMU used by the test are in the **
**                    expected state.                                         **
**                    Furthermore it sets up the SMU alarm actions to         **
**                    No action of all SMU alarms triggered by the test.      **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType ClkmTst_lInit 
(
  ClkmTst_BackupDataType * ClkmTst_BackupData,
  uint8 * ClkmTst_RestoreAlmFlag,
  uint32 * Clkm_SmuAlarmMask
)
{
  Sl_TstRsltType        Result;
  Std_ReturnType        SmuResult;
  uint32                SmuAlarmId;
  uint32                SmuClkmAlarmStatus = 0U;

  /* The value of the FSP action backup will be irrelevant as
   * SMU FSP is not activated during SafeTlib Pre-run phase.
   * At the backup of alarm action, the FSP action backup is not
   * validated and not stored for restoring
   */
  Smu_FSPActionType SmuAlarmFspAction = 0U;

  /* Check if SMU is in RUN state:                       */
  if (SMU_RUN_STATE != Smu_GetSmuState())
  {
    Result = CLKM_SMU_STATEERR;
  }
  else /* SMU in RUN state, take the backup */
  {
    /* Check if any of the CLKM modules alarms are already set */
    SmuResult = Smu_GetAlarmStatus(SMU_ALARM_GROUP_CLKM,
                                   &SmuClkmAlarmStatus
                                  );
    if(SmuResult != (Std_ReturnType)E_OK)
    {
      Result = CLKM_SMU_GETALMSTS_ERR;
    }
    else if(((SmuClkmAlarmStatus & SMU_ALARM_STM_STS) != 0U)
#if (CLKMTST_TEST_PLLERAY_CLOCK == TRUE)
          ||((SmuClkmAlarmStatus & SMU_ALARM_PLLERRAY_STS) != 0U)
#endif
              ||((SmuClkmAlarmStatus & SMU_ALARM_SYSPLL_STS) != 0U) 
              ||((SmuClkmAlarmStatus & SMU_ALARM_SRI_STS) != 0U) 
              ||((SmuClkmAlarmStatus & SMU_ALARM_SPB_STS) != 0U) 
              ||((SmuClkmAlarmStatus & SMU_ALARM_GTM_STS) != 0U) 
#if (CLKMTST_TEST_ADC_CLOCK == TRUE)
            ||((SmuClkmAlarmStatus & SMU_ALARM_ADC_STS) != 0U)
#endif
             )
    {
      Result = CLKM_SMU_ALMSTS_ERR;
    }
    else
    {
      /* Take the backup of CCUCON registers used by the test */
      (ClkmTst_BackupData->CCUCON0Backup) = (ClkmTst_CCUCONType)SCU_CCUCON0.U;
      (ClkmTst_BackupData->CCUCON3Backup) = (ClkmTst_CCUCONType)SCU_CCUCON3.U;
      (ClkmTst_BackupData->CCUCON4Backup) = (ClkmTst_CCUCONType)SCU_CCUCON4.U;
#if (CLKMTST_TEST_ADC_CLOCK == TRUE)
      (ClkmTst_BackupData->CCUCON9Backup) = (ClkmTst_CCUCONType)SCU_CCUCON9.U;
#endif

        /* Take the backup of SMU alarm action configurations for
         * Clock monitor modules
         */
        SmuAlarmId = (uint32)SMU_ALARM_ACTION_STM_INDEX;
        do
        {
          SmuResult = Smu_GetAlarmAction
                        (SMU_ALARM_GROUP_CLKM,
                         ClkmTst_kSmuAlarmId[SmuAlarmId],
                         &ClkmTst_BackupData->AlmActionBackup[SmuAlarmId],
                         &SmuAlarmFspAction
                        );
          SmuAlarmId++;
        }while( (SmuResult == (Std_ReturnType)E_OK) &&
                (SmuAlarmId <= (uint32)SMU_ALARM_ACTION_ADC_INDEX)
            );

        if(SmuResult != (Std_ReturnType)E_OK)
        {
          Result = CLKM_SMU_GETALMACTION_ERR;
        }
        else /* No error till now */
        {/* SMU alarm action backup are success and no alarms are already set */

          /* Set the Restoration of SMU alarm configuration to YES */
          *ClkmTst_RestoreAlmFlag = CLKMTST_RESTORE_SMUALM_CONIG;
          
          /*Set Clock monitor modules alarm actions to none (i.e. no action) */
          SmuAlarmId = (uint32)SMU_ALARM_ACTION_STM_INDEX;

          do
          {
            SmuResult = Smu_SetAlarmAction
                            (SMU_ALARM_GROUP_CLKM,
                             ClkmTst_kSmuAlarmId[SmuAlarmId],
                             SMU_ALARM_ACTION_NONE
                            );
            SmuAlarmId++;
          }while((SmuResult == (Std_ReturnType)E_OK) &&
                 (SmuAlarmId <= (uint32)SMU_ALARM_ACTION_ADC_INDEX)
                );

          if(SmuResult != (Std_ReturnType)E_OK)
          {
            Result = CLKM_SMU_SETALMACTION_ERR;
          }
          else
          {
            /* Initialize the SMU alarm to the clocks which are enabled */
            *Clkm_SmuAlarmMask = ClkmTst_lInitAlarmChkVal();
            
            Result = CLKM_SUCCESS;
          }
        } /* Alarms are set to no-actions */
    }/* Backup data taken*/
  }

  return Result;
}/* ClkmTst_lInit */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : void ClkmTst_lInitAlarmChkVal (void)                    **
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
** Return value     : Clkm_SmuAlarmMask - Group 3 Alarm mask value for which  **
**                    the tests are being considered.                         **
**                                                                            **
** Description      : This function sets the mask value SMU Alarms of Group3  **
**                    for all the tested clocks enabled and can be monitored  **
**                                                                            **
*******************************************************************************/
static uint32 ClkmTst_lInitAlarmChkVal(void)
{
  uint32 Clkm_SmuAlarmMask;
  uint32 Clkm_CCUCONINSEL;
  uint32 Clkm_CCUCONCLKSEL;
 #if (CLKMTST_TEST_PLLERAY_CLOCK == TRUE)
  volatile uint8 Clkm_PLLERAYMode = 0U;
 #endif
 
  /* Initialize SMU alarm check mask to check for SPB  
     freq whose clocks is always enabled
     and SRI divider shall never be shut off 
     because it is source for Cores, DSPR memories
  */
  Clkm_SmuAlarmMask = ((uint32)SMU_ALARM_SPB_STS | 
                        (uint32)SMU_ALARM_SRI_STS);

#if (CLKMTST_TEST_ADC_CLOCK == TRUE)
  if((uint32)SCU_CCUCON0.B.ADCCLKSEL != CLKM_MOD_CLK_STOPPED)
  {
    Clkm_SmuAlarmMask = (Clkm_SmuAlarmMask | (uint32)SMU_ALARM_ADC_STS);
  }
#endif

  if((uint32)SCU_CCUCON1.B.STMDIV != CLKM_MOD_CLK_STOPPED)
  {
    Clkm_SmuAlarmMask = (Clkm_SmuAlarmMask | (uint32)SMU_ALARM_STM_STS);
  }
  if((uint32)SCU_CCUCON1.B.GTMDIV != CLKM_MOD_CLK_STOPPED)
  {
    Clkm_SmuAlarmMask = (Clkm_SmuAlarmMask | (uint32)SMU_ALARM_GTM_STS);
  }
  
  /* Read INSEL and CLKSEL of CCUCON registers */
  Clkm_CCUCONINSEL = (uint32)SCU_CCUCON1.B.INSEL;
  Clkm_CCUCONCLKSEL = (uint32)SCU_CCUCON0.B.CLKSEL;
  
  if((Clkm_CCUCONINSEL == (uint32)CCUCON1_INSEL_FOSC0) && 
     (Clkm_CCUCONCLKSEL == (uint32)CCUCON0_CLKSEL_FPLL))
  {
    Clkm_SmuAlarmMask = (Clkm_SmuAlarmMask | (uint32)SMU_ALARM_SYSPLL_STS);
  }
#if (CLKMTST_TEST_PLLERAY_CLOCK == TRUE)
  /* Check PLL_ERAY is in Power Saving Mode or in Normal Mode */
  /* Monitor PLLERAY only when it is in Normal Mode */
  Clkm_PLLERAYMode = SCU_PLLERAYCON0.B.PLLPWD ;

  if(CLKM_PLLERAYCON0_PLLPWD == Clkm_PLLERAYMode)
  {
	  Clkm_SmuAlarmMask = (Clkm_SmuAlarmMask | (uint32)SMU_ALARM_PLLERRAY_STS);
  }
#endif

  return(Clkm_SmuAlarmMask);

}/*ClkmTst_lInitAlarmChkVal*/
/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : Sl_TstRsltType ClkmTst_lRestoreSmuAlarmsConfig          **
**                    (ClkmTst_BackupDataType ClkmTst_BackupData)             **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : ClkmTst_BackupData : backup of registers                **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : CLKM_SUCCESS - Test succeeded                           **
**                    CLKM_TESTNOTEXECUTED - Initialization of return Result  **
**                    When on function flow breaks, this error ID is returned **
**                    CLKM_SMU_SETALMACTION_ERR - Error on Smu_SetAlarmAction **
**                    API return E_NOT_OK                                     **
**                                                                            **
** Description      : This function restores the value of all SMU alarm       **
**                    actions that were modified by the test to               **
**                    their original content.                                 **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType ClkmTst_lRestoreSmuAlarmsConfig
(
  ClkmTst_BackupDataType ClkmTst_BackupData
)
{
  Sl_TstRsltType        Result;
  Std_ReturnType        SmuResult;
  uint32                SmuAlarmId;

  /* Initialize the Return value to be test not executed */
  Result = CLKM_TESTNOTEXECUTED;

  /*Restore Clock monitor modules alarm actions from backup variable */
  SmuAlarmId = (uint32)SMU_ALARM_ACTION_STM_INDEX;

  /* If there is a error on setting the alarm action, further alarms
   * are not set and hence no need to check for invalid alarm action
   * for all alarms
   */
  while(SmuAlarmId <= (uint32)SMU_ALARM_ACTION_ADC_INDEX)
  {
    SmuResult = Smu_SetAlarmAction
                   (SMU_ALARM_GROUP_CLKM,
                    ClkmTst_kSmuAlarmId[SmuAlarmId],
                    ClkmTst_BackupData.AlmActionBackup[SmuAlarmId]
                   );
    /* If set Alarm fails, the return value is updated for error */
    if(SmuResult != (Std_ReturnType)E_OK)
    {
      Result = CLKM_SMU_SETALMACTION_ERR;
    }

    SmuAlarmId++;
  }

  if(Result  == CLKM_TESTNOTEXECUTED)
  {
    /* Initialize the return value to be success */
    Result = CLKM_SUCCESS;
  }
  
  return Result;
}/* ClkmTst_lRestoreSmuAlarmsConfig */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : void ClkmTst_lSetupClockMonitorsTooLow(void)            **
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
** Return value     : None                                                    **
**                                                                            **
** Description      : This function configures all seven clock monitors       **
**                    depending on user configuration settings of too low     **
**                    frequency.                                              **
**                                                                            **
*******************************************************************************/
static void ClkmTst_lSetupClockMonitorsTooLow(void)
{ 
   uint8 ChipRevNo = 0U;
   volatile uint32 CCUCON3Value = 0U;
   volatile uint32 CCUCON4Value = 0U;
   
 #if (CLKMTST_TEST_PLLERAY_CLOCK == TRUE)
  volatile uint8 Clkm_PLLERAYMode = 0U;
 #endif
 
  /* disable the write-protection for registers */
   Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);
   
   ChipRevNo = (uint8)(((uint8)(SCU_CHIPID.B.CHREV)) \
                                            & CHIPID_CHREV_STEP_OFFSET); 

    /* Bits[3:0] of CHREV(Chip Revision Number):
            0000b for A-step silicon
            0001b for B-step silicon
            0010b for C-step silicon
			
    Due to a limitation in the TC27XCA, TC27XDB, TC26XBB, 
	TC29XBB, TC23XAB, TC22XAB, and TC21XAB devices, Target 
	Monitoring Frequencies 7.5 MHz and 6.6 MHz are not monitored
	as in rare cases unexpected SMU alarms may occur sporadically or 
	continuously for the respective clock monitors.*/
#if (CHIP_ID == 27U)
 if ((CLKM_TC27X_CA_STEP == ChipRevNo) || (CLKM_TC27X_DB_STEP == ChipRevNo) \
                                           || (CLKM_TC27X_BC_STEP == ChipRevNo))
#elif (CHIP_ID == 26U)
if (CLKM_TC26X_BB_STEP == ChipRevNo)
#elif (CHIP_ID == 29U)
if (CLKM_TC29X_BB_STEP == ChipRevNo)
#elif ((CHIP_ID == 21U) || (CHIP_ID == 22U) || (CHIP_ID == 23U))
if (CLKM_EPDEVICES_AB_STEP == ChipRevNo)	
#endif 
  { 
 	#if (CLKMTST_TEST_PLLERAY_CLOCK == TRUE)
	 /* Check PLL_ERAY is in Power Saving Mode or in Normal Mode */
	 /* Monitor PLLERAY only when it is in Normal Mode */
     Clkm_PLLERAYMode = SCU_PLLERAYCON0.B.PLLPWD ;

    if(CLKM_PLLERAYCON0_PLLPWD == Clkm_PLLERAYMode)
    {
	  CCUCON3Value = (unsigned_int)CLKM_CCUCON3_PLLERAY_LOWVAL_6MHZ;
    }
    #endif

     CCUCON3Value |= (unsigned_int)CLKM_CCUCON3_LOWVAL_6MHZ;

     SCU_CCUCON3.U = CCUCON3Value;
 
    if((uint32)SCU_CCUCON1.B.GTMDIV != CLKM_MOD_CLK_STOPPED)
    {
     CCUCON4Value = (unsigned_int)CLKM_CCUCON4_GTM_LOWVAL_6MHZ;
    }

    if((uint32)SCU_CCUCON1.B.STMDIV != CLKM_MOD_CLK_STOPPED)
    {
      CCUCON4Value |= (unsigned_int)CLKM_CCUCON4_STM_LOWVAL_6MHZ; 
    }

    CCUCON4Value |= (unsigned_int)CLKM_CCUCON4_SPB_LOWVAL_6MHZ;

    SCU_CCUCON4.U = CCUCON4Value;
 
    #if (CLKMTST_TEST_ADC_CLOCK == TRUE)
    if((uint32)SCU_CCUCON0.B.ADCCLKSEL != CLKM_MOD_CLK_STOPPED)
    {
      SCU_CCUCON9.U = (unsigned_int)CLKM_CCUCON9_LOWVAL_6MHZ;
    }
    #endif
  }
  else
  {
	 #if (CLKMTST_TEST_PLLERAY_CLOCK == TRUE)
	 /* Check PLL_ERAY is in Power Saving Mode or in Normal Mode */
	 /* Monitor PLLERAY only when it is in Normal Mode */
     Clkm_PLLERAYMode = SCU_PLLERAYCON0.B.PLLPWD ;

    if(CLKM_PLLERAYCON0_PLLPWD == Clkm_PLLERAYMode)
    {
	  CCUCON3Value = (unsigned_int)CLKM_CCUCON3_PLLERAY_LOWVAL_7_5MHZ;
    }
    #endif

     CCUCON3Value |= (unsigned_int)CLKM_CCUCON3_LOWVAL_7_5MHZ;

     SCU_CCUCON3.U = CCUCON3Value;
 
    if((uint32)SCU_CCUCON1.B.GTMDIV != CLKM_MOD_CLK_STOPPED)
    {
     CCUCON4Value = (unsigned_int)CLKM_CCUCON4_GTM_LOWVAL_7_5MHZ;
    }

    if((uint32)SCU_CCUCON1.B.STMDIV != CLKM_MOD_CLK_STOPPED)
    {
      CCUCON4Value |= (unsigned_int)CLKM_CCUCON4_STM_LOWVAL_7_5MHZ; 
    }

    CCUCON4Value |= (unsigned_int)CLKM_CCUCON4_SPB_LOWVAL_7_5MHZ;

    SCU_CCUCON4.U = CCUCON4Value;
 
    #if (CLKMTST_TEST_ADC_CLOCK == TRUE)
    if((uint32)SCU_CCUCON0.B.ADCCLKSEL != CLKM_MOD_CLK_STOPPED)
    {
      SCU_CCUCON9.U = (unsigned_int)CLKM_CCUCON9_LOWVAL_7_5MHZ;
    }
    #endif 
  }
  
  /* Update the CCU CON by update request */
  SCU_CCUCON3.B.UP = CLKMTST_UPDATE_CCUCON;

  #if (CLKMTST_TEST_ADC_CLOCK == TRUE)
  if((uint32)SCU_CCUCON0.B.ADCCLKSEL != CLKM_MOD_CLK_STOPPED)
  {
	SCU_CCUCON9.B.UP = CLKMTST_UPDATE_CCUCON;
  }
  #endif
  
  /* Enable the write-protection for registers */
  Mcal_SetSafetyENDINIT_Timed();
  
}/* ClkmTst_lSetupClockMonitorsTooLow */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : void ClkmTst_lSetupClockMonitorsTooHigh(void)           **
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
** Return value     : None                                                    **
**                                                                            **
** Description      : This function configures all seven clock monitors       **
**                    depending on user configuration settings of too high    **
**                    frequency.                                              **
**                                                                            **
*******************************************************************************/
static void ClkmTst_lSetupClockMonitorsTooHigh(void)
{
  volatile uint32 CCUCON3Value = 0U;
  volatile uint32 CCUCON4Value = 0U;

  #if (CLKMTST_TEST_PLLERAY_CLOCK == TRUE)
   volatile uint8 Clkm_PLLERAYMode = 0U;
  #endif
 
 /* disable the write-protection for registers */
  Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);
  
#if (CLKMTST_TEST_PLLERAY_CLOCK == TRUE)
  /* Check PLL_ERAY is in Power Saving Mode or in Normal Mode */
  /* Monitor PLLERAY only when it is in Normal Mode */
  Clkm_PLLERAYMode = SCU_PLLERAYCON0.B.PLLPWD ;

  if(CLKM_PLLERAYCON0_PLLPWD == Clkm_PLLERAYMode)
  {
	CCUCON3Value = (unsigned_int)CLKM_CCUCON3_PLLERAY_HIGHVAL;
  }
#endif
 
  CCUCON3Value |= (unsigned_int)CLKM_CCUCON3_HIGHVAL;
  
  SCU_CCUCON3.U = CCUCON3Value;
  
 if((uint32)SCU_CCUCON1.B.GTMDIV != CLKM_MOD_CLK_STOPPED)
 {
   CCUCON4Value = (unsigned_int)CLKM_CCUCON4_GTM_HIGHVAL;
 }

 if((uint32)SCU_CCUCON1.B.STMDIV != CLKM_MOD_CLK_STOPPED)
 {
	CCUCON4Value |= (unsigned_int)CLKM_CCUCON4_STM_HIGHVAL;
 }

 CCUCON4Value |= (unsigned_int)CLKM_CCUCON4_SPB_HIGHVAL;

 SCU_CCUCON4.U  = CCUCON4Value;
 
#if (CLKMTST_TEST_ADC_CLOCK == TRUE)
  if((uint32)SCU_CCUCON0.B.ADCCLKSEL != CLKM_MOD_CLK_STOPPED)
  {
   SCU_CCUCON9.U = (unsigned_int)CLKM_CCUCON9_HIGHVAL;
  }
#endif

  /* Update the CCU CON by update request */
  SCU_CCUCON3.B.UP = CLKMTST_UPDATE_CCUCON;
#if (CLKMTST_TEST_ADC_CLOCK == TRUE)
 if((uint32)SCU_CCUCON0.B.ADCCLKSEL != CLKM_MOD_CLK_STOPPED)
 {
    SCU_CCUCON9.B.UP = CLKMTST_UPDATE_CCUCON;
 }
#endif

  /* Enable the write-protection for registers */
  Mcal_SetSafetyENDINIT_Timed();
}/* ClkmTst_lSetupClockMonitorsTooHigh */


/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : void ClkmTst_lCalculateSignature                        **
**                    (uint32* const TstSignature)                            **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : TstSignature                                            **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function calculates test signature with SMU alarms **
**                    status and SCU_CCUCON3, SCU_CCUCON4 and SCU_CCUCON9 reg **
**                                                                            **
*******************************************************************************/
static void ClkmTst_lCalculateSignature
(uint32* const TstSignature)
{
  /* Update the Test signature */
  *TstSignature = (uint32)CRC32(*TstSignature,
                         (CLKMTST_CCUCON3_CONFIG_MASK & SCU_CCUCON3.U));
  *TstSignature = (uint32)CRC32(*TstSignature,
                         (CLKMTST_CCUCON4_CONFIG_MASK & SCU_CCUCON4.U));

#if (CLKMTST_TEST_ADC_CLOCK == TRUE)
  *TstSignature = (uint32)CRC32(*TstSignature,
                         (CLKMTST_CCUCON9_CONFIG_MASK & SCU_CCUCON9.U));
#endif
}

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : void ClkmTst_lRestoreClockMonitors                      **
**                      (ClkmTst_BackupDataType ClkmTst_BackupData)           **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : ClkmTst_BackupData : Back up of registers               **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function restores the clock monitor setup to       **
**                    SCU_CCUCON3, SCU_CCUCON4 and SCU_CCUCON9 registers.     **
**                                                                            **
*******************************************************************************/
static void ClkmTst_lRestoreClockMonitors
(
  ClkmTst_BackupDataType ClkmTst_BackupData
)
{
  /* disable the write-protection for registers */
  Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);

  SCU_CCUCON3.U = (unsigned_int)(ClkmTst_BackupData.CCUCON3Backup);
  SCU_CCUCON4.U = (unsigned_int)(ClkmTst_BackupData.CCUCON4Backup);

#if (CLKMTST_TEST_ADC_CLOCK == TRUE)
  SCU_CCUCON9.U = (unsigned_int)(ClkmTst_BackupData.CCUCON9Backup);
#endif

  /* Update the CCU CON by update request */
  SCU_CCUCON3.B.UP = CLKMTST_UPDATE_CCUCON;

#if (CLKMTST_TEST_ADC_CLOCK == TRUE)
  SCU_CCUCON9.B.UP = CLKMTST_UPDATE_CCUCON;
#endif

  /* In case of a clock error the CCU switches to the back-up clock 
     fBACK as clock source 
  */
  /* Rewrite CCUCON0 register */
  SCU_CCUCON0.U = (ClkmTst_BackupData.CCUCON0Backup);

  SCU_CCUCON0.B.UP = CLKMTST_UPDATE_CCUCON;


  /* Enable the write-protection for registers */
  Mcal_SetSafetyENDINIT_Timed();
} /* ClkmTst_lRestoreClockMonitors */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static void ClkmTst_lDisableClockMonitors(void)         **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : ClkmTst_BackupData - Backup of Application configured   **
**                    CLKM registers                                          **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function restores the clock monitor setup to       **
**                    SCU_CCUCON3, SCU_CCUCON4 and SCU_CCUCON9 registers.     **
**                                                                            **
*******************************************************************************/
static void ClkmTst_lDisableClockMonitors
(
  ClkmTst_BackupDataType  ClkmTst_BackupData
)
{
  /* disable the write-protection for registers */
  Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);

  SCU_CCUCON3.U = 0U;
  SCU_CCUCON4.U = 0U;

#if (CLKMTST_TEST_ADC_CLOCK == TRUE)
  SCU_CCUCON9.U = 0U;
#endif

  /* Update the CCU CON by update request */
  SCU_CCUCON3.B.UP = CLKMTST_UPDATE_CCUCON;
#if (CLKMTST_TEST_ADC_CLOCK == TRUE)
  SCU_CCUCON9.B.UP = CLKMTST_UPDATE_CCUCON;
#endif

  /* In case of a clock error the CCU switches to the back-up clock 
     fBACK as clock source */
  /* Rewrite CCUCON0 register */
  SCU_CCUCON0.U = (ClkmTst_BackupData.CCUCON0Backup);

  SCU_CCUCON0.B.UP = CLKMTST_UPDATE_CCUCON;

  /* Enable the write-protection for registers */
  Mcal_SetSafetyENDINIT_Timed();
} /* ClkmTst_lDisableClockMonitors */

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : Sl_TstRsltType ClkmTst_lClearSmuAlarms(void)            **
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
** Return value     : CLKM_SUCCESS - Test succeeded                           **
**                    <Error ID> - Type of error during test                  **
**                                                                            **
** Description      : This function clears all SMU alarms triggered by        **
**                    the clock monitor test.                                 **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType ClkmTst_lClearSmuAlarms(void)
{
  Sl_TstRsltType        Result;
  Std_ReturnType        SmuResult;
  uint32                SmuAlarmId;

  /* Initialize the return value to be test not executed */
  Result = CLKM_TESTNOTEXECUTED;

  /*Clear Clock monitor modules alarms */
  SmuAlarmId = (uint32)SMU_ALARM_ACTION_STM_INDEX;
  do
  {
    SmuResult = Smu_ClearAlarmStatus
                   (SMU_ALARM_GROUP_CLKM,ClkmTst_kSmuAlarmId[SmuAlarmId]);

    /* If Clear Alarm fails, the return value is updated for error */
    if(SmuResult != (Std_ReturnType)E_OK)
    {
      Result = CLKM_SMU_CLRALMSTS_ERR;
    }

    SmuAlarmId++;

  }while(SmuAlarmId <= (uint32)SMU_ALARM_ACTION_ADC_INDEX);

  if(Result == CLKM_TESTNOTEXECUTED)
  {
    Result = CLKM_SUCCESS;
  }
  return Result;
} /* ClkmTst_lClearSmuAlarms */

/*******************************************************************************
** Traceability      : [cover parentID=]        [/cover]                      **
**                                                                            **
** Syntax           : Sl_TstRsltType ClkmTst_lCheckSmuAlarm                   **
**                    (uint32 AlarmCheck,uint32 Clkm_SmuAlarmMask)            **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : AlarmCheck : value for which the alarm is checked       **
**                    Clkm_SmuAlarmMask : Mask for the alarms which are tested**
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : CLKM_SUCCESS - Test succeeded                           **
**                    <Error ID> - Type of error during test                  **
**                                                                            **
** Description      : Check the SMU alarm for all monitored frequency         **
**                                                                            **
*******************************************************************************/

static Sl_TstRsltType ClkmTst_lCheckSmuAlarm
(
  uint32 AlarmCheck,
  uint32 Clkm_SmuAlarmMask
)
{
  uint32                Timeout;
  Sl_TstRsltType        Result;
  Std_ReturnType        SmuResult;
  uint32                ClkmTstAlarmStatus = 0U;

  Timeout = CLKM_NO_FAULT_TIMEOUT;

  /* Initialize the return value to be timeout */
  Result = CLKM_TIMEOUT_ALM;


  do
  {
    SmuResult = Smu_GetAlarmStatus(SMU_ALARM_GROUP_CLKM, &ClkmTstAlarmStatus);

    ClkmTstAlarmStatus = (ClkmTstAlarmStatus & Clkm_SmuAlarmMask);

    /* Successfully read the Group alarm status */
    if((Std_ReturnType)E_OK == SmuResult)
    {

      /* Check for PLL Clock monitor test alarms set.
       * If not, return value is specific Timeout error.
       */
      if(ClkmTstAlarmStatus == AlarmCheck)
      {
        Result = CLKM_SUCCESS;
      }
    }
    else
    {
      /* Test fails during the read of alarm status */
      Result = CLKM_SMU_GETALMSTS_ERR;
    }
    Timeout = Timeout - 1U;
  }
  while((Timeout != 0U) && (CLKM_TIMEOUT_ALM == Result));

  return Result;
}

/*******************************************************************************
** Traceability      : [cover parentID=]        [/cover]                      **
**                                                                            **
** Syntax           : Sl_TstRsltType ClkmTst_lExecuteTest                     **
**                    (uint32* const TstSignature,                            **
**                     ClkmTst_BackupDataType ClkmTst_BackupData,             **
**                     uint32 Clkm_SmuAlarmMask)                              **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : ClkmTst_BackupData - Backup of registers                **
**                    Clkm_SmuAlarmMask - Mask to check the enabled Clkm      **
**                    SMU alarms                                              **
**                                                                            **
** Parameters (out) : TstSignature : Test signature generated by the test     **
**                                                                            **
** Return value     : CLKM_SUCCESS - Test succeeded                           **
**                    <Error ID> - Type of error during test                  **
**                                                                            **
** Description      : It first configures all seven clock monitors frequency  **
**                    to too low and checks that a SMU alarm is generated for **
**                    each clock monitor.                                     **
**                    All clock monitors are then restored, so that the       **
**                    monitored frequency gets valid, the SMU alarms are      **
**                    cleared and checked that no new SMU alarm is generated. **
**                    Finally the clock monitor are set to monitored          **
**                    frequencies of too high and again a SMU alarm is        **
**                    expected.                                               **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType ClkmTst_lExecuteTest
(
  uint32* const TstSignature,
  ClkmTst_BackupDataType ClkmTst_BackupData,
  uint32 Clkm_SmuAlarmMask
)
{

  Sl_TstRsltType        SmuClrAlmResult;
  Sl_TstRsltType        Result;

  /* Setup clock monitor for testing the target frequency threshold */
  ClkmTst_lSetupClockMonitorsTooLow();

  /* Alarms to be checked and Alarm mask values are same */
  Result = ClkmTst_lCheckSmuAlarm(Clkm_SmuAlarmMask,Clkm_SmuAlarmMask);

  /* Calculate the test signature with configured CCUCON reg and 
     SMU alarm status
   */
  if(Result == CLKM_SUCCESS)
  {
    ClkmTst_lCalculateSignature(TstSignature);
  }
  
  /* Disable the clock monitors */
  ClkmTst_lDisableClockMonitors(ClkmTst_BackupData);

  /* Clear SMU alarms */
  SmuClrAlmResult = ClkmTst_lClearSmuAlarms();

  /* If Clear Alarm status fails and
   * Previous state of Tests Results are all success, then
   * return value is updated with Clear alarm status error
   * else return error will be the test error when checking the SMU alarms.
   */
  if((SmuClrAlmResult != CLKM_SUCCESS) && (Result == CLKM_SUCCESS))
  {
    Result = SmuClrAlmResult;
  }

  if(Result == CLKM_SUCCESS)
  {

    ClkmTst_lRestoreClockMonitors(ClkmTst_BackupData);

    /* Check for the no SMU alarms are set */
    Result = ClkmTst_lCheckSmuAlarm(CLKM_SMU_ALARM_RESET,Clkm_SmuAlarmMask);

    if(Result == CLKM_SUCCESS)
    {
      /* Setup clock monitor for testing the target frequency threshold */
      ClkmTst_lSetupClockMonitorsTooHigh();

      /* Alarms to be checked and Alarm mask values are same */
      Result = ClkmTst_lCheckSmuAlarm(Clkm_SmuAlarmMask,Clkm_SmuAlarmMask);

      /* Calculate the test signature with configured CCUCON reg and 
         SMU alarm status
       */
      if(Result == CLKM_SUCCESS)
      {
        ClkmTst_lCalculateSignature(TstSignature);
      }

      /* Disable the clock monitors */
      ClkmTst_lDisableClockMonitors(ClkmTst_BackupData);

      /* Clear SMU alarms */
      SmuClrAlmResult = ClkmTst_lClearSmuAlarms();

      /* Restore back the clock monitors which have been changed for the test */
      ClkmTst_lRestoreClockMonitors(ClkmTst_BackupData);
      
      /* If Clear Alarm status fails and
       * Previous state of Tests Results are all success, then
       * return value is updated with Clear alarm status error
       * else return error will be the test error when checking the SMU alarms.
       */
      if((SmuClrAlmResult != CLKM_SUCCESS) && (Result == CLKM_SUCCESS))
      {
        Result = SmuClrAlmResult;
      }
      
    }
  }

  return Result;
} /* ClkmTst_lExecuteTest */

/*******************************************************************************
** Traceability      : [cover parentID=]        [/cover]                      **
**                                                                            **
** Syntax           : Sl_TstRsltType ClkmTst_ClkmTst                          **
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
**                                    used for test execution                 **
**                    TstSeed : Seed to be used for generating the signature  **
**                                                                            **
** Parameters (out) : TstSignature : Test signature generated by the test     **
**                                                                            **
** Return value     : CLKM_SUCCESS - Test succeeded                           **
**                    <Error ID> - Type of error during test                  **
**                                                                            **
** Description      : API provided for the clock monitor test.                **
**                    It is responsible for test preparation, test execution  **
**                    and final test restoration.                             **
**                                                                            **
*******************************************************************************/
Sl_TstRsltType ClkmTst_ClkmTst
(
  const Sl_ParamSetType ParamSetIndex,
  const uint8 TstSeed,
  uint32* const TstSignature
)
{
  Sl_TstRsltType         Result;
  Sl_TstRsltType         RestoreAlmConfigResult;
  ClkmTst_BackupDataType ClkmTst_BackupData;
  uint8                  ClkmTst_RestoreAlmFlag;
  uint32                 Clkm_SmuAlarmMask;

  UNUSED_PARAMETER(ParamSetIndex);
  
  *TstSignature = (uint32)CRC32((uint32)TEST_ID_CLKM_TST,(uint32)TstSeed);

  /* Set the Restore of SMU Alarm config to NO */
  ClkmTst_RestoreAlmFlag = CLKMTST_NO_RESTORE_SMUALM_CONIG;

  /* Prepare and check SMU for Clock monitor test */
  Result = ClkmTst_lInit(&ClkmTst_BackupData, 
                         &ClkmTst_RestoreAlmFlag,
                         &Clkm_SmuAlarmMask);

  if(CLKM_SUCCESS == Result)
  {
    Result = ClkmTst_lExecuteTest(TstSignature,
                                  ClkmTst_BackupData,
                                  Clkm_SmuAlarmMask);
  }

  /* Check if the SMU alarm configuration to be restored */
  if(ClkmTst_RestoreAlmFlag == CLKMTST_RESTORE_SMUALM_CONIG)
  {
    /* Restore back the SMU alarm configurations */
    RestoreAlmConfigResult = ClkmTst_lRestoreSmuAlarmsConfig
                                (ClkmTst_BackupData);

   /* If Restore alarm config fails and
      * Previous state of Tests Results are all success, then
      * return value is updated with set alarm config error
      * else return error will be the previous error state only.
      */
    if((RestoreAlmConfigResult != CLKM_SUCCESS) && (Result == CLKM_SUCCESS))
    {
      Result = RestoreAlmConfigResult;
    }
  }

   /* Add final test result to test signature: */
  *TstSignature = (uint32)CRC32(*TstSignature, (uint32)Result);

  return Result;
}

#define IFX_CLKM_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
