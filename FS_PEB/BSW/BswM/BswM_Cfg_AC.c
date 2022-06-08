/*
***********************************************************************************************************************
* 
* Product Info
* Isolar version: ISOLAR-AB 4.0.2
* Product release version: RTA-BSW 3.1.0
* 
***********************************************************************************************************************
*/


/***********************************************************************************************************************
 * Include files
 **********************************************************************************************************************/
#include "BswM.h"

#if (BSWM_RTE_IN_USE == TRUE)
#include "Rte_BswM.h"
#include "SchM_BswM.h"
#endif
#include "BswM_Prv.h"

/***********************************************************************************************************************
 * Type Definition
 **********************************************************************************************************************/
typedef void (*BswM_Cfg_vFunPtrv_t)(void);
typedef Std_ReturnType (*BswM_Cfg_u8FunPtrv_t)(void);

/* User Include Files */
#include "CanSM_ComM.h"

#include "Mcu.h"

#include "CanIf.h"

#include "Integration.h"

#include "Rte_Main.h"

#include "Can.h"

#include "TJA1145.h"

#include "Fim.h"

#include "CanTp.h"

#include "Xcp.h"

#include "Nvm.h"

#include "WdgM.h"

#include "BswM_Appl.h"

/***********************************************************************************************************************
 * BswMComMAllowCom Action/s Object.
 * # ComMAllowed
 * # NetworkReference
 ***********************************************************************************************************************/
#define BSWM_START_SEC_CONST_UNSPECIFIED 
#include "BswM_Cfg_MemMap.h"

CONST(BswM_Cfg_AC_ComMAllowComType_tst, BSWM_CONST) BswM_Cfg_AC_BswMComMAllowCom_cast[BSWM_NO_OF_AC_COMM_ALLOW_COM] =
{
	{
		/* BswM_AI_ComMCommAllowed_CAN1 */
		TRUE,
		0
	},
	{
		/* BswM_AI_ComMCommAllowed_CAN2 */
		TRUE,
		1
	},
	{
		/* BswM_AI_ComMCommNotAllowed_CAN1 */
		FALSE,
		0
	},
	{
		/* BswM_AI_ComMCommNotAllowed_CAN2 */
		FALSE,
		1
	}
};

#define BSWM_STOP_SEC_CONST_UNSPECIFIED 
#include "BswM_Cfg_MemMap.h"    

/***********************************************************************************************************************
 * BswMComMModeSwitch Action/s Object.
 * # ComMRequestMode
 * # ComUserReference
 ***********************************************************************************************************************/
#define BSWM_START_SEC_CONST_UNSPECIFIED 
#include "BswM_Cfg_MemMap.h"

CONST(BswM_Cfg_AC_ComMModeSwitchType_tst, BSWM_CONST) BswM_Cfg_AC_BswMComMModeSwitch_cast[BSWM_NO_OF_AC_COMM_MODE_SWITCH] =
{
	{
		/* BswM_AI_ComMReqFullComm_User0 */
		BSWM_FULL_COM,
		0
	},
	{
		/* BswM_AI_ComMReqFullComm_User1 */
		BSWM_FULL_COM,
		1
	},
	{
		/* BswM_AI_ComMReqNoComm_User0 */
		BSWM_NO_COM,
		0
	},
	{
		/* BswM_AI_ComMReqNoComm_User1 */
		BSWM_NO_COM,
		1
	}
};

#define BSWM_STOP_SEC_CONST_UNSPECIFIED 
#include "BswM_Cfg_MemMap.h"    

/***********************************************************************************************************************
 * IDs for SchMSwitch Functions.
 * # ID
 ***********************************************************************************************************************/
#define BSWM_START_SEC_CONST_UNSPECIFIED 
#include "BswM_Cfg_MemMap.h"

CONST(BswM_Cfg_AC_SchMSwitchType_tst, BSWM_CONST) BswM_Cfg_AC_BswMSchMSwitch_cast[BSWM_NO_OF_AC_SCHM_SWITCH] =
{
	{
		/* BswM_AI_BswMSwitchAppRun */
		0
	},
	{
		/* BswM_AI_BswMSwitchPostRun */
		1
	},
	{
		/* BswM_AI_BswMSwitchPrepShutdown */
		2
	},
	{
		/* BswM_AI_BswMSwitchRun */
		3
	},
	{
		/* BswM_AI_BswMSwitchShutdown */
		4
	},
	{
		/* BswM_AI_BswMSwitchStartupTwo */
		5
	}
};

