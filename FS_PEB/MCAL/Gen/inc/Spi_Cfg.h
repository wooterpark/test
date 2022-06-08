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
**  FILENAME  : Spi_Cfg.h                                                     **
**                                                                            **
**  $CC VERSION : \main\89 $                                                 **
**                                                                            **
**  DATE, TIME: 2021-09-29, 16:08:33                                          **
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
#ifndef SPI_CFG_H
#define SPI_CFG_H
/*Section to Generate Autosar Specific Version Information*/


#define SPI_AR_RELEASE_MAJOR_VERSION  (4U)
#define SPI_AR_RELEASE_MINOR_VERSION  (0U)
#define SPI_AR_RELEASE_REVISION_VERSION  (3U)

/*Section to Generate Vendor Specific Version Information*/
/* Vendor specific implementation version information */
#define SPI_SW_MAJOR_VERSION   (4U)
#define SPI_SW_MINOR_VERSION   (9U)
#define SPI_SW_PATCH_VERSION   (0U)

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
  /* Configuration: Total number of Config Root */
#define SPI_CONFIG_COUNT  (1U)

/*
         Container : SpiGeneralConfiguration
*/

/*
Configuration: SPI_DEV_ERROR_DETECT
- if STD_ON, DET is Enabled
- if STD_OFF,DET is Disabled
SPI005: The detection of all development errors is configurable (On / Off)
at precompile time. The switch SPI_DEV_ERROR_DETECT (see chapter 10) shall
activate or deactivate the detection of all development errors.

SPI029:If the switch SPI_DEV_ERROR_DETECT is enabled API parameter checking
is also enabled.
*/
#define SPI_DEV_ERROR_DETECT  (STD_OFF)


/*
Configuration: SPI_VERSION_INFO_API
- if STD_ON, Function Spi_GetVersionInfo is available
- if STD_OFF,Function Spi_GetVersionInfo is not available
*/
#define SPI_VERSION_INFO_API  (STD_OFF)


/*
Configuration: SPI_LEVEL_DELIVERED
Configure the Spi Handler/driver level of scalablity
0:The LEVEL 0 Simple Synchronous SPI Handler/Driver functionalities are
  selected.
1:The LEVEL 1 Basic Asynchronous SPI Handler/Driver functionalities are
  selected.
2:The LEVEL 2 Enhanced SPI Handler/Driver functionalities are selected.
SPI109: The SPI Handler/Driver level of scalable functionality shall be always
statically configurable, that means configured at pre-compile time, to allow the
best source code optimisation.
SPI110: In order to select the SPI Handler/Driver level of scalable
functionality, the SPI_LEVEL_DELIVERED parameter shall be configured with
one of the 3 authorized values according to the described levels: 0, 1 or 2.
*/
#define SPI_LEVEL_DELIVERED  (2U)

/*
SPI LEVEL 2 supports both Synchronous and Asynchronou transmision.
"SPI_LEVEL2_ASYNC_ONLY" macro is applicable for only LEVEL 2,
 where in only Asynchronous jobs are defined.
*/
#define SPI_LEVEL2_ASYNC_ONLY  (STD_OFF)


/*
Configuration: SPI_CHANNEL_BUFFERS_ALLOWED
Configure the Spi Handler/driver buffer usage
0:The Usage 0, only Internal Buffers are selected in Handler/Driver.
1:The Usage 1, only External Buffers are selected in Handler/Driver.
2:The Usage 2, both Internal and External Buffers are selected in
Handler/Driver.
SPI111: In order to select which Channel Buffers the SPI Handler/Driver manages,
the SPI_CHANNEL_BUFFERS_ALLOWED parameter shall be configured with one of
the 3 authorized values according to the described usage: 0, 1 or 2.
SPI115,SPI117.
*/
#define SPI_CHANNEL_BUFFERS_ALLOWED  (1U)

/*
Configuration: SPI_INTERRUPTABLE_SEQUENCE_ALLOWED
- if STD_ON, configuration of interruptible sequences is allowed
- if STD_OFF,configuration of interruptible sequences is not allowed
SPI121, SPI122
*/
#define SPI_INTERRUPTABLE_SEQUENCE_ALLOWED  (STD_OFF)


