/*
 * DcmAppl_DcmCheckControlMaskAndState.c
 *
 *  Created on: 2020Äê3ÔÂ26ÈÕ
 *      Author: fujian
 */

#include "DcmDspUds_Rdbi_Inf.h"

#if((DCM_CFG_DSPUDSSUPPORT_ENABLED != DCM_CFG_OFF)&&(DCM_CFG_DSP_IOCBI_ENABLED != DCM_CFG_OFF))

#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
/**
 *  @ingroup DCM_TPL
 *  DcmAppl_DcmCheckControlMaskAndState :-\n
 *  This application function shall be called if there is at-least one valid DID in the multi DID RDBI request to validate the total response length.\n
 *  This function shall be called before reading the Data for the requested DIDs.\n
 *  If the *ErrorCode is updated to be a non zero value, then the same shall be sent from Dcm as the response irrespective of the return value.\n
 *  In case the project does not want to do the length validation, then E_OK should be returned.
 *
 *  @param[in]       dataTotalRespLength_u32  : The total response length in bytes of all DIDs to be read in the current request\n
 *  @param[in]       dataNumOfDids_u16        : The number of valid DIDs in the multi DID request
 *  @param[out]      ErrorCode                : The negative response code to be updated by the application after validating dataTotalRespLength_u32\n
 *
 *  @retval          E_OK - If the project has validated the length successfully\n
 *  @retval          E_NOT_OK - If the length validation is not successful.\n
 *                  (In this case, Dcm shall send NRC0x22 (Conditions Not Correct) if *ErrorCode is not updated)\n
 *
 */
FUNC(Std_ReturnType, DCM_APPL_CODE) DcmAppl_DcmCheckControlMaskAndState(VAR(uint16,AUTOMATIC) nrDID_u16, VAR(uint8,AUTOMATIC) dataIoParam_u8,
													P2CONST(uint8, AUTOMATIC, DCM_APPL_DATA) adrCtlStateAndMask_pcst,VAR(uint16,AUTOMATIC) dataCtlStateAndMaskLen_u16
													)
{
    VAR(Std_ReturnType,AUTOMATIC) retVal = E_OK;
    /*TESTCODE-START
    retVal = DcmAppl_DcmCheckControlMaskAndState(dataTotalRespLength_u32,dataNumOfDids_u16,ErrorCode);
    TESTCODE-END*/

    return(retVal);
}

#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
#endif /* (DCM_CFG_DSP_READDATABYIDENTIFIER_ENABLED != DCM_CFG_OFF) */
