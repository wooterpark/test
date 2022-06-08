/*
 * File: SWC_ADM.c
 *
 * Code generated for Simulink model 'SWC_ADM'.
 *
 * Model version                  : 1.269
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Tue Sep  7 10:10:19 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SWC_ADM.h"
#include "SWC_ADM_private.h"
#include "set_get_data.h"

/* Exported block signals */
float32 VAR_ADM_HiPrecVolt_f32;        /* '<S18>/Signal Conversion' */
float32 VAR_ADM_BMSVolt_f32;           /* '<S13>/Signal Conversion' */
float32 VAR_ADM_L2Com_HiPrecVolt_IN;   /* '<S8>/Switch' */
float32 VAR_ADM_L2Com_BMSVolt_IN;      /* '<S10>/Switch' */
uint8 VAR_ADM_stModeReq_u8;            /* '<S7>/Switch' */
boolean VAR_ADM_VoltCmpChkErr_b;       /* '<S12>/Debounce' */
boolean VAR_ADM_BMSVoltRngErr_b;       /* '<S11>/Debounce' */
boolean VAR_ADM_flgDchgReq_b;          /* '<S9>/Switch' */
boolean VAR_ADM_flgCrash_b;            /* '<S6>/Switch' */
boolean VAR_ADM_GlbDchgErr_b;          /* '<S3>/Logical Operator2' */

/* Exported data definition */
#pragma section ".rodata.CPU1_Calib_32"

/* Definition for custom storage class: iEDS_Parameter */
const volatile float32 CAL_ADM_BMSLowerThr_f32 = 0.0F;
                            /* Referenced by: '<S13>/CAL_ADM_BMSLowerThr_f32' */
const volatile float32 CAL_ADM_BMSUpperThr_f32 = 600.0F;
                            /* Referenced by: '<S13>/CAL_ADM_BMSUpperThr_f32' */
const volatile sint16 CAL_ADM_BMSVoltRngErrCntThr_s16 = 150;
                    /* Referenced by: '<S11>/CAL_ADM_BMSVoltRngErrCntThr_s16' */
const volatile sint16 CAL_ADM_BMSVoltRngErrDebThr_s16 = 100;
                    /* Referenced by: '<S11>/CAL_ADM_BMSVoltRngErrDebThr_s16' */
const volatile boolean CAL_ADM_BMSVoltRngErrRst_b = 0;
                         /* Referenced by: '<S11>/CAL_ADM_BMSVoltRngErrRst_b' */
const volatile uint8 CAL_ADM_DchgMode_u8 = 1U;
                                 /* Referenced by: '<S3>/CAL_ADM_DchgMode_u8' */
const volatile boolean CAL_ADM_GlbDchgErrRst_b = 0;
                             /* Referenced by: '<S3>/CAL_ADM_GlbDchgErrRst_b' */
const volatile float32 CAL_ADM_GlbDchgThrshTime_f32 = 2.8F;
                        /* Referenced by: '<S3>/CAL_ADM_GlbDchgThrshTime_f32' */
const volatile float32 CAL_ADM_GlbDchgThrshVolt_f32 = 60.0F;
                        /* Referenced by: '<S3>/CAL_ADM_GlbDchgThrshVolt_f32' */
const volatile float32 CAL_ADM_L2Com_BMSVolt = 0.0F;/* Referenced by: '<S10>/Constant3' */
const volatile boolean CAL_ADM_L2Com_BMSVolt_b = 0;/* Referenced by: '<S10>/Constant2' */
const volatile float32 CAL_ADM_L2Com_HiPrecVolt = 0.0F;/* Referenced by: '<S8>/Constant3' */
const volatile boolean CAL_ADM_L2Com_HiPrecVolt_b = 0;/* Referenced by: '<S8>/Constant2' */
const volatile float32 CAL_ADM_VoltAbsDiffThrPerc_f32 = 0.1F;
                     /* Referenced by: '<S18>/CAL_ADM_VoltAbsDiffThrPerc_f32' */
