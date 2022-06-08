/*
 * File: SWC_TRSP.h
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

#ifndef RTW_HEADER_SWC_TRSP_h_
#define RTW_HEADER_SWC_TRSP_h_
#include <math.h>
#ifndef SWC_TRSP_COMMON_INCLUDES_
# define SWC_TRSP_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* SWC_TRSP_COMMON_INCLUDES_ */

#include "SWC_TRSP_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Exported data define */

/* Definition for custom storage class: Define */
#define GLB_TRSP_CircAge_f32           360.0F                    /* Referenced by:
                                                                  * '<S8>/GLB_TOM_CircAge_f1'
                                                                  * '<S8>/GLB_TOM_CircAge_f2'
                                                                  * '<S8>/GLB_TRSP_CircAge_f32'
                                                                  */
#define GLB_TRSP_MotorPole_u8          4U                        /* Referenced by: '<S8>/GLB_TRSP_MotorPole_u8' */
#define GLB_TRSP_Sixty_f32             60.0F                     /* Referenced by: '<S8>/GLB_TRSP_Sixty_f32' */

/* Block states (default storage) for system '<S14>/Count' */
typedef struct {
  sint16 Delay_DSTATE;                 /* '<S17>/Delay' */
} DW_Count_SWC_TRSP_T;

/* Block signals for system '<S5>/Debouncer11' */
typedef struct {
  sint16 Switch;                       /* '<S17>/Switch' */
} B_Debouncer11_SWC_TRSP_T;

/* Block states (default storage) for system '<S5>/Debouncer11' */
typedef struct {
  sint16 Delay2_DSTATE;                /* '<S14>/Delay2' */
  boolean UnitDelay1_DSTATE;           /* '<S14>/Unit Delay1' */
  boolean Delay1_DSTATE;               /* '<S14>/Delay1' */
  DW_Count_SWC_TRSP_T Count;           /* '<S14>/Count' */
} DW_Debouncer11_SWC_TRSP_T;

/* Block states (default storage) for system '<S2>/Debouncer' */
typedef struct {
  sint16 Delay2_DSTATE;                /* '<S86>/Delay2' */
  boolean UnitDelay1_DSTATE;           /* '<S86>/Unit Delay1' */
  boolean Delay1_DSTATE;               /* '<S86>/Delay1' */
  DW_Count_SWC_TRSP_T Subsystem;       /* '<S86>/Subsystem' */
} DW_Debouncer_SWC_TRSP_T;

/* Block signals (default storage) */
typedef struct {
  sint16 Switch;                       /* '<S96>/Switch' */
  sint16 Switch_i;                     /* '<S92>/Switch' */
  B_Debouncer11_SWC_TRSP_T Debouncer15;/* '<S85>/Debouncer15' */
  B_Debouncer11_SWC_TRSP_T Debouncer12;/* '<S13>/Debouncer12' */
  B_Debouncer11_SWC_TRSP_T Debouncer11_fe;/* '<S12>/Debouncer11' */
  B_Debouncer11_SWC_TRSP_T Debouncer11_n;/* '<S11>/Debouncer11' */
  B_Debouncer11_SWC_TRSP_T Debouncer9; /* '<S10>/Debouncer9' */
  B_Debouncer11_SWC_TRSP_T Debouncer8; /* '<S10>/Debouncer8' */
  B_Debouncer11_SWC_TRSP_T Debouncer7; /* '<S10>/Debouncer7' */
  B_Debouncer11_SWC_TRSP_T Debouncer6; /* '<S10>/Debouncer6' */
  B_Debouncer11_SWC_TRSP_T Debouncer5; /* '<S10>/Debouncer5' */
  B_Debouncer11_SWC_TRSP_T Debouncer4; /* '<S10>/Debouncer4' */
  B_Debouncer11_SWC_TRSP_T Debouncer10;/* '<S10>/Debouncer10' */
  B_Debouncer11_SWC_TRSP_T Debouncer3; /* '<S9>/Debouncer3' */
  B_Debouncer11_SWC_TRSP_T Debouncer2; /* '<S9>/Debouncer2' */
  B_Debouncer11_SWC_TRSP_T Debouncer1; /* '<S9>/Debouncer1' */
  B_Debouncer11_SWC_TRSP_T Debouncer;  /* '<S9>/Debouncer' */
  B_Debouncer11_SWC_TRSP_T Debouncer11_g;/* '<S7>/Debouncer11' */
  B_Debouncer11_SWC_TRSP_T Debouncer11_f;/* '<S6>/Debouncer11' */
  B_Debouncer11_SWC_TRSP_T Debouncer11;/* '<S5>/Debouncer11' */
} B_SWC_TRSP_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  uint8 Delay_DSTATE;                  /* '<S98>/Delay' */
  DW_Debouncer_SWC_TRSP_T Debouncer_o; /* '<S3>/Debouncer' */
  DW_Debouncer_SWC_TRSP_T Debouncer_n; /* '<S2>/Debouncer' */
  DW_Debouncer11_SWC_TRSP_T Debouncer15;/* '<S85>/Debouncer15' */
  DW_Debouncer11_SWC_TRSP_T Debouncer12;/* '<S13>/Debouncer12' */
  DW_Debouncer11_SWC_TRSP_T Debouncer11_fe;/* '<S12>/Debouncer11' */
  DW_Debouncer11_SWC_TRSP_T Debouncer11_n;/* '<S11>/Debouncer11' */
  DW_Debouncer11_SWC_TRSP_T Debouncer9;/* '<S10>/Debouncer9' */
  DW_Debouncer11_SWC_TRSP_T Debouncer8;/* '<S10>/Debouncer8' */
  DW_Debouncer11_SWC_TRSP_T Debouncer7;/* '<S10>/Debouncer7' */
  DW_Debouncer11_SWC_TRSP_T Debouncer6;/* '<S10>/Debouncer6' */
  DW_Debouncer11_SWC_TRSP_T Debouncer5;/* '<S10>/Debouncer5' */
  DW_Debouncer11_SWC_TRSP_T Debouncer4;/* '<S10>/Debouncer4' */
  DW_Debouncer11_SWC_TRSP_T Debouncer10;/* '<S10>/Debouncer10' */
  DW_Debouncer11_SWC_TRSP_T Debouncer3;/* '<S9>/Debouncer3' */
  DW_Debouncer11_SWC_TRSP_T Debouncer2;/* '<S9>/Debouncer2' */
  DW_Debouncer11_SWC_TRSP_T Debouncer1;/* '<S9>/Debouncer1' */
  DW_Debouncer11_SWC_TRSP_T Debouncer; /* '<S9>/Debouncer' */
  DW_Debouncer11_SWC_TRSP_T Debouncer11_g;/* '<S7>/Debouncer11' */
  DW_Debouncer11_SWC_TRSP_T Debouncer11_f;/* '<S6>/Debouncer11' */
  DW_Debouncer11_SWC_TRSP_T Debouncer11;/* '<S5>/Debouncer11' */
} DW_SWC_TRSP_T;

