/*
 * File: SWC_SCF_EI09_EmDisChaFunction.h
 *
 * Code generated for Simulink model 'SWC_SCF'.
 *
 * Model version                  : 1.11
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Wed Jan 20 16:15:29 2021
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_SWC_SCF_EI09_EmDisChaFunction_h_
#define RTW_HEADER_SWC_SCF_EI09_EmDisChaFunction_h_
#ifndef SWC_SCF_COMMON_INCLUDES_
# define SWC_SCF_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_SWC_SCF.h"
#endif                                 /* SWC_SCF_COMMON_INCLUDES_ */

#include "SWC_SCF_types.h"

/* Block states (default storage) for system '<S14>/EI09_EmDisChaFunction' */
typedef struct {
  uint16 UnitDelay1_DSTATE;            /* '<S22>/Unit Delay1' */
  boolean UnitDelay2_DSTATE;           /* '<S22>/Unit Delay2' */
} DW_EI09_EmDisChaFunction_SWC__T;

/* Invariant block signals for system '<S14>/EI09_EmDisChaFunction' */
typedef struct {
  const boolean Constant;              /* '<S21>/Constant' */
} ConstB_EI09_EmDisChaFunction__T;

extern void SWC_SCF_EI09_EmDisChaFunction(boolean rtu_HSPF_flgCrash, boolean
  rtu_CSPF_RecflgCrash, boolean *rty_flgEmgyDcha,
  DW_EI09_EmDisChaFunction_SWC__T *localDW);

#endif                         /* RTW_HEADER_SWC_SCF_EI09_EmDisChaFunction_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
