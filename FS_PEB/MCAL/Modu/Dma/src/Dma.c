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
**  $FILENAME  : Dma.c                                                        **
**                                                                            **
**  $CC VERSION : \main\49 $                                                 **
**                                                                            **
**  $DATE      : 2013-06-26 $                                                 **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : This file contains                                         **
**                 - functionality of Dma Driver                              **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
**  TRACEABILITY : [cover parentID=DS_NAS_DMA_PR69_PR469_PR122_PR123,
                   DS_NAS_DMA_PR647,DS_NAS_DMA_PR746,SAS_NAS_ALL_PR749,
                   SAS_NAS_ALL_PR102,SAS_NAS_ALL_PR630_PR631
                   SAS_NAS_ALL_PR471,SAS_NAS_ALL_PR470,SAS_NAS_ALL_PR70,
                   SAS_NAS_ALL_PR1652, DS_NAS_HE2_DMA_PR3018,
                   DS_NAS_EP_DMA_PR3018][/cover]                              **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

  /* Inclusion of controller sfr file */
#include "IfxSrc_reg.h"

  /* Inclusion of Dma sfr file */
#include "IfxDma_reg.h"
#include "IfxDma_bf.h"

  /* Inclusion of Dma.h header file */
#include "Dma.h"

  /* Inclusion of Dma_Callout.h header file */
#include "Dma_Callout.h"
/*******************************************************************************
**                      Imported Compiler Switch Checks                       **
*******************************************************************************/
/*************** SW Version Checks ***************/
#ifndef DMA_SW_MAJOR_VERSION
  #error "DMA_SW_MAJOR_VERSION is not defined."
#endif

#ifndef DMA_SW_MINOR_VERSION
  #error "DMA_SW_MINOR_VERSION is not defined."
#endif

#ifndef DMA_SW_PATCH_VERSION
  #error "DMA_SW_PATCH_VERSION is not defined."
#endif

/* Check for Correct inclusion of headers */
#if ( DMA_SW_MAJOR_VERSION != 1U )
  #error "DMA_SW_MAJOR_VERSION does not match."
#endif
#if ( DMA_SW_MINOR_VERSION != 2U )
  #error "DMA_SW_MINOR_VERSION does not match."
#endif

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
#define DMA_SET_TX_REQ_MASK                   ((uint32)0x80000000U)
#define DMA_CHCFGR_TREL_MASK                  ((uint32)0xD7FF0000U)
/* Macro to Clear WRP Buffer, Dma Channel , TRL Interrupt flags */
#define DMA_CHCSR_INTFLAGS_SET_MASK           (0x06000000U)
#define DMA_TSR_INTFLAGS_SET_MASK             (0x00040000U)
/*Macro for magic numbers*/
#define DMA_NUM_8                             ((uint8)0x08U)
#define DMA_NUM_11                            ((uint8)0x0BU)
#define DMA_NUM_12                            ((uint8)0x0CU)
/* Macro for dma driver and channel initialization states */
#define DMA_DRIVER_UNINIT                     ((uint8)0x00U)
#define DMA_DRIVER_INIT                       ((uint8)0x01U)
#define DMA_DRIVER_CH_UNINIT                  ((uint8)0x00U)
#define DMA_DRIVER_CH_INIT                    ((uint8)0x01U)

#define DMA_16_BIT_MAX_VALUE                  ((uint16)0xFFFFU)
#define DMA_MAX_TCOUNT                        ((uint16)0x4000U)
#define DMA_HW_TX_REQ                         ((uint8)16U)
#define DMA_DISABLE_HW_REQ                    ((uint8)17U)
#define DMA_HALT_REQ                          ((uint8)8U)
#define DMA_HALT_CLEAR                        ((uint8)24U)

/*Callout macro definition*/
#define DMA_CALLOUT_CH_RESET_ERR              ((uint8)0x01U)
#define DMA_SAFETY_ENDINT_TIMEOUT             ((uint32)150000U)
#define DMA_DEINIT_RESET_VALUE                (0x00000000U)
#define DMA_DEINIT_BLK_ERR_VALUE              (0x05030000U)

#if(DMA_RESET_SFR_INIT == STD_ON)

#define DMA_RESET_VALUE                       (0x00000000U)
#define DMA_BLK_ERR_VALUE                     (0x05030000U)
#define DMA_MODE_RESET_VAL                    (0x00000001U)

#endif /* DMA_RESET_SFR_INIT == STD_ON */

#define DMA_CHCSR_SCH_SET_MASK                (0x80000000U)
#define DMA_CHCSR_SIT_SET_MASK                (0x08000000U)
#define DMA_CHCSR_SWB_SET_MASK                (0x01000000U)
#define DMA_CHCSR_SCH_CLR_MASK                ((uint32)0x0FCFBFFFU)
#define DMA_TSR_HW_DISABLE_REQ_CLR_MASK       ((uint32)0x0105030FU)
#define DMA_TSR_HW_DISABLE_REQ_SET_MASK       (0x00000000U)
#define DMA_TSR_HW_TX_REQ_CLR_MASK            ((uint32)0x0106030FU)
#define DMA_TSR_HW_TX_REQ_SET_MASK            ((uint32)1U<<DMA_HW_TX_REQ)
#define DMA_CHCSR_INTFLAGS_CLR_MASK           ((uint32)0x89CFBFFFU)
#define DMA_TSR_INTFLAGS_CLR_MASK             ((uint32)0x0103030FU)
#define DMA_DMA_HALT_REQ_CLR_MASK             ((uint32)0x0107020FU)
#define DMA_DMA_HALT_REQ_SET_MASK             ((uint32)1U << DMA_HALT_REQ)
#define DMA_DMA_HALT_CLEAR_CLR_MASK           ((uint32)0x0007030FU)
#define DMA_DMA_HALT_CLEAR_SET_MASK           ((uint32)1U << DMA_HALT_CLEAR)
#define DMA_TSR_DISABLE_HW_REQ_RESET_MASK     ((uint32)1U<<DMA_DISABLE_HW_REQ)
#define DMA_CHCSR_SIT_CLR_MASK                ((uint32)0x87CFBFFFU)
#define DMA_CHCSR_SWB_CLR_MASK                ((uint32)0x8ECFBFFFU)
#define DMA_ADICR_CLR_MASK                    ((uint32)0xFCCF0000U)
#define DMA_TSR_RST_CLR_MASK                  ((uint32)0x0107030EU)
#define DMA_TSR_RST_SET_MASK                  ((uint32)0x00000001U)
#define DMA_MODE_SVMODE_SET_MASK              ((uint32)0x00000001U)

#define DMA_ADICR_INC_SRC_ADD                 (3U)
#define DMA_ADICR_INC_DST_ADD                 (7U)
#define DMA_ADICR_SRC_ADD_OFFSET              (0U)
#define DMA_ADICR_DST_ADD_OFFSET              (4U)
#define DMA_ADICR_SRC_CB_EN                   (20U)
#define DMA_ADICR_DST_CB_EN                   (21U)
#define DMA_ADICR_SRC_CB_LEN                  (8U)
#define DMA_ADICR_DST_CB_LEN                  (12U)
#define DMA_ADICR_SRC_WRP_EN                  (24U)
#define DMA_ADICR_DST_WRP_EN                  (25U)
#define DMA_CHCSR_SIT_EN                      (27U)
#define DMA_CHCSR_SIT_RESET_MASK              (0x00000000U)

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
/*Memory Map of the DMA Code*/
#define DMA_START_SEC_CODE
#include "MemMap.h"

static uint32 Dma_lRemapDsprAddress(const uint32* Address);
static void Dma_lSetXferCount(Dma_ChType Channel, uint16 Tcount);
#if (DMA_DEV_ERROR_DETECT == STD_ON )
/* Functions to check for DET's*/
static Std_ReturnType Dma_lDetCheckUnInit(uint8 ServiceId);
static Std_ReturnType Dma_lDetCheckChannelUnInit(uint8 ServiceId,
                                                            Dma_ChType Channel);
static Std_ReturnType Dma_lDetCheckChannel(uint8 ServiceId,Dma_ChType Channel);
static Std_ReturnType Dma_lDetCheckNullAddr(uint8 ServiceId, const void
                                                                  *AddressPtr);
static Std_ReturnType Dma_lDetCheckTCount(uint8 ServiceId, uint16 TCount);
static Std_ReturnType Dma_lDetCheckMoveEngine(uint8 ServiceId,uint8 MoveEngine);
static Std_ReturnType Dma_lDetCheckMask(uint8 ServiceId, uint32 ClrErrMask);
static Std_ReturnType Dma_lDetCheckHaltMode(uint8 ServiceId,
                                            Dma_ChannelHaltType HaltMode);
static Std_ReturnType Dma_lDetCheckIntrMode(uint8 ServiceId,
                                          Dma_InterruptModeType InterruptMode);
static Std_ReturnType Dma_lDetCheckShadowSettings(uint8 ServiceId, uint8
                                    ShadowControl, const uint32 *ShadowAddrPtr);
#if (DMA_DOUBLE_BUFFER_ENABLE == STD_ON)
static Std_ReturnType Dma_lDetCheckDblBuffMode(uint8 ServiceId,
                                                            Dma_ChType Channel);
#endif
#if (DMA_LINKED_LIST_ENABLE == STD_ON)
static Std_ReturnType Dma_lDetCheckTcsptr(uint8 ServiceId, const
                             Dma_TransactionSetType* TcsPtr, uint32 MaxLLcount);
static Std_ReturnType Dma_lDetCheckExtBufferPtr(uint8 ServiceId, const
                                        Dma_FullTxCtrlSetType *ExtBuffBasePtr);
static Std_ReturnType Dma_lDetCheckLLType(uint8 ServiceId, Dma_ChType Channel);
static Std_ReturnType Dma_lDetCheckLLCount(uint8 ServiceId, uint32
                                                            LinkedListCount);
#endif

#endif /* End of DMA_DEV_ERROR_DETECT */

#if(DMA_RESET_SFR_INIT == STD_ON)
static void Dma_lResetSfr(void);
#endif /* DMA_RESET_SFR_INIT == STD_ON */

#define DMA_STOP_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is 
 allowed only for MemMap.h*/
#include "MemMap.h"
/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
#if (DMA_PB_FIXEDADDR == STD_ON)
#define DMA_START_SEC_CONST_32BIT
/*
 * To be used for global constants (32 bits)
 * Inclusion of MemMap.h
*/
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is 
 allowed only for MemMap.h*/
#include "MemMap.h"

/* To store the Dma driver configuration pointer */
/*IFX_MISRA_RULE_08_07_STATUS=ConfigRoot can not be a local variable*/
static const Dma_ConfigType * const Dma_kConfigPtr = &Dma_ConfigRoot[0];

#define DMA_STOP_SEC_CONST_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is 
 allowed only for MemMap.h*/
#include "MemMap.h"
#endif /* End of DMA_PB_FIXEDADDR */
/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
/*[cover parentID = DS_NAS_DMA_PR115] Global Variables [/cover]*/
#if (DMA_PB_FIXEDADDR == STD_OFF)
#define DMA_START_SEC_VAR_32BIT
/*
 * To be used for 32bit global variables 
 * 
 * Inclusion of MemMap.h
*/
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is 
 allowed only for MemMap.h*/
#include "MemMap.h"
static const Dma_ConfigType *Dma_kConfigPtr;
#define DMA_STOP_SEC_VAR_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is 
 allowed only for MemMap.h*/
#include "MemMap.h"
#endif /* End of DMA_PB_FIXEDADDR */

#define DMA_START_SEC_VAR_8BIT
/*
 * To be used for 8bit global variables
 * Inclusion of MemMap.h
*/
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is 
 allowed only for MemMap.h*/
#include "MemMap.h"
#if ( DMA_DEBUG_SUPPORT == STD_ON )
  /*IFX_MISRA_RULE_08_10_STATUS=Variable Dma_DriverState is declared as
   extern in Dma_Dbg.h, which will be included application for debugging*/
  uint8 Dma_DriverState;
  /*IFX_MISRA_RULE_08_10_STATUS=Variable Dma_ChannelState is declared as
   extern in Dma_Dbg.h, which will be included application for debugging*/
  uint8 Dma_ChannelState[DMA_NUM_OF_CHANNELS];
#else
  static uint8 Dma_DriverState;
  static uint8 Dma_ChannelState[DMA_NUM_OF_CHANNELS];
#endif/* End of DMA_DEBUG_SUPPORT */

#ifdef IFX_DMA_DEBUG
extern volatile uint8 TestDma_Debug;
#endif

#define DMA_STOP_SEC_VAR_8BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is 
 allowed only for MemMap.h*/
#include "MemMap.h"


/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/

/*Memory Map of the DMA Code*/
#define DMA_START_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is 
 allowed only for MemMap.h*/
