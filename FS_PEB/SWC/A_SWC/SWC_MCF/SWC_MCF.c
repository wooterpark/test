/*
 * File: SWC_MCF.c
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

#include "SWC_MCF.h"
#include "SWC_MCF_private.h"
#include "look1_iflf_binlcapw.h"
#include "look1_iflf_binlcpw.h"
#include "look1_iflf_binlxpw.h"
#include "look2_iflf_binlxpw.h"

/* Exported block signals */
float32 VAR_MCF_iU_f32;                /* '<S13>/Multiport Switch' */
float32 VAR_MCF_iV_f32;                /* '<S13>/Multiport Switch1' */
float32 VAR_MCF_iW_f32;                /* '<S13>/Multiport Switch2' */
float32 VAR_MCF_Is_f32;                /* '<S11>/Sqrt' */
float32 VAR_MCF_agOffset_f32;          /* '<S12>/Switch3' */
float32 VAR_MCF_agRtrEe_f32;           /* '<S15>/Switch' */
float32 VAR_MCF_uDcLnk_f32;            /* '<S13>/Switch4' */
float32 VAR_MCF_idAct_f32;             /* '<S14>/Add' */
float32 VAR_MCF_iqAct_f32;             /* '<S14>/Add1' */
float32 VAR_MCF_UsUseRateDes_f32;      /* '<S22>/Subtract' */
float32 VAR_MCF_udRv_f32;              /* '<S56>/Product5' */
float32 VAR_MCF_periodCalc_f32;        /* '<S32>/Add' */
float32 VAR_MCF_isdFW_f32;             /* '<S36>/Switch2' */
float32 VAR_MCF_idMotHeat_f32;         /* '<S34>/Switch' */
float32 VAR_MCF_idDes_f32;             /* '<S30>/Merge' */
float32 VAR_MCF_MPC_Ld_f32;            /* '<S55>/Add' */
float32 VAR_MCF_Rdc_nWoFlt_f32;        /* '<S55>/Add2' */
float32 VAR_MCF_MPC_Lq_f32;            /* '<S55>/Add1' */
float32 VAR_MCF_MPC_LdSubLq_f32;       /* '<S27>/Add2' */
float32 VAR_MCF_iqDes_f32;             /* '<S31>/Merge' */
float32 VAR_MCF_EmfBack_f32;           /* '<S56>/Product17' */
float32 VAR_MCF_uqRv_f32;              /* '<S56>/Product21' */
float32 VAR_MCF_udDes_f32;             /* '<S25>/Switch1' */
float32 VAR_MCF_uqDes_f32;             /* '<S25>/Switch4' */
float32 VAR_MCF_UsUseRateReal_f32;     /* '<S23>/Add' */
float32 VAR_MCF_uAlphaDeadCpn_f32;     /* '<S60>/Switch' */
float32 VAR_MCF_uBetaDeadCpn_f32;      /* '<S60>/Switch' */
float32 VAR_MCF_UdDes11ZR_f32;         /* '<S61>/Switch2' */
float32 VAR_MCF_UqDes11ZR_f32;         /* '<S61>/Switch2' */
float32 VAR_MCF_uAlphaZero_f32;        /* '<S62>/Switch' */
float32 VAR_MCF_uBetaZero_f32;         /* '<S62>/Switch' */
float32 VAR_MCF_uDDesEOL_f32;          /* '<S107>/Switch' */
float32 VAR_MCF_uQDesEOL_f32;          /* '<S107>/Switch' */
float32 VAR_MCF_uAOfsClb_f32;          /* '<S180>/Switch' */
float32 VAR_MCF_uBOfsClb_f32;          /* '<S180>/Switch1' */
float32 VAR_MCF_usPeak_f32;            /* '<S168>/Sqrt' */
float32 VAR_MCF_AgRem_f32;             /* '<S170>/Add3' */
float32 VAR_MCF_uAOm_f32;              /* '<S168>/Divide' */
float32 VAR_MCF_uBOm_f32;              /* '<S168>/Divide1' */
float32 VAR_MCF_iAlphaActFlt_f32;      /* '<S103>/Add' */
float32 VAR_MCF_iBetaActFlt_f32;       /* '<S101>/Add' */
float32 VAR_MCF_IsSet11ZR_f32;         /* '<S89>/1-D Lookup Table' */
float32 VAR_MCF_IsThetaSet11ZR_f32;    /* '<S89>/1-D Lookup Table1' */
float32 VAR_MCF_PCUHeaterPower_f32;    /* '<S42>/Product4' */
float32 VAR_MCF_PowerDcLnk_f32;        /* '<S42>/Product1' */
float32 VAR_MCF_PowerMech_f32;         /* '<S42>/Product3' */
float32 VAR_MCF_PowerMotHeat_f32;      /* '<S42>/Add' */
uint8 VAR_MCF_HSPF_stIphaOffCal_u8;    /* '<S9>/Add' */
uint8 VAR_MCF_TMAhtChsts_f32;          /* '<S38>/Switch' */
boolean VAR_MCF_flgFw_b;               /* '<S22>/Switch3' */
boolean VAR_MCF_flgMotHeat_b;          /* '<S45>/Logical Operator' */
boolean VAR_MCF_SCF_flgInitEn_b;       /* '<S55>/Logical Operator' */
boolean VAR_MCF_FlgDeadCpn_b;          /* '<S81>/Logical Operator' */
float32 GLB_MCF_DycU_f32;
float32 GLB_MCF_DycV_f32;
float32 GLB_MCF_DycW_f32;
float32 GLB_MCF_ialpha_f32;
float32 GLB_MCF_ibeta_f32;
float32 GLB_MCF_uA_f32;
float32 GLB_MCF_uB_f32;
/* Exported data definition */
#pragma section ".rodata.Calib_32"

/* Definition for custom storage class: iEDS_Parameter */
const volatile uint8 CAL_MCF_ActiveHeatInit_u8 = 0U;/* Referenced by: '<S38>/Constant3' */
const volatile uint8 CAL_MCF_ActiveHeatNormal_u8 = 3U;/* Referenced by: '<S38>/Constant2' */
const volatile float32 CAL_MCF_AgDiffCurrSec_f32 = 30.0F;
                          /* Referenced by: '<S65>/CAL_MCF_AgDiffCurrSec_f32' */
const volatile float32 CAL_MCF_AgRangeDeadCpnX_Trq_af32[7] = { 0.0F, 5.0F, 10.0F,
  30.0F, 50.0F, 100.0F, 310.0F } ;
                   /* Referenced by: '<S65>/Angle range of dead compensation' */

const volatile float32 CAL_MCF_AgRangeDeadCpnY_Ag_af32[7] = { 25.0F, 25.0F,
  10.0F, 5.0F, 5.0F, 5.0F, 5.0F } ;
                   /* Referenced by: '<S65>/Angle range of dead compensation' */

const volatile float32 CAL_MCF_AplhaRefZeroCtl_f32 = 0.0F;
                      /* Referenced by: '<S95>/CAL_McPoc_ZeroCtlAplhaRef_f32' */
const volatile float32 CAL_MCF_BetaRefZeroCtl_f32 = 0.0F;
                         /* Referenced by: '<S96>/CAL_MCF_BetaRefZeroCtl_f32' */
const volatile float32 CAL_MCF_CoefFltZero_A_f32 = 1.0F;/* Referenced by:
                                                         * '<S102>/CAL_MCF_CoefFltZero_A_f32'
                                                         * '<S104>/CAL_MCF_CoefFltZero_A_f32'
                                                         */
const volatile float32 CAL_MCF_CoefFltZero_B_f32 = 1.0F;/* Referenced by:
                                                         * '<S102>/CAL_MCF_CoefFltZero_B_f32'
                                                         * '<S104>/CAL_MCF_CoefFltZero_B_f32'
                                                         */
const volatile float32 CAL_MCF_CoefFltZero_C_f32 = 1.0F;/* Referenced by:
                                                         * '<S102>/CAL_MCF_CoefFltZero_C_f32'
                                                         * '<S104>/CAL_MCF_CoefFltZero_C_f32'
                                                         */
const volatile float32 CAL_MCF_CoefPIAlphaZeroCtlY_Ki_af32[10] = { 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F } ;
                                     /* Referenced by: '<S93>/MC_ZeroAlphaKp' */

const volatile float32 CAL_MCF_CoefPIAlphaZeroFtlY_Kp_af32[10] = { 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F } ;
                                     /* Referenced by: '<S93>/MC_ZeroAlphaKi' */

const volatile float32 CAL_MCF_CoefPIBetaZeroCtlY_Ki_af32[10] = { 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F } ;
                                     /* Referenced by: '<S94>/MC_ZeroAlphaKp' */

const volatile float32 CAL_MCF_CoefPIBetaZeroCtlY_Kp_af32[10] = { 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F } ;
                                     /* Referenced by: '<S94>/MC_ZeroAlphaKi' */

const volatile float32 CAL_MCF_CoefPIZoreCtlX_N_af32[10] = { 0.0F, 1000.0F,
  3000.0F, 5000.0F, 7000.0F, 9000.0F, 11000.0F, 13000.0F, 15000.0F, 16000.0F } ;/* Referenced by:
                                                                      * '<S93>/MC_ZeroAlphaKi'
                                                                      * '<S93>/MC_ZeroAlphaKp'
                                                                      * '<S94>/MC_ZeroAlphaKi'
                                                                      * '<S94>/MC_ZeroAlphaKp'
                                                                      */

const volatile float32 CAL_MCF_CoefuDCLimtEOL_f32 = 0.5F;
                        /* Referenced by: '<S112>/CAL_MCF_CoefuDCLimtEOL_f32' */
const volatile float32 CAL_MCF_DeadTimeCpn_f32 = 1.5F;
                            /* Referenced by: '<S65>/CAL_MCF_DeadTimeCpn_f32' */
const volatile float32 CAL_MCF_DeadTimeTableX_Frq_af32[15] = { 1000.0F, 2000.0F,
  3000.0F, 4000.0F, 5000.0F, 6000.0F, 7000.0F, 8000.0F, 9000.0F, 10000.0F,
  11000.0F, 12000.0F, 13000.0F, 14000.0F, 15000.0F } ;
                                     /* Referenced by: '<S121>/DeadTimeTable' */

/* 死区时间查表输入载频 */
const volatile float32 CAL_MCF_DeadTimeTableY_Ti_af32[15] = { 2.4F, 2.4F, 2.4F,
  2.4F, 2.4F, 2.4F, 2.4F, 2.4F, 2.4F, 2.4F, 2.4F, 2.4F, 2.4F, 2.4F, 2.4F } ;
                                     /* Referenced by: '<S121>/DeadTimeTable' */

/* 死区时间查表输出死区时间 */
const volatile float32 CAL_MCF_DeltaPower_f32 = 2.0F;/* Referenced by: '<S38>/Constant4' */
const volatile float32 CAL_MCF_DisChaisdDes_f32 = -50.0F;
                        /* Referenced by: '<S47>/CAL_MCF_DisChargeisdDes_f32' */
const volatile float32 CAL_MCF_DisChaisqDes_f32 = 0.0F;
                           /* Referenced by: '<S51>/CAL_MCF_DisChaisqDes_f32' */
const volatile float32 CAL_MCF_DownLimPIZeroCtl_f32 = -5.0F;/* Referenced by:
                                                             * '<S95>/CAL_MCF_DownLimPIZeroCtl_f32'
                                                             * '<S96>/CAL_MCF_DownLimPIZeroCtl_f32'
                                                             */
const volatile float32 CAL_MCF_DownLimitIMotHeat_f32 = -500.0F;/* Referenced by: '<S43>/Saturation2' */
const volatile float32 CAL_MCF_DownLimitPIMotHeat_f32 = -500.0F;/* Referenced by: '<S43>/Saturation1' */
const volatile float32 CAL_MCF_DycUSet_f32 = 0.5F;
                             /* Referenced by: '<S106>/CAL_McSfc_DycUSet_f32' */
const volatile float32 CAL_MCF_DycVSet_f32 = 0.5F;
                             /* Referenced by: '<S106>/CAL_McSfc_DycVSet_f32' */
const volatile float32 CAL_MCF_DycWSet_f32 = 0.5F;
                             /* Referenced by: '<S106>/CAL_McSfc_DycWSet_f32' */
const volatile float32 CAL_MCF_FixFreq_f32 = 10000.0F;
                               /* Referenced by: '<S119>/CAL_MCF_FixFreq_f32' */

/* 定频 */
const volatile boolean CAL_MCF_FlgUpdateDyc_b = 0;
                         /* Referenced by: '<S106>/CAL_McSfc_FlgUpdateDyc_b ' */
const volatile boolean CAL_MCF_FlgUseClose_b = 0;
                             /* Referenced by: '<S113>/CAL_MCF_FlgUseClose_b' */
const volatile boolean CAL_MCF_FlgUseDeadCpn_b = 0;
                            /* Referenced by: '<S81>/CAL_MCF_FlgUseDeadCpn_b' */
const volatile boolean CAL_MCF_FlgUseEOL_b = 0;
                               /* Referenced by: '<S107>/CAL_MCF_FlgUseEOL_b' */

/* 电感测试标志位 */
const volatile boolean CAL_MCF_FlgUseOpen_b = 0;
                              /* Referenced by: '<S113>/CAL_MCF_FlgUseOpen_b' */
const volatile boolean CAL_MCF_FlgUseSatuEOL_b = 0;
                           /* Referenced by: '<S109>/CAL_MCF_FlgUseSatuEOL_b' */
const volatile boolean CAL_MCF_FlgUseSetDyc_b = 0;
                            /* Referenced by: '<S106>/CAL_MCF_FlgUpdateDyc_b' */
const volatile float32 CAL_MCF_FrqRmp_f32 = 500.0F;/* Referenced by:
                                                    * '<S184>/CAL_MCF_FrqRmp_f32'
                                                    * '<S185>/CAL_MCF_FrqRmp_f32'
                                                    */

/* 载频Ramp值 */
const volatile float32 CAL_MCF_HalfFreq_f32 = 5000.0F;
                              /* Referenced by: '<S119>/CAL_MCF_HalfFreq_f32' */

/* 半频 */
const volatile float32 CAL_MCF_HarmIn1113ZRX_Spd_af32[23] = { 0.0F, 500.0F,
  1000.0F, 1500.0F, 2000.0F, 2500.0F, 3000.0F, 3500.0F, 4000.0F, 4500.0F,
  5000.0F, 5500.0F, 6000.0F, 7000.0F, 8000.0F, 9000.0F, 10000.0F, 11000.0F,
  12000.0F, 13000.0F, 14000.0F, 15000.0F, 16000.0F } ;/* Referenced by:
                                                       * '<S89>/1-D Lookup Table'
                                                       * '<S89>/1-D Lookup Table1'
                                                       */

const volatile float32 CAL_MCF_HarmIn11ZRY_Is_af32[23] = { 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F } ;
                                   /* Referenced by: '<S89>/1-D Lookup Table' */

const volatile float32 CAL_MCF_HarmIn11ZRY_Thetam_af32[23] = { 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F } ;
                                  /* Referenced by: '<S89>/1-D Lookup Table1' */

const volatile float32 CAL_MCF_IrmsDesEOLX_af32[20] = { 0.0F, 7.0F, 24.0F, 44.0F,
  64.0F, 82.0F, 100.0F, 118.0F, 135.0F, 152.0F, 169.0F, 187.0F, 199.0F, 200.0F,
  220.0F, 240.0F, 260.0F, 280.0F, 300.0F, 320.0F } ;
                                   /* Referenced by: '<S111>/Isrms_udDes_Tab' */

const volatile float32 CAL_MCF_IsSet11ZR_f32 = 0.0F;
                              /* Referenced by: '<S89>/CAL_MCF_IsSet11ZR_f32' */
const volatile float32 CAL_MCF_IsThetaSet11ZR_f32 = 0.0F;
                         /* Referenced by: '<S89>/CAL_MCF_IsThetaSet11ZR_f32' */
const volatile float32 CAL_MCF_IsrmsDesEOL_f32 = 0.0F;/* Referenced by:
                                                       * '<S109>/CAL_MCF_IsrmsDesEOL_f32'
                                                       * '<S111>/CAL_MCF_IsrmsDesEOL_f32'
                                                       */
const volatile float32 CAL_MCF_KiAlphaZeroCtl_f32 = 0.0F;
                         /* Referenced by: '<S93>/CAL_MCF_KiAlphaZeroCtl_f32' */
const volatile float32 CAL_MCF_KiBetaZeroCtl_f32 = 0.0F;
                          /* Referenced by: '<S94>/CAL_MCF_KiBetaZeroCtl_f32' */
const volatile float32 CAL_MCF_KiMotHeat_f32 = 0.008F;/* Referenced by: '<S43>/Constant1' */
const volatile float32 CAL_MCF_KiUdEOL_f32 = 0.0F;
                               /* Referenced by: '<S109>/CAL_MCF_KiUdEOL_f32' */
const volatile float32 CAL_MCF_KpAlphaZeroCtl_f32 = 0.0F;
                         /* Referenced by: '<S93>/CAL_MCF_KpAlphaZeroCtl_f32' */
const volatile float32 CAL_MCF_KpBetaZeroCtl_f32 = 0.0F;
                          /* Referenced by: '<S94>/CAL_MCF_KpBetaZeroCtl_f32' */
const volatile float32 CAL_MCF_KpMotHeat_f32 = 0.05F;/* Referenced by: '<S43>/Constant3' */
const volatile float32 CAL_MCF_KpUdEOL_f32 = 0.0F;
                               /* Referenced by: '<S109>/CAL_MCF_KpUdEOL_f32' */
const volatile uint8 CAL_MCF_Non_ActiveHeat_u8 = 2U;/* Referenced by: '<S38>/Constant5' */
const volatile float32 CAL_MCF_OffsetInternal_f32 = 0.0F;
                         /* Referenced by: '<S12>/CAL_MCF_OffsetInternal_f32' */
const volatile float32 CAL_MCF_OmbwFirstFltX_N_af32[10] = { 0.0F, 1000.0F,
  3000.0F, 5000.0F, 7000.0F, 9000.0F, 11000.0F, 13000.0F, 15000.0F, 16000.0F } ;/* Referenced by:
                                                                      * '<S101>/LookupOmbw1'
                                                                      * '<S103>/LookupOmbw1'
                                                                      */

const volatile float32 CAL_MCF_OmbwFirstFltY_Ombw_af32[10] = { 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F } ;/* Referenced by:
                                               * '<S101>/LookupOmbw1'
                                               * '<S103>/LookupOmbw1'
                                               */

const volatile uint8 CAL_MCF_Part_ActiveHeat_u8 = 1U;/* Referenced by: '<S38>/Constant' */
const volatile float32 CAL_MCF_SampleTime_f32 = 0.0001F;/* Referenced by:
                                                         * '<S101>/CAL_McPocSampleTime_f2'
                                                         * '<S102>/CAL_MCF_SampleTime_f32'
                                                         * '<S102>/CAL_McPocSampleTime_f1'
                                                         * '<S102>/CAL_McPocSampleTime_f3'
                                                         * '<S103>/CAL_McPocSampleTime_f2'
                                                         * '<S104>/CAL_MCF_SampleTime_f32'
                                                         * '<S104>/CAL_McPocSampleTime_f1'
                                                         * '<S104>/CAL_McPocSampleTime_f3'
                                                         */
const volatile float32 CAL_MCF_SpdActiveHeat_af32[9] = { 1000.0F, 2000.0F,
  3000.0F, 4000.0F, 5000.0F, 6000.0F, 7000.0F, 8000.0F, 9000.0F } ;
                                   /* Referenced by: '<S46>/1-D Lookup Table' */

const volatile float32 CAL_MCF_SpdOffActiveHeat_f32 = 8000.0F;
                       /* Referenced by: '<S46>/CAL_MCF_SpdOffActiveHeat_f32' */
const volatile float32 CAL_MCF_SpdOffDeadCpn_f32 = 1000.0F;
                          /* Referenced by: '<S82>/CAL_MCF_SpdOffDeadCpn_f32' */
const volatile float32 CAL_MCF_SpdOnDeadCpn_f32 = 950.0F;
                           /* Referenced by: '<S82>/CAL_MCF_SpdOnDeadCpn_f32' */
const volatile float32 CAL_MCF_TrqInvMax_f32 = 315.0F;
                             /* Referenced by: '<S112>/CAL_MCF_TrqInvMax_f32' */
const volatile float32 CAL_MCF_TrqOffActiveHeat_af32[9] = { 150.0F, 150.0F,
  150.0F, 150.0F, 150.0F, 200.0F, 200.0F, 200.0F, 200.0F } ;
                                   /* Referenced by: '<S46>/1-D Lookup Table' */

const volatile float32 CAL_MCF_TrqOffDeadCpn_f32 = 100.0F;
                          /* Referenced by: '<S80>/CAL_MCF_TrqOffDeadCpn_f32' */
const volatile float32 CAL_MCF_UpLimPIZeroCtl_f32 = 5.0F;/* Referenced by:
                                                          * '<S95>/CAL_MCF_UpLimPIZeroCtl_f32'
                                                          * '<S96>/CAL_MCF_UpLimPIZeroCtl_f32'
                                                          */
const volatile float32 CAL_MCF_UpLimitIMotHeat_f32 = 500.0F;/* Referenced by: '<S43>/Saturation2' */
const volatile float32 CAL_MCF_UpLimitPIMotHeat_f32 = 0.0F;/* Referenced by: '<S43>/Saturation1' */
const volatile float32 CAL_MCF_UpPowerHeat_f32 = 3.0F;/* Referenced by: '<S42>/Saturation' */
const volatile float32 CAL_MCF_UsUseRateDesTableX_Spd_af32[11] = { 0.0F, 1000.0F,
  2000.0F, 2500.0F, 3000.0F, 4000.0F, 6000.0F, 8000.0F, 12000.0F, 14000.0F,
  16000.0F } ;               /* Referenced by: '<S22>/Spd_UsUseRateDes_Table' */

const volatile float32 CAL_MCF_UsUseRateDesTableY_UsRes_af32[11] = { 0.893F,
  0.893F, 0.893F, 0.893F, 0.893F, 0.893F, 0.893F, 0.893F, 0.893F, 0.893F, 0.893F
} ;                          /* Referenced by: '<S22>/Spd_UsUseRateDes_Table' */

const volatile float32 CAL_MCF_UsdScalSet_f32 = 0.0F;
                             /* Referenced by: '<S25>/CAL_MCF_UsdScalSet_f32' */
const volatile float32 CAL_MCF_UsqScalSet_f32 = 0.0F;
                             /* Referenced by: '<S25>/CAL_MCF_UsqScalSet_f32' */
const volatile boolean CAL_MCF_bUseduDclnkSet_b = 0;
                           /* Referenced by: '<S13>/CAL_MCF_bUseduDclnkSet_b' */

/* 内外部电压来源切换 */
const volatile float32 CAL_MCF_cofFltN_f32 = 0.01F;
                               /* Referenced by: '<S181>/CAL_MCF_cofFltN_f32' */

/* 转速滤波系数 */
const volatile float32 CAL_MCF_cofFltPowerHeat_f32 = 0.01F;
                               /* Referenced by: '<S41>/CAL_MCF_cofFltWe_f32' */
const volatile float32 CAL_MCF_cofFltWe_f32 = 0.01F;
                               /* Referenced by: '<S58>/CAL_MCF_cofFltWe_f32' */
const volatile float32 CAL_MCF_cofOverModu_f32 = 1.0F;
                           /* Referenced by: '<S168>/CAL_MCF_cofOverModu_f32' */

/* 过调制系数 */
const volatile boolean CAL_MCF_flgCalibOffset_b = 1;
                           /* Referenced by: '<S12>/CAL_MCF_flgCalibOffset_b' */
const volatile boolean CAL_MCF_flgDpwm_b = 0;
                                 /* Referenced by: '<S122>/CAL_MCF_flgDpwm_b' */

/* DPWM功能使能标志位 */
const volatile boolean CAL_MCF_flgHarmInIsThetaTab11ZR_b = 0;
                  /* Referenced by: '<S89>/CAL_MCF_flgHarmInIsThetaTab11ZR_b' */
const volatile boolean CAL_MCF_flgInternalOffset_b = 1;
                        /* Referenced by: '<S12>/CAL_MCF_flgInternalOffset_b' */
const volatile boolean CAL_MCF_flgLowOrHvudcLnk_b = 1;
                         /* Referenced by: '<S13>/CAL_MCF_flgLowOrHvudcLnk_b' */

/* 高压低压切换标志位 */
const volatile boolean CAL_MCF_flgMotHeat_b = 0;/* Referenced by: '<S45>/Constant6' */
const volatile boolean CAL_MCF_flgNWS_b = 1;
                                  /* Referenced by: '<S140>/CAL_MCF_flgNWS_b' */

/* 窄波抑制功能使能标志位 */
const volatile boolean CAL_MCF_flgOfsClbTest_b = 1;
                           /* Referenced by: '<S180>/CAL_MCF_flgOfsClbTest_b' */

/* 使用自标定数值调试标志位 */
const volatile boolean CAL_MCF_flgOverModu_b = 1;
                             /* Referenced by: '<S117>/CAL_MCF_flgOverModu_b' */

/* 过调制使能标志位 */
const volatile boolean CAL_MCF_flgRpwmFrqRandom_b = 0;
                        /* Referenced by: '<S119>/CAL_MCF_flgRpwmFrqRandom_b' */

/* Rpwm随机频率标志位 */
const volatile boolean CAL_MCF_flgTabZeroCtl_b = 0;/* Referenced by:
                                                    * '<S93>/CAL_MCF_flgTabZeroCtl_b'
                                                    * '<S94>/CAL_MCF_flgTabZeroCtl_b'
                                                    */
const volatile boolean CAL_MCF_flgUse1113ZR_b = 0;
                             /* Referenced by: '<S61>/CAL_MCF_flgUse1113ZR_b' */
const volatile boolean CAL_MCF_flgUseFF_b = 0;
                                 /* Referenced by: '<S32>/CAL_MCF_flgUseFF_b' */
const volatile boolean CAL_MCF_flgUseUsOver_b = 1;
                             /* Referenced by: '<S56>/CAL_MCF_flgUseUsOver_b' */
const volatile boolean CAL_MCF_flgUseUsdqSet_b = 0;
                            /* Referenced by: '<S25>/CAL_MCF_flgUseUsdqSet_b' */
const volatile boolean CAL_MCF_flgUseZeroCtl_b = 0;
                            /* Referenced by: '<S62>/CAL_MCF_flgUseZeroCtl_b' */
const volatile boolean CAL_MCF_flgUseisTheta_b = 0;/* Referenced by:
                                                    * '<S30>/CAL_MCF_flgUseisTheta_b'
                                                    * '<S31>/CAL_MCF_flgUseisTheta_b'
                                                    */
const volatile boolean CAL_MCF_flgUseisdqSet_b = 0;/* Referenced by:
                                                    * '<S30>/CAL_MCF_flgUseisdqSet_b'
                                                    * '<S31>/CAL_MCF_flgUseisdqSet_b'
                                                    */
const volatile boolean CAL_MCF_flgVF_b = 0;
                                   /* Referenced by: '<S119>/CAL_MCF_flgVF_b' */

/* 变频使能标志位 */
const volatile float32 CAL_MCF_iUCnvFac_f32 = 0.478F;
                               /* Referenced by: '<S13>/CAL_CSP_iUCnvFac_f32' */

/* U相转换系数 */
const volatile float32 CAL_MCF_iVCnvFac_f32 = 0.478F;
                               /* Referenced by: '<S13>/CAL_CSP_iVCnvFac_f32' */

/* V相转换系数 */
const volatile float32 CAL_MCF_iWCnvFac_f32 = 0.478F;
                               /* Referenced by: '<S13>/CAL_MCF_iWCnvFac_f32' */

/* W相转换系数 */
const volatile float32 CAL_MCF_isMax_f32 = 730.0F;
                                  /* Referenced by: '<S52>/CAL_MCF_isMax_f32' */
const volatile float32 CAL_MCF_isSet_f32 = 0.0F;/* Referenced by:
                                                 * '<S50>/CAL_MCF_isSet_f32'
                                                 * '<S54>/CAL_MCF_isSet_f32'
                                                 */
const volatile float32 CAL_MCF_isThetaSet_f32 = 0.0F;/* Referenced by:
                                                      * '<S50>/CAL_MCF_isThetaSet_f32'
                                                      * '<S54>/CAL_MCF_isThetaSet_f32'
                                                      */
const volatile float32 CAL_MCF_isdSet_f32 = 0.0F;
                                 /* Referenced by: '<S49>/CAL_MCF_isdSet_f32' */
const volatile float32 CAL_MCF_isdfwKi_f32 = 10.0F;
                                 /* Referenced by: '<S32>/CAL_MCF_isdfwKi_f1' */
const volatile float32 CAL_MCF_isdfwKp_f32 = 10.0F;
                                 /* Referenced by: '<S32>/CAL_MCF_isdfwKp_f1' */
const volatile float32 CAL_MCF_isqSet_f32 = 0.0F;
                                 /* Referenced by: '<S53>/CAL_MCF_isqSet_f32' */
const volatile float32 CAL_MCF_nDpwmOffDelay_f32 = 5950.0F;
                         /* Referenced by: '<S122>/CAL_MCF_nDpwmOffDelay_f32' */

/* DPWM功能关闭滞环条件(转速) */
const volatile float32 CAL_MCF_nDpwmOff_f32 = 6000.0F;
                              /* Referenced by: '<S122>/CAL_MCF_nDpwmOff_f32' */

/* DPWM功能关闭条件(转速) */
const volatile float32 CAL_MCF_perCpnAg_f32 = 1.5F;
                              /* Referenced by: '<S177>/CAL_MCF_perCpnAg_f32' */

/* 角度补偿周期 */
const volatile float32 CAL_MCF_ratLo_f32 = 0.0F;
                                 /* Referenced by: '<S126>/CAL_MCF_ratLo_f32' */

/* 占空比限制下限 */
const volatile float32 CAL_MCF_ratNarrWave_f32 = 5.4F;
                           /* Referenced by: '<S140>/CAL_MCF_ratNarrWave_f32' */

/* 窄波低阈值 */
const volatile float32 CAL_MCF_ratUp_f32 = 1.0F;
                                 /* Referenced by: '<S126>/CAL_MCF_ratUp_f32' */

/* 占空比限制上限 */
const volatile uint8 CAL_MCF_stChangePha_u8 = 1U;/* Referenced by:
                                                  * '<S13>/CAL_MCF_stChangePha_u8'
                                                  * '<S126>/CAL_MCF_stChangePha_u8'
                                                  */

/* 换相标志位 */
const volatile uint8 CAL_MCF_stDpwm_u8 = 4U;
                                 /* Referenced by: '<S130>/CAL_MCF_stDpwm_u8' */

/* DPWM调制方式选择 */
const volatile uint8 CAL_MCF_stPwmMode_u8 = 0U;
                              /* Referenced by: '<S106>/CAL_MCF_stPwmMode_u8' */
const volatile float32 CAL_MCF_trqDpwmOff_f32 = 100.0F;
                            /* Referenced by: '<S122>/CAL_MCF_trqDpwmOff_f32' */

/* DPWM功能关闭条件(扭矩) */
const volatile float32 CAL_MCF_uDDesEOLY_af32[20] = { 0.0F, 10.0F, 20.0F, 30.0F,
  40.0F, 50.0F, 60.0F, 70.0F, 80.0F, 90.0F, 100.0F, 110.0F, 117.0F, 118.0F,
  118.0F, 118.0F, 118.0F, 118.0F, 118.0F, 118.0F } ;
                                   /* Referenced by: '<S111>/Isrms_udDes_Tab' */

