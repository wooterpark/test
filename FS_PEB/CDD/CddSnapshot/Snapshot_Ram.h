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
* $Name______: Snapshot_Ram.h$
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
Version generation time: 2020-04-21 14:12:04, By Rory.Li
*******************************************************************************/

#ifndef SNAPSHOT_RAM_H_
#define SNAPSHOT_RAM_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "Std_Types.h"

extern boolean EventFlag2FR_boolean;

typedef enum
{
    SNAPSHOT_RAM_BEFORE_FAULT = 0,
    SNAPSHOT_RAM_AFTER_FAULT = 1,
    SNAPSHOT_RAM_LOCK_FAULT = 2
} SnapshotRam_Fsm_E;

#define SNAPSHOT_RAM_F_VAR_NUM                       (5U)
#define SNAPSHOT_RAM_F_VAR_BUFFER_SIZE               (2000U)
#define SNAPSHOT_RAM_F_VAR_BUFFER_HALF_SIZE          (1000U)
#define SNAPSHOT_RAM_F_STORED_TOTAL_SIZE             (20002UL)

#define SNAPSHOT_RAM_S_VAR_NUM                       (5U)
#define SNAPSHOT_RAM_S_VAR_BUFFER_SIZE               (2000U)
#define SNAPSHOT_RAM_S_VAR_BUFFER_HALF_SIZE          (1000U)
#define SNAPSHOT_RAM_S_STORED_TOTAL_SIZE             (20002UL)

typedef struct
{
    uint16 BeforeFaultCnt;
    uint16 Buffer[SNAPSHOT_RAM_F_VAR_BUFFER_SIZE][SNAPSHOT_RAM_F_VAR_NUM];
    uint16 AfterFaultCnt;
    SnapshotRam_Fsm_E Fsm;
} SnapshotRam_FastInfo_S;

typedef struct
{
    uint16 BeforeFaultCnt;
    uint16 Buffer[SNAPSHOT_RAM_S_VAR_BUFFER_SIZE][SNAPSHOT_RAM_S_VAR_NUM];
    uint16 AfterFaultCnt;
    SnapshotRam_Fsm_E Fsm;
} SnapshotRam_SlowInfo_S;

typedef struct
{
    SnapshotRam_FastInfo_S FastInfo;
    SnapshotRam_SlowInfo_S SlowInfo;
} SnapshotRam_RamInfo_S;

typedef struct
{
    float32 FastVar0;
    float32 FastVar1;
    float32 FastVar2;
    float32 FastVar3;
    float32 FastVar4;
} SnapshotFastRam_RteInfo_S;

typedef struct
{
    float32 SlowVar0;
    float32 SlowVar1;
    float32 SlowVar2;
    float32 SlowVar3;
    float32 SlowVar4;
} SnapshotSlowRam_RteInfo_S;

typedef struct
{
    float32 k;
    float32 b;
} SnapshotRam_Coeff_S;

typedef struct
{
    SnapshotRam_RamInfo_S *RamInfoPtr;
    SnapshotRam_Coeff_S CFastVar0;
    SnapshotRam_Coeff_S CFastVar1;
    SnapshotRam_Coeff_S CFastVar2;
    SnapshotRam_Coeff_S CFastVar3;
    SnapshotRam_Coeff_S CFastVar4;

    SnapshotRam_Coeff_S CSlowVar0;
    SnapshotRam_Coeff_S CSlowVar1;
    SnapshotRam_Coeff_S CSlowVar2;
    SnapshotRam_Coeff_S CSlowVar3;
    SnapshotRam_Coeff_S CSlowVar4;
} SnapshotRam_ConfigType_S;

/*******************************************************************************
** Function Name : SnapshotRam_UpdateFastInfo
** Parameter[in] : (1)SnapshotRam_RteInfo_S *
** Parameter[out]: None
** Return Value  : None
** Note          :
** Description   : 2020-04-21 14:12:04, By Rory.Li
*******************************************************************************/
extern void SnapshotRam_UpdateFastInfo(const SnapshotFastRam_RteInfo_S *rteInfoPtr);

/*******************************************************************************
** Function Name : SnapshotRam_UpdateSlowInfo
** Parameter[in] : (1)SnapshotRam_RteInfo_S *
** Parameter[out]: None
** Return Value  : None
** Note          :
** Description   : 2020-04-21 14:12:04, By Rory.Li
*******************************************************************************/
extern void SnapshotRam_UpdateSlowInfo(const SnapshotSlowRam_RteInfo_S *rteInfoPtr);

/*******************************************************************************
** Function Name : SnapshotRam_Init
** Parameter[in] : (1)const SnapshotRam_ConfigType_S *
** Parameter[out]: None
** Return Value  : (1)E_OK: Init successfully
** Note          :
** Description   :
*******************************************************************************/
extern Std_ReturnType SnapshotRam_Init(const SnapshotRam_ConfigType_S *mCfgPtr);

#ifdef __cplusplus
}
#endif

#endif
