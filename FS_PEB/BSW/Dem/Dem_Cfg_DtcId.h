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

#ifndef DEM_CFG_DTCID_H
#define DEM_CFG_DTCID_H

#include "Dem_Cfg_EventId.h"

#define DEM_CFG_EVCOMB_DISABLED       1u
#define DEM_CFG_EVCOMB_ONSTORAGE      2u
#define DEM_CFG_EVCOMB_ONRETRIEVAL    3u
#define DEM_CFG_EVCOMB            DEM_CFG_EVCOMB_ONSTORAGE

#define DEM_DTCID_INVALID           0u
#define DEM_DTCID_COUNT             80u
#define DEM_DTCID_ARRAYLENGTH       (DEM_DTCID_COUNT+1u)

#define DemConf_DemDTCClass_DemDTC_Can_Timeout                       1u
#define DemConf_DemDTCClass_DemDTC_CANSM_E_BUS_OFF_NETWORK           2u
#define DemConf_DemDTCClass_DemDTC_ADC_UVWPhaseBISTFail              3u
#define DemConf_DemDTCClass_DemDTC_Cpld_Fault                        4u
#define DemConf_DemDTCClass_DemDTC_Epark_OverCurFail                 5u
#define DemConf_DemDTCClass_DemDTC_Epark_PosSampFail                 6u
#define DemConf_DemDTCClass_DemDTC_Epark_SampFail                    7u
#define DemConf_DemDTCClass_DemDTC_Event_NvM_ReadErr                 8u
#define DemConf_DemDTCClass_DemDTC_Event_NvM_WriteErr                9u
#define DemConf_DemDTCClass_DemDTC_FR_StorageErr                     10u
#define DemConf_DemDTCClass_DemDTC_HSPF_Fault                        11u
#define DemConf_DemDTCClass_DemDTC_HSPF_VerMatchFailureErr           12u
#define DemConf_DemDTCClass_DemDTC_HvMcu_Fault                       13u
#define DemConf_DemDTCClass_DemDTC_IgbtDrv_Fault                     14u
#define DemConf_DemDTCClass_DemDTC_IOHWAB_VSampFault                 15u
#define DemConf_DemDTCClass_DemDTC_IOHWAB_Nen33Fail                  16u
#define DemConf_DemDTCClass_DemDTC_IOHWAB_CrashFail                  17u
#define DemConf_DemDTCClass_DemDTC_IOHWAB_DcLnkOverVolFail           18u
#define DemConf_DemDTCClass_DemDTC_IOHWAB_IphaOCFail                 19u
#define DemConf_DemDTCClass_DemDTC_IOHWAB_SttrSenorShrFail           20u
#define DemConf_DemDTCClass_DemDTC_IOHWAB_SttrTempSampFail           21u
#define DemConf_DemDTCClass_DemDTC_IOHWAB_TCoolantSampFail           22u
#define DemConf_DemDTCClass_DemDTC_IOHWAB_KL30OVolFault              23u
#define DemConf_DemDTCClass_DemDTC_MDF_AlOfsNoPlausErr               24u
#define DemConf_DemDTCClass_DemDTC_MDF_DiashCirNoPsblErr             25u
#define DemConf_DemDTCClass_DemDTC_MDF_EmacBlkdErr                   26u
#define DemConf_DemDTCClass_DemDTC_MDF_EmacBlkdWarn                  27u
#define DemConf_DemDTCClass_DemDTC_MDF_ICtlRatErr                    28u
#define DemConf_DemDTCClass_DemDTC_MDF_IsOvHiErr                     29u
#define DemConf_DemDTCClass_DemDTC_MDF_OpenCirNoPsblErr              30u
#define DemConf_DemDTCClass_DemDTC_MDF_OperOutdRngErr                31u
#define DemConf_DemDTCClass_DemDTC_MDF_PhaseLossFaultErr             32u
#define DemConf_DemDTCClass_DemDTC_MDF_PrfElDrvErr                   33u
#define DemConf_DemDTCClass_DemDTC_PCF_ActOvTiErr                    34u
#define DemConf_DemDTCClass_DemDTC_PCF_IdcOvErr                      35u
#define DemConf_DemDTCClass_DemDTC_PCF_SelfcheckErr                  36u
#define DemConf_DemDTCClass_DemDTC_PCF_SenClbErr                     37u
#define DemConf_DemDTCClass_DemDTC_PCF_SenOvErr                      38u
#define DemConf_DemDTCClass_DemDTC_PCF_StallRetryErr                 39u
#define DemConf_DemDTCClass_DemDTC_PCF_StallWarn                     40u
#define DemConf_DemDTCClass_DemDTC_PCF_UnexpPosErr                   41u
#define DemConf_DemDTCClass_DemDTC_RCF_AccOvTiErr                    42u
#define DemConf_DemDTCClass_DemDTC_RCF_EstOfsErr                     43u
#define DemConf_DemDTCClass_DemDTC_RCF_FwlBwdOvTiErr                 44u
#define DemConf_DemDTCClass_DemDTC_RCF_FwlFwdOvTiErr                 45u
#define DemConf_DemDTCClass_DemDTC_RCF_OfsClbFail                    46u
#define DemConf_DemDTCClass_DemDTC_RCF_PsiOvErr                      47u
#define DemConf_DemDTCClass_DemDTC_RSL_DOSErr                        48u
#define DemConf_DemDTCClass_DemDTC_RSL_ExcFaultErr                   49u
#define DemConf_DemDTCClass_DemDTC_RSL_LOSErr                        50u
#define DemConf_DemDTCClass_DemDTC_RSL_LOTErr                        51u
#define DemConf_DemDTCClass_DemDTC_SCF_DisChgOvTiFail                52u
#define DemConf_DemDTCClass_DemDTC_SCF_LowPwrShtDwnOvTiFail          53u
#define DemConf_DemDTCClass_DemDTC_SCF_RunToDischarErr               54u
#define DemConf_DemDTCClass_DemDTC_TPC_iDcLnkOvCLimFail              55u
#define DemConf_DemDTCClass_DemDTC_TPC_iDcLnkOvcWarn                 56u
#define DemConf_DemDTCClass_DemDTC_TPC_SpdOvHiLimFail                57u
#define DemConf_DemDTCClass_DemDTC_TPC_SpdOvHiWarn                   58u
#define DemConf_DemDTCClass_DemDTC_TPC_TCoolantOvHiWarn              59u
#define DemConf_DemDTCClass_DemDTC_TPC_TDbcOvHiWarn                  60u
#define DemConf_DemDTCClass_DemDTC_TPC_TDbcOvLoWarn                  61u
#define DemConf_DemDTCClass_DemDTC_TPC_TDbcUHiLimFail                62u
#define DemConf_DemDTCClass_DemDTC_TPC_TDbcULoLimFail                63u
#define DemConf_DemDTCClass_DemDTC_TPC_TDbcVHiLimFail                64u
#define DemConf_DemDTCClass_DemDTC_TPC_TDbcVLoLimFail                65u
#define DemConf_DemDTCClass_DemDTC_TPC_TDbcWHiLimFail                66u
#define DemConf_DemDTCClass_DemDTC_TPC_TDbcWLoLimFail                67u
#define DemConf_DemDTCClass_DemDTC_TPC_TDrvBoardOvHiWarn             68u
#define DemConf_DemDTCClass_DemDTC_TPC_TIGBTOvHiLimErr               69u
#define DemConf_DemDTCClass_DemDTC_TPC_TIGBTOvHiWarn                 70u
#define DemConf_DemDTCClass_DemDTC_TPC_TIGBTOvLoWarn                 71u
#define DemConf_DemDTCClass_DemDTC_TPC_TSttrOvHiLimFail              72u
#define DemConf_DemDTCClass_DemDTC_TPC_TSttrOvHiWarn                 73u
#define DemConf_DemDTCClass_DemDTC_TPC_TSttrOvLoWarn                 74u
#define DemConf_DemDTCClass_DemDTC_TPC_uDcLnkOvVLimFail              75u
#define DemConf_DemDTCClass_DemDTC_TPC_uDcLnkOvWarn                  76u
#define DemConf_DemDTCClass_DemDTC_TPC_uDcLnkUnVLimFail              77u
#define DemConf_DemDTCClass_DemDTC_TPC_uDcLnkUnvWarn                 78u
#define DemConf_DemDTCClass_DemDTC_Cpld_Rx_SelfTest_Fail             79u
#define DemConf_DemDTCClass_DemDTC_HvMcu_UdcOverFlagLimit            80u

