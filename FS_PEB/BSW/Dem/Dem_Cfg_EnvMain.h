/*
***********************************************************************************************************************
* 
* Product Info
* Isolar version: ISOLAR-AB 4.0.2
* Product release version: RTA-BSW 3.1.0
* 
***********************************************************************************************************************
*/

/********************************************************************************************************************/
/*                                                                                                                  */
/* TOOL-GENERATED SOURCECODE, DO NOT CHANGE                                                                         */
/*                                                                                                                  */
/********************************************************************************************************************/

#ifndef DEM_CFG_ENVMAIN_H
#define DEM_CFG_ENVMAIN_H

/* min number of bytes required for storing any eventIds ExtendedData and one FreezeFrame (=> EvBuff) */
#define DEM_CFG_ENVMINSIZE_OF_RAWENVDATA           (23u + 0u)

/* min number of bytes required for storing any eventIds ExtendedData and multiple FreezeFrame (=> EvMem) */
#define DEM_CFG_ENVMINSIZE_OF_MULTIPLE_RAWENVDATA   (23u + 0u)

#define DEM_CFG_ENVEVENTID2ENVDATA \
{ \
   { 0u,0u }                                                      /* DEM_EVENTID_INVALID */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* ADC_UPhaseBISTFail */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* ADC_VPhaseBISTFail */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* ADC_WPhaseBISTFail */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* CANSM_E_BUS_OFF_NETWORK_0 */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* CANSM_E_BUS_OFF_NETWORK_1 */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* Can_Timeout */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* Cpld_AliveChkErr */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* Cpld_DI_ExdClk_InFail */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* Cpld_ExdClkInFail */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* Cpld_IphaOC */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* Cpld_NEN_InFail */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* Cpld_ParityChkErr */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* Cpld_Rx_SelfTest_Fail */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* Cpld_SPIComFail */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* Cpld_SZTKT_InFail */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* Cpld_Short_Circuit_HS_InFail */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* Cpld_Short_Circuit_LS_InFail */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* Cpld_UdcOverVolFail */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* Cpld_UnderVol_HS_InFail */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* Cpld_UnderVol_LS_InFail */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* Epark_OverCurFail */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* Epark_PosMonSampFail */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* Epark_PosSampFail */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* Epark_SampFail */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, DEM_FREEZEFRAME_SET1_FREEZE }  /* Event_NvM_ReadErr */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, DEM_FREEZEFRAME_SET1_FREEZE }  /* Event_NvM_WriteErr */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* FR_StorageErr */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* HSPF_InvOpenErr */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* HSPF_MotorOpenErr */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* HSPF_VerMatchFailureErr */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* HSPF_stIphaOffCalFail */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* HSPF_tDBCTempCmpErr */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* HvMcu_ComErr */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* HvMcu_DisChrgDutyErr */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* HvMcu_DisChrgFail */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* HvMcu_DisChrgFreqErr */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* HvMcu_EmerPowerSapErr */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* HvMcu_UartCheckFailErr */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* HvMcu_UartLostFrameErr */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* HvMcu_UdcCheckErr */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* HvMcu_UdcOverFlagLimit */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* HvMcu_UdcOverVolErr */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* IOHWAB_12VNarrSampErr */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* IOHWAB_12VSampErr */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* IOHWAB_12VWideSampErr */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* IOHWAB_18VLwBrgSampFail */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* IOHWAB_18VUpBrgSampFail */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* IOHWAB_1V3MCU_SampFail */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* IOHWAB_3V3MCU_SampFail */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* IOHWAB_5VQcoSampFail */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* IOHWAB_5VQt1SampFail */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* IOHWAB_5VQt2SampFail */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* IOHWAB_Cpld1v8SampFail */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* IOHWAB_Cpld3v3SampFail */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* IOHWAB_CrashFail */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* IOHWAB_DcLnkOverVolFail */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* IOHWAB_IphaOCFail */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* IOHWAB_KL30OverVolErr */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* IOHWAB_KL30SevOverVolFail */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* IOHWAB_KL30SevUnderVolFail */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* IOHWAB_KL30UnderVolErr */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* IOHWAB_Nen33Fail */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* IOHWAB_SttrSenorShrFail */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* IOHWAB_SttrTemp1SampFail */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* IOHWAB_SttrTemp2SampFail */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* IOHWAB_TCoolantSampFail */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* IOHWAB_VDD5_D_SampFail */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* IgbtDrv_ComErr */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* IgbtDrv_LwBrgFaultAFail */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* IgbtDrv_LwBrgFaultBFail */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* IgbtDrv_UpBrgFaultAFail */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* IgbtDrv_UpBrgFaultBFail */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* MDF_AlOfsNoPlausErr */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* MDF_DiashCirNoPsblErr */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* MDF_EmacBlkdErr */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* MDF_EmacBlkdWarn */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* MDF_ICtlRatErr */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* MDF_IsOvHiErr */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* MDF_OpenCirNoPsblErr */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* MDF_OperOutdRngErr */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* MDF_PhaseLossFaultErr */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* MDF_PrfElDrvErr */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* PCF_ActOvTiErr */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* PCF_IdcOvErr */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* PCF_SelfcheckErr */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* PCF_SenClbErr */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* PCF_SenOvErr */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* PCF_StallRetryErr */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* PCF_StallWarn */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* PCF_UnexpPosErr */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* RCF_AccOvTiErr */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* RCF_EstOfsErr */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* RCF_FwlBwdOvTiErr */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* RCF_FwlFwdOvTiErr */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* RCF_OfsClbFail */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* RCF_PsiOvErr */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* RSL_DOSErr */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* RSL_ExcErr */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* RSL_LOSErr */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* RSL_LOTErr */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* SCF_DisChgOvTiFail */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* SCF_LowPwrShtDwnOvTiFail */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* SCF_RunToDischarErr */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* TPC_SpdOvHiLimFail */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* TPC_SpdOvHiWarn */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* TPC_TCoolantOvHiWarn */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* TPC_TDbcOvHiWarn */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* TPC_TDbcOvLoWarn */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* TPC_TDbcUHiLimFail */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* TPC_TDbcULoLimFail */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* TPC_TDbcVHiLimFail */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* TPC_TDbcVLoLimFail */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* TPC_TDbcWHiLimFail */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* TPC_TDbcWLoLimFail */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* TPC_TDrvBoardOvHiWarn */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* TPC_TIGBTOvHiLimErr */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* TPC_TIGBTOvHiWarn */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* TPC_TIGBTOvLoWarn */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* TPC_TSttrOvHiLimFail */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* TPC_TSttrOvHiWarn */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* TPC_TSttrOvLoWarn */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* TPC_iDcLnkOvCLimFail */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* TPC_iDcLnkOvcWarn */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* TPC_uDcLnkOvVLimFail */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* TPC_uDcLnkOvWarn */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* TPC_uDcLnkUnVLimFail */ \
   ,{  DEM_EXTDATA_DEM_DCM_06_EXTERN, 0u }                         /* TPC_uDcLnkUnvWarn */ \
}

#endif

