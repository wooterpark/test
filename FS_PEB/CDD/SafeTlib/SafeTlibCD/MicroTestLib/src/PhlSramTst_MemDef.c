/*******************************************************************************
** Copyright (C) Infineon Technologies (2015)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**   $FILENAME   : PhlSramTst_MemDef.c $                                      **
**                                                                            **
**   $CC VERSION : \main\13 $                                                 **
**                                                                            **
**   $DATE       : 2015-09-14 $                                               **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon AURIX                                                **
**                                                                            **
**  COMPILER  : Tasking                                                       **
**                                                                            **
**  AUTHOR    : SafeTlib Team                                                 **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  TRACEABILITY:                                                             **
**                                                                            **
**  DESCRIPTION  : This file contains                                         **
**                 - Peripheral SRAM Memory Definitions for the Peripheral    **
**                   SRAM test                                                **
**                                                                            **
**                                                                            **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [Yes/No]: No                                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

#include "PhlSramTst_MemDef.h"
#include "PhlSramTst_Cfg.h"
#include "Mcal.h"
#include "Smu.h"
#include "ChipId.h"
/*******************************************************************************
**                      Local Macro Definitions                               **
*******************************************************************************/


/*******************************************************************************
**                      Local Type Definitions                                **
*******************************************************************************/

/*******************************************************************************
**                        Exported object definitions                          *
*******************************************************************************/

#if((CHIP_ID == 22U) ||(CHIP_ID == 21U))

#define IFX_PHL_SRAM_START_SEC_CONST_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"

/* Memory definition for TC22x MCAN SRAM: */
static const PhlSramTst_MemoryDefinitionType PhlSramTst_kMdMcan =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP4,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_4,          /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_5,          /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = SMU_ALARM_6,          /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_7,          /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 1U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 1U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 32U,                  /* Number of data bits            */
  .NrOfEccBits      = 7U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 1U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 5U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 6U,                   /* Second ECC bit to invert       */
  .TowerDepth       = 1216U                 /* Tower Depth                    */  
};

#define IFX_PHL_SRAM_STOP_SEC_CONST_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"

#define IFX_PHL_SRAM_START_SEC_CONST_32BIT_ASIL_B
#include "Ifx_MemMap.h"

/* Memory definitions of all Peripheral SRAMs: */
const PhlSramTst_MemoryDefinitionType* const
      PhlSramTst_kMemDef[PHLSRAMTST_MEMORY_COUNT] =
{
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 00: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 01: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 02: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 03: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 04: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 05: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 06: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 07: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 08: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 09: Reserved           */
  &PhlSramTst_kMdMcan,                        /* 10: MCAN0 SRAM         */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 11: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 12: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 13: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 14: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 15: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 16: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 17: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 18: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 19: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 20: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 21: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 22: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 23: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 24: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 25: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 26: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 27: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 28: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 29: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 30: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 31: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 32: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 33: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 34: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 35: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 36: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 37: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 38: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 39: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 40: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 41: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 42: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 43: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 44: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 45: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 46: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 47: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 48: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 49: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 50: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 51: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 52: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 53: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 54: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 55: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 56: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 57: Reserved           */
};
#define IFX_PHL_SRAM_STOP_SEC_CONST_32BIT_ASIL_B
#include "Ifx_MemMap.h" 

#define IFX_PHL_SRAM_START_SEC_CONST_8BIT_ASIL_B
#include "Ifx_MemMap.h"
/* Lookup table to get memory controller index from memory index: */
const uint8 PhlSramTst_kMcTable[PHLSRAMTST_MEMORY_COUNT] =
{
  PHLSRAMTST_MC_IDX_INVALID,  /* 00: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 01: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 02: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 03: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 04: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 05: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 06: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 07: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 08: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 09: Reserved           */
  36U,                        /* 10: MCAN0 SRAM         */
  PHLSRAMTST_MC_IDX_INVALID,  /* 11: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 12: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 13: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 14: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 15: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 16: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 17: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 18: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 19: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 20: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 21: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 22: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 23: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 24: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 25: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 26: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 27: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 28: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 29: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 30: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 31: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 32: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 33: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 34: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 35: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 36: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 37: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 38: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 39: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 40: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 41: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 42: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 43: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 44: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 45: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 46: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 47: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 48: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 49: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 50: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 51: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 52: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 53: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 54: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 55: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 56: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 57: Reserved           */
};
#define IFX_PHL_SRAM_STOP_SEC_CONST_8BIT_ASIL_B
#include "Ifx_MemMap.h"

#elif(CHIP_ID == 23U) 

#define IFX_PHL_SRAM_START_SEC_CONST_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"
/* Memory definition for TC23x ETHER_MAC SRAM: */
static const PhlSramTst_MemoryDefinitionType PhlSramTst_kMdEtherMac =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP4,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_16,         /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_17,         /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = SMU_ALARM_18,         /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_19,         /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 2U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 1U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 35U,                  /* Number of data bits            */
  .NrOfEccBits      = 7U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 1U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 0U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 1U,                   /* Second ECC bit to invert       */
  .TowerDepth       = 1024U,                /* Tower Depth                    */
};

/* Memory definition for TC23x MCAN SRAM: */
static const PhlSramTst_MemoryDefinitionType PhlSramTst_kMdMcan =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP4,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_4,          /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_5,          /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = SMU_ALARM_6,          /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_7,          /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 1U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 1U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 32U,                  /* Number of data bits            */
  .NrOfEccBits      = 7U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 1U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 5U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 6U,                   /* Second ECC bit to invert       */
  .TowerDepth       = 1216U                 /* Tower Depth                    */  
};

/* Memory definition for TC23x ERAY_OBF SRAM: */
static const PhlSramTst_MemoryDefinitionType PhlSramTst_kMdErayObf =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP4,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_8,          /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_9,          /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = SMU_ALARM_10,         /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_11,         /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 2U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 1U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 32U,                  /* Number of data bits            */
  .NrOfEccBits      = 7U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 1U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 5U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 6U,                   /* Second ECC bit to invert       */
  .TowerDepth       = 64U                   /* Tower Depth                    */  
};

/* Memory definition for TC23x ERAY_IBF_TBF SRAM: */
static const PhlSramTst_MemoryDefinitionType PhlSramTst_kMdErayIbfTbf =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP4,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_8,          /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_9,          /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = SMU_ALARM_10,         /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_11,         /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 4U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 1U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 32U,                  /* Number of data bits            */
  .NrOfEccBits      = 7U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 1U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 5U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 6U,                   /* Second ECC bit to invert       */
  .TowerDepth       = 128U,                 /* Tower Depth                    */  
};

/* Memory definition for TC23x ERAY_MBF SRAM: */
static const PhlSramTst_MemoryDefinitionType PhlSramTst_kMdErayMbf =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP4,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_8,          /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_9,          /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = SMU_ALARM_10,         /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_11,         /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 1U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 1U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 32U,                  /* Number of data bits            */
  .NrOfEccBits      = 7U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 1U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 5U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 6U,                   /* Second ECC bit to invert       */
  .TowerDepth       = 2048U,                /* Tower Depth                    */  
};

/* Memory definition for TC23x EMEM_LOWER SRAM: */
static const PhlSramTst_MemoryDefinitionType PhlSramTst_kMdEmemLower =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP4,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_12,         /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_13,         /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = PHLSRAMTST_SMU_NONE,  /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_15,         /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 2U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 1U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 128U,                 /* Number of data bits            */
  .NrOfEccBits      = 9U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 1U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 0U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 1U,                   /* Second ECC bit to invert       */
  .TowerDepth       = 2048U,                /* Tower Depth                    */
};


/* Memory definition for TC23x FFT0 SRAM: */
static const PhlSramTst_MemoryDefinitionType PhlSramTst_kMdFft0 =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP2,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_17,         /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_18,         /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = SMU_ALARM_19,         /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_20,         /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 4U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 1U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 64U,                  /* Number of data bits            */
  .NrOfEccBits      = 8U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 1U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 0U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 1U,                   /* Second ECC bit to invert       */
  .TowerDepth       = 2048U                  /* Tower Depth                    */  
};

/* Memory definition for TC23x FFT1 SRAM: */
static const PhlSramTst_MemoryDefinitionType PhlSramTst_kMdFft1 =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP2,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_17,         /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_18,         /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = SMU_ALARM_19,         /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_20,         /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 1U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 1U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 16U,                  /* Number of data bits            */
  .NrOfEccBits      = 6U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 1U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 0U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 1U,                   /* Second ECC bit to invert       */
  .TowerDepth       = 1024U                  /* Tower Depth                    */  
};

