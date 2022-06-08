/*
***********************************************************************************************************************
* 
* Product Info
* Isolar version: ISOLAR-AB 4.0.2
* Product release version: RTA-BSW 3.1.0
* 
***********************************************************************************************************************
*/


#ifndef DCM_LCFG_DSPUDS_H
#define DCM_LCFG_DSPUDS_H
/*
 ***************************************************************************************************
 *    DCM Appl API Prototyes generated from configuration
 ***************************************************************************************************
*/
#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
extern FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_DidServices_F186_ReadData(P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) adrData_pu8);
#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"

/***Extern declarations to obtain NRC value from the application in case of E_NOT_OK return from ReadData API ***/
extern FUNC(Std_ReturnType,DCM_APPL_CODE)  DcmAppl_DcmReadDataNRC(VAR(uint16,AUTOMATIC)Did,VAR(uint32,AUTOMATIC)DidSignalPosn,P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_INTERN_DATA) ErrorCode);


 /***Extern declarations for XXX_ReadData of type USE_DATA_SYNCH_FNC ***/
extern FUNC(Std_ReturnType,DCM_APPL_CODE) DataReadFnc_Test (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
extern FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadPP_SWC_CSP_CSP_iU (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
extern FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadPP_SWC_CSP_CSP_iV (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
extern FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadPP_SWC_CSP_CSP_iW (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
extern FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadPP_SWC_CSP_CSP_uDcLnk (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
extern FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadSPF_uKl30Flt (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
extern FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadSPF_tDBCTempUFlt (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
extern FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadSPF_tStrrTemp1Flt (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
extern FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadSPF_tStrrTemp2Flt (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
extern FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadPP_SWC_CSP_CSP_Is (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
extern FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadPP_SWC_MPP_MPP_TrqMech (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
extern FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadAspRsd_nWoFlt (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
extern FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadADS (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
extern FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadSIC (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
extern FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadECU_Data_Y (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
extern FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadECU_Data_M (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
extern FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadECU_Data_D (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
extern FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadECUHWBOMECU_Name (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
extern FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadECUHWBOM_version (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
extern FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadECUHW_Version_FRS (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
extern FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadECUHW_Subversion (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
extern FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadECUSWBOMECU_Name (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
extern FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadECUSWBOM_version (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
extern FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadECUSW_Version_and_FRS (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
extern FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadECUSW_Subversion (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
extern FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadECUBoot_version_number (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
extern FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadP_FingerPrint (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
extern FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadP_FingerPrint1 (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
extern FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadP_FingerPrint2 (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
extern FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadP_FingerPrint3 (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
extern FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadP_FingerPrint4 (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
extern FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadP_FingerPrint5 (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
extern FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadCalSW_Number (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
extern FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadAppSW_Number (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
extern FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadBSW_Number (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
extern FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadDspData_Service_Date (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
extern FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadSupplierSpecific_ID (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
extern FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadSysSupplierECUHW_Num (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
extern FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadSysSupplierECUSW_Num (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);
extern FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadECUname_ID (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data);

 











/***Extern declarations for XXX_FreezeCurrentStateFnc of type USE_DATA_SYNCH_FNC ***/
extern FUNC(Std_ReturnType,DCM_APPL_CODE) FreeseCurrentStateFnc_Test (P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_INTERN_DATA) ErrorCode);


/***Extern declarations for XXX_ResetToDefaultFnc of type USE_DATA_SYNCH_FNC ***/
extern FUNC(Std_ReturnType,DCM_APPL_CODE) ResetToDefault_Test (P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_INTERN_DATA) ErrorCode);

/***Extern declarations for ReturnControlToEcuFnc.Only Synchronous API is used irrespective of UsePort Configuration to USE_DATA_SYNCH_FNC or USE_DATA_ASYNCH_FNC **/
extern FUNC(Std_ReturnType,DCM_APPL_CODE) ReturnControlToECUFnc_Test (P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_INTERN_DATA) ErrorCode);

/***Extern declarations for ShortTermAdjustmentFnc of type USE_DATA_SYNCH_FNC  for Fixed LENGTH with no control mask or internal control mask handling***/
extern FUNC(Std_ReturnType,DCM_APPL_CODE) AdjustmentFnc_Test (P2CONST(uint8,AUTOMATIC,DCM_INTERN_DATA) ControlStateInfo,P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_INTERN_DATA) ErrorCode);



/***Extern declarations for ShortTermAdjustmentFnc of type USE_DATA_SYNCH_FNC  for variable LENGTH with no control mask or internal control mask handling***/












/***Routine control Appl functions***/















#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
#endif /* DCM_LCFG_DSPUDS_H */



