#include "SWC_RCF.h"
#include "SWC_RCF_private.h"

#define SWC_RCF_IN_CollectValuesBwd    ((uint8)1U)
#define SWC_RCF_IN_CollectValuesFwd    ((uint8)2U)
#define SWC_RCF_IN_EvaluateResults     ((uint8)3U)
#define SWC_RCF_IN_InactiveState       ((uint8)4U)
#define SWC_RCF_IN_WaitState           ((uint8)5U)

#define SWC_RCF_IN_DefaultState        ((uint8)1U)
#define SWC_RCF_IN_EstAlRtrOfsState    ((uint8)2U)
#define SWC_RCF_IN_FailState           ((uint8)3U)
#define SWC_RCF_IN_FinishState         ((uint8)4U)
#define SWC_RCF_IN_wait                ((uint8)5U)

#define SWC_RCF_IN_Acceleration        ((uint8)1U)
#define SWC_RCF_IN_AlRtrOfsClbFrewhlBW ((uint8)2U)
#define SWC_RCF_IN_AlRtrOfsClbFrewhlFW ((uint8)3U)
#define SWC_RCF_IN_DefaultState_p      ((uint8)4U)
#define SWC_RCF_IN_FailState_g         ((uint8)5U)
#define SWC_RCF_IN_SucceedState        ((uint8)6U)
#define SWC_RCF_IN_Wait                ((uint8)7U)

float32 VAR_RCF_TrqEmDesOfsClb_f32;
float32 VAR_RCF_cTrqSlpOfsClb_f32;
float32 VAR_RCF_agRtrOffsEstimd_f32;
float32 VAR_RCF_UsAlfaScalSet_f32;
float32 VAR_RCF_UsBetaScalSet_f32;
float32 VAR_RCF_AutoClbOffset_f32;
float32 VAR_RCF_OfsClbAngBwd_f32;
float32 VAR_RCF_OfsFlt4800Bwd_f32;
float32 VAR_RCF_OfsFlt4600Bwd_f32;
float32 VAR_RCF_OfsFlt4400Bwd_f32;
float32 VAR_RCF_OfsFlt4200Bwd_f32;
float32 VAR_RCF_OfsFlt4000Bwd_f32;
float32 VAR_RCF_OfsFlt3800Bwd_f32;
float32 VAR_RCF_OfsFlt3600Bwd_f32;
float32 VAR_RCF_OfsClbAngFwd_f32;
float32 VAR_RCF_OfsFlt4800Fwd_f32;
float32 VAR_RCF_OfsFlt4600Fwd_f32;
float32 VAR_RCF_OfsFlt4400Fwd_f32;
float32 VAR_RCF_OfsFlt4200Fwd_f32;
float32 VAR_RCF_OfsFlt4000Fwd_f32;
float32 VAR_RCF_OfsFlt3800Fwd_f32;
float32 VAR_RCF_OfsFlt3600Fwd_f32;
uint8 VAR_RCF_stAgRtrOfsCal_u8;
uint8 VAR_RCF_stDiagOfsClb_u8;
uint8 VAR_RCF_stEstAlRtrOfs_u8;
uint8 VAR_RCF_stOfsFrwhlFwd_u8;
uint8 VAR_RCF_stOfsFrwhlBwd_u8;
uint8 VAR_RCF_stOfsClbFrwhl_u8;
boolean VAR_RCF_flgDefaultToWait_b;
boolean VAR_RCF_flgDefaultToClbFreFwd_b;
boolean VAR_RCF_flgDefaultToFrewhlBwd_b;
boolean VAR_RCF_flgWaitToAcc_b;
boolean VAR_RCF_flgAccToClbFreFwd_b;
boolean VAR_RCF_flgClbFreFwdToAcc_b;
boolean VAR_RCF_flgAccToClbFreBwd_b;
boolean VAR_RCF_flgBwClbSucdToAcc_b;
boolean VAR_RCF_flgSucdToDefault_b;
boolean VAR_RCF_flgFwdorBwdToDefault_b;
boolean VAR_RCF_flgAccToDefault_b;
boolean VAR_RCF_flgFailToDefault_b;
boolean VAR_RCF_flgWaitToFail_b;
boolean VAR_RCF_flgPsiToFail_b;
boolean VAR_RCF_flgClbToFail_b;
boolean VAR_RCF_flgAccToSucd_b;
boolean VAR_RCF_flgEnblEstAlRtrOfs_b;
boolean VAR_RCF_flgEnblOfsClbFrwhlFwd_b;
boolean VAR_RCF_flgEnblOfsClbFrwhlBwd_b;
boolean VAR_RCF_flgEnblOfsClbFrwhl_b;
boolean VAR_RCF_flgFailorFnhToDefault_b;
boolean VAR_RCF_flgstDefTostEst_b;
boolean VAR_RCF_flgstEstTostDef_b;
boolean VAR_RCF_flgstEstToFail_b;
boolean VAR_RCF_flgstEstToWait_b;
boolean VAR_RCF_flgInactToFwdClb_b;
boolean VAR_RCF_flgClbToInact_b;
boolean VAR_RCF_flgClbReset_b;
boolean VAR_RCF_flgFwdClbToWait_b;
boolean VAR_RCF_flgWaitToBwdClb_b;
boolean VAR_RCF_flgBwdClbToCalc_b;
boolean VAR_RCF_flgInactToBwdClb_b;
boolean VAR_RCF_flgUseUsSet_b;
boolean VAR_RCF_flg360Edge_b;

#pragma section ".rodata.Calib_32"

const volatile float32 CAL_RCF_360EdgeRag_f32 = 35.0F;
const volatile float32 CAL_RCF_AlRtrOfsDvtMax_f32 = 10.0F;
const volatile boolean CAL_RCF_EstToDefault_b = 0;
const volatile float32 CAL_RCF_OffsetAngFiltCoef_f32 = 0.01F;
const volatile boolean CAL_RCF_SuccdToDefault_b = 1;
const volatile float32 CAL_RCF_TrqDesAcc_f32 = 2.5F;
const volatile float32 CAL_RCF_UsAlfaScalSet_f32 = 6.0F;
const volatile float32 CAL_RCF_UsBetaScalSet_f32 = 6.0F;
const volatile uint8 CAL_RCF_WithoutStatorCurrent_u8 = 0U;
const volatile float32 CAL_RCF_agReferenceBwd_f32 = 150.0F;
const volatile float32 CAL_RCF_agReferenceFwd_f32 = 150.0F;
const volatile float32 CAL_RCF_cTrqSlopAcc_f32 = 1.0F;
const volatile uint16 CAL_RCF_cntMovAveFilBwd_u16 = 100U;
const volatile uint16 CAL_RCF_cntMovAveFilFwd_u16 = 100U;
const volatile uint32 CAL_RCF_cntOfValBwd_u32 = 150000U;
const volatile uint32 CAL_RCF_cntOfValFwd_u32 = 150000U;
const volatile boolean CAL_RCF_flgEnOfsClb_b = 0;
const volatile boolean CAL_RCF_flgReAutoClbSuc_b = 0;
const volatile boolean CAL_RCF_flgUseClbSucNvm_b = 0;
const volatile float32 CAL_RCF_nAlRtrDesAcc_f32 = 5000.0F;
const volatile float32 CAL_RCF_nCalcSec1_f32 = 3400.0F;
const volatile float32 CAL_RCF_nCalcSec2_f32 = 3600.0F;
const volatile float32 CAL_RCF_nCalcSec3_f32 = 3800.0F;
const volatile float32 CAL_RCF_nCalcSec4_f32 = 4000.0F;
const volatile float32 CAL_RCF_nCalcSec5_f32 = 4200.0F;
const volatile float32 CAL_RCF_nCalcSec6_f32 = 4400.0F;
const volatile float32 CAL_RCF_nCalcSec7_f32 = 4600.0F;
const volatile float32 CAL_RCF_nCalcSec8_f32 = 4800.0F;
const volatile float32 CAL_RCF_nEstAlOfsStop_f32 = 10.0F;
const volatile float32 CAL_RCF_nExtClbFrewhlBwd_f32 = -3000.0F;
const volatile float32 CAL_RCF_nExtClbFrewhlFwd_f32 = 3000.0F;
const volatile float32 CAL_RCF_nLimitSucToDef_f32 = 10.0F;
const volatile float32 CAL_RCF_nMaxStartAcc_f32 = 2000.0F;
const volatile float32 CAL_RCF_nMinSkipAcc_f32 = 2000.0F;
const volatile float32 CAL_RCF_nMinSuccessStp_f32 = -300.0F;
const volatile float32 CAL_RCF_nOfValBwdStp_f32 = -3200.0F;
const volatile float32 CAL_RCF_nOfValFwdStp_f32 = 3200.0F;
const volatile float32 CAL_RCF_nOfsClbMaxBwd_f32 = -2000.0F;
const volatile float32 CAL_RCF_nOfsClbMaxFwd_f32 = 5000.0F;
const volatile float32 CAL_RCF_nOfsClbMinBwd_f32 = -5000.0F;
const volatile float32 CAL_RCF_nOfsClbMinFwd_f32 = 2000.0F;
const volatile uint32 CAL_RCF_tHiEstAlOfs_u32 = 100000U;
const volatile uint16 CAL_RCF_tMaxAcc_u16 = 1800U;
const volatile uint32 CAL_RCF_tMaxEstAlOfs1_u32 = 10000U;
const volatile uint32 CAL_RCF_tMaxEstAlOfs_u32 = 50000U;
const volatile uint16 CAL_RCF_tMaxFwlBwd_u16 = 1700U;
const volatile uint16 CAL_RCF_tMaxFwlFwd_u16 = 1700U;
const volatile uint32 CAL_RCF_tUAlfaSet_u32 = 50000U;
const volatile uint32 CAL_RCF_tUbetaSet_u32 = 20000U;

#pragma section

B_SWC_RCF_T SWC_RCF_B;
DW_SWC_RCF_T SWC_RCF_DW;
static float32 SWC_RCF_AloffsetCalc(float32 RCF_stOfsFrwhlFwdin, float32
  RCF_stOfsFrwhlBwdin, float32 OfsFlt3600Fwd, float32 OfsFlt3800Fwd, float32
  OfsFlt4000Fwd, float32 OfsFlt4200Fwd, float32 OfsFlt4400Fwd, float32
  OfsFlt4600Fwd, float32 OfsFlt4800Fwd, float32 OfsFlt3600Bwd, float32
  OfsFlt3800Bwd, float32 OfsFlt4000Bwd, float32 OfsFlt4200Bwd, float32
  OfsFlt4400Bwd, float32 OfsFlt4600Bwd, float32 OfsFlt4800Bwd);
