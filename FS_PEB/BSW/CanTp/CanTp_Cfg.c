/*
***********************************************************************************************************************
* 
* Product Info
* Isolar version: ISOLAR-AB 4.0.2
* Product release version: RTA-BSW 3.1.0
* 
***********************************************************************************************************************
*/



/* Includes */
 
#include "CanTp.h"
#include "PduR_CanTp.h"

#if (!defined(PDUR_AR_RELEASE_MAJOR_VERSION) || (PDUR_AR_RELEASE_MAJOR_VERSION != 4))
#error "AUTOSAR major version undefined or mismatched"
#endif
#if (!defined(PDUR_AR_RELEASE_MINOR_VERSION) || (PDUR_AR_RELEASE_MINOR_VERSION != 2))
#error "AUTOSAR minor version undefined or mismatched"
#endif
#include "CanIf.h"
#if (!defined(CANIF_AR_RELEASE_MAJOR_VERSION) || (CANIF_AR_RELEASE_MAJOR_VERSION != 4))
#error "AUTOSAR major version undefined or mismatched"
#endif
#if (!defined(CANIF_AR_RELEASE_MINOR_VERSION) || (CANIF_AR_RELEASE_MINOR_VERSION != 2))
#error "AUTOSAR minor version undefined or mismatched"
#endif


typedef uint16 CanTp_TickType;
typedef uint8 CanTp_SduIdType;
typedef uint8 CanTp_ChannelIdType;
typedef void (*CanTp_GetSduPairType)(CanTp_SduIdType *TxSduId, CanTp_SduIdType *RxSduId, uint8 Address);



struct CanTp_RxPduStructType               /* Rx N-PDU to Connection Configuration Mapping Structure */
{
    const CanTp_SduIdType RxSduId;         /* RxSdu for combination of N-PDU and N-Ta */
    const CanTp_SduIdType TxSduId;         /* TxSdu for combination of N-PDU and N-Sa */
    const CanTp_GetSduPairType GetSduPair;
};

struct CanTp_TxSduStructType               /* TxConnection Configuration Structure */
{
    const uint8 TX_DL;                     /* Max CAN_DL of Tx */
    const uint8 BitFields;                 /* 4:IsTcDisabled|3:IsPadingOn|2:IsFunctional|1:IsFcDisabled|0:IsFdEnabled */
    const uint8 Address;                   /* Extended/Mixed Address to be used during transmission */
    const uint8 AddressFormatId;           /* Addressing Format Identifier */
    const uint8 TimeOutId;                 /* Timeout Index for this Connection in CanTp_TimeOut */
    const CanTp_ChannelIdType ChannelId;   /* Index of RAM Channel used by this connection */
    const PduIdType TxConfirmationId;      /* Transmit Confirmation Id for SF/FF/CF Frame */
    const PduIdType TxPduId;               /* Transmit N-PDU Id for this Connection */
    const PduIdType PduRPduHandleId;       /* Identifier to be used for PduR Api calls */
};

struct CanTp_RxSduStructType               /* RxConnection Configuration Structure */
{
    const uint8 BitFields;                 /* 3:IsPadingOn|2:IsFunctional|1:IsFcDisabled|0:IsFdEnabled */
    const uint8 Address;                   /* Extended/Mixed Address to be used during reception */
    const uint8 AddressFormatId;           /* Addressing Format Identifier */
    const uint8 TimeOutId;                 /* Timeout Index for this Connection in CanTp_TimeOut */
    const uint8 ParamId;                   /* Rx Conn. STmin/BS/FcWaitMax Index for this connection. */
    const CanTp_ChannelIdType ChannelId;   /* Index of RAM Channel used by this connection */
    const PduIdType TxConfirmationId;      /* Transmit Confirmation Id for FC Frame */
    const PduIdType TxPduId;               /* Transmit FC relevant N-PDU Id for this Connection */
    const PduIdType PduRPduHandleId;       /* Identifier to be used for PduR Api calls */
};
 
struct CanTp_TimeOutStructType             /* TimeOut Configuration Structure */
{
    const CanTp_TickType AsArTicks;
    const CanTp_TickType BsBrTicks;
    const CanTp_TickType CsCrTicks;
};

struct CanTp_ParamStructType               /* RxConnection Specific left overs Configuration Structure */
{
    const uint8 Param[2];                  /* Param[0] is for STMin and Param[1] is for BS */
    const uint16 FcWaitMax;
};

struct CanTp_ConfigStructType
{
    
    const CanTp_ChannelIdType NumberOfChannels;
    const CanTp_SduIdType NumberOfRxPdus;
    const CanTp_SduIdType NumberOfTxPdus;
    const CanTp_SduIdType NumberOfRxSdus;
    const CanTp_SduIdType NumberOfTxSdus;
    
