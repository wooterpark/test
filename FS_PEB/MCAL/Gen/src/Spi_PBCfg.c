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
**  FILENAME  : Spi_PBCfg.c                                                   **
**                                                                            **
**  $CC VERSION : \main\92 $                                                 **
**                                                                            **
**  DATE, TIME: 2021-09-29, 16:08:33                                         **
**                                                                            **
**  GENERATOR : Build b141014-0350                                            **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : SPI configuration generated out of ECU configuration       **
**                 file                                                       **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Include SPI Module File */
/* [cover parentID=DS_NAS_SPI_PR699,DS_NAS_SPI_PR709] */

#include "Spi.h"
/* Inclusion of Mcal Specific Global Header File */
#include "Mcal.h"

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/
/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
/* MISRA RULE 87 VIOLATION: Inclusion of MemMap.h in between the code can't
   be avoided as it is required for mapping global variables, constants
   and code
*/
/* Violates MISRA Required Rule 16.9,
            function identifier used without '&' or parenthisized parameter list
           when using function pointer in configurations
*/

/*
                     Container: SpiChannelConfiguration
*/
#define SPI_START_SEC_POSTBUILDCFG
/*
 * To be used for global or static constants (unspecified size)
*/
#include "MemMap.h"
/*
Configuration : Channel Configuration Constant Structure.
The IB Channels are configured first followed by EB.
*/
static const Spi_ChannelConfigType Spi_kChannelConfig0[] =
{
/* EB Channel: SpiChannel_WrH_PRW Configuration */
  {
    /* Default Data, SPI_DEFAULT_DATA */
    (uint32)0x00000000U,
    /* Data Configuration */
    Spi_DataConfig(16U, /* Data Width */
                   SPI_DATA_MSB_FIRST), /* Transfer Start */
        /* EB Channels : SPI112: Max EB Buffers  */
    (Spi_NumberOfDataType)50U,
    /* Buffer Type, SPI_CHANNEL_TYPE */
    (uint8)SPI_EB_BUFFER,
  },
/* EB Channel: SpiChannel_WrL_PRW Configuration */
  {
    /* Default Data, SPI_DEFAULT_DATA */
    (uint32)0x00000000U,
    /* Data Configuration */
    Spi_DataConfig(16U, /* Data Width */
                   SPI_DATA_MSB_FIRST), /* Transfer Start */
        /* EB Channels : SPI112: Max EB Buffers  */
    (Spi_NumberOfDataType)50U,
    /* Buffer Type, SPI_CHANNEL_TYPE */
    (uint8)SPI_EB_BUFFER,
  },
/* EB Channel: SpiChannel_Rd_PSTAT Configuration */
  {
    /* Default Data, SPI_DEFAULT_DATA */
    (uint32)0x00000000U,
    /* Data Configuration */
    Spi_DataConfig(16U, /* Data Width */
                   SPI_DATA_MSB_FIRST), /* Transfer Start */
        /* EB Channels : SPI112: Max EB Buffers  */
    (Spi_NumberOfDataType)50U,
    /* Buffer Type, SPI_CHANNEL_TYPE */
    (uint8)SPI_EB_BUFFER,
  },
/* EB Channel: SpiChannel_Rd_PSTAT2 Configuration */
  {
    /* Default Data, SPI_DEFAULT_DATA */
    (uint32)0x00000000U,
    /* Data Configuration */
    Spi_DataConfig(16U, /* Data Width */
                   SPI_DATA_MSB_FIRST), /* Transfer Start */
        /* EB Channels : SPI112: Max EB Buffers  */
    (Spi_NumberOfDataType)50U,
    /* Buffer Type, SPI_CHANNEL_TYPE */
    (uint8)SPI_EB_BUFFER,
  },
/* EB Channel: SpiChannel_Rd_PER Configuration */
  {
    /* Default Data, SPI_DEFAULT_DATA */
    (uint32)0x00000000U,
    /* Data Configuration */
    Spi_DataConfig(16U, /* Data Width */
                   SPI_DATA_MSB_FIRST), /* Transfer Start */
        /* EB Channels : SPI112: Max EB Buffers  */
    (Spi_NumberOfDataType)50U,
    /* Buffer Type, SPI_CHANNEL_TYPE */
    (uint8)SPI_EB_BUFFER,
  },
/* EB Channel: SpiChannel_Rd_PPIN Configuration */
  {
    /* Default Data, SPI_DEFAULT_DATA */
    (uint32)0x00000000U,
    /* Data Configuration */
    Spi_DataConfig(16U, /* Data Width */
                   SPI_DATA_MSB_FIRST), /* Transfer Start */
        /* EB Channels : SPI112: Max EB Buffers  */
    (Spi_NumberOfDataType)50U,
    /* Buffer Type, SPI_CHANNEL_TYPE */
    (uint8)SPI_EB_BUFFER,
  },
/* EB Channel: SpiChannel_Rd_PCS Configuration */
  {
    /* Default Data, SPI_DEFAULT_DATA */
    (uint32)0x00000000U,
    /* Data Configuration */
    Spi_DataConfig(16U, /* Data Width */
                   SPI_DATA_MSB_FIRST), /* Transfer Start */
        /* EB Channels : SPI112: Max EB Buffers  */
    (Spi_NumberOfDataType)50U,
    /* Buffer Type, SPI_CHANNEL_TYPE */
    (uint8)SPI_EB_BUFFER,
  },
/* EB Channel: SpiChannel_Rd_SSTAT Configuration */
  {
    /* Default Data, SPI_DEFAULT_DATA */
    (uint32)0x00000000U,
    /* Data Configuration */
    Spi_DataConfig(16U, /* Data Width */
                   SPI_DATA_MSB_FIRST), /* Transfer Start */
        /* EB Channels : SPI112: Max EB Buffers  */
    (Spi_NumberOfDataType)50U,
    /* Buffer Type, SPI_CHANNEL_TYPE */
    (uint8)SPI_EB_BUFFER,
  },
/* EB Channel: SpiChannel_Rd_SSTAT2 Configuration */
  {
    /* Default Data, SPI_DEFAULT_DATA */
    (uint32)0x00000000U,
    /* Data Configuration */
    Spi_DataConfig(16U, /* Data Width */
                   SPI_DATA_MSB_FIRST), /* Transfer Start */
        /* EB Channels : SPI112: Max EB Buffers  */
    (Spi_NumberOfDataType)50U,
    /* Buffer Type, SPI_CHANNEL_TYPE */
    (uint8)SPI_EB_BUFFER,
  },
/* EB Channel: SpiChannel_Rd_SER Configuration */
  {
    /* Default Data, SPI_DEFAULT_DATA */
    (uint32)0x00000000U,
    /* Data Configuration */
    Spi_DataConfig(16U, /* Data Width */
                   SPI_DATA_MSB_FIRST), /* Transfer Start */
        /* EB Channels : SPI112: Max EB Buffers  */
    (Spi_NumberOfDataType)50U,
    /* Buffer Type, SPI_CHANNEL_TYPE */
    (uint8)SPI_EB_BUFFER,
  },
/* EB Channel: SpiChannel_Rd_SGM1 Configuration */
  {
    /* Default Data, SPI_DEFAULT_DATA */
    (uint32)0x00000000U,
    /* Data Configuration */
    Spi_DataConfig(16U, /* Data Width */
                   SPI_DATA_MSB_FIRST), /* Transfer Start */
        /* EB Channels : SPI112: Max EB Buffers  */
    (Spi_NumberOfDataType)50U,
    /* Buffer Type, SPI_CHANNEL_TYPE */
    (uint8)SPI_EB_BUFFER,
  },
/* EB Channel: SpiChannel_Rd_SGM2 Configuration */
  {
    /* Default Data, SPI_DEFAULT_DATA */
    (uint32)0x00000000U,
    /* Data Configuration */
    Spi_DataConfig(16U, /* Data Width */
                   SPI_DATA_MSB_FIRST), /* Transfer Start */
        /* EB Channels : SPI112: Max EB Buffers  */
    (Spi_NumberOfDataType)50U,
    /* Buffer Type, SPI_CHANNEL_TYPE */
    (uint8)SPI_EB_BUFFER,
  },
/* EB Channel: SpiChannel_Rd_SCS Configuration */
  {
    /* Default Data, SPI_DEFAULT_DATA */
    (uint32)0x00000000U,
    /* Data Configuration */
    Spi_DataConfig(16U, /* Data Width */
                   SPI_DATA_MSB_FIRST), /* Transfer Start */
        /* EB Channels : SPI112: Max EB Buffers  */
    (Spi_NumberOfDataType)50U,
    /* Buffer Type, SPI_CHANNEL_TYPE */
    (uint8)SPI_EB_BUFFER,
  },
/* EB Channel: SpiChannel_ModeCtrl Configuration */
  {
    /* Default Data, SPI_DEFAULT_DATA */
    (uint32)0x00000000U,
    /* Data Configuration */
    Spi_DataConfig(16U, /* Data Width */
                   SPI_DATA_MSB_FIRST), /* Transfer Start */
        /* EB Channels : SPI112: Max EB Buffers  */
    (Spi_NumberOfDataType)50U,
    /* Buffer Type, SPI_CHANNEL_TYPE */
    (uint8)SPI_EB_BUFFER,
  },
/* EB Channel: SpiChannel_WrH Configuration */
  {
    /* Default Data, SPI_DEFAULT_DATA */
    (uint32)0x00000000U,
    /* Data Configuration */
    Spi_DataConfig(16U, /* Data Width */
                   SPI_DATA_MSB_FIRST), /* Transfer Start */
        /* EB Channels : SPI112: Max EB Buffers  */
    (Spi_NumberOfDataType)50U,
    /* Buffer Type, SPI_CHANNEL_TYPE */
    (uint8)SPI_EB_BUFFER,
  },
/* EB Channel: SpiChannel_WrL Configuration */
  {
    /* Default Data, SPI_DEFAULT_DATA */
    (uint32)0x00000000U,
    /* Data Configuration */
    Spi_DataConfig(16U, /* Data Width */
                   SPI_DATA_MSB_FIRST), /* Transfer Start */
        /* EB Channels : SPI112: Max EB Buffers  */
    (Spi_NumberOfDataType)50U,
    /* Buffer Type, SPI_CHANNEL_TYPE */
    (uint8)SPI_EB_BUFFER,
  },
/* EB Channel: SpiChannel_Other Configuration */
  {
    /* Default Data, SPI_DEFAULT_DATA */
    (uint32)0x00000000U,
    /* Data Configuration */
    Spi_DataConfig(16U, /* Data Width */
                   SPI_DATA_MSB_FIRST), /* Transfer Start */
        /* EB Channels : SPI112: Max EB Buffers  */
    (Spi_NumberOfDataType)50U,
    /* Buffer Type, SPI_CHANNEL_TYPE */
    (uint8)SPI_EB_BUFFER,
  },
/* EB Channel: SpiChannel_Rd_PCTRL Configuration */
  {
    /* Default Data, SPI_DEFAULT_DATA */
    (uint32)0x00000000U,
    /* Data Configuration */
    Spi_DataConfig(16U, /* Data Width */
                   SPI_DATA_MSB_FIRST), /* Transfer Start */
        /* EB Channels : SPI112: Max EB Buffers  */
    (Spi_NumberOfDataType)50U,
    /* Buffer Type, SPI_CHANNEL_TYPE */
    (uint8)SPI_EB_BUFFER,
  },
/* EB Channel: SpiChannel_Rd_PCTRL2 Configuration */
  {
    /* Default Data, SPI_DEFAULT_DATA */
    (uint32)0x00000000U,
    /* Data Configuration */
    Spi_DataConfig(16U, /* Data Width */
                   SPI_DATA_MSB_FIRST), /* Transfer Start */
        /* EB Channels : SPI112: Max EB Buffers  */
    (Spi_NumberOfDataType)50U,
    /* Buffer Type, SPI_CHANNEL_TYPE */
    (uint8)SPI_EB_BUFFER,
  },
/* EB Channel: SpiChannel_Rd_SCTRL Configuration */
  {
    /* Default Data, SPI_DEFAULT_DATA */
    (uint32)0x00000000U,
    /* Data Configuration */
    Spi_DataConfig(16U, /* Data Width */
                   SPI_DATA_MSB_FIRST), /* Transfer Start */
        /* EB Channels : SPI112: Max EB Buffers  */
    (Spi_NumberOfDataType)50U,
    /* Buffer Type, SPI_CHANNEL_TYPE */
    (uint8)SPI_EB_BUFFER,
  },
/* EB Channel: SpiChannel_Rd_PRW Configuration */
  {
    /* Default Data, SPI_DEFAULT_DATA */
    (uint32)0x00000000U,
    /* Data Configuration */
    Spi_DataConfig(16U, /* Data Width */
                   SPI_DATA_MSB_FIRST), /* Transfer Start */
        /* EB Channels : SPI112: Max EB Buffers  */
    (Spi_NumberOfDataType)50U,
    /* Buffer Type, SPI_CHANNEL_TYPE */
    (uint8)SPI_EB_BUFFER,
  },
/* EB Channel: SpiChannel_Nop Configuration */
  {
    /* Default Data, SPI_DEFAULT_DATA */
    (uint32)0x00000000U,
    /* Data Configuration */
    Spi_DataConfig(16U, /* Data Width */
                   SPI_DATA_MSB_FIRST), /* Transfer Start */
        /* EB Channels : SPI112: Max EB Buffers  */
    (Spi_NumberOfDataType)50U,
    /* Buffer Type, SPI_CHANNEL_TYPE */
    (uint8)SPI_EB_BUFFER,
  },
/* EB Channel: SpiChannel_WrL_PCTRL Configuration */
  {
    /* Default Data, SPI_DEFAULT_DATA */
    (uint32)0x00000000U,
    /* Data Configuration */
    Spi_DataConfig(16U, /* Data Width */
                   SPI_DATA_MSB_FIRST), /* Transfer Start */
        /* EB Channels : SPI112: Max EB Buffers  */
    (Spi_NumberOfDataType)50U,
    /* Buffer Type, SPI_CHANNEL_TYPE */
    (uint8)SPI_EB_BUFFER,
  },
/* EB Channel: SpiChannel_WrL_PCTRL2 Configuration */
  {
    /* Default Data, SPI_DEFAULT_DATA */
    (uint32)0x00000000U,
    /* Data Configuration */
    Spi_DataConfig(16U, /* Data Width */
                   SPI_DATA_MSB_FIRST), /* Transfer Start */
        /* EB Channels : SPI112: Max EB Buffers  */
    (Spi_NumberOfDataType)50U,
    /* Buffer Type, SPI_CHANNEL_TYPE */
    (uint8)SPI_EB_BUFFER,
  },
/* EB Channel: SpiChannel_PCFG Configuration */
  {
    /* Default Data, SPI_DEFAULT_DATA */
    (uint32)0x00000000U,
    /* Data Configuration */
    Spi_DataConfig(16U, /* Data Width */
                   SPI_DATA_MSB_FIRST), /* Transfer Start */
        /* EB Channels : SPI112: Max EB Buffers  */
    (Spi_NumberOfDataType)50U,
    /* Buffer Type, SPI_CHANNEL_TYPE */
    (uint8)SPI_EB_BUFFER,
  },
/* EB Channel: SpiChannel_PCFG2 Configuration */
  {
    /* Default Data, SPI_DEFAULT_DATA */
    (uint32)0x00000000U,
    /* Data Configuration */
    Spi_DataConfig(16U, /* Data Width */
                   SPI_DATA_MSB_FIRST), /* Transfer Start */
        /* EB Channels : SPI112: Max EB Buffers  */
    (Spi_NumberOfDataType)50U,
    /* Buffer Type, SPI_CHANNEL_TYPE */
    (uint8)SPI_EB_BUFFER,
  },
/* EB Channel: SpiChannel_PCTRL Configuration */
  {
    /* Default Data, SPI_DEFAULT_DATA */
    (uint32)0x00000000U,
    /* Data Configuration */
    Spi_DataConfig(16U, /* Data Width */
                   SPI_DATA_MSB_FIRST), /* Transfer Start */
        /* EB Channels : SPI112: Max EB Buffers  */
    (Spi_NumberOfDataType)50U,
    /* Buffer Type, SPI_CHANNEL_TYPE */
    (uint8)SPI_EB_BUFFER,
  },
/* EB Channel: SpiChannel_PCTRL2 Configuration */
  {
    /* Default Data, SPI_DEFAULT_DATA */
    (uint32)0x00000000U,
    /* Data Configuration */
    Spi_DataConfig(16U, /* Data Width */
                   SPI_DATA_MSB_FIRST), /* Transfer Start */
        /* EB Channels : SPI112: Max EB Buffers  */
    (Spi_NumberOfDataType)50U,
    /* Buffer Type, SPI_CHANNEL_TYPE */
    (uint8)SPI_EB_BUFFER,
  },
/* EB Channel: SpiChannel_PSCR Configuration */
  {
    /* Default Data, SPI_DEFAULT_DATA */
    (uint32)0x00000000U,
    /* Data Configuration */
    Spi_DataConfig(16U, /* Data Width */
                   SPI_DATA_MSB_FIRST), /* Transfer Start */
        /* EB Channels : SPI112: Max EB Buffers  */
    (Spi_NumberOfDataType)50U,
    /* Buffer Type, SPI_CHANNEL_TYPE */
    (uint8)SPI_EB_BUFFER,
  },
/* EB Channel: SpiChannel_PRW Configuration */
  {
    /* Default Data, SPI_DEFAULT_DATA */
    (uint32)0x00000000U,
    /* Data Configuration */
    Spi_DataConfig(16U, /* Data Width */
                   SPI_DATA_MSB_FIRST), /* Transfer Start */
        /* EB Channels : SPI112: Max EB Buffers  */
    (Spi_NumberOfDataType)50U,
    /* Buffer Type, SPI_CHANNEL_TYPE */
    (uint8)SPI_EB_BUFFER,
  },
/* EB Channel: SpiChannel_SCFG Configuration */
  {
    /* Default Data, SPI_DEFAULT_DATA */
    (uint32)0x00000000U,
    /* Data Configuration */
    Spi_DataConfig(16U, /* Data Width */
                   SPI_DATA_MSB_FIRST), /* Transfer Start */
        /* EB Channels : SPI112: Max EB Buffers  */
    (Spi_NumberOfDataType)50U,
    /* Buffer Type, SPI_CHANNEL_TYPE */
    (uint8)SPI_EB_BUFFER,
  },
/* EB Channel: SpiChannel_SCFG2 Configuration */
  {
    /* Default Data, SPI_DEFAULT_DATA */
    (uint32)0x00000000U,
    /* Data Configuration */
    Spi_DataConfig(16U, /* Data Width */
                   SPI_DATA_MSB_FIRST), /* Transfer Start */
        /* EB Channels : SPI112: Max EB Buffers  */
    (Spi_NumberOfDataType)50U,
    /* Buffer Type, SPI_CHANNEL_TYPE */
    (uint8)SPI_EB_BUFFER,
  },
/* EB Channel: SpiChannel_SCTRL Configuration */
  {
    /* Default Data, SPI_DEFAULT_DATA */
    (uint32)0x00000000U,
    /* Data Configuration */
    Spi_DataConfig(16U, /* Data Width */
                   SPI_DATA_MSB_FIRST), /* Transfer Start */
        /* EB Channels : SPI112: Max EB Buffers  */
    (Spi_NumberOfDataType)50U,
    /* Buffer Type, SPI_CHANNEL_TYPE */
    (uint8)SPI_EB_BUFFER,
  },
/* EB Channel: SpiChannel_SSCR Configuration */
  {
    /* Default Data, SPI_DEFAULT_DATA */
    (uint32)0x00000000U,
    /* Data Configuration */
    Spi_DataConfig(16U, /* Data Width */
                   SPI_DATA_MSB_FIRST), /* Transfer Start */
        /* EB Channels : SPI112: Max EB Buffers  */
    (Spi_NumberOfDataType)50U,
    /* Buffer Type, SPI_CHANNEL_TYPE */
    (uint8)SPI_EB_BUFFER,
  },
/* EB Channel: SpiChannel_SDESAT Configuration */
  {
    /* Default Data, SPI_DEFAULT_DATA */
    (uint32)0x00000000U,
    /* Data Configuration */
    Spi_DataConfig(16U, /* Data Width */
                   SPI_DATA_MSB_FIRST), /* Transfer Start */
        /* EB Channels : SPI112: Max EB Buffers  */
    (Spi_NumberOfDataType)50U,
    /* Buffer Type, SPI_CHANNEL_TYPE */
    (uint8)SPI_EB_BUFFER,
  },
/* EB Channel: SpiChannel_SOCP Configuration */
  {
    /* Default Data, SPI_DEFAULT_DATA */
    (uint32)0x00000000U,
    /* Data Configuration */
    Spi_DataConfig(16U, /* Data Width */
                   SPI_DATA_MSB_FIRST), /* Transfer Start */
        /* EB Channels : SPI112: Max EB Buffers  */
    (Spi_NumberOfDataType)50U,
    /* Buffer Type, SPI_CHANNEL_TYPE */
    (uint8)SPI_EB_BUFFER,
  },
/* EB Channel: SpiChannel_SRTTOF Configuration */
  {
    /* Default Data, SPI_DEFAULT_DATA */
    (uint32)0x00000000U,
    /* Data Configuration */
    Spi_DataConfig(16U, /* Data Width */
                   SPI_DATA_MSB_FIRST), /* Transfer Start */
        /* EB Channels : SPI112: Max EB Buffers  */
    (Spi_NumberOfDataType)50U,
    /* Buffer Type, SPI_CHANNEL_TYPE */
    (uint8)SPI_EB_BUFFER,
  },
/* EB Channel: SpiChannel_SSTTOF Configuration */
  {
    /* Default Data, SPI_DEFAULT_DATA */
    (uint32)0x00000000U,
    /* Data Configuration */
    Spi_DataConfig(16U, /* Data Width */
                   SPI_DATA_MSB_FIRST), /* Transfer Start */
        /* EB Channels : SPI112: Max EB Buffers  */
    (Spi_NumberOfDataType)50U,
    /* Buffer Type, SPI_CHANNEL_TYPE */
    (uint8)SPI_EB_BUFFER,
  },
/* EB Channel: SpiChannel_SACLT Configuration */
  {
    /* Default Data, SPI_DEFAULT_DATA */
    (uint32)0x00000000U,
    /* Data Configuration */
    Spi_DataConfig(16U, /* Data Width */
                   SPI_DATA_MSB_FIRST), /* Transfer Start */
        /* EB Channels : SPI112: Max EB Buffers  */
    (Spi_NumberOfDataType)50U,
    /* Buffer Type, SPI_CHANNEL_TYPE */
    (uint8)SPI_EB_BUFFER,
  },
/* EB Channel: SpiChannel_CONF_Nop Configuration */
  {
    /* Default Data, SPI_DEFAULT_DATA */
    (uint32)0x00000000U,
    /* Data Configuration */
    Spi_DataConfig(16U, /* Data Width */
                   SPI_DATA_MSB_FIRST), /* Transfer Start */
        /* EB Channels : SPI112: Max EB Buffers  */
    (Spi_NumberOfDataType)50U,
    /* Buffer Type, SPI_CHANNEL_TYPE */
    (uint8)SPI_EB_BUFFER,
  },
/* EB Channel: SpiChannel_TLF35584 Configuration */
  {
    /* Default Data, SPI_DEFAULT_DATA */
    (uint32)0x00000000U,
    /* Data Configuration */
    Spi_DataConfig(16U, /* Data Width */
                   SPI_DATA_MSB_FIRST), /* Transfer Start */
        /* EB Channels : SPI112: Max EB Buffers  */
    (Spi_NumberOfDataType)8190U,
    /* Buffer Type, SPI_CHANNEL_TYPE */
    (uint8)SPI_EB_BUFFER,
  },
/* EB Channel: SpiChannel_CPLD Configuration */
  {
    /* Default Data, SPI_DEFAULT_DATA */
    (uint32)0x00000003U,
    /* Data Configuration */
    Spi_DataConfig(32U, /* Data Width */
                   SPI_DATA_MSB_FIRST), /* Transfer Start */
        /* EB Channels : SPI112: Max EB Buffers  */
    (Spi_NumberOfDataType)30U,
    /* Buffer Type, SPI_CHANNEL_TYPE */
    (uint8)SPI_EB_BUFFER,
  },
/* EB Channel: SpiChannel_TJA1145 Configuration */
  {
    /* Default Data, SPI_DEFAULT_DATA */
    (uint32)0x00000000U,
    /* Data Configuration */
    Spi_DataConfig(16U, /* Data Width */
                   SPI_DATA_MSB_FIRST), /* Transfer Start */
        /* EB Channels : SPI112: Max EB Buffers  */
    (Spi_NumberOfDataType)30U,
    /* Buffer Type, SPI_CHANNEL_TYPE */
    (uint8)SPI_EB_BUFFER,
  },
};

