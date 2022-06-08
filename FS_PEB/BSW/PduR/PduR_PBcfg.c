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
 * $Generator__: PduR  / AR42.4.0.1                Module Package Version
 * $Editor_____: 9.0                Tool Version
 * $Model______: 2.3.0.4                ECU Parameter Definition Version
 *
 
 </VersionHead>*/


#include "PduR_PBcfg.h"
#include "PduR_UpIf.h"


#include "PduR_LoIf.h"
#include "PduR_LoTp.h"

#include "PduR_UpTp.h"

#include "PduR_Mc.h"
#include "PduR_Gw.h"


#include "PduR_Gw_Cfg.h"
/* Generating PbCfg_c::PduR_UpIfToLo_PBcfg_c::upIf_To_Lo */

/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#define PDUR_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "PduR_MemMap.h"
#if defined(PDUR_CONFIG_SINGLE_IFTX_LO)
#define PduR_comToLo   NULL_PTR
#else
static CONST(PduR_RT_UpToLo,PDUR_CONST ) PduR_comToLo[] = {
    { CanIfConf_CanIfTxPduCfg_DIAG_01_Can_Network_1_CANNODE_0 , (PduR_loTransmitFP)PduR_RF_CanIf_Transmit, (PduR_loCancelTransmitFP)PduR_IH_CancelTransmit },    /*DIAG_01_Can_Network_1_CANNODE_0_Com2PduR*/
    { CanIfConf_CanIfTxPduCfg_PEB_01_Can_Network_0_CANNODE_0 , (PduR_loTransmitFP)PduR_RF_CanIf_Transmit, (PduR_loCancelTransmitFP)PduR_IH_CancelTransmit },    /*PEB_01_Can_Network_0_CANNODE_0_Com2PduR*/
    { CanIfConf_CanIfTxPduCfg_PEB_02_Can_Network_0_CANNODE_0 , (PduR_loTransmitFP)PduR_RF_CanIf_Transmit, (PduR_loCancelTransmitFP)PduR_IH_CancelTransmit },    /*PEB_02_Can_Network_0_CANNODE_0_Com2PduR*/
    { CanIfConf_CanIfTxPduCfg_PEB_03_Can_Network_0_CANNODE_0 , (PduR_loTransmitFP)PduR_RF_CanIf_Transmit, (PduR_loCancelTransmitFP)PduR_IH_CancelTransmit },    /*PEB_03_Can_Network_0_CANNODE_0_Com2PduR*/
    { CanIfConf_CanIfTxPduCfg_PEB_04_Can_Network_0_CANNODE_0 , (PduR_loTransmitFP)PduR_RF_CanIf_Transmit, (PduR_loCancelTransmitFP)PduR_IH_CancelTransmit },    /*PEB_04_Can_Network_0_CANNODE_0_Com2PduR*/
    { CanIfConf_CanIfTxPduCfg_PEB_05_Can_Network_0_CANNODE_0 , (PduR_loTransmitFP)PduR_RF_CanIf_Transmit, (PduR_loCancelTransmitFP)PduR_IH_CancelTransmit },    /*PEB_05_Can_Network_0_CANNODE_0_Com2PduR*/
    { CanIfConf_CanIfTxPduCfg_PEB_06_Can_Network_0_CANNODE_0 , (PduR_loTransmitFP)PduR_RF_CanIf_Transmit, (PduR_loCancelTransmitFP)PduR_IH_CancelTransmit },    /*PEB_06_Can_Network_0_CANNODE_0_Com2PduR*/
    { CanIfConf_CanIfTxPduCfg_PEB_07_Can_Network_0_CANNODE_0 , (PduR_loTransmitFP)PduR_RF_CanIf_Transmit, (PduR_loCancelTransmitFP)PduR_IH_CancelTransmit },    /*PEB_07_Can_Network_0_CANNODE_0_Com2PduR*/
    { CanIfConf_CanIfTxPduCfg_PEB_08_Can_Network_0_CANNODE_0 , (PduR_loTransmitFP)PduR_RF_CanIf_Transmit, (PduR_loCancelTransmitFP)PduR_IH_CancelTransmit },    /*PEB_08_Can_Network_0_CANNODE_0_Com2PduR*/
    { CanIfConf_CanIfTxPduCfg_PEB_09_Can_Network_0_CANNODE_0 , (PduR_loTransmitFP)PduR_RF_CanIf_Transmit, (PduR_loCancelTransmitFP)PduR_IH_CancelTransmit },    /*PEB_09_Can_Network_0_CANNODE_0_Com2PduR*/
    { CanIfConf_CanIfTxPduCfg_SysBoot_Tx_Can_Network_1_CANNODE_0 , (PduR_loTransmitFP)PduR_RF_CanIf_Transmit, (PduR_loCancelTransmitFP)PduR_IH_CancelTransmit }    /*SysBoot_Tx_Can_Network_1_CANNODE_0_Com2PduR*/

};
#endif /* PDUR_CONFIG_SINGLE_IFTX_LO */

