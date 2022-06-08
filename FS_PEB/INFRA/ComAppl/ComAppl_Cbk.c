///*
// * ComAppl_Cbk.c
// *
// *  Created on: 2019年11月10日
// *      Author: zhangyun
// */
//
//#include "Dem.h"
//#include "ComAppl_Cbk.h"
//#include "Com_PBCfg.h"
//#include "ComStack_Flags.h"
//#include "ComAppl_CheckSumLib.h"
//
//
//static uint8 ComStack_BufferRxAliveCounter_VCU_DC01=0;
//static uint8 ComStack_BufferTxAliveCounter_DC01=0;
//
//#define COM_START_SEC_CODE
//#include "Com_MemMap.h"
//
///*
//
//#define ComConf_ComIPdu_VCU_DC01_Can_Network_CANNODE_0 0
//#define ComConf_ComIPdu_VCU_DC02_Can_Network_CANNODE_0 1
//
//
//#define DemConf_DemEventParameter_Event_VCU_DC01_AliveCounter        9u
//#define DemConf_DemEventParameter_Event_VCU_DC01_CheckSum            10u
//#define DemConf_DemEventParameter_Event_VCU_DC01_DLC                 11u
//#define DemConf_DemEventParameter_Event_VCU_DC01_Tiout               12u
//
//
//
//*/
//
//FUNC(boolean,COM_CODE) Com_RxCbk_VCU_DC01(VAR(PduIdType, AUTOMATIC) id, P2CONST(uint8, AUTOMATIC, COM_APPL_CONST) ptr)
//{
//	uint32 transferData_Producer;
//	boolean isPduValid = TRUE;
//	transferData_Producer =ComStack_TransferData_Producer_au8[ComConf_ComIPdu_VCU_DC01_Can_Network_CANNODE_0];
//	transferData_Producer++;
//	Dem_ReportErrorStatus(DemConf_DemEventParameter_Event_VCU_DC01_Tiout,DEM_EVENT_STATUS_PASSED);
//	Dem_ReportErrorStatus(DemConf_DemEventParameter_Event_VCU_DC01_DLC,DEM_EVENT_STATUS_PASSED);
//	/*Evaluate Checksum*/
//	{
//		uint8 rxCheckSum;
//		uint8 expectCheckSum;
//		rxCheckSum=ComAppl_UnPackSignal(ptr,63,8,FALSE,8);
//		expectCheckSum=rxCheckSum;
//		if(ComAppl_EvalChk_Add8(ptr,8,63,8,&expectCheckSum))
//		{
//			Dem_ReportErrorStatus(DemConf_DemEventParameter_Event_VCU_DC01_CheckSum,DEM_EVENT_STATUS_PASSED);
//		}
//		else
//		{
//			Dem_ReportErrorStatus(DemConf_DemEventParameter_Event_VCU_DC01_CheckSum,DEM_EVENT_STATUS_PREFAILED);
//			isPduValid=FALSE;
//		}
//    }
//	if(isPduValid)
//	{
//		uint8 aliveCounter =0;
//		aliveCounter=ComAppl_UnPackSignal(ptr,51,4,FALSE,8);
//		if(ComAppl_EvalAc_Std(aliveCounter,ComStack_BufferRxAliveCounter_VCU_DC01))
//		{
//			Dem_ReportErrorStatus(DemConf_DemEventParameter_Event_VCU_DC01_AliveCounter,DEM_EVENT_STATUS_PASSED);
//		}
//		else
//		{
//			Dem_ReportErrorStatus(DemConf_DemEventParameter_Event_VCU_DC01_AliveCounter,DEM_EVENT_STATUS_PREFAILED);
//		}
//		ComStack_BufferRxAliveCounter_VCU_DC01=aliveCounter;
//	}
//
//	return TRUE;
//}
//
//FUNC(void,COM_CODE) Com_TimeoutCbk_VCU_DC01(void)
//{
//	Dem_ReportErrorStatus(DemConf_DemEventParameter_Event_VCU_DC01_Tiout,DEM_EVENT_STATUS_PREFAILED);
//}
//FUNC(void,COM_CODE) Com_TimeoutCbk_VCU_DC02(void)
//{
//
//}
//
//FUNC(boolean,COM_CODE) Com_TxCbk_DC01(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
//{
//   	{
//		uint8 aliveCounter=0;
//		aliveCounter=ComAppl_GenAc_Std(ComStack_BufferTxAliveCounter_DC01);
//		ComAppl_PackSignal(ptr,aliveCounter,51,4,FALSE,8);
//		ComStack_BufferTxAliveCounter_DC01=aliveCounter;
//	}
//
//	{
//		uint8 checksum =0;
//		checksum = ComAppl_GenChk_Add8(ptr,8,63,8);
//		ComAppl_PackSignal(ptr,checksum,63,8,FALSE,8);
//	}
//
//	(void) id;
//    return TRUE;
//}
//
//
//#define COM_STOP_SEC_CODE
//#include "Com_MemMap.h"
//
//
//
//
//
///******************************************************************/
//
///*************Error Notification for Rx Ipdus *****************/
//
///* Start: ComErrorNotification For Ipdu's */
//
//
//#define COM_START_SEC_CODE
//#include "Com_MemMap.h"
//
//#define COM_STOP_SEC_CODE
//#include "Com_MemMap.h"
//
//#define COM_START_SEC_CODE
//#include "Com_MemMap.h"
//
//#define COM_STOP_SEC_CODE
//#include "Com_MemMap.h"

