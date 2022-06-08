/*******************************************************************************
** Copyright (C) Infineon Technologies (2014)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**   $FILENAME   : SramEccTst_MemDef.c $                                      **
**                                                                            **
**   $CC VERSION : \main\24 $                                                 **
**                                                                            **
**   $DATE       : 2015-10-06 $                                               **
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
**                 - SRAM Memory Definitions for the SRAM ECC test            **
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

#include "SramEccTst_MemDef.h"
#include "ChipId.h"
#include "Mcal.h"
#include "Smu.h"

/*******************************************************************************
**                      Local Macro Definitions                               **
*******************************************************************************/


/*******************************************************************************
**                      Local Type Definitions                                **
*******************************************************************************/

/*******************************************************************************
**                        Exported object definitions                          *
*******************************************************************************/

#define IFX_SRAM_START_SEC_CONST_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"
#if(MCAL_NO_OF_CORES > 2U)
/* Memory definition for TC27x/TC29x CPU2 DSPR SRAM: */
static const SramEccTst_MemoryDefinitionType SramEccTst_kMdCpu2Dspr =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP6,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_10,         /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_11,         /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = SMU_ALARM_12,         /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_13,         /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 4U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 2U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 16U,                  /* Number of data bits            */
  .NrOfEccBits      = 6U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 5U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 0U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 1U,                   /* Second ECC bit to invert       */
  .Reserved         = 0U                   /* This element is added to make  */ 
                                            /* structure 4 byte aligned -     */
                                            /* workaround for windriver       */  
};

/* Memory definition for TC27x/TC29x CPU2 DTAG SRAM: */
static const SramEccTst_MemoryDefinitionType SramEccTst_kMdCpu2Dtag =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP6,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_14,         /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_15,         /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = SMU_ALARM_16,         /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_17,         /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 1U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 2U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 20U,                  /* Number of data bits            */
  #if (CHIP_ID == 29U)  
  .NrOfEccBits      = 10U,                   /* Number of ECC bits             */
  #else  
  .NrOfEccBits      = 6U,                   /* Number of ECC bits             */
  #endif  
  .NrOfEtrRegisters = 2U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 0U,                   /* First ECC bit to invert        */
  #if (CHIP_ID == 29U)    
  .EccInvPos1       = 4U,                   /* Second ECC bit to invert       */  
  #else
  .EccInvPos1       = 1U,                   /* Second ECC bit to invert       */
  #endif
  .Reserved         = 0U                   /* This element is added to make  */ 
                                            /* structure 4 byte aligned -     */
                                            /* workaround for windriver       */    
};

/* Memory defintion for TC27x/TC29x CPU2 PSPR SRAM: */
static const SramEccTst_MemoryDefinitionType SramEccTst_kMdCpu2Pspr =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP6,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_6,          /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_7,          /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = SMU_ALARM_8,          /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_9,          /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 2U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 1U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 64U,                  /* Number of data bits            */
  .NrOfEccBits      = 8U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 5U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 0U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 1U,                   /* Second ECC bit to invert       */
  .Reserved         = 0U                   /* This element is added to make  */ 
                                            /* structure 4 byte aligned -     */
                                            /* workaround for windriver       */    
};

/* Memory definition for TC27x/TC29x CPU2 PTAG SRAM: */
static const SramEccTst_MemoryDefinitionType SramEccTst_kMdCpu2Ptag =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP6,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SRAMECCTST_SMU_NONE,  /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_3,          /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = SMU_ALARM_4,          /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_5,          /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 1U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 2U,                   /* Number of Multiplexers         */
  #if (CHIP_ID == 29U)    
  .NrOfDataBits     = 19U,                  /* Number of data bits            */
  .NrOfEccBits      = 10U,                  /* Number of ECC bits             */
  #else
  .NrOfDataBits     = 20U,                  /* Number of data bits            */
  .NrOfEccBits      = 5U,                   /* Number of ECC bits             */
  #endif
  .NrOfEtrRegisters = 2U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 0U,                   /* First ECC bit to invert        */
  #if (CHIP_ID == 29U)    
  .EccInvPos1       = 4U,                   /* Second ECC bit to invert       */  
  #else
  .EccInvPos1       = 1U,                   /* Second ECC bit to invert       */
  #endif
  .Reserved         = 0U                   /* This element is added to make  */ 
                                            /* structure 4 byte aligned -     */
                                            /* workaround for windriver       */    
};
#endif

