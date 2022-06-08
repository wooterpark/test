


#ifndef CANNM_CFG_SCHM_H
#define CANNM_CFG_SCHM_H

/**
 ***************************************************************************************************
 * \moduledescription
 *                      BSW Scheduler header file defining CanNm Exclusive areas
 *
 * \scope               This is included only by CanNm module
 ***************************************************************************************************
 */

/*
 ***************************************************************************************************
 * Includes
 ***************************************************************************************************
 */

#include "SchM.h"

/* If the RTE code generation is Involved please include the below file */
//#include "SchM_CanNm.h"

/*
 ***************************************************************************************************
 * Prototypes
 ***************************************************************************************************
 */

LOCAL_INLINE FUNC(void, CANNM_CODE) SchM_Enter_CanNm_GetStateNoNest(void);
LOCAL_INLINE FUNC(void, CANNM_CODE) SchM_Exit_CanNm_GetStateNoNest(void);

LOCAL_INLINE FUNC(void, CANNM_CODE) SchM_Enter_CanNm_GetPduDataNoNest(void);
LOCAL_INLINE FUNC(void, CANNM_CODE) SchM_Exit_CanNm_GetPduDataNoNest(void);

LOCAL_INLINE FUNC(void, CANNM_CODE) SchM_Enter_CanNm_ChangeStateNoNest(void);
LOCAL_INLINE FUNC(void, CANNM_CODE) SchM_Exit_CanNm_ChangeStateNoNest(void);

LOCAL_INLINE FUNC(void, CANNM_CODE) SchM_Enter_CanNm_GetUserDataNoNest(void);
LOCAL_INLINE FUNC(void, CANNM_CODE) SchM_Exit_CanNm_GetUserDataNoNest(void);

LOCAL_INLINE FUNC(void, CANNM_CODE) SchM_Enter_CanNm_SetUserDataNoNest(void);
LOCAL_INLINE FUNC(void, CANNM_CODE) SchM_Exit_CanNm_SetUserDataNoNest(void);

LOCAL_INLINE FUNC(void, CANNM_CODE) SchM_Enter_CanNm_MainFunctionNoNest(void);
LOCAL_INLINE FUNC(void, CANNM_CODE) SchM_Exit_CanNm_MainFunctionNoNest(void);

LOCAL_INLINE FUNC(void, CANNM_CODE) SchM_Enter_CanNm_RxIndicationNoNest(void);
LOCAL_INLINE FUNC(void, CANNM_CODE) SchM_Exit_CanNm_RxIndicationNoNest(void);

LOCAL_INLINE FUNC(void, CANNM_CODE) SchM_Enter_CanNm_UpdateTxPduDataNoNest(void);
LOCAL_INLINE FUNC(void, CANNM_CODE) SchM_Exit_CanNm_UpdateTxPduDataNoNest(void);

LOCAL_INLINE FUNC(void, CANNM_CODE) SchM_Enter_CanNm_EnableCommunicationNoNest(void);
LOCAL_INLINE FUNC(void, CANNM_CODE) SchM_Exit_CanNm_EnableCommunicationNoNest(void);

/* NOTE on Exclusive area SchM_Enter_CanNm_GetStateNoNest:
 *
 * macros to suspend and resume interrupts for Exclusive area GETSTATE
 *
 * */

LOCAL_INLINE FUNC(void, CANNM_CODE) SchM_Enter_CanNm_GetStateNoNest (void)
        {
            /*The integrator should place the code here which Disables/Locks the interrupt*/
        }

LOCAL_INLINE FUNC(void, CANNM_CODE) SchM_Exit_CanNm_GetStateNoNest(void)
        {
            /*The integrator should place the code here which Enables/Unlocks the interrupt*/
        }

/* NOTE on Exclusive area SchM_Enter_CanNm_GetPduDataNoNest:
 *
 * macros to suspend and resume interrupts for Exclusive area GETPDUDATA
 *
 * */

LOCAL_INLINE FUNC(void, CANNM_CODE) SchM_Enter_CanNm_GetPduDataNoNest(void)
        {
            /*The integrator should place the code here which Disables/Locks the interrupt*/
        }

LOCAL_INLINE FUNC(void, CANNM_CODE) SchM_Exit_CanNm_GetPduDataNoNest(void)
        {
            /*The integrator should place the code here which Enables/Unlocks the interrupt*/
        }

/* NOTE on Exclusive area SchM_Enter_CanNm_ChangeStateNoNest:
 *
 * macros to suspend and resume interrupts for Exclusive area CHANGESTATE
 *
 * */

