/*
 * File: SWC_CSPF.c
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

#include "SWC_CSPF.h"
#include "SWC_CSPF_private.h"

/* Exported block signals */
float32 VAR_Cspf_TraTrqCurr_f32;       /* '<S84>/Switch' */
float32 VAR_Cspf_TraUdcCurr_f32;       /* '<S85>/Switch' */
float32 VAR_Cspf_TraNCurr_f32;         /* '<S83>/Switch' */
float32 VAR_Cspf_TraisCurr_f32;        /* '<S86>/Switch' */
float32 VAR_Cspf_TraagRtrELecSnsr_f32; /* '<S94>/Switch' */
float32 VAR_Cspf_Traisd_f32;           /* '<S96>/Switch' */
float32 VAR_Cspf_Traisq_f32;           /* '<S97>/Switch' */
float32 VAR_Cspf_TraTrqCurrWoDmpC_f32; /* '<S99>/Switch' */
float32 VAR_Cspf_TraOfsAL_f32;         /* '<S98>/Switch' */
float32 VAR_Cspf_TraiGBTTempU_f32;     /* '<S90>/Switch' */
float32 VAR_Cspf_TraiGBTTempV_f32;     /* '<S91>/Switch' */
float32 VAR_Cspf_TraiGBTTempW_f32;     /* '<S92>/Switch' */
float32 VAR_Cspf_TraTempCurrStr1_f32;  /* '<S93>/Switch' */
float32 VAR_Cspf_TraTempCurrStr2_f32;  /* '<S89>/Switch' */
float32 VAR_Cspf_TraTempCurrCooL_f32;  /* '<S82>/Switch' */
float32 VAR_Cspf_TraidcCurr_f32;       /* '<S18>/Switch' */
float32 VAR_Cspf_TraTrqAbsMax_f32;     /* '<S21>/Switch' */
float32 VAR_Cspf_TraTrqAbsMin_f32;     /* '<S22>/Switch' */
float32 VAR_Cspf_TraUT30Curr_f32;      /* '<S23>/Switch' */
uint16 VAR_Cspf_TraHwVer_u16;          /* '<S103>/Switch' */
uint16 VAR_Cspf_TrabDernDrvBoardTemp_u16;/* '<S34>/Switch' */
uint16 VAR_Cspf_TraCpldVer_u16;        /* '<S43>/Switch' */
uint16 VAR_Cspf_TraHvMcuVer_u16;       /* '<S44>/Switch' */
uint8 VAR_Cspf_TrastMode_u8;           /* '<S88>/Switch' */
uint8 VAR_Cspf_TraflgOfsClbSuc_u8;     /* '<S95>/Switch' */
uint8 VAR_Cspf_TrastGateDrv_u8;        /* '<S101>/Switch' */
uint8 VAR_Cspf_TrastDischg_u8;         /* '<S102>/Switch' */
uint8 VAR_Cspf_TrabDernCAN_u8;         /* '<S16>/Switch' */
uint8 VAR_Cspf_TrabDernN_u8;           /* '<S15>/Switch' */
uint8 VAR_Cspf_TrabDernOvridc_u8;      /* '<S24>/Switch' */
uint8 VAR_Cspf_TrabDernOvrUdc_u8;      /* '<S25>/Switch' */
uint8 VAR_Cspf_TrabDernStrTemp_u8;     /* '<S26>/Switch' */
uint8 VAR_Cspf_TrabDernTempCooL_u8;    /* '<S27>/Switch' */
uint8 VAR_Cspf_TrabDernTempiGBT_u8;    /* '<S28>/Switch' */
uint8 VAR_Cspf_TrabDernUndrUdc_u8;     /* '<S31>/Switch' */
uint8 VAR_Cspf_TrastTrqEmMax_u8;       /* '<S19>/Switch' */
uint8 VAR_Cspf_TrastTrqEmMin_u8;       /* '<S20>/Switch' */
uint8 VAR_Cspf_TrabDernTrqMax_u8;      /* '<S29>/Switch' */
uint8 VAR_Cspf_TrabDernTrqMin_u8;      /* '<S30>/Switch' */
uint8 VAR_Cspf_TrabReadyHV_u8;         /* '<S17>/Switch' */
uint8 VAR_Cspf_TraFailCode1_u8;        /* '<S35>/Switch' */
uint8 VAR_Cspf_TraFailCode2_u8;        /* '<S36>/Switch' */
uint8 VAR_Cspf_TraFailCode3_u8;        /* '<S37>/Switch' */
uint8 VAR_Cspf_TraFailCode4_u8;        /* '<S38>/Switch' */
uint8 VAR_Cspf_TraFailCode5_u8;        /* '<S39>/Switch' */
uint8 VAR_Cspf_TraFailCode6_u8;        /* '<S40>/Switch' */
uint8 VAR_Cspf_TraFailCode7_u8;        /* '<S41>/Switch' */
uint8 VAR_Cspf_TraFailCode8_u8;        /* '<S42>/Switch' */

/* Exported data definition */
#pragma section ".rodata.Calib_32"

/* Definition for custom storage class: iEDS_Parameter */
const volatile uint16 CAL_Cspf_CodeVer_u16 = 0U;
                               /* Referenced by: '<S33>/CAL_Cspf_CodeVer_u16' */
const volatile uint8 CAL_Cspf_CpldVer_u8 = 0U;/* Referenced by: '<S43>/Constant3' */
const volatile uint16 CAL_Cspf_DataVer_u16 = 0U;
                               /* Referenced by: '<S33>/CAL_Cspf_DataVer_u16' */
