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

#ifndef COM_PBCFG_H
#define COM_PBCFG_H

/*  START: Local #defines  */

#define COM_NUM_RX_SIGNALS        50u
#define COM_NUM_TX_SIGNALS        79u
#define COM_NUM_TX_IPDU         11u
#define COM_NUM_RX_IPDU         10u
#define COM_NUM_GWSRC_SIGNALS  0u
#define COM_NUM_GWSRC_GRPSIGNALS  0u
#define COM_NUM_GWSRC_IPDUS     0u
#define COM_NUM_GRPSIG_NOGW     0u

#ifdef COM_F_ONEEVERYN
#define COM_NUM_OF_SIG_GRPSIG_WITH_ONE_EVERY_N 0u
#endif /* #ifdef COM_F_ONEEVERYN */




#define COM_UPDATE_MAX      0xFF    /* max ipdu size */


#ifdef COM_RxIPduDeferredProcessing
    /* Buffer to hold data for deferred signal processing */
    #define COM_MAX_DEFERRED_IPDUBUFF_SIZE 8
#endif /* #ifdef COM_RxIPduDeferredProcessing */


/* START: I-PDU Buffers */
/* ComIPdu*/

/* ------------------------------------------------------------------------ */
/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_POSTBUILD_8
#include "Com_MemMap.h"
        extern VAR(uint8,COM_VAR) Com_IpduBuf_DIAG_01_Can_Network_1_CANNODE_0[];
        extern VAR(uint8,COM_VAR) Com_IpduBuf_PEB_01_Can_Network_0_CANNODE_0[];
        extern VAR(uint8,COM_VAR) Com_IpduBuf_PEB_03_Can_Network_0_CANNODE_0[];
        extern VAR(uint8,COM_VAR) Com_IpduBuf_PEB_04_Can_Network_0_CANNODE_0[];
        extern VAR(uint8,COM_VAR) Com_IpduBuf_PEB_08_Can_Network_0_CANNODE_0[];
        extern VAR(uint8,COM_VAR) Com_IpduBuf_PEB_09_Can_Network_0_CANNODE_0[];
        extern VAR(uint8,COM_VAR) Com_IpduBuf_PEB_02_Can_Network_0_CANNODE_0[];
        extern VAR(uint8,COM_VAR) Com_IpduBuf_PEB_05_Can_Network_0_CANNODE_0[];
        extern VAR(uint8,COM_VAR) Com_IpduBuf_PEB_07_Can_Network_0_CANNODE_0[];
        extern VAR(uint8,COM_VAR) Com_IpduBuf_SysBoot_Tx_Can_Network_1_CANNODE_0[];
        extern VAR(uint8,COM_VAR) Com_IpduBuf_PEB_06_Can_Network_0_CANNODE_0[];


/* ------------------------------------------------------------------------ */
/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_POSTBUILD_8
#include "Com_MemMap.h"

#ifdef COM_TXDOUBLEBUFFER

/* ------------------------------------------------------------------------ */
/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_POSTBUILD_8
#include "Com_MemMap.h"

        extern VAR(uint8,COM_VAR) Com_LocalBuf_DIAG_01_Can_Network_1_CANNODE_0[] ;
        extern VAR(uint8,COM_VAR) Com_LocalBuf_PEB_01_Can_Network_0_CANNODE_0[] ;
        extern VAR(uint8,COM_VAR) Com_LocalBuf_PEB_03_Can_Network_0_CANNODE_0[] ;
        extern VAR(uint8,COM_VAR) Com_LocalBuf_PEB_04_Can_Network_0_CANNODE_0[] ;
        extern VAR(uint8,COM_VAR) Com_LocalBuf_PEB_08_Can_Network_0_CANNODE_0[] ;
        extern VAR(uint8,COM_VAR) Com_LocalBuf_PEB_09_Can_Network_0_CANNODE_0[] ;
        extern VAR(uint8,COM_VAR) Com_LocalBuf_PEB_02_Can_Network_0_CANNODE_0[] ;
        extern VAR(uint8,COM_VAR) Com_LocalBuf_PEB_05_Can_Network_0_CANNODE_0[] ;
        extern VAR(uint8,COM_VAR) Com_LocalBuf_PEB_07_Can_Network_0_CANNODE_0[] ;
        extern VAR(uint8,COM_VAR) Com_LocalBuf_SysBoot_Tx_Can_Network_1_CANNODE_0[] ;
        extern VAR(uint8,COM_VAR) Com_LocalBuf_PEB_06_Can_Network_0_CANNODE_0[] ;


