/*
 * File: SWC_CddDiagCalib.c
 *
 * Code generated for Simulink model 'SWC_CddDiagCalib'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Wed May 20 14:39:06 2020
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SWC_CddDiagCalib.h"
#include "SWC_CddDiagCalib_private.h"

/* user code (top of source file) */
#include "Dem_EventStatus.h"
#include "Dem_ClientClearMachine.h"
#include "FiM_Cfg_Fids.h"
#include "FiM.h"
#include "Dem.h"

/*******************************************************************************
**                          Macro Definition                                  **
*******************************************************************************/
#define EVENTENABLECON_EN 0
#define CLEAR_DISABLE 0

/*******************************************************************************
**                          Typedef Definition                                **
*******************************************************************************/


/*******************************************************************************
**                   Static Local Variables Definition                        **
*******************************************************************************/




/*******************************************************************************
**                     Global Variables Definition                            **
*******************************************************************************/
uint8  VAR_DEM_EvtFailedList_au8[NVM_CFG_NV_BLOCK_LENGTH_DEM_HistoryEventList]={0u};
uint8  VAR_DEM_EventList_au8[NVM_CFG_NV_BLOCK_LENGTH_DEM_HistoryEventList] = {0u};
uint8  VAR_DEM_AllEvtFailedList_au8[DEM_EVENTID_COUNT+1u]={0u};
uint8  VAR_DEM_FidTraceEvents_au8[DEM_EVENTID_COUNT]={0u};
uint8  VAR_DEM_HisEvtFailedList_au8[NVM_CFG_NV_BLOCK_LENGTH_DEM_HistoryEventList] = {0u};
uint8  VAR_DEM_AllFID_Statues_au8[FIM_CFG_NUMBEROFFIDS+1u]={0u};
uint8  VAR_DEM_EvtFailed_and_Passed_TOPC_au8[NVM_CFG_NV_BLOCK_LENGTH_DEM_HistoryEventList] = {0u};

uint32 DEM_FF_InputDTC_u32 =0u;
uint32 DEM_Clear_InputDTC_u32 =0u;
static uint8  DEM_EventIDRecorder_u8 = 0u;

/*********************FID******************************************************/
static uint8  FID_Failed_State_u8 =1u;
static uint8  VAR_DEM_FID_Failed_u8;
static uint8  DEM_StartOP_u8 = 0u;

/*********************Flag to FR******************************************************/
boolean EventFlag2FR_boolean = FALSE;

uint8 Dem_ClearTest_Flag_u8 = 0u;

/**********************DEM_Watch_VAR******************************/
Dem_EventStatusExtendedType     VAR_DEM_Event_ADC_UPhaseBISTFail_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_ADC_VPhaseBISTFail_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_ADC_WPhaseBISTFail_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_CANSM_E_BUS_OFF_NETWORK_0_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_CANSM_E_BUS_OFF_NETWORK_1_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_Can_Timeout_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_Cpld_AliveChkErr_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_Cpld_DI_ExdClk_InFail_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_Cpld_ExdClkInFail_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_Cpld_IphaOC_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_Cpld_NEN_InFail_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_Cpld_ParityChkErr_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_Cpld_Rx_SelfTest_Fail_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_Cpld_SPIComFail_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_Cpld_SZTKT_InFail_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_Cpld_Short_Circuit_HS_InFail_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_Cpld_Short_Circuit_LS_InFail_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_Cpld_UdcOverVolFail_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_Cpld_UnderVol_HS_InFail_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_Cpld_UnderVol_LS_InFail_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_Epark_OverCurFail_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_Epark_PosMonSampFail_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_Epark_PosSampFail_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_Epark_SampFail_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_Event_NvM_ReadErr_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_Event_NvM_WriteErr_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_FR_StorageErr_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_HSPF_InvOpenErr_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_HSPF_MotorOpenErr_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_HSPF_VerMatchFailureErr_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_HSPF_stIphaOffCalFail_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_HSPF_tDBCTempCmpErr_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_HvMcu_ComErr_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_HvMcu_DisChrgDutyErr_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_HvMcu_DisChrgFail_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_HvMcu_DisChrgFreqErr_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_HvMcu_EmerPowerSapErr_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_HvMcu_UartCheckFailErr_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_HvMcu_UartLostFrameErr_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_HvMcu_UdcCheckErr_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_HvMcu_UdcOverFlagLimit_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_HvMcu_UdcOverVolErr_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_IOHWAB_12VNarrSampErr_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_IOHWAB_12VSampErr_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_IOHWAB_12VWideSampErr_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_IOHWAB_18VLwBrgSampFail_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_IOHWAB_18VUpBrgSampFail_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_IOHWAB_1V3MCU_SampFail_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_IOHWAB_3V3MCU_SampFail_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_IOHWAB_5VQcoSampFail_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_IOHWAB_5VQt1SampFail_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_IOHWAB_5VQt2SampFail_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_IOHWAB_Cpld1v8SampFail_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_IOHWAB_Cpld3v3SampFail_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_IOHWAB_CrashFail_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_IOHWAB_DcLnkOverVolFail_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_IOHWAB_IphaOCFail_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_IOHWAB_KL30OverVolErr_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_IOHWAB_KL30SevOverVolFail_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_IOHWAB_KL30SevUnderVolFail_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_IOHWAB_KL30UnderVolErr_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_IOHWAB_Nen33Fail_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_IOHWAB_SttrSenorShrFail_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_IOHWAB_SttrTemp1SampFail_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_IOHWAB_SttrTemp2SampFail_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_IOHWAB_TCoolantSampFail_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_IOHWAB_VDD5_D_SampFail_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_IgbtDrv_ComErr_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_IgbtDrv_LwBrgFaultAFail_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_IgbtDrv_LwBrgFaultBFail_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_IgbtDrv_UpBrgFaultAFail_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_IgbtDrv_UpBrgFaultBFail_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_MDF_AlOfsNoPlausErr_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_MDF_DiashCirNoPsblErr_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_MDF_EmacBlkdErr_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_MDF_EmacBlkdWarn_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_MDF_ICtlRatErr_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_MDF_IsOvHiErr_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_MDF_OpenCirNoPsblErr_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_MDF_OperOutdRngErr_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_MDF_PhaseLossFaultErr_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_MDF_PrfElDrvErr_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_PCF_ActOvTiErr_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_PCF_IdcOvErr_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_PCF_SelfcheckErr_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_PCF_SenClbErr_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_PCF_SenOvErr_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_PCF_StallRetryErr_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_PCF_StallWarn_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_PCF_UnexpPosErr_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_RCF_AccOvTiErr_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_RCF_EstOfsErr_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_RCF_FwlBwdOvTiErr_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_RCF_FwlFwdOvTiErr_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_RCF_OfsClbFail_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_RCF_PsiOvErr_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_RSL_DOSErr_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_RSL_ExcErr_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_RSL_LOSErr_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_RSL_LOTErr_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_SCF_DisChgOvTiFail_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_SCF_LowPwrShtDwnOvTiFail_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_SCF_RunToDischarErr_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_TPC_SpdOvHiLimFail_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_TPC_SpdOvHiWarn_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_TPC_TCoolantOvHiWarn_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_TPC_TDbcOvHiWarn_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_TPC_TDbcOvLoWarn_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_TPC_TDbcUHiLimFail_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_TPC_TDbcULoLimFail_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_TPC_TDbcVHiLimFail_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_TPC_TDbcVLoLimFail_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_TPC_TDbcWHiLimFail_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_TPC_TDbcWLoLimFail_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_TPC_TDrvBoardOvHiWarn_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_TPC_TIGBTOvHiLimErr_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_TPC_TIGBTOvHiWarn_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_TPC_TIGBTOvLoWarn_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_TPC_TSttrOvHiLimFail_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_TPC_TSttrOvHiWarn_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_TPC_TSttrOvLoWarn_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_TPC_iDcLnkOvCLimFail_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_TPC_iDcLnkOvcWarn_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_TPC_uDcLnkOvVLimFail_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_TPC_uDcLnkOvWarn_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_TPC_uDcLnkUnVLimFail_Status_u8 = 0;
Dem_EventStatusExtendedType     VAR_DEM_Event_TPC_uDcLnkUnvWarn_Status_u8 = 0;


Dem_EventStatusExtendedType DEM_ALLEvent_Status_au8[DEM_EVENTID_COUNT+1u]={0};
Dem_EventStatusExtendedType DEM_AllEventDeb_State_au8[DEM_EVENTID_COUNT+1u]={0};