/* Real-time Model Data Structure */
struct tag_RTM_SWC_TRSP_T {
  const char_T *errorStatus;
};

/* Block signals (default storage) */
extern B_SWC_TRSP_T SWC_TRSP_B;

/* Block states (default storage) */
extern DW_SWC_TRSP_T SWC_TRSP_DW;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern float32 VAR_NvM_AngAutoClbOffset_f32;/* '<S3>/Signal Conversion4' */
extern float32 VAR_L2Com_TrqSetP_f32;  /* '<S2>/Signal Conversion7' */
extern float32 VAR_L2Sampling_IsU_Mon_f32;/* '<S1>/Signal Conversion12' */
extern float32 VAR_L2Sampling_IsV_Mon_f32;/* '<S1>/Signal Conversion13' */
extern float32 VAR_L2Sampling_IsW_Mon_f32;/* '<S1>/Signal Conversion14' */
extern float32 VAR_TRSP_UBRWIDE_f32;   /* '<S78>/Product' */
extern float32 VAR_TRSP_UB_SBC_f32;    /* '<S78>/Product2' */
extern float32 VAR_TRSP_Diff_UBR_SBC_f32;/* '<S77>/Add' */
extern float32 VAR_TRSP_RslvSqrt_f32;  /* '<S57>/Sqrt' */
extern float32 VAR_TRSP_RslvSin_f32;   /* '<S56>/Data Type Conversion4' */
extern float32 VAR_TRSP_RslvCos_f32;   /* '<S56>/Data Type Conversion1' */
extern float32 VAR_TRSP_iU_f32;        /* '<S34>/Switch5' */
extern float32 VAR_TRSP_iW_f32;        /* '<S34>/Switch6' */
extern float32 VAR_TRSP_iV_f32;        /* '<S34>/Product1' */
extern float32 VAR_TRSP_iSum_f32;      /* '<S26>/Add' */
extern float32 VAR_TRSP_AgRtr_f32;     /* '<S8>/Switch' */
extern sint32 VAR_L2Sampling_RslvCos_s32;/* '<S1>/Signal Conversion24' */
extern sint32 VAR_L2Sampling_RslvSin_s32;/* '<S1>/Signal Conversion23' */
extern uint16 VAR_L2Com_ModeReq_u16;   /* '<S3>/Signal Conversion1' */
extern uint16 VAR_L2Sampling_RslvSinP_VADC_u16[32];/* '<S1>/Signal Conversion15' */
extern uint16 VAR_L2Sampling_RslvSinN_VADC_u16[32];/* '<S1>/Signal Conversion16' */
extern uint16 VAR_L2Sampling_RslvCosP_VADC_u16[32];/* '<S1>/Signal Conversion17' */
extern uint16 VAR_L2Sampling_RslvCosN_VADC_u16[32];/* '<S1>/Signal Conversion18' */
extern uint16 VAR_L2Sampling_RslvCosP_VADC_Max1_u16;/* '<S10>/RslvRngChk2' */
extern uint16 VAR_L2Sampling_RslvCosP_VADC_Min1_u16;/* '<S10>/RslvRngChk2' */
extern uint16 VAR_L2Sampling_RslvSinN_VADC_Max1_u16;/* '<S10>/RslvRngChk1' */
extern uint16 VAR_L2Sampling_RslvSinN_VADC_Min1_u16;/* '<S10>/RslvRngChk1' */
extern uint16 VAR_L2Sampling_RslvSinP_VADC_Max1_u16;/* '<S10>/RslvRngChk' */
extern uint16 VAR_L2Sampling_RslvSinP_VADC_Min1_u16;/* '<S10>/RslvRngChk' */
extern uint16 VAR_L2Sampling_RslvCosN_VADC_Max1_u16;/* '<S10>/RslvRngChk3' */
extern uint16 VAR_L2Sampling_RslvCosN_VADC_Min1_u16;/* '<S10>/RslvRngChk3' */
extern uint16 VAR_L2Sampling_ExciBackP_u16;/* '<S1>/Signal Conversion19' */
extern uint16 VAR_L2Sampling_ExciBackN_u16;/* '<S1>/Signal Conversion20' */
extern uint16 VAR_L2Sampling_Exci18VLS_MON_u16;/* '<S1>/Signal Conversion21' */
extern uint16 VAR_L2Sampling_LEM5V_MON_u16;/* '<S1>/Signal Conversion22' */
extern uint16 VAR_L2Sampling_UBRWIDE_MON_u16;/* '<S1>/Signal Conversion25' */
extern uint16 VAR_L2Sampling_UB_SBC_MON_u16;/* '<S1>/Signal Conversion27' */
extern uint16 VAR_L2Sampling_18VHS_MON_u16;/* '<S1>/Signal Conversion29' */
extern uint16 VAR_L2Sampling_3V3CPLD_MON_u16;/* '<S1>/Signal Conversion31' */
extern uint16 VAR_L2Sampling_1V8CPLD_MON_u16;/* '<S1>/Signal Conversion33' */
extern boolean VAR_TRSP_OfstRngChkRslt_b;/* '<S97>/OfstRngChk' */
extern boolean VAR_TRSP_OfstRngErr_b;  /* '<S99>/Logical Operator' */
extern boolean VAR_TRSP_TrqSetPRngChkRslt_b;/* '<S85>/RngChk2' */
extern boolean VAR_TRSP_TrqSetPRngErr_b;/* '<S85>/Debouncer15' */
extern boolean VAR_TRSP_RslvCosNRngChkRslt_b;/* '<S10>/RslvRngChk3' */
extern boolean VAR_TRSP_RslvCosNRngErr_b;/* '<S10>/Debouncer7' */
extern boolean VAR_TRSP_RslvSinPRngChkRslt_b;/* '<S10>/RslvRngChk' */
extern boolean VAR_TRSP_RslvSinPRngErr_b;/* '<S10>/Debouncer4' */
extern boolean VAR_TRSP_RslvSinNRngChkRslt_b;/* '<S10>/RslvRngChk1' */
extern boolean VAR_TRSP_RslvSinNRngErr_b;/* '<S10>/Debouncer5' */
extern boolean VAR_TRSP_RslvCosPRngChkRslt_b;/* '<S10>/RslvRngChk2' */
extern boolean VAR_TRSP_RslvCosPRngErr_b;/* '<S10>/Debouncer6' */
extern boolean VAR_TRSP_RslvRngErr_b;  /* '<S10>/Logical Operator' */
extern boolean VAR_TRSP_RslvSqrtErr_b; /* '<S10>/Debouncer8' */
extern boolean VAR_TRSP_UCurrRngChkRslt_b;/* '<S9>/RngChk' */
extern boolean VAR_TRSP_UCurrRngErr_b; /* '<S9>/Debouncer' */
extern boolean VAR_TRSP_VCurrRngChkRslt_b;/* '<S9>/RngChk1' */
extern boolean VAR_TRSP_VCurrRngErr_b; /* '<S9>/Debouncer1' */
extern boolean VAR_TRSP_WCurrRngChkRslt_b;/* '<S9>/RngChk2' */
extern boolean VAR_TRSP_WCurrRngErr_b; /* '<S9>/Debouncer2' */
extern boolean VAR_TRSP_CurrRngErr_b;  /* '<S9>/Logical Operator' */
extern boolean VAR_TRSP_CurrSumErr_b;  /* '<S9>/Debouncer3' */
extern boolean VAR_TRSP_RslvExciPRngChkRslt_b;/* '<S10>/RngChk2' */
extern boolean VAR_TRSP_RslvExciPRngErr_b;/* '<S10>/Debouncer9' */
extern boolean VAR_TRSP_RslvExciNRngChkRslt_b;/* '<S10>/RngChk1' */
extern boolean VAR_TRSP_RslvExciNRngErr_b;/* '<S10>/Debouncer10' */
extern boolean VAR_TRSP_RslvExciRngErr_b;/* '<S10>/Logical Operator1' */
extern boolean VAR_TRSP_RslvSensVoltRngChkRslt_b;/* '<S11>/RngChk' */
extern boolean VAR_TRSP_RslvSensVoltRngErr_b;/* '<S11>/Debouncer11' */
extern boolean VAR_TRSP_iPhasSensVoltRngChkRslt_b;/* '<S13>/RngChk' */
extern boolean VAR_TRSP_iPhasSensVoltRngErr_b;/* '<S13>/Debouncer12' */
extern boolean VAR_TRSP_UBRVoltRngErr_b;/* '<S12>/Debouncer11' */
extern boolean VAR_TRSP_18VHSVoltRngChkRslt_b;/* '<S5>/RngChk' */
extern boolean VAR_TRSP_18VHSVoltRngErr_b;/* '<S5>/Debouncer11' */
extern boolean VAR_TRSP_3V3CPLDVoltRngChkRslt_b;/* '<S7>/RngChk' */
extern boolean VAR_TRSP_3V3CPLDVoltRngErr_b;/* '<S7>/Debouncer11' */
extern boolean VAR_TRSP_1V8CPLDVoltRngChkRslt_b;/* '<S6>/RngChk' */
extern boolean VAR_TRSP_1V8CPLDVoltRngErr_b;/* '<S6>/Debouncer11' */
extern boolean VAR_TRSP_UBRVoltRngChkRslt_b;/* '<S77>/Relational Operator' */
extern boolean VAR_TRSP_RslvSqrtChkRslt_b;/* '<S57>/Logical Operator' */
extern boolean VAR_TRSP_CurrSumChkRslt_b;/* '<S26>/Relational Operator' */

