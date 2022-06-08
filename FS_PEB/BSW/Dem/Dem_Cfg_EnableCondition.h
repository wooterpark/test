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

#ifndef DEM_CFG_ENABLECONDITION_H
#define DEM_CFG_ENABLECONDITION_H

#include "Std_Types.h"

#define DEM_CFG_ENABLECONDITION_ON    STD_ON
#define DEM_CFG_ENABLECONDITION_OFF   STD_OFF
#define DEM_CFG_ENABLECONDITION       DEM_CFG_ENABLECONDITION_ON

#define DemConf_DemEnableCondition_DemEnableCondition_0   0u

#define DEM_ENABLECONDITION_COUNT         1u
#define DEM_ENABLECONDITION_ARRAYLENGTH   (DEM_ENABLECONDITION_COUNT)

/* define type depends on projectspecific number of storageconditions */
/* if no storage conditions are support use uint8 to allow empty inline functions */
#if (DEM_ENABLECONDITION_ARRAYLENGTH <= 8) \
	|| (DEM_CFG_ENABLECONDITION == DEM_CFG_ENABLECONDITION_OFF)
typedef uint8 Dem_EnCoList;
#elif (DEM_ENABLECONDITION_ARRAYLENGTH <= 16)
typedef uint16 Dem_EnCoList;
#elif (DEM_ENABLECONDITION_ARRAYLENGTH <= 32)
typedef uint32 Dem_EnCoList;
#else
#error DEM currently only supports up to 32 EnableConditions
#endif

#if (DEM_CFG_ENABLECONDITION == DEM_CFG_ENABLECONDITION_ON)

#define DEM_ENCOBM_DemEnableCondition_0                ((Dem_EnCoList)(1u << DemConf_DemEnableCondition_DemEnableCondition_0))

