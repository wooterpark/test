/*
 * SnapshotFlsApp.c
 *
 *  Created on: 2020��3��24��
 *      Author: fujian
 */
#include "SnapshotFlsApp.h"
#include "Snapshot_DFls.h"
#include "Snapshot_DFlsUpdate_PBCfg.h"

void SnapshotFlsApp_Init()
{
    Snapshot_DFls_DisableEccTrap();
    SnapshotDu_Init(&SnapshotDu_DefCfgType_S);
}
