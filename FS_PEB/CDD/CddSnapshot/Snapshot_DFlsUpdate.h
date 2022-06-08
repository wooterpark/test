/*******************************************************************************
**----------------------------------------------------------------------------**
** Copyright (c) 2018 by JEE.        All rights reserved.
** This software is copyright protected and proprietary to JEE.
** JEE grants to you only those rights as set out in the license conditions.
** All other rights remain with JEE.
**----------------------------------------------------------------------------**
**
* Administrative Information
* $Namespace_: \xx\xx$
* $Class_____: C$
* $Name______: Snapshot_DFlsUpdate.h$
* $Variant___: 0.0.0$
* $Revision__: 0$
* $Author____: Rory.Li$
**
**----------------------------------------------------------------------------**
** MAY BE CHANGED BY USER [Yes/No]: No
**----------------------------------------------------------------------------**
** DESCRIPTION: Fault recording code
**----------------------------------------------------------------------------**
** HISTORY:
V1.0.0:   Initial version.

*******************************************************************************/
#ifndef _SNAPSHOT_DFLS_UPDATE_H_
#define _SNAPSHOT_DFLS_UPDATE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "Std_Types.h"
#include "Snapshot_DFls.h"
#include "Snapshot_Ram_PBCfg.h"

#define SNAPSHOT_DU_STORED_NUM                     (3U)
#define SNAPSHOT_DU_SECTOR_NUM                     (18U)
#define SNAPSHOT_DU_ONE_STORED_SECTOR_NUM          (6U)

extern uint8 VAR_DEM_EventList_au8[24];

typedef enum
{
    SNAPSHOT_DU_IDLE = 0,
    SNAPSHOT_DU_ERASE,
    SNAPSHOT_DU_ERASE_BLOCKING,
    SNAPSHOT_DU_FAST,
    SNAPSHOT_DU_SLOW,
    SNAPSHOT_DU_DTC_ID,
    SNAPSHOT_DU_DTC_ID_BLOCKING,
    SNAPSHOT_DU_FINISHED
} SnapshotDu_Fsm_E;

typedef struct
{
    SnapshotDu_Fsm_E WriteFsm;
    uint8 StoredSn;
    uint32 FastWriteCnt;
    uint32 SlowWriteCnt;
} SnapshotDu_RamInfo_S;

typedef struct
{
    uint32 FastAddr;
    uint32 SlowAddr;
    uint32 DtcIdAddr;
} SnapshotDu_StoredInfo_S;

typedef struct
{
    SnapshotDu_StoredInfo_S StoredInfo[SNAPSHOT_DU_STORED_NUM];
    SnapshotDu_RamInfo_S *RamInfoPtr;
} SnapshotDu_ConfigType_S;

/*******************************************************************************
** Function Name : SnapshotDu_MainFunction
** Parameter[in] : None
** Parameter[out]: None
** Return Value  : None
** Note          :
** Description   :
*******************************************************************************/
extern void SnapshotDu_MainFunction(void);

/*******************************************************************************
** Function Name : SnapshotDu_Init
** Parameter[in] : (1)const SnapshotDu_ConfigType_S *
** Parameter[out]: None
** Return Value  : (1)E_OK: Init successfully
** Note          :
** Description   :
*******************************************************************************/
extern Std_ReturnType SnapshotDu_Init(const SnapshotDu_ConfigType_S *mCfgPtr);

extern uint8 SnapshotDu_PageBuffer[SNAPSHOT_DFLS_BURST_PAGE_SIZE];

#ifdef __cplusplus
}
#endif

#endif
