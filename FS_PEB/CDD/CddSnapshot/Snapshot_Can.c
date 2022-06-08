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
* $Name______: Snapshot_Can.c$
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

#include "BswM_Generic.h"
#include "BswM_Cfg_MRP.h"
#include "SchM_BswM_Type.h"

#include "Snapshot_MemFunc.h"
#include "Snapshot_DFls.h"
#include "Snapshot_DFlsUpdate_PBCfg.h"
#include "Snapshot_Can.h"


#define PRV_MAX_SF_LEN              (7UL)

#define PRV_SF_HIGH_NIBBLE          ((uint8)0x00)
#define PRV_FF_HIGH_NIBBLE          ((uint8)0x10)
#define PRV_CF_HIGH_NIBBLE          ((uint8)0x20)

typedef enum
{
    PRV_ERASE_DFLASH_IDLE = 0,
    PRV_ERASE_DFLASH,
    PRV_ERASE_DFLASH_BLOCKING
} Prv_EraseDFlsFsm_E;

typedef enum
{
    PRV_W_OFFSET_IDLE = 0,
    PRV_W_OFFSET_ERASE,
    PRV_W_OFFSET_ERASE_BLOCKING,
    PRV_W_OFFSET_WRITE,
    PRV_W_OFFSET_WRITE_BLOCKING
} Prv_WriteOffsetFsm_E;

typedef enum
{
    PRV_R_OFFSET_IDLE = 0,
    PRV_R_OFFSET_READ,
    PRV_R_OFFSET_BLOCKING
} Prv_ReadOffsetFsm_E;

typedef enum
{
    PRV_CAN_RX_IDLE = 0,
    PRV_CAN_TX_SF,
    PRV_CAN_TX_FF,
    PRV_CAN_TX_CF,
} Prv_CanFsm_E;

typedef struct
{
    boolean TxSF_Flag;
    Prv_EraseDFlsFsm_E EraseDFlsFsm;
    Prv_WriteOffsetFsm_E WriteOffsetFsm;
    Prv_ReadOffsetFsm_E ReadOffsetFsm;
    Prv_CanFsm_E CanFsm;
} Prv_InternalFsm_S;

static Prv_InternalFsm_S Prv_DefInternalFsm =
{
    FALSE,
    PRV_ERASE_DFLASH_IDLE,
    PRV_W_OFFSET_IDLE,
    PRV_R_OFFSET_IDLE,
    PRV_CAN_RX_IDLE
};
static const SnapshotCan_ConfigType_S *Prv_CfgTypePtr = NULL;

static void Prv_TransmitEnable(uint8 enableFlag);
static void Prv_ResetRxRamInfo(SnapshotCan_RxRamInfo_S *ramInfoPtr);
static void Prv_ResetTxRamInfo(SnapshotCan_TxRamInfo_S *ramInfoPtr);
static void Prv_ReceiveSF(
                             SnapshotCan_RxRamInfo_S *rxRamInfoPtr,
                             const SnapshotCan_TxRamInfo_S *txRamInfoPtr
                         );
static void Prv_PreTransmitSF(
                                 const SnapshotCan_RxRamInfo_S *rxRamInfoPtr,
                                 SnapshotCan_TxRamInfo_S *txRamInfoPtr
                             );
static void Prv_EraseDFlash_Handle(
                                      SnapshotCan_RxRamInfo_S *rxRamInfoPtr,
                                      SnapshotCan_TxRamInfo_S *txRamInfoPtr
                                  );
static void Prv_WriteOffset_Handle(
                                      SnapshotCan_RxRamInfo_S *rxRamInfoPtr,
                                      SnapshotCan_TxRamInfo_S *txRamInfoPtr
                                  );
static void Prv_ReadOffset_Handle(
                                     SnapshotCan_RxRamInfo_S *rxRamInfoPtr,
                                     SnapshotCan_TxRamInfo_S *txRamInfoPtr
                                 );
static void Prv_PostTransmitSF(
                                  SnapshotCan_RxRamInfo_S *rxRamInfoPtr,
                                  SnapshotCan_TxRamInfo_S *txRamInfoPtr
                              );
static void Prv_TransmitSF(
                              SnapshotCan_RxRamInfo_S *rxRamInfoPtr,
                              SnapshotCan_TxRamInfo_S *txRamInfoPtr
                          );