#define BSWM_STOP_SEC_CONST_UNSPECIFIED 
#include "BswM_Cfg_MemMap.h"    

#define BSWM_START_SEC_CODE 
#include "BswM_Cfg_MemMap.h"                
/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_SchMSwitch_0_BswM_AI_BswMSwitchAppRun
 * Description     :       SchMSwitch Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       Std_ReturnType
 * Remarks         :   
 *****************************************************************************************/
static FUNC(Std_ReturnType, BSWM_CODE) BswM_Cfg_AC_SchMSwitch_0_BswM_AI_BswMSwitchAppRun (void)
{
	VAR(Std_ReturnType, AUTOMATIC) dataRet_u8 = BSWM_NO_RET_VALUE;
	VAR(Std_ReturnType, AUTOMATIC) action_RetVal_pu8 = BSWM_NO_RET_VALUE;

	/*
	 SchM_Switch_p_o( mode )
	 P = Port name
	 O = Mode Group within the ModeSwitchInterface
	 */

	dataRet_u8 = SchM_Switch_BswM_MDGP_AUTOSAR_BswM_ModeDeclarationGroups_MDG_ECUM_STATE ( RTE_MODE_MDG_ECUM_STATE_ECUM_STATE_APP_RUN );

	/* return whether the action was sucessful or not */
	switch( dataRet_u8 )
	{
		case RTE_E_OK:
		action_RetVal_pu8 = E_OK;
		break;
		case RTE_E_LIMIT:
		action_RetVal_pu8 = E_NOT_OK;
		break;
		default:
		action_RetVal_pu8 = BSWM_NO_RET_VALUE;
		break;
	}

	return action_RetVal_pu8;
}

/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_SchMSwitch_1_BswM_AI_BswMSwitchPostRun
 * Description     :       SchMSwitch Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       Std_ReturnType
 * Remarks         :   
 *****************************************************************************************/
static FUNC(Std_ReturnType, BSWM_CODE) BswM_Cfg_AC_SchMSwitch_1_BswM_AI_BswMSwitchPostRun (void)
{
	VAR(Std_ReturnType, AUTOMATIC) dataRet_u8 = BSWM_NO_RET_VALUE;
	VAR(Std_ReturnType, AUTOMATIC) action_RetVal_pu8 = BSWM_NO_RET_VALUE;

	/*
	 SchM_Switch_p_o( mode )
	 P = Port name
	 O = Mode Group within the ModeSwitchInterface
	 */

	dataRet_u8 = SchM_Switch_BswM_MDGP_AUTOSAR_BswM_ModeDeclarationGroups_MDG_ECUM_STATE ( RTE_MODE_MDG_ECUM_STATE_ECUM_STATE_APP_POST_RUN );

	/* return whether the action was sucessful or not */
	switch( dataRet_u8 )
	{
		case RTE_E_OK:
		action_RetVal_pu8 = E_OK;
		break;
		case RTE_E_LIMIT:
		action_RetVal_pu8 = E_NOT_OK;
		break;
		default:
		action_RetVal_pu8 = BSWM_NO_RET_VALUE;
		break;
	}

	return action_RetVal_pu8;
}

/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_SchMSwitch_2_BswM_AI_BswMSwitchPrepShutdown
 * Description     :       SchMSwitch Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       Std_ReturnType
 * Remarks         :   
 *****************************************************************************************/
static FUNC(Std_ReturnType, BSWM_CODE) BswM_Cfg_AC_SchMSwitch_2_BswM_AI_BswMSwitchPrepShutdown (void)
{
	VAR(Std_ReturnType, AUTOMATIC) dataRet_u8 = BSWM_NO_RET_VALUE;
	VAR(Std_ReturnType, AUTOMATIC) action_RetVal_pu8 = BSWM_NO_RET_VALUE;

	/*
	 SchM_Switch_p_o( mode )
	 P = Port name
	 O = Mode Group within the ModeSwitchInterface
	 */

	dataRet_u8 = SchM_Switch_BswM_MDGP_AUTOSAR_BswM_ModeDeclarationGroups_MDG_ECUM_STATE ( RTE_MODE_MDG_ECUM_STATE_ECUM_STATE_PREP_SHUTDOWN );

	/* return whether the action was sucessful or not */
	switch( dataRet_u8 )
	{
		case RTE_E_OK:
		action_RetVal_pu8 = E_OK;
		break;
		case RTE_E_LIMIT:
		action_RetVal_pu8 = E_NOT_OK;
		break;
		default:
		action_RetVal_pu8 = BSWM_NO_RET_VALUE;
		break;
	}

	return action_RetVal_pu8;
}

