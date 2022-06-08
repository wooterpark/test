/*
 * File: SWC_MPC.h
 *
 * Code generated for Simulink model 'SWC_MPC'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Tue Jan 26 11:54:33 2021
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_SWC_MPC_h_
#define RTW_HEADER_SWC_MPC_h_
#include <math.h>
#ifndef SWC_MPC_COMMON_INCLUDES_
# define SWC_MPC_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_SWC_MPC.h"
#endif                                 /* SWC_MPC_COMMON_INCLUDES_ */

#include "SWC_MPC_types.h"

/* Macros for accessing real-time model data structure */

/* Exported data define */

/* Definition for custom storage class: Define */
#define MPC_GLB_MotorPole_u8           4U                        /* Referenced by: '<S9>/MPC_GLB_MotorPole_u8' */
#define MPC_GLB_SqrtTwo_f32            1.41421294F               /* Referenced by: '<S18>/Constant' */

/* 扭矩监控损耗系数 */
#define MPC_GLB_pi_f32                 3.14159203F               /* Referenced by:
                                                                  * '<S12>/Constant2'
                                                                  * '<S20>/Constant2'
                                                                  * '<S22>/Constant2'
                                                                  * '<S23>/Constant2'
                                                                  * '<S24>/Constant2'
                                                                  * '<S25>/Constant2'
                                                                  */
#define PRV_CalFltFrq_2ms              500.0F                    /* Referenced by:
                                                                  * '<S9>/PRV_CalFltFrq_10ms_3'
                                                                  * '<S15>/PRV_CalFltFrq_2ms'
                                                                  * '<S15>/PRV_CalFltFrq_2ms_1'
                                                                  * '<S15>/PRV_CalFltFrq_2ms_2'
                                                                  * '<S15>/PRV_CalFltFrq_2ms_3'
                                                                  * '<S15>/PRV_CalFltFrq_2ms_4'
                                                                  */

/* Block states (default storage) for system '<Root>' */
typedef struct tag_DW_SWC_MPC_T {
  float32 UnitDelay_DSTATE;            /* '<S22>/Unit Delay' */
  float32 UnitDelay_DSTATE_e;          /* '<S23>/Unit Delay' */
  float32 UnitDelay_DSTATE_er;         /* '<S12>/Unit Delay' */
  float32 UnitDelay_DSTATE_i;          /* '<S24>/Unit Delay' */
  float32 UnitDelay_DSTATE_b;          /* '<S25>/Unit Delay' */
  float32 UnitDelay_DSTATE_l;          /* '<S20>/Unit Delay' */
  boolean UnitDelay_DSTATE_lj;         /* '<S36>/Unit Delay' */
} DW_SWC_MPC_T;

/* Block states (default storage) */
extern DW_SWC_MPC_T SWC_MPC_DW;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern float32 VAR_MPC_TrqMon_f32;     /* '<S17>/Switch' */
extern float32 VAR_MPC_CofRandomPwm_f32;/* '<S14>/CofRpwm_table' */
extern float32 VAR_MPC_frqPwmVF_f32;   /* '<S18>/VFTable' */

/* Exported data declaration */
#pragma section ".rodata.Calib_32"

/* Declaration for custom storage class: iEDS_Parameter */
extern const volatile float32 CAL_MPC_CofUdc_f32;
                                 /* Referenced by: '<S17>/CAL_MPC_CofUdc_f32' */

/* 扭矩监控电压补偿系数 */
extern const volatile float32 CAL_MPC_IsCutOffFrq_f32;
                            /* Referenced by: '<S15>/CAL_MPC_IsCutOffFrq_f32' */
extern const volatile float32 CAL_MPC_LdSubLqCAx_af32[18];/* Referenced by:
                                                           * '<S6>/LdSubLqGen'
                                                           * '<S6>/LdSubLqMot'
                                                           */
extern const volatile float32 CAL_MPC_LdSubLqCAy_af32[15];/* Referenced by:
                                                           * '<S6>/LdSubLqGen'
                                                           * '<S6>/LdSubLqMot'
                                                           */