#if(MCAL_NO_OF_CORES > 1U)
/* Memory definition for TC26x/TC27x/TC29x CPU1 DSPR SRAM: */
static const SramEccTst_MemoryDefinitionType SramEccTst_kMdCpu1Dspr =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP1,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_10,         /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_11,         /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = SMU_ALARM_12,         /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_13,         /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 4U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 2U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 16U,                  /* Number of data bits            */
  .NrOfEccBits      = 6U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 5U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 0U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 1U,                   /* Second ECC bit to invert       */
  .Reserved         = 0U                   /* This element is added to make  */ 
                                            /* structure 4 byte aligned -     */
                                            /* workaround for windriver       */    
};

/* Memory definition for TC26x/TC27x/TC29x CPU1 DTAG SRAM: */
static const SramEccTst_MemoryDefinitionType SramEccTst_kMdCpu1Dtag =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP1,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_14,         /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_15,         /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = SMU_ALARM_16,         /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_17,         /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 1U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 2U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 20U,                  /* Number of data bits            */
  #if (CHIP_ID == 29U)    
  .NrOfEccBits      = 10U,                   /* Number of ECC bits             */  
  #else  
  .NrOfEccBits      = 6U,                   /* Number of ECC bits             */
  #endif  
  .NrOfEtrRegisters = 2U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 0U,                   /* First ECC bit to invert        */
  #if (CHIP_ID == 29U)  
  .EccInvPos1       = 4U,                   /* Second ECC bit to invert       */  
  #else
  .EccInvPos1       = 1U,                   /* Second ECC bit to invert       */
  #endif
  .Reserved         = 0U                   /* This element is added to make  */ 
                                            /* structure 4 byte aligned -     */
                                            /* workaround for windriver       */    
};

/* Memory definition of TC26x/TC27x/TC29x CPU1 PSPR SRAM: */
static const SramEccTst_MemoryDefinitionType SramEccTst_kMdCpu1Pspr =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP1,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_6,          /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_7,          /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = SMU_ALARM_8,          /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_9,          /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 2U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 1U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 64U,                  /* Number of data bits            */
  .NrOfEccBits      = 8U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 5U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 0U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 1U,                   /* Second ECC bit to invert       */
  .Reserved         = 0U                   /* This element is added to make  */ 
                                            /* structure 4 byte aligned -     */
                                            /* workaround for windriver       */    
};

/* Memory definition for TC26x/TC27x/TC29x CPU1 PTAG: */
static const SramEccTst_MemoryDefinitionType SramEccTst_kMdCpu1Ptag =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP1,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SRAMECCTST_SMU_NONE,  /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_3,          /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = SMU_ALARM_4,          /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_5,          /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 1U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 2U,                   /* Number of Multiplexers         */
  #if (CHIP_ID == 29U)    
  .NrOfDataBits     = 19U,                  /* Number of data bits            */  
  .NrOfEccBits      = 10U,                   /* Number of ECC bits             */  
  #else
  .NrOfDataBits     = 20U,                  /* Number of data bits            */
  .NrOfEccBits      = 5U,                   /* Number of ECC bits             */
  #endif
  .NrOfEtrRegisters = 2U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 0U,                   /* First ECC bit to invert        */
  #if (CHIP_ID == 29U)    
  .EccInvPos1       = 4U,                   /* Second ECC bit to invert       */
  #else
  .EccInvPos1       = 1U,                   /* Second ECC bit to invert       */  
  #endif
  .Reserved         = 0U                   /* This element is added to make  */ 
                                            /* structure 4 byte aligned -     */
                                            /* workaround for windriver       */    
};
#endif

/* Memory definition for CPU0 DSPR for derivatives: */
static const SramEccTst_MemoryDefinitionType SramEccTst_kMdCpu0Dspr =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP0,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_10,         /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_11,         /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = SMU_ALARM_12,         /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_13,         /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 4U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 2U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 16U,                  /* Number of data bits            */
  .NrOfEccBits      = 6U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 5U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 0U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 1U,                   /* Second ECC bit to invert       */
  .Reserved         = 0U                   /* This element is added to make  */ 
                                            /* structure 4 byte aligned -     */
                                            /* workaround for windriver       */    
};

