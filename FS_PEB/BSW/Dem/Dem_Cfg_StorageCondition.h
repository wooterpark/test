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

#ifndef DEM_CFG_STORAGECONDITION_H
#define DEM_CFG_STORAGECONDITION_H

#include "Std_Types.h"

#define DEM_CFG_STORAGECONDITION_ON    STD_ON
#define DEM_CFG_STORAGECONDITION_OFF   STD_OFF
#define DEM_CFG_STORAGECONDITION       DEM_CFG_STORAGECONDITION_OFF

#define DemConf_DemStorageCondition_DemStorageCondition_0   0u

#define DEM_STORAGECONDITION_COUNT         1u
#define DEM_STORAGECONDITION_ARRAYLENGTH   (DEM_STORAGECONDITION_COUNT)

/* define type depends on projectspecific number of storageconditions */
/* if no storage conditions are support use uint8 to allow empty inline functions */
#if (DEM_STORAGECONDITION_ARRAYLENGTH <= 8) \
	|| (DEM_CFG_STORAGECONDITION == DEM_CFG_STORAGECONDITION_OFF)
typedef uint8 Dem_StoCoList;
#elif (DEM_STORAGECONDITION_ARRAYLENGTH <= 16)
typedef uint16 Dem_StoCoList;
#elif (DEM_STORAGECONDITION_ARRAYLENGTH <= 32)
typedef uint32 Dem_StoCoList;
#else
#error DEM currently only supports up to 32 StorageConditions
#endif

#if (DEM_CFG_STORAGECONDITION == DEM_CFG_STORAGECONDITION_ON)

#define DEM_STOCOBM_DemStorageCondition_0               ((Dem_StoCoList)(1u << DemConf_DemStorageCondition_DemStorageCondition_0))

