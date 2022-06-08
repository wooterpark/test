/*
***********************************************************************************************************************
* 
* Product Info
* Isolar version: ISOLAR-AB 4.0.2
* Product release version: RTA-BSW 3.1.0
* 
***********************************************************************************************************************
*/



#include "Dcm.h"
#include "Rte_Dcm.h"

#include "DcmDspUds_Uds_Prot.h"

#include "SchM_Dcm.h"

#include "NvM.h"
#include "ComM_Dcm.h"

#include "DcmDspUds_Rc_Prot.h"


#include "DcmDspUds_Rdtc_Priv.h"

#include "DcmDspUds_Er_Prot.h"



#include "DcmDspUds_Cdtcs_Prot.h"







/**
 ***************************************************************************************************
            Session Control (DSC) Service
 ***************************************************************************************************
*/
/* Initialization of the parameters for the supported sessions */
#define DCM_START_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
CONST(Dcm_Dsp_Session_t, DCM_CONST) Dcm_Dsp_Session[DCM_CFG_DSP_NUMSESSIONS] =
{

   /* session configuration for DEFAULT_SESSION*/
   {
		50000,				/* P2 Max time in us */
		4000000,				/* P2* Max time in us */
		0x1,				/* Session ID */
		RTE_MODE_DcmDiagnosticSessionControl_DEFAULT_SESSION, /* DcmDiagnosticSessionControl Mode  for the Session Level */
		DCM_NO_BOOT			/* Diagnostic session used for jump to Bootloader */
	},

   /* session configuration for PROGRAMMING_SESSION*/
   {
		50000,				/* P2 Max time in us */
		4000000,				/* P2* Max time in us */
		0x2,				/* Session ID */
		RTE_MODE_DcmDiagnosticSessionControl_PROGRAMMING_SESSION, /* DcmDiagnosticSessionControl Mode  for the Session Level */
		DCM_OEM_BOOT			/* Diagnostic session used for jump to Bootloader */
	},

   /* session configuration for EXTENDED_DIAGNOSTIC_SESSION*/
   {
		50000,				/* P2 Max time in us */
		4000000,				/* P2* Max time in us */
		0x3,				/* Session ID */
		RTE_MODE_DcmDiagnosticSessionControl_EXTENDED_DIAGNOSTIC_SESSION, /* DcmDiagnosticSessionControl Mode  for the Session Level */
		DCM_NO_BOOT			/* Diagnostic session used for jump to Bootloader */
	},

   /* session configuration for CODING_SESSION*/
   {
		50000,				/* P2 Max time in us */
		4000000,				/* P2* Max time in us */
		0x41,				/* Session ID */
		RTE_MODE_DcmDiagnosticSessionControl_CODING_SESSION, /* DcmDiagnosticSessionControl Mode  for the Session Level */
		DCM_NO_BOOT			/* Diagnostic session used for jump to Bootloader */
	}
};
#define DCM_STOP_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"



/**
 ***************************************************************************************************
            Security Access (SECA) Service
 ***************************************************************************************************
*/
/* Initialization of the parameters for the supported security */
#define DCM_START_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
CONST(Dcm_Dsp_Security_t, DCM_CONST) Dcm_Dsp_Security[DCM_CFG_DSP_NUMSECURITY] =
{
   /* security configuration for DSP_SEC_LEV_L1*/
   {
   
		10000,			/* Delay timer on Power On in DcmTaskTime Counts*/

		10000,			/* Delay time after failed security access in DcmTaskTime Counts */

		/* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
		(void*)	&Rte_Call_SecurityAccess_DSP_SEC_LEV_L1_GetSeed, /* RTE Port for the GetSeed Function */
		/* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
		(void*) &Rte_Call_SecurityAccess_DSP_SEC_LEV_L1_CompareKey, /* RTE Port for the Compare Key Function */
		0x1, 		/* Security Level */
		16,			/* Security Seed size */
		16,			/* Security Key size */
		3,			/* Number of failed security access after which delay time is active */
		5,			/* Number of failed security access after which security is locked */
		0,			/* Size of the Access Data Record in Seed Request */
		USE_ASYNCH_CLIENT_SERVER			}
,
   /* security configuration for DSP_SEC_LEV_L2*/
   {
   
		10000,			/* Delay timer on Power On in DcmTaskTime Counts*/

		10000,			/* Delay time after failed security access in DcmTaskTime Counts */

		/* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
		(void*)	&Rte_Call_SecurityAccess_DSP_SEC_LEV_L2_GetSeed, /* RTE Port for the GetSeed Function */
		/* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
		(void*) &Rte_Call_SecurityAccess_DSP_SEC_LEV_L2_CompareKey, /* RTE Port for the Compare Key Function */
		0x2, 		/* Security Level */
		16,			/* Security Seed size */
		16,			/* Security Key size */
		3,			/* Number of failed security access after which delay time is active */
		5,			/* Number of failed security access after which security is locked */
		0,			/* Size of the Access Data Record in Seed Request */
		USE_ASYNCH_CLIENT_SERVER			}
,
   /* security configuration for DSP_SEC_LEV_L3*/
   {
   
		10000,			/* Delay timer on Power On in DcmTaskTime Counts*/

		10000,			/* Delay time after failed security access in DcmTaskTime Counts */

		/* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
		(void*)	&Rte_Call_SecurityAccess_DSP_SEC_LEV_L3_GetSeed, /* RTE Port for the GetSeed Function */
		/* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
		(void*) &Rte_Call_SecurityAccess_DSP_SEC_LEV_L3_CompareKey, /* RTE Port for the Compare Key Function */
		0x3, 		/* Security Level */
		16,			/* Security Seed size */
		16,			/* Security Key size */
		3,			/* Number of failed security access after which delay time is active */
		5,			/* Number of failed security access after which security is locked */
		0,			/* Size of the Access Data Record in Seed Request */
		USE_ASYNCH_CLIENT_SERVER			}
,
   /* security configuration for DSP_SEC_LEV_L4*/
   {
   
		10000,			/* Delay timer on Power On in DcmTaskTime Counts*/

		10000,			/* Delay time after failed security access in DcmTaskTime Counts */

		/* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
		(void*)	&Rte_Call_SecurityAccess_DSP_SEC_LEV_L4_GetSeed, /* RTE Port for the GetSeed Function */
		/* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
		(void*) &Rte_Call_SecurityAccess_DSP_SEC_LEV_L4_CompareKey, /* RTE Port for the Compare Key Function */
		0x4, 		/* Security Level */
		16,			/* Security Seed size */
		16,			/* Security Key size */
		3,			/* Number of failed security access after which delay time is active */
		5,			/* Number of failed security access after which security is locked */
		0,			/* Size of the Access Data Record in Seed Request */
		USE_ASYNCH_CLIENT_SERVER			}

};
#define DCM_STOP_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"















/**
 ***************************************************************************************************
            Routine control (RC) service - start
 ***************************************************************************************************
 */

#if (DCM_CFG_DSP_ROUTINECONTROL_ENABLED != DCM_CFG_OFF)




#define DCM_START_SEC_VAR_CLEARED_16 /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
VAR(sint16,DCM_VAR)              Dcm_RCSigOutN_as16[1];
#define DCM_STOP_SEC_VAR_CLEARED_16 /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"




#define DCM_START_SEC_VAR_CLEARED_32 /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
VAR(sint32,DCM_VAR)              Dcm_RCSigOutN_as32[1];
#define DCM_STOP_SEC_VAR_CLEARED_32 /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"



#define DCM_START_SEC_VAR_CLEARED_8 /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
VAR(sint8,DCM_VAR)               Dcm_RCSigOutN_as8[1];
#define DCM_STOP_SEC_VAR_CLEARED_8 /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"


typedef enum
{
    DcmDspRoutine_Test_DcmDspStopRoutineOutSignal_0_StpOut,
    DcmDspRoutine_Test_DcmDspRequestRoutineResultsOutSignal_0_ReqRsltOut,
    DcmDspRoutine_CheckPgmPreCond_DcmDspRequestRoutineResultsOutSignal_0_ReqRsltOut,
    DCM_RC_SIGOUTUINT32MAX
} Dcm_DspRoutineSigOutUInt32Idx_ten;

#define DCM_START_SEC_VAR_CLEARED_32 /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
static VAR(uint32,DCM_VAR)              Dcm_RCSigOut_au32[3];
#define DCM_STOP_SEC_VAR_CLEARED_32 /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"


#define DCM_START_SEC_VAR_CLEARED_32 /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
VAR(uint32,DCM_VAR)              Dcm_RCSigOutN_au32[1];
#define DCM_STOP_SEC_VAR_CLEARED_32 /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"

typedef enum
{
    DcmDspRoutine_CheckPgmPreCond_DcmDspStopRoutineOutSignal_0_StpOut,
    DCM_RC_SIGOUTUINT16MAX
} Dcm_DspRoutineSigOutUInt16Idx_ten;

#define DCM_START_SEC_VAR_CLEARED_16 /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
static VAR(uint16,DCM_VAR)              Dcm_RCSigOut_au16[1];
#define DCM_STOP_SEC_VAR_CLEARED_16 /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_16 /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
VAR(uint16,DCM_VAR)              Dcm_RCSigOutN_au16[1];
#define DCM_STOP_SEC_VAR_CLEARED_16 /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"


typedef enum
{
    DcmDspRoutine_CheckPgmPreCond_DcmDspStartRoutineOutSignal_ES_StrtOut,
    DcmDspRoutine_CheckPgmPreCond_DcmDspStartRoutineOutSignal_VS_StrtOut,
    DcmDspRoutine_CheckPgmPreCond_DcmDspStartRoutineOutSignal_IC_StrtOut,
    DcmDspRoutine_CheckPgmPreCond_DcmDspStartRoutineOutSignal_VC_StrtOut,
    DCM_RC_SIGOUTUINT8MAX
} Dcm_DspRoutineSigOutUInt8Idx_ten;

#define DCM_START_SEC_VAR_CLEARED_8 /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
static VAR(uint8,DCM_VAR)               Dcm_RCSigOut_au8[4];
#define DCM_STOP_SEC_VAR_CLEARED_8 /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_8 /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
VAR(uint8,DCM_VAR)               Dcm_RCSigOutN_au8[1];
#define DCM_STOP_SEC_VAR_CLEARED_8 /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"






#define DCM_START_SEC_VAR_CLEARED_16 /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
VAR(sint16,DCM_VAR)              Dcm_RCSigInN_as16[1];
#define DCM_STOP_SEC_VAR_CLEARED_16 /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"



#define DCM_START_SEC_VAR_CLEARED_32 /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
VAR(sint32,DCM_VAR)              Dcm_RCSigInN_as32[1];
#define DCM_STOP_SEC_VAR_CLEARED_32 /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"


#define DCM_START_SEC_VAR_CLEARED_8 /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
VAR(sint8,DCM_VAR)               Dcm_RCSigInN_as8[1];
#define DCM_STOP_SEC_VAR_CLEARED_8 /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"


#define DCM_START_SEC_VAR_CLEARED_32/*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
VAR(uint32,DCM_VAR)              Dcm_RCSigInN_au32[1];
#define DCM_STOP_SEC_VAR_CLEARED_32 /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"

typedef enum
{
    DcmDspRoutine_Test_DcmDspStopRoutineInSignal_0_StpIn,
    DcmDspRoutine_CheckPgmPreCond_DcmDspStopRoutineInSignal_0_StpIn,
    DCM_RC_SIGINUINT16MAX
} Dcm_DspRoutineSigInUInt16Idx_ten;

#define DCM_START_SEC_VAR_CLEARED_16 /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
static VAR(uint16,DCM_VAR)              Dcm_RCSigIn_au16[2];
#define DCM_STOP_SEC_VAR_CLEARED_16 /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"


