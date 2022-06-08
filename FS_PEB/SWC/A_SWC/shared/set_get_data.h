#ifndef set_get_data_h_
#define set_get_data_h_

#include "Platform_Types.h"
#pragma section ".data.CPU1_32"


typedef struct{
	float32 L2Sampling_IsU_Mon;
	float32 L2Sampling_IsV_Mon;
	float32 L2Sampling_IsW_Mon;
	uint16 L2Sampling_RslvSinP_VADC[32];
	uint16 L2Sampling_RslvSinN_VADC[32];
	uint16 L2Sampling_RslvCosP_VADC[32];
	uint16 L2Sampling_RslvCosN_VADC[32];
	uint16 L2Sampling_ExciBackP;
	uint16 L2Sampling_ExciBackN;
	uint16 L2Sampling_Exci18VLS_MON;
	uint16 L2Sampling_LEM5V_MON;
	sint32 L2Sampling_RslvSin;
    sint32 L2Sampling_RslvCos;
    uint16 L2Sampling_UBRWIDE_MON;
    uint16 L2Sampling_UBRNARR_MON;
    uint16 L2Sampling_UB_SBC_MON;
    uint16 L2Sampling_18VHS_MON;
    uint16 L2Sampling_3V3CPLD_MON;
    uint16 L2Sampling_1V8CPLD_MON;
	float32 NvM_AngAutoClbOffset;
	uint16 L2Com_ModeReq;
	float32 L2Com_NSetP;
	float32 L2Com_TrqSetP;
	float32 L2Sampling_DycU_Mon;
	float32 L2Sampling_DycV_Mon;
	float32 L2Sampling_DycW_Mon;
	float32 L2Com_HiPrecVolt;
	float32 HSPF_StrrTempFlt;
	float32 TRSP_iU;
	float32 TRSP_iW;
	float32 TRSP_iV;
	boolean TRSP_CurrRngErr;
	boolean TRSP_CurrSumErr;
	boolean TRSP_RslvRngErr;
	boolean TRSP_RslvSqrtErr;
	boolean TRSP_RslvExciRngErr;
	boolean TRSP_RslvSensVolRngErr;
	boolean TRSP_iPhasSensVolRngErr;
	float32 TRSP_RslvSin;
	float32 TRSP_RslvCos;
	boolean TRSP_OfstRngErr;
	boolean TRSP_ModeReqRngErr;
	boolean TRSP_NSetPRngErr;
	boolean TRSP_TrqSetPRngErr;
	boolean TRSP_OffsetRngErr;
	boolean TRSP_UBRVoltRngErr;
	boolean TRSP_18VHSVoltRngErr;
	boolean TRSP_3V3CPLDVoltRngErr;
	boolean TRSP_1V8CPLDVoltRngErr;
	float32 TCF_BlendTrq;
	boolean TCF_TrqCalcErr;
	uint8 TCF_TrqDir;
	uint8 TCF_nDir;
	float32 SWD_AgRtr;
	float32 SWD_AgRslv;
	float32 SWD_Spd;
	boolean STM_UintndSpdErr;
	boolean STM_UintndTrqErr;

	float32 L2Com_BMSVolt;
	//float32 L2Com_HiPrecVolt;
	boolean L2Com_DchgReq;
	boolean L2Com_Crash;
	boolean ADM_GlbDchgErr;
	boolean ADM_BMSVoltRngErr;
	boolean ADM_VoltCmpChkErr;
	boolean FRP_L2FaultReact;
	uint32 FRP_L2FaultinfoOut;
	float32 Agcomptime;
	float32 Spdcomptime;
}GetSet;

extern GetSet GetSet_signal;
#pragma section

#pragma section ".text.CPU1_Code" ax
extern void set_L2Sampling_IsU_Mon(float32 var);
extern float32 get_L2Sampling_IsU_Mon(void);

extern void set_L2Sampling_IsV_Mon(float32 var);
extern float32 get_L2Sampling_IsV_Mon(void);

extern void set_L2Sampling_IsW_Mon(float32 var);
extern float32 get_L2Sampling_IsW_Mon(void);