/* Model entry point functions */
extern void SWC_TRSP_initialize(void);

/* Exported entry point function */
extern void SWC_TRSP_100us(void);

/* Exported entry point function */
extern void SWC_TRSP_1ms(void);

/* Exported entry point function */
extern void SWC_TRSP_10ms(void);

/* Exported data declaration */
#pragma section ".rodata.Calib_32"

/* Declaration for custom storage class: iEDS_Parameter */
extern const volatile sint16 CAL_TRSP_18VHSVoltCountTrh_s16;
                           /* Referenced by: '<S5>/CAL_TOM_CurrRngDebTrh_s16' */
extern const volatile sint16 CAL_TRSP_18VHSVoltDebTrh_s16;
                            /* Referenced by: '<S5>/CAL_TOM_CurrRngDebTrh_s1' */
extern const volatile boolean CAL_TRSP_18VHSVoltErrRst_b;
                            /* Referenced by: '<S5>/CAL_TOM_CurrRngErrRst_b1' */
extern const volatile uint16 CAL_TRSP_18VHSVoltHiLim_u16;
                            /* Referenced by: '<S5>/CAL_TOM_CurrRngHiLim_f32' */
extern const volatile uint16 CAL_TRSP_18VHSVoltLoLim_u16;
                            /* Referenced by: '<S5>/CAL_TOM_CurrRngLoLim_f32' */
