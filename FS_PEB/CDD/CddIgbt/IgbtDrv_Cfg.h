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

#ifndef IGBTDRV_CFG_H
#define IGBTDRV_CFG_H
/*******************************************************************************
**                      Other Header File Inclusion                           **
*******************************************************************************/
#include "IgbtDrv_Types.h"
#include "Cdd_Infra_Cfg.h"
#if (_CDD_SIMULATION == STD_OFF)
#include "IgbtDrv_regdef.h"
#include "Dio.h"
#include "spi.h"
#include "IfxStm_reg.h"
#include "LvPower_Drv.h"
#include "Cpld_Drv.h"
#include "Dem.h"
#endif
/*******************************************************************************
**                          Macro Definition                         		  **
*******************************************************************************/
#define		IGBTDRV_DEM_USED				STD_OFF 	/*STD_ON: Dem Enabled; STD_OFF: Dem not used*/
#define		TEST_DOUBLE_PULSE				STD_ON
#define		TEST_ON_1EDI2010AS				STD_OFF		/*STD_ON: Test on 1edi2010as*/
#define 	BIT8_ACCESS						0U
#define 	BIT16_ACCESS					1U
#define 	IGBTDRV_NUM_OF_CHIPS 			6U			/*Number of 1EDi2002 chips*/
#define 	IGBTDRV_NUM_OF_REG   			28U			/*Number of 1EDi2002'S chips Register*/
#define 	IGBTDRV_NUM_OF_CFGREG   		8U			/*Number of 1EDi2002'S chips Register to Cfg*/
#define 	IGBTDRV_NUM_OF_REGSTATUS        11u
#define 	IGBTDRV_NUM_OF_REGCONF          15u
#define 	IGBTDRV_NUM_OF_Seq0     		14u
#define 	IGBTDRV_NUM_OF_SeqRdConf    	16u

#define 	IGBTDRV_INITERR_AUTO_RST_LIMIT   10u
#define 	IGBTDRV_CTRL_RST_CMD    	     5u

/* Pin Configuration */
#define		PIN_EN								DIO_CHANNEL_11_5 	/* EN Pin*/
#define		PIN_EN_L							DIO_CHANNEL_13_2 	/* EN Pin Low Side*/
#define		PIN_NRST_RDY						DIO_CHANNEL_11_7 	/* NRST/RDY Pin*/
#define		PIN_NRST_RDY_L						DIO_CHANNEL_11_12 	/* NRST/RDY Pin Low Side*/
#define		PIN_NRST_RDY_IN						DIO_CHANNEL_11_1 	/* NRST/RDY Pin*/
#define		PIN_NRST_RDY_L_IN					DIO_CHANNEL_10_4 	/* NRST/RDY Pin Low Side*/
#define		PIN_NFLTB_IN						DIO_CHANNEL_12_1 	/*Fault B*/
#define		PIN_NFLTA_IN						DIO_CHANNEL_11_4 	/*Fault A*/
#define		PIN_NFLTB_L_IN						DIO_CHANNEL_14_8 	/*Fault B Low Side*/
#define		PIN_NFLTA_L_IN						DIO_CHANNEL_13_3 	/*Fault A Low Side*/
#define		CDDIGBTDRV_ADCV18_GAIN_F32			0.1390F

/* Register Initialization Value */
#define		IGBTDRV_VALUE_PID			0x0000U
#define 	IGBTDRV_VALUE_PSTAT 		0x087DU
#define 	IGBTDRV_VALUE_PSTAT2 		0x0010U
#define 	IGBTDRV_VALUE_PER 			0x1C00u
#define 	IGBTDRV_VALUE_PCFG 			0x000Cu /*8-bit register*/
#define 	IGBTDRV_VALUE_PCFG2			0x205u
#define 	IGBTDRV_VALUE_PCTRL 		0x06u /*8-bit register*/
#define 	IGBTDRV_VALUE_PCTRL2 		0x07u /*8-bit register*/
#define 	IGBTDRV_VALUE_PSCR 			0x08u /*8-bit register*/
#define 	IGBTDRV_VALUE_PRW 			0x09u
#define 	IGBTDRV_VALUE_PPIN 			0x0Au
#define 	IGBTDRV_VALUE_PCS 			0x0Bu
#define 	IGBTDRV_VALUE_SID 			0x10u
#define 	IGBTDRV_VALUE_SSTAT 		0x11u
#define 	IGBTDRV_VALUE_SSTAT2 		0x12u
#define 	IGBTDRV_VALUE_SER 			0x13u
#define 	IGBTDRV_VALUE_SCFG 			0x00B1u
#define 	IGBTDRV_VALUE_SCFG2 		0x2020u
#define 	IGBTDRV_VALUE_SCTRL 		0x16u
#define 	IGBTDRV_VALUE_SSCR 			0x17u 		/*8-bit register*/
#define 	IGBTDRV_VALUE_SDESAT 		0x1101u
#define 	IGBTDRV_VALUE_SOCP 			0x19u
#define 	IGBTDRV_VALUE_SRTTOF 		0x0001u
#define 	IGBTDRV_VALUE_SGM1 			0x1Cu
#define 	IGBTDRV_VALUE_SGM2 			0x1Du
#define 	IGBTDRV_VALUE_SSTTOF 		0x1140u
#define 	IGBTDRV_VALUE_SACLT 		0xFF01u
#define 	IGBTDRV_VALUE_SCS 			0x1Fu

/*******************************************************************************
**                 		  typedef       		                              **
*******************************************************************************/
typedef	struct
{
	 IgbtDrv_RegStatusType     *IgbtDrv_RegStatus;
	 IgbtDrv_RegStatusType     *IgbtDrv_RegConf;
	 const IgbtDrv_RegCfgType  *IgbtDrv_RegCfg;

}IgbtDrv_HWCfgType;

/*******************************************************************************
**                 		  Function extern       		                      **
*******************************************************************************/
extern void IgbtDrv_WrReg8 (uint16 addr, uint16 data, boolean isSync);
extern void IgbtDrv_WrReg16(uint16 addr, uint16 data, boolean isSync);

#endif
