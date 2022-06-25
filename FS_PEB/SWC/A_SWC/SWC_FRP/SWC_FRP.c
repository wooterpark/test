/*
 * File: SWC_FRP.c
 *
 * Code generated for Simulink model 'SWC_FRP'.
 *
 * Model version                  : 1.238
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Fri Jun 24 16:31:10 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SWC_FRP.h"
#include "SWC_FRP_private.h"

/* user code (top of source file) */
#include "set_get_data.h"

/* Exported block signals */
uint32 VAR_FRP_FaultInfo_u32;          /* '<S3>/Bitwise Operator' */
boolean VAR_FRP_FaultReact_b;          /* '<S4>/Switch5' */

/* Exported data definition */
#pragma section ".rodata.Calib_32"

/* Definition for custom storage class: iEDS_Parameter */
const volatile boolean CAL_FRP_18VHSVoltRngErrOutCtl_b = 1;
                     /* Referenced by: '<S4>/CAL_FRP_18VHSVoltRngErrOutCtl_b' */
const volatile boolean CAL_FRP_1V8CPLDVoltRngErrOutCtl_b = 1;
                   /* Referenced by: '<S4>/CAL_FRP_1V8CPLDVoltRngErrOutCtl_b' */
const volatile boolean CAL_FRP_3V3CPLDVoltRngErrOutCtl_b = 1;
                   /* Referenced by: '<S4>/CAL_FRP_3V3CPLDVoltRngErrOutCtl_b' */
const volatile boolean CAL_FRP_BMSVoltRngErrOutCtl_b = 1;
                       /* Referenced by: '<S4>/CAL_FRP_BMSVoltRngErrOutCtl_b' */
const volatile boolean CAL_FRP_CurrRngErrOutCtl_b = 1;
                          /* Referenced by: '<S4>/CAL_FRP_CurrRngErrOutCtl_b' */
const volatile boolean CAL_FRP_CurrSumErrOutCtl_b = 1;
                          /* Referenced by: '<S4>/CAL_FRP_CurrSumErrOutCtl_b' */
const volatile boolean CAL_FRP_FaultReactCtl_b = 1;
                             /* Referenced by: '<S4>/CAL_FRP_FaultReactCtl_b' */
const volatile boolean CAL_FRP_ModeReqRngErrOutCtl_b = 1;
                       /* Referenced by: '<S4>/CAL_FRP_ModeReqRngErrOutCtl_b' */
const volatile boolean CAL_FRP_NSetPRngErrOutCtl_b = 1;
                         /* Referenced by: '<S4>/CAL_FRP_NSetPRngErrOutCtl_b' */
const volatile boolean CAL_FRP_OffsetRngErrrOutCtl_b = 1;
                       /* Referenced by: '<S4>/CAL_FRP_OffsetRngErrrOutCtl_b' */
const volatile boolean CAL_FRP_RslvExciRngErrOutCtl_b = 1;
                      /* Referenced by: '<S4>/CAL_FRP_RslvExciRngErrOutCtl_b' */
const volatile boolean CAL_FRP_RslvRngErrOutCtl_b = 1;
                          /* Referenced by: '<S4>/CAL_FRP_RslvRngErrOutCtl_b' */
const volatile boolean CAL_FRP_RslvSensVolRngErrOutCtl_b = 1;
                   /* Referenced by: '<S4>/CAL_FRP_RslvSensVolRngErrOutCtl_b' */
const volatile boolean CAL_FRP_RslvSqrtErrOutCtl_b = 1;
                         /* Referenced by: '<S4>/CAL_FRP_RslvSqrtErrOutCtl_b' */
const volatile boolean CAL_FRP_TrqCalcErrOutCtl_b = 1;
                          /* Referenced by: '<S4>/CAL_FRP_TrqCalcErrOutCtl_b' */
const volatile boolean CAL_FRP_TrqSetPRngErrOutCtl_b = 1;
                       /* Referenced by: '<S4>/CAL_FRP_TrqSetPRngErrOutCtl_b' */
const volatile boolean CAL_FRP_UBRVoltRngErrOutCtl_b = 1;
                       /* Referenced by: '<S4>/CAL_FRP_UBRVoltRngErrOutCtl_b' */
const volatile boolean CAL_FRP_UintndSpdErrOutCtl_b = 1;
                        /* Referenced by: '<S4>/CAL_FRP_UintndSpdErrOutCtl_b' */
const volatile boolean CAL_FRP_UintndTrqErrOutCtl_b = 1;
                        /* Referenced by: '<S4>/CAL_FRP_UintndTrqErrOutCtl_b' */