extern const volatile sint16 CAL_TRSP_1V8CPLDVoltCountTrh_s16;
                           /* Referenced by: '<S6>/CAL_TOM_CurrRngDebTrh_s16' */
extern const volatile sint16 CAL_TRSP_1V8CPLDVoltDebTrh_s16;
                            /* Referenced by: '<S6>/CAL_TOM_CurrRngDebTrh_s1' */
extern const volatile boolean CAL_TRSP_1V8CPLDVoltErrRst_b;
                            /* Referenced by: '<S6>/CAL_TOM_CurrRngErrRst_b1' */
extern const volatile uint16 CAL_TRSP_1V8CPLDVoltHiLim_u16;
                            /* Referenced by: '<S6>/CAL_TOM_CurrRngHiLim_f32' */
extern const volatile uint16 CAL_TRSP_1V8CPLDVoltLoLim_u16;
                            /* Referenced by: '<S6>/CAL_TOM_CurrRngLoLim_f32' */
extern const volatile sint16 CAL_TRSP_3V3CPLDVoltCountTrh_s16;
                           /* Referenced by: '<S7>/CAL_TOM_CurrRngDebTrh_s16' */
extern const volatile sint16 CAL_TRSP_3V3CPLDVoltDebTrh_s16;
                            /* Referenced by: '<S7>/CAL_TOM_CurrRngDebTrh_s1' */
extern const volatile boolean CAL_TRSP_3V3CPLDVoltErrRst_b;
                            /* Referenced by: '<S7>/CAL_TOM_CurrRngErrRst_b1' */
extern const volatile uint16 CAL_TRSP_3V3CPLDVoltHiLim_u16;
                            /* Referenced by: '<S7>/CAL_TOM_CurrRngHiLim_f32' */
extern const volatile uint16 CAL_TRSP_3V3CPLDVoltLoLim_u16;
                            /* Referenced by: '<S7>/CAL_TOM_CurrRngLoLim_f32' */
extern const volatile uint8 CAL_TRSP_AgTimecompCtl_u8;
                                  /* Referenced by: '<S8>/GLB_TOM_CircAge_f3' */
extern const volatile sint16 CAL_TRSP_CurrRngCountTrh_s16;/* Referenced by:
                                                           * '<S9>/CAL_TOM_CurrRngDebAdd_s1'
                                                           * '<S9>/CAL_TOM_CurrRngDebAdd_s2'
                                                           * '<S9>/CAL_TOM_CurrRngDebAdd_s3'
                                                           */
extern const volatile sint16 CAL_TRSP_CurrRngDebTrh_s16;/* Referenced by:
                                                         * '<S9>/CAL_TOM_CurrRngDebTrh_s1'
                                                         * '<S9>/CAL_TOM_CurrRngDebTrh_s16'
                                                         * '<S9>/CAL_TOM_CurrRngDebTrh_s2'
                                                         */
extern const volatile boolean CAL_TRSP_CurrRngErrRst_b;/* Referenced by:
                                                        * '<S9>/CAL_TOM_CurrRngErrRst_b'
                                                        * '<S9>/CAL_TOM_CurrRngErrRst_b1'
                                                        * '<S9>/CAL_TOM_CurrRngErrRst_b2'
                                                        */
extern const volatile sint16 CAL_TRSP_CurrSumCountTrh_s16;
                            /* Referenced by: '<S9>/CAL_TOM_CurrSumDebAdd_s1' */
