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

#ifndef DEM_CFG_NODES_H
#define DEM_CFG_NODES_H

/* ---------------------------------------- */
/* DEM_CFG_DEPDEGRADATIONREASONRECOVERABLE  */
/* ---------------------------------------- */
#define DEM_CFG_DEPDEGRADATIONREASONRECOVERABLE_OFF  STD_OFF
#define DEM_CFG_DEPDEGRADATIONREASONRECOVERABLE_ON   STD_ON
#define DEM_CFG_DEPDEGRADATIONREASONRECOVERABLE  DEM_CFG_DEPDEGRADATIONREASONRECOVERABLE_OFF

/* ---------------------------------------- */
/* DEM_CFG_DEPRECOVERYLIMIT                 */
/* ---------------------------------------- */
#define DEM_CFG_DEPRECOVERYLIMIT_OFF  STD_OFF
#define DEM_CFG_DEPRECOVERYLIMIT_ON   STD_ON
#define DEM_CFG_DEPRECOVERYLIMIT  DEM_CFG_DEPRECOVERYLIMIT_OFF

#define DEM_CFG_DEPENDENCY_PENDING_ON             FALSE

#define DEM_CFG_FAILUREDEPENDENCY_RECHECK_LIMIT  80u

/*                  ALLOWEDRECOVERIES             IGNORESPRIO    FAILEDCALLBACK_IDX                       */

#define DEM_CFG_NODEPARAMS \
{ \
    DEM_NODES_INIT (DEM_NODE_INFINITE_RECOVERIES, 0,             0                                       ) \
   ,DEM_NODES_INIT (5,                            1,             DEM_CFG_Rte_Call_Dem_CBStatusComp_DemComponent_BusOff_ComponentStatusChanged_IDX) \
   ,DEM_NODES_INIT (5,                            1,             DEM_CFG_Rte_Call_Dem_CBStatusComp_DemComponent_BusOff1_ComponentStatusChanged_IDX) \
   ,DEM_NODES_INIT (5,                            1,             DEM_CFG_Rte_Call_Dem_CBStatusComp_DemComponent_BusOff2_ComponentStatusChanged_IDX) \
   ,DEM_NODES_INIT (5,                            1,             DEM_CFG_Rte_Call_Dem_CBStatusComp_DemComponent_MCAL_Status_ComponentStatusChanged_IDX) \
   ,DEM_NODES_INIT (5,                            1,             DEM_CFG_Rte_Call_Dem_CBStatusComp_DemComponent_MCU_Status_ComponentStatusChanged_IDX) \
   ,DEM_NODES_INIT (5,                            1,             DEM_CFG_Rte_Call_Dem_CBStatusComp_DemComponent_MPDU_CommStatus_ComponentStatusChanged_IDX) \
   ,DEM_NODES_INIT (5,                            1,             DEM_CFG_Rte_Call_Dem_CBStatusComp_DemComponent_NvM_ReadErr_ComponentStatusChanged_IDX) \
   ,DEM_NODES_INIT (5,                            1,             DEM_CFG_Rte_Call_Dem_CBStatusComp_DemComponent_NvM_WriteErr_ComponentStatusChanged_IDX) \
   ,DEM_NODES_INIT (5,                            1,             DEM_CFG_Rte_Call_Dem_CBStatusComp_DemComponent_SEN_1_CommStatus_ComponentStatusChanged_IDX) \
   ,DEM_NODES_INIT (5,                            1,             DEM_CFG_Rte_Call_Dem_CBStatusComp_DemComponent_SEN_CommStatus_ComponentStatusChanged_IDX) \
   ,DEM_NODES_INIT (5,                            1,             DEM_CFG_Rte_Call_Dem_CBStatusComp_DemComponent_VCU_DC01_AliveCounter_ComponentStatusChanged_IDX) \
   ,DEM_NODES_INIT (5,                            1,             DEM_CFG_Rte_Call_Dem_CBStatusComp_DemComponent_VCU_DC01_CheckSum_ComponentStatusChanged_IDX) \
   ,DEM_NODES_INIT (5,                            1,             DEM_CFG_Rte_Call_Dem_CBStatusComp_DemComponent_VCU_DC01_DLC_ComponentStatusChanged_IDX) \
   ,DEM_NODES_INIT (5,                            1,             DEM_CFG_Rte_Call_Dem_CBStatusComp_DemComponent_VCU_DC01_Tiout_ComponentStatusChanged_IDX) \
}

