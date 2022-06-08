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
 * $Generator__: CanIf / AR42.4.0.1                Module Package Version
 * $Editor_____: 9.0                Tool Version
 * $Model______: 2.0.2.1                ECU Parameter Definition Version
 *

 </VersionHead>*/


/******************************************************************************/
/*                                  Include Section                                */
/******************************************************************************/

/* CanIf Private header */
#include "CanIf_Priv.h"
/* CanIf post build header */
#include "CanIf_PBcfg.h"
/* CanIf post build header */
#include "CanIf_Cfg_Internal.h"












/* BusOff callback functions to Can State Manager */
#include "CanSM_Cbk.h"
#if (!defined(CANSM_AR_RELEASE_MAJOR_VERSION) || (CANSM_AR_RELEASE_MAJOR_VERSION != CANIF_AR_RELEASE_MAJOR_VERSION))
#error "AUTOSAR major version undefined or mismatched"
#endif
#if (!defined(CANSM_AR_RELEASE_MINOR_VERSION) || (CANSM_AR_RELEASE_MINOR_VERSION != CANIF_AR_RELEASE_MINOR_VERSION))
#error "AUTOSAR minor version undefined or mismatched"
#endif
















/*
 ******************************************************************************
 * Variables
 ******************************************************************************
 */








/* CANIF callback configuration */

#if(CANIF_VARIANT_INFO != 2) && (CANIF_VARIANT_INFO != 3)
#define CANIF_START_SEC_CONST_UNSPECIFIED
#else
#define CANIF_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#endif
#include "CanIf_MemMap.h"
CONST(CanIf_CallbackFuncType, CANIF_CONST) CanIf_Callback =
{

    &CanSM_ControllerBusOff,














    NULL_PTR,
    
    &CanSM_ControllerModeIndication,
    NULL_PTR,
    NULL_PTR,
    
    NULL_PTR
    

};

#if(CANIF_VARIANT_INFO != 2) && (CANIF_VARIANT_INFO != 3)
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#else
#define CANIF_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#endif
#include "CanIf_MemMap.h"
