/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#define PDUR_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "PduR_MemMap.h"

/* Generating PbCfg_c::PduR_UpTpToLo_PBcfg_c::upTp_To_Lo */


/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#define PDUR_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "PduR_MemMap.h"
#if defined(PDUR_CONFIG_SINGLE_TPTX_LO)
#define PduR_DcmToLo NULL_PTR
#else
static CONST(PduR_RT_UpToLo,PDUR_CONST ) PduR_DcmToLo[] = {
    { CanTpConf_CanTpTxNSdu_UDS_Tx_Can_Network_0_Phys_PduR2CanTp, (PduR_loTransmitFP)PduR_RF_CanTp_Transmit, (PduR_loCancelTransmitFP)PduR_RF_CanTp_CancelTransmit },    /*DcmOnCan0_Tx_Can_Network_0_CANNODE_0_Phys_Dcm2PduR*/
    { CanTpConf_CanTpTxNSdu_UDS_Tx_Network_1_Phys_PduR2CanTp, (PduR_loTransmitFP)PduR_RF_CanTp_Transmit, (PduR_loCancelTransmitFP)PduR_RF_CanTp_CancelTransmit }    /*DcmOnCan1_Tx_Can_Network_1_CANNODE_0_Phys_Dcm2PduR*/

};
#endif /* PDUR_CONFIG_SINGLE_IFTX_LO */

/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#define PDUR_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "PduR_MemMap.h"

/* Generating PbCfg_c::PduR_LoIfRxToUp_PBcfg_c::loIfRx_To_Up */
    
        

/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#define PDUR_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "PduR_MemMap.h"
#if defined(PDUR_CONFIG_SINGLE_IFRX)
#define PduR_CanIfRxToUp   NULL_PTR
#else
static CONST( PduR_RT_LoIfRxToUp, PDUR_CONST ) PduR_CanIfRxToUp[] = {        
    { ComConf_ComIPdu_BMS_01_Can_Network_0_CANNODE_0, (PduR_upIfRxIndicationFP) PduR_RF_Com_RxIndication },   /*BMS_01_Can_Network_0_CANNODE_0_CanIf2PduR*/        
    { ComConf_ComIPdu_SysBoot_Rx_Can_Network_1_CANNODE_0, (PduR_upIfRxIndicationFP) PduR_RF_Com_RxIndication },   /*SysBoot_Rx_Can_Network_1_CANNODE_0_CanIf2PduR*/        
    { ComConf_ComIPdu_TOOL_01_Can_Network_1_CANNODE_0, (PduR_upIfRxIndicationFP) PduR_RF_Com_RxIndication },   /*TOOL_01_Can_Network_1_CANNODE_0_CanIf2PduR*/        
    { ComConf_ComIPdu_VCU_01_Can_Network_0_CANNODE_0, (PduR_upIfRxIndicationFP) PduR_RF_Com_RxIndication },   /*VCU_01_Can_Network_0_CANNODE_0_CanIf2PduR*/        
    { ComConf_ComIPdu_VCU_02_Can_Network_0_CANNODE_0, (PduR_upIfRxIndicationFP) PduR_RF_Com_RxIndication },   /*VCU_02_Can_Network_0_CANNODE_0_CanIf2PduR*/        
    { ComConf_ComIPdu_VCU_03_Can_Network_0_CANNODE_0, (PduR_upIfRxIndicationFP) PduR_RF_Com_RxIndication },   /*VCU_03_Can_Network_0_CANNODE_0_CanIf2PduR*/        
    { ComConf_ComIPdu_VCU_04_Can_Network_0_CANNODE_0, (PduR_upIfRxIndicationFP) PduR_RF_Com_RxIndication },   /*VCU_04_Can_Network_0_CANNODE_0_CanIf2PduR*/        
    { ComConf_ComIPdu_VCU_05_Can_Network_0_CANNODE_0, (PduR_upIfRxIndicationFP) PduR_RF_Com_RxIndication },   /*VCU_05_Can_Network_0_CANNODE_0_CanIf2PduR*/        
    { ComConf_ComIPdu_VCU_06_Can_Network_0_CANNODE_0, (PduR_upIfRxIndicationFP) PduR_RF_Com_RxIndication },   /*VCU_06_Can_Network_0_CANNODE_0_CanIf2PduR*/        
    { ComConf_ComIPdu_VCU_07_Mask_Can_Network_0_CANNODE_0, (PduR_upIfRxIndicationFP) PduR_RF_Com_RxIndication }    /*VCU_07_Mask_Can_Network_0_CANNODE_0_CanIf2PduR*/
 };