#define DEM_DTCGROUPID_INVALID           0u
#define DEM_DTCGROUPID_COUNT             1u
#define DEM_DTCGROUPID_ARRAYLENGTH       (DEM_DTCGROUPID_COUNT+1u)

// genInfo: for (EvCombination==OFF) the explicit mapping from dtcid to eventId is necessary, because an event may not be assigned to any DTC
#define  DEM_MAP_EVENTID_DTCID   \
const Dem_DtcIdType Dem_MapEventIdToDtcId[DEM_EVENTID_ARRAYLENGTH] = \
{ \
   DEM_DTCID_INVALID \
   ,DemConf_DemDTCClass_DemDTC_ADC_UVWPhaseBISTFail  /* ADC_UPhaseBISTFail */ \
   ,DemConf_DemDTCClass_DemDTC_ADC_UVWPhaseBISTFail  /* ADC_VPhaseBISTFail */ \
   ,DemConf_DemDTCClass_DemDTC_ADC_UVWPhaseBISTFail  /* ADC_WPhaseBISTFail */ \
   ,DemConf_DemDTCClass_DemDTC_CANSM_E_BUS_OFF_NETWORK  /* CANSM_E_BUS_OFF_NETWORK_0 */ \
   ,DemConf_DemDTCClass_DemDTC_CANSM_E_BUS_OFF_NETWORK  /* CANSM_E_BUS_OFF_NETWORK_1 */ \
   ,DemConf_DemDTCClass_DemDTC_Can_Timeout  /* Can_Timeout */ \
   ,DemConf_DemDTCClass_DemDTC_Cpld_Fault   /* Cpld_AliveChkErr */ \
   ,DemConf_DemDTCClass_DemDTC_Cpld_Fault   /* Cpld_DI_ExdClk_InFail */ \
   ,DemConf_DemDTCClass_DemDTC_Cpld_Fault   /* Cpld_ExdClkInFail */ \
   ,DemConf_DemDTCClass_DemDTC_Cpld_Fault   /* Cpld_IphaOC */ \
   ,DemConf_DemDTCClass_DemDTC_Cpld_Fault   /* Cpld_NEN_InFail */ \
   ,DemConf_DemDTCClass_DemDTC_Cpld_Fault   /* Cpld_ParityChkErr */ \
   ,DemConf_DemDTCClass_DemDTC_Cpld_Rx_SelfTest_Fail  /* Cpld_Rx_SelfTest_Fail */ \
   ,DemConf_DemDTCClass_DemDTC_Cpld_Fault   /* Cpld_SPIComFail */ \
   ,DemConf_DemDTCClass_DemDTC_Cpld_Fault   /* Cpld_SZTKT_InFail */ \
   ,DemConf_DemDTCClass_DemDTC_Cpld_Fault   /* Cpld_Short_Circuit_HS_InFail */ \
   ,DemConf_DemDTCClass_DemDTC_Cpld_Fault   /* Cpld_Short_Circuit_LS_InFail */ \
   ,DemConf_DemDTCClass_DemDTC_Cpld_Fault   /* Cpld_UdcOverVolFail */ \
   ,DemConf_DemDTCClass_DemDTC_Cpld_Fault   /* Cpld_UnderVol_HS_InFail */ \
   ,DemConf_DemDTCClass_DemDTC_Cpld_Fault   /* Cpld_UnderVol_LS_InFail */ \
   ,DemConf_DemDTCClass_DemDTC_Epark_OverCurFail  /* Epark_OverCurFail */ \
   ,DemConf_DemDTCClass_DemDTC_Epark_PosSampFail  /* Epark_PosMonSampFail */ \
   ,DemConf_DemDTCClass_DemDTC_Epark_PosSampFail  /* Epark_PosSampFail */ \
   ,DemConf_DemDTCClass_DemDTC_Epark_SampFail  /* Epark_SampFail */ \
   ,DemConf_DemDTCClass_DemDTC_Event_NvM_ReadErr  /* Event_NvM_ReadErr */ \
   ,DemConf_DemDTCClass_DemDTC_Event_NvM_WriteErr  /* Event_NvM_WriteErr */ \
   ,DemConf_DemDTCClass_DemDTC_FR_StorageErr  /* FR_StorageErr */ \
   ,DemConf_DemDTCClass_DemDTC_HSPF_Fault   /* HSPF_InvOpenErr */ \
   ,DemConf_DemDTCClass_DemDTC_HSPF_Fault   /* HSPF_MotorOpenErr */ \
   ,DemConf_DemDTCClass_DemDTC_HSPF_VerMatchFailureErr  /* HSPF_VerMatchFailureErr */ \
   ,DemConf_DemDTCClass_DemDTC_HSPF_Fault   /* HSPF_stIphaOffCalFail */ \
   ,DemConf_DemDTCClass_DemDTC_HSPF_Fault   /* HSPF_tDBCTempCmpErr */ \
   ,DemConf_DemDTCClass_DemDTC_HvMcu_Fault  /* HvMcu_ComErr */ \
   ,DemConf_DemDTCClass_DemDTC_HvMcu_Fault  /* HvMcu_DisChrgDutyErr */ \
   ,DemConf_DemDTCClass_DemDTC_HvMcu_Fault  /* HvMcu_DisChrgFail */ \
   ,DemConf_DemDTCClass_DemDTC_HvMcu_Fault  /* HvMcu_DisChrgFreqErr */ \
   ,DemConf_DemDTCClass_DemDTC_HvMcu_Fault  /* HvMcu_EmerPowerSapErr */ \
   ,DemConf_DemDTCClass_DemDTC_HvMcu_Fault  /* HvMcu_UartCheckFailErr */ \
   ,DemConf_DemDTCClass_DemDTC_HvMcu_Fault  /* HvMcu_UartLostFrameErr */ \
   ,DemConf_DemDTCClass_DemDTC_HvMcu_Fault  /* HvMcu_UdcCheckErr */ \
   ,DemConf_DemDTCClass_DemDTC_HvMcu_UdcOverFlagLimit  /* HvMcu_UdcOverFlagLimit */ \
   ,DemConf_DemDTCClass_DemDTC_HvMcu_Fault  /* HvMcu_UdcOverVolErr */ \
   ,DemConf_DemDTCClass_DemDTC_IOHWAB_VSampFault  /* IOHWAB_12VNarrSampErr */ \
   ,DemConf_DemDTCClass_DemDTC_IOHWAB_VSampFault  /* IOHWAB_12VSampErr */ \
   ,DemConf_DemDTCClass_DemDTC_IOHWAB_VSampFault  /* IOHWAB_12VWideSampErr */ \
   ,DemConf_DemDTCClass_DemDTC_IOHWAB_VSampFault  /* IOHWAB_18VLwBrgSampFail */ \
   ,DemConf_DemDTCClass_DemDTC_IOHWAB_VSampFault  /* IOHWAB_18VUpBrgSampFail */ \
   ,DemConf_DemDTCClass_DemDTC_IOHWAB_VSampFault  /* IOHWAB_1V3MCU_SampFail */ \
   ,DemConf_DemDTCClass_DemDTC_IOHWAB_VSampFault  /* IOHWAB_3V3MCU_SampFail */ \
   ,DemConf_DemDTCClass_DemDTC_IOHWAB_VSampFault  /* IOHWAB_5VQcoSampFail */ \
   ,DemConf_DemDTCClass_DemDTC_IOHWAB_VSampFault  /* IOHWAB_5VQt1SampFail */ \
   ,DemConf_DemDTCClass_DemDTC_IOHWAB_VSampFault  /* IOHWAB_5VQt2SampFail */ \
   ,DemConf_DemDTCClass_DemDTC_IOHWAB_VSampFault  /* IOHWAB_Cpld1v8SampFail */ \
   ,DemConf_DemDTCClass_DemDTC_IOHWAB_VSampFault  /* IOHWAB_Cpld3v3SampFail */ \
   ,DemConf_DemDTCClass_DemDTC_IOHWAB_CrashFail  /* IOHWAB_CrashFail */ \
   ,DemConf_DemDTCClass_DemDTC_IOHWAB_DcLnkOverVolFail  /* IOHWAB_DcLnkOverVolFail */ \
   ,DemConf_DemDTCClass_DemDTC_IOHWAB_IphaOCFail  /* IOHWAB_IphaOCFail */ \
   ,DemConf_DemDTCClass_DemDTC_IOHWAB_KL30OVolFault  /* IOHWAB_KL30OverVolErr */ \
   ,DemConf_DemDTCClass_DemDTC_IOHWAB_KL30OVolFault  /* IOHWAB_KL30SevOverVolFail */ \
   ,DemConf_DemDTCClass_DemDTC_IOHWAB_KL30OVolFault  /* IOHWAB_KL30SevUnderVolFail */ \
   ,DemConf_DemDTCClass_DemDTC_IOHWAB_KL30OVolFault  /* IOHWAB_KL30UnderVolErr */ \
   ,DemConf_DemDTCClass_DemDTC_IOHWAB_Nen33Fail  /* IOHWAB_Nen33Fail */ \
   ,DemConf_DemDTCClass_DemDTC_IOHWAB_SttrSenorShrFail  /* IOHWAB_SttrSenorShrFail */ \
   ,DemConf_DemDTCClass_DemDTC_IOHWAB_SttrTempSampFail  /* IOHWAB_SttrTemp1SampFail */ \
   ,DemConf_DemDTCClass_DemDTC_IOHWAB_SttrTempSampFail  /* IOHWAB_SttrTemp2SampFail */ \
   ,DemConf_DemDTCClass_DemDTC_IOHWAB_TCoolantSampFail  /* IOHWAB_TCoolantSampFail */ \
   ,DemConf_DemDTCClass_DemDTC_IOHWAB_VSampFault  /* IOHWAB_VDD5_D_SampFail */ \
   ,DemConf_DemDTCClass_DemDTC_IgbtDrv_Fault  /* IgbtDrv_ComErr */ \
   ,DemConf_DemDTCClass_DemDTC_IgbtDrv_Fault  /* IgbtDrv_LwBrgFaultAFail */ \
   ,DemConf_DemDTCClass_DemDTC_IgbtDrv_Fault  /* IgbtDrv_LwBrgFaultBFail */ \
   ,DemConf_DemDTCClass_DemDTC_IgbtDrv_Fault  /* IgbtDrv_UpBrgFaultAFail */ \
   ,DemConf_DemDTCClass_DemDTC_IgbtDrv_Fault  /* IgbtDrv_UpBrgFaultBFail */ \
   ,DemConf_DemDTCClass_DemDTC_MDF_AlOfsNoPlausErr  /* MDF_AlOfsNoPlausErr */ \
   ,DemConf_DemDTCClass_DemDTC_MDF_DiashCirNoPsblErr  /* MDF_DiashCirNoPsblErr */ \
   ,DemConf_DemDTCClass_DemDTC_MDF_EmacBlkdErr  /* MDF_EmacBlkdErr */ \
   ,DemConf_DemDTCClass_DemDTC_MDF_EmacBlkdWarn  /* MDF_EmacBlkdWarn */ \
   ,DemConf_DemDTCClass_DemDTC_MDF_ICtlRatErr  /* MDF_ICtlRatErr */ \
   ,DemConf_DemDTCClass_DemDTC_MDF_IsOvHiErr  /* MDF_IsOvHiErr */ \
   ,DemConf_DemDTCClass_DemDTC_MDF_OpenCirNoPsblErr  /* MDF_OpenCirNoPsblErr */ \
   ,DemConf_DemDTCClass_DemDTC_MDF_OperOutdRngErr  /* MDF_OperOutdRngErr */ \
   ,DemConf_DemDTCClass_DemDTC_MDF_PhaseLossFaultErr  /* MDF_PhaseLossFaultErr */ \
   ,DemConf_DemDTCClass_DemDTC_MDF_PrfElDrvErr  /* MDF_PrfElDrvErr */ \
   ,DemConf_DemDTCClass_DemDTC_PCF_ActOvTiErr  /* PCF_ActOvTiErr */ \
   ,DemConf_DemDTCClass_DemDTC_PCF_IdcOvErr  /* PCF_IdcOvErr */ \
   ,DemConf_DemDTCClass_DemDTC_PCF_SelfcheckErr  /* PCF_SelfcheckErr */ \
   ,DemConf_DemDTCClass_DemDTC_PCF_SenClbErr  /* PCF_SenClbErr */ \
   ,DemConf_DemDTCClass_DemDTC_PCF_SenOvErr  /* PCF_SenOvErr */ \
   ,DemConf_DemDTCClass_DemDTC_PCF_StallRetryErr  /* PCF_StallRetryErr */ \
   ,DemConf_DemDTCClass_DemDTC_PCF_StallWarn  /* PCF_StallWarn */ \
   ,DemConf_DemDTCClass_DemDTC_PCF_UnexpPosErr  /* PCF_UnexpPosErr */ \
   ,DemConf_DemDTCClass_DemDTC_RCF_AccOvTiErr  /* RCF_AccOvTiErr */ \
   ,DemConf_DemDTCClass_DemDTC_RCF_EstOfsErr  /* RCF_EstOfsErr */ \
   ,DemConf_DemDTCClass_DemDTC_RCF_FwlBwdOvTiErr  /* RCF_FwlBwdOvTiErr */ \
   ,DemConf_DemDTCClass_DemDTC_RCF_FwlFwdOvTiErr  /* RCF_FwlFwdOvTiErr */ \
   ,DemConf_DemDTCClass_DemDTC_RCF_OfsClbFail  /* RCF_OfsClbFail */ \
   ,DemConf_DemDTCClass_DemDTC_RCF_PsiOvErr  /* RCF_PsiOvErr */ \
   ,DemConf_DemDTCClass_DemDTC_RSL_DOSErr   /* RSL_DOSErr */ \
   ,DemConf_DemDTCClass_DemDTC_RSL_ExcFaultErr  /* RSL_ExcErr */ \
   ,DemConf_DemDTCClass_DemDTC_RSL_LOSErr   /* RSL_LOSErr */ \
   ,DemConf_DemDTCClass_DemDTC_RSL_LOTErr   /* RSL_LOTErr */ \
   ,DemConf_DemDTCClass_DemDTC_SCF_DisChgOvTiFail  /* SCF_DisChgOvTiFail */ \
   ,DemConf_DemDTCClass_DemDTC_SCF_LowPwrShtDwnOvTiFail  /* SCF_LowPwrShtDwnOvTiFail */ \
   ,DemConf_DemDTCClass_DemDTC_SCF_RunToDischarErr  /* SCF_RunToDischarErr */ \
   ,DemConf_DemDTCClass_DemDTC_TPC_SpdOvHiLimFail  /* TPC_SpdOvHiLimFail */ \
   ,DemConf_DemDTCClass_DemDTC_TPC_SpdOvHiWarn  /* TPC_SpdOvHiWarn */ \
   ,DemConf_DemDTCClass_DemDTC_TPC_TCoolantOvHiWarn  /* TPC_TCoolantOvHiWarn */ \
   ,DemConf_DemDTCClass_DemDTC_TPC_TDbcOvHiWarn  /* TPC_TDbcOvHiWarn */ \
   ,DemConf_DemDTCClass_DemDTC_TPC_TDbcOvLoWarn  /* TPC_TDbcOvLoWarn */ \
   ,DemConf_DemDTCClass_DemDTC_TPC_TDbcUHiLimFail  /* TPC_TDbcUHiLimFail */ \
   ,DemConf_DemDTCClass_DemDTC_TPC_TDbcULoLimFail  /* TPC_TDbcULoLimFail */ \
   ,DemConf_DemDTCClass_DemDTC_TPC_TDbcVHiLimFail  /* TPC_TDbcVHiLimFail */ \
   ,DemConf_DemDTCClass_DemDTC_TPC_TDbcVLoLimFail  /* TPC_TDbcVLoLimFail */ \
   ,DemConf_DemDTCClass_DemDTC_TPC_TDbcWHiLimFail  /* TPC_TDbcWHiLimFail */ \
   ,DemConf_DemDTCClass_DemDTC_TPC_TDbcWLoLimFail  /* TPC_TDbcWLoLimFail */ \
   ,DemConf_DemDTCClass_DemDTC_TPC_TDrvBoardOvHiWarn  /* TPC_TDrvBoardOvHiWarn */ \
   ,DemConf_DemDTCClass_DemDTC_TPC_TIGBTOvHiLimErr  /* TPC_TIGBTOvHiLimErr */ \
   ,DemConf_DemDTCClass_DemDTC_TPC_TIGBTOvHiWarn  /* TPC_TIGBTOvHiWarn */ \
   ,DemConf_DemDTCClass_DemDTC_TPC_TIGBTOvLoWarn  /* TPC_TIGBTOvLoWarn */ \
   ,DemConf_DemDTCClass_DemDTC_TPC_TSttrOvHiLimFail  /* TPC_TSttrOvHiLimFail */ \
   ,DemConf_DemDTCClass_DemDTC_TPC_TSttrOvHiWarn  /* TPC_TSttrOvHiWarn */ \
   ,DemConf_DemDTCClass_DemDTC_TPC_TSttrOvLoWarn  /* TPC_TSttrOvLoWarn */ \
   ,DemConf_DemDTCClass_DemDTC_TPC_iDcLnkOvCLimFail  /* TPC_iDcLnkOvCLimFail */ \
   ,DemConf_DemDTCClass_DemDTC_TPC_iDcLnkOvcWarn  /* TPC_iDcLnkOvcWarn */ \
   ,DemConf_DemDTCClass_DemDTC_TPC_uDcLnkOvVLimFail  /* TPC_uDcLnkOvVLimFail */ \
   ,DemConf_DemDTCClass_DemDTC_TPC_uDcLnkOvWarn  /* TPC_uDcLnkOvWarn */ \
   ,DemConf_DemDTCClass_DemDTC_TPC_uDcLnkUnVLimFail  /* TPC_uDcLnkUnVLimFail */ \
   ,DemConf_DemDTCClass_DemDTC_TPC_uDcLnkUnvWarn  /* TPC_uDcLnkUnvWarn */ \
};