/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_SchMSwitch_3_BswM_AI_BswMSwitchRun
 * Description     :       SchMSwitch Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       Std_ReturnType
 * Remarks         :   
 *****************************************************************************************/
static FUNC(Std_ReturnType, BSWM_CODE) BswM_Cfg_AC_SchMSwitch_3_BswM_AI_BswMSwitchRun (void)
{
	VAR(Std_ReturnType, AUTOMATIC) dataRet_u8 = BSWM_NO_RET_VALUE;
	VAR(Std_ReturnType, AUTOMATIC) action_RetVal_pu8 = BSWM_NO_RET_VALUE;

	/*
	 SchM_Switch_p_o( mode )
	 P = Port name
	 O = Mode Group within the ModeSwitchInterface
	 */

	dataRet_u8 = SchM_Switch_BswM_MDGP_AUTOSAR_BswM_ModeDeclarationGroups_MDG_ECUM_STATE ( RTE_MODE_MDG_ECUM_STATE_ECUM_STATE_RUN );

	/* return whether the action was sucessful or not */
	switch( dataRet_u8 )
	{
		case RTE_E_OK:
		action_RetVal_pu8 = E_OK;
		break;
		case RTE_E_LIMIT:
		action_RetVal_pu8 = E_NOT_OK;
		break;
		default:
		action_RetVal_pu8 = BSWM_NO_RET_VALUE;
		break;
	}

	return action_RetVal_pu8;
}

/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_SchMSwitch_4_BswM_AI_BswMSwitchShutdown
 * Description     :       SchMSwitch Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       Std_ReturnType
 * Remarks         :   
 *****************************************************************************************/
static FUNC(Std_ReturnType, BSWM_CODE) BswM_Cfg_AC_SchMSwitch_4_BswM_AI_BswMSwitchShutdown (void)
{
	VAR(Std_ReturnType, AUTOMATIC) dataRet_u8 = BSWM_NO_RET_VALUE;
	VAR(Std_ReturnType, AUTOMATIC) action_RetVal_pu8 = BSWM_NO_RET_VALUE;

	/*
	 SchM_Switch_p_o( mode )
	 P = Port name
	 O = Mode Group within the ModeSwitchInterface
	 */

	dataRet_u8 = SchM_Switch_BswM_MDGP_AUTOSAR_BswM_ModeDeclarationGroups_MDG_ECUM_STATE ( RTE_MODE_MDG_ECUM_STATE_ECUM_STATE_SHUTDOWN );

	/* return whether the action was sucessful or not */
	switch( dataRet_u8 )
	{
		case RTE_E_OK:
		action_RetVal_pu8 = E_OK;
		break;
		case RTE_E_LIMIT:
		action_RetVal_pu8 = E_NOT_OK;
		break;
		default:
		action_RetVal_pu8 = BSWM_NO_RET_VALUE;
		break;
	}

	return action_RetVal_pu8;
}

/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_SchMSwitch_5_BswM_AI_BswMSwitchStartupTwo
 * Description     :       SchMSwitch Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       Std_ReturnType
 * Remarks         :   
 *****************************************************************************************/
static FUNC(Std_ReturnType, BSWM_CODE) BswM_Cfg_AC_SchMSwitch_5_BswM_AI_BswMSwitchStartupTwo (void)
{
	VAR(Std_ReturnType, AUTOMATIC) dataRet_u8 = BSWM_NO_RET_VALUE;
	VAR(Std_ReturnType, AUTOMATIC) action_RetVal_pu8 = BSWM_NO_RET_VALUE;

	/*
	 SchM_Switch_p_o( mode )
	 P = Port name
	 O = Mode Group within the ModeSwitchInterface
	 */

	dataRet_u8 = SchM_Switch_BswM_MDGP_AUTOSAR_BswM_ModeDeclarationGroups_MDG_ECUM_STATE ( RTE_MODE_MDG_ECUM_STATE_ECUM_STATE_STARTUP_TWO );

	/* return whether the action was sucessful or not */
	switch( dataRet_u8 )
	{
		case RTE_E_OK:
		action_RetVal_pu8 = E_OK;
		break;
		case RTE_E_LIMIT:
		action_RetVal_pu8 = E_NOT_OK;
		break;
		default:
		action_RetVal_pu8 = BSWM_NO_RET_VALUE;
		break;
	}

	return action_RetVal_pu8;
}

