/*
 * File: RDC.c
 *
 * Code generated for Simulink model 'RDC'.
 *
 * Model version                  : 1.335
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Thu Dec 24 13:01:34 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "RDC.h"
#include "RDC_private.h"

/* Exported block signals */
real32_T VAR_CDD_Rslv_Sin_f32;         /* '<Root>/CDD_Rslv_Sin' */
real32_T VAR_CDD_Rslv_Cos_f32;         /* '<Root>/CDD_Rslv_Cos' */
real32_T VAR_CDD_RslvTimeStamp_f32;    /* '<Root>/CDD_RslvTimeStamp' */
real32_T VAR_CDD_Rslv_TimeGp_f32;      /* '<Root>/CDD_Rslv_TimeGp' */
real32_T VAR_CDD_Rslv_SinMax_f32;      /* '<Root>/CDD_Rslv_SinMax' */
real32_T VAR_CDD_Rslv_SinMin_f32;      /* '<Root>/CDD_Rslv_SinMin' */
real32_T VAR_CDD_Rslv_CosMax_f32;      /* '<Root>/CDD_Rslv_CosMax' */
real32_T VAR_CDD_Rslv_CosMin_f32;      /* '<Root>/CDD_Rslv_CosMin' */
real32_T VAR_MCF_cofFrqPwm_f32;        /* '<Root>/MCF_cofFrqPwm' */
uint8_T VAR_LvPower_PowerUpFnh_u8;     /* '<Root>/LvPower_LvPowerUpFnh' */
real32_T VAR_RDC_nWoFlt_f32;           /* '<S4>/Switch' */
real32_T VAR_RDC_ArctanAgRtr_f32;      /* '<S19>/Switch' */
boolean_T VAR_RDC_flgSpdHorL_b;        /* '<S18>/Switch1' */
boolean_T VAR_RDC_flgLotErr_b;         /* '<S14>/Relational Operator4' */
real32_T VAR_RDC_nWoFlt_L1;

/* Exported data definition */
#pragma section ".rodata.Calib_32"

/* Definition for custom storage class: iEDS_Parameter */
const volatile real32_T CAL_RDC_NRestrict_f32 = 250.0F;
                               /* Referenced by: '<S6>/CAL_RDC_NRestrict_f32' */
const volatile real32_T CAL_RDC_Nset_f32 = 0.0F;
                                    /* Referenced by: '<S4>/CAL_RDC_Nset_f32' */
const volatile real32_T CAL_RDC_SpdHiHyst_f32 = 2900.0F;
                              /* Referenced by: '<S18>/CAL_RDC_SpdHiHyst_f32' */
const volatile real32_T CAL_RDC_SpdHi_f32 = 3000.0F;
                                  /* Referenced by: '<S18>/CAL_RDC_SpdHi_f32' */
const volatile boolean_T CAL_RDC_flgCorrectOrReal_b = 1;
                          /* Referenced by: '<S6>/CAL_RDC_flgCorrectOrReal_b' */
const volatile boolean_T CAL_RDC_flgNrealOrNset_b = 1;
                            /* Referenced by: '<S4>/CAL_RDC_flgNrealOrNset_b' */
const volatile uint16_T CAL_RDC_nWofltDelay_u16 = 102U;
                            /* Referenced by: '<S15>/CAL_RDC_nWofltDelay_u16' */
const volatile real32_T CAL_RDC_tiRsvlAngleSample_f32 = 0.0F;
                        /* Referenced by: '<S5>/CAL_RDC_tiRsvlAngleSample_f1' */

#pragma section

/* Block states (default storage) */
DW_RDC_T RDC_DW;

/* Real-time model */
RT_MODEL_RDC_T RDC_M_;
RT_MODEL_RDC_T *const RDC_M = &RDC_M_;