#define DCM_START_SEC_VAR_CLEARED_16 /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
VAR(uint16,DCM_VAR)              Dcm_RCSigInN_au16[1];
#define DCM_STOP_SEC_VAR_CLEARED_16 /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"



#define DCM_START_SEC_VAR_CLEARED_8 /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
VAR(uint8,DCM_VAR)               Dcm_RCSigInN_au8[1];
#define DCM_STOP_SEC_VAR_CLEARED_8/*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"

#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"

FUNC(uint32,DCM_CODE) Dcm_RCGetSigVal_u32 ( VAR(uint8,AUTOMATIC) dataSigType_en, VAR(uint16,AUTOMATIC) idxSignalIndex_u16 )
{
    VAR(uint32,AUTOMATIC)       dataSigVal_u32;

    dataSigVal_u32 = 0;
   
    switch (dataSigType_en)
    {
    case DCM_UINT16:
        dataSigVal_u32 = (uint32)Dcm_RCSigOut_au16[idxSignalIndex_u16];
        break;
    case DCM_UINT32:
        dataSigVal_u32 = Dcm_RCSigOut_au32[idxSignalIndex_u16];
        break;
    case DCM_UINT8:
        dataSigVal_u32 = (uint32)Dcm_RCSigOut_au8[idxSignalIndex_u16];
        break;
/*MR12 RULE 16.6 VIOLATION: This 'switch' statement contains only a single path - it is redundant. MISRA C:2012 Rule-16.6*/
    default:
        (void)idxSignalIndex_u16;
        break;
    }
    return (dataSigVal_u32);
}


FUNC(void,DCM_CODE) Dcm_RCSetSigVal ( VAR(uint8,AUTOMATIC) dataSigType_en, VAR(uint16,AUTOMATIC) idxSignalIndex_u16, VAR(uint32,AUTOMATIC) dataSigVal_u32)
{

    switch (dataSigType_en)
    {
    case DCM_UINT16:
        Dcm_RCSigIn_au16[idxSignalIndex_u16]=(uint16)dataSigVal_u32;
        break;
/*MR12 RULE 16.6 VIOLATION: This 'switch' statement contains only a single path - it is redundant. MISRA C:2012 Rule-16.6*/
    default:
        (void)dataSigVal_u32;
        (void)idxSignalIndex_u16;
        break;
    }
}

#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"

#define DCM_START_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"

static CONST(Dcm_DspRoutineSignalInfo_tst, DCM_CONST) DcmDspRc_DcmDspRoutine_Test_StpInSig[]=
{
   {
        0,            /* Start bit position of the signal */    
        16,               /* length of the signal */    
        DcmDspRoutine_Test_DcmDspStopRoutineInSignal_0_StpIn,         /* Index of the signal */
        DCM_BIG_ENDIAN,       /* Signal Endianness is BIG_ENDIAN*/
         DCM_UINT16  /* Data Type is UINT16 */       
    }
};






static CONST(Dcm_DspRoutineSignalInfo_tst, DCM_CONST) DcmDspRc_DcmDspRoutine_Test_StopOutSig[]=
{
   {
        0,             /* Start bit position of the signal */
        32,               /* length of the signal */
        DcmDspRoutine_Test_DcmDspStopRoutineOutSignal_0_StpOut,            /* Index of the signal */
        DCM_BIG_ENDIAN,       /* Signal Endianness is BIG_ENDIAN*/
        DCM_UINT32  /* Data Type is UINT32 */   
    }
};

static CONST(Dcm_DspRoutineSignalInfo_tst, DCM_CONST) DcmDspRc_DcmDspRoutine_Test_ReqRsltOutSig[]=
{
    {
        0,             /* Start bit position of the signal */
        32,               /* length of the signal */
        DcmDspRoutine_Test_DcmDspRequestRoutineResultsOutSignal_0_ReqRsltOut,            /* Index of the signal */
        DCM_BIG_ENDIAN,       /* Signal Endianness is BIG_ENDIAN*/
        DCM_UINT32  /* Data Type is UINT32 */    
    }
};


static CONST(Dcm_DspRoutineSignalInfo_tst, DCM_CONST) DcmDspRc_DcmDspRoutine_CheckPgmPreCond_StpInSig[]=
{
   {
        0,            /* Start bit position of the signal */    
        16,               /* length of the signal */    
        DcmDspRoutine_CheckPgmPreCond_DcmDspStopRoutineInSignal_0_StpIn,         /* Index of the signal */
        DCM_BIG_ENDIAN,       /* Signal Endianness is BIG_ENDIAN*/
         DCM_UINT16  /* Data Type is UINT16 */       
    }
};




static CONST(Dcm_DspRoutineSignalInfo_tst, DCM_CONST) DcmDspRc_DcmDspRoutine_CheckPgmPreCond_StrtOutSig[]=
{
   {
        0,             /* Start bit position of the signal */
        8,               /* length of the signal */
	    DcmDspRoutine_CheckPgmPreCond_DcmDspStartRoutineOutSignal_ES_StrtOut,           /* Index of the signal */
	    DCM_BIG_ENDIAN,       /* Signal Endianness is BIG_ENDIAN*/
	   DCM_UINT8  /* Data Type is UINT8 */      
    }
,
   {
        8,             /* Start bit position of the signal */
        8,               /* length of the signal */
	    DcmDspRoutine_CheckPgmPreCond_DcmDspStartRoutineOutSignal_VS_StrtOut,           /* Index of the signal */
	    DCM_BIG_ENDIAN,       /* Signal Endianness is BIG_ENDIAN*/
	   DCM_UINT8  /* Data Type is UINT8 */      
    }
,
   {
        16,             /* Start bit position of the signal */
        8,               /* length of the signal */
	    DcmDspRoutine_CheckPgmPreCond_DcmDspStartRoutineOutSignal_IC_StrtOut,           /* Index of the signal */
	    DCM_BIG_ENDIAN,       /* Signal Endianness is BIG_ENDIAN*/
	   DCM_UINT8  /* Data Type is UINT8 */      
    }
,
   {
        24,             /* Start bit position of the signal */
        8,               /* length of the signal */
	    DcmDspRoutine_CheckPgmPreCond_DcmDspStartRoutineOutSignal_VC_StrtOut,           /* Index of the signal */
	    DCM_BIG_ENDIAN,       /* Signal Endianness is BIG_ENDIAN*/
	   DCM_UINT8  /* Data Type is UINT8 */      
    }
};


static CONST(Dcm_DspRoutineSignalInfo_tst, DCM_CONST) DcmDspRc_DcmDspRoutine_CheckPgmPreCond_StopOutSig[]=
{
   {
        0,             /* Start bit position of the signal */
        16,               /* length of the signal */
        DcmDspRoutine_CheckPgmPreCond_DcmDspStopRoutineOutSignal_0_StpOut,            /* Index of the signal */
        DCM_BIG_ENDIAN,       /* Signal Endianness is BIG_ENDIAN*/
        DCM_UINT16  /* Data Type is UINT16 */   
    }
};

static CONST(Dcm_DspRoutineSignalInfo_tst, DCM_CONST) DcmDspRc_DcmDspRoutine_CheckPgmPreCond_ReqRsltOutSig[]=
{
    {
        0,             /* Start bit position of the signal */
        32,               /* length of the signal */
        DcmDspRoutine_CheckPgmPreCond_DcmDspRequestRoutineResultsOutSignal_0_ReqRsltOut,            /* Index of the signal */
        DCM_BIG_ENDIAN,       /* Signal Endianness is BIG_ENDIAN*/
        DCM_UINT32  /* Data Type is UINT32 */    
    }
};



static CONST(Dcm_DspRoutineInfoType_tst, DCM_CONST) DcmDspRc_DcmDspRoutine_Test=
{
    /* Allowed Security Row Bit Mask for start routine*/
  0xFFFF,
  /* Allowed Security Row Bit Mask Stop Routine */
  0xFFFF,
  /* Allowed Security Row Bit Mask  Request Routine Results*/
  0xFFFF,

    /* Allowed Session Row Bit Mask for start routine */
  0xFFFF,
   /* Allowed Session Row Bit Mask  for stop routine */
  0xFFFF,
   /* Allowed Session Row Bit Mask request routine results */
  0xFFFF,
     NULL_PTR,       /*  No User defined Mode rule Function configured  */
    /*Reference to the routine control mode rule*/
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    /* Reference to In Signal from StartRoutine */
    NULL_PTR,
    /* Reference to In Signal from StopRoutine */
    DcmDspRc_DcmDspRoutine_Test_StpInSig,
/* Reference to In Signal from RequestResultRoutine */
    NULL_PTR,
    /* Reference to Out Signal from StartRoutine */
    NULL_PTR,
    /* Reference to Out Signal from StopRoutine */
    DcmDspRc_DcmDspRoutine_Test_StopOutSig,
    /* Reference to Out Signal from RequestResultsRoutine */
    DcmDspRc_DcmDspRoutine_Test_ReqRsltOutSig,
    /* (Maximum) Size of Control Option Record i.e. Optional Bytes in Request for Start Routine */
    0,
    /* (Maximum) Size of Control Option Record i.e. Optional Bytes in Request for Stop Routine */
    2,
/* (Maximum) Size of Control Option Record i.e. Optional Bytes in Request for RequestResults Routine */
    0,
    /* (Maximum) Size of Status Option Record i.e. Optional Bytes in Response for Request Start Routine */
    0,
    /* (Maximum) Size of Status Option Record i.e. Optional Bytes in Response for Request Stop Routine */
    4,
    /* (Maximum) Size of Status Option Record i.e. Optional Bytes in Response for RequestResults Routine */
    4,
    /* Minimum Size of Control Option Record i.e. Optional Bytes in Request for Start Routine */

    0,
    /* Minimum Size of Control Option Record i.e. Optional Bytes in Request for Stop Routine */
    2,
    /* Minimum Size of Control Option Record i.e. Optional Bytes in Request for RequestResult Routine */
    0,
    /* Minimum Size of Status Option Record i.e. Optional Bytes in Response for Request Start Routine */
    0,
    /* Minimum Size of Status Option Record i.e. Optional Bytes in Response for Request Stop Routine */
    4,
    /* Minimum Size of Status Option Record i.e. Optional Bytes in Response for Request RequestResults Routine */
    4,
    /* Number of In Signals configured for StartRoutine */
    0,
    /* Number of In Signals configured for StopRoutine */
    1,
/* Number of In Signals configured for ReqResultsRoutine */
    0,
    /* Number of Out Signals configured for StartRoutine */
    0,
    /* Number of Out Signals configured for StopRoutine */
    1,
    /* Number of Out Signals configured for RequestResultsRoutine */
    1
};


