

#include "DcmCore_DslDsd_Inf.h"
/*TESTCODE-START
#include "DcmTest.h"
TESTCODE-END*/
#if(DCM_CFG_STORING_ENABLED != DCM_CFG_OFF)

 #define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
/**
 * @ingroup DCM_TPL
 * DcmAppl_DcmGetStoreType :-\n
 * This API is used to retrieve the Type of Storage required by User.
 * This API should return the Storage Type required by the user for Jump to Boot.\n
 *
 * @param[in]       dataBootType_u8 : Posible values are DCM_JUMPTOOEMBOOTLOADER ,DCM_JUMPTOSYSSUPPLIERBOOTLOADER or DCM_JUMPDRIVETODRIVE
 * @param[out]      None
 * @retval          DCM_NOTVALID_TYPE     :  Jump to Boot Not allowed\n
 * @retval          DCM_WARMREQUEST_TYPE  :  Warm Request Type\n
 * @retval          DCM_WARMINIT_TYPE     :  Warm Init Type\n
 * @retval          DCM_WARMRESPONSE_TYPE :  Warm Response Type\n
 */
FUNC(uint8,DCM_APPL_CODE) DcmAppl_DcmGetStoreType(VAR(uint8, AUTOMATIC) dataBootType_u8)
{
	VAR(uint8,AUTOMATIC) retVal = DCM_NOTVALID_TYPE;

	/*TESTCODE-START
	retVal = DcmTest_DcmAppl_DcmGetStoreType(dataBootType_u8);
	TESTCODE-END*/
	retVal=DCM_WARMINIT_TYPE;

	return(retVal);
}
#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"

#endif

