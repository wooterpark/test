/*
 * File: SWC_TCF_private.h
 *
 * Code generated for Simulink model 'SWC_TCF'.
 *
 * Model version                  : 1.571
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Wed Jan 12 17:04:24 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_SWC_TCF_private_h_
#define RTW_HEADER_SWC_TCF_private_h_
#include "rtwtypes.h"
#include "SWC_TCF.h"

extern const float32 rtCP_pooled_lRa8o5hRGBX2[4096];
extern const float32 rtCP_pooled_7EBUHCewpktf[4096];
extern const uint32 rtCP_pooled_15wuF2dardNf[2];
extern const uint32 rtCP_pooled_xyWvZOEZV268[2];

#define rtCP_LookupCosTable_table      rtCP_pooled_lRa8o5hRGBX2  /* Expression: Tbl_cos_table
                                                                  * Referenced by: '<S9>/LookupCosTable'
                                                                  */
#define rtCP_LookupSinTable_table      rtCP_pooled_7EBUHCewpktf  /* Expression: Tbl_sin_table
                                                                  * Referenced by: '<S9>/LookupSinTable'
                                                                  */
#define rtCP_LdSubLqGen_L2_maxIndex    rtCP_pooled_15wuF2dardNf  /* Computed Parameter: rtCP_LdSubLqGen_L2_maxIndex
                                                                  * Referenced by: '<S10>/LdSubLqGen_L2'
                                                                  */
#define rtCP_LdSubLqMot_L2_maxIndex    rtCP_pooled_15wuF2dardNf  /* Computed Parameter: rtCP_LdSubLqMot_L2_maxIndex
                                                                  * Referenced by: '<S10>/LdSubLqMot_L2'
                                                                  */
#define rtCP_IS_N_Ploss_T_maxIndex     rtCP_pooled_xyWvZOEZV268  /* Computed Parameter: rtCP_IS_N_Ploss_T_maxIndex
                                                                  * Referenced by: '<S25>/IS_N_Ploss_T'
                                                                  */

extern void SWC_TCF_Subsystem(boolean rtu_Enable, sint16 rtu_CountTrh, sint16
  *rty_Count, DW_Subsystem_SWC_TCF_T *localDW);
extern void SWC_TCF_Debouncer(boolean rtu_BooleanIN, boolean rtu_Rst, sint16
  rtu_CountTrh, sint16 rtu_DebTrh, boolean *rty_OutLock, sint16 *rty_Count,
  sint16 *rty_Deb, DW_Debouncer_SWC_TCF_T *localDW);
extern void SWC_TCF_Debouncer_l(boolean rtu_BooleanIN, boolean rtu_Rst, sint16
  rtu_CountTrh, sint16 rtu_DebTrh, boolean *rty_OutLock, B_Debouncer_SWC_TCF_m_T
  *localB, DW_Debouncer_SWC_TCF_p_T *localDW);
extern void SWC_TCF_CurrAgTrqCalc(void);
extern void SWC_TCF_IdIqCalc(void);
extern void SWC_TCF_LdsubLqCalc(void);
extern void SWC_TCF_MotorModeJdg_Init(void);
extern void SWC_TCF_MotorModeJdg(void);
extern void SWC_TCF_IsCalc(void);
extern void SWC_TCF_PinputCalc(void);
extern void SWC_TCF_PlossCalc(void);
extern void SWC_TCF_PwrTrqCalc(void);
extern void SWC_TCF_TrqBlend(void);
extern void SWC_TCF_TrqTube(void);
extern void SWC_TCF_1ms(void);

#endif                                 /* RTW_HEADER_SWC_TCF_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