/*
                    Container: SpiJobConfiguration
*/
/* Notification Function of SpiJob_WrH_PRW is NULL_PTR */
/* Notification Function of SpiJob_WrL_PRW is NULL_PTR */
/* Notification Function of SpiJob_Rd_PSTAT is NULL_PTR */
/* Notification Function of SpiJob_Rd_PSTAT2 is NULL_PTR */
/* Notification Function of SpiJob_Rd_PER is NULL_PTR */
/* Notification Function of SpiJob_Rd_PPIN is NULL_PTR */
/* Notification Function of SpiJob_Rd_PCS is NULL_PTR */
/* Notification Function of SpiJob_Rd_SSTAT is NULL_PTR */
/* Notification Function of SpiJob_Rd_SSTAT2 is NULL_PTR */
/* Notification Function of SpiJob_Rd_SER is NULL_PTR */
/* Notification Function of SpiJob_PCTRL is NULL_PTR */
/* Notification Function of SpiJob_PCTRL2 is NULL_PTR */
/* Notification Function of SpiJob_Nop is NULL_PTR */
/* Notification Function of SpiJob_ModeCtrl is NULL_PTR */
/* Notification Function of SpiJob_WrH is NULL_PTR */
/* Notification Function of SpiJob_WrL is NULL_PTR */
/* Notification Function of SpiJob_Other is NULL_PTR */
/* Notification Function of SpiJob_Rd_SGM1 is NULL_PTR */
/* Notification Function of SpiJob_Rd_SGM2 is NULL_PTR */
/* Notification Function of SpiJob_Rd_SCS is NULL_PTR */
/* Notification Function of SpiJob_Rd_SCTRL is NULL_PTR */
/* Notification Function of SpiJob_Rd_PRW is NULL_PTR */
/* Notification Function of SpiJob_WrL_PCTRL is NULL_PTR */
/* Notification Function of SpiJob_WrL_PCTRL2 is NULL_PTR */
/* Notification Function of SpiJob_PCFG is NULL_PTR */
/* Notification Function of SpiJob_PCFG2 is NULL_PTR */
/* Notification Function of SpiJob_CONF_PCTRL is NULL_PTR */
/* Notification Function of SpiJob_CONF_PCTRL2 is NULL_PTR */
/* Notification Function of SpiJob_PSCR is NULL_PTR */
/* Notification Function of SpiJob_PRW is NULL_PTR */
/* Notification Function of SpiJob_SCFG is NULL_PTR */
/* Notification Function of SpiJob_SCFG2 is NULL_PTR */
/* Notification Function of SpiJob_SCTRL is NULL_PTR */
/* Notification Function of SpiJob_SSCR is NULL_PTR */
/* Notification Function of SpiJob_SDESAT is NULL_PTR */
/* Notification Function of SpiJob_SOCP is NULL_PTR */
/* Notification Function of SpiJob_SRTTOF is NULL_PTR */
/* Notification Function of SpiJob_SSTTOF is NULL_PTR */
/* Notification Function of SpiJob_SACLT is NULL_PTR */
/* Notification Function of SpiJob_CONF_Nop is NULL_PTR */
/* Notification Function of SpiJob_TLF35584 is NULL_PTR */
/* Notification Function of SpiJob_CPLD is NULL_PTR */
/* Notification Function of SpiJob_TJA1145 is NULL_PTR */


/*
Configuration: Channel Assignment
*/
/*Channel Assignment of Job: SpiJob_WrH_PRW*/
static const Spi_ChannelType SpiJob_WrH_PRW_ChannelLinkPtr[] =
{
  SpiConf_SpiChannel_SpiChannel_WrH_PRW,
  SPI_CHANNEL_LINK_DELIMITER
};
/*
Configuration: Channel Assignment
*/
/*Channel Assignment of Job: SpiJob_WrL_PRW*/
static const Spi_ChannelType SpiJob_WrL_PRW_ChannelLinkPtr[] =
{
  SpiConf_SpiChannel_SpiChannel_WrL_PRW,
  SPI_CHANNEL_LINK_DELIMITER
};
/*
Configuration: Channel Assignment
*/
/*Channel Assignment of Job: SpiJob_Rd_PSTAT*/
static const Spi_ChannelType SpiJob_Rd_PSTAT_ChannelLinkPtr[] =
{
  SpiConf_SpiChannel_SpiChannel_Rd_PSTAT,
  SPI_CHANNEL_LINK_DELIMITER
};
/*
Configuration: Channel Assignment
*/
/*Channel Assignment of Job: SpiJob_Rd_PSTAT2*/
static const Spi_ChannelType SpiJob_Rd_PSTAT2_ChannelLinkPtr[] =
{
  SpiConf_SpiChannel_SpiChannel_Rd_PSTAT2,
  SPI_CHANNEL_LINK_DELIMITER
};
/*
Configuration: Channel Assignment
*/
/*Channel Assignment of Job: SpiJob_Rd_PER*/
static const Spi_ChannelType SpiJob_Rd_PER_ChannelLinkPtr[] =
{
  SpiConf_SpiChannel_SpiChannel_Rd_PER,
  SPI_CHANNEL_LINK_DELIMITER
};
/*
Configuration: Channel Assignment
*/
/*Channel Assignment of Job: SpiJob_Rd_PPIN*/
static const Spi_ChannelType SpiJob_Rd_PPIN_ChannelLinkPtr[] =
{
  SpiConf_SpiChannel_SpiChannel_Rd_PPIN,
  SPI_CHANNEL_LINK_DELIMITER
};
/*
Configuration: Channel Assignment
*/
/*Channel Assignment of Job: SpiJob_Rd_PCS*/
static const Spi_ChannelType SpiJob_Rd_PCS_ChannelLinkPtr[] =
{
  SpiConf_SpiChannel_SpiChannel_Rd_PCS,
  SPI_CHANNEL_LINK_DELIMITER
};
/*
Configuration: Channel Assignment
*/
/*Channel Assignment of Job: SpiJob_Rd_SSTAT*/
static const Spi_ChannelType SpiJob_Rd_SSTAT_ChannelLinkPtr[] =
{
  SpiConf_SpiChannel_SpiChannel_Rd_SSTAT,
  SPI_CHANNEL_LINK_DELIMITER
};
/*
Configuration: Channel Assignment
*/
/*Channel Assignment of Job: SpiJob_Rd_SSTAT2*/
static const Spi_ChannelType SpiJob_Rd_SSTAT2_ChannelLinkPtr[] =
{
  SpiConf_SpiChannel_SpiChannel_Rd_SSTAT2,
  SPI_CHANNEL_LINK_DELIMITER
};
/*
Configuration: Channel Assignment
*/
/*Channel Assignment of Job: SpiJob_Rd_SER*/
static const Spi_ChannelType SpiJob_Rd_SER_ChannelLinkPtr[] =
{
  SpiConf_SpiChannel_SpiChannel_Rd_SER,
  SPI_CHANNEL_LINK_DELIMITER
};
/*
Configuration: Channel Assignment
*/
/*Channel Assignment of Job: SpiJob_PCTRL*/
static const Spi_ChannelType SpiJob_PCTRL_ChannelLinkPtr[] =
{
  SpiConf_SpiChannel_SpiChannel_Rd_PCTRL,
  SPI_CHANNEL_LINK_DELIMITER
};
/*
Configuration: Channel Assignment
*/
/*Channel Assignment of Job: SpiJob_PCTRL2*/
static const Spi_ChannelType SpiJob_PCTRL2_ChannelLinkPtr[] =
{
  SpiConf_SpiChannel_SpiChannel_Rd_PCTRL2,
  SPI_CHANNEL_LINK_DELIMITER
};
/*
Configuration: Channel Assignment
*/
/*Channel Assignment of Job: SpiJob_Nop*/
static const Spi_ChannelType SpiJob_Nop_ChannelLinkPtr[] =
{
  SpiConf_SpiChannel_SpiChannel_Nop,
  SPI_CHANNEL_LINK_DELIMITER
};
/*
Configuration: Channel Assignment
*/
/*Channel Assignment of Job: SpiJob_ModeCtrl*/
static const Spi_ChannelType SpiJob_ModeCtrl_ChannelLinkPtr[] =
{
  SpiConf_SpiChannel_SpiChannel_ModeCtrl,
  SPI_CHANNEL_LINK_DELIMITER
};
/*
Configuration: Channel Assignment
*/
/*Channel Assignment of Job: SpiJob_WrH*/
static const Spi_ChannelType SpiJob_WrH_ChannelLinkPtr[] =
{
  SpiConf_SpiChannel_SpiChannel_WrH,
  SPI_CHANNEL_LINK_DELIMITER
};
/*
Configuration: Channel Assignment
*/
/*Channel Assignment of Job: SpiJob_WrL*/
static const Spi_ChannelType SpiJob_WrL_ChannelLinkPtr[] =
{
  SpiConf_SpiChannel_SpiChannel_WrL,
  SPI_CHANNEL_LINK_DELIMITER
};
/*
Configuration: Channel Assignment
*/
/*Channel Assignment of Job: SpiJob_Other*/
static const Spi_ChannelType SpiJob_Other_ChannelLinkPtr[] =
{
  SpiConf_SpiChannel_SpiChannel_Other,
  SPI_CHANNEL_LINK_DELIMITER
};
/*
Configuration: Channel Assignment
*/
/*Channel Assignment of Job: SpiJob_Rd_SGM1*/
static const Spi_ChannelType SpiJob_Rd_SGM1_ChannelLinkPtr[] =
{
  SpiConf_SpiChannel_SpiChannel_Rd_SGM1,
  SPI_CHANNEL_LINK_DELIMITER
};
/*
Configuration: Channel Assignment
*/
/*Channel Assignment of Job: SpiJob_Rd_SGM2*/
static const Spi_ChannelType SpiJob_Rd_SGM2_ChannelLinkPtr[] =
{
  SpiConf_SpiChannel_SpiChannel_Rd_SGM2,
  SPI_CHANNEL_LINK_DELIMITER
};
/*
Configuration: Channel Assignment
*/
/*Channel Assignment of Job: SpiJob_Rd_SCS*/
static const Spi_ChannelType SpiJob_Rd_SCS_ChannelLinkPtr[] =
{
  SpiConf_SpiChannel_SpiChannel_Rd_SCS,
  SPI_CHANNEL_LINK_DELIMITER
};
/*
Configuration: Channel Assignment
*/
/*Channel Assignment of Job: SpiJob_Rd_SCTRL*/
static const Spi_ChannelType SpiJob_Rd_SCTRL_ChannelLinkPtr[] =
{
  SpiConf_SpiChannel_SpiChannel_Rd_SCTRL,
  SPI_CHANNEL_LINK_DELIMITER
};
/*
Configuration: Channel Assignment
*/
/*Channel Assignment of Job: SpiJob_Rd_PRW*/
static const Spi_ChannelType SpiJob_Rd_PRW_ChannelLinkPtr[] =
{
  SpiConf_SpiChannel_SpiChannel_Rd_PRW,
  SPI_CHANNEL_LINK_DELIMITER
};
/*
Configuration: Channel Assignment
*/
/*Channel Assignment of Job: SpiJob_WrL_PCTRL*/
static const Spi_ChannelType SpiJob_WrL_PCTRL_ChannelLinkPtr[] =
{
  SpiConf_SpiChannel_SpiChannel_WrL_PCTRL,
  SPI_CHANNEL_LINK_DELIMITER
};
/*
Configuration: Channel Assignment
*/
/*Channel Assignment of Job: SpiJob_WrL_PCTRL2*/
static const Spi_ChannelType SpiJob_WrL_PCTRL2_ChannelLinkPtr[] =
{
  SpiConf_SpiChannel_SpiChannel_WrL_PCTRL2,
  SPI_CHANNEL_LINK_DELIMITER
};
/*
Configuration: Channel Assignment
*/
/*Channel Assignment of Job: SpiJob_PCFG*/
static const Spi_ChannelType SpiJob_PCFG_ChannelLinkPtr[] =
{
  SpiConf_SpiChannel_SpiChannel_PCFG,
  SPI_CHANNEL_LINK_DELIMITER
};
/*
Configuration: Channel Assignment
*/
/*Channel Assignment of Job: SpiJob_PCFG2*/
static const Spi_ChannelType SpiJob_PCFG2_ChannelLinkPtr[] =
{
  SpiConf_SpiChannel_SpiChannel_PCFG2,
  SPI_CHANNEL_LINK_DELIMITER
};
/*
Configuration: Channel Assignment
*/
/*Channel Assignment of Job: SpiJob_CONF_PCTRL*/
static const Spi_ChannelType SpiJob_CONF_PCTRL_ChannelLinkPtr[] =
{
  SpiConf_SpiChannel_SpiChannel_PCTRL,
  SPI_CHANNEL_LINK_DELIMITER
};
/*
Configuration: Channel Assignment
*/
/*Channel Assignment of Job: SpiJob_CONF_PCTRL2*/
static const Spi_ChannelType SpiJob_CONF_PCTRL2_ChannelLinkPtr[] =
{
  SpiConf_SpiChannel_SpiChannel_PCTRL2,
  SPI_CHANNEL_LINK_DELIMITER
};
/*
Configuration: Channel Assignment
*/
/*Channel Assignment of Job: SpiJob_PSCR*/
static const Spi_ChannelType SpiJob_PSCR_ChannelLinkPtr[] =
{
  SpiConf_SpiChannel_SpiChannel_PSCR,
  SPI_CHANNEL_LINK_DELIMITER
};
/*
Configuration: Channel Assignment
*/
/*Channel Assignment of Job: SpiJob_PRW*/
static const Spi_ChannelType SpiJob_PRW_ChannelLinkPtr[] =
{
  SpiConf_SpiChannel_SpiChannel_PRW,
  SPI_CHANNEL_LINK_DELIMITER
};
/*
Configuration: Channel Assignment
*/
/*Channel Assignment of Job: SpiJob_SCFG*/
static const Spi_ChannelType SpiJob_SCFG_ChannelLinkPtr[] =
{
  SpiConf_SpiChannel_SpiChannel_SCFG,
  SPI_CHANNEL_LINK_DELIMITER
};
/*
Configuration: Channel Assignment
*/
/*Channel Assignment of Job: SpiJob_SCFG2*/
static const Spi_ChannelType SpiJob_SCFG2_ChannelLinkPtr[] =
{
  SpiConf_SpiChannel_SpiChannel_SCFG2,
  SPI_CHANNEL_LINK_DELIMITER
};
/*
Configuration: Channel Assignment
*/
/*Channel Assignment of Job: SpiJob_SCTRL*/
static const Spi_ChannelType SpiJob_SCTRL_ChannelLinkPtr[] =
{
  SpiConf_SpiChannel_SpiChannel_SCTRL,
  SPI_CHANNEL_LINK_DELIMITER
};
/*
Configuration: Channel Assignment
*/
/*Channel Assignment of Job: SpiJob_SSCR*/
static const Spi_ChannelType SpiJob_SSCR_ChannelLinkPtr[] =
{
  SpiConf_SpiChannel_SpiChannel_SSCR,
  SPI_CHANNEL_LINK_DELIMITER
};
/*
Configuration: Channel Assignment
*/
/*Channel Assignment of Job: SpiJob_SDESAT*/
static const Spi_ChannelType SpiJob_SDESAT_ChannelLinkPtr[] =
{
  SpiConf_SpiChannel_SpiChannel_SDESAT,
  SPI_CHANNEL_LINK_DELIMITER
};
/*
Configuration: Channel Assignment
*/
/*Channel Assignment of Job: SpiJob_SOCP*/
static const Spi_ChannelType SpiJob_SOCP_ChannelLinkPtr[] =
{
  SpiConf_SpiChannel_SpiChannel_SOCP,
  SPI_CHANNEL_LINK_DELIMITER
};
/*
Configuration: Channel Assignment
*/
/*Channel Assignment of Job: SpiJob_SRTTOF*/
static const Spi_ChannelType SpiJob_SRTTOF_ChannelLinkPtr[] =
{
  SpiConf_SpiChannel_SpiChannel_SRTTOF,
  SPI_CHANNEL_LINK_DELIMITER
};
/*
Configuration: Channel Assignment
*/
/*Channel Assignment of Job: SpiJob_SSTTOF*/
static const Spi_ChannelType SpiJob_SSTTOF_ChannelLinkPtr[] =
{
  SpiConf_SpiChannel_SpiChannel_SSTTOF,
  SPI_CHANNEL_LINK_DELIMITER
};
/*
Configuration: Channel Assignment
*/
/*Channel Assignment of Job: SpiJob_SACLT*/
static const Spi_ChannelType SpiJob_SACLT_ChannelLinkPtr[] =
{
  SpiConf_SpiChannel_SpiChannel_SACLT,
  SPI_CHANNEL_LINK_DELIMITER
};
/*
Configuration: Channel Assignment
*/
/*Channel Assignment of Job: SpiJob_CONF_Nop*/
static const Spi_ChannelType SpiJob_CONF_Nop_ChannelLinkPtr[] =
{
  SpiConf_SpiChannel_SpiChannel_CONF_Nop,
  SPI_CHANNEL_LINK_DELIMITER
};
/*
Configuration: Channel Assignment
*/
/*Channel Assignment of Job: SpiJob_TLF35584*/
static const Spi_ChannelType SpiJob_TLF35584_ChannelLinkPtr[] =
{
  SpiConf_SpiChannel_SpiChannel_TLF35584,
  SPI_CHANNEL_LINK_DELIMITER
};
/*
Configuration: Channel Assignment
*/
/*Channel Assignment of Job: SpiJob_CPLD*/
static const Spi_ChannelType SpiJob_CPLD_ChannelLinkPtr[] =
{
  SpiConf_SpiChannel_SpiChannel_CPLD,
  SPI_CHANNEL_LINK_DELIMITER
};
/*
Configuration: Channel Assignment
*/
/*Channel Assignment of Job: SpiJob_TJA1145*/
static const Spi_ChannelType SpiJob_TJA1145_ChannelLinkPtr[] =
{
  SpiConf_SpiChannel_SpiChannel_TJA1145,
  SPI_CHANNEL_LINK_DELIMITER
};