/* ------------------------------------------------------------------------ */
/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_POSTBUILD_8
#include "Com_MemMap.h"
#endif

/* LocalBuffer for Rx Ipdus */

/* ------------------------------------------------------------------------ */
/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_POSTBUILD_8
#include "Com_MemMap.h"

        extern VAR(uint8,COM_VAR) Com_LocalBuf_BMS_01_Can_Network_0_CANNODE_0[];
        extern VAR(uint8,COM_VAR) Com_LocalBuf_SysBoot_Rx_Can_Network_1_CANNODE_0[];
        extern VAR(uint8,COM_VAR) Com_LocalBuf_TOOL_01_Can_Network_1_CANNODE_0[];
        extern VAR(uint8,COM_VAR) Com_LocalBuf_VCU_01_Can_Network_0_CANNODE_0[];
        extern VAR(uint8,COM_VAR) Com_LocalBuf_VCU_02_Can_Network_0_CANNODE_0[];
        extern VAR(uint8,COM_VAR) Com_LocalBuf_VCU_03_Can_Network_0_CANNODE_0[];
        extern VAR(uint8,COM_VAR) Com_LocalBuf_VCU_04_Can_Network_0_CANNODE_0[];
        extern VAR(uint8,COM_VAR) Com_LocalBuf_VCU_05_Can_Network_0_CANNODE_0[];
        extern VAR(uint8,COM_VAR) Com_LocalBuf_VCU_06_Can_Network_0_CANNODE_0[];
        extern VAR(uint8,COM_VAR) Com_LocalBuf_VCU_07_Mask_Can_Network_0_CANNODE_0[];


/* ------------------------------------------------------------------------ */
/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_POSTBUILD_8
#include "Com_MemMap.h"
/* END: I-PDU Buffers */



/*Start: Signal Buffer -----> uint8/sint8/boolean/uint8[n]*/

/* ------------------------------------------------------------------------ */
/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_POSTBUILD_8
#include "Com_MemMap.h"
extern VAR(uint8,COM_VAR) Com_SigType_u8[];

/* ------------------------------------------------------------------------ */
/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_POSTBUILD_8
#include "Com_MemMap.h"
/*End: Signal Buffer -----> uint8/sint8/boolean/uint8[n]*/

/*Start: Signal Buffer -----> uint16/sint16*/

/* ------------------------------------------------------------------------ */
/* Begin section for RAM variables of uint16 type */
#define COM_START_SEC_VAR_CLEARED_POSTBUILD_16
#include "Com_MemMap.h"
extern VAR(uint16,COM_VAR) Com_SigType_u16[];

/* ------------------------------------------------------------------------ */
/* End section for RAM variables of uint16 type */
#define COM_STOP_SEC_VAR_CLEARED_POSTBUILD_16
#include "Com_MemMap.h"
/*End: Signal Buffer -----> uint16/sint16*/

/*Start: Signal Buffer -----> uint32/sint32*/

/* ------------------------------------------------------------------------ */
/* Begin section for RAM variables of uint32 type */
#define COM_START_SEC_VAR_CLEARED_POSTBUILD_32
#include "Com_MemMap.h"
extern VAR(uint32,COM_VAR) Com_SigType_u32[];

