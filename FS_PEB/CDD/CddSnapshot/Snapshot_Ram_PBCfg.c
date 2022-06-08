/*******************************************************************************
**----------------------------------------------------------------------------**
** Copyright (c) 2018 by JEE.       All rights reserved.
** This software is copyright protected and proprietary to JEE.
** JEE grants to you only those rights as set out in the license conditions.
** All other rights remain with JEE.
**----------------------------------------------------------------------------**
**
* Administrative Information
* $Namespace_: \xx\xx$
* $Class_____: C$
* $Name______: Snapshot_Ram_PBCfg.c$
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
Version generation time: 2020-06-23 14:12:04, By Rory.Li
*******************************************************************************/

#include "Snapshot_Ram_PBCfg.h"

SnapshotRam_RamInfo_S SnapshotRam_DefRamInfo_S __attribute__ ((asection(".data.CPU2_unspec","f=aw"))) =
{
    {
        0U,
        {0U},
        SNAPSHOT_RAM_F_VAR_BUFFER_HALF_SIZE,
        SNAPSHOT_RAM_BEFORE_FAULT
    },
    {
        0U,
        {0U},
        SNAPSHOT_RAM_S_VAR_BUFFER_HALF_SIZE,
        SNAPSHOT_RAM_BEFORE_FAULT
    }
};

const SnapshotRam_ConfigType_S SnapshotRam_DefConfigType_S =
{
    &SnapshotRam_DefRamInfo_S,
    {1.0F, 0.0F},
    {1.0F, 0.0F},
    {1.0F, 0.0F},
    {1.0F, 0.0F},
    {10.0F, 0.0F},

    {1.0F, 0.0F},
    {1.0F, 0.0F},
    {1.0F, 0.0F},
    {1.0F, 0.0F},
    {1.0F, 0.0F}
};