#include "MemMap.h"
/*******************************************************************************
** Traceability    : [cover parentID=DS_NAS_DMA_PR1786,DS_NAS_DMA_PR915,
                                     DS_NAS_DMA_PR63_8]                       **
**                                                                            **
** Syntax : void Dma_Init(const Dma_ConfigType *ConfigPtr)                    **
**                                                                            **
** Service ID:  0x00                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Reentrant                                                 **
**                                                                            **
** Parameters (in) :  ConfigPtr - Pointer to DMA Driver configuration set     **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description : Initialises the Dma Move Engines                             **
**            This function should be called before calling any other Dma apis**
*******************************************************************************/
void Dma_Init(const Dma_ConfigType *ConfigPtr)
{
  const Dma_ChannelConfigType *lChannelCfgPtr;
  uint8 Channel;
  uint8 ChIndex;
  uint8 DmaChReset;
  /* Check if DET is ON*/
  #if ( DMA_DEV_ERROR_DETECT == STD_ON )

  /*Check if PB Fixed Address is OFF*/
  #if (DMA_PB_FIXEDADDR == STD_OFF)
  /*Report DET if Config Pointer is NULL*/
  if(ConfigPtr == NULL_PTR)
  #else
  /*Report DET if Config Pointer does not match*/
  if(ConfigPtr != Dma_kConfigPtr)
  #endif/* End of DMA_PB_FIXEDADDR */
  {
     /*Report DET on ConfigPtr error*/
     Det_ReportError(DMA_MODULE_ID,DMA_MODULE_INSTANCE,
                    DMA_SID_INIT,DMA_E_PARAM_CONFIG);
  }
  else
  #endif /* End of DMA_DEV_ERROR_DETECT */
  {
    if(Dma_DriverState != DMA_DRIVER_INIT)
    {
      #if (DMA_PB_FIXEDADDR == STD_OFF)
      /*Store the Config Pointer to Global variable*/
      Dma_kConfigPtr = ConfigPtr;
      #endif /* End of DMA_PB_FIXEDADDR  */

#if(DMA_RESET_SFR_INIT == STD_ON)
      Dma_lResetSfr();
#endif /* DMA_RESET_SFR_INIT == STD_ON */

      /*Configure Pattern read register 0 for DMA*/
      DMA_SFR_INIT_WRITE32(MODULE_DMA.PRR0.U,ConfigPtr->DmaPat0);

      /*Configure Pattern read register 1 for DMA*/
      DMA_SFR_INIT_WRITE32(MODULE_DMA.PRR1.U,ConfigPtr->DmaPat1);

      /*Configure error registers of move engine 0 for DMA*/
      DMA_SFR_INIT_WRITE32(MODULE_DMA.BLK0.EER.U,ConfigPtr->DmaMovEng0Err);

      /*Configure error registers of move engine 1 for DMA*/
      DMA_SFR_INIT_WRITE32(MODULE_DMA.BLK1.EER.U,ConfigPtr->DmaMovEng1Err);

      /*Initialize all the channels*/
      for(ChIndex=0U;ChIndex<(ConfigPtr->ChannelsConfigured);ChIndex++)
      {
        /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on 
         ChannelCfgPtr to access the PB Configuration of a particular Channel
         and is within allowed range*/
        lChannelCfgPtr = &(ConfigPtr->ChannelCfgPtr[ChIndex]);
        Channel = lChannelCfgPtr->DmaChannelNumber;
        /*Check channel reset operation, if RST bit is set to 1, then call
        Dma_ErrorCallOut function defined in Dma_Callout.c */

        DmaChReset = (uint8)((DMA_SFR_INIT_USER_MODE_READ32                    \
                        (MODULE_DMA.TSR[Channel].U) >> IFX_DMA_TSR_RST_OFF)    \
                                               & IFX_DMA_TSR_RST_MSK);
        #ifdef IFX_DMA_DEBUG
        DmaChReset |= (TestDma_Debug >> 1U);
        #endif
        if(DmaChReset == 1U)
        {
          Dma_ErrorCallOut(Channel, DMA_CALLOUT_CH_RESET_ERR);
          break;
        }
        else
        {
          /*Configure the channel configuration settings for DMA channel*/
          DMA_SFR_INIT_WRITE32(MODULE_DMA.CH[Channel].CHCFGR.U,                \
                                              lChannelCfgPtr->DmaChannelConfig);

          /*Configure address and interrupt control settings for DMA channel*/
          DMA_SFR_INIT_WRITE32(MODULE_DMA.CH[Channel].ADICR.U,                 \
                                             lChannelCfgPtr->DmaAddrIntControl);

          /*Clear the safety ENDINIT bit in the WDT register in order
           to disable the write-protection for registers protected via
           the safety EndInit feature */
          DMA_SFR_INIT_RESETSAFETYENDINIT(DMA_SAFETY_ENDINT_TIMEOUT);

          /*Configure the hardware resource partition settings for DMA channel*/
          DMA_SFR_INIT_WRITE32(MODULE_DMA.HRR[Channel].U,                      \
                         (uint32)(lChannelCfgPtr->DmaChannelHwPartitionConfig));

          /*Configure the Hardware Resource Supervisor Mode settings */
          DMA_SFR_INIT_WRITE32(MODULE_DMA.MODE                                 \
                              [lChannelCfgPtr->DmaChannelHwPartitionConfig].U, \
                                   (uint32)(lChannelCfgPtr->DmaHwResourceMode));

          /* Set the safety ENDINIT bit in the WDT register again
           to enable the write-protection and to prevent a time-out */
          DMA_SFR_INIT_SETSAFETYENDINIT();

          Dma_ChannelState[Channel] = DMA_DRIVER_CH_INIT;
        }
        if(ChIndex == ((ConfigPtr->ChannelsConfigured) - 1U))
        {
          /*Configure DMA driver state to initialized*/
          Dma_DriverState = DMA_DRIVER_INIT;
        }
      }
    }
  }
}
#if (DMA_DEINIT_API == STD_ON)
/*******************************************************************************
** Traceability    : [cover parentID=DS_NAS_DMA_PR1787,DS_NAS_DMA_PR915,
                                     DS_NAS_DMA_PR63_9]                       **
** Syntax : void Dma_DeInit(void)                                             **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  None                                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  0x01                                                    **
**                                                                            **
** Description : Driver DeInitialization                                      **
**               This function will deinitialize the DMA peripheral           **
*******************************************************************************/
void Dma_DeInit(void)
{
  const Dma_ChannelConfigType *lChannelCfgPtr;
  uint8 Channel;
  uint8 ChIndex;
  if(Dma_DriverState == DMA_DRIVER_INIT)
  {
    /*Configure Pattern read register 0 to default  for DMA*/
    DMA_SFR_DEINIT_WRITE32(MODULE_DMA.PRR0.U,DMA_DEINIT_RESET_VALUE);

    /*Configure Pattern read register 1 to default for DMA*/
    DMA_SFR_DEINIT_WRITE32(MODULE_DMA.PRR1.U,DMA_DEINIT_RESET_VALUE);

    /*Configure error registers of move engine 0 to default for DMA*/
    DMA_SFR_DEINIT_WRITE32(MODULE_DMA.BLK0.EER.U,DMA_DEINIT_BLK_ERR_VALUE);

    /*Configure error registers of move engine 1 to default for DMA*/
    DMA_SFR_DEINIT_WRITE32(MODULE_DMA.BLK1.EER.U,DMA_DEINIT_BLK_ERR_VALUE);

    for(ChIndex=0U;ChIndex <(Dma_kConfigPtr->ChannelsConfigured);ChIndex++)
    {
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on 
       ChannelCfgPtr to access the PB Configuration of a particular Channel
       and is within allowed range*/
      lChannelCfgPtr = &(Dma_kConfigPtr->ChannelCfgPtr[ChIndex]);
      Channel = lChannelCfgPtr->DmaChannelNumber;
      /*If hardware requests are enabled for the DMA channel, then disable
      the DMA channel hardware requests */
      DMA_SFR_DEINIT_MODIFY32(MODULE_DMA.TSR[Channel].U,                       \
             DMA_TSR_HW_DISABLE_REQ_CLR_MASK,DMA_TSR_DISABLE_HW_REQ_RESET_MASK)
      /*Reset Dma channel to make it de initialized.*/
      DMA_SFR_DEINIT_MODIFY32(MODULE_DMA.TSR[Channel].U, DMA_TSR_RST_CLR_MASK  \
                                                     ,DMA_TSR_RST_SET_MASK)
      /*Clear the safety ENDINIT bit in the WDT register in order
        to disable the write-protection for registers protected via
        the safety EndInit feature */

      DMA_SFR_DEINIT_RESETSAFETYENDINIT(DMA_SAFETY_ENDINT_TIMEOUT);

      /*Configure the Hardware Resource Supervisor Mode settings */
      DMA_SFR_DEINIT_WRITE32(MODULE_DMA.MODE[lChannelCfgPtr->                  \
                   DmaChannelHwPartitionConfig].U, DMA_MODE_SVMODE_SET_MASK);

      /*Configure the hardware resource partition settings for DMA channel*/
      DMA_SFR_DEINIT_WRITE32(MODULE_DMA.HRR[Channel].U,DMA_DEINIT_RESET_VALUE);

      /* Set the safety ENDINIT bit in the WDT register again
         to enable the write-protection and to prevent a time-out */
      DMA_SFR_DEINIT_SETSAFETYENDINIT();

      /*Clear the Read data CRC register for DMA*/
      DMA_SFR_DEINIT_WRITE32(MODULE_DMA.CH[Channel].RDCRCR.U,                  \
                                                        DMA_DEINIT_RESET_VALUE);

      /*Clear the Source Destination CRC register for DMA channel*/
      DMA_SFR_DEINIT_WRITE32(MODULE_DMA.CH[Channel].SDCRCR.U,                  \
                                                        DMA_DEINIT_RESET_VALUE);

      /*Clear the Source Address Register for DMA channel*/
      DMA_SFR_DEINIT_WRITE32(MODULE_DMA.CH[Channel].SADR.U,                    \
                                                        DMA_DEINIT_RESET_VALUE);

      /*Clear the Destination Address Register for DMA channel*/
      DMA_SFR_DEINIT_WRITE32(MODULE_DMA.CH[Channel].DADR.U,                    \
                                                       DMA_DEINIT_RESET_VALUE);

      /*Clear the address and interrupt control register for DMA channel*/
      DMA_SFR_DEINIT_WRITE32(MODULE_DMA.CH[Channel].ADICR.U,                   \
                                                       DMA_DEINIT_RESET_VALUE);

      /*Clear the channel configuration register for DMA channel*/
      DMA_SFR_DEINIT_WRITE32(MODULE_DMA.CH[Channel].CHCFGR.U,                  \
                                                        DMA_DEINIT_RESET_VALUE);

      Dma_ChannelState[Channel] = DMA_DRIVER_CH_UNINIT;
    }
    /*Configure DMA state to uninitialized*/
    Dma_DriverState = DMA_DRIVER_UNINIT;
  }
}
#endif /* End of DMA_DEINIT_API */
/*******************************************************************************
** Traceability   : [cover parentID=DS_NAS_DMA_PR1790,DS_NAS_DMA_PR915,
                                    DS_NAS_DMA_PR63_10]                       **
**                                                                            **
** Syntax : Std_ReturnType Dma_StartSwTransaction(Dma_ChType Channel, const   **
**          uint32 *SrcAddressPtr,const uint32 *DestAddressPtr, uint16 TCount)**
**                                                                            **
** Service ID:  0x02                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in) : Channel - Channel ID                                     **
**                   SrcAddressPtr - Source address for read move             **
**                   DestAddressPtr - Destination address for write move      **
**                   TCount - Number of transfers per transaction             **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  E_OK/E_NOT_OK                                           **
**                                                                            **
** Description :  This function starts a transaction with a software trigger  **
**                and will move data as per source and destination address for**
**                TCount number of transfers                                  **
*******************************************************************************/
Std_ReturnType Dma_StartSwTransaction(Dma_ChType Channel, const uint32
                    *SrcAddressPtr, const uint32 *DestAddressPtr, uint16 TCount)
{
  uint32 RemapAddress;
  Std_ReturnType RetVal;

  /* Check for DET's, only if DET is enabled */
  #if ( DMA_DEV_ERROR_DETECT == STD_ON )

  Std_ReturnType ErrorFlag;

    /* Check for DMA Driver is Initialized */
  ErrorFlag = Dma_lDetCheckUnInit(DMA_SID_STARTSWTX);
  if(ErrorFlag == E_OK)
  {
    /* Check for DMA channel is Initialized */
    ErrorFlag = Dma_lDetCheckChannelUnInit(DMA_SID_STARTSWTX,Channel);
    if(ErrorFlag == E_OK)
    {
      /* Check for source address is valid */
      ErrorFlag = Dma_lDetCheckNullAddr(DMA_SID_STARTSWTX,SrcAddressPtr);
      if(ErrorFlag == E_OK)
      {
        /* Check for destination address is valid */
        ErrorFlag = Dma_lDetCheckNullAddr(DMA_SID_STARTSWTX,DestAddressPtr);
        if(ErrorFlag == E_OK)
        {
          /* Check for transafer count is valid */
          ErrorFlag = Dma_lDetCheckTCount(DMA_SID_STARTSWTX,TCount);
        }
      }
    }
  }
  /* If any DET is reported Return value is made E_NOT_OK */

  if(ErrorFlag == E_NOT_OK)
  {
    RetVal = E_NOT_OK;
  }
  else
  #endif /* End of DMA_DEV_ERROR_DETECT */
  {
    /* set source address after remapping it to global address*/
    RemapAddress= Dma_lRemapDsprAddress(SrcAddressPtr);
    DMA_SFR_RUNTIME_WRITE32(MODULE_DMA.CH[Channel].SADR.U, RemapAddress);
    
    /* set destination address after remapping it to global address*/
    RemapAddress= Dma_lRemapDsprAddress(DestAddressPtr);
    DMA_SFR_RUNTIME_WRITE32(MODULE_DMA.CH[Channel].DADR.U, RemapAddress);
    
    /* set transfer count value*/
    Dma_lSetXferCount(Channel, TCount);

    /*give software trigger*/
    DMA_SFR_RUNTIME_MODIFY32(MODULE_DMA.CH[Channel].CHCSR.U,                   \
                                 DMA_CHCSR_SCH_CLR_MASK,DMA_CHCSR_SCH_SET_MASK)
    RetVal = E_OK;
  }
  return RetVal;
}
/*******************************************************************************
** Traceability   : [cover parentID=DS_NAS_DMA_PR1791,DS_NAS_DMA_PR915,
                                    DS_NAS_DMA_PR63_11]                       **
** Syntax : Std_ReturnType Dma_StartHwTransaction(Dma_ChType Channel, const   **
**          uint32 *SrcAddressPtr,const uint32 *DestAddressPtr, uint16 TCount)**
**                                                                            **
** Service ID:  0x03                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in) : Channel - Channel ID                                     **
**                   SrcAddressPtr - Source address for read move             **
**                   DestAddressPtr - Destination address for write move      **
**                   TCount - Number of transfers per transaction             **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
** Description :  This function starts a transaction with a hardware trigger  **
**                and will move data as per source and destination address for**
**                TCount number of transfers                                  **
*******************************************************************************/
Std_ReturnType Dma_StartHwTransaction(Dma_ChType Channel, const uint32
                    *SrcAddressPtr, const uint32 *DestAddressPtr, uint16 TCount)
{
  uint32 RemapAddress;
  Std_ReturnType RetVal;

  /* Check for DET's, only if DET is enabled */
  #if ( DMA_DEV_ERROR_DETECT == STD_ON )

  Std_ReturnType ErrorFlag;

  /* Check for DMA Driver is Initialized */
  ErrorFlag = Dma_lDetCheckUnInit(DMA_SID_STARTHWTX);
  if(ErrorFlag == E_OK)
  {
    /* Check for DMA channel is Initialized */
    ErrorFlag = Dma_lDetCheckChannelUnInit(DMA_SID_STARTHWTX,Channel);
    if(ErrorFlag == E_OK)
    {
      /* Check for source address is valid */
      ErrorFlag = Dma_lDetCheckNullAddr(DMA_SID_STARTHWTX,SrcAddressPtr);
      if(ErrorFlag == E_OK)
      {
        /* Check for destination address is valid */
        ErrorFlag = Dma_lDetCheckNullAddr(DMA_SID_STARTHWTX,DestAddressPtr);
        if(ErrorFlag == E_OK)
        {
          /* Check for transfer count value is invalid */
          ErrorFlag = Dma_lDetCheckTCount(DMA_SID_STARTHWTX,TCount);
        }
      }
    }
  }

  /* If any DET is reported Return value is made E_NOT_OK */
  if(ErrorFlag == E_NOT_OK)
  {
    RetVal = E_NOT_OK;
  }
  else
  #endif /* End of DMA_DEV_ERROR_DETECT */
  {
    /* set source address after remapping it to global address*/
    RemapAddress= Dma_lRemapDsprAddress(SrcAddressPtr);

    DMA_SFR_RUNTIME_WRITE32(MODULE_DMA.CH[Channel].SADR.U, RemapAddress);
    /* set destination address after remapping it to global address*/
    RemapAddress= Dma_lRemapDsprAddress(DestAddressPtr);

    DMA_SFR_RUNTIME_WRITE32(MODULE_DMA.CH[Channel].DADR.U, RemapAddress);

    /* set transfer count value*/
    Dma_lSetXferCount(Channel, TCount);

    /* for hardware transaction request to be enabled, DCH =0 and ECH=1 */
    DMA_SFR_RUNTIME_MODIFY32(MODULE_DMA.TSR[Channel].U,                        \
               DMA_TSR_HW_DISABLE_REQ_CLR_MASK,DMA_TSR_HW_DISABLE_REQ_SET_MASK)
    DMA_SFR_RUNTIME_MODIFY32(MODULE_DMA.TSR[Channel].U,                        \
                         DMA_TSR_HW_TX_REQ_CLR_MASK,DMA_TSR_HW_TX_REQ_SET_MASK)
    RetVal = E_OK;
  }
  return RetVal;
}
/*******************************************************************************
** Traceability   : [cover parentID=DS_NAS_DMA_PR1792,DS_NAS_DMA_PR915,
                                    DS_NAS_DMA_PR63_12]                       **
**                                                                            **
** Syntax : Std_ReturnType Dma_DisableHwTransaction(Dma_ChType Channel)       **
**                                                                            **
** Service ID:  0x04                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in) :  Channel - Channel ID                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  E_OK/E_NOT_OK                                           **
**                                                                            **
** Description : Disables the hardware transaction mode                       **
*******************************************************************************/
Std_ReturnType Dma_DisableHwTransaction(Dma_ChType Channel)
{
  Std_ReturnType RetVal;

  /* Check for DET's, only if DET is enabled */
  #if ( DMA_DEV_ERROR_DETECT == STD_ON )
  Std_ReturnType ErrorFlag;
  /* Check for DMA Driver is Initialized */
  ErrorFlag = Dma_lDetCheckUnInit(DMA_SID_DISABLEHWTX);
  if(ErrorFlag == E_OK)
  {
    /* Check for DMA channel is Initialized */
    ErrorFlag = Dma_lDetCheckChannelUnInit(DMA_SID_DISABLEHWTX,Channel);
  }
  /* If any DET is reported Return value is made E_NOT_OK */
  if(ErrorFlag == E_NOT_OK)
  {
    RetVal = E_NOT_OK;
  }
  else
  #endif /* End of DMA_DEV_ERROR_DETECT */
  {
    /*Disable hardware request for given channel*/
    DMA_SFR_RUNTIME_MODIFY32(MODULE_DMA.TSR[Channel].U,                        \
             DMA_TSR_HW_DISABLE_REQ_CLR_MASK,DMA_TSR_DISABLE_HW_REQ_RESET_MASK)
    RetVal = E_OK;
  }
  return RetVal;
}
/*******************************************************************************
** Traceability   : [cover parentID=DS_NAS_DMA_PR1793,DS_NAS_DMA_PR915,
                                    DS_NAS_DMA_PR63_13]                       **
** Syntax :Dma_ChannelStatusType Dma_GetChannelStatus(Dma_ChType Channel)     **
**                                                                            **
** Service ID:  0x05                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in) :  Channel - Channel ID                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  Dma_ChannelStatusType                                   **
**                                                                            **
** Description :  Returns a structure of type Dma_ChannelStatusType with      **
**                following bitfields:                                        **
**                DmaPending: indicates channel is active/idle                **
**                DmaIntDetected: indicates interrupt from channel has been   **
**                                 detected depending on Interrupt settings   **
**                DmaPatternMatch: indicates a pattern match has been detected**
**                DmaHaltAck: Status of halt acknowledge bit                  **
**                DmaTxReqLost: transaction request lost bit status           **
**                DmaHwReqOn: indicates whether hardware request bit is on    **
**                DmaCurrBuffer: indicates active buffer is buffer0/buffer1   **
**                DmaFrozenBuffER:indicates one of a double buffer is frozen  **
**                DmaInvalidStatus:In case of DETs                            **
*******************************************************************************/
Dma_ChannelStatusType Dma_GetChannelStatus(Dma_ChType Channel)
{
  Dma_ChannelStatusType ChStatusStruct;

  /* Check for DET's, only if DET is enabled */
  #if ( DMA_DEV_ERROR_DETECT == STD_ON )
  Std_ReturnType ErrorFlag;

  /* Check for DMA Driver is Initialized */
  ErrorFlag = Dma_lDetCheckUnInit(DMA_SID_GETCHSTATUS);
  if(ErrorFlag == E_OK)
  {
    /* Check for DMA channel is Initialized */
    ErrorFlag = Dma_lDetCheckChannelUnInit(DMA_SID_GETCHSTATUS,Channel);
  }
  /* If any DET is reported,then DmaInvalidStatus bit of returning structure is
     made as 1  */
  if(ErrorFlag == E_NOT_OK)
  {
    ChStatusStruct.DmaInvalidStatus =1U;
  }
  else
  #endif /* End of DMA_DEV_ERROR_DETECT */
  {
    /*Get DMA request pending status for the channel*/
    ChStatusStruct.DmaPending = (uint8)((DMA_SFR_RUNTIME_USER_MODE_READ32      \
                          (MODULE_DMA.TSR[Channel].U) >>  IFX_DMA_TSR_CH_OFF)  \
                                                & IFX_DMA_TSR_CH_MSK);
    /*Get hardware request enable/disable state for the channel*/
  
    ChStatusStruct.DmaHwReqOn = (uint8)((DMA_SFR_RUNTIME_USER_MODE_READ32      \
                     (MODULE_DMA.TSR[Channel].U) >> IFX_DMA_TSR_HTRE_OFF)      \
                                              & IFX_DMA_TSR_HTRE_MSK);
    /*Get transaction/transfer request lost event status for the channel*/
    ChStatusStruct.DmaTxReqLost = (uint8)((DMA_SFR_RUNTIME_USER_MODE_READ32    \
    (MODULE_DMA.TSR[Channel].U) >> IFX_DMA_TSR_TRL_OFF)                        \
                                                & IFX_DMA_TSR_TRL_MSK);
    /*Get halt acknowledge status for the channel*/
    ChStatusStruct.DmaHaltAck = (uint8)((DMA_SFR_RUNTIME_USER_MODE_READ32      \
    (MODULE_DMA.TSR[Channel].U) >> IFX_DMA_TSR_HLTACK_OFF)                     \
                                              & IFX_DMA_TSR_HLTACK_MSK);
    /*Get pattern detection status for the channel*/
    ChStatusStruct.DmaPatternMatch = (uint8)((DMA_SFR_RUNTIME_USER_MODE_READ32 \
    (MODULE_DMA.CH[Channel].CHCSR.U) >> IFX_DMA_CH_CHCSR_IPM_OFF)              \
                                           & IFX_DMA_CH_CHCSR_IPM_MSK);
    /*Get interrupt detection status for the channel*/
    ChStatusStruct.DmaIntDetected = (uint8)((DMA_SFR_RUNTIME_USER_MODE_READ32  \
    (MODULE_DMA.CH[Channel].CHCSR.U) >> IFX_DMA_CH_CHCSR_ICH_OFF)              \
                                           & IFX_DMA_CH_CHCSR_ICH_MSK);
    /*Get information about which buffer is active for the channel
      Note: This bit is active during DMA double buffering operation*/
    ChStatusStruct.DmaCurrBuffer = (uint8)((DMA_SFR_RUNTIME_USER_MODE_READ32   \
     (MODULE_DMA.CH[Channel].CHCSR.U) >> IFX_DMA_CH_CHCSR_BUFFER_OFF)          \
                                       & IFX_DMA_CH_CHCSR_BUFFER_MSK);
    /*It shows which buffer is frozen and available for cyclic software task
      Note: This bit is active during DMA double buffering operation*/
    ChStatusStruct.DmaFrozenBuff = (uint8)((DMA_SFR_RUNTIME_USER_MODE_READ32   \
    (MODULE_DMA.CH[Channel].CHCSR.U) >> IFX_DMA_CH_CHCSR_FROZEN_OFF)           \
                                      & IFX_DMA_CH_CHCSR_FROZEN_MSK);
    /*Reset DmaInvalidStatus bit of returning structure to 0 indicating no DET*/
    ChStatusStruct.DmaInvalidStatus =0U;
  }
  return ChStatusStruct;
}
/*******************************************************************************
** Traceability   : [cover parentID=DS_NAS_DMA_PR1794,DS_NAS_DMA_PR915,
                                    DS_NAS_DMA_PR63_14]                       **
**                                                                            **
** Syntax : Dma_ErrorType Dma_GetMoveEngineErrFlags(uint8 MoveEngine)         **
**                                                                            **
** Service ID:  0x06                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in) :  MoveEngine - Move Engine ID                             **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : Dma_ErrorType                                            **
**                                                                            **
** Description :  Returns a structure of type Dma_ErrorType with following    **
**                bitfields:                                                  **
**                DmaMovEngSrcErr: Holds Move engine source error flag        **
**                DmaMovEngDestErr: Holds Move engine destination error flag  **
**                DmaMovEngSpbErr:  Holds Move engine SPB error flag          **
**                DmaMovEngSriErr:  Holds Move engine SRI error flag          **
**                DmaMovEngRamErr:  Holds Move engine RAM error flag          **
**                DmaMovEngSafeLinkListErr: Holds Move engine Safe linkedlist **
**                                          error flag                        **
**                DmaMovEngLinkListErr:Holds Move engine linkedlist error flag**
**                DmaMovEngInvalidErr:  This bit is set if some DET occurs.   **
*******************************************************************************/
Dma_ErrorType Dma_GetMoveEngineErrFlags(uint8 MoveEngine)
{
  Dma_ErrorType MovEngErrStruct;
  /* Check for DET's, only if DET is enabled */
  #if ( DMA_DEV_ERROR_DETECT == STD_ON )
  Std_ReturnType ErrorFlag;
  /* Check for DMA Driver is Initialized */
  ErrorFlag = Dma_lDetCheckUnInit(DMA_SID_GETMEERRFLAGS);
  if(ErrorFlag == E_OK)
  {
    /* Check for DMA move engine number is valid */
    ErrorFlag = Dma_lDetCheckMoveEngine(DMA_SID_GETMEERRFLAGS,MoveEngine);
  }
  /* If any DET is reported,then DmaMovEngInvalidErr bit of returning structure
     is made as 1  */
  if(ErrorFlag == E_NOT_OK)
  {
    MovEngErrStruct.DmaMovEngInvalidErr =1U;
  }
  else
  #endif /* End of DMA_DEV_ERROR_DETECT */
  {
    if (MoveEngine==0U)
    {
      /*Get Move engine 0 source error flag value */
      MovEngErrStruct.DmaMovEngSrcErr = (uint8)                                \
               ((DMA_SFR_RUNTIME_USER_MODE_READ32(MODULE_DMA.BLK0.ERRSR.U) >>  \
            IFX_DMA_BLK_ERRSR_SER_OFF) & IFX_DMA_BLK_ERRSR_SER_MSK);
      /*Get Move engine 0 destination error flag value */
      MovEngErrStruct.DmaMovEngDestErr = (uint8)
               ((DMA_SFR_RUNTIME_USER_MODE_READ32(MODULE_DMA.BLK0.ERRSR.U) >>  \
            IFX_DMA_BLK_ERRSR_DER_OFF) & IFX_DMA_BLK_ERRSR_DER_MSK);
      /*Get Move engine 0 SPB bus error flag value */
      MovEngErrStruct.DmaMovEngSpbErr =(uint8)                                 \
               ((DMA_SFR_RUNTIME_USER_MODE_READ32(MODULE_DMA.BLK0.ERRSR.U) >>  \
        IFX_DMA_BLK_ERRSR_SPBER_OFF) & IFX_DMA_BLK_ERRSR_SPBER_MSK);
      /*Get Move engine 0 SRI bus error flag value */
      MovEngErrStruct.DmaMovEngSriErr = (uint8)                                \
               ((DMA_SFR_RUNTIME_USER_MODE_READ32(MODULE_DMA.BLK0.ERRSR.U) >>  \
        IFX_DMA_BLK_ERRSR_SRIER_OFF) & IFX_DMA_BLK_ERRSR_SRIER_MSK);
      /*Get RAM error flag value that occurs during the loading of a transaction
       control set from DMARAM to the DMA sub-block-0 channel registers */
       MovEngErrStruct.DmaMovEngRamErr = (uint8)                               \
               ((DMA_SFR_RUNTIME_USER_MODE_READ32(MODULE_DMA.BLK0.ERRSR.U) >>  \
       IFX_DMA_BLK_ERRSR_RAMER_OFF) & IFX_DMA_BLK_ERRSR_RAMER_MSK);
      /*Get safe linked list error flag value that occurs during SDCRC checksum
      comparison for move engine 0*/
      MovEngErrStruct.DmaMovEngSafeLinkListErr = (uint8)                       \
               ((DMA_SFR_RUNTIME_USER_MODE_READ32(MODULE_DMA.BLK0.ERRSR.U) >>  \
       IFX_DMA_BLK_ERRSR_SLLER_OFF) & IFX_DMA_BLK_ERRSR_SLLER_MSK);
      /*Get DMA Linked List Error flag value that occurs during the loading of a
       new transaction control set from anywhere in memory to overwrite the
       current transaction control set stored in the DMARAM for move engine 0 */
        MovEngErrStruct.DmaMovEngLinkListErr = (uint8)                         \
               ((DMA_SFR_RUNTIME_USER_MODE_READ32(MODULE_DMA.BLK0.ERRSR.U) >>  \
       IFX_DMA_BLK_ERRSR_DLLER_OFF) & IFX_DMA_BLK_ERRSR_DLLER_MSK);
    }
    else
    {
      /*Get Move engine 1 source error flag value */
      MovEngErrStruct.DmaMovEngSrcErr = (uint8)                                \
               ((DMA_SFR_RUNTIME_USER_MODE_READ32(MODULE_DMA.BLK1.ERRSR.U) >>  \
             IFX_DMA_BLK_ERRSR_SER_OFF) & IFX_DMA_BLK_ERRSR_SER_MSK);
      /*Get Move engine 1 destination error flag value */
      MovEngErrStruct.DmaMovEngDestErr = (uint8)                               \
               ((DMA_SFR_RUNTIME_USER_MODE_READ32(MODULE_DMA.BLK1.ERRSR.U) >>  \
             IFX_DMA_BLK_ERRSR_DER_OFF) & IFX_DMA_BLK_ERRSR_DER_MSK);
      /*Get Move engine 1 SPB bus error flag value */
      MovEngErrStruct.DmaMovEngSpbErr = (uint8)                                \
               ((DMA_SFR_RUNTIME_USER_MODE_READ32(MODULE_DMA.BLK1.ERRSR.U) >>  \
         IFX_DMA_BLK_ERRSR_SPBER_OFF) & IFX_DMA_BLK_ERRSR_SPBER_MSK);
      /*Get Move engine 1 SRI bus error flag value */
      MovEngErrStruct.DmaMovEngSriErr = (uint8)                                \
               ((DMA_SFR_RUNTIME_USER_MODE_READ32(MODULE_DMA.BLK1.ERRSR.U) >>  \
        IFX_DMA_BLK_ERRSR_SRIER_OFF) & IFX_DMA_BLK_ERRSR_SRIER_MSK);
      /*Get RAM error flag value that occurs during the loading of a transaction
       control set from DMARAM to the DMA sub-block-1 channel registers */
      MovEngErrStruct.DmaMovEngRamErr = (uint8)                                \
               ((DMA_SFR_RUNTIME_USER_MODE_READ32(MODULE_DMA.BLK1.ERRSR.U) >>  \
         IFX_DMA_BLK_ERRSR_RAMER_OFF) & IFX_DMA_BLK_ERRSR_RAMER_MSK);
      /*Get safe linked list error flag value that occurs during SDCRC checksum
      comparison for move engine 1*/
      MovEngErrStruct.DmaMovEngSafeLinkListErr = (uint8)                       \
               ((DMA_SFR_RUNTIME_USER_MODE_READ32(MODULE_DMA.BLK1.ERRSR.U) >>  \
         IFX_DMA_BLK_ERRSR_SLLER_OFF) & IFX_DMA_BLK_ERRSR_SLLER_MSK);
      /*Get DMA Linked List Error flag value that occurs during the loading of a
       new transaction control set from anywhere in memory to overwrite the
       current transaction control set stored in the DMARAM for move engine 1 */
       MovEngErrStruct.DmaMovEngLinkListErr = (uint8)                          \
               ((DMA_SFR_RUNTIME_USER_MODE_READ32(MODULE_DMA.BLK1.ERRSR.U) >>  \
        IFX_DMA_BLK_ERRSR_DLLER_OFF) & IFX_DMA_BLK_ERRSR_DLLER_MSK);
    }
    /*Reset DmaMovEngInvalidErr bitfield to 0 indicating no DET condition*/
    MovEngErrStruct.DmaMovEngInvalidErr =0U;
  }
  return MovEngErrStruct;
}
/*******************************************************************************
** Traceability   : [cover parentID=DS_NAS_DMA_PR1795,DS_NAS_DMA_PR915,
                                    DS_NAS_DMA_PR63_26]                       **
**                                                                            **
** Syntax: Std_ReturnType Dma_ClearMoveEngineErrFlags(uint8 MoveEngine,       **
**                                                        uint32 ClrErrMask)  **
** Service ID:  0x07                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in) :  MoveEngine - Move Engine ID                             **
**                    ClrErrMask - Error mask                                 **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  E_OK/E_NOT_OK                                           **
**                                                                            **
** Description :  clears error flags related to move engine as per the mask   **
*******************************************************************************/
Std_ReturnType Dma_ClearMoveEngineErrFlags (uint8 MoveEngine, uint32 ClrErrMask)
{
  Std_ReturnType RetVal;

  /* Check for DET's, only if DET is enabled */
  #if ( DMA_DEV_ERROR_DETECT == STD_ON )
  Std_ReturnType ErrorFlag;
  /* Check for DMA Driver is Initialized */
  ErrorFlag = Dma_lDetCheckUnInit(DMA_SID_CLRMEERRFLAGS);
  if(ErrorFlag == E_OK)
  {
     /* Check for DMA move engine number is valid */
     ErrorFlag = Dma_lDetCheckMoveEngine(DMA_SID_CLRMEERRFLAGS,MoveEngine);
     if(ErrorFlag == E_OK)
     {
       /* Check for DMA channel is Initialized */
       ErrorFlag = Dma_lDetCheckMask(DMA_SID_CLRMEERRFLAGS,ClrErrMask);
     }
  }
  /* If any DET is reported Return value is made E_NOT_OK */
  if(ErrorFlag == E_NOT_OK)
  {
    RetVal = E_NOT_OK;
  }
  else
  #endif /* End of DMA_DEV_ERROR_DETECT */
  {
    if( MoveEngine == 0U)
    {
      /*write appropriate mask value to clear error register of move engine 0*/
      DMA_SFR_RUNTIME_WRITE32(MODULE_DMA.BLK0.CLRE.U,ClrErrMask);
    }
    else
    {
      /*write appropriate mask value to clear error register of move engine 1*/
      DMA_SFR_RUNTIME_WRITE32(MODULE_DMA.BLK1.CLRE.U,ClrErrMask);
    }
    RetVal = E_OK;
  }
  return RetVal;
}
/*******************************************************************************
** Traceability   : [cover parentID=DS_NAS_DMA_PR1796,DS_NAS_DMA_PR915,
                                    DS_NAS_DMA_PR63_15]                       **
**                                                                            **
** Syntax : Std_ReturnType Dma_ClearInterruptStatus(Dma_ChType Channel)       **
**                                                                            **
** Service ID:  0x08                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in) :  Channel - Channel ID                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  E_OK/E_NOT_OK                                           **
**                                                                            **
** Description : Clears interrupt related flags for the channel               **
*******************************************************************************/
Std_ReturnType Dma_ClearInterruptStatus(Dma_ChType Channel)
{
  Std_ReturnType RetVal;
  
  /* Check for DET's, only if DET is enabled */
  #if ( DMA_DEV_ERROR_DETECT == STD_ON )
  Std_ReturnType ErrorFlag;
  /* Check for DMA Driver is Initialized */
  ErrorFlag = Dma_lDetCheckUnInit(DMA_SID_CLRINTERRUPTS);

  if(ErrorFlag == E_OK)
  {
    /* Check for DMA channel is Initialized */
    ErrorFlag = Dma_lDetCheckChannelUnInit(DMA_SID_CLRINTERRUPTS,Channel);
  }
  /* If any DET is reported Return value is made E_NOT_OK */
  if(ErrorFlag == E_NOT_OK)
  {
    RetVal = E_NOT_OK;
  }
  else
  #endif /* End of DMA_DEV_ERROR_DETECT */
  {
    /*clear wrap buffer interrupt flags for source and destination and clear
    channel interrupt flags ICH,IPM*/
    DMA_SFR_RUNTIME_MODIFY32(MODULE_DMA.CH[Channel].CHCSR.U,                   \
                       DMA_CHCSR_INTFLAGS_CLR_MASK,DMA_CHCSR_INTFLAGS_SET_MASK)
    /*clear channel transaction request lost flag (TRL)*/
    DMA_SFR_RUNTIME_MODIFY32(MODULE_DMA.TSR[Channel].U,                        \
                           DMA_TSR_INTFLAGS_CLR_MASK,DMA_TSR_INTFLAGS_SET_MASK)
    RetVal = E_OK;
  }
  return RetVal;
}
/*******************************************************************************
** Traceability   : [cover parentID=DS_NAS_DMA_PR1797,DS_NAS_DMA_PR915,
                                    DS_NAS_DMA_PR63_16]                       **
**                                                                            **
** Syntax : uint16 Dma_GetTransferCount(Dma_ChType Channel)                   **
**                                                                            **
** Service ID:  0x09                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in) :  Channel - Channel ID                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  uint16                                                  **
**                                                                            **
** Description : returns the number of transfers remaining for the channel    **
**               In case of DET it returns 0xFFFF                             **
*******************************************************************************/
uint16 Dma_GetTransferCount(Dma_ChType Channel)
{
  uint16 RetCount;
  /* Check for DET's, only if DET is enabled */
  #if ( DMA_DEV_ERROR_DETECT == STD_ON )
  Std_ReturnType ErrorFlag;
  /* Check for DMA Driver is Initialized */
  ErrorFlag = Dma_lDetCheckUnInit(DMA_SID_GETTCOUNT);
  if(ErrorFlag == E_OK)
  {
    /* Check for DMA channel is Initialized */
    ErrorFlag = Dma_lDetCheckChannelUnInit(DMA_SID_GETTCOUNT,Channel);
  }
  /* If any DET is reported,then return value RetCount is made as 0xFFFF */
  if(ErrorFlag == E_NOT_OK)
  {
    RetCount = DMA_16_BIT_MAX_VALUE;
  }
  else
  #endif /* End of DMA_DEV_ERROR_DETECT */
  {
    /*Update remaining transfer count value */
    RetCount = (uint16)((DMA_SFR_RUNTIME_USER_MODE_READ32                      \
         (MODULE_DMA.CH[Channel].CHCSR.U) >> IFX_DMA_CH_CHCSR_TCOUNT_OFF)      \
                                       & IFX_DMA_CH_CHCSR_TCOUNT_MSK);
  }
  return RetCount;
}
/*******************************************************************************
** Traceability   : [cover parentID=DS_NAS_DMA_PR1801,DS_NAS_DMA_PR915,
                                    DS_NAS_DMA_PR63_19]                       **
**                                                                            **
** Syntax : Std_ReturnType Dma_ConfigHaltChannel(Dma_ChType Channel,          **
**                                          Dma_ChannelHaltType HaltMode)     **
**                                                                            **
** Service ID:  0x0A                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in) :  Channel - Channel ID                                    **
**                HaltMode- Halt ON/OFF mode                                  **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  E_OK/E_NOT_OK                                           **
**                                                                            **
** Description : Service for configuring halt mode of a DMA channel           **
*******************************************************************************/
Std_ReturnType Dma_ConfigHaltChannel(Dma_ChType Channel,Dma_ChannelHaltType
                                                                       HaltMode)
{
  Std_ReturnType RetVal;
  uint8 TsrHltAck;
  /* Check for DET's, only if DET is enabled */
  #if ( DMA_DEV_ERROR_DETECT == STD_ON )

  Std_ReturnType ErrorFlag;

  /* Check for DMA Driver is Initialized */
  ErrorFlag = Dma_lDetCheckUnInit(DMA_SID_CONFIGHALTCH);
  if(ErrorFlag == E_OK)
  {
    /* Check for DMA channel is Initialized */
    ErrorFlag = Dma_lDetCheckChannelUnInit(DMA_SID_CONFIGHALTCH,Channel);
    if(ErrorFlag == E_OK)
    {
      /* Check for halt mode is valid */
      ErrorFlag = Dma_lDetCheckHaltMode(DMA_SID_CONFIGHALTCH,HaltMode);
    }
  }
  /* If any DET is reported Return value is made E_NOT_OK */
  if(ErrorFlag == E_NOT_OK)
  {
    RetVal = E_NOT_OK;
  }
  else
  #endif /* End of DMA_DEV_ERROR_DETECT */
  {
    /* read TSR_HLTACK bit to check channel is already in Halt state or not */
    TsrHltAck = (uint8)((DMA_SFR_RUNTIME_USER_MODE_READ32                      \
                      (MODULE_DMA.TSR[Channel].U) >> IFX_DMA_TSR_HLTACK_OFF)   \
                                           & IFX_DMA_TSR_HLTACK_MSK);
    if(HaltMode == DMA_HALT_ON)
    {
      /*Check if channel is already in Halt state*/
      if((TsrHltAck != 1U))
      {
        /* Set halt request to put channel on Halt mode */
        DMA_SFR_RUNTIME_MODIFY32(MODULE_DMA.TSR[Channel].U,                    \
                          DMA_DMA_HALT_REQ_CLR_MASK,DMA_DMA_HALT_REQ_SET_MASK)
      }
    }
    else
    {
      /*Check if channel is already in Halt state*/
      if((TsrHltAck == 1U))
      {
        /* Set HLTCLR bit to clear channel Halt mode */
        DMA_SFR_RUNTIME_MODIFY32(MODULE_DMA.TSR[Channel].U,                    \
                       DMA_DMA_HALT_CLEAR_CLR_MASK,DMA_DMA_HALT_CLEAR_SET_MASK)
      }
    }
    RetVal = E_OK;
  }
  return RetVal;
}
/*******************************************************************************
** Traceability   : [cover parentID=DS_NAS_DMA_PR1802,DS_NAS_DMA_PR915,
                                    DS_NAS_DMA_PR63_20]                       **
**                                                                            **
** Syntax : Std_ReturnType Dma_ConfigChannelInterrupt(Dma_ChType Channel,     **
**                                        Dma_InterruptModeType InterruptMode)**
**                                                                            **
** Service ID:  0x0B                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in) :  Channel - Channel ID                                    **
**                    InterruptMode- Interrupt ON/OFF mode                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  E_OK/E_NOT_OK                                           **
**                                                                            **
** Description : API Service for configuring interrupt mode of a DMA channel  **
*******************************************************************************/
Std_ReturnType Dma_ConfigChannelInterrupt(Dma_ChType Channel,
                          Dma_InterruptModeType InterruptMode)
{
  Std_ReturnType RetVal;

  /* Check for DET's, only if DET is enabled */
  #if ( DMA_DEV_ERROR_DETECT == STD_ON )

  Std_ReturnType ErrorFlag;
    /* Check for DMA Driver is Initialized */
  ErrorFlag = Dma_lDetCheckUnInit(DMA_SID_CONFIGCHINTR);
  if(ErrorFlag == E_OK)
  {
    /* Check for DMA channel is Initialized */
    ErrorFlag = Dma_lDetCheckChannelUnInit(DMA_SID_CONFIGCHINTR,Channel);
    if(ErrorFlag == E_OK)
    {
      /* Check for interrupt mode is valid */
      ErrorFlag = Dma_lDetCheckIntrMode(DMA_SID_CONFIGCHINTR,InterruptMode);
    }
  }
  /* If any DET is reported Return value is made E_NOT_OK */
  if(ErrorFlag == E_NOT_OK)
  {
    RetVal = E_NOT_OK;
  }
  else
  #endif /* End of DMA_DEV_ERROR_DETECT */
  {
    if (InterruptMode == DMA_CH_INT_ON)
    {
      /*Activate channel interrupt trigger*/
      DMA_SFR_RUNTIME_MODIFY32(MODULE_DMA.CH[Channel].CHCSR.U,                 \
                                 DMA_CHCSR_SIT_CLR_MASK,DMA_CHCSR_SIT_SET_MASK)
    }
    else
    {
      /*Interrupt trigger for channel will not be activated*/
      DMA_SFR_RUNTIME_MODIFY32(MODULE_DMA.CH[Channel].CHCSR.U,                 \
                               DMA_CHCSR_SIT_CLR_MASK,DMA_CHCSR_SIT_RESET_MASK)
    }
    RetVal = E_OK;
  }
  return RetVal;
}
/*******************************************************************************
** Traceability  :[cover parentID=DS_NAS_DMA_PR1798,DS_NAS_DMA_PR915,
                                  DS_NAS_DMA_PR63_21]                         **
**                                                                            **
** Syntax : Std_ReturnType Dma_ConfigShadowAddress(Dma_ChType Channel, const  **
**                                                uint32 *ShadowAddrPtr)      **
** Service ID:  0x11                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in) :  Channel - Channel ID                                    **
**                    ShadowAddrPtr: Contains address to be put in shadow     **
**                                   register.                                **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  E_OK/E_NOT_OK                                           **
**                                                                            **
** Description : This API is used configure channel shadow register for a     **
**               particular operation                                         **
*******************************************************************************/
Std_ReturnType Dma_ConfigShadowAddress(Dma_ChType Channel,const uint32
                                                                *ShadowAddrPtr)
{
  uint32 RemapAddress;
  volatile uint8 ShadowControl;
  Std_ReturnType RetVal;
  /* Check for DET's, only if DET is enabled */
  #if ( DMA_DEV_ERROR_DETECT == STD_ON )

  Std_ReturnType ErrorFlag;
  /* Check for DMA Driver is Initialized */
  ErrorFlag = Dma_lDetCheckUnInit(DMA_SID_CONFIGSHADOW);
  if(ErrorFlag == E_OK)
  {
    /* Check for DMA channel is Initialized */
    ErrorFlag = Dma_lDetCheckChannelUnInit(DMA_SID_CONFIGSHADOW,Channel);
    if(ErrorFlag == E_OK)
    {

      ShadowControl = (uint8)((DMA_SFR_RUNTIME_USER_MODE_READ32                \
      (MODULE_DMA.CH[Channel].ADICR.U) >> IFX_DMA_BLK_ME_ADICR_SHCT_OFF)       \
                                      & IFX_DMA_BLK_ME_ADICR_SHCT_MSK);
      /* Check if shadow control value is valid */
      ErrorFlag=Dma_lDetCheckShadowSettings(DMA_SID_CONFIGSHADOW, ShadowControl,
                                                                 ShadowAddrPtr);
    }
  }
  /* If any DET is reported Return value is made E_NOT_OK */
  if(ErrorFlag == E_NOT_OK)
  {
    RetVal = E_NOT_OK;
  }
  else
  #endif /* End of DMA_DEV_ERROR_DETECT */
  {
    ShadowControl = (uint8)((DMA_SFR_RUNTIME_USER_MODE_READ32                  \
    (MODULE_DMA.CH[Channel].ADICR.U) >> IFX_DMA_BLK_ME_ADICR_SHCT_OFF)         \
                                    & IFX_DMA_BLK_ME_ADICR_SHCT_MSK);
    if(ShadowControl > 2U)
    {
      /*configure shadow address register*/
      RemapAddress= Dma_lRemapDsprAddress(ShadowAddrPtr);

      DMA_SFR_RUNTIME_WRITE32(MODULE_DMA.CH[Channel].SHADR.U,RemapAddress);

      RetVal = E_OK;
    }
    else
    {
      /*
      As this situation corresponds to Read only source/destination
      buffering (single), and channel shadow address register isn't directly
      writable.
      */
      RetVal = E_NOT_OK;
    }
  }
  return RetVal;
}
#if (DMA_DOUBLE_BUFFER_ENABLE == STD_ON)
/*******************************************************************************
** Traceability   : [cover parentID=DS_NAS_DMA_PR1799,DS_NAS_DMA_PR915,
                                    DS_NAS_DMA_PR63_22]                       **
**                                                                            **
** Syntax : Std_ReturnType Dma_SwitchBuffer(Dma_ChType Channel)               **
**                                                                            **
** Service ID:  0x0C                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in) :  Channel - Channel ID                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  E_OK/E_NOT_OK                                           **
**                                                                            **
** Description : This API is used to switch buffers provided double buffering **
**               mode is ON                                                   **
*******************************************************************************/
Std_ReturnType Dma_SwitchBuffer(Dma_ChType Channel)
{
  Std_ReturnType RetVal;

  /* Check for DET's, only if DET is enabled */
  #if ( DMA_DEV_ERROR_DETECT == STD_ON )

  Std_ReturnType ErrorFlag;
  /* Check for DMA Driver is Initialized */
  ErrorFlag = Dma_lDetCheckUnInit(DMA_SID_SWITCHBUFFER);
  if(ErrorFlag == E_OK)
  {
    /* Check for DMA channel is Initialized */
    ErrorFlag = Dma_lDetCheckChannelUnInit(DMA_SID_SWITCHBUFFER,Channel);
    if(ErrorFlag == E_OK)
    {
      /* Check if shadow address is configured for double buffer mode */
      ErrorFlag=Dma_lDetCheckDblBuffMode(DMA_SID_SWITCHBUFFER,Channel);
    }
  }
  /* If any DET is reported Return value is made E_NOT_OK */
  if(ErrorFlag == E_NOT_OK)
  {
    RetVal = E_NOT_OK;
  }
  else
  #endif /* End of DMA_DEV_ERROR_DETECT */
  {
    /*Switch buffer*/
    DMA_SFR_RUNTIME_MODIFY32(MODULE_DMA.CH[Channel].CHCSR.U,                   \
                                 DMA_CHCSR_SWB_CLR_MASK,DMA_CHCSR_SWB_SET_MASK)

    RetVal = E_OK;
  }
  return RetVal;
}
#endif /* End of DMA_DOUBLE_BUFFER_ENABLE */

