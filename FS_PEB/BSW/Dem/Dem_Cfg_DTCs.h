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

#ifndef DEM_CFG_DTCS_H
#define DEM_CFG_DTCS_H

#include "Std_Types.h"

/* ---------------------------------------- */
/* DEM_CFG_STOREWAITINGFORMONITORINGEVENT     */
/* ---------------------------------------- */
#define DEM_CFG_STOREWAITINGFORMONITORINGEVENT  FALSE

/* ---------------------------------------- */
/* DEM_CFG_DTCFILTER_EXTERNALPROCESSING     */
/* ---------------------------------------- */
#define DEM_CFG_DTCFILTER_EXTERNALPROCESSING_OFF  STD_OFF
#define DEM_CFG_DTCFILTER_EXTERNALPROCESSING_ON   STD_ON
#define DEM_CFG_DTCFILTER_EXTERNALPROCESSING      DEM_CFG_DTCFILTER_EXTERNALPROCESSING_OFF

/* --------------------------------------------------- */
/* DEM_CFG_REPORT_CHRONOLOGICAL_ORDER_HOOKS_ENABLED    */
/* --------------------------------------------------- */
#define DEM_CFG_REPORT_CHRONOLOGICAL_ORDER_HOOKS_ENABLED   FALSE

#define DEM_CFG_DTCSTATUS_AVAILABILITYMASK     0xFFu
#define DEM_CFG_DTC_TRANSLATION_TYPE           DEM_DTC_TRANSLATION_ISO14229_1

#define DEM_CFG_DTCSTATEMANGER_DTCS_PER_CYCLE   10u

/* --------------------------------------------------- */
/* DEM DTC STATE BITPOSITION                         */
/* --------------------------------------------------- */

#define DEM_DTC_BP_STATE_SUPPRESSED             0u
#define DEM_DTC_BP_GROUP_DTCSETTING_DISABLED    1u

typedef uint8 Dem_DtcStateType;
#define DEM_DTCSTATE_ISBITSET                    rba_DiagLib_Bit8IsBitSet
#define DEM_DTCSTATE_OVERWRITEBIT                rba_DiagLib_Bit8OverwriteBit
#define DEM_DTCSTATE_CLEARBIT                    rba_DiagLib_Bit8ClearBit
#define DEM_DTCSTATE_SETBIT                      rba_DiagLib_Bit8SetBit

/**
 * Selects a group of DTCs.
 */

/*                KIND                               SEVERITY                           NV-STORAGE  FUNC_UNIT                DTCCODE_IS_INDEX          */

