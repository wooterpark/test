/*
 * File: SWC_VCF.c
 *
 * Code generated for Simulink model 'SWC_VCF'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Fri Jan 15 17:02:12 2021
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SWC_VCF.h"
#include "SWC_VCF_private.h"
#include "look1_iflf_binlcapw.h"

/* Named constants for Chart: '<S9>/Chart' */
#define SWC_VCF_IN_AutoHoldIn          ((uint8)1U)
#define SWC_VCF_IN_AutoHoldOut         ((uint8)2U)

/* Exported block signals */
float32 VAR_Vcf_nMotorObsv_f32;        /* '<S51>/Product1' */
float32 VAR_Vcf_nVehicleObsv_f32;      /* '<S51>/Product2' */
float32 VAR_Vcf_TrqDmp_f32;            /* '<S52>/Switch2' */
float32 VAR_Vcf_SpdChangeRatio_f32;    /* '<S41>/Divide' */
float32 VAR_Vcf_TrqSrtPInside_f32;     /* '<S46>/Switch' */
float32 VAR_Vcf_SlopeReq_f32;          /* '<S29>/Switch' */
float32 VAR_Vcf_trqDesAdDmp_f32;       /* '<S54>/Switch2' */
float32 VAR_Vcf_KpNCtl_f32;            /* '<S35>/Switch2' */
float32 VAR_Vcf_trqLoad_f32;           /* '<S51>/Add1' */
float32 VAR_Vcf_trqDesUnProc_f32;      /* '<S53>/Chart1' */
float32 VAR_Vcf_trqRmp_f32;            /* '<S53>/Chart1' */
uint8 VAR_Vcf_CntAdding_u8;            /* '<S41>/Switch1' */
uint8 VAR_Vcf_SlopeChangePer_u8;       /* '<S40>/Switch15' */
boolean VAR_Vcf_flgDmpActv_b;          /* '<S49>/Logical Operator' */
boolean VAR_Vcf_AsrOvHiLim_b;          /* '<S46>/Relational Operator6' */
boolean VAR_Vcf_AsrUnLolim_b;          /* '<S46>/Relational Operator7' */
boolean VAR_Vcf_flgTrqSetPDecAsr_b;    /* '<S46>/Relational Operator1' */
boolean VAR_Vcf_AsrSlipFlg2_b;         /* '<S45>/Switch20' */
boolean VAR_Vcf_AsrSlipFlg1_b;         /* '<S45>/Switch19' */
boolean VAR_Vcf_AsrRatioUnLolim_b;     /* '<S45>/Switch13' */
boolean VAR_Vcf_SlipFlag_b;            /* '<S45>/Switch11' */
boolean VAR_Vcf_TranstoHoldIn_b;       /* '<S12>/Logical Operator3' */
boolean VAR_Vcf_TranstoHoldOut_b;      /* '<S13>/Logical Operator2' */
boolean VAR_VCF_flgHoldModeReq_b;      /* '<S9>/Switch' */
boolean VAR_Vcf_CrawlFlg_b;            /* '<S14>/Logical Operator5' */

/* Exported data definition */
#pragma section ".rodata.Calib_32"

/* Definition for custom storage class: iEDS_Parameter */
const volatile float32 CAL_Vcf_AccPedSet_f32 = 5.0F;/* Referenced by: '<S17>/Constant' */
const volatile float32 CAL_Vcf_ActiveCntAver_f32 = 0.02F;
                          /* Referenced by: '<S41>/CAL_TDC_ActiveCntAver_f32' */
const volatile uint8 CAL_Vcf_ActiveCnt_u8 = 50U;/* Referenced by:
                                                 * '<S43>/Constant'
                                                 * '<S44>/Constant'
                                                 */
const volatile float32 CAL_Vcf_AutoHoldSpd_f32 = 0.0F;
                            /* Referenced by: '<S31>/CAL_Vcf_AutoHoldSpd_f32' */
const volatile uint8 CAL_Vcf_BetLimSlope_u8 = 4U;/* Referenced by: '<S40>/Constant16' */
const volatile boolean CAL_Vcf_BrkLgt_b = 1;/* Referenced by: '<S18>/Constant' */
const volatile float32 CAL_Vcf_BwdHoldInSpdLim_f32 = -100.0F;
                        /* Referenced by: '<S12>/CAL_Vcf_BwdHoldInSpdLim_f32' */
const volatile float32 CAL_Vcf_BwdHoldOutSpdLim_f32 = -300.0F;/* Referenced by:
                                                               * '<S12>/CAL_Vcf_BwdHoldOutSpdLim_f32'
                                                               * '<S13>/CAL_Vcf_BwdHoldOutSpdLim_f32'
                                                               */
const volatile float32 CAL_Vcf_CofHoldTrq_f32 = 0.01F;
                              /* Referenced by: '<S8>/CAL_Vcf_CofHoldTrq_f32' */
const volatile float32 CAL_Vcf_CrawlDspd_f32 = 500.0F;/* Referenced by: '<S16>/Chart' */
const volatile float32 CAL_Vcf_CrawlNsetD_f32 = 600.0F;/* Referenced by:
                                                        * '<S15>/CAL_VCF_CrawlNsetD_f32'
                                                        * '<S16>/Chart'
                                                        */
const volatile float32 CAL_Vcf_CrawlNsetR_f32 = -500.0F;/* Referenced by:
                                                         * '<S15>/CAL_VCF_CrawlNsetR_f32'
                                                         * '<S16>/Chart'
                                                         */
const volatile float32 CAL_Vcf_CrawlRspd_f32 = -400.0F;/* Referenced by: '<S16>/Chart' */
const volatile boolean CAL_Vcf_CrawlSwt_b = 0;/* Referenced by: '<S14>/Constant6' */
const volatile float32 CAL_Vcf_CrawltrqLo_f32 = -45.0F;/* Referenced by: '<S16>/Constant10' */
const volatile float32 CAL_Vcf_CrawltrqUp_f32 = 45.0F;/* Referenced by: '<S16>/Constant9' */
const volatile float32 CAL_Vcf_Crawltrqadd1_f32 = 2.0F;/* Referenced by: '<S16>/Chart' */
const volatile float32 CAL_Vcf_Crawltrqadd2_f32 = 0.2F;/* Referenced by: '<S16>/Chart' */
const volatile float32 CAL_Vcf_Crawltrqsub_f32 = 1.0F;/* Referenced by: '<S16>/Chart' */
const volatile float32 CAL_Vcf_DampingMatrixA_af32[16] = { -8.33333302F,
  0.416666657F, 1.0F, 0.0F, 8.33333302F, -0.416666657F, -1.0F, 0.0F,
  -1166.66663F, 58.3333321F, 0.0F, 0.0F, 0.0F, 1.66666663F, 0.0F, 0.0F } ;
                        /* Referenced by: '<S51>/CAL_VCF_DampingMatrixA_af32' */

const volatile float32 CAL_Vcf_DampingMatrixB_af32[4] = { 33.3333321F, 0.0F,
  0.0F, 0.0F } ;        /* Referenced by: '<S51>/CAL_VCF_DampingMatrixB_af32' */

const volatile float32 CAL_Vcf_DampingMatrixC_af32[4] = { 1.0F, 0.0F, 0.0F, 0.0F
} ;                     /* Referenced by: '<S51>/CAL_VCF_DampingMatrixC_af32' */

const volatile float32 CAL_Vcf_DampingMatrixLp_af32[4] = { 101.25F, 60.0803566F,
  -2.32040811F, 270.0F } ;
                       /* Referenced by: '<S51>/CAL_VCF_DampingMatrixLp_af32' */

const volatile uint8 CAL_Vcf_Drv_go_alOffsetcalReq_u8 = 5U;
                   /* Referenced by: '<S53>/CAL_TDC_Drv_go_alOffsetcalReq_u8' */
const volatile boolean CAL_Vcf_FunctionReqSwt_b = 0;
                           /* Referenced by: '<S39>/CAL_Vcf_FunctionReqSwt_b' */
const volatile float32 CAL_Vcf_FwdHoldInSpdLim_f32 = 100.0F;
                        /* Referenced by: '<S12>/CAL_Vcf_FwdHoldInSpdLim_f32' */
const volatile float32 CAL_Vcf_FwdHoldOutSpdLim_f32 = 300.0F;/* Referenced by:
                                                              * '<S12>/CAL_Vcf_FwdHoldOutSpdLim_f32'
                                                              * '<S13>/CAL_Vcf_FwdHoldOutSpdLim_f32'
                                                              */
const volatile uint8 CAL_Vcf_GearD_u8 = 1U;/* Referenced by:
                                            * '<S16>/Chart'
                                            * '<S19>/Constant'
                                            * '<S23>/Constant'
                                            */
const volatile boolean CAL_Vcf_GearHoldOutSwt_b = 0;
                           /* Referenced by: '<S13>/CAL_Vcf_GearHoldOutSwt_b' */
const volatile uint8 CAL_Vcf_GearLvD_u8 = 1U;/* Referenced by:
                                              * '<S12>/CAL_VCF_GearLvD_u8'
                                              * '<S13>/CAL_VCF_GearLvD_u8'
                                              */
const volatile uint8 CAL_Vcf_GearLvN_u8 = 0U;
                                 /* Referenced by: '<S13>/CAL_Vcf_GearLvN_u8' */
const volatile uint8 CAL_Vcf_GearLvR_u8 = 2U;/* Referenced by:
                                              * '<S12>/CAL_VCF_GearLvR_u8'
                                              * '<S13>/CAL_VCF_GearLvR_u8'
                                              */
const volatile uint8 CAL_Vcf_GearR_u8 = 2U;/* Referenced by:
                                            * '<S16>/Chart'
                                            * '<S20>/Constant'
                                            * '<S24>/Constant'
                                            */
const volatile float32 CAL_Vcf_GenElecSpd_f32 = 50.0F;
                             /* Referenced by: '<S39>/CAL_Vcf_GenElecSpd_f32' */
const volatile float32 CAL_Vcf_HoldModVcuReq_u8 = 1.0F;/* Referenced by:
                                                        * '<S12>/CAL_Vcf_HoldModVcuReq_u8'
                                                        * '<S13>/CAL_Vcf_HoldModVcuReq_u8'
                                                        */
const volatile uint16 CAL_Vcf_HoldTimeCount_u16 = 400U;/* Referenced by: '<S9>/Chart' */
const volatile boolean CAL_Vcf_HoldTrqInSwt_b = 1;
                              /* Referenced by: '<S8>/CAL_Vcf_HoldTrqInSwt_b' */
const volatile boolean CAL_Vcf_HoldTrqLoadSwt_b = 1;
                            /* Referenced by: '<S8>/CAL_Vcf_HoldTrqLoadSwt_b' */
const volatile float32 CAL_Vcf_MotorDrvSpd_f32 = 20.0F;/* Referenced by: '<S39>/Constant2' */
const volatile float32 CAL_Vcf_NegDmpMaxSpeed_f32 = -4000.0F;
                         /* Referenced by: '<S49>/CAL_VCF_NegDmpMaxSpeed_f32' */
const volatile float32 CAL_Vcf_NegDmpMaxTrq_f32 = -310.0F;
                           /* Referenced by: '<S49>/CAL_VCF_NegDmpMaxTrq_f32' */
const volatile uint8 CAL_Vcf_NormalTrqSlope_u8 = 1U;/* Referenced by:
                                                     * '<S40>/Constant15'
                                                     * '<S40>/Constant21'
                                                     */
const volatile float32 CAL_Vcf_OvCrawlDspd_f32 = 1000.0F;/* Referenced by: '<S21>/Constant' */
const volatile float32 CAL_Vcf_OvCrawlRspd_f32 = 800.0F;/* Referenced by: '<S22>/Constant' */
const volatile uint8 CAL_Vcf_OvHiLimSlope_u8 = 2U;/* Referenced by: '<S40>/Constant12' */
const volatile float32 CAL_Vcf_PosDmpMaxSpeed_f32 = 4000.0F;
                         /* Referenced by: '<S49>/CAL_VCF_PosDmpMaxSpeed_f32' */
const volatile float32 CAL_Vcf_PosDmpMaxTrq_f32 = 310.0F;
                           /* Referenced by: '<S49>/CAL_VCF_PosDmpMaxTrq_f32' */
const volatile float32 CAL_Vcf_ReqTrqMechTrqDif_f32 = 10.0F;
                       /* Referenced by: '<S45>/CAL_Vcf_ReqTrqMechTrqDif_f32' */
const volatile float32 CAL_Vcf_SLCalTrqSlp_f32 = 1.0F;
                            /* Referenced by: '<S53>/CAL_VCF_SLCalTrqSlp_f32' */
