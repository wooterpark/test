/*
 * File: SWC_PCF_types.h
 *
 * Code generated for Simulink model 'SWC_PCF'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Sat Jan 16 13:41:43 2021
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_SWC_PCF_types_h_
#define RTW_HEADER_SWC_PCF_types_h_
#include "rtwtypes.h"

/* Model Code Variants */
#ifndef DEFINED_TYPEDEF_FOR_iEDS_Enum_stEPPuDc_def_
#define DEFINED_TYPEDEF_FOR_iEDS_Enum_stEPPuDc_def_

typedef enum {
  PCFuDc_serlowfail = 0,               /* Default value */
  PCFuDc_norlowfail,
  PCFuDc_normal,
  PCFuDc_norhighfail,
  PCFuDc_serhighfail
} iEDS_Enum_stEPPuDc_def;

#endif

#ifndef DEFINED_TYPEDEF_FOR_iEDS_Enum_stEPPSm_def_
#define DEFINED_TYPEDEF_FOR_iEDS_Enum_stEPPSm_def_

typedef enum {
  stPark_Init = 0,                     /* Default value */
  stPark_SelfCheck,
  stPark_SLInit,
  stPark_Standby,
  stPark_NPCInit,
  stPark_NPCOutP,
  stPark_NPCInP,
  stPark_NPCRun,
  stPark_Fault,
  stPark_RPCInit,
  stPark_RPCRun,
  stPark_RPCOutP,
  stPark_RPCInP,
  stPark_RPCSuc,
  stPark_SLActJudge,
  stPark_SLRun,
  stPark_SLPosSuc,
  stPark_SLPosAlve,
  stPark_SLPosMid,
  stPark_SLRetry,
  stPark_SLMotorAcc,
  stPark_SLWait,
  stPark_SLFnh,
  stPark_SLFault,
  stPark_BCInit,
  stPark_BCOutP,
  stPark_BCInP,
  stPark_BCRun,
  stPark_BCFault
} iEDS_Enum_stEPPSm_def;

#endif

#ifndef DEFINED_TYPEDEF_FOR_iEDS_Enum_stEPPCtl_def_
#define DEFINED_TYPEDEF_FOR_iEDS_Enum_stEPPCtl_def_

typedef enum {
  stParkCtl_Halt = 0,                  /* Default value */
  stParkCtl_Normal,
  stParkCtl_Retry,
  stParkCtl_SelfLearn,
  stParkCtl_Blind
} iEDS_Enum_stEPPCtl_def;

#endif
#endif                                 /* RTW_HEADER_SWC_PCF_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