#define DEM_CFG_DTCPARAMS8 \
{ \
    DEM_DTCS_INIT8(0u,                                0u,                                0u,         0u,                      FALSE                    )/* No DTC Assigned */ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_Can_Timeout*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_CANSM_E_BUS_OFF_NETWORK*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_ADC_UVWPhaseBISTFail*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_Cpld_Fault*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_Epark_OverCurFail*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_Epark_PosSampFail*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_Epark_SampFail*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_Event_NvM_ReadErr*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_Event_NvM_WriteErr*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_FR_StorageErr*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_HSPF_Fault*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_HSPF_VerMatchFailureErr*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_HvMcu_Fault*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_IgbtDrv_Fault*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_IOHWAB_VSampFault*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_IOHWAB_Nen33Fail*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_IOHWAB_CrashFail*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_IOHWAB_DcLnkOverVolFail*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_IOHWAB_IphaOCFail*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_IOHWAB_SttrSenorShrFail*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_IOHWAB_SttrTempSampFail*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_IOHWAB_TCoolantSampFail*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_IOHWAB_KL30OVolFault*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_MDF_AlOfsNoPlausErr*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_MDF_DiashCirNoPsblErr*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_MDF_EmacBlkdErr*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_MDF_EmacBlkdWarn*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_MDF_ICtlRatErr*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_MDF_IsOvHiErr*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_MDF_OpenCirNoPsblErr*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_MDF_OperOutdRngErr*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_MDF_PhaseLossFaultErr*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_MDF_PrfElDrvErr*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_PCF_ActOvTiErr*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_PCF_IdcOvErr*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_PCF_SelfcheckErr*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_PCF_SenClbErr*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_PCF_SenOvErr*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_PCF_StallRetryErr*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_PCF_StallWarn*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_PCF_UnexpPosErr*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_RCF_AccOvTiErr*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_RCF_EstOfsErr*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_RCF_FwlBwdOvTiErr*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_RCF_FwlFwdOvTiErr*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_RCF_OfsClbFail*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_RCF_PsiOvErr*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_RSL_DOSErr*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_RSL_ExcFaultErr*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_RSL_LOSErr*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_RSL_LOTErr*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_SCF_DisChgOvTiFail*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_SCF_LowPwrShtDwnOvTiFail*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_SCF_RunToDischarErr*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_TPC_iDcLnkOvCLimFail*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_TPC_iDcLnkOvcWarn*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_TPC_SpdOvHiLimFail*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_TPC_SpdOvHiWarn*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_TPC_TCoolantOvHiWarn*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_TPC_TDbcOvHiWarn*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_TPC_TDbcOvLoWarn*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_TPC_TDbcUHiLimFail*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_TPC_TDbcULoLimFail*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_TPC_TDbcVHiLimFail*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_TPC_TDbcVLoLimFail*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_TPC_TDbcWHiLimFail*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_TPC_TDbcWLoLimFail*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_TPC_TDrvBoardOvHiWarn*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_TPC_TIGBTOvHiLimErr*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_TPC_TIGBTOvHiWarn*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_TPC_TIGBTOvLoWarn*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_TPC_TSttrOvHiLimFail*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_TPC_TSttrOvHiWarn*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_TPC_TSttrOvLoWarn*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_TPC_uDcLnkOvVLimFail*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_TPC_uDcLnkOvWarn*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_TPC_uDcLnkUnVLimFail*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_TPC_uDcLnkUnvWarn*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_Cpld_Rx_SelfTest_Fail*/ \
    ,DEM_DTCS_INIT8(DEM_DTC_KIND_ALL_DTCS,             DEM_SEVERITY_NO_SEVERITY,          0u,         0x6u,                    FALSE                    )/*DemDTC_HvMcu_UdcOverFlagLimit*/ \
}

