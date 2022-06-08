/*******************************************************************************
**----------------------------------------------------------------------------**
** Copyright (c) 2018 by JEE.		All rights reserved.
** This software is copyright protected and proprietary to JEE.
** JEE grants to you only those rights as set out in the license conditions.
** All other rights remain with JEE.
**----------------------------------------------------------------------------**
**
* Administrative Information
* $Namespace_: \xx\xx$
* $Class_____: C$
* $Name______: HvMcu_Drv.c$
* $Variant___: 0.0.0$
* $Revision__: 0$
* $Author____: XM$
**
**----------------------------------------------------------------------------**
** MAY BE CHANGED BY USER [Yes/No]: yes
**----------------------------------------------------------------------------**
** DESCRIPTION:
           implement the Hvmcu communicate with lvMCU
**----------------------------------------------------------------------------**
** HISTORY:
V1.0.0:Initial version.

*******************************************************************************/
#include "Platform_Types.h"
#include "IfxSrc_reg.h"
#include "IfxDma_reg.h"
#include "IfxDma_regdef.h"
#include "CRC_Verify.h"
#include "HvMcu_Drv.h"
#include "Uart.h"
#include "Dem.h"
#include "Dma.h"
//#include "Dem_Cfg_EventId.h"
//#include "Rte_Dem_Type.h"


/*JEE_MISRA_RULES_1_01 It's Allowed*/
#pragma section ".rodata.Calib_32"
/*JEE_MISRA_RULES_8_04 It's Allowed*/
const volatile float CAL_Hvmcu_DClink_Gain_f32=0.15326f;
const volatile float CAL_Hvmcu_UdcOvLi_Value_f32=600.0f;
const volatile uint16 CAL_Hvmcu_ComErr_Cycle_u16=250u;
const volatile uint16 CAL_Hvmcu_ComErr_Rate_u16=100u;
const volatile sint8 CAL_Hvmcu_ComErr_deb_s8=2u;
/*JEE_MISRA_RULES_1_01 It's Allowed*/
#pragma section

uint16 Uart_Mux_Data[UARTx_MUXDATA_NUM];

static uint8 Uart_Tx_Buffer[UARTx_TXDATA_NUM];
/*JEE_MISRA_RULES_1_01&1_02 It's Allowed*/
uint8 Uart_Rx_Buffer[UARTx_RXDATA_NUM] __attribute__ ((asection(".data.FIFO_UART_BUFFER","f=aw")));
HvMcu_Com_S HvMcu_Com =
{
	FALSE,
	0U,
	FALSE,
	{/*Rx_Data */
		0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U,0x00U, Uart_Mux_Data, Uart_Rx_Buffer
	},
	{/*Tx_Data*/
		FALSE, FALSE, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, Uart_Tx_Buffer
	},
	{/*Diagnose Data*/
		FALSE, Hv_RUN, 0x00, 0x00U, 0x00U,
		{
			DemConf_DemEventParameter_HvMcu_UartLostFrameErr,
			DemConf_DemEventParameter_HvMcu_UartCheckFailErr,
			DemConf_DemEventParameter_HvMcu_UdcCheckErr,
			DemConf_DemEventParameter_HvMcu_DisChrgFreqErr,
			DemConf_DemEventParameter_HvMcu_DisChrgDutyErr,
			DemConf_DemEventParameter_HvMcu_DisChrgFail,
			DemConf_DemEventParameter_HvMcu_EmerPowerSapErr,
			0U,//FJ
			0U,0U,0U,0U,0U,0U,0U,0U
		}
	}
};

static void HvMcu_TxData_Load(Uart_Tx_S* mTx);
static void HvMcu_TxData_Pack(Uart_Tx_S* mTx);
static void HvMcu_RxData_Diag(Uart_Diag_S* mDiag);
static void HvMcu_BERCal_Diag(Uart_Diag_S* mDiag);
static void HvMcu_PostBack_Diag(Uart_Diag_S const * const mDiag);
static void HvMcu_RxData_Unpack(Uart_Rx_S* mRx ,Uart_Diag_S* mDiag);
/*******************************************************************************
** Function Name : HvMcu_TxData_Load
** Parameter[in] : Uart_Tx_S* mTx
** Parameter[out]: none
** Return Value  : void
** Note          : static function
** Description   : Load data to the TxBuffer will be Send.
*******************************************************************************/
static void HvMcu_TxData_Load(Uart_Tx_S* mTx)
{

	if(TRUE == mTx->EmDisChrgFlg)
	{
		mTx->ReqMode = (uint8)DISCHANGE_MODE;
	}
	else if(TRUE == mTx->SelfLearingFlg)
	{
		mTx->ReqMode = (uint8)ANGLE_MODE;
	}
	else
	{
		mTx->ReqMode = (uint8)NORM_MODE;
	}
}

