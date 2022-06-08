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

#ifndef DEM_CFG_NODEID_H
#define DEM_CFG_NODEID_H

#define DEM_NODEID_INVALID             0
#define DEM_NODEID_COUNT               14u
#define DEM_NODEID_ARRAYLENGTH         (DEM_NODEID_COUNT+1u)

#define DemConf_DemNode_DemComponent_BusOff 1
#define DemConf_DemNode_DemComponent_BusOff1 2
#define DemConf_DemNode_DemComponent_BusOff2 3
#define DemConf_DemNode_DemComponent_MCAL_Status 4
#define DemConf_DemNode_DemComponent_MCU_Status 5
#define DemConf_DemNode_DemComponent_MPDU_CommStatus 6
#define DemConf_DemNode_DemComponent_NvM_ReadErr 7
#define DemConf_DemNode_DemComponent_NvM_WriteErr 8
#define DemConf_DemNode_DemComponent_SEN_1_CommStatus 9
#define DemConf_DemNode_DemComponent_SEN_CommStatus 10
#define DemConf_DemNode_DemComponent_VCU_DC01_AliveCounter 11
#define DemConf_DemNode_DemComponent_VCU_DC01_CheckSum 12
#define DemConf_DemNode_DemComponent_VCU_DC01_DLC 13
#define DemConf_DemNode_DemComponent_VCU_DC01_Tiout 14

#if (DEM_NODEID_ARRAYLENGTH > 255)
#error Number of specified nodes exceeds supported limit of 255.
#endif

#endif