static CONST(Dcm_DspRoutineInfoType_tst, DCM_CONST) DcmDspRc_DcmDspRoutine_CheckPgmPreCond=
{
    /* Allowed Security Row Bit Mask for start routine*/
  0xFFFF,
  /* Allowed Security Row Bit Mask Stop Routine */
  0xFFFF,
  /* Allowed Security Row Bit Mask  Request Routine Results*/
  0xFFFF,

    /* Allowed Session Row Bit Mask for start routine */
        0x7uL,    
   /* Allowed Session Row Bit Mask  for stop routine */
        0x7uL,    
   /* Allowed Session Row Bit Mask request routine results */
        0x7uL,    
     NULL_PTR,       /*  No User defined Mode rule Function configured  */
    /*Reference to the routine control mode rule*/
    &Dcm_DcmModeRule_0,
    &Dcm_DcmModeRule_0,
    &Dcm_DcmModeRule_0,
    /* Reference to In Signal from StartRoutine */
    NULL_PTR,
    /* Reference to In Signal from StopRoutine */
    DcmDspRc_DcmDspRoutine_CheckPgmPreCond_StpInSig,
/* Reference to In Signal from RequestResultRoutine */
    NULL_PTR,
    /* Reference to Out Signal from StartRoutine */
    DcmDspRc_DcmDspRoutine_CheckPgmPreCond_StrtOutSig,
    /* Reference to Out Signal from StopRoutine */
    DcmDspRc_DcmDspRoutine_CheckPgmPreCond_StopOutSig,
    /* Reference to Out Signal from RequestResultsRoutine */
    DcmDspRc_DcmDspRoutine_CheckPgmPreCond_ReqRsltOutSig,
    /* (Maximum) Size of Control Option Record i.e. Optional Bytes in Request for Start Routine */
    0,
    /* (Maximum) Size of Control Option Record i.e. Optional Bytes in Request for Stop Routine */
    2,
/* (Maximum) Size of Control Option Record i.e. Optional Bytes in Request for RequestResults Routine */
    0,
    /* (Maximum) Size of Status Option Record i.e. Optional Bytes in Response for Request Start Routine */
    4,
    /* (Maximum) Size of Status Option Record i.e. Optional Bytes in Response for Request Stop Routine */
    2,
    /* (Maximum) Size of Status Option Record i.e. Optional Bytes in Response for RequestResults Routine */
    4,
    /* Minimum Size of Control Option Record i.e. Optional Bytes in Request for Start Routine */

    0,
    /* Minimum Size of Control Option Record i.e. Optional Bytes in Request for Stop Routine */
    2,
    /* Minimum Size of Control Option Record i.e. Optional Bytes in Request for RequestResult Routine */
    0,
    /* Minimum Size of Status Option Record i.e. Optional Bytes in Response for Request Start Routine */
    4,
    /* Minimum Size of Status Option Record i.e. Optional Bytes in Response for Request Stop Routine */
    2,
    /* Minimum Size of Status Option Record i.e. Optional Bytes in Response for Request RequestResults Routine */
    4,
    /* Number of In Signals configured for StartRoutine */
    0,
    /* Number of In Signals configured for StopRoutine */
    1,
/* Number of In Signals configured for ReqResultsRoutine */
    0,
    /* Number of Out Signals configured for StartRoutine */
    4,
    /* Number of Out Signals configured for StopRoutine */
    1,
    /* Number of Out Signals configured for RequestResultsRoutine */
    1
};


#define DCM_STOP_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"

#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"

static FUNC(Std_ReturnType,DCM_CODE) Dcm_Dsp_RC_DcmDspRoutine_Test_Func ( VAR(uint8, AUTOMATIC) dataSubFunc_u8 )
{
    VAR(Std_ReturnType,AUTOMATIC) dataRetVal_u8;
    dataRetVal_u8 = E_NOT_OK;

    switch (dataSubFunc_u8)
    {
    case 1u:
        dataRetVal_u8 = Rte_Call_RoutineServices_DcmDspRoutine_Test_Start
                (
                    Dcm_RCOpStatus_u8,
                    &(Dcm_RCNegResCode_u8)
                  );

        break;

    case 2u:
        dataRetVal_u8 = Rte_Call_RoutineServices_DcmDspRoutine_Test_Stop
                (
Dcm_RCSigIn_au16[DcmDspRoutine_Test_DcmDspStopRoutineInSignal_0_StpIn],                    Dcm_RCOpStatus_u8,
                    &(Dcm_RCSigOut_au32[DcmDspRoutine_Test_DcmDspStopRoutineOutSignal_0_StpOut]),
                    &(Dcm_RCNegResCode_u8)
                );

        break;

    case 3u:
        dataRetVal_u8 = Rte_Call_RoutineServices_DcmDspRoutine_Test_RequestResults
                (
                    Dcm_RCOpStatus_u8,
                    &(Dcm_RCSigOut_au32[DcmDspRoutine_Test_DcmDspRequestRoutineResultsOutSignal_0_ReqRsltOut]),
                    &(Dcm_RCNegResCode_u8)
                );
        break;

    default:
        Dcm_RCNegResCode_u8 = DCM_E_SUBFUNCTIONNOTSUPPORTED;
        break;
    }

    return (dataRetVal_u8);
}


static FUNC(Std_ReturnType,DCM_CODE) Dcm_Dsp_RC_DcmDspRoutine_CheckPgmPreCond_Func ( VAR(uint8, AUTOMATIC) dataSubFunc_u8 )
{
    VAR(Std_ReturnType,AUTOMATIC) dataRetVal_u8;
    dataRetVal_u8 = E_NOT_OK;

    switch (dataSubFunc_u8)
    {
    case 1u:
        dataRetVal_u8 = Rte_Call_RoutineServices_DcmDspRoutine_CheckPgmPreCond_Start
                (
                    Dcm_RCOpStatus_u8,
                    &(Dcm_RCSigOut_au8[DcmDspRoutine_CheckPgmPreCond_DcmDspStartRoutineOutSignal_ES_StrtOut]),
                    &(Dcm_RCSigOut_au8[DcmDspRoutine_CheckPgmPreCond_DcmDspStartRoutineOutSignal_VS_StrtOut]),
                    &(Dcm_RCSigOut_au8[DcmDspRoutine_CheckPgmPreCond_DcmDspStartRoutineOutSignal_IC_StrtOut]),
                    &(Dcm_RCSigOut_au8[DcmDspRoutine_CheckPgmPreCond_DcmDspStartRoutineOutSignal_VC_StrtOut]),
                    &(Dcm_RCNegResCode_u8)
                  );

        break;

    case 2u:
        dataRetVal_u8 = Rte_Call_RoutineServices_DcmDspRoutine_CheckPgmPreCond_Stop
                (
Dcm_RCSigIn_au16[DcmDspRoutine_CheckPgmPreCond_DcmDspStopRoutineInSignal_0_StpIn],                    Dcm_RCOpStatus_u8,
                    &(Dcm_RCSigOut_au16[DcmDspRoutine_CheckPgmPreCond_DcmDspStopRoutineOutSignal_0_StpOut]),
                    &(Dcm_RCNegResCode_u8)
                );

        break;

    case 3u:
        dataRetVal_u8 = Rte_Call_RoutineServices_DcmDspRoutine_CheckPgmPreCond_RequestResults
                (
                    Dcm_RCOpStatus_u8,
                    &(Dcm_RCSigOut_au32[DcmDspRoutine_CheckPgmPreCond_DcmDspRequestRoutineResultsOutSignal_0_ReqRsltOut]),
                    &(Dcm_RCNegResCode_u8)
                );
        break;

    default:
        Dcm_RCNegResCode_u8 = DCM_E_SUBFUNCTIONNOTSUPPORTED;
        break;
    }

    return (dataRetVal_u8);
}

#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"

#define DCM_START_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"

/* Array with function pointers configured for RIDs to check if they are supported in the current variant */

CONST(Dcm_DspRoutineType_tst, DCM_CONST) Dcm_DspRoutine_cast[DCM_CFG_RC_NUMRIDS]=
{

    /* DcmDspRoutine_Test */
    {
        0x200,        /* Routine Identifier */
        TRUE,      /* Fixed length */
        TRUE,       /* UsePort is set to TRUE, call will be to RTE ports */
        &DcmDspRc_DcmDspRoutine_Test,      /* Reference to Routine Info */
        &Dcm_Dsp_RC_DcmDspRoutine_Test_Func,        /* Reference to Call-out function */

        TRUE,       /* Is Start Routine supported ? */

        TRUE,       /* Is Stop Routine supported ? */
        TRUE,       /* Stop this routine if active on Session change */
        TRUE,       /* Is RequestSequnceError supported for RequestResults subfunction for Routine which is not started ? */
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),      /*Configuration mask indicating the availability of routine in different DCMConfigsets*/
#endif
        TRUE,       /* Is Request Results Routine supported ? */
    }
,
    /* DcmDspRoutine_CheckPgmPreCond */
    {
        0x203,        /* Routine Identifier */
        TRUE,      /* Fixed length */
        TRUE,       /* UsePort is set to TRUE, call will be to RTE ports */
        &DcmDspRc_DcmDspRoutine_CheckPgmPreCond,      /* Reference to Routine Info */
        &Dcm_Dsp_RC_DcmDspRoutine_CheckPgmPreCond_Func,        /* Reference to Call-out function */

        TRUE,       /* Is Start Routine supported ? */

        TRUE,       /* Is Stop Routine supported ? */
        TRUE,       /* Stop this routine if active on Session change */
        TRUE,       /* Is RequestSequnceError supported for RequestResults subfunction for Routine which is not started ? */
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),      /*Configuration mask indicating the availability of routine in different DCMConfigsets*/
#endif
        TRUE,       /* Is Request Results Routine supported ? */
    }
};
#define DCM_STOP_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
/* Array for storing current status of each RID*/
VAR(Dcm_DspRoutineStatusType_ten, DCM_VAR) Dcm_RoutineStatus_aen[DCM_CFG_RC_NUMRIDS];
#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
#endif

/**
 ***************************************************************************************************
            Routine control (RC) service - end
 ***************************************************************************************************
 */












 #define DCM_START_SEC_CODE /*Adding this for memory mapping*/
 #include "Dcm_Cfg_MemMap.h"
              
static FUNC(Std_ReturnType,DCM_CODE) Dcm_ReadDidSignal_DspData_ASW_VER_F189(P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data)
{
    /*MR12 RULE 13.4 VIOLATION: The result of an assignment is being used in an arithmetic operation or another assigning operation. MISRA C:2012 Rule-13.4 */
     return(Rte_Read_R_DataServices_DspData_ASW_VER_F189_Data(Data));
}
                
              
static FUNC(Std_ReturnType,DCM_CODE) Dcm_ReadDidSignal_DspData_SYS_SUP_ID_F18A(P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data)
{
    /*MR12 RULE 13.4 VIOLATION: The result of an assignment is being used in an arithmetic operation or another assigning operation. MISRA C:2012 Rule-13.4 */
     return(Rte_Read_R_DataServices_DspData_SYS_SUP_ID_F18A_Data(Data));
}
                
              
static FUNC(Std_ReturnType,DCM_CODE) Dcm_ReadDidSignal_DspData_MANU_DATE_F18B(P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data)
{
    /*MR12 RULE 13.4 VIOLATION: The result of an assignment is being used in an arithmetic operation or another assigning operation. MISRA C:2012 Rule-13.4 */
     return(Rte_Read_R_DataServices_DspData_MANU_DATE_F18B_Data(Data));
}
                
 
  
 
#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"


 #define DCM_START_SEC_CODE /*Adding this for memory mapping*/
 #include "Dcm_Cfg_MemMap.h"
static FUNC(Std_ReturnType,DCM_CODE) Dcm_WriteDidSignal_DspData_ASW_VER_F189(P2CONST(uint8,AUTOMATIC,DCM_INTERN_DATA) Data)
{
   /*MR12 RULE 13.4 VIOLATION: The result of an assignment is being used in an arithmetic operation or another assigning operation. MISRA C:2012 Rule-13.4 */
    return(Rte_Write_P_DataServices_DspData_ASW_VER_F189_Data(Data));
}
static FUNC(Std_ReturnType,DCM_CODE) Dcm_WriteDidSignal_DspData_SYS_SUP_ID_F18A(P2CONST(uint8,AUTOMATIC,DCM_INTERN_DATA) Data)
{
   /*MR12 RULE 13.4 VIOLATION: The result of an assignment is being used in an arithmetic operation or another assigning operation. MISRA C:2012 Rule-13.4 */
    return(Rte_Write_P_DataServices_DspData_SYS_SUP_ID_F18A_Data(Data));
}
 
