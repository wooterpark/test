
/*******************************************************************************
**----------------------------------------------------------------------------**
** Copyright (c) 2021 by JEE.		All rights reserved.
** This software is copyright protected and proprietary to JEE.
** JEE grants to you only those rights as set out in the license conditions.
** All other rights remain with JEE.
**----------------------------------------------------------------------------**
**
* Administrative Information
* $Namespace_: \xx\xx$
* $Class_____: C$
* $Name______: Rdc_FS.h$
* $Variant___: 0.0.0$
* $Revision__: 0$
* $Author____: ZhangYang$
**
**----------------------------------------------------------------------------**
** MAY BE CHANGED BY USER [Yes/No]: No
**----------------------------------------------------------------------------**
** DESCRIPTION:
				Function Safety Level2 Communication.
**----------------------------------------------------------------------------**
** HISTORY:
V1.0.0:   initial version  2021/12/25

*******************************************************************************/

/*******************************************************************************
**                      Other Header File Inclusion                           **
*******************************************************************************/
#include "L2COM_FS.h"
#include "Com_Priv.h"
#include "Com_Cbk.h"
/*******************************************************************************
**                          Macro Definition                         		  **
*******************************************************************************/



/*******************************************************************************
**                          Typedef Definition                         		  **
*******************************************************************************/


/*******************************************************************************
**                   Static Local Variables Definition              		  **
*******************************************************************************/

static uint8 ComStack_BufferTxAliveCounter_MCU_0x430;

/*******************************************************************************
**                     Global Variables Definition              		      **
*******************************************************************************/

uint8 VAR_RollCntRx_MCU_430_u8;
uint8 VAR_CheckSumTx_MCU_430_u8;
uint16 VAR_TCF_FSEstTrq_u16;
uint32 VAR_FRP_AppFaultInfo_u32;
uint32 VAR_FS_BswFaultInfo_u32;

/*******************************************************************************
**                  Static Local Function Declaration            		      **
*******************************************************************************/

/*******************************************************************************
**                 		  Function Source Code            		              **
*******************************************************************************/
void FS_FltInfoCom_Report(void)
{
	uint8 sendstate01;
	uint8 sendstate02;
	uint8 sendstate03;
	uint8 sendstate04;

	uint16 PEB07_MaxDynTrq;
	uint16 PEB07_MaxPredTrq;
	uint16 PEB07_MinDynTrq;
	uint16 PEB07_MinDynTrq_AppFlt;
	uint16 PEB07_MinDynTrq_BswFlt;
	uint16 PEB07_MinPredTrq;

	VAR_FRP_AppFaultInfo_u32=get_FRP_L2FaultinfoOut();

//	VAR_FS_BswFaultInfo_u32=get_FS_BswFaultinfoOut();

	VAR_TCF_FSEstTrq_u16=(uint16)(get_TCF_BlendTrq()+ 512.000000);

	PEB07_MaxDynTrq=(uint16)(VAR_FRP_AppFaultInfo_u32&0x3ffu);
	PEB07_MaxPredTrq=(uint16)((VAR_FRP_AppFaultInfo_u32>>10)&0x3ffu);
	PEB07_MinDynTrq_AppFlt=(uint16)((VAR_FRP_AppFaultInfo_u32>>20)&0x1u);
	PEB07_MinDynTrq_BswFlt=(uint16)((VAR_FS_BswFaultInfo_u32)&0x1ffu);
	PEB07_MinDynTrq=(PEB07_MinDynTrq_BswFlt<< 1)|PEB07_MinDynTrq_AppFlt;
	PEB07_MinPredTrq=VAR_TCF_FSEstTrq_u16;

	sendstate01=Com_SendSignal(((VAR(Com_SignalIdType, AUTOMATIC))66), &PEB07_MaxDynTrq );
	sendstate02=Com_SendSignal(((VAR(Com_SignalIdType, AUTOMATIC))65), &PEB07_MaxPredTrq);
	sendstate03=Com_SendSignal(((VAR(Com_SignalIdType, AUTOMATIC))64), &PEB07_MinDynTrq);
	sendstate04=Com_SendSignal(((VAR(Com_SignalIdType, AUTOMATIC))63), &PEB07_MinPredTrq);
}

/*******************************************************************************
** Function Name	: Com_Callout_PEB07_0x430_Can_Network_0_CANNODE_0
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: Function Safety e2e callout function.
*******************************************************************************/


FUNC(boolean,COM_CODE) Com_Callout_PEB07_0x430_Can_Network_0_CANNODE_0(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
	static uint8 PDU_0x430_Send_Delay_count=0;
	static uint8 PDU_0x430_Send_Start_Flg=0;
	if(PDU_0x430_Send_Start_Flg==0)
	{
		PDU_0x430_Send_Delay_count++;
		if(PDU_0x430_Send_Delay_count==2)
		{
			PDU_0x430_Send_Start_Flg=1;
		}
	}
	else
	{
		{
			uint8 aliveCounter=0;
			aliveCounter=ComAppl_GenAc_Std(ComStack_BufferTxAliveCounter_MCU_0x430);
			ComAppl_PackSignal(ptr,aliveCounter,48,4,TRUE,8);
			VAR_RollCntRx_MCU_430_u8 = aliveCounter;
			ComStack_BufferTxAliveCounter_MCU_0x430=aliveCounter;
		}
		{
			uint8 checksum =0;
			checksum =Com_CRC(ptr);
			VAR_CheckSumTx_MCU_430_u8 = checksum;
			ComAppl_PackSignal(ptr,checksum,56,8,TRUE,8);
		}
		(void) id;
		return TRUE;
	}
}

