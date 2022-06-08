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
****************************************************************************************************
* This Configuration File is generated using versions (automatically filled in) as listed below.
*
* $Generator__: Xcp / AR42.4.0.1                 Module Package Version
* $Editor_____: 9.0             Tool Version
****************************************************************************************************
</VersionHead>*/

#ifndef  XCP_SYMBOLIC_NAMES_CFG_H
#define  XCP_SYMBOLIC_NAMES_CFG_H

/***************************************************************************************************
* Includes
***************************************************************************************************/


/***************************************************************************************************
* Defines/Macros
***************************************************************************************************/

/*********************** Symbolic names definition ************************/
/**************************************************************************/
/*******       Event Channel number definition          *******************/
/**************************************************************************/
#define XcpConf_XcpEventChannel_XcpEventChannel_2ms            0u
#define XcpConf_XcpEventChannel_XcpEventChannel_10ms            1u
#define XcpConf_XcpEventChannel_XcpEventChannel_100ms            2u

/**************************************************************************/
/*******       Transport Layer Number definition        *******************/
/**************************************************************************/
#define XcpConf_XcpTransportLayer_XcpTransportLayer            0u

/*********************** Symbolic names definition for XcpOnCan ************************/
/**************************************************************************/
/*************          RxPduId Number definition          ****************/
/**************************************************************************/
#define XcpConf_XcpRxPdu_XcpRxPdu_CMD            0u
#define XcpConf_XcpRxPdu_XcpRxPdu_Broadcast            1u

/**************************************************************************/
/*************         TxPduId Number definition           ****************/
/**************************************************************************/
#define XcpConf_XcpTxPdu_XcpTxPdu_RES            0u
#define XcpConf_XcpTxPdu_XcpTxPdu_DAQ0            1u
#define XcpConf_XcpTxPdu_XcpTxPdu_DAQ1            2u
#define XcpConf_XcpTxPdu_XcpTxPdu_DAQ2            3u



#endif   /* #ifndef XCP_SYMBOLIC_NAME_CFG_H */