const volatile uint8 CAL_Cspf_FailCode1_u8 = 0U;/* Referenced by: '<S35>/Constant3' */
const volatile uint8 CAL_Cspf_FailCode2_u8 = 0U;/* Referenced by: '<S36>/Constant3' */
const volatile uint8 CAL_Cspf_FailCode3_u8 = 0U;/* Referenced by: '<S37>/Constant3' */
const volatile uint8 CAL_Cspf_FailCode4_u8 = 0U;/* Referenced by: '<S38>/Constant3' */
const volatile uint8 CAL_Cspf_FailCode5_u8 = 0U;/* Referenced by: '<S39>/Constant3' */
const volatile uint8 CAL_Cspf_FailCode6_u8 = 0U;/* Referenced by: '<S40>/Constant3' */
const volatile uint8 CAL_Cspf_FailCode7_u8 = 0U;/* Referenced by: '<S41>/Constant3' */
const volatile uint8 CAL_Cspf_FailCode8_u8 = 0U;/* Referenced by: '<S42>/Constant3' */
const volatile uint8 CAL_Cspf_HvMcuVer_u8 = 0U;/* Referenced by: '<S44>/Constant3' */
const volatile uint16 CAL_Cspf_HwVer_u16 = 0U;/* Referenced by: '<S103>/Constant3' */
const volatile float32 CAL_Cspf_IdcMax_f32 = 0.0F;/* Referenced by: '<S11>/Constant3' */
const volatile float32 CAL_Cspf_IdcMin_f32 = 0.0F;/* Referenced by: '<S10>/Constant3' */
const volatile float32 CAL_Cspf_IsFlt_f32 = 0.0F;/* Referenced by: '<S86>/Constant3' */
const volatile float32 CAL_Cspf_KpHighNCtL_f32 = 0.0F;/* Referenced by: '<S58>/Constant3' */
const volatile float32 CAL_Cspf_KpLowNCtl_f32 = 0.0F;/* Referenced by: '<S61>/Constant3' */
const volatile uint8 CAL_Cspf_MainReLay_u8 = 0U;/* Referenced by: '<S57>/Constant3' */
const volatile float32 CAL_Cspf_NDiffMax_f32 = 0.0F;/* Referenced by: '<S59>/Constant3' */
const volatile float32 CAL_Cspf_NSetP_f32 = 0.0F;/* Referenced by: '<S70>/Constant3' */
const volatile float32 CAL_Cspf_TraTrqMax_f32 = 0.0F;/* Referenced by: '<S21>/Constant3' */
const volatile float32 CAL_Cspf_TraTrqMin_f32 = 0.0F;/* Referenced by: '<S22>/Constant3' */
const volatile float32 CAL_Cspf_TrqCurrWoDmpC_f32 = 0.0F;/* Referenced by: '<S99>/Constant3' */
const volatile float32 CAL_Cspf_TrqDmpLim_f32 = 0.0F;/* Referenced by: '<S75>/Constant3' */
const volatile float32 CAL_Cspf_TrqDmpMax_f32 = 0.0F;/* Referenced by: '<S76>/Constant3' */
const volatile float32 CAL_Cspf_TrqMaxNCtL_f32 = 10.0F;/* Referenced by: '<S60>/Constant3' */
const volatile float32 CAL_Cspf_TrqMax_f32 = 310.0F;/* Referenced by: '<S64>/Constant3' */
const volatile float32 CAL_Cspf_TrqMechFlt_f32 = 0.0F;/* Referenced by: '<S84>/Constant3' */
const volatile float32 CAL_Cspf_TrqMinNCtl_f32 = -10.0F;/* Referenced by: '<S62>/Constant3' */
const volatile float32 CAL_Cspf_TrqMin_f32 = -310.0F;/* Referenced by: '<S65>/Constant3' */
const volatile float32 CAL_Cspf_TrqSLope_f32 = 0.0F;/* Referenced by: '<S63>/Constant3' */
const volatile float32 CAL_Cspf_TrqSetP_f32 = 0.0F;/* Referenced by: '<S67>/Constant3' */
const volatile float32 CAL_Cspf_UdcMax_f32 = 0.0F;/* Referenced by: '<S9>/Constant3' */
const volatile float32 CAL_Cspf_UdcMin_f32 = 0.0F;/* Referenced by: '<S8>/Constant3' */
const volatile float32 CAL_Cspf_agOffset_f32 = 0.0F;/* Referenced by: '<S98>/Constant3' */
const volatile float32 CAL_Cspf_agRtrEe_f32 = 0.0F;/* Referenced by: '<S94>/Constant3' */
const volatile uint8 CAL_Cspf_bDernCAN_u8 = 0U;/* Referenced by: '<S16>/Constant3' */
const volatile uint8 CAL_Cspf_bDernCoolantTemp_u8 = 0U;/* Referenced by: '<S27>/Constant3' */
const volatile uint8 CAL_Cspf_bDernDbcTemp_u8 = 0U;/* Referenced by: '<S28>/Constant3' */
const volatile uint16 CAL_Cspf_bDernDrvBoardTemp_u16 = 0U;/* Referenced by: '<S34>/Constant3' */
const volatile uint8 CAL_Cspf_bDernExcMax_u8 = 0U;/* Referenced by: '<S29>/Constant3' */
const volatile uint8 CAL_Cspf_bDernExcMin_u8 = 0U;/* Referenced by: '<S30>/Constant3' */
const volatile uint8 CAL_Cspf_bDernMtrSpd_u8 = 0U;/* Referenced by: '<S15>/Constant3' */
const volatile uint8 CAL_Cspf_bDernOvrIdc_u8 = 0U;/* Referenced by: '<S24>/Constant3' */
const volatile uint8 CAL_Cspf_bDernOvrUdc_u8 = 0U;/* Referenced by: '<S25>/Constant3' */
const volatile uint8 CAL_Cspf_bDernStrTemp_u8 = 0U;/* Referenced by: '<S26>/Constant3' */
const volatile uint8 CAL_Cspf_bDernUndrUdc_u8 = 0U;/* Referenced by: '<S31>/Constant3' */
const volatile uint8 CAL_Cspf_bReadyHV_u8 = 0U;/* Referenced by: '<S17>/Constant3' */
const volatile boolean CAL_Cspf_flgCpldVerSwt_b = 0;/* Referenced by: '<S43>/Constant2' */
const volatile boolean CAL_Cspf_flgCrashSwt_b = 0;/* Referenced by: '<S49>/Constant2' */
const volatile boolean CAL_Cspf_flgCrash_b = 0;/* Referenced by: '<S49>/Constant3' */
const volatile boolean CAL_Cspf_flgDchaReqSwt_b = 0;/* Referenced by: '<S50>/Constant2' */
const volatile boolean CAL_Cspf_flgDchaReq_b = 0;/* Referenced by: '<S50>/Constant3' */
const volatile boolean CAL_Cspf_flgFailCode1Swt_b = 0;/* Referenced by: '<S35>/Constant2' */
const volatile boolean CAL_Cspf_flgFailCode2Swt_b = 0;/* Referenced by: '<S36>/Constant2' */
const volatile boolean CAL_Cspf_flgFailCode3Swt_b = 0;/* Referenced by: '<S37>/Constant2' */
const volatile boolean CAL_Cspf_flgFailCode4Swt_b = 0;/* Referenced by: '<S38>/Constant2' */
const volatile boolean CAL_Cspf_flgFailCode5Swt_b = 0;/* Referenced by: '<S39>/Constant2' */
const volatile boolean CAL_Cspf_flgFailCode6Swt_b = 0;/* Referenced by: '<S40>/Constant2' */
const volatile boolean CAL_Cspf_flgFailCode7Swt_b = 0;/* Referenced by: '<S41>/Constant2' */
const volatile boolean CAL_Cspf_flgFailCode8Swt_b = 0;/* Referenced by: '<S42>/Constant2' */
const volatile boolean CAL_Cspf_flgHvMcuVerSwt_b = 0;/* Referenced by: '<S44>/Constant2' */
const volatile boolean CAL_Cspf_flgHwVerSwt_b = 0;/* Referenced by: '<S103>/Constant2' */
const volatile boolean CAL_Cspf_flgIdcMaxSwt_b = 0;/* Referenced by: '<S11>/Constant2' */
const volatile boolean CAL_Cspf_flgIdcMinSwt_b = 0;/* Referenced by: '<S10>/Constant2' */
const volatile boolean CAL_Cspf_flgIsFltSwt_b = 0;/* Referenced by: '<S86>/Constant2' */
const volatile boolean CAL_Cspf_flgKpHighNCtLSwt_b = 0;/* Referenced by: '<S58>/Constant2' */
const volatile boolean CAL_Cspf_flgKpLowNCtlSwt_b = 0;/* Referenced by: '<S61>/Constant2' */
const volatile boolean CAL_Cspf_flgNDiffMaxSwt_b = 0;/* Referenced by: '<S59>/Constant2' */
const volatile boolean CAL_Cspf_flgNSetPSwt_b = 0;/* Referenced by: '<S70>/Constant2' */
const volatile boolean CAL_Cspf_flgOfsClbSucSwt_b = 0;/* Referenced by: '<S95>/Constant2' */
const volatile uint8 CAL_Cspf_flgOfsClbSuc_u8 = 0U;/* Referenced by: '<S95>/Constant3' */
const volatile boolean CAL_Cspf_flgTraTrqMaxSwt_b = 0;/* Referenced by: '<S21>/Constant2' */
const volatile boolean CAL_Cspf_flgTraTrqMinSwt_b = 0;/* Referenced by: '<S22>/Constant2' */
const volatile boolean CAL_Cspf_flgTrqCurrWoDmpCSwt_b = 0;/* Referenced by: '<S99>/Constant2' */
const volatile boolean CAL_Cspf_flgTrqDmpMaxSwt_b = 0;/* Referenced by: '<S76>/Constant2' */
const volatile boolean CAL_Cspf_flgTrqDmpMinSwt_b = 0;/* Referenced by: '<S75>/Constant2' */
const volatile boolean CAL_Cspf_flgTrqMaxNCtLSwt_b = 1;/* Referenced by: '<S60>/Constant2' */
const volatile boolean CAL_Cspf_flgTrqMaxSwt_b = 1;/* Referenced by: '<S64>/Constant2' */
const volatile boolean CAL_Cspf_flgTrqMechFltSwt_b = 0;/* Referenced by: '<S84>/Constant2' */
const volatile boolean CAL_Cspf_flgTrqMinNCtlSwt_b = 1;/* Referenced by: '<S62>/Constant2' */
const volatile boolean CAL_Cspf_flgTrqMinSwt_b = 1;/* Referenced by: '<S65>/Constant2' */
const volatile boolean CAL_Cspf_flgTrqSetPSwt_b = 0;/* Referenced by: '<S67>/Constant2' */
const volatile boolean CAL_Cspf_flgUdcMaxSwt_b = 0;/* Referenced by: '<S9>/Constant2' */
const volatile boolean CAL_Cspf_flgUdcMinSwt_b = 0;/* Referenced by: '<S8>/Constant2' */
const volatile boolean CAL_Cspf_flgagOffsetSwt_b = 0;/* Referenced by: '<S98>/Constant2' */
const volatile boolean CAL_Cspf_flgagRtrEeSwt_b = 0;/* Referenced by: '<S94>/Constant2' */
const volatile boolean CAL_Cspf_flgbDernCANSwt_b = 0;/* Referenced by: '<S16>/Constant2' */
const volatile boolean CAL_Cspf_flgbDernCoolantTempSwt_b = 0;/* Referenced by: '<S27>/Constant2' */
const volatile boolean CAL_Cspf_flgbDernDbcTempSwt_b = 0;/* Referenced by: '<S28>/Constant2' */
const volatile boolean CAL_Cspf_flgbDernDrvBoardTempSwt_b = 0;/* Referenced by: '<S34>/Constant2' */
const volatile boolean CAL_Cspf_flgbDernExcMaxSwt_b = 0;/* Referenced by: '<S29>/Constant2' */
const volatile boolean CAL_Cspf_flgbDernExcMinSwt_b = 0;/* Referenced by: '<S30>/Constant2' */
const volatile boolean CAL_Cspf_flgbDernMtrSpdSwt_b = 0;/* Referenced by: '<S15>/Constant2' */
const volatile boolean CAL_Cspf_flgbDernOvrIdcSwt_b = 0;/* Referenced by: '<S24>/Constant2' */
const volatile boolean CAL_Cspf_flgbDernOvrUdcSwt_b = 0;/* Referenced by: '<S25>/Constant2' */
const volatile boolean CAL_Cspf_flgbDernStrTempSwt_b = 0;/* Referenced by: '<S26>/Constant2' */
const volatile boolean CAL_Cspf_flgbDernUndrUdcSwt_b = 0;/* Referenced by: '<S31>/Constant2' */
const volatile boolean CAL_Cspf_flgbReadyHVSwt_b = 0;/* Referenced by: '<S17>/Constant2' */
const volatile boolean CAL_Cspf_flgcTrqSLopeSwt_b = 0;/* Referenced by: '<S63>/Constant2' */
const volatile boolean CAL_Cspf_flgiDActSlowFltSwt_b = 0;/* Referenced by: '<S96>/Constant2' */
const volatile boolean CAL_Cspf_flgiDcLnkEstFltSwt_b = 0;/* Referenced by: '<S18>/Constant2' */
const volatile boolean CAL_Cspf_flgiQActSlowFltSwt_b = 0;/* Referenced by: '<S97>/Constant2' */
const volatile boolean CAL_Cspf_flgkDmpSwt_b = 0;/* Referenced by: '<S72>/Constant2' */
const volatile boolean CAL_Cspf_flgnSlowFltSwt_b = 0;/* Referenced by: '<S83>/Constant2' */
const volatile boolean CAL_Cspf_flgstDisChgSwt_b = 0;/* Referenced by: '<S102>/Constant2' */
const volatile boolean CAL_Cspf_flgstDmpCtLReqSwt_b = 0;/* Referenced by: '<S74>/Constant2' */
const volatile boolean CAL_Cspf_flgstGateDrvSwt_b = 0;/* Referenced by: '<S101>/Constant2' */
const volatile boolean CAL_Cspf_flgstMainReLaySwt_b = 0;/* Referenced by: '<S57>/Constant2' */
const volatile boolean CAL_Cspf_flgstModeReqSwt_b = 0;/* Referenced by: '<S66>/Constant2' */
const volatile boolean CAL_Cspf_flgstModeSwt_b = 0;/* Referenced by: '<S88>/Constant2' */
const volatile boolean CAL_Cspf_flgstTrqEmMaxSwt_b = 0;/* Referenced by: '<S19>/Constant2' */
const volatile boolean CAL_Cspf_flgstTrqEmMinSwt_b = 0;/* Referenced by: '<S20>/Constant2' */
const volatile boolean CAL_Cspf_flgtCoolantTempFltSwt_b = 0;/* Referenced by: '<S82>/Constant2' */
const volatile boolean CAL_Cspf_flgtDBCTempUFltSwt_b = 0;/* Referenced by: '<S90>/Constant2' */
const volatile boolean CAL_Cspf_flgtDBCTempVFltSwt_b = 0;/* Referenced by: '<S91>/Constant2' */
const volatile boolean CAL_Cspf_flgtDBCTempWFltSwt_b = 0;/* Referenced by: '<S92>/Constant2' */
const volatile boolean CAL_Cspf_flgtStrrTemp1FltSwt_b = 0;/* Referenced by: '<S93>/Constant2' */
const volatile boolean CAL_Cspf_flgtStrrTemp2FltSwt_b = 0;/* Referenced by: '<S89>/Constant2' */
const volatile boolean CAL_Cspf_flguDcLnkSlowFltSwt_b = 0;/* Referenced by: '<S85>/Constant2' */
const volatile boolean CAL_Cspf_flguKl30FltSwt_b = 0;/* Referenced by: '<S23>/Constant2' */
const volatile float32 CAL_Cspf_iDActSlowFlt_f32 = 0.0F;/* Referenced by: '<S96>/Constant3' */
const volatile float32 CAL_Cspf_iDcLnkEstFlt_f32 = 0.0F;/* Referenced by: '<S18>/Constant3' */
const volatile float32 CAL_Cspf_iQActSlowFlt_f32 = 0.0F;/* Referenced by: '<S97>/Constant3' */
const volatile float32 CAL_Cspf_kDmp_f32 = 0.0F;/* Referenced by: '<S72>/Constant3' */
const volatile float32 CAL_Cspf_nSlowFlt_f32 = 0.0F;/* Referenced by: '<S83>/Constant3' */
const volatile uint8 CAL_Cspf_stDisChg_u8 = 0U;/* Referenced by: '<S102>/Constant3' */
const volatile uint8 CAL_Cspf_stDmpCtLReq_u8 = 0U;/* Referenced by: '<S74>/Constant3' */
const volatile uint8 CAL_Cspf_stGateDrv_u8 = 0U;/* Referenced by: '<S101>/Constant3' */
const volatile uint8 CAL_Cspf_stModeReq_u8 = 0U;/* Referenced by: '<S66>/Constant3' */
const volatile uint8 CAL_Cspf_stMode_u8 = 0U;/* Referenced by: '<S88>/Constant3' */
const volatile uint8 CAL_Cspf_stTrqEmMax_u8 = 0U;/* Referenced by: '<S19>/Constant3' */
const volatile uint8 CAL_Cspf_stTrqEmMin_u8 = 0U;/* Referenced by: '<S20>/Constant3' */
const volatile float32 CAL_Cspf_tCoolantTempFlt_f32 = 0.0F;/* Referenced by: '<S82>/Constant3' */
const volatile float32 CAL_Cspf_tDBCTempUFlt_f32 = 0.0F;/* Referenced by: '<S90>/Constant3' */
const volatile float32 CAL_Cspf_tDBCTempVFlt_f32 = 0.0F;/* Referenced by: '<S91>/Constant3' */
const volatile float32 CAL_Cspf_tDBCTempWFlt_f32 = 0.0F;/* Referenced by: '<S92>/Constant3' */
const volatile float32 CAL_Cspf_tStrrTemp1Flt_f32 = 0.0F;/* Referenced by: '<S93>/Constant3' */
const volatile float32 CAL_Cspf_tStrrTemp2Flt_f32 = 0.0F;/* Referenced by: '<S89>/Constant3' */
const volatile float32 CAL_Cspf_uDcLnkSlowFlt_f32 = 0.0F;/* Referenced by: '<S85>/Constant3' */
const volatile float32 CAL_Cspf_uKl30Flt_f32 = 0.0F;/* Referenced by: '<S23>/Constant3' */

#pragma section

/* Block states (default storage) */
DW_SWC_CSPF_T SWC_CSPF_DW;

