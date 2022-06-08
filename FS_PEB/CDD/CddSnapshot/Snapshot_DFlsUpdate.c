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
* $Name______: Snapshot_DFlsUpdate.c$
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

#include "Snapshot_MemFunc.h"
#include "Snapshot_DFlsUpdate.h"
#include "Snapshot_Ram_PBCfg.h"

static const SnapshotDu_ConfigType_S *Prv_CfgTypePtr = NULL;

static uint8 Prv_GetStoredSn(void);
static Std_ReturnType Prv_EraseInfo(uint8 storedSn);
static Std_ReturnType Prv_WriteFastInfo(
                                           SnapshotRam_RamInfo_S *extRamInfoPtr,
                                           SnapshotDu_RamInfo_S *ramInfoPtr
                                       );
static Std_ReturnType Prv_WriteSlowInfo(
                                           SnapshotRam_RamInfo_S *extRamInfoPtr,
                                           SnapshotDu_RamInfo_S *ramInfoPtr
                                       );
static Std_ReturnType Prv_WriteDtcIdInfo(
		                                   const SnapshotDu_RamInfo_S *ramInfoPtr
                                        );
static void Prv_UpdateInfoToFls(
                                   SnapshotRam_RamInfo_S *extRamInfoPtr,
                                   SnapshotDu_RamInfo_S *ramInfoPtr
                               );

uint8 SnapshotDu_PageBuffer[SNAPSHOT_DFLS_BURST_PAGE_SIZE] __attribute__ ((asection(".data.DFLS_UPDATE_BUFFER", "f=aw"))) = {(uint8)0};

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_Snapshot_RP_SWC_SCF_SCF_stFFAction(CONSTP2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) data);

/*******************************************************************************
** Function Name : Prv_GetStoredSn
** Parameter[in] : None
** Parameter[out]: None
** Return Value  : (1)storedSn
** Note          : None
** Description   : Get stored sequence number.
*******************************************************************************/
static uint8 Prv_GetStoredSn(void)
{
    uint8 storedSn = (uint8)0;
    uint8 rteDtcValue = (uint8)0; /* 2: IGBT, 3: high voltage */
    uint32 currAddr0;

    currAddr0 = Prv_CfgTypePtr->StoredInfo[0].FastAddr \
              + (SNAPSHOT_RAM_F_STORED_TOTAL_SIZE & SNAPSHOT_DFLS_BURST_PAGE_SIZE_N_MASK) \
              + (SNAPSHOT_DFLS_BURST_PAGE_SIZE - 1UL);
    /* JEE_MISRA_RULE_11_04 It's allowed . */
    if ((uint8)0x57 == *(uint8 *)currAddr0) /* W */
    {
        Rte_Read_SWC_Snapshot_RP_SWC_SCF_SCF_stFFAction(&rteDtcValue);

        if ((rteDtcValue >= (uint8)2) && (rteDtcValue <= (uint8)3))
        {
            storedSn = rteDtcValue - (uint8)1;
        }
        else
        {
            storedSn = (uint8)0xFF;
        }
    }

    return (storedSn);
}

/*******************************************************************************
** Function Name : Prv_EraseInfo
** Parameter[in] : None
** Parameter[out]: None
** Return Value  : None
** Note          : None
** Description   : Erase routine.
*******************************************************************************/
static Std_ReturnType Prv_EraseInfo(uint8 storedSn)
{
    Std_ReturnType status = E_NOT_OK;

    if ((storedSn >= 1U) && (storedSn <= 2U))
    {
        (void)Snapshot_DFls_EraseSectors(
                                            Prv_CfgTypePtr->StoredInfo[storedSn].FastAddr,
                                            SNAPSHOT_DU_ONE_STORED_SECTOR_NUM
                                        );
        status = E_OK;
    }

    return (status);
}

