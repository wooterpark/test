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


#include "Bfx.h"
#include "Dem.h"
#include "NvM.h"

#include "rba_MemDiag_Prv.h"
#include "BswM_Appl.h"


/* Initial inhibition after reset to avoid loss of events due to reset of fault code memory after flashing */
#define RBA_MEMDIAG_INHBDIAG    (10u) /* 10 = 1s */


#define RBA_MEMDIAG_START_SEC_VAR_CLEARED_8
#include "rba_MemDiag_MemMap.h"

/* Counter for inhibition after reset */
static uint8 rba_MemDiag_cntrInhbDiag;

#define RBA_MEMDIAG_STOP_SEC_VAR_CLEARED_8
#include "rba_MemDiag_MemMap.h"


#define RBA_MEMDIAG_START_SEC_CODE_SLOW
#include "rba_MemDiag_MemMap.h"


/** ********************************************************************************************************************
 * \brief Initialization process for rba_MemDiag
 *
 * Handles stored Dem events of last cycle.
 *
 * \param   none
 * \return  none
 ***************************************************************************************************
 */
void rba_MemDiag_Proc_Ini(void)
{
    NvM_RequestResultType stBlk;
    uint8 stErr;

    /* Restore errors from NvM RAM block */

    if (NvM_GetErrorStatus(NvMConf_NvMBlockDescriptor_rba_MemDiag_StrdErr_Blk, &stBlk) == E_OK)
    {
        if ((stBlk == NVM_REQ_OK) || (stBlk == NVM_REQ_BLOCK_SKIPPED))
        {
            /* Block is available, restore errors from last cycle */
            /* Errors are only restored if no newer error was reported while initialization before */

            stErr = rba_MemDiag_StrdErr.stErr;

            /* Restore write error */
            if (
                    Bfx_GetBit_u8u8_u8(stErr, RBA_MEMDIAG_STERR_WRERR_BP)
                 && (rba_MemDiag_flgSetWrErr == FALSE)
                 )
            {
                /* Provide most revent block with error */
                rba_MemDiag_nrLstWrErr = rba_MemDiag_StrdErr.nrLstWrErr;

                /* Trigger update of Dem event */
                rba_MemDiag_flgSetWrErr = TRUE;
                rba_MemDiag_flgRstWrErr = FALSE;
            }

            /* Restore read error */
            if (
                    Bfx_GetBit_u8u8_u8(stErr, RBA_MEMDIAG_STERR_READERR_BP)
                 && (rba_MemDiag_flgSetReadErr == FALSE)
                 )
            {
                /* Provide most revent block with error */
                rba_MemDiag_nrLstReadErr = rba_MemDiag_StrdErr.nrLstReadErr;

                /* Trigger update of Dem event */
                rba_MemDiag_flgSetReadErr = TRUE;
                rba_MemDiag_flgRstReadErr = FALSE;
            }

            /* Restore read error for single storage block */
            if (
                    Bfx_GetBit_u8u8_u8(stErr, RBA_MEMDIAG_STERR_READSNGERR_BP)
                 && (rba_MemDiagExtd_flgSetReadSngErr == FALSE)
                 )
            {
                /* Provide most revent block with error */
                rba_MemDiagExtd_nrLstReadSngErr = rba_MemDiag_StrdErr.nrLstReadSngErr;

                /* Trigger update of Dem event */
                rba_MemDiagExtd_flgSetReadSngErr = TRUE;
                rba_MemDiagExtd_flgRstReadSngErr = FALSE;
            }
        }
    }

    /* Reset NvM RAM block because data are restored in protected RAM */
    rba_MemDiag_StrdErr.stErr = 0u;
    rba_MemDiag_StrdErr.nrLstWrErr = 0u;
    rba_MemDiag_StrdErr.nrLstReadErr = 0u;
    rba_MemDiag_StrdErr.nrLstReadSngErr = 0u;

    /* Resetted data are most valid data */
    (void) NvM_SetRamBlockStatus(NvMConf_NvMBlockDescriptor_rba_MemDiag_StrdErr_Blk, TRUE);

    SET_rba_MemDiag_flgInhbDiag;
}



/** ********************************************************************************************************************
 * \brief Main cyclic process for rba_MemDiag
 *
 * Handles Dem events for read and write errors.
 *
 * \param   none
 * \return  none
 ***************************************************************************************************
 */