/* ------------------------------------------------------------------------ */
/* End section for RAM variables of uint32 type */
#define COM_STOP_SEC_VAR_CLEARED_POSTBUILD_32
#include "Com_MemMap.h"
/*End: Signal Buffer -----> uint32/sint32*/

/*Start: Signal Buffer -----> uint64/sint64*/
#ifdef COM_RXSIG_INT64

/* ------------------------------------------------------------------------ */
/* Begin section for RAM variables of uint64 type */
#define COM_START_SEC_VAR_CLEARED_POSTBUILD_64
#include "Com_MemMap.h"
extern VAR(uint64,COM_VAR) Com_SigType_u64[];

/* ------------------------------------------------------------------------ */
/* End section for RAM variables of uint64 type */
#define COM_STOP_SEC_VAR_CLEARED_POSTBUILD_64
#include "Com_MemMap.h"
#endif
/*End: Signal Buffer -----> uint64/sint64*/


#ifdef COM_RXSIG_FLOAT64SUPP

/* ------------------------------------------------------------------------ */
/* Begin section for RAM variables of struct/enum/pointer type */
#define COM_START_SEC_VAR_CLEARED_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"
extern VAR(float64,COM_VAR) Com_SigType_f64[];

/* ------------------------------------------------------------------------ */
/* End section for RAM variables of struct/enum/pointer type */
#define COM_STOP_SEC_VAR_CLEARED_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"
#endif /* #ifdef COM_RXSIG_FLOAT64SUPP */




#ifdef COM_RX_SIGNALGROUP

/*Start: Rx Group Signal Buffer -----> uint8/sint8/boolean/uint8[n]*/

/* ------------------------------------------------------------------------ */
/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_POSTBUILD_8
#include "Com_MemMap.h"

extern VAR(uint8,COM_VAR) Com_RxGrpSigType_u8[];

/* ------------------------------------------------------------------------ */
/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_POSTBUILD_8
#include "Com_MemMap.h"

/*End: Rx Group Signal Buffer -----> uint8/sint8/boolean/uint8[n]*/

/*Start: Rx Group Signal Buffer -----> uint16/sint16*/

/* ------------------------------------------------------------------------ */
/* Begin section for RAM variables of uint16 type */
#define COM_START_SEC_VAR_CLEARED_POSTBUILD_16
#include "Com_MemMap.h"
extern VAR(uint16,COM_VAR) Com_RxGrpSigType_u16[];

/* ------------------------------------------------------------------------ */
/* End section for RAM variables of uint16 type */
#define COM_STOP_SEC_VAR_CLEARED_POSTBUILD_16
#include "Com_MemMap.h"
/*End:Rx Group Signal Buffer -----> uint16/sint16*/

/*Start: Rx Group Signal Buffer -----> uint32/sint32*/

/* ------------------------------------------------------------------------ */
/* Begin section for RAM variables of uint32 type */
#define COM_START_SEC_VAR_CLEARED_POSTBUILD_32
#include "Com_MemMap.h"
extern VAR(uint32,COM_VAR) Com_RxGrpSigType_u32[];

/* ------------------------------------------------------------------------ */
/* End section for RAM variables of uint32 type */
#define COM_STOP_SEC_VAR_CLEARED_POSTBUILD_32
#include "Com_MemMap.h"
/*End: Rx Group Signal Buffer -----> uint32/sint32*/

/*Start: Rx Group Signal Buffer -----> uint64/sint64*/
#ifdef COM_RXGRPSIG_INT64

/* ------------------------------------------------------------------------ */
/* Begin section for RAM variables of uint64 type */
#define COM_START_SEC_VAR_CLEARED_POSTBUILD_64
#include "Com_MemMap.h"
extern VAR(uint64,COM_VAR) Com_RxGrpSigType_u64[];