/*******************************************************************************
** Function Name : Prv_WriteFastInfo
** Parameter[in] : (1)SnapshotRam_RamInfo_S *, (2)SnapshotDu_RamInfo_S *
** Parameter[out]: None
** Return Value  : None
** Note          : E_OK: Write successfully
** Description   : Write fast Info.
*******************************************************************************/
static Std_ReturnType Prv_WriteFastInfo(
                                           SnapshotRam_RamInfo_S *extRamInfoPtr,
                                           SnapshotDu_RamInfo_S *ramInfoPtr
                                       )
{
    Std_ReturnType status = E_NOT_OK;
    uint32 currTargetAddr;
    uint8 *currAddrPtr;

    if (ramInfoPtr->FastWriteCnt < SNAPSHOT_RAM_F_STORED_TOTAL_SIZE)
    {
        currTargetAddr = Prv_CfgTypePtr->StoredInfo[ramInfoPtr->StoredSn].FastAddr + ramInfoPtr->FastWriteCnt;

        if (ramInfoPtr->FastWriteCnt < (SNAPSHOT_RAM_F_STORED_TOTAL_SIZE & SNAPSHOT_DFLS_BURST_PAGE_SIZE_N_MASK))
        {
            /* JEE_MISRA_RULE_18_04 It's allowed . */
            currAddrPtr = (uint8 *)&extRamInfoPtr->FastInfo.BeforeFaultCnt + ramInfoPtr->FastWriteCnt;
        }
        else /* Last Page */
        {
            Snapshot_MemSet(&SnapshotDu_PageBuffer[0], (uint8)0, SNAPSHOT_DFLS_BURST_PAGE_SIZE);
            Snapshot_MemCopy(
                                &SnapshotDu_PageBuffer[0],
            /* JEE_MISRA_RULE_18_04 It's allowed . */
                                (const uint8 *)&extRamInfoPtr->FastInfo.BeforeFaultCnt + ramInfoPtr->FastWriteCnt,
                                (SNAPSHOT_RAM_F_STORED_TOTAL_SIZE & SNAPSHOT_DFLS_BURST_PAGE_SIZE_P_MASK)
                            );
            SnapshotDu_PageBuffer[31] = (uint8)0x57; /* Flag -> ASCII: 'W' */
            currAddrPtr = &SnapshotDu_PageBuffer[0];
        }

        /* JEE_MISRA_RULE_11_05 It's allowed . */
        if (E_OK == Snapshot_DFls_WriteBurst(currTargetAddr, (const Fls_AddressType *)(void *)currAddrPtr))
        {
            ramInfoPtr->FastWriteCnt += SNAPSHOT_DFLS_BURST_PAGE_SIZE;
        }
    }
    else
    {
        ramInfoPtr->FastWriteCnt = 0UL;
        status = E_OK;
    }

    return (status);
}

