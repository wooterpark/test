#ifndef RTW_HEADER_SWC_RCF_h_
#define RTW_HEADER_SWC_RCF_h_
#include <math.h>
#ifndef SWC_RCF_COMMON_INCLUDES_
# define SWC_RCF_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_SWC_RCF.h"
#endif

#include "SWC_RCF_types.h"

#define CAL_RCF_CircAge_f32            360.0F
#define CAL_RCF_MotorPole_u8           4U
#define CAL_RCF_Sixty_f32              60.0F
#define RCF_DrvOffsetCal_E             19U
#define RCF_Drv_OffsetAcc_E            5U
#define RCF_Drv_OffsetFw_E             6U
#define RCF_EstAlOfsFail_E             2U
#define RCF_EstAlOfsFinish_E           1U
#define RCF_EstAlOfsNoFinish_E         0U
#define RCF_EstAlOfsPreFinish_E        3U
#define RCF_FishdSucdClbBwd_E          1U
#define RCF_FishdSucdClbFwd_E          1U
#define RCF_InProgress_E               1U
#define RCF_Inactive_E                 0U
#define RCF_NoFishdSucdClbBwd_E        0U
#define RCF_NoFishdSucdClbFwd_E        0U
#define RCF_OfsClb_Acceleration_E      2U
#define RCF_OfsClb_AlRtrOfsPlausFail_E 6U
#define RCF_OfsClb_EstAlOfsFailed_E    7U
#define RCF_OfsClb_FrewhlBwd_E         1U
#define RCF_OfsClb_FrewhlFwd_E         1U
#define RCF_OfsClb_FrewhlStp_E         4U
#define RCF_OfsClb_FrwhlNotPossibleFail_E 3U
#define RCF_OfsClb_NotTest_E           0U
#define RCF_OfsClb_OverTimeAccFail_E   2U
#define RCF_OfsClb_OverTimeFrwhlBwdFail_E 5U
#define RCF_OfsClb_OverTimeFrwhlFwdFail_E 4U
#define RCF_OfsClb_Standby_E           0U
#define RCF_OfsClb_SuccessfulTested_E  1U
#define RCF_OfsClbfishedFaild_E        3U
#define RCF_OfsClbfishedSucd_E         2U
#define RCF_goalOfsClbReq_E            5U

typedef struct {
  float32 UnitDelay_DSTATE;
} DW_IfActionSubsystem8_SWC_RCF_T;

typedef struct tag_B_SWC_RCF_T {
  float32 TmpSignalConversionAtRP_SWC_Rdc;
  float32 TmpSignalConversionAtRP_SWC_R_k;
  float32 Add;
  float32 Add1;
  float32 Switch;
  float32 RCF_agRtrOffsEstimd;
  uint8 Add2;
  uint8 Add3;
  uint8 Add4;
  boolean TmpSignalConversionAtRP_SWC_HvM;
  boolean LogicalOperator;
} B_SWC_RCF_T;

typedef struct tag_DW_SWC_RCF_T {
  float64 UnitDelay_DSTATE;
  float32 Delay_DSTATE[100];
  float32 UnitDelay4_DSTATE;
  float32 UnitDelay1_DSTATE;
  float32 UnitDelay3_DSTATE;
  float32 Delay_DSTATE_a[100];
  float32 UnitDelay4_DSTATE_l;
  float32 UnitDelay1_DSTATE_f;
  float32 UnitDelay3_DSTATE_k;
  float32 OfsFlt3600Fwd;
  float32 OfsFlt3800Fwd;
  float32 OfsFlt4000Fwd;
  float32 OfsFlt4200Fwd;
  float32 OfsFlt4400Fwd;
  float32 OfsFlt4600Fwd;
  float32 OfsFlt4800Fwd;
  float32 OfsFlt3600Bwd;
  float32 OfsFlt3800Bwd;
  float32 OfsFlt4000Bwd;
  float32 OfsFlt4200Bwd;
  float32 OfsFlt4400Bwd;
  float32 OfsFlt4600Bwd;
  float32 OfsFlt4800Bwd;
  float32 Rsv_cnt3800Avg;
  float32 Rsv_cnt4000Avg;
  float32 Rsv_cnt4200Avg;
  float32 Rsv_cnt4400Avg;
  float32 Rsv_cnt4600Avg;
  float32 Rsv_cnt4800Avg;
  float32 Rsv_cnt5000Avg;
  uint32 RCF_cntEstAlOfsConst;
  uint32 RCF_cntEstAlOfsConst1;
  uint32 RCF_noOfValuesBwd;
  uint32 RCF_noOfValuesFwd;
  uint16 RCF_cntDurAccState;
  uint16 RCF_cntDurFrewhlClbBwdState;
  uint16 RCF_cntDurFrewhlClbFwdState;
  uint8 UnitDelay_DSTATE_b;
  uint8 UnitDelay_DSTATE_m;
  uint8 UnitDelay_DSTATE_g2;
  boolean UnitDelay5_DSTATE;
  boolean UnitDelay2_DSTATE;
  uint8 is_active_c1_SWC_RCF;
  uint8 is_c1_SWC_RCF;
  uint8 RCF_flgOfsClbFrwhl_Fwd;
  uint8 is_active_c3_SWC_RCF;
  uint8 is_c3_SWC_RCF;
  uint8 is_active_c2_SWC_RCF;
  uint8 is_c2_SWC_RCF;
  DW_IfActionSubsystem8_SWC_RCF_T IfActionSubsystem12;
  DW_IfActionSubsystem8_SWC_RCF_T IfActionSubsystem11;
  DW_IfActionSubsystem8_SWC_RCF_T IfActionSubsystem10;
  DW_IfActionSubsystem8_SWC_RCF_T IfActionSubsystem9;
  DW_IfActionSubsystem8_SWC_RCF_T IfActionSubsystem7;
  DW_IfActionSubsystem8_SWC_RCF_T IfActionSubsystem6_d;
  DW_IfActionSubsystem8_SWC_RCF_T IfActionSubsystem13;
  DW_IfActionSubsystem8_SWC_RCF_T IfActionSubsystem6;
  DW_IfActionSubsystem8_SWC_RCF_T IfActionSubsystem5;
  DW_IfActionSubsystem8_SWC_RCF_T IfActionSubsystem4;
  DW_IfActionSubsystem8_SWC_RCF_T IfActionSubsystem3;
  DW_IfActionSubsystem8_SWC_RCF_T IfActionSubsystem2;
  DW_IfActionSubsystem8_SWC_RCF_T IfActionSubsystem1;
  DW_IfActionSubsystem8_SWC_RCF_T IfActionSubsystem8;
} DW_SWC_RCF_T;

