

#include "DcmDspUds_Cdtcs_Inf.h"
/*TESTCODE-START
#include "DcmTest.h"
TESTCODE-END*/
#if ( (DCM_CFG_DSPUDSSUPPORT_ENABLED != DCM_CFG_OFF) && (DCM_CFG_DSP_CONTROLDTCSETTING_ENABLED != DCM_CFG_OFF) )

 #define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
/**
 * @ingroup DCM_TPL
 * DcmAppl_EnableDTCSetting :-\n
 * This api will be invoked after calling "Dem_EnableDTCSetting".The return value from "Dem_EnableDTCSetting"
 * is passed to  DcmAppl_EnableDTCSetting as DtcEnableStatus.Based on the status ,Customer specific operations
 * can be performed.
 * @param[in]     DtcEnableStatus: Value to indicate whether DTC enabling is successful or not.
 * @param[out]    None
 * @retval        None
 *
 */
FUNC (void, DCM_APPL_CODE) DcmAppl_EnableDTCSetting(
													VAR(Dem_ReturnControlDTCSettingType,AUTOMATIC) DtcEnableStatus
													)
{
	/*Customer specific code can be added here*/
	(void)DtcEnableStatus;

	/*TESTCODE-START
	DcmTest_DcmAppl_EnableDTCSetting(DtcEnableStatus);
	TESTCODE-END*/
}
#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
#endif /* (DCM_CFG_DSPUDSSUPPORT_ENABLED != DCM_CFG_OFF) && (DCM_CFG_DSP_CONTROLDTCSETTING_ENABLED != DCM_CFG_OFF) */

