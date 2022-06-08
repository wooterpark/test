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
* $Name______: HVMCU_Drv.h$
* $Variant___: 0.0.0$
* $Revision__: 0$
* $Author____: XM$
**
**----------------------------------------------------------------------------**
** MAY BE CHANGED BY USER [Yes/No]: No
**----------------------------------------------------------------------------**
** DESCRIPTION:
				implement the Hvmcu communicate with lvMCU
**----------------------------------------------------------------------------**
** HISTORY:
V1.0.0:  Initial version.

*******************************************************************************/
#ifndef HV_MCU_DRIVER_H_
#define HV_MCU_DRIVER_H_

#include "Platform_Types.h"

#define Hv_RUN 0U
#define Hv_RESET 1U
#define Hv_RESTART 2U

#define DMAADICRCFG              (0x04303088U)
#define DMACHCFGRCFG             (0x40100000U)
#define ASCLINRXREG              (0xF0000748U)
#define TX_STARTBIT              (0x80U)
#define RX_STARTBIT              (0x80U)
#define UARTx_TXDATA_NUM         (6U)
#define UARTx_RXDATA_NUM         (8U)
#define UARTx_MUXDATA_NUM        (12U)

#define CNTRMUX_U_TMPE           (0U)
#define CNTRMUX_V_TMPE           (1U)
#define CNTRMUX_W_TMPE           (2U)
#define CNTRMUX_U_EMF_VOL        (3U)
#define CNTRMUX_V_EMF_VOL        (4U)
#define CNTRMUX_W_EMF_VOL        (5U)
#define CNTRMUX_EMERPOWER_VOL    (6U)
#define CNTRMUX_DRIVER_L_VOL     (7U)
#define CNTRMUX_OVERVOL_BASE     (8U)
#define CNTRMUX_DRVBARD_TEMP     (9U)
#define CNTRMUX_SW_VERSION       (10U)
#define CNTRMUX_FAULTCODE1       (11U)

typedef enum
{
	NORM_MODE,
	FLASHBL_MODE,
	ANGLE_MODE,
	DISCHANGE_MODE
}HvMcu_State_E;

typedef uint8 Uart_Division;
typedef uint8 Uart_StayInit;
typedef boolean Uart_Com_Ctrl;

/*******************************************************************************
** Function Name : Std_Bool_Diag
** Parameter[in] : (1)input, (2)limit, (3)count, (4)output
** Parameter[out]: none
** Return Value  : none
** Note          : none
** Description   : Diagnose The Data of Boolean
*******************************************************************************/
#define Std_Bool_Diag(value,limit,count,output) do{\
			if(value)							\
			{									\
				(count)++ ;						\
				if((count) > (limit))			\
				{								\
					(output) = 1;				\
					(count) = limit;			\
				}								\
			}else								\
			{									\
				if((count)>0) (count)--;	    \
			}									\
		}while(0)


typedef struct
{
	uint8 	EmDisChrgFlg;
	uint8   SelfLearingFlg;

	uint8 	TxCntrMsg;
	uint8 	ReqMode;
	uint8	TiTmrPhaCorr;
	uint8	tiDutyDcha;
	uint16	tiPeriod;
	uint8 * const TxBufPtr;
}Uart_Tx_S;

typedef struct
{
	uint8	RxCntrMsg;
	uint8	RspMode;
	uint8 	StOverUdc;
	uint8	TiTmrTxEdg;
	uint8	CrcRec;
	uint16	UdcValue;
	uint16	UdcLoValue;
	uint16* const MuxDataPtr;
	uint8* const RxBufPtr;
}Uart_Rx_S;

typedef struct Uart_Diag_S
{
	uint8 Rx_Fail_Once;
	uint8 RxRecovBeat;
	sint8 HvComErrDbs;
	uint32 FrameCount;
	uint32 ErrorCount;

	uint8  FatIDIndex[16];
}Uart_Diag_S;

typedef struct
{
	Uart_Com_Ctrl Enable;
	Uart_Division Factor;
	Uart_StayInit State;
	Uart_Rx_S Uart_Rx;
	Uart_Tx_S Uart_Tx;
	Uart_Diag_S Uart_Diag;
}HvMcu_Com_S;

typedef struct
{
	uint8 EmDisChrgFlg;
}HvMcu_InPut_S;

typedef struct
{
	uint16 IGBT_Temp_U;
	uint16 IGBT_Temp_V;
	uint16 IGBT_Temp_W;
	uint16 EMF_Voltg_U;
	uint16 EMF_Voltg_V;
	uint16 EMF_Voltg_W;
	uint16 VDD15L_Vol;

	float32 UdcValue;
	float32 UdcLoValue;
	uint16 Sw_Version;
	uint16 DrvBoard_Temp;
}HvMcu_OutPut_S;

extern uint16 Uart_Mux_Data[UARTx_MUXDATA_NUM];
extern HvMcu_Com_S HvMcu_Com;
extern void HvMcu_Com_Init(void);
extern void HvMcu_Com_Uart(const HvMcu_InPut_S* InPtr,HvMcu_OutPut_S* OutPtr);

#endif
