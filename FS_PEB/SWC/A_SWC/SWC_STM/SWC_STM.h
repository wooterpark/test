/*
 * File: SWC_STM.h
 *
 * Code generated for Simulink model 'SWC_STM'.
 *
 * Model version                  : 1.499
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Wed Sep  1 08:21:32 2021
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
#define GLB_STM_MotorFw_u8             1U                        /* Referenced by: '<S11>/GLB_TOM_MotorFw_u1' */
#define GLB_STM_MotorStop_u8           0U                        /* Referenced by: '<S11>/GLB_TOM_MotorStop_u8' */
#define GLB_STM_PosvTrq_u8             1U                        /* Referenced by: '<S18>/GLB_TOM_PosvTrq_u1' */
#define GLB_STM_ZeroTrq_u8             0U                        /* Referenced by: '<S18>/GLB_TpcCod_ZeroTrq_u1' */

/* Block states (default storage) for system '<S3>/Subsystem' */
typedef struct {
  sint16 Delay_DSTATE;                 /* '<S7>/Delay' */
} DW_Subsystem_SWC_STM_T;

/* Block states (default storage) for system '<S1>/Debouncer' */
typedef struct {
  sint16 Delay2_DSTATE;                /* '<S3>/Delay2' */
  boolean UnitDelay1_DSTATE;           /* '<S3>/Unit Delay1' */
  boolean Delay1_DSTATE;               /* '<S3>/Delay1' */
  DW_Subsystem_SWC_STM_T Subsystem;    /* '<S3>/Subsystem' */
} DW_Debouncer_SWC_STM_T;

/* Block signals for system '<S8>/Debouncer' */
typedef struct {
  sint16 Switch;                       /* '<S13>/Switch' */
} B_Debouncer_SWC_STM_k_T;

/* Block states (default storage) for system '<S8>/Debouncer' */
typedef struct {
  sint16 Delay2_DSTATE;                /* '<S10>/Delay2' */
  boolean UnitDelay1_DSTATE;           /* '<S10>/Unit Delay1' */
  boolean Delay1_DSTATE;               /* '<S10>/Delay1' */
  DW_Subsystem_SWC_STM_T Subsystem;    /* '<S10>/Subsystem' */
} DW_Debouncer_SWC_STM_i_T;

/* Block signals (default storage) */
typedef struct {
  sint16 Switch;                       /* '<S7>/Switch' */
  B_Debouncer_SWC_STM_k_T Debouncer_l; /* '<S15>/Debouncer' */
  B_Debouncer_SWC_STM_k_T Debouncer_n; /* '<S8>/Debouncer' */
} B_SWC_STM_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  DW_Debouncer_SWC_STM_i_T Debouncer_l;/* '<S15>/Debouncer' */
  DW_Debouncer_SWC_STM_i_T Debouncer_n;/* '<S8>/Debouncer' */
  DW_Debouncer_SWC_STM_T Debouncer;    /* '<S1>/Debouncer' */
} DW_SWC_STM_T;

/* Real-time Model Data Structure */
struct tag_RTM_SWC_STM_T {
  const char_T *errorStatus;
};
#pragma section ".data.CPU1_32"
/* Block signals (default storage) */
extern B_SWC_STM_T SWC_STM_B;

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
extern boolean VAR_STM_UintndTrqMonRslt_b;/* '<S18>/Logical Operator1' */
extern boolean VAR_STM_UintndTrqErr_b; /* '<S17>/Logical Operator' */
extern boolean VAR_STM_UintndSpdMonRslt_b;/* '<S11>/Logical Operator1' */
extern boolean VAR_STM_UintndSpdErr_b; /* '<S10>/Logical Operator' */
#pragma section
#pragma section ".text.CPU1_Code" ax
/* Model entry point functions */
extern void SWC_STM_initialize(void);

/* Exported entry point function */
extern void SWC_STM_1ms(void);
#pragma section
/* Exported data declaration */
//#pragma section ".rodata.Calib_32"

/* Declaration for custom storage class: iEDS_Parameter */
extern const volatile uint8 CAL_STM_SpeedCtlMode_u8;/* Referenced by:
                                                     * '<S9>/Constant'
                                                     * '<S16>/CAL_TOM_SpeedCtlMode_u1'
                                                     */
