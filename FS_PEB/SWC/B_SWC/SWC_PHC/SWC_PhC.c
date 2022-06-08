/*
 * File: SWC_PhC.c
 *
 * Code generated for Simulink model 'SWC_PhC'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Sun Jun 28 13:59:20 2020
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SWC_PhC.h"
#include "SWC_PhC_private.h"

/* Block signals (default storage) */
B_SWC_PhC_T SWC_PhC_B;

/* Model step function for TID1 */
void SWC_PhC_GetResult_MCUHwAdc_Task_100us(void)
                               /* Explicit Task: RE_PhC_GetResult_MCUHw_100us */
{
  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_PhC_GetResult_MCUHw_100us' incorporates:
   *  SubSystem: '<Root>/RE_PhC_GetResult_MCUHw_100us_sys'
   */
  /* CCaller: '<S2>/C Caller' */
  PhC_GetResult_MCUHwAdc(&SWC_PhC_B.CCaller);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_PhC_GetResult_MCUHw_100us' */

  /* Outport: '<Root>/PP_SWC_PhC_PhC_iUNoOff' */
  (void) Rte_Write_PP_SWC_PhC_PhC_iUNoOff(SWC_PhC_B.CCaller.iUNoOff);

  /* Outport: '<Root>/PP_SWC_PhC_PhC_iVNoOff' */
  (void) Rte_Write_PP_SWC_PhC_PhC_iVNoOff(SWC_PhC_B.CCaller.iVNoOff);

  /* Outport: '<Root>/PP_SWC_PhC_PhC_iWNoOff' */
  (void) Rte_Write_PP_SWC_PhC_PhC_iWNoOff(SWC_PhC_B.CCaller.iWNoOff);

  /* Outport: '<Root>/PP_SWC_PhC_PhC_uDcLnkLowMcu' */
  (void) Rte_Write_PP_SWC_PhC_PhC_uDcLnkLowMcu(SWC_PhC_B.CCaller.uDcLnkLowMcu);
}

/* Model step function for TID2 */
void SWC_PhC_FaultHand_Task_2ms(void)  /* Explicit Task: RE_PhC_FaultHand_2ms */
{
  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_PhC_FaultHand_2ms' incorporates:
   *  SubSystem: '<Root>/RE_PhC_FaultHand_2ms_sys'
   */
  /* CCaller: '<S1>/C Caller' */
  PhC_FaultHand();

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_PhC_FaultHand_2ms' */
}

/* Model initialize function */
void SWC_PhC_Init(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
