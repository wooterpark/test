/*
 * File: SWC_MCF.h
 *
 * Code generated for Simulink model 'SWC_MCF'.
 *
 * Model version                  : 1.10
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Mon Jan 25 16:58:23 2021
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_SWC_MCF_h_
#define RTW_HEADER_SWC_MCF_h_
#include <math.h>
#ifndef SWC_MCF_COMMON_INCLUDES_
# define SWC_MCF_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_SWC_MCF.h"
#endif                                 /* SWC_MCF_COMMON_INCLUDES_ */

#include "SWC_MCF_types.h"

/* Macros for accessing real-time model data structure */

/* Exported data define */

/* Definition for custom storage class: Define */
#define MCF_ANGLE_CURRENT_150          150.0F                    /* Referenced by: '<S65>/Chart' */
#define MCF_ANGLE_CURRENT_210          210.0F                    /* Referenced by: '<S65>/Chart' */
#define MCF_ANGLE_CURRENT_270          270.0F                    /* Referenced by: '<S65>/Chart' */
#define MCF_ANGLE_CURRENT_30           30.0F                     /* Referenced by: '<S65>/Chart' */
#define MCF_ANGLE_CURRENT_330          330.0F                    /* Referenced by: '<S65>/Chart' */
#define MCF_ANGLE_CURRENT_90           90.0F                     /* Referenced by: '<S65>/Chart' */
#define MCF_CURRENT_SECTOR_1           1U                        /* Referenced by: '<S65>/Chart' */
#define MCF_CURRENT_SECTOR_2           2U                        /* Referenced by: '<S65>/Chart' */
#define MCF_CURRENT_SECTOR_3           3U                        /* Referenced by: '<S65>/Chart' */
#define MCF_CURRENT_SECTOR_4           4U                        /* Referenced by: '<S65>/Chart' */
#define MCF_CURRENT_SECTOR_5           5U                        /* Referenced by: '<S65>/Chart' */
#define MCF_CURRENT_SECTOR_6           6U                        /* Referenced by: '<S65>/Chart' */
#define MCF_GLB_CircAge_f32            360.0F                    /* Referenced by:
                                                                  * '<S14>/CAL_CSP_GLB_CircAge_f32'
                                                                  * '<S177>/MCF_GLB_CircAge_f32'
                                                                  * '<S87>/MCF_GLB_CircAge_f32 '
                                                                  */
#define MCF_GLB_DigtValue_u16          4096U                     /* Referenced by:
                                                                  * '<S13>/CAL_CSP_GLB_DigtValue_u1'
                                                                  * '<S13>/CAL_CSP_GLB_DigtValue_u16'
                                                                  * '<S13>/CAL_CSP_GLB_DigtValue_u2'
                                                                  * '<S14>/CAL_CSP_GLB_DigtValue_u16'
                                                                  * '<S177>/MCF_GLB_DigtValue_u16'
                                                                  * '<S87>/MCF_GLB_DigtValue_u16 '
                                                                  */
#define MCF_GLB_IGBTRun_u8             3U                        /* Referenced by: '<S110>/MCF_GLB_IGBTRun_u8' */
#define MCF_GLB_MotorPole_u8           4U                        /* Referenced by:
                                                                  * '<S177>/MCF_GLB_MotorPole_u8'
                                                                  * '<S28>/MCF_GLB_MotorPole_u8'
                                                                  * '<S90>/MCF_GLB_MotorPole_u8'
                                                                  * '<S102>/MCF_GLB_MotorPole_u8'
                                                                  * '<S104>/MCF_GLB_MotorPole_u8'
                                                                  */
#define MCF_GLB_OneHalf_f32            0.5F                      /* Referenced by:
                                                                  * '<S13>/CAL_CSP_GLB_OneHalf_f1'
                                                                  * '<S13>/CAL_CSP_GLB_OneHalf_f2'
                                                                  * '<S13>/CAL_CSP_GLB_OneHalf_f32'
                                                                  * '<S127>/MCF_GLB_OneHalf_f32'
                                                                  * '<S128>/MCF_GLB_OneHalf_f32'
                                                                  * '<S130>/MCF_GLB_OneHalf_f32'
                                                                  * '<S145>/MCF_GLB_OneHalf_f32'
                                                                  * '<S147>/MCF_GLB_OneHalf_f32'
                                                                  * '<S148>/MCF_GLB_OneHalf_f32'
                                                                  */

/* 常数0.5 */
#define MCF_GLB_Sixty_f32              60.0F                     /* Referenced by:
                                                                  * '<S168>/MCF_GLB_Sixty_f32  '
                                                                  * '<S177>/MCF_GLB_Sixty_f3'
                                                                  */

/* 常数值60 */
#define MCF_GLB_SqrtThree_f32          1.73205101F               /* Referenced by:
                                                                  * '<S10>/MCF_GLB_SqrtThree_f32'
                                                                  * '<S168>/MCF_GLB_SqrtThree_f32'
                                                                  * '<S148>/MCF_GLB_SqrtThree_f32'
                                                                  */
#define MCF_GLB_pi_f32                 3.14159203F               /* Referenced by:
                                                                  * '<S56>/MCF_GLB_pi_f32'
                                                                  * '<S90>/MCF_GLB_pi_f32'
                                                                  * '<S102>/MCF_GLB_pi_f32'
                                                                  * '<S104>/MCF_GLB_pi_f32'
                                                                  */
#define MCF_Succeed_u8                 2U                        /* Referenced by: '<S13>/CAL_CSP_Succeed_u8' */

/* 自检或标定成功 */

/* Block signals (default storage) */
typedef struct tag_B_SWC_MCF_T {
  float32 Divide2;                     /* '<S168>/Divide2' */
  float32 Switch3;                     /* '<S112>/Switch3' */
  float32 CAL_MCF_uQDesEOL_f32_h;      /* '<S112>/CAL_MCF_uQDesEOL_f32' */
  float32 MCF_udDes11ZR;               /* '<S88>/Add' */
  float32 MCF_uqDes11ZR;               /* '<S88>/Add1' */
  float32 MCF_uAlphaDeadCpn;           /* '<S66>/Product1' */
  float32 MCF_uBetaDeadCpn;            /* '<S67>/Product1' */
  float32 uDLookupTable;               /* '<S42>/1-D Lookup Table' */
  float32 Switch;                      /* '<S44>/Switch' */
} B_SWC_MCF_T;