    const struct CanTp_RxPduStructType *RxPdu;
    const struct CanTp_TxSduStructType *TxSdu;
    const struct CanTp_RxSduStructType *RxSdu;
    const struct CanTp_TimeOutStructType *TimeOut;
    const struct CanTp_ParamStructType *Param;
};



/* CanIf HandleId import */

#define CANTP_IF_PDU_ID_00000     CanIfConf_CanIfTxPduCfg_DcmOnCan0_Tx_Can_Network_0_CANNODE_0
#define CANTP_IF_PDU_ID_00001     CanIfConf_CanIfTxPduCfg_DcmOnCan1_Tx_Can_Network_1_CANNODE_0

#define CANTP_IF_FC_PDU_ID_00000  0
#define CANTP_IF_FC_PDU_ID_00001  CanIfConf_CanIfTxPduCfg_DcmOnCan0_Tx_Can_Network_0_CANNODE_0
#define CANTP_IF_FC_PDU_ID_00002  0
#define CANTP_IF_FC_PDU_ID_00003  CanIfConf_CanIfTxPduCfg_DcmOnCan1_Tx_Can_Network_1_CANNODE_0

/* PduR HandleId import */

#define CANTP_PDUR_DEST_ID_00000  PduRConf_PduRDestPdu_DcmOnCan0_Tx_Can_Network_0_CANNODE_0_Phys_PduR2CanTp
#define CANTP_PDUR_DEST_ID_00001  PduRConf_PduRDestPdu_DcmOnCan1_Tx_Can_Network_1_CANNODE_0_Phys_PduR2CanTp

#define CANTP_PDUR_SRC_ID_00000   PduRConf_PduRSrcPdu_DcmOnCan0_Func_Can_Network_0_CANNODE_0_CanTp2PduR
#define CANTP_PDUR_SRC_ID_00001   PduRConf_PduRSrcPdu_DcmOnCan0_Phys_Can_Network_0_CANNODE_0_CanTp2PduR
#define CANTP_PDUR_SRC_ID_00002   PduRConf_PduRSrcPdu_DcmOnCan1_Func_Can_Network_1_CANNODE_0_CanTp2PduR
#define CANTP_PDUR_SRC_ID_00003   PduRConf_PduRSrcPdu_DcmOnCan1_Phys_Can_Network_1_CANNODE_0_CanTp2PduR

        
/* Function definitions */

#define CANTP_START_SEC_CONFIG_CODE
#include "CanTp_MemMap.h"


#define CANTP_STOP_SEC_CONFIG_CODE
#include "CanTp_MemMap.h"


/* ConfigSet Structure definitions */
 
#define CANTP_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanTp_MemMap.h"


static const struct CanTp_RxPduStructType CanTp_RxPdu[4u] =
{    
    
    {  0,         4,         NULL_PTR                 },
    {  1,         0,         NULL_PTR                 },
    {  2,         4,         NULL_PTR                 },
    {  3,         1,         NULL_PTR                 } 
};

static const struct CanTp_TxSduStructType CanTp_TxSdu[2u] =
{
    {  0x8,  0x8,  0xBF, 0,    0,    1,     0,     CANTP_IF_PDU_ID_00000, CANTP_PDUR_DEST_ID_00000 },
    {  0x8,  0x8,  0xBF, 0,    1,    3,     1,     CANTP_IF_PDU_ID_00001, CANTP_PDUR_DEST_ID_00001 }
};

static const struct CanTp_RxSduStructType CanTp_RxSdu[4u] =
{
    {  0x4,  0x0,  0,    2,    0,    0,     0,     CANTP_IF_FC_PDU_ID_00000, CANTP_PDUR_SRC_ID_00000  },
    {  0x0,  0xBF, 0,    2,    0,    0,     0,     CANTP_IF_FC_PDU_ID_00001, CANTP_PDUR_SRC_ID_00001  },
    {  0x4,  0x0,  0,    3,    1,    2,     0,     CANTP_IF_FC_PDU_ID_00002, CANTP_PDUR_SRC_ID_00002  },
    {  0x0,  0xBF, 0,    3,    1,    2,     1,     CANTP_IF_FC_PDU_ID_00003, CANTP_PDUR_SRC_ID_00003  }
};

static const struct CanTp_TimeOutStructType CanTp_TimeOut[4u] =
{
{   70,                 150,                0          },
{   25,                 750,                100        },
{   70,                 0,                  150        },
{   25,                 0,                  150        }
};

static const struct CanTp_ParamStructType CanTp_Param[2u] =
{
    {{ 0x14,     0x8,      },     0x0       },
    {{ 0x5,      0x8,      },     0x0       }
};

const struct CanTp_ConfigStructType CanTp_Config = 
{ 
     
    4,
    4,
    2,
    4,
    2,
       
    &CanTp_RxPdu[0],
    &CanTp_TxSdu[0],
    &CanTp_RxSdu[0],
    &CanTp_TimeOut[0],
    &CanTp_Param[0]
};
 
#define CANTP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanTp_MemMap.h"