#pragma section ".rodata.Calib_32"
/**********************DEM_FID_Calib******************************/
const  volatile uint8 CAL_DEM_FIM_DFC_ADC_UPhaseBISTFail_au8[10] = {FiMConf_FiMFID_FIM_ReqFailrMod,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_ADC_VPhaseBISTFail_au8[10] = {FiMConf_FiMFID_FIM_ReqFailrMod,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_ADC_WPhaseBISTFail_au8[10] = {FiMConf_FiMFID_FIM_ReqFailrMod,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_CANSM_E_BUS_OFF_NETWORK_0_au8[10] = {FiMConf_FiMFID_FIM_ReqFailrMod,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_CANSM_E_BUS_OFF_NETWORK_1_au8[10] = {FiMConf_FiMFID_FIM_ReqFailrMod,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_Can_Timeout_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_Cpld_AliveChkErr_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_Cpld_DI_ExdClk_InFail_au8[10] = {FiMConf_FiMFID_FIM_ReqFailrMod,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_Cpld_ExdClkInFail_au8[10] = {FiMConf_FiMFID_FIM_ReqFailrMod,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_Cpld_IphaOC_au8[10] = {FiMConf_FiMFID_FIM_ReqFailrMod,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_Cpld_NEN_InFail_au8[10] = {FiMConf_FiMFID_FIM_ReqFailrMod,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_Cpld_ParityChkErr_au8[10] = {FiMConf_FiMFID_FIM_ReqFailrMod,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_Cpld_Rx_SelfTest_Fail_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_Cpld_SPIComFail_au8[10] = {FiMConf_FiMFID_FIM_ReqFailrMod,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_Cpld_SZTKT_InFail_au8[10] = {FiMConf_FiMFID_FIM_ReqFailrMod,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_Cpld_Short_Circuit_HS_InFail_au8[10] = {FiMConf_FiMFID_FIM_ReqFailrMod,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_Cpld_Short_Circuit_LS_InFail_au8[10] = {FiMConf_FiMFID_FIM_ReqFailrMod,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_Cpld_UdcOverVolFail_au8[10] = {FiMConf_FiMFID_FIM_ReqFailrMod,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_Cpld_UnderVol_HS_InFail_au8[10] = {FiMConf_FiMFID_FIM_ReqFailrMod,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_Cpld_UnderVol_LS_InFail_au8[10] = {FiMConf_FiMFID_FIM_ReqFailrMod,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_Epark_OverCurFail_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_Epark_PosMonSampFail_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_Epark_PosSampFail_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_Epark_SampFail_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_Event_NvM_ReadErr_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_Event_NvM_WriteErr_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_FR_StorageErr_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_HSPF_InvOpenErr_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_HSPF_MotorOpenErr_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_HSPF_VerMatchFailureErr_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_HSPF_stIphaOffCalFail_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_HSPF_tDBCTempCmpErr_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_HvMcu_ComErr_au8[10] = {FiMConf_FiMFID_FIM_ReqFailrMod,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_HvMcu_DisChrgDutyErr_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_HvMcu_DisChrgFail_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_HvMcu_DisChrgFreqErr_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_HvMcu_EmerPowerSapErr_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_HvMcu_UartCheckFailErr_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_HvMcu_UartLostFrameErr_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_HvMcu_UdcCheckErr_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_HvMcu_UdcOverFlagLimit_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_HvMcu_UdcOverVolErr_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_IOHWAB_12VNarrSampErr_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_IOHWAB_12VSampErr_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_IOHWAB_12VWideSampErr_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_IOHWAB_18VLwBrgSampFail_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_IOHWAB_18VUpBrgSampFail_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_IOHWAB_1V3MCU_SampFail_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_IOHWAB_3V3MCU_SampFail_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_IOHWAB_5VQcoSampFail_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_IOHWAB_5VQt1SampFail_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_IOHWAB_5VQt2SampFail_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_IOHWAB_Cpld1v8SampFail_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_IOHWAB_Cpld3v3SampFail_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_IOHWAB_CrashFail_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_IOHWAB_DcLnkOverVolFail_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_IOHWAB_IphaOCFail_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_IOHWAB_KL30OverVolErr_au8[10] = {FiMConf_FiMFID_FIM_ReqFailrMod,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_IOHWAB_KL30SevOverVolFail_au8[10] = {FiMConf_FiMFID_FIM_ReqFailrMod,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_IOHWAB_KL30SevUnderVolFail_au8[10] = {FiMConf_FiMFID_FIM_ReqFailrMod,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_IOHWAB_KL30UnderVolErr_au8[10] = {FiMConf_FiMFID_FIM_ReqFailrMod,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_IOHWAB_Nen33Fail_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_IOHWAB_SttrSenorShrFail_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_IOHWAB_SttrTemp1SampFail_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_IOHWAB_SttrTemp2SampFail_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_IOHWAB_TCoolantSampFail_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_IOHWAB_VDD5_D_SampFail_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_IgbtDrv_ComErr_au8[10] = {FiMConf_FiMFID_FIM_ReqFailrMod,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_IgbtDrv_LwBrgFaultAFail_au8[10] = {FiMConf_FiMFID_FIM_ReqFailrMod,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_IgbtDrv_LwBrgFaultBFail_au8[10] = {FiMConf_FiMFID_FIM_ReqFailrMod,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_IgbtDrv_UpBrgFaultAFail_au8[10] = {FiMConf_FiMFID_FIM_ReqFailrMod,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_IgbtDrv_UpBrgFaultBFail_au8[10] = {FiMConf_FiMFID_FIM_ReqFailrMod,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_MDF_AlOfsNoPlausErr_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_MDF_DiashCirNoPsblErr_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_MDF_EmacBlkdErr_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_MDF_EmacBlkdWarn_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_MDF_ICtlRatErr_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_MDF_IsOvHiErr_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_MDF_OpenCirNoPsblErr_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_MDF_OperOutdRngErr_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_MDF_PhaseLossFaultErr_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_MDF_PrfElDrvErr_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_PCF_ActOvTiErr_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_PCF_IdcOvErr_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_PCF_SelfcheckErr_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_PCF_SenClbErr_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_PCF_SenOvErr_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_PCF_StallRetryErr_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_PCF_StallWarn_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_PCF_UnexpPosErr_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_RCF_AccOvTiErr_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_RCF_EstOfsErr_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_RCF_FwlBwdOvTiErr_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_RCF_FwlFwdOvTiErr_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_RCF_OfsClbFail_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_RCF_PsiOvErr_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_RSL_DOSErr_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_RSL_ExcErr_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_RSL_LOSErr_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_RSL_LOTErr_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_SCF_DisChgOvTiFail_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_SCF_LowPwrShtDwnOvTiFail_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_SCF_RunToDischarErr_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_TPC_SpdOvHiLimFail_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_TPC_SpdOvHiWarn_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_TPC_TCoolantOvHiWarn_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_TPC_TDbcOvHiWarn_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_TPC_TDbcOvLoWarn_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_TPC_TDbcUHiLimFail_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_TPC_TDbcULoLimFail_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_TPC_TDbcVHiLimFail_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_TPC_TDbcVLoLimFail_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_TPC_TDbcWHiLimFail_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_TPC_TDbcWLoLimFail_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_TPC_TDrvBoardOvHiWarn_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_TPC_TIGBTOvHiLimErr_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_TPC_TIGBTOvHiWarn_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_TPC_TIGBTOvLoWarn_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_TPC_TSttrOvHiLimFail_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_TPC_TSttrOvHiWarn_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_TPC_TSttrOvLoWarn_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_TPC_iDcLnkOvCLimFail_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_TPC_iDcLnkOvcWarn_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_TPC_uDcLnkOvVLimFail_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_TPC_uDcLnkOvWarn_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_TPC_uDcLnkUnVLimFail_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};
const  volatile uint8 CAL_DEM_FIM_DFC_TPC_uDcLnkUnvWarn_au8[10] = {FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused,FiMConf_FiMFID_FIM_Unused};

/**********************Dem_Enable_Calib******************************/
const  volatile uint8 CAL_DEM_Disbl_DFC_ADC_UPhaseBISTFail_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_ADC_VPhaseBISTFail_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_ADC_WPhaseBISTFail_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_CANSM_E_BUS_OFF_NETWORK_0_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_CANSM_E_BUS_OFF_NETWORK_1_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_Can_Timeout_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_Cpld_AliveChkErr_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_Cpld_DI_ExdClk_InFail_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_Cpld_ExdClkInFail_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_Cpld_IphaOC_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_Cpld_NEN_InFail_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_Cpld_ParityChkErr_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_Cpld_Rx_SelfTest_Fail_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_Cpld_SPIComFail_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_Cpld_SZTKT_InFail_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_Cpld_Short_Circuit_HS_InFail_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_Cpld_Short_Circuit_LS_InFail_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_Cpld_UdcOverVolFail_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_Cpld_UnderVol_HS_InFail_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_Cpld_UnderVol_LS_InFail_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_Epark_OverCurFail_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_Epark_PosMonSampFail_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_Epark_PosSampFail_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_Epark_SampFail_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_Event_NvM_ReadErr_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_Event_NvM_WriteErr_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_FR_StorageErr_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_HSPF_InvOpenErr_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_HSPF_MotorOpenErr_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_HSPF_VerMatchFailureErr_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_HSPF_stIphaOffCalFail_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_HSPF_tDBCTempCmpErr_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_HvMcu_ComErr_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_HvMcu_DisChrgDutyErr_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_HvMcu_DisChrgFail_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_HvMcu_DisChrgFreqErr_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_HvMcu_EmerPowerSapErr_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_HvMcu_UartCheckFailErr_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_HvMcu_UartLostFrameErr_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_HvMcu_UdcCheckErr_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_HvMcu_UdcOverFlagLimit_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_HvMcu_UdcOverVolErr_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_IOHWAB_12VNarrSampErr_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_IOHWAB_12VSampErr_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_IOHWAB_12VWideSampErr_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_IOHWAB_18VLwBrgSampFail_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_IOHWAB_18VUpBrgSampFail_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_IOHWAB_1V3MCU_SampFail_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_IOHWAB_3V3MCU_SampFail_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_IOHWAB_5VQcoSampFail_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_IOHWAB_5VQt1SampFail_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_IOHWAB_5VQt2SampFail_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_IOHWAB_Cpld1v8SampFail_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_IOHWAB_Cpld3v3SampFail_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_IOHWAB_CrashFail_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_IOHWAB_DcLnkOverVolFail_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_IOHWAB_IphaOCFail_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_IOHWAB_KL30OverVolErr_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_IOHWAB_KL30SevOverVolFail_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_IOHWAB_KL30SevUnderVolFail_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_IOHWAB_KL30UnderVolErr_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_IOHWAB_Nen33Fail_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_IOHWAB_SttrSenorShrFail_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_IOHWAB_SttrTemp1SampFail_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_IOHWAB_SttrTemp2SampFail_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_IOHWAB_TCoolantSampFail_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_IOHWAB_VDD5_D_SampFail_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_IgbtDrv_ComErr_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_IgbtDrv_LwBrgFaultAFail_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_IgbtDrv_LwBrgFaultBFail_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_IgbtDrv_UpBrgFaultAFail_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_IgbtDrv_UpBrgFaultBFail_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_MDF_AlOfsNoPlausErr_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_MDF_DiashCirNoPsblErr_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_MDF_EmacBlkdErr_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_MDF_EmacBlkdWarn_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_MDF_ICtlRatErr_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_MDF_IsOvHiErr_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_MDF_OpenCirNoPsblErr_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_MDF_OperOutdRngErr_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_MDF_PhaseLossFaultErr_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_MDF_PrfElDrvErr_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_PCF_ActOvTiErr_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_PCF_IdcOvErr_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_PCF_SelfcheckErr_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_PCF_SenClbErr_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_PCF_SenOvErr_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_PCF_StallRetryErr_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_PCF_StallWarn_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_PCF_UnexpPosErr_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_RCF_AccOvTiErr_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_RCF_EstOfsErr_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_RCF_FwlBwdOvTiErr_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_RCF_FwlFwdOvTiErr_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_RCF_OfsClbFail_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_RCF_PsiOvErr_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_RSL_DOSErr_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_RSL_ExcErr_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_RSL_LOSErr_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_RSL_LOTErr_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_SCF_DisChgOvTiFail_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_SCF_LowPwrShtDwnOvTiFail_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_SCF_RunToDischarErr_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_TPC_SpdOvHiLimFail_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_TPC_SpdOvHiWarn_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_TPC_TCoolantOvHiWarn_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_TPC_TDbcOvHiWarn_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_TPC_TDbcOvLoWarn_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_TPC_TDbcUHiLimFail_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_TPC_TDbcULoLimFail_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_TPC_TDbcVHiLimFail_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_TPC_TDbcVLoLimFail_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_TPC_TDbcWHiLimFail_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_TPC_TDbcWLoLimFail_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_TPC_TDrvBoardOvHiWarn_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_TPC_TIGBTOvHiLimErr_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_TPC_TIGBTOvHiWarn_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_TPC_TIGBTOvLoWarn_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_TPC_TSttrOvHiLimFail_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_TPC_TSttrOvHiWarn_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_TPC_TSttrOvLoWarn_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_TPC_iDcLnkOvCLimFail_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_TPC_iDcLnkOvcWarn_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_TPC_uDcLnkOvVLimFail_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_TPC_uDcLnkOvWarn_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_TPC_uDcLnkUnVLimFail_u8  = EVENTENABLECON_EN;
const  volatile uint8 CAL_DEM_Disbl_DFC_TPC_uDcLnkUnvWarn_u8  = EVENTENABLECON_EN;

/**********************ClearAllDTC_Calib******************************/
const volatile uint8 CAL_DEM_Clear_DTC_Flag_u8 = CLEAR_DISABLE;
#pragma section

/*******************************************************************************
**                  Static Local Function Declaration                         **
*******************************************************************************/
static void DEM_EventState_Update(void);
static void FiM_EventFID_Update(void);
static void FiM_FIDList_Update(void);
static void DEM_Clear_DTC(void);
static void DEM_EventLists_Update(void);
static void DEM_SingleEventAndFidUpdate(void);

/*******************************************************************************
**                        Function Source Code                                **
*******************************************************************************/


/*******************************************************************************
** Function Name    : DEM_Clear_DTC
** Parameter[in]    : None
** Parameter[out]   : None
** Return Value     : None
** Note             : None
** Description      : Clear DTC information.
*******************************************************************************/
static void DEM_Clear_DTC(void)
{
    if ( (CAL_DEM_Clear_DTC_Flag_u8 == 1u ) || (Dem_ClearTest_Flag_u8 == 1u))
    {
        (void)Dem_DisableDTCSetting(DEM_DTC_GROUP_ALL_DTCS, DEM_DTC_KIND_ALL_DTCS);
    }
    else if((CAL_DEM_Clear_DTC_Flag_u8 == 2u ) || (Dem_ClearTest_Flag_u8 == 2u))
    {
        ClearDTC_User();
    }
    else if((CAL_DEM_Clear_DTC_Flag_u8 == 3u ) || (Dem_ClearTest_Flag_u8 == 3u))
    {
        (void)Dem_EnableDTCSetting(DEM_DTC_GROUP_ALL_DTCS, DEM_DTC_KIND_ALL_DTCS);
        Dem_ClearTest_Flag_u8 = 0u;
    }
    else
    {

    }
}

/*******************************************************************************
** Function Name    : DEM_Clear_DTC
** Parameter[in]    : None
** Parameter[out]   : None
** Return Value     : None
** Note             : None
** Description      : Clear DTC information.
*******************************************************************************/
static void DEM_EventState_Update(void)
{
    Dem_EventIdType i_EventID_NUM;
    for(i_EventID_NUM=1u;i_EventID_NUM<DEM_EVENTID_COUNT+1u;i_EventID_NUM++)
    {
        (void)Dem_GetEventStatus(i_EventID_NUM,&DEM_ALLEvent_Status_au8[i_EventID_NUM]);
    }
}

/*******************************************************************************
** Function Name    : FiM_EventFID_Update
** Parameter[in]    : None
** Parameter[out]   : None
** Return Value     : None
** Note             : None
** Description      : Update all FIDs which may be bonded to an event with calibration variable CAL_DEM_FIM_DFC_XXX_au8[i].
*******************************************************************************/
static void FiM_EventFID_Update(void)
{
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_ADC_UPhaseBISTFail)]=CAL_DEM_FIM_DFC_ADC_UPhaseBISTFail_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_ADC_UPhaseBISTFail)+1u]=CAL_DEM_FIM_DFC_ADC_UPhaseBISTFail_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_ADC_UPhaseBISTFail)+2u]=CAL_DEM_FIM_DFC_ADC_UPhaseBISTFail_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_ADC_UPhaseBISTFail)+3u]=CAL_DEM_FIM_DFC_ADC_UPhaseBISTFail_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_ADC_UPhaseBISTFail)+4u]=CAL_DEM_FIM_DFC_ADC_UPhaseBISTFail_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_ADC_UPhaseBISTFail)+5u]=CAL_DEM_FIM_DFC_ADC_UPhaseBISTFail_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_ADC_UPhaseBISTFail)+6u]=CAL_DEM_FIM_DFC_ADC_UPhaseBISTFail_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_ADC_UPhaseBISTFail)+7u]=CAL_DEM_FIM_DFC_ADC_UPhaseBISTFail_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_ADC_UPhaseBISTFail)+8u]=CAL_DEM_FIM_DFC_ADC_UPhaseBISTFail_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_ADC_UPhaseBISTFail)+9u]=CAL_DEM_FIM_DFC_ADC_UPhaseBISTFail_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_ADC_VPhaseBISTFail)]=CAL_DEM_FIM_DFC_ADC_VPhaseBISTFail_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_ADC_VPhaseBISTFail)+1u]=CAL_DEM_FIM_DFC_ADC_VPhaseBISTFail_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_ADC_VPhaseBISTFail)+2u]=CAL_DEM_FIM_DFC_ADC_VPhaseBISTFail_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_ADC_VPhaseBISTFail)+3u]=CAL_DEM_FIM_DFC_ADC_VPhaseBISTFail_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_ADC_VPhaseBISTFail)+4u]=CAL_DEM_FIM_DFC_ADC_VPhaseBISTFail_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_ADC_VPhaseBISTFail)+5u]=CAL_DEM_FIM_DFC_ADC_VPhaseBISTFail_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_ADC_VPhaseBISTFail)+6u]=CAL_DEM_FIM_DFC_ADC_VPhaseBISTFail_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_ADC_VPhaseBISTFail)+7u]=CAL_DEM_FIM_DFC_ADC_VPhaseBISTFail_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_ADC_VPhaseBISTFail)+8u]=CAL_DEM_FIM_DFC_ADC_VPhaseBISTFail_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_ADC_VPhaseBISTFail)+9u]=CAL_DEM_FIM_DFC_ADC_VPhaseBISTFail_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_ADC_WPhaseBISTFail)]=CAL_DEM_FIM_DFC_ADC_WPhaseBISTFail_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_ADC_WPhaseBISTFail)+1u]=CAL_DEM_FIM_DFC_ADC_WPhaseBISTFail_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_ADC_WPhaseBISTFail)+2u]=CAL_DEM_FIM_DFC_ADC_WPhaseBISTFail_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_ADC_WPhaseBISTFail)+3u]=CAL_DEM_FIM_DFC_ADC_WPhaseBISTFail_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_ADC_WPhaseBISTFail)+4u]=CAL_DEM_FIM_DFC_ADC_WPhaseBISTFail_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_ADC_WPhaseBISTFail)+5u]=CAL_DEM_FIM_DFC_ADC_WPhaseBISTFail_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_ADC_WPhaseBISTFail)+6u]=CAL_DEM_FIM_DFC_ADC_WPhaseBISTFail_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_ADC_WPhaseBISTFail)+7u]=CAL_DEM_FIM_DFC_ADC_WPhaseBISTFail_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_ADC_WPhaseBISTFail)+8u]=CAL_DEM_FIM_DFC_ADC_WPhaseBISTFail_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_ADC_WPhaseBISTFail)+9u]=CAL_DEM_FIM_DFC_ADC_WPhaseBISTFail_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_CANSM_E_BUS_OFF_NETWORK_0)]=CAL_DEM_FIM_DFC_CANSM_E_BUS_OFF_NETWORK_0_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_CANSM_E_BUS_OFF_NETWORK_0)+1u]=CAL_DEM_FIM_DFC_CANSM_E_BUS_OFF_NETWORK_0_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_CANSM_E_BUS_OFF_NETWORK_0)+2u]=CAL_DEM_FIM_DFC_CANSM_E_BUS_OFF_NETWORK_0_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_CANSM_E_BUS_OFF_NETWORK_0)+3u]=CAL_DEM_FIM_DFC_CANSM_E_BUS_OFF_NETWORK_0_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_CANSM_E_BUS_OFF_NETWORK_0)+4u]=CAL_DEM_FIM_DFC_CANSM_E_BUS_OFF_NETWORK_0_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_CANSM_E_BUS_OFF_NETWORK_0)+5u]=CAL_DEM_FIM_DFC_CANSM_E_BUS_OFF_NETWORK_0_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_CANSM_E_BUS_OFF_NETWORK_0)+6u]=CAL_DEM_FIM_DFC_CANSM_E_BUS_OFF_NETWORK_0_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_CANSM_E_BUS_OFF_NETWORK_0)+7u]=CAL_DEM_FIM_DFC_CANSM_E_BUS_OFF_NETWORK_0_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_CANSM_E_BUS_OFF_NETWORK_0)+8u]=CAL_DEM_FIM_DFC_CANSM_E_BUS_OFF_NETWORK_0_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_CANSM_E_BUS_OFF_NETWORK_0)+9u]=CAL_DEM_FIM_DFC_CANSM_E_BUS_OFF_NETWORK_0_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_CANSM_E_BUS_OFF_NETWORK_1)]=CAL_DEM_FIM_DFC_CANSM_E_BUS_OFF_NETWORK_1_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_CANSM_E_BUS_OFF_NETWORK_1)+1u]=CAL_DEM_FIM_DFC_CANSM_E_BUS_OFF_NETWORK_1_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_CANSM_E_BUS_OFF_NETWORK_1)+2u]=CAL_DEM_FIM_DFC_CANSM_E_BUS_OFF_NETWORK_1_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_CANSM_E_BUS_OFF_NETWORK_1)+3u]=CAL_DEM_FIM_DFC_CANSM_E_BUS_OFF_NETWORK_1_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_CANSM_E_BUS_OFF_NETWORK_1)+4u]=CAL_DEM_FIM_DFC_CANSM_E_BUS_OFF_NETWORK_1_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_CANSM_E_BUS_OFF_NETWORK_1)+5u]=CAL_DEM_FIM_DFC_CANSM_E_BUS_OFF_NETWORK_1_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_CANSM_E_BUS_OFF_NETWORK_1)+6u]=CAL_DEM_FIM_DFC_CANSM_E_BUS_OFF_NETWORK_1_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_CANSM_E_BUS_OFF_NETWORK_1)+7u]=CAL_DEM_FIM_DFC_CANSM_E_BUS_OFF_NETWORK_1_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_CANSM_E_BUS_OFF_NETWORK_1)+8u]=CAL_DEM_FIM_DFC_CANSM_E_BUS_OFF_NETWORK_1_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_CANSM_E_BUS_OFF_NETWORK_1)+9u]=CAL_DEM_FIM_DFC_CANSM_E_BUS_OFF_NETWORK_1_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Can_Timeout)]=CAL_DEM_FIM_DFC_Can_Timeout_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Can_Timeout)+1u]=CAL_DEM_FIM_DFC_Can_Timeout_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Can_Timeout)+2u]=CAL_DEM_FIM_DFC_Can_Timeout_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Can_Timeout)+3u]=CAL_DEM_FIM_DFC_Can_Timeout_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Can_Timeout)+4u]=CAL_DEM_FIM_DFC_Can_Timeout_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Can_Timeout)+5u]=CAL_DEM_FIM_DFC_Can_Timeout_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Can_Timeout)+6u]=CAL_DEM_FIM_DFC_Can_Timeout_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Can_Timeout)+7u]=CAL_DEM_FIM_DFC_Can_Timeout_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Can_Timeout)+8u]=CAL_DEM_FIM_DFC_Can_Timeout_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Can_Timeout)+9u]=CAL_DEM_FIM_DFC_Can_Timeout_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_AliveChkErr)]=CAL_DEM_FIM_DFC_Cpld_AliveChkErr_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_AliveChkErr)+1u]=CAL_DEM_FIM_DFC_Cpld_AliveChkErr_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_AliveChkErr)+2u]=CAL_DEM_FIM_DFC_Cpld_AliveChkErr_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_AliveChkErr)+3u]=CAL_DEM_FIM_DFC_Cpld_AliveChkErr_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_AliveChkErr)+4u]=CAL_DEM_FIM_DFC_Cpld_AliveChkErr_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_AliveChkErr)+5u]=CAL_DEM_FIM_DFC_Cpld_AliveChkErr_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_AliveChkErr)+6u]=CAL_DEM_FIM_DFC_Cpld_AliveChkErr_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_AliveChkErr)+7u]=CAL_DEM_FIM_DFC_Cpld_AliveChkErr_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_AliveChkErr)+8u]=CAL_DEM_FIM_DFC_Cpld_AliveChkErr_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_AliveChkErr)+9u]=CAL_DEM_FIM_DFC_Cpld_AliveChkErr_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_DI_ExdClk_InFail)]=CAL_DEM_FIM_DFC_Cpld_DI_ExdClk_InFail_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_DI_ExdClk_InFail)+1u]=CAL_DEM_FIM_DFC_Cpld_DI_ExdClk_InFail_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_DI_ExdClk_InFail)+2u]=CAL_DEM_FIM_DFC_Cpld_DI_ExdClk_InFail_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_DI_ExdClk_InFail)+3u]=CAL_DEM_FIM_DFC_Cpld_DI_ExdClk_InFail_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_DI_ExdClk_InFail)+4u]=CAL_DEM_FIM_DFC_Cpld_DI_ExdClk_InFail_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_DI_ExdClk_InFail)+5u]=CAL_DEM_FIM_DFC_Cpld_DI_ExdClk_InFail_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_DI_ExdClk_InFail)+6u]=CAL_DEM_FIM_DFC_Cpld_DI_ExdClk_InFail_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_DI_ExdClk_InFail)+7u]=CAL_DEM_FIM_DFC_Cpld_DI_ExdClk_InFail_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_DI_ExdClk_InFail)+8u]=CAL_DEM_FIM_DFC_Cpld_DI_ExdClk_InFail_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_DI_ExdClk_InFail)+9u]=CAL_DEM_FIM_DFC_Cpld_DI_ExdClk_InFail_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_ExdClkInFail)]=CAL_DEM_FIM_DFC_Cpld_ExdClkInFail_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_ExdClkInFail)+1u]=CAL_DEM_FIM_DFC_Cpld_ExdClkInFail_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_ExdClkInFail)+2u]=CAL_DEM_FIM_DFC_Cpld_ExdClkInFail_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_ExdClkInFail)+3u]=CAL_DEM_FIM_DFC_Cpld_ExdClkInFail_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_ExdClkInFail)+4u]=CAL_DEM_FIM_DFC_Cpld_ExdClkInFail_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_ExdClkInFail)+5u]=CAL_DEM_FIM_DFC_Cpld_ExdClkInFail_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_ExdClkInFail)+6u]=CAL_DEM_FIM_DFC_Cpld_ExdClkInFail_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_ExdClkInFail)+7u]=CAL_DEM_FIM_DFC_Cpld_ExdClkInFail_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_ExdClkInFail)+8u]=CAL_DEM_FIM_DFC_Cpld_ExdClkInFail_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_ExdClkInFail)+9u]=CAL_DEM_FIM_DFC_Cpld_ExdClkInFail_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_IphaOC)]=CAL_DEM_FIM_DFC_Cpld_IphaOC_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_IphaOC)+1u]=CAL_DEM_FIM_DFC_Cpld_IphaOC_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_IphaOC)+2u]=CAL_DEM_FIM_DFC_Cpld_IphaOC_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_IphaOC)+3u]=CAL_DEM_FIM_DFC_Cpld_IphaOC_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_IphaOC)+4u]=CAL_DEM_FIM_DFC_Cpld_IphaOC_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_IphaOC)+5u]=CAL_DEM_FIM_DFC_Cpld_IphaOC_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_IphaOC)+6u]=CAL_DEM_FIM_DFC_Cpld_IphaOC_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_IphaOC)+7u]=CAL_DEM_FIM_DFC_Cpld_IphaOC_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_IphaOC)+8u]=CAL_DEM_FIM_DFC_Cpld_IphaOC_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_IphaOC)+9u]=CAL_DEM_FIM_DFC_Cpld_IphaOC_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_NEN_InFail)]=CAL_DEM_FIM_DFC_Cpld_NEN_InFail_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_NEN_InFail)+1u]=CAL_DEM_FIM_DFC_Cpld_NEN_InFail_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_NEN_InFail)+2u]=CAL_DEM_FIM_DFC_Cpld_NEN_InFail_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_NEN_InFail)+3u]=CAL_DEM_FIM_DFC_Cpld_NEN_InFail_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_NEN_InFail)+4u]=CAL_DEM_FIM_DFC_Cpld_NEN_InFail_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_NEN_InFail)+5u]=CAL_DEM_FIM_DFC_Cpld_NEN_InFail_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_NEN_InFail)+6u]=CAL_DEM_FIM_DFC_Cpld_NEN_InFail_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_NEN_InFail)+7u]=CAL_DEM_FIM_DFC_Cpld_NEN_InFail_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_NEN_InFail)+8u]=CAL_DEM_FIM_DFC_Cpld_NEN_InFail_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_NEN_InFail)+9u]=CAL_DEM_FIM_DFC_Cpld_NEN_InFail_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_ParityChkErr)]=CAL_DEM_FIM_DFC_Cpld_ParityChkErr_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_ParityChkErr)+1u]=CAL_DEM_FIM_DFC_Cpld_ParityChkErr_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_ParityChkErr)+2u]=CAL_DEM_FIM_DFC_Cpld_ParityChkErr_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_ParityChkErr)+3u]=CAL_DEM_FIM_DFC_Cpld_ParityChkErr_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_ParityChkErr)+4u]=CAL_DEM_FIM_DFC_Cpld_ParityChkErr_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_ParityChkErr)+5u]=CAL_DEM_FIM_DFC_Cpld_ParityChkErr_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_ParityChkErr)+6u]=CAL_DEM_FIM_DFC_Cpld_ParityChkErr_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_ParityChkErr)+7u]=CAL_DEM_FIM_DFC_Cpld_ParityChkErr_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_ParityChkErr)+8u]=CAL_DEM_FIM_DFC_Cpld_ParityChkErr_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_ParityChkErr)+9u]=CAL_DEM_FIM_DFC_Cpld_ParityChkErr_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_Rx_SelfTest_Fail)]=CAL_DEM_FIM_DFC_Cpld_Rx_SelfTest_Fail_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_Rx_SelfTest_Fail)+1u]=CAL_DEM_FIM_DFC_Cpld_Rx_SelfTest_Fail_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_Rx_SelfTest_Fail)+2u]=CAL_DEM_FIM_DFC_Cpld_Rx_SelfTest_Fail_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_Rx_SelfTest_Fail)+3u]=CAL_DEM_FIM_DFC_Cpld_Rx_SelfTest_Fail_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_Rx_SelfTest_Fail)+4u]=CAL_DEM_FIM_DFC_Cpld_Rx_SelfTest_Fail_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_Rx_SelfTest_Fail)+5u]=CAL_DEM_FIM_DFC_Cpld_Rx_SelfTest_Fail_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_Rx_SelfTest_Fail)+6u]=CAL_DEM_FIM_DFC_Cpld_Rx_SelfTest_Fail_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_Rx_SelfTest_Fail)+7u]=CAL_DEM_FIM_DFC_Cpld_Rx_SelfTest_Fail_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_Rx_SelfTest_Fail)+8u]=CAL_DEM_FIM_DFC_Cpld_Rx_SelfTest_Fail_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_Rx_SelfTest_Fail)+9u]=CAL_DEM_FIM_DFC_Cpld_Rx_SelfTest_Fail_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_SPIComFail)]=CAL_DEM_FIM_DFC_Cpld_SPIComFail_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_SPIComFail)+1u]=CAL_DEM_FIM_DFC_Cpld_SPIComFail_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_SPIComFail)+2u]=CAL_DEM_FIM_DFC_Cpld_SPIComFail_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_SPIComFail)+3u]=CAL_DEM_FIM_DFC_Cpld_SPIComFail_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_SPIComFail)+4u]=CAL_DEM_FIM_DFC_Cpld_SPIComFail_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_SPIComFail)+5u]=CAL_DEM_FIM_DFC_Cpld_SPIComFail_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_SPIComFail)+6u]=CAL_DEM_FIM_DFC_Cpld_SPIComFail_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_SPIComFail)+7u]=CAL_DEM_FIM_DFC_Cpld_SPIComFail_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_SPIComFail)+8u]=CAL_DEM_FIM_DFC_Cpld_SPIComFail_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_SPIComFail)+9u]=CAL_DEM_FIM_DFC_Cpld_SPIComFail_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_SZTKT_InFail)]=CAL_DEM_FIM_DFC_Cpld_SZTKT_InFail_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_SZTKT_InFail)+1u]=CAL_DEM_FIM_DFC_Cpld_SZTKT_InFail_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_SZTKT_InFail)+2u]=CAL_DEM_FIM_DFC_Cpld_SZTKT_InFail_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_SZTKT_InFail)+3u]=CAL_DEM_FIM_DFC_Cpld_SZTKT_InFail_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_SZTKT_InFail)+4u]=CAL_DEM_FIM_DFC_Cpld_SZTKT_InFail_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_SZTKT_InFail)+5u]=CAL_DEM_FIM_DFC_Cpld_SZTKT_InFail_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_SZTKT_InFail)+6u]=CAL_DEM_FIM_DFC_Cpld_SZTKT_InFail_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_SZTKT_InFail)+7u]=CAL_DEM_FIM_DFC_Cpld_SZTKT_InFail_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_SZTKT_InFail)+8u]=CAL_DEM_FIM_DFC_Cpld_SZTKT_InFail_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_SZTKT_InFail)+9u]=CAL_DEM_FIM_DFC_Cpld_SZTKT_InFail_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_Short_Circuit_HS_InFail)]=CAL_DEM_FIM_DFC_Cpld_Short_Circuit_HS_InFail_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_Short_Circuit_HS_InFail)+1u]=CAL_DEM_FIM_DFC_Cpld_Short_Circuit_HS_InFail_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_Short_Circuit_HS_InFail)+2u]=CAL_DEM_FIM_DFC_Cpld_Short_Circuit_HS_InFail_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_Short_Circuit_HS_InFail)+3u]=CAL_DEM_FIM_DFC_Cpld_Short_Circuit_HS_InFail_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_Short_Circuit_HS_InFail)+4u]=CAL_DEM_FIM_DFC_Cpld_Short_Circuit_HS_InFail_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_Short_Circuit_HS_InFail)+5u]=CAL_DEM_FIM_DFC_Cpld_Short_Circuit_HS_InFail_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_Short_Circuit_HS_InFail)+6u]=CAL_DEM_FIM_DFC_Cpld_Short_Circuit_HS_InFail_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_Short_Circuit_HS_InFail)+7u]=CAL_DEM_FIM_DFC_Cpld_Short_Circuit_HS_InFail_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_Short_Circuit_HS_InFail)+8u]=CAL_DEM_FIM_DFC_Cpld_Short_Circuit_HS_InFail_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_Short_Circuit_HS_InFail)+9u]=CAL_DEM_FIM_DFC_Cpld_Short_Circuit_HS_InFail_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_Short_Circuit_LS_InFail)]=CAL_DEM_FIM_DFC_Cpld_Short_Circuit_LS_InFail_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_Short_Circuit_LS_InFail)+1u]=CAL_DEM_FIM_DFC_Cpld_Short_Circuit_LS_InFail_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_Short_Circuit_LS_InFail)+2u]=CAL_DEM_FIM_DFC_Cpld_Short_Circuit_LS_InFail_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_Short_Circuit_LS_InFail)+3u]=CAL_DEM_FIM_DFC_Cpld_Short_Circuit_LS_InFail_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_Short_Circuit_LS_InFail)+4u]=CAL_DEM_FIM_DFC_Cpld_Short_Circuit_LS_InFail_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_Short_Circuit_LS_InFail)+5u]=CAL_DEM_FIM_DFC_Cpld_Short_Circuit_LS_InFail_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_Short_Circuit_LS_InFail)+6u]=CAL_DEM_FIM_DFC_Cpld_Short_Circuit_LS_InFail_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_Short_Circuit_LS_InFail)+7u]=CAL_DEM_FIM_DFC_Cpld_Short_Circuit_LS_InFail_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_Short_Circuit_LS_InFail)+8u]=CAL_DEM_FIM_DFC_Cpld_Short_Circuit_LS_InFail_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_Short_Circuit_LS_InFail)+9u]=CAL_DEM_FIM_DFC_Cpld_Short_Circuit_LS_InFail_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_UdcOverVolFail)]=CAL_DEM_FIM_DFC_Cpld_UdcOverVolFail_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_UdcOverVolFail)+1u]=CAL_DEM_FIM_DFC_Cpld_UdcOverVolFail_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_UdcOverVolFail)+2u]=CAL_DEM_FIM_DFC_Cpld_UdcOverVolFail_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_UdcOverVolFail)+3u]=CAL_DEM_FIM_DFC_Cpld_UdcOverVolFail_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_UdcOverVolFail)+4u]=CAL_DEM_FIM_DFC_Cpld_UdcOverVolFail_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_UdcOverVolFail)+5u]=CAL_DEM_FIM_DFC_Cpld_UdcOverVolFail_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_UdcOverVolFail)+6u]=CAL_DEM_FIM_DFC_Cpld_UdcOverVolFail_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_UdcOverVolFail)+7u]=CAL_DEM_FIM_DFC_Cpld_UdcOverVolFail_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_UdcOverVolFail)+8u]=CAL_DEM_FIM_DFC_Cpld_UdcOverVolFail_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_UdcOverVolFail)+9u]=CAL_DEM_FIM_DFC_Cpld_UdcOverVolFail_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_UnderVol_HS_InFail)]=CAL_DEM_FIM_DFC_Cpld_UnderVol_HS_InFail_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_UnderVol_HS_InFail)+1u]=CAL_DEM_FIM_DFC_Cpld_UnderVol_HS_InFail_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_UnderVol_HS_InFail)+2u]=CAL_DEM_FIM_DFC_Cpld_UnderVol_HS_InFail_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_UnderVol_HS_InFail)+3u]=CAL_DEM_FIM_DFC_Cpld_UnderVol_HS_InFail_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_UnderVol_HS_InFail)+4u]=CAL_DEM_FIM_DFC_Cpld_UnderVol_HS_InFail_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_UnderVol_HS_InFail)+5u]=CAL_DEM_FIM_DFC_Cpld_UnderVol_HS_InFail_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_UnderVol_HS_InFail)+6u]=CAL_DEM_FIM_DFC_Cpld_UnderVol_HS_InFail_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_UnderVol_HS_InFail)+7u]=CAL_DEM_FIM_DFC_Cpld_UnderVol_HS_InFail_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_UnderVol_HS_InFail)+8u]=CAL_DEM_FIM_DFC_Cpld_UnderVol_HS_InFail_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_UnderVol_HS_InFail)+9u]=CAL_DEM_FIM_DFC_Cpld_UnderVol_HS_InFail_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_UnderVol_LS_InFail)]=CAL_DEM_FIM_DFC_Cpld_UnderVol_LS_InFail_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_UnderVol_LS_InFail)+1u]=CAL_DEM_FIM_DFC_Cpld_UnderVol_LS_InFail_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_UnderVol_LS_InFail)+2u]=CAL_DEM_FIM_DFC_Cpld_UnderVol_LS_InFail_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_UnderVol_LS_InFail)+3u]=CAL_DEM_FIM_DFC_Cpld_UnderVol_LS_InFail_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_UnderVol_LS_InFail)+4u]=CAL_DEM_FIM_DFC_Cpld_UnderVol_LS_InFail_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_UnderVol_LS_InFail)+5u]=CAL_DEM_FIM_DFC_Cpld_UnderVol_LS_InFail_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_UnderVol_LS_InFail)+6u]=CAL_DEM_FIM_DFC_Cpld_UnderVol_LS_InFail_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_UnderVol_LS_InFail)+7u]=CAL_DEM_FIM_DFC_Cpld_UnderVol_LS_InFail_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_UnderVol_LS_InFail)+8u]=CAL_DEM_FIM_DFC_Cpld_UnderVol_LS_InFail_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Cpld_UnderVol_LS_InFail)+9u]=CAL_DEM_FIM_DFC_Cpld_UnderVol_LS_InFail_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Epark_OverCurFail)]=CAL_DEM_FIM_DFC_Epark_OverCurFail_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Epark_OverCurFail)+1u]=CAL_DEM_FIM_DFC_Epark_OverCurFail_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Epark_OverCurFail)+2u]=CAL_DEM_FIM_DFC_Epark_OverCurFail_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Epark_OverCurFail)+3u]=CAL_DEM_FIM_DFC_Epark_OverCurFail_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Epark_OverCurFail)+4u]=CAL_DEM_FIM_DFC_Epark_OverCurFail_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Epark_OverCurFail)+5u]=CAL_DEM_FIM_DFC_Epark_OverCurFail_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Epark_OverCurFail)+6u]=CAL_DEM_FIM_DFC_Epark_OverCurFail_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Epark_OverCurFail)+7u]=CAL_DEM_FIM_DFC_Epark_OverCurFail_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Epark_OverCurFail)+8u]=CAL_DEM_FIM_DFC_Epark_OverCurFail_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Epark_OverCurFail)+9u]=CAL_DEM_FIM_DFC_Epark_OverCurFail_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Epark_PosMonSampFail)]=CAL_DEM_FIM_DFC_Epark_PosMonSampFail_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Epark_PosMonSampFail)+1u]=CAL_DEM_FIM_DFC_Epark_PosMonSampFail_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Epark_PosMonSampFail)+2u]=CAL_DEM_FIM_DFC_Epark_PosMonSampFail_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Epark_PosMonSampFail)+3u]=CAL_DEM_FIM_DFC_Epark_PosMonSampFail_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Epark_PosMonSampFail)+4u]=CAL_DEM_FIM_DFC_Epark_PosMonSampFail_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Epark_PosMonSampFail)+5u]=CAL_DEM_FIM_DFC_Epark_PosMonSampFail_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Epark_PosMonSampFail)+6u]=CAL_DEM_FIM_DFC_Epark_PosMonSampFail_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Epark_PosMonSampFail)+7u]=CAL_DEM_FIM_DFC_Epark_PosMonSampFail_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Epark_PosMonSampFail)+8u]=CAL_DEM_FIM_DFC_Epark_PosMonSampFail_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Epark_PosMonSampFail)+9u]=CAL_DEM_FIM_DFC_Epark_PosMonSampFail_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Epark_PosSampFail)]=CAL_DEM_FIM_DFC_Epark_PosSampFail_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Epark_PosSampFail)+1u]=CAL_DEM_FIM_DFC_Epark_PosSampFail_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Epark_PosSampFail)+2u]=CAL_DEM_FIM_DFC_Epark_PosSampFail_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Epark_PosSampFail)+3u]=CAL_DEM_FIM_DFC_Epark_PosSampFail_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Epark_PosSampFail)+4u]=CAL_DEM_FIM_DFC_Epark_PosSampFail_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Epark_PosSampFail)+5u]=CAL_DEM_FIM_DFC_Epark_PosSampFail_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Epark_PosSampFail)+6u]=CAL_DEM_FIM_DFC_Epark_PosSampFail_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Epark_PosSampFail)+7u]=CAL_DEM_FIM_DFC_Epark_PosSampFail_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Epark_PosSampFail)+8u]=CAL_DEM_FIM_DFC_Epark_PosSampFail_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Epark_PosSampFail)+9u]=CAL_DEM_FIM_DFC_Epark_PosSampFail_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Epark_SampFail)]=CAL_DEM_FIM_DFC_Epark_SampFail_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Epark_SampFail)+1u]=CAL_DEM_FIM_DFC_Epark_SampFail_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Epark_SampFail)+2u]=CAL_DEM_FIM_DFC_Epark_SampFail_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Epark_SampFail)+3u]=CAL_DEM_FIM_DFC_Epark_SampFail_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Epark_SampFail)+4u]=CAL_DEM_FIM_DFC_Epark_SampFail_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Epark_SampFail)+5u]=CAL_DEM_FIM_DFC_Epark_SampFail_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Epark_SampFail)+6u]=CAL_DEM_FIM_DFC_Epark_SampFail_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Epark_SampFail)+7u]=CAL_DEM_FIM_DFC_Epark_SampFail_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Epark_SampFail)+8u]=CAL_DEM_FIM_DFC_Epark_SampFail_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Epark_SampFail)+9u]=CAL_DEM_FIM_DFC_Epark_SampFail_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Event_NvM_ReadErr)]=CAL_DEM_FIM_DFC_Event_NvM_ReadErr_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Event_NvM_ReadErr)+1u]=CAL_DEM_FIM_DFC_Event_NvM_ReadErr_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Event_NvM_ReadErr)+2u]=CAL_DEM_FIM_DFC_Event_NvM_ReadErr_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Event_NvM_ReadErr)+3u]=CAL_DEM_FIM_DFC_Event_NvM_ReadErr_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Event_NvM_ReadErr)+4u]=CAL_DEM_FIM_DFC_Event_NvM_ReadErr_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Event_NvM_ReadErr)+5u]=CAL_DEM_FIM_DFC_Event_NvM_ReadErr_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Event_NvM_ReadErr)+6u]=CAL_DEM_FIM_DFC_Event_NvM_ReadErr_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Event_NvM_ReadErr)+7u]=CAL_DEM_FIM_DFC_Event_NvM_ReadErr_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Event_NvM_ReadErr)+8u]=CAL_DEM_FIM_DFC_Event_NvM_ReadErr_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Event_NvM_ReadErr)+9u]=CAL_DEM_FIM_DFC_Event_NvM_ReadErr_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Event_NvM_WriteErr)]=CAL_DEM_FIM_DFC_Event_NvM_WriteErr_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Event_NvM_WriteErr)+1u]=CAL_DEM_FIM_DFC_Event_NvM_WriteErr_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Event_NvM_WriteErr)+2u]=CAL_DEM_FIM_DFC_Event_NvM_WriteErr_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Event_NvM_WriteErr)+3u]=CAL_DEM_FIM_DFC_Event_NvM_WriteErr_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Event_NvM_WriteErr)+4u]=CAL_DEM_FIM_DFC_Event_NvM_WriteErr_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Event_NvM_WriteErr)+5u]=CAL_DEM_FIM_DFC_Event_NvM_WriteErr_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Event_NvM_WriteErr)+6u]=CAL_DEM_FIM_DFC_Event_NvM_WriteErr_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Event_NvM_WriteErr)+7u]=CAL_DEM_FIM_DFC_Event_NvM_WriteErr_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Event_NvM_WriteErr)+8u]=CAL_DEM_FIM_DFC_Event_NvM_WriteErr_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_Event_NvM_WriteErr)+9u]=CAL_DEM_FIM_DFC_Event_NvM_WriteErr_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_FR_StorageErr)]=CAL_DEM_FIM_DFC_FR_StorageErr_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_FR_StorageErr)+1u]=CAL_DEM_FIM_DFC_FR_StorageErr_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_FR_StorageErr)+2u]=CAL_DEM_FIM_DFC_FR_StorageErr_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_FR_StorageErr)+3u]=CAL_DEM_FIM_DFC_FR_StorageErr_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_FR_StorageErr)+4u]=CAL_DEM_FIM_DFC_FR_StorageErr_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_FR_StorageErr)+5u]=CAL_DEM_FIM_DFC_FR_StorageErr_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_FR_StorageErr)+6u]=CAL_DEM_FIM_DFC_FR_StorageErr_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_FR_StorageErr)+7u]=CAL_DEM_FIM_DFC_FR_StorageErr_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_FR_StorageErr)+8u]=CAL_DEM_FIM_DFC_FR_StorageErr_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_FR_StorageErr)+9u]=CAL_DEM_FIM_DFC_FR_StorageErr_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HSPF_InvOpenErr)]=CAL_DEM_FIM_DFC_HSPF_InvOpenErr_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HSPF_InvOpenErr)+1u]=CAL_DEM_FIM_DFC_HSPF_InvOpenErr_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HSPF_InvOpenErr)+2u]=CAL_DEM_FIM_DFC_HSPF_InvOpenErr_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HSPF_InvOpenErr)+3u]=CAL_DEM_FIM_DFC_HSPF_InvOpenErr_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HSPF_InvOpenErr)+4u]=CAL_DEM_FIM_DFC_HSPF_InvOpenErr_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HSPF_InvOpenErr)+5u]=CAL_DEM_FIM_DFC_HSPF_InvOpenErr_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HSPF_InvOpenErr)+6u]=CAL_DEM_FIM_DFC_HSPF_InvOpenErr_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HSPF_InvOpenErr)+7u]=CAL_DEM_FIM_DFC_HSPF_InvOpenErr_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HSPF_InvOpenErr)+8u]=CAL_DEM_FIM_DFC_HSPF_InvOpenErr_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HSPF_InvOpenErr)+9u]=CAL_DEM_FIM_DFC_HSPF_InvOpenErr_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HSPF_MotorOpenErr)]=CAL_DEM_FIM_DFC_HSPF_MotorOpenErr_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HSPF_MotorOpenErr)+1u]=CAL_DEM_FIM_DFC_HSPF_MotorOpenErr_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HSPF_MotorOpenErr)+2u]=CAL_DEM_FIM_DFC_HSPF_MotorOpenErr_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HSPF_MotorOpenErr)+3u]=CAL_DEM_FIM_DFC_HSPF_MotorOpenErr_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HSPF_MotorOpenErr)+4u]=CAL_DEM_FIM_DFC_HSPF_MotorOpenErr_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HSPF_MotorOpenErr)+5u]=CAL_DEM_FIM_DFC_HSPF_MotorOpenErr_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HSPF_MotorOpenErr)+6u]=CAL_DEM_FIM_DFC_HSPF_MotorOpenErr_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HSPF_MotorOpenErr)+7u]=CAL_DEM_FIM_DFC_HSPF_MotorOpenErr_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HSPF_MotorOpenErr)+8u]=CAL_DEM_FIM_DFC_HSPF_MotorOpenErr_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HSPF_MotorOpenErr)+9u]=CAL_DEM_FIM_DFC_HSPF_MotorOpenErr_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HSPF_VerMatchFailureErr)]=CAL_DEM_FIM_DFC_HSPF_VerMatchFailureErr_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HSPF_VerMatchFailureErr)+1u]=CAL_DEM_FIM_DFC_HSPF_VerMatchFailureErr_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HSPF_VerMatchFailureErr)+2u]=CAL_DEM_FIM_DFC_HSPF_VerMatchFailureErr_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HSPF_VerMatchFailureErr)+3u]=CAL_DEM_FIM_DFC_HSPF_VerMatchFailureErr_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HSPF_VerMatchFailureErr)+4u]=CAL_DEM_FIM_DFC_HSPF_VerMatchFailureErr_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HSPF_VerMatchFailureErr)+5u]=CAL_DEM_FIM_DFC_HSPF_VerMatchFailureErr_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HSPF_VerMatchFailureErr)+6u]=CAL_DEM_FIM_DFC_HSPF_VerMatchFailureErr_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HSPF_VerMatchFailureErr)+7u]=CAL_DEM_FIM_DFC_HSPF_VerMatchFailureErr_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HSPF_VerMatchFailureErr)+8u]=CAL_DEM_FIM_DFC_HSPF_VerMatchFailureErr_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HSPF_VerMatchFailureErr)+9u]=CAL_DEM_FIM_DFC_HSPF_VerMatchFailureErr_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HSPF_stIphaOffCalFail)]=CAL_DEM_FIM_DFC_HSPF_stIphaOffCalFail_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HSPF_stIphaOffCalFail)+1u]=CAL_DEM_FIM_DFC_HSPF_stIphaOffCalFail_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HSPF_stIphaOffCalFail)+2u]=CAL_DEM_FIM_DFC_HSPF_stIphaOffCalFail_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HSPF_stIphaOffCalFail)+3u]=CAL_DEM_FIM_DFC_HSPF_stIphaOffCalFail_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HSPF_stIphaOffCalFail)+4u]=CAL_DEM_FIM_DFC_HSPF_stIphaOffCalFail_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HSPF_stIphaOffCalFail)+5u]=CAL_DEM_FIM_DFC_HSPF_stIphaOffCalFail_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HSPF_stIphaOffCalFail)+6u]=CAL_DEM_FIM_DFC_HSPF_stIphaOffCalFail_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HSPF_stIphaOffCalFail)+7u]=CAL_DEM_FIM_DFC_HSPF_stIphaOffCalFail_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HSPF_stIphaOffCalFail)+8u]=CAL_DEM_FIM_DFC_HSPF_stIphaOffCalFail_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HSPF_stIphaOffCalFail)+9u]=CAL_DEM_FIM_DFC_HSPF_stIphaOffCalFail_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HSPF_tDBCTempCmpErr)]=CAL_DEM_FIM_DFC_HSPF_tDBCTempCmpErr_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HSPF_tDBCTempCmpErr)+1u]=CAL_DEM_FIM_DFC_HSPF_tDBCTempCmpErr_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HSPF_tDBCTempCmpErr)+2u]=CAL_DEM_FIM_DFC_HSPF_tDBCTempCmpErr_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HSPF_tDBCTempCmpErr)+3u]=CAL_DEM_FIM_DFC_HSPF_tDBCTempCmpErr_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HSPF_tDBCTempCmpErr)+4u]=CAL_DEM_FIM_DFC_HSPF_tDBCTempCmpErr_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HSPF_tDBCTempCmpErr)+5u]=CAL_DEM_FIM_DFC_HSPF_tDBCTempCmpErr_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HSPF_tDBCTempCmpErr)+6u]=CAL_DEM_FIM_DFC_HSPF_tDBCTempCmpErr_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HSPF_tDBCTempCmpErr)+7u]=CAL_DEM_FIM_DFC_HSPF_tDBCTempCmpErr_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HSPF_tDBCTempCmpErr)+8u]=CAL_DEM_FIM_DFC_HSPF_tDBCTempCmpErr_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HSPF_tDBCTempCmpErr)+9u]=CAL_DEM_FIM_DFC_HSPF_tDBCTempCmpErr_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_ComErr)]=CAL_DEM_FIM_DFC_HvMcu_ComErr_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_ComErr)+1u]=CAL_DEM_FIM_DFC_HvMcu_ComErr_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_ComErr)+2u]=CAL_DEM_FIM_DFC_HvMcu_ComErr_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_ComErr)+3u]=CAL_DEM_FIM_DFC_HvMcu_ComErr_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_ComErr)+4u]=CAL_DEM_FIM_DFC_HvMcu_ComErr_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_ComErr)+5u]=CAL_DEM_FIM_DFC_HvMcu_ComErr_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_ComErr)+6u]=CAL_DEM_FIM_DFC_HvMcu_ComErr_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_ComErr)+7u]=CAL_DEM_FIM_DFC_HvMcu_ComErr_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_ComErr)+8u]=CAL_DEM_FIM_DFC_HvMcu_ComErr_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_ComErr)+9u]=CAL_DEM_FIM_DFC_HvMcu_ComErr_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_DisChrgDutyErr)]=CAL_DEM_FIM_DFC_HvMcu_DisChrgDutyErr_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_DisChrgDutyErr)+1u]=CAL_DEM_FIM_DFC_HvMcu_DisChrgDutyErr_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_DisChrgDutyErr)+2u]=CAL_DEM_FIM_DFC_HvMcu_DisChrgDutyErr_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_DisChrgDutyErr)+3u]=CAL_DEM_FIM_DFC_HvMcu_DisChrgDutyErr_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_DisChrgDutyErr)+4u]=CAL_DEM_FIM_DFC_HvMcu_DisChrgDutyErr_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_DisChrgDutyErr)+5u]=CAL_DEM_FIM_DFC_HvMcu_DisChrgDutyErr_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_DisChrgDutyErr)+6u]=CAL_DEM_FIM_DFC_HvMcu_DisChrgDutyErr_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_DisChrgDutyErr)+7u]=CAL_DEM_FIM_DFC_HvMcu_DisChrgDutyErr_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_DisChrgDutyErr)+8u]=CAL_DEM_FIM_DFC_HvMcu_DisChrgDutyErr_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_DisChrgDutyErr)+9u]=CAL_DEM_FIM_DFC_HvMcu_DisChrgDutyErr_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_DisChrgFail)]=CAL_DEM_FIM_DFC_HvMcu_DisChrgFail_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_DisChrgFail)+1u]=CAL_DEM_FIM_DFC_HvMcu_DisChrgFail_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_DisChrgFail)+2u]=CAL_DEM_FIM_DFC_HvMcu_DisChrgFail_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_DisChrgFail)+3u]=CAL_DEM_FIM_DFC_HvMcu_DisChrgFail_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_DisChrgFail)+4u]=CAL_DEM_FIM_DFC_HvMcu_DisChrgFail_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_DisChrgFail)+5u]=CAL_DEM_FIM_DFC_HvMcu_DisChrgFail_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_DisChrgFail)+6u]=CAL_DEM_FIM_DFC_HvMcu_DisChrgFail_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_DisChrgFail)+7u]=CAL_DEM_FIM_DFC_HvMcu_DisChrgFail_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_DisChrgFail)+8u]=CAL_DEM_FIM_DFC_HvMcu_DisChrgFail_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_DisChrgFail)+9u]=CAL_DEM_FIM_DFC_HvMcu_DisChrgFail_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_DisChrgFreqErr)]=CAL_DEM_FIM_DFC_HvMcu_DisChrgFreqErr_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_DisChrgFreqErr)+1u]=CAL_DEM_FIM_DFC_HvMcu_DisChrgFreqErr_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_DisChrgFreqErr)+2u]=CAL_DEM_FIM_DFC_HvMcu_DisChrgFreqErr_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_DisChrgFreqErr)+3u]=CAL_DEM_FIM_DFC_HvMcu_DisChrgFreqErr_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_DisChrgFreqErr)+4u]=CAL_DEM_FIM_DFC_HvMcu_DisChrgFreqErr_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_DisChrgFreqErr)+5u]=CAL_DEM_FIM_DFC_HvMcu_DisChrgFreqErr_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_DisChrgFreqErr)+6u]=CAL_DEM_FIM_DFC_HvMcu_DisChrgFreqErr_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_DisChrgFreqErr)+7u]=CAL_DEM_FIM_DFC_HvMcu_DisChrgFreqErr_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_DisChrgFreqErr)+8u]=CAL_DEM_FIM_DFC_HvMcu_DisChrgFreqErr_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_DisChrgFreqErr)+9u]=CAL_DEM_FIM_DFC_HvMcu_DisChrgFreqErr_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_EmerPowerSapErr)]=CAL_DEM_FIM_DFC_HvMcu_EmerPowerSapErr_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_EmerPowerSapErr)+1u]=CAL_DEM_FIM_DFC_HvMcu_EmerPowerSapErr_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_EmerPowerSapErr)+2u]=CAL_DEM_FIM_DFC_HvMcu_EmerPowerSapErr_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_EmerPowerSapErr)+3u]=CAL_DEM_FIM_DFC_HvMcu_EmerPowerSapErr_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_EmerPowerSapErr)+4u]=CAL_DEM_FIM_DFC_HvMcu_EmerPowerSapErr_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_EmerPowerSapErr)+5u]=CAL_DEM_FIM_DFC_HvMcu_EmerPowerSapErr_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_EmerPowerSapErr)+6u]=CAL_DEM_FIM_DFC_HvMcu_EmerPowerSapErr_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_EmerPowerSapErr)+7u]=CAL_DEM_FIM_DFC_HvMcu_EmerPowerSapErr_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_EmerPowerSapErr)+8u]=CAL_DEM_FIM_DFC_HvMcu_EmerPowerSapErr_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_EmerPowerSapErr)+9u]=CAL_DEM_FIM_DFC_HvMcu_EmerPowerSapErr_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_UartCheckFailErr)]=CAL_DEM_FIM_DFC_HvMcu_UartCheckFailErr_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_UartCheckFailErr)+1u]=CAL_DEM_FIM_DFC_HvMcu_UartCheckFailErr_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_UartCheckFailErr)+2u]=CAL_DEM_FIM_DFC_HvMcu_UartCheckFailErr_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_UartCheckFailErr)+3u]=CAL_DEM_FIM_DFC_HvMcu_UartCheckFailErr_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_UartCheckFailErr)+4u]=CAL_DEM_FIM_DFC_HvMcu_UartCheckFailErr_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_UartCheckFailErr)+5u]=CAL_DEM_FIM_DFC_HvMcu_UartCheckFailErr_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_UartCheckFailErr)+6u]=CAL_DEM_FIM_DFC_HvMcu_UartCheckFailErr_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_UartCheckFailErr)+7u]=CAL_DEM_FIM_DFC_HvMcu_UartCheckFailErr_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_UartCheckFailErr)+8u]=CAL_DEM_FIM_DFC_HvMcu_UartCheckFailErr_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_UartCheckFailErr)+9u]=CAL_DEM_FIM_DFC_HvMcu_UartCheckFailErr_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_UartLostFrameErr)]=CAL_DEM_FIM_DFC_HvMcu_UartLostFrameErr_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_UartLostFrameErr)+1u]=CAL_DEM_FIM_DFC_HvMcu_UartLostFrameErr_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_UartLostFrameErr)+2u]=CAL_DEM_FIM_DFC_HvMcu_UartLostFrameErr_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_UartLostFrameErr)+3u]=CAL_DEM_FIM_DFC_HvMcu_UartLostFrameErr_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_UartLostFrameErr)+4u]=CAL_DEM_FIM_DFC_HvMcu_UartLostFrameErr_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_UartLostFrameErr)+5u]=CAL_DEM_FIM_DFC_HvMcu_UartLostFrameErr_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_UartLostFrameErr)+6u]=CAL_DEM_FIM_DFC_HvMcu_UartLostFrameErr_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_UartLostFrameErr)+7u]=CAL_DEM_FIM_DFC_HvMcu_UartLostFrameErr_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_UartLostFrameErr)+8u]=CAL_DEM_FIM_DFC_HvMcu_UartLostFrameErr_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_UartLostFrameErr)+9u]=CAL_DEM_FIM_DFC_HvMcu_UartLostFrameErr_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_UdcCheckErr)]=CAL_DEM_FIM_DFC_HvMcu_UdcCheckErr_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_UdcCheckErr)+1u]=CAL_DEM_FIM_DFC_HvMcu_UdcCheckErr_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_UdcCheckErr)+2u]=CAL_DEM_FIM_DFC_HvMcu_UdcCheckErr_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_UdcCheckErr)+3u]=CAL_DEM_FIM_DFC_HvMcu_UdcCheckErr_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_UdcCheckErr)+4u]=CAL_DEM_FIM_DFC_HvMcu_UdcCheckErr_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_UdcCheckErr)+5u]=CAL_DEM_FIM_DFC_HvMcu_UdcCheckErr_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_UdcCheckErr)+6u]=CAL_DEM_FIM_DFC_HvMcu_UdcCheckErr_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_UdcCheckErr)+7u]=CAL_DEM_FIM_DFC_HvMcu_UdcCheckErr_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_UdcCheckErr)+8u]=CAL_DEM_FIM_DFC_HvMcu_UdcCheckErr_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_UdcCheckErr)+9u]=CAL_DEM_FIM_DFC_HvMcu_UdcCheckErr_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_UdcOverFlagLimit)]=CAL_DEM_FIM_DFC_HvMcu_UdcOverFlagLimit_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_UdcOverFlagLimit)+1u]=CAL_DEM_FIM_DFC_HvMcu_UdcOverFlagLimit_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_UdcOverFlagLimit)+2u]=CAL_DEM_FIM_DFC_HvMcu_UdcOverFlagLimit_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_UdcOverFlagLimit)+3u]=CAL_DEM_FIM_DFC_HvMcu_UdcOverFlagLimit_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_UdcOverFlagLimit)+4u]=CAL_DEM_FIM_DFC_HvMcu_UdcOverFlagLimit_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_UdcOverFlagLimit)+5u]=CAL_DEM_FIM_DFC_HvMcu_UdcOverFlagLimit_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_UdcOverFlagLimit)+6u]=CAL_DEM_FIM_DFC_HvMcu_UdcOverFlagLimit_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_UdcOverFlagLimit)+7u]=CAL_DEM_FIM_DFC_HvMcu_UdcOverFlagLimit_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_UdcOverFlagLimit)+8u]=CAL_DEM_FIM_DFC_HvMcu_UdcOverFlagLimit_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_UdcOverFlagLimit)+9u]=CAL_DEM_FIM_DFC_HvMcu_UdcOverFlagLimit_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_UdcOverVolErr)]=CAL_DEM_FIM_DFC_HvMcu_UdcOverVolErr_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_UdcOverVolErr)+1u]=CAL_DEM_FIM_DFC_HvMcu_UdcOverVolErr_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_UdcOverVolErr)+2u]=CAL_DEM_FIM_DFC_HvMcu_UdcOverVolErr_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_UdcOverVolErr)+3u]=CAL_DEM_FIM_DFC_HvMcu_UdcOverVolErr_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_UdcOverVolErr)+4u]=CAL_DEM_FIM_DFC_HvMcu_UdcOverVolErr_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_UdcOverVolErr)+5u]=CAL_DEM_FIM_DFC_HvMcu_UdcOverVolErr_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_UdcOverVolErr)+6u]=CAL_DEM_FIM_DFC_HvMcu_UdcOverVolErr_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_UdcOverVolErr)+7u]=CAL_DEM_FIM_DFC_HvMcu_UdcOverVolErr_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_UdcOverVolErr)+8u]=CAL_DEM_FIM_DFC_HvMcu_UdcOverVolErr_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_HvMcu_UdcOverVolErr)+9u]=CAL_DEM_FIM_DFC_HvMcu_UdcOverVolErr_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_12VNarrSampErr)]=CAL_DEM_FIM_DFC_IOHWAB_12VNarrSampErr_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_12VNarrSampErr)+1u]=CAL_DEM_FIM_DFC_IOHWAB_12VNarrSampErr_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_12VNarrSampErr)+2u]=CAL_DEM_FIM_DFC_IOHWAB_12VNarrSampErr_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_12VNarrSampErr)+3u]=CAL_DEM_FIM_DFC_IOHWAB_12VNarrSampErr_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_12VNarrSampErr)+4u]=CAL_DEM_FIM_DFC_IOHWAB_12VNarrSampErr_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_12VNarrSampErr)+5u]=CAL_DEM_FIM_DFC_IOHWAB_12VNarrSampErr_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_12VNarrSampErr)+6u]=CAL_DEM_FIM_DFC_IOHWAB_12VNarrSampErr_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_12VNarrSampErr)+7u]=CAL_DEM_FIM_DFC_IOHWAB_12VNarrSampErr_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_12VNarrSampErr)+8u]=CAL_DEM_FIM_DFC_IOHWAB_12VNarrSampErr_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_12VNarrSampErr)+9u]=CAL_DEM_FIM_DFC_IOHWAB_12VNarrSampErr_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_12VSampErr)]=CAL_DEM_FIM_DFC_IOHWAB_12VSampErr_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_12VSampErr)+1u]=CAL_DEM_FIM_DFC_IOHWAB_12VSampErr_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_12VSampErr)+2u]=CAL_DEM_FIM_DFC_IOHWAB_12VSampErr_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_12VSampErr)+3u]=CAL_DEM_FIM_DFC_IOHWAB_12VSampErr_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_12VSampErr)+4u]=CAL_DEM_FIM_DFC_IOHWAB_12VSampErr_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_12VSampErr)+5u]=CAL_DEM_FIM_DFC_IOHWAB_12VSampErr_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_12VSampErr)+6u]=CAL_DEM_FIM_DFC_IOHWAB_12VSampErr_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_12VSampErr)+7u]=CAL_DEM_FIM_DFC_IOHWAB_12VSampErr_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_12VSampErr)+8u]=CAL_DEM_FIM_DFC_IOHWAB_12VSampErr_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_12VSampErr)+9u]=CAL_DEM_FIM_DFC_IOHWAB_12VSampErr_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_12VWideSampErr)]=CAL_DEM_FIM_DFC_IOHWAB_12VWideSampErr_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_12VWideSampErr)+1u]=CAL_DEM_FIM_DFC_IOHWAB_12VWideSampErr_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_12VWideSampErr)+2u]=CAL_DEM_FIM_DFC_IOHWAB_12VWideSampErr_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_12VWideSampErr)+3u]=CAL_DEM_FIM_DFC_IOHWAB_12VWideSampErr_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_12VWideSampErr)+4u]=CAL_DEM_FIM_DFC_IOHWAB_12VWideSampErr_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_12VWideSampErr)+5u]=CAL_DEM_FIM_DFC_IOHWAB_12VWideSampErr_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_12VWideSampErr)+6u]=CAL_DEM_FIM_DFC_IOHWAB_12VWideSampErr_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_12VWideSampErr)+7u]=CAL_DEM_FIM_DFC_IOHWAB_12VWideSampErr_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_12VWideSampErr)+8u]=CAL_DEM_FIM_DFC_IOHWAB_12VWideSampErr_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_12VWideSampErr)+9u]=CAL_DEM_FIM_DFC_IOHWAB_12VWideSampErr_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_18VLwBrgSampFail)]=CAL_DEM_FIM_DFC_IOHWAB_18VLwBrgSampFail_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_18VLwBrgSampFail)+1u]=CAL_DEM_FIM_DFC_IOHWAB_18VLwBrgSampFail_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_18VLwBrgSampFail)+2u]=CAL_DEM_FIM_DFC_IOHWAB_18VLwBrgSampFail_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_18VLwBrgSampFail)+3u]=CAL_DEM_FIM_DFC_IOHWAB_18VLwBrgSampFail_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_18VLwBrgSampFail)+4u]=CAL_DEM_FIM_DFC_IOHWAB_18VLwBrgSampFail_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_18VLwBrgSampFail)+5u]=CAL_DEM_FIM_DFC_IOHWAB_18VLwBrgSampFail_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_18VLwBrgSampFail)+6u]=CAL_DEM_FIM_DFC_IOHWAB_18VLwBrgSampFail_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_18VLwBrgSampFail)+7u]=CAL_DEM_FIM_DFC_IOHWAB_18VLwBrgSampFail_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_18VLwBrgSampFail)+8u]=CAL_DEM_FIM_DFC_IOHWAB_18VLwBrgSampFail_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_18VLwBrgSampFail)+9u]=CAL_DEM_FIM_DFC_IOHWAB_18VLwBrgSampFail_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_18VUpBrgSampFail)]=CAL_DEM_FIM_DFC_IOHWAB_18VUpBrgSampFail_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_18VUpBrgSampFail)+1u]=CAL_DEM_FIM_DFC_IOHWAB_18VUpBrgSampFail_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_18VUpBrgSampFail)+2u]=CAL_DEM_FIM_DFC_IOHWAB_18VUpBrgSampFail_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_18VUpBrgSampFail)+3u]=CAL_DEM_FIM_DFC_IOHWAB_18VUpBrgSampFail_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_18VUpBrgSampFail)+4u]=CAL_DEM_FIM_DFC_IOHWAB_18VUpBrgSampFail_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_18VUpBrgSampFail)+5u]=CAL_DEM_FIM_DFC_IOHWAB_18VUpBrgSampFail_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_18VUpBrgSampFail)+6u]=CAL_DEM_FIM_DFC_IOHWAB_18VUpBrgSampFail_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_18VUpBrgSampFail)+7u]=CAL_DEM_FIM_DFC_IOHWAB_18VUpBrgSampFail_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_18VUpBrgSampFail)+8u]=CAL_DEM_FIM_DFC_IOHWAB_18VUpBrgSampFail_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_18VUpBrgSampFail)+9u]=CAL_DEM_FIM_DFC_IOHWAB_18VUpBrgSampFail_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_1V3MCU_SampFail)]=CAL_DEM_FIM_DFC_IOHWAB_1V3MCU_SampFail_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_1V3MCU_SampFail)+1u]=CAL_DEM_FIM_DFC_IOHWAB_1V3MCU_SampFail_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_1V3MCU_SampFail)+2u]=CAL_DEM_FIM_DFC_IOHWAB_1V3MCU_SampFail_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_1V3MCU_SampFail)+3u]=CAL_DEM_FIM_DFC_IOHWAB_1V3MCU_SampFail_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_1V3MCU_SampFail)+4u]=CAL_DEM_FIM_DFC_IOHWAB_1V3MCU_SampFail_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_1V3MCU_SampFail)+5u]=CAL_DEM_FIM_DFC_IOHWAB_1V3MCU_SampFail_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_1V3MCU_SampFail)+6u]=CAL_DEM_FIM_DFC_IOHWAB_1V3MCU_SampFail_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_1V3MCU_SampFail)+7u]=CAL_DEM_FIM_DFC_IOHWAB_1V3MCU_SampFail_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_1V3MCU_SampFail)+8u]=CAL_DEM_FIM_DFC_IOHWAB_1V3MCU_SampFail_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_1V3MCU_SampFail)+9u]=CAL_DEM_FIM_DFC_IOHWAB_1V3MCU_SampFail_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_3V3MCU_SampFail)]=CAL_DEM_FIM_DFC_IOHWAB_3V3MCU_SampFail_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_3V3MCU_SampFail)+1u]=CAL_DEM_FIM_DFC_IOHWAB_3V3MCU_SampFail_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_3V3MCU_SampFail)+2u]=CAL_DEM_FIM_DFC_IOHWAB_3V3MCU_SampFail_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_3V3MCU_SampFail)+3u]=CAL_DEM_FIM_DFC_IOHWAB_3V3MCU_SampFail_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_3V3MCU_SampFail)+4u]=CAL_DEM_FIM_DFC_IOHWAB_3V3MCU_SampFail_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_3V3MCU_SampFail)+5u]=CAL_DEM_FIM_DFC_IOHWAB_3V3MCU_SampFail_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_3V3MCU_SampFail)+6u]=CAL_DEM_FIM_DFC_IOHWAB_3V3MCU_SampFail_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_3V3MCU_SampFail)+7u]=CAL_DEM_FIM_DFC_IOHWAB_3V3MCU_SampFail_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_3V3MCU_SampFail)+8u]=CAL_DEM_FIM_DFC_IOHWAB_3V3MCU_SampFail_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_3V3MCU_SampFail)+9u]=CAL_DEM_FIM_DFC_IOHWAB_3V3MCU_SampFail_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_5VQcoSampFail)]=CAL_DEM_FIM_DFC_IOHWAB_5VQcoSampFail_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_5VQcoSampFail)+1u]=CAL_DEM_FIM_DFC_IOHWAB_5VQcoSampFail_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_5VQcoSampFail)+2u]=CAL_DEM_FIM_DFC_IOHWAB_5VQcoSampFail_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_5VQcoSampFail)+3u]=CAL_DEM_FIM_DFC_IOHWAB_5VQcoSampFail_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_5VQcoSampFail)+4u]=CAL_DEM_FIM_DFC_IOHWAB_5VQcoSampFail_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_5VQcoSampFail)+5u]=CAL_DEM_FIM_DFC_IOHWAB_5VQcoSampFail_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_5VQcoSampFail)+6u]=CAL_DEM_FIM_DFC_IOHWAB_5VQcoSampFail_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_5VQcoSampFail)+7u]=CAL_DEM_FIM_DFC_IOHWAB_5VQcoSampFail_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_5VQcoSampFail)+8u]=CAL_DEM_FIM_DFC_IOHWAB_5VQcoSampFail_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_5VQcoSampFail)+9u]=CAL_DEM_FIM_DFC_IOHWAB_5VQcoSampFail_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_5VQt1SampFail)]=CAL_DEM_FIM_DFC_IOHWAB_5VQt1SampFail_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_5VQt1SampFail)+1u]=CAL_DEM_FIM_DFC_IOHWAB_5VQt1SampFail_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_5VQt1SampFail)+2u]=CAL_DEM_FIM_DFC_IOHWAB_5VQt1SampFail_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_5VQt1SampFail)+3u]=CAL_DEM_FIM_DFC_IOHWAB_5VQt1SampFail_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_5VQt1SampFail)+4u]=CAL_DEM_FIM_DFC_IOHWAB_5VQt1SampFail_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_5VQt1SampFail)+5u]=CAL_DEM_FIM_DFC_IOHWAB_5VQt1SampFail_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_5VQt1SampFail)+6u]=CAL_DEM_FIM_DFC_IOHWAB_5VQt1SampFail_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_5VQt1SampFail)+7u]=CAL_DEM_FIM_DFC_IOHWAB_5VQt1SampFail_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_5VQt1SampFail)+8u]=CAL_DEM_FIM_DFC_IOHWAB_5VQt1SampFail_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_5VQt1SampFail)+9u]=CAL_DEM_FIM_DFC_IOHWAB_5VQt1SampFail_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_5VQt2SampFail)]=CAL_DEM_FIM_DFC_IOHWAB_5VQt2SampFail_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_5VQt2SampFail)+1u]=CAL_DEM_FIM_DFC_IOHWAB_5VQt2SampFail_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_5VQt2SampFail)+2u]=CAL_DEM_FIM_DFC_IOHWAB_5VQt2SampFail_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_5VQt2SampFail)+3u]=CAL_DEM_FIM_DFC_IOHWAB_5VQt2SampFail_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_5VQt2SampFail)+4u]=CAL_DEM_FIM_DFC_IOHWAB_5VQt2SampFail_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_5VQt2SampFail)+5u]=CAL_DEM_FIM_DFC_IOHWAB_5VQt2SampFail_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_5VQt2SampFail)+6u]=CAL_DEM_FIM_DFC_IOHWAB_5VQt2SampFail_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_5VQt2SampFail)+7u]=CAL_DEM_FIM_DFC_IOHWAB_5VQt2SampFail_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_5VQt2SampFail)+8u]=CAL_DEM_FIM_DFC_IOHWAB_5VQt2SampFail_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_5VQt2SampFail)+9u]=CAL_DEM_FIM_DFC_IOHWAB_5VQt2SampFail_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_Cpld1v8SampFail)]=CAL_DEM_FIM_DFC_IOHWAB_Cpld1v8SampFail_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_Cpld1v8SampFail)+1u]=CAL_DEM_FIM_DFC_IOHWAB_Cpld1v8SampFail_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_Cpld1v8SampFail)+2u]=CAL_DEM_FIM_DFC_IOHWAB_Cpld1v8SampFail_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_Cpld1v8SampFail)+3u]=CAL_DEM_FIM_DFC_IOHWAB_Cpld1v8SampFail_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_Cpld1v8SampFail)+4u]=CAL_DEM_FIM_DFC_IOHWAB_Cpld1v8SampFail_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_Cpld1v8SampFail)+5u]=CAL_DEM_FIM_DFC_IOHWAB_Cpld1v8SampFail_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_Cpld1v8SampFail)+6u]=CAL_DEM_FIM_DFC_IOHWAB_Cpld1v8SampFail_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_Cpld1v8SampFail)+7u]=CAL_DEM_FIM_DFC_IOHWAB_Cpld1v8SampFail_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_Cpld1v8SampFail)+8u]=CAL_DEM_FIM_DFC_IOHWAB_Cpld1v8SampFail_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_Cpld1v8SampFail)+9u]=CAL_DEM_FIM_DFC_IOHWAB_Cpld1v8SampFail_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_Cpld3v3SampFail)]=CAL_DEM_FIM_DFC_IOHWAB_Cpld3v3SampFail_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_Cpld3v3SampFail)+1u]=CAL_DEM_FIM_DFC_IOHWAB_Cpld3v3SampFail_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_Cpld3v3SampFail)+2u]=CAL_DEM_FIM_DFC_IOHWAB_Cpld3v3SampFail_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_Cpld3v3SampFail)+3u]=CAL_DEM_FIM_DFC_IOHWAB_Cpld3v3SampFail_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_Cpld3v3SampFail)+4u]=CAL_DEM_FIM_DFC_IOHWAB_Cpld3v3SampFail_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_Cpld3v3SampFail)+5u]=CAL_DEM_FIM_DFC_IOHWAB_Cpld3v3SampFail_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_Cpld3v3SampFail)+6u]=CAL_DEM_FIM_DFC_IOHWAB_Cpld3v3SampFail_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_Cpld3v3SampFail)+7u]=CAL_DEM_FIM_DFC_IOHWAB_Cpld3v3SampFail_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_Cpld3v3SampFail)+8u]=CAL_DEM_FIM_DFC_IOHWAB_Cpld3v3SampFail_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_Cpld3v3SampFail)+9u]=CAL_DEM_FIM_DFC_IOHWAB_Cpld3v3SampFail_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_CrashFail)]=CAL_DEM_FIM_DFC_IOHWAB_CrashFail_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_CrashFail)+1u]=CAL_DEM_FIM_DFC_IOHWAB_CrashFail_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_CrashFail)+2u]=CAL_DEM_FIM_DFC_IOHWAB_CrashFail_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_CrashFail)+3u]=CAL_DEM_FIM_DFC_IOHWAB_CrashFail_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_CrashFail)+4u]=CAL_DEM_FIM_DFC_IOHWAB_CrashFail_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_CrashFail)+5u]=CAL_DEM_FIM_DFC_IOHWAB_CrashFail_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_CrashFail)+6u]=CAL_DEM_FIM_DFC_IOHWAB_CrashFail_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_CrashFail)+7u]=CAL_DEM_FIM_DFC_IOHWAB_CrashFail_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_CrashFail)+8u]=CAL_DEM_FIM_DFC_IOHWAB_CrashFail_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_CrashFail)+9u]=CAL_DEM_FIM_DFC_IOHWAB_CrashFail_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_DcLnkOverVolFail)]=CAL_DEM_FIM_DFC_IOHWAB_DcLnkOverVolFail_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_DcLnkOverVolFail)+1u]=CAL_DEM_FIM_DFC_IOHWAB_DcLnkOverVolFail_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_DcLnkOverVolFail)+2u]=CAL_DEM_FIM_DFC_IOHWAB_DcLnkOverVolFail_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_DcLnkOverVolFail)+3u]=CAL_DEM_FIM_DFC_IOHWAB_DcLnkOverVolFail_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_DcLnkOverVolFail)+4u]=CAL_DEM_FIM_DFC_IOHWAB_DcLnkOverVolFail_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_DcLnkOverVolFail)+5u]=CAL_DEM_FIM_DFC_IOHWAB_DcLnkOverVolFail_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_DcLnkOverVolFail)+6u]=CAL_DEM_FIM_DFC_IOHWAB_DcLnkOverVolFail_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_DcLnkOverVolFail)+7u]=CAL_DEM_FIM_DFC_IOHWAB_DcLnkOverVolFail_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_DcLnkOverVolFail)+8u]=CAL_DEM_FIM_DFC_IOHWAB_DcLnkOverVolFail_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_DcLnkOverVolFail)+9u]=CAL_DEM_FIM_DFC_IOHWAB_DcLnkOverVolFail_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_IphaOCFail)]=CAL_DEM_FIM_DFC_IOHWAB_IphaOCFail_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_IphaOCFail)+1u]=CAL_DEM_FIM_DFC_IOHWAB_IphaOCFail_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_IphaOCFail)+2u]=CAL_DEM_FIM_DFC_IOHWAB_IphaOCFail_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_IphaOCFail)+3u]=CAL_DEM_FIM_DFC_IOHWAB_IphaOCFail_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_IphaOCFail)+4u]=CAL_DEM_FIM_DFC_IOHWAB_IphaOCFail_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_IphaOCFail)+5u]=CAL_DEM_FIM_DFC_IOHWAB_IphaOCFail_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_IphaOCFail)+6u]=CAL_DEM_FIM_DFC_IOHWAB_IphaOCFail_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_IphaOCFail)+7u]=CAL_DEM_FIM_DFC_IOHWAB_IphaOCFail_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_IphaOCFail)+8u]=CAL_DEM_FIM_DFC_IOHWAB_IphaOCFail_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_IphaOCFail)+9u]=CAL_DEM_FIM_DFC_IOHWAB_IphaOCFail_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_KL30OverVolErr)]=CAL_DEM_FIM_DFC_IOHWAB_KL30OverVolErr_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_KL30OverVolErr)+1u]=CAL_DEM_FIM_DFC_IOHWAB_KL30OverVolErr_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_KL30OverVolErr)+2u]=CAL_DEM_FIM_DFC_IOHWAB_KL30OverVolErr_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_KL30OverVolErr)+3u]=CAL_DEM_FIM_DFC_IOHWAB_KL30OverVolErr_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_KL30OverVolErr)+4u]=CAL_DEM_FIM_DFC_IOHWAB_KL30OverVolErr_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_KL30OverVolErr)+5u]=CAL_DEM_FIM_DFC_IOHWAB_KL30OverVolErr_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_KL30OverVolErr)+6u]=CAL_DEM_FIM_DFC_IOHWAB_KL30OverVolErr_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_KL30OverVolErr)+7u]=CAL_DEM_FIM_DFC_IOHWAB_KL30OverVolErr_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_KL30OverVolErr)+8u]=CAL_DEM_FIM_DFC_IOHWAB_KL30OverVolErr_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_KL30OverVolErr)+9u]=CAL_DEM_FIM_DFC_IOHWAB_KL30OverVolErr_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_KL30SevOverVolFail)]=CAL_DEM_FIM_DFC_IOHWAB_KL30SevOverVolFail_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_KL30SevOverVolFail)+1u]=CAL_DEM_FIM_DFC_IOHWAB_KL30SevOverVolFail_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_KL30SevOverVolFail)+2u]=CAL_DEM_FIM_DFC_IOHWAB_KL30SevOverVolFail_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_KL30SevOverVolFail)+3u]=CAL_DEM_FIM_DFC_IOHWAB_KL30SevOverVolFail_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_KL30SevOverVolFail)+4u]=CAL_DEM_FIM_DFC_IOHWAB_KL30SevOverVolFail_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_KL30SevOverVolFail)+5u]=CAL_DEM_FIM_DFC_IOHWAB_KL30SevOverVolFail_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_KL30SevOverVolFail)+6u]=CAL_DEM_FIM_DFC_IOHWAB_KL30SevOverVolFail_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_KL30SevOverVolFail)+7u]=CAL_DEM_FIM_DFC_IOHWAB_KL30SevOverVolFail_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_KL30SevOverVolFail)+8u]=CAL_DEM_FIM_DFC_IOHWAB_KL30SevOverVolFail_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_KL30SevOverVolFail)+9u]=CAL_DEM_FIM_DFC_IOHWAB_KL30SevOverVolFail_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_KL30SevUnderVolFail)]=CAL_DEM_FIM_DFC_IOHWAB_KL30SevUnderVolFail_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_KL30SevUnderVolFail)+1u]=CAL_DEM_FIM_DFC_IOHWAB_KL30SevUnderVolFail_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_KL30SevUnderVolFail)+2u]=CAL_DEM_FIM_DFC_IOHWAB_KL30SevUnderVolFail_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_KL30SevUnderVolFail)+3u]=CAL_DEM_FIM_DFC_IOHWAB_KL30SevUnderVolFail_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_KL30SevUnderVolFail)+4u]=CAL_DEM_FIM_DFC_IOHWAB_KL30SevUnderVolFail_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_KL30SevUnderVolFail)+5u]=CAL_DEM_FIM_DFC_IOHWAB_KL30SevUnderVolFail_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_KL30SevUnderVolFail)+6u]=CAL_DEM_FIM_DFC_IOHWAB_KL30SevUnderVolFail_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_KL30SevUnderVolFail)+7u]=CAL_DEM_FIM_DFC_IOHWAB_KL30SevUnderVolFail_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_KL30SevUnderVolFail)+8u]=CAL_DEM_FIM_DFC_IOHWAB_KL30SevUnderVolFail_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_KL30SevUnderVolFail)+9u]=CAL_DEM_FIM_DFC_IOHWAB_KL30SevUnderVolFail_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_KL30UnderVolErr)]=CAL_DEM_FIM_DFC_IOHWAB_KL30UnderVolErr_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_KL30UnderVolErr)+1u]=CAL_DEM_FIM_DFC_IOHWAB_KL30UnderVolErr_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_KL30UnderVolErr)+2u]=CAL_DEM_FIM_DFC_IOHWAB_KL30UnderVolErr_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_KL30UnderVolErr)+3u]=CAL_DEM_FIM_DFC_IOHWAB_KL30UnderVolErr_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_KL30UnderVolErr)+4u]=CAL_DEM_FIM_DFC_IOHWAB_KL30UnderVolErr_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_KL30UnderVolErr)+5u]=CAL_DEM_FIM_DFC_IOHWAB_KL30UnderVolErr_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_KL30UnderVolErr)+6u]=CAL_DEM_FIM_DFC_IOHWAB_KL30UnderVolErr_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_KL30UnderVolErr)+7u]=CAL_DEM_FIM_DFC_IOHWAB_KL30UnderVolErr_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_KL30UnderVolErr)+8u]=CAL_DEM_FIM_DFC_IOHWAB_KL30UnderVolErr_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_KL30UnderVolErr)+9u]=CAL_DEM_FIM_DFC_IOHWAB_KL30UnderVolErr_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_Nen33Fail)]=CAL_DEM_FIM_DFC_IOHWAB_Nen33Fail_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_Nen33Fail)+1u]=CAL_DEM_FIM_DFC_IOHWAB_Nen33Fail_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_Nen33Fail)+2u]=CAL_DEM_FIM_DFC_IOHWAB_Nen33Fail_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_Nen33Fail)+3u]=CAL_DEM_FIM_DFC_IOHWAB_Nen33Fail_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_Nen33Fail)+4u]=CAL_DEM_FIM_DFC_IOHWAB_Nen33Fail_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_Nen33Fail)+5u]=CAL_DEM_FIM_DFC_IOHWAB_Nen33Fail_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_Nen33Fail)+6u]=CAL_DEM_FIM_DFC_IOHWAB_Nen33Fail_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_Nen33Fail)+7u]=CAL_DEM_FIM_DFC_IOHWAB_Nen33Fail_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_Nen33Fail)+8u]=CAL_DEM_FIM_DFC_IOHWAB_Nen33Fail_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_Nen33Fail)+9u]=CAL_DEM_FIM_DFC_IOHWAB_Nen33Fail_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_SttrSenorShrFail)]=CAL_DEM_FIM_DFC_IOHWAB_SttrSenorShrFail_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_SttrSenorShrFail)+1u]=CAL_DEM_FIM_DFC_IOHWAB_SttrSenorShrFail_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_SttrSenorShrFail)+2u]=CAL_DEM_FIM_DFC_IOHWAB_SttrSenorShrFail_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_SttrSenorShrFail)+3u]=CAL_DEM_FIM_DFC_IOHWAB_SttrSenorShrFail_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_SttrSenorShrFail)+4u]=CAL_DEM_FIM_DFC_IOHWAB_SttrSenorShrFail_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_SttrSenorShrFail)+5u]=CAL_DEM_FIM_DFC_IOHWAB_SttrSenorShrFail_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_SttrSenorShrFail)+6u]=CAL_DEM_FIM_DFC_IOHWAB_SttrSenorShrFail_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_SttrSenorShrFail)+7u]=CAL_DEM_FIM_DFC_IOHWAB_SttrSenorShrFail_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_SttrSenorShrFail)+8u]=CAL_DEM_FIM_DFC_IOHWAB_SttrSenorShrFail_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_SttrSenorShrFail)+9u]=CAL_DEM_FIM_DFC_IOHWAB_SttrSenorShrFail_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_SttrTemp1SampFail)]=CAL_DEM_FIM_DFC_IOHWAB_SttrTemp1SampFail_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_SttrTemp1SampFail)+1u]=CAL_DEM_FIM_DFC_IOHWAB_SttrTemp1SampFail_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_SttrTemp1SampFail)+2u]=CAL_DEM_FIM_DFC_IOHWAB_SttrTemp1SampFail_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_SttrTemp1SampFail)+3u]=CAL_DEM_FIM_DFC_IOHWAB_SttrTemp1SampFail_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_SttrTemp1SampFail)+4u]=CAL_DEM_FIM_DFC_IOHWAB_SttrTemp1SampFail_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_SttrTemp1SampFail)+5u]=CAL_DEM_FIM_DFC_IOHWAB_SttrTemp1SampFail_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_SttrTemp1SampFail)+6u]=CAL_DEM_FIM_DFC_IOHWAB_SttrTemp1SampFail_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_SttrTemp1SampFail)+7u]=CAL_DEM_FIM_DFC_IOHWAB_SttrTemp1SampFail_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_SttrTemp1SampFail)+8u]=CAL_DEM_FIM_DFC_IOHWAB_SttrTemp1SampFail_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_SttrTemp1SampFail)+9u]=CAL_DEM_FIM_DFC_IOHWAB_SttrTemp1SampFail_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_SttrTemp2SampFail)]=CAL_DEM_FIM_DFC_IOHWAB_SttrTemp2SampFail_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_SttrTemp2SampFail)+1u]=CAL_DEM_FIM_DFC_IOHWAB_SttrTemp2SampFail_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_SttrTemp2SampFail)+2u]=CAL_DEM_FIM_DFC_IOHWAB_SttrTemp2SampFail_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_SttrTemp2SampFail)+3u]=CAL_DEM_FIM_DFC_IOHWAB_SttrTemp2SampFail_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_SttrTemp2SampFail)+4u]=CAL_DEM_FIM_DFC_IOHWAB_SttrTemp2SampFail_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_SttrTemp2SampFail)+5u]=CAL_DEM_FIM_DFC_IOHWAB_SttrTemp2SampFail_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_SttrTemp2SampFail)+6u]=CAL_DEM_FIM_DFC_IOHWAB_SttrTemp2SampFail_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_SttrTemp2SampFail)+7u]=CAL_DEM_FIM_DFC_IOHWAB_SttrTemp2SampFail_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_SttrTemp2SampFail)+8u]=CAL_DEM_FIM_DFC_IOHWAB_SttrTemp2SampFail_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_SttrTemp2SampFail)+9u]=CAL_DEM_FIM_DFC_IOHWAB_SttrTemp2SampFail_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_TCoolantSampFail)]=CAL_DEM_FIM_DFC_IOHWAB_TCoolantSampFail_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_TCoolantSampFail)+1u]=CAL_DEM_FIM_DFC_IOHWAB_TCoolantSampFail_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_TCoolantSampFail)+2u]=CAL_DEM_FIM_DFC_IOHWAB_TCoolantSampFail_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_TCoolantSampFail)+3u]=CAL_DEM_FIM_DFC_IOHWAB_TCoolantSampFail_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_TCoolantSampFail)+4u]=CAL_DEM_FIM_DFC_IOHWAB_TCoolantSampFail_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_TCoolantSampFail)+5u]=CAL_DEM_FIM_DFC_IOHWAB_TCoolantSampFail_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_TCoolantSampFail)+6u]=CAL_DEM_FIM_DFC_IOHWAB_TCoolantSampFail_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_TCoolantSampFail)+7u]=CAL_DEM_FIM_DFC_IOHWAB_TCoolantSampFail_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_TCoolantSampFail)+8u]=CAL_DEM_FIM_DFC_IOHWAB_TCoolantSampFail_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_TCoolantSampFail)+9u]=CAL_DEM_FIM_DFC_IOHWAB_TCoolantSampFail_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_VDD5_D_SampFail)]=CAL_DEM_FIM_DFC_IOHWAB_VDD5_D_SampFail_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_VDD5_D_SampFail)+1u]=CAL_DEM_FIM_DFC_IOHWAB_VDD5_D_SampFail_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_VDD5_D_SampFail)+2u]=CAL_DEM_FIM_DFC_IOHWAB_VDD5_D_SampFail_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_VDD5_D_SampFail)+3u]=CAL_DEM_FIM_DFC_IOHWAB_VDD5_D_SampFail_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_VDD5_D_SampFail)+4u]=CAL_DEM_FIM_DFC_IOHWAB_VDD5_D_SampFail_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_VDD5_D_SampFail)+5u]=CAL_DEM_FIM_DFC_IOHWAB_VDD5_D_SampFail_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_VDD5_D_SampFail)+6u]=CAL_DEM_FIM_DFC_IOHWAB_VDD5_D_SampFail_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_VDD5_D_SampFail)+7u]=CAL_DEM_FIM_DFC_IOHWAB_VDD5_D_SampFail_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_VDD5_D_SampFail)+8u]=CAL_DEM_FIM_DFC_IOHWAB_VDD5_D_SampFail_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IOHWAB_VDD5_D_SampFail)+9u]=CAL_DEM_FIM_DFC_IOHWAB_VDD5_D_SampFail_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IgbtDrv_ComErr)]=CAL_DEM_FIM_DFC_IgbtDrv_ComErr_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IgbtDrv_ComErr)+1u]=CAL_DEM_FIM_DFC_IgbtDrv_ComErr_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IgbtDrv_ComErr)+2u]=CAL_DEM_FIM_DFC_IgbtDrv_ComErr_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IgbtDrv_ComErr)+3u]=CAL_DEM_FIM_DFC_IgbtDrv_ComErr_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IgbtDrv_ComErr)+4u]=CAL_DEM_FIM_DFC_IgbtDrv_ComErr_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IgbtDrv_ComErr)+5u]=CAL_DEM_FIM_DFC_IgbtDrv_ComErr_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IgbtDrv_ComErr)+6u]=CAL_DEM_FIM_DFC_IgbtDrv_ComErr_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IgbtDrv_ComErr)+7u]=CAL_DEM_FIM_DFC_IgbtDrv_ComErr_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IgbtDrv_ComErr)+8u]=CAL_DEM_FIM_DFC_IgbtDrv_ComErr_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IgbtDrv_ComErr)+9u]=CAL_DEM_FIM_DFC_IgbtDrv_ComErr_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IgbtDrv_LwBrgFaultAFail)]=CAL_DEM_FIM_DFC_IgbtDrv_LwBrgFaultAFail_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IgbtDrv_LwBrgFaultAFail)+1u]=CAL_DEM_FIM_DFC_IgbtDrv_LwBrgFaultAFail_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IgbtDrv_LwBrgFaultAFail)+2u]=CAL_DEM_FIM_DFC_IgbtDrv_LwBrgFaultAFail_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IgbtDrv_LwBrgFaultAFail)+3u]=CAL_DEM_FIM_DFC_IgbtDrv_LwBrgFaultAFail_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IgbtDrv_LwBrgFaultAFail)+4u]=CAL_DEM_FIM_DFC_IgbtDrv_LwBrgFaultAFail_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IgbtDrv_LwBrgFaultAFail)+5u]=CAL_DEM_FIM_DFC_IgbtDrv_LwBrgFaultAFail_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IgbtDrv_LwBrgFaultAFail)+6u]=CAL_DEM_FIM_DFC_IgbtDrv_LwBrgFaultAFail_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IgbtDrv_LwBrgFaultAFail)+7u]=CAL_DEM_FIM_DFC_IgbtDrv_LwBrgFaultAFail_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IgbtDrv_LwBrgFaultAFail)+8u]=CAL_DEM_FIM_DFC_IgbtDrv_LwBrgFaultAFail_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IgbtDrv_LwBrgFaultAFail)+9u]=CAL_DEM_FIM_DFC_IgbtDrv_LwBrgFaultAFail_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IgbtDrv_LwBrgFaultBFail)]=CAL_DEM_FIM_DFC_IgbtDrv_LwBrgFaultBFail_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IgbtDrv_LwBrgFaultBFail)+1u]=CAL_DEM_FIM_DFC_IgbtDrv_LwBrgFaultBFail_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IgbtDrv_LwBrgFaultBFail)+2u]=CAL_DEM_FIM_DFC_IgbtDrv_LwBrgFaultBFail_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IgbtDrv_LwBrgFaultBFail)+3u]=CAL_DEM_FIM_DFC_IgbtDrv_LwBrgFaultBFail_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IgbtDrv_LwBrgFaultBFail)+4u]=CAL_DEM_FIM_DFC_IgbtDrv_LwBrgFaultBFail_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IgbtDrv_LwBrgFaultBFail)+5u]=CAL_DEM_FIM_DFC_IgbtDrv_LwBrgFaultBFail_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IgbtDrv_LwBrgFaultBFail)+6u]=CAL_DEM_FIM_DFC_IgbtDrv_LwBrgFaultBFail_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IgbtDrv_LwBrgFaultBFail)+7u]=CAL_DEM_FIM_DFC_IgbtDrv_LwBrgFaultBFail_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IgbtDrv_LwBrgFaultBFail)+8u]=CAL_DEM_FIM_DFC_IgbtDrv_LwBrgFaultBFail_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IgbtDrv_LwBrgFaultBFail)+9u]=CAL_DEM_FIM_DFC_IgbtDrv_LwBrgFaultBFail_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IgbtDrv_UpBrgFaultAFail)]=CAL_DEM_FIM_DFC_IgbtDrv_UpBrgFaultAFail_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IgbtDrv_UpBrgFaultAFail)+1u]=CAL_DEM_FIM_DFC_IgbtDrv_UpBrgFaultAFail_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IgbtDrv_UpBrgFaultAFail)+2u]=CAL_DEM_FIM_DFC_IgbtDrv_UpBrgFaultAFail_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IgbtDrv_UpBrgFaultAFail)+3u]=CAL_DEM_FIM_DFC_IgbtDrv_UpBrgFaultAFail_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IgbtDrv_UpBrgFaultAFail)+4u]=CAL_DEM_FIM_DFC_IgbtDrv_UpBrgFaultAFail_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IgbtDrv_UpBrgFaultAFail)+5u]=CAL_DEM_FIM_DFC_IgbtDrv_UpBrgFaultAFail_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IgbtDrv_UpBrgFaultAFail)+6u]=CAL_DEM_FIM_DFC_IgbtDrv_UpBrgFaultAFail_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IgbtDrv_UpBrgFaultAFail)+7u]=CAL_DEM_FIM_DFC_IgbtDrv_UpBrgFaultAFail_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IgbtDrv_UpBrgFaultAFail)+8u]=CAL_DEM_FIM_DFC_IgbtDrv_UpBrgFaultAFail_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IgbtDrv_UpBrgFaultAFail)+9u]=CAL_DEM_FIM_DFC_IgbtDrv_UpBrgFaultAFail_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IgbtDrv_UpBrgFaultBFail)]=CAL_DEM_FIM_DFC_IgbtDrv_UpBrgFaultBFail_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IgbtDrv_UpBrgFaultBFail)+1u]=CAL_DEM_FIM_DFC_IgbtDrv_UpBrgFaultBFail_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IgbtDrv_UpBrgFaultBFail)+2u]=CAL_DEM_FIM_DFC_IgbtDrv_UpBrgFaultBFail_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IgbtDrv_UpBrgFaultBFail)+3u]=CAL_DEM_FIM_DFC_IgbtDrv_UpBrgFaultBFail_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IgbtDrv_UpBrgFaultBFail)+4u]=CAL_DEM_FIM_DFC_IgbtDrv_UpBrgFaultBFail_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IgbtDrv_UpBrgFaultBFail)+5u]=CAL_DEM_FIM_DFC_IgbtDrv_UpBrgFaultBFail_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IgbtDrv_UpBrgFaultBFail)+6u]=CAL_DEM_FIM_DFC_IgbtDrv_UpBrgFaultBFail_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IgbtDrv_UpBrgFaultBFail)+7u]=CAL_DEM_FIM_DFC_IgbtDrv_UpBrgFaultBFail_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IgbtDrv_UpBrgFaultBFail)+8u]=CAL_DEM_FIM_DFC_IgbtDrv_UpBrgFaultBFail_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_IgbtDrv_UpBrgFaultBFail)+9u]=CAL_DEM_FIM_DFC_IgbtDrv_UpBrgFaultBFail_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_AlOfsNoPlausErr)]=CAL_DEM_FIM_DFC_MDF_AlOfsNoPlausErr_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_AlOfsNoPlausErr)+1u]=CAL_DEM_FIM_DFC_MDF_AlOfsNoPlausErr_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_AlOfsNoPlausErr)+2u]=CAL_DEM_FIM_DFC_MDF_AlOfsNoPlausErr_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_AlOfsNoPlausErr)+3u]=CAL_DEM_FIM_DFC_MDF_AlOfsNoPlausErr_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_AlOfsNoPlausErr)+4u]=CAL_DEM_FIM_DFC_MDF_AlOfsNoPlausErr_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_AlOfsNoPlausErr)+5u]=CAL_DEM_FIM_DFC_MDF_AlOfsNoPlausErr_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_AlOfsNoPlausErr)+6u]=CAL_DEM_FIM_DFC_MDF_AlOfsNoPlausErr_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_AlOfsNoPlausErr)+7u]=CAL_DEM_FIM_DFC_MDF_AlOfsNoPlausErr_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_AlOfsNoPlausErr)+8u]=CAL_DEM_FIM_DFC_MDF_AlOfsNoPlausErr_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_AlOfsNoPlausErr)+9u]=CAL_DEM_FIM_DFC_MDF_AlOfsNoPlausErr_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_DiashCirNoPsblErr)]=CAL_DEM_FIM_DFC_MDF_DiashCirNoPsblErr_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_DiashCirNoPsblErr)+1u]=CAL_DEM_FIM_DFC_MDF_DiashCirNoPsblErr_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_DiashCirNoPsblErr)+2u]=CAL_DEM_FIM_DFC_MDF_DiashCirNoPsblErr_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_DiashCirNoPsblErr)+3u]=CAL_DEM_FIM_DFC_MDF_DiashCirNoPsblErr_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_DiashCirNoPsblErr)+4u]=CAL_DEM_FIM_DFC_MDF_DiashCirNoPsblErr_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_DiashCirNoPsblErr)+5u]=CAL_DEM_FIM_DFC_MDF_DiashCirNoPsblErr_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_DiashCirNoPsblErr)+6u]=CAL_DEM_FIM_DFC_MDF_DiashCirNoPsblErr_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_DiashCirNoPsblErr)+7u]=CAL_DEM_FIM_DFC_MDF_DiashCirNoPsblErr_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_DiashCirNoPsblErr)+8u]=CAL_DEM_FIM_DFC_MDF_DiashCirNoPsblErr_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_DiashCirNoPsblErr)+9u]=CAL_DEM_FIM_DFC_MDF_DiashCirNoPsblErr_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_EmacBlkdErr)]=CAL_DEM_FIM_DFC_MDF_EmacBlkdErr_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_EmacBlkdErr)+1u]=CAL_DEM_FIM_DFC_MDF_EmacBlkdErr_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_EmacBlkdErr)+2u]=CAL_DEM_FIM_DFC_MDF_EmacBlkdErr_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_EmacBlkdErr)+3u]=CAL_DEM_FIM_DFC_MDF_EmacBlkdErr_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_EmacBlkdErr)+4u]=CAL_DEM_FIM_DFC_MDF_EmacBlkdErr_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_EmacBlkdErr)+5u]=CAL_DEM_FIM_DFC_MDF_EmacBlkdErr_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_EmacBlkdErr)+6u]=CAL_DEM_FIM_DFC_MDF_EmacBlkdErr_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_EmacBlkdErr)+7u]=CAL_DEM_FIM_DFC_MDF_EmacBlkdErr_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_EmacBlkdErr)+8u]=CAL_DEM_FIM_DFC_MDF_EmacBlkdErr_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_EmacBlkdErr)+9u]=CAL_DEM_FIM_DFC_MDF_EmacBlkdErr_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_EmacBlkdWarn)]=CAL_DEM_FIM_DFC_MDF_EmacBlkdWarn_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_EmacBlkdWarn)+1u]=CAL_DEM_FIM_DFC_MDF_EmacBlkdWarn_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_EmacBlkdWarn)+2u]=CAL_DEM_FIM_DFC_MDF_EmacBlkdWarn_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_EmacBlkdWarn)+3u]=CAL_DEM_FIM_DFC_MDF_EmacBlkdWarn_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_EmacBlkdWarn)+4u]=CAL_DEM_FIM_DFC_MDF_EmacBlkdWarn_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_EmacBlkdWarn)+5u]=CAL_DEM_FIM_DFC_MDF_EmacBlkdWarn_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_EmacBlkdWarn)+6u]=CAL_DEM_FIM_DFC_MDF_EmacBlkdWarn_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_EmacBlkdWarn)+7u]=CAL_DEM_FIM_DFC_MDF_EmacBlkdWarn_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_EmacBlkdWarn)+8u]=CAL_DEM_FIM_DFC_MDF_EmacBlkdWarn_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_EmacBlkdWarn)+9u]=CAL_DEM_FIM_DFC_MDF_EmacBlkdWarn_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_ICtlRatErr)]=CAL_DEM_FIM_DFC_MDF_ICtlRatErr_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_ICtlRatErr)+1u]=CAL_DEM_FIM_DFC_MDF_ICtlRatErr_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_ICtlRatErr)+2u]=CAL_DEM_FIM_DFC_MDF_ICtlRatErr_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_ICtlRatErr)+3u]=CAL_DEM_FIM_DFC_MDF_ICtlRatErr_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_ICtlRatErr)+4u]=CAL_DEM_FIM_DFC_MDF_ICtlRatErr_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_ICtlRatErr)+5u]=CAL_DEM_FIM_DFC_MDF_ICtlRatErr_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_ICtlRatErr)+6u]=CAL_DEM_FIM_DFC_MDF_ICtlRatErr_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_ICtlRatErr)+7u]=CAL_DEM_FIM_DFC_MDF_ICtlRatErr_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_ICtlRatErr)+8u]=CAL_DEM_FIM_DFC_MDF_ICtlRatErr_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_ICtlRatErr)+9u]=CAL_DEM_FIM_DFC_MDF_ICtlRatErr_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_IsOvHiErr)]=CAL_DEM_FIM_DFC_MDF_IsOvHiErr_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_IsOvHiErr)+1u]=CAL_DEM_FIM_DFC_MDF_IsOvHiErr_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_IsOvHiErr)+2u]=CAL_DEM_FIM_DFC_MDF_IsOvHiErr_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_IsOvHiErr)+3u]=CAL_DEM_FIM_DFC_MDF_IsOvHiErr_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_IsOvHiErr)+4u]=CAL_DEM_FIM_DFC_MDF_IsOvHiErr_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_IsOvHiErr)+5u]=CAL_DEM_FIM_DFC_MDF_IsOvHiErr_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_IsOvHiErr)+6u]=CAL_DEM_FIM_DFC_MDF_IsOvHiErr_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_IsOvHiErr)+7u]=CAL_DEM_FIM_DFC_MDF_IsOvHiErr_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_IsOvHiErr)+8u]=CAL_DEM_FIM_DFC_MDF_IsOvHiErr_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_IsOvHiErr)+9u]=CAL_DEM_FIM_DFC_MDF_IsOvHiErr_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_OpenCirNoPsblErr)]=CAL_DEM_FIM_DFC_MDF_OpenCirNoPsblErr_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_OpenCirNoPsblErr)+1u]=CAL_DEM_FIM_DFC_MDF_OpenCirNoPsblErr_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_OpenCirNoPsblErr)+2u]=CAL_DEM_FIM_DFC_MDF_OpenCirNoPsblErr_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_OpenCirNoPsblErr)+3u]=CAL_DEM_FIM_DFC_MDF_OpenCirNoPsblErr_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_OpenCirNoPsblErr)+4u]=CAL_DEM_FIM_DFC_MDF_OpenCirNoPsblErr_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_OpenCirNoPsblErr)+5u]=CAL_DEM_FIM_DFC_MDF_OpenCirNoPsblErr_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_OpenCirNoPsblErr)+6u]=CAL_DEM_FIM_DFC_MDF_OpenCirNoPsblErr_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_OpenCirNoPsblErr)+7u]=CAL_DEM_FIM_DFC_MDF_OpenCirNoPsblErr_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_OpenCirNoPsblErr)+8u]=CAL_DEM_FIM_DFC_MDF_OpenCirNoPsblErr_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_OpenCirNoPsblErr)+9u]=CAL_DEM_FIM_DFC_MDF_OpenCirNoPsblErr_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_OperOutdRngErr)]=CAL_DEM_FIM_DFC_MDF_OperOutdRngErr_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_OperOutdRngErr)+1u]=CAL_DEM_FIM_DFC_MDF_OperOutdRngErr_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_OperOutdRngErr)+2u]=CAL_DEM_FIM_DFC_MDF_OperOutdRngErr_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_OperOutdRngErr)+3u]=CAL_DEM_FIM_DFC_MDF_OperOutdRngErr_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_OperOutdRngErr)+4u]=CAL_DEM_FIM_DFC_MDF_OperOutdRngErr_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_OperOutdRngErr)+5u]=CAL_DEM_FIM_DFC_MDF_OperOutdRngErr_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_OperOutdRngErr)+6u]=CAL_DEM_FIM_DFC_MDF_OperOutdRngErr_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_OperOutdRngErr)+7u]=CAL_DEM_FIM_DFC_MDF_OperOutdRngErr_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_OperOutdRngErr)+8u]=CAL_DEM_FIM_DFC_MDF_OperOutdRngErr_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_OperOutdRngErr)+9u]=CAL_DEM_FIM_DFC_MDF_OperOutdRngErr_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_PhaseLossFaultErr)]=CAL_DEM_FIM_DFC_MDF_PhaseLossFaultErr_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_PhaseLossFaultErr)+1u]=CAL_DEM_FIM_DFC_MDF_PhaseLossFaultErr_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_PhaseLossFaultErr)+2u]=CAL_DEM_FIM_DFC_MDF_PhaseLossFaultErr_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_PhaseLossFaultErr)+3u]=CAL_DEM_FIM_DFC_MDF_PhaseLossFaultErr_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_PhaseLossFaultErr)+4u]=CAL_DEM_FIM_DFC_MDF_PhaseLossFaultErr_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_PhaseLossFaultErr)+5u]=CAL_DEM_FIM_DFC_MDF_PhaseLossFaultErr_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_PhaseLossFaultErr)+6u]=CAL_DEM_FIM_DFC_MDF_PhaseLossFaultErr_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_PhaseLossFaultErr)+7u]=CAL_DEM_FIM_DFC_MDF_PhaseLossFaultErr_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_PhaseLossFaultErr)+8u]=CAL_DEM_FIM_DFC_MDF_PhaseLossFaultErr_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_PhaseLossFaultErr)+9u]=CAL_DEM_FIM_DFC_MDF_PhaseLossFaultErr_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_PrfElDrvErr)]=CAL_DEM_FIM_DFC_MDF_PrfElDrvErr_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_PrfElDrvErr)+1u]=CAL_DEM_FIM_DFC_MDF_PrfElDrvErr_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_PrfElDrvErr)+2u]=CAL_DEM_FIM_DFC_MDF_PrfElDrvErr_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_PrfElDrvErr)+3u]=CAL_DEM_FIM_DFC_MDF_PrfElDrvErr_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_PrfElDrvErr)+4u]=CAL_DEM_FIM_DFC_MDF_PrfElDrvErr_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_PrfElDrvErr)+5u]=CAL_DEM_FIM_DFC_MDF_PrfElDrvErr_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_PrfElDrvErr)+6u]=CAL_DEM_FIM_DFC_MDF_PrfElDrvErr_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_PrfElDrvErr)+7u]=CAL_DEM_FIM_DFC_MDF_PrfElDrvErr_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_PrfElDrvErr)+8u]=CAL_DEM_FIM_DFC_MDF_PrfElDrvErr_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_MDF_PrfElDrvErr)+9u]=CAL_DEM_FIM_DFC_MDF_PrfElDrvErr_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_ActOvTiErr)]=CAL_DEM_FIM_DFC_PCF_ActOvTiErr_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_ActOvTiErr)+1u]=CAL_DEM_FIM_DFC_PCF_ActOvTiErr_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_ActOvTiErr)+2u]=CAL_DEM_FIM_DFC_PCF_ActOvTiErr_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_ActOvTiErr)+3u]=CAL_DEM_FIM_DFC_PCF_ActOvTiErr_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_ActOvTiErr)+4u]=CAL_DEM_FIM_DFC_PCF_ActOvTiErr_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_ActOvTiErr)+5u]=CAL_DEM_FIM_DFC_PCF_ActOvTiErr_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_ActOvTiErr)+6u]=CAL_DEM_FIM_DFC_PCF_ActOvTiErr_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_ActOvTiErr)+7u]=CAL_DEM_FIM_DFC_PCF_ActOvTiErr_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_ActOvTiErr)+8u]=CAL_DEM_FIM_DFC_PCF_ActOvTiErr_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_ActOvTiErr)+9u]=CAL_DEM_FIM_DFC_PCF_ActOvTiErr_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_IdcOvErr)]=CAL_DEM_FIM_DFC_PCF_IdcOvErr_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_IdcOvErr)+1u]=CAL_DEM_FIM_DFC_PCF_IdcOvErr_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_IdcOvErr)+2u]=CAL_DEM_FIM_DFC_PCF_IdcOvErr_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_IdcOvErr)+3u]=CAL_DEM_FIM_DFC_PCF_IdcOvErr_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_IdcOvErr)+4u]=CAL_DEM_FIM_DFC_PCF_IdcOvErr_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_IdcOvErr)+5u]=CAL_DEM_FIM_DFC_PCF_IdcOvErr_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_IdcOvErr)+6u]=CAL_DEM_FIM_DFC_PCF_IdcOvErr_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_IdcOvErr)+7u]=CAL_DEM_FIM_DFC_PCF_IdcOvErr_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_IdcOvErr)+8u]=CAL_DEM_FIM_DFC_PCF_IdcOvErr_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_IdcOvErr)+9u]=CAL_DEM_FIM_DFC_PCF_IdcOvErr_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_SelfcheckErr)]=CAL_DEM_FIM_DFC_PCF_SelfcheckErr_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_SelfcheckErr)+1u]=CAL_DEM_FIM_DFC_PCF_SelfcheckErr_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_SelfcheckErr)+2u]=CAL_DEM_FIM_DFC_PCF_SelfcheckErr_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_SelfcheckErr)+3u]=CAL_DEM_FIM_DFC_PCF_SelfcheckErr_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_SelfcheckErr)+4u]=CAL_DEM_FIM_DFC_PCF_SelfcheckErr_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_SelfcheckErr)+5u]=CAL_DEM_FIM_DFC_PCF_SelfcheckErr_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_SelfcheckErr)+6u]=CAL_DEM_FIM_DFC_PCF_SelfcheckErr_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_SelfcheckErr)+7u]=CAL_DEM_FIM_DFC_PCF_SelfcheckErr_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_SelfcheckErr)+8u]=CAL_DEM_FIM_DFC_PCF_SelfcheckErr_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_SelfcheckErr)+9u]=CAL_DEM_FIM_DFC_PCF_SelfcheckErr_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_SenClbErr)]=CAL_DEM_FIM_DFC_PCF_SenClbErr_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_SenClbErr)+1u]=CAL_DEM_FIM_DFC_PCF_SenClbErr_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_SenClbErr)+2u]=CAL_DEM_FIM_DFC_PCF_SenClbErr_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_SenClbErr)+3u]=CAL_DEM_FIM_DFC_PCF_SenClbErr_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_SenClbErr)+4u]=CAL_DEM_FIM_DFC_PCF_SenClbErr_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_SenClbErr)+5u]=CAL_DEM_FIM_DFC_PCF_SenClbErr_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_SenClbErr)+6u]=CAL_DEM_FIM_DFC_PCF_SenClbErr_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_SenClbErr)+7u]=CAL_DEM_FIM_DFC_PCF_SenClbErr_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_SenClbErr)+8u]=CAL_DEM_FIM_DFC_PCF_SenClbErr_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_SenClbErr)+9u]=CAL_DEM_FIM_DFC_PCF_SenClbErr_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_SenOvErr)]=CAL_DEM_FIM_DFC_PCF_SenOvErr_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_SenOvErr)+1u]=CAL_DEM_FIM_DFC_PCF_SenOvErr_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_SenOvErr)+2u]=CAL_DEM_FIM_DFC_PCF_SenOvErr_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_SenOvErr)+3u]=CAL_DEM_FIM_DFC_PCF_SenOvErr_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_SenOvErr)+4u]=CAL_DEM_FIM_DFC_PCF_SenOvErr_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_SenOvErr)+5u]=CAL_DEM_FIM_DFC_PCF_SenOvErr_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_SenOvErr)+6u]=CAL_DEM_FIM_DFC_PCF_SenOvErr_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_SenOvErr)+7u]=CAL_DEM_FIM_DFC_PCF_SenOvErr_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_SenOvErr)+8u]=CAL_DEM_FIM_DFC_PCF_SenOvErr_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_SenOvErr)+9u]=CAL_DEM_FIM_DFC_PCF_SenOvErr_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_StallRetryErr)]=CAL_DEM_FIM_DFC_PCF_StallRetryErr_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_StallRetryErr)+1u]=CAL_DEM_FIM_DFC_PCF_StallRetryErr_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_StallRetryErr)+2u]=CAL_DEM_FIM_DFC_PCF_StallRetryErr_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_StallRetryErr)+3u]=CAL_DEM_FIM_DFC_PCF_StallRetryErr_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_StallRetryErr)+4u]=CAL_DEM_FIM_DFC_PCF_StallRetryErr_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_StallRetryErr)+5u]=CAL_DEM_FIM_DFC_PCF_StallRetryErr_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_StallRetryErr)+6u]=CAL_DEM_FIM_DFC_PCF_StallRetryErr_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_StallRetryErr)+7u]=CAL_DEM_FIM_DFC_PCF_StallRetryErr_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_StallRetryErr)+8u]=CAL_DEM_FIM_DFC_PCF_StallRetryErr_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_StallRetryErr)+9u]=CAL_DEM_FIM_DFC_PCF_StallRetryErr_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_StallWarn)]=CAL_DEM_FIM_DFC_PCF_StallWarn_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_StallWarn)+1u]=CAL_DEM_FIM_DFC_PCF_StallWarn_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_StallWarn)+2u]=CAL_DEM_FIM_DFC_PCF_StallWarn_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_StallWarn)+3u]=CAL_DEM_FIM_DFC_PCF_StallWarn_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_StallWarn)+4u]=CAL_DEM_FIM_DFC_PCF_StallWarn_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_StallWarn)+5u]=CAL_DEM_FIM_DFC_PCF_StallWarn_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_StallWarn)+6u]=CAL_DEM_FIM_DFC_PCF_StallWarn_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_StallWarn)+7u]=CAL_DEM_FIM_DFC_PCF_StallWarn_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_StallWarn)+8u]=CAL_DEM_FIM_DFC_PCF_StallWarn_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_StallWarn)+9u]=CAL_DEM_FIM_DFC_PCF_StallWarn_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_UnexpPosErr)]=CAL_DEM_FIM_DFC_PCF_UnexpPosErr_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_UnexpPosErr)+1u]=CAL_DEM_FIM_DFC_PCF_UnexpPosErr_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_UnexpPosErr)+2u]=CAL_DEM_FIM_DFC_PCF_UnexpPosErr_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_UnexpPosErr)+3u]=CAL_DEM_FIM_DFC_PCF_UnexpPosErr_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_UnexpPosErr)+4u]=CAL_DEM_FIM_DFC_PCF_UnexpPosErr_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_UnexpPosErr)+5u]=CAL_DEM_FIM_DFC_PCF_UnexpPosErr_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_UnexpPosErr)+6u]=CAL_DEM_FIM_DFC_PCF_UnexpPosErr_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_UnexpPosErr)+7u]=CAL_DEM_FIM_DFC_PCF_UnexpPosErr_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_UnexpPosErr)+8u]=CAL_DEM_FIM_DFC_PCF_UnexpPosErr_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_PCF_UnexpPosErr)+9u]=CAL_DEM_FIM_DFC_PCF_UnexpPosErr_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RCF_AccOvTiErr)]=CAL_DEM_FIM_DFC_RCF_AccOvTiErr_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RCF_AccOvTiErr)+1u]=CAL_DEM_FIM_DFC_RCF_AccOvTiErr_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RCF_AccOvTiErr)+2u]=CAL_DEM_FIM_DFC_RCF_AccOvTiErr_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RCF_AccOvTiErr)+3u]=CAL_DEM_FIM_DFC_RCF_AccOvTiErr_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RCF_AccOvTiErr)+4u]=CAL_DEM_FIM_DFC_RCF_AccOvTiErr_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RCF_AccOvTiErr)+5u]=CAL_DEM_FIM_DFC_RCF_AccOvTiErr_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RCF_AccOvTiErr)+6u]=CAL_DEM_FIM_DFC_RCF_AccOvTiErr_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RCF_AccOvTiErr)+7u]=CAL_DEM_FIM_DFC_RCF_AccOvTiErr_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RCF_AccOvTiErr)+8u]=CAL_DEM_FIM_DFC_RCF_AccOvTiErr_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RCF_AccOvTiErr)+9u]=CAL_DEM_FIM_DFC_RCF_AccOvTiErr_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RCF_EstOfsErr)]=CAL_DEM_FIM_DFC_RCF_EstOfsErr_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RCF_EstOfsErr)+1u]=CAL_DEM_FIM_DFC_RCF_EstOfsErr_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RCF_EstOfsErr)+2u]=CAL_DEM_FIM_DFC_RCF_EstOfsErr_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RCF_EstOfsErr)+3u]=CAL_DEM_FIM_DFC_RCF_EstOfsErr_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RCF_EstOfsErr)+4u]=CAL_DEM_FIM_DFC_RCF_EstOfsErr_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RCF_EstOfsErr)+5u]=CAL_DEM_FIM_DFC_RCF_EstOfsErr_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RCF_EstOfsErr)+6u]=CAL_DEM_FIM_DFC_RCF_EstOfsErr_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RCF_EstOfsErr)+7u]=CAL_DEM_FIM_DFC_RCF_EstOfsErr_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RCF_EstOfsErr)+8u]=CAL_DEM_FIM_DFC_RCF_EstOfsErr_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RCF_EstOfsErr)+9u]=CAL_DEM_FIM_DFC_RCF_EstOfsErr_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RCF_FwlBwdOvTiErr)]=CAL_DEM_FIM_DFC_RCF_FwlBwdOvTiErr_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RCF_FwlBwdOvTiErr)+1u]=CAL_DEM_FIM_DFC_RCF_FwlBwdOvTiErr_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RCF_FwlBwdOvTiErr)+2u]=CAL_DEM_FIM_DFC_RCF_FwlBwdOvTiErr_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RCF_FwlBwdOvTiErr)+3u]=CAL_DEM_FIM_DFC_RCF_FwlBwdOvTiErr_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RCF_FwlBwdOvTiErr)+4u]=CAL_DEM_FIM_DFC_RCF_FwlBwdOvTiErr_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RCF_FwlBwdOvTiErr)+5u]=CAL_DEM_FIM_DFC_RCF_FwlBwdOvTiErr_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RCF_FwlBwdOvTiErr)+6u]=CAL_DEM_FIM_DFC_RCF_FwlBwdOvTiErr_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RCF_FwlBwdOvTiErr)+7u]=CAL_DEM_FIM_DFC_RCF_FwlBwdOvTiErr_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RCF_FwlBwdOvTiErr)+8u]=CAL_DEM_FIM_DFC_RCF_FwlBwdOvTiErr_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RCF_FwlBwdOvTiErr)+9u]=CAL_DEM_FIM_DFC_RCF_FwlBwdOvTiErr_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RCF_FwlFwdOvTiErr)]=CAL_DEM_FIM_DFC_RCF_FwlFwdOvTiErr_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RCF_FwlFwdOvTiErr)+1u]=CAL_DEM_FIM_DFC_RCF_FwlFwdOvTiErr_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RCF_FwlFwdOvTiErr)+2u]=CAL_DEM_FIM_DFC_RCF_FwlFwdOvTiErr_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RCF_FwlFwdOvTiErr)+3u]=CAL_DEM_FIM_DFC_RCF_FwlFwdOvTiErr_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RCF_FwlFwdOvTiErr)+4u]=CAL_DEM_FIM_DFC_RCF_FwlFwdOvTiErr_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RCF_FwlFwdOvTiErr)+5u]=CAL_DEM_FIM_DFC_RCF_FwlFwdOvTiErr_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RCF_FwlFwdOvTiErr)+6u]=CAL_DEM_FIM_DFC_RCF_FwlFwdOvTiErr_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RCF_FwlFwdOvTiErr)+7u]=CAL_DEM_FIM_DFC_RCF_FwlFwdOvTiErr_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RCF_FwlFwdOvTiErr)+8u]=CAL_DEM_FIM_DFC_RCF_FwlFwdOvTiErr_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RCF_FwlFwdOvTiErr)+9u]=CAL_DEM_FIM_DFC_RCF_FwlFwdOvTiErr_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RCF_OfsClbFail)]=CAL_DEM_FIM_DFC_RCF_OfsClbFail_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RCF_OfsClbFail)+1u]=CAL_DEM_FIM_DFC_RCF_OfsClbFail_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RCF_OfsClbFail)+2u]=CAL_DEM_FIM_DFC_RCF_OfsClbFail_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RCF_OfsClbFail)+3u]=CAL_DEM_FIM_DFC_RCF_OfsClbFail_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RCF_OfsClbFail)+4u]=CAL_DEM_FIM_DFC_RCF_OfsClbFail_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RCF_OfsClbFail)+5u]=CAL_DEM_FIM_DFC_RCF_OfsClbFail_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RCF_OfsClbFail)+6u]=CAL_DEM_FIM_DFC_RCF_OfsClbFail_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RCF_OfsClbFail)+7u]=CAL_DEM_FIM_DFC_RCF_OfsClbFail_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RCF_OfsClbFail)+8u]=CAL_DEM_FIM_DFC_RCF_OfsClbFail_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RCF_OfsClbFail)+9u]=CAL_DEM_FIM_DFC_RCF_OfsClbFail_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RCF_PsiOvErr)]=CAL_DEM_FIM_DFC_RCF_PsiOvErr_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RCF_PsiOvErr)+1u]=CAL_DEM_FIM_DFC_RCF_PsiOvErr_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RCF_PsiOvErr)+2u]=CAL_DEM_FIM_DFC_RCF_PsiOvErr_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RCF_PsiOvErr)+3u]=CAL_DEM_FIM_DFC_RCF_PsiOvErr_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RCF_PsiOvErr)+4u]=CAL_DEM_FIM_DFC_RCF_PsiOvErr_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RCF_PsiOvErr)+5u]=CAL_DEM_FIM_DFC_RCF_PsiOvErr_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RCF_PsiOvErr)+6u]=CAL_DEM_FIM_DFC_RCF_PsiOvErr_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RCF_PsiOvErr)+7u]=CAL_DEM_FIM_DFC_RCF_PsiOvErr_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RCF_PsiOvErr)+8u]=CAL_DEM_FIM_DFC_RCF_PsiOvErr_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RCF_PsiOvErr)+9u]=CAL_DEM_FIM_DFC_RCF_PsiOvErr_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RSL_DOSErr)]=CAL_DEM_FIM_DFC_RSL_DOSErr_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RSL_DOSErr)+1u]=CAL_DEM_FIM_DFC_RSL_DOSErr_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RSL_DOSErr)+2u]=CAL_DEM_FIM_DFC_RSL_DOSErr_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RSL_DOSErr)+3u]=CAL_DEM_FIM_DFC_RSL_DOSErr_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RSL_DOSErr)+4u]=CAL_DEM_FIM_DFC_RSL_DOSErr_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RSL_DOSErr)+5u]=CAL_DEM_FIM_DFC_RSL_DOSErr_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RSL_DOSErr)+6u]=CAL_DEM_FIM_DFC_RSL_DOSErr_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RSL_DOSErr)+7u]=CAL_DEM_FIM_DFC_RSL_DOSErr_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RSL_DOSErr)+8u]=CAL_DEM_FIM_DFC_RSL_DOSErr_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RSL_DOSErr)+9u]=CAL_DEM_FIM_DFC_RSL_DOSErr_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RSL_ExcErr)]=CAL_DEM_FIM_DFC_RSL_ExcErr_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RSL_ExcErr)+1u]=CAL_DEM_FIM_DFC_RSL_ExcErr_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RSL_ExcErr)+2u]=CAL_DEM_FIM_DFC_RSL_ExcErr_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RSL_ExcErr)+3u]=CAL_DEM_FIM_DFC_RSL_ExcErr_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RSL_ExcErr)+4u]=CAL_DEM_FIM_DFC_RSL_ExcErr_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RSL_ExcErr)+5u]=CAL_DEM_FIM_DFC_RSL_ExcErr_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RSL_ExcErr)+6u]=CAL_DEM_FIM_DFC_RSL_ExcErr_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RSL_ExcErr)+7u]=CAL_DEM_FIM_DFC_RSL_ExcErr_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RSL_ExcErr)+8u]=CAL_DEM_FIM_DFC_RSL_ExcErr_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RSL_ExcErr)+9u]=CAL_DEM_FIM_DFC_RSL_ExcErr_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RSL_LOSErr)]=CAL_DEM_FIM_DFC_RSL_LOSErr_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RSL_LOSErr)+1u]=CAL_DEM_FIM_DFC_RSL_LOSErr_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RSL_LOSErr)+2u]=CAL_DEM_FIM_DFC_RSL_LOSErr_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RSL_LOSErr)+3u]=CAL_DEM_FIM_DFC_RSL_LOSErr_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RSL_LOSErr)+4u]=CAL_DEM_FIM_DFC_RSL_LOSErr_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RSL_LOSErr)+5u]=CAL_DEM_FIM_DFC_RSL_LOSErr_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RSL_LOSErr)+6u]=CAL_DEM_FIM_DFC_RSL_LOSErr_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RSL_LOSErr)+7u]=CAL_DEM_FIM_DFC_RSL_LOSErr_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RSL_LOSErr)+8u]=CAL_DEM_FIM_DFC_RSL_LOSErr_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RSL_LOSErr)+9u]=CAL_DEM_FIM_DFC_RSL_LOSErr_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RSL_LOTErr)]=CAL_DEM_FIM_DFC_RSL_LOTErr_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RSL_LOTErr)+1u]=CAL_DEM_FIM_DFC_RSL_LOTErr_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RSL_LOTErr)+2u]=CAL_DEM_FIM_DFC_RSL_LOTErr_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RSL_LOTErr)+3u]=CAL_DEM_FIM_DFC_RSL_LOTErr_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RSL_LOTErr)+4u]=CAL_DEM_FIM_DFC_RSL_LOTErr_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RSL_LOTErr)+5u]=CAL_DEM_FIM_DFC_RSL_LOTErr_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RSL_LOTErr)+6u]=CAL_DEM_FIM_DFC_RSL_LOTErr_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RSL_LOTErr)+7u]=CAL_DEM_FIM_DFC_RSL_LOTErr_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RSL_LOTErr)+8u]=CAL_DEM_FIM_DFC_RSL_LOTErr_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_RSL_LOTErr)+9u]=CAL_DEM_FIM_DFC_RSL_LOTErr_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_SCF_DisChgOvTiFail)]=CAL_DEM_FIM_DFC_SCF_DisChgOvTiFail_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_SCF_DisChgOvTiFail)+1u]=CAL_DEM_FIM_DFC_SCF_DisChgOvTiFail_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_SCF_DisChgOvTiFail)+2u]=CAL_DEM_FIM_DFC_SCF_DisChgOvTiFail_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_SCF_DisChgOvTiFail)+3u]=CAL_DEM_FIM_DFC_SCF_DisChgOvTiFail_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_SCF_DisChgOvTiFail)+4u]=CAL_DEM_FIM_DFC_SCF_DisChgOvTiFail_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_SCF_DisChgOvTiFail)+5u]=CAL_DEM_FIM_DFC_SCF_DisChgOvTiFail_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_SCF_DisChgOvTiFail)+6u]=CAL_DEM_FIM_DFC_SCF_DisChgOvTiFail_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_SCF_DisChgOvTiFail)+7u]=CAL_DEM_FIM_DFC_SCF_DisChgOvTiFail_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_SCF_DisChgOvTiFail)+8u]=CAL_DEM_FIM_DFC_SCF_DisChgOvTiFail_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_SCF_DisChgOvTiFail)+9u]=CAL_DEM_FIM_DFC_SCF_DisChgOvTiFail_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_SCF_LowPwrShtDwnOvTiFail)]=CAL_DEM_FIM_DFC_SCF_LowPwrShtDwnOvTiFail_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_SCF_LowPwrShtDwnOvTiFail)+1u]=CAL_DEM_FIM_DFC_SCF_LowPwrShtDwnOvTiFail_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_SCF_LowPwrShtDwnOvTiFail)+2u]=CAL_DEM_FIM_DFC_SCF_LowPwrShtDwnOvTiFail_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_SCF_LowPwrShtDwnOvTiFail)+3u]=CAL_DEM_FIM_DFC_SCF_LowPwrShtDwnOvTiFail_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_SCF_LowPwrShtDwnOvTiFail)+4u]=CAL_DEM_FIM_DFC_SCF_LowPwrShtDwnOvTiFail_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_SCF_LowPwrShtDwnOvTiFail)+5u]=CAL_DEM_FIM_DFC_SCF_LowPwrShtDwnOvTiFail_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_SCF_LowPwrShtDwnOvTiFail)+6u]=CAL_DEM_FIM_DFC_SCF_LowPwrShtDwnOvTiFail_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_SCF_LowPwrShtDwnOvTiFail)+7u]=CAL_DEM_FIM_DFC_SCF_LowPwrShtDwnOvTiFail_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_SCF_LowPwrShtDwnOvTiFail)+8u]=CAL_DEM_FIM_DFC_SCF_LowPwrShtDwnOvTiFail_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_SCF_LowPwrShtDwnOvTiFail)+9u]=CAL_DEM_FIM_DFC_SCF_LowPwrShtDwnOvTiFail_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_SCF_RunToDischarErr)]=CAL_DEM_FIM_DFC_SCF_RunToDischarErr_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_SCF_RunToDischarErr)+1u]=CAL_DEM_FIM_DFC_SCF_RunToDischarErr_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_SCF_RunToDischarErr)+2u]=CAL_DEM_FIM_DFC_SCF_RunToDischarErr_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_SCF_RunToDischarErr)+3u]=CAL_DEM_FIM_DFC_SCF_RunToDischarErr_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_SCF_RunToDischarErr)+4u]=CAL_DEM_FIM_DFC_SCF_RunToDischarErr_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_SCF_RunToDischarErr)+5u]=CAL_DEM_FIM_DFC_SCF_RunToDischarErr_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_SCF_RunToDischarErr)+6u]=CAL_DEM_FIM_DFC_SCF_RunToDischarErr_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_SCF_RunToDischarErr)+7u]=CAL_DEM_FIM_DFC_SCF_RunToDischarErr_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_SCF_RunToDischarErr)+8u]=CAL_DEM_FIM_DFC_SCF_RunToDischarErr_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_SCF_RunToDischarErr)+9u]=CAL_DEM_FIM_DFC_SCF_RunToDischarErr_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_SpdOvHiLimFail)]=CAL_DEM_FIM_DFC_TPC_SpdOvHiLimFail_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_SpdOvHiLimFail)+1u]=CAL_DEM_FIM_DFC_TPC_SpdOvHiLimFail_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_SpdOvHiLimFail)+2u]=CAL_DEM_FIM_DFC_TPC_SpdOvHiLimFail_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_SpdOvHiLimFail)+3u]=CAL_DEM_FIM_DFC_TPC_SpdOvHiLimFail_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_SpdOvHiLimFail)+4u]=CAL_DEM_FIM_DFC_TPC_SpdOvHiLimFail_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_SpdOvHiLimFail)+5u]=CAL_DEM_FIM_DFC_TPC_SpdOvHiLimFail_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_SpdOvHiLimFail)+6u]=CAL_DEM_FIM_DFC_TPC_SpdOvHiLimFail_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_SpdOvHiLimFail)+7u]=CAL_DEM_FIM_DFC_TPC_SpdOvHiLimFail_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_SpdOvHiLimFail)+8u]=CAL_DEM_FIM_DFC_TPC_SpdOvHiLimFail_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_SpdOvHiLimFail)+9u]=CAL_DEM_FIM_DFC_TPC_SpdOvHiLimFail_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_SpdOvHiWarn)]=CAL_DEM_FIM_DFC_TPC_SpdOvHiWarn_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_SpdOvHiWarn)+1u]=CAL_DEM_FIM_DFC_TPC_SpdOvHiWarn_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_SpdOvHiWarn)+2u]=CAL_DEM_FIM_DFC_TPC_SpdOvHiWarn_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_SpdOvHiWarn)+3u]=CAL_DEM_FIM_DFC_TPC_SpdOvHiWarn_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_SpdOvHiWarn)+4u]=CAL_DEM_FIM_DFC_TPC_SpdOvHiWarn_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_SpdOvHiWarn)+5u]=CAL_DEM_FIM_DFC_TPC_SpdOvHiWarn_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_SpdOvHiWarn)+6u]=CAL_DEM_FIM_DFC_TPC_SpdOvHiWarn_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_SpdOvHiWarn)+7u]=CAL_DEM_FIM_DFC_TPC_SpdOvHiWarn_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_SpdOvHiWarn)+8u]=CAL_DEM_FIM_DFC_TPC_SpdOvHiWarn_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_SpdOvHiWarn)+9u]=CAL_DEM_FIM_DFC_TPC_SpdOvHiWarn_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TCoolantOvHiWarn)]=CAL_DEM_FIM_DFC_TPC_TCoolantOvHiWarn_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TCoolantOvHiWarn)+1u]=CAL_DEM_FIM_DFC_TPC_TCoolantOvHiWarn_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TCoolantOvHiWarn)+2u]=CAL_DEM_FIM_DFC_TPC_TCoolantOvHiWarn_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TCoolantOvHiWarn)+3u]=CAL_DEM_FIM_DFC_TPC_TCoolantOvHiWarn_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TCoolantOvHiWarn)+4u]=CAL_DEM_FIM_DFC_TPC_TCoolantOvHiWarn_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TCoolantOvHiWarn)+5u]=CAL_DEM_FIM_DFC_TPC_TCoolantOvHiWarn_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TCoolantOvHiWarn)+6u]=CAL_DEM_FIM_DFC_TPC_TCoolantOvHiWarn_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TCoolantOvHiWarn)+7u]=CAL_DEM_FIM_DFC_TPC_TCoolantOvHiWarn_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TCoolantOvHiWarn)+8u]=CAL_DEM_FIM_DFC_TPC_TCoolantOvHiWarn_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TCoolantOvHiWarn)+9u]=CAL_DEM_FIM_DFC_TPC_TCoolantOvHiWarn_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcOvHiWarn)]=CAL_DEM_FIM_DFC_TPC_TDbcOvHiWarn_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcOvHiWarn)+1u]=CAL_DEM_FIM_DFC_TPC_TDbcOvHiWarn_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcOvHiWarn)+2u]=CAL_DEM_FIM_DFC_TPC_TDbcOvHiWarn_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcOvHiWarn)+3u]=CAL_DEM_FIM_DFC_TPC_TDbcOvHiWarn_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcOvHiWarn)+4u]=CAL_DEM_FIM_DFC_TPC_TDbcOvHiWarn_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcOvHiWarn)+5u]=CAL_DEM_FIM_DFC_TPC_TDbcOvHiWarn_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcOvHiWarn)+6u]=CAL_DEM_FIM_DFC_TPC_TDbcOvHiWarn_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcOvHiWarn)+7u]=CAL_DEM_FIM_DFC_TPC_TDbcOvHiWarn_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcOvHiWarn)+8u]=CAL_DEM_FIM_DFC_TPC_TDbcOvHiWarn_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcOvHiWarn)+9u]=CAL_DEM_FIM_DFC_TPC_TDbcOvHiWarn_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcOvLoWarn)]=CAL_DEM_FIM_DFC_TPC_TDbcOvLoWarn_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcOvLoWarn)+1u]=CAL_DEM_FIM_DFC_TPC_TDbcOvLoWarn_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcOvLoWarn)+2u]=CAL_DEM_FIM_DFC_TPC_TDbcOvLoWarn_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcOvLoWarn)+3u]=CAL_DEM_FIM_DFC_TPC_TDbcOvLoWarn_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcOvLoWarn)+4u]=CAL_DEM_FIM_DFC_TPC_TDbcOvLoWarn_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcOvLoWarn)+5u]=CAL_DEM_FIM_DFC_TPC_TDbcOvLoWarn_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcOvLoWarn)+6u]=CAL_DEM_FIM_DFC_TPC_TDbcOvLoWarn_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcOvLoWarn)+7u]=CAL_DEM_FIM_DFC_TPC_TDbcOvLoWarn_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcOvLoWarn)+8u]=CAL_DEM_FIM_DFC_TPC_TDbcOvLoWarn_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcOvLoWarn)+9u]=CAL_DEM_FIM_DFC_TPC_TDbcOvLoWarn_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcUHiLimFail)]=CAL_DEM_FIM_DFC_TPC_TDbcUHiLimFail_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcUHiLimFail)+1u]=CAL_DEM_FIM_DFC_TPC_TDbcUHiLimFail_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcUHiLimFail)+2u]=CAL_DEM_FIM_DFC_TPC_TDbcUHiLimFail_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcUHiLimFail)+3u]=CAL_DEM_FIM_DFC_TPC_TDbcUHiLimFail_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcUHiLimFail)+4u]=CAL_DEM_FIM_DFC_TPC_TDbcUHiLimFail_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcUHiLimFail)+5u]=CAL_DEM_FIM_DFC_TPC_TDbcUHiLimFail_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcUHiLimFail)+6u]=CAL_DEM_FIM_DFC_TPC_TDbcUHiLimFail_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcUHiLimFail)+7u]=CAL_DEM_FIM_DFC_TPC_TDbcUHiLimFail_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcUHiLimFail)+8u]=CAL_DEM_FIM_DFC_TPC_TDbcUHiLimFail_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcUHiLimFail)+9u]=CAL_DEM_FIM_DFC_TPC_TDbcUHiLimFail_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcULoLimFail)]=CAL_DEM_FIM_DFC_TPC_TDbcULoLimFail_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcULoLimFail)+1u]=CAL_DEM_FIM_DFC_TPC_TDbcULoLimFail_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcULoLimFail)+2u]=CAL_DEM_FIM_DFC_TPC_TDbcULoLimFail_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcULoLimFail)+3u]=CAL_DEM_FIM_DFC_TPC_TDbcULoLimFail_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcULoLimFail)+4u]=CAL_DEM_FIM_DFC_TPC_TDbcULoLimFail_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcULoLimFail)+5u]=CAL_DEM_FIM_DFC_TPC_TDbcULoLimFail_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcULoLimFail)+6u]=CAL_DEM_FIM_DFC_TPC_TDbcULoLimFail_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcULoLimFail)+7u]=CAL_DEM_FIM_DFC_TPC_TDbcULoLimFail_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcULoLimFail)+8u]=CAL_DEM_FIM_DFC_TPC_TDbcULoLimFail_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcULoLimFail)+9u]=CAL_DEM_FIM_DFC_TPC_TDbcULoLimFail_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcVHiLimFail)]=CAL_DEM_FIM_DFC_TPC_TDbcVHiLimFail_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcVHiLimFail)+1u]=CAL_DEM_FIM_DFC_TPC_TDbcVHiLimFail_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcVHiLimFail)+2u]=CAL_DEM_FIM_DFC_TPC_TDbcVHiLimFail_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcVHiLimFail)+3u]=CAL_DEM_FIM_DFC_TPC_TDbcVHiLimFail_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcVHiLimFail)+4u]=CAL_DEM_FIM_DFC_TPC_TDbcVHiLimFail_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcVHiLimFail)+5u]=CAL_DEM_FIM_DFC_TPC_TDbcVHiLimFail_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcVHiLimFail)+6u]=CAL_DEM_FIM_DFC_TPC_TDbcVHiLimFail_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcVHiLimFail)+7u]=CAL_DEM_FIM_DFC_TPC_TDbcVHiLimFail_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcVHiLimFail)+8u]=CAL_DEM_FIM_DFC_TPC_TDbcVHiLimFail_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcVHiLimFail)+9u]=CAL_DEM_FIM_DFC_TPC_TDbcVHiLimFail_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcVLoLimFail)]=CAL_DEM_FIM_DFC_TPC_TDbcVLoLimFail_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcVLoLimFail)+1u]=CAL_DEM_FIM_DFC_TPC_TDbcVLoLimFail_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcVLoLimFail)+2u]=CAL_DEM_FIM_DFC_TPC_TDbcVLoLimFail_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcVLoLimFail)+3u]=CAL_DEM_FIM_DFC_TPC_TDbcVLoLimFail_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcVLoLimFail)+4u]=CAL_DEM_FIM_DFC_TPC_TDbcVLoLimFail_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcVLoLimFail)+5u]=CAL_DEM_FIM_DFC_TPC_TDbcVLoLimFail_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcVLoLimFail)+6u]=CAL_DEM_FIM_DFC_TPC_TDbcVLoLimFail_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcVLoLimFail)+7u]=CAL_DEM_FIM_DFC_TPC_TDbcVLoLimFail_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcVLoLimFail)+8u]=CAL_DEM_FIM_DFC_TPC_TDbcVLoLimFail_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcVLoLimFail)+9u]=CAL_DEM_FIM_DFC_TPC_TDbcVLoLimFail_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcWHiLimFail)]=CAL_DEM_FIM_DFC_TPC_TDbcWHiLimFail_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcWHiLimFail)+1u]=CAL_DEM_FIM_DFC_TPC_TDbcWHiLimFail_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcWHiLimFail)+2u]=CAL_DEM_FIM_DFC_TPC_TDbcWHiLimFail_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcWHiLimFail)+3u]=CAL_DEM_FIM_DFC_TPC_TDbcWHiLimFail_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcWHiLimFail)+4u]=CAL_DEM_FIM_DFC_TPC_TDbcWHiLimFail_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcWHiLimFail)+5u]=CAL_DEM_FIM_DFC_TPC_TDbcWHiLimFail_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcWHiLimFail)+6u]=CAL_DEM_FIM_DFC_TPC_TDbcWHiLimFail_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcWHiLimFail)+7u]=CAL_DEM_FIM_DFC_TPC_TDbcWHiLimFail_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcWHiLimFail)+8u]=CAL_DEM_FIM_DFC_TPC_TDbcWHiLimFail_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcWHiLimFail)+9u]=CAL_DEM_FIM_DFC_TPC_TDbcWHiLimFail_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcWLoLimFail)]=CAL_DEM_FIM_DFC_TPC_TDbcWLoLimFail_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcWLoLimFail)+1u]=CAL_DEM_FIM_DFC_TPC_TDbcWLoLimFail_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcWLoLimFail)+2u]=CAL_DEM_FIM_DFC_TPC_TDbcWLoLimFail_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcWLoLimFail)+3u]=CAL_DEM_FIM_DFC_TPC_TDbcWLoLimFail_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcWLoLimFail)+4u]=CAL_DEM_FIM_DFC_TPC_TDbcWLoLimFail_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcWLoLimFail)+5u]=CAL_DEM_FIM_DFC_TPC_TDbcWLoLimFail_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcWLoLimFail)+6u]=CAL_DEM_FIM_DFC_TPC_TDbcWLoLimFail_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcWLoLimFail)+7u]=CAL_DEM_FIM_DFC_TPC_TDbcWLoLimFail_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcWLoLimFail)+8u]=CAL_DEM_FIM_DFC_TPC_TDbcWLoLimFail_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDbcWLoLimFail)+9u]=CAL_DEM_FIM_DFC_TPC_TDbcWLoLimFail_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDrvBoardOvHiWarn)]=CAL_DEM_FIM_DFC_TPC_TDrvBoardOvHiWarn_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDrvBoardOvHiWarn)+1u]=CAL_DEM_FIM_DFC_TPC_TDrvBoardOvHiWarn_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDrvBoardOvHiWarn)+2u]=CAL_DEM_FIM_DFC_TPC_TDrvBoardOvHiWarn_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDrvBoardOvHiWarn)+3u]=CAL_DEM_FIM_DFC_TPC_TDrvBoardOvHiWarn_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDrvBoardOvHiWarn)+4u]=CAL_DEM_FIM_DFC_TPC_TDrvBoardOvHiWarn_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDrvBoardOvHiWarn)+5u]=CAL_DEM_FIM_DFC_TPC_TDrvBoardOvHiWarn_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDrvBoardOvHiWarn)+6u]=CAL_DEM_FIM_DFC_TPC_TDrvBoardOvHiWarn_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDrvBoardOvHiWarn)+7u]=CAL_DEM_FIM_DFC_TPC_TDrvBoardOvHiWarn_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDrvBoardOvHiWarn)+8u]=CAL_DEM_FIM_DFC_TPC_TDrvBoardOvHiWarn_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TDrvBoardOvHiWarn)+9u]=CAL_DEM_FIM_DFC_TPC_TDrvBoardOvHiWarn_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TIGBTOvHiLimErr)]=CAL_DEM_FIM_DFC_TPC_TIGBTOvHiLimErr_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TIGBTOvHiLimErr)+1u]=CAL_DEM_FIM_DFC_TPC_TIGBTOvHiLimErr_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TIGBTOvHiLimErr)+2u]=CAL_DEM_FIM_DFC_TPC_TIGBTOvHiLimErr_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TIGBTOvHiLimErr)+3u]=CAL_DEM_FIM_DFC_TPC_TIGBTOvHiLimErr_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TIGBTOvHiLimErr)+4u]=CAL_DEM_FIM_DFC_TPC_TIGBTOvHiLimErr_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TIGBTOvHiLimErr)+5u]=CAL_DEM_FIM_DFC_TPC_TIGBTOvHiLimErr_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TIGBTOvHiLimErr)+6u]=CAL_DEM_FIM_DFC_TPC_TIGBTOvHiLimErr_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TIGBTOvHiLimErr)+7u]=CAL_DEM_FIM_DFC_TPC_TIGBTOvHiLimErr_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TIGBTOvHiLimErr)+8u]=CAL_DEM_FIM_DFC_TPC_TIGBTOvHiLimErr_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TIGBTOvHiLimErr)+9u]=CAL_DEM_FIM_DFC_TPC_TIGBTOvHiLimErr_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TIGBTOvHiWarn)]=CAL_DEM_FIM_DFC_TPC_TIGBTOvHiWarn_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TIGBTOvHiWarn)+1u]=CAL_DEM_FIM_DFC_TPC_TIGBTOvHiWarn_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TIGBTOvHiWarn)+2u]=CAL_DEM_FIM_DFC_TPC_TIGBTOvHiWarn_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TIGBTOvHiWarn)+3u]=CAL_DEM_FIM_DFC_TPC_TIGBTOvHiWarn_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TIGBTOvHiWarn)+4u]=CAL_DEM_FIM_DFC_TPC_TIGBTOvHiWarn_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TIGBTOvHiWarn)+5u]=CAL_DEM_FIM_DFC_TPC_TIGBTOvHiWarn_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TIGBTOvHiWarn)+6u]=CAL_DEM_FIM_DFC_TPC_TIGBTOvHiWarn_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TIGBTOvHiWarn)+7u]=CAL_DEM_FIM_DFC_TPC_TIGBTOvHiWarn_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TIGBTOvHiWarn)+8u]=CAL_DEM_FIM_DFC_TPC_TIGBTOvHiWarn_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TIGBTOvHiWarn)+9u]=CAL_DEM_FIM_DFC_TPC_TIGBTOvHiWarn_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TIGBTOvLoWarn)]=CAL_DEM_FIM_DFC_TPC_TIGBTOvLoWarn_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TIGBTOvLoWarn)+1u]=CAL_DEM_FIM_DFC_TPC_TIGBTOvLoWarn_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TIGBTOvLoWarn)+2u]=CAL_DEM_FIM_DFC_TPC_TIGBTOvLoWarn_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TIGBTOvLoWarn)+3u]=CAL_DEM_FIM_DFC_TPC_TIGBTOvLoWarn_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TIGBTOvLoWarn)+4u]=CAL_DEM_FIM_DFC_TPC_TIGBTOvLoWarn_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TIGBTOvLoWarn)+5u]=CAL_DEM_FIM_DFC_TPC_TIGBTOvLoWarn_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TIGBTOvLoWarn)+6u]=CAL_DEM_FIM_DFC_TPC_TIGBTOvLoWarn_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TIGBTOvLoWarn)+7u]=CAL_DEM_FIM_DFC_TPC_TIGBTOvLoWarn_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TIGBTOvLoWarn)+8u]=CAL_DEM_FIM_DFC_TPC_TIGBTOvLoWarn_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TIGBTOvLoWarn)+9u]=CAL_DEM_FIM_DFC_TPC_TIGBTOvLoWarn_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TSttrOvHiLimFail)]=CAL_DEM_FIM_DFC_TPC_TSttrOvHiLimFail_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TSttrOvHiLimFail)+1u]=CAL_DEM_FIM_DFC_TPC_TSttrOvHiLimFail_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TSttrOvHiLimFail)+2u]=CAL_DEM_FIM_DFC_TPC_TSttrOvHiLimFail_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TSttrOvHiLimFail)+3u]=CAL_DEM_FIM_DFC_TPC_TSttrOvHiLimFail_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TSttrOvHiLimFail)+4u]=CAL_DEM_FIM_DFC_TPC_TSttrOvHiLimFail_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TSttrOvHiLimFail)+5u]=CAL_DEM_FIM_DFC_TPC_TSttrOvHiLimFail_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TSttrOvHiLimFail)+6u]=CAL_DEM_FIM_DFC_TPC_TSttrOvHiLimFail_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TSttrOvHiLimFail)+7u]=CAL_DEM_FIM_DFC_TPC_TSttrOvHiLimFail_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TSttrOvHiLimFail)+8u]=CAL_DEM_FIM_DFC_TPC_TSttrOvHiLimFail_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TSttrOvHiLimFail)+9u]=CAL_DEM_FIM_DFC_TPC_TSttrOvHiLimFail_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TSttrOvHiWarn)]=CAL_DEM_FIM_DFC_TPC_TSttrOvHiWarn_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TSttrOvHiWarn)+1u]=CAL_DEM_FIM_DFC_TPC_TSttrOvHiWarn_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TSttrOvHiWarn)+2u]=CAL_DEM_FIM_DFC_TPC_TSttrOvHiWarn_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TSttrOvHiWarn)+3u]=CAL_DEM_FIM_DFC_TPC_TSttrOvHiWarn_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TSttrOvHiWarn)+4u]=CAL_DEM_FIM_DFC_TPC_TSttrOvHiWarn_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TSttrOvHiWarn)+5u]=CAL_DEM_FIM_DFC_TPC_TSttrOvHiWarn_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TSttrOvHiWarn)+6u]=CAL_DEM_FIM_DFC_TPC_TSttrOvHiWarn_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TSttrOvHiWarn)+7u]=CAL_DEM_FIM_DFC_TPC_TSttrOvHiWarn_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TSttrOvHiWarn)+8u]=CAL_DEM_FIM_DFC_TPC_TSttrOvHiWarn_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TSttrOvHiWarn)+9u]=CAL_DEM_FIM_DFC_TPC_TSttrOvHiWarn_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TSttrOvLoWarn)]=CAL_DEM_FIM_DFC_TPC_TSttrOvLoWarn_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TSttrOvLoWarn)+1u]=CAL_DEM_FIM_DFC_TPC_TSttrOvLoWarn_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TSttrOvLoWarn)+2u]=CAL_DEM_FIM_DFC_TPC_TSttrOvLoWarn_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TSttrOvLoWarn)+3u]=CAL_DEM_FIM_DFC_TPC_TSttrOvLoWarn_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TSttrOvLoWarn)+4u]=CAL_DEM_FIM_DFC_TPC_TSttrOvLoWarn_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TSttrOvLoWarn)+5u]=CAL_DEM_FIM_DFC_TPC_TSttrOvLoWarn_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TSttrOvLoWarn)+6u]=CAL_DEM_FIM_DFC_TPC_TSttrOvLoWarn_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TSttrOvLoWarn)+7u]=CAL_DEM_FIM_DFC_TPC_TSttrOvLoWarn_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TSttrOvLoWarn)+8u]=CAL_DEM_FIM_DFC_TPC_TSttrOvLoWarn_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_TSttrOvLoWarn)+9u]=CAL_DEM_FIM_DFC_TPC_TSttrOvLoWarn_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_iDcLnkOvCLimFail)]=CAL_DEM_FIM_DFC_TPC_iDcLnkOvCLimFail_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_iDcLnkOvCLimFail)+1u]=CAL_DEM_FIM_DFC_TPC_iDcLnkOvCLimFail_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_iDcLnkOvCLimFail)+2u]=CAL_DEM_FIM_DFC_TPC_iDcLnkOvCLimFail_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_iDcLnkOvCLimFail)+3u]=CAL_DEM_FIM_DFC_TPC_iDcLnkOvCLimFail_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_iDcLnkOvCLimFail)+4u]=CAL_DEM_FIM_DFC_TPC_iDcLnkOvCLimFail_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_iDcLnkOvCLimFail)+5u]=CAL_DEM_FIM_DFC_TPC_iDcLnkOvCLimFail_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_iDcLnkOvCLimFail)+6u]=CAL_DEM_FIM_DFC_TPC_iDcLnkOvCLimFail_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_iDcLnkOvCLimFail)+7u]=CAL_DEM_FIM_DFC_TPC_iDcLnkOvCLimFail_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_iDcLnkOvCLimFail)+8u]=CAL_DEM_FIM_DFC_TPC_iDcLnkOvCLimFail_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_iDcLnkOvCLimFail)+9u]=CAL_DEM_FIM_DFC_TPC_iDcLnkOvCLimFail_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_iDcLnkOvcWarn)]=CAL_DEM_FIM_DFC_TPC_iDcLnkOvcWarn_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_iDcLnkOvcWarn)+1u]=CAL_DEM_FIM_DFC_TPC_iDcLnkOvcWarn_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_iDcLnkOvcWarn)+2u]=CAL_DEM_FIM_DFC_TPC_iDcLnkOvcWarn_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_iDcLnkOvcWarn)+3u]=CAL_DEM_FIM_DFC_TPC_iDcLnkOvcWarn_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_iDcLnkOvcWarn)+4u]=CAL_DEM_FIM_DFC_TPC_iDcLnkOvcWarn_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_iDcLnkOvcWarn)+5u]=CAL_DEM_FIM_DFC_TPC_iDcLnkOvcWarn_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_iDcLnkOvcWarn)+6u]=CAL_DEM_FIM_DFC_TPC_iDcLnkOvcWarn_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_iDcLnkOvcWarn)+7u]=CAL_DEM_FIM_DFC_TPC_iDcLnkOvcWarn_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_iDcLnkOvcWarn)+8u]=CAL_DEM_FIM_DFC_TPC_iDcLnkOvcWarn_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_iDcLnkOvcWarn)+9u]=CAL_DEM_FIM_DFC_TPC_iDcLnkOvcWarn_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_uDcLnkOvVLimFail)]=CAL_DEM_FIM_DFC_TPC_uDcLnkOvVLimFail_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_uDcLnkOvVLimFail)+1u]=CAL_DEM_FIM_DFC_TPC_uDcLnkOvVLimFail_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_uDcLnkOvVLimFail)+2u]=CAL_DEM_FIM_DFC_TPC_uDcLnkOvVLimFail_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_uDcLnkOvVLimFail)+3u]=CAL_DEM_FIM_DFC_TPC_uDcLnkOvVLimFail_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_uDcLnkOvVLimFail)+4u]=CAL_DEM_FIM_DFC_TPC_uDcLnkOvVLimFail_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_uDcLnkOvVLimFail)+5u]=CAL_DEM_FIM_DFC_TPC_uDcLnkOvVLimFail_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_uDcLnkOvVLimFail)+6u]=CAL_DEM_FIM_DFC_TPC_uDcLnkOvVLimFail_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_uDcLnkOvVLimFail)+7u]=CAL_DEM_FIM_DFC_TPC_uDcLnkOvVLimFail_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_uDcLnkOvVLimFail)+8u]=CAL_DEM_FIM_DFC_TPC_uDcLnkOvVLimFail_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_uDcLnkOvVLimFail)+9u]=CAL_DEM_FIM_DFC_TPC_uDcLnkOvVLimFail_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_uDcLnkOvWarn)]=CAL_DEM_FIM_DFC_TPC_uDcLnkOvWarn_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_uDcLnkOvWarn)+1u]=CAL_DEM_FIM_DFC_TPC_uDcLnkOvWarn_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_uDcLnkOvWarn)+2u]=CAL_DEM_FIM_DFC_TPC_uDcLnkOvWarn_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_uDcLnkOvWarn)+3u]=CAL_DEM_FIM_DFC_TPC_uDcLnkOvWarn_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_uDcLnkOvWarn)+4u]=CAL_DEM_FIM_DFC_TPC_uDcLnkOvWarn_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_uDcLnkOvWarn)+5u]=CAL_DEM_FIM_DFC_TPC_uDcLnkOvWarn_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_uDcLnkOvWarn)+6u]=CAL_DEM_FIM_DFC_TPC_uDcLnkOvWarn_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_uDcLnkOvWarn)+7u]=CAL_DEM_FIM_DFC_TPC_uDcLnkOvWarn_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_uDcLnkOvWarn)+8u]=CAL_DEM_FIM_DFC_TPC_uDcLnkOvWarn_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_uDcLnkOvWarn)+9u]=CAL_DEM_FIM_DFC_TPC_uDcLnkOvWarn_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_uDcLnkUnVLimFail)]=CAL_DEM_FIM_DFC_TPC_uDcLnkUnVLimFail_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_uDcLnkUnVLimFail)+1u]=CAL_DEM_FIM_DFC_TPC_uDcLnkUnVLimFail_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_uDcLnkUnVLimFail)+2u]=CAL_DEM_FIM_DFC_TPC_uDcLnkUnVLimFail_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_uDcLnkUnVLimFail)+3u]=CAL_DEM_FIM_DFC_TPC_uDcLnkUnVLimFail_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_uDcLnkUnVLimFail)+4u]=CAL_DEM_FIM_DFC_TPC_uDcLnkUnVLimFail_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_uDcLnkUnVLimFail)+5u]=CAL_DEM_FIM_DFC_TPC_uDcLnkUnVLimFail_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_uDcLnkUnVLimFail)+6u]=CAL_DEM_FIM_DFC_TPC_uDcLnkUnVLimFail_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_uDcLnkUnVLimFail)+7u]=CAL_DEM_FIM_DFC_TPC_uDcLnkUnVLimFail_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_uDcLnkUnVLimFail)+8u]=CAL_DEM_FIM_DFC_TPC_uDcLnkUnVLimFail_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_uDcLnkUnVLimFail)+9u]=CAL_DEM_FIM_DFC_TPC_uDcLnkUnVLimFail_au8[9];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_uDcLnkUnvWarn)]=CAL_DEM_FIM_DFC_TPC_uDcLnkUnvWarn_au8[0];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_uDcLnkUnvWarn)+1u]=CAL_DEM_FIM_DFC_TPC_uDcLnkUnvWarn_au8[1];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_uDcLnkUnvWarn)+2u]=CAL_DEM_FIM_DFC_TPC_uDcLnkUnvWarn_au8[2];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_uDcLnkUnvWarn)+3u]=CAL_DEM_FIM_DFC_TPC_uDcLnkUnvWarn_au8[3];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_uDcLnkUnvWarn)+4u]=CAL_DEM_FIM_DFC_TPC_uDcLnkUnvWarn_au8[4];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_uDcLnkUnvWarn)+5u]=CAL_DEM_FIM_DFC_TPC_uDcLnkUnvWarn_au8[5];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_uDcLnkUnvWarn)+6u]=CAL_DEM_FIM_DFC_TPC_uDcLnkUnvWarn_au8[6];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_uDcLnkUnvWarn)+7u]=CAL_DEM_FIM_DFC_TPC_uDcLnkUnvWarn_au8[7];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_uDcLnkUnvWarn)+8u]=CAL_DEM_FIM_DFC_TPC_uDcLnkUnvWarn_au8[8];
    FiM_CfgInhibitSourceMatrix_au16[INDEX_TRANSFORMATION(DemConf_DemEventParameter_TPC_uDcLnkUnvWarn)+9u]=CAL_DEM_FIM_DFC_TPC_uDcLnkUnvWarn_au8[9];
}
/*******************************************************************************
** Function Name    : DemEnCon_ID_Update
** Parameter[in]    : None
** Parameter[out]   : None
** Return Value     : None
** Note             : None
** Description      : Update all events' enableConditionMask with calibration variable CAL_DEM_Disbl_DFC_XXX and Macro DEM_ENCOBM_DemEnableCondition_0.
*******************************************************************************/
void DemEnCon_ID_Update( void )
{
    Dem_AllEventsParam[DemConf_DemEventParameter_ADC_UPhaseBISTFail].enableConditionMask=(CAL_DEM_Disbl_DFC_ADC_UPhaseBISTFail_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_ADC_VPhaseBISTFail].enableConditionMask=(CAL_DEM_Disbl_DFC_ADC_VPhaseBISTFail_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_ADC_WPhaseBISTFail].enableConditionMask=(CAL_DEM_Disbl_DFC_ADC_WPhaseBISTFail_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_CANSM_E_BUS_OFF_NETWORK_0].enableConditionMask=(CAL_DEM_Disbl_DFC_CANSM_E_BUS_OFF_NETWORK_0_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_CANSM_E_BUS_OFF_NETWORK_1].enableConditionMask=(CAL_DEM_Disbl_DFC_CANSM_E_BUS_OFF_NETWORK_1_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_Can_Timeout].enableConditionMask=(CAL_DEM_Disbl_DFC_Can_Timeout_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_Cpld_AliveChkErr].enableConditionMask=(CAL_DEM_Disbl_DFC_Cpld_AliveChkErr_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_Cpld_DI_ExdClk_InFail].enableConditionMask=(CAL_DEM_Disbl_DFC_Cpld_DI_ExdClk_InFail_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_Cpld_ExdClkInFail].enableConditionMask=(CAL_DEM_Disbl_DFC_Cpld_ExdClkInFail_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_Cpld_IphaOC].enableConditionMask=(CAL_DEM_Disbl_DFC_Cpld_IphaOC_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_Cpld_NEN_InFail].enableConditionMask=(CAL_DEM_Disbl_DFC_Cpld_NEN_InFail_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_Cpld_ParityChkErr].enableConditionMask=(CAL_DEM_Disbl_DFC_Cpld_ParityChkErr_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_Cpld_Rx_SelfTest_Fail].enableConditionMask=(CAL_DEM_Disbl_DFC_Cpld_Rx_SelfTest_Fail_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_Cpld_SPIComFail].enableConditionMask=(CAL_DEM_Disbl_DFC_Cpld_SPIComFail_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_Cpld_SZTKT_InFail].enableConditionMask=(CAL_DEM_Disbl_DFC_Cpld_SZTKT_InFail_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_Cpld_Short_Circuit_HS_InFail].enableConditionMask=(CAL_DEM_Disbl_DFC_Cpld_Short_Circuit_HS_InFail_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_Cpld_Short_Circuit_LS_InFail].enableConditionMask=(CAL_DEM_Disbl_DFC_Cpld_Short_Circuit_LS_InFail_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_Cpld_UdcOverVolFail].enableConditionMask=(CAL_DEM_Disbl_DFC_Cpld_UdcOverVolFail_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_Cpld_UnderVol_HS_InFail].enableConditionMask=(CAL_DEM_Disbl_DFC_Cpld_UnderVol_HS_InFail_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_Cpld_UnderVol_LS_InFail].enableConditionMask=(CAL_DEM_Disbl_DFC_Cpld_UnderVol_LS_InFail_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_Epark_OverCurFail].enableConditionMask=(CAL_DEM_Disbl_DFC_Epark_OverCurFail_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_Epark_PosMonSampFail].enableConditionMask=(CAL_DEM_Disbl_DFC_Epark_PosMonSampFail_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_Epark_PosSampFail].enableConditionMask=(CAL_DEM_Disbl_DFC_Epark_PosSampFail_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_Epark_SampFail].enableConditionMask=(CAL_DEM_Disbl_DFC_Epark_SampFail_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_Event_NvM_ReadErr].enableConditionMask=(CAL_DEM_Disbl_DFC_Event_NvM_ReadErr_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_Event_NvM_WriteErr].enableConditionMask=(CAL_DEM_Disbl_DFC_Event_NvM_WriteErr_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_FR_StorageErr].enableConditionMask=(CAL_DEM_Disbl_DFC_FR_StorageErr_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_HSPF_InvOpenErr].enableConditionMask=(CAL_DEM_Disbl_DFC_HSPF_InvOpenErr_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_HSPF_MotorOpenErr].enableConditionMask=(CAL_DEM_Disbl_DFC_HSPF_MotorOpenErr_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_HSPF_VerMatchFailureErr].enableConditionMask=(CAL_DEM_Disbl_DFC_HSPF_VerMatchFailureErr_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_HSPF_stIphaOffCalFail].enableConditionMask=(CAL_DEM_Disbl_DFC_HSPF_stIphaOffCalFail_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_HSPF_tDBCTempCmpErr].enableConditionMask=(CAL_DEM_Disbl_DFC_HSPF_tDBCTempCmpErr_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_HvMcu_ComErr].enableConditionMask=(CAL_DEM_Disbl_DFC_HvMcu_ComErr_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_HvMcu_DisChrgDutyErr].enableConditionMask=(CAL_DEM_Disbl_DFC_HvMcu_DisChrgDutyErr_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_HvMcu_DisChrgFail].enableConditionMask=(CAL_DEM_Disbl_DFC_HvMcu_DisChrgFail_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_HvMcu_DisChrgFreqErr].enableConditionMask=(CAL_DEM_Disbl_DFC_HvMcu_DisChrgFreqErr_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_HvMcu_EmerPowerSapErr].enableConditionMask=(CAL_DEM_Disbl_DFC_HvMcu_EmerPowerSapErr_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_HvMcu_UartCheckFailErr].enableConditionMask=(CAL_DEM_Disbl_DFC_HvMcu_UartCheckFailErr_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_HvMcu_UartLostFrameErr].enableConditionMask=(CAL_DEM_Disbl_DFC_HvMcu_UartLostFrameErr_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_HvMcu_UdcCheckErr].enableConditionMask=(CAL_DEM_Disbl_DFC_HvMcu_UdcCheckErr_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_HvMcu_UdcOverFlagLimit].enableConditionMask=(CAL_DEM_Disbl_DFC_HvMcu_UdcOverFlagLimit_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_HvMcu_UdcOverVolErr].enableConditionMask=(CAL_DEM_Disbl_DFC_HvMcu_UdcOverVolErr_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_IOHWAB_12VNarrSampErr].enableConditionMask=(CAL_DEM_Disbl_DFC_IOHWAB_12VNarrSampErr_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_IOHWAB_12VSampErr].enableConditionMask=(CAL_DEM_Disbl_DFC_IOHWAB_12VSampErr_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_IOHWAB_12VWideSampErr].enableConditionMask=(CAL_DEM_Disbl_DFC_IOHWAB_12VWideSampErr_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_IOHWAB_18VLwBrgSampFail].enableConditionMask=(CAL_DEM_Disbl_DFC_IOHWAB_18VLwBrgSampFail_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_IOHWAB_18VUpBrgSampFail].enableConditionMask=(CAL_DEM_Disbl_DFC_IOHWAB_18VUpBrgSampFail_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_IOHWAB_1V3MCU_SampFail].enableConditionMask=(CAL_DEM_Disbl_DFC_IOHWAB_1V3MCU_SampFail_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_IOHWAB_3V3MCU_SampFail].enableConditionMask=(CAL_DEM_Disbl_DFC_IOHWAB_3V3MCU_SampFail_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_IOHWAB_5VQcoSampFail].enableConditionMask=(CAL_DEM_Disbl_DFC_IOHWAB_5VQcoSampFail_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_IOHWAB_5VQt1SampFail].enableConditionMask=(CAL_DEM_Disbl_DFC_IOHWAB_5VQt1SampFail_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_IOHWAB_5VQt2SampFail].enableConditionMask=(CAL_DEM_Disbl_DFC_IOHWAB_5VQt2SampFail_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_IOHWAB_Cpld1v8SampFail].enableConditionMask=(CAL_DEM_Disbl_DFC_IOHWAB_Cpld1v8SampFail_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_IOHWAB_Cpld3v3SampFail].enableConditionMask=(CAL_DEM_Disbl_DFC_IOHWAB_Cpld3v3SampFail_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_IOHWAB_CrashFail].enableConditionMask=(CAL_DEM_Disbl_DFC_IOHWAB_CrashFail_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_IOHWAB_DcLnkOverVolFail].enableConditionMask=(CAL_DEM_Disbl_DFC_IOHWAB_DcLnkOverVolFail_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_IOHWAB_IphaOCFail].enableConditionMask=(CAL_DEM_Disbl_DFC_IOHWAB_IphaOCFail_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_IOHWAB_KL30OverVolErr].enableConditionMask=(CAL_DEM_Disbl_DFC_IOHWAB_KL30OverVolErr_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_IOHWAB_KL30SevOverVolFail].enableConditionMask=(CAL_DEM_Disbl_DFC_IOHWAB_KL30SevOverVolFail_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_IOHWAB_KL30SevUnderVolFail].enableConditionMask=(CAL_DEM_Disbl_DFC_IOHWAB_KL30SevUnderVolFail_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_IOHWAB_KL30UnderVolErr].enableConditionMask=(CAL_DEM_Disbl_DFC_IOHWAB_KL30UnderVolErr_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_IOHWAB_Nen33Fail].enableConditionMask=(CAL_DEM_Disbl_DFC_IOHWAB_Nen33Fail_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_IOHWAB_SttrSenorShrFail].enableConditionMask=(CAL_DEM_Disbl_DFC_IOHWAB_SttrSenorShrFail_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_IOHWAB_SttrTemp1SampFail].enableConditionMask=(CAL_DEM_Disbl_DFC_IOHWAB_SttrTemp1SampFail_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_IOHWAB_SttrTemp2SampFail].enableConditionMask=(CAL_DEM_Disbl_DFC_IOHWAB_SttrTemp2SampFail_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_IOHWAB_TCoolantSampFail].enableConditionMask=(CAL_DEM_Disbl_DFC_IOHWAB_TCoolantSampFail_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_IOHWAB_VDD5_D_SampFail].enableConditionMask=(CAL_DEM_Disbl_DFC_IOHWAB_VDD5_D_SampFail_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_IgbtDrv_ComErr].enableConditionMask=(CAL_DEM_Disbl_DFC_IgbtDrv_ComErr_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_IgbtDrv_LwBrgFaultAFail].enableConditionMask=(CAL_DEM_Disbl_DFC_IgbtDrv_LwBrgFaultAFail_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_IgbtDrv_LwBrgFaultBFail].enableConditionMask=(CAL_DEM_Disbl_DFC_IgbtDrv_LwBrgFaultBFail_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_IgbtDrv_UpBrgFaultAFail].enableConditionMask=(CAL_DEM_Disbl_DFC_IgbtDrv_UpBrgFaultAFail_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_IgbtDrv_UpBrgFaultBFail].enableConditionMask=(CAL_DEM_Disbl_DFC_IgbtDrv_UpBrgFaultBFail_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_MDF_AlOfsNoPlausErr].enableConditionMask=(CAL_DEM_Disbl_DFC_MDF_AlOfsNoPlausErr_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_MDF_DiashCirNoPsblErr].enableConditionMask=(CAL_DEM_Disbl_DFC_MDF_DiashCirNoPsblErr_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_MDF_EmacBlkdErr].enableConditionMask=(CAL_DEM_Disbl_DFC_MDF_EmacBlkdErr_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_MDF_EmacBlkdWarn].enableConditionMask=(CAL_DEM_Disbl_DFC_MDF_EmacBlkdWarn_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_MDF_ICtlRatErr].enableConditionMask=(CAL_DEM_Disbl_DFC_MDF_ICtlRatErr_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_MDF_IsOvHiErr].enableConditionMask=(CAL_DEM_Disbl_DFC_MDF_IsOvHiErr_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_MDF_OpenCirNoPsblErr].enableConditionMask=(CAL_DEM_Disbl_DFC_MDF_OpenCirNoPsblErr_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_MDF_OperOutdRngErr].enableConditionMask=(CAL_DEM_Disbl_DFC_MDF_OperOutdRngErr_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_MDF_PhaseLossFaultErr].enableConditionMask=(CAL_DEM_Disbl_DFC_MDF_PhaseLossFaultErr_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_MDF_PrfElDrvErr].enableConditionMask=(CAL_DEM_Disbl_DFC_MDF_PrfElDrvErr_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_PCF_ActOvTiErr].enableConditionMask=(CAL_DEM_Disbl_DFC_PCF_ActOvTiErr_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_PCF_IdcOvErr].enableConditionMask=(CAL_DEM_Disbl_DFC_PCF_IdcOvErr_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_PCF_SelfcheckErr].enableConditionMask=(CAL_DEM_Disbl_DFC_PCF_SelfcheckErr_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_PCF_SenClbErr].enableConditionMask=(CAL_DEM_Disbl_DFC_PCF_SenClbErr_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_PCF_SenOvErr].enableConditionMask=(CAL_DEM_Disbl_DFC_PCF_SenOvErr_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_PCF_StallRetryErr].enableConditionMask=(CAL_DEM_Disbl_DFC_PCF_StallRetryErr_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_PCF_StallWarn].enableConditionMask=(CAL_DEM_Disbl_DFC_PCF_StallWarn_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_PCF_UnexpPosErr].enableConditionMask=(CAL_DEM_Disbl_DFC_PCF_UnexpPosErr_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_RCF_AccOvTiErr].enableConditionMask=(CAL_DEM_Disbl_DFC_RCF_AccOvTiErr_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_RCF_EstOfsErr].enableConditionMask=(CAL_DEM_Disbl_DFC_RCF_EstOfsErr_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_RCF_FwlBwdOvTiErr].enableConditionMask=(CAL_DEM_Disbl_DFC_RCF_FwlBwdOvTiErr_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_RCF_FwlFwdOvTiErr].enableConditionMask=(CAL_DEM_Disbl_DFC_RCF_FwlFwdOvTiErr_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_RCF_OfsClbFail].enableConditionMask=(CAL_DEM_Disbl_DFC_RCF_OfsClbFail_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_RCF_PsiOvErr].enableConditionMask=(CAL_DEM_Disbl_DFC_RCF_PsiOvErr_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_RSL_DOSErr].enableConditionMask=(CAL_DEM_Disbl_DFC_RSL_DOSErr_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_RSL_ExcErr].enableConditionMask=(CAL_DEM_Disbl_DFC_RSL_ExcErr_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_RSL_LOSErr].enableConditionMask=(CAL_DEM_Disbl_DFC_RSL_LOSErr_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_RSL_LOTErr].enableConditionMask=(CAL_DEM_Disbl_DFC_RSL_LOTErr_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_SCF_DisChgOvTiFail].enableConditionMask=(CAL_DEM_Disbl_DFC_SCF_DisChgOvTiFail_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_SCF_LowPwrShtDwnOvTiFail].enableConditionMask=(CAL_DEM_Disbl_DFC_SCF_LowPwrShtDwnOvTiFail_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_SCF_RunToDischarErr].enableConditionMask=(CAL_DEM_Disbl_DFC_SCF_RunToDischarErr_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_TPC_SpdOvHiLimFail].enableConditionMask=(CAL_DEM_Disbl_DFC_TPC_SpdOvHiLimFail_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_TPC_SpdOvHiWarn].enableConditionMask=(CAL_DEM_Disbl_DFC_TPC_SpdOvHiWarn_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_TPC_TCoolantOvHiWarn].enableConditionMask=(CAL_DEM_Disbl_DFC_TPC_TCoolantOvHiWarn_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_TPC_TDbcOvHiWarn].enableConditionMask=(CAL_DEM_Disbl_DFC_TPC_TDbcOvHiWarn_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_TPC_TDbcOvLoWarn].enableConditionMask=(CAL_DEM_Disbl_DFC_TPC_TDbcOvLoWarn_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_TPC_TDbcUHiLimFail].enableConditionMask=(CAL_DEM_Disbl_DFC_TPC_TDbcUHiLimFail_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_TPC_TDbcULoLimFail].enableConditionMask=(CAL_DEM_Disbl_DFC_TPC_TDbcULoLimFail_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_TPC_TDbcVHiLimFail].enableConditionMask=(CAL_DEM_Disbl_DFC_TPC_TDbcVHiLimFail_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_TPC_TDbcVLoLimFail].enableConditionMask=(CAL_DEM_Disbl_DFC_TPC_TDbcVLoLimFail_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_TPC_TDbcWHiLimFail].enableConditionMask=(CAL_DEM_Disbl_DFC_TPC_TDbcWHiLimFail_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_TPC_TDbcWLoLimFail].enableConditionMask=(CAL_DEM_Disbl_DFC_TPC_TDbcWLoLimFail_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_TPC_TDrvBoardOvHiWarn].enableConditionMask=(CAL_DEM_Disbl_DFC_TPC_TDrvBoardOvHiWarn_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_TPC_TIGBTOvHiLimErr].enableConditionMask=(CAL_DEM_Disbl_DFC_TPC_TIGBTOvHiLimErr_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_TPC_TIGBTOvHiWarn].enableConditionMask=(CAL_DEM_Disbl_DFC_TPC_TIGBTOvHiWarn_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_TPC_TIGBTOvLoWarn].enableConditionMask=(CAL_DEM_Disbl_DFC_TPC_TIGBTOvLoWarn_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_TPC_TSttrOvHiLimFail].enableConditionMask=(CAL_DEM_Disbl_DFC_TPC_TSttrOvHiLimFail_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_TPC_TSttrOvHiWarn].enableConditionMask=(CAL_DEM_Disbl_DFC_TPC_TSttrOvHiWarn_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_TPC_TSttrOvLoWarn].enableConditionMask=(CAL_DEM_Disbl_DFC_TPC_TSttrOvLoWarn_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_TPC_iDcLnkOvCLimFail].enableConditionMask=(CAL_DEM_Disbl_DFC_TPC_iDcLnkOvCLimFail_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_TPC_iDcLnkOvcWarn].enableConditionMask=(CAL_DEM_Disbl_DFC_TPC_iDcLnkOvcWarn_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_TPC_uDcLnkOvVLimFail].enableConditionMask=(CAL_DEM_Disbl_DFC_TPC_uDcLnkOvVLimFail_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_TPC_uDcLnkOvWarn].enableConditionMask=(CAL_DEM_Disbl_DFC_TPC_uDcLnkOvWarn_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_TPC_uDcLnkUnVLimFail].enableConditionMask=(CAL_DEM_Disbl_DFC_TPC_uDcLnkUnVLimFail_u8 | DEM_ENCOBM_DemEnableCondition_0);
    Dem_AllEventsParam[DemConf_DemEventParameter_TPC_uDcLnkUnvWarn].enableConditionMask=(CAL_DEM_Disbl_DFC_TPC_uDcLnkUnvWarn_u8 | DEM_ENCOBM_DemEnableCondition_0);
}