/* Block states (default storage) for system '<Root>' */
typedef struct tag_DW_SWC_MCF_T {
  float32 UnitDelay2_DSTATE;           /* '<S184>/Unit Delay2' */
  float32 Delay2_DSTATE;               /* '<S32>/Delay2' */
  float32 Delay_DSTATE;                /* '<S25>/Delay' */
  float32 UnitDelay_DSTATE_g;          /* '<S57>/Unit Delay' */
  float32 Delay1_DSTATE;               /* '<S25>/Delay1' */
  float32 UnitDelay1_DSTATE;           /* '<S57>/Unit Delay1' */
  float32 UnitDelay_DSTATE_k;          /* '<S58>/Unit Delay' */
  float32 UnitDelay_DSTATE_o;          /* '<S41>/Unit Delay' */
  float32 UnitDelay2_DSTATE_c;         /* '<S185>/Unit Delay2' */
  float32 UnitDelay_1_DSTATE;          /* '<S106>/Unit Delay' */
  float32 UnitDelay_2_DSTATE;          /* '<S106>/Unit Delay' */
  float32 UnitDelay_3_DSTATE;          /* '<S106>/Unit Delay' */
  float32 UnitDelay_DSTATE_b;          /* '<S181>/Unit Delay' */
  float32 UnitDelay1_DSTATE_h;         /* '<S109>/Unit Delay1' */
  float32 UnitDelay_DSTATE_f;          /* '<S112>/Unit Delay' */
  float32 UnitDelay_DSTATE_n;          /* '<S109>/Unit Delay' */
  float32 UnitDelay4_DSTATE;           /* '<S103>/Unit Delay4' */
  float32 Delay_DSTATE_p;              /* '<S95>/Delay' */
  float32 Delay1_DSTATE_g;             /* '<S95>/Delay1' */
  float32 UnitDelay4_DSTATE_o;         /* '<S101>/Unit Delay4' */
  float32 Delay_DSTATE_g;              /* '<S96>/Delay' */
  float32 Delay1_DSTATE_p;             /* '<S96>/Delay1' */
  float32 UnitDelay_DSTATE_bu;         /* '<S102>/Unit Delay' */
  float32 UnitDelay2_DSTATE_d;         /* '<S102>/Unit Delay2' */
  float32 UnitDelay3_DSTATE;           /* '<S102>/Unit Delay3' */
  float32 UnitDelay1_DSTATE_hc;        /* '<S102>/Unit Delay1' */
  float32 UnitDelay_DSTATE_d;          /* '<S104>/Unit Delay' */
  float32 UnitDelay2_DSTATE_h;         /* '<S104>/Unit Delay2' */
  float32 UnitDelay3_DSTATE_p;         /* '<S104>/Unit Delay3' */
  float32 UnitDelay1_DSTATE_k;         /* '<S104>/Unit Delay1' */
  float32 UnitDelay_DSTATE_kk;         /* '<S43>/Unit Delay' */
  uint16 UnitDelay1_DSTATE_l;          /* '<S119>/Unit Delay1' */
  boolean UnitDelay_DSTATE_p;          /* '<S34>/Unit Delay' */
  boolean UnitDelay_DSTATE_gm;         /* '<S82>/Unit Delay' */
  boolean UnitDelay_DSTATE_ns;         /* '<S122>/Unit Delay' */
} DW_SWC_MCF_T;

/* Block signals (default storage) */
extern B_SWC_MCF_T SWC_MCF_B;

/* Block states (default storage) */
extern DW_SWC_MCF_T SWC_MCF_DW;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern float32 VAR_MCF_iU_f32;         /* '<S13>/Multiport Switch' */
extern float32 VAR_MCF_iV_f32;         /* '<S13>/Multiport Switch1' */
extern float32 VAR_MCF_iW_f32;         /* '<S13>/Multiport Switch2' */
extern float32 VAR_MCF_Is_f32;         /* '<S11>/Sqrt' */
extern float32 VAR_MCF_agOffset_f32;   /* '<S12>/Switch3' */
extern float32 VAR_MCF_agRtrEe_f32;    /* '<S15>/Switch' */
extern float32 VAR_MCF_uDcLnk_f32;     /* '<S13>/Switch4' */
extern float32 VAR_MCF_idAct_f32;      /* '<S14>/Add' */
extern float32 VAR_MCF_iqAct_f32;      /* '<S14>/Add1' */
extern float32 VAR_MCF_UsUseRateDes_f32;/* '<S22>/Subtract' */
extern float32 VAR_MCF_udRv_f32;       /* '<S56>/Product5' */
extern float32 VAR_MCF_periodCalc_f32; /* '<S32>/Add' */
extern float32 VAR_MCF_isdFW_f32;      /* '<S36>/Switch2' */
extern float32 VAR_MCF_idMotHeat_f32;  /* '<S34>/Switch' */
extern float32 VAR_MCF_idDes_f32;      /* '<S30>/Merge' */
extern float32 VAR_MCF_MPC_Ld_f32;     /* '<S55>/Add' */
extern float32 VAR_MCF_Rdc_nWoFlt_f32; /* '<S55>/Add2' */
extern float32 VAR_MCF_MPC_Lq_f32;     /* '<S55>/Add1' */
extern float32 VAR_MCF_MPC_LdSubLq_f32;/* '<S27>/Add2' */
extern float32 VAR_MCF_iqDes_f32;      /* '<S31>/Merge' */
extern float32 VAR_MCF_EmfBack_f32;    /* '<S56>/Product17' */
extern float32 VAR_MCF_uqRv_f32;       /* '<S56>/Product21' */
//extern float32 VAR_MCF_udDes_f32;      /* '<S25>/Switch1' */
//extern float32 VAR_MCF_uqDes_f32;      /* '<S25>/Switch4' */
extern float32 VAR_MCF_UsUseRateReal_f32;/* '<S23>/Add' */
extern float32 VAR_MCF_uAlphaDeadCpn_f32;/* '<S60>/Switch' */
extern float32 VAR_MCF_uBetaDeadCpn_f32;/* '<S60>/Switch' */
extern float32 VAR_MCF_UdDes11ZR_f32;  /* '<S61>/Switch2' */
extern float32 VAR_MCF_UqDes11ZR_f32;  /* '<S61>/Switch2' */
extern float32 VAR_MCF_uAlphaZero_f32; /* '<S62>/Switch' */
extern float32 VAR_MCF_uBetaZero_f32;  /* '<S62>/Switch' */
extern float32 VAR_MCF_uDDesEOL_f32;   /* '<S107>/Switch' */
extern float32 VAR_MCF_uQDesEOL_f32;   /* '<S107>/Switch' */
extern float32 VAR_MCF_uAOfsClb_f32;   /* '<S180>/Switch' */
extern float32 VAR_MCF_uBOfsClb_f32;   /* '<S180>/Switch1' */
extern float32 VAR_MCF_usPeak_f32;     /* '<S168>/Sqrt' */
extern float32 VAR_MCF_AgRem_f32;      /* '<S170>/Add3' */
extern float32 VAR_MCF_uAOm_f32;       /* '<S168>/Divide' */
extern float32 VAR_MCF_uBOm_f32;       /* '<S168>/Divide1' */
extern float32 VAR_MCF_iAlphaActFlt_f32;/* '<S103>/Add' */
extern float32 VAR_MCF_iBetaActFlt_f32;/* '<S101>/Add' */
extern float32 VAR_MCF_IsSet11ZR_f32;  /* '<S89>/1-D Lookup Table' */
extern float32 VAR_MCF_IsThetaSet11ZR_f32;/* '<S89>/1-D Lookup Table1' */
extern float32 VAR_MCF_PCUHeaterPower_f32;/* '<S42>/Product4' */
extern float32 VAR_MCF_PowerDcLnk_f32; /* '<S42>/Product1' */
extern float32 VAR_MCF_PowerMech_f32;  /* '<S42>/Product3' */
extern float32 VAR_MCF_PowerMotHeat_f32;/* '<S42>/Add' */
extern uint8 VAR_MCF_HSPF_stIphaOffCal_u8;/* '<S9>/Add' */
extern uint8 VAR_MCF_TMAhtChsts_f32;   /* '<S38>/Switch' */
extern boolean VAR_MCF_flgFw_b;        /* '<S22>/Switch3' */
extern boolean VAR_MCF_flgMotHeat_b;   /* '<S45>/Logical Operator' */
extern boolean VAR_MCF_SCF_flgInitEn_b;/* '<S55>/Logical Operator' */
extern boolean VAR_MCF_FlgDeadCpn_b;   /* '<S81>/Logical Operator' */

/* Exported data declaration */
#pragma section ".rodata.Calib_32"

/* Declaration for custom storage class: iEDS_Parameter */
extern const volatile uint8 CAL_MCF_ActiveHeatInit_u8;/* Referenced by: '<S38>/Constant3' */
extern const volatile uint8 CAL_MCF_ActiveHeatNormal_u8;/* Referenced by: '<S38>/Constant2' */
extern const volatile float32 CAL_MCF_AgDiffCurrSec_f32;
                          /* Referenced by: '<S65>/CAL_MCF_AgDiffCurrSec_f32' */
