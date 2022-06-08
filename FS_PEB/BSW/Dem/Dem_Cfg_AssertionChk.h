/*
***********************************************************************************************************************
* 
* Product Info
* Isolar version: ISOLAR-AB 4.0.2
* Product release version: RTA-BSW 3.1.0
* 
***********************************************************************************************************************
*/

/********************************************************************************************************************/
/*                                                                                                                  */
/* TOOL-GENERATED SOURCECODE, DO NOT CHANGE                                                                         */
/*                                                                                                                  */
/********************************************************************************************************************/

#ifndef DEM_CFG_ASSERTIONCHK_H
#define DEM_CFG_ASSERTIONCHK_H

#include "Dem_Lib.h"
#include "Dem_EventStatus.h"
#include "Dem_GenericNvData.h"
#include "Dem_DisturbanceMemory.h"
#include "Dem_Obd.h"

/* -------------------------------------------------- */
/* DEM_CFG_STATIC_ASSERTION_FOR_NVM_BLOCKLENGTH       */
/* -------------------------------------------------- */
#define DEM_CFG_STATIC_ASSERTION_FOR_NVM_BLOCKLENGTH_ON   STD_ON
#define DEM_CFG_STATIC_ASSERTION_FOR_NVM_BLOCKLENGTH_OFF  STD_OFF
#define DEM_CFG_STATIC_ASSERTION_FOR_NVM_BLOCKLENGTH  DEM_CFG_STATIC_ASSERTION_FOR_NVM_BLOCKLENGTH_ON

#if(DEM_CFG_STATIC_ASSERTION_FOR_NVM_BLOCKLENGTH == DEM_CFG_STATIC_ASSERTION_FOR_NVM_BLOCKLENGTH_ON)
/* Macros which defines the block size of each configured NvM Block */
#define  DEM_NVM_ID_DEM_GENERIC_NV_DATA_SIZE                16
#define  DEM_NVM_ID_EVMEM_LOC_0_SIZE                        40
#define  DEM_NVM_ID_EVMEM_LOC_1_SIZE                        40
#define  DEM_NVM_ID_EVMEM_LOC_10_SIZE                       40
#define  DEM_NVM_ID_EVMEM_LOC_11_SIZE                       40
#define  DEM_NVM_ID_EVMEM_LOC_12_SIZE                       40
#define  DEM_NVM_ID_EVMEM_LOC_13_SIZE                       40
#define  DEM_NVM_ID_EVMEM_LOC_14_SIZE                       40
#define  DEM_NVM_ID_EVMEM_LOC_15_SIZE                       40
#define  DEM_NVM_ID_EVMEM_LOC_16_SIZE                       40
#define  DEM_NVM_ID_EVMEM_LOC_17_SIZE                       40
#define  DEM_NVM_ID_EVMEM_LOC_18_SIZE                       40
#define  DEM_NVM_ID_EVMEM_LOC_19_SIZE                       40
#define  DEM_NVM_ID_EVMEM_LOC_2_SIZE                        40
#define  DEM_NVM_ID_EVMEM_LOC_3_SIZE                        40
#define  DEM_NVM_ID_EVMEM_LOC_4_SIZE                        40
#define  DEM_NVM_ID_EVMEM_LOC_5_SIZE                        40
#define  DEM_NVM_ID_EVMEM_LOC_6_SIZE                        40
#define  DEM_NVM_ID_EVMEM_LOC_7_SIZE                        40
#define  DEM_NVM_ID_EVMEM_LOC_8_SIZE                        40
#define  DEM_NVM_ID_EVMEM_LOC_9_SIZE                        40
#define  DEM_NVM_ID_EVT_STATUSBYTE_SIZE                     128

