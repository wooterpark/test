/*====================================================================================================================*/
/*  
 *  @Copyright (C) 2019, �Ϻ�֪�ӿƼ����޹�˾       Shanghai ZC Technology Co., Ltd.               All rights reserved.
 *  
 *               This software is copyright protected and proprietary to Shanghai ZC Technology Co., Ltd.
 *               Shanghai ZC Technology Co., Ltd. grants to you only those rights as set out in the license conditions.
 *               All other rights remain with  Shanghai ZC Technology Co., Ltd.
 */               
/**********************************************************************************************************************/
/*
 * �汾��Ϣ�ο�: TLF35584ErrHdl.h
 */
/*====================================================================================================================*/


/*====================================================================================================================*/
/*                                                     Includes                                                       */
/*====================================================================================================================*/
#include "TLF35584ErrHdl.h"
#include "TLF35584ErrHdl_Cfg.h"
#include "TLF35584.h"
#include "IfxScu_reg.h"

/*====================================================================================================================*/
/*                                                 Macro Definitions                                                  */
/*====================================================================================================================*/

#define TLF35584ERRHDL_FAULT_IF_INTMISS_ID   1u

#define TLF35584ERRHDL_READ_REG_NUMBER        12u
/*====================================================================================================================*/
/*                                                Typedef Definitions                                                 */
/*====================================================================================================================*/

/*====================================================================================================================*/
/*                                            Private Variable Definitions                                            */
/*====================================================================================================================*/


static boolean TLF35584ErrHdl_StartupCheckFlag = FALSE;	/* TLF35584���ϼ��ģ���ϵ�״̬����־λ */

static boolean TLF35584ErrHdl_InitFinishFlag = FALSE;	/* TLF35584���ϼ��ģ���ʼ��״̬��־λ */

static TLF35584ErrHdl_FaultSrcType TLF35584ErrHdl_HandlerFlag = TLF35584ErrHdl_Fault_S_None;	/* TLF35584���ϼ������ʱ����־λ */

static uint8 TLF35584ErrHdl_Reg[TLF35584ERRHDL_MAX_ADDRESS];	/* TLF35584���ϼ��Ĵ����洢���� */

/*====================================================================================================================*/
/*                                            Global Variable Definitions                                             */
/*====================================================================================================================*/

TLF35584ErrHdl_FaultStsType TLF35584ErrHdl_Status;	/* TLF35584���ϼ��״̬�洢���� */

/* QAC Annotation�������±�Ӧ����ָ�����͵Ķ��󣻶�д�Ĵ��� */
/* PRQA S 491,303 EOF*/
const TLF35584ErrHdl_GroupType TLF35584ErrHdl_Group =
{
	TLF35584ERRHDL_FAULT_COUNT,
	TLF35584ErrHdl_FaultList/*PRQA S 674*/ /* QAC Annotation�����ú���ʹ�� */
};

/*====================================================================================================================*/
/*                                            Private Function Declarations                                           */
/*====================================================================================================================*/

static boolean TLF35584ErrHdl_GetStartupCheckFlag(void);
static void TLF35584ErrHdl_SetStartupCheckFlag(boolean flag);
static void TLF35584ErrHdl_ClrStartupCheckFlag(void);
static void TLF35584ErrHdl_SetInitFinishFlag(void);
static boolean TLF35584ErrHdl_GetInitFinishFlag(void);
static void TLF35584ErrHdl_ClrInitFinishFlag(void);
static Std_ReturnType TLF35584ErrHdl_FaultClr(uint8 FaultID);
static Std_ReturnType TLF35584ErrHdl_FaultRead(void);
static Std_ReturnType TLF35584ErrHdl_FaultParse(uint8 FaultID);
static Std_ReturnType TLF35584ErrHdl_FaultCheck(uint8 FaultID);
static TLF35584ErrHdl_FaultSrcType TLF35584ErrHdl_GetHandlerFlag(void);
static void TLF35584ErrHdl_ClrHandlerFlag(void);
static uint8 TLF35584ErrHdl_GetErrRegValue(uint8 RegisterID);
static void TLF35584ErrHdl_SetErrRegValue(uint8 RegisterID, uint8 Value);
static void TLF35584ErrHdl_ClrErrRegValue(uint8 RegisterID);
static void TLF35584ErrHdl_ClrInfo(void);

