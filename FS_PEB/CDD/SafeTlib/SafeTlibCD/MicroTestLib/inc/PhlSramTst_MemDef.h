#ifndef PHLSRAMTST_MEMDEF_H
#define PHLSRAMTST_MEMDEF_H
/*******************************************************************************
**                                                                            **
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
**   $FILENAME   : PhlSramTst_MemDef.h $                                      **
**                                                                            **
**   $CC VERSION : \main\3 $                                                  **
**                                                                            **
**   $DATE       : 2018-02-22 $                                               **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  AUTHOR    : DL-BLR-ATV-STC                                                **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : This file contains the memory definitions used by the      **
**                 Peripheral SRAM test                                       **
**                                                                            **
**  REFERENCE(S) :                                                            **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

#include "Platform_Types.h"
#include "Compiler_Cfg.h"
#include "PhlSramTst.h"


/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/* Special constant to indicate that a certain SMU Alarm does not exist: */
#define PHLSRAMTST_SMU_NONE                (0xFFU)

/* Total number of memory controllers: */
#define PHLSRAMTST_MBIST_CONTROLLER_COUNT  ( 88U )

/* Total number of supported memories: */
#define PHLSRAMTST_MEMORY_COUNT            ((uint8)58U)

#define PHLSRAMTST_MC_IDX_INVALID          ((uint8)0xFFU)

/* Definition of all SRAMs supported on different derivatives 23/26/27/29: */
#define PHL_SRAM_MINI_MCDS                  (  0U )
#define PHL_SRAM_ETHER_MAC                  (  1U )
#define PHL_SRAM_GTM_FIFO                   (  2U )
#define PHL_SRAM_GTM_MCS0                   (  3U )
#define PHL_SRAM_GTM_MCS1                   (  4U )
#define PHL_SRAM_GTM_DPLL1A                 (  5U )
#define PHL_SRAM_GTM_DPLL1B                 (  6U )
#define PHL_SRAM_GTM_DPLL2                  (  7U )
#define PHL_SRAM_PSI5                       (  8U )
#define PHL_SRAM_SADMA                      (  9U )
#define PHL_SRAM_MCAN0                      ( 10U )
#define PHL_SRAM_MCAN1                      ( 11U )
#define PHL_SRAM_ERAY0_OBF                  ( 12U )
#define PHL_SRAM_ERAY0_IBF_TBF              ( 13U )
#define PHL_SRAM_ERAY0_MBF                  ( 14U )
#define PHL_SRAM_ERAY1_OBF                  ( 15U )
#define PHL_SRAM_ERAY1_IBF_TBF              ( 16U )
#define PHL_SRAM_ERAY1_MBF                  ( 17U )
#define PHL_SRAM_MCDS                       ( 18U )
#define PHL_SRAM_EMEM_LOWER0                ( 19U )
#define PHL_SRAM_EMEM_LOWER1                ( 20U )
#define PHL_SRAM_EMEM_LOWER2                ( 21U )
#define PHL_SRAM_EMEM_LOWER3                ( 22U )
#define PHL_SRAM_EMEM_LOWER4                ( 23U )
#define PHL_SRAM_EMEM_LOWER5                ( 24U )
#define PHL_SRAM_EMEM_LOWER6                ( 25U )
#define PHL_SRAM_EMEM_LOWER7                ( 26U )
#define PHL_SRAM_EMEM_LOWER8                ( 27U )
#define PHL_SRAM_EMEM_LOWER9                ( 28U )
#define PHL_SRAM_EMEM_LOWER10               ( 29U )
#define PHL_SRAM_EMEM_LOWER11               ( 30U )
#define PHL_SRAM_EMEM_LOWER12               ( 31U )
#define PHL_SRAM_EMEM_LOWER13               ( 32U )
#define PHL_SRAM_EMEM_LOWER14               ( 33U )
#define PHL_SRAM_EMEM_LOWER15               ( 34U )
#define PHL_SRAM_EMEM_UPPER0                ( 35U )
#define PHL_SRAM_EMEM_UPPER1                ( 36U )
#define PHL_SRAM_EMEM_UPPER2                ( 37U )
#define PHL_SRAM_EMEM_UPPER3                ( 38U )
#define PHL_SRAM_EMEM_UPPER4                ( 39U )
#define PHL_SRAM_EMEM_UPPER5                ( 40U )
#define PHL_SRAM_EMEM_UPPER6                ( 41U )
#define PHL_SRAM_EMEM_UPPER7                ( 42U )
#define PHL_SRAM_EMEM_UPPER8                ( 43U )
#define PHL_SRAM_EMEM_UPPER9                ( 44U )
#define PHL_SRAM_EMEM_UPPER10               ( 45U )
#define PHL_SRAM_EMEM_UPPER11               ( 46U )
#define PHL_SRAM_EMEM_UPPER12               ( 47U )
#define PHL_SRAM_EMEM_UPPER13               ( 48U )
#define PHL_SRAM_EMEM_UPPER14               ( 49U )
#define PHL_SRAM_EMEM_UPPER15               ( 50U )
#define PHL_SRAM_CIF0                       ( 51U )
#define PHL_SRAM_CIF1                       ( 52U )
#define PHL_SRAM_CIF2                       ( 53U )
#define PHL_SRAM_EMEM_XTM0                  ( 54U )
#define PHL_SRAM_EMEM_XTM1                  ( 55U )
#define PHL_SRAM_FFT0                       ( 56U )
#define PHL_SRAM_FFT1                       ( 57U )


