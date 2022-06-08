/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2013)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  $FILENAME   : Dma_Dbg.h $                                                **
**                                                                           **
**  $CC VERSION : \main\2 $                                                  **
**                                                                           **
**  $DATE       : 2013-09-13 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                 - Debug information of DMA driver.                        **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/

#ifndef DMA_DBG_H
#define DMA_DBG_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Dma.h"

/*******************************************************************************
**                            Global Variables                               **
*******************************************************************************/
#if ( DMA_DEBUG_SUPPORT == STD_ON )

#define DMA_START_SEC_VAR_8BIT
#include "MemMap.h"

extern uint8 Dma_DriverState;
extern uint8 Dma_ChannelState[DMA_NUM_OF_CHANNELS];

#define DMA_STOP_SEC_VAR_8BIT
#include "MemMap.h"

#endif /* End of DMA_DEBUG_SUPPORT */

#endif /* DMA_DBG_H */