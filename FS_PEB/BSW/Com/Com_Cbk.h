/*
***********************************************************************************************************************
* 
* Product Info
* Isolar version: ISOLAR-AB 4.0.2
* Product release version: RTA-BSW 3.1.0
* 
***********************************************************************************************************************
*/






 
/*<VersionHead>
 * This Configuration File is generated using versions (automatically filled in) as listed below.
 *
 * $Generator__: Com / AR42.4.0.0                Module Package Version
 * $Editor_____: 9.0                Tool Version
 * $Model______: 2.3.0.4                ECU Parameter Definition Version
 *
 
 </VersionHead>*/


#ifndef COM_CBK_H
#define COM_CBK_H

#define COMCallback(CALLBACKROUTINENAME) FUNC(void,COM_CODE)(CALLBACKROUTINENAME)(void)

/************* Com Notification in Tx side ************************/


/* Start: ComNotification for Signals */


/* End: ComNotification for Signals */


/* Start: ComNotification for Signals Groups */


/* End: ComNotification for Signals Groups */

/* Start : IPDU notification for TX IPDUs */


/* End : IPDU notification for TX IPDUs */

/******************************************************************/


/************* Com Notification in Rx side ************************/


/* Start: ComNotification for Signals */


#define COM_START_SEC_CODE
#include "Com_MemMap.h"
FUNC(void,COM_CODE) Rte_COMCbk_BMS01_stMainRelay_BMS_01(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
FUNC(void,COM_CODE) Rte_COMCbk_BMS01_BattVolt_BMS_01(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
FUNC(void,COM_CODE) Rte_COMCbk_BMS01_BattCurr_BMS_01(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
FUNC(void,COM_CODE) Rte_COMCbk_VCU01_stHvbMaiRly_VCU_01(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
FUNC(void,COM_CODE) Rte_COMCbk_VCU01_UdcMin_VCU_01(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
FUNC(void,COM_CODE) Rte_COMCbk_VCU01_UdcMax_VCU_01(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
FUNC(void,COM_CODE) Rte_COMCbk_VCU01_IdcMin_VCU_01(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
FUNC(void,COM_CODE) Rte_COMCbk_VCU01_IdcMax_VCU_01(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
FUNC(void,COM_CODE) Rte_COMCbk_VCU02_TrqMinNCtl_VCU_02(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
FUNC(void,COM_CODE) Rte_COMCbk_VCU02_TrqMaxNCtl_VCU_02(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
FUNC(void,COM_CODE) Rte_COMCbk_VCU02_NDiffMax_VCU_02(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
FUNC(void,COM_CODE) Rte_COMCbk_VCU02_KpLowNCtl_VCU_02(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
FUNC(void,COM_CODE) Rte_COMCbk_VCU02_KpHighNCtl_VCU_02(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
FUNC(void,COM_CODE) Rte_COMCbk_VCU03_cTrqSlopeMax_VCU_03(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
FUNC(void,COM_CODE) Rte_COMCbk_VCU03_TrqMin_VCU_03(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
FUNC(void,COM_CODE) Rte_COMCbk_VCU03_TrqMax_VCU_03(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
FUNC(void,COM_CODE) Rte_COMCbk_VCU04_MotDir_VCU_04(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
FUNC(void,COM_CODE) Rte_COMCbk_VCU04_bKL15_VCU_04(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
FUNC(void,COM_CODE) Rte_COMCbk_VCU04_TrqSetP_VCU_04(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
FUNC(void,COM_CODE) Rte_COMCbk_VCU04_stModeReq_VCU_04(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
FUNC(void,COM_CODE) Rte_COMCbk_VCU04_NSetP_VCU_04(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
FUNC(void,COM_CODE) Rte_COMCbk_VCU05_TrqDmpMax_VCU_05(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
FUNC(void,COM_CODE) Rte_COMCbk_VCU05_TrqDmpLim_VCU_05(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
FUNC(void,COM_CODE) Rte_COMCbk_VCU05_stDmpCtlReq_VCU_05(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
FUNC(void,COM_CODE) Rte_COMCbk_VCU05_kDmp_VCU_05(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
FUNC(void,COM_CODE) Rte_COMCbk_VCU05_OfsAl_VCU_05(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
FUNC(void,COM_CODE) Rte_COMCbk_VCU05_bSetOfsAl_VCU_05(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
FUNC(void,COM_CODE) Rte_COMCbk_VCU06_VehGrad_VCU_06(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
FUNC(void,COM_CODE) Rte_COMCbk_VCU06_Park_VCU_06(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
FUNC(void,COM_CODE) Rte_COMCbk_VCU06_stDoor_VCU_06(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
FUNC(void,COM_CODE) Rte_COMCbk_VCU06_stBreak_VCU_06(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
FUNC(void,COM_CODE) Rte_COMCbk_VCU06_stBelt_VCU_06(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"


/* End: ComNotification for Signals */


/* Start: ComNotification for Signals Groups */



/* End: ComNotification for Signals Groups */


/* Start: ComNotification for Rx IPdus */


/* End: ComNotification for Rx IPdus */


/******************************************************************/

/************* Com Error Notification in Tx side ************************/


/* Start: ComErrorNotification For Ipdu's */



/* End: ComErrorNotification for Ipdu's */


/* Start: ComErrorNotification for Signals */



/* End: ComErrorNotification for Signals */


/* Start: ComErrorNotification for Signals Groups */


/* End: ComErrorNotification for Signals Groups */


/******************************************************************/

/************* Com Timeout Notification in Tx side ************************/


/* Start: ComTimeoutNotification for Signals */



/* End: ComTimeoutNotification for Signals */


/* Start: ComTimeoutNotification for Signals Groups */


/* End: ComTimeoutNotification for Signals Groups */

/******************************************************************/

/************* Com Notification in Rx side ************************/


/* Start: ComTimeoutNotification for Signals */



/* End: ComTimeoutNotification for Signals */


/* Start: ComTimeoutNotification for Signals Groups */


/* End: ComTimeoutNotification for Signals Groups */


/******************************************************************/

/************* Com Invalid Notification for Rx************************/


/* Start: ComInvalidNotification for Signals */



/* End: ComInvalidNotification for Signals */


/* Start: ComInvalidNotification for Signals Groups */

/* End: ComInvalidNotification for Signals Groups */



/******************************************************************/

/************* Com Ipdu Callouts ************************/




#define COM_START_SEC_CODE
#include "Com_MemMap.h"
FUNC(boolean,COM_CODE) Com_RxCallout_BMS_01_Can_Network_0_CANNODE_0(VAR(PduIdType, AUTOMATIC) id, P2CONST(uint8, AUTOMATIC, COM_APPL_CONST) ptr);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
FUNC(boolean,COM_CODE) SysBoot_SysBoot_Rx_Can_Network_1_CANNODE_0(VAR(PduIdType, AUTOMATIC) id, P2CONST(uint8, AUTOMATIC, COM_APPL_CONST) ptr);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
FUNC(boolean,COM_CODE) Com_RxCallout_TOOL_01_Can_Network_1_CANNODE_0(VAR(PduIdType, AUTOMATIC) id, P2CONST(uint8, AUTOMATIC, COM_APPL_CONST) ptr);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
FUNC(boolean,COM_CODE) Com_RxCallout_VCU_01_Can_Network_0_CANNODE_0(VAR(PduIdType, AUTOMATIC) id, P2CONST(uint8, AUTOMATIC, COM_APPL_CONST) ptr);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
FUNC(boolean,COM_CODE) Com_RxCallout_VCU_02_Can_Network_0_CANNODE_0(VAR(PduIdType, AUTOMATIC) id, P2CONST(uint8, AUTOMATIC, COM_APPL_CONST) ptr);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
FUNC(boolean,COM_CODE) Com_RxCallout_VCU_03_Can_Network_0_CANNODE_0(VAR(PduIdType, AUTOMATIC) id, P2CONST(uint8, AUTOMATIC, COM_APPL_CONST) ptr);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
FUNC(boolean,COM_CODE) Com_RxCallout_VCU_04_Can_Network_0_CANNODE_0(VAR(PduIdType, AUTOMATIC) id, P2CONST(uint8, AUTOMATIC, COM_APPL_CONST) ptr);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
FUNC(boolean,COM_CODE) Com_RxCallout_VCU_05_Can_Network_0_CANNODE_0(VAR(PduIdType, AUTOMATIC) id, P2CONST(uint8, AUTOMATIC, COM_APPL_CONST) ptr);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
FUNC(boolean,COM_CODE) Com_RxCallout_VCU_06_Can_Network_0_CANNODE_0(VAR(PduIdType, AUTOMATIC) id, P2CONST(uint8, AUTOMATIC, COM_APPL_CONST) ptr);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
FUNC(boolean,COM_CODE) Com_RxCallout_VCU_07_Mask_Can_Network_0_CANNODE_0(VAR(PduIdType, AUTOMATIC) id, P2CONST(uint8, AUTOMATIC, COM_APPL_CONST) ptr);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"



#define COM_START_SEC_CODE
#include "Com_MemMap.h"
FUNC(boolean,COM_CODE) Com_TxCallout_DIAG_01_Can_Network_1_CANNODE_0(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
FUNC(boolean,COM_CODE) Com_TxCallout_SysBoot_Tx_Can_Network_1_CANNODE_0(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
FUNC(boolean,COM_CODE) Com_Callout_PEB07_0x430_Can_Network_0_CANNODE_0(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
/******************************************************************/

/*************Error Notification for Rx Ipdus *****************/

/* Start: ComErrorNotification For Ipdu's */



/******************************************************************/

#endif /* COM_CBK_H */

