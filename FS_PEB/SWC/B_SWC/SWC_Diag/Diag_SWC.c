#include "Rte_Type.h"
#include "Diag_SWC.h"
#include "SchM_BswM_Type.h"
#include "BswM.h"
#include "rba_Reset.h"
#include "Dem.h"/*FJ 2019/12/19*/
#include "HAMCSHA1.h"//FJ 20200508
#include "Rte_Dcm_Type.h"//FJ 20200509
#include "NvM.h"//FJ 20200511 for DEM Test
#include "Dio.h"//FJ 20200615
#include "Dio_Cfg.h"//FJ 20200615
#include "IoHwAb_Adc.h"//FJ 20200615
#include "rba_Reset.h"

#define SWC_COMPARE_KEY_FAILED 11
#define DCM_VOLTAGE_MIN 11.5
#define DCM_VOLTAGE_MAX 16
/*******************************************************************************************
 * *                   Test Data
 ********************************************************************************************/
uint16 VehicleSpeed_Data = 20;
uint8 EngineSpeed_Data = 10;
uint8 genUint8 = 0;
uint8 VAR_IOControl_u8 = 0;
uint8 VAR_JumpToBoot_Test = 0;
uint8 VAR_EcuRest_Test = 0;
uint8 ECUDID_Data =11;
uint8 UDS31_Test = 0;
/*Sys DID data*/
static uint8 Sys_Supplier_ID[5] ={0,1,2,1,2};
static uint8 ECU_M_Date_Y = 20;
static uint8 ECU_M_Date_M = 5;
static uint8 ECU_M_Date_D =9;
static uint8 ECUHWBOMECU_Name[4] = {1,2,1,2};
static uint8 ECUHWBOM_version = 1;
static uint8 ECUHW_Version_and_FRS = 1;
static uint8 ECUHW_Subversion = 0;
static uint8 ECUSWBOMECU_Name[4] = {1,2,1,2};
static uint8 ECUSWBOM_version = 1;
static uint8 ECUSW_Version_and_FRS = 1;
static uint8 ECUSW_Subversion = 0;

static uint8 CalSW_Num[7] = {2,0,2,0,5,1,0};
static uint8 ASW_Num[7] = {2,0,2,0,5,1,0};
static uint8 BSW_Num[7] = {2,0,2,0,5,1,0};
static uint8 ServiceData[3] = {20,5,9};
static uint8 Supplier_Spec_ID[2] = {12,12};
static uint8 Sys_Suppiler_ECUHW_Num = 1;
static uint8 Sys_Suppiler_ECUSW_Num = 1;
static uint8 ECU_Name_ID[15] = {1,2,1,2,1,2,1,2,1,2,1,2,1,2,1};

/*******************************************************************************************
 * *                  End of Test Data
 ********************************************************************************************/

/*The conversion coefficient c of SWC to Dcm*/
static uint8 SWC2Dcm_C[11] = {
		10,
		10,
		10,
		10,
		10,
		1,
		1,
		1,
		10,
		10,
		10
};
static uint16 SWC2Dcm_D[11] ={
		10000,
		10000,
		10000,
		0,
		0,
		40,
		0,
		0,
		1000,
		350,
		20000
};

/********DCM Seed Counter******/
uint8 Dcm_Seed_Cnt = 0;

volatile uint16 RoutineControl_Test_Status;
volatile uint16 RoutineControl_CheckProgCond_Status;
volatile uint8 InputOutputControl_Test_Status;

/* Seed values for Service 0x27 */

uint8 DcmSeed[16] =
{
	0x11,0x11,
	0x22,0x22,
	0x33,0x33,
	0x44,0x44,
	0x11,0x11,
	0x22,0x22,
	0x33,0x33,
	0x44,0x44

};

/* Key values for Service 0x27 */

uint8 DcmKey[16] =
{
	0x10, 0x10,
	0x20, 0x20,
	0x30, 0x30,
	0x40, 0x40,
	0x10, 0x10,
	0x20, 0x20,
	0x30, 0x30,
	0x40, 0x40

};

/*Vehicle Manufacturer ECU Software Version Number	0xF189*/
//Dcm_DataArrayTypeUint8_DspData_ASW_VER_F189Type   dataF189={0x10, 0x9, 0x8, 0x7, 0x6, 0x5, 0x4, 0x3};
Dcm_DataArrayTypeUint8_DspData_MANU_DATE_F18BType dataF18B={0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02};
Dcm_DataArrayTypeUint8_DspData_SYS_SUP_ID_F18AType dataF18A={0x01, 0x02, 0x03, 0x01, 0x02, 0x02, 0x02, 0x02};

uint8 Dcm_EcuReset_Mode_u8=0;
uint8 Dcm_EcuReset_LastMode_u8=0;
uint8 Dcm_EcuReset_StateTest_au8[10];

/*Data conversion method*/
uint16 Data_In_FJ = 2345;
uint8 Data_Out_FJ[2] = {0,0};
void Dcm_U16ToU8(uint16 Data_In,uint8* Data_Out)
{
	*Data_Out = (uint8)(Data_In >>8 &0xFF);
	*(Data_Out+1) = (uint8)(Data_In &0xFF);
}
volatile uint32 Prv_Jump_JumpToCblFlag_u32 __attribute__ ((asection(".data.JumpToCBL_Flag", "f=aw"))) = 0UL;


