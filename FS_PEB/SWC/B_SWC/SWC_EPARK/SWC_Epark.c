/*
 * File: SWC_Epark.c
 *
 * Code generated for Simulink model 'SWC_Epark'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Sun Jun 28 13:27:34 2020
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SWC_Epark.h"
#include "SWC_Epark_private.h"

/* Block signals (default storage) */
B_SWC_Epark_T SWC_Epark_B;

/* Model step function for TID1 */
void SWC_Epark_10ms(void)              /* Explicit Task: RE_Epark_10ms */
{
  boolean tmpRead;
  float32 tmpRead_0;
  EparkInIFType rtb_BusConversion_InsertedFor_C;

  /* Inport: '<Root>/RP_SWC_PCF_PCF_dycPWM' */
  Rte_Read_RP_SWC_PCF_PCF_dycPWM(&tmpRead_0);

  /* Inport: '<Root>/RP_SWC_PCF_PCF_MotDir' */
  Rte_Read_RP_SWC_PCF_PCF_MotDir(&tmpRead);

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_Epark_10ms' incorporates:
   *  SubSystem: '<Root>/RE_Epark_10ms_sys'
   */
  /* BusCreator generated from: '<S1>/C Caller' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion1'
   */
  rtb_BusConversion_InsertedFor_C.Epark_Con_Duty_f32 = tmpRead_0;
  rtb_BusConversion_InsertedFor_C.Epark_Direction_b = tmpRead;

  /* CCaller: '<S1>/C Caller' */
  Epark_SetOutput(&rtb_BusConversion_InsertedFor_C, &SWC_Epark_B.CCaller);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_Epark_10ms' */

  /* Outport: '<Root>/PP_SWC_Epark_Epark_iPcf' */
  (void) Rte_Write_PP_SWC_Epark_Epark_iPcf(SWC_Epark_B.CCaller.iEpc);

  /* Outport: '<Root>/PP_SWC_Epark_Epark_posPcf' */
  (void) Rte_Write_PP_SWC_Epark_Epark_posPcf(SWC_Epark_B.CCaller.posEpc);

  /* Outport: '<Root>/PP_SWC_Epark_Epark_posPcfMon' */
  (void) Rte_Write_PP_SWC_Epark_Epark_posPcfMon(SWC_Epark_B.CCaller.posEpcMon);
}

/* Model initialize function */
void SWC_Epark_Init(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
