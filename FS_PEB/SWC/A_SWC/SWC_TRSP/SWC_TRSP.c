/*
 * File: SWC_TRSP.c
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

#include "SWC_TRSP.h"
#include "SWC_TRSP_private.h"

/* user code (top of source file) */
#include "set_get_data.h"

/* Exported block signals */
float32 VAR_NvM_AngAutoClbOffset_f32;  /* '<S3>/Signal Conversion4' */
float32 VAR_L2Com_TrqSetP_f32;         /* '<S2>/Signal Conversion7' */
float32 VAR_L2Sampling_IsU_Mon_f32;    /* '<S1>/Signal Conversion12' */
float32 VAR_L2Sampling_IsV_Mon_f32;    /* '<S1>/Signal Conversion13' */
float32 VAR_L2Sampling_IsW_Mon_f32;    /* '<S1>/Signal Conversion14' */
float32 VAR_TRSP_UBRWIDE_f32;          /* '<S78>/Product' */
float32 VAR_TRSP_UB_SBC_f32;           /* '<S78>/Product2' */
float32 VAR_TRSP_Diff_UBR_SBC_f32;     /* '<S77>/Add' */
float32 VAR_TRSP_RslvSqrt_f32;         /* '<S57>/Sqrt' */
float32 VAR_TRSP_RslvSin_f32;          /* '<S56>/Data Type Conversion4' */
float32 VAR_TRSP_RslvCos_f32;          /* '<S56>/Data Type Conversion1' */
float32 VAR_TRSP_iU_f32;               /* '<S34>/Switch5' */
float32 VAR_TRSP_iW_f32;               /* '<S34>/Switch6' */
float32 VAR_TRSP_iV_f32;               /* '<S34>/Product1' */
float32 VAR_TRSP_iSum_f32;             /* '<S26>/Add' */
float32 VAR_TRSP_AgRtr_f32;            /* '<S8>/Switch' */
sint32 VAR_L2Sampling_RslvCos_s32;     /* '<S1>/Signal Conversion24' */
sint32 VAR_L2Sampling_RslvSin_s32;     /* '<S1>/Signal Conversion23' */
uint16 VAR_L2Com_ModeReq_u16;          /* '<S3>/Signal Conversion1' */
uint16 VAR_L2Sampling_RslvSinP_VADC_u16[32];/* '<S1>/Signal Conversion15' */
uint16 VAR_L2Sampling_RslvSinN_VADC_u16[32];/* '<S1>/Signal Conversion16' */
uint16 VAR_L2Sampling_RslvCosP_VADC_u16[32];/* '<S1>/Signal Conversion17' */
uint16 VAR_L2Sampling_RslvCosN_VADC_u16[32];/* '<S1>/Signal Conversion18' */
uint16 VAR_L2Sampling_RslvCosP_VADC_Max1_u16;/* '<S10>/RslvRngChk2' */
uint16 VAR_L2Sampling_RslvCosP_VADC_Min1_u16;/* '<S10>/RslvRngChk2' */
uint16 VAR_L2Sampling_RslvSinN_VADC_Max1_u16;/* '<S10>/RslvRngChk1' */
uint16 VAR_L2Sampling_RslvSinN_VADC_Min1_u16;/* '<S10>/RslvRngChk1' */
uint16 VAR_L2Sampling_RslvSinP_VADC_Max1_u16;/* '<S10>/RslvRngChk' */
uint16 VAR_L2Sampling_RslvSinP_VADC_Min1_u16;/* '<S10>/RslvRngChk' */
uint16 VAR_L2Sampling_RslvCosN_VADC_Max1_u16;/* '<S10>/RslvRngChk3' */
uint16 VAR_L2Sampling_RslvCosN_VADC_Min1_u16;/* '<S10>/RslvRngChk3' */
uint16 VAR_L2Sampling_ExciBackP_u16;   /* '<S1>/Signal Conversion19' */
uint16 VAR_L2Sampling_ExciBackN_u16;   /* '<S1>/Signal Conversion20' */
uint16 VAR_L2Sampling_Exci18VLS_MON_u16;/* '<S1>/Signal Conversion21' */
uint16 VAR_L2Sampling_LEM5V_MON_u16;   /* '<S1>/Signal Conversion22' */
uint16 VAR_L2Sampling_UBRWIDE_MON_u16; /* '<S1>/Signal Conversion25' */
uint16 VAR_L2Sampling_UB_SBC_MON_u16;  /* '<S1>/Signal Conversion27' */
uint16 VAR_L2Sampling_18VHS_MON_u16;   /* '<S1>/Signal Conversion29' */
uint16 VAR_L2Sampling_3V3CPLD_MON_u16; /* '<S1>/Signal Conversion31' */
uint16 VAR_L2Sampling_1V8CPLD_MON_u16; /* '<S1>/Signal Conversion33' */
boolean VAR_TRSP_OfstRngChkRslt_b;     /* '<S97>/OfstRngChk' */
boolean VAR_TRSP_OfstRngErr_b;         /* '<S99>/Logical Operator' */
boolean VAR_TRSP_TrqSetPRngChkRslt_b;  /* '<S85>/RngChk2' */
boolean VAR_TRSP_TrqSetPRngErr_b;      /* '<S85>/Debouncer15' */
boolean VAR_TRSP_RslvCosNRngChkRslt_b; /* '<S10>/RslvRngChk3' */
boolean VAR_TRSP_RslvCosNRngErr_b;     /* '<S10>/Debouncer7' */
boolean VAR_TRSP_RslvSinPRngChkRslt_b; /* '<S10>/RslvRngChk' */
boolean VAR_TRSP_RslvSinPRngErr_b;     /* '<S10>/Debouncer4' */
boolean VAR_TRSP_RslvSinNRngChkRslt_b; /* '<S10>/RslvRngChk1' */
boolean VAR_TRSP_RslvSinNRngErr_b;     /* '<S10>/Debouncer5' */
boolean VAR_TRSP_RslvCosPRngChkRslt_b; /* '<S10>/RslvRngChk2' */
boolean VAR_TRSP_RslvCosPRngErr_b;     /* '<S10>/Debouncer6' */
boolean VAR_TRSP_RslvRngErr_b;         /* '<S10>/Logical Operator' */
boolean VAR_TRSP_RslvSqrtErr_b;        /* '<S10>/Debouncer8' */
boolean VAR_TRSP_UCurrRngChkRslt_b;    /* '<S9>/RngChk' */
boolean VAR_TRSP_UCurrRngErr_b;        /* '<S9>/Debouncer' */
boolean VAR_TRSP_VCurrRngChkRslt_b;    /* '<S9>/RngChk1' */
boolean VAR_TRSP_VCurrRngErr_b;        /* '<S9>/Debouncer1' */
boolean VAR_TRSP_WCurrRngChkRslt_b;    /* '<S9>/RngChk2' */
boolean VAR_TRSP_WCurrRngErr_b;        /* '<S9>/Debouncer2' */
boolean VAR_TRSP_CurrRngErr_b;         /* '<S9>/Logical Operator' */
boolean VAR_TRSP_CurrSumErr_b;         /* '<S9>/Debouncer3' */
boolean VAR_TRSP_RslvExciPRngChkRslt_b;/* '<S10>/RngChk2' */
boolean VAR_TRSP_RslvExciPRngErr_b;    /* '<S10>/Debouncer9' */
boolean VAR_TRSP_RslvExciNRngChkRslt_b;/* '<S10>/RngChk1' */
boolean VAR_TRSP_RslvExciNRngErr_b;    /* '<S10>/Debouncer10' */
boolean VAR_TRSP_RslvExciRngErr_b;     /* '<S10>/Logical Operator1' */
boolean VAR_TRSP_RslvSensVoltRngChkRslt_b;/* '<S11>/RngChk' */
boolean VAR_TRSP_RslvSensVoltRngErr_b; /* '<S11>/Debouncer11' */
boolean VAR_TRSP_iPhasSensVoltRngChkRslt_b;/* '<S13>/RngChk' */
boolean VAR_TRSP_iPhasSensVoltRngErr_b;/* '<S13>/Debouncer12' */
boolean VAR_TRSP_UBRVoltRngErr_b;      /* '<S12>/Debouncer11' */
boolean VAR_TRSP_18VHSVoltRngChkRslt_b;/* '<S5>/RngChk' */
boolean VAR_TRSP_18VHSVoltRngErr_b;    /* '<S5>/Debouncer11' */
boolean VAR_TRSP_3V3CPLDVoltRngChkRslt_b;/* '<S7>/RngChk' */
boolean VAR_TRSP_3V3CPLDVoltRngErr_b;  /* '<S7>/Debouncer11' */
boolean VAR_TRSP_1V8CPLDVoltRngChkRslt_b;/* '<S6>/RngChk' */
boolean VAR_TRSP_1V8CPLDVoltRngErr_b;  /* '<S6>/Debouncer11' */
boolean VAR_TRSP_UBRVoltRngChkRslt_b;  /* '<S77>/Relational Operator' */
boolean VAR_TRSP_RslvSqrtChkRslt_b;    /* '<S57>/Logical Operator' */
boolean VAR_TRSP_CurrSumChkRslt_b;     /* '<S26>/Relational Operator' */

/* Exported data definition */
#pragma section ".rodata.Calib_32"

/* Definition for custom storage class: iEDS_Parameter */
const volatile sint16 CAL_TRSP_18VHSVoltCountTrh_s16 = 1000;
                           /* Referenced by: '<S5>/CAL_TOM_CurrRngDebTrh_s16' */
const volatile sint16 CAL_TRSP_18VHSVoltDebTrh_s16 = 500;
                            /* Referenced by: '<S5>/CAL_TOM_CurrRngDebTrh_s1' */
const volatile boolean CAL_TRSP_18VHSVoltErrRst_b = 0;
                            /* Referenced by: '<S5>/CAL_TOM_CurrRngErrRst_b1' */
const volatile uint16 CAL_TRSP_18VHSVoltHiLim_u16 = 3000U;
                            /* Referenced by: '<S5>/CAL_TOM_CurrRngHiLim_f32' */
const volatile uint16 CAL_TRSP_18VHSVoltLoLim_u16 = 2000U;
                            /* Referenced by: '<S5>/CAL_TOM_CurrRngLoLim_f32' */
const volatile sint16 CAL_TRSP_1V8CPLDVoltCountTrh_s16 = 1000;
                           /* Referenced by: '<S6>/CAL_TOM_CurrRngDebTrh_s16' */
const volatile sint16 CAL_TRSP_1V8CPLDVoltDebTrh_s16 = 500;
                            /* Referenced by: '<S6>/CAL_TOM_CurrRngDebTrh_s1' */
const volatile boolean CAL_TRSP_1V8CPLDVoltErrRst_b = 0;
                            /* Referenced by: '<S6>/CAL_TOM_CurrRngErrRst_b1' */
const volatile uint16 CAL_TRSP_1V8CPLDVoltHiLim_u16 = 2000U;
                            /* Referenced by: '<S6>/CAL_TOM_CurrRngHiLim_f32' */
const volatile uint16 CAL_TRSP_1V8CPLDVoltLoLim_u16 = 1000U;
                            /* Referenced by: '<S6>/CAL_TOM_CurrRngLoLim_f32' */
const volatile sint16 CAL_TRSP_3V3CPLDVoltCountTrh_s16 = 1000;
                           /* Referenced by: '<S7>/CAL_TOM_CurrRngDebTrh_s16' */
const volatile sint16 CAL_TRSP_3V3CPLDVoltDebTrh_s16 = 500;
                            /* Referenced by: '<S7>/CAL_TOM_CurrRngDebTrh_s1' */
const volatile boolean CAL_TRSP_3V3CPLDVoltErrRst_b = 0;
                            /* Referenced by: '<S7>/CAL_TOM_CurrRngErrRst_b1' */
const volatile uint16 CAL_TRSP_3V3CPLDVoltHiLim_u16 = 3000U;
                            /* Referenced by: '<S7>/CAL_TOM_CurrRngHiLim_f32' */
const volatile uint16 CAL_TRSP_3V3CPLDVoltLoLim_u16 = 2000U;
                            /* Referenced by: '<S7>/CAL_TOM_CurrRngLoLim_f32' */