/*====================================================================================================================*/
/*                                            Private Function Implementation                                         */
/*====================================================================================================================*/
/**********************************************************************************************************************/
/*
 * FunctionName        : static boolean TLF35584ErrHdl_GetStartupCheckFlag(void)
 * Service ID          : [SWDD-17-006]
 * Sync/Async          : Synchronous
 * Reentrancy          : Non-reentrant
 * Param-Name[in]      : None
 * Param-Name[out]     : None
 * Param-Name[in/out]  : None
 * Return              : None
 * CallByAPI           : None
 * Description         : �˺������ڻ�ȡ�ϵ�������־λ��
 */
/**********************************************************************************************************************/
static boolean TLF35584ErrHdl_GetStartupCheckFlag(void)/* PRQA S 3219 */ /* QAC Annotation:Ԥ���������� */
{
	return TLF35584ErrHdl_StartupCheckFlag;
}

/**********************************************************************************************************************/
/*
 * FunctionName        : static void TLF35584ErrHdl_SetStartupCheckFlag(boolean flag)
 * Service ID          : [SWDD-17-007]
 * Sync/Async          : Synchronous
 * Reentrancy          : Non-reentrant
 * Param-Name[in]      : flag
 * Param-Name[out]     : None
 * Param-Name[in/out]  : None
 * Return              : None
 * CallByAPI           : None
 * Description         : �˺������������ϵ�������־λ��
 */
/**********************************************************************************************************************/
static void TLF35584ErrHdl_SetStartupCheckFlag(boolean flag)
{
	TLF35584ErrHdl_StartupCheckFlag = flag;
}

/**********************************************************************************************************************/
/*
 * FunctionName        : static void TLF35584ErrHdl_ClrStartupCheckFlag(void)
 * Service ID          : [SWDD-17-008]
 * Sync/Async          : Synchronous
 * Reentrancy          : Non-reentrant
 * Param-Name[in]      : None
 * Param-Name[out]     : None
 * Param-Name[in/out]  : None
 * Return              : None
 * CallByAPI           : None
 * Description         : �˺�����������ϵ�������־λ��
 */
/**********************************************************************************************************************/
static void TLF35584ErrHdl_ClrStartupCheckFlag(void)
{
	TLF35584ErrHdl_StartupCheckFlag = FALSE;
}


/**********************************************************************************************************************/
/*
 * FunctionName        : static TLF35584ErrHdl_FaultSrcType TLF35584ErrHdl_GetHandlerFlag()
 * Service ID          : [SWDD-17-009]
 * Sync/Async          : Synchronous
 * Reentrancy          : Non-reentrant
 * Param-Name[in]      : None
 * Param-Name[out]     : None
 * Param-Name[in/out]  : None
 * Return              : None
 * CallByAPI           : None
 * Description         : �˺������ڻ�ȡ����Դ��־λ��
 */
/**********************************************************************************************************************/
static TLF35584ErrHdl_FaultSrcType TLF35584ErrHdl_GetHandlerFlag(void)
{
	return TLF35584ErrHdl_HandlerFlag;
}

/**********************************************************************************************************************/
/*
 * FunctionName        : static TLF35584ErrHdl_FaultSrcType TLF35584ErrHdl_ClrHandlerFlag()
 * Service ID          : [SWDD-17-010]
 * Sync/Async          : Synchronous
 * Reentrancy          : Non-reentrant
 * Param-Name[in]      : None
 * Param-Name[out]     : None
 * Param-Name[in/out]  : None
 * Return              : None
 * CallByAPI           : None
 * Description         : �˺��������������Դ��־λ��
 */
