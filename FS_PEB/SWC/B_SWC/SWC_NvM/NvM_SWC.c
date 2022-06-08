/* *****************************************************************************
 * BEGIN: Banner
 *-----------------------------------------------------------------------------
 *                                 ETAS GmbH
 *                      D-70469 Stuttgart, Borsigstr. 14
 *-----------------------------------------------------------------------------
 ****************************************************************************/
#include "Std_Types.h"
#include "Snapshot_Can_PBCfg.h"
#include "Rte_NvM_SWC.h"
#include "BswM.h"
#include "Fls.h"
#include "NvM_SWC.h"
#include "Rte_Dem_Type.h"
#include "Dem.h"

#include "SchM_BswM_Type.h"

#define RTE_START_SEC_Partition_Core0_CODE
#include "NvM_SWC_MemMap.h"
static uint8 NvM_SwcICopyDataToRam(uint8 * dest_addr, uint8 * src_addr, uint32 size);
#define RTE_STOP_SEC_Partition_Core0_CODE
#include "NvM_SWC_MemMap.h"

#define RTE_START_SEC_Partition_Core0_VAR_INIT_BOOLEAN
#include "NvM_SWC_MemMap.h"
static boolean Erase_Enable = FALSE;
#define RTE_STOP_SEC_Partition_Core0_VAR_INIT_BOOLEAN
#include "NvM_SWC_MemMap.h"

#define RTE_START_SEC_Partition_Core0_VAR_CLEARED_UNSPECIFIED
#include "NvM_SWC_MemMap.h"
uint8 NvM_RamBlock_RedundantBlock_1024[1024];
#define RTE_STOP_SEC_Partition_Core0_VAR_CLEARED_UNSPECIFIED
#include "NvM_SWC_MemMap.h"

#define RTE_START_SEC_Partition_Core0_VAR_INIT_32
#include "NvM_SWC_MemMap.h"
//static uint32 modify_addr1 = 0x200;
//static uint32 modify_addr2 = 0x600;
#define RTE_STOP_SEC_Partition_Core0_VAR_INIT_32
#include "NvM_SWC_MemMap.h"

#define RTE_START_SEC_Partition_Core0_VAR_CLEARED_UNSPECIFIED
#include "NvM_SWC_MemMap.h"
static uint8 InvalidData[2176u]={0};
//static uint8 MngData[32u]={0};
#define RTE_STOP_SEC_Partition_Core0_VAR_CLEARED_UNSPECIFIED
#include "NvM_SWC_MemMap.h"

#define RTE_START_SEC_Partition_Core0_VAR_INIT_8
#include "NvM_SWC_MemMap.h"
static uint8 RedundantBlockTestData=0xCA;
#define RTE_STOP_SEC_Partition_Core0_VAR_INIT_8
#include "NvM_SWC_MemMap.h"

#define RTE_START_SEC_Partition_Core0_VAR_CLEARED_UNSPECIFIED
#include "NvM_SWC_MemMap.h"
#define NvM_SWC_FIRSTWRITE 0U
#define NvM_SWC_DELAY      1U
#define NvM_SWC_SECONDWRITE  2U
#define NvM_SWC_WRITECNT_MAX 200U
/*Test data*/
/*Test data used for testing write operation of block native 1024*/
uint8 TEST_DATA_NVM_NATIVE_1024[1024];

/*Test data used for testing write operation of block redundant 1024*/
uint8 TEST_DATA_NVM_REDUNDANT_1024[1024];

/*NvM_User Data*/
float32 NvM_MC_OffSet=0;//FJ
uint8 errOderTable[64]={0};//FJ
uint8 VAR_DEM_DiagEvtHistList_au8[NVM_CFG_NV_BLOCK_LENGTH_DEM_HistoryEventList] = {0};//FJ
uint8 VAR_NvM_EEP_Study_au8[8]={0};//FJ
uint8 VAR_NvM_TLC_TrqReason_au8[6] = {0};
boolean VAR_NvM_BSW_NVM_SLFnh_au8 = FALSE;//FJ
uint8 VAR_NvM_BSW_NVM_AimOutP_au8[8]={0};//FJ
uint8 VAR_NvM_EPC_NVMPosAimUpLimt_au8[8]={0};//FJ
float32 VAR_NvM_EPC_flgSLWD_au8 = 0;//FJ
uint8 VAR_NvM_UDS_VIN[17] = {0};//FJ 2020/5/14
uint8 VAR_NvM_UDS_ECUPN_V0[4] = {0};//FJ 2020/5/9
uint8 VAR_NvM_UDS_ECUPN_V4 = 0;//FJ 2020/5/9
uint8 VAR_NvM_UDS_ECUPN_V5 = 0;//FJ 2020/5/9
boolean VAR_BSW_NVM_OffSet = FALSE;

