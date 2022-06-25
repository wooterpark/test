/*
 * File: SWC_ADM.h
 *
 * Code generated for Simulink model 'SWC_ADM'.
 *
 * Model version                  : 1.285
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Fri Jun 24 16:29:57 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_SWC_ADM_h_
#define RTW_HEADER_SWC_ADM_h_
#include <math.h>
#ifndef SWC_ADM_COMMON_INCLUDES_
# define SWC_ADM_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* SWC_ADM_COMMON_INCLUDES_ */

#include "SWC_ADM_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<S11>/Debounce' */
typedef struct {
  sint16 UnitDelay2_DSTATE;            /* '<S14>/Unit Delay2' */
  sint16 Delay_DSTATE;                 /* '<S16>/Delay' */
  boolean UnitDelay3_DSTATE;           /* '<S14>/Unit Delay3' */
  boolean UnitDelay1_DSTATE;           /* '<S14>/Unit Delay1' */
} DW_Debounce_SWC_ADM_T;

/* Block signals (default storage) */
typedef struct {
  uint8 Add3;                          /* '<S4>/Add3' */
  boolean LogicalOperator;             /* '<S4>/Logical Operator' */
  boolean LogicalOperator1;            /* '<S4>/Logical Operator1' */
} B_SWC_ADM_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  float32 UnitDelay8_DSTATE;           /* '<S3>/Unit Delay8' */
  float32 UnitDelay4_DSTATE;           /* '<S3>/Unit Delay4' */
  DW_Debounce_SWC_ADM_T Debounce_n;    /* '<S12>/Debounce' */
  DW_Debounce_SWC_ADM_T Debounce;      /* '<S11>/Debounce' */
} DW_SWC_ADM_T;

/* Real-time Model Data Structure */
struct tag_RTM_SWC_ADM_T {
  const char_T *errorStatus;
};

/* Block signals (default storage) */
extern B_SWC_ADM_T SWC_ADM_B;

/* Block states (default storage) */
extern DW_SWC_ADM_T SWC_ADM_DW;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern float32 VAR_ADM_HiPrecVolt_f32; /* '<S18>/Signal Conversion' */
extern float32 VAR_ADM_BMSVolt_f32;    /* '<S13>/Signal Conversion' */
extern float32 VAR_ADM_L2Com_HiPrecVolt_IN;/* '<S8>/Switch' */
extern float32 VAR_ADM_L2Com_BMSVolt_IN;/* '<S10>/Switch' */
extern uint8 VAR_ADM_stModeReq_u8;     /* '<S7>/Switch' */
extern boolean VAR_ADM_VoltCmpChkErr_b;/* '<S12>/Debounce' */
extern boolean VAR_ADM_BMSVoltRngErr_b;/* '<S11>/Debounce' */
extern boolean VAR_VoltCmpChkErrSt;    /* '<S18>/Switch4' */
extern boolean VAR_BMSVoltRngErrSt;    /* '<S13>/Logical Operator' */
extern boolean VAR_ADM_flgDchgReq_b;   /* '<S9>/Switch' */
extern boolean VAR_ADM_flgCrash_b;     /* '<S6>/Switch' */
extern boolean VAR_ADM_GlbDchgErr_b;   /* '<S3>/Switch1' */

/* Model entry point functions */
extern void SWC_ADM_initialize(void);
extern void SWC_ADM_terminate(void);

/* Exported entry point function */
extern void SWC_ADM_1ms(void);

/* Exported data declaration */
#pragma section ".rodata.Calib_32"

/* Declaration for custom storage class: iEDS_Parameter */
extern const volatile float32 CAL_ADM_BMSLowerThr_f32;
                            /* Referenced by: '<S13>/CAL_ADM_BMSLowerThr_f32' */
extern const volatile float32 CAL_ADM_BMSUpperThr_f32;
                            /* Referenced by: '<S13>/CAL_ADM_BMSUpperThr_f32' */
extern const volatile sint16 CAL_ADM_BMSVoltRngErrCntThr_s16;
                    /* Referenced by: '<S11>/CAL_ADM_BMSVoltRngErrCntThr_s16' */
extern const volatile sint16 CAL_ADM_BMSVoltRngErrDebThr_s16;
                    /* Referenced by: '<S11>/CAL_ADM_BMSVoltRngErrDebThr_s16' */
extern const volatile boolean CAL_ADM_BMSVoltRngErrRst_b;
                         /* Referenced by: '<S11>/CAL_ADM_BMSVoltRngErrRst_b' */
extern const volatile uint8 CAL_ADM_DchgMode_u8;
                                 /* Referenced by: '<S3>/CAL_ADM_DchgMode_u8' */
extern const volatile boolean CAL_ADM_GlbDchgErrRst_b;
                             /* Referenced by: '<S3>/CAL_ADM_GlbDchgErrRst_b' */
extern const volatile float32 CAL_ADM_GlbDchgThrshTime_f32;
                        /* Referenced by: '<S3>/CAL_ADM_GlbDchgThrshTime_f32' */
extern const volatile float32 CAL_ADM_GlbDchgThrshVolt_f32;
                        /* Referenced by: '<S3>/CAL_ADM_GlbDchgThrshVolt_f32' */