/**********************************************************************************************************************/
static void TLF35584ErrHdl_ClrHandlerFlag(void)
{
  TLF35584ErrHdl_HandlerFlag = TLF35584ErrHdl_Fault_S_None;
}

/**********************************************************************************************************************/
/*
 * FunctionName        : static uint8 TLF35584ErrHdl_GetErrRegValue(uint8 RegisterID)
 * Service ID          : [SWDD-17-011]
 * Sync/Async          : Synchronous
 * Reentrancy          : Non-reentrant
 * Param-Name[in]      : None
 * Param-Name[out]     : None
 * Param-Name[in/out]  : None
 * Return              : None
 * CallByAPI           : None
 * Description         : �˺������ڻ�ȡ����Ĵ������ش洢���ݡ�
 */
/**********************************************************************************************************************/
static uint8 TLF35584ErrHdl_GetErrRegValue(uint8 RegisterID)
{
	uint8 L_Value;
	if(RegisterID < TLF35584ERRHDL_MAX_ADDRESS)
	{
		L_Value =  TLF35584ErrHdl_Reg[RegisterID];
	}
	else
	{
		L_Value =  0u;
	}
	
	return L_Value;
}/*PRQA S 2006*/ /* QAC Annotation����ͬ����ֵ����ͬһͨ���� */

/**********************************************************************************************************************/
/*
 * FunctionName        : static void TLF35584ErrHdl_SetErrRegValue(uint8 RegisterID, uint8 Value)
 * Service ID          : [SWDD-17-012]
 * Sync/Async          : Synchronous
 * Reentrancy          : Non-reentrant
 * Param-Name[in]      : None
 * Param-Name[out]     : None
 * Param-Name[in/out]  : None
 * Return              : None
 * CallByAPI           : None
 * Description         : �˺����������ô���Ĵ������ش洢���ݡ�
 */
/**********************************************************************************************************************/
static void TLF35584ErrHdl_SetErrRegValue(uint8 RegisterID, uint8 Value)
{
	if(RegisterID < TLF35584ERRHDL_MAX_ADDRESS)
	{
		TLF35584ErrHdl_Reg[RegisterID] = Value;
	}
	else
	{
		
	}
}

/**********************************************************************************************************************/
/*
 * FunctionName        : static void TLF35584ErrHdl_ClrErrRegValue(uint8 RegisterID)
 * Service ID          : [SWDD-17-013]
 * Sync/Async          : Synchronous
 * Reentrancy          : Non-reentrant
 * Param-Name[in]      : None
 * Param-Name[out]     : None
 * Param-Name[in/out]  : None
 * Return              : None
 * CallByAPI           : None
 * Description         : �˺��������������Ĵ������ش洢���ݡ�
 */
/**********************************************************************************************************************/
static void TLF35584ErrHdl_ClrErrRegValue(uint8 RegisterID)/*PRQA S 3219*/ /* QAC Annotation����Ҫʱ��ʹ�� */
{
	if(RegisterID < TLF35584ERRHDL_MAX_ADDRESS)
	{
		TLF35584ErrHdl_Reg[RegisterID] = 0u;
	}
	else
	{
		
	}
}

/**********************************************************************************************************************/
/*
 * FunctionName        : static void TLF35584ErrHdl_SetInitFinishFlag(void)
 * Service ID          : [SWDD-17-014]
 * Sync/Async          : Synchronous
 * Reentrancy          : Non-reentrant
 * Param-Name[in]      : None
 * Param-Name[out]     : None
 * Param-Name[in/out]  : None
 * Return              : None
 * CallByAPI           : None
 * Description         : �˺����������ó�ʼ����׼λ��
 */
/**********************************************************************************************************************/
static void TLF35584ErrHdl_SetInitFinishFlag(void)
{
	TLF35584ErrHdl_InitFinishFlag = TRUE;
}

