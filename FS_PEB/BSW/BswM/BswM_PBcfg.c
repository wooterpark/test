/*
***********************************************************************************************************************
* 
* Product Info
* Isolar version: ISOLAR-AB 4.0.2
* Product release version: RTA-BSW 3.1.0
* 
***********************************************************************************************************************
*/

/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
 */
#include "BswM.h"

/*
 **********************************************************************************************************************
 * Defines/Macros
 **********************************************************************************************************************
 */

#define BSWM_CFG_VERSION_INFO  {    /*Version details*/  \
                    6U, /*Vendor Id*/  \
                    42U, /*Module Id*/  \
                    2U, /*SW Major version*/  \
                    0U, /*SW Minor version*/  \
                    0U /*SW Patch version*/  \
               }

/*
 **********************************************************************************************************************
 * Variables
 **********************************************************************************************************************
 */

#define BSWM_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED 
#include "BswM_Cfg_MemMap.h"

static CONST(BswM_Cfg_ActionListType_tst, BSWM_CONST) BswM_Cfg_AL_cast [13];

/* static declaration for Rule Structures */

static CONST(BswM_Cfg_RuleType_tst, BSWM_CONST) BswM_Cfg_Rule_cast[13];

/* Definition for Rule Structures */

static CONST(BswM_Cfg_RuleType_tst, BSWM_CONST) BswM_Cfg_Rule_cast[13]=
{
	{ /*   Rule Structure for the configuration container BswM_AR_AfterRun    */
		BSWM_FALSE,
		&BswM_Cfg_LE_BswM_LE_AfterRun,
		&BswM_Cfg_AL_cast[0], /* trueActionList */
		NULL_PTR
	},
	{ /*   Rule Structure for the configuration container BswM_AR_DcmEnableRxAndTx_CAN0    */
		BSWM_FALSE,
		&BswM_Cfg_LE_BswM_LE_DcmEnableRxAndTx_CAN0,
		&BswM_Cfg_AL_cast[3], /* trueActionList */
		NULL_PTR
	},
	{ /*   Rule Structure for the configuration container BswM_AR_DcmEnableRxDisableTx_CAN0    */
		BSWM_FALSE,
		&BswM_Cfg_LE_BswM_LE_DcmEnableRxDisableTx_CAN0,
		&BswM_Cfg_AL_cast[4], /* trueActionList */
		NULL_PTR
	},
	{ /*   Rule Structure for the configuration container BswM_AR_GoDown    */
		BSWM_FALSE,
		&BswM_Cfg_LE_BswM_LE_GoDown,
		&BswM_Cfg_AL_cast[6], /* trueActionList */
		NULL_PTR
	},
	{ /*   Rule Structure for the configuration container BswM_AR_InitBlockTwo    */
		BSWM_FALSE,
		&BswM_Cfg_LE_BswM_LE_InitBlockTwo,
		&BswM_Cfg_AL_cast[2], /* trueActionList */
		NULL_PTR
	},
	{ /*   Rule Structure for the configuration container BswM_AR_PostRun_Core0    */
		BSWM_FALSE,
		&BswM_Cfg_LE_BswM_LE_PostRun_Core0,
		&BswM_Cfg_AL_cast[10], /* trueActionList */
		NULL_PTR
	},
	{ /*   Rule Structure for the configuration container BswM_AR_ReadAllComplete    */
		BSWM_FALSE,
		&BswM_Cfg_LE_BswM_LE_InitBlockReadAllComplete,
		&BswM_Cfg_AL_cast[1], /* trueActionList */
		NULL_PTR
	},
	{ /*   Rule Structure for the configuration container BswM_AR_Shutdown    */
		BSWM_FALSE,
		&BswM_Cfg_LE_BswM_LE_Shutdown,
		&BswM_Cfg_AL_cast[7], /* trueActionList */
		NULL_PTR
	},
	{ /*   Rule Structure for the configuration container BswM_AR_StartCom    */
		BSWM_FALSE,
		&BswM_Cfg_LE_BswM_LE_StartCom,
		&BswM_Cfg_AL_cast[5], /* trueActionList */
		NULL_PTR
	},
	{ /*   Rule Structure for the configuration container BswM_AR_StartPduGroup_FR    */
		BSWM_FALSE,
		&BswM_Cfg_LE_BswM_LE_StartPduGroup_FR,
		&BswM_Cfg_AL_cast[8], /* trueActionList */
		NULL_PTR
	},
	{ /*   Rule Structure for the configuration container BswM_AR_StartPduGroup_Sys    */
		BSWM_FALSE,
		&BswM_Cfg_LE_BswM_LE_StartPduGroup_Sys,
		&BswM_Cfg_AL_cast[9], /* trueActionList */
		NULL_PTR
	},
	{ /*   Rule Structure for the configuration container BswM_AR_StopPduGroup_FR    */
		BSWM_FALSE,
		&BswM_Cfg_LE_BswM_LE_StopPduGroup_FR,
		&BswM_Cfg_AL_cast[11], /* trueActionList */
		NULL_PTR
	},
	{ /*   Rule Structure for the configuration container BswM_AR_StopPduGroup_Sys    */
		BSWM_FALSE,
		&BswM_Cfg_LE_BswM_LE_StopPduGroup_Sys,
		&BswM_Cfg_AL_cast[12], /* trueActionList */
		NULL_PTR
	}
};

/* ModeRequestPort structure for MRP BswM_MRP_ComM_CAN1. Variant : __KW_COMMON
 * - ModeInit Value Present flag (isModeInitValuePresent_b) 
 * - NetworkID (idNetwork_u8)
 * - ModeInit Value (dataModeInitValue_en)
 * - RequestProcessing (dataReqProcessing_en)
 * - Number of associated rules (nrAssociatedRules_u16)
 * - Reference to ListOfRules Array (adrRulesRef_pu16)
 */
#define BSWM_CFG_BSWM_MRP_COMM_CAN1 { \
        FALSE,      \
        0,       \
        COMM_NO_COMMUNICATION,        \
        BSWM_IMMEDIATE,      \
        0,       \
        NULL_PTR      \
}