/*******************************************************************************
**                      Typedefs                                              **
*******************************************************************************/

/* Type definition PhlSramTst_MemoryDefitionType -
 * This structure holds the description of an individual SRAM: */
typedef struct PhlSramTst_MemoryDefinitionType
{
  /* SMU alarm group: */
  uint8                     SmuAlarmGrp;
  /* Correctable bit error SMU alarm index: */
  uint8                     SmuNr_SbeCorr;
  /* Uncorrectable bit error SMU alarm index: */
  uint8                     SmuNr_UcErr;
  /* Address error SMU alarm index: */
  uint8                     SmuNr_AdrErr;
  /* Error tracking buffer overflow SMU alarm index: */
  uint8                     SmuNr_AdrBufFull;

  /* Number of memories per MBIST: */
  uint8                     NrOfMemBlocks;
  /* Number of multiplexers (left / right half): */
  uint8                     NrOfMultiplexers;
  /* Number of data bits per word: */
  uint8                     NrOfDataBits;
  /* Number of ECC bits per data word: */
  uint8                     NrOfEccBits;

  /* Number of error tracking registers: */
  uint8                     NrOfEtrRegisters;
  uint8                     EccInvPos0;
  uint8                     EccInvPos1;
  /*tower depth  */
  uint16                     TowerDepth;  
} PhlSramTst_MemoryDefinitionType;


/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/
#define IFX_PHL_SRAM_START_SEC_CONST_32BIT_ASIL_B
#include "Ifx_MemMap.h"
/* Memory definition export: */
extern const PhlSramTst_MemoryDefinitionType* const
                PhlSramTst_kMemDef[PHLSRAMTST_MEMORY_COUNT];
#define IFX_PHL_SRAM_STOP_SEC_CONST_32BIT_ASIL_B
#include "Ifx_MemMap.h" 
#define IFX_PHL_SRAM_START_SEC_CONST_8BIT_ASIL_B
#include "Ifx_MemMap.h"
/* Memory controller index lookup table export: */
extern const uint8 PhlSramTst_kMcTable[PHLSRAMTST_MEMORY_COUNT];
#define IFX_PHL_SRAM_STOP_SEC_CONST_8BIT_ASIL_B
#include "Ifx_MemMap.h"
/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/

/*******************************************************************************
**                Global Function like macro Definitions                      **
*******************************************************************************/
#endif /* PHLSRAMTST_MEMDEF_H */