extern const volatile float32 CAL_MCF_AgRangeDeadCpnX_Trq_af32[7];
                   /* Referenced by: '<S65>/Angle range of dead compensation' */
extern const volatile float32 CAL_MCF_AgRangeDeadCpnY_Ag_af32[7];
                   /* Referenced by: '<S65>/Angle range of dead compensation' */
extern const volatile float32 CAL_MCF_AplhaRefZeroCtl_f32;
                      /* Referenced by: '<S95>/CAL_McPoc_ZeroCtlAplhaRef_f32' */
extern const volatile float32 CAL_MCF_BetaRefZeroCtl_f32;
                         /* Referenced by: '<S96>/CAL_MCF_BetaRefZeroCtl_f32' */
extern const volatile float32 CAL_MCF_CoefFltZero_A_f32;/* Referenced by:
                                                         * '<S102>/CAL_MCF_CoefFltZero_A_f32'
                                                         * '<S104>/CAL_MCF_CoefFltZero_A_f32'
                                                         */
extern const volatile float32 CAL_MCF_CoefFltZero_B_f32;/* Referenced by:
                                                         * '<S102>/CAL_MCF_CoefFltZero_B_f32'
                                                         * '<S104>/CAL_MCF_CoefFltZero_B_f32'
                                                         */
extern const volatile float32 CAL_MCF_CoefFltZero_C_f32;/* Referenced by:
                                                         * '<S102>/CAL_MCF_CoefFltZero_C_f32'
                                                         * '<S104>/CAL_MCF_CoefFltZero_C_f32'
                                                         */
extern const volatile float32 CAL_MCF_CoefPIAlphaZeroCtlY_Ki_af32[10];
                                     /* Referenced by: '<S93>/MC_ZeroAlphaKp' */
extern const volatile float32 CAL_MCF_CoefPIAlphaZeroFtlY_Kp_af32[10];
                                     /* Referenced by: '<S93>/MC_ZeroAlphaKi' */
extern const volatile float32 CAL_MCF_CoefPIBetaZeroCtlY_Ki_af32[10];
                                     /* Referenced by: '<S94>/MC_ZeroAlphaKp' */
extern const volatile float32 CAL_MCF_CoefPIBetaZeroCtlY_Kp_af32[10];
                                     /* Referenced by: '<S94>/MC_ZeroAlphaKi' */
extern const volatile float32 CAL_MCF_CoefPIZoreCtlX_N_af32[10];/* Referenced by:
                                                                 * '<S93>/MC_ZeroAlphaKi'
                                                                 * '<S93>/MC_ZeroAlphaKp'
                                                                 * '<S94>/MC_ZeroAlphaKi'
                                                                 * '<S94>/MC_ZeroAlphaKp'
                                                                 */
extern const volatile float32 CAL_MCF_CoefuDCLimtEOL_f32;
                        /* Referenced by: '<S112>/CAL_MCF_CoefuDCLimtEOL_f32' */
extern const volatile float32 CAL_MCF_DeadTimeCpn_f32;
                            /* Referenced by: '<S65>/CAL_MCF_DeadTimeCpn_f32' */
extern const volatile float32 CAL_MCF_DeadTimeTableX_Frq_af32[15];
                                     /* Referenced by: '<S121>/DeadTimeTable' */

/* 死区时间查表输入载频 */
extern const volatile float32 CAL_MCF_DeadTimeTableY_Ti_af32[15];
                                     /* Referenced by: '<S121>/DeadTimeTable' */

/* 死区时间查表输出死区时间 */
extern const volatile float32 CAL_MCF_DeltaPower_f32;/* Referenced by: '<S38>/Constant4' */
extern const volatile float32 CAL_MCF_DisChaisdDes_f32;
                        /* Referenced by: '<S47>/CAL_MCF_DisChargeisdDes_f32' */
extern const volatile float32 CAL_MCF_DisChaisqDes_f32;
                           /* Referenced by: '<S51>/CAL_MCF_DisChaisqDes_f32' */
extern const volatile float32 CAL_MCF_DownLimPIZeroCtl_f32;/* Referenced by:
                                                            * '<S95>/CAL_MCF_DownLimPIZeroCtl_f32'
                                                            * '<S96>/CAL_MCF_DownLimPIZeroCtl_f32'
                                                            */
extern const volatile float32 CAL_MCF_DownLimitIMotHeat_f32;/* Referenced by: '<S43>/Saturation2' */
extern const volatile float32 CAL_MCF_DownLimitPIMotHeat_f32;/* Referenced by: '<S43>/Saturation1' */
extern const volatile float32 CAL_MCF_DycUSet_f32;
                             /* Referenced by: '<S106>/CAL_McSfc_DycUSet_f32' */
extern const volatile float32 CAL_MCF_DycVSet_f32;
                             /* Referenced by: '<S106>/CAL_McSfc_DycVSet_f32' */
extern const volatile float32 CAL_MCF_DycWSet_f32;
                             /* Referenced by: '<S106>/CAL_McSfc_DycWSet_f32' */
extern const volatile float32 CAL_MCF_FixFreq_f32;
                               /* Referenced by: '<S119>/CAL_MCF_FixFreq_f32' */

/* 定频 */
extern const volatile boolean CAL_MCF_FlgUpdateDyc_b;
                         /* Referenced by: '<S106>/CAL_McSfc_FlgUpdateDyc_b ' */
extern const volatile boolean CAL_MCF_FlgUseClose_b;
                             /* Referenced by: '<S113>/CAL_MCF_FlgUseClose_b' */
extern const volatile boolean CAL_MCF_FlgUseDeadCpn_b;
                            /* Referenced by: '<S81>/CAL_MCF_FlgUseDeadCpn_b' */
extern const volatile boolean CAL_MCF_FlgUseEOL_b;
                               /* Referenced by: '<S107>/CAL_MCF_FlgUseEOL_b' */

/* 电感测试标志位 */
extern const volatile boolean CAL_MCF_FlgUseOpen_b;
                              /* Referenced by: '<S113>/CAL_MCF_FlgUseOpen_b' */
extern const volatile boolean CAL_MCF_FlgUseSatuEOL_b;
                           /* Referenced by: '<S109>/CAL_MCF_FlgUseSatuEOL_b' */
extern const volatile boolean CAL_MCF_FlgUseSetDyc_b;
                            /* Referenced by: '<S106>/CAL_MCF_FlgUpdateDyc_b' */
extern const volatile float32 CAL_MCF_FrqRmp_f32;/* Referenced by:
                                                  * '<S184>/CAL_MCF_FrqRmp_f32'
                                                  * '<S185>/CAL_MCF_FrqRmp_f32'
                                                  */

/* 载频Ramp值 */
extern const volatile float32 CAL_MCF_HalfFreq_f32;
                              /* Referenced by: '<S119>/CAL_MCF_HalfFreq_f32' */

/* 半频 */
extern const volatile float32 CAL_MCF_HarmIn1113ZRX_Spd_af32[23];/* Referenced by:
                                                                  * '<S89>/1-D Lookup Table'
                                                                  * '<S89>/1-D Lookup Table1'
                                                                  */
extern const volatile float32 CAL_MCF_HarmIn11ZRY_Is_af32[23];
                                   /* Referenced by: '<S89>/1-D Lookup Table' */
extern const volatile float32 CAL_MCF_HarmIn11ZRY_Thetam_af32[23];
                                  /* Referenced by: '<S89>/1-D Lookup Table1' */
extern const volatile float32 CAL_MCF_IrmsDesEOLX_af32[20];
                                   /* Referenced by: '<S111>/Isrms_udDes_Tab' */
extern const volatile float32 CAL_MCF_IsSet11ZR_f32;
                              /* Referenced by: '<S89>/CAL_MCF_IsSet11ZR_f32' */
extern const volatile float32 CAL_MCF_IsThetaSet11ZR_f32;
                         /* Referenced by: '<S89>/CAL_MCF_IsThetaSet11ZR_f32' */
