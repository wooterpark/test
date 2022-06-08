/*
 * File: SWC_Epark.h
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

#ifndef RTW_HEADER_SWC_Epark_h_
#define RTW_HEADER_SWC_Epark_h_
#ifndef SWC_Epark_COMMON_INCLUDES_
# define SWC_Epark_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_SWC_Epark.h"
#endif                                 /* SWC_Epark_COMMON_INCLUDES_ */

#include "SWC_Epark_types.h"

/* Macros for accessing real-time model data structure */

/* Block signals (default storage) */
typedef struct tag_B_SWC_Epark_T {
  EparkOutIFType CCaller;              /* '<S1>/C Caller' */
} B_SWC_Epark_T;

/* Block signals (default storage) */
extern B_SWC_Epark_T SWC_Epark_B;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Data Type Conversion' : Eliminate redundant data type conversion
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
 * '<Root>' : 'SWC_Epark'
 * '<S1>'   : 'SWC_Epark/RE_Epark_10ms_sys'
 * '<S2>'   : 'SWC_Epark/SWC_Epark_Init'
 */
#endif                                 /* RTW_HEADER_SWC_Epark_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
