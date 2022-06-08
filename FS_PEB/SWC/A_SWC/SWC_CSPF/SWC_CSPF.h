/*
 * File: SWC_CSPF.h
 *
 * Code generated for Simulink model 'SWC_CSPF'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Wed Nov 11 13:42:07 2020
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_SWC_CSPF_h_
#define RTW_HEADER_SWC_CSPF_h_
#include <math.h>
#ifndef SWC_CSPF_COMMON_INCLUDES_
# define SWC_CSPF_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_SWC_CSPF.h"
#endif                                 /* SWC_CSPF_COMMON_INCLUDES_ */

#include "SWC_CSPF_types.h"

/* Macros for accessing real-time model data structure */

/* Exported data define */

/* Definition for custom storage class: Define */
#define CSPF_GLB_IGBTCLOSE_u8          0U                        /* Referenced by: '<S46>/CSPF_GLB_IGBTCLOSE_u8' */
#define CSPF_GLB_PWMRUN_u8             3U                        /* Referenced by: '<S46>/CSPF_GLB_PWMRUN_u8' */
#define CSPF_IGBTASCDownCPLD_u8        2U                        /* Referenced by: '<S100>/Constant5' */
#define CSPF_IGBTASCUpCPLD_u8          1U                        /* Referenced by: '<S100>/Constant' */
#define CSPF_IGBTAscDwn_u8             2U                        /* Referenced by: '<S100>/Constant6' */
#define CSPF_IGBTAscUp_u8              1U                        /* Referenced by: '<S100>/Constant3' */
#define CSPF_IGBTCloseCPLD_u8          0U                        /* Referenced by: '<S100>/Constant1' */
#define CSPF_IGBTRunCPLD_u8            3U                        /* Referenced by: '<S100>/Constant4' */
#define CSPF_IGBTRun_u8                3U                        /* Referenced by: '<S100>/Constant2' */
#define CSPF_IGBTclose_u8              0U                        /* Referenced by: '<S100>/Constant24' */

/* Block states (default storage) for system '<Root>' */
typedef struct tag_DW_SWC_CSPF_T {
  uint8 UnitDelay_DSTATE;              /* '<S87>/Unit Delay' */
  uint8 UnitDelay_DSTATE_j;            /* '<S100>/Unit Delay' */
} DW_SWC_CSPF_T;

/* Block states (default storage) */
extern DW_SWC_CSPF_T SWC_CSPF_DW;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern float32 VAR_Cspf_TraTrqCurr_f32;/* '<S84>/Switch' */
extern float32 VAR_Cspf_TraUdcCurr_f32;/* '<S85>/Switch' */
extern float32 VAR_Cspf_TraNCurr_f32;  /* '<S83>/Switch' */
extern float32 VAR_Cspf_TraisCurr_f32; /* '<S86>/Switch' */
extern float32 VAR_Cspf_TraagRtrELecSnsr_f32;/* '<S94>/Switch' */
extern float32 VAR_Cspf_Traisd_f32;    /* '<S96>/Switch' */
extern float32 VAR_Cspf_Traisq_f32;    /* '<S97>/Switch' */
extern float32 VAR_Cspf_TraTrqCurrWoDmpC_f32;/* '<S99>/Switch' */
extern float32 VAR_Cspf_TraOfsAL_f32;  /* '<S98>/Switch' */
extern float32 VAR_Cspf_TraiGBTTempU_f32;/* '<S90>/Switch' */
extern float32 VAR_Cspf_TraiGBTTempV_f32;/* '<S91>/Switch' */
extern float32 VAR_Cspf_TraiGBTTempW_f32;/* '<S92>/Switch' */
extern float32 VAR_Cspf_TraTempCurrStr1_f32;/* '<S93>/Switch' */
extern float32 VAR_Cspf_TraTempCurrStr2_f32;/* '<S89>/Switch' */
extern float32 VAR_Cspf_TraTempCurrCooL_f32;/* '<S82>/Switch' */
extern float32 VAR_Cspf_TraidcCurr_f32;/* '<S18>/Switch' */
extern float32 VAR_Cspf_TraTrqAbsMax_f32;/* '<S21>/Switch' */
extern float32 VAR_Cspf_TraTrqAbsMin_f32;/* '<S22>/Switch' */
extern float32 VAR_Cspf_TraUT30Curr_f32;/* '<S23>/Switch' */
extern uint16 VAR_Cspf_TraHwVer_u16;   /* '<S103>/Switch' */
extern uint16 VAR_Cspf_TrabDernDrvBoardTemp_u16;/* '<S34>/Switch' */
extern uint16 VAR_Cspf_TraCpldVer_u16; /* '<S43>/Switch' */
extern uint16 VAR_Cspf_TraHvMcuVer_u16;/* '<S44>/Switch' */
extern uint8 VAR_Cspf_TrastMode_u8;    /* '<S88>/Switch' */
extern uint8 VAR_Cspf_TraflgOfsClbSuc_u8;/* '<S95>/Switch' */
extern uint8 VAR_Cspf_TrastGateDrv_u8; /* '<S101>/Switch' */
extern uint8 VAR_Cspf_TrastDischg_u8;  /* '<S102>/Switch' */
extern uint8 VAR_Cspf_TrabDernCAN_u8;  /* '<S16>/Switch' */
extern uint8 VAR_Cspf_TrabDernN_u8;    /* '<S15>/Switch' */
extern uint8 VAR_Cspf_TrabDernOvridc_u8;/* '<S24>/Switch' */
extern uint8 VAR_Cspf_TrabDernOvrUdc_u8;/* '<S25>/Switch' */
extern uint8 VAR_Cspf_TrabDernStrTemp_u8;/* '<S26>/Switch' */
extern uint8 VAR_Cspf_TrabDernTempCooL_u8;/* '<S27>/Switch' */
extern uint8 VAR_Cspf_TrabDernTempiGBT_u8;/* '<S28>/Switch' */
extern uint8 VAR_Cspf_TrabDernUndrUdc_u8;/* '<S31>/Switch' */
extern uint8 VAR_Cspf_TrastTrqEmMax_u8;/* '<S19>/Switch' */
extern uint8 VAR_Cspf_TrastTrqEmMin_u8;/* '<S20>/Switch' */
extern uint8 VAR_Cspf_TrabDernTrqMax_u8;/* '<S29>/Switch' */
extern uint8 VAR_Cspf_TrabDernTrqMin_u8;/* '<S30>/Switch' */
extern uint8 VAR_Cspf_TrabReadyHV_u8;  /* '<S17>/Switch' */
extern uint8 VAR_Cspf_TraFailCode1_u8; /* '<S35>/Switch' */
extern uint8 VAR_Cspf_TraFailCode2_u8; /* '<S36>/Switch' */
extern uint8 VAR_Cspf_TraFailCode3_u8; /* '<S37>/Switch' */
extern uint8 VAR_Cspf_TraFailCode4_u8; /* '<S38>/Switch' */
extern uint8 VAR_Cspf_TraFailCode5_u8; /* '<S39>/Switch' */
extern uint8 VAR_Cspf_TraFailCode6_u8; /* '<S40>/Switch' */
extern uint8 VAR_Cspf_TraFailCode7_u8; /* '<S41>/Switch' */
extern uint8 VAR_Cspf_TraFailCode8_u8; /* '<S42>/Switch' */