extern B_SWC_RCF_T SWC_RCF_B;
extern DW_SWC_RCF_T SWC_RCF_DW;
extern float32 VAR_RCF_TrqEmDesOfsClb_f32;
extern float32 VAR_RCF_cTrqSlpOfsClb_f32;
extern float32 VAR_RCF_agRtrOffsEstimd_f32;
extern float32 VAR_RCF_UsAlfaScalSet_f32;
extern float32 VAR_RCF_UsBetaScalSet_f32;
extern float32 VAR_RCF_AutoClbOffset_f32;
extern float32 VAR_RCF_OfsClbAngBwd_f32;
extern float32 VAR_RCF_OfsFlt4800Bwd_f32;
extern float32 VAR_RCF_OfsFlt4600Bwd_f32;
extern float32 VAR_RCF_OfsFlt4400Bwd_f32;
extern float32 VAR_RCF_OfsFlt4200Bwd_f32;
extern float32 VAR_RCF_OfsFlt4000Bwd_f32;
extern float32 VAR_RCF_OfsFlt3800Bwd_f32;
extern float32 VAR_RCF_OfsFlt3600Bwd_f32;
extern float32 VAR_RCF_OfsClbAngFwd_f32;
extern float32 VAR_RCF_OfsFlt4800Fwd_f32;
extern float32 VAR_RCF_OfsFlt4600Fwd_f32;
extern float32 VAR_RCF_OfsFlt4400Fwd_f32;
extern float32 VAR_RCF_OfsFlt4200Fwd_f32;
extern float32 VAR_RCF_OfsFlt4000Fwd_f32;
extern float32 VAR_RCF_OfsFlt3800Fwd_f32;
extern float32 VAR_RCF_OfsFlt3600Fwd_f32;
extern uint8 VAR_RCF_stAgRtrOfsCal_u8;
extern uint8 VAR_RCF_stDiagOfsClb_u8;
extern uint8 VAR_RCF_stEstAlRtrOfs_u8;
extern uint8 VAR_RCF_stOfsFrwhlFwd_u8;
extern uint8 VAR_RCF_stOfsFrwhlBwd_u8;
extern uint8 VAR_RCF_stOfsClbFrwhl_u8;
extern boolean VAR_RCF_flgDefaultToWait_b;
extern boolean VAR_RCF_flgDefaultToClbFreFwd_b;
extern boolean VAR_RCF_flgDefaultToFrewhlBwd_b;
extern boolean VAR_RCF_flgWaitToAcc_b;
extern boolean VAR_RCF_flgAccToClbFreFwd_b;
extern boolean VAR_RCF_flgClbFreFwdToAcc_b;
extern boolean VAR_RCF_flgAccToClbFreBwd_b;
extern boolean VAR_RCF_flgBwClbSucdToAcc_b;
extern boolean VAR_RCF_flgSucdToDefault_b;
extern boolean VAR_RCF_flgFwdorBwdToDefault_b;
extern boolean VAR_RCF_flgAccToDefault_b;
extern boolean VAR_RCF_flgFailToDefault_b;
extern boolean VAR_RCF_flgWaitToFail_b;
extern boolean VAR_RCF_flgPsiToFail_b;
extern boolean VAR_RCF_flgClbToFail_b;
extern boolean VAR_RCF_flgAccToSucd_b;
extern boolean VAR_RCF_flgEnblEstAlRtrOfs_b;
extern boolean VAR_RCF_flgEnblOfsClbFrwhlFwd_b;
extern boolean VAR_RCF_flgEnblOfsClbFrwhlBwd_b;
extern boolean VAR_RCF_flgEnblOfsClbFrwhl_b;
extern boolean VAR_RCF_flgFailorFnhToDefault_b;
extern boolean VAR_RCF_flgstDefTostEst_b;
extern boolean VAR_RCF_flgstEstTostDef_b;
extern boolean VAR_RCF_flgstEstToFail_b;
extern boolean VAR_RCF_flgstEstToWait_b;
extern boolean VAR_RCF_flgInactToFwdClb_b;
extern boolean VAR_RCF_flgClbToInact_b;
extern boolean VAR_RCF_flgClbReset_b;
extern boolean VAR_RCF_flgFwdClbToWait_b;
extern boolean VAR_RCF_flgWaitToBwdClb_b;
extern boolean VAR_RCF_flgBwdClbToCalc_b;
extern boolean VAR_RCF_flgInactToBwdClb_b;
extern boolean VAR_RCF_flgUseUsSet_b;
extern boolean VAR_RCF_flg360Edge_b;

