


#include "DcmCore_DslDsd_Inf.h"
/*TESTCODE-START
#include "DcmTest.h"
TESTCODE-END*/
#if(DCM_CFG_STORING_ENABLED != DCM_CFG_OFF)

#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
 /**
 * @ingroup DCM_TPL
 * DcmAppl_Switch_DcmBootLoaderReset :-\n
 * Notify the application regarding Jump to BootLoader.Application can take the further actions.
 *
 * @param[in]     None
 * @param[out]    None
 * @retval        None
 *
 */
 FUNC(void,DCM_APPL_CODE)   DcmAppl_Switch_DcmBootLoaderReset(void)
 {
	/*TESTCODE-START
	DcmTest_DcmAppl_Switch_DcmBootLoaderReset();
	TESTCODE-END*/
 }
#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"

#endif