#include "Com_Priv.h"
#include "Com_Cbk.h"
//#include "ComSig.h"
#include "CddSBL_Jump.h"
#include "Snapshot_Can_PBCfg.h"
#include "ComAppl_Cbk.h"

uint8 VAR_flgRecBMS01_u8;
uint8 VAR_flgRecVCU01_u8;
uint8 VAR_flgRecVCU02_u8;
uint8 VAR_flgRecVCU03_u8;
uint8 VAR_flgRecVCU04_u8;
uint8 VAR_flgRecVCU05_u8;
uint8 VAR_flgRecVCU06_u8;
uint8 VAR_flgRecVCU07_u8;

uint8 VAR_ComRecNmFlag_u8;

FUNC(boolean,COM_CODE) Com_TxCallout_DIAG_01_Can_Network_1_CANNODE_0(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    *(ptr++) = SnapshotCan_DefConfigType_S.TxRamInfoPtr->InfoBuffer[0];
    *(ptr++) = SnapshotCan_DefConfigType_S.TxRamInfoPtr->InfoBuffer[1];
    *(ptr++) = SnapshotCan_DefConfigType_S.TxRamInfoPtr->InfoBuffer[2];
    *(ptr++) = SnapshotCan_DefConfigType_S.TxRamInfoPtr->InfoBuffer[3];
    *(ptr++) = SnapshotCan_DefConfigType_S.TxRamInfoPtr->InfoBuffer[4];
    *(ptr++) = SnapshotCan_DefConfigType_S.TxRamInfoPtr->InfoBuffer[5];
    *(ptr++) = SnapshotCan_DefConfigType_S.TxRamInfoPtr->InfoBuffer[6];
    *ptr = SnapshotCan_DefConfigType_S.TxRamInfoPtr->InfoBuffer[7];

    SnapshotCan_TransmitDisable(&SnapshotCan_DefConfigType_S.TxRamInfoPtr->TxCom);
	return 1;
}

FUNC(boolean,COM_CODE) Com_TxCallout_SysBoot_Tx_Can_Network_1_CANNODE_0(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
	*(ptr++) = CddSBL_DefRamInfo_S.TxBuffer[0];
	*(ptr++) = CddSBL_DefRamInfo_S.TxBuffer[1];
	*(ptr++) = CddSBL_DefRamInfo_S.TxBuffer[2];
	*(ptr++) = CddSBL_DefRamInfo_S.TxBuffer[3];
	*(ptr++) = CddSBL_DefRamInfo_S.TxBuffer[4];
	*(ptr++) = CddSBL_DefRamInfo_S.TxBuffer[5];
	*(ptr++) = CddSBL_DefRamInfo_S.TxBuffer[6];
	*ptr = CddSBL_DefRamInfo_S.TxBuffer[7];

	CddSBL_Jump_TransmitDisable(&CddSBL_DefRamInfo_S);

	return 1;
}


FUNC(boolean,COM_CODE) SysBoot_SysBoot_Rx_Can_Network_1_CANNODE_0(VAR(PduIdType, AUTOMATIC) id, P2CONST(uint8, AUTOMATIC, COM_APPL_CONST) ptr)/*ID不用管；P2CONST(uint8, AUTOMATIC, COM_APPL_CONST) ptr对应数据*/
{
    CddSBL_DefRamInfo_S.RxBuffer[0] = *(ptr++);
    CddSBL_DefRamInfo_S.RxBuffer[1] = *(ptr++);
    CddSBL_DefRamInfo_S.RxBuffer[2] = *(ptr++);
    CddSBL_DefRamInfo_S.RxBuffer[3] = *(ptr++);
    CddSBL_DefRamInfo_S.RxBuffer[4] = *(ptr++);
    CddSBL_DefRamInfo_S.RxBuffer[5] = *(ptr++);
    CddSBL_DefRamInfo_S.RxBuffer[6] = *(ptr++);
    CddSBL_DefRamInfo_S.RxBuffer[7] = *ptr;

	return 1;
}


