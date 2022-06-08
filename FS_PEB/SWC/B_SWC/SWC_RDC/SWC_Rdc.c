/*
 * File: SWC_Rdc.c
 *
 * Code generated for Simulink model 'SWC_Rdc'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Sun Jun 28 14:42:12 2020
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SWC_Rdc.h"
#include "SWC_Rdc_private.h"

/* Block signals (default storage) */
B_SWC_Rdc_T SWC_Rdc_B;

/* Model step function for TID1 */
void SWC_Rdc_AngleHandle_Task_100us(void)
                                   /* Explicit Task: RE_Rdc_AngLeHandle_100us */
{
  float32 tmpRead;

  /* Inport: '<Root>/PP_SWC_MCF_MCF_cofFrqPwm' */
  Rte_Read_PP_SWC_MCF_MCF_cofFrqPwm(&tmpRead);

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_Rdc_AngLeHandle_100us' incorporates:
   *  SubSystem: '<Root>/RE_Rdc_AngLeHandle_100us_sys'
   */
  /* CCaller: '<S1>/C Caller' */
  Rdc_AngleHandle(&tmpRead, &SWC_Rdc_B.CCaller);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_Rdc_AngLeHandle_100us' */

  /* Outport: '<Root>/PP_SWC_Rdc_Rdc_ArctanAgRtr' */
  (void) Rte_Write_PP_SWC_Rdc_Rdc_ArctanAgRtr(SWC_Rdc_B.CCaller.ArctanAgRtr_f32);

  /* Outport: '<Root>/PP_SWC_Rdc_Rdc_nWoFlt' */
  (void) Rte_Write_PP_SWC_Rdc_Rdc_nWoFlt(SWC_Rdc_B.CCaller.nWoFlt_f32);
}

/* Model step function for TID2 */
void SWC_Rdc_Res_Task_102us(void)      /* Explicit Task: RE_Rdc_Res_102us */
{
  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_Rdc_Res_102us' incorporates:
   *  SubSystem: '<Root>/RE_Rdc_Res_102us_sys'
   */
  /* CCaller: '<S3>/C Caller' */
  Rdc_Res_Isr();

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_Rdc_Res_102us' */
}

/* Model step function for TID3 */
void SWC_Rdc_FaultHandleMainFunction_Task_2ms(void)
                         /* Explicit Task: RE_Rdc_FaultHandleMainFunction_2ms */
{
  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_Rdc_FaultHandleMainFunction_2ms' incorporates:
   *  SubSystem: '<Root>/RE_Rdc_FaultHandleMainFunction_2ms_sys'
   */
  /* CCaller: '<S2>/C Caller' */
  Rdc_FaultHandleMainFunction();

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_Rdc_FaultHandleMainFunction_2ms' */
}

/* Model initialize function */
void SWC_Rdc_Init(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