/*******************************************************************************
** Function Name : HvMcu_TxData_Pack
** Parameter[in] : Uart_Tx_S* mTx
** Parameter[out]: none
** Return Value  : void
** Note          : static function
** Description   : Load data to the TxBuffer will be Send.
*******************************************************************************/
static void HvMcu_TxData_Pack(Uart_Tx_S* mTx)
{
	mTx->TxCntrMsg = (mTx->TxCntrMsg + 1u)&0x0Fu;

	mTx->TxBufPtr[0] = (uint8)(TX_STARTBIT      \
							| (mTx->ReqMode<<4U)\
							| (mTx->TxCntrMsg ));

	mTx->TxBufPtr[1] = ((uint8)mTx->tiPeriod &0x7FU);

	mTx->TxBufPtr[2] = (uint8)(mTx->tiPeriod>>7U);

	mTx->TxBufPtr[3] = mTx->tiDutyDcha &0x7FU;

	mTx->TxBufPtr[4] = mTx->TiTmrPhaCorr &0x7FU;

	uint8 CrcLocal = cal_crc_table(mTx->TxBufPtr,5U);

	mTx->TxBufPtr[0] |= ((CrcLocal>>1U) & 0x40U);

	mTx->TxBufPtr[5] = CrcLocal & 0x7FU;
}

/*******************************************************************************
** Function Name : HvMcu_PostBack_Diag
** Parameter[in] : Uart_Diag_S* mDiag
** Parameter[out]: Uart_Diag_S* mDiag
** Return Value  : void
** Note          : static function 10ms
** Description   : Post back Fault Diag.
*******************************************************************************/
static void HvMcu_PostBack_Diag(Uart_Diag_S const * const mDiag)
{
	static uint8 Index = 0x0F;
	float UdcValue_temp;
	if(mDiag->Rx_Fail_Once == FALSE)
	{
		Index = (Index + 1u)&0x0Fu;

		if(((Uart_Mux_Data[CNTRMUX_FAULTCODE1]>>Index)&0x01u)==1u)
		{
			(void)Dem_SetEventStatus(mDiag->FatIDIndex[Index],DEM_EVENT_STATUS_FAILED);
		}

		if(HvMcu_Com.Uart_Rx.StOverUdc==1u)
		{
			(void)Dem_SetEventStatus(DemConf_DemEventParameter_HvMcu_UdcOverVolErr,DEM_EVENT_STATUS_FAILED);
		}
		UdcValue_temp = (float)HvMcu_Com.Uart_Rx.UdcValue*CAL_Hvmcu_DClink_Gain_f32;
		if(UdcValue_temp>CAL_Hvmcu_UdcOvLi_Value_f32)
			(void)Dem_SetEventStatus(DemConf_DemEventParameter_HvMcu_UdcOverFlagLimit,DEM_EVENT_STATUS_PREFAILED);
	}
}

/*******************************************************************************
** Function Name : HvMcu_BERCal_Diag
** Parameter[in] : Uart_Diag_S* mDiag
** Parameter[out]: Uart_Diag_S* mDiag
** Return Value  : void
** Note          : static function
** Description   : Bit Error Rate calculation.
*******************************************************************************/
static void HvMcu_BERCal_Diag(Uart_Diag_S* mDiag)
{
	if(mDiag->FrameCount < CAL_Hvmcu_ComErr_Cycle_u16)
	{
		mDiag->ErrorCount += mDiag->Rx_Fail_Once;
		mDiag->FrameCount++;
	}
	else
	{
		if(mDiag->ErrorCount > CAL_Hvmcu_ComErr_Rate_u16)
		{
			mDiag->RxRecovBeat = Hv_RESET;
			mDiag->HvComErrDbs++;

			if(mDiag->HvComErrDbs > ((sint8)CAL_Hvmcu_ComErr_deb_s8))
			{
				mDiag->HvComErrDbs = CAL_Hvmcu_ComErr_deb_s8;
				(void)Dem_SetEventStatus(DemConf_DemEventParameter_HvMcu_ComErr,DEM_EVENT_STATUS_FAILED);
			}
		}
		else
		{
			mDiag->HvComErrDbs--;
			if(mDiag->HvComErrDbs < ((sint8)0))
			{
				mDiag->HvComErrDbs = 0;
				(void)Dem_SetEventStatus(DemConf_DemEventParameter_HvMcu_ComErr,DEM_EVENT_STATUS_PASSED);
			}
		}
		mDiag->FrameCount = 0;
		mDiag->ErrorCount = 0;
	}
}