/* Tx PDUs Configuration */
#if(CANIF_VARIANT_INFO != 2) && (CANIF_VARIANT_INFO != 3)
#define CANIF_START_SEC_CONST_UNSPECIFIED
#else
#define CANIF_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#endif
#include "CanIf_MemMap.h"
CONST(CanIf_TxPduInfo, CANIF_CONST) CanIf_TxPduConfig[]=
{
/*
    CanTxPduId, TargetTxPduId, CanTxPduId, Hth_Ref_Id, Controller, CanIdType,  User,  ReadTxPdu,  CbkIdx ,Tx_Buffer Offset , Start Indx , End Indx, HTHIndex, CanId,  DLC,                                     Type                                                 Notify
                                                                                        Status
*/



{   CanIfConf_CanIfTxPduCfg_PEB_09_Can_Network_0_CANNODE_0,    9 ,   CANIF_STATIC,   (uint8)Can_17_MCanPConf_CanHardwareObject_Can_Network_0_CANNODE_0_Tx_Std_MailBox_1,    (uint8)CANIF_Can_Network_0_CANNODE_0,   0x00,   PDUR,   FALSE    ,    0,   0x450,   8 },
{   CanIfConf_CanIfTxPduCfg_PEB_04_Can_Network_0_CANNODE_0,    4 ,   CANIF_STATIC,   (uint8)Can_17_MCanPConf_CanHardwareObject_Can_Network_0_CANNODE_0_Tx_Std_MailBox_10,    (uint8)CANIF_Can_Network_0_CANNODE_0,   0x00,   PDUR,   FALSE    ,    0,   0x230,   8 },
{   CanIfConf_CanIfTxPduCfg_PEB_05_Can_Network_0_CANNODE_0,    5 ,   CANIF_STATIC,   (uint8)Can_17_MCanPConf_CanHardwareObject_Can_Network_0_CANNODE_0_Tx_Std_MailBox_2,    (uint8)CANIF_Can_Network_0_CANNODE_0,   0x00,   PDUR,   FALSE    ,    0,   0x240,   8 },
{   CanIfConf_CanIfTxPduCfg_PEB_01_Can_Network_0_CANNODE_0,    1 ,   CANIF_STATIC,   (uint8)Can_17_MCanPConf_CanHardwareObject_Can_Network_0_CANNODE_0_Tx_Std_MailBox_3,    (uint8)CANIF_Can_Network_0_CANNODE_0,   0x00,   PDUR,   FALSE    ,    0,   0x200,   8 },
{   CanIfConf_CanIfTxPduCfg_PEB_02_Can_Network_0_CANNODE_0,    2 ,   CANIF_STATIC,   (uint8)Can_17_MCanPConf_CanHardwareObject_Can_Network_0_CANNODE_0_Tx_Std_MailBox_4,    (uint8)CANIF_Can_Network_0_CANNODE_0,   0x00,   PDUR,   FALSE    ,    0,   0x400,   8 },
{   CanIfConf_CanIfTxPduCfg_PEB_06_Can_Network_0_CANNODE_0,    6 ,   CANIF_STATIC,   (uint8)Can_17_MCanPConf_CanHardwareObject_Can_Network_0_CANNODE_0_Tx_Std_MailBox_5,    (uint8)CANIF_Can_Network_0_CANNODE_0,   0x00,   PDUR,   FALSE    ,    0,   0x420,   8 },
{   CanIfConf_CanIfTxPduCfg_PEB_08_Can_Network_0_CANNODE_0,    8 ,   CANIF_STATIC,   (uint8)Can_17_MCanPConf_CanHardwareObject_Can_Network_0_CANNODE_0_Tx_Std_MailBox_6,    (uint8)CANIF_Can_Network_0_CANNODE_0,   0x00,   PDUR,   FALSE    ,    0,   0x440,   8 },
{   CanIfConf_CanIfTxPduCfg_PEB_03_Can_Network_0_CANNODE_0,    3 ,   CANIF_STATIC,   (uint8)Can_17_MCanPConf_CanHardwareObject_Can_Network_0_CANNODE_0_Tx_Std_MailBox_7,    (uint8)CANIF_Can_Network_0_CANNODE_0,   0x00,   PDUR,   FALSE    ,    0,   0x210,   8 },
{   CanIfConf_CanIfTxPduCfg_DcmOnCan0_Tx_Can_Network_0_CANNODE_0,    CanTpConf_CanTpTxNPdu_UDS_Tx_Phys_Network_0_Phys_CanTp2CanIf ,   CANIF_STATIC,   (uint8)Can_17_MCanPConf_CanHardwareObject_Can_Network_0_CANNODE_0_Tx_Std_MailBox_8,    (uint8)CANIF_Can_Network_0_CANNODE_0,   0x00,   CANTP,   FALSE    ,    0,   0x651,   8 },
{   CanIfConf_CanIfTxPduCfg_PEB_07_Can_Network_0_CANNODE_0,    7 ,   CANIF_STATIC,   (uint8)Can_17_MCanPConf_CanHardwareObject_Can_Network_0_CANNODE_0_Tx_Std_MailBox_9,    (uint8)CANIF_Can_Network_0_CANNODE_0,   0x00,   PDUR,   FALSE    ,    0,   0x430,   8 },
{   CanIfConf_CanIfTxPduCfg_XCP_Daq0_Can_Network_1_CANNODE_0,    1 ,   CANIF_STATIC,   (uint8)Can_17_MCanPConf_CanHardwareObject_Can_Network_1_CANNODE_0_Tx_Std_MailBox_1,    (uint8)CANIF_Can_Network_1_CANNODE_0,   0x00,   XCP,   FALSE    ,    0,   0x310,   8 },
{   CanIfConf_CanIfTxPduCfg_XCP_Daq1_Can_Network_1_CANNODE_0,    2 ,   CANIF_STATIC,   (uint8)Can_17_MCanPConf_CanHardwareObject_Can_Network_1_CANNODE_0_Tx_Std_MailBox_2,    (uint8)CANIF_Can_Network_1_CANNODE_0,   0x00,   XCP,   FALSE    ,    0,   0x311,   8 },
{   CanIfConf_CanIfTxPduCfg_XCP_Daq2_Can_Network_1_CANNODE_0,    3 ,   CANIF_STATIC,   (uint8)Can_17_MCanPConf_CanHardwareObject_Can_Network_1_CANNODE_0_Tx_Std_MailBox_3,    (uint8)CANIF_Can_Network_1_CANNODE_0,   0x00,   XCP,   FALSE    ,    0,   0x312,   8 },
{   CanIfConf_CanIfTxPduCfg_SysBoot_Tx_Can_Network_1_CANNODE_0,    10 ,   CANIF_STATIC,   (uint8)Can_17_MCanPConf_CanHardwareObject_Can_Network_1_CANNODE_0_Tx_Std_MailBox_4,    (uint8)CANIF_Can_Network_1_CANNODE_0,   0x00,   PDUR,   FALSE    ,    0,   0x605,   8 },
{   CanIfConf_CanIfTxPduCfg_XCP_Tx_Can_Network_1_CANNODE_0,    0 ,   CANIF_STATIC,   (uint8)Can_17_MCanPConf_CanHardwareObject_Can_Network_1_CANNODE_0_Tx_Std_MailBox_5,    (uint8)CANIF_Can_Network_1_CANNODE_0,   0x00,   XCP,   FALSE    ,    0,   0x300,   8 },
{   CanIfConf_CanIfTxPduCfg_DcmOnCan1_Tx_Can_Network_1_CANNODE_0,    CanTpConf_CanTpTxNPdu_UDS_Tx_Can_Network_1_Phys_CanTp2CanIf ,   CANIF_STATIC,   (uint8)Can_17_MCanPConf_CanHardwareObject_Can_Network_1_CANNODE_0_Tx_Std_MailBox_6,    (uint8)CANIF_Can_Network_1_CANNODE_0,   0x00,   CANTP,   FALSE    ,    0,   0x651,   8 },
{   CanIfConf_CanIfTxPduCfg_DIAG_01_Can_Network_1_CANNODE_0,    0 ,   CANIF_STATIC,   (uint8)Can_17_MCanPConf_CanHardwareObject_Can_Network_1_CANNODE_0_Tx_Std_MailBox_7,    (uint8)CANIF_Can_Network_1_CANNODE_0,   0x00,   PDUR,   FALSE    ,    0,   0x790,   8 }};
#if(CANIF_VARIANT_INFO != 2) && (CANIF_VARIANT_INFO != 3)
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#else
#define CANIF_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#endif
#include "CanIf_MemMap.h"










