/*====================================================================================================================*/
/*  
 *  @Copyright (C) 2019, 上海知从科技有限公司       Shanghai ZC Technology Co., Ltd.               All rights reserved.
 *  
 *               This software is copyright protected and proprietary to Shanghai ZC Technology Co., Ltd.
 *               Shanghai ZC Technology Co., Ltd. grants to you only those rights as set out in the license conditions.
 *               All other rights remain with  Shanghai ZC Technology Co., Ltd.
 */               
/**********************************************************************************************************************/
/* 			
 *	@file		<TLF35584ErrHdl.h>
 *	@brief		<实现TLF35584驱动模块故障处理>
 *	
 *	<Compiler: HighTec GNU v4.9.4.0    MCU:TC39x>
 *	
 *	@author 	<谢江>
 *	@date		<2021-03-11>
 */
/*====================================================================================================================*/


/*====================================================================================================================*/
/*  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author          Change Id       Description
 *  01.00.00   2021-03-11  谢江                  -           创建.
 *  01.01.00   2021-06-04  谢江                  -           1.修改模块名
 *  01.02.00   2021-09-28  谢江                  -           Fix the problem of INMISSS failure reporting
 *                                                           Delete SCU_TRAPCLR.B.ESR1T operation
 *  --------------------------------------------------------------------------------------------------------------------
 */
/*====================================================================================================================*/
 
 
#ifndef  _TLF35584ERRHDL_H
#define  _TLF35584ERRHDL_H

/*====================================================================================================================*/
/*                                                     Includes                                                       */
/*====================================================================================================================*/
#include "Std_Types.h"

/*====================================================================================================================*/
/*                                                 Macro Definitions                                                  */
/*====================================================================================================================*/

#define TLF35584ERRHDL_FAULT_COUNT                     (65u)				  /* Define Fault Count in xlsx */
#define TLF35584ERRHDL_MAX_ADDRESS                     (0x3Fu)                /* Define Max Register Address */


/*====================================================================================================================*/
/*                                                Typedef Definitions                                                 */
/*====================================================================================================================*/
/* define function pointer type TstM_FuncPtrType */
typedef void (*TLF35584ErrHdl_PtrType)(void);

/* Define Fault Code for Every Fault. */
typedef enum
{
	TLF35584ErrHdl_Fault_None = 0x00U,
	TLF35584ErrHdl_Fault_Success = 0x01U,
	TLF35584ErrHdl_Fault_Error = 0x02U,
	TLF35584ErrHdl_Fault_Clear = 0x03U
}TLF35584ErrHdl_FaultCodeType;


/* Define Fault Source for Every Fault. */
typedef enum
{
	TLF35584ErrHdl_Fault_S_None = 0x00U,
	TLF35584ErrHdl_Fault_S_IRQ = 0x01U,
	TLF35584ErrHdl_Fault_S_Reset = 0x02U,
	TLF35584ErrHdl_Fault_S_User = 0x03U,
}TLF35584ErrHdl_FaultSrcType;

/* Define Fault Info for Every Fault */
typedef struct
{
	uint8 Fault_ID;
	TLF35584ErrHdl_FaultCodeType Fault_Status;
	TLF35584ErrHdl_FaultSrcType Fault_Source;
}TLF35584ErrHdl_FaultInfoType;

typedef struct
{
	boolean Sys_Status;
	uint8 Error_Count ;
	TLF35584ErrHdl_FaultInfoType Fault_List[TLF35584ERRHDL_FAULT_COUNT];
}TLF35584ErrHdl_FaultStsType;

typedef struct
{
	uint8 Fault_ID;
	uint8 Register_ID;
	uint8 Shift_Count;
	uint8 Bit_Count;
	uint8 RightValue;
}TLF35584ErrHdl_FaultType;

typedef struct
{
	uint8 Fault_Count;
	TLF35584ErrHdl_FaultType** Fault_List;

}TLF35584ErrHdl_GroupType;

typedef struct
{
	boolean Enable;
	TLF35584ErrHdl_PtrType Callback_Ptr;
}TLF35584ErrHdl_ConfigType;

/*====================================================================================================================*/
/*                                           Global Variable Declarations                                             */
/*====================================================================================================================*/

extern TLF35584ErrHdl_FaultStsType TLF35584ErrHdl_Status;

extern const TLF35584ErrHdl_GroupType TLF35584ErrHdl_Group;

/*====================================================================================================================*/
/*                                           Global Function Declarations                                             */
/*====================================================================================================================*/
extern void TLF35584ErrHdl_Init(void);
extern void TLF35584ErrHdl_DeInit(void);
extern void TLF35584ErrHdl_SetHandlerFlag(TLF35584ErrHdl_FaultSrcType Source);
extern void TLF35584ErrHdl_IRQHandler(void);
extern Std_ReturnType TLF35584ErrHdl_MainFunction(void);

#endif