extern const volatile float32 CAL_STM_UxptNLim_f32;/* Referenced by:
                                                    * '<S11>/Constant3'
                                                    * '<S11>/Constant4'
                                                    * '<S11>/Constant5'
                                                    */
extern const volatile sint16 CAL_STM_UxptSpdMonCountTrh_s16;
                          /* Referenced by: '<S8>/CAL_TOM_SpeedMonDebTrh_s16' */
extern const volatile sint16 CAL_STM_UxptSpdMonDebTrh_s16;
                           /* Referenced by: '<S8>/CAL_TOM_SpeedMonDebTrh_s1' */
extern const volatile boolean CAL_STM_UxptSpdMonErrRst_b;
                            /* Referenced by: '<S8>/CAL_TOM_SpeedMonErrRst_b' */
extern const volatile float32 CAL_STM_UxptTrqLim_f32;/* Referenced by:
                                                      * '<S18>/Constant3'
                                                      * '<S18>/Constant4'
                                                      * '<S18>/Constant5'
                                                      */
extern const volatile sint16 CAL_STM_UxptTrqMonCountTrh_s16;
                         /* Referenced by: '<S15>/CAL_TOM_HiTrqMonDebTrh_s16' */
extern const volatile sint16 CAL_STM_UxptTrqMonDebTrh_s16;
                          /* Referenced by: '<S15>/CAL_TOM_HiTrqMonDebTrh_s1' */
extern const volatile boolean CAL_STM_UxptTrqMonErrRst_b;
                         /* Referenced by: '<S15>/CAL_TOM_TrqMonMaulErrRst_b' */

//#pragma section

/* Real-time Model object */
extern RT_MODEL_SWC_STM_T *const SWC_STM_M;

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
 * '<S3>'   : 'SWC_STM/SWC_STM_1ms_sys/Debouncer'
 * '<S4>'   : 'SWC_STM/SWC_STM_1ms_sys/SpdMonProc'
 * '<S5>'   : 'SWC_STM/SWC_STM_1ms_sys/TrqMonProc'
 * '<S6>'   : 'SWC_STM/SWC_STM_1ms_sys/Debouncer/Compare To Zero'
 * '<S7>'   : 'SWC_STM/SWC_STM_1ms_sys/Debouncer/Subsystem'
 * '<S8>'   : 'SWC_STM/SWC_STM_1ms_sys/SpdMonProc/SpdMon'
 * '<S9>'   : 'SWC_STM/SWC_STM_1ms_sys/SpdMonProc/SpdMonEnable'
 * '<S10>'  : 'SWC_STM/SWC_STM_1ms_sys/SpdMonProc/SpdMon/Debouncer'
 * '<S11>'  : 'SWC_STM/SWC_STM_1ms_sys/SpdMonProc/SpdMon/UintndSpdMon'
 * '<S12>'  : 'SWC_STM/SWC_STM_1ms_sys/SpdMonProc/SpdMon/Debouncer/Compare To Zero'
 * '<S13>'  : 'SWC_STM/SWC_STM_1ms_sys/SpdMonProc/SpdMon/Debouncer/Subsystem'
 * '<S14>'  : 'SWC_STM/SWC_STM_1ms_sys/SpdMonProc/SpdMon/UintndSpdMon/Compare To Zero3'
 * '<S15>'  : 'SWC_STM/SWC_STM_1ms_sys/TrqMonProc/TrqMon'
 * '<S16>'  : 'SWC_STM/SWC_STM_1ms_sys/TrqMonProc/TrqMonEnable'
 * '<S17>'  : 'SWC_STM/SWC_STM_1ms_sys/TrqMonProc/TrqMon/Debouncer'
 * '<S18>'  : 'SWC_STM/SWC_STM_1ms_sys/TrqMonProc/TrqMon/UintndTrqMon'
 * '<S19>'  : 'SWC_STM/SWC_STM_1ms_sys/TrqMonProc/TrqMon/Debouncer/Compare To Zero'
 * '<S20>'  : 'SWC_STM/SWC_STM_1ms_sys/TrqMonProc/TrqMon/Debouncer/Subsystem'
 * '<S21>'  : 'SWC_STM/SWC_STM_1ms_sys/TrqMonProc/TrqMon/UintndTrqMon/Compare To Zero3'
 */
#endif                                 /* RTW_HEADER_SWC_STM_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
