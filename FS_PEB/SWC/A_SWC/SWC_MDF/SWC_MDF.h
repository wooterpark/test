/*
 * File: SWC_MDF.h
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

#ifndef RTW_HEADER_SWC_MDF_h_
#define RTW_HEADER_SWC_MDF_h_
#include <math.h>
#ifndef SWC_MDF_COMMON_INCLUDES_
# define SWC_MDF_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_SWC_MDF.h"
#endif                                 /* SWC_MDF_COMMON_INCLUDES_ */

#include "SWC_MDF_types.h"

/* Macros for accessing real-time model data structure */

/* Exported data define */

/* Definition for custom storage class: Define */
#define MDF_GLB_IGBTAscDwn_u8          2U                        /* Referenced by:
                                                                  * '<S43>/MDF_GLB_IGBTAscDwn_u8'
                                                                  * '<S60>/MDF_GLB_IGBTAscDwn_u8'
                                                                  */

/* IGBT下桥短路状态 */
#define MDF_GLB_IGBTAscUp_u8           1U                        /* Referenced by:
                                                                  * '<S43>/MDF_GLB_IGBTAscUp_u8'
                                                                  * '<S60>/MDF_GLB_IGBTAscUp_u8'
                                                                  */

/* IGBT上桥短路状态 */
#define MDF_GLB_IGBTclose_u8           0U                        /* Referenced by: '<S40>/MDF_GLB_IGBTclose_u8' */
#define MDF_GLB_IGBTrun_u8             3U                        /* Referenced by:
                                                                  * '<S15>/MDF_GLB_IGBTrun_u8'
                                                                  * '<S30>/MDF_GLB_IGBTrun_u8'
                                                                  * '<S36>/MDF_GLB_IGBTrun_u8'
                                                                  * '<S46>/MDF_GLB_IGBTrun_u8'
                                                                  * '<S56>/MDF_GLB_IGBTrun_u8'
                                                                  * '<S70>/MDF_GLB_IGBTrun_u8'
                                                                  */

/* PWM run状态 */
#define MDF_GLB_MaxTrq_f32             310.0F                    /* Referenced by: '<S34>/MDF_GLB_MaxTrq_f32' */

/* 扭矩最大值 */
#define MDF_GLB_MotorPole_u8           4U                        /* Referenced by: '<S5>/MDF_GLB_MotorPole_u8' */
#define MDF_GLB_pi_f32                 3.14159203F               /* Referenced by:
                                                                  * '<S62>/MDF_GLB_pi_f32'
                                                                  * '<S63>/MDF_GLB_pi_f32'
                                                                  * '<S64>/MDF_GLB_pi_f32'
                                                                  * '<S18>/MDF_GLB_pi_f32'
                                                                  * '<S22>/MDF_GLB_pi_f32'
                                                                  */

/* GLB_Pi */

/* Block signals (default storage) */
typedef struct tag_B_SWC_MDF_T {
  uint8 Switch1_d;                     /* '<S59>/Switch1' */
  uint8 Switch1_k;                     /* '<S58>/Switch1' */
  uint8 Switch1_g;                     /* '<S48>/Switch1' */
  uint8 Switch2;                       /* '<S45>/Switch2' */
  uint8 Switch2_k;                     /* '<S42>/Switch2' */
  uint8 Switch1_p;                     /* '<S39>/Switch1' */
  uint8 Switch1_gg;                    /* '<S38>/Switch1' */
  uint8 Switch5;                       /* '<S31>/Switch5' */
  uint8 Switch2_n;                     /* '<S31>/Switch2' */
  uint8 Switch1_n;                     /* '<S17>/Switch1' */
} B_SWC_MDF_T;