/**********************************************************************************************************************/
/*
 * FunctionName        : static boolean TLF35584ErrHdl_GetInitFinishFlag(void)
 * Service ID          : [SWDD-17-015]
 * Sync/Async          : Synchronous
 * Reentrancy          : Non-reentrant
 * Param-Name[in]      : None
 * Param-Name[out]     : None
 * Param-Name[in/out]  : None
 * Return              : None
 * CallByAPI           : None
 * Description         : �˺������ڻ�ȡ��ʼ��״̬��
 */
/**********************************************************************************************************************/
static boolean TLF35584ErrHdl_GetInitFinishFlag(void)
{
	return TLF35584ErrHdl_InitFinishFlag;
}

/**********************************************************************************************************************/
/*
 * FunctionName        : static void TLF35584ErrHdl_ClrInitFinishFlag(void)
 * Service ID          : [SWDD-17-016]
 * Sync/Async          : Synchronous
 * Reentrancy          : Non-reentrant
 * Param-Name[in]      : None
 * Param-Name[out]     : None
 * Param-Name[in/out]  : None
 * Return              : None
 * CallByAPI           : None
 * Description         : �˺������������ʼ����־λ��
 */
/**********************************************************************************************************************/
static void TLF35584ErrHdl_ClrInitFinishFlag(void)
{
	TLF35584ErrHdl_InitFinishFlag = FALSE;
}

/**********************************************************************************************************************/
/*
 * FunctionName        : static Std_ReturnType TLF35584ErrHdl_FaultClr(uint8 FaultID)
 * Service ID          : [SWDD-17-017]
 * Sync/Async          : Synchronous
 * Reentrancy          : Non-reentrant
 * Param-Name[in]      : None
 * Param-Name[out]     : None
 * Param-Name[in/out]  : None
 * Return              : None
 * CallByAPI           : None
 * Description         : �˺����������TLF35584����״̬��
 */
/**********************************************************************************************************************/
static Std_ReturnType TLF35584ErrHdl_FaultClr(uint8 FaultID)
{
	Std_ReturnType Ret;
	uint8 L_RegValue;
	TLF35584_CmdType TempReg;

	L_RegValue = (1u << TLF35584ErrHdl_Group.Fault_List[FaultID]->Shift_Count);

	TempReg.ReqCmd = TLF35584ErrHdl_Group.Fault_List[FaultID]->Register_ID;
	TempReg.UserData = L_RegValue;

	Ret = TLF35584_Write(&TempReg, 1U);/*PRQA S 3335,3757*/ /* QAC Annotation��ǿ��ת������ */

	return Ret;

}

/**********************************************************************************************************************/
/*
 * FunctionName        : static Std_ReturnType TLF35584ErrHdl_FaultRead(void)
 * Service ID          : [SWDD-17-018]
 * Sync/Async          : Synchronous
 * Reentrancy          : Non-reentrant
 * Param-Name[in]      : None
 * Param-Name[out]     : None
 * Param-Name[in/out]  : None
 * Return              : None
 * CallByAPI           : None
 * Description         : �˺������ڻ�ȡ����Ĵ���ֵ��
 */
/**********************************************************************************************************************/
static Std_ReturnType TLF35584ErrHdl_FaultRead(void)
{
	uint8 u8_Index;
	Std_ReturnType Ret;
	TLF35584_CmdType TempReg[TLF35584ERRHDL_READ_REG_NUMBER] =
		{
			{TLF35584_REG_IF, 0x00},
			{TLF35584_REG_OTFAIL, 0x00},
			{TLF35584_REG_OTWRNSF, 0x00},
			{TLF35584_REG_MONSF0, 0x00},
			{TLF35584_REG_MONSF1, 0x00},
			{TLF35584_REG_MONSF2, 0x00},
			{TLF35584_REG_MONSF3, 0x00},
			{TLF35584_REG_SPISF, 0x00},
			{TLF35584_REG_SYSFAIL, 0x00},
			{TLF35584_REG_SYSSF, 0x00},
			{TLF35584_REG_INITERR, 0x00},
			{TLF35584_REG_WKSF, 0x00},
		};

	Ret = TLF35584_Read(&TempReg[0], TLF35584ERRHDL_READ_REG_NUMBER);/*PRQA S 3335,3757*/ /* QAC Annotation��ǿ��ת������ */
	if(Ret == E_OK)
	{
		for(u8_Index = 0u;u8_Index < TLF35584ERRHDL_READ_REG_NUMBER;u8_Index++)
		{
			TLF35584ErrHdl_SetErrRegValue(TempReg[u8_Index].ReqCmd, TempReg[u8_Index].UserData);
		}
	}
	else
	{
		/* Do nothing */
	}

	
	return Ret;
	
}

