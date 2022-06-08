/*******************************************************************************
**----------------------------------------------------------------------------**
** Copyright (c) 2019 by Jee.		All rights reserved.
** This software is copyright protected and proprietary to Jee.
** JEE grants to you only those rights as set out in the license conditions.
** All other rights remain with Jee.
**----------------------------------------------------------------------------**
**
* Administrative Information
* $Namespace_: \Prv\IgbtDrv$
* $Class_____: C$
* $Name______: IgbtDrv.c$
* $Variant___: 0.0.0$
* $Revision__: 0$
* $Author____: LQ$
**
**----------------------------------------------------------------------------**
** MAY BE CHANGED BY USER [Yes/No]: No
**----------------------------------------------------------------------------**
** DESCRIPTION:
** 1EDI2002AS Driver
*******************************************************************************
* $History__:$
* V0.0.0      2019.10.03 		LQ
*  N: new created
*******************************************************************************/


/*******************************************************************************
**                      Other Header File Inclusion                           **
*******************************************************************************/
#include "IgbtDrv.h"
/*******************************************************************************
**                          Macro Definition                         		  **
*******************************************************************************/
#define IGBTDRV_REGCFG_NUM(Array)		   sizeof(Array) / sizeof((Array)[0u])

#define IGBTDRV_DIAG_THRSEHOLD            50u

#define PRV_IGBTDRV_RESETCHIP_STEP1       0u
#define PRV_IGBTDRV_RESETCHIP_STEP2       1u
#define PRV_IGBTDRV_RESETCHIP_FINSIH      0u

#define PRV_PCTRL_CLRP_CLRS 			(uint16)3
#define PRV_PCTRL_BITSPOS 				(uint16)5

#define PRV_PRW_VALUE  					(uint16)0xABCC
#define PRV_PSTAT2_BITSPOS 				(uint16)5
#define PRV_PSTAT2_BITSMASK 			(uint16)7
/*******************************************************************************
**                          Typedef Definition                         		  **
*******************************************************************************/
typedef struct
{
	uint8	ModuleFSMWatch_au8[4u];
	uint8  	InitSeqStepFSMWatch_au8[10u];
	uint8 	InitCheckSeqStepFSMWatch_au8[8u];
	uint8	RunTimeStepFSMWatch_au8[3u];
	uint8	ErrorHandlingFSMWatch_au8[5u];
	uint32  Fsm_IdleCount_u32;
	uint32  Fsm_10msCount_u32;
} IgbtDrv_FSM_WatchType;


typedef struct
{
	uint8	ASYspiTxOnce;
	uint8  	ModeCtrlTxFinish_u8;
	uint8	Reg8CfgTxFinish_u8;
	uint8 	Reg16CfgTxFinish_u8;
	uint8   RegReadTxFinish_u8;
	uint8	ReadStatusRegsTxFinish_u8;
	uint8   ReadConfRegsTxFinish_u8;
} IgbtDrv_NotifConfirmType;

typedef struct  {
   /* Inter-runnable variable handles */
   uint8 * Irv_RE_SWC_IgbtDrv_1ms_IVDP_State;
   uint8 * Irv_RE_SWC_IgbtDrv_10ms_IVDP_State;

} Rte_IgbtDrv_InterType ;

/*******************************************************************************
**                   Static Local Variables Definition              		  **
*******************************************************************************/
#pragma section ".data.CPU1_32"
static IgbtDrv_RegStatusType   *Prv_IgbtDrv_RegStatus_pst;
static IgbtDrv_RegStatusType   *Prv_IgbtDrv_RegConf_pst;
static const IgbtDrv_RegCfgType *Prv_IgbtDrv_RegCfg_pst;
static IgbtDrv_FSM_WatchType Prv_Debug_FsmWatch_st;

static uint8 Prv_IgbtDrvDiagCnt = 0u;

static uint16  Prv_IgbtDrv_SpiRxBuff_Reg[IGBTDRV_NUM_OF_CHIPS];

static uint16  Prv_IgbtDrv_SpiTxBuff_RegForRead[IGBTDRV_NUM_OF_Seq0][IGBTDRV_NUM_OF_CHIPS];
#if 0u
static uint16  Prv_IgbtDrv_SpiRxBuff_RegForRead[IGBTDRV_NUM_OF_Seq0][IGBTDRV_NUM_OF_CHIPS];
#endif
static uint16  Prv_IgbtDrv_SpiTxBuff_RegForRdConf[IGBTDRV_NUM_OF_SeqRdConf][IGBTDRV_NUM_OF_CHIPS];
#if 0u
static uint16  Prv_IgbtDrv_SpiRxBuff_RegForRdConf[IGBTDRV_NUM_OF_SeqRdConf][IGBTDRV_NUM_OF_CHIPS];
#endif


static uint16  Prv_SpiRxBuffReadOneReg_L[32u][IGBTDRV_NUM_OF_CHIPS];
static IgbtDrvErrType VAR_IgbtDrv_Det_ReportError_u8;
static IgbtDrv_ChipOpm VAR_IgbtDrv_ChipOpm_en[IGBTDRV_NUM_OF_CHIPS];
uint8 VAR_Igbt_Normal_State_u16;

#pragma section

/*******************************************************************************
**                     Global Variables Definition              		      **
*******************************************************************************/
uint8 IgbtDrv_AppCtrlCmd_u8 ;
uint8 IgbtDrv_AppWorkReady_u8 ;
uint8 IgbtDrv_AppFaultType_u8 ;

Dio_LevelType  VAR_IgbtDrv_Level_NRST_RDY_u8, VAR_IgbtDrv_Level_NRST_RDY_L_u8;
Dio_LevelType  VAR_IgbtDrv_Level_NFLTA_u8, VAR_IgbtDrv_Level_NFLTA_L_u8;		/*1 normal; 0 fault  */
Dio_LevelType  VAR_IgbtDrv_Level_NFLTB_u8, VAR_IgbtDrv_Level_NFLTB_L_u8;


/******************************************************    Inter-runnable  ****************************************************/
static uint8 Rte_Var_CPT_IgbtDrv_1ms_IVDP_State;
static uint8 Rte_Var_CPT_IgbtDrv_10ms_IVDP_State;
static const Rte_IgbtDrv_InterType Rte_Inst_IgbtDrv =
{
	 /* Inter-runnable variable handles */
	   &Rte_Var_CPT_IgbtDrv_1ms_IVDP_State,
	   &Rte_Var_CPT_IgbtDrv_10ms_IVDP_State,
};

#define Rte_IrvIWrite_RE_IgbtDrv_1ms_IVDP_State(data)     ( (*Rte_Inst_IgbtDrv.Irv_RE_SWC_IgbtDrv_1ms_IVDP_State) = (data) )
#define Rte_IrvIRead_RE_IgbtDrv_10ms_IVDP_State()         (*Rte_Inst_IgbtDrv.Irv_RE_SWC_IgbtDrv_10ms_IVDP_State)
/********************************************************************************************************************************/


/*******************************************************************************
**                  Static Local Function Declaration            		      **
*******************************************************************************/
static void Prv_IgbtDrv_Det_ReportError( IgbtDrvErrType ErrorId );
static void Prv_IgbtDrv_Diag_Handle(IgbtDrv_FSM_ErrorHandlingModeType FsmErrorMode, IgbtDrvErrType ErrorID );
static void Prv_IgbtDrv_Diag_Init( void);
static  uint16 Prv_IgbtDrv_GetDataWithParity(uint16 data );
static void Prv_IgbtDrv_InitTxBuff(void) ;
static void Prv_GetRegisterStatus( boolean isSync );
static void Prv_GetPinStaus( void );
static void Prv_IgbtDrv_ReadConfRegs(boolean isSync);
static void Prv_IgbtDrv_ChipReset( void) ;
static void Prv_IgbtDrv_ChipNormal( void );
static uint8 Prv_ReadChipReadyStatus( void );
static void Prv_IgbtDrv_GetCurrOpm_Again( void );
static void Prv_IgbtDrv_GetRegisterValue_Loop(void );
static boolean Prv_IgbtDrv_IsOpmExpected( IgbtDrv_ChipOpm refOpm );
static uint8 Prv_FsmOpmCheck( IgbtDrv_ChipOpm opm );
static void Prv_IgbtDrv_ModeCtrl( uint16 modeCmd, boolean isSync );
static uint8 Prv_FsmModeCtrl( uint16 modeCmd  );
static void Prv_IgbtDrv_ReadOneReg( uint16 addr, boolean isSync);
static void Prv_IgbtDrv_ClrError( boolean isSync);
static uint8 Prv_FsmClrError( void );
static boolean Prv_IgbtDrv_IsSRDYExpected( void );
static boolean Prv_IgbtDrv_IsErrOccur( void );
static boolean Prv_IgbtDrv_IsActOPM4( void );
static boolean Prv_IgbtDrv_IsSCFGCorrect(void);

/*IgbtDrv Machine*/
static void Prv_IgbtDrv_InitSeq(void);
static void Prv_IgbtDrv_InitCheckSeq(void);
static void Prv_IgbtDrv_RunTimeOperation(void);
static void Prv_IgbtDrv_ErrorHandling(void);

/*Prv_IgbtDrv_InitSeq Submachine*/
static void Prv_ResetChip_InitSeqStep0(void);
static void Prv_ReadPrimaryReadyStatus_InitSeqStep1(void);
static void Prv_CheckPrimaryStatus_InitSeqStep2(void);
static void Prv_ReadSecondaryReadyStatus_InitSeqStep3(void);
static void Prv_ClearFlags_InitSeqStep4(void);
static void Prv_CheckDeviceID_InitSeqStep5(void);
static void Prv_EnterConfigMode_InitSeqStep6(void);
static void Prv_VerifyOPM2_InitSeqStep7(void);
static void Prv_ConfigDevice_InitSeqStep8(void);
static void Prv_SystemTest_InitSeqStep9(void);

/*Prv_IgbtDrv_InitCheckSeq Submachine*/
static void Prv_ExitConfigMode_InitCheckSeqStep1(void);
static void Prv_VerifyOPM3_InitCheckSeqStep2(void);
static void Prv_VerifyConfig_InitCheckSeqStep3(void);
static void Prv_ConfigurationJudge_InitCheckSeqStep4(void);
static void Prv_CheckDeviceStatus_InitCheckSeqStep5(void);
static void Prv_VerifyStatus_InitCheckSeqStep6(void);
static void Prv_ClearFlags_InitCheckSeqStep7(void);
static void Prv_GotoOPM4_InitCheckSeqStep8(void);