/* Memory definition for CPU0 PSPR SRAM for derivatives: */
static const SramEccTst_MemoryDefinitionType SramEccTst_kMdCpu0Pspr =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP0,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_6,          /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_7,          /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = SMU_ALARM_8,          /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_9,          /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 2U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 1U,                   /* Number of Multiplexers         */
  #if (CHIP_ID == 29U)  
  .NrOfDataBits     = 64U,                  /* Number of data bits            */    
  #else
  .NrOfDataBits     = 32U,                  /* Number of data bits            */
  #endif
  .NrOfEccBits      = 8U,                   /* Number of ECC bits             */
  #if (CHIP_ID == 29U)    
  .NrOfEtrRegisters = 5U,                   /* Number of error tracking regs  */  
  #else
  .NrOfEtrRegisters = 3U,                   /* Number of error tracking regs  */
  #endif
  .EccInvPos0       = 0U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 1U,                   /* Second ECC bit to invert       */
  .Reserved         = 0U                   /* This element is added to make  */ 
                                            /* structure 4 byte aligned -     */
                                            /* workaround for windriver       */    
};

/* Memory definition for CPU0 PTAG SRAM for derivatives: */
static const SramEccTst_MemoryDefinitionType SramEccTst_kMdCpu0Ptag =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP0,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SRAMECCTST_SMU_NONE,  /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_3,          /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = SMU_ALARM_4,          /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_5,          /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 1U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 2U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 20U,                  /* Number of data bits            */
  #if (CHIP_ID == 29U)    
  .NrOfEccBits      = 10U,                   /* Number of ECC bits             */    
  #else
  .NrOfEccBits      = 5U,                   /* Number of ECC bits             */
  #endif
  .NrOfEtrRegisters = 2U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 0U,                   /* First ECC bit to invert        */
  #if (CHIP_ID == 29U)   
  .EccInvPos1       = 4U,                   /* Second ECC bit to invert       */
  #else
  .EccInvPos1       = 1U,                   /* Second ECC bit to invert       */  
  #endif
  .Reserved         = 0U                   /* This element is added to make  */ 
                                            /* structure 4 byte aligned -     */
                                            /* workaround for windriver       */    
};

#if(CHIP_ID == 29U)

/* Memory definition for TC29x CPU0 DTAG SRAM: */
static const SramEccTst_MemoryDefinitionType SramEccTst_kMdCpu0Dtag =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP0,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_14,         /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_15,         /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = SMU_ALARM_16,         /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_17,         /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 1U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 2U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 20U,                  /* Number of data bits            */
  .NrOfEccBits      = 10U,                  /* Number of ECC bits             */
  .NrOfEtrRegisters = 2U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 0U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 4U,                   /* Second ECC bit to invert       */
  .Reserved         = 0U                   /* This element is added to make  */ 
                                            /* structure 4 byte aligned -     */
                                            /* workaround for windriver       */    
};


/* Memory definition for TC29x CPU1 DSPR2 SRAM: */
static const SramEccTst_MemoryDefinitionType SramEccTst_kMdCpu1Dspr2 =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP1,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_10,         /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_11,         /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = SMU_ALARM_12,         /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_13,         /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 4U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 2U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 16U,                  /* Number of data bits            */
  .NrOfEccBits      = 6U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 5U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 0U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 1U,                   /* Second ECC bit to invert       */
  .Reserved         = 0U                   /* This element is added to make  */ 
                                            /* structure 4 byte aligned -     */
                                            /* workaround for windriver       */    
};


/* Memory definition for TC29x CPU2 DSPR2 SRAM: */
static const SramEccTst_MemoryDefinitionType SramEccTst_kMdCpu2Dspr2 =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP6,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_10,         /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_11,         /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = SMU_ALARM_12,         /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_13,         /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 4U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 2U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 16U,                  /* Number of data bits            */
  .NrOfEccBits      = 6U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 5U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 0U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 1U,                   /* Second ECC bit to invert       */
  .Reserved         = 0U                   /* This element is added to make  */ 
                                            /* structure 4 byte aligned -     */
                                            /* workaround for windriver       */    
};

#endif

