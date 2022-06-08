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

#ifndef DEM_CFG_NVM_H
#define DEM_CFG_NVM_H

#define  DEM_NVM_ID_DEM_GENERIC_NV_DATA           0u
#define  DEM_NVM_ID_EVMEM_LOC_0                   1u
#define  DEM_NVM_ID_EVMEM_LOC_1                   2u
#define  DEM_NVM_ID_EVMEM_LOC_10                  3u
#define  DEM_NVM_ID_EVMEM_LOC_11                  4u
#define  DEM_NVM_ID_EVMEM_LOC_12                  5u
#define  DEM_NVM_ID_EVMEM_LOC_13                  6u
#define  DEM_NVM_ID_EVMEM_LOC_14                  7u
#define  DEM_NVM_ID_EVMEM_LOC_15                  8u
#define  DEM_NVM_ID_EVMEM_LOC_16                  9u
#define  DEM_NVM_ID_EVMEM_LOC_17                  10u
#define  DEM_NVM_ID_EVMEM_LOC_18                  11u
#define  DEM_NVM_ID_EVMEM_LOC_19                  12u
#define  DEM_NVM_ID_EVMEM_LOC_2                   13u
#define  DEM_NVM_ID_EVMEM_LOC_3                   14u
#define  DEM_NVM_ID_EVMEM_LOC_4                   15u
#define  DEM_NVM_ID_EVMEM_LOC_5                   16u
#define  DEM_NVM_ID_EVMEM_LOC_6                   17u
#define  DEM_NVM_ID_EVMEM_LOC_7                   18u
#define  DEM_NVM_ID_EVMEM_LOC_8                   19u
#define  DEM_NVM_ID_EVMEM_LOC_9                   20u
#define  DEM_NVM_ID_EVT_STATUSBYTE                21u

#define  DEM_NVM_CFG_BLOCKID_TYPE                 uint8
#define  DEM_NVM_CFG_NUM_BLOCKS_TOTAL             22
#define  DEM_NVM_CFG_NUM_BLOCKS_EXTENDED          21

#define  DEM_NVM_CFG_NVM_BLOCK_IDS                \
{\
    NvMConf_NvMBlockDescriptor_Dem_GenericNvData,\
    NvMConf_NvMBlockDescriptor_Dem_EvMemEventMemory0,\
    NvMConf_NvMBlockDescriptor_Dem_EvMemEventMemory1,\
    NvMConf_NvMBlockDescriptor_Dem_EvMemEventMemory10,\
    NvMConf_NvMBlockDescriptor_Dem_EvMemEventMemory11,\
    NvMConf_NvMBlockDescriptor_Dem_EvMemEventMemory12,\
    NvMConf_NvMBlockDescriptor_Dem_EvMemEventMemory13,\
    NvMConf_NvMBlockDescriptor_Dem_EvMemEventMemory14,\
    NvMConf_NvMBlockDescriptor_Dem_EvMemEventMemory15,\
    NvMConf_NvMBlockDescriptor_Dem_EvMemEventMemory16,\
    NvMConf_NvMBlockDescriptor_Dem_EvMemEventMemory17,\
    NvMConf_NvMBlockDescriptor_Dem_EvMemEventMemory18,\
    NvMConf_NvMBlockDescriptor_Dem_EvMemEventMemory19,\
    NvMConf_NvMBlockDescriptor_Dem_EvMemEventMemory2,\
    NvMConf_NvMBlockDescriptor_Dem_EvMemEventMemory3,\
    NvMConf_NvMBlockDescriptor_Dem_EvMemEventMemory4,\
    NvMConf_NvMBlockDescriptor_Dem_EvMemEventMemory5,\
    NvMConf_NvMBlockDescriptor_Dem_EvMemEventMemory6,\
    NvMConf_NvMBlockDescriptor_Dem_EvMemEventMemory7,\
    NvMConf_NvMBlockDescriptor_Dem_EvMemEventMemory8,\
    NvMConf_NvMBlockDescriptor_Dem_EvMemEventMemory9,\
    NvMConf_NvMBlockDescriptor_Dem_AllEventsStatusByte\
}

#define  DEM_NVM_CFG_BLOCKS_EXTENDED              \
{\
    {&Dem_GenericNvData, DEM_SIZEOF_VAR(Dem_GenericNvData), DEM_CFG_COPY_FCT_ID_MEMCOPY},\
    {&Dem_EvMemEventMemory[0], DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType), DEM_CFG_COPY_FCT_ID_MEMCOPY},\
    {&Dem_EvMemEventMemory[1], DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType), DEM_CFG_COPY_FCT_ID_MEMCOPY},\
    {&Dem_EvMemEventMemory[10], DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType), DEM_CFG_COPY_FCT_ID_MEMCOPY},\
    {&Dem_EvMemEventMemory[11], DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType), DEM_CFG_COPY_FCT_ID_MEMCOPY},\
    {&Dem_EvMemEventMemory[12], DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType), DEM_CFG_COPY_FCT_ID_MEMCOPY},\
    {&Dem_EvMemEventMemory[13], DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType), DEM_CFG_COPY_FCT_ID_MEMCOPY},\
    {&Dem_EvMemEventMemory[14], DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType), DEM_CFG_COPY_FCT_ID_MEMCOPY},\
    {&Dem_EvMemEventMemory[15], DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType), DEM_CFG_COPY_FCT_ID_MEMCOPY},\
    {&Dem_EvMemEventMemory[16], DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType), DEM_CFG_COPY_FCT_ID_MEMCOPY},\
    {&Dem_EvMemEventMemory[17], DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType), DEM_CFG_COPY_FCT_ID_MEMCOPY},\
    {&Dem_EvMemEventMemory[18], DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType), DEM_CFG_COPY_FCT_ID_MEMCOPY},\
    {&Dem_EvMemEventMemory[19], DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType), DEM_CFG_COPY_FCT_ID_MEMCOPY},\
    {&Dem_EvMemEventMemory[2], DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType), DEM_CFG_COPY_FCT_ID_MEMCOPY},\
    {&Dem_EvMemEventMemory[3], DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType), DEM_CFG_COPY_FCT_ID_MEMCOPY},\
    {&Dem_EvMemEventMemory[4], DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType), DEM_CFG_COPY_FCT_ID_MEMCOPY},\
    {&Dem_EvMemEventMemory[5], DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType), DEM_CFG_COPY_FCT_ID_MEMCOPY},\
    {&Dem_EvMemEventMemory[6], DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType), DEM_CFG_COPY_FCT_ID_MEMCOPY},\
    {&Dem_EvMemEventMemory[7], DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType), DEM_CFG_COPY_FCT_ID_MEMCOPY},\
    {&Dem_EvMemEventMemory[8], DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType), DEM_CFG_COPY_FCT_ID_MEMCOPY},\
    {&Dem_EvMemEventMemory[9], DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType), DEM_CFG_COPY_FCT_ID_MEMCOPY}\
}

#define  DEM_NVM_CFG_NUM_STORAGEBUFFER            2

/* 2 block types supported: normal Dem and Bfm Record */
#define DEM_CFG_COPY_FCT_ID_MEMCOPY           0   /* normal mem copy*/

#define DEM_NVM_CFG_COPYFCT_NUM  1 

#define DEM_NVM_CFG_COPYFCT_INIT  { (&Dem_NvMNormalMemCopy)   }

#endif

