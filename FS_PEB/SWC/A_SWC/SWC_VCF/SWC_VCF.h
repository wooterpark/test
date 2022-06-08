/*
 * File: SWC_VCF.h
 *
 * Code generated for Simulink model 'SWC_VCF'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Fri Jan 15 17:02:12 2021
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_SWC_VCF_h_
#define RTW_HEADER_SWC_VCF_h_
#include <math.h>
#ifndef SWC_VCF_COMMON_INCLUDES_
# define SWC_VCF_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_SWC_VCF.h"
#endif                                 /* SWC_VCF_COMMON_INCLUDES_ */

#include "SWC_VCF_types.h"

/* Macros for accessing real-time model data structure */

/* Exported data define */

/* Definition for custom storage class: Define */
#define PRV_SpdCtl_u8                  1U                        /* Referenced by:
                                                                  * '<S31>/PRV_SpdCtl_u8'
                                                                  * '<S35>/CAL_Vcf_go_nCtlExtReq_u8'
                                                                  */
#define VCF_GLB_pi_f32                 3.14159203F               /* Referenced by:
                                                                  * '<S51>/VCF_GLB_pi_f32_1'
                                                                  * '<S51>/VCF_GLB_pi_f32_2'
                                                                  * '<S51>/VCF_GLB_pi_f32_3'
                                                                  */

/* Block signals (default storage) */
typedef struct tag_B_SWC_VCF_T {
  float32 VCF_TrqSlop;                 /* '<S29>/StepSlopFunction' */
  uint8 CSPF_flgHoldModeReq;           /* '<S9>/Chart' */
} B_SWC_VCF_T;

/* Block states (default storage) for system '<Root>' */
typedef struct tag_DW_SWC_VCF_T {
  float32 UnitDelay_DSTATE[4];         /* '<S51>/Unit Delay' */
  float32 UnitDelay1_DSTATE[4];        /* '<S51>/Unit Delay1' */
  float32 UnitDelay_DSTATE_h;          /* '<S48>/Unit Delay' */
  float32 UnitDelay1_DSTATE_i;         /* '<S41>/Unit Delay1' */
  float32 UnitDelay5_DSTATE;           /* '<S41>/Unit Delay5' */
  float32 UnitDelay_DSTATE_n;          /* '<S16>/Unit Delay' */
  float32 UnitDelay_DSTATE_d;          /* '<S15>/Unit Delay' */
  uint16 count;                        /* '<S29>/StepSlopFunction' */
  uint16 count2;                       /* '<S29>/StepSlopFunction' */
  uint16 timecnt;                      /* '<S9>/Chart' */
  uint8 UnitDelay2_DSTATE;             /* '<S41>/Unit Delay2' */
  uint8 UnitDelay_DSTATE_g;            /* '<S13>/Unit Delay' */
  uint8 UnitDelay1_DSTATE_m;           /* '<S8>/Unit Delay1' */
  uint8 Delay2_DSTATE[2];              /* '<S8>/Delay2' */
  uint8 Delay3_DSTATE[3];              /* '<S8>/Delay3' */
  boolean UnitDelay_DSTATE_i;          /* '<S37>/Unit Delay' */
  boolean UnitDelay_DSTATE_c;          /* '<S8>/Unit Delay' */
  boolean Delay_DSTATE[2];             /* '<S8>/Delay' */
  boolean Delay1_DSTATE[3];            /* '<S8>/Delay1' */
  uint8 is_active_c1_SWC_VCF;          /* '<S9>/Chart' */
  uint8 is_c1_SWC_VCF;                 /* '<S9>/Chart' */
} DW_SWC_VCF_T;