FUNC(Std_ReturnType,DCM_APPL_CODE) RTE_VehicleSpeed_Data (uint8* Buffer)
{
   uint8 i=0;
   Buffer[i] = (uint8)(VehicleSpeed_Data & 0x00FF);
   return E_OK;
}

/*Modified by FJ in 2020/4/9*/
void SwcDcmEcuHardReset_func(void)
{
	/*To Do*/
}

/*Added by FJ in 2020/4/9*/
void SwcDcmEcuSoftReset_func(void)
{
	uint8 ResetType_Test = 0;
	ResetType_Test = Rte_Mode_Diag_SWC_RPort_DcmEcuReset_MDGP_DcmEcuReset();
	if(ResetType_Test == 4U)
	{
		 VAR_EcuRest_Test = 1;
		 rba_Reset_Request(RBA_RESET_GRP_SOFTRESET_E,SWRESET_UDS_SOFTRESET,(uint32)0x0000);
	}
}

/*Added by FJ in 2020/4/9*/
void SwcDcmEcuJumpToBootLoader_func(void)
{
	uint8 ResetType_Test = 0;
	boolean CheckProPreCon_OK = FALSE;
	float32 Engine_Speed = 0;
	float32 Voltage_Condition = 0;

	/*Here to Get the App data */
	Rte_Read_SWC_PCF_RP_SWC_HSPF_HSPF_nSlowFlt(&Engine_Speed);
	IoHwAb_ADC_GetPhyVoltage(0u,&Voltage_Condition);

	/*Check programming preconditions*/
	if(!((Engine_Speed > 0) || (Engine_Speed < 0)) && (Voltage_Condition > DCM_VOLTAGE_MIN) && (Voltage_Condition < DCM_VOLTAGE_MAX))
	{
		CheckProPreCon_OK = FALSE;
	}
	else
	{
		CheckProPreCon_OK = TRUE;
	}

	/*Call ECU reset*/
	if(CheckProPreCon_OK)
	{
		ResetType_Test = Rte_Mode_Diag_SWC_RPort_DcmEcuReset_MDGP_DcmEcuReset();
		if(ResetType_Test == 1U)
		{
			VAR_JumpToBoot_Test = 1;
    	//	Pws_CoreCfg(WDGIF_OFF_MODE);
			Prv_Jump_JumpToCblFlag_u32 = 0x5A5A5A5AUL;
			Tlf35584SafeWdg_FunctionClosed();/*LQ 20201028*/
			rba_Reset_Request(RBA_RESET_GRP_SOFTRESET_E,SWRESET_UDS_JUMP_TO_BOOT,(uint32)0x0000);
		}
	}
}

Std_ReturnType DEM_FF_uDcLnk(uint8* Buffer)
{
   Dcm_ReadPP_SWC_CSP_CSP_uDcLnk(Buffer);
   return E_OK;
}

Std_ReturnType DEM_FF_Is(uint8* Buffer)
{
   Dcm_ReadPP_SWC_CSP_CSP_Is(Buffer);
   return E_OK;
}

Std_ReturnType DEM_FF_TrqMech(uint8* Buffer)
{
   Dcm_ReadPP_SWC_MPP_MPP_TrqMech(Buffer);
   return E_OK;
}

Std_ReturnType DEM_FF_nWoFlt(uint8* Buffer)
{
   Dcm_ReadAspRsd_nWoFlt(Buffer);
   return E_OK;
}

Std_ReturnType DEM_FF_tDBCTempUFlt(uint8* Buffer)
{
   Dcm_ReadSPF_tDBCTempUFlt(Buffer);
   return E_OK;
}

Std_ReturnType DEM_FF_tStrrTemp1Flt(uint8* Buffer)
{
   Dcm_ReadSPF_tStrrTemp1Flt(Buffer);
   return E_OK;
}

Std_ReturnType DEM_FF_tStrrTemp2Flt(uint8* Buffer)
{
   Dcm_ReadSPF_tStrrTemp2Flt(Buffer);
   return E_OK;
}

Std_ReturnType DEM_FF_uKl30Flt(uint8* Buffer)
{
   Dcm_ReadSPF_uKl30Flt(Buffer);
   return E_OK;
}

Std_ReturnType DEM_FF_iU(uint8* Buffer)
{
   Dcm_ReadPP_SWC_CSP_CSP_iU(Buffer);
   return E_OK;
}

Std_ReturnType DEM_FF_iV(uint8* Buffer)
{
   Dcm_ReadPP_SWC_CSP_CSP_iV(Buffer);
   return E_OK;
}

Std_ReturnType DEM_FF_iW(uint8* Buffer)
{
   Dcm_ReadPP_SWC_CSP_CSP_iW(Buffer);
   return E_OK;
}

