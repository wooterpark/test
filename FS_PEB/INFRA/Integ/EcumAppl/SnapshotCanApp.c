/*
 * SnapshotCanApp.c
 *
 *  Created on: 2020Äê3ÔÂ24ÈÕ
 *      Author: fujian
 */
#include "SnapshotCanApp.h"
#include "Snapshot_Can.h"
#include "Snapshot_Can_PBCfg.h"
#include "Snapshot_Ram_PBCfg.h"

void SnapshotCanApp_Init()
{
	SnapshotRam_Init(&SnapshotRam_DefConfigType_S);
    SnapshotCan_Init(&SnapshotCan_DefConfigType_S);
}