/* Rx Handle configuration */

#define CANIF_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "CanIf_MemMap.h"

CONST(CanIf_HrhConfigType, CANIF_CONST) CanIf_HrhConfig[] =
{
/*   HRHInfo ,    Pdu/ListIdx,   NumCanIds/NumRanges,     Controller,  ReadRxPduInfo,    CanId,  HrhRangeMask */

{ CANIF_FULL,       0    ,       1    ,   (uint8)CANIF_Can_Network_0_CANNODE_0,       CANIF_READ_NOTIFSTATUS,   0x120,       0x1FFFFFFFU }/*Can_Network_0_CANNODE_0_Rx_Std_MailBox_1*/,
{ CANIF_FULL,       2    ,       1    ,   (uint8)CANIF_Can_Network_0_CANNODE_0,       CANIF_READ_NOTIFSTATUS,   0x100,       0x1FFFFFFFU }/*Can_Network_0_CANNODE_0_Rx_Std_MailBox_2*/,
{ CANIF_FULL,       3    ,       1    ,   (uint8)CANIF_Can_Network_0_CANNODE_0,       CANIF_READ_NOTIFSTATUS,   0x310,       0x1FFFFFFFU }/*Can_Network_0_CANNODE_0_Rx_Std_MailBox_3*/,
{ CANIF_FULL,       4    ,       1    ,   (uint8)CANIF_Can_Network_0_CANNODE_0,       CANIF_READ_NOTIFSTATUS,   0x220,       0x1FFFFFFFU }/*Can_Network_0_CANNODE_0_Rx_Std_MailBox_4*/,
{ CANIF_FULL,       5    ,       1    ,   (uint8)CANIF_Can_Network_0_CANNODE_0,       CANIF_READ_NOTIFSTATUS,   0x320,       0x1FFFFFFFU }/*Can_Network_0_CANNODE_0_Rx_Std_MailBox_5*/,
{ CANIF_FULL,       6    ,       1    ,   (uint8)CANIF_Can_Network_0_CANNODE_0,       CANIF_READ_NOTIFSTATUS,   0x300,       0x1FFFFFFFU }/*Can_Network_0_CANNODE_0_Rx_Std_MailBox_6*/,
{ CANIF_FULL,       7    ,       1    ,   (uint8)CANIF_Can_Network_0_CANNODE_0,       CANIF_READ_NOTIFSTATUS,   0x110,       0x1FFFFFFFU }/*Can_Network_0_CANNODE_0_Rx_Std_MailBox_7*/,
{ CANIF_FULL,       8    ,       1    ,   (uint8)CANIF_Can_Network_0_CANNODE_0,       CANIF_READ_NOTIFSTATUS,   0x603,       0x1FFFFFFFU }/*Can_Network_0_CANNODE_0_Rx_Std_MailBox_8*/,
{ CANIF_FULL,       9    ,       1    ,   (uint8)CANIF_Can_Network_0_CANNODE_0,       CANIF_READ_NOTIFSTATUS,   0x602,       0x1FFFFFFFU }/*Can_Network_0_CANNODE_0_Rx_Std_MailBox_9*/,
{ CANIF_BASIC_RANGE_SFON_SINTGT,       1    ,           2047    ,   (uint8)CANIF_Can_Network_0_CANNODE_0,       CANIF_READ_NOTIFSTATUS,   0x1,       0x1FFFFFFFU }/*Can_Network_0_CANNODE_0_Rx_Std_MailBox_10*/,
{ CANIF_FULL,       10    ,       1    ,   (uint8)CANIF_Can_Network_1_CANNODE_0,       CANIF_READ_NOTIFSTATUS,   0x780,       0x1FFFFFFFU }/*Can_Network_1_CANNODE_0_Rx_Std_MailBox_1*/,
{ CANIF_FULL,       11    ,       1    ,   (uint8)CANIF_Can_Network_1_CANNODE_0,       CANIF_READ_NOTIFSTATUS,   0x220,       0x1FFFFFFFU }/*Can_Network_1_CANNODE_0_Rx_Std_MailBox_2*/,
{ CANIF_FULL,       12    ,       1    ,   (uint8)CANIF_Can_Network_1_CANNODE_0,       CANIF_READ_NOTIFSTATUS,   0x604,       0x1FFFFFFFU }/*Can_Network_1_CANNODE_0_Rx_Std_MailBox_3*/,
{ CANIF_FULL,       13    ,       1    ,   (uint8)CANIF_Can_Network_1_CANNODE_0,       CANIF_READ_NOTIFSTATUS,   0x210,       0x1FFFFFFFU }/*Can_Network_1_CANNODE_0_Rx_Std_MailBox_4*/,
{ CANIF_FULL,       14    ,       1    ,   (uint8)CANIF_Can_Network_1_CANNODE_0,       CANIF_READ_NOTIFSTATUS,   0x603,       0x1FFFFFFFU }/*Can_Network_1_CANNODE_0_Rx_Std_MailBox_5*/,
{ CANIF_FULL,       15    ,       1    ,   (uint8)CANIF_Can_Network_1_CANNODE_0,       CANIF_READ_NOTIFSTATUS,   0x602,       0x1FFFFFFFU }/*Can_Network_1_CANNODE_0_Rx_Std_MailBox_6*/
};