#pragma section ".rodata.Calib_32"

extern const volatile float32 CAL_RCF_360EdgeRag_f32;
extern const volatile float32 CAL_RCF_AlRtrOfsDvtMax_f32;
extern const volatile boolean CAL_RCF_EstToDefault_b;
extern const volatile float32 CAL_RCF_OffsetAngFiltCoef_f32;
extern const volatile boolean CAL_RCF_SuccdToDefault_b;
extern const volatile float32 CAL_RCF_TrqDesAcc_f32;
extern const volatile float32 CAL_RCF_UsAlfaScalSet_f32;
extern const volatile float32 CAL_RCF_UsBetaScalSet_f32;
extern const volatile uint8 CAL_RCF_WithoutStatorCurrent_u8;
extern const volatile float32 CAL_RCF_agReferenceBwd_f32;
extern const volatile float32 CAL_RCF_agReferenceFwd_f32;
extern const volatile float32 CAL_RCF_cTrqSlopAcc_f32;
extern const volatile uint16 CAL_RCF_cntMovAveFilBwd_u16;
extern const volatile uint16 CAL_RCF_cntMovAveFilFwd_u16;
extern const volatile uint32 CAL_RCF_cntOfValBwd_u32;
extern const volatile uint32 CAL_RCF_cntOfValFwd_u32;
extern const volatile boolean CAL_RCF_flgEnOfsClb_b;
extern const volatile boolean CAL_RCF_flgReAutoClbSuc_b;
extern const volatile boolean CAL_RCF_flgUseClbSucNvm_b;
extern const volatile float32 CAL_RCF_nAlRtrDesAcc_f32;
extern const volatile float32 CAL_RCF_nCalcSec1_f32;
extern const volatile float32 CAL_RCF_nCalcSec2_f32;
extern const volatile float32 CAL_RCF_nCalcSec3_f32;
extern const volatile float32 CAL_RCF_nCalcSec4_f32;
extern const volatile float32 CAL_RCF_nCalcSec5_f32;
extern const volatile float32 CAL_RCF_nCalcSec6_f32;
extern const volatile float32 CAL_RCF_nCalcSec7_f32;
extern const volatile float32 CAL_RCF_nCalcSec8_f32;
extern const volatile float32 CAL_RCF_nEstAlOfsStop_f32;
extern const volatile float32 CAL_RCF_nExtClbFrewhlBwd_f32;
extern const volatile float32 CAL_RCF_nExtClbFrewhlFwd_f32;
extern const volatile float32 CAL_RCF_nLimitSucToDef_f32;
extern const volatile float32 CAL_RCF_nMaxStartAcc_f32;
extern const volatile float32 CAL_RCF_nMinSkipAcc_f32;
extern const volatile float32 CAL_RCF_nMinSuccessStp_f32;
extern const volatile float32 CAL_RCF_nOfValBwdStp_f32;
extern const volatile float32 CAL_RCF_nOfValFwdStp_f32;
extern const volatile float32 CAL_RCF_nOfsClbMaxBwd_f32;
extern const volatile float32 CAL_RCF_nOfsClbMaxFwd_f32;
extern const volatile float32 CAL_RCF_nOfsClbMinBwd_f32;
extern const volatile float32 CAL_RCF_nOfsClbMinFwd_f32;
extern const volatile uint32 CAL_RCF_tHiEstAlOfs_u32;
extern const volatile uint16 CAL_RCF_tMaxAcc_u16;
extern const volatile uint32 CAL_RCF_tMaxEstAlOfs1_u32;
extern const volatile uint32 CAL_RCF_tMaxEstAlOfs_u32;
extern const volatile uint16 CAL_RCF_tMaxFwlBwd_u16;
extern const volatile uint16 CAL_RCF_tMaxFwlFwd_u16;
extern const volatile uint32 CAL_RCF_tUAlfaSet_u32;
extern const volatile uint32 CAL_RCF_tUbetaSet_u32;

#pragma section

#endif