/**********************************************************************************************************************/
/*
 * FunctionName        : static Std_ReturnType TLF35584ErrHdl_FaultParse(uint8 FaultID)
 * Service ID          : [SWDD-17-019]
 * Sync/Async          : Synchronous
 * Reentrancy          : Non-reentrant
 * Param-Name[in]      : FaultID
 * Param-Name[out]     : None
 * Param-Name[in/out]  : None
 * Return              : None
 * CallByAPI           : None
 * Description         : �˺������ڽ�����ȡ��״̬�Ĵ�����־λ��
 */
/**********************************************************************************************************************/
static Std_ReturnType TLF35584ErrHdl_FaultParse(uint8 FaultID)
{
	uint8 L_RegValue;
	uint8 L_ShiftCount;
	uint8 L_RightValue;
	uint8 L_Mask;
	Std_ReturnType Ret;

	/* Call API Get TLF35584 Reg Vaule. */
	L_RegValue = TLF35584ErrHdl_GetErrRegValue(TLF35584ErrHdl_Group.Fault_List[FaultID]->Register_ID);

	L_ShiftCount = TLF35584ErrHdl_Group.Fault_List[FaultID]->Shift_Count;
	L_Mask = TLF35584ErrHdl_Group.Fault_List[FaultID]->Bit_Count;
	L_RightValue = TLF35584ErrHdl_Group.Fault_List[FaultID]->RightValue;
	
	Ret = (((L_RegValue >> L_ShiftCount) & L_Mask) == L_RightValue) ? (E_OK) : (E_NOT_OK);

	return Ret;
}

/**********************************************************************************************************************/
/*
 * FunctionName        : static Std_ReturnType TLF35584ErrHdl_FaultCheck(uint8 FaultID)
 * Service ID          : [SWDD-17-020]
 * Sync/Async          : Synchronous
 * Reentrancy          : Non-reentrant
 * Param-Name[in]      : None
 * Param-Name[out]     : None
 * Param-Name[in/out]  : None
 * Return              : None
 * CallByAPI           : None
 * Description         : �˺���ʵ�ִ���Check���ܣ�����Ƿ𻹴��ڹ��ϡ�
 */
/**********************************************************************************************************************/
static Std_ReturnType TLF35584ErrHdl_FaultCheck(uint8 FaultID)
{
	Std_ReturnType Ret;
	uint8 L_ShiftCount;
	uint8 L_RightValue;
	uint8 L_Mask;
	TLF35584_CmdType TempReg[1U];

	TempReg[0u].ReqCmd = TLF35584ErrHdl_Group.Fault_List[FaultID]->Register_ID;	/*PRQA S 3138*//* QAC Annotation��no effect*/
	TempReg[0u].UserData = (uint8)0U;
	/* Call TLF35584 Read Fault API. */
	Ret = TLF35584_Read(TempReg, 1u);/*PRQA S 3335,3757*/ /* QAC Annotation��ǿ��ת������ */

	if(Ret == E_OK)
	{
		L_ShiftCount = TLF35584ErrHdl_Group.Fault_List[FaultID]->Shift_Count;
		L_Mask = TLF35584ErrHdl_Group.Fault_List[FaultID]->Bit_Count;
		L_RightValue = TLF35584ErrHdl_Group.Fault_List[FaultID]->RightValue;
		
		Ret = (((TempReg[0u].UserData >> L_ShiftCount) & L_Mask) == L_RightValue) ? (E_OK) : (E_NOT_OK);
	}
	else
	{

	}

	return Ret;
}