#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"


/*Handling of  Sender receiver supported IOCBI DIDs*/
 








/**
 **********************************************************************************************************************
           DID Signal Substructure Configuration for IOCBI
 **********************************************************************************************************************
**/
#define DCM_START_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
CONST(Dcm_SignalDIDIocbiConfig_tst, DCM_CONST) Dcm_DspIOControlInfo[2]=
{
    {
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR    
    },
    {
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
            (void*)&ReturnControlToECUFnc_Test,            /* Return Control To Ecu Function */
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
            (void*)&ResetToDefault_Test,         /* Reset To Default Function */
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
            (void*)&FreeseCurrentStateFnc_Test,            /* Freeze Current State Function */
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
             (void*)&AdjustmentFnc_Test            /* Short Term Adjustment Function */
                
    }
};
  
#define DCM_STOP_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
/**
 **********************************************************************************************************************
           DID Signal Substructure Configuration for condition check for read and write and read datalength function
 **********************************************************************************************************************
**/
#define DCM_START_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
CONST(Dcm_SignalDIDSubStructConfig_tst, DCM_CONST) Dcm_DspDid_ControlInfo_st[5]=
{
    {
        NULL_PTR,
        NULL_PTR
,
        NULL_PTR
          
,
        0
    },



    {

            NULL_PTR,          /* Condition Check Read Function */
            NULL_PTR,          /* Read Data Length Function */
            NULL_PTR,           /* Write Data Function */
                1    /*Index to DcmDspControlInfoStructure*/   /*IOCBI Sub structure address*/
    }
, 
    {

            NULL_PTR,          /* Condition Check Read Function */
            NULL_PTR,          /* Read Data Length Function */
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
	    (void*)&Dcm_WriteDidSignal_DspData_SYS_SUP_ID_F18A,         /* Write Data Function */
            0                                                /*IOCBI Sub structure address*/
    }
, 
    {

            NULL_PTR,          /* Condition Check Read Function */
            NULL_PTR,          /* Read Data Length Function */
            NULL_PTR,           /* Write Data Function */
            0                                                /*IOCBI Sub structure address*/
    }
, 
    {

            NULL_PTR,          /* Condition Check Read Function */
            NULL_PTR,          /* Read Data Length Function */
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
	    (void*)&Dcm_WriteDidSignal_DspData_ASW_VER_F189,         /* Write Data Function */
            0                                                /*IOCBI Sub structure address*/
    }

};


#define DCM_STOP_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"

/**
 ***************************************************************************************************
           DID Signal Configuration
 ***************************************************************************************************
**/

#define DCM_START_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
CONST(Dcm_DataInfoConfig_tst, DCM_CONST) Dcm_DspDataInfo_st [47]=
{
    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
	        (void*)&Dcm_ReadADS,            /* Read Data Function */
    
    
           8,                                                 /*Signal Data Size */
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
	       USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
           DCM_BIG_ENDIAN,                 /*Signal endianness is BIG_ENDIAN*/
     
           TRUE,       /*Signal's fixedLength type**/
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
             (void*)&Dcm_ReadDidSignal_DspData_ASW_VER_F189,            /* Read Data Function */
    
    
           16,                                                 /*Signal Data Size */
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
           4,    /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                    /* Data Type is UINT8*/
	       USE_DATA_SENDER_RECEIVER,      /*DataUsePort is USE_DATA_SENDER_RECEIVER*/
           DCM_BIG_ENDIAN,                 /*Signal endianness is BIG_ENDIAN*/
     
           TRUE,       /*Signal's fixedLength type**/
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
	        (void*)&Dcm_ReadAppSW_Number,            /* Read Data Function */
    
    
           56,                                                 /*Signal Data Size */
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
	       USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
           DCM_BIG_ENDIAN,                 /*Signal endianness is BIG_ENDIAN*/
     
           TRUE,       /*Signal's fixedLength type**/
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
	        (void*)&Dcm_ReadBSW_Number,            /* Read Data Function */
    
    
           56,                                                 /*Signal Data Size */
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
	       USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
           DCM_BIG_ENDIAN,                 /*Signal endianness is BIG_ENDIAN*/
     
           TRUE,       /*Signal's fixedLength type**/
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
	        (void*)&Dcm_ReadCalSW_Number,            /* Read Data Function */
    
    
           56,                                                 /*Signal Data Size */
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
	       USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
           DCM_BIG_ENDIAN,                 /*Signal endianness is BIG_ENDIAN*/
     
           TRUE,       /*Signal's fixedLength type**/
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
	        (void*)&Dcm_ReadECUBoot_version_number,            /* Read Data Function */
    
    
           16,                                                 /*Signal Data Size */
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
	       USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
           DCM_BIG_ENDIAN,                 /*Signal endianness is BIG_ENDIAN*/
     
           TRUE,       /*Signal's fixedLength type**/
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
	        (void*)&Dcm_ReadECUHWBOMECU_Name,            /* Read Data Function */
    
    
           32,                                                 /*Signal Data Size */
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
	       USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
           DCM_BIG_ENDIAN,                 /*Signal endianness is BIG_ENDIAN*/
     
           TRUE,       /*Signal's fixedLength type**/
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
	        (void*)&Dcm_ReadECUHWBOM_version,            /* Read Data Function */
    
    
           8,                                                 /*Signal Data Size */
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
	       USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
           DCM_BIG_ENDIAN,                 /*Signal endianness is BIG_ENDIAN*/
     
           TRUE,       /*Signal's fixedLength type**/
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
	        (void*)&Dcm_ReadECUHW_Subversion,            /* Read Data Function */
    
    
           8,                                                 /*Signal Data Size */
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
	       USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
           DCM_BIG_ENDIAN,                 /*Signal endianness is BIG_ENDIAN*/
     
           TRUE,       /*Signal's fixedLength type**/
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
	        (void*)&Dcm_ReadECUHW_Version_FRS,            /* Read Data Function */
    
    
           8,                                                 /*Signal Data Size */
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
	       USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
           DCM_BIG_ENDIAN,                 /*Signal endianness is BIG_ENDIAN*/
     
           TRUE,       /*Signal's fixedLength type**/
     
     
    }
    
    
,    
     {   
            NULL_PTR,            /* Read Data Function */
    
    
           32,                                                 /*Signal Data Size */
           NvMConf_NvMBlockDescriptor_NvM_UDS_ECUPN_V0,                               /*NVM block id for USE_BLOCK_ID*/
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
	       USE_BLOCK_ID,      /*DataUsePort is USE_BLOCK_ID*/
           DCM_BIG_ENDIAN,                 /*Signal endianness is BIG_ENDIAN*/
     
           TRUE,       /*Signal's fixedLength type**/
     
     
    }
    
    
,    
     {   
            NULL_PTR,            /* Read Data Function */
    
    
           8,                                                 /*Signal Data Size */
           NvMConf_NvMBlockDescriptor_NvM_UDS_ECUPN_V4,                               /*NVM block id for USE_BLOCK_ID*/
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
	       USE_BLOCK_ID,      /*DataUsePort is USE_BLOCK_ID*/
           DCM_BIG_ENDIAN,                 /*Signal endianness is BIG_ENDIAN*/
     
           TRUE,       /*Signal's fixedLength type**/
     
     
    }
    
    