LOCAL_INLINE FUNC(void, CANNM_CODE) SchM_Enter_CanNm_ChangeStateNoNest(void)
        {
            /*The integrator should place the code here which Disables/Locks the interrupt*/
        }

LOCAL_INLINE FUNC(void, CANNM_CODE) SchM_Exit_CanNm_ChangeStateNoNest(void)
        {
            /*The integrator should place the code here which Enables/Unlocks the interrupt*/
        }

/* NOTE on Exclusive area SchM_Enter_CanNm_GetUserDataNoNest:
 *
 * macros to suspend and resume interrupts for Exclusive area GETUSERDATA
 *
 * */

LOCAL_INLINE FUNC(void, CANNM_CODE) SchM_Enter_CanNm_GetUserDataNoNest(void)
        {
            /*The integrator should place the code here which Disables/Locks the interrupt*/
        }

LOCAL_INLINE FUNC(void, CANNM_CODE) SchM_Exit_CanNm_GetUserDataNoNest(void)
        {
            /*The integrator should place the code here which Enables/Unlocks the interrupt*/
        }

/* NOTE on Exclusive area SchM_Enter_CanNm_SetUserDataNoNest:
 *
 * macros to suspend and resume interrupts for Exclusive area SETUSERDATA
 *
 * */

LOCAL_INLINE FUNC(void, CANNM_CODE) SchM_Enter_CanNm_SetUserDataNoNest(void)
        {
            /*The integrator should place the code here which Disables/Locks the interrupt*/
        }

LOCAL_INLINE FUNC(void, CANNM_CODE) SchM_Exit_CanNm_SetUserDataNoNest(void)
        {
            /*The integrator should place the code here which Enables/Unlocks the interrupt*/
        }

/* NOTE on Exclusive area SchM_Enter_CanNm_MainFunctionNoNest:
 *
 * macros to suspend and resume interrupts for Exclusive area MAINFUNCTION
 *
 * */

LOCAL_INLINE FUNC(void, CANNM_CODE) SchM_Enter_CanNm_MainFunctionNoNest(void)
        {
            /*The integrator should place the code here which Disables/Locks the interrupt*/
        }

LOCAL_INLINE FUNC(void, CANNM_CODE) SchM_Exit_CanNm_MainFunctionNoNest(void)
        {
            /*The integrator should place the code here which Enables/Unlocks the interrupt*/
        }

/* NOTE on Exclusive area SchM_Enter_CanNm_RxIndicationNoNest:
 *
 * macros to suspend and resume interrupts for Exclusive area RXINDICATION
 *
 * */

LOCAL_INLINE FUNC(void, CANNM_CODE) SchM_Enter_CanNm_RxIndicationNoNest(void)
        {
            /*The integrator should place the code here which Disables/Locks the interrupt*/
        }

LOCAL_INLINE FUNC(void, CANNM_CODE) SchM_Exit_CanNm_RxIndicationNoNest(void)
        {
            /*The integrator should place the code here which Enables/Unlocks the interrupt*/
        }

/* NOTE on Exclusive area SchM_Enter_CanNm_UpdateTxPduDataNoNest:
 *
 * macros to suspend and resume interrupts for Exclusive area UPDATETXPDUDATA
 *
 * */

LOCAL_INLINE FUNC(void, CANNM_CODE) SchM_Enter_CanNm_UpdateTxPduDataNoNest(void)
        {
            /*The integrator should place the code here which Disables/Locks the interrupt*/
        }

LOCAL_INLINE FUNC(void, CANNM_CODE) SchM_Exit_CanNm_UpdateTxPduDataNoNest(void)
        {
            /*The integrator should place the code here which Enables/Unlocks the interrupt*/
        }

/* NOTE on Exclusive area SchM_Enter_CanNm_EnableCommunicationNoNest:
 *
 * macros to suspend and resume interrupts for Exclusive area ENABLECOMMUNICATION
 *
 * */

LOCAL_INLINE FUNC(void, CANNM_CODE) SchM_Enter_CanNm_EnableCommunicationNoNest(void)
        {
            /*The integrator should place the code here which Disables/Locks the interrupt*/
        }

LOCAL_INLINE FUNC(void, CANNM_CODE) SchM_Exit_CanNm_EnableCommunicationNoNest(void)
        {
            /*The integrator should place the code here which Enables/Unlocks the interrupt*/
        }

#endif /* CANNM_CFG_SCHM_H */