extern const volatile sint16 CAL_TRSP_CurrSumDebTrh_s16;
                           /* Referenced by: '<S9>/CAL_TOM_CurrSumDebTrh_s16' */
extern const volatile boolean CAL_TRSP_CurrSumErrRst_b;
                             /* Referenced by: '<S9>/CAL_TOM_CurrSumErrRst_b' */
extern const volatile float32 CAL_TRSP_CurrSumLim_f32;
                             /* Referenced by: '<S26>/CAL_TOM_CurrSumLim_f32' */
extern const volatile float32 CAL_TRSP_Diff_UBR_SBCLim_f32;
                             /* Referenced by: '<S77>/CAL_TOM_CurrSumLim_f32' */
extern const volatile boolean CAL_TRSP_OfstErrRst_b;
                               /* Referenced by: '<S97>/CAL_TOM_OfstErrRst_b' */
extern const volatile float32 CAL_TRSP_OfstRngHiLim_f32;
                           /* Referenced by: '<S97>/CAL_TOM_OfstRngHiLim_f32' */
extern const volatile float32 CAL_TRSP_OfstRngLoLim_f32;
                           /* Referenced by: '<S97>/CAL_TOM_OfstRngLoLim_f32' */
extern const volatile sint16 CAL_TRSP_ReqTrqCountTrh_s16;
                           /* Referenced by: '<S85>/CAL_TOM_CurrRngDebTrh_s5' */
extern const volatile sint16 CAL_TRSP_ReqTrqDebTrh_s16;
                           /* Referenced by: '<S85>/CAL_TOM_CurrRngDebTrh_s4' */
extern const volatile boolean CAL_TRSP_ReqTrqErrRst_b;
                           /* Referenced by: '<S85>/CAL_TOM_CurrRngErrRst_b3' */
extern const volatile float32 CAL_TRSP_ReqTrqHiLim_f32;
                            /* Referenced by: '<S85>/CAL_TOM_CurrRngHiLim_f2' */
extern const volatile float32 CAL_TRSP_ReqTrqLoLim_f32;
                            /* Referenced by: '<S85>/CAL_TOM_CurrRngLoLim_f2' */
extern const volatile sint16 CAL_TRSP_RslvExciCountTrh_s16;/* Referenced by:
                                                            * '<S10>/CAL_TOM_RslvExciDebTrh_s16'
                                                            * '<S10>/CAL_TOM_RslvExciDebTrh_s3'
                                                            */
extern const volatile sint16 CAL_TRSP_RslvExciDebTrh_s16;/* Referenced by:
                                                          * '<S10>/CAL_TOM_RslvExciDebTrh_s1'
                                                          * '<S10>/CAL_TOM_RslvExciDebTrh_s2'
                                                          */
extern const volatile boolean CAL_TRSP_RslvExciErrRst_b;/* Referenced by:
                                                         * '<S10>/CAL_TOM_RslvExciErrRst_b'
                                                         * '<S10>/CAL_TOM_RslvExciErrRst_b1'
                                                         */
extern const volatile uint16 CAL_TRSP_RslvRngCosNHiLim_u16;
                         /* Referenced by: '<S10>/CAL_TOM_RslvRngSinHiLim_f3' */
extern const volatile uint16 CAL_TRSP_RslvRngCosNLoLim_u16;
                         /* Referenced by: '<S10>/CAL_TOM_RslvRngSinLoLim_f3' */
extern const volatile uint16 CAL_TRSP_RslvRngCosPHiLim_u16;
                         /* Referenced by: '<S10>/CAL_TOM_RslvRngSinHiLim_f2' */
extern const volatile uint16 CAL_TRSP_RslvRngCosPLoLim_u16;
                         /* Referenced by: '<S10>/CAL_TOM_RslvRngSinLoLim_f2' */
extern const volatile sint16 CAL_TRSP_RslvRngCountTrh_s16;/* Referenced by:
                                                           * '<S10>/CAL_TOM_RslvRngDebTrh_s16'
                                                           * '<S10>/CAL_TOM_RslvRngDebTrh_s3'
                                                           * '<S10>/CAL_TOM_RslvRngDebTrh_s5'
                                                           * '<S10>/CAL_TOM_RslvRngDebTrh_s7'
                                                           */
extern const volatile sint16 CAL_TRSP_RslvRngDebTrh_s16;/* Referenced by:
                                                         * '<S10>/CAL_TOM_RslvRngDebTrh_s1'
                                                         * '<S10>/CAL_TOM_RslvRngDebTrh_s2'
                                                         * '<S10>/CAL_TOM_RslvRngDebTrh_s4'
                                                         * '<S10>/CAL_TOM_RslvRngDebTrh_s6'
                                                         */
extern const volatile boolean CAL_TRSP_RslvRngErrRst_b;/* Referenced by:
                                                        * '<S10>/CAL_TOM_RslvRngErrRst_b'
                                                        * '<S10>/CAL_TOM_RslvRngErrRst_b1'
                                                        * '<S10>/CAL_TOM_RslvRngErrRst_b2'
                                                        * '<S10>/CAL_TOM_RslvRngErrRst_b3'
                                                        */
extern const volatile uint16 CAL_TRSP_RslvRngExciHiLim_u16;/* Referenced by:
                                                            * '<S10>/CAL_TOM_RslvRngExciHiLim_f1'
                                                            * '<S10>/CAL_TOM_RslvRngExciHiLim_f32'
                                                            */