/*Prv_IgbtDrv_RunTimeOperation Submachine*/
static void Prv_CheckPrimaryStatus_RunTimeStep1(void);
static void Prv_VerifyStatus_RunTimeStep2(void);
static void Prv_RuntimeErrorDetected_RunTimeStep3(void);

static void Prv_IgbtDrvFsmReset(uint8* ctrlCmd_u8);

/*Prv_IgbtDrv_ErrorHandling Submachine*/
static void Prv_HandlingLMIErrors(void);
static void Prv_HandlingInitErrors(void);
static void Prv_HandlingEventsClassAErrors(void);
static void Prv_HandlingEventsClassBErrors(void);
static void Prv_HandlingRuntimeError(void);


/*******************************************************************************
**                 		  configuration Data           		              **
*******************************************************************************/
static IgbtDrv_NotifConfirmType Prv_NotifConfirm_st =
{
	0,
	0,
	1,
	1,
	0,
	0,
	0,
};
  /*JEE_MISRA_RULE_8_09 It's allowed .*/
static const Spi_ChannelType Prv_IgbtDrv_Seq0ChannelSet[IGBTDRV_NUM_OF_Seq0]=
{
		SpiConf_SpiChannel_SpiChannel_WrH_PRW,
		SpiConf_SpiChannel_SpiChannel_WrL_PRW,
		SpiConf_SpiChannel_SpiChannel_Rd_PSTAT,
		SpiConf_SpiChannel_SpiChannel_Rd_PSTAT2,
		SpiConf_SpiChannel_SpiChannel_Rd_PER,
		SpiConf_SpiChannel_SpiChannel_Rd_SSTAT,
		SpiConf_SpiChannel_SpiChannel_Rd_SSTAT2,
		SpiConf_SpiChannel_SpiChannel_Rd_SER,
		SpiConf_SpiChannel_SpiChannel_Rd_SGM1,
		SpiConf_SpiChannel_SpiChannel_Rd_SGM2,
		SpiConf_SpiChannel_SpiChannel_Rd_PCTRL,
		SpiConf_SpiChannel_SpiChannel_Rd_PCTRL2,
		SpiConf_SpiChannel_SpiChannel_Rd_PRW,
		SpiConf_SpiChannel_SpiChannel_Nop
};
/*JEE_MISRA_RULE_8_09 It's allowed .*/
static const Spi_ChannelType Prv_IgbtDrv_RdConfChannelSet[IGBTDRV_NUM_OF_SeqRdConf]=
{
		SpiConf_SpiChannel_SpiChannel_PCFG,
		SpiConf_SpiChannel_SpiChannel_PCFG2,
		SpiConf_SpiChannel_SpiChannel_PCTRL,
		SpiConf_SpiChannel_SpiChannel_PCTRL2,
		SpiConf_SpiChannel_SpiChannel_PSCR,
		SpiConf_SpiChannel_SpiChannel_PRW,
		SpiConf_SpiChannel_SpiChannel_SCFG,
		SpiConf_SpiChannel_SpiChannel_SCFG2,
		SpiConf_SpiChannel_SpiChannel_SCTRL,
		SpiConf_SpiChannel_SpiChannel_SSCR,
		SpiConf_SpiChannel_SpiChannel_SDESAT,
		SpiConf_SpiChannel_SpiChannel_SOCP,
		SpiConf_SpiChannel_SpiChannel_SRTTOF,
		SpiConf_SpiChannel_SpiChannel_SSTTOF,
		SpiConf_SpiChannel_SpiChannel_SACLT,
		SpiConf_SpiChannel_SpiChannel_CONF_Nop
};
/*Address of configuration registers*/
static const uint8 Prv_IgbtDrv_ConfRegTable[IGBTDRV_NUM_OF_SeqRdConf-1u]=
{
		IGBTDRV_REG_PCFG,
		IGBTDRV_REG_PCFG2,
		IGBTDRV_REG_PCTRL,
		IGBTDRV_REG_PCTRL2,
		IGBTDRV_REG_PSCR,
		IGBTDRV_REG_PRW,
		IGBTDRV_REG_SCFG,
		IGBTDRV_REG_SCFG2,
		IGBTDRV_REG_SCTRL,
		IGBTDRV_REG_SSCR,
		IGBTDRV_REG_SDESAT,
		IGBTDRV_REG_SOCP,
		IGBTDRV_REG_SRTTOF,
		IGBTDRV_REG_SSTTOF,
		IGBTDRV_REG_SACLT,

};

/*initialize   Prv_IgbtDrv_FSM_RamParam_st*/
static IgbtDrv_FSM_RamParamType Prv_IgbtDrv_FSM_RamParam_st =
{
	InitSeqMode,
	ResetChipMode,
	ExitConfigModeMode,
	CheckPrimaryStatus2Mode,
	LMIErrMode,
};


/*initialize  Prv_IgbtDrv_FSM_FlsParam_st*/
static const  IgbtDrv_FSM_FlsParamType Prv_IgbtDrv_FSM_FlsParam_st =
{
	/*IgbtDrv Machine*/
	{
		Prv_IgbtDrv_InitSeq,
		Prv_IgbtDrv_InitCheckSeq,
		Prv_IgbtDrv_RunTimeOperation,
		Prv_IgbtDrv_ErrorHandling,
	},
	/*Prv_IgbtDrv_InitSeq Submachine*/
	{
		Prv_ResetChip_InitSeqStep0,
		Prv_ReadPrimaryReadyStatus_InitSeqStep1,
		Prv_CheckPrimaryStatus_InitSeqStep2,
		Prv_ReadSecondaryReadyStatus_InitSeqStep3,
		Prv_ClearFlags_InitSeqStep4,
		Prv_CheckDeviceID_InitSeqStep5,
		Prv_EnterConfigMode_InitSeqStep6,
		Prv_VerifyOPM2_InitSeqStep7,
		Prv_ConfigDevice_InitSeqStep8,
		Prv_SystemTest_InitSeqStep9
	},
	/*Prv_IgbtDrv_InitCheckSeq Submachine*/
	{
		Prv_ExitConfigMode_InitCheckSeqStep1,
		Prv_VerifyOPM3_InitCheckSeqStep2,
		Prv_VerifyConfig_InitCheckSeqStep3,
		Prv_ConfigurationJudge_InitCheckSeqStep4,
		Prv_CheckDeviceStatus_InitCheckSeqStep5,
		Prv_VerifyStatus_InitCheckSeqStep6,
		Prv_ClearFlags_InitCheckSeqStep7,
		Prv_GotoOPM4_InitCheckSeqStep8,

	},
	/*Prv_IgbtDrv_RunTimeOperation Submachine*/
	{
		Prv_CheckPrimaryStatus_RunTimeStep1,
		Prv_VerifyStatus_RunTimeStep2,
		Prv_RuntimeErrorDetected_RunTimeStep3,
	},
	/*Prv_IgbtDrv_ErrorHandling Submachine*/
	{
		Prv_HandlingLMIErrors,
		Prv_HandlingInitErrors,
		Prv_HandlingEventsClassAErrors,
		Prv_HandlingEventsClassBErrors,
		Prv_HandlingRuntimeError,
	},

};

/*******************************************************************************
**                 		  Function Source Code            		              **
*******************************************************************************/
/*******************************************************************************
** Function Name	: Prv_IgbtDrv_Det_ReportError
** Parameter[in] 	: ErrorId
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: ReportError
*******************************************************************************/
static void Prv_IgbtDrv_Det_ReportError( IgbtDrvErrType ErrorId)
{
	VAR_IgbtDrv_Det_ReportError_u8 = ErrorId;
}

/*******************************************************************************
** Function Name	: Prv_IgbtDrv_Diag_Init
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: Prv_IgbtDrvDiagCnt clear .
*******************************************************************************/
static void Prv_IgbtDrv_Diag_Init(void)
{
	Prv_IgbtDrvDiagCnt = 0u;
}

/*******************************************************************************
** Function Name	: Prv_IgbtDrv_Diag_Handle
** Parameter[in] 	: FsmErrorMode and ErrorID
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: diagnose handle
*******************************************************************************/
static void Prv_IgbtDrv_Diag_Handle(IgbtDrv_FSM_ErrorHandlingModeType FsmErrorMode, IgbtDrvErrType ErrorID)
{
	Prv_IgbtDrvDiagCnt++;

	if( Prv_IgbtDrvDiagCnt > IGBTDRV_DIAG_THRSEHOLD )
	{
		Prv_IgbtDrvDiagCnt = 0u;
		Prv_IgbtDrv_FSM_RamParam_st.Mode = ErrorHandlingMode;
		Prv_IgbtDrv_FSM_RamParam_st.ErrorHandlingMode = FsmErrorMode;
		Prv_IgbtDrv_Det_ReportError(ErrorID);
	}
}

/*******************************************************************************
** Function Name	: Prv_IgbtDrv_GetDataWithParity
** Parameter[in] 	: data
** Parameter[out] 	: None
** Return Value	  	: data
** Note	  			: None
** Description	  	: Get Data With Parity .
*******************************************************************************/
static uint16 Prv_IgbtDrv_GetDataWithParity(uint16 data)
{
	uint8 idx;
	uint16 tempdata = 0u;
    uint16 RetVal;
	for( idx=0u;idx<16u;idx++ )
	{
		tempdata += ( (data>>idx) & 0x0001u );
	}
	if( (tempdata & 0x0001u) == 0u )
	{
		RetVal = ( data|(uint16)1u );
	}
	else
	{
		RetVal = data;
	}
	return (RetVal);
}

