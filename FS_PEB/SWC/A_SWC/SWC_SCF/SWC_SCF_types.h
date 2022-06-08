/*
 * File: SWC_SCF_types.h
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

#ifndef RTW_HEADER_SWC_SCF_types_h_
#define RTW_HEADER_SWC_SCF_types_h_
#include "rtwtypes.h"

/* Model Code Variants */
#ifndef DEFINED_TYPEDEF_FOR_iEDS_Enum_stSysCtl_def_
#define DEFINED_TYPEDEF_FOR_iEDS_Enum_stSysCtl_def_

typedef enum {
  PreDriveMod = 0,                     /* Default value */
  DriveMod,
  PostDriveMod,
  ShutDownMod,
  FaultMod
} iEDS_Enum_stSysCtl_def;

#endif

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
#endif                                 /* RTW_HEADER_SWC_SCF_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