extern const volatile uint16 CAL_TRSP_RslvRngExciLoLim_u16;/* Referenced by:
                                                            * '<S10>/CAL_TOM_RslvRngExciLoLim_f1'
                                                            * '<S10>/CAL_TOM_RslvRngExciLoLim_f32'
                                                            */
extern const volatile uint16 CAL_TRSP_RslvRngSinNHiLim_u16;
                         /* Referenced by: '<S10>/CAL_TOM_RslvRngSinHiLim_f1' */
extern const volatile uint16 CAL_TRSP_RslvRngSinNLoLim_u16;
                         /* Referenced by: '<S10>/CAL_TOM_RslvRngSinLoLim_f1' */
extern const volatile uint16 CAL_TRSP_RslvRngSinPHiLim_u16;
                        /* Referenced by: '<S10>/CAL_TOM_RslvRngSinHiLim_f32' */
extern const volatile uint16 CAL_TRSP_RslvRngSinPLoLim_u16;
                        /* Referenced by: '<S10>/CAL_TOM_RslvRngSinLoLim_f32' */
extern const volatile sint16 CAL_TRSP_RslvSensVoltCountTrh_s16;
                          /* Referenced by: '<S11>/CAL_TOM_CurrRngDebTrh_s16' */
extern const volatile sint16 CAL_TRSP_RslvSensVoltDebTrh_s16;
                           /* Referenced by: '<S11>/CAL_TOM_CurrRngDebTrh_s1' */
extern const volatile boolean CAL_TRSP_RslvSensVoltErrRst_b;
                           /* Referenced by: '<S11>/CAL_TOM_CurrRngErrRst_b1' */
extern const volatile uint16 CAL_TRSP_RslvSensVoltHiLim_u16;
                           /* Referenced by: '<S11>/CAL_TOM_CurrRngHiLim_f32' */
extern const volatile uint16 CAL_TRSP_RslvSensVoltLoLim_u16;
                           /* Referenced by: '<S11>/CAL_TOM_CurrRngLoLim_f32' */
extern const volatile sint16 CAL_TRSP_RslvSqrtCountTrh_s16;
                         /* Referenced by: '<S10>/CAL_TOM_RslvSqrtDebTrh_s16' */
extern const volatile sint16 CAL_TRSP_RslvSqrtDebTrh_s16;
                          /* Referenced by: '<S10>/CAL_TOM_RslvSqrtDebTrh_s1' */
extern const volatile boolean CAL_TRSP_RslvSqrtErrRst_b;
                           /* Referenced by: '<S10>/CAL_TOM_RslvSqrtErrRst_b' */
extern const volatile uint16 CAL_TRSP_RslvSqrtHiLim_u16;
                            /* Referenced by: '<S57>/CAL_TOM_RslvSqrtLim_f32' */
extern const volatile uint16 CAL_TRSP_RslvSqrtLoLim_u16;
                             /* Referenced by: '<S57>/CAL_TOM_RslvSqrtLim_f1' */
extern const volatile uint8 CAL_TRSP_SpeedCtlMode_u8;
                            /* Referenced by: '<S98>/CAL_TOM_SpeedCtlMode_u3' */
extern const volatile uint8 CAL_TRSP_TorqueCtlMode_u8;
                            /* Referenced by: '<S98>/CAL_TOM_SpeedCtlMode_u2' */
extern const volatile sint16 CAL_TRSP_UBRVoltCountTrh_s16;
                          /* Referenced by: '<S12>/CAL_TOM_CurrRngDebTrh_s16' */
extern const volatile sint16 CAL_TRSP_UBRVoltDebTrh_s16;
                           /* Referenced by: '<S12>/CAL_TOM_CurrRngDebTrh_s1' */
extern const volatile boolean CAL_TRSP_UBRVoltErrRst_b;
                           /* Referenced by: '<S12>/CAL_TOM_CurrRngErrRst_b1' */
extern const volatile float32 CAL_TRSP_UBRWIDECnvFac_f32;
                               /* Referenced by: '<S78>/CAL_CSP_iUCnvFac_f32' */
extern const volatile float32 CAL_TRSP_UB_SBCCnvFac_f32;
                               /* Referenced by: '<S78>/CAL_MCF_iWCnvFac_f32' */
extern const volatile float32 CAL_TRSP_UCurrRngHiLim_f32;
                             /* Referenced by: '<S9>/CAL_TOM_CurrRngHiLim_f1' */
extern const volatile float32 CAL_TRSP_UCurrRngLoLim_f32;
                             /* Referenced by: '<S9>/CAL_TOM_CurrRngLoLim_f1' */
extern const volatile float32 CAL_TRSP_VCurrRngHiLim_f32;
                             /* Referenced by: '<S9>/CAL_TOM_CurrRngHiLim_f2' */
extern const volatile float32 CAL_TRSP_VCurrRngLoLim_f32;
                             /* Referenced by: '<S9>/CAL_TOM_CurrRngLoLim_f2' */
extern const volatile float32 CAL_TRSP_WCurrRngHiLim_f32;
                             /* Referenced by: '<S9>/CAL_TOM_CurrRngHiLim_f3' */
extern const volatile float32 CAL_TRSP_WCurrRngLoLim_f32;
                             /* Referenced by: '<S9>/CAL_TOM_CurrRngLoLim_f3' */
