/*
 * File: SWC_TCF.h
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
                                                                  * '<S10>/Constant1'
                                                                  * '<S17>/GLB_TOM_BwELect_u8'
                                                                  */
#define GLB_TCF_BwGene_u8              2U                        /* Referenced by: '<S19>/GLB_TOM_BwGene_u8' */
#define GLB_TCF_CircAge_f32            360.0F                    /* Referenced by: '<S9>/CAL_TOM_GLB_CircAge_f32' */
#define GLB_TCF_DigtValue_u16          4096U                     /* Referenced by: '<S9>/CAL_TOM_GLB_DigtValue_u16' */
#define GLB_TCF_FwELect_u8             1U                        /* Referenced by:
                                                                  * '<S10>/Constant'
                                                                  * '<S16>/GLB_TOM_FwELect_u8'
                                                                  */
#define GLB_TCF_FwGene_u8              4U                        /* Referenced by: '<S18>/GLB_TOM_FwGene_u8' */
#define GLB_TCF_MotorBw_u8             2U                        /* Referenced by:
                                                                  * '<S13>/GLB_TOM_MotorBw_u8'
                                                                  * '<S15>/GLB_TOM_MotorBw_u8'
                                                                  */
#define GLB_TCF_MotorFw_u8             1U                        /* Referenced by:
                                                                  * '<S13>/GLB_TOM_MotorFw_u8'
                                                                  * '<S15>/GLB_TOM_MotorFw_u8'
                                                                  */
#define GLB_TCF_MotorStop_u8           0U                        /* Referenced by: '<S15>/GLB_TOM_MotorStop_u8' */
#define GLB_TCF_NegvTrq_u8             2U                        /* Referenced by:
                                                                  * '<S13>/GLB_TOM_NegvTrq_u8'
                                                                  * '<S14>/GLB_TOM_NegvTrq_u8'
                                                                  */
#define GLB_TCF_PosvTrq_u8             1U                        /* Referenced by:
                                                                  * '<S13>/GLB_TOM_PosvTrq_u8'
                                                                  * '<S14>/GLB_TOM_PosvTrq_u8'
                                                                  */
#define GLB_TCF_ZeroTrq_u8             0U                        /* Referenced by: '<S14>/GLB_TpcCod_ZeroTrq_u8' */

/* Block states (default storage) for system '<S4>/Subsystem' */
typedef struct {
  sint16 Delay_DSTATE;                 /* '<S22>/Delay' */
} DW_Subsystem_SWC_TCF_T;

/* Block states (default storage) for system '<S1>/Debouncer' */
typedef struct {
  sint16 Delay2_DSTATE;                /* '<S4>/Delay2' */
  boolean UnitDelay1_DSTATE;           /* '<S4>/Unit Delay1' */
  boolean Delay1_DSTATE;               /* '<S4>/Delay1' */
  DW_Subsystem_SWC_TCF_T Subsystem;    /* '<S4>/Subsystem' */
} DW_Debouncer_SWC_TCF_T;

/* Block signals for system '<S6>/Debouncer' */
typedef struct {
  sint16 Switch;                       /* '<S32>/Switch' */
} B_Debouncer_SWC_TCF_m_T;

/* Block states (default storage) for system '<S6>/Debouncer' */
typedef struct {
  sint16 Delay2_DSTATE;                /* '<S28>/Delay2' */
  boolean UnitDelay1_DSTATE;           /* '<S28>/Unit Delay1' */
  boolean Delay1_DSTATE;               /* '<S28>/Delay1' */
  DW_Subsystem_SWC_TCF_T Subsystem;    /* '<S28>/Subsystem' */
} DW_Debouncer_SWC_TCF_p_T;

/* Block signals (default storage) */
typedef struct {
  sint16 Switch;                       /* '<S22>/Switch' */
  B_Debouncer_SWC_TCF_m_T Debouncer_l; /* '<S6>/Debouncer' */
} B_SWC_TCF_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  float32 UnitDelay_DSTATE;            /* '<S12>/Unit Delay' */
  DW_Debouncer_SWC_TCF_p_T Debouncer_l;/* '<S6>/Debouncer' */
  DW_Debouncer_SWC_TCF_T Debouncer;    /* '<S1>/Debouncer' */
} DW_SWC_TCF_T;

