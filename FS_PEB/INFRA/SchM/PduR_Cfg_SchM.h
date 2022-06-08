

#ifndef PDUR_CFG_SCHM_H
#define PDUR_CFG_SCHM_H

#include "SchM.h"
#include "SchM_Default.h"
//#include "rba_BswSrv.h"

/* If the RTE code generation is Involved please include the below file */
//#include "SchM_PduR.h"

// pbt2kor : Looks like too many locks in PduR !!
LOCAL_INLINE FUNC(void, PDUR_CODE) SchM_Enter_PduR_LockTpGatewayBuffer(void);
LOCAL_INLINE FUNC(void, PDUR_CODE) SchM_Exit_PduR_LockTpGatewayBuffer(void);
LOCAL_INLINE FUNC(void, PDUR_CODE) SchM_Enter_PduR_LockDisableRoutingNoNest(void);
LOCAL_INLINE FUNC(void, PDUR_CODE) SchM_Exit_PduR_LockDisableRoutingNoNest(void);
LOCAL_INLINE FUNC(void, PDUR_CODE) SchM_Enter_PduR_LockEnableRoutingNoNest(void);
LOCAL_INLINE FUNC(void, PDUR_CODE) SchM_Exit_PduR_LockEnableRoutingNoNest(void);


LOCAL_INLINE FUNC(void, PDUR_CODE) SchM_Enter_PduR_LockIFGatewayTx(void);
LOCAL_INLINE FUNC(void, PDUR_CODE) SchM_Exit_PduR_LockIFGatewayTx(void);
LOCAL_INLINE FUNC(void, PDUR_CODE) SchM_Enter_PduR_LockIFGatewayTxConf(void);
LOCAL_INLINE FUNC(void, PDUR_CODE) SchM_Exit_PduR_LockIFGatewayTxConf(void);
LOCAL_INLINE FUNC(void, PDUR_CODE) SchM_Enter_PduR_LockTpGatewayCopyRxData(void);
LOCAL_INLINE FUNC(void, PDUR_CODE) SchM_Exit_PduR_LockTpGatewayCopyRxData(void);
LOCAL_INLINE FUNC(void, PDUR_CODE) SchM_Enter_PduR_LockTpGatewayCopyTxDataNoNest(void);
LOCAL_INLINE FUNC(void, PDUR_CODE) SchM_Exit_PduR_LockTpGatewayCopyTxDataNoNest(void);
LOCAL_INLINE FUNC(void, PDUR_CODE) SchM_Enter_PduR_LockIFGatewayTriggerTxNoNest(void);
LOCAL_INLINE FUNC(void, PDUR_CODE) SchM_Exit_PduR_LockIFGatewayTriggerTxNoNest(void);
LOCAL_INLINE FUNC(void, PDUR_CODE) SchM_Enter_PduR_LockIFGatewayTriggerTxConf(void);
LOCAL_INLINE FUNC(void, PDUR_CODE) SchM_Exit_PduR_LockIFGatewayTriggerTxConf(void);
LOCAL_INLINE FUNC(void, PDUR_CODE) SchM_Enter_PduR_LockMcTpTxCopyTxData(void);
LOCAL_INLINE FUNC(void, PDUR_CODE) SchM_Exit_PduR_LockMcTpTxCopyTxData(void);
LOCAL_INLINE FUNC(void, PDUR_CODE) SchM_Enter_PduR_LockMcTpTxConf(void);
LOCAL_INLINE FUNC(void, PDUR_CODE) SchM_Exit_PduR_LockMcTpTxConf(void);
LOCAL_INLINE FUNC(void, PDUR_CODE) SchM_Enter_PduR_LockMCTxConfNoNest(void);
LOCAL_INLINE FUNC(void, PDUR_CODE) SchM_Exit_PduR_LockMCTxConfNoNest(void);
// The integrator shall implement the particular services SchM_Enter and SchM_Exit.

// Since there is currently only one resource used (PDUR_RESOURCE), there is no need to consider the resource name

LOCAL_INLINE FUNC(void, PDUR_CODE) SchM_Enter_PduR_LockIFGatewayTx(void)
{
    /*The integrator shall place his code here which would disable/lock the interrupt*/
    SCHM_ENTER_DEFAULT();
}

LOCAL_INLINE FUNC(void, PDUR_CODE) SchM_Exit_PduR_LockIFGatewayTx(void)
{
    /*The integrator shall place his code here which would disable/lock the interrupt*/
    SCHM_EXIT_DEFAULT();
}

LOCAL_INLINE FUNC(void, PDUR_CODE) SchM_Enter_PduR_LockIFGatewayTxConf(void)
{
    /*The integrator shall place his code here which would disable/lock the interrupt*/
    SCHM_ENTER_DEFAULT();
}

LOCAL_INLINE FUNC(void, PDUR_CODE) SchM_Exit_PduR_LockIFGatewayTxConf(void)
{
    /*The integrator shall place his code here which would disable/lock the interrupt*/
    SCHM_EXIT_DEFAULT();
}

LOCAL_INLINE FUNC(void, PDUR_CODE) SchM_Enter_PduR_LockIFGatewayTriggerTxConf(void)
{
    /*The integrator shall place his code here which would disable/lock the interrupt*/
    SCHM_ENTER_DEFAULT();
}

