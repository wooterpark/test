/*
 * File: SWC_STM.c
 *
 * Code generated for Simulink model 'SWC_STM'.
 *
 * Model version                  : 1.499
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Wed Sep  1 08:21:32 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SWC_STM.h"
#include "SWC_STM_private.h"
#include "set_get_data.h"

#pragma section ".data.CPU1_32"
/* Exported block signals */
boolean VAR_STM_UintndTrqMonRslt_b;    /* '<S18>/Logical Operator1' */
boolean VAR_STM_UintndTrqErr_b;        /* '<S17>/Logical Operator' */
boolean VAR_STM_UintndSpdMonRslt_b;    /* '<S11>/Logical Operator1' */
boolean VAR_STM_UintndSpdErr_b;        /* '<S10>/Logical Operator' */
#pragma section
/* Exported data definition */
#pragma section ".rodata.CPU1_Calib_32"

/* Definition for custom storage class: iEDS_Parameter */
const volatile uint8 CAL_STM_SpeedCtlMode_u8 = 10U;/* Referenced by:
                                                    * '<S9>/Constant'
                                                    * '<S16>/CAL_TOM_SpeedCtlMode_u1'
                                                    */
const volatile float32 CAL_STM_UxptNLim_f32 = 500.0F;/* Referenced by:
                                                      * '<S11>/Constant3'
                                                      * '<S11>/Constant4'
                                                      * '<S11>/Constant5'
                                                      */
const volatile sint16 CAL_STM_UxptSpdMonCountTrh_s16 = 150;
                          /* Referenced by: '<S8>/CAL_TOM_SpeedMonDebTrh_s16' */
const volatile sint16 CAL_STM_UxptSpdMonDebTrh_s16 = 100;
                           /* Referenced by: '<S8>/CAL_TOM_SpeedMonDebTrh_s1' */
const volatile boolean CAL_STM_UxptSpdMonErrRst_b = 0;
                            /* Referenced by: '<S8>/CAL_TOM_SpeedMonErrRst_b' */
const volatile float32 CAL_STM_UxptTrqLim_f32 = 50.0F;/* Referenced by:
                                                       * '<S18>/Constant3'
                                                       * '<S18>/Constant4'
                                                       * '<S18>/Constant5'
                                                       */
const volatile sint16 CAL_STM_UxptTrqMonCountTrh_s16 = 150;
                         /* Referenced by: '<S15>/CAL_TOM_HiTrqMonDebTrh_s16' */
const volatile sint16 CAL_STM_UxptTrqMonDebTrh_s16 = 100;
                          /* Referenced by: '<S15>/CAL_TOM_HiTrqMonDebTrh_s1' */
const volatile boolean CAL_STM_UxptTrqMonErrRst_b = 0;
                         /* Referenced by: '<S15>/CAL_TOM_TrqMonMaulErrRst_b' */

#pragma section

#pragma section ".data.CPU1_32"
/* Block signals (default storage) */
B_SWC_STM_T SWC_STM_B;

/* Block states (default storage) */
DW_SWC_STM_T SWC_STM_DW;
#pragma section
/* Real-time model */
RT_MODEL_SWC_STM_T SWC_STM_M_;
RT_MODEL_SWC_STM_T *const SWC_STM_M = &SWC_STM_M_;

/*
 * Output and update for enable system:
 *    '<S3>/Subsystem'
 *    '<S10>/Subsystem'
 *    '<S17>/Subsystem'
 */
#pragma section ".text.CPU1_Code" ax
void SWC_STM_Subsystem(boolean rtu_Enable, sint16 rtu_CountTrh, sint16
  *rty_Count, DW_Subsystem_SWC_STM_T *localDW)
{
  sint16 rtb_Add_g;

  /* Outputs for Enabled SubSystem: '<S3>/Subsystem' incorporates:
   *  EnablePort: '<S7>/Enable'
   */
  if (rtu_Enable) {
    /* Sum: '<S7>/Add' incorporates:
     *  Constant: '<S7>/Constant'
     *  Delay: '<S7>/Delay'
     */
    rtb_Add_g = (sint16)(localDW->Delay_DSTATE + 1);

    /* Switch: '<S7>/Switch' incorporates:
     *  Constant: '<S7>/Constant1'
     *  RelationalOperator: '<S7>/Relational Operator'
     */
    if (rtb_Add_g >= rtu_CountTrh) {
      *rty_Count = 0;
    } else {
      *rty_Count = rtb_Add_g;
    }

    /* End of Switch: '<S7>/Switch' */

    /* Update for Delay: '<S7>/Delay' */
    localDW->Delay_DSTATE = *rty_Count;
  }

  /* End of Outputs for SubSystem: '<S3>/Subsystem' */
}