/* ModeRequestPort structure for MRP BswM_MRP_ComM_CAN2. Variant : __KW_COMMON
 * - ModeInit Value Present flag (isModeInitValuePresent_b) 
 * - NetworkID (idNetwork_u8)
 * - ModeInit Value (dataModeInitValue_en)
 * - RequestProcessing (dataReqProcessing_en)
 * - Number of associated rules (nrAssociatedRules_u16)
 * - Reference to ListOfRules Array (adrRulesRef_pu16)
 */
#define BSWM_CFG_BSWM_MRP_COMM_CAN2 { \
        FALSE,      \
        1,       \
        COMM_NO_COMMUNICATION,        \
        BSWM_IMMEDIATE,      \
        0,       \
        NULL_PTR      \
}

/* Array of ComM Indication MRP structs. Variant : __KW_COMMON */
#define BSWM_CFG_COMMINDICATION_MRPS {   \
       BSWM_CFG_BSWM_MRP_COMM_CAN1,      \
       BSWM_CFG_BSWM_MRP_COMM_CAN2,      \
}

/*Array of BswMRule indexes associated with ModeReqPort BswM_MRP_DcmRxTx_CAN0. Variant :  __KW_COMMON*/
static CONST(uint16, BSWM_CONST) BswM_Cfg_ListOfRules_BswM_MRP_DcmRxTx_CAN0_cau16[ ] = {1 , 2};

/* ModeRequestPort structure for MRP BswM_MRP_DcmRxTx_CAN0. Variant : __KW_COMMON
 * - ModeInit Value Present flag (isModeInitValuePresent_b) 
 * - NetworkHandleType (idNetwork_u8)
 * - ModeInit Value (dataModeInitValue_en)
 * - RequestProcessing (dataReqProcessing_en)
 * - Number of associated rules (nrAssociatedRules_u16)
 * - Reference to ListOfRules Array (adrRulesRef_pu16)
 */
#define BSWM_CFG_BSWM_MRP_DCMRXTX_CAN0 { \
        FALSE,      \
        0,       \
        DCM_ENABLE_RX_TX_NORM,        \
        BSWM_DEFERRED,      \
        2,       \
        &BswM_Cfg_ListOfRules_BswM_MRP_DcmRxTx_CAN0_cau16[0]        \
}

/* Array of Dcm Com Mode Request MRP structs. Variant : __KW_COMMON */
#define BSWM_CFG_DCMCOMMODEREQ_MRPS {   \
       BSWM_CFG_BSWM_MRP_DCMRXTX_CAN0,      \
}

/* ModeRequestPort structure for MRP BswM_MRP_ApplicationRequestPort_Core0. Variant : __KW_COMMON
 * - ModeInit Value Present flag (isModeInitValuePresent_b) 
 * - UserId (idUser_u16)
 * - Max requested mode (dataModeMax_u16)
 * - ModeInit Value (dataModeInitValue_u16)
 * - RequestProcessing (dataReqProcessing_en)
 * - Number of associated rules (nrAssociatedRules_u16)
 * - Reference to ListOfRules Array (adrRulesRef_pu16)
 */
#define BSWM_CFG_BSWM_MRP_APPLICATIONREQUESTPORT_CORE0 { \
	    FALSE,        \
	    0,   \
	    3,  \
	    0,         \
	    BSWM_DEFERRED,    \
	    0, \
	    NULL_PTR \
}

/*Array of BswMRule indexes associated with ModeReqPort BswM_MRP_StartPduGroup_FR. Variant :  __KW_COMMON*/
static CONST(uint16, BSWM_CONST) BswM_Cfg_ListOfRules_BswM_MRP_StartPduGroup_FR_cau16[ ] = {9};

/* ModeRequestPort structure for MRP BswM_MRP_StartPduGroup_FR. Variant : __KW_COMMON
 * - ModeInit Value Present flag (isModeInitValuePresent_b) 
 * - UserId (idUser_u16)
 * - Max requested mode (dataModeMax_u16)
 * - ModeInit Value (dataModeInitValue_u16)
 * - RequestProcessing (dataReqProcessing_en)
 * - Number of associated rules (nrAssociatedRules_u16)
 * - Reference to ListOfRules Array (adrRulesRef_pu16)
 */
#define BSWM_CFG_BSWM_MRP_STARTPDUGROUP_FR { \
	    FALSE,        \
	    6,   \
	    6,  \
	    0,         \
	    BSWM_IMMEDIATE,    \
	    1, \
	    &BswM_Cfg_ListOfRules_BswM_MRP_StartPduGroup_FR_cau16[0]  \
}

/*Array of BswMRule indexes associated with ModeReqPort BswM_MRP_StartPduGroup_Sys. Variant :  __KW_COMMON*/
static CONST(uint16, BSWM_CONST) BswM_Cfg_ListOfRules_BswM_MRP_StartPduGroup_Sys_cau16[ ] = {10};

/* ModeRequestPort structure for MRP BswM_MRP_StartPduGroup_Sys. Variant : __KW_COMMON
 * - ModeInit Value Present flag (isModeInitValuePresent_b) 
 * - UserId (idUser_u16)
 * - Max requested mode (dataModeMax_u16)
 * - ModeInit Value (dataModeInitValue_u16)
 * - RequestProcessing (dataReqProcessing_en)
 * - Number of associated rules (nrAssociatedRules_u16)
 * - Reference to ListOfRules Array (adrRulesRef_pu16)
 */
#define BSWM_CFG_BSWM_MRP_STARTPDUGROUP_SYS { \
	    FALSE,        \
	    8,   \
	    9,  \
	    0,         \
	    BSWM_IMMEDIATE,    \
	    1, \
	    &BswM_Cfg_ListOfRules_BswM_MRP_StartPduGroup_Sys_cau16[0]  \
}

/*Array of BswMRule indexes associated with ModeReqPort BswM_MRP_StopPduGroup_FR. Variant :  __KW_COMMON*/
static CONST(uint16, BSWM_CONST) BswM_Cfg_ListOfRules_BswM_MRP_StopPduGroup_FR_cau16[ ] = {11};

/* ModeRequestPort structure for MRP BswM_MRP_StopPduGroup_FR. Variant : __KW_COMMON
 * - ModeInit Value Present flag (isModeInitValuePresent_b) 
 * - UserId (idUser_u16)
 * - Max requested mode (dataModeMax_u16)
 * - ModeInit Value (dataModeInitValue_u16)
 * - RequestProcessing (dataReqProcessing_en)
 * - Number of associated rules (nrAssociatedRules_u16)
 * - Reference to ListOfRules Array (adrRulesRef_pu16)
 */
