/*<RBHead>
 *************************************************************************
 *                                                                       *
 *                      ROBERT BOSCH GMBH                                *
 *                          STUTTGART                                    *
 *                                                                       *
 *          Alle Rechte vorbehalten - All rights reserved                *
 *                                                                       *
 *************************************************************************

 *************************************************************************
 *    Administrative Information (automatically filled in by eASEE)      *
 *************************************************************************
 *
 * $Filename__:$
 *
 * $Author____:$
 *
 * $Function__:$
 *
 *************************************************************************
 * $Domain____:$
 * $User______:$
 * $Date______:$
 * $Class_____:$
 * $Name______:$
 * $Variant___:$
 * $Revision__:$
 * $Type______:$
 * $State_____:$
 * $Generated_:$
 *************************************************************************
 *
 * $UniqueName:$
 * $Component_:$
 *
 *
 *************************************************************************
 * List Of Changes
 *
 * $History$
 *
 *************************************************************************
 </RBHead>*/


#include "NvM.h"
#include "NvM_Prv.h" /* Private header, but needed for internal information */

#include "rba_MemDiag_Prv.h"




/* Defines for diagnosis signals with block ids
 * Block id is limited to 15 bits
 * MSB defines block type */
#define RBA_MEMDIAG_SIGNAL_BLKID_MSK    0x7FFFu
#define RBA_MEMDIAG_SIGNAL_NVM          0x0000u
#define RBA_MEMDIAG_SIGNAL_EEPADAPTDGS  0x8000u


/* Internal order type */
typedef enum
{
    RBA_MEMDIAG_ORDTYP_IGR,         /* Order ignored */
    RBA_MEMDIAG_ORDTYP_READ,        /* Read order */
    RBA_MEMDIAG_ORDTYP_READSNG,     /* Read order for single storage block, only for extended memory diagnosis */
    RBA_MEMDIAG_ORDTYP_WR           /* Write order */
} rba_MemDiag_OrdTyp_ten;

/* Internal order result */
typedef enum
{
    RBA_MEMDIAG_ORDRES_IGR,         /* Order ignored */
    RBA_MEMDIAG_ORDRES_SUC,         /* Order finished successful */
    RBA_MEMDIAG_ORDRES_FAIL         /* Order failed */
} rba_MemDiag_OrdRes_ten;


#define RBA_MEMDIAG_START_SEC_CODE
#include "rba_MemDiag_MemMap.h"

/* Common handler for diagnosis callbacks */
LOCAL_INLINE void rba_MemDiag_HndlDiagClbck(rba_MemDiag_OrdTyp_ten idxOrdTyp, rba_MemDiag_OrdRes_ten idxOrdRes,
        uint16 nrBlkIdSig);

/* NvM declares this callback only in NvM_Cfg.c (not in NvM_Cfg.h). So declaration is needed here. */
Std_ReturnType rba_MemDiag_DiagClbckNvM(NvM_BlockIdType BlockId, uint8 ServiceId, NvM_RequestResultType JobResult);


/** ********************************************************************************************************************
 * \brief Diagnosis callback for NvM
 *
 * This function is called by NvM after finishing an job (NVM_SERVICE_ID_READ_BLOCK, NVM_SERVICE_ID_READ_ALL,
 * NVM_SERVICE_ID_WRITE_BLOCK, NVM_SERVICE_ID_WRITE_ALL).
 * Block id, mode and result of job are provided by NvM.
 *
 * \param   BlockId     Id of NvM block for which the job was executed
 * \param   ServiceId   Executed service by NvM
 * \param   JobResult   Result of NvM job
 * \return  Standard return type
 * \retval  E_OK        always return success
 *
 * \seealso MemDiag_DiagClbckEepAdaptDGS
 ******************************************************************************************************************** */
