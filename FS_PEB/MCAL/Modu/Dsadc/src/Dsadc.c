/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2013)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  $FILENAME   : Dsadc.c $                                                  **
**                                                                            **
**  $CC VERSION : \main\32 $                                                 **
**                                                                            **
**  $DATE       : 2016-11-23 $                                               **
**                                                                            **
**  AUTHOR      : DL-AUTOSAR-Engineering                                      **
**                                                                            **
**  VENDOR      : Infineon Technologies                                       **
**                                                                            **
**  DESCRIPTION : This file contains                                          **
**                functionality of DSADC driver.                              **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: No                                       **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                                                                            **
**  TRACEABILITY : [cover parentID=] [/cover]                                 **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

  /* Inclusion of controller sfr file */
#include "IfxSrc_reg.h"

  /* Inclusion of Dsadc sfr file */
#include "IfxDsadc_reg.h"

  /* Inclusion of Dsadc.h header file */
#include "Dsadc.h"


/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/
/*************** SW Version Checks ***************/
#ifndef DSADC_SW_MAJOR_VERSION
  #error "DSADC_SW_MAJOR_VERSION is not defined."
#endif

#ifndef DSADC_SW_MINOR_VERSION
  #error "DSADC_SW_MINOR_VERSION is not defined."
#endif

#ifndef DSADC_SW_PATCH_VERSION
  #error "DSADC_SW_PATCH_VERSION is not defined."
#endif

/* Check for Correct inclusion of headers */
#if ( DSADC_SW_MAJOR_VERSION != 2U )
  #error "DSADC_SW_MAJOR_VERSION does not match."
#endif
#if ( DSADC_SW_MINOR_VERSION != 2U )
  #error "DSADC_SW_MINOR_VERSION does not match."
#endif

#define DSADC_DRIVER_UNINIT                 ((uint8)0U)
#define DSADC_DRIVER_INIT                   ((uint8)1U)

#define DSADC_ZERO_U                            (0U)
#define DSADC_ONE_U                             (1U)

/* Start Address of DSADC Register - SRC_DSADC0_SR0*/
#define DSADC_REGMAP                    ((Ifx_DSADC *)(void *) &(MODULE_DSADC))
/* Start Address of DSADC Interrupt Register - SRC_DSADC0_SR0*/
#define DSADC_SRC_REGMAP    ((Ifx_SRC_DSADC *)(void *) &(SRC_DSADC_DSADC0_SRM))

#define DSADC_KRST_TIMEOUT_VALUE (0x00000100U)

/******************************************************************************
**                      Private Type Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

#define DSADC_START_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"
/* function to get modulator clock frequency.. */
static float32 Dsadc_lGetModulatorClockFreq(Dsadc_ChannelType ChannelId);
/* function to get CIC filter frequency  */
static float32 Dsadc_lGetCICFilterFrequency(Dsadc_ChannelType ChannelId);
/* function to get FIR filter frequency  */
static float32 Dsadc_lGetFIRFreq(Dsadc_ChannelType ChannelId);

#define DSADC_STOP_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"
/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
#if (DSADC_PB_FIXEDADDR == STD_ON)
#define DSADC_START_SEC_CONST_32BIT
/*
 * To be used for global constants (32 bits)
 * Inclusion of MemMap.h
*/
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

/* To store the Dsadc driver configuration pointer */
static const Dsadc_ConfigType * const Dsadc_kConfigPtr = &Dsadc_ConfigRoot[0U];

#define DSADC_STOP_SEC_CONST_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"
#endif /* End of DSADC_PB_FIXEDADDR */
/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
#if (DSADC_PB_FIXEDADDR == STD_OFF)
#define DSADC_START_SEC_VAR_32BIT
/*
 * To be used for global or static variables (32 bits) that are initialized
 * after every reset (the normal case)
 * Inclusion of MemMap.h
*/
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

static const Dsadc_ConfigType *Dsadc_kConfigPtr = NULL_PTR;

#define DSADC_STOP_SEC_VAR_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"
#endif /* End of DSADC_PB_FIXEDADDR */


#define DSADC_START_SEC_VAR_8BIT
/*
 * To be used for 8bit global variables
 * Inclusion of MemMap.h
*/
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"
#if (DSADC_DEBUG_SUPPORT == STD_ON)
uint8 Dsadc_DriverState;
#else
/*IFX_MISRA_RULE_08_07_STATUS=Dsadc_DriverState is accessed in multiple
functions*/
static uint8 Dsadc_DriverState;
#endif/* End of DSADC_DEBUG_SUPPORT */

#define DSADC_STOP_SEC_VAR_8BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"
/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/
/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/





