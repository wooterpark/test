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
**  FILENAME  : Dma_PBCfg.c                                                  **
**                                                                           **
**  $CC VERSION : \main\13 $                                                 **
**                                                                           **
**  DATE, TIME: 2021-09-29, 16:08:33                                         **
**                                                                           **
**  GENERATOR : Build b141014-0350                                           **
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
/*******************************************************************************
**                                                                            **
**  TRACEBILITY : 
    [cover parentID = DS_NAS_DMA_PR69_PR469_PR122_PR123,DS_NAS_DMA_PR647,
    DS_NAS_DMA_PR446,DS_NAS_DMA_PR699,DS_NAS_DMA_PR709,
    SAS_NAS_DMA_PR914,SAS_NAS_DMA_PR915,SAS_NAS_DMA_PR916,
    SAS_NAS_DMA_PR82,DS_NAS_DMA_PR704,SAS_NAS_DMA_PR60,
    DS_NAS_DMA_PR707,DS_NAS_DMA_PR708,DS_NAS_DMA_PR712
    ]
**  [/cover]                                                                 **
*******************************************************************************/

/*******************************************************************************
**                            Includes                                        **
*******************************************************************************/
/* Include module header file */
#include "Dma.h"
/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
/*
                     Container: DmaChannelConfiguration
*/

/* Memory Mapping the configuration constant */
#define DMA_START_SEC_POSTBUILDCFG
#include "MemMap.h"

/************************** DMA Channel Config Root ***************************/

/******** Configuration of channels in DmaConfigSet(0) ********/
static const Dma_ChannelConfigType Dma_kChannelConfigRoot0[]=
{
 {
/* Configuration for DMA Channel(52) */
  0X10300000U, /* Configuration for DMA register CHCFGR */
  0X00301289U, /* Configuration for DMA register ADICR */
  0X01U,       /* Configuration for DMA register MODE */
  0X00U,       /* Configuration for DMA register HRR */
  52U           /*DMA channel ID*/
 },
 {
/* Configuration for DMA Channel(51) */
  0X10300000U, /* Configuration for DMA register CHCFGR */
  0X00301289U, /* Configuration for DMA register ADICR */
  0X01U,       /* Configuration for DMA register MODE */
  0X00U,       /* Configuration for DMA register HRR */
  51U           /*DMA channel ID*/
 },
 {
/* Configuration for DMA Channel(50) */
  0X00300000U, /* Configuration for DMA register CHCFGR */
  0X00301289U, /* Configuration for DMA register ADICR */
  0X01U,       /* Configuration for DMA register MODE */
  0X00U,       /* Configuration for DMA register HRR */
  50U           /*DMA channel ID*/
 },
 {
/* Configuration for DMA Channel(32) */
  0X00100000U, /* Configuration for DMA register CHCFGR */
  0X04303088U, /* Configuration for DMA register ADICR */
  0X01U,       /* Configuration for DMA register MODE */
  0X00U,       /* Configuration for DMA register HRR */
  32U           /*DMA channel ID*/
 },
 {
/* Configuration for DMA Channel(45) */
  0X10300000U, /* Configuration for DMA register CHCFGR */
  0X0E306088U, /* Configuration for DMA register ADICR */
  0X01U,       /* Configuration for DMA register MODE */
  0X00U,       /* Configuration for DMA register HRR */
  45U           /*DMA channel ID*/
 },
 {
/* Configuration for DMA Channel(44) */
  0X00300000U, /* Configuration for DMA register CHCFGR */
  0X0E306088U, /* Configuration for DMA register ADICR */
  0X01U,       /* Configuration for DMA register MODE */
  0X00U,       /* Configuration for DMA register HRR */
  44U           /*DMA channel ID*/
 },
 {
/* Configuration for DMA Channel(43) */
  0X10300000U, /* Configuration for DMA register CHCFGR */
  0X0E306088U, /* Configuration for DMA register ADICR */
  0X01U,       /* Configuration for DMA register MODE */
  0X00U,       /* Configuration for DMA register HRR */
  43U           /*DMA channel ID*/
 },
 {
/* Configuration for DMA Channel(42) */
  0X00300000U, /* Configuration for DMA register CHCFGR */
  0X0E306088U, /* Configuration for DMA register ADICR */
  0X01U,       /* Configuration for DMA register MODE */
  0X00U,       /* Configuration for DMA register HRR */
  42U           /*DMA channel ID*/
 }
};

/*************************** DMA Config Root **********************************/

const Dma_ConfigType Dma_ConfigRoot[1]=
{
/*************** Configuration for DmaConfigSet(0) ***************/
 {
  &Dma_kChannelConfigRoot0[0U], /* Address of channel config root
                                  for DMA configuration [0] */
  0X00000000U, /* Configuration for DMA register PRR0 */
  0X00000000U, /* Configuration for DMA register PRR1 */
  0X05030000U, /* Configuration for DMA register ERR0 */
  0X05030000U, /* Configuration for DMA register ERR1 */
  8U           /*Number of channels configured*/
 }
};

#define DMA_STOP_SEC_POSTBUILDCFG
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is 
 allowed only for MemMap.h*/
#include "MemMap.h"