LOCAL_INLINE FUNC(void, PDUR_CODE) SchM_Exit_PduR_LockIFGatewayTriggerTxConf(void)
{
    /*The integrator shall place his code here which would disable/lock the interrupt*/
    SCHM_EXIT_DEFAULT();
}

LOCAL_INLINE FUNC(void, PDUR_CODE) SchM_Enter_PduR_LockEnableRoutingNoNest(void)
{
    /*The integrator shall place his code here which would disable/lock the interrupt*/
    SCHM_ENTER_DEFAULT();
}

LOCAL_INLINE FUNC(void, PDUR_CODE) SchM_Enter_PduR_LockIFGatewayTriggerTxNoNest(void)
{
    /*The integrator shall place his code here which would disable/lock the interrupt*/
    SCHM_ENTER_DEFAULT();
}

LOCAL_INLINE FUNC(void, PDUR_CODE) SchM_Enter_PduR_LockDisableRoutingNoNest(void)
{
    /*The integrator shall place his code here which would disable/lock the interrupt*/
    SCHM_ENTER_DEFAULT();
}

LOCAL_INLINE FUNC(void, PDUR_CODE) SchM_Exit_PduR_LockDisableRoutingNoNest(void)
{
    /*The integrator shall place his code here which would disable/lock the interrupt*/
    SCHM_EXIT_DEFAULT();
}

LOCAL_INLINE FUNC(void, PDUR_CODE) SchM_Enter_PduR_LockMCTxConfNoNest(void)
{
    /*The integrator shall place his code here which would disable/lock the interrupt*/
    SCHM_ENTER_DEFAULT();
}

LOCAL_INLINE FUNC(void, PDUR_CODE) SchM_Exit_PduR_LockMCTxConfNoNest(void)
{
    /*The integrator shall place his code here which would disable/lock the interrupt*/
    SCHM_EXIT_DEFAULT();
}

LOCAL_INLINE FUNC(void, PDUR_CODE) SchM_Exit_PduR_LockIFGatewayTriggerTxNoNest(void)
{
    /*The integrator shall place his code here which would disable/lock the interrupt*/
    SCHM_EXIT_DEFAULT();
}

LOCAL_INLINE FUNC(void, PDUR_CODE) SchM_Exit_PduR_LockEnableRoutingNoNest(void)
{
    /*The integrator shall place his code here which would disable/lock the interrupt*/
    SCHM_EXIT_DEFAULT();
}

LOCAL_INLINE FUNC(void, PDUR_CODE) SchM_Enter_PduR_LockTpGatewayBuffer(void)
{
    /*The integrator shall place his code here which would disable/lock the interrupt*/
        SCHM_ENTER_DEFAULT();
}

LOCAL_INLINE FUNC(void, PDUR_CODE) SchM_Exit_PduR_LockTpGatewayBuffer(void)
{
    /*The integrator shall place his code here which would disable/lock the interrupt*/
        SCHM_EXIT_DEFAULT();
}

LOCAL_INLINE FUNC(void, PDUR_CODE) SchM_Enter_PduR_LockTpGatewayCopyRxData(void)
{
    /*The integrator shall place his code here which would disable/lock the interrupt*/
        SCHM_ENTER_DEFAULT();
}

LOCAL_INLINE FUNC(void, PDUR_CODE) SchM_Exit_PduR_LockTpGatewayCopyRxData(void)
{
    /*The integrator shall place his code here which would disable/lock the interrupt*/
        SCHM_EXIT_DEFAULT();
}

LOCAL_INLINE FUNC(void, PDUR_CODE) SchM_Enter_PduR_LockMcTpTxCopyTxData(void)
{
    /*The integrator shall place his code here which would disable/lock the interrupt*/
        SCHM_ENTER_DEFAULT();
}

LOCAL_INLINE FUNC(void, PDUR_CODE) SchM_Exit_PduR_LockMcTpTxCopyTxData(void)
{
    /*The integrator shall place his code here which would disable/lock the interrupt*/
        SCHM_EXIT_DEFAULT();
}

LOCAL_INLINE FUNC(void, PDUR_CODE) SchM_Enter_PduR_LockMcTpTxConf(void)
{
    /*The integrator shall place his code here which would disable/lock the interrupt*/
        SCHM_ENTER_DEFAULT();
}

LOCAL_INLINE FUNC(void, PDUR_CODE) SchM_Exit_PduR_LockMcTpTxConf(void)
{
    /*The integrator shall place his code here which would disable/lock the interrupt*/
        SCHM_EXIT_DEFAULT();
}

LOCAL_INLINE FUNC(void, PDUR_CODE) SchM_Enter_PduR_LockTpGatewayCopyTxDataNoNest(void)
{
    /*The integrator shall place his code here which would disable/lock the interrupt*/
        SCHM_ENTER_DEFAULT();
}

LOCAL_INLINE FUNC(void, PDUR_CODE) SchM_Exit_PduR_LockTpGatewayCopyTxDataNoNest(void)
{
    /*The integrator shall place his code here which would disable/lock the interrupt*/
        SCHM_EXIT_DEFAULT();
}

#endif /* PDUR_CFG_SCHM_H */

// -------- END OF FILE -------------------------------------------------------
