

#include "set_get_data.h"

#pragma section ".data.CPU1_32"
GetSet GetSet_signal;
#pragma section
#pragma section ".text.CPU1_Code" ax
/*******************************************************************************
** Function Name	: None
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: set and get L2Sampling_IsU_Mon
*******************************************************************************/
void set_L2Sampling_IsU_Mon(float32 var)
{
	GetSet_signal.L2Sampling_IsU_Mon= var;
}

float32 get_L2Sampling_IsU_Mon(void)
{
	return GetSet_signal.L2Sampling_IsU_Mon ;
}

/*******************************************************************************
** Function Name	: None
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: set and get L2Sampling_IsV_Mon
*******************************************************************************/
void set_L2Sampling_IsV_Mon(float32 var)
{
	GetSet_signal.L2Sampling_IsV_Mon = var;
}

float32 get_L2Sampling_IsV_Mon(void)
{
	return GetSet_signal.L2Sampling_IsV_Mon;
}

/*******************************************************************************
** Function Name	: None
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: set and get L2Sampling_IsW_Mon
*******************************************************************************/
void set_L2Sampling_IsW_Mon(float32 var)
{
	GetSet_signal.L2Sampling_IsW_Mon = var;
}

float32 get_L2Sampling_IsW_Mon(void)
{
	return GetSet_signal.L2Sampling_IsW_Mon;
}
/*******************************************************************************
** Function Name	: None
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: set and get L2Sampling_RslvSinP_VADC
*******************************************************************************/
void set_L2Sampling_RslvSinP_VADC(uint16* var)
{
	uint8 i;
	for(i = 0; i < 32; i++)
	{
		GetSet_signal.L2Sampling_RslvSinP_VADC[i] = *(var + i);
	}
}

uint16 get_L2Sampling_RslvSinP_VADC(sint32 index)
{
	return GetSet_signal.L2Sampling_RslvSinP_VADC[index];
}
/*******************************************************************************
** Function Name	: None
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: set and get L2Sampling_RslvSinN_VADC
*******************************************************************************/
void set_L2Sampling_RslvSinN_VADC(uint16* var)
{
	uint8 i;
	for(i = 0; i < 32; i++)
	{
		GetSet_signal.L2Sampling_RslvSinN_VADC[i] = *(var + i);
	}
}

uint16 get_L2Sampling_RslvSinN_VADC(sint32 index )
{
	return GetSet_signal.L2Sampling_RslvSinN_VADC[index];
}
/*******************************************************************************
** Function Name	: None
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: set and get L2Sampling_RslvCosP_VADC
*******************************************************************************/
void set_L2Sampling_RslvCosP_VADC(uint16* var)
{
	uint8 i;
	for(i = 0; i < 32; i++)
	{
		GetSet_signal.L2Sampling_RslvCosP_VADC[i] = *(var + i);
	}
}

uint16 get_L2Sampling_RslvCosP_VADC(sint32 index)
{
	return GetSet_signal.L2Sampling_RslvCosP_VADC[index];
}
/*******************************************************************************
** Function Name	: None
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: set and get L2Sampling_RslvCosN_VADC
*******************************************************************************/
void set_L2Sampling_RslvCosN_VADC(uint16* var)
{
	uint8 i;
	for(i = 0; i < 32; i++)
	{
		GetSet_signal.L2Sampling_RslvCosN_VADC[i] = *(var + i);
	}
}

uint16 get_L2Sampling_RslvCosN_VADC(sint32 index)
{
	return GetSet_signal.L2Sampling_RslvCosN_VADC[index];
}
/*******************************************************************************
** Function Name	: None
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: set and get L2Sampling_ExciBackP
*******************************************************************************/
void set_L2Sampling_ExciBackP(uint16 var)
{
	GetSet_signal.L2Sampling_ExciBackP = var;
}

uint16 get_L2Sampling_ExciBackP(void)
{
	return GetSet_signal.L2Sampling_ExciBackP;
}
/*******************************************************************************
** Function Name	: None
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: set and get L2Sampling_ExciBackN
*******************************************************************************/
void set_L2Sampling_ExciBackN(uint16 var)
{
	GetSet_signal.L2Sampling_ExciBackN = var;
}

uint16 get_L2Sampling_ExciBackN(void)
{
	return GetSet_signal.L2Sampling_ExciBackN;
}

/*******************************************************************************
** Function Name	: None
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: set and get L2Sampling_Exci18VLS_MON
*******************************************************************************/
void set_L2Sampling_Exci18VLS_MON(uint16 var)
{
	GetSet_signal.L2Sampling_Exci18VLS_MON = var;
}