const volatile float32 CAL_ADM_VoltAbsDiffThr_f32 = 10.0F;
                         /* Referenced by: '<S18>/CAL_ADM_VoltAbsDiffThr_f32' */
const volatile float32 CAL_ADM_VoltChgThr_f32 = 100.0F;
                             /* Referenced by: '<S18>/CAL_ADM_VoltChgThr_f32' */
const volatile sint16 CAL_ADM_VoltCmpChkErrCntThr_s16 = 150;
                    /* Referenced by: '<S12>/CAL_ADM_VoltCmpChkErrCntThr_s16' */
const volatile sint16 CAL_ADM_VoltCmpChkErrDebThr_s16 = 100;
                    /* Referenced by: '<S12>/CAL_ADM_VoltCmpChkErrDebThr_s16' */
const volatile boolean CAL_ADM_VoltCmpChkErrRst_b = 0;
                         /* Referenced by: '<S12>/CAL_ADM_VoltCmpChkErrRst_b' */
const volatile boolean CAL_ADM_flgCrashSwt_b = 0;/* Referenced by: '<S6>/Constant2' */
const volatile boolean CAL_ADM_flgCrash_b = 0;/* Referenced by: '<S6>/Constant3' */
const volatile boolean CAL_ADM_flgDchgReqSwt_b = 0;/* Referenced by: '<S9>/Constant2' */
const volatile boolean CAL_ADM_flgDchgReq_b = 0;/* Referenced by: '<S9>/Constant3' */
const volatile boolean CAL_ADM_flgstModeReqSwt_b = 0;/* Referenced by: '<S7>/Constant2' */
const volatile uint8 CAL_ADM_stModeReq_u8 = 0U;/* Referenced by: '<S7>/Constant3' */

#pragma section

/* Block signals (default storage) */
B_SWC_ADM_T SWC_ADM_B;

/* Block states (default storage) */
DW_SWC_ADM_T SWC_ADM_DW;

/* Real-time model */
RT_MODEL_SWC_ADM_T SWC_ADM_M_;
RT_MODEL_SWC_ADM_T *const SWC_ADM_M = &SWC_ADM_M_;