const volatile uint8 CAL_TRSP_AgTimecompCtl_u8 = 0U;
                                  /* Referenced by: '<S8>/GLB_TOM_CircAge_f3' */
const volatile sint16 CAL_TRSP_CurrRngCountTrh_s16 = 1000;/* Referenced by:
                                                           * '<S9>/CAL_TOM_CurrRngDebAdd_s1'
                                                           * '<S9>/CAL_TOM_CurrRngDebAdd_s2'
                                                           * '<S9>/CAL_TOM_CurrRngDebAdd_s3'
                                                           */
const volatile sint16 CAL_TRSP_CurrRngDebTrh_s16 = 500;/* Referenced by:
                                                        * '<S9>/CAL_TOM_CurrRngDebTrh_s1'
                                                        * '<S9>/CAL_TOM_CurrRngDebTrh_s16'
                                                        * '<S9>/CAL_TOM_CurrRngDebTrh_s2'
                                                        */
const volatile boolean CAL_TRSP_CurrRngErrRst_b = 0;/* Referenced by:
                                                     * '<S9>/CAL_TOM_CurrRngErrRst_b'
                                                     * '<S9>/CAL_TOM_CurrRngErrRst_b1'
                                                     * '<S9>/CAL_TOM_CurrRngErrRst_b2'
                                                     */
const volatile sint16 CAL_TRSP_CurrSumCountTrh_s16 = 1000;
                            /* Referenced by: '<S9>/CAL_TOM_CurrSumDebAdd_s1' */
const volatile sint16 CAL_TRSP_CurrSumDebTrh_s16 = 500;
                           /* Referenced by: '<S9>/CAL_TOM_CurrSumDebTrh_s16' */
const volatile boolean CAL_TRSP_CurrSumErrRst_b = 0;
                             /* Referenced by: '<S9>/CAL_TOM_CurrSumErrRst_b' */
const volatile float32 CAL_TRSP_CurrSumLim_f32 = 80.0F;
                             /* Referenced by: '<S26>/CAL_TOM_CurrSumLim_f32' */
const volatile float32 CAL_TRSP_Diff_UBR_SBCLim_f32 = 3.0F;
                             /* Referenced by: '<S77>/CAL_TOM_CurrSumLim_f32' */
const volatile boolean CAL_TRSP_OfstErrRst_b = 0;
                               /* Referenced by: '<S97>/CAL_TOM_OfstErrRst_b' */
const volatile float32 CAL_TRSP_OfstRngHiLim_f32 = 360.0F;
                           /* Referenced by: '<S97>/CAL_TOM_OfstRngHiLim_f32' */
const volatile float32 CAL_TRSP_OfstRngLoLim_f32 = 0.0F;
                           /* Referenced by: '<S97>/CAL_TOM_OfstRngLoLim_f32' */
const volatile sint16 CAL_TRSP_ReqTrqCountTrh_s16 = 10;
                           /* Referenced by: '<S85>/CAL_TOM_CurrRngDebTrh_s5' */
const volatile sint16 CAL_TRSP_ReqTrqDebTrh_s16 = 5;
                           /* Referenced by: '<S85>/CAL_TOM_CurrRngDebTrh_s4' */
const volatile boolean CAL_TRSP_ReqTrqErrRst_b = 0;
                           /* Referenced by: '<S85>/CAL_TOM_CurrRngErrRst_b3' */
const volatile float32 CAL_TRSP_ReqTrqHiLim_f32 = 350.0F;
                            /* Referenced by: '<S85>/CAL_TOM_CurrRngHiLim_f2' */
const volatile float32 CAL_TRSP_ReqTrqLoLim_f32 = -350.0F;
                            /* Referenced by: '<S85>/CAL_TOM_CurrRngLoLim_f2' */
const volatile sint16 CAL_TRSP_RslvExciCountTrh_s16 = 1000;/* Referenced by:
                                                            * '<S10>/CAL_TOM_RslvExciDebTrh_s16'
                                                            * '<S10>/CAL_TOM_RslvExciDebTrh_s3'
                                                            */
const volatile sint16 CAL_TRSP_RslvExciDebTrh_s16 = 500;/* Referenced by:
                                                         * '<S10>/CAL_TOM_RslvExciDebTrh_s1'
                                                         * '<S10>/CAL_TOM_RslvExciDebTrh_s2'
                                                         */
const volatile boolean CAL_TRSP_RslvExciErrRst_b = 0;/* Referenced by:
                                                      * '<S10>/CAL_TOM_RslvExciErrRst_b'
                                                      * '<S10>/CAL_TOM_RslvExciErrRst_b1'
                                                      */
const volatile uint16 CAL_TRSP_RslvRngCosNHiLim_u16 = 700U;
                         /* Referenced by: '<S10>/CAL_TOM_RslvRngSinHiLim_f3' */
const volatile uint16 CAL_TRSP_RslvRngCosNLoLim_u16 = 300U;
                         /* Referenced by: '<S10>/CAL_TOM_RslvRngSinLoLim_f3' */
const volatile uint16 CAL_TRSP_RslvRngCosPHiLim_u16 = 700U;
                         /* Referenced by: '<S10>/CAL_TOM_RslvRngSinHiLim_f2' */
const volatile uint16 CAL_TRSP_RslvRngCosPLoLim_u16 = 300U;
                         /* Referenced by: '<S10>/CAL_TOM_RslvRngSinLoLim_f2' */
const volatile sint16 CAL_TRSP_RslvRngCountTrh_s16 = 1000;/* Referenced by:
                                                           * '<S10>/CAL_TOM_RslvRngDebTrh_s16'
                                                           * '<S10>/CAL_TOM_RslvRngDebTrh_s3'
                                                           * '<S10>/CAL_TOM_RslvRngDebTrh_s5'
                                                           * '<S10>/CAL_TOM_RslvRngDebTrh_s7'
                                                           */
const volatile sint16 CAL_TRSP_RslvRngDebTrh_s16 = 500;/* Referenced by:
                                                        * '<S10>/CAL_TOM_RslvRngDebTrh_s1'
                                                        * '<S10>/CAL_TOM_RslvRngDebTrh_s2'
                                                        * '<S10>/CAL_TOM_RslvRngDebTrh_s4'
                                                        * '<S10>/CAL_TOM_RslvRngDebTrh_s6'
                                                        */
const volatile boolean CAL_TRSP_RslvRngErrRst_b = 0;/* Referenced by:
                                                     * '<S10>/CAL_TOM_RslvRngErrRst_b'
                                                     * '<S10>/CAL_TOM_RslvRngErrRst_b1'
                                                     * '<S10>/CAL_TOM_RslvRngErrRst_b2'
                                                     * '<S10>/CAL_TOM_RslvRngErrRst_b3'
                                                     */
const volatile uint16 CAL_TRSP_RslvRngExciHiLim_u16 = 2500U;/* Referenced by:
                                                             * '<S10>/CAL_TOM_RslvRngExciHiLim_f1'
                                                             * '<S10>/CAL_TOM_RslvRngExciHiLim_f32'
                                                             */
const volatile uint16 CAL_TRSP_RslvRngExciLoLim_u16 = 800U;/* Referenced by:
                                                            * '<S10>/CAL_TOM_RslvRngExciLoLim_f1'
                                                            * '<S10>/CAL_TOM_RslvRngExciLoLim_f32'
                                                            */
const volatile uint16 CAL_TRSP_RslvRngSinNHiLim_u16 = 700U;
                         /* Referenced by: '<S10>/CAL_TOM_RslvRngSinHiLim_f1' */
const volatile uint16 CAL_TRSP_RslvRngSinNLoLim_u16 = 300U;
                         /* Referenced by: '<S10>/CAL_TOM_RslvRngSinLoLim_f1' */
const volatile uint16 CAL_TRSP_RslvRngSinPHiLim_u16 = 700U;
                        /* Referenced by: '<S10>/CAL_TOM_RslvRngSinHiLim_f32' */
const volatile uint16 CAL_TRSP_RslvRngSinPLoLim_u16 = 300U;
                        /* Referenced by: '<S10>/CAL_TOM_RslvRngSinLoLim_f32' */
const volatile sint16 CAL_TRSP_RslvSensVoltCountTrh_s16 = 1000;
                          /* Referenced by: '<S11>/CAL_TOM_CurrRngDebTrh_s16' */
const volatile sint16 CAL_TRSP_RslvSensVoltDebTrh_s16 = 500;
                           /* Referenced by: '<S11>/CAL_TOM_CurrRngDebTrh_s1' */
const volatile boolean CAL_TRSP_RslvSensVoltErrRst_b = 0;
                           /* Referenced by: '<S11>/CAL_TOM_CurrRngErrRst_b1' */
const volatile uint16 CAL_TRSP_RslvSensVoltHiLim_u16 = 2376U;
                           /* Referenced by: '<S11>/CAL_TOM_CurrRngHiLim_f32' */
const volatile uint16 CAL_TRSP_RslvSensVoltLoLim_u16 = 1720U;
                           /* Referenced by: '<S11>/CAL_TOM_CurrRngLoLim_f32' */
const volatile sint16 CAL_TRSP_RslvSqrtCountTrh_s16 = 1000;
                         /* Referenced by: '<S10>/CAL_TOM_RslvSqrtDebTrh_s16' */
const volatile sint16 CAL_TRSP_RslvSqrtDebTrh_s16 = 500;
                          /* Referenced by: '<S10>/CAL_TOM_RslvSqrtDebTrh_s1' */
const volatile boolean CAL_TRSP_RslvSqrtErrRst_b = 0;
                           /* Referenced by: '<S10>/CAL_TOM_RslvSqrtErrRst_b' */
const volatile uint16 CAL_TRSP_RslvSqrtHiLim_u16 = 6000U;
                            /* Referenced by: '<S57>/CAL_TOM_RslvSqrtLim_f32' */
const volatile uint16 CAL_TRSP_RslvSqrtLoLim_u16 = 5300U;
                             /* Referenced by: '<S57>/CAL_TOM_RslvSqrtLim_f1' */
const volatile uint8 CAL_TRSP_SpeedCtlMode_u8 = 7U;
                            /* Referenced by: '<S98>/CAL_TOM_SpeedCtlMode_u3' */
const volatile uint8 CAL_TRSP_TorqueCtlMode_u8 = 8U;
                            /* Referenced by: '<S98>/CAL_TOM_SpeedCtlMode_u2' */
const volatile sint16 CAL_TRSP_UBRVoltCountTrh_s16 = 1000;
                          /* Referenced by: '<S12>/CAL_TOM_CurrRngDebTrh_s16' */
const volatile sint16 CAL_TRSP_UBRVoltDebTrh_s16 = 500;
                           /* Referenced by: '<S12>/CAL_TOM_CurrRngDebTrh_s1' */
const volatile boolean CAL_TRSP_UBRVoltErrRst_b = 0;
                           /* Referenced by: '<S12>/CAL_TOM_CurrRngErrRst_b1' */
const volatile float32 CAL_TRSP_UBRWIDECnvFac_f32 = 0.00714F;
                               /* Referenced by: '<S78>/CAL_CSP_iUCnvFac_f32' */
const volatile float32 CAL_TRSP_UB_SBCCnvFac_f32 = 0.0069F;
                               /* Referenced by: '<S78>/CAL_MCF_iWCnvFac_f32' */
const volatile float32 CAL_TRSP_UCurrRngHiLim_f32 = -2000.0F;
                             /* Referenced by: '<S9>/CAL_TOM_CurrRngHiLim_f1' */
const volatile float32 CAL_TRSP_UCurrRngLoLim_f32 = -21000.0F;
                             /* Referenced by: '<S9>/CAL_TOM_CurrRngLoLim_f1' */
const volatile float32 CAL_TRSP_VCurrRngHiLim_f32 = 21000.0F;
                             /* Referenced by: '<S9>/CAL_TOM_CurrRngHiLim_f2' */
const volatile float32 CAL_TRSP_VCurrRngLoLim_f32 = 2000.0F;
                             /* Referenced by: '<S9>/CAL_TOM_CurrRngLoLim_f2' */
const volatile float32 CAL_TRSP_WCurrRngHiLim_f32 = 21000.0F;
                             /* Referenced by: '<S9>/CAL_TOM_CurrRngHiLim_f3' */