/*Definition of ECU DID */
FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadPP_SWC_CSP_CSP_iU (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data)
{
	Std_ReturnType retValue = RTE_E_OK;
	float32 ECUDID_iU = 0;
	uint16 Dcm_Data_In = 0;
	Rte_Read_SWC_MDF_RP_SWC_MCF_MCF_iU(&ECUDID_iU);//LQ20200630
	/*Get MethodType of iU*/
	Dcm_Data_In = (uint16)(ECUDID_iU * SWC2Dcm_C[0] + SWC2Dcm_D[0]);
	Dcm_U16ToU8(Dcm_Data_In,Data);
	return ( retValue );
}
FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadPP_SWC_CSP_CSP_iV (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data)
{
	Std_ReturnType retValue = RTE_E_OK;
	float32 ECUDID_iV = 0;
	uint16 Dcm_Data_In = 0;
	Rte_Read_SWC_MDF_RP_SWC_MCF_MCF_iV(&ECUDID_iV);//LQ20200630
	/*Get MethodType of iV*/
	Dcm_Data_In = (uint16)(ECUDID_iV * SWC2Dcm_C[1] + SWC2Dcm_D[1]);
	Dcm_U16ToU8(Dcm_Data_In,Data);
	return ( retValue );
}
FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadPP_SWC_CSP_CSP_iW (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data)
{
	Std_ReturnType retValue = RTE_E_OK;
	float32 ECUDID_iW = 0;
	uint16 Dcm_Data_In = 0;
	Rte_Read_SWC_MDF_RP_SWC_MCF_MCF_iW(&ECUDID_iW);//LQ20200630
	/*Get MethodType of iV*/
	Dcm_Data_In = (uint16)(ECUDID_iW * SWC2Dcm_C[2] + SWC2Dcm_D[2]);
	Dcm_U16ToU8(Dcm_Data_In,Data);
	return ( retValue );
}
FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadPP_SWC_CSP_CSP_uDcLnk (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data)
{
	Std_ReturnType retValue = RTE_E_OK;
	float32 ECUDID_uDcLnk = 0;
	uint16 Dcm_Data_In = 0;
	Rte_Read_SWC_HSPF_RP_SWC_MCF_MCF_uDcLnk(&ECUDID_uDcLnk);//LQ20200630
	/*Get MethodType of uDcLnk*/
	Dcm_Data_In = (uint16)(ECUDID_uDcLnk * SWC2Dcm_C[3] + SWC2Dcm_D[3]);
	Dcm_U16ToU8(Dcm_Data_In,Data);
	return ( retValue );
}
FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadSPF_uKl30Flt (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data)
{
	Std_ReturnType retValue = RTE_E_OK;
	float32 ECUDID_uKl30Flt = 0;
	uint16 Dcm_Data_In = 0;
	Rte_Read_SWC_CSPF_RP_SWC_HSPF_HSPF_uKl30Flt(&ECUDID_uKl30Flt);//LQ20200630
	/*Get MethodType of uKl30Flt*/
	Dcm_Data_In = (uint16)(ECUDID_uKl30Flt * SWC2Dcm_C[4] + SWC2Dcm_D[4]);
	Dcm_U16ToU8(Dcm_Data_In,Data);
	return ( retValue );
}
FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadSPF_tDBCTempUFlt (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data)
{
	Std_ReturnType retValue = RTE_E_OK;
	float32 ECUDID_tDBCTempUFlt = 0;
	Rte_Read_SWC_MDF_RP_SWC_HSPF_HSPF_tDBCTempUFlt(&ECUDID_tDBCTempUFlt);//LQ20200630
	/*Get MethodType of tDBCTempUFlt*/
	*Data = (uint8)(ECUDID_tDBCTempUFlt * SWC2Dcm_C[5] + SWC2Dcm_D[5]);
	return ( retValue );
}
FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadSPF_tStrrTemp1Flt (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data)
{
	Std_ReturnType retValue = RTE_E_OK;
	float32 ECUDID_tStrrTemp1Flt = 0;
	Rte_Read_SWC_CSPF_RP_SWC_HSPF_HSPF_tStrrTemp1Flt(&ECUDID_tStrrTemp1Flt);//LQ20200630
	/*Get MethodType of tDBCTempUFlt*/
	*Data = (uint8)(ECUDID_tStrrTemp1Flt * SWC2Dcm_C[6] + SWC2Dcm_D[6]);
	return ( retValue );
}
FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadSPF_tStrrTemp2Flt (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data)
{
	Std_ReturnType retValue = RTE_E_OK;
	float32 ECUDID_tStrrTemp2Flt = 0;
	Rte_Read_SWC_CSPF_RP_SWC_HSPF_HSPF_tStrrTemp2Flt(&ECUDID_tStrrTemp2Flt);//LQ20200630
	/*Get MethodType of tDBCTempUFlt*/
	*Data = (uint8)(ECUDID_tStrrTemp2Flt * SWC2Dcm_C[7] + SWC2Dcm_D[7]);
	return ( retValue );
}
FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadPP_SWC_CSP_CSP_Is (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data)
{
	Std_ReturnType retValue = RTE_E_OK;
	float32 ECUDID_Is = 0;
	uint16 Dcm_Data_In = 0;
	Rte_Read_SWC_MPC_RP_SWC_MCF_MCF_Is(&ECUDID_Is);//LQ20200630
	/*Get MethodType of uKl30Flt*/
	Dcm_Data_In = (uint16)(ECUDID_Is * SWC2Dcm_C[8] + SWC2Dcm_D[8]);
	Dcm_U16ToU8(Dcm_Data_In,Data);
	return ( retValue );
}
FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadPP_SWC_MPP_MPP_TrqMech (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data)
{
	Std_ReturnType retValue = RTE_E_OK;
	float32 ECUDID_TrqMech = 0;
	uint16 Dcm_Data_In = 0;
	Rte_Read_SWC_MDF_RP_SWC_MPC_MPC_TrqMech(&ECUDID_TrqMech);//LQ20200630
	/*Get MethodType of uKl30Flt*/
	Dcm_Data_In = (uint16)(ECUDID_TrqMech * SWC2Dcm_C[9] + SWC2Dcm_D[9]);
	Dcm_U16ToU8(Dcm_Data_In,Data);
	return ( retValue );
}
FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadAspRsd_nWoFlt (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data)
{
	Std_ReturnType retValue = RTE_E_OK;
	float32 ECUDID_nWoFlt = 0;
	uint16 Dcm_Data_In = 0;
	Rte_Read_SWC_HSPF_RP_SWC_Rdc_Rdc_nWoFlt(&ECUDID_nWoFlt);//LQ20200630
	/*Get MethodType of uKl30Flt*/
	Dcm_Data_In = (uint16)(ECUDID_nWoFlt * SWC2Dcm_C[10] + SWC2Dcm_D[10]);
	Dcm_U16ToU8(Dcm_Data_In,Data);
	return ( retValue );
}

