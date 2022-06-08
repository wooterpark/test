/*
 * File: SWC_LvPower.c
 *
 * Code generated for Simulink model 'SWC_LvPower'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Wed Jul  1 09:58:15 2020
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SWC_LvPower.h"
#include "SWC_LvPower_private.h"

/* Model step function for TID1 */
void SWC_LvPowerSetup_Task_1ms(void)   /* Explicit Task: RE_LvPowerSetup_1ms */
{
  uint8 tmpWrite;

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_LvPowerSetup_1ms' incorporates:
   *  SubSystem: '<Root>/RE_LvPowerSetup_1ms_sys'
   */
  /* CCaller: '<S1>/C Caller' incorporates:
   *  Outport: '<Root>/PP_SWC_LvPower_LvPower_stLowpowerUp'
   */
  LV_PowerSetup(&tmpWrite);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_LvPowerSetup_1ms' */

  /* Outport: '<Root>/PP_SWC_LvPower_LvPower_stLowpowerUp' */
  (void) Rte_Write_PP_SWC_LvPower_LvPower_stLowpowerUp(tmpWrite);
}

/* Model initialize function */
void SWC_LvPower_Init(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