const volatile float32 CAL_TRSP_WCurrRngLoLim_f32 = 2000.0F;
                             /* Referenced by: '<S9>/CAL_TOM_CurrRngLoLim_f3' */
const volatile boolean CAL_TRSP_flgChangPha_b = 0;
                              /* Referenced by: '<S34>/CAL_CSP_flgChangPha_b' */
const volatile float32 CAL_TRSP_iPhaUOffset_f32 = -10600.0F;
                                /* Referenced by: '<S34>/CAL_CSP_iUCnvFac_f1' */
const volatile float32 CAL_TRSP_iPhaVOffset_f32 = 10610.0F;
                                /* Referenced by: '<S34>/CAL_CSP_iUCnvFac_f2' */
const volatile float32 CAL_TRSP_iPhaWOffset_f32 = 10780.0F;
                                /* Referenced by: '<S34>/CAL_CSP_iUCnvFac_f3' */
const volatile sint16 CAL_TRSP_iPhasSensVoltCountTrh_s16 = 1000;
                          /* Referenced by: '<S13>/CAL_TOM_CurrRngDebTrh_s16' */
const volatile sint16 CAL_TRSP_iPhasSensVoltDebTrh_s16 = 500;
                           /* Referenced by: '<S13>/CAL_TOM_CurrRngDebTrh_s1' */
const volatile boolean CAL_TRSP_iPhasSensVoltErrRst_b = 0;
                            /* Referenced by: '<S13>/CAL_TOM_CurrRngErrRst_b' */
const volatile uint16 CAL_TRSP_iPhasSensVoltHiLim_u16 = 4096U;
                            /* Referenced by: '<S13>/CAL_TOM_CurrRngHiLim_f1' */
const volatile uint16 CAL_TRSP_iPhasSensVoltLoLim_u16 = 4014U;
                           /* Referenced by: '<S13>/CAL_TOM_CurrRngLoLim_f32' */
const volatile float32 CAL_TRSP_iUCnvFac_f32 = -0.0916F;
                               /* Referenced by: '<S34>/CAL_CSP_iUCnvFac_f32' */
const volatile float32 CAL_TRSP_iVCnvFac_f32 = 0.0924F;
                               /* Referenced by: '<S34>/CAL_CSP_iVCnvFac_f32' */
const volatile float32 CAL_TRSP_iWCnvFac_f32 = 0.0916F;
                               /* Referenced by: '<S34>/CAL_MCF_iWCnvFac_f32' */

#pragma section
#pragma section ".data.CPU1_32"
/* Block signals (default storage) */
B_SWC_TRSP_T SWC_TRSP_B;

/* Block states (default storage) */
DW_SWC_TRSP_T SWC_TRSP_DW;

/* Real-time model */
RT_MODEL_SWC_TRSP_T SWC_TRSP_M_;
RT_MODEL_SWC_TRSP_T *const SWC_TRSP_M = &SWC_TRSP_M_;
#pragma section

#pragma section ".text.CPU1_Code" ax
/*
 * Output and update for enable system:
 *    '<S14>/Count'
 *    '<S18>/Count'
 *    '<S22>/Count'
 *    '<S27>/Count'
 *    '<S28>/Count'
 *    '<S29>/Count'
 *    '<S30>/Count'
 *    '<S43>/Count'
 *    '<S44>/Count'
 *    '<S45>/Count'
 *    ...
 */
void SWC_TRSP_Count(boolean rtu_Enable, sint16 rtu_CountTrh, sint16 *rty_Count,
                    DW_Count_SWC_TRSP_T *localDW)
{
  sint16 rtb_Add_h;

  /* Outputs for Enabled SubSystem: '<S14>/Count' incorporates:
   *  EnablePort: '<S17>/Enable'
   */
  if (rtu_Enable) {
    /* Sum: '<S17>/Add' incorporates:
     *  Constant: '<S17>/Constant'
     *  Delay: '<S17>/Delay'
     */
    rtb_Add_h = (sint16)(localDW->Delay_DSTATE + 1);

    /* Switch: '<S17>/Switch' incorporates:
     *  Constant: '<S17>/Constant1'
     *  RelationalOperator: '<S17>/Relational Operator'
     */
    if (rtb_Add_h >= rtu_CountTrh) {
      *rty_Count = 0;
    } else {
      *rty_Count = rtb_Add_h;
    }

    /* End of Switch: '<S17>/Switch' */

    /* Update for Delay: '<S17>/Delay' */
    localDW->Delay_DSTATE = *rty_Count;
  }

  /* End of Outputs for SubSystem: '<S14>/Count' */
}

/*
 * Output and update for atomic system:
 *    '<S5>/Debouncer11'
 *    '<S6>/Debouncer11'
 *    '<S7>/Debouncer11'
 *    '<S9>/Debouncer'
 *    '<S9>/Debouncer1'
 *    '<S9>/Debouncer2'
 *    '<S9>/Debouncer3'
 *    '<S10>/Debouncer10'
 *    '<S10>/Debouncer4'
 *    '<S10>/Debouncer5'
 *    ...
 */
boolean SWC_TRSP_Debouncer11(boolean rtu_BooleanIN, boolean rtu_Rst, sint16
  rtu_CountTrh, sint16 rtu_DebTrh, B_Debouncer11_SWC_TRSP_T *localB,
  DW_Debouncer11_SWC_TRSP_T *localDW)
{
  boolean rty_OutLock_0;
  boolean rtb_RelationalOperator_i;

  /* Switch: '<S14>/Switch1' incorporates:
   *  UnitDelay: '<S14>/Unit Delay1'
   */
  localDW->UnitDelay1_DSTATE = ((!rtu_Rst) && localDW->UnitDelay1_DSTATE);

  /* Outputs for Enabled SubSystem: '<S14>/Count' */
  /* Delay: '<S14>/Delay1' */
  SWC_TRSP_Count(localDW->Delay1_DSTATE, rtu_CountTrh, &localB->Switch,
                 &localDW->Count);

  /* End of Outputs for SubSystem: '<S14>/Count' */

  /* Switch: '<S14>/Switch2' incorporates:
   *  Constant: '<S14>/Constant'
   *  Constant: '<S16>/Constant'
   *  Delay: '<S14>/Delay2'
   *  RelationalOperator: '<S16>/Compare'
   */
  if (localB->Switch == 0) {
    localDW->Delay2_DSTATE = 0;
  }

  /* End of Switch: '<S14>/Switch2' */

  /* Sum: '<S14>/Add' incorporates:
   *  Delay: '<S14>/Delay2'
   */
  localDW->Delay2_DSTATE += rtu_BooleanIN;

  /* RelationalOperator: '<S14>/Relational Operator' */
  rtb_RelationalOperator_i = (localDW->Delay2_DSTATE >= rtu_DebTrh);

  /* Logic: '<S14>/Logical Operator' incorporates:
   *  UnitDelay: '<S14>/Unit Delay1'
   */
  rty_OutLock_0 = (rtb_RelationalOperator_i || localDW->UnitDelay1_DSTATE);

  /* Switch: '<S14>/Switch' incorporates:
   *  Constant: '<S14>/Constant1'
   *  Delay: '<S14>/Delay2'
   */
  if (rtb_RelationalOperator_i) {
    localDW->Delay2_DSTATE = 0;
  }

  /* End of Switch: '<S14>/Switch' */

  /* Logic: '<S14>/Logical Operator1' incorporates:
   *  Delay: '<S14>/Delay1'
   */
  localDW->Delay1_DSTATE = (localDW->Delay1_DSTATE || rtu_BooleanIN);

  /* Update for UnitDelay: '<S14>/Unit Delay1' */
  localDW->UnitDelay1_DSTATE = rty_OutLock_0;
  return rty_OutLock_0;
}

/*
 * Output and update for atomic system:
 *    '<S5>/RngChk'
 *    '<S6>/RngChk'
 *    '<S7>/RngChk'
 *    '<S10>/RngChk1'
 *    '<S10>/RngChk2'
 *    '<S11>/RngChk'
 *    '<S13>/RngChk'
 */
boolean SWC_TRSP_RngChk(uint16 rtu_TRSP_RngChkVal, uint16 rtu_TRSP_HiTrh, uint16
  rtu_TRSP_LoTrh)
{
  /* Logic: '<S15>/Logical Operator' incorporates:
   *  RelationalOperator: '<S15>/Relational Operator'
   *  RelationalOperator: '<S15>/Relational Operator1'
   */
  return (rtu_TRSP_RngChkVal >= rtu_TRSP_HiTrh) || (rtu_TRSP_RngChkVal <=
    rtu_TRSP_LoTrh);
}

/* Output and update for atomic system: '<S1>/AgRtrCalc' */
void SWC_TRSP_AgRtrCalc(void)
{
  /* Sum: '<S8>/Add' incorporates:
   *  Inport: '<Root>/NvM_AngAutoClbOffset'
   *  Inport: '<Root>/SWD_AgRslv'
   */
  VAR_TRSP_AgRtr_f32 = get_SWD_AgRslv() + get_NvM_AngAutoClbOffset();

  /* Switch: '<S8>/Switch2' incorporates:
   *  Constant: '<S8>/GLB_TOM_CircAge_f3'
   */
  if (CAL_TRSP_AgTimecompCtl_u8 != 0) {
    /* Switch: '<S8>/Switch3' incorporates:
     *  Constant: '<S8>/GLB_TRSP_CircAge_f32'
     *  Constant: '<S8>/GLB_TRSP_MotorPole_u8'
     *  Constant: '<S8>/GLB_TRSP_Sixty_f32'
     *  Constant: '<S8>/const'
     *  Inport: '<Root>/CDD_TimecompAg'
     *  Inport: '<Root>/SWD_Spd'
     *  Product: '<S8>/Divide2'
     *  Product: '<S8>/Divide3'
     *  Sum: '<S8>/Add1'
     *  Sum: '<S8>/Add4'
     */
    if (CAL_TRSP_AgTimecompCtl_u8 >= 2) {
      VAR_TRSP_AgRtr_f32 += get_SWD_Spd() * get_CDD_TimecompAg() * (float32)
        ((uint8)GLB_TRSP_MotorPole_u8) * GLB_TRSP_CircAge_f32 /
        GLB_TRSP_Sixty_f32 * 1.0E-8F;
    } else {
      VAR_TRSP_AgRtr_f32 -= get_SWD_Spd() * get_CDD_TimecompAg() * (float32)
        ((uint8)GLB_TRSP_MotorPole_u8) * GLB_TRSP_CircAge_f32 /
        GLB_TRSP_Sixty_f32 * 1.0E-8F;
    }

    /* End of Switch: '<S8>/Switch3' */
  }

  /* End of Switch: '<S8>/Switch2' */

  /* Switch: '<S8>/Switch' incorporates:
   *  Constant: '<S8>/Constant1'
   *  Constant: '<S8>/GLB_TOM_CircAge_f1'
   *  RelationalOperator: '<S8>/Relational Operator'
   *  RelationalOperator: '<S8>/Relational Operator1'
   *  Sum: '<S8>/Add2'
   *  Switch: '<S8>/Switch1'
   */
  if (GLB_TRSP_CircAge_f32 <= VAR_TRSP_AgRtr_f32) {
    VAR_TRSP_AgRtr_f32 -= GLB_TRSP_CircAge_f32;
  } else {
    if (VAR_TRSP_AgRtr_f32 <= 0.0F) {
      /* Switch: '<S8>/Switch1' incorporates:
       *  Constant: '<S8>/GLB_TOM_CircAge_f2'
       *  Sum: '<S8>/Add3'
       */
      VAR_TRSP_AgRtr_f32 += GLB_TRSP_CircAge_f32;
    }
  }

  /* End of Switch: '<S8>/Switch' */
}

/* Output and update for atomic system: '<S9>/CurrSumChk' */
void SWC_TRSP_CurrSumChk(void)
{
  /* Sum: '<S26>/Add' */
  VAR_TRSP_iSum_f32 = (VAR_TRSP_iU_f32 + VAR_TRSP_iV_f32) + VAR_TRSP_iW_f32;

  /* RelationalOperator: '<S26>/Relational Operator' incorporates:
   *  Abs: '<S26>/Abs'
   *  Constant: '<S26>/CAL_TOM_CurrSumLim_f32'
   */
  VAR_TRSP_CurrSumChkRslt_b = (fabsf(VAR_TRSP_iSum_f32) >=
    CAL_TRSP_CurrSumLim_f32);
}

