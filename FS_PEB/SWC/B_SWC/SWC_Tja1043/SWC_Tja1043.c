/*
 * File: SWC_Tja1043.c
 *
 * Code generated for Simulink model 'SWC_Tja1043'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Wed Jul  1 11:28:20 2020
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SWC_Tja1043.h"
#include "SWC_Tja1043_private.h"

/* Model step function for TID1 */
void SWC_CanTrcv_Task_2ms(void)        /* Explicit Task: RE_CanTrcv_2ms */
{
  CanTrcv_OutPut_S rtb_CCaller;

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_CanTrcv_2ms' incorporates:
   *  SubSystem: '<Root>/RE_CanTrcv_2ms_sys'
   */
  /* CCaller: '<S1>/C Caller' */
  CanTrcv_Set(&rtb_CCaller);

  /* Outport: '<Root>/PP_SWC_Tja1043_Tja1043_flgCAN_WakeUp' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion'
   */
  (void) Rte_Write_PP_SWC_Tja1043_Tja1043_flgCAN_WakeUp(rtb_CCaller.WakeupSorce
    != 0);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_CanTrcv_2ms' */
}

/* Model initialize function */
void SWC_Tja1043_Init(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