/**********************************************************************************************************************/
/*
 * FunctionName        : static void TLF35584ErrHdl_ClrInfo(void)
 * Service ID          : [SWDD-17-021]
 * Sync/Async          : Synchronous
 * Reentrancy          : Non-reentrant
 * Param-Name[in]      : None
 * Param-Name[out]     : None
 * Param-Name[in/out]  : None
 * Return              : None
 * CallByAPI           : None
 * Description         : �˺���ʵ�����������Ϣ���ܡ�
 */
/**********************************************************************************************************************/
static void TLF35584ErrHdl_ClrInfo(void)
{
	uint8 u8_Index;

	TLF35584ErrHdl_Status.Sys_Status = TRUE;
	TLF35584ErrHdl_Status.Error_Count = 0u;

	for(u8_Index = 0u; u8_Index < TLF35584ErrHdl_Group.Fault_Count; u8_Index++)
	{
		TLF35584ErrHdl_Status.Fault_List[u8_Index].Fault_ID = TLF35584ErrHdl_Group.Fault_List[u8_Index]->Fault_ID;
		TLF35584ErrHdl_Status.Fault_List[u8_Index].Fault_Status = TLF35584ErrHdl_Fault_None;
		TLF35584ErrHdl_Status.Fault_List[u8_Index].Fault_Source = TLF35584ErrHdl_Fault_S_None;

		TLF35584ErrHdl_ClrErrRegValue(u8_Index);
	}
}

/*====================================================================================================================*/
/*                                            Global Function Implementation                                          */
/*====================================================================================================================*/
/**********************************************************************************************************************/
/*
 * FunctionName        : void TLF35584ErrHdl_Init(void)
 * Service ID          : [SWDD-17-022]
 * Sync/Async          : Synchronous
 * Reentrancy          : Non-reentrant
 * Param-Name[in]      : None
 * Param-Name[out]     : None
 * Param-Name[in/out]  : None
 * Return              : None
 * CallByAPI           : None
 * Description         : �˺������ڳ�ʼ����
 */
/**********************************************************************************************************************/
void TLF35584ErrHdl_Init(void)
{	
	TLF35584ErrHdl_ClrInfo();

	/* Startup Error Check. */
	TLF35584ErrHdl_SetHandlerFlag(TLF35584ErrHdl_Fault_S_Reset);
	TLF35584ErrHdl_SetStartupCheckFlag(TRUE);
	(void)TLF35584ErrHdl_MainFunction();
	TLF35584ErrHdl_SetHandlerFlag(TLF35584ErrHdl_Fault_S_None);
	TLF35584ErrHdl_ClrStartupCheckFlag();

	TLF35584ErrHdl_SetInitFinishFlag();
}

/**********************************************************************************************************************/
/*
 * FunctionName        : void TLF35584ErrHdl_DeInit(void)
 * Service ID          : [SWDD-17-023]
 * Sync/Async          : Synchronous
 * Reentrancy          : Non-reentrant
 * Param-Name[in]      : None
 * Param-Name[out]     : None
 * Param-Name[in/out]  : None
 * Return              : None
 * CallByAPI           : None
 * Description         : �˺������ڷ���ʼ����
 */
/**********************************************************************************************************************/
void TLF35584ErrHdl_DeInit(void)
{
	TLF35584ErrHdl_ClrInfo();
	/* Unregister NMI Trap Function. */
	TLF35584ErrHdl_SetHandlerFlag(TLF35584ErrHdl_Fault_S_None);
	
	TLF35584ErrHdl_ClrInitFinishFlag();
}