/*
Configuration: SPI_HW_STATUS_API
- if STD_ON, Function Spi_GetHWUnitStatus is available
- if STD_OFF,Function Spi_GetHWUnitStatus is not available
*/
#define SPI_HW_STATUS_API  (STD_OFF)


/*
Configuration: SPI_HW_STATUS_API
- if STD_ON, Function Spi_Cancel is available
- if STD_OFF,Function Spi_Cancel is not available
*/
#define SPI_CANCEL_API  (STD_OFF)


/*
Configuration: SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT
- if STD_ON, concurrent Spi_SyncTransmit() calls for different se-quences on
    different buses allowed
- if STD_OFF, concurrent Spi_SyncTransmit() calls for different se-quences on
   different buses Not allowed
*/
#define SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT  (STD_ON)


/*
Configuration: SPI_MAX_JOB_TRIG_Q_LENGTH
Configure the total SPI Job Queue length.
*/
#define SPI_MAX_JOB_TRIG_Q_LENGTH  (100U)

/*
Configuration: SPI_PB_FIXEDADDR
- if STD_ON, Fixed Address feature is Enabled
- if STD_OFF,Fixed Address feature is Disabled
*/
#define SPI_PB_FIXEDADDR  (STD_OFF)



/*
Configuration: Spi_RUNNING_IN_USER_0_MODE_ENABLE 
- if STD_ON, enable User0 mode 
- if STD_OFF, enable User1 mode 
*/
#define SPI_RUNNING_IN_USER_0_MODE_ENABLE (STD_OFF)

/*
Configuration: SPI_USER_MODE_INIT_API_ENABLE
- if STD_ON, Enable Protected Mode(user mode) in Init API 
- if STD_OFF, Enable Supervisor mode in Init API  
*/
#define  SPI_USER_MODE_INIT_API_ENABLE (STD_OFF)

/*Configuration: SPI_USER_MODE_DEINIT_API_ENABLE
- if STD_ON, Enable Protected mode in DeInit API 
- if STD_OFF, Disable Protected mode in DeInit API
*/
#define  SPI_USER_MODE_DEINIT_API_ENABLE (STD_OFF)

/*Configuration: SPI_MODE_RUNTIME_API_ENABLE
- if STD_ON, Enable Protected mode in APIs other than Init/Deinit APIs
- if STD_OFF, Disable Protected mode in APIs other than Init/Deinit APIs
*/
#define  SPI_USER_MODE_RUNTIME_API_ENABLE (STD_OFF)

/*
Configuration: SPI_SYNCTRANSMIT_TIMEOUT_COUNTER
 Timeout loop counter while waiting for data transmission/reception
 of 1 data element
*/
#define SPI_SYNCTRANSMIT_TIMEOUT_COUNTER  (1048575U)


/*
                 Container : SpiDriverConfiguration
*/

/*
Configuration : SPI_MAXIMUM_SEQUENCE
It is the maximum among the total number of sequences configured in each
Spi configuration.
For example if there are two post build configurations with 2 and 3 sequences
repectively, SPI_MAXIMUM_SEQUENCE must be configured as 3.
*/
#define SPI_MAXIMUM_SEQUENCE (10U)

/*
Configuration : SPI_MAXIMUM_IB_BUFFER_SIZE(Vendor Specific)
It is the maximum among the total number of IB buffer size configured in each
Spi configuration.
For example if there are two post build configurations, one having 3 IB channels
with total buffer size 30 and another having 2 IB channels with total buffer
size 40, SPI_MAXIMUM_IB_BUFFER_SIZE must be configured as 40.
The IB Buffer is realized by software implementation.
This parameter provides the buffer size to be used based on the number of
IB Channels configured and their buffer size.
*/

#define SPI_MAXIMUM_IB_BUFFER_SIZE  (4U)
/*
Configuration : SPI_MAXIMUM_EB_CHANNELS(Vendor Specific)
It is the maximum among the total number of EB channels configured in each
Spi configuration.
For example if there are two post build configurations, one having 5 EB channels
and another having 2 EB channels, SPI_MAXIMUM_EB_CHANNELS must be
configured as 5.
*/
#define SPI_MAXIMUM_EB_CHANNELS  (43U)