/*******************************************************************************
** Function Name    : FiM_FIDList_Update
** Parameter[in]    : None
** Parameter[out]   : None
** Return Value     : None
** Note             : None
** Description      : Iterate all FID to get the respective permission state.
*******************************************************************************/
static void FiM_FIDList_Update(void)
{
    uint8 i_FID_NUM;
    for(i_FID_NUM=1u;i_FID_NUM<FIM_CFG_NUMBEROFFIDS + 1u;i_FID_NUM++)
        {
            (void)FiM_GetFunctionPermission(i_FID_NUM, &VAR_DEM_AllFID_Statues_au8[i_FID_NUM]);
        }
}

/*******************************************************************************
** Function Name    : DEM_EventLists_Update
** Parameter[in]    : None
** Parameter[out]   : None
** Return Value     : None
** Note             : None
** Description      : Update Event lists depending on Event kinds.
*******************************************************************************/
static void DEM_EventLists_Update(void)
{
    DEM_Failcode_Update(VAR_DEM_EventList_au8,EVENT_FAILED_CURR);
    DEM_Failcode_Update(VAR_DEM_HisEvtFailedList_au8,EVENT_FAILED_HIS);
    DEM_Failcode_Update(VAR_DEM_EvtFailed_and_Passed_TOPC_au8,EVENT_FAILED_PASSED_TOPC);
}