,    
     {   
            NULL_PTR,            /* Read Data Function */
    
    
           8,                                                 /*Signal Data Size */
           NvMConf_NvMBlockDescriptor_NvM_UDS_ECUPN_V5,                               /*NVM block id for USE_BLOCK_ID*/
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
	       USE_BLOCK_ID,      /*DataUsePort is USE_BLOCK_ID*/
           DCM_BIG_ENDIAN,                 /*Signal endianness is BIG_ENDIAN*/
     
           TRUE,       /*Signal's fixedLength type**/
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
	        (void*)&Dcm_ReadECUSWBOMECU_Name,            /* Read Data Function */
    
    
           8,                                                 /*Signal Data Size */
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
	       USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
           DCM_BIG_ENDIAN,                 /*Signal endianness is BIG_ENDIAN*/
     
           TRUE,       /*Signal's fixedLength type**/
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
	        (void*)&Dcm_ReadECUSWBOM_version,            /* Read Data Function */
    
    
           8,                                                 /*Signal Data Size */
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
	       USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
           DCM_BIG_ENDIAN,                 /*Signal endianness is BIG_ENDIAN*/
     
           TRUE,       /*Signal's fixedLength type**/
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
	        (void*)&Dcm_ReadECUSW_Subversion,            /* Read Data Function */
    
    
           8,                                                 /*Signal Data Size */
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
	       USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
           DCM_BIG_ENDIAN,                 /*Signal endianness is BIG_ENDIAN*/
     
           TRUE,       /*Signal's fixedLength type**/
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
	        (void*)&Dcm_ReadECUSW_Version_and_FRS,            /* Read Data Function */
    
    
           8,                                                 /*Signal Data Size */
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
	       USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
           DCM_BIG_ENDIAN,                 /*Signal endianness is BIG_ENDIAN*/
     
           TRUE,       /*Signal's fixedLength type**/
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
	        (void*)&Dcm_ReadECU_Data_D,            /* Read Data Function */
    
    
           8,                                                 /*Signal Data Size */
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
	       USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
           DCM_BIG_ENDIAN,                 /*Signal endianness is BIG_ENDIAN*/
     
           TRUE,       /*Signal's fixedLength type**/
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
	        (void*)&Dcm_ReadECU_Data_M,            /* Read Data Function */
    
    
           8,                                                 /*Signal Data Size */
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
	       USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
           DCM_BIG_ENDIAN,                 /*Signal endianness is BIG_ENDIAN*/
     
           TRUE,       /*Signal's fixedLength type**/
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
	        (void*)&Dcm_ReadECU_Data_Y,            /* Read Data Function */
    
    
           8,                                                 /*Signal Data Size */
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
	       USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
           DCM_BIG_ENDIAN,                 /*Signal endianness is BIG_ENDIAN*/
     
           TRUE,       /*Signal's fixedLength type**/
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
	        (void*)&Dcm_ReadECUname_ID,            /* Read Data Function */
    
    
           120,                                                 /*Signal Data Size */
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
	       USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
           DCM_BIG_ENDIAN,                 /*Signal endianness is BIG_ENDIAN*/
     
           TRUE,       /*Signal's fixedLength type**/
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
	        (void*)&DataReadFnc_Test,            /* Read Data Function */
    
    
           8,                                                 /*Signal Data Size */
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
           1,    /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
	       USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
           DCM_BIG_ENDIAN,                 /*Signal endianness is BIG_ENDIAN*/
     
           TRUE,       /*Signal's fixedLength type**/
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
             (void*)&Dcm_ReadDidSignal_DspData_MANU_DATE_F18B,            /* Read Data Function */
    
    
           64,                                                 /*Signal Data Size */
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
           3,    /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                    /* Data Type is UINT8*/
	       USE_DATA_SENDER_RECEIVER,      /*DataUsePort is USE_DATA_SENDER_RECEIVER*/
           DCM_BIG_ENDIAN,                 /*Signal endianness is BIG_ENDIAN*/
     
           TRUE,       /*Signal's fixedLength type**/
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
	        (void*)&Dcm_ReadP_FingerPrint,            /* Read Data Function */
    
    
           360,                                                 /*Signal Data Size */
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
	       USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
           DCM_BIG_ENDIAN,                 /*Signal endianness is BIG_ENDIAN*/
     
           TRUE,       /*Signal's fixedLength type**/
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
	        (void*)&Dcm_ReadP_FingerPrint1,            /* Read Data Function */
    
    
           360,                                                 /*Signal Data Size */
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
	       USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
           DCM_BIG_ENDIAN,                 /*Signal endianness is BIG_ENDIAN*/
     
           TRUE,       /*Signal's fixedLength type**/
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
	        (void*)&Dcm_ReadP_FingerPrint2,            /* Read Data Function */
    
    
           360,                                                 /*Signal Data Size */
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
	       USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
           DCM_BIG_ENDIAN,                 /*Signal endianness is BIG_ENDIAN*/
     
           TRUE,       /*Signal's fixedLength type**/
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
	        (void*)&Dcm_ReadP_FingerPrint3,            /* Read Data Function */
    
    
           360,                                                 /*Signal Data Size */
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
	       USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
           DCM_BIG_ENDIAN,                 /*Signal endianness is BIG_ENDIAN*/
     
           TRUE,       /*Signal's fixedLength type**/
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
	        (void*)&Dcm_ReadP_FingerPrint4,            /* Read Data Function */
    
    
           360,                                                 /*Signal Data Size */
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
	       USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
           DCM_BIG_ENDIAN,                 /*Signal endianness is BIG_ENDIAN*/
     
           TRUE,       /*Signal's fixedLength type**/
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
	        (void*)&Dcm_ReadP_FingerPrint5,            /* Read Data Function */
    
    
           360,                                                 /*Signal Data Size */
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
	       USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
           DCM_BIG_ENDIAN,                 /*Signal endianness is BIG_ENDIAN*/
     
           TRUE,       /*Signal's fixedLength type**/
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
	        (void*)&Dcm_ReadSIC,            /* Read Data Function */
    
    
           40,                                                 /*Signal Data Size */
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
	       USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
           DCM_BIG_ENDIAN,                 /*Signal endianness is BIG_ENDIAN*/
     
           TRUE,       /*Signal's fixedLength type**/
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
	        (void*)&Dcm_ReadAspRsd_nWoFlt,            /* Read Data Function */
    
    
           16,                                                 /*Signal Data Size */
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
	       USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
           DCM_BIG_ENDIAN,                 /*Signal endianness is BIG_ENDIAN*/
     
           TRUE,       /*Signal's fixedLength type**/
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
	        (void*)&Dcm_ReadPP_SWC_CSP_CSP_Is,            /* Read Data Function */
    
    
           16,                                                 /*Signal Data Size */
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
	       USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
           DCM_BIG_ENDIAN,                 /*Signal endianness is BIG_ENDIAN*/
     
           TRUE,       /*Signal's fixedLength type**/
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
	        (void*)&Dcm_ReadPP_SWC_CSP_CSP_iU,            /* Read Data Function */
    
    
           16,                                                 /*Signal Data Size */
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
	       USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
           DCM_BIG_ENDIAN,                 /*Signal endianness is BIG_ENDIAN*/
     
           TRUE,       /*Signal's fixedLength type**/
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
	        (void*)&Dcm_ReadPP_SWC_CSP_CSP_iV,            /* Read Data Function */
    
    
           16,                                                 /*Signal Data Size */
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
	       USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
           DCM_BIG_ENDIAN,                 /*Signal endianness is BIG_ENDIAN*/
     
           TRUE,       /*Signal's fixedLength type**/
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
	        (void*)&Dcm_ReadPP_SWC_CSP_CSP_iW,            /* Read Data Function */
    
    
           16,                                                 /*Signal Data Size */
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
	       USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
           DCM_BIG_ENDIAN,                 /*Signal endianness is BIG_ENDIAN*/
     
           TRUE,       /*Signal's fixedLength type**/
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
	        (void*)&Dcm_ReadPP_SWC_CSP_CSP_uDcLnk,            /* Read Data Function */
    
    
           16,                                                 /*Signal Data Size */
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
	       USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
           DCM_BIG_ENDIAN,                 /*Signal endianness is BIG_ENDIAN*/
     
           TRUE,       /*Signal's fixedLength type**/
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
	        (void*)&Dcm_ReadPP_SWC_MPP_MPP_TrqMech,            /* Read Data Function */
    
    
           16,                                                 /*Signal Data Size */
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
	       USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
           DCM_BIG_ENDIAN,                 /*Signal endianness is BIG_ENDIAN*/
     
           TRUE,       /*Signal's fixedLength type**/
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
	        (void*)&Dcm_ReadSPF_tDBCTempUFlt,            /* Read Data Function */
    
    
           8,                                                 /*Signal Data Size */
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
	       USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
           DCM_BIG_ENDIAN,                 /*Signal endianness is BIG_ENDIAN*/
     
           TRUE,       /*Signal's fixedLength type**/
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
	        (void*)&Dcm_ReadSPF_tStrrTemp1Flt,            /* Read Data Function */
    
    
           8,                                                 /*Signal Data Size */
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
	       USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
           DCM_BIG_ENDIAN,                 /*Signal endianness is BIG_ENDIAN*/
     
           TRUE,       /*Signal's fixedLength type**/
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
	        (void*)&Dcm_ReadSPF_tStrrTemp2Flt,            /* Read Data Function */
    
    
           8,                                                 /*Signal Data Size */
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
	       USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
           DCM_BIG_ENDIAN,                 /*Signal endianness is BIG_ENDIAN*/
     
           TRUE,       /*Signal's fixedLength type**/
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
	        (void*)&Dcm_ReadSPF_uKl30Flt,            /* Read Data Function */
    
    
           16,                                                 /*Signal Data Size */
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
	       USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
           DCM_BIG_ENDIAN,                 /*Signal endianness is BIG_ENDIAN*/
     
           TRUE,       /*Signal's fixedLength type**/
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
             (void*)&Dcm_ReadDidSignal_DspData_SYS_SUP_ID_F18A,            /* Read Data Function */
    
    
           64,                                                 /*Signal Data Size */
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
           2,    /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                    /* Data Type is UINT8*/
	       USE_DATA_SENDER_RECEIVER,      /*DataUsePort is USE_DATA_SENDER_RECEIVER*/
           DCM_BIG_ENDIAN,                 /*Signal endianness is BIG_ENDIAN*/
     
           TRUE,       /*Signal's fixedLength type**/
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
	        (void*)&Dcm_ReadDspData_Service_Date,            /* Read Data Function */
    
    
           24,                                                 /*Signal Data Size */
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
	       USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
           DCM_BIG_ENDIAN,                 /*Signal endianness is BIG_ENDIAN*/
     
           TRUE,       /*Signal's fixedLength type**/
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
	        (void*)&Dcm_ReadSupplierSpecific_ID,            /* Read Data Function */
    
    
           16,                                                 /*Signal Data Size */
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
	       USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
           DCM_BIG_ENDIAN,                 /*Signal endianness is BIG_ENDIAN*/
     
           TRUE,       /*Signal's fixedLength type**/
     
     
    }
    
    
,    
     {   
            NULL_PTR,            /* Read Data Function */
    
    
           136,                                                 /*Signal Data Size */
           NvMConf_NvMBlockDescriptor_NvM_UDS_VIN,                               /*NVM block id for USE_BLOCK_ID*/
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
	       USE_BLOCK_ID,      /*DataUsePort is USE_BLOCK_ID*/
           DCM_BIG_ENDIAN,                 /*Signal endianness is BIG_ENDIAN*/
     
           TRUE,       /*Signal's fixedLength type**/
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
	        (void*)&Dcm_ReadSysSupplierECUHW_Num,            /* Read Data Function */
    
    
           8,                                                 /*Signal Data Size */
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
	       USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
           DCM_BIG_ENDIAN,                 /*Signal endianness is BIG_ENDIAN*/
     
           TRUE,       /*Signal's fixedLength type**/
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
	        (void*)&Dcm_ReadSysSupplierECUSW_Num,            /* Read Data Function */
    
    
           8,                                                 /*Signal Data Size */
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
           0,                         /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
	       USE_DATA_SYNCH_FNC,      /*DataUsePort is USE_DATA_SYNCH_FNC*/
           DCM_BIG_ENDIAN,                 /*Signal endianness is BIG_ENDIAN*/
     
           TRUE,       /*Signal's fixedLength type**/
     
     
    }
    
    
};



#define DCM_STOP_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"



/**
 ***************************************************************************************************
           DID Signal Configuration
 ***************************************************************************************************
**/
#define DCM_START_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"


/* DID DspDid_ASW_VER_F189 signal configuration */
static CONST(Dcm_SignalDIDConfig_tst, DCM_CONST) DcmDspDid_F189_SigConf[1]=
{
 /* Signal DspDidSignal_F189 */
    {
        0,    /* Signal Bit Position */
        1
    }
};

/* DID DspDid_SYS_SUP_ID_F18A signal configuration */
static CONST(Dcm_SignalDIDConfig_tst, DCM_CONST) DcmDspDid_213_SigConf[1]=
{
 /* Signal DspDidSignal_F18A */
    {
        0,    /* Signal Bit Position */
        41
    }
};

/* DID DspDid_MANU_DATE_F18B signal configuration */
static CONST(Dcm_SignalDIDConfig_tst, DCM_CONST) DcmDspDid_214_SigConf[1]=
{
 /* Signal DspDidSignal_F18B */
    {
        0,    /* Signal Bit Position */
        22
    }
};

/* DID DspDid_Sys_F190 signal configuration */
static CONST(Dcm_SignalDIDConfig_tst, DCM_CONST) DcmDspDid_F190_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Bit Position */
        44
    }
};

/* DID DspDid_IOC_DATA_0200 signal configuration */
static CONST(Dcm_SignalDIDConfig_tst, DCM_CONST) DcmDspDid_200_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Bit Position */
        21
    }
};

/* DID DspDid_ECU_0200 signal configuration */
static CONST(Dcm_SignalDIDConfig_tst, DCM_CONST) DcmDspDid_211_SigConf[11]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Bit Position */
        32
    }
, 
 /* Signal DcmDspDidSignal_0 */
    {
        16,    /* Signal Bit Position */
        33
    }
, 
 /* Signal DcmDspDidSignal_1 */
    {
        32,    /* Signal Bit Position */
        34
    }
, 
 /* Signal DcmDspDidSignal_2 */
    {
        48,    /* Signal Bit Position */
        35
    }
, 
 /* Signal DcmDspDidSignal_3 */
    {
        64,    /* Signal Bit Position */
        40
    }
, 
 /* Signal DcmDspDidSignal_4 */
    {
        80,    /* Signal Bit Position */
        37
    }
, 
 /* Signal DcmDspDidSignal_5 */
    {
        88,    /* Signal Bit Position */
        38
    }
, 
 /* Signal DcmDspDidSignal_6 */
    {
        96,    /* Signal Bit Position */
        39
    }
, 
 /* Signal DcmDspDidSignal_7 */
    {
        104,    /* Signal Bit Position */
        31
    }
, 
 /* Signal DcmDspDidSignal_8 */
    {
        120,    /* Signal Bit Position */
        36
    }
, 
 /* Signal DcmDspDidSignal_9 */
    {
        136,    /* Signal Bit Position */
        30
    }
};

/* DID DspDid_Sys_F103 signal configuration */
static CONST(Dcm_SignalDIDConfig_tst, DCM_CONST) DcmDspDid_F103_SigConf[3]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Bit Position */
        10
    }
, 
 /* Signal DcmDspDidSignal_0 */
    {
        32,    /* Signal Bit Position */
        11
    }
, 
 /* Signal DcmDspDidSignal_1 */
    {
        40,    /* Signal Bit Position */
        12
    }
};

/* DID DspDid_Sys_F186 signal configuration */
static CONST(Dcm_SignalDIDConfig_tst, DCM_CONST) DcmDspDid_F186_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Bit Position */
        0
    }
};

