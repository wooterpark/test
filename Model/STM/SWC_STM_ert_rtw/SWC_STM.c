/*
 * File: SWC_STM.c
 *
 * Code generated for Simulink model 'SWC_STM'.
 *
 * Model version                  : 1.508
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Wed Apr 27 16:14:23 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SWC_STM.h"
#include "SWC_STM_private.h"

/* user code (top of source file) */
#include "set_get_data.h"

/* Exported block signals */
boolean VAR_STM_UintndTrqMonRslt_b;    /* '<S7>/Logical Operator1' */
boolean VAR_STM_UintndTrqErr_b;        /* '<S6>/Logical Operator' */

/* Exported data definition */
#pragma section ".rodata.Calib_32"

/* Definition for custom storage class: iEDS_Parameter */
const volatile uint8 CAL_STM_SpeedCtlMode_u8 = 7U;
                             /* Referenced by: '<S5>/CAL_TOM_SpeedCtlMode_u1' */
const volatile float32 CAL_STM_TrqSetRamp_f32 = 20.0F;
                              /* Referenced by: '<S7>/CAL_STM_TrqSetRamp_f32' */
const volatile float32 CAL_STM_UxptTrqLim_f32 = 50.0F;/* Referenced by:
                                                       * '<S7>/Constant3'
                                                       * '<S7>/Constant4'
                                                       * '<S7>/Constant5'
                                                       */
const volatile sint16 CAL_STM_UxptTrqMonCountTrh_s16 = 100;
                          /* Referenced by: '<S4>/CAL_TOM_HiTrqMonDebTrh_s16' */
const volatile sint16 CAL_STM_UxptTrqMonDebTrh_s16 = 50;
                           /* Referenced by: '<S4>/CAL_TOM_HiTrqMonDebTrh_s1' */
const volatile boolean CAL_STM_UxptTrqMonErrRst_b = 0;
                          /* Referenced by: '<S4>/CAL_TOM_TrqMonMaulErrRst_b' */

#pragma section

/* Block states (default storage) */
DW_SWC_STM_T SWC_STM_DW;

/* Real-time model */
RT_MODEL_SWC_STM_T SWC_STM_M_;
RT_MODEL_SWC_STM_T *const SWC_STM_M = &SWC_STM_M_;

/* Output and update for atomic system: '<S4>/Debouncer' */
void SWC_STM_Debouncer(boolean rtu_BooleanIN, boolean rtu_Rst, sint16
  rtu_CountTrh, sint16 rtu_DebTrh, boolean *rty_OutLock, DW_Debouncer_SWC_STM_T *
  localDW)
{
  boolean rtb_RelationalOperator_l;

  /* Switch: '<S6>/Switch1' incorporates:
   *  UnitDelay: '<S6>/Unit Delay1'
   */
  localDW->UnitDelay1_DSTATE = ((!rtu_Rst) && localDW->UnitDelay1_DSTATE);

  /* Outputs for Enabled SubSystem: '<S6>/Subsystem' incorporates:
   *  EnablePort: '<S9>/Enable'
   */
  /* Delay: '<S6>/Delay1' */
  if (localDW->Delay1_DSTATE) {
    /* Sum: '<S9>/Add' incorporates:
     *  Constant: '<S9>/Constant'
     *  Delay: '<S9>/Delay'
     */
    localDW->Delay_DSTATE++;

    /* Switch: '<S9>/Switch' incorporates:
     *  Constant: '<S9>/Constant1'
     *  Delay: '<S9>/Delay'
     *  RelationalOperator: '<S9>/Relational Operator'
     */
    if (localDW->Delay_DSTATE >= rtu_CountTrh) {
      localDW->Delay_DSTATE = 0;
    }

    /* End of Switch: '<S9>/Switch' */
  }

  /* End of Outputs for SubSystem: '<S6>/Subsystem' */

  /* Switch: '<S6>/Switch2' incorporates:
   *  Constant: '<S6>/Constant'
   *  Constant: '<S8>/Constant'
   *  Delay: '<S6>/Delay2'
   *  Delay: '<S9>/Delay'
   *  RelationalOperator: '<S8>/Compare'
   */
  if (localDW->Delay_DSTATE == 0) {
    localDW->Delay2_DSTATE = 0;
  }

  /* End of Switch: '<S6>/Switch2' */

  /* Sum: '<S6>/Add' incorporates:
   *  Delay: '<S6>/Delay2'
   */
  localDW->Delay2_DSTATE += rtu_BooleanIN;

  /* RelationalOperator: '<S6>/Relational Operator' */
  rtb_RelationalOperator_l = (localDW->Delay2_DSTATE >= rtu_DebTrh);

  /* Logic: '<S6>/Logical Operator' incorporates:
   *  UnitDelay: '<S6>/Unit Delay1'
   */
  *rty_OutLock = (rtb_RelationalOperator_l || localDW->UnitDelay1_DSTATE);

  /* Switch: '<S6>/Switch' incorporates:
   *  Constant: '<S6>/Constant1'
   *  Delay: '<S6>/Delay2'
   */
  if (rtb_RelationalOperator_l) {
    localDW->Delay2_DSTATE = 0;
  }

  /* End of Switch: '<S6>/Switch' */

  /* Logic: '<S6>/Logical Operator1' incorporates:
   *  Delay: '<S6>/Delay1'
   */
  localDW->Delay1_DSTATE = (localDW->Delay1_DSTATE || rtu_BooleanIN);

  /* Update for UnitDelay: '<S6>/Unit Delay1' */
  localDW->UnitDelay1_DSTATE = *rty_OutLock;
}

