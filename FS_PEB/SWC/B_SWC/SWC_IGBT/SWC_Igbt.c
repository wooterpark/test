/*
 * File: SWC_Igbt.c
 *
 * Code generated for Simulink model 'SWC_Igbt'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Sun Jun 28 17:43:43 2020
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SWC_Igbt.h"
#include "SWC_Igbt_private.h"

/* Model step function for TID1 */
void SWC_StateManagement_Taks_1ms(void)
                                /* Explicit Task: RE_Igbt_StateManagement_1ms */
{
  IgbtDrvRdyOutIFType rtb_CCaller;

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_Igbt_StateManagement_1ms' incorporates:
   *  SubSystem: '<Root>/RE_Igbt_StateManagement_1ms_sys'
   */
  /* CCaller: '<S2>/C Caller' */
  IgbtDrv_StateManagement(&rtb_CCaller);

  /* Outport: '<Root>/PP_SWC_Igbt_Igbt_flgGateDrvRdyHs' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion'
   */
  (void) Rte_Write_PP_SWC_Igbt_Igbt_flgGateDrvRdyHs
    (rtb_CCaller.flgGateDrvRdyHs_u8 != 0);

  /* Outport: '<Root>/PP_SWC_Igbt_Igbt_flgGateDrvRdyLs' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion1'
   */
  (void) Rte_Write_PP_SWC_Igbt_Igbt_flgGateDrvRdyLs
    (rtb_CCaller.flgGateDrvRdyLs_u8 != 0);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_Igbt_StateManagement_1ms' */
}

/* Model step function for TID2 */
void SWC_Igbt_Mainfunction_Task_10ms(void)
                                  /* Explicit Task: RE_Igbt_Mainfunction_10ms */
{
  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_Igbt_Mainfunction_10ms' incorporates:
   *  SubSystem: '<Root>/RE_Igbt_Mainfunction_10ms_sys'
   */
  /* CCaller: '<S1>/C Caller' */
//  IgbtDrv_10ms_MainFunction();

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_Igbt_Mainfunction_10ms' */
}

/* Model initialize function */
void SWC_Igbt_Init(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