#define IFX_PHL_SRAM_STOP_SEC_CONST_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"

#define IFX_PHL_SRAM_START_SEC_CONST_32BIT_ASIL_B
#include "Ifx_MemMap.h"

/* Memory definitions of all Peripheral SRAMs: */
const PhlSramTst_MemoryDefinitionType* const
      PhlSramTst_kMemDef[PHLSRAMTST_MEMORY_COUNT] =
{
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 00: Reserved           */
  &PhlSramTst_kMdEtherMac,                    /* 01: ETHER_MAC SRAM     */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 02: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 03: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 04: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 05: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 06: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 07: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 08: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 09: Reserved           */
  &PhlSramTst_kMdMcan,                        /* 10: MCAN0 SRAM         */
  &PhlSramTst_kMdMcan,                        /* 11: MCAN1 SRAM         */
  &PhlSramTst_kMdErayObf,                     /* 12: ERAY0_OBF SRAM     */
  &PhlSramTst_kMdErayIbfTbf,                  /* 13: ERAY0_IBF_TBF SRAM */
  &PhlSramTst_kMdErayMbf,                     /* 14: ERAY0_MBF SRAM     */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 15: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 16: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 17: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 18: Reserved           */
  &PhlSramTst_kMdEmemLower,                   /* 19: EMEM_LOWER0 SRAM   */
  &PhlSramTst_kMdEmemLower,                   /* 20: EMEM_LOWER1 SRAM   */
  &PhlSramTst_kMdEmemLower,                   /* 21: EMEM_LOWER2 SRAM   */
  &PhlSramTst_kMdEmemLower,                   /* 22: EMEM_LOWER3 SRAM   */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 23: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 24: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 25: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 26: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 27: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 28: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 29: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 30: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 31: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 32: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 33: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 34: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 35: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 36: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 37: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 38: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 39: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 40: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 41: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 42: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 43: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 44: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 45: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 46: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 47: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 48: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 49: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 50: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 51: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 52: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 53: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 54: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 55: Reserved           */
  &PhlSramTst_kMdFft0,                        /* 56: FFT0 SRAM          */
  &PhlSramTst_kMdFft1                         /* 57: FFT1 SRAM          */
};
#define IFX_PHL_SRAM_STOP_SEC_CONST_32BIT_ASIL_B
#include "Ifx_MemMap.h"

#define IFX_PHL_SRAM_START_SEC_CONST_8BIT_ASIL_B
#include "Ifx_MemMap.h"

/* Lookup table to get memory controller index from memory index: */
const uint8 PhlSramTst_kMcTable[PHLSRAMTST_MEMORY_COUNT] =
{
  PHLSRAMTST_MC_IDX_INVALID,  /* 00: Reserved           */
  22U,                        /* 01: ETHER_MAC SRAM     */
  PHLSRAMTST_MC_IDX_INVALID,  /* 02: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 03: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 04: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 05: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 06: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 07: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 08: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 09: Reserved           */
  36U,                        /* 10: MCAN0 SRAM         */
  37U,                        /* 11: MCAN1 SRAM         */
  38U,                        /* 12: ERAY0_OBF SRAM     */
  39U,                        /* 13: ERAY0_IBF_TBF SRAM */
  40U,                        /* 14: ERAY0_MBF SRAM     */
  PHLSRAMTST_MC_IDX_INVALID,  /* 15: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 16: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 17: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 18: Reserved           */
  46U,                        /* 19: EMEM_LOWER0 SRAM   */
  47U,                        /* 20: EMEM_LOWER1 SRAM   */
  48U,                        /* 21: EMEM_LOWER2 SRAM   */
  49U,                        /* 22: EMEM_LOWER3 SRAM   */
  PHLSRAMTST_MC_IDX_INVALID,  /* 23: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 24: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 25: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 26: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 27: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 28: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 29: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 30: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 31: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 32: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 33: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 34: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 35: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 36: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 37: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 38: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 39: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 40: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 41: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 42: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 43: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 44: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 45: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 46: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 47: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 48: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 49: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 50: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 51: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 52: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 53: Reserved           */
  84U,                        /* 54: EMEM_XTM0 SRAM     */
  85U,                        /* 55: EMEM_XTM1 SRAM     */
  86U,                        /* 56: FFT0 SRAM          */
  87U                         /* 57: FFT1 SRAM          */
};
#define IFX_PHL_SRAM_STOP_SEC_CONST_8BIT_ASIL_B
#include "Ifx_MemMap.h"

#elif(CHIP_ID == 26U)

#define IFX_PHL_SRAM_START_SEC_CONST_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"

/* Memory definition for TC26x ETHER_MAC SRAM: */
static const PhlSramTst_MemoryDefinitionType PhlSramTst_kMdEtherMac =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP4,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_16,         /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_17,         /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = SMU_ALARM_18,         /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_19,         /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 2U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 1U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 35U,                  /* Number of data bits            */
  .NrOfEccBits      = 7U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 1U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 0U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 1U,                   /* Second ECC bit to invert       */
  .TowerDepth       = 1024U,                /* Tower Depth                    */  
};

/* Memory definition for TC26x GTM_FIFO SRAM: */
static const PhlSramTst_MemoryDefinitionType PhlSramTst_kMdGtmFifo =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP4,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_0,          /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_1,          /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = SMU_ALARM_2,          /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_3,          /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 1U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 1U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 29U,                  /* Number of data bits            */
  .NrOfEccBits      = 7U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 1U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 0U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 1U,                   /* Second ECC bit to invert       */
  .TowerDepth       = 1024U                 /* Tower Depth                    */  
};

/* Memory definition for TC26x GTM_MCS SRAM: */
static const PhlSramTst_MemoryDefinitionType PhlSramTst_kMdGtmMcs0 =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP4,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_0,          /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_1,          /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = SMU_ALARM_2,          /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_3,          /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 3U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 1U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 32U,                  /* Number of data bits            */
  .NrOfEccBits      = 8U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 1U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 0U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 1U,                   /* Second ECC bit to invert       */
  .TowerDepth       = 1024U                 /* Tower Depth                    */  
};

/* Memory definition for TC26x GTM_MCS SRAM: */
static const PhlSramTst_MemoryDefinitionType PhlSramTst_kMdGtmMcs1 =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP4,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_0,          /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_1,          /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = SMU_ALARM_2,          /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_3,          /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 3U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 1U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 32U,                  /* Number of data bits            */
  .NrOfEccBits      = 8U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 1U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 0U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 1U,                   /* Second ECC bit to invert       */
  .TowerDepth       = 512U                  /* Tower Depth                    */
};

/* Memory definition for TC26x GTM_DPLL1A SRAM: */
static const PhlSramTst_MemoryDefinitionType PhlSramTst_kMdGtmDpll1A =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP4,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_0,          /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_1,          /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = SMU_ALARM_2,          /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_3,          /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 1U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 1U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 24U,                  /* Number of data bits            */
  .NrOfEccBits      = 7U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 1U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 0U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 1U,                   /* Second ECC bit to invert       */
  .TowerDepth       = 128U                  /* Tower Depth                    */
};

/* Memory definition for TC26x GTM_DPLL1B SRAM: */
static const PhlSramTst_MemoryDefinitionType PhlSramTst_kMdGtmDpll1B =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP4,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_0,          /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_1,          /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = SMU_ALARM_2,          /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_3,          /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 1U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 1U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 24U,                  /* Number of data bits            */
  .NrOfEccBits      = 7U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 1U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 0U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 1U,                   /* Second ECC bit to invert       */
  .TowerDepth       = 384U                  /* Tower Depth                    */
};

/* Memory definition for TC26x GTM_DPLL2 SRAM: */
static const PhlSramTst_MemoryDefinitionType PhlSramTst_kMdGtmDpll2 =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP4,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_0,          /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_1,          /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = SMU_ALARM_2,          /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_3,          /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 1U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 1U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 24U,                  /* Number of data bits            */
  .NrOfEccBits      = 7U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 1U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 0U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 1U,                   /* Second ECC bit to invert       */
  .TowerDepth       = 1024U                  /* Tower Depth                    */
};