/*******************************************************************************
** Function Name    : DEM_Failcode_Update
** Parameter[in]    : None
** Parameter[out]   : None
** Return Value     : None
** Note             : None
** Description      : Iterate all Events to test whether it's event status bit1(TestFailedThisOperationCycle) && bit0(TestFailed) ==1,
**                    and record the event Id to array DEM_FailcpdeAR if (bit1 && bit0) == 1 is true.
*******************************************************************************/
void DEM_Failcode_Update(Dem_EventStatusExtendedType* Event_List_Kind,uint8 Event_Kind)
{
    uint8 k_new=0,i_event;
    for(i_event=1u;i_event<DEM_EVENTID_COUNT+1u;i_event++)
        {
            if(k_new < 24u)
            {
                if((DEM_ALLEvent_Status_au8[i_event] & 0x03u) == Event_Kind)
                {
                    Event_List_Kind[k_new]=i_event;
                    k_new ++;
                }
            }
            else
            {
                break;
            }
        }
}

/*******************************************************************************
** Function Name    : FID_EventTrack
** Parameter[in]    : None
** Parameter[out]    : None
** Return Value     : None
** Note             : None
** Description      : Track the event which influenced by FID8,which means that if there is a function named 8,through
**                    the service bellow you can find the influenced Events(maybe more than one).
**                    CAL_TrackFID2EventID_u8 is a calibration variable.
*******************************************************************************/
void FID_EventTrack(void)
{
#if 0
    uint16 i_FiMMatix,k_st=0;
    if(FID_Failed_State_u8 == 0)
    {
        for(i_FiMMatix=0;i_FiMMatix<(DEM_EVENTID_COUNT*10);i_FiMMatix++)
        {
            /************************FID_Failed*************************/
            if(FiM_CfgInhibitSourceMatrix_au16[i_FiMMatix] == 8)
            {
                VAR_DEM_FidTraceEvents_au8[k_st] = (i_FiMMatix/10)+1;
                if(DEM_EventIDRecorder_u8==VAR_DEM_FidTraceEvents_au8[k_st])
                {
                    VAR_DEM_FID_Failed_u8=VAR_DEM_FidTraceEvents_au8[k_st];
                }
                k_st++;
            }
        }
    }
#endif
}