#if (DMA_LINKED_LIST_ENABLE == STD_ON)
/*******************************************************************************
** Traceability   : [cover parentID=DS_NAS_DMA_PR1800,DS_NAS_DMA_PR915,
                                    DS_NAS_DMA_PR63_23]                       **
**                                                                            **
** Syntax : Std_ReturnType Dma_ConfigChannelLinkList (Dma_ChType Channel,     **
**               const Dma_TransactionSetType *TcsPtr, Dma_FullTxCtrlSetType  **
**                   *ExtBuffBasePtr, uint32 LinkedListCount)                 **
**                                                                            **
** Service ID:  0x0D                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in) :Channel - Channel ID                                      **
**                TcsPtr - Pointer to a structure that will contain source    **
**                         address, CRC values, destination address and       **
**                         transfer count.                                    **
**                LinkedListCount - Total number of transactions to be made   **
**                ExtBuffBasePtr  - Pointer to 32 byte aligned array of       **
**                                  structure of type Dma_FullTxCtrlSetType   **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  E_OK/E_NOT_OK                                           **
**                                                                            **
** Description : This API is used to trigger a transaction in linkedlist style**
*******************************************************************************/
Std_ReturnType Dma_ConfigChannelLinkList (Dma_ChType Channel, const
                           Dma_TransactionSetType *TcsPtr,Dma_FullTxCtrlSetType
                           *ExtBuffBasePtr, uint32 LinkedListCount)
{
  /* Store the current base pointer of 32 byte transaction control set */
  const Dma_FullTxCtrlSetType *FixedExtBuffBasePtr=ExtBuffBasePtr;
  Dma_FullTxCtrlSetType *NextTcsPtr=ExtBuffBasePtr;
  Std_ReturnType RetVal;
  uint32 ReadDataCRC=0U;
  uint32 AddrCtrlReg;
  uint32 ChConfigReg;
  uint32 ChStatusReg;
  uint32 LoopCtr;
  uint32 RegSetMask;

   /* Check for DET's, only if DET is enabled */
  #if ( DMA_DEV_ERROR_DETECT == STD_ON )

  Std_ReturnType ErrorFlag;
  /* Check for DMA Driver is Initialized */
  ErrorFlag = Dma_lDetCheckUnInit(DMA_SID_CONFIGCHLINKLIST);
  if(ErrorFlag == E_OK)
  {
    /* Check for DMA channel is Initialized */
    ErrorFlag = Dma_lDetCheckChannelUnInit(DMA_SID_CONFIGCHLINKLIST,Channel);
    if(ErrorFlag == E_OK)
    {
      /* Check for TcsPtr is valid */
      ErrorFlag = Dma_lDetCheckTcsptr(DMA_SID_CONFIGCHLINKLIST,TcsPtr,
                                                            LinkedListCount);
      if(ErrorFlag == E_OK)
      {
        /* Check for Linked List type is valid */
        ErrorFlag = Dma_lDetCheckLLType(DMA_SID_CONFIGCHLINKLIST,Channel);
        if(ErrorFlag == E_OK)
        {
          /* Check for external buffer pointer is valid */
          ErrorFlag = Dma_lDetCheckExtBufferPtr(DMA_SID_CONFIGCHLINKLIST,
                                                            ExtBuffBasePtr);
        }
      }
    }
  }
  /* If any DET is reported Return value is made E_NOT_OK */
  if(ErrorFlag == E_NOT_OK)
  {
    RetVal = E_NOT_OK;
  }
  else
  #endif /* End of DMA_DEV_ERROR_DETECT */
  {
    /*Store the current channel configuration to be used for every transaction
    control set participating in Linked list operation*/
    AddrCtrlReg=DMA_SFR_RUNTIME_USER_MODE_READ32                               \
                                              (MODULE_DMA.CH[Channel].ADICR.U);
    ChConfigReg=DMA_SFR_RUNTIME_USER_MODE_READ32                               \
                                             (MODULE_DMA.CH[Channel].CHCFGR.U);
    ChStatusReg=DMA_SFR_RUNTIME_USER_MODE_READ32                               \
                                              (MODULE_DMA.CH[Channel].CHCSR.U);

    for(LoopCtr=0U; LoopCtr< LinkedListCount; LoopCtr++)
    {
      /*Configure RDCRCR register for linked list transaction*/
      ExtBuffBasePtr->DmaReadDataCrc= ReadDataCRC;

      /*Configure SDCRCR register for linked list transaction*/
      ExtBuffBasePtr->DmaSrcDestCrc = TcsPtr->DmaSrcDestCrcVal;

      /*Configure SADR register for linked list transaction*/
      ExtBuffBasePtr->DmaSourceAddress = TcsPtr->DmaSrcAddr;

      /*Configure DADR register for linked list transaction*/
      ExtBuffBasePtr->DmaDestinationAddress = TcsPtr->DmaDestAddr;

      /*Configure ADICR register for linked list transaction*/
      ExtBuffBasePtr->DmaAddressIntrControl = AddrCtrlReg;

      /*Configure CHCFGR register for linked list transaction*/
      ExtBuffBasePtr->DmaChannelConfig = (ChConfigReg |(uint32)(TcsPtr->
                                                           DmaXferReloadValue));
      if(LoopCtr != (LinkedListCount - 1U))
      {
        /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on 
         NextTcsPtr to access next element of Application Data Buffer*/
        NextTcsPtr++;
        /*Store the address of next Transaction control set to shadow address
        register*/
        ExtBuffBasePtr->DmaShadowAddress = NextTcsPtr;
      }
      else
      {
      /*Store the null address to shadow  address register to stop transaction*/
        ExtBuffBasePtr->DmaShadowAddress = (Dma_FullTxCtrlSetType*)NULL_PTR;
      }
      /*
      *Since SCH can only take 1 or 0, so any value of DmaAutoStart greater
      * than 0 will be treated as 1
      */
      if(TcsPtr->DmaAutoStart != 0U)
      {
        ExtBuffBasePtr->DmaChControlStatus =(ChStatusReg | DMA_SET_TX_REQ_MASK);
      }
      else
      {
        ExtBuffBasePtr->DmaChControlStatus = ChStatusReg;
      }
      /* Increment both pointers to point to next transaction set */
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on 
       ExtBuffBasePtr to access next element of Application Data Buffer*/
      ExtBuffBasePtr++;
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on 
       TcsPtr to access next element of Application Data Buffer*/
      TcsPtr++;
    }
/*configure the first transaction control set for channel */
/*write to RDCRCR with DmaReadDataCrc value pointed by FixedExtBuffBasePtr*/
    RegSetMask = FixedExtBuffBasePtr->DmaReadDataCrc ;

    DMA_SFR_RUNTIME_WRITE32(MODULE_DMA.CH[Channel].RDCRCR.U,RegSetMask);

/*write to SDCRCR with DmaSrcDestCrc value pointed by FixedExtBuffBasePtr*/
    RegSetMask = FixedExtBuffBasePtr->DmaSrcDestCrc ;

    DMA_SFR_RUNTIME_WRITE32(MODULE_DMA.CH[Channel].SDCRCR.U,RegSetMask);

/*write to SADR with DmaSourceAddress value pointed by FixedExtBuffBasePtr*/
    RegSetMask = FixedExtBuffBasePtr->DmaSourceAddress ;

    DMA_SFR_RUNTIME_WRITE32(MODULE_DMA.CH[Channel].SADR.U,RegSetMask);

/*write to DADR with appropriate value pointed by FixedExtBuffBasePtr*/
    RegSetMask = FixedExtBuffBasePtr->DmaDestinationAddress ;

    DMA_SFR_RUNTIME_WRITE32(MODULE_DMA.CH[Channel].DADR.U,RegSetMask);

/*write to ADICR with appropriate value pointed by FixedExtBuffBasePtr*/
    RegSetMask = FixedExtBuffBasePtr->DmaAddressIntrControl ;

    DMA_SFR_RUNTIME_WRITE32(MODULE_DMA.CH[Channel].ADICR.U,RegSetMask);

/*write to CHCFGR with DmaChannelConfig value pointed by FixedExtBuffBasePtr*/
    RegSetMask = FixedExtBuffBasePtr->DmaChannelConfig ;

    DMA_SFR_RUNTIME_WRITE32(MODULE_DMA.CH[Channel].CHCFGR.U,RegSetMask);

/*write to SHADR with DmaShadowAddress value pointed by FixedExtBuffBasePtr*/
  /*IFX_MISRA_RULE_11_01_STATUS=DmaShadowAddress is written as Set Mask*/
  /*IFX_MISRA_RULE_11_03_STATUS=DmaShadowAddress is written as Set Mask*/
    RegSetMask = (uint32)(FixedExtBuffBasePtr->DmaShadowAddress) ;

    DMA_SFR_RUNTIME_WRITE32(MODULE_DMA.CH[Channel].SHADR.U,RegSetMask);

/*write to CHCSR with DmaChControlStatus value pointed by FixedExtBuffBasePtr*/
    RegSetMask = FixedExtBuffBasePtr->DmaChControlStatus ;

    DMA_SFR_RUNTIME_WRITE32(MODULE_DMA.CH[Channel].CHCSR.U,RegSetMask);

    RetVal = E_OK;
  }
  return RetVal;
}
#endif /* End of DMA_LINKED_LIST_ENABLE */
/*******************************************************************************
** Traceability   : [cover parentID=DS_NAS_DMA_PR1803,DS_NAS_DMA_PR915,
                                    DS_NAS_DMA_PR63_17]                       **
**                                                                            **
** Syntax : Std_ReturnType Dma_GiveSwTrigger(Dma_ChType Channel)              **
**                                                                            **
** Service ID:  0x0E                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in) :  Channel - Channel ID                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  E_OK/E_NOT_OK                                           **
**                                                                            **
** Description : This API performs a software trigger.                        **
*******************************************************************************/
Std_ReturnType Dma_GiveSwTrigger(Dma_ChType Channel)
{
  Std_ReturnType RetVal;

  /* Check for DET's, only if DET is enabled */
  #if ( DMA_DEV_ERROR_DETECT == STD_ON )

  Std_ReturnType ErrorFlag;

  /* Check for DMA Driver is Initialized */
  ErrorFlag = Dma_lDetCheckUnInit(DMA_SID_GIVESWTRIG);
  if(ErrorFlag == E_OK)
  {
    /* Check for DMA channel is Initialized */
    ErrorFlag = Dma_lDetCheckChannelUnInit(DMA_SID_GIVESWTRIG,Channel);
  }
  /* If any DET is reported Return value is made E_NOT_OK */
  if(ErrorFlag == E_NOT_OK)
  {
    RetVal = E_NOT_OK;
  }
  else
  #endif /* End of DMA_DEV_ERROR_DETECT */
  {
    /*Give a software trigger*/
    DMA_SFR_RUNTIME_MODIFY32(MODULE_DMA.CH[Channel].CHCSR.U,                   \
                                 DMA_CHCSR_SCH_CLR_MASK,DMA_CHCSR_SCH_SET_MASK)

    RetVal = E_OK;
  }
  return RetVal;
}
/*******************************************************************************
** Traceability   : [cover parentID=DS_NAS_DMA_PR1804,DS_NAS_DMA_PR915,
                                    DS_NAS_DMA_PR63_18]                       **
**                                                                            **
** Syntax : Dma_CrcSetType Dma_GetCRC(Dma_ChType Channel)                     **
**                                                                            **
** Service ID:  0x0F                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in) :  Channel - Channel ID                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  Dma_CrcSetType                                          **
**                                                                            **
** Description : Returns CRC values of read data and source/destinatinon      **
**               address registers calculated by the hardware for the channel.**
*******************************************************************************/
Dma_CrcSetType Dma_GetCRC(Dma_ChType Channel)
{
  Dma_CrcSetType CrcValStruct;
   /* Check for DET's, only if DET is enabled */

  #if ( DMA_DEV_ERROR_DETECT == STD_ON )

  Std_ReturnType ErrorFlag;

  /* Check for DMA Driver is Initialized */
  ErrorFlag = Dma_lDetCheckUnInit(DMA_SID_GETCHCRCVALUES);
  if(ErrorFlag == E_OK)
  {
    /* Check for DMA channel is Initialized */
    ErrorFlag = Dma_lDetCheckChannelUnInit(DMA_SID_GETCHCRCVALUES,Channel);
  }
  /* If any DET is reported,then DmaInvalidCrc bit of returning structure is
     made as 1  */
  if(ErrorFlag == E_NOT_OK)
  {
    CrcValStruct.DmaInvalidCrc =1U;
  }
  else
  #endif /* End of DMA_DEV_ERROR_DETECT */
  {
    /*Store the read data CRC values in DmaRdDataCrc */
    CrcValStruct.DmaRdDataCrc = DMA_SFR_RUNTIME_USER_MODE_READ32               \
                                              (MODULE_DMA.CH[Channel].RDCRCR.U);

    /*Store the source and destination address CRC values in DmaSrcDstAddrCrc*/
    CrcValStruct.DmaSrcDstAddrCrc= DMA_SFR_RUNTIME_USER_MODE_READ32            \
                                              (MODULE_DMA.CH[Channel].SDCRCR.U);

    /*Reset DmaInvalidCrc bit of returning structure to 0 indicating no DET*/
    CrcValStruct.DmaInvalidCrc =0U;
  }
  return CrcValStruct;
}
/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_HE2_DMA_PR2933, DS_NAS_EP_DMA_PR2933]**
** Syntax : Std_ReturnType Dma_ReconfigureChannel(Dma_ChType Channel,         **
                         const Dma_ChannelAddressConfigType *ChAddrConfigPtr) **