/* Memory definition for DAM SRAM: */
static const SramEccTst_MemoryDefinitionType SramEccTst_kMdDam =
{
  .SmuAlarmGrp      = SMU_ALARM_GROUP2,     /* SMU alarm group                */
  .SmuNr_SbeCorr    = SMU_ALARM_17,         /* Correctable error SMU alarm    */
  .SmuNr_UcErr      = SMU_ALARM_18,         /* Uncorrectable error SMU alarm  */
  .SmuNr_AdrErr     = SMU_ALARM_19,         /* Address error SMU alarm        */
  .SmuNr_AdrBufFull = SMU_ALARM_20,         /* Address buffer full SMU alarm  */
  .NrOfMemBlocks    = 1U,                   /* Number of memory blocks        */
  .NrOfMultiplexers = 1U,                   /* Number of Multiplexers         */
  .NrOfDataBits     = 64U,                  /* Number of data bits            */
  .NrOfEccBits      = 8U,                   /* Number of ECC bits             */
  .NrOfEtrRegisters = 1U,                   /* Number of error tracking regs  */
  .EccInvPos0       = 0U,                   /* First ECC bit to invert        */
  .EccInvPos1       = 1U,                   /* Second ECC bit to invert       */
  .Reserved         = 0U                   /* This element is added to make  */ 
                                            /* structure 4 byte aligned -     */
                                            /* workaround for windriver       */    
};

#define IFX_SRAM_STOP_SEC_CONST_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"

#define IFX_SRAM_START_SEC_CONST_32BIT_ASIL_B
#include "Ifx_MemMap.h"

/* Memory definitions of all SRAMs: */
#if (CHIP_ID == 29U)
const SramEccTst_MemoryDefinitionType* const
      SramEccTst_kMemDef[SRAMECCTST_MEMORY_COUNT] =
{
  &SramEccTst_kMdCpu0Dspr,                    /* 00: CPU0 DSPR        */
  &SramEccTst_kMdCpu0Dtag,                    /* 01: CPU0 DTAG        */
  &SramEccTst_kMdCpu0Pspr,                    /* 02: CPU0 PSPR        */
  &SramEccTst_kMdCpu0Ptag,                    /* 03: CPU0 PTAG        */
  &SramEccTst_kMdCpu1Dspr,                    /* 04: CPU1 DSPR        */
  &SramEccTst_kMdCpu1Dspr2,                   /* 05: CPU1 DSPR2       */
  &SramEccTst_kMdCpu1Dtag,                    /* 06: CPU1 DTAG        */
  &SramEccTst_kMdCpu1Pspr,                    /* 07: CPU1 PSPR0       */
  &SramEccTst_kMdCpu1Ptag,                    /* 08: CPU1 PTAG        */
  &SramEccTst_kMdCpu2Dspr,                    /* 09: CPU2 DSPR        */
  &SramEccTst_kMdCpu2Dspr2,                   /* 10: CPU2 DSPR2       */
  &SramEccTst_kMdCpu2Dtag,                    /* 11: CPU2 DTAG        */
  &SramEccTst_kMdCpu2Pspr,                    /* 12: CPU2 PSPR        */
  &SramEccTst_kMdCpu2Ptag,                    /* 13: CPU2 PTAG        */
  &SramEccTst_kMdDam                          /* 14: DAM (LMU)        */
};


#elif (CHIP_ID == 27U)

const SramEccTst_MemoryDefinitionType* const
      SramEccTst_kMemDef[SRAMECCTST_MEMORY_COUNT] =
{
  &SramEccTst_kMdCpu0Dspr,                    /* 00: CPU0 DSPR        */
  (SramEccTst_MemoryDefinitionType*)NULL_PTR, /* 01: Reserved         */
  &SramEccTst_kMdCpu0Pspr,                    /* 02: CPU0 PSPR        */
  &SramEccTst_kMdCpu0Ptag,                    /* 03: CPU0 PTAG        */
  &SramEccTst_kMdCpu1Dspr,                    /* 04: CPU1 DSPR        */
  (SramEccTst_MemoryDefinitionType*)NULL_PTR, /* 05: Reserved         */
  &SramEccTst_kMdCpu1Dtag,                    /* 06: CPU1 DTAG        */
  &SramEccTst_kMdCpu1Pspr,                    /* 07: CPU1 PSPR0       */
  &SramEccTst_kMdCpu1Ptag,                    /* 08: CPU1 PTAG        */
  &SramEccTst_kMdCpu2Dspr,                    /* 09: CPU2 DSPR        */
  (SramEccTst_MemoryDefinitionType*)NULL_PTR, /* 10: Reserved         */
  &SramEccTst_kMdCpu2Dtag,                    /* 11: CPU2 DTAG        */
  &SramEccTst_kMdCpu2Pspr,                    /* 12: CPU2 PSPR        */
  &SramEccTst_kMdCpu2Ptag,                    /* 13: CPU2 PTAG        */
  &SramEccTst_kMdDam                          /* 14: DAM (LMU)        */
};