static void SWC_RC_enter_internal_FailState(void);
static void SWC_enter_internal_DefaultState(void);
void SWC_RCF_IfActionSubsystem8(float32 rtu_In, float32 *rty_Out,
  DW_IfActionSubsystem8_SWC_RCF_T *localDW)
{
  *rty_Out = (1.0F - CAL_RCF_OffsetAngFiltCoef_f32) * localDW->UnitDelay_DSTATE
    + rtu_In * CAL_RCF_OffsetAngFiltCoef_f32;
  localDW->UnitDelay_DSTATE = *rty_Out;
}

static float32 SWC_RCF_AloffsetCalc(float32 RCF_stOfsFrwhlFwdin, float32
  RCF_stOfsFrwhlBwdin, float32 OfsFlt3600Fwd, float32 OfsFlt3800Fwd, float32
  OfsFlt4000Fwd, float32 OfsFlt4200Fwd, float32 OfsFlt4400Fwd, float32
  OfsFlt4600Fwd, float32 OfsFlt4800Fwd, float32 OfsFlt3600Bwd, float32
  OfsFlt3800Bwd, float32 OfsFlt4000Bwd, float32 OfsFlt4200Bwd, float32
  OfsFlt4400Bwd, float32 OfsFlt4600Bwd, float32 OfsFlt4800Bwd)
{
  float32 Rsv_cntMax;
  float32 Rsv_cntMin;
  if ((RCF_stOfsFrwhlFwdin == ((uint8)RCF_FishdSucdClbFwd_E)) &&
      (RCF_stOfsFrwhlBwdin == ((uint8)RCF_FishdSucdClbBwd_E))) {
    SWC_RCF_DW.Rsv_cnt3800Avg = (OfsFlt3600Fwd + OfsFlt3600Bwd) / 2.0F;
    SWC_RCF_DW.Rsv_cnt4000Avg = (OfsFlt3800Fwd + OfsFlt3800Bwd) / 2.0F;
    SWC_RCF_DW.Rsv_cnt4200Avg = (OfsFlt4000Fwd + OfsFlt4000Bwd) / 2.0F;
    SWC_RCF_DW.Rsv_cnt4400Avg = (OfsFlt4200Fwd + OfsFlt4200Bwd) / 2.0F;
    SWC_RCF_DW.Rsv_cnt4600Avg = (OfsFlt4400Fwd + OfsFlt4400Bwd) / 2.0F;
    SWC_RCF_DW.Rsv_cnt4800Avg = (OfsFlt4600Fwd + OfsFlt4600Bwd) / 2.0F;
    SWC_RCF_DW.Rsv_cnt5000Avg = (OfsFlt4800Fwd + OfsFlt4800Bwd) / 2.0F;
  }

  Rsv_cntMax = SWC_RCF_DW.Rsv_cnt3800Avg;
  Rsv_cntMin = SWC_RCF_DW.Rsv_cnt3800Avg;
  if (SWC_RCF_DW.Rsv_cnt3800Avg < SWC_RCF_DW.Rsv_cnt4000Avg) {
    Rsv_cntMax = SWC_RCF_DW.Rsv_cnt4000Avg;
  }

  if (SWC_RCF_DW.Rsv_cnt3800Avg > SWC_RCF_DW.Rsv_cnt4000Avg) {
    Rsv_cntMin = SWC_RCF_DW.Rsv_cnt4000Avg;
  }

  if (Rsv_cntMax < SWC_RCF_DW.Rsv_cnt4200Avg) {
    Rsv_cntMax = SWC_RCF_DW.Rsv_cnt4200Avg;
  }

  if (Rsv_cntMin > SWC_RCF_DW.Rsv_cnt4200Avg) {
    Rsv_cntMin = SWC_RCF_DW.Rsv_cnt4200Avg;
  }

  if (Rsv_cntMax < SWC_RCF_DW.Rsv_cnt4400Avg) {
    Rsv_cntMax = SWC_RCF_DW.Rsv_cnt4400Avg;
  }

  if (Rsv_cntMin > SWC_RCF_DW.Rsv_cnt4400Avg) {
    Rsv_cntMin = SWC_RCF_DW.Rsv_cnt4400Avg;
  }

  if (Rsv_cntMax < SWC_RCF_DW.Rsv_cnt4600Avg) {
    Rsv_cntMax = SWC_RCF_DW.Rsv_cnt4600Avg;
  }

  if (Rsv_cntMin > SWC_RCF_DW.Rsv_cnt4600Avg) {
    Rsv_cntMin = SWC_RCF_DW.Rsv_cnt4600Avg;
  }

  if (Rsv_cntMax < SWC_RCF_DW.Rsv_cnt4800Avg) {
    Rsv_cntMax = SWC_RCF_DW.Rsv_cnt4800Avg;
  }

  if (Rsv_cntMin > SWC_RCF_DW.Rsv_cnt4800Avg) {
    Rsv_cntMin = SWC_RCF_DW.Rsv_cnt4800Avg;
  }

  if (Rsv_cntMax < SWC_RCF_DW.Rsv_cnt5000Avg) {
    Rsv_cntMax = SWC_RCF_DW.Rsv_cnt5000Avg;
  }

  if (Rsv_cntMin > SWC_RCF_DW.Rsv_cnt5000Avg) {
    Rsv_cntMin = SWC_RCF_DW.Rsv_cnt5000Avg;
  }

  return ((((((((SWC_RCF_DW.Rsv_cnt4600Avg + SWC_RCF_DW.Rsv_cnt4800Avg) +
                SWC_RCF_DW.Rsv_cnt5000Avg) + SWC_RCF_DW.Rsv_cnt3800Avg) +
              SWC_RCF_DW.Rsv_cnt4000Avg) + SWC_RCF_DW.Rsv_cnt4200Avg) +
            SWC_RCF_DW.Rsv_cnt4400Avg) - Rsv_cntMax) - Rsv_cntMin) / 5.0F;
}

static void SWC_RC_enter_internal_FailState(void)
{
  VAR_RCF_stAgRtrOfsCal_u8 = ((uint8)RCF_OfsClb_FrewhlStp_E);
  VAR_RCF_TrqEmDesOfsClb_f32 = 0.0F;
  VAR_RCF_cTrqSlpOfsClb_f32 = 1.0F;
  SWC_RCF_DW.RCF_cntDurAccState = 0U;
  SWC_RCF_DW.RCF_cntDurFrewhlClbFwdState = 0U;
  SWC_RCF_DW.RCF_cntDurFrewhlClbBwdState = 0U;
  SWC_RCF_DW.RCF_flgOfsClbFrwhl_Fwd = 0U;
  VAR_RCF_flgEnblOfsClbFrwhl_b = false;
  VAR_RCF_flgEnblOfsClbFrwhlBwd_b = false;
  VAR_RCF_flgEnblOfsClbFrwhlFwd_b = false;
  VAR_RCF_flgEnblEstAlRtrOfs_b = false;
}

static void SWC_enter_internal_DefaultState(void)
{
  VAR_RCF_stAgRtrOfsCal_u8 = ((uint8)RCF_OfsClb_Standby_E);
  VAR_RCF_stDiagOfsClb_u8 = ((uint8)RCF_OfsClb_NotTest_E);
  SWC_RCF_DW.RCF_cntDurAccState = 0U;
  SWC_RCF_DW.RCF_cntDurFrewhlClbBwdState = 0U;
  VAR_RCF_flgEnblOfsClbFrwhl_b = false;
  SWC_RCF_DW.RCF_cntDurFrewhlClbFwdState = 0U;
  VAR_RCF_TrqEmDesOfsClb_f32 = 0.0F;
  VAR_RCF_cTrqSlpOfsClb_f32 = 0.0F;
  VAR_RCF_flgEnblOfsClbFrwhlBwd_b = false;
  VAR_RCF_flgEnblOfsClbFrwhlFwd_b = false;
  VAR_RCF_flgEnblEstAlRtrOfs_b = false;
}