/*EPC Read Related Data*/
uint8  NvM_StopEPCRead_u8 = 0;
uint8  NvM_StopMCRead_u8 = 0;

/*Test Code*/
boolean  EPC_Write_Test_FJ = FALSE;//FJ 20200411
boolean  EPC_Read_Test_FJ = FALSE;//FJ 20200411
boolean  NvM2EPC_Write_OK_Flg_Test_FJ = FALSE;//FJ 20200413
uint8  NvM2EPC_Write_OK_Flg_Test3_FJ = 0;//FJ 20200413
float32  DataFrom_DFlash_FJ = 0;
uint8 NvM_EPCWrite_State = 0;
uint8  NvM_EPCFirstWrite_Cnt = 0;

uint8 NvM_EPC_Test = 0;//20200413
uint8 NvM_EPC_RequestResult = NVM_REQ_NOT_OK;

/*MC Variable*/
boolean MC_Read_Test_FJ = FALSE;
boolean MC_Write_Test_FJ = FALSE;

boolean MC2NvM_Write_Flg = FALSE;
float32 DatafromMC = 10;
boolean NvM2MC_Write_OK_Flg = FALSE;
uint8 NvM_MC_RequestResult = NVM_REQ_NOT_OK;
uint8 NvM_MCWrite_State = NvM_SWC_FIRSTWRITE;
uint8  NvM_MCFirstWrite_Cnt = 0;

#define RTE_STOP_SEC_Partition_Core0_VAR_CLEARED_UNSPECIFIED
#include "NvM_SWC_MemMap.h"
/***************************************************************************************************
 Function name    : ASWC_NvM_Run_func
 Syntax           : void  ASWC_NvM_Run_func(none)
 Description      : Test code for MEM stack
 Parameter        : none
 Return value     : none
 ***************************************************************************************************/
#define RTE_START_SEC_Partition_Core0_CODE
#include "NvM_SWC_MemMap.h"

#pragma GCC push_options
#pragma GCC optimize ("O0")

