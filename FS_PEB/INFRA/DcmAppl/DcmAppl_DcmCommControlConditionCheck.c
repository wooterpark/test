/*
 * DcmAppl_DcmCommControlConditionCheck.c
 *
 *  Created on: 2020Äê3ÔÂ27ÈÕ
 *      Author: fujian
 */

#include "DcmDspUds_Rdbi_Inf.h"

#if((DCM_CFG_DSPUDSSUPPORT_ENABLED != DCM_CFG_OFF)&&(DCM_CFG_DSP_COMMUNICATIONCONTROL_ENABLED != DCM_CFG_OFF))

#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"

FUNC (void, DCM_APPL_CODE) DcmAppl_DcmSwitchCommunicationControl( VAR(uint8,DCM_VAR) NetworkID ,Dcm_CommunicationModeType RequestedMode)
{
	/*if BswMDcmEnable is set to False*/
	/*To Do*/
}
FUNC(Std_ReturnType,DCM_APPL_CODE)  DcmAppl_DcmCommControlConditionCheck(VAR(uint8,AUTOMATIC) ControlType_u8,
                                                                                VAR(uint8,AUTOMATIC) DataCommType_u8,
                                                                                P2CONST(uint8,AUTOMATIC,DCM_INTERN_DATA) RequestData,
                                                                                VAR(uint16,AUTOMATIC) RequestLength,
                                                                                P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_INTERN_DATA) dataNegRespCode_u8 )
																				{
    VAR(Std_ReturnType,AUTOMATIC) retVal = E_OK;
    /*TESTCODE-START
    retVal = DcmTest_DcmAppl_DcmCommControlConditionCheck(dataTotalRespLength_u32,dataNumOfDids_u16,ErrorCode);
    TESTCODE-END*/

    return(retVal);
																				}

#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
#endif /* (DCM_CFG_DSP_READDATABYIDENTIFIER_ENABLED != DCM_CFG_OFF) */
