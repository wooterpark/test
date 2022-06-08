/*
 * File: SWC_Pwm3ph.c
 *
 * Code generated for Simulink model 'SWC_Pwm3ph'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Sun Jun 28 14:20:21 2020
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SWC_Pwm3ph.h"
#include "SWC_Pwm3ph_private.h"

/* Model step function for TID1 */
void SWC_Pwm3ph_Setoutput_Task_100us(void)
                                  /* Explicit Task: RE_Pwm3ph_Setoutput_100us */
{
  float32 tmpRead;
  float32 tmpRead_0;
  float32 tmpRead_1;
  float32 tmpRead_2;
  uint8 tmpRead_3;
  Pwm3phInIFType rtb_BusConversion_InsertedFor_C;

  /* Inport: '<Root>/RP_SWC_MCF_MCF_stPwmMode' */
  Rte_Read_RP_SWC_MCF_MCF_stPwmMode(&tmpRead_3);

  /* Inport: '<Root>/RP_SWC_MCF_MCF_frqPwm' */
  Rte_Read_RP_SWC_MCF_MCF_frqPwm(&tmpRead_2);

  /* Inport: '<Root>/RP_SWC_MCF_MCF_DycW' */
  Rte_Read_RP_SWC_MCF_MCF_DycW(&tmpRead_1);

  /* Inport: '<Root>/RP_SWC_MCF_MCF_DycV' */
  Rte_Read_RP_SWC_MCF_MCF_DycV(&tmpRead_0);

  /* Inport: '<Root>/RP_SWC_MCF_MCF_DycU' */
  Rte_Read_RP_SWC_MCF_MCF_DycU(&tmpRead);

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_Pwm3ph_Setoutput_100us' incorporates:
   *  SubSystem: '<Root>/RE_Pwm3ph_Setoutput_100us_sys'
   */
  /* BusCreator generated from: '<S1>/C Caller' */
  rtb_BusConversion_InsertedFor_C.PwmDutyCyclePhaseU1_f32 = tmpRead;
  rtb_BusConversion_InsertedFor_C.PwmDutyCyclePhaseV1_f32 = tmpRead_0;
  rtb_BusConversion_InsertedFor_C.PwmDutyCyclePhaseW1_f32 = tmpRead_1;

  /* DataTypeConversion: '<S1>/Data Type Conversion' */
  tmpRead_2 = fmodf(floorf(tmpRead_2), 65536.0F);

  /* BusCreator generated from: '<S1>/C Caller' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion'
   */
  rtb_BusConversion_InsertedFor_C.Pwm_Freq_u16 = (uint16)(tmpRead_2 < 0.0F ?
    (sint32)(uint16)-(sint16)(uint16)-tmpRead_2 : (sint32)(uint16)tmpRead_2);
  rtb_BusConversion_InsertedFor_C.Pwm_Mode_u8 = tmpRead_3;

  /* CCaller: '<S1>/C Caller' */
  Pwm3ph_SetOutput(&rtb_BusConversion_InsertedFor_C);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_Pwm3ph_Setoutput_100us' */
}

/* Model initialize function */
void SWC_Pwm3ph_Init(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
