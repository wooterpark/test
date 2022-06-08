

#include "DcmDspUds_Seca_Inf.h"
/*TESTCODE-START
#include "DcmTest.h"
TESTCODE-END*/
#if ( (DCM_CFG_DSPUDSSUPPORT_ENABLED != DCM_CFG_OFF) && (DCM_CFG_DSP_SECURITYACCESS_ENABLED != DCM_CFG_OFF) )

 #define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
/**
 * @ingroup DCM_TPL
 * DcmAppl_DcmSecaValidKey :-\n
 *  If the Key sent by the tester is valid this API called with the index of the security table which contains the security level for which key was sent.
 *  This API is an indication to the application regarding the valid key received.\n
 *  More Information: (Using the API DcmAppl_DcmCompareKey the check for the validity of the key sent from the tester will be performed for the KEY request.
 *  If the key sent from the tester is valid (DcmAppl_DcmCompareKey  returns DCM_E_OK) then the notification is given to application to perform any operations if required.
 *  If all the operations from application is completed, then the function should return E_OK; if something is in progress or if some operations  didn't happen properly,it should return DCM_E_PENDING.
 *  The function should be aware about the return value for the previous call because in case of DCM_E_PENDING, DCM will call the function repeatedly  for the same security level until it gets E_OK.\n
 *
 *  Ex: Tester Sends the key request and DcmAppl_DcmCompareKey returns DCM_E_OK.\n
 *  Notification is given to application that the key is valid (DcmAppl_DcmSecaValidKey)).
 *
 * @param[in]           SecTabIdx  : Index of the Security Table in configuration(Security level).
 * @param[out]          None
 * @retval              E_OK : All the operations are done.
 * @retval              DCM_E_PENDING : Some operations are in progress or if some operations  didn't happen properly.\n
 *
 */
FUNC(Std_ReturnType,DCM_APPL_CODE) DcmAppl_DcmSecaValidKey(VAR(uint8,AUTOMATIC) SecTabIdx)
{
    VAR(Std_ReturnType,AUTOMATIC) retVal = E_OK;
	/* dummy code to remove compiler warning */
    (void)(SecTabIdx);
	/*TESTCODE-START
	retVal = DcmTest_DcmAppl_DcmSecaValidKey(SecTabIdx);
	TESTCODE-END*/
    return(retVal);
}
#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"

#endif /*(DCM_CFG_DSPUDSSUPPORT_ENABLED != DCM_CFG_OFF) && (DCM_CFG_DSP_SECURITYACCESS_ENABLED != DCM_CFG_OFF)*/