/*******************************************************************************
** Function Name : Prv_WriteSlowInfo
** Parameter[in] : (1)SnapshotRam_RamInfo_S *, (2)SnapshotDu_RamInfo_S *
** Parameter[out]: None
** Return Value  : None
** Note          : E_OK: Write successfully
** Description   : Write slow Info.
*******************************************************************************/
static Std_ReturnType Prv_WriteSlowInfo(
                                           SnapshotRam_RamInfo_S *extRamInfoPtr,
                                           SnapshotDu_RamInfo_S *ramInfoPtr
                                       )
{
    Std_ReturnType status = E_NOT_OK;
    uint32 currTargetAddr;
    uint8 *currAddrPtr;

    if (ramInfoPtr->SlowWriteCnt < SNAPSHOT_RAM_S_STORED_TOTAL_SIZE)
    {
        currTargetAddr = Prv_CfgTypePtr->StoredInfo[ramInfoPtr->StoredSn].SlowAddr + ramInfoPtr->SlowWriteCnt;

        if (ramInfoPtr->SlowWriteCnt < (SNAPSHOT_RAM_S_STORED_TOTAL_SIZE & SNAPSHOT_DFLS_BURST_PAGE_SIZE_N_MASK))
        {
            /* JEE_MISRA_RULE_18_04 It's allowed . */
            currAddrPtr = (uint8 *)&extRamInfoPtr->SlowInfo.BeforeFaultCnt + ramInfoPtr->SlowWriteCnt;
        }
        else /* Last Page */
        {
            Snapshot_MemSet(&SnapshotDu_PageBuffer[0], (uint8)0, SNAPSHOT_DFLS_BURST_PAGE_SIZE);
            Snapshot_MemCopy(
                                &SnapshotDu_PageBuffer[0],
            /* JEE_MISRA_RULE_18_04 It's allowed . */
                                (uint8 *)&extRamInfoPtr->SlowInfo.BeforeFaultCnt + ramInfoPtr->SlowWriteCnt,
                                (SNAPSHOT_RAM_S_STORED_TOTAL_SIZE & SNAPSHOT_DFLS_BURST_PAGE_SIZE_P_MASK)
                            );
            SnapshotDu_PageBuffer[31] = (uint8)0x57; /* Flag -> ASCII: 'W' */
            currAddrPtr = &SnapshotDu_PageBuffer[0];
        }
        /* JEE_MISRA_RULE_11_05 It's allowed . */
        if (E_OK == Snapshot_DFls_WriteBurst(currTargetAddr, (const Fls_AddressType *)(void *)currAddrPtr))
        {
            ramInfoPtr->SlowWriteCnt += SNAPSHOT_DFLS_BURST_PAGE_SIZE;
        }
    }
    else
    {
        ramInfoPtr->SlowWriteCnt = 0UL;
        status = E_OK;
    }

    return (status);
}

/*******************************************************************************
** Function Name : Prv_WriteDtcIdInfo
** Parameter[in] : (1)SnapshotRam_RamInfo_S *, (2)SnapshotDu_RamInfo_S *
** Parameter[out]: None
** Return Value  : None
** Note          : E_OK: Write successfully
** Description   : Write DtcId Info.
*******************************************************************************/
static Std_ReturnType Prv_WriteDtcIdInfo(
		                                 const SnapshotDu_RamInfo_S *ramInfoPtr
                                        )
{
    Std_ReturnType status = E_NOT_OK;
    uint32 currTargetAddr;

    currTargetAddr = Prv_CfgTypePtr->StoredInfo[ramInfoPtr->StoredSn].DtcIdAddr;
    Snapshot_MemSet(&SnapshotDu_PageBuffer[0], (uint8)0, SNAPSHOT_DFLS_BURST_PAGE_SIZE);
    Snapshot_MemCopy(
                        &SnapshotDu_PageBuffer[0],
                        &VAR_DEM_EventList_au8[0],
                        24UL
                    );

    /* JEE_MISRA_RULE_11_05 It's allowed . */
    if (E_OK == Snapshot_DFls_WriteBurst(currTargetAddr, (const Fls_AddressType *)(void *)&SnapshotDu_PageBuffer[0]))
    {
        status = E_OK;
    }

    return (status);
}