/* ------------------------------------------------------------------------ */
/* End section for RAM variables of uint64 type */
#define COM_STOP_SEC_VAR_CLEARED_POSTBUILD_64
#include "Com_MemMap.h"
#endif
/*End: Rx Group Signal Buffer -----> uint64/sint64*/


#ifdef COM_RXGRPSIG_FLOAT64SUPP

/* ------------------------------------------------------------------------ */
/* Begin section for RAM variables of struct/enum/pointer type */
#define COM_START_SEC_VAR_CLEARED_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"
extern VAR(float64,COM_VAR) Com_RxGrpSigType_f64[];

/* ------------------------------------------------------------------------ */
/* End section for RAM variables of struct/enum/pointer type */
#define COM_STOP_SEC_VAR_CLEARED_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"
#endif /* #ifdef COM_RXGRPSIG_FLOAT64SUPP */


/*Start:Rx Group Signal second Buffer -----> uint8/sint8/boolean/uint8[n]*/

/* ------------------------------------------------------------------------ */
/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_POSTBUILD_8
#include "Com_MemMap.h"

extern VAR(uint8,COM_VAR) Com_SecondRxGrpSigType_u8[];

/* ------------------------------------------------------------------------ */
/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_POSTBUILD_8
#include "Com_MemMap.h"

/*End: Rx Group Signal second Signal Buffer -----> uint8/sint8/boolean/uint8[n]*/

/*Start: Rx Group Signal second Signal Buffer -----> uint16/sint16*/

/* ------------------------------------------------------------------------ */
/* Begin section for RAM variables of uint16 type */
#define COM_START_SEC_VAR_CLEARED_POSTBUILD_16
#include "Com_MemMap.h"
extern VAR(uint16,COM_VAR) Com_SecondRxGrpSigType_u16[];

/* ------------------------------------------------------------------------ */
/* End section for RAM variables of uint16 type */
#define COM_STOP_SEC_VAR_CLEARED_POSTBUILD_16
#include "Com_MemMap.h"
/*End: Rx Group Signal second Signal Buffer -----> uint16/sint16*/

/*Start: Rx Group Signal second Signal Buffer -----> uint32/sint32*/

/* ------------------------------------------------------------------------ */
/* Begin section for RAM variables of uint32 type */
#define COM_START_SEC_VAR_CLEARED_POSTBUILD_32
#include "Com_MemMap.h"
extern VAR(uint32,COM_VAR) Com_SecondRxGrpSigType_u32[];

/* ------------------------------------------------------------------------ */
/* End section for RAM variables of uint32 type */
#define COM_STOP_SEC_VAR_CLEARED_POSTBUILD_32
#include "Com_MemMap.h"
/*End: Rx Group Signal second Signal Buffer -----> uint32/sint32*/

/*Start: Rx Group Signal second Signal Buffer -----> uint64/sint64*/
#ifdef COM_RXGRPSIG_INT64

/* ------------------------------------------------------------------------ */
/* Begin section for RAM variables of uint64 type */
#define COM_START_SEC_VAR_CLEARED_POSTBUILD_64
#include "Com_MemMap.h"
extern VAR(uint64,COM_VAR) Com_SecondRxGrpSigType_u64[];

/* ------------------------------------------------------------------------ */
/* End section for RAM variables of uint64 type */
#define COM_STOP_SEC_VAR_CLEARED_POSTBUILD_64
#include "Com_MemMap.h"
#endif
/*End: Rx Group Signal second Signal Buffer -----> uint64/sint64*/


#ifdef COM_RXGRPSIG_FLOAT64SUPP

/* ------------------------------------------------------------------------ */
/* Begin section for RAM variables of struct/enum/pointer type */
#define COM_START_SEC_VAR_CLEARED_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"
extern VAR(float64,COM_VAR) Com_SecondRxGrpSigType_f64[];