**                                                                            **
** Service ID:  0x12                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in) : Channel        - Channel ID                              **
**                   ChAddrConfigPtr- Pointer to channel address configuration**
**                              structure of type Dma_ChannelAddressConfigType**
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  E_OK/E_NOT_OK                                           **
**                                                                            **
** Description : This service reconfigures/reinitializes the Dma channel with **
**               the configuration pointed by ChAddrConfigPtr of              **
**               type ChannelAddressConfigType.                               **
*******************************************************************************/
Std_ReturnType Dma_ReconfigureChannel(Dma_ChType Channel, 
                   const Dma_ChannelAddressConfigType *ChAddrConfigPtr)
{
  uint32 RegSetMask;
  Std_ReturnType RetVal;
  
  /* Check for DET's, only if DET is enabled */
  #if ( DMA_DEV_ERROR_DETECT == STD_ON )

  Std_ReturnType ErrorFlag;
  /* Check for DMA Driver is Initialized */
  ErrorFlag = Dma_lDetCheckUnInit(DMA_SID_RECONFIGCHANNEL);
  if(ErrorFlag == E_OK)
  {
    /* Check for DMA channel is Initialized */
    ErrorFlag = Dma_lDetCheckChannelUnInit(DMA_SID_RECONFIGCHANNEL,Channel);
    if(ErrorFlag == E_OK)
    {
      /* Check if ChAddrConfigPtr points to NULL */
      ErrorFlag = Dma_lDetCheckNullAddr(DMA_SID_RECONFIGCHANNEL,
                                         ChAddrConfigPtr);
    }
  }
  /* If any DET is reported Return value is made E_NOT_OK */
  if(ErrorFlag == E_NOT_OK)
  {
    RetVal = E_NOT_OK;
  }
  else
  #endif /* End of DMA_DEV_ERROR_DETECT */
  {
    /* Update DMA Channel Address and Interrupt Control Register */
    RegSetMask = 
    (((uint32)(ChAddrConfigPtr->IncrementSrcDirection)<<DMA_ADICR_INC_SRC_ADD)
    |((uint32)(ChAddrConfigPtr->IncrementDstDirection)<<DMA_ADICR_INC_DST_ADD) 
    |((uint32)(ChAddrConfigPtr->SrcAddressOffset)<<DMA_ADICR_SRC_ADD_OFFSET) 
    |((uint32)(ChAddrConfigPtr->DstAddressOffset)<<DMA_ADICR_DST_ADD_OFFSET) 
    |((uint32)(ChAddrConfigPtr->SrcCircularBuffEn)<<DMA_ADICR_SRC_CB_EN) 
    |((uint32)(ChAddrConfigPtr->DstCircularBuffEn)<<DMA_ADICR_DST_CB_EN) 
    |((uint32)(ChAddrConfigPtr->SrcCircularBuffLength)<<DMA_ADICR_SRC_CB_LEN) 
    |((uint32)(ChAddrConfigPtr->DstCircularBuffLength)<<DMA_ADICR_DST_CB_LEN) 
    |((uint32)(ChAddrConfigPtr->SrcCircularBuffEn)<<DMA_ADICR_SRC_WRP_EN) 
    |((uint32)(ChAddrConfigPtr->DstCircularBuffEn)<<DMA_ADICR_DST_WRP_EN));
    DMA_SFR_RUNTIME_MODIFY32(MODULE_DMA.CH[Channel].ADICR.U,DMA_ADICR_CLR_MASK,\
                                                                    RegSetMask)
    RetVal = E_OK;
  }
  return RetVal;
}


