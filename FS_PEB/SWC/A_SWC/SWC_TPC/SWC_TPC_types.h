/*
 * File: SWC_TPC_types.h
 *
 * Code generated for Simulink model 'SWC_TPC'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Fri Jan 15 14:28:54 2021
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_SWC_TPC_types_h_
#define RTW_HEADER_SWC_TPC_types_h_
#include "rtwtypes.h"

/* Model Code Variants */
#ifndef DEFINED_TYPEDEF_FOR_iEDS_Enum_stTrqEm_def_
#define DEFINED_TYPEDEF_FOR_iEDS_Enum_stTrqEm_def_

typedef enum {
  bDern_Inactive = 0,                  /* Default value */
  bDern_ExCTrq,
  bDern_StrTemp,
  bDern_TempIGBT,
  bDern_N,
  bDern_OvrIdc,
  bDern_UndrUdc,
  bDern_OvrUdc,
  bDern_CAN,
  bDern_TCoolant,
  bDern_TDrvBoard,
  bDern_TempDBC
} iEDS_Enum_stTrqEm_def;

#endif
#endif                                 /* RTW_HEADER_SWC_TPC_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