#define BSWM_STOP_SEC_CODE 
#include "BswM_Cfg_MemMap.h"            

/***********************************************************************************************************************
 * Array of Functions Pointers
 * # FunctionNames
 ***********************************************************************************************************************/
#define BSWM_START_SEC_CONST_UNSPECIFIED 
#include "BswM_Cfg_MemMap.h"             
static CONST(BswM_Cfg_u8FunPtrv_t, BSWM_CONST) BswM_Cfg_AC_BswMSchMSwitch_FunPtr_cafct[BSWM_NO_OF_AC_SCHM_SWITCH] =
{
	&BswM_Cfg_AC_SchMSwitch_0_BswM_AI_BswMSwitchAppRun,
	&BswM_Cfg_AC_SchMSwitch_1_BswM_AI_BswMSwitchPostRun,
	&BswM_Cfg_AC_SchMSwitch_2_BswM_AI_BswMSwitchPrepShutdown,
	&BswM_Cfg_AC_SchMSwitch_3_BswM_AI_BswMSwitchRun,
	&BswM_Cfg_AC_SchMSwitch_4_BswM_AI_BswMSwitchShutdown,
	&BswM_Cfg_AC_SchMSwitch_5_BswM_AI_BswMSwitchStartupTwo
};

#define BSWM_STOP_SEC_CONST_UNSPECIFIED 
#include "BswM_Cfg_MemMap.h"         

/*****************************************************************************************
 * Function name   :       BswM_Cfg_ProcessSchMSwitchFunction
 * Description     :       Determine which SchMSwitch Function to be invoked.
 * Parameter       :       SchMSwitchId
 * Return value    :       Std_ReturnType
 * Remarks         :   
 *****************************************************************************************/
#define BSWM_START_SEC_CODE 
#include "BswM_Cfg_MemMap.h"
FUNC(Std_ReturnType, BSWM_CODE) BswM_Cfg_ProcessSchMSwitchFunction
(
		VAR(uint16, AUTOMATIC) idSchMSwitch_u16
)
{
	VAR(Std_ReturnType, AUTOMATIC) RetVal = BSWM_NO_RET_VALUE;

	/* Check if the idSchMSwitch_u16 is within the array boundary */
	if (idSchMSwitch_u16 < (sizeof(BswM_Cfg_AC_BswMSchMSwitch_FunPtr_cafct) / sizeof(BswM_Cfg_u8FunPtrv_t)))
	{
		RetVal = BswM_Cfg_AC_BswMSchMSwitch_FunPtr_cafct[idSchMSwitch_u16]();
	}
	else
	{
		/* Do Nothing */
	}
	return RetVal;
}
#define BSWM_STOP_SEC_CODE 
#include "BswM_Cfg_MemMap.h"

/***********************************************************************************************************************
 * UserIDs for UserCallout Functions.
 * # UserID
 ***********************************************************************************************************************/
#define BSWM_START_SEC_CONST_UNSPECIFIED 
#include "BswM_Cfg_MemMap.h"