/* Output and update for atomic system: '<S1>/Debouncer' */
void SWC_STM_Debouncer(boolean rtu_BooleanIN, boolean rtu_Rst, sint16
  rtu_CountTrh, sint16 rtu_DebTrh, boolean *rty_OutLock, sint16 *rty_Count,
  sint16 *rty_Deb, DW_Debouncer_SWC_STM_T *localDW)
{
  boolean rtb_RelationalOperator_f;

  /* Switch: '<S3>/Switch1' incorporates:
   *  UnitDelay: '<S3>/Unit Delay1'
   */
  localDW->UnitDelay1_DSTATE = ((!rtu_Rst) && localDW->UnitDelay1_DSTATE);

  /* Outputs for Enabled SubSystem: '<S3>/Subsystem' */
  /* Delay: '<S3>/Delay1' */
  SWC_STM_Subsystem(localDW->Delay1_DSTATE, rtu_CountTrh, rty_Count,
                    &localDW->Subsystem);

  /* End of Outputs for SubSystem: '<S3>/Subsystem' */

  /* Switch: '<S3>/Switch2' incorporates:
   *  Constant: '<S3>/Constant'
   *  Constant: '<S6>/Constant'
   *  Delay: '<S3>/Delay2'
   *  RelationalOperator: '<S6>/Compare'
   */
  if (*rty_Count == 0) {
    localDW->Delay2_DSTATE = 0;
  }

  /* End of Switch: '<S3>/Switch2' */

  /* Sum: '<S3>/Add' incorporates:
   *  Delay: '<S3>/Delay2'
   */
  *rty_Deb = (sint16)(rtu_BooleanIN + localDW->Delay2_DSTATE);

  /* RelationalOperator: '<S3>/Relational Operator' */
  rtb_RelationalOperator_f = (*rty_Deb >= rtu_DebTrh);

  /* Logic: '<S3>/Logical Operator' incorporates:
   *  UnitDelay: '<S3>/Unit Delay1'
   */
  *rty_OutLock = (rtb_RelationalOperator_f || localDW->UnitDelay1_DSTATE);

  /* Switch: '<S3>/Switch' incorporates:
   *  Constant: '<S3>/Constant1'
   *  Delay: '<S3>/Delay2'
   */
  if (rtb_RelationalOperator_f) {
    localDW->Delay2_DSTATE = 0;
  } else {
    localDW->Delay2_DSTATE = *rty_Deb;
  }

  /* End of Switch: '<S3>/Switch' */

  /* Logic: '<S3>/Logical Operator1' incorporates:
   *  Delay: '<S3>/Delay1'
   */
  localDW->Delay1_DSTATE = (localDW->Delay1_DSTATE || rtu_BooleanIN);

  /* Update for UnitDelay: '<S3>/Unit Delay1' */
  localDW->UnitDelay1_DSTATE = *rty_OutLock;
}

/*
 * Output and update for atomic system:
 *    '<S8>/Debouncer'
 *    '<S15>/Debouncer'
 */