/* DID DspDid_Sys_F18A signal configuration */
static CONST(Dcm_SignalDIDConfig_tst, DCM_CONST) DcmDspDid_F18A_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Bit Position */
        29
    }
};

/* DID DspDid_Sys_F18B signal configuration */
static CONST(Dcm_SignalDIDConfig_tst, DCM_CONST) DcmDspDid_F18B_SigConf[3]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Bit Position */
        19
    }
, 
 /* Signal DcmDspDidSignal_0 */
    {
        8,    /* Signal Bit Position */
        18
    }
, 
 /* Signal DcmDspDidSignal_1 */
    {
        16,    /* Signal Bit Position */
        17
    }
};

/* DID DspDid_Sys_F191 signal configuration */
static CONST(Dcm_SignalDIDConfig_tst, DCM_CONST) DcmDspDid_F191_SigConf[4]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Bit Position */
        6
    }
, 
 /* Signal DcmDspDidSignal_0 */
    {
        32,    /* Signal Bit Position */
        7
    }
, 
 /* Signal DcmDspDidSignal_1 */
    {
        40,    /* Signal Bit Position */
        9
    }
, 
 /* Signal DcmDspDidSignal_2 */
    {
        48,    /* Signal Bit Position */
        8
    }
};

/* DID DspDid_Sys_F188 signal configuration */
static CONST(Dcm_SignalDIDConfig_tst, DCM_CONST) DcmDspDid_F188_SigConf[4]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Bit Position */
        13
    }
, 
 /* Signal DcmDspDidSignal_0 */
    {
        32,    /* Signal Bit Position */
        14
    }
, 
 /* Signal DcmDspDidSignal_1 */
    {
        40,    /* Signal Bit Position */
        16
    }
, 
 /* Signal DcmDspDidSignal_2 */
    {
        48,    /* Signal Bit Position */
        15
    }
};

/* DID DspDid_Sys_F101 signal configuration */
static CONST(Dcm_SignalDIDConfig_tst, DCM_CONST) DcmDspDid_F101_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Bit Position */
        5
    }
};

/* DID DspDid_Sys_F107 signal configuration */
static CONST(Dcm_SignalDIDConfig_tst, DCM_CONST) DcmDspDid_F107_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Bit Position */
        23
    }
};

/* DID DspDid_Sys_F131 signal configuration */
static CONST(Dcm_SignalDIDConfig_tst, DCM_CONST) DcmDspDid_F131_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Bit Position */
        24
    }
};

/* DID DspDid_Sys_F132 signal configuration */
static CONST(Dcm_SignalDIDConfig_tst, DCM_CONST) DcmDspDid_F132_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Bit Position */
        25
    }
};

/* DID DspDid_Sys_F133 signal configuration */
static CONST(Dcm_SignalDIDConfig_tst, DCM_CONST) DcmDspDid_F133_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Bit Position */
        26
    }
};

/* DID DspDid_Sys_F134 signal configuration */
static CONST(Dcm_SignalDIDConfig_tst, DCM_CONST) DcmDspDid_F134_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Bit Position */
        27
    }
};

/* DID DspDid_Sys_F135 signal configuration */
static CONST(Dcm_SignalDIDConfig_tst, DCM_CONST) DcmDspDid_F135_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Bit Position */
        28
    }
};

/* DID DspDid_Sys_F102 signal configuration */
static CONST(Dcm_SignalDIDConfig_tst, DCM_CONST) DcmDspDid_F102_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Bit Position */
        4
    }
};

/* DID DspDid_Sys_F104 signal configuration */
static CONST(Dcm_SignalDIDConfig_tst, DCM_CONST) DcmDspDid_F104_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Bit Position */
        2
    }
};

/* DID DspDid_Sys_F105 signal configuration */
static CONST(Dcm_SignalDIDConfig_tst, DCM_CONST) DcmDspDid_F105_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Bit Position */
        3
    }
};

/* DID DspDid_Sys_F10F signal configuration */
static CONST(Dcm_SignalDIDConfig_tst, DCM_CONST) DcmDspDid_F10F_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Bit Position */
        42
    }
};

/* DID DspDid_Sys_FD01 signal configuration */
static CONST(Dcm_SignalDIDConfig_tst, DCM_CONST) DcmDspDid_FD01_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Bit Position */
        43
    }
};

/* DID DspDid_Sys_F192 signal configuration */
static CONST(Dcm_SignalDIDConfig_tst, DCM_CONST) DcmDspDid_F192_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Bit Position */
        45
    }
};

/* DID DspDid_Sys_F194 signal configuration */
static CONST(Dcm_SignalDIDConfig_tst, DCM_CONST) DcmDspDid_F194_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Bit Position */
        46
    }
};

/* DID DspDid_Sys_F110 signal configuration */
static CONST(Dcm_SignalDIDConfig_tst, DCM_CONST) DcmDspDid_F110_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Bit Position */
        20
    }
};


#define DCM_STOP_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"



/**
 ***************************************************************************************************
           DID Extended Configuration
 ***************************************************************************************************
*/
#define DCM_START_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
static CONST(Dcm_ExtendedDIDConfig_tst, DCM_CONST) Did_extendedConfig_DspDidInfo_ASW_VER_F189=
{
    
        0x5uL,     /* Allowed Read Session levels */
        0xffffffffuL, /* Allowed Read Security levels */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        NULL_PTR,       /*Function pointer to RDBI Mode rule definitions*/
        0x5uL,     /* Allowed Write Session levels */
        0xffffffffuL, /* Allowed Write Security levels */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        NULL_PTR,       /*Function pointer to WDBI Mode rule definitions*/
        0x0uL,          /* Allowed IO control Session levels */
        0x0uL,          /* Allowed IO control Security levels */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        DCM_CONTROLMASK_INTERNAL,                                         /*Default value of Control mask*/
        0x0,                                         /*Control mask size in bytes*/
        FALSE,          /* If disabled does not the IOcontrol(IOCBI DIDS) to be reset on session/security change */
        0x00u
};
static CONST(Dcm_ExtendedDIDConfig_tst, DCM_CONST) Did_extendedConfig_DspDidInfo_SYS_SUP_ID_F18A=
{
    
        0x5uL,     /* Allowed Read Session levels */
        0xffffffffuL, /* Allowed Read Security levels */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        NULL_PTR,       /*Function pointer to RDBI Mode rule definitions*/
        0x5uL,     /* Allowed Write Session levels */
        0xffffffffuL, /* Allowed Write Security levels */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        NULL_PTR,       /*Function pointer to WDBI Mode rule definitions*/
        0x0uL,          /* Allowed IO control Session levels */
        0x0uL,          /* Allowed IO control Security levels */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        DCM_CONTROLMASK_INTERNAL,                                         /*Default value of Control mask*/
        0x0,                                         /*Control mask size in bytes*/
        FALSE,          /* If disabled does not the IOcontrol(IOCBI DIDS) to be reset on session/security change */
        0x00u
};
static CONST(Dcm_ExtendedDIDConfig_tst, DCM_CONST) Did_extendedConfig_DspDidInfo_MANU_DATE_F18B=
{
    
        0x1uL,     /* Allowed Read Session levels */
        0xffffffffuL, /* Allowed Read Security levels */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        NULL_PTR,       /*Function pointer to RDBI Mode rule definitions*/
        0x0uL,          /* Allowed Write Session levels */
        0x0uL,           /* Allowed Write Security levels */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        NULL_PTR,       /*Function pointer to WDBI Mode rule definitions*/
        0x0uL,          /* Allowed IO control Session levels */
        0x0uL,          /* Allowed IO control Security levels */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        DCM_CONTROLMASK_INTERNAL,                                         /*Default value of Control mask*/
        0x0,                                         /*Control mask size in bytes*/
        FALSE,          /* If disabled does not the IOcontrol(IOCBI DIDS) to be reset on session/security change */
        0x00u
};
static CONST(Dcm_ExtendedDIDConfig_tst, DCM_CONST) Did_extendedConfig_DspDidInfo_MANU_DATA_F190=
{
    
        0x7uL,     /* Allowed Read Session levels */
        0xffffffffuL, /* Allowed Read Security levels */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        NULL_PTR,       /*Function pointer to RDBI Mode rule definitions*/
        0x7uL,     /* Allowed Write Session levels */
        0x2uL,     /* Allowed Write Security levels */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        NULL_PTR,       /*Function pointer to WDBI Mode rule definitions*/
        0x0uL,          /* Allowed IO control Session levels */
        0x0uL,          /* Allowed IO control Security levels */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        DCM_CONTROLMASK_INTERNAL,                                         /*Default value of Control mask*/
        0x0,                                         /*Control mask size in bytes*/
        FALSE,          /* If disabled does not the IOcontrol(IOCBI DIDS) to be reset on session/security change */
        0x00u
};
static CONST(Dcm_ExtendedDIDConfig_tst, DCM_CONST) Did_extendedConfig_DspDidInfo_IOC_DATA_0200=
{
    
        0x5uL,     /* Allowed Read Session levels */
        0xffffffffuL, /* Allowed Read Security levels */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        NULL_PTR,       /*Function pointer to RDBI Mode rule definitions*/
        0x0uL,          /* Allowed Write Session levels */
        0x0uL,           /* Allowed Write Security levels */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        NULL_PTR,       /*Function pointer to WDBI Mode rule definitions*/
        0x5uL,     /* Allowed IO control Session levels */
        0xffffffffuL, /* Allowed IO control Security levels */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        DCM_CONTROLMASK_EXTERNAL,                                   /*Control mask is configured as external, control mask handling to be done by Application*/
        0x1,                                   /*Control mask size in bytes*/
        TRUE,            /* If Enabled allows the IOcontrol(IOCBI DIDS) to be reset on session/security change */
    
        0xF
};
static CONST(Dcm_ExtendedDIDConfig_tst, DCM_CONST) Did_extendedConfig_DcmDidInfo_0200=
{
    
        0x7uL,     /* Allowed Read Session levels */
        0xffffffffuL, /* Allowed Read Security levels */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        NULL_PTR,       /*Function pointer to RDBI Mode rule definitions*/
        0x0uL,          /* Allowed Write Session levels */
        0x0uL,           /* Allowed Write Security levels */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        NULL_PTR,       /*Function pointer to WDBI Mode rule definitions*/
        0x0uL,          /* Allowed IO control Session levels */
        0x0uL,          /* Allowed IO control Security levels */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        DCM_CONTROLMASK_INTERNAL,                                         /*Default value of Control mask*/
        0x0,                                         /*Control mask size in bytes*/
        FALSE,          /* If disabled does not the IOcontrol(IOCBI DIDS) to be reset on session/security change */
        0x00u
};
static CONST(Dcm_ExtendedDIDConfig_tst, DCM_CONST) Did_extendedConfig_DspDidInfo_F103=
{
    
        0x7uL,     /* Allowed Read Session levels */
        0x2uL,     /* Allowed Read Security levels */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        &Dcm_DcmModeRule_0,                     /*Function pointer to Mode rule definitions*/
        0x6uL,     /* Allowed Write Session levels */
        0x2uL,     /* Allowed Write Security levels */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        &Dcm_DcmModeRule_0,                   /*Function pointer to Mode rule definitions*/
        0x0uL,          /* Allowed IO control Session levels */
        0x0uL,          /* Allowed IO control Security levels */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        DCM_CONTROLMASK_INTERNAL,                                         /*Default value of Control mask*/
        0x0,                                         /*Control mask size in bytes*/
        FALSE,          /* If disabled does not the IOcontrol(IOCBI DIDS) to be reset on session/security change */
        0x00u
};
static CONST(Dcm_ExtendedDIDConfig_tst, DCM_CONST) Did_extendedConfig_DcmDspDidInfo_SysRead1=
{
    
        0x7uL,     /* Allowed Read Session levels */
        0xffffffffuL, /* Allowed Read Security levels */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        NULL_PTR,       /*Function pointer to RDBI Mode rule definitions*/
        0x0uL,          /* Allowed Write Session levels */
        0x0uL,           /* Allowed Write Security levels */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        NULL_PTR,       /*Function pointer to WDBI Mode rule definitions*/
        0x0uL,          /* Allowed IO control Session levels */
        0x0uL,          /* Allowed IO control Security levels */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        DCM_CONTROLMASK_INTERNAL,                                         /*Default value of Control mask*/
        0x0,                                         /*Control mask size in bytes*/
        FALSE,          /* If disabled does not the IOcontrol(IOCBI DIDS) to be reset on session/security change */
        0x00u
};