DEM_STATIC_ASSERT((DEM_SIZEOF_VAR(Dem_GenericNvData)==DEM_NVM_ID_DEM_GENERIC_NV_DATA_SIZE),DEM_NVM_ID_DEM_GENERIC_NV_DATA_BlockLengthIsInvalid);
DEM_STATIC_ASSERT((DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)==DEM_NVM_ID_EVMEM_LOC_0_SIZE),DEM_NVM_ID_EVMEM_LOC_0_BlockLengthIsInvalid);
DEM_STATIC_ASSERT((DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)==DEM_NVM_ID_EVMEM_LOC_1_SIZE),DEM_NVM_ID_EVMEM_LOC_1_BlockLengthIsInvalid);
DEM_STATIC_ASSERT((DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)==DEM_NVM_ID_EVMEM_LOC_10_SIZE),DEM_NVM_ID_EVMEM_LOC_10_BlockLengthIsInvalid);
DEM_STATIC_ASSERT((DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)==DEM_NVM_ID_EVMEM_LOC_11_SIZE),DEM_NVM_ID_EVMEM_LOC_11_BlockLengthIsInvalid);
DEM_STATIC_ASSERT((DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)==DEM_NVM_ID_EVMEM_LOC_12_SIZE),DEM_NVM_ID_EVMEM_LOC_12_BlockLengthIsInvalid);
DEM_STATIC_ASSERT((DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)==DEM_NVM_ID_EVMEM_LOC_13_SIZE),DEM_NVM_ID_EVMEM_LOC_13_BlockLengthIsInvalid);
DEM_STATIC_ASSERT((DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)==DEM_NVM_ID_EVMEM_LOC_14_SIZE),DEM_NVM_ID_EVMEM_LOC_14_BlockLengthIsInvalid);
DEM_STATIC_ASSERT((DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)==DEM_NVM_ID_EVMEM_LOC_15_SIZE),DEM_NVM_ID_EVMEM_LOC_15_BlockLengthIsInvalid);
DEM_STATIC_ASSERT((DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)==DEM_NVM_ID_EVMEM_LOC_16_SIZE),DEM_NVM_ID_EVMEM_LOC_16_BlockLengthIsInvalid);
DEM_STATIC_ASSERT((DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)==DEM_NVM_ID_EVMEM_LOC_17_SIZE),DEM_NVM_ID_EVMEM_LOC_17_BlockLengthIsInvalid);
DEM_STATIC_ASSERT((DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)==DEM_NVM_ID_EVMEM_LOC_18_SIZE),DEM_NVM_ID_EVMEM_LOC_18_BlockLengthIsInvalid);
DEM_STATIC_ASSERT((DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)==DEM_NVM_ID_EVMEM_LOC_19_SIZE),DEM_NVM_ID_EVMEM_LOC_19_BlockLengthIsInvalid);
DEM_STATIC_ASSERT((DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)==DEM_NVM_ID_EVMEM_LOC_2_SIZE),DEM_NVM_ID_EVMEM_LOC_2_BlockLengthIsInvalid);
DEM_STATIC_ASSERT((DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)==DEM_NVM_ID_EVMEM_LOC_3_SIZE),DEM_NVM_ID_EVMEM_LOC_3_BlockLengthIsInvalid);
DEM_STATIC_ASSERT((DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)==DEM_NVM_ID_EVMEM_LOC_4_SIZE),DEM_NVM_ID_EVMEM_LOC_4_BlockLengthIsInvalid);
DEM_STATIC_ASSERT((DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)==DEM_NVM_ID_EVMEM_LOC_5_SIZE),DEM_NVM_ID_EVMEM_LOC_5_BlockLengthIsInvalid);
DEM_STATIC_ASSERT((DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)==DEM_NVM_ID_EVMEM_LOC_6_SIZE),DEM_NVM_ID_EVMEM_LOC_6_BlockLengthIsInvalid);
DEM_STATIC_ASSERT((DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)==DEM_NVM_ID_EVMEM_LOC_7_SIZE),DEM_NVM_ID_EVMEM_LOC_7_BlockLengthIsInvalid);
DEM_STATIC_ASSERT((DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)==DEM_NVM_ID_EVMEM_LOC_8_SIZE),DEM_NVM_ID_EVMEM_LOC_8_BlockLengthIsInvalid);
DEM_STATIC_ASSERT((DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)==DEM_NVM_ID_EVMEM_LOC_9_SIZE),DEM_NVM_ID_EVMEM_LOC_9_BlockLengthIsInvalid);
DEM_STATIC_ASSERT((DEM_SIZEOF_VAR(Dem_AllEventsStatusByte)==DEM_NVM_ID_EVT_STATUSBYTE_SIZE),DEM_NVM_ID_EVT_STATUSBYTE_BlockLengthIsInvalid);

#endif

#endif