#define DEM_MAP_DTCGROUPID_DTCID \
{ {0u,0u}\
 ,{DemConf_DemDTCClass_DemDTC_Can_Timeout  , DemConf_DemDTCClass_DemDTC_HvMcu_UdcOverFlagLimit}	/* DEM_DTC_GROUP_ALL_DTCS */\
}

#if (DEM_CFG_EVCOMB == DEM_CFG_EVCOMB_DISABLED)

#define DEM_MAP_DTCID_EVENTID        \
const Dem_MapDtcIdToEventIdType  Dem_MapDtcIdToEventId[DEM_DTCID_ARRAYLENGTH] = \
{ \
   DEM_EVENTID_INVALID \
   ,DemConf_DemEventParameter_Can_Timeout /* DemDTC_Can_Timeout */ \
   ,DemConf_DemEventParameter_CANSM_E_BUS_OFF_NETWORK_0 /* DemDTC_CANSM_E_BUS_OFF_NETWORK */ \
   ,DemConf_DemEventParameter_ADC_UPhaseBISTFail /* DemDTC_ADC_UVWPhaseBISTFail */ \
   ,DemConf_DemEventParameter_Cpld_AliveChkErr /* DemDTC_Cpld_Fault */ \
   ,DemConf_DemEventParameter_Epark_OverCurFail /* DemDTC_Epark_OverCurFail */ \
   ,DemConf_DemEventParameter_Epark_PosMonSampFail /* DemDTC_Epark_PosSampFail */ \
   ,DemConf_DemEventParameter_Epark_SampFail /* DemDTC_Epark_SampFail */ \
   ,DemConf_DemEventParameter_Event_NvM_ReadErr /* DemDTC_Event_NvM_ReadErr */ \
   ,DemConf_DemEventParameter_Event_NvM_WriteErr /* DemDTC_Event_NvM_WriteErr */ \
   ,DemConf_DemEventParameter_FR_StorageErr /* DemDTC_FR_StorageErr */ \
   ,DemConf_DemEventParameter_HSPF_InvOpenErr /* DemDTC_HSPF_Fault */ \
   ,DemConf_DemEventParameter_HSPF_VerMatchFailureErr /* DemDTC_HSPF_VerMatchFailureErr */ \
   ,DemConf_DemEventParameter_HvMcu_ComErr /* DemDTC_HvMcu_Fault */ \
   ,DemConf_DemEventParameter_IgbtDrv_ComErr /* DemDTC_IgbtDrv_Fault */ \
   ,DemConf_DemEventParameter_IOHWAB_12VNarrSampErr /* DemDTC_IOHWAB_VSampFault */ \
   ,DemConf_DemEventParameter_IOHWAB_Nen33Fail /* DemDTC_IOHWAB_Nen33Fail */ \
   ,DemConf_DemEventParameter_IOHWAB_CrashFail /* DemDTC_IOHWAB_CrashFail */ \
   ,DemConf_DemEventParameter_IOHWAB_DcLnkOverVolFail /* DemDTC_IOHWAB_DcLnkOverVolFail */ \
   ,DemConf_DemEventParameter_IOHWAB_IphaOCFail /* DemDTC_IOHWAB_IphaOCFail */ \
   ,DemConf_DemEventParameter_IOHWAB_SttrSenorShrFail /* DemDTC_IOHWAB_SttrSenorShrFail */ \
   ,DemConf_DemEventParameter_IOHWAB_SttrTemp1SampFail /* DemDTC_IOHWAB_SttrTempSampFail */ \
   ,DemConf_DemEventParameter_IOHWAB_TCoolantSampFail /* DemDTC_IOHWAB_TCoolantSampFail */ \
   ,DemConf_DemEventParameter_IOHWAB_KL30OverVolErr /* DemDTC_IOHWAB_KL30OVolFault */ \
   ,DemConf_DemEventParameter_MDF_AlOfsNoPlausErr /* DemDTC_MDF_AlOfsNoPlausErr */ \
   ,DemConf_DemEventParameter_MDF_DiashCirNoPsblErr /* DemDTC_MDF_DiashCirNoPsblErr */ \
   ,DemConf_DemEventParameter_MDF_EmacBlkdErr /* DemDTC_MDF_EmacBlkdErr */ \
   ,DemConf_DemEventParameter_MDF_EmacBlkdWarn /* DemDTC_MDF_EmacBlkdWarn */ \
   ,DemConf_DemEventParameter_MDF_ICtlRatErr /* DemDTC_MDF_ICtlRatErr */ \
   ,DemConf_DemEventParameter_MDF_IsOvHiErr /* DemDTC_MDF_IsOvHiErr */ \
   ,DemConf_DemEventParameter_MDF_OpenCirNoPsblErr /* DemDTC_MDF_OpenCirNoPsblErr */ \
   ,DemConf_DemEventParameter_MDF_OperOutdRngErr /* DemDTC_MDF_OperOutdRngErr */ \
   ,DemConf_DemEventParameter_MDF_PhaseLossFaultErr /* DemDTC_MDF_PhaseLossFaultErr */ \
   ,DemConf_DemEventParameter_MDF_PrfElDrvErr /* DemDTC_MDF_PrfElDrvErr */ \
   ,DemConf_DemEventParameter_PCF_ActOvTiErr /* DemDTC_PCF_ActOvTiErr */ \
   ,DemConf_DemEventParameter_PCF_IdcOvErr /* DemDTC_PCF_IdcOvErr */ \
   ,DemConf_DemEventParameter_PCF_SelfcheckErr /* DemDTC_PCF_SelfcheckErr */ \
   ,DemConf_DemEventParameter_PCF_SenClbErr /* DemDTC_PCF_SenClbErr */ \
   ,DemConf_DemEventParameter_PCF_SenOvErr /* DemDTC_PCF_SenOvErr */ \
   ,DemConf_DemEventParameter_PCF_StallRetryErr /* DemDTC_PCF_StallRetryErr */ \
   ,DemConf_DemEventParameter_PCF_StallWarn /* DemDTC_PCF_StallWarn */ \
   ,DemConf_DemEventParameter_PCF_UnexpPosErr /* DemDTC_PCF_UnexpPosErr */ \
   ,DemConf_DemEventParameter_RCF_AccOvTiErr /* DemDTC_RCF_AccOvTiErr */ \
   ,DemConf_DemEventParameter_RCF_EstOfsErr /* DemDTC_RCF_EstOfsErr */ \
   ,DemConf_DemEventParameter_RCF_FwlBwdOvTiErr /* DemDTC_RCF_FwlBwdOvTiErr */ \
   ,DemConf_DemEventParameter_RCF_FwlFwdOvTiErr /* DemDTC_RCF_FwlFwdOvTiErr */ \
   ,DemConf_DemEventParameter_RCF_OfsClbFail /* DemDTC_RCF_OfsClbFail */ \
   ,DemConf_DemEventParameter_RCF_PsiOvErr /* DemDTC_RCF_PsiOvErr */ \
   ,DemConf_DemEventParameter_RSL_DOSErr /* DemDTC_RSL_DOSErr */ \
   ,DemConf_DemEventParameter_RSL_ExcErr /* DemDTC_RSL_ExcFaultErr */ \
   ,DemConf_DemEventParameter_RSL_LOSErr /* DemDTC_RSL_LOSErr */ \
   ,DemConf_DemEventParameter_RSL_LOTErr /* DemDTC_RSL_LOTErr */ \
   ,DemConf_DemEventParameter_SCF_DisChgOvTiFail /* DemDTC_SCF_DisChgOvTiFail */ \
   ,DemConf_DemEventParameter_SCF_LowPwrShtDwnOvTiFail /* DemDTC_SCF_LowPwrShtDwnOvTiFail */ \
   ,DemConf_DemEventParameter_SCF_RunToDischarErr /* DemDTC_SCF_RunToDischarErr */ \
   ,DemConf_DemEventParameter_TPC_iDcLnkOvCLimFail /* DemDTC_TPC_iDcLnkOvCLimFail */ \
   ,DemConf_DemEventParameter_TPC_iDcLnkOvcWarn /* DemDTC_TPC_iDcLnkOvcWarn */ \
   ,DemConf_DemEventParameter_TPC_SpdOvHiLimFail /* DemDTC_TPC_SpdOvHiLimFail */ \
   ,DemConf_DemEventParameter_TPC_SpdOvHiWarn /* DemDTC_TPC_SpdOvHiWarn */ \
   ,DemConf_DemEventParameter_TPC_TCoolantOvHiWarn /* DemDTC_TPC_TCoolantOvHiWarn */ \
   ,DemConf_DemEventParameter_TPC_TDbcOvHiWarn /* DemDTC_TPC_TDbcOvHiWarn */ \
   ,DemConf_DemEventParameter_TPC_TDbcOvLoWarn /* DemDTC_TPC_TDbcOvLoWarn */ \
   ,DemConf_DemEventParameter_TPC_TDbcUHiLimFail /* DemDTC_TPC_TDbcUHiLimFail */ \
   ,DemConf_DemEventParameter_TPC_TDbcULoLimFail /* DemDTC_TPC_TDbcULoLimFail */ \
   ,DemConf_DemEventParameter_TPC_TDbcVHiLimFail /* DemDTC_TPC_TDbcVHiLimFail */ \
   ,DemConf_DemEventParameter_TPC_TDbcVLoLimFail /* DemDTC_TPC_TDbcVLoLimFail */ \
   ,DemConf_DemEventParameter_TPC_TDbcWHiLimFail /* DemDTC_TPC_TDbcWHiLimFail */ \
   ,DemConf_DemEventParameter_TPC_TDbcWLoLimFail /* DemDTC_TPC_TDbcWLoLimFail */ \
   ,DemConf_DemEventParameter_TPC_TDrvBoardOvHiWarn /* DemDTC_TPC_TDrvBoardOvHiWarn */ \
   ,DemConf_DemEventParameter_TPC_TIGBTOvHiLimErr /* DemDTC_TPC_TIGBTOvHiLimErr */ \
   ,DemConf_DemEventParameter_TPC_TIGBTOvHiWarn /* DemDTC_TPC_TIGBTOvHiWarn */ \
   ,DemConf_DemEventParameter_TPC_TIGBTOvLoWarn /* DemDTC_TPC_TIGBTOvLoWarn */ \
   ,DemConf_DemEventParameter_TPC_TSttrOvHiLimFail /* DemDTC_TPC_TSttrOvHiLimFail */ \
   ,DemConf_DemEventParameter_TPC_TSttrOvHiWarn /* DemDTC_TPC_TSttrOvHiWarn */ \
   ,DemConf_DemEventParameter_TPC_TSttrOvLoWarn /* DemDTC_TPC_TSttrOvLoWarn */ \
   ,DemConf_DemEventParameter_TPC_uDcLnkOvVLimFail /* DemDTC_TPC_uDcLnkOvVLimFail */ \
   ,DemConf_DemEventParameter_TPC_uDcLnkOvWarn /* DemDTC_TPC_uDcLnkOvWarn */ \
   ,DemConf_DemEventParameter_TPC_uDcLnkUnVLimFail /* DemDTC_TPC_uDcLnkUnVLimFail */ \
   ,DemConf_DemEventParameter_TPC_uDcLnkUnvWarn /* DemDTC_TPC_uDcLnkUnvWarn */ \
   ,DemConf_DemEventParameter_Cpld_Rx_SelfTest_Fail /* DemDTC_Cpld_Rx_SelfTest_Fail */ \
   ,DemConf_DemEventParameter_HvMcu_UdcOverFlagLimit /* DemDTC_HvMcu_UdcOverFlagLimit */ \
};