void SWC_RCF_100us(void)
{
  sint32 idxDelay;
  float32 tmpRead;
  boolean rtb_TmpSignalConversionAtIVDP_i;
  float32 rtb_Switch_o;
  float32 rtb_Switch;
  uint8 RCF_stEstAlRtrOfs;
  uint32 qY;
  uint8 tmp;
  uint16 tmp_0;
  Rte_Read_RP_SWC_Rdc_Rdc_nWoFlt(&SWC_RCF_B.TmpSignalConversionAtRP_SWC_Rdc);
  Rte_Read_RP_SWC_Rdc_Rdc_ArctanAgRtr(&SWC_RCF_B.TmpSignalConversionAtRP_SWC_R_k);
  Rte_Read_RP_SWC_HvMcu_HvMcu_flgUphaEdgeRiseCo
    (&SWC_RCF_B.TmpSignalConversionAtRP_SWC_HvM);
  rtb_TmpSignalConversionAtIVDP_i =
    Rte_IrvIRead_RE_SWC_RCF_100us_IVDP_RCF_flgEnblEstAlRtrOfs();
  if (CAL_RCF_flgEnOfsClb_b) {
    VAR_RCF_flgFailorFnhToDefault_b = !rtb_TmpSignalConversionAtIVDP_i;
    VAR_RCF_flgstDefTostEst_b = (rtb_TmpSignalConversionAtIVDP_i &&
      (!CAL_RCF_EstToDefault_b));
    VAR_RCF_flgstEstTostDef_b = (VAR_RCF_flgFailorFnhToDefault_b ||
      CAL_RCF_EstToDefault_b);
    rtb_Switch_o = fabsf(SWC_RCF_B.TmpSignalConversionAtRP_SWC_Rdc);
    VAR_RCF_flgstEstToFail_b = (rtb_Switch_o > CAL_RCF_nEstAlOfsStop_f32);
    VAR_RCF_flgstEstToWait_b = (rtb_Switch_o < CAL_RCF_nEstAlOfsStop_f32);
    if (SWC_RCF_DW.is_active_c3_SWC_RCF == 0U) {
      SWC_RCF_DW.is_active_c3_SWC_RCF = 1U;
      SWC_RCF_DW.is_c3_SWC_RCF = SWC_RCF_IN_DefaultState;
      VAR_RCF_stEstAlRtrOfs_u8 = ((uint8)RCF_EstAlOfsNoFinish_E);
      SWC_RCF_DW.RCF_cntEstAlOfsConst = 0U;
      SWC_RCF_DW.RCF_cntEstAlOfsConst1 = 0U;
      VAR_RCF_flgUseUsSet_b = false;
    } else {
      switch (SWC_RCF_DW.is_c3_SWC_RCF) {
       case SWC_RCF_IN_DefaultState:
        if (VAR_RCF_flgstDefTostEst_b) {
          SWC_RCF_DW.is_c3_SWC_RCF = SWC_RCF_IN_EstAlRtrOfsState;
          VAR_RCF_flgUseUsSet_b = true;
          SWC_RCF_DW.RCF_cntEstAlOfsConst = 0U;
        }
        break;

       case SWC_RCF_IN_EstAlRtrOfsState:
        qY = SWC_RCF_DW.RCF_cntEstAlOfsConst + 1U;
        if (qY < SWC_RCF_DW.RCF_cntEstAlOfsConst) {
          qY = MAX_uint32_T;
        }

        SWC_RCF_DW.RCF_cntEstAlOfsConst = qY;
        rtb_TmpSignalConversionAtIVDP_i = (SWC_RCF_DW.RCF_cntEstAlOfsConst <=
          CAL_RCF_tUbetaSet_u32);
        if (SWC_RCF_DW.RCF_cntEstAlOfsConst <= CAL_RCF_tUAlfaSet_u32) {
          if (rtb_TmpSignalConversionAtIVDP_i) {
            SWC_RCF_DW.UnitDelay_DSTATE = 0.0;
          } else {
            SWC_RCF_DW.UnitDelay_DSTATE = CAL_RCF_UsAlfaScalSet_f32;
          }
        }

        VAR_RCF_UsAlfaScalSet_f32 = (float32)SWC_RCF_DW.UnitDelay_DSTATE;
        if (rtb_TmpSignalConversionAtIVDP_i) {
          VAR_RCF_UsBetaScalSet_f32 = CAL_RCF_UsBetaScalSet_f32;
        } else {
          VAR_RCF_UsBetaScalSet_f32 = 0.0F;
        }

        if ((SWC_RCF_DW.RCF_cntEstAlOfsConst > CAL_RCF_tMaxEstAlOfs_u32) &&
            VAR_RCF_flgstEstToWait_b) {
          SWC_RCF_DW.is_c3_SWC_RCF = SWC_RCF_IN_wait;
          SWC_RCF_DW.RCF_cntEstAlOfsConst = 0U;
          SWC_RCF_B.RCF_agRtrOffsEstimd =
            SWC_RCF_B.TmpSignalConversionAtRP_SWC_R_k;
          VAR_RCF_stEstAlRtrOfs_u8 = ((uint8)RCF_EstAlOfsPreFinish_E);
          VAR_RCF_UsAlfaScalSet_f32 = 0.0F;
          VAR_RCF_UsBetaScalSet_f32 = 0.0F;
          SWC_RCF_DW.RCF_cntEstAlOfsConst1 = 0U;
        } else if ((SWC_RCF_DW.RCF_cntEstAlOfsConst > CAL_RCF_tHiEstAlOfs_u32) &&
                   VAR_RCF_flgstEstToFail_b) {
          SWC_RCF_DW.is_c3_SWC_RCF = SWC_RCF_IN_FailState;
          SWC_RCF_DW.RCF_cntEstAlOfsConst = 0U;
          VAR_RCF_stEstAlRtrOfs_u8 = ((uint8)RCF_EstAlOfsFail_E);
          VAR_RCF_flgUseUsSet_b = false;
          VAR_RCF_UsAlfaScalSet_f32 = 0.0F;
          VAR_RCF_UsBetaScalSet_f32 = 0.0F;
          SWC_RCF_B.RCF_agRtrOffsEstimd = 0.0F;
        } else {
          if (VAR_RCF_flgstEstTostDef_b) {
            VAR_RCF_UsAlfaScalSet_f32 = 0.0F;
            VAR_RCF_UsBetaScalSet_f32 = 0.0F;
            SWC_RCF_DW.is_c3_SWC_RCF = SWC_RCF_IN_DefaultState;
            VAR_RCF_stEstAlRtrOfs_u8 = ((uint8)RCF_EstAlOfsNoFinish_E);
            SWC_RCF_DW.RCF_cntEstAlOfsConst = 0U;
            SWC_RCF_DW.RCF_cntEstAlOfsConst1 = 0U;
            VAR_RCF_flgUseUsSet_b = false;
          }
        }
        break;

       case SWC_RCF_IN_FailState:
        if (VAR_RCF_flgFailorFnhToDefault_b) {
          SWC_RCF_DW.is_c3_SWC_RCF = SWC_RCF_IN_DefaultState;
          VAR_RCF_stEstAlRtrOfs_u8 = ((uint8)RCF_EstAlOfsNoFinish_E);
          SWC_RCF_DW.RCF_cntEstAlOfsConst = 0U;
          SWC_RCF_DW.RCF_cntEstAlOfsConst1 = 0U;
          VAR_RCF_flgUseUsSet_b = false;
        }
        break;

       case SWC_RCF_IN_FinishState:
        if (VAR_RCF_flgFailorFnhToDefault_b) {
          SWC_RCF_DW.is_c3_SWC_RCF = SWC_RCF_IN_DefaultState;
          VAR_RCF_stEstAlRtrOfs_u8 = ((uint8)RCF_EstAlOfsNoFinish_E);
          SWC_RCF_DW.RCF_cntEstAlOfsConst = 0U;
          SWC_RCF_DW.RCF_cntEstAlOfsConst1 = 0U;
          VAR_RCF_flgUseUsSet_b = false;
        }
        break;

       default:
        qY = SWC_RCF_DW.RCF_cntEstAlOfsConst1 + 1U;
        if (qY < SWC_RCF_DW.RCF_cntEstAlOfsConst1) {
          qY = MAX_uint32_T;
        }

        SWC_RCF_DW.RCF_cntEstAlOfsConst1 = qY;
        if (SWC_RCF_DW.RCF_cntEstAlOfsConst1 >= CAL_RCF_tMaxEstAlOfs1_u32) {
          SWC_RCF_DW.is_c3_SWC_RCF = SWC_RCF_IN_FinishState;
          SWC_RCF_DW.RCF_cntEstAlOfsConst1 = 0U;
          VAR_RCF_stEstAlRtrOfs_u8 = ((uint8)RCF_EstAlOfsFinish_E);
          VAR_RCF_flgUseUsSet_b = false;
        }
        break;
      }
    }

    SWC_RCF_B.LogicalOperator = VAR_RCF_flgUseUsSet_b;
    SWC_RCF_B.Add = VAR_RCF_UsAlfaScalSet_f32;
    SWC_RCF_B.Add1 = VAR_RCF_UsBetaScalSet_f32;
    SWC_RCF_B.Add2 = VAR_RCF_stEstAlRtrOfs_u8;
    VAR_RCF_flgInactToFwdClb_b =
      (Rte_IrvIRead_RE_SWC_RCF_100us_IVDP_RCF_flgEnblOfsClbFrwhlFwd() &&
       SWC_RCF_B.TmpSignalConversionAtRP_SWC_HvM);
    VAR_RCF_flgClbToInact_b =
      !Rte_IrvIRead_RE_SWC_RCF_100us_IVDP_RCF_flgEnblOfsClbFrwhl();
    VAR_RCF_flgClbReset_b = SWC_RCF_B.TmpSignalConversionAtRP_SWC_HvM;
    VAR_RCF_flgFwdClbToWait_b = (SWC_RCF_B.TmpSignalConversionAtRP_SWC_Rdc <
      CAL_RCF_nOfValFwdStp_f32);
    VAR_RCF_flgWaitToBwdClb_b =
      (Rte_IrvIRead_RE_SWC_RCF_100us_IVDP_RCF_flgEnblOfsClbFrwhlBwd() &&
       SWC_RCF_B.TmpSignalConversionAtRP_SWC_HvM);
    VAR_RCF_flgBwdClbToCalc_b = (SWC_RCF_B.TmpSignalConversionAtRP_SWC_Rdc >
      CAL_RCF_nOfValBwdStp_f32);
    VAR_RCF_flgInactToBwdClb_b = VAR_RCF_flgWaitToBwdClb_b;
    if (SWC_RCF_DW.is_active_c2_SWC_RCF == 0U) {
      SWC_RCF_DW.is_active_c2_SWC_RCF = 1U;
      SWC_RCF_DW.is_c2_SWC_RCF = SWC_RCF_IN_InactiveState;
      VAR_RCF_stOfsClbFrwhl_u8 = ((uint8)RCF_Inactive_E);
      VAR_RCF_stOfsFrwhlFwd_u8 = ((uint8)RCF_NoFishdSucdClbFwd_E);
      VAR_RCF_stOfsFrwhlBwd_u8 = ((uint8)RCF_NoFishdSucdClbBwd_E);
    } else {
      Rte_Read_RP_SWC_HvMcu_HvMcu_AlOfsClb_TimeStamp(&tmpRead);
      switch (SWC_RCF_DW.is_c2_SWC_RCF) {
       case SWC_RCF_IN_CollectValuesBwd:
        qY = SWC_RCF_DW.RCF_noOfValuesBwd + 1U;
        if (qY < SWC_RCF_DW.RCF_noOfValuesBwd) {
          qY = MAX_uint32_T;
        }

        SWC_RCF_DW.RCF_noOfValuesBwd = qY;
        if ((VAR_RCF_agRtrOffsEstimd_f32 <= CAL_RCF_agReferenceBwd_f32 +
             CAL_RCF_360EdgeRag_f32) && (VAR_RCF_agRtrOffsEstimd_f32 >=
             CAL_RCF_agReferenceBwd_f32 - CAL_RCF_360EdgeRag_f32)) {
          if (SWC_RCF_B.TmpSignalConversionAtRP_SWC_R_k >= 180.0F) {
            rtb_Switch = SWC_RCF_B.TmpSignalConversionAtRP_SWC_R_k -
              CAL_RCF_CircAge_f32;
          } else {
            rtb_Switch = SWC_RCF_B.TmpSignalConversionAtRP_SWC_R_k;
          }
        } else {
          rtb_Switch = SWC_RCF_B.TmpSignalConversionAtRP_SWC_R_k;
        }

        VAR_RCF_OfsClbAngBwd_f32 = (SWC_RCF_B.TmpSignalConversionAtRP_SWC_Rdc *
          (float32)((uint8)CAL_RCF_MotorPole_u8) / CAL_RCF_Sixty_f32 *
          CAL_RCF_CircAge_f32 / 1.0E+6F * tmpRead + CAL_RCF_agReferenceBwd_f32)
          - rtb_Switch;
        rtb_TmpSignalConversionAtIVDP_i =
          ((SWC_RCF_B.TmpSignalConversionAtRP_SWC_Rdc >=
            CAL_RCF_nOfsClbMaxBwd_f32) ||
           (SWC_RCF_B.TmpSignalConversionAtRP_SWC_Rdc <=
            CAL_RCF_nOfsClbMinBwd_f32));
        if ((!rtb_TmpSignalConversionAtIVDP_i) &&
            SWC_RCF_B.TmpSignalConversionAtRP_SWC_HvM) {
          SWC_RCF_DW.UnitDelay_DSTATE_m = (uint8)((uint32)
            !SWC_RCF_DW.UnitDelay5_DSTATE + SWC_RCF_DW.UnitDelay_DSTATE_m);
          SWC_RCF_DW.UnitDelay5_DSTATE = (CAL_RCF_cntMovAveFilBwd_u16 <=
            SWC_RCF_DW.UnitDelay_DSTATE_m);
          if (CAL_RCF_cntMovAveFilBwd_u16 > 100) {
            tmp_0 = 100U;
          } else {
            tmp_0 = CAL_RCF_cntMovAveFilBwd_u16;
          }

          if (SWC_RCF_DW.UnitDelay5_DSTATE) {
            if (CAL_RCF_cntMovAveFilBwd_u16 <= 0) {
              rtb_Switch = VAR_RCF_OfsClbAngBwd_f32;
            } else {
              rtb_Switch = SWC_RCF_DW.Delay_DSTATE[(uint16)(100U - tmp_0)];
            }
          } else {
            rtb_Switch = 0.0F;
          }

          SWC_RCF_DW.UnitDelay4_DSTATE += rtb_Switch;
          SWC_RCF_DW.UnitDelay1_DSTATE += VAR_RCF_OfsClbAngBwd_f32;
          if (SWC_RCF_DW.UnitDelay5_DSTATE) {
            if (SWC_RCF_DW.UnitDelay5_DSTATE) {
              tmp_0 = CAL_RCF_cntMovAveFilBwd_u16;
            } else {
              tmp_0 = SWC_RCF_DW.UnitDelay_DSTATE_m;
            }

            SWC_RCF_DW.UnitDelay3_DSTATE = (SWC_RCF_DW.UnitDelay1_DSTATE -
              SWC_RCF_DW.UnitDelay4_DSTATE) / (float32)tmp_0;
          }

          for (idxDelay = 0; idxDelay < 99; idxDelay++) {
            SWC_RCF_DW.Delay_DSTATE[idxDelay] = SWC_RCF_DW.Delay_DSTATE[idxDelay
              + 1];
          }

          SWC_RCF_DW.Delay_DSTATE[99] = VAR_RCF_OfsClbAngBwd_f32;
        }

        if (SWC_RCF_DW.UnitDelay3_DSTATE < 0.0F) {
          rtb_Switch = CAL_RCF_CircAge_f32 + SWC_RCF_DW.UnitDelay3_DSTATE;
        } else if (SWC_RCF_DW.UnitDelay3_DSTATE >= CAL_RCF_CircAge_f32) {
          rtb_Switch = SWC_RCF_DW.UnitDelay3_DSTATE - CAL_RCF_CircAge_f32;
        } else {
          rtb_Switch = SWC_RCF_DW.UnitDelay3_DSTATE;
        }

        if ((rtb_Switch_o >= CAL_RCF_nCalcSec1_f32) && (rtb_Switch_o <
             CAL_RCF_nCalcSec2_f32)) {
          SWC_RCF_IfActionSubsystem8(rtb_Switch, &VAR_RCF_OfsFlt3600Bwd_f32,
            &SWC_RCF_DW.IfActionSubsystem13);
        } else if ((rtb_Switch_o >= CAL_RCF_nCalcSec2_f32) && (rtb_Switch_o <
                    CAL_RCF_nCalcSec3_f32)) {
          SWC_RCF_IfActionSubsystem8(rtb_Switch, &VAR_RCF_OfsFlt3800Bwd_f32,
            &SWC_RCF_DW.IfActionSubsystem6_d);
        } else if ((rtb_Switch_o >= CAL_RCF_nCalcSec3_f32) && (rtb_Switch_o <
                    CAL_RCF_nCalcSec4_f32)) {
          SWC_RCF_IfActionSubsystem8(rtb_Switch, &VAR_RCF_OfsFlt4000Bwd_f32,
            &SWC_RCF_DW.IfActionSubsystem7);
        } else if ((rtb_Switch_o >= CAL_RCF_nCalcSec4_f32) && (rtb_Switch_o <
                    CAL_RCF_nCalcSec5_f32)) {
          SWC_RCF_IfActionSubsystem8(rtb_Switch, &VAR_RCF_OfsFlt4200Bwd_f32,
            &SWC_RCF_DW.IfActionSubsystem9);
        } else if ((rtb_Switch_o >= CAL_RCF_nCalcSec5_f32) && (rtb_Switch_o <
                    CAL_RCF_nCalcSec6_f32)) {
          SWC_RCF_IfActionSubsystem8(rtb_Switch, &VAR_RCF_OfsFlt4400Bwd_f32,
            &SWC_RCF_DW.IfActionSubsystem10);
        } else if ((rtb_Switch_o >= CAL_RCF_nCalcSec6_f32) && (rtb_Switch_o <
                    CAL_RCF_nCalcSec7_f32)) {
          SWC_RCF_IfActionSubsystem8(rtb_Switch, &VAR_RCF_OfsFlt4600Bwd_f32,
            &SWC_RCF_DW.IfActionSubsystem11);
        } else {
          if ((rtb_Switch_o >= CAL_RCF_nCalcSec7_f32) && (rtb_Switch_o <
               CAL_RCF_nCalcSec8_f32)) {
            SWC_RCF_IfActionSubsystem8(rtb_Switch, &VAR_RCF_OfsFlt4800Bwd_f32,
              &SWC_RCF_DW.IfActionSubsystem12);
          }
        }

        SWC_RCF_DW.OfsFlt3600Bwd = VAR_RCF_OfsFlt3600Bwd_f32;
        SWC_RCF_DW.OfsFlt3800Bwd = VAR_RCF_OfsFlt3800Bwd_f32;
        SWC_RCF_DW.OfsFlt4000Bwd = VAR_RCF_OfsFlt4000Bwd_f32;
        SWC_RCF_DW.OfsFlt4200Bwd = VAR_RCF_OfsFlt4200Bwd_f32;
        SWC_RCF_DW.OfsFlt4400Bwd = VAR_RCF_OfsFlt4400Bwd_f32;
        SWC_RCF_DW.OfsFlt4600Bwd = VAR_RCF_OfsFlt4600Bwd_f32;
        SWC_RCF_DW.OfsFlt4800Bwd = VAR_RCF_OfsFlt4800Bwd_f32;
        if ((SWC_RCF_DW.RCF_noOfValuesBwd > CAL_RCF_cntOfValBwd_u32) ||
            VAR_RCF_flgBwdClbToCalc_b) {
          VAR_RCF_stOfsFrwhlBwd_u8 = ((uint8)RCF_FishdSucdClbBwd_E);
          SWC_RCF_DW.is_c2_SWC_RCF = SWC_RCF_IN_EvaluateResults;
        } else if (rtb_TmpSignalConversionAtIVDP_i && VAR_RCF_flgClbReset_b) {
          SWC_RCF_DW.is_c2_SWC_RCF = SWC_RCF_IN_CollectValuesBwd;
          VAR_RCF_stOfsClbFrwhl_u8 = ((uint8)RCF_InProgress_E);
          SWC_RCF_DW.RCF_noOfValuesBwd = 0U;
          VAR_RCF_stOfsFrwhlBwd_u8 = ((uint8)RCF_NoFishdSucdClbBwd_E);
        } else {
          if (VAR_RCF_flgClbToInact_b) {
            SWC_RCF_DW.is_c2_SWC_RCF = SWC_RCF_IN_InactiveState;
            VAR_RCF_stOfsClbFrwhl_u8 = ((uint8)RCF_Inactive_E);
            VAR_RCF_stOfsFrwhlFwd_u8 = ((uint8)RCF_NoFishdSucdClbFwd_E);
            VAR_RCF_stOfsFrwhlBwd_u8 = ((uint8)RCF_NoFishdSucdClbBwd_E);
          }
        }
        break;

       case SWC_RCF_IN_CollectValuesFwd:
        qY = SWC_RCF_DW.RCF_noOfValuesFwd + 1U;
        if (qY < SWC_RCF_DW.RCF_noOfValuesFwd) {
          qY = MAX_uint32_T;
        }

        SWC_RCF_DW.RCF_noOfValuesFwd = qY;
        VAR_RCF_flg360Edge_b = ((VAR_RCF_agRtrOffsEstimd_f32 <=
          CAL_RCF_agReferenceFwd_f32 + CAL_RCF_360EdgeRag_f32) &&
          (VAR_RCF_agRtrOffsEstimd_f32 >= CAL_RCF_agReferenceFwd_f32 -
           CAL_RCF_360EdgeRag_f32));
        if (VAR_RCF_flg360Edge_b) {
          if (SWC_RCF_B.TmpSignalConversionAtRP_SWC_R_k >= 180.0F) {
            rtb_Switch = SWC_RCF_B.TmpSignalConversionAtRP_SWC_R_k -
              CAL_RCF_CircAge_f32;
          } else {
            rtb_Switch = SWC_RCF_B.TmpSignalConversionAtRP_SWC_R_k;
          }
        } else {
          rtb_Switch = SWC_RCF_B.TmpSignalConversionAtRP_SWC_R_k;
        }

        VAR_RCF_OfsClbAngFwd_f32 = (SWC_RCF_B.TmpSignalConversionAtRP_SWC_Rdc *
          (float32)((uint8)CAL_RCF_MotorPole_u8) / CAL_RCF_Sixty_f32 *
          CAL_RCF_CircAge_f32 / 1.0E+6F * tmpRead + CAL_RCF_agReferenceFwd_f32)
          - rtb_Switch;
        rtb_TmpSignalConversionAtIVDP_i =
          ((SWC_RCF_B.TmpSignalConversionAtRP_SWC_Rdc >=
            CAL_RCF_nOfsClbMaxFwd_f32) ||
           (SWC_RCF_B.TmpSignalConversionAtRP_SWC_Rdc <=
            CAL_RCF_nOfsClbMinFwd_f32));
        if ((!rtb_TmpSignalConversionAtIVDP_i) &&
            SWC_RCF_B.TmpSignalConversionAtRP_SWC_HvM) {
          SWC_RCF_DW.UnitDelay_DSTATE_g2 = (uint8)((uint32)
            !SWC_RCF_DW.UnitDelay2_DSTATE + SWC_RCF_DW.UnitDelay_DSTATE_g2);
          SWC_RCF_DW.UnitDelay2_DSTATE = (CAL_RCF_cntMovAveFilFwd_u16 <=
            SWC_RCF_DW.UnitDelay_DSTATE_g2);
          if (CAL_RCF_cntMovAveFilFwd_u16 > 100) {
            tmp_0 = 100U;
          } else {
            tmp_0 = CAL_RCF_cntMovAveFilFwd_u16;
          }

          if (SWC_RCF_DW.UnitDelay2_DSTATE) {
            if (CAL_RCF_cntMovAveFilFwd_u16 <= 0) {
              rtb_Switch = VAR_RCF_OfsClbAngFwd_f32;
            } else {
              rtb_Switch = SWC_RCF_DW.Delay_DSTATE_a[(uint16)(100U - tmp_0)];
            }
          } else {
            rtb_Switch = 0.0F;
          }

          SWC_RCF_DW.UnitDelay4_DSTATE_l += rtb_Switch;
          SWC_RCF_DW.UnitDelay1_DSTATE_f += VAR_RCF_OfsClbAngFwd_f32;
          if (SWC_RCF_DW.UnitDelay2_DSTATE) {
            if (SWC_RCF_DW.UnitDelay2_DSTATE) {
              tmp_0 = CAL_RCF_cntMovAveFilFwd_u16;
            } else {
              tmp_0 = SWC_RCF_DW.UnitDelay_DSTATE_g2;
            }

            SWC_RCF_DW.UnitDelay3_DSTATE_k = (SWC_RCF_DW.UnitDelay1_DSTATE_f -
              SWC_RCF_DW.UnitDelay4_DSTATE_l) / (float32)tmp_0;
          }

          for (idxDelay = 0; idxDelay < 99; idxDelay++) {
            SWC_RCF_DW.Delay_DSTATE_a[idxDelay] =
              SWC_RCF_DW.Delay_DSTATE_a[idxDelay + 1];
          }

          SWC_RCF_DW.Delay_DSTATE_a[99] = VAR_RCF_OfsClbAngFwd_f32;
        }

        if (SWC_RCF_DW.UnitDelay3_DSTATE_k < 0.0F) {
          rtb_Switch_o = CAL_RCF_CircAge_f32 + SWC_RCF_DW.UnitDelay3_DSTATE_k;
        } else if (SWC_RCF_DW.UnitDelay3_DSTATE_k >= CAL_RCF_CircAge_f32) {
          rtb_Switch_o = SWC_RCF_DW.UnitDelay3_DSTATE_k - CAL_RCF_CircAge_f32;
        } else {
          rtb_Switch_o = SWC_RCF_DW.UnitDelay3_DSTATE_k;
        }

        if ((SWC_RCF_B.TmpSignalConversionAtRP_SWC_Rdc >= CAL_RCF_nCalcSec1_f32)
            && (SWC_RCF_B.TmpSignalConversionAtRP_SWC_Rdc <
                CAL_RCF_nCalcSec2_f32)) {
          SWC_RCF_IfActionSubsystem8(rtb_Switch_o, &VAR_RCF_OfsFlt3600Fwd_f32,
            &SWC_RCF_DW.IfActionSubsystem8);
        } else if ((SWC_RCF_B.TmpSignalConversionAtRP_SWC_Rdc >=
                    CAL_RCF_nCalcSec2_f32) &&
                   (SWC_RCF_B.TmpSignalConversionAtRP_SWC_Rdc <
                    CAL_RCF_nCalcSec3_f32)) {
          SWC_RCF_IfActionSubsystem8(rtb_Switch_o, &VAR_RCF_OfsFlt3800Fwd_f32,
            &SWC_RCF_DW.IfActionSubsystem1);
        } else if ((SWC_RCF_B.TmpSignalConversionAtRP_SWC_Rdc >=
                    CAL_RCF_nCalcSec3_f32) &&
                   (SWC_RCF_B.TmpSignalConversionAtRP_SWC_Rdc <
                    CAL_RCF_nCalcSec4_f32)) {
          SWC_RCF_IfActionSubsystem8(rtb_Switch_o, &VAR_RCF_OfsFlt4000Fwd_f32,
            &SWC_RCF_DW.IfActionSubsystem2);
        } else if ((SWC_RCF_B.TmpSignalConversionAtRP_SWC_Rdc >=
                    CAL_RCF_nCalcSec4_f32) &&
                   (SWC_RCF_B.TmpSignalConversionAtRP_SWC_Rdc <
                    CAL_RCF_nCalcSec5_f32)) {
          SWC_RCF_IfActionSubsystem8(rtb_Switch_o, &VAR_RCF_OfsFlt4200Fwd_f32,
            &SWC_RCF_DW.IfActionSubsystem3);
        } else if ((SWC_RCF_B.TmpSignalConversionAtRP_SWC_Rdc >=
                    CAL_RCF_nCalcSec5_f32) &&
                   (SWC_RCF_B.TmpSignalConversionAtRP_SWC_Rdc <
                    CAL_RCF_nCalcSec6_f32)) {
          SWC_RCF_IfActionSubsystem8(rtb_Switch_o, &VAR_RCF_OfsFlt4400Fwd_f32,
            &SWC_RCF_DW.IfActionSubsystem4);
        } else if ((SWC_RCF_B.TmpSignalConversionAtRP_SWC_Rdc >=
                    CAL_RCF_nCalcSec6_f32) &&
                   (SWC_RCF_B.TmpSignalConversionAtRP_SWC_Rdc <
                    CAL_RCF_nCalcSec7_f32)) {
          SWC_RCF_IfActionSubsystem8(rtb_Switch_o, &VAR_RCF_OfsFlt4600Fwd_f32,
            &SWC_RCF_DW.IfActionSubsystem5);
        } else {
          if ((SWC_RCF_B.TmpSignalConversionAtRP_SWC_Rdc >=
               CAL_RCF_nCalcSec7_f32) &&
              (SWC_RCF_B.TmpSignalConversionAtRP_SWC_Rdc < CAL_RCF_nCalcSec8_f32))
          {
            SWC_RCF_IfActionSubsystem8(rtb_Switch_o, &VAR_RCF_OfsFlt4800Fwd_f32,
              &SWC_RCF_DW.IfActionSubsystem6);
          }
        }

        SWC_RCF_DW.OfsFlt3600Fwd = VAR_RCF_OfsFlt3600Fwd_f32;
        SWC_RCF_DW.OfsFlt3800Fwd = VAR_RCF_OfsFlt3800Fwd_f32;
        SWC_RCF_DW.OfsFlt4000Fwd = VAR_RCF_OfsFlt4000Fwd_f32;
        SWC_RCF_DW.OfsFlt4200Fwd = VAR_RCF_OfsFlt4200Fwd_f32;
        SWC_RCF_DW.OfsFlt4400Fwd = VAR_RCF_OfsFlt4400Fwd_f32;
        SWC_RCF_DW.OfsFlt4600Fwd = VAR_RCF_OfsFlt4600Fwd_f32;
        SWC_RCF_DW.OfsFlt4800Fwd = VAR_RCF_OfsFlt4800Fwd_f32;
        if ((SWC_RCF_DW.RCF_noOfValuesFwd > CAL_RCF_cntOfValFwd_u32) ||
            VAR_RCF_flgFwdClbToWait_b) {
          VAR_RCF_stOfsFrwhlFwd_u8 = ((uint8)RCF_FishdSucdClbFwd_E);
          SWC_RCF_DW.is_c2_SWC_RCF = SWC_RCF_IN_WaitState;
        } else if (VAR_RCF_flgClbToInact_b) {
          SWC_RCF_DW.is_c2_SWC_RCF = SWC_RCF_IN_InactiveState;
          VAR_RCF_stOfsClbFrwhl_u8 = ((uint8)RCF_Inactive_E);
          VAR_RCF_stOfsFrwhlFwd_u8 = ((uint8)RCF_NoFishdSucdClbFwd_E);
          VAR_RCF_stOfsFrwhlBwd_u8 = ((uint8)RCF_NoFishdSucdClbBwd_E);
        } else {
          if (rtb_TmpSignalConversionAtIVDP_i && VAR_RCF_flgClbReset_b) {
            SWC_RCF_DW.is_c2_SWC_RCF = SWC_RCF_IN_CollectValuesFwd;
            VAR_RCF_stOfsClbFrwhl_u8 = ((uint8)RCF_InProgress_E);
            SWC_RCF_DW.RCF_noOfValuesFwd = 0U;
            VAR_RCF_stOfsFrwhlFwd_u8 = ((uint8)RCF_NoFishdSucdClbFwd_E);
          }
        }
        break;

       case SWC_RCF_IN_EvaluateResults:
        VAR_RCF_AutoClbOffset_f32 = SWC_RCF_AloffsetCalc((float32)
          VAR_RCF_stOfsFrwhlFwd_u8, (float32)VAR_RCF_stOfsFrwhlBwd_u8,
          SWC_RCF_DW.OfsFlt3600Fwd, SWC_RCF_DW.OfsFlt3800Fwd,
          SWC_RCF_DW.OfsFlt4000Fwd, SWC_RCF_DW.OfsFlt4200Fwd,
          SWC_RCF_DW.OfsFlt4400Fwd, SWC_RCF_DW.OfsFlt4600Fwd,
          SWC_RCF_DW.OfsFlt4800Fwd, SWC_RCF_DW.OfsFlt3600Bwd,
          SWC_RCF_DW.OfsFlt3800Bwd, SWC_RCF_DW.OfsFlt4000Bwd,
          SWC_RCF_DW.OfsFlt4200Bwd, SWC_RCF_DW.OfsFlt4400Bwd,
          SWC_RCF_DW.OfsFlt4600Bwd, SWC_RCF_DW.OfsFlt4800Bwd);
        if (fabsf(VAR_RCF_AutoClbOffset_f32 - VAR_RCF_agRtrOffsEstimd_f32) >=
            CAL_RCF_AlRtrOfsDvtMax_f32) {
          VAR_RCF_stOfsClbFrwhl_u8 = ((uint8)RCF_OfsClbfishedFaild_E);
        } else {
          VAR_RCF_stOfsClbFrwhl_u8 = ((uint8)RCF_OfsClbfishedSucd_E);
        }

        if (VAR_RCF_flgClbToInact_b) {
          SWC_RCF_DW.is_c2_SWC_RCF = SWC_RCF_IN_InactiveState;
          VAR_RCF_stOfsClbFrwhl_u8 = ((uint8)RCF_Inactive_E);
          VAR_RCF_stOfsFrwhlFwd_u8 = ((uint8)RCF_NoFishdSucdClbFwd_E);
          VAR_RCF_stOfsFrwhlBwd_u8 = ((uint8)RCF_NoFishdSucdClbBwd_E);
        }
        break;

       case SWC_RCF_IN_InactiveState:
        if (VAR_RCF_flgInactToFwdClb_b) {
          SWC_RCF_DW.is_c2_SWC_RCF = SWC_RCF_IN_CollectValuesFwd;
          VAR_RCF_stOfsClbFrwhl_u8 = ((uint8)RCF_InProgress_E);
          SWC_RCF_DW.RCF_noOfValuesFwd = 0U;
          VAR_RCF_stOfsFrwhlFwd_u8 = ((uint8)RCF_NoFishdSucdClbFwd_E);
        } else {
          if (VAR_RCF_flgInactToBwdClb_b) {
            SWC_RCF_DW.is_c2_SWC_RCF = SWC_RCF_IN_CollectValuesBwd;
            VAR_RCF_stOfsClbFrwhl_u8 = ((uint8)RCF_InProgress_E);
            SWC_RCF_DW.RCF_noOfValuesBwd = 0U;
            VAR_RCF_stOfsFrwhlBwd_u8 = ((uint8)RCF_NoFishdSucdClbBwd_E);
          }
        }
        break;

       default:
        if (VAR_RCF_flgClbToInact_b) {
          SWC_RCF_DW.is_c2_SWC_RCF = SWC_RCF_IN_InactiveState;
          VAR_RCF_stOfsClbFrwhl_u8 = ((uint8)RCF_Inactive_E);
          VAR_RCF_stOfsFrwhlFwd_u8 = ((uint8)RCF_NoFishdSucdClbFwd_E);
          VAR_RCF_stOfsFrwhlBwd_u8 = ((uint8)RCF_NoFishdSucdClbBwd_E);
        } else {
          if (VAR_RCF_flgWaitToBwdClb_b) {
            SWC_RCF_DW.is_c2_SWC_RCF = SWC_RCF_IN_CollectValuesBwd;
            VAR_RCF_stOfsClbFrwhl_u8 = ((uint8)RCF_InProgress_E);
            SWC_RCF_DW.RCF_noOfValuesBwd = 0U;
            VAR_RCF_stOfsFrwhlBwd_u8 = ((uint8)RCF_NoFishdSucdClbBwd_E);
          }
        }
        break;
      }
    }

    SWC_RCF_B.Add3 = VAR_RCF_stOfsFrwhlFwd_u8;
    SWC_RCF_B.Add4 = VAR_RCF_stOfsClbFrwhl_u8;
    if (VAR_RCF_AutoClbOffset_f32 < 0.0F) {
      SWC_RCF_B.Switch = CAL_RCF_CircAge_f32 + VAR_RCF_AutoClbOffset_f32;
    } else if (VAR_RCF_AutoClbOffset_f32 >= CAL_RCF_CircAge_f32) {
      SWC_RCF_B.Switch = VAR_RCF_AutoClbOffset_f32 - CAL_RCF_CircAge_f32;
    } else {
      SWC_RCF_B.Switch = VAR_RCF_AutoClbOffset_f32;
    }

    VAR_RCF_agRtrOffsEstimd_f32 = CAL_RCF_CircAge_f32 -
      SWC_RCF_B.RCF_agRtrOffsEstimd;
    RCF_stEstAlRtrOfs = SWC_RCF_B.Add2;
  } else {
    RCF_stEstAlRtrOfs = 0U;
  }

  Rte_IrvIWrite_RE_SWC_RCF_100us_IVDP_RCF_stEstAlRtrOfs(RCF_stEstAlRtrOfs);
  (void) Rte_Write_PP_SWC_RCF_RCF_flgUseUsSet(CAL_RCF_flgEnOfsClb_b &&
    SWC_RCF_B.LogicalOperator);
  if (CAL_RCF_flgEnOfsClb_b) {
    rtb_Switch = SWC_RCF_B.Add;
  } else {
    rtb_Switch = 0.0F;
  }

  (void) Rte_Write_PP_SWC_RCF_RCF_UsAlfaScalSet(rtb_Switch);
  if (CAL_RCF_flgEnOfsClb_b) {
    rtb_Switch = SWC_RCF_B.Add1;
  } else {
    rtb_Switch = 0.0F;
  }

  (void) Rte_Write_PP_SWC_RCF_RCF_UsBetaScalSet(rtb_Switch);
  if (CAL_RCF_flgEnOfsClb_b) {
    rtb_Switch = VAR_RCF_agRtrOffsEstimd_f32;
  } else {
    rtb_Switch = 0.0F;
  }

  (void) Rte_Write_PP_SWC_RCF_RCF_agRtrOffsEstimd(rtb_Switch);
  if (CAL_RCF_flgEnOfsClb_b) {
    rtb_Switch = SWC_RCF_B.Switch;
  } else {
    rtb_Switch = 0.0F;
  }

  (void) Rte_Write_PP_SWC_RCF_RCF_AutoClbOffset(rtb_Switch);
  if (CAL_RCF_flgEnOfsClb_b) {
    tmp = SWC_RCF_B.Add3;
  } else {
    tmp = 0U;
  }

  Rte_IrvIWrite_RE_SWC_RCF_100us_IVDP_RCF_stOfsFrwhlFwd(tmp);
  if (CAL_RCF_flgEnOfsClb_b) {
    tmp = SWC_RCF_B.Add4;
  } else {
    tmp = 0U;
  }

  Rte_IrvIWrite_RE_SWC_RCF_100us_IVDP_RCF_stOfsClbFrwhl(tmp);
  (void) Rte_Write_PP_SWC_RCF_RCF_stEstAlRtrOfs(RCF_stEstAlRtrOfs);
}