#elif(CHIP_ID == 26U)

const SramEccTst_MemoryDefinitionType* const
      SramEccTst_kMemDef[SRAMECCTST_MEMORY_COUNT] =
{
  &SramEccTst_kMdCpu0Dspr,                    /* 00: CPU0 DSPR        */
  (SramEccTst_MemoryDefinitionType*)NULL_PTR, /* 01: Reserved         */
  &SramEccTst_kMdCpu0Pspr,                    /* 02: CPU0 PSPR        */
  &SramEccTst_kMdCpu0Ptag,                    /* 03: CPU0 PTAG        */
  &SramEccTst_kMdCpu1Dspr,                    /* 04: CPU1 DSPR        */
  (SramEccTst_MemoryDefinitionType*)NULL_PTR, /* 05: Reserved         */
  &SramEccTst_kMdCpu1Dtag,                    /* 06: CPU1 DTAG        */
  &SramEccTst_kMdCpu1Pspr,                    /* 07: CPU1 PSPR0       */
  &SramEccTst_kMdCpu1Ptag,                    /* 08: CPU1 PTAG        */
  (SramEccTst_MemoryDefinitionType*)NULL_PTR, /* 09: Reserved         */
  (SramEccTst_MemoryDefinitionType*)NULL_PTR, /* 10: Reserved         */
  (SramEccTst_MemoryDefinitionType*)NULL_PTR, /* 11: Reserved         */
  (SramEccTst_MemoryDefinitionType*)NULL_PTR, /* 12: Reserved         */
  (SramEccTst_MemoryDefinitionType*)NULL_PTR, /* 13: Reserved         */
  &SramEccTst_kMdDam                          /* 14: DAM (LMU)        */
};



#elif ( (CHIP_ID == 24U)||(CHIP_ID == 23U) || (CHIP_ID == 22U) || (CHIP_ID == 21U) )

const SramEccTst_MemoryDefinitionType* const
      SramEccTst_kMemDef[SRAMECCTST_MEMORY_COUNT] =
{
  &SramEccTst_kMdCpu0Dspr,                    /* 00: CPU0 DSPR        */
  (SramEccTst_MemoryDefinitionType*)NULL_PTR, /* 01: Reserved         */
  &SramEccTst_kMdCpu0Pspr,                    /* 02: CPU0 PSPR        */
  &SramEccTst_kMdCpu0Ptag,                    /* 03: CPU0 PTAG        */
  (SramEccTst_MemoryDefinitionType*)NULL_PTR, /* 04: Reserved         */
  (SramEccTst_MemoryDefinitionType*)NULL_PTR, /* 05: Reserved         */
  (SramEccTst_MemoryDefinitionType*)NULL_PTR, /* 06: Reserved         */
  (SramEccTst_MemoryDefinitionType*)NULL_PTR, /* 07: Reserved         */
  (SramEccTst_MemoryDefinitionType*)NULL_PTR, /* 08: Reserved         */
  (SramEccTst_MemoryDefinitionType*)NULL_PTR, /* 09: Reserved         */
  (SramEccTst_MemoryDefinitionType*)NULL_PTR, /* 10: Reserved         */
  (SramEccTst_MemoryDefinitionType*)NULL_PTR, /* 11: Reserved         */
  (SramEccTst_MemoryDefinitionType*)NULL_PTR, /* 12: Reserved         */
  (SramEccTst_MemoryDefinitionType*)NULL_PTR, /* 13: Reserved         */
  &SramEccTst_kMdDam                          /* 14: DAM (LMU)        */
};


#endif


#define IFX_SRAM_STOP_SEC_CONST_32BIT_ASIL_B
#include "Ifx_MemMap.h"

#define IFX_SRAM_START_SEC_CONST_8BIT_ASIL_B
#include "Ifx_MemMap.h"

#if (CHIP_ID == 29U)

/* Lookup table to get memory controller index from memory index: */
const uint8 SramEccTst_kMcTable[SRAMECCTST_MEMORY_COUNT] =
{
  14U,                  /* 00: CPU0 DSPR    */
  19U,                  /* 01: CPU0 DTAG    */
  16U,                  /* 02: CPU0 PSPR    */
  17U,                  /* 03: CPU0 PTAG    */
  6U,                   /* 04: CPU1 DSPR    */
  20U,                  /* 05: CPU1 DSPR2   */
  8U,                   /* 06: CPU1 DTAG    */
  9U,                   /* 07: CPU1 PSPR    */
  11U,                  /* 08: CPU1 PTAG    */
  0U,                   /* 09: CPU2 DSPR    */
  21U,                  /* 10: CPU2 DSPR2   */
  2U,                   /* 11: CPU2 DTAG    */
  3U,                   /* 12: CPU2 PSPR    */
  5U,                   /* 13: CPU2 PTAG    */
  79U,                  /* 14: DAM (LMU)    */
};

