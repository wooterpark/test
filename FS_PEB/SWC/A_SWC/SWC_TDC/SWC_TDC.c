#include "SWC_TDC.h"
#include "SWC_TDC_private.h"
#include "look1_iflf_binlxpw.h"

float32 VAR_TDC_trqRmp_f32;

#pragma section ".rodata.Calib_32"

const volatile float32 CAL_TDC_DeltaT_f32 = 0.002F;
const volatile float32 CAL_TDC_KiNCtl_Y_Af32[10] = { 0.31F, 0.31F, 0.31F, 0.31F,
  0.31F, 0.4F, 0.63F, 0.63F, 0.64F, 0.64F } ;

const volatile float32 CAL_TDC_KpNCtl_Y_Af32[10] = { 0.05F, 0.05F, 0.05F, 0.05F,
  0.05F, 0.055F, 0.063F, 0.063F, 0.063F, 0.064F } ;

const volatile float32 CAL_TDC_n_Error_X_Af32[10] = { 0.0F, 100.0F, 300.0F,
  400.0F, 500.0F, 700.0F, 1000.0F, 1500.0F, 2000.0F, 3000.0F } ;

const volatile float32 CAL_TDC_trqIncMax_f32 = 20.0F;

#pragma section

DW_SWC_TDC_T SWC_TDC_DW;
void SWC_TDC_10ms(void)
{
  uint8 tmpRead;
  uint8 tmpRead_0;
  float32 rtb_tdc_xDevSpd;
  float32 rtb_Abs;
  float32 rtb_tdc_TrqPiIncMax;
  float32 rtb_TmpSignalConversionAtRP_SWC;
  float32 rtb_Subtract_d;
  float32 rtb_TmpSignalConversionAtRP_S_l;
  float32 rtb_tdc_KpNCtl;
  float32 rtb_tdc_TrqPiIncMin;
  Rte_Read_RP_SWC_Rdc_Rdc_nWoFlt(&rtb_tdc_xDevSpd);
  Rte_Read_RP_SWC_VCF_VCF_stModeReq(&tmpRead);
  Rte_Read_RP_SWC_VCF_VCF_NsetPReq(&rtb_tdc_TrqPiIncMax);
  rtb_tdc_xDevSpd = rtb_tdc_TrqPiIncMax - rtb_tdc_xDevSpd;
  rtb_Abs = fabsf(rtb_tdc_xDevSpd);
  if (tmpRead == ((uint8)CAL_TDC_go_nCtlExtReq_u8)) {
    Rte_Read_RP_SWC_VCF_VCF_KpNCtl(&rtb_tdc_KpNCtl);
  } else {
    rtb_tdc_KpNCtl = look1_iflf_binlxpw(rtb_Abs, ((const float32 *)
      &(CAL_TDC_n_Error_X_Af32[0])), ((const float32 *)&(CAL_TDC_KpNCtl_Y_Af32[0])),
      9U);
  }

  Rte_Read_RP_SWC_SCF_SCF_stModeReqToTdc(&tmpRead_0);
  if (tmpRead_0 == 1) {
    Rte_Read_RP_SWC_VCF_VCF_TrqDes(&SWC_TDC_DW.UnitDelay_DSTATE);
    rtb_tdc_TrqPiIncMax = 0.0F;
    rtb_tdc_TrqPiIncMin = 0.0F;
    rtb_tdc_xDevSpd = 0.0F;
    rtb_tdc_KpNCtl = 0.0F;
    rtb_Abs = 0.0F;
  } else if (tmpRead_0 == 2) {
    rtb_tdc_TrqPiIncMax = CAL_TDC_trqIncMax_f32;
    rtb_tdc_TrqPiIncMin = -CAL_TDC_trqIncMax_f32;
    rtb_Abs = look1_iflf_binlxpw(rtb_Abs, ((const float32 *)
      &(CAL_TDC_n_Error_X_Af32[0])), ((const float32 *)&(CAL_TDC_KiNCtl_Y_Af32[0])),
      9U) * CAL_TDC_DeltaT_f32;
  } else {
    rtb_tdc_TrqPiIncMax = 0.0F;
    rtb_tdc_TrqPiIncMin = 0.0F;
    rtb_tdc_xDevSpd = 0.0F;
    rtb_tdc_KpNCtl = 0.0F;
    rtb_Abs = 0.0F;
    SWC_TDC_DW.UnitDelay_DSTATE = 0.0F;
  }

  rtb_tdc_KpNCtl = (rtb_tdc_xDevSpd - SWC_TDC_DW.UnitDelay_DSTATE_c) *
    rtb_tdc_KpNCtl + rtb_Abs * rtb_tdc_xDevSpd;
  Rte_Read_RP_SWC_VCF_VCF_HoldStartTrq(&rtb_Subtract_d);
  if (rtb_tdc_KpNCtl > rtb_tdc_TrqPiIncMax) {
    rtb_tdc_KpNCtl = rtb_tdc_TrqPiIncMax;
  } else {
    if (rtb_tdc_KpNCtl < rtb_tdc_TrqPiIncMin) {
      rtb_tdc_KpNCtl = rtb_tdc_TrqPiIncMin;
    }
  }

  rtb_tdc_KpNCtl = (rtb_tdc_KpNCtl + SWC_TDC_DW.UnitDelay_DSTATE) +
    rtb_Subtract_d;
  Rte_Read_RP_SWC_TPC_TPC_TrqMax(&rtb_TmpSignalConversionAtRP_SWC);
  Rte_Read_RP_SWC_TPC_TPC_TrqMin(&rtb_TmpSignalConversionAtRP_S_l);
  if (rtb_tdc_KpNCtl > rtb_TmpSignalConversionAtRP_SWC) {
    SWC_TDC_DW.UnitDelay_DSTATE = rtb_TmpSignalConversionAtRP_SWC;
  } else if (rtb_tdc_KpNCtl < rtb_TmpSignalConversionAtRP_S_l) {
    SWC_TDC_DW.UnitDelay_DSTATE = rtb_TmpSignalConversionAtRP_S_l;
  } else {
    SWC_TDC_DW.UnitDelay_DSTATE = rtb_tdc_KpNCtl;
  }

  Rte_Read_RP_SWC_VCF_VCF_trqRamp(&VAR_TDC_trqRmp_f32);
  rtb_Subtract_d = SWC_TDC_DW.UnitDelay_DSTATE - SWC_TDC_DW.UnitDelay2_DSTATE;
  if (rtb_Subtract_d <= VAR_TDC_trqRmp_f32) {
    if (-rtb_Subtract_d > VAR_TDC_trqRmp_f32) {
      SWC_TDC_DW.UnitDelay_DSTATE = SWC_TDC_DW.UnitDelay2_DSTATE -
        VAR_TDC_trqRmp_f32;
    }
  } else {
    SWC_TDC_DW.UnitDelay_DSTATE = VAR_TDC_trqRmp_f32 +
      SWC_TDC_DW.UnitDelay2_DSTATE;
  }

  (void) Rte_Write_PP_SWC_TDC_TDC_flgTrqLmtActv((rtb_tdc_KpNCtl >
    rtb_TmpSignalConversionAtRP_SWC) || (rtb_tdc_KpNCtl <
    rtb_TmpSignalConversionAtRP_S_l));
  SWC_TDC_DW.UnitDelay_DSTATE_c = rtb_tdc_xDevSpd;
  SWC_TDC_DW.UnitDelay2_DSTATE = SWC_TDC_DW.UnitDelay_DSTATE;
  (void) Rte_Write_PP_SWC_TDC_TDC_TrqDes(SWC_TDC_DW.UnitDelay_DSTATE);
}

void SWC_TDC_Init(void)
{
}
