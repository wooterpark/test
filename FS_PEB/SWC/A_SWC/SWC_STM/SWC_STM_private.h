/*
 * File: SWC_STM_private.h
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

#ifndef RTW_HEADER_SWC_STM_private_h_
#define RTW_HEADER_SWC_STM_private_h_
#include "rtwtypes.h"
#include "SWC_STM.h"

extern void SWC_STM_Subsystem(boolean rtu_Enable, sint16 rtu_CountTrh, sint16
  *rty_Count, DW_Subsystem_SWC_STM_T *localDW);
extern void SWC_STM_Debouncer(boolean rtu_BooleanIN, boolean rtu_Rst, sint16
  rtu_CountTrh, sint16 rtu_DebTrh, boolean *rty_OutLock, sint16 *rty_Count,
  sint16 *rty_Deb, DW_Debouncer_SWC_STM_T *localDW);
extern void SWC_STM_Debouncer_n(boolean rtu_BooleanIN, boolean rtu_Rst, sint16
  rtu_CountTrh, sint16 rtu_DebTrh, boolean *rty_OutLock, B_Debouncer_SWC_STM_k_T
  *localB, DW_Debouncer_SWC_STM_i_T *localDW);
extern void SWC_STM_UintndSpdMon(void);
extern void SWC_STM_UintndTrqMon(void);
extern void SWC_STM_1ms(void);

#endif                                 /* RTW_HEADER_SWC_STM_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
