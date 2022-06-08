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



/*
 * If COM_DontUseExternalSymbolicNames is defined before including Com_Cfg.h file, then external symbolic names will
 * not be visible.
 * Com_PBcfg.c file should not use external symbolic names.
 * This mechanism is used to prevent the accidental usage of external symbolic names in this file
 * This file should use only internal symbolic name defined in  Com_PBcfg_InternalId.h
 */
#define COM_DontUseExternalSymbolicNames
#include "Com.h"
#include "Com_Cbk.h"
#include "Com_Priv.h"
#include "Com_Types.h"
#include "PduR_Com.h"
#include "Com_PBcfg.h"

/*
 * The file Com_PBcfg_InternalId.h defines internal symbolic names
 * These names should be used in the tables generated in this file
 * Regular symbolic names should not be used here
 */
#include "Com_PBcfg_InternalId.h"


/* START: Tx Signal Details  */

/* ------------------------------------------------------------------------ */
/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"

CONST(Com_Prv_xTxSigCfg_tst ,COM_CONST) Com_Prv_xTxSigCfg_acst[COM_NUM_TX_SIGNALS] =
{
        
    {  /* Diag_Data0_DIAG_01 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        0,                                                /*BitPosition*/

        8,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_DIAG_01_Can_Network_1_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x0,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* Diag_Data1_DIAG_01 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        8,                                                /*BitPosition*/

        8,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_DIAG_01_Can_Network_1_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x0,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* Diag_Data2_DIAG_01 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        16,                                                /*BitPosition*/

        8,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_DIAG_01_Can_Network_1_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x0,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* Diag_Data3_DIAG_01 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        24,                                                /*BitPosition*/

        8,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_DIAG_01_Can_Network_1_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x0,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* Diag_Data4_DIAG_01 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        32,                                                /*BitPosition*/

        8,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_DIAG_01_Can_Network_1_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x0,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* Diag_Data5_DIAG_01 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        40,                                                /*BitPosition*/

        8,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_DIAG_01_Can_Network_1_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x0,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* Diag_Data6_DIAG_01 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        48,                                                /*BitPosition*/

        8,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_DIAG_01_Can_Network_1_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x0,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* Diag_Data7_DIAG_01 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        56,                                                /*BitPosition*/

        8,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_DIAG_01_Can_Network_1_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x0,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* PEB01_ctRoll_PEB_01 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        48,                                                /*BitPosition*/

        4,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_01_Can_Network_0_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x0,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* PEB01_Checksum_PEB_01 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        56,                                                /*BitPosition*/

        8,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_01_Can_Network_0_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x0,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* PEB01_IsCurr_PEB_01 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        21,                                                /*BitPosition*/

        11,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_01_Can_Network_0_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT16
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x2,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* PEB01_stMode_PEB_01 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        52,                                                /*BitPosition*/

        4,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_01_Can_Network_0_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x0,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* PEB01_UdcCurr_PEB_01 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        11,                                                /*BitPosition*/

        10,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_01_Can_Network_0_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT16
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x2,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* PEB01_TrqCurr_PEB_01 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        0,                                                /*BitPosition*/

        11,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_01_Can_Network_0_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT16
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x2,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* PEB01_NCurr_PEB_01 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        32,                                                /*BitPosition*/

        16,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_01_Can_Network_0_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT16
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x2,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* PEB03_TempEpp_PEB_03 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        48,                                                /*BitPosition*/

        8,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_03_Can_Network_0_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x0,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* PEB03_TempCurrStr2_PEB_03 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        40,                                                /*BitPosition*/

        8,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_03_Can_Network_0_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x0,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* PEB03_TempCurrStr1_PEB_03 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        32,                                                /*BitPosition*/

        8,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_03_Can_Network_0_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x0,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* PEB03_IGBTTempW_PEB_03 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        16,                                                /*BitPosition*/

        8,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_03_Can_Network_0_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x0,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* PEB03_IGBTTempV_PEB_03 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        8,                                                /*BitPosition*/

        8,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_03_Can_Network_0_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x0,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* PEB03_IGBTTempU_PEB_03 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        0,                                                /*BitPosition*/

        8,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_03_Can_Network_0_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x0,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* PEB03_TempStr_PEB_03 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        24,                                                /*BitPosition*/

        8,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_03_Can_Network_0_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x0,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* PEB04_TrqCurrWoDmpC_PEB_04 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        53,                                                /*BitPosition*/

        11,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_04_Can_Network_0_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT16
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x2,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* PEB04_stGateDrv_PEB_04 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        37,                                                /*BitPosition*/

        2,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_04_Can_Network_0_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x0,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* PEB04_bDmpCActv_PEB_04 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        36,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_04_Can_Network_0_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = BOOLEAN
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x6,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* PEB04_agRtrElecSnsr_PEB_04 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        40,                                                /*BitPosition*/

        12,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_04_Can_Network_0_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT16
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x2,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* PEB04_Isq_PEB_04 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        24,                                                /*BitPosition*/

        12,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_04_Can_Network_0_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT16
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x2,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* PEB04_Isd_PEB_04 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        12,                                                /*BitPosition*/

        12,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_04_Can_Network_0_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT16
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x2,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* PEB04_OfsAl_PEB_04 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        0,                                                /*BitPosition*/

        12,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_04_Can_Network_0_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT16
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x2,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* PEB08_HwVer_PEB_08 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        16,                                                /*BitPosition*/

        16,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_08_Can_Network_0_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT16
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x2,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* PEB08_stDischg_PEB_08 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        0,                                                /*BitPosition*/

        8,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_08_Can_Network_0_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x0,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* PEB09_stEppFailSt_PEB_09 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        48,                                                /*BitPosition*/

        16,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_09_Can_Network_0_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT16
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x2,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* PEB09_stEppDrvMod_PEB_09 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        19,                                                /*BitPosition*/

        4,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_09_Can_Network_0_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x0,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* PEB09_stEpp_PEB_09 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        1,                                                /*BitPosition*/

        4,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_09_Can_Network_0_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x0,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* PEB09_posEpp_PEB_09 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        24,                                                /*BitPosition*/

        10,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_09_Can_Network_0_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT16
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x2,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* PEB09_IsEpp_PEB_09 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        8,                                                /*BitPosition*/

        11,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_09_Can_Network_0_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT16
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x2,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* PEB09_flgParkEn_PEB_09 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        0,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_09_Can_Network_0_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = BOOLEAN
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x6,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* PEB02_bDernTempIGBT_PEB_02 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        10,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_02_Can_Network_0_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = BOOLEAN
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x6,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* PEB02_bDernTempCool_PEB_02 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        11,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_02_Can_Network_0_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = BOOLEAN
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x6,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* PEB02_bDernN_PEB_02 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        12,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_02_Can_Network_0_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = BOOLEAN
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x6,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* PEB02_TrqAbsMin_PEB_02 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        47,                                                /*BitPosition*/

        11,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_02_Can_Network_0_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT16
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x2,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* PEB02_TrqAbsMax_PEB_02 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        30,                                                /*BitPosition*/

        11,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_02_Can_Network_0_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT16
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x2,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* PEB02_stTrqEmMin_PEB_02 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        13,                                                /*BitPosition*/

        6,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_02_Can_Network_0_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x0,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* PEB02_stTrqEmMax_PEB_02 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        41,                                                /*BitPosition*/

        6,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_02_Can_Network_0_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x0,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* PEB02_IdcCurr_PEB_02 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        19,                                                /*BitPosition*/

        11,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_02_Can_Network_0_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT16
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x2,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* PEB02_UT30Curr_PEB_02 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        58,                                                /*BitPosition*/

        6,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_02_Can_Network_0_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x0,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* PEB02_bReadyHv_PEB_02 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        9,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_02_Can_Network_0_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = BOOLEAN
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x6,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* PEB02_bDernUndrUdc_PEB_02 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        7,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_02_Can_Network_0_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = BOOLEAN
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x6,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* PEB02_bDernUndrIdc_PEB_02 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        6,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_02_Can_Network_0_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = BOOLEAN
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x6,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* PEB02_bDernTrqMin_PEB_02 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        5,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_02_Can_Network_0_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = BOOLEAN
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x6,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* PEB02_bDernTrqMax_PEB_02 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        4,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_02_Can_Network_0_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = BOOLEAN
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x6,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* PEB02_bDernStrTemp_PEB_02 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        3,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_02_Can_Network_0_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = BOOLEAN
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x6,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* PEB02_bDernOvrUdc_PEB_02 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        2,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_02_Can_Network_0_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = BOOLEAN
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x6,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* PEB02_bDernOvrIdc_PEB_02 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        1,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_02_Can_Network_0_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = BOOLEAN
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x6,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* PEB02_bDernCAN_PEB_02 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        0,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_02_Can_Network_0_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = BOOLEAN
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x6,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* PEB05_FailCode8_PEB_05 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        56,                                                /*BitPosition*/

        8,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_05_Can_Network_0_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x0,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* PEB05_FailCode7_PEB_05 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        48,                                                /*BitPosition*/

        8,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_05_Can_Network_0_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x0,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* PEB05_FailCode6_PEB_05 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        40,                                                /*BitPosition*/

        8,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_05_Can_Network_0_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x0,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* PEB05_FailCode5_PEB_05 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        32,                                                /*BitPosition*/

        8,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_05_Can_Network_0_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x0,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* PEB05_FailCode4_PEB_05 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        24,                                                /*BitPosition*/

        8,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_05_Can_Network_0_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x0,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* PEB05_FailCode3_PEB_05 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        16,                                                /*BitPosition*/

        8,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_05_Can_Network_0_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x0,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* PEB05_FailCode2_PEB_05 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        8,                                                /*BitPosition*/

        8,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_05_Can_Network_0_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x0,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* PEB05_FailCode1_PEB_05 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        0,                                                /*BitPosition*/

        8,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_05_Can_Network_0_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x0,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* PEB07_MinPredTrq_PEB_07 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        30,                                                /*BitPosition*/

        10,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_07_Can_Network_0_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT16
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x2,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* PEB07_MinDynTrq_PEB_07 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        20,                                                /*BitPosition*/

        10,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_07_Can_Network_0_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT16
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x2,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* PEB07_MaxPredTrq_PEB_07 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        10,                                                /*BitPosition*/

        10,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_07_Can_Network_0_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT16
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x2,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* PEB07_MaxDynTrq_PEB_07 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        0,                                                /*BitPosition*/

        10,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_07_Can_Network_0_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT16
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x2,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* SysBoot_Tx0_SysBoot_Tx */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        0,                                                /*BitPosition*/

        8,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_SysBoot_Tx_Can_Network_1_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x0,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* SysBoot_Tx1_SysBoot_Tx */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        8,                                                /*BitPosition*/

        8,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_SysBoot_Tx_Can_Network_1_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x0,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* SysBoot_Tx2_SysBoot_Tx */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        16,                                                /*BitPosition*/

        8,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_SysBoot_Tx_Can_Network_1_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x0,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* SysBoot_Tx3_SysBoot_Tx */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        24,                                                /*BitPosition*/

        8,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_SysBoot_Tx_Can_Network_1_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x0,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* SysBoot_Tx4_SysBoot_Tx */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        32,                                                /*BitPosition*/

        8,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_SysBoot_Tx_Can_Network_1_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x0,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* SysBoot_Tx5_SysBoot_Tx */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        40,                                                /*BitPosition*/

        8,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_SysBoot_Tx_Can_Network_1_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x0,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* SysBoot_Tx6_SysBoot_Tx */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        48,                                                /*BitPosition*/

        8,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_SysBoot_Tx_Can_Network_1_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x0,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* SysBoot_Tx7_SysBoot_Tx */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        56,                                                /*BitPosition*/

        8,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_SysBoot_Tx_Can_Network_1_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x0,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* PEB06_HvMcuVer_PEB_06 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        48,                                                /*BitPosition*/

        16,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_06_Can_Network_0_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT16
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x2,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* PEB06_CpldVer_PEB_06 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        32,                                                /*BitPosition*/

        16,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_06_Can_Network_0_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT16
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x2,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* PEB06_DataVer_PEB_06 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        16,                                                /*BitPosition*/

        16,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_06_Can_Network_0_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT16
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x2,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    },
        
    {  /* PEB06_CodeVer_PEB_06 */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */
        0,                                                /*BitPosition*/

        16,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_SigTriggeredOnChange
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_06_Can_Network_0_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT16
            Endianess:1;  = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x2,                                               /*General*/
        /*
        {
            TransProp : 2;          = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled: 1;      = COM_FALSE
        }Com_TxSigPropType;    */
        0x29                                               /*DataInvTimeout*/
    }

};

/* ------------------------------------------------------------------------ */
/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"

/* END: Tx Signal Details  */
/* START: Rx Signal Details  */

/* ------------------------------------------------------------------------ */
/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"