/*******************************************************************************
** Function Name    : DEM_ClearTempStates
** Parameter[in]    : None
** Parameter[out]   : None
** Return Value     : None
** Note             : None
** Description      : Clear the array VAR_DEM_FidTraceEvents_au8 which storing the current EventID tracked by FID.
*******************************************************************************/
void DEM_ClearTempStates(void)
{
    uint8 i_STFID;
    for(i_STFID=0;i_STFID<DEM_EVENTID_COUNT;i_STFID++)
    {
        VAR_DEM_FidTraceEvents_au8[i_STFID]=0;
    }
}

uint8 i_HisNum;
/*******************************************************************************
** Function Name    : DEM_HistoryEventList_Record
** Parameter[in]    : None
** Parameter[out]   : None
** Return Value     : None
** Note             : None
** Description      : Record the EventID which confirmed as FAILED as historical event.
*******************************************************************************/
void DEM_HistoryEventList_Record( void )
{
    /*To Do*/
}

/*******************************************************************************
** Function Name    : DEM_SingleEventAndFidUpdate
** Parameter[in]    : None
** Parameter[out]   : None
** Return Value     : None
** Note             : None
** Description      : Get the status of a single event or the state of a single FID.
**                    CAL_TrackFID2EventID_u8 is a calibration variable for a FID.
*******************************************************************************/
static void DEM_SingleEventAndFidUpdate(void)
{
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_ADC_UPhaseBISTFail,&VAR_DEM_Event_ADC_UPhaseBISTFail_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_ADC_VPhaseBISTFail,&VAR_DEM_Event_ADC_VPhaseBISTFail_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_ADC_WPhaseBISTFail,&VAR_DEM_Event_ADC_WPhaseBISTFail_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_CANSM_E_BUS_OFF_NETWORK_0,&VAR_DEM_Event_CANSM_E_BUS_OFF_NETWORK_0_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_CANSM_E_BUS_OFF_NETWORK_1,&VAR_DEM_Event_CANSM_E_BUS_OFF_NETWORK_1_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_Can_Timeout,&VAR_DEM_Event_Can_Timeout_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_Cpld_AliveChkErr,&VAR_DEM_Event_Cpld_AliveChkErr_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_Cpld_DI_ExdClk_InFail,&VAR_DEM_Event_Cpld_DI_ExdClk_InFail_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_Cpld_ExdClkInFail,&VAR_DEM_Event_Cpld_ExdClkInFail_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_Cpld_IphaOC,&VAR_DEM_Event_Cpld_IphaOC_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_Cpld_NEN_InFail,&VAR_DEM_Event_Cpld_NEN_InFail_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_Cpld_ParityChkErr,&VAR_DEM_Event_Cpld_ParityChkErr_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_Cpld_Rx_SelfTest_Fail,&VAR_DEM_Event_Cpld_Rx_SelfTest_Fail_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_Cpld_SPIComFail,&VAR_DEM_Event_Cpld_SPIComFail_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_Cpld_SZTKT_InFail,&VAR_DEM_Event_Cpld_SZTKT_InFail_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_Cpld_Short_Circuit_HS_InFail,&VAR_DEM_Event_Cpld_Short_Circuit_HS_InFail_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_Cpld_Short_Circuit_LS_InFail,&VAR_DEM_Event_Cpld_Short_Circuit_LS_InFail_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_Cpld_UdcOverVolFail,&VAR_DEM_Event_Cpld_UdcOverVolFail_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_Cpld_UnderVol_HS_InFail,&VAR_DEM_Event_Cpld_UnderVol_HS_InFail_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_Cpld_UnderVol_LS_InFail,&VAR_DEM_Event_Cpld_UnderVol_LS_InFail_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_Epark_OverCurFail,&VAR_DEM_Event_Epark_OverCurFail_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_Epark_PosMonSampFail,&VAR_DEM_Event_Epark_PosMonSampFail_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_Epark_PosSampFail,&VAR_DEM_Event_Epark_PosSampFail_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_Epark_SampFail,&VAR_DEM_Event_Epark_SampFail_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_Event_NvM_ReadErr,&VAR_DEM_Event_Event_NvM_ReadErr_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_Event_NvM_WriteErr,&VAR_DEM_Event_Event_NvM_WriteErr_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_FR_StorageErr,&VAR_DEM_Event_FR_StorageErr_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_HSPF_InvOpenErr,&VAR_DEM_Event_HSPF_InvOpenErr_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_HSPF_MotorOpenErr,&VAR_DEM_Event_HSPF_MotorOpenErr_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_HSPF_VerMatchFailureErr,&VAR_DEM_Event_HSPF_VerMatchFailureErr_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_HSPF_stIphaOffCalFail,&VAR_DEM_Event_HSPF_stIphaOffCalFail_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_HSPF_tDBCTempCmpErr,&VAR_DEM_Event_HSPF_tDBCTempCmpErr_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_HvMcu_ComErr,&VAR_DEM_Event_HvMcu_ComErr_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_HvMcu_DisChrgDutyErr,&VAR_DEM_Event_HvMcu_DisChrgDutyErr_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_HvMcu_DisChrgFail,&VAR_DEM_Event_HvMcu_DisChrgFail_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_HvMcu_DisChrgFreqErr,&VAR_DEM_Event_HvMcu_DisChrgFreqErr_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_HvMcu_EmerPowerSapErr,&VAR_DEM_Event_HvMcu_EmerPowerSapErr_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_HvMcu_UartCheckFailErr,&VAR_DEM_Event_HvMcu_UartCheckFailErr_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_HvMcu_UartLostFrameErr,&VAR_DEM_Event_HvMcu_UartLostFrameErr_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_HvMcu_UdcCheckErr,&VAR_DEM_Event_HvMcu_UdcCheckErr_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_HvMcu_UdcOverFlagLimit,&VAR_DEM_Event_HvMcu_UdcOverFlagLimit_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_HvMcu_UdcOverVolErr,&VAR_DEM_Event_HvMcu_UdcOverVolErr_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_IOHWAB_12VNarrSampErr,&VAR_DEM_Event_IOHWAB_12VNarrSampErr_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_IOHWAB_12VSampErr,&VAR_DEM_Event_IOHWAB_12VSampErr_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_IOHWAB_12VWideSampErr,&VAR_DEM_Event_IOHWAB_12VWideSampErr_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_IOHWAB_18VLwBrgSampFail,&VAR_DEM_Event_IOHWAB_18VLwBrgSampFail_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_IOHWAB_18VUpBrgSampFail,&VAR_DEM_Event_IOHWAB_18VUpBrgSampFail_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_IOHWAB_1V3MCU_SampFail,&VAR_DEM_Event_IOHWAB_1V3MCU_SampFail_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_IOHWAB_3V3MCU_SampFail,&VAR_DEM_Event_IOHWAB_3V3MCU_SampFail_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_IOHWAB_5VQcoSampFail,&VAR_DEM_Event_IOHWAB_5VQcoSampFail_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_IOHWAB_5VQt1SampFail,&VAR_DEM_Event_IOHWAB_5VQt1SampFail_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_IOHWAB_5VQt2SampFail,&VAR_DEM_Event_IOHWAB_5VQt2SampFail_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_IOHWAB_Cpld1v8SampFail,&VAR_DEM_Event_IOHWAB_Cpld1v8SampFail_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_IOHWAB_Cpld3v3SampFail,&VAR_DEM_Event_IOHWAB_Cpld3v3SampFail_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_IOHWAB_CrashFail,&VAR_DEM_Event_IOHWAB_CrashFail_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_IOHWAB_DcLnkOverVolFail,&VAR_DEM_Event_IOHWAB_DcLnkOverVolFail_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_IOHWAB_IphaOCFail,&VAR_DEM_Event_IOHWAB_IphaOCFail_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_IOHWAB_KL30OverVolErr,&VAR_DEM_Event_IOHWAB_KL30OverVolErr_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_IOHWAB_KL30SevOverVolFail,&VAR_DEM_Event_IOHWAB_KL30SevOverVolFail_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_IOHWAB_KL30SevUnderVolFail,&VAR_DEM_Event_IOHWAB_KL30SevUnderVolFail_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_IOHWAB_KL30UnderVolErr,&VAR_DEM_Event_IOHWAB_KL30UnderVolErr_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_IOHWAB_Nen33Fail,&VAR_DEM_Event_IOHWAB_Nen33Fail_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_IOHWAB_SttrSenorShrFail,&VAR_DEM_Event_IOHWAB_SttrSenorShrFail_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_IOHWAB_SttrTemp1SampFail,&VAR_DEM_Event_IOHWAB_SttrTemp1SampFail_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_IOHWAB_SttrTemp2SampFail,&VAR_DEM_Event_IOHWAB_SttrTemp2SampFail_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_IOHWAB_TCoolantSampFail,&VAR_DEM_Event_IOHWAB_TCoolantSampFail_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_IOHWAB_VDD5_D_SampFail,&VAR_DEM_Event_IOHWAB_VDD5_D_SampFail_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_IgbtDrv_ComErr,&VAR_DEM_Event_IgbtDrv_ComErr_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_IgbtDrv_LwBrgFaultAFail,&VAR_DEM_Event_IgbtDrv_LwBrgFaultAFail_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_IgbtDrv_LwBrgFaultBFail,&VAR_DEM_Event_IgbtDrv_LwBrgFaultBFail_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_IgbtDrv_UpBrgFaultAFail,&VAR_DEM_Event_IgbtDrv_UpBrgFaultAFail_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_IgbtDrv_UpBrgFaultBFail,&VAR_DEM_Event_IgbtDrv_UpBrgFaultBFail_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_MDF_AlOfsNoPlausErr,&VAR_DEM_Event_MDF_AlOfsNoPlausErr_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_MDF_DiashCirNoPsblErr,&VAR_DEM_Event_MDF_DiashCirNoPsblErr_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_MDF_EmacBlkdErr,&VAR_DEM_Event_MDF_EmacBlkdErr_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_MDF_EmacBlkdWarn,&VAR_DEM_Event_MDF_EmacBlkdWarn_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_MDF_ICtlRatErr,&VAR_DEM_Event_MDF_ICtlRatErr_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_MDF_IsOvHiErr,&VAR_DEM_Event_MDF_IsOvHiErr_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_MDF_OpenCirNoPsblErr,&VAR_DEM_Event_MDF_OpenCirNoPsblErr_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_MDF_OperOutdRngErr,&VAR_DEM_Event_MDF_OperOutdRngErr_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_MDF_PhaseLossFaultErr,&VAR_DEM_Event_MDF_PhaseLossFaultErr_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_MDF_PrfElDrvErr,&VAR_DEM_Event_MDF_PrfElDrvErr_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_PCF_ActOvTiErr,&VAR_DEM_Event_PCF_ActOvTiErr_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_PCF_IdcOvErr,&VAR_DEM_Event_PCF_IdcOvErr_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_PCF_SelfcheckErr,&VAR_DEM_Event_PCF_SelfcheckErr_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_PCF_SenClbErr,&VAR_DEM_Event_PCF_SenClbErr_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_PCF_SenOvErr,&VAR_DEM_Event_PCF_SenOvErr_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_PCF_StallRetryErr,&VAR_DEM_Event_PCF_StallRetryErr_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_PCF_StallWarn,&VAR_DEM_Event_PCF_StallWarn_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_PCF_UnexpPosErr,&VAR_DEM_Event_PCF_UnexpPosErr_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_RCF_AccOvTiErr,&VAR_DEM_Event_RCF_AccOvTiErr_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_RCF_EstOfsErr,&VAR_DEM_Event_RCF_EstOfsErr_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_RCF_FwlBwdOvTiErr,&VAR_DEM_Event_RCF_FwlBwdOvTiErr_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_RCF_FwlFwdOvTiErr,&VAR_DEM_Event_RCF_FwlFwdOvTiErr_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_RCF_OfsClbFail,&VAR_DEM_Event_RCF_OfsClbFail_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_RCF_PsiOvErr,&VAR_DEM_Event_RCF_PsiOvErr_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_RSL_DOSErr,&VAR_DEM_Event_RSL_DOSErr_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_RSL_ExcErr,&VAR_DEM_Event_RSL_ExcErr_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_RSL_LOSErr,&VAR_DEM_Event_RSL_LOSErr_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_RSL_LOTErr,&VAR_DEM_Event_RSL_LOTErr_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_SCF_DisChgOvTiFail,&VAR_DEM_Event_SCF_DisChgOvTiFail_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_SCF_LowPwrShtDwnOvTiFail,&VAR_DEM_Event_SCF_LowPwrShtDwnOvTiFail_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_SCF_RunToDischarErr,&VAR_DEM_Event_SCF_RunToDischarErr_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_TPC_SpdOvHiLimFail,&VAR_DEM_Event_TPC_SpdOvHiLimFail_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_TPC_SpdOvHiWarn,&VAR_DEM_Event_TPC_SpdOvHiWarn_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_TPC_TCoolantOvHiWarn,&VAR_DEM_Event_TPC_TCoolantOvHiWarn_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_TPC_TDbcOvHiWarn,&VAR_DEM_Event_TPC_TDbcOvHiWarn_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_TPC_TDbcOvLoWarn,&VAR_DEM_Event_TPC_TDbcOvLoWarn_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_TPC_TDbcUHiLimFail,&VAR_DEM_Event_TPC_TDbcUHiLimFail_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_TPC_TDbcULoLimFail,&VAR_DEM_Event_TPC_TDbcULoLimFail_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_TPC_TDbcVHiLimFail,&VAR_DEM_Event_TPC_TDbcVHiLimFail_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_TPC_TDbcVLoLimFail,&VAR_DEM_Event_TPC_TDbcVLoLimFail_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_TPC_TDbcWHiLimFail,&VAR_DEM_Event_TPC_TDbcWHiLimFail_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_TPC_TDbcWLoLimFail,&VAR_DEM_Event_TPC_TDbcWLoLimFail_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_TPC_TDrvBoardOvHiWarn,&VAR_DEM_Event_TPC_TDrvBoardOvHiWarn_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_TPC_TIGBTOvHiLimErr,&VAR_DEM_Event_TPC_TIGBTOvHiLimErr_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_TPC_TIGBTOvHiWarn,&VAR_DEM_Event_TPC_TIGBTOvHiWarn_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_TPC_TIGBTOvLoWarn,&VAR_DEM_Event_TPC_TIGBTOvLoWarn_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_TPC_TSttrOvHiLimFail,&VAR_DEM_Event_TPC_TSttrOvHiLimFail_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_TPC_TSttrOvHiWarn,&VAR_DEM_Event_TPC_TSttrOvHiWarn_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_TPC_TSttrOvLoWarn,&VAR_DEM_Event_TPC_TSttrOvLoWarn_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_TPC_iDcLnkOvCLimFail,&VAR_DEM_Event_TPC_iDcLnkOvCLimFail_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_TPC_iDcLnkOvcWarn,&VAR_DEM_Event_TPC_iDcLnkOvcWarn_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_TPC_uDcLnkOvVLimFail,&VAR_DEM_Event_TPC_uDcLnkOvVLimFail_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_TPC_uDcLnkOvWarn,&VAR_DEM_Event_TPC_uDcLnkOvWarn_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_TPC_uDcLnkUnVLimFail,&VAR_DEM_Event_TPC_uDcLnkUnVLimFail_Status_u8);
    (void)Dem_GetEventStatus(DemConf_DemEventParameter_TPC_uDcLnkUnvWarn,&VAR_DEM_Event_TPC_uDcLnkUnvWarn_Status_u8);
}