/* Memory definition for TC26x PSI5 SRAM: */
static const PhlSramTst_MemoryDefinitionType PhlSramTst_kMdPsi5 =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP4,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_16,         /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_17,         /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = SMU_ALARM_18,         /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_19,         /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 1U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 1U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 32U,                  /* Number of data bits            */
  .NrOfEccBits      = 8U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 1U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 0U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 1U,                   /* Second ECC bit to invert       */
  .TowerDepth       = 192U                  /* Tower Depth                    */
};

/* Memory definition for TC26x SADMA SRAM: */
static const PhlSramTst_MemoryDefinitionType PhlSramTst_kMdSadma =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP4,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_16,         /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_17,         /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = SMU_ALARM_18,         /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_19,         /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 4U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 1U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 64U,                  /* Number of data bits            */
  .NrOfEccBits      = 8U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 1U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 0U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 1U,                   /* Second ECC bit to invert       */
  .TowerDepth       = 64U                   /* Tower Depth                    */
};

/* Memory definition for TC26x MCAN SRAM: */
static const PhlSramTst_MemoryDefinitionType PhlSramTst_kMdMcan =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP4,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_4,          /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_5,          /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = SMU_ALARM_6,          /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_7,          /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 1U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 1U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 32U,                  /* Number of data bits            */
  .NrOfEccBits      = 8U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 1U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 0U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 1U,                   /* Second ECC bit to invert       */
  .TowerDepth       = 2496U                 /* Tower Depth                    */
};

/* Memory definition for TC26x ERAY_OBF SRAM: */
static const PhlSramTst_MemoryDefinitionType PhlSramTst_kMdErayObf =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP4,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_8,          /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_9,          /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = SMU_ALARM_10,         /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_11,         /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 2U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 1U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 32U,                  /* Number of data bits            */
  .NrOfEccBits      = 8U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 1U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 0U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 1U,                   /* Second ECC bit to invert       */
  .TowerDepth       = 64U                   /* Tower Depth                    */
};

/* Memory definition for TC26x ERAY_IBF_TBF SRAM: */
static const PhlSramTst_MemoryDefinitionType PhlSramTst_kMdErayIbfTbf =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP4,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_8,          /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_9,          /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = SMU_ALARM_10,         /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_11,         /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 4U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 1U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 32U,                  /* Number of data bits            */
  .NrOfEccBits      = 8U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 1U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 0U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 1U,                   /* Second ECC bit to invert       */
  .TowerDepth       = 128U                  /* Tower Depth                    */
};

/* Memory definition for TC26x ERAY_MBF SRAM: */
static const PhlSramTst_MemoryDefinitionType PhlSramTst_kMdErayMbf =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP4,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_8,          /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_9,          /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = SMU_ALARM_10,         /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_11,         /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 1U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 1U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 32U,                  /* Number of data bits            */
  .NrOfEccBits      = 8U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 1U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 0U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 1U,                   /* Second ECC bit to invert       */
  .TowerDepth       = 2048U                 /* Tower Depth                    */
};

/* Memory definition for TC26x EMEM_LOWER SRAM: */
static const PhlSramTst_MemoryDefinitionType PhlSramTst_kMdEmemLower =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP4,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_12,         /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_13,         /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = PHLSRAMTST_SMU_NONE,  /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_15,         /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 2U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 1U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 128U,                 /* Number of data bits            */
  .NrOfEccBits      = 9U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 1U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 0U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 1U,                   /* Second ECC bit to invert       */
  .TowerDepth       = 2048U                 /* Tower Depth - not used         */
};

/* Memory definition for TC26x CIF0 SRAM: */
static const PhlSramTst_MemoryDefinitionType PhlSramTst_kMdCif0 =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP4,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_16,         /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_17,         /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = PHLSRAMTST_SMU_NONE,  /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_19,         /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 4U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 1U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 8U,                   /* Number of data bits            */
  .NrOfEccBits      = 6U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 1U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 0U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 1U,                   /* Second ECC bit to invert       */
  .TowerDepth       = 5120U                 /* Tower Depth                    */
};

/* Memory definition for TC26x CIF1 SRAM: */
static const PhlSramTst_MemoryDefinitionType PhlSramTst_kMdCif1 =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP4,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_16,         /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_17,         /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = PHLSRAMTST_SMU_NONE,  /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_19,         /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 2U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 1U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 8U,                   /* Number of data bits            */
  .NrOfEccBits      = 6U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 1U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 0U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 1U,                   /* Second ECC bit to invert       */
  .TowerDepth       = 384U                  /* Tower Depth                    */
};

/* Memory definition for TC26x CIF2 SRAM: */
static const PhlSramTst_MemoryDefinitionType PhlSramTst_kMdCif2 =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP4,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_16,         /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_17,         /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = PHLSRAMTST_SMU_NONE,  /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_19,         /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 1U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 1U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 36U,                  /* Number of data bits            */
  .NrOfEccBits      = 8U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 1U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 0U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 1U,                   /* Second ECC bit to invert       */
  .TowerDepth       = 512U                  /* Tower Depth                    */
};

/* Memory definition for TC26x FFT0 SRAM: */
static const PhlSramTst_MemoryDefinitionType PhlSramTst_kMdFft0 =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP2,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_17,         /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_18,         /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = SMU_ALARM_19,         /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_20,         /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 4U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 1U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 64U,                  /* Number of data bits            */
  .NrOfEccBits      = 8U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 1U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 0U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 1U,                   /* Second ECC bit to invert       */
  .TowerDepth       = 1024U                 /* Tower Depth                    */
};

/* Memory definition for TC26x FFT1 SRAM: */
static const PhlSramTst_MemoryDefinitionType PhlSramTst_kMdFft1 =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP2,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_17,         /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_18,         /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = SMU_ALARM_19,         /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_20,         /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 1U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 1U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 16U,                  /* Number of data bits            */
  .NrOfEccBits      = 6U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 1U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 0U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 1U,                   /* Second ECC bit to invert       */
  .TowerDepth       = 512U                  /* Tower Depth                    */
};

#define IFX_PHL_SRAM_STOP_SEC_CONST_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"

#define IFX_PHL_SRAM_START_SEC_CONST_32BIT_ASIL_B
#include "Ifx_MemMap.h"

/* Memory definitions of all Peripheral SRAMs: */
const PhlSramTst_MemoryDefinitionType* const
      PhlSramTst_kMemDef[PHLSRAMTST_MEMORY_COUNT] =
{
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 00: Reserved           */
  &PhlSramTst_kMdEtherMac,                    /* 01: ETHER_MAC SRAM     */
  &PhlSramTst_kMdGtmFifo,                     /* 02: GTM_FIFO SRAM      */
  &PhlSramTst_kMdGtmMcs0,                     /* 03: GTM_MCS0 SRAM      */
  &PhlSramTst_kMdGtmMcs1,                     /* 04: GTM_MCS1 SRAM      */
  &PhlSramTst_kMdGtmDpll1A,                   /* 05: GTM_DPLL1A SRAM    */
  &PhlSramTst_kMdGtmDpll1B,                   /* 06: GTM_DPLL1B SRAM    */
  &PhlSramTst_kMdGtmDpll2,                    /* 07: GTM_DPLL2 SRAM     */
  &PhlSramTst_kMdPsi5,                        /* 08: PSI5 SRAM          */
  &PhlSramTst_kMdSadma,                       /* 09: SADMA SRAM         */
  &PhlSramTst_kMdMcan,                        /* 10: MCAN0 SRAM         */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 11: Reserved           */
  &PhlSramTst_kMdErayObf,                     /* 12: ERAY0_OBF SRAM     */
  &PhlSramTst_kMdErayIbfTbf,                  /* 13: ERAY0_IBF_TBF SRAM */
  &PhlSramTst_kMdErayMbf,                     /* 14: ERAY0_MBF SRAM     */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 15: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 16: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 17: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 18: Reserved           */
  &PhlSramTst_kMdEmemLower,                   /* 19: EMEM_LOWER0 SRAM   */
  &PhlSramTst_kMdEmemLower,                   /* 20: EMEM_LOWER1 SRAM   */
  &PhlSramTst_kMdEmemLower,                   /* 21: EMEM_LOWER2 SRAM   */
  &PhlSramTst_kMdEmemLower,                   /* 22: EMEM_LOWER3 SRAM   */
  &PhlSramTst_kMdEmemLower,                   /* 23: EMEM_LOWER4 SRAM   */
  &PhlSramTst_kMdEmemLower,                   /* 24: EMEM_LOWER5 SRAM   */
  &PhlSramTst_kMdEmemLower,                   /* 25: EMEM_LOWER6 SRAM   */
  &PhlSramTst_kMdEmemLower,                   /* 26: EMEM_LOWER7 SRAM   */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 27: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 28: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 29: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 30: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 31: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 32: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 33: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 34: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 35: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 36: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 37: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 38: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 39: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 40: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 41: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 42: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 43: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 44: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 45: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 46: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 47: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 48: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 49: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 50: Reserved           */
  &PhlSramTst_kMdCif0,                        /* 51: CIF0 SRAM          */
  &PhlSramTst_kMdCif1,                        /* 52: CIF1 SRAM          */
  &PhlSramTst_kMdCif2,                        /* 53: CIF2 SRAM          */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 54: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 55: Reserved           */
  &PhlSramTst_kMdFft0,                        /* 56: FFT0 SRAM          */
  &PhlSramTst_kMdFft1,                        /* 57: FFT1 SRAM          */
};
#define IFX_PHL_SRAM_STOP_SEC_CONST_32BIT_ASIL_B
#include "Ifx_MemMap.h"