#endif  /* PDUR_CONFIG_SINGLE_IFRX */

/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#define PDUR_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "PduR_MemMap.h"


        
    
/* Generating PbCfg_c::PduR_LoIfDTxToUp_PBcfg_c::loIf_DTxToUp */
    
        

/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#define PDUR_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "PduR_MemMap.h"
#if defined(PDUR_CONFIG_SINGLE_IFTX_UP )
#define PduR_CanIfTxToUp NULL_PTR
#else

static CONST(PduR_RT_LoIfTxToUp, PDUR_CONST ) PduR_CanIfTxToUp [] = { 
{ ComConf_ComIPdu_DIAG_01_Can_Network_1_CANNODE_0 , (PduR_upIfTxConfirmationFP) PduR_RF_Com_TxConfirmation} ,   /* Index: 0  SrcPdu: DIAG_01_Can_Network_1_CANNODE_0_Com2PduR  DestPdu: DIAG_01_Can_Network_1_CANNODE_0_PduR2CanIf*/
{ ComConf_ComIPdu_PEB_01_Can_Network_0_CANNODE_0 , (PduR_upIfTxConfirmationFP) PduR_RF_Com_TxConfirmation} ,   /* Index: 1  SrcPdu: PEB_01_Can_Network_0_CANNODE_0_Com2PduR  DestPdu: PEB_01_Can_Network_0_CANNODE_0_PduR2CanIf*/
{ ComConf_ComIPdu_PEB_02_Can_Network_0_CANNODE_0 , (PduR_upIfTxConfirmationFP) PduR_RF_Com_TxConfirmation} ,   /* Index: 2  SrcPdu: PEB_02_Can_Network_0_CANNODE_0_Com2PduR  DestPdu: PEB_02_Can_Network_0_CANNODE_0_PduR2CanIf*/
{ ComConf_ComIPdu_PEB_03_Can_Network_0_CANNODE_0 , (PduR_upIfTxConfirmationFP) PduR_RF_Com_TxConfirmation} ,   /* Index: 3  SrcPdu: PEB_03_Can_Network_0_CANNODE_0_Com2PduR  DestPdu: PEB_03_Can_Network_0_CANNODE_0_PduR2CanIf*/
{ ComConf_ComIPdu_PEB_04_Can_Network_0_CANNODE_0 , (PduR_upIfTxConfirmationFP) PduR_RF_Com_TxConfirmation} ,   /* Index: 4  SrcPdu: PEB_04_Can_Network_0_CANNODE_0_Com2PduR  DestPdu: PEB_04_Can_Network_0_CANNODE_0_PduR2CanIf*/
{ ComConf_ComIPdu_PEB_05_Can_Network_0_CANNODE_0 , (PduR_upIfTxConfirmationFP) PduR_RF_Com_TxConfirmation} ,   /* Index: 5  SrcPdu: PEB_05_Can_Network_0_CANNODE_0_Com2PduR  DestPdu: PEB_05_Can_Network_0_CANNODE_0_PduR2CanIf*/
{ ComConf_ComIPdu_PEB_06_Can_Network_0_CANNODE_0 , (PduR_upIfTxConfirmationFP) PduR_RF_Com_TxConfirmation} ,   /* Index: 6  SrcPdu: PEB_06_Can_Network_0_CANNODE_0_Com2PduR  DestPdu: PEB_06_Can_Network_0_CANNODE_0_PduR2CanIf*/
{ ComConf_ComIPdu_PEB_07_Can_Network_0_CANNODE_0 , (PduR_upIfTxConfirmationFP) PduR_RF_Com_TxConfirmation} ,   /* Index: 7  SrcPdu: PEB_07_Can_Network_0_CANNODE_0_Com2PduR  DestPdu: PEB_07_Can_Network_0_CANNODE_0_PduR2CanIf*/
{ ComConf_ComIPdu_PEB_08_Can_Network_0_CANNODE_0 , (PduR_upIfTxConfirmationFP) PduR_RF_Com_TxConfirmation} ,   /* Index: 8  SrcPdu: PEB_08_Can_Network_0_CANNODE_0_Com2PduR  DestPdu: PEB_08_Can_Network_0_CANNODE_0_PduR2CanIf*/
{ ComConf_ComIPdu_PEB_09_Can_Network_0_CANNODE_0 , (PduR_upIfTxConfirmationFP) PduR_RF_Com_TxConfirmation} ,   /* Index: 9  SrcPdu: PEB_09_Can_Network_0_CANNODE_0_Com2PduR  DestPdu: PEB_09_Can_Network_0_CANNODE_0_PduR2CanIf*/
{ ComConf_ComIPdu_SysBoot_Tx_Can_Network_1_CANNODE_0 , (PduR_upIfTxConfirmationFP) PduR_RF_Com_TxConfirmation}     /* Index: 10  SrcPdu: SysBoot_Tx_Can_Network_1_CANNODE_0_Com2PduR  DestPdu: SysBoot_Tx_Can_Network_1_CANNODE_0_PduR2CanIf*/
};
#endif  /* PDUR_CONFIG_SINGLE_IFTX_UP */