/*******************************************************************************
**                      Local Function Definitions                            **
*******************************************************************************/

/*******************************************************************************
** Syntax : static uint32 Dma_lRemapDsprAddress(const uint32* Address)        **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in): Address- input address                                    **
**                                                                            **
** Parameters (out):  none                                                    **
**                                                                            **
** Return value:  RemapAddress(address after remapping)                       **
**                                                                            **
** Description : This function maps the DSPR address to the global address    **
              which can be used by other cores or Dma                         **
*******************************************************************************/
static uint32 Dma_lRemapDsprAddress(const uint32* Address)
{
  uint32 RemapAddress;
  /*IFX_MISRA_RULE_11_01_STATUS=DSPR address is mapped to the global address*/
  /*IFX_MISRA_RULE_11_03_STATUS=DSPR address is mapped to the global address*/
  RemapAddress = Mcal_GetDsprReMapAddress((uint32)Address);
  return RemapAddress;
}

/*******************************************************************************
** Syntax : static void Dma_lSetXferCount(Dma_ChType Channel, uint16 Tcount)  **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in): channel- input channel                                    **
**                  Tcount - transfer count                                   **
** Parameters (out):  none                                                    **
**                                                                            **
** Return value:  none                                                        **
**                                                                            **
** Description : Function to update transfer count value for Dma channel      **
**                                                                            **
*******************************************************************************/
static void Dma_lSetXferCount(Dma_ChType Channel, uint16 Tcount)
{
  /*
  This contains the number of DMA transfers for DMA transaction of DMA
  channel 0n. This 14-bit transfer count value is loaded into CHCSRz.TCOUNT
  at the start of a DMA transaction (when TSRz.CH becomes set
  and CHCSRz.TCOUNT = 0). TREL can be written during a running DMA
  transaction because TCOUNT will be updated (decremented) during the DMA
  transaction.
  If TREL = 0 or if TREL = 1, TCOUNT will be loaded with 1 when a new
  transaction is started (at least one DMA transfer must be executed
  per DMA transaction).
  */
  DMA_SFR_RUNTIME_MODIFY32(MODULE_DMA.CH[Channel].CHCFGR.U,                    \
                                           DMA_CHCFGR_TREL_MASK,(uint32)Tcount)
}

