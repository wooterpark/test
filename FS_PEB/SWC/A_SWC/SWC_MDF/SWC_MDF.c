/*
 * File: SWC_MDF.c
 *
 * Code generated for Simulink model 'SWC_MDF'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Tue Jan 26 09:57:53 2021
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SWC_MDF.h"
#include "SWC_MDF_private.h"
#include "look1_iflf_binlxpw.h"
#include "look2_iflf_binlxpw.h"

/* Exported block signals */
float32 VAR_MDF_OffSetSiteAObs_f32;    /* '<S18>/Abs' */
float32 VAR_MDF_OffSetSiteBObs_f32;    /* '<S18>/Abs1' */
float32 VAR_MDF_offsetDeltaObs_f32;    /* '<S18>/Add2' */
float32 VAR_MDF_3PhaUnbalanceObs_f32;  /* '<S53>/Divide' */
float32 VAR_MDF_offsetDeltaFlt_f32;    /* '<S21>/Abs1' */
uint8 VAR_MDF_AlOfsNoPlausState_u8;
               /* '<S1>/RP_SWC_FIM_MDF_AlOfsNoPlausErr_GetFunctionPermission' */
uint8 VAR_MDF_DiashCirNoPsblState_u8;
             /* '<S1>/RP_SWC_FIM_MDF_DiashCirNoPsblErr_GetFunctionPermission' */
uint8 VAR_MDF_EmacBlkdState_u8;
                  /* '<S1>/RP_SWC_FIM_MDF_EmacBlkdWarn_GetFunctionPermission' */
uint8 VAR_MDF_ICtlRatState_u8;
                       /* '<S1>/RP_SWC_FIM_MDF_IctlRat_GetFunctionPermission' */
uint8 VAR_MDF_OpenCirNoPsblState_u8;
              /* '<S1>/RP_SWC_FIM_MDF_OpenCirNoPsblErr_GetFunctionPermission' */
uint8 VAR_MDF_OperOutdRngState_u8;
                /* '<S1>/RP_SWC_FIM_MDF_OperOutdRngErr_GetFunctionPermission' */
uint8 VAR_MDF_PhaseFaultState_u8;
             /* '<S1>/RP_SWC_FIM_MDF_PhaseLossFaultErr_GetFunctionPermission' */
uint8 VAR_MDF_PrfElDrvState_u8;
              /* '<S1>/RP_SWC_FIM_MDF_DiagPrfChkElecDt_GetFunctionPermission' */
boolean VAR_MDF_bAlOfsChk_b;           /* '<S19>/Logical Operator1' */
boolean VAR_MDF_bstGateDrvShCir_b;     /* '<S60>/Logical Operator' */
boolean VAR_MDF_bEMBlkChk_b;           /* '<S30>/Logical Operator1' */
boolean VAR_MDF_bICtlRatChk_b;         /* '<S36>/Logical Operator1' */
boolean VAR_MDF_bstGateDrvOpenCir_b;   /* '<S40>/Logical Operator' */
boolean VAR_MDF_flagOperOutdRngChk_b;  /* '<S43>/Logical Operator' */
boolean VAR_MDF_PhaseFaultChk_b;       /* '<S46>/Logical Operator1' */
boolean VAR_MDF_bPwrCmpDFCCalc_b;      /* '<S56>/Logical Operator' */
boolean VAR_MDF_bshCirNoPsblFaul_b;    /* '<S59>/Logical Operator' */
boolean VAR_MDF_bFaultPwrCmp_b;        /* '<S58>/Relational Operator6' */
boolean VAR_MDF_bPhaseFault_b;         /* '<S49>/Logical Operator1' */
boolean VAR_MDF_flagOperOutdRngFault_b;/* '<S45>/Logical Operator' */
boolean VAR_MDF_bOpenCirNoPsblFault_b; /* '<S42>/Logical Operator' */
boolean VAR_MDF_bIsOvHiFault_b;        /* '<S39>/Relational Operator' */
boolean VAR_MDF_bFaultICtlChk_b;       /* '<S38>/Logical Operator' */
boolean VAR_MDF_bFaultEMBlkWarn_b;     /* '<S34>/Logical Operator3' */
boolean VAR_MDF_bFaultEMBlkErr_b;      /* '<S33>/Switch6' */
boolean VAR_MDF_bAlfOfsNoPlauseFault_b;/* '<S20>/Logical Operator1' */

/* Exported data definition */
#pragma section ".rodata.Calib_32"

/* Definition for custom storage class: iEDS_Parameter */
const volatile float32 CAL_MDF_3PhaUnbalance_f32 = 0.99F;
                          /* Referenced by: '<S53>/CAL_MDF_3PhaUnbalance_f32' */

/* 三相不平衡度阈值 */
const volatile float32 CAL_MDF_DIffAlOfsMax_f32 = 5.0F;
                           /* Referenced by: '<S21>/CAL_MDF_DIffAlOfsMax_f32' */

/* 角度差值阈值 */
const volatile float32 CAL_MDF_EMBlkWarn_f32 = 0.2F;
                              /* Referenced by: '<S34>/CAL_MDF_EMBlkWarn_f32' */

/* 堵转警告扭矩比例系数 */
const volatile float32 CAL_MDF_FwWiIs_f32 = 300.0F;
                                 /* Referenced by: '<S42>/CAL_MDF_FwWiIs_f32' */
const volatile float32 CAL_MDF_FwWoIs_f32 = 10.0F;
                                 /* Referenced by: '<S42>/CAL_MDF_FwWoIs_f32' */
const volatile uint8 CAL_MDF_Inactive_u8 = 0U;
                                /* Referenced by: '<S43>/CAL_MDF_Inactive_u8' */
const volatile float32 CAL_MDF_IsErrFlt_f32 = 0.02F;
                               /* Referenced by: '<S71>/CAL_MDF_IsErrFlt_f32' */
const volatile float32 CAL_MDF_IsErrThres_f32 = 110.0F;
                             /* Referenced by: '<S38>/CAL_MDF_IsErrThres_f32' */

/* 电流合理性电流差值阈值 */
const volatile float32 CAL_MDF_IsMaxSet_f32 = 750.0F;
                               /* Referenced by: '<S39>/CAL_MDF_IsMaxSet_f32' */

/* 相电流最大值设定值 */
const volatile float32 CAL_MDF_IsPhaseFault_f32 = 10.0F;
                           /* Referenced by: '<S46>/CAL_MDF_IsPhaseFault_f32' */

/* 缺相诊断Is阈值 */
const volatile float32 CAL_MDF_IsThreshCirNoPsbl_f32 = 100.0F;
                      /* Referenced by: '<S59>/CAL_MDF_IsThreshCirNoPsbl_f32' */

/* 无法主动短路Is阈值 */
const volatile float32 CAL_MDF_OfsDeltaAgFltFrq_f32 = 5.0F;
                       /* Referenced by: '<S21>/CAL_MDF_OfsDeltaAgFltFrq_f32' */

/* 偏移角度差值滤波频率 */
const volatile float32 CAL_MDF_Pwr3PhaFlt_f32 = 0.02F;
                             /* Referenced by: '<S72>/CAL_MDF_Pwr3PhaFlt_f32' */
const volatile float32 CAL_MDF_PwrDcLinkEstFlt_f32 = 0.02F;
                        /* Referenced by: '<S74>/CAL_MDF_PwrDcLinkEstFlt_f32' */
const volatile float32 CAL_MDF_PwrLoss_X_af32[2] = { 0.0F, 1.0F } ;
                           /* Referenced by: '<S66>/2-D powloss lookup Table' */

const volatile float32 CAL_MDF_PwrLoss_Y_af32[2] = { 0.0F, 1.0F } ;
                           /* Referenced by: '<S66>/2-D powloss lookup Table' */

const volatile float32 CAL_MDF_PwrLoss_Z_af32[4] = { 1.0F, 1.0F, 1.0F, 1.0F } ;
                           /* Referenced by: '<S66>/2-D powloss lookup Table' */

const volatile float32 CAL_MDF_UdcFwMin_f32 = 180.0F;
                               /* Referenced by: '<S62>/CAL_MDF_UdcFwMin_f32' */

/* Freewheel状态判断电压阈值 */
const volatile float32 CAL_MDF_UdcThreshCirNoPsbl_f32 = 400.0F;
                     /* Referenced by: '<S59>/CAL_MDF_UdcThreshCirNoPsbl_f32' */

/* 无法主动短路电压阈值 */
const volatile float32 CAL_MDF_UsErrFlt_f32 = 0.02F;
                               /* Referenced by: '<S73>/CAL_MDF_UsErrFlt_f32' */
const volatile float32 CAL_MDF_UsErrThres_f32 = 250.0F;
                             /* Referenced by: '<S38>/CAL_MDF_UsErrThres_f32' */

/* 电流合理性电压差值阈值 */
const volatile float32 CAL_MDF_UsFrwhlMax_f32 = 750.0F;
                             /* Referenced by: '<S62>/CAL_MDF_UsFrwhlMax_f32' */
const volatile float32 CAL_MDF_cErrPwrDcEstMax_f32 = 0.3F;
                        /* Referenced by: '<S58>/CAL_MDF_cErrPwrDcEstMax_f32' */
const volatile float32 CAL_MDF_cofnAbsPhaseFault_Y_af32[46] = { 1.0F, 1.0F, 0.0F,
  0.0F, 1.0F, 1.0F, 0.0F, 0.0F, 1.0F, 1.0F, 0.0F, 0.0F, 1.0F, 1.0F, 0.0F, 0.0F,
  1.0F, 1.0F, 0.0F, 0.0F, 1.0F, 1.0F, 0.0F, 0.0F, 1.0F, 1.0F, 0.0F, 0.0F, 1.0F,
  1.0F, 0.0F, 0.0F, 1.0F, 1.0F, 0.0F, 0.0F, 1.0F, 1.0F, 0.0F, 0.0F, 1.0F, 1.0F,
  0.0F, 0.0F, 1.0F, 1.0F } ;       /* Referenced by: '<S46>/1-D Lookup Table' */

const volatile float32 CAL_MDF_nAbsPhaseFault_X_af32[46] = { 0.0F, 600.0F,
  651.0F, 900.0F, 901.0F, 1400.0F, 1401.0F, 1600.0F, 1601.0F, 2900.0F, 2901.0F,
  3100.0F, 3101.0F, 4400.0F, 4401.0F, 4600.0F, 4601.0F, 5900.0F, 5901.0F,
  6100.0F, 6101.0F, 7400.0F, 7401.0F, 7600.0F, 7601.0F, 8900.0F, 8901.0F,
  9100.0F, 9101.0F, 10400.0F, 10401.0F, 10600.0F, 10601.0F, 11900.0F, 11901.0F,
  12100.0F, 12101.0F, 13400.0F, 13401.0F, 13600.0F, 13601.0F, 14900.0F, 14901.0F,
  15100.0F, 15101.0F, 16000.0F } ; /* Referenced by: '<S46>/1-D Lookup Table' */

const volatile float32 CAL_MDF_nAbsPhaseFault_f32 = 200.0F;
                         /* Referenced by: '<S46>/CAL_MDF_nAbsPhaseFault_f32' */

/* 缺相故障判断转速绝对值阈值 */
const volatile float32 CAL_MDF_nAbsThresOpenCirNoPsbl_f32 = 2000.0F;
                 /* Referenced by: '<S40>/CAL_MDF_nAbsThresOpenCirNoPsbl_f32' */
const volatile float32 CAL_MDF_nAbsThresblockedElMa_f32 = 50.0F;
                   /* Referenced by: '<S34>/CAL_MDF_nAbsThresblockedElMa_f32' */

/* 堵转判断转速阈值 */
const volatile float32 CAL_MDF_nAbsThreshCirNoPsbl_f32 = 200.0F;
                    /* Referenced by: '<S60>/CAL_MDF_nAbsThreshCirNoPsbl_f32' */

/* 无法主动短路检测转速阈值 */
const volatile float32 CAL_MDF_nDidMax_f32 = 5000.0F;
                                /* Referenced by: '<S56>/CAL_MDF_nDidMax_f32' */
const volatile float32 CAL_MDF_nDidMin_f32 = 1000.0F;
                                /* Referenced by: '<S56>/CAL_MDF_nDidMin_f32' */
const volatile float32 CAL_MDF_nThresAlOfsNoPlauseFaultMax_f32 = 8000.0F;
            /* Referenced by: '<S15>/CAL_MDF_nThresAlOfsNoPlauseFaultMax_f32' */

/* 角度合理性诊断转速阈值 */
const volatile float32 CAL_MDF_nThresAlOfsNoPlauseFaultMin_f32 = 2000.0F;
            /* Referenced by: '<S15>/CAL_MDF_nThresAlOfsNoPlauseFaultMin_f32' */

/* 角度合理性诊断转速阈值 */
const volatile float32 CAL_MDF_pwrDcDiaMin_f32 = 9000.0F;
                            /* Referenced by: '<S56>/CAL_MDF_pwrDcDiaMin_f32' */