/*
Configuration: SPI_MAXIMUM_IB_CHANNELS(Vendor Specific)
It is the maximum among the total number of IB channels configured in each
Spi configuration.
For example if there are two post build configurations, one having 3 IB channels
and another having 6 IB channels, SPI_MAXIMUM_IB_CHANNELS must be
configured as 6.
*/
#define SPI_MAXIMUM_IB_CHANNELS  (0U)

/*
Configuration: SPI_MAXIMUM_CHANNEL
It is the maximum among the total number of channels configured in each
Spi configuration.
*/
#define SPI_MAXIMUM_CHANNEL  (43U)

/*
Configuration: SPI_MAXIMUM_JOB
It is the maximum among the total number of Jobs configured in each
Spi configuration.
*/
#define SPI_MAXIMUM_JOB  (43U)

/*
Configuration: SPI_WRITELOCK_INDEX
This is the array index valve to define the total number of IB channels
configured to be used in Spi_WriteIB API to lock the channels using
variable Spi_ChannelWriteLock
*/
#define SPI_WRITELOCK_INDEX (0U)

/*
Configuration: SPI_SAFETY_ENABLE
This determines if the safety features of SPI is enabled or not.
*/
#define SPI_SAFETY_ENABLE (STD_OFF)

/*
Configuration: SPI_SLAVE_ENABLE
This determines if the Slave has been configured or not
*/
#define SPI_SLAVE_ENABLE (STD_OFF)



/*
                    Container : SpiChannelConfiguration
*/
/*
Configuration: SPI_CHANNEL_NAME
SPI Driver Channel Symbolic Names. For Each Channel a unique Id is created.
The Symbolic Name is Equivalent to the Channel Container Name
*/