/*******************************************************************************
** Function Name : HvMcu_RxData_Diag
** Parameter[in] : Uart_Diag_S* mDiag
** Parameter[out]: Uart_Diag_S* mDiag
** Return Value  : void
** Note          : static function
** Description   : Makesure the Recieve Data Complete.
*******************************************************************************/
static void HvMcu_RxData_Diag(Uart_Diag_S* mDiag)
{
	HvMcu_BERCal_Diag(mDiag);

	switch(mDiag->RxRecovBeat)
	{
		case Hv_RUN:
			(void)Uart_Write(0U,Uart_Tx_Buffer,(Uart_SizeType)UARTx_TXDATA_NUM);
			HvMcu_PostBack_Diag(mDiag);
		break;

		case Hv_RESET:
			/*JEE_MISRA_RULES_11_04 It's Allowed*/
			MODULE_DMA.TSR[32u].B.DCH = 1u;
			MODULE_DMA.TSR[32u].B.RST = 1u;
	
			mDiag->RxRecovBeat = Hv_RESTART;
		break;

		case Hv_RESTART:
			if(MODULE_DMA.TSR[32].B.RST == 0u)
			{	/*JEE_MISRA_RULES_11_04 It's Allowed*/
				MODULE_DMA.CH[32].ADICR.U = DMAADICRCFG;
				MODULE_DMA.CH[32].CHCFGR.U = DMACHCFGRCFG;
				/*JEE_MISRA_RULES_11_03&11_04 It's Allowed*/
				(void)Dma_StartHwTransaction(DMA_CH32, (const uint32*)ASCLINRXREG, (const uint32 *)Uart_Rx_Buffer, UARTx_RXDATA_NUM);

				mDiag->RxRecovBeat = Hv_RUN;
				mDiag->ErrorCount = 0U;
			}
		break;

		default:/*Nothing*/
		break;
	}
}

/*******************************************************************************
** Function Name : HvMcu_RxData_Unpack
** Parameter[in] : Uart_Rx_S* mRx
** Parameter[out]: Uart_Diag_S* mDiag
** Return Value  : void
** Note          : static function
** Description   : Analysis the recieved data in the UART1
*******************************************************************************/
static void HvMcu_RxData_Unpack(Uart_Rx_S* mRx ,Uart_Diag_S* mDiag)
{
	mDiag->Rx_Fail_Once = TRUE;

	if(mRx->RxBufPtr[0] > 0x7FU)
	{
		mRx->CrcRec = (mRx->RxBufPtr[7] | ((mRx->RxBufPtr[6] & 0x40U) << 1U));

		mRx->RxBufPtr[6] &= 0xBFU;

		if(mRx->CrcRec == cal_crc_table(mRx->RxBufPtr, 7U))
		{
			mRx->RxCntrMsg =  mRx->RxBufPtr[0] & 0x0FU;

			mRx->RspMode   = (mRx->RxBufPtr[0] & 0x70U) >> 4U;

			mRx->UdcValue  = ((uint16)mRx->RxBufPtr[1] | ((uint16)mRx->RxBufPtr[2]<<7U)) & 0x0FFFu;

			mRx->MuxDataPtr[mRx->RxCntrMsg] = ((uint16)(mRx->RxBufPtr[3]) | ((uint16)mRx->RxBufPtr[4] <<7U))&0xFFFu;

			mRx->StOverUdc = (mRx->RxBufPtr[4] & 0x20U)>>5U;

			mRx->TiTmrTxEdg = mRx->RxBufPtr[5] & 0x7FU;

			mRx->RxBufPtr[0] = 0U;

			mDiag->Rx_Fail_Once = FALSE;
		}
	}
}

