/*
 * File: SWC_BCC.c
 *
 * Code generated for Simulink model 'SWC_BCC'.
 *
 * Model version                  : 1.24
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Fri Nov  6 11:38:53 2020
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SWC_BCC.h"
#include "SWC_BCC_private.h"
#include "look1_iflf_binlxpw.h"
#include "look2_iflf_binlxpw.h"

/* Exported block signals */
float32 VAR_WTjpwr_f32;                /* '<S134>/Add' */
float32 VAR_WCoolantTj_f32;            /* '<S61>/Add10' */
float32 VAR_WihTjtIGBT_f32;            /* '<S61>/Add9' */
float32 VAR_WilTjtIGBT_f32;            /* '<S132>/Add12' */
float32 VAR_WdlTjtIGBT_f32;            /* '<S132>/Add14' */
float32 VAR_WdhTjtIGBT_f32;            /* '<S132>/Add6' */
float32 VAR_VTjpwr_f32;                /* '<S106>/Add' */
float32 VAR_VCoolantTj_f32;            /* '<S60>/Add10' */
float32 VAR_VilTjtIGBT_f32;            /* '<S60>/Add12' */
float32 VAR_VdlTjtIGBT_f32;            /* '<S60>/Add14' */
float32 VAR_VdhTjtIGBT_f32;            /* '<S60>/Add6' */
float32 VAR_VihTjtIGBT_f32;            /* '<S60>/Add9' */
float32 VAR_UTjpwr_f32;                /* '<S73>/Add' */
float32 VAR_UCoolantTj_f32;            /* '<S59>/Add10' */
float32 VAR_UilTjtIGBT_f32;            /* '<S59>/Add12' */
float32 VAR_UdlTjtIGBT_f32;            /* '<S59>/Add14' */
float32 VAR_UdhTjtIGBT_f32;            /* '<S59>/Add6' */
float32 VAR_UihTjtIGBT_f32;            /* '<S59>/Add9' */
float32 VAR_BCC_iDcLnkEst_f32;         /* '<S16>/Merge' */
float32 VAR_BCC_iDcLnkEstFlt_f32;      /* '<S51>/Sum1' */
boolean VAR_BCC_flgstGateDrv_b;        /* '<S52>/Logical Operator' */

/* Exported data definition */
#pragma section ".rodata.Calib_32"

/* Definition for custom storage class: iEDS_Parameter */
const volatile float32 CAL_BCC_AgGenCoe_f32 = 2.0F;/* Referenced by:
                                                    * '<S18>/CAL_BCC_AgGenCoe_f32'
                                                    * '<S19>/CAL_BCC_AgGenCoe_f32'
                                                    * '<S20>/CAL_BCC_AgGenCoe_f32'
                                                    * '<S21>/CAL_BCC_AgGenCoe_f32'
                                                    * '<S22>/CAL_BCC_AgGenCoe_f32'
                                                    * '<S23>/CAL_BCC_AgGenCoe_f32'
                                                    */
const volatile float32 CAL_BCC_dycLowLimt_f32 = 0.012F;/* Referenced by:
                                                        * '<S45>/CAL_BCC_dycLowLimt_f32'
                                                        * '<S46>/CAL_BCC_dycLowLimt_f32'
                                                        * '<S47>/CAL_BCC_dycLowLimt_f32'
                                                        * '<S48>/CAL_BCC_dycLowLimt_f32'
                                                        * '<S49>/CAL_BCC_dycLowLimt_f32'
                                                        * '<S50>/CAL_BCC_dycLowLimt_f32'
                                                        */
const volatile float32 CAL_BCC_dycUpLimt_f32 = 0.988F;/* Referenced by:
                                                       * '<S45>/CAL_BCC_dycUpLimt_f32'
                                                       * '<S46>/CAL_BCC_dycUpLimt_f32'
                                                       * '<S47>/CAL_BCC_dycUpLimt_f32'
                                                       * '<S48>/CAL_BCC_dycUpLimt_f32'
                                                       * '<S49>/CAL_BCC_dycUpLimt_f32'
                                                       * '<S50>/CAL_BCC_dycUpLimt_f32'
                                                       */
const volatile boolean CAL_BCC_flgDelayDyc_b = 0;/* Referenced by:
                                                  * '<S4>/CAL_BCC_flgDelayDyc_b'
                                                  * '<S16>/CAL_BCC_flgDelayDyc_b'
                                                  */
const volatile boolean CAL_BCC_flgEnableIdc_b = 0;/* Referenced by: '<S3>/Constant' */
const volatile boolean CAL_BCC_flgEnableTj_b = 1;/* Referenced by: '<S3>/Constant1' */
const volatile float32 CAL_BCC_iDcEstflt_f32 = 10.0F;
                              /* Referenced by: '<S17>/CAL_BCC_iDcEstflt_f32' */

/* 母线电压估算滤波系数 */
const volatile float32 CAL_BCC_iThetaOffsetGen_f32 = 0.56F;
                       /* Referenced by: '<S163>/CAL_BCC_iThetaOffsetGen_f32' */
const volatile float32 CAL_BCC_iThetaOffset_f32 = 0.44F;
                          /* Referenced by: '<S163>/CAL_BCC_iThetaOffset_f32' */

/* 相电流折算半个运行周期 */
const volatile float32 CAL_BCC_tiFull_f32 = 1.0F;/* Referenced by:
                                                  * '<S18>/Gain1'
                                                  * '<S18>/Gain2'
                                                  * '<S19>/Gain1'
                                                  * '<S19>/Gain2'
                                                  * '<S20>/Gain1'
                                                  * '<S20>/Gain2'
                                                  * '<S21>/Gain1'
                                                  * '<S21>/Gain2'
                                                  * '<S22>/Gain1'
                                                  * '<S22>/Gain2'
                                                  * '<S23>/Gain1'
                                                  * '<S23>/Gain2'
                                                  */
const volatile float32 CAL_CoolantFlowReq_u8 = 8.0F;/* Referenced by: '<S6>/Constant6' */
const volatile float32 CAL_TjCoolantFlowTab_af32[6] = { 0.0F, 2.0F, 4.0F, 6.0F,
  8.0F, 10.0F } ;                      /* Referenced by:
                                        * '<S6>/1-D Lookup Table'
                                        * '<S6>/1-D Lookup Table1'
                                        * '<S6>/1-D Lookup Table2'
                                        */

const volatile float32 CAL_TjDycMax_f32 = 1.0F;/* Referenced by:
                                                * '<S63>/Constant1'
                                                * '<S75>/Constant1'
                                                * '<S76>/Constant1'
                                                * '<S77>/Constant1'
                                                * '<S96>/Constant1'
                                                * '<S108>/Constant1'
                                                * '<S109>/Constant1'
                                                * '<S110>/Constant1'
                                                * '<S129>/Constant1'
                                                * '<S136>/Constant1'
                                                * '<S137>/Constant1'
                                                * '<S138>/Constant1'
                                                */
const volatile float32 CAL_TjDycMin_f32 = 0.0F;/* Referenced by:
                                                * '<S63>/Constant'
                                                * '<S75>/Constant'
                                                * '<S76>/Constant'
                                                * '<S77>/Constant'
                                                * '<S96>/Constant'
                                                * '<S108>/Constant'
                                                * '<S109>/Constant'
                                                * '<S110>/Constant'
                                                * '<S129>/Constant'
                                                * '<S136>/Constant'
                                                * '<S137>/Constant'
                                                * '<S138>/Constant'
                                                */
const volatile float32 CAL_TjLv1Act_f32 = 0.005F;/* Referenced by:
                                                  * '<S67>/Constant12'
                                                  * '<S69>/Constant12'
                                                  * '<S71>/Constant12'
                                                  * '<S72>/Constant12'
                                                  * '<S100>/Constant12'
                                                  * '<S102>/Constant12'
                                                  * '<S104>/Constant12'
                                                  * '<S105>/Constant12'
                                                  * '<S133>/Constant12'
                                                  * '<S143>/Constant12'
                                                  * '<S145>/Constant12'
                                                  * '<S147>/Constant12'
                                                  */
const volatile float32 CAL_TjLv2Act_f32 = 0.045F;/* Referenced by:
                                                  * '<S67>/Constant14'
                                                  * '<S69>/Constant14'
                                                  * '<S71>/Constant14'
                                                  * '<S72>/Constant14'
                                                  * '<S100>/Constant14'
                                                  * '<S102>/Constant14'
                                                  * '<S104>/Constant14'
                                                  * '<S105>/Constant14'
                                                  * '<S133>/Constant14'
                                                  * '<S143>/Constant14'
                                                  * '<S145>/Constant14'
                                                  * '<S147>/Constant14'
                                                  */
const volatile float32 CAL_TjLv3Act_f32 = 0.015F;/* Referenced by:
                                                  * '<S67>/Constant4'
                                                  * '<S69>/Constant4'
                                                  * '<S71>/Constant4'
                                                  * '<S72>/Constant4'
                                                  * '<S100>/Constant4'
                                                  * '<S102>/Constant4'
                                                  * '<S104>/Constant4'
                                                  * '<S105>/Constant4'
                                                  * '<S133>/Constant4'
                                                  * '<S143>/Constant4'
                                                  * '<S145>/Constant4'
                                                  * '<S147>/Constant4'
                                                  */
const volatile float32 CAL_TjLv3Pas_f32 = 0.03F;/* Referenced by:
                                                 * '<S67>/Constant20'
                                                 * '<S69>/Constant20'
                                                 * '<S71>/Constant20'
                                                 * '<S72>/Constant20'
                                                 * '<S100>/Constant20'
                                                 * '<S102>/Constant20'
                                                 * '<S104>/Constant20'
                                                 * '<S105>/Constant20'
                                                 * '<S133>/Constant20'
                                                 * '<S143>/Constant20'
                                                 * '<S145>/Constant20'
                                                 * '<S147>/Constant20'
                                                 */
const volatile float32 CAL_Tj_cofFltCoolant_f32 = 1000.0F;/* Referenced by:
                                                           * '<S59>/CAL_Tj_cofFltCoolant_f32'
                                                           * '<S60>/CAL_Tj_cofFltCoolant_f32'
                                                           * '<S61>/CAL_Tj_cofFltCoolant_f32'
                                                           */
const volatile float32 CAL_TjrthLv4DhIhTab_af32[6] = { 0.05F, 0.05F, 0.04F,
  0.03F, 0.02F, 0.02F } ;          /* Referenced by: '<S6>/1-D Lookup Table2' */

const volatile float32 CAL_TjrthLv4IhIhTab_af32[6] = { 0.096F, 0.096F, 0.086F,
  0.076F, 0.066F, 0.066F } ;        /* Referenced by: '<S6>/1-D Lookup Table' */

const volatile float32 CAL_TjrthLv4IhNtcTab_af32[6] = { 0.06F, 0.06F, 0.05F,
  0.04F, 0.03F, 0.03F } ;          /* Referenced by: '<S6>/1-D Lookup Table1' */

const volatile float32 CAL_TjrthLv4dhdh_f32 = 0.03F;/* Referenced by: '<S6>/Constant14' */
const volatile float32 CAL_TjrthLv4dhdl_f32 = 0.03F;/* Referenced by: '<S6>/Constant15' */
const volatile float32 CAL_TjrthLv4dhil_f32 = 0.03F;/* Referenced by: '<S6>/Constant13' */
const volatile float32 CAL_TjrthLv4dhntc_f32 = 0.03F;/* Referenced by: '<S6>/Constant21' */
const volatile float32 CAL_TjrthLv4dldh_f32 = 0.03F;/* Referenced by: '<S6>/Constant18' */
const volatile float32 CAL_TjrthLv4dldl_f32 = 0.03F;/* Referenced by: '<S6>/Constant19' */
const volatile float32 CAL_TjrthLv4dlih_f32 = 0.03F;/* Referenced by: '<S6>/Constant16' */
const volatile float32 CAL_TjrthLv4dlil_f32 = 0.03F;/* Referenced by: '<S6>/Constant17' */
const volatile float32 CAL_TjrthLv4dlntc_f32 = 0.016F;/* Referenced by: '<S6>/Constant23' */
const volatile float32 CAL_TjrthLv4ihdh_f32 = 0.03F;/* Referenced by: '<S6>/Constant5' */
const volatile float32 CAL_TjrthLv4ihdl_f32 = 0.03F;/* Referenced by: '<S6>/Constant7' */
const volatile float32 CAL_TjrthLv4ihil_f32 = 0.03F;/* Referenced by: '<S6>/Constant4' */
const volatile float32 CAL_TjrthLv4ildh_f32 = 0.03F;/* Referenced by: '<S6>/Constant10' */
const volatile float32 CAL_TjrthLv4ildl_f32 = 0.03F;/* Referenced by: '<S6>/Constant11' */
const volatile float32 CAL_TjrthLv4ilih_f32 = 0.03F;/* Referenced by: '<S6>/Constant8' */
const volatile float32 CAL_TjrthLv4ilil_f32 = 0.03F;/* Referenced by: '<S6>/Constant9' */
const volatile float32 CAL_TjrthLv4ilntc_f32 = 0.017F;/* Referenced by: '<S6>/Constant22' */
const volatile uint8 CAL_TjstUVW_u8 = 1U;/* Referenced by:
                                          * '<S59>/Constant7'
                                          * '<S60>/Constant7'
                                          * '<S61>/Constant7'
                                          */
const volatile float32 CAL_tiPwmLim_f32 = 0.0004F;/* Referenced by:
                                                   * '<S54>/Constant'
                                                   * '<S55>/Constant'
                                                   * '<S56>/Constant'
                                                   */

#pragma section

/* Block signals (default storage) */
B_SWC_BCC_T SWC_BCC_B;

/* Block states (default storage) */
DW_SWC_BCC_T SWC_BCC_DW;

