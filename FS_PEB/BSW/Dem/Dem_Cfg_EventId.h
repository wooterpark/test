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

#ifndef DEM_CFG_EVENTID_H
#define DEM_CFG_EVENTID_H

#define DEM_EVENTID_INVALID                                          0u
#define DEM_EVENTID_COUNT         127u
#define DEM_EVENTID_ARRAYLENGTH   (DEM_EVENTID_COUNT+1u)

#define DemConf_DemEventParameter_ADC_UPhaseBISTFail                 1u
#define DemConf_DemEventParameter_ADC_VPhaseBISTFail                 2u
#define DemConf_DemEventParameter_ADC_WPhaseBISTFail                 3u
#define DemConf_DemEventParameter_CANSM_E_BUS_OFF_NETWORK_0          4u
#define DemConf_DemEventParameter_CANSM_E_BUS_OFF_NETWORK_1          5u
#define DemConf_DemEventParameter_Can_Timeout                        6u
#define DemConf_DemEventParameter_Cpld_AliveChkErr                   7u
#define DemConf_DemEventParameter_Cpld_DI_ExdClk_InFail              8u
#define DemConf_DemEventParameter_Cpld_ExdClkInFail                  9u
#define DemConf_DemEventParameter_Cpld_IphaOC                        10u
#define DemConf_DemEventParameter_Cpld_NEN_InFail                    11u
#define DemConf_DemEventParameter_Cpld_ParityChkErr                  12u
#define DemConf_DemEventParameter_Cpld_Rx_SelfTest_Fail              13u
#define DemConf_DemEventParameter_Cpld_SPIComFail                    14u
#define DemConf_DemEventParameter_Cpld_SZTKT_InFail                  15u
#define DemConf_DemEventParameter_Cpld_Short_Circuit_HS_InFail       16u
#define DemConf_DemEventParameter_Cpld_Short_Circuit_LS_InFail       17u
#define DemConf_DemEventParameter_Cpld_UdcOverVolFail                18u
#define DemConf_DemEventParameter_Cpld_UnderVol_HS_InFail            19u
#define DemConf_DemEventParameter_Cpld_UnderVol_LS_InFail            20u
#define DemConf_DemEventParameter_Epark_OverCurFail                  21u
#define DemConf_DemEventParameter_Epark_PosMonSampFail               22u
#define DemConf_DemEventParameter_Epark_PosSampFail                  23u
#define DemConf_DemEventParameter_Epark_SampFail                     24u
#define DemConf_DemEventParameter_Event_NvM_ReadErr                  25u
#define DemConf_DemEventParameter_Event_NvM_WriteErr                 26u
#define DemConf_DemEventParameter_FR_StorageErr                      27u
#define DemConf_DemEventParameter_HSPF_InvOpenErr                    28u
#define DemConf_DemEventParameter_HSPF_MotorOpenErr                  29u
#define DemConf_DemEventParameter_HSPF_VerMatchFailureErr            30u
#define DemConf_DemEventParameter_HSPF_stIphaOffCalFail              31u
#define DemConf_DemEventParameter_HSPF_tDBCTempCmpErr                32u
#define DemConf_DemEventParameter_HvMcu_ComErr                       33u
#define DemConf_DemEventParameter_HvMcu_DisChrgDutyErr               34u
#define DemConf_DemEventParameter_HvMcu_DisChrgFail                  35u
#define DemConf_DemEventParameter_HvMcu_DisChrgFreqErr               36u
#define DemConf_DemEventParameter_HvMcu_EmerPowerSapErr              37u
#define DemConf_DemEventParameter_HvMcu_UartCheckFailErr             38u
#define DemConf_DemEventParameter_HvMcu_UartLostFrameErr             39u
#define DemConf_DemEventParameter_HvMcu_UdcCheckErr                  40u
#define DemConf_DemEventParameter_HvMcu_UdcOverFlagLimit             41u
#define DemConf_DemEventParameter_HvMcu_UdcOverVolErr                42u
#define DemConf_DemEventParameter_IOHWAB_12VNarrSampErr              43u
#define DemConf_DemEventParameter_IOHWAB_12VSampErr                  44u
#define DemConf_DemEventParameter_IOHWAB_12VWideSampErr              45u
#define DemConf_DemEventParameter_IOHWAB_18VLwBrgSampFail            46u
#define DemConf_DemEventParameter_IOHWAB_18VUpBrgSampFail            47u
#define DemConf_DemEventParameter_IOHWAB_1V3MCU_SampFail             48u
#define DemConf_DemEventParameter_IOHWAB_3V3MCU_SampFail             49u
#define DemConf_DemEventParameter_IOHWAB_5VQcoSampFail               50u
#define DemConf_DemEventParameter_IOHWAB_5VQt1SampFail               51u
#define DemConf_DemEventParameter_IOHWAB_5VQt2SampFail               52u
#define DemConf_DemEventParameter_IOHWAB_Cpld1v8SampFail             53u
#define DemConf_DemEventParameter_IOHWAB_Cpld3v3SampFail             54u
#define DemConf_DemEventParameter_IOHWAB_CrashFail                   55u
#define DemConf_DemEventParameter_IOHWAB_DcLnkOverVolFail            56u
#define DemConf_DemEventParameter_IOHWAB_IphaOCFail                  57u
#define DemConf_DemEventParameter_IOHWAB_KL30OverVolErr              58u
#define DemConf_DemEventParameter_IOHWAB_KL30SevOverVolFail          59u
#define DemConf_DemEventParameter_IOHWAB_KL30SevUnderVolFail         60u
#define DemConf_DemEventParameter_IOHWAB_KL30UnderVolErr             61u
#define DemConf_DemEventParameter_IOHWAB_Nen33Fail                   62u
#define DemConf_DemEventParameter_IOHWAB_SttrSenorShrFail            63u
#define DemConf_DemEventParameter_IOHWAB_SttrTemp1SampFail           64u
#define DemConf_DemEventParameter_IOHWAB_SttrTemp2SampFail           65u
#define DemConf_DemEventParameter_IOHWAB_TCoolantSampFail            66u
#define DemConf_DemEventParameter_IOHWAB_VDD5_D_SampFail             67u
#define DemConf_DemEventParameter_IgbtDrv_ComErr                     68u
#define DemConf_DemEventParameter_IgbtDrv_LwBrgFaultAFail            69u
#define DemConf_DemEventParameter_IgbtDrv_LwBrgFaultBFail            70u
#define DemConf_DemEventParameter_IgbtDrv_UpBrgFaultAFail            71u
#define DemConf_DemEventParameter_IgbtDrv_UpBrgFaultBFail            72u
#define DemConf_DemEventParameter_MDF_AlOfsNoPlausErr                73u
#define DemConf_DemEventParameter_MDF_DiashCirNoPsblErr              74u
#define DemConf_DemEventParameter_MDF_EmacBlkdErr                    75u
#define DemConf_DemEventParameter_MDF_EmacBlkdWarn                   76u
#define DemConf_DemEventParameter_MDF_ICtlRatErr                     77u
#define DemConf_DemEventParameter_MDF_IsOvHiErr                      78u
#define DemConf_DemEventParameter_MDF_OpenCirNoPsblErr               79u
#define DemConf_DemEventParameter_MDF_OperOutdRngErr                 80u
#define DemConf_DemEventParameter_MDF_PhaseLossFaultErr              81u
#define DemConf_DemEventParameter_MDF_PrfElDrvErr                    82u
#define DemConf_DemEventParameter_PCF_ActOvTiErr                     83u
#define DemConf_DemEventParameter_PCF_IdcOvErr                       84u
#define DemConf_DemEventParameter_PCF_SelfcheckErr                   85u
#define DemConf_DemEventParameter_PCF_SenClbErr                      86u
#define DemConf_DemEventParameter_PCF_SenOvErr                       87u
#define DemConf_DemEventParameter_PCF_StallRetryErr                  88u
#define DemConf_DemEventParameter_PCF_StallWarn                      89u
#define DemConf_DemEventParameter_PCF_UnexpPosErr                    90u
#define DemConf_DemEventParameter_RCF_AccOvTiErr                     91u
#define DemConf_DemEventParameter_RCF_EstOfsErr                      92u
#define DemConf_DemEventParameter_RCF_FwlBwdOvTiErr                  93u
#define DemConf_DemEventParameter_RCF_FwlFwdOvTiErr                  94u
#define DemConf_DemEventParameter_RCF_OfsClbFail                     95u
#define DemConf_DemEventParameter_RCF_PsiOvErr                       96u
#define DemConf_DemEventParameter_RSL_DOSErr                         97u
#define DemConf_DemEventParameter_RSL_ExcErr                         98u
#define DemConf_DemEventParameter_RSL_LOSErr                         99u
#define DemConf_DemEventParameter_RSL_LOTErr                         100u
#define DemConf_DemEventParameter_SCF_DisChgOvTiFail                 101u
#define DemConf_DemEventParameter_SCF_LowPwrShtDwnOvTiFail           102u
#define DemConf_DemEventParameter_SCF_RunToDischarErr                103u
#define DemConf_DemEventParameter_TPC_SpdOvHiLimFail                 104u
#define DemConf_DemEventParameter_TPC_SpdOvHiWarn                    105u
#define DemConf_DemEventParameter_TPC_TCoolantOvHiWarn               106u
#define DemConf_DemEventParameter_TPC_TDbcOvHiWarn                   107u
#define DemConf_DemEventParameter_TPC_TDbcOvLoWarn                   108u
#define DemConf_DemEventParameter_TPC_TDbcUHiLimFail                 109u
#define DemConf_DemEventParameter_TPC_TDbcULoLimFail                 110u
#define DemConf_DemEventParameter_TPC_TDbcVHiLimFail                 111u
#define DemConf_DemEventParameter_TPC_TDbcVLoLimFail                 112u
#define DemConf_DemEventParameter_TPC_TDbcWHiLimFail                 113u
#define DemConf_DemEventParameter_TPC_TDbcWLoLimFail                 114u
#define DemConf_DemEventParameter_TPC_TDrvBoardOvHiWarn              115u
#define DemConf_DemEventParameter_TPC_TIGBTOvHiLimErr                116u
#define DemConf_DemEventParameter_TPC_TIGBTOvHiWarn                  117u
#define DemConf_DemEventParameter_TPC_TIGBTOvLoWarn                  118u
#define DemConf_DemEventParameter_TPC_TSttrOvHiLimFail               119u
#define DemConf_DemEventParameter_TPC_TSttrOvHiWarn                  120u
#define DemConf_DemEventParameter_TPC_TSttrOvLoWarn                  121u
#define DemConf_DemEventParameter_TPC_iDcLnkOvCLimFail               122u
#define DemConf_DemEventParameter_TPC_iDcLnkOvcWarn                  123u
#define DemConf_DemEventParameter_TPC_uDcLnkOvVLimFail               124u
#define DemConf_DemEventParameter_TPC_uDcLnkOvWarn                   125u
#define DemConf_DemEventParameter_TPC_uDcLnkUnVLimFail               126u
#define DemConf_DemEventParameter_TPC_uDcLnkUnvWarn                  127u

#endif

