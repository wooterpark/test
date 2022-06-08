/*
 * File: SWC_TCF.h
 *
 * Code generated for Simulink model 'SWC_TCF'.
 *
 * Model version                  : 1.604
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Wed May 25 19:51:06 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_SWC_TCF_h_
#define RTW_HEADER_SWC_TCF_h_
#include <math.h>
#ifndef SWC_TCF_COMMON_INCLUDES_
# define SWC_TCF_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* SWC_TCF_COMMON_INCLUDES_ */

#include "SWC_TCF_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Exported data define */

/* Definition for custom storage class: Define */
#define GLB_TCF_BwELect_u8             3U                        /* Referenced by:
                                                                  * '<S9>/Constant1'
                                                                  * '<S22>/Constant3'
                                                                  * '<S16>/GLB_TOM_BwELect_u8'
                                                                  */
#define GLB_TCF_BwGene_u8              2U                        /* Referenced by: '<S18>/GLB_TOM_BwGene_u8' */
#define GLB_TCF_CircAge_f32            360.0F                    /* Referenced by: '<S8>/CAL_TOM_GLB_CircAge_f32' */
#define GLB_TCF_DigtValue_u16          4096U                     /* Referenced by: '<S8>/CAL_TOM_GLB_DigtValue_u16' */
#define GLB_TCF_FwELect_u8             1U                        /* Referenced by:
                                                                  * '<S9>/Constant'
                                                                  * '<S22>/Constant1'
                                                                  * '<S15>/GLB_TOM_FwELect_u8'
                                                                  */
#define GLB_TCF_FwGene_u8              4U                        /* Referenced by: '<S17>/GLB_TOM_FwGene_u8' */
#define GLB_TCF_MotorBw_u8             2U                        /* Referenced by:
                                                                  * '<S12>/GLB_TOM_MotorBw_u8'
                                                                  * '<S14>/GLB_TOM_MotorBw_u8'
                                                                  */
#define GLB_TCF_MotorFw_u8             1U                        /* Referenced by:
                                                                  * '<S12>/GLB_TOM_MotorFw_u8'
                                                                  * '<S14>/GLB_TOM_MotorFw_u8'
                                                                  */
#define GLB_TCF_MotorStop_u8           0U                        /* Referenced by: '<S14>/GLB_TOM_MotorStop_u8' */
#define GLB_TCF_NegvTrq_u8             2U                        /* Referenced by:
                                                                  * '<S12>/GLB_TOM_NegvTrq_u8'
                                                                  * '<S13>/GLB_TOM_NegvTrq_u8'
                                                                  */
#define GLB_TCF_PosvTrq_u8             1U                        /* Referenced by:
                                                                  * '<S12>/GLB_TOM_PosvTrq_u8'
                                                                  * '<S13>/GLB_TOM_PosvTrq_u8'
                                                                  */
#define GLB_TCF_ZeroTrq_u8             0U                        /* Referenced by: '<S13>/GLB_TpcCod_ZeroTrq_u8' */

/* Block states (default storage) for system '<S5>/Debouncer' */
typedef struct {
  sint16 Delay2_DSTATE;                /* '<S29>/Delay2' */
  sint16 Delay_DSTATE;                 /* '<S33>/Delay' */
  boolean UnitDelay1_DSTATE;           /* '<S29>/Unit Delay1' */
  boolean Delay1_DSTATE;               /* '<S29>/Delay1' */
} DW_Debouncer_SWC_TCF_T;

/* Block signals (default storage) */
typedef struct {
  boolean LogicalOperator;             /* '<S6>/Logical Operator' */
} B_SWC_TCF_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  float32 UnitDelay_DSTATE;            /* '<S22>/Unit Delay' */
  float32 UnitDelay_DSTATE_p;          /* '<S20>/Unit Delay' */
  float32 UnitDelay_DSTATE_c;          /* '<S19>/Unit Delay' */
  float32 UnitDelay_DSTATE_ct;         /* '<S7>/Unit Delay' */
  uint8 Delay_DSTATE;                  /* '<S22>/Delay' */
  boolean Relay_Mode;                  /* '<S6>/Relay' */
  DW_Debouncer_SWC_TCF_T Debouncer;    /* '<S5>/Debouncer' */
} DW_SWC_TCF_T;