const volatile uint8 CAL_MDF_stFrwhlPhd_u8 = 2U;
                              /* Referenced by: '<S62>/CAL_MDF_stFrwhlPhd_u8' */
const volatile uint8 CAL_MDF_stFrwhlWiIs_u8 = 1U;/* Referenced by:
                                                  * '<S62>/CAL_MDF_stFrwhlWiIs_u8'
                                                  * '<S42>/CAL_MDF_stFrwhlWiIs_u8'
                                                  */
const volatile uint8 CAL_MDF_stFrwhlWoIs_u8 = 0U;/* Referenced by:
                                                  * '<S62>/CAL_MDF_stFrwhlWoIs_u8'
                                                  * '<S42>/CAL_MDF_stFrwhlWoIs_u8'
                                                  */
const volatile boolean CAL_MDF_tOperOutdRngSelState_b = 1;
                     /* Referenced by: '<S43>/CAL_MDF_tOperOutdRngSelState_b' */

/* 温度传感器状态，后期关联FID */
const volatile float32 CAL_MDF_tThd_TempDBCInvCoolObsvr_f32 = 70.0F;
               /* Referenced by: '<S45>/CAL_MDF_tThd_TempDBCInvCoolObsvr_f32' */
const volatile float32 CAL_MDF_tThd_TempDBCInvSens3Pha_f32 = 102.0F;
                /* Referenced by: '<S45>/CAL_MDF_tThd_TempDBCInvSens3Pha_f32' */
const volatile float32 CAL_MDF_tThd_TempStr_f32 = 180.0F;
                           /* Referenced by: '<S45>/CAL_MDF_tThd_TempStr_f32' */
const volatile float32 CAL_MDF_tiAgComp_f32 = 1.0F;
                               /* Referenced by: '<S18>/CAL_MDF_tiAgComp_f32' */

/* 角度补偿时间 */
const volatile float32 CAL_MDF_tiAlfOfsNoPlauseFault_f32 = 0.1F;
                  /* Referenced by: '<S20>/CAL_MDF_tiAlfOfsNoPlauseFault_f32' */

/* 角度合理性诊断延时时间 */
const volatile float32 CAL_MDF_tiEMBlk_f32 = 10.0F;
                                /* Referenced by: '<S35>/CAL_MDF_tiEMBlk_f32' */

/* 进堵转限扭的堵转状态持续时间 */
const volatile float32 CAL_MDF_tiOffsetSteady_f32 = 0.2F;
                         /* Referenced by: '<S19>/CAL_MDF_tiOffsetSteady_f32' */

/* 稳态时间阈值 */
const volatile float32 CAL_MDF_tiPhaFaultDelay_f32 = 0.04F;
                        /* Referenced by: '<S49>/CAL_MDF_tiPhaFaultDelay_f32' */

/* 缺相诊断故障延时 */
const volatile float32 CAL_MDF_tiQuitEMBlk_f32 = 0.5F;
                            /* Referenced by: '<S33>/CAL_MDF_tiQuitEMBlk_f32' */

/* 退出堵转转速大于阈值持续时间 */
const volatile float32 CAL_MDF_trqOfsNoPlausFault_f32 = 0.05F;
                     /* Referenced by: '<S15>/CAL_MDF_trqOfsNoPlausFault_f32' */

/* 角度合理性诊断扭矩需求值阈值 */
#pragma section

/* Block signals (default storage) */
B_SWC_MDF_T SWC_MDF_B;

/* Block states (default storage) */
DW_SWC_MDF_T SWC_MDF_DW;

