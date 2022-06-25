/*
 * File: SWC_ADM_private.h
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

#ifndef RTW_HEADER_SWC_ADM_private_h_
#define RTW_HEADER_SWC_ADM_private_h_
#include "rtwtypes.h"
#include "SWC_ADM.h"

extern boolean SWC_ADM_Debounce(boolean rtu_BooleanIN, boolean rtu_Rst, sint16
  rtu_CountTrh, sint16 rtu_DebTrh, DW_Debounce_SWC_ADM_T *localDW);
extern void SWC_ADM_GlbDchgMon(void);
extern void SWC_ADM_BMSVoltRngChk(void);
extern void SWC_ADM_VoltCmpChk(void);
extern void SWC_ADM_1ms(void);

#endif                                 /* RTW_HEADER_SWC_ADM_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