/* Invariant block signals (default storage) */
typedef struct {
  const float32 Product5;              /* '<S22>/Product5' */
  const float32 Product8;              /* '<S20>/Product8' */
  const float32 Product6;              /* '<S19>/Product6' */
  const float32 Product5_k;            /* '<S7>/Product5' */
} ConstB_SWC_TCF_T;

/* Real-time Model Data Structure */
struct tag_RTM_SWC_TCF_T {
  const char_T *errorStatus;
};

/* Block signals (default storage) */
extern B_SWC_TCF_T SWC_TCF_B;

/* Block states (default storage) */
extern DW_SWC_TCF_T SWC_TCF_DW;
extern const ConstB_SWC_TCF_T SWC_TCF_ConstB;/* constant block i/o */

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern float32 VAR_L2Sampling_DycUMon_f32;/* '<S1>/Signal Conversion4' */
extern float32 VAR_L2Sampling_DycVMon_f32;/* '<S1>/Signal Conversion5' */
extern float32 VAR_L2Sampling_DycWMon_f32;/* '<S1>/Signal Conversion6' */
extern float32 VAR_HSPF_StrrTempFlt_f32;/* '<S1>/Signal Conversion7' */
extern float32 VAR_TCF_CurrAgTrqTubeH1_f32;/* '<S31>/Add2' */
extern float32 VAR_TCF_CurrAgTrqTubeL1_f32;/* '<S31>/Add3' */
extern float32 VAR_TCF_PwrTrqfltcomp_f32;/* '<S31>/Switch' */
extern float32 VAR_TCF_PwrTrqTubeH1_f32;/* '<S31>/Add' */
extern float32 VAR_TCF_PwrTrqTubeL1_f32;/* '<S31>/Add1' */
extern float32 VAR_TCF_BlendTrq_f32;   /* '<S30>/TubeSelector2' */
extern float32 VAR_TCF_PwrTrqCompCof_f32;/* '<S22>/Switch' */
extern float32 VAR_TCF_PwrTrqNoflt_f32;/* '<S22>/Product2' */
extern float32 VAR_TCF_PwrTrqflt_f32;  /* '<S22>/Saturation1' */
extern float32 VAR_TCF_Ploss_f32;      /* '<S21>/Switch' */
extern float32 VAR_TCF_PwrInputNoflt_f32;/* '<S20>/Add4' */
extern float32 VAR_TCF_PwrInputflt_f32;/* '<S20>/Saturation1' */
extern float32 VAR_TCF_IsNoflt_f32;    /* '<S19>/Sqrt' */
extern float32 VAR_TCF_Isflt_f32;      /* '<S19>/Saturation1' */
extern float32 VAR_TCF_LdsubLq_f32;    /* '<S9>/Switch' */
extern float32 VAR_TCF_idAct_f32;      /* '<S8>/Add2' */
extern float32 VAR_TCF_iqAct_f32;      /* '<S8>/Add3' */
extern float32 VAR_TCF_CurrAgTrqNoComp_f32;/* '<S7>/Product2' */
extern float32 VAR_TCF_CurrAgTrqflt_f32;/* '<S7>/Saturation1' */
extern uint8 VAR_TCF_nDir_u8;          /* '<S14>/Switch' */
extern uint8 VAR_TCF_TrqDir_u8;        /* '<S13>/Switch' */
extern uint8 VAR_TCF_MotorMode_u8;     /* '<S12>/Merge' */
extern boolean VAR_TCF_TrqCalcMonRslt_b;/* '<S30>/TubeSelector2' */
extern boolean VAR_TCF_TrqCalcErr_b;   /* '<S29>/Logical Operator' */

/* Model entry point functions */
extern void SWC_TCF_initialize(void);

/* Exported entry point function */
extern void SWC_TCF_1ms(void);

/* Exported data declaration */
#pragma section ".rodata.Calib_32"

/* Declaration for custom storage class: iEDS_Parameter */
extern const volatile float32 CAL_TCF_AgTrqTubeCAy_af32[18];
                                   /* Referenced by: '<S31>/1-D Lookup Table' */
