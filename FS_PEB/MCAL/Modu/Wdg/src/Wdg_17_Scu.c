/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2017)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  $FILENAME   : Wdg_17_Scu.c $                                             **
**                                                                           **
**  $CC VERSION : \main\105 $                                                **
**                                                                           **
**  $DATE       : 2017-12-28 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains functionality of WDG driver.            **
**                                                                           **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: NO                                      **
**                                                                           **
******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/*  TRACEABILITY: [cover parentID=SAS_NAS_ALL_PR749,SAS_NAS_ALL_PR470,
                 SAS_NAS_ALL_PR70,SAS_NAS_ALL_PR1652,SAS_NAS_ALL_PR630_PR631]   
                   [/cover]                                                  */

/* WDG061: Inclusion structure */
  /* Inclusion of controller sfr file */
#include "IfxScu_reg.h"
#include "IfxScu_bf.h"

/* Global functions like Set/Reset END INIT protection bit,
  Enable/Disable interrupts, Automic write function */
#include "Mcal.h"
/* Inclusion of Wdg module header file */
#include "Wdg_17_Scu.h"
#if (WDG_MAXQM_TIMERS != 0U)
#include "Wdg_17_Scu_Local.h"
#endif

/* Include WDG Schm files  */
#include "SchM_17_McalCfg.h"
#include SCHM_WDG_17_SCU_HEADER

/* Include Safe WDG header file */
#if (WDG_MAXSAFE_TIMERS != 0U)
#include "Wdg_17_Scu_Safe.h"
#endif

/* Include SchM_Wdg header file to export EA access functions */
/* Traceability : [cover parentID=DS_AS_WDG040][/cover]         */


#if (WDG_MAXQM_TIMERS != 0U)
/* Include Wdg_Cbk File*/
#include "Wdg_17_Scu_Cbk.h"

/* Gtm related information are brought in from here */
#include "Gtm.h"
#endif

/** Traceability : [cover parentID=SAS_AS_WDG062, DS_AS_WDG110][/cover]  */
#if((WDG_DISABLE_REJECT_DEM_REPORT == ENABLE_DEM_REPORT) ||                 \
    (WDG_MODE_FAIL_DEM_REPORT == ENABLE_DEM_REPORT) ||                      \
    (WDG_INIT_FAILED_DEM_REPORT == ENABLE_DEM_REPORT))
#include "Dem.h"
#endif


/*******************************************************************************
**                      Imported Compiler Switch Checks                       **
*******************************************************************************/

#ifndef WDG_17_SCU_AR_RELEASE_MAJOR_VERSION
  #error "WDG_17_SCU_AR_RELEASE_MAJOR_VERSION is not defined. "
#endif

#ifndef WDG_17_SCU_AR_RELEASE_MINOR_VERSION
  #error "WDG_17_SCU_AR_RELEASE_MINOR_VERSION is not defined. "
#endif

#ifndef WDG_17_SCU_AR_RELEASE_REVISION_VERSION
  #error "WDG_17_SCU_AR_RELEASE_REVISION_VERSION is not defined. "
#endif

#if ( WDG_17_SCU_AR_RELEASE_MAJOR_VERSION != 4U)
  #error "WDG_17_SCU_AR_RELEASE_MAJOR_VERSION does not match. "
#endif

#if ( WDG_17_SCU_AR_RELEASE_MINOR_VERSION != 0U )
  #error "WDG_17_SCU_AR_RELEASE_MINOR_VERSION does not match. "
#endif

#ifndef WDG_17_SCU_SW_MAJOR_VERSION
  #error "WDG_17_SCU_SW_MAJOR_VERSION is not defined. "
#endif

#ifndef WDG_17_SCU_SW_MINOR_VERSION
  #error "WDG_17_SCU_SW_MINOR_VERSION is not defined. "
#endif

#ifndef WDG_17_SCU_SW_PATCH_VERSION
  #error "WDG_17_SCU_SW_PATCH_VERSION is not defined. "
#endif

/* Check for Correct inclusion of headers */
#if ( WDG_17_SCU_SW_MAJOR_VERSION != 3U )
  #error "WDG_17_SCU_SW_MAJOR_VERSION does not match. "
#endif

#if ( WDG_17_SCU_SW_MINOR_VERSION != 5U )
  #error "WDG_17_SCU_SW_MINOR_VERSION does not match. "
#endif

/* Traceability : [cover parentID=DS_AS40X_WDG087][/cover]                    */
/*------------------------------------------------------------------------------
                            DEM File inclusion
------------------------------------------------------------------------------*/
/*If DEM is enabled, the check for DEM versions*/
#if( (WDG_DISABLE_REJECT_DEM_REPORT == ENABLE_DEM_REPORT) ||\
     (WDG_MODE_FAIL_DEM_REPORT == ENABLE_DEM_REPORT) )

#ifndef DEM_AR_RELEASE_MAJOR_VERSION
  #error "DEM_AR_RELEASE_MAJOR_VERSION is not defined. "
#endif
#ifndef DEM_AR_RELEASE_MINOR_VERSION
  #error "DEM_AR_RELEASE_MINOR_VERSION is not defined. "
#endif

#if (IFX_DEM_VERSION_CHECK == STD_ON)

#if ( DEM_AR_RELEASE_MAJOR_VERSION != 4U )
  #error "DEM_AR_RELEASE_MAJOR_VERSION does not match. "
#endif
#if ( DEM_AR_RELEASE_MINOR_VERSION != 0U )
  #error "DEM_AR_RELEASE_MINOR_VERSION does not match. "
#endif

#endif /*  (IFX_DEM_VERSION_CHECK == STD_ON)  */

#endif
/*------------------------------------------------------------------------------
                            DET File inclusion
------------------------------------------------------------------------------*/

#if (WDG_DEV_ERROR_DETECT == STD_ON)

#ifndef DET_AR_RELEASE_MAJOR_VERSION
  #error "DET_AR_RELEASE_MAJOR_VERSION is not defined. "
#endif
#ifndef DET_AR_RELEASE_MINOR_VERSION
  #error "DET_AR_RELEASE_MINOR_VERSION is not defined. "
#endif
#if (IFX_DET_VERSION_CHECK == STD_ON)

#if ( DET_AR_RELEASE_MAJOR_VERSION != 4U )
  #error "DET_AR_RELEASE_MAJOR_VERSION does not match. "
#endif
#if ( DET_AR_RELEASE_MINOR_VERSION != 0U )
  #error "DET_AR_RELEASE_MINOR_VERSION does not match. "
#endif

#endif /* (IFX_DET_VERSION_CHECK == STD_ON) */
#endif /*End for WDG_DEV_ERROR_DETECT */
/*----------------------------------------------------------------------------*/

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/


/* Masks the 16bit WDT reload value */
#define WDG_MASK_WDTREL                (0xFFFF0000U)

/* Sets the WDTIR bit and enables the watchdog by resetting WDTDR
   bit in WDTCON1 */
#define WDG_SET_WDTIR_RESET_WDTDR      (0x00000004U)

/* Resets the WDTIR bit and enables the watchdog by resetting WDTDR
   bit in WDTCON1 */
#define WDG_RESET_WDTIR_RESET_WDTDR    (0x00000000U)

/* Mask for Watchdog status in WDTSR*/
#define WDG_STATUS_MASK                 (0x0000003CU)

/* This is the reload value which will triiger an almost instant reset */
#define WDG_INSTANT_RESET_RELOAD_VALUE (0xFFFFU) /* 1 tick near reset */

/* Shift value of REL in WDTCPU0CON0 SFR*/
#define WDG_REL_SHIFT_VALUE             (16U)

/* To mask password */
#define WDT_PASS_MASK                  (0x0000FFFCU)

/* Password mask BIT[15:8] */
#define WDT_PASS_UPPER_MASK            (0x0000FF00U)

/* Password mask BIT[7:2] */
#define WDT_PASS_LOWER_MASK            (0x000000FCU)

/* Set LCK and ENDINIT bit in WDTCPUxCON0*/
#define WDT_SETLCK_ENDINIT             (0x00000003U)

/* Register Mapping for WDG */
#define WDG_REGMAP       ((Ifx_SCU_WDTCPU*)(void*)&(SCU_WDTCPU0_CON0))

#define WDG_CON1_DR_SETMASK            (0x00000008U)
#define WDG_CON1_DR_CLEARMASK          (0xFFFFFFFFU)
#define WDG_SR_TO_MASK                 (0x00000010U)
#define WDG_SR_DS_MASK                 (0x00000008U)
#define WDG_SR_TO_BITPOS               (4U)
#define WDG_SR_DS_BITPOS               (3U)

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
#define WDG_17_SCU_START_SEC_CODE
#include "MemMap.h"


/* Function to Access password before accessing ENDINIT registers */
IFX_LOCAL_INLINE uint32 Wdg_lAccessPassword(uint32 WdtCon0);

/* Function to Check if  Password Sequencing Or Time Checking is enabled */
IFX_LOCAL_INLINE Std_ReturnType Wdg_lCheckPassSeqOrTimeCheck(void);

/* Function to Modify the ENDINIT registers */
IFX_LOCAL_INLINE uint32 Wdg_lReloadModifyAccess(uint16 ReloadValue);

/* Calculate password to be put in the CON0 SFR */
IFX_LOCAL_INLINE uint32 Wdg_lModifyAccessPassword(uint32 PasswordAccess);

#if (WDG_MAXQM_TIMERS != 0U)
/* WDGx QM initialization */
static void Wdg_lQmInit(const Wdg_17_Scu_ConfigType* ConfigPtr); 
  