extern const volatile float32 CAL_ADM_L2Com_BMSVolt;/* Referenced by: '<S10>/Constant3' */
extern const volatile boolean CAL_ADM_L2Com_BMSVolt_b;/* Referenced by: '<S10>/Constant2' */
extern const volatile float32 CAL_ADM_L2Com_HiPrecVolt;/* Referenced by: '<S8>/Constant3' */
extern const volatile boolean CAL_ADM_L2Com_HiPrecVolt_b;/* Referenced by: '<S8>/Constant2' */
extern const volatile float32 CAL_ADM_VoltAbsDiffThrPerc_f32;
                     /* Referenced by: '<S18>/CAL_ADM_VoltAbsDiffThrPerc_f32' */
extern const volatile float32 CAL_ADM_VoltAbsDiffThr_f32;
                         /* Referenced by: '<S18>/CAL_ADM_VoltAbsDiffThr_f32' */
extern const volatile float32 CAL_ADM_VoltChgThr_f32;
                             /* Referenced by: '<S18>/CAL_ADM_VoltChgThr_f32' */
extern const volatile sint16 CAL_ADM_VoltCmpChkErrCntThr_s16;
                    /* Referenced by: '<S12>/CAL_ADM_VoltCmpChkErrCntThr_s16' */
extern const volatile sint16 CAL_ADM_VoltCmpChkErrDebThr_s16;
                    /* Referenced by: '<S12>/CAL_ADM_VoltCmpChkErrDebThr_s16' */
extern const volatile boolean CAL_ADM_VoltCmpChkErrRst_b;
                         /* Referenced by: '<S12>/CAL_ADM_VoltCmpChkErrRst_b' */
extern const volatile boolean CAL_ADM_VoltCmpChkErrst_b;
                           /* Referenced by: '<S3>/CAL_ADM_VoltCmpChkErrst_b' */
extern const volatile boolean CAL_ADM_flgCrashSwt_b;/* Referenced by: '<S6>/Constant2' */
extern const volatile boolean CAL_ADM_flgCrash_b;/* Referenced by: '<S6>/Constant3' */
extern const volatile boolean CAL_ADM_flgDchgReqSwt_b;/* Referenced by: '<S9>/Constant2' */
extern const volatile boolean CAL_ADM_flgDchgReq_b;/* Referenced by: '<S9>/Constant3' */
extern const volatile boolean CAL_ADM_flgstModeReqSwt_b;/* Referenced by: '<S7>/Constant2' */
extern const volatile uint8 CAL_ADM_stModeReq_u8;/* Referenced by: '<S7>/Constant3' */

#pragma section

/* Real-time Model object */
extern RT_MODEL_SWC_ADM_T *const SWC_ADM_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S6>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S7>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S8>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S9>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S10>/Data Type Conversion' : Eliminate redundant data type conversion
 */

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
 * '<Root>' : 'SWC_ADM'
 * '<S1>'   : 'SWC_ADM/SWC_ADM_1ms_sys'
 * '<S2>'   : 'SWC_ADM/SWC_ADM_Init'
 * '<S3>'   : 'SWC_ADM/SWC_ADM_1ms_sys/GlbDchgMon'
 * '<S4>'   : 'SWC_ADM/SWC_ADM_1ms_sys/SigMng'
 * '<S5>'   : 'SWC_ADM/SWC_ADM_1ms_sys/VoltMon'
 * '<S6>'   : 'SWC_ADM/SWC_ADM_1ms_sys/SigMng/Subsystem1'
 * '<S7>'   : 'SWC_ADM/SWC_ADM_1ms_sys/SigMng/Subsystem10'
 * '<S8>'   : 'SWC_ADM/SWC_ADM_1ms_sys/SigMng/Subsystem2'
 * '<S9>'   : 'SWC_ADM/SWC_ADM_1ms_sys/SigMng/Subsystem22'
 * '<S10>'  : 'SWC_ADM/SWC_ADM_1ms_sys/SigMng/Subsystem3'
 * '<S11>'  : 'SWC_ADM/SWC_ADM_1ms_sys/VoltMon/BMSVoltRngMon'
 * '<S12>'  : 'SWC_ADM/SWC_ADM_1ms_sys/VoltMon/VoltCmpChkMon'
 * '<S13>'  : 'SWC_ADM/SWC_ADM_1ms_sys/VoltMon/BMSVoltRngMon/BMSVoltRngChk'
 * '<S14>'  : 'SWC_ADM/SWC_ADM_1ms_sys/VoltMon/BMSVoltRngMon/Debounce'
 * '<S15>'  : 'SWC_ADM/SWC_ADM_1ms_sys/VoltMon/BMSVoltRngMon/Debounce/Compare To Zero'
 * '<S16>'  : 'SWC_ADM/SWC_ADM_1ms_sys/VoltMon/BMSVoltRngMon/Debounce/Subsystem'
 * '<S17>'  : 'SWC_ADM/SWC_ADM_1ms_sys/VoltMon/VoltCmpChkMon/Debounce'
 * '<S18>'  : 'SWC_ADM/SWC_ADM_1ms_sys/VoltMon/VoltCmpChkMon/VoltCmpChk'
 * '<S19>'  : 'SWC_ADM/SWC_ADM_1ms_sys/VoltMon/VoltCmpChkMon/Debounce/Compare To Zero'
 * '<S20>'  : 'SWC_ADM/SWC_ADM_1ms_sys/VoltMon/VoltCmpChkMon/Debounce/Subsystem'
 */
#endif                                 /* RTW_HEADER_SWC_ADM_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
