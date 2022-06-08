/*
 * This is a template file. It defines integration functions necessary to complete RTA-BSW.
 * The integrator must complete the templates before deploying software containing functions defined in this file.
 * Once templates have been completed, the integrator should delete the #error line.
 * Note: The integrator is responsible for updates made to this file.
 *
 * To remove the following error define the macro NOT_READY_FOR_TESTING_OR_DEPLOYMENT with a compiler option (e.g. -D NOT_READY_FOR_TESTING_OR_DEPLOYMENT)
 * The removal of the error only allows the user to proceed with the building phase
 */


/*****************************************************************************************
 * Header Includes *
 *****************************************************************************************/

#include "Std_Types.h"
#include "BswM.h"
#include "BswM_Prv.h"
#include "BswM_Appl.h"
#include "Dio.h"//FJ 20200410
#include "Dio_Cfg.h"//FJ 20200410
#include "TJA1043_Drv.h"
/***********************************************************
* Function name: void BswM_Appl_IncompatibleGenerator( void )
* Description: Function called by BswM in case of version incompatibility in the post-build generate.
* This an empty function. User will write the error handler code here.
* Return value: None
* Remarks:
***********************************************************/
BswM_ModeState_t BswM_ModeState_Run_State=BSWM_MODE_ECUM_STATE_STARTUP_ONE;
boolean FlgPostDevDone = FALSE;//FJ 20200410
boolean Kl15signal_State_ON = TRUE;//FJ 20200410

#define BSWM_START_SEC_CODE
#include "BswM_Cfg_MemMap.h"

FUNC(void, BSWM_CODE) BswM_Appl_IncompatibleGenerator( void )
{
    /* Fill the error handling code to handle the version mis-match in the post-build structure */
    return;
}



void BswM_UserCallout_InitTwo(void){BswM_ModeState_Run_State=BSWM_MODE_ECUM_STATE_STARTUP_TWO;}
void BswM_UserCallout_ReadAll(void){BswM_ModeState_Run_State=BSWM_MODE_ECUM_STATE_RUN;}
void BswM_UserCallout_FullComm(void){BswM_ModeState_Run_State=BSWM_MODE_ECUM_STATE_APP_RUN;}
void BswM_UserCallout_StopComm(void){BswM_ModeState_Run_State=BSWM_MODE_ECUM_STATE_APP_POST_RUN;}
void BswM_UserCallout_Shutdown(void){BswM_ModeState_Run_State=BSWM_MODE_ECUM_STATE_PREP_SHUTDOWN;}
void BswM_UserCallout_Godown(void){BswM_ModeState_Run_State=BSWM_MODE_ECUM_STATE_SHUTDOWN;}
void BswM_UserCallout_SetFlagToSWC(void)
{
	/*here to query the state of KL15 signal */
	Kl15signal_State_ON = Dio_ReadChannel(DioConf_DioChannel_DI_KL15_P21_5);

	/*Set the Flag after NvM_WriteAll*/
	if(!Kl15signal_State_ON)
	{
		FlgPostDevDone = TRUE;
		/*Send flag FlgPostDevDone back to SWC*/
		//Rte_Write_SWC_FaultRecord_PP_SWC_FR_CDD_flgPostDrvDone(FlgPostDevDone);
		Rte_Write_SWC_Snapshot_PP_SWC_Snapshot_Snapshot_flgPostDrvDone(FlgPostDevDone);
	}
}
void BswM_UserCallback_ExtDogDeInit(void)
{
	CanTrcv_Sleep();
	WdgM_DeInit();
//	Pws_CoreCfg(WDGIF_OFF_MODE);/*LQ 20201027*/
	Tlf35584SafeWdg_FunctionClosed();/*LQ 20201028*/
}


#define BSWM_STOP_SEC_CODE
#include "BswM_Cfg_MemMap.h"


/*
 **********************************************************************************************************************
*/