#define BSWM_CFG_BSWM_MRP_STOPPDUGROUP_FR { \
	    FALSE,        \
	    7,   \
	    6,  \
	    0,         \
	    BSWM_IMMEDIATE,    \
	    1, \
	    &BswM_Cfg_ListOfRules_BswM_MRP_StopPduGroup_FR_cau16[0]  \
}

/*Array of BswMRule indexes associated with ModeReqPort BswM_MRP_StopPduGroup_Sys. Variant :  __KW_COMMON*/
static CONST(uint16, BSWM_CONST) BswM_Cfg_ListOfRules_BswM_MRP_StopPduGroup_Sys_cau16[ ] = {12};

/* ModeRequestPort structure for MRP BswM_MRP_StopPduGroup_Sys. Variant : __KW_COMMON
 * - ModeInit Value Present flag (isModeInitValuePresent_b) 
 * - UserId (idUser_u16)
 * - Max requested mode (dataModeMax_u16)
 * - ModeInit Value (dataModeInitValue_u16)
 * - RequestProcessing (dataReqProcessing_en)
 * - Number of associated rules (nrAssociatedRules_u16)
 * - Reference to ListOfRules Array (adrRulesRef_pu16)
 */
#define BSWM_CFG_BSWM_MRP_STOPPDUGROUP_SYS { \
	    FALSE,        \
	    9,   \
	    9,  \
	    0,         \
	    BSWM_IMMEDIATE,    \
	    1, \
	    &BswM_Cfg_ListOfRules_BswM_MRP_StopPduGroup_Sys_cau16[0]  \
}

/*Array of BswMRule indexes associated with ModeReqPort BswM_MRP_BswM_MDG. Variant :  __KW_COMMON*/
static CONST(uint16, BSWM_CONST) BswM_Cfg_ListOfRules_BswM_MRP_BswM_MDG_cau16[ ] = {3 , 4 , 6 , 7 , 8};

/* ModeRequestPort structure for MRP BswM_MRP_BswM_MDG. Variant : __KW_COMMON
 * - ModeInit Value Present flag (isModeInitValuePresent_b) 
 * - UserId (idUser_u16)
 * - Max requested mode (dataModeMax_u16)
 * - ModeInit Value (dataModeInitValue_u16)
 * - RequestProcessing (dataReqProcessing_en)
 * - Number of associated rules (nrAssociatedRules_u16)
 * - Reference to ListOfRules Array (adrRulesRef_pu16)
 */
#define BSWM_CFG_BSWM_MRP_BSWM_MDG { \
        FALSE,        \
        1,    \
        65535,                \
        0,         \
        BSWM_DEFERRED,    \
        5, \
        &BswM_Cfg_ListOfRules_BswM_MRP_BswM_MDG_cau16[0]  \
}

/*Array of BswMRule indexes associated with ModeReqPort BswM_MRP_SWC_RequestAfterRun. Variant :  __KW_COMMON*/
static CONST(uint16, BSWM_CONST) BswM_Cfg_ListOfRules_BswM_MRP_SWC_RequestAfterRun_cau16[ ] = {0};

/* ModeRequestPort structure for MRP BswM_MRP_SWC_RequestAfterRun. Variant : __KW_COMMON
 * - ModeInit Value Present flag (isModeInitValuePresent_b) 
 * - UserId (idUser_u16)
 * - Max requested mode (dataModeMax_u16)
 * - ModeInit Value (dataModeInitValue_u16)
 * - RequestProcessing (dataReqProcessing_en)
 * - Number of associated rules (nrAssociatedRules_u16)
 * - Reference to ListOfRules Array (adrRulesRef_pu16)
 */
#define BSWM_CFG_BSWM_MRP_SWC_REQUESTAFTERRUN { \
        FALSE,        \
        2,    \
        65535,                \
        0,         \
        BSWM_IMMEDIATE,    \
        1, \
        &BswM_Cfg_ListOfRules_BswM_MRP_SWC_RequestAfterRun_cau16[0]  \
}

/*Array of BswMRule indexes associated with ModeReqPort BswM_MRP_SWC_RequestShutDown. Variant :  __KW_COMMON*/
static CONST(uint16, BSWM_CONST) BswM_Cfg_ListOfRules_BswM_MRP_SWC_RequestShutDown_cau16[ ] = {5};

/* ModeRequestPort structure for MRP BswM_MRP_SWC_RequestShutDown. Variant : __KW_COMMON
 * - ModeInit Value Present flag (isModeInitValuePresent_b) 
 * - UserId (idUser_u16)
 * - Max requested mode (dataModeMax_u16)
 * - ModeInit Value (dataModeInitValue_u16)
 * - RequestProcessing (dataReqProcessing_en)
 * - Number of associated rules (nrAssociatedRules_u16)
 * - Reference to ListOfRules Array (adrRulesRef_pu16)
 */
#define BSWM_CFG_BSWM_MRP_SWC_REQUESTSHUTDOWN { \
        FALSE,        \
        3,    \
        65535,                \
        0,         \
        BSWM_DEFERRED,    \
        1, \
        &BswM_Cfg_ListOfRules_BswM_MRP_SWC_RequestShutDown_cau16[0]  \
}

/* Array of GenericRequest MRP structs. Variant : __KW_COMMON */
#define BSWM_CFG_GENERICREQ_MRPS {   \
    BSWM_CFG_BSWM_MRP_APPLICATIONREQUESTPORT_CORE0,      \
    BSWM_CFG_BSWM_MRP_STARTPDUGROUP_FR,      \
    BSWM_CFG_BSWM_MRP_STARTPDUGROUP_SYS,      \
    BSWM_CFG_BSWM_MRP_STOPPDUGROUP_FR,      \
    BSWM_CFG_BSWM_MRP_STOPPDUGROUP_SYS,      \
    BSWM_CFG_BSWM_MRP_BSWM_MDG,      \
    BSWM_CFG_BSWM_MRP_SWC_REQUESTAFTERRUN,      \
    BSWM_CFG_BSWM_MRP_SWC_REQUESTSHUTDOWN,      \
}