/* Block states (default storage) for system '<Root>' */
typedef struct tag_DW_SWC_MDF_T {
  float32 UnitDelay1_DSTATE;           /* '<S19>/Unit Delay1' */
  float32 UnitDelay_DSTATE;            /* '<S74>/Unit Delay' */
  float32 UnitDelay_DSTATE_j;          /* '<S72>/Unit Delay' */
  float32 UnitDelay_DSTATE_d;          /* '<S71>/Unit Delay' */
  float32 UnitDelay_DSTATE_g;          /* '<S73>/Unit Delay' */
  float32 UnitDelay_DSTATE_i;          /* '<S50>/Unit Delay' */
  float32 UnitDelay1_DSTATE_f;         /* '<S50>/Unit Delay1' */
  float32 UnitDelay2_DSTATE;           /* '<S50>/Unit Delay2' */
  float32 UnitDelay3_DSTATE;           /* '<S50>/Unit Delay3' */
  float32 UnitDelay_DSTATE_jv;         /* '<S51>/Unit Delay' */
  float32 UnitDelay1_DSTATE_a;         /* '<S51>/Unit Delay1' */
  float32 UnitDelay2_DSTATE_c;         /* '<S51>/Unit Delay2' */
  float32 UnitDelay3_DSTATE_b;         /* '<S51>/Unit Delay3' */
  float32 UnitDelay_DSTATE_gl;         /* '<S52>/Unit Delay' */
  float32 UnitDelay1_DSTATE_m;         /* '<S52>/Unit Delay1' */
  float32 UnitDelay2_DSTATE_n;         /* '<S52>/Unit Delay2' */
  float32 UnitDelay3_DSTATE_k;         /* '<S52>/Unit Delay3' */
  float32 UnitDelay1_DSTATE_h;         /* '<S49>/Unit Delay1' */
  float32 UnitDelay1_DSTATE_hq;        /* '<S35>/Unit Delay1' */
  float32 UnitDelay2_DSTATE_b;         /* '<S33>/Unit Delay2' */
  float32 UnitDelay_DSTATE_m;          /* '<S22>/Unit Delay' */
  float32 UnitDelay1_DSTATE_aj;        /* '<S20>/Unit Delay1' */
  uint8 UnitDelay_DSTATE_h;            /* '<S62>/Unit Delay' */
  boolean UnitDelay2_DSTATE_o;         /* '<S19>/Unit Delay2' */
  boolean UnitDelay2_DSTATE_a;         /* '<S49>/Unit Delay2' */
  boolean UnitDelay_DSTATE_b;          /* '<S39>/Unit Delay' */
  boolean UnitDelay2_DSTATE_p;         /* '<S35>/Unit Delay2' */
  boolean UnitDelay5_DSTATE;           /* '<S33>/Unit Delay5' */
  boolean UnitDelay4_DSTATE;           /* '<S33>/Unit Delay4' */
  boolean UnitDelay1_DSTATE_fu;        /* '<S33>/Unit Delay1' */
  boolean UnitDelay2_DSTATE_ag;        /* '<S20>/Unit Delay2' */
  boolean Pwr3PhaCmp_MODE;             /* '<S13>/Pwr3PhaCmp' */
  boolean PhaseFaultCalc_MODE;         /* '<S12>/PhaseFaultCalc' */
  boolean EMBlk_MODE;                  /* '<S7>/EMBlk' */
} DW_SWC_MDF_T;

/* Block signals (default storage) */
extern B_SWC_MDF_T SWC_MDF_B;

/* Block states (default storage) */
extern DW_SWC_MDF_T SWC_MDF_DW;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern float32 VAR_MDF_OffSetSiteAObs_f32;/* '<S18>/Abs' */
extern float32 VAR_MDF_OffSetSiteBObs_f32;/* '<S18>/Abs1' */
extern float32 VAR_MDF_offsetDeltaObs_f32;/* '<S18>/Add2' */
extern float32 VAR_MDF_3PhaUnbalanceObs_f32;/* '<S53>/Divide' */
extern float32 VAR_MDF_offsetDeltaFlt_f32;/* '<S21>/Abs1' */
extern uint8 VAR_MDF_AlOfsNoPlausState_u8;
               /* '<S1>/RP_SWC_FIM_MDF_AlOfsNoPlausErr_GetFunctionPermission' */
extern uint8 VAR_MDF_DiashCirNoPsblState_u8;
             /* '<S1>/RP_SWC_FIM_MDF_DiashCirNoPsblErr_GetFunctionPermission' */
extern uint8 VAR_MDF_EmacBlkdState_u8;
                  /* '<S1>/RP_SWC_FIM_MDF_EmacBlkdWarn_GetFunctionPermission' */
extern uint8 VAR_MDF_ICtlRatState_u8;
                       /* '<S1>/RP_SWC_FIM_MDF_IctlRat_GetFunctionPermission' */