/*
Configuration: Job Configuration Constant Structure.
*/
static const Spi_JobConfigType Spi_kJobConfig0[] =
{

/* Job: SpiJob_WrH_PRW Configuration */
  {
   /* Job End Notification: Spi_JobEndNotification, SPI118 */
    NULL_PTR,
    /* User given name outside the naming convention */
    /* Spi_ChannelLinkPtr */
    SpiJob_WrH_PRW_ChannelLinkPtr,
    /* Baud Rate (1388888 Hz) Hw configuration Parameters */
    Spi_BaudRateParams(/*TQ*/(0x3U), /*Q*/(0x2U),
              /*A*/(0x2U), /*B*/(0x0U), /*C*/(0x3U)),

    /* Time Delay Configuration */
      (uint32)Spi_DelayParams(/*IPRE*/0x04U,/*IDLE*/ 0x04U,
        /*LPRE*/0x02U, /*LEAD*/0x06U,
        /*TPRE*/0x02U, /*TRAIL*/0x06U),

    SPI_CS_HW, /* Hw CS Pin is Selected */

    /*CS Active level Polarity*/
    SPI_CS_POLARITY_LOW,

 /* Shift Clock Configuration : Clock Idle Polarity: SPI_SHIFT_CLOCK_IDLE_LEVEL,
                                  Clock Phase: SPI_DATA_SHIFT_EDGE */
    Spi_ShiftClkConfig(SPI_CLK_IDLE_LOW,
                      SPI_DATA_SHIFT_LEAD),
   /* Job Priority escalated to Maximum as it is mapped
      to one or more non-interruptible sequence */
    SPI_JOB_PRIORITY_3,

    /* Spi HW Unit. bit[7:4]: Channel no, bit[3:0]: hw module no */
      (uint8)((uint8)SPI_QSPI_CHANNEL0 << 4U) | (SPI_QSPI2_INDEX),

    /* Channel Based Chip Select */
    (uint8)0U,
    
    /* Spi Parity Selection */
    (uint8)SPI_QSPI_PARITY_UNUSED,
    
  },
/* Job: SpiJob_WrL_PRW Configuration */
  {
   /* Job End Notification: Spi_JobEndNotification, SPI118 */
    NULL_PTR,
    /* User given name outside the naming convention */
    /* Spi_ChannelLinkPtr */
    SpiJob_WrL_PRW_ChannelLinkPtr,
    /* Baud Rate (1388888 Hz) Hw configuration Parameters */
    Spi_BaudRateParams(/*TQ*/(0x3U), /*Q*/(0x2U),
              /*A*/(0x2U), /*B*/(0x0U), /*C*/(0x3U)),

    /* Time Delay Configuration */
      (uint32)Spi_DelayParams(/*IPRE*/0x04U,/*IDLE*/ 0x04U,
        /*LPRE*/0x02U, /*LEAD*/0x06U,
        /*TPRE*/0x02U, /*TRAIL*/0x06U),

    SPI_CS_HW, /* Hw CS Pin is Selected */

    /*CS Active level Polarity*/
    SPI_CS_POLARITY_LOW,

 /* Shift Clock Configuration : Clock Idle Polarity: SPI_SHIFT_CLOCK_IDLE_LEVEL,
                                  Clock Phase: SPI_DATA_SHIFT_EDGE */
    Spi_ShiftClkConfig(SPI_CLK_IDLE_LOW,
                      SPI_DATA_SHIFT_LEAD),
   /* Job Priority escalated to Maximum as it is mapped
      to one or more non-interruptible sequence */
    SPI_JOB_PRIORITY_3,

    /* Spi HW Unit. bit[7:4]: Channel no, bit[3:0]: hw module no */
      (uint8)((uint8)SPI_QSPI_CHANNEL0 << 4U) | (SPI_QSPI2_INDEX),

    /* Channel Based Chip Select */
    (uint8)0U,
    
    /* Spi Parity Selection */
    (uint8)SPI_QSPI_PARITY_UNUSED,
    
  },
/* Job: SpiJob_Rd_PSTAT Configuration */
  {
   /* Job End Notification: Spi_JobEndNotification, SPI118 */
    NULL_PTR,
    /* User given name outside the naming convention */
    /* Spi_ChannelLinkPtr */
    SpiJob_Rd_PSTAT_ChannelLinkPtr,
    /* Baud Rate (1388888 Hz) Hw configuration Parameters */
    Spi_BaudRateParams(/*TQ*/(0x3U), /*Q*/(0x2U),
              /*A*/(0x2U), /*B*/(0x0U), /*C*/(0x3U)),

    /* Time Delay Configuration */
      (uint32)Spi_DelayParams(/*IPRE*/0x04U,/*IDLE*/ 0x04U,
        /*LPRE*/0x02U, /*LEAD*/0x06U,
        /*TPRE*/0x02U, /*TRAIL*/0x06U),

    SPI_CS_HW, /* Hw CS Pin is Selected */

    /*CS Active level Polarity*/
    SPI_CS_POLARITY_LOW,

 /* Shift Clock Configuration : Clock Idle Polarity: SPI_SHIFT_CLOCK_IDLE_LEVEL,
                                  Clock Phase: SPI_DATA_SHIFT_EDGE */
    Spi_ShiftClkConfig(SPI_CLK_IDLE_LOW,
                      SPI_DATA_SHIFT_LEAD),
   /* Job Priority escalated to Maximum as it is mapped
      to one or more non-interruptible sequence */
    SPI_JOB_PRIORITY_3,

    /* Spi HW Unit. bit[7:4]: Channel no, bit[3:0]: hw module no */
      (uint8)((uint8)SPI_QSPI_CHANNEL0 << 4U) | (SPI_QSPI2_INDEX),

    /* Channel Based Chip Select */
    (uint8)0U,
    
    /* Spi Parity Selection */
    (uint8)SPI_QSPI_PARITY_UNUSED,
    
  },
/* Job: SpiJob_Rd_PSTAT2 Configuration */
  {
   /* Job End Notification: Spi_JobEndNotification, SPI118 */
    NULL_PTR,
    /* User given name outside the naming convention */
    /* Spi_ChannelLinkPtr */
    SpiJob_Rd_PSTAT2_ChannelLinkPtr,
    /* Baud Rate (1388888 Hz) Hw configuration Parameters */
    Spi_BaudRateParams(/*TQ*/(0x3U), /*Q*/(0x2U),
              /*A*/(0x2U), /*B*/(0x0U), /*C*/(0x3U)),

    /* Time Delay Configuration */
      (uint32)Spi_DelayParams(/*IPRE*/0x04U,/*IDLE*/ 0x04U,
        /*LPRE*/0x02U, /*LEAD*/0x06U,
        /*TPRE*/0x02U, /*TRAIL*/0x06U),

    SPI_CS_HW, /* Hw CS Pin is Selected */

    /*CS Active level Polarity*/
    SPI_CS_POLARITY_LOW,

 /* Shift Clock Configuration : Clock Idle Polarity: SPI_SHIFT_CLOCK_IDLE_LEVEL,
                                  Clock Phase: SPI_DATA_SHIFT_EDGE */
    Spi_ShiftClkConfig(SPI_CLK_IDLE_LOW,
                      SPI_DATA_SHIFT_LEAD),
   /* Job Priority escalated to Maximum as it is mapped
      to one or more non-interruptible sequence */
    SPI_JOB_PRIORITY_3,

    /* Spi HW Unit. bit[7:4]: Channel no, bit[3:0]: hw module no */
      (uint8)((uint8)SPI_QSPI_CHANNEL0 << 4U) | (SPI_QSPI2_INDEX),

    /* Channel Based Chip Select */
    (uint8)0U,
    
    /* Spi Parity Selection */
    (uint8)SPI_QSPI_PARITY_UNUSED,
    
  },
/* Job: SpiJob_Rd_PER Configuration */
  {
   /* Job End Notification: Spi_JobEndNotification, SPI118 */
    NULL_PTR,
    /* User given name outside the naming convention */
    /* Spi_ChannelLinkPtr */
    SpiJob_Rd_PER_ChannelLinkPtr,
    /* Baud Rate (1388888 Hz) Hw configuration Parameters */
    Spi_BaudRateParams(/*TQ*/(0x3U), /*Q*/(0x2U),
              /*A*/(0x2U), /*B*/(0x0U), /*C*/(0x3U)),

    /* Time Delay Configuration */
      (uint32)Spi_DelayParams(/*IPRE*/0x04U,/*IDLE*/ 0x04U,
        /*LPRE*/0x02U, /*LEAD*/0x06U,
        /*TPRE*/0x02U, /*TRAIL*/0x06U),

    SPI_CS_HW, /* Hw CS Pin is Selected */

    /*CS Active level Polarity*/
    SPI_CS_POLARITY_LOW,

 /* Shift Clock Configuration : Clock Idle Polarity: SPI_SHIFT_CLOCK_IDLE_LEVEL,
                                  Clock Phase: SPI_DATA_SHIFT_EDGE */
    Spi_ShiftClkConfig(SPI_CLK_IDLE_LOW,
                      SPI_DATA_SHIFT_LEAD),
   /* Job Priority escalated to Maximum as it is mapped
      to one or more non-interruptible sequence */
    SPI_JOB_PRIORITY_3,

    /* Spi HW Unit. bit[7:4]: Channel no, bit[3:0]: hw module no */
      (uint8)((uint8)SPI_QSPI_CHANNEL0 << 4U) | (SPI_QSPI2_INDEX),

    /* Channel Based Chip Select */
    (uint8)0U,
    
    /* Spi Parity Selection */
    (uint8)SPI_QSPI_PARITY_UNUSED,
    
  },
/* Job: SpiJob_Rd_PPIN Configuration */
  {
   /* Job End Notification: Spi_JobEndNotification, SPI118 */
    NULL_PTR,
    /* User given name outside the naming convention */
    /* Spi_ChannelLinkPtr */
    SpiJob_Rd_PPIN_ChannelLinkPtr,
    /* Baud Rate (1388888 Hz) Hw configuration Parameters */
    Spi_BaudRateParams(/*TQ*/(0x3U), /*Q*/(0x2U),
              /*A*/(0x2U), /*B*/(0x0U), /*C*/(0x3U)),

    /* Time Delay Configuration */
      (uint32)Spi_DelayParams(/*IPRE*/0x04U,/*IDLE*/ 0x04U,
        /*LPRE*/0x02U, /*LEAD*/0x06U,
        /*TPRE*/0x02U, /*TRAIL*/0x06U),

    SPI_CS_HW, /* Hw CS Pin is Selected */

    /*CS Active level Polarity*/
    SPI_CS_POLARITY_LOW,

 /* Shift Clock Configuration : Clock Idle Polarity: SPI_SHIFT_CLOCK_IDLE_LEVEL,
                                  Clock Phase: SPI_DATA_SHIFT_EDGE */
    Spi_ShiftClkConfig(SPI_CLK_IDLE_LOW,
                      SPI_DATA_SHIFT_LEAD),
   /* Job Priority escalated to Maximum as it is mapped
      to one or more non-interruptible sequence */
    SPI_JOB_PRIORITY_3,

    /* Spi HW Unit. bit[7:4]: Channel no, bit[3:0]: hw module no */
      (uint8)((uint8)SPI_QSPI_CHANNEL0 << 4U) | (SPI_QSPI2_INDEX),

    /* Channel Based Chip Select */
    (uint8)0U,
    
    /* Spi Parity Selection */
    (uint8)SPI_QSPI_PARITY_UNUSED,
    
  },
/* Job: SpiJob_Rd_PCS Configuration */
  {
   /* Job End Notification: Spi_JobEndNotification, SPI118 */
    NULL_PTR,
    /* User given name outside the naming convention */
    /* Spi_ChannelLinkPtr */
    SpiJob_Rd_PCS_ChannelLinkPtr,
    /* Baud Rate (1388888 Hz) Hw configuration Parameters */
    Spi_BaudRateParams(/*TQ*/(0x3U), /*Q*/(0x2U),
              /*A*/(0x2U), /*B*/(0x0U), /*C*/(0x3U)),

    /* Time Delay Configuration */
      (uint32)Spi_DelayParams(/*IPRE*/0x04U,/*IDLE*/ 0x04U,
        /*LPRE*/0x02U, /*LEAD*/0x06U,
        /*TPRE*/0x02U, /*TRAIL*/0x06U),

    SPI_CS_HW, /* Hw CS Pin is Selected */

    /*CS Active level Polarity*/
    SPI_CS_POLARITY_LOW,

 /* Shift Clock Configuration : Clock Idle Polarity: SPI_SHIFT_CLOCK_IDLE_LEVEL,
                                  Clock Phase: SPI_DATA_SHIFT_EDGE */
    Spi_ShiftClkConfig(SPI_CLK_IDLE_LOW,
                      SPI_DATA_SHIFT_LEAD),
   /* Job Priority escalated to Maximum as it is mapped
      to one or more non-interruptible sequence */
    SPI_JOB_PRIORITY_3,

    /* Spi HW Unit. bit[7:4]: Channel no, bit[3:0]: hw module no */
      (uint8)((uint8)SPI_QSPI_CHANNEL0 << 4U) | (SPI_QSPI2_INDEX),

    /* Channel Based Chip Select */
    (uint8)0U,
    
    /* Spi Parity Selection */
    (uint8)SPI_QSPI_PARITY_UNUSED,
    
  },
/* Job: SpiJob_Rd_SSTAT Configuration */
  {
   /* Job End Notification: Spi_JobEndNotification, SPI118 */
    NULL_PTR,
    /* User given name outside the naming convention */
    /* Spi_ChannelLinkPtr */
    SpiJob_Rd_SSTAT_ChannelLinkPtr,
    /* Baud Rate (1388888 Hz) Hw configuration Parameters */
    Spi_BaudRateParams(/*TQ*/(0x3U), /*Q*/(0x2U),
              /*A*/(0x2U), /*B*/(0x0U), /*C*/(0x3U)),

    /* Time Delay Configuration */
      (uint32)Spi_DelayParams(/*IPRE*/0x04U,/*IDLE*/ 0x04U,
        /*LPRE*/0x02U, /*LEAD*/0x06U,
        /*TPRE*/0x02U, /*TRAIL*/0x06U),

    SPI_CS_HW, /* Hw CS Pin is Selected */

    /*CS Active level Polarity*/
    SPI_CS_POLARITY_LOW,

 /* Shift Clock Configuration : Clock Idle Polarity: SPI_SHIFT_CLOCK_IDLE_LEVEL,
                                  Clock Phase: SPI_DATA_SHIFT_EDGE */
    Spi_ShiftClkConfig(SPI_CLK_IDLE_LOW,
                      SPI_DATA_SHIFT_LEAD),
   /* Job Priority escalated to Maximum as it is mapped
      to one or more non-interruptible sequence */
    SPI_JOB_PRIORITY_3,

    /* Spi HW Unit. bit[7:4]: Channel no, bit[3:0]: hw module no */
      (uint8)((uint8)SPI_QSPI_CHANNEL0 << 4U) | (SPI_QSPI2_INDEX),

    /* Channel Based Chip Select */
    (uint8)0U,
    
    /* Spi Parity Selection */
    (uint8)SPI_QSPI_PARITY_UNUSED,
    
  },
/* Job: SpiJob_Rd_SSTAT2 Configuration */
  {
   /* Job End Notification: Spi_JobEndNotification, SPI118 */
    NULL_PTR,
    /* User given name outside the naming convention */
    /* Spi_ChannelLinkPtr */
    SpiJob_Rd_SSTAT2_ChannelLinkPtr,
    /* Baud Rate (1388888 Hz) Hw configuration Parameters */
    Spi_BaudRateParams(/*TQ*/(0x3U), /*Q*/(0x2U),
              /*A*/(0x2U), /*B*/(0x0U), /*C*/(0x3U)),

    /* Time Delay Configuration */
      (uint32)Spi_DelayParams(/*IPRE*/0x04U,/*IDLE*/ 0x04U,
        /*LPRE*/0x02U, /*LEAD*/0x06U,
        /*TPRE*/0x02U, /*TRAIL*/0x06U),

    SPI_CS_HW, /* Hw CS Pin is Selected */

    /*CS Active level Polarity*/
    SPI_CS_POLARITY_LOW,

 /* Shift Clock Configuration : Clock Idle Polarity: SPI_SHIFT_CLOCK_IDLE_LEVEL,
                                  Clock Phase: SPI_DATA_SHIFT_EDGE */
    Spi_ShiftClkConfig(SPI_CLK_IDLE_LOW,
                      SPI_DATA_SHIFT_LEAD),
   /* Job Priority escalated to Maximum as it is mapped
      to one or more non-interruptible sequence */
    SPI_JOB_PRIORITY_3,

    /* Spi HW Unit. bit[7:4]: Channel no, bit[3:0]: hw module no */
      (uint8)((uint8)SPI_QSPI_CHANNEL0 << 4U) | (SPI_QSPI2_INDEX),

    /* Channel Based Chip Select */
    (uint8)0U,
    
    /* Spi Parity Selection */
    (uint8)SPI_QSPI_PARITY_UNUSED,
    
  },
/* Job: SpiJob_Rd_SER Configuration */
  {
   /* Job End Notification: Spi_JobEndNotification, SPI118 */
    NULL_PTR,
    /* User given name outside the naming convention */
    /* Spi_ChannelLinkPtr */
    SpiJob_Rd_SER_ChannelLinkPtr,
    /* Baud Rate (1388888 Hz) Hw configuration Parameters */
    Spi_BaudRateParams(/*TQ*/(0x3U), /*Q*/(0x2U),
              /*A*/(0x2U), /*B*/(0x0U), /*C*/(0x3U)),

    /* Time Delay Configuration */
      (uint32)Spi_DelayParams(/*IPRE*/0x04U,/*IDLE*/ 0x04U,
        /*LPRE*/0x02U, /*LEAD*/0x06U,
        /*TPRE*/0x02U, /*TRAIL*/0x06U),

    SPI_CS_HW, /* Hw CS Pin is Selected */

    /*CS Active level Polarity*/
    SPI_CS_POLARITY_LOW,

 /* Shift Clock Configuration : Clock Idle Polarity: SPI_SHIFT_CLOCK_IDLE_LEVEL,
                                  Clock Phase: SPI_DATA_SHIFT_EDGE */
    Spi_ShiftClkConfig(SPI_CLK_IDLE_LOW,
                      SPI_DATA_SHIFT_LEAD),
   /* Job Priority escalated to Maximum as it is mapped
      to one or more non-interruptible sequence */
    SPI_JOB_PRIORITY_3,

    /* Spi HW Unit. bit[7:4]: Channel no, bit[3:0]: hw module no */
      (uint8)((uint8)SPI_QSPI_CHANNEL0 << 4U) | (SPI_QSPI2_INDEX),

    /* Channel Based Chip Select */
    (uint8)0U,
    
    /* Spi Parity Selection */
    (uint8)SPI_QSPI_PARITY_UNUSED,
    
  },
/* Job: SpiJob_PCTRL Configuration */
  {
   /* Job End Notification: Spi_JobEndNotification, SPI118 */
    NULL_PTR,
    /* User given name outside the naming convention */
    /* Spi_ChannelLinkPtr */
    SpiJob_PCTRL_ChannelLinkPtr,
    /* Baud Rate (1388888 Hz) Hw configuration Parameters */
    Spi_BaudRateParams(/*TQ*/(0x3U), /*Q*/(0x2U),
              /*A*/(0x2U), /*B*/(0x0U), /*C*/(0x3U)),

    /* Time Delay Configuration */
      (uint32)Spi_DelayParams(/*IPRE*/0x04U,/*IDLE*/ 0x04U,
        /*LPRE*/0x02U, /*LEAD*/0x06U,
        /*TPRE*/0x02U, /*TRAIL*/0x06U),

    SPI_CS_HW, /* Hw CS Pin is Selected */

    /*CS Active level Polarity*/
    SPI_CS_POLARITY_LOW,

 /* Shift Clock Configuration : Clock Idle Polarity: SPI_SHIFT_CLOCK_IDLE_LEVEL,
                                  Clock Phase: SPI_DATA_SHIFT_EDGE */
    Spi_ShiftClkConfig(SPI_CLK_IDLE_LOW,
                      SPI_DATA_SHIFT_LEAD),
   /* Job Priority escalated to Maximum as it is mapped
      to one or more non-interruptible sequence */
    SPI_JOB_PRIORITY_3,

    /* Spi HW Unit. bit[7:4]: Channel no, bit[3:0]: hw module no */
      (uint8)((uint8)SPI_QSPI_CHANNEL0 << 4U) | (SPI_QSPI2_INDEX),

    /* Channel Based Chip Select */
    (uint8)0U,
    
    /* Spi Parity Selection */
    (uint8)SPI_QSPI_PARITY_UNUSED,
    
  },
/* Job: SpiJob_PCTRL2 Configuration */
  {
   /* Job End Notification: Spi_JobEndNotification, SPI118 */
    NULL_PTR,
    /* User given name outside the naming convention */
    /* Spi_ChannelLinkPtr */
    SpiJob_PCTRL2_ChannelLinkPtr,
    /* Baud Rate (1388888 Hz) Hw configuration Parameters */
    Spi_BaudRateParams(/*TQ*/(0x3U), /*Q*/(0x2U),
              /*A*/(0x2U), /*B*/(0x0U), /*C*/(0x3U)),

    /* Time Delay Configuration */
      (uint32)Spi_DelayParams(/*IPRE*/0x04U,/*IDLE*/ 0x04U,
        /*LPRE*/0x02U, /*LEAD*/0x06U,
        /*TPRE*/0x02U, /*TRAIL*/0x06U),

    SPI_CS_HW, /* Hw CS Pin is Selected */

    /*CS Active level Polarity*/
    SPI_CS_POLARITY_LOW,

 /* Shift Clock Configuration : Clock Idle Polarity: SPI_SHIFT_CLOCK_IDLE_LEVEL,
                                  Clock Phase: SPI_DATA_SHIFT_EDGE */
    Spi_ShiftClkConfig(SPI_CLK_IDLE_LOW,
                      SPI_DATA_SHIFT_LEAD),
   /* Job Priority escalated to Maximum as it is mapped
      to one or more non-interruptible sequence */
    SPI_JOB_PRIORITY_3,

    /* Spi HW Unit. bit[7:4]: Channel no, bit[3:0]: hw module no */
      (uint8)((uint8)SPI_QSPI_CHANNEL0 << 4U) | (SPI_QSPI2_INDEX),

    /* Channel Based Chip Select */
    (uint8)0U,
    
    /* Spi Parity Selection */
    (uint8)SPI_QSPI_PARITY_UNUSED,
    
  },
/* Job: SpiJob_Nop Configuration */
  {
   /* Job End Notification: Spi_JobEndNotification, SPI118 */
    NULL_PTR,
    /* User given name outside the naming convention */
    /* Spi_ChannelLinkPtr */
    SpiJob_Nop_ChannelLinkPtr,
    /* Baud Rate (1388888 Hz) Hw configuration Parameters */
    Spi_BaudRateParams(/*TQ*/(0x3U), /*Q*/(0x2U),
              /*A*/(0x2U), /*B*/(0x0U), /*C*/(0x3U)),

    /* Time Delay Configuration */
      (uint32)Spi_DelayParams(/*IPRE*/0x04U,/*IDLE*/ 0x04U,
        /*LPRE*/0x02U, /*LEAD*/0x06U,
        /*TPRE*/0x02U, /*TRAIL*/0x06U),

    SPI_CS_HW, /* Hw CS Pin is Selected */

    /*CS Active level Polarity*/
    SPI_CS_POLARITY_LOW,

 /* Shift Clock Configuration : Clock Idle Polarity: SPI_SHIFT_CLOCK_IDLE_LEVEL,
                                  Clock Phase: SPI_DATA_SHIFT_EDGE */
    Spi_ShiftClkConfig(SPI_CLK_IDLE_LOW,
                      SPI_DATA_SHIFT_LEAD),
   /* Job Priority escalated to Maximum as it is mapped
      to one or more non-interruptible sequence */
    SPI_JOB_PRIORITY_3,

    /* Spi HW Unit. bit[7:4]: Channel no, bit[3:0]: hw module no */
      (uint8)((uint8)SPI_QSPI_CHANNEL0 << 4U) | (SPI_QSPI2_INDEX),

    /* Channel Based Chip Select */
    (uint8)0U,
    
    /* Spi Parity Selection */
    (uint8)SPI_QSPI_PARITY_UNUSED,
    
  },
/* Job: SpiJob_ModeCtrl Configuration */
  {
   /* Job End Notification: Spi_JobEndNotification, SPI118 */
    NULL_PTR,
    /* User given name outside the naming convention */
    /* Spi_ChannelLinkPtr */
    SpiJob_ModeCtrl_ChannelLinkPtr,
    /* Baud Rate (1388888 Hz) Hw configuration Parameters */
    Spi_BaudRateParams(/*TQ*/(0x3U), /*Q*/(0x2U),
              /*A*/(0x2U), /*B*/(0x0U), /*C*/(0x3U)),

    /* Time Delay Configuration */
      (uint32)Spi_DelayParams(/*IPRE*/0x04U,/*IDLE*/ 0x04U,
        /*LPRE*/0x02U, /*LEAD*/0x06U,
        /*TPRE*/0x02U, /*TRAIL*/0x06U),

    SPI_CS_HW, /* Hw CS Pin is Selected */

    /*CS Active level Polarity*/
    SPI_CS_POLARITY_LOW,

 /* Shift Clock Configuration : Clock Idle Polarity: SPI_SHIFT_CLOCK_IDLE_LEVEL,
                                  Clock Phase: SPI_DATA_SHIFT_EDGE */
    Spi_ShiftClkConfig(SPI_CLK_IDLE_LOW,
                      SPI_DATA_SHIFT_LEAD),
   /* Job Priority escalated to Maximum as it is mapped
      to one or more non-interruptible sequence */
    SPI_JOB_PRIORITY_3,

    /* Spi HW Unit. bit[7:4]: Channel no, bit[3:0]: hw module no */
      (uint8)((uint8)SPI_QSPI_CHANNEL0 << 4U) | (SPI_QSPI2_INDEX),

    /* Channel Based Chip Select */
    (uint8)0U,
    
    /* Spi Parity Selection */
    (uint8)SPI_QSPI_PARITY_UNUSED,
    
  },
/* Job: SpiJob_WrH Configuration */
  {
   /* Job End Notification: Spi_JobEndNotification, SPI118 */
    NULL_PTR,
    /* User given name outside the naming convention */
    /* Spi_ChannelLinkPtr */
    SpiJob_WrH_ChannelLinkPtr,
    /* Baud Rate (1388888 Hz) Hw configuration Parameters */
    Spi_BaudRateParams(/*TQ*/(0x3U), /*Q*/(0x2U),
              /*A*/(0x2U), /*B*/(0x0U), /*C*/(0x3U)),

    /* Time Delay Configuration */
      (uint32)Spi_DelayParams(/*IPRE*/0x04U,/*IDLE*/ 0x04U,
        /*LPRE*/0x02U, /*LEAD*/0x06U,
        /*TPRE*/0x02U, /*TRAIL*/0x06U),

    SPI_CS_HW, /* Hw CS Pin is Selected */

    /*CS Active level Polarity*/
    SPI_CS_POLARITY_LOW,

 /* Shift Clock Configuration : Clock Idle Polarity: SPI_SHIFT_CLOCK_IDLE_LEVEL,
                                  Clock Phase: SPI_DATA_SHIFT_EDGE */
    Spi_ShiftClkConfig(SPI_CLK_IDLE_LOW,
                      SPI_DATA_SHIFT_LEAD),
   /* Job Priority escalated to Maximum as it is mapped
      to one or more non-interruptible sequence */
    SPI_JOB_PRIORITY_3,

    /* Spi HW Unit. bit[7:4]: Channel no, bit[3:0]: hw module no */
      (uint8)((uint8)SPI_QSPI_CHANNEL0 << 4U) | (SPI_QSPI2_INDEX),

    /* Channel Based Chip Select */
    (uint8)0U,
    
    /* Spi Parity Selection */
    (uint8)SPI_QSPI_PARITY_UNUSED,
    
  },
/* Job: SpiJob_WrL Configuration */
  {
   /* Job End Notification: Spi_JobEndNotification, SPI118 */
    NULL_PTR,
    /* User given name outside the naming convention */
    /* Spi_ChannelLinkPtr */
    SpiJob_WrL_ChannelLinkPtr,
    /* Baud Rate (1388888 Hz) Hw configuration Parameters */
    Spi_BaudRateParams(/*TQ*/(0x3U), /*Q*/(0x2U),
              /*A*/(0x2U), /*B*/(0x0U), /*C*/(0x3U)),

    /* Time Delay Configuration */
      (uint32)Spi_DelayParams(/*IPRE*/0x04U,/*IDLE*/ 0x04U,
        /*LPRE*/0x02U, /*LEAD*/0x06U,
        /*TPRE*/0x02U, /*TRAIL*/0x06U),

    SPI_CS_HW, /* Hw CS Pin is Selected */

    /*CS Active level Polarity*/
    SPI_CS_POLARITY_LOW,

 /* Shift Clock Configuration : Clock Idle Polarity: SPI_SHIFT_CLOCK_IDLE_LEVEL,
                                  Clock Phase: SPI_DATA_SHIFT_EDGE */
    Spi_ShiftClkConfig(SPI_CLK_IDLE_LOW,
                      SPI_DATA_SHIFT_LEAD),
   /* Job Priority escalated to Maximum as it is mapped
      to one or more non-interruptible sequence */
    SPI_JOB_PRIORITY_3,

    /* Spi HW Unit. bit[7:4]: Channel no, bit[3:0]: hw module no */
      (uint8)((uint8)SPI_QSPI_CHANNEL0 << 4U) | (SPI_QSPI2_INDEX),

    /* Channel Based Chip Select */
    (uint8)0U,
    
    /* Spi Parity Selection */
    (uint8)SPI_QSPI_PARITY_UNUSED,
    
  },
/* Job: SpiJob_Other Configuration */
  {
   /* Job End Notification: Spi_JobEndNotification, SPI118 */
    NULL_PTR,
    /* User given name outside the naming convention */
    /* Spi_ChannelLinkPtr */
    SpiJob_Other_ChannelLinkPtr,
    /* Baud Rate (1000000 Hz) Hw configuration Parameters */
    Spi_BaudRateParams(/*TQ*/(0x9U), /*Q*/(0x1U),
              /*A*/(0x2U), /*B*/(0x1U), /*C*/(0x1U)),

    /* Time Delay Configuration */
      (uint32)Spi_DelayParams(/*IPRE*/0x01U,/*IDLE*/ 0x01U,
        /*LPRE*/0x00U, /*LEAD*/0x01U,
        /*TPRE*/0x00U, /*TRAIL*/0x01U),

    SPI_CS_HW, /* Hw CS Pin is Selected */

    /*CS Active level Polarity*/
    SPI_CS_POLARITY_LOW,

 /* Shift Clock Configuration : Clock Idle Polarity: SPI_SHIFT_CLOCK_IDLE_LEVEL,
                                  Clock Phase: SPI_DATA_SHIFT_EDGE */
    Spi_ShiftClkConfig(SPI_CLK_IDLE_LOW,
                      SPI_DATA_SHIFT_LEAD),
   /* Job Priority escalated to Maximum as it is mapped
      to one or more non-interruptible sequence */
    SPI_JOB_PRIORITY_3,

    /* Spi HW Unit. bit[7:4]: Channel no, bit[3:0]: hw module no */
      (uint8)((uint8)SPI_QSPI_CHANNEL12 << 4U) | (SPI_QSPI3_INDEX),

    /* Channel Based Chip Select */
    (uint8)0U,
    
    /* Spi Parity Selection */
    (uint8)SPI_QSPI_PARITY_UNUSED,
    
  },
/* Job: SpiJob_Rd_SGM1 Configuration */
  {
   /* Job End Notification: Spi_JobEndNotification, SPI118 */
    NULL_PTR,
    /* User given name outside the naming convention */
    /* Spi_ChannelLinkPtr */
    SpiJob_Rd_SGM1_ChannelLinkPtr,
    /* Baud Rate (1388888 Hz) Hw configuration Parameters */
    Spi_BaudRateParams(/*TQ*/(0x3U), /*Q*/(0x2U),
              /*A*/(0x2U), /*B*/(0x0U), /*C*/(0x3U)),

    /* Time Delay Configuration */
      (uint32)Spi_DelayParams(/*IPRE*/0x04U,/*IDLE*/ 0x04U,
        /*LPRE*/0x02U, /*LEAD*/0x06U,
        /*TPRE*/0x02U, /*TRAIL*/0x06U),

    SPI_CS_HW, /* Hw CS Pin is Selected */

    /*CS Active level Polarity*/
    SPI_CS_POLARITY_LOW,

 /* Shift Clock Configuration : Clock Idle Polarity: SPI_SHIFT_CLOCK_IDLE_LEVEL,
                                  Clock Phase: SPI_DATA_SHIFT_EDGE */
    Spi_ShiftClkConfig(SPI_CLK_IDLE_LOW,
                      SPI_DATA_SHIFT_LEAD),
   /* Job Priority escalated to Maximum as it is mapped
      to one or more non-interruptible sequence */
    SPI_JOB_PRIORITY_3,

    /* Spi HW Unit. bit[7:4]: Channel no, bit[3:0]: hw module no */
      (uint8)((uint8)SPI_QSPI_CHANNEL0 << 4U) | (SPI_QSPI2_INDEX),

    /* Channel Based Chip Select */
    (uint8)0U,
    
    /* Spi Parity Selection */
    (uint8)SPI_QSPI_PARITY_UNUSED,
    
  },
/* Job: SpiJob_Rd_SGM2 Configuration */
  {
   /* Job End Notification: Spi_JobEndNotification, SPI118 */
    NULL_PTR,
    /* User given name outside the naming convention */
    /* Spi_ChannelLinkPtr */
    SpiJob_Rd_SGM2_ChannelLinkPtr,
    /* Baud Rate (1388888 Hz) Hw configuration Parameters */
    Spi_BaudRateParams(/*TQ*/(0x3U), /*Q*/(0x2U),
              /*A*/(0x2U), /*B*/(0x0U), /*C*/(0x3U)),

    /* Time Delay Configuration */
      (uint32)Spi_DelayParams(/*IPRE*/0x04U,/*IDLE*/ 0x04U,
        /*LPRE*/0x02U, /*LEAD*/0x06U,
        /*TPRE*/0x02U, /*TRAIL*/0x06U),

    SPI_CS_HW, /* Hw CS Pin is Selected */

    /*CS Active level Polarity*/
    SPI_CS_POLARITY_LOW,

 /* Shift Clock Configuration : Clock Idle Polarity: SPI_SHIFT_CLOCK_IDLE_LEVEL,
                                  Clock Phase: SPI_DATA_SHIFT_EDGE */
    Spi_ShiftClkConfig(SPI_CLK_IDLE_LOW,
                      SPI_DATA_SHIFT_LEAD),
   /* Job Priority escalated to Maximum as it is mapped
      to one or more non-interruptible sequence */
    SPI_JOB_PRIORITY_3,

    /* Spi HW Unit. bit[7:4]: Channel no, bit[3:0]: hw module no */
      (uint8)((uint8)SPI_QSPI_CHANNEL0 << 4U) | (SPI_QSPI2_INDEX),

    /* Channel Based Chip Select */
    (uint8)0U,
    
    /* Spi Parity Selection */
    (uint8)SPI_QSPI_PARITY_UNUSED,
    
  },
/* Job: SpiJob_Rd_SCS Configuration */
  {
   /* Job End Notification: Spi_JobEndNotification, SPI118 */
    NULL_PTR,
    /* User given name outside the naming convention */
    /* Spi_ChannelLinkPtr */
    SpiJob_Rd_SCS_ChannelLinkPtr,
    /* Baud Rate (1388888 Hz) Hw configuration Parameters */
    Spi_BaudRateParams(/*TQ*/(0x3U), /*Q*/(0x2U),
              /*A*/(0x2U), /*B*/(0x0U), /*C*/(0x3U)),

    /* Time Delay Configuration */
      (uint32)Spi_DelayParams(/*IPRE*/0x04U,/*IDLE*/ 0x04U,
        /*LPRE*/0x02U, /*LEAD*/0x06U,
        /*TPRE*/0x02U, /*TRAIL*/0x06U),

    SPI_CS_HW, /* Hw CS Pin is Selected */

    /*CS Active level Polarity*/
    SPI_CS_POLARITY_LOW,

 /* Shift Clock Configuration : Clock Idle Polarity: SPI_SHIFT_CLOCK_IDLE_LEVEL,
                                  Clock Phase: SPI_DATA_SHIFT_EDGE */
    Spi_ShiftClkConfig(SPI_CLK_IDLE_LOW,
                      SPI_DATA_SHIFT_LEAD),
   /* Job Priority escalated to Maximum as it is mapped
      to one or more non-interruptible sequence */
    SPI_JOB_PRIORITY_3,

    /* Spi HW Unit. bit[7:4]: Channel no, bit[3:0]: hw module no */
      (uint8)((uint8)SPI_QSPI_CHANNEL0 << 4U) | (SPI_QSPI2_INDEX),

    /* Channel Based Chip Select */
    (uint8)0U,
    
    /* Spi Parity Selection */
    (uint8)SPI_QSPI_PARITY_UNUSED,
    
  },
/* Job: SpiJob_Rd_SCTRL Configuration */
  {
   /* Job End Notification: Spi_JobEndNotification, SPI118 */
    NULL_PTR,
    /* User given name outside the naming convention */
    /* Spi_ChannelLinkPtr */
    SpiJob_Rd_SCTRL_ChannelLinkPtr,
    /* Baud Rate (1388888 Hz) Hw configuration Parameters */
    Spi_BaudRateParams(/*TQ*/(0x3U), /*Q*/(0x2U),
              /*A*/(0x2U), /*B*/(0x0U), /*C*/(0x3U)),

    /* Time Delay Configuration */
      (uint32)Spi_DelayParams(/*IPRE*/0x04U,/*IDLE*/ 0x04U,
        /*LPRE*/0x02U, /*LEAD*/0x06U,
        /*TPRE*/0x02U, /*TRAIL*/0x06U),

    SPI_CS_HW, /* Hw CS Pin is Selected */

    /*CS Active level Polarity*/
    SPI_CS_POLARITY_LOW,

 /* Shift Clock Configuration : Clock Idle Polarity: SPI_SHIFT_CLOCK_IDLE_LEVEL,
                                  Clock Phase: SPI_DATA_SHIFT_EDGE */
    Spi_ShiftClkConfig(SPI_CLK_IDLE_LOW,
                      SPI_DATA_SHIFT_LEAD),
   /* Job Priority escalated to Maximum as it is mapped
      to one or more non-interruptible sequence */
    SPI_JOB_PRIORITY_3,

    /* Spi HW Unit. bit[7:4]: Channel no, bit[3:0]: hw module no */
      (uint8)((uint8)SPI_QSPI_CHANNEL0 << 4U) | (SPI_QSPI2_INDEX),

    /* Channel Based Chip Select */
    (uint8)0U,
    
    /* Spi Parity Selection */
    (uint8)SPI_QSPI_PARITY_UNUSED,
    
  },
/* Job: SpiJob_Rd_PRW Configuration */
  {
   /* Job End Notification: Spi_JobEndNotification, SPI118 */
    NULL_PTR,
    /* User given name outside the naming convention */
    /* Spi_ChannelLinkPtr */
    SpiJob_Rd_PRW_ChannelLinkPtr,
    /* Baud Rate (1388888 Hz) Hw configuration Parameters */
    Spi_BaudRateParams(/*TQ*/(0x3U), /*Q*/(0x2U),
              /*A*/(0x2U), /*B*/(0x0U), /*C*/(0x3U)),

    /* Time Delay Configuration */
      (uint32)Spi_DelayParams(/*IPRE*/0x04U,/*IDLE*/ 0x04U,
        /*LPRE*/0x02U, /*LEAD*/0x06U,
        /*TPRE*/0x02U, /*TRAIL*/0x06U),

    SPI_CS_HW, /* Hw CS Pin is Selected */

    /*CS Active level Polarity*/
    SPI_CS_POLARITY_LOW,

 /* Shift Clock Configuration : Clock Idle Polarity: SPI_SHIFT_CLOCK_IDLE_LEVEL,
                                  Clock Phase: SPI_DATA_SHIFT_EDGE */
    Spi_ShiftClkConfig(SPI_CLK_IDLE_LOW,
                      SPI_DATA_SHIFT_LEAD),
   /* Job Priority escalated to Maximum as it is mapped
      to one or more non-interruptible sequence */
    SPI_JOB_PRIORITY_3,

    /* Spi HW Unit. bit[7:4]: Channel no, bit[3:0]: hw module no */
      (uint8)((uint8)SPI_QSPI_CHANNEL0 << 4U) | (SPI_QSPI2_INDEX),

    /* Channel Based Chip Select */
    (uint8)0U,
    
    /* Spi Parity Selection */
    (uint8)SPI_QSPI_PARITY_UNUSED,
    
  },
/* Job: SpiJob_WrL_PCTRL Configuration */
  {
   /* Job End Notification: Spi_JobEndNotification, SPI118 */
    NULL_PTR,
    /* User given name outside the naming convention */
    /* Spi_ChannelLinkPtr */
    SpiJob_WrL_PCTRL_ChannelLinkPtr,
    /* Baud Rate (1388888 Hz) Hw configuration Parameters */
    Spi_BaudRateParams(/*TQ*/(0x3U), /*Q*/(0x2U),
              /*A*/(0x2U), /*B*/(0x0U), /*C*/(0x3U)),

    /* Time Delay Configuration */
      (uint32)Spi_DelayParams(/*IPRE*/0x04U,/*IDLE*/ 0x04U,
        /*LPRE*/0x02U, /*LEAD*/0x06U,
        /*TPRE*/0x02U, /*TRAIL*/0x06U),

    SPI_CS_HW, /* Hw CS Pin is Selected */

    /*CS Active level Polarity*/
    SPI_CS_POLARITY_LOW,

 /* Shift Clock Configuration : Clock Idle Polarity: SPI_SHIFT_CLOCK_IDLE_LEVEL,
                                  Clock Phase: SPI_DATA_SHIFT_EDGE */
    Spi_ShiftClkConfig(SPI_CLK_IDLE_LOW,
                      SPI_DATA_SHIFT_LEAD),
   /* Job Priority escalated to Maximum as it is mapped
      to one or more non-interruptible sequence */
    SPI_JOB_PRIORITY_3,

    /* Spi HW Unit. bit[7:4]: Channel no, bit[3:0]: hw module no */
      (uint8)((uint8)SPI_QSPI_CHANNEL0 << 4U) | (SPI_QSPI2_INDEX),

    /* Channel Based Chip Select */
    (uint8)0U,
    
    /* Spi Parity Selection */
    (uint8)SPI_QSPI_PARITY_UNUSED,
    
  },
/* Job: SpiJob_WrL_PCTRL2 Configuration */
  {
   /* Job End Notification: Spi_JobEndNotification, SPI118 */
    NULL_PTR,
    /* User given name outside the naming convention */
    /* Spi_ChannelLinkPtr */
    SpiJob_WrL_PCTRL2_ChannelLinkPtr,
    /* Baud Rate (1388888 Hz) Hw configuration Parameters */
    Spi_BaudRateParams(/*TQ*/(0x3U), /*Q*/(0x2U),
              /*A*/(0x2U), /*B*/(0x0U), /*C*/(0x3U)),

    /* Time Delay Configuration */
      (uint32)Spi_DelayParams(/*IPRE*/0x04U,/*IDLE*/ 0x04U,
        /*LPRE*/0x02U, /*LEAD*/0x06U,
        /*TPRE*/0x02U, /*TRAIL*/0x06U),

    SPI_CS_HW, /* Hw CS Pin is Selected */

    /*CS Active level Polarity*/
    SPI_CS_POLARITY_LOW,

 /* Shift Clock Configuration : Clock Idle Polarity: SPI_SHIFT_CLOCK_IDLE_LEVEL,
                                  Clock Phase: SPI_DATA_SHIFT_EDGE */
    Spi_ShiftClkConfig(SPI_CLK_IDLE_LOW,
                      SPI_DATA_SHIFT_LEAD),
   /* Job Priority escalated to Maximum as it is mapped
      to one or more non-interruptible sequence */
    SPI_JOB_PRIORITY_3,

    /* Spi HW Unit. bit[7:4]: Channel no, bit[3:0]: hw module no */
      (uint8)((uint8)SPI_QSPI_CHANNEL0 << 4U) | (SPI_QSPI2_INDEX),

    /* Channel Based Chip Select */
    (uint8)0U,
    
    /* Spi Parity Selection */
    (uint8)SPI_QSPI_PARITY_UNUSED,
    
  },
/* Job: SpiJob_PCFG Configuration */
  {
   /* Job End Notification: Spi_JobEndNotification, SPI118 */
    NULL_PTR,
    /* User given name outside the naming convention */
    /* Spi_ChannelLinkPtr */
    SpiJob_PCFG_ChannelLinkPtr,
    /* Baud Rate (1388888 Hz) Hw configuration Parameters */
    Spi_BaudRateParams(/*TQ*/(0x3U), /*Q*/(0x2U),
              /*A*/(0x2U), /*B*/(0x0U), /*C*/(0x3U)),

    /* Time Delay Configuration */
      (uint32)Spi_DelayParams(/*IPRE*/0x04U,/*IDLE*/ 0x04U,
        /*LPRE*/0x02U, /*LEAD*/0x06U,
        /*TPRE*/0x02U, /*TRAIL*/0x06U),

    SPI_CS_HW, /* Hw CS Pin is Selected */

    /*CS Active level Polarity*/
    SPI_CS_POLARITY_LOW,

 /* Shift Clock Configuration : Clock Idle Polarity: SPI_SHIFT_CLOCK_IDLE_LEVEL,
                                  Clock Phase: SPI_DATA_SHIFT_EDGE */
    Spi_ShiftClkConfig(SPI_CLK_IDLE_LOW,
                      SPI_DATA_SHIFT_LEAD),
   /* Job Priority escalated to Maximum as it is mapped
      to one or more non-interruptible sequence */
    SPI_JOB_PRIORITY_3,

    /* Spi HW Unit. bit[7:4]: Channel no, bit[3:0]: hw module no */
      (uint8)((uint8)SPI_QSPI_CHANNEL0 << 4U) | (SPI_QSPI2_INDEX),

    /* Channel Based Chip Select */
    (uint8)0U,
    
    /* Spi Parity Selection */
    (uint8)SPI_QSPI_PARITY_UNUSED,
    
  },
/* Job: SpiJob_PCFG2 Configuration */
  {
   /* Job End Notification: Spi_JobEndNotification, SPI118 */
    NULL_PTR,
    /* User given name outside the naming convention */
    /* Spi_ChannelLinkPtr */
    SpiJob_PCFG2_ChannelLinkPtr,
    /* Baud Rate (1388888 Hz) Hw configuration Parameters */
    Spi_BaudRateParams(/*TQ*/(0x3U), /*Q*/(0x2U),
              /*A*/(0x2U), /*B*/(0x0U), /*C*/(0x3U)),

    /* Time Delay Configuration */
      (uint32)Spi_DelayParams(/*IPRE*/0x04U,/*IDLE*/ 0x04U,
        /*LPRE*/0x02U, /*LEAD*/0x06U,
        /*TPRE*/0x02U, /*TRAIL*/0x06U),

    SPI_CS_HW, /* Hw CS Pin is Selected */

    /*CS Active level Polarity*/
    SPI_CS_POLARITY_LOW,

 /* Shift Clock Configuration : Clock Idle Polarity: SPI_SHIFT_CLOCK_IDLE_LEVEL,
                                  Clock Phase: SPI_DATA_SHIFT_EDGE */
    Spi_ShiftClkConfig(SPI_CLK_IDLE_LOW,
                      SPI_DATA_SHIFT_LEAD),
   /* Job Priority escalated to Maximum as it is mapped
      to one or more non-interruptible sequence */
    SPI_JOB_PRIORITY_3,

    /* Spi HW Unit. bit[7:4]: Channel no, bit[3:0]: hw module no */
      (uint8)((uint8)SPI_QSPI_CHANNEL0 << 4U) | (SPI_QSPI2_INDEX),

    /* Channel Based Chip Select */
    (uint8)0U,
    
    /* Spi Parity Selection */
    (uint8)SPI_QSPI_PARITY_UNUSED,
    
  },
/* Job: SpiJob_CONF_PCTRL Configuration */
  {
   /* Job End Notification: Spi_JobEndNotification, SPI118 */
    NULL_PTR,
    /* User given name outside the naming convention */
    /* Spi_ChannelLinkPtr */
    SpiJob_CONF_PCTRL_ChannelLinkPtr,
    /* Baud Rate (1388888 Hz) Hw configuration Parameters */
    Spi_BaudRateParams(/*TQ*/(0x3U), /*Q*/(0x2U),
              /*A*/(0x2U), /*B*/(0x0U), /*C*/(0x3U)),

    /* Time Delay Configuration */
      (uint32)Spi_DelayParams(/*IPRE*/0x04U,/*IDLE*/ 0x04U,
        /*LPRE*/0x02U, /*LEAD*/0x06U,
        /*TPRE*/0x02U, /*TRAIL*/0x06U),

    SPI_CS_HW, /* Hw CS Pin is Selected */

    /*CS Active level Polarity*/
    SPI_CS_POLARITY_LOW,

 /* Shift Clock Configuration : Clock Idle Polarity: SPI_SHIFT_CLOCK_IDLE_LEVEL,
                                  Clock Phase: SPI_DATA_SHIFT_EDGE */
    Spi_ShiftClkConfig(SPI_CLK_IDLE_LOW,
                      SPI_DATA_SHIFT_LEAD),
   /* Job Priority escalated to Maximum as it is mapped
      to one or more non-interruptible sequence */
    SPI_JOB_PRIORITY_3,

    /* Spi HW Unit. bit[7:4]: Channel no, bit[3:0]: hw module no */
      (uint8)((uint8)SPI_QSPI_CHANNEL0 << 4U) | (SPI_QSPI2_INDEX),

    /* Channel Based Chip Select */
    (uint8)0U,
    
    /* Spi Parity Selection */
    (uint8)SPI_QSPI_PARITY_UNUSED,
    
  },
/* Job: SpiJob_CONF_PCTRL2 Configuration */
  {
   /* Job End Notification: Spi_JobEndNotification, SPI118 */
    NULL_PTR,
    /* User given name outside the naming convention */
    /* Spi_ChannelLinkPtr */
    SpiJob_CONF_PCTRL2_ChannelLinkPtr,
    /* Baud Rate (1388888 Hz) Hw configuration Parameters */
    Spi_BaudRateParams(/*TQ*/(0x3U), /*Q*/(0x2U),
              /*A*/(0x2U), /*B*/(0x0U), /*C*/(0x3U)),

    /* Time Delay Configuration */
      (uint32)Spi_DelayParams(/*IPRE*/0x04U,/*IDLE*/ 0x04U,
        /*LPRE*/0x02U, /*LEAD*/0x06U,
        /*TPRE*/0x02U, /*TRAIL*/0x06U),

    SPI_CS_HW, /* Hw CS Pin is Selected */

    /*CS Active level Polarity*/
    SPI_CS_POLARITY_LOW,

 /* Shift Clock Configuration : Clock Idle Polarity: SPI_SHIFT_CLOCK_IDLE_LEVEL,
                                  Clock Phase: SPI_DATA_SHIFT_EDGE */
    Spi_ShiftClkConfig(SPI_CLK_IDLE_LOW,
                      SPI_DATA_SHIFT_LEAD),
   /* Job Priority escalated to Maximum as it is mapped
      to one or more non-interruptible sequence */
    SPI_JOB_PRIORITY_3,

    /* Spi HW Unit. bit[7:4]: Channel no, bit[3:0]: hw module no */
      (uint8)((uint8)SPI_QSPI_CHANNEL0 << 4U) | (SPI_QSPI2_INDEX),

    /* Channel Based Chip Select */
    (uint8)0U,
    
    /* Spi Parity Selection */
    (uint8)SPI_QSPI_PARITY_UNUSED,
    
  },
/* Job: SpiJob_PSCR Configuration */
  {
   /* Job End Notification: Spi_JobEndNotification, SPI118 */
    NULL_PTR,
    /* User given name outside the naming convention */
    /* Spi_ChannelLinkPtr */
    SpiJob_PSCR_ChannelLinkPtr,
    /* Baud Rate (1388888 Hz) Hw configuration Parameters */
    Spi_BaudRateParams(/*TQ*/(0x3U), /*Q*/(0x2U),
              /*A*/(0x2U), /*B*/(0x0U), /*C*/(0x3U)),

    /* Time Delay Configuration */
      (uint32)Spi_DelayParams(/*IPRE*/0x04U,/*IDLE*/ 0x04U,
        /*LPRE*/0x02U, /*LEAD*/0x06U,
        /*TPRE*/0x02U, /*TRAIL*/0x06U),

    SPI_CS_HW, /* Hw CS Pin is Selected */

    /*CS Active level Polarity*/
    SPI_CS_POLARITY_LOW,

 /* Shift Clock Configuration : Clock Idle Polarity: SPI_SHIFT_CLOCK_IDLE_LEVEL,
                                  Clock Phase: SPI_DATA_SHIFT_EDGE */
    Spi_ShiftClkConfig(SPI_CLK_IDLE_LOW,
                      SPI_DATA_SHIFT_LEAD),
   /* Job Priority escalated to Maximum as it is mapped
      to one or more non-interruptible sequence */
    SPI_JOB_PRIORITY_3,

    /* Spi HW Unit. bit[7:4]: Channel no, bit[3:0]: hw module no */
      (uint8)((uint8)SPI_QSPI_CHANNEL0 << 4U) | (SPI_QSPI2_INDEX),

    /* Channel Based Chip Select */
    (uint8)0U,
    
    /* Spi Parity Selection */
    (uint8)SPI_QSPI_PARITY_UNUSED,
    
  },
/* Job: SpiJob_PRW Configuration */
  {
   /* Job End Notification: Spi_JobEndNotification, SPI118 */
    NULL_PTR,
    /* User given name outside the naming convention */
    /* Spi_ChannelLinkPtr */
    SpiJob_PRW_ChannelLinkPtr,
    /* Baud Rate (1388888 Hz) Hw configuration Parameters */
    Spi_BaudRateParams(/*TQ*/(0x3U), /*Q*/(0x2U),
              /*A*/(0x2U), /*B*/(0x0U), /*C*/(0x3U)),

    /* Time Delay Configuration */
      (uint32)Spi_DelayParams(/*IPRE*/0x04U,/*IDLE*/ 0x04U,
        /*LPRE*/0x02U, /*LEAD*/0x06U,
        /*TPRE*/0x02U, /*TRAIL*/0x06U),

    SPI_CS_HW, /* Hw CS Pin is Selected */

    /*CS Active level Polarity*/
    SPI_CS_POLARITY_LOW,

 /* Shift Clock Configuration : Clock Idle Polarity: SPI_SHIFT_CLOCK_IDLE_LEVEL,
                                  Clock Phase: SPI_DATA_SHIFT_EDGE */
    Spi_ShiftClkConfig(SPI_CLK_IDLE_LOW,
                      SPI_DATA_SHIFT_LEAD),
   /* Job Priority escalated to Maximum as it is mapped
      to one or more non-interruptible sequence */
    SPI_JOB_PRIORITY_3,

    /* Spi HW Unit. bit[7:4]: Channel no, bit[3:0]: hw module no */
      (uint8)((uint8)SPI_QSPI_CHANNEL0 << 4U) | (SPI_QSPI2_INDEX),

    /* Channel Based Chip Select */
    (uint8)0U,
    
    /* Spi Parity Selection */
    (uint8)SPI_QSPI_PARITY_UNUSED,
    
  },
/* Job: SpiJob_SCFG Configuration */
  {
   /* Job End Notification: Spi_JobEndNotification, SPI118 */
    NULL_PTR,
    /* User given name outside the naming convention */
    /* Spi_ChannelLinkPtr */
    SpiJob_SCFG_ChannelLinkPtr,
    /* Baud Rate (1388888 Hz) Hw configuration Parameters */
    Spi_BaudRateParams(/*TQ*/(0x3U), /*Q*/(0x2U),
              /*A*/(0x2U), /*B*/(0x0U), /*C*/(0x3U)),

    /* Time Delay Configuration */
      (uint32)Spi_DelayParams(/*IPRE*/0x04U,/*IDLE*/ 0x04U,
        /*LPRE*/0x02U, /*LEAD*/0x06U,
        /*TPRE*/0x02U, /*TRAIL*/0x06U),

    SPI_CS_HW, /* Hw CS Pin is Selected */

    /*CS Active level Polarity*/
    SPI_CS_POLARITY_LOW,

 /* Shift Clock Configuration : Clock Idle Polarity: SPI_SHIFT_CLOCK_IDLE_LEVEL,
                                  Clock Phase: SPI_DATA_SHIFT_EDGE */
    Spi_ShiftClkConfig(SPI_CLK_IDLE_LOW,
                      SPI_DATA_SHIFT_LEAD),
   /* Job Priority escalated to Maximum as it is mapped
      to one or more non-interruptible sequence */
    SPI_JOB_PRIORITY_3,

    /* Spi HW Unit. bit[7:4]: Channel no, bit[3:0]: hw module no */
      (uint8)((uint8)SPI_QSPI_CHANNEL0 << 4U) | (SPI_QSPI2_INDEX),

    /* Channel Based Chip Select */
    (uint8)0U,
    
    /* Spi Parity Selection */
    (uint8)SPI_QSPI_PARITY_UNUSED,
    
  },
/* Job: SpiJob_SCFG2 Configuration */
  {
   /* Job End Notification: Spi_JobEndNotification, SPI118 */
    NULL_PTR,
    /* User given name outside the naming convention */
    /* Spi_ChannelLinkPtr */
    SpiJob_SCFG2_ChannelLinkPtr,
    /* Baud Rate (1388888 Hz) Hw configuration Parameters */
    Spi_BaudRateParams(/*TQ*/(0x3U), /*Q*/(0x2U),
              /*A*/(0x2U), /*B*/(0x0U), /*C*/(0x3U)),

    /* Time Delay Configuration */
      (uint32)Spi_DelayParams(/*IPRE*/0x04U,/*IDLE*/ 0x04U,
        /*LPRE*/0x02U, /*LEAD*/0x06U,
        /*TPRE*/0x02U, /*TRAIL*/0x06U),

    SPI_CS_HW, /* Hw CS Pin is Selected */

    /*CS Active level Polarity*/
    SPI_CS_POLARITY_LOW,

 /* Shift Clock Configuration : Clock Idle Polarity: SPI_SHIFT_CLOCK_IDLE_LEVEL,
                                  Clock Phase: SPI_DATA_SHIFT_EDGE */
    Spi_ShiftClkConfig(SPI_CLK_IDLE_LOW,
                      SPI_DATA_SHIFT_LEAD),
   /* Job Priority escalated to Maximum as it is mapped
      to one or more non-interruptible sequence */
    SPI_JOB_PRIORITY_3,

    /* Spi HW Unit. bit[7:4]: Channel no, bit[3:0]: hw module no */
      (uint8)((uint8)SPI_QSPI_CHANNEL0 << 4U) | (SPI_QSPI2_INDEX),

    /* Channel Based Chip Select */
    (uint8)0U,
    
    /* Spi Parity Selection */
    (uint8)SPI_QSPI_PARITY_UNUSED,
    
  },
/* Job: SpiJob_SCTRL Configuration */
  {
   /* Job End Notification: Spi_JobEndNotification, SPI118 */
    NULL_PTR,
    /* User given name outside the naming convention */
    /* Spi_ChannelLinkPtr */
    SpiJob_SCTRL_ChannelLinkPtr,
    /* Baud Rate (1388888 Hz) Hw configuration Parameters */
    Spi_BaudRateParams(/*TQ*/(0x3U), /*Q*/(0x2U),
              /*A*/(0x2U), /*B*/(0x0U), /*C*/(0x3U)),

    /* Time Delay Configuration */
      (uint32)Spi_DelayParams(/*IPRE*/0x04U,/*IDLE*/ 0x04U,
        /*LPRE*/0x02U, /*LEAD*/0x06U,
        /*TPRE*/0x02U, /*TRAIL*/0x06U),

    SPI_CS_HW, /* Hw CS Pin is Selected */

    /*CS Active level Polarity*/
    SPI_CS_POLARITY_LOW,

 /* Shift Clock Configuration : Clock Idle Polarity: SPI_SHIFT_CLOCK_IDLE_LEVEL,
                                  Clock Phase: SPI_DATA_SHIFT_EDGE */
    Spi_ShiftClkConfig(SPI_CLK_IDLE_LOW,
                      SPI_DATA_SHIFT_LEAD),
   /* Job Priority escalated to Maximum as it is mapped
      to one or more non-interruptible sequence */
    SPI_JOB_PRIORITY_3,

    /* Spi HW Unit. bit[7:4]: Channel no, bit[3:0]: hw module no */
      (uint8)((uint8)SPI_QSPI_CHANNEL0 << 4U) | (SPI_QSPI2_INDEX),

    /* Channel Based Chip Select */
    (uint8)0U,
    
    /* Spi Parity Selection */
    (uint8)SPI_QSPI_PARITY_UNUSED,
    
  },
/* Job: SpiJob_SSCR Configuration */
  {
   /* Job End Notification: Spi_JobEndNotification, SPI118 */
    NULL_PTR,
    /* User given name outside the naming convention */
    /* Spi_ChannelLinkPtr */
    SpiJob_SSCR_ChannelLinkPtr,
    /* Baud Rate (1388888 Hz) Hw configuration Parameters */
    Spi_BaudRateParams(/*TQ*/(0x3U), /*Q*/(0x2U),
              /*A*/(0x2U), /*B*/(0x0U), /*C*/(0x3U)),

    /* Time Delay Configuration */
      (uint32)Spi_DelayParams(/*IPRE*/0x04U,/*IDLE*/ 0x04U,
        /*LPRE*/0x02U, /*LEAD*/0x06U,
        /*TPRE*/0x02U, /*TRAIL*/0x06U),

    SPI_CS_HW, /* Hw CS Pin is Selected */

    /*CS Active level Polarity*/
    SPI_CS_POLARITY_LOW,

 /* Shift Clock Configuration : Clock Idle Polarity: SPI_SHIFT_CLOCK_IDLE_LEVEL,
                                  Clock Phase: SPI_DATA_SHIFT_EDGE */
    Spi_ShiftClkConfig(SPI_CLK_IDLE_LOW,
                      SPI_DATA_SHIFT_LEAD),
   /* Job Priority escalated to Maximum as it is mapped
      to one or more non-interruptible sequence */
    SPI_JOB_PRIORITY_3,

    /* Spi HW Unit. bit[7:4]: Channel no, bit[3:0]: hw module no */
      (uint8)((uint8)SPI_QSPI_CHANNEL0 << 4U) | (SPI_QSPI2_INDEX),

    /* Channel Based Chip Select */
    (uint8)0U,
    
    /* Spi Parity Selection */
    (uint8)SPI_QSPI_PARITY_UNUSED,
    
  },
/* Job: SpiJob_SDESAT Configuration */
  {
   /* Job End Notification: Spi_JobEndNotification, SPI118 */
    NULL_PTR,
    /* User given name outside the naming convention */
    /* Spi_ChannelLinkPtr */
    SpiJob_SDESAT_ChannelLinkPtr,
    /* Baud Rate (1388888 Hz) Hw configuration Parameters */
    Spi_BaudRateParams(/*TQ*/(0x3U), /*Q*/(0x2U),
              /*A*/(0x2U), /*B*/(0x0U), /*C*/(0x3U)),

    /* Time Delay Configuration */
      (uint32)Spi_DelayParams(/*IPRE*/0x04U,/*IDLE*/ 0x04U,
        /*LPRE*/0x02U, /*LEAD*/0x06U,
        /*TPRE*/0x02U, /*TRAIL*/0x06U),

    SPI_CS_HW, /* Hw CS Pin is Selected */

    /*CS Active level Polarity*/
    SPI_CS_POLARITY_LOW,

 /* Shift Clock Configuration : Clock Idle Polarity: SPI_SHIFT_CLOCK_IDLE_LEVEL,
                                  Clock Phase: SPI_DATA_SHIFT_EDGE */
    Spi_ShiftClkConfig(SPI_CLK_IDLE_LOW,
                      SPI_DATA_SHIFT_LEAD),
   /* Job Priority escalated to Maximum as it is mapped
      to one or more non-interruptible sequence */
    SPI_JOB_PRIORITY_3,

    /* Spi HW Unit. bit[7:4]: Channel no, bit[3:0]: hw module no */
      (uint8)((uint8)SPI_QSPI_CHANNEL0 << 4U) | (SPI_QSPI2_INDEX),

    /* Channel Based Chip Select */
    (uint8)0U,
    
    /* Spi Parity Selection */
    (uint8)SPI_QSPI_PARITY_UNUSED,
    
  },
/* Job: SpiJob_SOCP Configuration */
  {
   /* Job End Notification: Spi_JobEndNotification, SPI118 */
    NULL_PTR,
    /* User given name outside the naming convention */
    /* Spi_ChannelLinkPtr */
    SpiJob_SOCP_ChannelLinkPtr,
    /* Baud Rate (1388888 Hz) Hw configuration Parameters */
    Spi_BaudRateParams(/*TQ*/(0x3U), /*Q*/(0x2U),
              /*A*/(0x2U), /*B*/(0x0U), /*C*/(0x3U)),

    /* Time Delay Configuration */
      (uint32)Spi_DelayParams(/*IPRE*/0x04U,/*IDLE*/ 0x04U,
        /*LPRE*/0x02U, /*LEAD*/0x06U,
        /*TPRE*/0x02U, /*TRAIL*/0x06U),

    SPI_CS_HW, /* Hw CS Pin is Selected */

    /*CS Active level Polarity*/
    SPI_CS_POLARITY_LOW,

 /* Shift Clock Configuration : Clock Idle Polarity: SPI_SHIFT_CLOCK_IDLE_LEVEL,
                                  Clock Phase: SPI_DATA_SHIFT_EDGE */
    Spi_ShiftClkConfig(SPI_CLK_IDLE_LOW,
                      SPI_DATA_SHIFT_LEAD),
   /* Job Priority escalated to Maximum as it is mapped
      to one or more non-interruptible sequence */
    SPI_JOB_PRIORITY_3,

    /* Spi HW Unit. bit[7:4]: Channel no, bit[3:0]: hw module no */
      (uint8)((uint8)SPI_QSPI_CHANNEL0 << 4U) | (SPI_QSPI2_INDEX),

    /* Channel Based Chip Select */
    (uint8)0U,
    
    /* Spi Parity Selection */
    (uint8)SPI_QSPI_PARITY_UNUSED,
    
  },
/* Job: SpiJob_SRTTOF Configuration */
  {
   /* Job End Notification: Spi_JobEndNotification, SPI118 */
    NULL_PTR,
    /* User given name outside the naming convention */
    /* Spi_ChannelLinkPtr */
    SpiJob_SRTTOF_ChannelLinkPtr,
    /* Baud Rate (1388888 Hz) Hw configuration Parameters */
    Spi_BaudRateParams(/*TQ*/(0x3U), /*Q*/(0x2U),
              /*A*/(0x2U), /*B*/(0x0U), /*C*/(0x3U)),

    /* Time Delay Configuration */
      (uint32)Spi_DelayParams(/*IPRE*/0x04U,/*IDLE*/ 0x04U,
        /*LPRE*/0x02U, /*LEAD*/0x06U,
        /*TPRE*/0x02U, /*TRAIL*/0x06U),

    SPI_CS_HW, /* Hw CS Pin is Selected */

    /*CS Active level Polarity*/
    SPI_CS_POLARITY_LOW,

 /* Shift Clock Configuration : Clock Idle Polarity: SPI_SHIFT_CLOCK_IDLE_LEVEL,
                                  Clock Phase: SPI_DATA_SHIFT_EDGE */
    Spi_ShiftClkConfig(SPI_CLK_IDLE_LOW,
                      SPI_DATA_SHIFT_LEAD),
   /* Job Priority escalated to Maximum as it is mapped
      to one or more non-interruptible sequence */
    SPI_JOB_PRIORITY_3,

    /* Spi HW Unit. bit[7:4]: Channel no, bit[3:0]: hw module no */
      (uint8)((uint8)SPI_QSPI_CHANNEL0 << 4U) | (SPI_QSPI2_INDEX),

    /* Channel Based Chip Select */
    (uint8)0U,
    
    /* Spi Parity Selection */
    (uint8)SPI_QSPI_PARITY_UNUSED,
    
  },
/* Job: SpiJob_SSTTOF Configuration */
  {
   /* Job End Notification: Spi_JobEndNotification, SPI118 */
    NULL_PTR,
    /* User given name outside the naming convention */
    /* Spi_ChannelLinkPtr */
    SpiJob_SSTTOF_ChannelLinkPtr,
    /* Baud Rate (1388888 Hz) Hw configuration Parameters */
    Spi_BaudRateParams(/*TQ*/(0x3U), /*Q*/(0x2U),
              /*A*/(0x2U), /*B*/(0x0U), /*C*/(0x3U)),

    /* Time Delay Configuration */
      (uint32)Spi_DelayParams(/*IPRE*/0x04U,/*IDLE*/ 0x04U,
        /*LPRE*/0x02U, /*LEAD*/0x06U,
        /*TPRE*/0x02U, /*TRAIL*/0x06U),

    SPI_CS_HW, /* Hw CS Pin is Selected */

    /*CS Active level Polarity*/
    SPI_CS_POLARITY_LOW,

 /* Shift Clock Configuration : Clock Idle Polarity: SPI_SHIFT_CLOCK_IDLE_LEVEL,
                                  Clock Phase: SPI_DATA_SHIFT_EDGE */
    Spi_ShiftClkConfig(SPI_CLK_IDLE_LOW,
                      SPI_DATA_SHIFT_LEAD),
   /* Job Priority escalated to Maximum as it is mapped
      to one or more non-interruptible sequence */
    SPI_JOB_PRIORITY_3,

    /* Spi HW Unit. bit[7:4]: Channel no, bit[3:0]: hw module no */
      (uint8)((uint8)SPI_QSPI_CHANNEL0 << 4U) | (SPI_QSPI2_INDEX),

    /* Channel Based Chip Select */
    (uint8)0U,
    
    /* Spi Parity Selection */
    (uint8)SPI_QSPI_PARITY_UNUSED,
    
  },
/* Job: SpiJob_SACLT Configuration */
  {
   /* Job End Notification: Spi_JobEndNotification, SPI118 */
    NULL_PTR,
    /* User given name outside the naming convention */
    /* Spi_ChannelLinkPtr */
    SpiJob_SACLT_ChannelLinkPtr,
    /* Baud Rate (1388888 Hz) Hw configuration Parameters */
    Spi_BaudRateParams(/*TQ*/(0x3U), /*Q*/(0x2U),
              /*A*/(0x2U), /*B*/(0x0U), /*C*/(0x3U)),

    /* Time Delay Configuration */
      (uint32)Spi_DelayParams(/*IPRE*/0x04U,/*IDLE*/ 0x04U,
        /*LPRE*/0x02U, /*LEAD*/0x06U,
        /*TPRE*/0x02U, /*TRAIL*/0x06U),

    SPI_CS_HW, /* Hw CS Pin is Selected */

    /*CS Active level Polarity*/
    SPI_CS_POLARITY_LOW,

 /* Shift Clock Configuration : Clock Idle Polarity: SPI_SHIFT_CLOCK_IDLE_LEVEL,
                                  Clock Phase: SPI_DATA_SHIFT_EDGE */
    Spi_ShiftClkConfig(SPI_CLK_IDLE_LOW,
                      SPI_DATA_SHIFT_LEAD),
   /* Job Priority escalated to Maximum as it is mapped
      to one or more non-interruptible sequence */
    SPI_JOB_PRIORITY_3,

    /* Spi HW Unit. bit[7:4]: Channel no, bit[3:0]: hw module no */
      (uint8)((uint8)SPI_QSPI_CHANNEL0 << 4U) | (SPI_QSPI2_INDEX),

    /* Channel Based Chip Select */
    (uint8)0U,
    
    /* Spi Parity Selection */
    (uint8)SPI_QSPI_PARITY_UNUSED,
    
  },
/* Job: SpiJob_CONF_Nop Configuration */
  {
   /* Job End Notification: Spi_JobEndNotification, SPI118 */
    NULL_PTR,
    /* User given name outside the naming convention */
    /* Spi_ChannelLinkPtr */
    SpiJob_CONF_Nop_ChannelLinkPtr,
    /* Baud Rate (1388888 Hz) Hw configuration Parameters */
    Spi_BaudRateParams(/*TQ*/(0x3U), /*Q*/(0x2U),
              /*A*/(0x2U), /*B*/(0x0U), /*C*/(0x3U)),

    /* Time Delay Configuration */
      (uint32)Spi_DelayParams(/*IPRE*/0x04U,/*IDLE*/ 0x04U,
        /*LPRE*/0x02U, /*LEAD*/0x06U,
        /*TPRE*/0x02U, /*TRAIL*/0x06U),

    SPI_CS_HW, /* Hw CS Pin is Selected */

    /*CS Active level Polarity*/
    SPI_CS_POLARITY_LOW,

 /* Shift Clock Configuration : Clock Idle Polarity: SPI_SHIFT_CLOCK_IDLE_LEVEL,
                                  Clock Phase: SPI_DATA_SHIFT_EDGE */
    Spi_ShiftClkConfig(SPI_CLK_IDLE_LOW,
                      SPI_DATA_SHIFT_LEAD),
   /* Job Priority escalated to Maximum as it is mapped
      to one or more non-interruptible sequence */
    SPI_JOB_PRIORITY_3,

    /* Spi HW Unit. bit[7:4]: Channel no, bit[3:0]: hw module no */
      (uint8)((uint8)SPI_QSPI_CHANNEL0 << 4U) | (SPI_QSPI2_INDEX),

    /* Channel Based Chip Select */
    (uint8)0U,
    
    /* Spi Parity Selection */
    (uint8)SPI_QSPI_PARITY_UNUSED,
    
  },
/* Job: SpiJob_TLF35584 Configuration */
  {
   /* Job End Notification: Spi_JobEndNotification, SPI118 */
    NULL_PTR,
    /* User given name outside the naming convention */
    /* Spi_ChannelLinkPtr */
    SpiJob_TLF35584_ChannelLinkPtr,
    /* Baud Rate (10000000 Hz) Hw configuration Parameters */
    Spi_BaudRateParams(/*TQ*/(0x0U), /*Q*/(0x1U),
              /*A*/(0x2U), /*B*/(0x0U), /*C*/(0x2U)),

    /* Time Delay Configuration */
      (uint32)Spi_DelayParams(/*IPRE*/0x02U,/*IDLE*/ 0x04U,
        /*LPRE*/0x03U, /*LEAD*/0x04U,
        /*TPRE*/0x03U, /*TRAIL*/0x04U),

    SPI_CS_HW, /* Hw CS Pin is Selected */

    /*CS Active level Polarity*/
    SPI_CS_POLARITY_LOW,

 /* Shift Clock Configuration : Clock Idle Polarity: SPI_SHIFT_CLOCK_IDLE_LEVEL,
                                  Clock Phase: SPI_DATA_SHIFT_EDGE */
    Spi_ShiftClkConfig(SPI_CLK_IDLE_LOW,
                      SPI_DATA_SHIFT_TRAIL),
   /* Job Priority escalated to Maximum as it is mapped
      to one or more non-interruptible sequence */
    SPI_JOB_PRIORITY_3,

    /* Spi HW Unit. bit[7:4]: Channel no, bit[3:0]: hw module no */
      (uint8)((uint8)SPI_QSPI_CHANNEL6 << 4U) | (SPI_QSPI0_INDEX),

    /* Channel Based Chip Select */
    (uint8)1U,

    /* Spi Parity Selection */
    (uint8)SPI_QSPI_PARITY_UNUSED,
    
  },
/* Job: SpiJob_CPLD Configuration */
  {
   /* Job End Notification: Spi_JobEndNotification, SPI118 */
    NULL_PTR,
    /* User given name outside the naming convention */
    /* Spi_ChannelLinkPtr */
    SpiJob_CPLD_ChannelLinkPtr,
    /* Baud Rate (500000 Hz) Hw configuration Parameters */
    Spi_BaudRateParams(/*TQ*/(0x0U), /*Q*/(0x13U),
              /*A*/(0x3U), /*B*/(0x3U), /*C*/(0x3U)),

    /* Time Delay Configuration */
      (uint32)Spi_DelayParams(/*IPRE*/0x02U,/*IDLE*/ 0x01U,
        /*LPRE*/0x02U, /*LEAD*/0x02U,
        /*TPRE*/0x02U, /*TRAIL*/0x01U),

    SPI_CS_HW, /* Hw CS Pin is Selected */

    /*CS Active level Polarity*/
    SPI_CS_POLARITY_LOW,

 /* Shift Clock Configuration : Clock Idle Polarity: SPI_SHIFT_CLOCK_IDLE_LEVEL,
                                  Clock Phase: SPI_DATA_SHIFT_EDGE */
    Spi_ShiftClkConfig(SPI_CLK_IDLE_LOW,
                      SPI_DATA_SHIFT_LEAD),
   /* Job Priority escalated to Maximum as it is mapped
      to one or more non-interruptible sequence */
    SPI_JOB_PRIORITY_3,

    /* Spi HW Unit. bit[7:4]: Channel no, bit[3:0]: hw module no */
      (uint8)((uint8)SPI_QSPI_CHANNEL5 << 4U) | (SPI_QSPI1_INDEX),

    /* Channel Based Chip Select */
    (uint8)1U,

    /* Spi Parity Selection */
    (uint8)SPI_QSPI_PARITY_UNUSED,
    
  },
/* Job: SpiJob_TJA1145 Configuration */
  {
   /* Job End Notification: Spi_JobEndNotification, SPI118 */
    NULL_PTR,
    /* User given name outside the naming convention */
    /* Spi_ChannelLinkPtr */
    SpiJob_TJA1145_ChannelLinkPtr,
    /* Baud Rate (1000000 Hz) Hw configuration Parameters */
    Spi_BaudRateParams(/*TQ*/(0x9U), /*Q*/(0x1U),
              /*A*/(0x2U), /*B*/(0x1U), /*C*/(0x1U)),

    /* Time Delay Configuration */
      (uint32)Spi_DelayParams(/*IPRE*/0x01U,/*IDLE*/ 0x01U,
        /*LPRE*/0x00U, /*LEAD*/0x01U,
        /*TPRE*/0x00U, /*TRAIL*/0x01U),

    SPI_CS_HW, /* Hw CS Pin is Selected */

    /*CS Active level Polarity*/
    SPI_CS_POLARITY_LOW,

 /* Shift Clock Configuration : Clock Idle Polarity: SPI_SHIFT_CLOCK_IDLE_LEVEL,
                                  Clock Phase: SPI_DATA_SHIFT_EDGE */
    Spi_ShiftClkConfig(SPI_CLK_IDLE_LOW,
                      SPI_DATA_SHIFT_LEAD),
   /* Job Priority escalated to Maximum as it is mapped
      to one or more non-interruptible sequence */
    SPI_JOB_PRIORITY_3,

    /* Spi HW Unit. bit[7:4]: Channel no, bit[3:0]: hw module no */
      (uint8)((uint8)SPI_QSPI_CHANNEL12 << 4U) | (SPI_QSPI3_INDEX),

    /* Channel Based Chip Select */
    (uint8)1U,

    /* Spi Parity Selection */
    (uint8)SPI_QSPI_PARITY_UNUSED,
    
  }
};

