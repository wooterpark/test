/*
 * File: SWC_FRP.h
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

#ifndef RTW_HEADER_SWC_FRP_h_
#define RTW_HEADER_SWC_FRP_h_
#ifndef SWC_FRP_COMMON_INCLUDES_
# define SWC_FRP_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* SWC_FRP_COMMON_INCLUDES_ */

#include "SWC_FRP_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Real-time Model Data Structure */
struct tag_RTM_SWC_FRP_T {
  const char_T *errorStatus;
};

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern uint32 VAR_FRP_FaultInfo_u32;   /* '<S3>/Bitwise Operator' */
extern boolean VAR_FRP_FaultReact_b;   /* '<S4>/Switch5' */

/* Model entry point functions */
extern void SWC_FRP_initialize(void);
extern void SWC_FRP_terminate(void);

/* Exported entry point function */
extern void SWC_FRP_1ms(void);

/* Exported data declaration */
#pragma section ".rodata.Calib_32"

/* Declaration for custom storage class: iEDS_Parameter */
extern const volatile boolean CAL_FRP_18VHSVoltRngErrOutCtl_b;
                     /* Referenced by: '<S4>/CAL_FRP_18VHSVoltRngErrOutCtl_b' */
extern const volatile boolean CAL_FRP_1V8CPLDVoltRngErrOutCtl_b;
                   /* Referenced by: '<S4>/CAL_FRP_1V8CPLDVoltRngErrOutCtl_b' */
extern const volatile boolean CAL_FRP_3V3CPLDVoltRngErrOutCtl_b;
                   /* Referenced by: '<S4>/CAL_FRP_3V3CPLDVoltRngErrOutCtl_b' */
extern const volatile boolean CAL_FRP_BMSVoltRngErrOutCtl_b;
                       /* Referenced by: '<S4>/CAL_FRP_BMSVoltRngErrOutCtl_b' */
extern const volatile boolean CAL_FRP_CurrRngErrOutCtl_b;
                          /* Referenced by: '<S4>/CAL_FRP_CurrRngErrOutCtl_b' */
extern const volatile boolean CAL_FRP_CurrSumErrOutCtl_b;
                          /* Referenced by: '<S4>/CAL_FRP_CurrSumErrOutCtl_b' */
extern const volatile boolean CAL_FRP_FaultReactCtl_b;
                             /* Referenced by: '<S4>/CAL_FRP_FaultReactCtl_b' */
extern const volatile boolean CAL_FRP_ModeReqRngErrOutCtl_b;
                       /* Referenced by: '<S4>/CAL_FRP_ModeReqRngErrOutCtl_b' */
extern const volatile boolean CAL_FRP_NSetPRngErrOutCtl_b;
                         /* Referenced by: '<S4>/CAL_FRP_NSetPRngErrOutCtl_b' */
extern const volatile boolean CAL_FRP_OffsetRngErrrOutCtl_b;
                       /* Referenced by: '<S4>/CAL_FRP_OffsetRngErrrOutCtl_b' */
extern const volatile boolean CAL_FRP_RslvExciRngErrOutCtl_b;
                      /* Referenced by: '<S4>/CAL_FRP_RslvExciRngErrOutCtl_b' */
extern const volatile boolean CAL_FRP_RslvRngErrOutCtl_b;
                          /* Referenced by: '<S4>/CAL_FRP_RslvRngErrOutCtl_b' */
extern const volatile boolean CAL_FRP_RslvSensVolRngErrOutCtl_b;
                   /* Referenced by: '<S4>/CAL_FRP_RslvSensVolRngErrOutCtl_b' */
extern const volatile boolean CAL_FRP_RslvSqrtErrOutCtl_b;
                         /* Referenced by: '<S4>/CAL_FRP_RslvSqrtErrOutCtl_b' */
extern const volatile boolean CAL_FRP_TrqCalcErrOutCtl_b;
                          /* Referenced by: '<S4>/CAL_FRP_TrqCalcErrOutCtl_b' */
extern const volatile boolean CAL_FRP_TrqSetPRngErrOutCtl_b;
                       /* Referenced by: '<S4>/CAL_FRP_TrqSetPRngErrOutCtl_b' */
extern const volatile boolean CAL_FRP_UBRVoltRngErrOutCtl_b;
                       /* Referenced by: '<S4>/CAL_FRP_UBRVoltRngErrOutCtl_b' */
extern const volatile boolean CAL_FRP_UintndSpdErrOutCtl_b;
                        /* Referenced by: '<S4>/CAL_FRP_UintndSpdErrOutCtl_b' */
extern const volatile boolean CAL_FRP_UintndTrqErrOutCtl_b;
                        /* Referenced by: '<S4>/CAL_FRP_UintndTrqErrOutCtl_b' */
extern const volatile boolean CAL_FRP_VoltCmpChkErrOutCtl_b;
                       /* Referenced by: '<S4>/CAL_FRP_VoltCmpChkErrOutCtl_b' */