#define DEM_CFG_DTCPARAMS32 \
{ \
    DEM_DTCS_INIT32(0              )/* No DTC Assigned */ \
    ,DEM_DTCS_INIT32(0xC00000       )/*DemDTC_Can_Timeout*/ \
    ,DEM_DTCS_INIT32(0xC00001       )/*DemDTC_CANSM_E_BUS_OFF_NETWORK*/ \
    ,DEM_DTCS_INIT32(0x300000       )/*DemDTC_ADC_UVWPhaseBISTFail*/ \
    ,DEM_DTCS_INIT32(0x300005       )/*DemDTC_Cpld_Fault*/ \
    ,DEM_DTCS_INIT32(0x300012       )/*DemDTC_Epark_OverCurFail*/ \
    ,DEM_DTCS_INIT32(0x300013       )/*DemDTC_Epark_PosSampFail*/ \
    ,DEM_DTCS_INIT32(0x300015       )/*DemDTC_Epark_SampFail*/ \
    ,DEM_DTCS_INIT32(0x300016       )/*DemDTC_Event_NvM_ReadErr*/ \
    ,DEM_DTCS_INIT32(0x300017       )/*DemDTC_Event_NvM_WriteErr*/ \
    ,DEM_DTCS_INIT32(0x300018       )/*DemDTC_FR_StorageErr*/ \
    ,DEM_DTCS_INIT32(0x300019       )/*DemDTC_HSPF_Fault*/ \
    ,DEM_DTCS_INIT32(0x30001A       )/*DemDTC_HSPF_VerMatchFailureErr*/ \
    ,DEM_DTCS_INIT32(0x30001E       )/*DemDTC_HvMcu_Fault*/ \
    ,DEM_DTCS_INIT32(0x300027       )/*DemDTC_IgbtDrv_Fault*/ \
    ,DEM_DTCS_INIT32(0x30002C       )/*DemDTC_IOHWAB_VSampFault*/ \
    ,DEM_DTCS_INIT32(0x300038       )/*DemDTC_IOHWAB_Nen33Fail*/ \
    ,DEM_DTCS_INIT32(0x300039       )/*DemDTC_IOHWAB_CrashFail*/ \
    ,DEM_DTCS_INIT32(0x30003A       )/*DemDTC_IOHWAB_DcLnkOverVolFail*/ \
    ,DEM_DTCS_INIT32(0x30003B       )/*DemDTC_IOHWAB_IphaOCFail*/ \
    ,DEM_DTCS_INIT32(0x30003C       )/*DemDTC_IOHWAB_SttrSenorShrFail*/ \
    ,DEM_DTCS_INIT32(0x30003D       )/*DemDTC_IOHWAB_SttrTempSampFail*/ \
    ,DEM_DTCS_INIT32(0x30003F       )/*DemDTC_IOHWAB_TCoolantSampFail*/ \
    ,DEM_DTCS_INIT32(0x300041       )/*DemDTC_IOHWAB_KL30OVolFault*/ \
    ,DEM_DTCS_INIT32(0x300045       )/*DemDTC_MDF_AlOfsNoPlausErr*/ \
    ,DEM_DTCS_INIT32(0x300046       )/*DemDTC_MDF_DiashCirNoPsblErr*/ \
    ,DEM_DTCS_INIT32(0x300047       )/*DemDTC_MDF_EmacBlkdErr*/ \
    ,DEM_DTCS_INIT32(0x300048       )/*DemDTC_MDF_EmacBlkdWarn*/ \
    ,DEM_DTCS_INIT32(0x300049       )/*DemDTC_MDF_ICtlRatErr*/ \
    ,DEM_DTCS_INIT32(0x30004A       )/*DemDTC_MDF_IsOvHiErr*/ \
    ,DEM_DTCS_INIT32(0x30004B       )/*DemDTC_MDF_OpenCirNoPsblErr*/ \
    ,DEM_DTCS_INIT32(0x30004C       )/*DemDTC_MDF_OperOutdRngErr*/ \
    ,DEM_DTCS_INIT32(0x30004D       )/*DemDTC_MDF_PhaseLossFaultErr*/ \
    ,DEM_DTCS_INIT32(0x30004E       )/*DemDTC_MDF_PrfElDrvErr*/ \
    ,DEM_DTCS_INIT32(0x30004F       )/*DemDTC_PCF_ActOvTiErr*/ \
    ,DEM_DTCS_INIT32(0x300050       )/*DemDTC_PCF_IdcOvErr*/ \
    ,DEM_DTCS_INIT32(0x300051       )/*DemDTC_PCF_SelfcheckErr*/ \
    ,DEM_DTCS_INIT32(0x300052       )/*DemDTC_PCF_SenClbErr*/ \
    ,DEM_DTCS_INIT32(0x300053       )/*DemDTC_PCF_SenOvErr*/ \
    ,DEM_DTCS_INIT32(0x300054       )/*DemDTC_PCF_StallRetryErr*/ \
    ,DEM_DTCS_INIT32(0x300055       )/*DemDTC_PCF_StallWarn*/ \
    ,DEM_DTCS_INIT32(0x300056       )/*DemDTC_PCF_UnexpPosErr*/ \
    ,DEM_DTCS_INIT32(0x300057       )/*DemDTC_RCF_AccOvTiErr*/ \
    ,DEM_DTCS_INIT32(0x300058       )/*DemDTC_RCF_EstOfsErr*/ \
    ,DEM_DTCS_INIT32(0x300059       )/*DemDTC_RCF_FwlBwdOvTiErr*/ \
    ,DEM_DTCS_INIT32(0x30005A       )/*DemDTC_RCF_FwlFwdOvTiErr*/ \
    ,DEM_DTCS_INIT32(0x30005B       )/*DemDTC_RCF_OfsClbFail*/ \
    ,DEM_DTCS_INIT32(0x30005C       )/*DemDTC_RCF_PsiOvErr*/ \
    ,DEM_DTCS_INIT32(0x30005D       )/*DemDTC_RSL_DOSErr*/ \
    ,DEM_DTCS_INIT32(0x30005E       )/*DemDTC_RSL_ExcFaultErr*/ \
    ,DEM_DTCS_INIT32(0x30005F       )/*DemDTC_RSL_LOSErr*/ \
    ,DEM_DTCS_INIT32(0x300060       )/*DemDTC_RSL_LOTErr*/ \
    ,DEM_DTCS_INIT32(0x300061       )/*DemDTC_SCF_DisChgOvTiFail*/ \
    ,DEM_DTCS_INIT32(0x300062       )/*DemDTC_SCF_LowPwrShtDwnOvTiFail*/ \
    ,DEM_DTCS_INIT32(0x300063       )/*DemDTC_SCF_RunToDischarErr*/ \
    ,DEM_DTCS_INIT32(0x300064       )/*DemDTC_TPC_iDcLnkOvCLimFail*/ \
    ,DEM_DTCS_INIT32(0x300065       )/*DemDTC_TPC_iDcLnkOvcWarn*/ \
    ,DEM_DTCS_INIT32(0x300066       )/*DemDTC_TPC_SpdOvHiLimFail*/ \
    ,DEM_DTCS_INIT32(0x300067       )/*DemDTC_TPC_SpdOvHiWarn*/ \
    ,DEM_DTCS_INIT32(0x300068       )/*DemDTC_TPC_TCoolantOvHiWarn*/ \
    ,DEM_DTCS_INIT32(0x300069       )/*DemDTC_TPC_TDbcOvHiWarn*/ \
    ,DEM_DTCS_INIT32(0x30006A       )/*DemDTC_TPC_TDbcOvLoWarn*/ \
    ,DEM_DTCS_INIT32(0x30006B       )/*DemDTC_TPC_TDbcUHiLimFail*/ \
    ,DEM_DTCS_INIT32(0x30006C       )/*DemDTC_TPC_TDbcULoLimFail*/ \
    ,DEM_DTCS_INIT32(0x30006D       )/*DemDTC_TPC_TDbcVHiLimFail*/ \
    ,DEM_DTCS_INIT32(0x30006E       )/*DemDTC_TPC_TDbcVLoLimFail*/ \
    ,DEM_DTCS_INIT32(0x30006F       )/*DemDTC_TPC_TDbcWHiLimFail*/ \
    ,DEM_DTCS_INIT32(0x300070       )/*DemDTC_TPC_TDbcWLoLimFail*/ \
    ,DEM_DTCS_INIT32(0x300071       )/*DemDTC_TPC_TDrvBoardOvHiWarn*/ \
    ,DEM_DTCS_INIT32(0x300072       )/*DemDTC_TPC_TIGBTOvHiLimErr*/ \
    ,DEM_DTCS_INIT32(0x300073       )/*DemDTC_TPC_TIGBTOvHiWarn*/ \
    ,DEM_DTCS_INIT32(0x300074       )/*DemDTC_TPC_TIGBTOvLoWarn*/ \
    ,DEM_DTCS_INIT32(0x300075       )/*DemDTC_TPC_TSttrOvHiLimFail*/ \
    ,DEM_DTCS_INIT32(0x300076       )/*DemDTC_TPC_TSttrOvHiWarn*/ \
    ,DEM_DTCS_INIT32(0x300077       )/*DemDTC_TPC_TSttrOvLoWarn*/ \
    ,DEM_DTCS_INIT32(0x300078       )/*DemDTC_TPC_uDcLnkOvVLimFail*/ \
    ,DEM_DTCS_INIT32(0x300079       )/*DemDTC_TPC_uDcLnkOvWarn*/ \
    ,DEM_DTCS_INIT32(0x30007A       )/*DemDTC_TPC_uDcLnkUnVLimFail*/ \
    ,DEM_DTCS_INIT32(0x30007B       )/*DemDTC_TPC_uDcLnkUnvWarn*/ \
    ,DEM_DTCS_INIT32(0x30007C       )/*DemDTC_Cpld_Rx_SelfTest_Fail*/ \
    ,DEM_DTCS_INIT32(0x30007D       )/*DemDTC_HvMcu_UdcOverFlagLimit*/ \
}

/*                DTCGROUPCODE  */

#define DEM_CFG_DTCGROUPPARAMS \
{ \
    DEM_DTCGROUPS_INIT(0       )/* No DTCGROUP Assigned */ \
,DEM_DTCGROUPS_INIT(DEM_DTC_GROUP_ALL_DTCS) /* DEM_DTC_GROUP_ALL_DTCS */\
}

#define DEM_DTC_FILTER_NUMBER_OF_EVENTS_PER_CYCLE    25u
#define DEM_DTC_FILTER_RETRIEVE_NUMBER_OF_DTCS       50u

#define DEM_DTC_DTCSETTING_CALLBACK_SUPPORTED_OFF STD_OFF
#define DEM_DTC_DTCSETTING_CALLBACK_SUPPORTED_ON STD_ON

#define DEM_DTC_DTCSETTING_CALLBACK_SUPPORTED DEM_DTC_DTCSETTING_CALLBACK_SUPPORTED_OFF

#endif