/*
                     Container: Spi_SequenceConfiguration
*/
/* Notification Function of Sequence: SpiSequence_0 */
extern void SpiSeq0EndNotification(void);
/* Notification Function of Sequence: SpiSequence_1 */
extern void SpiSeq1EndNotification(void);
/* Notification Function of Sequence: SpiSequence_2 */
extern void SpiSeq2EndNotification(void);
/* Notification Function of Sequence: SpiSequence_3 */
extern void SpiSeq3EndNotification(void);
/* Notification Function of Sequence: SpiSequence_6 */
extern void SpiSeq6EndNotification(void);
/* Notification Function of Sequence: SpiSequence_CddIgbtDrv_RdConf */
extern void SpiSeqCddIgbtDrv_RdConfEndNotification(void);
/* Notification Function of Sequence: SpiSequence_TLF35584 is NULL_PTR */
/* Notification Function of Sequence: SpiSequence_CPLD is NULL_PTR */
/* Notification Function of Sequence: SpiSequence_CddIgbtDrv_RdConf2 */
extern void SpiSeqCddIgbtDrv_RdConf2EndNotification(void);
/* Notification Function of Sequence: SpiSequence_TJA1145 is NULL_PTR */

/*
Configuration: Job Assignment
*/
/* Job Assignment of Sequence: SpiSequence_0 */
static const Spi_JobType SpiSequence_0_JobLinkPtr[] =
{
  SpiConf_SpiJob_SpiJob_WrH_PRW,
  SpiConf_SpiJob_SpiJob_WrL_PRW,
  SpiConf_SpiJob_SpiJob_Rd_PSTAT,
  SpiConf_SpiJob_SpiJob_Rd_PSTAT2,
  SpiConf_SpiJob_SpiJob_Rd_PER,
  SpiConf_SpiJob_SpiJob_Rd_SSTAT,
  SpiConf_SpiJob_SpiJob_Rd_SSTAT2,
  SpiConf_SpiJob_SpiJob_Rd_SER,
  SpiConf_SpiJob_SpiJob_Rd_SGM1,
  SpiConf_SpiJob_SpiJob_Rd_SGM2,
  SpiConf_SpiJob_SpiJob_PCTRL,
  SpiConf_SpiJob_SpiJob_PCTRL2,
  SpiConf_SpiJob_SpiJob_Rd_PRW,
  SpiConf_SpiJob_SpiJob_Nop,
  SPI_JOB_LINK_DELIMITER
};
/*
Configuration: Job Assignment
*/
/* Job Assignment of Sequence: SpiSequence_1 */
static const Spi_JobType SpiSequence_1_JobLinkPtr[] =
{
  SpiConf_SpiJob_SpiJob_ModeCtrl,
  SPI_JOB_LINK_DELIMITER
};
/*
Configuration: Job Assignment
*/
/* Job Assignment of Sequence: SpiSequence_2 */
static const Spi_JobType SpiSequence_2_JobLinkPtr[] =
{
  SpiConf_SpiJob_SpiJob_WrL,
  SPI_JOB_LINK_DELIMITER
};
/*
Configuration: Job Assignment
*/
/* Job Assignment of Sequence: SpiSequence_3 */
static const Spi_JobType SpiSequence_3_JobLinkPtr[] =
{
  SpiConf_SpiJob_SpiJob_WrH,
  SpiConf_SpiJob_SpiJob_WrL,
  SPI_JOB_LINK_DELIMITER
};
/*
Configuration: Job Assignment
*/
/* Job Assignment of Sequence: SpiSequence_6 */
static const Spi_JobType SpiSequence_6_JobLinkPtr[] =
{
  SpiConf_SpiJob_SpiJob_WrL_PCTRL,
  SpiConf_SpiJob_SpiJob_WrL_PCTRL2,
  SPI_JOB_LINK_DELIMITER
};
/*
Configuration: Job Assignment
*/
/* Job Assignment of Sequence: SpiSequence_CddIgbtDrv_RdConf */
static const Spi_JobType SpiSequence_CddIgbtDrv_RdConf_JobLinkPtr[] =
{
  SpiConf_SpiJob_SpiJob_PCFG,
  SpiConf_SpiJob_SpiJob_PCFG2,
  SpiConf_SpiJob_SpiJob_CONF_PCTRL,
  SpiConf_SpiJob_SpiJob_CONF_PCTRL2,
  SpiConf_SpiJob_SpiJob_PSCR,
  SpiConf_SpiJob_SpiJob_PRW,
  SpiConf_SpiJob_SpiJob_SCFG,
  SpiConf_SpiJob_SpiJob_SCFG2,
  SpiConf_SpiJob_SpiJob_SCTRL,
  SpiConf_SpiJob_SpiJob_SSCR,
  SpiConf_SpiJob_SpiJob_SDESAT,
  SpiConf_SpiJob_SpiJob_SOCP,
  SpiConf_SpiJob_SpiJob_SRTTOF,
  SpiConf_SpiJob_SpiJob_SSTTOF,
  SpiConf_SpiJob_SpiJob_SACLT,
  SpiConf_SpiJob_SpiJob_CONF_Nop,
  SPI_JOB_LINK_DELIMITER
};
/* Job Assignment of Sequence: SpiSequence_TLF35584 */
static const Spi_JobType SpiSequence_TLF35584_JobLinkPtr[] =
{
  SpiConf_SpiJob_SpiJob_TLF35584,
  SPI_JOB_LINK_DELIMITER
};
/* Job Assignment of Sequence: SpiSequence_CPLD */
static const Spi_JobType SpiSequence_CPLD_JobLinkPtr[] =
{
  SpiConf_SpiJob_SpiJob_CPLD,
  SPI_JOB_LINK_DELIMITER
};
/*
Configuration: Job Assignment
*/
/* Job Assignment of Sequence: SpiSequence_CddIgbtDrv_RdConf2 */
static const Spi_JobType SpiSequence_CddIgbtDrv_RdConf2_JobLinkPtr[] =
{
  SpiConf_SpiJob_SpiJob_PRW,
  SpiConf_SpiJob_SpiJob_SCFG,
  SpiConf_SpiJob_SpiJob_SCFG2,
  SpiConf_SpiJob_SpiJob_SDESAT,
  SpiConf_SpiJob_SpiJob_SRTTOF,
  SpiConf_SpiJob_SpiJob_SSTTOF,
  SpiConf_SpiJob_SpiJob_CONF_Nop,
  SPI_JOB_LINK_DELIMITER
};
/* Job Assignment of Sequence: SpiSequence_TJA1145 */
static const Spi_JobType SpiSequence_TJA1145_JobLinkPtr[] =
{
  SpiConf_SpiJob_SpiJob_TJA1145,
  SPI_JOB_LINK_DELIMITER
};