#define DCM_STOP_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"


/**
 ***************************************************************************************************
           DID Configuration Structure
 ***************************************************************************************************
*/
#define DCM_START_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
CONST (Dcm_DIDConfig_tst, DCM_CONST) Dcm_DIDConfig []=
{

    {
        0x200,                        /*DID*/
        1,                          /*No of Signals*/
        1,                            /*TotalSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_200_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif
        &Did_extendedConfig_DspDidInfo_IOC_DATA_0200   /*ExtendedConfiguration*/
    }


,
    {
        0x211,                        /*DID*/
        11,                          /*No of Signals*/
        19,                            /*TotalSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_211_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif
        &Did_extendedConfig_DcmDidInfo_0200   /*ExtendedConfiguration*/
    }


,
    {
        0x213,                        /*DID*/
        1,                          /*No of Signals*/
        8,                            /*TotalSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_213_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif
        &Did_extendedConfig_DspDidInfo_SYS_SUP_ID_F18A   /*ExtendedConfiguration*/
    }


,
    {
        0x214,                        /*DID*/
        1,                          /*No of Signals*/
        8,                            /*TotalSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_214_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif
        &Did_extendedConfig_DspDidInfo_MANU_DATE_F18B   /*ExtendedConfiguration*/
    }


,
    {
        0xF101,                        /*DID*/
        1,                          /*No of Signals*/
        2,                            /*TotalSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_F101_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif
        &Did_extendedConfig_DcmDspDidInfo_SysRead1   /*ExtendedConfiguration*/
    }


,
    {
        0xF102,                        /*DID*/
        1,                          /*No of Signals*/
        7,                            /*TotalSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_F102_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif
        &Did_extendedConfig_DcmDspDidInfo_SysRead1   /*ExtendedConfiguration*/
    }


,
    {
        0xF103,                        /*DID*/
        3,                          /*No of Signals*/
        6,                            /*TotalSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_F103_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif
        &Did_extendedConfig_DspDidInfo_F103   /*ExtendedConfiguration*/
    }


,
    {
        0xF104,                        /*DID*/
        1,                          /*No of Signals*/
        7,                            /*TotalSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_F104_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif
        &Did_extendedConfig_DcmDspDidInfo_SysRead1   /*ExtendedConfiguration*/
    }


,
    {
        0xF105,                        /*DID*/
        1,                          /*No of Signals*/
        7,                            /*TotalSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_F105_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif
        &Did_extendedConfig_DcmDspDidInfo_SysRead1   /*ExtendedConfiguration*/
    }


,
    {
        0xF107,                        /*DID*/
        1,                          /*No of Signals*/
        45,                            /*TotalSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_F107_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif
        &Did_extendedConfig_DcmDspDidInfo_SysRead1   /*ExtendedConfiguration*/
    }


,
    {
        0xF10F,                        /*DID*/
        1,                          /*No of Signals*/
        3,                            /*TotalSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_F10F_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif
        &Did_extendedConfig_DcmDspDidInfo_SysRead1   /*ExtendedConfiguration*/
    }


,
    {
        0xF110,                        /*DID*/
        1,                          /*No of Signals*/
        15,                            /*TotalSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_F110_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif
        &Did_extendedConfig_DcmDspDidInfo_SysRead1   /*ExtendedConfiguration*/
    }


,
    {
        0xF131,                        /*DID*/
        1,                          /*No of Signals*/
        45,                            /*TotalSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_F131_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif
        &Did_extendedConfig_DcmDspDidInfo_SysRead1   /*ExtendedConfiguration*/
    }


,
    {
        0xF132,                        /*DID*/
        1,                          /*No of Signals*/
        45,                            /*TotalSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_F132_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif
        &Did_extendedConfig_DcmDspDidInfo_SysRead1   /*ExtendedConfiguration*/
    }


,
    {
        0xF133,                        /*DID*/
        1,                          /*No of Signals*/
        45,                            /*TotalSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_F133_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif
        &Did_extendedConfig_DcmDspDidInfo_SysRead1   /*ExtendedConfiguration*/
    }


,
    {
        0xF134,                        /*DID*/
        1,                          /*No of Signals*/
        45,                            /*TotalSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_F134_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif
        &Did_extendedConfig_DcmDspDidInfo_SysRead1   /*ExtendedConfiguration*/
    }


,
    {
        0xF135,                        /*DID*/
        1,                          /*No of Signals*/
        45,                            /*TotalSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_F135_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif
        &Did_extendedConfig_DcmDspDidInfo_SysRead1   /*ExtendedConfiguration*/
    }


,
    {
        0xF186,                        /*DID*/
        1,                          /*No of Signals*/
        1,                            /*TotalSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_F186_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif
        &Did_extendedConfig_DcmDspDidInfo_SysRead1   /*ExtendedConfiguration*/
    }


,
    {
        0xF188,                        /*DID*/
        4,                          /*No of Signals*/
        7,                            /*TotalSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_F188_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif
        &Did_extendedConfig_DcmDspDidInfo_SysRead1   /*ExtendedConfiguration*/
    }


,
    {
        0xF189,                        /*DID*/
        1,                          /*No of Signals*/
        2,                            /*TotalSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_F189_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif
        &Did_extendedConfig_DspDidInfo_ASW_VER_F189   /*ExtendedConfiguration*/
    }


,
    {
        0xF18A,                        /*DID*/
        1,                          /*No of Signals*/
        5,                            /*TotalSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_F18A_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif
        &Did_extendedConfig_DcmDspDidInfo_SysRead1   /*ExtendedConfiguration*/
    }


,
    {
        0xF18B,                        /*DID*/
        3,                          /*No of Signals*/
        3,                            /*TotalSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_F18B_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif
        &Did_extendedConfig_DcmDspDidInfo_SysRead1   /*ExtendedConfiguration*/
    }


,
    {
        0xF190,                        /*DID*/
        1,                          /*No of Signals*/
        17,                            /*TotalSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_F190_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif
        &Did_extendedConfig_DspDidInfo_MANU_DATA_F190   /*ExtendedConfiguration*/
    }


,
    {
        0xF191,                        /*DID*/
        4,                          /*No of Signals*/
        7,                            /*TotalSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_F191_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif
        &Did_extendedConfig_DcmDspDidInfo_SysRead1   /*ExtendedConfiguration*/
    }


,
    {
        0xF192,                        /*DID*/
        1,                          /*No of Signals*/
        1,                            /*TotalSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_F192_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif
        &Did_extendedConfig_DcmDspDidInfo_SysRead1   /*ExtendedConfiguration*/
    }


,
    {
        0xF194,                        /*DID*/
        1,                          /*No of Signals*/
        1,                            /*TotalSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_F194_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif
        &Did_extendedConfig_DcmDspDidInfo_SysRead1   /*ExtendedConfiguration*/
    }


,
    {
        0xFD01,                        /*DID*/
        1,                          /*No of Signals*/
        2,                            /*TotalSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_FD01_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif
        &Did_extendedConfig_DcmDspDidInfo_SysRead1   /*ExtendedConfiguration*/
    }



};
#define DCM_STOP_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"


#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
FUNC(uint16,DCM_CODE) Dcm_DIDcalculateTableSize_u16(void)
{
  return ((uint16)(sizeof(Dcm_DIDConfig))/(uint16)(sizeof(Dcm_DIDConfig_tst)));
}
#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"







#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
boolean Dcm_ControlDtcSettingModecheck_b(
/* MR12 RULE 8.13 VIOLATION:The object addressed by the pointer parameter 'NegRespCode_u8' is not modified and so the pointer could be of type 'pointer to const' - Prototype is suggested by Autosar */
P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_INTERN_DATA) NegRespCode_u8)
{
    VAR(Std_ReturnType,AUTOMATIC) retVal_u8;
    VAR(boolean,AUTOMATIC) retVal_b;

    /* Call the DcmAppl API to check if the DTC Setting needs to be re-enabled */
    retVal_u8 =DcmAppl_UserDTCSettingEnableModeRuleService();

    if(retVal_u8!=E_OK)
    {
        (void)NegRespCode_u8;
        retVal_b = FALSE;
    }
    else
    {
        (void)NegRespCode_u8;
        retVal_b = TRUE;
    }
    return (retVal_b);

}
#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"




/**
 ***************************************************************************************************
            Ecu Reset (ER) Service
 ***************************************************************************************************
*/
#define DCM_START_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
/* Initialization of the parameters for the supported Reset Types */
CONST(Dcm_DspEcuReset_tst, DCM_CONST) Dcm_DspEcuResetType_cast[DCM_CFG_DSP_NUMRESETTYPE] =
{

    {
        RTE_MODE_DcmEcuReset_HARD,         /* DcmEcuReset Mode  for the ResetType */
        0x1,                              /* ResetType */
        DCM_RESET_NO_BOOT

    },

    {
        RTE_MODE_DcmEcuReset_KEYONOFF,         /* DcmEcuReset Mode  for the ResetType */
        0x2,                              /* ResetType */
        DCM_RESET_NO_BOOT

    },

    {
        RTE_MODE_DcmEcuReset_SOFT,         /* DcmEcuReset Mode  for the ResetType */
        0x3,                              /* ResetType */
        DCM_RESET_SYS_BOOT

    },

    {
        RTE_MODE_DcmEcuReset_BCRESET,         /* DcmEcuReset Mode  for the ResetType */
        0x60,                              /* ResetType */
        DCM_RESET_NO_BOOT

    }
};
#define DCM_STOP_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"





/**
 ***************************************************************************************************
        Communication Control Service
 ***************************************************************************************************
*/
#define DCM_START_SEC_VAR_INIT_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
P2FUNC(Std_ReturnType,DCM_APPL_CODE,Dcm_ComMUserReEnableModeRuleRef)(void) = &DcmAppl_UserCommCtrlReEnableModeRuleService;
#define DCM_STOP_SEC_VAR_INIT_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"

static FUNC(boolean,DCM_CODE) Dcm_ComMChannel_Can_Network_0_Channel_IsModeDefault ( void )
{
	VAR(boolean,AUTOMATIC)	dataRetValue_b;

	if ( SchM_Mode_Dcm_R_DcmCommunicationControl_ComMChannel_Can_Network_0_Channel() != RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_0_Channel_DCM_ENABLE_RX_TX_NORM_NM )
	{
		dataRetValue_b = FALSE;
	}
	else
	{
		dataRetValue_b = TRUE;
	}
	return (dataRetValue_b);
}

static FUNC(boolean,DCM_CODE) Dcm_ComMChannel_Can_Network_1_Channel_IsModeDefault ( void )
{
	VAR(boolean,AUTOMATIC)	dataRetValue_b;

	if ( SchM_Mode_Dcm_R_DcmCommunicationControl_ComMChannel_Can_Network_1_Channel() != RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_1_Channel_DCM_ENABLE_RX_TX_NORM_NM )
	{
		dataRetValue_b = FALSE;
	}
	else
	{
		dataRetValue_b = TRUE;
	}
	return (dataRetValue_b);
}