uint16 get_L2Sampling_Exci18VLS_MON(void)
{
	return GetSet_signal.L2Sampling_Exci18VLS_MON;
}

/*******************************************************************************
** Function Name	: None
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: set and get L2Sampling_LEM5V_MON
*******************************************************************************/
void set_L2Sampling_LEM5V_MON(uint16 var)
{
	GetSet_signal.L2Sampling_LEM5V_MON = var;
}

uint16 get_L2Sampling_LEM5V_MON(void)
{
	return GetSet_signal.L2Sampling_LEM5V_MON;
}

/*******************************************************************************
** Function Name	: None
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: set and get L2Sampling_RslvSin_MON
*******************************************************************************/
void set_L2Sampling_RslvSin(sint32 var)
{
	GetSet_signal.L2Sampling_RslvSin = var;
}

sint32 get_L2Sampling_RslvSin(void)
{
	return GetSet_signal.L2Sampling_RslvSin;
}
/*******************************************************************************
** Function Name	: None
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: set and get L2Sampling_RslvCos_MON
*******************************************************************************/
void set_L2Sampling_RslvCos(sint32 var)
{
	GetSet_signal.L2Sampling_RslvCos = var;
}

sint32 get_L2Sampling_RslvCos(void)
{
	return GetSet_signal.L2Sampling_RslvCos;
}

/*******************************************************************************
** Function Name	: None
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: set and get L2Sampling_UBRWIDE_MON
*******************************************************************************/
void set_L2Sampling_UBRWIDE_MON(uint16 var)
{
	GetSet_signal.L2Sampling_UBRWIDE_MON = var;
}

uint16 get_L2Sampling_UBRWIDE_MON(void)
{
	return GetSet_signal.L2Sampling_UBRWIDE_MON;
}

/*******************************************************************************
** Function Name	: None
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: set and get L2Sampling_UBRNARR_MON
*******************************************************************************/
void set_L2Sampling_UBRNARR_MON(uint16 var)
{
	GetSet_signal.L2Sampling_UBRNARR_MON = var;
}

uint16 get_L2Sampling_UBRNARR_MON(void)
{
	return GetSet_signal.L2Sampling_UBRNARR_MON;
}

/*******************************************************************************
** Function Name	: None
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: set and get L2Sampling_UB_SBC_MON
*******************************************************************************/
void set_L2Sampling_UB_SBC_MON(uint16 var)
{
	GetSet_signal.L2Sampling_UB_SBC_MON = var;
}

uint16 get_L2Sampling_UB_SBC_MON(void)
{
	return GetSet_signal.L2Sampling_UB_SBC_MON;
}
/*******************************************************************************
** Function Name	: None
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: set and get L2Sampling_18VHS_MON
*******************************************************************************/
void set_L2Sampling_18VHS_MON(uint16 var)
{
	GetSet_signal.L2Sampling_18VHS_MON = var;
}

uint16 get_L2Sampling_18VHS_MON(void)
{
	return GetSet_signal.L2Sampling_18VHS_MON;
}
/*******************************************************************************
** Function Name	: None
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: set and get L2Sampling_3V3CPLD_MON
*******************************************************************************/
void set_L2Sampling_3V3CPLD_MON(uint16 var)
{
	GetSet_signal.L2Sampling_3V3CPLD_MON = var;
}

uint16 get_L2Sampling_3V3CPLD_MON(void)
{
	return GetSet_signal.L2Sampling_3V3CPLD_MON;
}

/*******************************************************************************
** Function Name	: None
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: set and get L2Sampling_1V8CPLD_MON
*******************************************************************************/
void set_L2Sampling_1V8CPLD_MON(uint16 var)
{
	GetSet_signal.L2Sampling_1V8CPLD_MON = var;
}

uint16 get_L2Sampling_1V8CPLD_MON(void)
{
	return GetSet_signal.L2Sampling_1V8CPLD_MON;
}
/*******************************************************************************
** Function Name	: None
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: set and get NvM_AngAutoClbOffset
*******************************************************************************/
void set_NvM_AngAutoClbOffset(float32 var)
{
	GetSet_signal.NvM_AngAutoClbOffset = var;
}

float32 get_NvM_AngAutoClbOffset(void)
{
	return GetSet_signal.NvM_AngAutoClbOffset;
}