/* Output and update for atomic system: '<S1>/GlbDchgMon' */
void SWC_ADM_GlbDchgMon(void)
{
  boolean rtb_LogicalOperator;
  float32 rtb_Add3;

  /* Logic: '<S3>/Logical Operator' incorporates:
   *  Constant: '<S3>/CAL_ADM_DchgMode_u8'
   *  RelationalOperator: '<S3>/Relational Operator'
   */
  rtb_LogicalOperator = (SWC_ADM_B.LogicalOperator || (SWC_ADM_B.Add3 ==
    CAL_ADM_DchgMode_u8) || SWC_ADM_B.LogicalOperator1);

  /* Switch: '<S3>/Switch15' incorporates:
   *  Constant: '<S3>/Constant28'
   *  UnitDelay: '<S3>/Unit Delay4'
   */
  if (!rtb_LogicalOperator) {
    SWC_ADM_DW.UnitDelay4_DSTATE = 0.0F;
  }

  /* End of Switch: '<S3>/Switch15' */

  /* Sum: '<S3>/Add3' incorporates:
   *  UnitDelay: '<S3>/Unit Delay4'
   *  UnitDelay: '<S3>/Unit Delay8'
   */
  rtb_Add3 = SWC_ADM_DW.UnitDelay8_DSTATE + SWC_ADM_DW.UnitDelay4_DSTATE;

  /* Saturate: '<S3>/Saturation' */
  if (rtb_Add3 > 3.0F) {
    SWC_ADM_DW.UnitDelay4_DSTATE = 3.0F;
  } else if (rtb_Add3 < 0.0F) {
    SWC_ADM_DW.UnitDelay4_DSTATE = 0.0F;
  } else {
    SWC_ADM_DW.UnitDelay4_DSTATE = rtb_Add3;
  }

  /* End of Saturate: '<S3>/Saturation' */

  /* Switch: '<S3>/Switch26' incorporates:
   *  Constant: '<S3>/CAL_ADM_GlbDchgThrshTime_f32'
   *  Constant: '<S3>/Constant18'
   *  RelationalOperator: '<S3>/Relational Operator9'
   *  UnitDelay: '<S3>/Unit Delay4'
   */
  if (SWC_ADM_DW.UnitDelay4_DSTATE >= CAL_ADM_GlbDchgThrshTime_f32) {
    SWC_ADM_DW.UnitDelay4_DSTATE = VAR_ADM_L2Com_HiPrecVolt_IN;
  } else {
    SWC_ADM_DW.UnitDelay4_DSTATE = 0.0F;
  }

  /* End of Switch: '<S3>/Switch26' */

  /* Switch: '<S3>/Switch1' incorporates:
   *  Constant: '<S3>/CAL_ADM_GlbDchgErrRst_b'
   *  Constant: '<S3>/CAL_ADM_GlbDchgThrshVolt_f32'
   *  Constant: '<S3>/Constant1'
   *  RelationalOperator: '<S3>/Relational Operator10'
   *  Switch: '<S3>/Switch2'
   *  UnitDelay: '<S3>/Unit Delay1'
   *  UnitDelay: '<S3>/Unit Delay4'
   */
  if (SWC_ADM_DW.UnitDelay4_DSTATE > CAL_ADM_GlbDchgThrshVolt_f32) {
    SWC_ADM_DW.UnitDelay1_DSTATE = true;
  } else {
    SWC_ADM_DW.UnitDelay1_DSTATE = ((!CAL_ADM_GlbDchgErrRst_b) &&
      SWC_ADM_DW.UnitDelay1_DSTATE);
  }

  /* End of Switch: '<S3>/Switch1' */

  /* Logic: '<S3>/Logical Operator2' incorporates:
   *  Logic: '<S3>/Logical Operator1'
   *  UnitDelay: '<S3>/Unit Delay1'
   */
  VAR_ADM_GlbDchgErr_b = (SWC_ADM_DW.UnitDelay1_DSTATE || (rtb_LogicalOperator &&
    get_ADM_VoltCmpChkErr()));

  /* SignalConversion: '<S3>/Signal Conversion1' */
  set_ADM_GlbDchgErr(VAR_ADM_GlbDchgErr_b);

  /* Switch: '<S3>/Switch23' incorporates:
   *  Constant: '<S3>/Normal'
   *  Constant: '<S3>/Ts'
   *  UnitDelay: '<S3>/Unit Delay8'
   */
  if (rtb_LogicalOperator) {
    SWC_ADM_DW.UnitDelay8_DSTATE = 0.001F;
  } else {
    SWC_ADM_DW.UnitDelay8_DSTATE = 0.0F;
  }

  /* End of Switch: '<S3>/Switch23' */

  /* Update for UnitDelay: '<S3>/Unit Delay4' */
  SWC_ADM_DW.UnitDelay4_DSTATE = rtb_Add3;
}

/* Output and update for atomic system: '<S11>/BMSVoltRngChk' */
void SWC_ADM_BMSVoltRngChk(void)
{
  /* SignalConversion: '<S13>/Signal Conversion' */
  VAR_ADM_BMSVolt_f32 = VAR_ADM_L2Com_BMSVolt_IN;

  /* Logic: '<S13>/Logical Operator' incorporates:
   *  Constant: '<S13>/CAL_ADM_BMSLowerThr_f32'
   *  Constant: '<S13>/CAL_ADM_BMSUpperThr_f32'
   *  RelationalOperator: '<S13>/Relational Operator1'
   *  RelationalOperator: '<S13>/Relational Operator2'
   */
  SWC_ADM_B.LogicalOperator_a = ((VAR_ADM_BMSVolt_f32 < CAL_ADM_BMSLowerThr_f32)
    || (VAR_ADM_BMSVolt_f32 > CAL_ADM_BMSUpperThr_f32));
}

/*
 * Output and update for atomic system:
 *    '<S11>/Debounce'
 *    '<S12>/Debounce'
 */