CONST(BswM_Cfg_AC_UserCalloutType_tst, BSWM_CONST) BswM_Cfg_AC_BswMUserCallout_cast[BSWM_NO_OF_AC_USERCALLOUT] =
{
	{
		/* BswMAction_AL_BswMode_FullComm */
		0
	},
	{
		/* BswMAction_AL_BswMode_Godown */
		1
	},
	{
		/* BswMAction_AL_BswMode_InitTwo */
		2
	},
	{
		/* BswMAction_AL_BswMode_ReadAll */
		3
	},
	{
		/* BswMAction_AL_BswMode_Shutdown */
		4
	},
	{
		/* BswMAction_AL_BswMode_StopComm */
		5
	},
	{
		/* BswMAction_Al_SetFlagToSWC */
		6
	},
	{
		/* BswMAction_XcpInit */
		7
	},
	{
		/* BswM_AI_CanIfInit */
		8
	},
	{
		/* BswM_AI_CanSmInit */
		9
	},
	{
		/* BswM_AI_CanTpInit */
		10
	},
	{
		/* BswM_AI_ComInit */
		11
	},
	{
		/* BswM_AI_ComMDeInit */
		12
	},
	{
		/* BswM_AI_ComMInit */
		13
	},
	{
		/* BswM_AI_DcmInit */
		14
	},
	{
		/* BswM_AI_DemInit */
		15
	},
	{
		/* BswM_AI_DemShutdown */
		16
	},
	{
		/* BswM_AI_EcuM_MainFunction */
		17
	},
	{
		/* BswM_AI_FeeRbEndInit */
		18
	},
	{
		/* BswM_AI_FimInit */
		19
	},
	{
		/* BswM_AI_GoDown */
		20
	},
	{
		/* BswM_AI_NvMInit */
		21
	},
	{
		/* BswM_AI_NvMReadAll */
		22
	},
	{
		/* BswM_AI_NvMWriteAll */
		23
	},
	{
		/* BswM_AI_PduRInit */
		24
	},
	{
		/* BswM_AI_RteStop */
		25
	},
	{
		/* BswM_AI_RteTimerStart */
		26
	},
	{
		/* BswM_AI_WdgMInit */
		27
	},
	{
		/* BswM_Al_Wdg2Stop */
		28
	},
	{
		/* BswM_Fee_Init */
		29
	}
};

#define BSWM_STOP_SEC_CONST_UNSPECIFIED 
#include "BswM_Cfg_MemMap.h"    

#define BSWM_START_SEC_CODE 
#include "BswM_Cfg_MemMap.h"                
/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_UserCallout_0_BswMAction_AL_BswMode_FullComm
 * Description     :       UserCallout Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       void
 * Remarks         :   
 *****************************************************************************************/
static FUNC(void, BSWM_CODE) BswM_Cfg_AC_UserCallout_0_BswMAction_AL_BswMode_FullComm (void)
{
	BswM_UserCallout_FullComm();
}

/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_UserCallout_1_BswMAction_AL_BswMode_Godown
 * Description     :       UserCallout Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       void
 * Remarks         :   
 *****************************************************************************************/
static FUNC(void, BSWM_CODE) BswM_Cfg_AC_UserCallout_1_BswMAction_AL_BswMode_Godown (void)
{
	BswM_UserCallout_Godown();
}

/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_UserCallout_2_BswMAction_AL_BswMode_InitTwo
 * Description     :       UserCallout Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       void
 * Remarks         :   
 *****************************************************************************************/
static FUNC(void, BSWM_CODE) BswM_Cfg_AC_UserCallout_2_BswMAction_AL_BswMode_InitTwo (void)
{
	BswM_UserCallout_InitTwo( );
}

/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_UserCallout_3_BswMAction_AL_BswMode_ReadAll
 * Description     :       UserCallout Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       void
 * Remarks         :   
 *****************************************************************************************/
static FUNC(void, BSWM_CODE) BswM_Cfg_AC_UserCallout_3_BswMAction_AL_BswMode_ReadAll (void)
{
	BswM_UserCallout_ReadAll();
}

/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_UserCallout_4_BswMAction_AL_BswMode_Shutdown
 * Description     :       UserCallout Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       void
 * Remarks         :   
 *****************************************************************************************/
static FUNC(void, BSWM_CODE) BswM_Cfg_AC_UserCallout_4_BswMAction_AL_BswMode_Shutdown (void)
{
	BswM_UserCallout_Shutdown();
}

/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_UserCallout_5_BswMAction_AL_BswMode_StopComm
 * Description     :       UserCallout Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       void
 * Remarks         :   
 *****************************************************************************************/
static FUNC(void, BSWM_CODE) BswM_Cfg_AC_UserCallout_5_BswMAction_AL_BswMode_StopComm (void)
{
	BswM_UserCallout_StopComm();
}

/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_UserCallout_6_BswMAction_Al_SetFlagToSWC
 * Description     :       UserCallout Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       void
 * Remarks         :   
 *****************************************************************************************/