extern const volatile float32 CAL_TCF_HiSpdDirStop_f32;
                           /* Referenced by: '<S14>/CAL_TOM_HiSpdDirStop_f32' */
extern const volatile float32 CAL_TCF_HiTrqDirStop_f32;
                           /* Referenced by: '<S13>/CAL_TOM_HiTrqDirStop_f32' */
extern const volatile float32 CAL_TCF_IsCutOffFrq_f32;
                            /* Referenced by: '<S19>/CAL_TCF_IsCutOffFrq_f32' */
extern const volatile float32 CAL_TCF_IsPwrLosCAx_af32[35];/* Referenced by: '<S21>/IS_N_Ploss_T' */
extern const volatile float32 CAL_TCF_LdSubLqCAzGen_af32[270];/* Referenced by: '<S9>/LdSubLqGen_L2' */
extern const volatile float32 CAL_TCF_LdSubLqCAzMot_af32[270];/* Referenced by: '<S9>/LdSubLqMot_L2' */
extern const volatile float32 CAL_TCF_LdSubLqIdCAx_af32[18];/* Referenced by:
                                                             * '<S9>/LdSubLqGen_L2'
                                                             * '<S9>/LdSubLqMot_L2'
                                                             */
extern const volatile float32 CAL_TCF_LdSubLqIqCAy_af32[15];/* Referenced by:
                                                             * '<S9>/LdSubLqGen_L2'
                                                             * '<S9>/LdSubLqMot_L2'
                                                             */
extern const volatile float32 CAL_TCF_LoSpdDirStop_f32;
                           /* Referenced by: '<S14>/CAL_TOM_LoSpdDirStop_f32' */
extern const volatile float32 CAL_TCF_LoTrqDirStop_f32;
                           /* Referenced by: '<S13>/CAL_TOM_LoTrqDirStop_f32' */
extern const volatile uint8 CAL_TCF_MotorPole_u8;
                                   /* Referenced by: '<S7>/CAL_TOM_GLB_Pn_u8' */
extern const volatile float32 CAL_TCF_NPwrLosCAy_af32[16];/* Referenced by: '<S21>/IS_N_Ploss_T' */
extern const volatile float32 CAL_TCF_Psi_f32;
                                     /* Referenced by: '<S7>/CAL_TOM_Psi_f32' */
extern const volatile float32 CAL_TCF_PwrCompaElectCAz_af32[792];
                                /* Referenced by: '<S22>/PwrTrqSpdCompaElect' */
extern const volatile float32 CAL_TCF_PwrCompaIsCAy_af32[24];/* Referenced by:
                                                              * '<S22>/PwrTrqSpdCompaElect'
                                                              * '<S22>/PwrTrqSpdCompaGen'
                                                              */
extern const volatile float32 CAL_TCF_PwrCompaSpdCAx_af32[33];/* Referenced by:
                                                               * '<S22>/PwrTrqSpdCompaElect'
                                                               * '<S22>/PwrTrqSpdCompaGen'
                                                               */
extern const volatile float32 CAL_TCF_PwrInputCutOffFrq_f32;
                      /* Referenced by: '<S20>/CAL_TCF_PwrInputCutOffFrq_f32' */
extern const volatile float32 CAL_TCF_PwrLossCAz_af32[560];/* Referenced by: '<S21>/IS_N_Ploss_T' */
extern const volatile float32 CAL_TCF_PwrTrqCalcSpdThrH_f32;/* Referenced by: '<S6>/Relay' */
extern const volatile float32 CAL_TCF_PwrTrqCalcSpdThrL_f32;/* Referenced by: '<S6>/Relay' */
extern const volatile float32 CAL_TCF_PwrTrqTubeCAy_af32[18];
                                 /* Referenced by: '<S31>/Cal_PowerTrqTube_T' */
extern const volatile uint8 CAL_TCF_SpeedCtlMode_u8;
                             /* Referenced by: '<S6>/CAL_TOM_SpeedCtlMode_u8' */
extern const volatile float32 CAL_TCF_TempStrMax_f32;
                             /* Referenced by: '<S21>/CAL_TOM_TempStrMax_f32' */
