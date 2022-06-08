

#include "DcmDspUds_Dsc_Inf.h"
/*TESTCODE-START
#include "DcmTest.h"
TESTCODE-END*/
#if ( (DCM_CFG_DSPUDSSUPPORT_ENABLED != DCM_CFG_OFF) && ( DCM_CFG_DSP_DIAGNOSTICSESSIONCONTROL_ENABLED != DCM_CFG_OFF ) )

#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
/**
 * @ingroup DCM_TPL
 * DcmAppl_Switch_DcmDiagnosticSessionControl :-\n
 * This API is used to notify the application regarding session transition.Application can take further actions according to the
 * session transition.
 *
 *
 * @param[in]   SessionMode : Requested session control type value
 * @param[out]   None
 * @retval       None
 */
FUNC(void,DCM_APPL_CODE) DcmAppl_Switch_DcmDiagnosticSessionControl(VAR(Dcm_SesCtrlType,AUTOMATIC) SessionMode)

{
	(void)(SessionMode);
	/*TESTCODE-START
	 DcmTest_DcmAppl_Switch_DcmDiagnosticSessionControl(SessionMode);
	 TESTCODE-END*/
}
#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
#endif /*( (DCM_CFG_DSPUDSSUPPORT_ENABLED != DCM_CFG_OFF) && ( DCM_CFG_DSP_DIAGNOSTICSESSIONCONTROL_ENABLED != DCM_CFG_OFF ) )*/


