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

#ifndef PDUR_CFG_SYMBOLICNAMES_H
#define PDUR_CFG_SYMBOLICNAMES_H

/* Note: Module variant generation is done here, specifically to make below macros available on the inclusion of 
 * PduR_memmap.h header file by other modules without PduR_Cfg.h inclusion */


#define PDUR_VARIANT_PRE_COMPILE    (0)

#define PDUR_VARIANT_POSTBUILD_LOADABLE    (1)

#if !defined(PDUR_CONFIGURATION_VARIANT)
#define PDUR_CONFIGURATION_VARIANT    PDUR_VARIANT_PRE_COMPILE
#endif /* PDUR_CONFIGURATION_VARIANT */




/* For PduRRoutingTable: Symbolic Name reference are generated for Tx Paths and Rx paths
For TxPaths:
PduRConf_PduRSrcPdu_<shortname of PduRSrcPdu> will be used by module which gives PduR_<UpperLayer>Transmit request e.g Com,Dcm,Up-Cdd
PduRConf_PduRDestPdu_<shortname of PduRDestPdu> will be used by module which gives PduR_<LowerLayer>TxConfirmation callback e.g CanIf,CanTp,Low-Cdd

For RxPaths:
PduRConf_PduRSrcPdu_<shortname of PduRSrcPdu> will be used by module which gives PduR_<LowerLayer>RxIndication callback e.g CanIf,CanTp,Low-Cdd */

#define PduRConf_PduRSrcPdu_BMS_01_Can_Network_0_CANNODE_0_CanIf2PduR    0

#define PduRConf_PduRSrcPdu_DIAG_01_Can_Network_1_CANNODE_0_Com2PduR    0
#define PduRConf_PduRDestPdu_DIAG_01_Can_Network_1_CANNODE_0_PduR2CanIf  0

#define PduRConf_PduRSrcPdu_DcmOnCan0_Func_Can_Network_0_CANNODE_0_CanTp2PduR    0
#define PduRConf_PduRDestPdu_DcmOnCan0_Func_Can_Network_0_CANNODE_0_PduR2Dcm  0

#define PduRConf_PduRSrcPdu_DcmOnCan0_Phys_Can_Network_0_CANNODE_0_CanTp2PduR    1
#define PduRConf_PduRDestPdu_DcmOnCan0_Phys_Can_Network_0_CANNODE_0_PduR2Dcm  1

#define PduRConf_PduRSrcPdu_DcmOnCan0_Tx_Can_Network_0_CANNODE_0_Phys_Dcm2PduR    0
#define PduRConf_PduRDestPdu_DcmOnCan0_Tx_Can_Network_0_CANNODE_0_Phys_PduR2CanTp  0

#define PduRConf_PduRSrcPdu_DcmOnCan1_Func_Can_Network_1_CANNODE_0_CanTp2PduR    2
#define PduRConf_PduRDestPdu_DcmOnCan1_Func_Can_Network_1_CANNODE_0_PduR2Dcm  2

#define PduRConf_PduRSrcPdu_DcmOnCan1_Phys_Can_Network_1_CANNODE_0_CanTp2PduR    3
#define PduRConf_PduRDestPdu_DcmOnCan1_Phys_Can_Network_1_CANNODE_0_PduR2Dcm  3

#define PduRConf_PduRSrcPdu_DcmOnCan1_Tx_Can_Network_1_CANNODE_0_Phys_Dcm2PduR    1
#define PduRConf_PduRDestPdu_DcmOnCan1_Tx_Can_Network_1_CANNODE_0_Phys_PduR2CanTp  1

#define PduRConf_PduRSrcPdu_PEB_01_Can_Network_0_CANNODE_0_Com2PduR    1
#define PduRConf_PduRDestPdu_PEB_01_Can_Network_0_CANNODE_0_PduR2CanIf  1

#define PduRConf_PduRSrcPdu_PEB_02_Can_Network_0_CANNODE_0_Com2PduR    2
#define PduRConf_PduRDestPdu_PEB_02_Can_Network_0_CANNODE_0_PduR2CanIf  2

#define PduRConf_PduRSrcPdu_PEB_03_Can_Network_0_CANNODE_0_Com2PduR    3
#define PduRConf_PduRDestPdu_PEB_03_Can_Network_0_CANNODE_0_PduR2CanIf  3

#define PduRConf_PduRSrcPdu_PEB_04_Can_Network_0_CANNODE_0_Com2PduR    4
#define PduRConf_PduRDestPdu_PEB_04_Can_Network_0_CANNODE_0_PduR2CanIf  4

#define PduRConf_PduRSrcPdu_PEB_05_Can_Network_0_CANNODE_0_Com2PduR    5
#define PduRConf_PduRDestPdu_PEB_05_Can_Network_0_CANNODE_0_PduR2CanIf  5

#define PduRConf_PduRSrcPdu_PEB_06_Can_Network_0_CANNODE_0_Com2PduR    6
#define PduRConf_PduRDestPdu_PEB_06_Can_Network_0_CANNODE_0_PduR2CanIf  6

#define PduRConf_PduRSrcPdu_PEB_07_Can_Network_0_CANNODE_0_Com2PduR    7
#define PduRConf_PduRDestPdu_PEB_07_Can_Network_0_CANNODE_0_PduR2CanIf  7

#define PduRConf_PduRSrcPdu_PEB_08_Can_Network_0_CANNODE_0_Com2PduR    8
#define PduRConf_PduRDestPdu_PEB_08_Can_Network_0_CANNODE_0_PduR2CanIf  8

#define PduRConf_PduRSrcPdu_PEB_09_Can_Network_0_CANNODE_0_Com2PduR    9
#define PduRConf_PduRDestPdu_PEB_09_Can_Network_0_CANNODE_0_PduR2CanIf  9

#define PduRConf_PduRSrcPdu_SysBoot_Rx_Can_Network_1_CANNODE_0_CanIf2PduR    1

#define PduRConf_PduRSrcPdu_SysBoot_Tx_Can_Network_1_CANNODE_0_Com2PduR    10
#define PduRConf_PduRDestPdu_SysBoot_Tx_Can_Network_1_CANNODE_0_PduR2CanIf  10

#define PduRConf_PduRSrcPdu_TOOL_01_Can_Network_1_CANNODE_0_CanIf2PduR    2

#define PduRConf_PduRSrcPdu_VCU_01_Can_Network_0_CANNODE_0_CanIf2PduR    3

#define PduRConf_PduRSrcPdu_VCU_02_Can_Network_0_CANNODE_0_CanIf2PduR    4

#define PduRConf_PduRSrcPdu_VCU_03_Can_Network_0_CANNODE_0_CanIf2PduR    5

#define PduRConf_PduRSrcPdu_VCU_04_Can_Network_0_CANNODE_0_CanIf2PduR    6

#define PduRConf_PduRSrcPdu_VCU_05_Can_Network_0_CANNODE_0_CanIf2PduR    7

#define PduRConf_PduRSrcPdu_VCU_06_Can_Network_0_CANNODE_0_CanIf2PduR    8

#define PduRConf_PduRSrcPdu_VCU_07_Mask_Can_Network_0_CANNODE_0_CanIf2PduR    9




#endif /* PDUR_CFG_SYMBOLICNAMES_H */
