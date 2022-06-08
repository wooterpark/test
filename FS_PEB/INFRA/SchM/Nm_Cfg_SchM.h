


#ifndef NM_CFG_SCHM_H
#define NM_CFG_SCHM_H

/**
 ***************************************************************************************************
 * \moduledescription
 *                      BSW Scheduler header file defining Nm Exclusive areas
 *
 * \scope               This is included only by Nm module
 ***************************************************************************************************
 */

/*
 ***************************************************************************************************
 * Includes
 ***************************************************************************************************
 */
#include "SchM.h"
#include "rba_BswSrv.h"

/* If the RTE code generation is Involved please include the below file */
//#include "SchM_Nm.h"

/*
 ***************************************************************************************************
 * Prototypes
 ***************************************************************************************************
 */

LOCAL_INLINE FUNC(void, NM_CODE) SchM_Enter_Nm_CallbacksNoNest(void);
LOCAL_INLINE FUNC(void, NM_CODE) SchM_Exit_Nm_CallbacksNoNest(void);

LOCAL_INLINE FUNC(void, NM_CODE) SchM_Enter_Nm_MainFunctionNoNest(void);
LOCAL_INLINE FUNC(void, NM_CODE) SchM_Exit_Nm_MainFunctionNoNest(void);


LOCAL_INLINE FUNC(void, NM_CODE) SchM_Enter_Nm_ChangeStateNoNest(void);
LOCAL_INLINE FUNC(void, NM_CODE) SchM_Exit_Nm_ChangeStateNoNest(void);


LOCAL_INLINE FUNC(void, NM_CODE) SchM_Enter_Nm_GetStateNoNest(void);
LOCAL_INLINE FUNC(void, NM_CODE) SchM_Exit_Nm_GetStateNoNest(void);
/* NOTE on Exclusive area SchM_Enter_Nm_CallbacksNoNest:
 *
 * macros to suspend and resume interrupts for Exclusive area
 *
 * */

LOCAL_INLINE FUNC(void, NM_CODE)  SchM_Enter_Nm_CallbacksNoNest(void)
{
    /*The integrator should place the code here which Disables/Locks the interrupt*/
    rba_BswSrv_GetLockCommon();
}

LOCAL_INLINE FUNC(void, NM_CODE) SchM_Exit_Nm_CallbacksNoNest(void)
{
    /*The integrator should place the code here which Enables/Unlocks the interrupt*/
    rba_BswSrv_ReleaseLockCommon();
}

/* NOTE on Exclusive area SchM_Enter_Nm_MainFunctionNoNest:
 *
 * macros to suspend and resume interrupts for Exclusive area
 *
 * */

LOCAL_INLINE FUNC(void, NM_CODE) SchM_Enter_Nm_MainFunctionNoNest(void)
{
    /*The integrator should place the code here which Disables/Locks the interrupt*/
    rba_BswSrv_GetLockCommon();
}

LOCAL_INLINE FUNC(void, NM_CODE) SchM_Exit_Nm_MainFunctionNoNest(void)
{
    /*The integrator should place the code here which Enables/Unlocks the interrupt*/
    rba_BswSrv_ReleaseLockCommon();
}


/* NOTE on Exclusive area SchM_Enter_Nm_ChangeStateNoNest:
 *
 * macros to suspend and resume interrupts for Exclusive area
 *
 * */

LOCAL_INLINE FUNC(void, NM_CODE) SchM_Enter_Nm_ChangeStateNoNest(void)
{
    /*The integrator should place the code here which Disables/Locks the interrupt*/
    rba_BswSrv_GetLockCommon();
}

LOCAL_INLINE FUNC(void, NM_CODE) SchM_Exit_Nm_ChangeStateNoNest(void)
{
    /*The integrator should place the code here which Enables/Unlocks the interrupt*/
    rba_BswSrv_ReleaseLockCommon();
}

/* NOTE on Exclusive area SchM_Enter_Nm_ChangeStateNoNest:
 *
 * macros to suspend and resume interrupts for Exclusive area
 *
 * */

LOCAL_INLINE FUNC(void, NM_CODE) SchM_Enter_Nm_GetStateNoNest(void)
{
    /*The integrator should place the code here which Disables/Locks the interrupt*/
    rba_BswSrv_GetLockCommon();
}

LOCAL_INLINE FUNC(void, NM_CODE) SchM_Exit_Nm_GetStateNoNest(void)
{
    /*The integrator should place the code here which Enables/Unlocks the interrupt*/
    rba_BswSrv_ReleaseLockCommon();
}
#endif /* _NM_CFG_SCHM_H */
