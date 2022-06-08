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
* $Name______: Snapshot_DFlsUpdate_PBCfg.c$
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

#include "Snapshot_DFlsUpdate_PBCfg.h"

static SnapshotDu_RamInfo_S Prv_DefRamInfo_S __attribute__ ((asection(".data.CPU2_unspec","f=aw"))) =
{
    SNAPSHOT_DU_IDLE,
    (uint8)0,
    0UL,
    0UL
};

const SnapshotDu_ConfigType_S SnapshotDu_DefCfgType_S =
{
    {
        {SNAPSHOT_DU_PBCFG_FAST_ADDR0, SNAPSHOT_DU_PBCFG_SLOW_ADDR0, SNAPSHOT_DU_PBCFG_DTC_ADDR0},
        {SNAPSHOT_DU_PBCFG_FAST_ADDR1, SNAPSHOT_DU_PBCFG_SLOW_ADDR1, SNAPSHOT_DU_PBCFG_DTC_ADDR1},
        {SNAPSHOT_DU_PBCFG_FAST_ADDR2, SNAPSHOT_DU_PBCFG_SLOW_ADDR2, SNAPSHOT_DU_PBCFG_DTC_ADDR2}
    },
    &Prv_DefRamInfo_S
};