extern const volatile float32 CAL_MPC_LdSubLqCAzGen_af32[270];/* Referenced by: '<S6>/LdSubLqGen' */
extern const volatile float32 CAL_MPC_LdSubLqCAzMot_af32[270];/* Referenced by: '<S6>/LdSubLqMot' */
extern const volatile float32 CAL_MPC_Ld_f32;
                                      /* Referenced by: '<S6>/CAL_MPC_Ld_f32' */
extern const volatile float32 CAL_MPC_Lq_f32;
                                      /* Referenced by: '<S6>/CAL_MPP_Lq_f32' */
extern const volatile float32 CAL_MPC_MtpaTableX_Trq_af32[15];
                                  /* Referenced by: '<S19>/MPC_MtpaTable_Trq' */
extern const volatile float32 CAL_MPC_MtpaTableY_isd_af32[15];
                                  /* Referenced by: '<S19>/MPC_MtpaTable_Trq' */
extern const volatile float32 CAL_MPC_MtpvTableX_Udc_af32[8];/* Referenced by:
                                                              * '<S19>/MTPV_Gen'
                                                              * '<S19>/MTPV_Mot'
                                                              */
extern const volatile float32 CAL_MPC_MtpvTableY_N_af32[19];/* Referenced by:
                                                             * '<S19>/MTPV_Gen'
                                                             * '<S19>/MTPV_Mot'
                                                             */
extern const volatile float32 CAL_MPC_MtpvTableZ_idGen_af32[152];/* Referenced by: '<S19>/MTPV_Gen' */
extern const volatile float32 CAL_MPC_MtpvTableZ_idMot_af32[152];/* Referenced by: '<S19>/MTPV_Mot' */
extern const volatile float32 CAL_MPC_OmbwTableX_Spd_af32[11];
                                     /* Referenced by: '<S19>/MPC_Ombw_Table' */
extern const volatile float32 CAL_MPC_OmbwTableY_Ombw_af32[11];
                                     /* Referenced by: '<S19>/MPC_Ombw_Table' */
extern const volatile float32 CAL_MPC_Psi_f32;
                                     /* Referenced by: '<S7>/CAL_MPC_Psi_f32' */
extern const volatile float32 CAL_MPC_Rcmp_f32;
                                   /* Referenced by: '<S17>/CAL_MPC_Rcmp_f32' */

/* 扭矩监控电阻补偿 */
extern const volatile float32 CAL_MPC_Rs_f32;
                                      /* Referenced by: '<S8>/CAL_MPC_Rs_f32' */
extern const volatile float32 CAL_MPC_RvTableX_Spd_af32[11];/* Referenced by: '<S19>/MPC_Rv_Table' */
extern const volatile float32 CAL_MPC_RvTableY_Rv_af32[11];/* Referenced by: '<S19>/MPC_Rv_Table' */
extern const volatile float32 CAL_MPC_TrqMechCutOffFrq_f32;
                        /* Referenced by: '<S9>/CAL_MPC_TrqMechCutOffFrq_f32' */
extern const volatile float32 CAL_MPC_cofRpwm_Y_af32[17];
                                      /* Referenced by: '<S14>/CofRpwm_table' */

/* 随机PWM频率系数查表X轴转速 */
extern const volatile boolean CAL_MPC_flgDesOrAct_b;
                               /* Referenced by: '<S6>/CAL_MPC_flgDesOrAct_b' */
extern const volatile boolean CAL_MPC_flgUseLdSubLq_b;
                             /* Referenced by: '<S6>/CAL_MPC_flgUseLdSubLq_b' */
extern const volatile boolean CAL_MPC_flgUseLdq_b;
                                 /* Referenced by: '<S6>/CAL_MPC_flgUseLdq_b' */
extern const volatile boolean CAL_MPC_flgUseRs_b;
                                  /* Referenced by: '<S8>/CAL_MPC_flgUseRs_b' */
extern const volatile float32 CAL_MPC_frqPwmVFTableX_Is_af32[11];/* Referenced by: '<S18>/VFTable' */