/*
 * Output and update for atomic system:
 *    '<S9>/RngChk'
 *    '<S9>/RngChk1'
 *    '<S9>/RngChk2'
 *    '<S85>/RngChk2'
 */
boolean SWC_TRSP_RngChk_k(float32 rtu_TRSP_RngChkVal, float32 rtu_TRSP_HiTrh,
  float32 rtu_TRSP_LoTrh)
{
  /* Logic: '<S31>/Logical Operator' incorporates:
   *  RelationalOperator: '<S31>/Relational Operator'
   *  RelationalOperator: '<S31>/Relational Operator1'
   */
  return (rtu_TRSP_RngChkVal >= rtu_TRSP_HiTrh) || (rtu_TRSP_RngChkVal <=
    rtu_TRSP_LoTrh);
}

/* Output and update for atomic system: '<S9>/iPhaCalc' */
void SWC_TRSP_iPhaCalc(void)
{
  /* Switch: '<S34>/Switch5' incorporates:
   *  Constant: '<S34>/CAL_CSP_flgChangPha_b'
   *  Constant: '<S34>/CAL_CSP_iUCnvFac_f1'
   *  Constant: '<S34>/CAL_CSP_iUCnvFac_f3'
   *  Constant: '<S34>/CAL_CSP_iUCnvFac_f32'
   *  Constant: '<S34>/CAL_MCF_iWCnvFac_f32'
   *  Product: '<S34>/Product'
   *  Product: '<S34>/Product2'
   *  Sum: '<S34>/Subtract'
   *  Sum: '<S34>/Subtract2'
   *  Switch: '<S34>/Switch6'
   */
  if (CAL_TRSP_flgChangPha_b) {
    VAR_TRSP_iU_f32 = (VAR_L2Sampling_IsW_Mon_f32 - CAL_TRSP_iPhaWOffset_f32) *
      CAL_TRSP_iWCnvFac_f32;
    VAR_TRSP_iW_f32 = (VAR_L2Sampling_IsU_Mon_f32 - CAL_TRSP_iPhaUOffset_f32) *
      CAL_TRSP_iUCnvFac_f32;
  } else {
    VAR_TRSP_iU_f32 = (VAR_L2Sampling_IsU_Mon_f32 - CAL_TRSP_iPhaUOffset_f32) *
      CAL_TRSP_iUCnvFac_f32;
    VAR_TRSP_iW_f32 = (VAR_L2Sampling_IsW_Mon_f32 - CAL_TRSP_iPhaWOffset_f32) *
      CAL_TRSP_iWCnvFac_f32;
  }

  /* End of Switch: '<S34>/Switch5' */

  /* Product: '<S34>/Product1' incorporates:
   *  Constant: '<S34>/CAL_CSP_iUCnvFac_f2'
   *  Constant: '<S34>/CAL_CSP_iVCnvFac_f32'
   *  Sum: '<S34>/Subtract1'
   */
  VAR_TRSP_iV_f32 = (VAR_L2Sampling_IsV_Mon_f32 - CAL_TRSP_iPhaVOffset_f32) *
    CAL_TRSP_iVCnvFac_f32;
}

/*
 * Output and update for atomic system:
 *    '<S10>/RslvRngChk'
 *    '<S10>/RslvRngChk1'
 *    '<S10>/RslvRngChk2'
 *    '<S10>/RslvRngChk3'
 */
void SWC_TRSP_RslvRngChk(const uint16 rtu_L2Sampling_Rslv_VADC[32], uint16
  rtu_TRSP_HiTrh, uint16 rtu_TRSP_LoTrh, boolean *rty_TRSP_RslvRngChkRslt,
  uint16 *rty_L2Sampling_Rslv_VADC_Max, uint16 *rty_L2Sampling_Rslv_VADC_Min)
{
  uint16 maxV;
  sint32 sigIdx;
  uint16 minV;
  uint16 u1_tmp;

  /* MinMax: '<S52>/Max' */
  maxV = rtu_L2Sampling_Rslv_VADC[0];

  /* MinMax: '<S52>/Min' */
  minV = rtu_L2Sampling_Rslv_VADC[0];
  for (sigIdx = 0; sigIdx < 31; sigIdx++) {
    /* MinMax: '<S52>/Max' incorporates:
     *  MinMax: '<S52>/Min'
     */
    u1_tmp = rtu_L2Sampling_Rslv_VADC[sigIdx + 1];
    if (maxV <= u1_tmp) {
      maxV = u1_tmp;
    }

    /* MinMax: '<S52>/Min' */
    if (minV >= u1_tmp) {
      minV = u1_tmp;
    }
  }

  /* MinMax: '<S52>/Max' */
  *rty_L2Sampling_Rslv_VADC_Max = maxV;

  /* MinMax: '<S52>/Min' */
  *rty_L2Sampling_Rslv_VADC_Min = minV;

  /* Logic: '<S52>/Logical Operator' incorporates:
   *  RelationalOperator: '<S52>/Relational Operator'
   *  RelationalOperator: '<S52>/Relational Operator1'
   */
  *rty_TRSP_RslvRngChkRslt = ((*rty_L2Sampling_Rslv_VADC_Max >= rtu_TRSP_HiTrh) ||
    (*rty_L2Sampling_Rslv_VADC_Min <= rtu_TRSP_LoTrh));
}

/* Output and update for atomic system: '<S10>/RslvSigCalc' */
void SWC_TRSP_RslvSigCalc(void)
{
  sint32 tmp;
  sint32 tmp_0;
  sint32 i;
  uint16 *rtb_DataTypeConversion3_0;
  uint16 *rtb_DataTypeConversion2_0;

  /* DataTypeConversion: '<S56>/Data Type Conversion5' */
  rtb_DataTypeConversion3_0 = &VAR_L2Sampling_RslvSinP_VADC_u16[0];

  /* DataTypeConversion: '<S56>/Data Type Conversion6' */
  rtb_DataTypeConversion2_0 = &VAR_L2Sampling_RslvSinN_VADC_u16[0];

  /* Sum: '<S56>/Sum of Elements3' */
  tmp = 0;

  /* Sum: '<S56>/Sum of Elements1' */
  tmp_0 = 0;
  for (i = 0; i < 16; i++) {
    /* Sum: '<S56>/Sum of Elements3' incorporates:
     *  Constant: '<S56>/Constant1'
     *  Constant: '<S56>/Constant7'
     *  Selector: '<S56>/Selector12'
     *  Selector: '<S56>/Selector7'
     */
    tmp = (tmp + rtb_DataTypeConversion2_0[(sint32)rtCP_Constant1_Value_p[i]]) -
      rtb_DataTypeConversion3_0[(sint32)rtCP_Constant7_Value[i]];

    /* Sum: '<S56>/Sum of Elements1' incorporates:
     *  Constant: '<S56>/Constant2'
     *  Constant: '<S56>/Constant5'
     *  Selector: '<S56>/Selector5'
     *  Selector: '<S56>/Selector6'
     */
    tmp_0 = (tmp_0 + rtb_DataTypeConversion3_0[(sint32)rtCP_Constant5_Value[i]])
      - rtb_DataTypeConversion2_0[(sint32)rtCP_Constant2_Value[i]];
  }

  /* DataTypeConversion: '<S56>/Data Type Conversion4' incorporates:
   *  Sum: '<S56>/Add8'
   *  Sum: '<S56>/Sum of Elements1'
   *  Sum: '<S56>/Sum of Elements3'
   */
  VAR_TRSP_RslvSin_f32 = (float32)(tmp_0 + tmp);

  /* DataTypeConversion: '<S56>/Data Type Conversion2' */
  rtb_DataTypeConversion2_0 = &VAR_L2Sampling_RslvCosP_VADC_u16[0];

  /* DataTypeConversion: '<S56>/Data Type Conversion3' */
  rtb_DataTypeConversion3_0 = &VAR_L2Sampling_RslvCosN_VADC_u16[0];

  /* Sum: '<S56>/Sum of Elements4' */
  tmp = 0;

  /* Sum: '<S56>/Sum of Elements2' */
  tmp_0 = 0;
  for (i = 0; i < 16; i++) {
    /* Sum: '<S56>/Sum of Elements4' incorporates:
     *  Constant: '<S56>/Constant4'
     *  Constant: '<S56>/Constant8'
     *  Selector: '<S56>/Selector1'
     *  Selector: '<S56>/Selector4'
     */
    tmp = (tmp + rtb_DataTypeConversion3_0[(sint32)rtCP_Constant8_Value[i]]) -
      rtb_DataTypeConversion2_0[(sint32)rtCP_Constant4_Value[i]];

    /* Sum: '<S56>/Sum of Elements2' incorporates:
     *  Constant: '<S56>/Constant3'
     *  Constant: '<S56>/Constant6'
     *  Selector: '<S56>/Selector2'
     *  Selector: '<S56>/Selector3'
     */
    tmp_0 = (tmp_0 + rtb_DataTypeConversion2_0[(sint32)rtCP_Constant3_Value[i]])
      - rtb_DataTypeConversion3_0[(sint32)rtCP_Constant6_Value[i]];
  }

  /* DataTypeConversion: '<S56>/Data Type Conversion1' incorporates:
   *  Sum: '<S56>/Add5'
   *  Sum: '<S56>/Sum of Elements2'
   *  Sum: '<S56>/Sum of Elements4'
   */
  VAR_TRSP_RslvCos_f32 = (float32)(tmp_0 + tmp);
}

/* Output and update for atomic system: '<S10>/RslvSqrtChk' */
void SWC_TRSP_RslvSqrtChk(void)
{
  /* Sqrt: '<S57>/Sqrt' incorporates:
   *  Product: '<S57>/Product'
   *  Product: '<S57>/Product1'
   *  Sum: '<S57>/Add'
   */
  VAR_TRSP_RslvSqrt_f32 = sqrtf(VAR_TRSP_RslvSin_f32 * VAR_TRSP_RslvSin_f32 +
    VAR_TRSP_RslvCos_f32 * VAR_TRSP_RslvCos_f32);

  /* Logic: '<S57>/Logical Operator' incorporates:
   *  Constant: '<S57>/CAL_TOM_RslvSqrtLim_f1'
   *  Constant: '<S57>/CAL_TOM_RslvSqrtLim_f32'
   *  RelationalOperator: '<S57>/Relational Operator'
   *  RelationalOperator: '<S57>/Relational Operator1'
   */
  VAR_TRSP_RslvSqrtChkRslt_b = ((VAR_TRSP_RslvSqrt_f32 >=
    CAL_TRSP_RslvSqrtHiLim_u16) || (VAR_TRSP_RslvSqrt_f32 <=
    CAL_TRSP_RslvSqrtLoLim_u16));
}

/* Output and update for atomic system: '<S12>/UBRVoltCompChk' */
void SWC_TRSP_UBRVoltCompChk(void)
{
  /* Sum: '<S77>/Add' */
  VAR_TRSP_Diff_UBR_SBC_f32 = VAR_TRSP_UBRWIDE_f32 - VAR_TRSP_UB_SBC_f32;

  /* RelationalOperator: '<S77>/Relational Operator' incorporates:
   *  Abs: '<S77>/Abs'
   *  Constant: '<S77>/CAL_TOM_CurrSumLim_f32'
   */
  VAR_TRSP_UBRVoltRngChkRslt_b = (fabsf(VAR_TRSP_Diff_UBR_SBC_f32) >=
    CAL_TRSP_Diff_UBR_SBCLim_f32);
}

/* Output and update for atomic system: '<S12>/UBR_SBCVoltCalc' */
void SWC_TRSP_UBR_SBCVoltCalc(void)
{
  /* Product: '<S78>/Product' incorporates:
   *  Constant: '<S78>/CAL_CSP_iUCnvFac_f32'
   */
  VAR_TRSP_UBRWIDE_f32 = (float32)VAR_L2Sampling_UBRWIDE_MON_u16 *
    CAL_TRSP_UBRWIDECnvFac_f32;

  /* Product: '<S78>/Product2' incorporates:
   *  Constant: '<S78>/CAL_MCF_iWCnvFac_f32'
   */
  VAR_TRSP_UB_SBC_f32 = (float32)VAR_L2Sampling_UB_SBC_MON_u16 *
    CAL_TRSP_UB_SBCCnvFac_f32;
}