void DEM_FID2FR_Update(void)
{
    boolean permissionState = TRUE;
    (void)FiM_GetFunctionPermission(FiMConf_FiMFID_FiM_FlagforFR,&permissionState);
    if(TRUE == permissionState)
    {
        EventFlag2FR_boolean = FALSE;
    }
    else
    {
        EventFlag2FR_boolean =TRUE;
    }
}

void ClearDTC_User(void)
{
    uint8 EventID_i = 0,Event_NUM = 0;
    for(EventID_i=1u;EventID_i<DEM_EVENTID_COUNT+1u;EventID_i++)
    {
        (void)Dem_ISO14229ByteSetTestFailed(&(Dem_AllEventsStatusByte[EventID_i]), FALSE);
        (void)Dem_ISO14229ByteSetTestFailedTOC(&(Dem_AllEventsStatusByte[EventID_i]), FALSE);
        (void)Dem_ISO14229ByteSetPendingDTC(&(Dem_AllEventsStatusByte[EventID_i]), FALSE);
        (void)Dem_ISO14229ByteSetConfirmedDTC(&(Dem_AllEventsStatusByte[EventID_i]), FALSE);
        (void)Dem_ISO14229ByteSetTestNotCompleteSLC(&(Dem_AllEventsStatusByte[EventID_i]), TRUE);
        (void)Dem_ISO14229ByteSetTestFailedSLC(&(Dem_AllEventsStatusByte[EventID_i]), FALSE);
        (void)Dem_ISO14229ByteSetTestNotCompleteTOC(&(Dem_AllEventsStatusByte[EventID_i]), TRUE);
        (void)Dem_ISO14229ByteSetWarningIndicatorRequested(&(Dem_AllEventsStatusByte[EventID_i]), FALSE);
    }
    for(Event_NUM=0;Event_NUM<NVM_CFG_NV_BLOCK_LENGTH_DEM_HistoryEventList;Event_NUM++)
    {
        VAR_DEM_EventList_au8[Event_NUM] = 0U;
        VAR_DEM_HisEvtFailedList_au8[Event_NUM] = 0U;
        VAR_DEM_EvtFailed_and_Passed_TOPC_au8[Event_NUM] = 0U;
    }
}

