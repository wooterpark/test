#ifndef Test_App_H
#define Test_App_H

#include "Rte_Dcm_Type.h"


#define DCM_MODE_TYPE_ONE 1U
#define DCM_MODE_TYPE_NONE 0U

extern uint16 VehicleSpeed_Data;
extern uint16 EngineLoad_Data;

static void Diag_memcpy(uint8 *dstAddr, uint8 *srcAddr, uint8 size);

extern FUNC(Std_ReturnType,DCM_APPL_CODE) RTE_VehicleSpeed_Data (uint8* Buffer);

extern Std_ReturnType DEM_FF_uDcLnk(uint8* Buffer);

extern Std_ReturnType DEM_FF_Is(uint8* Buffer);

extern Std_ReturnType DEM_FF_TrqMech(uint8* Buffer);

extern Std_ReturnType DEM_FF_nWoFlt(uint8* Buffer);

extern Std_ReturnType DEM_FF_tDBCTempUFlt(uint8* Buffer);

extern Std_ReturnType DEM_FF_tStrrTemp1Flt(uint8* Buffer);

extern Std_ReturnType DEM_FF_tStrrTemp2Flt(uint8* Buffer);

extern Std_ReturnType DEM_FF_uKl30Flt(uint8* Buffer);
extern Std_ReturnType DEM_FF_iU(uint8* Buffer);
extern Std_ReturnType DEM_FF_iV(uint8* Buffer);
extern Std_ReturnType DEM_FF_iW(uint8* Buffer);

/*Extern function declaration in Dcm*/
extern FUNC( Std_ReturnType, DCM_CODE) Dcm_GetSesCtrlType(CONSTP2VAR(Dcm_SesCtrlType, AUTOMATIC, DCM_APPL_DATA)  SesCtrlType);

/*Data conversion method*/
void Dcm_U16ToU8(uint16 Data_In,uint8* Data_Out);

/*R_port in Rte.c*/
extern FUNC(uint8, RTE_CODE) Rte_Mode_Diag_SWC_RPort_DcmEcuReset_MDGP_DcmEcuReset(void);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PCF_RP_SWC_HSPF_HSPF_nSlowFlt(CONSTP2VAR(float32, AUTOMATIC, RTE_APPL_DATA) data);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_MDF_RP_SWC_MCF_MCF_iU(CONSTP2VAR(float32, AUTOMATIC, RTE_APPL_DATA) data);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_MDF_RP_SWC_MCF_MCF_iV(CONSTP2VAR(float32, AUTOMATIC, RTE_APPL_DATA) data);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_MDF_RP_SWC_MCF_MCF_iW(CONSTP2VAR(float32, AUTOMATIC, RTE_APPL_DATA) data);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_HSPF_RP_SWC_MCF_MCF_uDcLnk(CONSTP2VAR(float32, AUTOMATIC, RTE_APPL_DATA) data);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_CSPF_RP_SWC_HSPF_HSPF_uKl30Flt(CONSTP2VAR(float32, AUTOMATIC, RTE_APPL_DATA) data);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_MDF_RP_SWC_HSPF_HSPF_tDBCTempUFlt(CONSTP2VAR(float32, AUTOMATIC, RTE_APPL_DATA) data);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_CSPF_RP_SWC_HSPF_HSPF_tStrrTemp1Flt(CONSTP2VAR(float32, AUTOMATIC, RTE_APPL_DATA) data);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_CSPF_RP_SWC_HSPF_HSPF_tStrrTemp2Flt(CONSTP2VAR(float32, AUTOMATIC, RTE_APPL_DATA) data);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_MPC_RP_SWC_MCF_MCF_Is(CONSTP2VAR(float32, AUTOMATIC, RTE_APPL_DATA) data);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_MDF_RP_SWC_MPC_MPC_TrqMech(CONSTP2VAR(float32, AUTOMATIC, RTE_APPL_DATA) data);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_HSPF_RP_SWC_Rdc_Rdc_nWoFlt(CONSTP2VAR(float32, AUTOMATIC, RTE_APPL_DATA) data);