#define IFX_PHL_SRAM_START_SEC_CONST_8BIT_ASIL_B
#include "Ifx_MemMap.h"

/* Lookup table to get memory controller index from memory index: */
const uint8 PhlSramTst_kMcTable[PHLSRAMTST_MEMORY_COUNT] =
{
  PHLSRAMTST_MC_IDX_INVALID,  /* 00: Reserved           */
  22U,                        /* 01: ETHER_MAC SRAM     */
  28U,                        /* 02: GTM_FIFO SRAM      */
  29U,                        /* 03: GTM_MCS0 SRAM      */
  30U,                        /* 04: GTM_MCS1 SRAM      */
  31U,                        /* 05: GTM_DPLL1A SRAM    */
  32U,                        /* 06: GTM_DPLL1B SRAM    */
  33U,                        /* 07: GTM_DPLL2 SRAM     */
  34U,                        /* 08: PSI5 SRAM          */
  83U,                        /* 09: SADMA SRAM         */
  36U,                        /* 10: MCAN0 SRAM         */
  PHLSRAMTST_MC_IDX_INVALID,  /* 11: Reserved           */
  38U,                        /* 12: ERAY0_OBF SRAM     */
  39U,                        /* 13: ERAY0_IBF_TBF SRAM */
  40U,                        /* 14: ERAY0_MBF SRAM     */
  PHLSRAMTST_MC_IDX_INVALID,  /* 15: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 16: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 17: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 18: Reserved           */
  46U,                        /* 19: EMEM_LOWER0 SRAM   */
  47U,                        /* 20: EMEM_LOWER1 SRAM   */
  48U,                        /* 21: EMEM_LOWER2 SRAM   */
  49U,                        /* 22: EMEM_LOWER3 SRAM   */
  50U,                        /* 23: EMEM_LOWER4 SRAM   */
  51U,                        /* 24: EMEM_LOWER5 SRAM   */
  52U,                        /* 25: EMEM_LOWER6 SRAM   */
  53U,                        /* 26: EMEM_LOWER7 SRAM   */
  PHLSRAMTST_MC_IDX_INVALID,  /* 27: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 28: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 29: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 30: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 31: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 32: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 33: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 34: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 35: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 36: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 37: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 38: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 39: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 40: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 41: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 42: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 43: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 44: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 45: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 46: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 47: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 48: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 49: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 50: Reserved           */
  78U,                        /* 51: CIF0 SRAM          */
  80U,                        /* 52: CIF1 SRAM          */
  81U,                        /* 53: CIF2 SRAM          */
  84U,                        /* 54: EMEM_XTM0 SRAM     */
  85U,                        /* 55: EMEM_XTM1 SRAM     */
  86U,                        /* 56: FFT0 SRAM          */
  87U,                        /* 57: FFT1 SRAM          */
};
#define IFX_PHL_SRAM_STOP_SEC_CONST_8BIT_ASIL_B
#include "Ifx_MemMap.h"

#elif(CHIP_ID == 27U)

#define IFX_PHL_SRAM_START_SEC_CONST_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"

/* Memory definition for TC27x ETHER_MAC SRAM: */
static const PhlSramTst_MemoryDefinitionType PhlSramTst_kMdEtherMac =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP4,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_16,         /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_17,         /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = SMU_ALARM_18,         /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_19,         /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 2U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 1U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 35U,                  /* Number of data bits            */
  .NrOfEccBits      = 7U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 1U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 0U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 1U,                   /* Second ECC bit to invert       */
  .TowerDepth       = 1024U                 /* Tower Depth                    */
};

/* Memory definition for TC27x GTM_FIFO SRAM: */
static const PhlSramTst_MemoryDefinitionType PhlSramTst_kMdGtmFifo =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP4,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_0,          /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_1,          /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = SMU_ALARM_2,          /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_3,          /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 1U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 1U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 29U,                  /* Number of data bits            */
  .NrOfEccBits      = 7U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 1U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 0U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 1U,                   /* Second ECC bit to invert       */
  .TowerDepth       = 1024U                 /* Tower Depth                    */
};

/* Memory definition for TC27x GTM_MCS0 SRAM: */
static const PhlSramTst_MemoryDefinitionType PhlSramTst_kMdGtmMcs0 =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP4,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_0,          /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_1,          /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = SMU_ALARM_2,          /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_3,          /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 4U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 1U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 32U,                  /* Number of data bits            */
  .NrOfEccBits      = 8U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 1U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 0U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 1U,                   /* Second ECC bit to invert       */
  .TowerDepth       = 1024U                 /* Tower Depth                    */
};

/* Memory definition for TC27x GTM_MCS1 SRAM: */
static const PhlSramTst_MemoryDefinitionType PhlSramTst_kMdGtmMcs1 =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP4,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_0,          /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_1,          /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = SMU_ALARM_2,          /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_3,          /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 4U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 1U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 32U,                  /* Number of data bits            */
  .NrOfEccBits      = 8U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 1U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 0U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 1U,                   /* Second ECC bit to invert       */
  .TowerDepth       = 512U                 /* Tower Depth                    */
};

/* Memory definition for TC27x GTM_DPLL1A SRAM: */
static const PhlSramTst_MemoryDefinitionType PhlSramTst_kMdGtmDpll1A =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP4,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_0,          /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_1,          /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = SMU_ALARM_2,          /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_3,          /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 1U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 1U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 24U,                  /* Number of data bits            */
  .NrOfEccBits      = 7U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 1U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 0U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 1U,                   /* Second ECC bit to invert       */
  .TowerDepth       = 128U                  /* Tower Depth                    */
};

/* Memory definition for TC27x GTM_DPLL1B SRAM: */
static const PhlSramTst_MemoryDefinitionType PhlSramTst_kMdGtmDpll1B =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP4,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_0,          /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_1,          /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = SMU_ALARM_2,          /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_3,          /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 1U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 1U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 24U,                  /* Number of data bits            */
  .NrOfEccBits      = 7U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 1U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 0U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 1U,                   /* Second ECC bit to invert       */
  .TowerDepth       = 384U                  /* Tower Depth                    */
};

/* Memory definition for TC27x GTM_DPLL2 SRAM: */
static const PhlSramTst_MemoryDefinitionType PhlSramTst_kMdGtmDpll2 =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP4,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_0,          /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_1,          /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = SMU_ALARM_2,          /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_3,          /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 1U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 1U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 24U,                  /* Number of data bits            */
  .NrOfEccBits      = 7U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 1U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 0U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 1U,                   /* Second ECC bit to invert       */
  .TowerDepth       = 2048U                  /* Tower Depth                    */
};

/* Memory definition for TC27x PSI5 SRAM: */
static const PhlSramTst_MemoryDefinitionType PhlSramTst_kMdPsi5 =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP4,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_16,         /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_17,         /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = SMU_ALARM_18,         /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_19,         /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 1U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 1U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 32U,                  /* Number of data bits            */
  .NrOfEccBits      = 8U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 1U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 0U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 1U,                   /* Second ECC bit to invert       */
  .TowerDepth       = 192U                  /* Tower Depth                    */
};