extern const volatile float32 CAL_MCF_IsrmsDesEOL_f32;/* Referenced by:
                                                       * '<S109>/CAL_MCF_IsrmsDesEOL_f32'
                                                       * '<S111>/CAL_MCF_IsrmsDesEOL_f32'
                                                       */
extern const volatile float32 CAL_MCF_KiAlphaZeroCtl_f32;
                         /* Referenced by: '<S93>/CAL_MCF_KiAlphaZeroCtl_f32' */
extern const volatile float32 CAL_MCF_KiBetaZeroCtl_f32;
                          /* Referenced by: '<S94>/CAL_MCF_KiBetaZeroCtl_f32' */
extern const volatile float32 CAL_MCF_KiMotHeat_f32;/* Referenced by: '<S43>/Constant1' */
extern const volatile float32 CAL_MCF_KiUdEOL_f32;
                               /* Referenced by: '<S109>/CAL_MCF_KiUdEOL_f32' */
extern const volatile float32 CAL_MCF_KpAlphaZeroCtl_f32;
                         /* Referenced by: '<S93>/CAL_MCF_KpAlphaZeroCtl_f32' */
extern const volatile float32 CAL_MCF_KpBetaZeroCtl_f32;
                          /* Referenced by: '<S94>/CAL_MCF_KpBetaZeroCtl_f32' */
extern const volatile float32 CAL_MCF_KpMotHeat_f32;/* Referenced by: '<S43>/Constant3' */
extern const volatile float32 CAL_MCF_KpUdEOL_f32;
                               /* Referenced by: '<S109>/CAL_MCF_KpUdEOL_f32' */
extern const volatile uint8 CAL_MCF_Non_ActiveHeat_u8;/* Referenced by: '<S38>/Constant5' */
extern const volatile float32 CAL_MCF_OffsetInternal_f32;
                         /* Referenced by: '<S12>/CAL_MCF_OffsetInternal_f32' */
extern const volatile float32 CAL_MCF_OmbwFirstFltX_N_af32[10];/* Referenced by:
                                                                * '<S101>/LookupOmbw1'
                                                                * '<S103>/LookupOmbw1'
                                                                */
extern const volatile float32 CAL_MCF_OmbwFirstFltY_Ombw_af32[10];/* Referenced by:
                                                                   * '<S101>/LookupOmbw1'
                                                                   * '<S103>/LookupOmbw1'
                                                                   */
extern const volatile uint8 CAL_MCF_Part_ActiveHeat_u8;/* Referenced by: '<S38>/Constant' */
extern const volatile float32 CAL_MCF_SampleTime_f32;/* Referenced by:
                                                      * '<S101>/CAL_McPocSampleTime_f2'
                                                      * '<S102>/CAL_MCF_SampleTime_f32'
                                                      * '<S102>/CAL_McPocSampleTime_f1'
                                                      * '<S102>/CAL_McPocSampleTime_f3'
                                                      * '<S103>/CAL_McPocSampleTime_f2'
                                                      * '<S104>/CAL_MCF_SampleTime_f32'
                                                      * '<S104>/CAL_McPocSampleTime_f1'
                                                      * '<S104>/CAL_McPocSampleTime_f3'
                                                      */
extern const volatile float32 CAL_MCF_SpdActiveHeat_af32[9];
                                   /* Referenced by: '<S46>/1-D Lookup Table' */
extern const volatile float32 CAL_MCF_SpdOffActiveHeat_f32;
                       /* Referenced by: '<S46>/CAL_MCF_SpdOffActiveHeat_f32' */
extern const volatile float32 CAL_MCF_SpdOffDeadCpn_f32;
                          /* Referenced by: '<S82>/CAL_MCF_SpdOffDeadCpn_f32' */
extern const volatile float32 CAL_MCF_SpdOnDeadCpn_f32;
                           /* Referenced by: '<S82>/CAL_MCF_SpdOnDeadCpn_f32' */
extern const volatile float32 CAL_MCF_TrqInvMax_f32;
                             /* Referenced by: '<S112>/CAL_MCF_TrqInvMax_f32' */
extern const volatile float32 CAL_MCF_TrqOffActiveHeat_af32[9];
                                   /* Referenced by: '<S46>/1-D Lookup Table' */
extern const volatile float32 CAL_MCF_TrqOffDeadCpn_f32;
                          /* Referenced by: '<S80>/CAL_MCF_TrqOffDeadCpn_f32' */
extern const volatile float32 CAL_MCF_UpLimPIZeroCtl_f32;/* Referenced by:
                                                          * '<S95>/CAL_MCF_UpLimPIZeroCtl_f32'
                                                          * '<S96>/CAL_MCF_UpLimPIZeroCtl_f32'
                                                          */
extern const volatile float32 CAL_MCF_UpLimitIMotHeat_f32;/* Referenced by: '<S43>/Saturation2' */
extern const volatile float32 CAL_MCF_UpLimitPIMotHeat_f32;/* Referenced by: '<S43>/Saturation1' */
extern const volatile float32 CAL_MCF_UpPowerHeat_f32;/* Referenced by: '<S42>/Saturation' */
extern const volatile float32 CAL_MCF_UsUseRateDesTableX_Spd_af32[11];
                             /* Referenced by: '<S22>/Spd_UsUseRateDes_Table' */
extern const volatile float32 CAL_MCF_UsUseRateDesTableY_UsRes_af32[11];
                             /* Referenced by: '<S22>/Spd_UsUseRateDes_Table' */
extern const volatile float32 CAL_MCF_UsdScalSet_f32;
                             /* Referenced by: '<S25>/CAL_MCF_UsdScalSet_f32' */
extern const volatile float32 CAL_MCF_UsqScalSet_f32;
                             /* Referenced by: '<S25>/CAL_MCF_UsqScalSet_f32' */
extern const volatile boolean CAL_MCF_bUseduDclnkSet_b;
                           /* Referenced by: '<S13>/CAL_MCF_bUseduDclnkSet_b' */

/* 内外部电压来源切换 */
extern const volatile float32 CAL_MCF_cofFltN_f32;
                               /* Referenced by: '<S181>/CAL_MCF_cofFltN_f32' */

/* 转速滤波系数 */
extern const volatile float32 CAL_MCF_cofFltPowerHeat_f32;
                               /* Referenced by: '<S41>/CAL_MCF_cofFltWe_f32' */
extern const volatile float32 CAL_MCF_cofFltWe_f32;
                               /* Referenced by: '<S58>/CAL_MCF_cofFltWe_f32' */
extern const volatile float32 CAL_MCF_cofOverModu_f32;
                           /* Referenced by: '<S168>/CAL_MCF_cofOverModu_f32' */

/* 过调制系数 */
extern const volatile boolean CAL_MCF_flgCalibOffset_b;
                           /* Referenced by: '<S12>/CAL_MCF_flgCalibOffset_b' */
extern const volatile boolean CAL_MCF_flgDpwm_b;
                                 /* Referenced by: '<S122>/CAL_MCF_flgDpwm_b' */

/* DPWM功能使能标志位 */
extern const volatile boolean CAL_MCF_flgHarmInIsThetaTab11ZR_b;
                  /* Referenced by: '<S89>/CAL_MCF_flgHarmInIsThetaTab11ZR_b' */
extern const volatile boolean CAL_MCF_flgInternalOffset_b;
                        /* Referenced by: '<S12>/CAL_MCF_flgInternalOffset_b' */
extern const volatile boolean CAL_MCF_flgLowOrHvudcLnk_b;
                         /* Referenced by: '<S13>/CAL_MCF_flgLowOrHvudcLnk_b' */

