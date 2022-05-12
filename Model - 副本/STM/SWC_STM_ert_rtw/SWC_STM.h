/*
 * File: SWC_STM.h
 *
 * Code generated for Simulink model 'SWC_STM'.
 *
 * Model version                  : 1.508
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Wed Apr 27 16:14:23 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_SWC_STM_h_
#define RTW_HEADER_SWC_STM_h_
#include <math.h>
#ifndef SWC_STM_COMMON_INCLUDES_
# define SWC_STM_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* SWC_STM_COMMON_INCLUDES_ */

#include "SWC_STM_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Exported data define */

/* Definition for custom storage class: Define */
#define GLB_STM_PosvTrq_u8             1U                        /* Referenced by: '<S7>/GLB_TOM_PosvTrq_u1' */
#define GLB_STM_ZeroTrq_u8             0U                        /* Referenced by: '<S7>/GLB_TpcCod_ZeroTrq_u1' */

/* Block states (default storage) for system '<S4>/Debouncer' */
typedef struct {
  sint16 Delay2_DSTATE;                /* '<S6>/Delay2' */
  sint16 Delay_DSTATE;                 /* '<S9>/Delay' */
  boolean UnitDelay1_DSTATE;           /* '<S6>/Unit Delay1' */
  boolean Delay1_DSTATE;               /* '<S6>/Delay1' */
} DW_Debouncer_SWC_STM_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  float32 UnitDelay2_DSTATE;           /* '<S7>/Unit Delay2' */
  DW_Debouncer_SWC_STM_T Debouncer;    /* '<S4>/Debouncer' */
} DW_SWC_STM_T;

/* Real-time Model Data Structure */
struct tag_RTM_SWC_STM_T {
  const char_T *errorStatus;
};

/* Block states (default storage) */
extern DW_SWC_STM_T SWC_STM_DW;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern boolean VAR_STM_UintndTrqMonRslt_b;/* '<S7>/Logical Operator1' */
extern boolean VAR_STM_UintndTrqErr_b; /* '<S6>/Logical Operator' */

/* Model entry point functions */
extern void SWC_STM_initialize(void);

/* Exported entry point function */
extern void SWC_STM_1ms(void);

/* Exported data declaration */
#pragma section ".rodata.Calib_32"

/* Declaration for custom storage class: iEDS_Parameter */
extern const volatile uint8 CAL_STM_SpeedCtlMode_u8;
                             /* Referenced by: '<S5>/CAL_TOM_SpeedCtlMode_u1' */
extern const volatile float32 CAL_STM_TrqSetRamp_f32;
                              /* Referenced by: '<S7>/CAL_STM_TrqSetRamp_f32' */
extern const volatile float32 CAL_STM_UxptTrqLim_f32;/* Referenced by:
                                                      * '<S7>/Constant3'
                                                      * '<S7>/Constant4'
                                                      * '<S7>/Constant5'
                                                      */
extern const volatile sint16 CAL_STM_UxptTrqMonCountTrh_s16;
                          /* Referenced by: '<S4>/CAL_TOM_HiTrqMonDebTrh_s16' */
extern const volatile sint16 CAL_STM_UxptTrqMonDebTrh_s16;
                           /* Referenced by: '<S4>/CAL_TOM_HiTrqMonDebTrh_s1' */
extern const volatile boolean CAL_STM_UxptTrqMonErrRst_b;
                          /* Referenced by: '<S4>/CAL_TOM_TrqMonMaulErrRst_b' */

#pragma section

/* Real-time Model object */
extern RT_MODEL_SWC_STM_T *const SWC_STM_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S7>/Signal Conversion' : Eliminate redundant signal conversion block
 * Block '<S7>/Signal Conversion1' : Eliminate redundant signal conversion block
 * Block '<S7>/Signal Conversion2' : Eliminate redundant signal conversion block
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
 * '<Root>' : 'SWC_STM'
 * '<S1>'   : 'SWC_STM/SWC_STM_1ms_sys'
 * '<S2>'   : 'SWC_STM/SWC_STM_Init'
 * '<S3>'   : 'SWC_STM/SWC_STM_1ms_sys/TrqMonProc'
 * '<S4>'   : 'SWC_STM/SWC_STM_1ms_sys/TrqMonProc/TrqMon'
 * '<S5>'   : 'SWC_STM/SWC_STM_1ms_sys/TrqMonProc/TrqMonEnable'
 * '<S6>'   : 'SWC_STM/SWC_STM_1ms_sys/TrqMonProc/TrqMon/Debouncer'
 * '<S7>'   : 'SWC_STM/SWC_STM_1ms_sys/TrqMonProc/TrqMon/UintndTrqMon'
 * '<S8>'   : 'SWC_STM/SWC_STM_1ms_sys/TrqMonProc/TrqMon/Debouncer/Compare To Zero'
 * '<S9>'   : 'SWC_STM/SWC_STM_1ms_sys/TrqMonProc/TrqMon/Debouncer/Subsystem'
 * '<S10>'  : 'SWC_STM/SWC_STM_1ms_sys/TrqMonProc/TrqMon/UintndTrqMon/Compare To Zero3'
 */
#endif                                 /* RTW_HEADER_SWC_STM_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