/*******************************************************************************
** Function Name	: Prv_IgbtDrv_InitTxBuff
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: initialize SPI TxBuf.
*******************************************************************************/
static void Prv_IgbtDrv_InitTxBuff(void)
{
	uint8 idx, jdx;
	for( idx=0; idx < IGBTDRV_NUM_OF_CHIPS; idx++ )
	{
		/*Initialize PRW with ABCC*/
		Prv_IgbtDrv_SpiTxBuff_RegForRead[0u][idx] = Prv_IgbtDrv_GetDataWithParity( CMD_WRITEH_REQUEST(PRV_PRW_VALUE) );
		Prv_IgbtDrv_SpiTxBuff_RegForRead[1u][idx] = Prv_IgbtDrv_GetDataWithParity( CMD_WRITEL_REQUEST(IGBTDRV_REG_PRW,PRV_PRW_VALUE) );
		/*Fill the last buffer with NOP*/
		Prv_IgbtDrv_SpiTxBuff_RegForRead[IGBTDRV_NUM_OF_Seq0 - 1u][idx] = Prv_IgbtDrv_GetDataWithParity(CMD_NOP);

		/*Fill the last buffer with NOP*/
		Prv_IgbtDrv_SpiTxBuff_RegForRdConf[IGBTDRV_NUM_OF_SeqRdConf-1u][idx] = Prv_IgbtDrv_GetDataWithParity(CMD_NOP);

	}
	/*To fill the buffer with SPI read command for status registers and the last element is NOP.*/
	for( jdx = 2u;jdx < (IGBTDRV_NUM_OF_Seq0 - 1u); jdx++ )
	{
		for( idx=0; idx < IGBTDRV_NUM_OF_CHIPS; idx++ )
		{
			Prv_IgbtDrv_SpiTxBuff_RegForRead[jdx][idx] = Prv_IgbtDrv_GetDataWithParity( CMD_READ_REQUEST( Prv_IgbtDrv_RegStatus_pst[jdx-2u].Reg_ShortName ));

		}
	}
	/*To fill the buffer with SPI read command for configuration registers and the last element is NOP*/
	for( jdx=0; jdx<(IGBTDRV_NUM_OF_SeqRdConf-1u); jdx++ )
	{
		for(idx=0;idx<IGBTDRV_NUM_OF_CHIPS;idx++)
		{
			Prv_IgbtDrv_SpiTxBuff_RegForRdConf[jdx][idx] = Prv_IgbtDrv_GetDataWithParity( CMD_READ_REQUEST( Prv_IgbtDrv_RegConf_pst[jdx].Reg_ShortName));
		}
	}

}
/*******************************************************************************
** Function Name	: Prv_GetRegisterStatus
** Parameter[in] 	: isSync
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: Get SpiSequence_0 Register Status.
*******************************************************************************/
static void Prv_GetRegisterStatus( boolean isSync )
{
	uint8 chnId;
	static uint16 GetRegisterStatustxTemp[6];
	static uint16 timeStamp;
      /*JEE_MISRA_RULE_11_04 It's allowed .*/
	timeStamp = (uint16)(STM0_TIM0.U/100U); /*uS*/
	GetRegisterStatustxTemp[0] = (timeStamp << 2u);

	for( chnId=0;chnId<IGBTDRV_NUM_OF_CHIPS;chnId++ )
	{
		Prv_IgbtDrv_SpiTxBuff_RegForRead[0u][chnId] = Prv_IgbtDrv_GetDataWithParity(CMD_WRITEH_REQUEST(GetRegisterStatustxTemp[0]));
		Prv_IgbtDrv_SpiTxBuff_RegForRead[1u][chnId] = Prv_IgbtDrv_GetDataWithParity(CMD_WRITEL_REQUEST(IGBTDRV_REG_PRW,GetRegisterStatustxTemp[0]));
	}
	(void)Spi_SetupEB(Prv_IgbtDrv_Seq0ChannelSet[0u], (Spi_DataType*)(&Prv_IgbtDrv_SpiTxBuff_RegForRead[0u][0u]),\
					(Spi_DataType*)( &GetRegisterStatustxTemp[0] ), IGBTDRV_NUM_OF_CHIPS); /*Channel chnId*/
	(void)Spi_SetupEB(Prv_IgbtDrv_Seq0ChannelSet[1u], (Spi_DataType*)(&Prv_IgbtDrv_SpiTxBuff_RegForRead[1u][0u]),\
					(Spi_DataType*)( &GetRegisterStatustxTemp[0] ), IGBTDRV_NUM_OF_CHIPS); /*Channel chnId*/
	(void)Spi_SetupEB(Prv_IgbtDrv_Seq0ChannelSet[2u], (Spi_DataType*)(&Prv_IgbtDrv_SpiTxBuff_RegForRead[2u][0u]),\
					(Spi_DataType*)( &GetRegisterStatustxTemp[0] ), IGBTDRV_NUM_OF_CHIPS); /*Channel chnId*/
	/* Setup all channels */
	for( chnId = 3u; chnId<IGBTDRV_NUM_OF_Seq0;chnId++ )
	{
		(void)Spi_SetupEB(Prv_IgbtDrv_Seq0ChannelSet[chnId], (Spi_DataType*)(&Prv_IgbtDrv_SpiTxBuff_RegForRead[chnId][0]),\
				(Spi_DataType*)( &(Prv_IgbtDrv_RegStatus_pst[chnId-3u].Reg_Value[0u]) ), IGBTDRV_NUM_OF_CHIPS); /*Channel chnId*/
	}
	if( isSync == 1U )
	{
		(void)Spi_SyncTransmit(SpiConf_SpiSequence_SpiSequence_0);
	}
	else
	{
		(void)Spi_AsyncTransmit(SpiConf_SpiSequence_SpiSequence_0);
	}
}
/*******************************************************************************
** Function Name	: Prv_GetPinStaus
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: Get Rdy and Fault pin Status.
*******************************************************************************/
static void Prv_GetPinStaus( void )
{
	/*Read pin NRST/RDY states*/
	VAR_IgbtDrv_Level_NRST_RDY_u8   = Dio_ReadChannel(PIN_NRST_RDY_IN);
	VAR_IgbtDrv_Level_NRST_RDY_L_u8 = Dio_ReadChannel(PIN_NRST_RDY_L_IN);
	/*Read pin NFLTB states*/
	VAR_IgbtDrv_Level_NFLTB_u8      = Dio_ReadChannel(PIN_NFLTB_IN);
	VAR_IgbtDrv_Level_NFLTB_L_u8    = Dio_ReadChannel(PIN_NFLTB_L_IN);
	/*Read pin NFLTA states*/
	VAR_IgbtDrv_Level_NFLTA_u8      = Dio_ReadChannel(PIN_NFLTA_IN);
	VAR_IgbtDrv_Level_NFLTA_L_u8    = Dio_ReadChannel(PIN_NFLTA_L_IN);


}
/*******************************************************************************
** Function Name	: Prv_IgbtDrv_ReadConfRegs
** Parameter[in] 	: isSync
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: Read one Register Status.
*******************************************************************************/
static void Prv_IgbtDrv_ReadConfRegs( boolean isSync )
{
	uint8 chnId;
	static uint16 ReadConfRegstxTemp[6];

	/* First channels ,Note asynchronous Spi "Tx first,Rx Second "*/
	(void)Spi_SetupEB(Prv_IgbtDrv_RdConfChannelSet[0u], (Spi_DataType*)(&Prv_IgbtDrv_SpiTxBuff_RegForRdConf[0u][0u]), \
			(Spi_DataType*)( &ReadConfRegstxTemp[0] ), IGBTDRV_NUM_OF_CHIPS);

	/* Setup Only used channels */
	for( chnId = 1u; chnId < IGBTDRV_NUM_OF_SeqRdConf; chnId++ )
	{
		/* Note ,First Tx Prv_IgbtDrv_SpiTxBuff_RegForRdConf[0u][0u], Rx By Prv_IgbtDrv_RegConf_pst[0u].Reg_Value[0u]*/
		(void)Spi_SetupEB(Prv_IgbtDrv_RdConfChannelSet[chnId], (Spi_DataType*)(&Prv_IgbtDrv_SpiTxBuff_RegForRdConf[chnId][0]), \
				(Spi_DataType*)( &(Prv_IgbtDrv_RegConf_pst[chnId-1u].Reg_Value[0u]) ), IGBTDRV_NUM_OF_CHIPS);
	}
	if( isSync == 1U )
	{
		(void)Spi_SyncTransmit(SpiConf_SpiSequence_SpiSequence_CddIgbtDrv_RdConf);
	}
	else
	{
		(void)Spi_AsyncTransmit(SpiConf_SpiSequence_SpiSequence_CddIgbtDrv_RdConf);
	}
}
/*******************************************************************************
** Function Name	: Prv_IgbtDrv_ChipReset
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: 1ED2002as Reset.
*******************************************************************************/
static void Prv_IgbtDrv_ChipReset(void)
{
	Dio_WriteChannel(PIN_NRST_RDY, STD_LOW); 				/* High_side NRST/RDY pin for 1edi2002as */
	Dio_WriteChannel(PIN_NRST_RDY_L, STD_LOW);				/* Low_side  NRST/RDY pin for 1edi2002as */
}
/*******************************************************************************
** Function Name	: Prv_IgbtDrv_ChipNormal
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: 1ED2002as Normal.
*******************************************************************************/
static void Prv_IgbtDrv_ChipNormal(void)
{
	Dio_WriteChannel(PIN_NRST_RDY, STD_HIGH);
	Dio_WriteChannel(PIN_NRST_RDY_L, STD_HIGH);
}
/*******************************************************************************
** Function Name	: Prv_ReadChipReadyStatus
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: Read Rdy Pin status.
*******************************************************************************/
static uint8 Prv_ReadChipReadyStatus(void)
{
	uint8 valRDY_IN,valRDY_L_IN;
	uint8 val;

	valRDY_IN   = Dio_ReadChannel(PIN_NRST_RDY_IN);
	valRDY_L_IN = Dio_ReadChannel(PIN_NRST_RDY_L_IN);

	if( (valRDY_IN == 1u)&&(valRDY_L_IN == 1u) )
	{
		val = 1u;
	}
	else
	{
		val = 0u;
	}
	return val;
}
/*******************************************************************************
** Function Name	: Prv_IgbtDrv_GetCurrOpm_Again
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: Get Current Opm.
*******************************************************************************/
static void Prv_IgbtDrv_GetCurrOpm_Again(void )
{
	uint8 idx;
	for( idx=0; idx<IGBTDRV_NUM_OF_CHIPS; idx++ )
	{
               /*JEE_MISRA_RULE_10_05 It's allowed .*/
		VAR_IgbtDrv_ChipOpm_en[idx] = (IgbtDrv_ChipOpm)( (uint16)(  ( (uint16)( PRV_PSTAT2_BITSMASK << PRV_PSTAT2_BITSPOS) & Prv_SpiRxBuffReadOneReg_L[IGBTDRV_REG_PSTAT2][idx] ) >> PRV_PSTAT2_BITSPOS  ) );
	}
}
/*******************************************************************************
** Function Name	: Prv_IgbtDrv_GetRegisterValue_Loop
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: Get Current Opm per 10ms when err State.
*******************************************************************************/
static void Prv_IgbtDrv_GetRegisterValue_Loop(void )
{
	uint8 idx;
	static uint16 VAR_IgbtDrv_RegPER_au16[IGBTDRV_NUM_OF_CHIPS];
	static uint16 VAR_IgbtDrv_RegSER_au16[IGBTDRV_NUM_OF_CHIPS];

	for( idx=0u; idx<IGBTDRV_NUM_OF_CHIPS; idx++ )
	{
               /*JEE_MISRA_RULE_10_05 It's allowed .*/
		VAR_IgbtDrv_ChipOpm_en[idx] = (IgbtDrv_ChipOpm)( (uint16)( ( (uint16)( PRV_PSTAT2_BITSMASK << PRV_PSTAT2_BITSPOS) & Prv_IgbtDrv_RegStatus_pst[1u].Reg_Value[idx] ) >> PRV_PSTAT2_BITSPOS )  );
		VAR_IgbtDrv_RegPER_au16[idx] =  Prv_IgbtDrv_RegStatus_pst[2u].Reg_Value[idx] ;
		VAR_IgbtDrv_RegSER_au16[idx] =  Prv_IgbtDrv_RegStatus_pst[5u].Reg_Value[idx] ;
	}
}