/* 高压低压切换标志位 */
extern const volatile boolean CAL_MCF_flgMotHeat_b;/* Referenced by: '<S45>/Constant6' */
extern const volatile boolean CAL_MCF_flgNWS_b;
                                  /* Referenced by: '<S140>/CAL_MCF_flgNWS_b' */

/* 窄波抑制功能使能标志位 */
extern const volatile boolean CAL_MCF_flgOfsClbTest_b;
                           /* Referenced by: '<S180>/CAL_MCF_flgOfsClbTest_b' */

/* 使用自标定数值调试标志位 */
extern const volatile boolean CAL_MCF_flgOverModu_b;
                             /* Referenced by: '<S117>/CAL_MCF_flgOverModu_b' */

/* 过调制使能标志位 */
extern const volatile boolean CAL_MCF_flgRpwmFrqRandom_b;
                        /* Referenced by: '<S119>/CAL_MCF_flgRpwmFrqRandom_b' */

/* Rpwm随机频率标志位 */
extern const volatile boolean CAL_MCF_flgTabZeroCtl_b;/* Referenced by:
                                                       * '<S93>/CAL_MCF_flgTabZeroCtl_b'
                                                       * '<S94>/CAL_MCF_flgTabZeroCtl_b'
                                                       */
extern const volatile boolean CAL_MCF_flgUse1113ZR_b;
                             /* Referenced by: '<S61>/CAL_MCF_flgUse1113ZR_b' */
extern const volatile boolean CAL_MCF_flgUseFF_b;
                                 /* Referenced by: '<S32>/CAL_MCF_flgUseFF_b' */
extern const volatile boolean CAL_MCF_flgUseUsOver_b;
                             /* Referenced by: '<S56>/CAL_MCF_flgUseUsOver_b' */
extern const volatile boolean CAL_MCF_flgUseUsdqSet_b;
                            /* Referenced by: '<S25>/CAL_MCF_flgUseUsdqSet_b' */
extern const volatile boolean CAL_MCF_flgUseZeroCtl_b;
                            /* Referenced by: '<S62>/CAL_MCF_flgUseZeroCtl_b' */
extern const volatile boolean CAL_MCF_flgUseisTheta_b;/* Referenced by:
                                                       * '<S30>/CAL_MCF_flgUseisTheta_b'
                                                       * '<S31>/CAL_MCF_flgUseisTheta_b'
                                                       */
extern const volatile boolean CAL_MCF_flgUseisdqSet_b;/* Referenced by:
                                                       * '<S30>/CAL_MCF_flgUseisdqSet_b'
                                                       * '<S31>/CAL_MCF_flgUseisdqSet_b'
                                                       */
extern const volatile boolean CAL_MCF_flgVF_b;
                                   /* Referenced by: '<S119>/CAL_MCF_flgVF_b' */

/* 变频使能标志位 */
extern const volatile float32 CAL_MCF_iUCnvFac_f32;
                               /* Referenced by: '<S13>/CAL_CSP_iUCnvFac_f32' */

/* U相转换系数 */
extern const volatile float32 CAL_MCF_iVCnvFac_f32;
                               /* Referenced by: '<S13>/CAL_CSP_iVCnvFac_f32' */

/* V相转换系数 */
extern const volatile float32 CAL_MCF_iWCnvFac_f32;
                               /* Referenced by: '<S13>/CAL_MCF_iWCnvFac_f32' */

/* W相转换系数 */
extern const volatile float32 CAL_MCF_isMax_f32;
                                  /* Referenced by: '<S52>/CAL_MCF_isMax_f32' */
extern const volatile float32 CAL_MCF_isSet_f32;/* Referenced by:
                                                 * '<S50>/CAL_MCF_isSet_f32'
                                                 * '<S54>/CAL_MCF_isSet_f32'
                                                 */
extern const volatile float32 CAL_MCF_isThetaSet_f32;/* Referenced by:
                                                      * '<S50>/CAL_MCF_isThetaSet_f32'
                                                      * '<S54>/CAL_MCF_isThetaSet_f32'
                                                      */
extern const volatile float32 CAL_MCF_isdSet_f32;
                                 /* Referenced by: '<S49>/CAL_MCF_isdSet_f32' */
extern const volatile float32 CAL_MCF_isdfwKi_f32;
                                 /* Referenced by: '<S32>/CAL_MCF_isdfwKi_f1' */
extern const volatile float32 CAL_MCF_isdfwKp_f32;
                                 /* Referenced by: '<S32>/CAL_MCF_isdfwKp_f1' */
extern const volatile float32 CAL_MCF_isqSet_f32;
                                 /* Referenced by: '<S53>/CAL_MCF_isqSet_f32' */
extern const volatile float32 CAL_MCF_nDpwmOffDelay_f32;
                         /* Referenced by: '<S122>/CAL_MCF_nDpwmOffDelay_f32' */

/* DPWM功能关闭滞环条件(转速) */
extern const volatile float32 CAL_MCF_nDpwmOff_f32;
                              /* Referenced by: '<S122>/CAL_MCF_nDpwmOff_f32' */

/* DPWM功能关闭条件(转速) */
extern const volatile float32 CAL_MCF_perCpnAg_f32;
                              /* Referenced by: '<S177>/CAL_MCF_perCpnAg_f32' */

/* 角度补偿周期 */
extern const volatile float32 CAL_MCF_ratLo_f32;
                                 /* Referenced by: '<S126>/CAL_MCF_ratLo_f32' */

/* 占空比限制下限 */
extern const volatile float32 CAL_MCF_ratNarrWave_f32;
                           /* Referenced by: '<S140>/CAL_MCF_ratNarrWave_f32' */

/* 窄波低阈值 */
extern const volatile float32 CAL_MCF_ratUp_f32;
                                 /* Referenced by: '<S126>/CAL_MCF_ratUp_f32' */

/* 占空比限制上限 */
extern const volatile uint8 CAL_MCF_stChangePha_u8;/* Referenced by:
                                                    * '<S13>/CAL_MCF_stChangePha_u8'
                                                    * '<S126>/CAL_MCF_stChangePha_u8'
                                                    */

/* 换相标志位 */
extern const volatile uint8 CAL_MCF_stDpwm_u8;
                                 /* Referenced by: '<S130>/CAL_MCF_stDpwm_u8' */

/* DPWM调制方式选择 */
extern const volatile uint8 CAL_MCF_stPwmMode_u8;
                              /* Referenced by: '<S106>/CAL_MCF_stPwmMode_u8' */
extern const volatile float32 CAL_MCF_trqDpwmOff_f32;
                            /* Referenced by: '<S122>/CAL_MCF_trqDpwmOff_f32' */

/* DPWM功能关闭条件(扭矩) */
extern const volatile float32 CAL_MCF_uDDesEOLY_af32[20];
                                   /* Referenced by: '<S111>/Isrms_udDes_Tab' */
extern const volatile float32 CAL_MCF_uDDownLimEOL_f32;
                          /* Referenced by: '<S109>/CAL_MCF_uDDownLimEOL_f32' */
extern const volatile float32 CAL_MCF_uDUpLimEOL_f32;
                            /* Referenced by: '<S109>/CAL_MCF_uDUpLimEOL_f32' */
extern const volatile float32 CAL_MCF_uDclnkSet_f32;
                           /* Referenced by: '<S13>/CAL_MCF_uIntDclnkVol_f32' */

/* 内部母线电压设置 */
extern const volatile float32 CAL_MCF_uQDesEOL_f32;
                              /* Referenced by: '<S112>/CAL_MCF_uQDesEOL_f32' */
extern const volatile float32 CAL_MCF_udDecoupki_f32;
                             /* Referenced by: '<S57>/CAL_MCF_udDecoupki_f32' */
extern const volatile float32 CAL_MCF_udOverGain_f32;
                             /* Referenced by: '<S56>/CAL_MCF_udOverGain_f32' */
