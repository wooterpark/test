

#include "DcmCore_DslDsd_Inf.h"
/*TESTCODE-START
#include "DcmTest.h"
TESTCODE-END*/


#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
 /**
 * @ingroup DCM_TPL
 * DcmAppl_UserServiceModeRuleService :-\n
 * This API is used to do specific checks on the SID before processing the service.The ErrorCode parameter(Nrc_u8) needs to be updated by the application in case of failed checks.
 *
 * @param[in]     Sid_u8 : Service Id under processing
 * @param[out]    Nrc_u8 : NRC to be set by the application
 *
 * @retval               E_OK      : Service specific checks passed successfully \n
 * @retval               E_NOT_OK  : Service specific checks failed\n
 *
 */
FUNC(Std_ReturnType,DCM_APPL_CODE) DcmAppl_UserServiceModeRuleService(P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_INTERN_DATA) Nrc_u8, VAR(uint8,AUTOMATIC) Sid_u8)
{
	VAR(Std_ReturnType,AUTOMATIC) retVal_u8 = E_OK;
	*Nrc_u8= 0x00;
	/*TESTCODE-START
	retVal_u8=DcmTest_DcmAppl_UserServiceModeRuleService(Nrc_u8,Sid_u8);
	TESTCODE-END*/
	return (retVal_u8);
}
#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"