/*******************************************************************************
** Function Name	: None
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: set and get L2Com_ModeReq
*******************************************************************************/
void set_L2Com_ModeReq(uint16 var)
{
	GetSet_signal.L2Com_ModeReq = var;
}

uint16 get_L2Com_ModeReq(void)
{
	return GetSet_signal.L2Com_ModeReq;
}

/*******************************************************************************
** Function Name	: None
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: set and get L2Com_NSetP
*******************************************************************************/
void set_L2Com_NSetP(float32 var)
{
	GetSet_signal.L2Com_NSetP = var;
}

float32 get_L2Com_NSetP(void)
{
	return GetSet_signal.L2Com_NSetP;
}

/*******************************************************************************
** Function Name	: None
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: set and get L2Com_TrqSetP
*******************************************************************************/
void set_L2Com_TrqSetP(float32 var)
{
	GetSet_signal.L2Com_TrqSetP = var;
}

float32 get_L2Com_TrqSetP(void)
{
	return GetSet_signal.L2Com_TrqSetP;
}

/*******************************************************************************
** Function Name	: None
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: set and get L2Sampling_DycU_Mon
*******************************************************************************/
void set_L2Sampling_DycU_Mon(float32 var)
{
	GetSet_signal.L2Sampling_DycU_Mon = var;
}

float32 get_L2Sampling_DycU_Mon(void)
{
	return GetSet_signal.L2Sampling_DycU_Mon;
}

/*******************************************************************************
** Function Name	: None
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: set and get L2Sampling_DycV_Mon
*******************************************************************************/
void set_L2Sampling_DycV_Mon(float32 var)
{
	GetSet_signal.L2Sampling_DycV_Mon = var;
}

float32 get_L2Sampling_DycV_Mon(void)
{
	return GetSet_signal.L2Sampling_DycV_Mon;
}


/*******************************************************************************
** Function Name	: None
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: set and get L2Sampling_DycW_Mon
*******************************************************************************/
void set_L2Sampling_DycW_Mon(float32 var)
{
	GetSet_signal.L2Sampling_DycW_Mon = var;
}

float32 get_L2Sampling_DycW_Mon(void)
{
	return GetSet_signal.L2Sampling_DycW_Mon;
}

/*******************************************************************************
** Function Name	: None
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: set and get HVSP_HiPrecVolt
*******************************************************************************/
void set_L2Com_HiPrecVolt(float32 var)
{
	GetSet_signal.L2Com_HiPrecVolt = var;
}

float32 get_L2Com_HiPrecVolt(void)
{
	return GetSet_signal.L2Com_HiPrecVolt;
}
/*******************************************************************************
** Function Name	: None
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: set and get HSPF_StrrTempFlt
*******************************************************************************/
void set_HSPF_StrrTempFlt(float32 var)
{
	GetSet_signal.HSPF_StrrTempFlt = var;
}

float32 get_HSPF_StrrTempFlt(void)
{
	return GetSet_signal.HSPF_StrrTempFlt;
}
/*******************************************************************************
** Function Name	: None
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: set and get TRSP_iU
*******************************************************************************/
void set_TRSP_iU(float32 var)
{
	GetSet_signal.TRSP_iU = var;
}

float32 get_TRSP_iU(void)
{
	return GetSet_signal.TRSP_iU;
}

/*******************************************************************************
** Function Name	: None
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: set and get TRSP_iV
*******************************************************************************/
void set_TRSP_iV(float32 var)
{
	GetSet_signal.TRSP_iV = var;
}

float32 get_TRSP_iV(void)
{
	return GetSet_signal.TRSP_iV;
}


/*******************************************************************************
** Function Name	: None
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: set and get TRSP_iW
*******************************************************************************/
void set_TRSP_iW(float32 var)
{
	GetSet_signal.TRSP_iW = var;
}

float32 get_TRSP_iW(void)
{
	return GetSet_signal.TRSP_iW;
}

/*******************************************************************************
** Function Name	: None
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: set and get TRSP_CurrRngErr
*******************************************************************************/
void set_TRSP_CurrRngErr(boolean var)
{
	GetSet_signal.TRSP_CurrRngErr = var;
}

boolean get_TRSP_CurrRngErr(void)
{
	return GetSet_signal.TRSP_CurrRngErr;
}

/*******************************************************************************
** Function Name	: None
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: set and get TRSP_CurrSumErr
*******************************************************************************/
void set_TRSP_CurrSumErr(boolean var)
{
	GetSet_signal.TRSP_CurrSumErr = var;
}