/* ModeRequestPort structure for MRP BswM_MRP_NvMReadAllComplete. Variant : __KW_COMMON
 * - Mode Init Value present flag 
 * - Configured NvM Service
 * - Configured/Default Mode Init Value
 * - RequestProcessing Enum - Immediate/Deferred 
 * - Number of rules referring to this MRP 
 * - Pointer to array containing indexes of associated rules
 */
#define BSWM_CFG_BSWM_MRP_NVMREADALLCOMPLETE { \
    FALSE,        \
    BSWM_NVMREADALL,       \
    0,         \
    BSWM_IMMEDIATE,       \
    0,          \
    NULL_PTR \
}

/* ModeRequestPort structure for MRP BswM_MRP_NvMWriteAllComplete. Variant : __KW_COMMON
 * - Mode Init Value present flag 
 * - Configured NvM Service
 * - Configured/Default Mode Init Value
 * - RequestProcessing Enum - Immediate/Deferred 
 * - Number of rules referring to this MRP 
 * - Pointer to array containing indexes of associated rules
 */
#define BSWM_CFG_BSWM_MRP_NVMWRITEALLCOMPLETE { \
    FALSE,        \
    BSWM_NVMWRITEALL,       \
    0,         \
    BSWM_IMMEDIATE,       \
    0,          \
    NULL_PTR \
}

/* Array of NvM BlockRequest MRP structs. Variant : __KW_COMMON */
#define BSWM_CFG_NVMJOBMODEIND_MRPS {   \
    BSWM_CFG_BSWM_MRP_NVMREADALLCOMPLETE,      \
    BSWM_CFG_BSWM_MRP_NVMWRITEALLCOMPLETE,      \
}

/* BswM_Cfg_MRPType_tst : Array of structures for different MRP types. Variant : __KW_COMMON
 */
#define BSWM_CFG_MODEREQPORT {       \
	BSWM_CFG_COMMINDICATION_MRPS,      \
	BSWM_CFG_DCMCOMMODEREQ_MRPS,      \
	BSWM_CFG_GENERICREQ_MRPS,      \
	BSWM_CFG_NVMJOBMODEIND_MRPS,      \
            }

/* ModeArbitration Type structure  
 * - ModeRequestPortType structure (BswM_Cfg_MRPType_tst)
 * - Number of rules configured for the chosen variant 
 * - Pointer to base address of array of rules (BswM_Cfg_RuleType_tst)
 */
#define BSWM_CFG_MODEARBITRATION {      \
        BSWM_CFG_MODEREQPORT,     \
        13, \
        &BswM_Cfg_Rule_cast[0] \
}

/*
 **********************************************************************************************************************
 * Arrays of BswMPduGroupSwitch Group References for the variant  with contents: 
 *   # BswMPduEnableGroupSwitch Reference/References
 *   # BswMPduDisableGroupSwitch Reference/References
 **********************************************************************************************************************
 */

static CONST(Com_IpduGroupIdType, BSWM_CONST) BswM_Cfg_AC_BswM_AI_DcmEnableRxDisableTx_CAN0_BswMPduEnableGrpRef_cau16[1] =
{
	1
};

static CONST(Com_IpduGroupIdType, BSWM_CONST) BswM_Cfg_AC_BswM_AI_StartPduGroup_All_BswMPduEnableGrpRef_cau16[2] =
{
	1,
	3
};

static CONST(Com_IpduGroupIdType, BSWM_CONST) BswM_Cfg_AC_BswM_AI_StartPduGroup_FR_BswMPduEnableGrpRef_cau16[1] =
{
	0
};

static CONST(Com_IpduGroupIdType, BSWM_CONST) BswM_Cfg_AC_BswM_AI_StartPduGroup_Sys_BswMPduEnableGrpRef_cau16[1] =
{
	2
};

static CONST(Com_IpduGroupIdType, BSWM_CONST) BswM_Cfg_AC_BswM_Al_DcmEnableRxAndTx_BswMPduEnableGrpRef_cau16[2] =
{
	3,
	1
};

static CONST(Com_IpduGroupIdType, BSWM_CONST) BswM_Cfg_AC_BswM_AI_DcmEnableRxDisableTx_CAN0_BswMPduDisableGrpRef_cau16[1] =
{
	3
};

static CONST(Com_IpduGroupIdType, BSWM_CONST) BswM_Cfg_AC_BswM_AI_StopPduGroup_All_BswMPduDisableGrpRef_cau16[2] =
{
	1,
	3
};

static CONST(Com_IpduGroupIdType, BSWM_CONST) BswM_Cfg_AC_BswM_AI_StopPduGroup_FR_BswMPduDisableGrpRef_cau16[1] =
{
	0
};

static CONST(Com_IpduGroupIdType, BSWM_CONST) BswM_Cfg_AC_BswM_AI_StopPduGroup_Sys_BswMPduDisableGrpRef_cau16[1] =
{
	2
};

/*
 **********************************************************************************************************************
 * Array of BswMPduRouterControl Action for the variant  with contents: 
 *   # Reinit 
 *   # No of EnabledPduGroupRef
 *   # No of DisabledPduGroupRef
 *   # Base Addr of EnabledPduGroupRef
 *   # Base Addr of DisabledPduGroupRef
 **********************************************************************************************************************
 */