/* Function to change mode of WDG. Available modes are WDGIF_OFF_MODE,
   WDGIF_SLOW_MODE and WDGIF_FAST_MODE*/
/*  [cover parentID=DS_NAS_WDG_PR734] [/cover]  */
static Std_ReturnType Wdg_lChangeMode(WdgIf_ModeType Mode, uint8 ServiceId);

/*Function to operate the Service timer in respective WDG mode */
static void Wdg_lStartOrStopTimeEngine(WdgIf_ModeType Mode, uint8 ServiceId);

/* Function to calculate Timeout counter */
static void Wdg_lTimeoutHandler(WdgIf_ModeType Mode, uint16 timeout,\
                                                           uint8 ServiceId);

/* Function to trigger the Watchdog Hardware cyclically */
static void Wdg_lTrigger(void);
  
#if (WDG_DEV_ERROR_DETECT == STD_ON)
/* Function to check if hardware specific Configuration paramenters
are in range */
static Std_ReturnType Wdg_lInitParamRangeCheck(void);

/* Funtion to check for DET during Mode Change for WDG */
static Std_ReturnType Wdg_lSetModeDetCheck(WdgIf_ModeType Mode);

#endif
 /* (WDG_DEV_ERROR_DETECT == STD_ON) */

#endif/*WDG_MAXQM_TIMERS != 0U */

#if (WDG_DEV_ERROR_DETECT == STD_ON)
/* Funtion to check for DET during WDG Init */
static Std_ReturnType Wdg_lInitDetCheck(const Wdg_17_Scu_ConfigType* ConfigPtr);

#endif

#define WDG_17_SCU_STOP_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
  allowed only for MemMap.h*/
#include "MemMap.h"

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/


/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/

#if(WDG_PB_FIXEDADDR == STD_ON)
#define WDG_17_SCU_START_SEC_CONST_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
  allowed only for MemMap.h*/
#include "MemMap.h" 
/* To store the Wdg driver configuration pointer (Fixed address) */
/*  TRACEABILITY: [cover parentID=DS_NAS_WDG_PR115][/cover] */
const Wdg_17_Scu_ConfigType * const Wdg_kConfigPtr = &Wdg_ConfigRoot[0];
#define WDG_17_SCU_STOP_SEC_CONST_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
  allowed only for MemMap.h*/
#include "MemMap.h"
#endif  /*(WDG_PB_FIXEDADDR == STD_ON)*/

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

#if(WDG_PB_FIXEDADDR == STD_OFF)

#define WDG_17_SCU_START_SEC_VAR_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
  allowed only for MemMap.h*/
#include "MemMap.h"

/* To store the Wdg Driver configuration pointer */
const Wdg_17_Scu_ConfigType *Wdg_kConfigPtr;

#define WDG_17_SCU_STOP_SEC_VAR_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
  allowed only for MemMap.h*/
#include "MemMap.h" 
#endif /*(WDG_PB_FIXEDADDR == STD_OFF)*/

/* Below variales are available for WDG QM */
#if(WDG_MAXQM_TIMERS != 0U)

#define WDG_17_SCU_START_SEC_VAR_16BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
  allowed only for MemMap.h*/
#include "MemMap.h"

/*  [cover parentID=DS_AS40X_WDG153] [/cover]  */
#if (WDG_DEBUG_SUPPORT == STD_ON)
/* Wdg Timeout counter */
/*IFX_MISRA_RULE_08_10_STATUS=Variable Wdg_TimeoutCounter is declared as
 extern in Wdg_17_Scu_Dbg.h, which will be included application for
 debugging*/
uint16 Wdg_TimeoutCounter[WDG_MAX_TIMERS];
#else
static uint16 Wdg_TimeoutCounter[WDG_MAX_TIMERS];
#endif /*(WDG_DEBUG_SUPPORT == STD_ON)*/

static uint16 Wdg_CurrentReloadValue[WDG_MAX_TIMERS];

#define WDG_17_SCU_STOP_SEC_VAR_16BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
  allowed only for MemMap.h*/
#include "MemMap.h"

#define WDG_17_SCU_START_SEC_VAR_UNSPECIFIED
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
  allowed only for MemMap.h*/
#include "MemMap.h"

/*  [cover parentID=DS_AS40X_WDG152] [/cover]  */
#if (WDG_DEBUG_SUPPORT == STD_ON)
/* Driver Internal State, Assigned Default state: WDG_UNINIT */
/*IFX_MISRA_RULE_08_10_STATUS=Variable Wdg_17_Scu_DriverState is declared as
 extern in Wdg_17_Scu_Dbg.h, which will be included application for
 debugging*/
Wdg_17_Scu_StatusType Wdg_17_Scu_DriverState[WDG_MAX_TIMERS];
#elif (WDG_DEV_ERROR_DETECT == STD_ON)
/* Driver Internal State, Assigned Default state: WDG_UNINIT */
static Wdg_17_Scu_StatusType Wdg_17_Scu_DriverState[WDG_MAX_TIMERS];
#endif    /*(WDG_DEBUG_SUPPORT == STD_ON)*/

/*  [cover parentID=DS_AS40X_WDG154,DS_AS40X_WDG148] [/cover]  */
#if (WDG_DEBUG_SUPPORT == STD_ON)
/* Driver current mode */
/*IFX_MISRA_RULE_08_10_STATUS=Variable Wdg_17_Scu_DriverMode is declared as
 extern in Wdg_17_Scu_Dbg.h, which will be included application for
 debugging*/
WdgIf_ModeType Wdg_17_Scu_DriverMode[WDG_MAX_TIMERS];
#else
/* Driver current mode */
static WdgIf_ModeType Wdg_17_Scu_DriverMode[WDG_MAX_TIMERS];
#endif    /*(WDG_DEBUG_SUPPORT == STD_ON)*/

#define WDG_17_SCU_STOP_SEC_VAR_UNSPECIFIED
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
  allowed only for MemMap.h*/
#include "MemMap.h"
#endif 
/* WDG_MAXQM_TIMERS != 0U */
/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
#define WDG_17_SCU_START_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
  allowed only for MemMap.h*/
#include "MemMap.h"

/*******************************************************************************
** Syntax         :IFX_LOCAL_INLINE uint32 Wdg_lAccessPassword(uint32 WdtCon0) *
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : WDTCON0 register                                        **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : uint32 (modified wdtCon0)                               **
**                                                                            **
** Description      : Function to Access password before accessing ENDINIT    **
**                      registers                                             **
**                      Password Access:                                      **
**       - (Bits[15:8])Set previous password bits                             **
**       - (Bits[7:2]) calculate the Inverted bits from previous password     **
**       - (Bit[1]) Set WDTLCK to '0' to unlock SCU_WDTCPUx_CON0              **
**       - (Bit[0]) Set ENDINIT bit while password access                     **
*******************************************************************************/
IFX_LOCAL_INLINE uint32 Wdg_lAccessPassword(uint32 WdtCon0)
{
  /* "volatile" keyword added, to avoid incorrect assembly generation 
      by WINDRIVER compiler only */
  volatile uint32 lPasswordAccess;

  /* Keep bits[15:8] as is */
  lPasswordAccess = (uint32)(WdtCon0 & WDT_PASS_UPPER_MASK);
  /* Invert the bits[7:2] */ 
  lPasswordAccess |= (uint32)((uint32)(~WdtCon0) & WDT_PASS_LOWER_MASK);
  /* Set ENDINIT bit, Clear LCK bit */
  lPasswordAccess |= (uint32)(1U);
  /* Get Reload value */
  lPasswordAccess |= (uint32)(WdtCon0 & WDG_MASK_WDTREL);
  /* CON0 SFR with new password */
  return (lPasswordAccess);
}

/*******************************************************************************
** Syntax     :  IFX_LOCAL_INLINE Std_ReturnType Wdg_lCheckPassSeqOrTimeCheck **
**                                                        (void)              **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Re-entrant                                              **
**                                                                            **
** Parameters(in)   : void                                                    **
**                                                                            **
** Parameters (out) : RetVal                                                  **
**                                                                            **
** Return value     : E_OK/E_NOT_OK                                           **
**                                                                            **
** Description      : Function to Check if  Password Sequencing Or            **
**                    Time Checking is enabled                                **
*******************************************************************************/
IFX_LOCAL_INLINE Std_ReturnType Wdg_lCheckPassSeqOrTimeCheck(void)
{
  uint8 CoreId;
  uint32 lPassSeqOrTimeChck;
  Std_ReturnType RetVal;

  RetVal = E_OK;
  CoreId = WDG_SFR_INIT_GETCOREID();

  /* Create Mask value for PAS and TCS bit fields of Status register */
  lPassSeqOrTimeChck = (uint32)(((uint32)1U << IFX_SCU_WDTCPU_SR_PAS_OFF) |   \
                                ((uint32)1U << IFX_SCU_WDTCPU_SR_TCS_OFF));

  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently
    access into WDTCPUxSR SFR register */
  lPassSeqOrTimeChck &= \
                 (uint32)WDG_SFR_INIT_USER_MODE_READ32(WDG_REGMAP[CoreId].SR.U);

  if(lPassSeqOrTimeChck != 0U)
  {
    /* Time checking or Password Sequencing enabled */
    #if (WDG_INIT_FAILED_DEM_REPORT == ENABLE_DEM_REPORT)
    Dem_ReportErrorStatus((Dem_EventIdType)WDG_E_INIT_FAILED,                 \
                           DEM_EVENT_STATUS_FAILED);
    #endif
    RetVal = E_NOT_OK;
  }
  return RetVal;
}