static void Prv_TransmitFF(
                              const SnapshotCan_RxRamInfo_S *rxRamInfoPtr,
                              SnapshotCan_TxRamInfo_S *txRamInfoPtr
                          );
static void Prv_TransmitCF(
                              SnapshotCan_RxRamInfo_S *rxRamInfoPtr,
                              SnapshotCan_TxRamInfo_S *txRamInfoPtr
                          );

/*******************************************************************************
** Function Name : Prv_TransmitEnable
** Parameter[in] : (1)enableFlag
** Parameter[out]: None
** Return Value  : None
** Note          : None
** Description   : Enable transmit.
*******************************************************************************/
static void Prv_TransmitEnable(uint8 enableFlag)
{
    if ((uint8)1== enableFlag)
    {
        /* Enable Transmit */
        BswM_RequestMode(
                            BSWM_CFG_USERID_BSWM_MRP_STARTPDUGROUP_FR,
                            RTE_MODE_MDG_ECUM_STATE_ECUM_STATE_STARTUP_TWO
                        );
    }
    else
    {
        /* Disable Transmit */
        BswM_RequestMode(
                            BSWM_CFG_USERID_BSWM_MRP_STOPPDUGROUP_FR,
                            RTE_MODE_MDG_ECUM_STATE_ECUM_STATE_STARTUP_TWO
                        );
    }
}

/*******************************************************************************
** Function Name : Prv_ResetRxRamInfo
** Parameter[in] : (1)SnapshotCan_RxRamInfo_S *
** Parameter[out]: None
** Return Value  : None
** Note          : None
** Description   : Reset Ram Infomation.
*******************************************************************************/
static void Prv_ResetRxRamInfo(SnapshotCan_RxRamInfo_S *ramInfoPtr)
{
    ramInfoPtr->FuncId = (uint8)0;
    ramInfoPtr->SubFuncId = (uint8)0;
    Snapshot_MemSet(&ramInfoPtr->InfoBuffer[0], Prv_CfgTypePtr->RxFlsCfg.PaddingValue, 8UL);
}

/*******************************************************************************
** Function Name : Prv_ResetTxRamInfo
** Parameter[in] : (1)SnapshotCan_TxRamInfo_S *
** Parameter[out]: None
** Return Value  : None
** Note          : None
** Description   : Reset Tx Ram Information.
*******************************************************************************/
static void Prv_ResetTxRamInfo(SnapshotCan_TxRamInfo_S *ramInfoPtr)
{
    ramInfoPtr->CompletedInfoLen = 0U;
    ramInfoPtr->SN = (uint8)0;
}