Std_ReturnType rba_MemDiag_DiagClbckNvM(NvM_BlockIdType BlockId, uint8 ServiceId, NvM_RequestResultType JobResult)
{
    rba_MemDiag_OrdTyp_ten idxOrdTyp;
    rba_MemDiag_OrdRes_ten idxOrdRes;
    uint8 nrActvSrv;
    uint16 nrBlkIdSig;

    /* Set order type */
    switch (ServiceId)
    {
        case NVM_SERVICE_ID_READ_BLOCK:
        case NVM_SERVICE_ID_READ_ALL:
        {
            idxOrdTyp = RBA_MEMDIAG_ORDTYP_READ;
            break;
        }

        case NVM_SERVICE_ID_WRITE_BLOCK:
        case NVM_SERVICE_ID_WRITE_ALL:
        case NVM_SERVICE_ID_INVALIDATE_NV_BLOCK:
        case NVM_SERVICE_ID_ERASE_NV_BLOCK:
        {
            idxOrdTyp = RBA_MEMDIAG_ORDTYP_WR;
            break;
        }

        default:
        {
            idxOrdTyp = RBA_MEMDIAG_ORDTYP_IGR;
            break;
        }
    }

    /* Set order status */
    switch (JobResult)
    {
        case NVM_REQ_OK:
        {
            idxOrdRes = RBA_MEMDIAG_ORDRES_SUC;
            break;
        }

        case NVM_REQ_NOT_OK:
        case NVM_REQ_INTEGRITY_FAILED:
        case NVM_REQ_REDUNDANCY_FAILED:
        case NVM_REQ_RESTORED_FROM_ROM:
        {
            idxOrdRes = RBA_MEMDIAG_ORDRES_FAIL;
            break;
        }

        default:
        {
            idxOrdRes = RBA_MEMDIAG_ORDRES_IGR;
            break;
        }
    }

    /* Handle exceptions for diagnosis */
    if (idxOrdTyp == RBA_MEMDIAG_ORDTYP_READ)
    {
        if (NvM_Rb_GetActiveService(&nrActvSrv) != E_OK)
        {
            /* Should not happen. Set to dummy service and ignore this result */
            nrActvSrv = NVM_SERVICE_ID_INIT;
            idxOrdTyp = RBA_MEMDIAG_ORDTYP_IGR;
        }

        /* Read diagnosis ignores blocks which are not initialized by first initialization */
        if ((NvM_Prv_BlockDescriptors_acst[BlockId].stFlags_u16 & NVM_PRV_BLOCK_FLAG_SELECT_FOR_FIRST_INIT_ALL) == 0u)
        {
            idxOrdTyp = RBA_MEMDIAG_ORDTYP_IGR;
        }

        /* Read diagnosis ignores blocks which are not initialized by initialization after layout change */
        if ((NvM_Prv_BlockDescriptors_acst[BlockId].stFlags_u16 & NVM_PRV_BLOCK_FLAG_SELECT_FOR_INIT_AT_LAYOUT_CHANGE) == 0u)
        {
            idxOrdTyp = RBA_MEMDIAG_ORDTYP_IGR;
        }

        /* Read diagnosis ignores blocks while NvM_ReadAll if layout change was detected */
        if (
                (nrActvSrv == NVM_SERVICE_ID_READ_ALL)
             && (JobResult == NVM_REQ_RESTORED_FROM_ROM)
             && ((NvM_Prv_stRequests_rAMwAM_au16[NVM_PRV_MULTI_BLOCK] & NVM_PRV_BLOCK_REQ_INIT_AT_LAYOUT_CHANGE) != 0u)
            )
        {
            /* Flag NVM_PRV_BLOCK_REQ_INIT_AT_LAYOUT_CHANGE is set after first block in NvM_ReadAll.
             * This is always ignored block NvM_ConfigId, so init after layout change can be detected for all blocks
             */
            idxOrdTyp = RBA_MEMDIAG_ORDTYP_IGR;
        }

        /* Read diagnosis is suppressed while first init or init after layout change is running */
        if (
                (nrActvSrv == NVM_SERVICE_ID_RB_FIRST_INIT_ALL)
             || (nrActvSrv == NVM_SERVICE_ID_RB_INIT_AFTER_READ_ALL)
             )
        {
            idxOrdTyp = RBA_MEMDIAG_ORDTYP_IGR;
        }

        /* Ignore special NvM blocks */
        if (BlockId == NvMConf_NvMBlockDescriptor_NvM_ConfigId)
        {
            idxOrdTyp = RBA_MEMDIAG_ORDTYP_IGR;
        }
    }

    /* Switch to own order type for single storage blocks */
    /* DATASET blocks are also treated as single storage blocks, because each block is only stored once */
    if ((idxOrdTyp == RBA_MEMDIAG_ORDTYP_READ)
            && (NvM_Prv_BlockDescriptors_acst[BlockId].BlockManagementType_en != NVM_BLOCK_REDUNDANT))
    {
        idxOrdTyp = RBA_MEMDIAG_ORDTYP_READSNG;
    }

    /* Provide block number for dignosis signals */
    nrBlkIdSig = (BlockId & RBA_MEMDIAG_SIGNAL_BLKID_MSK) | RBA_MEMDIAG_SIGNAL_NVM;

    /* Call common diagnosis handler */
    rba_MemDiag_HndlDiagClbck(idxOrdTyp, idxOrdRes, nrBlkIdSig);

    return E_OK;
}