/****************************************************************************************************
**                                 Sys DID data get function
****************************************************************************************************/
FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadADS (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data)
{
	/*Here to get the value of the activated diagnostic session type */
	Std_ReturnType retValue = RTE_E_OK;
	uint8 SesCtrlType_Temp = DCM_DEFAULT_SESSION;
	Dcm_GetSesCtrlType(&SesCtrlType_Temp);
	*Data = SesCtrlType_Temp;
	return ( retValue );
}

FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadSIC (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data)
{
	Std_ReturnType retValue = RTE_E_OK;
	uint8 i = 0;
	for(i = 0;i < 5;i++)
	{
		*(Data + i) = Sys_Supplier_ID[i];
	}
	return ( retValue );
}
FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadECU_Data_Y (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data)
{
	Std_ReturnType retValue = RTE_E_OK;
	*Data = ECU_M_Date_Y;
	return ( retValue );
}
FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadECU_Data_M (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data)
{
	Std_ReturnType retValue = RTE_E_OK;
	*Data = ECU_M_Date_M;
	return ( retValue );
}
FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadECU_Data_D (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data)
{
	Std_ReturnType retValue = RTE_E_OK;
	*Data = ECU_M_Date_D;
	return ( retValue );
}
FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadECUHWBOMECU_Name (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data)
{
	Std_ReturnType retValue = RTE_E_OK;
	uint8 i = 0;
	for(i = 0;i < 4;i++)
	{
		*(Data+i) = ECUHWBOMECU_Name[i];
	}
	return ( retValue );
}
FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadECUHWBOM_version (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data)
{
	Std_ReturnType retValue = RTE_E_OK;
	*Data = ECUHWBOM_version;
	return ( retValue );
}
FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadECUHW_Version_FRS (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data)
{
	Std_ReturnType retValue = RTE_E_OK;
	*Data = ECUHW_Version_and_FRS;
	return ( retValue );
}
FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadECUHW_Subversion (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data)
{
	Std_ReturnType retValue = RTE_E_OK;
	*Data = ECUHW_Subversion;
	return ( retValue );
}
FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadECUSWBOMECU_Name (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data)
{
	Std_ReturnType retValue = RTE_E_OK;
	uint8 i = 0;
	for(i = 0;i < 4;i++)
	{
		*(Data+i) = ECUSWBOMECU_Name[i];
	}
	return ( retValue );
}
FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadECUSWBOM_version (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data)
{
	Std_ReturnType retValue = RTE_E_OK;
	*Data = ECUSWBOM_version;
	return ( retValue );
}
FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadECUSW_Version_and_FRS (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data)
{
	Std_ReturnType retValue = RTE_E_OK;
	*Data = ECUSW_Version_and_FRS;
	return ( retValue );
}
FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadECUSW_Subversion (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data)
{
	Std_ReturnType retValue = RTE_E_OK;
	*Data = ECUSW_Subversion;
	return ( retValue );
}
FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadECUBoot_version_number (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data)
{
	Std_ReturnType retValue = RTE_E_OK;
	*Data = *(uint8*)0x8003E300;
	*(Data+1) = *(uint8*)0x8003E301;
	return ( retValue );
}

FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadP_FingerPrint (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data)
{
	Std_ReturnType retValue = RTE_E_OK;
	/*Here to get FP value*/
	Diag_memcpy(Data,(uint8*)0x8017FF80,30U);
	return ( retValue );
}
FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadP_FingerPrint1 (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data)
{
	Std_ReturnType retValue = RTE_E_OK;
	/*Here to get FP1 value*/
	//*Data = ECU_M_Date_M;
	return ( retValue );
}

FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadP_FingerPrint2 (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data)
{
	Std_ReturnType retValue = RTE_E_OK;
	/*Here to get FP2 value*/
	//*Data = ECU_M_Date_M;
	return ( retValue );
}

FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadP_FingerPrint3 (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data)
{
	Std_ReturnType retValue = RTE_E_OK;
	/*Here to get FP3 value*/
	//*Data = ECU_M_Date_M;
	return ( retValue );
}

FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadP_FingerPrint4 (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data)
{
	Std_ReturnType retValue = RTE_E_OK;
	/*Here to get FP4 value*/
	//*Data = ECU_M_Date_M;
	return ( retValue );
}

FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadP_FingerPrint5 (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data)
{
	Std_ReturnType retValue = RTE_E_OK;
	/*Here to get FP5 value*/
	//*Data = ECU_M_Date_M;
	return ( retValue );
}

FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadCalSW_Number (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data)
{
	Std_ReturnType retValue = RTE_E_OK;
	uint8 i = 0;
	for(i = 0;i < 7;i++)
	{
		*(Data+i) = CalSW_Num[i];
	}
	return ( retValue );
}

FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadAppSW_Number (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data)
{
	Std_ReturnType retValue = RTE_E_OK;
	uint8 i = 0;
	for(i = 0;i < 7;i++)
	{
		*(Data+i) = ASW_Num[i];
	}
	return ( retValue );
}

FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadBSW_Number (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data)
{
	Std_ReturnType retValue = RTE_E_OK;
	uint8 i = 0;
	for(i = 0;i < 7;i++)
	{
		*(Data+i) = BSW_Num[i];
	}
	return ( retValue );
}

FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadDspData_Service_Date (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data)
{
	Std_ReturnType retValue = RTE_E_OK;
	uint8 i = 0;
	for(i = 0;i < 3;i++)
	{
		*(Data+i) = ServiceData[i];
	}
	return ( retValue );
}

FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadSupplierSpecific_ID (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data)
{
	Std_ReturnType retValue = RTE_E_OK;
	uint8 i = 0;
	for(i = 0;i < 2;i++)
	{
		*(Data+i) = Supplier_Spec_ID[i];
	}
	return ( retValue );
}

FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadSysSupplierECUHW_Num (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data)
{
	Std_ReturnType retValue = RTE_E_OK;
	*Data = Sys_Suppiler_ECUHW_Num;
	return ( retValue );
}

FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadSysSupplierECUSW_Num (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data)
{
	Std_ReturnType retValue = RTE_E_OK;
	*Data = Sys_Suppiler_ECUSW_Num;
	return ( retValue );
}

FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_ReadECUname_ID (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data)
{
	Std_ReturnType retValue = RTE_E_OK;
	uint8 i = 0;
	for(i = 0;i < 15;i++)
	{
		*(Data+i) = ECU_Name_ID[i];
	}
	return ( retValue );
}


uint8 GetSC_Flag_u8 = 0;
uint8 SesCtrlType_Test = 19;
uint8 ModeSwitch_Flag = 1;
/*Test Code*/
extern uint8 K_LV1[K_LENGTH];
extern uint8 K_LV2[K_LENGTH];
extern uint8 K_LV3[K_LENGTH];
extern uint8 K_LV4[K_LENGTH];

uint8 UDS27_Test = 0;
uint8 DEM_Test = 0;
uint8 DCM_Seed_FJ[SEED_LENGTH]={66,114,105,108,108,105,97,110,99,101,95,97,117,116,111,33};
uint8 DCM_Key_FJ[KEY_LENGTH];

FUNC(void, TestDiag_CODE) RE_Swc_Dem_Periodic(void)
{
	/*Here to generate Dcm seed random value*/
	Dcm_Seed_Cnt++;

	/*For DEM other uses, reserved by FJ*/
	switch(GetSC_Flag_u8)
	{
	case 1:
		Dcm_GetSesCtrlType(&SesCtrlType_Test);
		break;
	case 2:
		GetSC_Flag_u8 = 0;
		break;
	case 3:
		ModeSwitch_Flag = 1;
		Rte_Switch_Diag_SWC_PPort_Mdg2_MDGP_Mdg2(ModeSwitch_Flag);
		GetSC_Flag_u8 = 0;
		break;
	case 4:
		ModeSwitch_Flag = 0;
		Rte_Switch_Diag_SWC_PPort_Mdg2_MDGP_Mdg2(ModeSwitch_Flag);
		GetSC_Flag_u8 = 0;
		break;
	default:
		GetSC_Flag_u8 = 0;
		break;
	}
	switch(UDS27_Test)
	{
	case 1:
		HMACSHA1(K_LV1,DcmSeed,DcmKey);
		/* Key = 0x15 4A ED 59 CF B3 2E DC 37 8D 30 6B 0F 02 AB 6B */
		UDS27_Test = 0;
		break;
	case 2:
		HMACSHA1(K_LV2,DcmSeed,DcmKey);
		/* Key = 0xB4 36 B5 C7 49 AB BC 4D 68 ED DD B6 28 11 66 81 */
		UDS27_Test = 0;
		break;
	case 3:
		HMACSHA1(K_LV3,DcmSeed,DcmKey);
		/* Key = 0x5D 79 E2 D1 14 B6 3C B3 FC 38 07 42 8D 72 03 47 */
		UDS27_Test = 0;
		break;
	case 4:
		HMACSHA1(K_LV4,DcmSeed,DcmKey);
		/* Key = 0x86 8F 07 E6 05 97 88 FA DF E9 FB 35 1B 69 E8 54 */
		UDS27_Test = 0;
		break;
	case 5:
		Dcm_RandSeedCal();
		UDS27_Test = 0;
		break;
	case 6:
		Dcm_U16ToU8(Data_In_FJ,Data_Out_FJ);
		UDS27_Test = 0;
		break;
	default:

		break;

	}
	switch(DEM_Test)
	{
	case 1:
		Dem_Shutdown();
		NvM_WriteAll();
		DEM_Test = 0;
		break;
	case 2:

		DEM_Test = 0;
		break;
	default:

		break;
	}
}