/*
 * Output and update for atomic system:
 *    '<S2>/Debouncer'
 *    '<S3>/Debouncer'
 */
void SWC_TRSP_Debouncer(boolean rtu_BooleanIN, boolean rtu_Rst, sint16
  rtu_CountTrh, sint16 rtu_DebTrh, boolean *rty_OutLock, sint16 *rty_Count,
  sint16 *rty_Deb, DW_Debouncer_SWC_TRSP_T *localDW)
{
  boolean rtb_RelationalOperator_m;

  /* Switch: '<S86>/Switch1' incorporates:
   *  UnitDelay: '<S86>/Unit Delay1'
   */
  localDW->UnitDelay1_DSTATE = ((!rtu_Rst) && localDW->UnitDelay1_DSTATE);

  /* Outputs for Enabled SubSystem: '<S86>/Subsystem' */
  /* Delay: '<S86>/Delay1' */
  SWC_TRSP_Count(localDW->Delay1_DSTATE, rtu_CountTrh, rty_Count,
                 &localDW->Subsystem);

  /* End of Outputs for SubSystem: '<S86>/Subsystem' */

  /* Switch: '<S86>/Switch2' incorporates:
   *  Constant: '<S86>/Constant'
   *  Constant: '<S91>/Constant'
   *  Delay: '<S86>/Delay2'
   *  RelationalOperator: '<S91>/Compare'
   */
  if (*rty_Count == 0) {
    localDW->Delay2_DSTATE = 0;
  }

  /* End of Switch: '<S86>/Switch2' */

  /* Sum: '<S86>/Add' incorporates:
   *  Delay: '<S86>/Delay2'
   */
  *rty_Deb = (sint16)(rtu_BooleanIN + localDW->Delay2_DSTATE);

  /* RelationalOperator: '<S86>/Relational Operator' */
  rtb_RelationalOperator_m = (*rty_Deb >= rtu_DebTrh);

  /* Logic: '<S86>/Logical Operator' incorporates:
   *  UnitDelay: '<S86>/Unit Delay1'
   */
  *rty_OutLock = (rtb_RelationalOperator_m || localDW->UnitDelay1_DSTATE);

  /* Switch: '<S86>/Switch' incorporates:
   *  Constant: '<S86>/Constant1'
   *  Delay: '<S86>/Delay2'
   */
  if (rtb_RelationalOperator_m) {
    localDW->Delay2_DSTATE = 0;
  } else {
    localDW->Delay2_DSTATE = *rty_Deb;
  }

  /* End of Switch: '<S86>/Switch' */

  /* Logic: '<S86>/Logical Operator1' incorporates:
   *  Delay: '<S86>/Delay1'
   */
  localDW->Delay1_DSTATE = (localDW->Delay1_DSTATE || rtu_BooleanIN);

  /* Update for UnitDelay: '<S86>/Unit Delay1' */
  localDW->UnitDelay1_DSTATE = *rty_OutLock;
}

/* Output and update for atomic system: '<S97>/Lock' */
void SWC_TRSP_Lock(void)
{
  /* Switch: '<S99>/Switch1' incorporates:
   *  Constant: '<S97>/CAL_TOM_OfstErrRst_b'
   */
  VAR_TRSP_OfstRngErr_b = ((!CAL_TRSP_OfstErrRst_b) && VAR_TRSP_OfstRngErr_b);

  /* Logic: '<S99>/Logical Operator' */
  VAR_TRSP_OfstRngErr_b = (VAR_TRSP_OfstRngChkRslt_b || VAR_TRSP_OfstRngErr_b);
}

/* Output and update for atomic system: '<S97>/OfstRngChk' */
boolean SWC_TRSP_OfstRngChk(float32 rtu_TRSP_OfstRngChkVal, float32
  rtu_TRSP_HiTrh, float32 rtu_TRSP_LoTrh)
{
  /* Logic: '<S100>/Logical Operator' incorporates:
   *  RelationalOperator: '<S100>/Relational Operator'
   *  RelationalOperator: '<S100>/Relational Operator1'
   */
  return (rtu_TRSP_OfstRngChkVal > rtu_TRSP_HiTrh) || (rtu_TRSP_OfstRngChkVal <
    rtu_TRSP_LoTrh);
}