void rba_MemDiag_Proc_100ms(void)
{
    boolean flgEveTstd, flgEveTstdTmp;
    boolean flgEveFaild, flgEveFaildTmp;


    if (rba_MemDiag_cntrInhbDiag < RBA_MEMDIAG_INHBDIAG)
    {
        /* Diagnosis is inhibited after each reset to avoid loss of events due to reset of fault code memory */
        rba_MemDiag_cntrInhbDiag++;
        SET_rba_MemDiag_flgInhbDiag;
    }
    else
    {
        /*
         * Diagnosis is inhibited after Dem is shutted down.
         * No interface to Dem available to get this information.
         * System control states are used for that information
         */

        if (BswM_ModeState_Run_State<=BswM_ModeState_Run_State	)
        {
            SET_rba_MemDiag_flgInhbDiag;
        }
        else
        {
            CLR_rba_MemDiag_flgInhbDiag;
        }
    }

    /* No reporting as long as diagnosis is inhibited
     * No event gets lost, all events until reporting are collected */
    if (!GET_rba_MemDiag_flgInhbDiag)
    {
        /* Failed read event reported by callback */
        if (rba_MemDiag_flgSetReadErr)
        {
            /* Reset flag for callback */
            rba_MemDiag_flgSetReadErr = FALSE;

            /* Report event */
            Dem_ReportErrorStatus(DemConf_DemEventParameter_Event_NvM_ReadErr, DEM_EVENT_STATUS_FAILED);
        }

        /* Successful read event reported by callback */
        if (rba_MemDiag_flgRstReadErr)
        {
            /* Reset flag for callback */
            rba_MemDiag_flgRstReadErr = FALSE;

            /* Report/heal event if not already tested or failed in this cycle */
            flgEveTstd = (
                    (Dem_GetEventTested(DemConf_DemEventParameter_Event_NvM_ReadErr, &flgEveTstdTmp) == E_OK)
                 && (flgEveTstdTmp != FALSE)
                 );
            flgEveFaild = (
                    (Dem_GetEventFailed(DemConf_DemEventParameter_Event_NvM_ReadErr, &flgEveFaildTmp) == E_OK)
                 && (flgEveFaildTmp != FALSE)
                 );
            if ((flgEveTstd == FALSE) || (flgEveFaild == FALSE))
            {
                Dem_ReportErrorStatus(DemConf_DemEventParameter_Event_NvM_ReadErr, DEM_EVENT_STATUS_PASSED);
            }
        }

        /* Failed write event is reported by callback */
        if (rba_MemDiag_flgSetWrErr)
        {
            /* Reset flag for callback */
            rba_MemDiag_flgSetWrErr = FALSE;

            /* Report event */
            Dem_ReportErrorStatus(DemConf_DemEventParameter_Event_NvM_WriteErr, DEM_EVENT_STATUS_FAILED);
        }

        /* Successful write event is reported by callback */
        if (rba_MemDiag_flgRstWrErr)
        {
            /* Reset flag for callback */
            rba_MemDiag_flgRstWrErr = FALSE;

            /* Report/heal event if not already tested or failed in this cycle */
            flgEveTstd = (
                    (Dem_GetEventTested(DemConf_DemEventParameter_Event_NvM_WriteErr, &flgEveTstdTmp) == E_OK)
                 && (flgEveTstdTmp != FALSE)
                 );
            flgEveFaild = (
                    (Dem_GetEventFailed(DemConf_DemEventParameter_Event_NvM_WriteErr, &flgEveFaildTmp) == E_OK)
                 && (flgEveFaildTmp != FALSE)
                 );
            if ((flgEveTstd == FALSE) || (flgEveFaild == FALSE))
            {
                Dem_ReportErrorStatus(DemConf_DemEventParameter_Event_NvM_WriteErr, DEM_EVENT_STATUS_PASSED);
            }
        }
    }
}


/** ********************************************************************************************************************
 * \brief Shutdown process for rba_MemDiag
 *
 * Stores errors occured after Dem_Shutdown.
 *
 * \param   none
 * \return  none
 ***************************************************************************************************
 */
void rba_MemDiag_Shutdown(void)
{
    uint8 stErr = 0u;

    /* Copy data to NvM RAM block */

    if (rba_MemDiag_flgSetWrErr)
    {
        Bfx_SetBit_u8u8(&stErr, RBA_MEMDIAG_STERR_WRERR_BP);
        rba_MemDiag_StrdErr.nrLstWrErr = rba_MemDiag_nrLstWrErr;
    }
    else
    {
        rba_MemDiag_StrdErr.nrLstWrErr = 0u;
    }

    if (rba_MemDiag_flgSetReadErr)
    {
        Bfx_SetBit_u8u8(&stErr, RBA_MEMDIAG_STERR_READERR_BP);
        rba_MemDiag_StrdErr.nrLstReadErr = rba_MemDiag_nrLstReadErr;
    }
    else
    {
        rba_MemDiag_StrdErr.nrLstReadErr = 0u;
    }

    if (rba_MemDiagExtd_flgSetReadSngErr)
    {
        Bfx_SetBit_u8u8(&stErr, RBA_MEMDIAG_STERR_READSNGERR_BP);
        rba_MemDiag_StrdErr.nrLstReadSngErr = rba_MemDiagExtd_nrLstReadSngErr;
    }
    else
    {
        rba_MemDiag_StrdErr.nrLstReadSngErr = 0u;
    }

    rba_MemDiag_StrdErr.stErr = stErr;

    (void) NvM_WriteBlock(NvMConf_NvMBlockDescriptor_rba_MemDiag_StrdErr_Blk, NULL_PTR);
}

#define RBA_MEMDIAG_STOP_SEC_CODE_SLOW
#include "rba_MemDiag_MemMap.h"