/* Memory definition for TC27x SADMA SRAM: */
static const PhlSramTst_MemoryDefinitionType PhlSramTst_kMdSadma =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP4,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_16,         /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_17,         /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = SMU_ALARM_18,         /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_19,         /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 4U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 1U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 64U,                  /* Number of data bits            */
  .NrOfEccBits      = 8U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 1U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 0U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 1U,                   /* Second ECC bit to invert       */
  .TowerDepth       = 64U                   /* Tower Depth                    */  
};

/* Memory definition for TC27x MCAN SRAM: */
static const PhlSramTst_MemoryDefinitionType PhlSramTst_kMdMcan =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP4,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_4,          /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_5,          /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = SMU_ALARM_6,          /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_7,          /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 1U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 1U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 32U,                  /* Number of data bits            */
  .NrOfEccBits      = 8U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 1U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 0U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 1U,                   /* Second ECC bit to invert       */
  .TowerDepth       = 2368U                  /* Tower Depth                    */
};

/* Memory definition for TC27x ERAY_OBF SRAM: */
static const PhlSramTst_MemoryDefinitionType PhlSramTst_kMdErayObf =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP4,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_8,          /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_9,          /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = SMU_ALARM_10,         /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_11,         /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 2U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 1U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 32U,                  /* Number of data bits            */
  .NrOfEccBits      = 8U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 1U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 0U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 1U,                   /* Second ECC bit to invert       */
  .TowerDepth       = 64U                   /* Tower Depth                    */
};

/* Memory definition for TC27x ERAY_IBF_TBF SRAM: */
static const PhlSramTst_MemoryDefinitionType PhlSramTst_kMdErayIbfTbf =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP4,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_8,          /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_9,          /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = SMU_ALARM_10,         /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_11,         /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 4U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 1U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 32U,                  /* Number of data bits            */
  .NrOfEccBits      = 8U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 1U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 0U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 1U,                   /* Second ECC bit to invert       */
  .TowerDepth       = 128U                  /* Tower Depth                    */
};

/* Memory definition for TC27x ERAY_MBF SRAM: */
static const PhlSramTst_MemoryDefinitionType PhlSramTst_kMdErayMbf =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP4,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_8,          /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_9,          /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = SMU_ALARM_10,         /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_11,         /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 1U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 1U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 32U,                  /* Number of data bits            */
  .NrOfEccBits      = 8U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 1U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 0U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 1U,                   /* Second ECC bit to invert       */
  .TowerDepth       = 2048U                 /* Tower Depth                    */
};

/* Memory definition for TC27x EMEM_LOWER SRAM: */
static const PhlSramTst_MemoryDefinitionType PhlSramTst_kMdEmemLower =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP4,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_12,         /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_13,         /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = PHLSRAMTST_SMU_NONE,  /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_15,         /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 2U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 1U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 128U,                 /* Number of data bits            */
  .NrOfEccBits      = 9U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 1U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 0U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 1U,                   /* Second ECC bit to invert       */
  .TowerDepth       = 2048U                 /* Tower Depth                    */
};

/* Memory definition for TC27x CIF0 SRAM: */
static const PhlSramTst_MemoryDefinitionType PhlSramTst_kMdCif0 =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP4,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_16,         /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_17,         /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = PHLSRAMTST_SMU_NONE,  /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_19,         /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 4U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 1U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 8U,                   /* Number of data bits            */
  .NrOfEccBits      = 6U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 1U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 0U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 1U,                   /* Second ECC bit to invert       */
  .TowerDepth       = 5120U                 /* Tower Depth                    */
};

/* Memory definition for TC27x CIF1 SRAM: */
static const PhlSramTst_MemoryDefinitionType PhlSramTst_kMdCif1 =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP4,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_16,         /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_17,         /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = PHLSRAMTST_SMU_NONE,  /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_19,         /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 2U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 1U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 8U,                   /* Number of data bits            */
  .NrOfEccBits      = 6U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 1U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 0U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 1U,                   /* Second ECC bit to invert       */
  .TowerDepth       = 384U                  /* Tower Depth                    */
};

/* Memory definition for TC27x CIF2 SRAM: */
static const PhlSramTst_MemoryDefinitionType PhlSramTst_kMdCif2 =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP4,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_16,         /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_17,         /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = PHLSRAMTST_SMU_NONE,  /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_19,         /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 1U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 1U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 36U,                  /* Number of data bits            */
  .NrOfEccBits      = 8U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 1U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 0U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 1U,                   /* Second ECC bit to invert       */
  .TowerDepth       = 512U                  /* Tower Depth                    */
};

#define IFX_PHL_SRAM_STOP_SEC_CONST_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"

#define IFX_PHL_SRAM_START_SEC_CONST_32BIT_ASIL_B
#include "Ifx_MemMap.h"

/* Memory definitions of all Peripheral SRAMs: */
const PhlSramTst_MemoryDefinitionType* const
      PhlSramTst_kMemDef[PHLSRAMTST_MEMORY_COUNT] =
{
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 00: Reserved           */
  &PhlSramTst_kMdEtherMac,                    /* 01: ETHER_MAC SRAM     */
  &PhlSramTst_kMdGtmFifo,                     /* 02: GTM_FIFO SRAM      */
  &PhlSramTst_kMdGtmMcs0,                     /* 03: GTM_MCS0 SRAM      */
  &PhlSramTst_kMdGtmMcs1,                     /* 04: GTM_MCS1 SRAM      */
  &PhlSramTst_kMdGtmDpll1A,                   /* 05: GTM_DPLL1A SRAM    */
  &PhlSramTst_kMdGtmDpll1B,                   /* 06: GTM_DPLL1B SRAM    */
  &PhlSramTst_kMdGtmDpll2,                    /* 07: GTM_DPLL2 SRAM     */
  &PhlSramTst_kMdPsi5,                        /* 08: PSI5 SRAM          */
  &PhlSramTst_kMdSadma,                       /* 09: SADMA SRAM         */
  &PhlSramTst_kMdMcan,                        /* 10: MCAN0 SRAM         */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 11: Reserved           */
  &PhlSramTst_kMdErayObf,                     /* 12: ERAY0_OBF SRAM     */
  &PhlSramTst_kMdErayIbfTbf,                  /* 13: ERAY0_IBF_TBF SRAM */
  &PhlSramTst_kMdErayMbf,                     /* 14: ERAY0_MBF SRAM     */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 15: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 16: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 17: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 18: Reserved           */
  &PhlSramTst_kMdEmemLower,                   /* 19: EMEM_LOWER0 SRAM   */
  &PhlSramTst_kMdEmemLower,                   /* 20: EMEM_LOWER1 SRAM   */
  &PhlSramTst_kMdEmemLower,                   /* 21: EMEM_LOWER2 SRAM   */
  &PhlSramTst_kMdEmemLower,                   /* 22: EMEM_LOWER3 SRAM   */
  &PhlSramTst_kMdEmemLower,                   /* 23: EMEM_LOWER4 SRAM   */
  &PhlSramTst_kMdEmemLower,                   /* 24: EMEM_LOWER5 SRAM   */
  &PhlSramTst_kMdEmemLower,                   /* 25: EMEM_LOWER6 SRAM   */
  &PhlSramTst_kMdEmemLower,                   /* 26: EMEM_LOWER7 SRAM   */
  &PhlSramTst_kMdEmemLower,                   /* 27: EMEM_LOWER8 SRAM   */
  &PhlSramTst_kMdEmemLower,                   /* 28: EMEM_LOWER9 SRAM   */
  &PhlSramTst_kMdEmemLower,                   /* 29: EMEM_LOWER10 SRAM  */
  &PhlSramTst_kMdEmemLower,                   /* 30: EMEM_LOWER11 SRAM  */
  &PhlSramTst_kMdEmemLower,                   /* 31: EMEM_LOWER12 SRAM  */
  &PhlSramTst_kMdEmemLower,                   /* 32: EMEM_LOWER13 SRAM  */
  &PhlSramTst_kMdEmemLower,                   /* 33: EMEM_LOWER14 SRAM  */
  &PhlSramTst_kMdEmemLower,                   /* 34: EMEM_LOWER15 SRAM  */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 35: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 36: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 37: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 38: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 39: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 40: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 41: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 42: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 43: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 44: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 45: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 46: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 47: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 48: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 49: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 50: Reserved           */
  &PhlSramTst_kMdCif0,                        /* 51: CIF0 SRAM          */
  &PhlSramTst_kMdCif1,                        /* 52: CIF1 SRAM          */
  &PhlSramTst_kMdCif2,                        /* 53: CIF2 SRAM          */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 54: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 55: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 56: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR  /* 57: Reserved           */
};
#define IFX_PHL_SRAM_STOP_SEC_CONST_32BIT_ASIL_B
#include "Ifx_MemMap.h"