#define DEM_ENCO_ADC_UPhaseBISTFail             (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_ADC_VPhaseBISTFail             (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_ADC_WPhaseBISTFail             (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_CANSM_E_BUS_OFF_NETWORK_0      (0u)
#define DEM_ENCO_CANSM_E_BUS_OFF_NETWORK_1      (0u)
#define DEM_ENCO_Can_Timeout                    (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_Cpld_AliveChkErr               (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_Cpld_DI_ExdClk_InFail          (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_Cpld_ExdClkInFail              (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_Cpld_IphaOC                    (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_Cpld_NEN_InFail                (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_Cpld_ParityChkErr              (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_Cpld_Rx_SelfTest_Fail          (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_Cpld_SPIComFail                (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_Cpld_SZTKT_InFail              (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_Cpld_Short_Circuit_HS_InFail   (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_Cpld_Short_Circuit_LS_InFail   (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_Cpld_UdcOverVolFail            (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_Cpld_UnderVol_HS_InFail        (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_Cpld_UnderVol_LS_InFail        (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_Epark_OverCurFail              (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_Epark_PosMonSampFail           (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_Epark_PosSampFail              (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_Epark_SampFail                 (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_Event_NvM_ReadErr              (0u)
#define DEM_ENCO_Event_NvM_WriteErr             (0u)
#define DEM_ENCO_FR_StorageErr                  (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_HSPF_InvOpenErr                (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_HSPF_MotorOpenErr              (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_HSPF_VerMatchFailureErr        (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_HSPF_stIphaOffCalFail          (0u)
#define DEM_ENCO_HSPF_tDBCTempCmpErr            (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_HvMcu_ComErr                   (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_HvMcu_DisChrgDutyErr           (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_HvMcu_DisChrgFail              (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_HvMcu_DisChrgFreqErr           (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_HvMcu_EmerPowerSapErr          (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_HvMcu_UartCheckFailErr         (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_HvMcu_UartLostFrameErr         (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_HvMcu_UdcCheckErr              (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_HvMcu_UdcOverFlagLimit         (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_HvMcu_UdcOverVolErr            (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_IOHWAB_12VNarrSampErr          (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_IOHWAB_12VSampErr              (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_IOHWAB_12VWideSampErr          (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_IOHWAB_18VLwBrgSampFail        (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_IOHWAB_18VUpBrgSampFail        (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_IOHWAB_1V3MCU_SampFail         (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_IOHWAB_3V3MCU_SampFail         (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_IOHWAB_5VQcoSampFail           (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_IOHWAB_5VQt1SampFail           (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_IOHWAB_5VQt2SampFail           (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_IOHWAB_Cpld1v8SampFail         (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_IOHWAB_Cpld3v3SampFail         (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_IOHWAB_CrashFail               (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_IOHWAB_DcLnkOverVolFail        (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_IOHWAB_IphaOCFail              (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_IOHWAB_KL30OverVolErr          (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_IOHWAB_KL30SevOverVolFail      (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_IOHWAB_KL30SevUnderVolFail     (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_IOHWAB_KL30UnderVolErr         (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_IOHWAB_Nen33Fail               (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_IOHWAB_SttrSenorShrFail        (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_IOHWAB_SttrTemp1SampFail       (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_IOHWAB_SttrTemp2SampFail       (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_IOHWAB_TCoolantSampFail        (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_IOHWAB_VDD5_D_SampFail         (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_IgbtDrv_ComErr                 (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_IgbtDrv_LwBrgFaultAFail        (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_IgbtDrv_LwBrgFaultBFail        (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_IgbtDrv_UpBrgFaultAFail        (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_IgbtDrv_UpBrgFaultBFail        (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_MDF_AlOfsNoPlausErr            (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_MDF_DiashCirNoPsblErr          (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_MDF_EmacBlkdErr                (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_MDF_EmacBlkdWarn               (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_MDF_ICtlRatErr                 (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_MDF_IsOvHiErr                  (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_MDF_OpenCirNoPsblErr           (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_MDF_OperOutdRngErr             (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_MDF_PhaseLossFaultErr          (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_MDF_PrfElDrvErr                (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_PCF_ActOvTiErr                 (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_PCF_IdcOvErr                   (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_PCF_SelfcheckErr               (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_PCF_SenClbErr                  (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_PCF_SenOvErr                   (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_PCF_StallRetryErr              (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_PCF_StallWarn                  (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_PCF_UnexpPosErr                (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_RCF_AccOvTiErr                 (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_RCF_EstOfsErr                  (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_RCF_FwlBwdOvTiErr              (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_RCF_FwlFwdOvTiErr              (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_RCF_OfsClbFail                 (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_RCF_PsiOvErr                   (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_RSL_DOSErr                     (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_RSL_ExcErr                     (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_RSL_LOSErr                     (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_RSL_LOTErr                     (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_SCF_DisChgOvTiFail             (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_SCF_LowPwrShtDwnOvTiFail       (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_SCF_RunToDischarErr            (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_TPC_SpdOvHiLimFail             (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_TPC_SpdOvHiWarn                (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_TPC_TCoolantOvHiWarn           (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_TPC_TDbcOvHiWarn               (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_TPC_TDbcOvLoWarn               (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_TPC_TDbcUHiLimFail             (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_TPC_TDbcULoLimFail             (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_TPC_TDbcVHiLimFail             (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_TPC_TDbcVLoLimFail             (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_TPC_TDbcWHiLimFail             (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_TPC_TDbcWLoLimFail             (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_TPC_TDrvBoardOvHiWarn          (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_TPC_TIGBTOvHiLimErr            (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_TPC_TIGBTOvHiWarn              (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_TPC_TIGBTOvLoWarn              (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_TPC_TSttrOvHiLimFail           (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_TPC_TSttrOvHiWarn              (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_TPC_TSttrOvLoWarn              (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_TPC_iDcLnkOvCLimFail           (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_TPC_iDcLnkOvcWarn              (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_TPC_uDcLnkOvVLimFail           (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_TPC_uDcLnkOvWarn               (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_TPC_uDcLnkUnVLimFail           (0u | DEM_ENCOBM_DemEnableCondition_0)
#define DEM_ENCO_TPC_uDcLnkUnvWarn              (0u | DEM_ENCOBM_DemEnableCondition_0)

#define DEM_CFG_ENCO_INITIALSTATE    (   0u \
                                       + (1u * DEM_ENCOBM_DemEnableCondition_0) \
                                      )

#endif

#endif