#else

#define DEM_MAP_DTCID_EVENTID        \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_Can_Timeout[] = { \
   DemConf_DemEventParameter_Can_Timeout \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_CANSM_E_BUS_OFF_NETWORK[] = { \
   DemConf_DemEventParameter_CANSM_E_BUS_OFF_NETWORK_0 \
,   DemConf_DemEventParameter_CANSM_E_BUS_OFF_NETWORK_1 \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_ADC_UVWPhaseBISTFail[] = { \
   DemConf_DemEventParameter_ADC_UPhaseBISTFail \
,   DemConf_DemEventParameter_ADC_VPhaseBISTFail \
,   DemConf_DemEventParameter_ADC_WPhaseBISTFail \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_Cpld_Fault[] = { \
   DemConf_DemEventParameter_Cpld_AliveChkErr \
,   DemConf_DemEventParameter_Cpld_DI_ExdClk_InFail \
,   DemConf_DemEventParameter_Cpld_ExdClkInFail \
,   DemConf_DemEventParameter_Cpld_IphaOC \
,   DemConf_DemEventParameter_Cpld_NEN_InFail \
,   DemConf_DemEventParameter_Cpld_ParityChkErr \
,   DemConf_DemEventParameter_Cpld_SPIComFail \
,   DemConf_DemEventParameter_Cpld_SZTKT_InFail \
,   DemConf_DemEventParameter_Cpld_Short_Circuit_HS_InFail \
,   DemConf_DemEventParameter_Cpld_Short_Circuit_LS_InFail \
,   DemConf_DemEventParameter_Cpld_UdcOverVolFail \
,   DemConf_DemEventParameter_Cpld_UnderVol_HS_InFail \
,   DemConf_DemEventParameter_Cpld_UnderVol_LS_InFail \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_Epark_OverCurFail[] = { \
   DemConf_DemEventParameter_Epark_OverCurFail \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_Epark_PosSampFail[] = { \
   DemConf_DemEventParameter_Epark_PosMonSampFail \
,   DemConf_DemEventParameter_Epark_PosSampFail \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_Epark_SampFail[] = { \
   DemConf_DemEventParameter_Epark_SampFail \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_Event_NvM_ReadErr[] = { \
   DemConf_DemEventParameter_Event_NvM_ReadErr \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_Event_NvM_WriteErr[] = { \
   DemConf_DemEventParameter_Event_NvM_WriteErr \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_FR_StorageErr[] = { \
   DemConf_DemEventParameter_FR_StorageErr \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_HSPF_Fault[] = { \
   DemConf_DemEventParameter_HSPF_InvOpenErr \
,   DemConf_DemEventParameter_HSPF_MotorOpenErr \
,   DemConf_DemEventParameter_HSPF_stIphaOffCalFail \
,   DemConf_DemEventParameter_HSPF_tDBCTempCmpErr \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_HSPF_VerMatchFailureErr[] = { \
   DemConf_DemEventParameter_HSPF_VerMatchFailureErr \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_HvMcu_Fault[] = { \
   DemConf_DemEventParameter_HvMcu_ComErr \
,   DemConf_DemEventParameter_HvMcu_DisChrgDutyErr \
,   DemConf_DemEventParameter_HvMcu_DisChrgFail \
,   DemConf_DemEventParameter_HvMcu_DisChrgFreqErr \
,   DemConf_DemEventParameter_HvMcu_EmerPowerSapErr \
,   DemConf_DemEventParameter_HvMcu_UartCheckFailErr \
,   DemConf_DemEventParameter_HvMcu_UartLostFrameErr \
,   DemConf_DemEventParameter_HvMcu_UdcCheckErr \
,   DemConf_DemEventParameter_HvMcu_UdcOverVolErr \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_IgbtDrv_Fault[] = { \
   DemConf_DemEventParameter_IgbtDrv_ComErr \
,   DemConf_DemEventParameter_IgbtDrv_LwBrgFaultAFail \
,   DemConf_DemEventParameter_IgbtDrv_LwBrgFaultBFail \
,   DemConf_DemEventParameter_IgbtDrv_UpBrgFaultAFail \
,   DemConf_DemEventParameter_IgbtDrv_UpBrgFaultBFail \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_IOHWAB_VSampFault[] = { \
   DemConf_DemEventParameter_IOHWAB_12VNarrSampErr \
,   DemConf_DemEventParameter_IOHWAB_12VSampErr \
,   DemConf_DemEventParameter_IOHWAB_12VWideSampErr \
,   DemConf_DemEventParameter_IOHWAB_18VLwBrgSampFail \
,   DemConf_DemEventParameter_IOHWAB_18VUpBrgSampFail \
,   DemConf_DemEventParameter_IOHWAB_1V3MCU_SampFail \
,   DemConf_DemEventParameter_IOHWAB_3V3MCU_SampFail \
,   DemConf_DemEventParameter_IOHWAB_5VQcoSampFail \
,   DemConf_DemEventParameter_IOHWAB_5VQt1SampFail \
,   DemConf_DemEventParameter_IOHWAB_5VQt2SampFail \
,   DemConf_DemEventParameter_IOHWAB_Cpld1v8SampFail \
,   DemConf_DemEventParameter_IOHWAB_Cpld3v3SampFail \
,   DemConf_DemEventParameter_IOHWAB_VDD5_D_SampFail \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_IOHWAB_Nen33Fail[] = { \
   DemConf_DemEventParameter_IOHWAB_Nen33Fail \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_IOHWAB_CrashFail[] = { \
   DemConf_DemEventParameter_IOHWAB_CrashFail \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_IOHWAB_DcLnkOverVolFail[] = { \
   DemConf_DemEventParameter_IOHWAB_DcLnkOverVolFail \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_IOHWAB_IphaOCFail[] = { \
   DemConf_DemEventParameter_IOHWAB_IphaOCFail \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_IOHWAB_SttrSenorShrFail[] = { \
   DemConf_DemEventParameter_IOHWAB_SttrSenorShrFail \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_IOHWAB_SttrTempSampFail[] = { \
   DemConf_DemEventParameter_IOHWAB_SttrTemp1SampFail \
,   DemConf_DemEventParameter_IOHWAB_SttrTemp2SampFail \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_IOHWAB_TCoolantSampFail[] = { \
   DemConf_DemEventParameter_IOHWAB_TCoolantSampFail \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_IOHWAB_KL30OVolFault[] = { \
   DemConf_DemEventParameter_IOHWAB_KL30OverVolErr \
,   DemConf_DemEventParameter_IOHWAB_KL30SevOverVolFail \
,   DemConf_DemEventParameter_IOHWAB_KL30SevUnderVolFail \
,   DemConf_DemEventParameter_IOHWAB_KL30UnderVolErr \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_MDF_AlOfsNoPlausErr[] = { \
   DemConf_DemEventParameter_MDF_AlOfsNoPlausErr \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_MDF_DiashCirNoPsblErr[] = { \
   DemConf_DemEventParameter_MDF_DiashCirNoPsblErr \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_MDF_EmacBlkdErr[] = { \
   DemConf_DemEventParameter_MDF_EmacBlkdErr \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_MDF_EmacBlkdWarn[] = { \
   DemConf_DemEventParameter_MDF_EmacBlkdWarn \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_MDF_ICtlRatErr[] = { \
   DemConf_DemEventParameter_MDF_ICtlRatErr \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_MDF_IsOvHiErr[] = { \
   DemConf_DemEventParameter_MDF_IsOvHiErr \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_MDF_OpenCirNoPsblErr[] = { \
   DemConf_DemEventParameter_MDF_OpenCirNoPsblErr \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_MDF_OperOutdRngErr[] = { \
   DemConf_DemEventParameter_MDF_OperOutdRngErr \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_MDF_PhaseLossFaultErr[] = { \
   DemConf_DemEventParameter_MDF_PhaseLossFaultErr \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_MDF_PrfElDrvErr[] = { \
   DemConf_DemEventParameter_MDF_PrfElDrvErr \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_PCF_ActOvTiErr[] = { \
   DemConf_DemEventParameter_PCF_ActOvTiErr \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_PCF_IdcOvErr[] = { \
   DemConf_DemEventParameter_PCF_IdcOvErr \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_PCF_SelfcheckErr[] = { \
   DemConf_DemEventParameter_PCF_SelfcheckErr \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_PCF_SenClbErr[] = { \
   DemConf_DemEventParameter_PCF_SenClbErr \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_PCF_SenOvErr[] = { \
   DemConf_DemEventParameter_PCF_SenOvErr \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_PCF_StallRetryErr[] = { \
   DemConf_DemEventParameter_PCF_StallRetryErr \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_PCF_StallWarn[] = { \
   DemConf_DemEventParameter_PCF_StallWarn \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_PCF_UnexpPosErr[] = { \
   DemConf_DemEventParameter_PCF_UnexpPosErr \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_RCF_AccOvTiErr[] = { \
   DemConf_DemEventParameter_RCF_AccOvTiErr \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_RCF_EstOfsErr[] = { \
   DemConf_DemEventParameter_RCF_EstOfsErr \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_RCF_FwlBwdOvTiErr[] = { \
   DemConf_DemEventParameter_RCF_FwlBwdOvTiErr \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_RCF_FwlFwdOvTiErr[] = { \
   DemConf_DemEventParameter_RCF_FwlFwdOvTiErr \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_RCF_OfsClbFail[] = { \
   DemConf_DemEventParameter_RCF_OfsClbFail \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_RCF_PsiOvErr[] = { \
   DemConf_DemEventParameter_RCF_PsiOvErr \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_RSL_DOSErr[] = { \
   DemConf_DemEventParameter_RSL_DOSErr \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_RSL_ExcFaultErr[] = { \
   DemConf_DemEventParameter_RSL_ExcErr \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_RSL_LOSErr[] = { \
   DemConf_DemEventParameter_RSL_LOSErr \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_RSL_LOTErr[] = { \
   DemConf_DemEventParameter_RSL_LOTErr \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_SCF_DisChgOvTiFail[] = { \
   DemConf_DemEventParameter_SCF_DisChgOvTiFail \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_SCF_LowPwrShtDwnOvTiFail[] = { \
   DemConf_DemEventParameter_SCF_LowPwrShtDwnOvTiFail \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_SCF_RunToDischarErr[] = { \
   DemConf_DemEventParameter_SCF_RunToDischarErr \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_TPC_iDcLnkOvCLimFail[] = { \
   DemConf_DemEventParameter_TPC_iDcLnkOvCLimFail \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_TPC_iDcLnkOvcWarn[] = { \
   DemConf_DemEventParameter_TPC_iDcLnkOvcWarn \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_TPC_SpdOvHiLimFail[] = { \
   DemConf_DemEventParameter_TPC_SpdOvHiLimFail \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_TPC_SpdOvHiWarn[] = { \
   DemConf_DemEventParameter_TPC_SpdOvHiWarn \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_TPC_TCoolantOvHiWarn[] = { \
   DemConf_DemEventParameter_TPC_TCoolantOvHiWarn \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_TPC_TDbcOvHiWarn[] = { \
   DemConf_DemEventParameter_TPC_TDbcOvHiWarn \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_TPC_TDbcOvLoWarn[] = { \
   DemConf_DemEventParameter_TPC_TDbcOvLoWarn \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_TPC_TDbcUHiLimFail[] = { \
   DemConf_DemEventParameter_TPC_TDbcUHiLimFail \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_TPC_TDbcULoLimFail[] = { \
   DemConf_DemEventParameter_TPC_TDbcULoLimFail \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_TPC_TDbcVHiLimFail[] = { \
   DemConf_DemEventParameter_TPC_TDbcVHiLimFail \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_TPC_TDbcVLoLimFail[] = { \
   DemConf_DemEventParameter_TPC_TDbcVLoLimFail \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_TPC_TDbcWHiLimFail[] = { \
   DemConf_DemEventParameter_TPC_TDbcWHiLimFail \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_TPC_TDbcWLoLimFail[] = { \
   DemConf_DemEventParameter_TPC_TDbcWLoLimFail \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_TPC_TDrvBoardOvHiWarn[] = { \
   DemConf_DemEventParameter_TPC_TDrvBoardOvHiWarn \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_TPC_TIGBTOvHiLimErr[] = { \
   DemConf_DemEventParameter_TPC_TIGBTOvHiLimErr \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_TPC_TIGBTOvHiWarn[] = { \
   DemConf_DemEventParameter_TPC_TIGBTOvHiWarn \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_TPC_TIGBTOvLoWarn[] = { \
   DemConf_DemEventParameter_TPC_TIGBTOvLoWarn \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_TPC_TSttrOvHiLimFail[] = { \
   DemConf_DemEventParameter_TPC_TSttrOvHiLimFail \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_TPC_TSttrOvHiWarn[] = { \
   DemConf_DemEventParameter_TPC_TSttrOvHiWarn \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_TPC_TSttrOvLoWarn[] = { \
   DemConf_DemEventParameter_TPC_TSttrOvLoWarn \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_TPC_uDcLnkOvVLimFail[] = { \
   DemConf_DemEventParameter_TPC_uDcLnkOvVLimFail \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_TPC_uDcLnkOvWarn[] = { \
   DemConf_DemEventParameter_TPC_uDcLnkOvWarn \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_TPC_uDcLnkUnVLimFail[] = { \
   DemConf_DemEventParameter_TPC_uDcLnkUnVLimFail \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_TPC_uDcLnkUnvWarn[] = { \
   DemConf_DemEventParameter_TPC_uDcLnkUnvWarn \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_Cpld_Rx_SelfTest_Fail[] = { \
   DemConf_DemEventParameter_Cpld_Rx_SelfTest_Fail \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_HvMcu_UdcOverFlagLimit[] = { \
   DemConf_DemEventParameter_HvMcu_UdcOverFlagLimit \
}; \
 \
 \
 \
const Dem_MapDtcIdToEventIdType  Dem_MapDtcIdToEventId[DEM_DTCID_ARRAYLENGTH] = \
{ \
   { \
      NULL_PTR, \
      0u \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_Can_Timeout[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_Can_Timeout)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_Can_Timeout[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_CANSM_E_BUS_OFF_NETWORK[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_CANSM_E_BUS_OFF_NETWORK)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_CANSM_E_BUS_OFF_NETWORK[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_ADC_UVWPhaseBISTFail[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_ADC_UVWPhaseBISTFail)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_ADC_UVWPhaseBISTFail[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_Cpld_Fault[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_Cpld_Fault)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_Cpld_Fault[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_Epark_OverCurFail[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_Epark_OverCurFail)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_Epark_OverCurFail[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_Epark_PosSampFail[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_Epark_PosSampFail)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_Epark_PosSampFail[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_Epark_SampFail[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_Epark_SampFail)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_Epark_SampFail[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_Event_NvM_ReadErr[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_Event_NvM_ReadErr)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_Event_NvM_ReadErr[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_Event_NvM_WriteErr[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_Event_NvM_WriteErr)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_Event_NvM_WriteErr[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_FR_StorageErr[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_FR_StorageErr)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_FR_StorageErr[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_HSPF_Fault[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_HSPF_Fault)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_HSPF_Fault[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_HSPF_VerMatchFailureErr[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_HSPF_VerMatchFailureErr)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_HSPF_VerMatchFailureErr[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_HvMcu_Fault[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_HvMcu_Fault)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_HvMcu_Fault[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_IgbtDrv_Fault[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_IgbtDrv_Fault)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_IgbtDrv_Fault[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_IOHWAB_VSampFault[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_IOHWAB_VSampFault)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_IOHWAB_VSampFault[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_IOHWAB_Nen33Fail[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_IOHWAB_Nen33Fail)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_IOHWAB_Nen33Fail[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_IOHWAB_CrashFail[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_IOHWAB_CrashFail)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_IOHWAB_CrashFail[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_IOHWAB_DcLnkOverVolFail[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_IOHWAB_DcLnkOverVolFail)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_IOHWAB_DcLnkOverVolFail[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_IOHWAB_IphaOCFail[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_IOHWAB_IphaOCFail)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_IOHWAB_IphaOCFail[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_IOHWAB_SttrSenorShrFail[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_IOHWAB_SttrSenorShrFail)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_IOHWAB_SttrSenorShrFail[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_IOHWAB_SttrTempSampFail[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_IOHWAB_SttrTempSampFail)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_IOHWAB_SttrTempSampFail[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_IOHWAB_TCoolantSampFail[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_IOHWAB_TCoolantSampFail)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_IOHWAB_TCoolantSampFail[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_IOHWAB_KL30OVolFault[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_IOHWAB_KL30OVolFault)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_IOHWAB_KL30OVolFault[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_MDF_AlOfsNoPlausErr[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_MDF_AlOfsNoPlausErr)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_MDF_AlOfsNoPlausErr[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_MDF_DiashCirNoPsblErr[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_MDF_DiashCirNoPsblErr)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_MDF_DiashCirNoPsblErr[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_MDF_EmacBlkdErr[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_MDF_EmacBlkdErr)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_MDF_EmacBlkdErr[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_MDF_EmacBlkdWarn[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_MDF_EmacBlkdWarn)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_MDF_EmacBlkdWarn[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_MDF_ICtlRatErr[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_MDF_ICtlRatErr)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_MDF_ICtlRatErr[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_MDF_IsOvHiErr[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_MDF_IsOvHiErr)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_MDF_IsOvHiErr[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_MDF_OpenCirNoPsblErr[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_MDF_OpenCirNoPsblErr)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_MDF_OpenCirNoPsblErr[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_MDF_OperOutdRngErr[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_MDF_OperOutdRngErr)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_MDF_OperOutdRngErr[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_MDF_PhaseLossFaultErr[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_MDF_PhaseLossFaultErr)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_MDF_PhaseLossFaultErr[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_MDF_PrfElDrvErr[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_MDF_PrfElDrvErr)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_MDF_PrfElDrvErr[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_PCF_ActOvTiErr[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_PCF_ActOvTiErr)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_PCF_ActOvTiErr[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_PCF_IdcOvErr[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_PCF_IdcOvErr)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_PCF_IdcOvErr[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_PCF_SelfcheckErr[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_PCF_SelfcheckErr)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_PCF_SelfcheckErr[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_PCF_SenClbErr[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_PCF_SenClbErr)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_PCF_SenClbErr[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_PCF_SenOvErr[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_PCF_SenOvErr)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_PCF_SenOvErr[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_PCF_StallRetryErr[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_PCF_StallRetryErr)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_PCF_StallRetryErr[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_PCF_StallWarn[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_PCF_StallWarn)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_PCF_StallWarn[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_PCF_UnexpPosErr[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_PCF_UnexpPosErr)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_PCF_UnexpPosErr[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_RCF_AccOvTiErr[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_RCF_AccOvTiErr)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_RCF_AccOvTiErr[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_RCF_EstOfsErr[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_RCF_EstOfsErr)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_RCF_EstOfsErr[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_RCF_FwlBwdOvTiErr[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_RCF_FwlBwdOvTiErr)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_RCF_FwlBwdOvTiErr[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_RCF_FwlFwdOvTiErr[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_RCF_FwlFwdOvTiErr)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_RCF_FwlFwdOvTiErr[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_RCF_OfsClbFail[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_RCF_OfsClbFail)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_RCF_OfsClbFail[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_RCF_PsiOvErr[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_RCF_PsiOvErr)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_RCF_PsiOvErr[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_RSL_DOSErr[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_RSL_DOSErr)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_RSL_DOSErr[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_RSL_ExcFaultErr[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_RSL_ExcFaultErr)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_RSL_ExcFaultErr[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_RSL_LOSErr[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_RSL_LOSErr)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_RSL_LOSErr[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_RSL_LOTErr[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_RSL_LOTErr)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_RSL_LOTErr[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_SCF_DisChgOvTiFail[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_SCF_DisChgOvTiFail)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_SCF_DisChgOvTiFail[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_SCF_LowPwrShtDwnOvTiFail[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_SCF_LowPwrShtDwnOvTiFail)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_SCF_LowPwrShtDwnOvTiFail[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_SCF_RunToDischarErr[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_SCF_RunToDischarErr)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_SCF_RunToDischarErr[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_TPC_iDcLnkOvCLimFail[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_TPC_iDcLnkOvCLimFail)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_TPC_iDcLnkOvCLimFail[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_TPC_iDcLnkOvcWarn[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_TPC_iDcLnkOvcWarn)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_TPC_iDcLnkOvcWarn[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_TPC_SpdOvHiLimFail[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_TPC_SpdOvHiLimFail)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_TPC_SpdOvHiLimFail[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_TPC_SpdOvHiWarn[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_TPC_SpdOvHiWarn)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_TPC_SpdOvHiWarn[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_TPC_TCoolantOvHiWarn[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_TPC_TCoolantOvHiWarn)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_TPC_TCoolantOvHiWarn[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_TPC_TDbcOvHiWarn[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_TPC_TDbcOvHiWarn)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_TPC_TDbcOvHiWarn[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_TPC_TDbcOvLoWarn[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_TPC_TDbcOvLoWarn)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_TPC_TDbcOvLoWarn[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_TPC_TDbcUHiLimFail[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_TPC_TDbcUHiLimFail)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_TPC_TDbcUHiLimFail[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_TPC_TDbcULoLimFail[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_TPC_TDbcULoLimFail)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_TPC_TDbcULoLimFail[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_TPC_TDbcVHiLimFail[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_TPC_TDbcVHiLimFail)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_TPC_TDbcVHiLimFail[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_TPC_TDbcVLoLimFail[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_TPC_TDbcVLoLimFail)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_TPC_TDbcVLoLimFail[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_TPC_TDbcWHiLimFail[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_TPC_TDbcWHiLimFail)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_TPC_TDbcWHiLimFail[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_TPC_TDbcWLoLimFail[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_TPC_TDbcWLoLimFail)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_TPC_TDbcWLoLimFail[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_TPC_TDrvBoardOvHiWarn[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_TPC_TDrvBoardOvHiWarn)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_TPC_TDrvBoardOvHiWarn[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_TPC_TIGBTOvHiLimErr[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_TPC_TIGBTOvHiLimErr)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_TPC_TIGBTOvHiLimErr[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_TPC_TIGBTOvHiWarn[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_TPC_TIGBTOvHiWarn)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_TPC_TIGBTOvHiWarn[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_TPC_TIGBTOvLoWarn[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_TPC_TIGBTOvLoWarn)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_TPC_TIGBTOvLoWarn[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_TPC_TSttrOvHiLimFail[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_TPC_TSttrOvHiLimFail)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_TPC_TSttrOvHiLimFail[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_TPC_TSttrOvHiWarn[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_TPC_TSttrOvHiWarn)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_TPC_TSttrOvHiWarn[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_TPC_TSttrOvLoWarn[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_TPC_TSttrOvLoWarn)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_TPC_TSttrOvLoWarn[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_TPC_uDcLnkOvVLimFail[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_TPC_uDcLnkOvVLimFail)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_TPC_uDcLnkOvVLimFail[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_TPC_uDcLnkOvWarn[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_TPC_uDcLnkOvWarn)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_TPC_uDcLnkOvWarn[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_TPC_uDcLnkUnVLimFail[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_TPC_uDcLnkUnVLimFail)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_TPC_uDcLnkUnVLimFail[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_TPC_uDcLnkUnvWarn[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_TPC_uDcLnkUnvWarn)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_TPC_uDcLnkUnvWarn[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_Cpld_Rx_SelfTest_Fail[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_Cpld_Rx_SelfTest_Fail)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_Cpld_Rx_SelfTest_Fail[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_HvMcu_UdcOverFlagLimit[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_HvMcu_UdcOverFlagLimit)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_HvMcu_UdcOverFlagLimit[0])) \
   } \
};

#endif

/*----------------------------------------------------------------------------
 J1939Node <-> DTC Mapping
 ----------------------------------------------------------------------------*/

#endif

