/*
 * File: SWC_Cpld.c
 *
 * Code generated for Simulink model 'SWC_Cpld'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Wed Nov 11 10:26:39 2020
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SWC_Cpld.h"
#include "SWC_Cpld_private.h"

/* Block signals (default storage) */
B_SWC_Cpld_T SWC_Cpld_B;

/* Model step function for TID1 */
void SWC_Cpld_Task_10ms(void)          /* Explicit Task: RE_Cpld_10ms */
{
  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_Cpld_10ms' incorporates:
   *  SubSystem: '<Root>/RE_Cpld_10ms_sys'
   */
  /* CCaller: '<S1>/C Caller' */
  Cpld_Com_Task(&SWC_Cpld_B.CCaller);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_Cpld_10ms' */

  /* Outport: '<Root>/PP_SWC_Cpld_Cpld_CpldSwVer' */
  (void) Rte_Write_PP_SWC_Cpld_Cpld_CpldSwVer(SWC_Cpld_B.CCaller.CpldVersion);

  /* Outport: '<Root>/PP_SWC_Cpld_Cpld_ProjectNum' */
  (void) Rte_Write_PP_SWC_Cpld_Cpld_ProjectNum(SWC_Cpld_B.CCaller.ProjectNum);

  /* Outport: '<Root>/PP_SWC_Cpld_Cpld_IgbtState' */
  (void) Rte_Write_PP_SWC_Cpld_Cpld_IgbtState(SWC_Cpld_B.CCaller.PwmDriveState);
}

/* Model initialize function */
void SWC_Cpld_Init(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
