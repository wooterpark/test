/*
 * File: SWC_PhC.h
 *
 * Code generated for Simulink model 'SWC_PhC'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Sun Jun 28 13:59:20 2020
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_SWC_PhC_h_
#define RTW_HEADER_SWC_PhC_h_
#ifndef SWC_PhC_COMMON_INCLUDES_
# define SWC_PhC_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_SWC_PhC.h"
#endif                                 /* SWC_PhC_COMMON_INCLUDES_ */

#include "SWC_PhC_types.h"

/* Macros for accessing real-time model data structure */

/* Block signals (default storage) */
typedef struct tag_B_SWC_PhC_T {
  PhCOutIFType CCaller;                /* '<S2>/C Caller' */
} B_SWC_PhC_T;

/* Block signals (default storage) */
extern B_SWC_PhC_T SWC_PhC_B;

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
 * '<Root>' : 'SWC_PhC'
 * '<S1>'   : 'SWC_PhC/RE_PhC_FaultHand_2ms_sys'
 * '<S2>'   : 'SWC_PhC/RE_PhC_GetResult_MCUHw_100us_sys'
 * '<S3>'   : 'SWC_PhC/SWC_PhC_Init'
 */
#endif                                 /* RTW_HEADER_SWC_PhC_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