/* Model step function for TID1 */
void SWC_CSPF_10ms(void)               /* Explicit Task: RE_SWC_CSPF_10ms */
{
  uint8 tmpRead;
  float32 tmpRead_0;
  float32 tmpRead_1;
  float32 tmpRead_2;
  float32 tmpRead_3;
  float32 tmpRead_4;
  float32 tmpRead_5;
  float32 tmpRead_6;
  float32 tmpRead_7;
  float32 tmpRead_8;
  uint8 tmpRead_9;
  float32 tmpRead_a;
  float32 tmpRead_b;
  float32 tmpRead_c;
  uint8 tmpRead_d;
  float32 tmpRead_e;
  boolean tmpRead_f;
  uint8 tmpRead_g;
  uint8 tmpRead_h;
  boolean tmpRead_i;
  boolean tmpRead_j;
  iEDS_Enum_stSysCtl_def rtb_DataTypeConversion;
  iEDS_Enum_stDrvCtl_def rtb_DataTypeConversion1;
  uint8 rtb_TmpSignalConversionAtRP_SWC;
  float32 rtb_RP_SWC_IoHwAb_ADC_BSW_HwVer;
  uint8 rtb_TmpSignalConversionAtRP_S_j;
  boolean rtb_Compare14;

  /* Inport: '<Root>/RP_SWC_HSPF_HSPF_uDcLnkSlowFlt' */
  Rte_Read_RP_SWC_HSPF_HSPF_uDcLnkSlowFlt(&VAR_Cspf_TraUdcCurr_f32);

  /* Inport: '<Root>/RP_SWC_MPC_MPC_TrqMechFlt' */
  Rte_Read_RP_SWC_MPC_MPC_TrqMechFlt(&VAR_Cspf_TraTrqCurr_f32);

  /* Inport: '<Root>/RP_SWC_HSPF_HSPF_nSlowFlt' */
  Rte_Read_RP_SWC_HSPF_HSPF_nSlowFlt(&VAR_Cspf_TraNCurr_f32);

  /* Inport: '<Root>/RP_SWC_MPC_MPC_IsFlt' */
  Rte_Read_RP_SWC_MPC_MPC_IsFlt(&VAR_Cspf_TraisCurr_f32);

  /* Inport: '<Root>/RP_SWC_SCF_SCF_stDrvCtl' */
  Rte_Read_RP_SWC_SCF_SCF_stDrvCtl(&tmpRead_h);

  /* Inport: '<Root>/RP_SWC_SCF_SCF_stSysCtl' */
  Rte_Read_RP_SWC_SCF_SCF_stSysCtl(&tmpRead_g);

  /* Inport: '<Root>/RP_SWC_Com_Com_VCU02_KpHighNCtL' */
  Rte_Read_RP_SWC_Com_Com_VCU02_KpHighNCtL(&tmpRead_4);

  /* Inport: '<Root>/RP_SWC_Com_Com_BMS01_stMainReLay' */
  Rte_Read_RP_SWC_Com_Com_BMS01_stMainReLay(&tmpRead);

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_CSPF_10ms' incorporates:
   *  SubSystem: '<Root>/RE_SWC_CSPF_10ms_sys'
   */
  /* Switch: '<S57>/Switch' incorporates:
   *  Constant: '<S57>/Constant2'
   */
  if (CAL_Cspf_flgstMainReLaySwt_b) {
    /* Outport: '<Root>/PP_SWC_CSPF_CSPF_RecstMainReLay' incorporates:
     *  Constant: '<S57>/Constant3'
     */
    (void) Rte_Write_PP_SWC_CSPF_CSPF_RecstMainReLay(CAL_Cspf_MainReLay_u8);
  } else {
    /* Outport: '<Root>/PP_SWC_CSPF_CSPF_RecstMainReLay' */
    (void) Rte_Write_PP_SWC_CSPF_CSPF_RecstMainReLay(tmpRead);
  }

  /* End of Switch: '<S57>/Switch' */

  /* Switch: '<S84>/Switch' incorporates:
   *  Constant: '<S84>/Constant2'
   *  Constant: '<S84>/Constant3'
   *  Inport: '<Root>/RP_SWC_MPC_MPC_TrqMechFlt'
   */
  if (CAL_Cspf_flgTrqMechFltSwt_b) {
    VAR_Cspf_TraTrqCurr_f32 = CAL_Cspf_TrqMechFlt_f32;
  }

  /* End of Switch: '<S84>/Switch' */

  /* Outport: '<Root>/PP_SWC_CSPF_CSPF_TraTrqCurr' incorporates:
   *  Sum: '<S78>/Add4'
   */
  (void) Rte_Write_PP_SWC_CSPF_CSPF_TraTrqCurr(VAR_Cspf_TraTrqCurr_f32);

  /* Switch: '<S85>/Switch' incorporates:
   *  Constant: '<S85>/Constant2'
   *  Constant: '<S85>/Constant3'
   *  Inport: '<Root>/RP_SWC_HSPF_HSPF_uDcLnkSlowFlt'
   */
  if (CAL_Cspf_flguDcLnkSlowFltSwt_b) {
    VAR_Cspf_TraUdcCurr_f32 = CAL_Cspf_uDcLnkSlowFlt_f32;
  }

  /* End of Switch: '<S85>/Switch' */

  /* Outport: '<Root>/PP_SWC_CSPF_CSPF_TraUdcCurr' incorporates:
   *  Sum: '<S78>/Add5'
   */
  (void) Rte_Write_PP_SWC_CSPF_CSPF_TraUdcCurr(VAR_Cspf_TraUdcCurr_f32);

  /* Switch: '<S83>/Switch' incorporates:
   *  Constant: '<S83>/Constant2'
   *  Constant: '<S83>/Constant3'
   *  Inport: '<Root>/RP_SWC_HSPF_HSPF_nSlowFlt'
   */
  if (CAL_Cspf_flgnSlowFltSwt_b) {
    VAR_Cspf_TraNCurr_f32 = CAL_Cspf_nSlowFlt_f32;
  }

  /* End of Switch: '<S83>/Switch' */

  /* Outport: '<Root>/PP_SWC_CSPF_CSPF_TraNCurr' incorporates:
   *  Sum: '<S78>/Add3'
   */
  (void) Rte_Write_PP_SWC_CSPF_CSPF_TraNCurr(VAR_Cspf_TraNCurr_f32);

  /* Switch: '<S58>/Switch' incorporates:
   *  Constant: '<S58>/Constant2'
   */
  if (CAL_Cspf_flgKpHighNCtLSwt_b) {
    /* Outport: '<Root>/PP_SWC_CSPF_CSPF_RecKpHighNCtL' incorporates:
     *  Constant: '<S58>/Constant3'
     */
    (void) Rte_Write_PP_SWC_CSPF_CSPF_RecKpHighNCtL(CAL_Cspf_KpHighNCtL_f32);
  } else {
    /* Outport: '<Root>/PP_SWC_CSPF_CSPF_RecKpHighNCtL' */
    (void) Rte_Write_PP_SWC_CSPF_CSPF_RecKpHighNCtL(tmpRead_4);
  }

  /* End of Switch: '<S58>/Switch' */

  /* Switch: '<S86>/Switch' incorporates:
   *  Constant: '<S86>/Constant2'
   *  Constant: '<S86>/Constant3'
   *  Inport: '<Root>/RP_SWC_MPC_MPC_IsFlt'
   */
  if (CAL_Cspf_flgIsFltSwt_b) {
    VAR_Cspf_TraisCurr_f32 = CAL_Cspf_IsFlt_f32;
  }

  /* End of Switch: '<S86>/Switch' */

  /* Outport: '<Root>/PP_SWC_CSPF_CSPF_TraisCurr' incorporates:
   *  Sum: '<S78>/Add2'
   */
  (void) Rte_Write_PP_SWC_CSPF_CSPF_TraisCurr(VAR_Cspf_TraisCurr_f32);

  /* DataTypeConversion: '<S78>/Data Type Conversion' */
  rtb_DataTypeConversion = (iEDS_Enum_stSysCtl_def)tmpRead_g;

  /* DataTypeConversion: '<S78>/Data Type Conversion1' */
  rtb_DataTypeConversion1 = (iEDS_Enum_stDrvCtl_def)tmpRead_h;

  /* Switch: '<S87>/Switch9' incorporates:
   *  Constant: '<S87>/Constant24'
   *  Constant: '<S87>/iEDS_Enum_stDrvCtl_def.Drv_Failure'
   *  Constant: '<S87>/iEDS_Enum_stSysCtl_def.PostDriveMod'
   *  Constant: '<S87>/iEDS_Enum_stSysCtl_def.PostDriveMod1'
   *  Constant: '<S87>/iEDS_Enum_stSysCtl_def.PreDriveMod'
   *  Logic: '<S87>/Logical Operator9'
   *  RelationalOperator: '<S87>/Compare'
   *  RelationalOperator: '<S87>/Compare13'
   *  RelationalOperator: '<S87>/Compare16'
   *  RelationalOperator: '<S87>/Compare3'
   *  Switch: '<S87>/Switch'
   *  Switch: '<S87>/Switch14'
   *  UnitDelay: '<S87>/Unit Delay'
   */
  if ((FaultMod == rtb_DataTypeConversion) && (Drv_Failure ==
       rtb_DataTypeConversion1)) {
    SWC_CSPF_DW.UnitDelay_DSTATE = 13U;
  } else if (PostDriveMod == rtb_DataTypeConversion) {
    /* UnitDelay: '<S87>/Unit Delay' incorporates:
     *  Constant: '<S87>/Constant29'
     *  Switch: '<S87>/Switch14'
     */
    SWC_CSPF_DW.UnitDelay_DSTATE = 11U;
  } else if (PreDriveMod == rtb_DataTypeConversion) {
    /* UnitDelay: '<S87>/Unit Delay' incorporates:
     *  Constant: '<S87>/Constant'
     *  Switch: '<S87>/Switch'
     *  Switch: '<S87>/Switch14'
     */
    SWC_CSPF_DW.UnitDelay_DSTATE = 0U;
  } else {
    /* RelationalOperator: '<S87>/Compare14' incorporates:
     *  Constant: '<S87>/iEDS_Enum_stSysCtl_def.DriveMod'
     *  Switch: '<S87>/Switch'
     *  Switch: '<S87>/Switch14'
     */
    rtb_Compare14 = (DriveMod == rtb_DataTypeConversion);

    /* Switch: '<S87>/Switch1' incorporates:
     *  Constant: '<S87>/Constant9'
     *  Constant: '<S87>/iEDS_Enum_stDrvCtl_def.Drv_Discharge'
     *  Constant: '<S87>/iEDS_Enum_stDrvCtl_def.Drv_FrWCtl'
     *  Constant: '<S87>/iEDS_Enum_stDrvCtl_def.Drv_Initial'
     *  Constant: '<S87>/iEDS_Enum_stDrvCtl_def.Drv_IsCtl'
     *  Constant: '<S87>/iEDS_Enum_stDrvCtl_def.Drv_OffsetAcc'
     *  Constant: '<S87>/iEDS_Enum_stDrvCtl_def.Drv_OffsetFw'
     *  Constant: '<S87>/iEDS_Enum_stDrvCtl_def.Drv_Standby'
     *  Constant: '<S87>/iEDS_Enum_stDrvCtl_def.Drv_TrqCtl'
     *  Constant: '<S87>/iEDS_Enum_stDrvCtl_def.Drv_UdcBatCtl'
     *  Constant: '<S87>/iEDS_Enum_stDrvCtl_def.Drv_UdcCtl '
     *  Constant: '<S87>/iEDS_Enum_stDrvCtl_def.Drv_nCtlExt'
     *  Logic: '<S87>/Logical Operator'
     *  Logic: '<S87>/Logical Operator1'
     *  Logic: '<S87>/Logical Operator10'
     *  Logic: '<S87>/Logical Operator11'
     *  Logic: '<S87>/Logical Operator12'
     *  Logic: '<S87>/Logical Operator2'
     *  Logic: '<S87>/Logical Operator3'
     *  Logic: '<S87>/Logical Operator4'
     *  Logic: '<S87>/Logical Operator5'
     *  Logic: '<S87>/Logical Operator6'
     *  Logic: '<S87>/Logical Operator7'
     *  Logic: '<S87>/Logical Operator8'
     *  RelationalOperator: '<S87>/Compare1'
     *  RelationalOperator: '<S87>/Compare10'
     *  RelationalOperator: '<S87>/Compare11'
     *  RelationalOperator: '<S87>/Compare12'
     *  RelationalOperator: '<S87>/Compare15'
     *  RelationalOperator: '<S87>/Compare2'
     *  RelationalOperator: '<S87>/Compare4'
     *  RelationalOperator: '<S87>/Compare5'
     *  RelationalOperator: '<S87>/Compare6'
     *  RelationalOperator: '<S87>/Compare7'
     *  RelationalOperator: '<S87>/Compare8'
     *  RelationalOperator: '<S87>/Compare9'
     *  Switch: '<S87>/Switch'
     *  Switch: '<S87>/Switch10'
     *  Switch: '<S87>/Switch11'
     *  Switch: '<S87>/Switch12'
     *  Switch: '<S87>/Switch14'
     *  Switch: '<S87>/Switch2'
     *  Switch: '<S87>/Switch3'
     *  Switch: '<S87>/Switch4'
     *  Switch: '<S87>/Switch5'
     *  Switch: '<S87>/Switch6'
     *  Switch: '<S87>/Switch7'
     *  Switch: '<S87>/Switch8'
     */
    if (rtb_Compare14 && (Drv_IdLe == rtb_DataTypeConversion1)) {
      /* UnitDelay: '<S87>/Unit Delay' incorporates:
       *  Constant: '<S87>/Constant11'
       */
      SWC_CSPF_DW.UnitDelay_DSTATE = 1U;
    } else if (rtb_Compare14 && (Drv_Standby == rtb_DataTypeConversion1)) {
      /* UnitDelay: '<S87>/Unit Delay' incorporates:
       *  Constant: '<S87>/Constant16'
       *  Switch: '<S87>/Switch2'
       */
      SWC_CSPF_DW.UnitDelay_DSTATE = 3U;
    } else if (rtb_Compare14 && (Drv_UdcCtl == rtb_DataTypeConversion1)) {
      /* UnitDelay: '<S87>/Unit Delay' incorporates:
       *  Constant: '<S87>/Constant27'
       *  Switch: '<S87>/Switch2'
       *  Switch: '<S87>/Switch3'
       */
      SWC_CSPF_DW.UnitDelay_DSTATE = 4U;
    } else if (rtb_Compare14 && ((Drv_OffsetAcc == rtb_DataTypeConversion1) ||
                (Drv_OffsetFw == rtb_DataTypeConversion1))) {
      /* UnitDelay: '<S87>/Unit Delay' incorporates:
       *  Constant: '<S87>/Constant17'
       *  Switch: '<S87>/Switch2'
       *  Switch: '<S87>/Switch3'
       *  Switch: '<S87>/Switch4'
       */
      SWC_CSPF_DW.UnitDelay_DSTATE = 5U;
    } else if (rtb_Compare14 && (Drv_nCtlExt == rtb_DataTypeConversion1)) {
      /* UnitDelay: '<S87>/Unit Delay' incorporates:
       *  Constant: '<S87>/Constant19'
       *  Switch: '<S87>/Switch12'
       *  Switch: '<S87>/Switch2'
       *  Switch: '<S87>/Switch3'
       *  Switch: '<S87>/Switch4'
       */
      SWC_CSPF_DW.UnitDelay_DSTATE = 6U;
    } else if (rtb_Compare14 && (Drv_nCtlInt == rtb_DataTypeConversion1)) {
      /* UnitDelay: '<S87>/Unit Delay' incorporates:
       *  Constant: '<S87>/Constant20'
       *  Switch: '<S87>/Switch12'
       *  Switch: '<S87>/Switch2'
       *  Switch: '<S87>/Switch3'
       *  Switch: '<S87>/Switch4'
       *  Switch: '<S87>/Switch5'
       */
      SWC_CSPF_DW.UnitDelay_DSTATE = 7U;
    } else if (rtb_Compare14 && (Drv_TrqCtl == rtb_DataTypeConversion1)) {
      /* UnitDelay: '<S87>/Unit Delay' incorporates:
       *  Constant: '<S87>/Constant21'
       *  Switch: '<S87>/Switch12'
       *  Switch: '<S87>/Switch2'
       *  Switch: '<S87>/Switch3'
       *  Switch: '<S87>/Switch4'
       *  Switch: '<S87>/Switch5'
       *  Switch: '<S87>/Switch6'
       */
      SWC_CSPF_DW.UnitDelay_DSTATE = 8U;
    } else if (rtb_Compare14 && (Drv_IsCtl == rtb_DataTypeConversion1)) {
      /* UnitDelay: '<S87>/Unit Delay' incorporates:
       *  Constant: '<S87>/Constant22'
       *  Switch: '<S87>/Switch12'
       *  Switch: '<S87>/Switch2'
       *  Switch: '<S87>/Switch3'
       *  Switch: '<S87>/Switch4'
       *  Switch: '<S87>/Switch5'
       *  Switch: '<S87>/Switch6'
       *  Switch: '<S87>/Switch7'
       */
      SWC_CSPF_DW.UnitDelay_DSTATE = 9U;
    } else if (rtb_Compare14 && (Drv_UdcBatCtl == rtb_DataTypeConversion1)) {
      /* UnitDelay: '<S87>/Unit Delay' incorporates:
       *  Constant: '<S87>/Constant23'
       *  Switch: '<S87>/Switch12'
       *  Switch: '<S87>/Switch2'
       *  Switch: '<S87>/Switch3'
       *  Switch: '<S87>/Switch4'
       *  Switch: '<S87>/Switch5'
       *  Switch: '<S87>/Switch6'
       *  Switch: '<S87>/Switch7'
       *  Switch: '<S87>/Switch8'
       */
      SWC_CSPF_DW.UnitDelay_DSTATE = 10U;
    } else if (rtb_Compare14 && (Drv_Discharge == rtb_DataTypeConversion1)) {
      /* UnitDelay: '<S87>/Unit Delay' incorporates:
       *  Constant: '<S87>/Constant25'
       *  Switch: '<S87>/Switch10'
       *  Switch: '<S87>/Switch12'
       *  Switch: '<S87>/Switch2'
       *  Switch: '<S87>/Switch3'
       *  Switch: '<S87>/Switch4'
       *  Switch: '<S87>/Switch5'
       *  Switch: '<S87>/Switch6'
       *  Switch: '<S87>/Switch7'
       *  Switch: '<S87>/Switch8'
       */
      SWC_CSPF_DW.UnitDelay_DSTATE = 14U;
    } else {
      if (rtb_Compare14 && (Drv_FrWCtl == rtb_DataTypeConversion1)) {
        /* UnitDelay: '<S87>/Unit Delay' incorporates:
         *  Constant: '<S87>/Constant26'
         *  Switch: '<S87>/Switch10'
         *  Switch: '<S87>/Switch11'
         *  Switch: '<S87>/Switch12'
         *  Switch: '<S87>/Switch2'
         *  Switch: '<S87>/Switch3'
         *  Switch: '<S87>/Switch4'
         *  Switch: '<S87>/Switch5'
         *  Switch: '<S87>/Switch6'
         *  Switch: '<S87>/Switch7'
         *  Switch: '<S87>/Switch8'
         */
        SWC_CSPF_DW.UnitDelay_DSTATE = 15U;
      }
    }

    /* End of Switch: '<S87>/Switch1' */
  }

  /* End of Switch: '<S87>/Switch9' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_CSPF_10ms' */

  /* Inport: '<Root>/RP_SWC_Rdc_Rdc_ArctanAgRtr' */
  Rte_Read_RP_SWC_Rdc_Rdc_ArctanAgRtr(&VAR_Cspf_TraagRtrELecSnsr_f32);

  /* Inport: '<Root>/RP_SWC_Com_Com_VCU05_kDmp' */
  Rte_Read_RP_SWC_Com_Com_VCU05_kDmp(&tmpRead_e);

  /* Inport: '<Root>/RP_SWC_Com_Com_VCU04_NSetP' */
  Rte_Read_RP_SWC_Com_Com_VCU04_NSetP(&tmpRead_a);

  /* Inport: '<Root>/RP_SWC_Com_Com_VCU04_stModeReq' */
  Rte_Read_RP_SWC_Com_Com_VCU04_stModeReq(&tmpRead_9);

  /* Inport: '<Root>/RP_SWC_Com_Com_VCU04_TrqSetP' */
  Rte_Read_RP_SWC_Com_Com_VCU04_TrqSetP(&tmpRead_8);

  /* Inport: '<Root>/RP_SWC_Com_Com_VCU03_TrqMax' */
  Rte_Read_RP_SWC_Com_Com_VCU03_TrqMax(&tmpRead_7);

  /* Inport: '<Root>/RP_SWC_Com_Com_VCU03_TrqMin' */
  Rte_Read_RP_SWC_Com_Com_VCU03_TrqMin(&tmpRead_6);

  /* Inport: '<Root>/RP_SWC_Com_Com_VCU03_cTrqSlopeMax' */
  Rte_Read_RP_SWC_Com_Com_VCU03_cTrqSlopeMax(&tmpRead_5);

  /* Inport: '<Root>/RP_SWC_Com_Com_VCU02_KpLowNCtL' */
  Rte_Read_RP_SWC_Com_Com_VCU02_KpLowNCtL(&tmpRead_3);

  /* Inport: '<Root>/RP_SWC_Com_Com_VCU02_NDiffMax' */
  Rte_Read_RP_SWC_Com_Com_VCU02_NDiffMax(&tmpRead_2);

  /* Inport: '<Root>/RP_SWC_Com_Com_VCU02_TrqMaxNCtL' */
  Rte_Read_RP_SWC_Com_Com_VCU02_TrqMaxNCtL(&tmpRead_1);

  /* Inport: '<Root>/RP_SWC_Com_Com_VCU02_TrqMinNCtL' */
  Rte_Read_RP_SWC_Com_Com_VCU02_TrqMinNCtL(&tmpRead_0);

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_CSPF_10ms' incorporates:
   *  SubSystem: '<Root>/RE_SWC_CSPF_10ms_sys'
   */
  /* Switch: '<S88>/Switch' incorporates:
   *  Constant: '<S88>/Constant2'
   *  Constant: '<S88>/Constant3'
   *  UnitDelay: '<S87>/Unit Delay'
   */
  if (CAL_Cspf_flgstModeSwt_b) {
    VAR_Cspf_TrastMode_u8 = CAL_Cspf_stMode_u8;
  } else {
    VAR_Cspf_TrastMode_u8 = SWC_CSPF_DW.UnitDelay_DSTATE;
  }

  /* End of Switch: '<S88>/Switch' */

  /* Outport: '<Root>/PP_SWC_CSPF_CSPF_TrastMode' incorporates:
   *  Sum: '<S78>/Add'
   */
  (void) Rte_Write_PP_SWC_CSPF_CSPF_TrastMode(VAR_Cspf_TrastMode_u8);

  /* Switch: '<S61>/Switch' incorporates:
   *  Constant: '<S61>/Constant2'
   */
  if (CAL_Cspf_flgKpLowNCtlSwt_b) {
    /* Outport: '<Root>/PP_SWC_CSPF_CSPF_RecKpLowNCtL' incorporates:
     *  Constant: '<S61>/Constant3'
     */
    (void) Rte_Write_PP_SWC_CSPF_CSPF_RecKpLowNCtL(CAL_Cspf_KpLowNCtl_f32);
  } else {
    /* Outport: '<Root>/PP_SWC_CSPF_CSPF_RecKpLowNCtL' */
    (void) Rte_Write_PP_SWC_CSPF_CSPF_RecKpLowNCtL(tmpRead_3);
  }

  /* End of Switch: '<S61>/Switch' */

  /* Switch: '<S59>/Switch' incorporates:
   *  Constant: '<S59>/Constant2'
   */
  if (CAL_Cspf_flgNDiffMaxSwt_b) {
    /* Outport: '<Root>/PP_SWC_CSPF_CSPF_RecNDiffMax' incorporates:
     *  Constant: '<S59>/Constant3'
     */
    (void) Rte_Write_PP_SWC_CSPF_CSPF_RecNDiffMax(CAL_Cspf_NDiffMax_f32);
  } else {
    /* Outport: '<Root>/PP_SWC_CSPF_CSPF_RecNDiffMax' */
    (void) Rte_Write_PP_SWC_CSPF_CSPF_RecNDiffMax(tmpRead_2);
  }

  /* End of Switch: '<S59>/Switch' */

  /* Switch: '<S60>/Switch' incorporates:
   *  Constant: '<S60>/Constant2'
   */
  if (CAL_Cspf_flgTrqMaxNCtLSwt_b) {
    /* Outport: '<Root>/PP_SWC_CSPF_CSPF_RecTrqMaxNCtL' incorporates:
     *  Constant: '<S60>/Constant3'
     */
    (void) Rte_Write_PP_SWC_CSPF_CSPF_RecTrqMaxNCtL(CAL_Cspf_TrqMaxNCtL_f32);
  } else {
    /* Outport: '<Root>/PP_SWC_CSPF_CSPF_RecTrqMaxNCtL' */
    (void) Rte_Write_PP_SWC_CSPF_CSPF_RecTrqMaxNCtL(tmpRead_1);
  }

  /* End of Switch: '<S60>/Switch' */

  /* Switch: '<S62>/Switch' incorporates:
   *  Constant: '<S62>/Constant2'
   */
  if (CAL_Cspf_flgTrqMinNCtlSwt_b) {
    /* Outport: '<Root>/PP_SWC_CSPF_CSPF_RecTrqMinNCtL' incorporates:
     *  Constant: '<S62>/Constant3'
     */
    (void) Rte_Write_PP_SWC_CSPF_CSPF_RecTrqMinNCtL(CAL_Cspf_TrqMinNCtl_f32);
  } else {
    /* Outport: '<Root>/PP_SWC_CSPF_CSPF_RecTrqMinNCtL' */
    (void) Rte_Write_PP_SWC_CSPF_CSPF_RecTrqMinNCtL(tmpRead_0);
  }

  /* End of Switch: '<S62>/Switch' */

  /* Switch: '<S63>/Switch' incorporates:
   *  Constant: '<S63>/Constant2'
   */
  if (CAL_Cspf_flgcTrqSLopeSwt_b) {
    /* Outport: '<Root>/PP_SWC_CSPF_CSPF_RecTrqSLope' incorporates:
     *  Constant: '<S63>/Constant3'
     */
    (void) Rte_Write_PP_SWC_CSPF_CSPF_RecTrqSLope(CAL_Cspf_TrqSLope_f32);
  } else {
    /* Outport: '<Root>/PP_SWC_CSPF_CSPF_RecTrqSLope' */
    (void) Rte_Write_PP_SWC_CSPF_CSPF_RecTrqSLope(tmpRead_5);
  }

  /* End of Switch: '<S63>/Switch' */

  /* Switch: '<S64>/Switch' incorporates:
   *  Constant: '<S64>/Constant2'
   */
  if (CAL_Cspf_flgTrqMaxSwt_b) {
    /* Outport: '<Root>/PP_SWC_CSPF_CSPF_RecTrqMax' incorporates:
     *  Constant: '<S64>/Constant3'
     */
    (void) Rte_Write_PP_SWC_CSPF_CSPF_RecTrqMax(CAL_Cspf_TrqMax_f32);
  } else {
    /* Outport: '<Root>/PP_SWC_CSPF_CSPF_RecTrqMax' */
    (void) Rte_Write_PP_SWC_CSPF_CSPF_RecTrqMax(tmpRead_7);
  }

  /* End of Switch: '<S64>/Switch' */

  /* Switch: '<S65>/Switch' incorporates:
   *  Constant: '<S65>/Constant2'
   */
  if (CAL_Cspf_flgTrqMinSwt_b) {
    /* Outport: '<Root>/PP_SWC_CSPF_CSPF_RecTrqMin' incorporates:
     *  Constant: '<S65>/Constant3'
     */
    (void) Rte_Write_PP_SWC_CSPF_CSPF_RecTrqMin(CAL_Cspf_TrqMin_f32);
  } else {
    /* Outport: '<Root>/PP_SWC_CSPF_CSPF_RecTrqMin' */
    (void) Rte_Write_PP_SWC_CSPF_CSPF_RecTrqMin(tmpRead_6);
  }

  /* End of Switch: '<S65>/Switch' */

  /* Switch: '<S70>/Switch' incorporates:
   *  Constant: '<S70>/Constant2'
   */
  if (CAL_Cspf_flgNSetPSwt_b) {
    /* Outport: '<Root>/PP_SWC_CSPF_CSPF_RecNSetP' incorporates:
     *  Constant: '<S70>/Constant3'
     */
    (void) Rte_Write_PP_SWC_CSPF_CSPF_RecNSetP(CAL_Cspf_NSetP_f32);
  } else {
    /* Outport: '<Root>/PP_SWC_CSPF_CSPF_RecNSetP' */
    (void) Rte_Write_PP_SWC_CSPF_CSPF_RecNSetP(tmpRead_a);
  }

  /* End of Switch: '<S70>/Switch' */

  /* Switch: '<S66>/Switch' incorporates:
   *  Constant: '<S66>/Constant2'
   */
  if (CAL_Cspf_flgstModeReqSwt_b) {
    /* Outport: '<Root>/PP_SWC_CSPF_CSPF_RecstModeReq' incorporates:
     *  Constant: '<S66>/Constant3'
     */
    (void) Rte_Write_PP_SWC_CSPF_CSPF_RecstModeReq(CAL_Cspf_stModeReq_u8);
  } else {
    /* Outport: '<Root>/PP_SWC_CSPF_CSPF_RecstModeReq' */
    (void) Rte_Write_PP_SWC_CSPF_CSPF_RecstModeReq(tmpRead_9);
  }

  /* End of Switch: '<S66>/Switch' */

  /* Switch: '<S67>/Switch' incorporates:
   *  Constant: '<S67>/Constant2'
   */
  if (CAL_Cspf_flgTrqSetPSwt_b) {
    /* Outport: '<Root>/PP_SWC_CSPF_CSPF_RecTrqSetP' incorporates:
     *  Constant: '<S67>/Constant3'
     */
    (void) Rte_Write_PP_SWC_CSPF_CSPF_RecTrqSetP(CAL_Cspf_TrqSetP_f32);
  } else {
    /* Outport: '<Root>/PP_SWC_CSPF_CSPF_RecTrqSetP' */
    (void) Rte_Write_PP_SWC_CSPF_CSPF_RecTrqSetP(tmpRead_8);
  }

  /* End of Switch: '<S67>/Switch' */

  /* Switch: '<S72>/Switch' incorporates:
   *  Constant: '<S72>/Constant2'
   */
  if (CAL_Cspf_flgkDmpSwt_b) {
    /* Outport: '<Root>/PP_SWC_CSPF_CSPF_RecKpDmp' incorporates:
     *  Constant: '<S72>/Constant3'
     */
    (void) Rte_Write_PP_SWC_CSPF_CSPF_RecKpDmp(CAL_Cspf_kDmp_f32);
  } else {
    /* Outport: '<Root>/PP_SWC_CSPF_CSPF_RecKpDmp' */
    (void) Rte_Write_PP_SWC_CSPF_CSPF_RecKpDmp(tmpRead_e);
  }

  /* End of Switch: '<S72>/Switch' */

  /* Switch: '<S94>/Switch' incorporates:
   *  Constant: '<S94>/Constant2'
   *  Constant: '<S94>/Constant3'
   *  Inport: '<Root>/RP_SWC_Rdc_Rdc_ArctanAgRtr'
   */
  if (CAL_Cspf_flgagRtrEeSwt_b) {
    VAR_Cspf_TraagRtrELecSnsr_f32 = CAL_Cspf_agRtrEe_f32;
  }

  /* End of Switch: '<S94>/Switch' */

  /* Outport: '<Root>/PP_SWC_CSPF_CSPF_TraagRtrELecSnsr' incorporates:
   *  Sum: '<S80>/Add12'
   */
  (void) Rte_Write_PP_SWC_CSPF_CSPF_TraagRtrELecSnsr
    (VAR_Cspf_TraagRtrELecSnsr_f32);

  /* Switch: '<S95>/Switch' incorporates:
   *  Constant: '<S95>/Constant2'
   *  Constant: '<S95>/Constant3'
   *  DataTypeConversion: '<S95>/Data Type Conversion'
   *  Inport: '<Root>/RP_SWC_RCF_RCF_flgOfsClbSuc'
   */
  if (CAL_Cspf_flgOfsClbSucSwt_b) {
    VAR_Cspf_TraflgOfsClbSuc_u8 = CAL_Cspf_flgOfsClbSuc_u8;
  } else {
    Rte_Read_RP_SWC_RCF_RCF_flgOfsClbSuc(&tmpRead_i);
    VAR_Cspf_TraflgOfsClbSuc_u8 = tmpRead_i;
  }

  /* End of Switch: '<S95>/Switch' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_CSPF_10ms' */

  /* Inport: '<Root>/RP_SWC_TDC_TDC_TrqDes' */
  Rte_Read_RP_SWC_TDC_TDC_TrqDes(&VAR_Cspf_TraTrqCurrWoDmpC_f32);

  /* Inport: '<Root>/RP_SWC_RCF_RCF_AutoClbOffset' */
  Rte_Read_RP_SWC_RCF_RCF_AutoClbOffset(&VAR_Cspf_TraOfsAL_f32);

  /* Inport: '<Root>/RP_SWC_MPC_MPC_isqFlt' */
  Rte_Read_RP_SWC_MPC_MPC_isqFlt(&VAR_Cspf_Traisq_f32);

  /* Inport: '<Root>/RP_SWC_MPC_MPC_isdFlt' */
  Rte_Read_RP_SWC_MPC_MPC_isdFlt(&VAR_Cspf_Traisd_f32);

  /* Inport: '<Root>/RP_SWC_Com_Com_VCU05_stDmpCtLReq' */
  Rte_Read_RP_SWC_Com_Com_VCU05_stDmpCtLReq(&tmpRead_d);

  /* Inport: '<Root>/RP_SWC_Com_Com_VCU05_TrqDmpMax' */
  Rte_Read_RP_SWC_Com_Com_VCU05_TrqDmpMax(&tmpRead_b);

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_CSPF_10ms' incorporates:
   *  SubSystem: '<Root>/RE_SWC_CSPF_10ms_sys'
   */
  /* Outport: '<Root>/PP_SWC_CSPF_CSPF_TrabDmpCActv' incorporates:
   *  Sum: '<S80>/Add13'
   */
  (void) Rte_Write_PP_SWC_CSPF_CSPF_TrabDmpCActv(VAR_Cspf_TraflgOfsClbSuc_u8);

  /* Switch: '<S96>/Switch' incorporates:
   *  Constant: '<S96>/Constant2'
   *  Constant: '<S96>/Constant3'
   *  Inport: '<Root>/RP_SWC_MPC_MPC_isdFlt'
   */
  if (CAL_Cspf_flgiDActSlowFltSwt_b) {
    VAR_Cspf_Traisd_f32 = CAL_Cspf_iDActSlowFlt_f32;
  }

  /* End of Switch: '<S96>/Switch' */

  /* Outport: '<Root>/PP_SWC_CSPF_CSPF_Traisd' incorporates:
   *  Sum: '<S80>/Add14'
   */
  (void) Rte_Write_PP_SWC_CSPF_CSPF_Traisd(VAR_Cspf_Traisd_f32);

  /* Switch: '<S74>/Switch' incorporates:
   *  Constant: '<S74>/Constant2'
   */
  if (CAL_Cspf_flgstDmpCtLReqSwt_b) {
    /* Outport: '<Root>/PP_SWC_CSPF_CSPF_RecstDmpCtLReq' incorporates:
     *  Constant: '<S74>/Constant3'
     */
    (void) Rte_Write_PP_SWC_CSPF_CSPF_RecstDmpCtLReq(CAL_Cspf_stDmpCtLReq_u8);
  } else {
    /* Outport: '<Root>/PP_SWC_CSPF_CSPF_RecstDmpCtLReq' */
    (void) Rte_Write_PP_SWC_CSPF_CSPF_RecstDmpCtLReq(tmpRead_d);
  }

  /* End of Switch: '<S74>/Switch' */

  /* Switch: '<S97>/Switch' incorporates:
   *  Constant: '<S97>/Constant2'
   *  Constant: '<S97>/Constant3'
   *  Inport: '<Root>/RP_SWC_MPC_MPC_isqFlt'
   */
  if (CAL_Cspf_flgiQActSlowFltSwt_b) {
    VAR_Cspf_Traisq_f32 = CAL_Cspf_iQActSlowFlt_f32;
  }

  /* End of Switch: '<S97>/Switch' */

  /* Outport: '<Root>/PP_SWC_CSPF_CSPF_Traisq' incorporates:
   *  Sum: '<S80>/Add15'
   */
  (void) Rte_Write_PP_SWC_CSPF_CSPF_Traisq(VAR_Cspf_Traisq_f32);

  /* Switch: '<S99>/Switch' incorporates:
   *  Constant: '<S99>/Constant2'
   *  Constant: '<S99>/Constant3'
   *  Inport: '<Root>/RP_SWC_TDC_TDC_TrqDes'
   */
  if (CAL_Cspf_flgTrqCurrWoDmpCSwt_b) {
    VAR_Cspf_TraTrqCurrWoDmpC_f32 = CAL_Cspf_TrqCurrWoDmpC_f32;
  }

  /* End of Switch: '<S99>/Switch' */

  /* Outport: '<Root>/PP_SWC_CSPF_CSPF_TraTrqCurrWoDmpC' incorporates:
   *  Sum: '<S80>/Add17'
   */
  (void) Rte_Write_PP_SWC_CSPF_CSPF_TraTrqCurrWoDmpC
    (VAR_Cspf_TraTrqCurrWoDmpC_f32);

  /* Switch: '<S98>/Switch' incorporates:
   *  Constant: '<S98>/Constant2'
   *  Constant: '<S98>/Constant3'
   *  Inport: '<Root>/RP_SWC_RCF_RCF_AutoClbOffset'
   */
  if (CAL_Cspf_flgagOffsetSwt_b) {
    VAR_Cspf_TraOfsAL_f32 = CAL_Cspf_agOffset_f32;
  }

  /* End of Switch: '<S98>/Switch' */

  /* Outport: '<Root>/PP_SWC_CSPF_CSPF_TraOfsAL' incorporates:
   *  Sum: '<S80>/Add16'
   */
  (void) Rte_Write_PP_SWC_CSPF_CSPF_TraOfsAL(VAR_Cspf_TraOfsAL_f32);

  /* Switch: '<S76>/Switch' incorporates:
   *  Constant: '<S76>/Constant2'
   */
  if (CAL_Cspf_flgTrqDmpMaxSwt_b) {
    /* Outport: '<Root>/PP_SWC_CSPF_CSPF_RecTrqDmpMax' incorporates:
     *  Constant: '<S76>/Constant3'
     */
    (void) Rte_Write_PP_SWC_CSPF_CSPF_RecTrqDmpMax(CAL_Cspf_TrqDmpMax_f32);
  } else {
    /* Outport: '<Root>/PP_SWC_CSPF_CSPF_RecTrqDmpMax' */
    (void) Rte_Write_PP_SWC_CSPF_CSPF_RecTrqDmpMax(tmpRead_b);
  }

  /* End of Switch: '<S76>/Switch' */

  /* SignalConversion generated from: '<S2>/RP_SWC_Cpld_Cpld_IgbtState_read' incorporates:
   *  Inport: '<Root>/RP_SWC_Cpld_Cpld_IgbtState'
   */
  Rte_Read_RP_SWC_Cpld_Cpld_IgbtState(&rtb_TmpSignalConversionAtRP_SWC);

  /* SignalConversion generated from: '<S2>/RP_SWC_SCF_SCF_stGateDrv_read' incorporates:
   *  Inport: '<Root>/RP_SWC_SCF_SCF_stGateDrv'
   */
  Rte_Read_RP_SWC_SCF_SCF_stGateDrv(&rtb_TmpSignalConversionAtRP_S_j);

  /* Switch: '<S100>/Switch4' incorporates:
   *  Constant: '<S100>/Constant'
   *  Constant: '<S100>/Constant1'
   *  Constant: '<S100>/Constant3'
   *  Constant: '<S100>/Constant4'
   *  Constant: '<S100>/Constant5'
   *  Constant: '<S46>/CSPF_GLB_IGBTCLOSE_u8'
   *  Constant: '<S46>/CSPF_GLB_PWMRUN_u8'
   *  Logic: '<S100>/Logical Operator'
   *  Logic: '<S100>/Logical Operator1'
   *  RelationalOperator: '<S100>/Relational Operator'
   *  RelationalOperator: '<S100>/Relational Operator1'
   *  RelationalOperator: '<S100>/Relational Operator2'
   *  RelationalOperator: '<S100>/Relational Operator3'
   *  RelationalOperator: '<S100>/Relational Operator4'
   *  RelationalOperator: '<S100>/Relational Operator5'
   *  Switch: '<S100>/Switch2'
   *  Switch: '<S100>/Switch5'
   *  Switch: '<S100>/Switch9'
   *  UnitDelay: '<S100>/Unit Delay'
   */
  if (rtb_TmpSignalConversionAtRP_SWC == ((uint8)CSPF_IGBTASCUpCPLD_u8)) {
    SWC_CSPF_DW.UnitDelay_DSTATE_j = ((uint8)CSPF_IGBTAscUp_u8);
  } else if (rtb_TmpSignalConversionAtRP_SWC == ((uint8)CSPF_IGBTASCDownCPLD_u8))
  {
    /* UnitDelay: '<S100>/Unit Delay' incorporates:
     *  Constant: '<S100>/Constant6'
     *  Switch: '<S100>/Switch5'
     */
    SWC_CSPF_DW.UnitDelay_DSTATE_j = ((uint8)CSPF_IGBTAscDwn_u8);
  } else if ((rtb_TmpSignalConversionAtRP_SWC == ((uint8)CSPF_IGBTCloseCPLD_u8))
             && (rtb_TmpSignalConversionAtRP_S_j == ((uint8)
               CSPF_GLB_IGBTCLOSE_u8))) {
    /* UnitDelay: '<S100>/Unit Delay' incorporates:
     *  Constant: '<S100>/Constant24'
     *  Switch: '<S100>/Switch5'
     *  Switch: '<S100>/Switch9'
     */
    SWC_CSPF_DW.UnitDelay_DSTATE_j = ((uint8)CSPF_IGBTclose_u8);
  } else {
    if ((rtb_TmpSignalConversionAtRP_S_j == ((uint8)CSPF_GLB_PWMRUN_u8)) &&
        (rtb_TmpSignalConversionAtRP_SWC == ((uint8)CSPF_IGBTRunCPLD_u8))) {
      /* Switch: '<S100>/Switch2' incorporates:
       *  Constant: '<S100>/Constant2'
       *  Switch: '<S100>/Switch5'
       *  Switch: '<S100>/Switch9'
       *  UnitDelay: '<S100>/Unit Delay'
       */
      SWC_CSPF_DW.UnitDelay_DSTATE_j = ((uint8)CSPF_IGBTRun_u8);
    }
  }

  /* End of Switch: '<S100>/Switch4' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_CSPF_10ms' */

  /* Inport: '<Root>/RP_SWC_SCF_SCF_stDisChg' */
  Rte_Read_RP_SWC_SCF_SCF_stDisChg(&VAR_Cspf_TrastDischg_u8);

  /* Inport: '<Root>/RP_SWC_HSPF_HSPF_tStrrTemp2Flt' */
  Rte_Read_RP_SWC_HSPF_HSPF_tStrrTemp2Flt(&VAR_Cspf_TraTempCurrStr2_f32);

  /* Inport: '<Root>/RP_SWC_HSPF_HSPF_tStrrTemp1Flt' */
  Rte_Read_RP_SWC_HSPF_HSPF_tStrrTemp1Flt(&VAR_Cspf_TraTempCurrStr1_f32);

  /* Inport: '<Root>/RP_SWC_HSPF_HSPF_tCoolantTempFlt' */
  Rte_Read_RP_SWC_HSPF_HSPF_tCoolantTempFlt(&VAR_Cspf_TraTempCurrCooL_f32);

  /* Inport: '<Root>/RP_SWC_HSPF_HSPF_tDBCTempWFlt' */
  Rte_Read_RP_SWC_HSPF_HSPF_tDBCTempWFlt(&VAR_Cspf_TraiGBTTempW_f32);

  /* Inport: '<Root>/RP_SWC_HSPF_HSPF_tDBCTempVFlt' */
  Rte_Read_RP_SWC_HSPF_HSPF_tDBCTempVFlt(&VAR_Cspf_TraiGBTTempV_f32);

  /* Inport: '<Root>/RP_SWC_HSPF_HSPF_tDBCTempUFlt' */
  Rte_Read_RP_SWC_HSPF_HSPF_tDBCTempUFlt(&VAR_Cspf_TraiGBTTempU_f32);

  /* Inport: '<Root>/RP_SWC_Com_Com_RecflgDchaReq' */
  Rte_Read_RP_SWC_Com_Com_RecflgDchaReq(&tmpRead_f);

  /* Inport: '<Root>/RP_SWC_Com_Com_VCU05_TrqDmpMin' */
  Rte_Read_RP_SWC_Com_Com_VCU05_TrqDmpMin(&tmpRead_c);

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_CSPF_10ms' incorporates:
   *  SubSystem: '<Root>/RE_SWC_CSPF_10ms_sys'
   */
  /* Switch: '<S101>/Switch' incorporates:
   *  Constant: '<S101>/Constant2'
   *  Constant: '<S101>/Constant3'
   *  UnitDelay: '<S100>/Unit Delay'
   */
  if (CAL_Cspf_flgstGateDrvSwt_b) {
    VAR_Cspf_TrastGateDrv_u8 = CAL_Cspf_stGateDrv_u8;
  } else {
    VAR_Cspf_TrastGateDrv_u8 = SWC_CSPF_DW.UnitDelay_DSTATE_j;
  }

  /* End of Switch: '<S101>/Switch' */

  /* Outport: '<Root>/PP_SWC_CSPF_CSPF_TrastGateDrv' incorporates:
   *  Sum: '<S80>/Add1'
   */
  (void) Rte_Write_PP_SWC_CSPF_CSPF_TrastGateDrv(VAR_Cspf_TrastGateDrv_u8);

  /* Switch: '<S90>/Switch' incorporates:
   *  Constant: '<S90>/Constant2'
   *  Constant: '<S90>/Constant3'
   *  Inport: '<Root>/RP_SWC_HSPF_HSPF_tDBCTempUFlt'
   */
  if (CAL_Cspf_flgtDBCTempUFltSwt_b) {
    VAR_Cspf_TraiGBTTempU_f32 = CAL_Cspf_tDBCTempUFlt_f32;
  }

  /* End of Switch: '<S90>/Switch' */

  /* Outport: '<Root>/PP_SWC_CSPF_CSPF_TraiGBTTempU' incorporates:
   *  Sum: '<S79>/Add6'
   */
  (void) Rte_Write_PP_SWC_CSPF_CSPF_TraiGBTTempU(VAR_Cspf_TraiGBTTempU_f32);

  /* Switch: '<S91>/Switch' incorporates:
   *  Constant: '<S91>/Constant2'
   *  Constant: '<S91>/Constant3'
   *  Inport: '<Root>/RP_SWC_HSPF_HSPF_tDBCTempVFlt'
   */
  if (CAL_Cspf_flgtDBCTempVFltSwt_b) {
    VAR_Cspf_TraiGBTTempV_f32 = CAL_Cspf_tDBCTempVFlt_f32;
  }

  /* End of Switch: '<S91>/Switch' */

  /* Outport: '<Root>/PP_SWC_CSPF_CSPF_TraiGBTTempV' incorporates:
   *  Sum: '<S79>/Add7'
   */
  (void) Rte_Write_PP_SWC_CSPF_CSPF_TraiGBTTempV(VAR_Cspf_TraiGBTTempV_f32);

  /* Switch: '<S75>/Switch' incorporates:
   *  Constant: '<S75>/Constant2'
   */
  if (CAL_Cspf_flgTrqDmpMinSwt_b) {
    /* Outport: '<Root>/PP_SWC_CSPF_CSPF_RecTrqDmpMin' incorporates:
     *  Constant: '<S75>/Constant3'
     */
    (void) Rte_Write_PP_SWC_CSPF_CSPF_RecTrqDmpMin(CAL_Cspf_TrqDmpLim_f32);
  } else {
    /* Outport: '<Root>/PP_SWC_CSPF_CSPF_RecTrqDmpMin' */
    (void) Rte_Write_PP_SWC_CSPF_CSPF_RecTrqDmpMin(tmpRead_c);
  }

  /* End of Switch: '<S75>/Switch' */

  /* Switch: '<S92>/Switch' incorporates:
   *  Constant: '<S92>/Constant2'
   *  Constant: '<S92>/Constant3'
   *  Inport: '<Root>/RP_SWC_HSPF_HSPF_tDBCTempWFlt'
   */
  if (CAL_Cspf_flgtDBCTempWFltSwt_b) {
    VAR_Cspf_TraiGBTTempW_f32 = CAL_Cspf_tDBCTempWFlt_f32;
  }

  /* End of Switch: '<S92>/Switch' */

  /* Outport: '<Root>/PP_SWC_CSPF_CSPF_TraiGBTTempW' incorporates:
   *  Sum: '<S79>/Add8'
   */
  (void) Rte_Write_PP_SWC_CSPF_CSPF_TraiGBTTempW(VAR_Cspf_TraiGBTTempW_f32);

  /* Switch: '<S93>/Switch' incorporates:
   *  Constant: '<S93>/Constant2'
   *  Constant: '<S93>/Constant3'
   *  Inport: '<Root>/RP_SWC_HSPF_HSPF_tStrrTemp1Flt'
   */
  if (CAL_Cspf_flgtStrrTemp1FltSwt_b) {
    VAR_Cspf_TraTempCurrStr1_f32 = CAL_Cspf_tStrrTemp1Flt_f32;
  }

  /* End of Switch: '<S93>/Switch' */

  /* Outport: '<Root>/PP_SWC_CSPF_CSPF_TraTempCurrStr1' incorporates:
   *  Sum: '<S79>/Add10'
   */
  (void) Rte_Write_PP_SWC_CSPF_CSPF_TraTempCurrStr1(VAR_Cspf_TraTempCurrStr1_f32);

  /* Switch: '<S89>/Switch' incorporates:
   *  Constant: '<S89>/Constant2'
   *  Constant: '<S89>/Constant3'
   *  Inport: '<Root>/RP_SWC_HSPF_HSPF_tStrrTemp2Flt'
   */
  if (CAL_Cspf_flgtStrrTemp2FltSwt_b) {
    VAR_Cspf_TraTempCurrStr2_f32 = CAL_Cspf_tStrrTemp2Flt_f32;
  }

  /* End of Switch: '<S89>/Switch' */

  /* Outport: '<Root>/PP_SWC_CSPF_CSPF_TraTempCurrStr2' incorporates:
   *  Sum: '<S79>/Add11'
   */
  (void) Rte_Write_PP_SWC_CSPF_CSPF_TraTempCurrStr2(VAR_Cspf_TraTempCurrStr2_f32);

  /* Switch: '<S50>/Switch' incorporates:
   *  Constant: '<S50>/Constant2'
   */
  if (CAL_Cspf_flgDchaReqSwt_b) {
    /* Outport: '<Root>/PP_SWC_CSPF_CSPF_RecflgDchaReq' incorporates:
     *  Constant: '<S50>/Constant3'
     */
    (void) Rte_Write_PP_SWC_CSPF_CSPF_RecflgDchaReq(CAL_Cspf_flgDchaReq_b);
  } else {
    /* Outport: '<Root>/PP_SWC_CSPF_CSPF_RecflgDchaReq' */
    (void) Rte_Write_PP_SWC_CSPF_CSPF_RecflgDchaReq(tmpRead_f);
  }

  /* End of Switch: '<S50>/Switch' */

  /* Switch: '<S82>/Switch' incorporates:
   *  Constant: '<S82>/Constant2'
   *  Constant: '<S82>/Constant3'
   *  Inport: '<Root>/RP_SWC_HSPF_HSPF_tCoolantTempFlt'
   */
  if (CAL_Cspf_flgtCoolantTempFltSwt_b) {
    VAR_Cspf_TraTempCurrCooL_f32 = CAL_Cspf_tCoolantTempFlt_f32;
  }

  /* End of Switch: '<S82>/Switch' */

  /* Outport: '<Root>/PP_SWC_CSPF_CSPF_TraTempCurrCooL' incorporates:
   *  Sum: '<S77>/Add9'
   */
  (void) Rte_Write_PP_SWC_CSPF_CSPF_TraTempCurrCooL(VAR_Cspf_TraTempCurrCooL_f32);

  /* Switch: '<S102>/Switch' incorporates:
   *  Constant: '<S102>/Constant2'
   *  Constant: '<S102>/Constant3'
   *  Inport: '<Root>/RP_SWC_SCF_SCF_stDisChg'
   */
  if (CAL_Cspf_flgstDisChgSwt_b) {
    VAR_Cspf_TrastDischg_u8 = CAL_Cspf_stDisChg_u8;
  }

  /* End of Switch: '<S102>/Switch' */

  /* Outport: '<Root>/PP_SWC_CSPF_CSPF_TrastDischg' incorporates:
   *  Sum: '<S81>/Add18'
   */
  (void) Rte_Write_PP_SWC_CSPF_CSPF_TrastDischg(VAR_Cspf_TrastDischg_u8);

  /* FunctionCaller: '<S2>/RP_SWC_IoHwAb_ADC_BSW_HwVer_IoHwAb_ADC_GetPhyVoltage' incorporates:
   *  Constant: '<S2>/Constant9'
   */
  Rte_Call_RP_SWC_IoHwAb_ADC_BSW_HwVer_IoHwAb_ADC_GetPhyVoltage(29,
    &rtb_RP_SWC_IoHwAb_ADC_BSW_HwVer);

  /* Switch: '<S103>/Switch' incorporates:
   *  Constant: '<S103>/Constant2'
   *  Constant: '<S103>/Constant3'
   *  DataTypeConversion: '<S103>/Data Type Conversion'
   */
  if (CAL_Cspf_flgHwVerSwt_b) {
    VAR_Cspf_TraHwVer_u16 = CAL_Cspf_HwVer_u16;
  } else {
    /* DataTypeConversion: '<S103>/Data Type Conversion' */
    tmpRead_4 = fmodf(floorf(rtb_RP_SWC_IoHwAb_ADC_BSW_HwVer), 65536.0F);
    VAR_Cspf_TraHwVer_u16 = (uint16)(tmpRead_4 < 0.0F ? (sint32)(uint16)-(sint16)
      (uint16)-tmpRead_4 : (sint32)(uint16)tmpRead_4);
  }

  /* End of Switch: '<S103>/Switch' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_CSPF_10ms' */

  /* Inport: '<Root>/RP_SWC_Com_Com_VCU_flgCrash' */
  Rte_Read_RP_SWC_Com_Com_VCU_flgCrash(&tmpRead_j);

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_CSPF_10ms' incorporates:
   *  SubSystem: '<Root>/RE_SWC_CSPF_10ms_sys'
   */
  /* Outport: '<Root>/PP_SWC_CSPF_CSPF_TraHwVer' incorporates:
   *  Sum: '<S81>/Add19'
   */
  (void) Rte_Write_PP_SWC_CSPF_CSPF_TraHwVer(VAR_Cspf_TraHwVer_u16);

  /* Switch: '<S49>/Switch' incorporates:
   *  Constant: '<S49>/Constant2'
   */
  if (CAL_Cspf_flgCrashSwt_b) {
    /* Outport: '<Root>/PP_SWC_CSPF_CSPF_RecflgCrash' incorporates:
     *  Constant: '<S49>/Constant3'
     */
    (void) Rte_Write_PP_SWC_CSPF_CSPF_RecflgCrash(CAL_Cspf_flgCrash_b);
  } else {
    /* Outport: '<Root>/PP_SWC_CSPF_CSPF_RecflgCrash' */
    (void) Rte_Write_PP_SWC_CSPF_CSPF_RecflgCrash(tmpRead_j);
  }

  /* End of Switch: '<S49>/Switch' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_CSPF_10ms' */
}