/* Printing of shared sequence */
static const Spi_SequenceType SpiSequence_2_SharedSeqsPtr[] = {
  SpiConf_SpiSequence_SpiSequence_3,
  SPI_SHARED_JOBS_DELIMITER
};


/* Printing of shared sequence */
static const Spi_SequenceType SpiSequence_3_SharedSeqsPtr[] = {
  SpiConf_SpiSequence_SpiSequence_2,
  SPI_SHARED_JOBS_DELIMITER
};



/* Printing of shared sequence */
static const Spi_SequenceType SpiSequence_CddIgbtDrv_RdConf_SharedSeqsPtr[] = {
  SpiConf_SpiSequence_SpiSequence_CddIgbtDrv_RdConf2,
  SPI_SHARED_JOBS_DELIMITER
};




/* Printing of shared sequence */
static const Spi_SequenceType SpiSequence_CddIgbtDrv_RdConf2_SharedSeqsPtr[] = {
  SpiConf_SpiSequence_SpiSequence_CddIgbtDrv_RdConf,
  SPI_SHARED_JOBS_DELIMITER
};

/*
Configuration: Sequence Configuration Constant Structure.
*/
static const Spi_SequenceConfigType Spi_kSequenceConfig0[] =
{   /* Sequence: SpiSequence_TLF35584 Configuration */
  {
    /* Spi_SeqEndNotification */
    NULL_PTR,

    /* User given name outside the naming convention */    /* Spi_JobLinkPtr */
    SpiSequence_TLF35584_JobLinkPtr,

    /* User given name outside the naming convention */
    /* Sequences that share jobs with this sequence */
    NULL_PTR,
    /* This holds the total number of jobs linked to this sequence */
    1U,
  /* Holds the Hw modules used by the sequence  */
    (uint8)1U
  },
  /* Sequence: SpiSequence_CPLD Configuration */
  {
    /* Spi_SeqEndNotification */
    NULL_PTR,

    /* User given name outside the naming convention */    /* Spi_JobLinkPtr */
    SpiSequence_CPLD_JobLinkPtr,

    /* User given name outside the naming convention */
    /* Sequences that share jobs with this sequence */
    NULL_PTR,
    /* This holds the total number of jobs linked to this sequence */
    1U,
  /* Holds the Hw modules used by the sequence  */
    (uint8)2U
  },
  /* Sequence: SpiSequence_TJA1145 Configuration */
  {
    /* Spi_SeqEndNotification */
    NULL_PTR,

    /* User given name outside the naming convention */    /* Spi_JobLinkPtr */
    SpiSequence_TJA1145_JobLinkPtr,

    /* User given name outside the naming convention */
    /* Sequences that share jobs with this sequence */
    NULL_PTR,
    /* This holds the total number of jobs linked to this sequence */
    1U,
  /* Holds the Hw modules used by the sequence  */
    (uint8)8U
  },
    
  /* Sequence: SpiSequence_0 Configuration */
  {
    /* Spi_SeqEndNotification */
    &SpiSeq0EndNotification,

    /* User given name outside the naming convention */    /* Spi_JobLinkPtr */
    SpiSequence_0_JobLinkPtr,

    /* User given name outside the naming convention */
    /* Sequences that share jobs with this sequence */
    NULL_PTR,
     /* This holds the total number of jobs linked to this sequence */
    14U,
  /* Holds the Hw modules used by the sequence.
    For ASync Sequences in SpiLevelDeliverd 2, it's not applicable  */
  (uint8)0U
  },
  /* Sequence: SpiSequence_1 Configuration */
  {
    /* Spi_SeqEndNotification */
    &SpiSeq1EndNotification,

    /* User given name outside the naming convention */    /* Spi_JobLinkPtr */
    SpiSequence_1_JobLinkPtr,

    /* User given name outside the naming convention */
    /* Sequences that share jobs with this sequence */
    NULL_PTR,
     /* This holds the total number of jobs linked to this sequence */
    1U,
  /* Holds the Hw modules used by the sequence.
    For ASync Sequences in SpiLevelDeliverd 2, it's not applicable  */
  (uint8)0U
  },
  /* Sequence: SpiSequence_2 Configuration */
  {
    /* Spi_SeqEndNotification */
    &SpiSeq2EndNotification,

    /* User given name outside the naming convention */    /* Spi_JobLinkPtr */
    SpiSequence_2_JobLinkPtr,

    /* User given name outside the naming convention */
    /* Sequences that share jobs with this sequence */
    SpiSequence_2_SharedSeqsPtr,
     /* This holds the total number of jobs linked to this sequence */
    1U,
  /* Holds the Hw modules used by the sequence.
    For ASync Sequences in SpiLevelDeliverd 2, it's not applicable  */
  (uint8)0U
  },
  /* Sequence: SpiSequence_3 Configuration */
  {
    /* Spi_SeqEndNotification */
    &SpiSeq3EndNotification,

    /* User given name outside the naming convention */    /* Spi_JobLinkPtr */
    SpiSequence_3_JobLinkPtr,

    /* User given name outside the naming convention */
    /* Sequences that share jobs with this sequence */
    SpiSequence_3_SharedSeqsPtr,
     /* This holds the total number of jobs linked to this sequence */
    2U,
  /* Holds the Hw modules used by the sequence.
    For ASync Sequences in SpiLevelDeliverd 2, it's not applicable  */
  (uint8)0U
  },
  /* Sequence: SpiSequence_6 Configuration */
  {
    /* Spi_SeqEndNotification */
    &SpiSeq6EndNotification,

    /* User given name outside the naming convention */    /* Spi_JobLinkPtr */
    SpiSequence_6_JobLinkPtr,

    /* User given name outside the naming convention */
    /* Sequences that share jobs with this sequence */
    NULL_PTR,
     /* This holds the total number of jobs linked to this sequence */
    2U,
  /* Holds the Hw modules used by the sequence.
    For ASync Sequences in SpiLevelDeliverd 2, it's not applicable  */
  (uint8)0U
  },
  /* Sequence: SpiSequence_CddIgbtDrv_RdConf Configuration */
  {
    /* Spi_SeqEndNotification */
    &SpiSeqCddIgbtDrv_RdConfEndNotification,

    /* User given name outside the naming convention */    /* Spi_JobLinkPtr */
    SpiSequence_CddIgbtDrv_RdConf_JobLinkPtr,

    /* User given name outside the naming convention */
    /* Sequences that share jobs with this sequence */
    SpiSequence_CddIgbtDrv_RdConf_SharedSeqsPtr,
     /* This holds the total number of jobs linked to this sequence */
    16U,
  /* Holds the Hw modules used by the sequence.
    For ASync Sequences in SpiLevelDeliverd 2, it's not applicable  */
  (uint8)0U
  },
  /* Sequence: SpiSequence_CddIgbtDrv_RdConf2 Configuration */
  {
    /* Spi_SeqEndNotification */
    &SpiSeqCddIgbtDrv_RdConf2EndNotification,

    /* User given name outside the naming convention */    /* Spi_JobLinkPtr */
    SpiSequence_CddIgbtDrv_RdConf2_JobLinkPtr,

    /* User given name outside the naming convention */
    /* Sequences that share jobs with this sequence */
    SpiSequence_CddIgbtDrv_RdConf2_SharedSeqsPtr,
     /* This holds the total number of jobs linked to this sequence */
    7U,
  /* Holds the Hw modules used by the sequence.
    For ASync Sequences in SpiLevelDeliverd 2, it's not applicable  */
  (uint8)0U
  },
};