static FUNC(void, BSWM_CODE) BswM_Cfg_AC_UserCallout_6_BswMAction_Al_SetFlagToSWC (void)
{
	BswM_UserCallout_SetFlagToSWC();
}

/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_UserCallout_7_BswMAction_XcpInit
 * Description     :       UserCallout Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       void
 * Remarks         :   
 *****************************************************************************************/
static FUNC(void, BSWM_CODE) BswM_Cfg_AC_UserCallout_7_BswMAction_XcpInit (void)
{
	Xcp_Init(0);;
}

/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_UserCallout_8_BswM_AI_CanIfInit
 * Description     :       UserCallout Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       void
 * Remarks         :   
 *****************************************************************************************/
static FUNC(void, BSWM_CODE) BswM_Cfg_AC_UserCallout_8_BswM_AI_CanIfInit (void)
{
	CanIf_Init(NULL_PTR);
}

/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_UserCallout_9_BswM_AI_CanSmInit
 * Description     :       UserCallout Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       void
 * Remarks         :   
 *****************************************************************************************/
static FUNC(void, BSWM_CODE) BswM_Cfg_AC_UserCallout_9_BswM_AI_CanSmInit (void)
{
	CanSM_Init(NULL_PTR);
}

/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_UserCallout_10_BswM_AI_CanTpInit
 * Description     :       UserCallout Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       void
 * Remarks         :   
 *****************************************************************************************/
static FUNC(void, BSWM_CODE) BswM_Cfg_AC_UserCallout_10_BswM_AI_CanTpInit (void)
{
	CanTp_Init(NULL_PTR);
}

/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_UserCallout_11_BswM_AI_ComInit
 * Description     :       UserCallout Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       void
 * Remarks         :   
 *****************************************************************************************/
static FUNC(void, BSWM_CODE) BswM_Cfg_AC_UserCallout_11_BswM_AI_ComInit (void)
{
	Com_Init(NULL_PTR);
}

/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_UserCallout_12_BswM_AI_ComMDeInit
 * Description     :       UserCallout Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       void
 * Remarks         :   
 *****************************************************************************************/
static FUNC(void, BSWM_CODE) BswM_Cfg_AC_UserCallout_12_BswM_AI_ComMDeInit (void)
{
	ComM_DeInit();
}

/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_UserCallout_13_BswM_AI_ComMInit
 * Description     :       UserCallout Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       void
 * Remarks         :   
 *****************************************************************************************/
static FUNC(void, BSWM_CODE) BswM_Cfg_AC_UserCallout_13_BswM_AI_ComMInit (void)
{
	ComM_Init(NULL_PTR);
}

/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_UserCallout_14_BswM_AI_DcmInit
 * Description     :       UserCallout Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       void
 * Remarks         :   
 *****************************************************************************************/
static FUNC(void, BSWM_CODE) BswM_Cfg_AC_UserCallout_14_BswM_AI_DcmInit (void)
{
	Dcm_Init();
}

/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_UserCallout_15_BswM_AI_DemInit
 * Description     :       UserCallout Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       void
 * Remarks         :   
 *****************************************************************************************/
static FUNC(void, BSWM_CODE) BswM_Cfg_AC_UserCallout_15_BswM_AI_DemInit (void)
{
	Dem_Init();
}

/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_UserCallout_16_BswM_AI_DemShutdown
 * Description     :       UserCallout Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       void
 * Remarks         :   
 *****************************************************************************************/
static FUNC(void, BSWM_CODE) BswM_Cfg_AC_UserCallout_16_BswM_AI_DemShutdown (void)
{
	Dem_Shutdown();
}

/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_UserCallout_17_BswM_AI_EcuM_MainFunction
 * Description     :       UserCallout Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       void
 * Remarks         :   
 *****************************************************************************************/
static FUNC(void, BSWM_CODE) BswM_Cfg_AC_UserCallout_17_BswM_AI_EcuM_MainFunction (void)
{
	Loop_EcuM_MainFunction();
}

/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_UserCallout_18_BswM_AI_FeeRbEndInit
 * Description     :       UserCallout Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       void
 * Remarks         :   
 *****************************************************************************************/
static FUNC(void, BSWM_CODE) BswM_Cfg_AC_UserCallout_18_BswM_AI_FeeRbEndInit (void)
{
	Fee_Rb_EndInit();
}