static CONST(BswM_Cfg_AC_PduGroupSwitchType_tst, BSWM_CONST) BswM_Cfg_AC_BswMPduGroupSwitch_cast[BSWM_NO_OF_AC_IPDUGROUPSWITCH] =
{
	{
		/* BswM_AI_DcmEnableRxDisableTx_CAN0 */
		FALSE,
		1,
		1,

		&BswM_Cfg_AC_BswM_AI_DcmEnableRxDisableTx_CAN0_BswMPduEnableGrpRef_cau16[0],

		&BswM_Cfg_AC_BswM_AI_DcmEnableRxDisableTx_CAN0_BswMPduDisableGrpRef_cau16[0]

	},
	{
		/* BswM_AI_StartPduGroup_All */
		FALSE,
		2,
		0,

		&BswM_Cfg_AC_BswM_AI_StartPduGroup_All_BswMPduEnableGrpRef_cau16[0],

		NULL_PTR

	},
	{
		/* BswM_AI_StartPduGroup_FR */
		FALSE,
		1,
		0,

		&BswM_Cfg_AC_BswM_AI_StartPduGroup_FR_BswMPduEnableGrpRef_cau16[0],

		NULL_PTR

	},
	{
		/* BswM_AI_StartPduGroup_Sys */
		FALSE,
		1,
		0,

		&BswM_Cfg_AC_BswM_AI_StartPduGroup_Sys_BswMPduEnableGrpRef_cau16[0],

		NULL_PTR

	},
	{
		/* BswM_AI_StopPduGroup_All */
		FALSE,
		0,
		2,

		NULL_PTR,

		&BswM_Cfg_AC_BswM_AI_StopPduGroup_All_BswMPduDisableGrpRef_cau16[0]

	},
	{
		/* BswM_AI_StopPduGroup_FR */
		FALSE,
		0,
		1,

		NULL_PTR,

		&BswM_Cfg_AC_BswM_AI_StopPduGroup_FR_BswMPduDisableGrpRef_cau16[0]

	},
	{
		/* BswM_AI_StopPduGroup_Sys */
		FALSE,
		0,
		1,

		NULL_PTR,

		&BswM_Cfg_AC_BswM_AI_StopPduGroup_Sys_BswMPduDisableGrpRef_cau16[0]

	},
	{
		/* BswM_Al_DcmEnableRxAndTx */
		FALSE,
		2,
		0,

		&BswM_Cfg_AC_BswM_Al_DcmEnableRxAndTx_BswMPduEnableGrpRef_cau16[0],

		NULL_PTR

	}
};

/*****************************************************************************************
 * Array of ActionListItems for __KW_COMMON with contents:
 * {
 *     AbortOnFailFlag,
 *     ActionListItemType,
 *     PointerToActionListItem
 * }
 *****************************************************************************************/

static CONST(BswM_Cfg_ActionListItemType_tst, BSWM_CONST) BswM_Cfg_AL_BswM_AL_AfterRun_Items_cast [1] =
{
	{
		/* ActionListItemName  :   BswM_ALI_SetFlagToSWC */
		FALSE,
		BSWM_ACTION_USR_CALLOUT,
		&BswM_Cfg_AC_BswMUserCallout_cast[6] /* BswMAction_Al_SetFlagToSWC */
	}
};

static CONST(BswM_Cfg_ActionListItemType_tst, BSWM_CONST) BswM_Cfg_AL_BswM_AL_BswModules_InitListReadAll_Items_cast [14] =
{
	{
		/* ActionListItemName  :   BswM_ALI_CanIfInit */
		FALSE,
		BSWM_ACTION_USR_CALLOUT,
		&BswM_Cfg_AC_BswMUserCallout_cast[8] /* BswM_AI_CanIfInit */
	},
	{
		/* ActionListItemName  :   BswM_ALI_CanSmInit */
		FALSE,
		BSWM_ACTION_USR_CALLOUT,
		&BswM_Cfg_AC_BswMUserCallout_cast[9] /* BswM_AI_CanSmInit */
	},
	{
		/* ActionListItemName  :   BswM_ALI_PduRInit */
		FALSE,
		BSWM_ACTION_USR_CALLOUT,
		&BswM_Cfg_AC_BswMUserCallout_cast[24] /* BswM_AI_PduRInit */
	},
	{
		/* ActionListItemName  :   BswM_ALI_ComInit */
		FALSE,
		BSWM_ACTION_USR_CALLOUT,
		&BswM_Cfg_AC_BswMUserCallout_cast[11] /* BswM_AI_ComInit */
	},
	{
		/* ActionListItemName  :   BswM_ALI_ComMInit */
		FALSE,
		BSWM_ACTION_USR_CALLOUT,
		&BswM_Cfg_AC_BswMUserCallout_cast[13] /* BswM_AI_ComMInit */
	},
	{
		/* ActionListItemName  :   BswM_ALI_BswMRun */
		FALSE,
		BSWM_ACTION_SCHM_SWITCH,
		&BswM_Cfg_AC_BswMSchMSwitch_cast[3] /* BswM_AI_BswMSwitchRun */
	},
	{
		/* ActionListItemName  :   BswM_ActionListItem_CanTpInit */
		FALSE,
		BSWM_ACTION_USR_CALLOUT,
		&BswM_Cfg_AC_BswMUserCallout_cast[10] /* BswM_AI_CanTpInit */
	},
	{
		/* ActionListItemName  :   BswM_ActionListItem_DcmInit */
		FALSE,
		BSWM_ACTION_USR_CALLOUT,
		&BswM_Cfg_AC_BswMUserCallout_cast[14] /* BswM_AI_DcmInit */
	},
	{
		/* ActionListItemName  :   BswM_ActionListItem_FimInit */
		FALSE,
		BSWM_ACTION_USR_CALLOUT,
		&BswM_Cfg_AC_BswMUserCallout_cast[19] /* BswM_AI_FimInit */
	},
	{
		/* ActionListItemName  :   BswM_ActionListItem_DemInit */
		FALSE,
		BSWM_ACTION_USR_CALLOUT,
		&BswM_Cfg_AC_BswMUserCallout_cast[15] /* BswM_AI_DemInit */
	},
	{
		/* ActionListItemName  :   BswM_ALI_XCPinit */
		FALSE,
		BSWM_ACTION_USR_CALLOUT,
		&BswM_Cfg_AC_BswMUserCallout_cast[7] /* BswMAction_XcpInit */
	},
	{
		/* ActionListItemName  :   BswM_ALI_WdgMInit */
		FALSE,
		BSWM_ACTION_USR_CALLOUT,
		&BswM_Cfg_AC_BswMUserCallout_cast[27] /* BswM_AI_WdgMInit */
	},
	{
		/* ActionListItemName  :   BswM_ALI_RteTimerStart */
		FALSE,
		BSWM_ACTION_USR_CALLOUT,
		&BswM_Cfg_AC_BswMUserCallout_cast[26] /* BswM_AI_RteTimerStart */
	},
	{
		/* ActionListItemName  :   BswM_ALI_BswM_Mode_ReadAll */
		FALSE,
		BSWM_ACTION_USR_CALLOUT,
		&BswM_Cfg_AC_BswMUserCallout_cast[3] /* BswMAction_AL_BswMode_ReadAll */
	}
};