/* Output and update for atomic system: '<S4>/UintndTrqMon' */
void SWC_STM_UintndTrqMon(void)
{
  float32 rtb_Saturation;
  float32 rtb_Subtract;
  boolean rtb_Compare;
  boolean rtb_LogicalOperator5;

  /* Saturate: '<S7>/Saturation' incorporates:
   *  Inport: '<Root>/L2Com_TrqSetP'
   */
  if (get_L2Com_TrqSetP() > 500.0F) {
    rtb_Saturation = 500.0F;
  } else if (get_L2Com_TrqSetP() < -500.0F) {
    rtb_Saturation = -500.0F;
  } else {
    rtb_Saturation = get_L2Com_TrqSetP();
  }

  /* End of Saturate: '<S7>/Saturation' */

  /* Sum: '<S7>/Subtract' incorporates:
   *  UnitDelay: '<S7>/Unit Delay2'
   */
  rtb_Subtract = rtb_Saturation - SWC_STM_DW.UnitDelay2_DSTATE;

  /* Switch: '<S7>/Switch2' incorporates:
   *  Constant: '<S7>/CAL_STM_TrqSetRamp_f32'
   *  RelationalOperator: '<S7>/Relational Operator'
   *  Sum: '<S7>/Add1'
   *  UnitDelay: '<S7>/Unit Delay2'
   */
  if (rtb_Subtract <= CAL_STM_TrqSetRamp_f32) {
    /* Switch: '<S7>/Switch3' incorporates:
     *  Product: '<S7>/Product'
     *  RelationalOperator: '<S7>/Relational Operator1'
     */
    if (-rtb_Subtract <= CAL_STM_TrqSetRamp_f32) {
      /* UnitDelay: '<S7>/Unit Delay2' */
      SWC_STM_DW.UnitDelay2_DSTATE = rtb_Saturation;
    } else {
      /* UnitDelay: '<S7>/Unit Delay2' incorporates:
       *  Sum: '<S7>/Add2'
       */
      SWC_STM_DW.UnitDelay2_DSTATE -= CAL_STM_TrqSetRamp_f32;
    }

    /* End of Switch: '<S7>/Switch3' */
  } else {
    SWC_STM_DW.UnitDelay2_DSTATE += CAL_STM_TrqSetRamp_f32;
  }

  /* End of Switch: '<S7>/Switch2' */

  /* RelationalOperator: '<S10>/Compare' incorporates:
   *  Constant: '<S10>/Constant'
   *  UnitDelay: '<S7>/Unit Delay2'
   */
  rtb_Compare = (SWC_STM_DW.UnitDelay2_DSTATE >= 0.0F);

  /* Logic: '<S7>/Logical Operator5' incorporates:
   *  Constant: '<S7>/GLB_TOM_PosvTrq_u1'
   *  Constant: '<S7>/GLB_TpcCod_ZeroTrq_u1'
   *  Inport: '<Root>/TCF_TrqDir'
   *  RelationalOperator: '<S7>/Relational Operator10'
   *  RelationalOperator: '<S7>/Relational Operator11'
   */
  rtb_LogicalOperator5 = ((get_TCF_TrqDir() == ((uint8)GLB_STM_PosvTrq_u8)) ||
    (get_TCF_TrqDir() == ((uint8)GLB_STM_ZeroTrq_u8)));

  /* Sum: '<S7>/Add3' incorporates:
   *  Inport: '<Root>/TCF_BlendTrq'
   *  UnitDelay: '<S7>/Unit Delay2'
   */
  rtb_Saturation = get_TCF_BlendTrq() - SWC_STM_DW.UnitDelay2_DSTATE;

  /* Logic: '<S7>/Logical Operator1' incorporates:
   *  Abs: '<S7>/Abs'
   *  Constant: '<S7>/Constant3'
   *  Constant: '<S7>/Constant4'
   *  Constant: '<S7>/Constant5'
   *  Gain: '<S7>/Gain2'
   *  Inport: '<Root>/TCF_BlendTrq'
   *  Logic: '<S7>/Logical Operator10'
   *  Logic: '<S7>/Logical Operator6'
   *  Logic: '<S7>/Logical Operator7'
   *  Logic: '<S7>/Logical Operator8'
   *  Logic: '<S7>/Logical Operator9'
   *  RelationalOperator: '<S7>/Relational Operator12'
   *  RelationalOperator: '<S7>/Relational Operator13'
   *  RelationalOperator: '<S7>/Relational Operator14'
   *  RelationalOperator: '<S7>/Relational Operator15'
   */
  VAR_STM_UintndTrqMonRslt_b = ((rtb_LogicalOperator5 && rtb_Compare &&
    (rtb_Saturation >= CAL_STM_UxptTrqLim_f32)) || ((!rtb_LogicalOperator5) && (
    !rtb_Compare) && (rtb_Saturation <= -CAL_STM_UxptTrqLim_f32)) ||
    ((rtb_LogicalOperator5 != rtb_Compare) && (fabsf(get_TCF_BlendTrq()) >=
    CAL_STM_UxptTrqLim_f32)));
}