FUNC(void, TestDiag_CODE) RunnableEntity_dcm(void)
{
	/*For DCM other uses, reserved by FJ*/
	uint8 ModeCondition_Type = 0;
	uint8 Ignition_Condition = 0;
	float32 Engine_Speed = 0;

	/*Get motor speed and ignition condition*/
	Rte_Read_SWC_MDF_RP_SWC_HSPF_HSPF_nSlowFlt(&Engine_Speed);//LQ20200630
	Ignition_Condition = Dio_ReadChannel(DioConf_DioChannel_DI_KL15_P21_5);/*ON returns 1*/

	/*Diagnostic enabled when ignition on and motor not running*/
	if(!((Engine_Speed > 0) || (Engine_Speed < 0)) && (Ignition_Condition == 1U))
	{
		ModeCondition_Type = DCM_MODE_TYPE_ONE;
	}
	else
	{
		ModeCondition_Type = DCM_MODE_TYPE_NONE;
	}

	/*Implement mode switch*/
	Rte_Switch_Diag_SWC_PPort_Mdg2_MDGP_Mdg2(ModeCondition_Type);

	SwcDcmEcuSoftReset_func();//FJ 20200409
	SwcDcmEcuJumpToBootLoader_func();//FJ 20200409
}

FUNC(Std_ReturnType, TestDiag_CODE) Swc_DSP_SEC_LEV_L1_CK_func(	P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Key,
        														VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
																CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
	Std_ReturnType retValue = RTE_E_OK;
	uint8 Dcm_SubKey_Num = 0;

	/*Calculate the key according to the Seed*/
	HMACSHA1(K_LV1,DcmSeed,DcmKey);

	for(Dcm_SubKey_Num = 0;Dcm_SubKey_Num < KEY_LENGTH;Dcm_SubKey_Num ++)
	{
		if(Key[Dcm_SubKey_Num] != DcmKey[Dcm_SubKey_Num])
		{
			retValue = SWC_COMPARE_KEY_FAILED;
		}
		else{/*Do nothing. Sub Key is correct.*/}
	}
	
	return ( retValue );
}
FUNC(Std_ReturnType, TestDiag_CODE) Swc_DSP_SEC_LEV_L1_GS_func( VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
        														CONSTP2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Seed,
																CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
	Std_ReturnType retValue = RTE_E_OK;
	uint8 Dcm_Seed_Num = 0;

	/*Get the seed of a random value*/
	Dcm_RandSeedCal();

	for(Dcm_Seed_Num = 0;Dcm_Seed_Num < SEED_LENGTH;Dcm_Seed_Num ++)
	{
		*(Seed+Dcm_Seed_Num) = DcmSeed[Dcm_Seed_Num];
	}

	return (retValue);
}
FUNC(Std_ReturnType, TestDiag_CODE) Swc_DSP_SEC_LEV_L2_CK_func( P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Key,
																VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
																CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
	Std_ReturnType retValue = RTE_E_OK;
	
	uint8 Dcm_SubKey_Num = 0;

	/*Calculate the key according to the Seed*/
	HMACSHA1(K_LV2,DcmSeed,DcmKey);

	for(Dcm_SubKey_Num = 0;Dcm_SubKey_Num < KEY_LENGTH;Dcm_SubKey_Num ++)
	{
		if(Key[Dcm_SubKey_Num] != DcmKey[Dcm_SubKey_Num])
		{
			retValue = SWC_COMPARE_KEY_FAILED;
		}
		else{/*Do nothing. Sub Key is correct.*/}
	}
	
	return ( retValue );
}
FUNC(Std_ReturnType, TestDiag_CODE) Swc_DSP_SEC_LEV_L2_GS_func( VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
																CONSTP2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Seed,
																CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
	Std_ReturnType retValue = RTE_E_OK;
	uint8 Dcm_Seed_Num = 0;

	/*Get the seed of a random value*/
	Dcm_RandSeedCal();

	for(Dcm_Seed_Num = 0;Dcm_Seed_Num < SEED_LENGTH;Dcm_Seed_Num ++)
	{
		*(Seed+Dcm_Seed_Num) = DcmSeed[Dcm_Seed_Num];
	}
	return (retValue);
}
FUNC(Std_ReturnType, TestDiag_CODE) Swc_DSP_SEC_LEV_L3_CK_func( P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Key,
																VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
																CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
	Std_ReturnType retValue = RTE_E_OK;
	
	uint8 Dcm_SubKey_Num = 0;

	/*Calculate the key according to the Seed*/
	HMACSHA1(K_LV3,DcmSeed,DcmKey);

	for(Dcm_SubKey_Num = 0;Dcm_SubKey_Num < KEY_LENGTH;Dcm_SubKey_Num ++)
	{
		if(Key[Dcm_SubKey_Num] != DcmKey[Dcm_SubKey_Num])
		{
			retValue = SWC_COMPARE_KEY_FAILED;
		}
		else{/*Do nothing. Sub Key is correct.*/}
	}
	
	return ( retValue );
}
FUNC(Std_ReturnType, TestDiag_CODE) Swc_DSP_SEC_LEV_L3_GS_func( VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
        														CONSTP2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Seed,
																CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
	Std_ReturnType retValue = RTE_E_OK;
	uint8 Dcm_Seed_Num = 0;

	/*Get the seed of a random value*/
	Dcm_RandSeedCal();

	for(Dcm_Seed_Num = 0;Dcm_Seed_Num < SEED_LENGTH;Dcm_Seed_Num ++)
	{
		*(Seed+Dcm_Seed_Num) = DcmSeed[Dcm_Seed_Num];
	}
	return (retValue);
}
FUNC(Std_ReturnType, TestDiag_CODE) Swc_DSP_SEC_LEV_L4_CK_func( P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Key,
																VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
																CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
	Std_ReturnType retValue = RTE_E_OK;
	
	uint8 Dcm_SubKey_Num = 0;

	/*Calculate the key according to the Seed*/
	HMACSHA1(K_LV4,DcmSeed,DcmKey);

	for(Dcm_SubKey_Num = 0;Dcm_SubKey_Num < KEY_LENGTH;Dcm_SubKey_Num ++)
	{
		if(Key[Dcm_SubKey_Num] != DcmKey[Dcm_SubKey_Num])
		{
			retValue = SWC_COMPARE_KEY_FAILED;
		}
		else{/*Do nothing. Sub Key is correct.*/}
	}
	
	return ( retValue );
}
FUNC(Std_ReturnType, TestDiag_CODE) Swc_DSP_SEC_LEV_L4_GS_func( VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
        														CONSTP2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Seed,
																CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
	Std_ReturnType retValue = RTE_E_OK;
	uint8 Dcm_Seed_Num = 0;

	/*Get the seed of a random value*/
	Dcm_RandSeedCal();

	for(Dcm_Seed_Num = 0;Dcm_Seed_Num < SEED_LENGTH;Dcm_Seed_Num ++)
	{
		*(Seed+Dcm_Seed_Num) = DcmSeed[Dcm_Seed_Num];
	}
	return (retValue);
}
FUNC(Std_ReturnType, TestDiag_CODE) Swc_RoutineServices_DcmDspRoutine_CheckProgCond_Result_func(VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
																								CONSTP2VAR(Dcm_RequestDataOut_DcmDspRoutine_CheckPgmPreCond_DcmDspRequestRoutineResultsOutSignal_0Type, AUTOMATIC, RTE_APPL_DATA) dataOut_DcmDspRequestRoutineResultsOutSignal_0,
																								CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
	Std_ReturnType retValue = RTE_E_OK;
	*ErrorCode = ( Dcm_NegativeResponseCodeType )RTE_E_OK;
	RoutineControl_CheckProgCond_Status += 0x100;

	return ( retValue );
}
FUNC(Std_ReturnType, Diag_SWC_CODE) Swc_RoutineServices_DcmDspRoutine_CheckProgCond_Start_func(VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
                                                                                               CONSTP2VAR(Dcm_StartDataOut_DcmDspRoutine_CheckPgmPreCond_DcmDspStartRoutineOutSignal_ESType, AUTOMATIC, RTE_APPL_DATA) DataOut_DcmDspStartRoutineOutSignal_ES,
                                                                                               CONSTP2VAR(Dcm_StartDataOut_DcmDspRoutine_CheckPgmPreCond_DcmDspStartRoutineOutSignal_VSType, AUTOMATIC, RTE_APPL_DATA) DataOut_DcmDspStartRoutineOutSignal_VS,
                                                                                               CONSTP2VAR(Dcm_StartDataOut_DcmDspRoutine_CheckPgmPreCond_DcmDspStartRoutineOutSignal_ICType, AUTOMATIC, RTE_APPL_DATA) DataOut_DcmDspStartRoutineOutSignal_IC,
                                                                                               CONSTP2VAR(Dcm_StartDataOut_DcmDspRoutine_CheckPgmPreCond_DcmDspStartRoutineOutSignal_VCType, AUTOMATIC, RTE_APPL_DATA) DataOut_DcmDspStartRoutineOutSignal_VC,
                                                                                               CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
	Std_ReturnType retValue = RTE_E_OK;
	float32 Engine_Speed = 0;
	float32 Voltage_Condition = 0;

	/*Here to Get the App data */
    Rte_Read_SWC_PCF_RP_SWC_HSPF_HSPF_nSlowFlt(&Engine_Speed);
	IoHwAb_ADC_GetPhyVoltage(0u,&Voltage_Condition);

	if((Engine_Speed > 0) ||(Engine_Speed < 0))
	{
		*DataOut_DcmDspStartRoutineOutSignal_ES = 0x01;
	}
	else
	{
		*DataOut_DcmDspStartRoutineOutSignal_ES = 0x00;
	}
#if 0
	if(Vehicle_Speed != 0)
	{
		*DataOut_DcmDspStartRoutineOutSignal_VS = 0x02;
	}
	else
	{
		*DataOut_DcmDspStartRoutineOutSignal_VS = 0x00;
	}

	if(Ignition_Condition != 0)
	{
		*DataOut_DcmDspStartRoutineOutSignal_IC = 0x03;
	}
	else
	{
		*DataOut_DcmDspStartRoutineOutSignal_IC = 0x00;
	}
#endif
	if((Voltage_Condition > DCM_VOLTAGE_MIN) && (Voltage_Condition < DCM_VOLTAGE_MAX))
	{
		*DataOut_DcmDspStartRoutineOutSignal_VC = 0x04;
	}
	else
	{
		*DataOut_DcmDspStartRoutineOutSignal_VC = 0x00;
	}
	*ErrorCode = ( Dcm_NegativeResponseCodeType )RTE_E_OK;
	RoutineControl_CheckProgCond_Status += 0x01;

	return ( retValue );
}
FUNC(Std_ReturnType, TestDiag_CODE) Swc_RoutineServices_DcmDspRoutine_CheckProgCond_Stop_func(  VAR(Dcm_StopDataIn_DcmDspRoutine_CheckPgmPreCond_DcmDspStopRoutineInSignal_0Type, AUTOMATIC) dataIn_DcmDspStopRoutineInSignal_0,
																								VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
																								CONSTP2VAR(Dcm_StopDataOut_DcmDspRoutine_CheckPgmPreCond_DcmDspStopRoutineOutSignal_0Type, AUTOMATIC, RTE_APPL_DATA) dataOut_DcmDspStopRoutineOutSignal_0,
																								CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
	Std_ReturnType retValue = RTE_E_OK;
	*ErrorCode = ( Dcm_NegativeResponseCodeType )RTE_E_OK;
	RoutineControl_CheckProgCond_Status += 0x10;

	return ( retValue );
}
FUNC(Std_ReturnType, TestDiag_CODE) Swc_RoutineServices_DcmDspRoutine_Test_Result_func( VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
																						CONSTP2VAR(Dcm_RequestDataOut_DcmDspRoutine_Test_DcmDspRequestRoutineResultsOutSignal_0Type, AUTOMATIC, RTE_APPL_DATA) dataOut_DcmDspRequestRoutineResultsOutSignal_0,
																						CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
	Std_ReturnType retValue = RTE_E_OK;
	*ErrorCode = ( Dcm_NegativeResponseCodeType )RTE_E_OK;
	RoutineControl_Test_Status += 0x100;

	return ( retValue );
}
FUNC(Std_ReturnType, TestDiag_CODE) Swc_RoutineServices_DcmDspRoutine_Test_Start_func(	VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
        																				CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
	Std_ReturnType retValue = RTE_E_OK;
	*ErrorCode = ( Dcm_NegativeResponseCodeType )RTE_E_OK;
	RoutineControl_Test_Status += 0x01;

	return ( retValue );
}
FUNC(Std_ReturnType, TestDiag_CODE) Swc_RoutineServices_DcmDspRoutine_Test_Stop_func(	VAR(Dcm_StopDataIn_DcmDspRoutine_Test_DcmDspStopRoutineInSignal_0Type, AUTOMATIC) dataIn_DcmDspStopRoutineInSignal_0,
																						VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
																						CONSTP2VAR(Dcm_StopDataOut_DcmDspRoutine_Test_DcmDspStopRoutineOutSignal_0Type, AUTOMATIC, RTE_APPL_DATA) dataOut_DcmDspStopRoutineOutSignal_0,
																						CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
	Std_ReturnType retValue = RTE_E_OK;
	*ErrorCode = ( Dcm_NegativeResponseCodeType )RTE_E_OK;
	RoutineControl_Test_Status += 0x10;

	return ( retValue );
}

