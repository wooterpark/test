/*
***********************************************************************************************************************
* 
* Product Info
* Isolar version: ISOLAR-AB 4.0.2
* Product release version: RTA-BSW 3.1.0
* 
***********************************************************************************************************************
*/

#ifndef BSWM_CFG_LE_H
#define BSWM_CFG_LE_H

/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
 */
#include "Std_Types.h"

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

/*
 **********************************************************************************************************************
 * Defines/Macros
 **********************************************************************************************************************
 */

/******************************     BswM Logical Expression    *****************************************/

#define BSWMLOGEXP_BSWM_LE_AFTERRUN  \
                    ( RTE_MODE_MDG_ECUM_STATE_ECUM_STATE_PREP_SHUTDOWN  ==  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_SWC_REQUESTAFTERRUN].dataMode_u16 )

#define BSWMLOGEXP_BSWM_LE_DCMENABLERXANDTX_CAN0  \
                    ( DCM_ENABLE_RX_TX_NORM  ==  BswM_Cfg_DcmComModeRequestModeInfo_ast[BSWM_IDX_BSWM_MRP_DCMRXTX_CAN0].dataMode_u8 )

#define BSWMLOGEXP_BSWM_LE_DCMENABLERXDISABLETX_CAN0  \
                    ( DCM_ENABLE_RX_DISABLE_TX_NORM  ==  BswM_Cfg_DcmComModeRequestModeInfo_ast[BSWM_IDX_BSWM_MRP_DCMRXTX_CAN0].dataMode_u8 )

#define BSWMLOGEXP_BSWM_LE_GODOWN  \
                    ( RTE_MODE_MDG_ECUM_STATE_ECUM_STATE_SHUTDOWN  ==  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_BSWM_MDG].dataMode_u16 )

#define BSWMLOGEXP_BSWM_LE_INITBLOCKREADALLCOMPLETE  \
                    ( RTE_MODE_MDG_ECUM_STATE_ECUM_STATE_STARTUP_TWO  ==  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_BSWM_MDG].dataMode_u16 )

#define BSWMLOGEXP_BSWM_LE_INITBLOCKTWO  \
                    ( RTE_MODE_MDG_ECUM_STATE_ECUM_STATE_STARTUP_ONE  ==  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_BSWM_MDG].dataMode_u16 )

#define BSWMLOGEXP_BSWM_LE_POSTRUN_CORE0  \
                    ( RTE_MODE_MDG_ECUM_STATE_ECUM_STATE_RUN  ==  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_SWC_REQUESTSHUTDOWN].dataMode_u16 )

#define BSWMLOGEXP_BSWM_LE_SHUTDOWN  \
                    ( RTE_MODE_MDG_ECUM_STATE_ECUM_STATE_PREP_SHUTDOWN  ==  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_BSWM_MDG].dataMode_u16 )

#define BSWMLOGEXP_BSWM_LE_STARTCOM  \
                    ( RTE_MODE_MDG_ECUM_STATE_ECUM_STATE_RUN  ==  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_BSWM_MDG].dataMode_u16 )

#define BSWMLOGEXP_BSWM_LE_STARTPDUGROUP_FR  \
                    ( RTE_MODE_MDG_ECUM_STATE_ECUM_STATE_STARTUP_TWO  ==  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_STARTPDUGROUP_FR].dataMode_u16 )

#define BSWMLOGEXP_BSWM_LE_STARTPDUGROUP_SYS  \
                    ( RTE_MODE_MDG_ECUM_STATE_ECUM_STATE_STARTUP_TWO  ==  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_STARTPDUGROUP_SYS].dataMode_u16 )

#define BSWMLOGEXP_BSWM_LE_STOPPDUGROUP_FR  \
                    ( RTE_MODE_MDG_ECUM_STATE_ECUM_STATE_STARTUP_TWO  ==  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_STOPPDUGROUP_FR].dataMode_u16 )

#define BSWMLOGEXP_BSWM_LE_STOPPDUGROUP_SYS  \
                    ( RTE_MODE_MDG_ECUM_STATE_ECUM_STATE_STARTUP_TWO  ==  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_STOPPDUGROUP_SYS].dataMode_u16 )

/******************   Macros for checking whether the ModeValues are defined   ******************************/

#define BSWMMODEVALUE_BSWM_LE_AFTERRUN  \
        ( FALSE  !=  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_SWC_REQUESTAFTERRUN].isValidModePresent_b )

#define BSWMMODEVALUE_BSWM_LE_DCMENABLERXANDTX_CAN0  \
        ( FALSE  !=  BswM_Cfg_DcmComModeRequestModeInfo_ast[BSWM_IDX_BSWM_MRP_DCMRXTX_CAN0].isValidModePresent_b )

#define BSWMMODEVALUE_BSWM_LE_DCMENABLERXDISABLETX_CAN0  \
        ( FALSE  !=  BswM_Cfg_DcmComModeRequestModeInfo_ast[BSWM_IDX_BSWM_MRP_DCMRXTX_CAN0].isValidModePresent_b )