#define CANIF_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "CanIf_MemMap.h"















/* Rx PDUs Configuration */

#define CANIF_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(CanIf_RxPduConfigType, CANIF_CONST) CanIf_RxPduConfig[]=
{
/*     RxBufferOffset,  target ID,  RxPduId , HRH , CbkIdx, User, CanIdType, DLC,  RxPduCanId      */

{    PduRConf_PduRSrcPdu_VCU_06_Can_Network_0_CANNODE_0_CanIf2PduR ,   CanIfConf_CanIfRxPduCfg_VCU_06_Can_Network_0_CANNODE_0,       0,  0,   PDUR,   0x20u,   8,   0x120 },
{    PduRConf_PduRSrcPdu_VCU_07_Mask_Can_Network_0_CANNODE_0_CanIf2PduR ,   CanIfConf_CanIfRxPduCfg_VCU_07_Mask_Can_Network_0_CANNODE_0,       9,  0,   PDUR,   0x20u,   8,   0x7FF },
{    PduRConf_PduRSrcPdu_VCU_04_Can_Network_0_CANNODE_0_CanIf2PduR ,   CanIfConf_CanIfRxPduCfg_VCU_04_Can_Network_0_CANNODE_0,       1,  0,   PDUR,   0x20u,   8,   0x100 },
{    PduRConf_PduRSrcPdu_VCU_02_Can_Network_0_CANNODE_0_CanIf2PduR ,   CanIfConf_CanIfRxPduCfg_VCU_02_Can_Network_0_CANNODE_0,       2,  0,   PDUR,   0x20u,   8,   0x310 },
{    PduRConf_PduRSrcPdu_BMS_01_Can_Network_0_CANNODE_0_CanIf2PduR ,   CanIfConf_CanIfRxPduCfg_BMS_01_Can_Network_0_CANNODE_0,       3,  0,   PDUR,   0x20u,   8,   0x220 },
{    PduRConf_PduRSrcPdu_VCU_03_Can_Network_0_CANNODE_0_CanIf2PduR ,   CanIfConf_CanIfRxPduCfg_VCU_03_Can_Network_0_CANNODE_0,       4,  0,   PDUR,   0x20u,   8,   0x320 },
{    PduRConf_PduRSrcPdu_VCU_01_Can_Network_0_CANNODE_0_CanIf2PduR ,   CanIfConf_CanIfRxPduCfg_VCU_01_Can_Network_0_CANNODE_0,       5,  0,   PDUR,   0x20u,   8,   0x300 },
{    PduRConf_PduRSrcPdu_VCU_05_Can_Network_0_CANNODE_0_CanIf2PduR ,   CanIfConf_CanIfRxPduCfg_VCU_05_Can_Network_0_CANNODE_0,       6,  0,   PDUR,   0x20u,   8,   0x110 },
{    CanTpConf_CanTpRxNPdu_UDS_Rx_Can_Network_0_Phys_CanIf2CanTp ,   CanIfConf_CanIfRxPduCfg_DcmOnCan0_Phys_Can_Network_0_CANNODE_0,       7,  0,   CANTP,   0x20u,   1,   0x603 },
{    CanTpConf_CanTpRxNPdu_UDS_Rx_Can_Network_0_Func_CanIf2CanTp ,   CanIfConf_CanIfRxPduCfg_DcmOnCan0_Func_Can_Network_0_CANNODE_0,       8,  0,   CANTP,   0x20u,   1,   0x602 },
{    PduRConf_PduRSrcPdu_TOOL_01_Can_Network_1_CANNODE_0_CanIf2PduR ,   CanIfConf_CanIfRxPduCfg_TOOL_01_Can_Network_1_CANNODE_0,       10,  0,   PDUR,   0x20u,   8,   0x780 },
{    XcpConf_XcpRxPdu_XcpRxPdu_CMD ,   CanIfConf_CanIfRxPduCfg_XCP_Rx_Can_Network_1_CANNODE_0,       11,  0,   XCP,   0x30u,   1,   0x220 },
{    PduRConf_PduRSrcPdu_SysBoot_Rx_Can_Network_1_CANNODE_0_CanIf2PduR ,   CanIfConf_CanIfRxPduCfg_SysBoot_Rx_Can_Network_1_CANNODE_0,       12,  0,   PDUR,   0x20u,   8,   0x604 },
{    XcpConf_XcpRxPdu_XcpRxPdu_Broadcast ,   CanIfConf_CanIfRxPduCfg_XCP_Bordcast_Can_Network_1_CANNODE_0,       13,  0,   XCP,   0x30u,   1,   0x210 },
{    CanTpConf_CanTpRxNPdu_UDS_Rx_Can_Network_1_Phys_CanIf2CanTp ,   CanIfConf_CanIfRxPduCfg_DcmOnCan1_Phys_Can_Network_1_CANNODE_0,       14,  0,   CANTP,   0x20u,   1,   0x603 },
{    CanTpConf_CanTpRxNPdu_UDS_Rx_Can_Network_1_Func_CanIf2CanTp ,   CanIfConf_CanIfRxPduCfg_DcmOnCan1_Func_Can_Network_1_CANNODE_0,       15,  0,   CANTP,   0x20u,   1,   0x602 }
};

#define CANIF_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "CanIf_MemMap.h"


























   







































#if(CANIF_VARIANT_INFO == 3)
/* Generate an instance of structure Std_VersionInfoType in CanIf_PBcfg_c.xpt*/
#define CANIF_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(Std_VersionInfoType, CANIF_CONST)  CanIf_VersionInfo =
{
    6,    /* Vendor Id */
    60,    /* Module Id */
    4,    /* Sw Major Version */
    0,    /* Sw Minor Version */
    1     /* Sw Patch Version */
};
#define CANIF_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "CanIf_MemMap.h"
#endif



/* Global configuration structure */


#define CANIF_START_SEC_CONST_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(CanIf_ConfigType, CANIF_CONST) CanIf_Config =
{
    CanIf_TxPduConfig,
    /* MR12 RULE 1.1 VIOLATION:This is a known defect in CChecker 2.1.0 tool.No fix required in the component.*/
    CanIf_RxPduConfig,
    CanIf_HrhConfig,
    CANIF_NUM_STATIC_CANTXPDUIDS,
    CANIF_NUM_CANRXPDUIDS,
    CANIF_NUM_DYNAMIC_CANTXPDUIDS,
    CANIF_NUM_CONTROLLERS
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#include "CanIf_MemMap.h"