/* 变载频查表X轴相电流幅值 */
extern const volatile float32 CAL_MPC_frqPwmVFTableY_VoltModuRate_af32[13];/* Referenced by: '<S18>/VFTable' */

/* 变载频查表Y轴电压调制度 */
extern const volatile float32 CAL_MPC_frqPwmVFTableZ_Frq_af32[143];/* Referenced by: '<S18>/VFTable' */

/* 变载频查表Z轴载频频率 */
extern const volatile float32 CAL_MPC_idActCutOffFrq_f32;
                         /* Referenced by: '<S15>/CAL_MPC_idActCutOffFrq_f32' */
extern const volatile float32 CAL_MPC_iqActCutOffFrq_f32;
                         /* Referenced by: '<S15>/CAL_MPC_iqActCutOffFrq_f32' */
extern const volatile float32 CAL_MPC_isdFFTableX_Spd_af32[17];
                                 /* Referenced by: '<S19>/MPC_isdFFTable_isd' */
extern const volatile float32 CAL_MPC_isdFFTableX_Udc_af32[8];
                              /* Referenced by: '<S19>/MPC_isdFFTable_UdcCof' */
extern const volatile float32 CAL_MPC_isdFFTableY_Trq_af32[17];
                                 /* Referenced by: '<S19>/MPC_isdFFTable_isd' */
extern const volatile float32 CAL_MPC_isdFFTableY_UdcCof_af32[8];
                              /* Referenced by: '<S19>/MPC_isdFFTable_UdcCof' */
extern const volatile float32 CAL_MPC_isdFFTableZ_isd_af32[289];
                                 /* Referenced by: '<S19>/MPC_isdFFTable_isd' */
extern const volatile float32 CAL_MPC_nCofRpwm_X_af32[17];
                                      /* Referenced by: '<S14>/CofRpwm_table' */

/* 随机PWM频率系数查表Y轴频率系数值 */
extern const volatile float32 CAL_MPC_nSetTrqMonMin_f32;
                          /* Referenced by: '<S36>/CAL_MPC_nSetTrqMonMin_f32' */

/* 扭矩监控转速计算阈值 */
extern const volatile float32 CAL_MPC_nTrqMonMax_f32;
                             /* Referenced by: '<S36>/CAL_MPC_nTrqMonMax_f32' */

/* 开启扭矩监控转速滞环上限值阈值 */
extern const volatile float32 CAL_MPC_nTrqMonMin_f32;
                             /* Referenced by: '<S36>/CAL_MPC_nTrqMonMin_f32' */

/* 开启扭矩监控转速滞环下限阈值 */
extern const volatile float32 CAL_MPC_tCpnBwdGenTableX_n_af32[16];
                                   /* Referenced by: '<S31>/1-D Lookup Table' */

/* 后退发电查表开管时间补偿X轴速度 */
extern const volatile float32 CAL_MPC_tCpnBwdGenTableY_tCpn_af32[16];
                                   /* Referenced by: '<S31>/1-D Lookup Table' */

/* 后退发电查表开管时间补偿Y轴修正时间 */
extern const volatile float32 CAL_MPC_tCpnBwdMotTableX_n_af32[16];
                                   /* Referenced by: '<S32>/1-D Lookup Table' */

/* 后退电动查表开管时间补偿X轴速度 */
extern const volatile float32 CAL_MPC_tCpnBwdMotTableY_tCpn_af32[16];
                                   /* Referenced by: '<S32>/1-D Lookup Table' */

/* 后退电动查表开管时间补偿Y轴修正时间 */
extern const volatile float32 CAL_MPC_tCpnFwdGenTableX_n_af32[16];
                                   /* Referenced by: '<S34>/1-D Lookup Table' */

/* 前进发电查表开管时间补偿X轴速度 */
extern const volatile float32 CAL_MPC_tCpnFwdGenTableY_tCpn_af32[16];
                                   /* Referenced by: '<S34>/1-D Lookup Table' */