extern const volatile float32 CAL_TCF_TempStrMin_f32;
                             /* Referenced by: '<S21>/CAL_TOM_TempStrMin_f32' */
extern const volatile float32 CAL_TCF_TempStrPlossFact_f32;
                       /* Referenced by: '<S21>/CAL_TOM_TempStrPlossFact_f32' */
extern const volatile sint16 CAL_TCF_TrqCalcMonCountTrh_s16;
                           /* Referenced by: '<S5>/CAL_TOM_HiTrqMonDebTrh_s5' */
extern const volatile sint16 CAL_TCF_TrqCalcMonDebTrh_s16;
                           /* Referenced by: '<S5>/CAL_TOM_HiTrqMonDebTrh_s4' */
extern const volatile boolean CAL_TCF_TrqCalcMonErrRst_b;
                             /* Referenced by: '<S5>/CAL_TOM_TrqMonErrRst_b2' */
extern const volatile sint16 CAL_TCF_TrqInvalid_s16;
                                      /* Referenced by: '<S30>/TubeSelector2' */
extern const volatile float32 CAL_TCF_TrqMechCutOffFrq_f32;/* Referenced by:
                                                            * '<S7>/CAL_TCF_TrqMechCutOffFrq_f32'
                                                            * '<S22>/CAL_TCF_TrqMechCutOffFrq_f32'
                                                            */
extern const volatile float32 CAL_TCF_TrqTubeNCAx_af32[18];/* Referenced by:
                                                            * '<S31>/1-D Lookup Table'
                                                            * '<S31>/Cal_PowerTrqTube_T'
                                                            */
extern const volatile boolean CAL_TCF_flgUsePlossCompa_b;
                         /* Referenced by: '<S21>/CAL_TOM_flgUsePlossCompa_b' */
extern const volatile uint16 PRV_CalFltFrq_1ms;/* Referenced by:
                                                * '<S7>/PRV_CalFltFrq_1ms'
                                                * '<S20>/PRV_CalFltFrq_1ms'
                                                * '<S22>/PRV_CalFltFrq_1ms'
                                                */
extern const volatile uint16 PRV_IsCalFltFrq_1ms;
                                /* Referenced by: '<S19>/PRV_IsCalFltFrq_1ms' */

#pragma section