#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"

#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"

/* Function to map Dcm_CommunicationModeType to Rte_Communication Mode type for ComMChannel_Can_Network_0_Channel */
static FUNC(Std_ReturnType,DCM_CODE) Dcm_ComMChannel_Can_Network_0_Channel_SwitchIndication ( VAR(Dcm_CommunicationModeType,AUTOMATIC) Mode )
{
	VAR(Std_ReturnType,AUTOMATIC)	dataRetValue_u8;
	switch (Mode)
	{
		case DCM_ENABLE_RX_TX_NORM: dataRetValue_u8 = SchM_Switch_Dcm_DcmCommunicationControl_ComMChannel_Can_Network_0_Channel( RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_0_Channel_DCM_ENABLE_RX_TX_NORM);
			break;
		case DCM_ENABLE_RX_DISABLE_TX_NORM:  dataRetValue_u8 = SchM_Switch_Dcm_DcmCommunicationControl_ComMChannel_Can_Network_0_Channel(RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_0_Channel_DCM_ENABLE_RX_DISABLE_TX_NORM);
			break;
		case DCM_DISABLE_RX_ENABLE_TX_NORM: dataRetValue_u8 = SchM_Switch_Dcm_DcmCommunicationControl_ComMChannel_Can_Network_0_Channel(RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_0_Channel_DCM_DISABLE_RX_ENABLE_TX_NORM);
			break;
		case DCM_DISABLE_RX_TX_NORMAL:  dataRetValue_u8 = SchM_Switch_Dcm_DcmCommunicationControl_ComMChannel_Can_Network_0_Channel(RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_0_Channel_DCM_DISABLE_RX_TX_NORM);
			break;
		case DCM_ENABLE_RX_TX_NM:  dataRetValue_u8 = SchM_Switch_Dcm_DcmCommunicationControl_ComMChannel_Can_Network_0_Channel(RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_0_Channel_DCM_ENABLE_RX_TX_NM);
			break;
		case DCM_ENABLE_RX_DISABLE_TX_NM: dataRetValue_u8 = SchM_Switch_Dcm_DcmCommunicationControl_ComMChannel_Can_Network_0_Channel( RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_0_Channel_DCM_ENABLE_RX_DISABLE_TX_NM);
			break;
		case DCM_DISABLE_RX_ENABLE_TX_NM:  dataRetValue_u8 = SchM_Switch_Dcm_DcmCommunicationControl_ComMChannel_Can_Network_0_Channel(RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_0_Channel_DCM_DISABLE_RX_ENABLE_TX_NM);
			break;
		case DCM_DISABLE_RX_TX_NM:  dataRetValue_u8 = SchM_Switch_Dcm_DcmCommunicationControl_ComMChannel_Can_Network_0_Channel(RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_0_Channel_DCM_DISABLE_RX_TX_NM);
			break;
		case DCM_ENABLE_RX_TX_NORM_NM:  dataRetValue_u8 = SchM_Switch_Dcm_DcmCommunicationControl_ComMChannel_Can_Network_0_Channel(RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_0_Channel_DCM_ENABLE_RX_TX_NORM_NM);
			break;
		case DCM_ENABLE_RX_DISABLE_TX_NORM_NM:  dataRetValue_u8 = SchM_Switch_Dcm_DcmCommunicationControl_ComMChannel_Can_Network_0_Channel(RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_0_Channel_DCM_ENABLE_RX_DISABLE_TX_NORM_NM);
			break;
		case DCM_DISABLE_RX_ENABLE_TX_NORM_NM:  dataRetValue_u8 = SchM_Switch_Dcm_DcmCommunicationControl_ComMChannel_Can_Network_0_Channel(RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_0_Channel_DCM_DISABLE_RX_ENABLE_TX_NORM_NM);
			break;
		case DCM_DISABLE_RX_TX_NORM_NM:  dataRetValue_u8 = SchM_Switch_Dcm_DcmCommunicationControl_ComMChannel_Can_Network_0_Channel(RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_0_Channel_DCM_DISABLE_RX_TX_NORM_NM);
			break;
		default: dataRetValue_u8 = SchM_Switch_Dcm_DcmCommunicationControl_ComMChannel_Can_Network_0_Channel(RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_0_Channel_DCM_ENABLE_RX_TX_NORM);
			break;
	}
	return (dataRetValue_u8);
}

/* Function to map Dcm_CommunicationModeType to Rte_Communication Mode type for ComMChannel_Can_Network_1_Channel */
static FUNC(Std_ReturnType,DCM_CODE) Dcm_ComMChannel_Can_Network_1_Channel_SwitchIndication ( VAR(Dcm_CommunicationModeType,AUTOMATIC) Mode )
{
	VAR(Std_ReturnType,AUTOMATIC)	dataRetValue_u8;
	switch (Mode)
	{
		case DCM_ENABLE_RX_TX_NORM: dataRetValue_u8 = SchM_Switch_Dcm_DcmCommunicationControl_ComMChannel_Can_Network_1_Channel( RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_1_Channel_DCM_ENABLE_RX_TX_NORM);
			break;
		case DCM_ENABLE_RX_DISABLE_TX_NORM:  dataRetValue_u8 = SchM_Switch_Dcm_DcmCommunicationControl_ComMChannel_Can_Network_1_Channel(RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_1_Channel_DCM_ENABLE_RX_DISABLE_TX_NORM);
			break;
		case DCM_DISABLE_RX_ENABLE_TX_NORM: dataRetValue_u8 = SchM_Switch_Dcm_DcmCommunicationControl_ComMChannel_Can_Network_1_Channel(RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_1_Channel_DCM_DISABLE_RX_ENABLE_TX_NORM);
			break;
		case DCM_DISABLE_RX_TX_NORMAL:  dataRetValue_u8 = SchM_Switch_Dcm_DcmCommunicationControl_ComMChannel_Can_Network_1_Channel(RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_1_Channel_DCM_DISABLE_RX_TX_NORM);
			break;
		case DCM_ENABLE_RX_TX_NM:  dataRetValue_u8 = SchM_Switch_Dcm_DcmCommunicationControl_ComMChannel_Can_Network_1_Channel(RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_1_Channel_DCM_ENABLE_RX_TX_NM);
			break;
		case DCM_ENABLE_RX_DISABLE_TX_NM: dataRetValue_u8 = SchM_Switch_Dcm_DcmCommunicationControl_ComMChannel_Can_Network_1_Channel( RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_1_Channel_DCM_ENABLE_RX_DISABLE_TX_NM);
			break;
		case DCM_DISABLE_RX_ENABLE_TX_NM:  dataRetValue_u8 = SchM_Switch_Dcm_DcmCommunicationControl_ComMChannel_Can_Network_1_Channel(RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_1_Channel_DCM_DISABLE_RX_ENABLE_TX_NM);
			break;
		case DCM_DISABLE_RX_TX_NM:  dataRetValue_u8 = SchM_Switch_Dcm_DcmCommunicationControl_ComMChannel_Can_Network_1_Channel(RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_1_Channel_DCM_DISABLE_RX_TX_NM);
			break;
		case DCM_ENABLE_RX_TX_NORM_NM:  dataRetValue_u8 = SchM_Switch_Dcm_DcmCommunicationControl_ComMChannel_Can_Network_1_Channel(RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_1_Channel_DCM_ENABLE_RX_TX_NORM_NM);
			break;
		case DCM_ENABLE_RX_DISABLE_TX_NORM_NM:  dataRetValue_u8 = SchM_Switch_Dcm_DcmCommunicationControl_ComMChannel_Can_Network_1_Channel(RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_1_Channel_DCM_ENABLE_RX_DISABLE_TX_NORM_NM);
			break;
		case DCM_DISABLE_RX_ENABLE_TX_NORM_NM:  dataRetValue_u8 = SchM_Switch_Dcm_DcmCommunicationControl_ComMChannel_Can_Network_1_Channel(RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_1_Channel_DCM_DISABLE_RX_ENABLE_TX_NORM_NM);
			break;
		case DCM_DISABLE_RX_TX_NORM_NM:  dataRetValue_u8 = SchM_Switch_Dcm_DcmCommunicationControl_ComMChannel_Can_Network_1_Channel(RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_1_Channel_DCM_DISABLE_RX_TX_NORM_NM);
			break;
		default: dataRetValue_u8 = SchM_Switch_Dcm_DcmCommunicationControl_ComMChannel_Can_Network_1_Channel(RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_1_Channel_DCM_ENABLE_RX_TX_NORM);
			break;
	}
	return (dataRetValue_u8);
}

#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
#define DCM_START_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
/* Array for storing Special Subnet IDs supported and their corresponding ComM channels */
CONST (Dcm_Dsld_SpecificSubnetInfo, DCM_CONST) Dcm_specific_subnet_table[DCM_CFG_NUM_SPECIFIC_SUBNETS]=
{
	{
		&Dcm_ComMChannel_Can_Network_0_Channel_SwitchIndication,		/* Auto generated Dcm function to be called for invoking SchM Switch Indication */
		&Dcm_ComMChannel_Can_Network_0_Channel_IsModeDefault,		/* Auto generated Dcm function to be called for checking if Active Mode is Default */
		1,
		ComMConf_ComMChannel_ComMChannel_Can_Network_0_Channel
	}
,
	{
		&Dcm_ComMChannel_Can_Network_0_Channel_SwitchIndication,		/* Auto generated Dcm function to be called for invoking SchM Switch Indication */
		&Dcm_ComMChannel_Can_Network_0_Channel_IsModeDefault,		/* Auto generated Dcm function to be called for checking if Active Mode is Default */
		2,
		ComMConf_ComMChannel_ComMChannel_Can_Network_0_Channel
	}
,
	{
		&Dcm_ComMChannel_Can_Network_0_Channel_SwitchIndication,		/* Auto generated Dcm function to be called for invoking SchM Switch Indication */
		&Dcm_ComMChannel_Can_Network_0_Channel_IsModeDefault,		/* Auto generated Dcm function to be called for checking if Active Mode is Default */
		3,
		ComMConf_ComMChannel_ComMChannel_Can_Network_0_Channel
	}

};
#define DCM_STOP_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"

#define DCM_START_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
/*Array  stores the channelID info which is to be informed about the communication mode change if the subnet ID is 0  */
CONST(Dcm_Dsld_AllChannelsInfoType, DCM_CONST) Dcm_AllChannels_ForModeInfo[DCM_CFG_NUM_ALLCHANNELS_MODE_INFO]=
{
	{
		&Dcm_ComMChannel_Can_Network_0_Channel_SwitchIndication,  	/* Auto generated Dcm function to be called for invoking SchM Switch Indication */
		&Dcm_ComMChannel_Can_Network_0_Channel_IsModeDefault,		/* Auto generated Dcm function to be called for checking if Active Mode is Default */
 		ComMConf_ComMChannel_ComMChannel_Can_Network_0_Channel
	}
,
	{
		&Dcm_ComMChannel_Can_Network_1_Channel_SwitchIndication,  	/* Auto generated Dcm function to be called for invoking SchM Switch Indication */
		&Dcm_ComMChannel_Can_Network_1_Channel_IsModeDefault,		/* Auto generated Dcm function to be called for checking if Active Mode is Default */
 		ComMConf_ComMChannel_ComMChannel_Can_Network_1_Channel
	}
};
#define DCM_STOP_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"




/**
 ***************************************************************************************************
        Clear Diagnostic Information Service (0x14)
 ***************************************************************************************************
*/











