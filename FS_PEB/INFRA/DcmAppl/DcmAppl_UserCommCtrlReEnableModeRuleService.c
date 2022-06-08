/*
 * DcmAppl_UserCommCtrlReEnableModeRuleService.c
 *
 *  Created on: 2020��3��27��
 *      Author: fujian
 */

#include "DcmDspUds_Cdtcs_Inf.h"
/*TESTCODE-START
#include "DcmTest.h"
TESTCODE-END*/

#if (DCM_CFG_DSP_CONTROLDTCSETTING_ENABLED != DCM_CFG_OFF)

#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"

 /**
 * @ingroup DCM_TPL
 * DcmAppl_UserCommCtrlReEnableModeRuleService :-\n
 * This API is invoked to check for conditions to decide if CommCtrl Mode Rule needs to be enabled
 *
 * @param[in]     None
 * @param[out]    None
 * @retval        E_OK   : Check to decide if the CommCtrl Mode Rule needs to be enabled passed successfully \n
 * @retval        E_NOT_OK  : Check to decide if the CommCtrl Mode Rule needs to be enabled  failed \n
 *
 */
FUNC(Std_ReturnType,DCM_APPL_CODE) DcmAppl_UserCommCtrlReEnableModeRuleService(void)
{
	VAR(Std_ReturnType,AUTOMATIC) retVal_u8 = E_OK;
	/*TESTCODE-START
	retVal_u8=DcmTest_DcmAppl_UserCommCtrlReEnableModeRuleService();
	TESTCODE-END*/
	return (retVal_u8);
}
#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
#endif