extern uint8 VAR_MDF_OpenCirNoPsblState_u8;
              /* '<S1>/RP_SWC_FIM_MDF_OpenCirNoPsblErr_GetFunctionPermission' */
extern uint8 VAR_MDF_OperOutdRngState_u8;
                /* '<S1>/RP_SWC_FIM_MDF_OperOutdRngErr_GetFunctionPermission' */
extern uint8 VAR_MDF_PhaseFaultState_u8;
             /* '<S1>/RP_SWC_FIM_MDF_PhaseLossFaultErr_GetFunctionPermission' */
extern uint8 VAR_MDF_PrfElDrvState_u8;
              /* '<S1>/RP_SWC_FIM_MDF_DiagPrfChkElecDt_GetFunctionPermission' */
extern boolean VAR_MDF_bAlOfsChk_b;    /* '<S19>/Logical Operator1' */
extern boolean VAR_MDF_bstGateDrvShCir_b;/* '<S60>/Logical Operator' */
extern boolean VAR_MDF_bEMBlkChk_b;    /* '<S30>/Logical Operator1' */
extern boolean VAR_MDF_bICtlRatChk_b;  /* '<S36>/Logical Operator1' */
extern boolean VAR_MDF_bstGateDrvOpenCir_b;/* '<S40>/Logical Operator' */
extern boolean VAR_MDF_flagOperOutdRngChk_b;/* '<S43>/Logical Operator' */
extern boolean VAR_MDF_PhaseFaultChk_b;/* '<S46>/Logical Operator1' */
extern boolean VAR_MDF_bPwrCmpDFCCalc_b;/* '<S56>/Logical Operator' */
extern boolean VAR_MDF_bshCirNoPsblFaul_b;/* '<S59>/Logical Operator' */
extern boolean VAR_MDF_bFaultPwrCmp_b; /* '<S58>/Relational Operator6' */
extern boolean VAR_MDF_bPhaseFault_b;  /* '<S49>/Logical Operator1' */
extern boolean VAR_MDF_flagOperOutdRngFault_b;/* '<S45>/Logical Operator' */
extern boolean VAR_MDF_bOpenCirNoPsblFault_b;/* '<S42>/Logical Operator' */
extern boolean VAR_MDF_bIsOvHiFault_b; /* '<S39>/Relational Operator' */
extern boolean VAR_MDF_bFaultICtlChk_b;/* '<S38>/Logical Operator' */
extern boolean VAR_MDF_bFaultEMBlkWarn_b;/* '<S34>/Logical Operator3' */
extern boolean VAR_MDF_bFaultEMBlkErr_b;/* '<S33>/Switch6' */
extern boolean VAR_MDF_bAlfOfsNoPlauseFault_b;/* '<S20>/Logical Operator1' */

/* Exported data declaration */
#pragma section ".rodata.Calib_32"

/* Declaration for custom storage class: iEDS_Parameter */
extern const volatile float32 CAL_MDF_3PhaUnbalance_f32;
                          /* Referenced by: '<S53>/CAL_MDF_3PhaUnbalance_f32' */

/* 三相不平衡度阈值 */
extern const volatile float32 CAL_MDF_DIffAlOfsMax_f32;
                           /* Referenced by: '<S21>/CAL_MDF_DIffAlOfsMax_f32' */

/* 角度差值阈值 */
extern const volatile float32 CAL_MDF_EMBlkWarn_f32;
                              /* Referenced by: '<S34>/CAL_MDF_EMBlkWarn_f32' */

/* 堵转警告扭矩比例系数 */
extern const volatile float32 CAL_MDF_FwWiIs_f32;
                                 /* Referenced by: '<S42>/CAL_MDF_FwWiIs_f32' */
extern const volatile float32 CAL_MDF_FwWoIs_f32;
                                 /* Referenced by: '<S42>/CAL_MDF_FwWoIs_f32' */
extern const volatile uint8 CAL_MDF_Inactive_u8;
                                /* Referenced by: '<S43>/CAL_MDF_Inactive_u8' */
extern const volatile float32 CAL_MDF_IsErrFlt_f32;
                               /* Referenced by: '<S71>/CAL_MDF_IsErrFlt_f32' */