/* Model step function for TID1 */
void SWC_MDF_10ms(void)                /* Explicit Task: RE_SWC_MDF_10ms */
{
  float32 tmpRead;
  uint8 tmpRead_0;
  float32 tmpRead_1;
  float32 tmpRead_2;
  float32 tmpRead_3;
  float32 tmpRead_4;
  float32 tmpRead_5;
  float32 rtb_TmpSignalConversionAtRP_SWC;
  float32 rtb_TmpSignalConversionAtRP__nu;
  float32 rtb_TmpSignalConversionAtRP_S_o;
  float32 rtb_Divide_o;
  float32 rtb_Product5_js;
  float32 rtb_Product5_n;
  float32 rtb_TmpSignalConversionAtRP__iw;
  float32 rtb_TmpSignalConversionAtRP__lr;
  float32 rtb_Switch1_be;
  float32 rtb_TmpSignalConversionAtRP_S_c;
  float32 rtb_TmpSignalConversionAtRP__fh;
  float32 rtb_TmpSignalConversionAtRP__jo;
  float32 rtb_TmpSignalConversionAtRP_S_p;
  float32 rtb_Abs2;
  boolean rtb_DataTypeConversion;
  iEDS_Enum_stDrvCtl_def rtb_DataTypeConversion1;
  uint8 rtb_TmpSignalConversionAtRP_S_e;
  float32 rtb_Abs;
  float32 rtb_TmpSignalConversionAtRP__pk;
  float32 rtb_TmpSignalConversionAtRP_S_b;
  uint8 rtb_RP_SWC_FIM_MDFIsOvHiErr_Get;
  boolean rtb_RelationalOperator_og;
  float32 rtb_TmpSignalConversionAtRP_S_a;
  float32 rtb_TmpSignalConversionAtRP__jj;
  float32 rtb_TmpSignalConversionAtRP_S_f;
  float32 rtb_Abs_p;
  float32 rtb_UnitDelay_k3;
  float32 rtb_UnitDelay1_m;
  float32 rtb_Abs_n;
  float32 rtb_UnitDelay_p;
  uint8 rtb_Gain3;
  sint32 tmp;
  sint32 Switch1;
  float32 VAR_MDF_OffSetSiteAObs_f32_tmp;

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_MDF_10ms' incorporates:
   *  SubSystem: '<Root>/RE_SWC_MDF_10ms_sys'
   */
  /* SignalConversion generated from: '<S1>/RP_SWC_MPC_MPC_isdFlt_read' incorporates:
   *  Inport: '<Root>/RP_SWC_MPC_MPC_isdFlt'
   */
  Rte_Read_RP_SWC_MPC_MPC_isdFlt(&rtb_TmpSignalConversionAtRP_SWC);

  /* SignalConversion generated from: '<S1>/RP_SWC_MPC_MPC_Rs_read' incorporates:
   *  Inport: '<Root>/RP_SWC_MPC_MPC_Rs'
   */
  Rte_Read_RP_SWC_MPC_MPC_Rs(&rtb_TmpSignalConversionAtRP__nu);

  /* SignalConversion generated from: '<S1>/RP_SWC_MCF_MCF_udDes_read' incorporates:
   *  Inport: '<Root>/RP_SWC_MCF_MCF_udDes'
   */
  Rte_Read_RP_SWC_MCF_MCF_udDes(&rtb_TmpSignalConversionAtRP__jo);

  /* SignalConversion generated from: '<S1>/RP_SWC_HSPF_HSPF_nSlowFlt_read' incorporates:
   *  Inport: '<Root>/RP_SWC_HSPF_HSPF_nSlowFlt'
   */
  Rte_Read_RP_SWC_HSPF_HSPF_nSlowFlt(&rtb_TmpSignalConversionAtRP_S_o);

  /* Product: '<S63>/Divide' incorporates:
   *  Constant: '<S63>/CnvFac1'
   */
  rtb_Divide_o = rtb_TmpSignalConversionAtRP_S_o / 60.0F;

  /* Product: '<S63>/Product1' incorporates:
   *  Constant: '<S5>/MDF_GLB_MotorPole_u8'
   */
  rtb_Product5_js = (float32)((uint8)MDF_GLB_MotorPole_u8) * rtb_Divide_o;

  /* Product: '<S18>/Product5' incorporates:
   *  Constant: '<S18>/Constant'
   *  Constant: '<S18>/MDF_GLB_pi_f32'
   */
  rtb_Product5_n = 2.0F * rtb_Product5_js * MDF_GLB_pi_f32;

  /* SignalConversion generated from: '<S1>/RP_SWC_MPC_MPC_Lq_read' incorporates:
   *  Inport: '<Root>/RP_SWC_MPC_MPC_Lq'
   */
  Rte_Read_RP_SWC_MPC_MPC_Lq(&rtb_TmpSignalConversionAtRP__iw);

  /* SignalConversion generated from: '<S1>/RP_SWC_MPC_MPC_isqFlt_read' incorporates:
   *  Inport: '<Root>/RP_SWC_MPC_MPC_isqFlt'
   */
  Rte_Read_RP_SWC_MPC_MPC_isqFlt(&rtb_TmpSignalConversionAtRP__lr);

  /* Product: '<S18>/Product1' */
  rtb_Switch1_be = rtb_Product5_n * rtb_TmpSignalConversionAtRP__iw *
    rtb_TmpSignalConversionAtRP__lr;

  /* Product: '<S18>/Product' incorporates:
   *  Product: '<S64>/Product'
   */
  VAR_MDF_OffSetSiteAObs_f32_tmp = rtb_TmpSignalConversionAtRP_SWC *
    rtb_TmpSignalConversionAtRP__nu;

  /* Abs: '<S18>/Abs' incorporates:
   *  Product: '<S18>/Product'
   *  Sum: '<S18>/Add'
   */
  VAR_MDF_OffSetSiteAObs_f32 = fabsf((rtb_TmpSignalConversionAtRP__jo -
    VAR_MDF_OffSetSiteAObs_f32_tmp) + rtb_Switch1_be);

  /* Switch: '<S24>/Switch' incorporates:
   *  Abs: '<S24>/Abs'
   *  Constant: '<S24>/Constant'
   *  Constant: '<S25>/Constant'
   *  RelationalOperator: '<S25>/Compare'
   */
  if (fabsf(VAR_MDF_OffSetSiteAObs_f32) <= 0.0001F) {
    rtb_Abs2 = 0.0001F;
  } else {
    rtb_Abs2 = VAR_MDF_OffSetSiteAObs_f32;
  }

  /* End of Switch: '<S24>/Switch' */

  /* Gain: '<S24>/Gain3' incorporates:
   *  Constant: '<S27>/Constant'
   *  RelationalOperator: '<S27>/Compare'
   */
  rtb_Gain3 = (uint8)((rtb_Abs2 >= 0.0F) << 7);

  /* SignalConversion generated from: '<S1>/RP_SWC_MCF_MCF_uqDes_read' incorporates:
   *  Inport: '<Root>/RP_SWC_MCF_MCF_uqDes'
   */
  Rte_Read_RP_SWC_MCF_MCF_uqDes(&rtb_TmpSignalConversionAtRP_S_p);

  /* Product: '<S18>/Product2' incorporates:
   *  Product: '<S64>/Product2'
   */
  rtb_TmpSignalConversionAtRP__nu *= rtb_TmpSignalConversionAtRP__lr;

  /* Sum: '<S18>/Add1' incorporates:
   *  Product: '<S18>/Product2'
   */
  rtb_Switch1_be = (rtb_TmpSignalConversionAtRP__nu + rtb_Switch1_be) -
    rtb_TmpSignalConversionAtRP_S_p;

  /* Abs: '<S18>/Abs1' */
  VAR_MDF_OffSetSiteBObs_f32 = fabsf(rtb_Switch1_be);

  /* Switch: '<S24>/Switch1' incorporates:
   *  Abs: '<S24>/Abs1'
   *  Constant: '<S24>/Constant1'
   *  Constant: '<S26>/Constant'
   *  RelationalOperator: '<S26>/Compare'
   */
  if (fabsf(VAR_MDF_OffSetSiteBObs_f32) <= 0.0001F) {
    rtb_Switch1_be = 0.0001F;
  } else {
    rtb_Switch1_be = VAR_MDF_OffSetSiteBObs_f32;
  }

  /* End of Switch: '<S24>/Switch1' */

  /* Product: '<S24>/Divide' */
  rtb_Abs2 /= rtb_Switch1_be;

  /* Abs: '<S24>/Abs2' */
  rtb_Abs2 = fabsf(rtb_Abs2);

  /* RelationalOperator: '<S29>/Compare' incorporates:
   *  Constant: '<S29>/Constant'
   */
  rtb_DataTypeConversion = (rtb_Abs2 >= 1.0F);

  /* Switch: '<S24>/Switch2' incorporates:
   *  Constant: '<S24>/Constant2'
   *  Product: '<S24>/Divide1'
   */
  if (rtb_DataTypeConversion) {
    rtb_Abs2 = 1.0F / rtb_Abs2;
  }

  /* End of Switch: '<S24>/Switch2' */

  /* MultiPortSwitch: '<S24>/Multiport Switch' incorporates:
   *  Constant: '<S24>/Constant10'
   *  Constant: '<S24>/Constant3'
   *  Constant: '<S24>/Constant4'
   *  Constant: '<S24>/Constant5'
   *  Constant: '<S24>/Constant7'
   *  Constant: '<S24>/Constant8'
   *  Constant: '<S24>/Constant9'
   *  Constant: '<S28>/Constant'
   *  Gain: '<S24>/Gain1'
   *  Gain: '<S24>/Gain2'
   *  Gain: '<S24>/Gain4'
   *  LookupNDDirect: '<S24>/Direct Lookup Table (n-D)'
   *  RelationalOperator: '<S28>/Compare'
   *  Sum: '<S24>/Add'
   *  Sum: '<S24>/Add1'
   *  Sum: '<S24>/Add2'
   *  Sum: '<S24>/Add3'
   *  Sum: '<S24>/Add5'
   *  Sum: '<S24>/Add6'
   *  Sum: '<S24>/Add7'
   *  Sum: '<S24>/Add8'
   *
   * About '<S24>/Direct Lookup Table (n-D)':
   *  1-dimensional Direct Look-Up returning a Scalar,
   *
   *     Remove protection against out-of-range input in generated code: 'off'
   */
  switch ((sint32)((((((uint32)((rtb_Switch1_be >= 0.0F) << 7) << 1) + rtb_Gain3)
                     + ((uint32)(rtb_DataTypeConversion << 7) << 2)) >> 2) >> 5))
  {
   case 0:
    /* LookupNDDirect: '<S24>/Direct Lookup Table (n-D)' incorporates:
     *  Gain: '<S24>/Gain'
     *
     * About '<S24>/Direct Lookup Table (n-D)':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     */
    rtb_Abs2 *= 1024.0F;
    if (rtb_Abs2 > 1024.0F) {
      rtb_Abs2 = 1024.0F;
    }

    rtb_Abs2 = (float32)(58672U * rtCP_DirectLookupTablenD_table[(sint32)
                         rtb_Abs2]) * 1.49011612E-8F + 180.0F;
    break;

   case 1:
    /* LookupNDDirect: '<S24>/Direct Lookup Table (n-D)' incorporates:
     *  Gain: '<S24>/Gain'
     *
     * About '<S24>/Direct Lookup Table (n-D)':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     */
    rtb_Abs2 *= 1024.0F;
    if (rtb_Abs2 > 1024.0F) {
      rtb_Abs2 = 1024.0F;
    }

    rtb_Abs2 = 180.0F - (float32)(58672U * rtCP_DirectLookupTablenD_table
      [(sint32)rtb_Abs2]) * 1.49011612E-8F;
    break;

   case 2:
    /* LookupNDDirect: '<S24>/Direct Lookup Table (n-D)' incorporates:
     *  Gain: '<S24>/Gain'
     *
     * About '<S24>/Direct Lookup Table (n-D)':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     */
    rtb_Abs2 *= 1024.0F;
    if (rtb_Abs2 > 1024.0F) {
      rtb_Abs2 = 1024.0F;
    }

    rtb_Abs2 = 360.0F - (float32)(58672U * rtCP_DirectLookupTablenD_table
      [(sint32)rtb_Abs2]) * 1.49011612E-8F;
    break;

   case 3:
    /* LookupNDDirect: '<S24>/Direct Lookup Table (n-D)' incorporates:
     *  Gain: '<S24>/Gain'
     *
     * About '<S24>/Direct Lookup Table (n-D)':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     */
    rtb_Abs2 *= 1024.0F;
    if (rtb_Abs2 > 1024.0F) {
      rtb_Abs2 = 1024.0F;
    }

    rtb_Abs2 = (float32)(58672U * rtCP_DirectLookupTablenD_table[(sint32)
                         rtb_Abs2]) * 1.49011612E-8F;
    break;

   case 4:
    /* LookupNDDirect: '<S24>/Direct Lookup Table (n-D)' incorporates:
     *  Gain: '<S24>/Gain'
     *
     * About '<S24>/Direct Lookup Table (n-D)':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     */
    rtb_Abs2 *= 1024.0F;
    if (rtb_Abs2 > 1024.0F) {
      rtb_Abs2 = 1024.0F;
    }

    rtb_Abs2 = 270.0F - (float32)(58672U * rtCP_DirectLookupTablenD_table
      [(sint32)rtb_Abs2]) * 1.49011612E-8F;
    break;

   case 5:
    /* LookupNDDirect: '<S24>/Direct Lookup Table (n-D)' incorporates:
     *  Gain: '<S24>/Gain'
     *
     * About '<S24>/Direct Lookup Table (n-D)':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     */
    rtb_Abs2 *= 1024.0F;
    if (rtb_Abs2 > 1024.0F) {
      rtb_Abs2 = 1024.0F;
    }

    rtb_Abs2 = (float32)(58672U * rtCP_DirectLookupTablenD_table[(sint32)
                         rtb_Abs2]) * 1.49011612E-8F + 90.0F;
    break;

   case 6:
    /* LookupNDDirect: '<S24>/Direct Lookup Table (n-D)' incorporates:
     *  Gain: '<S24>/Gain'
     *
     * About '<S24>/Direct Lookup Table (n-D)':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     */
    rtb_Abs2 *= 1024.0F;
    if (rtb_Abs2 > 1024.0F) {
      rtb_Abs2 = 1024.0F;
    }

    rtb_Abs2 = (float32)(58672U * rtCP_DirectLookupTablenD_table[(sint32)
                         rtb_Abs2]) * 1.49011612E-8F + 270.0F;
    break;

   default:
    /* LookupNDDirect: '<S24>/Direct Lookup Table (n-D)' incorporates:
     *  Gain: '<S24>/Gain'
     *
     * About '<S24>/Direct Lookup Table (n-D)':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     */
    rtb_Abs2 *= 1024.0F;
    if (rtb_Abs2 > 1024.0F) {
      rtb_Abs2 = 1024.0F;
    }

    rtb_Abs2 = 90.0F - (float32)(58672U * rtCP_DirectLookupTablenD_table[(sint32)
      rtb_Abs2]) * 1.49011612E-8F;
    break;
  }

  /* End of MultiPortSwitch: '<S24>/Multiport Switch' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_MDF_10ms' */

  /* Inport: '<Root>/RP_SWC_VCF_VCF_TrqDes' */
  Rte_Read_RP_SWC_VCF_VCF_TrqDes(&tmpRead_5);

  /* Inport: '<Root>/RP_SWC_Rdc_Rdc_nWoFlt' */
  Rte_Read_RP_SWC_Rdc_Rdc_nWoFlt(&rtb_Abs);

  /* Inport: '<Root>/RP_SWC_MCF_MCF_dtPwm' */
  Rte_Read_RP_SWC_MCF_MCF_dtPwm(&tmpRead_3);

  /* Inport: '<Root>/RP_SWC_SCF_SCF_stDrvCtl' */
  Rte_Read_RP_SWC_SCF_SCF_stDrvCtl(&tmpRead_0);

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_MDF_10ms' incorporates:
   *  SubSystem: '<Root>/RE_SWC_MDF_10ms_sys'
   */
  /* Sum: '<S18>/Add2' incorporates:
   *  Constant: '<S18>/CAL_MDF_tiAgComp_f32'
   *  Constant: '<S18>/Constant3'
   *  Constant: '<S18>/MDF_GLB_pi_f32'
   *  Product: '<S18>/Divide1'
   *  Product: '<S18>/Product3'
   */
  VAR_MDF_offsetDeltaObs_f32 = rtb_Abs2 - rtb_Product5_n * 180.0F /
    MDF_GLB_pi_f32 * tmpRead_3 * CAL_MDF_tiAgComp_f32;

  /* FunctionCaller: '<S1>/RP_SWC_FIM_MDF_AlOfsNoPlausErr_GetFunctionPermission' */
  Rte_Call_RP_SWC_FIM_MDF_AlOfsNoPlausErr_GetFunctionPermission
    (&VAR_MDF_AlOfsNoPlausState_u8);

  /* DataTypeConversion: '<S3>/Data Type Conversion1' */
  rtb_DataTypeConversion1 = (iEDS_Enum_stDrvCtl_def)tmpRead_0;

  /* SignalConversion generated from: '<S1>/RP_SWC_SCF_SCF_stGateDrv_read' incorporates:
   *  Inport: '<Root>/RP_SWC_SCF_SCF_stGateDrv'
   */
  Rte_Read_RP_SWC_SCF_SCF_stGateDrv(&rtb_TmpSignalConversionAtRP_S_e);

  /* Abs: '<S4>/Abs' */
  rtb_Abs = fabsf(rtb_Abs);

  /* Logic: '<S15>/Logical Operator' incorporates:
   *  Abs: '<S15>/Abs'
   *  Constant: '<S15>/CAL_MDF_nThresAlOfsNoPlauseFaultMax_f32'
   *  Constant: '<S15>/CAL_MDF_nThresAlOfsNoPlauseFaultMin_f32'
   *  Constant: '<S15>/CAL_MDF_trqOfsNoPlausFault_f32'
   *  Constant: '<S15>/MDF_GLB_IGBTrun_u8'
   *  Constant: '<S15>/iEDS_Enum_stDrvCtl_def.Drv_OffsetAcc'
   *  Constant: '<S15>/iEDS_Enum_stDrvCtl_def.Drv_OffsetFw'
   *  Logic: '<S15>/Logical Operator1'
   *  Logic: '<S15>/Logical Operator2'
   *  RelationalOperator: '<S15>/Relational Operator1'
   *  RelationalOperator: '<S15>/Relational Operator2'
   *  RelationalOperator: '<S15>/Relational Operator3'
   *  RelationalOperator: '<S15>/Relational Operator4'
   *  RelationalOperator: '<S15>/Relational Operator5'
   *  RelationalOperator: '<S15>/Relational Operator6'
   */
  rtb_DataTypeConversion = ((VAR_MDF_AlOfsNoPlausState_u8 != 0) &&
    ((Drv_OffsetAcc != rtb_DataTypeConversion1) && (rtb_DataTypeConversion1 !=
    Drv_OffsetFw)) && (fabsf(tmpRead_5) <= CAL_MDF_trqOfsNoPlausFault_f32) &&
    (rtb_TmpSignalConversionAtRP_S_e == ((uint8)MDF_GLB_IGBTrun_u8)) &&
    ((rtb_Abs > CAL_MDF_nThresAlOfsNoPlauseFaultMin_f32) && (rtb_Abs <
    CAL_MDF_nThresAlOfsNoPlauseFaultMax_f32)));

  /* Switch: '<S19>/Switch' incorporates:
   *  Constant: '<S19>/CAL_MDF_tiOffsetSteady_f32'
   *  Constant: '<S19>/Ts2'
   *  RelationalOperator: '<S19>/Relational Operator1'
   *  Sum: '<S19>/Sum1'
   *  UnitDelay: '<S19>/Unit Delay1'
   *  UnitDelay: '<S19>/Unit Delay2'
   */
  if ((sint32)rtb_DataTypeConversion > (sint32)SWC_MDF_DW.UnitDelay2_DSTATE_o) {
    SWC_MDF_DW.UnitDelay1_DSTATE = CAL_MDF_tiOffsetSteady_f32;
  }

  SWC_MDF_DW.UnitDelay1_DSTATE -= 0.01F;

  /* End of Switch: '<S19>/Switch' */

  /* Logic: '<S19>/Logical Operator1' incorporates:
   *  Constant: '<S19>/Ts1'
   *  RelationalOperator: '<S19>/Relational Operator'
   *  UnitDelay: '<S19>/Unit Delay1'
   */
  VAR_MDF_bAlOfsChk_b = (rtb_DataTypeConversion && (SWC_MDF_DW.UnitDelay1_DSTATE
    <= -0.01F));

  /* Outputs for Enabled SubSystem: '<S6>/OfsNoPlausFaultCalc' incorporates:
   *  EnablePort: '<S17>/Enable'
   */
  if (VAR_MDF_bAlOfsChk_b) {
    /* Product: '<S22>/Divide' incorporates:
     *  Constant: '<S21>/CAL_MDF_OfsDeltaAgFltFrq_f32'
     *  Constant: '<S21>/PRV_CalFltFrq_10ms'
     */
    rtb_Abs2 = 100.0F / CAL_MDF_OfsDeltaAgFltFrq_f32;

    /* Switch: '<S23>/Switch' incorporates:
     *  Constant: '<S22>/Constant'
     *  RelationalOperator: '<S23>/UpperRelop'
     *  Switch: '<S23>/Switch2'
     */
    if (rtb_Abs2 < 1.0F) {
      rtb_Abs2 = 1.0F;
    }

    /* End of Switch: '<S23>/Switch' */

    /* Product: '<S22>/Divide1' incorporates:
     *  Constant: '<S22>/CAL_Mdf_Multiple_u8'
     *  Constant: '<S22>/MDF_GLB_pi_f32'
     *  Product: '<S22>/Product2'
     *  Sum: '<S22>/Add'
     */
    rtb_Abs2 /= MDF_GLB_pi_f32 * 2.0F + rtb_Abs2;

    /* Sum: '<S22>/Sum1' incorporates:
     *  Constant: '<S22>/One'
     *  Product: '<S22>/Product'
     *  Product: '<S22>/Product1'
     *  Sum: '<S22>/Subtract1'
     *  UnitDelay: '<S22>/Unit Delay'
     */
    SWC_MDF_DW.UnitDelay_DSTATE_m = (1.0F - rtb_Abs2) *
      VAR_MDF_offsetDeltaObs_f32 + rtb_Abs2 * SWC_MDF_DW.UnitDelay_DSTATE_m;

    /* Abs: '<S21>/Abs1' incorporates:
     *  UnitDelay: '<S22>/Unit Delay'
     */
    VAR_MDF_offsetDeltaFlt_f32 = fabsf(SWC_MDF_DW.UnitDelay_DSTATE_m);

    /* RelationalOperator: '<S21>/Relational Operator' incorporates:
     *  Constant: '<S21>/CAL_MDF_DIffAlOfsMax_f32'
     */
    rtb_RelationalOperator_og = (VAR_MDF_offsetDeltaFlt_f32 >
      CAL_MDF_DIffAlOfsMax_f32);

    /* Switch: '<S20>/Switch' incorporates:
     *  Constant: '<S20>/CAL_MDF_tiAlfOfsNoPlauseFault_f32'
     *  Constant: '<S20>/unitTime'
     *  RelationalOperator: '<S20>/Relational Operator1'
     *  Sum: '<S20>/Sum1'
     *  UnitDelay: '<S20>/Unit Delay1'
     *  UnitDelay: '<S20>/Unit Delay2'
     */
    if ((sint32)rtb_RelationalOperator_og > (sint32)
        SWC_MDF_DW.UnitDelay2_DSTATE_ag) {
      SWC_MDF_DW.UnitDelay1_DSTATE_aj = CAL_MDF_tiAlfOfsNoPlauseFault_f32;
    }

    SWC_MDF_DW.UnitDelay1_DSTATE_aj -= 0.01F;

    /* End of Switch: '<S20>/Switch' */

    /* Saturate: '<S20>/Saturation' incorporates:
     *  UnitDelay: '<S20>/Unit Delay1'
     */
    if (SWC_MDF_DW.UnitDelay1_DSTATE_aj > 10000.0F) {
      rtb_Abs2 = 10000.0F;
    } else if (SWC_MDF_DW.UnitDelay1_DSTATE_aj < -10000.0F) {
      rtb_Abs2 = -10000.0F;
    } else {
      rtb_Abs2 = SWC_MDF_DW.UnitDelay1_DSTATE_aj;
    }

    /* End of Saturate: '<S20>/Saturation' */

    /* Logic: '<S20>/Logical Operator1' incorporates:
     *  Constant: '<S20>/-unitTime'
     *  RelationalOperator: '<S20>/Relational Operator'
     */
    VAR_MDF_bAlfOfsNoPlauseFault_b = (rtb_RelationalOperator_og && (rtb_Abs2 <=
      -0.01F));

    /* Switch: '<S17>/Switch1' incorporates:
     *  Constant: '<S17>/Constant5'
     *  Constant: '<S17>/Constant6'
     */
    if (VAR_MDF_bAlfOfsNoPlauseFault_b) {
      SWC_MDF_B.Switch1_n = 3U;
    } else {
      SWC_MDF_B.Switch1_n = 2U;
    }

    /* End of Switch: '<S17>/Switch1' */

    /* Update for UnitDelay: '<S20>/Unit Delay2' */
    SWC_MDF_DW.UnitDelay2_DSTATE_ag = rtb_RelationalOperator_og;
  }

  /* End of Outputs for SubSystem: '<S6>/OfsNoPlausFaultCalc' */

  /* FunctionCaller: '<S1>/RP_SWC_Dem_MDF_AlOfsNoPlausFail_SetEventStatus' */
  Rte_Call_RP_SWC_Dem_MDF_AlOfsNoPlausFail_SetEventStatus(SWC_MDF_B.Switch1_n);

  /* FunctionCaller: '<S1>/RP_SWC_FIM_MDF_DiashCirNoPsblErr_GetFunctionPermission' */
  Rte_Call_RP_SWC_FIM_MDF_DiashCirNoPsblErr_GetFunctionPermission
    (&VAR_MDF_DiashCirNoPsblState_u8);

  /* Logic: '<S60>/Logical Operator' incorporates:
   *  Constant: '<S60>/CAL_MDF_nAbsThreshCirNoPsbl_f32'
   *  Constant: '<S60>/MDF_GLB_IGBTAscDwn_u8'
   *  Constant: '<S60>/MDF_GLB_IGBTAscUp_u8'
   *  Logic: '<S60>/Logical Operator1'
   *  RelationalOperator: '<S60>/Relational Operator'
   *  RelationalOperator: '<S60>/Relational Operator1'
   *  RelationalOperator: '<S60>/Relational Operator2'
   */
  VAR_MDF_bstGateDrvShCir_b = ((VAR_MDF_DiashCirNoPsblState_u8 != 0) &&
    ((rtb_TmpSignalConversionAtRP_S_e == ((uint8)MDF_GLB_IGBTAscUp_u8)) ||
     (rtb_TmpSignalConversionAtRP_S_e == ((uint8)MDF_GLB_IGBTAscDwn_u8))) &&
    (rtb_Abs > CAL_MDF_nAbsThreshCirNoPsbl_f32));

  /* SignalConversion generated from: '<S1>/RP_SWC_MPC_MPC_IsFlt_read' incorporates:
   *  Inport: '<Root>/RP_SWC_MPC_MPC_IsFlt'
   */
  Rte_Read_RP_SWC_MPC_MPC_IsFlt(&rtb_TmpSignalConversionAtRP_S_b);

  /* SignalConversion generated from: '<S1>/RP_SWC_HSPF_HSPF_uDcLnkSlowFlt_read' incorporates:
   *  Inport: '<Root>/RP_SWC_HSPF_HSPF_uDcLnkSlowFlt'
   */
  Rte_Read_RP_SWC_HSPF_HSPF_uDcLnkSlowFlt(&rtb_TmpSignalConversionAtRP__fh);

  /* Outputs for Enabled SubSystem: '<S14>/DFCCalc' incorporates:
   *  EnablePort: '<S59>/Enable'
   */
  if (VAR_MDF_bstGateDrvShCir_b) {
    /* Logic: '<S59>/Logical Operator' incorporates:
     *  Constant: '<S59>/CAL_MDF_IsThreshCirNoPsbl_f32'
     *  Constant: '<S59>/CAL_MDF_UdcThreshCirNoPsbl_f32'
     *  RelationalOperator: '<S59>/Relational Operator'
     *  RelationalOperator: '<S59>/Relational Operator1'
     */
    VAR_MDF_bshCirNoPsblFaul_b = ((rtb_TmpSignalConversionAtRP_S_b <=
      CAL_MDF_IsThreshCirNoPsbl_f32) || (rtb_TmpSignalConversionAtRP__fh >=
      CAL_MDF_UdcThreshCirNoPsbl_f32));

    /* Switch: '<S59>/Switch1' incorporates:
     *  Constant: '<S59>/Constant3'
     *  Constant: '<S59>/Constant4'
     */
    if (VAR_MDF_bshCirNoPsblFaul_b) {
      SWC_MDF_B.Switch1_d = 3U;
    } else {
      SWC_MDF_B.Switch1_d = 2U;
    }

    /* End of Switch: '<S59>/Switch1' */
  }

  /* End of Outputs for SubSystem: '<S14>/DFCCalc' */

  /* FunctionCaller: '<S1>/RP_SWC_Dem_MDF_DiashCirNoPsblFail_SetEventStatus' */
  Rte_Call_RP_SWC_Dem_MDF_DiashCirNoPsblFail_SetEventStatus(SWC_MDF_B.Switch1_d);

  /* FunctionCaller: '<S1>/RP_SWC_FIM_MDF_EmacBlkdWarn_GetFunctionPermission' */
  Rte_Call_RP_SWC_FIM_MDF_EmacBlkdWarn_GetFunctionPermission
    (&VAR_MDF_EmacBlkdState_u8);

  /* Logic: '<S30>/Logical Operator1' incorporates:
   *  Constant: '<S30>/Constant2'
   *  Constant: '<S30>/Constant3'
   *  Constant: '<S30>/MDF_GLB_IGBTrun_u8'
   *  Logic: '<S30>/Logical Operator'
   *  RelationalOperator: '<S30>/Relational Operator'
   *  RelationalOperator: '<S30>/Relational Operator1'
   *  RelationalOperator: '<S30>/Relational Operator2'
   */
  VAR_MDF_bEMBlkChk_b = ((VAR_MDF_EmacBlkdState_u8 != 0) &&
    (rtb_TmpSignalConversionAtRP_S_e == ((uint8)MDF_GLB_IGBTrun_u8)) &&
    ((Drv_OffsetAcc != rtb_DataTypeConversion1) && (rtb_DataTypeConversion1 !=
    Drv_OffsetFw)));

  /* SignalConversion generated from: '<S1>/RP_SWC_MPC_MPC_TrqMech_read' incorporates:
   *  Inport: '<Root>/RP_SWC_MPC_MPC_TrqMech'
   */
  Rte_Read_RP_SWC_MPC_MPC_TrqMech(&rtb_TmpSignalConversionAtRP__pk);

  /* Outputs for Enabled SubSystem: '<S7>/EMBlk' incorporates:
   *  EnablePort: '<S31>/Enable'
   */
  if (VAR_MDF_bEMBlkChk_b) {
    SWC_MDF_DW.EMBlk_MODE = true;

    /* RelationalOperator: '<S34>/Relational Operator1' incorporates:
     *  Constant: '<S34>/CAL_MDF_nAbsThresblockedElMa_f32'
     */
    rtb_RelationalOperator_og = (rtb_Abs < CAL_MDF_nAbsThresblockedElMa_f32);

    /* Logic: '<S34>/Logical Operator3' incorporates:
     *  Abs: '<S4>/Abs1'
     *  Constant: '<S34>/CAL_MDF_EMBlkWarn_f32'
     *  Constant: '<S34>/MDF_GLB_MaxTrq_f32'
     *  Product: '<S34>/Product'
     *  RelationalOperator: '<S34>/Relational Operator4'
     */
    VAR_MDF_bFaultEMBlkWarn_b = ((fabsf(rtb_TmpSignalConversionAtRP__pk) >
      MDF_GLB_MaxTrq_f32 * CAL_MDF_EMBlkWarn_f32) && rtb_RelationalOperator_og);

    /* Switch: '<S31>/Switch5' incorporates:
     *  Constant: '<S31>/Constant19'
     *  Constant: '<S31>/Constant20'
     */
    if (VAR_MDF_bFaultEMBlkWarn_b) {
      SWC_MDF_B.Switch5 = 3U;
    } else {
      SWC_MDF_B.Switch5 = 2U;
    }

    /* End of Switch: '<S31>/Switch5' */

    /* Switch: '<S35>/Switch' incorporates:
     *  Constant: '<S35>/CAL_MDF_tiEMBlk_f32'
     *  Constant: '<S35>/Unit time'
     *  RelationalOperator: '<S35>/Relational Operator1'
     *  Sum: '<S35>/Sum1'
     *  UnitDelay: '<S35>/Unit Delay1'
     *  UnitDelay: '<S35>/Unit Delay2'
     */
    if ((sint32)VAR_MDF_bFaultEMBlkWarn_b > (sint32)
        SWC_MDF_DW.UnitDelay2_DSTATE_p) {
      SWC_MDF_DW.UnitDelay1_DSTATE_hq = CAL_MDF_tiEMBlk_f32;
    }

    SWC_MDF_DW.UnitDelay1_DSTATE_hq -= 0.01F;

    /* End of Switch: '<S35>/Switch' */

    /* Switch: '<S33>/Switch1' incorporates:
     *  Constant: '<S33>/Constant'
     *  Constant: '<S35>/unit time'
     *  Logic: '<S33>/Logical Operator10'
     *  Logic: '<S33>/Logical Operator11'
     *  Logic: '<S33>/Logical Operator2'
     *  Logic: '<S35>/Logical Operator1'
     *  RelationalOperator: '<S35>/Relational Operator'
     *  Saturate: '<S35>/Saturation'
     *  UnitDelay: '<S33>/Unit Delay3'
     *  UnitDelay: '<S33>/Unit Delay5'
     *  UnitDelay: '<S35>/Unit Delay1'
     */
    if (VAR_MDF_bFaultEMBlkErr_b && (!rtb_RelationalOperator_og)) {
      SWC_MDF_DW.UnitDelay5_DSTATE = false;
    } else {
      if (SWC_MDF_DW.UnitDelay1_DSTATE_hq > 10000.0F) {
        /* Saturate: '<S35>/Saturation' */
        rtb_Abs2 = 10000.0F;
      } else if (SWC_MDF_DW.UnitDelay1_DSTATE_hq < -10000.0F) {
        /* Saturate: '<S35>/Saturation' */
        rtb_Abs2 = -10000.0F;
      } else {
        /* Saturate: '<S35>/Saturation' incorporates:
         *  UnitDelay: '<S35>/Unit Delay1'
         */
        rtb_Abs2 = SWC_MDF_DW.UnitDelay1_DSTATE_hq;
      }

      SWC_MDF_DW.UnitDelay5_DSTATE = ((VAR_MDF_bFaultEMBlkWarn_b && (rtb_Abs2 <=
        -0.01F)) || SWC_MDF_DW.UnitDelay5_DSTATE);
    }

    /* End of Switch: '<S33>/Switch1' */

    /* Switch: '<S33>/Switch2' incorporates:
     *  Constant: '<S33>/CAL_MDF_tiQuitEMBlk_f32'
     *  Constant: '<S33>/Constant3'
     *  Logic: '<S33>/Logical Operator1'
     *  RelationalOperator: '<S33>/Relational Operator1'
     *  Sum: '<S33>/Sum1'
     *  UnitDelay: '<S33>/Unit Delay1'
     *  UnitDelay: '<S33>/Unit Delay2'
     *  UnitDelay: '<S33>/Unit Delay4'
     */
    if (SWC_MDF_DW.UnitDelay4_DSTATE && ((sint32)rtb_RelationalOperator_og <
         (sint32)SWC_MDF_DW.UnitDelay1_DSTATE_fu)) {
      SWC_MDF_DW.UnitDelay2_DSTATE_b = CAL_MDF_tiQuitEMBlk_f32;
    }

    SWC_MDF_DW.UnitDelay2_DSTATE_b -= 0.01F;

    /* End of Switch: '<S33>/Switch2' */

    /* Switch: '<S33>/Switch6' incorporates:
     *  Constant: '<S33>/Constant2'
     *  Logic: '<S33>/Logical Operator3'
     *  Logic: '<S33>/Logical Operator9'
     *  RelationalOperator: '<S33>/Relational Operator'
     *  UnitDelay: '<S33>/Unit Delay5'
     */
    if (!rtb_RelationalOperator_og) {
      /* Saturate: '<S33>/Saturation' incorporates:
       *  UnitDelay: '<S33>/Unit Delay2'
       */
      if (SWC_MDF_DW.UnitDelay2_DSTATE_b > 10000.0F) {
        rtb_Abs2 = 10000.0F;
      } else if (SWC_MDF_DW.UnitDelay2_DSTATE_b < -10000.0F) {
        rtb_Abs2 = -10000.0F;
      } else {
        rtb_Abs2 = SWC_MDF_DW.UnitDelay2_DSTATE_b;
      }

      /* End of Saturate: '<S33>/Saturation' */
      VAR_MDF_bFaultEMBlkErr_b = (rtb_Abs2 > -0.01F);
    } else {
      VAR_MDF_bFaultEMBlkErr_b = SWC_MDF_DW.UnitDelay5_DSTATE;
    }

    /* End of Switch: '<S33>/Switch6' */

    /* Switch: '<S31>/Switch2' incorporates:
     *  Constant: '<S31>/Constant4'
     *  Constant: '<S31>/Constant8'
     */
    if (VAR_MDF_bFaultEMBlkErr_b) {
      SWC_MDF_B.Switch2_n = 3U;
    } else {
      SWC_MDF_B.Switch2_n = 2U;
    }

    /* End of Switch: '<S31>/Switch2' */

    /* Update for UnitDelay: '<S35>/Unit Delay2' */
    SWC_MDF_DW.UnitDelay2_DSTATE_p = VAR_MDF_bFaultEMBlkWarn_b;

    /* Update for UnitDelay: '<S33>/Unit Delay4' */
    SWC_MDF_DW.UnitDelay4_DSTATE = VAR_MDF_bFaultEMBlkErr_b;

    /* Update for UnitDelay: '<S33>/Unit Delay1' */
    SWC_MDF_DW.UnitDelay1_DSTATE_fu = rtb_RelationalOperator_og;
  } else {
    if (SWC_MDF_DW.EMBlk_MODE) {
      /* Disable for Outport: '<S31>/MDF_bFaultEMBlkErr' */
      VAR_MDF_bFaultEMBlkErr_b = false;

      /* Disable for Outport: '<S31>/MDF_bFaultEMBlkWarn' */
      VAR_MDF_bFaultEMBlkWarn_b = false;
      SWC_MDF_DW.EMBlk_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S7>/EMBlk' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_MDF_10ms' */

  /* Inport: '<Root>/RP_SWC_MPC_MPC_Ld' */
  Rte_Read_RP_SWC_MPC_MPC_Ld(&tmpRead_4);

  /* Inport: '<Root>/RP_SWC_MCF_MCF_iqDes' */
  Rte_Read_RP_SWC_MCF_MCF_iqDes(&tmpRead_2);

  /* Inport: '<Root>/RP_SWC_MCF_MCF_idDes' */
  Rte_Read_RP_SWC_MCF_MCF_idDes(&tmpRead_1);

  /* Inport: '<Root>/RP_SWC_HSPF_HSPF_PwrDcLnk' */
  Rte_Read_RP_SWC_HSPF_HSPF_PwrDcLnk(&tmpRead);

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_MDF_10ms' incorporates:
   *  SubSystem: '<Root>/RE_SWC_MDF_10ms_sys'
   */
  /* FunctionCaller: '<S1>/RP_SWC_Dem_MDF_EmacBlkdFail_SetEventStatus' */
  Rte_Call_RP_SWC_Dem_MDF_EmacBlkdFail_SetEventStatus(SWC_MDF_B.Switch2_n);

  /* FunctionCaller: '<S1>/RP_SWC_Dem_MDF_EmacBlkdWarn_SetEventStatus' */
  Rte_Call_RP_SWC_Dem_MDF_EmacBlkdWarn_SetEventStatus(SWC_MDF_B.Switch5);

  /* FunctionCaller: '<S1>/RP_SWC_FIM_MDF_IctlRat_GetFunctionPermission' */
  Rte_Call_RP_SWC_FIM_MDF_IctlRat_GetFunctionPermission(&VAR_MDF_ICtlRatState_u8);

  /* Logic: '<S36>/Logical Operator1' incorporates:
   *  Constant: '<S36>/MDF_GLB_IGBTrun_u8'
   *  Constant: '<S36>/iEDS_Enum_stDrvCtl_def.Drv_OffsetAcc'
   *  Constant: '<S36>/iEDS_Enum_stDrvCtl_def.Drv_OffsetFw'
   *  Logic: '<S36>/Logical Operator'
   *  RelationalOperator: '<S36>/Relational Operator'
   *  RelationalOperator: '<S36>/Relational Operator1'
   *  RelationalOperator: '<S36>/Relational Operator2'
   */
  VAR_MDF_bICtlRatChk_b = ((VAR_MDF_ICtlRatState_u8 != 0) &&
    (rtb_TmpSignalConversionAtRP_S_e == ((uint8)MDF_GLB_IGBTrun_u8)) &&
    ((Drv_OffsetAcc != rtb_DataTypeConversion1) && (rtb_DataTypeConversion1 !=
    Drv_OffsetFw)));

  /* Product: '<S64>/Product5' incorporates:
   *  Constant: '<S64>/MDF_GLB_pi_f32'
   *  Constant: '<S64>/cnv'
   */
  rtb_Product5_js = rtb_Product5_js * MDF_GLB_pi_f32 * 2.0F;

  /* SignalConversion generated from: '<S1>/RP_SWC_MPC_MPC_Psi_read' incorporates:
   *  Inport: '<Root>/RP_SWC_MPC_MPC_Psi'
   */
  Rte_Read_RP_SWC_MPC_MPC_Psi(&rtb_TmpSignalConversionAtRP_S_c);

  /* Outputs for Atomic SubSystem: '<S5>/mdf_DiaElDrvCalc' */
  /* Sum: '<S74>/Add1' incorporates:
   *  Constant: '<S63>/CnvFac'
   *  Constant: '<S63>/MDF_GLB_pi_f32'
   *  Constant: '<S74>/CAL_MDF_PwrDcLinkEstFlt_f32'
   *  Constant: '<S74>/Constant1'
   *  Lookup_n-D: '<S66>/2-D powloss lookup Table'
   *  Product: '<S63>/Product5'
   *  Product: '<S74>/Product'
   *  Product: '<S74>/Product1'
   *  Product: '<S74>/Product2'
   *  Sum: '<S74>/Add'
   *  Sum: '<S74>/Add2'
   *  UnitDelay: '<S74>/Unit Delay'
   */
  SWC_MDF_DW.UnitDelay_DSTATE = (rtb_Divide_o * MDF_GLB_pi_f32 * 2.0F *
    rtb_TmpSignalConversionAtRP__pk + look2_iflf_binlxpw
    (rtb_TmpSignalConversionAtRP_S_b, rtb_TmpSignalConversionAtRP_S_o, ((const
    float32 *)&(CAL_MDF_PwrLoss_X_af32[0])), ((const float32 *)
    &(CAL_MDF_PwrLoss_Y_af32[0])), ((const float32 *)&(CAL_MDF_PwrLoss_Z_af32[0])),
     rtCP_uDpowlosslookupTable_maxIn, 2U)) * CAL_MDF_PwrDcLinkEstFlt_f32 + (1.0F
    - CAL_MDF_PwrDcLinkEstFlt_f32) * SWC_MDF_DW.UnitDelay_DSTATE;

  /* Sum: '<S72>/Add' incorporates:
   *  Constant: '<S72>/CAL_MDF_Pwr3PhaFlt_f32'
   *  Constant: '<S72>/Constant'
   *  Product: '<S72>/Product'
   *  Product: '<S72>/Product1'
   *  Sum: '<S72>/Add1'
   *  UnitDelay: '<S72>/Unit Delay'
   */
  SWC_MDF_DW.UnitDelay_DSTATE_j = (1.0F - CAL_MDF_Pwr3PhaFlt_f32) *
    SWC_MDF_DW.UnitDelay_DSTATE_j + tmpRead * CAL_MDF_Pwr3PhaFlt_f32;

  /* Sum: '<S71>/Add4' */
  rtb_Abs2 = tmpRead_1 - rtb_TmpSignalConversionAtRP_SWC;

  /* Product: '<S71>/Product4' */
  rtb_Divide_o = rtb_Abs2 * rtb_Abs2;

  /* Sum: '<S71>/Add5' */
  rtb_Abs2 = tmpRead_2 - rtb_TmpSignalConversionAtRP__lr;

  /* Sqrt: '<S71>/Sqrt1' incorporates:
   *  Product: '<S71>/Product6'
   *  Sum: '<S71>/Add6'
   */
  rtb_Abs2 = sqrtf(rtb_Abs2 * rtb_Abs2 + rtb_Divide_o);

  /* Sum: '<S71>/Add' incorporates:
   *  Constant: '<S71>/CAL_MDF_IsErrFlt_f32'
   *  Constant: '<S71>/Constant'
   *  Product: '<S71>/Product'
   *  Product: '<S71>/Product1'
   *  Sum: '<S71>/Add1'
   *  UnitDelay: '<S71>/Unit Delay'
   */
  SWC_MDF_DW.UnitDelay_DSTATE_d = (1.0F - CAL_MDF_IsErrFlt_f32) *
    SWC_MDF_DW.UnitDelay_DSTATE_d + rtb_Abs2 * CAL_MDF_IsErrFlt_f32;

  /* Sum: '<S73>/Add1' incorporates:
   *  Product: '<S64>/Product1'
   *  Sum: '<S64>/Add'
   */
  rtb_Abs2 = (VAR_MDF_OffSetSiteAObs_f32_tmp - rtb_TmpSignalConversionAtRP__lr *
              rtb_TmpSignalConversionAtRP__iw * rtb_Product5_js) -
    rtb_TmpSignalConversionAtRP__jo;

  /* Product: '<S73>/Product5' */
  rtb_TmpSignalConversionAtRP__jo = rtb_Abs2 * rtb_Abs2;

  /* Sum: '<S73>/Add2' incorporates:
   *  Product: '<S64>/Product3'
   *  Product: '<S64>/Product4'
   *  Sum: '<S64>/Add1'
   */
  rtb_Abs2 = ((rtb_TmpSignalConversionAtRP_SWC * tmpRead_4 * rtb_Product5_js +
               rtb_TmpSignalConversionAtRP__nu) + rtb_Product5_js *
              rtb_TmpSignalConversionAtRP_S_c) - rtb_TmpSignalConversionAtRP_S_p;

  /* Sqrt: '<S73>/Sqrt' incorporates:
   *  Product: '<S73>/Product3'
   *  Sum: '<S73>/Add3'
   */
  rtb_Abs2 = sqrtf(rtb_Abs2 * rtb_Abs2 + rtb_TmpSignalConversionAtRP__jo);

  /* Sum: '<S73>/Add' incorporates:
   *  Constant: '<S73>/CAL_MDF_UsErrFlt_f32'
   *  Constant: '<S73>/Constant'
   *  Product: '<S73>/Product'
   *  Product: '<S73>/Product4'
   *  Sum: '<S73>/Add4'
   *  UnitDelay: '<S73>/Unit Delay'
   */
  SWC_MDF_DW.UnitDelay_DSTATE_g = (1.0F - CAL_MDF_UsErrFlt_f32) *
    SWC_MDF_DW.UnitDelay_DSTATE_g + rtb_Abs2 * CAL_MDF_UsErrFlt_f32;

  /* End of Outputs for SubSystem: '<S5>/mdf_DiaElDrvCalc' */

  /* Outputs for Enabled SubSystem: '<S8>/iCtlJudge' incorporates:
   *  EnablePort: '<S38>/Enable'
   */
  if (VAR_MDF_bICtlRatChk_b) {
    /* Outputs for Atomic SubSystem: '<S5>/mdf_DiaElDrvCalc' */
    /* Switch: '<S70>/Switch1' incorporates:
     *  Constant: '<S70>/Constant'
     *  Constant: '<S70>/MDF_GLB_IGBTrun_u8'
     *  RelationalOperator: '<S70>/Relational Operator'
     *  Switch: '<S70>/Switch'
     *  UnitDelay: '<S71>/Unit Delay'
     *  UnitDelay: '<S73>/Unit Delay'
     */
    if (rtb_TmpSignalConversionAtRP_S_e == ((uint8)MDF_GLB_IGBTrun_u8)) {
      rtb_Abs2 = SWC_MDF_DW.UnitDelay_DSTATE_g;
      rtb_TmpSignalConversionAtRP_SWC = SWC_MDF_DW.UnitDelay_DSTATE_d;
    } else {
      rtb_Abs2 = 0.0F;
      rtb_TmpSignalConversionAtRP_SWC = 0.0F;
    }

    /* End of Switch: '<S70>/Switch1' */
    /* End of Outputs for SubSystem: '<S5>/mdf_DiaElDrvCalc' */

    /* Logic: '<S38>/Logical Operator' incorporates:
     *  Constant: '<S38>/CAL_MDF_IsErrThres_f32'
     *  Constant: '<S38>/CAL_MDF_UsErrThres_f32'
     *  RelationalOperator: '<S38>/Relational Operator'
     *  RelationalOperator: '<S38>/Relational Operator1'
     */
    VAR_MDF_bFaultICtlChk_b = ((rtb_Abs2 > CAL_MDF_UsErrThres_f32) ||
      (rtb_TmpSignalConversionAtRP_SWC > CAL_MDF_IsErrThres_f32));

    /* Switch: '<S38>/Switch1' incorporates:
     *  Constant: '<S38>/Constant3'
     *  Constant: '<S38>/Constant4'
     */
    if (VAR_MDF_bFaultICtlChk_b) {
      SWC_MDF_B.Switch1_gg = 3U;
    } else {
      SWC_MDF_B.Switch1_gg = 2U;
    }

    /* End of Switch: '<S38>/Switch1' */
  }

  /* End of Outputs for SubSystem: '<S8>/iCtlJudge' */

  /* FunctionCaller: '<S1>/RP_SWC_Dem_MDF_ICtlRatFail_SetEventStatus' */
  Rte_Call_RP_SWC_Dem_MDF_ICtlRatFail_SetEventStatus(SWC_MDF_B.Switch1_gg);

  /* FunctionCaller: '<S1>/RP_SWC_FIM_MDFIsOvHiErr_GetFunctionPermission' */
  Rte_Call_RP_SWC_FIM_MDFIsOvHiErr_GetFunctionPermission
    (&rtb_RP_SWC_FIM_MDFIsOvHiErr_Get);

  /* Outputs for Enabled SubSystem: '<S9>/Subsystem' incorporates:
   *  EnablePort: '<S39>/Enable'
   */
  if (rtb_RP_SWC_FIM_MDFIsOvHiErr_Get > 0) {
    /* RelationalOperator: '<S39>/Relational Operator' incorporates:
     *  Constant: '<S39>/CAL_MDF_IsMaxSet_f32'
     */
    VAR_MDF_bIsOvHiFault_b = (rtb_TmpSignalConversionAtRP_S_b >
      CAL_MDF_IsMaxSet_f32);

    /* Logic: '<S39>/Logical Operator' incorporates:
     *  UnitDelay: '<S39>/Unit Delay'
     */
    SWC_MDF_DW.UnitDelay_DSTATE_b = (VAR_MDF_bIsOvHiFault_b ||
      SWC_MDF_DW.UnitDelay_DSTATE_b);

    /* Switch: '<S39>/Switch1' incorporates:
     *  Constant: '<S39>/Constant5'
     *  Constant: '<S39>/Constant6'
     *  UnitDelay: '<S39>/Unit Delay'
     */
    if (SWC_MDF_DW.UnitDelay_DSTATE_b) {
      SWC_MDF_B.Switch1_p = 3U;
    } else {
      SWC_MDF_B.Switch1_p = 2U;
    }

    /* End of Switch: '<S39>/Switch1' */
  }

  /* End of Outputs for SubSystem: '<S9>/Subsystem' */

  /* FunctionCaller: '<S1>/RP_SWC_Dem_MDF_IsOvHiFail_SetEventStatus' */
  Rte_Call_RP_SWC_Dem_MDF_IsOvHiFail_SetEventStatus(SWC_MDF_B.Switch1_p);

  /* FunctionCaller: '<S1>/RP_SWC_FIM_MDF_OpenCirNoPsblErr_GetFunctionPermission' */
  Rte_Call_RP_SWC_FIM_MDF_OpenCirNoPsblErr_GetFunctionPermission
    (&VAR_MDF_OpenCirNoPsblState_u8);

  /* Logic: '<S40>/Logical Operator' incorporates:
   *  Constant: '<S40>/CAL_MDF_nAbsThresOpenCirNoPsbl_f32'
   *  Constant: '<S40>/MDF_GLB_IGBTclose_u8'
   *  Constant: '<S40>/iEDS_Enum_stDrvCtl_def.Drv_SensCalFW'
   *  RelationalOperator: '<S40>/Relational Operator'
   *  RelationalOperator: '<S40>/Relational Operator1'
   *  RelationalOperator: '<S40>/Relational Operator2'
   */
  VAR_MDF_bstGateDrvOpenCir_b = ((VAR_MDF_OpenCirNoPsblState_u8 != 0) &&
    (rtb_TmpSignalConversionAtRP_S_e == ((uint8)MDF_GLB_IGBTclose_u8)) &&
    (rtb_Abs <= CAL_MDF_nAbsThresOpenCirNoPsbl_f32) && (rtb_DataTypeConversion1
    != Drv_SensCalFW));

  /* Product: '<S62>/Product' incorporates:
   *  Constant: '<S5>/MDF_GLB_MotorPole_u8'
   *  Constant: '<S62>/MDF_GLB_pi_f32'
   *  Gain: '<S62>/1//60*2'
   */
  rtb_TmpSignalConversionAtRP_S_c *= 0.0333333351F *
    rtb_TmpSignalConversionAtRP_S_o * MDF_GLB_pi_f32 * (float32)((uint8)
    MDF_GLB_MotorPole_u8);

  /* Sum: '<S62>/Add' incorporates:
   *  Constant: '<S62>/MDF_GLB_pi_f32'
   *  Gain: '<S62>/1//(3*sqrt(6))'
   *  Product: '<S62>/Product5'
   */
  rtb_TmpSignalConversionAtRP_S_o = rtb_TmpSignalConversionAtRP_S_c -
    rtb_TmpSignalConversionAtRP__fh * MDF_GLB_pi_f32 * 0.136082768F;

  /* Switch: '<S62>/Switch1' incorporates:
   *  Constant: '<S62>/CAL_MDF_UdcFwMin_f32'
   *  Constant: '<S62>/CAL_MDF_stFrwhlWoIs_u8'
   *  Constant: '<S62>/Constant'
   *  Logic: '<S62>/Logical Operator1'
   *  RelationalOperator: '<S62>/Relational Operator2'
   *  RelationalOperator: '<S62>/Relational Operator4'
   */
  if ((rtb_TmpSignalConversionAtRP__fh < CAL_MDF_UdcFwMin_f32) ||
      (rtb_TmpSignalConversionAtRP_S_o < 0.0F)) {
    SWC_MDF_DW.UnitDelay_DSTATE_h = CAL_MDF_stFrwhlWoIs_u8;
  } else {
    /* Sum: '<S62>/Add1' incorporates:
     *  Constant: '<S62>/CAL_MDF_UsFrwhlMax_f32'
     */
    rtb_TmpSignalConversionAtRP__fh = rtb_TmpSignalConversionAtRP_S_c -
      CAL_MDF_UsFrwhlMax_f32;

    /* Switch: '<S62>/Switch' incorporates:
     *  Constant: '<S62>/CAL_MDF_stFrwhlWiIs_u8'
     *  Logic: '<S62>/Logical Operator'
     *  RelationalOperator: '<S62>/Relational Operator'
     *  RelationalOperator: '<S62>/Relational Operator1'
     *  RelationalOperator: '<S62>/Relational Operator3'
     *  Switch: '<S62>/Switch2'
     */
    if ((rtb_TmpSignalConversionAtRP_S_o > 0.0F) &&
        (rtb_TmpSignalConversionAtRP__fh < 0.0F)) {
      SWC_MDF_DW.UnitDelay_DSTATE_h = CAL_MDF_stFrwhlWiIs_u8;
    } else {
      if (rtb_TmpSignalConversionAtRP__fh >= 0.0F) {
        /* Switch: '<S62>/Switch2' incorporates:
         *  Constant: '<S62>/CAL_MDF_stFrwhlPhd_u8'
         */
        SWC_MDF_DW.UnitDelay_DSTATE_h = CAL_MDF_stFrwhlPhd_u8;
      }
    }

    /* End of Switch: '<S62>/Switch' */
  }

  /* End of Switch: '<S62>/Switch1' */

  /* Outputs for Enabled SubSystem: '<S10>/OpenCirNoPsblCalc' incorporates:
   *  EnablePort: '<S42>/Enable'
   */
  if (VAR_MDF_bstGateDrvOpenCir_b) {
    /* Switch: '<S42>/Switch' incorporates:
     *  Constant: '<S42>/CAL_MDF_FwWoIs_f32'
     *  Constant: '<S42>/CAL_MDF_stFrwhlWoIs_u8'
     *  Constant: '<S42>/Constant4'
     *  RelationalOperator: '<S42>/Relational Operator'
     *  RelationalOperator: '<S42>/Relational Operator2'
     */
    if (CAL_MDF_stFrwhlWoIs_u8 == SWC_MDF_DW.UnitDelay_DSTATE_h) {
      tmp = (rtb_TmpSignalConversionAtRP_S_b >= CAL_MDF_FwWoIs_f32);
    } else {
      tmp = 0;
    }

    /* End of Switch: '<S42>/Switch' */

    /* Switch: '<S42>/Switch1' incorporates:
     *  Constant: '<S42>/CAL_MDF_FwWiIs_f32'
     *  Constant: '<S42>/CAL_MDF_stFrwhlWiIs_u8'
     *  Constant: '<S42>/Constant5'
     *  RelationalOperator: '<S42>/Relational Operator1'
     *  RelationalOperator: '<S42>/Relational Operator3'
     */
    if (SWC_MDF_DW.UnitDelay_DSTATE_h == CAL_MDF_stFrwhlWiIs_u8) {
      Switch1 = (rtb_TmpSignalConversionAtRP_S_b >= CAL_MDF_FwWiIs_f32);
    } else {
      Switch1 = 0;
    }

    /* End of Switch: '<S42>/Switch1' */

    /* Logic: '<S42>/Logical Operator' */
    VAR_MDF_bOpenCirNoPsblFault_b = ((tmp != 0) || (Switch1 != 0));

    /* Switch: '<S42>/Switch2' incorporates:
     *  Constant: '<S42>/Constant7'
     *  Constant: '<S42>/Constant8'
     */
    if (VAR_MDF_bOpenCirNoPsblFault_b) {
      SWC_MDF_B.Switch2_k = 3U;
    } else {
      SWC_MDF_B.Switch2_k = 2U;
    }

    /* End of Switch: '<S42>/Switch2' */
  }

  /* End of Outputs for SubSystem: '<S10>/OpenCirNoPsblCalc' */

  /* FunctionCaller: '<S1>/RP_SWC_Dem_MDF_OpenCirNoPsblFail_SetEventStatus' */
  Rte_Call_RP_SWC_Dem_MDF_OpenCirNoPsblFail_SetEventStatus(SWC_MDF_B.Switch2_k);

  /* FunctionCaller: '<S1>/RP_SWC_FIM_MDF_OperOutdRngErr_GetFunctionPermission' */
  Rte_Call_RP_SWC_FIM_MDF_OperOutdRngErr_GetFunctionPermission
    (&VAR_MDF_OperOutdRngState_u8);

  /* Logic: '<S43>/Logical Operator' incorporates:
   *  Constant: '<S43>/CAL_MDF_Inactive_u8'
   *  Constant: '<S43>/CAL_MDF_tOperOutdRngSelState_b'
   *  Constant: '<S43>/MDF_GLB_IGBTAscDwn_u8'
   *  Constant: '<S43>/MDF_GLB_IGBTAscUp_u8'
   *  Constant: '<S43>/iEDS_Enum_stDrvCtl_def.Drv_Standby'
   *  Logic: '<S43>/Logical Operator1'
   *  RelationalOperator: '<S43>/Relational Operator'
   *  RelationalOperator: '<S43>/Relational Operator1'
   *  RelationalOperator: '<S43>/Relational Operator2'
   *  RelationalOperator: '<S43>/Relational Operator3'
   */
  VAR_MDF_flagOperOutdRngChk_b = ((VAR_MDF_OperOutdRngState_u8 != 0) &&
    ((rtb_TmpSignalConversionAtRP_S_e == ((uint8)MDF_GLB_IGBTAscUp_u8)) ||
     (rtb_TmpSignalConversionAtRP_S_e == ((uint8)MDF_GLB_IGBTAscDwn_u8))) &&
    (rtb_DataTypeConversion1 == Drv_Standby) && (CAL_MDF_tOperOutdRngSelState_b
    != CAL_MDF_Inactive_u8));

  /* SignalConversion generated from: '<S1>/RP_SWC_HSPF_HSPF_tDBCTempUFlt_read' incorporates:
   *  Inport: '<Root>/RP_SWC_HSPF_HSPF_tDBCTempUFlt'
   */
  Rte_Read_RP_SWC_HSPF_HSPF_tDBCTempUFlt(&rtb_TmpSignalConversionAtRP_S_a);

  /* SignalConversion generated from: '<S1>/RP_SWC_HSPF_HSPF_tDBCTempVFlt_read' incorporates:
   *  Inport: '<Root>/RP_SWC_HSPF_HSPF_tDBCTempVFlt'
   */
  Rte_Read_RP_SWC_HSPF_HSPF_tDBCTempVFlt(&rtb_TmpSignalConversionAtRP__jj);

  /* SignalConversion generated from: '<S1>/RP_SWC_HSPF_HSPF_tDBCTempWFlt_read' incorporates:
   *  Inport: '<Root>/RP_SWC_HSPF_HSPF_tDBCTempWFlt'
   */
  Rte_Read_RP_SWC_HSPF_HSPF_tDBCTempWFlt(&rtb_TmpSignalConversionAtRP_S_f);

  /* Outputs for Enabled SubSystem: '<S11>/OperOutdRngFltCalc' incorporates:
   *  EnablePort: '<S45>/Enable'
   */
  if (VAR_MDF_flagOperOutdRngChk_b) {
    /* Inport: '<Root>/RP_SWC_HSPF_HSPF_tCoolantTempFlt' */
    Rte_Read_RP_SWC_HSPF_HSPF_tCoolantTempFlt(&rtb_UnitDelay_k3);

    /* Inport: '<Root>/RP_SWC_HSPF_HSPF_tStrrTempFlt' */
    Rte_Read_RP_SWC_HSPF_HSPF_tStrrTempFlt(&rtb_UnitDelay1_m);

    /* Switch: '<S45>/Switch' incorporates:
     *  Sum: '<S45>/Subtract'
     */
    if (rtb_TmpSignalConversionAtRP_S_a - rtb_TmpSignalConversionAtRP__jj >=
        0.0F) {
      rtb_TmpSignalConversionAtRP__jj = rtb_TmpSignalConversionAtRP_S_a;
    }

    /* End of Switch: '<S45>/Switch' */

    /* Switch: '<S45>/Switch1' incorporates:
     *  Sum: '<S45>/Subtract1'
     */
    if (rtb_TmpSignalConversionAtRP__jj - rtb_TmpSignalConversionAtRP_S_f < 0.0F)
    {
      rtb_TmpSignalConversionAtRP__jj = rtb_TmpSignalConversionAtRP_S_f;
    }

    /* End of Switch: '<S45>/Switch1' */

    /* Logic: '<S45>/Logical Operator' incorporates:
     *  Constant: '<S45>/CAL_MDF_tThd_TempDBCInvCoolObsvr_f32'
     *  Constant: '<S45>/CAL_MDF_tThd_TempDBCInvSens3Pha_f32'
     *  Constant: '<S45>/CAL_MDF_tThd_TempStr_f32'
     *  RelationalOperator: '<S45>/Relational Operator'
     *  RelationalOperator: '<S45>/Relational Operator1'
     *  RelationalOperator: '<S45>/Relational Operator2'
     */
    VAR_MDF_flagOperOutdRngFault_b = ((rtb_TmpSignalConversionAtRP__jj >
      CAL_MDF_tThd_TempDBCInvSens3Pha_f32) || (rtb_UnitDelay1_m >
      CAL_MDF_tThd_TempStr_f32) || (rtb_UnitDelay_k3 >
      CAL_MDF_tThd_TempDBCInvCoolObsvr_f32));

    /* Switch: '<S45>/Switch2' incorporates:
     *  Constant: '<S45>/Constant3'
     *  Constant: '<S45>/Constant4'
     */
    if (VAR_MDF_flagOperOutdRngFault_b) {
      SWC_MDF_B.Switch2 = 3U;
    } else {
      SWC_MDF_B.Switch2 = 2U;
    }

    /* End of Switch: '<S45>/Switch2' */
  }

  /* End of Outputs for SubSystem: '<S11>/OperOutdRngFltCalc' */

  /* FunctionCaller: '<S1>/RP_SWC_Dem_MDF_OperOutdRngFail_SetEventStatus' */
  Rte_Call_RP_SWC_Dem_MDF_OperOutdRngFail_SetEventStatus(SWC_MDF_B.Switch2);

  /* FunctionCaller: '<S1>/RP_SWC_FIM_MDF_PhaseLossFaultErr_GetFunctionPermission' */
  Rte_Call_RP_SWC_FIM_MDF_PhaseLossFaultErr_GetFunctionPermission
    (&VAR_MDF_PhaseFaultState_u8);

  /* Logic: '<S46>/Logical Operator1' incorporates:
   *  Constant: '<S46>/CAL_MDF_IsPhaseFault_f32'
   *  Constant: '<S46>/CAL_MDF_nAbsPhaseFault_f32'
   *  Constant: '<S46>/MDF_GLB_IGBTrun_u8'
   *  DataTypeConversion: '<S46>/Data Type Conversion'
   *  Logic: '<S46>/Logical Operator'
   *  Lookup_n-D: '<S46>/1-D Lookup Table'
   *  RelationalOperator: '<S46>/Relational Operator'
   *  RelationalOperator: '<S46>/Relational Operator1'
   *  RelationalOperator: '<S46>/Relational Operator2'
   */
  VAR_MDF_PhaseFaultChk_b = ((VAR_MDF_PhaseFaultState_u8 != 0) &&
    (rtb_TmpSignalConversionAtRP_S_e == ((uint8)MDF_GLB_IGBTrun_u8)) &&
    (rtb_TmpSignalConversionAtRP_S_b > CAL_MDF_IsPhaseFault_f32) &&
    ((look1_iflf_binlxpw(rtb_Abs, ((const float32 *)
    &(CAL_MDF_nAbsPhaseFault_X_af32[0])), ((const float32 *)
    &(CAL_MDF_cofnAbsPhaseFault_Y_af32[0])), 45U) != 0.0F) && (rtb_Abs >=
    CAL_MDF_nAbsPhaseFault_f32)));

  /* Outputs for Enabled SubSystem: '<S12>/PhaseFaultCalc' incorporates:
   *  EnablePort: '<S48>/Enable'
   */
  if (VAR_MDF_PhaseFaultChk_b) {
    /* Inport: '<Root>/RP_SWC_MCF_MCF_iW' */
    Rte_Read_RP_SWC_MCF_MCF_iW(&rtb_Abs_n);

    /* Inport: '<Root>/RP_SWC_MCF_MCF_iV' */
    Rte_Read_RP_SWC_MCF_MCF_iV(&rtb_Abs_p);

    /* Inport: '<Root>/RP_SWC_MCF_MCF_iU' */
    Rte_Read_RP_SWC_MCF_MCF_iU(&rtb_UnitDelay_p);
    SWC_MDF_DW.PhaseFaultCalc_MODE = true;

    /* Abs: '<S50>/Abs' */
    rtb_TmpSignalConversionAtRP_S_b = fabsf(rtb_UnitDelay_p);

    /* UnitDelay: '<S50>/Unit Delay' */
    rtb_TmpSignalConversionAtRP_S_a = SWC_MDF_DW.UnitDelay_DSTATE_i;

    /* UnitDelay: '<S50>/Unit Delay1' */
    rtb_TmpSignalConversionAtRP__jj = SWC_MDF_DW.UnitDelay1_DSTATE_f;

    /* UnitDelay: '<S50>/Unit Delay2' */
    rtb_TmpSignalConversionAtRP_S_f = SWC_MDF_DW.UnitDelay2_DSTATE;

    /* Sum: '<S50>/Add' incorporates:
     *  UnitDelay: '<S50>/Unit Delay'
     *  UnitDelay: '<S50>/Unit Delay1'
     *  UnitDelay: '<S50>/Unit Delay2'
     *  UnitDelay: '<S50>/Unit Delay3'
     */
    rtb_Abs2 = (((rtb_TmpSignalConversionAtRP_S_b +
                  SWC_MDF_DW.UnitDelay_DSTATE_i) +
                 SWC_MDF_DW.UnitDelay1_DSTATE_f) + SWC_MDF_DW.UnitDelay2_DSTATE)
      + SWC_MDF_DW.UnitDelay3_DSTATE;

    /* Abs: '<S51>/Abs' */
    rtb_Abs_p = fabsf(rtb_Abs_p);

    /* UnitDelay: '<S51>/Unit Delay' */
    rtb_UnitDelay_k3 = SWC_MDF_DW.UnitDelay_DSTATE_jv;

    /* UnitDelay: '<S51>/Unit Delay1' */
    rtb_UnitDelay1_m = SWC_MDF_DW.UnitDelay1_DSTATE_a;

    /* UnitDelay: '<S51>/Unit Delay2' */
    rtb_TmpSignalConversionAtRP__fh = SWC_MDF_DW.UnitDelay2_DSTATE_c;

    /* Sum: '<S51>/Add' incorporates:
     *  UnitDelay: '<S51>/Unit Delay'
     *  UnitDelay: '<S51>/Unit Delay1'
     *  UnitDelay: '<S51>/Unit Delay2'
     *  UnitDelay: '<S51>/Unit Delay3'
     */
    rtb_Product5_js = (((rtb_Abs_p + SWC_MDF_DW.UnitDelay_DSTATE_jv) +
                        SWC_MDF_DW.UnitDelay1_DSTATE_a) +
                       SWC_MDF_DW.UnitDelay2_DSTATE_c) +
      SWC_MDF_DW.UnitDelay3_DSTATE_b;

    /* Switch: '<S54>/Switch' incorporates:
     *  RelationalOperator: '<S54>/Relational Operator1'
     */
    if (rtb_Abs2 >= rtb_Product5_js) {
      rtb_TmpSignalConversionAtRP_SWC = rtb_Abs2;
    } else {
      rtb_TmpSignalConversionAtRP_SWC = rtb_Product5_js;
    }

    /* End of Switch: '<S54>/Switch' */

    /* Abs: '<S52>/Abs' */
    rtb_Abs_n = fabsf(rtb_Abs_n);

    /* UnitDelay: '<S52>/Unit Delay' */
    rtb_UnitDelay_p = SWC_MDF_DW.UnitDelay_DSTATE_gl;

    /* UnitDelay: '<S52>/Unit Delay1' */
    rtb_TmpSignalConversionAtRP_S_o = SWC_MDF_DW.UnitDelay1_DSTATE_m;

    /* UnitDelay: '<S52>/Unit Delay2' */
    rtb_TmpSignalConversionAtRP_S_c = SWC_MDF_DW.UnitDelay2_DSTATE_n;

    /* Sum: '<S52>/Add' incorporates:
     *  UnitDelay: '<S52>/Unit Delay'
     *  UnitDelay: '<S52>/Unit Delay1'
     *  UnitDelay: '<S52>/Unit Delay2'
     *  UnitDelay: '<S52>/Unit Delay3'
     */
    rtb_TmpSignalConversionAtRP_S_p = (((rtb_Abs_n +
      SWC_MDF_DW.UnitDelay_DSTATE_gl) + SWC_MDF_DW.UnitDelay1_DSTATE_m) +
      SWC_MDF_DW.UnitDelay2_DSTATE_n) + SWC_MDF_DW.UnitDelay3_DSTATE_k;

    /* Switch: '<S54>/Switch1' incorporates:
     *  RelationalOperator: '<S54>/Relational Operator2'
     */
    if (rtb_TmpSignalConversionAtRP_SWC < rtb_TmpSignalConversionAtRP_S_p) {
      rtb_TmpSignalConversionAtRP_SWC = rtb_TmpSignalConversionAtRP_S_p;
    }

    /* End of Switch: '<S54>/Switch1' */

    /* Product: '<S54>/Product' incorporates:
     *  Constant: '<S54>/AverageFac'
     */
    rtb_TmpSignalConversionAtRP_SWC *= 0.2F;

    /* Switch: '<S55>/Switch' incorporates:
     *  RelationalOperator: '<S55>/Relational Operator1'
     */
    if (rtb_Abs2 > rtb_Product5_js) {
      rtb_Abs2 = rtb_Product5_js;
    }

    /* End of Switch: '<S55>/Switch' */

    /* Switch: '<S55>/Switch1' incorporates:
     *  RelationalOperator: '<S55>/Relational Operator2'
     */
    if (rtb_Abs2 > rtb_TmpSignalConversionAtRP_S_p) {
      rtb_Abs2 = rtb_TmpSignalConversionAtRP_S_p;
    }

    /* End of Switch: '<S55>/Switch1' */

    /* Switch: '<S53>/Switch' incorporates:
     *  Constant: '<S53>/Constant1'
     *  RelationalOperator: '<S53>/Relational Operator'
     */
    if (rtb_TmpSignalConversionAtRP_SWC >= 1.0E-6F) {
      rtb_Product5_js = rtb_TmpSignalConversionAtRP_SWC;
    } else {
      rtb_Product5_js = 1.0E-6F;
    }

    /* End of Switch: '<S53>/Switch' */

    /* Product: '<S53>/Divide' incorporates:
     *  Constant: '<S55>/AverageFac'
     *  Product: '<S55>/Product'
     *  Sum: '<S53>/Add'
     */
    VAR_MDF_3PhaUnbalanceObs_f32 = (rtb_TmpSignalConversionAtRP_SWC - rtb_Abs2 *
      0.2F) * (1.0F / rtb_Product5_js);

    /* RelationalOperator: '<S53>/Relational Operator1' incorporates:
     *  Constant: '<S53>/CAL_MDF_3PhaUnbalance_f32'
     */
    rtb_RelationalOperator_og = (VAR_MDF_3PhaUnbalanceObs_f32 >=
      CAL_MDF_3PhaUnbalance_f32);

    /* Switch: '<S49>/Switch' incorporates:
     *  Constant: '<S49>/CAL_MDF_tiPhaFaultDelay_f32'
     *  Constant: '<S49>/unitTime'
     *  RelationalOperator: '<S49>/Relational Operator1'
     *  Sum: '<S49>/Sum1'
     *  UnitDelay: '<S49>/Unit Delay1'
     *  UnitDelay: '<S49>/Unit Delay2'
     */
    if ((sint32)rtb_RelationalOperator_og > (sint32)
        SWC_MDF_DW.UnitDelay2_DSTATE_a) {
      SWC_MDF_DW.UnitDelay1_DSTATE_h = CAL_MDF_tiPhaFaultDelay_f32;
    }

    SWC_MDF_DW.UnitDelay1_DSTATE_h -= 0.01F;

    /* End of Switch: '<S49>/Switch' */

    /* Saturate: '<S49>/Saturation' incorporates:
     *  UnitDelay: '<S49>/Unit Delay1'
     */
    if (SWC_MDF_DW.UnitDelay1_DSTATE_h > 10000.0F) {
      rtb_Abs2 = 10000.0F;
    } else if (SWC_MDF_DW.UnitDelay1_DSTATE_h < -10000.0F) {
      rtb_Abs2 = -10000.0F;
    } else {
      rtb_Abs2 = SWC_MDF_DW.UnitDelay1_DSTATE_h;
    }

    /* End of Saturate: '<S49>/Saturation' */

    /* Logic: '<S49>/Logical Operator1' incorporates:
     *  Constant: '<S49>/-unitTime'
     *  RelationalOperator: '<S49>/Relational Operator'
     */
    VAR_MDF_bPhaseFault_b = (rtb_RelationalOperator_og && (rtb_Abs2 <= -0.01F));

    /* Switch: '<S48>/Switch1' incorporates:
     *  Constant: '<S48>/Constant5'
     *  Constant: '<S48>/Constant6'
     */
    if (VAR_MDF_bPhaseFault_b) {
      SWC_MDF_B.Switch1_g = 3U;
    } else {
      SWC_MDF_B.Switch1_g = 2U;
    }

    /* End of Switch: '<S48>/Switch1' */

    /* Update for UnitDelay: '<S50>/Unit Delay' */
    SWC_MDF_DW.UnitDelay_DSTATE_i = rtb_TmpSignalConversionAtRP_S_b;

    /* Update for UnitDelay: '<S50>/Unit Delay1' */
    SWC_MDF_DW.UnitDelay1_DSTATE_f = rtb_TmpSignalConversionAtRP_S_a;

    /* Update for UnitDelay: '<S50>/Unit Delay2' */
    SWC_MDF_DW.UnitDelay2_DSTATE = rtb_TmpSignalConversionAtRP__jj;

    /* Update for UnitDelay: '<S50>/Unit Delay3' */
    SWC_MDF_DW.UnitDelay3_DSTATE = rtb_TmpSignalConversionAtRP_S_f;

    /* Update for UnitDelay: '<S51>/Unit Delay' */
    SWC_MDF_DW.UnitDelay_DSTATE_jv = rtb_Abs_p;

    /* Update for UnitDelay: '<S51>/Unit Delay1' */
    SWC_MDF_DW.UnitDelay1_DSTATE_a = rtb_UnitDelay_k3;

    /* Update for UnitDelay: '<S51>/Unit Delay2' */
    SWC_MDF_DW.UnitDelay2_DSTATE_c = rtb_UnitDelay1_m;

    /* Update for UnitDelay: '<S51>/Unit Delay3' */
    SWC_MDF_DW.UnitDelay3_DSTATE_b = rtb_TmpSignalConversionAtRP__fh;

    /* Update for UnitDelay: '<S52>/Unit Delay' */
    SWC_MDF_DW.UnitDelay_DSTATE_gl = rtb_Abs_n;

    /* Update for UnitDelay: '<S52>/Unit Delay1' */
    SWC_MDF_DW.UnitDelay1_DSTATE_m = rtb_UnitDelay_p;

    /* Update for UnitDelay: '<S52>/Unit Delay2' */
    SWC_MDF_DW.UnitDelay2_DSTATE_n = rtb_TmpSignalConversionAtRP_S_o;

    /* Update for UnitDelay: '<S52>/Unit Delay3' */
    SWC_MDF_DW.UnitDelay3_DSTATE_k = rtb_TmpSignalConversionAtRP_S_c;

    /* Update for UnitDelay: '<S49>/Unit Delay2' */
    SWC_MDF_DW.UnitDelay2_DSTATE_a = rtb_RelationalOperator_og;
  } else {
    if (SWC_MDF_DW.PhaseFaultCalc_MODE) {
      /* Disable for Outport: '<S48>/MDF_bPhaseFault' */
      VAR_MDF_bPhaseFault_b = false;
      SWC_MDF_DW.PhaseFaultCalc_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S12>/PhaseFaultCalc' */

  /* FunctionCaller: '<S1>/RP_SWC_Dem_MDF_PhaseLossFaultFail_SetEventStatus' */
  Rte_Call_RP_SWC_Dem_MDF_PhaseLossFaultFail_SetEventStatus(SWC_MDF_B.Switch1_g);

  /* FunctionCaller: '<S1>/RP_SWC_FIM_MDF_DiagPrfChkElecDt_GetFunctionPermission' */
  Rte_Call_RP_SWC_FIM_MDF_DiagPrfChkElecDt_GetFunctionPermission
    (&VAR_MDF_PrfElDrvState_u8);

  /* Logic: '<S56>/Logical Operator' incorporates:
   *  Constant: '<S56>/CAL_MDF_nDidMax_f32'
   *  Constant: '<S56>/CAL_MDF_nDidMin_f32'
   *  Constant: '<S56>/CAL_MDF_pwrDcDiaMin_f32'
   *  Constant: '<S56>/MDF_GLB_IGBTrun_u8'
   *  Constant: '<S56>/iEDS_Enum_stDrvCtl_def.Drv_OffsetAcc'
   *  Constant: '<S56>/iEDS_Enum_stDrvCtl_def.Drv_OffsetFw'
   *  Logic: '<S56>/Logical Operator1'
   *  Logic: '<S56>/Logical Operator2'
   *  RelationalOperator: '<S56>/Relational Operator'
   *  RelationalOperator: '<S56>/Relational Operator1'
   *  RelationalOperator: '<S56>/Relational Operator2'
   *  RelationalOperator: '<S56>/Relational Operator3'
   *  RelationalOperator: '<S56>/Relational Operator4'
   *  RelationalOperator: '<S56>/Relational Operator5'
   *  UnitDelay: '<S72>/Unit Delay'
   */
  VAR_MDF_bPwrCmpDFCCalc_b = ((VAR_MDF_PrfElDrvState_u8 != 0) &&
    (rtb_TmpSignalConversionAtRP_S_e == ((uint8)MDF_GLB_IGBTrun_u8)) &&
    ((Drv_OffsetAcc != rtb_DataTypeConversion1) && (rtb_DataTypeConversion1 !=
    Drv_OffsetFw)) && ((rtb_Abs >= CAL_MDF_nDidMin_f32) && (rtb_Abs <=
    CAL_MDF_nDidMax_f32)) && (SWC_MDF_DW.UnitDelay_DSTATE_j >
    CAL_MDF_pwrDcDiaMin_f32));

  /* Outputs for Enabled SubSystem: '<S13>/Pwr3PhaCmp' incorporates:
   *  EnablePort: '<S58>/Enable'
   */
  if (VAR_MDF_bPwrCmpDFCCalc_b) {
    SWC_MDF_DW.Pwr3PhaCmp_MODE = true;

    /* RelationalOperator: '<S58>/Relational Operator6' incorporates:
     *  Abs: '<S58>/Abs1'
     *  Abs: '<S58>/Abs2'
     *  Constant: '<S58>/CAL_MDF_cErrPwrDcEstMax_f32'
     *  Product: '<S58>/Product'
     *  Sum: '<S58>/Subtract'
     *  UnitDelay: '<S72>/Unit Delay'
     *  UnitDelay: '<S74>/Unit Delay'
     */
    VAR_MDF_bFaultPwrCmp_b = (fabsf(SWC_MDF_DW.UnitDelay_DSTATE_j) *
      CAL_MDF_cErrPwrDcEstMax_f32 < fabsf(SWC_MDF_DW.UnitDelay_DSTATE_j -
      SWC_MDF_DW.UnitDelay_DSTATE));

    /* Switch: '<S58>/Switch1' incorporates:
     *  Constant: '<S58>/Constant3'
     *  Constant: '<S58>/Constant4'
     */
    if (VAR_MDF_bFaultPwrCmp_b) {
      SWC_MDF_B.Switch1_k = 3U;
    } else {
      SWC_MDF_B.Switch1_k = 2U;
    }

    /* End of Switch: '<S58>/Switch1' */
  } else {
    if (SWC_MDF_DW.Pwr3PhaCmp_MODE) {
      /* Disable for Outport: '<S58>/MDF_bFaultPwrCmp' */
      VAR_MDF_bFaultPwrCmp_b = false;
      SWC_MDF_DW.Pwr3PhaCmp_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S13>/Pwr3PhaCmp' */

  /* FunctionCaller: '<S1>/RP_SWC_Dem_MDF_PrfElDrvFail_SetEventStatus' */
  Rte_Call_RP_SWC_Dem_MDF_PrfElDrvFail_SetEventStatus(SWC_MDF_B.Switch1_k);

  /* Update for UnitDelay: '<S19>/Unit Delay2' */
  SWC_MDF_DW.UnitDelay2_DSTATE_o = rtb_DataTypeConversion;

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_MDF_10ms' */

  /* Outport: '<Root>/PP_SWC_MDF_MDF_stFrwhl' */
  (void) Rte_Write_PP_SWC_MDF_MDF_stFrwhl(SWC_MDF_DW.UnitDelay_DSTATE_h);

  /* Outport: '<Root>/PP_SWC_MDF_MDF_bFaultEMBlkWarnSt' */
  (void) Rte_Write_PP_SWC_MDF_MDF_bFaultEMBlkWarnSt(SWC_MDF_B.Switch5);
}

/* Model initialize function */
void SWC_MDF_Init(void)
{
  /* SystemInitialize for Outport: '<Root>/PP_SWC_MDF_MDF_bFaultEMBlkWarnSt' */
  (void) Rte_Write_PP_SWC_MDF_MDF_bFaultEMBlkWarnSt(SWC_MDF_B.Switch5);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