/*Fnc to implement UDS $2F*/
/*FJ 2020/3/26*/
FUNC(Std_ReturnType,DCM_APPL_CODE) DataReadFnc_Test (P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data)
{
	Std_ReturnType retValue = RTE_E_OK;
	*Data = VAR_IOControl_u8;
	return ( retValue );
}

FUNC(Std_ReturnType,DCM_APPL_CODE) FreeseCurrentStateFnc_Test (P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_INTERN_DATA) ErrorCode)
{
	Std_ReturnType retValue = RTE_E_OK;
	*ErrorCode = ( Dcm_NegativeResponseCodeType )RTE_E_OK;
	InputOutputControl_Test_Status += 0x01;
	VAR_IOControl_u8++;
	return ( retValue );
}


/***Extern declarations for XXX_ResetToDefaultFnc of type USE_DATA_SYNCH_FNC ***/
FUNC(Std_ReturnType,DCM_APPL_CODE) ResetToDefault_Test (P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_INTERN_DATA) ErrorCode)
{
	Std_ReturnType retValue = RTE_E_OK;
	*ErrorCode = ( Dcm_NegativeResponseCodeType )RTE_E_OK;
	InputOutputControl_Test_Status += 0x01;
	VAR_IOControl_u8 = 0;

	return ( retValue );
}

