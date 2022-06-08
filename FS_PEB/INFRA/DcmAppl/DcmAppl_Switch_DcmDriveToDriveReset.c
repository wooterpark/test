


#include "DcmCore_DslDsd_Inf.h"
#include "rba_Reset.h"
/*TESTCODE-START
#include "DcmTest.h"
TESTCODE-END*/
#if((DCM_CFG_STORING_ENABLED != DCM_CFG_OFF) && (DCM_CFG_DSPUDSSUPPORT_ENABLED != DCM_CFG_OFF) && (DCM_CFG_DSP_ECURESET_ENABLED != DCM_CFG_OFF) )

#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"

 /**
 * @ingroup DCM_TPL
 * DcmAppl_Switch_DcmDriveToDriveReset :-\n
 * This API is used to notify the application regarding jump to drive to drive.Application can take further actions.
 *
 * @param[in]     None
 * @param[out]    None
 * @retval        None
 *
 */
FUNC(void,DCM_APPL_CODE)  DcmAppl_Switch_DcmDriveToDriveReset(void)
{
	/*TESTCODE-START
	//DcmTest_DcmAppl_Switch_DcmDriveToDriveReset();
	TESTCODE-END*/

}
#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
#endif