/*******************************************************************************
** Function Name    : SWC_DEM_PAR_100ms
** Parameter[in]    : None
** Parameter[out]   : None
** Return Value     : None
** Note             : None
** Description      : Cdd_DiagCalib Main Scheduling function.
*******************************************************************************/
void SWC_DEM_PAR_100ms(void)           /* Explicit Task: RE_SWC_DEM_PAR_100ms */
{
    uint8 EventList2Can[8] = {0};
    uint8 k_new = 0,i_event = 0;
    if( DEM_StartOP_u8 == 0u )
    {
        (void)Dem_SetOperationCycleState(DemConf_DemOperationCycle_DemOperationCycle_OP,DEM_CYCLE_STATE_START);
        DEM_StartOP_u8 = 1u;
    }
    DEM_SingleEventAndFidUpdate();
    FiM_FIDList_Update();
    DEM_Clear_DTC();
    DEM_EventState_Update();
    DemEnCon_ID_Update();
    FiM_EventFID_Update();
    DEM_EventLists_Update();
    FID_EventTrack();
    DEM_HistoryEventList_Record();
    DEM_FID2FR_Update();

    for(i_event=1;i_event<DEM_EVENTID_COUNT+1u;i_event++)
        {
            if(k_new < 8u)
            {
                if((DEM_ALLEvent_Status_au8[i_event] & 0x03u) == 0x03u)
                {
                    EventList2Can[k_new]=i_event;
                    k_new ++;
                }
            }
            else
            {
                break;
            }
        }
  /* Outport: '<Root>/PP_SWC_CddDiagCalib_CddDiagCalib_FailCode1' */
  (void) Rte_Write_SWC_DiagCalib_PP_SWC_DiagCalib_DiagCalib_FailCode1(EventList2Can[0]);

  /* Outport: '<Root>/PP_SWC_CddDiagCalib_CddDiagCalib_FailCode2' */
  (void) Rte_Write_SWC_DiagCalib_PP_SWC_DiagCalib_DiagCalib_FailCode2(EventList2Can[1]);

  /* Outport: '<Root>/PP_SWC_CddDiagCalib_CddDiagCalib_FailCode3' */
  (void) Rte_Write_SWC_DiagCalib_PP_SWC_DiagCalib_DiagCalib_FailCode3(EventList2Can[2]);

  /* Outport: '<Root>/PP_SWC_CddDiagCalib_CddDiagCalib_FailCode4' */
  (void) Rte_Write_SWC_DiagCalib_PP_SWC_DiagCalib_DiagCalib_FailCode4(EventList2Can[3]);

  /* Outport: '<Root>/PP_SWC_CddDiagCalib_CddDiagCalib_FailCode5' */
  (void) Rte_Write_SWC_DiagCalib_PP_SWC_DiagCalib_DiagCalib_FailCode5(EventList2Can[4]);

  /* Outport: '<Root>/PP_SWC_CddDiagCalib_CddDiagCalib_FailCode6' */
  (void) Rte_Write_SWC_DiagCalib_PP_SWC_DiagCalib_DiagCalib_FailCode6(EventList2Can[5]);

  /* Outport: '<Root>/PP_SWC_CddDiagCalib_CddDiagCalib_FailCode7' */
  (void) Rte_Write_SWC_DiagCalib_PP_SWC_DiagCalib_DiagCalib_FailCode7(EventList2Can[6]);

  /* Outport: '<Root>/PP_SWC_CddDiagCalib_CddDiagCalib_FailCode8' */
  (void) Rte_Write_SWC_DiagCalib_PP_SWC_DiagCalib_DiagCalib_FailCode8(EventList2Can[7]);
}

/* Model initialize function */
void SWC_CddDiagCalib_Init(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]


 */