/*******************************************************************************
** Function Name : Prv_UpdateInfoToFls
** Parameter[in] : (1)SnapshotRam_RamInfo_S *, (2)SnapshotDu_RamInfo_S *
** Parameter[out]: None
** Return Value  : None
** Note          : None
** Description   : Update Info to Flash.
*******************************************************************************/
static void Prv_UpdateInfoToFls(
                                   SnapshotRam_RamInfo_S *extRamInfoPtr,
                                   SnapshotDu_RamInfo_S *ramInfoPtr
                               )
{
    switch (ramInfoPtr->WriteFsm)
    {
        case SNAPSHOT_DU_IDLE:
        {
            if ((SNAPSHOT_RAM_LOCK_FAULT == extRamInfoPtr->FastInfo.Fsm)
             && (SNAPSHOT_RAM_LOCK_FAULT == extRamInfoPtr->SlowInfo.Fsm))
            {
                ramInfoPtr->StoredSn = Prv_GetStoredSn();

                switch (ramInfoPtr->StoredSn)
                {
                    case (uint8)0:
                    {
                        ramInfoPtr->WriteFsm = SNAPSHOT_DU_FAST;
                        break;
                    }
                    case (uint8)1:
                    case (uint8)2:
                    {
                        ramInfoPtr->WriteFsm = SNAPSHOT_DU_ERASE; /* 1 or 2 */
                        break;
                    }
                    default :
                    {
                        /* Intentionally Empty*/
                        break;
                    }
                }
            }
            break;
        }
        case SNAPSHOT_DU_ERASE:
        {
            if (0UL == Snapshot_DFls_HWBusyCheck())
            {
                if (E_OK == Prv_EraseInfo(ramInfoPtr->StoredSn))
                {
                    ramInfoPtr->WriteFsm = SNAPSHOT_DU_ERASE_BLOCKING;
                }
            }
            break;
        }
        case SNAPSHOT_DU_ERASE_BLOCKING:
        {
            if (0UL == Snapshot_DFls_HWBusyCheck())
            {
                ramInfoPtr->WriteFsm = SNAPSHOT_DU_FAST;
            }
            break;
        }
        case SNAPSHOT_DU_FAST:
        {
            if (0UL == Snapshot_DFls_HWBusyCheck())
            {
                if (E_OK == Prv_WriteFastInfo(extRamInfoPtr, ramInfoPtr))
                {
                    ramInfoPtr->WriteFsm = SNAPSHOT_DU_SLOW;
                }
            }
            break;
        }
        case SNAPSHOT_DU_SLOW:
        {
            if (0UL == Snapshot_DFls_HWBusyCheck())
            {
                if (E_OK == Prv_WriteSlowInfo(extRamInfoPtr, ramInfoPtr))
                {
                    ramInfoPtr->WriteFsm = SNAPSHOT_DU_DTC_ID;
                }
            }
            break;
        }
        case SNAPSHOT_DU_DTC_ID:
        {
            if (0UL == Snapshot_DFls_HWBusyCheck())
            {
                if (E_OK == Prv_WriteDtcIdInfo(ramInfoPtr))
                {
                    ramInfoPtr->WriteFsm = SNAPSHOT_DU_DTC_ID_BLOCKING;
                }
            }
            break;
        }
        case SNAPSHOT_DU_DTC_ID_BLOCKING:
        {
            if (0UL == Snapshot_DFls_HWBusyCheck())
            {
                ramInfoPtr->WriteFsm = SNAPSHOT_DU_FINISHED;
            }
            break;
        }
        default:
        {
            /* Intentionally Empty*/
            break;
        }
    }
}

/*******************************************************************************
** Function Name : SnapshotDu_MainFunction
** Parameter[in] : None
** Parameter[out]: None
** Return Value  : None
** Note          : None
** Description   : Main schduling function.
*******************************************************************************/
void SnapshotDu_MainFunction(void)
{
    Prv_UpdateInfoToFls(&SnapshotRam_DefRamInfo_S, Prv_CfgTypePtr->RamInfoPtr);
}

/*******************************************************************************
** Function Name : SnapshotDu_Init
** Parameter[in] : (1)const SnapshotDu_ConfigType_S *
** Parameter[out]: None
** Return Value  : (1)E_OK: Init successfully
** Note          : None
** Description   : Init function.
*******************************************************************************/
Std_ReturnType SnapshotDu_Init(const SnapshotDu_ConfigType_S *mCfgPtr)
{
    Std_ReturnType mStatus = E_NOT_OK;

    if (NULL != mCfgPtr)
    {
        Prv_CfgTypePtr = mCfgPtr;
        mStatus = E_OK;
    }

    return (mStatus);
}