extern const volatile boolean CAL_TRSP_flgChangPha_b;
                              /* Referenced by: '<S34>/CAL_CSP_flgChangPha_b' */
extern const volatile float32 CAL_TRSP_iPhaUOffset_f32;
                                /* Referenced by: '<S34>/CAL_CSP_iUCnvFac_f1' */
extern const volatile float32 CAL_TRSP_iPhaVOffset_f32;
                                /* Referenced by: '<S34>/CAL_CSP_iUCnvFac_f2' */
extern const volatile float32 CAL_TRSP_iPhaWOffset_f32;
                                /* Referenced by: '<S34>/CAL_CSP_iUCnvFac_f3' */
extern const volatile sint16 CAL_TRSP_iPhasSensVoltCountTrh_s16;
                          /* Referenced by: '<S13>/CAL_TOM_CurrRngDebTrh_s16' */
extern const volatile sint16 CAL_TRSP_iPhasSensVoltDebTrh_s16;
                           /* Referenced by: '<S13>/CAL_TOM_CurrRngDebTrh_s1' */
extern const volatile boolean CAL_TRSP_iPhasSensVoltErrRst_b;
                            /* Referenced by: '<S13>/CAL_TOM_CurrRngErrRst_b' */
extern const volatile uint16 CAL_TRSP_iPhasSensVoltHiLim_u16;
                            /* Referenced by: '<S13>/CAL_TOM_CurrRngHiLim_f1' */
extern const volatile uint16 CAL_TRSP_iPhasSensVoltLoLim_u16;
                           /* Referenced by: '<S13>/CAL_TOM_CurrRngLoLim_f32' */
extern const volatile float32 CAL_TRSP_iUCnvFac_f32;
                               /* Referenced by: '<S34>/CAL_CSP_iUCnvFac_f32' */
extern const volatile float32 CAL_TRSP_iVCnvFac_f32;
                               /* Referenced by: '<S34>/CAL_CSP_iVCnvFac_f32' */
extern const volatile float32 CAL_TRSP_iWCnvFac_f32;
                               /* Referenced by: '<S34>/CAL_MCF_iWCnvFac_f32' */

#pragma section