extern const volatile float32 CAL_MDF_IsErrThres_f32;
                             /* Referenced by: '<S38>/CAL_MDF_IsErrThres_f32' */

/* 电流合理性电流差值阈值 */
extern const volatile float32 CAL_MDF_IsMaxSet_f32;
                               /* Referenced by: '<S39>/CAL_MDF_IsMaxSet_f32' */

/* 相电流最大值设定值 */
extern const volatile float32 CAL_MDF_IsPhaseFault_f32;
                           /* Referenced by: '<S46>/CAL_MDF_IsPhaseFault_f32' */

/* 缺相诊断Is阈值 */
extern const volatile float32 CAL_MDF_IsThreshCirNoPsbl_f32;
                      /* Referenced by: '<S59>/CAL_MDF_IsThreshCirNoPsbl_f32' */

/* 无法主动短路Is阈值 */
extern const volatile float32 CAL_MDF_OfsDeltaAgFltFrq_f32;
                       /* Referenced by: '<S21>/CAL_MDF_OfsDeltaAgFltFrq_f32' */

/* 偏移角度差值滤波频率 */
extern const volatile float32 CAL_MDF_Pwr3PhaFlt_f32;
                             /* Referenced by: '<S72>/CAL_MDF_Pwr3PhaFlt_f32' */
extern const volatile float32 CAL_MDF_PwrDcLinkEstFlt_f32;
                        /* Referenced by: '<S74>/CAL_MDF_PwrDcLinkEstFlt_f32' */
extern const volatile float32 CAL_MDF_PwrLoss_X_af32[2];
                           /* Referenced by: '<S66>/2-D powloss lookup Table' */
extern const volatile float32 CAL_MDF_PwrLoss_Y_af32[2];
                           /* Referenced by: '<S66>/2-D powloss lookup Table' */
extern const volatile float32 CAL_MDF_PwrLoss_Z_af32[4];
                           /* Referenced by: '<S66>/2-D powloss lookup Table' */
extern const volatile float32 CAL_MDF_UdcFwMin_f32;
                               /* Referenced by: '<S62>/CAL_MDF_UdcFwMin_f32' */

/* Freewheel状态判断电压阈值 */
extern const volatile float32 CAL_MDF_UdcThreshCirNoPsbl_f32;
                     /* Referenced by: '<S59>/CAL_MDF_UdcThreshCirNoPsbl_f32' */

/* 无法主动短路电压阈值 */
extern const volatile float32 CAL_MDF_UsErrFlt_f32;
                               /* Referenced by: '<S73>/CAL_MDF_UsErrFlt_f32' */
extern const volatile float32 CAL_MDF_UsErrThres_f32;
                             /* Referenced by: '<S38>/CAL_MDF_UsErrThres_f32' */

/* 电流合理性电压差值阈值 */
extern const volatile float32 CAL_MDF_UsFrwhlMax_f32;
                             /* Referenced by: '<S62>/CAL_MDF_UsFrwhlMax_f32' */
extern const volatile float32 CAL_MDF_cErrPwrDcEstMax_f32;
                        /* Referenced by: '<S58>/CAL_MDF_cErrPwrDcEstMax_f32' */
extern const volatile float32 CAL_MDF_cofnAbsPhaseFault_Y_af32[46];
                                   /* Referenced by: '<S46>/1-D Lookup Table' */
extern const volatile float32 CAL_MDF_nAbsPhaseFault_X_af32[46];
                                   /* Referenced by: '<S46>/1-D Lookup Table' */
extern const volatile float32 CAL_MDF_nAbsPhaseFault_f32;
                         /* Referenced by: '<S46>/CAL_MDF_nAbsPhaseFault_f32' */

/* 缺相故障判断转速绝对值阈值 */
extern const volatile float32 CAL_MDF_nAbsThresOpenCirNoPsbl_f32;
                 /* Referenced by: '<S40>/CAL_MDF_nAbsThresOpenCirNoPsbl_f32' */
extern const volatile float32 CAL_MDF_nAbsThresblockedElMa_f32;
                   /* Referenced by: '<S34>/CAL_MDF_nAbsThresblockedElMa_f32' */

