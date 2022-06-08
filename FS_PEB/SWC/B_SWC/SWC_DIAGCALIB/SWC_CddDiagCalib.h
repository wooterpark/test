/*
 * File: SWC_CddDiagCalib.h
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

#ifndef RTW_HEADER_SWC_CddDiagCalib_h_
#define RTW_HEADER_SWC_CddDiagCalib_h_
#ifndef SWC_CddDiagCalib_COMMON_INCLUDES_
# define SWC_CddDiagCalib_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_SWC_DiagCalib.h"
#endif                                 /* SWC_CddDiagCalib_COMMON_INCLUDES_ */

#include "SWC_CddDiagCalib_types.h"

/* Macros for accessing real-time model data structure */

/* user code (top of header file) */
#include "FiM_Cfg_PbCfg.h"
#include "FiM_Priv_Data.h"
#include "Std_Types.h"
#include "Dem.h"
#include "Dem_Events.h"
#include "FiM_Cfg_Fids.h"
#include "NvM_Cfg.h"
#include "FiM.h"

/*******************************************************************************
**                          Macro Definition                           **
*******************************************************************************/
#define INDEX_TRANSFORMATION(ID_Event) ((ID_Event-1u)*10u)
#define FIM_CFG_MAX_TOTAL_LINKS_EVENT_CALC_USER 1270
#define EVENT_FAILED_CURR                      0x03U
#define EVENT_FAILED_HIS                       0x01U    /*Event stored in DFlash*/
#define EVENT_FAILED_PASSED_TOPC               0x02U
/*******************************************************************************
**                          Typedef Definition                           **
*******************************************************************************/
typedef uint8 Dem_EventStatusExtendedType;

/*******************************************************************************
**                          External Function Declaration                     **
*******************************************************************************/
extern void DEM_Failcode_Update(Dem_EventStatusExtendedType* Event_List_Kind,uint8 Event_Kind);
extern void FID_EventTrack(void);
extern void DEM_ClearTempStates(void);
extern void DEM_HistoryEventList_Record( void );
extern void DEM_FID2FR_Update(void);
void ClearDTC_User(void);
extern void DemEnCon_ID_Update( void );


/*******************************************************************************
**                   Static Local Variables Definition                **
*******************************************************************************/



/*******************************************************************************
**                     External Variables Declaration                    **
*******************************************************************************/
extern FiM_FunctionIdType FiM_CfgInhibitSourceMatrix_au16[FIM_CFG_MAX_TOTAL_LINKS_EVENT_CALC_USER];
extern uint8 VAR_DEM_EvtFailedList_au8[NVM_CFG_NV_BLOCK_LENGTH_DEM_HistoryEventList];
extern uint32 DEM_FF_InputDTC_u32;
extern uint32 DEM_Clear_InputDTC_u32;
extern boolean EventFlag2FR_boolean;
extern uint8 Dem_ClearTest_Flag_u8;

extern uint8  VAR_DEM_EventList_au8[NVM_CFG_NV_BLOCK_LENGTH_DEM_HistoryEventList] ;
extern uint8  VAR_DEM_AllEvtFailedList_au8[DEM_EVENTID_COUNT+1u];
extern uint8  VAR_DEM_FidTraceEvents_au8[DEM_EVENTID_COUNT];
extern uint8  VAR_DEM_FidTraceEvents_au8[DEM_EVENTID_COUNT];
extern uint8  VAR_DEM_HisEvtFailedList_au8[NVM_CFG_NV_BLOCK_LENGTH_DEM_HistoryEventList];
extern uint8  VAR_DEM_AllFID_Statues_au8[FIM_CFG_NUMBEROFFIDS+1u];
extern uint8  VAR_DEM_EvtFailed_and_Passed_TOPC_au8[NVM_CFG_NV_BLOCK_LENGTH_DEM_HistoryEventList];