CONST(Com_Prv_xRxSigCfg_tst ,COM_CONST) Com_Prv_xRxSigCfg_acst[COM_NUM_RX_SIGNALS] =
{    
        
    {  /* BMS01_stMainRelay_BMS_01 */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        
        &Rte_COMCbk_BMS01_stMainRelay_BMS_01,
        
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       (uint32)(0uL),    /* DataInvalid_Val */
#endif
           (uint32)(0uL),        /*Init_Val */
#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif /* #ifdef COM_RxSigUpdateBit */
       11,                         /*BitPosition*/
       0,                /* Signal Buffer Index */
       
      2, /*BitSize*/

#ifdef COM_RxFilters
        0xff,                           /*Filter_Index*/
#endif

       (Com_IpduIdType)ComConf_ComIPdu_Internal_BMS_01_Can_Network_0_CANNODE_0,                       /*Ipdu Reference*/
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType; */
        0x0,       /*General*/

        /*
        {
            DataInvalidType:2;   =  NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = COM_FALSE
        } Com_RxSigPropType; */
        0x28         /*DataInvTimeout*/
    }
    ,
        
    {  /* BMS01_ctRoll_BMS_01 */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       (uint32)(0uL),    /* DataInvalid_Val */
#endif
           (uint32)(0uL),        /*Init_Val */
#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif /* #ifdef COM_RxSigUpdateBit */
       48,                         /*BitPosition*/
       1,                /* Signal Buffer Index */
       
      4, /*BitSize*/

#ifdef COM_RxFilters
        0xff,                           /*Filter_Index*/
#endif

       (Com_IpduIdType)ComConf_ComIPdu_Internal_BMS_01_Can_Network_0_CANNODE_0,                       /*Ipdu Reference*/
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType; */
        0x0,       /*General*/

        /*
        {
            DataInvalidType:2;   =  NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = COM_FALSE
        } Com_RxSigPropType; */
        0x28         /*DataInvTimeout*/
    }
    ,
        
    {  /* BMS01_Checksum_BMS_01 */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       (uint32)(0uL),    /* DataInvalid_Val */
#endif
           (uint32)(0uL),        /*Init_Val */
#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif /* #ifdef COM_RxSigUpdateBit */
       56,                         /*BitPosition*/
       2,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        0xff,                           /*Filter_Index*/
#endif

       (Com_IpduIdType)ComConf_ComIPdu_Internal_BMS_01_Can_Network_0_CANNODE_0,                       /*Ipdu Reference*/
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType; */
        0x0,       /*General*/

        /*
        {
            DataInvalidType:2;   =  NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = COM_FALSE
        } Com_RxSigPropType; */
        0x28         /*DataInvTimeout*/
    }
    ,
        
    {  /* BMS01_BattVolt_BMS_01 */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        
        &Rte_COMCbk_BMS01_BattVolt_BMS_01,
        
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       (uint32)(0uL),    /* DataInvalid_Val */
#endif
           (uint32)(0uL),        /*Init_Val */
#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif /* #ifdef COM_RxSigUpdateBit */
       16,                         /*BitPosition*/
       0,                /* Signal Buffer Index */
       
      10, /*BitSize*/

#ifdef COM_RxFilters
        0xff,                           /*Filter_Index*/
#endif

       (Com_IpduIdType)ComConf_ComIPdu_Internal_BMS_01_Can_Network_0_CANNODE_0,                       /*Ipdu Reference*/
        /*
        {
            Type:5;        = UINT16
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType; */
        0x2,       /*General*/

        /*
        {
            DataInvalidType:2;   =  NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = COM_FALSE
        } Com_RxSigPropType; */
        0x28         /*DataInvTimeout*/
    }
    ,
        
    {  /* BMS01_BattCurr_BMS_01 */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        
        &Rte_COMCbk_BMS01_BattCurr_BMS_01,
        
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       (uint32)(0uL),    /* DataInvalid_Val */
#endif
           (uint32)(0uL),        /*Init_Val */
#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif /* #ifdef COM_RxSigUpdateBit */
       0,                         /*BitPosition*/
       1,                /* Signal Buffer Index */
       
      11, /*BitSize*/

#ifdef COM_RxFilters
        0xff,                           /*Filter_Index*/
#endif

       (Com_IpduIdType)ComConf_ComIPdu_Internal_BMS_01_Can_Network_0_CANNODE_0,                       /*Ipdu Reference*/
        /*
        {
            Type:5;        = UINT16
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType; */
        0x2,       /*General*/

        /*
        {
            DataInvalidType:2;   =  NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = COM_FALSE
        } Com_RxSigPropType; */
        0x28         /*DataInvTimeout*/
    }
    ,
        
    {  /* SysBoot_Rx0_SysBoot_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       (uint32)(0uL),    /* DataInvalid_Val */
#endif
           (uint32)(0uL),        /*Init_Val */
#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif /* #ifdef COM_RxSigUpdateBit */
       0,                         /*BitPosition*/
       3,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        0xff,                           /*Filter_Index*/
#endif

       (Com_IpduIdType)ComConf_ComIPdu_Internal_SysBoot_Rx_Can_Network_1_CANNODE_0,                       /*Ipdu Reference*/
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType; */
        0x0,       /*General*/

        /*
        {
            DataInvalidType:2;   =  NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = COM_FALSE
        } Com_RxSigPropType; */
        0x28         /*DataInvTimeout*/
    }
    ,
        
    {  /* SysBoot_Rx1_SysBoot_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       (uint32)(0uL),    /* DataInvalid_Val */
#endif
           (uint32)(0uL),        /*Init_Val */
#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif /* #ifdef COM_RxSigUpdateBit */
       8,                         /*BitPosition*/
       4,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        0xff,                           /*Filter_Index*/
#endif

       (Com_IpduIdType)ComConf_ComIPdu_Internal_SysBoot_Rx_Can_Network_1_CANNODE_0,                       /*Ipdu Reference*/
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType; */
        0x0,       /*General*/

        /*
        {
            DataInvalidType:2;   =  NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = COM_FALSE
        } Com_RxSigPropType; */
        0x28         /*DataInvTimeout*/
    }
    ,
        
    {  /* SysBoot_Rx2_SysBoot_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       (uint32)(0uL),    /* DataInvalid_Val */
#endif
           (uint32)(0uL),        /*Init_Val */
#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif /* #ifdef COM_RxSigUpdateBit */
       16,                         /*BitPosition*/
       5,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        0xff,                           /*Filter_Index*/
#endif

       (Com_IpduIdType)ComConf_ComIPdu_Internal_SysBoot_Rx_Can_Network_1_CANNODE_0,                       /*Ipdu Reference*/
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType; */
        0x0,       /*General*/

        /*
        {
            DataInvalidType:2;   =  NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = COM_FALSE
        } Com_RxSigPropType; */
        0x28         /*DataInvTimeout*/
    }
    ,
        
    {  /* SysBoot_Rx3_SysBoot_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       (uint32)(0uL),    /* DataInvalid_Val */
#endif
           (uint32)(0uL),        /*Init_Val */
#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif /* #ifdef COM_RxSigUpdateBit */
       24,                         /*BitPosition*/
       6,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        0xff,                           /*Filter_Index*/
#endif

       (Com_IpduIdType)ComConf_ComIPdu_Internal_SysBoot_Rx_Can_Network_1_CANNODE_0,                       /*Ipdu Reference*/
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType; */
        0x0,       /*General*/

        /*
        {
            DataInvalidType:2;   =  NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = COM_FALSE
        } Com_RxSigPropType; */
        0x28         /*DataInvTimeout*/
    }
    ,
        
    {  /* SysBoot_Rx4_SysBoot_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       (uint32)(0uL),    /* DataInvalid_Val */
#endif
           (uint32)(0uL),        /*Init_Val */
#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif /* #ifdef COM_RxSigUpdateBit */
       32,                         /*BitPosition*/
       7,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        0xff,                           /*Filter_Index*/
#endif

       (Com_IpduIdType)ComConf_ComIPdu_Internal_SysBoot_Rx_Can_Network_1_CANNODE_0,                       /*Ipdu Reference*/
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType; */
        0x0,       /*General*/

        /*
        {
            DataInvalidType:2;   =  NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = COM_FALSE
        } Com_RxSigPropType; */
        0x28         /*DataInvTimeout*/
    }
    ,
        
    {  /* SysBoot_Rx5_SysBoot_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       (uint32)(0uL),    /* DataInvalid_Val */
#endif
           (uint32)(0uL),        /*Init_Val */
#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif /* #ifdef COM_RxSigUpdateBit */
       40,                         /*BitPosition*/
       8,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        0xff,                           /*Filter_Index*/
#endif

       (Com_IpduIdType)ComConf_ComIPdu_Internal_SysBoot_Rx_Can_Network_1_CANNODE_0,                       /*Ipdu Reference*/
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType; */
        0x0,       /*General*/

        /*
        {
            DataInvalidType:2;   =  NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = COM_FALSE
        } Com_RxSigPropType; */
        0x28         /*DataInvTimeout*/
    }
    ,
        
    {  /* SysBoot_Rx6_SysBoot_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       (uint32)(0uL),    /* DataInvalid_Val */
#endif
           (uint32)(0uL),        /*Init_Val */
#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif /* #ifdef COM_RxSigUpdateBit */
       48,                         /*BitPosition*/
       9,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        0xff,                           /*Filter_Index*/
#endif

       (Com_IpduIdType)ComConf_ComIPdu_Internal_SysBoot_Rx_Can_Network_1_CANNODE_0,                       /*Ipdu Reference*/
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType; */
        0x0,       /*General*/

        /*
        {
            DataInvalidType:2;   =  NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = COM_FALSE
        } Com_RxSigPropType; */
        0x28         /*DataInvTimeout*/
    }
    ,
        
    {  /* SysBoot_Rx7_SysBoot_Rx */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       (uint32)(0uL),    /* DataInvalid_Val */
#endif
           (uint32)(0uL),        /*Init_Val */
#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif /* #ifdef COM_RxSigUpdateBit */
       56,                         /*BitPosition*/
       10,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        0xff,                           /*Filter_Index*/
#endif

       (Com_IpduIdType)ComConf_ComIPdu_Internal_SysBoot_Rx_Can_Network_1_CANNODE_0,                       /*Ipdu Reference*/
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType; */
        0x0,       /*General*/

        /*
        {
            DataInvalidType:2;   =  NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = COM_FALSE
        } Com_RxSigPropType; */
        0x28         /*DataInvTimeout*/
    }
    ,
        
    {  /* Data_Access_TOOL_01 */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       (uint32)(0uL),    /* DataInvalid_Val */
#endif
           (uint32)(0uL),        /*Init_Val */
#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif /* #ifdef COM_RxSigUpdateBit */
       0,                         /*BitPosition*/
       11,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        0xff,                           /*Filter_Index*/
#endif

       (Com_IpduIdType)ComConf_ComIPdu_Internal_TOOL_01_Can_Network_1_CANNODE_0,                       /*Ipdu Reference*/
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType; */
        0x0,       /*General*/

        /*
        {
            DataInvalidType:2;   =  NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = COM_FALSE
        } Com_RxSigPropType; */
        0x28         /*DataInvTimeout*/
    }
    ,
        
    {  /* VCU01_ctRoll_VCU_01 */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       (uint32)(0uL),    /* DataInvalid_Val */
#endif
           (uint32)(0uL),        /*Init_Val */
#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif /* #ifdef COM_RxSigUpdateBit */
       48,                         /*BitPosition*/
       12,                /* Signal Buffer Index */
       
      4, /*BitSize*/

#ifdef COM_RxFilters
        0xff,                           /*Filter_Index*/
#endif

       (Com_IpduIdType)ComConf_ComIPdu_Internal_VCU_01_Can_Network_0_CANNODE_0,                       /*Ipdu Reference*/
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType; */
        0x0,       /*General*/

        /*
        {
            DataInvalidType:2;   =  NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = COM_FALSE
        } Com_RxSigPropType; */
        0x28         /*DataInvTimeout*/
    }
    ,
        
    {  /* VCU01_Checksum_VCU_01 */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       (uint32)(0uL),    /* DataInvalid_Val */
#endif
           (uint32)(0uL),        /*Init_Val */
#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif /* #ifdef COM_RxSigUpdateBit */
       56,                         /*BitPosition*/
       13,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        0xff,                           /*Filter_Index*/
#endif

       (Com_IpduIdType)ComConf_ComIPdu_Internal_VCU_01_Can_Network_0_CANNODE_0,                       /*Ipdu Reference*/
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType; */
        0x0,       /*General*/

        /*
        {
            DataInvalidType:2;   =  NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = COM_FALSE
        } Com_RxSigPropType; */
        0x28         /*DataInvTimeout*/
    }
    ,
        
    {  /* VCU01_stHvbMaiRly_VCU_01 */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        
        &Rte_COMCbk_VCU01_stHvbMaiRly_VCU_01,
        
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       (uint32)(0uL),    /* DataInvalid_Val */
#endif
           (uint32)(0uL),        /*Init_Val */
#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif /* #ifdef COM_RxSigUpdateBit */
       42,                         /*BitPosition*/
       14,                /* Signal Buffer Index */
       
      3, /*BitSize*/

#ifdef COM_RxFilters
        0xff,                           /*Filter_Index*/
#endif

       (Com_IpduIdType)ComConf_ComIPdu_Internal_VCU_01_Can_Network_0_CANNODE_0,                       /*Ipdu Reference*/
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType; */
        0x0,       /*General*/

        /*
        {
            DataInvalidType:2;   =  NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = COM_FALSE
        } Com_RxSigPropType; */
        0x28         /*DataInvTimeout*/
    }
    ,
        
    {  /* VCU01_UdcMin_VCU_01 */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        
        &Rte_COMCbk_VCU01_UdcMin_VCU_01,
        
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       (uint32)(0uL),    /* DataInvalid_Val */
#endif
           (uint32)(0uL),        /*Init_Val */
#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif /* #ifdef COM_RxSigUpdateBit */
       32,                         /*BitPosition*/
       2,                /* Signal Buffer Index */
       
      10, /*BitSize*/

#ifdef COM_RxFilters
        0xff,                           /*Filter_Index*/
#endif

       (Com_IpduIdType)ComConf_ComIPdu_Internal_VCU_01_Can_Network_0_CANNODE_0,                       /*Ipdu Reference*/
        /*
        {
            Type:5;        = UINT16
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType; */
        0x2,       /*General*/

        /*
        {
            DataInvalidType:2;   =  NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = COM_FALSE
        } Com_RxSigPropType; */
        0x28         /*DataInvTimeout*/
    }
    ,
        
    {  /* VCU01_UdcMax_VCU_01 */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        
        &Rte_COMCbk_VCU01_UdcMax_VCU_01,
        
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       (uint32)(0uL),    /* DataInvalid_Val */
#endif
           (uint32)(0uL),        /*Init_Val */
#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif /* #ifdef COM_RxSigUpdateBit */
       22,                         /*BitPosition*/
       3,                /* Signal Buffer Index */
       
      10, /*BitSize*/

#ifdef COM_RxFilters
        0xff,                           /*Filter_Index*/
#endif

       (Com_IpduIdType)ComConf_ComIPdu_Internal_VCU_01_Can_Network_0_CANNODE_0,                       /*Ipdu Reference*/
        /*
        {
            Type:5;        = UINT16
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType; */
        0x2,       /*General*/

        /*
        {
            DataInvalidType:2;   =  NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = COM_FALSE
        } Com_RxSigPropType; */
        0x28         /*DataInvTimeout*/
    }
    ,
        
    {  /* VCU01_IdcMin_VCU_01 */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        
        &Rte_COMCbk_VCU01_IdcMin_VCU_01,
        
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       (uint32)(0uL),    /* DataInvalid_Val */
#endif
           (uint32)(0uL),        /*Init_Val */
#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif /* #ifdef COM_RxSigUpdateBit */
       11,                         /*BitPosition*/
       4,                /* Signal Buffer Index */
       
      11, /*BitSize*/

#ifdef COM_RxFilters
        0xff,                           /*Filter_Index*/
#endif

       (Com_IpduIdType)ComConf_ComIPdu_Internal_VCU_01_Can_Network_0_CANNODE_0,                       /*Ipdu Reference*/
        /*
        {
            Type:5;        = UINT16
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType; */
        0x2,       /*General*/

        /*
        {
            DataInvalidType:2;   =  NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = COM_FALSE
        } Com_RxSigPropType; */
        0x28         /*DataInvTimeout*/
    }
    ,
        
    {  /* VCU01_IdcMax_VCU_01 */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        
        &Rte_COMCbk_VCU01_IdcMax_VCU_01,
        
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       (uint32)(0uL),    /* DataInvalid_Val */
#endif
           (uint32)(0uL),        /*Init_Val */
#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif /* #ifdef COM_RxSigUpdateBit */
       0,                         /*BitPosition*/
       5,                /* Signal Buffer Index */
       
      11, /*BitSize*/

#ifdef COM_RxFilters
        0xff,                           /*Filter_Index*/
#endif

       (Com_IpduIdType)ComConf_ComIPdu_Internal_VCU_01_Can_Network_0_CANNODE_0,                       /*Ipdu Reference*/
        /*
        {
            Type:5;        = UINT16
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType; */
        0x2,       /*General*/

        /*
        {
            DataInvalidType:2;   =  NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = COM_FALSE
        } Com_RxSigPropType; */
        0x28         /*DataInvTimeout*/
    }
    ,
        
    {  /* VCU02_TrqMinNCtl_VCU_02 */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        
        &Rte_COMCbk_VCU02_TrqMinNCtl_VCU_02,
        
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       (uint32)(0uL),    /* DataInvalid_Val */
#endif
           (uint32)(0uL),        /*Init_Val */
#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif /* #ifdef COM_RxSigUpdateBit */
       34,                         /*BitPosition*/
       6,                /* Signal Buffer Index */
       
      11, /*BitSize*/

#ifdef COM_RxFilters
        0xff,                           /*Filter_Index*/
#endif

       (Com_IpduIdType)ComConf_ComIPdu_Internal_VCU_02_Can_Network_0_CANNODE_0,                       /*Ipdu Reference*/
        /*
        {
            Type:5;        = UINT16
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType; */
        0x2,       /*General*/

        /*
        {
            DataInvalidType:2;   =  NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = COM_FALSE
        } Com_RxSigPropType; */
        0x28         /*DataInvTimeout*/
    }
    ,
        
    {  /* VCU02_TrqMaxNCtl_VCU_02 */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        
        &Rte_COMCbk_VCU02_TrqMaxNCtl_VCU_02,
        
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       (uint32)(0uL),    /* DataInvalid_Val */
#endif
           (uint32)(0uL),        /*Init_Val */
#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif /* #ifdef COM_RxSigUpdateBit */
       45,                         /*BitPosition*/
       7,                /* Signal Buffer Index */
       
      11, /*BitSize*/

#ifdef COM_RxFilters
        0xff,                           /*Filter_Index*/
#endif

       (Com_IpduIdType)ComConf_ComIPdu_Internal_VCU_02_Can_Network_0_CANNODE_0,                       /*Ipdu Reference*/
        /*
        {
            Type:5;        = UINT16
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType; */
        0x2,       /*General*/

        /*
        {
            DataInvalidType:2;   =  NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = COM_FALSE
        } Com_RxSigPropType; */
        0x28         /*DataInvTimeout*/
    }
    ,
        
    {  /* VCU02_NDiffMax_VCU_02 */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        
        &Rte_COMCbk_VCU02_NDiffMax_VCU_02,
        
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       (uint32)(0uL),    /* DataInvalid_Val */
#endif
           (uint32)(0uL),        /*Init_Val */
#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif /* #ifdef COM_RxSigUpdateBit */
       18,                         /*BitPosition*/
       8,                /* Signal Buffer Index */
       
      16, /*BitSize*/

#ifdef COM_RxFilters
        0xff,                           /*Filter_Index*/
#endif

       (Com_IpduIdType)ComConf_ComIPdu_Internal_VCU_02_Can_Network_0_CANNODE_0,                       /*Ipdu Reference*/
        /*
        {
            Type:5;        = UINT16
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType; */
        0x2,       /*General*/

        /*
        {
            DataInvalidType:2;   =  NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = COM_FALSE
        } Com_RxSigPropType; */
        0x28         /*DataInvTimeout*/
    }
    ,
        
    {  /* VCU02_KpLowNCtl_VCU_02 */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        
        &Rte_COMCbk_VCU02_KpLowNCtl_VCU_02,
        
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       (uint32)(0uL),    /* DataInvalid_Val */
#endif
           (uint32)(0uL),        /*Init_Val */
#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif /* #ifdef COM_RxSigUpdateBit */
       9,                         /*BitPosition*/
       9,                /* Signal Buffer Index */
       
      9, /*BitSize*/

#ifdef COM_RxFilters
        0xff,                           /*Filter_Index*/
#endif

       (Com_IpduIdType)ComConf_ComIPdu_Internal_VCU_02_Can_Network_0_CANNODE_0,                       /*Ipdu Reference*/
        /*
        {
            Type:5;        = UINT16
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType; */
        0x2,       /*General*/

        /*
        {
            DataInvalidType:2;   =  NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = COM_FALSE
        } Com_RxSigPropType; */
        0x28         /*DataInvTimeout*/
    }
    ,
        
    {  /* VCU02_KpHighNCtl_VCU_02 */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        
        &Rte_COMCbk_VCU02_KpHighNCtl_VCU_02,
        
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       (uint32)(0uL),    /* DataInvalid_Val */
#endif
           (uint32)(0uL),        /*Init_Val */
#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif /* #ifdef COM_RxSigUpdateBit */
       0,                         /*BitPosition*/
       10,                /* Signal Buffer Index */
       
      9, /*BitSize*/

#ifdef COM_RxFilters
        0xff,                           /*Filter_Index*/
#endif

       (Com_IpduIdType)ComConf_ComIPdu_Internal_VCU_02_Can_Network_0_CANNODE_0,                       /*Ipdu Reference*/
        /*
        {
            Type:5;        = UINT16
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType; */
        0x2,       /*General*/

        /*
        {
            DataInvalidType:2;   =  NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = COM_FALSE
        } Com_RxSigPropType; */
        0x28         /*DataInvTimeout*/
    }
    ,
        
    {  /* VCU03_ctRoll_VCU_03 */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       (uint32)(0uL),    /* DataInvalid_Val */
#endif
           (uint32)(0uL),        /*Init_Val */
#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif /* #ifdef COM_RxSigUpdateBit */
       48,                         /*BitPosition*/
       15,                /* Signal Buffer Index */
       
      4, /*BitSize*/

#ifdef COM_RxFilters
        0xff,                           /*Filter_Index*/
#endif

       (Com_IpduIdType)ComConf_ComIPdu_Internal_VCU_03_Can_Network_0_CANNODE_0,                       /*Ipdu Reference*/
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType; */
        0x0,       /*General*/

        /*
        {
            DataInvalidType:2;   =  NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = COM_FALSE
        } Com_RxSigPropType; */
        0x28         /*DataInvTimeout*/
    }
    ,
        
    {  /* VCU03_Checksum_VCU_03 */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       (uint32)(0uL),    /* DataInvalid_Val */
#endif
           (uint32)(0uL),        /*Init_Val */
#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif /* #ifdef COM_RxSigUpdateBit */
       56,                         /*BitPosition*/
       16,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        0xff,                           /*Filter_Index*/
#endif

       (Com_IpduIdType)ComConf_ComIPdu_Internal_VCU_03_Can_Network_0_CANNODE_0,                       /*Ipdu Reference*/
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType; */
        0x0,       /*General*/

        /*
        {
            DataInvalidType:2;   =  NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = COM_FALSE
        } Com_RxSigPropType; */
        0x28         /*DataInvTimeout*/
    }
    ,
        
    {  /* VCU03_cTrqSlopeMax_VCU_03 */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        
        &Rte_COMCbk_VCU03_cTrqSlopeMax_VCU_03,
        
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       (uint32)(0uL),    /* DataInvalid_Val */
#endif
           (uint32)(0uL),        /*Init_Val */
#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif /* #ifdef COM_RxSigUpdateBit */
       24,                         /*BitPosition*/
       11,                /* Signal Buffer Index */
       
      15, /*BitSize*/

#ifdef COM_RxFilters
        0xff,                           /*Filter_Index*/
#endif

       (Com_IpduIdType)ComConf_ComIPdu_Internal_VCU_03_Can_Network_0_CANNODE_0,                       /*Ipdu Reference*/
        /*
        {
            Type:5;        = UINT16
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType; */
        0x2,       /*General*/

        /*
        {
            DataInvalidType:2;   =  NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = COM_FALSE
        } Com_RxSigPropType; */
        0x28         /*DataInvTimeout*/
    }
    ,
        
    {  /* VCU03_TrqMin_VCU_03 */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        
        &Rte_COMCbk_VCU03_TrqMin_VCU_03,
        
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       (uint32)(0uL),    /* DataInvalid_Val */
#endif
           (uint32)(0uL),        /*Init_Val */
#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif /* #ifdef COM_RxSigUpdateBit */
       11,                         /*BitPosition*/
       12,                /* Signal Buffer Index */
       
      11, /*BitSize*/

#ifdef COM_RxFilters
        0xff,                           /*Filter_Index*/
#endif

       (Com_IpduIdType)ComConf_ComIPdu_Internal_VCU_03_Can_Network_0_CANNODE_0,                       /*Ipdu Reference*/
        /*
        {
            Type:5;        = UINT16
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType; */
        0x2,       /*General*/

        /*
        {
            DataInvalidType:2;   =  NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = COM_FALSE
        } Com_RxSigPropType; */
        0x28         /*DataInvTimeout*/
    }
    ,
        
    {  /* VCU03_TrqMax_VCU_03 */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        
        &Rte_COMCbk_VCU03_TrqMax_VCU_03,
        
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       (uint32)(0uL),    /* DataInvalid_Val */
#endif
           (uint32)(0uL),        /*Init_Val */
#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif /* #ifdef COM_RxSigUpdateBit */
       0,                         /*BitPosition*/
       13,                /* Signal Buffer Index */
       
      11, /*BitSize*/

#ifdef COM_RxFilters
        0xff,                           /*Filter_Index*/
#endif

       (Com_IpduIdType)ComConf_ComIPdu_Internal_VCU_03_Can_Network_0_CANNODE_0,                       /*Ipdu Reference*/
        /*
        {
            Type:5;        = UINT16
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType; */
        0x2,       /*General*/

        /*
        {
            DataInvalidType:2;   =  NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = COM_FALSE
        } Com_RxSigPropType; */
        0x28         /*DataInvTimeout*/
    }
    ,
        
    {  /* VCU04_MotDir_VCU_04 */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        
        &Rte_COMCbk_VCU04_MotDir_VCU_04,
        
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       (uint32)(0uL),    /* DataInvalid_Val */
#endif
           (uint32)(0uL),        /*Init_Val */
#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif /* #ifdef COM_RxSigUpdateBit */
       45,                         /*BitPosition*/
       17,                /* Signal Buffer Index */
       
      2, /*BitSize*/

#ifdef COM_RxFilters
        0xff,                           /*Filter_Index*/
#endif

       (Com_IpduIdType)ComConf_ComIPdu_Internal_VCU_04_Can_Network_0_CANNODE_0,                       /*Ipdu Reference*/
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType; */
        0x0,       /*General*/

        /*
        {
            DataInvalidType:2;   =  NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = COM_FALSE
        } Com_RxSigPropType; */
        0x28         /*DataInvTimeout*/
    }
    ,
        
    {  /* VCU04_bKL15_VCU_04 */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        
        &Rte_COMCbk_VCU04_bKL15_VCU_04,
        
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       (uint32)(0uL),    /* DataInvalid_Val */
#endif
           (uint32)(0uL),        /*Init_Val */
#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif /* #ifdef COM_RxSigUpdateBit */
       47,                         /*BitPosition*/
       18,                /* Signal Buffer Index */
       
      1, /*BitSize*/

#ifdef COM_RxFilters
        0xff,                           /*Filter_Index*/
#endif

       (Com_IpduIdType)ComConf_ComIPdu_Internal_VCU_04_Can_Network_0_CANNODE_0,                       /*Ipdu Reference*/
        /*
        {
            Type:5;        = BOOLEAN
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType; */
        0x6,       /*General*/

        /*
        {
            DataInvalidType:2;   =  NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = COM_FALSE
        } Com_RxSigPropType; */
        0x28         /*DataInvTimeout*/
    }
    ,
        
    {  /* VCU04_ctRoll_VCU_04 */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       (uint32)(0uL),    /* DataInvalid_Val */
#endif
           (uint32)(0uL),        /*Init_Val */
#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif /* #ifdef COM_RxSigUpdateBit */
       48,                         /*BitPosition*/
       19,                /* Signal Buffer Index */
       
      4, /*BitSize*/

#ifdef COM_RxFilters
        0xff,                           /*Filter_Index*/
#endif

       (Com_IpduIdType)ComConf_ComIPdu_Internal_VCU_04_Can_Network_0_CANNODE_0,                       /*Ipdu Reference*/
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType; */
        0x0,       /*General*/

        /*
        {
            DataInvalidType:2;   =  NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = COM_FALSE
        } Com_RxSigPropType; */
        0x28         /*DataInvTimeout*/
    }
    ,
        
    {  /* VCU04_Checksum_VCU_04 */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       (uint32)(0uL),    /* DataInvalid_Val */
#endif
           (uint32)(0uL),        /*Init_Val */
#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif /* #ifdef COM_RxSigUpdateBit */
       56,                         /*BitPosition*/
       20,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        0xff,                           /*Filter_Index*/
#endif

       (Com_IpduIdType)ComConf_ComIPdu_Internal_VCU_04_Can_Network_0_CANNODE_0,                       /*Ipdu Reference*/
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType; */
        0x0,       /*General*/

        /*
        {
            DataInvalidType:2;   =  NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = COM_FALSE
        } Com_RxSigPropType; */
        0x28         /*DataInvTimeout*/
    }
    ,
        
    {  /* VCU04_TrqSetP_VCU_04 */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        
        &Rte_COMCbk_VCU04_TrqSetP_VCU_04,
        
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       (uint32)(0uL),    /* DataInvalid_Val */
#endif
           (uint32)(0uL),        /*Init_Val */
#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif /* #ifdef COM_RxSigUpdateBit */
       20,                         /*BitPosition*/
       14,                /* Signal Buffer Index */
       
      16, /*BitSize*/

#ifdef COM_RxFilters
        0xff,                           /*Filter_Index*/
#endif

       (Com_IpduIdType)ComConf_ComIPdu_Internal_VCU_04_Can_Network_0_CANNODE_0,                       /*Ipdu Reference*/
        /*
        {
            Type:5;        = UINT16
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType; */
        0x2,       /*General*/

        /*
        {
            DataInvalidType:2;   =  NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = COM_FALSE
        } Com_RxSigPropType; */
        0x28         /*DataInvTimeout*/
    }
    ,
        
    {  /* VCU04_stModeReq_VCU_04 */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        
        &Rte_COMCbk_VCU04_stModeReq_VCU_04,
        
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       (uint32)(0uL),    /* DataInvalid_Val */
#endif
           (uint32)(0uL),        /*Init_Val */
#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif /* #ifdef COM_RxSigUpdateBit */
       16,                         /*BitPosition*/
       21,                /* Signal Buffer Index */
       
      4, /*BitSize*/

#ifdef COM_RxFilters
        0xff,                           /*Filter_Index*/
#endif

       (Com_IpduIdType)ComConf_ComIPdu_Internal_VCU_04_Can_Network_0_CANNODE_0,                       /*Ipdu Reference*/
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType; */
        0x0,       /*General*/

        /*
        {
            DataInvalidType:2;   =  NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = COM_FALSE
        } Com_RxSigPropType; */
        0x28         /*DataInvTimeout*/
    }
    ,
        
    {  /* VCU04_NSetP_VCU_04 */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        
        &Rte_COMCbk_VCU04_NSetP_VCU_04,
        
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       (uint32)(0uL),    /* DataInvalid_Val */
#endif
           (uint32)(0uL),        /*Init_Val */
#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif /* #ifdef COM_RxSigUpdateBit */
       0,                         /*BitPosition*/
       15,                /* Signal Buffer Index */
       
      16, /*BitSize*/

#ifdef COM_RxFilters
        0xff,                           /*Filter_Index*/
#endif

       (Com_IpduIdType)ComConf_ComIPdu_Internal_VCU_04_Can_Network_0_CANNODE_0,                       /*Ipdu Reference*/
        /*
        {
            Type:5;        = UINT16
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType; */
        0x2,       /*General*/

        /*
        {
            DataInvalidType:2;   =  NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = COM_FALSE
        } Com_RxSigPropType; */
        0x28         /*DataInvTimeout*/
    }
    ,
        
    {  /* VCU05_TrqDmpMax_VCU_05 */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        
        &Rte_COMCbk_VCU05_TrqDmpMax_VCU_05,
        
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       (uint32)(0uL),    /* DataInvalid_Val */
#endif
           (uint32)(0uL),        /*Init_Val */
#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif /* #ifdef COM_RxSigUpdateBit */
       10,                         /*BitPosition*/
       16,                /* Signal Buffer Index */
       
      10, /*BitSize*/

#ifdef COM_RxFilters
        0xff,                           /*Filter_Index*/
#endif

       (Com_IpduIdType)ComConf_ComIPdu_Internal_VCU_05_Can_Network_0_CANNODE_0,                       /*Ipdu Reference*/
        /*
        {
            Type:5;        = UINT16
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType; */
        0x2,       /*General*/

        /*
        {
            DataInvalidType:2;   =  NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = COM_FALSE
        } Com_RxSigPropType; */
        0x28         /*DataInvTimeout*/
    }
    ,
        
    {  /* VCU05_TrqDmpLim_VCU_05 */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        
        &Rte_COMCbk_VCU05_TrqDmpLim_VCU_05,
        
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       (uint32)(0uL),    /* DataInvalid_Val */
#endif
           (uint32)(0uL),        /*Init_Val */
#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif /* #ifdef COM_RxSigUpdateBit */
       40,                         /*BitPosition*/
       17,                /* Signal Buffer Index */
       
      10, /*BitSize*/

#ifdef COM_RxFilters
        0xff,                           /*Filter_Index*/
#endif

       (Com_IpduIdType)ComConf_ComIPdu_Internal_VCU_05_Can_Network_0_CANNODE_0,                       /*Ipdu Reference*/
        /*
        {
            Type:5;        = UINT16
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType; */
        0x2,       /*General*/

        /*
        {
            DataInvalidType:2;   =  NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = COM_FALSE
        } Com_RxSigPropType; */
        0x28         /*DataInvTimeout*/
    }
    ,
        
    {  /* VCU05_stDmpCtlReq_VCU_05 */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        
        &Rte_COMCbk_VCU05_stDmpCtlReq_VCU_05,
        
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       (uint32)(0uL),    /* DataInvalid_Val */
#endif
           (uint32)(0uL),        /*Init_Val */
#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif /* #ifdef COM_RxSigUpdateBit */
       8,                         /*BitPosition*/
       22,                /* Signal Buffer Index */
       
      2, /*BitSize*/

#ifdef COM_RxFilters
        0xff,                           /*Filter_Index*/
#endif

       (Com_IpduIdType)ComConf_ComIPdu_Internal_VCU_05_Can_Network_0_CANNODE_0,                       /*Ipdu Reference*/
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType; */
        0x0,       /*General*/

        /*
        {
            DataInvalidType:2;   =  NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = COM_FALSE
        } Com_RxSigPropType; */
        0x28         /*DataInvTimeout*/
    }
    ,
        
    {  /* VCU05_kDmp_VCU_05 */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        
        &Rte_COMCbk_VCU05_kDmp_VCU_05,
        
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       (uint32)(0uL),    /* DataInvalid_Val */
#endif
           (uint32)(0uL),        /*Init_Val */
#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif /* #ifdef COM_RxSigUpdateBit */
       0,                         /*BitPosition*/
       23,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        0xff,                           /*Filter_Index*/
#endif

       (Com_IpduIdType)ComConf_ComIPdu_Internal_VCU_05_Can_Network_0_CANNODE_0,                       /*Ipdu Reference*/
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType; */
        0x0,       /*General*/

        /*
        {
            DataInvalidType:2;   =  NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = COM_FALSE
        } Com_RxSigPropType; */
        0x28         /*DataInvTimeout*/
    }
    ,
        
    {  /* VCU05_OfsAl_VCU_05 */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        
        &Rte_COMCbk_VCU05_OfsAl_VCU_05,
        
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       (uint32)(0uL),    /* DataInvalid_Val */
#endif
           (uint32)(0uL),        /*Init_Val */
#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif /* #ifdef COM_RxSigUpdateBit */
       24,                         /*BitPosition*/
       18,                /* Signal Buffer Index */
       
      12, /*BitSize*/

#ifdef COM_RxFilters
        0xff,                           /*Filter_Index*/
#endif

       (Com_IpduIdType)ComConf_ComIPdu_Internal_VCU_05_Can_Network_0_CANNODE_0,                       /*Ipdu Reference*/
        /*
        {
            Type:5;        = UINT16
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType; */
        0x2,       /*General*/

        /*
        {
            DataInvalidType:2;   =  NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = COM_FALSE
        } Com_RxSigPropType; */
        0x28         /*DataInvTimeout*/
    }
    ,
        
    {  /* VCU05_bSetOfsAl_VCU_05 */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        
        &Rte_COMCbk_VCU05_bSetOfsAl_VCU_05,
        
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       (uint32)(0uL),    /* DataInvalid_Val */
#endif
           (uint32)(0uL),        /*Init_Val */
#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif /* #ifdef COM_RxSigUpdateBit */
       20,                         /*BitPosition*/
       24,                /* Signal Buffer Index */
       
      1, /*BitSize*/

#ifdef COM_RxFilters
        0xff,                           /*Filter_Index*/
#endif

       (Com_IpduIdType)ComConf_ComIPdu_Internal_VCU_05_Can_Network_0_CANNODE_0,                       /*Ipdu Reference*/
        /*
        {
            Type:5;        = BOOLEAN
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType; */
        0x6,       /*General*/

        /*
        {
            DataInvalidType:2;   =  NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = COM_FALSE
        } Com_RxSigPropType; */
        0x28         /*DataInvTimeout*/
    }
    ,
        
    {  /* VCU06_VehGrad_VCU_06 */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        
        &Rte_COMCbk_VCU06_VehGrad_VCU_06,
        
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       (uint32)(0uL),    /* DataInvalid_Val */
#endif
           (uint32)(0uL),        /*Init_Val */
#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif /* #ifdef COM_RxSigUpdateBit */
       16,                         /*BitPosition*/
       25,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        0xff,                           /*Filter_Index*/
#endif

       (Com_IpduIdType)ComConf_ComIPdu_Internal_VCU_06_Can_Network_0_CANNODE_0,                       /*Ipdu Reference*/
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType; */
        0x0,       /*General*/

        /*
        {
            DataInvalidType:2;   =  NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = COM_FALSE
        } Com_RxSigPropType; */
        0x28         /*DataInvTimeout*/
    }
    ,
        
    {  /* VCU06_Park_VCU_06 */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        
        &Rte_COMCbk_VCU06_Park_VCU_06,
        
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       (uint32)(0uL),    /* DataInvalid_Val */
#endif
           (uint32)(0uL),        /*Init_Val */
#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif /* #ifdef COM_RxSigUpdateBit */
       6,                         /*BitPosition*/
       26,                /* Signal Buffer Index */
       
      1, /*BitSize*/

#ifdef COM_RxFilters
        0xff,                           /*Filter_Index*/
#endif

       (Com_IpduIdType)ComConf_ComIPdu_Internal_VCU_06_Can_Network_0_CANNODE_0,                       /*Ipdu Reference*/
        /*
        {
            Type:5;        = BOOLEAN
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType; */
        0x6,       /*General*/

        /*
        {
            DataInvalidType:2;   =  NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = COM_FALSE
        } Com_RxSigPropType; */
        0x28         /*DataInvTimeout*/
    }
    ,
        
    {  /* VCU06_stDoor_VCU_06 */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        
        &Rte_COMCbk_VCU06_stDoor_VCU_06,
        
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       (uint32)(0uL),    /* DataInvalid_Val */
#endif
           (uint32)(0uL),        /*Init_Val */
#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif /* #ifdef COM_RxSigUpdateBit */
       8,                         /*BitPosition*/
       27,                /* Signal Buffer Index */
       
      4, /*BitSize*/

#ifdef COM_RxFilters
        0xff,                           /*Filter_Index*/
#endif

       (Com_IpduIdType)ComConf_ComIPdu_Internal_VCU_06_Can_Network_0_CANNODE_0,                       /*Ipdu Reference*/
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType; */
        0x0,       /*General*/

        /*
        {
            DataInvalidType:2;   =  NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = COM_FALSE
        } Com_RxSigPropType; */
        0x28         /*DataInvTimeout*/
    }
    ,
        
    {  /* VCU06_stBreak_VCU_06 */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        
        &Rte_COMCbk_VCU06_stBreak_VCU_06,
        
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       (uint32)(0uL),    /* DataInvalid_Val */
#endif
           (uint32)(0uL),        /*Init_Val */
#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif /* #ifdef COM_RxSigUpdateBit */
       2,                         /*BitPosition*/
       28,                /* Signal Buffer Index */
       
      4, /*BitSize*/

#ifdef COM_RxFilters
        0xff,                           /*Filter_Index*/
#endif

       (Com_IpduIdType)ComConf_ComIPdu_Internal_VCU_06_Can_Network_0_CANNODE_0,                       /*Ipdu Reference*/
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType; */
        0x0,       /*General*/

        /*
        {
            DataInvalidType:2;   =  NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = COM_FALSE
        } Com_RxSigPropType; */
        0x28         /*DataInvTimeout*/
    }
    ,
        
    {  /* VCU06_stBelt_VCU_06 */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        
        &Rte_COMCbk_VCU06_stBelt_VCU_06,
        
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       (uint32)(0uL),    /* DataInvalid_Val */
#endif
           (uint32)(0uL),        /*Init_Val */
#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif /* #ifdef COM_RxSigUpdateBit */
       0,                         /*BitPosition*/
       29,                /* Signal Buffer Index */
       
      2, /*BitSize*/

#ifdef COM_RxFilters
        0xff,                           /*Filter_Index*/
#endif

       (Com_IpduIdType)ComConf_ComIPdu_Internal_VCU_06_Can_Network_0_CANNODE_0,                       /*Ipdu Reference*/
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType; */
        0x0,       /*General*/

        /*
        {
            DataInvalidType:2;   =  NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = COM_FALSE
        } Com_RxSigPropType; */
        0x28         /*DataInvTimeout*/
    }
    ,
        
    {  /* MaskData1_VCU_07_Mask */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       (uint32)(0uL),    /* DataInvalid_Val */
#endif
           (uint32)(0uL),        /*Init_Val */
#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif /* #ifdef COM_RxSigUpdateBit */
       0,                         /*BitPosition*/
       30,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        0xff,                           /*Filter_Index*/
#endif

       (Com_IpduIdType)ComConf_ComIPdu_Internal_VCU_07_Mask_Can_Network_0_CANNODE_0,                       /*Ipdu Reference*/
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = LITTLE_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType; */
        0x0,       /*General*/

        /*
        {
            DataInvalidType:2;   =  NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = COM_FALSE
        } Com_RxSigPropType; */
        0x28         /*DataInvTimeout*/
    }
    

};