/* Model step function for TID1 */
void SWC_STM_1ms(void)                 /* Explicit Task: SWC_STM_1ms */
{
  /* RootInportFunctionCallGenerator generated from: '<Root>/SWC_STM_1ms' incorporates:
   *  SubSystem: '<Root>/SWC_STM_1ms_sys'
   */
  /* Outputs for Enabled SubSystem: '<S3>/TrqMon' incorporates:
   *  EnablePort: '<S4>/Enable'
   */
  /* Outputs for Atomic SubSystem: '<S3>/TrqMonEnable' */
  /* RelationalOperator: '<S5>/Relational Operator1' incorporates:
   *  Constant: '<S4>/CAL_TOM_HiTrqMonDebTrh_s1'
   *  Constant: '<S4>/CAL_TOM_HiTrqMonDebTrh_s16'
   *  Constant: '<S4>/CAL_TOM_TrqMonMaulErrRst_b'
   *  Constant: '<S5>/CAL_TOM_SpeedCtlMode_u1'
   *  Inport: '<Root>/L2Com_ModeReq'
   */
  if (get_L2Com_ModeReq() != CAL_STM_SpeedCtlMode_u8) {
    /* Outputs for Atomic SubSystem: '<S4>/UintndTrqMon' */
    SWC_STM_UintndTrqMon();

    /* End of Outputs for SubSystem: '<S4>/UintndTrqMon' */

    /* Outputs for Atomic SubSystem: '<S4>/Debouncer' */
    SWC_STM_Debouncer(VAR_STM_UintndTrqMonRslt_b, CAL_STM_UxptTrqMonErrRst_b,
                      CAL_STM_UxptTrqMonCountTrh_s16,
                      CAL_STM_UxptTrqMonDebTrh_s16, &VAR_STM_UintndTrqErr_b,
                      &SWC_STM_DW.Debouncer);

    /* End of Outputs for SubSystem: '<S4>/Debouncer' */
  }

  /* End of RelationalOperator: '<S5>/Relational Operator1' */
  /* End of Outputs for SubSystem: '<S3>/TrqMonEnable' */
  /* End of Outputs for SubSystem: '<S3>/TrqMon' */

  /* SignalConversion: '<S1>/Signal Conversion1' */
  set_STM_UintndTrqErr(VAR_STM_UintndTrqErr_b);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/SWC_STM_1ms' */
}

/* Model initialize function */
void SWC_STM_initialize(void)
{
  /* SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/SWC_STM_1ms' incorporates:
   *  SubSystem: '<Root>/SWC_STM_1ms_sys'
   */
  /* SystemInitialize for SignalConversion: '<S1>/Signal Conversion1' */
  set_STM_UintndTrqErr(VAR_STM_UintndTrqErr_b);

  /* End of SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/SWC_STM_1ms' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