const volatile uint8 CAL_Vcf_SpdCtlReq_u8 = 9U;
                               /* Referenced by: '<S14>/CAL_VCF_SpdCtlReq_u8' */
const volatile float32 CAL_Vcf_SpdDebounce_f32 = -0.3F;
                            /* Referenced by: '<S46>/CAL_Vcf_SpdDebounce_f32' */
const volatile uint8 CAL_Vcf_StandByReq_u8 = 3U;/* Referenced by: '<S14>/Constant7' */
const volatile boolean CAL_Vcf_StepSlopeFunSwt_b = 1;/* Referenced by: '<S29>/Constant' */
const volatile float32 CAL_Vcf_TrqAbsDiff_f32 = 20.0F;
                             /* Referenced by: '<S46>/CAL_Vcf_TrqAbsDiff_f32' */
const volatile uint8 CAL_Vcf_TrqCtlReq_u8 = 8U;
                               /* Referenced by: '<S14>/CAL_Csd_TrqCtlReq_u8' */
const volatile float32 CAL_Vcf_TrqDecRatio_f32 = 0.25F;
                            /* Referenced by: '<S46>/CAL_Vcf_TrqDecRatio_f32' */
const volatile float32 CAL_Vcf_TrqDmpNegMax_f32 = 10.0F;
                           /* Referenced by: '<S48>/CAL_Vcf_TrqDmpNegMax_f32' */
const volatile float32 CAL_Vcf_TrqDmpPosMax_f32 = 5.0F;
                           /* Referenced by: '<S48>/CAL_Vcf_TrqDmpPosMax_f32' */
const volatile boolean CAL_Vcf_TrqDmpSwt_b = 1;/* Referenced by:
                                                * '<S50>/CAL_Vcf_TrqDmpSwt_b'
                                                * '<S50>/CAL_Vcf_TrqDmpSwt_b1'
                                                */
const volatile float32 CAL_Vcf_TrqFbkLMaxNeg_f32 = -10.0F;
                                   /* Referenced by: '<S29>/StepSlopFunction' */
const volatile float32 CAL_Vcf_TrqFbkLMax_f32 = 10.0F;
                                   /* Referenced by: '<S29>/StepSlopFunction' */
const volatile float32 CAL_Vcf_TrqFbkLMinNeg_f32 = -10.0F;
                                   /* Referenced by: '<S29>/StepSlopFunction' */
const volatile float32 CAL_Vcf_TrqFbkLMin_f32 = 10.0F;
                                   /* Referenced by: '<S29>/StepSlopFunction' */
const volatile float32 CAL_Vcf_TrqHoldOutLim_f32 = 0.0F;
                          /* Referenced by: '<S13>/CAL_Vcf_TrqHoldOutLim_f32' */
const volatile float32 CAL_Vcf_TrqSlopAccMax_f32 = 1000.0F;
                                   /* Referenced by: '<S29>/StepSlopFunction' */
const volatile float32 CAL_Vcf_TrqSlopAccStep_f32 = 50.0F;
                                   /* Referenced by: '<S29>/StepSlopFunction' */
const volatile uint8 CAL_Vcf_UnLoLimSlope_u8 = 4U;/* Referenced by: '<S40>/Constant14' */
const volatile float32 CAL_Vcf_cnCtlNrm_f32 = 0.5F;/* Referenced by:
                                                    * '<S35>/CAL_Vcf_cnCtlNrm_f32_1'
                                                    * '<S35>/CAL_Vcf_cnCtlNrm_f32_2'
                                                    */
const volatile boolean CAL_Vcf_flgOpenCrawlFcn_b = 0;
                          /* Referenced by: '<S14>/CAL_VCF_flgOpenCrawlFcn_b' */
const volatile boolean CAL_Vcf_flgOpenHoldFcn_b = 0;
                            /* Referenced by: '<S9>/CAL_VCF_flgOpenHoldFcn_b' */
const volatile boolean CAL_Vcf_flgUseSLCal_b = 0;
                              /* Referenced by: '<S53>/CAL_VCF_flgUseSLCal_b' */
const volatile float32 CAL_Vcf_nAccChgHiLim_f32 = 10.0F;/* Referenced by:
                                                         * '<S40>/Constant11'
                                                         * '<S46>/CAL_Vcf_nAccChgHiLim_f32'
                                                         */
const volatile float32 CAL_Vcf_nAccChgLoLim_f32 = 5.0F;/* Referenced by:
                                                        * '<S40>/Constant13'
                                                        * '<S46>/CAL_Vcf_nAccChgLoLim_f32'
                                                        */
const volatile float32 CAL_Vcf_nSetRamp_f32 = 50.0F;/* Referenced by: '<S15>/Constant2' */
const volatile float32 CAL_Vcf_spdThredDmpNeg_f32 = -150.0F;
                         /* Referenced by: '<S48>/CAL_Vcf_spdThredDmpNeg_f32' */
const volatile float32 CAL_Vcf_spdThredDmpPos_f32 = -100.0F;
                         /* Referenced by: '<S48>/CAL_Vcf_spdThredDmpPos_f32' */
const volatile float32 CAL_Vcf_stModeReqTabX_af32[16] = { 0.0F, 1.0F, 2.0F, 3.0F,
  4.0F, 5.0F, 6.0F, 7.0F, 8.0F, 9.0F, 10.0F, 11.0F, 12.0F, 13.0F, 14.0F, 15.0F }
;                                  /* Referenced by: '<S30>/1-D Lookup Table' */

const volatile float32 CAL_Vcf_stModeReqTabY_af32[16] = { 0.0F, 255.0F, 255.0F,
  3.0F, 8.0F, 5.0F, 1.0F, 9.0F, 2.0F, 10.0F, 11.0F, 255.0F, 255.0F, 255.0F, 4.0F,
  12.0F } ;                        /* Referenced by: '<S30>/1-D Lookup Table' */

const volatile float32 CAL_Vcf_tDamping_f32 = 0.002F;
                               /* Referenced by: '<S51>/CAL_VCF_tDamping_f32' */
const volatile uint16 CAL_Vcf_tSlopAddMax_u16 = 2U;
                                   /* Referenced by: '<S29>/StepSlopFunction' */
const volatile float32 CAL_Vcf_trqHoldMax_f32 = 60.0F;
                              /* Referenced by: '<S8>/CAL_Vcf_trqHoldMax_f32' */
const volatile float32 CAL_Vcf_trqHoldMin_f32 = -60.0F;
                              /* Referenced by: '<S8>/CAL_Vcf_trqHoldMin_f32' */
const volatile float32 CAL_Vcf_trqSlopeCoffent_f32 = 0.002F;
                        /* Referenced by: '<S53>/CAL_TDC_trqSlopeCoffent_f32' */

#pragma section

/* Block signals (default storage) */
B_SWC_VCF_T SWC_VCF_B;

/* Block states (default storage) */
DW_SWC_VCF_T SWC_VCF_DW;

