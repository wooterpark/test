/*
 * File: SWC_TRSP_private.h
 *
 * Code generated for Simulink model 'SWC_TRSP'.
 *
 * Model version                  : 1.875
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Thu Jan 13 11:26:53 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_SWC_TRSP_private_h_
#define RTW_HEADER_SWC_TRSP_private_h_
#include "rtwtypes.h"
#include "SWC_TRSP.h"

extern const float32 rtCP_pooled_IHWa07uMFLto[16];
extern const float32 rtCP_pooled_CANa91mi8sAl[16];

#define rtCP_Constant1_Value_p         rtCP_pooled_IHWa07uMFLto  /* Computed Parameter: rtCP_Constant1_Value_p
                                                                  * Referenced by: '<S56>/Constant1'
                                                                  */
#define rtCP_Constant2_Value           rtCP_pooled_CANa91mi8sAl  /* Computed Parameter: rtCP_Constant2_Value
                                                                  * Referenced by: '<S56>/Constant2'
                                                                  */
#define rtCP_Constant5_Value           rtCP_pooled_CANa91mi8sAl  /* Computed Parameter: rtCP_Constant5_Value
                                                                  * Referenced by: '<S56>/Constant5'
                                                                  */
#define rtCP_Constant7_Value           rtCP_pooled_IHWa07uMFLto  /* Computed Parameter: rtCP_Constant7_Value
                                                                  * Referenced by: '<S56>/Constant7'
                                                                  */
#define rtCP_Constant3_Value           rtCP_pooled_CANa91mi8sAl  /* Computed Parameter: rtCP_Constant3_Value
                                                                  * Referenced by: '<S56>/Constant3'
                                                                  */
#define rtCP_Constant4_Value           rtCP_pooled_IHWa07uMFLto  /* Computed Parameter: rtCP_Constant4_Value
                                                                  * Referenced by: '<S56>/Constant4'
                                                                  */
#define rtCP_Constant6_Value           rtCP_pooled_CANa91mi8sAl  /* Computed Parameter: rtCP_Constant6_Value
                                                                  * Referenced by: '<S56>/Constant6'
                                                                  */
#define rtCP_Constant8_Value           rtCP_pooled_IHWa07uMFLto  /* Computed Parameter: rtCP_Constant8_Value
                                                                  * Referenced by: '<S56>/Constant8'
                                                                  */

extern void SWC_TRSP_Count(boolean rtu_Enable, sint16 rtu_CountTrh, sint16
  *rty_Count, DW_Count_SWC_TRSP_T *localDW);
extern boolean SWC_TRSP_Debouncer11(boolean rtu_BooleanIN, boolean rtu_Rst,
  sint16 rtu_CountTrh, sint16 rtu_DebTrh, B_Debouncer11_SWC_TRSP_T *localB,
  DW_Debouncer11_SWC_TRSP_T *localDW);
extern boolean SWC_TRSP_RngChk(uint16 rtu_TRSP_RngChkVal, uint16 rtu_TRSP_HiTrh,
  uint16 rtu_TRSP_LoTrh);
extern boolean SWC_TRSP_RngChk_k(float32 rtu_TRSP_RngChkVal, float32
  rtu_TRSP_HiTrh, float32 rtu_TRSP_LoTrh);
extern void SWC_TRSP_RslvRngChk(const uint16 rtu_L2Sampling_Rslv_VADC[32],
  uint16 rtu_TRSP_HiTrh, uint16 rtu_TRSP_LoTrh, boolean *rty_TRSP_RslvRngChkRslt,
  uint16 *rty_L2Sampling_Rslv_VADC_Max, uint16 *rty_L2Sampling_Rslv_VADC_Min);
extern void SWC_TRSP_Debouncer(boolean rtu_BooleanIN, boolean rtu_Rst, sint16
  rtu_CountTrh, sint16 rtu_DebTrh, boolean *rty_OutLock, sint16 *rty_Count,
  sint16 *rty_Deb, DW_Debouncer_SWC_TRSP_T *localDW);
extern boolean SWC_TRSP_OfstRngChk(float32 rtu_TRSP_OfstRngChkVal, float32
  rtu_TRSP_HiTrh, float32 rtu_TRSP_LoTrh);
extern void SWC_TRSP_AgRtrCalc(void);
extern void SWC_TRSP_CurrSumChk(void);
extern void SWC_TRSP_iPhaCalc(void);
extern void SWC_TRSP_RslvSigCalc(void);
extern void SWC_TRSP_RslvSqrtChk(void);
extern void SWC_TRSP_UBRVoltCompChk(void);
extern void SWC_TRSP_UBR_SBCVoltCalc(void);
extern void SWC_TRSP_Lock(void);
extern void SWC_TRSP_100us(void);
extern void SWC_TRSP_1ms(void);
extern void SWC_TRSP_10ms(void);

#endif                                 /* RTW_HEADER_SWC_TRSP_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
