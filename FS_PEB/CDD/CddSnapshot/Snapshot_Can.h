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
* $Name______: Snapshot_Can.h$
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
#ifndef _SNAPSHOT_CAN_H_
#define _SNAPSHOT_CAN_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "Std_Types.h"
extern void BswM_RequestMode(uint16 User,uint16 mode);

typedef struct
{
    uint8 *SduDataPtr;
    uint32 SduLength;
} SnapshotCan_PduInfo_S;

typedef struct
{
    uint8 PaddingValue;
} SnapshotCan_RxFlsConfig_S;

typedef struct
{
    uint8 PaddingValue;
    SnapshotCan_PduInfo_S DtcIdBufferInfo[4];
    SnapshotCan_PduInfo_S DtcDataBufferInfo[8];
} SnapshotCan_TxFlsConfig_S;

typedef struct
{
    uint8 FuncId;
    uint8 SubFuncId;
    uint8 InfoBuffer[8U];
} SnapshotCan_RxRamInfo_S;

typedef struct
{
    uint8 TxFlag;
    uint16 TxCnt;
} SnapshotCan_TxCom_S;

typedef struct
{
    uint32 CompletedInfoLen;
    uint8 SN;
    uint8 InfoBuffer[8U];
    SnapshotCan_TxCom_S TxCom;
} SnapshotCan_TxRamInfo_S;

typedef struct
{
    float32 OffsetValue;
    boolean OffsetFlag;
} SnapshotCan_OffsetRamInfo_S;

typedef struct
{
    SnapshotCan_RxFlsConfig_S RxFlsCfg;
    SnapshotCan_TxFlsConfig_S TxFlsCfg;
    SnapshotCan_RxRamInfo_S *RxRamInfoPtr;
    SnapshotCan_TxRamInfo_S *TxRamInfoPtr;
    SnapshotCan_OffsetRamInfo_S *OffsetRamInfoPtr;
} SnapshotCan_ConfigType_S;

/*******************************************************************************
** Function Name	: SnapshotCan_TransmitDisable
** Parameter[in] 	: (1)SnapshotCan_TxCom_S pointer
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	:
*******************************************************************************/
extern void SnapshotCan_TransmitDisable(SnapshotCan_TxCom_S * txComPtr);

/*******************************************************************************
** Function Name : SnapshotCan_MainFunction
** Parameter[in] : None
** Parameter[out]: None
** Return Value  : None
** Note          :
** Description   :
*******************************************************************************/
extern void SnapshotCan_MainFunction(void);

/*******************************************************************************
** Function Name : SnapshotCan_Init
** Parameter[in] : (1)const SnapshotCan_ConfigType_S *
** Parameter[out]: None
** Return Value  : (1)E_OK: Init successfully
** Note          :
** Description   :
*******************************************************************************/
extern Std_ReturnType SnapshotCan_Init(const SnapshotCan_ConfigType_S *mCfgPtr);

#ifdef __cplusplus
}
#endif

#endif