/*******************************************************************************
** Function Name : Prv_ReceiveSF
** Parameter[in] : (1)SnapshotCan_RxRamInfo_S *
** Parameter[out]: (1)SnapshotCan_TxRamInfo_S *
** Return Value  : None
** Note          : None
** Description   : Receive singal frame.
*******************************************************************************/
static void Prv_ReceiveSF(
                             SnapshotCan_RxRamInfo_S *rxRamInfoPtr,
                             const SnapshotCan_TxRamInfo_S *txRamInfoPtr
                         )
{
    uint32 len;

    if ((NULL != rxRamInfoPtr) && (NULL != txRamInfoPtr))
    {
        len = ((uint16)rxRamInfoPtr->InfoBuffer[0] & 0x0FUL);

        if ((len > 0UL) && (len <= PRV_MAX_SF_LEN))
        {
            switch (rxRamInfoPtr->InfoBuffer[1])
            {
                case (uint8)0xA0: /* Read DtcId */
                {
                    if (((uint8)2 == rxRamInfoPtr->InfoBuffer[0]) && (rxRamInfoPtr->InfoBuffer[2] <= (uint8)3))
                    {
                        rxRamInfoPtr->FuncId = rxRamInfoPtr->InfoBuffer[1];
                        rxRamInfoPtr->SubFuncId = rxRamInfoPtr->InfoBuffer[2];

                        Prv_DefInternalFsm.CanFsm = PRV_CAN_TX_FF;
                    }
                    break;
                }
                case (uint8)0xA1: /* Read DtcData */
                {
                    if (((uint8)2 == rxRamInfoPtr->InfoBuffer[0]) && (rxRamInfoPtr->InfoBuffer[2] <= (uint8)7))
                    {
                        rxRamInfoPtr->FuncId = rxRamInfoPtr->InfoBuffer[1];
                        rxRamInfoPtr->SubFuncId = rxRamInfoPtr->InfoBuffer[2];

                        Prv_DefInternalFsm.CanFsm = PRV_CAN_TX_FF;
                    }
                    break;
                }
                case (uint8)0xA2: /* Clear DtcId and DtcData */
                case (uint8)0x22: /* Read Offset */
                {
                    if (((uint8)2 == rxRamInfoPtr->InfoBuffer[0]) && ((uint8)0 == rxRamInfoPtr->InfoBuffer[2]))
                    {
                        rxRamInfoPtr->FuncId = rxRamInfoPtr->InfoBuffer[1];
                        rxRamInfoPtr->SubFuncId = rxRamInfoPtr->InfoBuffer[2];

                        Prv_DefInternalFsm.CanFsm = PRV_CAN_TX_SF;
                        Prv_DefInternalFsm.TxSF_Flag = TRUE;
                    }
                    break;
                }
                case (uint8)0x2E: /* Write Offset */
                {
                    if (((uint8)6 == rxRamInfoPtr->InfoBuffer[0]) && ((uint8)0 == rxRamInfoPtr->InfoBuffer[2]))
                    {
                        rxRamInfoPtr->FuncId = rxRamInfoPtr->InfoBuffer[1];
                        rxRamInfoPtr->SubFuncId = rxRamInfoPtr->InfoBuffer[2];

                        Prv_DefInternalFsm.CanFsm = PRV_CAN_TX_SF;
                        Prv_DefInternalFsm.TxSF_Flag = TRUE;
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
    }
}

/*******************************************************************************
** Function Name : Prv_PreTransmitSF
** Parameter[in] : (1)SnapshotCan_RxRamInfo_S *
** Parameter[out]: (1)SnapshotCan_TxRamInfo_S *
** Return Value  : None
** Note          : None
** Description   : PreTransmit SF.
*******************************************************************************/
static void Prv_PreTransmitSF(
                                 const SnapshotCan_RxRamInfo_S *rxRamInfoPtr,
                                 SnapshotCan_TxRamInfo_S *txRamInfoPtr
                             )
{
    Snapshot_MemSet(&txRamInfoPtr->InfoBuffer[0], Prv_CfgTypePtr->TxFlsCfg.PaddingValue, 8UL);

    if (0x22U == rxRamInfoPtr->FuncId)
    {
        txRamInfoPtr->InfoBuffer[0] = (PRV_SF_HIGH_NIBBLE | (uint8)0x06);
    }
    else
    {
        txRamInfoPtr->InfoBuffer[0] = (PRV_SF_HIGH_NIBBLE | (uint8)0x02);
    }

    txRamInfoPtr->InfoBuffer[1] = rxRamInfoPtr->FuncId + (uint8)0x40;
    txRamInfoPtr->InfoBuffer[2] = rxRamInfoPtr->SubFuncId;

    if ((uint8)0xA2 == rxRamInfoPtr->FuncId) /* Erase DFlash: Sector24- 41 */
    {
        Prv_DefInternalFsm.EraseDFlsFsm = PRV_ERASE_DFLASH;
    }
    else if ((uint8)0x2E == rxRamInfoPtr->FuncId) /* Write Offset */
    {
        Prv_DefInternalFsm.WriteOffsetFsm = PRV_W_OFFSET_ERASE;
    }
    else /* Read Offset */
    {
        Prv_DefInternalFsm.ReadOffsetFsm = PRV_R_OFFSET_READ;
    }
}

/*******************************************************************************
** Function Name : Prv_EraseDFlash_Handle
** Parameter[in] : None
** Parameter[out]: None
** Return Value  : None
** Note          : None
** Description   : Erase DFlash handle.
*******************************************************************************/
static void Prv_EraseDFlash_Handle(
                                      SnapshotCan_RxRamInfo_S *rxRamInfoPtr,
                                      SnapshotCan_TxRamInfo_S *txRamInfoPtr
                                  )
{
    switch (Prv_DefInternalFsm.EraseDFlsFsm)
    {
        case PRV_ERASE_DFLASH:
        {
            if (0UL == Snapshot_DFls_HWBusyCheck())
            {
                (void)Snapshot_DFls_EraseSectors(SNAPSHOT_DFLS_SECTOR_24, SNAPSHOT_DU_SECTOR_NUM);
                Prv_DefInternalFsm.EraseDFlsFsm = PRV_ERASE_DFLASH_BLOCKING;
            }
            break;
        }
        case PRV_ERASE_DFLASH_BLOCKING:
        {
            if (0UL == Snapshot_DFls_HWBusyCheck())
            {
                txRamInfoPtr->TxCom.TxFlag = (uint8)1;  /* Close Tx */
                Prv_TransmitEnable((uint8)1);

                Prv_ResetRxRamInfo(rxRamInfoPtr);
                Prv_ResetTxRamInfo(txRamInfoPtr);
                Prv_DefInternalFsm.EraseDFlsFsm = PRV_ERASE_DFLASH_IDLE;
                Prv_DefInternalFsm.CanFsm = PRV_CAN_RX_IDLE;
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
** Function Name : Prv_WriteOffset_Handle
** Parameter[in] : None
** Parameter[out]: None
** Return Value  : None
** Note          : None
** Description   : Write offset handle.
*******************************************************************************/
static void Prv_WriteOffset_Handle(
                                      SnapshotCan_RxRamInfo_S *rxRamInfoPtr,
                                      SnapshotCan_TxRamInfo_S *txRamInfoPtr
                                  )
{
    switch (Prv_DefInternalFsm.WriteOffsetFsm)
    {
        case PRV_W_OFFSET_ERASE:
        {
            if (0UL == Snapshot_DFls_HWBusyCheck())
            {
                (void)Snapshot_DFls_EraseSectors(SNAPSHOT_DFLS_SECTOR_47, 1UL);
                Prv_DefInternalFsm.WriteOffsetFsm = PRV_W_OFFSET_ERASE_BLOCKING;
            }
            break;
        }
        case PRV_W_OFFSET_ERASE_BLOCKING:
        {
            if (0UL == Snapshot_DFls_HWBusyCheck())
            {
                Snapshot_MemSet(&SnapshotDu_PageBuffer[0], (uint8)0, SNAPSHOT_DFLS_BURST_PAGE_SIZE);
                SnapshotDu_PageBuffer[0] = rxRamInfoPtr->InfoBuffer[6];
                SnapshotDu_PageBuffer[1] = rxRamInfoPtr->InfoBuffer[5];
                SnapshotDu_PageBuffer[2] = rxRamInfoPtr->InfoBuffer[4];
                SnapshotDu_PageBuffer[3] = rxRamInfoPtr->InfoBuffer[3];
                Snapshot_MemSet(&SnapshotDu_PageBuffer[4], (uint8)0x5A, SNAPSHOT_DU_PBCFG_OFFSET_FLAG_LEN);
                Prv_DefInternalFsm.WriteOffsetFsm = PRV_W_OFFSET_WRITE;
            }
            break;
        }
        case PRV_W_OFFSET_WRITE:
        {
            if (0UL == Snapshot_DFls_HWBusyCheck())
            {
                /* JEE_MISRA_RULE_11_05 It's allowed . */
                (void)Snapshot_DFls_WriteBurst(SNAPSHOT_DU_PBCFG_OFFSET_ADDR, (const Fls_AddressType *)(void *)&SnapshotDu_PageBuffer[0]);
                Prv_DefInternalFsm.WriteOffsetFsm = PRV_W_OFFSET_WRITE_BLOCKING;
            }
            break;
        }
        case PRV_W_OFFSET_WRITE_BLOCKING:
        {
            if (0UL == Snapshot_DFls_HWBusyCheck())
            {
                txRamInfoPtr->TxCom.TxFlag = (uint8)1;  /* Close Tx */
                Prv_TransmitEnable((uint8)1);

                Prv_ResetRxRamInfo(rxRamInfoPtr);
                Prv_ResetTxRamInfo(txRamInfoPtr);
                Prv_DefInternalFsm.WriteOffsetFsm = PRV_W_OFFSET_IDLE;
                Prv_DefInternalFsm.CanFsm = PRV_CAN_RX_IDLE;
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
** Function Name : Prv_ReadOffset_Handle
** Parameter[in] : None
** Parameter[out]: None
** Return Value  : None
** Note          : None
** Description   : Read offset handle.
*******************************************************************************/
static void Prv_ReadOffset_Handle(
                                     SnapshotCan_RxRamInfo_S *rxRamInfoPtr,
                                     SnapshotCan_TxRamInfo_S *txRamInfoPtr
                                 )
{
    uint32 value;

    switch (Prv_DefInternalFsm.ReadOffsetFsm)
    {
        case PRV_R_OFFSET_READ:
        {
            if (0UL == Snapshot_DFls_HWBusyCheck())
            {
                /* JEE_MISRA_RULE_11_04 It's allowed . */
                value = (*(uint32 *)SNAPSHOT_DU_PBCFG_OFFSET_ADDR);
                Prv_CfgTypePtr->OffsetRamInfoPtr->OffsetValue = (float32)value / 100.0F;

                /* JEE_MISRA_RULE_11_04 It's allowed . */
                if (0x5A5A5A5AUL == (*(uint32 *)SNAPSHOT_DU_PBCFG_OFFSET_FLAG_ADDR))
                {
                    Prv_CfgTypePtr->OffsetRamInfoPtr->OffsetFlag = TRUE;
                }

                txRamInfoPtr->InfoBuffer[3] = (uint8)((value & 0xFF000000UL) >> 24UL);
                txRamInfoPtr->InfoBuffer[4] = (uint8)((value & 0x00FF0000UL) >> 16UL);
                txRamInfoPtr->InfoBuffer[5] = (uint8)((value & 0x0000FF00UL) >> 8UL);
                txRamInfoPtr->InfoBuffer[6] = (uint8)(value & 0x000000FFUL);
                Prv_DefInternalFsm.ReadOffsetFsm = PRV_R_OFFSET_BLOCKING;
            }
            break;
        }
        case PRV_R_OFFSET_BLOCKING:
        {
            if (0UL == Snapshot_DFls_HWBusyCheck())
            {
                txRamInfoPtr->TxCom.TxFlag = (uint8)1;  /* Close Tx */
                Prv_TransmitEnable((uint8)1);

                Prv_ResetRxRamInfo(rxRamInfoPtr);
                Prv_ResetTxRamInfo(txRamInfoPtr);
                Prv_DefInternalFsm.ReadOffsetFsm = PRV_R_OFFSET_IDLE;
                Prv_DefInternalFsm.CanFsm = PRV_CAN_RX_IDLE;
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
** Function Name : Prv_PostTransmitSF
** Parameter[in] : (1)SnapshotCan_RxRamInfo_S *
** Parameter[out]: (1)SnapshotCan_TxRamInfo_S *
** Return Value  : None
** Note          : None
** Description   : Post transmit SF.
*******************************************************************************/
static void Prv_PostTransmitSF(
                                  SnapshotCan_RxRamInfo_S *rxRamInfoPtr,
                                  SnapshotCan_TxRamInfo_S *txRamInfoPtr
                              )
{
    if ((uint8)0xA2 == rxRamInfoPtr->FuncId) /* Erase DFlash: Sector24- 41 */
    {
        Prv_EraseDFlash_Handle(rxRamInfoPtr, txRamInfoPtr);
    }
    else if ((uint8)0x2E == rxRamInfoPtr->FuncId) /* Write Offset */
    {
        Prv_WriteOffset_Handle(rxRamInfoPtr, txRamInfoPtr);
    }
    else /* Read Offset */
    {
        Prv_ReadOffset_Handle(rxRamInfoPtr, txRamInfoPtr);
    }
}

/*******************************************************************************
** Function Name : Prv_TransmitSF
** Parameter[in] : (1)SnapshotCan_RxRamInfo_S *
** Parameter[out]: (1)SnapshotCan_TxRamInfo_S *
** Return Value  : None
** Note          : None
** Description   : Transmit SF.
*******************************************************************************/
static void Prv_TransmitSF(
                              SnapshotCan_RxRamInfo_S *rxRamInfoPtr,
                              SnapshotCan_TxRamInfo_S *txRamInfoPtr
                          )
{
    if ((NULL != rxRamInfoPtr) && (NULL != txRamInfoPtr))
    {
        if (TRUE == Prv_DefInternalFsm.TxSF_Flag)
        {
            Prv_DefInternalFsm.TxSF_Flag = FALSE;
            Prv_PreTransmitSF(rxRamInfoPtr, txRamInfoPtr);
        }
        else
        {
            Prv_PostTransmitSF(rxRamInfoPtr, txRamInfoPtr);
        }
    }
}

/*******************************************************************************
** Function Name : Prv_TransmitFF
** Parameter[in] : (1)SnapshotCan_RxRamInfo_S *
** Parameter[out]: (1)SnapshotCan_TxRamInfo_S *
** Return Value  : None
** Note          : None
** Description   : Transmit FF.
*******************************************************************************/
static void Prv_TransmitFF(
                              const SnapshotCan_RxRamInfo_S *rxRamInfoPtr,
                              SnapshotCan_TxRamInfo_S *txRamInfoPtr
                          )
{
    uint32  len;
    const SnapshotCan_PduInfo_S *pduInfoPtr;

    if(NULL != rxRamInfoPtr)
    {
        if ((uint8)0xA0 == rxRamInfoPtr->FuncId)
        {
            pduInfoPtr = &Prv_CfgTypePtr->TxFlsCfg.DtcIdBufferInfo[rxRamInfoPtr->SubFuncId];
        }
        else
        {
            pduInfoPtr = &Prv_CfgTypePtr->TxFlsCfg.DtcDataBufferInfo[rxRamInfoPtr->SubFuncId];
        }
    }

    if ((NULL != rxRamInfoPtr) && (NULL != txRamInfoPtr))
    {
        txRamInfoPtr->InfoBuffer[0] = (PRV_FF_HIGH_NIBBLE | (uint8)((pduInfoPtr->SduLength & 0x0F0000UL) >> 16UL));
        txRamInfoPtr->InfoBuffer[1] = (uint8)((pduInfoPtr->SduLength & 0xFF00UL) >> 8UL);
        txRamInfoPtr->InfoBuffer[2] = (uint8)(pduInfoPtr->SduLength & 0xFFUL);
        txRamInfoPtr->InfoBuffer[3] = rxRamInfoPtr->FuncId + (uint8)0x40;
        txRamInfoPtr->InfoBuffer[4] = rxRamInfoPtr->SubFuncId;
        len = PRV_MAX_SF_LEN - 4UL;

        Snapshot_MemCopy(
                            &txRamInfoPtr->InfoBuffer[5],
                            pduInfoPtr->SduDataPtr,
                            len
                        );
        Prv_TransmitEnable((uint8)1);

        txRamInfoPtr->CompletedInfoLen = len;
        txRamInfoPtr->SN = (uint8)1;
        Prv_DefInternalFsm.CanFsm = PRV_CAN_TX_CF;
    }
}

/*******************************************************************************
** Function Name : Prv_TransmitCF
** Parameter[in] : (1)SnapshotCan_RxRamInfo_S *
** Parameter[out]: (1)SnapshotCan_TxRamInfo_S *
** Return Value  : None
** Note          : None
** Description   : Transmit CF.
*******************************************************************************/
static void Prv_TransmitCF(
                              SnapshotCan_RxRamInfo_S *rxRamInfoPtr,
                              SnapshotCan_TxRamInfo_S *txRamInfoPtr
                          )
{
    uint32 len;
    const SnapshotCan_PduInfo_S *pduInfoPtr;

    if(NULL != rxRamInfoPtr)
    {
    	if ((uint8)0xA0 == rxRamInfoPtr->FuncId)
    	{
    	    pduInfoPtr = &Prv_CfgTypePtr->TxFlsCfg.DtcIdBufferInfo[rxRamInfoPtr->SubFuncId];
    	}
    	else
    	{
    	    pduInfoPtr = &Prv_CfgTypePtr->TxFlsCfg.DtcDataBufferInfo[rxRamInfoPtr->SubFuncId];
    	}
    }

    if ((NULL != rxRamInfoPtr) && (NULL != txRamInfoPtr))
    {
        Snapshot_MemSet(&txRamInfoPtr->InfoBuffer[0], Prv_CfgTypePtr->TxFlsCfg.PaddingValue, 8UL);
        txRamInfoPtr->InfoBuffer[0] = (PRV_CF_HIGH_NIBBLE | (txRamInfoPtr->SN & (uint8)0x0F));

        if ((txRamInfoPtr->CompletedInfoLen + PRV_MAX_SF_LEN) <= pduInfoPtr->SduLength)
        {
            len = PRV_MAX_SF_LEN;
        }
        else
        {
            len = pduInfoPtr->SduLength - txRamInfoPtr->CompletedInfoLen;
        }

        Snapshot_MemCopy(
                            &txRamInfoPtr->InfoBuffer[1],
        /* JEE_MISRA_RULE_18_04 It's allowed . */
                            pduInfoPtr->SduDataPtr + txRamInfoPtr->CompletedInfoLen,
                            len
                        );

        txRamInfoPtr->SN = ((txRamInfoPtr->SN + (uint8)1) & (uint8)0x0F);
        txRamInfoPtr->CompletedInfoLen += len;

        if (txRamInfoPtr->CompletedInfoLen == pduInfoPtr->SduLength)
        {
            Prv_ResetRxRamInfo(rxRamInfoPtr);
            Prv_ResetTxRamInfo(txRamInfoPtr);
            Prv_DefInternalFsm.CanFsm = PRV_CAN_RX_IDLE;

            txRamInfoPtr->TxCom.TxFlag = (uint8)1; /* Close Tx */
        }
    }
}

/*******************************************************************************
** Function Name	: SnapshotCan_TransmitDisable
** Parameter[in] 	: (1)SnapshotCan_TxCom_S pointer
** Parameter[out] 	: None
** Return Value	  	: None
** Note		    	: None
** Description	  	: Disable transmit.
*******************************************************************************/
void SnapshotCan_TransmitDisable(SnapshotCan_TxCom_S * txComPtr)
{
    if ((uint8)1 == txComPtr->TxFlag)
    {
        txComPtr->TxCnt++;

        if (txComPtr->TxCnt >= 1U)
        {
            txComPtr->TxCnt = 0U;
            Prv_TransmitEnable((uint8)0);
            txComPtr->TxFlag = (uint8)0;
        }
    }
}

/*******************************************************************************
** Function Name	: SnapshotCan_MainFunction
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			    : None
** Description	  	: Main schduling function.
*******************************************************************************/
void SnapshotCan_MainFunction(void)
{
    SnapshotCan_RxRamInfo_S *rxRamInfoPtr;
    SnapshotCan_TxRamInfo_S *txRamInfoPtr;

    rxRamInfoPtr = Prv_CfgTypePtr->RxRamInfoPtr;
    txRamInfoPtr = Prv_CfgTypePtr->TxRamInfoPtr;

    switch (Prv_DefInternalFsm.CanFsm)
    {
        case PRV_CAN_RX_IDLE:
        {
            Prv_ReceiveSF(rxRamInfoPtr, txRamInfoPtr);
            break;
        }
        case PRV_CAN_TX_SF:
        {
            Prv_TransmitSF(rxRamInfoPtr, txRamInfoPtr);
            break;
        }
        case PRV_CAN_TX_FF:
        {
            Prv_TransmitFF(rxRamInfoPtr, txRamInfoPtr);
            break;
        }
        case PRV_CAN_TX_CF:
        {
            Prv_TransmitCF(rxRamInfoPtr, txRamInfoPtr);
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
** Function Name : SnapshotCan_Init
** Parameter[in] : (1)const SnapshotCan_ConfigType_S *
** Parameter[out]: None
** Return Value  : (1)E_OK: Init successfully
** Note          : None
** Description   : Init function.
*******************************************************************************/
Std_ReturnType SnapshotCan_Init(const SnapshotCan_ConfigType_S *mCfgPtr)
{
    Std_ReturnType mStatus = E_NOT_OK;

    if (NULL != mCfgPtr)
    {
        Prv_CfgTypePtr = mCfgPtr;
        /* JEE_MISRA_RULE_11_04 It's allowed . */
        Prv_CfgTypePtr->OffsetRamInfoPtr->OffsetValue = (float32)(*(uint32 *)SNAPSHOT_DU_PBCFG_OFFSET_ADDR) / 100.0F;

        /* JEE_MISRA_RULE_11_04 It's allowed . */
        if (0x5A5A5A5AUL == (*(uint32 *)SNAPSHOT_DU_PBCFG_OFFSET_FLAG_ADDR))
        {
            Prv_CfgTypePtr->OffsetRamInfoPtr->OffsetFlag = TRUE;
        }

        mStatus = E_OK;
    }

    return (mStatus);
}