boolean get_TRSP_CurrSumErr(void)
{
	return GetSet_signal.TRSP_CurrSumErr;
}

/*******************************************************************************
** Function Name	: None
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: set and get TRSP_RslvRngErr
*******************************************************************************/
void set_TRSP_RslvRngErr(boolean var)
{
	GetSet_signal.TRSP_RslvRngErr = var;
}

boolean get_TRSP_RslvRngErr(void)
{
	return GetSet_signal.TRSP_RslvRngErr;
}

/*******************************************************************************
** Function Name	: None
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: set and get TRSP_RslvSqrtErr
*******************************************************************************/
void set_TRSP_RslvSqrtErr(boolean var)
{
	GetSet_signal.TRSP_RslvSqrtErr = var;
}

boolean get_TRSP_RslvSqrtErr(void)
{
	return GetSet_signal.TRSP_RslvSqrtErr;
}


/*******************************************************************************
** Function Name	: None
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: set and get TRSP_RslvExciRngErr
*******************************************************************************/
void set_TRSP_RslvExciRngErr(boolean var)
{
	GetSet_signal.TRSP_RslvExciRngErr = var;
}

boolean get_TRSP_RslvExciRngErr(void)
{
	return GetSet_signal.TRSP_RslvExciRngErr;
}


/*******************************************************************************
** Function Name	: None
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: set and get TRSP_RslvSensVolRngErr
*******************************************************************************/
void set_TRSP_RslvSensVolRngErr(boolean var)
{
	GetSet_signal.TRSP_RslvSensVolRngErr = var;
}

boolean get_TRSP_RslvSensVolRngErr(void)
{
	return GetSet_signal.TRSP_RslvSensVolRngErr;
}

/*******************************************************************************
** Function Name	: None
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: set and get TRSP_iPhasSensVolRngErr
*******************************************************************************/
void set_TRSP_iPhasSensVolRngErr(boolean var)
{
	GetSet_signal.TRSP_iPhasSensVolRngErr = var;
}

boolean get_TRSP_iPhasSensVolRngErr(void)
{
	return GetSet_signal.TRSP_iPhasSensVolRngErr;
}


/*******************************************************************************
** Function Name	: None
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: set and get TRSP_RslvSin
*******************************************************************************/
void set_TRSP_RslvSin(float32 var)
{
	GetSet_signal.TRSP_RslvSin = var;
}

float32 get_TRSP_RslvSin(void)
{
	return GetSet_signal.TRSP_RslvSin;
}

/*******************************************************************************
** Function Name	: None
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: set and get TRSP_RslvCos
*******************************************************************************/
void set_TRSP_RslvCos(float32 var)
{
	GetSet_signal.TRSP_RslvCos = var;
}

float32 get_TRSP_RslvCos(void)
{
	return GetSet_signal.TRSP_RslvCos;
}

/*******************************************************************************
** Function Name	: None
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: set and get TRSP_OfstRngErr
*******************************************************************************/
void set_TRSP_OfstRngErr(boolean var)
{
	GetSet_signal.TRSP_OfstRngErr = var;
}

boolean get_TRSP_OfstRngErr(void)
{
	return GetSet_signal.TRSP_OfstRngErr;
}


/*******************************************************************************
** Function Name	: None
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: set and get TRSP_ModeReqRngErr
*******************************************************************************/
void set_TRSP_ModeReqRngErr(boolean var)
{
	GetSet_signal.TRSP_ModeReqRngErr = var;
}

boolean get_TRSP_ModeReqRngErr(void)
{
	return GetSet_signal.TRSP_ModeReqRngErr;
}

/*******************************************************************************
** Function Name	: None
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: set and get TRSP_NSetPRngErr
*******************************************************************************/
void set_TRSP_NSetPRngErr(boolean var)
{
	GetSet_signal.TRSP_NSetPRngErr = var;
}

boolean get_TRSP_NSetPRngErr(void)
{
	return GetSet_signal.TRSP_NSetPRngErr;
}


/*******************************************************************************
** Function Name	: None
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: set and get TRSP_TrqSetPRngErr
*******************************************************************************/
void set_TRSP_TrqSetPRngErr(boolean var)
{
	GetSet_signal.TRSP_TrqSetPRngErr = var;
}

boolean get_TRSP_TrqSetPRngErr(void)
{
	return GetSet_signal.TRSP_TrqSetPRngErr;
}
/*******************************************************************************
** Function Name	: None
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: set and get STM_UintndTrqErr
*******************************************************************************/
void set_TRSP_OffsetRngErr(boolean var)
{
	GetSet_signal.TRSP_OffsetRngErr = var;
}