FUNC(void, NvM_SWC_CODE) RE_NvM_SWC_func(void){
	EPC_WriteBlock();
	RCF_WriteBlock();
	SWC_Write_Test();

	static uint8 NvM_Test = 0;
	static MDF_Both_State_t TC_CorruptBothNvM = MODIFY_BOTH_NV_BLOCK_NONE;
	boolean retVal 		= E_NOT_OK;
	uint8 Erase_result 	= E_NOT_OK;
	/*  -------------------------------------- Server Call Point  --------------------------------  */
	switch(Erase_Enable)
	{
	case ERASE_BANK0:
		Erase_result = Fls_17_Pmu_Erase(0x0,FLS_SECTOR_SIZE);
		Erase_Enable = 0;
		break;
	case ERASE_BANK1:
		Erase_result = Fls_17_Pmu_Erase(FLS_SECTOR_SIZE,FLS_SECTOR_SIZE);
		Erase_Enable = 0;
		break;
	case 3:
		//Rte_Write_SWC_SMG_PP_SWC_SMG_SMG_stSysCtl(RTE_MODE_MDG_ECUM_STATE_ECUM_STATE_PREP_SHUTDOWN);
		Erase_Enable = 0;
		break;
	case 4:
		//Rte_Write_SWC_SMG_PP_SWC_SMG_SMG_stSysCtl(RTE_MODE_MDG_ECUM_STATE_ECUM_STATE_RUN);
		Erase_Enable = 0;
		break;
	default :
		Erase_Enable = 0;
		break;
	}
#if 0
//	switch(NvM_Test)
//	{
//		case ASW_WRITE_BLOCK_1024:
//			/*Update 1024 bytes of value 0x7E to test block*/
//			UpdatePIMWithValue(TEST_DATA_NVM_NATIVE_1024,1024u,0x14);
//
//			retVal = Rte_Call_RPort_NvM_SWC_BlockNative_1024_WriteBlock(TEST_DATA_NVM_NATIVE_1024);
//
//			/*Set NvM_Test back to SWC_ZERO to prevent further write operation*/
//			NvM_Test = SWC_ZERO;
//			break;
//		case ASW_READ_BLOCK_1024:
//			/*Erase PIM before read*/
//			UpdatePIMWithValue(Rte_CPim_NvM_SWC_NvM_SWC_BlockNative_1024,1024,0);
//
//			/*Perform read block*/
//			retVal = Rte_Call_RPort_NvM_SWC_BlockNative_1024_ReadBlock(Rte_CPim_NvM_SWC_NvM_SWC_BlockNative_1024);
//
//			/*Set NvM_Test back to SWC_ZERO to prevent further read operation*/
//			NvM_Test = SWC_ZERO;
//			break;
//		case ASW_WRITE_REDUNDANT_BLOCK_1024:
//			/*Update 1024 bytes of value 0x7E to test block*/
//			UpdatePIMWithValue(TEST_DATA_NVM_REDUNDANT_1024,1024u,0x3C);
//
//			retVal = Rte_Call_RPort_NvM_SWC_BlockRedundant_1024_WriteBlock(TEST_DATA_NVM_REDUNDANT_1024);
//
//			/*Set NvM_Test back to SWC_ZERO to prevent further write operation*/
//			NvM_Test = SWC_ZERO;
//			break;
//		case ASW_READ_REDUNDANT_BLOCK_1024:
//			/*Erase PIM before read*/
//			UpdatePIMWithValue(NvM_RamBlock_RedundantBlock_1024,1024,0);
//
//			/*Perform read block*/
//			retVal = Rte_Call_RPort_NvM_SWC_BlockRedundant_1024_ReadBlock(NvM_RamBlock_RedundantBlock_1024);
//
//			/*Set NvM_Test back to SWC_ZERO to prevent further read operation*/
//			NvM_Test = SWC_ZERO;
//			break;
//		case ASW_WRITE_ALL_BLKS_REQ:
//			/*Update PIM with new value*/
//			UpdatePIMWithValue(Rte_CPim_NvM_SWC_NvM_SWC_BlockNative_1024,1024,0x33);
//			UpdatePIMWithValue(NvM_RamBlock_RedundantBlock_1024,1024,0x66);
//			/*Change block status*/
//			retVal |= Rte_Call_RPort_NvM_SWC_BlockNative_1024_SetRamBlockStatus(TRUE);
//			retVal |= Rte_Call_RPort_NvM_SWC_BlockRedundant_1024_SetRamBlockStatus(TRUE);
//		//	retVal |= Rte_Call_RPort_ShutdownTarget_SelectShutdownTarget(ECUM_SHUTDOWN_TARGET_OFF,0);
//		//	retVal |= Rte_Call_RPort_RequestBswMShutdown_BswMSwcGenericRequest(0, 1);
//			retVal |=  Rte_Call_RPort_ShutdownTarget_SelectShutdownTarget(ECUM_SHUTDOWN_TARGET_RESET,0);
//			retVal |=  Rte_Write_PPort_NvM_Request_Shutdown_uint16(RTE_MODE_MDG_ECUM_STATE_ECUM_STATE_APP_POST_RUN);
//			/*Set NvM_Test back to SWC_ZERO to prevent further erase operation*/
//			NvM_Test = SWC_ZERO;
//			break;
//		case ASW_CORRUPT_ONE_BLOCK_OF_REDUNDANT_BLOCK_1024_1:
//			retVal = NvM_SwcIModifyNvBlock(modify_addr1);
//			if(retVal == E_OK){
//				NvM_Test = SWC_ZERO;
//			}
//			break;
//		case ASW_CORRUPT_ONE_BLOCK_OF_REDUNDANT_BLOCK_1024_2:
//			retVal = NvM_SwcIModifyNvBlock(modify_addr2);
//			if(retVal == E_OK){
//				NvM_Test = SWC_ZERO;
//			}
//			break;
//		case ASW_CORRUPT_TWO_BLOCK_OF_REDUNDANT_BLOCK_1024:
//			switch(TC_CorruptBothNvM)
//			{
//			case MODIFY_BOTH_NV_BLOCK_NONE:
//				TC_CorruptBothNvM = MODIFY_READ_BLOCK;
//				break;
//			case MODIFY_READ_BLOCK:
//				if(E_OK == NvM_SwcIModifyNvBlock(modify_addr1)){
//					TC_CorruptBothNvM = MODIFY_BACKUP_BLOCK;
//				}
//				break;
//			case MODIFY_BACKUP_BLOCK:
//				if(E_OK == NvM_SwcIModifyNvBlock(modify_addr2)){
//					TC_CorruptBothNvM = MODIFY_BOTH_NV_BLOCK_NONE;
//					NvM_Test = SWC_ZERO;
//				}
//				break;
//			default:
//				break;
//			}
//			break;
//		default:
//			break;
//	}
#endif
};