/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#define PDUR_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "PduR_MemMap.h"

        
    
/* Generating PbCfg_c::PduR_LoIfTTxToUp_PBcfg_c::loIf_TTxToUp */
    
/* Generating PbCfg_c::PduR_LoTpRxToUp_PBcfg_c::loTpRx_To_Up */

        

/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#define PDUR_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "PduR_MemMap.h"
#if defined ( PDUR_CONFIG_SINGLE_TPRX )
#define PduR_CanTpRxToUp   NULL_PTR
#else
static CONST( PduR_RT_LoTpRxToUp, PDUR_CONST ) PduR_CanTpRxToUp[] = {
    {DcmConf_DcmDslProtocolRx_DcmOnCan0_Func_Can_Network_0_CANNODE_0_PduR2Dcm, (PduR_upTpStartOfReceptionFP) PduR_RF_Dcm_StartOfReception,(PduR_upTpProvideRxBufFP) PduR_RF_Dcm_CopyRxData,(PduR_upTpRxIndicationFP) PduR_RF_Dcm_TpRxIndication },   /*DcmOnCan0_Func_Can_Network_0_CANNODE_0_CanTp2PduR*/
    {DcmConf_DcmDslProtocolRx_DcmOnCan0_Phys_Can_Network_0_CANNODE_0_PduR2Dcm, (PduR_upTpStartOfReceptionFP) PduR_RF_Dcm_StartOfReception,(PduR_upTpProvideRxBufFP) PduR_RF_Dcm_CopyRxData,(PduR_upTpRxIndicationFP) PduR_RF_Dcm_TpRxIndication },   /*DcmOnCan0_Phys_Can_Network_0_CANNODE_0_CanTp2PduR*/
    {DcmConf_DcmDslProtocolRx_DcmOnCan1_Func_Can_Network_1_CANNODE_0_PduR2Dcm, (PduR_upTpStartOfReceptionFP) PduR_RF_Dcm_StartOfReception,(PduR_upTpProvideRxBufFP) PduR_RF_Dcm_CopyRxData,(PduR_upTpRxIndicationFP) PduR_RF_Dcm_TpRxIndication },   /*DcmOnCan1_Func_Can_Network_1_CANNODE_0_CanTp2PduR*/
    {DcmConf_DcmDslProtocolRx_DcmOnCan1_Phys_Can_Network_1_CANNODE_0_PduR2Dcm, (PduR_upTpStartOfReceptionFP) PduR_RF_Dcm_StartOfReception,(PduR_upTpProvideRxBufFP) PduR_RF_Dcm_CopyRxData,(PduR_upTpRxIndicationFP) PduR_RF_Dcm_TpRxIndication }    /*DcmOnCan1_Phys_Can_Network_1_CANNODE_0_CanTp2PduR*/
};
#endif  /* PDUR_CONFIG_SINGLE_TPRX */