/*******************************************************************************
** Syntax     :  IFX_LOCAL_INLINE uint32 Wdg_lModifyAccessPassword            **
**                                       (uint32 PasswordAccess)              **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Re-entrant                                              **
**                                                                            **
** Parameters(in)   : void                                                    **
**                                                                            **
** Parameters (out) : RetVal                                                  **
**                                                                            **
** Return value     : E_OK/E_NOT_OK                                           **
**                                                                            **
** Description      : Function to calculate the password to be                **
**                             put in CON0 SFR                                **
*******************************************************************************/
IFX_LOCAL_INLINE uint32 Wdg_lModifyAccessPassword(uint32 PasswordAccess)
{
  /* Calculate only password */
  PasswordAccess = (uint32)(PasswordAccess & WDT_PASS_MASK);
  
  /* Set LCK bit and ENDINIT Bit */
  PasswordAccess |= WDT_SETLCK_ENDINIT;

  return (PasswordAccess);
}

/*******************************************************************************
** Syntax           :IFX_LOCAL_INLINE uint32 Wdg_lReloadModifyAccess          **
**                                                (uint16 ReloadValue)        **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-reentrant                                           **
**                                                                            **
** Parameters(in)   : ReloadValue (in ticks)                                  **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : uint32 (modified Value)                                 **
**                                                                            **
** Description      : Function to Modify the ENDINIT registers                **
*******************************************************************************/
IFX_LOCAL_INLINE uint32 Wdg_lReloadModifyAccess(uint16 ReloadValue)
{
  /* Create Value for the bit field REL(Bit: 31:16) */
  return (uint32)((((uint32)(ReloadValue)) << WDG_REL_SHIFT_VALUE)&          \
                                 WDG_MASK_WDTREL);
}

/*******************************************************************************
** Traceability     : [cover parentID=DS_AS_WDG064, DS_AS_WDG001,
                      DS_AS_WDG019, DS_AS_WDG025, DS_AS_WDG089,DS_AS40X_WDG173,
                      DS_AS_WDG101, DS_AS_WDG051,DS_AS_WDG106_WDG100,
                      DS_NAS_WDG_PR759_PR760_PR761,DS_MCAL_WDG_050]           **
**                                                                            **
** Syntax           : void Wdg_17_Scu_Init( const Wdg_17_Scu_ConfigType       **
**                                                            *ConfigPtr )    **
**                    [/cover]                                                **
**                                                                            **
** Service ID       : 0                                                       **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-reentrant                                           **
**                                                                            **
** Parameters(in)   : ConfigPtr (Pointer to configuration set)                **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Driver Module Initialization function. This routine     **
**                    initializes the watchdog driver and watchdog hardware   **
**                    i.e it sets the default watchdog mode and timeout       **
**                    period as provided in the configuration set. This       **
**                    configuration set shall be chosen from a limited number **
**                    of statically configured sets.                          **
**                    - WDG001: WDG028:                                       **
*******************************************************************************/
void Wdg_17_Scu_Init(const Wdg_17_Scu_ConfigType* ConfigPtr)
{
#if (WDG_MAXSAFE_TIMERS != 0U)
  uint16 PasswordInit;
  uint8 SafeArrayIdx;
#endif

  Std_ReturnType ErrorFlag;
  uint8 CoreId;

  CoreId = WDG_SFR_INIT_GETCOREID();

  /* Wdg_lInitDetCheck checks ConfigPtr */
  #if (WDG_DEV_ERROR_DETECT == STD_ON)
  ErrorFlag = Wdg_lInitDetCheck(ConfigPtr);
  if(ErrorFlag != E_NOT_OK)
  #endif
   /*(WDG_DEV_ERROR_DETECT == STD_ON)*/
  {
    ErrorFlag = Wdg_lCheckPassSeqOrTimeCheck();
    if(ErrorFlag == E_OK)
    {
      #if(WDG_PB_FIXEDADDR == STD_OFF)
      Wdg_kConfigPtr = ConfigPtr;
      #else
      UNUSED_PARAMETER(ConfigPtr)
      #endif

      #if (WDG_MAXQM_TIMERS != 0U)
      /*WDGx QM driver initialization */
      if(Wdg_kConfigPtr->WdgSafetyProperty[CoreId] == 0U)
      {
        Wdg_lQmInit(Wdg_kConfigPtr);
      }/* WdgSafetyProperty[CoreId]==0U */
      #endif
  
      #if (WDG_MAXSAFE_TIMERS != 0U)
      /*WDGx safety driver initialization */ 
      if(Wdg_kConfigPtr->WdgSafetyProperty[CoreId] == 1U)
      {
        /* Get the index value for Initial password */
        SafeArrayIdx = (uint8)ConfigPtr->WdgSafeIndex[CoreId];
      
        /* get initial password*/
        PasswordInit = (uint16)ConfigPtr->InitialPassword[SafeArrayIdx];
      
        Wdg_lSafetyInit(Wdg_kConfigPtr, PasswordInit, WDG_INIT_ACCESS);
      }/* WdgSafetyProperty[CoreId] == 1U */
      #endif
    }
  } /* End of (ErrorFlag != E_NOT_OK) */
}/* End of Wdg_17_Scu_Init */

#if (WDG_MAXQM_TIMERS != 0U)
/*******************************************************************************
** Traceability     : [cover parentID=DS_AS_WDG064, DS_AS40X_WDG016,
                      DS_AS_WDG017, DS_AS_WDG018, DS_AS_WDG026,DS_AS_WDG107,
                      DS_AS_WDG031, DS_AS_WDG091, DS_AS_WDG103,DS_AS_WDG160,
                      DS_NAS_WDG_PR759_PR760_PR761]                           **
**                                                                            **
** Syntax           : Std_ReturnType Wdg_17_Scu_SetMode( WdgIf_ModeType Mode )**
**                    [/cover]                                                **
**                                                                            **
** Service ID       : 1                                                       **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-reentrant                                           **
**                                                                            **
** Parameters (in)  : WdgIf_ModeType Mode                                     **
**                      One of the following statically configured modes:     **
**                      1. WDGIF_OFF_MODE                                     **
**                      2. WDGIF_SLOW_MODE                                    **
**                      3. WDGIF_FAST_MODE                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Std_ReturnType (E_OK or E_NOT_OK)                       **
**                                                                            **
** Description      : By choosing one of a limited number of statically       **
**                    configured settings (e.g. toggle or window watchdog,    **
**                    different timeout periods) the watchdog driver and      **
**                    hardware can be switched between the following three    **
**                    different watchdog Modes Off or Slow or Fast:           **
**                    - WDG004:, WDG031:                                      **
*******************************************************************************/
Std_ReturnType Wdg_17_Scu_SetMode(WdgIf_ModeType Mode)
{
  uint16 TimeoutValue;
  WdgIf_ModeType PreviousMode;
  uint8 GtmModuleNumber;
  uint8 GtmChannelNumber;
  uint8 GtmArrayIdx;
  
  /* Return value indicating the result of this function execution:
       E_NOT_OK or E_OK*/
  Std_ReturnType ReturnValue;
  uint8 CoreId;
  CoreId = WDG_SFR_RUNTIME_GETCOREID();
  /* Report the development errors only if WDG_DEV_ERROR_DETECT is STD_ON */
  #if (WDG_DEV_ERROR_DETECT == STD_ON)
  /* Check for Idle State WDG017: */
  ReturnValue = Wdg_lSetModeDetCheck(Mode);

  if (ReturnValue==E_OK)
  #endif
  {
    /* Check if the Wachdog disable is not allowed */
    #if (WDG_DISABLE_ALLOWED == STD_OFF)
    /* Check if the requested mode is OFF_MODE but WDG Disable is not allowed,
       then report error */
    if (Mode == WDGIF_OFF_MODE)
    {
      #if (WDG_DISABLE_REJECT_DEM_REPORT == ENABLE_DEM_REPORT)
      /* Report Production errors to DEM - WDG010: WDG012: WDG026: WDG025:*/
      Dem_ReportErrorStatus((Dem_EventIdType)WDG_E_DISABLE_REJECTED,
                             DEM_EVENT_STATUS_FAILED);
      #endif
      /* Set error flag */
      ReturnValue = E_NOT_OK;
    }
    else
    {
      ReturnValue = E_OK;
    }

    if(ReturnValue == E_OK)
    #endif
    /* (WDG_DISABLE_ALLOWED == STD_OFF) */
    {
      GtmArrayIdx = Wdg_kConfigPtr->WdgQmIndex[CoreId];     
      /* Enter the critical section */
      SchM_Enter_Wdg_17_Scu_TimerHandling();

      #if ((WDG_DEV_ERROR_DETECT == STD_ON) || (WDG_DEBUG_SUPPORT == STD_ON))
      /* Set Driver State to Busy - WDG018: */
      Wdg_17_Scu_DriverState[CoreId] = WDG_BUSY;
      #endif  
      /*(WDG_DEV_ERROR_DETECT == STD_ON)||(WDG_DEBUG_SUPPORT == STD_ON)*/

      /* Hold the previous mode information */
      PreviousMode = Wdg_17_Scu_DriverMode[CoreId];
      /* Diasble GTM channel before mode change*/
      /*Read GTM module number  */
      GtmModuleNumber = \
               Wdg_kConfigPtr->GtmConf[GtmArrayIdx].GtmModuleNumberForService;
      /*Read GTM channel number  */
      GtmChannelNumber = \
                Wdg_kConfigPtr->GtmConf[GtmArrayIdx].GtmChannelNumberForService;
      
     /* ATOM/TOM channel module is disabled*/
        Wdg_lDisableGtmChannel(GtmArrayIdx,GtmModuleNumber,GtmChannelNumber,
                                                       WDG_RUNTIME_ACCESS);
      
        /* Set WDG to the given Mode */
      ReturnValue = Wdg_lChangeMode(Mode, WDG_RUNTIME_ACCESS);

      /* Check if there was an error during mode switching */
      if (ReturnValue != E_OK)
      {
        #if (WDG_MODE_FAIL_DEM_REPORT == ENABLE_DEM_REPORT)

        /* Report Production errors to DEM - WDG010: WDG012: WDG016: */
        Dem_ReportErrorStatus((Dem_EventIdType)WDG_E_MODE_FAILED,
                                DEM_EVENT_STATUS_FAILED);

        #endif
         /* #if (WDG_MODE_FAIL_DEM_REPORT == ENABLE_DEM_REPORT) */
      }
      else
      {
           /* Update the current mode of Wdg driver */
        Wdg_17_Scu_DriverMode[CoreId] = Mode;
        if(PreviousMode == WDGIF_OFF_MODE)
        {
          /* Wdg_TimeoutCounter will be set in the next
                         Wdg_17_Scu_SetTriggerCondition call which should be
                         done immediately,in case of transition from OFF mode
                         to any other mode.*/
          TimeoutValue = WDG_INITIAL_TIMEOUT;
        }
        else if(PreviousMode == WDGIF_SLOW_MODE)
        {
          TimeoutValue = Wdg_TimeoutCounter[CoreId] *
            Wdg_kConfigPtr->GtmConf[GtmArrayIdx].SlowServiceGtmCbkTime;
        } 
        else 
        {
          TimeoutValue = Wdg_TimeoutCounter[CoreId] * 
               Wdg_kConfigPtr->GtmConf[GtmArrayIdx].FastServiceGtmCbkTime;
        }
        /* Calculate Timeout counter for the remaining timeout value */
        Wdg_lTimeoutHandler(Wdg_17_Scu_DriverMode[CoreId],TimeoutValue,\
                                                            WDG_RUNTIME_ACCESS);
        Wdg_lStartOrStopTimeEngine(Mode,WDG_RUNTIME_ACCESS);
      }
      
      #if ((WDG_DEV_ERROR_DETECT == STD_ON) || (WDG_DEBUG_SUPPORT == STD_ON))
      /* Set Driver State to Idle - WDG018: */
      Wdg_17_Scu_DriverState[CoreId] = WDG_IDLE;
      #endif
      /*(WDG_DEV_ERROR_DETECT == STD_ON)||(WDG_DEBUG_SUPPORT == STD_ON)*/

      /* Exit the critical section */
      SchM_Exit_Wdg_17_Scu_TimerHandling();
    }
  }
  /* Return the end status of execution of this function */
  return (ReturnValue); /* WDG032: WDG008: */
}/* End of Wdg_17_Scu_SetMode */