static CONST(BswM_Cfg_ActionListItemType_tst, BSWM_CONST) BswM_Cfg_AL_BswM_AL_BswModules_InitListTwo_Items_cast [6] =
{
	{
		/* ActionListItemName  :   BswM_ALI_FeeInit */
		FALSE,
		BSWM_ACTION_USR_CALLOUT,
		&BswM_Cfg_AC_BswMUserCallout_cast[29] /* BswM_Fee_Init */
	},
	{
		/* ActionListItemName  :   BswM_ALI_FeeRbEndInit */
		FALSE,
		BSWM_ACTION_USR_CALLOUT,
		&BswM_Cfg_AC_BswMUserCallout_cast[18] /* BswM_AI_FeeRbEndInit */
	},
	{
		/* ActionListItemName  :   BswM_ALI_NvMInit */
		FALSE,
		BSWM_ACTION_USR_CALLOUT,
		&BswM_Cfg_AC_BswMUserCallout_cast[21] /* BswM_AI_NvMInit */
	},
	{
		/* ActionListItemName  :   BswM_ALI_NvMReadAll */
		FALSE,
		BSWM_ACTION_USR_CALLOUT,
		&BswM_Cfg_AC_BswMUserCallout_cast[22] /* BswM_AI_NvMReadAll */
	},
	{
		/* ActionListItemName  :   BswM_ALI_BswMStartupTwo */
		FALSE,
		BSWM_ACTION_SCHM_SWITCH,
		&BswM_Cfg_AC_BswMSchMSwitch_cast[5] /* BswM_AI_BswMSwitchStartupTwo */
	},
	{
		/* ActionListItemName  :   BswM_ALI_BswM_Mode_InitTwo */
		FALSE,
		BSWM_ACTION_USR_CALLOUT,
		&BswM_Cfg_AC_BswMUserCallout_cast[2] /* BswMAction_AL_BswMode_InitTwo */
	}
};

static CONST(BswM_Cfg_ActionListItemType_tst, BSWM_CONST) BswM_Cfg_AL_BswM_AL_DcmEnableRxAndTx_CAN0_Items_cast [1] =
{
	{
		/* ActionListItemName  :   BswMActionListItem */
		FALSE,
		BSWM_ACTION_PDU_GRP_SWITCH,
		&BswM_Cfg_AC_BswMPduGroupSwitch_cast[7] /* BswM_Al_DcmEnableRxAndTx */
	}
};

static CONST(BswM_Cfg_ActionListItemType_tst, BSWM_CONST) BswM_Cfg_AL_BswM_AL_DcmEnableRxDisableTx_CAN0_Items_cast [1] =
{
	{
		/* ActionListItemName  :   BswMActionListItem */
		FALSE,
		BSWM_ACTION_PDU_GRP_SWITCH,
		&BswM_Cfg_AC_BswMPduGroupSwitch_cast[0] /* BswM_AI_DcmEnableRxDisableTx_CAN0 */
	}
};

static CONST(BswM_Cfg_ActionListItemType_tst, BSWM_CONST) BswM_Cfg_AL_BswM_AL_FullComm_AllBus_Items_cast [7] =
{
	{
		/* ActionListItemName  :   BswM_ALI_StartPdu */
		FALSE,
		BSWM_ACTION_PDU_GRP_SWITCH,
		&BswM_Cfg_AC_BswMPduGroupSwitch_cast[1] /* BswM_AI_StartPduGroup_All */
	},
	{
		/* ActionListItemName  :   BswM_ALI_AllowComm_CAN2 */
		FALSE,
		BSWM_ACTION_COMM_ALLOW_COM,
		&BswM_Cfg_AC_BswMComMAllowCom_cast[1] /* BswM_AI_ComMCommAllowed_CAN2 */
	},
	{
		/* ActionListItemName  :   BswM_ALI_AllowComm_CAN1 */
		FALSE,
		BSWM_ACTION_COMM_ALLOW_COM,
		&BswM_Cfg_AC_BswMComMAllowCom_cast[0] /* BswM_AI_ComMCommAllowed_CAN1 */
	},
	{
		/* ActionListItemName  :   BswM_ALI_RequestComModeUser1 */
		FALSE,
		BSWM_ACTION_COMM_MODE_SWITCH,
		&BswM_Cfg_AC_BswMComMModeSwitch_cast[1] /* BswM_AI_ComMReqFullComm_User1 */
	},
	{
		/* ActionListItemName  :   BswM_ALI_RequestComModeUser0 */
		FALSE,
		BSWM_ACTION_COMM_MODE_SWITCH,
		&BswM_Cfg_AC_BswMComMModeSwitch_cast[0] /* BswM_AI_ComMReqFullComm_User0 */
	},
	{
		/* ActionListItemName  :   BswM_ALI_BswMAppRun */
		FALSE,
		BSWM_ACTION_SCHM_SWITCH,
		&BswM_Cfg_AC_BswMSchMSwitch_cast[0] /* BswM_AI_BswMSwitchAppRun */
	},
	{
		/* ActionListItemName  :   BswM_ALI_BswM_Mode_FullComm */
		FALSE,
		BSWM_ACTION_USR_CALLOUT,
		&BswM_Cfg_AC_BswMUserCallout_cast[0] /* BswMAction_AL_BswMode_FullComm */
	}
};

static CONST(BswM_Cfg_ActionListItemType_tst, BSWM_CONST) BswM_Cfg_AL_BswM_AL_GoDown_Items_cast [5] =
{
	{
		/* ActionListItemName  :   BswM_ALI_RteStop */
		FALSE,
		BSWM_ACTION_USR_CALLOUT,
		&BswM_Cfg_AC_BswMUserCallout_cast[25] /* BswM_AI_RteStop */
	},
	{
		/* ActionListItemName  :   BswM_ALI_Wdg2Stop */
		FALSE,
		BSWM_ACTION_USR_CALLOUT,
		&BswM_Cfg_AC_BswMUserCallout_cast[28] /* BswM_Al_Wdg2Stop */
	},
	{
		/* ActionListItemName  :   BswM_ALI_GoDown */
		FALSE,
		BSWM_ACTION_USR_CALLOUT,
		&BswM_Cfg_AC_BswMUserCallout_cast[20] /* BswM_AI_GoDown */
	},
	{
		/* ActionListItemName  :   BswM_ALI_EcuM_MainFunction */
		FALSE,
		BSWM_ACTION_USR_CALLOUT,
		&BswM_Cfg_AC_BswMUserCallout_cast[17] /* BswM_AI_EcuM_MainFunction */
	},
	{
		/* ActionListItemName  :   BswM_ALI_BswM_Mode_GoDown */
		FALSE,
		BSWM_ACTION_USR_CALLOUT,
		&BswM_Cfg_AC_BswMUserCallout_cast[1] /* BswMAction_AL_BswMode_Godown */
	}
};