#if (DMA_DEV_ERROR_DETECT == STD_ON )
/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          :static Std_ReturnType Dma_lDetCheckUnInit(uint8 ServiceId)**
**                                                                            **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : ServiceId - Service ID of the API from which this API is **
**                   invoked                                                  **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK/ E_NOT_OK                                           **
**                                                                            **
** Description     : This function reports a DET if DMA is uninitialized      **
*******************************************************************************/
static Std_ReturnType Dma_lDetCheckUnInit(uint8 ServiceId)
{
  Std_ReturnType RetVal;
  if(Dma_DriverState == DMA_DRIVER_UNINIT)
  {
    Det_ReportError(DMA_MODULE_ID,DMA_MODULE_INSTANCE,
                                                ServiceId,DMA_E_UNINIT);
    RetVal = E_NOT_OK;
  }
  else
  {
    RetVal = E_OK;
  }
return RetVal;
}

/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : static Std_ReturnType Dma_lDetCheckChannelUnInit(uint8   **
**                                         ServiceId, Dma_ChType Channel)     **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : ServiceId - Service ID of the API from which this API is **
**                   invoked                                                  **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK/ E_NOT_OK                                           **
**                                                                            **
** Description     : This api reports a DET if DMA channel is uninitialized   **
*******************************************************************************/
static Std_ReturnType Dma_lDetCheckChannelUnInit(uint8 ServiceId,
                                                             Dma_ChType Channel)
{
  Std_ReturnType RetVal;
  /*
  *check if channel ID passed is in allowed range
  *(i.e less than max no. of channels)
  */
  RetVal = Dma_lDetCheckChannel(ServiceId, Channel);
  if(RetVal == E_OK)
  {
    /* check if channel ID passed is initialized in Dma_Init*/
    if(Dma_ChannelState[Channel] == DMA_DRIVER_CH_UNINIT)
    {
      Det_ReportError(DMA_MODULE_ID, DMA_MODULE_INSTANCE, ServiceId,
                                                               DMA_E_CH_UNINIT);
      RetVal = E_NOT_OK;
    }
    else
    {
      RetVal = E_OK;
    }
  }
  return RetVal;
}
/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : static Std_ReturnType Dma_lDetCheckChannel(uint8         **
**                   ServiceId, Dma_ChType Channel)                           **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : ServiceId - Service ID of the API from which this API is **
**                   invoked                                                  **
**                   Channel - Channel ID                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK/ E_NOT_OK                                           **
**                                                                            **
** Description     : This function :                                          **
**                  - reports a DET if DMA channel is invalid                 **
*******************************************************************************/
static Std_ReturnType Dma_lDetCheckChannel(uint8 ServiceId,Dma_ChType Channel)
{
  Std_ReturnType RetVal;
  if((uint8)Channel >= (uint8)DMA_NUM_OF_CHANNELS )
  {
    Det_ReportError(DMA_MODULE_ID,DMA_MODULE_INSTANCE,
                     ServiceId, DMA_E_INVALID_CHANNEL);
    RetVal = E_NOT_OK;
  }
  else
  {
      RetVal = E_OK;
  }
  return RetVal;
}