/**********************************************************************************************************************/
/*
 * FunctionName        : void TLF35584ErrHdl_NMIHandler(void)
 * Service ID          : [SWDD-17-025]
 * Sync/Async          : Synchronous
 * Reentrancy          : Non-reentrant
 * Param-Name[in]      : None
 * Param-Name[out]     : None
 * Param-Name[in/out]  : None
 * Return              : None
 * CallByAPI           : None
 * Description         : �˺���ʵ��TLF35584 Handler NMI�����ܡ�
 */
/**********************************************************************************************************************/
void TLF35584ErrHdl_IRQHandler(void)
{
	if(TLF35584ErrHdl_GetInitFinishFlag() == TRUE)/*PRQA S 3415,3760*/ /* QAC Annotation��ǿ��ת������ */
	{
		/* Trace[SWDD-17-005]:TLF35584�ж���Ӧ */
		/* Set NMI Flag. */
		TLF35584ErrHdl_SetHandlerFlag(TLF35584ErrHdl_Fault_S_IRQ);

		/*SBC Fault INIT reaction*/
		if((VAR_TLF35584_InitFinish_Flag_b == TRUE)&&(VAR_TLF35584_SelfTestFinish_Flag_b == TRUE))
		{
			(void) TLF35584ErrHdl_FaultRead();

			if( ((TLF35584ErrHdl_Reg[TLF35584_REG_MONSF1]&(0xF0))!=(0x00))||((TLF35584ErrHdl_Reg[TLF35584_REG_MONSF2]&(0xF0))!=(0x00))||((TLF35584ErrHdl_Reg[TLF35584_REG_MONSF3]&(0x30))!=(0x00)))
			{
				 /*����L3��ȫ�ض�·��*/
				(void) Smu_ActivateFSP();
			}
			else
			{

			}

		}
		else
		{

		}

	}
	else
	{
		/* Not TLF35584 NMI Request or Not Init.Skip this loop. */
	}
	
}

/**********************************************************************************************************************/
/*
 * FunctionName        : static void TLF35584ErrHdl_SetHandlerFlag(TLF35584ErrHdl_FaultSrcType Source)
 * Service ID          : [SWDD-17-024]
 * Sync/Async          : Synchronous
 * Reentrancy          : Non-reentrant
 * Param-Name[in]      : None
 * Param-Name[out]     : None
 * Param-Name[in/out]  : None
 * Return              : None
 * CallByAPI           : None
 * Description         : �˺����������ô���Դ��
 */
/**********************************************************************************************************************/
void TLF35584ErrHdl_SetHandlerFlag(TLF35584ErrHdl_FaultSrcType Source)
{
	TLF35584ErrHdl_HandlerFlag = Source;
}

/**********************************************************************************************************************/
/*
 * FunctionName        : Std_ReturnType TLF35584ErrHdl_MainFunction(void)
 * Service ID          : [SWDD-17-026]
 * Sync/Async          : Synchronous
 * Reentrancy          : Non-reentrant
 * Param-Name[in]      : None
 * Param-Name[out]     : None
 * Param-Name[in/out]  : None
 * Return              : None
 * CallByAPI           : None
 * Description         : �˺���TLF35584 Handler��⹦�ܡ�
 */