/* Model step function for TID1 */
void SWC_TRSP_100us(void)              /* Explicit Task: SWC_TRSP_100us */
{
  sint32 i;

  /* RootInportFunctionCallGenerator generated from: '<Root>/SWC_TRSP_100us' incorporates:
   *  SubSystem: '<Root>/SWC_TRSP_100us_sys'
   */
  for (i = 0; i < 32; i++) {
    /* SignalConversion: '<S1>/Signal Conversion15' incorporates:
     *  Inport: '<Root>/L2Sampling_RslvSinP_VADC'
     */
    VAR_L2Sampling_RslvSinP_VADC_u16[i] = get_L2Sampling_RslvSinP_VADC(i);

    /* SignalConversion: '<S1>/Signal Conversion16' incorporates:
     *  Inport: '<Root>/L2Sampling_RslvSinN_VADC'
     */
    VAR_L2Sampling_RslvSinN_VADC_u16[i] = get_L2Sampling_RslvSinN_VADC(i);

    /* SignalConversion: '<S1>/Signal Conversion17' incorporates:
     *  Inport: '<Root>/L2Sampling_RslvCosP_VADC'
     */
    VAR_L2Sampling_RslvCosP_VADC_u16[i] = get_L2Sampling_RslvCosP_VADC(i);

    /* SignalConversion: '<S1>/Signal Conversion18' incorporates:
     *  Inport: '<Root>/L2Sampling_RslvCosN_VADC'
     */
    VAR_L2Sampling_RslvCosN_VADC_u16[i] = get_L2Sampling_RslvCosN_VADC(i);
  }

  /* Outputs for Atomic SubSystem: '<S10>/RslvRngChk3' */
  /* SignalConversion generated from: '<S10>/RslvRngChk3' incorporates:
   *  Constant: '<S10>/CAL_TOM_RslvRngSinHiLim_f3'
   *  Constant: '<S10>/CAL_TOM_RslvRngSinLoLim_f3'
   */
  SWC_TRSP_RslvRngChk(VAR_L2Sampling_RslvCosN_VADC_u16,
                      CAL_TRSP_RslvRngCosNHiLim_u16,
                      CAL_TRSP_RslvRngCosNLoLim_u16,
                      &VAR_TRSP_RslvCosNRngChkRslt_b,
                      &VAR_L2Sampling_RslvCosN_VADC_Max1_u16,
                      &VAR_L2Sampling_RslvCosN_VADC_Min1_u16);

  /* End of Outputs for SubSystem: '<S10>/RslvRngChk3' */

  /* Outputs for Atomic SubSystem: '<S10>/Debouncer7' */
  /* SignalConversion generated from: '<S10>/Debouncer7' incorporates:
   *  Constant: '<S10>/CAL_TOM_RslvRngDebTrh_s6'
   *  Constant: '<S10>/CAL_TOM_RslvRngDebTrh_s7'
   *  Constant: '<S10>/CAL_TOM_RslvRngErrRst_b3'
   */
  VAR_TRSP_RslvCosNRngErr_b = SWC_TRSP_Debouncer11(VAR_TRSP_RslvCosNRngChkRslt_b,
    CAL_TRSP_RslvRngErrRst_b, CAL_TRSP_RslvRngCountTrh_s16,
    CAL_TRSP_RslvRngDebTrh_s16, &SWC_TRSP_B.Debouncer7, &SWC_TRSP_DW.Debouncer7);

  /* End of Outputs for SubSystem: '<S10>/Debouncer7' */

  /* Outputs for Atomic SubSystem: '<S10>/RslvRngChk' */
  /* SignalConversion generated from: '<S10>/RslvRngChk' incorporates:
   *  Constant: '<S10>/CAL_TOM_RslvRngSinHiLim_f32'
   *  Constant: '<S10>/CAL_TOM_RslvRngSinLoLim_f32'
   */
  SWC_TRSP_RslvRngChk(VAR_L2Sampling_RslvSinP_VADC_u16,
                      CAL_TRSP_RslvRngSinPHiLim_u16,
                      CAL_TRSP_RslvRngSinPLoLim_u16,
                      &VAR_TRSP_RslvSinPRngChkRslt_b,
                      &VAR_L2Sampling_RslvSinP_VADC_Max1_u16,
                      &VAR_L2Sampling_RslvSinP_VADC_Min1_u16);

  /* End of Outputs for SubSystem: '<S10>/RslvRngChk' */

  /* Outputs for Atomic SubSystem: '<S10>/Debouncer4' */
  /* SignalConversion generated from: '<S10>/Debouncer4' incorporates:
   *  Constant: '<S10>/CAL_TOM_RslvRngDebTrh_s1'
   *  Constant: '<S10>/CAL_TOM_RslvRngDebTrh_s16'
   *  Constant: '<S10>/CAL_TOM_RslvRngErrRst_b'
   */
  VAR_TRSP_RslvSinPRngErr_b = SWC_TRSP_Debouncer11(VAR_TRSP_RslvSinPRngChkRslt_b,
    CAL_TRSP_RslvRngErrRst_b, CAL_TRSP_RslvRngCountTrh_s16,
    CAL_TRSP_RslvRngDebTrh_s16, &SWC_TRSP_B.Debouncer4, &SWC_TRSP_DW.Debouncer4);

  /* End of Outputs for SubSystem: '<S10>/Debouncer4' */

  /* Outputs for Atomic SubSystem: '<S10>/RslvRngChk1' */
  /* SignalConversion generated from: '<S10>/RslvRngChk1' incorporates:
   *  Constant: '<S10>/CAL_TOM_RslvRngSinHiLim_f1'
   *  Constant: '<S10>/CAL_TOM_RslvRngSinLoLim_f1'
   */
  SWC_TRSP_RslvRngChk(VAR_L2Sampling_RslvSinN_VADC_u16,
                      CAL_TRSP_RslvRngSinNHiLim_u16,
                      CAL_TRSP_RslvRngSinNLoLim_u16,
                      &VAR_TRSP_RslvSinNRngChkRslt_b,
                      &VAR_L2Sampling_RslvSinN_VADC_Max1_u16,
                      &VAR_L2Sampling_RslvSinN_VADC_Min1_u16);

  /* End of Outputs for SubSystem: '<S10>/RslvRngChk1' */

  /* Outputs for Atomic SubSystem: '<S10>/Debouncer5' */
  /* SignalConversion generated from: '<S10>/Debouncer5' incorporates:
   *  Constant: '<S10>/CAL_TOM_RslvRngDebTrh_s4'
   *  Constant: '<S10>/CAL_TOM_RslvRngDebTrh_s5'
   *  Constant: '<S10>/CAL_TOM_RslvRngErrRst_b2'
   */
  VAR_TRSP_RslvSinNRngErr_b = SWC_TRSP_Debouncer11(VAR_TRSP_RslvSinNRngChkRslt_b,
    CAL_TRSP_RslvRngErrRst_b, CAL_TRSP_RslvRngCountTrh_s16,
    CAL_TRSP_RslvRngDebTrh_s16, &SWC_TRSP_B.Debouncer5, &SWC_TRSP_DW.Debouncer5);

  /* End of Outputs for SubSystem: '<S10>/Debouncer5' */

  /* Outputs for Atomic SubSystem: '<S10>/RslvRngChk2' */
  /* SignalConversion generated from: '<S10>/RslvRngChk2' incorporates:
   *  Constant: '<S10>/CAL_TOM_RslvRngSinHiLim_f2'
   *  Constant: '<S10>/CAL_TOM_RslvRngSinLoLim_f2'
   */
  SWC_TRSP_RslvRngChk(VAR_L2Sampling_RslvCosP_VADC_u16,
                      CAL_TRSP_RslvRngCosPHiLim_u16,
                      CAL_TRSP_RslvRngCosPLoLim_u16,
                      &VAR_TRSP_RslvCosPRngChkRslt_b,
                      &VAR_L2Sampling_RslvCosP_VADC_Max1_u16,
                      &VAR_L2Sampling_RslvCosP_VADC_Min1_u16);

  /* End of Outputs for SubSystem: '<S10>/RslvRngChk2' */

  /* Outputs for Atomic SubSystem: '<S10>/Debouncer6' */
  /* SignalConversion generated from: '<S10>/Debouncer6' incorporates:
   *  Constant: '<S10>/CAL_TOM_RslvRngDebTrh_s2'
   *  Constant: '<S10>/CAL_TOM_RslvRngDebTrh_s3'
   *  Constant: '<S10>/CAL_TOM_RslvRngErrRst_b1'
   */
  VAR_TRSP_RslvCosPRngErr_b = SWC_TRSP_Debouncer11(VAR_TRSP_RslvCosPRngChkRslt_b,
    CAL_TRSP_RslvRngErrRst_b, CAL_TRSP_RslvRngCountTrh_s16,
    CAL_TRSP_RslvRngDebTrh_s16, &SWC_TRSP_B.Debouncer6, &SWC_TRSP_DW.Debouncer6);

  /* End of Outputs for SubSystem: '<S10>/Debouncer6' */

  /* Logic: '<S10>/Logical Operator' */
  VAR_TRSP_RslvRngErr_b = (VAR_TRSP_RslvSinPRngErr_b ||
    VAR_TRSP_RslvSinNRngErr_b || VAR_TRSP_RslvCosPRngErr_b ||
    VAR_TRSP_RslvCosNRngErr_b);

  /* SignalConversion: '<S1>/Signal Conversion6' */
  set_TRSP_RslvRngErr(VAR_TRSP_RslvRngErr_b);

  /* Outputs for Atomic SubSystem: '<S10>/RslvSigCalc' */
  SWC_TRSP_RslvSigCalc();

  /* End of Outputs for SubSystem: '<S10>/RslvSigCalc' */

  /* Outputs for Atomic SubSystem: '<S10>/RslvSqrtChk' */
  SWC_TRSP_RslvSqrtChk();

  /* End of Outputs for SubSystem: '<S10>/RslvSqrtChk' */

  /* Outputs for Atomic SubSystem: '<S10>/Debouncer8' */
  /* SignalConversion generated from: '<S10>/Debouncer8' incorporates:
   *  Constant: '<S10>/CAL_TOM_RslvSqrtDebTrh_s1'
   *  Constant: '<S10>/CAL_TOM_RslvSqrtDebTrh_s16'
   *  Constant: '<S10>/CAL_TOM_RslvSqrtErrRst_b'
   */
  VAR_TRSP_RslvSqrtErr_b = SWC_TRSP_Debouncer11(VAR_TRSP_RslvSqrtChkRslt_b,
    CAL_TRSP_RslvSqrtErrRst_b, CAL_TRSP_RslvSqrtCountTrh_s16,
    CAL_TRSP_RslvSqrtDebTrh_s16, &SWC_TRSP_B.Debouncer8, &SWC_TRSP_DW.Debouncer8);

  /* End of Outputs for SubSystem: '<S10>/Debouncer8' */

  /* SignalConversion: '<S1>/Signal Conversion7' */
  set_TRSP_RslvSqrtErr(VAR_TRSP_RslvSqrtErr_b);

  /* SignalConversion: '<S1>/Signal Conversion10' */
  set_TRSP_RslvSin(VAR_TRSP_RslvSin_f32);

  /* SignalConversion: '<S1>/Signal Conversion11' */
  set_TRSP_RslvCos(VAR_TRSP_RslvCos_f32);

  /* SignalConversion: '<S1>/Signal Conversion12' incorporates:
   *  Inport: '<Root>/L2Sampling_IsU_Mon'
   */
  VAR_L2Sampling_IsU_Mon_f32 = get_L2Sampling_IsU_Mon();

  /* Outputs for Atomic SubSystem: '<S9>/RngChk' */
  /* SignalConversion generated from: '<S9>/RngChk' incorporates:
   *  Constant: '<S9>/CAL_TOM_CurrRngHiLim_f1'
   *  Constant: '<S9>/CAL_TOM_CurrRngLoLim_f1'
   */
  VAR_TRSP_UCurrRngChkRslt_b = SWC_TRSP_RngChk_k(VAR_L2Sampling_IsU_Mon_f32,
    CAL_TRSP_UCurrRngHiLim_f32, CAL_TRSP_UCurrRngLoLim_f32);

  /* End of Outputs for SubSystem: '<S9>/RngChk' */

  /* Outputs for Atomic SubSystem: '<S9>/Debouncer' */
  /* SignalConversion generated from: '<S9>/Debouncer' incorporates:
   *  Constant: '<S9>/CAL_TOM_CurrRngDebAdd_s1'
   *  Constant: '<S9>/CAL_TOM_CurrRngDebTrh_s16'
   *  Constant: '<S9>/CAL_TOM_CurrRngErrRst_b'
   */
  VAR_TRSP_UCurrRngErr_b = SWC_TRSP_Debouncer11(VAR_TRSP_UCurrRngChkRslt_b,
    CAL_TRSP_CurrRngErrRst_b, CAL_TRSP_CurrRngCountTrh_s16,
    CAL_TRSP_CurrRngDebTrh_s16, &SWC_TRSP_B.Debouncer, &SWC_TRSP_DW.Debouncer);

  /* End of Outputs for SubSystem: '<S9>/Debouncer' */

  /* SignalConversion: '<S1>/Signal Conversion13' incorporates:
   *  Inport: '<Root>/L2Sampling_IsV_Mon'
   */
  VAR_L2Sampling_IsV_Mon_f32 = get_L2Sampling_IsV_Mon();

  /* Outputs for Atomic SubSystem: '<S9>/RngChk1' */
  /* SignalConversion generated from: '<S9>/RngChk1' incorporates:
   *  Constant: '<S9>/CAL_TOM_CurrRngHiLim_f2'
   *  Constant: '<S9>/CAL_TOM_CurrRngLoLim_f2'
   */
  VAR_TRSP_VCurrRngChkRslt_b = SWC_TRSP_RngChk_k(VAR_L2Sampling_IsV_Mon_f32,
    CAL_TRSP_VCurrRngHiLim_f32, CAL_TRSP_VCurrRngLoLim_f32);

  /* End of Outputs for SubSystem: '<S9>/RngChk1' */

  /* Outputs for Atomic SubSystem: '<S9>/Debouncer1' */
  /* SignalConversion generated from: '<S9>/Debouncer1' incorporates:
   *  Constant: '<S9>/CAL_TOM_CurrRngDebAdd_s2'
   *  Constant: '<S9>/CAL_TOM_CurrRngDebTrh_s1'
   *  Constant: '<S9>/CAL_TOM_CurrRngErrRst_b1'
   */
  VAR_TRSP_VCurrRngErr_b = SWC_TRSP_Debouncer11(VAR_TRSP_VCurrRngChkRslt_b,
    CAL_TRSP_CurrRngErrRst_b, CAL_TRSP_CurrRngCountTrh_s16,
    CAL_TRSP_CurrRngDebTrh_s16, &SWC_TRSP_B.Debouncer1, &SWC_TRSP_DW.Debouncer1);

  /* End of Outputs for SubSystem: '<S9>/Debouncer1' */

  /* SignalConversion: '<S1>/Signal Conversion14' incorporates:
   *  Inport: '<Root>/L2Sampling_IsW_Mon'
   */
  VAR_L2Sampling_IsW_Mon_f32 = get_L2Sampling_IsW_Mon();

  /* Outputs for Atomic SubSystem: '<S9>/RngChk2' */
  /* SignalConversion generated from: '<S9>/RngChk2' incorporates:
   *  Constant: '<S9>/CAL_TOM_CurrRngHiLim_f3'
   *  Constant: '<S9>/CAL_TOM_CurrRngLoLim_f3'
   */
  VAR_TRSP_WCurrRngChkRslt_b = SWC_TRSP_RngChk_k(VAR_L2Sampling_IsW_Mon_f32,
    CAL_TRSP_WCurrRngHiLim_f32, CAL_TRSP_WCurrRngLoLim_f32);

  /* End of Outputs for SubSystem: '<S9>/RngChk2' */

  /* Outputs for Atomic SubSystem: '<S9>/Debouncer2' */
  /* SignalConversion generated from: '<S9>/Debouncer2' incorporates:
   *  Constant: '<S9>/CAL_TOM_CurrRngDebAdd_s3'
   *  Constant: '<S9>/CAL_TOM_CurrRngDebTrh_s2'
   *  Constant: '<S9>/CAL_TOM_CurrRngErrRst_b2'
   */
  VAR_TRSP_WCurrRngErr_b = SWC_TRSP_Debouncer11(VAR_TRSP_WCurrRngChkRslt_b,
    CAL_TRSP_CurrRngErrRst_b, CAL_TRSP_CurrRngCountTrh_s16,
    CAL_TRSP_CurrRngDebTrh_s16, &SWC_TRSP_B.Debouncer2, &SWC_TRSP_DW.Debouncer2);

  /* End of Outputs for SubSystem: '<S9>/Debouncer2' */

  /* Logic: '<S9>/Logical Operator' */
  VAR_TRSP_CurrRngErr_b = (VAR_TRSP_UCurrRngErr_b || VAR_TRSP_VCurrRngErr_b ||
    VAR_TRSP_WCurrRngErr_b);

  /* SignalConversion: '<S1>/Signal Conversion4' */
  set_TRSP_CurrRngErr(VAR_TRSP_CurrRngErr_b);

  /* Outputs for Atomic SubSystem: '<S9>/iPhaCalc' */
  SWC_TRSP_iPhaCalc();

  /* End of Outputs for SubSystem: '<S9>/iPhaCalc' */

  /* Outputs for Atomic SubSystem: '<S9>/CurrSumChk' */
  SWC_TRSP_CurrSumChk();

  /* End of Outputs for SubSystem: '<S9>/CurrSumChk' */

  /* Outputs for Atomic SubSystem: '<S9>/Debouncer3' */
  /* SignalConversion generated from: '<S9>/Debouncer3' incorporates:
   *  Constant: '<S9>/CAL_TOM_CurrSumDebAdd_s1'
   *  Constant: '<S9>/CAL_TOM_CurrSumDebTrh_s16'
   *  Constant: '<S9>/CAL_TOM_CurrSumErrRst_b'
   */
  VAR_TRSP_CurrSumErr_b = SWC_TRSP_Debouncer11(VAR_TRSP_CurrSumChkRslt_b,
    CAL_TRSP_CurrSumErrRst_b, CAL_TRSP_CurrSumCountTrh_s16,
    CAL_TRSP_CurrSumDebTrh_s16, &SWC_TRSP_B.Debouncer3, &SWC_TRSP_DW.Debouncer3);

  /* End of Outputs for SubSystem: '<S9>/Debouncer3' */

  /* SignalConversion: '<S1>/Signal Conversion5' */
  set_TRSP_CurrSumErr(VAR_TRSP_CurrSumErr_b);

  /* SignalConversion: '<S1>/Signal Conversion' */
  set_TRSP_iU(VAR_TRSP_iU_f32);

  /* SignalConversion: '<S1>/Signal Conversion1' */
  set_TRSP_iV(VAR_TRSP_iV_f32);

  /* SignalConversion: '<S1>/Signal Conversion2' */
  set_TRSP_iW(VAR_TRSP_iW_f32);

  /* SignalConversion: '<S1>/Signal Conversion19' incorporates:
   *  Inport: '<Root>/L2Sampling_ExciBackP'
   */
  VAR_L2Sampling_ExciBackP_u16 = get_L2Sampling_ExciBackP();

  /* Outputs for Atomic SubSystem: '<S10>/RngChk2' */
  /* SignalConversion generated from: '<S10>/RngChk2' incorporates:
   *  Constant: '<S10>/CAL_TOM_RslvRngExciHiLim_f32'
   *  Constant: '<S10>/CAL_TOM_RslvRngExciLoLim_f32'
   */
  VAR_TRSP_RslvExciPRngChkRslt_b = SWC_TRSP_RngChk(VAR_L2Sampling_ExciBackP_u16,
    CAL_TRSP_RslvRngExciHiLim_u16, CAL_TRSP_RslvRngExciLoLim_u16);

  /* End of Outputs for SubSystem: '<S10>/RngChk2' */

  /* Outputs for Atomic SubSystem: '<S10>/Debouncer9' */
  /* SignalConversion generated from: '<S10>/Debouncer9' incorporates:
   *  Constant: '<S10>/CAL_TOM_RslvExciDebTrh_s1'
   *  Constant: '<S10>/CAL_TOM_RslvExciDebTrh_s16'
   *  Constant: '<S10>/CAL_TOM_RslvExciErrRst_b'
   */
  VAR_TRSP_RslvExciPRngErr_b = SWC_TRSP_Debouncer11
    (VAR_TRSP_RslvExciPRngChkRslt_b, CAL_TRSP_RslvExciErrRst_b,
     CAL_TRSP_RslvExciCountTrh_s16, CAL_TRSP_RslvExciDebTrh_s16,
     &SWC_TRSP_B.Debouncer9, &SWC_TRSP_DW.Debouncer9);

  /* End of Outputs for SubSystem: '<S10>/Debouncer9' */

  /* SignalConversion: '<S1>/Signal Conversion20' incorporates:
   *  Inport: '<Root>/L2Sampling_ExciBackN'
   */
  VAR_L2Sampling_ExciBackN_u16 = get_L2Sampling_ExciBackN();

  /* Outputs for Atomic SubSystem: '<S10>/RngChk1' */
  /* SignalConversion generated from: '<S10>/RngChk1' incorporates:
   *  Constant: '<S10>/CAL_TOM_RslvRngExciHiLim_f1'
   *  Constant: '<S10>/CAL_TOM_RslvRngExciLoLim_f1'
   */
  VAR_TRSP_RslvExciNRngChkRslt_b = SWC_TRSP_RngChk(VAR_L2Sampling_ExciBackN_u16,
    CAL_TRSP_RslvRngExciHiLim_u16, CAL_TRSP_RslvRngExciLoLim_u16);

  /* End of Outputs for SubSystem: '<S10>/RngChk1' */

  /* Outputs for Atomic SubSystem: '<S10>/Debouncer10' */
  /* SignalConversion generated from: '<S10>/Debouncer10' incorporates:
   *  Constant: '<S10>/CAL_TOM_RslvExciDebTrh_s2'
   *  Constant: '<S10>/CAL_TOM_RslvExciDebTrh_s3'
   *  Constant: '<S10>/CAL_TOM_RslvExciErrRst_b1'
   */
  VAR_TRSP_RslvExciNRngErr_b = SWC_TRSP_Debouncer11
    (VAR_TRSP_RslvExciNRngChkRslt_b, CAL_TRSP_RslvExciErrRst_b,
     CAL_TRSP_RslvExciCountTrh_s16, CAL_TRSP_RslvExciDebTrh_s16,
     &SWC_TRSP_B.Debouncer10, &SWC_TRSP_DW.Debouncer10);

  /* End of Outputs for SubSystem: '<S10>/Debouncer10' */

  /* Logic: '<S10>/Logical Operator1' */
  VAR_TRSP_RslvExciRngErr_b = (VAR_TRSP_RslvExciPRngErr_b ||
    VAR_TRSP_RslvExciNRngErr_b);

  /* SignalConversion: '<S1>/Signal Conversion8' */
  set_TRSP_RslvExciRngErr(VAR_TRSP_RslvExciRngErr_b);

  /* SignalConversion: '<S1>/Signal Conversion21' incorporates:
   *  Inport: '<Root>/L2Sampling_Exci18VLS_MON'
   */
  VAR_L2Sampling_Exci18VLS_MON_u16 = get_L2Sampling_Exci18VLS_MON();

  /* Outputs for Atomic SubSystem: '<S11>/RngChk' */
  /* SignalConversion generated from: '<S11>/RngChk' incorporates:
   *  Constant: '<S11>/CAL_TOM_CurrRngHiLim_f32'
   *  Constant: '<S11>/CAL_TOM_CurrRngLoLim_f32'
   */
  VAR_TRSP_RslvSensVoltRngChkRslt_b = SWC_TRSP_RngChk
    (VAR_L2Sampling_Exci18VLS_MON_u16, CAL_TRSP_RslvSensVoltHiLim_u16,
     CAL_TRSP_RslvSensVoltLoLim_u16);

  /* End of Outputs for SubSystem: '<S11>/RngChk' */

  /* Outputs for Atomic SubSystem: '<S11>/Debouncer11' */
  /* SignalConversion generated from: '<S11>/Debouncer11' incorporates:
   *  Constant: '<S11>/CAL_TOM_CurrRngDebTrh_s1'
   *  Constant: '<S11>/CAL_TOM_CurrRngDebTrh_s16'
   *  Constant: '<S11>/CAL_TOM_CurrRngErrRst_b1'
   */
  VAR_TRSP_RslvSensVoltRngErr_b = SWC_TRSP_Debouncer11
    (VAR_TRSP_RslvSensVoltRngChkRslt_b, CAL_TRSP_RslvSensVoltErrRst_b,
     CAL_TRSP_RslvSensVoltCountTrh_s16, CAL_TRSP_RslvSensVoltDebTrh_s16,
     &SWC_TRSP_B.Debouncer11_n, &SWC_TRSP_DW.Debouncer11_n);

  /* End of Outputs for SubSystem: '<S11>/Debouncer11' */

  /* SignalConversion: '<S1>/Signal Conversion3' */
  set_TRSP_RslvSensVolRngErr(VAR_TRSP_RslvSensVoltRngErr_b);

  /* SignalConversion: '<S1>/Signal Conversion22' incorporates:
   *  Inport: '<Root>/L2Sampling_LEM5V_MON'
   */
  VAR_L2Sampling_LEM5V_MON_u16 = get_L2Sampling_LEM5V_MON();

  /* Outputs for Atomic SubSystem: '<S13>/RngChk' */
  /* SignalConversion generated from: '<S13>/RngChk' incorporates:
   *  Constant: '<S13>/CAL_TOM_CurrRngHiLim_f1'
   *  Constant: '<S13>/CAL_TOM_CurrRngLoLim_f32'
   */
  VAR_TRSP_iPhasSensVoltRngChkRslt_b = SWC_TRSP_RngChk
    (VAR_L2Sampling_LEM5V_MON_u16, CAL_TRSP_iPhasSensVoltHiLim_u16,
     CAL_TRSP_iPhasSensVoltLoLim_u16);

  /* End of Outputs for SubSystem: '<S13>/RngChk' */

  /* Outputs for Atomic SubSystem: '<S13>/Debouncer12' */
  /* SignalConversion generated from: '<S13>/Debouncer12' incorporates:
   *  Constant: '<S13>/CAL_TOM_CurrRngDebTrh_s1'
   *  Constant: '<S13>/CAL_TOM_CurrRngDebTrh_s16'
   *  Constant: '<S13>/CAL_TOM_CurrRngErrRst_b'
   */
  VAR_TRSP_iPhasSensVoltRngErr_b = SWC_TRSP_Debouncer11
    (VAR_TRSP_iPhasSensVoltRngChkRslt_b, CAL_TRSP_iPhasSensVoltErrRst_b,
     CAL_TRSP_iPhasSensVoltCountTrh_s16, CAL_TRSP_iPhasSensVoltDebTrh_s16,
     &SWC_TRSP_B.Debouncer12, &SWC_TRSP_DW.Debouncer12);

  /* End of Outputs for SubSystem: '<S13>/Debouncer12' */

  /* SignalConversion: '<S1>/Signal Conversion9' */
  set_TRSP_iPhasSensVolRngErr(VAR_TRSP_iPhasSensVoltRngErr_b);

  /* SignalConversion: '<S1>/Signal Conversion25' incorporates:
   *  Inport: '<Root>/L2Sampling_UBRWIDE_MON'
   */
  VAR_L2Sampling_UBRWIDE_MON_u16 = get_L2Sampling_UBRWIDE_MON();

  /* SignalConversion: '<S1>/Signal Conversion27' incorporates:
   *  Inport: '<Root>/L2Sampling_UB_SBC_MON'
   */
  VAR_L2Sampling_UB_SBC_MON_u16 = get_L2Sampling_UB_SBC_MON();

  /* Outputs for Atomic SubSystem: '<S12>/UBR_SBCVoltCalc' */
  SWC_TRSP_UBR_SBCVoltCalc();

  /* End of Outputs for SubSystem: '<S12>/UBR_SBCVoltCalc' */

  /* Outputs for Atomic SubSystem: '<S12>/UBRVoltCompChk' */
  SWC_TRSP_UBRVoltCompChk();

  /* End of Outputs for SubSystem: '<S12>/UBRVoltCompChk' */

  /* Outputs for Atomic SubSystem: '<S12>/Debouncer11' */
  /* SignalConversion generated from: '<S12>/Debouncer11' incorporates:
   *  Constant: '<S12>/CAL_TOM_CurrRngDebTrh_s1'
   *  Constant: '<S12>/CAL_TOM_CurrRngDebTrh_s16'
   *  Constant: '<S12>/CAL_TOM_CurrRngErrRst_b1'
   */
  VAR_TRSP_UBRVoltRngErr_b = SWC_TRSP_Debouncer11(VAR_TRSP_UBRVoltRngChkRslt_b,
    CAL_TRSP_UBRVoltErrRst_b, CAL_TRSP_UBRVoltCountTrh_s16,
    CAL_TRSP_UBRVoltDebTrh_s16, &SWC_TRSP_B.Debouncer11_fe,
    &SWC_TRSP_DW.Debouncer11_fe);

  /* End of Outputs for SubSystem: '<S12>/Debouncer11' */

  /* SignalConversion: '<S1>/Signal Conversion28' */
  set_TRSP_UBRVoltRngErr(VAR_TRSP_UBRVoltRngErr_b);

  /* SignalConversion: '<S1>/Signal Conversion29' incorporates:
   *  Inport: '<Root>/L2Sampling_18VHS_MON'
   */
  VAR_L2Sampling_18VHS_MON_u16 = get_L2Sampling_18VHS_MON();

  /* Outputs for Atomic SubSystem: '<S5>/RngChk' */
  /* SignalConversion generated from: '<S5>/RngChk' incorporates:
   *  Constant: '<S5>/CAL_TOM_CurrRngHiLim_f32'
   *  Constant: '<S5>/CAL_TOM_CurrRngLoLim_f32'
   */
  VAR_TRSP_18VHSVoltRngChkRslt_b = SWC_TRSP_RngChk(VAR_L2Sampling_18VHS_MON_u16,
    CAL_TRSP_18VHSVoltHiLim_u16, CAL_TRSP_18VHSVoltLoLim_u16);

  /* End of Outputs for SubSystem: '<S5>/RngChk' */

  /* Outputs for Atomic SubSystem: '<S5>/Debouncer11' */
  /* SignalConversion generated from: '<S5>/Debouncer11' incorporates:
   *  Constant: '<S5>/CAL_TOM_CurrRngDebTrh_s1'
   *  Constant: '<S5>/CAL_TOM_CurrRngDebTrh_s16'
   *  Constant: '<S5>/CAL_TOM_CurrRngErrRst_b1'
   */
  VAR_TRSP_18VHSVoltRngErr_b = SWC_TRSP_Debouncer11
    (VAR_TRSP_18VHSVoltRngChkRslt_b, CAL_TRSP_18VHSVoltErrRst_b,
     CAL_TRSP_18VHSVoltCountTrh_s16, CAL_TRSP_18VHSVoltDebTrh_s16,
     &SWC_TRSP_B.Debouncer11, &SWC_TRSP_DW.Debouncer11);

  /* End of Outputs for SubSystem: '<S5>/Debouncer11' */

  /* SignalConversion: '<S1>/Signal Conversion30' */
  set_TRSP_18VHSVoltRngErr(VAR_TRSP_18VHSVoltRngErr_b);

  /* SignalConversion: '<S1>/Signal Conversion31' incorporates:
   *  Inport: '<Root>/L2Sampling_3V3CPLD_MON'
   */
  VAR_L2Sampling_3V3CPLD_MON_u16 = get_L2Sampling_3V3CPLD_MON();

  /* Outputs for Atomic SubSystem: '<S7>/RngChk' */
  /* SignalConversion generated from: '<S7>/RngChk' incorporates:
   *  Constant: '<S7>/CAL_TOM_CurrRngHiLim_f32'
   *  Constant: '<S7>/CAL_TOM_CurrRngLoLim_f32'
   */
  VAR_TRSP_3V3CPLDVoltRngChkRslt_b = SWC_TRSP_RngChk
    (VAR_L2Sampling_3V3CPLD_MON_u16, CAL_TRSP_3V3CPLDVoltHiLim_u16,
     CAL_TRSP_3V3CPLDVoltLoLim_u16);

  /* End of Outputs for SubSystem: '<S7>/RngChk' */

  /* Outputs for Atomic SubSystem: '<S7>/Debouncer11' */
  /* SignalConversion generated from: '<S7>/Debouncer11' incorporates:
   *  Constant: '<S7>/CAL_TOM_CurrRngDebTrh_s1'
   *  Constant: '<S7>/CAL_TOM_CurrRngDebTrh_s16'
   *  Constant: '<S7>/CAL_TOM_CurrRngErrRst_b1'
   */
  VAR_TRSP_3V3CPLDVoltRngErr_b = SWC_TRSP_Debouncer11
    (VAR_TRSP_3V3CPLDVoltRngChkRslt_b, CAL_TRSP_3V3CPLDVoltErrRst_b,
     CAL_TRSP_3V3CPLDVoltCountTrh_s16, CAL_TRSP_3V3CPLDVoltDebTrh_s16,
     &SWC_TRSP_B.Debouncer11_g, &SWC_TRSP_DW.Debouncer11_g);

  /* End of Outputs for SubSystem: '<S7>/Debouncer11' */

  /* SignalConversion: '<S1>/Signal Conversion32' */
  set_TRSP_3V3CPLDVoltRngErr(VAR_TRSP_3V3CPLDVoltRngErr_b);

  /* SignalConversion: '<S1>/Signal Conversion33' incorporates:
   *  Inport: '<Root>/L2Sampling_1V8CPLD_MON'
   */
  VAR_L2Sampling_1V8CPLD_MON_u16 = get_L2Sampling_1V8CPLD_MON();

  /* Outputs for Atomic SubSystem: '<S6>/RngChk' */
  /* SignalConversion generated from: '<S6>/RngChk' incorporates:
   *  Constant: '<S6>/CAL_TOM_CurrRngHiLim_f32'
   *  Constant: '<S6>/CAL_TOM_CurrRngLoLim_f32'
   */
  VAR_TRSP_1V8CPLDVoltRngChkRslt_b = SWC_TRSP_RngChk
    (VAR_L2Sampling_1V8CPLD_MON_u16, CAL_TRSP_1V8CPLDVoltHiLim_u16,
     CAL_TRSP_1V8CPLDVoltLoLim_u16);

  /* End of Outputs for SubSystem: '<S6>/RngChk' */

  /* Outputs for Atomic SubSystem: '<S6>/Debouncer11' */
  /* SignalConversion generated from: '<S6>/Debouncer11' incorporates:
   *  Constant: '<S6>/CAL_TOM_CurrRngDebTrh_s1'
   *  Constant: '<S6>/CAL_TOM_CurrRngDebTrh_s16'
   *  Constant: '<S6>/CAL_TOM_CurrRngErrRst_b1'
   */
  VAR_TRSP_1V8CPLDVoltRngErr_b = SWC_TRSP_Debouncer11
    (VAR_TRSP_1V8CPLDVoltRngChkRslt_b, CAL_TRSP_1V8CPLDVoltErrRst_b,
     CAL_TRSP_1V8CPLDVoltCountTrh_s16, CAL_TRSP_1V8CPLDVoltDebTrh_s16,
     &SWC_TRSP_B.Debouncer11_f, &SWC_TRSP_DW.Debouncer11_f);

  /* End of Outputs for SubSystem: '<S6>/Debouncer11' */

  /* SignalConversion: '<S1>/Signal Conversion34' */
  set_TRSP_1V8CPLDVoltRngErr(VAR_TRSP_1V8CPLDVoltRngErr_b);

  /* Outputs for Atomic SubSystem: '<S1>/AgRtrCalc' */
  SWC_TRSP_AgRtrCalc();

  /* End of Outputs for SubSystem: '<S1>/AgRtrCalc' */

  /* SignalConversion: '<S1>/Signal Conversion26' */
  set_TRSP_AgRtr(VAR_TRSP_AgRtr_f32);

  /* SignalConversion: '<S1>/Signal Conversion24' incorporates:
   *  Inport: '<Root>/L2Sampling_RslvCos'
   */
  VAR_L2Sampling_RslvCos_s32 = get_L2Sampling_RslvCos();

  /* SignalConversion: '<S1>/Signal Conversion23' incorporates:
   *  Inport: '<Root>/L2Sampling_RslvSin'
   */
  VAR_L2Sampling_RslvSin_s32 = get_L2Sampling_RslvSin();

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/SWC_TRSP_100us' */
}