/*******************************************************************************
** Traceability     : [cover parentID= DS_AS40X_WDG144,
                    DS_AS40X_WDG146, DS_AS40X_WDG155,
                    DS_NAS_WDG_PR759_PR760_PR761]                             **
**                                                                            **
** Syntax           : void Wdg_17_Scu_SetTriggerCondition(uint16 timeout)     **
**                    [/cover]                                                **
**                                                                            **
** Service ID       : 0x03                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-reentrant                                           **
**                                                                            **
** Parameters(in)   : uint16 timeout                                          **
**                    Timeout value (milliseconds) for setting the trigger    **
**                    counter.                                                **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : The function Wdg_17_Scu_SetTriggerCondition shall sets  **
**                    Timeout value (milliseconds) for setting the trigger    **
**                    counter - WDG144:                                       **
**                                                                            **
*******************************************************************************/
void Wdg_17_Scu_SetTriggerCondition(uint16 timeout)
{
  uint8 CoreId;
  CoreId = WDG_SFR_RUNTIME_GETCOREID();
  #if ( (WDG_DEV_ERROR_DETECT == STD_ON) && (WDG_MAX_TIMEOUT < 65535U) )
  /* When development error detection is enabled for the module, check that the
     timeout parameter given is less or equal to the maximum timeout value
     (WdgMaxTimeout)  WDG146:*/
  /* To avoid compiler warning "condition is always false" */
  if(timeout > (uint16)WDG_MAX_TIMEOUT )
  {
    /* REPORT TO DET - WDG010: WDG045: WDG035: WDG066:*/
    Det_ReportError( WDG_17_SCU_MODULE_ID, WDG_17_SCU_INSTANCE_ID,
                     WDG_SID_TRIGGER_CONDITION, WDG_E_PARAM_TIMEOUT );
  }
  else
  #endif 
  /* #if (WDG_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Enter the critical section*/
    SchM_Enter_Wdg_17_Scu_TimerHandling();

    /* Check that OFF mode is not the current mode */
    if (Wdg_17_Scu_DriverMode[CoreId] != WDGIF_OFF_MODE)
    {
      /* Trigger the Watchdog hardware */
      Wdg_lTrigger();
    }

    /*Restart the GTM timer after setting the new window time*/
    Wdg_lStartOrStopTimeEngine(Wdg_17_Scu_DriverMode[CoreId],\
                                                     WDG_RUNTIME_ACCESS);

    /* Calculate Timeout counter for the new timeout parameter */
    Wdg_lTimeoutHandler(Wdg_17_Scu_DriverMode[CoreId],timeout,\
                                                     WDG_RUNTIME_ACCESS);
    /* Exit the critical section*/
    SchM_Exit_Wdg_17_Scu_TimerHandling();
  }
} /* End of Wdg_17_Scu_SetTriggerCondition  */

/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/

/*******************************************************************************
** Traceability     : [cover parentID=DS_AS_WDG161, DS_AS40X_WDG136,
                    DS_AS_WDG093, DS_AS40X_WDG094,
                    DS_NAS_WDG_PR759_PR760_PR761]                             **
**                                                                            **
** Syntax           : static void Wdg_lTrigger( void )                        **
**                    [/cover]                                                **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-reentrant                                           **
**                                                                            **
** Parameters (in)  : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This routine triggers the watchdog hardware. It has to  **
**                    be called cyclically in order to prevent the            **
**                    watchdog hardware from expiring.                        **
*******************************************************************************/
static void Wdg_lTrigger(void)
{
  uint32 PasswordAccess;
  uint32 ModifyAccess;
  /* Local variable to hold the value of Watchdog Timer Control Register */
  uint32 WdtCon0;
  uint8 CoreId;
  CoreId = WDG_SFR_RUNTIME_GETCOREID();

  /* Password Access: WDG037:
   - (Bits[7:4])Set Hardware password to WDTHPW1 TO 1111.
   - (Bits[3:2])This field must be written with the value of the bits
                SCU_WDTCPU0_CON1.WDTDR and SCU_WDTCPU0_CON1.WDTIR.
   - (Bit[1])Set WDTLCK to '0' to unlock SCU_WDTCPU0_CON0.
   - (Bit[0])Write back the read ENDINIT bit.
  */
  /* Enter critical section - WDG040:*/
  SchM_Enter_Wdg_17_Scu_Trigger();
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently
    access the password from WDTCON0 SFR register */
  WdtCon0 = WDG_SFR_RUNTIME_USER_MODE_READ32(WDG_REGMAP[CoreId].CON0.U);

  /* Password Access: WDG037:  
     - (Bits[15:8])Set Hardware password WDTHPW1 TO 0
     - (Bits[7:4])Set Hardware password TO 1111
     - (Bits[3:2]) This field must be written with 0's during a password
                   access to SCU_WDTCPU0_CON0.
     - (Bit[1]) Set WDTLCK to '0' to unlock SCU_WDTCPUx_CON0
     - (Bit[0]) Set ENDINIT bit while password access
  */
  PasswordAccess = Wdg_lAccessPassword(WdtCon0);
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently
    write the modified password into WDTCON0 SFR register */
  WDG_SFR_RUNTIME_USER_MODE_WRITE32(WDG_REGMAP[CoreId].CON0.U,\
                                (uint32)PasswordAccess);  /* PASSWORD ACCESS */

  /* Modify Access: WDG009:
     - (Bits[15:8]) Password as is.
     - (Bits[7:2]) Bits should be inverted
     - (Bit[1]) Set WDTLCK to '1' to unlock SCU_WDTCPUx_CON0
     - (Bit[0]) Set ENDINIT bit to '1' while modify access
  */
  ModifyAccess = (PasswordAccess) | WDT_SETLCK_ENDINIT;
  
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently
    write the modified password into WDTCON0 SFR register */
  WDG_SFR_RUNTIME_USER_MODE_WRITE32(WDG_REGMAP[CoreId].CON0.U,\
                                  (uint32)ModifyAccess);    /* MODIFY ACCESS */

  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently
    access the password from WDTCON0 SFR register */
  WdtCon0 =(uint32)WDG_SFR_RUNTIME_USER_MODE_READ32(WDG_REGMAP[CoreId].CON0.U);
  PasswordAccess = Wdg_lAccessPassword(WdtCon0);
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently
    write the modified password into WDTCON0 SFR register */
  WDG_SFR_RUNTIME_USER_MODE_WRITE32(WDG_REGMAP[CoreId].CON0.U,\
                                  (uint32)PasswordAccess);/* PASSWORD ACCESS */
  /* Update with the existing Reload Value */

  ModifyAccess = Wdg_lModifyAccessPassword(PasswordAccess);
  ModifyAccess |= Wdg_lReloadModifyAccess(Wdg_CurrentReloadValue[CoreId]);
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently
    write the modified password into WDTCON0 SFR register */
  WDG_SFR_RUNTIME_USER_MODE_WRITE32(WDG_REGMAP[CoreId].CON0.U,\
                               (uint32)ModifyAccess); /* RELOAD VALUE UPDATE */

  /* Exit critical section - WDG040: */
  SchM_Exit_Wdg_17_Scu_Trigger();

  return;
} /* End of Wdg_lTrigger */