/* Model step function */
void RDC_step(void)
{
  int_T idxDelay;
  real32_T rtb_Product1;
  real32_T rtb_Divide_p;
  boolean_T rtb_Compare_g;
  real32_T rtb_Abs;
  real32_T rtb_Isc_ResSum4;
  real32_T rtb_Saturation_j;
  real32_T rtb_Add7_a;
  uint8_T rtb_Gain3;

  /* Product: '<S6>/Product1' incorporates:
   *  Constant: '<S6>/GLB_RDC_OneHalf_f32'
   *  Inport: '<Root>/CDD_Rslv_SinMax'
   *  Inport: '<Root>/CDD_Rslv_SinMin'
   *  Sum: '<S6>/Add'
   */
  rtb_Product1 = (VAR_CDD_Rslv_SinMax_f32 + VAR_CDD_Rslv_SinMin_f32) *
    GLB_RDC_OneHalf_f32;

  /* Logic: '<S6>/Logical Operator' incorporates:
   *  Abs: '<S6>/Abs'
   *  Constant: '<S6>/CAL_RDC_NRestrict_f32'
   *  Constant: '<S6>/CAL_RDC_flgCorrectOrReal_b'
   *  RelationalOperator: '<S6>/Relational Operator'
   */
  rtb_Compare_g = (CAL_RDC_flgCorrectOrReal_b && (fabsf(VAR_RDC_nWoFlt_f32) >=
    CAL_RDC_NRestrict_f32));

  /* Switch: '<S6>/Switch' incorporates:
   *  Inport: '<Root>/CDD_Rslv_Sin'
   *  Sum: '<S6>/Add6'
   */
  if (rtb_Compare_g) {
    rtb_Divide_p = VAR_CDD_Rslv_Sin_f32 - rtb_Product1;
  } else {
    rtb_Divide_p = VAR_CDD_Rslv_Sin_f32;
  }

  /* End of Switch: '<S6>/Switch' */

  /* Switch: '<S8>/Switch' incorporates:
   *  Abs: '<S8>/Abs'
   *  Constant: '<S8>/Constant'
   *  Constant: '<S9>/Constant'
   *  RelationalOperator: '<S9>/Compare'
   */
  if (fabsf(rtb_Divide_p) <= 0.0001F) {
    rtb_Divide_p = 0.0001F;
  }

  /* End of Switch: '<S8>/Switch' */

  /* Gain: '<S8>/Gain3' incorporates:
   *  Constant: '<S11>/Constant'
   *  RelationalOperator: '<S11>/Compare'
   */
  rtb_Gain3 = (uint8_T)((rtb_Divide_p >= 0.0F) << 7);

  /* Switch: '<S6>/Switch1' incorporates:
   *  Inport: '<Root>/CDD_Rslv_Cos'
   *  Product: '<S6>/Product'
   */
  if (rtb_Compare_g) {
    /* Product: '<S6>/Product2' incorporates:
     *  Constant: '<S6>/GLB_RDC_OneHalf_f32'
     *  Inport: '<Root>/CDD_Rslv_CosMax'
     *  Inport: '<Root>/CDD_Rslv_CosMin'
     *  Sum: '<S6>/Add1'
     */
    rtb_Saturation_j = (VAR_CDD_Rslv_CosMin_f32 + VAR_CDD_Rslv_CosMax_f32) *
      GLB_RDC_OneHalf_f32;

    /* Sum: '<S6>/Add7' incorporates:
     *  Inport: '<Root>/CDD_Rslv_Cos'
     */
    rtb_Add7_a = VAR_CDD_Rslv_Cos_f32 - rtb_Saturation_j;

    /* Sum: '<S6>/Add4' incorporates:
     *  Inport: '<Root>/CDD_Rslv_CosMax'
     */
    rtb_Saturation_j = VAR_CDD_Rslv_CosMax_f32 - rtb_Saturation_j;

    /* Saturate: '<S6>/Saturation1' */
    if (rtb_Saturation_j > 10000.0F) {
      rtb_Saturation_j = 10000.0F;
    } else {
      if (rtb_Saturation_j < 0.1F) {
        rtb_Saturation_j = 0.1F;
      }
    }

    /* End of Saturate: '<S6>/Saturation1' */

    /* Product: '<S6>/Divide' incorporates:
     *  Inport: '<Root>/CDD_Rslv_SinMax'
     *  Sum: '<S6>/Add3'
     */
    rtb_Saturation_j = (VAR_CDD_Rslv_SinMax_f32 - rtb_Product1) /
      rtb_Saturation_j;

    /* Saturate: '<S6>/Saturation' */
    if (rtb_Saturation_j > 1.5F) {
      rtb_Saturation_j = 1.5F;
    } else {
      if (rtb_Saturation_j < 0.5F) {
        rtb_Saturation_j = 0.5F;
      }
    }

    /* End of Saturate: '<S6>/Saturation' */
    rtb_Product1 = rtb_Saturation_j * rtb_Add7_a;
  } else {
    rtb_Product1 = VAR_CDD_Rslv_Cos_f32;
  }

  /* End of Switch: '<S6>/Switch1' */

  /* Switch: '<S8>/Switch1' incorporates:
   *  Abs: '<S8>/Abs1'
   *  Constant: '<S10>/Constant'
   *  Constant: '<S8>/Constant1'
   *  RelationalOperator: '<S10>/Compare'
   */
  if (fabsf(rtb_Product1) <= 0.0001F) {
    rtb_Product1 = 0.0001F;
  }

  /* End of Switch: '<S8>/Switch1' */

  /* Product: '<S8>/Divide' */
  rtb_Divide_p /= rtb_Product1;

  /* Abs: '<S8>/Abs2' */
  rtb_Divide_p = fabsf(rtb_Divide_p);

  /* RelationalOperator: '<S13>/Compare' incorporates:
   *  Constant: '<S13>/Constant'
   */
  rtb_Compare_g = (rtb_Divide_p >= 1.0F);

  /* Switch: '<S8>/Switch2' incorporates:
   *  Constant: '<S8>/Constant2'
   *  Product: '<S8>/Divide1'
   */
  if (rtb_Compare_g) {
    rtb_Divide_p = 1.0F / rtb_Divide_p;
  }

  /* End of Switch: '<S8>/Switch2' */

  /* MultiPortSwitch: '<S8>/Multiport Switch' incorporates:
   *  Constant: '<S12>/Constant'
   *  Constant: '<S8>/Constant10'
   *  Constant: '<S8>/Constant3'
   *  Constant: '<S8>/Constant4'
   *  Constant: '<S8>/Constant5'
   *  Constant: '<S8>/Constant7'
   *  Constant: '<S8>/Constant8'
   *  Constant: '<S8>/Constant9'
   *  Gain: '<S8>/Gain1'
   *  Gain: '<S8>/Gain2'
   *  Gain: '<S8>/Gain4'
   *  LookupNDDirect: '<S8>/Direct Lookup Table (n-D)'
   *  RelationalOperator: '<S12>/Compare'
   *  Sum: '<S8>/Add'
   *  Sum: '<S8>/Add1'
   *  Sum: '<S8>/Add2'
   *  Sum: '<S8>/Add3'
   *  Sum: '<S8>/Add5'
   *  Sum: '<S8>/Add6'
   *  Sum: '<S8>/Add7'
   *  Sum: '<S8>/Add8'
   *
   * About '<S8>/Direct Lookup Table (n-D)':
   *  1-dimensional Direct Look-Up returning a Scalar,
   *
   *     Remove protection against out-of-range input in generated code: 'off'
   */
  switch ((int32_T)((((((uint32_T)((rtb_Product1 >= 0.0F) << 7) << 1) +
                       rtb_Gain3) + ((uint32_T)(rtb_Compare_g << 7) << 2)) >> 2)
                    >> 5)) {
   case 0:
    /* LookupNDDirect: '<S8>/Direct Lookup Table (n-D)' incorporates:
     *  Gain: '<S8>/Gain'
     *
     * About '<S8>/Direct Lookup Table (n-D)':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     */
    rtb_Divide_p *= 1024.0F;
    if (rtb_Divide_p > 1024.0F) {
      rtb_Divide_p = 1024.0F;
    }

    rtb_Divide_p = (real32_T)(58672U * rtCP_DirectLookupTablenD_table[(int32_T)
      rtb_Divide_p]) * 1.49011612E-8F + 180.0F;
    break;

   case 1:
    /* LookupNDDirect: '<S8>/Direct Lookup Table (n-D)' incorporates:
     *  Gain: '<S8>/Gain'
     *
     * About '<S8>/Direct Lookup Table (n-D)':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     */
    rtb_Divide_p *= 1024.0F;
    if (rtb_Divide_p > 1024.0F) {
      rtb_Divide_p = 1024.0F;
    }

    rtb_Divide_p = 180.0F - (real32_T)(58672U * rtCP_DirectLookupTablenD_table
      [(int32_T)rtb_Divide_p]) * 1.49011612E-8F;
    break;

   case 2:
    /* LookupNDDirect: '<S8>/Direct Lookup Table (n-D)' incorporates:
     *  Gain: '<S8>/Gain'
     *
     * About '<S8>/Direct Lookup Table (n-D)':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     */
    rtb_Divide_p *= 1024.0F;
    if (rtb_Divide_p > 1024.0F) {
      rtb_Divide_p = 1024.0F;
    }

    rtb_Divide_p = 360.0F - (real32_T)(58672U * rtCP_DirectLookupTablenD_table
      [(int32_T)rtb_Divide_p]) * 1.49011612E-8F;
    break;

   case 3:
    /* LookupNDDirect: '<S8>/Direct Lookup Table (n-D)' incorporates:
     *  Gain: '<S8>/Gain'
     *
     * About '<S8>/Direct Lookup Table (n-D)':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     */
    rtb_Divide_p *= 1024.0F;
    if (rtb_Divide_p > 1024.0F) {
      rtb_Divide_p = 1024.0F;
    }

    rtb_Divide_p = (real32_T)(58672U * rtCP_DirectLookupTablenD_table[(int32_T)
      rtb_Divide_p]) * 1.49011612E-8F;
    break;

   case 4:
    /* LookupNDDirect: '<S8>/Direct Lookup Table (n-D)' incorporates:
     *  Gain: '<S8>/Gain'
     *
     * About '<S8>/Direct Lookup Table (n-D)':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     */
    rtb_Divide_p *= 1024.0F;
    if (rtb_Divide_p > 1024.0F) {
      rtb_Divide_p = 1024.0F;
    }

    rtb_Divide_p = 270.0F - (real32_T)(58672U * rtCP_DirectLookupTablenD_table
      [(int32_T)rtb_Divide_p]) * 1.49011612E-8F;
    break;

   case 5:
    /* LookupNDDirect: '<S8>/Direct Lookup Table (n-D)' incorporates:
     *  Gain: '<S8>/Gain'
     *
     * About '<S8>/Direct Lookup Table (n-D)':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     */
    rtb_Divide_p *= 1024.0F;
    if (rtb_Divide_p > 1024.0F) {
      rtb_Divide_p = 1024.0F;
    }

    rtb_Divide_p = (real32_T)(58672U * rtCP_DirectLookupTablenD_table[(int32_T)
      rtb_Divide_p]) * 1.49011612E-8F + 90.0F;
    break;

   case 6:
    /* LookupNDDirect: '<S8>/Direct Lookup Table (n-D)' incorporates:
     *  Gain: '<S8>/Gain'
     *
     * About '<S8>/Direct Lookup Table (n-D)':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     */
    rtb_Divide_p *= 1024.0F;
    if (rtb_Divide_p > 1024.0F) {
      rtb_Divide_p = 1024.0F;
    }

    rtb_Divide_p = (real32_T)(58672U * rtCP_DirectLookupTablenD_table[(int32_T)
      rtb_Divide_p]) * 1.49011612E-8F + 270.0F;
    break;

   default:
    /* LookupNDDirect: '<S8>/Direct Lookup Table (n-D)' incorporates:
     *  Gain: '<S8>/Gain'
     *
     * About '<S8>/Direct Lookup Table (n-D)':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     */
    rtb_Divide_p *= 1024.0F;
    if (rtb_Divide_p > 1024.0F) {
      rtb_Divide_p = 1024.0F;
    }

    rtb_Divide_p = 90.0F - (real32_T)(58672U * rtCP_DirectLookupTablenD_table
      [(int32_T)rtb_Divide_p]) * 1.49011612E-8F;
    break;
  }

  /* End of MultiPortSwitch: '<S8>/Multiport Switch' */

  /* Sum: '<S7>/Add2' incorporates:
   *  Constant: '<S1>/GLB_RDC_MotorPole_u8'
   *  Constant: '<S5>/CAL_RDC_tiRsvlAngleSample_f1'
   *  Constant: '<S5>/CalcuclateTime'
   *  Constant: '<S5>/GLB_RDC_CircAge_f32'
   *  Constant: '<S5>/GLB_RDC_Sixty_f32'
   *  Inport: '<Root>/CDD_RslvTimeStamp'
   *  Inport: '<Root>/CDD_Rslv_TimeGp'
   *  Product: '<S5>/Divide'
   *  Product: '<S5>/Product'
   *  Sum: '<S5>/Add5'
   */
  VAR_RDC_ArctanAgRtr_f32 = VAR_RDC_nWoFlt_f32 * (real32_T)((uint8_T)
    GLB_RDC_MotorPole_u8) * GLB_RDC_CircAge_f32 / GLB_RDC_Sixty_f32 / 1.0E+6F *
    ((VAR_CDD_RslvTimeStamp_f32 + VAR_CDD_Rslv_TimeGp_f32) +
     CAL_RDC_tiRsvlAngleSample_f32) + rtb_Divide_p;

  /* Switch: '<S7>/Switch' incorporates:
   *  Constant: '<S7>/Constant1'
   *  Constant: '<S7>/GLB_RDC_CircAge_f32'
   *  RelationalOperator: '<S7>/Relational Operator'
   *  RelationalOperator: '<S7>/Relational Operator1'
   *  Sum: '<S7>/Add'
   *  Switch: '<S7>/Switch1'
   */
  if (GLB_RDC_CircAge_f32 <= VAR_RDC_ArctanAgRtr_f32) {
    VAR_RDC_ArctanAgRtr_f32 -= GLB_RDC_CircAge_f32;
  } else {
    if (VAR_RDC_ArctanAgRtr_f32 < 0.0F) {
      /* Switch: '<S7>/Switch1' incorporates:
       *  Sum: '<S7>/Add1'
       */
      VAR_RDC_ArctanAgRtr_f32 += GLB_RDC_CircAge_f32;
    }
  }

  /* End of Switch: '<S7>/Switch' */

  /* Switch: '<S14>/Switch' incorporates:
   *  Constant: '<S14>/GLB_RDC_CircAge_f32'
   *  Gain: '<S14>/Gain'
   *  RelationalOperator: '<S14>/Relational Operator'
   *  RelationalOperator: '<S14>/Relational Operator1'
   *  Sum: '<S14>/Add'
   *  Switch: '<S14>/Switch1'
   */
  if (GLB_RDC_CircAge_f32 <= VAR_RDC_ArctanAgRtr_f32) {
    rtb_Divide_p = VAR_RDC_ArctanAgRtr_f32 - GLB_RDC_CircAge_f32;
  } else if (VAR_RDC_ArctanAgRtr_f32 <= -GLB_RDC_CircAge_f32) {
    /* Switch: '<S14>/Switch1' incorporates:
     *  Sum: '<S14>/Add1'
     */
    rtb_Divide_p = VAR_RDC_ArctanAgRtr_f32 + GLB_RDC_CircAge_f32;
  } else {
    /* Switch: '<S14>/Switch1' */
    rtb_Divide_p = VAR_RDC_ArctanAgRtr_f32;
  }

  /* End of Switch: '<S14>/Switch' */

  /* Sum: '<S14>/Add2' incorporates:
   *  UnitDelay: '<S14>/Unit Delay'
   */
  rtb_Product1 = rtb_Divide_p - RDC_DW.UnitDelay_DSTATE_c;

  /* Product: '<S14>/Product' incorporates:
   *  Constant: '<S14>/GLB_RDC_CircAge_f32'
   *  Constant: '<S14>/GLB_RDC_OneHalf_f32'
   */
  rtb_Saturation_j = GLB_RDC_OneHalf_f32 * GLB_RDC_CircAge_f32;

  /* Switch: '<S14>/Switch2' incorporates:
   *  Constant: '<S14>/GLB_RDC_CircAge_f32'
   *  Gain: '<S14>/Gain1'
   *  RelationalOperator: '<S14>/Relational Operator2'
   *  RelationalOperator: '<S14>/Relational Operator3'
   *  Sum: '<S14>/Add3'
   *  Switch: '<S14>/Switch3'
   */
  if (rtb_Product1 > rtb_Saturation_j) {
    rtb_Add7_a = rtb_Product1 - GLB_RDC_CircAge_f32;
  } else if (rtb_Product1 < -rtb_Saturation_j) {
    /* Switch: '<S14>/Switch3' incorporates:
     *  Constant: '<S14>/GLB_RDC_CircAge_f32'
     *  Sum: '<S14>/Add4'
     */
    rtb_Add7_a = rtb_Product1 + GLB_RDC_CircAge_f32;
  } else {
    rtb_Add7_a = rtb_Product1;
  }

  /* End of Switch: '<S14>/Switch2' */

  /* Product: '<S15>/Product3' incorporates:
   *  Inport: '<Root>/MCF_cofFrqPwm'
   */
  rtb_Add7_a *= VAR_MCF_cofFrqPwm_f32;

  /* Sum: '<S15>/Add7' incorporates:
   *  Delay: '<S15>/Delay1'
   *  Delay: '<S15>/Delay10'
   *  Delay: '<S15>/Delay2'
   *  Delay: '<S15>/Delay3'
   *  Delay: '<S15>/Delay4'
   *  Delay: '<S15>/Delay5'
   *  Delay: '<S15>/Delay6'
   *  Delay: '<S15>/Delay7'
   *  Delay: '<S15>/Delay9'
   */
  rtb_Isc_ResSum4 = ((((((((rtb_Add7_a + RDC_DW.Delay1_DSTATE) +
    RDC_DW.Delay10_DSTATE[0]) + RDC_DW.Delay9_DSTATE[0]) + RDC_DW.Delay7_DSTATE
    [0]) + RDC_DW.Delay6_DSTATE[0]) + RDC_DW.Delay5_DSTATE[0]) +
                      RDC_DW.Delay4_DSTATE[0]) + RDC_DW.Delay3_DSTATE[0]) +
    RDC_DW.Delay2_DSTATE[0];

  /* Switch: '<S15>/Switch' incorporates:
   *  Constant: '<S15>/Constant'
   *  Constant: '<S15>/Constant2'
   *  Constant: '<S15>/UpComplete'
   *  Inport: '<Root>/LvPower_LvPowerUpFnh'
   *  RelationalOperator: '<S15>/Relational Operator'
   *  Sum: '<S15>/Add'
   *  UnitDelay: '<S15>/Unit Delay'
   */
  if (VAR_LvPower_PowerUpFnh_u8 == 1) {
    /* Switch: '<S16>/Switch2' incorporates:
     *  Constant: '<S15>/CAL_RDC_nWofltDelay_u16'
     *  RelationalOperator: '<S16>/LowerRelop1'
     */
    if (RDC_DW.UnitDelay_DSTATE_h > CAL_RDC_nWofltDelay_u16) {
      RDC_DW.UnitDelay_DSTATE_h = CAL_RDC_nWofltDelay_u16;
    }

    /* End of Switch: '<S16>/Switch2' */
  } else {
    RDC_DW.UnitDelay_DSTATE_h = 0U;
  }

  RDC_DW.UnitDelay_DSTATE_h++;

  /* End of Switch: '<S15>/Switch' */

  /* Switch: '<S4>/Switch' incorporates:
   *  Constant: '<S4>/CAL_RDC_Nset_f32'
   *  Constant: '<S4>/CAL_RDC_flgNrealOrNset_b'
   *  Saturate: '<S4>/Saturation'
   */
  if (CAL_RDC_flgNrealOrNset_b) {
    /* Switch: '<S15>/Switch1' incorporates:
     *  Constant: '<S15>/CAL_RDC_nWofltDelay_u16'
     *  Constant: '<S15>/Calcaulate'
     *  Constant: '<S15>/Constant10'
     *  Constant: '<S15>/Constant3'
     *  Constant: '<S15>/GLB_RDC_MotorPole_u8'
     *  Delay: '<S15>/Delay11'
     *  Delay: '<S15>/Delay12'
     *  Delay: '<S15>/Delay13'
     *  Delay: '<S15>/Delay14'
     *  Delay: '<S15>/Delay15'
     *  Delay: '<S15>/Delay16'
     *  Delay: '<S15>/Delay17'
     *  Delay: '<S15>/Delay18'
     *  Delay: '<S15>/Delay8'
     *  Gain: '<S15>/Gain4'
     *  Product: '<S15>/Divide'
     *  RelationalOperator: '<S15>/Relational Operator1'
     *  Sum: '<S15>/Add6'
     *  UnitDelay: '<S15>/Unit Delay'
     */
    if (RDC_DW.UnitDelay_DSTATE_h >= CAL_RDC_nWofltDelay_u16) {
      VAR_RDC_nWoFlt_f32 = (((((((((rtb_Isc_ResSum4 + RDC_DW.Delay8_DSTATE) +
        RDC_DW.Delay11_DSTATE[0]) + RDC_DW.Delay18_DSTATE[0]) +
        RDC_DW.Delay17_DSTATE[0]) + RDC_DW.Delay16_DSTATE[0]) +
        RDC_DW.Delay15_DSTATE[0]) + RDC_DW.Delay14_DSTATE[0]) +
        RDC_DW.Delay13_DSTATE[0]) + RDC_DW.Delay12_DSTATE[0]) * 0.166666672F /
        100.0F / (real32_T)((uint8_T)GLB_RDC_MotorPole_u8) / 0.0001F;
    } else {
      VAR_RDC_nWoFlt_f32 = 0.0F;
    }

    /* End of Switch: '<S15>/Switch1' */
  } else if (CAL_RDC_Nset_f32 > 20000.0F) {
    /* Saturate: '<S4>/Saturation' */
    VAR_RDC_nWoFlt_f32 = 20000.0F;
  } else if (CAL_RDC_Nset_f32 < -20000.0F) {
    /* Saturate: '<S4>/Saturation' */
    VAR_RDC_nWoFlt_f32 = -20000.0F;
  } else {
    /* Saturate: '<S4>/Saturation' incorporates:
     *  Constant: '<S4>/CAL_RDC_Nset_f32'
     */
    VAR_RDC_nWoFlt_f32 = CAL_RDC_Nset_f32;
  }

  /* End of Switch: '<S4>/Switch' */

  /* Sum: '<S4>/Add4' incorporates:
   *  Constant: '<S4>/Constant3'
   *  Constant: '<S4>/Constant4'
   *  Product: '<S4>/Product'
   *  UnitDelay: '<S4>/Unit Delay'
   */
  RDC_DW.UnitDelay_DSTATE_o += VAR_RDC_nWoFlt_f32 * 0.0001F * 24.0F;

  /* Switch: '<S17>/Switch' incorporates:
   *  Constant: '<S17>/Constant'
   *  Constant: '<S17>/Constant1'
   *  RelationalOperator: '<S17>/Relational Operator'
   *  RelationalOperator: '<S17>/Relational Operator1'
   *  Sum: '<S17>/Add'
   *  Switch: '<S17>/Switch1'
   *  UnitDelay: '<S4>/Unit Delay'
   */
  if (360.0F <= RDC_DW.UnitDelay_DSTATE_o) {
    RDC_DW.UnitDelay_DSTATE_o -= 360.0F;
  } else {
    if (RDC_DW.UnitDelay_DSTATE_o <= -360.0F) {
      /* Switch: '<S17>/Switch1' incorporates:
       *  Constant: '<S17>/Constant2'
       *  Sum: '<S17>/Add1'
       *  UnitDelay: '<S4>/Unit Delay'
       */
      RDC_DW.UnitDelay_DSTATE_o += 360.0F;
    }
  }

  /* End of Switch: '<S17>/Switch' */

  /* Switch: '<S4>/Switch2' incorporates:
   *  Constant: '<S4>/CAL_RDC_flgNrealOrNset_b'
   *  UnitDelay: '<S4>/Unit Delay'
   */
  if (!CAL_RDC_flgNrealOrNset_b) {
    VAR_RDC_ArctanAgRtr_f32 = RDC_DW.UnitDelay_DSTATE_o;
  }

  /* End of Switch: '<S4>/Switch2' */

  /* Switch: '<S19>/Switch' incorporates:
   *  Constant: '<S19>/Constant1'
   *  Constant: '<S19>/GLB_RDC_CircAge_f32'
   *  RelationalOperator: '<S19>/Relational Operator'
   *  RelationalOperator: '<S19>/Relational Operator1'
   *  Sum: '<S19>/Add2'
   *  Switch: '<S19>/Switch1'
   */
  if (GLB_RDC_CircAge_f32 <= VAR_RDC_ArctanAgRtr_f32) {
    VAR_RDC_ArctanAgRtr_f32 -= GLB_RDC_CircAge_f32;
  } else {
    if (VAR_RDC_ArctanAgRtr_f32 <= 0.0F) {
      /* Switch: '<S19>/Switch1' incorporates:
       *  Sum: '<S19>/Add3'
       */
      VAR_RDC_ArctanAgRtr_f32 += GLB_RDC_CircAge_f32;
    }
  }

  /* End of Switch: '<S19>/Switch' */

  /* Abs: '<S18>/Abs' */
  rtb_Abs = fabsf(VAR_RDC_nWoFlt_f32);

  /* Switch: '<S18>/Switch1' incorporates:
   *  Constant: '<S18>/CAL_RDC_SpdHiHyst_f32'
   *  Constant: '<S18>/CAL_RDC_SpdHi_f32'
   *  Constant: '<S18>/Constant1'
   *  RelationalOperator: '<S18>/Relational Operator'
   *  RelationalOperator: '<S18>/Relational Operator1'
   *  UnitDelay: '<S18>/Unit Delay2'
   */
  if (rtb_Abs >= CAL_RDC_SpdHi_f32) {
    VAR_RDC_flgSpdHorL_b = false;
  } else {
    VAR_RDC_flgSpdHorL_b = ((rtb_Abs <= CAL_RDC_SpdHiHyst_f32) ||
      VAR_RDC_flgSpdHorL_b);
  }

  /* End of Switch: '<S18>/Switch1' */

  /* RelationalOperator: '<S14>/Relational Operator4' incorporates:
   *  Abs: '<S14>/Abs'
   */
  VAR_RDC_flgLotErr_b = (fabsf(rtb_Product1) > rtb_Saturation_j);

  /* Update for UnitDelay: '<S14>/Unit Delay' */
  RDC_DW.UnitDelay_DSTATE_c = rtb_Divide_p;

  /* Update for Delay: '<S15>/Delay1' */
  RDC_DW.Delay1_DSTATE = rtb_Add7_a;

  /* Update for Delay: '<S15>/Delay10' */
  RDC_DW.Delay10_DSTATE[0] = RDC_DW.Delay10_DSTATE[1];
  RDC_DW.Delay10_DSTATE[1] = rtb_Add7_a;

  /* Update for Delay: '<S15>/Delay9' */
  RDC_DW.Delay9_DSTATE[0] = RDC_DW.Delay9_DSTATE[1];
  RDC_DW.Delay9_DSTATE[1] = RDC_DW.Delay9_DSTATE[2];
  RDC_DW.Delay9_DSTATE[2] = rtb_Add7_a;

  /* Update for Delay: '<S15>/Delay7' */
  RDC_DW.Delay7_DSTATE[0] = RDC_DW.Delay7_DSTATE[1];
  RDC_DW.Delay7_DSTATE[1] = RDC_DW.Delay7_DSTATE[2];
  RDC_DW.Delay7_DSTATE[2] = RDC_DW.Delay7_DSTATE[3];
  RDC_DW.Delay7_DSTATE[3] = rtb_Add7_a;

  /* Update for Delay: '<S15>/Delay6' */
  RDC_DW.Delay6_DSTATE[0] = RDC_DW.Delay6_DSTATE[1];
  RDC_DW.Delay6_DSTATE[1] = RDC_DW.Delay6_DSTATE[2];
  RDC_DW.Delay6_DSTATE[2] = RDC_DW.Delay6_DSTATE[3];
  RDC_DW.Delay6_DSTATE[3] = RDC_DW.Delay6_DSTATE[4];
  RDC_DW.Delay6_DSTATE[4] = rtb_Add7_a;

  /* Update for Delay: '<S15>/Delay5' */
  for (idxDelay = 0; idxDelay < 5; idxDelay++) {
    RDC_DW.Delay5_DSTATE[idxDelay] = RDC_DW.Delay5_DSTATE[idxDelay + 1];
  }

  RDC_DW.Delay5_DSTATE[5] = rtb_Add7_a;

  /* End of Update for Delay: '<S15>/Delay5' */

  /* Update for Delay: '<S15>/Delay4' */
  for (idxDelay = 0; idxDelay < 6; idxDelay++) {
    RDC_DW.Delay4_DSTATE[idxDelay] = RDC_DW.Delay4_DSTATE[idxDelay + 1];
  }

  RDC_DW.Delay4_DSTATE[6] = rtb_Add7_a;

  /* End of Update for Delay: '<S15>/Delay4' */

  /* Update for Delay: '<S15>/Delay3' */
  for (idxDelay = 0; idxDelay < 7; idxDelay++) {
    RDC_DW.Delay3_DSTATE[idxDelay] = RDC_DW.Delay3_DSTATE[idxDelay + 1];
  }

  RDC_DW.Delay3_DSTATE[7] = rtb_Add7_a;

  /* End of Update for Delay: '<S15>/Delay3' */

  /* Update for Delay: '<S15>/Delay2' */
  for (idxDelay = 0; idxDelay < 8; idxDelay++) {
    RDC_DW.Delay2_DSTATE[idxDelay] = RDC_DW.Delay2_DSTATE[idxDelay + 1];
  }

  RDC_DW.Delay2_DSTATE[8] = rtb_Add7_a;

  /* End of Update for Delay: '<S15>/Delay2' */

  /* Update for Delay: '<S15>/Delay8' */
  RDC_DW.Delay8_DSTATE = rtb_Isc_ResSum4;

  /* Update for Delay: '<S15>/Delay11' */
  RDC_DW.Delay11_DSTATE[0] = RDC_DW.Delay11_DSTATE[1];
  RDC_DW.Delay11_DSTATE[1] = rtb_Isc_ResSum4;

  /* Update for Delay: '<S15>/Delay18' */
  RDC_DW.Delay18_DSTATE[0] = RDC_DW.Delay18_DSTATE[1];
  RDC_DW.Delay18_DSTATE[1] = RDC_DW.Delay18_DSTATE[2];
  RDC_DW.Delay18_DSTATE[2] = rtb_Isc_ResSum4;

  /* Update for Delay: '<S15>/Delay17' */
  RDC_DW.Delay17_DSTATE[0] = RDC_DW.Delay17_DSTATE[1];
  RDC_DW.Delay17_DSTATE[1] = RDC_DW.Delay17_DSTATE[2];
  RDC_DW.Delay17_DSTATE[2] = RDC_DW.Delay17_DSTATE[3];
  RDC_DW.Delay17_DSTATE[3] = rtb_Isc_ResSum4;

  /* Update for Delay: '<S15>/Delay16' */
  RDC_DW.Delay16_DSTATE[0] = RDC_DW.Delay16_DSTATE[1];
  RDC_DW.Delay16_DSTATE[1] = RDC_DW.Delay16_DSTATE[2];
  RDC_DW.Delay16_DSTATE[2] = RDC_DW.Delay16_DSTATE[3];
  RDC_DW.Delay16_DSTATE[3] = RDC_DW.Delay16_DSTATE[4];
  RDC_DW.Delay16_DSTATE[4] = rtb_Isc_ResSum4;

  /* Update for Delay: '<S15>/Delay15' */
  for (idxDelay = 0; idxDelay < 5; idxDelay++) {
    RDC_DW.Delay15_DSTATE[idxDelay] = RDC_DW.Delay15_DSTATE[idxDelay + 1];
  }

  RDC_DW.Delay15_DSTATE[5] = rtb_Isc_ResSum4;

  /* End of Update for Delay: '<S15>/Delay15' */

  /* Update for Delay: '<S15>/Delay14' */
  for (idxDelay = 0; idxDelay < 6; idxDelay++) {
    RDC_DW.Delay14_DSTATE[idxDelay] = RDC_DW.Delay14_DSTATE[idxDelay + 1];
  }

  RDC_DW.Delay14_DSTATE[6] = rtb_Isc_ResSum4;

  /* End of Update for Delay: '<S15>/Delay14' */

  /* Update for Delay: '<S15>/Delay13' */
  for (idxDelay = 0; idxDelay < 7; idxDelay++) {
    RDC_DW.Delay13_DSTATE[idxDelay] = RDC_DW.Delay13_DSTATE[idxDelay + 1];
  }

  RDC_DW.Delay13_DSTATE[7] = rtb_Isc_ResSum4;

  /* End of Update for Delay: '<S15>/Delay13' */

  /* Update for Delay: '<S15>/Delay12' */
  for (idxDelay = 0; idxDelay < 8; idxDelay++) {
    RDC_DW.Delay12_DSTATE[idxDelay] = RDC_DW.Delay12_DSTATE[idxDelay + 1];
  }

  RDC_DW.Delay12_DSTATE[8] = rtb_Isc_ResSum4;

  /* End of Update for Delay: '<S15>/Delay12' */
}

/* Model initialize function */
void RDC_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void RDC_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