static const Spi_DmaConfigType Spi_kDmaConfig0[]=
{

  { /* QSPI0 Module Hw Dma Config */
    DMA_CHANNEL_INVALID,  /* Tx */    DMA_CHANNEL_INVALID   /* Rx */  },

  { /* QSPI1 Module Hw Dma Config */
    DMA_CHANNEL_INVALID,  /* Tx */    DMA_CHANNEL_INVALID   /* Rx */  },

  { /* QSPI2 Module Hw Dma Config */
    DMA_CHANNEL31,  /* Tx */    DMA_CHANNEL30   /* Rx */  },

  { /* QSPI3 Module Hw Dma Config */
    DMA_CHANNEL_INVALID,  /* Tx */    DMA_CHANNEL_INVALID   /* Rx */  },

};

static const Spi_HWModuleConfigType Spi_kModuleConfig0[]=
{
  /* QSPI0 Module */
  {
      /*Clock Settings:Sleep Control Disabled*/
      SPI_CLK_SLEEP_DISABLE,
	  /*SSOC register value for QSPI0*/
	  (uint32)0x0U,
      SPI_QSPI0_MRIS_SEL,
      &Spi_kDmaConfig0[0U],
  },
  /* QSPI1 Module */
  {
      /*Clock Settings:Sleep Control Disabled*/
      SPI_CLK_SLEEP_DISABLE,
	  /*SSOC register value for QSPI1*/
	  (uint32)0x0U,
      SPI_QSPI1_MRIS_SEL,
      &Spi_kDmaConfig0[1U],
  },
  /* QSPI2 Module */
  {
      /*Clock Settings:Sleep Control Disabled*/
      SPI_CLK_SLEEP_DISABLE,
  	  /*SSOC register value for QSPI2*/
	  (uint32)0x0U,
      SPI_QSPI2_MRIS_SEL,
      &Spi_kDmaConfig0[2U],
  },
  /* QSPI3 Module */
  {
      /*Clock Settings:Sleep Control Disabled*/
      SPI_CLK_SLEEP_DISABLE,
  	  /*SSOC register value for QSPI3*/
	  (uint32)0x0U,
      SPI_QSPI3_MRIS_SEL,
      &Spi_kDmaConfig0[3U],
  },
};