/*******************************************************************************
** Function Name	: Prv_IgbtDrv_IsOpmExpected
** Parameter[in] 	: refOpm
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: Judge Opm is expected.
*******************************************************************************/
static boolean Prv_IgbtDrv_IsOpmExpected(IgbtDrv_ChipOpm refOpm)
{
	uint8 idx;
	uint8 PrvIgbtDrv_jdx=0;
	boolean RetStatus;

	for(idx=0;idx<IGBTDRV_NUM_OF_CHIPS;idx++)
	{
		if( VAR_IgbtDrv_ChipOpm_en[idx] == refOpm )
		{
			PrvIgbtDrv_jdx++;
		}
	}
	if( PrvIgbtDrv_jdx == IGBTDRV_NUM_OF_CHIPS )
	{
		RetStatus = (boolean)TRUE;

	}
	else
	{
		RetStatus = (boolean)FALSE;
	}
	return (RetStatus);
}
/*******************************************************************************
** Function Name	: Prv_FsmOpmCheck
** Parameter[in] 	: opm
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: Judge Opm is expected.
*******************************************************************************/
static uint8 Prv_FsmOpmCheck( IgbtDrv_ChipOpm opm  )
{
	uint8 ret = 0u;
	if( Prv_NotifConfirm_st.ASYspiTxOnce == 0u )
	{
		Prv_NotifConfirm_st.ASYspiTxOnce = 1u ;
		Prv_IgbtDrv_ReadOneReg(IGBTDRV_REG_PSTAT2,0u );
	}
	else
	{
		if( Prv_NotifConfirm_st.RegReadTxFinish_u8 == 1u )
		{
			Prv_NotifConfirm_st.RegReadTxFinish_u8 = 0u ;
			Prv_NotifConfirm_st.ASYspiTxOnce = 0u;
			Prv_IgbtDrv_GetCurrOpm_Again();
			if( Prv_IgbtDrv_IsOpmExpected( opm ) == 1u  )
			{
				ret = 1u;
			}
		}
		else
		{
			ret = 0u;
		}
	}
	return ret;
}


/*******************************************************************************
** Function Name	: Prv_IgbtDrv_ModeCtrl
** Parameter[in] 	: modeCmd,isSync
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: IgbtDrv Mode Ctrl.
*******************************************************************************/
static void Prv_IgbtDrv_ModeCtrl(uint16 modeCmd, boolean isSync)
{
	uint8 idx;
	static uint16  Prv_IgbtDrv_SpiTxBuff_CmdForModCtrl[IGBTDRV_NUM_OF_CHIPS];

	for( idx=0;idx<IGBTDRV_NUM_OF_CHIPS;idx++ )
	{
		Prv_IgbtDrv_SpiTxBuff_CmdForModCtrl[idx] = modeCmd;
	}
	(void)Spi_SetupEB(SpiConf_SpiChannel_SpiChannel_ModeCtrl,(Spi_DataType*)Prv_IgbtDrv_SpiTxBuff_CmdForModCtrl, \
			(Spi_DataType*)Prv_IgbtDrv_SpiRxBuff_Reg,IGBTDRV_NUM_OF_CHIPS);

	if( isSync == 1U )
	{
		(void)Spi_SyncTransmit(SpiConf_SpiSequence_SpiSequence_1);
	}
	else
	{
		(void)Spi_AsyncTransmit(SpiConf_SpiSequence_SpiSequence_1);
	}
}
/*******************************************************************************
** Function Name	: Prv_FsmModeCtrl
** Parameter[in] 	: modeCmd
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: IgbtDrv Mode Ctrl.
*******************************************************************************/
static uint8 Prv_FsmModeCtrl( uint16 modeCmd  )
{
	uint8 ret = 0u;
	if( Prv_NotifConfirm_st.ASYspiTxOnce == 0u )
	{
		Prv_NotifConfirm_st.ASYspiTxOnce = 1u ;
		Prv_IgbtDrv_ModeCtrl(modeCmd,0u);
	}
	else
	{
		if( Prv_NotifConfirm_st.ModeCtrlTxFinish_u8 == 1u )
		{
			Prv_NotifConfirm_st.ModeCtrlTxFinish_u8 = 0u;
			Prv_NotifConfirm_st.ASYspiTxOnce = 0u;
			ret = 1u;
		}
		else
		{
			ret = 0u;
		}
	}
	return ret;
}
/*******************************************************************************
** Function Name	: IgbtDrv_WrReg8
** Parameter[in] 	: uint16 addr, uint16 data, boolean isSync
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: WrReg8.
*******************************************************************************/
 void IgbtDrv_WrReg8(uint16 addr, uint16 data, boolean isSync)
{
	uint8 idx;
	static uint16  Prv_IgbtDrv_SpiTxBuff_WrReg8[IGBTDRV_NUM_OF_CHIPS];

	for( idx=0;idx<IGBTDRV_NUM_OF_CHIPS;idx++ )
	{
		Prv_IgbtDrv_SpiTxBuff_WrReg8[idx] =   \
				Prv_IgbtDrv_GetDataWithParity(CMD_WRITEL_REQUEST(addr,data));
	}
	(void)Spi_SetupEB(SpiConf_SpiChannel_SpiChannel_WrL,(Spi_DataType*)Prv_IgbtDrv_SpiTxBuff_WrReg8,  \
			                   	   (Spi_DataType*)Prv_IgbtDrv_SpiRxBuff_Reg,IGBTDRV_NUM_OF_CHIPS);

	if( isSync == 1U )
	{
		(void)Spi_SyncTransmit(SpiConf_SpiSequence_SpiSequence_2);
	}
	else
	{
		(void)Spi_AsyncTransmit(SpiConf_SpiSequence_SpiSequence_2);
	}
}
 /*******************************************************************************
 ** Function Name	: IgbtDrv_WrReg16
 ** Parameter[in] 	: uint16 addr, uint16 data, boolean isSync
 ** Parameter[out] 	: None
 ** Return Value	: None
 ** Note			: None
 ** Description	  	: WrReg16
 *******************************************************************************/