extern void set_L2Sampling_RslvSinP_VADC(uint16* var);
extern uint16 get_L2Sampling_RslvSinP_VADC(sint32 index);

extern void set_L2Sampling_RslvSinN_VADC(uint16* var);
extern uint16 get_L2Sampling_RslvSinN_VADC(sint32 index);

extern void set_L2Sampling_RslvCosP_VADC(uint16* var);
extern uint16 get_L2Sampling_RslvCosP_VADC(sint32 index);

extern void set_L2Sampling_RslvCosN_VADC(uint16* var);
extern uint16 get_L2Sampling_RslvCosN_VADC(sint32 index);

extern void set_L2Sampling_ExciBackP(uint16 var);
extern uint16 get_L2Sampling_ExciBackP(void);

extern void set_L2Sampling_ExciBackN(uint16 var);
extern uint16 get_L2Sampling_ExciBackN(void);

extern void set_L2Sampling_Exci18VLS_MON(uint16 var);
extern uint16 get_L2Sampling_Exci18VLS_MON(void);

extern void set_L2Sampling_LEM5V_MON(uint16 var);
extern uint16 get_L2Sampling_LEM5V_MON(void);

extern void set_L2Sampling_RslvSin(sint32 var);
extern sint32 get_L2Sampling_RslvCos(void);

extern void set_L2Sampling_RslvCos(sint32 var);
extern sint32 get_L2Sampling_RslvCos(void);

extern void set_L2Sampling_UBRWIDE_MON(uint16 var);
extern uint16 get_L2Sampling_UBRWIDE_MON(void);

extern void set_L2Sampling_UBRNARR_MON(uint16 var);
extern uint16 get_L2Sampling_UBRNARR_MON(void);

extern void set_L2Sampling_UB_SBC_MON(uint16 var);
extern uint16 get_L2Sampling_UB_SBC_MON(void);

extern void set_L2Sampling_18VHS_MON(uint16 var);
extern uint16 get_L2Sampling_18VHS_MON(void);

extern void set_L2Sampling_3V3CPLD_MON(uint16 var);
extern uint16 get_L2Sampling_3V3CPLD_MON(void);

extern void set_L2Sampling_1V8CPLD_MON(uint16 var);
extern uint16 get_L2Sampling_1V8CPLD_MON(void);

extern void set_NvM_AngAutoClbOffset(float32 var);
extern float32 get_NvM_AngAutoClbOffset(void);

extern void set_L2Com_ModeReq(uint16 var);
extern uint16 get_L2Com_ModeReq(void);

extern void set_L2Com_NSetP(float32 var);
extern float32 get_L2Com_NSetP(void);

extern void set_L2Com_TrqSetP(float32 var);
extern float32 get_L2Com_TrqSetP(void);

extern void set_L2Sampling_DycU_Mon(float32 var);
extern float32 get_L2Sampling_DycU_Mon(void);

extern void set_L2Sampling_DycV_Mon(float32 var);
extern float32 get_L2Sampling_DycV_Mon(void);

extern void set_L2Sampling_DycW_Mon(float32 var);
extern float32 get_L2Sampling_DycW_Mon(void);

extern void set_L2Com_HiPrecVolt(float32 var);
extern float32 get_L2Com_HiPrecVolt(void);

extern void set_HVSP_HiPrecVolt(float32 var);
extern float32 get_HVSP_HiPrecVolt(void);

extern void set_HSPF_StrrTempFlt(float32 var);
extern float32 get_HSPF_StrrTempFlt(void);

extern void set_TRSP_iU(float32 var);
extern float32 get_TRSP_iU(void);

extern void set_TRSP_iV(float32 var);
extern float32 get_TRSP_iV(void);

extern void set_TRSP_iW(float32 var);
extern float32 get_TRSP_iW(void);

extern void set_TRSP_CurrRngErr(boolean var);
extern boolean get_TRSP_CurrRngErr(void);

extern void set_TRSP_CurrSumErr(boolean var);
extern boolean get_TRSP_CurrSumErr(void);

extern void set_TRSP_RslvRngErr(boolean var);
extern boolean get_TRSP_RslvRngErr(void);

extern void set_TRSP_RslvSqrtErr(boolean var);
extern boolean get_TRSP_RslvSqrtErr(void);