const volatile float32 CAL_MCF_uDDownLimEOL_f32 = 0.0F;
                          /* Referenced by: '<S109>/CAL_MCF_uDDownLimEOL_f32' */
const volatile float32 CAL_MCF_uDUpLimEOL_f32 = 100.0F;
                            /* Referenced by: '<S109>/CAL_MCF_uDUpLimEOL_f32' */
const volatile float32 CAL_MCF_uDclnkSet_f32 = 0.0F;
                           /* Referenced by: '<S13>/CAL_MCF_uIntDclnkVol_f32' */

/* 内部母线电压设置 */
const volatile float32 CAL_MCF_uQDesEOL_f32 = 0.0F;
                              /* Referenced by: '<S112>/CAL_MCF_uQDesEOL_f32' */
const volatile float32 CAL_MCF_udDecoupki_f32 = 1.0F;
                             /* Referenced by: '<S57>/CAL_MCF_udDecoupki_f32' */
const volatile float32 CAL_MCF_udOverGain_f32 = 1.01F;
                             /* Referenced by: '<S56>/CAL_MCF_udOverGain_f32' */
const volatile float32 CAL_MCF_udki_f32 = 1.0F;
                                   /* Referenced by: '<S57>/CAL_MCF_udki_f32' */
const volatile float32 CAL_MCF_udkp_f32 = 1.0F;
                                   /* Referenced by: '<S57>/CAL_MCF_udkp_f32' */
const volatile float32 CAL_MCF_uqDecoupki_f32 = 1.0F;
                              /* Referenced by: '<S57>/CAL_MCF_uqDecoupki_f1' */
const volatile float32 CAL_MCF_uqOverGain_f32 = 1.01F;
                             /* Referenced by: '<S56>/CAL_MCF_uqOverGain_f32' */
const volatile float32 CAL_MCF_uqki_f32 = 1.0F;
                                    /* Referenced by: '<S57>/CAL_MCF_uqki_f1' */
const volatile float32 CAL_MCF_uqkp_f32 = 1.0F;
                                    /* Referenced by: '<S57>/CAL_MCF_udki_f2' */
const volatile float32 CAL_PowerMotHeat_f32 = 0.0F;/* Referenced by: '<S42>/Constant3' */
const volatile float32 CAL_cofPowerLimitMotHeat_af32[9] = { 1.0F, 1.0F, 1.0F,
  0.8F, 0.6F, 0.4F, 0.0F, 0.0F, 0.0F } ;
                                   /* Referenced by: '<S42>/1-D Lookup Table' */

const volatile float32 CAL_tStrrTempFltMotHeat_af32[9] = { -50.0F, 0.0F, 170.0F,
  172.0F, 174.0F, 176.0F, 178.0F, 180.0F, 182.0F } ;
                                   /* Referenced by: '<S42>/1-D Lookup Table' */

#pragma section

/* Block signals (default storage) */
B_SWC_MCF_T SWC_MCF_B;

/* Block states (default storage) */
DW_SWC_MCF_T SWC_MCF_DW;

/*
 * Output and update for action system:
 *    '<S148>/Osc_nrN6'
 *    '<S148>/Osc_nrN7'
 */
void SWC_MCF_Osc_nrN6(float32 rtu_MCF_tiY, float32 rtu_MCF_tiZ, float32
                      *rty_MCF_tiYout, float32 *rty_MCF_tiZout)
{
  /* Gain: '<S164>/Gain' */
  *rty_MCF_tiYout = -rtu_MCF_tiY;

  /* Gain: '<S164>/Gain1' */
  *rty_MCF_tiZout = -rtu_MCF_tiZ;
}