/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/*Memory Map of the DSADC Code*/
#define DSADC_START_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"
/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_DSADC_PR2822,DS_NAS_HE2_DSADC_PR3018]
**                                                                            **
** Syntax          : void Dsadc_Init(const Dsadc_ConfigType* ConfigPtr)       **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      : 0x00                                                     **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Non Reentrant                                            **
**                                                                            **
** Parameters (in) : ConfigPtr - Pointer to Dsadc Driver configuration set    **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
** Description : Driver Module Initialization                                 **
**               1.This function will initialize all relevant registers of    **
**                 with the values of structure given by ConfigPtr            **
**                                                                            **
*******************************************************************************/
void Dsadc_Init(const Dsadc_ConfigType* ConfigPtr)
{
  volatile uint8 ClcStatus; /* Variable to hold the CLC register status */
  uint8 lchcount;
  Dsadc_ChannelType lChannelID;


  #if(DSADC_RESET_SFR_INIT == STD_ON)
  uint32 TimeOutVar;
  volatile uint32 ReadBack;
  volatile uint8 KrstStatus; /* Variable to hold the KRST register status */
  #endif
  const Dsadc_ChannelConfigType *lchannelconfig;

  ClcStatus = 1U;

  /* Check if DET is ON*/
  #if ( DSADC_DEV_ERROR_DETECT == STD_ON )
  /*Check if PB Fixed Address is OFF*/
  #if (DSADC_PB_FIXEDADDR == STD_OFF)
  /*Report DET if Config Pointer is NULL*/
  if(ConfigPtr == NULL_PTR)
  #else
  /*Report DET if Config Pointer does not match*/
  if(ConfigPtr != Dsadc_kConfigPtr)
  #endif/* End of Dsadc_PB_FIXEDADDR */
  {
    /*Report DET on ConfigPtr error*/
    Det_ReportError((uint16)DSADC_MODULE_ID,DSADC_MODULE_INSTANCE,
                    DSADC_SID_INIT,DSADC_E_PARAM_CONFIG);
  }
  else
  #endif /* End of Dsadc_DEV_ERROR_DETECT */
  {
   if(Dsadc_DriverState != DSADC_DRIVER_INIT)
   {
    #if (DSADC_PB_FIXEDADDR == STD_OFF)
    /*Store the Config Pointer to Global variable*/
    Dsadc_kConfigPtr = ConfigPtr;
    #endif /* End of Dsadc_PB_FIXEDADDR  */

    /*Initialize all the Dsadc modules.*/
    /*Check if the module configuration exists*/
    /*IFX_MISRA_RULE_13_07_STATUS=MISRA states to check only
    for logical operators but PC LINT also checks for
    bitwise operators. Confirmed as a tool issue from PCLINT*/
    if(ConfigPtr != NULL_PTR)
    {
     /*Clear the ENDINIT bit in the WDT_CONSR register in order
     to disable the write-protection for registers protected
     via the EndInit feature */
     DSADC_SFR_INIT_RESETENDINIT();
     /*IFX_MISRA_RULE_11_05_STATUS=volatile in terms of pointer access.
     Permitted for special function registers.*/
     DSADC_SFR_INIT_WRITE32(DSADC_REGMAP->CLC.U, DSADC_ZERO_U);
     /* Set ENOINIT bit in the WDT_CONSR register in order to enable
     the write protection for registers peotected via EndInit
     feature */
     DSADC_SFR_INIT_SETENDINIT();

     /*IFX_MISRA_RULE_11_05_STATUS=volatile in terms of pointer access.
     Permitted for special function registers.*/
     ClcStatus = (uint8)(((uint32) \
                       DSADC_SFR_INIT_USER_MODE_READ32(DSADC_REGMAP->CLC.U)) & \
                    ((uint32)IFX_DSADC_CLC_DISS_MSK << IFX_DSADC_CLC_DISS_OFF));
     ClcStatus = (uint8)((uint32)ClcStatus >> IFX_DSADC_CLC_DISS_OFF);

     if(ClcStatus == 0U)
     {
      #if(DSADC_RESET_SFR_INIT == STD_ON)
      DSADC_SFR_INIT_RESETENDINIT();
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
      efficiently access the SFRs of multiple DSADC kernels*/
      DSADC_SFR_INIT_MODIFY32(DSADC_KRST0.U, DSADC_KRST0_SFR_MSK,  \
                   ((uint32)IFX_DSADC_KRST0_RST_MSK << IFX_DSADC_KRST0_RST_OFF))
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
      efficiently access the SFRs of multiple DSADC kernels*/
      ReadBack = (uint32)DSADC_SFR_INIT_USER_MODE_READ32(DSADC_KRST0.U);
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
      efficiently access the SFRs of multiple DSADC kernels*/
      DSADC_SFR_INIT_WRITE32(DSADC_KRST1.U, DSADC_ONE_U);
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
      efficiently access the SFRs of multiple DSADC kernels*/
      ReadBack = (uint32)DSADC_SFR_INIT_USER_MODE_READ32(DSADC_KRST1.U);
      DSADC_SFR_INIT_SETENDINIT();
      TimeOutVar = DSADC_KRST_TIMEOUT_VALUE;
      do
      {
       TimeOutVar--;

       KrstStatus = (uint8)(((uint32) \
                             DSADC_SFR_INIT_USER_MODE_READ32(DSADC_KRST0.U)) & \
          ((uint32)IFX_DSADC_KRST0_RSTSTAT_MSK << IFX_DSADC_KRST0_RSTSTAT_OFF));
       KrstStatus = (uint8)((uint32)KrstStatus >> IFX_DSADC_KRST0_RSTSTAT_OFF);
      }while((KrstStatus != 1U)&&(TimeOutVar > 0U));
      DSADC_SFR_INIT_RESETENDINIT();
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
      efficiently access the SFRs of multiple DSADC kernels*/
      DSADC_SFR_INIT_WRITE32(DSADC_KRSTCLR.U, DSADC_KRSTCLR_SFR_MSK);
      ReadBack = (uint32)DSADC_SFR_INIT_USER_MODE_READ32(DSADC_KRSTCLR.U);
      DSADC_SFR_INIT_SETENDINIT();
      UNUSED_PARAMETER(ReadBack)
      #endif
      /* (DSADC_RESET_SFR_INIT == STD_ON) */
      DSADC_SFR_INIT_RESETENDINIT();
      /*Configure the Sleep Mode enable/diable*/
      /*IFX_MISRA_RULE_11_05_STATUS=volatile in terms of pointer access.
      Permitted for special function registers.*/
      DSADC_SFR_INIT_MODIFY32(DSADC_REGMAP->CLC.U, DSADC_CLC_SFR_EDIS_MSK,\
                ((uint32)Dsadc_kConfigPtr->SleepMode << IFX_DSADC_CLC_EDIS_OFF))
      /*IFX_MISRA_RULE_11_05_STATUS=volatile in terms of pointer access.
      Permitted for special function registers.*/
      DSADC_SFR_INIT_MODIFY32(DSADC_REGMAP->CLC.U, DSADC_CLC_SFR_DISR_MSK,\
                                      ((uint32)FALSE << IFX_DSADC_CLC_DISR_OFF))
      DSADC_SFR_INIT_SETENDINIT();

      /*IFX_MISRA_RULE_11_05_STATUS=volatile in terms of pointer access.
      Permitted for special function registers.*/
      ClcStatus = (uint8)(((uint32) \
                       DSADC_SFR_INIT_USER_MODE_READ32(DSADC_REGMAP->CLC.U)) & \
                    ((uint32)IFX_DSADC_CLC_DISS_MSK << IFX_DSADC_CLC_DISS_OFF));
      ClcStatus = (uint8)((uint32)ClcStatus >> IFX_DSADC_CLC_DISS_OFF);

      if(ClcStatus == 0U)
      {
       /*IFX_MISRA_RULE_11_05_STATUS=volatile in terms of pointer access.
       Permitted for special function registers.*/
       DSADC_SFR_INIT_USER_MODE_MODIFY32(DSADC_REGMAP->GLOBCFG.U, \
             DSADC_GLOBCFG_SFR_MSK,((uint32)TRUE << IFX_DSADC_GLOBCFG_PSWC_OFF))
       /*Configure the clock settings for Dsadc*/
       /*IFX_MISRA_RULE_11_05_STATUS=volatile in terms of pointer access.
       Permitted for special function registers.*/
       DSADC_SFR_INIT_USER_MODE_WRITE32(DSADC_REGMAP->GLOBCFG.U, \
                                                Dsadc_kConfigPtr->GlobalConfig);

       /* Set the ENDINIT bit in the WDT_CONSR register again
       to enable the write-protection and to prevent a time-out */
       /*IFX_MISRA_RULE_11_05_STATUS=volatile in terms of pointer access.
       Permitted for special function registers.*/
       DSADC_SFR_INIT_USER_MODE_MODIFY32(DSADC_REGMAP->GLOBCFG.U, \
            DSADC_GLOBCFG_SFR_MSK,((uint32)FALSE << IFX_DSADC_GLOBCFG_PSWC_OFF))

       #if (DSADC_RESOLVER_SUPPORT == STD_ON)
       /* Write Carrier Generation register */
       /*IFX_MISRA_RULE_11_05_STATUS=volatile in terms of pointer access.
       Permitted for special function registers.*/
       DSADC_SFR_INIT_USER_MODE_WRITE32(DSADC_REGMAP->CGCFG.U, \
                                            Dsadc_kConfigPtr->CarrierGenConfig);

       #endif
       /* Initilize all the channel configuration */
       for(lchcount = 0U; lchcount< DSADC_NUM_OF_CHANNELS; lchcount++)
       {
        /* Store Channel configuration locally to easy access */
        lchannelconfig = Dsadc_kConfigPtr->Dsadc_kChannelConf[lchcount];
        /* Check channel configuration available */
        if(NULL_PTR != lchannelconfig)
        {
         /* Get the channel ID from configuration parameter */
         lChannelID = lchannelconfig->ChannelID;
         /* Write Modulator configuration for specified channel */
         /*IFX_MISRA_RULE_11_05_STATUS=volatile in terms of pointer access.
         Permitted for special function registers.*/
         DSADC_SFR_INIT_USER_MODE_WRITE32( \
         DSADC_REGMAP->CH[lChannelID].MODCFG.U,lchannelconfig->ModulatorConfig);
         /* Write Demodulator configuration for specified channel */
         /*IFX_MISRA_RULE_11_05_STATUS=volatile in terms of pointer access.
         Permitted for special function registers.*/
         DSADC_SFR_INIT_USER_MODE_WRITE32(DSADC_REGMAP->CH[lChannelID].DICFG.U,\
                                             lchannelconfig->DemodulatorConfig);
         /* Write Main CIC filter configuration for specified channel */
         /*IFX_MISRA_RULE_11_05_STATUS=volatile in terms of pointer access.
          Permitted for special function registers.*/
         DSADC_SFR_INIT_USER_MODE_WRITE32(DSADC_REGMAP->CH[lChannelID].FCFGC.U,\
                                                 lchannelconfig->MainCICConfig);
         /* Write Main FIR filter configuration for specified channel */
         /*IFX_MISRA_RULE_11_05_STATUS=volatile in terms of pointer access.
         Permitted for special function registers.*/
         DSADC_SFR_INIT_USER_MODE_WRITE32(DSADC_REGMAP->CH[lChannelID].FCFGM.U,\
                                                     lchannelconfig->FIRConfig);
         /* Write offset value for specified channel */
         /*IFX_MISRA_RULE_11_05_STATUS=volatile in terms of pointer access.
         Permitted for special function registers.*/
         DSADC_SFR_INIT_USER_MODE_WRITE32(DSADC_REGMAP->CH[lChannelID].OFFM.U,\
                                                 lchannelconfig->OffsetConfig);
         #if (DSADC_ENABLE_LIMIT_CHECK == STD_ON)
         /* Write Auxiliary CIC filter configuration for specified channel */
         /*IFX_MISRA_RULE_11_05_STATUS=volatile in terms of pointer access.
         Permitted for special function registers.*/
         DSADC_SFR_INIT_USER_MODE_WRITE32(DSADC_REGMAP->CH[lChannelID].FCFGA.U,\
                                                  lchannelconfig->AuxCICConfig);
         /* Write Boundary condition for specified channel */
         /*IFX_MISRA_RULE_11_05_STATUS=volatile in terms of pointer access.
           Permitted for special function registers.*/
         DSADC_SFR_INIT_USER_MODE_WRITE32( \
                                      DSADC_REGMAP->CH[lChannelID].BOUNDSEL.U, \
                                                lchannelconfig->BoundaryConfig);
         #endif
         /* Write Integrator configuration for specified channel */
         /*IFX_MISRA_RULE_11_05_STATUS=volatile in terms of pointer access.
          Permitted for special function registers.*/
         DSADC_SFR_INIT_USER_MODE_WRITE32(DSADC_REGMAP->CH[lChannelID].IWCTR.U,\
                                             lchannelconfig->IntegrationConfig);
         #if (DSADC_RESOLVER_SUPPORT == STD_ON)
         /* Write Recifier configuration for specified channel */
         /*IFX_MISRA_RULE_11_05_STATUS=volatile in terms of pointer access.
          Permitted for special function registers.*/
         DSADC_SFR_INIT_USER_MODE_WRITE32( \
         DSADC_REGMAP->CH[lChannelID].RECTCFG.U,lchannelconfig->RectfierConfig);
         /*IFX_MISRA_RULE_11_05_STATUS=volatile in terms of pointer access.
         Permitted for special function registers.*/
         DSADC_SFR_INIT_USER_MODE_WRITE32( \
            DSADC_REGMAP->CH[lChannelID].CGSYNC.U,lchannelconfig->CGSyncConfig);
         #endif
         /* Write Time Stamp configuration for specified channel */
         /*IFX_MISRA_RULE_11_05_STATUS=volatile in terms of pointer access.
         Permitted for special function registers.*/
         DSADC_SFR_INIT_USER_MODE_WRITE32(DSADC_REGMAP->CH[lChannelID].TSTMP.U,\
                                               lchannelconfig->TimeStampConfig);
         #if (DSADC_INITIAL_CONFIGURATION  == STD_ON)
         /*IFX_MISRA_RULE_11_05_STATUS=volatile in terms of pointer access.
         Permitted for special function registers.*/
         DSADC_SFR_INIT_USER_MODE_WRITE32(DSADC_REGMAP->CH[lChannelID].ICCFG.U,\
                                          lchannelconfig->InitialChannelConfig);
         #endif
         /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
         efficiently access the SFRs of multiple*/
         DSADC_SFR_INIT_MODIFY32(DSADC_SRC_REGMAP[lChannelID].SRM.U, \
              DSADC_SRC_SRCR_MSK, ((uint32)DSADC_ONE_U << IFX_SRC_SRCR_SRE_OFF))
         #if (DSADC_ENABLE_LIMIT_CHECK == STD_ON)
         /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
         efficiently access the SFRs of multiple*/
         DSADC_SFR_INIT_MODIFY32(DSADC_SRC_REGMAP[lChannelID].SRA.U, \
              DSADC_SRC_SRCR_MSK, ((uint32)DSADC_ONE_U << IFX_SRC_SRCR_SRE_OFF))
         #endif
        }
       }
       #if (DSADC_COMMON_MODE_HOLD_VOLTAGE == STD_ON)
       /*IFX_MISRA_RULE_11_05_STATUS=volatile in terms of pointer access.
       Permitted for special function registers.*/
       DSADC_SFR_INIT_USER_MODE_WRITE32(DSADC_GLOBVCMH0.U, \
                                    Dsadc_kConfigPtr->CommonModeHoldConfig[0U]);
       #if(DSADC_MAX_CMHV_REG != 2U)
       /*IFX_MISRA_RULE_11_05_STATUS=volatile in terms of pointer access.
       Permitted for special function registers.*/
       DSADC_SFR_INIT_USER_MODE_WRITE32(DSADC_GLOBVCMH1.U, \
                                    Dsadc_kConfigPtr->CommonModeHoldConfig[1U]);
       /*IFX_MISRA_RULE_11_05_STATUS=volatile in terms of pointer access.
       Permitted for special function registers.*/
       DSADC_SFR_INIT_USER_MODE_WRITE32(DSADC_GLOBVCMH2.U,
                                    Dsadc_kConfigPtr->CommonModeHoldConfig[2U]);
       #else
       /*IFX_MISRA_RULE_11_05_STATUS=volatile in terms of pointer access.
        Permitted for special function registers.*/
       DSADC_SFR_INIT_USER_MODE_WRITE32(DSADC_GLOBVCMH2.U, \
                                    Dsadc_kConfigPtr->CommonModeHoldConfig[1U]);
       #endif
       #endif
       #if (DSADC_INITIAL_CONFIGURATION == STD_ON)
       /*IFX_MISRA_RULE_11_05_STATUS=volatile in terms of pointer access.
       Permitted for special function registers.*/
       DSADC_SFR_INIT_USER_MODE_WRITE32(DSADC_REGMAP->IGCFG.U, \
                                         Dsadc_kConfigPtr->GlobalInitialConfig);
       #endif

       /* Change the Dsadc_DriverState to initialized*/
       Dsadc_DriverState = DSADC_DRIVER_INIT;
      }
     }
     if(ClcStatus != 0U)
     {
      /* Change the Dsadc_DriverState to initialized*/
      Dsadc_DriverState = DSADC_DRIVER_UNINIT;
     }
    }
   }
  }
}