/***Extern declarations for ReturnControlToEcuFnc.Only Synchronous API is used irrespective of UsePort Configuration to USE_DATA_SYNCH_FNC or USE_DATA_ASYNCH_FNC **/
FUNC(Std_ReturnType,DCM_APPL_CODE) ReturnControlToECUFnc_Test (P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_INTERN_DATA) ErrorCode)
{
	Std_ReturnType retValue = RTE_E_OK;
	*ErrorCode = ( Dcm_NegativeResponseCodeType )RTE_E_OK;
	InputOutputControl_Test_Status += 0x01;

	return ( retValue );
}

/***Extern declarations for ShortTermAdjustmentFnc of type USE_DATA_SYNCH_FNC  for Fixed LENGTH with no control mask or internal control mask handling***/
FUNC(Std_ReturnType,DCM_APPL_CODE) AdjustmentFnc_Test (P2CONST(uint8,AUTOMATIC,DCM_INTERN_DATA) ControlStateInfo,P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_INTERN_DATA) ErrorCode)
{
	Std_ReturnType retValue = RTE_E_OK;
	*ErrorCode = ( Dcm_NegativeResponseCodeType )RTE_E_OK;
	InputOutputControl_Test_Status += 0x01;
	VAR_IOControl_u8 = *ControlStateInfo;

	return ( retValue );
}

/*******************************************************************************
** Function Name	: Dcm_RandSeedCal
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: This function implemented to generate random seed value.
*******************************************************************************/
void Dcm_RandSeedCal(void)
{
	uint8 Seed_Num = 0;
	for(Seed_Num = 0;Seed_Num < SEED_LENGTH;Seed_Num ++)
	{
		DcmSeed[Seed_Num] = Dcm_Seed_Cnt;
		Dcm_Seed_Cnt ++;
	}
}

static void Diag_memcpy(uint8 *dstAddr, uint8 *srcAddr, uint8 size)
{
    while (size--)
    {
        *dstAddr++ = *srcAddr++;
    }
    return;
}