/* Invariant block signals (default storage) */
typedef struct {
  const float32 DataTypeConversion;    /* '<S14>/Data Type Conversion' */
  const uint8 DataTypeConversion_d;    /* '<S39>/Data Type Conversion' */
  const uint8 DataTypeConversion1;     /* '<S39>/Data Type Conversion1' */
  const uint8 DataTypeConversion2;     /* '<S39>/Data Type Conversion2' */
  const uint8 DataTypeConversion_h;    /* '<S12>/Data Type Conversion' */
  const uint8 DataTypeConversion_e;    /* '<S8>/Data Type Conversion' */
  const uint8 DataTypeConversion1_f;   /* '<S8>/Data Type Conversion1' */
  const uint8 DataTypeConversion2_c;   /* '<S8>/Data Type Conversion2' */
  const uint8 DataTypeConversion3;     /* '<S8>/Data Type Conversion3' */
  const boolean LogicalOperator5;      /* '<S12>/Logical Operator5' */
  const boolean RelationalOperator4;   /* '<S12>/Relational Operator4' */
} ConstB_SWC_VCF_T;

/* Block signals (default storage) */
extern B_SWC_VCF_T SWC_VCF_B;

/* Block states (default storage) */
extern DW_SWC_VCF_T SWC_VCF_DW;
extern const ConstB_SWC_VCF_T SWC_VCF_ConstB;/* constant block i/o */

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern float32 VAR_Vcf_nMotorObsv_f32; /* '<S51>/Product1' */
extern float32 VAR_Vcf_nVehicleObsv_f32;/* '<S51>/Product2' */
extern float32 VAR_Vcf_TrqDmp_f32;     /* '<S52>/Switch2' */
extern float32 VAR_Vcf_SpdChangeRatio_f32;/* '<S41>/Divide' */
extern float32 VAR_Vcf_TrqSrtPInside_f32;/* '<S46>/Switch' */
extern float32 VAR_Vcf_SlopeReq_f32;   /* '<S29>/Switch' */
extern float32 VAR_Vcf_trqDesAdDmp_f32;/* '<S54>/Switch2' */
extern float32 VAR_Vcf_KpNCtl_f32;     /* '<S35>/Switch2' */
extern float32 VAR_Vcf_trqLoad_f32;    /* '<S51>/Add1' */
extern float32 VAR_Vcf_trqDesUnProc_f32;/* '<S53>/Chart1' */
extern float32 VAR_Vcf_trqRmp_f32;     /* '<S53>/Chart1' */
extern uint8 VAR_Vcf_CntAdding_u8;     /* '<S41>/Switch1' */
extern uint8 VAR_Vcf_SlopeChangePer_u8;/* '<S40>/Switch15' */
extern boolean VAR_Vcf_flgDmpActv_b;   /* '<S49>/Logical Operator' */
extern boolean VAR_Vcf_AsrOvHiLim_b;   /* '<S46>/Relational Operator6' */
extern boolean VAR_Vcf_AsrUnLolim_b;   /* '<S46>/Relational Operator7' */
extern boolean VAR_Vcf_flgTrqSetPDecAsr_b;/* '<S46>/Relational Operator1' */
extern boolean VAR_Vcf_AsrSlipFlg2_b;  /* '<S45>/Switch20' */
extern boolean VAR_Vcf_AsrSlipFlg1_b;  /* '<S45>/Switch19' */
extern boolean VAR_Vcf_AsrRatioUnLolim_b;/* '<S45>/Switch13' */
extern boolean VAR_Vcf_SlipFlag_b;     /* '<S45>/Switch11' */
extern boolean VAR_Vcf_TranstoHoldIn_b;/* '<S12>/Logical Operator3' */
extern boolean VAR_Vcf_TranstoHoldOut_b;/* '<S13>/Logical Operator2' */
extern boolean VAR_VCF_flgHoldModeReq_b;/* '<S9>/Switch' */
extern boolean VAR_Vcf_CrawlFlg_b;     /* '<S14>/Logical Operator5' */

/* Exported data declaration */
#pragma section ".rodata.Calib_32"

/* Declaration for custom storage class: iEDS_Parameter */
extern const volatile float32 CAL_Vcf_AccPedSet_f32;/* Referenced by: '<S17>/Constant' */
extern const volatile float32 CAL_Vcf_ActiveCntAver_f32;
                          /* Referenced by: '<S41>/CAL_TDC_ActiveCntAver_f32' */