#if (DSADC_DEINIT_API == STD_ON)
/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_DSADC_PR2823 ]                       **
**                                                                            **
** Syntax          : void Dsadc_DeInit(void)                                  **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      : 0x01                                                     **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Non Reentrant                                            **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
** Description : Driver DeInitialization                                      **
**               1.This function will deinitialize the DSADC peripheral       **
**                                                                            **
*******************************************************************************/
void Dsadc_DeInit(void)
{
  volatile uint32 Readback;
  volatile uint8 ClcStatus; /* Variable to hold the CLC register status */
  volatile uint8 KrstStatus; /* Variable to hold the KRST register status */
  uint8 ChNum;
  uint8 DsadcServReq;

  #if(DSADC_RESET_SFR_INIT == STD_ON)
  uint32 TimeOutVar;
  #endif

  ChNum = 0U;
  ClcStatus = 0U;
  /*Start from DSADC module*/
  if(Dsadc_DriverState == DSADC_DRIVER_INIT)
  {
    /*IFX_MISRA_RULE_13_07_STATUS=MISRA states to check only
                for logical operators but PC LINT also checks for
           bitwise operators. Confirmed as a tool issue from PCLINT*/
    if(Dsadc_kConfigPtr != NULL_PTR)
    {
      while(ChNum < DSADC_NUM_OF_CHANNELS)
      {
        /* Disable Service Requests */
        /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
             efficiently access the SFRs of multiple*/
        DsadcServReq = (uint8)(((uint32)DSADC_SFR_DEINIT_USER_MODE_READ32( \
                                           DSADC_SRC_REGMAP[ChNum].SRM.U)) & \
                      ((uint32)IFX_SRC_SRCR_SRE_MSK << IFX_SRC_SRCR_SRE_OFF));
        DsadcServReq =  (uint8)((uint32)DsadcServReq >> IFX_SRC_SRCR_SRE_OFF);
        if(DsadcServReq == DSADC_ONE_U)
        {
          /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
             efficiently access the SFRs of multiple*/
          DSADC_SFR_DEINIT_MODIFY32(DSADC_SRC_REGMAP[ChNum].SRM.U, \
             DSADC_SRC_SRCR_MSK, ((uint32)DSADC_ONE_U << IFX_SRC_SRCR_CLRR_OFF))
          /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
             efficiently access the SFRs of multiple*/
          DSADC_SFR_DEINIT_MODIFY32(DSADC_SRC_REGMAP[ChNum].SRM.U, \
           DSADC_SRC_SRCR_MSK, ((uint32)DSADC_ONE_U << IFX_SRC_SRCR_IOVCLR_OFF))
          /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
             efficiently access the SFRs of multiple*/
          DSADC_SFR_DEINIT_MODIFY32(DSADC_SRC_REGMAP[ChNum].SRM.U, \
           DSADC_SRC_SRCR_MSK, ((uint32)DSADC_ONE_U << IFX_SRC_SRCR_SWSCLR_OFF))
          /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
             efficiently access the SFRs of multiple*/
          DSADC_SFR_DEINIT_MODIFY32(DSADC_SRC_REGMAP[ChNum].SRM.U, \
              ~((uint32)(IFX_SRC_SRCR_SRE_MSK << IFX_SRC_SRCR_SRE_OFF)),\
                                                           DSADC_SFR_CLEAR_MSK)
        }
        /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
             efficiently access the SFRs of multiple*/
        DsadcServReq = (uint8)(((uint32)DSADC_SFR_DEINIT_USER_MODE_READ32( \
                                           DSADC_SRC_REGMAP[ChNum].SRA.U)) & \
                      ((uint32)IFX_SRC_SRCR_SRE_MSK << IFX_SRC_SRCR_SRE_OFF));
        DsadcServReq =  (uint8)((uint32)DsadcServReq >> IFX_SRC_SRCR_SRE_OFF);
        if(DsadcServReq == DSADC_ONE_U)
        {
          /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
             efficiently access the SFRs of multiple*/
          DSADC_SFR_DEINIT_MODIFY32(DSADC_SRC_REGMAP[ChNum].SRA.U, \
             DSADC_SRC_SRCR_MSK, ((uint32)DSADC_ONE_U << IFX_SRC_SRCR_CLRR_OFF))
          /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
             efficiently access the SFRs of multiple*/
          DSADC_SFR_DEINIT_MODIFY32(DSADC_SRC_REGMAP[ChNum].SRA.U, \
           DSADC_SRC_SRCR_MSK, ((uint32)DSADC_ONE_U << IFX_SRC_SRCR_IOVCLR_OFF))
          /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
             efficiently access the SFRs of multiple*/
          DSADC_SFR_DEINIT_MODIFY32(DSADC_SRC_REGMAP[ChNum].SRA.U, \
           DSADC_SRC_SRCR_MSK, ((uint32)DSADC_ONE_U << IFX_SRC_SRCR_SWSCLR_OFF))
          /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
             efficiently access the SFRs of multiple*/
          DSADC_SFR_DEINIT_MODIFY32(DSADC_SRC_REGMAP[ChNum].SRA.U, \
                   ~((uint32)(IFX_SRC_SRCR_SRE_MSK << IFX_SRC_SRCR_SRE_OFF)), \
                                                           DSADC_SFR_CLEAR_MSK)
        }
        ChNum++;
      }

      #if(DSADC_RESET_SFR_INIT == STD_ON)
      DSADC_SFR_DEINIT_RESETENDINIT();
      /* Set request to reset the DSADC Kernel */
      /*IFX_MISRA_RULE_11_05_STATUS=volatile in terms of pointer access.
              Permitted for special function registers.*/
      DSADC_SFR_DEINIT_MODIFY32(DSADC_REGMAP->KRST0.U, DSADC_KRST0_SFR_MSK,  \
                              ((uint32)DSADC_ONE_U << IFX_DSADC_KRST0_RST_OFF))
      /*IFX_MISRA_RULE_11_05_STATUS=volatile in terms of pointer access.
              Permitted for special function registers.*/
      DSADC_SFR_DEINIT_WRITE32(DSADC_REGMAP->KRST1.U, DSADC_KRST1_SFR_MSK);
      /*IFX_MISRA_RULE_11_05_STATUS=volatile in terms of pointer access.
              Permitted for special function registers.*/
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
             efficiently access the SFRs of multiple*/
      Readback = DSADC_SFR_DEINIT_USER_MODE_READ32(DSADC_REGMAP[ChNum].KRST0.U);
      /*IFX_MISRA_RULE_11_05_STATUS=volatile in terms of pointer access.
              Permitted for special function registers.*/
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
             efficiently access the SFRs of multiple*/
      Readback = DSADC_SFR_DEINIT_USER_MODE_READ32(DSADC_REGMAP[ChNum].KRST1.U);
      TimeOutVar = DSADC_KRST_TIMEOUT_VALUE;
      do
      {
        TimeOutVar--;

       KrstStatus = (uint8)(((uint32) \
                           DSADC_SFR_DEINIT_USER_MODE_READ32(DSADC_KRST0.U)) & \
          ((uint32)IFX_DSADC_KRST0_RSTSTAT_MSK << IFX_DSADC_KRST0_RSTSTAT_OFF));
       KrstStatus = (uint8)((uint32)KrstStatus >> IFX_DSADC_KRST0_RSTSTAT_OFF);
      }while((KrstStatus != 1U)&&(TimeOutVar > 0U));
      DSADC_SFR_DEINIT_SETENDINIT();
      #endif
      UNUSED_PARAMETER(Readback)
      DSADC_SFR_DEINIT_RESETENDINIT();
      /* Clear the DSADC Kernel Reset Flag */
      /*IFX_MISRA_RULE_11_05_STATUS=volatile in terms of pointer access.
              Permitted for special function registers.*/
      DSADC_SFR_DEINIT_WRITE32(DSADC_REGMAP->KRSTCLR.U, DSADC_KRSTCLR_SFR_MSK);
      /* Disable the Module using CLC register */
      /*IFX_MISRA_RULE_11_05_STATUS=volatile in terms of pointer access.
              Permitted for special function registers.*/
      DSADC_SFR_DEINIT_MODIFY32(DSADC_REGMAP->CLC.U, DSADC_CLC_SFR_DISR_MSK,\
                                       ((uint32)TRUE << IFX_DSADC_CLC_DISR_OFF))
      /* Set the ENDINIT bit in the WDT_CONSR register again
      to enable the write-protection and to prevent a time-out */
      DSADC_SFR_DEINIT_SETENDINIT();
      ClcStatus = (uint8)(((uint32) \
                     DSADC_SFR_DEINIT_USER_MODE_READ32(DSADC_REGMAP->CLC.U)) & \
                    ((uint32)IFX_DSADC_CLC_DISS_MSK << IFX_DSADC_CLC_DISS_OFF));
      ClcStatus = (uint8)((uint32)ClcStatus >> IFX_DSADC_CLC_DISS_OFF);
    }
  }

  if(ClcStatus != 0U)
  {
    #if (DSADC_PB_FIXEDADDR == STD_OFF)
    /*Store the NULL to Global Pointer variable*/
    Dsadc_kConfigPtr = NULL_PTR;
    #endif /* End of DSADC_PB_FIXEDADDR */
    /* Set Dsadc_DriverState to Un-Initialized */
    Dsadc_DriverState = DSADC_DRIVER_UNINIT;
  }
}
#endif /* End of DSADC_DEINIT_API */
/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          :float32 Dsadc_CalGroupDelay(Dsadc_ChannelType ChannelId)  **
**                                                                            **
** Service ID      : 0x12                                                     **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      :  Reentrant                                               **
**                                                                            **
** Parameters (in) : ChannnelId - Dsadc Channel number                        **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : returns calculated group delay of the channel            **
**                                                                            **
** Description :     this function is called to calculate the                 **
**                 delay between data enter the filter chain and appear at the**
**                 filter chain output                                        **
**                                                                            **
*******************************************************************************/
float32 Dsadc_CalGroupDelay(Dsadc_ChannelType ChannelId)
{
  uint8 CicDF,CicConfig,Fir0En,Fir1En;
  uint32 DicfgStatus,FcfgcStatus,IwctrStatus;
  float32 TsMod,TsComb,TsFir0,TsFir1;
  float32 GdDsA,GdComb,GdFir0,GdFir1,GdInt;

  /*Read the decimation factor of each filter  */
  /*IFX_MISRA_RULE_11_05_STATUS=volatile in terms of pointer access.
              Permitted for special function registers.*/
  CicDF = (uint8)(((uint32) \
    DSADC_SFR_RUNTIME_USER_MODE_READ32(DSADC_REGMAP->CH[ChannelId].FCFGC.U)) & \
        ((uint32)IFX_DSADC_CH_FCFGC_CFMDF_MSK << IFX_DSADC_CH_FCFGC_CFMDF_OFF));
  CicDF = (uint8)((uint32)CicDF >> IFX_DSADC_CH_FCFGC_CFMDF_OFF);
  /*IFX_MISRA_RULE_11_05_STATUS=volatile in terms of pointer access.
              Permitted for special function registers.*/
  FcfgcStatus = (uint32)(((uint32) \
    DSADC_SFR_RUNTIME_USER_MODE_READ32(DSADC_REGMAP->CH[ChannelId].FCFGC.U)) & \
        ((uint32)IFX_DSADC_CH_FCFGC_CFMC_MSK << IFX_DSADC_CH_FCFGC_CFMC_OFF));
  CicConfig = (uint8)((uint32)FcfgcStatus >> IFX_DSADC_CH_FCFGC_CFMC_OFF);
  /*IFX_MISRA_RULE_11_05_STATUS=volatile in terms of pointer access.
              Permitted for special function registers.*/
  Fir0En = (uint8)(((uint32) \
    DSADC_SFR_RUNTIME_USER_MODE_READ32(DSADC_REGMAP->CH[ChannelId].FCFGM.U)) & \
      ((uint32)IFX_DSADC_CH_FCFGM_FIR0EN_MSK << IFX_DSADC_CH_FCFGM_FIR0EN_OFF));
  Fir0En = (uint8)((uint32)Fir0En >> IFX_DSADC_CH_FCFGM_FIR0EN_OFF);
  /*IFX_MISRA_RULE_11_05_STATUS=volatile in terms of pointer access.
              Permitted for special function registers.*/
  Fir1En = (uint8)(((uint32) \
    DSADC_SFR_RUNTIME_USER_MODE_READ32(DSADC_REGMAP->CH[ChannelId].FCFGM.U)) & \
      ((uint32)IFX_DSADC_CH_FCFGM_FIR1EN_MSK << IFX_DSADC_CH_FCFGM_FIR1EN_OFF));
  Fir1En = (uint8)((uint32)Fir1En >> IFX_DSADC_CH_FCFGM_FIR1EN_OFF);
  /* Calculate time period of modulator clock, CIC filter and FIR filters*/
  TsMod = 1.0f / Dsadc_lGetModulatorClockFreq(ChannelId);
  TsComb = TsMod * (1.0f + (float32)CicDF);
  TsFir0 = TsComb * (1.0f + (float32)Fir0En);
  TsFir1 = TsFir0 * (1.0f + (float32)Fir1En);
  /* Calculate group delay of modulator, CIC, FIR filters and integrator */
  GdDsA = 7.0f * TsMod;
  GdComb = (CicConfig != 3U)?(TsMod * (1.0f + (float32)CicDF) * 0.5f *
              ((float32)CicConfig + 1.0f)):(TsMod * (2.0f + (float32)CicDF));
  GdFir0 = (Fir0En != 0U) ? (0.5f * 8.0f * TsComb) : 0.0f;
  GdFir1 = (Fir1En != 0U) ? ((Fir0En != 0U)? ( 28.0f * TsFir0): \
                            ((0.5f * 28.0f * TsFir0))): 0.0f;
  /*IFX_MISRA_RULE_11_05_STATUS=volatile in terms of pointer access.
       Permitted for special function registers.*/
  /*IFX_MISRA_RULE_11_05_STATUS=volatile in terms of pointer access.
       Permitted for special function registers.*/
  DicfgStatus = (((uint32) \
    DSADC_SFR_RUNTIME_USER_MODE_READ32(DSADC_REGMAP->CH[ChannelId].DICFG.U)) & \
    ((uint32)IFX_DSADC_CH_DICFG_ITRMODE_MSK << IFX_DSADC_CH_DICFG_ITRMODE_OFF));
  DicfgStatus = (uint32)(DicfgStatus >> IFX_DSADC_CH_DICFG_ITRMODE_OFF);
  /*IFX_MISRA_RULE_11_05_STATUS=volatile in terms of pointer access.
       Permitted for special function registers.*/
  IwctrStatus = (((uint32) \
    DSADC_SFR_RUNTIME_USER_MODE_READ32(DSADC_REGMAP->CH[ChannelId].IWCTR.U)) & \
    ((uint32)IFX_DSADC_CH_IWCTR_NVALINT_MSK << IFX_DSADC_CH_IWCTR_NVALINT_OFF));
  IwctrStatus = (IwctrStatus >> IFX_DSADC_CH_IWCTR_NVALINT_OFF);

  GdInt = (DicfgStatus == 0U) ? 0.0f : (0.5f * (((float32)IwctrStatus) + 1.0f) \
                                                                      * TsFir1);
  /* Add group delay of all components */
  return (GdDsA + GdComb + GdFir0 + GdFir1 + GdInt);
}


