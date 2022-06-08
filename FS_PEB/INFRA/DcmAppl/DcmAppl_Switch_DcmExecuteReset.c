


#include "DcmCore_DslDsd_Inf.h"
/*TESTCODE-START
#include "DcmTest.h"
TESTCODE-END*/
#include "rba_Reset.h"

#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
 /**
 *  @ingroup DCM_TPL
 *  DcmAppl_Switch_DcmExecuteReset :-\n
 *  This API is invoked to notify the application that Dcm shall trigger Ecu Reset soon after this API is called.The application may
 *  do the necessary actions required before reset in this function.The API is called only if RTE is disabled.
 *
 * @param[in]     None
 * @param[out]    None
 * @retval        None
 *
 */
 FUNC(void,DCM_APPL_CODE)  DcmAppl_Switch_DcmExecuteReset(void)
 {
	/*TESTCODE-START
	DcmTest_DcmAppl_Switch_DcmExecuteReset();
	TESTCODE-END*/
	// rba_Reset_Request(RBA_RESET_GRP_CB_E,RBA_RESET_CBPROG_E,0x22);

 }

#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"