extern void set_TRSP_RslvExciRngErr(boolean var);
extern boolean get_TRSP_RslvExciRngErr(void);

extern void set_TRSP_RslvSensVolErr(boolean var);
extern boolean get_TRSP_RslvSensVolErr(void);

extern void set_TRSP_iPhasSensVolErr(boolean var);
extern boolean get_TRSP_iPhasSensVolErr(void);

extern void set_TRSP_RslvSin(float32 var);
extern float32 get_TRSP_RslvSin(void);

extern void set_TRSP_RslvCos(float32 var);
extern float32 get_TRSP_RslvCos(void);

extern void set_TRSP_OfstRngErr(boolean var);
extern boolean get_TRSP_OfstRngErr(void);

extern void set_TRSP_ModeReqRngErr(boolean var);
extern boolean get_TRSP_ModeReqRngErr(void);

extern void set_TRSP_NSetPRngErr(boolean var);
extern boolean get_TRSP_NSetPRngErr(void);

extern void set_TRSP_TrqSetPRngErr(boolean var);
extern boolean get_TRSP_TrqSetPRngErr(void);

extern void set_TRSP_OffsetRngErr(boolean var);
extern boolean get_TRSP_OffsetRngErr(void);

extern void set_TRSP_UBRVoltRngErr(boolean var);
extern boolean get_TRSP_UBRVoltRngErr(void);

extern void set_TRSP_18VHSVoltRngErr(boolean var);
extern boolean get_TRSP_18VHSVoltRngErr(void);

extern void set_TRSP_3V3CPLDVoltRngErr(boolean var);
extern boolean get_TRSP_3V3CPLDVoltRngErr(void);

extern void set_TRSP_1V8CPLDVoltRngErr(boolean var);
extern boolean get_TRSP_1V8CPLDVoltRngErr(void);

extern void set_TCF_BlendTrq(float32 var);
extern float32 get_TCF_BlendTrq(void);

extern void set_TCF_TrqCalcErr(boolean var);
extern boolean get_TCF_TrqCalcErr(void);

extern void set_TCF_TrqDir(uint8 var);
extern uint8 get_TCF_TrqDir(void);

extern void set_TCF_nDir(uint8 var);
extern uint8 get_TCF_nDir(void);

extern void set_TRSP_AgRtr(float32 var);
extern float32 get_TRSP_AgRtr(void);

extern void set_SWD_AgRslv(float32 var);
extern float32 get_SWD_AgRslv(void);

extern void set_SWD_Spd(float32 var);
extern float32 get_SWD_Spd(void);

extern void set_STM_UintndSpdErr(boolean var);
extern boolean get_STM_UintndSpdErr(void);

extern void set_STM_UintndTrqErr(boolean var);
extern boolean get_STM_UintndTrqErr(void);

extern void set_L2Com_BMSVolt(float32 var);
extern void set_L2Com_DchgReq(boolean var);
//extern void set_L2Com_ModeReq(uint8 var);
extern void set_L2Com_Crash(boolean var);
extern void set_ADM_BMSVoltRngErr(boolean var);
extern void set_ADM_GlbDchgErr(boolean var);
extern void set_ADM_VoltCmpChkErr(boolean var);
extern void set_FRP_L2FaultinfoOut(uint32 var);
extern void set_FRP_L2FaultReact(boolean var);

extern float32 get_L2Com_BMSVolt(void);
extern boolean get_L2Com_DchgReq(void);
//extern uint8 get_L2Com_ModeReq(void);
extern boolean get_L2Com_Crash(void);
extern boolean get_ADM_BMSVoltRngErr(void);
extern boolean get_ADM_VoltCmpChkErr(void);
extern boolean get_ADM_GlbDchgErr(void);
extern uint32 get_FRP_L2FaultinfoOut(void);
extern boolean get_FFRP_L2FaultReact(void);
extern void set_CDD_TimecompAg(float32 var);
extern float32 get_CDD_TimecompAg(void);
extern void set_CDD_TimecompSpd(float32 var);
extern float32 get_CDD_TimecompSpd(void);

#pragma section
#endif