/*ECU DID's data*/
/***Declarations for XXX_ReadData of type USE_DATA_SYNCH_FNC ***/
FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadPP_SWC_CSP_CSP_iU (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadPP_SWC_CSP_CSP_iV (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadPP_SWC_CSP_CSP_iW (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadPP_SWC_CSP_CSP_uDcLnk (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadSPF_uKl30Flt (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadSPF_tDBCTempUFlt (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadSPF_tStrrTemp1Flt (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadSPF_tStrrTemp2Flt (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadPP_SWC_CSP_CSP_Is (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadPP_SWC_MPP_MPP_TrqMech (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadAspRsd_nWoFlt (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadADS (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadSIC (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadECU_Data_Y (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadECU_Data_M (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadECU_Data_D (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadECUHWBOMECU_Name (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadECUHWBOM_version (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadECUHW_Version_FRS (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadECUHW_Subversion (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadECUSWBOMECU_Name (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadECUSWBOM_version (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadECUSW_Version_and_FRS (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadECUSW_Subversion (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadECUBoot_version_number (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadP_FingerPrint (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadP_FingerPrint1 (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadP_FingerPrint2 (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadP_FingerPrint3 (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadP_FingerPrint4 (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadP_FingerPrint5 (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadCalSW_Number (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadAppSW_Number (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadBSW_Number (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadDspData_Service_Date (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadSupplierSpecific_ID (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadSysSupplierECUHW_Num (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadSysSupplierECUSW_Num (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadECUname_ID (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);

FUNC(void, TestDiag_CODE) RE_Swc_Dem_Periodic(void);
FUNC(void, TestDiag_CODE) RunnableEntity_dcm(void);

void SwcDcmEcuHardReset_func(void);
void SwcDcmEcuSoftReset_func(void);
void SwcDcmEcuJumpToBootLoader_func(void);
void Dcm_RandSeedCal(void);

FUNC(Std_ReturnType, Diag_SWC_CODE) Swc_DSP_SEC_LEV_L1_CK_func(P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Key,
                                                               VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
                                                               CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, Diag_SWC_CODE) Swc_DSP_SEC_LEV_L1_GS_func(VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
                                                               CONSTP2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Seed,
                                                               CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, Diag_SWC_CODE) Swc_DSP_SEC_LEV_L2_CK_func(P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Key,
                                                               VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
                                                               CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, Diag_SWC_CODE) Swc_DSP_SEC_LEV_L2_GS_func(VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
                                                               CONSTP2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Seed,
                                                               CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, Diag_SWC_CODE) Swc_DSP_SEC_LEV_L3_CK_func(P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Key,
                                                               VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
                                                               CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, Diag_SWC_CODE) Swc_DSP_SEC_LEV_L3_GS_func(VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
                                                               CONSTP2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Seed,
                                                               CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, Diag_SWC_CODE) Swc_DSP_SEC_LEV_L4_CK_func(P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Key,
                                                               VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
                                                               CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, Diag_SWC_CODE) Swc_DSP_SEC_LEV_L4_GS_func(VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
                                                               CONSTP2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Seed,
                                                               CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, Diag_SWC_CODE) Swc_RoutineServices_DcmDspRoutine_CheckProgCond_Result_func(VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
                                                                                                CONSTP2VAR(Dcm_RequestDataOut_DcmDspRoutine_CheckPgmPreCond_DcmDspRequestRoutineResultsOutSignal_0Type, AUTOMATIC, RTE_APPL_DATA) dataOut_DcmDspRequestRoutineResultsOutSignal_0,
                                                                                                CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, Diag_SWC_CODE) Swc_RoutineServices_DcmDspRoutine_CheckProgCond_Start_func(VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
                                                                                               CONSTP2VAR(Dcm_StartDataOut_DcmDspRoutine_CheckPgmPreCond_DcmDspStartRoutineOutSignal_ESType, AUTOMATIC, RTE_APPL_DATA) DataOut_DcmDspStartRoutineOutSignal_ES,
                                                                                               CONSTP2VAR(Dcm_StartDataOut_DcmDspRoutine_CheckPgmPreCond_DcmDspStartRoutineOutSignal_VSType, AUTOMATIC, RTE_APPL_DATA) DataOut_DcmDspStartRoutineOutSignal_VS,
                                                                                               CONSTP2VAR(Dcm_StartDataOut_DcmDspRoutine_CheckPgmPreCond_DcmDspStartRoutineOutSignal_ICType, AUTOMATIC, RTE_APPL_DATA) DataOut_DcmDspStartRoutineOutSignal_IC,
                                                                                               CONSTP2VAR(Dcm_StartDataOut_DcmDspRoutine_CheckPgmPreCond_DcmDspStartRoutineOutSignal_VCType, AUTOMATIC, RTE_APPL_DATA) DataOut_DcmDspStartRoutineOutSignal_VC,
                                                                                               CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, Diag_SWC_CODE) Swc_RoutineServices_DcmDspRoutine_CheckProgCond_Stop_func(VAR(Dcm_StopDataIn_DcmDspRoutine_CheckPgmPreCond_DcmDspStopRoutineInSignal_0Type, AUTOMATIC) dataIn_DcmDspStopRoutineInSignal_0,
                                                                                              VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
                                                                                              CONSTP2VAR(Dcm_StopDataOut_DcmDspRoutine_CheckPgmPreCond_DcmDspStopRoutineOutSignal_0Type, AUTOMATIC, RTE_APPL_DATA) dataOut_DcmDspStopRoutineOutSignal_0,
                                                                                              CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, Diag_SWC_CODE) Swc_RoutineServices_DcmDspRoutine_Test_Result_func(VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
                                                                                       CONSTP2VAR(Dcm_RequestDataOut_DcmDspRoutine_Test_DcmDspRequestRoutineResultsOutSignal_0Type, AUTOMATIC, RTE_APPL_DATA) dataOut_DcmDspRequestRoutineResultsOutSignal_0,
                                                                                       CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, Diag_SWC_CODE) Swc_RoutineServices_DcmDspRoutine_Test_Start_func(VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
                                                                                      CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, Diag_SWC_CODE) Swc_RoutineServices_DcmDspRoutine_Test_Stop_func(VAR(Dcm_StopDataIn_DcmDspRoutine_Test_DcmDspStopRoutineInSignal_0Type, AUTOMATIC) dataIn_DcmDspStopRoutineInSignal_0,
                                                                                     VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
                                                                                     CONSTP2VAR(Dcm_StopDataOut_DcmDspRoutine_Test_DcmDspStopRoutineOutSignal_0Type, AUTOMATIC, RTE_APPL_DATA) dataOut_DcmDspStopRoutineOutSignal_0,
                                                                                     CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode);
/*Fnc to implement UDS $2F*/
/*FJ 2020/3/26*/
FUNC(Std_ReturnType,DCM_APPL_CODE) DataReadFnc_Test (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
FUNC(Std_ReturnType,DCM_APPL_CODE) FreeseCurrentStateFnc_Test (P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_INTERN_DATA) ErrorCode);


/***Extern declarations for XXX_ResetToDefaultFnc of type USE_DATA_SYNCH_FNC ***/
FUNC(Std_ReturnType,DCM_APPL_CODE) ResetToDefault_Test (P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_INTERN_DATA) ErrorCode);

/***Extern declarations for ReturnControlToEcuFnc.Only Synchronous API is used irrespective of UsePort Configuration to USE_DATA_SYNCH_FNC or USE_DATA_ASYNCH_FNC **/
FUNC(Std_ReturnType,DCM_APPL_CODE) ReturnControlToECUFnc_Test (P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_INTERN_DATA) ErrorCode);

/***Extern declarations for ShortTermAdjustmentFnc of type USE_DATA_SYNCH_FNC  for Fixed LENGTH with no control mask or internal control mask handling***/
FUNC(Std_ReturnType,DCM_APPL_CODE) AdjustmentFnc_Test (P2CONST(uint8,AUTOMATIC,DCM_INTERN_DATA) ControlStateInfo,P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_INTERN_DATA) ErrorCode);
#define Diag_SWC_STOP_SEC_CODE

#endif