/* Model step function for TID1 */
void SWC_VCF_2ms(void)                 /* Explicit Task: RE_SWC_VCF_2ms */
{
  float32 tmpRead;
  uint8 tmpRead_0;
  uint8 tmpRead_1;
  float32 tmpRead_2;
  float32 tmpRead_3;
  uint8 tmpRead_4;
  uint8 tmpRead_5;
  float32 rtb_TmpSignalConversionAtRP__ln;
  float32 rtb_Add4;
  float32 rtb_CAL_VCF_DampingMatrixA_af32[4];
  float32 rtb_TmpSignalConversionAtRP_SWC;
  uint8 rtb_TmpSignalConversionAtRP_S_j;
  float32 rtb_TmpSignalConversionAtRP_S_p;
  float32 rtb_Abs1;
  float32 rtb_TmpSignalConversionAtRP_S_f;
  float32 rtb_TmpSignalConversionAtRP_S_e;
  boolean rtb_TmpSignalConversionAtIVD_hw;
  uint8 rtb_DataTypeConversion_o;
  boolean rtb_TmpSignalConversionAtIVDP_o;
  sint32 rtb_Switch5;
  float32 rtb_Switch2_a;
  float32 rtb_TmpSignalConversionAtRP_S_n;

  /* Inport: '<Root>/RP_SWC_CSPF_CSPF_RecstDmpCtLReq' */
  Rte_Read_RP_SWC_CSPF_CSPF_RecstDmpCtLReq(&rtb_DataTypeConversion_o);

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_VCF_2ms' incorporates:
   *  SubSystem: '<Root>/RE_SWC_VCF_2ms_sys'
   */
  /* Gain: '<S51>/CAL_VCF_DampingMatrixA_af32' incorporates:
   *  UnitDelay: '<S51>/Unit Delay'
   */
  for (rtb_Switch5 = 0; rtb_Switch5 < 4; rtb_Switch5++) {
    rtb_Add4 = CAL_Vcf_DampingMatrixA_af32[rtb_Switch5 + 12] *
      SWC_VCF_DW.UnitDelay_DSTATE[3] + (CAL_Vcf_DampingMatrixA_af32[rtb_Switch5
      + 8] * SWC_VCF_DW.UnitDelay_DSTATE[2] +
      (CAL_Vcf_DampingMatrixA_af32[rtb_Switch5 + 4] *
       SWC_VCF_DW.UnitDelay_DSTATE[1] + CAL_Vcf_DampingMatrixA_af32[rtb_Switch5]
       * SWC_VCF_DW.UnitDelay_DSTATE[0]));
    rtb_CAL_VCF_DampingMatrixA_af32[rtb_Switch5] = rtb_Add4;
  }

  /* End of Gain: '<S51>/CAL_VCF_DampingMatrixA_af32' */

  /* SignalConversion generated from: '<S2>/RP_SWC_TDC_TDC_TrqDes_read' incorporates:
   *  Inport: '<Root>/RP_SWC_TDC_TDC_TrqDes'
   */
  Rte_Read_RP_SWC_TDC_TDC_TrqDes(&rtb_TmpSignalConversionAtRP_SWC);

  /* SignalConversion generated from: '<S2>/RP_SWC_Rdc_Rdc_nWoFlt_read' incorporates:
   *  Inport: '<Root>/RP_SWC_Rdc_Rdc_nWoFlt'
   */
  Rte_Read_RP_SWC_Rdc_Rdc_nWoFlt(&rtb_TmpSignalConversionAtRP__ln);

  /* Sum: '<S51>/Add2' incorporates:
   *  Constant: '<S51>/AgVelCnvFac'
   *  Constant: '<S51>/VCF_GLB_pi_f32_1'
   *  Gain: '<S51>/CAL_VCF_DampingMatrixC_af32'
   *  Product: '<S51>/Product'
   *  UnitDelay: '<S51>/Unit Delay'
   */
  rtb_Add4 = rtb_TmpSignalConversionAtRP__ln * VCF_GLB_pi_f32 / 30.0F -
    (((CAL_Vcf_DampingMatrixC_af32[0] * SWC_VCF_DW.UnitDelay_DSTATE[0] +
       CAL_Vcf_DampingMatrixC_af32[1] * SWC_VCF_DW.UnitDelay_DSTATE[1]) +
      CAL_Vcf_DampingMatrixC_af32[2] * SWC_VCF_DW.UnitDelay_DSTATE[2]) +
     CAL_Vcf_DampingMatrixC_af32[3] * SWC_VCF_DW.UnitDelay_DSTATE[3]);

  /* Gain: '<S51>/CAL_VCF_DampingMatrixLp_af32' incorporates:
   *  UnitDelay: '<S51>/Unit Delay'
   */
  SWC_VCF_DW.UnitDelay_DSTATE[0] = CAL_Vcf_DampingMatrixLp_af32[0] * rtb_Add4;

  /* Sum: '<S51>/Add6' incorporates:
   *  Gain: '<S51>/CAL_VCF_DampingMatrixB_af32'
   *  Gain: '<S51>/CAL_VCF_tDamping_f32'
   *  Sum: '<S51>/Add'
   *  UnitDelay: '<S51>/Unit Delay'
   *  UnitDelay: '<S51>/Unit Delay1'
   */
  SWC_VCF_DW.UnitDelay_DSTATE[0] = ((CAL_Vcf_DampingMatrixB_af32[0] *
    rtb_TmpSignalConversionAtRP_SWC + rtb_CAL_VCF_DampingMatrixA_af32[0]) +
    SWC_VCF_DW.UnitDelay_DSTATE[0]) * CAL_Vcf_tDamping_f32 +
    SWC_VCF_DW.UnitDelay1_DSTATE[0];

  /* Gain: '<S51>/CAL_VCF_DampingMatrixLp_af32' incorporates:
   *  UnitDelay: '<S51>/Unit Delay'
   */
  SWC_VCF_DW.UnitDelay_DSTATE[1] = CAL_Vcf_DampingMatrixLp_af32[1] * rtb_Add4;

  /* Sum: '<S51>/Add6' incorporates:
   *  Gain: '<S51>/CAL_VCF_DampingMatrixB_af32'
   *  Gain: '<S51>/CAL_VCF_tDamping_f32'
   *  Sum: '<S51>/Add'
   *  UnitDelay: '<S51>/Unit Delay'
   *  UnitDelay: '<S51>/Unit Delay1'
   */
  SWC_VCF_DW.UnitDelay_DSTATE[1] = ((CAL_Vcf_DampingMatrixB_af32[1] *
    rtb_TmpSignalConversionAtRP_SWC + rtb_CAL_VCF_DampingMatrixA_af32[1]) +
    SWC_VCF_DW.UnitDelay_DSTATE[1]) * CAL_Vcf_tDamping_f32 +
    SWC_VCF_DW.UnitDelay1_DSTATE[1];

  /* Gain: '<S51>/CAL_VCF_DampingMatrixLp_af32' incorporates:
   *  UnitDelay: '<S51>/Unit Delay'
   */
  SWC_VCF_DW.UnitDelay_DSTATE[2] = CAL_Vcf_DampingMatrixLp_af32[2] * rtb_Add4;

  /* Sum: '<S51>/Add6' incorporates:
   *  Gain: '<S51>/CAL_VCF_DampingMatrixB_af32'
   *  Gain: '<S51>/CAL_VCF_tDamping_f32'
   *  Sum: '<S51>/Add'
   *  UnitDelay: '<S51>/Unit Delay'
   *  UnitDelay: '<S51>/Unit Delay1'
   */
  SWC_VCF_DW.UnitDelay_DSTATE[2] = ((CAL_Vcf_DampingMatrixB_af32[2] *
    rtb_TmpSignalConversionAtRP_SWC + rtb_CAL_VCF_DampingMatrixA_af32[2]) +
    SWC_VCF_DW.UnitDelay_DSTATE[2]) * CAL_Vcf_tDamping_f32 +
    SWC_VCF_DW.UnitDelay1_DSTATE[2];

  /* Gain: '<S51>/CAL_VCF_DampingMatrixLp_af32' incorporates:
   *  UnitDelay: '<S51>/Unit Delay'
   */
  SWC_VCF_DW.UnitDelay_DSTATE[3] = CAL_Vcf_DampingMatrixLp_af32[3] * rtb_Add4;

  /* Sum: '<S51>/Add6' incorporates:
   *  Gain: '<S51>/CAL_VCF_DampingMatrixB_af32'
   *  Gain: '<S51>/CAL_VCF_tDamping_f32'
   *  Sum: '<S51>/Add'
   *  UnitDelay: '<S51>/Unit Delay'
   *  UnitDelay: '<S51>/Unit Delay1'
   */
  SWC_VCF_DW.UnitDelay_DSTATE[3] = ((CAL_Vcf_DampingMatrixB_af32[3] *
    rtb_TmpSignalConversionAtRP_SWC + rtb_CAL_VCF_DampingMatrixA_af32[3]) +
    SWC_VCF_DW.UnitDelay_DSTATE[3]) * CAL_Vcf_tDamping_f32 +
    SWC_VCF_DW.UnitDelay1_DSTATE[3];

  /* Product: '<S51>/Product1' incorporates:
   *  Constant: '<S51>/AgVelCnvFac1'
   *  Constant: '<S51>/VCF_GLB_pi_f32_2'
   *  UnitDelay: '<S51>/Unit Delay'
   */
  VAR_Vcf_nMotorObsv_f32 = 30.0F * SWC_VCF_DW.UnitDelay_DSTATE[0] /
    VCF_GLB_pi_f32;

  /* Product: '<S51>/Product2' incorporates:
   *  Constant: '<S51>/AgVelCnvFac2'
   *  Constant: '<S51>/VCF_GLB_pi_f32_3'
   *  UnitDelay: '<S51>/Unit Delay'
   */
  VAR_Vcf_nVehicleObsv_f32 = 30.0F * SWC_VCF_DW.UnitDelay_DSTATE[1] /
    VCF_GLB_pi_f32;

  /* SignalConversion generated from: '<S2>/RP_SWC_SCF_SCF_stDrvCtl_read' incorporates:
   *  Inport: '<Root>/RP_SWC_SCF_SCF_stDrvCtl'
   */
  Rte_Read_RP_SWC_SCF_SCF_stDrvCtl(&rtb_TmpSignalConversionAtRP_S_j);

  /* SignalConversion generated from: '<S2>/RP_SWC_HSPF_HSPF_nSlowFlt_read' incorporates:
   *  Inport: '<Root>/RP_SWC_HSPF_HSPF_nSlowFlt'
   */
  Rte_Read_RP_SWC_HSPF_HSPF_nSlowFlt(&rtb_TmpSignalConversionAtRP_S_p);

  /* Logic: '<S49>/Logical Operator' incorporates:
   *  Constant: '<S49>/CAL_VCF_NegDmpMaxSpeed_f32'
   *  Constant: '<S49>/CAL_VCF_NegDmpMaxTrq_f32'
   *  Constant: '<S49>/CAL_VCF_PosDmpMaxSpeed_f32'
   *  Constant: '<S49>/CAL_VCF_PosDmpMaxTrq_f32'
   *  Constant: '<S49>/iEDS_Enum_stDrvCtl_def_Drv_TrqCtl'
   *  DataTypeConversion: '<S49>/Data Type Conversion'
   *  DataTypeConversion: '<S49>/Data Type Conversion1'
   *  Logic: '<S49>/Logical Operator1'
   *  Logic: '<S49>/Logical Operator2'
   *  RelationalOperator: '<S49>/Relational Operator1'
   *  RelationalOperator: '<S49>/Relational Operator2'
   *  RelationalOperator: '<S49>/Relational Operator3'
   *  RelationalOperator: '<S49>/Relational Operator4'
   *  RelationalOperator: '<S49>/Relational Operator5'
   */
  VAR_Vcf_flgDmpActv_b = ((rtb_DataTypeConversion_o != 0) &&
    (rtb_TmpSignalConversionAtRP_S_j == (sint32)Drv_TrqCtl) &&
    ((rtb_TmpSignalConversionAtRP_SWC <= CAL_Vcf_PosDmpMaxTrq_f32) &&
     (rtb_TmpSignalConversionAtRP_SWC >= CAL_Vcf_NegDmpMaxTrq_f32)) &&
    ((rtb_TmpSignalConversionAtRP_S_p <= CAL_Vcf_PosDmpMaxSpeed_f32) &&
     (rtb_TmpSignalConversionAtRP_S_p >= CAL_Vcf_NegDmpMaxSpeed_f32)));

  /* Switch: '<S50>/Switch' incorporates:
   *  Constant: '<S50>/Constant'
   *  Inport: '<Root>/RP_SWC_CSPF_CSPF_RecKpDmp'
   *  Product: '<S50>/Product'
   *  Sum: '<S50>/Subtract'
   */
  if (VAR_Vcf_flgDmpActv_b) {
    Rte_Read_RP_SWC_CSPF_CSPF_RecKpDmp(&tmpRead);
    VAR_Vcf_TrqDmp_f32 = -((VAR_Vcf_nMotorObsv_f32 - VAR_Vcf_nVehicleObsv_f32) *
      tmpRead);
  } else {
    VAR_Vcf_TrqDmp_f32 = 0.0F;
  }

  /* End of Switch: '<S50>/Switch' */

  /* Switch: '<S48>/Switch1' incorporates:
   *  Constant: '<S48>/CAL_Vcf_TrqDmpPosMax_f32'
   *  Constant: '<S48>/CAL_Vcf_spdThredDmpNeg_f32'
   *  Constant: '<S48>/CAL_Vcf_spdThredDmpPos_f32'
   *  RelationalOperator: '<S48>/Relational Operator'
   *  RelationalOperator: '<S48>/Relational Operator1'
   *  Switch: '<S48>/Switch2'
   *  UnitDelay: '<S48>/Unit Delay'
   */
  if (rtb_TmpSignalConversionAtRP_S_p >= CAL_Vcf_spdThredDmpPos_f32) {
    SWC_VCF_DW.UnitDelay_DSTATE_h = CAL_Vcf_TrqDmpPosMax_f32;
  } else {
    if (rtb_TmpSignalConversionAtRP_S_p <= CAL_Vcf_spdThredDmpNeg_f32) {
      /* Switch: '<S48>/Switch2' incorporates:
       *  Constant: '<S48>/CAL_Vcf_TrqDmpNegMax_f32'
       *  UnitDelay: '<S48>/Unit Delay'
       */
      SWC_VCF_DW.UnitDelay_DSTATE_h = CAL_Vcf_TrqDmpNegMax_f32;
    }
  }

  /* End of Switch: '<S48>/Switch1' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_VCF_2ms' */

  /* Inport: '<Root>/RP_SWC_CSPF_CSPF_RecTrqDmpMax' */
  Rte_Read_RP_SWC_CSPF_CSPF_RecTrqDmpMax(&rtb_Abs1);

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_VCF_2ms' incorporates:
   *  SubSystem: '<Root>/RE_SWC_VCF_2ms_sys'
   */
  /* Switch: '<S50>/Switch1' incorporates:
   *  Constant: '<S50>/CAL_Vcf_TrqDmpSwt_b'
   *  UnitDelay: '<S48>/Unit Delay'
   */
  if (CAL_Vcf_TrqDmpSwt_b) {
    rtb_Add4 = rtb_Abs1;
  } else {
    rtb_Add4 = SWC_VCF_DW.UnitDelay_DSTATE_h;
  }

  /* End of Switch: '<S50>/Switch1' */

  /* Switch: '<S52>/Switch2' incorporates:
   *  Constant: '<S50>/CAL_Vcf_TrqDmpSwt_b1'
   *  RelationalOperator: '<S52>/LowerRelop1'
   *  Switch: '<S50>/Switch2'
   */
  if (VAR_Vcf_TrqDmp_f32 > rtb_Add4) {
    VAR_Vcf_TrqDmp_f32 = rtb_Add4;
  } else {
    if (CAL_Vcf_TrqDmpSwt_b) {
      /* Switch: '<S50>/Switch2' incorporates:
       *  Inport: '<Root>/RP_SWC_CSPF_CSPF_RecTrqDmpMin'
       */
      Rte_Read_RP_SWC_CSPF_CSPF_RecTrqDmpMin(&rtb_Switch2_a);
    } else {
      /* Switch: '<S50>/Switch2' incorporates:
       *  Gain: '<S48>/Gain'
       *  UnitDelay: '<S48>/Unit Delay'
       */
      rtb_Switch2_a = -SWC_VCF_DW.UnitDelay_DSTATE_h;
    }

    /* Switch: '<S52>/Switch' incorporates:
     *  RelationalOperator: '<S52>/UpperRelop'
     */
    if (VAR_Vcf_TrqDmp_f32 < rtb_Switch2_a) {
      VAR_Vcf_TrqDmp_f32 = rtb_Switch2_a;
    }

    /* End of Switch: '<S52>/Switch' */
  }

  /* End of Switch: '<S52>/Switch2' */

  /* SignalConversion generated from: '<S2>/RP_SWC_CSPF_CSPF_RecTrqSetP_read' incorporates:
   *  Inport: '<Root>/RP_SWC_CSPF_CSPF_RecTrqSetP'
   */
  Rte_Read_RP_SWC_CSPF_CSPF_RecTrqSetP(&rtb_TmpSignalConversionAtRP_S_f);

  /* SignalConversion generated from: '<S2>/RP_SWC_MPC_MPC_TrqMechFlt_read' incorporates:
   *  Inport: '<Root>/RP_SWC_MPC_MPC_TrqMechFlt'
   */
  Rte_Read_RP_SWC_MPC_MPC_TrqMechFlt(&rtb_TmpSignalConversionAtRP_S_e);

  /* Chart: '<S29>/StepSlopFunction' */
  if (rtb_TmpSignalConversionAtRP_S_e >= 0.0F) {
    SWC_VCF_DW.count2 = 0U;
    if ((rtb_TmpSignalConversionAtRP_S_e <= CAL_Vcf_TrqFbkLMin_f32) &&
        (rtb_TmpSignalConversionAtRP_S_f != 0.0F)) {
      SWC_VCF_B.VCF_TrqSlop = CAL_Vcf_TrqSlopAccStep_f32;
    } else if ((rtb_TmpSignalConversionAtRP_S_e > CAL_Vcf_TrqFbkLMax_f32) &&
               (SWC_VCF_B.VCF_TrqSlop != CAL_Vcf_TrqSlopAccMax_f32)) {
      rtb_Switch5 = SWC_VCF_DW.count + 1;
      if (rtb_Switch5 > 65535) {
        rtb_Switch5 = 65535;
      }

      SWC_VCF_DW.count = (uint16)rtb_Switch5;
      if (SWC_VCF_DW.count > CAL_Vcf_tSlopAddMax_u16) {
        if (SWC_VCF_B.VCF_TrqSlop < CAL_Vcf_TrqSlopAccMax_f32) {
          SWC_VCF_B.VCF_TrqSlop += CAL_Vcf_TrqSlopAccStep_f32;
          SWC_VCF_DW.count = 0U;
        } else {
          SWC_VCF_B.VCF_TrqSlop = CAL_Vcf_TrqSlopAccMax_f32;
          SWC_VCF_DW.count = 0U;
        }
      }
    } else {
      SWC_VCF_B.VCF_TrqSlop = CAL_Vcf_TrqSlopAccMax_f32;
    }
  } else {
    SWC_VCF_DW.count = 0U;
    if ((rtb_TmpSignalConversionAtRP_S_e >= CAL_Vcf_TrqFbkLMinNeg_f32) &&
        (rtb_TmpSignalConversionAtRP_S_f != 0.0F)) {
      SWC_VCF_B.VCF_TrqSlop = CAL_Vcf_TrqSlopAccStep_f32;
    } else if ((rtb_TmpSignalConversionAtRP_S_e < CAL_Vcf_TrqFbkLMaxNeg_f32) &&
               (SWC_VCF_B.VCF_TrqSlop != CAL_Vcf_TrqSlopAccMax_f32)) {
      rtb_Switch5 = SWC_VCF_DW.count2 + 1;
      if (rtb_Switch5 > 65535) {
        rtb_Switch5 = 65535;
      }

      SWC_VCF_DW.count2 = (uint16)rtb_Switch5;
      if (SWC_VCF_DW.count2 > CAL_Vcf_tSlopAddMax_u16) {
        if (SWC_VCF_B.VCF_TrqSlop < CAL_Vcf_TrqSlopAccMax_f32) {
          SWC_VCF_B.VCF_TrqSlop += CAL_Vcf_TrqSlopAccStep_f32;
          SWC_VCF_DW.count2 = 0U;
        } else {
          SWC_VCF_B.VCF_TrqSlop = CAL_Vcf_TrqSlopAccMax_f32;
          SWC_VCF_DW.count2 = 0U;
        }
      }
    } else {
      SWC_VCF_B.VCF_TrqSlop = CAL_Vcf_TrqSlopAccMax_f32;
    }
  }

  /* End of Chart: '<S29>/StepSlopFunction' */

  /* Abs: '<S41>/Abs1' */
  rtb_Abs1 = fabsf(rtb_TmpSignalConversionAtRP__ln);

  /* Sum: '<S41>/Add4' incorporates:
   *  Sum: '<S41>/Add3'
   *  UnitDelay: '<S41>/Unit Delay1'
   *  UnitDelay: '<S41>/Unit Delay5'
   */
  rtb_Add4 = (rtb_Abs1 - SWC_VCF_DW.UnitDelay1_DSTATE_i) +
    SWC_VCF_DW.UnitDelay5_DSTATE;

  /* Product: '<S41>/Divide' incorporates:
   *  Constant: '<S41>/CAL_TDC_ActiveCntAver_f32'
   */
  VAR_Vcf_SpdChangeRatio_f32 = rtb_Add4 * CAL_Vcf_ActiveCntAver_f32;

  /* RelationalOperator: '<S46>/Relational Operator6' incorporates:
   *  Constant: '<S46>/CAL_Vcf_nAccChgHiLim_f32'
   */
  VAR_Vcf_AsrOvHiLim_b = (VAR_Vcf_SpdChangeRatio_f32 > CAL_Vcf_nAccChgHiLim_f32);

  /* Sum: '<S46>/Add' incorporates:
   *  Abs: '<S46>/Abs2'
   *  Abs: '<S46>/Abs3'
   */
  rtb_TmpSignalConversionAtRP_S_e = fabsf(rtb_TmpSignalConversionAtRP_S_f) -
    fabsf(rtb_TmpSignalConversionAtRP_S_e);

  /* RelationalOperator: '<S46>/Relational Operator7' incorporates:
   *  Constant: '<S46>/CAL_Vcf_nAccChgLoLim_f32'
   */
  VAR_Vcf_AsrUnLolim_b = (VAR_Vcf_SpdChangeRatio_f32 < CAL_Vcf_nAccChgLoLim_f32);

  /* RelationalOperator: '<S46>/Relational Operator1' incorporates:
   *  UnitDelay: '<S46>/Unit Delay4'
   */
  VAR_Vcf_flgTrqSetPDecAsr_b = (VAR_Vcf_TrqSrtPInside_f32 >=
    rtb_TmpSignalConversionAtRP_S_f);

  /* Switch: '<S46>/Switch' incorporates:
   *  Constant: '<S46>/CAL_Vcf_SpdDebounce_f32'
   *  RelationalOperator: '<S46>/Relational Operator4'
   */
  if (VAR_Vcf_SpdChangeRatio_f32 >= CAL_Vcf_SpdDebounce_f32) {
    /* Switch: '<S46>/Switch6' incorporates:
     *  Constant: '<S46>/CAL_Vcf_TrqAbsDiff_f32'
     *  Constant: '<S46>/CAL_Vcf_TrqDecRatio_f32'
     *  Logic: '<S46>/Logical Operator2'
     *  Product: '<S46>/Divide1'
     *  RelationalOperator: '<S46>/Relational Operator'
     *  Switch: '<S46>/Switch12'
     *  Switch: '<S46>/Switch9'
     *  UnitDelay: '<S45>/Unit Delay3'
     */
    if (VAR_Vcf_AsrOvHiLim_b && (rtb_TmpSignalConversionAtRP_S_e >=
         CAL_Vcf_TrqAbsDiff_f32)) {
      VAR_Vcf_TrqSrtPInside_f32 = rtb_TmpSignalConversionAtRP_S_f *
        CAL_Vcf_TrqDecRatio_f32;
    } else if (VAR_Vcf_AsrUnLolim_b) {
      /* Switch: '<S46>/Switch3' incorporates:
       *  Switch: '<S46>/Switch12'
       *  UnitDelay: '<S45>/Unit Delay3'
       */
      if (VAR_Vcf_SlipFlag_b) {
        /* Switch: '<S46>/Switch4' */
        if (VAR_Vcf_flgTrqSetPDecAsr_b) {
          VAR_Vcf_TrqSrtPInside_f32 = rtb_TmpSignalConversionAtRP_S_f;
        }

        /* End of Switch: '<S46>/Switch4' */
      } else {
        VAR_Vcf_TrqSrtPInside_f32 = rtb_TmpSignalConversionAtRP_S_f;
      }

      /* End of Switch: '<S46>/Switch3' */
    } else if (VAR_Vcf_SlipFlag_b) {
      /* Switch: '<S46>/Switch10' incorporates:
       *  RelationalOperator: '<S46>/Relational Operator3'
       *  Switch: '<S46>/Switch12'
       *  Switch: '<S46>/Switch9'
       *  UnitDelay: '<S46>/Unit Delay4'
       */
      if (VAR_Vcf_TrqSrtPInside_f32 >= rtb_TmpSignalConversionAtRP_S_f) {
        VAR_Vcf_TrqSrtPInside_f32 = rtb_TmpSignalConversionAtRP_S_f;
      }

      /* End of Switch: '<S46>/Switch10' */
    } else {
      /* Switch: '<S46>/Switch12' incorporates:
       *  Switch: '<S46>/Switch9'
       */
      VAR_Vcf_TrqSrtPInside_f32 = rtb_TmpSignalConversionAtRP_S_f;
    }

    /* End of Switch: '<S46>/Switch6' */
  } else {
    VAR_Vcf_TrqSrtPInside_f32 = rtb_TmpSignalConversionAtRP_S_f;
  }

  /* End of Switch: '<S46>/Switch' */

  /* Switch: '<S39>/Switch5' incorporates:
   *  Constant: '<S39>/CAL_Vcf_FunctionReqSwt_b'
   *  Constant: '<S39>/Constant9'
   */
  if (CAL_Vcf_FunctionReqSwt_b) {
    /* Switch: '<S39>/Switch1' incorporates:
     *  Constant: '<S39>/Constant'
     *  Inport: '<Root>/RP_SWC_TPC_TPC_SgnRotDir'
     *  Inport: '<Root>/RP_SWC_TPC_TPC_SgnTrqMechDir'
     *  Logic: '<S39>/Logical Operator1'
     *  RelationalOperator: '<S39>/Relational Operator2'
     *  RelationalOperator: '<S39>/Relational Operator3'
     *  RelationalOperator: '<S39>/Relational Operator4'
     */
    if ((rtb_TmpSignalConversionAtRP_S_j == SWC_VCF_ConstB.DataTypeConversion_d)
        || (rtb_TmpSignalConversionAtRP_S_j ==
            SWC_VCF_ConstB.DataTypeConversion1) ||
        (rtb_TmpSignalConversionAtRP_S_j == SWC_VCF_ConstB.DataTypeConversion2))
    {
      Rte_Read_RP_SWC_TPC_TPC_SgnTrqMechDir(&tmpRead_1);
      Rte_Read_RP_SWC_TPC_TPC_SgnRotDir(&tmpRead_0);

      /* Switch: '<S39>/Switch2' incorporates:
       *  Abs: '<S39>/Abs'
       *  Abs: '<S39>/Abs1'
       *  Constant: '<S39>/CAL_Vcf_GenElecSpd_f32'
       *  Constant: '<S39>/Constant1'
       *  Constant: '<S39>/Constant2'
       *  Inport: '<Root>/RP_SWC_TPC_TPC_SgnRotDir'
       *  Inport: '<Root>/RP_SWC_TPC_TPC_SgnTrqMechDir'
       *  RelationalOperator: '<S39>/Relational Operator1'
       *  RelationalOperator: '<S39>/Relational Operator5'
       *  RelationalOperator: '<S39>/Relational Operator6'
       *  Sum: '<S39>/Add'
       */
      if ((uint8)((uint32)tmpRead_0 + tmpRead_1) == 3) {
        rtb_Switch5 = (fabsf(rtb_TmpSignalConversionAtRP_S_p) >=
                       CAL_Vcf_GenElecSpd_f32);
      } else {
        rtb_Switch5 = (fabsf(rtb_TmpSignalConversionAtRP_S_p) >=
                       CAL_Vcf_MotorDrvSpd_f32);
      }

      /* End of Switch: '<S39>/Switch2' */
    } else {
      rtb_Switch5 = 0;
    }

    /* End of Switch: '<S39>/Switch1' */
  } else {
    rtb_Switch5 = 0;
  }

  /* End of Switch: '<S39>/Switch5' */

  /* SignalConversion generated from: '<S2>/IVDP_VCF_CrawlFlg_read' incorporates:
   *  SignalConversion generated from: '<S1>/IVDP_VCF_CrawlFlg_write'
   */
  rtb_TmpSignalConversionAtIVD_hw =
    Rte_IrvIRead_RE_SWC_VCF_2ms_IVDP_VCF_CrawlFlg();

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_VCF_2ms' */

  /* Inport: '<Root>/RP_SWC_CSPF_CSPF_RecstModeReq' */
  Rte_Read_RP_SWC_CSPF_CSPF_RecstModeReq(&tmpRead_4);

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_VCF_2ms' incorporates:
   *  SubSystem: '<Root>/RE_SWC_VCF_2ms_sys'
   */
  /* DataTypeConversion: '<S30>/Data Type Conversion' incorporates:
   *  DataTypeConversion: '<S30>/Data Type Conversion1'
   *  Lookup_n-D: '<S30>/1-D Lookup Table'
   */
  rtb_TmpSignalConversionAtRP_S_p = fmodf(floorf(look1_iflf_binlcapw(tmpRead_4,
    ((const float32 *)&(CAL_Vcf_stModeReqTabX_af32[0])), ((const float32 *)
    &(CAL_Vcf_stModeReqTabY_af32[0])), 15U)), 256.0F);
  rtb_DataTypeConversion_o = (uint8)(rtb_TmpSignalConversionAtRP_S_p < 0.0F ?
    (sint32)(uint8)-(sint8)(uint8)-rtb_TmpSignalConversionAtRP_S_p : (sint32)
    (uint8)rtb_TmpSignalConversionAtRP_S_p);

  /* SignalConversion generated from: '<S2>/IVDP_VCF_flgHoldModeReq_read' incorporates:
   *  SignalConversion generated from: '<S1>/IVDP_VCF_flgHoldModeReq_write'
   */
  rtb_TmpSignalConversionAtIVDP_o =
    Rte_IrvIRead_RE_SWC_VCF_2ms_IVDP_VCF_flgHoldModeReq();

  /* Switch: '<S31>/Switch1' incorporates:
   *  Constant: '<S31>/PRV_SpdCtl_u8'
   *  Switch: '<S31>/Switch'
   */
  if (rtb_TmpSignalConversionAtIVDP_o) {
    rtb_TmpSignalConversionAtRP_S_j = ((uint8)PRV_SpdCtl_u8);
  } else if (rtb_TmpSignalConversionAtIVD_hw) {
    /* Switch: '<S31>/Switch' incorporates:
     *  SignalConversion generated from: '<S1>/IVDP_VCF_CrawlModeReq_write'
     *  SignalConversion generated from: '<S2>/IVDP_VCF_CrawlModeReq_read'
     */
    rtb_TmpSignalConversionAtRP_S_j =
      Rte_IrvIRead_RE_SWC_VCF_2ms_IVDP_VCF_CrawlModeReq();
  } else {
    rtb_TmpSignalConversionAtRP_S_j = rtb_DataTypeConversion_o;
  }

  /* End of Switch: '<S31>/Switch1' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_VCF_2ms' */

  /* Inport: '<Root>/RP_SWC_CSPF_CSPF_RecTrqSLope' */
  Rte_Read_RP_SWC_CSPF_CSPF_RecTrqSLope(&VAR_Vcf_SlopeReq_f32);

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_VCF_2ms' incorporates:
   *  SubSystem: '<Root>/RE_SWC_VCF_2ms_sys'
   */
  /* Switch: '<S29>/Switch' incorporates:
   *  Constant: '<S29>/Constant'
   *  Inport: '<Root>/RP_SWC_CSPF_CSPF_RecTrqSLope'
   */
  if (CAL_Vcf_StepSlopeFunSwt_b) {
    VAR_Vcf_SlopeReq_f32 = SWC_VCF_B.VCF_TrqSlop;
  }

  /* End of Switch: '<S29>/Switch' */

  /* Sum: '<S41>/Add1' incorporates:
   *  UnitDelay: '<S41>/Unit Delay2'
   */
  VAR_Vcf_CntAdding_u8 = (uint8)((uint32)VAR_Vcf_CntAdding_u8 +
    SWC_VCF_DW.UnitDelay2_DSTATE);

  /* Switch: '<S41>/Switch1' incorporates:
   *  Constant: '<S41>/Constant'
   *  Constant: '<S43>/Constant'
   *  RelationalOperator: '<S43>/Compare'
   */
  if (VAR_Vcf_CntAdding_u8 > CAL_Vcf_ActiveCnt_u8) {
    VAR_Vcf_CntAdding_u8 = 0U;
  }

  /* End of Switch: '<S41>/Switch1' */

  /* Switch: '<S40>/Switch15' incorporates:
   *  Constant: '<S40>/Constant11'
   *  Constant: '<S40>/Constant12'
   *  Constant: '<S40>/Constant13'
   *  RelationalOperator: '<S40>/Relational Operator4'
   *  RelationalOperator: '<S40>/Relational Operator5'
   *  Switch: '<S40>/Switch16'
   *  Switch: '<S40>/Switch18'
   *  UnitDelay: '<S37>/Unit Delay'
   */
  if (VAR_Vcf_SpdChangeRatio_f32 > CAL_Vcf_nAccChgHiLim_f32) {
    VAR_Vcf_SlopeChangePer_u8 = CAL_Vcf_OvHiLimSlope_u8;
  } else if (VAR_Vcf_SpdChangeRatio_f32 < CAL_Vcf_nAccChgLoLim_f32) {
    /* Switch: '<S40>/Switch17' incorporates:
     *  Constant: '<S40>/Constant14'
     *  Constant: '<S40>/Constant15'
     *  Logic: '<S40>/Logical Operator'
     *  Switch: '<S40>/Switch16'
     *  UnitDelay: '<S37>/Unit Delay'
     */
    if ((VAR_Vcf_CntAdding_u8 != 0) && SWC_VCF_DW.UnitDelay_DSTATE_i) {
      VAR_Vcf_SlopeChangePer_u8 = CAL_Vcf_UnLoLimSlope_u8;
    } else {
      VAR_Vcf_SlopeChangePer_u8 = CAL_Vcf_NormalTrqSlope_u8;
    }

    /* End of Switch: '<S40>/Switch17' */
  } else if (SWC_VCF_DW.UnitDelay_DSTATE_i) {
    /* Switch: '<S40>/Switch18' incorporates:
     *  Constant: '<S40>/Constant16'
     *  Switch: '<S40>/Switch16'
     */
    VAR_Vcf_SlopeChangePer_u8 = CAL_Vcf_BetLimSlope_u8;
  } else {
    /* Switch: '<S40>/Switch16' incorporates:
     *  Constant: '<S40>/Constant21'
     *  Switch: '<S40>/Switch18'
     */
    VAR_Vcf_SlopeChangePer_u8 = CAL_Vcf_NormalTrqSlope_u8;
  }

  /* End of Switch: '<S40>/Switch15' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_VCF_2ms' */

  /* Inport: '<Root>/RP_SWC_PCF_PCF_stParkCtl' */
  Rte_Read_RP_SWC_PCF_PCF_stParkCtl(&tmpRead_5);

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_VCF_2ms' incorporates:
   *  SubSystem: '<Root>/RE_SWC_VCF_2ms_sys'
   */
  /* Chart: '<S53>/Chart1' incorporates:
   *  Constant: '<S53>/CAL_TDC_Drv_go_alOffsetcalReq_u8'
   *  Constant: '<S53>/CAL_TDC_trqSlopeCoffent_f32'
   *  Constant: '<S53>/CAL_VCF_SLCalTrqSlp_f32'
   *  Constant: '<S53>/CAL_VCF_flgUseSLCal_b'
   *  Constant: '<S53>/SLCtl'
   *  Inport: '<Root>/RP_SWC_PCF_PCF_SLtrqDes'
   *  Inport: '<Root>/RP_SWC_RCF_RCF_TrqEmDesOfsClb'
   *  Inport: '<Root>/RP_SWC_RCF_RCF_cTrqSlpOfsClb'
   *  Logic: '<S53>/Logical Operator'
   *  Product: '<S53>/Product'
   *  RelationalOperator: '<S53>/Relational Operator'
   *  RelationalOperator: '<S53>/Relational Operator1'
   *  Switch: '<S31>/Switch3'
   *  Switch: '<S39>/Switch6'
   */
  if (rtb_TmpSignalConversionAtRP_S_j == CAL_Vcf_Drv_go_alOffsetcalReq_u8) {
    Rte_Read_RP_SWC_RCF_RCF_cTrqSlpOfsClb(&VAR_Vcf_trqRmp_f32);
    Rte_Read_RP_SWC_RCF_RCF_TrqEmDesOfsClb(&VAR_Vcf_trqDesUnProc_f32);
  } else if ((tmpRead_5 == 3) && CAL_Vcf_flgUseSLCal_b) {
    Rte_Read_RP_SWC_PCF_PCF_SLtrqDes(&VAR_Vcf_trqDesUnProc_f32);
    VAR_Vcf_trqRmp_f32 = CAL_Vcf_SLCalTrqSlp_f32;
  } else {
    if (rtb_TmpSignalConversionAtIVD_hw) {
      /* Switch: '<S31>/Switch3' incorporates:
       *  SignalConversion generated from: '<S1>/IVDP_VCF_RecCrawlTrqSetP_write'
       *  SignalConversion generated from: '<S2>/IVDP_VCF_RecCrawlTrqSetP_read'
       */
      VAR_Vcf_trqDesUnProc_f32 =
        Rte_IrvIRead_RE_SWC_VCF_2ms_IVDP_VCF_RecCrawlTrqSetP();
    } else if (rtb_Switch5 != 0) {
      /* Switch: '<S39>/Switch6' incorporates:
       *  Switch: '<S31>/Switch3'
       */
      VAR_Vcf_trqDesUnProc_f32 = VAR_Vcf_TrqSrtPInside_f32;
    } else {
      VAR_Vcf_trqDesUnProc_f32 = rtb_TmpSignalConversionAtRP_S_f;
    }

    /* Switch: '<S39>/Switch7' incorporates:
     *  Product: '<S38>/Product'
     *  Switch: '<S31>/Switch3'
     *  Switch: '<S39>/Switch6'
     */
    if (rtb_Switch5 != 0) {
      rtb_TmpSignalConversionAtRP_S_f = (float32)VAR_Vcf_SlopeChangePer_u8 *
        VAR_Vcf_SlopeReq_f32;
    } else {
      rtb_TmpSignalConversionAtRP_S_f = VAR_Vcf_SlopeReq_f32;
    }

    /* End of Switch: '<S39>/Switch7' */
    VAR_Vcf_trqRmp_f32 = rtb_TmpSignalConversionAtRP_S_f *
      CAL_Vcf_trqSlopeCoffent_f32;
  }

  /* End of Chart: '<S53>/Chart1' */

  /* Sum: '<S54>/Add' incorporates:
   *  Sum: '<S53>/Add'
   */
  VAR_Vcf_trqDesAdDmp_f32 = VAR_Vcf_TrqDmp_f32 + VAR_Vcf_trqDesUnProc_f32;

  /* Switch: '<S54>/Switch2' incorporates:
   *  Constant: '<S54>/Constant'
   *  Constant: '<S54>/Constant1'
   *  Product: '<S54>/Product'
   *  RelationalOperator: '<S54>/Relational Operator'
   *  Sum: '<S53>/Add'
   */
  if (VAR_Vcf_trqDesUnProc_f32 * VAR_Vcf_trqDesAdDmp_f32 <= 0.0F) {
    VAR_Vcf_trqDesAdDmp_f32 = 0.0F;
  }

  /* End of Switch: '<S54>/Switch2' */

  /* Outport: '<Root>/PP_SWC_VCF_VCF_TrqDes' incorporates:
   *  Sum: '<S54>/Add1'
   */
  (void) Rte_Write_PP_SWC_VCF_VCF_TrqDes(VAR_Vcf_trqDesAdDmp_f32);

  /* Switch: '<S41>/Switch2' incorporates:
   *  Constant: '<S41>/Constant9'
   *  Constant: '<S44>/Constant'
   *  RelationalOperator: '<S44>/Compare'
   *  UnitDelay: '<S41>/Unit Delay5'
   */
  if (VAR_Vcf_CntAdding_u8 == CAL_Vcf_ActiveCnt_u8) {
    SWC_VCF_DW.UnitDelay5_DSTATE = 0.0F;
  } else {
    SWC_VCF_DW.UnitDelay5_DSTATE = rtb_Add4;
  }

  /* End of Switch: '<S41>/Switch2' */

  /* SignalConversion generated from: '<S2>/RP_SWC_CSPF_CSPF_RecNSetP_read' incorporates:
   *  Inport: '<Root>/RP_SWC_CSPF_CSPF_RecNSetP'
   */
  Rte_Read_RP_SWC_CSPF_CSPF_RecNSetP(&rtb_TmpSignalConversionAtRP_S_n);

  /* Switch: '<S31>/Switch4' incorporates:
   *  Switch: '<S31>/Switch5'
   */
  if (rtb_TmpSignalConversionAtIVDP_o) {
    /* Outport: '<Root>/PP_SWC_VCF_VCF_NsetPReq' incorporates:
     *  Constant: '<S31>/CAL_Vcf_AutoHoldSpd_f32'
     */
    (void) Rte_Write_PP_SWC_VCF_VCF_NsetPReq(CAL_Vcf_AutoHoldSpd_f32);
  } else {
    if (rtb_TmpSignalConversionAtIVD_hw) {
      /* Switch: '<S31>/Switch5' incorporates:
       *  SignalConversion generated from: '<S1>/IVDP_VCF_RecCrawlNSetP_write'
       *  SignalConversion generated from: '<S2>/IVDP_VCF_RecCrawlNSetP_read'
       */
      rtb_Add4 = Rte_IrvIRead_RE_SWC_VCF_2ms_IVDP_VCF_RecCrawlNSetP();
    } else {
      /* Switch: '<S31>/Switch5' */
      rtb_Add4 = rtb_TmpSignalConversionAtRP_S_n;
    }

    /* Outport: '<Root>/PP_SWC_VCF_VCF_NsetPReq' */
    (void) Rte_Write_PP_SWC_VCF_VCF_NsetPReq(rtb_Add4);
  }

  /* End of Switch: '<S31>/Switch4' */

  /* Switch: '<S35>/Switch2' incorporates:
   *  Constant: '<S35>/CAL_Vcf_go_nCtlExtReq_u8'
   *  Constant: '<S35>/Constant1'
   *  Inport: '<Root>/RP_SWC_CSPF_CSPF_RecNDiffMax'
   *  RelationalOperator: '<S35>/Relational Operator1'
   */
  if (rtb_DataTypeConversion_o == ((uint8)PRV_SpdCtl_u8)) {
    Rte_Read_RP_SWC_CSPF_CSPF_RecNDiffMax(&tmpRead_3);

    /* Switch: '<S35>/Switch' incorporates:
     *  Abs: '<S35>/Abs'
     *  Constant: '<S35>/CAL_Vcf_cnCtlNrm_f32_1'
     *  Constant: '<S35>/CAL_Vcf_cnCtlNrm_f32_2'
     *  Inport: '<Root>/RP_SWC_CSPF_CSPF_RecKpHighNCtL'
     *  Inport: '<Root>/RP_SWC_CSPF_CSPF_RecKpLowNCtL'
     *  Inport: '<Root>/RP_SWC_CSPF_CSPF_RecNDiffMax'
     *  Product: '<S35>/Product'
     *  Product: '<S35>/Product1'
     *  RelationalOperator: '<S35>/Relational Operator'
     *  Sum: '<S35>/Add'
     */
    if (fabsf(rtb_TmpSignalConversionAtRP_S_n - rtb_TmpSignalConversionAtRP__ln)
        <= tmpRead_3) {
      Rte_Read_RP_SWC_CSPF_CSPF_RecKpLowNCtL(&tmpRead_2);
      VAR_Vcf_KpNCtl_f32 = tmpRead_2 * CAL_Vcf_cnCtlNrm_f32;
    } else {
      Rte_Read_RP_SWC_CSPF_CSPF_RecKpHighNCtL(&tmpRead_2);
      VAR_Vcf_KpNCtl_f32 = tmpRead_2 * CAL_Vcf_cnCtlNrm_f32;
    }

    /* End of Switch: '<S35>/Switch' */
  } else {
    VAR_Vcf_KpNCtl_f32 = 0.0F;
  }

  /* End of Switch: '<S35>/Switch2' */

  /* Outport: '<Root>/PP_SWC_VCF_VCF_KpNCtl' incorporates:
   *  Sum: '<S35>/Add1'
   */
  (void) Rte_Write_PP_SWC_VCF_VCF_KpNCtl(VAR_Vcf_KpNCtl_f32);

  /* Switch: '<S45>/Switch20' incorporates:
   *  Constant: '<S45>/CAL_Vcf_ReqTrqMechTrqDif_f32'
   *  Constant: '<S45>/Constant18'
   *  Constant: '<S45>/Constant22'
   *  RelationalOperator: '<S45>/Relational Operator2'
   *  Switch: '<S45>/Switch14'
   *  Switch: '<S45>/Switch19'
   *  UnitDelay: '<S45>/Unit Delay3'
   */
  if (VAR_Vcf_SlipFlag_b) {
    VAR_Vcf_AsrSlipFlg2_b = !VAR_Vcf_flgTrqSetPDecAsr_b;
    VAR_Vcf_AsrSlipFlg1_b = (rtb_TmpSignalConversionAtRP_S_e >
      CAL_Vcf_ReqTrqMechTrqDif_f32);
  } else {
    VAR_Vcf_AsrSlipFlg2_b = false;
    VAR_Vcf_AsrSlipFlg1_b = false;
  }

  /* End of Switch: '<S45>/Switch20' */

  /* Switch: '<S45>/Switch13' */
  if (VAR_Vcf_AsrUnLolim_b) {
    VAR_Vcf_AsrRatioUnLolim_b = VAR_Vcf_AsrSlipFlg1_b;
  } else {
    VAR_Vcf_AsrRatioUnLolim_b = VAR_Vcf_AsrSlipFlg2_b;
  }

  /* End of Switch: '<S45>/Switch13' */

  /* Switch: '<S45>/Switch11' */
  VAR_Vcf_SlipFlag_b = (VAR_Vcf_AsrOvHiLim_b || VAR_Vcf_AsrRatioUnLolim_b);

  /* Sum: '<S51>/Add1' incorporates:
   *  UnitDelay: '<S51>/Unit Delay'
   */
  VAR_Vcf_trqLoad_f32 = SWC_VCF_DW.UnitDelay_DSTATE[3];

  /* Update for UnitDelay: '<S51>/Unit Delay1' incorporates:
   *  UnitDelay: '<S51>/Unit Delay'
   */
  SWC_VCF_DW.UnitDelay1_DSTATE[0] = SWC_VCF_DW.UnitDelay_DSTATE[0];
  SWC_VCF_DW.UnitDelay1_DSTATE[1] = SWC_VCF_DW.UnitDelay_DSTATE[1];
  SWC_VCF_DW.UnitDelay1_DSTATE[2] = SWC_VCF_DW.UnitDelay_DSTATE[2];
  SWC_VCF_DW.UnitDelay1_DSTATE[3] = SWC_VCF_DW.UnitDelay_DSTATE[3];

  /* Update for UnitDelay: '<S41>/Unit Delay1' */
  SWC_VCF_DW.UnitDelay1_DSTATE_i = rtb_Abs1;

  /* Update for UnitDelay: '<S41>/Unit Delay2' incorporates:
   *  Constant: '<S41>/Constant1'
   */
  SWC_VCF_DW.UnitDelay2_DSTATE = 1U;

  /* Update for UnitDelay: '<S37>/Unit Delay' */
  SWC_VCF_DW.UnitDelay_DSTATE_i = VAR_Vcf_SlipFlag_b;

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_VCF_2ms' */

  /* Outport: '<Root>/PP_SWC_VCF_VCF_trqDesUnProc' */
  (void) Rte_Write_PP_SWC_VCF_VCF_trqDesUnProc(0.0F);

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_VCF_2ms' incorporates:
   *  SubSystem: '<Root>/RE_SWC_VCF_2ms_sys'
   */
  /* Outport: '<Root>/PP_SWC_VCF_VCF_trqRamp' incorporates:
   *  Sum: '<S53>/Add1'
   */
  (void) Rte_Write_PP_SWC_VCF_VCF_trqRamp(VAR_Vcf_trqRmp_f32);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_VCF_2ms' */

  /* Outport: '<Root>/PP_SWC_VCF_VCF_stModeReq' */
  (void) Rte_Write_PP_SWC_VCF_VCF_stModeReq(rtb_TmpSignalConversionAtRP_S_j);
}