/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_UserCallout_19_BswM_AI_FimInit
 * Description     :       UserCallout Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       void
 * Remarks         :   
 *****************************************************************************************/
static FUNC(void, BSWM_CODE) BswM_Cfg_AC_UserCallout_19_BswM_AI_FimInit (void)
{
	FiM_Init(&FiMConfigSet);
}

/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_UserCallout_20_BswM_AI_GoDown
 * Description     :       UserCallout Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       void
 * Remarks         :   
 *****************************************************************************************/
static FUNC(void, BSWM_CODE) BswM_Cfg_AC_UserCallout_20_BswM_AI_GoDown (void)
{
	EcuM_GoDown(42);
}

/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_UserCallout_21_BswM_AI_NvMInit
 * Description     :       UserCallout Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       void
 * Remarks         :   
 *****************************************************************************************/
static FUNC(void, BSWM_CODE) BswM_Cfg_AC_UserCallout_21_BswM_AI_NvMInit (void)
{
	NvM_Init();
}

/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_UserCallout_22_BswM_AI_NvMReadAll
 * Description     :       UserCallout Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       void
 * Remarks         :   
 *****************************************************************************************/
static FUNC(void, BSWM_CODE) BswM_Cfg_AC_UserCallout_22_BswM_AI_NvMReadAll (void)
{
	IC_BswM_NvM_ReadAll();
}

/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_UserCallout_23_BswM_AI_NvMWriteAll
 * Description     :       UserCallout Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       void
 * Remarks         :   
 *****************************************************************************************/
static FUNC(void, BSWM_CODE) BswM_Cfg_AC_UserCallout_23_BswM_AI_NvMWriteAll (void)
{
	IC_BswM_NvM_WriteAll();
}

/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_UserCallout_24_BswM_AI_PduRInit
 * Description     :       UserCallout Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       void
 * Remarks         :   
 *****************************************************************************************/
static FUNC(void, BSWM_CODE) BswM_Cfg_AC_UserCallout_24_BswM_AI_PduRInit (void)
{
	PduR_Init(&PduR_Config);
}

/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_UserCallout_25_BswM_AI_RteStop
 * Description     :       UserCallout Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       void
 * Remarks         :   
 *****************************************************************************************/
static FUNC(void, BSWM_CODE) BswM_Cfg_AC_UserCallout_25_BswM_AI_RteStop (void)
{
	Rte_Stop();
}

/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_UserCallout_26_BswM_AI_RteTimerStart
 * Description     :       UserCallout Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       void
 * Remarks         :   
 *****************************************************************************************/
static FUNC(void, BSWM_CODE) BswM_Cfg_AC_UserCallout_26_BswM_AI_RteTimerStart (void)
{
	Rte_Start();
}

/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_UserCallout_27_BswM_AI_WdgMInit
 * Description     :       UserCallout Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       void
 * Remarks         :   
 *****************************************************************************************/
static FUNC(void, BSWM_CODE) BswM_Cfg_AC_UserCallout_27_BswM_AI_WdgMInit (void)
{
	WdgM_Init(&WdgM_Config);
}

/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_UserCallout_28_BswM_Al_Wdg2Stop
 * Description     :       UserCallout Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       void
 * Remarks         :   
 *****************************************************************************************/
static FUNC(void, BSWM_CODE) BswM_Cfg_AC_UserCallout_28_BswM_Al_Wdg2Stop (void)
{
	BswM_UserCallback_ExtDogDeInit();
}

/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_UserCallout_29_BswM_Fee_Init
 * Description     :       UserCallout Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       void
 * Remarks         :   
 *****************************************************************************************/
static FUNC(void, BSWM_CODE) BswM_Cfg_AC_UserCallout_29_BswM_Fee_Init (void)
{
	Fee_Init(NULL_PTR);
}

#define BSWM_STOP_SEC_CODE 
#include "BswM_Cfg_MemMap.h"            

/***********************************************************************************************************************
 * Array of Functions Pointers
 * # FunctionNames
 ***********************************************************************************************************************/