/* Model step function for TID2 */
void SWC_TRSP_1ms(void)                /* Explicit Task: SWC_TRSP_1ms */
{
  boolean rtb_LogicalOperator_lm;
  sint16 rtb_Add_fy;

  /* RootInportFunctionCallGenerator generated from: '<Root>/SWC_TRSP_1ms' incorporates:
   *  SubSystem: '<Root>/SWC_TRSP_1ms_sys'
   */
  /* SignalConversion: '<S3>/Signal Conversion4' incorporates:
   *  Inport: '<Root>/NvM_AngAutoClbOffset'
   */
  VAR_NvM_AngAutoClbOffset_f32 = get_NvM_AngAutoClbOffset();

  /* SignalConversion: '<S3>/Signal Conversion1' incorporates:
   *  Inport: '<Root>/L2Com_ModeReq'
   */
  VAR_L2Com_ModeReq_u16 = get_L2Com_ModeReq();

  /* Outputs for Atomic SubSystem: '<S94>/OfstChkEnable' */
  /* Sum: '<S98>/Add' incorporates:
   *  Constant: '<S98>/Constant'
   *  Delay: '<S98>/Delay'
   */
  SWC_TRSP_DW.Delay_DSTATE++;

  /* Outputs for Enabled SubSystem: '<S94>/OfstChk' incorporates:
   *  EnablePort: '<S97>/Enable'
   */
  /* Logic: '<S98>/Logical Operator2' incorporates:
   *  Constant: '<S101>/Constant'
   *  Constant: '<S98>/CAL_TOM_SpeedCtlMode_u2'
   *  Constant: '<S98>/CAL_TOM_SpeedCtlMode_u3'
   *  Delay: '<S98>/Delay'
   *  Logic: '<S98>/Logical Operator'
   *  RelationalOperator: '<S101>/Compare'
   *  RelationalOperator: '<S98>/Relational Operator3'
   *  RelationalOperator: '<S98>/Relational Operator4'
   */
  if ((SWC_TRSP_DW.Delay_DSTATE == 1) && ((VAR_L2Com_ModeReq_u16 ==
        CAL_TRSP_SpeedCtlMode_u8) || (VAR_L2Com_ModeReq_u16 ==
        CAL_TRSP_TorqueCtlMode_u8))) {
    /* Outputs for Atomic SubSystem: '<S97>/OfstRngChk' */
    /* SignalConversion generated from: '<S97>/OfstRngChk' incorporates:
     *  Constant: '<S97>/CAL_TOM_OfstRngHiLim_f32'
     *  Constant: '<S97>/CAL_TOM_OfstRngLoLim_f32'
     */
    VAR_TRSP_OfstRngChkRslt_b = SWC_TRSP_OfstRngChk(VAR_NvM_AngAutoClbOffset_f32,
      CAL_TRSP_OfstRngHiLim_f32, CAL_TRSP_OfstRngLoLim_f32);

    /* End of Outputs for SubSystem: '<S97>/OfstRngChk' */

    /* Outputs for Atomic SubSystem: '<S97>/Lock' */
    SWC_TRSP_Lock();

    /* End of Outputs for SubSystem: '<S97>/Lock' */
  }

  /* End of Logic: '<S98>/Logical Operator2' */
  /* End of Outputs for SubSystem: '<S94>/OfstChk' */
  /* End of Outputs for SubSystem: '<S94>/OfstChkEnable' */

  /* SignalConversion: '<S3>/Signal Conversion' */
  set_TRSP_OfstRngErr(VAR_TRSP_OfstRngErr_b);

  /* Outputs for Atomic SubSystem: '<S3>/Debouncer' */
  SWC_TRSP_Debouncer(false, false, 0, 0, &rtb_LogicalOperator_lm,
                     &SWC_TRSP_B.Switch, &rtb_Add_fy, &SWC_TRSP_DW.Debouncer_o);

  /* End of Outputs for SubSystem: '<S3>/Debouncer' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/SWC_TRSP_1ms' */
}

