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
#ifndef IGBTDRV_H
#define IGBTDRV_H

/*******************************************************************************
**                      Other Header File Inclusion                           **
*******************************************************************************/
#include "IgbtDrv_Cfg.h"

/*******************************************************************************
**                          Macro Definition                         		  **
*******************************************************************************/
/* Read Command */
#define CMD_READ_REQUEST(address) 			(  (uint16)( (uint16)(address)<<7U )  | (uint16)(0x2AU) )

/* WriteL Command */
#define CMD_WRITEL_REQUEST(address,data) 	( (uint16)0xA000 |  (uint16)((uint16)(address) << 7U) |  (uint16)( (uint16)( ( (uint16)(data) & (uint16)0x00FCU)>> 2U )<< 1U )  )

/* WriteH Command */
#define CMD_WRITEH_REQUEST(data) 			( (uint16)0x4400 | ( (uint16)( ( ( (uint16)(data)&0xFF00U ) >> 8U ) << 1U ) ) )

/* NOP Command */
#define CMD_NOP 							0x1410U

/* ENTER_CMODE Command */
#define CMD_ENTER_CMODE 					0x1880U

/* EXIT_CMODE Command */
#define CMD_EXIT_CMODE 						0x1220U

/*Enter Verification Mode*/
#define CMD_ENTER_VMODE						0x1140U

/*f_ssosc2 in MHz from Datasheet*/
#define SSOSC2_MHZ							17.1F

#define IGBTDRV_V18_MIN_F32					13.2F

/**/
#define  IgbtDrv_GetSetMask(Value, Mask, BitPos)\
								(((uint16)(Value) & (uint16)(Mask))<<(BitPos))
#define  IgbtDrv_GetClearMask(Value, Mask, BitPos)\
								(((uint16)(~(uint16)(Value)) & (uint16)(Mask))<<(BitPos))


/*******************************************************************************
**                          Typedef Definition                         		  **
*******************************************************************************/
typedef struct {
	uint8 flgGateDrvRdyHs_u8;
	uint8 flgGateDrvRdyLs_u8;
} IgbtDrvRdyOutIFType;


/*******************************************************************************
**                     Global Variables Definition              		      **
*******************************************************************************/
extern uint8 IgbtDrv_AppCtrlCmd_u8 ;
extern uint8 IgbtDrv_AppWorkReady_u8 ;
extern uint8 IgbtDrv_AppFaultType_u8 ;
extern uint8 VAR_Igbt_Normal_State_u16;

extern const IgbtDrv_HWCfgType IgbtDrv_HWCfg_cst ;

extern Dio_LevelType  VAR_IgbtDrv_Level_NRST_RDY_u8, VAR_IgbtDrv_Level_NRST_RDY_L_u8;
extern Dio_LevelType  VAR_IgbtDrv_Level_NFLTA_u8, VAR_IgbtDrv_Level_NFLTA_L_u8;
extern Dio_LevelType  VAR_IgbtDrv_Level_NFLTB_u8, VAR_IgbtDrv_Level_NFLTB_L_u8;

/*******************************************************************************
**                 		    Function extern             		              **
*******************************************************************************/
extern void IgbtDrv_init(const IgbtDrv_HWCfgType *arg_HWCfg_pst);

extern void IgbtDrv_StateManagement (IgbtDrvRdyOutIFType* out);

extern void IgbtDrv_10ms_MainFunction(void);

/*******************************************************************************
** Function Name	: SpiSeqxEndNotification
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: Spi Driver Notification.
*******************************************************************************/
extern void SpiSeq0EndNotification(void);

extern void SpiSeq1EndNotification(void);

extern void SpiSeq2EndNotification(void);

extern void SpiSeq3EndNotification(void);

extern void SpiSeq6EndNotification(void);

extern void SpiSeqCddIgbtDrv_RdConfEndNotification(void);


extern void SpiSeqCddIgbtDrv_RdConf2EndNotification(void);



#endif