#define IFX_PHL_SRAM_START_SEC_CONST_8BIT_ASIL_B
#include "Ifx_MemMap.h"

/* Lookup table to get memory controller index from memory index: */
const uint8 PhlSramTst_kMcTable[PHLSRAMTST_MEMORY_COUNT] =
{
  PHLSRAMTST_MC_IDX_INVALID,  /* 00: Reserved           */
  22U,                        /* 01: ETHER_MAC SRAM     */
  28U,                        /* 02: GTM_FIFO SRAM      */
  29U,                        /* 03: GTM_MCS0 SRAM      */
  30U,                        /* 04: GTM_MCS1 SRAM      */
  31U,                        /* 05: GTM_DPLL1A SRAM    */
  32U,                        /* 06: GTM_DPLL1B SRAM    */
  33U,                        /* 07: GTM_DPLL2 SRAM     */
  34U,                        /* 08: PSI5 SRAM          */
  83U,                        /* 09: SADMA SRAM         */
  36U,                        /* 10: MCAN0 SRAM         */
  PHLSRAMTST_MC_IDX_INVALID,  /* 11: Reserved           */
  38U,                        /* 12: ERAY0_OBF SRAM     */
  39U,                        /* 13: ERAY0_IBF_TBF SRAM */
  40U,                        /* 14: ERAY0_MBF SRAM     */
  PHLSRAMTST_MC_IDX_INVALID,  /* 15: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 16: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 17: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 18: Reserved           */
  46U,                        /* 19: EMEM_LOWER0 SRAM   */
  47U,                        /* 20: EMEM_LOWER1 SRAM   */
  48U,                        /* 21: EMEM_LOWER2 SRAM   */
  49U,                        /* 22: EMEM_LOWER3 SRAM   */
  50U,                        /* 23: EMEM_LOWER4 SRAM   */
  51U,                        /* 24: EMEM_LOWER5 SRAM   */
  52U,                        /* 25: EMEM_LOWER6 SRAM   */
  53U,                        /* 26: EMEM_LOWER7 SRAM   */
  54U,                        /* 27: EMEM_LOWER8 SRAM   */
  55U,                        /* 28: EMEM_LOWER9 SRAM   */
  56U,                        /* 29: EMEM_LOWER10 SRAM  */
  57U,                        /* 30: EMEM_LOWER11 SRAM  */
  58U,                        /* 31: EMEM_LOWER12 SRAM  */
  59U,                        /* 32: EMEM_LOWER13 SRAM  */
  60U,                        /* 33: EMEM_LOWER14 SRAM  */
  61U,                        /* 34: EMEM_LOWER15 SRAM  */
  PHLSRAMTST_MC_IDX_INVALID,  /* 35: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 36: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 37: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 38: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 39: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 40: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 41: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 42: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 43: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 44: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 45: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 46: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 47: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 48: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 49: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 50: Reserved           */
  78U,                        /* 51: CIF0 SRAM          */
  80U,                        /* 52: CIF1 SRAM          */
  81U,                        /* 53: CIF2 SRAM          */
  PHLSRAMTST_MC_IDX_INVALID,  /* 54: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 55: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 56: Reserved           */
  PHLSRAMTST_MC_IDX_INVALID,  /* 57: Reserved           */
};
#define IFX_PHL_SRAM_STOP_SEC_CONST_8BIT_ASIL_B
#include "Ifx_MemMap.h"

#elif(CHIP_ID == 29U)

#define IFX_PHL_SRAM_START_SEC_CONST_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"

/* Memory definition for TC29x ETHER_MAC SRAM: */
static const PhlSramTst_MemoryDefinitionType PhlSramTst_kMdEtherMac =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP4,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_16,         /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_17,         /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = SMU_ALARM_18,         /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_19,         /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 2U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 1U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 35U,                  /* Number of data bits            */
  .NrOfEccBits      = 7U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 1U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 0U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 1U,                   /* Second ECC bit to invert       */
  .TowerDepth       = 1024U                 /* Tower Depth                    */
};

/* Memory definition for TC29x GTM_FIFO SRAM: */
static const PhlSramTst_MemoryDefinitionType PhlSramTst_kMdGtmFifo =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP4,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_0,          /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_1,          /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = SMU_ALARM_2,          /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_3,          /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 2U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 1U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 29U,                  /* Number of data bits            */
  .NrOfEccBits      = 7U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 1U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 0U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 1U,                   /* Second ECC bit to invert       */
  .TowerDepth       = 1024U                 /* Tower Depth                    */
};

/* Memory definition for TC29x GTM_MCS0 SRAM: */
static const PhlSramTst_MemoryDefinitionType PhlSramTst_kMdGtmMcs0 =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP4,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_0,          /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_1,          /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = SMU_ALARM_2,          /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_3,          /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 6U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 1U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 32U,                  /* Number of data bits            */
  .NrOfEccBits      = 7U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 1U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 5U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 6U,                   /* Second ECC bit to invert       */
  .TowerDepth       = 1024U                 /* Tower Depth                    */
};

/* Memory definition for TC29x GTM_MCS1 SRAM: */
static const PhlSramTst_MemoryDefinitionType PhlSramTst_kMdGtmMcs1 =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP4,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_0,          /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_1,          /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = SMU_ALARM_2,          /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_3,          /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 6U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 1U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 32U,                  /* Number of data bits            */
  .NrOfEccBits      = 7U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 1U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 5U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 6U,                   /* Second ECC bit to invert       */
  .TowerDepth       = 512U                  /* Tower Depth                    */
};


/* Memory definition for TC29x GTM_DPLL1A SRAM: */
static const PhlSramTst_MemoryDefinitionType PhlSramTst_kMdGtmDpll1A =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP4,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_0,          /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_1,          /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = SMU_ALARM_2,          /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_3,          /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 1U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 1U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 24U,                  /* Number of data bits            */
  .NrOfEccBits      = 6U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 1U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 1U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 2U,                   /* Second ECC bit to invert       */
  .TowerDepth       = 128U                  /* Tower Depth                    */
};

/* Memory definition for TC29x GTM_DPLL1B SRAM: */
static const PhlSramTst_MemoryDefinitionType PhlSramTst_kMdGtmDpll1B =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP4,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_0,          /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_1,          /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = SMU_ALARM_2,          /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_3,          /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 1U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 1U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 24U,                  /* Number of data bits            */
  .NrOfEccBits      = 6U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 1U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 1U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 2U,                   /* Second ECC bit to invert       */
  .TowerDepth       = 384U                  /* Tower Depth                    */
};

/* Memory definition for TC29x GTM_DPLL2 SRAM: */
static const PhlSramTst_MemoryDefinitionType PhlSramTst_kMdGtmDpll2 =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP4,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_0,          /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_1,          /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = SMU_ALARM_2,          /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_3,          /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 1U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 1U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 24U,                  /* Number of data bits            */
  .NrOfEccBits      = 6U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 1U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 1U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 2U,                   /* Second ECC bit to invert       */
  .TowerDepth       = 4096U                  /* Tower Depth                    */
};
/* Memory definition for TC29x PSI5 SRAM: */
static const PhlSramTst_MemoryDefinitionType PhlSramTst_kMdPsi5 =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP4,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_16,         /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_17,         /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = SMU_ALARM_18,         /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_19,         /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 1U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 1U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 32U,                  /* Number of data bits            */
  .NrOfEccBits      = 7U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 1U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 5U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 6U,                   /* Second ECC bit to invert       */
  .TowerDepth       = 320U                  /* Tower Depth                    */
};

/* Memory definition for TC29x SADMA SRAM: */
static const PhlSramTst_MemoryDefinitionType PhlSramTst_kMdSadma =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP4,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_16,         /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_17,         /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = SMU_ALARM_18,         /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_19,         /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 4U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 1U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 64U,                  /* Number of data bits            */
  .NrOfEccBits      = 8U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 1U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 0U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 1U,                   /* Second ECC bit to invert       */
  .TowerDepth       = 128U                  /* Tower Depth                    */
};