/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax    :   float32 Dsadc_GetChOutputFreq (Dsadc_ChannelType ChannelId) **
**                                                                            **
** Service ID      : 0x13                                                     **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      :  Reentrant                                               **
**                                                                            **
** Parameters (in) : ChannnelId - Dsadc Channel number                        **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : returns output frequency of the channel                  **
**                                                                            **
** Description :     calculates output(integrator) frequency of the           **
**                                                      given channel         **
**                                                                            **
*******************************************************************************/
float32 Dsadc_GetChOutputFreq(Dsadc_ChannelType ChannelId)
{
  uint32 IwctrStatus;
  float32 FIRFreq,IntFreq;
  FIRFreq = Dsadc_lGetFIRFreq(ChannelId);
  /*IFX_MISRA_RULE_11_05_STATUS=volatile in terms of pointer access.
              Permitted for special function registers.*/
  IwctrStatus = (((uint32) \
    DSADC_SFR_RUNTIME_USER_MODE_READ32(DSADC_REGMAP->CH[ChannelId].IWCTR.U)) & \
    ((uint32)IFX_DSADC_CH_IWCTR_NVALINT_MSK << IFX_DSADC_CH_IWCTR_NVALINT_OFF));
  IwctrStatus =(IwctrStatus >> IFX_DSADC_CH_IWCTR_NVALINT_OFF);

  IntFreq = FIRFreq/(((float32)IwctrStatus) + 1.0f);
  return (IntFreq);
}