/* Real-time Model object */
extern RT_MODEL_SWC_TRSP_T *const SWC_TRSP_M;

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
 * '<Root>' : 'SWC_TRSP'
 * '<S1>'   : 'SWC_TRSP/SWC_TRSP_100us_sys'
 * '<S2>'   : 'SWC_TRSP/SWC_TRSP_10ms_sys'
 * '<S3>'   : 'SWC_TRSP/SWC_TRSP_1ms_sys'
 * '<S4>'   : 'SWC_TRSP/SWC_TRSP_Init'
 * '<S5>'   : 'SWC_TRSP/SWC_TRSP_100us_sys/18VHSVoltChk'
 * '<S6>'   : 'SWC_TRSP/SWC_TRSP_100us_sys/1V8CPLDVoltChk'
 * '<S7>'   : 'SWC_TRSP/SWC_TRSP_100us_sys/3V3CPLDVoltChk'
 * '<S8>'   : 'SWC_TRSP/SWC_TRSP_100us_sys/AgRtrCalc'
 * '<S9>'   : 'SWC_TRSP/SWC_TRSP_100us_sys/CurrChk'
 * '<S10>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/RslvChk'
 * '<S11>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/RslvSensVoltChk'
 * '<S12>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/UBRVoltChk'
 * '<S13>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/iPhasSensVoltChk'
 * '<S14>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/18VHSVoltChk/Debouncer11'
 * '<S15>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/18VHSVoltChk/RngChk'
 * '<S16>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/18VHSVoltChk/Debouncer11/Compare To Zero'
 * '<S17>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/18VHSVoltChk/Debouncer11/Count'
 * '<S18>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/1V8CPLDVoltChk/Debouncer11'
 * '<S19>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/1V8CPLDVoltChk/RngChk'
 * '<S20>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/1V8CPLDVoltChk/Debouncer11/Compare To Zero'
 * '<S21>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/1V8CPLDVoltChk/Debouncer11/Count'
 * '<S22>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/3V3CPLDVoltChk/Debouncer11'
 * '<S23>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/3V3CPLDVoltChk/RngChk'
 * '<S24>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/3V3CPLDVoltChk/Debouncer11/Compare To Zero'
 * '<S25>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/3V3CPLDVoltChk/Debouncer11/Count'
 * '<S26>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/CurrChk/CurrSumChk'
 * '<S27>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/CurrChk/Debouncer'
 * '<S28>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/CurrChk/Debouncer1'
 * '<S29>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/CurrChk/Debouncer2'
 * '<S30>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/CurrChk/Debouncer3'
 * '<S31>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/CurrChk/RngChk'
 * '<S32>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/CurrChk/RngChk1'
 * '<S33>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/CurrChk/RngChk2'
 * '<S34>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/CurrChk/iPhaCalc'
 * '<S35>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/CurrChk/Debouncer/Compare To Zero'
 * '<S36>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/CurrChk/Debouncer/Count'
 * '<S37>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/CurrChk/Debouncer1/Compare To Zero'
 * '<S38>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/CurrChk/Debouncer1/Count'
 * '<S39>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/CurrChk/Debouncer2/Compare To Zero'
 * '<S40>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/CurrChk/Debouncer2/Count'
 * '<S41>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/CurrChk/Debouncer3/Compare To Zero'
 * '<S42>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/CurrChk/Debouncer3/Count'
 * '<S43>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/RslvChk/Debouncer10'
 * '<S44>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/RslvChk/Debouncer4'
 * '<S45>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/RslvChk/Debouncer5'
 * '<S46>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/RslvChk/Debouncer6'
 * '<S47>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/RslvChk/Debouncer7'
 * '<S48>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/RslvChk/Debouncer8'
 * '<S49>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/RslvChk/Debouncer9'
 * '<S50>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/RslvChk/RngChk1'
 * '<S51>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/RslvChk/RngChk2'
 * '<S52>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/RslvChk/RslvRngChk'
 * '<S53>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/RslvChk/RslvRngChk1'
 * '<S54>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/RslvChk/RslvRngChk2'
 * '<S55>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/RslvChk/RslvRngChk3'
 * '<S56>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/RslvChk/RslvSigCalc'
 * '<S57>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/RslvChk/RslvSqrtChk'
 * '<S58>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/RslvChk/Debouncer10/Compare To Zero'
 * '<S59>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/RslvChk/Debouncer10/Count'
 * '<S60>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/RslvChk/Debouncer4/Compare To Zero'
 * '<S61>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/RslvChk/Debouncer4/Count'
 * '<S62>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/RslvChk/Debouncer5/Compare To Zero'
 * '<S63>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/RslvChk/Debouncer5/Count'
 * '<S64>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/RslvChk/Debouncer6/Compare To Zero'
 * '<S65>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/RslvChk/Debouncer6/Count'
 * '<S66>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/RslvChk/Debouncer7/Compare To Zero'
 * '<S67>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/RslvChk/Debouncer7/Count'
 * '<S68>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/RslvChk/Debouncer8/Compare To Zero'
 * '<S69>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/RslvChk/Debouncer8/Count'
 * '<S70>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/RslvChk/Debouncer9/Compare To Zero'
 * '<S71>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/RslvChk/Debouncer9/Count'
 * '<S72>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/RslvSensVoltChk/Debouncer11'
 * '<S73>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/RslvSensVoltChk/RngChk'
 * '<S74>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/RslvSensVoltChk/Debouncer11/Compare To Zero'
 * '<S75>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/RslvSensVoltChk/Debouncer11/Count'
 * '<S76>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/UBRVoltChk/Debouncer11'
 * '<S77>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/UBRVoltChk/UBRVoltCompChk'
 * '<S78>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/UBRVoltChk/UBR_SBCVoltCalc'
 * '<S79>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/UBRVoltChk/Debouncer11/Compare To Zero'
 * '<S80>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/UBRVoltChk/Debouncer11/Count'
 * '<S81>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/iPhasSensVoltChk/Debouncer12'
 * '<S82>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/iPhasSensVoltChk/RngChk'
 * '<S83>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/iPhasSensVoltChk/Debouncer12/Compare To Zero'
 * '<S84>'  : 'SWC_TRSP/SWC_TRSP_100us_sys/iPhasSensVoltChk/Debouncer12/Count'
 * '<S85>'  : 'SWC_TRSP/SWC_TRSP_10ms_sys/CANSigChk'
 * '<S86>'  : 'SWC_TRSP/SWC_TRSP_10ms_sys/Debouncer'
 * '<S87>'  : 'SWC_TRSP/SWC_TRSP_10ms_sys/CANSigChk/Debouncer15'
 * '<S88>'  : 'SWC_TRSP/SWC_TRSP_10ms_sys/CANSigChk/RngChk2'
 * '<S89>'  : 'SWC_TRSP/SWC_TRSP_10ms_sys/CANSigChk/Debouncer15/Compare To Zero'
 * '<S90>'  : 'SWC_TRSP/SWC_TRSP_10ms_sys/CANSigChk/Debouncer15/Count'
 * '<S91>'  : 'SWC_TRSP/SWC_TRSP_10ms_sys/Debouncer/Compare To Zero'
 * '<S92>'  : 'SWC_TRSP/SWC_TRSP_10ms_sys/Debouncer/Subsystem'
 * '<S93>'  : 'SWC_TRSP/SWC_TRSP_1ms_sys/Debouncer'
 * '<S94>'  : 'SWC_TRSP/SWC_TRSP_1ms_sys/OfstAgChk'
 * '<S95>'  : 'SWC_TRSP/SWC_TRSP_1ms_sys/Debouncer/Compare To Zero'
 * '<S96>'  : 'SWC_TRSP/SWC_TRSP_1ms_sys/Debouncer/Subsystem'
 * '<S97>'  : 'SWC_TRSP/SWC_TRSP_1ms_sys/OfstAgChk/OfstChk'
 * '<S98>'  : 'SWC_TRSP/SWC_TRSP_1ms_sys/OfstAgChk/OfstChkEnable'
 * '<S99>'  : 'SWC_TRSP/SWC_TRSP_1ms_sys/OfstAgChk/OfstChk/Lock'
 * '<S100>' : 'SWC_TRSP/SWC_TRSP_1ms_sys/OfstAgChk/OfstChk/OfstRngChk'
 * '<S101>' : 'SWC_TRSP/SWC_TRSP_1ms_sys/OfstAgChk/OfstChkEnable/Compare To Constant'
 */
#endif                                 /* RTW_HEADER_SWC_TRSP_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
