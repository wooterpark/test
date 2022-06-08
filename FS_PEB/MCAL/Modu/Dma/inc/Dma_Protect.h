/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2016)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  $FILENAME   : Dma_Protect.h $                                            **
**                                                                            **
**   $CC VERSION : \main\5 $                                                  **
**                                                                            **
**   $DATE       : 2016-04-30 $                                               **
**                                                                            **
**   AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**   VENDOR      : Infineon Technologies                                      **
**                                                                            **
**  DESCRIPTION  : This file file define all the first level                  **
**                 indirection macros for Protected mode support              **
**                                                                            **
**                                                                            **
**  MAY BE CHANGED BY USER [Yes/No]: Yes                                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                                                                            **
** Traceabilty      :                                                         **
**                                                                            **
*******************************************************************************/

#ifndef  DMA_PROTECT_CFG_H
#define  DMA_PROTECT_CFG_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Inclusion of McalOsConfig.h */
#include "McalOsConfig.h"
#include MCAL_OS_HEADER
#include "Dma_Cfg.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
#define OS_AREA_DRV_DMA (0x01U)

#if (DMA_USER_MODE_INIT_API_ENABLE == STD_ON) 
#define DMA_INIT_WRITE32(reg, value)                                 OS_WritePeripheral32(OS_AREA_DRV_DMA,(volatile uint32*)(volatile void*)(&(reg)),(value))
#define DMA_INIT_RESETSAFETYENDINIT(Time)                                 TRUSTED_ApplSafetyResetEndInit_Timed ((Time))
#define DMA_INIT_SETSAFETYENDINIT(void)                                       TRUSTED_ApplSafetySetEndInit_Timed(void)
#if (DMA_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)
  #define DMA_INIT_USER_MODE_OS_API_READ32(reg)                           OS_ReadPeripheral32(OS_AREA_DRV_DMA,(volatile uint32*)(volatile void*)(&(reg)))
#endif                                                                       
#endif /* DMA_USER_MODE_INIT_API_ENABLE == STD_ON  */

#if (DMA_USER_MODE_DEINIT_API_ENABLE == STD_ON) 
#define DMA_DEINIT_WRITE32(reg, value)                                 OS_WritePeripheral32(OS_AREA_DRV_DMA,(volatile uint32*)(volatile void*)(&(reg)),(value))
#define DMA_DEINIT_MODIFY32(reg,clearmask,setmask)                     OS_ModifyPeripheral32(OS_AREA_DRV_DMA,(volatile uint32*)(volatile void*)(&(reg)),(clearmask),(setmask));
#define DMA_DEINIT_RESETSAFETYENDINIT(Time)                                 TRUSTED_ApplSafetyResetEndInit_Timed ((Time))
#define DMA_DEINIT_SETSAFETYENDINIT(void)                                       TRUSTED_ApplSafetySetEndInit_Timed(void)
#endif /* DMA_USER_MODE_DEINIT_API_ENABLE == STD_ON  */ 

#if (DMA_USER_MODE_RUNTIME_API_ENABLE == STD_ON) 
#define DMA_RUNTIME_WRITE32(reg, value)                                 OS_WritePeripheral32(OS_AREA_DRV_DMA,(volatile uint32*)(volatile void*)(&(reg)),(value))
#define DMA_RUNTIME_MODIFY32(reg,clearmask,setmask)                     OS_ModifyPeripheral32(OS_AREA_DRV_DMA,(volatile uint32*)(volatile void*)(&(reg)),(clearmask),(setmask));
#if (DMA_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)                            
  #define DMA_RUNTIME_USER_MODE_OS_API_READ32(reg)                           OS_ReadPeripheral32(OS_AREA_DRV_DMA,(volatile uint32*)(volatile void*)(&(reg)))
#endif                                                                       
#endif /* DMA_USER_MODE_RUNTIME_API_ENABLE == STD_ON  */
 #endif 