/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : static Std_ReturnType Dma_lDetCheckNullAddr(uint8        **
**                   ServiceId, const void *AddressPtr)                       **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : ServiceId - Service ID of the API from which this API is **
**                   invoked                                                  **
**                   AddressPtr - pointer to an address                       **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK/ E_NOT_OK                                           **
**                                                                            **
** Description     : This function :                                          **
**                  - reports a DET if source address entered is invalid      **
*******************************************************************************/
static Std_ReturnType Dma_lDetCheckNullAddr(uint8 ServiceId,
                                                    const void *AddressPtr)
{
  Std_ReturnType RetVal;
  if(AddressPtr == NULL_PTR )
  {
    Det_ReportError(DMA_MODULE_ID,DMA_MODULE_INSTANCE,
                          ServiceId, DMA_E_INVALID_ADDR);
    RetVal = E_NOT_OK;
  }
  else
  {
      RetVal = E_OK;
  }
  return RetVal;
}
/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : static Std_ReturnType Dma_lDetCheckTCount(uint8          **
**                   ServiceId, uint16 TCount)                                **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : ServiceId - Service ID of the API from which this API is **
**                   invoked                                                  **
**                   TCount - Transfer count                                  **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK/ E_NOT_OK                                           **
**                                                                            **
** Description     : This function :                                          **
**                  - reports a DET if Transfer count entered is invalid      **
*******************************************************************************/
static Std_ReturnType Dma_lDetCheckTCount(uint8 ServiceId, uint16 TCount)
{

  Std_ReturnType RetVal;
  if(TCount >= DMA_MAX_TCOUNT)
  {
    Det_ReportError(DMA_MODULE_ID,DMA_MODULE_INSTANCE,
                              ServiceId, DMA_E_INVALID_TCOUNT);
    RetVal = E_NOT_OK;
  }
  else
  {
      RetVal = E_OK;
  }
  return RetVal;
}
/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : static Std_ReturnType Dma_lDetCheckMoveEngine(uint8      **
**                   ServiceId, uint8 MoveEngine)                             **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : ServiceId - Service ID of the API from which this API is **
**                   invoked                                                  **
**                   MoveEngine - Move Engine ID                              **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK/ E_NOT_OK                                           **
**                                                                            **
** Description     : This function :                                          **
**                  - reports a DET if Move Engine ID entered is invalid      **
*******************************************************************************/
static Std_ReturnType Dma_lDetCheckMoveEngine(uint8 ServiceId, uint8 MoveEngine)
{
  Std_ReturnType RetVal;
  if((MoveEngine == 0U ) || (MoveEngine == 1U ))
  {
    RetVal = E_OK;
  }
  else
  {
    Det_ReportError(DMA_MODULE_ID,DMA_MODULE_INSTANCE,
                                ServiceId, DMA_E_INVALID_ME);
    RetVal = E_NOT_OK;
  }
  return RetVal;
}
/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : static Std_ReturnType Dma_lDetCheckMask(uint8            **
**                   ServiceId, uint32 ClrErrMask)                            **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : ServiceId - Service ID of the API from which this API is **
**                   invoked                                                  **
**                   ClrErrMask - clear error mask value                      **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK/ E_NOT_OK                                           **
**                                                                            **
** Description     : This function :                                          **
**                  - reports a DET if clear error mask entered is invalid    **
*******************************************************************************/
static Std_ReturnType Dma_lDetCheckMask(uint8 ServiceId, uint32 ClrErrMask)
{
  Std_ReturnType RetVal;
  /*check for the range*/
  if((ClrErrMask <= 0x0000FFFFU) ||(ClrErrMask >= 0x08000000U) )
  {
    Det_ReportError(DMA_MODULE_ID,DMA_MODULE_INSTANCE,
                            ServiceId, DMA_E_INVALID_MASK);
    RetVal = E_NOT_OK;
  }
  else
  {
      RetVal = E_OK;
  }
  return RetVal;
}
/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : static Std_ReturnType Dma_lDetCheckHaltMode(uint8        **
**                    ServiceId, Dma_ChannelHaltType HaltMode)                **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : ServiceId - Service ID of the API from which this API is **
**                   invoked                                                  **
**                   HaltMode - Halt mode value                               **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK/ E_NOT_OK                                           **
**                                                                            **
** Description     : This function :                                          **
**                  - reports a DET if halt mode entered is invalid           **
*******************************************************************************/
static Std_ReturnType Dma_lDetCheckHaltMode(uint8 ServiceId,
                                            Dma_ChannelHaltType HaltMode)
{
  Std_ReturnType RetVal;
  if((HaltMode == DMA_HALT_OFF) || (HaltMode == DMA_HALT_ON) )
  {
    RetVal = E_OK;
  }
  else
  {
    Det_ReportError(DMA_MODULE_ID,DMA_MODULE_INSTANCE,
                                ServiceId, DMA_E_INVALID_HALT_MODE);
    RetVal = E_NOT_OK;
  }
  return RetVal;
}
/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : static Std_ReturnType Dma_lDetCheckIntrMode(uint8        **
**                    ServiceId, Dma_InterruptModeType InterruptMode)         **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : ServiceId - Service ID of the API from which this API is **
**                   invoked                                                  **
**                   InterruptMode - Interrupt mode value                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK/ E_NOT_OK                                           **
**                                                                            **
** Description     : This function :                                          **
**                  - reports a DET if Interrupt mode entered is invalid      **
*******************************************************************************/
static Std_ReturnType Dma_lDetCheckIntrMode(uint8 ServiceId,
                                            Dma_InterruptModeType InterruptMode)
{
  Std_ReturnType RetVal;
  if((InterruptMode == DMA_CH_INT_OFF) || (InterruptMode == DMA_CH_INT_ON))
  {
    RetVal = E_OK;
  }
  else
  {
    Det_ReportError(DMA_MODULE_ID,DMA_MODULE_INSTANCE,
                                ServiceId, DMA_E_INVALID_INTR_MODE);
    RetVal = E_NOT_OK;
  }
  return RetVal;
}