FUNC(boolean,COM_CODE) Com_RxCallout_TOOL_01_Can_Network_1_CANNODE_0(VAR(PduIdType, AUTOMATIC) id, P2CONST(uint8, AUTOMATIC, COM_APPL_CONST) ptr)
{
    SnapshotCan_DefConfigType_S.RxRamInfoPtr->InfoBuffer[0] = *(ptr++);
    SnapshotCan_DefConfigType_S.RxRamInfoPtr->InfoBuffer[1] = *(ptr++);
    SnapshotCan_DefConfigType_S.RxRamInfoPtr->InfoBuffer[2] = *(ptr++);
    SnapshotCan_DefConfigType_S.RxRamInfoPtr->InfoBuffer[3] = *(ptr++);
    SnapshotCan_DefConfigType_S.RxRamInfoPtr->InfoBuffer[4] = *(ptr++);
    SnapshotCan_DefConfigType_S.RxRamInfoPtr->InfoBuffer[5] = *(ptr++);
    SnapshotCan_DefConfigType_S.RxRamInfoPtr->InfoBuffer[6] = *(ptr++);
    SnapshotCan_DefConfigType_S.RxRamInfoPtr->InfoBuffer[7] = *ptr;
	return TRUE;
}


FUNC(boolean,COM_CODE) Com_RxCallout_BMS_01_Can_Network_0_CANNODE_0(VAR(PduIdType, AUTOMATIC) id, P2CONST(uint8, AUTOMATIC, COM_APPL_CONST) ptr)
{
	VAR_flgRecBMS01_u8 = 1;
	return 1;
}
FUNC(boolean,COM_CODE) Com_RxCallout_VCU_01_Can_Network_0_CANNODE_0(VAR(PduIdType, AUTOMATIC) id, P2CONST(uint8, AUTOMATIC, COM_APPL_CONST) ptr)
{
	VAR_flgRecVCU01_u8 =1 ;
	return 1;
}

FUNC(boolean,COM_CODE) Com_RxCallout_VCU_02_Can_Network_0_CANNODE_0(VAR(PduIdType, AUTOMATIC) id, P2CONST(uint8, AUTOMATIC, COM_APPL_CONST) ptr)
{
	VAR_flgRecVCU02_u8 = 1;
	return 1;
}

FUNC(boolean,COM_CODE) Com_RxCallout_VCU_03_Can_Network_0_CANNODE_0(VAR(PduIdType, AUTOMATIC) id, P2CONST(uint8, AUTOMATIC, COM_APPL_CONST) ptr)
{
	VAR_flgRecVCU03_u8 =1 ;
	return 1;
}

FUNC(boolean,COM_CODE) Com_RxCallout_VCU_04_Can_Network_0_CANNODE_0(VAR(PduIdType, AUTOMATIC) id, P2CONST(uint8, AUTOMATIC, COM_APPL_CONST) ptr)
{
	VAR_flgRecVCU04_u8 =1 ;
	return 1;
}

FUNC(boolean,COM_CODE) Com_RxCallout_VCU_05_Can_Network_0_CANNODE_0(VAR(PduIdType, AUTOMATIC) id, P2CONST(uint8, AUTOMATIC, COM_APPL_CONST) ptr)
{
	VAR_flgRecVCU05_u8 =1 ;
	return 1;
}

FUNC(boolean,COM_CODE) Com_RxCallout_VCU_06_Can_Network_0_CANNODE_0(VAR(PduIdType, AUTOMATIC) id, P2CONST(uint8, AUTOMATIC, COM_APPL_CONST) ptr)
{
	VAR_flgRecVCU06_u8 =1 ;
	return 1;
}

FUNC(boolean,COM_CODE) Com_RxCallout_VCU_07_Mask_Can_Network_0_CANNODE_0(VAR(PduIdType, AUTOMATIC) id, P2CONST(uint8, AUTOMATIC, COM_APPL_CONST) ptr)
{
	VAR_flgRecVCU07_u8 =1 ;
	return 1;
}

void SetCanWakeUpflg(void)
{
    if(VAR_flgRecBMS01_u8||VAR_flgRecVCU01_u8||VAR_flgRecVCU02_u8||VAR_flgRecVCU03_u8||VAR_flgRecVCU04_u8||VAR_flgRecVCU05_u8||VAR_flgRecVCU06_u8||VAR_flgRecVCU07_u8)
    {
    	VAR_ComRecNmFlag_u8 = 1;
    }
    else
    {
    	VAR_ComRecNmFlag_u8 = 0;
    }
    VAR_flgRecBMS01_u8 = 0;
    VAR_flgRecVCU01_u8 = 0;
    VAR_flgRecVCU02_u8 = 0;
    VAR_flgRecVCU03_u8 = 0;
    VAR_flgRecVCU04_u8 = 0;
    VAR_flgRecVCU05_u8 = 0;
    VAR_flgRecVCU06_u8 = 0;
    VAR_flgRecVCU07_u8 = 0;
}