/** ********************************************************************************************************************
 * \brief Common handler for diagnosis callbacks
 *
 * Sets and resets global flags for cyclic process.
 *
 * \param   nrOrdTyp        Type of order
 * \param   stOrd           Result of order
 * \param   nrBlkIdSig      Block id for environmental signal
 * \return  none
 ******************************************************************************************************************** */
LOCAL_INLINE void rba_MemDiag_HndlDiagClbck(rba_MemDiag_OrdTyp_ten idxOrdTyp, rba_MemDiag_OrdRes_ten idxOrdRes, uint16 nrBlkIdSig)
{
    switch (idxOrdTyp)
    {
        /* Read order finished */
        case RBA_MEMDIAG_ORDTYP_READ:
        {
            switch (idxOrdRes)
            {
                /* Read order successful */
                case RBA_MEMDIAG_ORDRES_SUC:
                {
                    /* Trigger update of Dem event */
                    rba_MemDiag_flgRstReadErr = TRUE;
                    break;
                }

                /* Read order failed */
                case RBA_MEMDIAG_ORDRES_FAIL:
                {
                    /* Provide most revent block with error */
                    rba_MemDiag_nrLstReadErr = nrBlkIdSig;

                    /* Trigger update of Dem event */
                    rba_MemDiag_flgSetReadErr = TRUE;
                    rba_MemDiag_flgRstReadErr = FALSE;

                    break;
                }

                /* Read order is ignored */
                default:
                {
                    break;
                }
            }
            break;
        }

        /* Write order finished */
        case RBA_MEMDIAG_ORDTYP_WR:
        {
            switch (idxOrdRes)
            {
                /* Write order successful */
                case RBA_MEMDIAG_ORDRES_SUC:
                {
                    /* Trigger update of Dem event */
                    rba_MemDiag_flgRstWrErr = TRUE;
                    break;
                }

                /* Write order failed */
                case RBA_MEMDIAG_ORDRES_FAIL:
                {
                    /* Provide most revent block with error */
                    rba_MemDiag_nrLstWrErr = nrBlkIdSig;

                    /* Trigger update of Dem event */
                    rba_MemDiag_flgSetWrErr = TRUE;
                    rba_MemDiag_flgRstWrErr = FALSE;

                    break;
                }

                /* Write order is ignored */
                default:
                {
                    break;
                }
            }
            break;
        }

        /* Read order for single storage block finished */
        /* Only for extended memory diagnosis */
        case RBA_MEMDIAG_ORDTYP_READSNG:
        {
            switch (idxOrdRes)
            {
                /* Read order successful */
                case RBA_MEMDIAG_ORDRES_SUC:
                {
                    /* Trigger update of Dem event */
                    rba_MemDiagExtd_flgRstReadSngErr = TRUE;
                    break;
                }

                /* Read order failed */
                case RBA_MEMDIAG_ORDRES_FAIL:
                {
                    /* Provide most revent block with error */
                    rba_MemDiagExtd_nrLstReadSngErr = nrBlkIdSig;

                    /* Trigger update of Dem event */
                    rba_MemDiagExtd_flgSetReadSngErr = TRUE;
                    rba_MemDiagExtd_flgRstReadSngErr = FALSE;

                    break;
                }

                /* Read order is ignored */
                default:
                {
                    break;
                }
            }
            break;
        }

        /* Order is ignored */
        default:
        {
            break;
        }
    }
}

#define RBA_MEMDIAG_STOP_SEC_CODE
#include "rba_MemDiag_MemMap.h"