extern const volatile float32 CAL_MCF_udki_f32;
                                   /* Referenced by: '<S57>/CAL_MCF_udki_f32' */
extern const volatile float32 CAL_MCF_udkp_f32;
                                   /* Referenced by: '<S57>/CAL_MCF_udkp_f32' */
extern const volatile float32 CAL_MCF_uqDecoupki_f32;
                              /* Referenced by: '<S57>/CAL_MCF_uqDecoupki_f1' */
extern const volatile float32 CAL_MCF_uqOverGain_f32;
                             /* Referenced by: '<S56>/CAL_MCF_uqOverGain_f32' */
extern const volatile float32 CAL_MCF_uqki_f32;
                                    /* Referenced by: '<S57>/CAL_MCF_uqki_f1' */
extern const volatile float32 CAL_MCF_uqkp_f32;
                                    /* Referenced by: '<S57>/CAL_MCF_udki_f2' */
extern const volatile float32 CAL_PowerMotHeat_f32;/* Referenced by: '<S42>/Constant3' */
extern const volatile float32 CAL_cofPowerLimitMotHeat_af32[9];
                                   /* Referenced by: '<S42>/1-D Lookup Table' */
extern const volatile float32 CAL_tStrrTempFltMotHeat_af32[9];
                                   /* Referenced by: '<S42>/1-D Lookup Table' */