void SWC_STM_Debouncer_n(boolean rtu_BooleanIN, boolean rtu_Rst, sint16
  rtu_CountTrh, sint16 rtu_DebTrh, boolean *rty_OutLock, B_Debouncer_SWC_STM_k_T
  *localB, DW_Debouncer_SWC_STM_i_T *localDW)
{
  boolean rtb_RelationalOperator_b;

  /* Switch: '<S10>/Switch1' incorporates:
   *  UnitDelay: '<S10>/Unit Delay1'
   */
  localDW->UnitDelay1_DSTATE = ((!rtu_Rst) && localDW->UnitDelay1_DSTATE);

  /* Outputs for Enabled SubSystem: '<S10>/Subsystem' */
  /* Delay: '<S10>/Delay1' */
  SWC_STM_Subsystem(localDW->Delay1_DSTATE, rtu_CountTrh, &localB->Switch,
                    &localDW->Subsystem);

  /* End of Outputs for SubSystem: '<S10>/Subsystem' */

  /* Switch: '<S10>/Switch2' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S12>/Constant'
   *  Delay: '<S10>/Delay2'
   *  RelationalOperator: '<S12>/Compare'
   */
  if (localB->Switch == 0) {
    localDW->Delay2_DSTATE = 0;
  }

  /* End of Switch: '<S10>/Switch2' */

  /* Sum: '<S10>/Add' incorporates:
   *  Delay: '<S10>/Delay2'
   */
  localDW->Delay2_DSTATE += rtu_BooleanIN;

  /* RelationalOperator: '<S10>/Relational Operator' */
  rtb_RelationalOperator_b = (localDW->Delay2_DSTATE >= rtu_DebTrh);

  /* Logic: '<S10>/Logical Operator' incorporates:
   *  UnitDelay: '<S10>/Unit Delay1'
   */
  *rty_OutLock = (rtb_RelationalOperator_b || localDW->UnitDelay1_DSTATE);

  /* Switch: '<S10>/Switch' incorporates:
   *  Constant: '<S10>/Constant1'
   *  Delay: '<S10>/Delay2'
   */
  if (rtb_RelationalOperator_b) {
    localDW->Delay2_DSTATE = 0;
  }

  /* End of Switch: '<S10>/Switch' */

  /* Logic: '<S10>/Logical Operator1' incorporates:
   *  Delay: '<S10>/Delay1'
   */
  localDW->Delay1_DSTATE = (localDW->Delay1_DSTATE || rtu_BooleanIN);

  /* Update for UnitDelay: '<S10>/Unit Delay1' */
  localDW->UnitDelay1_DSTATE = *rty_OutLock;
}

/* Output and update for atomic system: '<S8>/UintndSpdMon' */
void SWC_STM_UintndSpdMon(void)
{
  float32 rtb_Add3;
  boolean rtb_Compare;
  boolean rtb_LogicalOperator5;

  /* RelationalOperator: '<S14>/Compare' incorporates:
   *  Constant: '<S14>/Constant'
   *  Inport: '<Root>/L2Com_NSetP'
   */
  rtb_Compare = (get_L2Com_NSetP() >= 0.0F);

  /* Logic: '<S11>/Logical Operator5' incorporates:
   *  Constant: '<S11>/GLB_TOM_MotorFw_u1'
   *  Constant: '<S11>/GLB_TOM_MotorStop_u8'
   *  Inport: '<Root>/TCF_nDir'
   *  RelationalOperator: '<S11>/Relational Operator10'
   *  RelationalOperator: '<S11>/Relational Operator11'
   */
  rtb_LogicalOperator5 = ((get_TCF_nDir() == ((uint8)GLB_STM_MotorFw_u8)) ||
    (get_TCF_nDir() == ((uint8)GLB_STM_MotorStop_u8)));

  /* Sum: '<S11>/Add3' incorporates:
   *  Inport: '<Root>/L2Com_NSetP'
   *  Inport: '<Root>/SWD_nWoFlt'
   */
  rtb_Add3 = get_SWD_Spd() - get_L2Com_NSetP();

  /* Logic: '<S11>/Logical Operator1' incorporates:
   *  Abs: '<S11>/Abs'
   *  Constant: '<S11>/Constant3'
   *  Constant: '<S11>/Constant4'
   *  Constant: '<S11>/Constant5'
   *  Gain: '<S11>/Gain2'
   *  Inport: '<Root>/SWD_nWoFlt'
   *  Logic: '<S11>/Logical Operator10'
   *  Logic: '<S11>/Logical Operator6'
   *  Logic: '<S11>/Logical Operator7'
   *  Logic: '<S11>/Logical Operator8'
   *  Logic: '<S11>/Logical Operator9'
   *  RelationalOperator: '<S11>/Relational Operator12'
   *  RelationalOperator: '<S11>/Relational Operator13'
   *  RelationalOperator: '<S11>/Relational Operator14'
   *  RelationalOperator: '<S11>/Relational Operator15'
   */
  VAR_STM_UintndSpdMonRslt_b = ((rtb_LogicalOperator5 && rtb_Compare &&
    (rtb_Add3 >= CAL_STM_UxptNLim_f32)) || ((!rtb_LogicalOperator5) &&
    (!rtb_Compare) && (rtb_Add3 <= -CAL_STM_UxptNLim_f32)) ||
    ((rtb_LogicalOperator5 != rtb_Compare) && (fabsf(get_SWD_Spd()) >=
    CAL_STM_UxptNLim_f32)));
}