/*******************************************************************************
** Traceability     : [cover parentID=DS_NAS_WDG_PR759_PR760_PR761]           **
**                                                                            **
** Syntax           : static Std_ReturnType Wdg_lChangeMode(                  **
**                     WdgIf_ModeType Mode, uint8 ServiceId)                **
**                                                                            **
**                    [/cover]                                                **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : E_OK or E_NOT_OK                                        **
**                                                                            **
** Description      : This routine changes the mode of WDG to the given mode. **
**                                                                            **
*******************************************************************************/
static Std_ReturnType Wdg_lChangeMode(WdgIf_ModeType Mode, uint8 ServiceId)
{
  Std_ReturnType ChangeModeDone;
  uint32 WdtCon0;
  uint16 ClockDivider;
  uint16 ReloadValue;
  #if (WDG_DISABLE_ALLOWED == STD_ON)
  uint8 TimeoutModeFlag;
  uint8 DisableFlag;
  #endif
  uint8 CoreId;
  uint8 ModeArrayIdx;
  /* Get core Id */
  if (ServiceId == WDG_INIT_ACCESS)
  {
    CoreId = WDG_SFR_INIT_GETCOREID();
  }
  else
  {
    CoreId = WDG_SFR_RUNTIME_GETCOREID();
  }
  /* Get the WDGx mode index */
  ModeArrayIdx = Wdg_kConfigPtr->WdgQmIndex[CoreId];
  
  /* Set the default error status to E_NOT_OK */
  ChangeModeDone = E_NOT_OK;
  
  #if (WDG_DISABLE_ALLOWED == STD_ON)
  /* Check if OFF-Mode is requested */
  if (Mode == WDGIF_OFF_MODE)
  {
    if (ServiceId == WDG_INIT_ACCESS)
    {
      /* Reset ENDINIT bit in SCU_WDTCPU0_CON0 to modify SCU_WDTCPU0_CON1 */
      WDG_SFR_INIT_RESETENDINIT();
      /* Request to Disable the Watchdog */
      /* To update WDTx_CON1 in Supervisor mode,
         i.e., WDG_REGMAP[CoreId].CON1.B.DR =(uint8)1U; */
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently
         write the into WDTCON1 SFR register */
      WDG_SFR_INIT_MODIFY32\
         (WDG_REGMAP[CoreId].CON1.U, WDG_CON1_DR_CLEARMASK,WDG_CON1_DR_SETMASK)
       /* Set ENDINIT bit in SCU_WDTCPU0_CON0 to lock SCU_WDTCPU0_CON1 */
      WDG_SFR_INIT_SETENDINIT();
      /* Check the status of disable watchdog request */

      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently
      read the TimeoutMode bit from WDT Status SFR register */
     TimeoutModeFlag = (uint8)((WDG_SFR_INIT_USER_MODE_READ32\
              (WDG_REGMAP[CoreId].SR.U) & WDG_SR_TO_MASK) >> WDG_SR_TO_BITPOS);
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently
      read the WDT Disable bit from WDT Status SFR register */
      DisableFlag = (uint8)((WDG_SFR_INIT_USER_MODE_READ32\
              (WDG_REGMAP[CoreId].SR.U) & WDG_SR_DS_MASK) >> WDG_SR_DS_BITPOS);
    }
    else
    {
      /* Reset ENDINIT bit in SCU_WDTCPU0_CON0 to modify SCU_WDTCPU0_CON1 */
      WDG_SFR_RUNTIME_RESETENDINIT();
      /* Request to Disable the Watchdog */
      /* To update WDTx_CON1 in Supervisor mode,
         i.e., WDG_REGMAP[CoreId].CON1.B.DR =(uint8)1U; */
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently
         write the into WDTCON1 SFR register */
      WDG_SFR_RUNTIME_MODIFY32\
         (WDG_REGMAP[CoreId].CON1.U, WDG_CON1_DR_CLEARMASK,WDG_CON1_DR_SETMASK)
       /* Set ENDINIT bit in SCU_WDTCPU0_CON0 to lock SCU_WDTCPU0_CON1 */
      WDG_SFR_RUNTIME_SETENDINIT();
      /* Check the status of disable watchdog request */

      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently
      read the TimeoutMode bit from WDT Status SFR register */
      TimeoutModeFlag = (uint8)((WDG_SFR_RUNTIME_USER_MODE_READ32\
              (WDG_REGMAP[CoreId].SR.U) & WDG_SR_TO_MASK) >> WDG_SR_TO_BITPOS);
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently
      read the WDT Disable bit from WDT Status SFR register */
       DisableFlag = (uint8)((WDG_SFR_RUNTIME_USER_MODE_READ32\
              (WDG_REGMAP[CoreId].SR.U) & WDG_SR_DS_MASK) >> WDG_SR_DS_BITPOS);
    }

    if ( (1U==DisableFlag) && (0U==TimeoutModeFlag) )
    {
      /* ChangeMode was succesful */
      ChangeModeDone = E_OK;
    }
  }
  else /* Mode is WDGIF_SLOW_MODE  or WDGIF_FAST_MODE */
  
  #endif 
  /* #if (WDG_DISABLE_ALLOWED == STD_ON) */
  {
    /* Mode is WDGIF_SLOW_MODE*/
    if (Mode == WDGIF_SLOW_MODE)
    {
      /* Get the Clock divider for Slow mode */
      ClockDivider = WDG_RESET_WDTIR_RESET_WDTDR;
      /* Get the Reload value for Slow mode */
      ReloadValue  = Wdg_kConfigPtr->SlowModeReloadValue[ModeArrayIdx];
    }
    else /* WDGIF_FAST_MODE */
    {
      /* Get the Clock divider for Fast mode */
      ClockDivider = WDG_SET_WDTIR_RESET_WDTDR;
      /* Get the Reload value for Fast mode */
      ReloadValue  = Wdg_kConfigPtr->FastModeReloadValue[ModeArrayIdx];
    }

    /* Enter critical section - WDG040:*/
    SchM_Enter_Wdg_17_Scu_ChangeMode();

    /* Store the current reload value */
    Wdg_CurrentReloadValue[CoreId] = ReloadValue;
    /* To update WDTx_CON1 in Supervisor mode,
      i.e., WDG_REGMAP[CoreId].CON1.U = (uint32)ClockDivider; */
    if (ServiceId == WDG_INIT_ACCESS)
    {
       WDG_SFR_INIT_RESETENDINIT();
       /* Set the clock divider */
       /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently
        write  into WDTCON1 SFR register */
       WDG_SFR_INIT_MODIFY32(WDG_REGMAP[CoreId].CON1.U,\
                     ((uint32)(ClockDivider)), (uint32)ClockDivider)
       WDG_SFR_INIT_SETENDINIT();

       /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently
       access the password from WDTCON0 SFR register */
       WdtCon0 = (uint32)WDG_SFR_INIT_USER_MODE_READ32                         \
                                                 (WDG_REGMAP[CoreId].CON0.U);
       /* PASSWORD ACCESS */
       WdtCon0 = Wdg_lAccessPassword(WdtCon0);
       /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently
       write the modified password into WDTCON0 SFR register */
       WDG_SFR_INIT_USER_MODE_WRITE32(WDG_REGMAP[CoreId].CON0.U,               \
                                                          (uint32)WdtCon0);
       WdtCon0 = Wdg_lModifyAccessPassword(WdtCon0);
      /* MODIFY ACCESS - WDG145:*/
      WdtCon0 |= Wdg_lReloadModifyAccess(ReloadValue);
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently
      write the modified password and reload value into WDTCON0 SFR register */
      WDG_SFR_INIT_USER_MODE_WRITE32(WDG_REGMAP[CoreId].CON0.U,(uint32)WdtCon0);
    }
    else
    {
      /* Reset ENDINIT bit in SCU_WDTCPU0_CON0 to modify SCU_WDTCPU0_CON1 */
      WDG_SFR_RUNTIME_RESETENDINIT();
      /* Set the clock divider */
      /*IFX_MISRA_RULE_17_04_STATUS==Pointer arithmetic is used to efficiently
      write the ClockDivider value into WDTCON1 SFR register */
      WDG_SFR_RUNTIME_WRITE32(WDG_REGMAP[CoreId].CON1.U,(uint32)ClockDivider);
      /* Set ENDINIT bit in SCU_WDTCPU0_CON0 to lock SCU_WDTCPU0_CON1 */
      WDG_SFR_RUNTIME_SETENDINIT();

      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently
      access the password from WDTCON0 SFR register */
      WdtCon0 = (uint32)WDG_SFR_RUNTIME_USER_MODE_READ32                       \
                                                (WDG_REGMAP[CoreId].CON0.U);
      /* PASSWORD ACCESS */
      WdtCon0 = Wdg_lAccessPassword(WdtCon0);
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently
      write the modified password into WDTCON0 SFR register */
      WDG_SFR_RUNTIME_USER_MODE_WRITE32(WDG_REGMAP[CoreId].CON0.U,             \
                                                               (uint32)WdtCon0);
      WdtCon0 = Wdg_lModifyAccessPassword(WdtCon0);
      /* MODIFY ACCESS - WDG145:*/
      WdtCon0 |= Wdg_lReloadModifyAccess(ReloadValue);
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently
      write the modified password and reload value into WDTCON0 SFR register */
      WDG_SFR_RUNTIME_USER_MODE_WRITE32(WDG_REGMAP[CoreId].CON0.U,             \
                                                              (uint32)WdtCon0);
    }
    /* Exit critical section - WDG040: */
    SchM_Exit_Wdg_17_Scu_ChangeMode();

    /* Check for the used clock divider */
    if ( ClockDivider == WDG_SET_WDTIR_RESET_WDTDR)
    {
      if (ServiceId == WDG_INIT_ACCESS)
      {
        /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently
        access the WDT Status SFR register to check Changemode was successful*/
        if (((uint32)WDG_SFR_INIT_USER_MODE_READ32(WDG_REGMAP[CoreId].SR.U) & \
        WDG_STATUS_MASK) == WDG_SET_WDTIR_RESET_WDTDR)
          {
          ChangeModeDone = E_OK; /* ChangeMode was succesful */
          }
      }
      else
      {
        /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently
        access the WDT Status SFR register to check Changemode was successful*/
        if (((uint32)WDG_SFR_RUNTIME_USER_MODE_READ32(WDG_REGMAP[CoreId].SR.U) \
        & WDG_STATUS_MASK) == WDG_SET_WDTIR_RESET_WDTDR)
          {
          ChangeModeDone = E_OK; /* ChangeMode was succesful */
          }
      }
    }
    else /* ClockDivider is WDG_CLK_DIVIDER_SLOW */
    {
      if (ServiceId == WDG_INIT_ACCESS)
      {
        /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently
        access the WDT Status SFR register to check Changemode was successful*/
        if (((uint32)WDG_SFR_INIT_USER_MODE_READ32(WDG_REGMAP[CoreId].SR.U) & \
                               WDG_STATUS_MASK) == WDG_RESET_WDTIR_RESET_WDTDR)
        {
          ChangeModeDone = E_OK; /* ChangeMode was succesful */
        }
      }
      else
      {
        /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently
        access the WDT Status SFR register to check Changemode was successful*/
        if (((uint32)WDG_SFR_RUNTIME_USER_MODE_READ32(WDG_REGMAP[CoreId].SR.U) \
                            & WDG_STATUS_MASK) == WDG_RESET_WDTIR_RESET_WDTDR)
        {
          ChangeModeDone = E_OK; /* ChangeMode was succesful */
        }
      }
    }/* End of 'if ( ClockDivider == WDG_SET_WDTIR_RESET_WDTDR)' */
  } /* End of 'if (Mode == WDGIF_SLOW_MODE)' */
  /* return E_OK if change mode done successfully */
  return ((Std_ReturnType)ChangeModeDone);
}