/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#define PDUR_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "PduR_MemMap.h"


        
    
/* Generating PbCfg_c::PduR_LoTpTxToUp_PBcfg_c::loTpTx_To_Up */
    
        

/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#define PDUR_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "PduR_MemMap.h"
#if defined(PDUR_CONFIG_SINGLE_TPTX_UP )
#define PduR_CanTpTxToUp NULL_PTR
#else
static CONST(PduR_RT_LoTpTxToUp, PDUR_CONST ) PduR_CanTpTxToUp [] = {  
    { DcmConf_DcmDslProtocolTx_DcmOnCan0_Tx_Can_Network_0_CANNODE_0_Phys_Dcm2PduR, (PduR_upTpProvideTxBufFP) PduR_RF_Dcm_CopyTxData,(PduR_upTpTxConfirmationFP) PduR_RF_Dcm_TpTxConfirmation },   /*Index: 0 DcmOnCan0_Tx_Can_Network_0_CANNODE_0_Phys_Dcm2PduR*/
    { DcmConf_DcmDslProtocolTx_DcmOnCan1_Tx_Can_Network_1_CANNODE_0_Phys_Dcm2PduR, (PduR_upTpProvideTxBufFP) PduR_RF_Dcm_CopyTxData,(PduR_upTpTxConfirmationFP) PduR_RF_Dcm_TpTxConfirmation }    /*Index: 1 DcmOnCan1_Tx_Can_Network_1_CANNODE_0_Phys_Dcm2PduR*/
};
#endif  /* PDUR_CONFIG_SINGLE_TPTX_UP */

/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#define PDUR_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "PduR_MemMap.h"


        
    
/* Generating PbCfg_c::PduR_Mc_ComToLo_PBcfg_c::mcComToLow */
/* Generating PbCfg_c::PduR_Mc_DcmToLo_PBcfg_c::mcDcmToLow */
/* Generating PbCfg_c::PduR_Mc_IpduMToLo_PBcfg_c::MC_IpduMUp_Lo */
/* Generating PbCfg_c::PduR_Mc_TpTxToUp_PBcfg_c::xpandMcTpTxToUp */
/* Generating PbCfg_c::PduR_Cdd_PBcfg_c::Xpand_Cdd_body */
/* Generating PbCfg_c::PduR_Mc_GwToLo_PBcfg_c::DisplayPduR_mcGwToLo */
/* Generating PbCfg_c::PduR_GwIfTx_PBcfg_c::display_GwIfTx */
/* Generating PbCfg_c::PduR_GwIf_PBcfg_c::display_GwIf */
/* Generating PbCfg_c::PduR_Gw_IfBuf_PBcfg_c::PduR_gw_Buf_If_structure */
/* Generating PbCfg_c::PduR_Rpg_PBcfg_c::display_PduR_RPG*/


#if defined(PDUR_MODE_DEPENDENT_ROUTING) && (PDUR_MODE_DEPENDENT_ROUTING != 0)


/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#define PDUR_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "PduR_MemMap.h"

static CONST (PduR_RPGInfoType, PDUR_CONST) PduR_RPGInfo[] = {

    {
     NULL_PTR,
     PDUR_RPGID_NULL,
     0
    },   /* PDUR_RPGID_NULL */

    
};