/* Invariant block signals (default storage) */
typedef struct {
  const float32 Product2;              /* '<S12>/Product2' */
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
extern float32 VAR_TCF_CurrAgTrqTubeH1_f32;/* '<S30>/Add2' */
extern float32 VAR_TCF_CurrAgTrqTubeL1_f32;/* '<S30>/Add3' */
extern float32 VAR_TCF_PwrTrqTubeH1_f32;/* '<S30>/Add' */
extern float32 VAR_TCF_PwrTrqTubeL1_f32;/* '<S30>/Add1' */
extern float32 VAR_TCF_BlendTrq_f32;   /* '<S29>/TubeSelector2' */
extern float32 VAR_TCF_PwrTrq1_f32;    /* '<S26>/Product2' */
extern float32 VAR_TCF_Ploss_f32;      /* '<S25>/Switch' */
extern float32 VAR_TCF_Pinput_f32;     /* '<S24>/Add4' */
extern float32 VAR_TCF_Is_f32;         /* '<S23>/Sqrt' */
extern float32 VAR_TCF_CurrAgTrqflt_f32;/* '<S3>/Saturation1' */
extern float32 VAR_TCF_LdsubLq_f32;    /* '<S10>/Switch' */
extern float32 VAR_TCF_idAct_f32;      /* '<S9>/Add2' */
extern float32 VAR_TCF_iqAct_f32;      /* '<S9>/Add3' */
extern float32 VAR_TCF_CurrAgTrq1_f32; /* '<S8>/Product2' */
extern uint8 VAR_TCF_nDir_u8;          /* '<S15>/Switch' */
extern uint8 VAR_TCF_TrqDir_u8;        /* '<S14>/Switch' */
extern uint8 VAR_TCF_MotorMode_u8;     /* '<S13>/Merge' */
extern boolean VAR_TCF_TrqCalcMonRslt_b;/* '<S29>/TubeSelector2' */
extern boolean VAR_TCF_TrqCalcErr_b;   /* '<S28>/Logical Operator' */

/* Model entry point functions */
extern void SWC_TCF_initialize(void);

/* Exported entry point function */
extern void SWC_TCF_1ms(void);

/* Exported data declaration */
#pragma section ".rodata.Calib_32"

/* Declaration for custom storage class: iEDS_Parameter */
extern const volatile float32 CAL_TCF_AgTrqTubeCAy_af32[35];
                                   /* Referenced by: '<S30>/1-D Lookup Table' */
extern const volatile float32 CAL_TCF_HiSpdDirStop_f32;
                           /* Referenced by: '<S15>/CAL_TOM_HiSpdDirStop_f32' */
extern const volatile float32 CAL_TCF_HiTrqDirStop_f32;
                           /* Referenced by: '<S14>/CAL_TOM_HiTrqDirStop_f32' */
extern const volatile float32 CAL_TCF_IsPwrLosCAx_af32[35];/* Referenced by: '<S25>/IS_N_Ploss_T' */
extern const volatile float32 CAL_TCF_LdSubLqCAzGen_af32[270];
                                      /* Referenced by: '<S10>/LdSubLqGen_L2' */
extern const volatile float32 CAL_TCF_LdSubLqCAzMot_af32[270];
                                      /* Referenced by: '<S10>/LdSubLqMot_L2' */
extern const volatile float32 CAL_TCF_LdSubLqIdCAx_af32[18];/* Referenced by:
                                                             * '<S10>/LdSubLqGen_L2'
                                                             * '<S10>/LdSubLqMot_L2'
                                                             */
extern const volatile float32 CAL_TCF_LdSubLqIqCAy_af32[15];/* Referenced by:
                                                             * '<S10>/LdSubLqGen_L2'
                                                             * '<S10>/LdSubLqMot_L2'
                                                             */
extern const volatile float32 CAL_TCF_LoSpdDirStop_f32;
                           /* Referenced by: '<S15>/CAL_TOM_LoSpdDirStop_f32' */
extern const volatile float32 CAL_TCF_LoTrqDirStop_f32;
                           /* Referenced by: '<S14>/CAL_TOM_LoTrqDirStop_f32' */
extern const volatile uint8 CAL_TCF_MotorPole_u8;
                                   /* Referenced by: '<S8>/CAL_TOM_GLB_Pn_u8' */
extern const volatile float32 CAL_TCF_NPwrLosCAy_af32[16];/* Referenced by:
                                                           * '<S25>/IS_N_Ploss_T'
                                                           * '<S26>/PwrTrqSpdCompa'
                                                           */
extern const volatile float32 CAL_TCF_Psi_f32;
                                     /* Referenced by: '<S8>/CAL_TOM_Psi_f32' */
extern const volatile float32 CAL_TCF_PwrLossCAz_af32[560];/* Referenced by: '<S25>/IS_N_Ploss_T' */
extern const volatile float32 CAL_TCF_PwrTrqSpdCompa_af32[16];
                                     /* Referenced by: '<S26>/PwrTrqSpdCompa' */
extern const volatile float32 CAL_TCF_PwrTrqTubeCAy_af32[35];
                                 /* Referenced by: '<S30>/Cal_PowerTrqTube_T' */
extern const volatile uint8 CAL_TCF_SpeedCtlMode_u8;
                             /* Referenced by: '<S7>/CAL_TOM_SpeedCtlMode_u8' */
extern const volatile float32 CAL_TCF_TempStrMax_f32;
                             /* Referenced by: '<S25>/CAL_TOM_TempStrMax_f32' */
extern const volatile float32 CAL_TCF_TempStrMin_f32;
                             /* Referenced by: '<S25>/CAL_TOM_TempStrMin_f32' */
extern const volatile float32 CAL_TCF_TempStrPlossFact_f32;
                       /* Referenced by: '<S25>/CAL_TOM_TempStrPlossFact_f32' */
extern const volatile sint16 CAL_TCF_TrqCalcMonCountTrh_s16;
                           /* Referenced by: '<S6>/CAL_TOM_HiTrqMonDebTrh_s5' */
extern const volatile sint16 CAL_TCF_TrqCalcMonDebTrh_s16;
                           /* Referenced by: '<S6>/CAL_TOM_HiTrqMonDebTrh_s4' */
extern const volatile boolean CAL_TCF_TrqCalcMonErrRst_b;
                             /* Referenced by: '<S6>/CAL_TOM_TrqMonErrRst_b2' */
extern const volatile sint16 CAL_TCF_TrqInvalid_s16;
                                      /* Referenced by: '<S29>/TubeSelector2' */
extern const volatile float32 CAL_TCF_TrqMechCutOffFrq_f32;
                        /* Referenced by: '<S3>/CAL_TCF_TrqMechCutOffFrq_f32' */
extern const volatile float32 CAL_TCF_TrqTubeNCAx_af32[35];/* Referenced by:
                                                            * '<S30>/1-D Lookup Table'
                                                            * '<S30>/Cal_PowerTrqTube_T'
                                                            */
extern const volatile boolean CAL_TCF_flgUsePlossCompa_b;
                         /* Referenced by: '<S25>/CAL_TOM_flgUsePlossCompa_b' */
extern const volatile uint16 PRV_CalFltFrq_1ms;
                                   /* Referenced by: '<S3>/PRV_CalFltFrq_1ms' */

#pragma section

/* Real-time Model object */
extern RT_MODEL_SWC_TCF_T *const SWC_TCF_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S20>/Data Type Duplicate' : Unused code path elimination
 * Block '<S20>/Data Type Propagation' : Unused code path elimination
 * Block '<S27>/Data Type Duplicate' : Unused code path elimination
 * Block '<S27>/Data Type Propagation' : Unused code path elimination
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
 * '<S4>'   : 'SWC_TCF/SWC_TCF_1ms_sys/Debouncer'
 * '<S5>'   : 'SWC_TCF/SWC_TCF_1ms_sys/PwrTrqCalcProc'
 * '<S6>'   : 'SWC_TCF/SWC_TCF_1ms_sys/TrqBlendProc'
 * '<S7>'   : 'SWC_TCF/SWC_TCF_1ms_sys/TrqCalcEnable'
 * '<S8>'   : 'SWC_TCF/SWC_TCF_1ms_sys/CurrAgTrqCalcProc/CurrAgTrqCalc'
 * '<S9>'   : 'SWC_TCF/SWC_TCF_1ms_sys/CurrAgTrqCalcProc/IdIqCalc'
 * '<S10>'  : 'SWC_TCF/SWC_TCF_1ms_sys/CurrAgTrqCalcProc/LdsubLqCalc'
 * '<S11>'  : 'SWC_TCF/SWC_TCF_1ms_sys/CurrAgTrqCalcProc/MotorModeJdg'
 * '<S12>'  : 'SWC_TCF/SWC_TCF_1ms_sys/CurrAgTrqCalcProc/SPF_tDBCTempWFilter3'
 * '<S13>'  : 'SWC_TCF/SWC_TCF_1ms_sys/CurrAgTrqCalcProc/MotorModeJdg/MotorMode'
 * '<S14>'  : 'SWC_TCF/SWC_TCF_1ms_sys/CurrAgTrqCalcProc/MotorModeJdg/TrqDir'
 * '<S15>'  : 'SWC_TCF/SWC_TCF_1ms_sys/CurrAgTrqCalcProc/MotorModeJdg/nDir'
 * '<S16>'  : 'SWC_TCF/SWC_TCF_1ms_sys/CurrAgTrqCalcProc/MotorModeJdg/MotorMode/If Action Subsystem'
 * '<S17>'  : 'SWC_TCF/SWC_TCF_1ms_sys/CurrAgTrqCalcProc/MotorModeJdg/MotorMode/If Action Subsystem1'
 * '<S18>'  : 'SWC_TCF/SWC_TCF_1ms_sys/CurrAgTrqCalcProc/MotorModeJdg/MotorMode/If Action Subsystem2'
 * '<S19>'  : 'SWC_TCF/SWC_TCF_1ms_sys/CurrAgTrqCalcProc/MotorModeJdg/MotorMode/If Action Subsystem3'
 * '<S20>'  : 'SWC_TCF/SWC_TCF_1ms_sys/CurrAgTrqCalcProc/SPF_tDBCTempWFilter3/Saturation Dynamic'
 * '<S21>'  : 'SWC_TCF/SWC_TCF_1ms_sys/Debouncer/Compare To Zero'
 * '<S22>'  : 'SWC_TCF/SWC_TCF_1ms_sys/Debouncer/Subsystem'
 * '<S23>'  : 'SWC_TCF/SWC_TCF_1ms_sys/PwrTrqCalcProc/IsCalc'
 * '<S24>'  : 'SWC_TCF/SWC_TCF_1ms_sys/PwrTrqCalcProc/PinputCalc'
 * '<S25>'  : 'SWC_TCF/SWC_TCF_1ms_sys/PwrTrqCalcProc/PlossCalc'
 * '<S26>'  : 'SWC_TCF/SWC_TCF_1ms_sys/PwrTrqCalcProc/PwrTrqCalc'
 * '<S27>'  : 'SWC_TCF/SWC_TCF_1ms_sys/PwrTrqCalcProc/PlossCalc/Saturation Dynamic'
 * '<S28>'  : 'SWC_TCF/SWC_TCF_1ms_sys/TrqBlendProc/Debouncer'
 * '<S29>'  : 'SWC_TCF/SWC_TCF_1ms_sys/TrqBlendProc/TrqBlend'
 * '<S30>'  : 'SWC_TCF/SWC_TCF_1ms_sys/TrqBlendProc/TrqTube'
 * '<S31>'  : 'SWC_TCF/SWC_TCF_1ms_sys/TrqBlendProc/Debouncer/Compare To Zero'
 * '<S32>'  : 'SWC_TCF/SWC_TCF_1ms_sys/TrqBlendProc/Debouncer/Subsystem'
 * '<S33>'  : 'SWC_TCF/SWC_TCF_1ms_sys/TrqBlendProc/TrqBlend/TubeSelector2'
 */
#endif                                 /* RTW_HEADER_SWC_TCF_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