void IgbtDrv_WrReg16(uint16 addr, uint16 data, boolean isSync)
{
	static uint16  Prv_IgbtDrv_SpiTxBuff_WrRegH[IGBTDRV_NUM_OF_CHIPS];
	static uint16  Prv_IgbtDrv_SpiTxBuff_WrRegL[IGBTDRV_NUM_OF_CHIPS];
	uint8 idx;
	for( idx=0;idx<IGBTDRV_NUM_OF_CHIPS;idx++ )
	{
		Prv_IgbtDrv_SpiTxBuff_WrRegH[idx] = Prv_IgbtDrv_GetDataWithParity( CMD_WRITEH_REQUEST(data) );
		Prv_IgbtDrv_SpiTxBuff_WrRegL[idx] = Prv_IgbtDrv_GetDataWithParity( CMD_WRITEL_REQUEST(addr,data) );
	}
	(void)Spi_SetupEB(SpiConf_SpiChannel_SpiChannel_WrH,(Spi_DataType*)Prv_IgbtDrv_SpiTxBuff_WrRegH, \
									(Spi_DataType*)Prv_IgbtDrv_SpiRxBuff_Reg,IGBTDRV_NUM_OF_CHIPS);

	(void)Spi_SetupEB(SpiConf_SpiChannel_SpiChannel_WrL,(Spi_DataType*)Prv_IgbtDrv_SpiTxBuff_WrRegL, \
									(Spi_DataType*)Prv_IgbtDrv_SpiRxBuff_Reg,IGBTDRV_NUM_OF_CHIPS);

	if( isSync == 1U )
	{
		(void)Spi_SyncTransmit(SpiConf_SpiSequence_SpiSequence_3);
	}
	else
	{
		(void)Spi_AsyncTransmit(SpiConf_SpiSequence_SpiSequence_3);
	}

}
/*******************************************************************************
** Function Name	: Prv_IgbtDrv_ReadOneReg
** Parameter[in] 	: uint16 addr, boolean isSync
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: Read One Register.
*******************************************************************************/
static void Prv_IgbtDrv_ReadOneReg(uint16 addr, boolean isSync)
{
	uint8 idx;
	static uint16  Prv_SpiTxBuff_ReadOneReg_H[IGBTDRV_NUM_OF_CHIPS];
	static uint16  Prv_SpiTxBuff_ReadOneReg_L[IGBTDRV_NUM_OF_CHIPS];
	static uint16  Prv_SpiRxBuffReadOneReg_H[IGBTDRV_NUM_OF_CHIPS];

	for( idx=0;idx<IGBTDRV_NUM_OF_CHIPS;idx++ )
	{
		Prv_SpiTxBuff_ReadOneReg_H[idx] = Prv_IgbtDrv_GetDataWithParity(CMD_READ_REQUEST(addr ));
		Prv_SpiTxBuff_ReadOneReg_L[idx] = Prv_IgbtDrv_GetDataWithParity(CMD_NOP);
	}

	(void)Spi_SetupEB(SpiConf_SpiChannel_SpiChannel_WrL_PCTRL,(Spi_DataType*)Prv_SpiTxBuff_ReadOneReg_H, \
			                        (Spi_DataType*)Prv_SpiRxBuffReadOneReg_H,IGBTDRV_NUM_OF_CHIPS);


	(void)Spi_SetupEB(SpiConf_SpiChannel_SpiChannel_WrL_PCTRL2,(Spi_DataType*)Prv_SpiTxBuff_ReadOneReg_L, \
									(Spi_DataType*)(&Prv_SpiRxBuffReadOneReg_L[addr][0u]),IGBTDRV_NUM_OF_CHIPS);


	if( isSync == 1U )
	{
		(void)Spi_SyncTransmit(SpiConf_SpiSequence_SpiSequence_6);
	}
	else
	{
		(void)Spi_AsyncTransmit(SpiConf_SpiSequence_SpiSequence_6);
	}

}
/*******************************************************************************
** Function Name	: Prv_FsmRegRstatValue
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: Read PSTAT Register.
*******************************************************************************/
static uint8 Prv_FsmRegRstatValue( void )
{
	uint8 ret = 0u;
	if( Prv_NotifConfirm_st.ASYspiTxOnce == 0u )
	{
		Prv_NotifConfirm_st.ASYspiTxOnce = 1u ;

		Prv_IgbtDrv_ReadOneReg(IGBTDRV_REG_PSTAT,0);
	}
	else
	{
		if( Prv_NotifConfirm_st.RegReadTxFinish_u8 == 1u )
		{
			Prv_NotifConfirm_st.RegReadTxFinish_u8 = 0u;
			Prv_NotifConfirm_st.ASYspiTxOnce = 0u;
			ret = 1u;
		}
		else
		{
			ret = 0u;
		}
	}
	return ret;
}
/*******************************************************************************
** Function Name	: Prv_IgbtDrv_ClrError
** Parameter[in] 	: isSync
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: Clear Error.
*******************************************************************************/
 static void Prv_IgbtDrv_ClrError(boolean isSync)
 {
 	uint16 tempRegValue[IGBTDRV_NUM_OF_CHIPS];
 	uint8 idx;
 	for(idx=0;idx<IGBTDRV_NUM_OF_CHIPS;idx++)
 	{
 		tempRegValue[idx] = (uint16)(PRV_PCTRL_CLRP_CLRS << PRV_PCTRL_BITSPOS);
 	}
 	IgbtDrv_WrReg8(IGBTDRV_REG_PCTRL, tempRegValue[0U], isSync);
 }

 /*******************************************************************************
 ** Function Name	: Prv_FsmClrError
 ** Parameter[in] 	: None
 ** Parameter[out] 	: None
 ** Return Value	: None
 ** Note			: None
 ** Description	  	: Clear Error.
 *******************************************************************************/
 static uint8 Prv_FsmClrError( void )
 {
 	uint8 ret = 0u;
 	if( Prv_NotifConfirm_st.ASYspiTxOnce == 0u )
 	{
 		Prv_NotifConfirm_st.ASYspiTxOnce = 1u ;
 		Prv_IgbtDrv_ClrError(0);
 	}
 	else
 	{
 		if( Prv_NotifConfirm_st.Reg8CfgTxFinish_u8 == 1u )
 		{
 			Prv_NotifConfirm_st.Reg8CfgTxFinish_u8 = 0u;
 			Prv_NotifConfirm_st.ASYspiTxOnce = 0u;
 			ret = 1u;
 		}
 		else
 		{
 			ret = 0u;
 		}
 	}
 	return ret;
 }

 /*******************************************************************************
 ** Function Name	: Prv_IgbtDrv_IsSRDYExpected
 ** Parameter[in] 	: None
 ** Parameter[out] 	: None
 ** Return Value	: None
 ** Note			: None
 ** Description	  	: Judge Rdy Pin id Expected.
 *******************************************************************************/
 static boolean Prv_IgbtDrv_IsSRDYExpected( void )
 {
 	uint8 idx;
 	uint8 IgbtDrv_jdx=0;
 	boolean RetStatus;
 	for( idx=0; idx< IGBTDRV_NUM_OF_CHIPS;idx++ )
 	{
 		if( (Prv_SpiRxBuffReadOneReg_L[IGBTDRV_REG_PSTAT][idx] & 0x0040u) == 0x0040u)
 		{
 			IgbtDrv_jdx++;
 		}
 	}
 	if(IgbtDrv_jdx == IGBTDRV_NUM_OF_CHIPS)
	{
 		  RetStatus = (boolean)TRUE;
	}
 	else
	{
 		  RetStatus = (boolean)FALSE;
	}
	return (RetStatus);
 }

 /*******************************************************************************
 ** Function Name	: Prv_IgbtDrv_IsErrOccur
 ** Parameter[in] 	: None
 ** Parameter[out] 	: None
 ** Return Value	: None
 ** Note			: None
 ** Description	  	: Judge Error id Occur.
 *******************************************************************************/
 static boolean Prv_IgbtDrv_IsErrOccur( void )
 {
 	uint8 idx;
 	uint8 IgbtDrv_jdx=0;
	boolean RetStatus;
 	for( idx=0; idx< IGBTDRV_NUM_OF_CHIPS;idx++ )
 	{
 		if( (Prv_SpiRxBuffReadOneReg_L[IGBTDRV_REG_PSTAT][idx] & 0x0800u) == 0x0800u)
 		{
 			IgbtDrv_jdx++;
 		}
 	}
 	if(IgbtDrv_jdx == IGBTDRV_NUM_OF_CHIPS)
	{
 		RetStatus = (boolean)TRUE;
	}
 	else
	{
 		RetStatus = (boolean)FALSE;
	}
        return (RetStatus);
 }

 /*******************************************************************************
 ** Function Name	: Prv_IgbtDrv_IsActOPM4
 ** Parameter[in] 	: None
 ** Parameter[out] 	: None
 ** Return Value	: None
 ** Note			: None
 ** Description	  	: Judge OPM4 is OK.
 *******************************************************************************/
 static boolean Prv_IgbtDrv_IsActOPM4( void )
 {
 	uint8 idx;
 	uint8 IgbtDrv_jdx = 0u;
	boolean RetStatus;
 	for( idx=0; idx< IGBTDRV_NUM_OF_CHIPS;idx++ )
 	{
 		if( (Prv_SpiRxBuffReadOneReg_L[IGBTDRV_REG_PSTAT][idx] & 0x0080u) == 0x0080u)
 		{
 			IgbtDrv_jdx++;
 		}
 	}
 	if(IgbtDrv_jdx == IGBTDRV_NUM_OF_CHIPS)
	{
 		RetStatus = (boolean)TRUE;
	}
 	else
	{
 		RetStatus = (boolean)FALSE;
	}
	return RetStatus;
 }
#if 0
 static void IgbtDrv_Fault_Injection(void)/*LQTest*/
{
	static uint8 Fault_InjectionCnt=0;
	Fault_InjectionCnt++;
	if( Fault_InjectionCnt<150 )
	{
		Prv_IgbtDrv_RegConf_pst[6u].Reg_Value[0] = 0;
	}
}
#endif
 /*******************************************************************************
 ** Function Name	: Prv_IgbtDrv_IsSCFGCorrect
 ** Parameter[in] 	: None
 ** Parameter[out] 	: None
 ** Return Value	: None
 ** Note			: None
 ** Description	  	: Judge SCFG is OK.
 *******************************************************************************/
 static boolean Prv_IgbtDrv_IsSCFGCorrect(void)
 {
 	uint8 idx;
 	uint8 IgbtDrv_jdx = 0u;
	boolean RetStatus;
	#if 0
 	IgbtDrv_Fault_Injection();/*LQTest*/
	#endif
 	for( idx=0;idx<IGBTDRV_NUM_OF_CHIPS;idx++ )
 	{
 		if(  (Prv_IgbtDrv_RegConf_pst[6u].Reg_Value[idx] &0xFFDCu)  == (IGBTDRV_VALUE_SCFG &0xFFDCu) )/*Note "6U" must modify with IgbtDrv_RegConf_st[] NO */
 		{
 			IgbtDrv_jdx++;
 		}
 	}
 	if(IgbtDrv_jdx == IGBTDRV_NUM_OF_CHIPS)
 	{
 		RetStatus =(boolean)TRUE;

 	}
 	else
 	{
 		RetStatus =(boolean)FALSE;
 	}
	return (RetStatus);
 }

/***************************IgbtDrv Machine************************************/

 /*******************************************************************************
 ** Function Name	: Prv_IgbtDrv_InitSeq \Prv_IgbtDrv_InitCheckSeq\ Prv_IgbtDrv_RunTimeOperation\ Prv_IgbtDrv_ErrorHandling
 ** Parameter[in] 	: None
 ** Parameter[out] 	: None
 ** Return Value	: None
 ** Note			: None
 ** Description	  	: IgbtDrv Machine
 *******************************************************************************/
static void Prv_IgbtDrv_InitSeq(void)
{
	Prv_Debug_FsmWatch_st.ModuleFSMWatch_au8[0u]++;
	Prv_IgbtDrv_FSM_FlsParam_st.IgbtDrv_InitSeqStepFSM_pa[Prv_IgbtDrv_FSM_RamParam_st.InitSeqMode]();
}

static void Prv_IgbtDrv_InitCheckSeq(void)
{
	Prv_Debug_FsmWatch_st.ModuleFSMWatch_au8[1u]++;
	Prv_IgbtDrv_FSM_FlsParam_st.IgbtDrv_InitCheckSeqStepFSM_pa[Prv_IgbtDrv_FSM_RamParam_st.InitSeqCheckMode]();
}

static void Prv_IgbtDrv_RunTimeOperation(void)
{
	Prv_Debug_FsmWatch_st.ModuleFSMWatch_au8[2u]++;
	Prv_GetPinStaus();								/*real-time supervision FaultA\B*/

	/**************************************FaultA/B Monitor***************************************************/
	if( VAR_IgbtDrv_Level_NFLTA_u8 == 0u )/*In case of an error event, NFLTA is driven to Low state.*/
	{
		(void)Dem_SetEventStatus(DemConf_DemEventParameter_IgbtDrv_UpBrgFaultAFail,DEM_EVENT_STATUS_FAILED);
	}
	if( VAR_IgbtDrv_Level_NFLTA_L_u8 == 0u )/*In case of an error event, NFLTA is driven to Low state.*/
	{
		(void)Dem_SetEventStatus(DemConf_DemEventParameter_IgbtDrv_LwBrgFaultAFail,DEM_EVENT_STATUS_FAILED);
	}
	if( VAR_IgbtDrv_Level_NFLTB_u8 == 0u )/*In case of an error event, NFLTB is driven to Low state.*/
	{
		(void)Dem_SetEventStatus(DemConf_DemEventParameter_IgbtDrv_UpBrgFaultBFail,DEM_EVENT_STATUS_FAILED);
	}
	if( VAR_IgbtDrv_Level_NFLTB_L_u8 == 0u )/*In case of an error event, NFLTB is driven to Low state.*/
	{
		(void)Dem_SetEventStatus(DemConf_DemEventParameter_IgbtDrv_LwBrgFaultBFail,DEM_EVENT_STATUS_FAILED);
	}
	/*******************************************************************************************************/

	IgbtDrv_AppWorkReady_u8 = 1u;
	Prv_IgbtDrv_FSM_FlsParam_st.IgbtDrv_RunTimeStepFSM_pa[Prv_IgbtDrv_FSM_RamParam_st.RunTimeMode]();
}