/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#define PDUR_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "PduR_MemMap.h"

/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#define PDUR_START_SEC_CONFIG_DATA_POSTBUILD_8
#include "PduR_MemMap.h"
/* Routing enable disbale flag to control routing. */
CONST(boolean, PDUR_CONST) PduR_RPG_EnRouting[] =
{
  TRUE, /*PDUR_RPGID_NULL*/
  
};

/* ------------------------------------------------------------------------ */
/* End section for constants */
#define PDUR_STOP_SEC_CONFIG_DATA_POSTBUILD_8
#include "PduR_MemMap.h"


#endif /* #if defined(PDUR_MODE_DEPENDENT_ROUTING) && (PDUR_MODE_DEPENDENT_ROUTING != 0) */


/* Generating PbCfg_c::PduR_Gw_TpBuf_PBcfg_c::PduR_gw_Buf_TP_structure*/

    /* Generating PbCfg_c::PduR_GwTp_PBcfg_c::display_GwTp */
    /* Generating PbCfg_c::PduR_PbConfigType_PBcfg_c::PduR_BswLoCfg */

/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#define PDUR_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "PduR_MemMap.h"
static CONST( PduR_LoTpConfig, PDUR_CONST ) PduR_LoTpCfg[] = {
  {
    PduR_CanTpRxToUp,       /* CanTp */
    PduR_CanTpTxToUp,       /* CanTp */
    4,        /* CanTp RxToUp Number Of Entries*/
    2     /* CanTp TxToUp Number Of Entries*/
    }
  };

/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#define PDUR_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "PduR_MemMap.h"

/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#define PDUR_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "PduR_MemMap.h"
static CONST( PduR_LoIfDConfig, PDUR_CONST ) PduR_LoIfDCfg[] = {
  {
    PduR_CanIfRxToUp,       /* CanIf */
    PduR_CanIfTxToUp,       /* CanIf */
    10,        /* CanIf RxToUp NrEntries*/
    11      /* CanIf TxToUp NrEntries*/
    }
  };

/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#define PDUR_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "PduR_MemMap.h"
/* Generating PbCfg_c::PduR_PbConfigType_PBcfg_c::PduR_BswUpCfg */

/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#define PDUR_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "PduR_MemMap.h"
static CONST( PduR_UpConfig, PDUR_CONST ) PduR_UpTpCfg[] = {
  {
    PduR_DcmToLo,     /* Dcm */
    NULL_PTR,       /* mcDcmToLo */
    2      /* Dcm */
    }
  };

/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#define PDUR_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "PduR_MemMap.h"


/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#define PDUR_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "PduR_MemMap.h"
static CONST( PduR_UpConfig, PDUR_CONST ) PduR_UpIfCfg[] = {
  {
    PduR_comToLo,     /* Com */
    NULL_PTR,       /* mcComToLo */
    11      /* Com */
    }
  };

/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#define PDUR_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "PduR_MemMap.h"
/* Generating PbCfg_c::PduR_Cdd_PBcfg_c::PduR_CddCfg */
/* Generating PbCfg_c::PduR_PbConfigType_PBcfg_c::PduR_BswUpToLoRxCfg */


    


/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#define PDUR_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "PduR_MemMap.h"