#pragma GCC pop_options

#define RTE_STOP_SEC_Partition_Core0_CODE
#include "NvM_SWC_MemMap.h"

/***************************************************************************************************
 Function name    : ReadAll_ImmediateBlock
 Syntax           : void  ReadAll_ImmediateBlock(none)
 Description      : Read All Immediate Block
 Parameter        : none
 Return value     : none
 ***************************************************************************************************/
#define RTE_START_SEC_Partition_Core0_CODE
#include "NvM_SWC_MemMap.h"
void ReadAll_ImmediateBlock (void)
{
	//Rte_Call_NvM_SWC_RPort_NvM_SWC_BlockNative_1024_ReadBlock(Rte_CPim_NvM_SWC_NvM_SWC_BlockNative_1024);//LQ
	//Rte_Call_NvM_SWC_RPort_NvM_SWC_BlockRedundant_1024_ReadBlock(NvM_RamBlock_RedundantBlock_1024);
}
#define RTE_STOP_SEC_Partition_Core0_CODE
#include "NvM_SWC_MemMap.h"

/***************************************************************************************************
 Function name    : WriteAll_ImmediateBlock
 Syntax           : void  WriteAll_ImmediateBlock(none)
 Description      : Write All Immediate Block
 Parameter        : none
 Return value     : none
 ***************************************************************************************************/
#define RTE_START_SEC_Partition_Core0_CODE
#include "NvM_SWC_MemMap.h"
void WriteAll_ImmediateBlock (void)
{
//	Rte_Call_RPort_NvM_SWC_BlockNative_1024_WriteBlock(Rte_CPim_NvM_SWC_NvM_SWC_BlockNative_1024);
//	Rte_Call_RPort_NvM_SWC_BlockRedundant_1024_WriteBlock(NvM_RamBlock_RedundantBlock_1024);
}

#define RTE_STOP_SEC_Partition_Core0_CODE
#include "NvM_SWC_MemMap.h"

/***************************************************************************************************
 Function name    : UpdatePIMWithValue
 Syntax           : void  UpdatePIMWithValue(uint8 *src, uint32 length, uint8 Value)
 Description      : Update PIM's value
 Parameter        : uint8 *src, uint32 length, uint8 Value
 Return value     : none
 ***************************************************************************************************/
#define RTE_START_SEC_Partition_Core0_CODE
#include "NvM_SWC_MemMap.h"

void UpdatePIMWithValue(uint8 *dst, uint32 length, uint8 Value)
{
	uint32 Cnt = 0;
	for(Cnt = 0; Cnt < length; Cnt++)
	{
		*dst = Value;
		dst++;
	}
}

#define RTE_STOP_SEC_Partition_Core0_CODE
#include "NvM_SWC_MemMap.h"

/***************************************************************************************************
 Function name    : NvM_SwcIModifyNvBlock
 Syntax           : void  NvM_SwcIModifyNvBlock(uint32 addr)
 Description      : Modify data on NV Block
 Parameter        : uint32 addr
 Return value     : none
 ***************************************************************************************************/