static void Prv_IgbtDrv_ErrorHandling(void)
{
	Prv_Debug_FsmWatch_st.ModuleFSMWatch_au8[3u]++;
	Prv_GetPinStaus();								/*real-time supervision FaultA\B*/
	IgbtDrv_AppWorkReady_u8 = 0u;
	Prv_IgbtDrv_FSM_FlsParam_st.IgbtDrv_ErrorHandlingFSM_pa[Prv_IgbtDrv_FSM_RamParam_st.ErrorHandlingMode]();
}

/*******************Initialization Sequence*************************************/

/*******************************************************************************
** Function Name	: Prv_ResetChip_InitSeqStep0
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: 1EDI2002AS Reset
*******************************************************************************/
static void Prv_ResetChip_InitSeqStep0(void)
{
	static uint8 Prv_ResetChip_u8 = 0;

	Prv_Debug_FsmWatch_st.InitSeqStepFSMWatch_au8[0u]++;

	Dio_WriteChannel(PIN_EN  , STD_LOW);
	Dio_WriteChannel(PIN_EN_L, STD_LOW);
	switch( Prv_ResetChip_u8 )
	{
		case PRV_IGBTDRV_RESETCHIP_STEP1:
		{
			Prv_ResetChip_u8 = PRV_IGBTDRV_RESETCHIP_STEP2;
			Prv_IgbtDrv_ChipReset();

			break;
		}
		case PRV_IGBTDRV_RESETCHIP_STEP2:
		{
			Prv_ResetChip_u8 = PRV_IGBTDRV_RESETCHIP_FINSIH;
			Prv_IgbtDrv_ChipNormal();

			Prv_IgbtDrv_FSM_RamParam_st.InitSeqMode = ReadPrimaryReadyStatusMode;

			break;
		}
		default:
		{
			Prv_ResetChip_u8 = 0;
			break;
		}
	}
}
/*******************************************************************************
** Function Name	: Prv_ReadPrimaryReadyStatus_InitSeqStep1
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: Get 1EDI2002AS Primary Ready Status.
*******************************************************************************/
static void Prv_ReadPrimaryReadyStatus_InitSeqStep1(void)
{
	Prv_Debug_FsmWatch_st.InitSeqStepFSMWatch_au8[1u]++;

	if( 1u == Prv_ReadChipReadyStatus() )
	{
		Prv_IgbtDrv_Diag_Init();
		Prv_IgbtDrv_FSM_RamParam_st.InitSeqMode = CheckPrimaryStatus1Mode;

	}
	else
	{

		Prv_IgbtDrv_Diag_Handle(InitErrMode,ReadPrimaryReadyStatusMode_Err);
	}


}
/*******************************************************************************
** Function Name	: Prv_CheckPrimaryStatus_InitSeqStep2
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: Get PSTAT Value.
*******************************************************************************/
static void Prv_CheckPrimaryStatus_InitSeqStep2(void)
{
	Prv_Debug_FsmWatch_st.InitSeqStepFSMWatch_au8[2u]++;

	if( 1u == Prv_FsmRegRstatValue() )
	{
		Prv_IgbtDrv_Diag_Init();
		Prv_IgbtDrv_FSM_RamParam_st.InitSeqMode = ReadSecondaryReadyStatusMode;
	}
	else
	{
		Prv_IgbtDrv_Diag_Handle(InitErrMode,CheckPrimaryStatus1Mode_Err);
	}

}

/*******************************************************************************
** Function Name	: Prv_ReadSecondaryReadyStatus_InitSeqStep3
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: Analysis PSTAT.SRDY,Judge Chip is  ready.
*******************************************************************************/
static void Prv_ReadSecondaryReadyStatus_InitSeqStep3(void)
{
	Prv_Debug_FsmWatch_st.InitSeqStepFSMWatch_au8[3u]++;

	if( Prv_IgbtDrv_IsSRDYExpected() == 1u )/*(SRDY = 1)?*/
	{
		Prv_IgbtDrv_Diag_Init();
		Prv_IgbtDrv_FSM_RamParam_st.InitSeqMode = ClearFlags1Mode;
	}
	else
	{

		Prv_IgbtDrv_Diag_Handle(InitErrMode,ReadSecondaryReadyStatusMode_Err);
	}

}

/*******************************************************************************
** Function Name	: Prv_ClearFlags_InitSeqStep4
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: Clear sticky \ Nfltb\ Nflta.
*******************************************************************************/
static void Prv_ClearFlags_InitSeqStep4(void)
{
	Prv_Debug_FsmWatch_st.InitSeqStepFSMWatch_au8[4u]++;

	if( 1u == Prv_FsmClrError() )
	{
		Prv_IgbtDrv_Diag_Init();
		Prv_IgbtDrv_FSM_RamParam_st.InitSeqMode = CheckDeviceIDMode;
	}
	else
	{
		Prv_IgbtDrv_Diag_Handle( InitErrMode,ClearFlags1Mode_Err );
	}
}

/*******************************************************************************
** Function Name	: Prv_CheckDeviceID_InitSeqStep5
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: Read PID\ SID .
*******************************************************************************/
static void Prv_CheckDeviceID_InitSeqStep5(void)
{
	Prv_Debug_FsmWatch_st.InitSeqStepFSMWatch_au8[5u]++;

	Prv_IgbtDrv_FSM_RamParam_st.InitSeqMode = EnterConfigMode;
}

/*******************************************************************************
** Function Name	: Prv_EnterConfigMode_InitSeqStep6
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: Send CMD_ENTER_CMODE CMD.
*******************************************************************************/
static void Prv_EnterConfigMode_InitSeqStep6(void)
{
	Prv_Debug_FsmWatch_st.InitSeqStepFSMWatch_au8[6u]++;

	if( 1u == Prv_FsmModeCtrl(CMD_ENTER_CMODE) )
	{
		Prv_IgbtDrv_Diag_Init();
		Prv_IgbtDrv_FSM_RamParam_st.InitSeqMode = VerifyOPM2Mode;
	}
	else
	{
		Prv_IgbtDrv_Diag_Handle(InitErrMode,EnterConfigMode_Err);
	}
}

/*******************************************************************************
** Function Name	: Prv_VerifyOPM2_InitSeqStep7
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: read PSTAT2.OPM,Judge OPM2 is OK.
*******************************************************************************/
static void Prv_VerifyOPM2_InitSeqStep7(void)
{
	Prv_Debug_FsmWatch_st.InitSeqStepFSMWatch_au8[7u]++;

	if( 1u == Prv_FsmOpmCheck(IgbtDrv_Opm2_e) )
	{
		Prv_IgbtDrv_Diag_Init();
		Prv_IgbtDrv_FSM_RamParam_st.InitSeqMode = ConfigDeviceMode;
	}
	else
	{
		Prv_IgbtDrv_Diag_Handle( InitErrMode,VerifyOPM2Mode_Err );
	}
}

/*******************************************************************************
** Function Name	: Prv_ConfigDevice_InitSeqStep8
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: According to IgbtDrv_RegCfg_st configurate Register.
*******************************************************************************/
static void Prv_ConfigDevice_InitSeqStep8(void)
{
	static uint8 stateMachineIndex = 0;
	Prv_Debug_FsmWatch_st.InitSeqStepFSMWatch_au8[8u]++;

	if( (Prv_NotifConfirm_st.Reg16CfgTxFinish_u8 == 1u)||(Prv_NotifConfirm_st.Reg8CfgTxFinish_u8 == 1u) )
	{
		Prv_NotifConfirm_st.Reg16CfgTxFinish_u8 = 0u;
		Prv_NotifConfirm_st.Reg8CfgTxFinish_u8 = 0u;

		Prv_IgbtDrv_RegCfg_pst[stateMachineIndex].pfun_IgbtDrv(Prv_IgbtDrv_RegCfg_pst[stateMachineIndex].Reg_ShortName,Prv_IgbtDrv_RegCfg_pst[stateMachineIndex].Reg_Value,0u);
		stateMachineIndex ++;
		if( stateMachineIndex == IGBTDRV_NUM_OF_CFGREG )
		{
			stateMachineIndex = 0u;
			Prv_IgbtDrv_FSM_RamParam_st.InitSeqMode = SystemTestMode;
		}
	}
	else
	{
		Prv_NotifConfirm_st.Reg16CfgTxFinish_u8 = 0u;
		Prv_NotifConfirm_st.Reg8CfgTxFinish_u8 = 0u;
	}


}
/*******************************************************************************
** Function Name	: Prv_SystemTest_InitSeqStep9
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: reserved  SystemTest.
*******************************************************************************/
static void Prv_SystemTest_InitSeqStep9(void)
{
	Prv_Debug_FsmWatch_st.InitSeqStepFSMWatch_au8[9u]++;
	Prv_IgbtDrv_FSM_RamParam_st.Mode = InitCheckSeqMode;

}

/*******************Initialization Sequence Check*************************************/

/*******************************************************************************
** Function Name	: Prv_ExitConfigMode_InitCheckSeqStep1
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: Send CMD_EXIT_CMODE CMD.
*******************************************************************************/
static void Prv_ExitConfigMode_InitCheckSeqStep1(void)
{
	Prv_Debug_FsmWatch_st.InitCheckSeqStepFSMWatch_au8[0u]++;

	if( 1u == Prv_FsmModeCtrl(CMD_EXIT_CMODE ) )
	{
		Prv_IgbtDrv_Diag_Init();
		Prv_IgbtDrv_FSM_RamParam_st.InitSeqCheckMode = VerifyOPM3Mode;
	}
	else
	{
		Prv_IgbtDrv_Diag_Handle( InitErrMode,ExitConfigModeMode_Err );
	}
}