CONST( PduR_RPTablesType, PDUR_CONST ) PduR_RoutingPathTables = {
    (P2CONST( PduR_loTransmitFuncType, AUTOMATIC, PDUR_CONST ))             PduR_loTransmitTable,
    (P2CONST( PduR_loCancelReceiveFuncType, AUTOMATIC,  PDUR_CONST))        PduR_loCancelRxTable,
    (P2CONST( PduR_loCancelTransmitFuncType, AUTOMATIC, PDUR_CONST ))       PduR_loCancelTransmitTable,
    (P2CONST( PduR_upIfRxIndicationFuncType, AUTOMATIC, PDUR_CONST ))       PduR_upIfRxIndicationTable,
    (P2CONST( PduR_upIfTxConfirmationFuncType, AUTOMATIC, PDUR_CONST ))     PduR_upIfTxConfirmationTable,
    (P2CONST( PduR_upTpCopyRxDataFuncType, AUTOMATIC, PDUR_CONST ))         PduR_upTpCopyRxDataTable,
    (P2CONST( PduR_upTpStartOfReceptionFuncType, AUTOMATIC, PDUR_CONST ))   PduR_upTpStartOfReceptionTable,
    (P2CONST( PduR_upTpRxIndicationFuncType, AUTOMATIC, PDUR_CONST ))       PduR_upTpRxIndicationTable,
    (P2CONST( PduR_upTpCopyTxDataFuncType, AUTOMATIC, PDUR_CONST ))         PduR_upTpCopyTxDataTable,
    (P2CONST( PduR_upTpTxConfirmationFuncType, AUTOMATIC, PDUR_CONST ))     PduR_upTpTxConfirmationTable,
    (P2CONST( PduR_upIfTriggerTxFuncType, AUTOMATIC, PDUR_CONST ))          PduR_upIfTriggerTxTable

};


/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#define PDUR_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "PduR_MemMap.h"

    
/*
    These structures are generated by the code generator tool. Respective module's function names are generated
    only if it is present in the PduR_PbCfg.c file in any one of the entries.
*/


/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#define PDUR_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "PduR_MemMap.h"


CONST(PduR_loTransmitFuncType, PDUR_CONST) PduR_loTransmitTable[] =
{
    {&PduR_RF_CanIf_Transmit_Func},
    {&PduR_RF_CanTp_Transmit_Func}
};




CONST(PduR_loCancelReceiveFuncType, PDUR_CONST) PduR_loCancelRxTable[] =
{
    {NULL_PTR}
};




CONST(PduR_loCancelTransmitFuncType, PDUR_CONST) PduR_loCancelTransmitTable[] =
{
    {&PduR_IH_CancelTransmit_Func},
    {&PduR_RF_CanTp_CancelTransmit_Func}
};



CONST(PduR_upIfRxIndicationFuncType, PDUR_CONST) PduR_upIfRxIndicationTable[] =
{
    {&PduR_RF_Com_RxIndication_Func}
};



CONST(PduR_upIfTxConfirmationFuncType, PDUR_CONST) PduR_upIfTxConfirmationTable[] =
{
    {&PduR_RF_Com_TxConfirmation_Func}
};



CONST(PduR_upIfTriggerTxFuncType, PDUR_CONST) PduR_upIfTriggerTxTable[] =
{
    {NULL_PTR}
};



CONST(PduR_upTpCopyRxDataFuncType, PDUR_CONST) PduR_upTpCopyRxDataTable[] =
{
    {&PduR_RF_Dcm_CopyRxData_Func}
};



CONST(PduR_upTpStartOfReceptionFuncType, PDUR_CONST) PduR_upTpStartOfReceptionTable[] =
{
    {&PduR_RF_Dcm_StartOfReception_Func}
};



CONST(PduR_upTpRxIndicationFuncType, PDUR_CONST) PduR_upTpRxIndicationTable[] =
{
    {&PduR_RF_Dcm_TpRxIndication_Func}
};




CONST(PduR_upTpCopyTxDataFuncType, PDUR_CONST) PduR_upTpCopyTxDataTable[] =
{
    {&PduR_RF_Dcm_CopyTxData_Func}
};



CONST(PduR_upTpTxConfirmationFuncType, PDUR_CONST) PduR_upTpTxConfirmationTable[] =
{
    {&PduR_RF_Dcm_TpTxConfirmation_Func}
};






/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#define PDUR_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "PduR_MemMap.h"
/* Generating PbCfg_c::PduR_PbConfigType_PBcfg_c::pdur_PBConfigType */