#define RTE_START_SEC_Partition_Core0_CODE
#include "NvM_SWC_MemMap.h"
uint8 NvM_SwcIModifyNvBlock(uint32 addr)
{
	static MDF_State_t MDF_State = MDF_NONE;
	uint8 ret_val = E_NOT_OK;
	switch(MDF_State)
	{
	case MDF_NONE:
		MDF_State = MDF_INIT_STATE;
		break;
	case MDF_INIT_STATE: /*copy data flash to buffer ram*/
		NvM_SwcICopyDataToRam(InvalidData, (uint8*)0xAF000000, sizeof(InvalidData));
		//NvM_SwcICopyDataToRam(MngData, (uint8*)0xAF02FFE0, sizeof(MngData));
		//Fee_I_SyncRead(&MngData[0],(uint32)0xAF007FD0,(sizeof(MngData)/sizeof(uint32)));
		MDF_State = MDF_ERASE_BANK;
		break;
	case MDF_ERASE_BANK: /*erase bank 0 before write data*/
		Erase_Enable = ERASE_BANK0;
		MDF_State = MDF_MODIFY_DATA;
		break;
	case MDF_MODIFY_DATA:
		InvalidData[addr]= RedundantBlockTestData - 1;
		MDF_State = MDF_UPDATE_DATA;
		break;
	case MDF_UPDATE_DATA: /*write data back to bank 0*/
		if( Fls_ConfigPtr->FlsStateVarPtr->FlsJobResult == MEMIF_JOB_OK){
			Fls_17_Pmu_Write((uint32)0x0, &InvalidData[0], sizeof(InvalidData));
			MDF_State = MDF_UPDATE_MANANGMENT_INFO;
//			MDF_State = MDF_NONE;
//			ret_val = E_OK;
		}
		break;
	case MDF_UPDATE_MANANGMENT_INFO: /*write back  management data*/
		if( Fls_ConfigPtr->FlsStateVarPtr->FlsJobResult == MEMIF_JOB_OK){
			//Fls_17_Pmu_Write((uint32)0x2FFE0, &MngData[0], sizeof(MngData));
			MDF_State = MDF_NONE;
			ret_val = E_OK;
		}
		break;
	default :
		break;
	}
	return ret_val ;
}
#define RTE_STOP_SEC_Partition_Core0_CODE
#include "NvM_SWC_MemMap.h"

/***************************************************************************************************
 Function name    : NvM_SwcICopyDataToRam
 Syntax           : static uint8 NvM_SwcICopyDataToRam(uint8 * dest_addr, uint8 * src_addr, size)
 Description      : Copy data from ROM to RAM for testing purpose
 Parameter        : uint8 * dest_addr, uint8 * src_addr, size
 Return value     : none
 ***************************************************************************************************/
#define RTE_START_SEC_Partition_Core0_CODE
#include "NvM_SWC_MemMap.h"
static uint8 NvM_SwcICopyDataToRam(uint8 * dest_addr, uint8 * src_addr, uint32 size)
{
	uint8 retVal = E_NOT_OK;
	if((dest_addr == NULL) || (NULL == src_addr) || (0u == size))
	{
		return retVal;
	}
	while(size > 0u)
	{
		*dest_addr = *src_addr;
		dest_addr++;
		src_addr++;
		size--;
	}
	retVal = E_OK;

	return retVal;
}
#define RTE_STOP_SEC_Partition_Core0_CODE
#include "NvM_SWC_MemMap.h"

/***************************************************************************************************
 Function name    : EPC_WriteBlock
 Syntax           : void  EPC_WriteBlock(none)
 Description      : EPC Write data to DFlash via NvM.
 Parameter        : none
 Return value     : none
 ***************************************************************************************************/
