/*
 * File: SWC_SCF_EI09_EmDisChaFunction.c
 *
 * Code generated for Simulink model 'SWC_SCF'.
 *
 * Model version                  : 1.11
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Wed Jan 20 16:15:29 2021
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SWC_SCF_EI09_EmDisChaFunction.h"
#include "SWC_SCF_private.h"

/* Includes for objects with custom storage classes. */
#include "SWC_SCF.h"

/* Output and update for atomic system: '<S14>/EI09_EmDisChaFunction' */
void SWC_SCF_EI09_EmDisChaFunction(boolean rtu_HSPF_flgCrash, boolean
  rtu_CSPF_RecflgCrash, boolean *rty_flgEmgyDcha,
  DW_EI09_EmDisChaFunction_SWC__T *localDW)
{
  boolean tmp;

  /* Switch: '<S21>/Switch' incorporates:
   *  Constant: '<S21>/CAL_Smgsys_EmgDchabysiglordoubSwt_b'
   *  Logic: '<S21>/Logical Operator'
   *  Logic: '<S21>/Logical Operator1'
   */
  if (CAL_Scf_EmgDchabysiglordoubSwt_b) {
    tmp = (rtu_HSPF_flgCrash || rtu_CSPF_RecflgCrash);
  } else {
    tmp = (rtu_CSPF_RecflgCrash && rtu_HSPF_flgCrash);
  }

  /* End of Switch: '<S21>/Switch' */

  /* Switch: '<S22>/Switch3' incorporates:
   *  Constant: '<S22>/Constant8'
   *  UnitDelay: '<S22>/Unit Delay1'
   */
  if (tmp) {
    /* Sum: '<S22>/Sum' incorporates:
     *  UnitDelay: '<S22>/Unit Delay1'
     *  UnitDelay: '<S22>/Unit Delay2'
     */
    localDW->UnitDelay1_DSTATE = (uint16)((uint32)!localDW->UnitDelay2_DSTATE +
      localDW->UnitDelay1_DSTATE);

    /* Switch: '<S22>/Switch2' incorporates:
     *  Constant: '<S22>/Constant6'
     *  RelationalOperator: '<S22>/Relational Operator2'
     *  UnitDelay: '<S22>/Unit Delay1'
     */
    if (localDW->UnitDelay1_DSTATE >= 65535) {
      localDW->UnitDelay1_DSTATE = MAX_uint16_T;
    }

    /* End of Switch: '<S22>/Switch2' */
  } else {
    localDW->UnitDelay1_DSTATE = 0U;
  }

  /* End of Switch: '<S22>/Switch3' */

  /* RelationalOperator: '<S22>/Relational Operator3' incorporates:
   *  Constant: '<S22>/CAL_SmgSys_cntDchaSigFit_u8'
   *  Product: '<S22>/Product1'
   *  UnitDelay: '<S22>/Unit Delay1'
   */
  *rty_flgEmgyDcha = (localDW->UnitDelay1_DSTATE >= CAL_Scf_cntDchaSigFit_u8);

  /* Update for UnitDelay: '<S22>/Unit Delay2' */
  localDW->UnitDelay2_DSTATE = *rty_flgEmgyDcha;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