static const Spi_BaudrateEconType Spi_kBaudrateEcon0[]=
{
  {
    Spi_BaudRateECON(0x2U, 0x2U, 0x0U, 0x3U,
    SPI_DATA_SHIFT_LEAD,
    SPI_CLK_IDLE_LOW,
    SPI_QSPI_PARITY_DISABLE),
    (uint8)((uint8)SPI_QSPI_CHANNEL0 << 4U) | (SPI_QSPI2_INDEX)
  },
  {
    Spi_BaudRateECON(0x1U, 0x2U, 0x1U, 0x1U,
    SPI_DATA_SHIFT_LEAD,
    SPI_CLK_IDLE_LOW,
    SPI_QSPI_PARITY_DISABLE),
    (uint8)((uint8)SPI_QSPI_CHANNEL12 << 4U) | (SPI_QSPI3_INDEX)
  },
  {
    Spi_BaudRateECON(0x1U, 0x2U, 0x0U, 0x2U,
    SPI_DATA_SHIFT_TRAIL,
    SPI_CLK_IDLE_LOW,
    SPI_QSPI_PARITY_DISABLE),
    (uint8)((uint8)SPI_QSPI_CHANNEL6 << 4U) | (SPI_QSPI0_INDEX)
  },
  {
    Spi_BaudRateECON(0x13U, 0x3U, 0x3U, 0x3U,
    SPI_DATA_SHIFT_LEAD,
    SPI_CLK_IDLE_LOW,
    SPI_QSPI_PARITY_DISABLE),
    (uint8)((uint8)SPI_QSPI_CHANNEL5 << 4U) | (SPI_QSPI1_INDEX)
  }
};

