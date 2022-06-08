


#ifndef CANIF_CFG_SCHM_H
#define CANIF_CFG_SCHM_H

#include "SchM.h"
#include "SchM_Default.h"

/* If the RTE code generation is Involved please include the below files */
//#include "SchM_CanIf.h"
//#include "SchM_Can.h"

/* The integrator shall implement the particular services SchM_Enter and SchM_Exit */

/* Since there is currently only one resource used, there is no need to consider the resource name */

LOCAL_INLINE FUNC(void, CANIF_CODE) SchM_Enter_CanIf_TxBufAccessNoNest(void);
LOCAL_INLINE FUNC(void, CANIF_CODE) SchM_Exit_CanIf_TxBufAccessNoNest(void);

LOCAL_INLINE FUNC(void, CANIF_CODE) SchM_Enter_CanIf_RxBufAccessNoNest(void);
LOCAL_INLINE FUNC(void, CANIF_CODE) SchM_Exit_CanIf_RxBufAccessNoNest(void);

LOCAL_INLINE FUNC(void, CANIF_CODE) SchM_Enter_CanIf_ControllerState(void);
LOCAL_INLINE FUNC(void, CANIF_CODE) SchM_Exit_CanIf_ControllerState(void);

LOCAL_INLINE FUNC(void, CANIF_CODE) SchM_Enter_CanIf_NewMsgRxWkpEvtNoNest(void);
LOCAL_INLINE FUNC(void, CANIF_CODE) SchM_Exit_CanIf_NewMsgRxWkpEvtNoNest(void);

LOCAL_INLINE FUNC(void, CANIF_CODE) SchM_Enter_CanIf_TxRxNotifNoNest(void);
LOCAL_INLINE FUNC(void, CANIF_CODE) SchM_Exit_CanIf_TxRxNotifNoNest(void);

LOCAL_INLINE FUNC(void, CANIF_CODE) SchM_Enter_CanIf_DynIdNoNest(void);
LOCAL_INLINE FUNC(void, CANIF_CODE) SchM_Exit_CanIf_DynIdNoNest(void);

LOCAL_INLINE FUNC(void, CANIF_CODE) SchM_Enter_CanIf_PNPduStatusNoNest(void);
LOCAL_INLINE FUNC(void, CANIF_CODE) SchM_Exit_CanIf_PNPduStatusNoNest(void);

LOCAL_INLINE FUNC(void, CANIF_CODE) SchM_Enter_CanIf_TxMuxing(void);
LOCAL_INLINE FUNC(void, CANIF_CODE) SchM_Exit_CanIf_TxMuxing(void);



LOCAL_INLINE FUNC(void, CANIF_CODE) SchM_Enter_CanIf_TxBufAccessNoNest(void)
{
    /* The integrator shall place here the code which would lock the interrupts */
    SCHM_ENTER_DEFAULT();
}

LOCAL_INLINE FUNC(void, CANIF_CODE) SchM_Exit_CanIf_TxBufAccessNoNest(void)
{
    /* The integrator shall place here the code which would unlock the interrupts */
    SCHM_EXIT_DEFAULT();
}


LOCAL_INLINE FUNC(void, CANIF_CODE) SchM_Enter_CanIf_RxBufAccessNoNest(void)
{
    /* The integrator shall place here the code which would lock the interrupts */
    SCHM_ENTER_DEFAULT();
}

LOCAL_INLINE FUNC(void, CANIF_CODE) SchM_Exit_CanIf_RxBufAccessNoNest(void)
{
    /* The integrator shall place here the code which would unlock the interrupts */
    SCHM_EXIT_DEFAULT();
}


LOCAL_INLINE FUNC(void, CANIF_CODE) SchM_Enter_CanIf_ControllerState(void)
{
    /* The integrator shall place here the code which would lock the interrupts */
    SCHM_ENTER_DEFAULT();
}

LOCAL_INLINE FUNC(void, CANIF_CODE) SchM_Exit_CanIf_ControllerState(void)
{
    /* The integrator shall place here the code which would unlock the interrupts */
    SCHM_EXIT_DEFAULT();
}


LOCAL_INLINE FUNC(void, CANIF_CODE) SchM_Enter_CanIf_NewMsgRxWkpEvtNoNest(void)
{
    /* The integrator shall place here the code which would lock the interrupts */
    SCHM_ENTER_DEFAULT();
}

LOCAL_INLINE FUNC(void, CANIF_CODE) SchM_Exit_CanIf_NewMsgRxWkpEvtNoNest(void)
{
    /* The integrator shall place here the code which would unlock the interrupts */
    SCHM_EXIT_DEFAULT();
}


LOCAL_INLINE FUNC(void, CANIF_CODE) SchM_Enter_CanIf_TxRxNotifNoNest(void)
{
    /* The integrator shall place here the code which would lock the interrupts */
    SCHM_ENTER_DEFAULT();
}

LOCAL_INLINE FUNC(void, CANIF_CODE) SchM_Exit_CanIf_TxRxNotifNoNest(void)
{
    /* The integrator shall place here the code which would unlock the interrupts */
    SCHM_EXIT_DEFAULT();
}


LOCAL_INLINE FUNC(void, CANIF_CODE) SchM_Enter_CanIf_DynIdNoNest(void)
{
    /* The integrator shall place here the code which would lock the interrupts */
    SCHM_ENTER_DEFAULT();
}

LOCAL_INLINE FUNC(void, CANIF_CODE) SchM_Exit_CanIf_DynIdNoNest(void)
{
    /* The integrator shall place here the code which would unlock the interrupts */
    SCHM_EXIT_DEFAULT();
}


LOCAL_INLINE FUNC(void, CANIF_CODE) SchM_Enter_CanIf_PNPduStatusNoNest(void)
{
    /* The integrator shall place here the code which would lock the interrupts */
    SCHM_ENTER_DEFAULT();
}

LOCAL_INLINE FUNC(void, CANIF_CODE) SchM_Exit_CanIf_PNPduStatusNoNest(void)
{
    /* The integrator shall place here the code which would unlock the interrupts */
    SCHM_EXIT_DEFAULT();
}


LOCAL_INLINE FUNC(void, CANIF_CODE) SchM_Enter_CanIf_TxMuxing(void)
{
    /* The integrator shall place here the code which would lock the interrupts */
    /*NOTE: This lock shall ensure to disable TX-request and TX-confirmation interrupts since this is used in
     * CanIf_Transmit() and CanIf_TxConfirmation(); else it would affect the TX-multiplexing behaviour.*/
    SCHM_ENTER_DEFAULT();
}

LOCAL_INLINE FUNC(void, CANIF_CODE) SchM_Exit_CanIf_TxMuxing(void)
{
    /* The integrator shall place here the code which would unlock the interrupts */
    SCHM_EXIT_DEFAULT();
}

#endif /* CANIF_CFG_SCHM_H */


/*<BASDKey>
*********************************************************************************************************
* $History___:
*
* P_AR40_14.08.0; 0     01.08.2014 LII2ABT
*   partial check-in for the first version of MVC_D
*
* $
*********************************************************************************************************
</BASDKey>*/