extern Dem_EventStatusExtendedType     VAR_DEM_Event_ADC_UPhaseBISTFail_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_ADC_VPhaseBISTFail_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_ADC_WPhaseBISTFail_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_CANSM_E_BUS_OFF_NETWORK_0_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_CANSM_E_BUS_OFF_NETWORK_1_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_Can_Timeout_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_Cpld_AliveChkErr_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_Cpld_DI_ExdClk_InFail_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_Cpld_ExdClkInFail_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_Cpld_IphaOC_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_Cpld_NEN_InFail_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_Cpld_ParityChkErr_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_Cpld_Rx_SelfTest_Fail_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_Cpld_SPIComFail_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_Cpld_SZTKT_InFail_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_Cpld_Short_Circuit_HS_InFail_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_Cpld_Short_Circuit_LS_InFail_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_Cpld_UdcOverVolFail_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_Cpld_UnderVol_HS_InFail_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_Cpld_UnderVol_LS_InFail_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_Epark_OverCurFail_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_Epark_PosMonSampFail_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_Epark_PosSampFail_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_Epark_SampFail_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_Event_NvM_ReadErr_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_Event_NvM_WriteErr_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_FR_StorageErr_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_HSPF_InvOpenErr_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_HSPF_MotorOpenErr_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_HSPF_VerMatchFailureErr_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_HSPF_stIphaOffCalFail_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_HSPF_tDBCTempCmpErr_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_HvMcu_ComErr_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_HvMcu_DisChrgDutyErr_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_HvMcu_DisChrgFail_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_HvMcu_DisChrgFreqErr_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_HvMcu_EmerPowerSapErr_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_HvMcu_UartCheckFailErr_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_HvMcu_UartLostFrameErr_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_HvMcu_UdcCheckErr_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_HvMcu_UdcOverFlagLimit_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_HvMcu_UdcOverVolErr_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_IOHWAB_12VNarrSampErr_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_IOHWAB_12VSampErr_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_IOHWAB_12VWideSampErr_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_IOHWAB_18VLwBrgSampFail_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_IOHWAB_18VUpBrgSampFail_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_IOHWAB_1V3MCU_SampFail_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_IOHWAB_3V3MCU_SampFail_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_IOHWAB_5VQcoSampFail_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_IOHWAB_5VQt1SampFail_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_IOHWAB_5VQt2SampFail_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_IOHWAB_Cpld1v8SampFail_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_IOHWAB_Cpld3v3SampFail_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_IOHWAB_CrashFail_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_IOHWAB_DcLnkOverVolFail_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_IOHWAB_IphaOCFail_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_IOHWAB_KL30OverVolErr_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_IOHWAB_KL30SevOverVolFail_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_IOHWAB_KL30SevUnderVolFail_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_IOHWAB_KL30UnderVolErr_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_IOHWAB_Nen33Fail_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_IOHWAB_SttrSenorShrFail_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_IOHWAB_SttrTemp1SampFail_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_IOHWAB_SttrTemp2SampFail_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_IOHWAB_TCoolantSampFail_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_IOHWAB_VDD5_D_SampFail_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_IgbtDrv_ComErr_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_IgbtDrv_LwBrgFaultAFail_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_IgbtDrv_LwBrgFaultBFail_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_IgbtDrv_UpBrgFaultAFail_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_IgbtDrv_UpBrgFaultBFail_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_MDF_AlOfsNoPlausErr_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_MDF_DiashCirNoPsblErr_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_MDF_EmacBlkdErr_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_MDF_EmacBlkdWarn_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_MDF_ICtlRatErr_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_MDF_IsOvHiErr_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_MDF_OpenCirNoPsblErr_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_MDF_OperOutdRngErr_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_MDF_PhaseLossFaultErr_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_MDF_PrfElDrvErr_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_PCF_ActOvTiErr_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_PCF_IdcOvErr_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_PCF_SelfcheckErr_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_PCF_SenClbErr_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_PCF_SenOvErr_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_PCF_StallRetryErr_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_PCF_StallWarn_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_PCF_UnexpPosErr_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_RCF_AccOvTiErr_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_RCF_EstOfsErr_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_RCF_FwlBwdOvTiErr_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_RCF_FwlFwdOvTiErr_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_RCF_OfsClbFail_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_RCF_PsiOvErr_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_RSL_DOSErr_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_RSL_ExcErr_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_RSL_LOSErr_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_RSL_LOTErr_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_SCF_DisChgOvTiFail_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_SCF_LowPwrShtDwnOvTiFail_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_SCF_RunToDischarErr_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_TPC_SpdOvHiLimFail_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_TPC_SpdOvHiWarn_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_TPC_TCoolantOvHiWarn_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_TPC_TDbcOvHiWarn_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_TPC_TDbcOvLoWarn_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_TPC_TDbcUHiLimFail_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_TPC_TDbcULoLimFail_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_TPC_TDbcVHiLimFail_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_TPC_TDbcVLoLimFail_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_TPC_TDbcWHiLimFail_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_TPC_TDbcWLoLimFail_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_TPC_TDrvBoardOvHiWarn_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_TPC_TIGBTOvHiLimErr_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_TPC_TIGBTOvHiWarn_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_TPC_TIGBTOvLoWarn_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_TPC_TSttrOvHiLimFail_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_TPC_TSttrOvHiWarn_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_TPC_TSttrOvLoWarn_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_TPC_iDcLnkOvCLimFail_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_TPC_iDcLnkOvcWarn_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_TPC_uDcLnkOvVLimFail_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_TPC_uDcLnkOvWarn_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_TPC_uDcLnkUnVLimFail_Status_u8;
extern Dem_EventStatusExtendedType     VAR_DEM_Event_TPC_uDcLnkUnvWarn_Status_u8;

extern Dem_EventStatusExtendedType    DEM_ALLEvent_Status_au8[DEM_EVENTID_COUNT+1u];
extern Dem_EventStatusExtendedType    DEM_AllEventDeb_State_au8[DEM_EVENTID_COUNT+1u];
/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'SWC_CddDiagCalib'
 * '<S1>'   : 'SWC_CddDiagCalib/RE_SWC_DEM_PAR_100ms_sys'
 * '<S2>'   : 'SWC_CddDiagCalib/SWC_CddDiagCalib_Init'
 */
#endif                                 /* RTW_HEADER_SWC_CddDiagCalib_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