/* 堵转判断转速阈值 */
extern const volatile float32 CAL_MDF_nAbsThreshCirNoPsbl_f32;
                    /* Referenced by: '<S60>/CAL_MDF_nAbsThreshCirNoPsbl_f32' */

/* 无法主动短路检测转速阈值 */
extern const volatile float32 CAL_MDF_nDidMax_f32;
                                /* Referenced by: '<S56>/CAL_MDF_nDidMax_f32' */
extern const volatile float32 CAL_MDF_nDidMin_f32;
                                /* Referenced by: '<S56>/CAL_MDF_nDidMin_f32' */
extern const volatile float32 CAL_MDF_nThresAlOfsNoPlauseFaultMax_f32;
            /* Referenced by: '<S15>/CAL_MDF_nThresAlOfsNoPlauseFaultMax_f32' */

/* 角度合理性诊断转速阈值 */
extern const volatile float32 CAL_MDF_nThresAlOfsNoPlauseFaultMin_f32;
            /* Referenced by: '<S15>/CAL_MDF_nThresAlOfsNoPlauseFaultMin_f32' */

/* 角度合理性诊断转速阈值 */
extern const volatile float32 CAL_MDF_pwrDcDiaMin_f32;
                            /* Referenced by: '<S56>/CAL_MDF_pwrDcDiaMin_f32' */
extern const volatile uint8 CAL_MDF_stFrwhlPhd_u8;
                              /* Referenced by: '<S62>/CAL_MDF_stFrwhlPhd_u8' */
extern const volatile uint8 CAL_MDF_stFrwhlWiIs_u8;/* Referenced by:
                                                    * '<S62>/CAL_MDF_stFrwhlWiIs_u8'
                                                    * '<S42>/CAL_MDF_stFrwhlWiIs_u8'
                                                    */
extern const volatile uint8 CAL_MDF_stFrwhlWoIs_u8;/* Referenced by:
                                                    * '<S62>/CAL_MDF_stFrwhlWoIs_u8'
                                                    * '<S42>/CAL_MDF_stFrwhlWoIs_u8'
                                                    */
extern const volatile boolean CAL_MDF_tOperOutdRngSelState_b;
                     /* Referenced by: '<S43>/CAL_MDF_tOperOutdRngSelState_b' */

/* 温度传感器状态，后期关联FID */
extern const volatile float32 CAL_MDF_tThd_TempDBCInvCoolObsvr_f32;
               /* Referenced by: '<S45>/CAL_MDF_tThd_TempDBCInvCoolObsvr_f32' */
extern const volatile float32 CAL_MDF_tThd_TempDBCInvSens3Pha_f32;
                /* Referenced by: '<S45>/CAL_MDF_tThd_TempDBCInvSens3Pha_f32' */
extern const volatile float32 CAL_MDF_tThd_TempStr_f32;
                           /* Referenced by: '<S45>/CAL_MDF_tThd_TempStr_f32' */
extern const volatile float32 CAL_MDF_tiAgComp_f32;
                               /* Referenced by: '<S18>/CAL_MDF_tiAgComp_f32' */

/* 角度补偿时间 */
extern const volatile float32 CAL_MDF_tiAlfOfsNoPlauseFault_f32;
                  /* Referenced by: '<S20>/CAL_MDF_tiAlfOfsNoPlauseFault_f32' */

/* 角度合理性诊断延时时间 */
extern const volatile float32 CAL_MDF_tiEMBlk_f32;
                                /* Referenced by: '<S35>/CAL_MDF_tiEMBlk_f32' */

/* 进堵转限扭的堵转状态持续时间 */
extern const volatile float32 CAL_MDF_tiOffsetSteady_f32;
                         /* Referenced by: '<S19>/CAL_MDF_tiOffsetSteady_f32' */

/* 稳态时间阈值 */
extern const volatile float32 CAL_MDF_tiPhaFaultDelay_f32;
                        /* Referenced by: '<S49>/CAL_MDF_tiPhaFaultDelay_f32' */

/* 缺相诊断故障延时 */
extern const volatile float32 CAL_MDF_tiQuitEMBlk_f32;
                            /* Referenced by: '<S33>/CAL_MDF_tiQuitEMBlk_f32' */