static CONST(BswM_Cfg_ActionListItemType_tst, BSWM_CONST) BswM_Cfg_AL_BswM_AL_Shutdown_Items_cast [5] =
{
	{
		/* ActionListItemName  :   BswM_ALI_Dem_Shutdown */
		FALSE,
		BSWM_ACTION_USR_CALLOUT,
		&BswM_Cfg_AC_BswMUserCallout_cast[16] /* BswM_AI_DemShutdown */
	},
	{
		/* ActionListItemName  :   BswM_ALI_NvM_WriteAll */
		FALSE,
		BSWM_ACTION_USR_CALLOUT,
		&BswM_Cfg_AC_BswMUserCallout_cast[23] /* BswM_AI_NvMWriteAll */
	},
	{
		/* ActionListItemName  :   BswM_ALI_ComMDeInit */
		FALSE,
		BSWM_ACTION_USR_CALLOUT,
		&BswM_Cfg_AC_BswMUserCallout_cast[12] /* BswM_AI_ComMDeInit */
	},
	{
		/* ActionListItemName  :   BswM_ALI_BswMShutdown */
		FALSE,
		BSWM_ACTION_SCHM_SWITCH,
		&BswM_Cfg_AC_BswMSchMSwitch_cast[4] /* BswM_AI_BswMSwitchShutdown */
	},
	{
		/* ActionListItemName  :   BswM_ALI_BswM_Mode_Shutdown */
		FALSE,
		BSWM_ACTION_USR_CALLOUT,
		&BswM_Cfg_AC_BswMUserCallout_cast[4] /* BswMAction_AL_BswMode_Shutdown */
	}
};

static CONST(BswM_Cfg_ActionListItemType_tst, BSWM_CONST) BswM_Cfg_AL_BswM_AL_StartPduGroup_FR_Items_cast [1] =
{
	{
		/* ActionListItemName  :   BswMActionListItem */
		FALSE,
		BSWM_ACTION_PDU_GRP_SWITCH,
		&BswM_Cfg_AC_BswMPduGroupSwitch_cast[2] /* BswM_AI_StartPduGroup_FR */
	}
};

static CONST(BswM_Cfg_ActionListItemType_tst, BSWM_CONST) BswM_Cfg_AL_BswM_AL_StartPduGroup_Sys_Items_cast [1] =
{
	{
		/* ActionListItemName  :   BswMActionListItem */
		FALSE,
		BSWM_ACTION_PDU_GRP_SWITCH,
		&BswM_Cfg_AC_BswMPduGroupSwitch_cast[3] /* BswM_AI_StartPduGroup_Sys */
	}
};

static CONST(BswM_Cfg_ActionListItemType_tst, BSWM_CONST) BswM_Cfg_AL_BswM_AL_StopComm_AllBus_Items_cast [7] =
{
	{
		/* ActionListItemName  :   BswM_ALI_RequestNoComModeUser1 */
		FALSE,
		BSWM_ACTION_COMM_MODE_SWITCH,
		&BswM_Cfg_AC_BswMComMModeSwitch_cast[3] /* BswM_AI_ComMReqNoComm_User1 */
	},
	{
		/* ActionListItemName  :   BswM_ALI_RequestNoComModeUser0 */
		FALSE,
		BSWM_ACTION_COMM_MODE_SWITCH,
		&BswM_Cfg_AC_BswMComMModeSwitch_cast[2] /* BswM_AI_ComMReqNoComm_User0 */
	},
	{
		/* ActionListItemName  :   BswM_ALI_DisAllowComm_CAN2 */
		FALSE,
		BSWM_ACTION_COMM_ALLOW_COM,
		&BswM_Cfg_AC_BswMComMAllowCom_cast[3] /* BswM_AI_ComMCommNotAllowed_CAN2 */
	},
	{
		/* ActionListItemName  :   BswM_ALI_DisAllowComm_CAN1 */
		FALSE,
		BSWM_ACTION_COMM_ALLOW_COM,
		&BswM_Cfg_AC_BswMComMAllowCom_cast[2] /* BswM_AI_ComMCommNotAllowed_CAN1 */
	},
	{
		/* ActionListItemName  :   BswM_ALI_StopPdu */
		FALSE,
		BSWM_ACTION_PDU_GRP_SWITCH,
		&BswM_Cfg_AC_BswMPduGroupSwitch_cast[4] /* BswM_AI_StopPduGroup_All */
	},
	{
		/* ActionListItemName  :   BswM_ALI_BswMSwitchPrepShutdown */
		FALSE,
		BSWM_ACTION_SCHM_SWITCH,
		&BswM_Cfg_AC_BswMSchMSwitch_cast[2] /* BswM_AI_BswMSwitchPrepShutdown */
	},
	{
		/* ActionListItemName  :   BswM_ALI_BswM_Mode_StopComm */
		FALSE,
		BSWM_ACTION_USR_CALLOUT,
		&BswM_Cfg_AC_BswMUserCallout_cast[5] /* BswMAction_AL_BswMode_StopComm */
	}
};

static CONST(BswM_Cfg_ActionListItemType_tst, BSWM_CONST) BswM_Cfg_AL_BswM_AL_StopPduGroup_FR_Items_cast [1] =
{
	{
		/* ActionListItemName  :   BswMActionListItem */
		FALSE,
		BSWM_ACTION_PDU_GRP_SWITCH,
		&BswM_Cfg_AC_BswMPduGroupSwitch_cast[5] /* BswM_AI_StopPduGroup_FR */
	}
};