/* ------------------------------------------------------------------------ */
/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"

/* END: Rx Signal Details  */












/* START: TMS Details  */


/* ------------------------------------------------------------------------ */
/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"

/* DIAG_01_Can_Network_1_CANNODE_0 has a TMS switch */
static CONST(Com_TransModeInfo ,COM_CONST) Com_DIAG_01_Can_Network_1_CANNODE_0_TransModeInfo[] = {
    {

    
    
    1, /* TimePeriodFact */
    
    1, /* TimeOffsetFact */
    
    
    0, /* RepetitionPeriodFact */
    
    0,  /* NumRepetitions */

#ifdef COM_MIXEDPHASESHIFT
    
    COM_TXMODE_PERIODIC, /* Mode */
    COM_FALSE    /* MixedPhaseShift status */
#else

    
    
    COM_TXMODE_PERIODIC /* Mode */

#endif /* #ifdef COM_MIXEDPHASESHIFT */

    }

,
    {

    
    
    1, /* TimePeriodFact */
    
    1, /* TimeOffsetFact */
    
    
    0, /* RepetitionPeriodFact */
    
    0,  /* NumRepetitions */

#ifdef COM_MIXEDPHASESHIFT
    COM_TXMODE_PERIODIC, /* Mode */
    COM_FALSE    /* MixedPhaseShift status */
#else


    COM_TXMODE_PERIODIC /* Mode */

#endif /* #ifdef COM_MIXEDPHASESHIFT */

    }};