/* Model step function for TID3 */
void SWC_TRSP_10ms(void)               /* Explicit Task: SWC_TRSP_10ms */
{
  boolean rtb_LogicalOperator_a;
  sint16 rtb_Add_fi;

  /* RootInportFunctionCallGenerator generated from: '<Root>/SWC_TRSP_10ms' incorporates:
   *  SubSystem: '<Root>/SWC_TRSP_10ms_sys'
   */
  /* SignalConversion: '<S2>/Signal Conversion7' incorporates:
   *  Inport: '<Root>/L2Com_TrqSetP'
   */
  VAR_L2Com_TrqSetP_f32 = get_L2Com_TrqSetP();

  /* Outputs for Atomic SubSystem: '<S85>/RngChk2' */
  /* SignalConversion generated from: '<S85>/RngChk2' incorporates:
   *  Constant: '<S85>/CAL_TOM_CurrRngHiLim_f2'
   *  Constant: '<S85>/CAL_TOM_CurrRngLoLim_f2'
   */
  VAR_TRSP_TrqSetPRngChkRslt_b = SWC_TRSP_RngChk_k(VAR_L2Com_TrqSetP_f32,
    CAL_TRSP_ReqTrqHiLim_f32, CAL_TRSP_ReqTrqLoLim_f32);

  /* End of Outputs for SubSystem: '<S85>/RngChk2' */

  /* Outputs for Atomic SubSystem: '<S85>/Debouncer15' */
  /* SignalConversion generated from: '<S85>/Debouncer15' incorporates:
   *  Constant: '<S85>/CAL_TOM_CurrRngDebTrh_s4'
   *  Constant: '<S85>/CAL_TOM_CurrRngDebTrh_s5'
   *  Constant: '<S85>/CAL_TOM_CurrRngErrRst_b3'
   */
  VAR_TRSP_TrqSetPRngErr_b = SWC_TRSP_Debouncer11(VAR_TRSP_TrqSetPRngChkRslt_b,
    CAL_TRSP_ReqTrqErrRst_b, CAL_TRSP_ReqTrqCountTrh_s16,
    CAL_TRSP_ReqTrqDebTrh_s16, &SWC_TRSP_B.Debouncer15, &SWC_TRSP_DW.Debouncer15);

  /* End of Outputs for SubSystem: '<S85>/Debouncer15' */

  /* SignalConversion: '<S2>/Signal Conversion3' */
  set_TRSP_TrqSetPRngErr(VAR_TRSP_TrqSetPRngErr_b);

  /* Outputs for Atomic SubSystem: '<S2>/Debouncer' */
  SWC_TRSP_Debouncer(false, false, 0, 0, &rtb_LogicalOperator_a,
                     &SWC_TRSP_B.Switch_i, &rtb_Add_fi, &SWC_TRSP_DW.Debouncer_n);

  /* End of Outputs for SubSystem: '<S2>/Debouncer' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/SWC_TRSP_10ms' */
}

/* Model initialize function */
void SWC_TRSP_initialize(void)
{
  /* SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/SWC_TRSP_1ms' incorporates:
   *  SubSystem: '<Root>/SWC_TRSP_1ms_sys'
   */
  /* SystemInitialize for SignalConversion: '<S3>/Signal Conversion' */
  set_TRSP_OfstRngErr(VAR_TRSP_OfstRngErr_b);

  /* End of SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/SWC_TRSP_1ms' */
}
#pragma section
/*
 * File trailer for generated code.
 *
 * [EOF]
 */