/*******************************************************************************
** Function Name	: Prv_ExitConfigMode_InitCheckSeqStep1
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: Raed PSTAT2.OPM,Judge OPM3 is OK.
*******************************************************************************/
static void Prv_VerifyOPM3_InitCheckSeqStep2(void)
{
	Prv_Debug_FsmWatch_st.InitCheckSeqStepFSMWatch_au8[1u]++;
	if( 1u == Prv_FsmOpmCheck(IgbtDrv_Opm3_e ) )
	{
		Prv_IgbtDrv_Diag_Init();
		Prv_IgbtDrv_FSM_RamParam_st.InitSeqCheckMode = VerifyConfigMode;
	}
	else
	{
		Prv_IgbtDrv_Diag_Handle( InitErrMode,VerifyOPM3Mode_Err );
	}

}

/*******************************************************************************
** Function Name	: Prv_VerifyConfig_InitCheckSeqStep3
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: Read configuration Register.
*******************************************************************************/
static void Prv_VerifyConfig_InitCheckSeqStep3(void)
{
	Prv_Debug_FsmWatch_st.InitCheckSeqStepFSMWatch_au8[2u]++;

	if( Prv_NotifConfirm_st.ASYspiTxOnce == 0u )	/**/
	{
		Prv_IgbtDrv_ReadConfRegs(0);
		Prv_NotifConfirm_st.ASYspiTxOnce = 1u;
	}
	else
	{
		if( Prv_NotifConfirm_st.ReadConfRegsTxFinish_u8 == 1u )
		{
			Prv_NotifConfirm_st.ReadConfRegsTxFinish_u8 = 0u;
			Prv_NotifConfirm_st.ASYspiTxOnce = 0u;
			Prv_IgbtDrv_Diag_Init();
			Prv_IgbtDrv_FSM_RamParam_st.InitSeqCheckMode = ConfigurationJudgeMode;
		}
		else
		{
			Prv_IgbtDrv_Diag_Handle(InitErrMode,VerifyConfigMode_Err);
		}
	}

}

/*******************************************************************************
** Function Name	: Prv_ConfigurationJudge_InitCheckSeqStep4
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: Read configuration Register,Compare with Prv_ConfigDevice_InitSeqStep8.
*******************************************************************************/
static void Prv_ConfigurationJudge_InitCheckSeqStep4(void)
{
	Prv_Debug_FsmWatch_st.InitCheckSeqStepFSMWatch_au8[3u]++;

	if( 1u == Prv_IgbtDrv_IsSCFGCorrect() )
	{
		Prv_IgbtDrv_FSM_RamParam_st.InitSeqCheckMode = CheckDeviceStatusMode;
		Prv_IgbtDrv_Diag_Init();
	}
	else
	{
		Prv_IgbtDrv_Diag_Handle(InitErrMode,ConfigurationJudgeMode_Err);
	}
}

/*******************************************************************************
** Function Name	: Prv_CheckDeviceStatus_InitCheckSeqStep5
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: Read Status Register.
*******************************************************************************/
static void Prv_CheckDeviceStatus_InitCheckSeqStep5(void)
{
	Prv_Debug_FsmWatch_st.InitCheckSeqStepFSMWatch_au8[4u]++;

	if( Prv_NotifConfirm_st.ASYspiTxOnce == 0u )	/**/
	{
		Prv_GetRegisterStatus(0);
		Prv_NotifConfirm_st.ASYspiTxOnce = 1u;
	}
	else
	{
		if(Prv_NotifConfirm_st.ReadStatusRegsTxFinish_u8 == 1u )
		{
			Prv_NotifConfirm_st.ReadStatusRegsTxFinish_u8 = 0u;
			Prv_NotifConfirm_st.ASYspiTxOnce = 0u;
			Prv_IgbtDrv_Diag_Init();
			Prv_IgbtDrv_FSM_RamParam_st.InitSeqCheckMode = VerifyStatus1Mode;
		}
		else
		{
			Prv_IgbtDrv_Diag_Handle(InitErrMode,CheckDeviceStatusMode_Err);
		}
	}
}
/*******************************************************************************
** Function Name	: Prv_VerifyStatus_InitCheckSeqStep6
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: Judge Status Register is OK.
*******************************************************************************/
static void Prv_VerifyStatus_InitCheckSeqStep6(void)
{
	Prv_Debug_FsmWatch_st.InitCheckSeqStepFSMWatch_au8[5u]++;

	Prv_IgbtDrv_FSM_RamParam_st.InitSeqCheckMode = ClearFlags2Mode;
}

/*******************************************************************************
** Function Name	: Prv_ClearFlags_InitCheckSeqStep7
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: Clear sticky \ Nfltb \ Nflta.
*******************************************************************************/
static void Prv_ClearFlags_InitCheckSeqStep7(void)
{
	Prv_Debug_FsmWatch_st.InitCheckSeqStepFSMWatch_au8[6u]++;

	if( 1u == Prv_FsmClrError() )
	{
		Prv_IgbtDrv_Diag_Init();
		Prv_IgbtDrv_FSM_RamParam_st.InitSeqCheckMode = GotoOPM4Mode;
	}
	else
	{
		Prv_IgbtDrv_Diag_Handle( InitErrMode,ClearFlags2Mode_Err );
	}
}

/*******************************************************************************
** Function Name	: Prv_GotoOPM4_InitCheckSeqStep8
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: Goto OPM4,Judge OPM4 is OK.
*******************************************************************************/
static void Prv_GotoOPM4_InitCheckSeqStep8(void)
{
	Prv_Debug_FsmWatch_st.InitCheckSeqStepFSMWatch_au8[7u]++;

	Dio_WriteChannel(PIN_EN  , STD_HIGH);
	Dio_WriteChannel(PIN_EN_L, STD_HIGH);
	if( 1u == Prv_FsmOpmCheck(IgbtDrv_Opm4_e ) )
	{
		Prv_IgbtDrv_Diag_Init();
		#if 0U
		Cpld_Clear_Fault();/*LQ20201101 no need clear*/
		#endif
		Prv_IgbtDrv_FSM_RamParam_st.Mode = RunTimeMode;
		Prv_IgbtDrv_FSM_RamParam_st.RunTimeMode = CheckPrimaryStatus2Mode;
		VAR_Igbt_Normal_State_u16 = 1U;
	}
	else
	{
		Prv_IgbtDrv_Diag_Handle(InitErrMode,GotoOPM4Mode_Err);
	}
}


/*Prv_IgbtDrv_RunTimeOperation Submachine*/

/*******************************************************************************
** Function Name	: Prv_CheckPrimaryStatus_RunTimeStep1
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: Read PSTAT .
*******************************************************************************/
static void Prv_CheckPrimaryStatus_RunTimeStep1(void)
{
	Prv_Debug_FsmWatch_st.RunTimeStepFSMWatch_au8[0u]++;

	if( 1u == Prv_FsmRegRstatValue() )
	{
		Prv_IgbtDrv_Diag_Init();
		Prv_IgbtDrv_FSM_RamParam_st.RunTimeMode = VerifyStatusMode;
	}
	else
	{
		Prv_IgbtDrv_Diag_Handle(RuntimeErrMode,CheckPrimaryStatus2Mode_Err);
	}
//	VAR_Igbt_Normal_State_u16 = 1U;

}

/*******************************************************************************
** Function Name	: Prv_VerifyStatus_RunTimeStep2
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	:  Analysis PSTAT.SRDY\ACT\GPONS\GPOFS.
*******************************************************************************/
static void Prv_VerifyStatus_RunTimeStep2(void)
{
	Prv_Debug_FsmWatch_st.RunTimeStepFSMWatch_au8[1u]++;

	if( Prv_IgbtDrv_IsActOPM4() == 1u )
	{
		Prv_IgbtDrv_FSM_RamParam_st.RunTimeMode = RuntimeErrorDetectedMode;

	}
	else
	{
		Prv_IgbtDrv_Det_ReportError(VerifyStatusMode_Err);
		Prv_IgbtDrv_FSM_RamParam_st.Mode = ErrorHandlingMode;
		Prv_IgbtDrv_FSM_RamParam_st.ErrorHandlingMode = RuntimeErrMode;
	}
}

/*******************************************************************************
** Function Name	: Prv_RuntimeErrorDetected_RunTimeStep3
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: Analysis PSTAT.Err.
*******************************************************************************/
static void Prv_RuntimeErrorDetected_RunTimeStep3(void)
{
	Prv_Debug_FsmWatch_st.RunTimeStepFSMWatch_au8[2u]++;

	if( Prv_IgbtDrv_IsErrOccur() == 1u )
	{
		Prv_IgbtDrv_Det_ReportError(RuntimeErrorDetectedMode_Err);
		Prv_IgbtDrv_FSM_RamParam_st.Mode = ErrorHandlingMode;
		Prv_IgbtDrv_FSM_RamParam_st.ErrorHandlingMode = RuntimeErrMode;
	}
	else
	{
		Prv_IgbtDrv_FSM_RamParam_st.RunTimeMode = CheckPrimaryStatus2Mode;
	}
}

/*******************************************************************************
** Function Name	: Prv_IgbtDrvFsmReset
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: IgbtDrv Fsm Reset.
*******************************************************************************/
static void Prv_IgbtDrvFsmReset(uint8* ctrlCmd_u8)
{
	if( *ctrlCmd_u8 == IGBTDRV_CTRL_RST_CMD )
	{
		*ctrlCmd_u8 = 0u;
		Prv_IgbtDrv_FSM_RamParam_st.Mode = InitSeqMode;
		Prv_IgbtDrv_FSM_RamParam_st.InitSeqMode = ResetChipMode;
		Prv_IgbtDrv_FSM_RamParam_st.InitSeqCheckMode = ExitConfigModeMode;
		Prv_IgbtDrv_FSM_RamParam_st.RunTimeMode = CheckPrimaryStatus2Mode;

		Prv_NotifConfirm_st.ASYspiTxOnce = 0u;
		Prv_NotifConfirm_st.ModeCtrlTxFinish_u8 = 0u;
		Prv_NotifConfirm_st.Reg8CfgTxFinish_u8 = 1u;
		Prv_NotifConfirm_st.Reg16CfgTxFinish_u8 = 1u;
		Prv_NotifConfirm_st.RegReadTxFinish_u8 = 0u;
		Prv_NotifConfirm_st.ReadStatusRegsTxFinish_u8 = 0u;
		Prv_NotifConfirm_st.ReadConfRegsTxFinish_u8 = 0u;

		VAR_IgbtDrv_Det_ReportError_u8 = None_Err;

		Dio_WriteChannel(PIN_EN  , STD_LOW);
		Dio_WriteChannel(PIN_EN_L, STD_LOW);

		//		Cpld_Clear_Fault();
		Dio_WriteChannel(DioConf_DioChannel_DO_CPLDCLR_P10_0,STD_HIGH);
		Timer_DelayTicks(2000U);
		Dio_WriteChannel(DioConf_DioChannel_DO_CPLDCLR_P10_0,STD_LOW);
	}
}

