


#ifndef _CANSM_CFG_SCHM_H
#define _CANSM_CFG_SCHM_H

#include "SchM.h"
#include "SchM_Default.h"
//#include "rba_BswSrv.h"

/* If the RTE code generation is Involved please include the below file */
//#include "SchM_CanSM.h"

/* The integrator shall implement the particular services SchM_Enter and SchM_Exit */

/* Since there is currently only one resource used, there is no need to consider the resource name */

LOCAL_INLINE FUNC(void, CANSM_CODE) SchM_Enter_CanSM_BOR_Nw_ModesNoNest(void);
LOCAL_INLINE FUNC(void, CANSM_CODE) SchM_Exit_CanSM_BOR_Nw_ModesNoNest(void);

LOCAL_INLINE FUNC(void, CANSM_CODE) SchM_Enter_CanSM_BaudModesNoNest(void);
LOCAL_INLINE FUNC(void, CANSM_CODE) SchM_Exit_CanSM_BaudModesNoNest(void);

LOCAL_INLINE FUNC(void, CANSM_CODE) SchM_Enter_CanSM_GetMutexNoNest(void);
LOCAL_INLINE FUNC(void, CANSM_CODE) SchM_Exit_CanSM_GetMutexNoNest(void);


LOCAL_INLINE FUNC(void, CANSM_CODE) SchM_Enter_CanSM_BOR_Nw_ModesNoNest(void)
{
    /* The integrator shall place here the code which would lock the interrupts */
    SCHM_ENTER_DEFAULT();
}

LOCAL_INLINE FUNC(void, CANSM_CODE) SchM_Exit_CanSM_BOR_Nw_ModesNoNest(void)
{
    /* The integrator shall place here the code which would unlock the interrupts */
    SCHM_EXIT_DEFAULT();
}


LOCAL_INLINE FUNC(void, CANSM_CODE) SchM_Enter_CanSM_BaudModesNoNest(void)
{
    /* The integrator shall place here the code which would lock the interrupts */
    SCHM_ENTER_DEFAULT();
}

LOCAL_INLINE FUNC(void, CANSM_CODE) SchM_Exit_CanSM_BaudModesNoNest(void)
{
    /* The integrator shall place here the code which would unlock the interrupts */
    SCHM_EXIT_DEFAULT();
}


LOCAL_INLINE FUNC(void, CANSM_CODE) SchM_Enter_CanSM_GetMutexNoNest(void)
{
    /* The integrator shall place here the code which would lock the interrupts */
    SCHM_ENTER_DEFAULT();
}

LOCAL_INLINE FUNC(void, CANSM_CODE) SchM_Exit_CanSM_GetMutexNoNest(void)
{
    /* The integrator shall place here the code which would unlock the interrupts */
    SCHM_EXIT_DEFAULT();
}

#endif /* _CANSM_CFG_SCHM_H */


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