#define BSWM_START_SEC_CONST_UNSPECIFIED 
#include "BswM_Cfg_MemMap.h"		     
static CONST(BswM_Cfg_vFunPtrv_t, BSWM_CONST) BswM_Cfg_AC_BswMUserCallout_FunPtr_cafct[BSWM_NO_OF_AC_USERCALLOUT] =
{
	&BswM_Cfg_AC_UserCallout_0_BswMAction_AL_BswMode_FullComm,
	&BswM_Cfg_AC_UserCallout_1_BswMAction_AL_BswMode_Godown,
	&BswM_Cfg_AC_UserCallout_2_BswMAction_AL_BswMode_InitTwo,
	&BswM_Cfg_AC_UserCallout_3_BswMAction_AL_BswMode_ReadAll,
	&BswM_Cfg_AC_UserCallout_4_BswMAction_AL_BswMode_Shutdown,
	&BswM_Cfg_AC_UserCallout_5_BswMAction_AL_BswMode_StopComm,
	&BswM_Cfg_AC_UserCallout_6_BswMAction_Al_SetFlagToSWC,
	&BswM_Cfg_AC_UserCallout_7_BswMAction_XcpInit,
	&BswM_Cfg_AC_UserCallout_8_BswM_AI_CanIfInit,
	&BswM_Cfg_AC_UserCallout_9_BswM_AI_CanSmInit,
	&BswM_Cfg_AC_UserCallout_10_BswM_AI_CanTpInit,
	&BswM_Cfg_AC_UserCallout_11_BswM_AI_ComInit,
	&BswM_Cfg_AC_UserCallout_12_BswM_AI_ComMDeInit,
	&BswM_Cfg_AC_UserCallout_13_BswM_AI_ComMInit,
	&BswM_Cfg_AC_UserCallout_14_BswM_AI_DcmInit,
	&BswM_Cfg_AC_UserCallout_15_BswM_AI_DemInit,
	&BswM_Cfg_AC_UserCallout_16_BswM_AI_DemShutdown,
	&BswM_Cfg_AC_UserCallout_17_BswM_AI_EcuM_MainFunction,
	&BswM_Cfg_AC_UserCallout_18_BswM_AI_FeeRbEndInit,
	&BswM_Cfg_AC_UserCallout_19_BswM_AI_FimInit,
	&BswM_Cfg_AC_UserCallout_20_BswM_AI_GoDown,
	&BswM_Cfg_AC_UserCallout_21_BswM_AI_NvMInit,
	&BswM_Cfg_AC_UserCallout_22_BswM_AI_NvMReadAll,
	&BswM_Cfg_AC_UserCallout_23_BswM_AI_NvMWriteAll,
	&BswM_Cfg_AC_UserCallout_24_BswM_AI_PduRInit,
	&BswM_Cfg_AC_UserCallout_25_BswM_AI_RteStop,
	&BswM_Cfg_AC_UserCallout_26_BswM_AI_RteTimerStart,
	&BswM_Cfg_AC_UserCallout_27_BswM_AI_WdgMInit,
	&BswM_Cfg_AC_UserCallout_28_BswM_Al_Wdg2Stop,
	&BswM_Cfg_AC_UserCallout_29_BswM_Fee_Init
};

#define BSWM_STOP_SEC_CONST_UNSPECIFIED 
#include "BswM_Cfg_MemMap.h"	     

/*****************************************************************************************
 * Function name   :       BswM_Cfg_ProcessUserCalloutFunction
 * Description     :       Determine which UserCallout Function to be invoked.
 * Parameter       :       UserId
 * Return value    :       void
 * Remarks         :   
 *****************************************************************************************/
#define BSWM_START_SEC_CODE 
#include "BswM_Cfg_MemMap.h"
FUNC(void, BSWM_CODE) BswM_Cfg_ProcessUserCalloutFunction
(
		VAR(uint16, AUTOMATIC) idUserCallout_u16
)
{
	/* Check if the idUserCallout_u16 is within the array boundary */
	if (idUserCallout_u16 < (sizeof(BswM_Cfg_AC_BswMUserCallout_FunPtr_cafct) / sizeof(BswM_Cfg_vFunPtrv_t)))
	{
		BswM_Cfg_AC_BswMUserCallout_FunPtr_cafct[idUserCallout_u16]();
	}
	else
	{
		/* Do Nothing */
	}
}
#define BSWM_STOP_SEC_CODE 
#include "BswM_Cfg_MemMap.h"

/**********************************************************************************************************************
 * End of file                                                                                                     
 **********************************************************************************************************************/
