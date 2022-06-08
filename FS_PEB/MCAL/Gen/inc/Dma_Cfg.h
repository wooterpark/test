/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2015)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  FILENAME  : Dma_Cfg.h                                                    **
**                                                                           **
**  $CC VERSION : \main\17 $                                                 **
**                                                                           **
**  DATE, TIME: 2021-09-29, 16:08:33                                     **
**                                                                           **
**  GENERATOR : Build b141014-0350                                         **
**                                                                           **
**  AUTHOR    : DL-AUTOSAR-Engineering                                       **
**                                                                           **
**  VENDOR    : Infineon Technologies                                        **
**                                                                           **
**  DESCRIPTION  : DMA configuration generated out of ECU configuration      **
**                 file (Dma.bmd/.xdm)                                       **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/
/******************************************************************************
**                                                                           **
    TRACEBILITY :[cover parentID = DS_NAS_DMA_PR446,
    SAS_NAS_DMA_PR914,SAS_NAS_DMA_PR915,SAS_NAS_DMA_PR916,SAS_NAS_DMA_PR60,
    SAS_NAS_DMA_PR64,SAS_NAS_DMA_PR82,DS_NAS_HE2_DMA_PR3054_1,
    DS_NAS_EP_DMA_PR3054_1,DS_NAS_HE2_DMA_PR3054_2,DS_NAS_EP_DMA_PR3054_2,
    DS_NAS_HE2_DMA_PR3054_3,DS_NAS_EP_DMA_PR3054_3,DS_NAS_HE2_DMA_PR3054_4
    DS_NAS_EP_DMA_PR3054_4][/cover]                                          **
**                                                                           **
******************************************************************************/

#ifndef DMA_CFG_H 
#define DMA_CFG_H 

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

#define DMA_MODULE_INSTANCE             ((uint8)4U)

/*SW Version Information*/
#define DMA_SW_MAJOR_VERSION            (1U)
#define DMA_SW_MINOR_VERSION            (2U)
#define DMA_SW_PATCH_VERSION            (0U)

/*Number of DMA channels present in the controller*/
#define DMA_NUM_OF_CHANNELS             (64U)

/* Total Number of DMA Config Sets */
#define DMA_CONFIG_COUNT               (1U)

/* Derived Configuration for DmaDevErrorDetect */
#define DMA_DEV_ERROR_DETECT            (STD_OFF)

/*
Configuration: Dma_RUNNING_IN_USER_0_MODE_ENABLE 
- if STD_ON, enable User0 mode 
- if STD_OFF, enable User1 mode 
*/
  #define DMA_RUNNING_IN_USER_0_MODE_ENABLE    (STD_OFF)
  
/*
Configuration: Dma_USER_MODE_INIT_API_ENABLE
- if STD_ON, Enable Protected Mode(user mode) in Init API 
- if STD_OFF, Enable Supervisor mode in Init API  
*/
  #define DMA_USER_MODE_INIT_API_ENABLE    (STD_OFF)
  /*
Configuration: Dma_USER_MODE_DEINIT_API_ENABLE
- if STD_ON, Enable Protected Mode(user mode) in DeInit API 
- if STD_OFF, Enable Supervisor mode in DeInit API 
*/
  #define DMA_USER_MODE_DEINIT_API_ENABLE    (STD_OFF)
  /*
Configuration: Dma_MODE_RUNTIME_API_ENABLE
- if STD_ON, Enable Protected Mode(user mode) in APIs other than Init/Deinit APIs
- if STD_OFF, Enable Supervisor mode in APIs other than Init/Deinit APIs
*/
  #define DMA_USER_MODE_RUNTIME_API_ENABLE    (STD_OFF)
  /* Derived Configuration for DmaVersionInfoApi */
#define DMA_VERSION_INFO_API            (STD_OFF)

/* Derived Configuration for DmaDoubleBufferEnable */
#define DMA_DOUBLE_BUFFER_ENABLE      (STD_OFF)

/* Derived Configuration for DmaDeInitApi */
#define DMA_DEINIT_API                  (STD_OFF)

/* Derived Configuration for DmaLinkedListEnable*/
#define DMA_LINKED_LIST_ENABLE          (STD_OFF)

/* Derived Configuration DmaDebugSupport*/
#define DMA_DEBUG_SUPPORT               (STD_OFF)

/* Derived Configuration DmaResetSfrAtInit */
#define DMA_RESET_SFR_INIT              (STD_OFF)



/* Derived Configuration DmaPBFixedAddress*/
#define DMA_PB_FIXEDADDR                (STD_OFF)



/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/

#endif  /*End of DMA_CFG_H */