/* Real-time Model object */
extern RT_MODEL_SWC_TCF_T *const SWC_TCF_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S11>/Data Type Duplicate' : Unused code path elimination
 * Block '<S11>/Data Type Propagation' : Unused code path elimination
 * Block '<S23>/Data Type Duplicate' : Unused code path elimination
 * Block '<S23>/Data Type Propagation' : Unused code path elimination
 * Block '<S24>/Data Type Duplicate' : Unused code path elimination
 * Block '<S24>/Data Type Propagation' : Unused code path elimination
 * Block '<S26>/Data Type Duplicate' : Unused code path elimination
 * Block '<S26>/Data Type Propagation' : Unused code path elimination
 * Block '<S28>/Data Type Duplicate' : Unused code path elimination
 * Block '<S28>/Data Type Propagation' : Unused code path elimination
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
 * '<Root>' : 'SWC_TCF'
 * '<S1>'   : 'SWC_TCF/SWC_TCF_1ms_sys'
 * '<S2>'   : 'SWC_TCF/SWC_TCF_Init'
 * '<S3>'   : 'SWC_TCF/SWC_TCF_1ms_sys/CurrAgTrqCalcProc'
 * '<S4>'   : 'SWC_TCF/SWC_TCF_1ms_sys/PwrTrqCalcProc'
 * '<S5>'   : 'SWC_TCF/SWC_TCF_1ms_sys/TrqBlendProc'
 * '<S6>'   : 'SWC_TCF/SWC_TCF_1ms_sys/TrqCalcEnable'
 * '<S7>'   : 'SWC_TCF/SWC_TCF_1ms_sys/CurrAgTrqCalcProc/CurrAgTrqCalc'
 * '<S8>'   : 'SWC_TCF/SWC_TCF_1ms_sys/CurrAgTrqCalcProc/IdIqCalc'
 * '<S9>'   : 'SWC_TCF/SWC_TCF_1ms_sys/CurrAgTrqCalcProc/LdsubLqCalc'
 * '<S10>'  : 'SWC_TCF/SWC_TCF_1ms_sys/CurrAgTrqCalcProc/MotorModeJdg'
 * '<S11>'  : 'SWC_TCF/SWC_TCF_1ms_sys/CurrAgTrqCalcProc/CurrAgTrqCalc/Saturation Dynamic'
 * '<S12>'  : 'SWC_TCF/SWC_TCF_1ms_sys/CurrAgTrqCalcProc/MotorModeJdg/MotorMode'
 * '<S13>'  : 'SWC_TCF/SWC_TCF_1ms_sys/CurrAgTrqCalcProc/MotorModeJdg/TrqDir'
 * '<S14>'  : 'SWC_TCF/SWC_TCF_1ms_sys/CurrAgTrqCalcProc/MotorModeJdg/nDir'
 * '<S15>'  : 'SWC_TCF/SWC_TCF_1ms_sys/CurrAgTrqCalcProc/MotorModeJdg/MotorMode/If Action Subsystem'
 * '<S16>'  : 'SWC_TCF/SWC_TCF_1ms_sys/CurrAgTrqCalcProc/MotorModeJdg/MotorMode/If Action Subsystem1'
 * '<S17>'  : 'SWC_TCF/SWC_TCF_1ms_sys/CurrAgTrqCalcProc/MotorModeJdg/MotorMode/If Action Subsystem2'
 * '<S18>'  : 'SWC_TCF/SWC_TCF_1ms_sys/CurrAgTrqCalcProc/MotorModeJdg/MotorMode/If Action Subsystem3'
 * '<S19>'  : 'SWC_TCF/SWC_TCF_1ms_sys/PwrTrqCalcProc/IsCalc'
 * '<S20>'  : 'SWC_TCF/SWC_TCF_1ms_sys/PwrTrqCalcProc/PinputCalc'
 * '<S21>'  : 'SWC_TCF/SWC_TCF_1ms_sys/PwrTrqCalcProc/PlossCalc'
 * '<S22>'  : 'SWC_TCF/SWC_TCF_1ms_sys/PwrTrqCalcProc/PwrTrqCalc'
 * '<S23>'  : 'SWC_TCF/SWC_TCF_1ms_sys/PwrTrqCalcProc/IsCalc/Saturation Dynamic'
 * '<S24>'  : 'SWC_TCF/SWC_TCF_1ms_sys/PwrTrqCalcProc/PinputCalc/Saturation Dynamic'
 * '<S25>'  : 'SWC_TCF/SWC_TCF_1ms_sys/PwrTrqCalcProc/PlossCalc/Compare To Constant1'
 * '<S26>'  : 'SWC_TCF/SWC_TCF_1ms_sys/PwrTrqCalcProc/PlossCalc/Saturation Dynamic'
 * '<S27>'  : 'SWC_TCF/SWC_TCF_1ms_sys/PwrTrqCalcProc/PwrTrqCalc/Compare To Constant1'
 * '<S28>'  : 'SWC_TCF/SWC_TCF_1ms_sys/PwrTrqCalcProc/PwrTrqCalc/Saturation Dynamic'
 * '<S29>'  : 'SWC_TCF/SWC_TCF_1ms_sys/TrqBlendProc/Debouncer'
 * '<S30>'  : 'SWC_TCF/SWC_TCF_1ms_sys/TrqBlendProc/TrqBlend'
 * '<S31>'  : 'SWC_TCF/SWC_TCF_1ms_sys/TrqBlendProc/TrqTube'
 * '<S32>'  : 'SWC_TCF/SWC_TCF_1ms_sys/TrqBlendProc/Debouncer/Compare To Zero'
 * '<S33>'  : 'SWC_TCF/SWC_TCF_1ms_sys/TrqBlendProc/Debouncer/Subsystem'
 * '<S34>'  : 'SWC_TCF/SWC_TCF_1ms_sys/TrqBlendProc/TrqBlend/TubeSelector2'
 */
#endif                                 /* RTW_HEADER_SWC_TCF_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
