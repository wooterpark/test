

#ifndef XCP_CFG_SCHM_H
#define XCP_CFG_SCHM_H

// ---- Includes --------------------------------------------------------------
#include "SchM.h"

/* If the RTE code generation is Involved please include the below file */
//#include "SchM_Xcp.h"

#ifndef XCP_CODE
  #define XCP_CODE
#endif

// The integrator shall implement the particular services SchM_Enter and SchM_Exit.

// Since there is currently only one resource used (XCP_RESOURCE), there is no need to consider the resource name


//      standard handling is required here
LOCAL_INLINE FUNC(void, XCP_CODE) SchM_Enter_Xcp_SendingShort(void);
LOCAL_INLINE FUNC(void, XCP_CODE) SchM_Exit_Xcp_SendingShort(void);
LOCAL_INLINE FUNC(void, XCP_CODE) SchM_Enter_Xcp_SendingLong(void);
LOCAL_INLINE FUNC(void, XCP_CODE) SchM_Exit_Xcp_SendingLong(void);
LOCAL_INLINE FUNC(void, XCP_CODE) SchM_Enter_Xcp_DownloadNoNest(void);
LOCAL_INLINE FUNC(void, XCP_CODE) SchM_Exit_Xcp_DownloadNoNest(void);
LOCAL_INLINE FUNC(void, XCP_CODE) SchM_Enter_Xcp_BufferAccessActiveNoNest(void);
LOCAL_INLINE FUNC(void, XCP_CODE) SchM_Exit_Xcp_BufferAccessActiveNoNest(void);
LOCAL_INLINE FUNC(void, XCP_CODE) SchM_Enter_Xcp_EthMainFunc(void);
LOCAL_INLINE FUNC(void, XCP_CODE) SchM_Exit_Xcp_EthMainFunc(void);
LOCAL_INLINE FUNC(void, XCP_CODE) SchM_Enter_Xcp_CanBuffering(void);
LOCAL_INLINE FUNC(void, XCP_CODE) SchM_Exit_Xcp_CanBuffering(void);
LOCAL_INLINE FUNC(void, XCP_CODE) SchM_Enter_Xcp_FrTransmit(void);
LOCAL_INLINE FUNC(void, XCP_CODE) SchM_Exit_Xcp_FrTransmit(void);
LOCAL_INLINE FUNC(void, XCP_CODE) SchM_Enter_Xcp_GetTimestamp(void);
LOCAL_INLINE FUNC(void, XCP_CODE) SchM_Exit_Xcp_GetTimestamp(void);
LOCAL_INLINE FUNC(void, XCP_CODE) SchM_Enter_Xcp_DaqRam(void);
LOCAL_INLINE FUNC(void, XCP_CODE) SchM_Exit_Xcp_DaqRam(void);

LOCAL_INLINE FUNC(void, XCP_CODE) SchM_Enter_Xcp_SendingShort(void)
{
  /* integrator shall place his code for locking/disabling the interrupt */
  /* either fill Xcp_SendingShort OR Xcp_SendingLong */
  /* Xcp_SendingShort is for systems where only very short locks are allowed */
}

LOCAL_INLINE FUNC(void, XCP_CODE) SchM_Exit_Xcp_SendingShort(void)
{
  /* integrator shall place his code for unlocking/enabling the interrupt */
  /* either fill Xcp_SendingShort OR Xcp_SendingLong*/
  /* Xcp_SendingShort is for systems where only very short locks are allowed */
}

LOCAL_INLINE FUNC(void, XCP_CODE) SchM_Enter_Xcp_SendingLong(void)
{
  /* integrator shall place his code for locking/disabling the interrupt */
  /* either fill Xcp_SendingShort OR Xcp_SendingLong */
  /* Xcp_SendingLong is for systems where longer locks are allowed */
}

LOCAL_INLINE FUNC(void, XCP_CODE) SchM_Exit_Xcp_SendingLong(void)
{
  /* integrator shall place his code for unlocking/enabling the interrupt */
  /* either fill Xcp_SendingShort OR Xcp_SendingLong */
  /* Xcp_SendingLong is for systems where longer locks are allowed */
}

LOCAL_INLINE FUNC(void, XCP_CODE) SchM_Enter_Xcp_DownloadNoNest(void)
{
  /* integrator shall place his code for locking/disabling the interrupt */
}

LOCAL_INLINE FUNC(void, XCP_CODE) SchM_Exit_Xcp_DownloadNoNest(void)
{
  /* integrator shall place his code for unlocking/enabling the interrupt */
}

LOCAL_INLINE FUNC(void, XCP_CODE) SchM_Enter_Xcp_BufferAccessActiveNoNest(void)
{
  /* integrator shall place his code for locking/disabling the interrupt */
}

LOCAL_INLINE FUNC(void, XCP_CODE) SchM_Exit_Xcp_BufferAccessActiveNoNest(void)
{
  /* integrator shall place his code for unlocking/enabling the interrupt */
}

LOCAL_INLINE FUNC(void, XCP_CODE) SchM_Enter_Xcp_EthMainFunc(void)
{
  /* integrator shall place his code for locking/disabling the interrupt */
}

LOCAL_INLINE FUNC(void, XCP_CODE) SchM_Exit_Xcp_EthMainFunc(void)
{
  /* integrator shall place his code for unlocking/enabling the interrupt */
}

LOCAL_INLINE FUNC(void, XCP_CODE) SchM_Enter_Xcp_CanBuffering(void)
{
  /* integrator shall place his code for locking/disabling the interrupt */
}

LOCAL_INLINE FUNC(void, XCP_CODE) SchM_Exit_Xcp_CanBuffering(void)
{
  /* integrator shall place his code for unlocking/enabling the interrupt */
}

LOCAL_INLINE FUNC(void, XCP_CODE) SchM_Enter_Xcp_FrTransmit(void)
{
  /* integrator shall place his code for locking/disabling the interrupt */
}

LOCAL_INLINE FUNC(void, XCP_CODE) SchM_Exit_Xcp_FrTransmit(void)
{
  /* integrator shall place his code for unlocking/enabling the interrupt */
}

LOCAL_INLINE FUNC(void, XCP_CODE) SchM_Enter_Xcp_GetTimestamp(void)
{
  /* integrator shall place his code for locking/disabling the interrupt */
}

LOCAL_INLINE FUNC(void, XCP_CODE) SchM_Exit_Xcp_GetTimestamp(void)
{
  /* integrator shall place his code for unlocking/enabling the interrupt */
}

LOCAL_INLINE FUNC(void, XCP_CODE) SchM_Enter_Xcp_DaqRam(void)
{
  /* integrator shall place his code for locking/disabling the interrupt */
}

LOCAL_INLINE FUNC(void, XCP_CODE) SchM_Exit_Xcp_DaqRam(void)
{
  /* integrator shall place his code for unlocking/enabling the interrupt */
}


#endif /* XCP_CFG_SCHM_H */

// -------- END OF FILE -------------------------------------------------------

