

#include "DcmCore_DslDsd_Inf.h"
/*TESTCODE-START
#include "DcmTest.h"
TESTCODE-END*/

#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
/**
 * @ingroup DCM_TPL
 * DcmAppl_DcmStartProtocol :-\n
 * With this callback function, application can check whether the conditions for further processing of the protocol identified by the passed ProtocolID.\n
 * Application can reject further processing of requested protocol due to failed conditions.
 *
 * @param[in]       ProtocolID                : Name of the protocol (IDs configured within DCM_PROTOCOL_ID)
 * @param[out]      None
 * @retval          DCM_E_OK                  : conditions in application allows further processing of protocol\n
 * @retval          DCM_E_PROTOCOL_NOT_ALLOWED: conditions in application does not allow further processing of protocol
 */

FUNC(Std_ReturnType,DCM_APPL_CODE) DcmAppl_DcmStartProtocol(VAR(Dcm_ProtocolType,AUTOMATIC) ProtocolID)
{
Std_ReturnType retVal;
retVal = E_OK;
#if (DCM_CFG_RBA_DIAGADAPT_SUPPORT_ENABLED != DCM_CFG_OFF)
    rba_DiagAdapt_StartProtocol(ProtocolID);
#else
    /* dummy code to remove compiler warning. Actual code to be written bu User. */
    (void)(ProtocolID);
#endif
	/*TESTCODE-START
	retVal =  DcmTest_DcmAppl_DcmStartProtocol(ProtocolID);
	TESTCODE-END*/
return (retVal);
}
#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"