#if (DMA_LINKED_LIST_ENABLE == STD_ON)
/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : static Std_ReturnType Dma_lDetCheckTcsptr(uint8          **
**                         ServiceId, const Dma_TransactionSetType *TcsPtr,   **
**                         uint32 MaxLLcount)                                 **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : ServiceId - Service ID of the API from which this API is **
**                   invoked                                                  **
**                   TcsPtr - pointer to a set of type Dma_TransactionSetType **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK/ E_NOT_OK                                           **
**                                                                            **
** Description     : This function :                                          **
**                  - reports a DET if value pointed by TcsPtr is invalid     **
*******************************************************************************/
static Std_ReturnType Dma_lDetCheckTcsptr(uint8 ServiceId, const
                              Dma_TransactionSetType *TcsPtr, uint32 MaxLLcount)
{
  uint32 LLcount;
  Std_ReturnType RetVal;
  /* Check for linked list count is valid */
  RetVal = Dma_lDetCheckLLCount(ServiceId, MaxLLcount);
  if(RetVal == E_OK)
  {
    if(TcsPtr != NULL_PTR)
    {
      /*check if input data elements pointed by TcsPtr are valid */
      for(LLcount=0U; LLcount< MaxLLcount; LLcount++)
      {
        if((TcsPtr->DmaSrcAddr == 0U) || (TcsPtr->DmaDestAddr == 0U) ||
                             (TcsPtr->DmaXferReloadValue >= DMA_MAX_TCOUNT))
        {
          Det_ReportError(DMA_MODULE_ID,DMA_MODULE_INSTANCE,
                          ServiceId, DMA_E_INVALID_TCSPTR);
          RetVal = E_NOT_OK;
          break;
        }
        else
        {
          /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on 
           TcsPtr to access next element of Application Data Buffer*/
          TcsPtr++;
        }
        RetVal = E_OK;
      }
    }
    else
    {
      /*Raise invalid address DET*/
      Det_ReportError(DMA_MODULE_ID,DMA_MODULE_INSTANCE,
                         ServiceId, DMA_E_INVALID_ADDR);
      RetVal = E_NOT_OK;
    }
  }
  return RetVal;
}
/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : static Std_ReturnType Dma_lDetCheckLLType(uint8          **
**                                         ServiceId, Dma_ChType Channel)     **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : ServiceId - Service ID of the API from which this API is **
**                   invoked                                                  **
**                   Channel - Input channel value                            **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK/ E_NOT_OK                                           **
**                                                                            **
** Description     : This function :                                          **
**                  - reports a DET if shadow address register**
**                    not configured for linked list transaction**
*******************************************************************************/
static Std_ReturnType Dma_lDetCheckLLType(uint8 ServiceId,Dma_ChType Channel)
{
  Std_ReturnType RetVal;
  volatile uint8 LLType;

  LLType = (uint8 )((DMA_SFR_RUNTIME_USER_MODE_READ32                          \
  (MODULE_DMA.CH[Channel].ADICR.U) >> IFX_DMA_BLK_ME_ADICR_SHCT_OFF)           \
                                   & IFX_DMA_BLK_ME_ADICR_SHCT_MSK);

  if(LLType >= DMA_NUM_12)
  {
      RetVal = E_OK;
  }
  else
  {
    Det_ReportError(DMA_MODULE_ID,DMA_MODULE_INSTANCE,
                                ServiceId, DMA_E_INVALID_LLTYPE);
    RetVal = E_NOT_OK;
  }
  return RetVal;
}
/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : static Std_ReturnType Dma_lDetCheckExtBufferPtr(uint8    **
**                          ServiceId,                                        **
**                          const Dma_FullTxCtrlSetType *ExtBuffBasePtr)      **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : ServiceId - Service ID of the API from which this API is **
**                   invoked                                                  **
**                   ExtBuffBasePtr - pointer to a structure of type          **
**                   Dma_FullTxCtrlSetType                                    **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK/ E_NOT_OK                                           **
**                                                                            **
** Description     : This function :                                          **
**                  - reports a DET if ExtBuffBasePtr is invalid pointer      **
*******************************************************************************/
static Std_ReturnType Dma_lDetCheckExtBufferPtr(uint8 ServiceId, const
                                        Dma_FullTxCtrlSetType *ExtBuffBasePtr)
{
  Std_ReturnType RetVal;
  if(ExtBuffBasePtr != NULL_PTR)
  {
    /*check if ExtBuffBasePtr is 32-byte aligned*/
    /*IFX_MISRA_RULE_11_01_STATUS=ExtBuffBasePtr is verified for 
      word alignement*/
    /*IFX_MISRA_RULE_11_03_STATUS=ExtBuffBasePtr is verified for 
      word alignement*/
    if((((uint32)ExtBuffBasePtr)%(32U)) == 0U)
    {
      RetVal = E_OK;
    }
    else
    {
      /*Raise DET as address is not 32 byte aligned*/
      Det_ReportError(DMA_MODULE_ID,DMA_MODULE_INSTANCE,
                         ServiceId, DMA_E_INVALID_EXTBUFFPTR);
      RetVal = E_NOT_OK;
    }
  }
  else
  {
    /*Raise invalid address DET*/
    Det_ReportError(DMA_MODULE_ID,DMA_MODULE_INSTANCE,
                         ServiceId, DMA_E_INVALID_ADDR);
    RetVal = E_NOT_OK;
  }
  return RetVal;
}
/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : static Std_ReturnType Dma_lDetCheckLLCount(uint8         **
**                    ServiceId, uint32 LinkedListCount)                      **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : ServiceId - Service ID of the API from which this API is **
**                   invoked                                                  **
**                   LinkedListCount- number of transaction control sets to be**
**                                    executed                                **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK/ E_NOT_OK                                           **
**                                                                            **
** Description     : This function :                                          **
**                  -reports a DET if LinkedListCount value entered is invalid**
*******************************************************************************/
static Std_ReturnType Dma_lDetCheckLLCount(uint8 ServiceId,
                                            uint32 LinkedListCount)
{
  Std_ReturnType RetVal;
  if(LinkedListCount == 0U)
  {
    Det_ReportError(DMA_MODULE_ID,DMA_MODULE_INSTANCE,
                                ServiceId, DMA_E_INVALID_LLCOUNT);
    RetVal = E_NOT_OK;
  }
  else
  {
    RetVal = E_OK;
  }
  return RetVal;
}


#endif /* End of DMA_LINKED_LIST_ENABLE */
#if (DMA_DOUBLE_BUFFER_ENABLE == STD_ON)
/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : static Std_ReturnType Dma_lDetCheckDblBuffMode(uint8     **
**                   ServiceId, Dma_ChType Channel)                           **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : ServiceId - Service ID of the API from which this API is **
**                   invoked                                                  **
**                   Channel - Input Dma Channel                              **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK/ E_NOT_OK                                           **
**                                                                            **
** Description     : This function reports a DET if Shadow control mode is not**
**                    configured for Double buffering operation               **
*******************************************************************************/
static Std_ReturnType Dma_lDetCheckDblBuffMode(uint8 ServiceId,
                                                            Dma_ChType Channel)
{
  Std_ReturnType RetVal;
  volatile uint8 ShadowControl;
  ShadowControl = (uint8)((DMA_SFR_RUNTIME_USER_MODE_READ32                    \
  (MODULE_DMA.CH[Channel].ADICR.U) >> IFX_DMA_BLK_ME_ADICR_SHCT_OFF)           \
                                     & IFX_DMA_BLK_ME_ADICR_SHCT_MSK);
  /*checking of volatile variable LLType is broken into two conditions from one,
  so that Misra rule 12.4 (reading volatile side effect) is not violated*/
  if(ShadowControl >= DMA_NUM_8)
  {
    if(ShadowControl <= DMA_NUM_11)
    {
      RetVal = E_OK;
    }
    else
    {
      Det_ReportError(DMA_MODULE_ID,DMA_MODULE_INSTANCE,
                              ServiceId, DMA_E_INVALID_SWITCHREQ);
      RetVal = E_NOT_OK;
    }
  }
  else
  {
    Det_ReportError(DMA_MODULE_ID,DMA_MODULE_INSTANCE,
                              ServiceId, DMA_E_INVALID_SWITCHREQ);
    RetVal = E_NOT_OK;
  }
  return RetVal;
}
#endif/* End of DMA_DOUBLE_BUFFER_ENABLE */
/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : static Std_ReturnType Dma_lDetCheckShadowSettings(uint8  **
**                   ServiceId, uint8 ShadowControl, uint32 *ShadowAddrPtr)   **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : ServiceId - Service ID of the API from which this API is **
**                   invoked                                                  **
**                   ShadowControl - contains the shadow control settings for **
**                   the channel                                              **
**                   ShadowAddrPtr - points to an address of a buffer which is**
**                   to be used for double address buffering                  **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK/ E_NOT_OK                                           **
**                                                                            **
** Description     : This function reports a DET if address pointed by        **
**                   ShadowAddrPtr is invalid or if Shadow control settings   **
**                   implies that shadow operation is disabled.               **
*******************************************************************************/
static Std_ReturnType Dma_lDetCheckShadowSettings(uint8 ServiceId, uint8
                                     ShadowControl, const uint32 *ShadowAddrPtr)
{
  Std_ReturnType RetVal;
  RetVal=Dma_lDetCheckNullAddr(ServiceId, ShadowAddrPtr);
  if(RetVal == E_OK )
  {
    if(ShadowControl != 0U)
    {
        RetVal = E_OK;
    }
    else
    {
      Det_ReportError(DMA_MODULE_ID,DMA_MODULE_INSTANCE,
                     ServiceId, DMA_E_INVALID_SHADOW_CONFIG);
      RetVal = E_NOT_OK;
    }
  }
  else
  {
    RetVal = E_NOT_OK;
  }
  return RetVal;
}

#endif /* End of DMA_DEV_ERROR_DETECT */

/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : static void Dma_lResetSfr(void)                          **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : None                                                     **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
** Description     : This function resets the SFR used                        **
                     in DMA module to their reset value                       **
*******************************************************************************/
#if(DMA_RESET_SFR_INIT == STD_ON)
static void Dma_lResetSfr(void)
{
  const Dma_ChannelConfigType *lChannelCfgPtr;
  uint8 Channel;
  uint8 ChIndex;
  
  DMA_SFR_INIT_WRITE32(MODULE_DMA.PRR0.U,DMA_RESET_VALUE);
  DMA_SFR_INIT_WRITE32(MODULE_DMA.PRR1.U,DMA_RESET_VALUE);
  DMA_SFR_INIT_WRITE32(MODULE_DMA.BLK0.CLRE.U,DMA_RESET_VALUE);
  DMA_SFR_INIT_WRITE32(MODULE_DMA.BLK1.CLRE.U,DMA_RESET_VALUE);
  
  /*Configure error registers of move engine 0 for DMA*/
  DMA_SFR_INIT_WRITE32(MODULE_DMA.BLK0.EER.U,DMA_BLK_ERR_VALUE);
  /*Configure error registers of move engine 1 for DMA*/
  DMA_SFR_INIT_WRITE32(MODULE_DMA.BLK1.EER.U,DMA_BLK_ERR_VALUE);

  /*Initialize all the channels*/
  for(ChIndex=0U; ChIndex<(Dma_kConfigPtr->ChannelsConfigured); ChIndex++)
  {
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on 
     ChannelCfgPtr to access the PB Configuration of a particular Channel
     and is within allowed range*/
    lChannelCfgPtr = &(Dma_kConfigPtr->ChannelCfgPtr[ChIndex]);
    Channel = lChannelCfgPtr->DmaChannelNumber;

    DMA_SFR_INIT_WRITE32(MODULE_DMA.TSR[Channel].U,DMA_RESET_VALUE);
    DMA_SFR_INIT_WRITE32(MODULE_DMA.CH[Channel].CHCFGR.U,DMA_RESET_VALUE);
    DMA_SFR_INIT_WRITE32(MODULE_DMA.CH[Channel].ADICR.U,DMA_RESET_VALUE);
    DMA_SFR_INIT_WRITE32(MODULE_DMA.CH[Channel].RDCRCR.U,DMA_RESET_VALUE);
    DMA_SFR_INIT_WRITE32(MODULE_DMA.CH[Channel].SDCRCR.U,DMA_RESET_VALUE);
    DMA_SFR_INIT_WRITE32(MODULE_DMA.CH[Channel].SADR.U,DMA_RESET_VALUE);
    DMA_SFR_INIT_WRITE32(MODULE_DMA.CH[Channel].DADR.U,DMA_RESET_VALUE);
    DMA_SFR_INIT_WRITE32(MODULE_DMA.CH[Channel].CHCSR.U,DMA_RESET_VALUE);

    DMA_SFR_INIT_RESETSAFETYENDINIT(DMA_SAFETY_ENDINT_TIMEOUT);

    /*Configure the hardware resource partition settings for DMA channel*/
    DMA_SFR_INIT_WRITE32(MODULE_DMA.HRR[Channel].U,DMA_RESET_VALUE);
    /*Configure the Hardware Resource Supervisor Mode settings */
    DMA_SFR_INIT_WRITE32(MODULE_DMA.MODE[lChannelCfgPtr->                      \
                             DmaChannelHwPartitionConfig].U,DMA_MODE_RESET_VAL);
    DMA_SFR_INIT_SETSAFETYENDINIT();
  }
}
#endif /* DMA_RESET_SFR_INIT == STD_ON */

#define DMA_STOP_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is 
 allowed only for MemMap.h*/
#include "MemMap.h"