/*******************************************************************************
** Traceability     : [cover parentID=DS_NAS_WDG_PR759_PR760_PR761]           **
**                                                                            **
** Syntax           : static void Wdg_lStartOrStopTimeEngine                    
**                                     (WdgIf_ModeType Mode, uint8 ServiceId) **
**                                                                            **
**                    [/cover]                                                **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-reentrant                                           **
**                                                                            **
** Parameters(in)   : WdgIf_ModeType Mode                                     **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function starts SRV timer if watchdog SLOW-MODE    **
**                    or FAST-MODE is requested                               **
**                                                                            **
*******************************************************************************/
static void Wdg_lStartOrStopTimeEngine(WdgIf_ModeType Mode, uint8 ServiceId)
{
  uint32 GtmSlowTicks;
  uint32 GtmFastTicks;
  uint8 GtmModuleNumber;
  uint8 GtmChannelNumber;
  uint8 CoreId;
  uint8 GtmArrayIdx;
  /* Get core Id */
  if (ServiceId == WDG_INIT_ACCESS)
  {
    CoreId = WDG_SFR_INIT_GETCOREID();
  }
  else
  {
    CoreId = WDG_SFR_RUNTIME_GETCOREID();
  }
  /* Get GTM index for WDGx */
  GtmArrayIdx = Wdg_kConfigPtr->WdgQmIndex[CoreId];
  /* Enter critical section - WDG040:*/
  SchM_Enter_Wdg_17_Scu_TimerHandling();
  /*Get GTM module number  */
  GtmModuleNumber = (uint8)Wdg_kConfigPtr->GtmConf[GtmArrayIdx]. \
                                           GtmModuleNumberForService;
  /* Get GTM module channel number*/
  GtmChannelNumber = (uint8)Wdg_kConfigPtr->GtmConf[GtmArrayIdx].  \
                                          GtmChannelNumberForService;
  /* Get GTM slow ticks  */
  GtmSlowTicks = Wdg_kConfigPtr->GtmConf[GtmArrayIdx].SlowServiceGtmCbkTicks;
  /* Get GTM fast ticks  */
  GtmFastTicks = Wdg_kConfigPtr->GtmConf[GtmArrayIdx].FastServiceGtmCbkTicks;

  /* ATOM/TOM channel module is disabled*/
  Wdg_lDisableGtmChannel(GtmArrayIdx,GtmModuleNumber,GtmChannelNumber,         \
                                                         ServiceId);

  switch(Mode)
  {
    case WDGIF_OFF_MODE:
    {
      break;
    }
    /* Start SRV timer with corresponding timer ticks value when Watchdog
     SLOW-Mode is requested */
    case WDGIF_SLOW_MODE:
    {
      /* ATOM/TOM channel is enabled*/
      Wdg_lEnableGtmChannel(GtmArrayIdx,GtmModuleNumber,GtmChannelNumber,      \
                                                        GtmSlowTicks,ServiceId);
      break;
    }
      /* Start SRV timer with corresponding timer ticks value when Watchdog
       FAST-Mode is requested */
    case WDGIF_FAST_MODE:
    {
      /* ATOM/TOM channel is enabled*/
      Wdg_lEnableGtmChannel(GtmArrayIdx,GtmModuleNumber,GtmChannelNumber,      \
                                                     GtmFastTicks,ServiceId);
      break;
    }
    default:
    {
      break;
    }
 }
  /* Exit the critical section */
  SchM_Exit_Wdg_17_Scu_TimerHandling();
}