/* ------------------------------------------------------------------------ */
/* End section for RAM variables of struct/enum/pointer type */
#define COM_STOP_SEC_VAR_CLEARED_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"
#endif /* #ifdef COM_RXGRPSIG_FLOAT64SUPP */


#endif /* #ifdef COM_RX_SIGNALGROUP*/

#ifdef COM_TX_SIGNALGROUP

/*Start: Tx group Signal Buffer -----> uint8/sint8/boolean/uint8[n]*/

/* ------------------------------------------------------------------------ */
/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_POSTBUILD_8
#include "Com_MemMap.h"
extern VAR(uint8,COM_VAR) Com_TxGrpSigType_u8[];

/* ------------------------------------------------------------------------ */
/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_POSTBUILD_8
#include "Com_MemMap.h"
/*End: Tx group Signal Buffer -----> uint8/sint8/boolean/uint8[n]*/

/*Start: Tx group Signal Buffer -----> uint16/sint16*/

/* ------------------------------------------------------------------------ */
/* Begin section for RAM variables of uint16 type */
#define COM_START_SEC_VAR_CLEARED_POSTBUILD_16
#include "Com_MemMap.h"
extern VAR(uint16,COM_VAR) Com_TxGrpSigType_u16[];

/* ------------------------------------------------------------------------ */
/* End section for RAM variables of uint16 type */
#define COM_STOP_SEC_VAR_CLEARED_POSTBUILD_16
#include "Com_MemMap.h"
/*End: Tx group  Signal Buffer -----> uint16/sint16*/

/*Start: Tx group Signal Buffer -----> uint32/sint32*/

/* ------------------------------------------------------------------------ */
/* Begin section for RAM variables of uint32 type */
#define COM_START_SEC_VAR_CLEARED_POSTBUILD_32
#include "Com_MemMap.h"
extern VAR(uint32,COM_VAR) Com_TxGrpSigType_u32[];

/* ------------------------------------------------------------------------ */
/* End section for RAM variables of uint32 type */
#define COM_STOP_SEC_VAR_CLEARED_POSTBUILD_32
#include "Com_MemMap.h"
/*End: Tx group Signal Buffer -----> uint32/sint32*/

/*Start: Tx group Signal Buffer -----> uint64/sint64*/
#ifdef COM_TXGRPSIG_INT64

/* ------------------------------------------------------------------------ */
/* Begin section for RAM variables of uint64 type */
#define COM_START_SEC_VAR_CLEARED_POSTBUILD_64
#include "Com_MemMap.h"
extern VAR(uint64,COM_VAR) Com_TxGrpSigType_u64[];

/* ------------------------------------------------------------------------ */
/* End section for RAM variables of uint64 type */
#define COM_STOP_SEC_VAR_CLEARED_POSTBUILD_64
#include "Com_MemMap.h"
#endif
/*End: Tx group Signal Buffer -----> uint64/sint64*/


#ifdef COM_TXGRPSIG_FLOAT64SUPP
/*Start: Tx group Signal Buffer -----> float64 */

/* ------------------------------------------------------------------------ */
/* Begin section for RAM variables of struct/enum/pointer type */
#define COM_START_SEC_VAR_CLEARED_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"
extern VAR(float64,COM_VAR) Com_TxGrpSigType_f64[];

/* ------------------------------------------------------------------------ */
/* End section for RAM variables of struct/enum/pointer type */
#define COM_STOP_SEC_VAR_CLEARED_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"
/*End: Tx group Signal Buffer -----> float64 */
#endif /* #ifdef COM_TXGRPSIG_FLOAT64SUPP */
#endif /* #ifdef COM_TX_SIGNALGROUP */

#ifdef COM_RxSigUpdateTimeout
#endif /* #ifdef COM_RxSigUpdateTimeout */

#ifdef COM_RxSigGrpUpdateTimeout
#endif /* #ifdef COM_RxSigGrpUpdateTimeout */

#endif   /* COM_PBCFG_H */
