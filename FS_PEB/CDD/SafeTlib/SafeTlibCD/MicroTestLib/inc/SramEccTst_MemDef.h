#ifndef SRAMECCTST_MEMDEF_H
#define SRAMECCTST_MEMDEF_H
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
**   $FILENAME   : SramEccTst_MemDef.h $                                      **
**                                                                            **
**   $CC VERSION : \main\14 $                                                 **
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
**                 SRAM test                                                  **
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
#include "SramEccTst.h"


/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/* Special constant to indicate that a certain SMU Alarm does not exist: */
#define SRAMECCTST_SMU_NONE                (0xFFU)

/* Total number of memory controllers: */
#define SRAMECCTST_MBIST_CONTROLLER_COUNT  ( 88U )

/* Total number of supported memories: */
#define SRAMECCTST_MEMORY_COUNT            ((uint8)15U)

#define SRAM_MC_IDX_INVALID                ((uint8)0xFFU)
/* Definition of all SRAMs supported on different derivatives 23/26/27/29: */
#define SRAM_CPU0_DSPR                     (  0U )
#define SRAM_CPU0_DTAG                     (  1U )
#define SRAM_CPU0_PSPR                     (  2U )
#define SRAM_CPU0_PTAG                     (  3U )
#define SRAM_CPU1_DSPR                     (  4U )
#define SRAM_CPU1_DSPR2                    (  5U )
#define SRAM_CPU1_DTAG                     (  6U )
#define SRAM_CPU1_PSPR0                    (  7U )
#define SRAM_CPU1_PTAG                     (  8U )
#define SRAM_CPU2_DSPR                     (  9U )
#define SRAM_CPU2_DSPR2                    ( 10U )
#define SRAM_CPU2_DTAG                     ( 11U )
#define SRAM_CPU2_PSPR                     ( 12U )
#define SRAM_CPU2_PTAG                     ( 13U )
#define SRAM_DAM                           ( 14U )


/*******************************************************************************
**                      Typedefs                                              **
*******************************************************************************/

/* Type definition SramEccTst_MemoryDefitionType -
 * This structure holds the description of an individual SRAM: */
typedef struct SramEccTst_MemoryDefinitionType
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
  uint32                    Reserved; /*This element is added to make the structure 4 byte aligned - workaround for windriver */
}SramEccTst_MemoryDefinitionType;


/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/
#define IFX_SRAM_START_SEC_CONST_32BIT_ASIL_B
#include "Ifx_MemMap.h"
/* Memory definition export: */
extern const SramEccTst_MemoryDefinitionType* const
                SramEccTst_kMemDef[SRAMECCTST_MEMORY_COUNT];
#define IFX_SRAM_STOP_SEC_CONST_32BIT_ASIL_B
#include "Ifx_MemMap.h"
#define IFX_SRAM_START_SEC_CONST_8BIT_ASIL_B
#include "Ifx_MemMap.h"
/* Memory controller index lookup table export: */
extern const uint8 SramEccTst_kMcTable[SRAMECCTST_MEMORY_COUNT];
#define IFX_SRAM_STOP_SEC_CONST_8BIT_ASIL_B
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
#endif /* SRAMECCTST_MEMDEF_H */
