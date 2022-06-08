

#include "DcmCore_DslDsd_Inf.h"
/*TESTCODE-START
#include "DcmTest.h"
TESTCODE-END*/

#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
/**
 *  @ingroup DCM_TPL
 *  DcmAppl_DcmIndicationFuncTpr:-\n
 *  This API is called by DCM if function functional tester present request is received with suppress positive bit set in the request.\n
 *  User has to add code if some action is intended.
 *
 * @param[in]   None
 *
 * @param[out]  None
 *
 * @retval      None
 *
  */
FUNC(void,DCM_APPL_CODE) DcmAppl_DcmIndicationFuncTpr(void)
{
    /* User has to add code if some action is intended */
	/*TESTCODE-START
	DcmTest_DcmAppl_DcmIndicationFuncTpr();
	TESTCODE-END*/
}
#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
