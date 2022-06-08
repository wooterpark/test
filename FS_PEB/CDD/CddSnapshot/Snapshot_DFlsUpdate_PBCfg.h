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
* $Name______: Snapshot_DFlsUpdate_PBCfg.h$
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
#ifndef _SNAPSHOT_DFLS_UPDATE_PBCFG_H_
#define _SNAPSHOT_DFLS_UPDATE_PBCFG_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "Snapshot_DFlsUpdate.h"

#define SNAPSHOT_DU_PBCFG_DTC_ADDR0                  (0xAF03B000UL)
#define SNAPSHOT_DU_PBCFG_DTC_ADDR1                  (0xAF047000UL)
#define SNAPSHOT_DU_PBCFG_DTC_ADDR2                  (0xAF053000UL)

#define SNAPSHOT_DU_PBCFG_FAST_ADDR0                 (0xAF030000UL)
#define SNAPSHOT_DU_PBCFG_SLOW_ADDR0                 (0xAF036000UL)
#define SNAPSHOT_DU_PBCFG_FAST_ADDR1                 (0xAF03C000UL)
#define SNAPSHOT_DU_PBCFG_SLOW_ADDR1                 (0xAF042000UL)
#define SNAPSHOT_DU_PBCFG_FAST_ADDR2                 (0xAF048000UL)
#define SNAPSHOT_DU_PBCFG_SLOW_ADDR2                 (0xAF04E000UL)

#define SNAPSHOT_DU_PBCFG_OFFSET_ADDR                (0xAF05E000UL)
#define SNAPSHOT_DU_PBCFG_OFFSET_FLAG_ADDR           (0xAF05E004UL)
#define SNAPSHOT_DU_PBCFG_OFFSET_DATA_LEN            (4UL)
#define SNAPSHOT_DU_PBCFG_OFFSET_FLAG_LEN            (4UL)

extern const SnapshotDu_ConfigType_S SnapshotDu_DefCfgType_S;

#ifdef __cplusplus
}
#endif

#endif
