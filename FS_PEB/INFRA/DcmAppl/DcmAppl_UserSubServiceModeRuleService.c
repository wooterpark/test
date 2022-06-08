

#include "DcmCore_DslDsd_Inf.h"
/*TESTCODE-START
#include "DcmTest.h"
TESTCODE-END*/


#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"

 /**
 * @ingroup DCM_TPL
 * DcmAppl_UserSubServiceModeRuleService :-\n
 * This API is invoked to do specific checks on the subfunction parameter before processing the service.The ErrorCode parameter(Nrc_u8) needs to be updated by the application in case of failed checks.
 *
 * @param[in]     Sid_u8 : Service Id under process
 * @param[in]     Subfunc_u8 : Subfunction of the service under process
 * @param[out]    Nrc_u8 : NRC to be set by the application
 * @retval               E_OK   : SubService specific checks passed successfully \n
 * @retval               E_NOT_OK  : SubService specific checks failed\n
 *
 */
FUNC(Std_ReturnType,DCM_APPL_CODE) DcmAppl_UserSubServiceModeRuleService(P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_INTERN_DATA) Nrc_u8, VAR(uint8,AUTOMATIC) Sid_u8,VAR(uint8,AUTOMATIC) Subfunc_u8)
{
	VAR(Std_ReturnType,AUTOMATIC) retVal_u8 = E_OK;
	*Nrc_u8= 0x00;
	/*TESTCODE-START
	retVal_u8=DcmTest_DcmAppl_UserSubServiceModeRuleService(Nrc_u8,Sid_u8,Subfunc_u8);
	TESTCODE-END*/
	return (retVal_u8);
}
#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"