/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#define PDUR_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "PduR_MemMap.h"
CONST( PduR_PBConfigType, PDUR_CONST ) PduR_GlobalPBConfig = {
  (P2CONST( PduR_CddConfig, AUTOMATIC, PDUR_CONST )) NULL_PTR,                /* PduR_CddCfg */
     (P2CONST( PduR_LoTpConfig, AUTOMATIC, PDUR_CONST )) PduR_LoTpCfg,           /* Pointer to lowerlayer Tp config structure */
     (P2CONST( PduR_LoIfDConfig, AUTOMATIC, PDUR_CONST )) PduR_LoIfDCfg,         /* Pointer to Direct lowerlayer If config structure */
     (P2CONST( PduR_LoIfTTConfig, AUTOMATIC, PDUR_CONST )) NULL_PTR,             /* PduR_LoIfTTCfg */
     (P2CONST( PduR_UpConfig, AUTOMATIC, PDUR_CONST )) PduR_UpIfCfg,             /* Pointer to Upperlayer If config structure */
     (P2CONST( PduR_UpConfig, AUTOMATIC, PDUR_CONST )) PduR_UpTpCfg,             /* Pointer to Upperlayer Tp config structure */
     (P2CONST( PduR_MT_UpToLo, AUTOMATIC, PDUR_CONST )) NULL_PTR,                /* mcGwToLo */
     (P2CONST( PduR_MT_LoIfTxToUp, AUTOMATIC, PDUR_CONST )) NULL_PTR,            /* McIfRx */
     (P2CONST( PduR_MT_LoTpTxToUp, AUTOMATIC, PDUR_CONST )) NULL_PTR,            /* McTpTx */
     (P2VAR(   PduR_MS_LoTpTxToUp, AUTOMATIC, PDUR_VAR )) NULL_PTR,              /* PduR_msTpTxToUp*/
     (P2CONST( PduR_GT_IfTx, AUTOMATIC, PDUR_CONST )) NULL_PTR,                  /* gwIfTx */
     (P2CONST( PduR_GT_If, AUTOMATIC, PDUR_CONST )) NULL_PTR,                    /* gwIf        */
     (P2CONST( PduR_GT_Tp, AUTOMATIC, PDUR_CONST )) NULL_PTR,                    /* GwTp */
     (P2CONST( PduR_RPTablesType, AUTOMATIC, PDUR_CONST )) &PduR_RoutingPathTables, /* PduR_RoutingPathTables */
#if defined(PDUR_TPGATEWAY_SUPPORT) && (PDUR_TPGATEWAY_SUPPORT != STD_OFF)
    (P2CONST(PduR_GwTp_SessionListType, AUTOMATIC, PDUR_CONST )) NULL_PTR, /*PduR_TpSession_Dynamic*/
#endif
#if defined(PDUR_MULTICAST_TO_IF_SUPPORT) && (PDUR_MULTICAST_TO_IF_SUPPORT != 0)
     (P2CONST(PduR_UpIfTxConf_Config, AUTOMATIC, PDUR_CONST)) PduR_UpIfTxConf_ConfigList,
#endif
#if defined(PDUR_MODE_DEPENDENT_ROUTING) && (PDUR_MODE_DEPENDENT_ROUTING != 0)
     (P2CONST (PduR_RPGInfoType, AUTOMATIC, PDUR_CONST))        PduR_RPGInfo,        /* RoutingPathGroup ConfigInfo */
     (P2CONST (boolean, AUTOMATIC, PDUR_CONST))   PduR_RPG_EnRouting,  /* RoutingControl StatusInfo */
     (P2VAR  (boolean , TYPEDEF , PDUR_VAR))  PduR_RPG_Status,        /*RAM status for each RPG*/
     (PduR_RoutingPathGroupIdType)                              0,        /* Number of RPGs.*/
#endif
     (P2CONST (PduR_UpTpToLoTpRxConfig, TYPEDEF, PDUR_CONST)) NULL_PTR,          /* Pointer to PduR_UpTpToLoTpRxConfig structure for supporting Cancel Receive API */
0,                  /* PDUR_CONFIGURATION_ID */
0, /*Total no of Gw Tp Routing Path*/
0, /*Total no of Gw If Routing path*/
     (PduIdType) 0       /* McTpTx */
};

/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#define PDUR_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "PduR_MemMap.h"







#define PDUR_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "PduR_MemMap.h"
CONST(PduR_ConfigType, PDUR_CONST) PduR_Config = {
    NULL_PTR,    /* Void pointer initialised with null pointer as PduR_Config will not be used in case of PDUR_VARIANT_PRE_COMPILE */
    NULL_PTR
};

#define PDUR_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "PduR_MemMap.h"