/* Output and update for atomic system: '<S15>/UintndTrqMon' */
void SWC_STM_UintndTrqMon(void)
{
  float32 rtb_Add3;
  boolean rtb_Compare;
  boolean rtb_LogicalOperator5;

  /* RelationalOperator: '<S21>/Compare' incorporates:
   *  Constant: '<S21>/Constant'
   *  Inport: '<Root>/L2Com_TrqSetP'
   */
  rtb_Compare = (get_L2Com_TrqSetP() >= 0.0F);

  /* Logic: '<S18>/Logical Operator5' incorporates:
   *  Constant: '<S18>/GLB_TOM_PosvTrq_u1'
   *  Constant: '<S18>/GLB_TpcCod_ZeroTrq_u1'
   *  Inport: '<Root>/TCF_TrqDir'
   *  RelationalOperator: '<S18>/Relational Operator10'
   *  RelationalOperator: '<S18>/Relational Operator11'
   */
  rtb_LogicalOperator5 = ((get_TCF_TrqDir() == ((uint8)GLB_STM_PosvTrq_u8)) ||
    (get_TCF_TrqDir() == ((uint8)GLB_STM_ZeroTrq_u8)));

  /* Sum: '<S18>/Add3' incorporates:
   *  Inport: '<Root>/L2Com_TrqSetP'
   *  Inport: '<Root>/TCF_BlendTrq'
   */
  rtb_Add3 = get_TCF_BlendTrq() - get_L2Com_TrqSetP();

  /* Logic: '<S18>/Logical Operator1' incorporates:
   *  Abs: '<S18>/Abs'
   *  Constant: '<S18>/Constant3'
   *  Constant: '<S18>/Constant4'
   *  Constant: '<S18>/Constant5'
   *  Gain: '<S18>/Gain2'
   *  Inport: '<Root>/TCF_BlendTrq'
   *  Logic: '<S18>/Logical Operator10'
   *  Logic: '<S18>/Logical Operator6'
   *  Logic: '<S18>/Logical Operator7'
   *  Logic: '<S18>/Logical Operator8'
   *  Logic: '<S18>/Logical Operator9'
   *  RelationalOperator: '<S18>/Relational Operator12'
   *  RelationalOperator: '<S18>/Relational Operator13'
   *  RelationalOperator: '<S18>/Relational Operator14'
   *  RelationalOperator: '<S18>/Relational Operator15'
   */
  VAR_STM_UintndTrqMonRslt_b = ((rtb_LogicalOperator5 && rtb_Compare &&
    (rtb_Add3 >= CAL_STM_UxptTrqLim_f32)) || ((!rtb_LogicalOperator5) &&
    (!rtb_Compare) && (rtb_Add3 <= -CAL_STM_UxptTrqLim_f32)) ||
    ((rtb_LogicalOperator5 != rtb_Compare) && (fabsf(get_TCF_BlendTrq()) >=
    CAL_STM_UxptTrqLim_f32)));
}