void EPC_WriteBlock (void)
{
	/*Load EPC data and write OK flag from DFlash after Power up*/
	if((NvM_StopEPCRead_u8 < 2)||(EPC_Read_Test_FJ))
	{
		/*Read EPC data and flag from DFlash*/
		NvM_ReadBlock(NvMConf_NvMBlockDescriptor_BSW_NVM_SLFnh,&VAR_NvM_BSW_NVM_SLFnh_au8);
		NvM_ReadBlock(NvMConf_NvMBlockDescriptor_EPC_flgSLWD,&VAR_NvM_EPC_flgSLWD_au8);

		/*write data from DFlash to EPC*/
		Rte_Write_NvM_SWC_PP_SWC_NvM_NvM_SLInPLimt(VAR_NvM_EPC_flgSLWD_au8);
		Rte_Write_NvM_SWC_PP_SWC_NvM_NvM_SLFnh(VAR_NvM_BSW_NVM_SLFnh_au8);
		NvM_StopEPCRead_u8++;
	}

	/*Read EPC write Flag*/
	Rte_Read_NvM_SWC_RP_SWC_PCF_PCF_flgSLWD(&EPC2NvM_Write_Flg);//LQ

	if((EPC2NvM_Write_Flg==TRUE)||(EPC_Write_Test_FJ))
	{
		if(NvM_SWC_FIRSTWRITE == NvM_EPCWrite_State )
		{
			/*Read EPC Data which needed to be written to DFlash*/
			Rte_Read_NvM_SWC_RP_SWC_PCF_PCF_SLInPLimt(&DatafromEPC);

			NvM_WriteBlock(NvMConf_NvMBlockDescriptor_EPC_flgSLWD,&DatafromEPC);
			EPC_Write_Test_FJ = TRUE;
		}
		if(NvM_SWC_DELAY == NvM_EPCWrite_State)
		{
			if(NvM_EPC_RequestResult == NVM_REQ_OK)
			{
				NvM2EPC_Write_OK_Flg = TRUE;
			}
			else if(NvM_EPC_RequestResult == NVM_REQ_NOT_OK)
			{
				NvM2EPC_Write_OK_Flg = FALSE;
			}
			else
			{
				/*Do Nothing*/
			}

		}
		if(NvM_SWC_SECONDWRITE == NvM_EPCWrite_State)
		{
			/*Send Write OK Flag back to EPC from RAM*/
			Rte_Write_NvM_SWC_PP_SWC_NvM_NvM_SLFnh(NvM2EPC_Write_OK_Flg);
			if(!NvM2EPC_Write_OK_Flg)
			{
				/*Report Write Error*/
//				Dem_SetEventStatus(DemConf_DemEventParameter_EPCWriteFail,DEM_EVENT_STATUS_FAILED);//FJ
			}
			else
			{
				/*Clear Write Error*/
//				Dem_SetEventStatus(DemConf_DemEventParameter_EPCWriteFail,DEM_EVENT_STATUS_PASSED);//FJ
			}
			NvM_WriteBlock(NvMConf_NvMBlockDescriptor_BSW_NVM_SLFnh,&NvM2EPC_Write_OK_Flg);
			EPC_Write_Test_FJ = FALSE;
		}

		NvM_EPCFirstWrite_Cnt++;

		/*Write State Manage*/
		if((0U < NvM_EPCFirstWrite_Cnt)&&(NvM_EPCFirstWrite_Cnt < NvM_SWC_WRITECNT_MAX))
		{
			NvM_EPCWrite_State = NvM_SWC_DELAY;
			NvM_GetErrorStatus(NvMConf_NvMBlockDescriptor_EPC_flgSLWD,&NvM_EPC_RequestResult);
			if(NVM_REQ_OK == NvM_EPC_RequestResult)
			{
				NvM_EPCFirstWrite_Cnt = NvM_SWC_WRITECNT_MAX-1U;
			}
		}
		else if(NvM_EPCFirstWrite_Cnt == NvM_SWC_WRITECNT_MAX)
		{
			NvM_EPCWrite_State = NvM_SWC_SECONDWRITE;

		}
		else
		{
			NvM_EPCWrite_State = NvM_SWC_FIRSTWRITE;
			NvM_EPCFirstWrite_Cnt = 0;
		}

	}
}

/***************************************************************************************************
 Function name    : MC_WriteBlock
 Syntax           : void  MC_WriteBlock(none)
 Description      : MC Write data to DFlash via NvM.
 Parameter        : none
 Return value     : none
 ***************************************************************************************************/