boolean get_TRSP_OffsetRngErr(void)
{
	return GetSet_signal.TRSP_OffsetRngErr;
}

/*******************************************************************************
** Function Name	: None
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: set and get TRSP_UBRVolRngErr
*******************************************************************************/
void set_TRSP_UBRVoltRngErr(boolean var)
{
	GetSet_signal.TRSP_UBRVoltRngErr = var;
}

boolean get_TRSP_UBRVoltRngErr(void)
{
	return GetSet_signal.TRSP_UBRVoltRngErr;
}

/*******************************************************************************
** Function Name	: None
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: set and get TRSP_18VHSVoltRngErr
*******************************************************************************/
void set_TRSP_18VHSVoltRngErr(boolean var)
{
	GetSet_signal.TRSP_18VHSVoltRngErr = var;
}

boolean get_TRSP_18VHSVoltRngErr(void)
{
	return GetSet_signal.TRSP_18VHSVoltRngErr;
}

/*******************************************************************************
** Function Name	: None
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: set and get 3V3CPLDVolRngErr
*******************************************************************************/
void set_TRSP_3V3CPLDVoltRngErr(boolean var)
{
	GetSet_signal.TRSP_3V3CPLDVoltRngErr = var;
}

boolean get_TRSP_3V3CPLDVoltRngErr(void)
{
	return GetSet_signal.TRSP_3V3CPLDVoltRngErr;
}

/*******************************************************************************
** Function Name	: None
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: set and get TRSP_1V8CPLDVoltRngErr
*******************************************************************************/
void set_TRSP_1V8CPLDVoltRngErr(boolean var)
{
	GetSet_signal.TRSP_1V8CPLDVoltRngErr = var;
}

boolean get_TRSP_1V8CPLDVoltRngErr(void)
{
	return GetSet_signal.TRSP_1V8CPLDVoltRngErr;
}


/*******************************************************************************
** Function Name	: None
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: set and get TCF_BlendTrq
*******************************************************************************/
void set_TCF_BlendTrq(float32 var)
{
	GetSet_signal.TCF_BlendTrq = var;
}

float32 get_TCF_BlendTrq(void)
{
	return GetSet_signal.TCF_BlendTrq;
}

/*******************************************************************************
** Function Name	: None
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: set and get TCF_TrqCalcErr
*******************************************************************************/
void set_TCF_TrqCalcErr(boolean var)
{
	GetSet_signal.TCF_TrqCalcErr = var;
}

boolean get_TCF_TrqCalcErr(void)
{
	return GetSet_signal.TCF_TrqCalcErr;
}


/*******************************************************************************
** Function Name	: None
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: set and get TCF_TrqDir
*******************************************************************************/
void set_TCF_TrqDir(uint8 var)
{
	GetSet_signal.TCF_TrqDir = var;
}

uint8 get_TCF_TrqDir(void)
{
	return GetSet_signal.TCF_TrqDir;
}


/*******************************************************************************
** Function Name	: None
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: set and get TCF_nDir
*******************************************************************************/
void set_TCF_nDir(uint8 var)
{
	GetSet_signal.TCF_nDir = var;
}

uint8 get_TCF_nDir(void)
{
	return GetSet_signal.TCF_nDir;
}


/*******************************************************************************
** Function Name	: None
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: set and get SWD_AgRtr
*******************************************************************************/
void set_TRSP_AgRtr(float32 var)
{
	GetSet_signal.SWD_AgRtr = var;
}

float32 get_TRSP_AgRtr(void)
{
	return GetSet_signal.SWD_AgRtr;
}

/*******************************************************************************
** Function Name	: None
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: set and get SWD_AgRtr
*******************************************************************************/
void set_SWD_AgRslv(float32 var)
{
	GetSet_signal.SWD_AgRslv = var;
}

float32 get_SWD_AgRslv(void)
{
	return GetSet_signal.SWD_AgRslv;
}
/*******************************************************************************
** Function Name	: None
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: set and get SWD_Spd
*******************************************************************************/
void set_SWD_Spd(float32 var)
{
	GetSet_signal.SWD_Spd = var;
}

float32 get_SWD_Spd(void)
{
	return GetSet_signal.SWD_Spd;
}

/*******************************************************************************
** Function Name	: None
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: set and get STM_UintndSpdErr
*******************************************************************************/
void set_STM_UintndSpdErr(boolean var)
{
	GetSet_signal.STM_UintndSpdErr = var;
}

