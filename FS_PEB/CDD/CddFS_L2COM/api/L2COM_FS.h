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
* $Name______: L2COM_FS.h$
* $Variant___: 0.0.0$
* $Revision__: 1.0$
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
#ifndef L2COM_FS_H_
#define L2COM_FS_H_

#include"Platform_Types.h";
#include "set_get_data.h"
#include "Com_Cfg.h"
/*******************************************************************************
**                          Macro Definition                         		  **
*******************************************************************************/
//#define FRP_STM_UINTNDSPDERR_MASK                  0x02U



/*******************************************************************************
**                          Typedef Definition                         		  **
*******************************************************************************/



/*******************************************************************************
**                     Global Variables Definition              		      **
*******************************************************************************/
extern uint8 VAR_RollCntRx_MCU_430_u8;
extern uint8 VAR_CheckSumTx_MCU_430_u8;
extern uint32 VAR_FRP_AppFaultInfo_u32;

/*******************************************************************************
**                        Global Function Prototypes              	    	  **
*******************************************************************************/

extern void FS_FltInfoCom_Report(void);

#endif