/* ------------------------------------------------------------------------ */
/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"



/* ------------------------------------------------------------------------ */
/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"

/* PEB_01_Can_Network_0_CANNODE_0 has a TMS switch */
static CONST(Com_TransModeInfo ,COM_CONST) Com_PEB_01_Can_Network_0_CANNODE_0_TransModeInfo[] = {
    {

    
    
    1, /* TimePeriodFact */
    
    1, /* TimeOffsetFact */
    
    
    0, /* RepetitionPeriodFact */
    
    0,  /* NumRepetitions */

#ifdef COM_MIXEDPHASESHIFT
    
    COM_TXMODE_PERIODIC, /* Mode */
    COM_FALSE    /* MixedPhaseShift status */
#else

    
    
    COM_TXMODE_PERIODIC /* Mode */

#endif /* #ifdef COM_MIXEDPHASESHIFT */

    }

,
    {

    
    
    1, /* TimePeriodFact */
    
    1, /* TimeOffsetFact */
    
    
    0, /* RepetitionPeriodFact */
    
    0,  /* NumRepetitions */

#ifdef COM_MIXEDPHASESHIFT
    COM_TXMODE_PERIODIC, /* Mode */
    COM_FALSE    /* MixedPhaseShift status */
#else


    COM_TXMODE_PERIODIC /* Mode */

#endif /* #ifdef COM_MIXEDPHASESHIFT */

    }};

/* ------------------------------------------------------------------------ */
/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"



/* ------------------------------------------------------------------------ */
/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"

/* PEB_03_Can_Network_0_CANNODE_0 has a TMS switch */
static CONST(Com_TransModeInfo ,COM_CONST) Com_PEB_03_Can_Network_0_CANNODE_0_TransModeInfo[] = {
    {

    
    
    1, /* TimePeriodFact */
    
    1, /* TimeOffsetFact */
    
    
    0, /* RepetitionPeriodFact */
    
    0,  /* NumRepetitions */

#ifdef COM_MIXEDPHASESHIFT
    
    COM_TXMODE_PERIODIC, /* Mode */
    COM_FALSE    /* MixedPhaseShift status */
#else

    
    
    COM_TXMODE_PERIODIC /* Mode */

#endif /* #ifdef COM_MIXEDPHASESHIFT */

    }

,
    {

    
    
    1, /* TimePeriodFact */
    
    1, /* TimeOffsetFact */
    
    
    0, /* RepetitionPeriodFact */
    
    0,  /* NumRepetitions */

#ifdef COM_MIXEDPHASESHIFT
    COM_TXMODE_PERIODIC, /* Mode */
    COM_FALSE    /* MixedPhaseShift status */
#else


    COM_TXMODE_PERIODIC /* Mode */

#endif /* #ifdef COM_MIXEDPHASESHIFT */

    }};

/* ------------------------------------------------------------------------ */
/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"



/* ------------------------------------------------------------------------ */
/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"

/* PEB_04_Can_Network_0_CANNODE_0 has a TMS switch */
static CONST(Com_TransModeInfo ,COM_CONST) Com_PEB_04_Can_Network_0_CANNODE_0_TransModeInfo[] = {
    {

    
    
    1, /* TimePeriodFact */
    
    1, /* TimeOffsetFact */
    
    
    0, /* RepetitionPeriodFact */
    
    0,  /* NumRepetitions */

#ifdef COM_MIXEDPHASESHIFT
    
    COM_TXMODE_PERIODIC, /* Mode */
    COM_FALSE    /* MixedPhaseShift status */
#else

    
    
    COM_TXMODE_PERIODIC /* Mode */

#endif /* #ifdef COM_MIXEDPHASESHIFT */

    }

,
    {

    
    
    1, /* TimePeriodFact */
    
    1, /* TimeOffsetFact */
    
    
    0, /* RepetitionPeriodFact */
    
    0,  /* NumRepetitions */

#ifdef COM_MIXEDPHASESHIFT
    COM_TXMODE_PERIODIC, /* Mode */
    COM_FALSE    /* MixedPhaseShift status */
#else


    COM_TXMODE_PERIODIC /* Mode */

#endif /* #ifdef COM_MIXEDPHASESHIFT */

    }};

/* ------------------------------------------------------------------------ */
/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"



/* ------------------------------------------------------------------------ */
/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"

/* PEB_08_Can_Network_0_CANNODE_0 has a TMS switch */
static CONST(Com_TransModeInfo ,COM_CONST) Com_PEB_08_Can_Network_0_CANNODE_0_TransModeInfo[] = {
    {

    
    
    1, /* TimePeriodFact */
    
    1, /* TimeOffsetFact */
    
    
    0, /* RepetitionPeriodFact */
    
    0,  /* NumRepetitions */

#ifdef COM_MIXEDPHASESHIFT
    
    COM_TXMODE_PERIODIC, /* Mode */
    COM_FALSE    /* MixedPhaseShift status */
#else

    
    
    COM_TXMODE_PERIODIC /* Mode */

#endif /* #ifdef COM_MIXEDPHASESHIFT */

    }

,
    {

    
    
    1, /* TimePeriodFact */
    
    1, /* TimeOffsetFact */
    
    
    0, /* RepetitionPeriodFact */
    
    0,  /* NumRepetitions */

#ifdef COM_MIXEDPHASESHIFT
    COM_TXMODE_PERIODIC, /* Mode */
    COM_FALSE    /* MixedPhaseShift status */
#else


    COM_TXMODE_PERIODIC /* Mode */

#endif /* #ifdef COM_MIXEDPHASESHIFT */

    }};

/* ------------------------------------------------------------------------ */
/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"



/* ------------------------------------------------------------------------ */
/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"

/* PEB_09_Can_Network_0_CANNODE_0 has a TMS switch */
static CONST(Com_TransModeInfo ,COM_CONST) Com_PEB_09_Can_Network_0_CANNODE_0_TransModeInfo[] = {
    {

    
    
    1, /* TimePeriodFact */
    
    1, /* TimeOffsetFact */
    
    
    0, /* RepetitionPeriodFact */
    
    0,  /* NumRepetitions */

#ifdef COM_MIXEDPHASESHIFT
    
    COM_TXMODE_PERIODIC, /* Mode */
    COM_FALSE    /* MixedPhaseShift status */
#else

    
    
    COM_TXMODE_PERIODIC /* Mode */

#endif /* #ifdef COM_MIXEDPHASESHIFT */

    }

,
    {

    
    
    1, /* TimePeriodFact */
    
    1, /* TimeOffsetFact */
    
    
    0, /* RepetitionPeriodFact */
    
    0,  /* NumRepetitions */

#ifdef COM_MIXEDPHASESHIFT
    COM_TXMODE_PERIODIC, /* Mode */
    COM_FALSE    /* MixedPhaseShift status */
#else


    COM_TXMODE_PERIODIC /* Mode */

#endif /* #ifdef COM_MIXEDPHASESHIFT */

    }};

/* ------------------------------------------------------------------------ */
/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"



/* ------------------------------------------------------------------------ */
/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"

/* PEB_02_Can_Network_0_CANNODE_0 has a TMS switch */
static CONST(Com_TransModeInfo ,COM_CONST) Com_PEB_02_Can_Network_0_CANNODE_0_TransModeInfo[] = {
    {

    
    
    10, /* TimePeriodFact */
    
    1, /* TimeOffsetFact */
    
    
    0, /* RepetitionPeriodFact */
    
    0,  /* NumRepetitions */

#ifdef COM_MIXEDPHASESHIFT
    
    COM_TXMODE_PERIODIC, /* Mode */
    COM_FALSE    /* MixedPhaseShift status */
#else

    
    
    COM_TXMODE_PERIODIC /* Mode */

#endif /* #ifdef COM_MIXEDPHASESHIFT */

    }

,
    {

    
    
    10, /* TimePeriodFact */
    
    1, /* TimeOffsetFact */
    
    
    0, /* RepetitionPeriodFact */
    
    0,  /* NumRepetitions */

#ifdef COM_MIXEDPHASESHIFT
    COM_TXMODE_PERIODIC, /* Mode */
    COM_FALSE    /* MixedPhaseShift status */
#else


    COM_TXMODE_PERIODIC /* Mode */

#endif /* #ifdef COM_MIXEDPHASESHIFT */

    }};

/* ------------------------------------------------------------------------ */
/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"



/* ------------------------------------------------------------------------ */
/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"

/* PEB_05_Can_Network_0_CANNODE_0 has a TMS switch */
static CONST(Com_TransModeInfo ,COM_CONST) Com_PEB_05_Can_Network_0_CANNODE_0_TransModeInfo[] = {
    {

    
    
    10, /* TimePeriodFact */
    
    1, /* TimeOffsetFact */
    
    
    0, /* RepetitionPeriodFact */
    
    0,  /* NumRepetitions */

#ifdef COM_MIXEDPHASESHIFT
    
    COM_TXMODE_PERIODIC, /* Mode */
    COM_FALSE    /* MixedPhaseShift status */
#else

    
    
    COM_TXMODE_PERIODIC /* Mode */

#endif /* #ifdef COM_MIXEDPHASESHIFT */

    }

,
    {

    
    
    10, /* TimePeriodFact */
    
    1, /* TimeOffsetFact */
    
    
    0, /* RepetitionPeriodFact */
    
    0,  /* NumRepetitions */

#ifdef COM_MIXEDPHASESHIFT
    COM_TXMODE_PERIODIC, /* Mode */
    COM_FALSE    /* MixedPhaseShift status */
#else


    COM_TXMODE_PERIODIC /* Mode */

#endif /* #ifdef COM_MIXEDPHASESHIFT */

    }};

/* ------------------------------------------------------------------------ */
/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"



/* ------------------------------------------------------------------------ */
/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"

/* PEB_07_Can_Network_0_CANNODE_0 has a TMS switch */
static CONST(Com_TransModeInfo ,COM_CONST) Com_PEB_07_Can_Network_0_CANNODE_0_TransModeInfo[] = {
    {

    
    
    10, /* TimePeriodFact */
    
    1, /* TimeOffsetFact */
    
    
    0, /* RepetitionPeriodFact */
    
    0,  /* NumRepetitions */

#ifdef COM_MIXEDPHASESHIFT
    
    COM_TXMODE_PERIODIC, /* Mode */
    COM_FALSE    /* MixedPhaseShift status */
#else

    
    
    COM_TXMODE_PERIODIC /* Mode */

#endif /* #ifdef COM_MIXEDPHASESHIFT */

    }

,
    {

    
    
    10, /* TimePeriodFact */
    
    1, /* TimeOffsetFact */
    
    
    0, /* RepetitionPeriodFact */
    
    0,  /* NumRepetitions */

#ifdef COM_MIXEDPHASESHIFT
    COM_TXMODE_PERIODIC, /* Mode */
    COM_FALSE    /* MixedPhaseShift status */
#else


    COM_TXMODE_PERIODIC /* Mode */

#endif /* #ifdef COM_MIXEDPHASESHIFT */

    }};

/* ------------------------------------------------------------------------ */
/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"



/* ------------------------------------------------------------------------ */
/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"

/* SysBoot_Tx_Can_Network_1_CANNODE_0 has a TMS switch */
static CONST(Com_TransModeInfo ,COM_CONST) Com_SysBoot_Tx_Can_Network_1_CANNODE_0_TransModeInfo[] = {
    {

    
    
    10, /* TimePeriodFact */
    
    1, /* TimeOffsetFact */
    
    
    0, /* RepetitionPeriodFact */
    
    0,  /* NumRepetitions */

#ifdef COM_MIXEDPHASESHIFT
    
    COM_TXMODE_PERIODIC, /* Mode */
    COM_FALSE    /* MixedPhaseShift status */
#else

    
    
    COM_TXMODE_PERIODIC /* Mode */

#endif /* #ifdef COM_MIXEDPHASESHIFT */

    }

,
    {

    
    
    10, /* TimePeriodFact */
    
    1, /* TimeOffsetFact */
    
    
    0, /* RepetitionPeriodFact */
    
    0,  /* NumRepetitions */

#ifdef COM_MIXEDPHASESHIFT
    COM_TXMODE_PERIODIC, /* Mode */
    COM_FALSE    /* MixedPhaseShift status */
#else


    COM_TXMODE_PERIODIC /* Mode */

#endif /* #ifdef COM_MIXEDPHASESHIFT */

    }};

/* ------------------------------------------------------------------------ */
/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"



/* ------------------------------------------------------------------------ */
/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"

/* PEB_06_Can_Network_0_CANNODE_0 has a TMS switch */
static CONST(Com_TransModeInfo ,COM_CONST) Com_PEB_06_Can_Network_0_CANNODE_0_TransModeInfo[] = {
    {

    
    
    100, /* TimePeriodFact */
    
    1, /* TimeOffsetFact */
    
    
    0, /* RepetitionPeriodFact */
    
    0,  /* NumRepetitions */

#ifdef COM_MIXEDPHASESHIFT
    
    COM_TXMODE_PERIODIC, /* Mode */
    COM_FALSE    /* MixedPhaseShift status */
#else

    
    
    COM_TXMODE_PERIODIC /* Mode */

#endif /* #ifdef COM_MIXEDPHASESHIFT */

    }

,
    {

    
    
    100, /* TimePeriodFact */
    
    1, /* TimeOffsetFact */
    
    
    0, /* RepetitionPeriodFact */
    
    0,  /* NumRepetitions */

#ifdef COM_MIXEDPHASESHIFT
    COM_TXMODE_PERIODIC, /* Mode */
    COM_FALSE    /* MixedPhaseShift status */
#else


    COM_TXMODE_PERIODIC /* Mode */

#endif /* #ifdef COM_MIXEDPHASESHIFT */

    }};

/* ------------------------------------------------------------------------ */
/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"

/* END: TMS Details  */



/* START: Tx IPDU Details  */

/* ------------------------------------------------------------------------ */
/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"