boolean get_STM_UintndSpdErr(void)
{
	return GetSet_signal.STM_UintndSpdErr;
}

/*******************************************************************************
** Function Name	: None
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: set and get STM_UintndTrqErr
*******************************************************************************/
void set_STM_UintndTrqErr(boolean var)
{
	GetSet_signal.STM_UintndTrqErr = var;
}

boolean get_STM_UintndTrqErr(void)
{
	return GetSet_signal.STM_UintndTrqErr;
}
/*******************************************************************************
** Function Name	: None
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: set and get STM_UintndTrqErr
*******************************************************************************/
void set_L2Com_BMSVolt(float32 var)
{
	GetSet_signal.L2Com_BMSVolt = var;

}

float32 get_L2Com_BMSVolt(void)
{
	return GetSet_signal.L2Com_BMSVolt;
}
/*******************************************************************************
** Function Name	: None
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: set and get STM_UintndTrqErr
*******************************************************************************/
void set_L2Com_DchgReq(boolean var)
{
	GetSet_signal.L2Com_DchgReq = var;
}
boolean get_L2Com_DchgReq(void)
{
	return GetSet_signal.L2Com_DchgReq ;
}
/*******************************************************************************
** Function Name	: None
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: set and get STM_UintndTrqErr
*******************************************************************************/
void set_L2Com_Crash(boolean var)
{
	GetSet_signal.L2Com_Crash = var;
}

boolean get_L2Com_Crash(void)
{
    return GetSet_signal.L2Com_Crash ;
}
/*******************************************************************************
** Function Name	: None
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: set and get STM_UintndTrqErr
*******************************************************************************/
void set_ADM_GlbDchgErr(boolean var)
{
	GetSet_signal.ADM_GlbDchgErr = var ;
}

boolean get_ADM_GlbDchgErr(void)
{
	return GetSet_signal.ADM_GlbDchgErr;
}
/*******************************************************************************
** Function Name	: None
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: set and get STM_UintndTrqErr
*******************************************************************************/
void set_ADM_BMSVoltRngErr(boolean var)
{
	GetSet_signal.ADM_BMSVoltRngErr = var;
}

boolean get_ADM_BMSVoltRngErr(void)
{
	return GetSet_signal.ADM_BMSVoltRngErr;
}
/*******************************************************************************
** Function Name	: None
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: set and get STM_UintndTrqErr
*******************************************************************************/
void set_ADM_VoltCmpChkErr(boolean var)
{
	GetSet_signal.ADM_VoltCmpChkErr = var;
}

boolean get_ADM_VoltCmpChkErr(void)
{
	return GetSet_signal.ADM_BMSVoltRngErr;
}
/*******************************************************************************
** Function Name	: None
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: set and get STM_UintndTrqErr
*******************************************************************************/
void set_FRP_L2FaultinfoOut(uint32 var)
{
	GetSet_signal.FRP_L2FaultinfoOut = var;
}
uint32 get_FRP_L2FaultinfoOut(void)
{
	return GetSet_signal.FRP_L2FaultinfoOut;
}
/*******************************************************************************
** Function Name	: None
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: set and get STM_UintndTrqErr
*******************************************************************************/
void set_FRP_L2FaultReact(boolean var)
{
	GetSet_signal.FRP_L2FaultReact = var;
}
boolean get_FFRP_L2FaultReact(void)
{
	return GetSet_signal.FRP_L2FaultReact;
}
/*******************************************************************************
** Function Name	: None
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: set and get STM_UintndTrqErr
*******************************************************************************/
void set_HVSP_HiPrecVolt(float32 var)
{
	GetSet_signal.L2Com_HiPrecVolt = var;
}
float32 get_HVSP_HiPrecVolt(void)
{
	return GetSet_signal.L2Com_HiPrecVolt;
}
/*******************************************************************************
** Function Name	: None
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: set and get CDD_TimecompAg_f32
*******************************************************************************/
void set_CDD_TimecompAg(float32 var)
{
	GetSet_signal.Agcomptime = var;
}
float32 get_CDD_TimecompAg(void)
{
	return GetSet_signal.Agcomptime;
}
/*******************************************************************************
** Function Name	: None
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: set and get CDD_TimecompSpd_f32
*******************************************************************************/
void set_CDD_TimecompSpd(float32 var)
{
	GetSet_signal.Spdcomptime = var;
}
float32 get_CDD_TimecompSpd(void)
{
	return GetSet_signal.Spdcomptime;
}

#pragma section