/* Model step function for TID1 */
void SWC_BCC_100us(void)               /* Explicit Task: RE_SWC_BCC_100us */
{
  float32 rtb_TmpSignalConversionAtRP__ou;
  float32 rtb_Saturation_c;
  float32 rtb_Switch2_a;
  float32 rtb_Switch4_g;
  float32 rtb_Product3;
  float32 rtb_Product8;
  float32 rtb_TmpSignalConversionAtRP_S_h;
  float32 rtb_Product14;
  float32 rtb_TmpSignalConversionAtRP_S_d;
  float32 rtb_Product11;
  float32 rtb_TmpSignalConversionAtRP_S_l;
  float32 rtb_Product_eb;
  uint8 rtb_TmpSignalConversionAtRP__lv;
  boolean rtb_RelationalOperator2_p;
  boolean rtb_RelationalOperator3;
  boolean rtb_Switch_b;
  float32 rtb_TmpSignalConversionAtRP__ha;
  float32 rtb_TmpSignalConversionAtRP_S_g;
  float32 rtb_TmpSignalConversionAtRP_S_i;
  uint8 rtb_TmpSignalConversionAtRP_S_b;
  float32 rtb_Switch1_a;
  float32 rtb_Gain11;
  float32 rtb_Switch2_i;
  float32 rtb_Product10_l;
  float32 rtb_Product9_j;
  float32 rtb_tvdh_e;
  float32 rtb_tvdl_j;
  float32 rtb_twih_j;
  float32 rtb_twil_i;
  float32 rtb_twdh_e;
  float32 rtb_twdl_p;
  float32 rtb_iu;
  float32 rtb_iv;
  float32 rtb_TmpSignalConversionAtRP_S_e;
  float32 rtb_Switch_i;
  float32 rtb_TmpSignalConversionAtRP__br;
  uint8 rtb_TmpSignalConversionAtRP_S_p;
  float32 rtb_TmpSignalConversionAtRP_SWC;
  float32 rtb_Switch3_ma;
  float32 rtb_Switch1_d1;
  float32 rtb_Gain11_pb;
  float32 rtb_Add2_p;
  float32 rtb_Add4_n;
  float32 rtb_Gain7_k;
  float32 rtb_dycmax;
  float32 rtb_TmpSignalConversionAtRP_S_n;
  float32 rtb_Switch10_idx_0;
  float32 rtb_Switch10_idx_1;
  float32 rtb_Switch10_idx_2;
  float32 rtb_Switch10_idx_3;
  sint32 rtb_TmpSignalConversionAtRP__nd;

  /* Inport: '<Root>/RP_SWC_Rdc_Rdc_nWoFlt' */
  Rte_Read_RP_SWC_Rdc_Rdc_nWoFlt(&rtb_Switch4_g);

  /* Inport: '<Root>/RP_SWC_MCF_MCF_Is' */
  Rte_Read_RP_SWC_MCF_MCF_Is(&rtb_Saturation_c);

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_BCC_100us' incorporates:
   *  SubSystem: '<Root>/RE_SWC_BCC_100us_sys'
   */
  /* SignalConversion generated from: '<S1>/RP_SWC_HSPF_HSPF_tDBCTempUFlt_read' incorporates:
   *  Inport: '<Root>/RP_SWC_HSPF_HSPF_tDBCTempUFlt'
   */
  Rte_Read_RP_SWC_HSPF_HSPF_tDBCTempUFlt(&rtb_TmpSignalConversionAtRP_SWC);

  /* SignalConversion generated from: '<S1>/RP_SWC_HSPF_HSPF_tDBCTempVFlt_read' incorporates:
   *  Inport: '<Root>/RP_SWC_HSPF_HSPF_tDBCTempVFlt'
   */
  Rte_Read_RP_SWC_HSPF_HSPF_tDBCTempVFlt(&rtb_TmpSignalConversionAtRP_S_n);

  /* SignalConversion generated from: '<S1>/RP_SWC_HSPF_HSPF_tDBCTempWFlt_read' incorporates:
   *  Inport: '<Root>/RP_SWC_HSPF_HSPF_tDBCTempWFlt'
   */
  Rte_Read_RP_SWC_HSPF_HSPF_tDBCTempWFlt(&rtb_TmpSignalConversionAtRP__br);

  /* SignalConversion generated from: '<S1>/RP_SWC_HSPF_HSPF_uDcLnkSlowFlt_read' incorporates:
   *  Inport: '<Root>/RP_SWC_HSPF_HSPF_uDcLnkSlowFlt'
   */
  Rte_Read_RP_SWC_HSPF_HSPF_uDcLnkSlowFlt(&rtb_TmpSignalConversionAtRP_S_e);

  /* SignalConversion generated from: '<S1>/RP_SWC_MCF_MCF_DycU_read' incorporates:
   *  Inport: '<Root>/RP_SWC_MCF_MCF_DycU'
   */
  Rte_Read_RP_SWC_MCF_MCF_DycU(&rtb_TmpSignalConversionAtRP__ha);

  /* SignalConversion generated from: '<S1>/RP_SWC_MCF_MCF_DycV_read' incorporates:
   *  Inport: '<Root>/RP_SWC_MCF_MCF_DycV'
   */
  Rte_Read_RP_SWC_MCF_MCF_DycV(&rtb_TmpSignalConversionAtRP_S_g);

  /* SignalConversion generated from: '<S1>/RP_SWC_MCF_MCF_DycW_read' incorporates:
   *  Inport: '<Root>/RP_SWC_MCF_MCF_DycW'
   */
  Rte_Read_RP_SWC_MCF_MCF_DycW(&rtb_TmpSignalConversionAtRP_S_i);

  /* SignalConversion generated from: '<S1>/RP_SWC_MCF_MCF_frqPwm_read' incorporates:
   *  Inport: '<Root>/RP_SWC_MCF_MCF_frqPwm'
   */
  Rte_Read_RP_SWC_MCF_MCF_frqPwm(&rtb_TmpSignalConversionAtRP_S_l);

  /* SignalConversion generated from: '<S1>/RP_SWC_MCF_MCF_secVolt_read' incorporates:
   *  Inport: '<Root>/RP_SWC_MCF_MCF_secVolt'
   */
  Rte_Read_RP_SWC_MCF_MCF_secVolt(&rtb_TmpSignalConversionAtRP_S_p);

  /* Saturate: '<S164>/Saturation' */
  if (rtb_Saturation_c > 1000.0F) {
    rtb_Saturation_c = 1000.0F;
  } else {
    if (rtb_Saturation_c < 0.001F) {
      rtb_Saturation_c = 0.001F;
    }
  }

  /* End of Saturate: '<S164>/Saturation' */

  /* SignalConversion generated from: '<S1>/RP_SWC_MCF_MCF_iU_read' incorporates:
   *  Inport: '<Root>/RP_SWC_MCF_MCF_iU'
   */
  Rte_Read_RP_SWC_MCF_MCF_iU(&rtb_TmpSignalConversionAtRP__ou);

  /* Product: '<S164>/Divide' */
  rtb_Switch2_a = rtb_TmpSignalConversionAtRP__ou / rtb_Saturation_c;

  /* Saturate: '<S164>/Saturation3' */
  if (rtb_Switch2_a > 1.0F) {
    rtb_Switch2_a = 1.0F;
  } else {
    if (rtb_Switch2_a < -1.0F) {
      rtb_Switch2_a = -1.0F;
    }
  }

  /* End of Saturate: '<S164>/Saturation3' */

  /* SignalConversion generated from: '<S1>/RP_SWC_TPC_TPC_stMotorMod_read' incorporates:
   *  Inport: '<Root>/RP_SWC_TPC_TPC_stMotorMod'
   */
  Rte_Read_RP_SWC_TPC_TPC_stMotorMod(&rtb_TmpSignalConversionAtRP__lv);

  /* Switch: '<S7>/Switch' incorporates:
   *  Constant: '<S7>/Q2'
   *  Constant: '<S7>/Q4'
   *  Logic: '<S7>/Logical Operator'
   *  RelationalOperator: '<S7>/Relational Operator'
   *  RelationalOperator: '<S7>/Relational Operator1'
   */
  rtb_Switch_b = ((rtb_TmpSignalConversionAtRP__lv == 2) ||
                  (rtb_TmpSignalConversionAtRP__lv == 4));

  /* Saturate: '<S163>/Saturation' */
  if (rtb_TmpSignalConversionAtRP_S_l > 20000.0F) {
    rtb_Product3 = 20000.0F;
  } else if (rtb_TmpSignalConversionAtRP_S_l < 0.01F) {
    rtb_Product3 = 0.01F;
  } else {
    rtb_Product3 = rtb_TmpSignalConversionAtRP_S_l;
  }

  /* End of Saturate: '<S163>/Saturation' */

  /* Switch: '<S163>/Switch' incorporates:
   *  Constant: '<S163>/CAL_BCC_iThetaOffsetGen_f32'
   *  Constant: '<S163>/CAL_BCC_iThetaOffset_f32'
   */
  if (rtb_Switch_b) {
    rtb_tvdh_e = CAL_BCC_iThetaOffsetGen_f32;
  } else {
    rtb_tvdh_e = CAL_BCC_iThetaOffset_f32;
  }

  /* End of Switch: '<S163>/Switch' */

  /* Product: '<S163>/Product3' incorporates:
   *  Constant: '<S163>/CAL_BCC_CircAge_f32'
   *  Constant: '<S163>/Constant1'
   *  Constant: '<S163>/Constant2'
   *  Product: '<S163>/Divide'
   *  Product: '<S163>/Product'
   *  Product: '<S163>/Product1'
   */
  rtb_Product3 = rtb_Switch4_g * 0.0666F * CAL_BCC_CircAge_f32 * (1.0F /
    rtb_Product3 * rtb_tvdh_e);

  /* RelationalOperator: '<S165>/Relational Operator2' incorporates:
   *  Constant: '<S165>/CAL_BCC_CircAge_f32'
   */
  rtb_RelationalOperator2_p = (rtb_Product3 >= CAL_BCC_CircAge_f32);

  /* RelationalOperator: '<S165>/Relational Operator3' incorporates:
   *  Constant: '<S165>/Constant2'
   */
  rtb_RelationalOperator3 = (rtb_Product3 > 0.0F);

  /* Switch: '<S165>/Switch2' incorporates:
   *  Constant: '<S165>/CAL_BCC_CircAge_f32'
   *  Sum: '<S165>/Add1'
   *  Sum: '<S165>/Add4'
   *  Switch: '<S165>/Switch3'
   */
  if (rtb_RelationalOperator2_p) {
    rtb_Switch4_g = rtb_Product3 - CAL_BCC_CircAge_f32;
  } else if (rtb_RelationalOperator3) {
    /* Switch: '<S165>/Switch3' */
    rtb_Switch4_g = rtb_Product3;
  } else {
    rtb_Switch4_g = rtb_Product3 + CAL_BCC_CircAge_f32;
  }

  /* End of Switch: '<S165>/Switch2' */

  /* LookupNDDirect: '<S165>/Direct Lookup Table (n-D)1' incorporates:
   *  Constant: '<S165>/Constant1'
   *  Product: '<S165>/Product1'
   *
   * About '<S165>/Direct Lookup Table (n-D)1':
   *  1-dimensional Direct Look-Up returning a Scalar,
   *
   *     Remove protection against out-of-range input in generated code: 'off'
   */
  rtb_tvdh_e = rtb_Switch4_g * 11.375F;
  if (rtb_tvdh_e > 4095.0F) {
    rtb_tvdh_e = 4095.0F;
  } else {
    if (rtb_tvdh_e < 0.0F) {
      rtb_tvdh_e = 0.0F;
    }
  }

  rtb_Switch4_g = rtCP_DirectLookupTablenD1_table[(sint32)rtb_tvdh_e];

  /* End of LookupNDDirect: '<S165>/Direct Lookup Table (n-D)1' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_BCC_100us' */

  /* Inport: '<Root>/RP_SWC_MPC_MPC_dtCorFac' */
  Rte_Read_RP_SWC_MPC_MPC_dtCorFac(&rtb_Product_eb);

  /* Inport: '<Root>/RP_SWC_MCF_MCF_tiLock' */
  Rte_Read_RP_SWC_MCF_MCF_tiLock(&rtb_dycmax);

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_BCC_100us' incorporates:
   *  SubSystem: '<Root>/RE_SWC_BCC_100us_sys'
   */
  /* Switch: '<S165>/Switch' incorporates:
   *  Constant: '<S165>/CAL_BCC_CircAge_f32'
   *  Sum: '<S165>/Add2'
   *  Sum: '<S165>/Add3'
   *  Switch: '<S165>/Switch1'
   */
  if (rtb_RelationalOperator2_p) {
    rtb_Product3 -= CAL_BCC_CircAge_f32;
  } else {
    if (!rtb_RelationalOperator3) {
      rtb_Product3 += CAL_BCC_CircAge_f32;
    }
  }

  /* End of Switch: '<S165>/Switch' */

  /* LookupNDDirect: '<S165>/Direct Lookup Table (n-D)' incorporates:
   *  Constant: '<S165>/Constant'
   *  Product: '<S165>/Product'
   *
   * About '<S165>/Direct Lookup Table (n-D)':
   *  1-dimensional Direct Look-Up returning a Scalar,
   *
   *     Remove protection against out-of-range input in generated code: 'off'
   */
  rtb_tvdh_e = rtb_Product3 * 11.375F;
  if (rtb_tvdh_e > 4095.0F) {
    rtb_tvdh_e = 4095.0F;
  } else {
    if (rtb_tvdh_e < 0.0F) {
      rtb_tvdh_e = 0.0F;
    }
  }

  rtb_Product3 = rtCP_DirectLookupTablenD_table[(sint32)rtb_tvdh_e];

  /* End of LookupNDDirect: '<S165>/Direct Lookup Table (n-D)' */

  /* SignalConversion generated from: '<S1>/RP_SWC_MCF_MCF_iV_read' incorporates:
   *  Inport: '<Root>/RP_SWC_MCF_MCF_iV'
   */
  Rte_Read_RP_SWC_MCF_MCF_iV(&rtb_TmpSignalConversionAtRP_S_h);

  /* SignalConversion generated from: '<S1>/RP_SWC_MCF_MCF_iW_read' incorporates:
   *  Inport: '<Root>/RP_SWC_MCF_MCF_iW'
   */
  Rte_Read_RP_SWC_MCF_MCF_iW(&rtb_TmpSignalConversionAtRP_S_d);

  /* Switch: '<S164>/Switch' incorporates:
   *  Constant: '<S164>/Constant1'
   *  Constant: '<S164>/Constant2'
   *  RelationalOperator: '<S164>/Relational Operator'
   */
  if (rtb_TmpSignalConversionAtRP_S_d >= rtb_TmpSignalConversionAtRP_S_h) {
    rtb_TmpSignalConversionAtRP__nd = 1;
  } else {
    rtb_TmpSignalConversionAtRP__nd = -1;
  }

  /* End of Switch: '<S164>/Switch' */

  /* Product: '<S164>/Product8' incorporates:
   *  Constant: '<S164>/Constant'
   *  Product: '<S164>/Product'
   *  Product: '<S164>/Product1'
   *  Product: '<S164>/Product6'
   *  Product: '<S164>/Product7'
   *  Sqrt: '<S164>/Sqrt'
   *  Sum: '<S164>/Add'
   *  Sum: '<S164>/Add3'
   */
  rtb_Product8 = (sqrtf(1.0F - rtb_Switch2_a * rtb_Switch2_a) * (float32)
                  rtb_TmpSignalConversionAtRP__nd * rtb_Product3 + rtb_Switch2_a
                  * rtb_Switch4_g) * rtb_Saturation_c;

  /* Product: '<S164>/Divide1' */
  rtb_Switch2_a = rtb_TmpSignalConversionAtRP_S_h / rtb_Saturation_c;

  /* Saturate: '<S164>/Saturation1' */
  if (rtb_Switch2_a > 1.0F) {
    rtb_Switch2_a = 1.0F;
  } else {
    if (rtb_Switch2_a < -1.0F) {
      rtb_Switch2_a = -1.0F;
    }
  }

  /* End of Saturate: '<S164>/Saturation1' */

  /* Switch: '<S164>/Switch2' incorporates:
   *  Constant: '<S164>/Constant5'
   *  Constant: '<S164>/Constant6'
   *  RelationalOperator: '<S164>/Relational Operator1'
   */
  if (rtb_TmpSignalConversionAtRP__ou >= rtb_TmpSignalConversionAtRP_S_d) {
    rtb_TmpSignalConversionAtRP__nd = 1;
  } else {
    rtb_TmpSignalConversionAtRP__nd = -1;
  }

  /* End of Switch: '<S164>/Switch2' */

  /* Product: '<S164>/Product14' incorporates:
   *  Constant: '<S164>/Constant4'
   *  Product: '<S164>/Product12'
   *  Product: '<S164>/Product13'
   *  Product: '<S164>/Product2'
   *  Product: '<S164>/Product3'
   *  Sqrt: '<S164>/Sqrt1'
   *  Sum: '<S164>/Add1'
   *  Sum: '<S164>/Add5'
   */
  rtb_Product14 = (sqrtf(1.0F - rtb_Switch2_a * rtb_Switch2_a) * (float32)
                   rtb_TmpSignalConversionAtRP__nd * rtb_Product3 +
                   rtb_Switch2_a * rtb_Switch4_g) * rtb_Saturation_c;

  /* Product: '<S164>/Divide2' */
  rtb_Switch2_a = rtb_TmpSignalConversionAtRP_S_d / rtb_Saturation_c;

  /* Saturate: '<S164>/Saturation2' */
  if (rtb_Switch2_a > 1.0F) {
    rtb_Switch2_a = 1.0F;
  } else {
    if (rtb_Switch2_a < -1.0F) {
      rtb_Switch2_a = -1.0F;
    }
  }

  /* End of Saturate: '<S164>/Saturation2' */

  /* Switch: '<S164>/Switch4' incorporates:
   *  Constant: '<S164>/Constant10'
   *  Constant: '<S164>/Constant9'
   *  RelationalOperator: '<S164>/Relational Operator2'
   */
  if (rtb_TmpSignalConversionAtRP_S_h >= rtb_TmpSignalConversionAtRP__ou) {
    rtb_TmpSignalConversionAtRP__nd = 1;
  } else {
    rtb_TmpSignalConversionAtRP__nd = -1;
  }

  /* End of Switch: '<S164>/Switch4' */

  /* Product: '<S164>/Product11' incorporates:
   *  Constant: '<S164>/Constant8'
   *  Product: '<S164>/Product10'
   *  Product: '<S164>/Product4'
   *  Product: '<S164>/Product5'
   *  Product: '<S164>/Product9'
   *  Sqrt: '<S164>/Sqrt2'
   *  Sum: '<S164>/Add2'
   *  Sum: '<S164>/Add4'
   */
  rtb_Product11 = (sqrtf(1.0F - rtb_Switch2_a * rtb_Switch2_a) * (float32)
                   rtb_TmpSignalConversionAtRP__nd * rtb_Product3 +
                   rtb_Switch2_a * rtb_Switch4_g) * rtb_Saturation_c;

  /* SignalConversion generated from: '<S1>/RP_SWC_SCF_SCF_stGateDrv_read' incorporates:
   *  Inport: '<Root>/RP_SWC_SCF_SCF_stGateDrv'
   */
  Rte_Read_RP_SWC_SCF_SCF_stGateDrv(&rtb_TmpSignalConversionAtRP_S_b);

  /* Switch: '<S4>/Switch' incorporates:
   *  Constant: '<S4>/CAL_BCC_flgDelayDyc_b'
   *  Switch: '<S4>/Switch1'
   *  Switch: '<S4>/Switch2'
   */
  if (!CAL_BCC_flgDelayDyc_b) {
    SWC_BCC_DW.UnitDelay_DSTATE = rtb_TmpSignalConversionAtRP__ha;
    SWC_BCC_DW.UnitDelay1_DSTATE = rtb_TmpSignalConversionAtRP_S_g;
    SWC_BCC_DW.UnitDelay2_DSTATE = rtb_TmpSignalConversionAtRP_S_i;
  }

  /* End of Switch: '<S4>/Switch' */

  /* Product: '<S9>/Product' incorporates:
   *  Constant: '<S9>/1stran1us'
   *  Sum: '<S9>/Subtract'
   */
  rtb_Product_eb = rtb_TmpSignalConversionAtRP_S_l * 1.0E-6F * (rtb_dycmax -
    rtb_Product_eb);

  /* Outputs for Enabled SubSystem: '<S3>/Idc_Calc' incorporates:
   *  EnablePort: '<S5>/Enable'
   */
  /* Constant: '<S3>/Constant' */
  if (CAL_BCC_flgEnableIdc_b) {
    /* Switch: '<S16>/Switch' incorporates:
     *  Constant: '<S16>/CAL_BCC_flgDelayDyc_b'
     */
    if (!CAL_BCC_flgDelayDyc_b) {
      SWC_BCC_DW.UnitDelay_DSTATE_ay = rtb_TmpSignalConversionAtRP_S_p;
    }

    /* End of Switch: '<S16>/Switch' */

    /* SwitchCase: '<S16>/Switch Case' */
    switch (SWC_BCC_DW.UnitDelay_DSTATE_ay) {
     case 1:
      /* Outputs for IfAction SubSystem: '<S16>/Case1' incorporates:
       *  ActionPort: '<S18>/Action Port'
       */
      /* Switch: '<S18>/Switch10' incorporates:
       *  Constant: '<S18>/Constant1'
       *  Constant: '<S27>/Constant'
       *  Gain: '<S18>/Gain3'
       *  RelationalOperator: '<S27>/Compare'
       */
      if (rtb_Product14 >= 0.0F) {
        rtb_TmpSignalConversionAtRP__ou = 2.0F * rtb_Product_eb;
      } else {
        rtb_TmpSignalConversionAtRP__ou = 0.0F;
      }

      /* End of Switch: '<S18>/Switch10' */

      /* Switch: '<S18>/Switch' incorporates:
       *  Constant: '<S45>/CAL_BCC_dycUpLimt_f32'
       *  Gain: '<S18>/Gain16'
       *  Gain: '<S18>/Gain2'
       *  RelationalOperator: '<S45>/Relational Operator'
       *  Switch: '<S18>/Switch11'
       */
      if (SWC_BCC_DW.UnitDelay_DSTATE >= CAL_BCC_dycUpLimt_f32) {
        rtb_dycmax = CAL_BCC_tiFull_f32 * rtb_Product_eb;
      } else if (rtb_Switch_b) {
        /* Switch: '<S18>/Switch11' incorporates:
         *  Constant: '<S18>/Constant2'
         */
        rtb_dycmax = 0.0F;
      } else {
        rtb_dycmax = 2.0F * rtb_Product_eb;
      }

      /* End of Switch: '<S18>/Switch' */

      /* Switch: '<S18>/Switch12' incorporates:
       *  Constant: '<S18>/Constant3'
       *  Constant: '<S28>/Constant'
       *  Gain: '<S18>/Gain18'
       *  RelationalOperator: '<S28>/Compare'
       */
      if (rtb_Product14 >= 0.0F) {
        rtb_TmpSignalConversionAtRP_S_h = 0.0F;
      } else {
        rtb_TmpSignalConversionAtRP_S_h = 2.0F * rtb_Product_eb;
      }

      /* End of Switch: '<S18>/Switch12' */

      /* Switch: '<S18>/Switch1' incorporates:
       *  Constant: '<S26>/Constant'
       *  Constant: '<S45>/CAL_BCC_dycLowLimt_f32'
       *  Gain: '<S18>/Gain1'
       *  Gain: '<S18>/Gain5'
       *  Logic: '<S18>/Logical Operator3'
       *  RelationalOperator: '<S26>/Compare'
       *  RelationalOperator: '<S45>/Relational Operator1'
       *  Switch: '<S18>/Switch2'
       *  Switch: '<S18>/Switch4'
       */
      if (SWC_BCC_DW.UnitDelay2_DSTATE <= CAL_BCC_dycLowLimt_f32) {
        rtb_Saturation_c = CAL_BCC_tiFull_f32 * rtb_Product_eb;
      } else if (rtb_Switch_b) {
        /* Switch: '<S18>/Switch3' incorporates:
         *  Constant: '<S18>/CAL_BCC_AgGenCoe_f32'
         *  Constant: '<S18>/Constant5'
         *  Constant: '<S26>/Constant'
         *  Product: '<S18>/Product'
         *  RelationalOperator: '<S26>/Compare'
         *  Switch: '<S18>/Switch4'
         */
        if (rtb_Product11 <= 0.0F) {
          rtb_Saturation_c = rtb_Product_eb * CAL_BCC_AgGenCoe_f32;
        } else {
          rtb_Saturation_c = 0.0F;
        }

        /* End of Switch: '<S18>/Switch3' */
      } else if (rtb_Product11 > 0.0F) {
        /* Switch: '<S18>/Switch2' incorporates:
         *  Constant: '<S18>/Constant4'
         *  Switch: '<S18>/Switch4'
         */
        rtb_Saturation_c = 0.0F;
      } else {
        rtb_Saturation_c = 2.0F * rtb_Product_eb;
      }

      /* End of Switch: '<S18>/Switch1' */

      /* Sum: '<S18>/Add19' incorporates:
       *  Gain: '<S18>/Gain17'
       *  Product: '<S18>/Product11'
       *  Product: '<S18>/Product12'
       *  Sum: '<S10>/Add1'
       *  Sum: '<S13>/Add1'
       *  Sum: '<S18>/Add15'
       *  Sum: '<S18>/Add16'
       *  Sum: '<S18>/Add17'
       *  Sum: '<S18>/Add18'
       */
      VAR_BCC_iDcLnkEst_f32 = (((SWC_BCC_DW.UnitDelay_DSTATE -
        SWC_BCC_DW.UnitDelay1_DSTATE) + rtb_TmpSignalConversionAtRP__ou) -
        rtb_dycmax) * rtb_Product8 + (((SWC_BCC_DW.UnitDelay1_DSTATE -
        SWC_BCC_DW.UnitDelay2_DSTATE) + rtb_TmpSignalConversionAtRP_S_h) -
        rtb_Saturation_c) * -rtb_Product11;

      /* End of Outputs for SubSystem: '<S16>/Case1' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S16>/Case2' incorporates:
       *  ActionPort: '<S19>/Action Port'
       */
      /* Switch: '<S19>/Switch13' incorporates:
       *  Constant: '<S19>/Constant4'
       *  Constant: '<S30>/Constant'
       *  Gain: '<S19>/Gain23'
       *  RelationalOperator: '<S30>/Compare'
       */
      if (rtb_Product8 >= 0.0F) {
        rtb_dycmax = 2.0F * rtb_Product_eb;
      } else {
        rtb_dycmax = 0.0F;
      }

      /* End of Switch: '<S19>/Switch13' */

      /* Switch: '<S19>/Switch' incorporates:
       *  Constant: '<S29>/Constant'
       *  Constant: '<S46>/CAL_BCC_dycUpLimt_f32'
       *  Gain: '<S19>/Gain2'
       *  Gain: '<S19>/Gain5'
       *  Logic: '<S19>/Logical Operator3'
       *  RelationalOperator: '<S29>/Compare'
       *  RelationalOperator: '<S46>/Relational Operator'
       *  Switch: '<S19>/Switch2'
       *  Switch: '<S19>/Switch4'
       */
      if (SWC_BCC_DW.UnitDelay1_DSTATE >= CAL_BCC_dycUpLimt_f32) {
        rtb_TmpSignalConversionAtRP__ou = CAL_BCC_tiFull_f32 * rtb_Product_eb;
      } else if (rtb_Switch_b) {
        /* Switch: '<S19>/Switch3' incorporates:
         *  Constant: '<S19>/CAL_BCC_AgGenCoe_f32'
         *  Constant: '<S19>/Constant2'
         *  Constant: '<S29>/Constant'
         *  Product: '<S19>/Product'
         *  RelationalOperator: '<S29>/Compare'
         *  Switch: '<S19>/Switch4'
         */
        if (rtb_Product14 >= 0.0F) {
          rtb_TmpSignalConversionAtRP__ou = rtb_Product_eb *
            CAL_BCC_AgGenCoe_f32;
        } else {
          rtb_TmpSignalConversionAtRP__ou = 0.0F;
        }

        /* End of Switch: '<S19>/Switch3' */
      } else if (rtb_Product14 < 0.0F) {
        /* Switch: '<S19>/Switch2' incorporates:
         *  Constant: '<S19>/Constant1'
         *  Switch: '<S19>/Switch4'
         */
        rtb_TmpSignalConversionAtRP__ou = 0.0F;
      } else {
        rtb_TmpSignalConversionAtRP__ou = 2.0F * rtb_Product_eb;
      }

      /* End of Switch: '<S19>/Switch' */

      /* Switch: '<S19>/Switch15' incorporates:
       *  Constant: '<S19>/Constant6'
       *  Constant: '<S31>/Constant'
       *  Gain: '<S19>/Gain22'
       *  RelationalOperator: '<S31>/Compare'
       */
      if (rtb_Product8 >= 0.0F) {
        rtb_TmpSignalConversionAtRP_S_h = 0.0F;
      } else {
        rtb_TmpSignalConversionAtRP_S_h = 2.0F * rtb_Product_eb;
      }

      /* End of Switch: '<S19>/Switch15' */

      /* Switch: '<S19>/Switch1' incorporates:
       *  Constant: '<S46>/CAL_BCC_dycLowLimt_f32'
       *  Gain: '<S19>/Gain1'
       *  Gain: '<S19>/Gain20'
       *  RelationalOperator: '<S46>/Relational Operator1'
       *  Switch: '<S19>/Switch14'
       */
      if (SWC_BCC_DW.UnitDelay2_DSTATE <= CAL_BCC_dycLowLimt_f32) {
        rtb_Saturation_c = CAL_BCC_tiFull_f32 * rtb_Product_eb;
      } else if (rtb_Switch_b) {
        /* Switch: '<S19>/Switch14' incorporates:
         *  Constant: '<S19>/Constant5'
         */
        rtb_Saturation_c = 0.0F;
      } else {
        rtb_Saturation_c = 2.0F * rtb_Product_eb;
      }

      /* End of Switch: '<S19>/Switch1' */

      /* Sum: '<S19>/Add24' incorporates:
       *  Gain: '<S19>/Gain21'
       *  Product: '<S19>/Product13'
       *  Product: '<S19>/Product14'
       *  Sum: '<S11>/Add1'
       *  Sum: '<S12>/Add1'
       *  Sum: '<S19>/Add20'
       *  Sum: '<S19>/Add21'
       *  Sum: '<S19>/Add22'
       *  Sum: '<S19>/Add23'
       */
      VAR_BCC_iDcLnkEst_f32 = (((SWC_BCC_DW.UnitDelay1_DSTATE -
        SWC_BCC_DW.UnitDelay_DSTATE) + rtb_dycmax) -
        rtb_TmpSignalConversionAtRP__ou) * rtb_Product14 +
        (((SWC_BCC_DW.UnitDelay_DSTATE - SWC_BCC_DW.UnitDelay2_DSTATE) +
          rtb_TmpSignalConversionAtRP_S_h) - rtb_Saturation_c) * -rtb_Product11;

      /* End of Outputs for SubSystem: '<S16>/Case2' */
      break;

     case 3:
      /* Outputs for IfAction SubSystem: '<S16>/Case3' incorporates:
       *  ActionPort: '<S20>/Action Port'
       */
      /* Switch: '<S20>/Switch13' incorporates:
       *  Constant: '<S20>/Constant4'
       *  Constant: '<S33>/Constant'
       *  Gain: '<S20>/Gain23'
       *  RelationalOperator: '<S33>/Compare'
       */
      if (rtb_Product11 >= 0.0F) {
        rtb_Saturation_c = 2.0F * rtb_Product_eb;
      } else {
        rtb_Saturation_c = 0.0F;
      }

      /* End of Switch: '<S20>/Switch13' */

      /* Switch: '<S20>/Switch1' incorporates:
       *  Constant: '<S47>/CAL_BCC_dycUpLimt_f32'
       *  Gain: '<S20>/Gain2'
       *  Gain: '<S20>/Gain20'
       *  RelationalOperator: '<S47>/Relational Operator'
       *  Switch: '<S20>/Switch14'
       */
      if (SWC_BCC_DW.UnitDelay1_DSTATE >= CAL_BCC_dycUpLimt_f32) {
        rtb_TmpSignalConversionAtRP__ou = CAL_BCC_tiFull_f32 * rtb_Product_eb;
      } else if (rtb_Switch_b) {
        /* Switch: '<S20>/Switch14' incorporates:
         *  Constant: '<S20>/Constant5'
         */
        rtb_TmpSignalConversionAtRP__ou = 0.0F;
      } else {
        rtb_TmpSignalConversionAtRP__ou = 2.0F * rtb_Product_eb;
      }

      /* End of Switch: '<S20>/Switch1' */

      /* Switch: '<S20>/Switch15' incorporates:
       *  Constant: '<S20>/Constant6'
       *  Constant: '<S34>/Constant'
       *  Gain: '<S20>/Gain22'
       *  RelationalOperator: '<S34>/Compare'
       */
      if (rtb_Product11 >= 0.0F) {
        rtb_TmpSignalConversionAtRP_S_h = 0.0F;
      } else {
        rtb_TmpSignalConversionAtRP_S_h = 2.0F * rtb_Product_eb;
      }

      /* End of Switch: '<S20>/Switch15' */

      /* Switch: '<S20>/Switch2' incorporates:
       *  Constant: '<S32>/Constant'
       *  Constant: '<S47>/CAL_BCC_dycLowLimt_f32'
       *  Gain: '<S20>/Gain1'
       *  Gain: '<S20>/Gain5'
       *  Logic: '<S20>/Logical Operator3'
       *  RelationalOperator: '<S32>/Compare'
       *  RelationalOperator: '<S47>/Relational Operator1'
       *  Switch: '<S20>/Switch3'
       *  Switch: '<S20>/Switch5'
       */
      if (SWC_BCC_DW.UnitDelay_DSTATE <= CAL_BCC_dycLowLimt_f32) {
        rtb_dycmax = CAL_BCC_tiFull_f32 * rtb_Product_eb;
      } else if (rtb_Switch_b) {
        /* Switch: '<S20>/Switch4' incorporates:
         *  Constant: '<S20>/CAL_BCC_AgGenCoe_f32'
         *  Constant: '<S20>/Constant2'
         *  Constant: '<S32>/Constant'
         *  Product: '<S20>/Product'
         *  RelationalOperator: '<S32>/Compare'
         *  Switch: '<S20>/Switch5'
         */
        if (rtb_Product8 <= 0.0F) {
          rtb_dycmax = rtb_Product_eb * CAL_BCC_AgGenCoe_f32;
        } else {
          rtb_dycmax = 0.0F;
        }

        /* End of Switch: '<S20>/Switch4' */
      } else if (rtb_Product8 > 0.0F) {
        /* Switch: '<S20>/Switch3' incorporates:
         *  Constant: '<S20>/Constant1'
         *  Switch: '<S20>/Switch5'
         */
        rtb_dycmax = 0.0F;
      } else {
        rtb_dycmax = 2.0F * rtb_Product_eb;
      }

      /* End of Switch: '<S20>/Switch2' */

      /* Sum: '<S20>/Add24' incorporates:
       *  Gain: '<S20>/Gain21'
       *  Product: '<S20>/Product13'
       *  Product: '<S20>/Product14'
       *  Sum: '<S13>/Add1'
       *  Sum: '<S14>/Add1'
       *  Sum: '<S20>/Add20'
       *  Sum: '<S20>/Add21'
       *  Sum: '<S20>/Add22'
       *  Sum: '<S20>/Add23'
       */
      VAR_BCC_iDcLnkEst_f32 = (((SWC_BCC_DW.UnitDelay1_DSTATE -
        SWC_BCC_DW.UnitDelay2_DSTATE) + rtb_Saturation_c) -
        rtb_TmpSignalConversionAtRP__ou) * rtb_Product14 +
        (((SWC_BCC_DW.UnitDelay2_DSTATE - SWC_BCC_DW.UnitDelay_DSTATE) +
          rtb_TmpSignalConversionAtRP_S_h) - rtb_dycmax) * -rtb_Product8;

      /* End of Outputs for SubSystem: '<S16>/Case3' */
      break;

     case 4:
      /* Outputs for IfAction SubSystem: '<S16>/Case4' incorporates:
       *  ActionPort: '<S21>/Action Port'
       */
      /* Switch: '<S21>/Switch13' incorporates:
       *  Constant: '<S21>/Constant4'
       *  Constant: '<S36>/Constant'
       *  Gain: '<S21>/Gain23'
       *  RelationalOperator: '<S36>/Compare'
       */
      if (rtb_Product14 >= 0.0F) {
        rtb_TmpSignalConversionAtRP__ou = 2.0F * rtb_Product_eb;
      } else {
        rtb_TmpSignalConversionAtRP__ou = 0.0F;
      }

      /* End of Switch: '<S21>/Switch13' */

      /* Switch: '<S21>/Switch1' incorporates:
       *  Constant: '<S35>/Constant'
       *  Constant: '<S48>/CAL_BCC_dycUpLimt_f32'
       *  Gain: '<S21>/Gain2'
       *  Gain: '<S21>/Gain5'
       *  Logic: '<S21>/Logical Operator3'
       *  RelationalOperator: '<S35>/Compare'
       *  RelationalOperator: '<S48>/Relational Operator'
       *  Switch: '<S21>/Switch3'
       *  Switch: '<S21>/Switch5'
       */
      if (SWC_BCC_DW.UnitDelay2_DSTATE >= CAL_BCC_dycUpLimt_f32) {
        rtb_Saturation_c = CAL_BCC_tiFull_f32 * rtb_Product_eb;
      } else if (rtb_Switch_b) {
        /* Switch: '<S21>/Switch4' incorporates:
         *  Constant: '<S21>/CAL_BCC_AgGenCoe_f32'
         *  Constant: '<S21>/Constant2'
         *  Constant: '<S35>/Constant'
         *  Product: '<S21>/Product'
         *  RelationalOperator: '<S35>/Compare'
         *  Switch: '<S21>/Switch5'
         */
        if (rtb_Product11 >= 0.0F) {
          rtb_Saturation_c = rtb_Product_eb * CAL_BCC_AgGenCoe_f32;
        } else {
          rtb_Saturation_c = 0.0F;
        }

        /* End of Switch: '<S21>/Switch4' */
      } else if (rtb_Product11 < 0.0F) {
        /* Switch: '<S21>/Switch3' incorporates:
         *  Constant: '<S21>/Constant1'
         *  Switch: '<S21>/Switch5'
         */
        rtb_Saturation_c = 0.0F;
      } else {
        rtb_Saturation_c = 2.0F * rtb_Product_eb;
      }

      /* End of Switch: '<S21>/Switch1' */

      /* Switch: '<S21>/Switch15' incorporates:
       *  Constant: '<S21>/Constant6'
       *  Constant: '<S37>/Constant'
       *  Gain: '<S21>/Gain22'
       *  RelationalOperator: '<S37>/Compare'
       */
      if (rtb_Product14 >= 0.0F) {
        rtb_TmpSignalConversionAtRP_S_h = 0.0F;
      } else {
        rtb_TmpSignalConversionAtRP_S_h = 2.0F * rtb_Product_eb;
      }

      /* End of Switch: '<S21>/Switch15' */

      /* Switch: '<S21>/Switch2' incorporates:
       *  Constant: '<S48>/CAL_BCC_dycLowLimt_f32'
       *  Gain: '<S21>/Gain1'
       *  Gain: '<S21>/Gain20'
       *  RelationalOperator: '<S48>/Relational Operator1'
       *  Switch: '<S21>/Switch14'
       */
      if (SWC_BCC_DW.UnitDelay_DSTATE <= CAL_BCC_dycLowLimt_f32) {
        rtb_dycmax = CAL_BCC_tiFull_f32 * rtb_Product_eb;
      } else if (rtb_Switch_b) {
        /* Switch: '<S21>/Switch14' incorporates:
         *  Constant: '<S21>/Constant5'
         */
        rtb_dycmax = 0.0F;
      } else {
        rtb_dycmax = 2.0F * rtb_Product_eb;
      }

      /* End of Switch: '<S21>/Switch2' */

      /* Sum: '<S21>/Add24' incorporates:
       *  Gain: '<S21>/Gain21'
       *  Product: '<S21>/Product13'
       *  Product: '<S21>/Product14'
       *  Sum: '<S12>/Add1'
       *  Sum: '<S15>/Add1'
       *  Sum: '<S21>/Add20'
       *  Sum: '<S21>/Add21'
       *  Sum: '<S21>/Add22'
       *  Sum: '<S21>/Add23'
       */
      VAR_BCC_iDcLnkEst_f32 = (((SWC_BCC_DW.UnitDelay2_DSTATE -
        SWC_BCC_DW.UnitDelay1_DSTATE) + rtb_TmpSignalConversionAtRP__ou) -
        rtb_Saturation_c) * rtb_Product11 + (((SWC_BCC_DW.UnitDelay1_DSTATE -
        SWC_BCC_DW.UnitDelay_DSTATE) + rtb_TmpSignalConversionAtRP_S_h) -
        rtb_dycmax) * -rtb_Product8;

      /* End of Outputs for SubSystem: '<S16>/Case4' */
      break;

     case 5:
      /* Outputs for IfAction SubSystem: '<S16>/Case5' incorporates:
       *  ActionPort: '<S22>/Action Port'
       */
      /* Switch: '<S22>/Switch13' incorporates:
       *  Constant: '<S22>/Constant4'
       *  Constant: '<S39>/Constant'
       *  Gain: '<S22>/Gain23'
       *  RelationalOperator: '<S39>/Compare'
       */
      if (rtb_Product8 >= 0.0F) {
        rtb_dycmax = 2.0F * rtb_Product_eb;
      } else {
        rtb_dycmax = 0.0F;
      }

      /* End of Switch: '<S22>/Switch13' */

      /* Switch: '<S22>/Switch1' incorporates:
       *  Constant: '<S49>/CAL_BCC_dycUpLimt_f32'
       *  Gain: '<S22>/Gain2'
       *  Gain: '<S22>/Gain20'
       *  RelationalOperator: '<S49>/Relational Operator'
       *  Switch: '<S22>/Switch14'
       */
      if (SWC_BCC_DW.UnitDelay2_DSTATE >= CAL_BCC_dycUpLimt_f32) {
        rtb_Saturation_c = CAL_BCC_tiFull_f32 * rtb_Product_eb;
      } else if (rtb_Switch_b) {
        /* Switch: '<S22>/Switch14' incorporates:
         *  Constant: '<S22>/Constant5'
         */
        rtb_Saturation_c = 0.0F;
      } else {
        rtb_Saturation_c = 2.0F * rtb_Product_eb;
      }

      /* End of Switch: '<S22>/Switch1' */

      /* Switch: '<S22>/Switch15' incorporates:
       *  Constant: '<S22>/Constant6'
       *  Constant: '<S40>/Constant'
       *  Gain: '<S22>/Gain22'
       *  RelationalOperator: '<S40>/Compare'
       */
      if (rtb_Product8 >= 0.0F) {
        rtb_TmpSignalConversionAtRP_S_h = 0.0F;
      } else {
        rtb_TmpSignalConversionAtRP_S_h = 2.0F * rtb_Product_eb;
      }

      /* End of Switch: '<S22>/Switch15' */

      /* Switch: '<S22>/Switch2' incorporates:
       *  Constant: '<S38>/Constant'
       *  Constant: '<S49>/CAL_BCC_dycLowLimt_f32'
       *  Gain: '<S22>/Gain1'
       *  Gain: '<S22>/Gain5'
       *  Logic: '<S22>/Logical Operator3'
       *  RelationalOperator: '<S38>/Compare'
       *  RelationalOperator: '<S49>/Relational Operator1'
       *  Switch: '<S22>/Switch3'
       *  Switch: '<S22>/Switch5'
       */
      if (SWC_BCC_DW.UnitDelay1_DSTATE <= CAL_BCC_dycLowLimt_f32) {
        rtb_TmpSignalConversionAtRP__ou = CAL_BCC_tiFull_f32 * rtb_Product_eb;
      } else if (rtb_Switch_b) {
        /* Switch: '<S22>/Switch4' incorporates:
         *  Constant: '<S22>/CAL_BCC_AgGenCoe_f32'
         *  Constant: '<S22>/Constant2'
         *  Constant: '<S38>/Constant'
         *  Product: '<S22>/Product'
         *  RelationalOperator: '<S38>/Compare'
         *  Switch: '<S22>/Switch5'
         */
        if (rtb_Product14 <= 0.0F) {
          rtb_TmpSignalConversionAtRP__ou = rtb_Product_eb *
            CAL_BCC_AgGenCoe_f32;
        } else {
          rtb_TmpSignalConversionAtRP__ou = 0.0F;
        }

        /* End of Switch: '<S22>/Switch4' */
      } else if (rtb_Product14 > 0.0F) {
        /* Switch: '<S22>/Switch3' incorporates:
         *  Constant: '<S22>/Constant1'
         *  Switch: '<S22>/Switch5'
         */
        rtb_TmpSignalConversionAtRP__ou = 0.0F;
      } else {
        rtb_TmpSignalConversionAtRP__ou = 2.0F * rtb_Product_eb;
      }

      /* End of Switch: '<S22>/Switch2' */

      /* Sum: '<S22>/Add24' incorporates:
       *  Gain: '<S22>/Gain21'
       *  Product: '<S22>/Product13'
       *  Product: '<S22>/Product14'
       *  Sum: '<S10>/Add1'
       *  Sum: '<S14>/Add1'
       *  Sum: '<S22>/Add20'
       *  Sum: '<S22>/Add21'
       *  Sum: '<S22>/Add22'
       *  Sum: '<S22>/Add23'
       */
      VAR_BCC_iDcLnkEst_f32 = (((SWC_BCC_DW.UnitDelay2_DSTATE -
        SWC_BCC_DW.UnitDelay_DSTATE) + rtb_dycmax) - rtb_Saturation_c) *
        rtb_Product11 + (((SWC_BCC_DW.UnitDelay_DSTATE -
                           SWC_BCC_DW.UnitDelay1_DSTATE) +
                          rtb_TmpSignalConversionAtRP_S_h) -
                         rtb_TmpSignalConversionAtRP__ou) * -rtb_Product14;

      /* End of Outputs for SubSystem: '<S16>/Case5' */
      break;

     case 6:
      /* Outputs for IfAction SubSystem: '<S16>/Case6' incorporates:
       *  ActionPort: '<S23>/Action Port'
       */
      /* Switch: '<S23>/Switch13' incorporates:
       *  Constant: '<S23>/Constant4'
       *  Constant: '<S42>/Constant'
       *  Gain: '<S23>/Gain23'
       *  RelationalOperator: '<S42>/Compare'
       */
      if (rtb_Product11 >= 0.0F) {
        rtb_Saturation_c = 2.0F * rtb_Product_eb;
      } else {
        rtb_Saturation_c = 0.0F;
      }

      /* End of Switch: '<S23>/Switch13' */

      /* Switch: '<S23>/Switch1' incorporates:
       *  Constant: '<S41>/Constant'
       *  Constant: '<S50>/CAL_BCC_dycUpLimt_f32'
       *  Gain: '<S23>/Gain2'
       *  Gain: '<S23>/Gain5'
       *  Logic: '<S23>/Logical Operator3'
       *  RelationalOperator: '<S41>/Compare'
       *  RelationalOperator: '<S50>/Relational Operator'
       *  Switch: '<S23>/Switch3'
       *  Switch: '<S23>/Switch5'
       */
      if (SWC_BCC_DW.UnitDelay_DSTATE >= CAL_BCC_dycUpLimt_f32) {
        rtb_dycmax = CAL_BCC_tiFull_f32 * rtb_Product_eb;
      } else if (rtb_Switch_b) {
        /* Switch: '<S23>/Switch4' incorporates:
         *  Constant: '<S23>/CAL_BCC_AgGenCoe_f32'
         *  Constant: '<S23>/Constant2'
         *  Constant: '<S41>/Constant'
         *  Product: '<S23>/Product'
         *  RelationalOperator: '<S41>/Compare'
         *  Switch: '<S23>/Switch5'
         */
        if (rtb_Product8 >= 0.0F) {
          rtb_dycmax = rtb_Product_eb * CAL_BCC_AgGenCoe_f32;
        } else {
          rtb_dycmax = 0.0F;
        }

        /* End of Switch: '<S23>/Switch4' */
      } else if (rtb_Product8 < 0.0F) {
        /* Switch: '<S23>/Switch3' incorporates:
         *  Constant: '<S23>/Constant1'
         *  Switch: '<S23>/Switch5'
         */
        rtb_dycmax = 0.0F;
      } else {
        rtb_dycmax = 2.0F * rtb_Product_eb;
      }

      /* End of Switch: '<S23>/Switch1' */

      /* Switch: '<S23>/Switch15' incorporates:
       *  Constant: '<S23>/Constant6'
       *  Constant: '<S43>/Constant'
       *  Gain: '<S23>/Gain22'
       *  RelationalOperator: '<S43>/Compare'
       */
      if (rtb_Product11 >= 0.0F) {
        rtb_TmpSignalConversionAtRP_S_h = 0.0F;
      } else {
        rtb_TmpSignalConversionAtRP_S_h = 2.0F * rtb_Product_eb;
      }

      /* End of Switch: '<S23>/Switch15' */

      /* Switch: '<S23>/Switch2' incorporates:
       *  Constant: '<S50>/CAL_BCC_dycLowLimt_f32'
       *  Gain: '<S23>/Gain1'
       *  Gain: '<S23>/Gain20'
       *  RelationalOperator: '<S50>/Relational Operator1'
       *  Switch: '<S23>/Switch14'
       */
      if (SWC_BCC_DW.UnitDelay1_DSTATE <= CAL_BCC_dycLowLimt_f32) {
        rtb_TmpSignalConversionAtRP__ou = CAL_BCC_tiFull_f32 * rtb_Product_eb;
      } else if (rtb_Switch_b) {
        /* Switch: '<S23>/Switch14' incorporates:
         *  Constant: '<S23>/Constant5'
         */
        rtb_TmpSignalConversionAtRP__ou = 0.0F;
      } else {
        rtb_TmpSignalConversionAtRP__ou = 2.0F * rtb_Product_eb;
      }

      /* End of Switch: '<S23>/Switch2' */

      /* Sum: '<S23>/Add24' incorporates:
       *  Gain: '<S23>/Gain21'
       *  Product: '<S23>/Product13'
       *  Product: '<S23>/Product14'
       *  Sum: '<S11>/Add1'
       *  Sum: '<S15>/Add1'
       *  Sum: '<S23>/Add20'
       *  Sum: '<S23>/Add21'
       *  Sum: '<S23>/Add22'
       *  Sum: '<S23>/Add23'
       */
      VAR_BCC_iDcLnkEst_f32 = (((SWC_BCC_DW.UnitDelay_DSTATE -
        SWC_BCC_DW.UnitDelay2_DSTATE) + rtb_Saturation_c) - rtb_dycmax) *
        rtb_Product8 + (((SWC_BCC_DW.UnitDelay2_DSTATE -
                          SWC_BCC_DW.UnitDelay1_DSTATE) +
                         rtb_TmpSignalConversionAtRP_S_h) -
                        rtb_TmpSignalConversionAtRP__ou) * -rtb_Product14;

      /* End of Outputs for SubSystem: '<S16>/Case6' */
      break;

     default:
      /* Outputs for IfAction SubSystem: '<S16>/Case7' incorporates:
       *  ActionPort: '<S24>/Action Port'
       */
      /* SignalConversion generated from: '<S24>/IdcCal_Default' incorporates:
       *  Constant: '<S24>/Constant'
       */
      VAR_BCC_iDcLnkEst_f32 = 0.0F;

      /* End of Outputs for SubSystem: '<S16>/Case7' */
      break;
    }

    /* End of SwitchCase: '<S16>/Switch Case' */

    /* Product: '<S51>/Divide' incorporates:
     *  Constant: '<S17>/100usflt'
     *  Constant: '<S17>/CAL_BCC_iDcEstflt_f32'
     */
    rtb_Product_eb = 10000.0F / CAL_BCC_iDcEstflt_f32;

    /* Switch: '<S53>/Switch' incorporates:
     *  Constant: '<S51>/Constant'
     *  RelationalOperator: '<S53>/UpperRelop'
     *  Switch: '<S53>/Switch2'
     */
    if (rtb_Product_eb < 1.0F) {
      rtb_Product_eb = 1.0F;
    }

    /* End of Switch: '<S53>/Switch' */

    /* Product: '<S51>/Divide1' incorporates:
     *  Constant: '<S51>/One1'
     *  Sum: '<S51>/Add'
     */
    rtb_Product_eb /= rtb_Product_eb + 6.283F;

    /* Sum: '<S51>/Sum1' incorporates:
     *  Constant: '<S51>/One'
     *  Product: '<S51>/Product'
     *  Product: '<S51>/Product1'
     *  Sum: '<S51>/Subtract1'
     */
    VAR_BCC_iDcLnkEstFlt_f32 = (1.0F - rtb_Product_eb) * VAR_BCC_iDcLnkEst_f32 +
      rtb_Product_eb * VAR_BCC_iDcLnkEstFlt_f32;

    /* Logic: '<S52>/Logical Operator' incorporates:
     *  Constant: '<S52>/IGBTAscDwn'
     *  Constant: '<S52>/IGBTAscUp'
     *  RelationalOperator: '<S52>/Relational Operator'
     *  RelationalOperator: '<S52>/Relational Operator1'
     */
    VAR_BCC_flgstGateDrv_b = ((rtb_TmpSignalConversionAtRP_S_b == 1) ||
      (rtb_TmpSignalConversionAtRP_S_b == 2));

    /* Switch: '<S52>/Switch' incorporates:
     *  Constant: '<S52>/Constant2'
     */
    if (VAR_BCC_flgstGateDrv_b) {
      rtb_Switch10_idx_2 = 0.0F;
    } else {
      rtb_Switch10_idx_2 = VAR_BCC_iDcLnkEstFlt_f32;
    }

    /* Outport: '<Root>/PP_SWC_BCC_BCC_iDcLnkEstFlt' incorporates:
     *  Switch: '<S52>/Switch'
     */
    (void) Rte_Write_PP_SWC_BCC_BCC_iDcLnkEstFlt(rtb_Switch10_idx_2);

    /* Update for Switch: '<S16>/Switch' incorporates:
     *  UnitDelay: '<S16>/Unit Delay'
     */
    SWC_BCC_DW.UnitDelay_DSTATE_ay = rtb_TmpSignalConversionAtRP_S_p;
  }

  /* End of Constant: '<S3>/Constant' */
  /* End of Outputs for SubSystem: '<S3>/Idc_Calc' */

  /* Outputs for Enabled SubSystem: '<S3>/Tj' incorporates:
   *  EnablePort: '<S6>/Enable'
   */
  /* Switch: '<S3>/Switch' incorporates:
   *  Constant: '<S3>/Constant1'
   *  Constant: '<S3>/Constant2'
   *  Constant: '<S54>/Constant'
   *  Constant: '<S55>/Constant'
   *  RelationalOperator: '<S54>/Compare'
   *  RelationalOperator: '<S55>/Compare'
   *  Switch: '<S3>/Switch1'
   */
  if (CAL_BCC_flgEnableTj_b) {
    SWC_BCC_DW.Tj_MODE = true;

    /* Chart: '<S57>/max_min' incorporates:
     *  Gain: '<S57>/Gain1'
     *  Gain: '<S57>/Gain2'
     *  RelationalOperator: '<S57>/Relational Operator'
     *  RelationalOperator: '<S57>/Relational Operator1'
     *  RelationalOperator: '<S57>/Relational Operator2'
     *  Sum: '<S57>/Add'
     */
    switch ((sint32)(((((uint32)((rtb_TmpSignalConversionAtRP_S_g >=
      rtb_TmpSignalConversionAtRP_S_i) << 7) << 1) + ((uint32)
                (rtb_TmpSignalConversionAtRP__ha >=
                 rtb_TmpSignalConversionAtRP_S_g) << 7)) + ((uint32)
               ((rtb_TmpSignalConversionAtRP__ha >=
                 rtb_TmpSignalConversionAtRP_S_i) << 7) << 2)) >> 7)) {
     case 0:
      rtb_dycmax = rtb_TmpSignalConversionAtRP_S_i;
      rtb_Saturation_c = rtb_TmpSignalConversionAtRP_S_g;
      rtb_Product_eb = rtb_TmpSignalConversionAtRP__ha;
      break;

     case 1:
      rtb_dycmax = rtb_TmpSignalConversionAtRP_S_i;
      rtb_Saturation_c = rtb_TmpSignalConversionAtRP__ha;
      rtb_Product_eb = rtb_TmpSignalConversionAtRP_S_g;
      break;

     case 2:
      rtb_dycmax = rtb_TmpSignalConversionAtRP_S_g;
      rtb_Saturation_c = rtb_TmpSignalConversionAtRP_S_i;
      rtb_Product_eb = rtb_TmpSignalConversionAtRP__ha;
      break;

     case 3:
      rtb_dycmax = 0.0F;
      rtb_Saturation_c = 0.0F;
      rtb_Product_eb = 0.0F;
      break;

     case 4:
      rtb_dycmax = 0.0F;
      rtb_Saturation_c = 0.0F;
      rtb_Product_eb = 0.0F;
      break;

     case 5:
      rtb_dycmax = rtb_TmpSignalConversionAtRP__ha;
      rtb_Saturation_c = rtb_TmpSignalConversionAtRP_S_i;
      rtb_Product_eb = rtb_TmpSignalConversionAtRP_S_g;
      break;

     case 6:
      rtb_dycmax = rtb_TmpSignalConversionAtRP_S_g;
      rtb_Saturation_c = rtb_TmpSignalConversionAtRP__ha;
      rtb_Product_eb = rtb_TmpSignalConversionAtRP_S_i;
      break;

     default:
      rtb_dycmax = rtb_TmpSignalConversionAtRP__ha;
      rtb_Saturation_c = rtb_TmpSignalConversionAtRP_S_g;
      rtb_Product_eb = rtb_TmpSignalConversionAtRP_S_i;
      break;
    }

    /* End of Chart: '<S57>/max_min' */

    /* Chart: '<S6>/tsoncal' incorporates:
     *  Constant: '<S6>/Constant2'
     */
    rtb_TmpSignalConversionAtRP__ou = 0.0F;
    rtb_TmpSignalConversionAtRP_S_h = 0.0F;
    rtb_TmpSignalConversionAtRP_S_d = 0.0F;
    rtb_Switch2_a = 0.0F;
    rtb_Switch4_g = 0.0F;
    rtb_Product3 = 0.0F;
    rtb_tvdh_e = 0.0F;
    rtb_tvdl_j = 0.0F;
    rtb_twih_j = 0.0F;
    rtb_twil_i = 0.0F;
    rtb_twdh_e = 0.0F;
    rtb_twdl_p = 0.0F;
    rtb_dycmax = (float32)(((1.0F - rtb_dycmax) - 0.024F) * 0.5) + 0.024F;
    rtb_Saturation_c = (float32)(((1.0F - rtb_Saturation_c) - 0.024F) * 0.5);
    rtb_Product_eb = (float32)(((1.0F - rtb_Product_eb) - 0.024F) * 0.5);
    switch (rtb_TmpSignalConversionAtRP_S_p) {
     case 1:
      rtb_Switch2_a = rtb_Saturation_c + 0.024F;
      rtb_TmpSignalConversionAtRP__ou = 0.5F - (rtb_Saturation_c + 0.024F);
      rtb_tvdl_j = rtb_dycmax;
      rtb_Switch4_g = 0.5F - rtb_dycmax;
      rtb_twil_i = rtb_Product_eb;
      rtb_twdl_p = 0.5F - rtb_Product_eb;
      break;

     case 2:
      rtb_Switch2_a = rtb_dycmax;
      rtb_TmpSignalConversionAtRP__ou = 0.5F - rtb_dycmax;
      rtb_Product3 = rtb_Product_eb;
      rtb_tvdh_e = 0.5F - rtb_Product_eb;
      rtb_twdl_p = rtb_Saturation_c + 0.024F;
      rtb_twih_j = 0.5F - (rtb_Saturation_c + 0.024F);
      break;

     case 3:
      rtb_Switch2_a = rtb_dycmax;
      rtb_TmpSignalConversionAtRP__ou = 0.5F - rtb_dycmax;
      rtb_Product3 = rtb_Saturation_c;
      rtb_tvdh_e = 0.5F - rtb_Saturation_c;
      rtb_twil_i = rtb_Product_eb;
      rtb_twdh_e = 0.5F - rtb_Product_eb;
      break;

     case 4:
      rtb_TmpSignalConversionAtRP_S_h = rtb_Product_eb;
      rtb_TmpSignalConversionAtRP_S_d = 0.5F - rtb_Product_eb;
      rtb_tvdl_j = rtb_Saturation_c + 0.024F;
      rtb_Switch4_g = 0.5F - (rtb_Saturation_c + 0.024F);
      rtb_twdl_p = rtb_dycmax;
      rtb_twih_j = 0.5F - rtb_dycmax;
      break;

     case 5:
      rtb_TmpSignalConversionAtRP_S_h = rtb_Product_eb;
      rtb_TmpSignalConversionAtRP_S_d = 0.5F - rtb_Product_eb;
      rtb_tvdl_j = rtb_dycmax;
      rtb_Switch4_g = 0.5F - rtb_dycmax;
      rtb_twil_i = rtb_Saturation_c;
      rtb_twdh_e = 0.5F - rtb_Saturation_c;
      break;

     case 6:
      rtb_TmpSignalConversionAtRP_S_h = rtb_Saturation_c;
      rtb_TmpSignalConversionAtRP_S_d = 0.5F - rtb_Saturation_c;
      rtb_Product3 = rtb_Product_eb;
      rtb_tvdh_e = 0.5F - rtb_Product_eb;
      rtb_twdl_p = rtb_dycmax;
      rtb_twih_j = 0.5F - rtb_dycmax;
      break;
    }

    /* End of Chart: '<S6>/tsoncal' */

    /* Saturate: '<S6>/Saturation4' */
    if (rtb_Switch4_g > 1.0F) {
      rtb_Switch4_g = 1.0F;
    } else {
      if (rtb_Switch4_g < 0.0F) {
        rtb_Switch4_g = 0.0F;
      }
    }

    /* End of Saturate: '<S6>/Saturation4' */

    /* Saturate: '<S6>/Saturation5' */
    if (rtb_Product3 > 1.0F) {
      rtb_Product3 = 1.0F;
    } else {
      if (rtb_Product3 < 0.0F) {
        rtb_Product3 = 0.0F;
      }
    }

    /* End of Saturate: '<S6>/Saturation5' */

    /* Saturate: '<S6>/Saturation6' */
    if (rtb_tvdh_e > 1.0F) {
      rtb_tvdh_e = 1.0F;
    } else {
      if (rtb_tvdh_e < 0.0F) {
        rtb_tvdh_e = 0.0F;
      }
    }

    /* End of Saturate: '<S6>/Saturation6' */

    /* Saturate: '<S6>/Saturation7' */
    if (rtb_tvdl_j > 1.0F) {
      rtb_tvdl_j = 1.0F;
    } else {
      if (rtb_tvdl_j < 0.0F) {
        rtb_tvdl_j = 0.0F;
      }
    }

    /* End of Saturate: '<S6>/Saturation7' */

    /* Saturate: '<S6>/Saturation8' */
    if (rtb_twih_j > 1.0F) {
      rtb_twih_j = 1.0F;
    } else {
      if (rtb_twih_j < 0.0F) {
        rtb_twih_j = 0.0F;
      }
    }

    /* End of Saturate: '<S6>/Saturation8' */

    /* Saturate: '<S6>/Saturation9' */
    if (rtb_twil_i > 1.0F) {
      rtb_twil_i = 1.0F;
    } else {
      if (rtb_twil_i < 0.0F) {
        rtb_twil_i = 0.0F;
      }
    }

    /* End of Saturate: '<S6>/Saturation9' */

    /* Saturate: '<S6>/Saturation10' */
    if (rtb_twdh_e > 1.0F) {
      rtb_twdh_e = 1.0F;
    } else {
      if (rtb_twdh_e < 0.0F) {
        rtb_twdh_e = 0.0F;
      }
    }

    /* End of Saturate: '<S6>/Saturation10' */

    /* Saturate: '<S6>/Saturation11' */
    if (rtb_twdl_p > 1.0F) {
      rtb_twdl_p = 1.0F;
    } else {
      if (rtb_twdl_p < 0.0F) {
        rtb_twdl_p = 0.0F;
      }
    }

    /* End of Saturate: '<S6>/Saturation11' */

    /* Saturate: '<S6>/Saturation' */
    if (rtb_TmpSignalConversionAtRP__ou > 1.0F) {
      rtb_TmpSignalConversionAtRP__ou = 1.0F;
    } else {
      if (rtb_TmpSignalConversionAtRP__ou < 0.0F) {
        rtb_TmpSignalConversionAtRP__ou = 0.0F;
      }
    }

    /* End of Saturate: '<S6>/Saturation' */

    /* Saturate: '<S6>/Saturation1' */
    if (rtb_TmpSignalConversionAtRP_S_h > 1.0F) {
      rtb_TmpSignalConversionAtRP_S_h = 1.0F;
    } else {
      if (rtb_TmpSignalConversionAtRP_S_h < 0.0F) {
        rtb_TmpSignalConversionAtRP_S_h = 0.0F;
      }
    }

    /* End of Saturate: '<S6>/Saturation1' */

    /* Saturate: '<S6>/Saturation2' */
    if (rtb_TmpSignalConversionAtRP_S_d > 1.0F) {
      rtb_TmpSignalConversionAtRP_S_d = 1.0F;
    } else {
      if (rtb_TmpSignalConversionAtRP_S_d < 0.0F) {
        rtb_TmpSignalConversionAtRP_S_d = 0.0F;
      }
    }

    /* End of Saturate: '<S6>/Saturation2' */

    /* Saturate: '<S6>/Saturation3' */
    if (rtb_Switch2_a > 1.0F) {
      rtb_Switch2_a = 1.0F;
    } else {
      if (rtb_Switch2_a < 0.0F) {
        rtb_Switch2_a = 0.0F;
      }
    }

    /* End of Saturate: '<S6>/Saturation3' */

    /* Switch: '<S61>/Switch10' incorporates:
     *  Constant: '<S61>/Constant19'
     *  Constant: '<S61>/Constant6'
     *  Constant: '<S61>/Constant7'
     *  RelationalOperator: '<S61>/Relational Operator6'
     *  RelationalOperator: '<S61>/Relational Operator7'
     *  Switch: '<S61>/Switch11'
     */
    if (CAL_TjstUVW_u8 == 1) {
      rtb_Switch10_idx_0 = rtb_TmpSignalConversionAtRP__ou;
      rtb_Switch10_idx_1 = rtb_TmpSignalConversionAtRP_S_h;
      rtb_Switch10_idx_2 = rtb_TmpSignalConversionAtRP_S_d;
      rtb_Switch10_idx_3 = rtb_Switch2_a;
    } else if (CAL_TjstUVW_u8 == 2) {
      /* Switch: '<S61>/Switch11' */
      rtb_Switch10_idx_0 = rtb_Switch4_g;
      rtb_Switch10_idx_1 = rtb_Product3;
      rtb_Switch10_idx_2 = rtb_tvdh_e;
      rtb_Switch10_idx_3 = rtb_tvdl_j;
    } else {
      rtb_Switch10_idx_0 = rtb_twih_j;
      rtb_Switch10_idx_1 = rtb_twil_i;
      rtb_Switch10_idx_2 = rtb_twdh_e;
      rtb_Switch10_idx_3 = rtb_twdl_p;
    }

    /* End of Switch: '<S61>/Switch10' */

    /* UnitDelay: '<S6>/Unit Delay2' */
    rtb_Product_eb = SWC_BCC_DW.UnitDelay2_DSTATE_o;

    /* UnitDelay: '<S6>/Unit Delay' */
    rtb_dycmax = SWC_BCC_DW.UnitDelay_DSTATE_d;

    /* UnitDelay: '<S6>/Unit Delay1' */
    rtb_Saturation_c = SWC_BCC_DW.UnitDelay1_DSTATE_f;

    /* Switch: '<S61>/Switch6' incorporates:
     *  Switch: '<S61>/Switch7'
     *  UnitDelay: '<S6>/Unit Delay1'
     *  UnitDelay: '<S6>/Unit Delay2'
     */
    if (SWC_BCC_ConstB.RelationalOperator2) {
      rtb_Gain11 = SWC_BCC_DW.UnitDelay2_DSTATE_o;
    } else if (SWC_BCC_ConstB.RelationalOperator3) {
      /* Switch: '<S61>/Switch7' incorporates:
       *  UnitDelay: '<S6>/Unit Delay'
       */
      rtb_Gain11 = SWC_BCC_DW.UnitDelay_DSTATE_d;
    } else {
      rtb_Gain11 = SWC_BCC_DW.UnitDelay1_DSTATE_f;
    }

    /* End of Switch: '<S61>/Switch6' */

    /* Abs: '<S6>/Abs' */
    rtb_iu = fabsf(rtb_Product8);

    /* Abs: '<S6>/Abs1' */
    rtb_iv = fabsf(rtb_Product14);

    /* Abs: '<S6>/Abs2' */
    rtb_Product14 = fabsf(rtb_Product11);

    /* Switch: '<S61>/Switch4' incorporates:
     *  Switch: '<S61>/Switch5'
     */
    if (SWC_BCC_ConstB.RelationalOperator) {
      rtb_Switch2_i = rtb_iu;
    } else if (SWC_BCC_ConstB.RelationalOperator1) {
      /* Switch: '<S61>/Switch5' */
      rtb_Switch2_i = rtb_iv;
    } else {
      rtb_Switch2_i = rtb_Product14;
    }

    /* End of Switch: '<S61>/Switch4' */

    /* Saturate: '<S6>/Saturation12' */
    if (rtb_TmpSignalConversionAtRP_S_l > 20000.0F) {
      rtb_TmpSignalConversionAtRP_S_l = 20000.0F;
    } else {
      if (rtb_TmpSignalConversionAtRP_S_l < 0.0001F) {
        rtb_TmpSignalConversionAtRP_S_l = 0.0001F;
      }
    }

    /* End of Saturate: '<S6>/Saturation12' */

    /* Product: '<S6>/Divide1' incorporates:
     *  Constant: '<S6>/Constant1'
     */
    rtb_TmpSignalConversionAtRP_S_l = 1.0F / rtb_TmpSignalConversionAtRP_S_l;

    /* Outputs for Enabled SubSystem: '<S6>/uTjCal1' incorporates:
     *  EnablePort: '<S59>/Enable'
     */
    /* Outputs for Enabled SubSystem: '<S6>/uTjCal2' incorporates:
     *  EnablePort: '<S60>/Enable'
     */
    /* Product: '<S61>/Divide2' incorporates:
     *  Gain: '<S61>/Gain4'
     *  Product: '<S59>/Divide2'
     *  Product: '<S60>/Divide2'
     */
    rtb_TmpSignalConversionAtRP_S_e = 0.005F * rtb_TmpSignalConversionAtRP_S_e /
      rtb_TmpSignalConversionAtRP_S_l;

    /* End of Outputs for SubSystem: '<S6>/uTjCal2' */
    /* End of Outputs for SubSystem: '<S6>/uTjCal1' */

    /* Product: '<S61>/Divide' incorporates:
     *  Gain: '<S61>/Gain1'
     *  Lookup_n-D: '<S61>/2-D Lookup Table'
     *  Product: '<S61>/Divide2'
     */
    rtb_Switch1_a = 0.001F * look2_iflf_binlxpw(rtb_Switch2_i, rtb_Gain11,
      rtCP_uDLookupTable_bp01Data_lw, rtCP_uDLookupTable_bp02Data_d,
      rtCP_uDLookupTable_tableData_c, rtCP_uDLookupTable_maxIndex_p, 17U) *
      rtb_TmpSignalConversionAtRP_S_e;

    /* Switch: '<S61>/Switch' incorporates:
     *  Constant: '<S129>/Constant'
     *  Constant: '<S129>/Constant1'
     *  Constant: '<S61>/Constant'
     *  Logic: '<S129>/Logical Operator'
     *  RelationalOperator: '<S129>/Relational Operator'
     *  RelationalOperator: '<S129>/Relational Operator1'
     */
    if ((rtb_Switch10_idx_0 >= CAL_TjDycMin_f32) && (rtb_Switch10_idx_0 <=
         CAL_TjDycMax_f32)) {
      rtb_Switch_i = rtb_Switch1_a;
    } else {
      rtb_Switch_i = 0.0F;
    }

    /* End of Switch: '<S61>/Switch' */

    /* Product: '<S61>/Product23' incorporates:
     *  Constant: '<S139>/Constant'
     *  Constant: '<S139>/Constant1'
     *  Constant: '<S139>/Constant2'
     *  Constant: '<S139>/Constant3'
     *  Gain: '<S61>/Gain5'
     *  Product: '<S139>/Product'
     *  Product: '<S139>/Product1'
     *  Product: '<S61>/Product1'
     *  Sum: '<S139>/Add'
     *  Sum: '<S139>/Add1'
     *  Sum: '<S61>/Add1'
     */
    rtb_Product10_l = ((rtb_Gain11 * 2.8E-6F + 0.00072F) * rtb_Switch2_i +
                       (rtb_Gain11 * -0.0012F + 0.839F)) * 2.0F * rtb_Switch2_i;

    /* Product: '<S61>/Product9' */
    rtb_Product9_j = rtb_Switch10_idx_0 * rtb_Product10_l;

    /* Product: '<S61>/Product10' */
    rtb_Product10_l *= rtb_Switch10_idx_1;

    /* Switch: '<S61>/Switch1' incorporates:
     *  Constant: '<S136>/Constant'
     *  Constant: '<S136>/Constant1'
     *  Constant: '<S61>/Constant1'
     *  Logic: '<S136>/Logical Operator'
     *  RelationalOperator: '<S136>/Relational Operator'
     *  RelationalOperator: '<S136>/Relational Operator1'
     */
    if ((rtb_Switch10_idx_1 < CAL_TjDycMin_f32) || (rtb_Switch10_idx_1 >
         CAL_TjDycMax_f32)) {
      rtb_Switch1_a = 0.0F;
    }

    /* End of Switch: '<S61>/Switch1' */

    /* Product: '<S61>/Product24' incorporates:
     *  Constant: '<S139>/Constant4'
     *  Constant: '<S139>/Constant5'
     *  Constant: '<S139>/Constant6'
     *  Constant: '<S139>/Constant7'
     *  Gain: '<S61>/Gain6'
     *  Product: '<S139>/Product2'
     *  Product: '<S139>/Product3'
     *  Product: '<S61>/Product6'
     *  Sum: '<S139>/Add2'
     *  Sum: '<S139>/Add3'
     *  Sum: '<S61>/Add8'
     */
    rtb_Product8 = ((rtb_Gain11 * 1.8E-6F + 0.0012F) * rtb_Switch2_i +
                    (rtb_Gain11 * -0.0019F + 1.061F)) * 2.0F * rtb_Switch2_i;

    /* Product: '<S61>/Product11' */
    rtb_Switch10_idx_1 = rtb_Switch10_idx_2 * rtb_Product8;

    /* Lookup_n-D: '<S61>/2-D Lookup Table1' */
    rtb_Switch2_i = look2_iflf_binlxpw(rtb_Switch2_i, rtb_Gain11,
      rtCP_uDLookupTable1_bp01Data_e, rtCP_uDLookupTable1_bp02Data_f,
      rtCP_uDLookupTable1_tableData_j, rtCP_uDLookupTable1_maxIndex_m, 17U);

    /* Product: '<S61>/Divide1' incorporates:
     *  Gain: '<S61>/Gain3'
     *  Product: '<S61>/Divide2'
     */
    rtb_Product11 = 0.001F * rtb_Switch2_i * rtb_TmpSignalConversionAtRP_S_e;

    /* Switch: '<S61>/Switch2' incorporates:
     *  Constant: '<S137>/Constant'
     *  Constant: '<S137>/Constant1'
     *  Constant: '<S61>/Constant2'
     *  Logic: '<S137>/Logical Operator'
     *  RelationalOperator: '<S137>/Relational Operator'
     *  RelationalOperator: '<S137>/Relational Operator1'
     */
    if ((rtb_Switch10_idx_2 >= CAL_TjDycMin_f32) && (rtb_Switch10_idx_2 <=
         CAL_TjDycMax_f32)) {
      rtb_Switch2_i = rtb_Product11;
    } else {
      rtb_Switch2_i = 0.0F;
    }

    /* End of Switch: '<S61>/Switch2' */

    /* Product: '<S61>/Product12' */
    rtb_Product8 *= rtb_Switch10_idx_3;

    /* Switch: '<S61>/Switch3' incorporates:
     *  Constant: '<S138>/Constant'
     *  Constant: '<S138>/Constant1'
     *  Constant: '<S61>/Constant3'
     *  Logic: '<S138>/Logical Operator'
     *  RelationalOperator: '<S138>/Relational Operator'
     *  RelationalOperator: '<S138>/Relational Operator1'
     */
    if ((rtb_Switch10_idx_3 < CAL_TjDycMin_f32) || (rtb_Switch10_idx_3 >
         CAL_TjDycMax_f32)) {
      rtb_Product11 = 0.0F;
    }

    /* End of Switch: '<S61>/Switch3' */

    /* Gain: '<S61>/Gain11' */
    rtb_Gain11 = 0.7F * rtb_TmpSignalConversionAtRP_S_l;

    /* Sum: '<S134>/Add' incorporates:
     *  Constant: '<S134>/Constant'
     *  Product: '<S134>/Product'
     *  Product: '<S134>/Product1'
     *  Sum: '<S134>/Add1'
     *  Sum: '<S61>/Add7'
     */
    VAR_WTjpwr_f32 = (((((((rtb_Product9_j + rtb_Product10_l) +
      rtb_Switch10_idx_1) + rtb_Product8) + rtb_Switch_i) + rtb_Switch1_a) +
                       rtb_Switch2_i) + rtb_Product11) * rtb_Gain11 + (1.0F -
      rtb_Gain11) * VAR_WTjpwr_f32;

    /* Sum: '<S61>/Add4' */
    rtb_Product8 += rtb_Product11;

    /* Lookup_n-D: '<S6>/1-D Lookup Table1' incorporates:
     *  Constant: '<S6>/Constant6'
     */
    rtb_Product11 = look1_iflf_binlxpw(CAL_CoolantFlowReq_u8, ((const float32 *)
      &(CAL_TjCoolantFlowTab_af32[0])), ((const float32 *)
      &(CAL_TjrthLv4IhNtcTab_af32[0])), 5U);

    /* Sum: '<S61>/Add' */
    rtb_Gain11 = rtb_Product9_j + rtb_Switch_i;

    /* Sum: '<S61>/Add2' */
    rtb_Switch1_a += rtb_Product10_l;

    /* Sum: '<S61>/Add3' */
    rtb_Switch2_i += rtb_Switch10_idx_1;

    /* Gain: '<S131>/Gain9' */
    rtb_Switch10_idx_1 = 0.7F * rtb_TmpSignalConversionAtRP_S_l;

    /* Sum: '<S141>/Add' incorporates:
     *  Constant: '<S141>/Constant'
     *  Constant: '<S6>/Constant21'
     *  Constant: '<S6>/Constant22'
     *  Constant: '<S6>/Constant23'
     *  Product: '<S131>/Product28'
     *  Product: '<S131>/Product3'
     *  Product: '<S131>/Product4'
     *  Product: '<S131>/Product5'
     *  Product: '<S141>/Product'
     *  Product: '<S141>/Product1'
     *  Sum: '<S131>/Add6'
     *  Sum: '<S141>/Add1'
     *  UnitDelay: '<S141>/Unit Delay'
     */
    SWC_BCC_DW.UnitDelay_DSTATE_g = (((rtb_Gain11 * rtb_Product11 +
      rtb_Switch1_a * CAL_TjrthLv4ilntc_f32) + rtb_Switch2_i *
      CAL_TjrthLv4dhntc_f32) + rtb_Product8 * CAL_TjrthLv4dlntc_f32) *
      rtb_Switch10_idx_1 + (1.0F - rtb_Switch10_idx_1) *
      SWC_BCC_DW.UnitDelay_DSTATE_g;

    /* Switch: '<S61>/Switch8' incorporates:
     *  Switch: '<S61>/Switch9'
     */
    if (SWC_BCC_ConstB.RelationalOperator4) {
      rtb_Switch10_idx_2 = rtb_TmpSignalConversionAtRP_SWC;
    } else if (SWC_BCC_ConstB.RelationalOperator5) {
      /* Switch: '<S61>/Switch9' */
      rtb_Switch10_idx_2 = rtb_TmpSignalConversionAtRP_S_n;
    } else {
      rtb_Switch10_idx_2 = rtb_TmpSignalConversionAtRP__br;
    }

    /* End of Switch: '<S61>/Switch8' */

    /* Sum: '<S61>/Add10' incorporates:
     *  UnitDelay: '<S141>/Unit Delay'
     */
    VAR_WCoolantTj_f32 = rtb_Switch10_idx_2 - SWC_BCC_DW.UnitDelay_DSTATE_g;

    /* Outputs for Enabled SubSystem: '<S6>/uTjCal1' incorporates:
     *  EnablePort: '<S59>/Enable'
     */
    /* Outputs for Enabled SubSystem: '<S6>/uTjCal2' incorporates:
     *  EnablePort: '<S60>/Enable'
     */
    /* Product: '<S61>/Product' incorporates:
     *  Constant: '<S61>/CAL_Tj_cofFltCoolant_f32'
     *  Product: '<S59>/Product'
     *  Product: '<S60>/Product'
     */
    rtb_Product9_j = rtb_TmpSignalConversionAtRP_S_l * CAL_Tj_cofFltCoolant_f32;

    /* End of Outputs for SubSystem: '<S6>/uTjCal2' */
    /* End of Outputs for SubSystem: '<S6>/uTjCal1' */

    /* Sum: '<S135>/Add' incorporates:
     *  Constant: '<S135>/Constant'
     *  Product: '<S135>/Product'
     *  Product: '<S135>/Product1'
     *  Product: '<S61>/Product'
     *  Sum: '<S135>/Add1'
     *  UnitDelay: '<S135>/Unit Delay'
     */
    SWC_BCC_DW.UnitDelay_DSTATE_m = (1.0F - rtb_Product9_j) *
      SWC_BCC_DW.UnitDelay_DSTATE_m + VAR_WCoolantTj_f32 * rtb_Product9_j;

    /* Lookup_n-D: '<S6>/1-D Lookup Table' incorporates:
     *  Constant: '<S6>/Constant6'
     */
    rtb_Product10_l = look1_iflf_binlxpw(CAL_CoolantFlowReq_u8, ((const float32 *)
      &(CAL_TjCoolantFlowTab_af32[0])), ((const float32 *)
      &(CAL_TjrthLv4IhIhTab_af32[0])), 5U);

    /* Lookup_n-D: '<S6>/1-D Lookup Table2' incorporates:
     *  Constant: '<S6>/Constant6'
     */
    rtb_Switch_i = look1_iflf_binlxpw(CAL_CoolantFlowReq_u8, ((const float32 *)
      &(CAL_TjCoolantFlowTab_af32[0])), ((const float32 *)
      &(CAL_TjrthLv4DhIhTab_af32[0])), 5U);

    /* Outputs for Enabled SubSystem: '<S6>/uTjCal2' incorporates:
     *  EnablePort: '<S60>/Enable'
     */
    if (rtb_TmpSignalConversionAtRP_S_l >= CAL_tiPwmLim_f32) {
      if (!SWC_BCC_DW.uTjCal2_MODE) {
        /* InitializeConditions for UnitDelay: '<S106>/Unit Delay' */
        SWC_BCC_DW.UnitDelay_DSTATE_mm = 0.0F;

        /* InitializeConditions for UnitDelay: '<S113>/Unit Delay' */
        SWC_BCC_DW.UnitDelay_DSTATE_gm = 0.0F;

        /* InitializeConditions for UnitDelay: '<S116>/Unit Delay' */
        SWC_BCC_DW.UnitDelay_DSTATE_lx = 0.0F;

        /* InitializeConditions for UnitDelay: '<S115>/Unit Delay' */
        SWC_BCC_DW.UnitDelay_DSTATE_as = 0.0F;

        /* InitializeConditions for UnitDelay: '<S117>/Unit Delay' */
        SWC_BCC_DW.UnitDelay_DSTATE_h2 = 0.0F;

        /* InitializeConditions for UnitDelay: '<S114>/Unit Delay' */
        SWC_BCC_DW.UnitDelay_DSTATE_ik = 0.0F;

        /* InitializeConditions for UnitDelay: '<S120>/Unit Delay' */
        SWC_BCC_DW.UnitDelay_DSTATE_fa = 0.0F;

        /* InitializeConditions for UnitDelay: '<S119>/Unit Delay' */
        SWC_BCC_DW.UnitDelay_DSTATE_n2 = 0.0F;

        /* InitializeConditions for UnitDelay: '<S121>/Unit Delay' */
        SWC_BCC_DW.UnitDelay_DSTATE_nt = 0.0F;

        /* InitializeConditions for UnitDelay: '<S118>/Unit Delay' */
        SWC_BCC_DW.UnitDelay_DSTATE_a5 = 0.0F;

        /* InitializeConditions for UnitDelay: '<S124>/Unit Delay' */
        SWC_BCC_DW.UnitDelay_DSTATE_gd = 0.0F;

        /* InitializeConditions for UnitDelay: '<S123>/Unit Delay' */
        SWC_BCC_DW.UnitDelay_DSTATE_pk = 0.0F;

        /* InitializeConditions for UnitDelay: '<S125>/Unit Delay' */
        SWC_BCC_DW.UnitDelay_DSTATE_hw = 0.0F;

        /* InitializeConditions for UnitDelay: '<S122>/Unit Delay' */
        SWC_BCC_DW.UnitDelay_DSTATE_dj = 0.0F;

        /* InitializeConditions for UnitDelay: '<S127>/Unit Delay' */
        SWC_BCC_DW.UnitDelay_DSTATE_cm = 0.0F;

        /* InitializeConditions for UnitDelay: '<S126>/Unit Delay' */
        SWC_BCC_DW.UnitDelay_DSTATE_cu = 0.0F;

        /* InitializeConditions for UnitDelay: '<S128>/Unit Delay' */
        SWC_BCC_DW.UnitDelay_DSTATE_bt = 0.0F;

        /* InitializeConditions for UnitDelay: '<S112>/Unit Delay' */
        SWC_BCC_DW.UnitDelay_DSTATE_gdo = 0.0F;

        /* InitializeConditions for UnitDelay: '<S107>/Unit Delay' */
        SWC_BCC_DW.UnitDelay_DSTATE_et = 0.0F;
        SWC_BCC_DW.uTjCal2_MODE = true;
      }

      /* Switch: '<S60>/Switch10' incorporates:
       *  Constant: '<S60>/Constant19'
       *  Constant: '<S60>/Constant6'
       *  Constant: '<S60>/Constant7'
       *  RelationalOperator: '<S60>/Relational Operator6'
       *  RelationalOperator: '<S60>/Relational Operator7'
       *  Switch: '<S60>/Switch11'
       */
      if (CAL_TjstUVW_u8 == 1) {
        rtb_Switch10_idx_0 = rtb_TmpSignalConversionAtRP__ou;
        rtb_Switch10_idx_1 = rtb_TmpSignalConversionAtRP_S_h;
        rtb_Switch10_idx_2 = rtb_TmpSignalConversionAtRP_S_d;
        rtb_Switch10_idx_3 = rtb_Switch2_a;
      } else if (CAL_TjstUVW_u8 == 2) {
        /* Switch: '<S60>/Switch11' */
        rtb_Switch10_idx_0 = rtb_Switch4_g;
        rtb_Switch10_idx_1 = rtb_Product3;
        rtb_Switch10_idx_2 = rtb_tvdh_e;
        rtb_Switch10_idx_3 = rtb_tvdl_j;
      } else {
        rtb_Switch10_idx_0 = rtb_twih_j;
        rtb_Switch10_idx_1 = rtb_twil_i;
        rtb_Switch10_idx_2 = rtb_twdh_e;
        rtb_Switch10_idx_3 = rtb_twdl_p;
      }

      /* End of Switch: '<S60>/Switch10' */

      /* Switch: '<S60>/Switch4' incorporates:
       *  Switch: '<S60>/Switch5'
       */
      if (SWC_BCC_ConstB.RelationalOperator_e) {
        rtb_Gain11_pb = rtb_iu;
      } else if (SWC_BCC_ConstB.RelationalOperator1_m) {
        /* Switch: '<S60>/Switch5' */
        rtb_Gain11_pb = rtb_iv;
      } else {
        rtb_Gain11_pb = rtb_Product14;
      }

      /* End of Switch: '<S60>/Switch4' */

      /* Switch: '<S60>/Switch6' incorporates:
       *  Switch: '<S60>/Switch7'
       *  UnitDelay: '<S6>/Unit Delay1'
       *  UnitDelay: '<S6>/Unit Delay2'
       */
      if (SWC_BCC_ConstB.RelationalOperator2_b) {
        SWC_BCC_DW.UnitDelay_DSTATE_d = SWC_BCC_DW.UnitDelay2_DSTATE_o;
      } else {
        if (!SWC_BCC_ConstB.RelationalOperator3_l) {
          SWC_BCC_DW.UnitDelay_DSTATE_d = SWC_BCC_DW.UnitDelay1_DSTATE_f;
        }
      }

      /* End of Switch: '<S60>/Switch6' */

      /* Product: '<S60>/Divide' incorporates:
       *  Gain: '<S60>/Gain1'
       *  Lookup_n-D: '<S60>/2-D Lookup Table'
       */
      rtb_Switch1_d1 = 0.001F * look2_iflf_binlxpw(rtb_Gain11_pb,
        SWC_BCC_DW.UnitDelay_DSTATE_d, rtCP_uDLookupTable_bp01Data_l,
        rtCP_uDLookupTable_bp02Data_k, rtCP_uDLookupTable_tableData_l,
        rtCP_uDLookupTable_maxIndex_g, 17U) * rtb_TmpSignalConversionAtRP_S_e;

      /* Switch: '<S60>/Switch' incorporates:
       *  Constant: '<S60>/Constant'
       *  Constant: '<S96>/Constant'
       *  Constant: '<S96>/Constant1'
       *  Logic: '<S96>/Logical Operator'
       *  RelationalOperator: '<S96>/Relational Operator'
       *  RelationalOperator: '<S96>/Relational Operator1'
       */
      if ((rtb_Switch10_idx_0 >= CAL_TjDycMin_f32) && (rtb_Switch10_idx_0 <=
           CAL_TjDycMax_f32)) {
        rtb_Gain7_k = rtb_Switch1_d1;
      } else {
        rtb_Gain7_k = 0.0F;
      }

      /* End of Switch: '<S60>/Switch' */

      /* Product: '<S60>/Product23' incorporates:
       *  Constant: '<S111>/Constant'
       *  Constant: '<S111>/Constant1'
       *  Constant: '<S111>/Constant2'
       *  Constant: '<S111>/Constant3'
       *  Gain: '<S60>/Gain5'
       *  Product: '<S111>/Product'
       *  Product: '<S111>/Product1'
       *  Product: '<S60>/Product1'
       *  Sum: '<S111>/Add'
       *  Sum: '<S111>/Add1'
       *  Sum: '<S60>/Add1'
       */
      rtb_Add2_p = ((SWC_BCC_DW.UnitDelay_DSTATE_d * 2.8E-6F + 0.00072F) *
                    rtb_Gain11_pb + (SWC_BCC_DW.UnitDelay_DSTATE_d * -0.0012F +
        0.839F)) * 2.0F * rtb_Gain11_pb;

      /* Product: '<S60>/Product9' */
      rtb_Switch10_idx_0 *= rtb_Add2_p;

      /* Product: '<S60>/Product10' */
      rtb_Add2_p *= rtb_Switch10_idx_1;

      /* Switch: '<S60>/Switch1' incorporates:
       *  Constant: '<S108>/Constant'
       *  Constant: '<S108>/Constant1'
       *  Constant: '<S60>/Constant1'
       *  Logic: '<S108>/Logical Operator'
       *  RelationalOperator: '<S108>/Relational Operator'
       *  RelationalOperator: '<S108>/Relational Operator1'
       */
      if ((rtb_Switch10_idx_1 < CAL_TjDycMin_f32) || (rtb_Switch10_idx_1 >
           CAL_TjDycMax_f32)) {
        rtb_Switch1_d1 = 0.0F;
      }

      /* End of Switch: '<S60>/Switch1' */

      /* Product: '<S60>/Product24' incorporates:
       *  Constant: '<S111>/Constant4'
       *  Constant: '<S111>/Constant5'
       *  Constant: '<S111>/Constant6'
       *  Constant: '<S111>/Constant7'
       *  Gain: '<S60>/Gain6'
       *  Product: '<S111>/Product2'
       *  Product: '<S111>/Product3'
       *  Product: '<S60>/Product6'
       *  Sum: '<S111>/Add2'
       *  Sum: '<S111>/Add3'
       *  Sum: '<S60>/Add8'
       */
      rtb_Add4_n = ((SWC_BCC_DW.UnitDelay_DSTATE_d * 1.8E-6F + 0.0012F) *
                    rtb_Gain11_pb + (SWC_BCC_DW.UnitDelay_DSTATE_d * -0.0019F +
        1.061F)) * 2.0F * rtb_Gain11_pb;

      /* Product: '<S60>/Product11' */
      rtb_Switch10_idx_1 = rtb_Switch10_idx_2 * rtb_Add4_n;

      /* Lookup_n-D: '<S60>/2-D Lookup Table1' */
      rtb_Gain11_pb = look2_iflf_binlxpw(rtb_Gain11_pb,
        SWC_BCC_DW.UnitDelay_DSTATE_d, rtCP_uDLookupTable1_bp01Data_b,
        rtCP_uDLookupTable1_bp02Data_l, rtCP_uDLookupTable1_tableData_g,
        rtCP_uDLookupTable1_maxIndex_c, 17U);

      /* Product: '<S60>/Divide1' incorporates:
       *  Gain: '<S60>/Gain3'
       */
      rtb_Switch3_ma = 0.001F * rtb_Gain11_pb * rtb_TmpSignalConversionAtRP_S_e;

      /* Switch: '<S60>/Switch2' incorporates:
       *  Constant: '<S109>/Constant'
       *  Constant: '<S109>/Constant1'
       *  Constant: '<S60>/Constant2'
       *  Logic: '<S109>/Logical Operator'
       *  RelationalOperator: '<S109>/Relational Operator'
       *  RelationalOperator: '<S109>/Relational Operator1'
       */
      if ((rtb_Switch10_idx_2 >= CAL_TjDycMin_f32) && (rtb_Switch10_idx_2 <=
           CAL_TjDycMax_f32)) {
        SWC_BCC_DW.UnitDelay_DSTATE_d = rtb_Switch3_ma;
      } else {
        SWC_BCC_DW.UnitDelay_DSTATE_d = 0.0F;
      }

      /* End of Switch: '<S60>/Switch2' */

      /* Product: '<S60>/Product12' */
      rtb_Add4_n *= rtb_Switch10_idx_3;

      /* Switch: '<S60>/Switch3' incorporates:
       *  Constant: '<S110>/Constant'
       *  Constant: '<S110>/Constant1'
       *  Constant: '<S60>/Constant3'
       *  Logic: '<S110>/Logical Operator'
       *  RelationalOperator: '<S110>/Relational Operator'
       *  RelationalOperator: '<S110>/Relational Operator1'
       */
      if ((rtb_Switch10_idx_3 < CAL_TjDycMin_f32) || (rtb_Switch10_idx_3 >
           CAL_TjDycMax_f32)) {
        rtb_Switch3_ma = 0.0F;
      }

      /* End of Switch: '<S60>/Switch3' */

      /* Gain: '<S60>/Gain11' */
      rtb_Gain11_pb = 0.7F * rtb_TmpSignalConversionAtRP_S_l;

      /* Sum: '<S106>/Add' incorporates:
       *  Constant: '<S106>/Constant'
       *  Product: '<S106>/Product'
       *  Product: '<S106>/Product1'
       *  Sum: '<S106>/Add1'
       *  Sum: '<S60>/Add7'
       *  UnitDelay: '<S106>/Unit Delay'
       */
      VAR_VTjpwr_f32 = (((((((rtb_Switch10_idx_0 + rtb_Add2_p) +
        rtb_Switch10_idx_1) + rtb_Add4_n) + rtb_Gain7_k) + rtb_Switch1_d1) +
                         SWC_BCC_DW.UnitDelay_DSTATE_d) + rtb_Switch3_ma) *
        rtb_Gain11_pb + (1.0F - rtb_Gain11_pb) * SWC_BCC_DW.UnitDelay_DSTATE_mm;

      /* Sum: '<S60>/Add4' */
      rtb_Add4_n += rtb_Switch3_ma;

      /* Sum: '<S60>/Add' */
      rtb_Switch10_idx_0 += rtb_Gain7_k;

      /* Sum: '<S60>/Add2' */
      rtb_Add2_p += rtb_Switch1_d1;

      /* Sum: '<S60>/Add3' */
      rtb_Switch10_idx_1 += SWC_BCC_DW.UnitDelay_DSTATE_d;

      /* Gain: '<S98>/Gain9' */
      rtb_Gain7_k = 0.7F * rtb_TmpSignalConversionAtRP_S_l;

      /* Sum: '<S113>/Add' incorporates:
       *  Constant: '<S113>/Constant'
       *  Constant: '<S6>/Constant21'
       *  Constant: '<S6>/Constant22'
       *  Constant: '<S6>/Constant23'
       *  Product: '<S113>/Product'
       *  Product: '<S113>/Product1'
       *  Product: '<S98>/Product28'
       *  Product: '<S98>/Product3'
       *  Product: '<S98>/Product4'
       *  Product: '<S98>/Product5'
       *  Sum: '<S113>/Add1'
       *  Sum: '<S98>/Add6'
       *  UnitDelay: '<S113>/Unit Delay'
       */
      SWC_BCC_DW.UnitDelay_DSTATE_gm = (((rtb_Switch10_idx_0 * rtb_Product11 +
        rtb_Add2_p * CAL_TjrthLv4ilntc_f32) + rtb_Switch10_idx_1 *
        CAL_TjrthLv4dhntc_f32) + rtb_Add4_n * CAL_TjrthLv4dlntc_f32) *
        rtb_Gain7_k + (1.0F - rtb_Gain7_k) * SWC_BCC_DW.UnitDelay_DSTATE_gm;

      /* Switch: '<S60>/Switch8' incorporates:
       *  Switch: '<S60>/Switch9'
       */
      if (SWC_BCC_ConstB.RelationalOperator4_b) {
        rtb_Switch10_idx_2 = rtb_TmpSignalConversionAtRP_SWC;
      } else if (SWC_BCC_ConstB.RelationalOperator5_i) {
        /* Switch: '<S60>/Switch9' */
        rtb_Switch10_idx_2 = rtb_TmpSignalConversionAtRP_S_n;
      } else {
        rtb_Switch10_idx_2 = rtb_TmpSignalConversionAtRP__br;
      }

      /* End of Switch: '<S60>/Switch8' */

      /* Sum: '<S60>/Add10' incorporates:
       *  UnitDelay: '<S113>/Unit Delay'
       */
      VAR_VCoolantTj_f32 = rtb_Switch10_idx_2 - SWC_BCC_DW.UnitDelay_DSTATE_gm;

      /* Gain: '<S100>/Gain' */
      rtb_Gain7_k = 1000.0F * rtb_TmpSignalConversionAtRP_S_l;

      /* Sum: '<S116>/Add' incorporates:
       *  Constant: '<S100>/Constant12'
       *  Constant: '<S116>/Constant'
       *  Product: '<S100>/Product37'
       *  Product: '<S116>/Product'
       *  Product: '<S116>/Product1'
       *  Sum: '<S116>/Add1'
       *  UnitDelay: '<S116>/Unit Delay'
       */
      SWC_BCC_DW.UnitDelay_DSTATE_lx = rtb_Add2_p * CAL_TjLv1Act_f32 *
        rtb_Gain7_k + (1.0F - rtb_Gain7_k) * SWC_BCC_DW.UnitDelay_DSTATE_lx;

      /* Gain: '<S100>/Gain2' */
      rtb_Gain7_k = 33.3F * rtb_TmpSignalConversionAtRP_S_l;

      /* Sum: '<S115>/Add' incorporates:
       *  Constant: '<S100>/Constant14'
       *  Constant: '<S115>/Constant'
       *  Product: '<S100>/Product39'
       *  Product: '<S115>/Product'
       *  Product: '<S115>/Product1'
       *  Sum: '<S115>/Add1'
       *  UnitDelay: '<S115>/Unit Delay'
       */
      SWC_BCC_DW.UnitDelay_DSTATE_as = rtb_Add2_p * CAL_TjLv2Act_f32 *
        rtb_Gain7_k + (1.0F - rtb_Gain7_k) * SWC_BCC_DW.UnitDelay_DSTATE_as;

      /* Gain: '<S100>/Gain7' */
      rtb_Gain7_k = 4.0F * rtb_TmpSignalConversionAtRP_S_l;

      /* Sum: '<S117>/Add' incorporates:
       *  Constant: '<S100>/Constant20'
       *  Constant: '<S100>/Constant4'
       *  Constant: '<S117>/Constant'
       *  Product: '<S100>/Product29'
       *  Product: '<S100>/Product30'
       *  Product: '<S117>/Product'
       *  Product: '<S117>/Product1'
       *  Sum: '<S100>/Add11'
       *  Sum: '<S117>/Add1'
       *  UnitDelay: '<S117>/Unit Delay'
       */
      SWC_BCC_DW.UnitDelay_DSTATE_h2 = (rtb_Add2_p * CAL_TjLv3Act_f32 +
        rtb_Add4_n * CAL_TjLv3Pas_f32) * rtb_Gain7_k + (1.0F - rtb_Gain7_k) *
        SWC_BCC_DW.UnitDelay_DSTATE_h2;

      /* Gain: '<S99>/Gain8' */
      rtb_Gain7_k = 0.7F * rtb_TmpSignalConversionAtRP_S_l;

      /* Sum: '<S114>/Add' incorporates:
       *  Constant: '<S114>/Constant'
       *  Constant: '<S6>/Constant13'
       *  Constant: '<S6>/Constant17'
       *  Constant: '<S6>/Constant4'
       *  Constant: '<S6>/Constant9'
       *  Product: '<S114>/Product'
       *  Product: '<S114>/Product1'
       *  Product: '<S99>/Product17'
       *  Product: '<S99>/Product2'
       *  Product: '<S99>/Product21'
       *  Product: '<S99>/Product7'
       *  Sum: '<S114>/Add1'
       *  Sum: '<S99>/Add5'
       *  UnitDelay: '<S114>/Unit Delay'
       */
      SWC_BCC_DW.UnitDelay_DSTATE_ik = (((rtb_Switch10_idx_0 *
        CAL_TjrthLv4ihil_f32 + rtb_Add2_p * CAL_TjrthLv4ilil_f32) +
        rtb_Switch10_idx_1 * CAL_TjrthLv4dhil_f32) + rtb_Add4_n *
        CAL_TjrthLv4dlil_f32) * rtb_Gain7_k + (1.0F - rtb_Gain7_k) *
        SWC_BCC_DW.UnitDelay_DSTATE_ik;

      /* Sum: '<S60>/Add12' incorporates:
       *  Sum: '<S60>/Add11'
       *  UnitDelay: '<S114>/Unit Delay'
       *  UnitDelay: '<S115>/Unit Delay'
       *  UnitDelay: '<S116>/Unit Delay'
       *  UnitDelay: '<S117>/Unit Delay'
       */
      VAR_VilTjtIGBT_f32 = (((SWC_BCC_DW.UnitDelay_DSTATE_lx +
        SWC_BCC_DW.UnitDelay_DSTATE_as) + SWC_BCC_DW.UnitDelay_DSTATE_h2) +
                            SWC_BCC_DW.UnitDelay_DSTATE_ik) + VAR_VCoolantTj_f32;

      /* Gain: '<S102>/Gain' */
      rtb_Gain7_k = 1000.0F * rtb_TmpSignalConversionAtRP_S_l;

      /* Sum: '<S120>/Add' incorporates:
       *  Constant: '<S102>/Constant12'
       *  Constant: '<S120>/Constant'
       *  Product: '<S102>/Product37'
       *  Product: '<S120>/Product'
       *  Product: '<S120>/Product1'
       *  Sum: '<S120>/Add1'
       *  UnitDelay: '<S120>/Unit Delay'
       */
      SWC_BCC_DW.UnitDelay_DSTATE_fa = rtb_Add4_n * CAL_TjLv1Act_f32 *
        rtb_Gain7_k + (1.0F - rtb_Gain7_k) * SWC_BCC_DW.UnitDelay_DSTATE_fa;

      /* Gain: '<S102>/Gain2' */
      rtb_Gain7_k = 33.3F * rtb_TmpSignalConversionAtRP_S_l;

      /* Sum: '<S119>/Add' incorporates:
       *  Constant: '<S102>/Constant14'
       *  Constant: '<S119>/Constant'
       *  Product: '<S102>/Product39'
       *  Product: '<S119>/Product'
       *  Product: '<S119>/Product1'
       *  Sum: '<S119>/Add1'
       *  UnitDelay: '<S119>/Unit Delay'
       */
      SWC_BCC_DW.UnitDelay_DSTATE_n2 = rtb_Add4_n * CAL_TjLv2Act_f32 *
        rtb_Gain7_k + (1.0F - rtb_Gain7_k) * SWC_BCC_DW.UnitDelay_DSTATE_n2;

      /* Gain: '<S102>/Gain7' */
      rtb_Gain7_k = 4.0F * rtb_TmpSignalConversionAtRP_S_l;

      /* Sum: '<S121>/Add' incorporates:
       *  Constant: '<S102>/Constant20'
       *  Constant: '<S102>/Constant4'
       *  Constant: '<S121>/Constant'
       *  Product: '<S102>/Product29'
       *  Product: '<S102>/Product30'
       *  Product: '<S121>/Product'
       *  Product: '<S121>/Product1'
       *  Sum: '<S102>/Add11'
       *  Sum: '<S121>/Add1'
       *  UnitDelay: '<S121>/Unit Delay'
       */
      SWC_BCC_DW.UnitDelay_DSTATE_nt = (rtb_Add4_n * CAL_TjLv3Act_f32 +
        rtb_Add2_p * CAL_TjLv3Pas_f32) * rtb_Gain7_k + (1.0F - rtb_Gain7_k) *
        SWC_BCC_DW.UnitDelay_DSTATE_nt;

      /* Gain: '<S101>/Gain8' */
      rtb_Gain7_k = 0.7F * rtb_TmpSignalConversionAtRP_S_l;

      /* Sum: '<S118>/Add' incorporates:
       *  Constant: '<S118>/Constant'
       *  Constant: '<S6>/Constant11'
       *  Constant: '<S6>/Constant15'
       *  Constant: '<S6>/Constant19'
       *  Constant: '<S6>/Constant7'
       *  Product: '<S101>/Product17'
       *  Product: '<S101>/Product2'
       *  Product: '<S101>/Product21'
       *  Product: '<S101>/Product7'
       *  Product: '<S118>/Product'
       *  Product: '<S118>/Product1'
       *  Sum: '<S101>/Add5'
       *  Sum: '<S118>/Add1'
       *  UnitDelay: '<S118>/Unit Delay'
       */
      SWC_BCC_DW.UnitDelay_DSTATE_a5 = (((rtb_Switch10_idx_0 *
        CAL_TjrthLv4ihdl_f32 + rtb_Add2_p * CAL_TjrthLv4ildl_f32) +
        rtb_Switch10_idx_1 * CAL_TjrthLv4dhdl_f32) + rtb_Add4_n *
        CAL_TjrthLv4dldl_f32) * rtb_Gain7_k + (1.0F - rtb_Gain7_k) *
        SWC_BCC_DW.UnitDelay_DSTATE_a5;

      /* Sum: '<S60>/Add14' incorporates:
       *  Sum: '<S60>/Add13'
       *  UnitDelay: '<S118>/Unit Delay'
       *  UnitDelay: '<S119>/Unit Delay'
       *  UnitDelay: '<S120>/Unit Delay'
       *  UnitDelay: '<S121>/Unit Delay'
       */
      VAR_VdlTjtIGBT_f32 = (((SWC_BCC_DW.UnitDelay_DSTATE_fa +
        SWC_BCC_DW.UnitDelay_DSTATE_n2) + SWC_BCC_DW.UnitDelay_DSTATE_nt) +
                            SWC_BCC_DW.UnitDelay_DSTATE_a5) + VAR_VCoolantTj_f32;

      /* Gain: '<S104>/Gain' */
      rtb_Gain7_k = 1000.0F * rtb_TmpSignalConversionAtRP_S_l;

      /* Sum: '<S124>/Add' incorporates:
       *  Constant: '<S104>/Constant12'
       *  Constant: '<S124>/Constant'
       *  Product: '<S104>/Product37'
       *  Product: '<S124>/Product'
       *  Product: '<S124>/Product1'
       *  Sum: '<S124>/Add1'
       *  UnitDelay: '<S124>/Unit Delay'
       */
      SWC_BCC_DW.UnitDelay_DSTATE_gd = rtb_Switch10_idx_1 * CAL_TjLv1Act_f32 *
        rtb_Gain7_k + (1.0F - rtb_Gain7_k) * SWC_BCC_DW.UnitDelay_DSTATE_gd;

      /* Gain: '<S104>/Gain2' */
      rtb_Gain7_k = 33.3F * rtb_TmpSignalConversionAtRP_S_l;

      /* Sum: '<S123>/Add' incorporates:
       *  Constant: '<S104>/Constant14'
       *  Constant: '<S123>/Constant'
       *  Product: '<S104>/Product39'
       *  Product: '<S123>/Product'
       *  Product: '<S123>/Product1'
       *  Sum: '<S123>/Add1'
       *  UnitDelay: '<S123>/Unit Delay'
       */
      SWC_BCC_DW.UnitDelay_DSTATE_pk = rtb_Switch10_idx_1 * CAL_TjLv2Act_f32 *
        rtb_Gain7_k + (1.0F - rtb_Gain7_k) * SWC_BCC_DW.UnitDelay_DSTATE_pk;

      /* Gain: '<S104>/Gain7' */
      rtb_Gain7_k = 4.0F * rtb_TmpSignalConversionAtRP_S_l;

      /* Sum: '<S125>/Add' incorporates:
       *  Constant: '<S104>/Constant20'
       *  Constant: '<S104>/Constant4'
       *  Constant: '<S125>/Constant'
       *  Product: '<S104>/Product29'
       *  Product: '<S104>/Product30'
       *  Product: '<S125>/Product'
       *  Product: '<S125>/Product1'
       *  Sum: '<S104>/Add11'
       *  Sum: '<S125>/Add1'
       *  UnitDelay: '<S125>/Unit Delay'
       */
      SWC_BCC_DW.UnitDelay_DSTATE_hw = (rtb_Switch10_idx_1 * CAL_TjLv3Act_f32 +
        rtb_Switch10_idx_0 * CAL_TjLv3Pas_f32) * rtb_Gain7_k + (1.0F -
        rtb_Gain7_k) * SWC_BCC_DW.UnitDelay_DSTATE_hw;

      /* Gain: '<S103>/Gain8' */
      rtb_Gain7_k = 0.7F * rtb_TmpSignalConversionAtRP_S_l;

      /* Sum: '<S122>/Add' incorporates:
       *  Constant: '<S122>/Constant'
       *  Constant: '<S6>/Constant10'
       *  Constant: '<S6>/Constant14'
       *  Constant: '<S6>/Constant18'
       *  Constant: '<S6>/Constant5'
       *  Product: '<S103>/Product17'
       *  Product: '<S103>/Product2'
       *  Product: '<S103>/Product21'
       *  Product: '<S103>/Product7'
       *  Product: '<S122>/Product'
       *  Product: '<S122>/Product1'
       *  Sum: '<S103>/Add5'
       *  Sum: '<S122>/Add1'
       *  UnitDelay: '<S122>/Unit Delay'
       */
      SWC_BCC_DW.UnitDelay_DSTATE_dj = (((rtb_Switch10_idx_0 *
        CAL_TjrthLv4ihdh_f32 + rtb_Add2_p * CAL_TjrthLv4ildh_f32) +
        rtb_Switch10_idx_1 * CAL_TjrthLv4dhdh_f32) + rtb_Add4_n *
        CAL_TjrthLv4dldh_f32) * rtb_Gain7_k + (1.0F - rtb_Gain7_k) *
        SWC_BCC_DW.UnitDelay_DSTATE_dj;

      /* Sum: '<S60>/Add6' incorporates:
       *  Sum: '<S60>/Add5'
       *  UnitDelay: '<S122>/Unit Delay'
       *  UnitDelay: '<S123>/Unit Delay'
       *  UnitDelay: '<S124>/Unit Delay'
       *  UnitDelay: '<S125>/Unit Delay'
       */
      VAR_VdhTjtIGBT_f32 = (((SWC_BCC_DW.UnitDelay_DSTATE_gd +
        SWC_BCC_DW.UnitDelay_DSTATE_pk) + SWC_BCC_DW.UnitDelay_DSTATE_hw) +
                            SWC_BCC_DW.UnitDelay_DSTATE_dj) + VAR_VCoolantTj_f32;

      /* Gain: '<S105>/Gain' */
      rtb_Gain7_k = 1000.0F * rtb_TmpSignalConversionAtRP_S_l;

      /* Sum: '<S127>/Add' incorporates:
       *  Constant: '<S105>/Constant12'
       *  Constant: '<S127>/Constant'
       *  Product: '<S105>/Product37'
       *  Product: '<S127>/Product'
       *  Product: '<S127>/Product1'
       *  Sum: '<S127>/Add1'
       *  UnitDelay: '<S127>/Unit Delay'
       */
      SWC_BCC_DW.UnitDelay_DSTATE_cm = rtb_Switch10_idx_0 * CAL_TjLv1Act_f32 *
        rtb_Gain7_k + (1.0F - rtb_Gain7_k) * SWC_BCC_DW.UnitDelay_DSTATE_cm;

      /* Gain: '<S105>/Gain2' */
      rtb_Gain7_k = 33.3F * rtb_TmpSignalConversionAtRP_S_l;

      /* Sum: '<S126>/Add' incorporates:
       *  Constant: '<S105>/Constant14'
       *  Constant: '<S126>/Constant'
       *  Product: '<S105>/Product39'
       *  Product: '<S126>/Product'
       *  Product: '<S126>/Product1'
       *  Sum: '<S126>/Add1'
       *  UnitDelay: '<S126>/Unit Delay'
       */
      SWC_BCC_DW.UnitDelay_DSTATE_cu = rtb_Switch10_idx_0 * CAL_TjLv2Act_f32 *
        rtb_Gain7_k + (1.0F - rtb_Gain7_k) * SWC_BCC_DW.UnitDelay_DSTATE_cu;

      /* Gain: '<S105>/Gain7' */
      rtb_Gain7_k = 4.0F * rtb_TmpSignalConversionAtRP_S_l;

      /* Sum: '<S128>/Add' incorporates:
       *  Constant: '<S105>/Constant20'
       *  Constant: '<S105>/Constant4'
       *  Constant: '<S128>/Constant'
       *  Product: '<S105>/Product29'
       *  Product: '<S105>/Product30'
       *  Product: '<S128>/Product'
       *  Product: '<S128>/Product1'
       *  Sum: '<S105>/Add11'
       *  Sum: '<S128>/Add1'
       *  UnitDelay: '<S128>/Unit Delay'
       */
      SWC_BCC_DW.UnitDelay_DSTATE_bt = (rtb_Switch10_idx_0 * CAL_TjLv3Act_f32 +
        rtb_Switch10_idx_1 * CAL_TjLv3Pas_f32) * rtb_Gain7_k + (1.0F -
        rtb_Gain7_k) * SWC_BCC_DW.UnitDelay_DSTATE_bt;

      /* Sum: '<S97>/Add5' incorporates:
       *  Constant: '<S6>/Constant16'
       *  Constant: '<S6>/Constant8'
       *  Product: '<S97>/Product17'
       *  Product: '<S97>/Product2'
       *  Product: '<S97>/Product21'
       *  Product: '<S97>/Product7'
       */
      rtb_Switch10_idx_2 = ((rtb_Switch10_idx_0 * rtb_Product10_l + rtb_Add2_p *
        CAL_TjrthLv4ilih_f32) + rtb_Switch10_idx_1 * rtb_Switch_i) + rtb_Add4_n *
        CAL_TjrthLv4dlih_f32;

      /* Gain: '<S97>/Gain8' */
      rtb_Switch10_idx_1 = 0.7F * rtb_TmpSignalConversionAtRP_S_l;

      /* Sum: '<S112>/Add' incorporates:
       *  Constant: '<S112>/Constant'
       *  Product: '<S112>/Product'
       *  Product: '<S112>/Product1'
       *  Sum: '<S112>/Add1'
       *  UnitDelay: '<S112>/Unit Delay'
       */
      SWC_BCC_DW.UnitDelay_DSTATE_gdo = (1.0F - rtb_Switch10_idx_1) *
        SWC_BCC_DW.UnitDelay_DSTATE_gdo + rtb_Switch10_idx_2 *
        rtb_Switch10_idx_1;

      /* Sum: '<S60>/Add9' incorporates:
       *  Sum: '<S60>/Add15'
       *  UnitDelay: '<S112>/Unit Delay'
       *  UnitDelay: '<S126>/Unit Delay'
       *  UnitDelay: '<S127>/Unit Delay'
       *  UnitDelay: '<S128>/Unit Delay'
       */
      VAR_VihTjtIGBT_f32 = (((SWC_BCC_DW.UnitDelay_DSTATE_cm +
        SWC_BCC_DW.UnitDelay_DSTATE_cu) + SWC_BCC_DW.UnitDelay_DSTATE_bt) +
                            SWC_BCC_DW.UnitDelay_DSTATE_gdo) +
        VAR_VCoolantTj_f32;

      /* MinMax: '<S60>/Max' incorporates:
       *  UnitDelay: '<S6>/Unit Delay'
       */
      SWC_BCC_DW.UnitDelay_DSTATE_d = fmaxf(fmaxf(fmaxf(VAR_VihTjtIGBT_f32,
        VAR_VdhTjtIGBT_f32), VAR_VilTjtIGBT_f32), VAR_VdlTjtIGBT_f32);

      /* Sum: '<S107>/Add' incorporates:
       *  Constant: '<S107>/Constant'
       *  Product: '<S107>/Product'
       *  Product: '<S107>/Product1'
       *  Sum: '<S107>/Add1'
       *  UnitDelay: '<S107>/Unit Delay'
       */
      SWC_BCC_DW.UnitDelay_DSTATE_et = (1.0F - rtb_Product9_j) *
        SWC_BCC_DW.UnitDelay_DSTATE_et + VAR_VCoolantTj_f32 * rtb_Product9_j;

      /* Update for UnitDelay: '<S106>/Unit Delay' */
      SWC_BCC_DW.UnitDelay_DSTATE_mm = VAR_VTjpwr_f32;
    } else {
      SWC_BCC_DW.uTjCal2_MODE = false;
    }

    /* End of Outputs for SubSystem: '<S6>/uTjCal2' */

    /* Sum: '<S6>/Add1' incorporates:
     *  Constant: '<S55>/Constant'
     *  MinMax: '<S6>/Max1'
     *  RelationalOperator: '<S55>/Compare'
     *  UnitDelay: '<S107>/Unit Delay'
     *  UnitDelay: '<S135>/Unit Delay'
     *  UnitDelay: '<S6>/Unit Delay3'
     */
    SWC_BCC_B.Add1 = fmaxf(fmaxf(SWC_BCC_DW.UnitDelay3_DSTATE,
      SWC_BCC_DW.UnitDelay_DSTATE_et), SWC_BCC_DW.UnitDelay_DSTATE_m);

    /* Outputs for Enabled SubSystem: '<S61>/Subsystem15' incorporates:
     *  EnablePort: '<S132>/Enable'
     */
    /* Outputs for Enabled SubSystem: '<S6>/uTjCal1' incorporates:
     *  EnablePort: '<S59>/Enable'
     */
    if (rtb_TmpSignalConversionAtRP_S_l >= CAL_tiPwmLim_f32) {
      if (!SWC_BCC_DW.uTjCal1_MODE) {
        /* InitializeConditions for UnitDelay: '<S73>/Unit Delay' */
        SWC_BCC_DW.UnitDelay_DSTATE_ad = 0.0F;

        /* InitializeConditions for UnitDelay: '<S80>/Unit Delay' */
        SWC_BCC_DW.UnitDelay_DSTATE_no = 0.0F;

        /* InitializeConditions for UnitDelay: '<S83>/Unit Delay' */
        SWC_BCC_DW.UnitDelay_DSTATE_m4 = 0.0F;

        /* InitializeConditions for UnitDelay: '<S82>/Unit Delay' */
        SWC_BCC_DW.UnitDelay_DSTATE_dt = 0.0F;

        /* InitializeConditions for UnitDelay: '<S84>/Unit Delay' */
        SWC_BCC_DW.UnitDelay_DSTATE_bb = 0.0F;

        /* InitializeConditions for UnitDelay: '<S81>/Unit Delay' */
        SWC_BCC_DW.UnitDelay_DSTATE_e4 = 0.0F;

        /* InitializeConditions for UnitDelay: '<S87>/Unit Delay' */
        SWC_BCC_DW.UnitDelay_DSTATE_pt = 0.0F;

        /* InitializeConditions for UnitDelay: '<S86>/Unit Delay' */
        SWC_BCC_DW.UnitDelay_DSTATE_bw = 0.0F;

        /* InitializeConditions for UnitDelay: '<S88>/Unit Delay' */
        SWC_BCC_DW.UnitDelay_DSTATE_n2r = 0.0F;

        /* InitializeConditions for UnitDelay: '<S85>/Unit Delay' */
        SWC_BCC_DW.UnitDelay_DSTATE_ar = 0.0F;

        /* InitializeConditions for UnitDelay: '<S91>/Unit Delay' */
        SWC_BCC_DW.UnitDelay_DSTATE_k0 = 0.0F;

        /* InitializeConditions for UnitDelay: '<S90>/Unit Delay' */
        SWC_BCC_DW.UnitDelay_DSTATE_lk = 0.0F;

        /* InitializeConditions for UnitDelay: '<S92>/Unit Delay' */
        SWC_BCC_DW.UnitDelay_DSTATE_o = 0.0F;

        /* InitializeConditions for UnitDelay: '<S89>/Unit Delay' */
        SWC_BCC_DW.UnitDelay_DSTATE_jg = 0.0F;

        /* InitializeConditions for UnitDelay: '<S94>/Unit Delay' */
        SWC_BCC_DW.UnitDelay_DSTATE_c3 = 0.0F;

        /* InitializeConditions for UnitDelay: '<S93>/Unit Delay' */
        SWC_BCC_DW.UnitDelay_DSTATE_cg = 0.0F;

        /* InitializeConditions for UnitDelay: '<S95>/Unit Delay' */
        SWC_BCC_DW.UnitDelay_DSTATE_ip = 0.0F;

        /* InitializeConditions for UnitDelay: '<S79>/Unit Delay' */
        SWC_BCC_DW.UnitDelay_DSTATE_eu = 0.0F;

        /* InitializeConditions for UnitDelay: '<S74>/Unit Delay' */
        SWC_BCC_DW.UnitDelay_DSTATE_ej = 0.0F;
        SWC_BCC_DW.uTjCal1_MODE = true;
      }

      /* Switch: '<S59>/Switch10' incorporates:
       *  Constant: '<S59>/Constant19'
       *  Constant: '<S59>/Constant6'
       *  Constant: '<S59>/Constant7'
       *  RelationalOperator: '<S59>/Relational Operator6'
       *  RelationalOperator: '<S59>/Relational Operator7'
       *  Switch: '<S59>/Switch11'
       */
      if (CAL_TjstUVW_u8 == 1) {
        rtb_Switch10_idx_0 = rtb_TmpSignalConversionAtRP__ou;
        rtb_Switch10_idx_1 = rtb_TmpSignalConversionAtRP_S_h;
        rtb_Switch10_idx_2 = rtb_TmpSignalConversionAtRP_S_d;
        rtb_Switch10_idx_3 = rtb_Switch2_a;
      } else if (CAL_TjstUVW_u8 == 2) {
        /* Switch: '<S59>/Switch11' */
        rtb_Switch10_idx_0 = rtb_Switch4_g;
        rtb_Switch10_idx_1 = rtb_Product3;
        rtb_Switch10_idx_2 = rtb_tvdh_e;
        rtb_Switch10_idx_3 = rtb_tvdl_j;
      } else {
        rtb_Switch10_idx_0 = rtb_twih_j;
        rtb_Switch10_idx_1 = rtb_twil_i;
        rtb_Switch10_idx_2 = rtb_twdh_e;
        rtb_Switch10_idx_3 = rtb_twdl_p;
      }

      /* End of Switch: '<S59>/Switch10' */

      /* Switch: '<S59>/Switch4' incorporates:
       *  Switch: '<S59>/Switch5'
       */
      if (SWC_BCC_ConstB.RelationalOperator_g) {
        rtb_Product14 = rtb_iu;
      } else {
        if (SWC_BCC_ConstB.RelationalOperator1_k) {
          /* Switch: '<S59>/Switch5' */
          rtb_Product14 = rtb_iv;
        }
      }

      /* End of Switch: '<S59>/Switch4' */

      /* Switch: '<S59>/Switch6' incorporates:
       *  Switch: '<S59>/Switch7'
       *  UnitDelay: '<S6>/Unit Delay2'
       */
      if (SWC_BCC_ConstB.RelationalOperator2_k) {
        SWC_BCC_DW.UnitDelay1_DSTATE_f = SWC_BCC_DW.UnitDelay2_DSTATE_o;
      } else {
        if (SWC_BCC_ConstB.RelationalOperator3_d) {
          /* Switch: '<S59>/Switch7' */
          SWC_BCC_DW.UnitDelay1_DSTATE_f = rtb_dycmax;
        }
      }

      /* End of Switch: '<S59>/Switch6' */

      /* Product: '<S59>/Divide' incorporates:
       *  Gain: '<S59>/Gain1'
       *  Lookup_n-D: '<S59>/2-D Lookup Table'
       */
      rtb_Product3 = 0.001F * look2_iflf_binlxpw(rtb_Product14,
        SWC_BCC_DW.UnitDelay1_DSTATE_f, rtCP_uDLookupTable_bp01Data,
        rtCP_uDLookupTable_bp02Data, rtCP_uDLookupTable_tableData,
        rtCP_uDLookupTable_maxIndex, 17U) * rtb_TmpSignalConversionAtRP_S_e;

      /* Switch: '<S59>/Switch' incorporates:
       *  Constant: '<S59>/Constant'
       *  Constant: '<S63>/Constant'
       *  Constant: '<S63>/Constant1'
       *  Logic: '<S63>/Logical Operator'
       *  RelationalOperator: '<S63>/Relational Operator'
       *  RelationalOperator: '<S63>/Relational Operator1'
       */
      if ((rtb_Switch10_idx_0 >= CAL_TjDycMin_f32) && (rtb_Switch10_idx_0 <=
           CAL_TjDycMax_f32)) {
        rtb_TmpSignalConversionAtRP__ou = rtb_Product3;
      } else {
        rtb_TmpSignalConversionAtRP__ou = 0.0F;
      }

      /* End of Switch: '<S59>/Switch' */

      /* Product: '<S59>/Product23' incorporates:
       *  Constant: '<S78>/Constant'
       *  Constant: '<S78>/Constant1'
       *  Constant: '<S78>/Constant2'
       *  Constant: '<S78>/Constant3'
       *  Gain: '<S59>/Gain5'
       *  Product: '<S59>/Product1'
       *  Product: '<S78>/Product'
       *  Product: '<S78>/Product1'
       *  Sum: '<S59>/Add1'
       *  Sum: '<S78>/Add'
       *  Sum: '<S78>/Add1'
       */
      rtb_TmpSignalConversionAtRP_S_h = ((SWC_BCC_DW.UnitDelay1_DSTATE_f *
        2.8E-6F + 0.00072F) * rtb_Product14 + (SWC_BCC_DW.UnitDelay1_DSTATE_f *
        -0.0012F + 0.839F)) * 2.0F * rtb_Product14;

      /* Product: '<S59>/Product9' */
      rtb_TmpSignalConversionAtRP_S_d = rtb_Switch10_idx_0 *
        rtb_TmpSignalConversionAtRP_S_h;

      /* Product: '<S59>/Product10' */
      rtb_TmpSignalConversionAtRP_S_h *= rtb_Switch10_idx_1;

      /* Switch: '<S59>/Switch1' incorporates:
       *  Constant: '<S59>/Constant1'
       *  Constant: '<S75>/Constant'
       *  Constant: '<S75>/Constant1'
       *  Logic: '<S75>/Logical Operator'
       *  RelationalOperator: '<S75>/Relational Operator'
       *  RelationalOperator: '<S75>/Relational Operator1'
       */
      if ((rtb_Switch10_idx_1 < CAL_TjDycMin_f32) || (rtb_Switch10_idx_1 >
           CAL_TjDycMax_f32)) {
        rtb_Product3 = 0.0F;
      }

      /* End of Switch: '<S59>/Switch1' */

      /* Product: '<S59>/Product24' incorporates:
       *  Constant: '<S78>/Constant4'
       *  Constant: '<S78>/Constant5'
       *  Constant: '<S78>/Constant6'
       *  Constant: '<S78>/Constant7'
       *  Gain: '<S59>/Gain6'
       *  Product: '<S59>/Product6'
       *  Product: '<S78>/Product2'
       *  Product: '<S78>/Product3'
       *  Sum: '<S59>/Add8'
       *  Sum: '<S78>/Add2'
       *  Sum: '<S78>/Add3'
       */
      rtb_Switch4_g = ((SWC_BCC_DW.UnitDelay1_DSTATE_f * 1.8E-6F + 0.0012F) *
                       rtb_Product14 + (SWC_BCC_DW.UnitDelay1_DSTATE_f *
        -0.0019F + 1.061F)) * 2.0F * rtb_Product14;

      /* Product: '<S59>/Product11' */
      rtb_Switch2_a = rtb_Switch10_idx_2 * rtb_Switch4_g;

      /* Lookup_n-D: '<S59>/2-D Lookup Table1' */
      rtb_Product14 = look2_iflf_binlxpw(rtb_Product14,
        SWC_BCC_DW.UnitDelay1_DSTATE_f, rtCP_uDLookupTable1_bp01Data,
        rtCP_uDLookupTable1_bp02Data, rtCP_uDLookupTable1_tableData,
        rtCP_uDLookupTable1_maxIndex, 17U);

      /* Product: '<S59>/Divide1' incorporates:
       *  Gain: '<S59>/Gain3'
       */
      rtb_TmpSignalConversionAtRP_S_e *= 0.001F * rtb_Product14;

      /* Switch: '<S59>/Switch2' incorporates:
       *  Constant: '<S59>/Constant2'
       *  Constant: '<S76>/Constant'
       *  Constant: '<S76>/Constant1'
       *  Logic: '<S76>/Logical Operator'
       *  RelationalOperator: '<S76>/Relational Operator'
       *  RelationalOperator: '<S76>/Relational Operator1'
       */
      if ((rtb_Switch10_idx_2 >= CAL_TjDycMin_f32) && (rtb_Switch10_idx_2 <=
           CAL_TjDycMax_f32)) {
        SWC_BCC_DW.UnitDelay1_DSTATE_f = rtb_TmpSignalConversionAtRP_S_e;
      } else {
        SWC_BCC_DW.UnitDelay1_DSTATE_f = 0.0F;
      }

      /* End of Switch: '<S59>/Switch2' */

      /* Product: '<S59>/Product12' */
      rtb_Switch4_g *= rtb_Switch10_idx_3;

      /* Switch: '<S59>/Switch3' incorporates:
       *  Constant: '<S59>/Constant3'
       *  Constant: '<S77>/Constant'
       *  Constant: '<S77>/Constant1'
       *  Logic: '<S77>/Logical Operator'
       *  RelationalOperator: '<S77>/Relational Operator'
       *  RelationalOperator: '<S77>/Relational Operator1'
       */
      if ((rtb_Switch10_idx_3 < CAL_TjDycMin_f32) || (rtb_Switch10_idx_3 >
           CAL_TjDycMax_f32)) {
        rtb_TmpSignalConversionAtRP_S_e = 0.0F;
      }

      /* End of Switch: '<S59>/Switch3' */

      /* Gain: '<S59>/Gain11' */
      rtb_Product14 = 0.7F * rtb_TmpSignalConversionAtRP_S_l;

      /* Sum: '<S73>/Add' incorporates:
       *  Constant: '<S73>/Constant'
       *  Product: '<S73>/Product'
       *  Product: '<S73>/Product1'
       *  Sum: '<S59>/Add7'
       *  Sum: '<S73>/Add1'
       *  UnitDelay: '<S73>/Unit Delay'
       */
      VAR_UTjpwr_f32 = (((((((rtb_TmpSignalConversionAtRP_S_d +
        rtb_TmpSignalConversionAtRP_S_h) + rtb_Switch2_a) + rtb_Switch4_g) +
                           rtb_TmpSignalConversionAtRP__ou) + rtb_Product3) +
                         SWC_BCC_DW.UnitDelay1_DSTATE_f) +
                        rtb_TmpSignalConversionAtRP_S_e) * rtb_Product14 + (1.0F
        - rtb_Product14) * SWC_BCC_DW.UnitDelay_DSTATE_ad;

      /* Sum: '<S59>/Add4' */
      rtb_Switch4_g += rtb_TmpSignalConversionAtRP_S_e;

      /* Sum: '<S59>/Add' */
      rtb_TmpSignalConversionAtRP_S_d += rtb_TmpSignalConversionAtRP__ou;

      /* Sum: '<S59>/Add2' */
      rtb_TmpSignalConversionAtRP_S_h += rtb_Product3;

      /* Sum: '<S59>/Add3' */
      rtb_Switch2_a += SWC_BCC_DW.UnitDelay1_DSTATE_f;

      /* Gain: '<S65>/Gain9' */
      rtb_TmpSignalConversionAtRP__ou = 0.7F * rtb_TmpSignalConversionAtRP_S_l;

      /* Sum: '<S80>/Add' incorporates:
       *  Constant: '<S6>/Constant21'
       *  Constant: '<S6>/Constant22'
       *  Constant: '<S6>/Constant23'
       *  Constant: '<S80>/Constant'
       *  Product: '<S65>/Product28'
       *  Product: '<S65>/Product3'
       *  Product: '<S65>/Product4'
       *  Product: '<S65>/Product5'
       *  Product: '<S80>/Product'
       *  Product: '<S80>/Product1'
       *  Sum: '<S65>/Add6'
       *  Sum: '<S80>/Add1'
       *  UnitDelay: '<S80>/Unit Delay'
       */
      SWC_BCC_DW.UnitDelay_DSTATE_no = (((rtb_TmpSignalConversionAtRP_S_d *
        rtb_Product11 + rtb_TmpSignalConversionAtRP_S_h * CAL_TjrthLv4ilntc_f32)
        + rtb_Switch2_a * CAL_TjrthLv4dhntc_f32) + rtb_Switch4_g *
        CAL_TjrthLv4dlntc_f32) * rtb_TmpSignalConversionAtRP__ou + (1.0F -
        rtb_TmpSignalConversionAtRP__ou) * SWC_BCC_DW.UnitDelay_DSTATE_no;

      /* Switch: '<S59>/Switch8' incorporates:
       *  Switch: '<S59>/Switch9'
       */
      if (SWC_BCC_ConstB.RelationalOperator4_j) {
        rtb_TmpSignalConversionAtRP__br = rtb_TmpSignalConversionAtRP_SWC;
      } else {
        if (SWC_BCC_ConstB.RelationalOperator5_a) {
          /* Switch: '<S59>/Switch9' */
          rtb_TmpSignalConversionAtRP__br = rtb_TmpSignalConversionAtRP_S_n;
        }
      }

      /* End of Switch: '<S59>/Switch8' */

      /* Sum: '<S59>/Add10' incorporates:
       *  UnitDelay: '<S80>/Unit Delay'
       */
      VAR_UCoolantTj_f32 = rtb_TmpSignalConversionAtRP__br -
        SWC_BCC_DW.UnitDelay_DSTATE_no;

      /* Gain: '<S67>/Gain' */
      rtb_TmpSignalConversionAtRP__ou = 1000.0F *
        rtb_TmpSignalConversionAtRP_S_l;

      /* Sum: '<S83>/Add' incorporates:
       *  Constant: '<S67>/Constant12'
       *  Constant: '<S83>/Constant'
       *  Product: '<S67>/Product37'
       *  Product: '<S83>/Product'
       *  Product: '<S83>/Product1'
       *  Sum: '<S83>/Add1'
       *  UnitDelay: '<S83>/Unit Delay'
       */
      SWC_BCC_DW.UnitDelay_DSTATE_m4 = rtb_TmpSignalConversionAtRP_S_h *
        CAL_TjLv1Act_f32 * rtb_TmpSignalConversionAtRP__ou + (1.0F -
        rtb_TmpSignalConversionAtRP__ou) * SWC_BCC_DW.UnitDelay_DSTATE_m4;

      /* Gain: '<S67>/Gain2' */
      rtb_TmpSignalConversionAtRP__ou = 33.3F * rtb_TmpSignalConversionAtRP_S_l;

      /* Sum: '<S82>/Add' incorporates:
       *  Constant: '<S67>/Constant14'
       *  Constant: '<S82>/Constant'
       *  Product: '<S67>/Product39'
       *  Product: '<S82>/Product'
       *  Product: '<S82>/Product1'
       *  Sum: '<S82>/Add1'
       *  UnitDelay: '<S82>/Unit Delay'
       */
      SWC_BCC_DW.UnitDelay_DSTATE_dt = rtb_TmpSignalConversionAtRP_S_h *
        CAL_TjLv2Act_f32 * rtb_TmpSignalConversionAtRP__ou + (1.0F -
        rtb_TmpSignalConversionAtRP__ou) * SWC_BCC_DW.UnitDelay_DSTATE_dt;

      /* Gain: '<S67>/Gain7' */
      rtb_TmpSignalConversionAtRP__ou = 4.0F * rtb_TmpSignalConversionAtRP_S_l;

      /* Sum: '<S84>/Add' incorporates:
       *  Constant: '<S67>/Constant20'
       *  Constant: '<S67>/Constant4'
       *  Constant: '<S84>/Constant'
       *  Product: '<S67>/Product29'
       *  Product: '<S67>/Product30'
       *  Product: '<S84>/Product'
       *  Product: '<S84>/Product1'
       *  Sum: '<S67>/Add11'
       *  Sum: '<S84>/Add1'
       *  UnitDelay: '<S84>/Unit Delay'
       */
      SWC_BCC_DW.UnitDelay_DSTATE_bb = (rtb_TmpSignalConversionAtRP_S_h *
        CAL_TjLv3Act_f32 + rtb_Switch4_g * CAL_TjLv3Pas_f32) *
        rtb_TmpSignalConversionAtRP__ou + (1.0F -
        rtb_TmpSignalConversionAtRP__ou) * SWC_BCC_DW.UnitDelay_DSTATE_bb;

      /* Gain: '<S66>/Gain8' */
      rtb_TmpSignalConversionAtRP__ou = 0.7F * rtb_TmpSignalConversionAtRP_S_l;

      /* Sum: '<S81>/Add' incorporates:
       *  Constant: '<S6>/Constant13'
       *  Constant: '<S6>/Constant17'
       *  Constant: '<S6>/Constant4'
       *  Constant: '<S6>/Constant9'
       *  Constant: '<S81>/Constant'
       *  Product: '<S66>/Product17'
       *  Product: '<S66>/Product2'
       *  Product: '<S66>/Product21'
       *  Product: '<S66>/Product7'
       *  Product: '<S81>/Product'
       *  Product: '<S81>/Product1'
       *  Sum: '<S66>/Add5'
       *  Sum: '<S81>/Add1'
       *  UnitDelay: '<S81>/Unit Delay'
       */
      SWC_BCC_DW.UnitDelay_DSTATE_e4 = (((rtb_TmpSignalConversionAtRP_S_d *
        CAL_TjrthLv4ihil_f32 + rtb_TmpSignalConversionAtRP_S_h *
        CAL_TjrthLv4ilil_f32) + rtb_Switch2_a * CAL_TjrthLv4dhil_f32) +
        rtb_Switch4_g * CAL_TjrthLv4dlil_f32) * rtb_TmpSignalConversionAtRP__ou
        + (1.0F - rtb_TmpSignalConversionAtRP__ou) *
        SWC_BCC_DW.UnitDelay_DSTATE_e4;

      /* Sum: '<S59>/Add12' incorporates:
       *  Sum: '<S59>/Add11'
       *  UnitDelay: '<S81>/Unit Delay'
       *  UnitDelay: '<S82>/Unit Delay'
       *  UnitDelay: '<S83>/Unit Delay'
       *  UnitDelay: '<S84>/Unit Delay'
       */
      VAR_UilTjtIGBT_f32 = (((SWC_BCC_DW.UnitDelay_DSTATE_m4 +
        SWC_BCC_DW.UnitDelay_DSTATE_dt) + SWC_BCC_DW.UnitDelay_DSTATE_bb) +
                            SWC_BCC_DW.UnitDelay_DSTATE_e4) + VAR_UCoolantTj_f32;

      /* Gain: '<S69>/Gain' */
      rtb_TmpSignalConversionAtRP__ou = 1000.0F *
        rtb_TmpSignalConversionAtRP_S_l;

      /* Sum: '<S87>/Add' incorporates:
       *  Constant: '<S69>/Constant12'
       *  Constant: '<S87>/Constant'
       *  Product: '<S69>/Product37'
       *  Product: '<S87>/Product'
       *  Product: '<S87>/Product1'
       *  Sum: '<S87>/Add1'
       *  UnitDelay: '<S87>/Unit Delay'
       */
      SWC_BCC_DW.UnitDelay_DSTATE_pt = rtb_Switch4_g * CAL_TjLv1Act_f32 *
        rtb_TmpSignalConversionAtRP__ou + (1.0F -
        rtb_TmpSignalConversionAtRP__ou) * SWC_BCC_DW.UnitDelay_DSTATE_pt;

      /* Gain: '<S69>/Gain2' */
      rtb_TmpSignalConversionAtRP__ou = 33.3F * rtb_TmpSignalConversionAtRP_S_l;

      /* Sum: '<S86>/Add' incorporates:
       *  Constant: '<S69>/Constant14'
       *  Constant: '<S86>/Constant'
       *  Product: '<S69>/Product39'
       *  Product: '<S86>/Product'
       *  Product: '<S86>/Product1'
       *  Sum: '<S86>/Add1'
       *  UnitDelay: '<S86>/Unit Delay'
       */
      SWC_BCC_DW.UnitDelay_DSTATE_bw = rtb_Switch4_g * CAL_TjLv2Act_f32 *
        rtb_TmpSignalConversionAtRP__ou + (1.0F -
        rtb_TmpSignalConversionAtRP__ou) * SWC_BCC_DW.UnitDelay_DSTATE_bw;

      /* Gain: '<S69>/Gain7' */
      rtb_TmpSignalConversionAtRP__ou = 4.0F * rtb_TmpSignalConversionAtRP_S_l;

      /* Sum: '<S88>/Add' incorporates:
       *  Constant: '<S69>/Constant20'
       *  Constant: '<S69>/Constant4'
       *  Constant: '<S88>/Constant'
       *  Product: '<S69>/Product29'
       *  Product: '<S69>/Product30'
       *  Product: '<S88>/Product'
       *  Product: '<S88>/Product1'
       *  Sum: '<S69>/Add11'
       *  Sum: '<S88>/Add1'
       *  UnitDelay: '<S88>/Unit Delay'
       */
      SWC_BCC_DW.UnitDelay_DSTATE_n2r = (rtb_Switch4_g * CAL_TjLv3Act_f32 +
        rtb_TmpSignalConversionAtRP_S_h * CAL_TjLv3Pas_f32) *
        rtb_TmpSignalConversionAtRP__ou + (1.0F -
        rtb_TmpSignalConversionAtRP__ou) * SWC_BCC_DW.UnitDelay_DSTATE_n2r;

      /* Gain: '<S68>/Gain8' */
      rtb_TmpSignalConversionAtRP__ou = 0.7F * rtb_TmpSignalConversionAtRP_S_l;

      /* Sum: '<S85>/Add' incorporates:
       *  Constant: '<S6>/Constant11'
       *  Constant: '<S6>/Constant15'
       *  Constant: '<S6>/Constant19'
       *  Constant: '<S6>/Constant7'
       *  Constant: '<S85>/Constant'
       *  Product: '<S68>/Product17'
       *  Product: '<S68>/Product2'
       *  Product: '<S68>/Product21'
       *  Product: '<S68>/Product7'
       *  Product: '<S85>/Product'
       *  Product: '<S85>/Product1'
       *  Sum: '<S68>/Add5'
       *  Sum: '<S85>/Add1'
       *  UnitDelay: '<S85>/Unit Delay'
       */
      SWC_BCC_DW.UnitDelay_DSTATE_ar = (((rtb_TmpSignalConversionAtRP_S_d *
        CAL_TjrthLv4ihdl_f32 + rtb_TmpSignalConversionAtRP_S_h *
        CAL_TjrthLv4ildl_f32) + rtb_Switch2_a * CAL_TjrthLv4dhdl_f32) +
        rtb_Switch4_g * CAL_TjrthLv4dldl_f32) * rtb_TmpSignalConversionAtRP__ou
        + (1.0F - rtb_TmpSignalConversionAtRP__ou) *
        SWC_BCC_DW.UnitDelay_DSTATE_ar;

      /* Sum: '<S59>/Add14' incorporates:
       *  Sum: '<S59>/Add13'
       *  UnitDelay: '<S85>/Unit Delay'
       *  UnitDelay: '<S86>/Unit Delay'
       *  UnitDelay: '<S87>/Unit Delay'
       *  UnitDelay: '<S88>/Unit Delay'
       */
      VAR_UdlTjtIGBT_f32 = (((SWC_BCC_DW.UnitDelay_DSTATE_pt +
        SWC_BCC_DW.UnitDelay_DSTATE_bw) + SWC_BCC_DW.UnitDelay_DSTATE_n2r) +
                            SWC_BCC_DW.UnitDelay_DSTATE_ar) + VAR_UCoolantTj_f32;

      /* Gain: '<S71>/Gain' */
      rtb_TmpSignalConversionAtRP__ou = 1000.0F *
        rtb_TmpSignalConversionAtRP_S_l;

      /* Sum: '<S91>/Add' incorporates:
       *  Constant: '<S71>/Constant12'
       *  Constant: '<S91>/Constant'
       *  Product: '<S71>/Product37'
       *  Product: '<S91>/Product'
       *  Product: '<S91>/Product1'
       *  Sum: '<S91>/Add1'
       *  UnitDelay: '<S91>/Unit Delay'
       */
      SWC_BCC_DW.UnitDelay_DSTATE_k0 = rtb_Switch2_a * CAL_TjLv1Act_f32 *
        rtb_TmpSignalConversionAtRP__ou + (1.0F -
        rtb_TmpSignalConversionAtRP__ou) * SWC_BCC_DW.UnitDelay_DSTATE_k0;

      /* Gain: '<S71>/Gain2' */
      rtb_TmpSignalConversionAtRP__ou = 33.3F * rtb_TmpSignalConversionAtRP_S_l;

      /* Sum: '<S90>/Add' incorporates:
       *  Constant: '<S71>/Constant14'
       *  Constant: '<S90>/Constant'
       *  Product: '<S71>/Product39'
       *  Product: '<S90>/Product'
       *  Product: '<S90>/Product1'
       *  Sum: '<S90>/Add1'
       *  UnitDelay: '<S90>/Unit Delay'
       */
      SWC_BCC_DW.UnitDelay_DSTATE_lk = rtb_Switch2_a * CAL_TjLv2Act_f32 *
        rtb_TmpSignalConversionAtRP__ou + (1.0F -
        rtb_TmpSignalConversionAtRP__ou) * SWC_BCC_DW.UnitDelay_DSTATE_lk;

      /* Gain: '<S71>/Gain7' */
      rtb_TmpSignalConversionAtRP__ou = 4.0F * rtb_TmpSignalConversionAtRP_S_l;

      /* Sum: '<S92>/Add' incorporates:
       *  Constant: '<S71>/Constant20'
       *  Constant: '<S71>/Constant4'
       *  Constant: '<S92>/Constant'
       *  Product: '<S71>/Product29'
       *  Product: '<S71>/Product30'
       *  Product: '<S92>/Product'
       *  Product: '<S92>/Product1'
       *  Sum: '<S71>/Add11'
       *  Sum: '<S92>/Add1'
       *  UnitDelay: '<S92>/Unit Delay'
       */
      SWC_BCC_DW.UnitDelay_DSTATE_o = (rtb_Switch2_a * CAL_TjLv3Act_f32 +
        rtb_TmpSignalConversionAtRP_S_d * CAL_TjLv3Pas_f32) *
        rtb_TmpSignalConversionAtRP__ou + (1.0F -
        rtb_TmpSignalConversionAtRP__ou) * SWC_BCC_DW.UnitDelay_DSTATE_o;

      /* Gain: '<S70>/Gain8' */
      rtb_TmpSignalConversionAtRP__ou = 0.7F * rtb_TmpSignalConversionAtRP_S_l;

      /* Sum: '<S89>/Add' incorporates:
       *  Constant: '<S6>/Constant10'
       *  Constant: '<S6>/Constant14'
       *  Constant: '<S6>/Constant18'
       *  Constant: '<S6>/Constant5'
       *  Constant: '<S89>/Constant'
       *  Product: '<S70>/Product17'
       *  Product: '<S70>/Product2'
       *  Product: '<S70>/Product21'
       *  Product: '<S70>/Product7'
       *  Product: '<S89>/Product'
       *  Product: '<S89>/Product1'
       *  Sum: '<S70>/Add5'
       *  Sum: '<S89>/Add1'
       *  UnitDelay: '<S89>/Unit Delay'
       */
      SWC_BCC_DW.UnitDelay_DSTATE_jg = (((rtb_TmpSignalConversionAtRP_S_d *
        CAL_TjrthLv4ihdh_f32 + rtb_TmpSignalConversionAtRP_S_h *
        CAL_TjrthLv4ildh_f32) + rtb_Switch2_a * CAL_TjrthLv4dhdh_f32) +
        rtb_Switch4_g * CAL_TjrthLv4dldh_f32) * rtb_TmpSignalConversionAtRP__ou
        + (1.0F - rtb_TmpSignalConversionAtRP__ou) *
        SWC_BCC_DW.UnitDelay_DSTATE_jg;

      /* Sum: '<S59>/Add6' incorporates:
       *  Sum: '<S59>/Add5'
       *  UnitDelay: '<S89>/Unit Delay'
       *  UnitDelay: '<S90>/Unit Delay'
       *  UnitDelay: '<S91>/Unit Delay'
       *  UnitDelay: '<S92>/Unit Delay'
       */
      VAR_UdhTjtIGBT_f32 = (((SWC_BCC_DW.UnitDelay_DSTATE_k0 +
        SWC_BCC_DW.UnitDelay_DSTATE_lk) + SWC_BCC_DW.UnitDelay_DSTATE_o) +
                            SWC_BCC_DW.UnitDelay_DSTATE_jg) + VAR_UCoolantTj_f32;

      /* Gain: '<S72>/Gain' */
      rtb_TmpSignalConversionAtRP__ou = 1000.0F *
        rtb_TmpSignalConversionAtRP_S_l;

      /* Sum: '<S94>/Add' incorporates:
       *  Constant: '<S72>/Constant12'
       *  Constant: '<S94>/Constant'
       *  Product: '<S72>/Product37'
       *  Product: '<S94>/Product'
       *  Product: '<S94>/Product1'
       *  Sum: '<S94>/Add1'
       *  UnitDelay: '<S94>/Unit Delay'
       */
      SWC_BCC_DW.UnitDelay_DSTATE_c3 = rtb_TmpSignalConversionAtRP_S_d *
        CAL_TjLv1Act_f32 * rtb_TmpSignalConversionAtRP__ou + (1.0F -
        rtb_TmpSignalConversionAtRP__ou) * SWC_BCC_DW.UnitDelay_DSTATE_c3;

      /* Gain: '<S72>/Gain2' */
      rtb_TmpSignalConversionAtRP__ou = 33.3F * rtb_TmpSignalConversionAtRP_S_l;

      /* Sum: '<S93>/Add' incorporates:
       *  Constant: '<S72>/Constant14'
       *  Constant: '<S93>/Constant'
       *  Product: '<S72>/Product39'
       *  Product: '<S93>/Product'
       *  Product: '<S93>/Product1'
       *  Sum: '<S93>/Add1'
       *  UnitDelay: '<S93>/Unit Delay'
       */
      SWC_BCC_DW.UnitDelay_DSTATE_cg = rtb_TmpSignalConversionAtRP_S_d *
        CAL_TjLv2Act_f32 * rtb_TmpSignalConversionAtRP__ou + (1.0F -
        rtb_TmpSignalConversionAtRP__ou) * SWC_BCC_DW.UnitDelay_DSTATE_cg;

      /* Gain: '<S72>/Gain7' */
      rtb_TmpSignalConversionAtRP__ou = 4.0F * rtb_TmpSignalConversionAtRP_S_l;

      /* Sum: '<S95>/Add' incorporates:
       *  Constant: '<S72>/Constant20'
       *  Constant: '<S72>/Constant4'
       *  Constant: '<S95>/Constant'
       *  Product: '<S72>/Product29'
       *  Product: '<S72>/Product30'
       *  Product: '<S95>/Product'
       *  Product: '<S95>/Product1'
       *  Sum: '<S72>/Add11'
       *  Sum: '<S95>/Add1'
       *  UnitDelay: '<S95>/Unit Delay'
       */
      SWC_BCC_DW.UnitDelay_DSTATE_ip = (rtb_TmpSignalConversionAtRP_S_d *
        CAL_TjLv3Act_f32 + rtb_Switch2_a * CAL_TjLv3Pas_f32) *
        rtb_TmpSignalConversionAtRP__ou + (1.0F -
        rtb_TmpSignalConversionAtRP__ou) * SWC_BCC_DW.UnitDelay_DSTATE_ip;

      /* Sum: '<S64>/Add5' incorporates:
       *  Constant: '<S6>/Constant16'
       *  Constant: '<S6>/Constant8'
       *  Product: '<S64>/Product17'
       *  Product: '<S64>/Product2'
       *  Product: '<S64>/Product21'
       *  Product: '<S64>/Product7'
       */
      rtb_TmpSignalConversionAtRP_SWC = ((rtb_TmpSignalConversionAtRP_S_d *
        rtb_Product10_l + rtb_TmpSignalConversionAtRP_S_h * CAL_TjrthLv4ilih_f32)
        + rtb_Switch2_a * rtb_Switch_i) + rtb_Switch4_g * CAL_TjrthLv4dlih_f32;

      /* Gain: '<S64>/Gain8' */
      rtb_Switch2_a = 0.7F * rtb_TmpSignalConversionAtRP_S_l;

      /* Sum: '<S79>/Add' incorporates:
       *  Constant: '<S79>/Constant'
       *  Product: '<S79>/Product'
       *  Product: '<S79>/Product1'
       *  Sum: '<S79>/Add1'
       *  UnitDelay: '<S79>/Unit Delay'
       */
      SWC_BCC_DW.UnitDelay_DSTATE_eu = (1.0F - rtb_Switch2_a) *
        SWC_BCC_DW.UnitDelay_DSTATE_eu + rtb_TmpSignalConversionAtRP_SWC *
        rtb_Switch2_a;

      /* Sum: '<S59>/Add9' incorporates:
       *  Sum: '<S59>/Add15'
       *  UnitDelay: '<S79>/Unit Delay'
       *  UnitDelay: '<S93>/Unit Delay'
       *  UnitDelay: '<S94>/Unit Delay'
       *  UnitDelay: '<S95>/Unit Delay'
       */
      VAR_UihTjtIGBT_f32 = (((SWC_BCC_DW.UnitDelay_DSTATE_c3 +
        SWC_BCC_DW.UnitDelay_DSTATE_cg) + SWC_BCC_DW.UnitDelay_DSTATE_ip) +
                            SWC_BCC_DW.UnitDelay_DSTATE_eu) + VAR_UCoolantTj_f32;

      /* MinMax: '<S59>/Max' incorporates:
       *  UnitDelay: '<S6>/Unit Delay2'
       */
      SWC_BCC_DW.UnitDelay2_DSTATE_o = fmaxf(fmaxf(fmaxf(VAR_UihTjtIGBT_f32,
        VAR_UdhTjtIGBT_f32), VAR_UilTjtIGBT_f32), VAR_UdlTjtIGBT_f32);

      /* Sum: '<S74>/Add' incorporates:
       *  Constant: '<S74>/Constant'
       *  Product: '<S74>/Product'
       *  Product: '<S74>/Product1'
       *  Sum: '<S74>/Add1'
       *  UnitDelay: '<S6>/Unit Delay3'
       *  UnitDelay: '<S74>/Unit Delay'
       */
      SWC_BCC_DW.UnitDelay3_DSTATE = (1.0F - rtb_Product9_j) *
        SWC_BCC_DW.UnitDelay_DSTATE_ej + VAR_UCoolantTj_f32 * rtb_Product9_j;

      /* Update for UnitDelay: '<S73>/Unit Delay' */
      SWC_BCC_DW.UnitDelay_DSTATE_ad = VAR_UTjpwr_f32;

      /* Update for UnitDelay: '<S74>/Unit Delay' incorporates:
       *  UnitDelay: '<S6>/Unit Delay3'
       */
      SWC_BCC_DW.UnitDelay_DSTATE_ej = SWC_BCC_DW.UnitDelay3_DSTATE;
      if (!SWC_BCC_DW.Subsystem15_MODE) {
        /* InitializeConditions for UnitDelay: '<S148>/Unit Delay' */
        SWC_BCC_DW.UnitDelay_DSTATE_i = 0.0F;

        /* InitializeConditions for UnitDelay: '<S150>/Unit Delay' */
        SWC_BCC_DW.UnitDelay_DSTATE_f = 0.0F;

        /* InitializeConditions for UnitDelay: '<S149>/Unit Delay' */
        SWC_BCC_DW.UnitDelay_DSTATE_p = 0.0F;

        /* InitializeConditions for UnitDelay: '<S151>/Unit Delay' */
        SWC_BCC_DW.UnitDelay_DSTATE_k = 0.0F;

        /* InitializeConditions for UnitDelay: '<S152>/Unit Delay' */
        SWC_BCC_DW.UnitDelay_DSTATE_a = 0.0F;

        /* InitializeConditions for UnitDelay: '<S154>/Unit Delay' */
        SWC_BCC_DW.UnitDelay_DSTATE_ir = 0.0F;

        /* InitializeConditions for UnitDelay: '<S153>/Unit Delay' */
        SWC_BCC_DW.UnitDelay_DSTATE_c = 0.0F;

        /* InitializeConditions for UnitDelay: '<S155>/Unit Delay' */
        SWC_BCC_DW.UnitDelay_DSTATE_cy = 0.0F;

        /* InitializeConditions for UnitDelay: '<S156>/Unit Delay' */
        SWC_BCC_DW.UnitDelay_DSTATE_ki = 0.0F;

        /* InitializeConditions for UnitDelay: '<S158>/Unit Delay' */
        SWC_BCC_DW.UnitDelay_DSTATE_cp = 0.0F;

        /* InitializeConditions for UnitDelay: '<S157>/Unit Delay' */
        SWC_BCC_DW.UnitDelay_DSTATE_b = 0.0F;

        /* InitializeConditions for UnitDelay: '<S159>/Unit Delay' */
        SWC_BCC_DW.UnitDelay_DSTATE_e = 0.0F;
        SWC_BCC_DW.Subsystem15_MODE = true;
      }

      /* Gain: '<S142>/Gain8' */
      rtb_TmpSignalConversionAtRP_SWC = 0.7F * rtb_TmpSignalConversionAtRP_S_l;

      /* Sum: '<S148>/Add' incorporates:
       *  Constant: '<S148>/Constant'
       *  Constant: '<S6>/Constant13'
       *  Constant: '<S6>/Constant17'
       *  Constant: '<S6>/Constant4'
       *  Constant: '<S6>/Constant9'
       *  Product: '<S142>/Product17'
       *  Product: '<S142>/Product2'
       *  Product: '<S142>/Product21'
       *  Product: '<S142>/Product7'
       *  Product: '<S148>/Product'
       *  Product: '<S148>/Product1'
       *  Sum: '<S142>/Add5'
       *  Sum: '<S148>/Add1'
       *  UnitDelay: '<S148>/Unit Delay'
       */
      SWC_BCC_DW.UnitDelay_DSTATE_i = (((rtb_Gain11 * CAL_TjrthLv4ihil_f32 +
        rtb_Switch1_a * CAL_TjrthLv4ilil_f32) + rtb_Switch2_i *
        CAL_TjrthLv4dhil_f32) + rtb_Product8 * CAL_TjrthLv4dlil_f32) *
        rtb_TmpSignalConversionAtRP_SWC + (1.0F -
        rtb_TmpSignalConversionAtRP_SWC) * SWC_BCC_DW.UnitDelay_DSTATE_i;

      /* Gain: '<S143>/Gain' */
      rtb_TmpSignalConversionAtRP_SWC = 1000.0F *
        rtb_TmpSignalConversionAtRP_S_l;

      /* Sum: '<S150>/Add' incorporates:
       *  Constant: '<S143>/Constant12'
       *  Constant: '<S150>/Constant'
       *  Product: '<S143>/Product37'
       *  Product: '<S150>/Product'
       *  Product: '<S150>/Product1'
       *  Sum: '<S150>/Add1'
       *  UnitDelay: '<S150>/Unit Delay'
       */
      SWC_BCC_DW.UnitDelay_DSTATE_f = rtb_Switch1_a * CAL_TjLv1Act_f32 *
        rtb_TmpSignalConversionAtRP_SWC + (1.0F -
        rtb_TmpSignalConversionAtRP_SWC) * SWC_BCC_DW.UnitDelay_DSTATE_f;

      /* Gain: '<S143>/Gain2' */
      rtb_TmpSignalConversionAtRP_SWC = 33.3F * rtb_TmpSignalConversionAtRP_S_l;

      /* Sum: '<S149>/Add' incorporates:
       *  Constant: '<S143>/Constant14'
       *  Constant: '<S149>/Constant'
       *  Product: '<S143>/Product39'
       *  Product: '<S149>/Product'
       *  Product: '<S149>/Product1'
       *  Sum: '<S149>/Add1'
       *  UnitDelay: '<S149>/Unit Delay'
       */
      SWC_BCC_DW.UnitDelay_DSTATE_p = rtb_Switch1_a * CAL_TjLv2Act_f32 *
        rtb_TmpSignalConversionAtRP_SWC + (1.0F -
        rtb_TmpSignalConversionAtRP_SWC) * SWC_BCC_DW.UnitDelay_DSTATE_p;

      /* Gain: '<S143>/Gain7' */
      rtb_TmpSignalConversionAtRP_SWC = 4.0F * rtb_TmpSignalConversionAtRP_S_l;

      /* Sum: '<S151>/Add' incorporates:
       *  Constant: '<S143>/Constant20'
       *  Constant: '<S143>/Constant4'
       *  Constant: '<S151>/Constant'
       *  Product: '<S143>/Product29'
       *  Product: '<S143>/Product30'
       *  Product: '<S151>/Product'
       *  Product: '<S151>/Product1'
       *  Sum: '<S143>/Add11'
       *  Sum: '<S151>/Add1'
       *  UnitDelay: '<S151>/Unit Delay'
       */
      SWC_BCC_DW.UnitDelay_DSTATE_k = (rtb_Switch1_a * CAL_TjLv3Act_f32 +
        rtb_Product8 * CAL_TjLv3Pas_f32) * rtb_TmpSignalConversionAtRP_SWC +
        (1.0F - rtb_TmpSignalConversionAtRP_SWC) * SWC_BCC_DW.UnitDelay_DSTATE_k;

      /* Sum: '<S132>/Add12' incorporates:
       *  Sum: '<S132>/Add11'
       *  UnitDelay: '<S148>/Unit Delay'
       *  UnitDelay: '<S149>/Unit Delay'
       *  UnitDelay: '<S150>/Unit Delay'
       *  UnitDelay: '<S151>/Unit Delay'
       */
      VAR_WilTjtIGBT_f32 = (((SWC_BCC_DW.UnitDelay_DSTATE_f +
        SWC_BCC_DW.UnitDelay_DSTATE_p) + SWC_BCC_DW.UnitDelay_DSTATE_k) +
                            SWC_BCC_DW.UnitDelay_DSTATE_i) + VAR_WCoolantTj_f32;

      /* Gain: '<S144>/Gain8' */
      rtb_TmpSignalConversionAtRP_SWC = 0.7F * rtb_TmpSignalConversionAtRP_S_l;

      /* Sum: '<S152>/Add' incorporates:
       *  Constant: '<S152>/Constant'
       *  Constant: '<S6>/Constant11'
       *  Constant: '<S6>/Constant15'
       *  Constant: '<S6>/Constant19'
       *  Constant: '<S6>/Constant7'
       *  Product: '<S144>/Product17'
       *  Product: '<S144>/Product2'
       *  Product: '<S144>/Product21'
       *  Product: '<S144>/Product7'
       *  Product: '<S152>/Product'
       *  Product: '<S152>/Product1'
       *  Sum: '<S144>/Add5'
       *  Sum: '<S152>/Add1'
       *  UnitDelay: '<S152>/Unit Delay'
       */
      SWC_BCC_DW.UnitDelay_DSTATE_a = (((rtb_Gain11 * CAL_TjrthLv4ihdl_f32 +
        rtb_Switch1_a * CAL_TjrthLv4ildl_f32) + rtb_Switch2_i *
        CAL_TjrthLv4dhdl_f32) + rtb_Product8 * CAL_TjrthLv4dldl_f32) *
        rtb_TmpSignalConversionAtRP_SWC + (1.0F -
        rtb_TmpSignalConversionAtRP_SWC) * SWC_BCC_DW.UnitDelay_DSTATE_a;

      /* Gain: '<S145>/Gain' */
      rtb_TmpSignalConversionAtRP_SWC = 1000.0F *
        rtb_TmpSignalConversionAtRP_S_l;

      /* Sum: '<S154>/Add' incorporates:
       *  Constant: '<S145>/Constant12'
       *  Constant: '<S154>/Constant'
       *  Product: '<S145>/Product37'
       *  Product: '<S154>/Product'
       *  Product: '<S154>/Product1'
       *  Sum: '<S154>/Add1'
       *  UnitDelay: '<S154>/Unit Delay'
       */
      SWC_BCC_DW.UnitDelay_DSTATE_ir = rtb_Product8 * CAL_TjLv1Act_f32 *
        rtb_TmpSignalConversionAtRP_SWC + (1.0F -
        rtb_TmpSignalConversionAtRP_SWC) * SWC_BCC_DW.UnitDelay_DSTATE_ir;

      /* Gain: '<S145>/Gain2' */
      rtb_TmpSignalConversionAtRP_SWC = 33.3F * rtb_TmpSignalConversionAtRP_S_l;

      /* Sum: '<S153>/Add' incorporates:
       *  Constant: '<S145>/Constant14'
       *  Constant: '<S153>/Constant'
       *  Product: '<S145>/Product39'
       *  Product: '<S153>/Product'
       *  Product: '<S153>/Product1'
       *  Sum: '<S153>/Add1'
       *  UnitDelay: '<S153>/Unit Delay'
       */
      SWC_BCC_DW.UnitDelay_DSTATE_c = rtb_Product8 * CAL_TjLv2Act_f32 *
        rtb_TmpSignalConversionAtRP_SWC + (1.0F -
        rtb_TmpSignalConversionAtRP_SWC) * SWC_BCC_DW.UnitDelay_DSTATE_c;

      /* Gain: '<S145>/Gain7' */
      rtb_TmpSignalConversionAtRP_SWC = 4.0F * rtb_TmpSignalConversionAtRP_S_l;

      /* Sum: '<S155>/Add' incorporates:
       *  Constant: '<S145>/Constant20'
       *  Constant: '<S145>/Constant4'
       *  Constant: '<S155>/Constant'
       *  Product: '<S145>/Product29'
       *  Product: '<S145>/Product30'
       *  Product: '<S155>/Product'
       *  Product: '<S155>/Product1'
       *  Sum: '<S145>/Add11'
       *  Sum: '<S155>/Add1'
       *  UnitDelay: '<S155>/Unit Delay'
       */
      SWC_BCC_DW.UnitDelay_DSTATE_cy = (rtb_Product8 * CAL_TjLv3Act_f32 +
        rtb_Switch1_a * CAL_TjLv3Pas_f32) * rtb_TmpSignalConversionAtRP_SWC +
        (1.0F - rtb_TmpSignalConversionAtRP_SWC) *
        SWC_BCC_DW.UnitDelay_DSTATE_cy;

      /* Sum: '<S132>/Add14' incorporates:
       *  Sum: '<S132>/Add13'
       *  UnitDelay: '<S152>/Unit Delay'
       *  UnitDelay: '<S153>/Unit Delay'
       *  UnitDelay: '<S154>/Unit Delay'
       *  UnitDelay: '<S155>/Unit Delay'
       */
      VAR_WdlTjtIGBT_f32 = (((SWC_BCC_DW.UnitDelay_DSTATE_ir +
        SWC_BCC_DW.UnitDelay_DSTATE_c) + SWC_BCC_DW.UnitDelay_DSTATE_cy) +
                            SWC_BCC_DW.UnitDelay_DSTATE_a) + VAR_WCoolantTj_f32;

      /* Gain: '<S146>/Gain8' */
      rtb_TmpSignalConversionAtRP_SWC = 0.7F * rtb_TmpSignalConversionAtRP_S_l;

      /* Sum: '<S156>/Add' incorporates:
       *  Constant: '<S156>/Constant'
       *  Constant: '<S6>/Constant10'
       *  Constant: '<S6>/Constant14'
       *  Constant: '<S6>/Constant18'
       *  Constant: '<S6>/Constant5'
       *  Product: '<S146>/Product17'
       *  Product: '<S146>/Product2'
       *  Product: '<S146>/Product21'
       *  Product: '<S146>/Product7'
       *  Product: '<S156>/Product'
       *  Product: '<S156>/Product1'
       *  Sum: '<S146>/Add5'
       *  Sum: '<S156>/Add1'
       *  UnitDelay: '<S156>/Unit Delay'
       */
      SWC_BCC_DW.UnitDelay_DSTATE_ki = (((rtb_Gain11 * CAL_TjrthLv4ihdh_f32 +
        rtb_Switch1_a * CAL_TjrthLv4ildh_f32) + rtb_Switch2_i *
        CAL_TjrthLv4dhdh_f32) + rtb_Product8 * CAL_TjrthLv4dldh_f32) *
        rtb_TmpSignalConversionAtRP_SWC + (1.0F -
        rtb_TmpSignalConversionAtRP_SWC) * SWC_BCC_DW.UnitDelay_DSTATE_ki;

      /* Gain: '<S147>/Gain' */
      rtb_TmpSignalConversionAtRP_SWC = 1000.0F *
        rtb_TmpSignalConversionAtRP_S_l;

      /* Sum: '<S158>/Add' incorporates:
       *  Constant: '<S147>/Constant12'
       *  Constant: '<S158>/Constant'
       *  Product: '<S147>/Product37'
       *  Product: '<S158>/Product'
       *  Product: '<S158>/Product1'
       *  Sum: '<S158>/Add1'
       *  UnitDelay: '<S158>/Unit Delay'
       */
      SWC_BCC_DW.UnitDelay_DSTATE_cp = rtb_Switch2_i * CAL_TjLv1Act_f32 *
        rtb_TmpSignalConversionAtRP_SWC + (1.0F -
        rtb_TmpSignalConversionAtRP_SWC) * SWC_BCC_DW.UnitDelay_DSTATE_cp;

      /* Gain: '<S147>/Gain2' */
      rtb_TmpSignalConversionAtRP_SWC = 33.3F * rtb_TmpSignalConversionAtRP_S_l;

      /* Sum: '<S157>/Add' incorporates:
       *  Constant: '<S147>/Constant14'
       *  Constant: '<S157>/Constant'
       *  Product: '<S147>/Product39'
       *  Product: '<S157>/Product'
       *  Product: '<S157>/Product1'
       *  Sum: '<S157>/Add1'
       *  UnitDelay: '<S157>/Unit Delay'
       */
      SWC_BCC_DW.UnitDelay_DSTATE_b = rtb_Switch2_i * CAL_TjLv2Act_f32 *
        rtb_TmpSignalConversionAtRP_SWC + (1.0F -
        rtb_TmpSignalConversionAtRP_SWC) * SWC_BCC_DW.UnitDelay_DSTATE_b;

      /* Gain: '<S147>/Gain7' */
      rtb_TmpSignalConversionAtRP_SWC = 4.0F * rtb_TmpSignalConversionAtRP_S_l;

      /* Sum: '<S159>/Add' incorporates:
       *  Constant: '<S147>/Constant20'
       *  Constant: '<S147>/Constant4'
       *  Constant: '<S159>/Constant'
       *  Product: '<S147>/Product29'
       *  Product: '<S147>/Product30'
       *  Product: '<S159>/Product'
       *  Product: '<S159>/Product1'
       *  Sum: '<S147>/Add11'
       *  Sum: '<S159>/Add1'
       *  UnitDelay: '<S159>/Unit Delay'
       */
      SWC_BCC_DW.UnitDelay_DSTATE_e = (rtb_Switch2_i * CAL_TjLv3Act_f32 +
        rtb_Gain11 * CAL_TjLv3Pas_f32) * rtb_TmpSignalConversionAtRP_SWC + (1.0F
        - rtb_TmpSignalConversionAtRP_SWC) * SWC_BCC_DW.UnitDelay_DSTATE_e;

      /* Sum: '<S132>/Add6' incorporates:
       *  Sum: '<S132>/Add5'
       *  UnitDelay: '<S156>/Unit Delay'
       *  UnitDelay: '<S157>/Unit Delay'
       *  UnitDelay: '<S158>/Unit Delay'
       *  UnitDelay: '<S159>/Unit Delay'
       */
      VAR_WdhTjtIGBT_f32 = (((SWC_BCC_DW.UnitDelay_DSTATE_cp +
        SWC_BCC_DW.UnitDelay_DSTATE_b) + SWC_BCC_DW.UnitDelay_DSTATE_e) +
                            SWC_BCC_DW.UnitDelay_DSTATE_ki) + VAR_WCoolantTj_f32;
    } else {
      SWC_BCC_DW.uTjCal1_MODE = false;
      SWC_BCC_DW.Subsystem15_MODE = false;
    }

    /* End of Outputs for SubSystem: '<S6>/uTjCal1' */
    /* End of Outputs for SubSystem: '<S61>/Subsystem15' */

    /* Gain: '<S133>/Gain' incorporates:
     *  Constant: '<S54>/Constant'
     *  RelationalOperator: '<S54>/Compare'
     */
    rtb_Switch10_idx_1 = 1000.0F * rtb_TmpSignalConversionAtRP_S_l;

    /* Sum: '<S161>/Add' incorporates:
     *  Constant: '<S133>/Constant12'
     *  Constant: '<S161>/Constant'
     *  Product: '<S133>/Product37'
     *  Product: '<S161>/Product'
     *  Product: '<S161>/Product1'
     *  Sum: '<S161>/Add1'
     *  UnitDelay: '<S161>/Unit Delay'
     */
    SWC_BCC_DW.UnitDelay_DSTATE_n = rtb_Gain11 * CAL_TjLv1Act_f32 *
      rtb_Switch10_idx_1 + (1.0F - rtb_Switch10_idx_1) *
      SWC_BCC_DW.UnitDelay_DSTATE_n;

    /* Gain: '<S133>/Gain2' */
    rtb_Switch10_idx_1 = 33.3F * rtb_TmpSignalConversionAtRP_S_l;

    /* Sum: '<S160>/Add' incorporates:
     *  Constant: '<S133>/Constant14'
     *  Constant: '<S160>/Constant'
     *  Product: '<S133>/Product39'
     *  Product: '<S160>/Product'
     *  Product: '<S160>/Product1'
     *  Sum: '<S160>/Add1'
     *  UnitDelay: '<S160>/Unit Delay'
     */
    SWC_BCC_DW.UnitDelay_DSTATE_j = rtb_Gain11 * CAL_TjLv2Act_f32 *
      rtb_Switch10_idx_1 + (1.0F - rtb_Switch10_idx_1) *
      SWC_BCC_DW.UnitDelay_DSTATE_j;

    /* Gain: '<S133>/Gain7' */
    rtb_Switch10_idx_1 = 4.0F * rtb_TmpSignalConversionAtRP_S_l;

    /* Sum: '<S162>/Add' incorporates:
     *  Constant: '<S133>/Constant20'
     *  Constant: '<S133>/Constant4'
     *  Constant: '<S162>/Constant'
     *  Product: '<S133>/Product29'
     *  Product: '<S133>/Product30'
     *  Product: '<S162>/Product'
     *  Product: '<S162>/Product1'
     *  Sum: '<S133>/Add11'
     *  Sum: '<S162>/Add1'
     *  UnitDelay: '<S162>/Unit Delay'
     */
    SWC_BCC_DW.UnitDelay_DSTATE_l = (rtb_Gain11 * CAL_TjLv3Act_f32 +
      rtb_Switch2_i * CAL_TjLv3Pas_f32) * rtb_Switch10_idx_1 + (1.0F -
      rtb_Switch10_idx_1) * SWC_BCC_DW.UnitDelay_DSTATE_l;

    /* Gain: '<S130>/Gain8' */
    rtb_Switch10_idx_1 = 0.7F * rtb_TmpSignalConversionAtRP_S_l;

    /* Sum: '<S140>/Add' incorporates:
     *  Constant: '<S140>/Constant'
     *  Constant: '<S6>/Constant16'
     *  Constant: '<S6>/Constant8'
     *  Product: '<S130>/Product17'
     *  Product: '<S130>/Product2'
     *  Product: '<S130>/Product21'
     *  Product: '<S130>/Product7'
     *  Product: '<S140>/Product'
     *  Product: '<S140>/Product1'
     *  Sum: '<S130>/Add5'
     *  Sum: '<S140>/Add1'
     *  UnitDelay: '<S140>/Unit Delay'
     */
    SWC_BCC_DW.UnitDelay_DSTATE_nd = (((rtb_Gain11 * rtb_Product10_l +
      rtb_Switch1_a * CAL_TjrthLv4ilih_f32) + rtb_Switch2_i * rtb_Switch_i) +
      rtb_Product8 * CAL_TjrthLv4dlih_f32) * rtb_Switch10_idx_1 + (1.0F -
      rtb_Switch10_idx_1) * SWC_BCC_DW.UnitDelay_DSTATE_nd;

    /* Sum: '<S61>/Add9' incorporates:
     *  Sum: '<S61>/Add15'
     *  UnitDelay: '<S140>/Unit Delay'
     *  UnitDelay: '<S160>/Unit Delay'
     *  UnitDelay: '<S161>/Unit Delay'
     *  UnitDelay: '<S162>/Unit Delay'
     */
    VAR_WihTjtIGBT_f32 = (((SWC_BCC_DW.UnitDelay_DSTATE_n +
      SWC_BCC_DW.UnitDelay_DSTATE_j) + SWC_BCC_DW.UnitDelay_DSTATE_l) +
                          SWC_BCC_DW.UnitDelay_DSTATE_nd) + VAR_WCoolantTj_f32;

    /* MinMax: '<S61>/Max' incorporates:
     *  UnitDelay: '<S6>/Unit Delay1'
     */
    SWC_BCC_DW.UnitDelay1_DSTATE_f = fmaxf(fmaxf(fmaxf(VAR_WihTjtIGBT_f32,
      VAR_WdhTjtIGBT_f32), VAR_WilTjtIGBT_f32), VAR_WdlTjtIGBT_f32);

    /* Sum: '<S6>/Add' incorporates:
     *  MinMax: '<S6>/Max'
     */
    SWC_BCC_B.Add = fmaxf(fmaxf(rtb_Product_eb, rtb_dycmax), rtb_Saturation_c);

    /* Outport: '<Root>/PP_SWC_BCC_BCC_tIgbtTj' */
    (void) Rte_Write_PP_SWC_BCC_BCC_tIgbtTj(SWC_BCC_B.Add);
    rtb_Switch10_idx_2 = SWC_BCC_B.Add1;
  } else {
    if (SWC_BCC_DW.Tj_MODE) {
      /* Disable for Enabled SubSystem: '<S6>/uTjCal2' */
      SWC_BCC_DW.uTjCal2_MODE = false;

      /* End of Disable for SubSystem: '<S6>/uTjCal2' */

      /* Disable for Enabled SubSystem: '<S6>/uTjCal1' */
      SWC_BCC_DW.uTjCal1_MODE = false;

      /* End of Disable for SubSystem: '<S6>/uTjCal1' */

      /* Disable for Enabled SubSystem: '<S61>/Subsystem15' */
      SWC_BCC_DW.Subsystem15_MODE = false;

      /* End of Disable for SubSystem: '<S61>/Subsystem15' */
      SWC_BCC_DW.Tj_MODE = false;
    }

    /* Outport: '<Root>/PP_SWC_BCC_BCC_tIgbtTj' */
    (void) Rte_Write_PP_SWC_BCC_BCC_tIgbtTj(rtb_TmpSignalConversionAtRP__br);
    rtb_Switch10_idx_2 = 65.0F;
  }

  /* End of Switch: '<S3>/Switch' */
  /* End of Outputs for SubSystem: '<S3>/Tj' */

  /* Outport: '<Root>/PP_SWC_BCC_BCC_tCoolantTj' incorporates:
   *  Switch: '<S3>/Switch1'
   */
  (void) Rte_Write_PP_SWC_BCC_BCC_tCoolantTj(rtb_Switch10_idx_2);

  /* Update for UnitDelay: '<S4>/Unit Delay' */
  SWC_BCC_DW.UnitDelay_DSTATE = rtb_TmpSignalConversionAtRP__ha;

  /* Update for UnitDelay: '<S4>/Unit Delay1' */
  SWC_BCC_DW.UnitDelay1_DSTATE = rtb_TmpSignalConversionAtRP_S_g;

  /* Update for UnitDelay: '<S4>/Unit Delay2' */
  SWC_BCC_DW.UnitDelay2_DSTATE = rtb_TmpSignalConversionAtRP_S_i;

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_BCC_100us' */
}

/* Model initialize function */
void SWC_BCC_Init(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