/*******************************************************************************
** Traceability     : [cover parentID=DS_AS40X_WDG140, DS_AS40X_WDG138,
                    DS_AS40X_WDG139, DS_AS40X_WDG145,
                    DS_NAS_WDG_PR759_PR760_PR761]                             **
**                                                                            **
** Syntax           : static void Wdg_lTimeoutHandler(WdgIf_ModeType Mode,    **
**                    uint16 timeout, uint8 ServiceId)                        **
**                    [/cover]                                                **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-reentrant                                           **
**                                                                            **
** Parameters(in)   : Mode    -     Watchdog mode to be switched,             **
**                    timeout -  Timeout period (in milliseconds)             **
**                               used to calculate Wdg_TimeoutCounter,        **
**                    ServiceId - WDG_INIT_ACCESS, WDG_RUNTIME_ACCESS,        **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function allow to set "0" as the time frame for    **
**                    triggering which will result in an (almost) immediate   **
**                    stop of the watchdog triggering and an (almost)         **
**                    instantaneous watchdog reset of the ECU.                **
**                    This function also calulates the value of Timeout       **
**                    counter if watchdog SLOW-MODE or FAST-MODE is requested **
**                    and resets if OFF-MODE is requested                     **
**                                                                            **
*******************************************************************************/
static void Wdg_lTimeoutHandler(WdgIf_ModeType Mode, uint16 timeout,\
                                                       uint8 ServiceId)
{
  /* Time elapsed in ms relative to the last notification */
  uint16 TimeInms;
  /* Local variable to hold the value of Watchdog Timer Control Register */
  uint32 WdtCon0;
  uint32 PasswordAccess;
  uint32 ModifyAccess;
  uint8 CoreId;
  uint8 GtmArrayIdx;
  if (ServiceId == WDG_INIT_ACCESS)
  {
    CoreId = WDG_SFR_INIT_GETCOREID();
  }
  else
  {
    CoreId = WDG_SFR_RUNTIME_GETCOREID();
  }
  /* Get GTM index */
  GtmArrayIdx = Wdg_kConfigPtr->WdgQmIndex[CoreId];
  /* If an immediate stop of the watchdog triggering and an instantaneous
     watchdog reset of the ECU is requested - WDG140: */
  if(timeout==0U)
  {
    /* Enter critical section - WDG040:*/
    SchM_Enter_Wdg_17_Scu_ChangeMode();

    /* Read the current value of Watchdog Timer Control Register */
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently
    access the password from WDTCON0 SFR register */
    WdtCon0 = (uint32)WDG_SFR_RUNTIME_USER_MODE_READ32                       \
                                                   (WDG_REGMAP[CoreId].CON0.U);
    /* Servicing the Watchdog Timer is performed in two steps, a Valid Password
      Access followed by a Valid Modify Access - WDG093: WDG094:*/

    /* PASSWORD ACCESS */
    PasswordAccess = Wdg_lAccessPassword(WdtCon0);
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently
    access the password from WDTCON0 SFR register */
    WDG_SFR_RUNTIME_USER_MODE_WRITE32(WDG_REGMAP[CoreId].CON0.U,\
                                                       (uint32)PasswordAccess);
    /* MODIFY ACCESS */
    ModifyAccess = Wdg_lModifyAccessPassword(PasswordAccess);
    ModifyAccess |= Wdg_lReloadModifyAccess(WDG_INSTANT_RESET_RELOAD_VALUE);
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently
    write the modified password into WDTCON0 SFR register */
    WDG_SFR_RUNTIME_USER_MODE_WRITE32(WDG_REGMAP[CoreId].CON0.U,             \
                                                        (uint32)ModifyAccess);
    /* As user wants a reset, update the watchdog Timeout Counter,
    so that Watchdog hardware timer will not be reloaded
    in the next call of Wdg_17_Scu_Cbk_GtmNotificationSRV */
    Wdg_TimeoutCounter[CoreId] = 0x00U;

    /* Exit critical section - WDG040: */
    SchM_Exit_Wdg_17_Scu_ChangeMode();
  }
  else
  {
    /* Enter the critical section */
    SchM_Enter_Wdg_17_Scu_TimerHandling();
    switch(Mode)
    {
      /* Reset Timeout counter if watchdog OFF_Mode is requested */
      case WDGIF_OFF_MODE:
      {
        /* As user wants OFF mode, update the watchdog Timeout Counter,
         so that Watchdog hardware timer will not be reloaded
         in the next call of Wdg_17_Scu_Cbk_GtmNotificationSRV */
        Wdg_TimeoutCounter[CoreId] = 0x00U;
        break;
      }
      /* Calculate Timeout counter when Watchdog SLOW Mode is requested */
      case WDGIF_SLOW_MODE:
      {
        /* Convert the time in GTM ticks into ms */
        /*MISRA Violation - Cannot be avoided for PB type structure*/
        TimeInms = Wdg_kConfigPtr->GtmConf[GtmArrayIdx].SlowServiceGtmCbkTime;
        Wdg_TimeoutCounter[CoreId] = (uint16)(timeout / TimeInms);
        break;
      }
      /* Calculate Timeout counter when Watchdog Fats Mode is requested */
      case WDGIF_FAST_MODE:
      {
        /* Convert the time in GTM ticks into ms */
        TimeInms = Wdg_kConfigPtr->GtmConf[GtmArrayIdx].FastServiceGtmCbkTime;
        Wdg_TimeoutCounter[CoreId] = (uint16)(timeout / TimeInms);
        break;
      }
      default:
      {
        break;
      }
    }
    /* Exit the critical section */
    SchM_Exit_Wdg_17_Scu_TimerHandling();
  }
}
#if (WDG_DEV_ERROR_DETECT == STD_ON)
/*******************************************************************************
**                                                                            **
** Syntax           : static Std_ReturnType Wdg_lSetModeDetCheck              **
**                    (WdgIf_ModeType Mode)                                   **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : E_OK or E_NOT_OK                                        **
**                                                                            **
** Description      : This function checks  the DET's during Mode Change      **
**                                                                            **
*******************************************************************************/
static Std_ReturnType Wdg_lSetModeDetCheck(WdgIf_ModeType Mode)
{
  /* Flag to indiate any DET/DEM Error. */
  Std_ReturnType ErrorFlag;
  uint8 CoreId;
  CoreId = WDG_SFR_RUNTIME_GETCOREID();
  /* Flag initialized to no error*/
  ErrorFlag = E_OK;

  if ( Wdg_17_Scu_DriverState[CoreId] != WDG_IDLE)
  {
    /* Report to DET - WDG010: WDG045: WDG017: WDG066:*/
    Det_ReportError( WDG_17_SCU_MODULE_ID, WDG_17_SCU_INSTANCE_ID,
                     WDG_SID_SETMODE, WDG_E_DRIVER_STATE);
    ErrorFlag = E_NOT_OK; /* Set error flag WDG017: */
  }
  /* Check if Mode is within allowed range - WDG091: */
  else if ( !((Mode == WDGIF_SLOW_MODE) || (Mode == WDGIF_FAST_MODE) || \
             (Mode == WDGIF_OFF_MODE)) )
  {
    /* Report to DET - WDG010: WDG045: WDG008: WDG066: WDG064: WDG091:*/
    Det_ReportError( WDG_17_SCU_MODULE_ID, WDG_17_SCU_INSTANCE_ID,
                     WDG_SID_SETMODE, WDG_E_PARAM_MODE );
    ErrorFlag = E_NOT_OK; /* Set error flag */
  }
  else
  {
    /* Nothing to do */
  }
  return (ErrorFlag);
}/* End of Wdg_lSetModeDetCheck*/

/*******************************************************************************
** Syntax           : static Std_ReturnType Wdg_lInitParamRangeCheck(void)    **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : E_OK or E_NOT_OK                                        **
**                                                                            **
** Description      : This function checks that the (hardware specific)       **
**                    contents of the given configuration set is within the   **
**                    allowed boundaries.                                     **
**                                                                            **
*******************************************************************************/
static Std_ReturnType Wdg_lInitParamRangeCheck(void)
{
  WdgIf_ModeType Mode;
  Std_ReturnType Ret_Val;
  uint8 CoreId;
  CoreId = WDG_SFR_INIT_GETCOREID();
  /* Check if GTM related configuration is within range */
  Ret_Val = Wdg_lGtmConfigCheck();
  /* Take the default value of the WDG Mode from configuration*/
  Mode = Wdg_kConfigPtr->DefaultMode[CoreId];
  if(Ret_Val != E_OK)
  {
    /* Report to DET - WDG090: WDG092*/
    Det_ReportError( WDG_17_SCU_MODULE_ID, WDG_17_SCU_INSTANCE_ID,
                      WDG_SID_INIT, WDG_E_PARAM_CONFIG );
  }
  else if ( !((Mode == WDGIF_SLOW_MODE) || (Mode == WDGIF_FAST_MODE) ||
             (Mode == WDGIF_OFF_MODE)) )
  {
    /* Report to DET - WDG010: WDG045: WDG008: WDG066: WDG064: WDG091:*/
    Det_ReportError( WDG_17_SCU_MODULE_ID, WDG_17_SCU_INSTANCE_ID,
                      WDG_SID_INIT, WDG_E_PARAM_CONFIG );
    Ret_Val = E_NOT_OK;
  }
  else
  {
    /*Do Nothing*/
  }
  return (Ret_Val);
}
#endif
 /* (WDG_DEV_ERROR_DETECT == STD_ON) */

/*******************************************************************************
**                                                                            **
** Syntax           : static void Wdg_lQmInit(const Wdg_17_Scu_ConfigType*    **
**                                            ConfigPtr)                      **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : E_OK or E_NOT_OK                                        **
**                                                                            **
** Description      : This function initializes WDGx without safety           **
**                                                                            **
*******************************************************************************/
static void Wdg_lQmInit(const Wdg_17_Scu_ConfigType* ConfigPtr)
{ 
  /*Enter if Wdg_lInitDetCheck returns E_OK  */
  /* Variables for WDG init */
  Std_ReturnType ReturnValue;
  uint8 CoreId;
  
  #if((WDG_DEV_ERROR_DETECT == STD_ON) || (WDG_DISABLE_ALLOWED == STD_OFF))
  /* Flag to indiate any DET/DEM Error. */
  Std_ReturnType ErrorFlag;
  #endif
  /*((WDG_DEV_ERROR_DETECT == STD_ON) || (WDG_DISABLE_ALLOWED == STD_OFF))*/
   
  CoreId = WDG_SFR_INIT_GETCOREID();
  
  #if ((WDG_DEV_ERROR_DETECT == STD_ON) || (WDG_DEBUG_SUPPORT == STD_ON))
  /* Set Driver State to Uninit */
  Wdg_17_Scu_DriverState[CoreId] = WDG_UNINIT;
  #endif 
  /*(WDG_DEV_ERROR_DETECT == STD_ON) ||
                       (WDG_DEBUG_SUPPORT == STD_ON)*/
  /* Set driver to OFF mode*/
  Wdg_17_Scu_DriverMode[CoreId] = WDGIF_OFF_MODE;

  #if (WDG_DEV_ERROR_DETECT == STD_ON)
  
  ErrorFlag = Wdg_lInitParamRangeCheck();
  if(ErrorFlag != E_NOT_OK)
  #endif
   /*(WDG_DEV_ERROR_DETECT == STD_ON)*/
  {
    /* Check if the default mode is STD_OFF and WDG Disable is 
                                           not allowed */
    #if (WDG_DISABLE_ALLOWED == STD_OFF)
    /*Check if the defaule mode configured is Off-Mode*/
    if(ConfigPtr->DefaultMode[CoreId] == WDGIF_OFF_MODE)
    {
      #if (WDG_DISABLE_REJECT_DEM_REPORT == ENABLE_DEM_REPORT)
      /* Report Production errors to DEM -
                         WDG010: WDG012: WDG026: WDG025:*/
      Dem_ReportErrorStatus((Dem_EventIdType)WDG_E_DISABLE_REJECTED,
                              DEM_EVENT_STATUS_FAILED);
      #endif
      /* Enable the error flag, as watchdog Disable is not allowed
             but default mode configured is Off-Mode (WDGIF_OFF_MODE) */
      ErrorFlag = E_NOT_OK;
    }
    else
    {
      ErrorFlag = E_OK;
    }
    if(ErrorFlag != E_NOT_OK)
    #endif
    /* WDG_DISABLE_ALLOWED == STD_OFF*/
    {
      /* Set WDG to the given Mode. Available modes are OFF_MODE,
          SLOW_MODE and FAST_MODE - WDG001, WDG100, WDG101*/
      ReturnValue = Wdg_lChangeMode(ConfigPtr->DefaultMode[CoreId],\
                                                              WDG_INIT_ACCESS);
      /* Check if there was an error during mode switching */
      if (ReturnValue != E_OK)
      {
        /* Enter the critical section */
        SchM_Enter_Wdg_17_Scu_TimerHandling();
        /* Reset Wdg_TimeoutCounter */
        Wdg_TimeoutCounter[CoreId] = 0x00U;
        /* Exit the critical section */
        SchM_Exit_Wdg_17_Scu_TimerHandling();
        #if (WDG_MODE_FAIL_DEM_REPORT == ENABLE_DEM_REPORT)
        /* Report Production errors to DEM - WDG010: WDG012:
              WDG016: WDG173*/
        Dem_ReportErrorStatus((Dem_EventIdType)WDG_E_MODE_FAILED,
                                DEM_EVENT_STATUS_FAILED);
        #endif 
        /* #if (WDG_MODE_FAIL_DEM_REPORT == ENABLE_DEM_REPORT)*/
        #if (WDG_DEV_ERROR_DETECT == STD_ON)
        /*Initialisation is unsuccessfull and Report to DET -
                   WDG010: WDG045:WDG003: WDG066: WDG064: WDG090:*/
        Det_ReportError( WDG_17_SCU_MODULE_ID,WDG_17_SCU_INSTANCE_ID,
                     WDG_SID_INIT,WDG_E_PARAM_CONFIG );
        #endif
         /* #if (WDG_DEV_ERROR_DETECT == STD_ON) */
      } /* End of '(ReturnValue != E_OK)'*/
      /* If init is done successfuly calculate Timeout counter*/
      else
      {
        /* Calculate the Timeout counter */
        Wdg_lTimeoutHandler(ConfigPtr->DefaultMode[CoreId],
                             ((uint16)WDG_INITIAL_TIMEOUT), WDG_INIT_ACCESS);
        /*Start the SRV timer with respecive reload value if the default
                   watchdog mode is FAST-mode or SLOW-mode*/
        Wdg_lStartOrStopTimeEngine(ConfigPtr->DefaultMode[CoreId],\
                                                        WDG_INIT_ACCESS);
        #if ((WDG_DEV_ERROR_DETECT == STD_ON) ||(WDG_DEBUG_SUPPORT == STD_ON))
        /* As the initialisation is successfull, set Driver State to Idle */
        Wdg_17_Scu_DriverState[CoreId] = WDG_IDLE;
        #endif 
        /*(WDG_DEV_ERROR_DETECT == STD_ON)||(WDG_DEBUG_SUPPORT == STD_ON)*/

        /* Update the current mode of Wdg driver */
        Wdg_17_Scu_DriverMode[CoreId] = ConfigPtr->DefaultMode[CoreId];
      }  /* End of '(ReturnValue == E_OK)' */
    } /* ErrorFlag != E_NOT_OK, WDG_DISABLE_ALLOWED == STD_OFF  */ 
  } /*ErrorFlag != E_NOT_OK, WDG_DEV_ERROR_DETECT == STD_ON  */
  return;
}/* End of Wdg_lQmInit */  

