/*
 * File: SWC_HvMcu.h
 *
 * Code generated for Simulink model 'SWC_HvMcu'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Sun Jun 28 17:21:32 2020
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_SWC_HvMcu_h_
#define RTW_HEADER_SWC_HvMcu_h_
#ifndef SWC_HvMcu_COMMON_INCLUDES_
# define SWC_HvMcu_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_SWC_HvMcu.h"
#endif                                 /* SWC_HvMcu_COMMON_INCLUDES_ */

#include "SWC_HvMcu_types.h"

/* Macros for accessing real-time model data structure */

/* Block signals (default storage) */
typedef struct tag_B_SWC_HvMcu_T {
  HvMcu_OutPut_S CCaller;              /* '<S1>/C Caller' */
  PosCal_OutPut_S CCaller1;            /* '<S1>/C Caller1' */
} B_SWC_HvMcu_T;

/* Block signals (default storage) */
extern B_SWC_HvMcu_T SWC_HvMcu_B;

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
 * '<Root>' : 'SWC_HvMcu'
 * '<S1>'   : 'SWC_HvMcu/RE_HvMcu_100us_sys'
 * '<S2>'   : 'SWC_HvMcu/RE_HvMcu_2ms_sys'
 * '<S3>'   : 'SWC_HvMcu/SWC_HvMcu_Init'
 */
#endif                                 /* RTW_HEADER_SWC_HvMcu_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