/***********************Prv_IgbtDrv_ErrorHandling Submachine*************************/

/*******************************************************************************
** Function Name	: Prv_HandlingLMIErrors\Prv_HandlingInitErrors\Prv_HandlingEventsClassAErrors\Prv_HandlingEventsClassBErrors\Prv_HandlingRuntimeError
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: IgbtDrv Error Handle.
*******************************************************************************/
static void Prv_HandlingLMIErrors(void)
{
	Prv_Debug_FsmWatch_st.ErrorHandlingFSMWatch_au8[0u]++;
	Prv_IgbtDrvFsmReset(&IgbtDrv_AppCtrlCmd_u8);

}
static void Prv_HandlingInitErrors(void)
{
	static uint8 InitErrorAutoRstCnt = 0u;
	Prv_Debug_FsmWatch_st.ErrorHandlingFSMWatch_au8[1u]++;
	InitErrorAutoRstCnt++;
	if( InitErrorAutoRstCnt < IGBTDRV_INITERR_AUTO_RST_LIMIT )
	{
		IgbtDrv_AppCtrlCmd_u8 = IGBTDRV_CTRL_RST_CMD;
	}
	else
	{
		InitErrorAutoRstCnt = IGBTDRV_INITERR_AUTO_RST_LIMIT;
		(void)Dem_SetEventStatus(DemConf_DemEventParameter_IgbtDrv_ComErr,DEM_EVENT_STATUS_FAILED);
	}
	Prv_IgbtDrvFsmReset(&IgbtDrv_AppCtrlCmd_u8);
}

static void Prv_HandlingEventsClassAErrors(void)
{
	Prv_Debug_FsmWatch_st.ErrorHandlingFSMWatch_au8[2u]++;

	if( VAR_IgbtDrv_Level_NFLTA_u8 == 0u )/*In case of an error event, NFLTA is driven to Low state.*/
	{
		(void)Dem_SetEventStatus(DemConf_DemEventParameter_IgbtDrv_UpBrgFaultAFail,DEM_EVENT_STATUS_FAILED);
	}
	if( VAR_IgbtDrv_Level_NFLTA_L_u8 == 0u )/*In case of an error event, NFLTA is driven to Low state.*/
	{
		(void)Dem_SetEventStatus(DemConf_DemEventParameter_IgbtDrv_LwBrgFaultAFail,DEM_EVENT_STATUS_FAILED);
	}

	Prv_IgbtDrvFsmReset(&IgbtDrv_AppCtrlCmd_u8);

}
static void Prv_HandlingEventsClassBErrors(void)
{
	Prv_Debug_FsmWatch_st.ErrorHandlingFSMWatch_au8[3u]++;

	if( VAR_IgbtDrv_Level_NFLTB_u8 == 0u )/*In case of an error event, NFLTB is driven to Low state.*/
	{
		(void)Dem_SetEventStatus(DemConf_DemEventParameter_IgbtDrv_UpBrgFaultBFail,DEM_EVENT_STATUS_FAILED);
	}
	if( VAR_IgbtDrv_Level_NFLTB_L_u8 == 0u )/*In case of an error event, NFLTB is driven to Low state.*/
	{
		(void)Dem_SetEventStatus(DemConf_DemEventParameter_IgbtDrv_LwBrgFaultBFail,DEM_EVENT_STATUS_FAILED);
	}

	Prv_IgbtDrvFsmReset(&IgbtDrv_AppCtrlCmd_u8);
}

static void Prv_HandlingRuntimeError(void)
{
	Prv_Debug_FsmWatch_st.ErrorHandlingFSMWatch_au8[4u]++;

	if( ( VAR_IgbtDrv_Level_NFLTA_u8 == 0u ) || ( VAR_IgbtDrv_Level_NFLTA_L_u8 == 0u ) )/*In case of an error event, NFLTA is driven to Low state.*/
	{
		Prv_IgbtDrv_FSM_RamParam_st.Mode = ErrorHandlingMode;/*Error Manager*/
		Prv_IgbtDrv_FSM_RamParam_st.ErrorHandlingMode = EventsClassAErrMode;
	}
	if( ( VAR_IgbtDrv_Level_NFLTB_u8 == 0u ) || ( VAR_IgbtDrv_Level_NFLTB_L_u8 == 0u )  )
	{
		Prv_IgbtDrv_FSM_RamParam_st.Mode = ErrorHandlingMode;/*Error Manager*/
		Prv_IgbtDrv_FSM_RamParam_st.ErrorHandlingMode = EventsClassBErrMode;
	}
	Prv_IgbtDrvFsmReset(&IgbtDrv_AppCtrlCmd_u8);
	(void)Dem_SetEventStatus(DemConf_DemEventParameter_IgbtDrv_ComErr,DEM_EVENT_STATUS_FAILED);


}



/*******************************************************************************
** Function Name	: IgbtDrv_init
** Parameter[in] 	: arg_HWCfg_pst
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: IgbtDrv initialization.
*******************************************************************************/
void IgbtDrv_init(const IgbtDrv_HWCfgType *arg_HWCfg_pst)
{

	if( arg_HWCfg_pst != NULL_PTR )
	{
		Prv_IgbtDrv_RegStatus_pst = arg_HWCfg_pst->IgbtDrv_RegStatus;
		Prv_IgbtDrv_RegConf_pst   = arg_HWCfg_pst->IgbtDrv_RegConf;
		Prv_IgbtDrv_RegCfg_pst    = arg_HWCfg_pst->IgbtDrv_RegCfg;
	}
	else
	{
		Prv_IgbtDrv_Det_ReportError(IgbtDrv_init_Err);
		Prv_IgbtDrv_FSM_RamParam_st.Mode = ErrorHandlingMode;
		Prv_IgbtDrv_FSM_RamParam_st.ErrorHandlingMode = InitErrMode;

	}

	Prv_IgbtDrv_InitTxBuff();
}

/*******************************************************************************
** Function Name	: IgbtDrv_StateManagement
** Parameter[in] 	: None
** Parameter[out] 	: out
** Return Value	  	: None
** Note			  	: 1ms
** Description	  	: 1ed2002 chip state control
*******************************************************************************/
void IgbtDrv_StateManagement (IgbtDrvRdyOutIFType* out)
{
	if(  LV_PowerFinish() == PWR_LV_POWERSETUP_OK )
	{
		Prv_IgbtDrv_FSM_FlsParam_st.IgbtDrv_ModuleFSM_pa[Prv_IgbtDrv_FSM_RamParam_st.Mode]();

		IgbtDrv_AppFaultType_u8 =(uint8)VAR_IgbtDrv_Det_ReportError_u8;

		out->flgGateDrvRdyHs_u8 = IgbtDrv_AppWorkReady_u8;
		out->flgGateDrvRdyLs_u8 = IgbtDrv_AppWorkReady_u8;
	}
	else
	{
		Prv_Debug_FsmWatch_st.Fsm_IdleCount_u32++;
	}
	Rte_IrvIWrite_RE_IgbtDrv_1ms_IVDP_State( (uint8)(Prv_IgbtDrv_FSM_RamParam_st.Mode) );
	Rte_Var_CPT_IgbtDrv_10ms_IVDP_State = Rte_Var_CPT_IgbtDrv_1ms_IVDP_State;

}

/*******************************************************************************
** Function Name	: IgbtDrv_10ms_MainFunction
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: 10ms
** Description	  	: When a fault is detected, this function executes. Read specific fault information.
*******************************************************************************/
void IgbtDrv_10ms_MainFunction(void)
{
	uint8 temp;
	temp = Rte_IrvIRead_RE_IgbtDrv_10ms_IVDP_State() ;
	if(  temp == (uint8) ErrorHandlingMode )
	{
		Prv_Debug_FsmWatch_st.Fsm_10msCount_u32++;
		if( Prv_NotifConfirm_st.ASYspiTxOnce == 0u )	/**/
		{
			Prv_GetRegisterStatus(0u);
			Prv_NotifConfirm_st.ASYspiTxOnce = 1u;
		}
		else
		{
			if(Prv_NotifConfirm_st.ReadStatusRegsTxFinish_u8 == 1u )
			{
				Prv_NotifConfirm_st.ReadStatusRegsTxFinish_u8 = 0u;
				Prv_NotifConfirm_st.ASYspiTxOnce = 0u;
			}
			else
			{
				Prv_IgbtDrv_GetRegisterValue_Loop();
			}
		}
	}
	else
	{
		Prv_Debug_FsmWatch_st.Fsm_10msCount_u32 = 0u;
	}
}
/*******************************************************************************
** Function Name	: SpiSeqxEndNotification
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: Spi Driver Notification.
*******************************************************************************/
void SpiSeq0EndNotification(void)
{
	static uint32 SpiSeq0EndNotificationCnt;
	SpiSeq0EndNotificationCnt++;
	Prv_NotifConfirm_st.ReadStatusRegsTxFinish_u8 = 1u;
}
void SpiSeq1EndNotification(void)
{
	static uint32 SpiSeq1EndNotificationCnt;
	SpiSeq1EndNotificationCnt++;
	Prv_NotifConfirm_st.ModeCtrlTxFinish_u8 = 1u;
}
void SpiSeq2EndNotification(void)
{
	static uint32 SpiSeq2EndNotificationCnt;
	SpiSeq2EndNotificationCnt++;
	Prv_NotifConfirm_st.Reg8CfgTxFinish_u8 = 1u;
}
void SpiSeq3EndNotification(void)
{
	static uint32 SpiSeq3EndNotificationCnt;
	SpiSeq3EndNotificationCnt++;
	Prv_NotifConfirm_st.Reg16CfgTxFinish_u8 = 1u;

}

void SpiSeq6EndNotification(void)
{
	static uint32 SpiSeq6EndNotificationCnt;
	SpiSeq6EndNotificationCnt++;
	Prv_NotifConfirm_st.RegReadTxFinish_u8 = 1u;

}

void SpiSeqCddIgbtDrv_RdConfEndNotification(void)
{
	static uint32 SpiSeqRdConfEndNotificationCnt;
	SpiSeqRdConfEndNotificationCnt++;
	Prv_NotifConfirm_st.ReadConfRegsTxFinish_u8 = 1u;
}

void SpiSeqCddIgbtDrv_RdConf2EndNotification(void)
{
	static uint32 SpiSeqRdConf2EndNotificationCnt;
	SpiSeqRdConf2EndNotificationCnt++;

}