/* 前进发电查表开管时间补偿Y轴修正时间 */
extern const volatile float32 CAL_MPC_tCpnFwdMotTableX_n_af32[16];
                                   /* Referenced by: '<S35>/1-D Lookup Table' */

/* 前进电动查表开管时间补偿X轴速度 */
extern const volatile float32 CAL_MPC_tCpnFwdMotTableY_tCpn_af32[16];
                                   /* Referenced by: '<S35>/1-D Lookup Table' */

/* 前进电动查表开管时间补偿Y轴修正时间 */
extern const volatile float32 CAL_MPC_udActCutOffFrq_f32;
                         /* Referenced by: '<S15>/CAL_MPC_udActCutOffFrq_f32' */
extern const volatile float32 CAL_MPC_uqActCutOffFrq_f32;
                         /* Referenced by: '<S15>/CAL_MPC_uqActCutOffFrq_f32' */

#pragma section

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S13>/Data Type Duplicate' : Unused code path elimination
 * Block '<S13>/Data Type Propagation' : Unused code path elimination
 * Block '<S26>/Data Type Duplicate' : Unused code path elimination
 * Block '<S26>/Data Type Propagation' : Unused code path elimination
 * Block '<S27>/Data Type Duplicate' : Unused code path elimination
 * Block '<S27>/Data Type Propagation' : Unused code path elimination
 * Block '<S28>/Data Type Duplicate' : Unused code path elimination
 * Block '<S28>/Data Type Propagation' : Unused code path elimination
 * Block '<S29>/Data Type Duplicate' : Unused code path elimination
 * Block '<S29>/Data Type Propagation' : Unused code path elimination
 * Block '<S30>/Data Type Duplicate' : Unused code path elimination
 * Block '<S30>/Data Type Propagation' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'SWC_MPC'
 * '<S1>'   : 'SWC_MPC/RE_SWC_MPC_2ms_sys'
 * '<S2>'   : 'SWC_MPC/RE_SWC_MPC_Init'
 * '<S3>'   : 'SWC_MPC/RE_SWC_MPC_2ms_sys/Subsystem1'
 * '<S4>'   : 'SWC_MPC/RE_SWC_MPC_2ms_sys/Subsystem1/MCF_PMSM'
 * '<S5>'   : 'SWC_MPC/RE_SWC_MPC_2ms_sys/Subsystem1/MPC_Sig'
 * '<S6>'   : 'SWC_MPC/RE_SWC_MPC_2ms_sys/Subsystem1/MCF_PMSM/LdqCalc'
 * '<S7>'   : 'SWC_MPC/RE_SWC_MPC_2ms_sys/Subsystem1/MCF_PMSM/PsiCalc'
 * '<S8>'   : 'SWC_MPC/RE_SWC_MPC_2ms_sys/Subsystem1/MCF_PMSM/RsCalc'
 * '<S9>'   : 'SWC_MPC/RE_SWC_MPC_2ms_sys/Subsystem1/MCF_PMSM/TrqCalc1'
 * '<S10>'  : 'SWC_MPC/RE_SWC_MPC_2ms_sys/Subsystem1/MCF_PMSM/PsiCalc/Model Info1'
 * '<S11>'  : 'SWC_MPC/RE_SWC_MPC_2ms_sys/Subsystem1/MCF_PMSM/RsCalc/Model Info'
 * '<S12>'  : 'SWC_MPC/RE_SWC_MPC_2ms_sys/Subsystem1/MCF_PMSM/TrqCalc1/SPF_tDBCTempWFilter3'
 * '<S13>'  : 'SWC_MPC/RE_SWC_MPC_2ms_sys/Subsystem1/MCF_PMSM/TrqCalc1/SPF_tDBCTempWFilter3/Saturation Dynamic'
 * '<S14>'  : 'SWC_MPC/RE_SWC_MPC_2ms_sys/Subsystem1/MPC_Sig/MPC_CofRpwm'
 * '<S15>'  : 'SWC_MPC/RE_SWC_MPC_2ms_sys/Subsystem1/MPC_Sig/MPC_Flt'
 * '<S16>'  : 'SWC_MPC/RE_SWC_MPC_2ms_sys/Subsystem1/MPC_Sig/MPC_Sig'
 * '<S17>'  : 'SWC_MPC/RE_SWC_MPC_2ms_sys/Subsystem1/MPC_Sig/MPC_TrqMon'
 * '<S18>'  : 'SWC_MPC/RE_SWC_MPC_2ms_sys/Subsystem1/MPC_Sig/MPC_VF'
 * '<S19>'  : 'SWC_MPC/RE_SWC_MPC_2ms_sys/Subsystem1/MPC_Sig/MPC_isd'
 * '<S20>'  : 'SWC_MPC/RE_SWC_MPC_2ms_sys/Subsystem1/MPC_Sig/MPC_Flt/IsFlt'
 * '<S21>'  : 'SWC_MPC/RE_SWC_MPC_2ms_sys/Subsystem1/MPC_Sig/MPC_Flt/UsCalc'
 * '<S22>'  : 'SWC_MPC/RE_SWC_MPC_2ms_sys/Subsystem1/MPC_Sig/MPC_Flt/idFlt'
 * '<S23>'  : 'SWC_MPC/RE_SWC_MPC_2ms_sys/Subsystem1/MPC_Sig/MPC_Flt/iqFlt'
 * '<S24>'  : 'SWC_MPC/RE_SWC_MPC_2ms_sys/Subsystem1/MPC_Sig/MPC_Flt/udFlt'
 * '<S25>'  : 'SWC_MPC/RE_SWC_MPC_2ms_sys/Subsystem1/MPC_Sig/MPC_Flt/uqFlt'
 * '<S26>'  : 'SWC_MPC/RE_SWC_MPC_2ms_sys/Subsystem1/MPC_Sig/MPC_Flt/IsFlt/Saturation Dynamic'
 * '<S27>'  : 'SWC_MPC/RE_SWC_MPC_2ms_sys/Subsystem1/MPC_Sig/MPC_Flt/idFlt/Saturation Dynamic'
 * '<S28>'  : 'SWC_MPC/RE_SWC_MPC_2ms_sys/Subsystem1/MPC_Sig/MPC_Flt/iqFlt/Saturation Dynamic'
 * '<S29>'  : 'SWC_MPC/RE_SWC_MPC_2ms_sys/Subsystem1/MPC_Sig/MPC_Flt/udFlt/Saturation Dynamic'
 * '<S30>'  : 'SWC_MPC/RE_SWC_MPC_2ms_sys/Subsystem1/MPC_Sig/MPC_Flt/uqFlt/Saturation Dynamic'
 * '<S31>'  : 'SWC_MPC/RE_SWC_MPC_2ms_sys/Subsystem1/MPC_Sig/MPC_Sig/BwdGen_2'
 * '<S32>'  : 'SWC_MPC/RE_SWC_MPC_2ms_sys/Subsystem1/MPC_Sig/MPC_Sig/BwdMot_3'
 * '<S33>'  : 'SWC_MPC/RE_SWC_MPC_2ms_sys/Subsystem1/MPC_Sig/MPC_Sig/FwdGen_1'
 * '<S34>'  : 'SWC_MPC/RE_SWC_MPC_2ms_sys/Subsystem1/MPC_Sig/MPC_Sig/FwdGen_4'
 * '<S35>'  : 'SWC_MPC/RE_SWC_MPC_2ms_sys/Subsystem1/MPC_Sig/MPC_Sig/FwdMot_1'
 * '<S36>'  : 'SWC_MPC/RE_SWC_MPC_2ms_sys/Subsystem1/MPC_Sig/MPC_TrqMon/SpdSwitch'
 * '<S37>'  : 'SWC_MPC/RE_SWC_MPC_2ms_sys/Subsystem1/MPC_Sig/MPC_isd/Compare To Constant'
 * '<S38>'  : 'SWC_MPC/RE_SWC_MPC_2ms_sys/Subsystem1/MPC_Sig/MPC_isd/Compare To Constant1'
 */
#endif                                 /* RTW_HEADER_SWC_MPC_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