/* Exported data declaration */
#pragma section ".rodata.Calib_32"

/* Declaration for custom storage class: iEDS_Parameter */
extern const volatile uint16 CAL_Cspf_CodeVer_u16;
                               /* Referenced by: '<S33>/CAL_Cspf_CodeVer_u16' */
extern const volatile uint8 CAL_Cspf_CpldVer_u8;/* Referenced by: '<S43>/Constant3' */
extern const volatile uint16 CAL_Cspf_DataVer_u16;
                               /* Referenced by: '<S33>/CAL_Cspf_DataVer_u16' */
extern const volatile uint8 CAL_Cspf_FailCode1_u8;/* Referenced by: '<S35>/Constant3' */
extern const volatile uint8 CAL_Cspf_FailCode2_u8;/* Referenced by: '<S36>/Constant3' */
extern const volatile uint8 CAL_Cspf_FailCode3_u8;/* Referenced by: '<S37>/Constant3' */
extern const volatile uint8 CAL_Cspf_FailCode4_u8;/* Referenced by: '<S38>/Constant3' */
extern const volatile uint8 CAL_Cspf_FailCode5_u8;/* Referenced by: '<S39>/Constant3' */
extern const volatile uint8 CAL_Cspf_FailCode6_u8;/* Referenced by: '<S40>/Constant3' */
extern const volatile uint8 CAL_Cspf_FailCode7_u8;/* Referenced by: '<S41>/Constant3' */
extern const volatile uint8 CAL_Cspf_FailCode8_u8;/* Referenced by: '<S42>/Constant3' */
extern const volatile uint8 CAL_Cspf_HvMcuVer_u8;/* Referenced by: '<S44>/Constant3' */
extern const volatile uint16 CAL_Cspf_HwVer_u16;/* Referenced by: '<S103>/Constant3' */
extern const volatile float32 CAL_Cspf_IdcMax_f32;/* Referenced by: '<S11>/Constant3' */
extern const volatile float32 CAL_Cspf_IdcMin_f32;/* Referenced by: '<S10>/Constant3' */
extern const volatile float32 CAL_Cspf_IsFlt_f32;/* Referenced by: '<S86>/Constant3' */
extern const volatile float32 CAL_Cspf_KpHighNCtL_f32;/* Referenced by: '<S58>/Constant3' */
extern const volatile float32 CAL_Cspf_KpLowNCtl_f32;/* Referenced by: '<S61>/Constant3' */
extern const volatile uint8 CAL_Cspf_MainReLay_u8;/* Referenced by: '<S57>/Constant3' */
extern const volatile float32 CAL_Cspf_NDiffMax_f32;/* Referenced by: '<S59>/Constant3' */
extern const volatile float32 CAL_Cspf_NSetP_f32;/* Referenced by: '<S70>/Constant3' */
extern const volatile float32 CAL_Cspf_TraTrqMax_f32;/* Referenced by: '<S21>/Constant3' */
extern const volatile float32 CAL_Cspf_TraTrqMin_f32;/* Referenced by: '<S22>/Constant3' */
extern const volatile float32 CAL_Cspf_TrqCurrWoDmpC_f32;/* Referenced by: '<S99>/Constant3' */
extern const volatile float32 CAL_Cspf_TrqDmpLim_f32;/* Referenced by: '<S75>/Constant3' */
extern const volatile float32 CAL_Cspf_TrqDmpMax_f32;/* Referenced by: '<S76>/Constant3' */
extern const volatile float32 CAL_Cspf_TrqMaxNCtL_f32;/* Referenced by: '<S60>/Constant3' */
extern const volatile float32 CAL_Cspf_TrqMax_f32;/* Referenced by: '<S64>/Constant3' */
extern const volatile float32 CAL_Cspf_TrqMechFlt_f32;/* Referenced by: '<S84>/Constant3' */
extern const volatile float32 CAL_Cspf_TrqMinNCtl_f32;/* Referenced by: '<S62>/Constant3' */
extern const volatile float32 CAL_Cspf_TrqMin_f32;/* Referenced by: '<S65>/Constant3' */
extern const volatile float32 CAL_Cspf_TrqSLope_f32;/* Referenced by: '<S63>/Constant3' */
extern const volatile float32 CAL_Cspf_TrqSetP_f32;/* Referenced by: '<S67>/Constant3' */
extern const volatile float32 CAL_Cspf_UdcMax_f32;/* Referenced by: '<S9>/Constant3' */
extern const volatile float32 CAL_Cspf_UdcMin_f32;/* Referenced by: '<S8>/Constant3' */
extern const volatile float32 CAL_Cspf_agOffset_f32;/* Referenced by: '<S98>/Constant3' */
extern const volatile float32 CAL_Cspf_agRtrEe_f32;/* Referenced by: '<S94>/Constant3' */
extern const volatile uint8 CAL_Cspf_bDernCAN_u8;/* Referenced by: '<S16>/Constant3' */
extern const volatile uint8 CAL_Cspf_bDernCoolantTemp_u8;/* Referenced by: '<S27>/Constant3' */
extern const volatile uint8 CAL_Cspf_bDernDbcTemp_u8;/* Referenced by: '<S28>/Constant3' */
extern const volatile uint16 CAL_Cspf_bDernDrvBoardTemp_u16;/* Referenced by: '<S34>/Constant3' */
extern const volatile uint8 CAL_Cspf_bDernExcMax_u8;/* Referenced by: '<S29>/Constant3' */
extern const volatile uint8 CAL_Cspf_bDernExcMin_u8;/* Referenced by: '<S30>/Constant3' */
extern const volatile uint8 CAL_Cspf_bDernMtrSpd_u8;/* Referenced by: '<S15>/Constant3' */
extern const volatile uint8 CAL_Cspf_bDernOvrIdc_u8;/* Referenced by: '<S24>/Constant3' */
extern const volatile uint8 CAL_Cspf_bDernOvrUdc_u8;/* Referenced by: '<S25>/Constant3' */
extern const volatile uint8 CAL_Cspf_bDernStrTemp_u8;/* Referenced by: '<S26>/Constant3' */
extern const volatile uint8 CAL_Cspf_bDernUndrUdc_u8;/* Referenced by: '<S31>/Constant3' */
extern const volatile uint8 CAL_Cspf_bReadyHV_u8;/* Referenced by: '<S17>/Constant3' */
extern const volatile boolean CAL_Cspf_flgCpldVerSwt_b;/* Referenced by: '<S43>/Constant2' */
extern const volatile boolean CAL_Cspf_flgCrashSwt_b;/* Referenced by: '<S49>/Constant2' */
extern const volatile boolean CAL_Cspf_flgCrash_b;/* Referenced by: '<S49>/Constant3' */
extern const volatile boolean CAL_Cspf_flgDchaReqSwt_b;/* Referenced by: '<S50>/Constant2' */
extern const volatile boolean CAL_Cspf_flgDchaReq_b;/* Referenced by: '<S50>/Constant3' */
extern const volatile boolean CAL_Cspf_flgFailCode1Swt_b;/* Referenced by: '<S35>/Constant2' */
extern const volatile boolean CAL_Cspf_flgFailCode2Swt_b;/* Referenced by: '<S36>/Constant2' */
extern const volatile boolean CAL_Cspf_flgFailCode3Swt_b;/* Referenced by: '<S37>/Constant2' */
extern const volatile boolean CAL_Cspf_flgFailCode4Swt_b;/* Referenced by: '<S38>/Constant2' */
extern const volatile boolean CAL_Cspf_flgFailCode5Swt_b;/* Referenced by: '<S39>/Constant2' */
extern const volatile boolean CAL_Cspf_flgFailCode6Swt_b;/* Referenced by: '<S40>/Constant2' */
extern const volatile boolean CAL_Cspf_flgFailCode7Swt_b;/* Referenced by: '<S41>/Constant2' */
extern const volatile boolean CAL_Cspf_flgFailCode8Swt_b;/* Referenced by: '<S42>/Constant2' */
extern const volatile boolean CAL_Cspf_flgHvMcuVerSwt_b;/* Referenced by: '<S44>/Constant2' */
extern const volatile boolean CAL_Cspf_flgHwVerSwt_b;/* Referenced by: '<S103>/Constant2' */
extern const volatile boolean CAL_Cspf_flgIdcMaxSwt_b;/* Referenced by: '<S11>/Constant2' */
extern const volatile boolean CAL_Cspf_flgIdcMinSwt_b;/* Referenced by: '<S10>/Constant2' */
extern const volatile boolean CAL_Cspf_flgIsFltSwt_b;/* Referenced by: '<S86>/Constant2' */
extern const volatile boolean CAL_Cspf_flgKpHighNCtLSwt_b;/* Referenced by: '<S58>/Constant2' */
extern const volatile boolean CAL_Cspf_flgKpLowNCtlSwt_b;/* Referenced by: '<S61>/Constant2' */
extern const volatile boolean CAL_Cspf_flgNDiffMaxSwt_b;/* Referenced by: '<S59>/Constant2' */
extern const volatile boolean CAL_Cspf_flgNSetPSwt_b;/* Referenced by: '<S70>/Constant2' */
extern const volatile boolean CAL_Cspf_flgOfsClbSucSwt_b;/* Referenced by: '<S95>/Constant2' */
extern const volatile uint8 CAL_Cspf_flgOfsClbSuc_u8;/* Referenced by: '<S95>/Constant3' */
extern const volatile boolean CAL_Cspf_flgTraTrqMaxSwt_b;/* Referenced by: '<S21>/Constant2' */
extern const volatile boolean CAL_Cspf_flgTraTrqMinSwt_b;/* Referenced by: '<S22>/Constant2' */
extern const volatile boolean CAL_Cspf_flgTrqCurrWoDmpCSwt_b;/* Referenced by: '<S99>/Constant2' */
extern const volatile boolean CAL_Cspf_flgTrqDmpMaxSwt_b;/* Referenced by: '<S76>/Constant2' */
extern const volatile boolean CAL_Cspf_flgTrqDmpMinSwt_b;/* Referenced by: '<S75>/Constant2' */
extern const volatile boolean CAL_Cspf_flgTrqMaxNCtLSwt_b;/* Referenced by: '<S60>/Constant2' */
extern const volatile boolean CAL_Cspf_flgTrqMaxSwt_b;/* Referenced by: '<S64>/Constant2' */
extern const volatile boolean CAL_Cspf_flgTrqMechFltSwt_b;/* Referenced by: '<S84>/Constant2' */
extern const volatile boolean CAL_Cspf_flgTrqMinNCtlSwt_b;/* Referenced by: '<S62>/Constant2' */
extern const volatile boolean CAL_Cspf_flgTrqMinSwt_b;/* Referenced by: '<S65>/Constant2' */
extern const volatile boolean CAL_Cspf_flgTrqSetPSwt_b;/* Referenced by: '<S67>/Constant2' */
extern const volatile boolean CAL_Cspf_flgUdcMaxSwt_b;/* Referenced by: '<S9>/Constant2' */
extern const volatile boolean CAL_Cspf_flgUdcMinSwt_b;/* Referenced by: '<S8>/Constant2' */
extern const volatile boolean CAL_Cspf_flgagOffsetSwt_b;/* Referenced by: '<S98>/Constant2' */
extern const volatile boolean CAL_Cspf_flgagRtrEeSwt_b;/* Referenced by: '<S94>/Constant2' */
extern const volatile boolean CAL_Cspf_flgbDernCANSwt_b;/* Referenced by: '<S16>/Constant2' */
extern const volatile boolean CAL_Cspf_flgbDernCoolantTempSwt_b;/* Referenced by: '<S27>/Constant2' */
extern const volatile boolean CAL_Cspf_flgbDernDbcTempSwt_b;/* Referenced by: '<S28>/Constant2' */
extern const volatile boolean CAL_Cspf_flgbDernDrvBoardTempSwt_b;/* Referenced by: '<S34>/Constant2' */
extern const volatile boolean CAL_Cspf_flgbDernExcMaxSwt_b;/* Referenced by: '<S29>/Constant2' */
extern const volatile boolean CAL_Cspf_flgbDernExcMinSwt_b;/* Referenced by: '<S30>/Constant2' */
extern const volatile boolean CAL_Cspf_flgbDernMtrSpdSwt_b;/* Referenced by: '<S15>/Constant2' */
extern const volatile boolean CAL_Cspf_flgbDernOvrIdcSwt_b;/* Referenced by: '<S24>/Constant2' */
extern const volatile boolean CAL_Cspf_flgbDernOvrUdcSwt_b;/* Referenced by: '<S25>/Constant2' */
extern const volatile boolean CAL_Cspf_flgbDernStrTempSwt_b;/* Referenced by: '<S26>/Constant2' */
extern const volatile boolean CAL_Cspf_flgbDernUndrUdcSwt_b;/* Referenced by: '<S31>/Constant2' */
extern const volatile boolean CAL_Cspf_flgbReadyHVSwt_b;/* Referenced by: '<S17>/Constant2' */
extern const volatile boolean CAL_Cspf_flgcTrqSLopeSwt_b;/* Referenced by: '<S63>/Constant2' */
extern const volatile boolean CAL_Cspf_flgiDActSlowFltSwt_b;/* Referenced by: '<S96>/Constant2' */
extern const volatile boolean CAL_Cspf_flgiDcLnkEstFltSwt_b;/* Referenced by: '<S18>/Constant2' */
extern const volatile boolean CAL_Cspf_flgiQActSlowFltSwt_b;/* Referenced by: '<S97>/Constant2' */
extern const volatile boolean CAL_Cspf_flgkDmpSwt_b;/* Referenced by: '<S72>/Constant2' */
extern const volatile boolean CAL_Cspf_flgnSlowFltSwt_b;/* Referenced by: '<S83>/Constant2' */
extern const volatile boolean CAL_Cspf_flgstDisChgSwt_b;/* Referenced by: '<S102>/Constant2' */
extern const volatile boolean CAL_Cspf_flgstDmpCtLReqSwt_b;/* Referenced by: '<S74>/Constant2' */
extern const volatile boolean CAL_Cspf_flgstGateDrvSwt_b;/* Referenced by: '<S101>/Constant2' */
extern const volatile boolean CAL_Cspf_flgstMainReLaySwt_b;/* Referenced by: '<S57>/Constant2' */
extern const volatile boolean CAL_Cspf_flgstModeReqSwt_b;/* Referenced by: '<S66>/Constant2' */
extern const volatile boolean CAL_Cspf_flgstModeSwt_b;/* Referenced by: '<S88>/Constant2' */
extern const volatile boolean CAL_Cspf_flgstTrqEmMaxSwt_b;/* Referenced by: '<S19>/Constant2' */
extern const volatile boolean CAL_Cspf_flgstTrqEmMinSwt_b;/* Referenced by: '<S20>/Constant2' */
extern const volatile boolean CAL_Cspf_flgtCoolantTempFltSwt_b;/* Referenced by: '<S82>/Constant2' */
extern const volatile boolean CAL_Cspf_flgtDBCTempUFltSwt_b;/* Referenced by: '<S90>/Constant2' */
extern const volatile boolean CAL_Cspf_flgtDBCTempVFltSwt_b;/* Referenced by: '<S91>/Constant2' */
extern const volatile boolean CAL_Cspf_flgtDBCTempWFltSwt_b;/* Referenced by: '<S92>/Constant2' */
extern const volatile boolean CAL_Cspf_flgtStrrTemp1FltSwt_b;/* Referenced by: '<S93>/Constant2' */
extern const volatile boolean CAL_Cspf_flgtStrrTemp2FltSwt_b;/* Referenced by: '<S89>/Constant2' */
extern const volatile boolean CAL_Cspf_flguDcLnkSlowFltSwt_b;/* Referenced by: '<S85>/Constant2' */
extern const volatile boolean CAL_Cspf_flguKl30FltSwt_b;/* Referenced by: '<S23>/Constant2' */
extern const volatile float32 CAL_Cspf_iDActSlowFlt_f32;/* Referenced by: '<S96>/Constant3' */
extern const volatile float32 CAL_Cspf_iDcLnkEstFlt_f32;/* Referenced by: '<S18>/Constant3' */
extern const volatile float32 CAL_Cspf_iQActSlowFlt_f32;/* Referenced by: '<S97>/Constant3' */
extern const volatile float32 CAL_Cspf_kDmp_f32;/* Referenced by: '<S72>/Constant3' */
extern const volatile float32 CAL_Cspf_nSlowFlt_f32;/* Referenced by: '<S83>/Constant3' */
extern const volatile uint8 CAL_Cspf_stDisChg_u8;/* Referenced by: '<S102>/Constant3' */
extern const volatile uint8 CAL_Cspf_stDmpCtLReq_u8;/* Referenced by: '<S74>/Constant3' */
extern const volatile uint8 CAL_Cspf_stGateDrv_u8;/* Referenced by: '<S101>/Constant3' */
extern const volatile uint8 CAL_Cspf_stModeReq_u8;/* Referenced by: '<S66>/Constant3' */
extern const volatile uint8 CAL_Cspf_stMode_u8;/* Referenced by: '<S88>/Constant3' */
extern const volatile uint8 CAL_Cspf_stTrqEmMax_u8;/* Referenced by: '<S19>/Constant3' */
extern const volatile uint8 CAL_Cspf_stTrqEmMin_u8;/* Referenced by: '<S20>/Constant3' */
extern const volatile float32 CAL_Cspf_tCoolantTempFlt_f32;/* Referenced by: '<S82>/Constant3' */
extern const volatile float32 CAL_Cspf_tDBCTempUFlt_f32;/* Referenced by: '<S90>/Constant3' */
extern const volatile float32 CAL_Cspf_tDBCTempVFlt_f32;/* Referenced by: '<S91>/Constant3' */
extern const volatile float32 CAL_Cspf_tDBCTempWFlt_f32;/* Referenced by: '<S92>/Constant3' */
extern const volatile float32 CAL_Cspf_tStrrTemp1Flt_f32;/* Referenced by: '<S93>/Constant3' */
extern const volatile float32 CAL_Cspf_tStrrTemp2Flt_f32;/* Referenced by: '<S89>/Constant3' */
extern const volatile float32 CAL_Cspf_uDcLnkSlowFlt_f32;/* Referenced by: '<S85>/Constant3' */
extern const volatile float32 CAL_Cspf_uKl30Flt_f32;/* Referenced by: '<S23>/Constant3' */