CONST(Com_Prv_xTxIpduInfoCfg_tst ,COM_CONST) Com_Prv_xTxIpduCfg_acst[COM_NUM_TX_IPDU] =
{
    {   /*Ipdu: DIAG_01_Can_Network_1_CANNODE_0*/

        Com_IpduBuf_DIAG_01_Can_Network_1_CANNODE_0,              /*Pointer to the Ipdu Buffer*/

        
        Com_DIAG_01_Can_Network_1_CANNODE_0_TransModeInfo,
        
        #ifdef COM_TxIPduCallOuts
        /* Ipdu Callout Function*/
        
        &Com_TxCallout_DIAG_01_Can_Network_1_CANNODE_0,
        
        #endif
        #ifdef COM_TxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,
        #endif

        #ifdef COM_ERRORNOTIFICATION
        /* Error Notification part */

        NULL_PTR,
        #endif

        #ifdef COM_TxIPduTimeOutNotify
        /* Timeout Notification part*/

        NULL_PTR,
        #endif

        #ifdef COM_TXDOUBLEBUFFER

        
        Com_LocalBuf_DIAG_01_Can_Network_1_CANNODE_0,      /*Pointer to the Local Ipdu Buffer*/
        
        #endif


        #ifdef COM_METADATA_SUPPORT
        NULL_PTR,               /* Pointer to the MetaData Ipdu Buffer */
        #endif


        8,/*Size in Bytes*/
        #ifdef COM_TxIPduTimeOut
        1,               /*Timeout Fact*/
        #endif /* #ifdef COM_TxIPduTimeOut */
        0, /*MinDelay Time factor*/

        8,                    /*No Of Signals present in the IPDU*/
        #ifdef COM_TX_SIGNALGROUP

        0,               /*No of Signal Groups present in the IPDU*/
        #endif

        (PduIdType)PduRConf_PduRSrcPdu_DIAG_01_Can_Network_1_CANNODE_0_Com2PduR,              /* PduR Id */

        (Com_TxIntSignalIdType)ComSignal_Internal_Diag_Data0_DIAG_01,     /*Index to First Signal within this Ipdu*/
        #ifdef COM_TX_SIGNALGROUP

        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif




/*
{
    Signal_Processing:1;          = IMMEDIATE
    TMSCalclation:2;              = MODE_VALID
    NoneModeTimeOut:1;            = COM_FALSE
    ClearUpdBit:2                 = CLEAR_UPDATEBIT_NOT_APPLICABLE
    FilterEvalReq:1               = COM_FALSE
    IsDynPdu:1;                   = COM_FALSE
    IsGwDestPdu:1;                = COM_FALSE
    IsCalloutFrmTrigTrans:1;      = COM_FALSE
    isLargeDataPdu:1;             = COM_FALSE
    isCancelTransmitSupported:1;  = COM_FALSE
    IsMetaDataSupported:1;        = COM_FALSE
    Not_Used:3;
}Com_TxIpduFlagType;
*/
        0x0,  /*Transmission Type*/

        0xFF              /*Padding Byte*/

    },
    {   /*Ipdu: PEB_01_Can_Network_0_CANNODE_0*/

        Com_IpduBuf_PEB_01_Can_Network_0_CANNODE_0,              /*Pointer to the Ipdu Buffer*/

        
        Com_PEB_01_Can_Network_0_CANNODE_0_TransModeInfo,
        
        #ifdef COM_TxIPduCallOuts
        /* Ipdu Callout Function*/
        NULL_PTR,
        
        #endif
        #ifdef COM_TxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,
        #endif

        #ifdef COM_ERRORNOTIFICATION
        /* Error Notification part */

        NULL_PTR,
        #endif

        #ifdef COM_TxIPduTimeOutNotify
        /* Timeout Notification part*/

        NULL_PTR,
        #endif

        #ifdef COM_TXDOUBLEBUFFER

        
        Com_LocalBuf_PEB_01_Can_Network_0_CANNODE_0,      /*Pointer to the Local Ipdu Buffer*/
        
        #endif


        #ifdef COM_METADATA_SUPPORT
        NULL_PTR,               /* Pointer to the MetaData Ipdu Buffer */
        #endif


        8,/*Size in Bytes*/
        #ifdef COM_TxIPduTimeOut
        1,               /*Timeout Fact*/
        #endif /* #ifdef COM_TxIPduTimeOut */
        0, /*MinDelay Time factor*/

        7,                    /*No Of Signals present in the IPDU*/
        #ifdef COM_TX_SIGNALGROUP

        0,               /*No of Signal Groups present in the IPDU*/
        #endif

        (PduIdType)PduRConf_PduRSrcPdu_PEB_01_Can_Network_0_CANNODE_0_Com2PduR,              /* PduR Id */

        (Com_TxIntSignalIdType)ComSignal_Internal_PEB01_ctRoll_PEB_01,     /*Index to First Signal within this Ipdu*/
        #ifdef COM_TX_SIGNALGROUP

        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif




/*
{
    Signal_Processing:1;          = IMMEDIATE
    TMSCalclation:2;              = MODE_VALID
    NoneModeTimeOut:1;            = COM_FALSE
    ClearUpdBit:2                 = CLEAR_UPDATEBIT_NOT_APPLICABLE
    FilterEvalReq:1               = COM_FALSE
    IsDynPdu:1;                   = COM_FALSE
    IsGwDestPdu:1;                = COM_FALSE
    IsCalloutFrmTrigTrans:1;      = COM_FALSE
    isLargeDataPdu:1;             = COM_FALSE
    isCancelTransmitSupported:1;  = COM_FALSE
    IsMetaDataSupported:1;        = COM_FALSE
    Not_Used:3;
}Com_TxIpduFlagType;
*/
        0x0,  /*Transmission Type*/

        0xFF              /*Padding Byte*/

    },
    {   /*Ipdu: PEB_03_Can_Network_0_CANNODE_0*/

        Com_IpduBuf_PEB_03_Can_Network_0_CANNODE_0,              /*Pointer to the Ipdu Buffer*/

        
        Com_PEB_03_Can_Network_0_CANNODE_0_TransModeInfo,
        
        #ifdef COM_TxIPduCallOuts
        /* Ipdu Callout Function*/
        NULL_PTR,
        
        #endif
        #ifdef COM_TxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,
        #endif

        #ifdef COM_ERRORNOTIFICATION
        /* Error Notification part */

        NULL_PTR,
        #endif

        #ifdef COM_TxIPduTimeOutNotify
        /* Timeout Notification part*/

        NULL_PTR,
        #endif

        #ifdef COM_TXDOUBLEBUFFER

        
        Com_LocalBuf_PEB_03_Can_Network_0_CANNODE_0,      /*Pointer to the Local Ipdu Buffer*/
        
        #endif


        #ifdef COM_METADATA_SUPPORT
        NULL_PTR,               /* Pointer to the MetaData Ipdu Buffer */
        #endif


        8,/*Size in Bytes*/
        #ifdef COM_TxIPduTimeOut
        1,               /*Timeout Fact*/
        #endif /* #ifdef COM_TxIPduTimeOut */
        0, /*MinDelay Time factor*/

        7,                    /*No Of Signals present in the IPDU*/
        #ifdef COM_TX_SIGNALGROUP

        0,               /*No of Signal Groups present in the IPDU*/
        #endif

        (PduIdType)PduRConf_PduRSrcPdu_PEB_03_Can_Network_0_CANNODE_0_Com2PduR,              /* PduR Id */

        (Com_TxIntSignalIdType)ComSignal_Internal_PEB03_TempEpp_PEB_03,     /*Index to First Signal within this Ipdu*/
        #ifdef COM_TX_SIGNALGROUP

        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif




/*
{
    Signal_Processing:1;          = IMMEDIATE
    TMSCalclation:2;              = MODE_VALID
    NoneModeTimeOut:1;            = COM_FALSE
    ClearUpdBit:2                 = CLEAR_UPDATEBIT_NOT_APPLICABLE
    FilterEvalReq:1               = COM_FALSE
    IsDynPdu:1;                   = COM_FALSE
    IsGwDestPdu:1;                = COM_FALSE
    IsCalloutFrmTrigTrans:1;      = COM_FALSE
    isLargeDataPdu:1;             = COM_FALSE
    isCancelTransmitSupported:1;  = COM_FALSE
    IsMetaDataSupported:1;        = COM_FALSE
    Not_Used:3;
}Com_TxIpduFlagType;
*/
        0x0,  /*Transmission Type*/

        0xFF              /*Padding Byte*/

    },
    {   /*Ipdu: PEB_04_Can_Network_0_CANNODE_0*/

        Com_IpduBuf_PEB_04_Can_Network_0_CANNODE_0,              /*Pointer to the Ipdu Buffer*/

        
        Com_PEB_04_Can_Network_0_CANNODE_0_TransModeInfo,
        
        #ifdef COM_TxIPduCallOuts
        /* Ipdu Callout Function*/
        NULL_PTR,
        
        #endif
        #ifdef COM_TxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,
        #endif

        #ifdef COM_ERRORNOTIFICATION
        /* Error Notification part */

        NULL_PTR,
        #endif

        #ifdef COM_TxIPduTimeOutNotify
        /* Timeout Notification part*/

        NULL_PTR,
        #endif

        #ifdef COM_TXDOUBLEBUFFER

        
        Com_LocalBuf_PEB_04_Can_Network_0_CANNODE_0,      /*Pointer to the Local Ipdu Buffer*/
        
        #endif


        #ifdef COM_METADATA_SUPPORT
        NULL_PTR,               /* Pointer to the MetaData Ipdu Buffer */
        #endif


        8,/*Size in Bytes*/
        #ifdef COM_TxIPduTimeOut
        1,               /*Timeout Fact*/
        #endif /* #ifdef COM_TxIPduTimeOut */
        0, /*MinDelay Time factor*/

        7,                    /*No Of Signals present in the IPDU*/
        #ifdef COM_TX_SIGNALGROUP

        0,               /*No of Signal Groups present in the IPDU*/
        #endif

        (PduIdType)PduRConf_PduRSrcPdu_PEB_04_Can_Network_0_CANNODE_0_Com2PduR,              /* PduR Id */

        (Com_TxIntSignalIdType)ComSignal_Internal_PEB04_TrqCurrWoDmpC_PEB_04,     /*Index to First Signal within this Ipdu*/
        #ifdef COM_TX_SIGNALGROUP

        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif




/*
{
    Signal_Processing:1;          = IMMEDIATE
    TMSCalclation:2;              = MODE_VALID
    NoneModeTimeOut:1;            = COM_FALSE
    ClearUpdBit:2                 = CLEAR_UPDATEBIT_NOT_APPLICABLE
    FilterEvalReq:1               = COM_FALSE
    IsDynPdu:1;                   = COM_FALSE
    IsGwDestPdu:1;                = COM_FALSE
    IsCalloutFrmTrigTrans:1;      = COM_FALSE
    isLargeDataPdu:1;             = COM_FALSE
    isCancelTransmitSupported:1;  = COM_FALSE
    IsMetaDataSupported:1;        = COM_FALSE
    Not_Used:3;
}Com_TxIpduFlagType;
*/
        0x0,  /*Transmission Type*/

        0xFF              /*Padding Byte*/

    },
    {   /*Ipdu: PEB_08_Can_Network_0_CANNODE_0*/

        Com_IpduBuf_PEB_08_Can_Network_0_CANNODE_0,              /*Pointer to the Ipdu Buffer*/

        
        Com_PEB_08_Can_Network_0_CANNODE_0_TransModeInfo,
        
        #ifdef COM_TxIPduCallOuts
        /* Ipdu Callout Function*/
        NULL_PTR,
        
        #endif
        #ifdef COM_TxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,
        #endif

        #ifdef COM_ERRORNOTIFICATION
        /* Error Notification part */

        NULL_PTR,
        #endif

        #ifdef COM_TxIPduTimeOutNotify
        /* Timeout Notification part*/

        NULL_PTR,
        #endif

        #ifdef COM_TXDOUBLEBUFFER

        
        Com_LocalBuf_PEB_08_Can_Network_0_CANNODE_0,      /*Pointer to the Local Ipdu Buffer*/
        
        #endif


        #ifdef COM_METADATA_SUPPORT
        NULL_PTR,               /* Pointer to the MetaData Ipdu Buffer */
        #endif


        8,/*Size in Bytes*/
        #ifdef COM_TxIPduTimeOut
        1,               /*Timeout Fact*/
        #endif /* #ifdef COM_TxIPduTimeOut */
        0, /*MinDelay Time factor*/

        2,                    /*No Of Signals present in the IPDU*/
        #ifdef COM_TX_SIGNALGROUP

        0,               /*No of Signal Groups present in the IPDU*/
        #endif

        (PduIdType)PduRConf_PduRSrcPdu_PEB_08_Can_Network_0_CANNODE_0_Com2PduR,              /* PduR Id */

        (Com_TxIntSignalIdType)ComSignal_Internal_PEB08_HwVer_PEB_08,     /*Index to First Signal within this Ipdu*/
        #ifdef COM_TX_SIGNALGROUP

        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif




/*
{
    Signal_Processing:1;          = IMMEDIATE
    TMSCalclation:2;              = MODE_VALID
    NoneModeTimeOut:1;            = COM_FALSE
    ClearUpdBit:2                 = CLEAR_UPDATEBIT_NOT_APPLICABLE
    FilterEvalReq:1               = COM_FALSE
    IsDynPdu:1;                   = COM_FALSE
    IsGwDestPdu:1;                = COM_FALSE
    IsCalloutFrmTrigTrans:1;      = COM_FALSE
    isLargeDataPdu:1;             = COM_FALSE
    isCancelTransmitSupported:1;  = COM_FALSE
    IsMetaDataSupported:1;        = COM_FALSE
    Not_Used:3;
}Com_TxIpduFlagType;
*/
        0x0,  /*Transmission Type*/

        0xFF              /*Padding Byte*/

    },
    {   /*Ipdu: PEB_09_Can_Network_0_CANNODE_0*/

        Com_IpduBuf_PEB_09_Can_Network_0_CANNODE_0,              /*Pointer to the Ipdu Buffer*/

        
        Com_PEB_09_Can_Network_0_CANNODE_0_TransModeInfo,
        
        #ifdef COM_TxIPduCallOuts
        /* Ipdu Callout Function*/
        NULL_PTR,
        
        #endif
        #ifdef COM_TxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,
        #endif

        #ifdef COM_ERRORNOTIFICATION
        /* Error Notification part */

        NULL_PTR,
        #endif

        #ifdef COM_TxIPduTimeOutNotify
        /* Timeout Notification part*/

        NULL_PTR,
        #endif

        #ifdef COM_TXDOUBLEBUFFER

        
        Com_LocalBuf_PEB_09_Can_Network_0_CANNODE_0,      /*Pointer to the Local Ipdu Buffer*/
        
        #endif


        #ifdef COM_METADATA_SUPPORT
        NULL_PTR,               /* Pointer to the MetaData Ipdu Buffer */
        #endif


        8,/*Size in Bytes*/
        #ifdef COM_TxIPduTimeOut
        1,               /*Timeout Fact*/
        #endif /* #ifdef COM_TxIPduTimeOut */
        0, /*MinDelay Time factor*/

        6,                    /*No Of Signals present in the IPDU*/
        #ifdef COM_TX_SIGNALGROUP

        0,               /*No of Signal Groups present in the IPDU*/
        #endif

        (PduIdType)PduRConf_PduRSrcPdu_PEB_09_Can_Network_0_CANNODE_0_Com2PduR,              /* PduR Id */

        (Com_TxIntSignalIdType)ComSignal_Internal_PEB09_stEppFailSt_PEB_09,     /*Index to First Signal within this Ipdu*/
        #ifdef COM_TX_SIGNALGROUP

        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif




/*
{
    Signal_Processing:1;          = IMMEDIATE
    TMSCalclation:2;              = MODE_VALID
    NoneModeTimeOut:1;            = COM_FALSE
    ClearUpdBit:2                 = CLEAR_UPDATEBIT_NOT_APPLICABLE
    FilterEvalReq:1               = COM_FALSE
    IsDynPdu:1;                   = COM_FALSE
    IsGwDestPdu:1;                = COM_FALSE
    IsCalloutFrmTrigTrans:1;      = COM_FALSE
    isLargeDataPdu:1;             = COM_FALSE
    isCancelTransmitSupported:1;  = COM_FALSE
    IsMetaDataSupported:1;        = COM_FALSE
    Not_Used:3;
}Com_TxIpduFlagType;
*/
        0x0,  /*Transmission Type*/

        0xFF              /*Padding Byte*/

    },
    {   /*Ipdu: PEB_02_Can_Network_0_CANNODE_0*/

        Com_IpduBuf_PEB_02_Can_Network_0_CANNODE_0,              /*Pointer to the Ipdu Buffer*/

        
        Com_PEB_02_Can_Network_0_CANNODE_0_TransModeInfo,
        
        #ifdef COM_TxIPduCallOuts
        /* Ipdu Callout Function*/
        NULL_PTR,
        
        #endif
        #ifdef COM_TxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,
        #endif

        #ifdef COM_ERRORNOTIFICATION
        /* Error Notification part */

        NULL_PTR,
        #endif

        #ifdef COM_TxIPduTimeOutNotify
        /* Timeout Notification part*/

        NULL_PTR,
        #endif

        #ifdef COM_TXDOUBLEBUFFER

        
        Com_LocalBuf_PEB_02_Can_Network_0_CANNODE_0,      /*Pointer to the Local Ipdu Buffer*/
        
        #endif


        #ifdef COM_METADATA_SUPPORT
        NULL_PTR,               /* Pointer to the MetaData Ipdu Buffer */
        #endif


        8,/*Size in Bytes*/
        #ifdef COM_TxIPduTimeOut
        10,               /*Timeout Fact*/
        #endif /* #ifdef COM_TxIPduTimeOut */
        0, /*MinDelay Time factor*/

        18,                    /*No Of Signals present in the IPDU*/
        #ifdef COM_TX_SIGNALGROUP

        0,               /*No of Signal Groups present in the IPDU*/
        #endif

        (PduIdType)PduRConf_PduRSrcPdu_PEB_02_Can_Network_0_CANNODE_0_Com2PduR,              /* PduR Id */

        (Com_TxIntSignalIdType)ComSignal_Internal_PEB02_bDernTempIGBT_PEB_02,     /*Index to First Signal within this Ipdu*/
        #ifdef COM_TX_SIGNALGROUP

        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif




/*
{
    Signal_Processing:1;          = IMMEDIATE
    TMSCalclation:2;              = MODE_VALID
    NoneModeTimeOut:1;            = COM_FALSE
    ClearUpdBit:2                 = CLEAR_UPDATEBIT_NOT_APPLICABLE
    FilterEvalReq:1               = COM_FALSE
    IsDynPdu:1;                   = COM_FALSE
    IsGwDestPdu:1;                = COM_FALSE
    IsCalloutFrmTrigTrans:1;      = COM_FALSE
    isLargeDataPdu:1;             = COM_FALSE
    isCancelTransmitSupported:1;  = COM_FALSE
    IsMetaDataSupported:1;        = COM_FALSE
    Not_Used:3;
}Com_TxIpduFlagType;
*/
        0x0,  /*Transmission Type*/

        0xFF              /*Padding Byte*/

    },
    {   /*Ipdu: PEB_05_Can_Network_0_CANNODE_0*/

        Com_IpduBuf_PEB_05_Can_Network_0_CANNODE_0,              /*Pointer to the Ipdu Buffer*/

        
        Com_PEB_05_Can_Network_0_CANNODE_0_TransModeInfo,
        
        #ifdef COM_TxIPduCallOuts
        /* Ipdu Callout Function*/
        NULL_PTR,
        
        #endif
        #ifdef COM_TxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,
        #endif

        #ifdef COM_ERRORNOTIFICATION
        /* Error Notification part */

        NULL_PTR,
        #endif

        #ifdef COM_TxIPduTimeOutNotify
        /* Timeout Notification part*/

        NULL_PTR,
        #endif

        #ifdef COM_TXDOUBLEBUFFER

        
        Com_LocalBuf_PEB_05_Can_Network_0_CANNODE_0,      /*Pointer to the Local Ipdu Buffer*/
        
        #endif


        #ifdef COM_METADATA_SUPPORT
        NULL_PTR,               /* Pointer to the MetaData Ipdu Buffer */
        #endif


        8,/*Size in Bytes*/
        #ifdef COM_TxIPduTimeOut
        10,               /*Timeout Fact*/
        #endif /* #ifdef COM_TxIPduTimeOut */
        0, /*MinDelay Time factor*/

        8,                    /*No Of Signals present in the IPDU*/
        #ifdef COM_TX_SIGNALGROUP

        0,               /*No of Signal Groups present in the IPDU*/
        #endif

        (PduIdType)PduRConf_PduRSrcPdu_PEB_05_Can_Network_0_CANNODE_0_Com2PduR,              /* PduR Id */

        (Com_TxIntSignalIdType)ComSignal_Internal_PEB05_FailCode8_PEB_05,     /*Index to First Signal within this Ipdu*/
        #ifdef COM_TX_SIGNALGROUP

        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif




/*
{
    Signal_Processing:1;          = IMMEDIATE
    TMSCalclation:2;              = MODE_VALID
    NoneModeTimeOut:1;            = COM_FALSE
    ClearUpdBit:2                 = CLEAR_UPDATEBIT_NOT_APPLICABLE
    FilterEvalReq:1               = COM_FALSE
    IsDynPdu:1;                   = COM_FALSE
    IsGwDestPdu:1;                = COM_FALSE
    IsCalloutFrmTrigTrans:1;      = COM_FALSE
    isLargeDataPdu:1;             = COM_FALSE
    isCancelTransmitSupported:1;  = COM_FALSE
    IsMetaDataSupported:1;        = COM_FALSE
    Not_Used:3;
}Com_TxIpduFlagType;
*/
        0x0,  /*Transmission Type*/

        0xFF              /*Padding Byte*/

    },
    {   /*Ipdu: PEB_07_Can_Network_0_CANNODE_0*/

        Com_IpduBuf_PEB_07_Can_Network_0_CANNODE_0,              /*Pointer to the Ipdu Buffer*/

        
        Com_PEB_07_Can_Network_0_CANNODE_0_TransModeInfo,
        
        #ifdef COM_TxIPduCallOuts
        /* Ipdu Callout Function*/
		&Com_Callout_PEB07_0x430_Can_Network_0_CANNODE_0,
        
        #endif
        #ifdef COM_TxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,
        #endif

        #ifdef COM_ERRORNOTIFICATION
        /* Error Notification part */

        NULL_PTR,
        #endif

        #ifdef COM_TxIPduTimeOutNotify
        /* Timeout Notification part*/

        NULL_PTR,
        #endif

        #ifdef COM_TXDOUBLEBUFFER

        
        Com_LocalBuf_PEB_07_Can_Network_0_CANNODE_0,      /*Pointer to the Local Ipdu Buffer*/
        
        #endif


        #ifdef COM_METADATA_SUPPORT
        NULL_PTR,               /* Pointer to the MetaData Ipdu Buffer */
        #endif


        8,/*Size in Bytes*/
        #ifdef COM_TxIPduTimeOut
        10,               /*Timeout Fact*/
        #endif /* #ifdef COM_TxIPduTimeOut */
        0, /*MinDelay Time factor*/

        4,                    /*No Of Signals present in the IPDU*/
        #ifdef COM_TX_SIGNALGROUP

        0,               /*No of Signal Groups present in the IPDU*/
        #endif

        (PduIdType)PduRConf_PduRSrcPdu_PEB_07_Can_Network_0_CANNODE_0_Com2PduR,              /* PduR Id */

        (Com_TxIntSignalIdType)ComSignal_Internal_PEB07_MinPredTrq_PEB_07,     /*Index to First Signal within this Ipdu*/
        #ifdef COM_TX_SIGNALGROUP

        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif




/*
{
    Signal_Processing:1;          = IMMEDIATE
    TMSCalclation:2;              = MODE_VALID
    NoneModeTimeOut:1;            = COM_FALSE
    ClearUpdBit:2                 = CLEAR_UPDATEBIT_NOT_APPLICABLE
    FilterEvalReq:1               = COM_FALSE
    IsDynPdu:1;                   = COM_FALSE
    IsGwDestPdu:1;                = COM_FALSE
    IsCalloutFrmTrigTrans:1;      = COM_FALSE
    isLargeDataPdu:1;             = COM_FALSE
    isCancelTransmitSupported:1;  = COM_FALSE
    IsMetaDataSupported:1;        = COM_FALSE
    Not_Used:3;
}Com_TxIpduFlagType;
*/
        0x0,  /*Transmission Type*/

        0xFF              /*Padding Byte*/

    },
    {   /*Ipdu: SysBoot_Tx_Can_Network_1_CANNODE_0*/

        Com_IpduBuf_SysBoot_Tx_Can_Network_1_CANNODE_0,              /*Pointer to the Ipdu Buffer*/

        
        Com_SysBoot_Tx_Can_Network_1_CANNODE_0_TransModeInfo,
        
        #ifdef COM_TxIPduCallOuts
        /* Ipdu Callout Function*/
        
        &Com_TxCallout_SysBoot_Tx_Can_Network_1_CANNODE_0,
        
        #endif
        #ifdef COM_TxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,
        #endif

        #ifdef COM_ERRORNOTIFICATION
        /* Error Notification part */

        NULL_PTR,
        #endif

        #ifdef COM_TxIPduTimeOutNotify
        /* Timeout Notification part*/

        NULL_PTR,
        #endif

        #ifdef COM_TXDOUBLEBUFFER

        
        Com_LocalBuf_SysBoot_Tx_Can_Network_1_CANNODE_0,      /*Pointer to the Local Ipdu Buffer*/
        
        #endif


        #ifdef COM_METADATA_SUPPORT
        NULL_PTR,               /* Pointer to the MetaData Ipdu Buffer */
        #endif


        8,/*Size in Bytes*/
        #ifdef COM_TxIPduTimeOut
        10,               /*Timeout Fact*/
        #endif /* #ifdef COM_TxIPduTimeOut */
        0, /*MinDelay Time factor*/

        8,                    /*No Of Signals present in the IPDU*/
        #ifdef COM_TX_SIGNALGROUP

        0,               /*No of Signal Groups present in the IPDU*/
        #endif

        (PduIdType)PduRConf_PduRSrcPdu_SysBoot_Tx_Can_Network_1_CANNODE_0_Com2PduR,              /* PduR Id */

        (Com_TxIntSignalIdType)ComSignal_Internal_SysBoot_Tx0_SysBoot_Tx,     /*Index to First Signal within this Ipdu*/
        #ifdef COM_TX_SIGNALGROUP

        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif




/*
{
    Signal_Processing:1;          = IMMEDIATE
    TMSCalclation:2;              = MODE_VALID
    NoneModeTimeOut:1;            = COM_FALSE
    ClearUpdBit:2                 = CLEAR_UPDATEBIT_NOT_APPLICABLE
    FilterEvalReq:1               = COM_FALSE
    IsDynPdu:1;                   = COM_FALSE
    IsGwDestPdu:1;                = COM_FALSE
    IsCalloutFrmTrigTrans:1;      = COM_FALSE
    isLargeDataPdu:1;             = COM_FALSE
    isCancelTransmitSupported:1;  = COM_FALSE
    IsMetaDataSupported:1;        = COM_FALSE
    Not_Used:3;
}Com_TxIpduFlagType;
*/
        0x0,  /*Transmission Type*/

        0xFF              /*Padding Byte*/

    },
    {   /*Ipdu: PEB_06_Can_Network_0_CANNODE_0*/

        Com_IpduBuf_PEB_06_Can_Network_0_CANNODE_0,              /*Pointer to the Ipdu Buffer*/

        
        Com_PEB_06_Can_Network_0_CANNODE_0_TransModeInfo,
        
        #ifdef COM_TxIPduCallOuts
        /* Ipdu Callout Function*/
        NULL_PTR,
        
        #endif
        #ifdef COM_TxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,
        #endif

        #ifdef COM_ERRORNOTIFICATION
        /* Error Notification part */

        NULL_PTR,
        #endif

        #ifdef COM_TxIPduTimeOutNotify
        /* Timeout Notification part*/

        NULL_PTR,
        #endif

        #ifdef COM_TXDOUBLEBUFFER

        
        Com_LocalBuf_PEB_06_Can_Network_0_CANNODE_0,      /*Pointer to the Local Ipdu Buffer*/
        
        #endif


        #ifdef COM_METADATA_SUPPORT
        NULL_PTR,               /* Pointer to the MetaData Ipdu Buffer */
        #endif


        8,/*Size in Bytes*/
        #ifdef COM_TxIPduTimeOut
        100,               /*Timeout Fact*/
        #endif /* #ifdef COM_TxIPduTimeOut */
        0, /*MinDelay Time factor*/

        4,                    /*No Of Signals present in the IPDU*/
        #ifdef COM_TX_SIGNALGROUP

        0,               /*No of Signal Groups present in the IPDU*/
        #endif

        (PduIdType)PduRConf_PduRSrcPdu_PEB_06_Can_Network_0_CANNODE_0_Com2PduR,              /* PduR Id */

        (Com_TxIntSignalIdType)ComSignal_Internal_PEB06_HvMcuVer_PEB_06,     /*Index to First Signal within this Ipdu*/
        #ifdef COM_TX_SIGNALGROUP

        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif




/*
{
    Signal_Processing:1;          = IMMEDIATE
    TMSCalclation:2;              = MODE_VALID
    NoneModeTimeOut:1;            = COM_FALSE
    ClearUpdBit:2                 = CLEAR_UPDATEBIT_NOT_APPLICABLE
    FilterEvalReq:1               = COM_FALSE
    IsDynPdu:1;                   = COM_FALSE
    IsGwDestPdu:1;                = COM_FALSE
    IsCalloutFrmTrigTrans:1;      = COM_FALSE
    isLargeDataPdu:1;             = COM_FALSE
    isCancelTransmitSupported:1;  = COM_FALSE
    IsMetaDataSupported:1;        = COM_FALSE
    Not_Used:3;
}Com_TxIpduFlagType;
*/
        0x0,  /*Transmission Type*/

        0xFF              /*Padding Byte*/

    }
};