/**********************************************************************************************************************/
Std_ReturnType TLF35584ErrHdl_MainFunction(void)
{
	uint8 u8_Index;
	boolean b_Check = FALSE;
	Std_ReturnType Ret = E_OK;
/*Test Code*/



	if(TLF35584ErrHdl_GetHandlerFlag() != TLF35584ErrHdl_Fault_S_None)
	{
		/* Init Check. */
		if(((TLF35584ErrHdl_GetInitFinishFlag() == TRUE) && (TLF35584_GetInitFinishFlag() == TRUE)) || (TLF35584ErrHdl_GetStartupCheckFlag() == TRUE))/*PRQA S 3398,3390,3415,4115*//* QAC Annotation��no effect*/
		{
			/*Clear Fault Status and Error Reg[] Value*/
			TLF35584ErrHdl_ClrInfo();
			
			/* Trace[SWDD-17-002]:TLF35584���ϼ�� */
			/* Call TLF35584 Read Fault API. Read Reg and store the value in the Err Reg[] */
			if(TLF35584ErrHdl_FaultRead() == E_OK)
			{
				for(u8_Index = 0u; u8_Index < TLF35584ErrHdl_Group.Fault_Count; u8_Index++)
				{
					if(TLF35584ErrHdl_Config[u8_Index].Enable == TRUE)
					{
						/*Check if the fault is set, if set feedback NOK*/
						if(TLF35584ErrHdl_FaultParse(u8_Index) != E_OK)
						{	
							Ret |= E_NOT_OK;
							/* Capture the Fault */
							TLF35584ErrHdl_Status.Sys_Status = FALSE;
							TLF35584ErrHdl_Status.Error_Count += 1u;
							TLF35584ErrHdl_Status.Fault_List[u8_Index].Fault_Source = TLF35584ErrHdl_GetHandlerFlag();
							TLF35584ErrHdl_Status.Fault_List[u8_Index].Fault_Status = TLF35584ErrHdl_Fault_Error;
							
							if(TLF35584ErrHdl_Group.Fault_List[u8_Index]->Fault_ID == TLF35584ERRHDL_FAULT_IF_INTMISS_ID)
							{
								/* Jump this loop. */
								b_Check = TRUE;
							}
							else
							{
								/* Trace[SWDD-17-003]:TLF35584������� */
								/* Fault Clear */
								;
								/* QAC Annotation��no effect */
								/* PRQA S 715 EOF*/
								/*Write 1 to clear 35584 error register*/
								if(TLF35584ErrHdl_FaultClr(u8_Index) != E_OK)
								{
									TLF35584ErrHdl_Status.Fault_List[u8_Index].Fault_Status = TLF35584ErrHdl_Fault_Clear;
								}
								else
								{
									/* Fault Check */
									if(TLF35584ErrHdl_FaultCheck(u8_Index) != E_OK)
									{
										TLF35584ErrHdl_Status.Fault_List[u8_Index].Fault_Status = TLF35584ErrHdl_Fault_Clear;
									}
									else
									{
										
									}
								}
								/* Trace[SWDD-17-004]:TLF35584�����ϱ� */
								/* Callback Function */
								if(TLF35584ErrHdl_Config[u8_Index].Callback_Ptr != NULL_PTR)
								{
									TLF35584ErrHdl_Config[u8_Index].Callback_Ptr();
								}
								else
								{
									
								}
							}					
						}
						else
						{
							TLF35584ErrHdl_Status.Fault_List[u8_Index].Fault_Status = TLF35584ErrHdl_Fault_Success;
						}
					}
					else
					{
						
					}
				}
				/* Check INTMISS Int Flag. */
				if(b_Check == TRUE)
				{
					/* Call TLF35584 Read Fault API. */
				    if(TLF35584ErrHdl_FaultRead() == E_OK)
				    {
					    if(TLF35584ErrHdl_FaultParse(TLF35584ERRHDL_FAULT_IF_INTMISS_ID - 1) != E_OK)
					    {
					    	TLF35584ErrHdl_Status.Fault_List[TLF35584ERRHDL_FAULT_IF_INTMISS_ID - 1].Fault_Status = TLF35584ErrHdl_Fault_Clear;
					    }
					    else
					    {
							/* Callback Function */
							if(TLF35584ErrHdl_Config[TLF35584ERRHDL_FAULT_IF_INTMISS_ID - 1].Callback_Ptr != NULL_PTR)
							{
								TLF35584ErrHdl_Config[TLF35584ERRHDL_FAULT_IF_INTMISS_ID - 1].Callback_Ptr();
							}
							else
							{

							}
					    }
				    }
				    else
					{

					}
				}
				else
				{
					
				}
			}
			else
			{
				Ret = E_NOT_OK;
			}
		}
		else
		{
			Ret = E_NOT_OK;
		}
		TLF35584ErrHdl_ClrHandlerFlag();
	}
	else
	{

	}

	return Ret;
}