#pragma section

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S7>/Constant2' : Unused code path elimination
 * Block '<S7>/Constant3' : Unused code path elimination
 * Block '<S7>/Data Type Conversion' : Unused code path elimination
 * Block '<S7>/Switch' : Unused code path elimination
 * Block '<S55>/Constant2' : Unused code path elimination
 * Block '<S55>/Constant3' : Unused code path elimination
 * Block '<S55>/Data Type Conversion' : Unused code path elimination
 * Block '<S55>/Switch' : Unused code path elimination
 * Block '<S56>/Constant2' : Unused code path elimination
 * Block '<S56>/Constant3' : Unused code path elimination
 * Block '<S56>/Data Type Conversion' : Unused code path elimination
 * Block '<S56>/Switch' : Unused code path elimination
 * Block '<S68>/Constant2' : Unused code path elimination
 * Block '<S68>/Constant3' : Unused code path elimination
 * Block '<S68>/Data Type Conversion' : Unused code path elimination
 * Block '<S68>/Switch' : Unused code path elimination
 * Block '<S69>/Constant2' : Unused code path elimination
 * Block '<S69>/Constant3' : Unused code path elimination
 * Block '<S69>/Data Type Conversion' : Unused code path elimination
 * Block '<S69>/Switch' : Unused code path elimination
 * Block '<S71>/Constant2' : Unused code path elimination
 * Block '<S71>/Constant3' : Unused code path elimination
 * Block '<S71>/Data Type Conversion' : Unused code path elimination
 * Block '<S71>/Switch' : Unused code path elimination
 * Block '<S73>/Constant2' : Unused code path elimination
 * Block '<S73>/Constant3' : Unused code path elimination
 * Block '<S73>/Data Type Conversion' : Unused code path elimination
 * Block '<S73>/Switch' : Unused code path elimination
 * Block '<S46>/CSPF_GLB_DWSHORTCIRCUIT_u8' : Unused code path elimination
 * Block '<S46>/CSPF_GLB_UPSHORTCIRCUIT_u8' : Unused code path elimination
 * Block '<S8>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S9>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S10>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S11>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S18>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S19>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S20>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S21>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S22>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S23>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S35>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S36>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S37>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S38>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S39>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S40>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S41>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S42>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S44>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S57>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S49>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S50>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S58>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S59>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S60>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S61>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S62>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S63>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S64>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S65>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S66>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S67>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S70>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S72>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S74>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S75>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S76>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S83>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S84>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S85>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S86>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S88>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S89>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S90>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S91>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S92>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S93>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S94>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S96>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S97>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S98>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S99>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S101>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S102>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S82>/Data Type Conversion' : Eliminate redundant data type conversion
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'SWC_CSPF'
 * '<S1>'   : 'SWC_CSPF/RE_SWC_CSPF_100ms_sys'
 * '<S2>'   : 'SWC_CSPF/RE_SWC_CSPF_10ms_sys'
 * '<S3>'   : 'SWC_CSPF/RE_SWC_CSPF_Init'
 * '<S4>'   : 'SWC_CSPF/RE_SWC_CSPF_100ms_sys/CSPF_Rec_100ms'
 * '<S5>'   : 'SWC_CSPF/RE_SWC_CSPF_100ms_sys/CSPF_Tra_100ms'
 * '<S6>'   : 'SWC_CSPF/RE_SWC_CSPF_100ms_sys/CSPF_Rec_100ms/VCU01'
 * '<S7>'   : 'SWC_CSPF/RE_SWC_CSPF_100ms_sys/CSPF_Rec_100ms/VCU01/Subsystem'
 * '<S8>'   : 'SWC_CSPF/RE_SWC_CSPF_100ms_sys/CSPF_Rec_100ms/VCU01/Subsystem1'
 * '<S9>'   : 'SWC_CSPF/RE_SWC_CSPF_100ms_sys/CSPF_Rec_100ms/VCU01/Subsystem2'
 * '<S10>'  : 'SWC_CSPF/RE_SWC_CSPF_100ms_sys/CSPF_Rec_100ms/VCU01/Subsystem3'
 * '<S11>'  : 'SWC_CSPF/RE_SWC_CSPF_100ms_sys/CSPF_Rec_100ms/VCU01/Subsystem4'
 * '<S12>'  : 'SWC_CSPF/RE_SWC_CSPF_100ms_sys/CSPF_Tra_100ms/CSDTra_100ms'
 * '<S13>'  : 'SWC_CSPF/RE_SWC_CSPF_100ms_sys/CSPF_Tra_100ms/CSDTra_100ms_sub2'
 * '<S14>'  : 'SWC_CSPF/RE_SWC_CSPF_100ms_sys/CSPF_Tra_100ms/CSDTra_100ms/PEB02'
 * '<S15>'  : 'SWC_CSPF/RE_SWC_CSPF_100ms_sys/CSPF_Tra_100ms/CSDTra_100ms/PEB02/Subsystem1'
 * '<S16>'  : 'SWC_CSPF/RE_SWC_CSPF_100ms_sys/CSPF_Tra_100ms/CSDTra_100ms/PEB02/Subsystem10'
 * '<S17>'  : 'SWC_CSPF/RE_SWC_CSPF_100ms_sys/CSPF_Tra_100ms/CSDTra_100ms/PEB02/Subsystem11'
 * '<S18>'  : 'SWC_CSPF/RE_SWC_CSPF_100ms_sys/CSPF_Tra_100ms/CSDTra_100ms/PEB02/Subsystem12'
 * '<S19>'  : 'SWC_CSPF/RE_SWC_CSPF_100ms_sys/CSPF_Tra_100ms/CSDTra_100ms/PEB02/Subsystem13'
 * '<S20>'  : 'SWC_CSPF/RE_SWC_CSPF_100ms_sys/CSPF_Tra_100ms/CSDTra_100ms/PEB02/Subsystem14'
 * '<S21>'  : 'SWC_CSPF/RE_SWC_CSPF_100ms_sys/CSPF_Tra_100ms/CSDTra_100ms/PEB02/Subsystem15'
 * '<S22>'  : 'SWC_CSPF/RE_SWC_CSPF_100ms_sys/CSPF_Tra_100ms/CSDTra_100ms/PEB02/Subsystem16'
 * '<S23>'  : 'SWC_CSPF/RE_SWC_CSPF_100ms_sys/CSPF_Tra_100ms/CSDTra_100ms/PEB02/Subsystem17'
 * '<S24>'  : 'SWC_CSPF/RE_SWC_CSPF_100ms_sys/CSPF_Tra_100ms/CSDTra_100ms/PEB02/Subsystem2'
 * '<S25>'  : 'SWC_CSPF/RE_SWC_CSPF_100ms_sys/CSPF_Tra_100ms/CSDTra_100ms/PEB02/Subsystem3'
 * '<S26>'  : 'SWC_CSPF/RE_SWC_CSPF_100ms_sys/CSPF_Tra_100ms/CSDTra_100ms/PEB02/Subsystem4'
 * '<S27>'  : 'SWC_CSPF/RE_SWC_CSPF_100ms_sys/CSPF_Tra_100ms/CSDTra_100ms/PEB02/Subsystem5'
 * '<S28>'  : 'SWC_CSPF/RE_SWC_CSPF_100ms_sys/CSPF_Tra_100ms/CSDTra_100ms/PEB02/Subsystem6'
 * '<S29>'  : 'SWC_CSPF/RE_SWC_CSPF_100ms_sys/CSPF_Tra_100ms/CSDTra_100ms/PEB02/Subsystem7'
 * '<S30>'  : 'SWC_CSPF/RE_SWC_CSPF_100ms_sys/CSPF_Tra_100ms/CSDTra_100ms/PEB02/Subsystem8'
 * '<S31>'  : 'SWC_CSPF/RE_SWC_CSPF_100ms_sys/CSPF_Tra_100ms/CSDTra_100ms/PEB02/Subsystem9'
 * '<S32>'  : 'SWC_CSPF/RE_SWC_CSPF_100ms_sys/CSPF_Tra_100ms/CSDTra_100ms_sub2/PEB05'
 * '<S33>'  : 'SWC_CSPF/RE_SWC_CSPF_100ms_sys/CSPF_Tra_100ms/CSDTra_100ms_sub2/PEB06'
 * '<S34>'  : 'SWC_CSPF/RE_SWC_CSPF_100ms_sys/CSPF_Tra_100ms/CSDTra_100ms_sub2/Subsystem11'
 * '<S35>'  : 'SWC_CSPF/RE_SWC_CSPF_100ms_sys/CSPF_Tra_100ms/CSDTra_100ms_sub2/PEB05/Subsystem18'
 * '<S36>'  : 'SWC_CSPF/RE_SWC_CSPF_100ms_sys/CSPF_Tra_100ms/CSDTra_100ms_sub2/PEB05/Subsystem19'
 * '<S37>'  : 'SWC_CSPF/RE_SWC_CSPF_100ms_sys/CSPF_Tra_100ms/CSDTra_100ms_sub2/PEB05/Subsystem20'
 * '<S38>'  : 'SWC_CSPF/RE_SWC_CSPF_100ms_sys/CSPF_Tra_100ms/CSDTra_100ms_sub2/PEB05/Subsystem21'
 * '<S39>'  : 'SWC_CSPF/RE_SWC_CSPF_100ms_sys/CSPF_Tra_100ms/CSDTra_100ms_sub2/PEB05/Subsystem22'
 * '<S40>'  : 'SWC_CSPF/RE_SWC_CSPF_100ms_sys/CSPF_Tra_100ms/CSDTra_100ms_sub2/PEB05/Subsystem23'
 * '<S41>'  : 'SWC_CSPF/RE_SWC_CSPF_100ms_sys/CSPF_Tra_100ms/CSDTra_100ms_sub2/PEB05/Subsystem24'
 * '<S42>'  : 'SWC_CSPF/RE_SWC_CSPF_100ms_sys/CSPF_Tra_100ms/CSDTra_100ms_sub2/PEB05/Subsystem25'
 * '<S43>'  : 'SWC_CSPF/RE_SWC_CSPF_100ms_sys/CSPF_Tra_100ms/CSDTra_100ms_sub2/PEB06/Subsystem26'
 * '<S44>'  : 'SWC_CSPF/RE_SWC_CSPF_100ms_sys/CSPF_Tra_100ms/CSDTra_100ms_sub2/PEB06/Subsystem27'
 * '<S45>'  : 'SWC_CSPF/RE_SWC_CSPF_10ms_sys/CSPF_Rec_10ms'
 * '<S46>'  : 'SWC_CSPF/RE_SWC_CSPF_10ms_sys/CSPF_Tra_10ms'
 * '<S47>'  : 'SWC_CSPF/RE_SWC_CSPF_10ms_sys/CSPF_Rec_10ms/CanSig_Select'
 * '<S48>'  : 'SWC_CSPF/RE_SWC_CSPF_10ms_sys/CSPF_Rec_10ms/CanSig_Select/BMS01'
 * '<S49>'  : 'SWC_CSPF/RE_SWC_CSPF_10ms_sys/CSPF_Rec_10ms/CanSig_Select/Subsystem1'
 * '<S50>'  : 'SWC_CSPF/RE_SWC_CSPF_10ms_sys/CSPF_Rec_10ms/CanSig_Select/Subsystem22'
 * '<S51>'  : 'SWC_CSPF/RE_SWC_CSPF_10ms_sys/CSPF_Rec_10ms/CanSig_Select/VCU02'
 * '<S52>'  : 'SWC_CSPF/RE_SWC_CSPF_10ms_sys/CSPF_Rec_10ms/CanSig_Select/VCU03'
 * '<S53>'  : 'SWC_CSPF/RE_SWC_CSPF_10ms_sys/CSPF_Rec_10ms/CanSig_Select/VCU04'
 * '<S54>'  : 'SWC_CSPF/RE_SWC_CSPF_10ms_sys/CSPF_Rec_10ms/CanSig_Select/VCU05'
 * '<S55>'  : 'SWC_CSPF/RE_SWC_CSPF_10ms_sys/CSPF_Rec_10ms/CanSig_Select/BMS01/Subsystem23'
 * '<S56>'  : 'SWC_CSPF/RE_SWC_CSPF_10ms_sys/CSPF_Rec_10ms/CanSig_Select/BMS01/Subsystem25'
 * '<S57>'  : 'SWC_CSPF/RE_SWC_CSPF_10ms_sys/CSPF_Rec_10ms/CanSig_Select/BMS01/Subsystem26'
 * '<S58>'  : 'SWC_CSPF/RE_SWC_CSPF_10ms_sys/CSPF_Rec_10ms/CanSig_Select/VCU02/Subsystem'
 * '<S59>'  : 'SWC_CSPF/RE_SWC_CSPF_10ms_sys/CSPF_Rec_10ms/CanSig_Select/VCU02/Subsystem1'
 * '<S60>'  : 'SWC_CSPF/RE_SWC_CSPF_10ms_sys/CSPF_Rec_10ms/CanSig_Select/VCU02/Subsystem2'
 * '<S61>'  : 'SWC_CSPF/RE_SWC_CSPF_10ms_sys/CSPF_Rec_10ms/CanSig_Select/VCU02/Subsystem24'
 * '<S62>'  : 'SWC_CSPF/RE_SWC_CSPF_10ms_sys/CSPF_Rec_10ms/CanSig_Select/VCU02/Subsystem3'
 * '<S63>'  : 'SWC_CSPF/RE_SWC_CSPF_10ms_sys/CSPF_Rec_10ms/CanSig_Select/VCU03/Subsystem4'
 * '<S64>'  : 'SWC_CSPF/RE_SWC_CSPF_10ms_sys/CSPF_Rec_10ms/CanSig_Select/VCU03/Subsystem5'
 * '<S65>'  : 'SWC_CSPF/RE_SWC_CSPF_10ms_sys/CSPF_Rec_10ms/CanSig_Select/VCU03/Subsystem6'
 * '<S66>'  : 'SWC_CSPF/RE_SWC_CSPF_10ms_sys/CSPF_Rec_10ms/CanSig_Select/VCU04/Subsystem10'
 * '<S67>'  : 'SWC_CSPF/RE_SWC_CSPF_10ms_sys/CSPF_Rec_10ms/CanSig_Select/VCU04/Subsystem11'
 * '<S68>'  : 'SWC_CSPF/RE_SWC_CSPF_10ms_sys/CSPF_Rec_10ms/CanSig_Select/VCU04/Subsystem7'
 * '<S69>'  : 'SWC_CSPF/RE_SWC_CSPF_10ms_sys/CSPF_Rec_10ms/CanSig_Select/VCU04/Subsystem8'
 * '<S70>'  : 'SWC_CSPF/RE_SWC_CSPF_10ms_sys/CSPF_Rec_10ms/CanSig_Select/VCU04/Subsystem9'
 * '<S71>'  : 'SWC_CSPF/RE_SWC_CSPF_10ms_sys/CSPF_Rec_10ms/CanSig_Select/VCU05/Subsystem12'
 * '<S72>'  : 'SWC_CSPF/RE_SWC_CSPF_10ms_sys/CSPF_Rec_10ms/CanSig_Select/VCU05/Subsystem13'
 * '<S73>'  : 'SWC_CSPF/RE_SWC_CSPF_10ms_sys/CSPF_Rec_10ms/CanSig_Select/VCU05/Subsystem14'
 * '<S74>'  : 'SWC_CSPF/RE_SWC_CSPF_10ms_sys/CSPF_Rec_10ms/CanSig_Select/VCU05/Subsystem15'
 * '<S75>'  : 'SWC_CSPF/RE_SWC_CSPF_10ms_sys/CSPF_Rec_10ms/CanSig_Select/VCU05/Subsystem16'
 * '<S76>'  : 'SWC_CSPF/RE_SWC_CSPF_10ms_sys/CSPF_Rec_10ms/CanSig_Select/VCU05/Subsystem17'
 * '<S77>'  : 'SWC_CSPF/RE_SWC_CSPF_10ms_sys/CSPF_Tra_10ms/CSPFTra_10ms'
 * '<S78>'  : 'SWC_CSPF/RE_SWC_CSPF_10ms_sys/CSPF_Tra_10ms/CSPFTra_10ms/PEB01'
 * '<S79>'  : 'SWC_CSPF/RE_SWC_CSPF_10ms_sys/CSPF_Tra_10ms/CSPFTra_10ms/PEB03'
 * '<S80>'  : 'SWC_CSPF/RE_SWC_CSPF_10ms_sys/CSPF_Tra_10ms/CSPFTra_10ms/PEB04'
 * '<S81>'  : 'SWC_CSPF/RE_SWC_CSPF_10ms_sys/CSPF_Tra_10ms/CSPFTra_10ms/PEB08'
 * '<S82>'  : 'SWC_CSPF/RE_SWC_CSPF_10ms_sys/CSPF_Tra_10ms/CSPFTra_10ms/Subsystem8'
 * '<S83>'  : 'SWC_CSPF/RE_SWC_CSPF_10ms_sys/CSPF_Tra_10ms/CSPFTra_10ms/PEB01/Subsystem1'
 * '<S84>'  : 'SWC_CSPF/RE_SWC_CSPF_10ms_sys/CSPF_Tra_10ms/CSPFTra_10ms/PEB01/Subsystem2'
 * '<S85>'  : 'SWC_CSPF/RE_SWC_CSPF_10ms_sys/CSPF_Tra_10ms/CSPFTra_10ms/PEB01/Subsystem3'
 * '<S86>'  : 'SWC_CSPF/RE_SWC_CSPF_10ms_sys/CSPF_Tra_10ms/CSPFTra_10ms/PEB01/Subsystem4'
 * '<S87>'  : 'SWC_CSPF/RE_SWC_CSPF_10ms_sys/CSPF_Tra_10ms/CSPFTra_10ms/PEB01/stMode'
 * '<S88>'  : 'SWC_CSPF/RE_SWC_CSPF_10ms_sys/CSPF_Tra_10ms/CSPFTra_10ms/PEB01/stMode/Subsystem10'
 * '<S89>'  : 'SWC_CSPF/RE_SWC_CSPF_10ms_sys/CSPF_Tra_10ms/CSPFTra_10ms/PEB03/Subsystem10'
 * '<S90>'  : 'SWC_CSPF/RE_SWC_CSPF_10ms_sys/CSPF_Tra_10ms/CSPFTra_10ms/PEB03/Subsystem5'
 * '<S91>'  : 'SWC_CSPF/RE_SWC_CSPF_10ms_sys/CSPF_Tra_10ms/CSPFTra_10ms/PEB03/Subsystem6'
 * '<S92>'  : 'SWC_CSPF/RE_SWC_CSPF_10ms_sys/CSPF_Tra_10ms/CSPFTra_10ms/PEB03/Subsystem7'
 * '<S93>'  : 'SWC_CSPF/RE_SWC_CSPF_10ms_sys/CSPF_Tra_10ms/CSPFTra_10ms/PEB03/Subsystem9'
 * '<S94>'  : 'SWC_CSPF/RE_SWC_CSPF_10ms_sys/CSPF_Tra_10ms/CSPFTra_10ms/PEB04/Subsystem11'
 * '<S95>'  : 'SWC_CSPF/RE_SWC_CSPF_10ms_sys/CSPF_Tra_10ms/CSPFTra_10ms/PEB04/Subsystem12'
 * '<S96>'  : 'SWC_CSPF/RE_SWC_CSPF_10ms_sys/CSPF_Tra_10ms/CSPFTra_10ms/PEB04/Subsystem13'
 * '<S97>'  : 'SWC_CSPF/RE_SWC_CSPF_10ms_sys/CSPF_Tra_10ms/CSPFTra_10ms/PEB04/Subsystem14'
 * '<S98>'  : 'SWC_CSPF/RE_SWC_CSPF_10ms_sys/CSPF_Tra_10ms/CSPFTra_10ms/PEB04/Subsystem15'
 * '<S99>'  : 'SWC_CSPF/RE_SWC_CSPF_10ms_sys/CSPF_Tra_10ms/CSPFTra_10ms/PEB04/Subsystem16'
 * '<S100>' : 'SWC_CSPF/RE_SWC_CSPF_10ms_sys/CSPF_Tra_10ms/CSPFTra_10ms/PEB04/stGateDrv'
 * '<S101>' : 'SWC_CSPF/RE_SWC_CSPF_10ms_sys/CSPF_Tra_10ms/CSPFTra_10ms/PEB04/stGateDrv/Subsystem10'
 * '<S102>' : 'SWC_CSPF/RE_SWC_CSPF_10ms_sys/CSPF_Tra_10ms/CSPFTra_10ms/PEB08/Subsystem17'
 * '<S103>' : 'SWC_CSPF/RE_SWC_CSPF_10ms_sys/CSPF_Tra_10ms/CSPFTra_10ms/PEB08/Subsystem18'
 */
#endif                                 /* RTW_HEADER_SWC_CSPF_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