/* ------------------------------------------------------------------------ */
/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"

/* END: Tx IPDU Details  */

/* START : Time out information structure for signals with update-bits */
#ifdef COM_RxSigUpdateTimeout
#endif /* #ifdef COM_RxSigUpdateTimeout */
/* END : Time out information structure for signals with update-bits */

/* START : Time out information structure for signal groups with update-bits */
#ifdef COM_RxSigGrpUpdateTimeout
#endif /* #ifdef COM_RxSigGrpUpdateTimeout */

#ifdef COM_RxSigUpdateTimeout
#endif /* #ifdef COM_RxSigUpdateTimeout */
/* END : Time out information structure for signals with update-bits */

/* START : Time out information structure for signal groups with update-bits */
#ifdef COM_RxSigGrpUpdateTimeout
#endif /* #ifdef COM_RxSigGrpUpdateTimeout */
/* END : Time out information structure for signal groups with update-bits */



/* START: Rx IPDU Details  */

/* ------------------------------------------------------------------------ */
/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"


CONST(Com_Prv_xRxIpduInfoCfg_tst ,COM_CONST) Com_Prv_xRxIpduCfg_acst[COM_NUM_RX_IPDU] =
{
    {   /*Ipdu: BMS_01_Can_Network_0_CANNODE_0*/
        

        Com_LocalBuf_BMS_01_Can_Network_0_CANNODE_0,              /*Pointer to the Local Ipdu Buffer*/
        
        #ifdef COM_RxSigUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signals with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigUpdateTimeout */
        #ifdef COM_RxSigGrpUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signal groups with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigGrpUpdateTimeout */

        #ifdef COM_RxIPduCallOuts
        /* Ipdu Callout */

        
        &Com_RxCallout_BMS_01_Can_Network_0_CANNODE_0,
        
        #endif

        #ifdef COM_RxIPduTimeoutNotify
        /* Timeout Notification part*/

        NULL_PTR,
        #endif /* COM_RxIPduTimeoutNotify */

        #ifdef COM_RxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,              /* Rx IPdu notification callback */
        #endif

        8, /*Size in Bytes*/

        #ifdef COM_RxIPduTimeout

        0,        /* First time out value after IPDU group start */

        0,              /*CC requriment: Support Rx IPDU Timeout*/
        #endif /* #ifdef COM_RxIPduTimeout */

        5,                /*No Of Signals present in the IPDU*/
        #ifdef COM_RX_SIGNALGROUP

        0,           /*No of Signal Groups present in the IPDU*/
        #endif

        (Com_RxIntSignalIdType)ComSignal_Internal_BMS01_stMainRelay_BMS_01,   /*Index to First Signal within this Ipdu*/
         #ifdef COM_RX_SIGNALGROUP

        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif
#ifdef COM_SIGNALGATEWAY
        0,       /* Number of signals with gateway */
#endif /* #ifdef COM_SIGNALGATEWAY */
#ifdef COM_SIGNALGROUPGATEWAY
        0,   /* Number of signal groups with gateway */
#endif /* #ifdef COM_SIGNALGROUPGATEWAY */

        /*
        {
            Signal_Processing:1;  = IMMEDIATE
            Notify_Cbk:1;         = true
            IsGwIPdu:1;           = false
            Not_Used:5;
        } Com_RxIpduFlagType;
        */
        0x2                /*Reception Type*/

    },
    {   /*Ipdu: SysBoot_Rx_Can_Network_1_CANNODE_0*/
        

        Com_LocalBuf_SysBoot_Rx_Can_Network_1_CANNODE_0,              /*Pointer to the Local Ipdu Buffer*/
        
        #ifdef COM_RxSigUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signals with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigUpdateTimeout */
        #ifdef COM_RxSigGrpUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signal groups with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigGrpUpdateTimeout */

        #ifdef COM_RxIPduCallOuts
        /* Ipdu Callout */

        
        &SysBoot_SysBoot_Rx_Can_Network_1_CANNODE_0,
        
        #endif

        #ifdef COM_RxIPduTimeoutNotify
        /* Timeout Notification part*/

        NULL_PTR,
        #endif /* COM_RxIPduTimeoutNotify */

        #ifdef COM_RxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,              /* Rx IPdu notification callback */
        #endif

        8, /*Size in Bytes*/

        #ifdef COM_RxIPduTimeout

        0,        /* First time out value after IPDU group start */

        0,              /*CC requriment: Support Rx IPDU Timeout*/
        #endif /* #ifdef COM_RxIPduTimeout */

        8,                /*No Of Signals present in the IPDU*/
        #ifdef COM_RX_SIGNALGROUP

        0,           /*No of Signal Groups present in the IPDU*/
        #endif

        (Com_RxIntSignalIdType)ComSignal_Internal_SysBoot_Rx0_SysBoot_Rx,   /*Index to First Signal within this Ipdu*/
         #ifdef COM_RX_SIGNALGROUP

        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif
#ifdef COM_SIGNALGATEWAY
        0,       /* Number of signals with gateway */
#endif /* #ifdef COM_SIGNALGATEWAY */
#ifdef COM_SIGNALGROUPGATEWAY
        0,   /* Number of signal groups with gateway */
#endif /* #ifdef COM_SIGNALGROUPGATEWAY */

        /*
        {
            Signal_Processing:1;  = IMMEDIATE
            Notify_Cbk:1;         = false
            IsGwIPdu:1;           = false
            Not_Used:5;
        } Com_RxIpduFlagType;
        */
        0x0                /*Reception Type*/

    },
    {   /*Ipdu: TOOL_01_Can_Network_1_CANNODE_0*/
        

        Com_LocalBuf_TOOL_01_Can_Network_1_CANNODE_0,              /*Pointer to the Local Ipdu Buffer*/
        
        #ifdef COM_RxSigUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signals with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigUpdateTimeout */
        #ifdef COM_RxSigGrpUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signal groups with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigGrpUpdateTimeout */

        #ifdef COM_RxIPduCallOuts
        /* Ipdu Callout */

        
        &Com_RxCallout_TOOL_01_Can_Network_1_CANNODE_0,
        
        #endif

        #ifdef COM_RxIPduTimeoutNotify
        /* Timeout Notification part*/

        NULL_PTR,
        #endif /* COM_RxIPduTimeoutNotify */

        #ifdef COM_RxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,              /* Rx IPdu notification callback */
        #endif

        8, /*Size in Bytes*/

        #ifdef COM_RxIPduTimeout

        0,        /* First time out value after IPDU group start */

        0,              /*CC requriment: Support Rx IPDU Timeout*/
        #endif /* #ifdef COM_RxIPduTimeout */

        1,                /*No Of Signals present in the IPDU*/
        #ifdef COM_RX_SIGNALGROUP

        0,           /*No of Signal Groups present in the IPDU*/
        #endif

        (Com_RxIntSignalIdType)ComSignal_Internal_Data_Access_TOOL_01,   /*Index to First Signal within this Ipdu*/
         #ifdef COM_RX_SIGNALGROUP

        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif
#ifdef COM_SIGNALGATEWAY
        0,       /* Number of signals with gateway */
#endif /* #ifdef COM_SIGNALGATEWAY */
#ifdef COM_SIGNALGROUPGATEWAY
        0,   /* Number of signal groups with gateway */
#endif /* #ifdef COM_SIGNALGROUPGATEWAY */

        /*
        {
            Signal_Processing:1;  = DEFERRED
            Notify_Cbk:1;         = false
            IsGwIPdu:1;           = false
            Not_Used:5;
        } Com_RxIpduFlagType;
        */
        0x1                /*Reception Type*/

    },
    {   /*Ipdu: VCU_01_Can_Network_0_CANNODE_0*/
        

        Com_LocalBuf_VCU_01_Can_Network_0_CANNODE_0,              /*Pointer to the Local Ipdu Buffer*/
        
        #ifdef COM_RxSigUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signals with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigUpdateTimeout */
        #ifdef COM_RxSigGrpUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signal groups with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigGrpUpdateTimeout */

        #ifdef COM_RxIPduCallOuts
        /* Ipdu Callout */

        
        &Com_RxCallout_VCU_01_Can_Network_0_CANNODE_0,
        
        #endif

        #ifdef COM_RxIPduTimeoutNotify
        /* Timeout Notification part*/

        NULL_PTR,
        #endif /* COM_RxIPduTimeoutNotify */

        #ifdef COM_RxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,              /* Rx IPdu notification callback */
        #endif

        8, /*Size in Bytes*/

        #ifdef COM_RxIPduTimeout

        0,        /* First time out value after IPDU group start */

        0,              /*CC requriment: Support Rx IPDU Timeout*/
        #endif /* #ifdef COM_RxIPduTimeout */

        7,                /*No Of Signals present in the IPDU*/
        #ifdef COM_RX_SIGNALGROUP

        0,           /*No of Signal Groups present in the IPDU*/
        #endif

        (Com_RxIntSignalIdType)ComSignal_Internal_VCU01_ctRoll_VCU_01,   /*Index to First Signal within this Ipdu*/
         #ifdef COM_RX_SIGNALGROUP

        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif
#ifdef COM_SIGNALGATEWAY
        0,       /* Number of signals with gateway */
#endif /* #ifdef COM_SIGNALGATEWAY */
#ifdef COM_SIGNALGROUPGATEWAY
        0,   /* Number of signal groups with gateway */
#endif /* #ifdef COM_SIGNALGROUPGATEWAY */

        /*
        {
            Signal_Processing:1;  = IMMEDIATE
            Notify_Cbk:1;         = true
            IsGwIPdu:1;           = false
            Not_Used:5;
        } Com_RxIpduFlagType;
        */
        0x2                /*Reception Type*/

    },
    {   /*Ipdu: VCU_02_Can_Network_0_CANNODE_0*/
        

        Com_LocalBuf_VCU_02_Can_Network_0_CANNODE_0,              /*Pointer to the Local Ipdu Buffer*/
        
        #ifdef COM_RxSigUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signals with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigUpdateTimeout */
        #ifdef COM_RxSigGrpUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signal groups with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigGrpUpdateTimeout */

        #ifdef COM_RxIPduCallOuts
        /* Ipdu Callout */

        
        &Com_RxCallout_VCU_02_Can_Network_0_CANNODE_0,
        
        #endif

        #ifdef COM_RxIPduTimeoutNotify
        /* Timeout Notification part*/

        NULL_PTR,
        #endif /* COM_RxIPduTimeoutNotify */

        #ifdef COM_RxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,              /* Rx IPdu notification callback */
        #endif

        8, /*Size in Bytes*/

        #ifdef COM_RxIPduTimeout

        0,        /* First time out value after IPDU group start */

        0,              /*CC requriment: Support Rx IPDU Timeout*/
        #endif /* #ifdef COM_RxIPduTimeout */

        5,                /*No Of Signals present in the IPDU*/
        #ifdef COM_RX_SIGNALGROUP

        0,           /*No of Signal Groups present in the IPDU*/
        #endif

        (Com_RxIntSignalIdType)ComSignal_Internal_VCU02_TrqMinNCtl_VCU_02,   /*Index to First Signal within this Ipdu*/
         #ifdef COM_RX_SIGNALGROUP

        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif
#ifdef COM_SIGNALGATEWAY
        0,       /* Number of signals with gateway */
#endif /* #ifdef COM_SIGNALGATEWAY */
#ifdef COM_SIGNALGROUPGATEWAY
        0,   /* Number of signal groups with gateway */
#endif /* #ifdef COM_SIGNALGROUPGATEWAY */

        /*
        {
            Signal_Processing:1;  = IMMEDIATE
            Notify_Cbk:1;         = true
            IsGwIPdu:1;           = false
            Not_Used:5;
        } Com_RxIpduFlagType;
        */
        0x2                /*Reception Type*/

    },
    {   /*Ipdu: VCU_03_Can_Network_0_CANNODE_0*/
        

        Com_LocalBuf_VCU_03_Can_Network_0_CANNODE_0,              /*Pointer to the Local Ipdu Buffer*/
        
        #ifdef COM_RxSigUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signals with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigUpdateTimeout */
        #ifdef COM_RxSigGrpUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signal groups with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigGrpUpdateTimeout */

        #ifdef COM_RxIPduCallOuts
        /* Ipdu Callout */

        
        &Com_RxCallout_VCU_03_Can_Network_0_CANNODE_0,
        
        #endif

        #ifdef COM_RxIPduTimeoutNotify
        /* Timeout Notification part*/

        NULL_PTR,
        #endif /* COM_RxIPduTimeoutNotify */

        #ifdef COM_RxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,              /* Rx IPdu notification callback */
        #endif

        8, /*Size in Bytes*/

        #ifdef COM_RxIPduTimeout

        0,        /* First time out value after IPDU group start */

        0,              /*CC requriment: Support Rx IPDU Timeout*/
        #endif /* #ifdef COM_RxIPduTimeout */

        5,                /*No Of Signals present in the IPDU*/
        #ifdef COM_RX_SIGNALGROUP

        0,           /*No of Signal Groups present in the IPDU*/
        #endif

        (Com_RxIntSignalIdType)ComSignal_Internal_VCU03_ctRoll_VCU_03,   /*Index to First Signal within this Ipdu*/
         #ifdef COM_RX_SIGNALGROUP

        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif
#ifdef COM_SIGNALGATEWAY
        0,       /* Number of signals with gateway */
#endif /* #ifdef COM_SIGNALGATEWAY */
#ifdef COM_SIGNALGROUPGATEWAY
        0,   /* Number of signal groups with gateway */
#endif /* #ifdef COM_SIGNALGROUPGATEWAY */

        /*
        {
            Signal_Processing:1;  = IMMEDIATE
            Notify_Cbk:1;         = true
            IsGwIPdu:1;           = false
            Not_Used:5;
        } Com_RxIpduFlagType;
        */
        0x2                /*Reception Type*/

    },
    {   /*Ipdu: VCU_04_Can_Network_0_CANNODE_0*/
        

        Com_LocalBuf_VCU_04_Can_Network_0_CANNODE_0,              /*Pointer to the Local Ipdu Buffer*/
        
        #ifdef COM_RxSigUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signals with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigUpdateTimeout */
        #ifdef COM_RxSigGrpUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signal groups with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigGrpUpdateTimeout */

        #ifdef COM_RxIPduCallOuts
        /* Ipdu Callout */

        
        &Com_RxCallout_VCU_04_Can_Network_0_CANNODE_0,
        
        #endif

        #ifdef COM_RxIPduTimeoutNotify
        /* Timeout Notification part*/

        NULL_PTR,
        #endif /* COM_RxIPduTimeoutNotify */

        #ifdef COM_RxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,              /* Rx IPdu notification callback */
        #endif

        8, /*Size in Bytes*/

        #ifdef COM_RxIPduTimeout

        0,        /* First time out value after IPDU group start */

        0,              /*CC requriment: Support Rx IPDU Timeout*/
        #endif /* #ifdef COM_RxIPduTimeout */

        7,                /*No Of Signals present in the IPDU*/
        #ifdef COM_RX_SIGNALGROUP

        0,           /*No of Signal Groups present in the IPDU*/
        #endif

        (Com_RxIntSignalIdType)ComSignal_Internal_VCU04_MotDir_VCU_04,   /*Index to First Signal within this Ipdu*/
         #ifdef COM_RX_SIGNALGROUP

        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif
#ifdef COM_SIGNALGATEWAY
        0,       /* Number of signals with gateway */
#endif /* #ifdef COM_SIGNALGATEWAY */
#ifdef COM_SIGNALGROUPGATEWAY
        0,   /* Number of signal groups with gateway */
#endif /* #ifdef COM_SIGNALGROUPGATEWAY */

        /*
        {
            Signal_Processing:1;  = IMMEDIATE
            Notify_Cbk:1;         = true
            IsGwIPdu:1;           = false
            Not_Used:5;
        } Com_RxIpduFlagType;
        */
        0x2                /*Reception Type*/

    },
    {   /*Ipdu: VCU_05_Can_Network_0_CANNODE_0*/
        

        Com_LocalBuf_VCU_05_Can_Network_0_CANNODE_0,              /*Pointer to the Local Ipdu Buffer*/
        
        #ifdef COM_RxSigUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signals with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigUpdateTimeout */
        #ifdef COM_RxSigGrpUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signal groups with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigGrpUpdateTimeout */

        #ifdef COM_RxIPduCallOuts
        /* Ipdu Callout */

        
        &Com_RxCallout_VCU_05_Can_Network_0_CANNODE_0,
        
        #endif

        #ifdef COM_RxIPduTimeoutNotify
        /* Timeout Notification part*/

        NULL_PTR,
        #endif /* COM_RxIPduTimeoutNotify */

        #ifdef COM_RxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,              /* Rx IPdu notification callback */
        #endif

        8, /*Size in Bytes*/

        #ifdef COM_RxIPduTimeout

        0,        /* First time out value after IPDU group start */

        0,              /*CC requriment: Support Rx IPDU Timeout*/
        #endif /* #ifdef COM_RxIPduTimeout */

        6,                /*No Of Signals present in the IPDU*/
        #ifdef COM_RX_SIGNALGROUP

        0,           /*No of Signal Groups present in the IPDU*/
        #endif

        (Com_RxIntSignalIdType)ComSignal_Internal_VCU05_TrqDmpMax_VCU_05,   /*Index to First Signal within this Ipdu*/
         #ifdef COM_RX_SIGNALGROUP

        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif
#ifdef COM_SIGNALGATEWAY
        0,       /* Number of signals with gateway */
#endif /* #ifdef COM_SIGNALGATEWAY */
#ifdef COM_SIGNALGROUPGATEWAY
        0,   /* Number of signal groups with gateway */
#endif /* #ifdef COM_SIGNALGROUPGATEWAY */

        /*
        {
            Signal_Processing:1;  = IMMEDIATE
            Notify_Cbk:1;         = true
            IsGwIPdu:1;           = false
            Not_Used:5;
        } Com_RxIpduFlagType;
        */
        0x2                /*Reception Type*/

    },
    {   /*Ipdu: VCU_06_Can_Network_0_CANNODE_0*/
        

        Com_LocalBuf_VCU_06_Can_Network_0_CANNODE_0,              /*Pointer to the Local Ipdu Buffer*/
        
        #ifdef COM_RxSigUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signals with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigUpdateTimeout */
        #ifdef COM_RxSigGrpUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signal groups with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigGrpUpdateTimeout */

        #ifdef COM_RxIPduCallOuts
        /* Ipdu Callout */

        
        &Com_RxCallout_VCU_06_Can_Network_0_CANNODE_0,
        
        #endif

        #ifdef COM_RxIPduTimeoutNotify
        /* Timeout Notification part*/

        NULL_PTR,
        #endif /* COM_RxIPduTimeoutNotify */

        #ifdef COM_RxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,              /* Rx IPdu notification callback */
        #endif

        8, /*Size in Bytes*/

        #ifdef COM_RxIPduTimeout

        0,        /* First time out value after IPDU group start */

        0,              /*CC requriment: Support Rx IPDU Timeout*/
        #endif /* #ifdef COM_RxIPduTimeout */

        5,                /*No Of Signals present in the IPDU*/
        #ifdef COM_RX_SIGNALGROUP

        0,           /*No of Signal Groups present in the IPDU*/
        #endif

        (Com_RxIntSignalIdType)ComSignal_Internal_VCU06_VehGrad_VCU_06,   /*Index to First Signal within this Ipdu*/
         #ifdef COM_RX_SIGNALGROUP

        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif
#ifdef COM_SIGNALGATEWAY
        0,       /* Number of signals with gateway */
#endif /* #ifdef COM_SIGNALGATEWAY */
#ifdef COM_SIGNALGROUPGATEWAY
        0,   /* Number of signal groups with gateway */
#endif /* #ifdef COM_SIGNALGROUPGATEWAY */

        /*
        {
            Signal_Processing:1;  = IMMEDIATE
            Notify_Cbk:1;         = true
            IsGwIPdu:1;           = false
            Not_Used:5;
        } Com_RxIpduFlagType;
        */
        0x2                /*Reception Type*/

    },
    {   /*Ipdu: VCU_07_Mask_Can_Network_0_CANNODE_0*/
        

        Com_LocalBuf_VCU_07_Mask_Can_Network_0_CANNODE_0,              /*Pointer to the Local Ipdu Buffer*/
        
        #ifdef COM_RxSigUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signals with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigUpdateTimeout */
        #ifdef COM_RxSigGrpUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signal groups with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigGrpUpdateTimeout */

        #ifdef COM_RxIPduCallOuts
        /* Ipdu Callout */

        
        &Com_RxCallout_VCU_07_Mask_Can_Network_0_CANNODE_0,
        
        #endif

        #ifdef COM_RxIPduTimeoutNotify
        /* Timeout Notification part*/

        NULL_PTR,
        #endif /* COM_RxIPduTimeoutNotify */

        #ifdef COM_RxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,              /* Rx IPdu notification callback */
        #endif

        8, /*Size in Bytes*/

        #ifdef COM_RxIPduTimeout

        0,        /* First time out value after IPDU group start */

        0,              /*CC requriment: Support Rx IPDU Timeout*/
        #endif /* #ifdef COM_RxIPduTimeout */

        1,                /*No Of Signals present in the IPDU*/
        #ifdef COM_RX_SIGNALGROUP

        0,           /*No of Signal Groups present in the IPDU*/
        #endif

        (Com_RxIntSignalIdType)ComSignal_Internal_MaskData1_VCU_07_Mask,   /*Index to First Signal within this Ipdu*/
         #ifdef COM_RX_SIGNALGROUP

        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif
#ifdef COM_SIGNALGATEWAY
        0,       /* Number of signals with gateway */
#endif /* #ifdef COM_SIGNALGATEWAY */
#ifdef COM_SIGNALGROUPGATEWAY
        0,   /* Number of signal groups with gateway */
#endif /* #ifdef COM_SIGNALGROUPGATEWAY */

        /*
        {
            Signal_Processing:1;  = IMMEDIATE
            Notify_Cbk:1;         = false
            IsGwIPdu:1;           = false
            Not_Used:5;
        } Com_RxIpduFlagType;
        */
        0x0                /*Reception Type*/

    }
};