/* 退出堵转转速大于阈值持续时间 */
extern const volatile float32 CAL_MDF_trqOfsNoPlausFault_f32;
                     /* Referenced by: '<S15>/CAL_MDF_trqOfsNoPlausFault_f32' */

/* 角度合理性诊断扭矩需求值阈值 */
#pragma section

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S23>/Data Type Duplicate' : Unused code path elimination
 * Block '<S23>/Data Type Propagation' : Unused code path elimination
 * Block '<S3>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S19>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S20>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S35>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S49>/Data Type Conversion1' : Eliminate redundant data type conversion
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
 * '<Root>' : 'SWC_MDF'
 * '<S1>'   : 'SWC_MDF/RE_SWC_MDF_10ms_sys'
 * '<S2>'   : 'SWC_MDF/RE_SWC_MDF_Init'
 * '<S3>'   : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem'
 * '<S4>'   : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_Fuc'
 * '<S5>'   : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_ParaCalc'
 * '<S6>'   : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_Fuc/DiaAlOfsNoPlaus'
 * '<S7>'   : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_Fuc/DiaEMBlk'
 * '<S8>'   : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_Fuc/DiaICtlRat'
 * '<S9>'   : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_Fuc/DiaIsMax'
 * '<S10>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_Fuc/DiaOpenCirNoPsbl'
 * '<S11>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_Fuc/DiaOperOutdRng'
 * '<S12>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_Fuc/DiaPhaseFault'
 * '<S13>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_Fuc/DiaPrfElDrv'
 * '<S14>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_Fuc/DiaShCirNoPsbl'
 * '<S15>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_Fuc/DiaAlOfsNoPlaus/DFCFlag'
 * '<S16>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_Fuc/DiaAlOfsNoPlaus/Model Info'
 * '<S17>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_Fuc/DiaAlOfsNoPlaus/OfsNoPlausFaultCalc'
 * '<S18>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_Fuc/DiaAlOfsNoPlaus/mdf_tanDelta_Calc'
 * '<S19>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_Fuc/DiaAlOfsNoPlaus/DFCFlag/On_Delay'
 * '<S20>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_Fuc/DiaAlOfsNoPlaus/OfsNoPlausFaultCalc/On_Delay'
 * '<S21>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_Fuc/DiaAlOfsNoPlaus/OfsNoPlausFaultCalc/mdf_offsetJudge'
 * '<S22>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_Fuc/DiaAlOfsNoPlaus/OfsNoPlausFaultCalc/mdf_offsetJudge/MDF_DeltaAgFilter'
 * '<S23>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_Fuc/DiaAlOfsNoPlaus/OfsNoPlausFaultCalc/mdf_offsetJudge/MDF_DeltaAgFilter/Saturation Dynamic'
 * '<S24>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_Fuc/DiaAlOfsNoPlaus/mdf_tanDelta_Calc/Subsystem1'
 * '<S25>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_Fuc/DiaAlOfsNoPlaus/mdf_tanDelta_Calc/Subsystem1/Compare To Constant'
 * '<S26>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_Fuc/DiaAlOfsNoPlaus/mdf_tanDelta_Calc/Subsystem1/Compare To Constant1'
 * '<S27>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_Fuc/DiaAlOfsNoPlaus/mdf_tanDelta_Calc/Subsystem1/Compare To Constant2'
 * '<S28>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_Fuc/DiaAlOfsNoPlaus/mdf_tanDelta_Calc/Subsystem1/Compare To Constant3'
 * '<S29>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_Fuc/DiaAlOfsNoPlaus/mdf_tanDelta_Calc/Subsystem1/Compare To Constant4'
 * '<S30>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_Fuc/DiaEMBlk/DFCFlag'
 * '<S31>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_Fuc/DiaEMBlk/EMBlk'
 * '<S32>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_Fuc/DiaEMBlk/Model Info'
 * '<S33>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_Fuc/DiaEMBlk/EMBlk/EMBlkErrLock'
 * '<S34>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_Fuc/DiaEMBlk/EMBlk/EMBlkWarnJud'
 * '<S35>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_Fuc/DiaEMBlk/EMBlk/On_Delay'
 * '<S36>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_Fuc/DiaICtlRat/DFCFlag'
 * '<S37>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_Fuc/DiaICtlRat/Model Info'
 * '<S38>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_Fuc/DiaICtlRat/iCtlJudge'
 * '<S39>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_Fuc/DiaIsMax/Subsystem'
 * '<S40>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_Fuc/DiaOpenCirNoPsbl/DFCFlag'
 * '<S41>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_Fuc/DiaOpenCirNoPsbl/Model Info'
 * '<S42>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_Fuc/DiaOpenCirNoPsbl/OpenCirNoPsblCalc'
 * '<S43>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_Fuc/DiaOperOutdRng/DFCFlag'
 * '<S44>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_Fuc/DiaOperOutdRng/Model Info'
 * '<S45>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_Fuc/DiaOperOutdRng/OperOutdRngFltCalc'
 * '<S46>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_Fuc/DiaPhaseFault/DFCFlag'
 * '<S47>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_Fuc/DiaPhaseFault/Model Info'
 * '<S48>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_Fuc/DiaPhaseFault/PhaseFaultCalc'
 * '<S49>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_Fuc/DiaPhaseFault/PhaseFaultCalc/On_Delay'
 * '<S50>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_Fuc/DiaPhaseFault/PhaseFaultCalc/Sum_iU'
 * '<S51>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_Fuc/DiaPhaseFault/PhaseFaultCalc/Sum_iV'
 * '<S52>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_Fuc/DiaPhaseFault/PhaseFaultCalc/Sum_iW'
 * '<S53>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_Fuc/DiaPhaseFault/PhaseFaultCalc/UnbalanceDegCompare'
 * '<S54>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_Fuc/DiaPhaseFault/PhaseFaultCalc/iPhaMax'
 * '<S55>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_Fuc/DiaPhaseFault/PhaseFaultCalc/iPhamin'
 * '<S56>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_Fuc/DiaPrfElDrv/DFCFlag'
 * '<S57>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_Fuc/DiaPrfElDrv/Model Info'
 * '<S58>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_Fuc/DiaPrfElDrv/Pwr3PhaCmp'
 * '<S59>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_Fuc/DiaShCirNoPsbl/DFCCalc'
 * '<S60>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_Fuc/DiaShCirNoPsbl/DFCFlag'
 * '<S61>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_Fuc/DiaShCirNoPsbl/Model Info'
 * '<S62>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_ParaCalc/FreewheelCalc'
 * '<S63>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_ParaCalc/OmMechCalc'
 * '<S64>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_ParaCalc/UsdqCalc'
 * '<S65>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_ParaCalc/mdf_DiaElDrvCalc'
 * '<S66>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_ParaCalc/pwrlossCalc'
 * '<S67>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_ParaCalc/FreewheelCalc/Model Info'
 * '<S68>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_ParaCalc/OmMechCalc/Model Info'
 * '<S69>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_ParaCalc/UsdqCalc/Model Info'
 * '<S70>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_ParaCalc/mdf_DiaElDrvCalc/Us_Is_Select'
 * '<S71>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_ParaCalc/mdf_DiaElDrvCalc/mdf_IsErrCalc'
 * '<S72>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_ParaCalc/mdf_DiaElDrvCalc/mdf_Pwr3PhaFlt'
 * '<S73>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_ParaCalc/mdf_DiaElDrvCalc/mdf_UsErrCalc'
 * '<S74>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_ParaCalc/mdf_DiaElDrvCalc/mdf_pwr3PhaMdlFildCalc'
 * '<S75>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_ParaCalc/mdf_DiaElDrvCalc/Us_Is_Select/Model Info'
 * '<S76>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_ParaCalc/mdf_DiaElDrvCalc/mdf_IsErrCalc/Model Info'
 * '<S77>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_ParaCalc/mdf_DiaElDrvCalc/mdf_Pwr3PhaFlt/Model Info'
 * '<S78>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_ParaCalc/mdf_DiaElDrvCalc/mdf_UsErrCalc/Model Info'
 * '<S79>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_ParaCalc/mdf_DiaElDrvCalc/mdf_pwr3PhaMdlFildCalc/Model Info'
 * '<S80>'  : 'SWC_MDF/RE_SWC_MDF_10ms_sys/Subsystem/MDF_ParaCalc/pwrlossCalc/Model Info'
 */
#endif                                 /* RTW_HEADER_SWC_MDF_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