void RCF_WriteBlock(void)
{
	Rte_Write_NvM_SWC_PP_SWC_NvM_NvM_AngAutoClbOffset(SnapshotCan_DefConfigType_S.OffsetRamInfoPtr->OffsetValue);
	Rte_Write_NvM_SWC_PP_SWC_NvM_NvM_flgAngAutoClbOffset(SnapshotCan_DefConfigType_S.OffsetRamInfoPtr->OffsetFlag);

#if 0
	/*Load MC data and write OK flag from DFlash after Power up*/
	if((NvM_StopMCRead_u8 < 2)||(MC_Read_Test_FJ))
	{
		/*Read MC data and flag from DFlash*/
//		NvM_ReadBlock(NvMConf_NvMBlockDescriptor_BSW_NVM_OffSet,&VAR_BSW_NVM_OffSet);
//		NvM_ReadBlock(NvMConf_NvMBlockDescriptor_EPC_flgSLWD,&NvM_MC_OffSet);

		/*write data from DFlash to MC*/
		Rte_Write_NvM_SWC_PP_SWC_NvM_NvM_AngAutoClbOffset(NvM_MC_OffSet);
		Rte_Write_NvM_SWC_PP_SWC_NvM_NvM_flgAngAutoClbOffset(VAR_BSW_NVM_OffSet);
		NvM_StopMCRead_u8++;
	}

	/*Read MC write Flag*/
	Rte_Read_NvM_SWC_RP_SWC_RCF_RCF_flgOfsClbSucToNVM(&MC2NvM_Write_Flg);//FJ

	if((MC2NvM_Write_Flg==TRUE)||(MC_Write_Test_FJ))
	{
		if(NvM_SWC_FIRSTWRITE == NvM_MCWrite_State )
		{
			/*Read MC Data which needed to be written to DFlash*/
			Rte_Read_NvM_SWC_RP_SWC_RCF_RCF_AutoClbOffset(&DatafromMC);

			NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvM_MC_Offset,&DatafromMC);
			MC_Write_Test_FJ = TRUE;
		}
		if(NvM_SWC_DELAY == NvM_MCWrite_State)
		{
			if(NvM_MC_RequestResult == NVM_REQ_OK)
			{
				NvM2MC_Write_OK_Flg = TRUE;
			}
			else if(NvM_MC_RequestResult == NVM_REQ_NOT_OK)
			{
				NvM2MC_Write_OK_Flg = FALSE;
			}
			else
			{
				/*Do Nothing*/
			}

		}
		if(NvM_SWC_SECONDWRITE == NvM_MCWrite_State)
		{
			/*Send Write OK Flag back to EPC from RAM*/
			Rte_Write_NvM_SWC_PP_SWC_NvM_NvM_flgAngAutoClbOffset(NvM2MC_Write_OK_Flg);
			if(!NvM2MC_Write_OK_Flg)
			{
				/*Report Write Error*/
				Dem_SetEventStatus(DemConf_DemEventParameter_V06_MCWriteFail,DEM_EVENT_STATUS_FAILED);
			}
			else
			{
				/*Clear Write Error*/
				Dem_SetEventStatus(DemConf_DemEventParameter_V06_MCWriteFail,DEM_EVENT_STATUS_PASSED);
			}
			NvM_WriteBlock(NvMConf_NvMBlockDescriptor_BSW_NVM_OffSet,&NvM2MC_Write_OK_Flg);
			MC_Write_Test_FJ = FALSE;
		}

		NvM_MCFirstWrite_Cnt++;

		/*Write State Manage*/
		if((0U < NvM_MCFirstWrite_Cnt)&&(NvM_MCFirstWrite_Cnt < NvM_SWC_WRITECNT_MAX))
		{
			NvM_MCWrite_State = NvM_SWC_DELAY;
			NvM_GetErrorStatus(NvMConf_NvMBlockDescriptor_NvM_MC_Offset,&NvM_MC_RequestResult);
			if(NVM_REQ_OK == NvM_MC_RequestResult)
			{
				NvM_MCFirstWrite_Cnt = NvM_SWC_WRITECNT_MAX-1U;
			}
		}
		else if(NvM_MCFirstWrite_Cnt == NvM_SWC_WRITECNT_MAX)
		{
			NvM_MCWrite_State = NvM_SWC_SECONDWRITE;

		}
		else
		{
			NvM_MCWrite_State = NvM_SWC_FIRSTWRITE;
			NvM_MCFirstWrite_Cnt = 0;
		}

	}
#endif
}

/***************************************************************************************************
 Function name    : SWC_Write_Test
 Syntax           : void  SWC_Write_Test(none)
 Description      : Test code for MEM stack
 Parameter        : none
 Return value     : none
 ***************************************************************************************************/
void SWC_Write_Test(void)
{
	switch(NvM_EPC_Test)
	{
	case 1:
		DataFrom_DFlash_FJ = 32.4;
		NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvM_MC_Offset,&DataFrom_DFlash_FJ);
		NvM_EPC_Test = 0;
		break;
	case 2:
		NvM_ReadBlock(NvMConf_NvMBlockDescriptor_NvM_MC_Offset,&NvM_MC_OffSet);
		NvM_EPC_Test = 0;
		break;
	case 3:
		NvM2EPC_Write_OK_Flg_Test3_FJ = TRUE;
		NvM_WriteBlock(NvMConf_NvMBlockDescriptor_BSW_NVM_OffSet,&NvM2EPC_Write_OK_Flg_Test3_FJ);
		NvM_EPC_Test = 0;
		break;
	case 4:
		NvM_ReadBlock(NvMConf_NvMBlockDescriptor_BSW_NVM_OffSet,&VAR_BSW_NVM_OffSet);
		NvM_EPC_Test = 0;
		break;
	default:
		NvM_EPC_Test = 0;
		break;
	}
}