/* ------------------------------------------------------------------------ */
/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"

/* END: Rx IPDU Details  */



/* START: IPDU Group Details  */

/* ------------------------------------------------------------------------ */
/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"

CONST(Com_Prv_xIpduGrpInfoCfg_tst ,COM_CONST) Com_Prv_xIpduGrpCfg_acst[4] =
{           /* "Index of First IPdu"               "No of Ipdus" */
{   
    /*ComIPduGroup_FR */
    
    0,
    
    1
}
,{   
    /*ComIPduGroup_Rx */
    
    1,
    
    10
}
,{   
    /*ComIPduGroup_Sys */
    
    11,
    
    1
}
,{   
    /*ComIPduGroup_Tx */
    
    12,
    
    9
}

};

/* ------------------------------------------------------------------------ */
/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"

/* END: IPDU Group Details  */






/* Reference to Ipdus belonging to the Ipdu Groups */

/* ------------------------------------------------------------------------ */
/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"

CONST(Com_IpduIdType ,COM_CONST) Com_Prv_xIPduGrp_IpduRefCfg_au8[21] =
{

    /*ComIPduGroup_FR */

    (COM_NUM_RX_IPDU + (Com_IpduIdType)ComConf_ComIPdu_Internal_DIAG_01_Can_Network_1_CANNODE_0),
    /*ComIPduGroup_Rx */

    ComConf_ComIPdu_Internal_VCU_06_Can_Network_0_CANNODE_0,
    ComConf_ComIPdu_Internal_VCU_04_Can_Network_0_CANNODE_0,
    ComConf_ComIPdu_Internal_VCU_02_Can_Network_0_CANNODE_0,
    ComConf_ComIPdu_Internal_BMS_01_Can_Network_0_CANNODE_0,
    ComConf_ComIPdu_Internal_VCU_03_Can_Network_0_CANNODE_0,
    ComConf_ComIPdu_Internal_VCU_01_Can_Network_0_CANNODE_0,
    ComConf_ComIPdu_Internal_VCU_05_Can_Network_0_CANNODE_0,
    ComConf_ComIPdu_Internal_VCU_07_Mask_Can_Network_0_CANNODE_0,
    ComConf_ComIPdu_Internal_TOOL_01_Can_Network_1_CANNODE_0,
    ComConf_ComIPdu_Internal_SysBoot_Rx_Can_Network_1_CANNODE_0,
    /*ComIPduGroup_Sys */

    (COM_NUM_RX_IPDU + (Com_IpduIdType)ComConf_ComIPdu_Internal_SysBoot_Tx_Can_Network_1_CANNODE_0),
    /*ComIPduGroup_Tx */

    (COM_NUM_RX_IPDU + (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_09_Can_Network_0_CANNODE_0),
    (COM_NUM_RX_IPDU + (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_05_Can_Network_0_CANNODE_0),
    (COM_NUM_RX_IPDU + (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_01_Can_Network_0_CANNODE_0),
    (COM_NUM_RX_IPDU + (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_02_Can_Network_0_CANNODE_0),
    (COM_NUM_RX_IPDU + (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_06_Can_Network_0_CANNODE_0),
    (COM_NUM_RX_IPDU + (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_08_Can_Network_0_CANNODE_0),
    (COM_NUM_RX_IPDU + (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_03_Can_Network_0_CANNODE_0),
    (COM_NUM_RX_IPDU + (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_07_Can_Network_0_CANNODE_0),
    (COM_NUM_RX_IPDU + (Com_IpduIdType)ComConf_ComIPdu_Internal_PEB_04_Can_Network_0_CANNODE_0)
};

/* ------------------------------------------------------------------------ */
/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"


#if defined ( COM_TX_SIGNALGROUP_ARRAY )

/* Tx-SignalGroup Array are not configured */
# define Com_Prv_xTxSigGrpArrayCfg_acst      ( NULL_PTR )
#endif /* #if defined ( COM_TX_SIGNALGROUP_ARRAY ) */

#if defined ( COM_RX_SIGNALGROUP_ARRAY )
/* Rx-SignalGroup Array are not configured */
# define Com_Prv_xRxSigGrpArrayCfg_acst      ( NULL_PTR )
#endif /* #if defined ( COM_RX_SIGNALGROUP_ARRAY ) */

/* Start section for RAM variables */

/* START: I-PDU Buffers */

   /* Tx Ipdu buffers */

/* ------------------------------------------------------------------------ */
/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_POSTBUILD_8
#include "Com_MemMap.h"


        VAR(uint8,COM_VAR) Com_IpduBuf_DIAG_01_Can_Network_1_CANNODE_0[8] ;
    
        VAR(uint8,COM_VAR) Com_IpduBuf_PEB_01_Can_Network_0_CANNODE_0[8] ;
    
        VAR(uint8,COM_VAR) Com_IpduBuf_PEB_03_Can_Network_0_CANNODE_0[8] ;
    
        VAR(uint8,COM_VAR) Com_IpduBuf_PEB_04_Can_Network_0_CANNODE_0[8] ;
    
        VAR(uint8,COM_VAR) Com_IpduBuf_PEB_08_Can_Network_0_CANNODE_0[8] ;
    
        VAR(uint8,COM_VAR) Com_IpduBuf_PEB_09_Can_Network_0_CANNODE_0[8] ;
    
        VAR(uint8,COM_VAR) Com_IpduBuf_PEB_02_Can_Network_0_CANNODE_0[8] ;
    
        VAR(uint8,COM_VAR) Com_IpduBuf_PEB_05_Can_Network_0_CANNODE_0[8] ;
    
        VAR(uint8,COM_VAR) Com_IpduBuf_PEB_07_Can_Network_0_CANNODE_0[8] ;
    
        VAR(uint8,COM_VAR) Com_IpduBuf_SysBoot_Tx_Can_Network_1_CANNODE_0[8] ;
    
        VAR(uint8,COM_VAR) Com_IpduBuf_PEB_06_Can_Network_0_CANNODE_0[8] ;
    

/* ------------------------------------------------------------------------ */
/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_POSTBUILD_8
#include "Com_MemMap.h"


#ifdef COM_TXDOUBLEBUFFER

/* ------------------------------------------------------------------------ */
/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_POSTBUILD_8
#include "Com_MemMap.h"


        VAR(uint8,COM_VAR) Com_LocalBuf_DIAG_01_Can_Network_1_CANNODE_0[8] ;
    
        VAR(uint8,COM_VAR) Com_LocalBuf_PEB_01_Can_Network_0_CANNODE_0[8] ;
    
        VAR(uint8,COM_VAR) Com_LocalBuf_PEB_03_Can_Network_0_CANNODE_0[8] ;
    
        VAR(uint8,COM_VAR) Com_LocalBuf_PEB_04_Can_Network_0_CANNODE_0[8] ;
    
        VAR(uint8,COM_VAR) Com_LocalBuf_PEB_08_Can_Network_0_CANNODE_0[8] ;
    
        VAR(uint8,COM_VAR) Com_LocalBuf_PEB_09_Can_Network_0_CANNODE_0[8] ;
    
        VAR(uint8,COM_VAR) Com_LocalBuf_PEB_02_Can_Network_0_CANNODE_0[8] ;
    
        VAR(uint8,COM_VAR) Com_LocalBuf_PEB_05_Can_Network_0_CANNODE_0[8] ;
    
        VAR(uint8,COM_VAR) Com_LocalBuf_PEB_07_Can_Network_0_CANNODE_0[8] ;
    
        VAR(uint8,COM_VAR) Com_LocalBuf_SysBoot_Tx_Can_Network_1_CANNODE_0[8] ;
    
        VAR(uint8,COM_VAR) Com_LocalBuf_PEB_06_Can_Network_0_CANNODE_0[8] ;
    

/* ------------------------------------------------------------------------ */
/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_POSTBUILD_8
#include "Com_MemMap.h"

#endif /*COM_TXDOUBLEBUFFER */

    /* Rx Ipdu Local Buffers */

/* ------------------------------------------------------------------------ */
/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_POSTBUILD_8
#include "Com_MemMap.h"

    
        VAR(uint8,COM_VAR) Com_LocalBuf_BMS_01_Can_Network_0_CANNODE_0[8] ;
    
        VAR(uint8,COM_VAR) Com_LocalBuf_SysBoot_Rx_Can_Network_1_CANNODE_0[8] ;
    
        VAR(uint8,COM_VAR) Com_LocalBuf_TOOL_01_Can_Network_1_CANNODE_0[8] ;
    
        VAR(uint8,COM_VAR) Com_LocalBuf_VCU_01_Can_Network_0_CANNODE_0[8] ;
    
        VAR(uint8,COM_VAR) Com_LocalBuf_VCU_02_Can_Network_0_CANNODE_0[8] ;
    
        VAR(uint8,COM_VAR) Com_LocalBuf_VCU_03_Can_Network_0_CANNODE_0[8] ;
    
        VAR(uint8,COM_VAR) Com_LocalBuf_VCU_04_Can_Network_0_CANNODE_0[8] ;
    
        VAR(uint8,COM_VAR) Com_LocalBuf_VCU_05_Can_Network_0_CANNODE_0[8] ;
    
        VAR(uint8,COM_VAR) Com_LocalBuf_VCU_06_Can_Network_0_CANNODE_0[8] ;
    
        VAR(uint8,COM_VAR) Com_LocalBuf_VCU_07_Mask_Can_Network_0_CANNODE_0[8] ;
    

/* ------------------------------------------------------------------------ */
/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_POSTBUILD_8
#include "Com_MemMap.h"

/* END: I-PDU Buffers */

#ifdef COM_F_MASKEDNEWDIFFERSOLD

/* ------------------------------------------------------------------------ */
/* Begin section for RAM variables of uint32 type */
#define COM_START_SEC_VAR_CLEARED_POSTBUILD_32
#include "Com_MemMap.h"
VAR(uint32,COM_VAR) Com_F_OldVal[1];

/* ------------------------------------------------------------------------ */
/* End section for RAM variables of uint32 type */
#define COM_STOP_SEC_VAR_CLEARED_POSTBUILD_32
#include "Com_MemMap.h"
#endif /* #ifdef COM_F_MASKEDNEWDIFFERSOLD */

#if defined(COM_SigTriggeredOnChange) || defined(COM_SigGrpTriggeredOnChange)

/* ------------------------------------------------------------------------ */
/* Begin section for RAM variables of struct/enum/pointer type */
#define COM_START_SEC_VAR_CLEARED_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"
VAR(Com_OldValTrigOnChngType,COM_VAR) Com_OldValTrigOnChng[1];

/* ------------------------------------------------------------------------ */
/* End section for RAM variables of struct/enum/pointer type */
#define COM_STOP_SEC_VAR_CLEARED_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"
#endif /* #if defined(COM_SigTriggeredOnChange) || defined(COM_SigGrpTriggeredOnChange) */

#ifdef COM_F_ONEEVERYN

/* ------------------------------------------------------------------------ */
/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"
CONST(Com_OneEveryNType,COM_CONST) Com_OneEveryN_Const[1] =
{
    /* Period   Offset  Occurence*/


{    1,    5, 1    }    /*  DummyForMisra    */
};

/* ------------------------------------------------------------------------ */
/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"


/* ------------------------------------------------------------------------ */
/* Begin section for RAM variables of struct/enum/pointer type */
#define COM_START_SEC_VAR_CLEARED_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"
VAR(Com_OneEveryNType,COM_VAR) Com_OneEveryN[1];

/* ------------------------------------------------------------------------ */
/* End section for RAM variables of struct/enum/pointer type */
#define COM_STOP_SEC_VAR_CLEARED_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"
#endif /* #ifdef COM_F_ONEEVERYN */


/* Signal Buffers */
/* Type: UINT8, SINT8, UINT8_N, BOOLEAN */

/* ------------------------------------------------------------------------ */
/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_POSTBUILD_8
#include "Com_MemMap.h"


VAR(uint8,COM_VAR) Com_SigType_u8[31];


/* ------------------------------------------------------------------------ */
/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_POSTBUILD_8
#include "Com_MemMap.h"



/* Type: UINT16, SINT16 */

/* ------------------------------------------------------------------------ */
/* Begin section for RAM variables of uint16 type */
#define COM_START_SEC_VAR_CLEARED_POSTBUILD_16
#include "Com_MemMap.h"


VAR(uint16,COM_VAR) Com_SigType_u16[19];


/* ------------------------------------------------------------------------ */
/* End section for RAM variables of uint16 type */
#define COM_STOP_SEC_VAR_CLEARED_POSTBUILD_16
#include "Com_MemMap.h"


/* Type: UINT32, SINT32 */

/* ------------------------------------------------------------------------ */
/* Begin section for RAM variables of uint32 type */
#define COM_START_SEC_VAR_CLEARED_POSTBUILD_32
#include "Com_MemMap.h"


VAR(uint32,COM_VAR) Com_SigType_u32[1];


/* ------------------------------------------------------------------------ */
/* End section for RAM variables of uint32 type */
#define COM_STOP_SEC_VAR_CLEARED_POSTBUILD_32
#include "Com_MemMap.h"


/* Type: UINT64, SINT64 */
#ifdef COM_RXSIG_INT64

/* ------------------------------------------------------------------------ */
/* Begin section for RAM variables of uint64 type */
#define COM_START_SEC_VAR_CLEARED_POSTBUILD_64
#include "Com_MemMap.h"


VAR(uint64,COM_VAR) Com_SigType_u64[1];


/* ------------------------------------------------------------------------ */
/* End section for RAM variables of uint64 type */
#define COM_STOP_SEC_VAR_CLEARED_POSTBUILD_64
#include "Com_MemMap.h"

#endif /* #ifdef COM_RXSIG_INT64 */






#ifdef COM_RX_SIGNALGROUP
/* Rx Group Signal Buffers */
/* Type: UINT8, SINT8, UINT8_N, BOOLEAN */

/* ------------------------------------------------------------------------ */
/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_POSTBUILD_8
#include "Com_MemMap.h"


VAR(uint8,COM_VAR) Com_RxGrpSigType_u8[1];


/* ------------------------------------------------------------------------ */
/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_POSTBUILD_8
#include "Com_MemMap.h"


/* Type: UINT16, SINT16 */

/* ------------------------------------------------------------------------ */
/* Begin section for RAM variables of uint16 type */
#define COM_START_SEC_VAR_CLEARED_POSTBUILD_16
#include "Com_MemMap.h"


VAR(uint16,COM_VAR) Com_RxGrpSigType_u16[1];


/* ------------------------------------------------------------------------ */
/* End section for RAM variables of uint16 type */
#define COM_STOP_SEC_VAR_CLEARED_POSTBUILD_16
#include "Com_MemMap.h"


/* Type: UINT32, SINT32 */

/* ------------------------------------------------------------------------ */
/* Begin section for RAM variables of uint32 type */
#define COM_START_SEC_VAR_CLEARED_POSTBUILD_32
#include "Com_MemMap.h"


VAR(uint32,COM_VAR) Com_RxGrpSigType_u32[1];


/* ------------------------------------------------------------------------ */
/* End section for RAM variables of uint32 type */
#define COM_STOP_SEC_VAR_CLEARED_POSTBUILD_32
#include "Com_MemMap.h"


/* Type: UINT64, SINT64 */
#ifdef COM_RXGRPSIG_INT64

/* ------------------------------------------------------------------------ */
/* Begin section for RAM variables of uint64 type */
#define COM_START_SEC_VAR_CLEARED_POSTBUILD_64
#include "Com_MemMap.h"


VAR(uint64,COM_VAR) Com_RxGrpSigType_u64[1];


/* ------------------------------------------------------------------------ */
/* End section for RAM variables of uint64 type */
#define COM_STOP_SEC_VAR_CLEARED_POSTBUILD_64
#include "Com_MemMap.h"

#endif /* #ifdef COM_RXGRPSIG_INT64 */




/* The function Com_ReceiveSignalGroup() is not interrupt safe, hence there is need to
 * to generate second buffer for all the group signals
 */
/* Type: UINT8, SINT8, UINT8_N, BOOLEAN */

/* ------------------------------------------------------------------------ */
/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_POSTBUILD_8
#include "Com_MemMap.h"

VAR(uint8,COM_VAR) Com_SecondRxGrpSigType_u8[1];

/* ------------------------------------------------------------------------ */
/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_POSTBUILD_8
#include "Com_MemMap.h"


/* Type: UINT16, SINT16 */

/* ------------------------------------------------------------------------ */
/* Begin section for RAM variables of uint16 type */
#define COM_START_SEC_VAR_CLEARED_POSTBUILD_16
#include "Com_MemMap.h"

VAR(uint16,COM_VAR) Com_SecondRxGrpSigType_u16[1];

/* ------------------------------------------------------------------------ */
/* End section for RAM variables of uint16 type */
#define COM_STOP_SEC_VAR_CLEARED_POSTBUILD_16
#include "Com_MemMap.h"


/* Type: UINT32, SINT32 */

/* ------------------------------------------------------------------------ */
/* Begin section for RAM variables of uint32 type */
#define COM_START_SEC_VAR_CLEARED_POSTBUILD_32
#include "Com_MemMap.h"

VAR(uint32,COM_VAR) Com_SecondRxGrpSigType_u32[1];

/* ------------------------------------------------------------------------ */
/* End section for RAM variables of uint32 type */
#define COM_STOP_SEC_VAR_CLEARED_POSTBUILD_32
#include "Com_MemMap.h"


/* Type: UINT64, SINT64 */
#ifdef COM_RXGRPSIG_INT64

/* ------------------------------------------------------------------------ */
/* Begin section for RAM variables of uint64 type */
#define COM_START_SEC_VAR_CLEARED_POSTBUILD_64
#include "Com_MemMap.h"

VAR(uint64,COM_VAR) Com_SecondRxGrpSigType_u64[1];

/* ------------------------------------------------------------------------ */
/* End section for RAM variables of uint64 type */
#define COM_STOP_SEC_VAR_CLEARED_POSTBUILD_64
#include "Com_MemMap.h"

#endif /* #ifdef COM_RXGRPSIG_INT64 */





#ifdef COM_RX_SIGNALGROUP_ARRAY

#define Com_RxSigGrpArrayBuf_u8     ( NULL_PTR )
#endif /* #ifdef COM_RX_SIGNALGROUP_ARRAY */

#endif /* #ifdef COM_RX_SIGNALGROUP */


#ifdef COM_TX_SIGNALGROUP
/* Tx Group Signal Buffers  */
/* Type: UINT8, SINT8, UINT8_N, BOOLEAN */

/* ------------------------------------------------------------------------ */
/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_POSTBUILD_8
#include "Com_MemMap.h"

VAR(uint8,COM_VAR) Com_TxGrpSigType_u8[1];

/* ------------------------------------------------------------------------ */
/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_POSTBUILD_8
#include "Com_MemMap.h"


/* Type: UINT16, SINT16 */

/* ------------------------------------------------------------------------ */
/* Begin section for RAM variables of uint16 type */
#define COM_START_SEC_VAR_CLEARED_POSTBUILD_16
#include "Com_MemMap.h"

VAR(uint16,COM_VAR) Com_TxGrpSigType_u16[1];

/* ------------------------------------------------------------------------ */
/* End section for RAM variables of uint16 type */
#define COM_STOP_SEC_VAR_CLEARED_POSTBUILD_16
#include "Com_MemMap.h"


/* Type: UINT32, SINT32 */

/* ------------------------------------------------------------------------ */
/* Begin section for RAM variables of uint32 type */
#define COM_START_SEC_VAR_CLEARED_POSTBUILD_32
#include "Com_MemMap.h"

VAR(uint32,COM_VAR) Com_TxGrpSigType_u32[1];

/* ------------------------------------------------------------------------ */
/* End section for RAM variables of uint32 type */
#define COM_STOP_SEC_VAR_CLEARED_POSTBUILD_32
#include "Com_MemMap.h"


/* Type: UINT64, SINT64 */
#ifdef COM_TXGRPSIG_INT64

/* ------------------------------------------------------------------------ */
/* Begin section for RAM variables of uint64 type */
#define COM_START_SEC_VAR_CLEARED_POSTBUILD_64
#include "Com_MemMap.h"

VAR(uint64,COM_VAR) Com_TxGrpSigType_u64[1];

/* ------------------------------------------------------------------------ */
/* End section for RAM variables of uint64 type */
#define COM_STOP_SEC_VAR_CLEARED_POSTBUILD_64
#include "Com_MemMap.h"

#endif /* #ifdef COM_TXGRPSIG_INT64 */



#endif /* #ifdef COM_TX_SIGNALGROUP */


/* ------------------------------------------------------------------------ */
/* Begin section for RAM variables of struct/enum/pointer type */
#define COM_START_SEC_VAR_CLEARED_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"

VAR(PduInfoType,COM_VAR)            Com_PduInfo_s[COM_NUM_TX_IPDU];

VAR(Com_TxIpduRamData,COM_VAR)      Com_TxIpduRam_s[COM_NUM_TX_IPDU];

VAR(Com_RxIpduRamData,COM_VAR)      Com_RxIpduRam_s[COM_NUM_RX_IPDU];

VAR(Com_TxSignalFlagType,COM_VAR)   Com_TxSignalFlag[COM_NUM_TX_SIGNALS];

VAR(Com_RxSignalFlagType,COM_VAR)   Com_RxSignalFlag[COM_NUM_RX_SIGNALS];

/* ------------------------------------------------------------------------ */
/* End section for RAM variables of struct/enum/pointer type */
#define COM_STOP_SEC_VAR_CLEARED_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"


/* ------------------------------------------------------------------------ */
/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_POSTBUILD_8
#include "Com_MemMap.h"

VAR(uint8,COM_VAR)    Com_IpduCounter_s[COM_NUM_TX_IPDU + COM_NUM_RX_IPDU];

VAR(uint8,COM_VAR)    Com_IpduCounter_DM[COM_NUM_RX_IPDU];

/* ------------------------------------------------------------------------ */
/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_POSTBUILD_8
#include "Com_MemMap.h"


#if defined (COM_SIGNALGATEWAY) || defined (COM_SIGNALGROUPGATEWAY)

/* ------------------------------------------------------------------------ */
/* Begin section for RAM variables of struct/enum/pointer type */
#define COM_START_SEC_VAR_CLEARED_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"
VAR(PduIdType,COM_VAR)    Com_RxGwQueue_aux[COM_NUM_GWSRC_IPDUS+1u];

VAR(Com_RxGwQueueRAMType,COM_VAR)   Com_RxGwQueue_S;

/* ------------------------------------------------------------------------ */
/* End section for RAM variables of struct/enum/pointer type */
#define COM_STOP_SEC_VAR_CLEARED_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"
#endif /* #if defined (COM_SIGNALGATEWAY) || defined (COM_SIGNALGROUPGATEWAY) */


#ifdef COM_RX_SIGNALGROUP

/* ------------------------------------------------------------------------ */
/* Begin section for RAM variables of struct/enum/pointer type */
#define COM_START_SEC_VAR_CLEARED_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"
VAR(Com_RxSignalGrpFlagType,COM_VAR) Com_RxSignalGrpFlag[1u];

/* ------------------------------------------------------------------------ */
/* End section for RAM variables of struct/enum/pointer type */
#define COM_STOP_SEC_VAR_CLEARED_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"
#endif

#ifdef COM_TX_SIGNALGROUP
#if defined (COM_SigGrpTriggeredOnChange) || defined (COM_SIGNALGROUPGATEWAY)

/* ------------------------------------------------------------------------ */
/* Begin section for RAM variables of struct/enum/pointer type */
#define COM_START_SEC_VAR_CLEARED_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"
VAR(Com_TxSignalGrpFlagType,COM_VAR) Com_TxSignalGrpFlag[1u];

/* ------------------------------------------------------------------------ */
/* End section for RAM variables of struct/enum/pointer type */
#define COM_STOP_SEC_VAR_CLEARED_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"
#endif /* #if defined (COM_SigGrpTriggeredOnChange) || defined (COM_SIGNALGROUPGATEWAY) */


/* ------------------------------------------------------------------------ */
/* Begin section for RAM variables of struct/enum/pointer type */
#define COM_START_SEC_VAR_CLEARED_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"
VAR(Com_TxGrpSignalFlagType,COM_VAR) Com_TxGrpSignalFlag[1u];

/* ------------------------------------------------------------------------ */
/* End section for RAM variables of struct/enum/pointer type */
#define COM_STOP_SEC_VAR_CLEARED_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"
#endif


#ifdef COM_RxIPduDeferredProcessing

/* ------------------------------------------------------------------------ */
/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_POSTBUILD_8
#include "Com_MemMap.h"

    /* Buffer to hold data for deferred signal processing */
    VAR(uint8,COM_VAR) Com_DeferredBuffer[COM_MAX_DEFERRED_IPDUBUFF_SIZE];

/* ------------------------------------------------------------------------ */
/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_POSTBUILD_8
#include "Com_MemMap.h"

#endif /* #ifdef COM_RxIPduDeferredProcessing */

#if defined (COM_SIGNALGATEWAY) || defined (COM_SIGNALGROUPGATEWAY)

/* ------------------------------------------------------------------------ */
/* Begin section for RAM variables of uint16 type */
#define COM_START_SEC_VAR_CLEARED_POSTBUILD_16
#include "Com_MemMap.h"

    VAR(uint16, AUTOMATIC) Com_NumOfGwSignalsUpdated_au16[ COM_NUM_GWSRC_IPDUS ];

/* ------------------------------------------------------------------------ */
/* End section for RAM variables of uint16 type */
#define COM_STOP_SEC_VAR_CLEARED_POSTBUILD_16
#include "Com_MemMap.h"

#endif /* #if defined (COM_SIGNALGATEWAY) || defined (COM_SIGNALGROUPGATEWAY) */

/* End section for RAM variables */


#if defined (COM_F_MASKEDNEWEQUALSX ) || defined(COM_F_MASKEDNEWDIFFERSX)

/* ------------------------------------------------------------------------ */
/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"

CONST(Com_MaskXType ,COM_CONST) Com_MaskX[1] =
{
    /*Mask       X*/



{    1,    5    }    /*  DummyForMisra    */
};

/* ------------------------------------------------------------------------ */
/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"


#endif /* #if defined (COM_F_MASKEDNEWEQUALSX ) || defined(COM_F_MASKEDNEWDIFFERSX) */


#ifdef COM_F_MASKEDNEWDIFFERSOLD

/* ------------------------------------------------------------------------ */
/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_POSTBUILD_32
#include "Com_MemMap.h"

CONST(uint32 ,COM_CONST) Com_Mask[1] =
{
    /*Mask*/
    1    /* DummyForMisra */
};

/* ------------------------------------------------------------------------ */
/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_POSTBUILD_32
#include "Com_MemMap.h"

#endif /* #ifdef COM_F_MASKEDNEWDIFFERSOLD */


#if defined (COM_F_NEWISWITHIN_POS) || defined(COM_F_NEWISOUTSIDE_POS)

/* ------------------------------------------------------------------------ */
/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"

CONST(Com_POSMinMaxType ,COM_CONST) Com_POSMinMax[1]=
{
    /*  Min      Max */





{    1,    5    }    /*  DummyForMisra    */


};


/* ------------------------------------------------------------------------ */
/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"

#endif /* #if defined (COM_F_NEWISWITHIN_POS) || defined(COM_F_NEWISOUTSIDE_POS) */


#if defined (COM_F_NEWISWITHIN_NEG) || defined(COM_F_NEWISOUTSIDE_NEG)

/* ------------------------------------------------------------------------ */
/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"

CONST(Com_NEGMinMaxType ,COM_CONST) Com_NEGMinMax[1] =
{
    /*  Min      Max */


{    1,    5    }    /*  DummyForMisra    */
};

/* ------------------------------------------------------------------------ */
/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"

#endif /* #if defined (COM_F_NEWISWITHIN_NEG) || defined(COM_F_NEWISOUTSIDE_NEG) */