const Spi_ConfigType Spi_ConfigRoot[1U] =
{
  {
    Spi_kChannelConfig0,
    Spi_kJobConfig0,
    Spi_kSequenceConfig0,
    {
      &Spi_kModuleConfig0[0U],
      &Spi_kModuleConfig0[1U],
      &Spi_kModuleConfig0[2U],
      &Spi_kModuleConfig0[3U],
    },
    Spi_kBaudrateEcon0,
    (Spi_JobType)(sizeof(Spi_kJobConfig0) / sizeof(Spi_JobConfigType)),
    (Spi_ChannelType)(sizeof(Spi_kChannelConfig0) / \
                      sizeof(Spi_ChannelConfigType)),
    (Spi_SequenceType)(sizeof(Spi_kSequenceConfig0) / \
                                        sizeof(Spi_SequenceConfigType)),
    (uint8)(sizeof(Spi_kBaudrateEcon0) / sizeof(Spi_BaudrateEconType)),
    3U
  }
};


#define SPI_STOP_SEC_POSTBUILDCFG
/* Allows to map variables, constants and code of modules to individual
  memory sections.*/
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
allowed only for MemMap.h*/  
#include "MemMap.h"

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/
/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
/* General Notes */
/*
SPI095: The code file structure shall not be defined within this specification
completely. At this point it shall be pointed out that the code-file structure
shall include the following file named:
- Spi_Lcfg.c ?for link time and for post-build configurable parameters and
- Spi_PBcfg.c ?for post build time configurable parameters.
These files shall contain all link time and post-build time configurable
parameters.
This file shall contain all link time and post-build time configurable
parameters.
For the implementation of VariantPC, the implementation stores the
pre compile time parameters that have to be defined as constants in this file.

SPI123: In this configuration, all Sequences declared are considered as Non
Interruptible Sequences. That means, their dedicated parameter
SPI_INTERRUPTIBLE_SEQUENCE (see SPI064 & SPI106) could be omitted or the
FALSE value should be used as default.

*/