boolean SWC_ADM_Debounce(boolean rtu_BooleanIN, boolean rtu_Rst, sint16
  rtu_CountTrh, sint16 rtu_DebTrh, DW_Debounce_SWC_ADM_T *localDW)
{
  boolean rty_OutLock_0;
  boolean rtb_RelationalOperator_j;

  /* Outputs for Enabled SubSystem: '<S14>/Subsystem' incorporates:
   *  EnablePort: '<S16>/Enable'
   */
  /* UnitDelay: '<S14>/Unit Delay3' */
  if (localDW->UnitDelay3_DSTATE) {
    /* Sum: '<S16>/Add' incorporates:
     *  Constant: '<S16>/Constant'
     *  Delay: '<S16>/Delay'
     */
    localDW->Delay_DSTATE++;

    /* Switch: '<S16>/Switch' incorporates:
     *  Constant: '<S16>/Constant1'
     *  Delay: '<S16>/Delay'
     *  RelationalOperator: '<S16>/Relational Operator'
     */
    if (localDW->Delay_DSTATE >= rtu_CountTrh) {
      localDW->Delay_DSTATE = 0;
    }

    /* End of Switch: '<S16>/Switch' */
  }

  /* End of Outputs for SubSystem: '<S14>/Subsystem' */

  /* Switch: '<S14>/Switch2' incorporates:
   *  Constant: '<S14>/Constant'
   *  Constant: '<S15>/Constant'
   *  Delay: '<S16>/Delay'
   *  RelationalOperator: '<S15>/Compare'
   *  UnitDelay: '<S14>/Unit Delay2'
   */
  if (localDW->Delay_DSTATE == 0) {
    localDW->UnitDelay2_DSTATE = 0;
  }

  /* End of Switch: '<S14>/Switch2' */

  /* Sum: '<S14>/Add' incorporates:
   *  UnitDelay: '<S14>/Unit Delay2'
   */
  localDW->UnitDelay2_DSTATE += rtu_BooleanIN;

  /* RelationalOperator: '<S14>/Relational Operator' */
  rtb_RelationalOperator_j = (localDW->UnitDelay2_DSTATE >= rtu_DebTrh);

  /* Switch: '<S14>/Switch' incorporates:
   *  Constant: '<S14>/Constant1'
   *  UnitDelay: '<S14>/Unit Delay2'
   */
  if (rtb_RelationalOperator_j) {
    localDW->UnitDelay2_DSTATE = 0;
  }

  /* End of Switch: '<S14>/Switch' */

  /* Switch: '<S14>/Switch1' incorporates:
   *  UnitDelay: '<S14>/Unit Delay1'
   */
  localDW->UnitDelay1_DSTATE = ((!rtu_Rst) && localDW->UnitDelay1_DSTATE);

  /* Logic: '<S14>/Logical Operator' incorporates:
   *  UnitDelay: '<S14>/Unit Delay1'
   */
  rty_OutLock_0 = (rtb_RelationalOperator_j || localDW->UnitDelay1_DSTATE);

  /* Logic: '<S14>/Logical Operator1' incorporates:
   *  UnitDelay: '<S14>/Unit Delay3'
   */
  localDW->UnitDelay3_DSTATE = (localDW->UnitDelay3_DSTATE || rtu_BooleanIN);

  /* Update for UnitDelay: '<S14>/Unit Delay1' */
  localDW->UnitDelay1_DSTATE = rty_OutLock_0;
  return rty_OutLock_0;
}