#pragma section

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S22>/Constant' : Unused code path elimination
 * Block '<S22>/Logical Operator' : Unused code path elimination
 * Block '<S36>/Data Type Duplicate' : Unused code path elimination
 * Block '<S36>/Data Type Propagation' : Unused code path elimination
 * Block '<S37>/Data Type Duplicate' : Unused code path elimination
 * Block '<S37>/Data Type Propagation' : Unused code path elimination
 * Block '<S34>/Add' : Unused code path elimination
 * Block '<S34>/Constant1' : Unused code path elimination
 * Block '<S99>/Data Type Duplicate' : Unused code path elimination
 * Block '<S99>/Data Type Propagation' : Unused code path elimination
 * Block '<S100>/Data Type Duplicate' : Unused code path elimination
 * Block '<S100>/Data Type Propagation' : Unused code path elimination
 * Block '<S114>/Data Type Duplicate' : Unused code path elimination
 * Block '<S114>/Data Type Propagation' : Unused code path elimination
 * Block '<S127>/Gain' : Eliminated nontunable gain of 1
 * Block '<S121>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S147>/Gain4' : Eliminated nontunable gain of 1
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
 * '<Root>' : 'SWC_MCF'
 * '<S1>'   : 'SWC_MCF/RE_SWC_MCF_100us_sys'
 * '<S2>'   : 'SWC_MCF/RE_SWC_MCF_Init'
 * '<S3>'   : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem'
 * '<S4>'   : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/MCF_Signal'
 * '<S5>'   : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McFwc'
 * '<S6>'   : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McPoc'
 * '<S7>'   : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McSfc'
 * '<S8>'   : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc'
 * '<S9>'   : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/MCF_Signal/MCF_Signal'
 * '<S10>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/MCF_Signal/MCF_Signal/Clark'
 * '<S11>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/MCF_Signal/MCF_Signal/IsCalc'
 * '<S12>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/MCF_Signal/MCF_Signal/OffsetCal'
 * '<S13>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/MCF_Signal/MCF_Signal/SigCnv'
 * '<S14>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/MCF_Signal/MCF_Signal/park'
 * '<S15>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/MCF_Signal/MCF_Signal/OffsetCal/Rem3'
 * '<S16>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/MCF_Signal/MCF_Signal/SigCnv/Model Info1'
 * '<S17>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McFwc/McFwc'
 * '<S18>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McFwc/McFwc/Conditional Judgment '
 * '<S19>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McFwc/McFwc/idqDes'
 * '<S20>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McFwc/McFwc/udqDes'
 * '<S21>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McFwc/McFwc/Conditional Judgment /FwcUsRes'
 * '<S22>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McFwc/McFwc/Conditional Judgment /FwcUsRes/GetFwFlag'
 * '<S23>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McFwc/McFwc/Conditional Judgment /FwcUsRes/GetUsResAct'
 * '<S24>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McFwc/McFwc/Conditional Judgment /FwcUsRes/UsMaxDivUsLimCalc'
 * '<S25>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McFwc/McFwc/Conditional Judgment /FwcUsRes/UsdqDesCalc'
 * '<S26>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McFwc/McFwc/Conditional Judgment /FwcUsRes/UsdqDesCalc/Compare To Zero'
 * '<S27>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McFwc/McFwc/idqDes/FluxWeakeningLoop'
 * '<S28>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McFwc/McFwc/idqDes/FluxWeakeningLoop/CalculateisqDes'
 * '<S29>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McFwc/McFwc/idqDes/FluxWeakeningLoop/GetisdDesFw'
 * '<S30>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McFwc/McFwc/idqDes/FluxWeakeningLoop/isdDesCoordinate1'
 * '<S31>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McFwc/McFwc/idqDes/FluxWeakeningLoop/isqDesCoordinate'
 * '<S32>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McFwc/McFwc/idqDes/FluxWeakeningLoop/GetisdDesFw/IncPI'
 * '<S33>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McFwc/McFwc/idqDes/FluxWeakeningLoop/GetisdDesFw/Subsystem'
 * '<S34>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McFwc/McFwc/idqDes/FluxWeakeningLoop/GetisdDesFw/Subsystem1'
 * '<S35>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McFwc/McFwc/idqDes/FluxWeakeningLoop/GetisdDesFw/Subsystem3'
 * '<S36>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McFwc/McFwc/idqDes/FluxWeakeningLoop/GetisdDesFw/IncPI/Dynamic1'
 * '<S37>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McFwc/McFwc/idqDes/FluxWeakeningLoop/GetisdDesFw/IncPI/Dynamic2'
 * '<S38>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McFwc/McFwc/idqDes/FluxWeakeningLoop/GetisdDesFw/Subsystem1/Subsystem'
 * '<S39>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McFwc/McFwc/idqDes/FluxWeakeningLoop/GetisdDesFw/Subsystem1/Subsystem4'
 * '<S40>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McFwc/McFwc/idqDes/FluxWeakeningLoop/GetisdDesFw/Subsystem1/Subsystem5'
 * '<S41>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McFwc/McFwc/idqDes/FluxWeakeningLoop/GetisdDesFw/Subsystem1/Subsystem/First_LowPass'
 * '<S42>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McFwc/McFwc/idqDes/FluxWeakeningLoop/GetisdDesFw/Subsystem1/Subsystem4/Subsystem1'
 * '<S43>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McFwc/McFwc/idqDes/FluxWeakeningLoop/GetisdDesFw/Subsystem1/Subsystem4/Subsystem2'
 * '<S44>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McFwc/McFwc/idqDes/FluxWeakeningLoop/GetisdDesFw/Subsystem1/Subsystem4/Subsystem3'
 * '<S45>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McFwc/McFwc/idqDes/FluxWeakeningLoop/GetisdDesFw/Subsystem1/Subsystem5/Subsystem'
 * '<S46>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McFwc/McFwc/idqDes/FluxWeakeningLoop/GetisdDesFw/Subsystem1/Subsystem5/Subsystem4'
 * '<S47>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McFwc/McFwc/idqDes/FluxWeakeningLoop/isdDesCoordinate1/Discharge_id'
 * '<S48>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McFwc/McFwc/idqDes/FluxWeakeningLoop/isdDesCoordinate1/id_Fw'
 * '<S49>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McFwc/McFwc/idqDes/FluxWeakeningLoop/isdDesCoordinate1/id_Set'
 * '<S50>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McFwc/McFwc/idqDes/FluxWeakeningLoop/isdDesCoordinate1/id_ThetaSet'
 * '<S51>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McFwc/McFwc/idqDes/FluxWeakeningLoop/isqDesCoordinate/Discharge_iq'
 * '<S52>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McFwc/McFwc/idqDes/FluxWeakeningLoop/isqDesCoordinate/iq_Cal'
 * '<S53>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McFwc/McFwc/idqDes/FluxWeakeningLoop/isqDesCoordinate/iq_Set'
 * '<S54>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McFwc/McFwc/idqDes/FluxWeakeningLoop/isqDesCoordinate/iq_ThetaSet'
 * '<S55>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McFwc/McFwc/udqDes/CurrentLoop'
 * '<S56>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McFwc/McFwc/udqDes/CurrentLoop/Subsystem'
 * '<S57>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McFwc/McFwc/udqDes/CurrentLoop/Subsystem1'
 * '<S58>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McFwc/McFwc/udqDes/CurrentLoop/Subsystem/First_LowPass'
 * '<S59>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McPoc/McPoc'
 * '<S60>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McPoc/McPoc/Calculat_ Dead_Compensation_Voltage'
 * '<S61>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McPoc/McPoc/Harmonic_Injection_Funcation'
 * '<S62>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McPoc/McPoc/Zero Sequence Control Function'
 * '<S63>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McPoc/McPoc/Calculat_ Dead_Compensation_Voltage/Calculate dead compensation voltage'
 * '<S64>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McPoc/McPoc/Calculat_ Dead_Compensation_Voltage/Determines dead compensation is enabled'
 * '<S65>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McPoc/McPoc/Calculat_ Dead_Compensation_Voltage/Calculate dead compensation voltage/Calculate coefficient alpha and beta axis'
 * '<S66>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McPoc/McPoc/Calculat_ Dead_Compensation_Voltage/Calculate dead compensation voltage/Calculate dead compensation voltage for alpha axis '
 * '<S67>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McPoc/McPoc/Calculat_ Dead_Compensation_Voltage/Calculate dead compensation voltage/Calculate dead compensation voltage for beta axis'
 * '<S68>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McPoc/McPoc/Calculat_ Dead_Compensation_Voltage/Calculate dead compensation voltage/Current angle calculate'
 * '<S69>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McPoc/McPoc/Calculat_ Dead_Compensation_Voltage/Calculate dead compensation voltage/Calculate coefficient alpha and beta axis/Chart'
 * '<S70>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McPoc/McPoc/Calculat_ Dead_Compensation_Voltage/Calculate dead compensation voltage/Calculate coefficient alpha and beta axis/Rem60'
 * '<S71>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McPoc/McPoc/Calculat_ Dead_Compensation_Voltage/Calculate dead compensation voltage/Calculate dead compensation voltage for alpha axis /Compare To Constant'
 * '<S72>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McPoc/McPoc/Calculat_ Dead_Compensation_Voltage/Calculate dead compensation voltage/Calculate dead compensation voltage for beta axis/Compare To Constant'
 * '<S73>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McPoc/McPoc/Calculat_ Dead_Compensation_Voltage/Calculate dead compensation voltage/Current angle calculate/Rem360'
 * '<S74>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McPoc/McPoc/Calculat_ Dead_Compensation_Voltage/Calculate dead compensation voltage/Current angle calculate/Subsystem1'
 * '<S75>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McPoc/McPoc/Calculat_ Dead_Compensation_Voltage/Calculate dead compensation voltage/Current angle calculate/Subsystem1/Compare To Constant'
 * '<S76>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McPoc/McPoc/Calculat_ Dead_Compensation_Voltage/Calculate dead compensation voltage/Current angle calculate/Subsystem1/Compare To Constant1'
 * '<S77>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McPoc/McPoc/Calculat_ Dead_Compensation_Voltage/Calculate dead compensation voltage/Current angle calculate/Subsystem1/Compare To Constant2'
 * '<S78>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McPoc/McPoc/Calculat_ Dead_Compensation_Voltage/Calculate dead compensation voltage/Current angle calculate/Subsystem1/Compare To Constant3'
 * '<S79>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McPoc/McPoc/Calculat_ Dead_Compensation_Voltage/Calculate dead compensation voltage/Current angle calculate/Subsystem1/Compare To Constant4'
 * '<S80>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McPoc/McPoc/Calculat_ Dead_Compensation_Voltage/Determines dead compensation is enabled/ Flag of dead compensation according to torque'
 * '<S81>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McPoc/McPoc/Calculat_ Dead_Compensation_Voltage/Determines dead compensation is enabled/Determines whether dead compensation is enabled'
 * '<S82>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McPoc/McPoc/Calculat_ Dead_Compensation_Voltage/Determines dead compensation is enabled/Flag of dead compensation according to speed'
 * '<S83>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McPoc/McPoc/Calculat_ Dead_Compensation_Voltage/Determines dead compensation is enabled/ Flag of dead compensation according to torque/Model Info'
 * '<S84>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McPoc/McPoc/Calculat_ Dead_Compensation_Voltage/Determines dead compensation is enabled/Determines whether dead compensation is enabled/Model Info'
 * '<S85>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McPoc/McPoc/Calculat_ Dead_Compensation_Voltage/Determines dead compensation is enabled/Flag of dead compensation according to speed/Model Info'
 * '<S86>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McPoc/McPoc/Harmonic_Injection_Funcation/Harmonic_injection_of_11_and_13'
 * '<S87>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McPoc/McPoc/Harmonic_Injection_Funcation/Harmonic_injection_of_11_and_13/Angle_transform_sine_and_cosine'
 * '<S88>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McPoc/McPoc/Harmonic_Injection_Funcation/Harmonic_injection_of_11_and_13/Reverse_the_park_transformation_11'
 * '<S89>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McPoc/McPoc/Harmonic_Injection_Funcation/Harmonic_injection_of_11_and_13/Set_11_steps_current_amplitude_and_phase'
 * '<S90>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McPoc/McPoc/Harmonic_Injection_Funcation/Harmonic_injection_of_11_and_13/The_voltage_equation 11'
 * '<S91>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McPoc/McPoc/Harmonic_Injection_Funcation/Harmonic_injection_of_11_and_13/Angle_transform_sine_and_cosine/Rem360'
 * '<S92>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McPoc/McPoc/Zero Sequence Control Function/Calculate zero sequence alpha and beta axis voltage'
 * '<S93>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McPoc/McPoc/Zero Sequence Control Function/Calculate zero sequence alpha and beta axis voltage/Calculate KpKi for uAlpha'
 * '<S94>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McPoc/McPoc/Zero Sequence Control Function/Calculate zero sequence alpha and beta axis voltage/Calculate KpKi for uBeta'
 * '<S95>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McPoc/McPoc/Zero Sequence Control Function/Calculate zero sequence alpha and beta axis voltage/Incremental PI'
 * '<S96>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McPoc/McPoc/Zero Sequence Control Function/Calculate zero sequence alpha and beta axis voltage/Incremental PI1'
 * '<S97>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McPoc/McPoc/Zero Sequence Control Function/Calculate zero sequence alpha and beta axis voltage/Signal Filter of current of alpha axis 1'
 * '<S98>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McPoc/McPoc/Zero Sequence Control Function/Calculate zero sequence alpha and beta axis voltage/Signal Filter of current of alpha axis 2'
 * '<S99>'  : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McPoc/McPoc/Zero Sequence Control Function/Calculate zero sequence alpha and beta axis voltage/Incremental PI/Saturation'
 * '<S100>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McPoc/McPoc/Zero Sequence Control Function/Calculate zero sequence alpha and beta axis voltage/Incremental PI1/Saturation'
 * '<S101>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McPoc/McPoc/Zero Sequence Control Function/Calculate zero sequence alpha and beta axis voltage/Signal Filter of current of alpha axis 1/First low pass'
 * '<S102>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McPoc/McPoc/Zero Sequence Control Function/Calculate zero sequence alpha and beta axis voltage/Signal Filter of current of alpha axis 1/Second band stop filter'
 * '<S103>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McPoc/McPoc/Zero Sequence Control Function/Calculate zero sequence alpha and beta axis voltage/Signal Filter of current of alpha axis 2/First low pass'
 * '<S104>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McPoc/McPoc/Zero Sequence Control Function/Calculate zero sequence alpha and beta axis voltage/Signal Filter of current of alpha axis 2/Second band stop filter'
 * '<S105>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McSfc/McSfc'
 * '<S106>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McSfc/McSfc/Calibration Duty Cycle'
 * '<S107>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McSfc/McSfc/EOL Function'
 * '<S108>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McSfc/McSfc/EOL Function/Inductancetestfunction'
 * '<S109>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McSfc/McSfc/EOL Function/Inductancetestfunction/Close Loop'
 * '<S110>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McSfc/McSfc/EOL Function/Inductancetestfunction/Enable initialize flag'
 * '<S111>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McSfc/McSfc/EOL Function/Inductancetestfunction/Open Loop'
 * '<S112>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McSfc/McSfc/EOL Function/Inductancetestfunction/Output UdDes of inductance'
 * '<S113>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McSfc/McSfc/EOL Function/Inductancetestfunction/Switch UdDes of inductance'
 * '<S114>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McSfc/McSfc/EOL Function/Inductancetestfunction/Close Loop/Saturation Dynamic'
 * '<S115>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc'
 * '<S116>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_DPWM'
 * '<S117>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_OverModu'
 * '<S118>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_RePark'
 * '<S119>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_frqpwmCalc'
 * '<S120>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_DPWM/MCF_DPWM'
 * '<S121>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_DPWM/MCF_DeadTimeCalc'
 * '<S122>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_DPWM/MCF_DpwmEn'
 * '<S123>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_DPWM/MCF_ModuSelec'
 * '<S124>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_DPWM/MCF_NarrWaSupr'
 * '<S125>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_DPWM/MCF_SVPWM'
 * '<S126>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_DPWM/MCF_dycCalc'
 * '<S127>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_DPWM/MCF_DPWM/DPWM_AntiClark'
 * '<S128>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_DPWM/MCF_DPWM/DPWM_ExtCalc'
 * '<S129>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_DPWM/MCF_DPWM/DPWM_ratCalc'
 * '<S130>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_DPWM/MCF_DPWM/DPWM_tiModu'
 * '<S131>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_DPWM/MCF_DPWM/DPWM_AntiClark/Model Info'
 * '<S132>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_DPWM/MCF_DPWM/DPWM_ExtCalc/Model Info'
 * '<S133>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_DPWM/MCF_DPWM/DPWM_ratCalc/Model Info'
 * '<S134>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_DPWM/MCF_DPWM/DPWM_tiModu/Model Info'
 * '<S135>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_DPWM/MCF_DeadTimeCalc/Model Info'
 * '<S136>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_DPWM/MCF_DpwmEn/Model Info'
 * '<S137>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_DPWM/MCF_ModuSelec/Model Info'
 * '<S138>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_DPWM/MCF_ModuSelec/ModuSele'
 * '<S139>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_DPWM/MCF_NarrWaSupr/NWS_OneVecNws'
 * '<S140>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_DPWM/MCF_NarrWaSupr/OSC_SwtCalc'
 * '<S141>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_DPWM/MCF_NarrWaSupr/NWS_OneVecNws/Model Info'
 * '<S142>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_DPWM/MCF_NarrWaSupr/OSC_SwtCalc/Chart'
 * '<S143>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_DPWM/MCF_NarrWaSupr/OSC_SwtCalc/Model Info'
 * '<S144>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_DPWM/MCF_SVPWM/Svpwm_OvModu'
 * '<S145>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_DPWM/MCF_SVPWM/Svpwm_TcmCalc'
 * '<S146>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_DPWM/MCF_SVPWM/Svpwm_cofDeadCpn'
 * '<S147>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_DPWM/MCF_SVPWM/Svpwm_stNCalc'
 * '<S148>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_DPWM/MCF_SVPWM/Svpwm_tiClac'
 * '<S149>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_DPWM/MCF_SVPWM/Svpwm_OvModu/Model Info'
 * '<S150>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_DPWM/MCF_SVPWM/Svpwm_OvModu/Svpwm_tiLim'
 * '<S151>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_DPWM/MCF_SVPWM/Svpwm_OvModu/Svpwm_tiOverLim'
 * '<S152>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_DPWM/MCF_SVPWM/Svpwm_TcmCalc/Model Info'
 * '<S153>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_DPWM/MCF_SVPWM/Svpwm_cofDeadCpn/Model Info'
 * '<S154>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_DPWM/MCF_SVPWM/Svpwm_stNCalc/Compare To Zero'
 * '<S155>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_DPWM/MCF_SVPWM/Svpwm_stNCalc/Compare To Zero1'
 * '<S156>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_DPWM/MCF_SVPWM/Svpwm_stNCalc/Compare To Zero2'
 * '<S157>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_DPWM/MCF_SVPWM/Svpwm_stNCalc/Model Info'
 * '<S158>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_DPWM/MCF_SVPWM/Svpwm_tiClac/Model Info'
 * '<S159>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_DPWM/MCF_SVPWM/Svpwm_tiClac/Osc_nrN1'
 * '<S160>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_DPWM/MCF_SVPWM/Svpwm_tiClac/Osc_nrN2'
 * '<S161>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_DPWM/MCF_SVPWM/Svpwm_tiClac/Osc_nrN3'
 * '<S162>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_DPWM/MCF_SVPWM/Svpwm_tiClac/Osc_nrN4'
 * '<S163>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_DPWM/MCF_SVPWM/Svpwm_tiClac/Osc_nrN5'
 * '<S164>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_DPWM/MCF_SVPWM/Svpwm_tiClac/Osc_nrN6'
 * '<S165>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_DPWM/MCF_SVPWM/Svpwm_tiClac/Osc_nrN7'
 * '<S166>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_DPWM/MCF_dycCalc/Model Info'
 * '<S167>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_DPWM/MCF_dycCalc/Model Info1'
 * '<S168>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_OverModu/MCF_OverModuEn'
 * '<S169>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_OverModu/MCF_OverModuEn/Model Info1'
 * '<S170>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_OverModu/MCF_OverModuEn/Rem60'
 * '<S171>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_OverModu/MCF_OverModuEn/Subsystem1'
 * '<S172>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_OverModu/MCF_OverModuEn/Subsystem1/Compare To Constant'
 * '<S173>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_OverModu/MCF_OverModuEn/Subsystem1/Compare To Constant1'
 * '<S174>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_OverModu/MCF_OverModuEn/Subsystem1/Compare To Constant2'
 * '<S175>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_OverModu/MCF_OverModuEn/Subsystem1/Compare To Constant3'
 * '<S176>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_OverModu/MCF_OverModuEn/Subsystem1/Compare To Constant4'
 * '<S177>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_RePark/Mcf_AgTranCalc'
 * '<S178>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_RePark/Mcf_HarmCpn'
 * '<S179>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_RePark/Mcf_RevPark'
 * '<S180>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_RePark/OSC_AlOfsClbCompen'
 * '<S181>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_RePark/Mcf_AgTranCalc/First_LowPass'
 * '<S182>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_RePark/Mcf_AgTranCalc/Model Info'
 * '<S183>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_frqpwmCalc/Chart'
 * '<S184>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_frqpwmCalc/FrqRamp'
 * '<S185>' : 'SWC_MCF/RE_SWC_MCF_100us_sys/Subsystem/McVmc/McVmc/MCF_frqpwmCalc/FrqRamp1'
 */
#endif                                 /* RTW_HEADER_SWC_MCF_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