/* Model step function for TID2 */
void SWC_CSPF_100ms(void)              /* Explicit Task: RE_SWC_CSPF_100ms */
{
  float32 tmpRead;
  float32 tmpRead_0;
  float32 tmpRead_1;
  float32 tmpRead_2;
  uint8 tmpRead_3;
  boolean tmpRead_4;
  boolean tmpRead_5;
  boolean tmpRead_6;
  boolean tmpRead_7;
  boolean tmpRead_8;
  boolean tmpRead_9;
  boolean tmpRead_a;
  boolean tmpRead_b;
  boolean tmpRead_c;
  boolean tmpRead_d;
  boolean tmpRead_e;
  boolean tmpRead_f;

  /* Inport: '<Root>/RP_SWC_Com_Com_VCU01_idcMax' */
  Rte_Read_RP_SWC_Com_Com_VCU01_idcMax(&tmpRead_1);

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_CSPF_100ms' incorporates:
   *  SubSystem: '<Root>/RE_SWC_CSPF_100ms_sys'
   */
  /* Switch: '<S11>/Switch' incorporates:
   *  Constant: '<S11>/Constant2'
   */
  if (CAL_Cspf_flgIdcMaxSwt_b) {
    /* Outport: '<Root>/PP_SWC_CSPF_CSPF_RecidcMax' incorporates:
     *  Constant: '<S11>/Constant3'
     */
    (void) Rte_Write_PP_SWC_CSPF_CSPF_RecidcMax(CAL_Cspf_IdcMax_f32);
  } else {
    /* Outport: '<Root>/PP_SWC_CSPF_CSPF_RecidcMax' */
    (void) Rte_Write_PP_SWC_CSPF_CSPF_RecidcMax(tmpRead_1);
  }

  /* End of Switch: '<S11>/Switch' */

  /* Switch: '<S16>/Switch' incorporates:
   *  Constant: '<S16>/Constant2'
   *  Constant: '<S16>/Constant3'
   *  DataTypeConversion: '<S16>/Data Type Conversion'
   *  Inport: '<Root>/RP_SWC_TPC_TPC_bDernCAN'
   */
  if (CAL_Cspf_flgbDernCANSwt_b) {
    VAR_Cspf_TrabDernCAN_u8 = CAL_Cspf_bDernCAN_u8;
  } else {
    Rte_Read_RP_SWC_TPC_TPC_bDernCAN(&tmpRead_4);
    VAR_Cspf_TrabDernCAN_u8 = tmpRead_4;
  }

  /* End of Switch: '<S16>/Switch' */

  /* Outport: '<Root>/PP_SWC_CSPF_CSPF_TrabDernCAN' incorporates:
   *  Sum: '<S14>/Add'
   */
  (void) Rte_Write_PP_SWC_CSPF_CSPF_TrabDernCAN(VAR_Cspf_TrabDernCAN_u8);

  /* Switch: '<S15>/Switch' incorporates:
   *  Constant: '<S15>/Constant2'
   *  Constant: '<S15>/Constant3'
   *  DataTypeConversion: '<S15>/Data Type Conversion'
   *  Inport: '<Root>/RP_SWC_TPC_TPC_bDernMtrSpd'
   */
  if (CAL_Cspf_flgbDernMtrSpdSwt_b) {
    VAR_Cspf_TrabDernN_u8 = CAL_Cspf_bDernMtrSpd_u8;
  } else {
    Rte_Read_RP_SWC_TPC_TPC_bDernMtrSpd(&tmpRead_5);
    VAR_Cspf_TrabDernN_u8 = tmpRead_5;
  }

  /* End of Switch: '<S15>/Switch' */

  /* Outport: '<Root>/PP_SWC_CSPF_CSPF_TrabDernN' incorporates:
   *  Sum: '<S14>/Add1'
   */
  (void) Rte_Write_PP_SWC_CSPF_CSPF_TrabDernN(VAR_Cspf_TrabDernN_u8);

  /* Switch: '<S24>/Switch' incorporates:
   *  Constant: '<S24>/Constant2'
   *  Constant: '<S24>/Constant3'
   *  DataTypeConversion: '<S24>/Data Type Conversion'
   *  Inport: '<Root>/RP_SWC_TPC_TPC_bDernOvrIdc'
   */
  if (CAL_Cspf_flgbDernOvrIdcSwt_b) {
    VAR_Cspf_TrabDernOvridc_u8 = CAL_Cspf_bDernOvrIdc_u8;
  } else {
    Rte_Read_RP_SWC_TPC_TPC_bDernOvrIdc(&tmpRead_6);
    VAR_Cspf_TrabDernOvridc_u8 = tmpRead_6;
  }

  /* End of Switch: '<S24>/Switch' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_CSPF_100ms' */

  /* Inport: '<Root>/RP_SWC_Com_Com_VCU01_idcMin' */
  Rte_Read_RP_SWC_Com_Com_VCU01_idcMin(&tmpRead_2);

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_CSPF_100ms' incorporates:
   *  SubSystem: '<Root>/RE_SWC_CSPF_100ms_sys'
   */
  /* Outport: '<Root>/PP_SWC_CSPF_CSPF_TrabDernOvridc' incorporates:
   *  Sum: '<S14>/Add2'
   */
  (void) Rte_Write_PP_SWC_CSPF_CSPF_TrabDernOvridc(VAR_Cspf_TrabDernOvridc_u8);

  /* Switch: '<S10>/Switch' incorporates:
   *  Constant: '<S10>/Constant2'
   */
  if (CAL_Cspf_flgIdcMinSwt_b) {
    /* Outport: '<Root>/PP_SWC_CSPF_CSPF_RecidcMin' incorporates:
     *  Constant: '<S10>/Constant3'
     */
    (void) Rte_Write_PP_SWC_CSPF_CSPF_RecidcMin(CAL_Cspf_IdcMin_f32);
  } else {
    /* Outport: '<Root>/PP_SWC_CSPF_CSPF_RecidcMin' */
    (void) Rte_Write_PP_SWC_CSPF_CSPF_RecidcMin(tmpRead_2);
  }

  /* End of Switch: '<S10>/Switch' */

  /* Switch: '<S25>/Switch' incorporates:
   *  Constant: '<S25>/Constant2'
   *  Constant: '<S25>/Constant3'
   *  DataTypeConversion: '<S25>/Data Type Conversion'
   *  Inport: '<Root>/RP_SWC_TPC_TPC_bDernOvrUdc'
   */
  if (CAL_Cspf_flgbDernOvrUdcSwt_b) {
    VAR_Cspf_TrabDernOvrUdc_u8 = CAL_Cspf_bDernOvrUdc_u8;
  } else {
    Rte_Read_RP_SWC_TPC_TPC_bDernOvrUdc(&tmpRead_7);
    VAR_Cspf_TrabDernOvrUdc_u8 = tmpRead_7;
  }

  /* End of Switch: '<S25>/Switch' */

  /* Outport: '<Root>/PP_SWC_CSPF_CSPF_TrabDernOvrUdc' incorporates:
   *  Sum: '<S14>/Add3'
   */
  (void) Rte_Write_PP_SWC_CSPF_CSPF_TrabDernOvrUdc(VAR_Cspf_TrabDernOvrUdc_u8);

  /* Switch: '<S26>/Switch' incorporates:
   *  Constant: '<S26>/Constant2'
   *  Constant: '<S26>/Constant3'
   *  DataTypeConversion: '<S26>/Data Type Conversion'
   *  Inport: '<Root>/RP_SWC_TPC_TPC_bDernStrTemp'
   */
  if (CAL_Cspf_flgbDernStrTempSwt_b) {
    VAR_Cspf_TrabDernStrTemp_u8 = CAL_Cspf_bDernStrTemp_u8;
  } else {
    Rte_Read_RP_SWC_TPC_TPC_bDernStrTemp(&tmpRead_8);
    VAR_Cspf_TrabDernStrTemp_u8 = tmpRead_8;
  }

  /* End of Switch: '<S26>/Switch' */

  /* Outport: '<Root>/PP_SWC_CSPF_CSPF_TrabDernStrTemp' incorporates:
   *  Sum: '<S14>/Add4'
   */
  (void) Rte_Write_PP_SWC_CSPF_CSPF_TrabDernStrTemp(VAR_Cspf_TrabDernStrTemp_u8);

  /* Switch: '<S27>/Switch' incorporates:
   *  Constant: '<S27>/Constant2'
   *  Constant: '<S27>/Constant3'
   *  DataTypeConversion: '<S27>/Data Type Conversion'
   *  Inport: '<Root>/RP_SWC_TPC_TPC_bDernCoolantTemp'
   */
  if (CAL_Cspf_flgbDernCoolantTempSwt_b) {
    VAR_Cspf_TrabDernTempCooL_u8 = CAL_Cspf_bDernCoolantTemp_u8;
  } else {
    Rte_Read_RP_SWC_TPC_TPC_bDernCoolantTemp(&tmpRead_9);
    VAR_Cspf_TrabDernTempCooL_u8 = tmpRead_9;
  }

  /* End of Switch: '<S27>/Switch' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_CSPF_100ms' */

  /* Inport: '<Root>/RP_SWC_Com_Com_VCU01_UdcMax' */
  Rte_Read_RP_SWC_Com_Com_VCU01_UdcMax(&tmpRead);

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_CSPF_100ms' incorporates:
   *  SubSystem: '<Root>/RE_SWC_CSPF_100ms_sys'
   */
  /* Outport: '<Root>/PP_SWC_CSPF_CSPF_TrabDernTempCooL' incorporates:
   *  Sum: '<S14>/Add5'
   */
  (void) Rte_Write_PP_SWC_CSPF_CSPF_TrabDernTempCooL
    (VAR_Cspf_TrabDernTempCooL_u8);

  /* Switch: '<S9>/Switch' incorporates:
   *  Constant: '<S9>/Constant2'
   */
  if (CAL_Cspf_flgUdcMaxSwt_b) {
    /* Outport: '<Root>/PP_SWC_CSPF_CSPF_RecUdcMax' incorporates:
     *  Constant: '<S9>/Constant3'
     */
    (void) Rte_Write_PP_SWC_CSPF_CSPF_RecUdcMax(CAL_Cspf_UdcMax_f32);
  } else {
    /* Outport: '<Root>/PP_SWC_CSPF_CSPF_RecUdcMax' */
    (void) Rte_Write_PP_SWC_CSPF_CSPF_RecUdcMax(tmpRead);
  }

  /* End of Switch: '<S9>/Switch' */

  /* Switch: '<S28>/Switch' incorporates:
   *  Constant: '<S28>/Constant2'
   *  Constant: '<S28>/Constant3'
   *  DataTypeConversion: '<S28>/Data Type Conversion'
   *  Inport: '<Root>/RP_SWC_TPC_TPC_bDernDbcTemp'
   */
  if (CAL_Cspf_flgbDernDbcTempSwt_b) {
    VAR_Cspf_TrabDernTempiGBT_u8 = CAL_Cspf_bDernDbcTemp_u8;
  } else {
    Rte_Read_RP_SWC_TPC_TPC_bDernDbcTemp(&tmpRead_a);
    VAR_Cspf_TrabDernTempiGBT_u8 = tmpRead_a;
  }

  /* End of Switch: '<S28>/Switch' */

  /* Outport: '<Root>/PP_SWC_CSPF_CSPF_TrabDernTempiGBT' incorporates:
   *  Sum: '<S14>/Add6'
   */
  (void) Rte_Write_PP_SWC_CSPF_CSPF_TrabDernTempiGBT
    (VAR_Cspf_TrabDernTempiGBT_u8);

  /* Switch: '<S31>/Switch' incorporates:
   *  Constant: '<S31>/Constant2'
   *  Constant: '<S31>/Constant3'
   *  DataTypeConversion: '<S31>/Data Type Conversion'
   *  Inport: '<Root>/RP_SWC_TPC_TPC_bDernUndrUdc'
   */
  if (CAL_Cspf_flgbDernUndrUdcSwt_b) {
    VAR_Cspf_TrabDernUndrUdc_u8 = CAL_Cspf_bDernUndrUdc_u8;
  } else {
    Rte_Read_RP_SWC_TPC_TPC_bDernUndrUdc(&tmpRead_d);
    VAR_Cspf_TrabDernUndrUdc_u8 = tmpRead_d;
  }

  /* End of Switch: '<S31>/Switch' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_CSPF_100ms' */

  /* Inport: '<Root>/RP_SWC_HSPF_HSPF_uKl30Flt' */
  Rte_Read_RP_SWC_HSPF_HSPF_uKl30Flt(&VAR_Cspf_TraUT30Curr_f32);

  /* Inport: '<Root>/RP_SWC_TPC_TPC_TrqMin' */
  Rte_Read_RP_SWC_TPC_TPC_TrqMin(&VAR_Cspf_TraTrqAbsMin_f32);

  /* Inport: '<Root>/RP_SWC_TPC_TPC_TrqMax' */
  Rte_Read_RP_SWC_TPC_TPC_TrqMax(&VAR_Cspf_TraTrqAbsMax_f32);

  /* Inport: '<Root>/RP_SWC_TPC_TPC_stTrqEmMin' */
  Rte_Read_RP_SWC_TPC_TPC_stTrqEmMin(&VAR_Cspf_TrastTrqEmMin_u8);

  /* Inport: '<Root>/RP_SWC_TPC_TPC_stTrqEmMax' */
  Rte_Read_RP_SWC_TPC_TPC_stTrqEmMax(&VAR_Cspf_TrastTrqEmMax_u8);

  /* Inport: '<Root>/RP_SWC_BCC_BCC_iDcLnkEstFlt' */
  Rte_Read_RP_SWC_BCC_BCC_iDcLnkEstFlt(&VAR_Cspf_TraidcCurr_f32);

  /* Inport: '<Root>/RP_SWC_Com_Com_VCU01_UdcMin' */
  Rte_Read_RP_SWC_Com_Com_VCU01_UdcMin(&tmpRead_0);

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_CSPF_100ms' incorporates:
   *  SubSystem: '<Root>/RE_SWC_CSPF_100ms_sys'
   */
  /* Outport: '<Root>/PP_SWC_CSPF_CSPF_TrabDernUndrUdc' incorporates:
   *  Sum: '<S14>/Add9'
   */
  (void) Rte_Write_PP_SWC_CSPF_CSPF_TrabDernUndrUdc(VAR_Cspf_TrabDernUndrUdc_u8);

  /* Switch: '<S18>/Switch' incorporates:
   *  Constant: '<S18>/Constant2'
   *  Constant: '<S18>/Constant3'
   *  Inport: '<Root>/RP_SWC_BCC_BCC_iDcLnkEstFlt'
   */
  if (CAL_Cspf_flgiDcLnkEstFltSwt_b) {
    VAR_Cspf_TraidcCurr_f32 = CAL_Cspf_iDcLnkEstFlt_f32;
  }

  /* End of Switch: '<S18>/Switch' */

  /* Outport: '<Root>/PP_SWC_CSPF_CSPF_TraidcCurr' incorporates:
   *  Sum: '<S14>/Add11'
   */
  (void) Rte_Write_PP_SWC_CSPF_CSPF_TraidcCurr(VAR_Cspf_TraidcCurr_f32);

  /* Switch: '<S8>/Switch' incorporates:
   *  Constant: '<S8>/Constant2'
   */
  if (CAL_Cspf_flgUdcMinSwt_b) {
    /* Outport: '<Root>/PP_SWC_CSPF_CSPF_RecUdcMin' incorporates:
     *  Constant: '<S8>/Constant3'
     */
    (void) Rte_Write_PP_SWC_CSPF_CSPF_RecUdcMin(CAL_Cspf_UdcMin_f32);
  } else {
    /* Outport: '<Root>/PP_SWC_CSPF_CSPF_RecUdcMin' */
    (void) Rte_Write_PP_SWC_CSPF_CSPF_RecUdcMin(tmpRead_0);
  }

  /* End of Switch: '<S8>/Switch' */

  /* Switch: '<S19>/Switch' incorporates:
   *  Constant: '<S19>/Constant2'
   *  Constant: '<S19>/Constant3'
   *  Inport: '<Root>/RP_SWC_TPC_TPC_stTrqEmMax'
   */
  if (CAL_Cspf_flgstTrqEmMaxSwt_b) {
    VAR_Cspf_TrastTrqEmMax_u8 = CAL_Cspf_stTrqEmMax_u8;
  }

  /* End of Switch: '<S19>/Switch' */

  /* Outport: '<Root>/PP_SWC_CSPF_CSPF_TrastTrqEmMax' incorporates:
   *  Sum: '<S14>/Add12'
   */
  (void) Rte_Write_PP_SWC_CSPF_CSPF_TrastTrqEmMax(VAR_Cspf_TrastTrqEmMax_u8);

  /* Switch: '<S20>/Switch' incorporates:
   *  Constant: '<S20>/Constant2'
   *  Constant: '<S20>/Constant3'
   *  Inport: '<Root>/RP_SWC_TPC_TPC_stTrqEmMin'
   */
  if (CAL_Cspf_flgstTrqEmMinSwt_b) {
    VAR_Cspf_TrastTrqEmMin_u8 = CAL_Cspf_stTrqEmMin_u8;
  }

  /* End of Switch: '<S20>/Switch' */

  /* Outport: '<Root>/PP_SWC_CSPF_CSPF_TrastTrqEmMin' incorporates:
   *  Sum: '<S14>/Add13'
   */
  (void) Rte_Write_PP_SWC_CSPF_CSPF_TrastTrqEmMin(VAR_Cspf_TrastTrqEmMin_u8);

  /* Switch: '<S21>/Switch' incorporates:
   *  Constant: '<S21>/Constant2'
   *  Constant: '<S21>/Constant3'
   *  Inport: '<Root>/RP_SWC_TPC_TPC_TrqMax'
   */
  if (CAL_Cspf_flgTraTrqMaxSwt_b) {
    VAR_Cspf_TraTrqAbsMax_f32 = CAL_Cspf_TraTrqMax_f32;
  }

  /* End of Switch: '<S21>/Switch' */

  /* Outport: '<Root>/PP_SWC_CSPF_CSPF_TraTrqAbsMax' incorporates:
   *  Sum: '<S14>/Add14'
   */
  (void) Rte_Write_PP_SWC_CSPF_CSPF_TraTrqAbsMax(VAR_Cspf_TraTrqAbsMax_f32);

  /* Switch: '<S22>/Switch' incorporates:
   *  Constant: '<S22>/Constant2'
   *  Constant: '<S22>/Constant3'
   *  Inport: '<Root>/RP_SWC_TPC_TPC_TrqMin'
   */
  if (CAL_Cspf_flgTraTrqMinSwt_b) {
    VAR_Cspf_TraTrqAbsMin_f32 = CAL_Cspf_TraTrqMin_f32;
  }

  /* End of Switch: '<S22>/Switch' */

  /* Outport: '<Root>/PP_SWC_CSPF_CSPF_TraTrqAbsMin' incorporates:
   *  Sum: '<S14>/Add15'
   */
  (void) Rte_Write_PP_SWC_CSPF_CSPF_TraTrqAbsMin(VAR_Cspf_TraTrqAbsMin_f32);

  /* Switch: '<S23>/Switch' incorporates:
   *  Constant: '<S23>/Constant2'
   *  Constant: '<S23>/Constant3'
   *  Inport: '<Root>/RP_SWC_HSPF_HSPF_uKl30Flt'
   */
  if (CAL_Cspf_flguKl30FltSwt_b) {
    VAR_Cspf_TraUT30Curr_f32 = CAL_Cspf_uKl30Flt_f32;
  }

  /* End of Switch: '<S23>/Switch' */

  /* Outport: '<Root>/PP_SWC_CSPF_CSPF_TraUT30Curr' incorporates:
   *  Sum: '<S14>/Add16'
   */
  (void) Rte_Write_PP_SWC_CSPF_CSPF_TraUT30Curr(VAR_Cspf_TraUT30Curr_f32);

  /* Switch: '<S29>/Switch' incorporates:
   *  Constant: '<S29>/Constant2'
   *  Constant: '<S29>/Constant3'
   *  DataTypeConversion: '<S29>/Data Type Conversion'
   *  Inport: '<Root>/RP_SWC_TPC_TPC_bDernExcMax'
   */
  if (CAL_Cspf_flgbDernExcMaxSwt_b) {
    VAR_Cspf_TrabDernTrqMax_u8 = CAL_Cspf_bDernExcMax_u8;
  } else {
    Rte_Read_RP_SWC_TPC_TPC_bDernExcMax(&tmpRead_b);
    VAR_Cspf_TrabDernTrqMax_u8 = tmpRead_b;
  }

  /* End of Switch: '<S29>/Switch' */

  /* Outport: '<Root>/PP_SWC_CSPF_CSPF_TrabDernTrqMax' incorporates:
   *  Sum: '<S14>/Add7'
   */
  (void) Rte_Write_PP_SWC_CSPF_CSPF_TrabDernTrqMax(VAR_Cspf_TrabDernTrqMax_u8);

  /* Switch: '<S30>/Switch' incorporates:
   *  Constant: '<S30>/Constant2'
   *  Constant: '<S30>/Constant3'
   *  DataTypeConversion: '<S30>/Data Type Conversion'
   *  Inport: '<Root>/RP_SWC_TPC_TPC_bDernExcMin'
   */
  if (CAL_Cspf_flgbDernExcMinSwt_b) {
    VAR_Cspf_TrabDernTrqMin_u8 = CAL_Cspf_bDernExcMin_u8;
  } else {
    Rte_Read_RP_SWC_TPC_TPC_bDernExcMin(&tmpRead_c);
    VAR_Cspf_TrabDernTrqMin_u8 = tmpRead_c;
  }

  /* End of Switch: '<S30>/Switch' */

  /* Outport: '<Root>/PP_SWC_CSPF_CSPF_TrabDernTrqMin' incorporates:
   *  Sum: '<S14>/Add8'
   */
  (void) Rte_Write_PP_SWC_CSPF_CSPF_TrabDernTrqMin(VAR_Cspf_TrabDernTrqMin_u8);

  /* Switch: '<S17>/Switch' incorporates:
   *  Constant: '<S17>/Constant2'
   *  Constant: '<S17>/Constant3'
   *  DataTypeConversion: '<S17>/Data Type Conversion'
   *  Inport: '<Root>/RP_SWC_SCF_SCF_bHvReady'
   */
  if (CAL_Cspf_flgbReadyHVSwt_b) {
    VAR_Cspf_TrabReadyHV_u8 = CAL_Cspf_bReadyHV_u8;
  } else {
    Rte_Read_RP_SWC_SCF_SCF_bHvReady(&tmpRead_f);
    VAR_Cspf_TrabReadyHV_u8 = tmpRead_f;
  }

  /* End of Switch: '<S17>/Switch' */

  /* Outport: '<Root>/PP_SWC_CSPF_CSPF_TrabReadyHv' incorporates:
   *  Sum: '<S14>/Add27'
   */
  (void) Rte_Write_PP_SWC_CSPF_CSPF_TrabReadyHv(VAR_Cspf_TrabReadyHV_u8);

  /* Switch: '<S34>/Switch' incorporates:
   *  Constant: '<S34>/Constant2'
   *  Constant: '<S34>/Constant3'
   *  DataTypeConversion: '<S34>/Data Type Conversion'
   *  Inport: '<Root>/RP_SWC_TPC_TPC_bDernDrvBoardTemp'
   */
  if (CAL_Cspf_flgbDernDrvBoardTempSwt_b) {
    VAR_Cspf_TrabDernDrvBoardTemp_u16 = CAL_Cspf_bDernDrvBoardTemp_u16;
  } else {
    Rte_Read_RP_SWC_TPC_TPC_bDernDrvBoardTemp(&tmpRead_e);
    VAR_Cspf_TrabDernDrvBoardTemp_u16 = tmpRead_e;
  }

  /* End of Switch: '<S34>/Switch' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_CSPF_100ms' */

  /* Inport: '<Root>/RP_SWC_DiagCalib_DiagCalib_FailCode8' */
  Rte_Read_RP_SWC_DiagCalib_DiagCalib_FailCode8(&VAR_Cspf_TraFailCode8_u8);

  /* Inport: '<Root>/RP_SWC_DiagCalib_DiagCalib_FailCode7' */
  Rte_Read_RP_SWC_DiagCalib_DiagCalib_FailCode7(&VAR_Cspf_TraFailCode7_u8);

  /* Inport: '<Root>/RP_SWC_DiagCalib_DiagCalib_FailCode6' */
  Rte_Read_RP_SWC_DiagCalib_DiagCalib_FailCode6(&VAR_Cspf_TraFailCode6_u8);

  /* Inport: '<Root>/RP_SWC_DiagCalib_DiagCalib_FailCode5' */
  Rte_Read_RP_SWC_DiagCalib_DiagCalib_FailCode5(&VAR_Cspf_TraFailCode5_u8);

  /* Inport: '<Root>/RP_SWC_DiagCalib_DiagCalib_FailCode4' */
  Rte_Read_RP_SWC_DiagCalib_DiagCalib_FailCode4(&VAR_Cspf_TraFailCode4_u8);

  /* Inport: '<Root>/RP_SWC_DiagCalib_DiagCalib_FailCode3' */
  Rte_Read_RP_SWC_DiagCalib_DiagCalib_FailCode3(&VAR_Cspf_TraFailCode3_u8);

  /* Inport: '<Root>/RP_SWC_DiagCalib_DiagCalib_FailCode2' */
  Rte_Read_RP_SWC_DiagCalib_DiagCalib_FailCode2(&VAR_Cspf_TraFailCode2_u8);

  /* Inport: '<Root>/RP_SWC_DiagCalib_DiagCalib_FailCode1' */
  Rte_Read_RP_SWC_DiagCalib_DiagCalib_FailCode1(&VAR_Cspf_TraFailCode1_u8);

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_CSPF_100ms' incorporates:
   *  SubSystem: '<Root>/RE_SWC_CSPF_100ms_sys'
   */
  /* Outport: '<Root>/PP_SWC_CSPF_CSPF_TrabDernDrvBoardTemp' incorporates:
   *  Sum: '<S13>/Add10'
   */
  (void) Rte_Write_PP_SWC_CSPF_CSPF_TrabDernDrvBoardTemp
    (VAR_Cspf_TrabDernDrvBoardTemp_u16);

  /* Switch: '<S35>/Switch' incorporates:
   *  Constant: '<S35>/Constant2'
   *  Constant: '<S35>/Constant3'
   *  Inport: '<Root>/RP_SWC_DiagCalib_DiagCalib_FailCode1'
   */
  if (CAL_Cspf_flgFailCode1Swt_b) {
    VAR_Cspf_TraFailCode1_u8 = CAL_Cspf_FailCode1_u8;
  }

  /* End of Switch: '<S35>/Switch' */

  /* Outport: '<Root>/PP_SWC_CSPF_CSPF_TraFailCode1' incorporates:
   *  Sum: '<S32>/Add17'
   */
  (void) Rte_Write_PP_SWC_CSPF_CSPF_TraFailCode1(VAR_Cspf_TraFailCode1_u8);

  /* Switch: '<S36>/Switch' incorporates:
   *  Constant: '<S36>/Constant2'
   *  Constant: '<S36>/Constant3'
   *  Inport: '<Root>/RP_SWC_DiagCalib_DiagCalib_FailCode2'
   */
  if (CAL_Cspf_flgFailCode2Swt_b) {
    VAR_Cspf_TraFailCode2_u8 = CAL_Cspf_FailCode2_u8;
  }

  /* End of Switch: '<S36>/Switch' */

  /* Outport: '<Root>/PP_SWC_CSPF_CSPF_TraFailCode2' incorporates:
   *  Sum: '<S32>/Add18'
   */
  (void) Rte_Write_PP_SWC_CSPF_CSPF_TraFailCode2(VAR_Cspf_TraFailCode2_u8);

  /* Switch: '<S37>/Switch' incorporates:
   *  Constant: '<S37>/Constant2'
   *  Constant: '<S37>/Constant3'
   *  Inport: '<Root>/RP_SWC_DiagCalib_DiagCalib_FailCode3'
   */
  if (CAL_Cspf_flgFailCode3Swt_b) {
    VAR_Cspf_TraFailCode3_u8 = CAL_Cspf_FailCode3_u8;
  }

  /* End of Switch: '<S37>/Switch' */

  /* Outport: '<Root>/PP_SWC_CSPF_CSPF_TraFailCode3' incorporates:
   *  Sum: '<S32>/Add19'
   */
  (void) Rte_Write_PP_SWC_CSPF_CSPF_TraFailCode3(VAR_Cspf_TraFailCode3_u8);

  /* Switch: '<S38>/Switch' incorporates:
   *  Constant: '<S38>/Constant2'
   *  Constant: '<S38>/Constant3'
   *  Inport: '<Root>/RP_SWC_DiagCalib_DiagCalib_FailCode4'
   */
  if (CAL_Cspf_flgFailCode4Swt_b) {
    VAR_Cspf_TraFailCode4_u8 = CAL_Cspf_FailCode4_u8;
  }

  /* End of Switch: '<S38>/Switch' */

  /* Outport: '<Root>/PP_SWC_CSPF_CSPF_TraFailCode4' incorporates:
   *  Sum: '<S32>/Add20'
   */
  (void) Rte_Write_PP_SWC_CSPF_CSPF_TraFailCode4(VAR_Cspf_TraFailCode4_u8);

  /* Switch: '<S39>/Switch' incorporates:
   *  Constant: '<S39>/Constant2'
   *  Constant: '<S39>/Constant3'
   *  Inport: '<Root>/RP_SWC_DiagCalib_DiagCalib_FailCode5'
   */
  if (CAL_Cspf_flgFailCode5Swt_b) {
    VAR_Cspf_TraFailCode5_u8 = CAL_Cspf_FailCode5_u8;
  }

  /* End of Switch: '<S39>/Switch' */

  /* Outport: '<Root>/PP_SWC_CSPF_CSPF_TraFailCode5' incorporates:
   *  Sum: '<S32>/Add21'
   */
  (void) Rte_Write_PP_SWC_CSPF_CSPF_TraFailCode5(VAR_Cspf_TraFailCode5_u8);

  /* Switch: '<S40>/Switch' incorporates:
   *  Constant: '<S40>/Constant2'
   *  Constant: '<S40>/Constant3'
   *  Inport: '<Root>/RP_SWC_DiagCalib_DiagCalib_FailCode6'
   */
  if (CAL_Cspf_flgFailCode6Swt_b) {
    VAR_Cspf_TraFailCode6_u8 = CAL_Cspf_FailCode6_u8;
  }

  /* End of Switch: '<S40>/Switch' */

  /* Outport: '<Root>/PP_SWC_CSPF_CSPF_TraFailCode6' incorporates:
   *  Sum: '<S32>/Add22'
   */
  (void) Rte_Write_PP_SWC_CSPF_CSPF_TraFailCode6(VAR_Cspf_TraFailCode6_u8);

  /* Switch: '<S41>/Switch' incorporates:
   *  Constant: '<S41>/Constant2'
   *  Constant: '<S41>/Constant3'
   *  Inport: '<Root>/RP_SWC_DiagCalib_DiagCalib_FailCode7'
   */
  if (CAL_Cspf_flgFailCode7Swt_b) {
    VAR_Cspf_TraFailCode7_u8 = CAL_Cspf_FailCode7_u8;
  }

  /* End of Switch: '<S41>/Switch' */

  /* Outport: '<Root>/PP_SWC_CSPF_CSPF_TraFailCode7' incorporates:
   *  Sum: '<S32>/Add23'
   */
  (void) Rte_Write_PP_SWC_CSPF_CSPF_TraFailCode7(VAR_Cspf_TraFailCode7_u8);

  /* Switch: '<S42>/Switch' incorporates:
   *  Constant: '<S42>/Constant2'
   *  Constant: '<S42>/Constant3'
   *  Inport: '<Root>/RP_SWC_DiagCalib_DiagCalib_FailCode8'
   */
  if (CAL_Cspf_flgFailCode8Swt_b) {
    VAR_Cspf_TraFailCode8_u8 = CAL_Cspf_FailCode8_u8;
  }

  /* End of Switch: '<S42>/Switch' */

  /* Outport: '<Root>/PP_SWC_CSPF_CSPF_TraFailCode8' incorporates:
   *  Sum: '<S32>/Add24'
   */
  (void) Rte_Write_PP_SWC_CSPF_CSPF_TraFailCode8(VAR_Cspf_TraFailCode8_u8);

  /* Switch: '<S43>/Switch' incorporates:
   *  Constant: '<S43>/Constant2'
   *  Constant: '<S43>/Constant3'
   *  DataTypeConversion: '<S43>/Data Type Conversion'
   *  Inport: '<Root>/RP_SWC_Cpld_Cpld_CpldSwVer'
   */
  if (CAL_Cspf_flgCpldVerSwt_b) {
    VAR_Cspf_TraCpldVer_u16 = CAL_Cspf_CpldVer_u8;
  } else {
    Rte_Read_RP_SWC_Cpld_Cpld_CpldSwVer(&tmpRead_3);
    VAR_Cspf_TraCpldVer_u16 = tmpRead_3;
  }

  /* End of Switch: '<S43>/Switch' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_CSPF_100ms' */

  /* Inport: '<Root>/RP_SWC_HvMcu_HvMcu_HvMcuVer' */
  Rte_Read_RP_SWC_HvMcu_HvMcu_HvMcuVer(&VAR_Cspf_TraHvMcuVer_u16);

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_CSPF_100ms' incorporates:
   *  SubSystem: '<Root>/RE_SWC_CSPF_100ms_sys'
   */
  /* Outport: '<Root>/PP_SWC_CSPF_CSPF_TraCpldVer' incorporates:
   *  Sum: '<S33>/Add25'
   */
  (void) Rte_Write_PP_SWC_CSPF_CSPF_TraCpldVer(VAR_Cspf_TraCpldVer_u16);

  /* Switch: '<S44>/Switch' incorporates:
   *  Constant: '<S44>/Constant2'
   *  Constant: '<S44>/Constant3'
   *  Inport: '<Root>/RP_SWC_HvMcu_HvMcu_HvMcuVer'
   */
  if (CAL_Cspf_flgHvMcuVerSwt_b) {
    VAR_Cspf_TraHvMcuVer_u16 = CAL_Cspf_HvMcuVer_u8;
  }

  /* End of Switch: '<S44>/Switch' */

  /* Outport: '<Root>/PP_SWC_CSPF_CSPF_TraHvMcuVer' incorporates:
   *  Sum: '<S33>/Add26'
   */
  (void) Rte_Write_PP_SWC_CSPF_CSPF_TraHvMcuVer(VAR_Cspf_TraHvMcuVer_u16);

  /* Outport: '<Root>/PP_SWC_CSPF_CSPF_TraCodeVer' incorporates:
   *  Constant: '<S33>/CAL_Cspf_CodeVer_u16'
   */
  (void) Rte_Write_PP_SWC_CSPF_CSPF_TraCodeVer(CAL_Cspf_CodeVer_u16);

  /* Outport: '<Root>/PP_SWC_CSPF_CSPF_TraDataVer' incorporates:
   *  Constant: '<S33>/CAL_Cspf_DataVer_u16'
   */
  (void) Rte_Write_PP_SWC_CSPF_CSPF_TraDataVer(CAL_Cspf_DataVer_u16);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_CSPF_100ms' */
}

/* Model initialize function */
void SWC_CSPF_Init(void)
{
  /* SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_CSPF_100ms' incorporates:
   *  SubSystem: '<Root>/RE_SWC_CSPF_100ms_sys'
   */
  /* Start for Outport: '<Root>/PP_SWC_CSPF_CSPF_TraCodeVer' incorporates:
   *  Constant: '<S33>/CAL_Cspf_CodeVer_u16'
   */
  (void) Rte_Write_PP_SWC_CSPF_CSPF_TraCodeVer(CAL_Cspf_CodeVer_u16);

  /* Start for Outport: '<Root>/PP_SWC_CSPF_CSPF_TraDataVer' incorporates:
   *  Constant: '<S33>/CAL_Cspf_DataVer_u16'
   */
  (void) Rte_Write_PP_SWC_CSPF_CSPF_TraDataVer(CAL_Cspf_DataVer_u16);

  /* End of SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_CSPF_100ms' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