/* Model step function for TID1 */
void SWC_MCF_100us(void)               /* Explicit Task: RE_SWC_MCF_100us */
{
  uint16 tmpRead;
  uint16 tmpRead_0;
  uint16 tmpRead_1;
  float32 tmpRead_2;
  float32 tmpRead_3;
  boolean tmpRead_4;
  float32 rtb_MCF_ibeta;
  float32 rtb_MCF_ialpha;
  float32 rtb_MCF_uaBase;
  float32 rtb_MCF_ubBase;
  float32 rtb_TmpSignalConversionAtRP_S_j;
  float32 rtb_MCF_uBCalc;
  float32 rtb_Product11;
  float32 rtb_Product_dh;
  float32 rtb_Product6;
  float32 rtb_TmpSignalConversionAtRP__os;
  float32 rtb_TmpSignalConversionAtRP_S_e;
  float32 rtb_MCF_frqPwmCalc_j;
  float32 rtb_Subtract_o;
  float32 rtb_TmpSignalConversionAtRP__gi;
  boolean rtb_TmpSignalConversionAtRP_S_o;
  boolean rtb_TmpSignalConversionAtRP__a1;
  float32 rtb_Subtract_cm;
  uint8 rtb_MCF_stN;
  float32 rtb_Product2_p0;
  float32 rtb_MCF_uDcalc;
  boolean rtb_RelationalOperator_o1;
  float32 rtb_Saturation_e;
  float32 rtb_Subtract2_k;
  float32 rtb_Add_j2;
  uint8 rtb_Gain3_o;
  uint8 rtb_Gain1_l;
  uint8 rtb_Gain3;
  uint8 y;
  sint32 rtb_MCF_isqDesCalc_0;

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_MCF_100us' incorporates:
   *  SubSystem: '<Root>/RE_SWC_MCF_100us_sys'
   */
  /* Sum: '<S9>/Add' incorporates:
   *  Inport: '<Root>/RP_SWC_HSPF_HSPF_stIphaOffCal'
   */
  Rte_Read_RP_SWC_HSPF_HSPF_stIphaOffCal(&VAR_MCF_HSPF_stIphaOffCal_u8);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_MCF_100us' */

  /* Inport: '<Root>/RP_SWC_PhC_PhC_iUNoOff' */
  Rte_Read_RP_SWC_PhC_PhC_iUNoOff(&tmpRead);

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_MCF_100us' incorporates:
   *  SubSystem: '<Root>/RE_SWC_MCF_100us_sys'
   */
  /* Switch: '<S13>/Switch' incorporates:
   *  Constant: '<S13>/CAL_CSP_GLB_DigtValue_u16'
   *  Constant: '<S13>/CAL_CSP_GLB_OneHalf_f32'
   *  Constant: '<S13>/CAL_CSP_Succeed_u8'
   *  Inport: '<Root>/RP_SWC_HSPF_HSPF_iPhaUOffset'
   *  Product: '<S13>/Product3'
   *  RelationalOperator: '<S13>/Relational Operator'
   */
  if (VAR_MCF_HSPF_stIphaOffCal_u8 == ((uint8)MCF_Succeed_u8)) {
    Rte_Read_RP_SWC_HSPF_HSPF_iPhaUOffset(&rtb_MCF_uaBase);
  } else {
    rtb_MCF_uaBase = (float32)((uint16)MCF_GLB_DigtValue_u16) *
      MCF_GLB_OneHalf_f32;
  }

  /* End of Switch: '<S13>/Switch' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_MCF_100us' */

  /* Inport: '<Root>/RP_SWC_PhC_PhC_iVNoOff' */
  Rte_Read_RP_SWC_PhC_PhC_iVNoOff(&tmpRead_0);

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_MCF_100us' incorporates:
   *  SubSystem: '<Root>/RE_SWC_MCF_100us_sys'
   */
  /* Switch: '<S13>/Switch1' incorporates:
   *  Constant: '<S13>/CAL_CSP_GLB_DigtValue_u1'
   *  Constant: '<S13>/CAL_CSP_GLB_OneHalf_f1'
   *  Constant: '<S13>/CAL_CSP_Succeed_u8'
   *  Inport: '<Root>/RP_SWC_HSPF_HSPF_iPhaVOffset'
   *  Product: '<S13>/Product4'
   *  RelationalOperator: '<S13>/Relational Operator1'
   */
  if (VAR_MCF_HSPF_stIphaOffCal_u8 == ((uint8)MCF_Succeed_u8)) {
    Rte_Read_RP_SWC_HSPF_HSPF_iPhaVOffset(&rtb_MCF_ubBase);
  } else {
    rtb_MCF_ubBase = (float32)((uint16)MCF_GLB_DigtValue_u16) *
      MCF_GLB_OneHalf_f32;
  }

  /* End of Switch: '<S13>/Switch1' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_MCF_100us' */

  /* Inport: '<Root>/RP_SWC_PhC_PhC_iWNoOff' */
  Rte_Read_RP_SWC_PhC_PhC_iWNoOff(&tmpRead_1);

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_MCF_100us' incorporates:
   *  SubSystem: '<Root>/RE_SWC_MCF_100us_sys'
   */
  /* Product: '<S13>/Product1' incorporates:
   *  Constant: '<S13>/CAL_CSP_iVCnvFac_f32'
   *  DataTypeConversion: '<S13>/Data Type Conversion1'
   *  Sum: '<S13>/Subtract1'
   */
  VAR_MCF_iW_f32 = ((float32)tmpRead_0 - rtb_MCF_ubBase) * CAL_MCF_iVCnvFac_f32;

  /* Switch: '<S13>/Switch2' incorporates:
   *  Constant: '<S13>/CAL_CSP_GLB_DigtValue_u2'
   *  Constant: '<S13>/CAL_CSP_GLB_OneHalf_f2'
   *  Constant: '<S13>/CAL_CSP_Succeed_u8'
   *  Inport: '<Root>/RP_SWC_HSPF_HSPF_iPhaWOffset'
   *  Product: '<S13>/Product5'
   *  RelationalOperator: '<S13>/Relational Operator2'
   */
  if (VAR_MCF_HSPF_stIphaOffCal_u8 == ((uint8)MCF_Succeed_u8)) {
    Rte_Read_RP_SWC_HSPF_HSPF_iPhaWOffset(&rtb_MCF_ubBase);
  } else {
    rtb_MCF_ubBase = (float32)((uint16)MCF_GLB_DigtValue_u16) *
      MCF_GLB_OneHalf_f32;
  }

  /* End of Switch: '<S13>/Switch2' */

  /* MultiPortSwitch: '<S13>/Multiport Switch' incorporates:
   *  Constant: '<S13>/CAL_CSP_iUCnvFac_f32'
   *  Constant: '<S13>/CAL_MCF_iWCnvFac_f32'
   *  Constant: '<S13>/CAL_MCF_stChangePha_u8'
   *  DataTypeConversion: '<S13>/Data Type Conversion'
   *  DataTypeConversion: '<S13>/Data Type Conversion2'
   *  Product: '<S13>/Product'
   *  Product: '<S13>/Product2'
   *  Sum: '<S13>/Subtract'
   *  Sum: '<S13>/Subtract2'
   */
  switch (CAL_MCF_stChangePha_u8) {
   case 1:
    VAR_MCF_iU_f32 = ((float32)tmpRead - rtb_MCF_uaBase) * CAL_MCF_iUCnvFac_f32;

    /* MultiPortSwitch: '<S13>/Multiport Switch1' incorporates:
     *  Constant: '<S13>/CAL_CSP_iUCnvFac_f32'
     *  DataTypeConversion: '<S13>/Data Type Conversion'
     *  Product: '<S13>/Product'
     *  Sum: '<S13>/Subtract'
     */
    VAR_MCF_iV_f32 = VAR_MCF_iW_f32;

    /* MultiPortSwitch: '<S13>/Multiport Switch2' incorporates:
     *  Constant: '<S13>/CAL_MCF_iWCnvFac_f32'
     *  DataTypeConversion: '<S13>/Data Type Conversion2'
     *  Product: '<S13>/Product2'
     *  Sum: '<S13>/Subtract2'
     */
    VAR_MCF_iW_f32 = ((float32)tmpRead_1 - rtb_MCF_ubBase) *
      CAL_MCF_iWCnvFac_f32;
    break;

   case 2:
    VAR_MCF_iU_f32 = ((float32)tmpRead - rtb_MCF_uaBase) * CAL_MCF_iUCnvFac_f32;

    /* MultiPortSwitch: '<S13>/Multiport Switch1' incorporates:
     *  Constant: '<S13>/CAL_CSP_iUCnvFac_f32'
     *  Constant: '<S13>/CAL_MCF_iWCnvFac_f32'
     *  DataTypeConversion: '<S13>/Data Type Conversion'
     *  DataTypeConversion: '<S13>/Data Type Conversion2'
     *  Product: '<S13>/Product'
     *  Product: '<S13>/Product2'
     *  Sum: '<S13>/Subtract'
     *  Sum: '<S13>/Subtract2'
     */
    VAR_MCF_iV_f32 = ((float32)tmpRead_1 - rtb_MCF_ubBase) *
      CAL_MCF_iWCnvFac_f32;
    break;

   case 3:
    VAR_MCF_iU_f32 = VAR_MCF_iW_f32;

    /* MultiPortSwitch: '<S13>/Multiport Switch1' incorporates:
     *  Constant: '<S13>/CAL_CSP_iUCnvFac_f32'
     *  DataTypeConversion: '<S13>/Data Type Conversion'
     *  Product: '<S13>/Product'
     *  Sum: '<S13>/Subtract'
     */
    VAR_MCF_iV_f32 = ((float32)tmpRead - rtb_MCF_uaBase) * CAL_MCF_iUCnvFac_f32;

    /* MultiPortSwitch: '<S13>/Multiport Switch2' incorporates:
     *  Constant: '<S13>/CAL_MCF_iWCnvFac_f32'
     *  DataTypeConversion: '<S13>/Data Type Conversion2'
     *  Product: '<S13>/Product2'
     *  Sum: '<S13>/Subtract2'
     */
    VAR_MCF_iW_f32 = ((float32)tmpRead_1 - rtb_MCF_ubBase) *
      CAL_MCF_iWCnvFac_f32;
    break;

   case 4:
    VAR_MCF_iU_f32 = ((float32)tmpRead_1 - rtb_MCF_ubBase) *
      CAL_MCF_iWCnvFac_f32;

    /* MultiPortSwitch: '<S13>/Multiport Switch1' incorporates:
     *  Constant: '<S13>/CAL_CSP_iUCnvFac_f32'
     *  Constant: '<S13>/CAL_MCF_iWCnvFac_f32'
     *  DataTypeConversion: '<S13>/Data Type Conversion'
     *  DataTypeConversion: '<S13>/Data Type Conversion2'
     *  Product: '<S13>/Product'
     *  Product: '<S13>/Product2'
     *  Sum: '<S13>/Subtract'
     *  Sum: '<S13>/Subtract2'
     */
    VAR_MCF_iV_f32 = ((float32)tmpRead - rtb_MCF_uaBase) * CAL_MCF_iUCnvFac_f32;
    break;

   case 5:
    VAR_MCF_iU_f32 = VAR_MCF_iW_f32;

    /* MultiPortSwitch: '<S13>/Multiport Switch1' incorporates:
     *  Constant: '<S13>/CAL_MCF_iWCnvFac_f32'
     *  DataTypeConversion: '<S13>/Data Type Conversion2'
     *  Product: '<S13>/Product2'
     *  Sum: '<S13>/Subtract2'
     */
    VAR_MCF_iV_f32 = ((float32)tmpRead_1 - rtb_MCF_ubBase) *
      CAL_MCF_iWCnvFac_f32;

    /* MultiPortSwitch: '<S13>/Multiport Switch2' incorporates:
     *  Constant: '<S13>/CAL_CSP_iUCnvFac_f32'
     *  DataTypeConversion: '<S13>/Data Type Conversion'
     *  Product: '<S13>/Product'
     *  Sum: '<S13>/Subtract'
     */
    VAR_MCF_iW_f32 = ((float32)tmpRead - rtb_MCF_uaBase) * CAL_MCF_iUCnvFac_f32;
    break;

   default:
    VAR_MCF_iU_f32 = ((float32)tmpRead_1 - rtb_MCF_ubBase) *
      CAL_MCF_iWCnvFac_f32;

    /* MultiPortSwitch: '<S13>/Multiport Switch1' incorporates:
     *  Constant: '<S13>/CAL_MCF_iWCnvFac_f32'
     *  DataTypeConversion: '<S13>/Data Type Conversion2'
     *  Product: '<S13>/Product2'
     *  Sum: '<S13>/Subtract2'
     */
    VAR_MCF_iV_f32 = VAR_MCF_iW_f32;

    /* MultiPortSwitch: '<S13>/Multiport Switch2' incorporates:
     *  Constant: '<S13>/CAL_CSP_iUCnvFac_f32'
     *  DataTypeConversion: '<S13>/Data Type Conversion'
     *  Product: '<S13>/Product'
     *  Sum: '<S13>/Subtract'
     */
    VAR_MCF_iW_f32 = ((float32)tmpRead - rtb_MCF_uaBase) * CAL_MCF_iUCnvFac_f32;
    break;
  }

  /* End of MultiPortSwitch: '<S13>/Multiport Switch' */

  /* Product: '<S10>/Divide' incorporates:
   *  Constant: '<S10>/ClarkTransformCoefficient1'
   *  Constant: '<S10>/MCF_GLB_SqrtThree_f32'
   *  Sum: '<S10>/Add1'
   *  Sum: '<S13>/Add2'
   *  Sum: '<S13>/Add3'
   */
  rtb_MCF_ibeta = (VAR_MCF_iV_f32 - VAR_MCF_iW_f32) * 0.33333F *
    MCF_GLB_SqrtThree_f32;

  /* Product: '<S10>/Product1' incorporates:
   *  Constant: '<S10>/ClarkTransformCoefficient'
   *  Constant: '<S10>/ClarkTransformCoefficient1'
   *  Product: '<S10>/Product'
   *  Sum: '<S10>/Add'
   *  Sum: '<S13>/Add1'
   *  Sum: '<S13>/Add2'
   *  Sum: '<S13>/Add3'
   */
  rtb_MCF_ialpha = ((2.0F * VAR_MCF_iU_f32 - VAR_MCF_iV_f32) - VAR_MCF_iW_f32) *
    0.33333F;

  /* Sqrt: '<S11>/Sqrt' incorporates:
   *  Product: '<S11>/Product'
   *  Product: '<S11>/Product1'
   *  Sum: '<S11>/Add'
   */
  VAR_MCF_Is_f32 = sqrtf(rtb_MCF_ialpha * rtb_MCF_ialpha + rtb_MCF_ibeta *
    rtb_MCF_ibeta);

  /* SignalConversion generated from: '<S1>/RP_SWC_RCF_RCF_agRtrOffsEstimd_read' incorporates:
   *  Inport: '<Root>/RP_SWC_RCF_RCF_agRtrOffsEstimd'
   */
  Rte_Read_RP_SWC_RCF_RCF_agRtrOffsEstimd(&VAR_MCF_agOffset_f32);

  /* Switch: '<S12>/Switch3' incorporates:
   *  Constant: '<S12>/CAL_MCF_OffsetInternal_f32'
   *  Constant: '<S12>/CAL_MCF_flgCalibOffset_b'
   *  Constant: '<S12>/CAL_MCF_flgInternalOffset_b'
   *  Inport: '<Root>/RP_SWC_NvM_NvM_AngAutoClbOffset'
   *  Inport: '<Root>/RP_SWC_NvM_NvM_flgAngAutoClbOffset'
   *  Switch: '<S12>/Switch'
   */
  if (CAL_MCF_flgInternalOffset_b) {
    VAR_MCF_agOffset_f32 = CAL_MCF_OffsetInternal_f32;
  } else {
    if (CAL_MCF_flgCalibOffset_b) {
      Rte_Read_RP_SWC_NvM_NvM_AngAutoClbOffset(&rtb_Saturation_e);
      Rte_Read_RP_SWC_NvM_NvM_flgAngAutoClbOffset(&tmpRead_4);

      /* Switch: '<S12>/Switch1' incorporates:
       *  Inport: '<Root>/RP_SWC_NvM_NvM_AngAutoClbOffset'
       *  Inport: '<Root>/RP_SWC_NvM_NvM_flgAngAutoClbOffset'
       *  Switch: '<S12>/Switch'
       */
      if (tmpRead_4) {
        VAR_MCF_agOffset_f32 = rtb_Saturation_e;
      }

      /* End of Switch: '<S12>/Switch1' */
    }
  }

  /* End of Switch: '<S12>/Switch3' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_MCF_100us' */

  /* Inport: '<Root>/RP_SWC_Rdc_Rdc_ArctanAgRtr' */
  Rte_Read_RP_SWC_Rdc_Rdc_ArctanAgRtr(&rtb_Subtract_o);

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_MCF_100us' incorporates:
   *  SubSystem: '<Root>/RE_SWC_MCF_100us_sys'
   */
  /* Sum: '<S12>/Add' */
  VAR_MCF_agRtrEe_f32 = VAR_MCF_agOffset_f32 + rtb_Subtract_o;

  /* Switch: '<S15>/Switch' incorporates:
   *  Constant: '<S15>/Constant'
   *  Constant: '<S15>/Constant1'
   *  RelationalOperator: '<S15>/Relational Operator'
   *  RelationalOperator: '<S15>/Relational Operator1'
   *  Sum: '<S15>/Add'
   *  Switch: '<S15>/Switch1'
   */
  if (360.0F <= VAR_MCF_agRtrEe_f32) {
    VAR_MCF_agRtrEe_f32 -= 360.0F;
  } else {
    if (VAR_MCF_agRtrEe_f32 <= 0.0F) {
      /* Switch: '<S15>/Switch1' incorporates:
       *  Constant: '<S15>/Constant2'
       *  Sum: '<S15>/Add1'
       */
      VAR_MCF_agRtrEe_f32 += 360.0F;
    }
  }

  /* End of Switch: '<S15>/Switch' */

  /* Switch: '<S13>/Switch4' incorporates:
   *  Constant: '<S13>/CAL_MCF_bUseduDclnkSet_b'
   *  Constant: '<S13>/CAL_MCF_uIntDclnkVol_f32'
   *  Inport: '<Root>/RP_SWC_HvMcu_HvMcu_uDcLnkHvMcu'
   *  Inport: '<Root>/RP_SWC_PhC_PhC_uDcLnkLowMcu'
   */
  if (CAL_MCF_bUseduDclnkSet_b) {
    VAR_MCF_uDcLnk_f32 = CAL_MCF_uDclnkSet_f32;
  } else {
    Rte_Read_RP_SWC_HvMcu_HvMcu_uDcLnkHvMcu(&VAR_MCF_uDcLnk_f32);
    Rte_Read_RP_SWC_PhC_PhC_uDcLnkLowMcu(&tmpRead_2);

    /* Switch: '<S13>/Switch3' incorporates:
     *  Constant: '<S13>/CAL_MCF_flgLowOrHvudcLnk_b'
     *  Inport: '<Root>/RP_SWC_HvMcu_HvMcu_uDcLnkHvMcu'
     *  Inport: '<Root>/RP_SWC_PhC_PhC_uDcLnkLowMcu'
     */
    if (CAL_MCF_flgLowOrHvudcLnk_b) {
      VAR_MCF_uDcLnk_f32 = tmpRead_2;
    }

    /* End of Switch: '<S13>/Switch3' */
  }

  /* End of Switch: '<S13>/Switch4' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_MCF_100us' */

  /* Inport: '<Root>/RP_SWC_MDF_MDF_bFaultEMBlkWarnSt' */
  Rte_Read_RP_SWC_MDF_MDF_bFaultEMBlkWarnSt(&rtb_Gain3_o);

  /* Inport: '<Root>/RP_SWC_MPC_MPC_frqPwmVF' */
  Rte_Read_RP_SWC_MPC_MPC_frqPwmVF(&rtb_MCF_frqPwmCalc_j);

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_MCF_100us' incorporates:
   *  SubSystem: '<Root>/RE_SWC_MCF_100us_sys'
   */
  /* Product: '<S14>/Divide' incorporates:
   *  Constant: '<S14>/CAL_CSP_GLB_CircAge_f32'
   *  Constant: '<S14>/CAL_CSP_GLB_DigtValue_u16'
   */
  rtb_MCF_uaBase = VAR_MCF_agRtrEe_f32 * (float32)((uint16)MCF_GLB_DigtValue_u16)
    / MCF_GLB_CircAge_f32;

  /* LookupNDDirect: '<S14>/LookupCosTable' incorporates:
   *  LookupNDDirect: '<S14>/LookupSinTable'
   *
   * About '<S14>/LookupCosTable':
   *  1-dimensional Direct Look-Up returning a Scalar,
   *
   *     Remove protection against out-of-range input in generated code: 'off'
   *
   * About '<S14>/LookupSinTable':
   *  1-dimensional Direct Look-Up returning a Scalar,
   *
   *     Remove protection against out-of-range input in generated code: 'off'
   */
  if (rtb_MCF_uaBase > 4095.0F) {
    tmpRead_2 = 4095.0F;
    rtb_MCF_uaBase = 4095.0F;
  } else {
    if (rtb_MCF_uaBase < 0.0F) {
      tmpRead_2 = 0.0F;
    } else {
      tmpRead_2 = rtb_MCF_uaBase;
    }

    if (rtb_MCF_uaBase < 0.0F) {
      rtb_MCF_uaBase = 0.0F;
    }
  }

  rtb_MCF_ubBase = rtCP_LookupCosTable_table_j[(sint32)tmpRead_2];

  /* End of LookupNDDirect: '<S14>/LookupCosTable' */

  /* LookupNDDirect: '<S14>/LookupSinTable'
   *
   * About '<S14>/LookupSinTable':
   *  1-dimensional Direct Look-Up returning a Scalar,
   *
   *     Remove protection against out-of-range input in generated code: 'off'
   */
  rtb_MCF_uaBase = rtCP_LookupSinTable_table_o[(sint32)rtb_MCF_uaBase];

  /* Sum: '<S14>/Add' incorporates:
   *  Product: '<S14>/Product'
   *  Product: '<S14>/Product1'
   */
  VAR_MCF_idAct_f32 = rtb_MCF_ubBase * rtb_MCF_ialpha + rtb_MCF_uaBase *
    rtb_MCF_ibeta;

  /* Sum: '<S14>/Add1' incorporates:
   *  Product: '<S14>/Product2'
   *  Product: '<S14>/Product3'
   */
  VAR_MCF_iqAct_f32 = rtb_MCF_ubBase * rtb_MCF_ibeta - rtb_MCF_uaBase *
    rtb_MCF_ialpha;
  GLB_MCF_ialpha_f32 = rtb_MCF_ialpha;
  GLB_MCF_ibeta_f32 = rtb_MCF_ibeta;
  /* SignalConversion generated from: '<S1>/RP_SWC_Rdc_Rdc_nWoFlt_read' incorporates:
   *  Inport: '<Root>/RP_SWC_Rdc_Rdc_nWoFlt'
   */
  Rte_Read_RP_SWC_Rdc_Rdc_nWoFlt(&VAR_MCF_Rdc_nWoFlt_f32);

  /* Abs: '<S22>/Abs' incorporates:
   *  Abs: '<S122>/Abs'
   *  Abs: '<S46>/Abs1'
   *  Abs: '<S82>/Abs'
   */
  rtb_Saturation_e = fabsf(VAR_MCF_Rdc_nWoFlt_f32);

  /* Lookup_n-D: '<S22>/Spd_UsUseRateDes_Table' incorporates:
   *  Abs: '<S22>/Abs'
   */
  rtb_MCF_uaBase = look1_iflf_binlcapw(rtb_Saturation_e, ((const float32 *)
    &(CAL_MCF_UsUseRateDesTableX_Spd_af32[0])), ((const float32 *)
    &(CAL_MCF_UsUseRateDesTableY_UsRes_af32[0])), 10U);

  /* Saturate: '<S22>/Saturation' */
  if (rtb_MCF_uaBase > 0.92F) {
    rtb_MCF_uaBase = 0.92F;
  } else {
    if (rtb_MCF_uaBase < 1.0E-6F) {
      rtb_MCF_uaBase = 1.0E-6F;
    }
  }

  /* End of Saturate: '<S22>/Saturation' */

  /* Sum: '<S22>/Subtract' incorporates:
   *  Constant: '<S22>/Constant2'
   *  Constant: '<S22>/Constant4'
   *  Product: '<S22>/Divide'
   */
  VAR_MCF_UsUseRateDes_f32 = 1.0F / rtb_MCF_uaBase - 1.0F;

  /* Saturate: '<S23>/Saturation1' incorporates:
   *  UnitDelay: '<S23>/Unit Delay'
   */
  if (VAR_MCF_UsUseRateReal_f32 > 20.0F) {
    rtb_MCF_uaBase = 20.0F;
  } else if (VAR_MCF_UsUseRateReal_f32 < -1.0F) {
    rtb_MCF_uaBase = -1.0F;
  } else {
    rtb_MCF_uaBase = VAR_MCF_UsUseRateReal_f32;
  }

  /* End of Saturate: '<S23>/Saturation1' */

  /* Sum: '<S22>/Add1' incorporates:
   *  Sum: '<S33>/Subtract3'
   */
  tmpRead_2 = rtb_MCF_uaBase - VAR_MCF_UsUseRateDes_f32;

  /* Switch: '<S22>/Switch3' incorporates:
   *  Constant: '<S22>/Constant1'
   *  RelationalOperator: '<S22>/Relational'
   *  Sum: '<S22>/Add1'
   */
  VAR_MCF_flgFw_b = (tmpRead_2 <= 0.0F);

  /* Product: '<S23>/Product' incorporates:
   *  Constant: '<S23>/cofOverMod1'
   *  Sum: '<S13>/Add'
   */
  rtb_MCF_ubBase = VAR_MCF_uDcLnk_f32 * 0.667F;

  /* SignalConversion generated from: '<S1>/RP_SWC_MPC_MPC_Rv_read' incorporates:
   *  Inport: '<Root>/RP_SWC_MPC_MPC_Rv'
   */
  Rte_Read_RP_SWC_MPC_MPC_Rv(&rtb_TmpSignalConversionAtRP_S_j);

  /* Product: '<S56>/Product5' incorporates:
   *  Sum: '<S14>/Add2'
   */
  VAR_MCF_udRv_f32 = rtb_TmpSignalConversionAtRP_S_j * VAR_MCF_idAct_f32;

  /* SignalConversion generated from: '<S1>/RP_SWC_SCF_SCF_flgEnDchaToMc_read' incorporates:
   *  Inport: '<Root>/RP_SWC_SCF_SCF_flgEnDchaToMc'
   */
  Rte_Read_RP_SWC_SCF_SCF_flgEnDchaToMc(&rtb_TmpSignalConversionAtRP__a1);

  /* SignalConversion generated from: '<S1>/RP_SWC_MPC_MPC_isdMTPA_read' incorporates:
   *  Inport: '<Root>/RP_SWC_MPC_MPC_isdMTPA'
   */
  Rte_Read_RP_SWC_MPC_MPC_isdMTPA(&rtb_TmpSignalConversionAtRP__gi);

  /* SignalConversion generated from: '<S1>/RP_SWC_SCF_SCF_flginitPI_read' incorporates:
   *  Inport: '<Root>/RP_SWC_SCF_SCF_flginitPI'
   */
  Rte_Read_RP_SWC_SCF_SCF_flginitPI(&VAR_MCF_SCF_flgInitEn_b);

  /* Chart: '<S119>/Chart' incorporates:
   *  Constant: '<S119>/CAL_MCF_FixFreq_f32'
   *  Constant: '<S119>/CAL_MCF_HalfFreq_f32'
   *  Constant: '<S119>/CAL_MCF_flgVF_b'
   *  Constant: '<S119>/Constant7'
   *  RelationalOperator: '<S119>/Relational Operator3'
   */
  if (3 == rtb_Gain3_o) {
    rtb_MCF_frqPwmCalc_j = CAL_MCF_HalfFreq_f32;
  } else {
    if (!CAL_MCF_flgVF_b) {
      rtb_MCF_frqPwmCalc_j = CAL_MCF_FixFreq_f32;
    }
  }

  /* End of Chart: '<S119>/Chart' */

  /* Sum: '<S184>/Subtract' incorporates:
   *  UnitDelay: '<S184>/Unit Delay2'
   */
  rtb_Subtract_o = rtb_MCF_frqPwmCalc_j - SWC_MCF_DW.UnitDelay2_DSTATE;

  /* Switch: '<S184>/Switch3' incorporates:
   *  Constant: '<S184>/CAL_MCF_FrqRmp_f32'
   *  RelationalOperator: '<S184>/Relational Operator'
   *  Sum: '<S184>/Add1'
   *  UnitDelay: '<S184>/Unit Delay2'
   */
  if (rtb_Subtract_o <= CAL_MCF_FrqRmp_f32) {
    /* Switch: '<S184>/Switch4' incorporates:
     *  Product: '<S184>/Product1'
     *  RelationalOperator: '<S184>/Relational Operator2'
     */
    if (-rtb_Subtract_o <= CAL_MCF_FrqRmp_f32) {
      /* UnitDelay: '<S184>/Unit Delay2' */
      SWC_MCF_DW.UnitDelay2_DSTATE = rtb_MCF_frqPwmCalc_j;
    } else {
      /* UnitDelay: '<S184>/Unit Delay2' incorporates:
       *  Sum: '<S184>/Add3'
       */
      SWC_MCF_DW.UnitDelay2_DSTATE -= CAL_MCF_FrqRmp_f32;
    }

    /* End of Switch: '<S184>/Switch4' */
  } else {
    SWC_MCF_DW.UnitDelay2_DSTATE += CAL_MCF_FrqRmp_f32;
  }

  /* End of Switch: '<S184>/Switch3' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_MCF_100us' */

  /* Inport: '<Root>/RP_SWC_MPC_MPC_isdMTPV' */
  Rte_Read_RP_SWC_MPC_MPC_isdMTPV(&rtb_Subtract2_k);

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_MCF_100us' incorporates:
   *  SubSystem: '<Root>/RE_SWC_MCF_100us_sys'
   */
  /* Saturate: '<S119>/Saturation1' incorporates:
   *  UnitDelay: '<S184>/Unit Delay2'
   */
  if (SWC_MCF_DW.UnitDelay2_DSTATE > 10000.0F) {
    rtb_MCF_uBCalc = 10000.0F;
  } else if (SWC_MCF_DW.UnitDelay2_DSTATE < 2000.0F) {
    rtb_MCF_uBCalc = 2000.0F;
  } else {
    rtb_MCF_uBCalc = SWC_MCF_DW.UnitDelay2_DSTATE;
  }

  /* End of Saturate: '<S119>/Saturation1' */

  /* Product: '<S119>/Divide1' incorporates:
   *  Constant: '<S119>/Constant2'
   */
  rtb_Subtract_o = 1.0F / rtb_MCF_uBCalc;

  /* Sum: '<S32>/Add' */
  VAR_MCF_periodCalc_f32 = rtb_Subtract_o;

  /* Sum: '<S33>/Subtract2' */
  rtb_Subtract2_k -= rtb_TmpSignalConversionAtRP__gi;

  /* Switch: '<S32>/Switch1' incorporates:
   *  Constant: '<S32>/Constant1'
   */
  if (VAR_MCF_SCF_flgInitEn_b) {
    VAR_MCF_isdFW_f32 = 0.0F;
  } else {
    /* Sum: '<S32>/Add4' incorporates:
     *  Constant: '<S32>/CAL_MCF_isdfwKi_f1'
     *  Constant: '<S32>/CAL_MCF_isdfwKp_f1'
     *  Constant: '<S32>/Constant'
     *  Product: '<S32>/Product'
     *  Product: '<S32>/Product1'
     *  Product: '<S32>/Product2'
     *  Product: '<S32>/Product3'
     *  Sum: '<S32>/Add3'
     *  UnitDelay: '<S32>/Delay2'
     *  UnitDelay: '<S32>/Delay3'
     */
    VAR_MCF_isdFW_f32 += CAL_MCF_isdfwKi_f32 * 10000.0F * VAR_MCF_periodCalc_f32
      * tmpRead_2 + (tmpRead_2 - SWC_MCF_DW.Delay2_DSTATE) * CAL_MCF_isdfwKp_f32;

    /* Switch: '<S37>/Switch2' incorporates:
     *  RelationalOperator: '<S37>/LowerRelop1'
     *  RelationalOperator: '<S37>/UpperRelop'
     *  Sum: '<S33>/Subtract1'
     *  Switch: '<S37>/Switch'
     */
    if (VAR_MCF_isdFW_f32 > 0.0F) {
      VAR_MCF_isdFW_f32 = 0.0F;
    } else {
      if (VAR_MCF_isdFW_f32 < rtb_Subtract2_k) {
        /* Switch: '<S37>/Switch' */
        VAR_MCF_isdFW_f32 = rtb_Subtract2_k;
      }
    }

    /* End of Switch: '<S37>/Switch2' */
  }

  /* End of Switch: '<S32>/Switch1' */

  /* Switch: '<S32>/Switch' incorporates:
   *  Constant: '<S32>/CAL_MCF_flgUseFF_b'
   *  Inport: '<Root>/RP_SWC_MPC_MPC_isdFF'
   *  Sum: '<S32>/Add1'
   */
  if (CAL_MCF_flgUseFF_b) {
    Rte_Read_RP_SWC_MPC_MPC_isdFF(&rtb_Product_dh);
    VAR_MCF_isdFW_f32 += rtb_Product_dh - rtb_TmpSignalConversionAtRP__gi;
  }

  /* End of Switch: '<S32>/Switch' */

  /* Switch: '<S36>/Switch2' incorporates:
   *  RelationalOperator: '<S36>/LowerRelop1'
   *  RelationalOperator: '<S36>/UpperRelop'
   *  Sum: '<S33>/Subtract1'
   *  Switch: '<S36>/Switch'
   */
  if (VAR_MCF_isdFW_f32 > 0.0F) {
    VAR_MCF_isdFW_f32 = 0.0F;
  } else {
    if (VAR_MCF_isdFW_f32 < rtb_Subtract2_k) {
      /* Switch: '<S36>/Switch' */
      VAR_MCF_isdFW_f32 = rtb_Subtract2_k;
    }
  }

  /* End of Switch: '<S36>/Switch2' */

  /* SignalConversion generated from: '<S1>/RP_SWC_TDC_TDC_TrqDes_read' incorporates:
   *  Inport: '<Root>/RP_SWC_TDC_TDC_TrqDes'
   */
  Rte_Read_RP_SWC_TDC_TDC_TrqDes(&rtb_TmpSignalConversionAtRP__os);

  /* SignalConversion generated from: '<S1>/RP_SWC_SCF_SCF_FIM_ReqFailrMod_read' incorporates:
   *  Inport: '<Root>/RP_SWC_SCF_SCF_FIM_ReqFailrMod'
   */
  Rte_Read_RP_SWC_SCF_SCF_FIM_ReqFailrMod(&rtb_TmpSignalConversionAtRP_S_o);

  /* RelationalOperator: '<S45>/Relational Operator5' */
  rtb_TmpSignalConversionAtRP_S_o = !rtb_TmpSignalConversionAtRP_S_o;

  /* Outputs for Enabled SubSystem: '<S60>/Calculate dead compensation voltage' incorporates:
   *  EnablePort: '<S63>/Enable'
   */
  /* Abs: '<S46>/Abs' incorporates:
   *  Abs: '<S122>/Abs1'
   *  Abs: '<S65>/Abs6'
   *  Abs: '<S80>/Abs'
   */
  rtb_Subtract2_k = fabsf(rtb_TmpSignalConversionAtRP__os);

  /* End of Outputs for SubSystem: '<S60>/Calculate dead compensation voltage' */

  /* Logic: '<S45>/Logical Operator' incorporates:
   *  Abs: '<S46>/Abs'
   *  Constant: '<S45>/Constant6'
   *  Constant: '<S46>/CAL_MCF_SpdOffActiveHeat_f32'
   *  Logic: '<S45>/Logical Operator1'
   *  Lookup_n-D: '<S46>/1-D Lookup Table'
   *  RelationalOperator: '<S46>/Relational Operator'
   *  RelationalOperator: '<S46>/Relational Operator2'
   */
  VAR_MCF_flgMotHeat_b = ((rtb_Saturation_e <= CAL_MCF_SpdOffActiveHeat_f32) &&
    (rtb_Subtract2_k <= look1_iflf_binlxpw(rtb_Saturation_e, ((const float32 *)
    &(CAL_MCF_SpdActiveHeat_af32[0])), ((const float32 *)
    &(CAL_MCF_TrqOffActiveHeat_af32[0])), 8U)) && CAL_MCF_flgMotHeat_b &&
    rtb_TmpSignalConversionAtRP_S_o);

  /* Outputs for Enabled SubSystem: '<S34>/Subsystem4' incorporates:
   *  EnablePort: '<S39>/Enable'
   */
  /* UnitDelay: '<S34>/Unit Delay' incorporates:
   *  Inport: '<Root>/RP_SWC_BCC_BCC_iDcLnkEstFlt'
   *  Inport: '<Root>/RP_SWC_HSPF_HSPF_tStrrTempFlt'
   *  Inport: '<Root>/RP_SWC_MPC_MPC_TrqMechFlt'
   */
  if (SWC_MCF_DW.UnitDelay_DSTATE_p) {
    Rte_Read_RP_SWC_BCC_BCC_iDcLnkEstFlt(&rtb_Product2_p0);
    Rte_Read_RP_SWC_MPC_MPC_TrqMechFlt(&rtb_Product6);
    Rte_Read_RP_SWC_HSPF_HSPF_tStrrTempFlt(&tmpRead_3);

    /* Lookup_n-D: '<S42>/1-D Lookup Table' incorporates:
     *  Inport: '<Root>/RP_SWC_BCC_BCC_iDcLnkEstFlt'
     *  Inport: '<Root>/RP_SWC_HSPF_HSPF_tStrrTempFlt'
     *  Inport: '<Root>/RP_SWC_MPC_MPC_TrqMechFlt'
     */
    SWC_MCF_B.uDLookupTable = look1_iflf_binlxpw(tmpRead_3, ((const float32 *)
      &(CAL_tStrrTempFltMotHeat_af32[0])), ((const float32 *)
      &(CAL_cofPowerLimitMotHeat_af32[0])), 8U);

    /* Saturate: '<S42>/Saturation' incorporates:
     *  Constant: '<S42>/Constant3'
     *  Sum: '<S42>/Add2'
     */
    if (CAL_PowerMotHeat_f32 > CAL_MCF_UpPowerHeat_f32) {
      rtb_MCF_uaBase = CAL_MCF_UpPowerHeat_f32;
    } else if (CAL_PowerMotHeat_f32 < 0.0F) {
      rtb_MCF_uaBase = 0.0F;
    } else {
      rtb_MCF_uaBase = CAL_PowerMotHeat_f32;
    }

    /* End of Saturate: '<S42>/Saturation' */

    /* Product: '<S42>/Product4' */
    VAR_MCF_PCUHeaterPower_f32 = rtb_MCF_uaBase * SWC_MCF_B.uDLookupTable;

    /* Product: '<S42>/Product1' incorporates:
     *  Constant: '<S42>/Constant'
     *  Product: '<S42>/Product'
     *  Sum: '<S13>/Add'
     */
    VAR_MCF_PowerDcLnk_f32 = rtb_Product2_p0 * VAR_MCF_uDcLnk_f32 * 0.001F;

    /* Product: '<S42>/Product3' incorporates:
     *  Constant: '<S42>/Constant1'
     *  Product: '<S42>/Product2'
     */
    VAR_MCF_PowerMech_f32 = rtb_Product6 * VAR_MCF_Rdc_nWoFlt_f32 *
      0.000104712039F;

    /* Sum: '<S42>/Add' */
    VAR_MCF_PowerMotHeat_f32 = VAR_MCF_PowerDcLnk_f32 - VAR_MCF_PowerMech_f32;

    /* Sum: '<S42>/Add1' */
    rtb_MCF_uaBase = VAR_MCF_PowerMotHeat_f32 - VAR_MCF_PCUHeaterPower_f32;

    /* Switch: '<S43>/Switch2' */
    if (VAR_MCF_flgMotHeat_b) {
      /* Saturate: '<S43>/Saturation2' incorporates:
       *  Constant: '<S43>/Constant1'
       *  Product: '<S43>/Product1'
       *  Sum: '<S43>/Add1'
       *  UnitDelay: '<S43>/Unit Delay'
       */
      if (SWC_MCF_DW.UnitDelay_DSTATE_kk > CAL_MCF_UpLimitIMotHeat_f32) {
        SWC_MCF_DW.UnitDelay_DSTATE_kk = CAL_MCF_UpLimitIMotHeat_f32;
      } else {
        if (SWC_MCF_DW.UnitDelay_DSTATE_kk < CAL_MCF_DownLimitIMotHeat_f32) {
          SWC_MCF_DW.UnitDelay_DSTATE_kk = CAL_MCF_DownLimitIMotHeat_f32;
        }
      }

      SWC_MCF_DW.UnitDelay_DSTATE_kk += rtb_MCF_uaBase * CAL_MCF_KiMotHeat_f32;
    } else {
      /* Saturate: '<S43>/Saturation2' incorporates:
       *  Constant: '<S43>/Constant2'
       *  UnitDelay: '<S43>/Unit Delay'
       */
      SWC_MCF_DW.UnitDelay_DSTATE_kk = 0.0F;
    }

    /* End of Switch: '<S43>/Switch2' */

    /* Sum: '<S43>/Add' incorporates:
     *  Constant: '<S43>/Constant3'
     *  Product: '<S43>/Product'
     *  UnitDelay: '<S43>/Unit Delay'
     */
    rtb_MCF_uaBase = rtb_MCF_uaBase * CAL_MCF_KpMotHeat_f32 +
      SWC_MCF_DW.UnitDelay_DSTATE_kk;

    /* Saturate: '<S43>/Saturation1' */
    if (rtb_MCF_uaBase > CAL_MCF_UpLimitPIMotHeat_f32) {
      rtb_MCF_uaBase = CAL_MCF_UpLimitPIMotHeat_f32;
    } else {
      if (rtb_MCF_uaBase < CAL_MCF_DownLimitPIMotHeat_f32) {
        rtb_MCF_uaBase = CAL_MCF_DownLimitPIMotHeat_f32;
      }
    }

    /* End of Saturate: '<S43>/Saturation1' */

    /* Switch: '<S44>/Switch' incorporates:
     *  Constant: '<S44>/Constant'
     *  RelationalOperator: '<S44>/Relational Operator'
     *  Sum: '<S44>/Add'
     */
    if (rtb_MCF_uaBase >= rtb_TmpSignalConversionAtRP__gi) {
      SWC_MCF_B.Switch = 0.0F;
    } else {
      SWC_MCF_B.Switch = rtb_MCF_uaBase - rtb_TmpSignalConversionAtRP__gi;
    }

    /* End of Switch: '<S44>/Switch' */
  }

  /* End of UnitDelay: '<S34>/Unit Delay' */
  /* End of Outputs for SubSystem: '<S34>/Subsystem4' */

  /* Switch: '<S34>/Switch' incorporates:
   *  Constant: '<S34>/Constant'
   */
  if (VAR_MCF_flgMotHeat_b) {
    VAR_MCF_idMotHeat_f32 = SWC_MCF_B.Switch;
  } else {
    VAR_MCF_idMotHeat_f32 = 0.0F;
  }

  /* End of Switch: '<S34>/Switch' */

  /* If: '<S30>/If' incorporates:
   *  Constant: '<S30>/CAL_MCF_flgUseisTheta_b'
   *  Constant: '<S30>/CAL_MCF_flgUseisdqSet_b'
   */
  if (CAL_MCF_flgUseisTheta_b) {
    /* Outputs for IfAction SubSystem: '<S30>/id_ThetaSet' incorporates:
     *  ActionPort: '<S50>/Action Port'
     */
    /* LookupNDDirect: '<S50>/McFwc_CosTable' incorporates:
     *  Constant: '<S50>/CAL_MCF_isThetaSet_f32'
     *  Gain: '<S50>/TransferCof'
     *
     * About '<S50>/McFwc_CosTable':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     */
    rtb_MCF_uaBase = 11.375F * CAL_MCF_isThetaSet_f32;
    if (rtb_MCF_uaBase > 4095.0F) {
      rtb_MCF_uaBase = 4095.0F;
    } else {
      if (rtb_MCF_uaBase < 0.0F) {
        rtb_MCF_uaBase = 0.0F;
      }
    }

    /* Product: '<S50>/Product' incorporates:
     *  Constant: '<S50>/CAL_MCF_isSet_f32'
     *  Constant: '<S50>/Constant'
     *  LookupNDDirect: '<S50>/McFwc_CosTable'
     *
     * About '<S50>/McFwc_CosTable':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     */
    VAR_MCF_idDes_f32 = CAL_MCF_isSet_f32 * rtCP_Constant_Value_d[(sint32)
      rtb_MCF_uaBase];

    /* End of Outputs for SubSystem: '<S30>/id_ThetaSet' */
  } else if (CAL_MCF_flgUseisdqSet_b) {
    /* Outputs for IfAction SubSystem: '<S30>/id_Set' incorporates:
     *  ActionPort: '<S49>/Action Port'
     */
    /* SignalConversion generated from: '<S49>/isdSet' incorporates:
     *  Constant: '<S49>/CAL_MCF_isdSet_f32'
     */
    VAR_MCF_idDes_f32 = CAL_MCF_isdSet_f32;

    /* End of Outputs for SubSystem: '<S30>/id_Set' */
  } else if (rtb_TmpSignalConversionAtRP__a1) {
    /* Outputs for IfAction SubSystem: '<S30>/Discharge_id' incorporates:
     *  ActionPort: '<S47>/Action Port'
     */
    /* SignalConversion generated from: '<S47>/DisChargeisdDes' incorporates:
     *  Constant: '<S47>/CAL_MCF_DisChargeisdDes_f32'
     */
    VAR_MCF_idDes_f32 = CAL_MCF_DisChaisdDes_f32;

    /* End of Outputs for SubSystem: '<S30>/Discharge_id' */
  } else {
    /* Outputs for IfAction SubSystem: '<S30>/id_Fw' incorporates:
     *  ActionPort: '<S48>/Action Port'
     */
    /* Sum: '<S48>/Add' incorporates:
     *  Sum: '<S35>/Add'
     */
    VAR_MCF_idDes_f32 = (VAR_MCF_isdFW_f32 + VAR_MCF_idMotHeat_f32) +
      rtb_TmpSignalConversionAtRP__gi;

    /* End of Outputs for SubSystem: '<S30>/id_Fw' */
  }

  /* End of If: '<S30>/If' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_MCF_100us' */

  /* Inport: '<Root>/RP_SWC_MPC_MPC_OmBw' */
  Rte_Read_RP_SWC_MPC_MPC_OmBw(&rtb_Product11);

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_MCF_100us' incorporates:
   *  SubSystem: '<Root>/RE_SWC_MCF_100us_sys'
   */
  /* Sum: '<S27>/Add2' incorporates:
   *  Inport: '<Root>/RP_SWC_MPC_MPC_LdSubLq'
   */
  Rte_Read_RP_SWC_MPC_MPC_LdSubLq(&VAR_MCF_MPC_LdSubLq_f32);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_MCF_100us' */

  /* Inport: '<Root>/RP_SWC_MPC_MPC_Rs' */
  Rte_Read_RP_SWC_MPC_MPC_Rs(&rtb_Add_j2);

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_MCF_100us' incorporates:
   *  SubSystem: '<Root>/RE_SWC_MCF_100us_sys'
   */
  /* Sum: '<S56>/Subtract' incorporates:
   *  Sum: '<S14>/Add2'
   *  Sum: '<S27>/Add'
   */
  rtb_TmpSignalConversionAtRP__gi = VAR_MCF_idDes_f32 - VAR_MCF_idAct_f32;

  /* Product: '<S119>/Divide2' incorporates:
   *  Constant: '<S119>/frqBase10K1'
   */
  rtb_MCF_uBCalc /= 10000.0F;

  /* Product: '<S56>/Product11' */
  rtb_Product11 *= rtb_MCF_uBCalc;

  /* SignalConversion generated from: '<S1>/RP_SWC_MPC_MPC_Ld_read' incorporates:
   *  Inport: '<Root>/RP_SWC_MPC_MPC_Ld'
   */
  Rte_Read_RP_SWC_MPC_MPC_Ld(&VAR_MCF_MPC_Ld_f32);

  /* Sum: '<S56>/Add' */
  rtb_Add_j2 += rtb_TmpSignalConversionAtRP_S_j;

  /* Product: '<S57>/Product' */
  rtb_Product_dh = rtb_Subtract_o * rtb_MCF_uBCalc;

  /* Product: '<S56>/Product6' incorporates:
   *  Constant: '<S56>/Constant'
   *  Constant: '<S56>/Constant1'
   *  Constant: '<S56>/MCF_GLB_pi_f32'
   *  Product: '<S56>/Product4'
   */
  rtb_Product6 = VAR_MCF_Rdc_nWoFlt_f32 * 0.0666666701F * MCF_GLB_pi_f32 * 2.0F;

  /* SignalConversion generated from: '<S1>/RP_SWC_MPC_MPC_Lq_read' incorporates:
   *  Inport: '<Root>/RP_SWC_MPC_MPC_Lq'
   */
  Rte_Read_RP_SWC_MPC_MPC_Lq(&VAR_MCF_MPC_Lq_f32);

  /* SignalConversion generated from: '<S1>/RP_SWC_MPC_MPC_Psi_read' incorporates:
   *  Inport: '<Root>/RP_SWC_MPC_MPC_Psi'
   */
  Rte_Read_RP_SWC_MPC_MPC_Psi(&rtb_TmpSignalConversionAtRP_S_e);

  /* Product: '<S28>/Product1' incorporates:
   *  Constant: '<S28>/Constant'
   *  Constant: '<S28>/MCF_GLB_MotorPole_u8'
   *  Product: '<S28>/Product'
   *  Product: '<S28>/Product2'
   *  Sum: '<S28>/Add'
   */
  rtb_MCF_uaBase = (VAR_MCF_MPC_LdSubLq_f32 * VAR_MCF_idDes_f32 +
                    rtb_TmpSignalConversionAtRP_S_e) * 1.5F * (float32)((uint8)
    MCF_GLB_MotorPole_u8);

  /* Saturate: '<S28>/Saturation' */
  if (rtb_MCF_uaBase > 255.0F) {
    rtb_MCF_uaBase = 255.0F;
  } else {
    if (rtb_MCF_uaBase < 0.01F) {
      rtb_MCF_uaBase = 0.01F;
    }
  }

  /* End of Saturate: '<S28>/Saturation' */

  /* Product: '<S28>/Divide' */
  VAR_MCF_iqDes_f32 = rtb_TmpSignalConversionAtRP__os / rtb_MCF_uaBase;

  /* If: '<S31>/If' incorporates:
   *  Constant: '<S31>/CAL_MCF_flgUseisTheta_b'
   *  Constant: '<S31>/CAL_MCF_flgUseisdqSet_b'
   */
  if (CAL_MCF_flgUseisTheta_b) {
    /* Outputs for IfAction SubSystem: '<S31>/iq_ThetaSet' incorporates:
     *  ActionPort: '<S54>/Action Port'
     */
    /* LookupNDDirect: '<S54>/McFwc_SinTable' incorporates:
     *  Constant: '<S54>/CAL_MCF_isThetaSet_f32'
     *  Gain: '<S54>/TransferCof'
     *
     * About '<S54>/McFwc_SinTable':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     */
    rtb_MCF_uaBase = 11.375F * CAL_MCF_isThetaSet_f32;
    if (rtb_MCF_uaBase > 4095.0F) {
      rtb_MCF_uaBase = 4095.0F;
    } else {
      if (rtb_MCF_uaBase < 0.0F) {
        rtb_MCF_uaBase = 0.0F;
      }
    }

    /* Product: '<S54>/Product' incorporates:
     *  Constant: '<S54>/CAL_MCF_isSet_f32'
     *  LookupNDDirect: '<S54>/McFwc_SinTable'
     *
     * About '<S54>/McFwc_SinTable':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     */
    VAR_MCF_iqDes_f32 = CAL_MCF_isSet_f32 * rtCP_McFwc_SinTable_table[(sint32)
      rtb_MCF_uaBase];

    /* End of Outputs for SubSystem: '<S31>/iq_ThetaSet' */
  } else if (CAL_MCF_flgUseisdqSet_b) {
    /* Outputs for IfAction SubSystem: '<S31>/iq_Set' incorporates:
     *  ActionPort: '<S53>/Action Port'
     */
    /* SignalConversion generated from: '<S53>/isqSet' incorporates:
     *  Constant: '<S53>/CAL_MCF_isqSet_f32'
     */
    VAR_MCF_iqDes_f32 = CAL_MCF_isqSet_f32;

    /* End of Outputs for SubSystem: '<S31>/iq_Set' */
  } else if (rtb_TmpSignalConversionAtRP__a1) {
    /* Outputs for IfAction SubSystem: '<S31>/Discharge_iq' incorporates:
     *  ActionPort: '<S51>/Action Port'
     */
    /* SignalConversion generated from: '<S51>/DisChaisqDes' incorporates:
     *  Constant: '<S51>/CAL_MCF_DisChaisqDes_f32'
     */
    VAR_MCF_iqDes_f32 = CAL_MCF_DisChaisqDes_f32;

    /* End of Outputs for SubSystem: '<S31>/Discharge_iq' */
  } else {
    /* Outputs for IfAction SubSystem: '<S31>/iq_Cal' incorporates:
     *  ActionPort: '<S52>/Action Port'
     */
    /* Sum: '<S52>/Subtract' incorporates:
     *  Constant: '<S52>/CAL_MCF_isMax_f32'
     *  Product: '<S52>/Product'
     *  Product: '<S52>/Product1'
     */
    rtb_MCF_uaBase = CAL_MCF_isMax_f32 * CAL_MCF_isMax_f32 - VAR_MCF_idDes_f32 *
      VAR_MCF_idDes_f32;

    /* Switch: '<S52>/Switch' incorporates:
     *  Product: '<S52>/Product2'
     *  Product: '<S52>/Product4'
     *  RelationalOperator: '<S52>/Operator'
     *  Sqrt: '<S52>/Sqrt'
     */
    if (rtb_MCF_uaBase <= VAR_MCF_iqDes_f32 * VAR_MCF_iqDes_f32) {
      /* Switch: '<S52>/Switch3' incorporates:
       *  Constant: '<S52>/Constant'
       *  Constant: '<S52>/Constant1'
       */
      if (VAR_MCF_iqDes_f32 != 0.0F) {
        rtb_MCF_isqDesCalc_0 = 1;
      } else {
        rtb_MCF_isqDesCalc_0 = -1;
      }

      /* End of Switch: '<S52>/Switch3' */
      VAR_MCF_iqDes_f32 = sqrtf(rtb_MCF_uaBase) * (float32)rtb_MCF_isqDesCalc_0;
    }

    /* End of Switch: '<S52>/Switch' */
    /* End of Outputs for SubSystem: '<S31>/iq_Cal' */
  }

  /* End of If: '<S31>/If' */

  /* Sum: '<S56>/Subtract1' incorporates:
   *  Sum: '<S14>/Add3'
   *  Sum: '<S27>/Add1'
   */
  rtb_TmpSignalConversionAtRP__os = VAR_MCF_iqDes_f32 - VAR_MCF_iqAct_f32;

  /* Switch: '<S57>/Switch' incorporates:
   *  Constant: '<S56>/CAL_MCF_flgUseUsOver_b'
   *  Constant: '<S57>/CAL_MCF_udDecoupki_f32'
   *  Constant: '<S57>/CAL_MCF_udki_f32'
   *  Constant: '<S57>/Constant2'
   *  Product: '<S56>/Product2'
   *  Product: '<S56>/Product3'
   *  Product: '<S56>/Product7'
   *  Product: '<S57>/Product10'
   *  Product: '<S57>/Product11'
   *  Sum: '<S57>/Add2'
   *  Sum: '<S57>/Subtract2'
   *  Switch: '<S56>/Switch6'
   *  UnitDelay: '<S57>/Unit Delay'
   */
  if (VAR_MCF_SCF_flgInitEn_b) {
    SWC_MCF_DW.UnitDelay_DSTATE_g = 0.0F;
  } else {
    if (CAL_MCF_flgUseUsOver_b) {
      /* Switch: '<S56>/Switch6' incorporates:
       *  Constant: '<S56>/CAL_MCF_udOverGain_f32'
       *  Product: '<S56>/Product12'
       *  UnitDelay: '<S25>/Delay'
       */
      rtb_MCF_uaBase = CAL_MCF_udOverGain_f32 * SWC_MCF_DW.Delay_DSTATE;
    } else {
      /* Switch: '<S56>/Switch6' incorporates:
       *  Constant: '<S56>/Constant18'
       */
      rtb_MCF_uaBase = 0.0F;
    }

    SWC_MCF_DW.UnitDelay_DSTATE_g += (rtb_Product11 * rtb_Add_j2 *
      rtb_TmpSignalConversionAtRP__gi * CAL_MCF_udki_f32 * rtb_Product_dh -
      rtb_Product6 * VAR_MCF_MPC_Lq_f32 * rtb_TmpSignalConversionAtRP__os *
      rtb_Product11 * (rtb_Product_dh * CAL_MCF_udDecoupki_f32)) -
      rtb_MCF_uaBase;
  }

  /* End of Switch: '<S57>/Switch' */

  /* Sum: '<S57>/Add1' incorporates:
   *  Constant: '<S57>/CAL_MCF_udkp_f32'
   *  Product: '<S56>/Product'
   *  Product: '<S56>/Product1'
   *  Product: '<S57>/Product19'
   *  UnitDelay: '<S57>/Unit Delay'
   */
  rtb_MCF_uBCalc = (rtb_Product11 * VAR_MCF_MPC_Ld_f32 *
                    rtb_TmpSignalConversionAtRP__gi * CAL_MCF_udkp_f32 -
                    VAR_MCF_udRv_f32) + SWC_MCF_DW.UnitDelay_DSTATE_g;

  /* Switch: '<S57>/Switch1' incorporates:
   *  Constant: '<S56>/CAL_MCF_flgUseUsOver_b'
   *  Constant: '<S57>/CAL_MCF_uqDecoupki_f1'
   *  Constant: '<S57>/CAL_MCF_uqki_f1'
   *  Constant: '<S57>/Constant3'
   *  Product: '<S56>/Product13'
   *  Product: '<S56>/Product14'
   *  Product: '<S56>/Product9'
   *  Product: '<S57>/Product16'
   *  Product: '<S57>/Product9'
   *  Sum: '<S57>/Add3'
   *  Sum: '<S57>/Add4'
   *  Switch: '<S56>/Switch7'
   *  UnitDelay: '<S57>/Unit Delay1'
   */
  if (VAR_MCF_SCF_flgInitEn_b) {
    SWC_MCF_DW.UnitDelay1_DSTATE = 0.0F;
  } else {
    if (CAL_MCF_flgUseUsOver_b) {
      /* Switch: '<S56>/Switch7' incorporates:
       *  Constant: '<S56>/CAL_MCF_uqOverGain_f32'
       *  Product: '<S56>/Product10'
       *  UnitDelay: '<S25>/Delay1'
       */
      rtb_MCF_uaBase = CAL_MCF_uqOverGain_f32 * SWC_MCF_DW.Delay1_DSTATE;
    } else {
      /* Switch: '<S56>/Switch7' incorporates:
       *  Constant: '<S56>/Constant2'
       */
      rtb_MCF_uaBase = 0.0F;
    }

    SWC_MCF_DW.UnitDelay1_DSTATE += (rtb_Product6 * VAR_MCF_MPC_Ld_f32 *
      rtb_TmpSignalConversionAtRP__gi * rtb_Product11 * (rtb_Product_dh *
      CAL_MCF_uqDecoupki_f32) + rtb_Product11 * rtb_Add_j2 *
      rtb_TmpSignalConversionAtRP__os * CAL_MCF_uqki_f32 * rtb_Product_dh) -
      rtb_MCF_uaBase;
  }

  /* End of Switch: '<S57>/Switch1' */

  /* Sum: '<S58>/Add1' incorporates:
   *  Constant: '<S58>/CAL_MCF_cofFltWe_f32'
   *  Constant: '<S58>/Constant'
   *  Product: '<S58>/Product'
   *  Product: '<S58>/Product1'
   *  Sum: '<S58>/Add'
   *  UnitDelay: '<S58>/Unit Delay'
   */
  SWC_MCF_DW.UnitDelay_DSTATE_k = (1.0F - CAL_MCF_cofFltWe_f32) *
    SWC_MCF_DW.UnitDelay_DSTATE_k + rtb_Product6 * CAL_MCF_cofFltWe_f32;

  /* Product: '<S56>/Product17' incorporates:
   *  UnitDelay: '<S58>/Unit Delay'
   */
  VAR_MCF_EmfBack_f32 = SWC_MCF_DW.UnitDelay_DSTATE_k *
    rtb_TmpSignalConversionAtRP_S_e;

  /* Product: '<S56>/Product21' incorporates:
   *  Sum: '<S14>/Add3'
   */
  VAR_MCF_uqRv_f32 = rtb_TmpSignalConversionAtRP_S_j * VAR_MCF_iqAct_f32;

  /* Sum: '<S57>/Add6' incorporates:
   *  Constant: '<S57>/CAL_MCF_udki_f2'
   *  Product: '<S56>/Product15'
   *  Product: '<S56>/Product8'
   *  Product: '<S57>/Product20'
   *  Sum: '<S57>/Add5'
   *  UnitDelay: '<S57>/Unit Delay1'
   */
  rtb_TmpSignalConversionAtRP_S_j = ((rtb_Product11 * VAR_MCF_MPC_Lq_f32 *
    rtb_TmpSignalConversionAtRP__os * CAL_MCF_uqkp_f32 +
    SWC_MCF_DW.UnitDelay1_DSTATE) + VAR_MCF_EmfBack_f32) - VAR_MCF_uqRv_f32;

  /* Sqrt: '<S24>/Sqrt1' incorporates:
   *  Product: '<S24>/Product'
   *  Product: '<S24>/Product1'
   *  Sum: '<S24>/Add1'
   */
  rtb_MCF_uaBase = sqrtf(rtb_MCF_uBCalc * rtb_MCF_uBCalc +
    rtb_TmpSignalConversionAtRP_S_j * rtb_TmpSignalConversionAtRP_S_j);

  /* Saturate: '<S24>/Saturation2' */
  if (rtb_MCF_uaBase > 1.0E+6F) {
    rtb_MCF_uaBase = 1.0E+6F;
  } else {
    if (rtb_MCF_uaBase < 1.0E-6F) {
      rtb_MCF_uaBase = 1.0E-6F;
    }
  }

  /* End of Saturate: '<S24>/Saturation2' */

  /* Product: '<S24>/Divide2' */
  rtb_MCF_uaBase = rtb_MCF_ubBase / rtb_MCF_uaBase;

  /* Switch: '<S25>/Switch2' incorporates:
   *  Constant: '<S25>/Constant'
   *  Constant: '<S26>/Constant'
   *  RelationalOperator: '<S26>/Compare'
   *  Sum: '<S25>/Add'
   */
  rtb_TmpSignalConversionAtRP__a1 = (rtb_MCF_uaBase - 1.0F < 0.0F);

  /* Switch: '<S25>/Switch1' incorporates:
   *  Constant: '<S25>/CAL_MCF_UsdScalSet_f32'
   *  Constant: '<S25>/CAL_MCF_UsqScalSet_f32'
   *  Constant: '<S25>/CAL_MCF_flgUseUsdqSet_b'
   *  Switch: '<S25>/Switch3'
   *  Switch: '<S25>/Switch4'
   *  Switch: '<S25>/Switch5'
   */
  if (CAL_MCF_flgUseUsdqSet_b) {
    VAR_MCF_udDes_f32 = CAL_MCF_UsdScalSet_f32;
    VAR_MCF_uqDes_f32 = CAL_MCF_UsqScalSet_f32;
  } else if (rtb_TmpSignalConversionAtRP__a1) {
    /* Switch: '<S25>/Switch3' incorporates:
     *  Product: '<S25>/Product'
     */
    VAR_MCF_udDes_f32 = rtb_MCF_uaBase * rtb_MCF_uBCalc;

    /* Switch: '<S25>/Switch5' incorporates:
     *  Product: '<S25>/Product2'
     */
    VAR_MCF_uqDes_f32 = rtb_MCF_uaBase * rtb_TmpSignalConversionAtRP_S_j;
  } else {
    /* Switch: '<S25>/Switch3' */
    VAR_MCF_udDes_f32 = rtb_MCF_uBCalc;

    /* Switch: '<S25>/Switch5' */
    VAR_MCF_uqDes_f32 = rtb_TmpSignalConversionAtRP_S_j;
  }

  /* End of Switch: '<S25>/Switch1' */

  /* Sqrt: '<S23>/Sqrt' incorporates:
   *  Product: '<S23>/Product5'
   *  Product: '<S23>/Product6'
   *  Sum: '<S23>/Add1'
   *  Sum: '<S25>/Add3'
   *  Sum: '<S25>/Add4'
   */
  rtb_MCF_uaBase = sqrtf(VAR_MCF_udDes_f32 * VAR_MCF_udDes_f32 +
    VAR_MCF_uqDes_f32 * VAR_MCF_uqDes_f32);

  /* Saturate: '<S23>/Saturation' */
  if (rtb_MCF_uaBase > 1023.0F) {
    rtb_MCF_uaBase = 1023.0F;
  } else {
    if (rtb_MCF_uaBase < 0.01F) {
      rtb_MCF_uaBase = 0.01F;
    }
  }

  /* End of Saturate: '<S23>/Saturation' */

  /* Sum: '<S23>/Add' incorporates:
   *  Constant: '<S23>/Constant'
   *  Product: '<S23>/Divide'
   */
  VAR_MCF_UsUseRateReal_f32 = rtb_MCF_ubBase / rtb_MCF_uaBase - 1.0F;

  /* Sum: '<S25>/Add1' incorporates:
   *  UnitDelay: '<S25>/Delay'
   */
  SWC_MCF_DW.Delay_DSTATE = rtb_MCF_uBCalc - VAR_MCF_udDes_f32;

  /* Sum: '<S25>/Add2' incorporates:
   *  UnitDelay: '<S25>/Delay1'
   */
  SWC_MCF_DW.Delay1_DSTATE = rtb_TmpSignalConversionAtRP_S_j - VAR_MCF_uqDes_f32;

  /* Sum: '<S41>/Add1' incorporates:
   *  Constant: '<S41>/CAL_MCF_cofFltWe_f32'
   *  Constant: '<S41>/Constant'
   *  Product: '<S41>/Product'
   *  Product: '<S41>/Product1'
   *  Sum: '<S41>/Add'
   *  UnitDelay: '<S41>/Unit Delay'
   */
  SWC_MCF_DW.UnitDelay_DSTATE_o = (1.0F - CAL_MCF_cofFltPowerHeat_f32) *
    SWC_MCF_DW.UnitDelay_DSTATE_o + VAR_MCF_PowerMotHeat_f32 *
    CAL_MCF_cofFltPowerHeat_f32;

  /* Logic: '<S38>/Logical Operator2' */
  rtb_TmpSignalConversionAtRP__a1 = !VAR_MCF_flgMotHeat_b;

  /* Switch: '<S38>/Switch' incorporates:
   *  Constant: '<S38>/Constant'
   *  Constant: '<S38>/Constant4'
   *  Constant: '<S38>/Constant6'
   *  Logic: '<S38>/Logical Operator'
   *  Logic: '<S38>/Logical Operator1'
   *  Logic: '<S38>/Logical Operator3'
   *  RelationalOperator: '<S38>/Relational Operator'
   *  RelationalOperator: '<S38>/Relational Operator2'
   *  Sum: '<S38>/Subtract'
   *  Switch: '<S38>/Switch1'
   *  Switch: '<S38>/Switch2'
   *  UnitDelay: '<S41>/Unit Delay'
   */
  if ((SWC_MCF_B.uDLookupTable < 100.0F) && rtb_TmpSignalConversionAtRP__a1) {
    VAR_MCF_TMAhtChsts_f32 = CAL_MCF_Part_ActiveHeat_u8;
  } else if (rtb_TmpSignalConversionAtRP__a1 && rtb_TmpSignalConversionAtRP_S_o)
  {
    /* Switch: '<S38>/Switch1' incorporates:
     *  Constant: '<S38>/Constant5'
     */
    VAR_MCF_TMAhtChsts_f32 = CAL_MCF_Non_ActiveHeat_u8;
  } else if (VAR_MCF_flgMotHeat_b && (VAR_MCF_PCUHeaterPower_f32 -
              SWC_MCF_DW.UnitDelay_DSTATE_o <= CAL_MCF_DeltaPower_f32)) {
    /* Switch: '<S38>/Switch2' incorporates:
     *  Constant: '<S38>/Constant2'
     *  Switch: '<S38>/Switch1'
     */
    VAR_MCF_TMAhtChsts_f32 = CAL_MCF_ActiveHeatNormal_u8;
  } else {
    /* Switch: '<S38>/Switch1' incorporates:
     *  Constant: '<S38>/Constant3'
     *  Switch: '<S38>/Switch2'
     */
    VAR_MCF_TMAhtChsts_f32 = CAL_MCF_ActiveHeatInit_u8;
  }

  /* End of Switch: '<S38>/Switch' */

  /* Sum: '<S119>/Add2' incorporates:
   *  Constant: '<S119>/Constant6'
   *  UnitDelay: '<S119>/Unit Delay1'
   */
  SWC_MCF_DW.UnitDelay1_DSTATE_l++;

  /* Switch: '<S119>/Switch2' incorporates:
   *  Constant: '<S119>/Constant4'
   *  Constant: '<S119>/Constant5'
   *  RelationalOperator: '<S119>/Relational Operator1'
   *  UnitDelay: '<S119>/Unit Delay1'
   */
  if (SWC_MCF_DW.UnitDelay1_DSTATE_l > 1024) {
    SWC_MCF_DW.UnitDelay1_DSTATE_l = 0U;
  }

  /* End of Switch: '<S119>/Switch2' */

  /* Switch: '<S119>/Switch1' incorporates:
   *  Constant: '<S119>/CAL_MCF_flgRpwmFrqRandom_b'
   *  Constant: '<S119>/Constant'
   *  Constant: '<S119>/Constant3'
   *  Constant: '<S119>/Constant8'
   *  Constant: '<S119>/Constant9'
   *  Inport: '<Root>/RP_SWC_MPC_MPC_CofRandomPwm'
   *  Product: '<S119>/Product'
   *  Selector: '<S119>/Selector'
   *  Sum: '<S119>/Add'
   *  Sum: '<S119>/Add1'
   *  UnitDelay: '<S119>/Unit Delay1'
   */
  if (CAL_MCF_flgRpwmFrqRandom_b) {
    Rte_Read_RP_SWC_MPC_MPC_CofRandomPwm(&rtb_Subtract_cm);
    rtb_TmpSignalConversionAtRP_S_j =
      (rtCP_Constant_Value_o0[SWC_MCF_DW.UnitDelay1_DSTATE_l - 1] - 1.0F) *
      rtb_Subtract_cm + 1.0F;
  } else {
    rtb_TmpSignalConversionAtRP_S_j = 1.0F;
  }

  /* End of Switch: '<S119>/Switch1' */

  /* Product: '<S119>/Product2' */
  rtb_MCF_frqPwmCalc_j *= rtb_TmpSignalConversionAtRP_S_j;

  /* Sum: '<S185>/Subtract' incorporates:
   *  UnitDelay: '<S185>/Unit Delay2'
   */
  rtb_Subtract_cm = rtb_MCF_frqPwmCalc_j - SWC_MCF_DW.UnitDelay2_DSTATE_c;

  /* Switch: '<S185>/Switch3' incorporates:
   *  Constant: '<S185>/CAL_MCF_FrqRmp_f32'
   *  RelationalOperator: '<S185>/Relational Operator'
   *  Sum: '<S185>/Add1'
   *  UnitDelay: '<S185>/Unit Delay2'
   */
  if (rtb_Subtract_cm <= CAL_MCF_FrqRmp_f32) {
    /* Switch: '<S185>/Switch4' incorporates:
     *  Product: '<S185>/Product1'
     *  RelationalOperator: '<S185>/Relational Operator2'
     */
    if (-rtb_Subtract_cm <= CAL_MCF_FrqRmp_f32) {
      /* UnitDelay: '<S185>/Unit Delay2' */
      SWC_MCF_DW.UnitDelay2_DSTATE_c = rtb_MCF_frqPwmCalc_j;
    } else {
      /* UnitDelay: '<S185>/Unit Delay2' incorporates:
       *  Sum: '<S185>/Add3'
       */
      SWC_MCF_DW.UnitDelay2_DSTATE_c -= CAL_MCF_FrqRmp_f32;
    }

    /* End of Switch: '<S185>/Switch4' */
  } else {
    SWC_MCF_DW.UnitDelay2_DSTATE_c += CAL_MCF_FrqRmp_f32;
  }

  /* End of Switch: '<S185>/Switch3' */

  /* Saturate: '<S119>/Saturation' incorporates:
   *  UnitDelay: '<S185>/Unit Delay2'
   */
  if (SWC_MCF_DW.UnitDelay2_DSTATE_c > 10000.0F) {
    rtb_MCF_frqPwmCalc_j = 10000.0F;
  } else if (SWC_MCF_DW.UnitDelay2_DSTATE_c < 2000.0F) {
    rtb_MCF_frqPwmCalc_j = 2000.0F;
  } else {
    rtb_MCF_frqPwmCalc_j = SWC_MCF_DW.UnitDelay2_DSTATE_c;
  }

  /* End of Saturate: '<S119>/Saturation' */

  /* Product: '<S119>/Divide' incorporates:
   *  Constant: '<S119>/Constant1'
   */
  rtb_Subtract_cm = 1.0F / rtb_MCF_frqPwmCalc_j;

  /* Switch: '<S82>/Switch' incorporates:
   *  Constant: '<S82>/CAL_MCF_SpdOffDeadCpn_f32'
   *  Constant: '<S82>/CAL_MCF_SpdOnDeadCpn_f32'
   *  Constant: '<S82>/Turn off dead compensation flag according to speed '
   *  RelationalOperator: '<S82>/Relational Operator'
   *  RelationalOperator: '<S82>/Relational Operator1'
   *  UnitDelay: '<S82>/Unit Delay'
   */
  if (rtb_Saturation_e > CAL_MCF_SpdOffDeadCpn_f32) {
    SWC_MCF_DW.UnitDelay_DSTATE_gm = false;
  } else {
    SWC_MCF_DW.UnitDelay_DSTATE_gm = ((rtb_Saturation_e <=
      CAL_MCF_SpdOnDeadCpn_f32) || SWC_MCF_DW.UnitDelay_DSTATE_gm);
  }

  /* End of Switch: '<S82>/Switch' */

  /* Logic: '<S81>/Logical Operator' incorporates:
   *  Constant: '<S80>/CAL_MCF_TrqOffDeadCpn_f32'
   *  Constant: '<S81>/CAL_MCF_FlgUseDeadCpn_b'
   *  Constant: '<S81>/Isd is negative'
   *  RelationalOperator: '<S80>/Relational Operator'
   *  RelationalOperator: '<S81>/Relational Operator'
   *  Sum: '<S27>/Add'
   *  UnitDelay: '<S82>/Unit Delay'
   */
  VAR_MCF_FlgDeadCpn_b = ((rtb_Subtract2_k <= CAL_MCF_TrqOffDeadCpn_f32) &&
    SWC_MCF_DW.UnitDelay_DSTATE_gm && CAL_MCF_FlgUseDeadCpn_b &&
    (VAR_MCF_idDes_f32 <= 0.0F));

  /* Outputs for Enabled SubSystem: '<S60>/Calculate dead compensation voltage' incorporates:
   *  EnablePort: '<S63>/Enable'
   */
  /* Switch generated from: '<S60>/Switch' incorporates:
   *  Constant: '<S60>/Set voltage alpha axis is zone '
   *  Constant: '<S60>/Set voltage beta axis is zone '
   */
  if (VAR_MCF_FlgDeadCpn_b) {
    /* Switch: '<S74>/Switch' incorporates:
     *  Abs: '<S74>/Abs'
     *  Constant: '<S74>/Constant'
     *  Constant: '<S75>/Constant'
     *  RelationalOperator: '<S75>/Compare'
     *  Sum: '<S27>/Add1'
     */
    if (fabsf(VAR_MCF_iqDes_f32) <= 0.0001F) {
      rtb_TmpSignalConversionAtRP_S_j = 0.0001F;
    } else {
      rtb_TmpSignalConversionAtRP_S_j = VAR_MCF_iqDes_f32;
    }

    /* End of Switch: '<S74>/Switch' */

    /* Gain: '<S74>/Gain3' incorporates:
     *  Constant: '<S77>/Constant'
     *  RelationalOperator: '<S77>/Compare'
     */
    rtb_Gain3_o = (uint8)((rtb_TmpSignalConversionAtRP_S_j >= 0.0F) << 7);

    /* Switch: '<S74>/Switch1' incorporates:
     *  Abs: '<S74>/Abs1'
     *  Constant: '<S74>/Constant1'
     *  Constant: '<S76>/Constant'
     *  RelationalOperator: '<S76>/Compare'
     *  Sum: '<S27>/Add'
     */
    if (fabsf(VAR_MCF_idDes_f32) <= 0.0001F) {
      rtb_MCF_uBCalc = 0.0001F;
    } else {
      rtb_MCF_uBCalc = VAR_MCF_idDes_f32;
    }

    /* End of Switch: '<S74>/Switch1' */

    /* Gain: '<S74>/Gain1' incorporates:
     *  Constant: '<S78>/Constant'
     *  RelationalOperator: '<S78>/Compare'
     */
    rtb_Gain1_l = (uint8)((rtb_MCF_uBCalc >= 0.0F) << 7);

    /* Product: '<S74>/Divide' */
    rtb_TmpSignalConversionAtRP_S_j /= rtb_MCF_uBCalc;

    /* Abs: '<S74>/Abs2' */
    rtb_MCF_uBCalc = fabsf(rtb_TmpSignalConversionAtRP_S_j);

    /* RelationalOperator: '<S79>/Compare' incorporates:
     *  Constant: '<S79>/Constant'
     */
    rtb_TmpSignalConversionAtRP__a1 = (rtb_MCF_uBCalc >= 1.0F);

    /* Switch: '<S74>/Switch2' incorporates:
     *  Constant: '<S74>/Constant2'
     *  Product: '<S74>/Divide1'
     */
    if (rtb_TmpSignalConversionAtRP__a1) {
      rtb_MCF_uBCalc = 1.0F / rtb_MCF_uBCalc;
    }

    /* End of Switch: '<S74>/Switch2' */

    /* MultiPortSwitch: '<S74>/Multiport Switch' incorporates:
     *  Constant: '<S74>/Constant10'
     *  Constant: '<S74>/Constant3'
     *  Constant: '<S74>/Constant4'
     *  Constant: '<S74>/Constant5'
     *  Constant: '<S74>/Constant7'
     *  Constant: '<S74>/Constant8'
     *  Constant: '<S74>/Constant9'
     *  Gain: '<S74>/Gain2'
     *  Gain: '<S74>/Gain4'
     *  LookupNDDirect: '<S74>/Direct Lookup Table (n-D)'
     *  Sum: '<S74>/Add'
     *  Sum: '<S74>/Add1'
     *  Sum: '<S74>/Add2'
     *  Sum: '<S74>/Add3'
     *  Sum: '<S74>/Add5'
     *  Sum: '<S74>/Add6'
     *  Sum: '<S74>/Add7'
     *  Sum: '<S74>/Add8'
     *
     * About '<S74>/Direct Lookup Table (n-D)':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     */
    switch ((sint32)((((((uint32)rtb_Gain1_l << 1) + rtb_Gain3_o) + ((uint32)
                (rtb_TmpSignalConversionAtRP__a1 << 7) << 2)) >> 2) >> 5)) {
     case 0:
      /* LookupNDDirect: '<S74>/Direct Lookup Table (n-D)' incorporates:
       *  Gain: '<S74>/Gain'
       *
       * About '<S74>/Direct Lookup Table (n-D)':
       *  1-dimensional Direct Look-Up returning a Scalar,
       *
       *     Remove protection against out-of-range input in generated code: 'off'
       */
      rtb_MCF_uaBase = 1024.0F * rtb_MCF_uBCalc;
      if (rtb_MCF_uaBase > 1024.0F) {
        rtb_MCF_uaBase = 1024.0F;
      }

      rtb_MCF_uBCalc = (float32)(58672U * rtCP_DirectLookupTablenD_table_
        [(sint32)rtb_MCF_uaBase]) * 1.49011612E-8F + 180.0F;
      break;

     case 1:
      /* LookupNDDirect: '<S74>/Direct Lookup Table (n-D)' incorporates:
       *  Gain: '<S74>/Gain'
       *
       * About '<S74>/Direct Lookup Table (n-D)':
       *  1-dimensional Direct Look-Up returning a Scalar,
       *
       *     Remove protection against out-of-range input in generated code: 'off'
       */
      rtb_MCF_uaBase = 1024.0F * rtb_MCF_uBCalc;
      if (rtb_MCF_uaBase > 1024.0F) {
        rtb_MCF_uaBase = 1024.0F;
      }

      rtb_MCF_uBCalc = 180.0F - (float32)(58672U *
        rtCP_DirectLookupTablenD_table_[(sint32)rtb_MCF_uaBase]) *
        1.49011612E-8F;
      break;

     case 2:
      /* LookupNDDirect: '<S74>/Direct Lookup Table (n-D)' incorporates:
       *  Gain: '<S74>/Gain'
       *
       * About '<S74>/Direct Lookup Table (n-D)':
       *  1-dimensional Direct Look-Up returning a Scalar,
       *
       *     Remove protection against out-of-range input in generated code: 'off'
       */
      rtb_MCF_uaBase = 1024.0F * rtb_MCF_uBCalc;
      if (rtb_MCF_uaBase > 1024.0F) {
        rtb_MCF_uaBase = 1024.0F;
      }

      rtb_MCF_uBCalc = 360.0F - (float32)(58672U *
        rtCP_DirectLookupTablenD_table_[(sint32)rtb_MCF_uaBase]) *
        1.49011612E-8F;
      break;

     case 3:
      /* LookupNDDirect: '<S74>/Direct Lookup Table (n-D)' incorporates:
       *  Gain: '<S74>/Gain'
       *
       * About '<S74>/Direct Lookup Table (n-D)':
       *  1-dimensional Direct Look-Up returning a Scalar,
       *
       *     Remove protection against out-of-range input in generated code: 'off'
       */
      rtb_MCF_uaBase = 1024.0F * rtb_MCF_uBCalc;
      if (rtb_MCF_uaBase > 1024.0F) {
        rtb_MCF_uaBase = 1024.0F;
      }

      rtb_MCF_uBCalc = (float32)(58672U * rtCP_DirectLookupTablenD_table_
        [(sint32)rtb_MCF_uaBase]) * 1.49011612E-8F;
      break;

     case 4:
      /* LookupNDDirect: '<S74>/Direct Lookup Table (n-D)' incorporates:
       *  Gain: '<S74>/Gain'
       *
       * About '<S74>/Direct Lookup Table (n-D)':
       *  1-dimensional Direct Look-Up returning a Scalar,
       *
       *     Remove protection against out-of-range input in generated code: 'off'
       */
      rtb_MCF_uaBase = 1024.0F * rtb_MCF_uBCalc;
      if (rtb_MCF_uaBase > 1024.0F) {
        rtb_MCF_uaBase = 1024.0F;
      }

      rtb_MCF_uBCalc = 270.0F - (float32)(58672U *
        rtCP_DirectLookupTablenD_table_[(sint32)rtb_MCF_uaBase]) *
        1.49011612E-8F;
      break;

     case 5:
      /* LookupNDDirect: '<S74>/Direct Lookup Table (n-D)' incorporates:
       *  Gain: '<S74>/Gain'
       *
       * About '<S74>/Direct Lookup Table (n-D)':
       *  1-dimensional Direct Look-Up returning a Scalar,
       *
       *     Remove protection against out-of-range input in generated code: 'off'
       */
      rtb_MCF_uaBase = 1024.0F * rtb_MCF_uBCalc;
      if (rtb_MCF_uaBase > 1024.0F) {
        rtb_MCF_uaBase = 1024.0F;
      }

      rtb_MCF_uBCalc = (float32)(58672U * rtCP_DirectLookupTablenD_table_
        [(sint32)rtb_MCF_uaBase]) * 1.49011612E-8F + 90.0F;
      break;

     case 6:
      /* LookupNDDirect: '<S74>/Direct Lookup Table (n-D)' incorporates:
       *  Gain: '<S74>/Gain'
       *
       * About '<S74>/Direct Lookup Table (n-D)':
       *  1-dimensional Direct Look-Up returning a Scalar,
       *
       *     Remove protection against out-of-range input in generated code: 'off'
       */
      rtb_MCF_uaBase = 1024.0F * rtb_MCF_uBCalc;
      if (rtb_MCF_uaBase > 1024.0F) {
        rtb_MCF_uaBase = 1024.0F;
      }

      rtb_MCF_uBCalc = (float32)(58672U * rtCP_DirectLookupTablenD_table_
        [(sint32)rtb_MCF_uaBase]) * 1.49011612E-8F + 270.0F;
      break;

     default:
      /* LookupNDDirect: '<S74>/Direct Lookup Table (n-D)' incorporates:
       *  Gain: '<S74>/Gain'
       *
       * About '<S74>/Direct Lookup Table (n-D)':
       *  1-dimensional Direct Look-Up returning a Scalar,
       *
       *     Remove protection against out-of-range input in generated code: 'off'
       */
      rtb_MCF_uaBase = 1024.0F * rtb_MCF_uBCalc;
      if (rtb_MCF_uaBase > 1024.0F) {
        rtb_MCF_uaBase = 1024.0F;
      }

      rtb_MCF_uBCalc = 90.0F - (float32)(58672U *
        rtCP_DirectLookupTablenD_table_[(sint32)rtb_MCF_uaBase]) *
        1.49011612E-8F;
      break;
    }

    /* End of MultiPortSwitch: '<S74>/Multiport Switch' */

    /* Sum: '<S68>/Add7' */
    rtb_MCF_uBCalc += VAR_MCF_agRtrEe_f32;

    /* DataTypeConversion: '<S73>/Data Type Conversion2' incorporates:
     *  Constant: '<S73>/360 degrees is the norm'
     *  Product: '<S73>/Divide1'
     */
    rtb_MCF_uaBase = fmodf(floorf(rtb_MCF_uBCalc * 0.00277777785F), 256.0F);

    /* Sum: '<S73>/Add3' incorporates:
     *  Constant: '<S73>/360 degrees is the norm1'
     *  DataTypeConversion: '<S73>/Data Type Conversion2'
     *  Product: '<S73>/Divide3'
     */
    rtb_MCF_uBCalc -= (float32)(rtb_MCF_uaBase < 0.0F ? (sint32)(sint8)-(sint8)
      (uint8)-rtb_MCF_uaBase : (sint32)(sint8)(uint8)rtb_MCF_uaBase) * 360.0F;

    /* Sum: '<S65>/Add' incorporates:
     *  Constant: '<S65>/CAL_MCF_AgDiffCurrSec_f32'
     */
    rtb_MCF_ubBase = rtb_MCF_uBCalc - CAL_MCF_AgDiffCurrSec_f32;

    /* Chart: '<S65>/Chart' */
    if ((rtb_MCF_ubBase > MCF_ANGLE_CURRENT_30) && (rtb_MCF_ubBase <=
         MCF_ANGLE_CURRENT_90)) {
      rtb_Gain3_o = ((uint8)MCF_CURRENT_SECTOR_2);
    } else if ((rtb_MCF_ubBase > MCF_ANGLE_CURRENT_90) && (rtb_MCF_ubBase <=
                MCF_ANGLE_CURRENT_150)) {
      rtb_Gain3_o = ((uint8)MCF_CURRENT_SECTOR_3);
    } else if ((rtb_MCF_ubBase > MCF_ANGLE_CURRENT_150) && (rtb_MCF_ubBase <=
                MCF_ANGLE_CURRENT_210)) {
      rtb_Gain3_o = ((uint8)MCF_CURRENT_SECTOR_4);
    } else if ((rtb_MCF_ubBase > MCF_ANGLE_CURRENT_210) && (rtb_MCF_ubBase <=
                MCF_ANGLE_CURRENT_270)) {
      rtb_Gain3_o = ((uint8)MCF_CURRENT_SECTOR_5);
    } else if ((rtb_MCF_ubBase > MCF_ANGLE_CURRENT_270) && (rtb_MCF_ubBase <=
                MCF_ANGLE_CURRENT_330)) {
      rtb_Gain3_o = ((uint8)MCF_CURRENT_SECTOR_6);
    } else {
      rtb_Gain3_o = ((uint8)MCF_CURRENT_SECTOR_1);
    }

    /* End of Chart: '<S65>/Chart' */

    /* Sum: '<S65>/Add1' incorporates:
     *  Constant: '<S65>/The middle angle of the sector1'
     */
    rtb_Gain3_o--;

    /* LookupNDDirect: '<S65>/Direct Lookup Table (n-D)' incorporates:
     *  LookupNDDirect: '<S65>/Direct Lookup Table (n-D)1'
     *
     * About '<S65>/Direct Lookup Table (n-D)':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     *
     * About '<S65>/Direct Lookup Table (n-D)1':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     */
    if (rtb_Gain3_o < 5) {
      rtb_Gain1_l = rtb_Gain3_o;
      y = rtb_Gain3_o;
    } else {
      rtb_Gain1_l = 5U;
      y = 5U;
    }

    /* Product: '<S65>/Product1' incorporates:
     *  Constant: '<S65>/  of '
     *  LookupNDDirect: '<S65>/Direct Lookup Table (n-D)'
     *  LookupNDDirect: '<S65>/Direct Lookup Table (n-D)1'
     *  Sum: '<S65>/Subtract1'
     *
     * About '<S65>/Direct Lookup Table (n-D)':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     *
     * About '<S65>/Direct Lookup Table (n-D)1':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     */
    rtb_TmpSignalConversionAtRP_S_j =
      (rtCP_DirectLookupTablenD_table[rtb_Gain1_l] -
       rtCP_DirectLookupTablenD1_table[y]) * 0.5F;

    /* Lookup_n-D: '<S65>/Angle range of dead compensation' */
    rtb_MCF_ubBase = look1_iflf_binlcpw(rtb_Subtract2_k, ((const float32 *)
      &(CAL_MCF_AgRangeDeadCpnX_Trq_af32[0])), ((const float32 *)
      &(CAL_MCF_AgRangeDeadCpnY_Ag_af32[0])), 6U);

    /* DataTypeConversion: '<S70>/Data Type Conversion2' incorporates:
     *  Constant: '<S70>/60 degrees is the norm1'
     *  Product: '<S70>/Divide1'
     */
    rtb_MCF_uaBase = fmodf(floorf(rtb_MCF_uBCalc * 0.0166666675F), 256.0F);

    /* Sum: '<S65>/Add11' incorporates:
     *  Constant: '<S65>/The middle angle of the sector'
     *  Constant: '<S70>/60 degrees is the norm'
     *  DataTypeConversion: '<S70>/Data Type Conversion2'
     *  Product: '<S70>/Divide3'
     *  Sum: '<S70>/Add3'
     */
    rtb_MCF_uaBase = (rtb_MCF_uBCalc - (float32)(rtb_MCF_uaBase < 0.0F ? (sint32)
      (sint8)-(sint8)(uint8)-rtb_MCF_uaBase : (sint32)(sint8)(uint8)
      rtb_MCF_uaBase) * 60.0F) - 30.0F;

    /* Switch: '<S66>/Switch3' incorporates:
     *  Abs: '<S66>/Abs3'
     *  Constant: '<S71>/Constant'
     *  RelationalOperator: '<S66>/Relational Operator4'
     *  RelationalOperator: '<S71>/Compare'
     *  Switch: '<S66>/Switch6'
     */
    if (rtb_MCF_uaBase < 0.0F) {
      /* Abs: '<S66>/Abs2' */
      rtb_MCF_uBCalc = fabsf(rtb_MCF_uaBase);

      /* Switch: '<S66>/Switch5' incorporates:
       *  Constant: '<S66>/Circuit sector normalization'
       *  LookupNDDirect: '<S65>/Direct Lookup Table (n-D)'
       *  Product: '<S66>/Divide2'
       *  Product: '<S66>/Product2'
       *  RelationalOperator: '<S66>/Relational Operator2'
       *  Sum: '<S66>/Add5'
       *  Sum: '<S66>/Add6'
       *
       * About '<S65>/Direct Lookup Table (n-D)':
       *  1-dimensional Direct Look-Up returning a Scalar,
       *
       *     Remove protection against out-of-range input in generated code: 'off'
       */
      if (rtb_MCF_uBCalc < rtb_MCF_ubBase) {
        rtb_MCF_uBCalc = rtCP_DirectLookupTablenD_table[rtb_Gain1_l] - (1.0F -
          rtb_MCF_uBCalc / rtb_MCF_ubBase) * rtb_TmpSignalConversionAtRP_S_j;
      } else {
        rtb_MCF_uBCalc = rtCP_DirectLookupTablenD_table[rtb_Gain1_l];
      }

      /* End of Switch: '<S66>/Switch5' */
    } else if (rtb_MCF_uaBase < rtb_MCF_ubBase) {
      /* Switch: '<S66>/Switch6' incorporates:
       *  Abs: '<S66>/Abs3'
       *  Constant: '<S66>/Circuit sector normalization 1'
       *  LookupNDDirect: '<S65>/Direct Lookup Table (n-D)1'
       *  Product: '<S66>/Divide3'
       *  Product: '<S66>/Product3'
       *  Sum: '<S66>/Add8'
       *  Sum: '<S66>/Add9'
       *
       * About '<S65>/Direct Lookup Table (n-D)1':
       *  1-dimensional Direct Look-Up returning a Scalar,
       *
       *     Remove protection against out-of-range input in generated code: 'off'
       */
      rtb_MCF_uBCalc = (1.0F - rtb_MCF_uaBase / rtb_MCF_ubBase) *
        rtb_TmpSignalConversionAtRP_S_j + rtCP_DirectLookupTablenD1_table[y];
    } else {
      /* Switch: '<S66>/Switch6' incorporates:
       *  LookupNDDirect: '<S65>/Direct Lookup Table (n-D)1'
       *
       * About '<S65>/Direct Lookup Table (n-D)1':
       *  1-dimensional Direct Look-Up returning a Scalar,
       *
       *     Remove protection against out-of-range input in generated code: 'off'
       */
      rtb_MCF_uBCalc = rtCP_DirectLookupTablenD1_table[y];
    }

    /* End of Switch: '<S66>/Switch3' */

    /* Product: '<S65>/Product' incorporates:
     *  Constant: '<S65>/CAL_MCF_DeadTimeCpn_f32'
     *  Constant: '<S65>/The conversion factor between seconds and microseconds'
     *  Product: '<S65>/Divide1'
     *  Product: '<S65>/Product3'
     *  Sum: '<S13>/Add'
     */
    rtb_TmpSignalConversionAtRP_S_j = CAL_MCF_DeadTimeCpn_f32 * 1.0E-6F /
      rtb_Subtract_cm * VAR_MCF_uDcLnk_f32;

    /* Product: '<S66>/Product1' */
    SWC_MCF_B.MCF_uAlphaDeadCpn = rtb_MCF_uBCalc *
      rtb_TmpSignalConversionAtRP_S_j;

    /* LookupNDDirect: '<S65>/Direct Lookup Table (n-D)2' incorporates:
     *  LookupNDDirect: '<S65>/Direct Lookup Table (n-D)3'
     *
     * About '<S65>/Direct Lookup Table (n-D)2':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     *
     * About '<S65>/Direct Lookup Table (n-D)3':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     */
    if (rtb_Gain3_o < 5) {
      rtb_Gain1_l = rtb_Gain3_o;
    } else {
      rtb_Gain3_o = 5U;
      rtb_Gain1_l = 5U;
    }

    /* Product: '<S65>/Product6' incorporates:
     *  Constant: '<S65>/Between two coefficients of alpha1'
     *  LookupNDDirect: '<S65>/Direct Lookup Table (n-D)2'
     *  LookupNDDirect: '<S65>/Direct Lookup Table (n-D)3'
     *  Sum: '<S65>/Subtract2'
     *
     * About '<S65>/Direct Lookup Table (n-D)2':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     *
     * About '<S65>/Direct Lookup Table (n-D)3':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     */
    rtb_MCF_uBCalc = (rtCP_DirectLookupTablenD2_table[rtb_Gain3_o] -
                      rtCP_DirectLookupTablenD3_table[rtb_Gain1_l]) * 0.5F;

    /* Switch: '<S67>/Switch3' incorporates:
     *  Abs: '<S67>/Abs3'
     *  Constant: '<S72>/Constant'
     *  RelationalOperator: '<S67>/Relational Operator4'
     *  RelationalOperator: '<S72>/Compare'
     *  Switch: '<S67>/Switch6'
     */
    if (rtb_MCF_uaBase < 0.0F) {
      /* Abs: '<S67>/Abs2' */
      rtb_MCF_uaBase = fabsf(rtb_MCF_uaBase);

      /* Switch: '<S67>/Switch5' incorporates:
       *  Constant: '<S67>/Circuit sector normalization'
       *  LookupNDDirect: '<S65>/Direct Lookup Table (n-D)2'
       *  Product: '<S67>/Divide2'
       *  Product: '<S67>/Product2'
       *  RelationalOperator: '<S67>/Relational Operator2'
       *  Sum: '<S67>/Add5'
       *  Sum: '<S67>/Add6'
       *
       * About '<S65>/Direct Lookup Table (n-D)2':
       *  1-dimensional Direct Look-Up returning a Scalar,
       *
       *     Remove protection against out-of-range input in generated code: 'off'
       */
      if (rtb_MCF_uaBase < rtb_MCF_ubBase) {
        rtb_MCF_uBCalc = rtCP_DirectLookupTablenD2_table[rtb_Gain3_o] - (1.0F -
          rtb_MCF_uaBase / rtb_MCF_ubBase) * rtb_MCF_uBCalc;
      } else {
        rtb_MCF_uBCalc = rtCP_DirectLookupTablenD2_table[rtb_Gain3_o];
      }

      /* End of Switch: '<S67>/Switch5' */
    } else if (rtb_MCF_uaBase < rtb_MCF_ubBase) {
      /* Switch: '<S67>/Switch6' incorporates:
       *  Abs: '<S67>/Abs3'
       *  Constant: '<S67>/Circuit sector normalization 1'
       *  LookupNDDirect: '<S65>/Direct Lookup Table (n-D)3'
       *  Product: '<S67>/Divide3'
       *  Product: '<S67>/Product3'
       *  Sum: '<S67>/Add8'
       *  Sum: '<S67>/Add9'
       *
       * About '<S65>/Direct Lookup Table (n-D)3':
       *  1-dimensional Direct Look-Up returning a Scalar,
       *
       *     Remove protection against out-of-range input in generated code: 'off'
       */
      rtb_MCF_uBCalc = (1.0F - rtb_MCF_uaBase / rtb_MCF_ubBase) * rtb_MCF_uBCalc
        + rtCP_DirectLookupTablenD3_table[rtb_Gain1_l];
    } else {
      /* Switch: '<S67>/Switch6' incorporates:
       *  LookupNDDirect: '<S65>/Direct Lookup Table (n-D)3'
       *
       * About '<S65>/Direct Lookup Table (n-D)3':
       *  1-dimensional Direct Look-Up returning a Scalar,
       *
       *     Remove protection against out-of-range input in generated code: 'off'
       */
      rtb_MCF_uBCalc = rtCP_DirectLookupTablenD3_table[rtb_Gain1_l];
    }

    /* End of Switch: '<S67>/Switch3' */

    /* Product: '<S67>/Product1' */
    SWC_MCF_B.MCF_uBetaDeadCpn = rtb_MCF_uBCalc *
      rtb_TmpSignalConversionAtRP_S_j;
    VAR_MCF_uAlphaDeadCpn_f32 = SWC_MCF_B.MCF_uAlphaDeadCpn;
    VAR_MCF_uBetaDeadCpn_f32 = SWC_MCF_B.MCF_uBetaDeadCpn;
  } else {
    VAR_MCF_uAlphaDeadCpn_f32 = 0.0F;
    VAR_MCF_uBetaDeadCpn_f32 = 0.0F;
  }

  /* End of Switch generated from: '<S60>/Switch' */
  /* End of Outputs for SubSystem: '<S60>/Calculate dead compensation voltage' */

  /* Outputs for Enabled SubSystem: '<S61>/Harmonic_injection_of_11_and_13' incorporates:
   *  EnablePort: '<S86>/ZeroEnable'
   */
  /* Switch generated from: '<S61>/Switch2' incorporates:
   *  Constant: '<S61>/CAL_MCF_flgUse1113ZR_b'
   *  Constant: '<S61>/Constant1'
   *  Constant: '<S61>/Constant4'
   */
  if (CAL_MCF_flgUse1113ZR_b) {
    /* Product: '<S87>/Product2' incorporates:
     *  Constant: '<S87>/Coeficientof12axis'
     */
    rtb_MCF_ubBase = VAR_MCF_agRtrEe_f32 * -12.0F;

    /* DataTypeConversion: '<S91>/Data Type Conversion2' incorporates:
     *  Constant: '<S91>/360degreesisthenorm'
     *  Product: '<S91>/Divide1'
     */
    rtb_MCF_uaBase = fmodf(floorf(rtb_MCF_ubBase * 0.00277777785F), 256.0F);

    /* Product: '<S87>/Divide' incorporates:
     *  Constant: '<S87>/MCF_GLB_CircAge_f32 '
     *  Constant: '<S87>/MCF_GLB_DigtValue_u16 '
     *  Constant: '<S91>/360degreesisthenorm1'
     *  DataTypeConversion: '<S91>/Data Type Conversion2'
     *  Product: '<S87>/Divide1'
     *  Product: '<S91>/Divide3'
     *  Sum: '<S91>/Add3'
     */
    rtb_MCF_uBCalc = (rtb_MCF_ubBase - (float32)(rtb_MCF_uaBase < 0.0F ? (sint32)
      (sint8)-(sint8)(uint8)-rtb_MCF_uaBase : (sint32)(sint8)(uint8)
      rtb_MCF_uaBase) * 360.0F) * ((float32)((uint16)MCF_GLB_DigtValue_u16) /
      MCF_GLB_CircAge_f32);

    /* LookupNDDirect: '<S87>/LookupCosTable'
     *
     * About '<S87>/LookupCosTable':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     */
    if (rtb_MCF_uBCalc > 4095.0F) {
      rtb_MCF_ubBase = 4095.0F;
    } else if (rtb_MCF_uBCalc < 0.0F) {
      rtb_MCF_ubBase = 0.0F;
    } else {
      rtb_MCF_ubBase = rtb_MCF_uBCalc;
    }

    rtb_MCF_ubBase = rtCP_LookupCosTable_table[(sint32)rtb_MCF_ubBase];

    /* End of LookupNDDirect: '<S87>/LookupCosTable' */

    /* Lookup_n-D: '<S89>/1-D Lookup Table' */
    VAR_MCF_IsSet11ZR_f32 = look1_iflf_binlxpw(VAR_MCF_Rdc_nWoFlt_f32, ((const
      float32 *)&(CAL_MCF_HarmIn1113ZRX_Spd_af32[0])), ((const float32 *)
      &(CAL_MCF_HarmIn11ZRY_Is_af32[0])), 22U);

    /* Lookup_n-D: '<S89>/1-D Lookup Table1' */
    VAR_MCF_IsThetaSet11ZR_f32 = look1_iflf_binlxpw(VAR_MCF_Rdc_nWoFlt_f32, ((
      const float32 *)&(CAL_MCF_HarmIn1113ZRX_Spd_af32[0])), ((const float32 *)
      &(CAL_MCF_HarmIn11ZRY_Thetam_af32[0])), 22U);

    /* Switch generated from: '<S89>/Switch1' incorporates:
     *  Constant: '<S89>/CAL_MCF_IsSet11ZR_f32'
     *  Constant: '<S89>/CAL_MCF_IsThetaSet11ZR_f32'
     *  Constant: '<S89>/CAL_MCF_flgHarmInIsThetaTab11ZR_b'
     */
    if (CAL_MCF_flgHarmInIsThetaTab11ZR_b) {
      rtb_TmpSignalConversionAtRP__os = VAR_MCF_IsSet11ZR_f32;
      rtb_TmpSignalConversionAtRP_S_j = VAR_MCF_IsThetaSet11ZR_f32;
    } else {
      rtb_TmpSignalConversionAtRP__os = CAL_MCF_IsSet11ZR_f32;
      rtb_TmpSignalConversionAtRP_S_j = CAL_MCF_IsThetaSet11ZR_f32;
    }

    /* End of Switch generated from: '<S89>/Switch1' */

    /* LookupNDDirect: '<S89>/LookupCosineTab' incorporates:
     *  Constant: '<S89>/Sine_and_cosine_table'
     *  Product: '<S89>/Product6'
     *
     * About '<S89>/LookupCosineTab':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     */
    rtb_MCF_uaBase = rtb_TmpSignalConversionAtRP_S_j * 11.375F;
    if (rtb_MCF_uaBase > 4095.0F) {
      rtb_MCF_uaBase = 4095.0F;
    } else {
      if (rtb_MCF_uaBase < 0.0F) {
        rtb_MCF_uaBase = 0.0F;
      }
    }

    /* Product: '<S89>/Product' incorporates:
     *  LookupNDDirect: '<S89>/LookupCosineTab'
     *
     * About '<S89>/LookupCosineTab':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     */
    rtb_Add_j2 = rtb_TmpSignalConversionAtRP__os * rtCP_LookupCosineTab_table
      [(sint32)rtb_MCF_uaBase];

    /* Product: '<S90>/Product7' incorporates:
     *  Constant: '<S90>/Coefficient1'
     *  Constant: '<S90>/Coefficient2'
     *  Constant: '<S90>/MCF_GLB_MotorPole_u8'
     *  Constant: '<S90>/MCF_GLB_pi_f32'
     *  Constant: '<S90>/Voltageequationcoefficient'
     *  Product: '<S90>/Divide'
     *  Product: '<S90>/Product14'
     *  Product: '<S90>/Product15'
     *  Product: '<S90>/Product3'
     *  Sum: '<S90>/Add'
     */
    rtb_TmpSignalConversionAtRP_S_e = (float32)((uint8)MCF_GLB_MotorPole_u8) *
      0.0166666675F * VAR_MCF_Rdc_nWoFlt_f32 * 2.0F * MCF_GLB_pi_f32 *
      (VAR_MCF_MPC_Lq_f32 + VAR_MCF_MPC_Ld_f32) * 5.5F;

    /* LookupNDDirect: '<S89>/LookupSineTab' incorporates:
     *  Constant: '<S89>/Sine_and_cosine_table'
     *  Product: '<S89>/Product1'
     *
     * About '<S89>/LookupSineTab':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     */
    rtb_MCF_uaBase = 11.375F * rtb_TmpSignalConversionAtRP_S_j;
    if (rtb_MCF_uaBase > 4095.0F) {
      rtb_MCF_uaBase = 4095.0F;
    } else {
      if (rtb_MCF_uaBase < 0.0F) {
        rtb_MCF_uaBase = 0.0F;
      }
    }

    /* Product: '<S89>/Product3' incorporates:
     *  LookupNDDirect: '<S89>/LookupSineTab'
     *
     * About '<S89>/LookupSineTab':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     */
    rtb_TmpSignalConversionAtRP__os *= rtCP_LookupSineTab_table[(sint32)
      rtb_MCF_uaBase];

    /* Sum: '<S90>/Add8' incorporates:
     *  Constant: '<S90>/Rs'
     *  Product: '<S90>/Product6'
     *  Product: '<S90>/Product8'
     */
    rtb_TmpSignalConversionAtRP_S_j = rtb_Add_j2 * 0.006F +
      rtb_TmpSignalConversionAtRP_S_e * rtb_TmpSignalConversionAtRP__os;

    /* LookupNDDirect: '<S87>/LookupSinTable'
     *
     * About '<S87>/LookupSinTable':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     */
    if (rtb_MCF_uBCalc > 4095.0F) {
      rtb_MCF_uBCalc = 4095.0F;
    } else {
      if (rtb_MCF_uBCalc < 0.0F) {
        rtb_MCF_uBCalc = 0.0F;
      }
    }

    rtb_MCF_uBCalc = rtCP_LookupSinTable_table[(sint32)rtb_MCF_uBCalc];

    /* End of LookupNDDirect: '<S87>/LookupSinTable' */

    /* Sum: '<S90>/Add2' incorporates:
     *  Constant: '<S90>/Rs2'
     *  Product: '<S90>/Product10'
     *  Product: '<S90>/Product2'
     */
    rtb_TmpSignalConversionAtRP_S_e = rtb_TmpSignalConversionAtRP__os * 0.006F -
      rtb_TmpSignalConversionAtRP_S_e * rtb_Add_j2;

    /* Sum: '<S88>/Add' incorporates:
     *  Product: '<S88>/Product'
     *  Product: '<S88>/Product1'
     */
    SWC_MCF_B.MCF_udDes11ZR = rtb_TmpSignalConversionAtRP_S_j * rtb_MCF_ubBase -
      rtb_TmpSignalConversionAtRP_S_e * rtb_MCF_uBCalc;

    /* Sum: '<S88>/Add1' incorporates:
     *  Product: '<S88>/Product2'
     *  Product: '<S88>/Product3'
     */
    SWC_MCF_B.MCF_uqDes11ZR = rtb_TmpSignalConversionAtRP_S_e * rtb_MCF_ubBase +
      rtb_TmpSignalConversionAtRP_S_j * rtb_MCF_uBCalc;
    VAR_MCF_UdDes11ZR_f32 = SWC_MCF_B.MCF_udDes11ZR;
    VAR_MCF_UqDes11ZR_f32 = SWC_MCF_B.MCF_uqDes11ZR;
  } else {
    VAR_MCF_UdDes11ZR_f32 = 0.0F;
    VAR_MCF_UqDes11ZR_f32 = 0.0F;
  }

  /* End of Switch generated from: '<S61>/Switch2' */
  /* End of Outputs for SubSystem: '<S61>/Harmonic_injection_of_11_and_13' */

  /* Outputs for Enabled SubSystem: '<S62>/Calculate zero sequence alpha and beta axis voltage' incorporates:
   *  EnablePort: '<S92>/Enable'
   */
  /* Switch generated from: '<S62>/Switch' incorporates:
   *  Constant: '<S62>/CAL_MCF_flgUseZeroCtl_b'
   *  Constant: '<S62>/Constant'
   *  Constant: '<S62>/Constant1'
   *  UnitDelay: '<S95>/Delay1'
   *  UnitDelay: '<S96>/Delay1'
   */
  if (CAL_MCF_flgUseZeroCtl_b) {
    /* Product: '<S103>/Product11' incorporates:
     *  Constant: '<S103>/CAL_McPocSampleTime_f2'
     *  Lookup_n-D: '<S103>/LookupOmbw1'
     *  Product: '<S101>/Product11'
     */
    rtb_MCF_ubBase = CAL_MCF_SampleTime_f32 * look1_iflf_binlcapw
      (VAR_MCF_Rdc_nWoFlt_f32, ((const float32 *)&(CAL_MCF_OmbwFirstFltX_N_af32
         [0])), ((const float32 *)&(CAL_MCF_OmbwFirstFltY_Ombw_af32[0])), 9U);

    /* Sum: '<S103>/Add' incorporates:
     *  Constant: '<S103>/Coefficient filter'
     *  Product: '<S103>/Product11'
     *  Product: '<S103>/Product12'
     *  Product: '<S103>/Product13'
     *  Sum: '<S103>/Add1'
     *  UnitDelay: '<S103>/Unit Delay4'
     */
    VAR_MCF_iAlphaActFlt_f32 = (1.0F - rtb_MCF_ubBase) *
      VAR_MCF_iAlphaActFlt_f32 + SWC_MCF_DW.UnitDelay4_DSTATE * rtb_MCF_ubBase;

    /* Sum: '<S95>/Add2' incorporates:
     *  Constant: '<S95>/CAL_McPoc_ZeroCtlAplhaRef_f32'
     */
    rtb_MCF_uBCalc = CAL_MCF_AplhaRefZeroCtl_f32 - VAR_MCF_iAlphaActFlt_f32;

    /* Switch generated from: '<S93>/Switch' incorporates:
     *  Constant: '<S93>/CAL_MCF_KiAlphaZeroCtl_f32'
     *  Constant: '<S93>/CAL_MCF_KpAlphaZeroCtl_f32'
     *  Constant: '<S93>/CAL_MCF_flgTabZeroCtl_b'
     *  Lookup_n-D: '<S93>/MC_ZeroAlphaKi'
     *  Lookup_n-D: '<S93>/MC_ZeroAlphaKp'
     */
    if (CAL_MCF_flgTabZeroCtl_b) {
      rtb_MCF_uaBase = look1_iflf_binlxpw(VAR_MCF_Rdc_nWoFlt_f32, ((const
        float32 *)&(CAL_MCF_CoefPIZoreCtlX_N_af32[0])), ((const float32 *)
        &(CAL_MCF_CoefPIAlphaZeroCtlY_Ki_af32[0])), 9U);
      rtb_TmpSignalConversionAtRP_S_e = look1_iflf_binlxpw
        (VAR_MCF_Rdc_nWoFlt_f32, ((const float32 *)
          &(CAL_MCF_CoefPIZoreCtlX_N_af32[0])), ((const float32 *)
          &(CAL_MCF_CoefPIAlphaZeroFtlY_Kp_af32[0])), 9U);
    } else {
      rtb_MCF_uaBase = CAL_MCF_KiAlphaZeroCtl_f32;
      rtb_TmpSignalConversionAtRP_S_e = CAL_MCF_KpAlphaZeroCtl_f32;
    }

    /* End of Switch generated from: '<S93>/Switch' */

    /* Sum: '<S95>/Add4' incorporates:
     *  Product: '<S95>/Product'
     *  Product: '<S95>/Product1'
     *  Sum: '<S95>/Add3'
     *  UnitDelay: '<S95>/Delay'
     *  UnitDelay: '<S95>/Delay1'
     */
    SWC_MCF_DW.Delay1_DSTATE_g += (rtb_MCF_uBCalc - SWC_MCF_DW.Delay_DSTATE_p) *
      rtb_TmpSignalConversionAtRP_S_e + rtb_MCF_uaBase * rtb_MCF_uBCalc;

    /* Switch: '<S99>/Switch2' incorporates:
     *  Constant: '<S95>/CAL_MCF_DownLimPIZeroCtl_f32'
     *  Constant: '<S95>/CAL_MCF_UpLimPIZeroCtl_f32'
     *  RelationalOperator: '<S99>/LowerRelop1'
     *  RelationalOperator: '<S99>/UpperRelop'
     *  Switch: '<S99>/Switch'
     *  UnitDelay: '<S95>/Delay1'
     */
    if (SWC_MCF_DW.Delay1_DSTATE_g > CAL_MCF_UpLimPIZeroCtl_f32) {
      SWC_MCF_DW.Delay1_DSTATE_g = CAL_MCF_UpLimPIZeroCtl_f32;
    } else {
      if (SWC_MCF_DW.Delay1_DSTATE_g < CAL_MCF_DownLimPIZeroCtl_f32) {
        /* Switch: '<S99>/Switch' incorporates:
         *  Constant: '<S95>/CAL_MCF_DownLimPIZeroCtl_f32'
         *  UnitDelay: '<S95>/Delay1'
         */
        SWC_MCF_DW.Delay1_DSTATE_g = CAL_MCF_DownLimPIZeroCtl_f32;
      }
    }

    /* End of Switch: '<S99>/Switch2' */

    /* Sum: '<S101>/Add' incorporates:
     *  Constant: '<S101>/Coefficient filter'
     *  Product: '<S101>/Product12'
     *  Product: '<S101>/Product13'
     *  Sum: '<S101>/Add1'
     *  UnitDelay: '<S101>/Unit Delay4'
     */
    VAR_MCF_iBetaActFlt_f32 = (1.0F - rtb_MCF_ubBase) * VAR_MCF_iBetaActFlt_f32
      + SWC_MCF_DW.UnitDelay4_DSTATE_o * rtb_MCF_ubBase;

    /* Sum: '<S96>/Add2' incorporates:
     *  Constant: '<S96>/CAL_MCF_BetaRefZeroCtl_f32'
     */
    rtb_TmpSignalConversionAtRP_S_j = CAL_MCF_BetaRefZeroCtl_f32 -
      VAR_MCF_iBetaActFlt_f32;

    /* Switch generated from: '<S94>/Switch' incorporates:
     *  Constant: '<S94>/CAL_MCF_KiBetaZeroCtl_f32'
     *  Constant: '<S94>/CAL_MCF_KpBetaZeroCtl_f32'
     *  Constant: '<S94>/CAL_MCF_flgTabZeroCtl_b'
     *  Lookup_n-D: '<S94>/MC_ZeroAlphaKi'
     *  Lookup_n-D: '<S94>/MC_ZeroAlphaKp'
     */
    if (CAL_MCF_flgTabZeroCtl_b) {
      rtb_MCF_uaBase = look1_iflf_binlxpw(VAR_MCF_Rdc_nWoFlt_f32, ((const
        float32 *)&(CAL_MCF_CoefPIZoreCtlX_N_af32[0])), ((const float32 *)
        &(CAL_MCF_CoefPIBetaZeroCtlY_Ki_af32[0])), 9U);
      rtb_TmpSignalConversionAtRP_S_e = look1_iflf_binlxpw
        (VAR_MCF_Rdc_nWoFlt_f32, ((const float32 *)
          &(CAL_MCF_CoefPIZoreCtlX_N_af32[0])), ((const float32 *)
          &(CAL_MCF_CoefPIBetaZeroCtlY_Kp_af32[0])), 9U);
    } else {
      rtb_MCF_uaBase = CAL_MCF_KiBetaZeroCtl_f32;
      rtb_TmpSignalConversionAtRP_S_e = CAL_MCF_KpBetaZeroCtl_f32;
    }

    /* End of Switch generated from: '<S94>/Switch' */

    /* Sum: '<S96>/Add4' incorporates:
     *  Product: '<S96>/Product'
     *  Product: '<S96>/Product1'
     *  Sum: '<S96>/Add3'
     *  UnitDelay: '<S96>/Delay'
     *  UnitDelay: '<S96>/Delay1'
     */
    SWC_MCF_DW.Delay1_DSTATE_p += (rtb_TmpSignalConversionAtRP_S_j -
      SWC_MCF_DW.Delay_DSTATE_g) * rtb_TmpSignalConversionAtRP_S_e +
      rtb_MCF_uaBase * rtb_TmpSignalConversionAtRP_S_j;

    /* Switch: '<S100>/Switch2' incorporates:
     *  Constant: '<S96>/CAL_MCF_DownLimPIZeroCtl_f32'
     *  Constant: '<S96>/CAL_MCF_UpLimPIZeroCtl_f32'
     *  RelationalOperator: '<S100>/LowerRelop1'
     *  RelationalOperator: '<S100>/UpperRelop'
     *  Switch: '<S100>/Switch'
     *  UnitDelay: '<S96>/Delay1'
     */
    if (SWC_MCF_DW.Delay1_DSTATE_p > CAL_MCF_UpLimPIZeroCtl_f32) {
      SWC_MCF_DW.Delay1_DSTATE_p = CAL_MCF_UpLimPIZeroCtl_f32;
    } else {
      if (SWC_MCF_DW.Delay1_DSTATE_p < CAL_MCF_DownLimPIZeroCtl_f32) {
        /* Switch: '<S100>/Switch' incorporates:
         *  Constant: '<S96>/CAL_MCF_DownLimPIZeroCtl_f32'
         *  UnitDelay: '<S96>/Delay1'
         */
        SWC_MCF_DW.Delay1_DSTATE_p = CAL_MCF_DownLimPIZeroCtl_f32;
      }
    }

    /* End of Switch: '<S100>/Switch2' */

    /* Product: '<S102>/Product7' incorporates:
     *  Constant: '<S102>/CAL_MCF_CoefFltZero_C_f32'
     *  Constant: '<S102>/Coefficient 1'
     *  Constant: '<S102>/Coefficient 3'
     *  Constant: '<S102>/MCF_GLB_MotorPole_u8'
     *  Constant: '<S102>/MCF_GLB_pi_f32'
     *  Product: '<S102>/Divide'
     *  Product: '<S102>/Product14'
     *  Product: '<S102>/Product8'
     *  Product: '<S104>/Product7'
     */
    rtb_MCF_ubBase = (float32)((uint8)MCF_GLB_MotorPole_u8) / 60.0F *
      VAR_MCF_Rdc_nWoFlt_f32 * 2.0F * MCF_GLB_pi_f32 * CAL_MCF_CoefFltZero_C_f32;

    /* Product: '<S102>/Product2' incorporates:
     *  Constant: '<S102>/CAL_MCF_CoefFltZero_A_f32'
     *  Constant: '<S102>/CAL_MCF_SampleTime_f32'
     *  Product: '<S102>/Product7'
     *  Product: '<S104>/Product2'
     */
    rtb_TmpSignalConversionAtRP__os = CAL_MCF_SampleTime_f32 *
      CAL_MCF_CoefFltZero_A_f32;
    rtb_Product11 = rtb_TmpSignalConversionAtRP__os * rtb_MCF_ubBase;

    /* UnitDelay: '<S102>/Unit Delay' */
    rtb_MCF_uaBase = SWC_MCF_DW.UnitDelay_DSTATE_bu;

    /* UnitDelay: '<S102>/Unit Delay2' */
    rtb_TmpSignalConversionAtRP_S_e = SWC_MCF_DW.UnitDelay2_DSTATE_d;

    /* Product: '<S102>/Product' incorporates:
     *  Constant: '<S102>/CAL_MCF_CoefFltZero_B_f32'
     *  Constant: '<S102>/CAL_McPocSampleTime_f1'
     *  Product: '<S102>/Product7'
     *  Product: '<S104>/Product'
     */
    rtb_TmpSignalConversionAtRP__gi = CAL_MCF_SampleTime_f32 *
      CAL_MCF_CoefFltZero_B_f32;
    rtb_Product_dh = rtb_TmpSignalConversionAtRP__gi * rtb_MCF_ubBase;

    /* Math: '<S102>/Math Function1' incorporates:
     *  Constant: '<S102>/CAL_McPocSampleTime_f3'
     *  Math: '<S104>/Math Function1'
     */
    rtb_Product6 = CAL_MCF_SampleTime_f32 * CAL_MCF_SampleTime_f32;

    /* Product: '<S102>/Product1' incorporates:
     *  Math: '<S102>/Math Function'
     *  Math: '<S102>/Math Function1'
     *  Product: '<S102>/Product7'
     */
    rtb_Product2_p0 = rtb_MCF_ubBase * rtb_MCF_ubBase * rtb_Product6;

    /* Sum: '<S102>/Subtract4' incorporates:
     *  Constant: '<S102>/Coefficient'
     *  Constant: '<S102>/Coefficient1'
     *  Constant: '<S102>/Coefficient2'
     *  Constant: '<S102>/Coefficient3'
     *  Product: '<S102>/Product3'
     *  Product: '<S102>/Product4'
     *  Product: '<S102>/Product5'
     *  Product: '<S102>/Product6'
     *  Sum: '<S102>/Subtract'
     *  Sum: '<S102>/Subtract1'
     *  Sum: '<S102>/Subtract2'
     *  Sum: '<S102>/Subtract3'
     *  UnitDelay: '<S102>/Unit Delay'
     *  UnitDelay: '<S102>/Unit Delay1'
     *  UnitDelay: '<S102>/Unit Delay2'
     *  UnitDelay: '<S102>/Unit Delay3'
     */
    SWC_MCF_DW.UnitDelay4_DSTATE_o = (((((1.0F - rtb_Product11) +
      rtb_Product2_p0) * SWC_MCF_DW.UnitDelay1_DSTATE_hc + (rtb_Product11 - 2.0F)
      * SWC_MCF_DW.UnitDelay_DSTATE_bu) + rtb_MCF_ibeta) + (2.0F -
      rtb_Product_dh) * SWC_MCF_DW.UnitDelay2_DSTATE_d) + ((rtb_Product_dh -
      1.0F) - rtb_Product2_p0) * SWC_MCF_DW.UnitDelay3_DSTATE;

    /* Product: '<S104>/Product2' */
    rtb_Product2_p0 = rtb_TmpSignalConversionAtRP__os * rtb_MCF_ubBase;

    /* UnitDelay: '<S104>/Unit Delay' */
    rtb_TmpSignalConversionAtRP__os = SWC_MCF_DW.UnitDelay_DSTATE_d;

    /* UnitDelay: '<S104>/Unit Delay2' */
    rtb_Add_j2 = SWC_MCF_DW.UnitDelay2_DSTATE_h;

    /* Product: '<S104>/Product' */
    rtb_Product11 = rtb_TmpSignalConversionAtRP__gi * rtb_MCF_ubBase;

    /* Product: '<S104>/Product1' incorporates:
     *  Math: '<S104>/Math Function'
     */
    rtb_Product_dh = rtb_MCF_ubBase * rtb_MCF_ubBase * rtb_Product6;

    /* Sum: '<S104>/Subtract4' incorporates:
     *  Constant: '<S104>/Coefficient'
     *  Constant: '<S104>/Coefficient1'
     *  Constant: '<S104>/Coefficient2'
     *  Constant: '<S104>/Coefficient3'
     *  Product: '<S104>/Product3'
     *  Product: '<S104>/Product4'
     *  Product: '<S104>/Product5'
     *  Product: '<S104>/Product6'
     *  Sum: '<S104>/Subtract'
     *  Sum: '<S104>/Subtract1'
     *  Sum: '<S104>/Subtract2'
     *  Sum: '<S104>/Subtract3'
     *  UnitDelay: '<S104>/Unit Delay'
     *  UnitDelay: '<S104>/Unit Delay1'
     *  UnitDelay: '<S104>/Unit Delay2'
     *  UnitDelay: '<S104>/Unit Delay3'
     */
    SWC_MCF_DW.UnitDelay4_DSTATE = (((((1.0F - rtb_Product2_p0) + rtb_Product_dh)
      * SWC_MCF_DW.UnitDelay1_DSTATE_k + (rtb_Product2_p0 - 2.0F) *
      SWC_MCF_DW.UnitDelay_DSTATE_d) + rtb_MCF_ialpha) + (2.0F - rtb_Product11) *
      SWC_MCF_DW.UnitDelay2_DSTATE_h) + ((rtb_Product11 - 1.0F) - rtb_Product_dh)
      * SWC_MCF_DW.UnitDelay3_DSTATE_p;

    /* Update for UnitDelay: '<S95>/Delay' */
    SWC_MCF_DW.Delay_DSTATE_p = rtb_MCF_uBCalc;

    /* Update for UnitDelay: '<S96>/Delay' */
    SWC_MCF_DW.Delay_DSTATE_g = rtb_TmpSignalConversionAtRP_S_j;

    /* Update for UnitDelay: '<S102>/Unit Delay' */
    SWC_MCF_DW.UnitDelay_DSTATE_bu = rtb_MCF_ibeta;

    /* Update for UnitDelay: '<S102>/Unit Delay2' */
    SWC_MCF_DW.UnitDelay2_DSTATE_d = SWC_MCF_DW.UnitDelay4_DSTATE_o;

    /* Update for UnitDelay: '<S102>/Unit Delay3' */
    SWC_MCF_DW.UnitDelay3_DSTATE = rtb_TmpSignalConversionAtRP_S_e;

    /* Update for UnitDelay: '<S102>/Unit Delay1' */
    SWC_MCF_DW.UnitDelay1_DSTATE_hc = rtb_MCF_uaBase;

    /* Update for UnitDelay: '<S104>/Unit Delay' */
    SWC_MCF_DW.UnitDelay_DSTATE_d = rtb_MCF_ialpha;

    /* Update for UnitDelay: '<S104>/Unit Delay2' */
    SWC_MCF_DW.UnitDelay2_DSTATE_h = SWC_MCF_DW.UnitDelay4_DSTATE;

    /* Update for UnitDelay: '<S104>/Unit Delay3' */
    SWC_MCF_DW.UnitDelay3_DSTATE_p = rtb_Add_j2;

    /* Update for UnitDelay: '<S104>/Unit Delay1' */
    SWC_MCF_DW.UnitDelay1_DSTATE_k = rtb_TmpSignalConversionAtRP__os;
    VAR_MCF_uAlphaZero_f32 = SWC_MCF_DW.Delay1_DSTATE_g;
    VAR_MCF_uBetaZero_f32 = SWC_MCF_DW.Delay1_DSTATE_p;
  } else {
    VAR_MCF_uAlphaZero_f32 = 0.0F;
    VAR_MCF_uBetaZero_f32 = 0.0F;
  }

  /* End of Switch generated from: '<S62>/Switch' */
  /* End of Outputs for SubSystem: '<S62>/Calculate zero sequence alpha and beta axis voltage' */

  /* Outputs for Enabled SubSystem: '<S107>/Inductancetestfunction' incorporates:
   *  EnablePort: '<S108>/Enable'
   */
  /* Switch generated from: '<S107>/Switch' incorporates:
   *  Constant: '<S107>/CAL_MCF_FlgUseEOL_b'
   *  Constant: '<S107>/uDDesiszero'
   *  Constant: '<S107>/uQDesiszero'
   *  Constant: '<S112>/CAL_MCF_uQDesEOL_f32'
   *  Inport: '<Root>/RP_SWC_SCF_SCF_stGateDrv'
   *  Inport: '<Root>/RP_SWC_TPC_TPC_TDbcTrqMax'
   */
  if (CAL_MCF_FlgUseEOL_b) {
    Rte_Read_RP_SWC_SCF_SCF_stGateDrv(&rtb_Gain3);

    /* Saturate: '<S109>/Saturation' incorporates:
     *  Constant: '<S109>/CAL_MCF_IsrmsDesEOL_f32'
     *  Inport: '<Root>/RP_SWC_SCF_SCF_stGateDrv'
     */
    if (CAL_MCF_IsrmsDesEOL_f32 > 1000.0F) {
      rtb_MCF_uaBase = 1000.0F;
    } else if (CAL_MCF_IsrmsDesEOL_f32 < 0.0F) {
      rtb_MCF_uaBase = 0.0F;
    } else {
      rtb_MCF_uaBase = CAL_MCF_IsrmsDesEOL_f32;
    }

    /* End of Saturate: '<S109>/Saturation' */

    /* Sum: '<S109>/Add' incorporates:
     *  Constant: '<S109>/Conversion_of_amplitude_and_effective_values'
     *  Product: '<S109>/Product2'
     *  Sum: '<S11>/Add1'
     */
    rtb_MCF_ibeta = rtb_MCF_uaBase - VAR_MCF_Is_f32 * 0.707106769F;

    /* Switch: '<S109>/Switch' incorporates:
     *  Constant: '<S109>/CAL_MCF_FlgUseSatuEOL_b'
     *  Constant: '<S109>/CAL_MCF_KiUdEOL_f32'
     *  Constant: '<S109>/Constant2'
     *  Constant: '<S109>/PWM_10K_period'
     *  Constant: '<S110>/MCF_GLB_IGBTRun_u8'
     *  Logic: '<S110>/Operator'
     *  Product: '<S109>/Product1'
     *  Product: '<S109>/Product3'
     *  RelationalOperator: '<S110>/Operator1'
     *  Sum: '<S109>/Add1'
     *  Switch: '<S109>/Switch1'
     *  UnitDelay: '<S109>/Unit Delay'
     */
    if (rtb_Gain3 != ((uint8)MCF_GLB_IGBTRun_u8)) {
      SWC_MCF_DW.UnitDelay_DSTATE_n = 0.0F;
    } else {
      if (CAL_MCF_FlgUseSatuEOL_b) {
        /* Saturate: '<S109>/Saturation1' incorporates:
         *  Switch: '<S109>/Switch1'
         *  UnitDelay: '<S109>/Unit Delay1'
         */
        if (SWC_MCF_DW.UnitDelay1_DSTATE_h > 1000.0F) {
          rtb_MCF_uaBase = 1000.0F;
        } else if (SWC_MCF_DW.UnitDelay1_DSTATE_h < 1.0E-5F) {
          rtb_MCF_uaBase = 1.0E-5F;
        } else {
          rtb_MCF_uaBase = SWC_MCF_DW.UnitDelay1_DSTATE_h;
        }

        /* End of Saturate: '<S109>/Saturation1' */

        /* Switch: '<S109>/Switch2' incorporates:
         *  RelationalOperator: '<S109>/Relational Operator'
         *  Switch: '<S109>/Switch1'
         *  UnitDelay: '<S109>/Unit Delay1'
         *  UnitDelay: '<S112>/Unit Delay'
         */
        if (SWC_MCF_DW.UnitDelay_DSTATE_f >= rtb_MCF_uaBase) {
          SWC_MCF_DW.UnitDelay_DSTATE_f = SWC_MCF_DW.UnitDelay1_DSTATE_h;
        }

        /* Switch: '<S109>/Switch1' incorporates:
         *  Sum: '<S109>/Add3'
         *  UnitDelay: '<S109>/Unit Delay1'
         */
        rtb_MCF_ialpha = SWC_MCF_DW.UnitDelay1_DSTATE_h -
          SWC_MCF_DW.UnitDelay_DSTATE_f;
      } else {
        /* Switch: '<S109>/Switch1' incorporates:
         *  Constant: '<S109>/Constant6'
         */
        rtb_MCF_ialpha = 0.0F;
      }

      SWC_MCF_DW.UnitDelay_DSTATE_n += rtb_MCF_ibeta * 0.0001F *
        CAL_MCF_KiUdEOL_f32 - rtb_MCF_ialpha;
    }

    /* End of Switch: '<S109>/Switch' */

    /* Sum: '<S109>/Add2' incorporates:
     *  Constant: '<S109>/CAL_MCF_KpUdEOL_f32'
     *  Product: '<S109>/Product'
     *  UnitDelay: '<S109>/Unit Delay'
     */
    SWC_MCF_DW.UnitDelay1_DSTATE_h = rtb_MCF_ibeta * CAL_MCF_KpUdEOL_f32 +
      SWC_MCF_DW.UnitDelay_DSTATE_n;

    /* Switch: '<S114>/Switch2' incorporates:
     *  Constant: '<S109>/CAL_MCF_uDDownLimEOL_f32'
     *  Constant: '<S109>/CAL_MCF_uDUpLimEOL_f32'
     *  RelationalOperator: '<S114>/LowerRelop1'
     *  RelationalOperator: '<S114>/UpperRelop'
     *  Switch: '<S114>/Switch'
     *  UnitDelay: '<S109>/Unit Delay1'
     */
    if (SWC_MCF_DW.UnitDelay1_DSTATE_h > CAL_MCF_uDUpLimEOL_f32) {
      SWC_MCF_DW.UnitDelay1_DSTATE_h = CAL_MCF_uDUpLimEOL_f32;
    } else {
      if (SWC_MCF_DW.UnitDelay1_DSTATE_h < CAL_MCF_uDDownLimEOL_f32) {
        /* Switch: '<S114>/Switch' incorporates:
         *  Constant: '<S109>/CAL_MCF_uDDownLimEOL_f32'
         *  UnitDelay: '<S109>/Unit Delay1'
         */
        SWC_MCF_DW.UnitDelay1_DSTATE_h = CAL_MCF_uDDownLimEOL_f32;
      }
    }

    /* End of Switch: '<S114>/Switch2' */

    /* Switch: '<S113>/Switch' incorporates:
     *  Constant: '<S113>/CAL_MCF_FlgUseClose_b'
     *  Constant: '<S113>/CAL_MCF_FlgUseOpen_b'
     *  Constant: '<S113>/Constant'
     *  Lookup_n-D: '<S111>/Isrms_udDes_Tab'
     *  Switch: '<S113>/Switch1'
     */
    if (CAL_MCF_FlgUseOpen_b) {
      /* Saturate: '<S111>/Saturation' incorporates:
       *  Constant: '<S111>/CAL_MCF_IsrmsDesEOL_f32'
       */
      if (CAL_MCF_IsrmsDesEOL_f32 > 1000.0F) {
        rtb_MCF_uaBase = 1000.0F;
      } else if (CAL_MCF_IsrmsDesEOL_f32 < 0.0F) {
        rtb_MCF_uaBase = 0.0F;
      } else {
        rtb_MCF_uaBase = CAL_MCF_IsrmsDesEOL_f32;
      }

      /* End of Saturate: '<S111>/Saturation' */
      SWC_MCF_B.Switch3 = look1_iflf_binlcpw(rtb_MCF_uaBase, ((const float32 *)
        &(CAL_MCF_IrmsDesEOLX_af32[0])), ((const float32 *)
        &(CAL_MCF_uDDesEOLY_af32[0])), 19U);
    } else if (CAL_MCF_FlgUseClose_b) {
      /* Switch: '<S113>/Switch1' incorporates:
       *  UnitDelay: '<S109>/Unit Delay1'
       */
      SWC_MCF_B.Switch3 = SWC_MCF_DW.UnitDelay1_DSTATE_h;
    } else {
      SWC_MCF_B.Switch3 = 0.0F;
    }

    /* End of Switch: '<S113>/Switch' */
    Rte_Read_RP_SWC_TPC_TPC_TDbcTrqMax(&rtb_MCF_uDcalc);

    /* Switch: '<S109>/Switch2' incorporates:
     *  Abs: '<S112>/Abs'
     *  Constant: '<S112>/CAL_MCF_CoefuDCLimtEOL_f32'
     *  Constant: '<S112>/CAL_MCF_TrqInvMax_f32'
     *  Inport: '<Root>/RP_SWC_TPC_TPC_TDbcTrqMax'
     *  Product: '<S112>/Divide'
     *  Product: '<S112>/Product'
     *  Product: '<S112>/Product2'
     *  Sum: '<S13>/Add'
     *  UnitDelay: '<S112>/Unit Delay'
     */
    SWC_MCF_DW.UnitDelay_DSTATE_f = fabsf(rtb_MCF_uDcalc) /
      CAL_MCF_TrqInvMax_f32 * (VAR_MCF_uDcLnk_f32 * CAL_MCF_CoefuDCLimtEOL_f32);

    /* Switch: '<S112>/Switch3' incorporates:
     *  Sum: '<S112>/Add1'
     *  UnitDelay: '<S112>/Unit Delay'
     */
    if (SWC_MCF_DW.UnitDelay_DSTATE_f - SWC_MCF_B.Switch3 == 0.0F) {
      SWC_MCF_B.Switch3 = SWC_MCF_DW.UnitDelay_DSTATE_f;
    }

    /* End of Switch: '<S112>/Switch3' */
    SWC_MCF_B.CAL_MCF_uQDesEOL_f32_h = CAL_MCF_uQDesEOL_f32;
    VAR_MCF_uDDesEOL_f32 = SWC_MCF_B.Switch3;
    VAR_MCF_uQDesEOL_f32 = SWC_MCF_B.CAL_MCF_uQDesEOL_f32_h;
  } else {
    VAR_MCF_uDDesEOL_f32 = 0.0F;
    VAR_MCF_uQDesEOL_f32 = 0.0F;
  }

  /* End of Switch generated from: '<S107>/Switch' */
  /* End of Outputs for SubSystem: '<S107>/Inductancetestfunction' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_MCF_100us' */

  /* Inport: '<Root>/RP_SWC_RCF_RCF_flgUseUsSet' */
  Rte_Read_RP_SWC_RCF_RCF_flgUseUsSet(&rtb_RelationalOperator_o1);

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_MCF_100us' incorporates:
   *  SubSystem: '<Root>/RE_SWC_MCF_100us_sys'
   */
  /* Switch generated from: '<S106>/Switch1' incorporates:
   *  Constant: '<S106>/CAL_McSfc_DycUSet_f32'
   *  Constant: '<S106>/CAL_McSfc_DycVSet_f32'
   *  Constant: '<S106>/CAL_McSfc_DycWSet_f32'
   *  Constant: '<S106>/CAL_McSfc_FlgUpdateDyc_b '
   *  UnitDelay generated from: '<S106>/Unit Delay'
   */
  if (CAL_MCF_FlgUpdateDyc_b) {
    SWC_MCF_DW.UnitDelay_1_DSTATE = CAL_MCF_DycUSet_f32;
    SWC_MCF_DW.UnitDelay_2_DSTATE = CAL_MCF_DycVSet_f32;
    SWC_MCF_DW.UnitDelay_3_DSTATE = CAL_MCF_DycWSet_f32;
  }

  /* End of Switch generated from: '<S106>/Switch1' */

  /* Switch: '<S178>/Switch' incorporates:
   *  Constant: '<S107>/CAL_MCF_FlgUseEOL_b'
   *  Sum: '<S178>/Add'
   *  Sum: '<S25>/Add4'
   */
  if (CAL_MCF_FlgUseEOL_b) {
    rtb_MCF_uDcalc = VAR_MCF_uDDesEOL_f32;
  } else {
    rtb_MCF_uDcalc = VAR_MCF_udDes_f32 + VAR_MCF_UdDes11ZR_f32;
  }

  /* End of Switch: '<S178>/Switch' */

  /* Sum: '<S181>/Add1' incorporates:
   *  Constant: '<S181>/CAL_MCF_cofFltN_f32'
   *  Constant: '<S181>/Constant'
   *  Product: '<S181>/Product'
   *  Product: '<S181>/Product1'
   *  Sum: '<S181>/Add'
   *  UnitDelay: '<S181>/Unit Delay'
   */
  SWC_MCF_DW.UnitDelay_DSTATE_b = (1.0F - CAL_MCF_cofFltN_f32) *
    SWC_MCF_DW.UnitDelay_DSTATE_b + VAR_MCF_Rdc_nWoFlt_f32 * CAL_MCF_cofFltN_f32;

  /* Sum: '<S177>/Add' incorporates:
   *  Constant: '<S177>/CAL_MCF_perCpnAg_f32'
   *  Constant: '<S177>/MCF_GLB_CircAge_f32'
   *  Constant: '<S177>/MCF_GLB_MotorPole_u8'
   *  Constant: '<S177>/MCF_GLB_Sixty_f3'
   *  Product: '<S177>/Divide1'
   *  Product: '<S177>/Product'
   *  Product: '<S177>/Product1'
   *  Product: '<S177>/Product2'
   *  Product: '<S177>/Product3'
   *  UnitDelay: '<S181>/Unit Delay'
   */
  rtb_Subtract_o = SWC_MCF_DW.UnitDelay_DSTATE_b * (float32)((uint8)
    MCF_GLB_MotorPole_u8) / MCF_GLB_Sixty_f32 * (CAL_MCF_perCpnAg_f32 *
    rtb_Subtract_o) * MCF_GLB_CircAge_f32 + VAR_MCF_agRtrEe_f32;

  /* Sum: '<S177>/Add1' incorporates:
   *  Constant: '<S177>/MCF_GLB_CircAge_f32'
   *  Sum: '<S177>/Add2'
   *  Switch: '<S177>/Switch'
   */
  rtb_MCF_uaBase = rtb_Subtract_o - MCF_GLB_CircAge_f32;

  /* Switch: '<S177>/Switch' incorporates:
   *  Constant: '<S177>/Constant'
   *  Constant: '<S177>/Constant1'
   *  Constant: '<S177>/MCF_GLB_CircAge_f32'
   *  RelationalOperator: '<S177>/Relational Operator'
   *  RelationalOperator: '<S177>/Relational Operator1'
   *  Sum: '<S177>/Add1'
   *  Sum: '<S177>/Add3'
   *  Switch: '<S177>/Switch1'
   */
  if (rtb_MCF_uaBase >= 0.0F) {
    rtb_Subtract_o = rtb_MCF_uaBase;
  } else {
    if (rtb_Subtract_o < 0.0F) {
      rtb_Subtract_o += MCF_GLB_CircAge_f32;
    }
  }

  /* Product: '<S177>/Divide' incorporates:
   *  Constant: '<S177>/MCF_GLB_CircAge_f32'
   *  Constant: '<S177>/MCF_GLB_DigtValue_u16'
   */
  rtb_Subtract_o = rtb_Subtract_o * (float32)((uint16)MCF_GLB_DigtValue_u16) /
    MCF_GLB_CircAge_f32;

  /* LookupNDDirect: '<S177>/LookupCosTable'
   *
   * About '<S177>/LookupCosTable':
   *  1-dimensional Direct Look-Up returning a Scalar,
   *
   *     Remove protection against out-of-range input in generated code: 'off'
   */
  if (rtb_Subtract_o > 4095.0F) {
    rtb_MCF_ibeta = 4095.0F;
  } else if (rtb_Subtract_o < 0.0F) {
    rtb_MCF_ibeta = 0.0F;
  } else {
    rtb_MCF_ibeta = rtb_Subtract_o;
  }

  rtb_MCF_ibeta = rtCP_LookupCosTable_table_k[(sint32)rtb_MCF_ibeta];

  /* End of LookupNDDirect: '<S177>/LookupCosTable' */

  /* Switch: '<S178>/Switch1' incorporates:
   *  Constant: '<S107>/CAL_MCF_FlgUseEOL_b'
   *  Sum: '<S178>/Add1'
   *  Sum: '<S25>/Add3'
   */
  if (CAL_MCF_FlgUseEOL_b) {
    rtb_MCF_ialpha = VAR_MCF_uQDesEOL_f32;
  } else {
    rtb_MCF_ialpha = VAR_MCF_uqDes_f32 + VAR_MCF_UqDes11ZR_f32;
  }

  /* End of Switch: '<S178>/Switch1' */

  /* LookupNDDirect: '<S177>/LookupSinTable'
   *
   * About '<S177>/LookupSinTable':
   *  1-dimensional Direct Look-Up returning a Scalar,
   *
   *     Remove protection against out-of-range input in generated code: 'off'
   */
  if (rtb_Subtract_o > 4095.0F) {
    rtb_Subtract_o = 4095.0F;
  } else {
    if (rtb_Subtract_o < 0.0F) {
      rtb_Subtract_o = 0.0F;
    }
  }

  rtb_Subtract_o = rtCP_LookupSinTable_table_k[(sint32)rtb_Subtract_o];

  /* End of LookupNDDirect: '<S177>/LookupSinTable' */

  /* Switch: '<S180>/Switch' incorporates:
   *  Constant: '<S180>/CAL_MCF_flgOfsClbTest_b'
   *  Inport: '<Root>/RP_SWC_RCF_RCF_UsAlfaScalSet'
   *  Inport: '<Root>/RP_SWC_RCF_RCF_UsBetaScalSet'
   *  Logic: '<S180>/Logical Operator'
   *  Product: '<S179>/Product'
   *  Product: '<S179>/Product1'
   *  Product: '<S179>/Product2'
   *  Product: '<S179>/Product3'
   *  Sum: '<S179>/Add'
   *  Sum: '<S179>/Add1'
   *  Sum: '<S180>/Add'
   *  Sum: '<S180>/Add1'
   *  Switch: '<S180>/Switch1'
   */
  if (rtb_RelationalOperator_o1 && CAL_MCF_flgOfsClbTest_b) {
    Rte_Read_RP_SWC_RCF_RCF_UsAlfaScalSet(&VAR_MCF_uAOfsClb_f32);
    Rte_Read_RP_SWC_RCF_RCF_UsBetaScalSet(&VAR_MCF_uBOfsClb_f32);
  } else {
    VAR_MCF_uAOfsClb_f32 = (rtb_MCF_uDcalc * rtb_MCF_ibeta - rtb_MCF_ialpha *
      rtb_Subtract_o) + VAR_MCF_uAlphaZero_f32;
    VAR_MCF_uBOfsClb_f32 = (rtb_MCF_ialpha * rtb_MCF_ibeta + rtb_MCF_uDcalc *
      rtb_Subtract_o) + VAR_MCF_uBetaZero_f32;
  }

  /* End of Switch: '<S180>/Switch' */

  /* Outputs for Enabled SubSystem: '<S117>/MCF_OverModuEn' incorporates:
   *  EnablePort: '<S168>/EnableOm'
   */
  /* Switch: '<S117>/Switch' incorporates:
   *  Constant: '<S117>/CAL_MCF_flgOverModu_b'
   *  Switch: '<S117>/Switch1'
   */
  if (CAL_MCF_flgOverModu_b) {
    /* Sqrt: '<S168>/Sqrt' incorporates:
     *  Product: '<S168>/Product2'
     *  Product: '<S168>/Product3'
     *  Sum: '<S168>/Add'
     */
    VAR_MCF_usPeak_f32 = sqrtf(VAR_MCF_uAOfsClb_f32 * VAR_MCF_uAOfsClb_f32 +
      VAR_MCF_uBOfsClb_f32 * VAR_MCF_uBOfsClb_f32);

    /* Product: '<S168>/Product' incorporates:
     *  Constant: '<S168>/CAL_MCF_cofOverModu_f32'
     *  Constant: '<S168>/MCF_GLB_SqrtThree_f32'
     *  Product: '<S168>/Divide4'
     *  Sum: '<S13>/Add'
     */
    rtb_MCF_uDcalc = VAR_MCF_uDcLnk_f32 / MCF_GLB_SqrtThree_f32 *
      CAL_MCF_cofOverModu_f32;

    /* RelationalOperator: '<S168>/Relational Operator' */
    rtb_RelationalOperator_o1 = (VAR_MCF_usPeak_f32 <= rtb_MCF_uDcalc);

    /* Switch: '<S171>/Switch' incorporates:
     *  Abs: '<S171>/Abs'
     *  Constant: '<S171>/Constant'
     *  Constant: '<S172>/Constant'
     *  RelationalOperator: '<S172>/Compare'
     */
    if (fabsf(VAR_MCF_uBOfsClb_f32) <= 0.0001F) {
      rtb_MCF_ibeta = 0.0001F;
    } else {
      rtb_MCF_ibeta = VAR_MCF_uBOfsClb_f32;
    }

    /* End of Switch: '<S171>/Switch' */

    /* Gain: '<S171>/Gain3' incorporates:
     *  Constant: '<S174>/Constant'
     *  RelationalOperator: '<S174>/Compare'
     */
    rtb_Gain3 = (uint8)((rtb_MCF_ibeta >= 0.0F) << 7);

    /* Switch: '<S171>/Switch1' incorporates:
     *  Abs: '<S171>/Abs1'
     *  Constant: '<S171>/Constant1'
     *  Constant: '<S173>/Constant'
     *  RelationalOperator: '<S173>/Compare'
     */
    if (fabsf(VAR_MCF_uAOfsClb_f32) <= 0.0001F) {
      rtb_Subtract_o = 0.0001F;
    } else {
      rtb_Subtract_o = VAR_MCF_uAOfsClb_f32;
    }

    /* End of Switch: '<S171>/Switch1' */

    /* Gain: '<S171>/Gain1' incorporates:
     *  Constant: '<S175>/Constant'
     *  RelationalOperator: '<S175>/Compare'
     */
    rtb_Gain3_o = (uint8)((rtb_Subtract_o >= 0.0F) << 7);

    /* Product: '<S171>/Divide' */
    rtb_MCF_ibeta /= rtb_Subtract_o;

    /* Abs: '<S171>/Abs2' */
    rtb_Subtract_o = fabsf(rtb_MCF_ibeta);

    /* RelationalOperator: '<S176>/Compare' incorporates:
     *  Constant: '<S176>/Constant'
     */
    rtb_TmpSignalConversionAtRP__a1 = (rtb_Subtract_o >= 1.0F);

    /* Switch: '<S171>/Switch2' incorporates:
     *  Constant: '<S171>/Constant2'
     *  Product: '<S171>/Divide1'
     */
    if (rtb_TmpSignalConversionAtRP__a1) {
      rtb_Subtract_o = 1.0F / rtb_Subtract_o;
    }

    /* End of Switch: '<S171>/Switch2' */

    /* MultiPortSwitch: '<S171>/Multiport Switch' incorporates:
     *  Constant: '<S171>/Constant10'
     *  Constant: '<S171>/Constant3'
     *  Constant: '<S171>/Constant4'
     *  Constant: '<S171>/Constant5'
     *  Constant: '<S171>/Constant7'
     *  Constant: '<S171>/Constant8'
     *  Constant: '<S171>/Constant9'
     *  Gain: '<S171>/Gain2'
     *  Gain: '<S171>/Gain4'
     *  LookupNDDirect: '<S171>/Direct Lookup Table (n-D)'
     *  Sum: '<S171>/Add'
     *  Sum: '<S171>/Add1'
     *  Sum: '<S171>/Add2'
     *  Sum: '<S171>/Add3'
     *  Sum: '<S171>/Add5'
     *  Sum: '<S171>/Add6'
     *  Sum: '<S171>/Add7'
     *  Sum: '<S171>/Add8'
     *
     * About '<S171>/Direct Lookup Table (n-D)':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     */
    switch ((sint32)((((((uint32)rtb_Gain3_o << 1) + rtb_Gain3) + ((uint32)
                (rtb_TmpSignalConversionAtRP__a1 << 7) << 2)) >> 2) >> 5)) {
     case 0:
      /* LookupNDDirect: '<S171>/Direct Lookup Table (n-D)' incorporates:
       *  Gain: '<S171>/Gain'
       *
       * About '<S171>/Direct Lookup Table (n-D)':
       *  1-dimensional Direct Look-Up returning a Scalar,
       *
       *     Remove protection against out-of-range input in generated code: 'off'
       */
      rtb_MCF_uaBase = 1024.0F * rtb_Subtract_o;
      if (rtb_MCF_uaBase > 1024.0F) {
        rtb_MCF_uaBase = 1024.0F;
      }

      rtb_Subtract_o = (float32)(58672U * rtCP_DirectLookupTablenD_tabl_h
        [(sint32)rtb_MCF_uaBase]) * 1.49011612E-8F + 180.0F;
      break;

     case 1:
      /* LookupNDDirect: '<S171>/Direct Lookup Table (n-D)' incorporates:
       *  Gain: '<S171>/Gain'
       *
       * About '<S171>/Direct Lookup Table (n-D)':
       *  1-dimensional Direct Look-Up returning a Scalar,
       *
       *     Remove protection against out-of-range input in generated code: 'off'
       */
      rtb_MCF_uaBase = 1024.0F * rtb_Subtract_o;
      if (rtb_MCF_uaBase > 1024.0F) {
        rtb_MCF_uaBase = 1024.0F;
      }

      rtb_Subtract_o = 180.0F - (float32)(58672U *
        rtCP_DirectLookupTablenD_tabl_h[(sint32)rtb_MCF_uaBase]) *
        1.49011612E-8F;
      break;

     case 2:
      /* LookupNDDirect: '<S171>/Direct Lookup Table (n-D)' incorporates:
       *  Gain: '<S171>/Gain'
       *
       * About '<S171>/Direct Lookup Table (n-D)':
       *  1-dimensional Direct Look-Up returning a Scalar,
       *
       *     Remove protection against out-of-range input in generated code: 'off'
       */
      rtb_MCF_uaBase = 1024.0F * rtb_Subtract_o;
      if (rtb_MCF_uaBase > 1024.0F) {
        rtb_MCF_uaBase = 1024.0F;
      }

      rtb_Subtract_o = 360.0F - (float32)(58672U *
        rtCP_DirectLookupTablenD_tabl_h[(sint32)rtb_MCF_uaBase]) *
        1.49011612E-8F;
      break;

     case 3:
      /* LookupNDDirect: '<S171>/Direct Lookup Table (n-D)' incorporates:
       *  Gain: '<S171>/Gain'
       *
       * About '<S171>/Direct Lookup Table (n-D)':
       *  1-dimensional Direct Look-Up returning a Scalar,
       *
       *     Remove protection against out-of-range input in generated code: 'off'
       */
      rtb_MCF_uaBase = 1024.0F * rtb_Subtract_o;
      if (rtb_MCF_uaBase > 1024.0F) {
        rtb_MCF_uaBase = 1024.0F;
      }

      rtb_Subtract_o = (float32)(58672U * rtCP_DirectLookupTablenD_tabl_h
        [(sint32)rtb_MCF_uaBase]) * 1.49011612E-8F;
      break;

     case 4:
      /* LookupNDDirect: '<S171>/Direct Lookup Table (n-D)' incorporates:
       *  Gain: '<S171>/Gain'
       *
       * About '<S171>/Direct Lookup Table (n-D)':
       *  1-dimensional Direct Look-Up returning a Scalar,
       *
       *     Remove protection against out-of-range input in generated code: 'off'
       */
      rtb_MCF_uaBase = 1024.0F * rtb_Subtract_o;
      if (rtb_MCF_uaBase > 1024.0F) {
        rtb_MCF_uaBase = 1024.0F;
      }

      rtb_Subtract_o = 270.0F - (float32)(58672U *
        rtCP_DirectLookupTablenD_tabl_h[(sint32)rtb_MCF_uaBase]) *
        1.49011612E-8F;
      break;

     case 5:
      /* LookupNDDirect: '<S171>/Direct Lookup Table (n-D)' incorporates:
       *  Gain: '<S171>/Gain'
       *
       * About '<S171>/Direct Lookup Table (n-D)':
       *  1-dimensional Direct Look-Up returning a Scalar,
       *
       *     Remove protection against out-of-range input in generated code: 'off'
       */
      rtb_MCF_uaBase = 1024.0F * rtb_Subtract_o;
      if (rtb_MCF_uaBase > 1024.0F) {
        rtb_MCF_uaBase = 1024.0F;
      }

      rtb_Subtract_o = (float32)(58672U * rtCP_DirectLookupTablenD_tabl_h
        [(sint32)rtb_MCF_uaBase]) * 1.49011612E-8F + 90.0F;
      break;

     case 6:
      /* LookupNDDirect: '<S171>/Direct Lookup Table (n-D)' incorporates:
       *  Gain: '<S171>/Gain'
       *
       * About '<S171>/Direct Lookup Table (n-D)':
       *  1-dimensional Direct Look-Up returning a Scalar,
       *
       *     Remove protection against out-of-range input in generated code: 'off'
       */
      rtb_MCF_uaBase = 1024.0F * rtb_Subtract_o;
      if (rtb_MCF_uaBase > 1024.0F) {
        rtb_MCF_uaBase = 1024.0F;
      }

      rtb_Subtract_o = (float32)(58672U * rtCP_DirectLookupTablenD_tabl_h
        [(sint32)rtb_MCF_uaBase]) * 1.49011612E-8F + 270.0F;
      break;

     default:
      /* LookupNDDirect: '<S171>/Direct Lookup Table (n-D)' incorporates:
       *  Gain: '<S171>/Gain'
       *
       * About '<S171>/Direct Lookup Table (n-D)':
       *  1-dimensional Direct Look-Up returning a Scalar,
       *
       *     Remove protection against out-of-range input in generated code: 'off'
       */
      rtb_MCF_uaBase = 1024.0F * rtb_Subtract_o;
      if (rtb_MCF_uaBase > 1024.0F) {
        rtb_MCF_uaBase = 1024.0F;
      }

      rtb_Subtract_o = 90.0F - (float32)(58672U *
        rtCP_DirectLookupTablenD_tabl_h[(sint32)rtb_MCF_uaBase]) *
        1.49011612E-8F;
      break;
    }

    /* End of MultiPortSwitch: '<S171>/Multiport Switch' */

    /* Sum: '<S170>/Add3' incorporates:
     *  Constant: '<S170>/angle'
     *  DataTypeConversion: '<S170>/Data Type Conversion2'
     *  Product: '<S170>/Divide2'
     *  Product: '<S170>/Divide3'
     */
    VAR_MCF_AgRem_f32 = rtb_Subtract_o - (float32)(sint32)fmodf(floorf
      (rtb_Subtract_o / 60.0F), 256.0F) * 60.0F;

    /* Saturate: '<S168>/Saturation' */
    if (rtb_MCF_uDcalc > 1000.0F) {
      rtb_MCF_uDcalc = 1000.0F;
    } else {
      if (rtb_MCF_uDcalc < 0.001F) {
        rtb_MCF_uDcalc = 0.001F;
      }
    }

    /* End of Saturate: '<S168>/Saturation' */

    /* Product: '<S168>/Divide2' */
    SWC_MCF_B.Divide2 = VAR_MCF_usPeak_f32 / rtb_MCF_uDcalc;

    /* Switch: '<S168>/Switch' incorporates:
     *  Constant: '<S168>/ADValue'
     *  Constant: '<S168>/CAL_MCF_cofOverModu_f32'
     *  Constant: '<S168>/Constant'
     *  Constant: '<S168>/MCF_GLB_Sixty_f32  '
     *  Lookup_n-D: '<S168>/OmTable'
     *  Product: '<S168>/Divide3'
     *  Product: '<S168>/Product1'
     */
    if (rtb_RelationalOperator_o1) {
      rtb_Subtract_o = 1.0F;
    } else {
      rtb_Subtract_o = look2_iflf_binlxpw(VAR_MCF_AgRem_f32 * 1023.0F /
        MCF_GLB_Sixty_f32, SWC_MCF_B.Divide2, rtCP_OmTable_bp01Data,
        rtCP_OmTable_bp02Data, rtCP_OmTable_tableData, rtCP_OmTable_maxIndex,
        1024U) * CAL_MCF_cofOverModu_f32;
    }

    /* End of Switch: '<S168>/Switch' */

    /* Product: '<S168>/Divide' */
    VAR_MCF_uAOm_f32 = VAR_MCF_uAOfsClb_f32 * rtb_Subtract_o;

    /* Product: '<S168>/Divide1' */
    VAR_MCF_uBOm_f32 = rtb_Subtract_o * VAR_MCF_uBOfsClb_f32;
    rtb_TmpSignalConversionAtRP_S_j = VAR_MCF_uAOm_f32;
    rtb_MCF_uBCalc = VAR_MCF_uBOm_f32;
  } else {
    rtb_TmpSignalConversionAtRP_S_j = VAR_MCF_uAOfsClb_f32;
    rtb_MCF_uBCalc = VAR_MCF_uBOfsClb_f32;
  }
  GLB_MCF_uA_f32 = rtb_TmpSignalConversionAtRP_S_j;
  GLB_MCF_uB_f32 = rtb_MCF_uBCalc;
  /* End of Switch: '<S117>/Switch' */
  /* End of Outputs for SubSystem: '<S117>/MCF_OverModuEn' */

  /* Product: '<S127>/Product' incorporates:
   *  Constant: '<S127>/MCF_GLB_OneHalf_f32'
   */
  rtb_Subtract_o = rtb_TmpSignalConversionAtRP_S_j * MCF_GLB_OneHalf_f32;

  /* Product: '<S127>/Product1' incorporates:
   *  Constant: '<S127>/cofClark2'
   */
  rtb_MCF_uaBase = rtb_MCF_uBCalc * 0.866F;

  /* Sum: '<S127>/Add' */
  rtb_MCF_ibeta = rtb_MCF_uaBase - rtb_Subtract_o;

  /* Sum: '<S127>/Add1' */
  rtb_MCF_uDcalc = (0.0F - rtb_Subtract_o) - rtb_MCF_uaBase;

  /* Product: '<S127>/Product2' incorporates:
   *  Constant: '<S127>/MCF_GLB_OneHalf_f32'
   *  Sum: '<S13>/Add'
   */
  rtb_Subtract_o = VAR_MCF_uDcLnk_f32 * MCF_GLB_OneHalf_f32;

  /* Saturate: '<S127>/Saturation' */
  if (rtb_Subtract_o > 700.0F) {
    rtb_Subtract_o = 700.0F;
  } else {
    if (rtb_Subtract_o < 0.0001F) {
      rtb_Subtract_o = 0.0001F;
    }
  }

  /* End of Saturate: '<S127>/Saturation' */

  /* Product: '<S127>/Divide' */
  rtb_MCF_uaBase = rtb_TmpSignalConversionAtRP_S_j / rtb_Subtract_o;

  /* Product: '<S127>/Divide1' */
  rtb_MCF_ubBase = rtb_MCF_ibeta / rtb_Subtract_o;

  /* Product: '<S127>/Divide2' */
  rtb_Subtract_o = rtb_MCF_uDcalc / rtb_Subtract_o;

  /* Switch: '<S128>/Switch4' incorporates:
   *  RelationalOperator: '<S128>/Relational Operator'
   */
  if (rtb_MCF_uaBase <= rtb_MCF_ubBase) {
    rtb_MCF_ialpha = rtb_MCF_uaBase;
  } else {
    rtb_MCF_ialpha = rtb_MCF_ubBase;
  }

  /* End of Switch: '<S128>/Switch4' */

  /* Switch: '<S128>/Switch6' incorporates:
   *  RelationalOperator: '<S128>/Relational Operator2'
   */
  if (rtb_MCF_ialpha > rtb_Subtract_o) {
    rtb_MCF_ialpha = rtb_Subtract_o;
  }

  /* End of Switch: '<S128>/Switch6' */

  /* Switch: '<S128>/Switch5' incorporates:
   *  RelationalOperator: '<S128>/Relational Operator8'
   */
  if (rtb_MCF_uaBase >= rtb_MCF_ubBase) {
    rtb_MCF_uDcalc = rtb_MCF_uaBase;
  } else {
    rtb_MCF_uDcalc = rtb_MCF_ubBase;
  }

  /* End of Switch: '<S128>/Switch5' */

  /* Switch: '<S128>/Switch7' incorporates:
   *  RelationalOperator: '<S128>/Relational Operator9'
   */
  if (rtb_MCF_uDcalc < rtb_Subtract_o) {
    rtb_MCF_uDcalc = rtb_Subtract_o;
  }

  /* End of Switch: '<S128>/Switch7' */

  /* MultiPortSwitch: '<S130>/Multiport Switch' incorporates:
   *  Constant: '<S128>/MCF_GLB_OneHalf_f32'
   *  Constant: '<S130>/CAL_MCF_stDpwm_u8'
   *  Constant: '<S130>/MCF_GLB_OneHalf_f32'
   *  Product: '<S128>/Product2'
   *  Product: '<S128>/Product3'
   *  Product: '<S130>/Product'
   *  Product: '<S130>/Product1'
   *  Product: '<S130>/Product3'
   *  Product: '<S130>/Product5'
   *  Product: '<S130>/Product6'
   *  Sum: '<S130>/Add1'
   *  Sum: '<S130>/Add10'
   */
  switch (CAL_MCF_stDpwm_u8) {
   case 1:
    rtb_MCF_uDcalc = rtb_Subtract_cm * MCF_GLB_OneHalf_f32 * MCF_GLB_OneHalf_f32;
    break;

   case 2:
    rtb_MCF_uDcalc = ((rtb_MCF_ialpha * rtb_Subtract_cm * MCF_GLB_OneHalf_f32 *
                       MCF_GLB_OneHalf_f32 + rtb_Subtract_cm *
                       MCF_GLB_OneHalf_f32) + rtb_MCF_uDcalc * rtb_Subtract_cm *
                      MCF_GLB_OneHalf_f32 * MCF_GLB_OneHalf_f32) *
      MCF_GLB_OneHalf_f32;
    break;

   case 3:
    /* Switch: '<S130>/Switch' incorporates:
     *  Constant: '<S128>/MCF_GLB_OneHalf_f32'
     *  Constant: '<S130>/MCF_GLB_OneHalf_f32'
     *  Logic: '<S128>/Logical Operator'
     *  Logic: '<S128>/Logical Operator1'
     *  Logic: '<S128>/Logical Operator2'
     *  Logic: '<S128>/Logical Operator3'
     *  Logic: '<S130>/Logical Operator4'
     *  Product: '<S128>/Product2'
     *  Product: '<S128>/Product3'
     *  Product: '<S130>/Product3'
     *  Product: '<S130>/Product5'
     *  Product: '<S130>/Product6'
     *  RelationalOperator: '<S128>/Relational Operator1'
     *  RelationalOperator: '<S128>/Relational Operator3'
     *  RelationalOperator: '<S128>/Relational Operator4'
     *  RelationalOperator: '<S128>/Relational Operator5'
     *  RelationalOperator: '<S128>/Relational Operator6'
     *  RelationalOperator: '<S128>/Relational Operator7'
     *  Sum: '<S130>/Add3'
     */
    if (((rtb_MCF_uaBase <= rtb_MCF_ubBase) || (rtb_MCF_ubBase <= rtb_Subtract_o))
        && ((rtb_MCF_ubBase <= rtb_Subtract_o) || (rtb_Subtract_o <=
          rtb_MCF_uaBase)) && ((rtb_Subtract_o <= rtb_MCF_uaBase) ||
         (rtb_MCF_uaBase <= rtb_MCF_ubBase))) {
      rtb_MCF_uDcalc = rtb_MCF_uDcalc * rtb_Subtract_cm * MCF_GLB_OneHalf_f32 *
        MCF_GLB_OneHalf_f32;
    } else {
      rtb_MCF_uDcalc = rtb_MCF_ialpha * rtb_Subtract_cm * MCF_GLB_OneHalf_f32 *
        MCF_GLB_OneHalf_f32 + rtb_Subtract_cm * MCF_GLB_OneHalf_f32;
    }

    /* End of Switch: '<S130>/Switch' */
    break;

   case 4:
    /* Switch: '<S130>/Switch1' incorporates:
     *  Constant: '<S128>/MCF_GLB_OneHalf_f32'
     *  Constant: '<S130>/MCF_GLB_OneHalf_f32'
     *  Logic: '<S128>/Logical Operator'
     *  Logic: '<S128>/Logical Operator1'
     *  Logic: '<S128>/Logical Operator2'
     *  Logic: '<S128>/Logical Operator3'
     *  Product: '<S128>/Product2'
     *  Product: '<S128>/Product3'
     *  Product: '<S130>/Product3'
     *  Product: '<S130>/Product5'
     *  Product: '<S130>/Product6'
     *  RelationalOperator: '<S128>/Relational Operator1'
     *  RelationalOperator: '<S128>/Relational Operator3'
     *  RelationalOperator: '<S128>/Relational Operator4'
     *  RelationalOperator: '<S128>/Relational Operator5'
     *  RelationalOperator: '<S128>/Relational Operator6'
     *  RelationalOperator: '<S128>/Relational Operator7'
     *  Sum: '<S130>/Add5'
     */
    if (((rtb_MCF_uaBase > rtb_MCF_ubBase) && (rtb_MCF_ubBase > rtb_Subtract_o))
        || ((rtb_MCF_ubBase > rtb_Subtract_o) && (rtb_Subtract_o >
          rtb_MCF_uaBase)) || ((rtb_Subtract_o > rtb_MCF_uaBase) &&
         (rtb_MCF_uaBase > rtb_MCF_ubBase))) {
      rtb_MCF_uDcalc = rtb_MCF_uDcalc * rtb_Subtract_cm * MCF_GLB_OneHalf_f32 *
        MCF_GLB_OneHalf_f32;
    } else {
      rtb_MCF_uDcalc = rtb_MCF_ialpha * rtb_Subtract_cm * MCF_GLB_OneHalf_f32 *
        MCF_GLB_OneHalf_f32 + rtb_Subtract_cm * MCF_GLB_OneHalf_f32;
    }

    /* End of Switch: '<S130>/Switch1' */
    break;

   case 5:
    /* Switch: '<S130>/Switch2' incorporates:
     *  Constant: '<S128>/MCF_GLB_OneHalf_f32'
     *  Constant: '<S130>/Constant'
     *  Constant: '<S130>/MCF_GLB_OneHalf_f32'
     *  Product: '<S128>/Product2'
     *  Product: '<S128>/Product3'
     *  Product: '<S130>/Product2'
     *  Product: '<S130>/Product3'
     *  Product: '<S130>/Product4'
     *  Product: '<S130>/Product5'
     *  Product: '<S130>/Product6'
     *  RelationalOperator: '<S130>/Relational Operator'
     *  Sum: '<S130>/Add6'
     *  Sum: '<S130>/Add7'
     */
    if (rtb_MCF_uDcalc * MCF_GLB_OneHalf_f32 + rtb_MCF_ialpha *
        MCF_GLB_OneHalf_f32 >= 0.0F) {
      rtb_MCF_uDcalc = rtb_MCF_uDcalc * rtb_Subtract_cm * MCF_GLB_OneHalf_f32 *
        MCF_GLB_OneHalf_f32;
    } else {
      rtb_MCF_uDcalc = rtb_MCF_ialpha * rtb_Subtract_cm * MCF_GLB_OneHalf_f32 *
        MCF_GLB_OneHalf_f32 + rtb_Subtract_cm * MCF_GLB_OneHalf_f32;
    }

    /* End of Switch: '<S130>/Switch2' */
    break;

   case 6:
    /* Switch: '<S130>/Switch3' incorporates:
     *  Constant: '<S128>/MCF_GLB_OneHalf_f32'
     *  Constant: '<S130>/Constant1'
     *  Constant: '<S130>/MCF_GLB_OneHalf_f32'
     *  Product: '<S128>/Product2'
     *  Product: '<S128>/Product3'
     *  Product: '<S130>/Product2'
     *  Product: '<S130>/Product3'
     *  Product: '<S130>/Product4'
     *  Product: '<S130>/Product5'
     *  Product: '<S130>/Product6'
     *  RelationalOperator: '<S130>/Relational Operator1'
     *  Sum: '<S130>/Add8'
     *  Sum: '<S130>/Add9'
     */
    if (rtb_MCF_uDcalc * MCF_GLB_OneHalf_f32 + rtb_MCF_ialpha *
        MCF_GLB_OneHalf_f32 < 0.0F) {
      rtb_MCF_uDcalc = rtb_MCF_uDcalc * rtb_Subtract_cm * MCF_GLB_OneHalf_f32 *
        MCF_GLB_OneHalf_f32;
    } else {
      rtb_MCF_uDcalc = rtb_MCF_ialpha * rtb_Subtract_cm * MCF_GLB_OneHalf_f32 *
        MCF_GLB_OneHalf_f32 + rtb_Subtract_cm * MCF_GLB_OneHalf_f32;
    }

    /* End of Switch: '<S130>/Switch3' */
    break;

   case 7:
    rtb_MCF_uDcalc = rtb_MCF_uDcalc * rtb_Subtract_cm * MCF_GLB_OneHalf_f32 *
      MCF_GLB_OneHalf_f32;
    break;

   case 8:
    rtb_MCF_uDcalc = rtb_MCF_ialpha * rtb_Subtract_cm * MCF_GLB_OneHalf_f32 *
      MCF_GLB_OneHalf_f32 + rtb_Subtract_cm * MCF_GLB_OneHalf_f32;
    break;

   default:
    rtb_MCF_uDcalc = ((rtb_MCF_ialpha * rtb_Subtract_cm * MCF_GLB_OneHalf_f32 *
                       MCF_GLB_OneHalf_f32 + rtb_Subtract_cm *
                       MCF_GLB_OneHalf_f32) + rtb_MCF_uDcalc * rtb_Subtract_cm *
                      MCF_GLB_OneHalf_f32 * MCF_GLB_OneHalf_f32) *
      MCF_GLB_OneHalf_f32;
    break;
  }

  /* End of MultiPortSwitch: '<S130>/Multiport Switch' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_MCF_100us' */

  /* Inport: '<Root>/RP_SWC_SCF_SCF_stPwmMode' */
  Rte_Read_RP_SWC_SCF_SCF_stPwmMode(&rtb_MCF_stN);

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_MCF_100us' incorporates:
   *  SubSystem: '<Root>/RE_SWC_MCF_100us_sys'
   */
  /* Product: '<S129>/Product2' incorporates:
   *  Constant: '<S129>/cofGenDpwm'
   *  Constant: '<S129>/cofGenDpwm1'
   *  Product: '<S129>/Product'
   *  Product: '<S129>/Product1'
   *  Sum: '<S129>/Add2'
   */
  rtb_MCF_ibeta = (rtb_MCF_uaBase * rtb_Subtract_cm * -0.25F + rtb_MCF_uDcalc) *
    2.0F;

  /* Product: '<S129>/Product5' incorporates:
   *  Constant: '<S129>/cofGenDpwm'
   *  Constant: '<S129>/cofGenDpwm1'
   *  Product: '<S129>/Product3'
   *  Product: '<S129>/Product4'
   *  Sum: '<S129>/Add4'
   */
  rtb_MCF_ubBase = (rtb_MCF_ubBase * rtb_Subtract_cm * -0.25F + rtb_MCF_uDcalc) *
    2.0F;

  /* Product: '<S129>/Product8' incorporates:
   *  Constant: '<S129>/cofGenDpwm'
   *  Constant: '<S129>/cofGenDpwm1'
   *  Product: '<S129>/Product6'
   *  Product: '<S129>/Product7'
   *  Sum: '<S129>/Add6'
   */
  rtb_Subtract_o = (rtb_Subtract_o * rtb_Subtract_cm * -0.25F + rtb_MCF_uDcalc) *
    2.0F;

  /* Switch: '<S121>/Switch' incorporates:
   *  Constant: '<S106>/CAL_MCF_FlgUpdateDyc_b'
   */
  if (CAL_MCF_FlgUseSetDyc_b) {
    /* Outport: '<Root>/PP_SWC_MCF_MCF_stPwmMode' incorporates:
     *  Constant: '<S106>/CAL_MCF_stPwmMode_u8'
     */
    (void) Rte_Write_PP_SWC_MCF_MCF_stPwmMode(CAL_MCF_stPwmMode_u8);
  } else {
    /* Outport: '<Root>/PP_SWC_MCF_MCF_stPwmMode' */
    (void) Rte_Write_PP_SWC_MCF_MCF_stPwmMode(rtb_MCF_stN);
  }

  /* End of Switch: '<S121>/Switch' */

  /* Outport: '<Root>/PP_SWC_MCF_MCF_tiLock' incorporates:
   *  Lookup_n-D: '<S121>/DeadTimeTable'
   */
  (void) Rte_Write_PP_SWC_MCF_MCF_tiLock(look1_iflf_binlcpw(rtb_MCF_frqPwmCalc_j,
    ((const float32 *)&(CAL_MCF_DeadTimeTableX_Frq_af32[0])), ((const float32 *)
    &(CAL_MCF_DeadTimeTableY_Ti_af32[0])), 14U));

  /* Switch: '<S122>/Switch' incorporates:
   *  Constant: '<S122>/CAL_MCF_nDpwmOffDelay_f32'
   *  Constant: '<S122>/CAL_MCF_nDpwmOff_f32'
   *  Constant: '<S122>/Constant1'
   *  RelationalOperator: '<S122>/Relational Operator'
   *  RelationalOperator: '<S122>/Relational Operator2'
   *  UnitDelay: '<S122>/Unit Delay'
   */
  if (rtb_Saturation_e >= CAL_MCF_nDpwmOff_f32) {
    SWC_MCF_DW.UnitDelay_DSTATE_ns = false;
  } else {
    SWC_MCF_DW.UnitDelay_DSTATE_ns = ((rtb_Saturation_e <=
      CAL_MCF_nDpwmOffDelay_f32) || SWC_MCF_DW.UnitDelay_DSTATE_ns);
  }

  /* End of Switch: '<S122>/Switch' */

  /* Sum: '<S146>/Add1' */
  rtb_MCF_uBCalc += VAR_MCF_uBetaDeadCpn_f32;

  /* Sum: '<S146>/Add' */
  rtb_TmpSignalConversionAtRP_S_j += VAR_MCF_uAlphaDeadCpn_f32;

  /* Product: '<S147>/Product' incorporates:
   *  Constant: '<S147>/cofstN1'
   */
  rtb_MCF_uDcalc = rtb_TmpSignalConversionAtRP_S_j * 0.866F;

  /* Product: '<S147>/Product1' incorporates:
   *  Constant: '<S147>/MCF_GLB_OneHalf_f32'
   *  Product: '<S148>/Product1'
   */
  rtb_Saturation_e = rtb_MCF_uBCalc * MCF_GLB_OneHalf_f32;

  /* Sum: '<S147>/Add2' incorporates:
   *  Constant: '<S154>/Constant'
   *  Constant: '<S155>/Constant'
   *  Constant: '<S156>/Constant'
   *  Product: '<S147>/Product1'
   *  Product: '<S147>/Product2'
   *  Product: '<S147>/Product3'
   *  RelationalOperator: '<S154>/Compare'
   *  RelationalOperator: '<S155>/Compare'
   *  RelationalOperator: '<S156>/Compare'
   *  Sum: '<S147>/Add'
   *  Sum: '<S147>/Add1'
   */
  rtb_MCF_stN = (uint8)(((uint32)((rtb_MCF_uDcalc - rtb_Saturation_e > 0.0F) <<
    1) + (rtb_MCF_uBCalc > 0.0F)) + (((0.0F - rtb_MCF_uDcalc) - rtb_Saturation_e
    > 0.0F) << 2));

  /* Saturate: '<S147>/Saturation' */
  if (rtb_MCF_stN > 6) {
    rtb_MCF_stN = 6U;
  } else {
    if (rtb_MCF_stN < 1) {
      rtb_MCF_stN = 1U;
    }
  }

  /* End of Saturate: '<S147>/Saturation' */

  /* Product: '<S148>/Product3' incorporates:
   *  Constant: '<S148>/coftiCalc2'
   */
  rtb_TmpSignalConversionAtRP_S_j *= 0.866F;

  /* Saturate: '<S148>/Saturation' incorporates:
   *  Sum: '<S13>/Add'
   */
  if (VAR_MCF_uDcLnk_f32 > 1000.0F) {
    rtb_MCF_uaBase = 1000.0F;
  } else if (VAR_MCF_uDcLnk_f32 < 0.0001F) {
    rtb_MCF_uaBase = 0.0001F;
  } else {
    rtb_MCF_uaBase = VAR_MCF_uDcLnk_f32;
  }

  /* End of Saturate: '<S148>/Saturation' */

  /* Product: '<S148>/Product4' incorporates:
   *  Constant: '<S148>/MCF_GLB_SqrtThree_f32'
   *  Product: '<S148>/Divide1'
   */
  rtb_MCF_ialpha = rtb_Subtract_cm / rtb_MCF_uaBase * MCF_GLB_SqrtThree_f32;

  /* SwitchCase: '<S148>/if' incorporates:
   *  Inport: '<S159>/MCF_tiY'
   *  Inport: '<S159>/MCF_tiZ'
   *  Inport: '<S160>/MCF_tiY'
   *  Inport: '<S161>/MCF_stXin'
   *  Inport: '<S162>/MCF_tiZ'
   *  Inport: '<S163>/MCF_stXin'
   *  Product: '<S148>/Product'
   *  Product: '<S148>/Product2'
   *  Product: '<S148>/Product7'
   *  Sum: '<S148>/Add1'
   *  Sum: '<S148>/Add2'
   */
  switch (rtb_MCF_stN) {
   case 1:
    /* Outputs for IfAction SubSystem: '<S148>/Osc_nrN1' incorporates:
     *  ActionPort: '<S159>/ActionPort'
     */
    rtb_MCF_uDcalc = (rtb_Saturation_e - rtb_TmpSignalConversionAtRP_S_j) *
      rtb_MCF_ialpha;
    rtb_MCF_uaBase = (rtb_Saturation_e + rtb_TmpSignalConversionAtRP_S_j) *
      rtb_MCF_ialpha;

    /* End of Outputs for SubSystem: '<S148>/Osc_nrN1' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S148>/Osc_nrN2' incorporates:
     *  ActionPort: '<S160>/ActionPort'
     */
    rtb_MCF_uDcalc = (rtb_Saturation_e + rtb_TmpSignalConversionAtRP_S_j) *
      rtb_MCF_ialpha;

    /* Gain: '<S160>/Gain' incorporates:
     *  Inport: '<S160>/MCF_tiY'
     *  Product: '<S148>/Product'
     *  Product: '<S148>/Product2'
     *  Sum: '<S148>/Add2'
     */
    rtb_MCF_uaBase = -(rtb_MCF_uBCalc * rtb_MCF_ialpha);

    /* End of Outputs for SubSystem: '<S148>/Osc_nrN2' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S148>/Osc_nrN3' incorporates:
     *  ActionPort: '<S161>/ActionPort'
     */
    /* Gain: '<S161>/Gain' incorporates:
     *  Product: '<S148>/Product7'
     *  Sum: '<S148>/Add1'
     */
    rtb_MCF_uDcalc = -((rtb_Saturation_e - rtb_TmpSignalConversionAtRP_S_j) *
                       rtb_MCF_ialpha);
    rtb_MCF_uaBase = rtb_MCF_uBCalc * rtb_MCF_ialpha;

    /* End of Outputs for SubSystem: '<S148>/Osc_nrN3' */
    break;

   case 4:
    /* Outputs for IfAction SubSystem: '<S148>/Osc_nrN4' incorporates:
     *  ActionPort: '<S162>/ActionPort'
     */
    /* Gain: '<S162>/Gain' incorporates:
     *  Product: '<S148>/Product'
     */
    rtb_MCF_uDcalc = -(rtb_MCF_uBCalc * rtb_MCF_ialpha);
    rtb_MCF_uaBase = (rtb_Saturation_e - rtb_TmpSignalConversionAtRP_S_j) *
      rtb_MCF_ialpha;

    /* End of Outputs for SubSystem: '<S148>/Osc_nrN4' */
    break;

   case 5:
    /* Outputs for IfAction SubSystem: '<S148>/Osc_nrN5' incorporates:
     *  ActionPort: '<S163>/ActionPort'
     */
    rtb_MCF_uDcalc = rtb_MCF_uBCalc * rtb_MCF_ialpha;

    /* Gain: '<S163>/Gain' incorporates:
     *  Inport: '<S163>/MCF_stXin'
     *  Product: '<S148>/Product'
     *  Product: '<S148>/Product2'
     *  Sum: '<S148>/Add2'
     */
    rtb_MCF_uaBase = -((rtb_Saturation_e + rtb_TmpSignalConversionAtRP_S_j) *
                       rtb_MCF_ialpha);

    /* End of Outputs for SubSystem: '<S148>/Osc_nrN5' */
    break;

   default:
    /* Outputs for IfAction SubSystem: '<S148>/Osc_nrN6' incorporates:
     *  ActionPort: '<S164>/ActionPort'
     */
    SWC_MCF_Osc_nrN6((rtb_Saturation_e + rtb_TmpSignalConversionAtRP_S_j) *
                     rtb_MCF_ialpha, (rtb_Saturation_e -
      rtb_TmpSignalConversionAtRP_S_j) * rtb_MCF_ialpha, &rtb_MCF_uDcalc,
                     &rtb_MCF_uaBase);

    /* End of Outputs for SubSystem: '<S148>/Osc_nrN6' */
    break;
  }

  /* End of SwitchCase: '<S148>/if' */

  /* Outputs for IfAction SubSystem: '<S144>/Svpwm_tiOverLim' incorporates:
   *  ActionPort: '<S151>/ActionPort'
   */
  /* If: '<S144>/If' incorporates:
   *  Inport: '<S150>/MCF_tiT2'
   *  Sum: '<S144>/Add'
   *  Sum: '<S144>/Add1'
   *  Sum: '<S151>/Add'
   */
  rtb_Saturation_e = rtb_MCF_uDcalc + rtb_MCF_uaBase;

  /* End of Outputs for SubSystem: '<S144>/Svpwm_tiOverLim' */
  if (rtb_Saturation_e - rtb_Subtract_cm > 0.0F) {
    /* Outputs for IfAction SubSystem: '<S144>/Svpwm_tiOverLim' incorporates:
     *  ActionPort: '<S151>/ActionPort'
     */
    /* Saturate: '<S151>/Saturation' */
    if (rtb_Saturation_e > 1024.0F) {
      rtb_Saturation_e = 1024.0F;
    } else {
      if (rtb_Saturation_e < 1.0E-9F) {
        rtb_Saturation_e = 1.0E-9F;
      }
    }

    /* End of Saturate: '<S151>/Saturation' */

    /* Product: '<S151>/Divide' */
    rtb_MCF_uDcalc = rtb_Subtract_cm * rtb_MCF_uDcalc / rtb_Saturation_e;

    /* Product: '<S151>/Divide1' */
    rtb_MCF_ialpha = rtb_Subtract_cm * rtb_MCF_uaBase / rtb_Saturation_e;

    /* End of Outputs for SubSystem: '<S144>/Svpwm_tiOverLim' */
  } else {
    /* Outputs for IfAction SubSystem: '<S144>/Svpwm_tiLim' incorporates:
     *  ActionPort: '<S150>/ActionPort'
     */
    rtb_MCF_ialpha = rtb_MCF_uaBase;

    /* End of Outputs for SubSystem: '<S144>/Svpwm_tiLim' */
  }

  /* End of If: '<S144>/If' */

  /* Sum: '<S145>/Add5' incorporates:
   *  Constant: '<S145>/MCF_GLB_OneHalf_f32'
   *  Product: '<S145>/Product1'
   *  Product: '<S145>/Product2'
   *  Product: '<S145>/Product3'
   */
  rtb_Saturation_e = (rtb_Subtract_cm * MCF_GLB_OneHalf_f32 +
                      MCF_GLB_OneHalf_f32 * rtb_MCF_uDcalc) +
    MCF_GLB_OneHalf_f32 * rtb_MCF_ialpha;

  /* Sum: '<S145>/Add6' */
  rtb_MCF_uDcalc = rtb_Saturation_e - rtb_MCF_uDcalc;

  /* MultiPortSwitch: '<S145>/MultiportSwitch' incorporates:
   *  Sum: '<S145>/Add7'
   */
  switch (rtb_MCF_stN) {
   case 1:
    rtb_MCF_uBCalc = rtb_MCF_uDcalc;

    /* MultiPortSwitch: '<S145>/MultiportSwitch1' */
    rtb_MCF_uaBase = rtb_Saturation_e;

    /* MultiPortSwitch: '<S145>/MultiportSwitch2' incorporates:
     *  Sum: '<S145>/Add7'
     */
    rtb_Saturation_e = rtb_MCF_uDcalc - rtb_MCF_ialpha;
    break;

   case 2:
    rtb_MCF_uBCalc = rtb_Saturation_e;

    /* MultiPortSwitch: '<S145>/MultiportSwitch1' incorporates:
     *  Sum: '<S145>/Add7'
     */
    rtb_MCF_uaBase = rtb_MCF_uDcalc - rtb_MCF_ialpha;

    /* MultiPortSwitch: '<S145>/MultiportSwitch2' */
    rtb_Saturation_e = rtb_MCF_uDcalc;
    break;

   case 3:
    rtb_MCF_uBCalc = rtb_Saturation_e;

    /* MultiPortSwitch: '<S145>/MultiportSwitch1' */
    rtb_MCF_uaBase = rtb_MCF_uDcalc;

    /* MultiPortSwitch: '<S145>/MultiportSwitch2' incorporates:
     *  Sum: '<S145>/Add7'
     */
    rtb_Saturation_e = rtb_MCF_uDcalc - rtb_MCF_ialpha;
    break;

   case 4:
    rtb_MCF_uBCalc = rtb_MCF_uDcalc - rtb_MCF_ialpha;

    /* MultiPortSwitch: '<S145>/MultiportSwitch1' incorporates:
     *  Sum: '<S145>/Add7'
     */
    rtb_MCF_uaBase = rtb_MCF_uDcalc;
    break;

   case 5:
    rtb_MCF_uBCalc = rtb_MCF_uDcalc - rtb_MCF_ialpha;

    /* MultiPortSwitch: '<S145>/MultiportSwitch1' incorporates:
     *  Sum: '<S145>/Add7'
     */
    rtb_MCF_uaBase = rtb_Saturation_e;

    /* MultiPortSwitch: '<S145>/MultiportSwitch2' */
    rtb_Saturation_e = rtb_MCF_uDcalc;
    break;

   default:
    rtb_MCF_uBCalc = rtb_MCF_uDcalc;

    /* MultiPortSwitch: '<S145>/MultiportSwitch1' incorporates:
     *  Sum: '<S145>/Add7'
     */
    rtb_MCF_uaBase = rtb_MCF_uDcalc - rtb_MCF_ialpha;
    break;
  }

  /* End of MultiPortSwitch: '<S145>/MultiportSwitch' */

  /* Chart: '<S123>/ModuSele' incorporates:
   *  Constant: '<S122>/CAL_MCF_flgDpwm_b'
   *  Constant: '<S122>/CAL_MCF_trqDpwmOff_f32'
   *  Logic: '<S122>/Logical Operator'
   *  RelationalOperator: '<S122>/Relational Operator1'
   *  Sum: '<S129>/Add1'
   *  Sum: '<S129>/Add3'
   *  Sum: '<S129>/Add5'
   *  UnitDelay: '<S122>/Unit Delay'
   */
  if ((rtb_Subtract2_k <= CAL_MCF_trqDpwmOff_f32) &&
      SWC_MCF_DW.UnitDelay_DSTATE_ns && CAL_MCF_flgDpwm_b) {
    rtb_MCF_uBCalc = rtb_Subtract_cm - rtb_MCF_ibeta;
    rtb_MCF_uaBase = rtb_Subtract_cm - rtb_MCF_ubBase;
    rtb_Saturation_e = rtb_Subtract_cm - rtb_Subtract_o;
  }

  /* End of Chart: '<S123>/ModuSele' */

  /* Switch: '<S139>/Switch' incorporates:
   *  RelationalOperator: '<S139>/Relational Operator'
   */
  if (rtb_MCF_uBCalc >= rtb_MCF_uaBase) {
    rtb_MCF_uDcalc = rtb_MCF_uBCalc;
  } else {
    rtb_MCF_uDcalc = rtb_MCF_uaBase;
  }

  /* End of Switch: '<S139>/Switch' */

  /* Switch: '<S139>/Switch1' incorporates:
   *  RelationalOperator: '<S139>/Relational Operator1'
   */
  if (rtb_MCF_uDcalc < rtb_Saturation_e) {
    rtb_MCF_uDcalc = rtb_Saturation_e;
  }

  /* End of Switch: '<S139>/Switch1' */

  /* Sum: '<S139>/Add4' */
  rtb_MCF_uDcalc = rtb_Subtract_cm - rtb_MCF_uDcalc;

  /* Sum: '<S139>/Add' */
  rtb_Subtract2_k = rtb_MCF_uBCalc + rtb_MCF_uDcalc;

  /* Sum: '<S139>/Add1' */
  rtb_Subtract_o = rtb_MCF_uaBase + rtb_MCF_uDcalc;

  /* Sum: '<S139>/Add2' */
  rtb_MCF_ibeta = rtb_Saturation_e + rtb_MCF_uDcalc;

  /* Sum: '<S140>/Add1' incorporates:
   *  Constant: '<S140>/CAL_MCF_ratNarrWave_f32'
   *  Constant: '<S140>/tiBase'
   *  Product: '<S140>/Product'
   */
  rtb_MCF_uDcalc = rtb_Subtract_cm - CAL_MCF_ratNarrWave_f32 * 1.0E-6F;

  /* Chart: '<S140>/Chart' incorporates:
   *  Constant: '<S140>/CAL_MCF_flgNWS_b'
   *  Logic: '<S140>/Logical Operator3'
   *  RelationalOperator: '<S140>/Relational Operator10'
   *  RelationalOperator: '<S140>/Relational Operator11'
   *  RelationalOperator: '<S140>/Relational Operator9'
   */
  if (CAL_MCF_flgNWS_b && ((rtb_MCF_uBCalc >= rtb_MCF_uDcalc) || (rtb_MCF_uaBase
        >= rtb_MCF_uDcalc) || (rtb_Saturation_e >= rtb_MCF_uDcalc))) {
    rtb_MCF_uBCalc = rtb_Subtract2_k;
    rtb_MCF_uaBase = rtb_Subtract_o;
    rtb_Saturation_e = rtb_MCF_ibeta;
  }

  /* End of Chart: '<S140>/Chart' */

  /* MultiPortSwitch: '<S147>/Multiport Switch' */
  switch (rtb_MCF_stN) {
   case 1:
    /* Outport: '<Root>/PP_SWC_MCF_MCF_secVolt' incorporates:
     *  Constant: '<S147>/Constant6'
     */
    (void) Rte_Write_PP_SWC_MCF_MCF_secVolt(2U);
    break;

   case 2:
    /* Outport: '<Root>/PP_SWC_MCF_MCF_secVolt' incorporates:
     *  Constant: '<S147>/Constant7'
     */
    (void) Rte_Write_PP_SWC_MCF_MCF_secVolt(6U);
    break;

   case 3:
    /* Outport: '<Root>/PP_SWC_MCF_MCF_secVolt' incorporates:
     *  Constant: '<S147>/Constant8'
     */
    (void) Rte_Write_PP_SWC_MCF_MCF_secVolt(1U);
    break;

   case 4:
    /* Outport: '<Root>/PP_SWC_MCF_MCF_secVolt' incorporates:
     *  Constant: '<S147>/Constant9'
     */
    (void) Rte_Write_PP_SWC_MCF_MCF_secVolt(4U);
    break;

   case 5:
    /* Outport: '<Root>/PP_SWC_MCF_MCF_secVolt' incorporates:
     *  Constant: '<S147>/Constant10'
     */
    (void) Rte_Write_PP_SWC_MCF_MCF_secVolt(3U);
    break;

   default:
    /* Outport: '<Root>/PP_SWC_MCF_MCF_secVolt' incorporates:
     *  Constant: '<S147>/Constant11'
     */
    (void) Rte_Write_PP_SWC_MCF_MCF_secVolt(5U);
    break;
  }

  /* End of MultiPortSwitch: '<S147>/Multiport Switch' */

  /* Switch: '<S126>/Switch6' incorporates:
   *  Constant: '<S106>/CAL_MCF_FlgUpdateDyc_b'
   *  Product: '<S126>/Divide'
   *  UnitDelay generated from: '<S106>/Unit Delay'
   */
  if (CAL_MCF_FlgUseSetDyc_b) {
    rtb_MCF_uDcalc = SWC_MCF_DW.UnitDelay_1_DSTATE;
  } else {
    rtb_MCF_uDcalc = rtb_MCF_uBCalc / rtb_Subtract_cm;
  }

  /* End of Switch: '<S126>/Switch6' */

  /* Switch: '<S126>/Switch' incorporates:
   *  Constant: '<S126>/CAL_MCF_ratUp_f32'
   *  RelationalOperator: '<S126>/Relational Operator'
   */
  if (rtb_MCF_uDcalc > CAL_MCF_ratUp_f32) {
    rtb_MCF_uDcalc = CAL_MCF_ratUp_f32;
  }

  /* End of Switch: '<S126>/Switch' */

  /* Switch: '<S126>/Switch3' incorporates:
   *  Constant: '<S126>/CAL_MCF_ratLo_f32'
   *  RelationalOperator: '<S126>/Relational Operator3'
   */
  if (rtb_MCF_uDcalc > CAL_MCF_ratLo_f32) {
    rtb_Subtract2_k = rtb_MCF_uDcalc;
  } else {
    rtb_Subtract2_k = CAL_MCF_ratLo_f32;
  }

  /* End of Switch: '<S126>/Switch3' */

  /* Switch: '<S126>/Switch7' incorporates:
   *  Constant: '<S106>/CAL_MCF_FlgUpdateDyc_b'
   *  Product: '<S126>/Divide1'
   *  UnitDelay generated from: '<S106>/Unit Delay'
   */
  if (CAL_MCF_FlgUseSetDyc_b) {
    rtb_MCF_uDcalc = SWC_MCF_DW.UnitDelay_2_DSTATE;
  } else {
    rtb_MCF_uDcalc = rtb_MCF_uaBase / rtb_Subtract_cm;
  }

  /* End of Switch: '<S126>/Switch7' */

  /* Switch: '<S126>/Switch1' incorporates:
   *  Constant: '<S126>/CAL_MCF_ratUp_f32'
   *  RelationalOperator: '<S126>/Relational Operator1'
   */
  if (rtb_MCF_uDcalc > CAL_MCF_ratUp_f32) {
    rtb_MCF_uDcalc = CAL_MCF_ratUp_f32;
  }

  /* End of Switch: '<S126>/Switch1' */

  /* Switch: '<S126>/Switch4' incorporates:
   *  Constant: '<S126>/CAL_MCF_ratLo_f32'
   *  RelationalOperator: '<S126>/Relational Operator4'
   */
  if (rtb_MCF_uDcalc > CAL_MCF_ratLo_f32) {
    rtb_Subtract_o = rtb_MCF_uDcalc;
  } else {
    rtb_Subtract_o = CAL_MCF_ratLo_f32;
  }

  /* End of Switch: '<S126>/Switch4' */

  /* Switch: '<S126>/Switch8' incorporates:
   *  Constant: '<S106>/CAL_MCF_FlgUpdateDyc_b'
   *  Product: '<S126>/Divide2'
   *  UnitDelay generated from: '<S106>/Unit Delay'
   */
  if (CAL_MCF_FlgUseSetDyc_b) {
    rtb_MCF_uDcalc = SWC_MCF_DW.UnitDelay_3_DSTATE;
  } else {
    rtb_MCF_uDcalc = rtb_Saturation_e / rtb_Subtract_cm;
  }

  /* End of Switch: '<S126>/Switch8' */

  /* Switch: '<S126>/Switch2' incorporates:
   *  Constant: '<S126>/CAL_MCF_ratUp_f32'
   *  RelationalOperator: '<S126>/Relational Operator2'
   */
  if (rtb_MCF_uDcalc > CAL_MCF_ratUp_f32) {
    rtb_MCF_uDcalc = CAL_MCF_ratUp_f32;
  }

  /* End of Switch: '<S126>/Switch2' */

  /* MultiPortSwitch: '<S126>/Multiport Switch' incorporates:
   *  Constant: '<S126>/CAL_MCF_stChangePha_u8'
   */
  switch (CAL_MCF_stChangePha_u8) {
   case 1:
    /* Outport: '<Root>/PP_SWC_MCF_MCF_DycU' */
    (void) Rte_Write_PP_SWC_MCF_MCF_DycU(rtb_Subtract2_k);
    GLB_MCF_DycU_f32 = rtb_Subtract2_k;
    /* Outport: '<Root>/PP_SWC_MCF_MCF_DycV' incorporates:
     *  MultiPortSwitch: '<S126>/Multiport Switch1'
     */
    (void) Rte_Write_PP_SWC_MCF_MCF_DycV(rtb_Subtract_o);
    GLB_MCF_DycV_f32 = rtb_Subtract_o;
    /* Switch: '<S126>/Switch5' incorporates:
     *  Constant: '<S126>/CAL_MCF_ratLo_f32'
     *  RelationalOperator: '<S126>/Relational Operator5'
     */
    if (rtb_MCF_uDcalc > CAL_MCF_ratLo_f32) {
      /* Outport: '<Root>/PP_SWC_MCF_MCF_DycW' incorporates:
       *  MultiPortSwitch: '<S126>/Multiport Switch2'
       */
      (void) Rte_Write_PP_SWC_MCF_MCF_DycW(rtb_MCF_uDcalc);
      GLB_MCF_DycW_f32 = rtb_MCF_uDcalc;
    } else {
      /* Outport: '<Root>/PP_SWC_MCF_MCF_DycW' incorporates:
       *  MultiPortSwitch: '<S126>/Multiport Switch2'
       */
      (void) Rte_Write_PP_SWC_MCF_MCF_DycW(CAL_MCF_ratLo_f32);
      GLB_MCF_DycW_f32 = CAL_MCF_ratLo_f32;
    }
    break;

   case 2:
    /* Outport: '<Root>/PP_SWC_MCF_MCF_DycU' */
    (void) Rte_Write_PP_SWC_MCF_MCF_DycU(rtb_Subtract2_k);
    GLB_MCF_DycU_f32 = rtb_Subtract2_k;
    /* Switch: '<S126>/Switch5' incorporates:
     *  Constant: '<S126>/CAL_MCF_ratLo_f32'
     *  RelationalOperator: '<S126>/Relational Operator5'
     */
    if (rtb_MCF_uDcalc > CAL_MCF_ratLo_f32) {
      /* Outport: '<Root>/PP_SWC_MCF_MCF_DycV' incorporates:
       *  MultiPortSwitch: '<S126>/Multiport Switch1'
       */
      (void) Rte_Write_PP_SWC_MCF_MCF_DycV(rtb_MCF_uDcalc);
      GLB_MCF_DycV_f32 = rtb_MCF_uDcalc;
    } else {
      /* Outport: '<Root>/PP_SWC_MCF_MCF_DycV' incorporates:
       *  MultiPortSwitch: '<S126>/Multiport Switch1'
       */
      (void) Rte_Write_PP_SWC_MCF_MCF_DycV(CAL_MCF_ratLo_f32);
      GLB_MCF_DycV_f32 = CAL_MCF_ratLo_f32;
    }

    /* Outport: '<Root>/PP_SWC_MCF_MCF_DycW' incorporates:
     *  MultiPortSwitch: '<S126>/Multiport Switch2'
     */
    (void) Rte_Write_PP_SWC_MCF_MCF_DycW(rtb_Subtract_o);
    GLB_MCF_DycW_f32 = rtb_Subtract_o;	
	
    break;

   case 3:
    /* Outport: '<Root>/PP_SWC_MCF_MCF_DycU' */
    (void) Rte_Write_PP_SWC_MCF_MCF_DycU(rtb_Subtract_o);
    GLB_MCF_DycU_f32 = rtb_Subtract_o;
    /* Outport: '<Root>/PP_SWC_MCF_MCF_DycV' incorporates:
     *  MultiPortSwitch: '<S126>/Multiport Switch1'
     */
    (void) Rte_Write_PP_SWC_MCF_MCF_DycV(rtb_Subtract2_k);
    GLB_MCF_DycV_f32 = rtb_Subtract2_k;
    /* Switch: '<S126>/Switch5' incorporates:
     *  Constant: '<S126>/CAL_MCF_ratLo_f32'
     *  RelationalOperator: '<S126>/Relational Operator5'
     */
    if (rtb_MCF_uDcalc > CAL_MCF_ratLo_f32) {
      /* Outport: '<Root>/PP_SWC_MCF_MCF_DycW' incorporates:
       *  MultiPortSwitch: '<S126>/Multiport Switch2'
       */
      (void) Rte_Write_PP_SWC_MCF_MCF_DycW(rtb_MCF_uDcalc);
      GLB_MCF_DycW_f32 = rtb_MCF_uDcalc;	  
    } else {
      /* Outport: '<Root>/PP_SWC_MCF_MCF_DycW' incorporates:
       *  MultiPortSwitch: '<S126>/Multiport Switch2'
       */
      (void) Rte_Write_PP_SWC_MCF_MCF_DycW(CAL_MCF_ratLo_f32);
      GLB_MCF_DycW_f32 = CAL_MCF_ratLo_f32;
    }
    break;

   case 4:
    /* Outport: '<Root>/PP_SWC_MCF_MCF_DycU' */
    (void) Rte_Write_PP_SWC_MCF_MCF_DycU(rtb_Subtract_o);
    GLB_MCF_DycU_f32 = rtb_Subtract_o;

    /* Switch: '<S126>/Switch5' incorporates:
     *  Constant: '<S126>/CAL_MCF_ratLo_f32'
     *  RelationalOperator: '<S126>/Relational Operator5'
     */
    if (rtb_MCF_uDcalc > CAL_MCF_ratLo_f32) {
      /* Outport: '<Root>/PP_SWC_MCF_MCF_DycV' incorporates:
       *  MultiPortSwitch: '<S126>/Multiport Switch1'
       */
      (void) Rte_Write_PP_SWC_MCF_MCF_DycV(rtb_MCF_uDcalc);
      GLB_MCF_DycV_f32 = rtb_MCF_uDcalc;
    } else {
      /* Outport: '<Root>/PP_SWC_MCF_MCF_DycV' incorporates:
       *  MultiPortSwitch: '<S126>/Multiport Switch1'
       */
      (void) Rte_Write_PP_SWC_MCF_MCF_DycV(CAL_MCF_ratLo_f32);
	  GLB_MCF_DycV_f32 = CAL_MCF_ratLo_f32;
    }

    /* Outport: '<Root>/PP_SWC_MCF_MCF_DycW' incorporates:
     *  MultiPortSwitch: '<S126>/Multiport Switch2'
     */
    (void) Rte_Write_PP_SWC_MCF_MCF_DycW(rtb_Subtract2_k);
	GLB_MCF_DycW_f32 = rtb_Subtract2_k;
    break;

   case 5:
    /* Switch: '<S126>/Switch5' incorporates:
     *  Constant: '<S126>/CAL_MCF_ratLo_f32'
     *  RelationalOperator: '<S126>/Relational Operator5'
     */
    if (rtb_MCF_uDcalc > CAL_MCF_ratLo_f32) {
      /* Outport: '<Root>/PP_SWC_MCF_MCF_DycU' */
      (void) Rte_Write_PP_SWC_MCF_MCF_DycU(rtb_MCF_uDcalc);
	  GLB_MCF_DycU_f32 = rtb_MCF_uDcalc;
    } else {
      /* Outport: '<Root>/PP_SWC_MCF_MCF_DycU' */
      (void) Rte_Write_PP_SWC_MCF_MCF_DycU(CAL_MCF_ratLo_f32);
	  GLB_MCF_DycU_f32 = CAL_MCF_ratLo_f32;
    }

    /* Outport: '<Root>/PP_SWC_MCF_MCF_DycV' incorporates:
     *  MultiPortSwitch: '<S126>/Multiport Switch1'
     */
    (void) Rte_Write_PP_SWC_MCF_MCF_DycV(rtb_Subtract2_k);
	GLB_MCF_DycV_f32 = rtb_Subtract2_k;

    /* Outport: '<Root>/PP_SWC_MCF_MCF_DycW' incorporates:
     *  MultiPortSwitch: '<S126>/Multiport Switch2'
     */
    (void) Rte_Write_PP_SWC_MCF_MCF_DycW(rtb_Subtract_o);
	GLB_MCF_DycW_f32 = rtb_Subtract_o;
    break;

   default:
    /* Switch: '<S126>/Switch5' incorporates:
     *  Constant: '<S126>/CAL_MCF_ratLo_f32'
     *  RelationalOperator: '<S126>/Relational Operator5'
     */
    if (rtb_MCF_uDcalc > CAL_MCF_ratLo_f32) {
      /* Outport: '<Root>/PP_SWC_MCF_MCF_DycU' */
      (void) Rte_Write_PP_SWC_MCF_MCF_DycU(rtb_MCF_uDcalc);
	  GLB_MCF_DycU_f32 = rtb_MCF_uDcalc;
    } else {
      /* Outport: '<Root>/PP_SWC_MCF_MCF_DycU' */
      (void) Rte_Write_PP_SWC_MCF_MCF_DycU(CAL_MCF_ratLo_f32);
	  GLB_MCF_DycU_f32 = CAL_MCF_ratLo_f32;
    }

    /* Outport: '<Root>/PP_SWC_MCF_MCF_DycV' incorporates:
     *  MultiPortSwitch: '<S126>/Multiport Switch1'
     */
    (void) Rte_Write_PP_SWC_MCF_MCF_DycV(rtb_Subtract_o);
	GLB_MCF_DycV_f32 = rtb_Subtract_o;

    /* Outport: '<Root>/PP_SWC_MCF_MCF_DycW' incorporates:
     *  MultiPortSwitch: '<S126>/Multiport Switch2'
     */
    (void) Rte_Write_PP_SWC_MCF_MCF_DycW(rtb_Subtract2_k);
	GLB_MCF_DycW_f32 = rtb_Subtract2_k;
    break;
  }

  /* End of MultiPortSwitch: '<S126>/Multiport Switch' */

  /* Outport: '<Root>/PP_SWC_MCF_MCF_cofFrqPwm' incorporates:
   *  Constant: '<S119>/frqBase10K'
   *  Product: '<S119>/Divide3'
   */
  (void) Rte_Write_PP_SWC_MCF_MCF_cofFrqPwm(rtb_MCF_frqPwmCalc_j / 10000.0F);

  /* Update for UnitDelay: '<S32>/Delay2' */
  SWC_MCF_DW.Delay2_DSTATE = tmpRead_2;

  /* Update for UnitDelay: '<S34>/Unit Delay' */
  SWC_MCF_DW.UnitDelay_DSTATE_p = VAR_MCF_flgMotHeat_b;

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_MCF_100us' */

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_MCF_100us' incorporates:
   *  SubSystem: '<Root>/RE_SWC_MCF_100us_sys'
   */
  /* Outport: '<Root>/PP_SWC_MCF_MCF_udDes' incorporates:
   *  Sum: '<S25>/Add4'
   */
  (void) Rte_Write_PP_SWC_MCF_MCF_udDes(VAR_MCF_udDes_f32);

  /* Outport: '<Root>/PP_SWC_MCF_MCF_uqDes' incorporates:
   *  Sum: '<S25>/Add3'
   */
  (void) Rte_Write_PP_SWC_MCF_MCF_uqDes(VAR_MCF_uqDes_f32);

  /* Outport: '<Root>/PP_SWC_MCF_MCF_idDes' incorporates:
   *  Sum: '<S27>/Add'
   */
  (void) Rte_Write_PP_SWC_MCF_MCF_idDes(VAR_MCF_idDes_f32);

  /* Outport: '<Root>/PP_SWC_MCF_MCF_iqDes' incorporates:
   *  Sum: '<S27>/Add1'
   */
  (void) Rte_Write_PP_SWC_MCF_MCF_iqDes(VAR_MCF_iqDes_f32);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_MCF_100us' */

  /* Outport: '<Root>/PP_SWC_MCF_MCF_frqPwm' */
  (void) Rte_Write_PP_SWC_MCF_MCF_frqPwm(rtb_MCF_frqPwmCalc_j);

  /* Outport: '<Root>/PP_SWC_MCF_MCF_dtPwm' */
  (void) Rte_Write_PP_SWC_MCF_MCF_dtPwm(rtb_Subtract_cm);

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_MCF_100us' incorporates:
   *  SubSystem: '<Root>/RE_SWC_MCF_100us_sys'
   */
  /* Outport: '<Root>/PP_SWC_MCF_MCF_Is' incorporates:
   *  Sum: '<S11>/Add1'
   */
  (void) Rte_Write_PP_SWC_MCF_MCF_Is(VAR_MCF_Is_f32);

  /* Outport: '<Root>/PP_SWC_MCF_MCF_isd' incorporates:
   *  Sum: '<S14>/Add2'
   */
  (void) Rte_Write_PP_SWC_MCF_MCF_isd(VAR_MCF_idAct_f32);

  /* Outport: '<Root>/PP_SWC_MCF_MCF_isq' incorporates:
   *  Sum: '<S14>/Add3'
   */
  (void) Rte_Write_PP_SWC_MCF_MCF_isq(VAR_MCF_iqAct_f32);

  /* Outport: '<Root>/PP_SWC_MCF_MCF_uDcLnk' incorporates:
   *  Sum: '<S13>/Add'
   */
  (void) Rte_Write_PP_SWC_MCF_MCF_uDcLnk(VAR_MCF_uDcLnk_f32);

  /* Outport: '<Root>/PP_SWC_MCF_MCF_iU' incorporates:
   *  Sum: '<S13>/Add1'
   */
  (void) Rte_Write_PP_SWC_MCF_MCF_iU(VAR_MCF_iU_f32);

  /* Outport: '<Root>/PP_SWC_MCF_MCF_iV' incorporates:
   *  Sum: '<S13>/Add3'
   */
  (void) Rte_Write_PP_SWC_MCF_MCF_iV(VAR_MCF_iV_f32);

  /* Outport: '<Root>/PP_SWC_MCF_MCF_iW' incorporates:
   *  Sum: '<S13>/Add2'
   */
  (void) Rte_Write_PP_SWC_MCF_MCF_iW(VAR_MCF_iW_f32);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_MCF_100us' */

  /* Outport: '<Root>/PP_SWC_MCF_MCF_VoltModuRate' */
  (void) Rte_Write_PP_SWC_MCF_MCF_VoltModuRate(SWC_MCF_B.Divide2);
}

/* Model initialize function */
void SWC_MCF_Init(void)
{
  /* SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_MCF_100us' incorporates:
   *  SubSystem: '<Root>/RE_SWC_MCF_100us_sys'
   */
  /* SystemInitialize for Enabled SubSystem: '<S107>/Inductancetestfunction' */
  /* Start for Constant: '<S112>/CAL_MCF_uQDesEOL_f32' */
  SWC_MCF_B.CAL_MCF_uQDesEOL_f32_h = CAL_MCF_uQDesEOL_f32;

  /* End of SystemInitialize for SubSystem: '<S107>/Inductancetestfunction' */
  /* End of SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_MCF_100us' */

  /* SystemInitialize for Outport: '<Root>/PP_SWC_MCF_MCF_VoltModuRate' */
  (void) Rte_Write_PP_SWC_MCF_MCF_VoltModuRate(SWC_MCF_B.Divide2);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