extern const volatile uint8 CAL_Vcf_ActiveCnt_u8;/* Referenced by:
                                                  * '<S43>/Constant'
                                                  * '<S44>/Constant'
                                                  */
extern const volatile float32 CAL_Vcf_AutoHoldSpd_f32;
                            /* Referenced by: '<S31>/CAL_Vcf_AutoHoldSpd_f32' */
extern const volatile uint8 CAL_Vcf_BetLimSlope_u8;/* Referenced by: '<S40>/Constant16' */
extern const volatile boolean CAL_Vcf_BrkLgt_b;/* Referenced by: '<S18>/Constant' */
extern const volatile float32 CAL_Vcf_BwdHoldInSpdLim_f32;
                        /* Referenced by: '<S12>/CAL_Vcf_BwdHoldInSpdLim_f32' */
extern const volatile float32 CAL_Vcf_BwdHoldOutSpdLim_f32;/* Referenced by:
                                                            * '<S12>/CAL_Vcf_BwdHoldOutSpdLim_f32'
                                                            * '<S13>/CAL_Vcf_BwdHoldOutSpdLim_f32'
                                                            */
extern const volatile float32 CAL_Vcf_CofHoldTrq_f32;
                              /* Referenced by: '<S8>/CAL_Vcf_CofHoldTrq_f32' */
extern const volatile float32 CAL_Vcf_CrawlDspd_f32;/* Referenced by: '<S16>/Chart' */
extern const volatile float32 CAL_Vcf_CrawlNsetD_f32;/* Referenced by:
                                                      * '<S15>/CAL_VCF_CrawlNsetD_f32'
                                                      * '<S16>/Chart'
                                                      */
extern const volatile float32 CAL_Vcf_CrawlNsetR_f32;/* Referenced by:
                                                      * '<S15>/CAL_VCF_CrawlNsetR_f32'
                                                      * '<S16>/Chart'
                                                      */
extern const volatile float32 CAL_Vcf_CrawlRspd_f32;/* Referenced by: '<S16>/Chart' */
extern const volatile boolean CAL_Vcf_CrawlSwt_b;/* Referenced by: '<S14>/Constant6' */
extern const volatile float32 CAL_Vcf_CrawltrqLo_f32;/* Referenced by: '<S16>/Constant10' */
extern const volatile float32 CAL_Vcf_CrawltrqUp_f32;/* Referenced by: '<S16>/Constant9' */
extern const volatile float32 CAL_Vcf_Crawltrqadd1_f32;/* Referenced by: '<S16>/Chart' */
extern const volatile float32 CAL_Vcf_Crawltrqadd2_f32;/* Referenced by: '<S16>/Chart' */
extern const volatile float32 CAL_Vcf_Crawltrqsub_f32;/* Referenced by: '<S16>/Chart' */
extern const volatile float32 CAL_Vcf_DampingMatrixA_af32[16];
                        /* Referenced by: '<S51>/CAL_VCF_DampingMatrixA_af32' */
extern const volatile float32 CAL_Vcf_DampingMatrixB_af32[4];
                        /* Referenced by: '<S51>/CAL_VCF_DampingMatrixB_af32' */
extern const volatile float32 CAL_Vcf_DampingMatrixC_af32[4];
                        /* Referenced by: '<S51>/CAL_VCF_DampingMatrixC_af32' */
extern const volatile float32 CAL_Vcf_DampingMatrixLp_af32[4];
                       /* Referenced by: '<S51>/CAL_VCF_DampingMatrixLp_af32' */
extern const volatile uint8 CAL_Vcf_Drv_go_alOffsetcalReq_u8;
                   /* Referenced by: '<S53>/CAL_TDC_Drv_go_alOffsetcalReq_u8' */
extern const volatile boolean CAL_Vcf_FunctionReqSwt_b;
                           /* Referenced by: '<S39>/CAL_Vcf_FunctionReqSwt_b' */
extern const volatile float32 CAL_Vcf_FwdHoldInSpdLim_f32;
                        /* Referenced by: '<S12>/CAL_Vcf_FwdHoldInSpdLim_f32' */
