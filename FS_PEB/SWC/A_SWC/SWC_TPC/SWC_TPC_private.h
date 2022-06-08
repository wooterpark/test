/*
 * File: SWC_TPC_private.h
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

#ifndef RTW_HEADER_SWC_TPC_private_h_
#define RTW_HEADER_SWC_TPC_private_h_
#include "rtwtypes.h"
#include "SWC_TPC.h"

extern const float32 rtCP_pooled_ql5zQ4h8iTSR[561];
extern const float32 rtCP_pooled_WDXHwAzWNUP4[33];
extern const float32 rtCP_pooled_Yv73sTDj9iJR[17];
extern const uint32 rtCP_pooled_g1xfL3KrJTm2[2];
extern const uint32 rtCP_pooled_My5wKaBX7VxP[2];
extern const uint32 rtCP_pooled_FId2DsqWqW8M[2];

#define rtCP_uDLookupTable_tableData   rtCP_pooled_ql5zQ4h8iTSR  /* Expression: CAL_TpcSmp_PowerLosTableZ_PwrLos_af32
                                                                  * Referenced by: '<S152>/2-D Lookup Table'
                                                                  */
#define rtCP_uDLookupTable_bp01Data    rtCP_pooled_WDXHwAzWNUP4  /* Expression: CAL_TpcSmp_PowerLosTableX_pwr_af32
                                                                  * Referenced by: '<S152>/2-D Lookup Table'
                                                                  */
#define rtCP_uDLookupTable_bp02Data    rtCP_pooled_Yv73sTDj9iJR  /* Expression: CAL_TpcSmp_PowerLosTableY_spd_af32
                                                                  * Referenced by: '<S152>/2-D Lookup Table'
                                                                  */
#define rtCP_uDLookupTable_tableData_d rtCP_pooled_ql5zQ4h8iTSR  /* Expression: CAL_TpcSmp_PowerLosTableZ_PwrLos_af32
                                                                  * Referenced by: '<S161>/2-D Lookup Table'
                                                                  */
#define rtCP_uDLookupTable_bp01Data_b  rtCP_pooled_WDXHwAzWNUP4  /* Expression: CAL_TpcSmp_PowerLosTableX_pwr_af32
                                                                  * Referenced by: '<S161>/2-D Lookup Table'
                                                                  */
#define rtCP_uDLookupTable_bp02Data_b  rtCP_pooled_Yv73sTDj9iJR  /* Expression: CAL_TpcSmp_PowerLosTableY_spd_af32
                                                                  * Referenced by: '<S161>/2-D Lookup Table'
                                                                  */
#define rtCP_uDLookupTable_maxIndex    rtCP_pooled_g1xfL3KrJTm2  /* Computed Parameter: rtCP_uDLookupTable_maxIndex
                                                                  * Referenced by: '<S152>/2-D Lookup Table'
                                                                  */
#define rtCP_uDLookupTable_maxIndex_c  rtCP_pooled_g1xfL3KrJTm2  /* Computed Parameter: rtCP_uDLookupTable_maxIndex_c
                                                                  * Referenced by: '<S161>/2-D Lookup Table'
                                                                  */
#define rtCP_GenExCTable_maxIndex      rtCP_pooled_My5wKaBX7VxP  /* Computed Parameter: rtCP_GenExCTable_maxIndex
                                                                  * Referenced by: '<S116>/GenExCTable'
                                                                  */
#define rtCP_ElecExCTable_maxIndex     rtCP_pooled_My5wKaBX7VxP  /* Computed Parameter: rtCP_ElecExCTable_maxIndex
                                                                  * Referenced by: '<S116>/ElecExCTable'
                                                                  */
#define rtCP_CoolantFlow2L_maxIndex    rtCP_pooled_FId2DsqWqW8M  /* Computed Parameter: rtCP_CoolantFlow2L_maxIndex
                                                                  * Referenced by: '<S7>/CoolantFlow2L'
                                                                  */
#define rtCP_CoolantFlow4L_maxIndex    rtCP_pooled_FId2DsqWqW8M  /* Computed Parameter: rtCP_CoolantFlow4L_maxIndex
                                                                  * Referenced by: '<S7>/CoolantFlow4L'
                                                                  */
#define rtCP_CoolantFlow6L_maxIndex    rtCP_pooled_FId2DsqWqW8M  /* Computed Parameter: rtCP_CoolantFlow6L_maxIndex
                                                                  * Referenced by: '<S7>/CoolantFlow6L'
                                                                  */

extern void SWC_TPC_GetHighTemp_Init(float32 *rty_TModuleTempHighest);
extern void SWC_TPC_GetHighTemp(float32 rtu_TModuletemp, float32
  rtu_TModuletempDly, float32 *rty_TModuleTempHighest);

#endif                                 /* RTW_HEADER_SWC_TPC_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
