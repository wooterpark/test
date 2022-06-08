

 #include "DcmCore_DslDsd_Inf.h"
 /*TESTCODE-START
#include "DcmTest.h"
TESTCODE-END*/

 #define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
 /**
 *  @ingroup DCM_TPL
 *  DcmAppl_DcmGetRxPermission:-\n
 *  This API is called by Dcm_StartOfReception before processing the new request. The use case for such an API is rejection/accepting Rx Requests arriving from particular protocols,
 *  for different variants of the same software.Integrator has to add code to check the receiving protocol based on the passed ProtocolId.\n
 *  The user may return E_NOT_OK if the request is to be rejected. Else, E_OK must be returned.It must be noted that all return values other than E_OK (Including DCM_E_PENDING) are treated alike,
 *  and the request will be rejected for all return values other than E_OK
 *
 * @param[in]     ProtocolId : The protocol id
 * @param[in]     DcmRxPduId : Pdu Id corresponding to the received Pdu
 * @param[in]     TpSduLength : Total message length of the request to be received
 * @param[in]     info : Contains the information about received message
 * @param[out]    None
 * @retval            E_OK      : The Rx Request can be accepted and processed
 * @retval            E_NOT_OK  : The Rx Request is rejected
 *
 */
FUNC(Std_ReturnType,DCM_APPL_CODE) DcmAppl_DcmGetRxPermission (
		VAR(Dcm_ProtocolType, AUTOMATIC) ProtocolId,
		VAR(PduIdType, AUTOMATIC) DcmRxPduId,
		P2CONST(PduInfoType, AUTOMATIC, DCM_APPL_DATA) info,
		VAR(PduLengthType, AUTOMATIC) TpSduLength)
{
	VAR(Std_ReturnType,AUTOMATIC) retVal = E_OK;
	/*User has to add code here to check the receiving protocol based on the passed ProtocolId
	  The user may return E_NOT_OK if the request is to be rejected. Else, E_OK must be returned.
	  It must be noted that all return values other than E_OK (Including DCM_E_PENDING) are treated
	  alike, and the request will be rejected for all return values other than E_OK*/


		if(ProtocolId == DCM_OBD_ON_CAN)
		{
			return (E_NOT_OK);
		}

	/* FC_VariationPoint_END */
	/*TESTCODE-START	TESTCODE-END*/
	//retVal = DcmTest_DcmAppl_DcmGetRxPermission(ProtocolId,DcmRxPduId,info,TpSduLength);

		(void)(ProtocolId);
		(void)(DcmRxPduId);
		(void)(TpSduLength);
		(void)(info);
		return (retVal);
		//return (E_NOT_OK);
}
#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