/* Memory definition for TC29x MCAN0 SRAM: */
static const PhlSramTst_MemoryDefinitionType PhlSramTst_kMdMcan0 =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP4,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_4,          /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_5,          /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = SMU_ALARM_6,          /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_7,          /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 1U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 1U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 32U,                  /* Number of data bits            */
  .NrOfEccBits      = 7U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 1U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 5U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 6U,                   /* Second ECC bit to invert       */
  .TowerDepth       = 2368U                 /* Tower Depth                    */
};

/* Memory definition for TC29x MCAN1 SRAM: */
static const PhlSramTst_MemoryDefinitionType PhlSramTst_kMdMcan1 =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP4,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_4,          /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_5,          /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = SMU_ALARM_6,          /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_7,          /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 1U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 1U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 32U,                  /* Number of data bits            */
  .NrOfEccBits      = 7U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 1U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 5U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 6U,                   /* Second ECC bit to invert       */
  .TowerDepth       = 1152U                 /* Tower Depth                    */
};

/* Memory definition for TC29x ERAY_OBF SRAM: */
static const PhlSramTst_MemoryDefinitionType PhlSramTst_kMdErayObf =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP4,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_8,          /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_9,          /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = SMU_ALARM_10,         /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_11,         /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 2U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 1U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 32U,                  /* Number of data bits            */
  .NrOfEccBits      = 7U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 1U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 5U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 6U,                   /* Second ECC bit to invert       */
  .TowerDepth       = 64U                   /* Tower Depth                    */
};

/* Memory definition for TC29x ERAY_IBF_TBF SRAM: */
static const PhlSramTst_MemoryDefinitionType PhlSramTst_kMdErayIbfTbf =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP4,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_8,          /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_9,          /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = SMU_ALARM_10,         /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_11,         /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 4U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 1U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 32U,                  /* Number of data bits            */
  .NrOfEccBits      = 7U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 1U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 5U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 6U,                   /* Second ECC bit to invert       */
  .TowerDepth       = 128U                  /* Tower Depth                    */
};

/* Memory definition for TC29x ERAY_MBF SRAM: */
static const PhlSramTst_MemoryDefinitionType PhlSramTst_kMdErayMbf =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP4,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_8,          /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_9,          /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = SMU_ALARM_10,         /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_11,         /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 1U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 1U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 32U,                  /* Number of data bits            */
  .NrOfEccBits      = 7U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 1U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 5U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 6U,                   /* Second ECC bit to invert       */
  .TowerDepth       = 2048U                 /* Tower Depth                    */
};

/* Memory definition for TC29x EMEM_LOWER / EMEM_UPPER SRAM: */
static const PhlSramTst_MemoryDefinitionType PhlSramTst_kMdEmem =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP4,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_12,         /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_13,         /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = PHLSRAMTST_SMU_NONE,  /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_15,         /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 2U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 1U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 128U,                 /* Number of data bits            */
  .NrOfEccBits      = 9U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 1U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 0U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 1U,                   /* Second ECC bit to invert       */
  .TowerDepth       = 2048U                 /* Tower Depth                    */
};

/* Memory definition for TC29x CIF0 SRAM: */
static const PhlSramTst_MemoryDefinitionType PhlSramTst_kMdCif0 =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP4,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_16,         /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_17,         /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = PHLSRAMTST_SMU_NONE,         /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_19,         /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 4U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 1U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 8U,                   /* Number of data bits            */
  .NrOfEccBits      = 5U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 1U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 0U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 2U,                   /* Second ECC bit to invert       */
  .TowerDepth       = 5120U                  /* Tower Depth                    */
};

/* Memory definition for TC29x CIF1 SRAM: */
static const PhlSramTst_MemoryDefinitionType PhlSramTst_kMdCif1 =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP4,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_16,         /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_17,         /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = PHLSRAMTST_SMU_NONE,         /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_19,         /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 2U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 1U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 8U,                   /* Number of data bits            */
  .NrOfEccBits      = 5U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 1U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 0U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 2U,                   /* Second ECC bit to invert       */
  .TowerDepth       = 384U                   /* Tower Depth                    */
};

/* Memory definition for TC29x CIF2 SRAM: */
static const PhlSramTst_MemoryDefinitionType PhlSramTst_kMdCif2 =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP4,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_16,         /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_17,         /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = PHLSRAMTST_SMU_NONE,  /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_19,         /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 1U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 1U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 36U,                  /* Number of data bits            */
  .NrOfEccBits      = 8U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 1U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 0U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 1U,                   /* Second ECC bit to invert       */
  .TowerDepth       = 512U                  /* Tower Depth                    */
};

/* Memory definition for TC29x FFT0 SRAM: */
static const PhlSramTst_MemoryDefinitionType PhlSramTst_kMdFft0 =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP2,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_17,         /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_18,         /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = SMU_ALARM_19,         /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_20,         /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 4U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 1U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 64U,                  /* Number of data bits            */
  .NrOfEccBits      = 8U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 1U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 0U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 1U,                   /* Second ECC bit to invert       */
  .TowerDepth       = 2048U                 /* Tower Depth                    */
};

/* Memory definition for TC29x FFT1 SRAM: */
static const PhlSramTst_MemoryDefinitionType PhlSramTst_kMdFft1 =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP2,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_17,         /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_18,         /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = SMU_ALARM_19,         /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_20,         /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 1U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 1U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 16U,                  /* Number of data bits            */
  .NrOfEccBits      = 6U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 1U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 0U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 1U,                   /* Second ECC bit to invert       */
  .TowerDepth       = 1024U                 /* Tower Depth                    */
};

#define IFX_PHL_SRAM_STOP_SEC_CONST_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"

#define IFX_PHL_SRAM_START_SEC_CONST_32BIT_ASIL_B
#include "Ifx_MemMap.h"