/*******************************************************************************
** Function Name : HV_Mcu_Init
** Parameter[in] : void
** Parameter[out]: void
** Return Value  : void
** Note          : init
** Description   : Init the Data
*******************************************************************************/
void HvMcu_Com_Init(void)
{
	Uart_Tx_S* mTx = &HvMcu_Com.Uart_Tx;
	Uart_Diag_S* mDiag = &HvMcu_Com.Uart_Diag;

	/*JEE_MISRA_RULES_11_04 It's Allowed*/
	SRC_ASCLIN1TX.U   = (0x00050000u);
	SRC_ASCLIN1RX.U   = (0x081E1C20u);
	SRC_ASCLIN1ERR.U  = (0x00140000u);

	mDiag->ErrorCount 	= 0U;
	mDiag->RxRecovBeat	= 0U;
	mTx->SelfLearingFlg = FALSE;
	mTx->ReqMode    = (uint8)NORM_MODE;
	/*JEE_MISRA_RULES_11_03&11_04 It's Allowed*/
	(void)Dma_StartHwTransaction(DMA_CH32,(const uint32*)ASCLINRXREG,\
								(const uint32*)Uart_Rx_Buffer,UARTx_RXDATA_NUM);
	(void)Uart_Read(0U, Uart_Rx_Buffer, 1U);

	HvMcu_Com.State = TRUE;
	HvMcu_Com.Enable = TRUE;
}

/*******************************************************************************
** Function Name : HvMcu_Com_Uart
** Parameter[in] : HvMcu_Com_S* mCom
** Parameter[out]: void
** Return Value  : void
** Note          : 100us
** Description   : NonReentrant
*******************************************************************************/
void HvMcu_Com_Uart(const HvMcu_InPut_S* InPtr,HvMcu_OutPut_S* OutPtr)
{
	HvMcu_Com.Uart_Tx.EmDisChrgFlg = InPtr->EmDisChrgFlg;

	HvMcu_Com.Factor = (HvMcu_Com.Factor + 1U)&0x01U;

	if((HvMcu_Com.Enable & HvMcu_Com.Factor)==1u)
	{
    	HvMcu_RxData_Unpack(&HvMcu_Com.Uart_Rx, &HvMcu_Com.Uart_Diag);

    	HvMcu_TxData_Load(&HvMcu_Com.Uart_Tx);

		HvMcu_TxData_Pack(&HvMcu_Com.Uart_Tx);

		HvMcu_RxData_Diag(&HvMcu_Com.Uart_Diag);

		if(HvMcu_Com.Uart_Diag.Rx_Fail_Once == FALSE)
		{
			OutPtr->IGBT_Temp_U = Uart_Mux_Data[CNTRMUX_U_TMPE];
			OutPtr->IGBT_Temp_V = Uart_Mux_Data[CNTRMUX_V_TMPE];
			OutPtr->IGBT_Temp_W = Uart_Mux_Data[CNTRMUX_W_TMPE];

			OutPtr->EMF_Voltg_U = Uart_Mux_Data[CNTRMUX_U_EMF_VOL];
			OutPtr->EMF_Voltg_V = Uart_Mux_Data[CNTRMUX_V_EMF_VOL];
			OutPtr->EMF_Voltg_W = Uart_Mux_Data[CNTRMUX_W_EMF_VOL];

			OutPtr->VDD15L_Vol = Uart_Mux_Data[CNTRMUX_DRIVER_L_VOL];

			OutPtr->Sw_Version = Uart_Mux_Data[CNTRMUX_SW_VERSION];
			OutPtr->DrvBoard_Temp = Uart_Mux_Data[CNTRMUX_DRVBARD_TEMP];
			OutPtr->UdcValue = (float)HvMcu_Com.Uart_Rx.UdcValue*CAL_Hvmcu_DClink_Gain_f32;

			HvMcu_Com.State = FALSE;
		}
		else
		{
			if(HvMcu_Com.State == TRUE)
			{
				OutPtr->IGBT_Temp_U = 2200U;
				OutPtr->IGBT_Temp_V = 2200U;
				OutPtr->IGBT_Temp_W = 2200U;
				OutPtr->DrvBoard_Temp = 2200U;
			}
		}
	}
}