extern const volatile float32 CAL_Vcf_FwdHoldOutSpdLim_f32;/* Referenced by:
                                                            * '<S12>/CAL_Vcf_FwdHoldOutSpdLim_f32'
                                                            * '<S13>/CAL_Vcf_FwdHoldOutSpdLim_f32'
                                                            */
extern const volatile uint8 CAL_Vcf_GearD_u8;/* Referenced by:
                                              * '<S16>/Chart'
                                              * '<S19>/Constant'
                                              * '<S23>/Constant'
                                              */
extern const volatile boolean CAL_Vcf_GearHoldOutSwt_b;
                           /* Referenced by: '<S13>/CAL_Vcf_GearHoldOutSwt_b' */
extern const volatile uint8 CAL_Vcf_GearLvD_u8;/* Referenced by:
                                                * '<S12>/CAL_VCF_GearLvD_u8'
                                                * '<S13>/CAL_VCF_GearLvD_u8'
                                                */
extern const volatile uint8 CAL_Vcf_GearLvN_u8;
                                 /* Referenced by: '<S13>/CAL_Vcf_GearLvN_u8' */
extern const volatile uint8 CAL_Vcf_GearLvR_u8;/* Referenced by:
                                                * '<S12>/CAL_VCF_GearLvR_u8'
                                                * '<S13>/CAL_VCF_GearLvR_u8'
                                                */
extern const volatile uint8 CAL_Vcf_GearR_u8;/* Referenced by:
                                              * '<S16>/Chart'
                                              * '<S20>/Constant'
                                              * '<S24>/Constant'
                                              */
extern const volatile float32 CAL_Vcf_GenElecSpd_f32;
                             /* Referenced by: '<S39>/CAL_Vcf_GenElecSpd_f32' */
extern const volatile float32 CAL_Vcf_HoldModVcuReq_u8;/* Referenced by:
                                                        * '<S12>/CAL_Vcf_HoldModVcuReq_u8'
                                                        * '<S13>/CAL_Vcf_HoldModVcuReq_u8'
                                                        */
extern const volatile uint16 CAL_Vcf_HoldTimeCount_u16;/* Referenced by: '<S9>/Chart' */
extern const volatile boolean CAL_Vcf_HoldTrqInSwt_b;
                              /* Referenced by: '<S8>/CAL_Vcf_HoldTrqInSwt_b' */
extern const volatile boolean CAL_Vcf_HoldTrqLoadSwt_b;
                            /* Referenced by: '<S8>/CAL_Vcf_HoldTrqLoadSwt_b' */
extern const volatile float32 CAL_Vcf_MotorDrvSpd_f32;/* Referenced by: '<S39>/Constant2' */
extern const volatile float32 CAL_Vcf_NegDmpMaxSpeed_f32;
                         /* Referenced by: '<S49>/CAL_VCF_NegDmpMaxSpeed_f32' */
extern const volatile float32 CAL_Vcf_NegDmpMaxTrq_f32;
                           /* Referenced by: '<S49>/CAL_VCF_NegDmpMaxTrq_f32' */
extern const volatile uint8 CAL_Vcf_NormalTrqSlope_u8;/* Referenced by:
                                                       * '<S40>/Constant15'
                                                       * '<S40>/Constant21'
                                                       */
extern const volatile float32 CAL_Vcf_OvCrawlDspd_f32;/* Referenced by: '<S21>/Constant' */
extern const volatile float32 CAL_Vcf_OvCrawlRspd_f32;/* Referenced by: '<S22>/Constant' */
extern const volatile uint8 CAL_Vcf_OvHiLimSlope_u8;/* Referenced by: '<S40>/Constant12' */
extern const volatile float32 CAL_Vcf_PosDmpMaxSpeed_f32;
                         /* Referenced by: '<S49>/CAL_VCF_PosDmpMaxSpeed_f32' */
extern const volatile float32 CAL_Vcf_PosDmpMaxTrq_f32;
                           /* Referenced by: '<S49>/CAL_VCF_PosDmpMaxTrq_f32' */