/* Model step function for TID1 */
void SWC_STM_1ms(void)                 /* Explicit Task: SWC_STM_1ms */
{
  boolean rtb_LogicalOperator;
  sint16 rtb_Add;

  /* RootInportFunctionCallGenerator generated from: '<Root>/SWC_STM_1ms' incorporates:
   *  SubSystem: '<Root>/SWC_STM_1ms_sys'
   */
  /* Outputs for Enabled SubSystem: '<S4>/SpdMon' incorporates:
   *  EnablePort: '<S8>/Enable'
   */
  /* Outputs for Atomic SubSystem: '<S4>/SpdMonEnable' */
  /* RelationalOperator: '<S9>/Relational Operator' incorporates:
   *  Constant: '<S8>/CAL_TOM_SpeedMonDebTrh_s1'
   *  Constant: '<S8>/CAL_TOM_SpeedMonDebTrh_s16'
   *  Constant: '<S8>/CAL_TOM_SpeedMonErrRst_b'
   *  Constant: '<S9>/Constant'
   *  Inport: '<Root>/L2Com_ModeReq'
   */
/*  if (get_L2Com_ModeReq() == CAL_STM_SpeedCtlMode_u8) {
     Outputs for Atomic SubSystem: '<S8>/UintndSpdMon'
    SWC_STM_UintndSpdMon();

     End of Outputs for SubSystem: '<S8>/UintndSpdMon'

     Outputs for Atomic SubSystem: '<S8>/Debouncer'
    SWC_STM_Debouncer_n(VAR_STM_UintndSpdMonRslt_b, CAL_STM_UxptSpdMonErrRst_b,
                        CAL_STM_UxptSpdMonCountTrh_s16,
                        CAL_STM_UxptSpdMonDebTrh_s16, &VAR_STM_UintndSpdErr_b,
                        &SWC_STM_B.Debouncer_n, &SWC_STM_DW.Debouncer_n);

     End of Outputs for SubSystem: '<S8>/Debouncer'
  }*/

  /* End of RelationalOperator: '<S9>/Relational Operator' */
  /* End of Outputs for SubSystem: '<S4>/SpdMonEnable' */
  /* End of Outputs for SubSystem: '<S4>/SpdMon' */

  /* SignalConversion: '<S1>/Signal Conversion' */
 // set_STM_UintndSpdErr(VAR_STM_UintndSpdErr_b);

  /* Outputs for Enabled SubSystem: '<S5>/TrqMon' incorporates:
   *  EnablePort: '<S15>/Enable'
   */
  /* Outputs for Atomic SubSystem: '<S5>/TrqMonEnable' */
  /* RelationalOperator: '<S16>/Relational Operator1' incorporates:
   *  Constant: '<S15>/CAL_TOM_HiTrqMonDebTrh_s1'
   *  Constant: '<S15>/CAL_TOM_HiTrqMonDebTrh_s16'
   *  Constant: '<S15>/CAL_TOM_TrqMonMaulErrRst_b'
   *  Constant: '<S16>/CAL_TOM_SpeedCtlMode_u1'
   *  Inport: '<Root>/L2Com_ModeReq'
   */
  if (get_L2Com_ModeReq() != CAL_STM_SpeedCtlMode_u8) {
    /* Outputs for Atomic SubSystem: '<S15>/UintndTrqMon' */
    SWC_STM_UintndTrqMon();

    /* End of Outputs for SubSystem: '<S15>/UintndTrqMon' */

    /* Outputs for Atomic SubSystem: '<S15>/Debouncer' */
    SWC_STM_Debouncer_n(VAR_STM_UintndTrqMonRslt_b, CAL_STM_UxptTrqMonErrRst_b,
                        CAL_STM_UxptTrqMonCountTrh_s16,
                        CAL_STM_UxptTrqMonDebTrh_s16, &VAR_STM_UintndTrqErr_b,
                        &SWC_STM_B.Debouncer_l, &SWC_STM_DW.Debouncer_l);

    /* End of Outputs for SubSystem: '<S15>/Debouncer' */
  }

  /* End of RelationalOperator: '<S16>/Relational Operator1' */
  /* End of Outputs for SubSystem: '<S5>/TrqMonEnable' */
  /* End of Outputs for SubSystem: '<S5>/TrqMon' */

  /* SignalConversion: '<S1>/Signal Conversion1' */
  set_STM_UintndTrqErr(VAR_STM_UintndTrqErr_b);

  /* Outputs for Atomic SubSystem: '<S1>/Debouncer' */
  SWC_STM_Debouncer(false, false, 0, 0, &rtb_LogicalOperator, &SWC_STM_B.Switch,
                    &rtb_Add, &SWC_STM_DW.Debouncer);

  /* End of Outputs for SubSystem: '<S1>/Debouncer' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/SWC_STM_1ms' */
}

/* Model initialize function */
void SWC_STM_initialize(void)
{
  /* SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/SWC_STM_1ms' incorporates:
   *  SubSystem: '<Root>/SWC_STM_1ms_sys'
   */
  /* SystemInitialize for SignalConversion: '<S1>/Signal Conversion' */
  set_STM_UintndSpdErr(VAR_STM_UintndSpdErr_b);

  /* SystemInitialize for SignalConversion: '<S1>/Signal Conversion1' */
  set_STM_UintndTrqErr(VAR_STM_UintndTrqErr_b);

  /* End of SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/SWC_STM_1ms' */
}
#pragma section
/*
 * File trailer for generated code.
 *
 * [EOF]
 */