void SWC_RCF_10ms(void)
{
  uint8 rtb_TmpSignalConversionAtRP_S_i;
  uint8 rtb_TmpSignalConversionAtRP_S_h;
  float32 rtb_TmpSignalConversionAtRP_SWC;
  uint8 rtb_TmpSignalConversionAtRP_S_l;
  uint8 rtb_TmpSignalConversionAtIVDP_R;
  uint8 rtb_TmpSignalConversionAtIVDP_f;
  boolean rtb_Switch8;
  boolean Switch6;
  float32 VAR_RCF_flgDefaultToWait_b_tmp;
  sint32 tmp;
  boolean guard1 = false;
  boolean guard2 = false;
  boolean guard3 = false;
  Switch6 = (SWC_RCF_DW.UnitDelay_DSTATE_b == 1);
  if (CAL_RCF_flgUseClbSucNvm_b) {
    if (CAL_RCF_flgReAutoClbSuc_b) {
      Rte_Read_RP_SWC_NvM_NvM_flgAngAutoClbOffset(&rtb_Switch8);
      rtb_Switch8 = ((!rtb_Switch8) && Switch6);
    } else {
      rtb_Switch8 = Switch6;
    }

    (void) Rte_Write_PP_SWC_RCF_RCF_flgOfsClbSucToNVM(rtb_Switch8);
  } else {
    (void) Rte_Write_PP_SWC_RCF_RCF_flgOfsClbSucToNVM(false);
  }

  Rte_Read_RP_SWC_CSPF_CSPF_RecstModeReq(&rtb_TmpSignalConversionAtRP_S_i);
  Rte_Read_RP_SWC_SCF_SCF_stDrvCtl(&rtb_TmpSignalConversionAtRP_S_h);
  Rte_Read_RP_SWC_HSPF_HSPF_nSlowFlt(&rtb_TmpSignalConversionAtRP_SWC);
  VAR_RCF_flgDefaultToWait_b_tmp = fabsf(rtb_TmpSignalConversionAtRP_SWC);
  VAR_RCF_flgDefaultToWait_b = ((rtb_TmpSignalConversionAtRP_S_i == ((uint8)
    RCF_goalOfsClbReq_E)) && (rtb_TmpSignalConversionAtRP_S_h == ((uint8)
    RCF_DrvOffsetCal_E)) && (VAR_RCF_flgDefaultToWait_b_tmp <
    CAL_RCF_nMaxStartAcc_f32));
  Rte_Read_RP_SWC_MDF_MDF_stFrwhl(&rtb_TmpSignalConversionAtRP_S_l);
  VAR_RCF_flgDefaultToClbFreFwd_b = ((rtb_TmpSignalConversionAtRP_S_l ==
    CAL_RCF_WithoutStatorCurrent_u8) && (rtb_TmpSignalConversionAtRP_S_i ==
    ((uint8)RCF_goalOfsClbReq_E)) && (rtb_TmpSignalConversionAtRP_S_h == ((uint8)
    RCF_DrvOffsetCal_E)) && (rtb_TmpSignalConversionAtRP_SWC >
    CAL_RCF_nMinSkipAcc_f32));
  VAR_RCF_flgDefaultToFrewhlBwd_b = ((rtb_TmpSignalConversionAtRP_S_i == ((uint8)
    RCF_goalOfsClbReq_E)) && (rtb_TmpSignalConversionAtRP_S_h == ((uint8)
    RCF_DrvOffsetCal_E)) && (rtb_TmpSignalConversionAtRP_S_l ==
    CAL_RCF_WithoutStatorCurrent_u8) && (rtb_TmpSignalConversionAtRP_SWC <
    -CAL_RCF_nMinSkipAcc_f32));
  rtb_TmpSignalConversionAtIVDP_R =
    Rte_IrvIRead_RE_SWC_RCF_10ms_IVDP_RCF_stEstAlRtrOfs();
  VAR_RCF_flgWaitToAcc_b = ((rtb_TmpSignalConversionAtRP_S_h == ((uint8)
    RCF_Drv_OffsetAcc_E)) && (rtb_TmpSignalConversionAtIVDP_R == ((uint8)
    RCF_EstAlOfsFinish_E)));
  rtb_TmpSignalConversionAtIVDP_f =
    Rte_IrvIRead_RE_SWC_RCF_10ms_IVDP_RCF_stOfsClbFrwhl();
  VAR_RCF_flgAccToClbFreFwd_b = ((rtb_TmpSignalConversionAtRP_S_l ==
    CAL_RCF_WithoutStatorCurrent_u8) && (rtb_TmpSignalConversionAtRP_SWC >=
    CAL_RCF_nAlRtrDesAcc_f32) && (rtb_TmpSignalConversionAtIVDP_f != ((uint8)
    RCF_OfsClbfishedSucd_E)));
  VAR_RCF_flgClbFreFwdToAcc_b =
    ((Rte_IrvIRead_RE_SWC_RCF_10ms_IVDP_RCF_stOfsFrwhlFwd() == ((uint8)
       RCF_FishdSucdClbFwd_E)) && (rtb_TmpSignalConversionAtRP_SWC <
      CAL_RCF_nExtClbFrewhlFwd_f32));
  VAR_RCF_flgAccToClbFreBwd_b = ((rtb_TmpSignalConversionAtRP_S_l ==
    CAL_RCF_WithoutStatorCurrent_u8) && (rtb_TmpSignalConversionAtRP_SWC <=
    -CAL_RCF_nAlRtrDesAcc_f32) && (rtb_TmpSignalConversionAtIVDP_f != ((uint8)
    RCF_OfsClbfishedSucd_E)));
  VAR_RCF_flgBwClbSucdToAcc_b = ((rtb_TmpSignalConversionAtIVDP_f == ((uint8)
    RCF_OfsClbfishedSucd_E)) && (rtb_TmpSignalConversionAtRP_SWC >=
    CAL_RCF_nExtClbFrewhlBwd_f32));
  VAR_RCF_flgSucdToDefault_b = ((rtb_TmpSignalConversionAtRP_S_i != ((uint8)
    RCF_goalOfsClbReq_E)) && CAL_RCF_SuccdToDefault_b &&
    (VAR_RCF_flgDefaultToWait_b_tmp < CAL_RCF_nLimitSucToDef_f32));
  VAR_RCF_flgFwdorBwdToDefault_b = ((rtb_TmpSignalConversionAtRP_S_i != ((uint8)
    RCF_goalOfsClbReq_E)) && (rtb_TmpSignalConversionAtRP_S_h != ((uint8)
    RCF_Drv_OffsetFw_E)));
  VAR_RCF_flgAccToDefault_b = ((rtb_TmpSignalConversionAtRP_S_i != ((uint8)
    RCF_goalOfsClbReq_E)) && (rtb_TmpSignalConversionAtRP_S_h != ((uint8)
    RCF_Drv_OffsetAcc_E)));
  VAR_RCF_flgFailToDefault_b = (rtb_TmpSignalConversionAtRP_S_i != ((uint8)
    RCF_goalOfsClbReq_E));
  VAR_RCF_flgWaitToFail_b = (rtb_TmpSignalConversionAtIVDP_R == ((uint8)
    RCF_EstAlOfsFail_E));
  VAR_RCF_flgPsiToFail_b = (rtb_TmpSignalConversionAtRP_S_l !=
    CAL_RCF_WithoutStatorCurrent_u8);
  VAR_RCF_flgClbToFail_b = (rtb_TmpSignalConversionAtIVDP_f == ((uint8)
    RCF_OfsClbfishedFaild_E));
  VAR_RCF_flgAccToSucd_b = ((rtb_TmpSignalConversionAtIVDP_f == ((uint8)
    RCF_OfsClbfishedSucd_E)) && (rtb_TmpSignalConversionAtRP_S_l ==
    CAL_RCF_WithoutStatorCurrent_u8) && (rtb_TmpSignalConversionAtRP_SWC >=
    CAL_RCF_nMinSuccessStp_f32));
  if (SWC_RCF_DW.is_active_c1_SWC_RCF == 0U) {
    SWC_RCF_DW.is_active_c1_SWC_RCF = 1U;
    SWC_RCF_DW.is_c1_SWC_RCF = SWC_RCF_IN_DefaultState_p;
    SWC_enter_internal_DefaultState();
  } else {
    guard1 = false;
    guard2 = false;
    guard3 = false;
    switch (SWC_RCF_DW.is_c1_SWC_RCF) {
     case SWC_RCF_IN_Acceleration:
      if (VAR_RCF_flgAccToDefault_b) {
        SWC_RCF_DW.is_c1_SWC_RCF = SWC_RCF_IN_DefaultState_p;
        SWC_enter_internal_DefaultState();
      } else {
        tmp = SWC_RCF_DW.RCF_cntDurAccState + 1;
        if (tmp > 65535) {
          tmp = 65535;
        }

        SWC_RCF_DW.RCF_cntDurAccState = (uint16)tmp;
        if (VAR_RCF_flgAccToSucd_b) {
          VAR_RCF_TrqEmDesOfsClb_f32 = 0.0F;
          VAR_RCF_cTrqSlpOfsClb_f32 = 1.0F;
          VAR_RCF_flgEnblOfsClbFrwhl_b = false;
          VAR_RCF_flgEnblOfsClbFrwhlBwd_b = false;
          VAR_RCF_flgEnblOfsClbFrwhlFwd_b = false;
          SWC_RCF_DW.is_c1_SWC_RCF = SWC_RCF_IN_SucceedState;
          VAR_RCF_stDiagOfsClb_u8 = ((uint8)RCF_OfsClb_SuccessfulTested_E);
          VAR_RCF_stAgRtrOfsCal_u8 = ((uint8)RCF_OfsClb_FrewhlStp_E);
        } else if (VAR_RCF_flgAccToClbFreFwd_b) {
          VAR_RCF_TrqEmDesOfsClb_f32 = 0.0F;
          VAR_RCF_cTrqSlpOfsClb_f32 = 1.0F;
          SWC_RCF_DW.is_c1_SWC_RCF = SWC_RCF_IN_AlRtrOfsClbFrewhlFW;
          VAR_RCF_stAgRtrOfsCal_u8 = ((uint8)RCF_OfsClb_FrewhlFwd_E);
          SWC_RCF_DW.RCF_cntDurFrewhlClbFwdState = 0U;
          VAR_RCF_flgEnblOfsClbFrwhlFwd_b = true;
          VAR_RCF_flgEnblOfsClbFrwhl_b = true;
        } else if (VAR_RCF_flgAccToClbFreBwd_b) {
          VAR_RCF_TrqEmDesOfsClb_f32 = 0.0F;
          VAR_RCF_cTrqSlpOfsClb_f32 = 1.0F;
          SWC_RCF_DW.is_c1_SWC_RCF = SWC_RCF_IN_AlRtrOfsClbFrewhlBW;
          VAR_RCF_stAgRtrOfsCal_u8 = ((uint8)RCF_OfsClb_FrewhlBwd_E);
          SWC_RCF_DW.RCF_cntDurFrewhlClbBwdState = 0U;
          VAR_RCF_flgEnblOfsClbFrwhlBwd_b = true;
          VAR_RCF_flgEnblOfsClbFrwhl_b = true;
        } else if (SWC_RCF_DW.RCF_cntDurAccState > CAL_RCF_tMaxAcc_u16) {
          VAR_RCF_stDiagOfsClb_u8 = ((uint8)RCF_OfsClb_OverTimeAccFail_E);
          guard1 = true;
        } else {
          if (VAR_RCF_flgPsiToFail_b) {
            VAR_RCF_stDiagOfsClb_u8 = ((uint8)RCF_OfsClb_FrwhlNotPossibleFail_E);
            guard1 = true;
          }
        }
      }
      break;

     case SWC_RCF_IN_AlRtrOfsClbFrewhlBW:
      if (VAR_RCF_flgFwdorBwdToDefault_b) {
        SWC_RCF_DW.is_c1_SWC_RCF = SWC_RCF_IN_DefaultState_p;
        SWC_enter_internal_DefaultState();
      } else {
        tmp = SWC_RCF_DW.RCF_cntDurFrewhlClbBwdState + 1;
        if (tmp > 65535) {
          tmp = 65535;
        }

        SWC_RCF_DW.RCF_cntDurFrewhlClbBwdState = (uint16)tmp;
        if (VAR_RCF_flgPsiToFail_b) {
          VAR_RCF_stDiagOfsClb_u8 = ((uint8)RCF_OfsClb_FrwhlNotPossibleFail_E);
          guard2 = true;
        } else if (SWC_RCF_DW.RCF_cntDurFrewhlClbFwdState >
                   CAL_RCF_tMaxFwlFwd_u16) {
          VAR_RCF_stDiagOfsClb_u8 = ((uint8)RCF_OfsClb_OverTimeFrwhlFwdFail_E);
          guard2 = true;
        } else if (SWC_RCF_DW.RCF_cntDurFrewhlClbBwdState >
                   CAL_RCF_tMaxFwlBwd_u16) {
          VAR_RCF_stDiagOfsClb_u8 = ((uint8)RCF_OfsClb_OverTimeFrwhlBwdFail_E);
          guard2 = true;
        } else if (VAR_RCF_flgClbToFail_b) {
          VAR_RCF_stDiagOfsClb_u8 = ((uint8)RCF_OfsClb_AlRtrOfsPlausFail_E);
          guard2 = true;
        } else {
          if (VAR_RCF_flgBwClbSucdToAcc_b) {
            SWC_RCF_DW.RCF_flgOfsClbFrwhl_Fwd = 0U;
            VAR_RCF_flgEnblOfsClbFrwhlBwd_b = false;
            SWC_RCF_DW.is_c1_SWC_RCF = SWC_RCF_IN_Acceleration;
            VAR_RCF_stAgRtrOfsCal_u8 = ((uint8)RCF_OfsClb_Acceleration_E);
            VAR_RCF_cTrqSlpOfsClb_f32 = CAL_RCF_cTrqSlopAcc_f32;
            SWC_RCF_DW.RCF_cntDurAccState = 0U;
            VAR_RCF_flgEnblOfsClbFrwhl_b = true;
            if (SWC_RCF_DW.RCF_flgOfsClbFrwhl_Fwd == 0) {
              VAR_RCF_TrqEmDesOfsClb_f32 = CAL_RCF_TrqDesAcc_f32;
            } else {
              VAR_RCF_TrqEmDesOfsClb_f32 = -CAL_RCF_TrqDesAcc_f32;
            }
          }
        }
      }
      break;

     case SWC_RCF_IN_AlRtrOfsClbFrewhlFW:
      if (VAR_RCF_flgFwdorBwdToDefault_b) {
        SWC_RCF_DW.is_c1_SWC_RCF = SWC_RCF_IN_DefaultState_p;
        SWC_enter_internal_DefaultState();
      } else if (VAR_RCF_flgClbFreFwdToAcc_b) {
        SWC_RCF_DW.RCF_flgOfsClbFrwhl_Fwd = 1U;
        VAR_RCF_flgEnblOfsClbFrwhlFwd_b = false;
        SWC_RCF_DW.is_c1_SWC_RCF = SWC_RCF_IN_Acceleration;
        VAR_RCF_stAgRtrOfsCal_u8 = ((uint8)RCF_OfsClb_Acceleration_E);
        VAR_RCF_cTrqSlpOfsClb_f32 = CAL_RCF_cTrqSlopAcc_f32;
        SWC_RCF_DW.RCF_cntDurAccState = 0U;
        VAR_RCF_flgEnblOfsClbFrwhl_b = true;
        if (SWC_RCF_DW.RCF_flgOfsClbFrwhl_Fwd == 0) {
          VAR_RCF_TrqEmDesOfsClb_f32 = CAL_RCF_TrqDesAcc_f32;
        } else {
          VAR_RCF_TrqEmDesOfsClb_f32 = -CAL_RCF_TrqDesAcc_f32;
        }
      } else {
        tmp = SWC_RCF_DW.RCF_cntDurFrewhlClbFwdState + 1;
        if (tmp > 65535) {
          tmp = 65535;
        }

        SWC_RCF_DW.RCF_cntDurFrewhlClbFwdState = (uint16)tmp;
        if (VAR_RCF_flgPsiToFail_b) {
          VAR_RCF_stDiagOfsClb_u8 = ((uint8)RCF_OfsClb_FrwhlNotPossibleFail_E);
          guard3 = true;
        } else if (SWC_RCF_DW.RCF_cntDurFrewhlClbFwdState >
                   CAL_RCF_tMaxFwlFwd_u16) {
          VAR_RCF_stDiagOfsClb_u8 = ((uint8)RCF_OfsClb_OverTimeFrwhlFwdFail_E);
          guard3 = true;
        } else if (SWC_RCF_DW.RCF_cntDurFrewhlClbBwdState >
                   CAL_RCF_tMaxFwlBwd_u16) {
          VAR_RCF_stDiagOfsClb_u8 = ((uint8)RCF_OfsClb_OverTimeFrwhlBwdFail_E);
          guard3 = true;
        } else {
          if (VAR_RCF_flgClbToFail_b) {
            VAR_RCF_stDiagOfsClb_u8 = ((uint8)RCF_OfsClb_AlRtrOfsPlausFail_E);
            guard3 = true;
          }
        }
      }
      break;

     case SWC_RCF_IN_DefaultState_p:
      if (VAR_RCF_flgDefaultToClbFreFwd_b) {
        SWC_RCF_DW.is_c1_SWC_RCF = SWC_RCF_IN_AlRtrOfsClbFrewhlFW;
        VAR_RCF_stAgRtrOfsCal_u8 = ((uint8)RCF_OfsClb_FrewhlFwd_E);
        SWC_RCF_DW.RCF_cntDurFrewhlClbFwdState = 0U;
        VAR_RCF_flgEnblOfsClbFrwhlFwd_b = true;
        VAR_RCF_flgEnblOfsClbFrwhl_b = true;
      } else if (VAR_RCF_flgDefaultToFrewhlBwd_b &&
                 (SWC_RCF_DW.RCF_flgOfsClbFrwhl_Fwd == 1)) {
        SWC_RCF_DW.is_c1_SWC_RCF = SWC_RCF_IN_AlRtrOfsClbFrewhlBW;
        VAR_RCF_stAgRtrOfsCal_u8 = ((uint8)RCF_OfsClb_FrewhlBwd_E);
        SWC_RCF_DW.RCF_cntDurFrewhlClbBwdState = 0U;
        VAR_RCF_flgEnblOfsClbFrwhlBwd_b = true;
        VAR_RCF_flgEnblOfsClbFrwhl_b = true;
      } else {
        if (VAR_RCF_flgDefaultToWait_b) {
          VAR_RCF_flgEnblEstAlRtrOfs_b = true;
          SWC_RCF_DW.is_c1_SWC_RCF = SWC_RCF_IN_Wait;
        }
      }
      break;

     case SWC_RCF_IN_FailState_g:
      if (VAR_RCF_flgFailToDefault_b) {
        SWC_RCF_DW.is_c1_SWC_RCF = SWC_RCF_IN_DefaultState_p;
        SWC_enter_internal_DefaultState();
      }
      break;

     case SWC_RCF_IN_SucceedState:
      if (VAR_RCF_flgSucdToDefault_b) {
        SWC_RCF_DW.is_c1_SWC_RCF = SWC_RCF_IN_DefaultState_p;
        SWC_enter_internal_DefaultState();
      }
      break;

     default:
      if (VAR_RCF_flgFailToDefault_b) {
        SWC_RCF_DW.is_c1_SWC_RCF = SWC_RCF_IN_DefaultState_p;
        SWC_enter_internal_DefaultState();
      } else if (VAR_RCF_flgWaitToFail_b) {
        VAR_RCF_stDiagOfsClb_u8 = ((uint8)RCF_OfsClb_EstAlOfsFailed_E);
        SWC_RCF_DW.is_c1_SWC_RCF = SWC_RCF_IN_FailState_g;
        SWC_RC_enter_internal_FailState();
      } else {
        if (VAR_RCF_flgWaitToAcc_b) {
          VAR_RCF_flgEnblEstAlRtrOfs_b = false;
          SWC_RCF_DW.RCF_flgOfsClbFrwhl_Fwd = 0U;
          SWC_RCF_DW.is_c1_SWC_RCF = SWC_RCF_IN_Acceleration;
          VAR_RCF_stAgRtrOfsCal_u8 = ((uint8)RCF_OfsClb_Acceleration_E);
          VAR_RCF_cTrqSlpOfsClb_f32 = CAL_RCF_cTrqSlopAcc_f32;
          SWC_RCF_DW.RCF_cntDurAccState = 0U;
          VAR_RCF_flgEnblOfsClbFrwhl_b = true;
          if (SWC_RCF_DW.RCF_flgOfsClbFrwhl_Fwd == 0) {
            VAR_RCF_TrqEmDesOfsClb_f32 = CAL_RCF_TrqDesAcc_f32;
          } else {
            VAR_RCF_TrqEmDesOfsClb_f32 = -CAL_RCF_TrqDesAcc_f32;
          }
        }
      }
      break;
    }

    if (guard3) {
      SWC_RCF_DW.is_c1_SWC_RCF = SWC_RCF_IN_FailState_g;
      SWC_RC_enter_internal_FailState();
    }

    if (guard2) {
      SWC_RCF_DW.is_c1_SWC_RCF = SWC_RCF_IN_FailState_g;
      SWC_RC_enter_internal_FailState();
    }

    if (guard1) {
      SWC_RCF_DW.is_c1_SWC_RCF = SWC_RCF_IN_FailState_g;
      SWC_RC_enter_internal_FailState();
    }
  }

  Rte_IrvIWrite_RE_SWC_RCF_10ms_IVDP_RCF_flgEnblEstAlRtrOfs
    (VAR_RCF_flgEnblEstAlRtrOfs_b);
  Rte_IrvIWrite_RE_SWC_RCF_10ms_IVDP_RCF_flgEnblOfsClbFrwhlFwd
    (VAR_RCF_flgEnblOfsClbFrwhlFwd_b);
  Rte_IrvIWrite_RE_SWC_RCF_10ms_IVDP_RCF_flgEnblOfsClbFrwhlBwd
    (VAR_RCF_flgEnblOfsClbFrwhlBwd_b);
  Rte_IrvIWrite_RE_SWC_RCF_10ms_IVDP_RCF_flgEnblOfsClbFrwhl
    (VAR_RCF_flgEnblOfsClbFrwhl_b);
  SWC_RCF_DW.UnitDelay_DSTATE_b = VAR_RCF_stDiagOfsClb_u8;
  if (SWC_RCF_DW.UnitDelay_DSTATE_b == 2) {
    rtb_TmpSignalConversionAtRP_S_i = 3U;
  } else {
    rtb_TmpSignalConversionAtRP_S_i = 2U;
  }

  Rte_Call_RP_SWC_DEM_RCF_AccOvTiErr_SetEventStatus
    (rtb_TmpSignalConversionAtRP_S_i);
  if (SWC_RCF_DW.UnitDelay_DSTATE_b == 7) {
    rtb_TmpSignalConversionAtRP_S_i = 3U;
  } else {
    rtb_TmpSignalConversionAtRP_S_i = 2U;
  }

  Rte_Call_RP_SWC_DEM_RCF_EstOfsErr_SetEventStatus
    (rtb_TmpSignalConversionAtRP_S_i);
  if (SWC_RCF_DW.UnitDelay_DSTATE_b == 5) {
    rtb_TmpSignalConversionAtRP_S_i = 3U;
  } else {
    rtb_TmpSignalConversionAtRP_S_i = 2U;
  }

  Rte_Call_RP_SWC_DEM_RCF_FwlBwdOvTiErr_SetEventStatus
    (rtb_TmpSignalConversionAtRP_S_i);
  if (SWC_RCF_DW.UnitDelay_DSTATE_b == 4) {
    rtb_TmpSignalConversionAtRP_S_i = 3U;
  } else {
    rtb_TmpSignalConversionAtRP_S_i = 2U;
  }

  Rte_Call_RP_SWC_DEM_RCF_FwlFwdOvTiErr_SetEventStatus
    (rtb_TmpSignalConversionAtRP_S_i);
  if (SWC_RCF_DW.UnitDelay_DSTATE_b == 6) {
    rtb_TmpSignalConversionAtRP_S_i = 3U;
  } else {
    rtb_TmpSignalConversionAtRP_S_i = 2U;
  }

  Rte_Call_RP_SWC_DEM_RCF_OfsClbFailErr_SetEventStatus
    (rtb_TmpSignalConversionAtRP_S_i);
  if (SWC_RCF_DW.UnitDelay_DSTATE_b == 3) {
    rtb_TmpSignalConversionAtRP_S_i = 3U;
  } else {
    rtb_TmpSignalConversionAtRP_S_i = 2U;
  }

  Rte_Call_RP_SWC_DEM_RCF_PsiOvErr_SetEventStatus
    (rtb_TmpSignalConversionAtRP_S_i);
  (void) Rte_Write_PP_SWC_RCF_RCF_TrqEmDesOfsClb(VAR_RCF_TrqEmDesOfsClb_f32);
  (void) Rte_Write_PP_SWC_RCF_RCF_cTrqSlpOfsClb(VAR_RCF_cTrqSlpOfsClb_f32);
  (void) Rte_Write_PP_SWC_RCF_RCF_flgOfsClbSuc(Switch6);
  (void) Rte_Write_PP_SWC_RCF_RCF_stAgRtrOfsCal(VAR_RCF_stAgRtrOfsCal_u8);
}

void SWC_RCF_Init(void)
{
}