/* Output and update for atomic system: '<S12>/VoltCmpChk' */
void SWC_ADM_VoltCmpChk(void)
{
  /* SignalConversion: '<S18>/Signal Conversion' */
  VAR_ADM_HiPrecVolt_f32 = VAR_ADM_L2Com_HiPrecVolt_IN;

  /* Switch: '<S18>/Switch4' incorporates:
   *  Abs: '<S18>/Abs'
   *  Constant: '<S18>/CAL_ADM_VoltAbsDiffThrPerc_f32'
   *  Constant: '<S18>/CAL_ADM_VoltAbsDiffThr_f32'
   *  Constant: '<S18>/CAL_ADM_VoltChgThr_f32'
   *  Product: '<S18>/Product'
   *  RelationalOperator: '<S18>/Relational Operator1'
   *  RelationalOperator: '<S18>/Relational Operator6'
   *  RelationalOperator: '<S18>/Relational Operator9'
   *  Sum: '<S18>/Add'
   */
  if (VAR_ADM_HiPrecVolt_f32 <= CAL_ADM_VoltChgThr_f32) {
    SWC_ADM_B.LogicalOperator_a = (fabsf(VAR_ADM_HiPrecVolt_f32 -
      VAR_ADM_L2Com_BMSVolt_IN) > CAL_ADM_VoltAbsDiffThr_f32);
  } else {
    SWC_ADM_B.LogicalOperator_a = (fabsf(VAR_ADM_HiPrecVolt_f32 -
      VAR_ADM_L2Com_BMSVolt_IN) > CAL_ADM_VoltAbsDiffThrPerc_f32 *
      VAR_ADM_HiPrecVolt_f32);
  }

  /* End of Switch: '<S18>/Switch4' */
}