#endif
 /* WDG_MAXQM_TIMERS != 0U */

#if (WDG_DEV_ERROR_DETECT == STD_ON)
/*******************************************************************************
**                                                                            **
** Syntax           :   static Std_ReturnType Wdg_lInitDetCheck(void)         **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : E_OK or E_NOT_OK                                        **
**                                                                            **
** Description      : This function checks  the DET's during Initialization   **
**                                                                            **
*******************************************************************************/
static Std_ReturnType Wdg_lInitDetCheck(const Wdg_17_Scu_ConfigType* ConfigPtr)
{
  /* Flag to indiate any DET/DEM Error. */
  Std_ReturnType ErrorFlag;
  /* Flag initialized to no error*/
  ErrorFlag = E_OK;

  #if(WDG_PB_FIXEDADDR == STD_OFF)
   /* Check if the passed parameter is a NULL_PTR.  If so, escalate... */
  if (ConfigPtr == NULL_PTR)
  {
    /* Report to DET - WDG010: WDG045: WDG003: WDG066: WDG064: WDG089:*/
    /* Traceability : [cover parentID=DS_AS40X_WDG111] [/cover] */
    Det_ReportError( WDG_17_SCU_MODULE_ID, WDG_17_SCU_INSTANCE_ID,
                     WDG_SID_INIT, WDG_E_PARAM_CONFIG );
    ErrorFlag = E_NOT_OK;
  }
  #else
  /* Check for fixed configuration pointer & DET not reported previously*/
  if (ConfigPtr != Wdg_kConfigPtr)
  {
    /* Report to DET - WDG010: WDG045: WDG003: WDG066: WDG064:*/
    Det_ReportError( WDG_17_SCU_MODULE_ID, WDG_17_SCU_INSTANCE_ID,
                     WDG_SID_INIT, WDG_E_PARAM_CONFIG );
    ErrorFlag = E_NOT_OK;
  }
  #endif
   /*(WDG_PB_FIXEDADDR == STD_OFF)*/

  return (ErrorFlag) ;

}/* End of Wdg_lInitDetCheck */

#endif
/* ((WDG_DEV_ERROR_DETECT == STD_ON))*/

#define WDG_17_SCU_STOP_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
  allowed only for MemMap.h*/
#include "MemMap.h"

#if (WDG_MAXQM_TIMERS != 0U)

#define WDG_17_SCU_START_SEC_CALLOUT_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
  allowed only for MemMap.h*/
#include "MemMap.h"
/*******************************************************************************
** Traceability     : [cover parentID= DS_AS40X_WDG035,              
                      DS_AS40X_WDG134, DS_AS40X_WDG135, DS_AS40X_WDG166,
                      DS_AS40X_WDG052,DS_NAS_WDG_PR759_PR760_PR761]           **
**                                                                            **
** Syntax           : void Wdg_17_Scu_Cbk_GtmNotifySRV(uint8 ModuleType,      **
**                     uint8 ModuleNo,uint8 ChannelNo,uint16 IrqNotifVal)     **
**                                                                            **
**                    [/cover]                                                **
**                                                                            **
** Service ID       :                                                         **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Callback function for SRV timer.                        **
**                    This function is called if SRV timer is expired and     **
**                    triggers the Watchdog hardware timer if Timeout counter **
**                    value has not reached zero.                             **
**                                                                            **
*******************************************************************************/
void Wdg_17_Scu_Cbk_GtmNotifySRV(uint8 ModuleType, uint8 ModuleNo,
                   uint8 ChannelNo,uint16 IrqNotifVal)
{
  uint8 CoreId;
  uint8 GtmModuleNum;
  uint8 GtmChannelNum;
  uint8 GtmArrayIdx;
  /* Unused Parameters*/
  UNUSED_PARAMETER(ModuleType)
  UNUSED_PARAMETER(ModuleNo)
  UNUSED_PARAMETER(ChannelNo)
  UNUSED_PARAMETER(IrqNotifVal)
  /* Get CPU Id */
  CoreId = WDG_SFR_RUNTIME_GETCOREID();
 
  #if (WDG_DEV_ERROR_DETECT == STD_ON)
  /* Check for Idle State */
  if (Wdg_17_Scu_DriverState[CoreId] != WDG_IDLE)
  {
    /* REPORT TO DET - WDG010: WDG045: WDG035: WDG066:*/
    Det_ReportError( WDG_17_SCU_MODULE_ID, WDG_17_SCU_INSTANCE_ID,
                     WDG_SID_GTMNOTIF, WDG_E_DRIVER_STATE );
  }
  else
  #endif
   /* (WDG_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Get GTM index to access */
    GtmArrayIdx = Wdg_kConfigPtr->WdgQmIndex[CoreId];
    /* Get GTM module number  */
    GtmModuleNum = Wdg_kConfigPtr->GtmConf[GtmArrayIdx].
                                               GtmModuleNumberForService;
    /* Get GTM channel number   */
    GtmChannelNum =  
         Wdg_kConfigPtr->GtmConf[GtmArrayIdx].GtmChannelNumberForService;   
    /* Enter the critical section */

    SchM_Enter_Wdg_17_Scu_TimerHandling();

    #if ((WDG_DEV_ERROR_DETECT == STD_ON) || (WDG_DEBUG_SUPPORT == STD_ON))
    /* Set Driver State to Busy - WDG052: */
    Wdg_17_Scu_DriverState[CoreId] = WDG_BUSY;
    #endif 
     /*(WDG_DEV_ERROR_DETECT == STD_ON)||(WDG_DEBUG_SUPPORT == STD_ON)*/

    /* Trigger the watchdog if Wdg_TimeoutCounter has not reached zero,
       otherwise watchdog will not get triggered and watchdog timer will expire
       causing reset - WDG134: WDG135: WDG140:*/

    if(Wdg_TimeoutCounter[CoreId] > 0x00U)
    {
      /* Decrement the Timeout Counter */
      Wdg_TimeoutCounter[CoreId] = Wdg_TimeoutCounter[CoreId] - 0x01U;
      /* Service the Watchdog hardware */
      Wdg_lTrigger();
    }
    else
    {
      /* Disable the GTM channel timer, as further service of WDG is
         not required after window expires*/
 
      /* Disable ATOM/TOM channel */ 
      Wdg_lDisableGtmChannel(GtmArrayIdx,GtmModuleNum,GtmChannelNum,\
                                                           WDG_RUNTIME_ACCESS);
    }
   #if ((WDG_DEV_ERROR_DETECT == STD_ON) || (WDG_DEBUG_SUPPORT == STD_ON))
     /* Set Driver State to Idle - WDG052: */
   Wdg_17_Scu_DriverState[CoreId] = WDG_IDLE;
   #endif
   /*(WDG_DEV_ERROR_DETECT == STD_ON)||(WDG_DEBUG_SUPPORT == STD_ON)*/
   /* Exit the critical section */
   SchM_Exit_Wdg_17_Scu_TimerHandling();
  }
}
#define WDG_17_SCU_STOP_SEC_CALLOUT_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
  allowed only for MemMap.h*/
#include "MemMap.h"
#endif
 /* WDG_MAXQM_TIMERS*/