static CONST(BswM_Cfg_ActionListItemType_tst, BSWM_CONST) BswM_Cfg_AL_BswM_AL_StopPduGroup_Sys_Items_cast [1] =
{
	{
		/* ActionListItemName  :   BswMActionListItem */
		FALSE,
		BSWM_ACTION_PDU_GRP_SWITCH,
		&BswM_Cfg_AC_BswMPduGroupSwitch_cast[6] /* BswM_AI_StopPduGroup_Sys */
	}
};

/*****************************************************************************************
 * Array of ActionLists for __KW_COMMON with contents:
 * {
 *     ExecutionType,
 *     NumberOfActionListItems,
 *     BaseAddressOfActionListItemArray,
 *     Unique Number for ActionList
 * }
 ****************************************************************************************/

static CONST(BswM_Cfg_ActionListType_tst, BSWM_CONST) BswM_Cfg_AL_cast [13] =
{
	{
		/* ActionListName   :   BswM_AL_AfterRun */
		BSWM_TRIGGER,
		1,
		&BswM_Cfg_AL_BswM_AL_AfterRun_Items_cast[0],
		0 /* Unique Number for ActionList */
	},
	{
		/* ActionListName   :   BswM_AL_BswModules_InitListReadAll */
		BSWM_TRIGGER,
		14,
		&BswM_Cfg_AL_BswM_AL_BswModules_InitListReadAll_Items_cast[0],
		1 /* Unique Number for ActionList */
	},
	{
		/* ActionListName   :   BswM_AL_BswModules_InitListTwo */
		BSWM_CONDITION,
		6,
		&BswM_Cfg_AL_BswM_AL_BswModules_InitListTwo_Items_cast[0],
		2 /* Unique Number for ActionList */
	},
	{
		/* ActionListName   :   BswM_AL_DcmEnableRxAndTx_CAN0 */
		BSWM_TRIGGER,
		1,
		&BswM_Cfg_AL_BswM_AL_DcmEnableRxAndTx_CAN0_Items_cast[0],
		3 /* Unique Number for ActionList */
	},
	{
		/* ActionListName   :   BswM_AL_DcmEnableRxDisableTx_CAN0 */
		BSWM_TRIGGER,
		1,
		&BswM_Cfg_AL_BswM_AL_DcmEnableRxDisableTx_CAN0_Items_cast[0],
		4 /* Unique Number for ActionList */
	},
	{
		/* ActionListName   :   BswM_AL_FullComm_AllBus */
		BSWM_TRIGGER,
		7,
		&BswM_Cfg_AL_BswM_AL_FullComm_AllBus_Items_cast[0],
		5 /* Unique Number for ActionList */
	},
	{
		/* ActionListName   :   BswM_AL_GoDown */
		BSWM_TRIGGER,
		5,
		&BswM_Cfg_AL_BswM_AL_GoDown_Items_cast[0],
		6 /* Unique Number for ActionList */
	},
	{
		/* ActionListName   :   BswM_AL_Shutdown */
		BSWM_TRIGGER,
		5,
		&BswM_Cfg_AL_BswM_AL_Shutdown_Items_cast[0],
		7 /* Unique Number for ActionList */
	},
	{
		/* ActionListName   :   BswM_AL_StartPduGroup_FR */
		BSWM_CONDITION,
		1,
		&BswM_Cfg_AL_BswM_AL_StartPduGroup_FR_Items_cast[0],
		8 /* Unique Number for ActionList */
	},
	{
		/* ActionListName   :   BswM_AL_StartPduGroup_Sys */
		BSWM_CONDITION,
		1,
		&BswM_Cfg_AL_BswM_AL_StartPduGroup_Sys_Items_cast[0],
		9 /* Unique Number for ActionList */
	},
	{
		/* ActionListName   :   BswM_AL_StopComm_AllBus */
		BSWM_TRIGGER,
		7,
		&BswM_Cfg_AL_BswM_AL_StopComm_AllBus_Items_cast[0],
		10 /* Unique Number for ActionList */
	},
	{
		/* ActionListName   :   BswM_AL_StopPduGroup_FR */
		BSWM_CONDITION,
		1,
		&BswM_Cfg_AL_BswM_AL_StopPduGroup_FR_Items_cast[0],
		11 /* Unique Number for ActionList */
	},
	{
		/* ActionListName   :   BswM_AL_StopPduGroup_Sys */
		BSWM_CONDITION,
		1,
		&BswM_Cfg_AL_BswM_AL_StopPduGroup_Sys_Items_cast[0],
		12 /* Unique Number for ActionList */
	}
};

/* PBAction Type structure Variant : __KW_COMMON
 * - Pointer to base address of array of IPduGroupSwitchType ActionType structure (BswM_Cfg_AC_PduGroupSwitchType_tst)
 */
#define BSWM_CFG_PBACTION                {      \
                &BswM_Cfg_AC_BswMPduGroupSwitch_cast[0],     \
}

/* ModeControl Type structure  
 * - ActionType structure (BswM_Cfg_PBActionType_tst)
 * - Pointer to base address of array of actionlists (BswM_Cfg_ActionListType_tst) Currently NULL_PTR
 */
#define BSWM_CFG_MODECONTROL {      \
        BSWM_CFG_PBACTION,     \
        &BswM_Cfg_AL_cast[0]   \
}

/* BswM_ConfigType  :
 * - ModeArbitration structure (BswM_Cfg_ModeArbitrationType_tst)
 * - ModeControl structure (BswM_Cfg_ModeControlType_tst)
 * - Version info to compare during module initialization
 */
CONST(BswM_ConfigType, BSWM_CONST) BswM_Config =
{
	BSWM_CFG_MODEARBITRATION,
	BSWM_CFG_MODECONTROL,
	BSWM_CFG_VERSION_INFO
};

#define BSWM_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED 
#include "BswM_Cfg_MemMap.h"

#define BSWM_START_SEC_CONFIG_DATA_POSTBUILD_32
#include "BswM_Cfg_MemMap.h"

CONSTP2CONST(BswM_ConfigType,AUTOMATIC,BSWM_CONST) BswM_Configurations_capcst[BSWM_NO_OF_CONFIGSETS]=
{
	&BswM_Config
};

#define BSWM_STOP_SEC_CONFIG_DATA_POSTBUILD_32
#include "BswM_Cfg_MemMap.h"
/**********************************************************************************************************************
 *																										
 **********************************************************************************************************************/