extern const volatile boolean CAL_FRP_iPhasSensVolRngErrOutCtl_b;
                  /* Referenced by: '<S4>/CAL_FRP_iPhasSensVolRngErrOutCtl_b' */

#pragma section

/* Real-time Model object */
extern RT_MODEL_SWC_FRP_T *const SWC_FRP_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'SWC_FRP'
 * '<S1>'   : 'SWC_FRP/SWC_FRM_1ms_sys'
 * '<S2>'   : 'SWC_FRP/SWC_FRP_Init'
 * '<S3>'   : 'SWC_FRP/SWC_FRM_1ms_sys/FaultInfoGen'
 * '<S4>'   : 'SWC_FRP/SWC_FRM_1ms_sys/FaultReactGen'
 * '<S5>'   : 'SWC_FRP/SWC_FRM_1ms_sys/FaultInfoGen/Bit Shift'
 * '<S6>'   : 'SWC_FRP/SWC_FRM_1ms_sys/FaultInfoGen/Bit Shift1'
 * '<S7>'   : 'SWC_FRP/SWC_FRM_1ms_sys/FaultInfoGen/Bit Shift10'
 * '<S8>'   : 'SWC_FRP/SWC_FRM_1ms_sys/FaultInfoGen/Bit Shift11'
 * '<S9>'   : 'SWC_FRP/SWC_FRM_1ms_sys/FaultInfoGen/Bit Shift12'
 * '<S10>'  : 'SWC_FRP/SWC_FRM_1ms_sys/FaultInfoGen/Bit Shift13'
 * '<S11>'  : 'SWC_FRP/SWC_FRM_1ms_sys/FaultInfoGen/Bit Shift14'
 * '<S12>'  : 'SWC_FRP/SWC_FRM_1ms_sys/FaultInfoGen/Bit Shift15'
 * '<S13>'  : 'SWC_FRP/SWC_FRM_1ms_sys/FaultInfoGen/Bit Shift16'
 * '<S14>'  : 'SWC_FRP/SWC_FRM_1ms_sys/FaultInfoGen/Bit Shift17'
 * '<S15>'  : 'SWC_FRP/SWC_FRM_1ms_sys/FaultInfoGen/Bit Shift18'
 * '<S16>'  : 'SWC_FRP/SWC_FRM_1ms_sys/FaultInfoGen/Bit Shift19'
 * '<S17>'  : 'SWC_FRP/SWC_FRM_1ms_sys/FaultInfoGen/Bit Shift2'
 * '<S18>'  : 'SWC_FRP/SWC_FRM_1ms_sys/FaultInfoGen/Bit Shift20'
 * '<S19>'  : 'SWC_FRP/SWC_FRM_1ms_sys/FaultInfoGen/Bit Shift21'
 * '<S20>'  : 'SWC_FRP/SWC_FRM_1ms_sys/FaultInfoGen/Bit Shift22'
 * '<S21>'  : 'SWC_FRP/SWC_FRM_1ms_sys/FaultInfoGen/Bit Shift23'
 * '<S22>'  : 'SWC_FRP/SWC_FRM_1ms_sys/FaultInfoGen/Bit Shift24'
 * '<S23>'  : 'SWC_FRP/SWC_FRM_1ms_sys/FaultInfoGen/Bit Shift25'
 * '<S24>'  : 'SWC_FRP/SWC_FRM_1ms_sys/FaultInfoGen/Bit Shift26'
 * '<S25>'  : 'SWC_FRP/SWC_FRM_1ms_sys/FaultInfoGen/Bit Shift27'
 * '<S26>'  : 'SWC_FRP/SWC_FRM_1ms_sys/FaultInfoGen/Bit Shift28'
 * '<S27>'  : 'SWC_FRP/SWC_FRM_1ms_sys/FaultInfoGen/Bit Shift29'
 * '<S28>'  : 'SWC_FRP/SWC_FRM_1ms_sys/FaultInfoGen/Bit Shift3'
 * '<S29>'  : 'SWC_FRP/SWC_FRM_1ms_sys/FaultInfoGen/Bit Shift30'
 * '<S30>'  : 'SWC_FRP/SWC_FRM_1ms_sys/FaultInfoGen/Bit Shift31'
 * '<S31>'  : 'SWC_FRP/SWC_FRM_1ms_sys/FaultInfoGen/Bit Shift4'
 * '<S32>'  : 'SWC_FRP/SWC_FRM_1ms_sys/FaultInfoGen/Bit Shift5'
 * '<S33>'  : 'SWC_FRP/SWC_FRM_1ms_sys/FaultInfoGen/Bit Shift6'
 * '<S34>'  : 'SWC_FRP/SWC_FRM_1ms_sys/FaultInfoGen/Bit Shift7'
 * '<S35>'  : 'SWC_FRP/SWC_FRM_1ms_sys/FaultInfoGen/Bit Shift8'
 * '<S36>'  : 'SWC_FRP/SWC_FRM_1ms_sys/FaultInfoGen/Bit Shift9'
 * '<S37>'  : 'SWC_FRP/SWC_FRM_1ms_sys/FaultInfoGen/Bit Shift/bit_shift'
 * '<S38>'  : 'SWC_FRP/SWC_FRM_1ms_sys/FaultInfoGen/Bit Shift1/bit_shift'
 * '<S39>'  : 'SWC_FRP/SWC_FRM_1ms_sys/FaultInfoGen/Bit Shift10/bit_shift'
 * '<S40>'  : 'SWC_FRP/SWC_FRM_1ms_sys/FaultInfoGen/Bit Shift11/bit_shift'
 * '<S41>'  : 'SWC_FRP/SWC_FRM_1ms_sys/FaultInfoGen/Bit Shift12/bit_shift'
 * '<S42>'  : 'SWC_FRP/SWC_FRM_1ms_sys/FaultInfoGen/Bit Shift13/bit_shift'
 * '<S43>'  : 'SWC_FRP/SWC_FRM_1ms_sys/FaultInfoGen/Bit Shift14/bit_shift'
 * '<S44>'  : 'SWC_FRP/SWC_FRM_1ms_sys/FaultInfoGen/Bit Shift15/bit_shift'
 * '<S45>'  : 'SWC_FRP/SWC_FRM_1ms_sys/FaultInfoGen/Bit Shift16/bit_shift'
 * '<S46>'  : 'SWC_FRP/SWC_FRM_1ms_sys/FaultInfoGen/Bit Shift17/bit_shift'
 * '<S47>'  : 'SWC_FRP/SWC_FRM_1ms_sys/FaultInfoGen/Bit Shift18/bit_shift'
 * '<S48>'  : 'SWC_FRP/SWC_FRM_1ms_sys/FaultInfoGen/Bit Shift19/bit_shift'
 * '<S49>'  : 'SWC_FRP/SWC_FRM_1ms_sys/FaultInfoGen/Bit Shift2/bit_shift'
 * '<S50>'  : 'SWC_FRP/SWC_FRM_1ms_sys/FaultInfoGen/Bit Shift20/bit_shift'
 * '<S51>'  : 'SWC_FRP/SWC_FRM_1ms_sys/FaultInfoGen/Bit Shift21/bit_shift'
 * '<S52>'  : 'SWC_FRP/SWC_FRM_1ms_sys/FaultInfoGen/Bit Shift22/bit_shift'
 * '<S53>'  : 'SWC_FRP/SWC_FRM_1ms_sys/FaultInfoGen/Bit Shift23/bit_shift'
 * '<S54>'  : 'SWC_FRP/SWC_FRM_1ms_sys/FaultInfoGen/Bit Shift24/bit_shift'
 * '<S55>'  : 'SWC_FRP/SWC_FRM_1ms_sys/FaultInfoGen/Bit Shift25/bit_shift'
 * '<S56>'  : 'SWC_FRP/SWC_FRM_1ms_sys/FaultInfoGen/Bit Shift26/bit_shift'
 * '<S57>'  : 'SWC_FRP/SWC_FRM_1ms_sys/FaultInfoGen/Bit Shift27/bit_shift'
 * '<S58>'  : 'SWC_FRP/SWC_FRM_1ms_sys/FaultInfoGen/Bit Shift28/bit_shift'
 * '<S59>'  : 'SWC_FRP/SWC_FRM_1ms_sys/FaultInfoGen/Bit Shift29/bit_shift'
 * '<S60>'  : 'SWC_FRP/SWC_FRM_1ms_sys/FaultInfoGen/Bit Shift3/bit_shift'
 * '<S61>'  : 'SWC_FRP/SWC_FRM_1ms_sys/FaultInfoGen/Bit Shift30/bit_shift'
 * '<S62>'  : 'SWC_FRP/SWC_FRM_1ms_sys/FaultInfoGen/Bit Shift31/bit_shift'
 * '<S63>'  : 'SWC_FRP/SWC_FRM_1ms_sys/FaultInfoGen/Bit Shift4/bit_shift'
 * '<S64>'  : 'SWC_FRP/SWC_FRM_1ms_sys/FaultInfoGen/Bit Shift5/bit_shift'
 * '<S65>'  : 'SWC_FRP/SWC_FRM_1ms_sys/FaultInfoGen/Bit Shift6/bit_shift'
 * '<S66>'  : 'SWC_FRP/SWC_FRM_1ms_sys/FaultInfoGen/Bit Shift7/bit_shift'
 * '<S67>'  : 'SWC_FRP/SWC_FRM_1ms_sys/FaultInfoGen/Bit Shift8/bit_shift'
 * '<S68>'  : 'SWC_FRP/SWC_FRM_1ms_sys/FaultInfoGen/Bit Shift9/bit_shift'
 */
#endif                                 /* RTW_HEADER_SWC_FRP_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
