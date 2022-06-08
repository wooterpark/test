

#ifndef FIM_CFG_SCHM_H
#define FIM_CFG_SCHM_H



LOCAL_INLINE FUNC(void, COM_CODE) SchM_Enter_FiM_Monitor_NoNest(void);
LOCAL_INLINE FUNC(void, COM_CODE) SchM_Exit_FiM_Monitor_NoNest(void);



LOCAL_INLINE FUNC(void, COM_CODE) SchM_Enter_FiM_Monitor_NoNest (void)
{
    /*The integrator shall place his code here which would disable/lock the interrupt*/

}

LOCAL_INLINE FUNC(void, COM_CODE) SchM_Exit_FiM_Monitor_NoNest (void)
{
    /*The integrator shall place his code here which would enable/unlock the interrupt*/

}



LOCAL_INLINE FUNC(void, COM_CODE) SchM_Enter_FiM_Status_NoNest(void);
LOCAL_INLINE FUNC(void, COM_CODE) SchM_Exit_FiM_Status_NoNest(void);



LOCAL_INLINE FUNC(void, COM_CODE) SchM_Enter_FiM_Status_NoNest (void)
{
    /*The integrator shall place his code here which would disable/lock the interrupt*/

}

LOCAL_INLINE FUNC(void, COM_CODE) SchM_Exit_FiM_Status_NoNest (void)
{
    /*The integrator shall place his code here which would enable/unlock the interrupt*/

}

#endif /* include protection */