#define  DEM_CFG_Rte_Call_Dem_CBStatusComp_DemComponent_SEN_CommStatus_ComponentStatusChanged_IDX    1
#define  DEM_CFG_Rte_Call_Dem_CBStatusComp_DemComponent_MPDU_CommStatus_ComponentStatusChanged_IDX    2
#define  DEM_CFG_Rte_Call_Dem_CBStatusComp_DemComponent_SEN_1_CommStatus_ComponentStatusChanged_IDX    3
#define  DEM_CFG_Rte_Call_Dem_CBStatusComp_DemComponent_MCAL_Status_ComponentStatusChanged_IDX    4
#define  DEM_CFG_Rte_Call_Dem_CBStatusComp_DemComponent_MCU_Status_ComponentStatusChanged_IDX    5
#define  DEM_CFG_Rte_Call_Dem_CBStatusComp_DemComponent_BusOff_ComponentStatusChanged_IDX    6
#define  DEM_CFG_Rte_Call_Dem_CBStatusComp_DemComponent_BusOff1_ComponentStatusChanged_IDX    7
#define  DEM_CFG_Rte_Call_Dem_CBStatusComp_DemComponent_BusOff2_ComponentStatusChanged_IDX    8
#define  DEM_CFG_Rte_Call_Dem_CBStatusComp_DemComponent_VCU_DC01_Tiout_ComponentStatusChanged_IDX    9
#define  DEM_CFG_Rte_Call_Dem_CBStatusComp_DemComponent_VCU_DC01_CheckSum_ComponentStatusChanged_IDX    10
#define  DEM_CFG_Rte_Call_Dem_CBStatusComp_DemComponent_VCU_DC01_AliveCounter_ComponentStatusChanged_IDX    11
#define  DEM_CFG_Rte_Call_Dem_CBStatusComp_DemComponent_VCU_DC01_DLC_ComponentStatusChanged_IDX    12
#define  DEM_CFG_Rte_Call_Dem_CBStatusComp_DemComponent_NvM_ReadErr_ComponentStatusChanged_IDX    13
#define  DEM_CFG_Rte_Call_Dem_CBStatusComp_DemComponent_NvM_WriteErr_ComponentStatusChanged_IDX    14

#define  DEM_CFG_NODEFAILEDCALLBACK_COUNT  14
#define  DEM_CFG_NODEFAILEDCALLBACK_ARRAYLENGTH  (DEM_CFG_NODEFAILEDCALLBACK_COUNT+1)

#define DEM_CFG_NODEFAILEDCALLBACKS \
{ \
	NULL_PTR \
    ,&Rte_Call_Dem_CBStatusComp_DemComponent_SEN_CommStatus_ComponentStatusChanged \
    ,&Rte_Call_Dem_CBStatusComp_DemComponent_MPDU_CommStatus_ComponentStatusChanged \
    ,&Rte_Call_Dem_CBStatusComp_DemComponent_SEN_1_CommStatus_ComponentStatusChanged \
    ,&Rte_Call_Dem_CBStatusComp_DemComponent_MCAL_Status_ComponentStatusChanged \
    ,&Rte_Call_Dem_CBStatusComp_DemComponent_MCU_Status_ComponentStatusChanged \
    ,&Rte_Call_Dem_CBStatusComp_DemComponent_BusOff_ComponentStatusChanged \
    ,&Rte_Call_Dem_CBStatusComp_DemComponent_BusOff1_ComponentStatusChanged \
    ,&Rte_Call_Dem_CBStatusComp_DemComponent_BusOff2_ComponentStatusChanged \
    ,&Rte_Call_Dem_CBStatusComp_DemComponent_VCU_DC01_Tiout_ComponentStatusChanged \
    ,&Rte_Call_Dem_CBStatusComp_DemComponent_VCU_DC01_CheckSum_ComponentStatusChanged \
    ,&Rte_Call_Dem_CBStatusComp_DemComponent_VCU_DC01_AliveCounter_ComponentStatusChanged \
    ,&Rte_Call_Dem_CBStatusComp_DemComponent_VCU_DC01_DLC_ComponentStatusChanged \
    ,&Rte_Call_Dem_CBStatusComp_DemComponent_NvM_ReadErr_ComponentStatusChanged \
    ,&Rte_Call_Dem_CBStatusComp_DemComponent_NvM_WriteErr_ComponentStatusChanged \
}

#endif