/* Model step function for TID2 */
void SWC_VCF_10ms(void)                /* Explicit Task: RE_SWC_VCF_10ms */
{
  boolean rtb_RP_SWC_FIM_MtrOvTempWarn__a;
  float32 rtb_TmpSignalConversionAtRP_SWC;
  boolean rtb_LogicalOperator1_o;
  boolean rtb_RP_SWC_FIM_IGBTOvTempWarn_p;
  uint8 rtb_TmpSignalConversionAtRP_S_j;
  float32 rtb_TmpSignalConversionAtRP_S_h;
  float32 rtb_TmpSignalConversionAtRP_S_o;
  float32 rtb_TmpSignalConversionAtRP_S_a;
  float64 rtb_Switch2_m;
  float64 rtb_Add;
  float32 rtb_TmpSignalConversionAtRP_S_n;
  sint32 tmp;

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_VCF_10ms' incorporates:
   *  SubSystem: '<Root>/RE_SWC_VCF_10ms_sys'
   */
  /* SignalConversion generated from: '<S1>/RP_SWC_Rdc_Rdc_nWoFlt_read' incorporates:
   *  Inport: '<Root>/RP_SWC_Rdc_Rdc_nWoFlt'
   */
  Rte_Read_RP_SWC_Rdc_Rdc_nWoFlt(&rtb_TmpSignalConversionAtRP_SWC);

  /* RelationalOperator: '<S12>/Relational Operator1' incorporates:
   *  Constant: '<S12>/CAL_VCF_GearLvR_u8'
   */
  rtb_RP_SWC_FIM_MtrOvTempWarn__a = (0 == CAL_Vcf_GearLvR_u8);

  /* Logic: '<S12>/Logical Operator1' incorporates:
   *  Constant: '<S12>/CAL_Vcf_FwdHoldInSpdLim_f32'
   *  Constant: '<S12>/CAL_Vcf_FwdHoldOutSpdLim_f32'
   *  Logic: '<S12>/Logical Operator6'
   *  RelationalOperator: '<S12>/Relational Operator3'
   *  RelationalOperator: '<S12>/Relational Operator6'
   */
  rtb_LogicalOperator1_o = (rtb_RP_SWC_FIM_MtrOvTempWarn__a &&
    ((rtb_TmpSignalConversionAtRP_SWC >= CAL_Vcf_FwdHoldInSpdLim_f32) &&
     (rtb_TmpSignalConversionAtRP_SWC <= CAL_Vcf_FwdHoldOutSpdLim_f32)));

  /* FunctionCaller: '<S1>/RP_SWC_FIM_ReqFailrMod_GetFunctionPermission' */
  Rte_Call_RP_SWC_FIM_ReqFailrMod_GetFunctionPermission
    (&rtb_RP_SWC_FIM_MtrOvTempWarn__a);

  /* RelationalOperator: '<S12>/Relational Operator8' incorporates:
   *  Constant: '<S12>/CAL_Vcf_HoldModVcuReq_u8'
   */
  rtb_RP_SWC_FIM_IGBTOvTempWarn_p = (0.0F == CAL_Vcf_HoldModVcuReq_u8);

  /* SignalConversion generated from: '<S1>/RP_SWC_SCF_SCF_stDrvCtl_read' incorporates:
   *  Inport: '<Root>/RP_SWC_SCF_SCF_stDrvCtl'
   */
  Rte_Read_RP_SWC_SCF_SCF_stDrvCtl(&rtb_TmpSignalConversionAtRP_S_j);

  /* Logic: '<S12>/Logical Operator3' incorporates:
   *  Constant: '<S12>/CAL_VCF_GearLvD_u8'
   *  Constant: '<S12>/CAL_Vcf_BwdHoldInSpdLim_f32'
   *  Constant: '<S12>/CAL_Vcf_BwdHoldOutSpdLim_f32'
   *  Logic: '<S12>/Logical Operator'
   *  Logic: '<S12>/Logical Operator2'
   *  Logic: '<S12>/Logical Operator4'
   *  RelationalOperator: '<S12>/Relational Operator'
   *  RelationalOperator: '<S12>/Relational Operator2'
   *  RelationalOperator: '<S12>/Relational Operator5'
   *  RelationalOperator: '<S12>/Relational Operator7'
   */
  VAR_Vcf_TranstoHoldIn_b = ((((0 == CAL_Vcf_GearLvD_u8) &&
    ((rtb_TmpSignalConversionAtRP_SWC <= CAL_Vcf_BwdHoldInSpdLim_f32) &&
     (rtb_TmpSignalConversionAtRP_SWC >= CAL_Vcf_BwdHoldOutSpdLim_f32))) ||
    rtb_LogicalOperator1_o) && SWC_VCF_ConstB.RelationalOperator4 &&
    SWC_VCF_ConstB.LogicalOperator5 && rtb_RP_SWC_FIM_MtrOvTempWarn__a &&
    rtb_RP_SWC_FIM_IGBTOvTempWarn_p && (rtb_TmpSignalConversionAtRP_S_j !=
    SWC_VCF_ConstB.DataTypeConversion_h));

  /* FunctionCaller: '<S1>/RP_SWC_FIM_IGBTOvTempWarn_GetFunctionPermission' */
  Rte_Call_RP_SWC_FIM_IGBTOvTempWarn_GetFunctionPermission
    (&rtb_RP_SWC_FIM_IGBTOvTempWarn_p);

  /* FunctionCaller: '<S1>/RP_SWC_FIM_MtrOvTempWarn_GetFunctionPermission' */
  Rte_Call_RP_SWC_FIM_MtrOvTempWarn_GetFunctionPermission
    (&rtb_RP_SWC_FIM_MtrOvTempWarn__a);

  /* SignalConversion generated from: '<S1>/RP_SWC_CSPF_CSPF_RecTrqSetP_read' incorporates:
   *  Inport: '<Root>/RP_SWC_CSPF_CSPF_RecTrqSetP'
   */
  Rte_Read_RP_SWC_CSPF_CSPF_RecTrqSetP(&rtb_TmpSignalConversionAtRP_S_h);

  /* Abs: '<S13>/Abs' */
  rtb_TmpSignalConversionAtRP_S_h = fabsf(rtb_TmpSignalConversionAtRP_S_h);

  /* SignalConversion generated from: '<S1>/RP_SWC_MPC_MPC_TrqMechFlt_read' incorporates:
   *  Inport: '<Root>/RP_SWC_MPC_MPC_TrqMechFlt'
   */
  Rte_Read_RP_SWC_MPC_MPC_TrqMechFlt(&rtb_TmpSignalConversionAtRP_S_o);

  /* Switch: '<S13>/Switch' incorporates:
   *  Constant: '<S13>/CAL_Vcf_GearHoldOutSwt_b'
   *  Constant: '<S13>/CAL_Vcf_GearLvN_u8'
   *  Constant: '<S13>/Constant1'
   *  RelationalOperator: '<S13>/Relational Operator'
   *  RelationalOperator: '<S13>/Relational Operator10'
   *  Sum: '<S13>/Add'
   *  UnitDelay: '<S13>/Unit Delay'
   */
  if (CAL_Vcf_GearHoldOutSwt_b) {
    rtb_LogicalOperator1_o = ((uint8)-SWC_VCF_DW.UnitDelay_DSTATE_g != 0);
  } else {
    rtb_LogicalOperator1_o = (0 == CAL_Vcf_GearLvN_u8);
  }

  /* End of Switch: '<S13>/Switch' */

  /* Logic: '<S13>/Logical Operator2' incorporates:
   *  Abs: '<S13>/Abs1'
   *  Constant: '<S13>/CAL_VCF_GearLvD_u8'
   *  Constant: '<S13>/CAL_VCF_GearLvR_u8'
   *  Constant: '<S13>/CAL_Vcf_BwdHoldOutSpdLim_f32'
   *  Constant: '<S13>/CAL_Vcf_FwdHoldOutSpdLim_f32'
   *  Constant: '<S13>/CAL_Vcf_HoldModVcuReq_u8'
   *  Constant: '<S13>/CAL_Vcf_TrqHoldOutLim_f32'
   *  Logic: '<S13>/Logical Operator'
   *  Logic: '<S13>/Logical Operator3'
   *  Logic: '<S13>/Logical Operator4'
   *  Logic: '<S13>/Logical Operator5'
   *  Logic: '<S13>/Logical Operator6'
   *  Logic: '<S13>/Logical Operator7'
   *  RelationalOperator: '<S13>/Relational Operator1'
   *  RelationalOperator: '<S13>/Relational Operator11'
   *  RelationalOperator: '<S13>/Relational Operator2'
   *  RelationalOperator: '<S13>/Relational Operator3'
   *  RelationalOperator: '<S13>/Relational Operator4'
   *  RelationalOperator: '<S13>/Relational Operator5'
   *  RelationalOperator: '<S13>/Relational Operator7'
   */
  VAR_Vcf_TranstoHoldOut_b = (rtb_LogicalOperator1_o ||
    ((rtb_TmpSignalConversionAtRP_S_h >= fabsf(rtb_TmpSignalConversionAtRP_S_o))
     && (rtb_TmpSignalConversionAtRP_S_h >= CAL_Vcf_TrqHoldOutLim_f32)) || (0.0F
    != CAL_Vcf_HoldModVcuReq_u8) || (((0 == CAL_Vcf_GearLvD_u8) &&
    (rtb_TmpSignalConversionAtRP_SWC <= CAL_Vcf_BwdHoldOutSpdLim_f32)) || ((0 ==
    CAL_Vcf_GearLvR_u8) && (rtb_TmpSignalConversionAtRP_SWC >=
    CAL_Vcf_FwdHoldOutSpdLim_f32))) || (!rtb_RP_SWC_FIM_IGBTOvTempWarn_p) ||
    (!rtb_RP_SWC_FIM_MtrOvTempWarn__a));

  /* Chart: '<S9>/Chart' */
  if (SWC_VCF_DW.is_active_c1_SWC_VCF == 0U) {
    SWC_VCF_DW.is_active_c1_SWC_VCF = 1U;
    SWC_VCF_DW.is_c1_SWC_VCF = SWC_VCF_IN_AutoHoldOut;
    SWC_VCF_B.CSPF_flgHoldModeReq = 0U;
  } else if (SWC_VCF_DW.is_c1_SWC_VCF == SWC_VCF_IN_AutoHoldIn) {
    tmp = SWC_VCF_DW.timecnt + 1;
    if (tmp > 65535) {
      tmp = 65535;
    }

    SWC_VCF_DW.timecnt = (uint16)tmp;
    if (VAR_Vcf_TranstoHoldOut_b || (SWC_VCF_DW.timecnt >
         CAL_Vcf_HoldTimeCount_u16)) {
      SWC_VCF_DW.is_c1_SWC_VCF = SWC_VCF_IN_AutoHoldOut;
      SWC_VCF_B.CSPF_flgHoldModeReq = 0U;
    }
  } else {
    /* case IN_AutoHoldOut: */
    if (VAR_Vcf_TranstoHoldIn_b && (!VAR_Vcf_TranstoHoldOut_b)) {
      SWC_VCF_DW.is_c1_SWC_VCF = SWC_VCF_IN_AutoHoldIn;
      SWC_VCF_DW.timecnt = 0U;
      SWC_VCF_B.CSPF_flgHoldModeReq = 1U;
    }
  }

  /* End of Chart: '<S9>/Chart' */

  /* Switch: '<S9>/Switch' incorporates:
   *  Constant: '<S9>/CAL_VCF_flgOpenHoldFcn_b'
   */
  VAR_VCF_flgHoldModeReq_b = (CAL_Vcf_flgOpenHoldFcn_b &&
    (SWC_VCF_B.CSPF_flgHoldModeReq != 0));

  /* SignalConversion generated from: '<S1>/RP_SWC_CSPF_CSPF_RecNSetP_read' incorporates:
   *  Inport: '<Root>/RP_SWC_CSPF_CSPF_RecNSetP'
   */
  Rte_Read_RP_SWC_CSPF_CSPF_RecNSetP(&rtb_TmpSignalConversionAtRP_S_n);

  /* Switch: '<S8>/Switch1' incorporates:
   *  Constant: '<S8>/CAL_Vcf_HoldTrqInSwt_b'
   *  Constant: '<S8>/CAL_Vcf_HoldTrqLoadSwt_b'
   *  Switch: '<S8>/Switch2'
   */
  if (CAL_Vcf_HoldTrqLoadSwt_b) {
    /* Outport: '<Root>/PP_SWC_VCF_VCF_HoldStartTrq' incorporates:
     *  Constant: '<S8>/Constant1'
     */
    (void) Rte_Write_PP_SWC_VCF_VCF_HoldStartTrq(0.0F);
  } else {
    if (CAL_Vcf_HoldTrqInSwt_b) {
      /* Switch: '<S8>/Switch2' incorporates:
       *  Constant: '<S8>/Constant2'
       *  Constant: '<S8>/Constant3'
       *  Constant: '<S8>/Constant4'
       *  Delay: '<S8>/Delay'
       *  Delay: '<S8>/Delay1'
       *  Logic: '<S8>/Logical Operator'
       *  RelationalOperator: '<S8>/Relational Operator'
       *  RelationalOperator: '<S8>/Relational Operator1'
       *  RelationalOperator: '<S8>/Relational Operator2'
       *  Sum: '<S8>/Add1'
       *  Sum: '<S8>/Add2'
       *  Sum: '<S8>/Add3'
       *  UnitDelay: '<S8>/Unit Delay'
       */
      rtb_LogicalOperator1_o = (((uint8)(VAR_VCF_flgHoldModeReq_b -
        SWC_VCF_DW.UnitDelay_DSTATE_c) == 1) || ((uint8)
        (VAR_VCF_flgHoldModeReq_b - SWC_VCF_DW.Delay_DSTATE[0]) == 1) || ((uint8)
        (VAR_VCF_flgHoldModeReq_b - SWC_VCF_DW.Delay1_DSTATE[0]) == 1));
    } else {
      /* Switch: '<S8>/Switch2' incorporates:
       *  Delay: '<S8>/Delay2'
       *  Delay: '<S8>/Delay3'
       *  Logic: '<S8>/Logical Operator1'
       *  Logic: '<S8>/Logical Operator2'
       *  Logic: '<S8>/Logical Operator3'
       *  RelationalOperator: '<S8>/Relational Operator3'
       *  RelationalOperator: '<S8>/Relational Operator4'
       *  RelationalOperator: '<S8>/Relational Operator5'
       *  RelationalOperator: '<S8>/Relational Operator6'
       *  UnitDelay: '<S8>/Unit Delay1'
       */
      rtb_LogicalOperator1_o = (VAR_VCF_flgHoldModeReq_b &&
        ((rtb_TmpSignalConversionAtRP_S_j == SWC_VCF_ConstB.DataTypeConversion_e)
         && ((SWC_VCF_DW.UnitDelay1_DSTATE_m ==
              SWC_VCF_ConstB.DataTypeConversion1_f) ||
             (SWC_VCF_DW.Delay2_DSTATE[0] ==
              SWC_VCF_ConstB.DataTypeConversion2_c) ||
             (SWC_VCF_DW.Delay3_DSTATE[0] == SWC_VCF_ConstB.DataTypeConversion3))));
    }

    /* Switch: '<S8>/Switch' */
    if (rtb_LogicalOperator1_o) {
      /* Product: '<S8>/Product' incorporates:
       *  Constant: '<S8>/CAL_Vcf_CofHoldTrq_f32'
       *  Sum: '<S8>/Add'
       */
      rtb_TmpSignalConversionAtRP_SWC = (rtb_TmpSignalConversionAtRP_SWC -
        rtb_TmpSignalConversionAtRP_S_n) * CAL_Vcf_CofHoldTrq_f32;

      /* Switch: '<S27>/Switch2' incorporates:
       *  Constant: '<S8>/CAL_Vcf_trqHoldMax_f32'
       *  Constant: '<S8>/CAL_Vcf_trqHoldMin_f32'
       *  RelationalOperator: '<S27>/LowerRelop1'
       *  RelationalOperator: '<S27>/UpperRelop'
       *  Switch: '<S27>/Switch'
       */
      if (rtb_TmpSignalConversionAtRP_SWC > CAL_Vcf_trqHoldMax_f32) {
        /* Outport: '<Root>/PP_SWC_VCF_VCF_HoldStartTrq' */
        (void) Rte_Write_PP_SWC_VCF_VCF_HoldStartTrq(CAL_Vcf_trqHoldMax_f32);
      } else if (rtb_TmpSignalConversionAtRP_SWC < CAL_Vcf_trqHoldMin_f32) {
        /* Outport: '<Root>/PP_SWC_VCF_VCF_HoldStartTrq' incorporates:
         *  Constant: '<S8>/CAL_Vcf_trqHoldMin_f32'
         *  Switch: '<S27>/Switch'
         */
        (void) Rte_Write_PP_SWC_VCF_VCF_HoldStartTrq(CAL_Vcf_trqHoldMin_f32);
      } else {
        /* Outport: '<Root>/PP_SWC_VCF_VCF_HoldStartTrq' incorporates:
         *  Switch: '<S27>/Switch'
         */
        (void) Rte_Write_PP_SWC_VCF_VCF_HoldStartTrq
          (rtb_TmpSignalConversionAtRP_SWC);
      }

      /* End of Switch: '<S27>/Switch2' */
    } else {
      /* Outport: '<Root>/PP_SWC_VCF_VCF_HoldStartTrq' incorporates:
       *  Constant: '<S8>/Constant'
       */
      (void) Rte_Write_PP_SWC_VCF_VCF_HoldStartTrq(0.0F);
    }

    /* End of Switch: '<S8>/Switch' */
  }

  /* End of Switch: '<S8>/Switch1' */

  /* SignalConversion generated from: '<S1>/IVDP_VCF_flgHoldModeReq_write' */
  Rte_IrvIWrite_RE_SWC_VCF_10ms_IVDP_VCF_flgHoldModeReq(VAR_VCF_flgHoldModeReq_b);

  /* SignalConversion generated from: '<S1>/RP_SWC_HSPF_HSPF_nSlowFlt_read' incorporates:
   *  Inport: '<Root>/RP_SWC_HSPF_HSPF_nSlowFlt'
   */
  Rte_Read_RP_SWC_HSPF_HSPF_nSlowFlt(&rtb_TmpSignalConversionAtRP_S_a);

  /* Logic: '<S14>/Logical Operator5' incorporates:
   *  Abs: '<S14>/Abs'
   *  Constant: '<S17>/Constant'
   *  Constant: '<S18>/Constant'
   *  Constant: '<S19>/Constant'
   *  Constant: '<S20>/Constant'
   *  Constant: '<S21>/Constant'
   *  Constant: '<S22>/Constant'
   *  Logic: '<S14>/Logical Operator2'
   *  Logic: '<S14>/Logical Operator3'
   *  Logic: '<S14>/Logical Operator4'
   *  RelationalOperator: '<S17>/Compare'
   *  RelationalOperator: '<S18>/Compare'
   *  RelationalOperator: '<S19>/Compare'
   *  RelationalOperator: '<S20>/Compare'
   *  RelationalOperator: '<S21>/Compare'
   *  RelationalOperator: '<S22>/Compare'
   */
  VAR_Vcf_CrawlFlg_b = ((!CAL_Vcf_BrkLgt_b) &&
                        (SWC_VCF_ConstB.DataTypeConversion <=
    CAL_Vcf_AccPedSet_f32) && (((rtb_TmpSignalConversionAtRP_S_a <=
    CAL_Vcf_OvCrawlDspd_f32) && (0 == CAL_Vcf_GearD_u8)) || ((0 ==
    CAL_Vcf_GearR_u8) && (fabsf(rtb_TmpSignalConversionAtRP_S_a) <=
    CAL_Vcf_OvCrawlRspd_f32))));

  /* Switch: '<S14>/Switch' incorporates:
   *  Constant: '<S14>/CAL_VCF_flgOpenCrawlFcn_b'
   */
  rtb_LogicalOperator1_o = (CAL_Vcf_flgOpenCrawlFcn_b && VAR_Vcf_CrawlFlg_b);

  /* Chart: '<S16>/Chart' incorporates:
   *  UnitDelay: '<S16>/Unit Delay'
   */
  if (rtb_LogicalOperator1_o) {
    if (0 == CAL_Vcf_GearD_u8) {
      if (rtb_TmpSignalConversionAtRP_S_a < CAL_Vcf_CrawlNsetD_f32) {
        if (rtb_TmpSignalConversionAtRP_S_a < CAL_Vcf_CrawlDspd_f32) {
          SWC_VCF_DW.UnitDelay_DSTATE_n += CAL_Vcf_Crawltrqadd1_f32;
        } else {
          SWC_VCF_DW.UnitDelay_DSTATE_n += CAL_Vcf_Crawltrqadd2_f32;
        }
      } else {
        SWC_VCF_DW.UnitDelay_DSTATE_n -= CAL_Vcf_Crawltrqsub_f32;
      }
    } else if (0 == CAL_Vcf_GearR_u8) {
      if (rtb_TmpSignalConversionAtRP_S_a > CAL_Vcf_CrawlNsetR_f32) {
        if (rtb_TmpSignalConversionAtRP_S_a > CAL_Vcf_CrawlRspd_f32) {
          SWC_VCF_DW.UnitDelay_DSTATE_n -= CAL_Vcf_Crawltrqadd1_f32;
        } else {
          SWC_VCF_DW.UnitDelay_DSTATE_n -= CAL_Vcf_Crawltrqadd2_f32;
        }
      } else {
        SWC_VCF_DW.UnitDelay_DSTATE_n += CAL_Vcf_Crawltrqsub_f32;
      }
    } else {
      SWC_VCF_DW.UnitDelay_DSTATE_n = 0.0F;
    }
  } else {
    SWC_VCF_DW.UnitDelay_DSTATE_n = 0.0F;
  }

  /* End of Chart: '<S16>/Chart' */

  /* Switch: '<S26>/Switch2' incorporates:
   *  Constant: '<S16>/Constant10'
   *  Constant: '<S16>/Constant9'
   *  RelationalOperator: '<S26>/LowerRelop1'
   *  RelationalOperator: '<S26>/UpperRelop'
   *  Switch: '<S26>/Switch'
   */
  if (SWC_VCF_DW.UnitDelay_DSTATE_n > CAL_Vcf_CrawltrqUp_f32) {
    /* SignalConversion generated from: '<S1>/IVDP_VCF_RecCrawlTrqSetP_write' */
    Rte_IrvIWrite_RE_SWC_VCF_10ms_IVDP_VCF_RecCrawlTrqSetP
      (CAL_Vcf_CrawltrqUp_f32);
  } else if (SWC_VCF_DW.UnitDelay_DSTATE_n < CAL_Vcf_CrawltrqLo_f32) {
    /* SignalConversion generated from: '<S1>/IVDP_VCF_RecCrawlTrqSetP_write' incorporates:
     *  Constant: '<S16>/Constant10'
     *  Switch: '<S26>/Switch'
     */
    Rte_IrvIWrite_RE_SWC_VCF_10ms_IVDP_VCF_RecCrawlTrqSetP
      (CAL_Vcf_CrawltrqLo_f32);
  } else {
    /* SignalConversion generated from: '<S1>/IVDP_VCF_RecCrawlTrqSetP_write' incorporates:
     *  Switch: '<S26>/Switch'
     */
    Rte_IrvIWrite_RE_SWC_VCF_10ms_IVDP_VCF_RecCrawlTrqSetP
      (SWC_VCF_DW.UnitDelay_DSTATE_n);
  }

  /* End of Switch: '<S26>/Switch2' */

  /* Switch: '<S15>/Switch2' incorporates:
   *  Constant: '<S15>/Constant1'
   */
  if (rtb_LogicalOperator1_o) {
    /* Switch: '<S15>/Switch' incorporates:
     *  Constant: '<S15>/CAL_VCF_CrawlNsetD_f32'
     *  Constant: '<S15>/Constant'
     *  Constant: '<S23>/Constant'
     *  Constant: '<S24>/Constant'
     *  RelationalOperator: '<S23>/Compare'
     *  RelationalOperator: '<S24>/Compare'
     *  Switch: '<S15>/Switch1'
     */
    if (0 == CAL_Vcf_GearD_u8) {
      rtb_Switch2_m = CAL_Vcf_CrawlNsetD_f32;
    } else if (0 == CAL_Vcf_GearR_u8) {
      /* Switch: '<S15>/Switch1' incorporates:
       *  Constant: '<S15>/CAL_VCF_CrawlNsetR_f32'
       */
      rtb_Switch2_m = CAL_Vcf_CrawlNsetR_f32;
    } else {
      rtb_Switch2_m = 0.0;
    }

    /* End of Switch: '<S15>/Switch' */
  } else {
    rtb_Switch2_m = 0.0;
  }

  /* End of Switch: '<S15>/Switch2' */

  /* Sum: '<S15>/Add' incorporates:
   *  UnitDelay: '<S15>/Unit Delay'
   */
  rtb_Add = rtb_Switch2_m - SWC_VCF_DW.UnitDelay_DSTATE_d;

  /* Switch: '<S15>/Switch3' incorporates:
   *  Constant: '<S15>/Constant2'
   *  RelationalOperator: '<S15>/Relational Operator1'
   *  Sum: '<S15>/Add1'
   *  UnitDelay: '<S15>/Unit Delay'
   */
  if (rtb_Add <= CAL_Vcf_nSetRamp_f32) {
    /* Switch: '<S15>/Switch4' incorporates:
     *  Product: '<S15>/Product'
     *  RelationalOperator: '<S15>/Relational Operator2'
     *  Sum: '<S15>/Add2'
     *  UnitDelay: '<S15>/Unit Delay'
     */
    if (-rtb_Add <= CAL_Vcf_nSetRamp_f32) {
      SWC_VCF_DW.UnitDelay_DSTATE_d = (float32)rtb_Switch2_m;
    } else {
      SWC_VCF_DW.UnitDelay_DSTATE_d = CAL_Vcf_nSetRamp_f32 -
        SWC_VCF_DW.UnitDelay_DSTATE_d;
    }

    /* End of Switch: '<S15>/Switch4' */
  } else {
    SWC_VCF_DW.UnitDelay_DSTATE_d += CAL_Vcf_nSetRamp_f32;
  }

  /* End of Switch: '<S15>/Switch3' */

  /* SignalConversion generated from: '<S1>/IVDP_VCF_RecCrawlNSetP_write' incorporates:
   *  UnitDelay: '<S15>/Unit Delay'
   */
  Rte_IrvIWrite_RE_SWC_VCF_10ms_IVDP_VCF_RecCrawlNSetP
    (SWC_VCF_DW.UnitDelay_DSTATE_d);

  /* SignalConversion generated from: '<S1>/IVDP_VCF_CrawlFlg_write' */
  Rte_IrvIWrite_RE_SWC_VCF_10ms_IVDP_VCF_CrawlFlg(rtb_LogicalOperator1_o);

  /* Switch: '<S14>/Switch5' */
  if (VAR_Vcf_CrawlFlg_b) {
    /* Switch: '<S14>/Switch6' incorporates:
     *  Constant: '<S14>/Constant6'
     */
    if (CAL_Vcf_CrawlSwt_b) {
      /* SignalConversion generated from: '<S1>/IVDP_VCF_CrawlModeReq_write' incorporates:
       *  Constant: '<S14>/CAL_VCF_SpdCtlReq_u8'
       */
      Rte_IrvIWrite_RE_SWC_VCF_10ms_IVDP_VCF_CrawlModeReq(CAL_Vcf_SpdCtlReq_u8);
    } else {
      /* SignalConversion generated from: '<S1>/IVDP_VCF_CrawlModeReq_write' incorporates:
       *  Constant: '<S14>/CAL_Csd_TrqCtlReq_u8'
       */
      Rte_IrvIWrite_RE_SWC_VCF_10ms_IVDP_VCF_CrawlModeReq(CAL_Vcf_TrqCtlReq_u8);
    }

    /* End of Switch: '<S14>/Switch6' */
  } else {
    /* SignalConversion generated from: '<S1>/IVDP_VCF_CrawlModeReq_write' incorporates:
     *  Constant: '<S14>/Constant7'
     */
    Rte_IrvIWrite_RE_SWC_VCF_10ms_IVDP_VCF_CrawlModeReq(CAL_Vcf_StandByReq_u8);
  }

  /* End of Switch: '<S14>/Switch5' */

  /* Update for UnitDelay: '<S13>/Unit Delay' */
  SWC_VCF_DW.UnitDelay_DSTATE_g = 0U;

  /* Update for UnitDelay: '<S8>/Unit Delay' */
  SWC_VCF_DW.UnitDelay_DSTATE_c = VAR_VCF_flgHoldModeReq_b;

  /* Update for Delay: '<S8>/Delay' */
  SWC_VCF_DW.Delay_DSTATE[0] = SWC_VCF_DW.Delay_DSTATE[1];
  SWC_VCF_DW.Delay_DSTATE[1] = VAR_VCF_flgHoldModeReq_b;

  /* Update for UnitDelay: '<S8>/Unit Delay1' */
  SWC_VCF_DW.UnitDelay1_DSTATE_m = rtb_TmpSignalConversionAtRP_S_j;

  /* Update for Delay: '<S8>/Delay2' */
  SWC_VCF_DW.Delay2_DSTATE[0] = SWC_VCF_DW.Delay2_DSTATE[1];
  SWC_VCF_DW.Delay2_DSTATE[1] = rtb_TmpSignalConversionAtRP_S_j;

  /* Update for Delay: '<S8>/Delay1' */
  SWC_VCF_DW.Delay1_DSTATE[0] = SWC_VCF_DW.Delay1_DSTATE[1];

  /* Update for Delay: '<S8>/Delay3' */
  SWC_VCF_DW.Delay3_DSTATE[0] = SWC_VCF_DW.Delay3_DSTATE[1];

  /* Update for Delay: '<S8>/Delay1' */
  SWC_VCF_DW.Delay1_DSTATE[1] = SWC_VCF_DW.Delay1_DSTATE[2];

  /* Update for Delay: '<S8>/Delay3' */
  SWC_VCF_DW.Delay3_DSTATE[1] = SWC_VCF_DW.Delay3_DSTATE[2];

  /* Update for Delay: '<S8>/Delay1' */
  SWC_VCF_DW.Delay1_DSTATE[2] = VAR_VCF_flgHoldModeReq_b;

  /* Update for Delay: '<S8>/Delay3' */
  SWC_VCF_DW.Delay3_DSTATE[2] = rtb_TmpSignalConversionAtRP_S_j;

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_VCF_10ms' */
}

/* Model initialize function */
void SWC_VCF_Init(void)
{
  /* Registration code */

  /* block I/O */

  /* exported global signals */
  VAR_Vcf_trqDesUnProc_f32 = 1.0F;
  VAR_Vcf_trqRmp_f32 = 1.0F;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