const volatile boolean CAL_FRP_VoltCmpChkErrOutCtl_b = 1;
                       /* Referenced by: '<S4>/CAL_FRP_VoltCmpChkErrOutCtl_b' */
const volatile boolean CAL_FRP_iPhasSensVolRngErrOutCtl_b = 1;
                  /* Referenced by: '<S4>/CAL_FRP_iPhasSensVolRngErrOutCtl_b' */

#pragma section

/* Real-time model */
RT_MODEL_SWC_FRP_T SWC_FRP_M_;
RT_MODEL_SWC_FRP_T *const SWC_FRP_M = &SWC_FRP_M_;

/* Output and update for atomic system: '<S1>/FaultInfoGen' */
void SWC_FRP_FaultInfoGen(void)
{
  /* Outputs for Atomic SubSystem: '<S3>/Bit Shift1' */
  /* Outputs for Atomic SubSystem: '<S3>/Bit Shift2' */
  /* Outputs for Atomic SubSystem: '<S3>/Bit Shift3' */
  /* Outputs for Atomic SubSystem: '<S3>/Bit Shift4' */
  /* Outputs for Atomic SubSystem: '<S3>/Bit Shift5' */
  /* Outputs for Atomic SubSystem: '<S3>/Bit Shift6' */
  /* Outputs for Atomic SubSystem: '<S3>/Bit Shift7' */
  /* Outputs for Atomic SubSystem: '<S3>/Bit Shift8' */
  /* Outputs for Atomic SubSystem: '<S3>/Bit Shift9' */
  /* Outputs for Atomic SubSystem: '<S3>/Bit Shift10' */
  /* Outputs for Atomic SubSystem: '<S3>/Bit Shift11' */
  /* Outputs for Atomic SubSystem: '<S3>/Bit Shift12' */
  /* Outputs for Atomic SubSystem: '<S3>/Bit Shift13' */
  /* Outputs for Atomic SubSystem: '<S3>/Bit Shift14' */
  /* Outputs for Atomic SubSystem: '<S3>/Bit Shift15' */
  /* Outputs for Atomic SubSystem: '<S3>/Bit Shift16' */
  /* Outputs for Atomic SubSystem: '<S3>/Bit Shift17' */
  /* Outputs for Atomic SubSystem: '<S3>/Bit Shift18' */
  /* Outputs for Atomic SubSystem: '<S3>/Bit Shift19' */
  /* Outputs for Atomic SubSystem: '<S3>/Bit Shift20' */
  /* S-Function (sfix_bitop): '<S3>/Bitwise Operator' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   *  DataTypeConversion: '<S3>/Data Type Conversion1'
   *  DataTypeConversion: '<S3>/Data Type Conversion10'
   *  DataTypeConversion: '<S3>/Data Type Conversion11'
   *  DataTypeConversion: '<S3>/Data Type Conversion12'
   *  DataTypeConversion: '<S3>/Data Type Conversion13'
   *  DataTypeConversion: '<S3>/Data Type Conversion14'
   *  DataTypeConversion: '<S3>/Data Type Conversion15'
   *  DataTypeConversion: '<S3>/Data Type Conversion16'
   *  DataTypeConversion: '<S3>/Data Type Conversion17'
   *  DataTypeConversion: '<S3>/Data Type Conversion18'
   *  DataTypeConversion: '<S3>/Data Type Conversion19'
   *  DataTypeConversion: '<S3>/Data Type Conversion2'
   *  DataTypeConversion: '<S3>/Data Type Conversion20'
   *  DataTypeConversion: '<S3>/Data Type Conversion3'
   *  DataTypeConversion: '<S3>/Data Type Conversion4'
   *  DataTypeConversion: '<S3>/Data Type Conversion5'
   *  DataTypeConversion: '<S3>/Data Type Conversion6'
   *  DataTypeConversion: '<S3>/Data Type Conversion7'
   *  DataTypeConversion: '<S3>/Data Type Conversion8'
   *  DataTypeConversion: '<S3>/Data Type Conversion9'
   *  Inport: '<Root>/ADM_BMSVoltRngErr'
   *  Inport: '<Root>/ADM_GlbDchgErr'
   *  Inport: '<Root>/ADM_VoltCmpChkErr'
   *  Inport: '<Root>/STM_UintndSpdErr'
   *  Inport: '<Root>/STM_UintndTrqErr'
   *  Inport: '<Root>/TCF_TrqCalcErr'
   *  Inport: '<Root>/TRSP_18VHSVoltRngErr'
   *  Inport: '<Root>/TRSP_1V8CPLDVoltRngErr'
   *  Inport: '<Root>/TRSP_3V3CPLDVoltRngErr'
   *  Inport: '<Root>/TRSP_CurrRngErr'
   *  Inport: '<Root>/TRSP_CurrSumErr'
   *  Inport: '<Root>/TRSP_ModeReqRngErr'
   *  Inport: '<Root>/TRSP_NSetPRngErr'
   *  Inport: '<Root>/TRSP_OffsetRngErr'
   *  Inport: '<Root>/TRSP_RslvExciRngErr'
   *  Inport: '<Root>/TRSP_RslvRngErr'
   *  Inport: '<Root>/TRSP_RslvSensVolRngErr'
   *  Inport: '<Root>/TRSP_RslvSqrtErr'
   *  Inport: '<Root>/TRSP_TrqSetPRngErr'
   *  Inport: '<Root>/TRSP_UBRVoltRngErr'
   *  Inport: '<Root>/TRSP_iPhasSensVolRngErr'
   *  MATLAB Function: '<S10>/bit_shift'
   *  MATLAB Function: '<S11>/bit_shift'
   *  MATLAB Function: '<S12>/bit_shift'
   *  MATLAB Function: '<S13>/bit_shift'
   *  MATLAB Function: '<S14>/bit_shift'
   *  MATLAB Function: '<S15>/bit_shift'
   *  MATLAB Function: '<S16>/bit_shift'
   *  MATLAB Function: '<S17>/bit_shift'
   *  MATLAB Function: '<S18>/bit_shift'
   *  MATLAB Function: '<S28>/bit_shift'
   *  MATLAB Function: '<S31>/bit_shift'
   *  MATLAB Function: '<S32>/bit_shift'
   *  MATLAB Function: '<S33>/bit_shift'
   *  MATLAB Function: '<S34>/bit_shift'
   *  MATLAB Function: '<S35>/bit_shift'
   *  MATLAB Function: '<S36>/bit_shift'
   *  MATLAB Function: '<S6>/bit_shift'
   *  MATLAB Function: '<S7>/bit_shift'
   *  MATLAB Function: '<S8>/bit_shift'
   *  MATLAB Function: '<S9>/bit_shift'
   */
  VAR_FRP_FaultInfo_u32 = (uint32)get_STM_UintndSpdErr() << 1 |
    get_STM_UintndTrqErr() | (uint32)get_TCF_TrqCalcErr() << 2 | (uint32)
    get_TRSP_iPhasSensVolRngErr() << 3 | (uint32)get_TRSP_RslvSensVolRngErr() <<
    4 | (uint32)get_TRSP_RslvExciRngErr() << 5 | (uint32)get_TRSP_RslvSqrtErr() <<
    6 | (uint32)get_TRSP_RslvRngErr() << 7 | (uint32)get_TRSP_CurrSumErr() << 8 |
    (uint32)get_TRSP_CurrRngErr() << 9 | (uint32)get_TRSP_TrqSetPRngErr() << 10 |
    (uint32)get_TRSP_NSetPRngErr() << 11 | (uint32)get_TRSP_ModeReqRngErr() <<
    12 | (uint32)get_TRSP_OffsetRngErr() << 13 | (uint32)get_ADM_BMSVoltRngErr()
    << 14 | (uint32)get_ADM_VoltCmpChkErr() << 15 | (uint32)get_ADM_GlbDchgErr()
    << 16 | (uint32)get_TRSP_UBRVoltRngErr() << 17 | (uint32)
    get_TRSP_18VHSVoltRngErr() << 18 | (uint32)get_TRSP_3V3CPLDVoltRngErr() <<
    19 | (uint32)get_TRSP_1V8CPLDVoltRngErr() << 20;

  /* End of Outputs for SubSystem: '<S3>/Bit Shift20' */
  /* End of Outputs for SubSystem: '<S3>/Bit Shift19' */
  /* End of Outputs for SubSystem: '<S3>/Bit Shift18' */
  /* End of Outputs for SubSystem: '<S3>/Bit Shift17' */
  /* End of Outputs for SubSystem: '<S3>/Bit Shift16' */
  /* End of Outputs for SubSystem: '<S3>/Bit Shift15' */
  /* End of Outputs for SubSystem: '<S3>/Bit Shift14' */
  /* End of Outputs for SubSystem: '<S3>/Bit Shift13' */
  /* End of Outputs for SubSystem: '<S3>/Bit Shift12' */
  /* End of Outputs for SubSystem: '<S3>/Bit Shift11' */
  /* End of Outputs for SubSystem: '<S3>/Bit Shift10' */
  /* End of Outputs for SubSystem: '<S3>/Bit Shift9' */
  /* End of Outputs for SubSystem: '<S3>/Bit Shift8' */
  /* End of Outputs for SubSystem: '<S3>/Bit Shift7' */
  /* End of Outputs for SubSystem: '<S3>/Bit Shift6' */
  /* End of Outputs for SubSystem: '<S3>/Bit Shift5' */
  /* End of Outputs for SubSystem: '<S3>/Bit Shift4' */
  /* End of Outputs for SubSystem: '<S3>/Bit Shift3' */
  /* End of Outputs for SubSystem: '<S3>/Bit Shift2' */
  /* End of Outputs for SubSystem: '<S3>/Bit Shift1' */

  /* SignalConversion: '<S3>/Signal Conversion' */
  set_FRP_L2FaultinfoOut(VAR_FRP_FaultInfo_u32);
}