/* Memory definitions of all Peripheral SRAMs: */
const PhlSramTst_MemoryDefinitionType* const
      PhlSramTst_kMemDef[PHLSRAMTST_MEMORY_COUNT] =
{
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 00: Reserved           */
  &PhlSramTst_kMdEtherMac,                    /* 01: ETHER_MAC SRAM     */
  &PhlSramTst_kMdGtmFifo,                     /* 02: GTM_FIFO SRAM      */
  &PhlSramTst_kMdGtmMcs0,                     /* 03: GTM_MCS0 SRAM      */
  &PhlSramTst_kMdGtmMcs1,                     /* 04: GTM_MCS1 SRAM      */
  &PhlSramTst_kMdGtmDpll1A,                   /* 05: GTM_DPLL1A SRAM    */
  &PhlSramTst_kMdGtmDpll1B,                   /* 06: GTM_DPLL1B SRAM    */
  &PhlSramTst_kMdGtmDpll2,                    /* 07: GTM_DPLL2 SRAM     */
  &PhlSramTst_kMdPsi5,                        /* 08: PSI5 SRAM          */
  &PhlSramTst_kMdSadma,                       /* 09: SADMA SRAM         */
  &PhlSramTst_kMdMcan0,                       /* 10: MCAN0 SRAM         */
  &PhlSramTst_kMdMcan1,                       /* 11: MCAN1 SRAM         */
  &PhlSramTst_kMdErayObf,                     /* 12: ERAY0_OBF SRAM     */
  &PhlSramTst_kMdErayIbfTbf,                  /* 13: ERAY0_IBF_TBF SRAM */
  &PhlSramTst_kMdErayMbf,                     /* 14: ERAY0_MBF SRAM     */
  &PhlSramTst_kMdErayObf,                     /* 15: ERAY1_OBF SRAM     */
  &PhlSramTst_kMdErayIbfTbf,                  /* 16: ERAY1_IBF_TBF SRAM */
  &PhlSramTst_kMdErayMbf,                     /* 17: ERAY1_MBF SRAM     */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 18: Reserved           */
  &PhlSramTst_kMdEmem,                        /* 19: EMEM_LOWER0 SRAM   */
  &PhlSramTst_kMdEmem,                        /* 20: EMEM_LOWER1 SRAM   */
  &PhlSramTst_kMdEmem,                        /* 21: EMEM_LOWER2 SRAM   */
  &PhlSramTst_kMdEmem,                        /* 22: EMEM_LOWER3 SRAM   */
  &PhlSramTst_kMdEmem,                        /* 23: EMEM_LOWER4 SRAM   */
  &PhlSramTst_kMdEmem,                        /* 24: EMEM_LOWER5 SRAM   */
  &PhlSramTst_kMdEmem,                        /* 25: EMEM_LOWER6 SRAM   */
  &PhlSramTst_kMdEmem,                        /* 26: EMEM_LOWER7 SRAM   */
  &PhlSramTst_kMdEmem,                        /* 27: EMEM_LOWER8 SRAM   */
  &PhlSramTst_kMdEmem,                        /* 28: EMEM_LOWER9 SRAM   */
  &PhlSramTst_kMdEmem,                        /* 29: EMEM_LOWER10 SRAM  */
  &PhlSramTst_kMdEmem,                        /* 30: EMEM_LOWER11 SRAM  */
  &PhlSramTst_kMdEmem,                        /* 31: EMEM_LOWER12 SRAM  */
  &PhlSramTst_kMdEmem,                        /* 32: EMEM_LOWER13 SRAM  */
  &PhlSramTst_kMdEmem,                        /* 33: EMEM_LOWER14 SRAM  */
  &PhlSramTst_kMdEmem,                        /* 34: EMEM_LOWER15 SRAM  */
  &PhlSramTst_kMdEmem,                        /* 35: EMEM_UPPER0 SRAM   */
  &PhlSramTst_kMdEmem,                        /* 36: EMEM_UPPER1 SRAM   */
  &PhlSramTst_kMdEmem,                        /* 37: EMEM_UPPER2 SRAM   */
  &PhlSramTst_kMdEmem,                        /* 38: EMEM_UPPER3 SRAM   */
  &PhlSramTst_kMdEmem,                        /* 39: EMEM_UPPER4 SRAM   */
  &PhlSramTst_kMdEmem,                        /* 40: EMEM_UPPER5 SRAM   */
  &PhlSramTst_kMdEmem,                        /* 41: EMEM_UPPER6 SRAM   */
  &PhlSramTst_kMdEmem,                        /* 42: EMEM_UPPER7 SRAM   */
  &PhlSramTst_kMdEmem,                        /* 43: EMEM_UPPER8 SRAM   */
  &PhlSramTst_kMdEmem,                        /* 44: EMEM_UPPER9 SRAM   */
  &PhlSramTst_kMdEmem,                        /* 45: EMEM_UPPER10 SRAM  */
  &PhlSramTst_kMdEmem,                        /* 46: EMEM_UPPER11 SRAM  */
  &PhlSramTst_kMdEmem,                        /* 47: EMEM_UPPER12 SRAM  */
  &PhlSramTst_kMdEmem,                        /* 48: EMEM_UPPER13 SRAM  */
  &PhlSramTst_kMdEmem,                        /* 49: EMEM_UPPER14 SRAM  */
  &PhlSramTst_kMdEmem,                        /* 50: EMEM_UPPER15 SRAM  */
  &PhlSramTst_kMdCif0,                        /* 51: CIF0 SRAM          */
  &PhlSramTst_kMdCif1,                        /* 52: CIF1 SRAM          */
  &PhlSramTst_kMdCif2,                        /* 53: CIF2 SRAM          */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 54: Reserved           */
  (PhlSramTst_MemoryDefinitionType*)NULL_PTR, /* 55: Reserved           */
  &PhlSramTst_kMdFft0,                        /* 56: FFT0 SRAM          */
  &PhlSramTst_kMdFft1                         /* 57: FFT1 SRAM          */
};
#define IFX_PHL_SRAM_STOP_SEC_CONST_32BIT_ASIL_B
#include "Ifx_MemMap.h"

#define IFX_PHL_SRAM_START_SEC_CONST_8BIT_ASIL_B
#include "Ifx_MemMap.h"

/* Lookup table to get memory controller index from memory index: */
const uint8 PhlSramTst_kMcTable[PHLSRAMTST_MEMORY_COUNT] =
{
  PHLSRAMTST_MC_IDX_INVALID,  /* 00: Reserved           */
  22U,                        /* 01: ETHER_MAC SRAM     */
  28U,                        /* 02: GTM_FIFO SRAM      */
  29U,                        /* 03: GTM_MCS0 SRAM      */
  30U,                        /* 04: GTM_MCS1 SRAM      */
  31U,                        /* 05: GTM_DPLL1A SRAM    */
  32U,                        /* 06: GTM_DPLL1B SRAM    */
  33U,                        /* 07: GTM_DPLL2 SRAM     */
  34U,                        /* 08: PSI5 SRAM          */
  83U,                        /* 09: SADMA SRAM         */
  36U,                        /* 10: MCAN0 SRAM         */
  37U,                        /* 11: MCAN1 SRAM         */
  38U,                        /* 12: ERAY0_OBF SRAM     */
  39U,                        /* 13: ERAY0_IBF_TBF SRAM */
  40U,                        /* 14: ERAY0_MBF SRAM     */
  41U,                        /* 15: ERAY1_OBF SRAM     */
  42U,                        /* 16: ERAY1_IBF_TBF SRAM */
  43U,                        /* 17: ERAY1_MBF SRAM     */
  PHLSRAMTST_MC_IDX_INVALID,  /* 18: Reserved           */
  46U,                        /* 19: EMEM_LOWER0 SRAM   */
  47U,                        /* 20: EMEM_LOWER1 SRAM   */
  48U,                        /* 21: EMEM_LOWER2 SRAM   */
  49U,                        /* 22: EMEM_LOWER3 SRAM   */
  50U,                        /* 23: EMEM_LOWER4 SRAM   */
  51U,                        /* 24: EMEM_LOWER5 SRAM   */
  52U,                        /* 25: EMEM_LOWER6 SRAM   */
  53U,                        /* 26: EMEM_LOWER7 SRAM   */
  54U,                        /* 27: EMEM_LOWER8 SRAM   */
  55U,                        /* 28: EMEM_LOWER9 SRAM   */
  56U,                        /* 29: EMEM_LOWER10 SRAM  */
  57U,                        /* 30: EMEM_LOWER11 SRAM  */
  58U,                        /* 31: EMEM_LOWER12 SRAM  */
  59U,                        /* 32: EMEM_LOWER13 SRAM  */
  60U,                        /* 33: EMEM_LOWER14 SRAM  */
  61U,                        /* 34: EMEM_LOWER15 SRAM  */
  62U,                        /* 35: EMEM_UPPER0 SRAM   */
  63U,                        /* 36: EMEM_UPPER1 SRAM   */
  64U,                        /* 37: EMEM_UPPER2 SRAM   */
  65U,                        /* 38: EMEM_UPPER3 SRAM   */
  66U,                        /* 39: EMEM_UPPER4 SRAM   */
  67U,                        /* 40: EMEM_UPPER5 SRAM   */
  68U,                        /* 41: EMEM_UPPER6 SRAM   */
  69U,                        /* 42: EMEM_UPPER7 SRAM   */
  70U,                        /* 43: EMEM_UPPER8 SRAM   */
  71U,                        /* 44: EMEM_UPPER9 SRAM   */
  72U,                        /* 45: EMEM_UPPER10 SRAM  */
  73U,                        /* 46: EMEM_UPPER11 SRAM  */
  74U,                        /* 47: EMEM_UPPER12 SRAM  */
  75U,                        /* 48: EMEM_UPPER13 SRAM  */
  76U,                        /* 49: EMEM_UPPER14 SRAM  */
  77U,                        /* 50: EMEM_UPPER15 SRAM  */
  78U,                        /* 51: CIF0 SRAM          */
  80U,                        /* 52: CIF1 SRAM          */
  81U,                        /* 53: CIF2 SRAM          */
  84U,                        /* 54: EMEM_XTM0 SRAM     */
  85U,                        /* 55: EMEM_XTM1 SRAM     */
  86U,                        /* 56: FFT0 SRAM          */
  87U                         /* 57: FFT1 SRAM          */
};
#define IFX_PHL_SRAM_STOP_SEC_CONST_8BIT_ASIL_B
#include "Ifx_MemMap.h"

#endif


/*******************************************************************************
**                        Local object definitions                             *
*******************************************************************************/

/*******************************************************************************
**                        Imported function declarations                       *
*******************************************************************************/

/*******************************************************************************
**                        Local function prototypes                            *
*******************************************************************************/

/*******************************************************************************
**                    Local in-line function definitions                       *
*******************************************************************************/

/*******************************************************************************
**                    Configuration error checking                             *
*******************************************************************************/

/*******************************************************************************
**                         Function definitions                                *
*******************************************************************************/