extern const volatile float32 CAL_Vcf_ReqTrqMechTrqDif_f32;
                       /* Referenced by: '<S45>/CAL_Vcf_ReqTrqMechTrqDif_f32' */
extern const volatile float32 CAL_Vcf_SLCalTrqSlp_f32;
                            /* Referenced by: '<S53>/CAL_VCF_SLCalTrqSlp_f32' */
extern const volatile uint8 CAL_Vcf_SpdCtlReq_u8;
                               /* Referenced by: '<S14>/CAL_VCF_SpdCtlReq_u8' */
extern const volatile float32 CAL_Vcf_SpdDebounce_f32;
                            /* Referenced by: '<S46>/CAL_Vcf_SpdDebounce_f32' */
extern const volatile uint8 CAL_Vcf_StandByReq_u8;/* Referenced by: '<S14>/Constant7' */
extern const volatile boolean CAL_Vcf_StepSlopeFunSwt_b;/* Referenced by: '<S29>/Constant' */
extern const volatile float32 CAL_Vcf_TrqAbsDiff_f32;
                             /* Referenced by: '<S46>/CAL_Vcf_TrqAbsDiff_f32' */
extern const volatile uint8 CAL_Vcf_TrqCtlReq_u8;
                               /* Referenced by: '<S14>/CAL_Csd_TrqCtlReq_u8' */
extern const volatile float32 CAL_Vcf_TrqDecRatio_f32;
                            /* Referenced by: '<S46>/CAL_Vcf_TrqDecRatio_f32' */
extern const volatile float32 CAL_Vcf_TrqDmpNegMax_f32;
                           /* Referenced by: '<S48>/CAL_Vcf_TrqDmpNegMax_f32' */
extern const volatile float32 CAL_Vcf_TrqDmpPosMax_f32;
                           /* Referenced by: '<S48>/CAL_Vcf_TrqDmpPosMax_f32' */
extern const volatile boolean CAL_Vcf_TrqDmpSwt_b;/* Referenced by:
                                                   * '<S50>/CAL_Vcf_TrqDmpSwt_b'
                                                   * '<S50>/CAL_Vcf_TrqDmpSwt_b1'
                                                   */
extern const volatile float32 CAL_Vcf_TrqFbkLMaxNeg_f32;
                                   /* Referenced by: '<S29>/StepSlopFunction' */
extern const volatile float32 CAL_Vcf_TrqFbkLMax_f32;
                                   /* Referenced by: '<S29>/StepSlopFunction' */
extern const volatile float32 CAL_Vcf_TrqFbkLMinNeg_f32;
                                   /* Referenced by: '<S29>/StepSlopFunction' */
extern const volatile float32 CAL_Vcf_TrqFbkLMin_f32;
                                   /* Referenced by: '<S29>/StepSlopFunction' */
extern const volatile float32 CAL_Vcf_TrqHoldOutLim_f32;
                          /* Referenced by: '<S13>/CAL_Vcf_TrqHoldOutLim_f32' */
extern const volatile float32 CAL_Vcf_TrqSlopAccMax_f32;
                                   /* Referenced by: '<S29>/StepSlopFunction' */
extern const volatile float32 CAL_Vcf_TrqSlopAccStep_f32;
                                   /* Referenced by: '<S29>/StepSlopFunction' */
extern const volatile uint8 CAL_Vcf_UnLoLimSlope_u8;/* Referenced by: '<S40>/Constant14' */
extern const volatile float32 CAL_Vcf_cnCtlNrm_f32;/* Referenced by:
                                                    * '<S35>/CAL_Vcf_cnCtlNrm_f32_1'
                                                    * '<S35>/CAL_Vcf_cnCtlNrm_f32_2'
                                                    */
extern const volatile boolean CAL_Vcf_flgOpenCrawlFcn_b;
                          /* Referenced by: '<S14>/CAL_VCF_flgOpenCrawlFcn_b' */
extern const volatile boolean CAL_Vcf_flgOpenHoldFcn_b;
                            /* Referenced by: '<S9>/CAL_VCF_flgOpenHoldFcn_b' */