/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiChannel_SpiChannel_WrH_PRW ((Spi_ChannelType)0U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiChannel_SpiChannel_WrL_PRW ((Spi_ChannelType)1U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiChannel_SpiChannel_Rd_PSTAT ((Spi_ChannelType)2U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiChannel_SpiChannel_Rd_PSTAT2 ((Spi_ChannelType)3U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiChannel_SpiChannel_Rd_PER ((Spi_ChannelType)4U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiChannel_SpiChannel_Rd_PPIN ((Spi_ChannelType)5U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiChannel_SpiChannel_Rd_PCS ((Spi_ChannelType)6U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiChannel_SpiChannel_Rd_SSTAT ((Spi_ChannelType)7U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiChannel_SpiChannel_Rd_SSTAT2 ((Spi_ChannelType)8U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiChannel_SpiChannel_Rd_SER ((Spi_ChannelType)9U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiChannel_SpiChannel_Rd_SGM1 ((Spi_ChannelType)10U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiChannel_SpiChannel_Rd_SGM2 ((Spi_ChannelType)11U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiChannel_SpiChannel_Rd_SCS ((Spi_ChannelType)12U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiChannel_SpiChannel_ModeCtrl ((Spi_ChannelType)13U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiChannel_SpiChannel_WrH ((Spi_ChannelType)14U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiChannel_SpiChannel_WrL ((Spi_ChannelType)15U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiChannel_SpiChannel_Other ((Spi_ChannelType)16U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiChannel_SpiChannel_Rd_PCTRL ((Spi_ChannelType)17U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiChannel_SpiChannel_Rd_PCTRL2 ((Spi_ChannelType)18U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiChannel_SpiChannel_Rd_SCTRL ((Spi_ChannelType)19U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiChannel_SpiChannel_Rd_PRW ((Spi_ChannelType)20U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiChannel_SpiChannel_Nop ((Spi_ChannelType)21U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiChannel_SpiChannel_WrL_PCTRL ((Spi_ChannelType)22U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiChannel_SpiChannel_WrL_PCTRL2 ((Spi_ChannelType)23U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiChannel_SpiChannel_PCFG ((Spi_ChannelType)24U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiChannel_SpiChannel_PCFG2 ((Spi_ChannelType)25U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiChannel_SpiChannel_PCTRL ((Spi_ChannelType)26U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiChannel_SpiChannel_PCTRL2 ((Spi_ChannelType)27U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiChannel_SpiChannel_PSCR ((Spi_ChannelType)28U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiChannel_SpiChannel_PRW ((Spi_ChannelType)29U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiChannel_SpiChannel_SCFG ((Spi_ChannelType)30U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiChannel_SpiChannel_SCFG2 ((Spi_ChannelType)31U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiChannel_SpiChannel_SCTRL ((Spi_ChannelType)32U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiChannel_SpiChannel_SSCR ((Spi_ChannelType)33U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiChannel_SpiChannel_SDESAT ((Spi_ChannelType)34U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiChannel_SpiChannel_SOCP ((Spi_ChannelType)35U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiChannel_SpiChannel_SRTTOF ((Spi_ChannelType)36U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiChannel_SpiChannel_SSTTOF ((Spi_ChannelType)37U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiChannel_SpiChannel_SACLT ((Spi_ChannelType)38U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiChannel_SpiChannel_CONF_Nop ((Spi_ChannelType)39U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiChannel_SpiChannel_TLF35584 ((Spi_ChannelType)40U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiChannel_SpiChannel_CPLD ((Spi_ChannelType)41U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiChannel_SpiChannel_TJA1145 ((Spi_ChannelType)42U)

/*
Configuration Options:
Selection of Channel Buffer Type
*/
/* EB Buffer Channel Type */
#define SPI_EB_BUFFER   (0U)

/* IB Buffer Channel Type */
#define SPI_IB_BUFFER   (1U)

/*
Configuration Options:
SPI Data Order Options
*/
/* Least Significant Bit is transferred first */
#define SPI_DATA_LSB_FIRST   (0U)

/* Most Significant Bit is transferred first */
#define SPI_DATA_MSB_FIRST   (1U)

/*
Macro: CHANNEL_LINK_DELIMITER
Identifier for Channel Link End Delimiter.
This parameter is used internally in the driver code to determine end
of Channel Link.
*/
#define SPI_CHANNEL_LINK_DELIMITER ((Spi_ChannelType)0xFFU)

/*
                   Container : SpiJobConfiguration
*/

/*
Configuration: Job Name
SPI Driver Job Symbolic Names. For Each Job a unique Id is created.
The Symbolic Name is Equivalent to the Job Container Name.
This name is referenced to build the Job Link within a sequence.
*/
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiJob_SpiJob_WrH_PRW ((Spi_JobType)0U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiJob_SpiJob_WrL_PRW ((Spi_JobType)1U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiJob_SpiJob_Rd_PSTAT ((Spi_JobType)2U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiJob_SpiJob_Rd_PSTAT2 ((Spi_JobType)3U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiJob_SpiJob_Rd_PER ((Spi_JobType)4U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiJob_SpiJob_Rd_PPIN ((Spi_JobType)5U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiJob_SpiJob_Rd_PCS ((Spi_JobType)6U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiJob_SpiJob_Rd_SSTAT ((Spi_JobType)7U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiJob_SpiJob_Rd_SSTAT2 ((Spi_JobType)8U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiJob_SpiJob_Rd_SER ((Spi_JobType)9U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiJob_SpiJob_PCTRL ((Spi_JobType)10U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiJob_SpiJob_PCTRL2 ((Spi_JobType)11U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiJob_SpiJob_Nop ((Spi_JobType)12U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiJob_SpiJob_ModeCtrl ((Spi_JobType)13U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiJob_SpiJob_WrH ((Spi_JobType)14U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiJob_SpiJob_WrL ((Spi_JobType)15U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiJob_SpiJob_Other ((Spi_JobType)16U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiJob_SpiJob_Rd_SGM1 ((Spi_JobType)17U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiJob_SpiJob_Rd_SGM2 ((Spi_JobType)18U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiJob_SpiJob_Rd_SCS ((Spi_JobType)19U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiJob_SpiJob_Rd_SCTRL ((Spi_JobType)20U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiJob_SpiJob_Rd_PRW ((Spi_JobType)21U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiJob_SpiJob_WrL_PCTRL ((Spi_JobType)22U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiJob_SpiJob_WrL_PCTRL2 ((Spi_JobType)23U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiJob_SpiJob_PCFG ((Spi_JobType)24U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiJob_SpiJob_PCFG2 ((Spi_JobType)25U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiJob_SpiJob_CONF_PCTRL ((Spi_JobType)26U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiJob_SpiJob_CONF_PCTRL2 ((Spi_JobType)27U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiJob_SpiJob_PSCR ((Spi_JobType)28U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiJob_SpiJob_PRW ((Spi_JobType)29U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiJob_SpiJob_SCFG ((Spi_JobType)30U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiJob_SpiJob_SCFG2 ((Spi_JobType)31U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiJob_SpiJob_SCTRL ((Spi_JobType)32U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiJob_SpiJob_SSCR ((Spi_JobType)33U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiJob_SpiJob_SDESAT ((Spi_JobType)34U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiJob_SpiJob_SOCP ((Spi_JobType)35U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiJob_SpiJob_SRTTOF ((Spi_JobType)36U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiJob_SpiJob_SSTTOF ((Spi_JobType)37U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiJob_SpiJob_SACLT ((Spi_JobType)38U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiJob_SpiJob_CONF_Nop ((Spi_JobType)39U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiJob_SpiJob_TLF35584 ((Spi_JobType)40U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiJob_SpiJob_CPLD ((Spi_JobType)41U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiJob_SpiJob_TJA1145 ((Spi_JobType)42U)
/*
Configuration Options:
SPI Shift Clock Idle Levels
*/
/* Idle Level : Low Voltage Level */
#define SPI_CLK_IDLE_LOW       (0U)
/* Idle Level : High Voltage Level */
#define SPI_CLK_IDLE_HIGH      (1U)

/*
Configuration Options:
SPI Data Shift Edge Options
*/
#define SPI_DATA_SHIFT_LEAD    ((uint8)1U)
#define SPI_DATA_SHIFT_TRAIL   ((uint8)0U)

/*
Configuration Options:
SPI CS Polarity Levels (The Active Level)
*/
/* Polarity : Low Voltage Level */
#define SPI_CS_POLARITY_LOW    (0U)
/* Polarity : High Voltage Level */
#define SPI_CS_POLARITY_HIGH   (1U)

/*
Configuration Options:
SPI CS Pins
*/
/* The  CS Pins are configured in the Module Port */
/* The following define is used if no Pins are referenced */
#define SPI_CS_NONE ((uint16)0xFFFFU)

#define SPI_CS_HW   ((uint16)0xEFFFU)


/*
Macro:JOB_LINK_DELIMITER
Job Link End Delimiter.
This parameter is used internally in the driver code to determine end
of Job Link.
*/
#define SPI_JOB_LINK_DELIMITER ((Spi_JobType)0xFFFFU)

/*
Macro:SPI_SHARED_JOBS_DELIMITER
Sequences sharing jobs end Delimiter.
This parameter is used internally in the driver code to determine end
of sequences sharing the Job Link.
*/
#define SPI_SHARED_JOBS_DELIMITER ((uint8)0xFFU)


/*
            Container : SpiSequenceConfiguration
*/

/*
Configuration Options:
SPI Sequence Interruptible Options
*/
#define SPI_SEQ_INT_FALSE     ((uint8)0U)
#define SPI_SEQ_INT_TRUE      ((uint8)1U)

/*
Configuration: SPI_SEQUENCE_NAME
SPI Driver Sequence Symbolic Names. For Each Sequence a unique Id is created.
The Symbolic Name is Equivalent to the Sequence Container Name*/

/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiSequence_SpiSequence_TLF35584 ((Spi_SequenceType)0U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiSequence_SpiSequence_CPLD ((Spi_SequenceType)1U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiSequence_SpiSequence_TJA1145 ((Spi_SequenceType)2U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiSequence_SpiSequence_0 ((Spi_SequenceType)3U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiSequence_SpiSequence_1 ((Spi_SequenceType)4U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiSequence_SpiSequence_2 ((Spi_SequenceType)5U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiSequence_SpiSequence_3 ((Spi_SequenceType)6U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiSequence_SpiSequence_6 ((Spi_SequenceType)7U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiSequence_SpiSequence_CddIgbtDrv_RdConf ((Spi_SequenceType)8U)
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiSequence_SpiSequence_CddIgbtDrv_RdConf2 ((Spi_SequenceType)9U)


/*
              Container : SpiHardwareConfiguration
*/

/*
Configuration Options:
Spi HW Units supported. This parameter is used internally
by the other configurations. The user should not alter this.
*/
#define SPI_0 ((uint8)0U)
#define SPI_1 ((uint8)1U)
#define SPI_2 ((uint8)2U)
#define SPI_3 ((uint8)3U)
#define SPI_4 ((uint8)4U)
#define SPI_5 ((uint8)5U)

#define SPI_QSPI_CHANNEL0 ((uint8)0U)
#define SPI_QSPI_CHANNEL1 ((uint8)1U)
#define SPI_QSPI_CHANNEL2 ((uint8)2U)
#define SPI_QSPI_CHANNEL3 ((uint8)3U)
#define SPI_QSPI_CHANNEL4 ((uint8)4U)
#define SPI_QSPI_CHANNEL5 ((uint8)5U)
#define SPI_QSPI_CHANNEL6 ((uint8)6U)
#define SPI_QSPI_CHANNEL7 ((uint8)7U)
#define SPI_QSPI_CHANNEL8 ((uint8)8U)
#define SPI_QSPI_CHANNEL9 ((uint8)9U)
#define SPI_QSPI_CHANNEL10 ((uint8)10U)
#define SPI_QSPI_CHANNEL11 ((uint8)11U)
#define SPI_QSPI_CHANNEL12 ((uint8)12U)
#define SPI_QSPI_CHANNEL13 ((uint8)13U)
#define SPI_QSPI_CHANNEL14 ((uint8)14U)
#define SPI_QSPI_CHANNEL15 ((uint8)15U)

/*
Configuration Options:
configuration options to check whether HW modules QSPIx are configured
*/
#define SPI_0_NOT_CONFIGURED   (255U)
#define SPI_1_NOT_CONFIGURED   (255U)
#define SPI_2_NOT_CONFIGURED   (255U)
#define SPI_3_NOT_CONFIGURED   (255U)
#define SPI_4_NOT_CONFIGURED   (255U)
#define SPI_5_NOT_CONFIGURED   (255U)
/*
Configuration Options:
QSPI Module Sleep Settings
*/
/* SPI Module is enabled.Module Does not enter Sleep Mode upon Sleep Request.*/
#define SPI_CLK_SLEEP_DISABLE   (0x00000008U)

/* SPI Module is Enabled.Module Enters Sleep Mode upon Sleep Request.*/
#define SPI_CLK_SLEEP_ENABLE    (0x00000000U)

/*
Master receive pin input selection
MRSTxA : 0
MRSTxB : 1
*/
#define SPI_QSPI0_MRIS_SEL (0U)
#define SPI_QSPI1_MRIS_SEL (1U)
#define SPI_QSPI2_MRIS_SEL (0U)
#define SPI_QSPI3_MRIS_SEL (4U)


/*
Configuration: SPI_QSPI0_USED
- if STD_ON, QSPI0 is used
- if STD_OFF,QSPI0 is not used
*/
#define SPI_QSPI0_USED  (STD_ON)
/* Index For QSPI0 Module */
#define SPI_QSPI0_INDEX (0U)

/*
Configuration: SPI_QSPI1_USED
- if STD_ON, QSPI1 is used
- if STD_OFF,QSPI1 is not used
*/
#define SPI_QSPI1_USED (STD_ON)
/* Index For QSPI1 Module */
#define SPI_QSPI1_INDEX (1U)

/*
Configuration: SPI_QSPI2_USED
- if STD_ON, QSPI2 is used
- if STD_OFF,QSPI2 is not used
*/
#define SPI_QSPI2_USED (STD_ON)
/* Index For QSPI2 Module */
#define SPI_QSPI2_INDEX (2U)

/*
Configuration: SPI_QSPI3_USED
- if STD_ON, QSPI3 is used
- if STD_OFF,QSPI3 is not used
*/
#define SPI_QSPI3_USED (STD_ON)
/* Index For QSPI3 Module */
#define SPI_QSPI3_INDEX (3U)

/*
Configuration: SPI_QSPI4_USED
- if STD_ON, QSPI4 is used
- if STD_OFF,QSPI4 is not used
*/
#define SPI_QSPI4_USED (STD_OFF)

/*
Configuration: SPI_QSPI5_USED
- if STD_ON, QSPI5 is used
- if STD_OFF,QSPI5 is not used
*/
#define SPI_QSPI5_USED (STD_OFF)






/* SPI Master Used Modules */
#define SPI_MASTER_MODULES_USED      (0x000fU)


/*
Configuration: SPI_SEQUENCE_QM_ARRAY_INDEX
This is the array index valve to define the total number of non-safety
sequences configured to be used in Spi_SeqStatus, SpiSeqCancel variables.
*/
#define SPI_SEQUENCE_QM_ARRAY_INDEX (1U)

/*
Configuration: SPI_JOB_QM_ARRAY_INDEX
This is the array index valve to define the total number of non-safety jobs
configured to be used in Spi_JobResult variables.
*/
#define SPI_JOB_QM_ARRAY_INDEX (3U)

#define SPI_ASYNC_MODE_LEVEL1 (SPI_ASYNC_MODE_POLLING)

/* Switch to Enable Check of DMA ADDRESS Alignment in case of EB Buffers */
#define SPI_DMA_ADDR_SIZE_ALIGN_CHECK  (STD_OFF)

/* Switch to globally enable / disable Seq end notification */
#define SPI_SEQ_END_NOTIF_REQ   (STD_ON)
/* Switch to globally enable / disable Job end notification */
#define SPI_JOB_END_NOTIF_REQ   (STD_OFF)

/*
 Number of HW SPI Modules:
*/
/*SPI108: The LEVEL 2 SPI Handler/Driver is specified for microcontrollers
that have to provide, at least, two SPI busses using separated hardware units.
Otherwise,using this level of functionality makes no sense.*/
#define SPI_MAX_HW_UNIT   (4U)

#define SPI_DMA_ADDRESS_ACCESS   (STD_ON)

#define SYNC_BUS (0U)
#define ASYNC_BUS (1U)


/* QSPI HW Type */
#define SPI_QSPI0_HWTYPE  (SYNC_BUS)
#define SPI_QSPI1_HWTYPE  (SYNC_BUS)
#define SPI_QSPI2_HWTYPE  (ASYNC_BUS)
#define SPI_QSPI3_HWTYPE  (SYNC_BUS)


/* SPI ASYNC Modules */
#define SPI_ASYNC_MODULES   (0x0004U)

#define SPI_ASIL_MASTER_ASYNC_USED (STD_OFF)

/* Time-out counter for infinite loops */
#define SPI_LOOPCNTR_MAX (0xFFFFFFFEU)

/* Debug switch */
#define IFX_SPI_DEBUG_TX  (STD_OFF)

#define IFX_SPI_DEBUG_ERR (STD_OFF)

#define IFX_SPI_DEBUG_RST (STD_OFF)

#define IFX_SPI_DEBUG_CLC (STD_OFF)


/* SPI Number of QM Async masters configured */
#define SPI_NUM_QM_ASYNC_MASTERS    (1U)

/* Module Debug Support */
#define SPI_DEBUG_SUPPORT  (STD_OFF)

/* SpiAsyncParallelTransmit Support */
#define SPI_ASYNC_PARALLEL_TRANSMIT  (STD_OFF)

/* SpiBaudrateConfigAtRuntime Support */
#define SPI_BAUDRATE_AT_RUNTIME      (STD_OFF)

/* SpiResetSfrAtInit Support */
#define SPI_RESET_SFR_INIT           (STD_ON)

/* Timeout count for kernel reset */
/* Kernel reset @160MHz CPU0, takes at most 59 cycles
   hence, one instance of loop takes 59 cycles(with succesful reset).
   loop counter 0x100 is sufficient for reset to happen at max clock of 300 */
#define SPI_KERNEL_RESET_WAIT_COUNT  (0x00000100U)

/*
  Transmit and Receive Dma Channel IRQ Priorities.
*/
#define IRQ_QSPI2_DMA_TX_OR_ERR_PRIO (IRQ_DMA_CHANNEL31_SR_PRIO)
#define IRQ_QSPI2_DMA_RX_OR_ERR_PRIO (IRQ_DMA_CHANNEL30_SR_PRIO)
/*
  Transmit and Receive Dma Channel IRQ CAT.
*/
#define IRQ_QSPI2_DMA_TX_OR_ERR_CAT (IRQ_DMA_CHANNEL31_SR_CAT)
#define IRQ_QSPI2_DMA_RX_OR_ERR_CAT (IRQ_DMA_CHANNEL30_SR_CAT)

/* Dem reporting  macros */
#define DEM_REPORT_DISABLED (0U)
#define DEM_REPORT_ENABLED (1U)

#define SPI_DMA_ERROR_DEM_REPORT    (DISABLE_DEM_REPORT)

#define SPI_HW_ERROR_DEM_REPORT    (DISABLE_DEM_REPORT)

/*
Function Like Macro:Spi_DataConfig
Data Width, Data Order
*/
/*IFX_MISRA_RULE_19_07_STATUS=Function like macros used in generated cfg files
                                            in order to minimise the runtime */
#define Spi_DataConfig(DataWidth,Heading) ((uint16)(((DataWidth) - (1U))\
                                                |(((uint32)(Heading)) << (8U))))

/*
Function Like Macro:Spi_ShiftClkConfig
Configuration of Shift Clock according to Register setting:
Clock Polarity and Clock Phase/Data Shift Edge
*/
/*IFX_MISRA_RULE_19_07_STATUS=Function like macros used in generated cfg files
                                            in order to minimise the runtime */
#define Spi_ShiftClkConfig(ClkPolarity,DataShiftEdge) ((uint8)\
((uint8) ( ((uint8)(ClkPolarity)) << (1U)) | ((uint8)(DataShiftEdge)) ))

/*
Function Like Macro: Spi_BaudRateParams
Spi baud rate parameters GLOBALCON.TQ, ECON.Q, A, B, C
bit 0-7: TQ
bit 8-13 : Q
bit 16-17 : A
bit 18-19 : B
bit 20-21 : C
*/
/*IFX_MISRA_RULE_19_07_STATUS=Function like macros used in generated cfg files
                                            in order to minimise the runtime */
#define Spi_BaudRateParams(TQ, Q, A, B, C) ((uint32)((((uint32)(TQ)) )|  \
                        (((uint32)(Q)) << ( 8U))| (((uint32)(A)) << (16U))| \
                        (((uint32)(B)) << (18U))| (((uint32)(C)) << (20U))))

/*
Function Like Macro: Spi_BaudRateECON
EcoN register config values
Q [5:0]
A [7:6]
B [9:8]
C [11:10]
CPH 12
CPOL 13
PAREN 14
*/
/*IFX_MISRA_RULE_19_07_STATUS=Function like macros used in generated cfg files
                                            in order to minimise the runtime */
#define Spi_BaudRateECON(Q, A, B, C, CPH, CPOL, PAREN) ((uint32)((((uint32)(Q)) )|  \
                        (((uint32)(A)) << (6U))| (((uint32)(B)) << (8U))| \
                        (((uint32)(C)) << (10U))| (((uint32)(CPH)) << (12U)) | \
                        (((uint32)(CPOL)) << (13U))| (((uint32)(PAREN)) << (14U))))

/*
Function Like Macro: Spi_CsGpioPortPin
Bit 0 - 3 : Pin no
Bit 4 - 9 : Port no
*/
/*IFX_MISRA_RULE_19_07_STATUS=Function like macros used in generated cfg files
                                            in order to minimise the runtime */
#define Spi_CsGpioPortPin(Port,Pin)                                       \
        ((uint16)((uint16)(((uint16)(Port)) << (4U)) | (((uint16)(Pin)))))

/*
Function Like Macro: Spi_DelayParams
Spi delay parameters according to register setting (BACON)
   bit 0 : Reserved
   bit 1-3: IPRE
   bit 4-6: IDLE
   bit 7-9: LPRE
   bit 10-12: LEAD
   bit 13-15: TPRE
   bit 16-18: TRAIL
   bit 19-31: Reserved

*/
/*IFX_MISRA_RULE_19_07_STATUS=Function like macros used in generated cfg files
                                            in order to minimise the runtime */
#define Spi_DelayParams(IPRE,IDLE,LPRE,LEAD,TPRE,TRAIL) \
((uint32)(\
(((uint32)(IPRE) & (0x7U)) << ( 1U)) | (((uint32)(IDLE)  & (0x7U)) << ( 4U))| \
(((uint32)(LPRE) & (0x7U)) << ( 7U)) | (((uint32)(LEAD)  & (0x7U)) << (10U))| \
(((uint32)(TPRE) & (0x7U)) << (13U)) | (((uint32)(TRAIL) & (0x7U)) << (16U))  \
))

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
**                      Global Inline Function Definitions                    **
*******************************************************************************/
#endif  /* SPI_CFG_H */