/* Output and update for atomic system: '<S1>/FaultReactGen' */
void SWC_FRP_FaultReactGen(void)
{
  /* Switch: '<S4>/Switch5' incorporates:
   *  Constant: '<S4>/CAL_FRP_18VHSVoltRngErrOutCtl_b'
   *  Constant: '<S4>/CAL_FRP_1V8CPLDVoltRngErrOutCtl_b'
   *  Constant: '<S4>/CAL_FRP_3V3CPLDVoltRngErrOutCtl_b'
   *  Constant: '<S4>/CAL_FRP_BMSVoltRngErrOutCtl_b'
   *  Constant: '<S4>/CAL_FRP_CurrRngErrOutCtl_b'
   *  Constant: '<S4>/CAL_FRP_CurrSumErrOutCtl_b'
   *  Constant: '<S4>/CAL_FRP_FaultReactCtl_b'
   *  Constant: '<S4>/CAL_FRP_ModeReqRngErrOutCtl_b'
   *  Constant: '<S4>/CAL_FRP_NSetPRngErrOutCtl_b'
   *  Constant: '<S4>/CAL_FRP_OffsetRngErrrOutCtl_b'
   *  Constant: '<S4>/CAL_FRP_RslvExciRngErrOutCtl_b'
   *  Constant: '<S4>/CAL_FRP_RslvRngErrOutCtl_b'
   *  Constant: '<S4>/CAL_FRP_RslvSensVolRngErrOutCtl_b'
   *  Constant: '<S4>/CAL_FRP_RslvSqrtErrOutCtl_b'
   *  Constant: '<S4>/CAL_FRP_TrqCalcErrOutCtl_b'
   *  Constant: '<S4>/CAL_FRP_TrqSetPRngErrOutCtl_b'
   *  Constant: '<S4>/CAL_FRP_UBRVoltRngErrOutCtl_b'
   *  Constant: '<S4>/CAL_FRP_UintndSpdErrOutCtl_b'
   *  Constant: '<S4>/CAL_FRP_UintndTrqErrOutCtl_b'
   *  Constant: '<S4>/CAL_FRP_VoltCmpChkErrOutCtl_b'
   *  Constant: '<S4>/CAL_FRP_iPhasSensVolRngErrOutCtl_b'
   *  Constant: '<S4>/Constant8'
   *  Inport: '<Root>/ADM_BMSVoltRngErr'
   *  Inport: '<Root>/ADM_VoltCmpChkErr'
   *  Inport: '<Root>/STM_UintndSpdErr'
   *  Inport: '<Root>/STM_UintndTrqErr'
   *  Inport: '<Root>/TCF_TrqCalcErr'
   *  Inport: '<Root>/TRSP_18VHSVoltRngErr'
   *  Inport: '<Root>/TRSP_1V8CPLDVoltRngErr'
   *  Inport: '<Root>/TRSP_3V3CPLDVoltRngErr'
   *  Inport: '<Root>/TRSP_CurrRngErr'
   *  Inport: '<Root>/TRSP_CurrSumErr'
   *  Inport: '<Root>/TRSP_ModeReqRngErr'
   *  Inport: '<Root>/TRSP_NSetPRngErr'
   *  Inport: '<Root>/TRSP_OffsetRngErr'
   *  Inport: '<Root>/TRSP_RslvExciRngErr'
   *  Inport: '<Root>/TRSP_RslvRngErr'
   *  Inport: '<Root>/TRSP_RslvSensVolRngErr'
   *  Inport: '<Root>/TRSP_RslvSqrtErr'
   *  Inport: '<Root>/TRSP_TrqSetPRngErr'
   *  Inport: '<Root>/TRSP_UBRVoltRngErr'
   *  Inport: '<Root>/TRSP_iPhasSensVolRngErr'
   *  Logic: '<S4>/Logical Operator3'
   *  Switch: '<S4>/Switch1'
   *  Switch: '<S4>/Switch10'
   *  Switch: '<S4>/Switch11'
   *  Switch: '<S4>/Switch12'
   *  Switch: '<S4>/Switch13'
   *  Switch: '<S4>/Switch14'
   *  Switch: '<S4>/Switch15'
   *  Switch: '<S4>/Switch16'
   *  Switch: '<S4>/Switch17'
   *  Switch: '<S4>/Switch18'
   *  Switch: '<S4>/Switch19'
   *  Switch: '<S4>/Switch2'
   *  Switch: '<S4>/Switch20'
   *  Switch: '<S4>/Switch21'
   *  Switch: '<S4>/Switch3'
   *  Switch: '<S4>/Switch4'
   *  Switch: '<S4>/Switch6'
   *  Switch: '<S4>/Switch7'
   *  Switch: '<S4>/Switch8'
   *  Switch: '<S4>/Switch9'
   */
  if (CAL_FRP_FaultReactCtl_b) {
    VAR_FRP_FaultReact_b = ((CAL_FRP_VoltCmpChkErrOutCtl_b &&
      get_ADM_VoltCmpChkErr()) || (CAL_FRP_BMSVoltRngErrOutCtl_b &&
      get_ADM_BMSVoltRngErr()) || (CAL_FRP_OffsetRngErrrOutCtl_b &&
      get_TRSP_OffsetRngErr()) || (CAL_FRP_ModeReqRngErrOutCtl_b &&
      get_TRSP_ModeReqRngErr()) || (CAL_FRP_NSetPRngErrOutCtl_b &&
      get_TRSP_NSetPRngErr()) || (CAL_FRP_TrqSetPRngErrOutCtl_b &&
      get_TRSP_TrqSetPRngErr()) || (CAL_FRP_CurrRngErrOutCtl_b &&
      get_TRSP_CurrRngErr()) || (CAL_FRP_CurrSumErrOutCtl_b &&
      get_TRSP_CurrSumErr()) || (CAL_FRP_RslvRngErrOutCtl_b &&
      get_TRSP_RslvRngErr()) || (CAL_FRP_RslvSqrtErrOutCtl_b &&
      get_TRSP_RslvSqrtErr()) || (CAL_FRP_RslvExciRngErrOutCtl_b &&
      get_TRSP_RslvExciRngErr()) || (CAL_FRP_RslvSensVolRngErrOutCtl_b &&
      get_TRSP_RslvSensVolRngErr()) || (CAL_FRP_iPhasSensVolRngErrOutCtl_b &&
      get_TRSP_iPhasSensVolRngErr()) || (CAL_FRP_TrqCalcErrOutCtl_b &&
      get_TCF_TrqCalcErr()) || (CAL_FRP_UintndSpdErrOutCtl_b &&
      get_STM_UintndSpdErr()) || (CAL_FRP_UintndTrqErrOutCtl_b &&
      get_STM_UintndTrqErr()) || (CAL_FRP_UBRVoltRngErrOutCtl_b &&
      get_TRSP_UBRVoltRngErr()) || (CAL_FRP_18VHSVoltRngErrOutCtl_b &&
      get_TRSP_18VHSVoltRngErr()) || (CAL_FRP_3V3CPLDVoltRngErrOutCtl_b &&
      get_TRSP_3V3CPLDVoltRngErr()) || (CAL_FRP_1V8CPLDVoltRngErrOutCtl_b &&
      get_TRSP_1V8CPLDVoltRngErr()));
  } else {
    VAR_FRP_FaultReact_b = false;
  }

  /* End of Switch: '<S4>/Switch5' */

  /* SignalConversion: '<S4>/Signal Conversion' */
  set_FRP_L2FaultReact(VAR_FRP_FaultReact_b);
}

/* Model step function for TID1 */
void SWC_FRP_1ms(void)                 /* Explicit Task: SWC_FRP_1ms */
{
  /* RootInportFunctionCallGenerator generated from: '<Root>/SWC_FRP_1ms' incorporates:
   *  SubSystem: '<Root>/SWC_FRM_1ms_sys'
   */
  /* Outputs for Atomic SubSystem: '<S1>/FaultInfoGen' */
  SWC_FRP_FaultInfoGen();

  /* End of Outputs for SubSystem: '<S1>/FaultInfoGen' */

  /* Outputs for Atomic SubSystem: '<S1>/FaultReactGen' */
  SWC_FRP_FaultReactGen();

  /* End of Outputs for SubSystem: '<S1>/FaultReactGen' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/SWC_FRP_1ms' */
}

/* Model initialize function */
void SWC_FRP_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void SWC_FRP_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
