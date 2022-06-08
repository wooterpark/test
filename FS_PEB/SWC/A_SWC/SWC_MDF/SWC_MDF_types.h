/*
 * File: SWC_MDF_types.h
 *
 * Code generated for Simulink model 'SWC_MDF'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Tue Jan 26 09:57:53 2021
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_SWC_MDF_types_h_
#define RTW_HEADER_SWC_MDF_types_h_
#include "rtwtypes.h"

/* Model Code Variants */
#ifndef DEFINED_TYPEDEF_FOR_iEDS_Enum_stDrvCtl_def_
#define DEFINED_TYPEDEF_FOR_iEDS_Enum_stDrvCtl_def_

typedef enum {
  Drv_Initial = 0,                     /* Default value */
  Drv_MocSop,
  Drv_SensCalFW,
  Drv_Standby,
  Drv_Run,
  Drv_OffsetAcc,
  Drv_OffsetFw,
  Drv_Discharge,
  Drv_Failure,
  Drv_TrqCtl,
  Drv_nCtlExt,
  Drv_inActive,
  Drv_nCtlInt,
  Drv_IsCtl,
  Drv_UdcCtl,
  Drv_UdcBatCtl,
  Drv_FrWCtl,
  Drv_IdLe,
  Drv_TestBench,
  Drv_OffsetCal,
  Drv_EparkCalInit,
  Drv_EparkCalAcc,
  Drv_EparkCalFw
} iEDS_Enum_stDrvCtl_def;

#endif
#endif                                 /* RTW_HEADER_SWC_MDF_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