#define BSWMMODEVALUE_BSWM_LE_GODOWN  \
        ( FALSE  !=  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_BSWM_MDG].isValidModePresent_b )

#define BSWMMODEVALUE_BSWM_LE_INITBLOCKREADALLCOMPLETE  \
        ( FALSE  !=  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_BSWM_MDG].isValidModePresent_b )

#define BSWMMODEVALUE_BSWM_LE_INITBLOCKTWO  \
        ( FALSE  !=  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_BSWM_MDG].isValidModePresent_b )

#define BSWMMODEVALUE_BSWM_LE_POSTRUN_CORE0  \
        ( FALSE  !=  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_SWC_REQUESTSHUTDOWN].isValidModePresent_b )

#define BSWMMODEVALUE_BSWM_LE_SHUTDOWN  \
        ( FALSE  !=  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_BSWM_MDG].isValidModePresent_b )

#define BSWMMODEVALUE_BSWM_LE_STARTCOM  \
        ( FALSE  !=  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_BSWM_MDG].isValidModePresent_b )

#define BSWMMODEVALUE_BSWM_LE_STARTPDUGROUP_FR  \
        ( FALSE  !=  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_STARTPDUGROUP_FR].isValidModePresent_b )

#define BSWMMODEVALUE_BSWM_LE_STARTPDUGROUP_SYS  \
        ( FALSE  !=  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_STARTPDUGROUP_SYS].isValidModePresent_b )

#define BSWMMODEVALUE_BSWM_LE_STOPPDUGROUP_FR  \
        ( FALSE  !=  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_STOPPDUGROUP_FR].isValidModePresent_b )

#define BSWMMODEVALUE_BSWM_LE_STOPPDUGROUP_SYS  \
        ( FALSE  !=  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_STOPPDUGROUP_SYS].isValidModePresent_b )

/*
 **********************************************************************************************************************
 * Extern declarations
 **********************************************************************************************************************
 */

/********************************  LogicalExpressionEvaluateFunctions  ***************************************/
#define BSWM_START_SEC_CODE
#include "BswM_Cfg_MemMap.h"

extern FUNC(void, BSWM_CODE) BswM_Cfg_LE_BswM_LE_AfterRun (P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) isValidMode_pb, P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) hasLogExpRes_pb);
extern FUNC(void, BSWM_CODE) BswM_Cfg_LE_BswM_LE_DcmEnableRxAndTx_CAN0 (P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) isValidMode_pb, P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) hasLogExpRes_pb);
extern FUNC(void, BSWM_CODE) BswM_Cfg_LE_BswM_LE_DcmEnableRxDisableTx_CAN0 (P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) isValidMode_pb, P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) hasLogExpRes_pb);
extern FUNC(void, BSWM_CODE) BswM_Cfg_LE_BswM_LE_GoDown (P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) isValidMode_pb, P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) hasLogExpRes_pb);
extern FUNC(void, BSWM_CODE) BswM_Cfg_LE_BswM_LE_InitBlockReadAllComplete (P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) isValidMode_pb, P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) hasLogExpRes_pb);
extern FUNC(void, BSWM_CODE) BswM_Cfg_LE_BswM_LE_InitBlockTwo (P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) isValidMode_pb, P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) hasLogExpRes_pb);
extern FUNC(void, BSWM_CODE) BswM_Cfg_LE_BswM_LE_PostRun_Core0 (P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) isValidMode_pb, P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) hasLogExpRes_pb);
extern FUNC(void, BSWM_CODE) BswM_Cfg_LE_BswM_LE_Shutdown (P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) isValidMode_pb, P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) hasLogExpRes_pb);
extern FUNC(void, BSWM_CODE) BswM_Cfg_LE_BswM_LE_StartCom (P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) isValidMode_pb, P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) hasLogExpRes_pb);
extern FUNC(void, BSWM_CODE) BswM_Cfg_LE_BswM_LE_StartPduGroup_FR (P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) isValidMode_pb, P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) hasLogExpRes_pb);
extern FUNC(void, BSWM_CODE) BswM_Cfg_LE_BswM_LE_StartPduGroup_Sys (P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) isValidMode_pb, P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) hasLogExpRes_pb);
extern FUNC(void, BSWM_CODE) BswM_Cfg_LE_BswM_LE_StopPduGroup_FR (P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) isValidMode_pb, P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) hasLogExpRes_pb);
extern FUNC(void, BSWM_CODE) BswM_Cfg_LE_BswM_LE_StopPduGroup_Sys (P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) isValidMode_pb, P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) hasLogExpRes_pb);

#define BSWM_STOP_SEC_CODE
#include "BswM_Cfg_MemMap.h"

#endif  /* BSWM_CFG_LE_H */
/**********************************************************************************************************************
 * End of header file
 **********************************************************************************************************************/