/* Model step function for TID1 */
void SWC_ADM_1ms(void)                 /* Explicit Task: SWC_ADM_1ms */
{
  /* RootInportFunctionCallGenerator generated from: '<Root>/SWC_ADM_1ms' incorporates:
   *  SubSystem: '<Root>/SWC_ADM_1ms_sys'
   */
  /* Outputs for Atomic SubSystem: '<S1>/SigMng' */
  /* Switch: '<S9>/Switch' incorporates:
   *  Constant: '<S9>/Constant2'
   *  Constant: '<S9>/Constant3'
   *  DataTypeConversion: '<S9>/Data Type Conversion'
   *  Inport: '<Root>/L2Com_ModeReq'
   */
  if (CAL_ADM_flgDchgReqSwt_b) {
    VAR_ADM_flgDchgReq_b = CAL_ADM_flgDchgReq_b;
  } else {
    VAR_ADM_flgDchgReq_b = (get_L2Com_ModeReq() != 0);
  }

  /* End of Switch: '<S9>/Switch' */

  /* Logic: '<S4>/Logical Operator' */
  SWC_ADM_B.LogicalOperator = VAR_ADM_flgDchgReq_b;

  /* Switch: '<S7>/Switch' incorporates:
   *  Constant: '<S7>/Constant2'
   *  Constant: '<S7>/Constant3'
   *  DataTypeConversion: '<S7>/Data Type Conversion'
   *  Inport: '<Root>/L2Com_DchgReq'
   */
  if (CAL_ADM_flgstModeReqSwt_b) {
    VAR_ADM_stModeReq_u8 = CAL_ADM_stModeReq_u8;
  } else {
    VAR_ADM_stModeReq_u8 = get_L2Com_DchgReq();
  }

  /* End of Switch: '<S7>/Switch' */

  /* Sum: '<S4>/Add3' */
  SWC_ADM_B.Add3 = VAR_ADM_stModeReq_u8;

  /* Switch: '<S6>/Switch' incorporates:
   *  Constant: '<S6>/Constant2'
   *  Constant: '<S6>/Constant3'
   *  Inport: '<Root>/L2Com_Crash'
   */
  if (CAL_ADM_flgCrashSwt_b) {
    VAR_ADM_flgCrash_b = CAL_ADM_flgCrash_b;
  } else {
    VAR_ADM_flgCrash_b = get_L2Com_Crash();
  }

  /* End of Switch: '<S6>/Switch' */

  /* Logic: '<S4>/Logical Operator1' */
  SWC_ADM_B.LogicalOperator1 = VAR_ADM_flgCrash_b;

  /* Switch: '<S8>/Switch' incorporates:
   *  Constant: '<S8>/Constant2'
   *  Constant: '<S8>/Constant3'
   *  Inport: '<Root>/L2Com_HiPrecVolt'
   */
  if (CAL_ADM_L2Com_HiPrecVolt_b) {
    VAR_ADM_L2Com_HiPrecVolt_IN = CAL_ADM_L2Com_HiPrecVolt;
  } else {
    VAR_ADM_L2Com_HiPrecVolt_IN = get_L2Com_HiPrecVolt();
  }

  /* End of Switch: '<S8>/Switch' */

  /* Switch: '<S10>/Switch' incorporates:
   *  Constant: '<S10>/Constant2'
   *  Constant: '<S10>/Constant3'
   *  Inport: '<Root>/L2Com_BMSVolt'
   */
  if (CAL_ADM_L2Com_BMSVolt_b) {
    VAR_ADM_L2Com_BMSVolt_IN = CAL_ADM_L2Com_BMSVolt;
  } else {
    VAR_ADM_L2Com_BMSVolt_IN = get_L2Com_BMSVolt();
  }

  /* End of Switch: '<S10>/Switch' */
  /* End of Outputs for SubSystem: '<S1>/SigMng' */

  /* Outputs for Atomic SubSystem: '<S12>/VoltCmpChk' */
  SWC_ADM_VoltCmpChk();

  /* End of Outputs for SubSystem: '<S12>/VoltCmpChk' */

  /* Outputs for Atomic SubSystem: '<S12>/Debounce' */
  /* SignalConversion generated from: '<S12>/Debounce' incorporates:
   *  Constant: '<S12>/CAL_ADM_VoltCmpChkErrCntThr_s16'
   *  Constant: '<S12>/CAL_ADM_VoltCmpChkErrDebThr_s16'
   *  Constant: '<S12>/CAL_ADM_VoltCmpChkErrRst_b'
   */
  VAR_ADM_VoltCmpChkErr_b = SWC_ADM_Debounce(SWC_ADM_B.LogicalOperator_a,
    CAL_ADM_VoltCmpChkErrRst_b, CAL_ADM_VoltCmpChkErrCntThr_s16,
    CAL_ADM_VoltCmpChkErrDebThr_s16, &SWC_ADM_DW.Debounce_n);

  /* End of Outputs for SubSystem: '<S12>/Debounce' */

  /* SignalConversion: '<S12>/Signal Conversion2' */
  set_ADM_VoltCmpChkErr(VAR_ADM_VoltCmpChkErr_b);

  /* Outputs for Atomic SubSystem: '<S1>/GlbDchgMon' */
  SWC_ADM_GlbDchgMon();

  /* End of Outputs for SubSystem: '<S1>/GlbDchgMon' */

  /* Outputs for Atomic SubSystem: '<S11>/BMSVoltRngChk' */
  SWC_ADM_BMSVoltRngChk();

  /* End of Outputs for SubSystem: '<S11>/BMSVoltRngChk' */

  /* Outputs for Atomic SubSystem: '<S11>/Debounce' */
  /* SignalConversion generated from: '<S11>/Debounce' incorporates:
   *  Constant: '<S11>/CAL_ADM_BMSVoltRngErrCntThr_s16'
   *  Constant: '<S11>/CAL_ADM_BMSVoltRngErrDebThr_s16'
   *  Constant: '<S11>/CAL_ADM_BMSVoltRngErrRst_b'
   */
  VAR_ADM_BMSVoltRngErr_b = SWC_ADM_Debounce(SWC_ADM_B.LogicalOperator_a,
    CAL_ADM_BMSVoltRngErrRst_b, CAL_ADM_BMSVoltRngErrCntThr_s16,
    CAL_ADM_BMSVoltRngErrDebThr_s16, &SWC_ADM_DW.Debounce);

  /* End of Outputs for SubSystem: '<S11>/Debounce' */

  /* SignalConversion: '<S11>/Signal Conversion2' */
  set_ADM_BMSVoltRngErr(VAR_ADM_BMSVoltRngErr_b);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/SWC_ADM_1ms' */
}

/* Model initialize function */
void SWC_ADM_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void SWC_ADM_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