/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                                                                            **
** Syntax           : static float32 Dsadc_lGetModulatorClockFreq             **
**                         (Dsadc_ChannelType ChannelId)                      **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : float32 - modulator frequency                           **
**                                                                            **
** Description      : This function to get modulator clock frequency          **
**                                                                            **
*******************************************************************************/
static float32 Dsadc_lGetModulatorClockFreq(Dsadc_ChannelType ChannelId)
{
  uint32 ModcfgStatus;
  float32 SourceFreq,ModFreq;
  SourceFreq  = Dsadc_kConfigPtr->SourceClkFreq;
  /*IFX_MISRA_RULE_11_05_STATUS=volatile in terms of pointer access.
              Permitted for special function registers.*/
  ModcfgStatus = (((uint32) \
    DSADC_SFR_RUNTIME_USER_MODE_READ32(DSADC_REGMAP->CH[ChannelId].MODCFG.U)) &\
    ((uint32)IFX_DSADC_CH_MODCFG_DIVM_MSK << IFX_DSADC_CH_MODCFG_DIVM_OFF));
  ModcfgStatus = (ModcfgStatus >> IFX_DSADC_CH_MODCFG_DIVM_OFF);

  ModFreq = SourceFreq / ((((float32)ModcfgStatus) + 1.0f)*2.0f);
  return (ModFreq);
}
/*******************************************************************************
**                                                                            **
** Syntax           : static float32 Dsadc_lGetCICFilterFrequency             **
**                         (Dsadc_ChannelType ChannelId)                      **
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
** Return value     : float32                                                 **
**                                                                            **
** Description      : This function to get CIC filter frequency               **
**                                                                            **
*******************************************************************************/
static float32 Dsadc_lGetCICFilterFrequency(Dsadc_ChannelType ChannelId)
{
  uint32 FcfgcStatus;
  float32 ModFreq,CICFreq;
  ModFreq = Dsadc_lGetModulatorClockFreq(ChannelId);
  /*IFX_MISRA_RULE_11_05_STATUS=volatile in terms of pointer access.
              Permitted for special function registers.*/
  FcfgcStatus = (((uint32) \
    DSADC_SFR_RUNTIME_USER_MODE_READ32(DSADC_REGMAP->CH[ChannelId].FCFGC.U)) & \
        ((uint32)IFX_DSADC_CH_FCFGC_CFMDF_MSK << IFX_DSADC_CH_FCFGC_CFMDF_OFF));
  FcfgcStatus =(FcfgcStatus >> IFX_DSADC_CH_FCFGC_CFMDF_OFF);

  CICFreq = ModFreq/(((float32)(FcfgcStatus)) + 1.0f);
  return (CICFreq);
}
/*******************************************************************************
**                                                                            **
** Syntax           : static float32 Dsadc_lGetFIRFreq                        **
**                         (Dsadc_ChannelType ChannelId)                      **
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
** Return value     : float32                                                 **
**                                                                            **
** Description      : This function to get FIR filter frequency               **
**                                                                            **
*******************************************************************************/
static float32 Dsadc_lGetFIRFreq(Dsadc_ChannelType ChannelId)
{
  uint8 Fir0En,Fir1En,FirDiv;
  float32 CICFreq,FIRFreq;
  /*IFX_MISRA_RULE_11_05_STATUS=volatile in terms of pointer access.
              Permitted for special function registers.*/
  Fir0En = (uint8)(((uint32) \
    DSADC_SFR_RUNTIME_USER_MODE_READ32(DSADC_REGMAP->CH[ChannelId].FCFGM.U)) & \
      ((uint32)IFX_DSADC_CH_FCFGM_FIR0EN_MSK << IFX_DSADC_CH_FCFGM_FIR0EN_OFF));
  Fir0En = (uint8)((uint32)Fir0En >> IFX_DSADC_CH_FCFGM_FIR0EN_OFF);
  /*IFX_MISRA_RULE_11_05_STATUS=volatile in terms of pointer access.
              Permitted for special function registers.*/
  Fir1En = (uint8)(((uint32) \
    DSADC_SFR_RUNTIME_USER_MODE_READ32(DSADC_REGMAP->CH[ChannelId].FCFGM.U)) & \
      ((uint32)IFX_DSADC_CH_FCFGM_FIR1EN_MSK << IFX_DSADC_CH_FCFGM_FIR1EN_OFF));
  Fir1En = (uint8)((uint32)Fir1En >> IFX_DSADC_CH_FCFGM_FIR1EN_OFF);

  FirDiv = ((Fir0En & Fir1En) == 1U)?4U:((Fir0En == 1U)?2U: \
                                     ((Fir1En == 1U)?2U:1U));
  CICFreq = Dsadc_lGetCICFilterFrequency(ChannelId);
  FIRFreq = CICFreq /(float32)FirDiv;
  return (FIRFreq);
}


#define DSADC_STOP_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"