extern const volatile boolean CAL_Vcf_flgUseSLCal_b;
                              /* Referenced by: '<S53>/CAL_VCF_flgUseSLCal_b' */
extern const volatile float32 CAL_Vcf_nAccChgHiLim_f32;/* Referenced by:
                                                        * '<S40>/Constant11'
                                                        * '<S46>/CAL_Vcf_nAccChgHiLim_f32'
                                                        */
extern const volatile float32 CAL_Vcf_nAccChgLoLim_f32;/* Referenced by:
                                                        * '<S40>/Constant13'
                                                        * '<S46>/CAL_Vcf_nAccChgLoLim_f32'
                                                        */
extern const volatile float32 CAL_Vcf_nSetRamp_f32;/* Referenced by: '<S15>/Constant2' */
extern const volatile float32 CAL_Vcf_spdThredDmpNeg_f32;
                         /* Referenced by: '<S48>/CAL_Vcf_spdThredDmpNeg_f32' */
extern const volatile float32 CAL_Vcf_spdThredDmpPos_f32;
                         /* Referenced by: '<S48>/CAL_Vcf_spdThredDmpPos_f32' */
extern const volatile float32 CAL_Vcf_stModeReqTabX_af32[16];
                                   /* Referenced by: '<S30>/1-D Lookup Table' */
extern const volatile float32 CAL_Vcf_stModeReqTabY_af32[16];
                                   /* Referenced by: '<S30>/1-D Lookup Table' */
extern const volatile float32 CAL_Vcf_tDamping_f32;
                               /* Referenced by: '<S51>/CAL_VCF_tDamping_f32' */
extern const volatile uint16 CAL_Vcf_tSlopAddMax_u16;
                                   /* Referenced by: '<S29>/StepSlopFunction' */
extern const volatile float32 CAL_Vcf_trqHoldMax_f32;
                              /* Referenced by: '<S8>/CAL_Vcf_trqHoldMax_f32' */
extern const volatile float32 CAL_Vcf_trqHoldMin_f32;
                              /* Referenced by: '<S8>/CAL_Vcf_trqHoldMin_f32' */
extern const volatile float32 CAL_Vcf_trqSlopeCoffent_f32;
                        /* Referenced by: '<S53>/CAL_TDC_trqSlopeCoffent_f32' */

