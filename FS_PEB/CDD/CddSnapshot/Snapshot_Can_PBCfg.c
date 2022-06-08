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
* $Name______: Snapshot_Can_PBCfg.c$
* $Variant___: 0.0.0$
* $Revision__: 0$
* $Author____: Rory.Li$
**
**----------------------------------------------------------------------------**
** MAY BE CHANGED BY USER [Yes/No]: No
**----------------------------------------------------------------------------**
** DESCRIPTION:
**----------------------------------------------------------------------------**
** HISTORY:
V1.0.0:   Initial version.

*******************************************************************************/

#include "Snapshot_DFlsUpdate_PBCfg.h"
#include "Snapshot_Can_PBCfg.h"
#include "Snapshot_Ram_PBCfg.h"

static SnapshotCan_RxRamInfo_S Prv_DefRxRamInfo_S =
{
    (uint8)0,
    (uint8)0,
    {(uint8)0,(uint8)0,(uint8)0,(uint8)0,(uint8)0,(uint8)0,(uint8)0,(uint8)0}
};

static SnapshotCan_TxRamInfo_S Prv_DefTxRamInfo_S =
{
    0UL,
    (uint8)0,
    {(uint8)0,(uint8)0,(uint8)0,(uint8)0,(uint8)0,(uint8)0,(uint8)0,(uint8)0},
    {
        (uint8)0,
        0U
    }
};

static SnapshotCan_OffsetRamInfo_S Prv_DefOffsetRamInfo_S =
{
    0.0F,
    FALSE
};

const SnapshotCan_ConfigType_S SnapshotCan_DefConfigType_S =
{
    {(uint8)0},
    {
        (uint8)0,
        {
            {(uint8 *)&VAR_DEM_EventList_au8[0], 24UL},
            /* JEE_MISRA_RULE_11_04 It's allowed . */
            {(uint8 *)SNAPSHOT_DU_PBCFG_DTC_ADDR0, 24UL},
            /* JEE_MISRA_RULE_11_04 It's allowed . */
            {(uint8 *)SNAPSHOT_DU_PBCFG_DTC_ADDR1, 24UL},
            /* JEE_MISRA_RULE_11_04 It's allowed . */
            {(uint8 *)SNAPSHOT_DU_PBCFG_DTC_ADDR2, 24UL}
        },
        {
            {(uint8 *)&SnapshotRam_DefRamInfo_S.FastInfo.BeforeFaultCnt, SNAPSHOT_RAM_F_STORED_TOTAL_SIZE},
            {(uint8 *)&SnapshotRam_DefRamInfo_S.SlowInfo.BeforeFaultCnt, SNAPSHOT_RAM_S_STORED_TOTAL_SIZE},
            /* JEE_MISRA_RULE_11_04 It's allowed . */
            {(uint8 *)SNAPSHOT_DU_PBCFG_FAST_ADDR0, SNAPSHOT_RAM_F_STORED_TOTAL_SIZE},
            /* JEE_MISRA_RULE_11_04 It's allowed . */
            {(uint8 *)SNAPSHOT_DU_PBCFG_SLOW_ADDR0, SNAPSHOT_RAM_S_STORED_TOTAL_SIZE},
            /* JEE_MISRA_RULE_11_04 It's allowed . */
            {(uint8 *)SNAPSHOT_DU_PBCFG_FAST_ADDR1, SNAPSHOT_RAM_F_STORED_TOTAL_SIZE},
            /* JEE_MISRA_RULE_11_04 It's allowed . */
            {(uint8 *)SNAPSHOT_DU_PBCFG_SLOW_ADDR1, SNAPSHOT_RAM_S_STORED_TOTAL_SIZE},
            /* JEE_MISRA_RULE_11_04 It's allowed . */
            {(uint8 *)SNAPSHOT_DU_PBCFG_FAST_ADDR2, SNAPSHOT_RAM_F_STORED_TOTAL_SIZE},
            /* JEE_MISRA_RULE_11_04 It's allowed . */
            {(uint8 *)SNAPSHOT_DU_PBCFG_SLOW_ADDR2, SNAPSHOT_RAM_S_STORED_TOTAL_SIZE}
        }
    },
    &Prv_DefRxRamInfo_S,
    &Prv_DefTxRamInfo_S,
    &Prv_DefOffsetRamInfo_S
};