#elif (CHIP_ID == 27U)

/* Lookup table to get memory controller index from memory index: */
const uint8 SramEccTst_kMcTable[SRAMECCTST_MEMORY_COUNT] =
{
  14U,                  /* 00: CPU0 DSPR    */
  SRAM_MC_IDX_INVALID,  /* 01: Reserved     */
  16U,                  /* 02: CPU0 PSPR    */
  17U,                  /* 03: CPU0 PTAG    */
  6U,                   /* 04: CPU1 DSPR    */
  SRAM_MC_IDX_INVALID,  /* 05: Reserved     */
  8U,                   /* 06: CPU1 DTAG    */
  9U,                   /* 07: CPU1 PSPR    */
  11U,                  /* 08: CPU1 PTAG    */
  0U,                   /* 09: CPU2 DSPR    */
  SRAM_MC_IDX_INVALID,  /* 10: Reserved     */
  2U,                   /* 11: CPU2 DTAG    */
  3U,                   /* 12: CPU2 PSPR    */
  5U,                   /* 13: CPU2 PTAG    */
  79U,                  /* 14: DAM (LMU)    */
};

#elif(CHIP_ID == 26U)

/* Lookup table to get memory controller index from memory index: */
const uint8 SramEccTst_kMcTable[SRAMECCTST_MEMORY_COUNT] =
{
  14U,                  /* 00: CPU0 DSPR    */
  SRAM_MC_IDX_INVALID,  /* 01: Reserved     */
  16U,                  /* 02: CPU0 PSPR    */
  17U,                  /* 03: CPU0 PTAG    */
  6U,                   /* 04: CPU1 DSPR    */
  SRAM_MC_IDX_INVALID,  /* 05: Reserved     */
  8U,                   /* 06: CPU1 DTAG    */
  9U,                   /* 07: CPU1 PSPR    */
  11U,                   /* 08: CPU1 PTAG    */
  SRAM_MC_IDX_INVALID,  /* 09: Reserved         */
  SRAM_MC_IDX_INVALID,  /* 09: Reserved         */
  SRAM_MC_IDX_INVALID,  /* 09: Reserved         */
  SRAM_MC_IDX_INVALID,  /* 09: Reserved         */
  SRAM_MC_IDX_INVALID,  /* 09: Reserved         */
  SRAM_MC_IDX_INVALID,  /* 09: Reserved         */      
};

#elif ( (CHIP_ID == 24U)||(CHIP_ID == 23U) || (CHIP_ID == 22U) || (CHIP_ID == 21U) )

/* Lookup table to get memory controller index from memory index: */
const uint8 SramEccTst_kMcTable[SRAMECCTST_MEMORY_COUNT] =
{
  14U,                  /* 00: CPU0 DSPR    */
  SRAM_MC_IDX_INVALID,  /* 01: Reserved     */
  16U,                  /* 02: CPU0 PSPR    */
  17U,                  /* 03: CPU0 PTAG    */
  SRAM_MC_IDX_INVALID,  /* 04: Reserved     */
  SRAM_MC_IDX_INVALID,  /* 05: Reserved     */
  SRAM_MC_IDX_INVALID,  /* 06: Reserved     */
  SRAM_MC_IDX_INVALID,  /* 07: Reserved     */
  SRAM_MC_IDX_INVALID,  /* 08: Reserved     */
  SRAM_MC_IDX_INVALID,  /* 09: Reserved     */
  SRAM_MC_IDX_INVALID,  /* 10: Reserved     */
  SRAM_MC_IDX_INVALID,  /* 11: Reserved     */
  SRAM_MC_IDX_INVALID,  /* 12: Reserved     */
  SRAM_MC_IDX_INVALID,  /* 13: Reserved     */
  79U,                  /* 14: DAM (LMU)    */
};

#endif

#define IFX_SRAM_STOP_SEC_CONST_8BIT_ASIL_B
#include "Ifx_MemMap.h"
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