#define DEM_STOCO_ADC_UPhaseBISTFail                        (0u)
#define DEM_STOCO_ADC_VPhaseBISTFail                        (0u)
#define DEM_STOCO_ADC_WPhaseBISTFail                        (0u)
#define DEM_STOCO_CANSM_E_BUS_OFF_NETWORK_0                 (0u)
#define DEM_STOCO_CANSM_E_BUS_OFF_NETWORK_1                 (0u)
#define DEM_STOCO_Can_Timeout                               (0u)
#define DEM_STOCO_Cpld_AliveChkErr                          (0u)
#define DEM_STOCO_Cpld_DI_ExdClk_InFail                     (0u)
#define DEM_STOCO_Cpld_ExdClkInFail                         (0u)
#define DEM_STOCO_Cpld_IphaOC                               (0u)
#define DEM_STOCO_Cpld_NEN_InFail                           (0u)
#define DEM_STOCO_Cpld_ParityChkErr                         (0u)
#define DEM_STOCO_Cpld_Rx_SelfTest_Fail                     (0u)
#define DEM_STOCO_Cpld_SPIComFail                           (0u)
#define DEM_STOCO_Cpld_SZTKT_InFail                         (0u)
#define DEM_STOCO_Cpld_Short_Circuit_HS_InFail              (0u)
#define DEM_STOCO_Cpld_Short_Circuit_LS_InFail              (0u)
#define DEM_STOCO_Cpld_UdcOverVolFail                       (0u)
#define DEM_STOCO_Cpld_UnderVol_HS_InFail                   (0u)
#define DEM_STOCO_Cpld_UnderVol_LS_InFail                   (0u)
#define DEM_STOCO_Epark_OverCurFail                         (0u)
#define DEM_STOCO_Epark_PosMonSampFail                      (0u)
#define DEM_STOCO_Epark_PosSampFail                         (0u)
#define DEM_STOCO_Epark_SampFail                            (0u)
#define DEM_STOCO_Event_NvM_ReadErr                         (0u)
#define DEM_STOCO_Event_NvM_WriteErr                        (0u)
#define DEM_STOCO_FR_StorageErr                             (0u)
#define DEM_STOCO_HSPF_InvOpenErr                           (0u)
#define DEM_STOCO_HSPF_MotorOpenErr                         (0u)
#define DEM_STOCO_HSPF_VerMatchFailureErr                   (0u)
#define DEM_STOCO_HSPF_stIphaOffCalFail                     (0u)
#define DEM_STOCO_HSPF_tDBCTempCmpErr                       (0u)
#define DEM_STOCO_HvMcu_ComErr                              (0u)
#define DEM_STOCO_HvMcu_DisChrgDutyErr                      (0u)
#define DEM_STOCO_HvMcu_DisChrgFail                         (0u)
#define DEM_STOCO_HvMcu_DisChrgFreqErr                      (0u)
#define DEM_STOCO_HvMcu_EmerPowerSapErr                     (0u)
#define DEM_STOCO_HvMcu_UartCheckFailErr                    (0u)
#define DEM_STOCO_HvMcu_UartLostFrameErr                    (0u)
#define DEM_STOCO_HvMcu_UdcCheckErr                         (0u)
#define DEM_STOCO_HvMcu_UdcOverFlagLimit                    (0u)
#define DEM_STOCO_HvMcu_UdcOverVolErr                       (0u)
#define DEM_STOCO_IOHWAB_12VNarrSampErr                     (0u)
#define DEM_STOCO_IOHWAB_12VSampErr                         (0u)
#define DEM_STOCO_IOHWAB_12VWideSampErr                     (0u)
#define DEM_STOCO_IOHWAB_18VLwBrgSampFail                   (0u)
#define DEM_STOCO_IOHWAB_18VUpBrgSampFail                   (0u)
#define DEM_STOCO_IOHWAB_1V3MCU_SampFail                    (0u)
#define DEM_STOCO_IOHWAB_3V3MCU_SampFail                    (0u)
#define DEM_STOCO_IOHWAB_5VQcoSampFail                      (0u)
#define DEM_STOCO_IOHWAB_5VQt1SampFail                      (0u)
#define DEM_STOCO_IOHWAB_5VQt2SampFail                      (0u)
#define DEM_STOCO_IOHWAB_Cpld1v8SampFail                    (0u)
#define DEM_STOCO_IOHWAB_Cpld3v3SampFail                    (0u)
#define DEM_STOCO_IOHWAB_CrashFail                          (0u)
#define DEM_STOCO_IOHWAB_DcLnkOverVolFail                   (0u)
#define DEM_STOCO_IOHWAB_IphaOCFail                         (0u)
#define DEM_STOCO_IOHWAB_KL30OverVolErr                     (0u)
#define DEM_STOCO_IOHWAB_KL30SevOverVolFail                 (0u)
#define DEM_STOCO_IOHWAB_KL30SevUnderVolFail                (0u)
#define DEM_STOCO_IOHWAB_KL30UnderVolErr                    (0u)
#define DEM_STOCO_IOHWAB_Nen33Fail                          (0u)
#define DEM_STOCO_IOHWAB_SttrSenorShrFail                   (0u)
#define DEM_STOCO_IOHWAB_SttrTemp1SampFail                  (0u)
#define DEM_STOCO_IOHWAB_SttrTemp2SampFail                  (0u)
#define DEM_STOCO_IOHWAB_TCoolantSampFail                   (0u)
#define DEM_STOCO_IOHWAB_VDD5_D_SampFail                    (0u)
#define DEM_STOCO_IgbtDrv_ComErr                            (0u)
#define DEM_STOCO_IgbtDrv_LwBrgFaultAFail                   (0u)
#define DEM_STOCO_IgbtDrv_LwBrgFaultBFail                   (0u)
#define DEM_STOCO_IgbtDrv_UpBrgFaultAFail                   (0u)
#define DEM_STOCO_IgbtDrv_UpBrgFaultBFail                   (0u)
#define DEM_STOCO_MDF_AlOfsNoPlausErr                       (0u)
#define DEM_STOCO_MDF_DiashCirNoPsblErr                     (0u)
#define DEM_STOCO_MDF_EmacBlkdErr                           (0u)
#define DEM_STOCO_MDF_EmacBlkdWarn                          (0u)
#define DEM_STOCO_MDF_ICtlRatErr                            (0u)
#define DEM_STOCO_MDF_IsOvHiErr                             (0u)
#define DEM_STOCO_MDF_OpenCirNoPsblErr                      (0u)
#define DEM_STOCO_MDF_OperOutdRngErr                        (0u)
#define DEM_STOCO_MDF_PhaseLossFaultErr                     (0u)
#define DEM_STOCO_MDF_PrfElDrvErr                           (0u)
#define DEM_STOCO_PCF_ActOvTiErr                            (0u)
#define DEM_STOCO_PCF_IdcOvErr                              (0u)
#define DEM_STOCO_PCF_SelfcheckErr                          (0u)
#define DEM_STOCO_PCF_SenClbErr                             (0u)
#define DEM_STOCO_PCF_SenOvErr                              (0u)
#define DEM_STOCO_PCF_StallRetryErr                         (0u)
#define DEM_STOCO_PCF_StallWarn                             (0u)
#define DEM_STOCO_PCF_UnexpPosErr                           (0u)
#define DEM_STOCO_RCF_AccOvTiErr                            (0u)
#define DEM_STOCO_RCF_EstOfsErr                             (0u)
#define DEM_STOCO_RCF_FwlBwdOvTiErr                         (0u)
#define DEM_STOCO_RCF_FwlFwdOvTiErr                         (0u)
#define DEM_STOCO_RCF_OfsClbFail                            (0u)
#define DEM_STOCO_RCF_PsiOvErr                              (0u)
#define DEM_STOCO_RSL_DOSErr                                (0u)
#define DEM_STOCO_RSL_ExcErr                                (0u)
#define DEM_STOCO_RSL_LOSErr                                (0u)
#define DEM_STOCO_RSL_LOTErr                                (0u)
#define DEM_STOCO_SCF_DisChgOvTiFail                        (0u)
#define DEM_STOCO_SCF_LowPwrShtDwnOvTiFail                  (0u)
#define DEM_STOCO_SCF_RunToDischarErr                       (0u)
#define DEM_STOCO_TPC_SpdOvHiLimFail                        (0u)
#define DEM_STOCO_TPC_SpdOvHiWarn                           (0u)
#define DEM_STOCO_TPC_TCoolantOvHiWarn                      (0u)
#define DEM_STOCO_TPC_TDbcOvHiWarn                          (0u)
#define DEM_STOCO_TPC_TDbcOvLoWarn                          (0u)
#define DEM_STOCO_TPC_TDbcUHiLimFail                        (0u)
#define DEM_STOCO_TPC_TDbcULoLimFail                        (0u)
#define DEM_STOCO_TPC_TDbcVHiLimFail                        (0u)
#define DEM_STOCO_TPC_TDbcVLoLimFail                        (0u)
#define DEM_STOCO_TPC_TDbcWHiLimFail                        (0u)
#define DEM_STOCO_TPC_TDbcWLoLimFail                        (0u)
#define DEM_STOCO_TPC_TDrvBoardOvHiWarn                     (0u)
#define DEM_STOCO_TPC_TIGBTOvHiLimErr                       (0u)
#define DEM_STOCO_TPC_TIGBTOvHiWarn                         (0u)
#define DEM_STOCO_TPC_TIGBTOvLoWarn                         (0u)
#define DEM_STOCO_TPC_TSttrOvHiLimFail                      (0u)
#define DEM_STOCO_TPC_TSttrOvHiWarn                         (0u)
#define DEM_STOCO_TPC_TSttrOvLoWarn                         (0u)
#define DEM_STOCO_TPC_iDcLnkOvCLimFail                      (0u)
#define DEM_STOCO_TPC_iDcLnkOvcWarn                         (0u)
#define DEM_STOCO_TPC_uDcLnkOvVLimFail                      (0u)
#define DEM_STOCO_TPC_uDcLnkOvWarn                          (0u)
#define DEM_STOCO_TPC_uDcLnkUnVLimFail                      (0u)
#define DEM_STOCO_TPC_uDcLnkUnvWarn                         (0u)

#define DEM_CFG_STOCO_INITIALSTATE    (   0u \
                                       + (1u * DEM_STOCOBM_DemStorageCondition_0) \
                                      )

/* definition of replacement failures */
#define DEM_CFG_STOCO_PARAMS \
{ \
   { \
   DEM_EVENTID_INVALID, \
   } \
}

#endif

#endif