#pragma section

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S26>/Data Type Duplicate' : Unused code path elimination
 * Block '<S26>/Data Type Propagation' : Unused code path elimination
 * Block '<S27>/Data Type Duplicate' : Unused code path elimination
 * Block '<S27>/Data Type Propagation' : Unused code path elimination
 * Block '<S39>/Constant10' : Unused code path elimination
 * Block '<S39>/Switch' : Unused code path elimination
 * Block '<S52>/Data Type Duplicate' : Unused code path elimination
 * Block '<S52>/Data Type Propagation' : Unused code path elimination
 * Block '<S13>/Abs2' : Eliminated since data is unsigned
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
 * '<Root>' : 'SWC_VCF'
 * '<S1>'   : 'SWC_VCF/RE_SWC_VCF_10ms_sys'
 * '<S2>'   : 'SWC_VCF/RE_SWC_VCF_2ms_sys'
 * '<S3>'   : 'SWC_VCF/RE_SWC_VCF_Init'
 * '<S4>'   : 'SWC_VCF/RE_SWC_VCF_10ms_sys/10ms'
 * '<S5>'   : 'SWC_VCF/RE_SWC_VCF_10ms_sys/10ms/10ms'
 * '<S6>'   : 'SWC_VCF/RE_SWC_VCF_10ms_sys/10ms/10ms/AutoHold'
 * '<S7>'   : 'SWC_VCF/RE_SWC_VCF_10ms_sys/10ms/10ms/Crawl'
 * '<S8>'   : 'SWC_VCF/RE_SWC_VCF_10ms_sys/10ms/10ms/HoldStartTrqCal'
 * '<S9>'   : 'SWC_VCF/RE_SWC_VCF_10ms_sys/10ms/10ms/AutoHold/Subsystem'
 * '<S10>'  : 'SWC_VCF/RE_SWC_VCF_10ms_sys/10ms/10ms/AutoHold/Subsystem/Chart'
 * '<S11>'  : 'SWC_VCF/RE_SWC_VCF_10ms_sys/10ms/10ms/AutoHold/Subsystem/Subsystem'
 * '<S12>'  : 'SWC_VCF/RE_SWC_VCF_10ms_sys/10ms/10ms/AutoHold/Subsystem/Subsystem/TrastoHoldIn'
 * '<S13>'  : 'SWC_VCF/RE_SWC_VCF_10ms_sys/10ms/10ms/AutoHold/Subsystem/Subsystem/TrastoHoldOut'
 * '<S14>'  : 'SWC_VCF/RE_SWC_VCF_10ms_sys/10ms/10ms/Crawl/CrawlMode'
 * '<S15>'  : 'SWC_VCF/RE_SWC_VCF_10ms_sys/10ms/10ms/Crawl/CrawlSpdCal'
 * '<S16>'  : 'SWC_VCF/RE_SWC_VCF_10ms_sys/10ms/10ms/Crawl/CrawlTrqCal'
 * '<S17>'  : 'SWC_VCF/RE_SWC_VCF_10ms_sys/10ms/10ms/Crawl/CrawlMode/CAL_VCF_AccPedSet_f32'
 * '<S18>'  : 'SWC_VCF/RE_SWC_VCF_10ms_sys/10ms/10ms/Crawl/CrawlMode/CAL_VCF_BrkLgt_b '
 * '<S19>'  : 'SWC_VCF/RE_SWC_VCF_10ms_sys/10ms/10ms/Crawl/CrawlMode/CAL_VCF_GearD_u8'
 * '<S20>'  : 'SWC_VCF/RE_SWC_VCF_10ms_sys/10ms/10ms/Crawl/CrawlMode/CAL_VCF_GearR_u8'
 * '<S21>'  : 'SWC_VCF/RE_SWC_VCF_10ms_sys/10ms/10ms/Crawl/CrawlMode/CAL_VCF_OvCrawlDspd_f32'
 * '<S22>'  : 'SWC_VCF/RE_SWC_VCF_10ms_sys/10ms/10ms/Crawl/CrawlMode/Compare To Constant'
 * '<S23>'  : 'SWC_VCF/RE_SWC_VCF_10ms_sys/10ms/10ms/Crawl/CrawlSpdCal/CAL_VCF_GearD_u8'
 * '<S24>'  : 'SWC_VCF/RE_SWC_VCF_10ms_sys/10ms/10ms/Crawl/CrawlSpdCal/CAL_VCF_GearR_u8'
 * '<S25>'  : 'SWC_VCF/RE_SWC_VCF_10ms_sys/10ms/10ms/Crawl/CrawlTrqCal/Chart'
 * '<S26>'  : 'SWC_VCF/RE_SWC_VCF_10ms_sys/10ms/10ms/Crawl/CrawlTrqCal/Saturation Dynamic'
 * '<S27>'  : 'SWC_VCF/RE_SWC_VCF_10ms_sys/10ms/10ms/HoldStartTrqCal/Saturation Dynamic1'
 * '<S28>'  : 'SWC_VCF/RE_SWC_VCF_2ms_sys/2ms'
 * '<S29>'  : 'SWC_VCF/RE_SWC_VCF_2ms_sys/2ms/2msSub1'
 * '<S30>'  : 'SWC_VCF/RE_SWC_VCF_2ms_sys/2ms/CanSig_MAP'
 * '<S31>'  : 'SWC_VCF/RE_SWC_VCF_2ms_sys/2ms/SignalSelect'
 * '<S32>'  : 'SWC_VCF/RE_SWC_VCF_2ms_sys/2ms/Subsystem'
 * '<S33>'  : 'SWC_VCF/RE_SWC_VCF_2ms_sys/2ms/2msSub1/ASRFunction'
 * '<S34>'  : 'SWC_VCF/RE_SWC_VCF_2ms_sys/2ms/2msSub1/Damping_2ms'
 * '<S35>'  : 'SWC_VCF/RE_SWC_VCF_2ms_sys/2ms/2msSub1/KpCal_2ms'
 * '<S36>'  : 'SWC_VCF/RE_SWC_VCF_2ms_sys/2ms/2msSub1/StepSlopFunction'
 * '<S37>'  : 'SWC_VCF/RE_SWC_VCF_2ms_sys/2ms/2msSub1/ASRFunction/ASRFunction'
 * '<S38>'  : 'SWC_VCF/RE_SWC_VCF_2ms_sys/2ms/2msSub1/ASRFunction/ChangeSlopeValue'
 * '<S39>'  : 'SWC_VCF/RE_SWC_VCF_2ms_sys/2ms/2msSub1/ASRFunction/FuntionEnableDetermine'
 * '<S40>'  : 'SWC_VCF/RE_SWC_VCF_2ms_sys/2ms/2msSub1/ASRFunction/ASRFunction/SlopeValueChange'
 * '<S41>'  : 'SWC_VCF/RE_SWC_VCF_2ms_sys/2ms/2msSub1/ASRFunction/ASRFunction/SpdChangeRatio'
 * '<S42>'  : 'SWC_VCF/RE_SWC_VCF_2ms_sys/2ms/2msSub1/ASRFunction/ASRFunction/TorqueCalculate'
 * '<S43>'  : 'SWC_VCF/RE_SWC_VCF_2ms_sys/2ms/2msSub1/ASRFunction/ASRFunction/SpdChangeRatio/Compare To Constant'
 * '<S44>'  : 'SWC_VCF/RE_SWC_VCF_2ms_sys/2ms/2msSub1/ASRFunction/ASRFunction/SpdChangeRatio/Compare To Constant1'
 * '<S45>'  : 'SWC_VCF/RE_SWC_VCF_2ms_sys/2ms/2msSub1/ASRFunction/ASRFunction/TorqueCalculate/ASRSlipFlag'
 * '<S46>'  : 'SWC_VCF/RE_SWC_VCF_2ms_sys/2ms/2msSub1/ASRFunction/ASRFunction/TorqueCalculate/ASRTrqDes'
 * '<S47>'  : 'SWC_VCF/RE_SWC_VCF_2ms_sys/2ms/2msSub1/Damping_2ms/Vcf_DmpCtl'
 * '<S48>'  : 'SWC_VCF/RE_SWC_VCF_2ms_sys/2ms/2msSub1/Damping_2ms/Vcf_DmpCtl/Subsystem'
 * '<S49>'  : 'SWC_VCF/RE_SWC_VCF_2ms_sys/2ms/2msSub1/Damping_2ms/Vcf_DmpCtl/Vcf_FlgDmpCalc'
 * '<S50>'  : 'SWC_VCF/RE_SWC_VCF_2ms_sys/2ms/2msSub1/Damping_2ms/Vcf_DmpCtl/Vcf_TrqDmpCalc'
 * '<S51>'  : 'SWC_VCF/RE_SWC_VCF_2ms_sys/2ms/2msSub1/Damping_2ms/Vcf_DmpCtl/Vcf_nVehicleObsv'
 * '<S52>'  : 'SWC_VCF/RE_SWC_VCF_2ms_sys/2ms/2msSub1/Damping_2ms/Vcf_DmpCtl/Vcf_TrqDmpCalc/TrqDmpMax TrqDmpMin'
 * '<S53>'  : 'SWC_VCF/RE_SWC_VCF_2ms_sys/2ms/Subsystem/TrqSelect'
 * '<S54>'  : 'SWC_VCF/RE_SWC_VCF_2ms_sys/2ms/Subsystem/VCF_TrqResultant'
 * '<S55>'  : 'SWC_VCF/RE_SWC_VCF_2ms_sys/2ms/Subsystem/TrqSelect/Chart1'
 */
#endif                                 /* RTW_HEADER_SWC_VCF_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
