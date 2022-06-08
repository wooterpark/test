/*******************************************************************************
**----------------------------------------------------------------------------**
** Copyright (c) 2018 by JEE.		All rights reserved.
** This software is copyright protected and proprietary to JEE.
** JEE grants to you only those rights as set out in the license conditions.
** All other rights remain with JEE.
**----------------------------------------------------------------------------**
**
* Administrative Information
* $Namespace_: \OsShell\OsShell_Schedule_Cfg.c$
* $Class_____: C$
* $Name______: .c$
* $Variant___: 0.0.0$
* $Revision__: 0$
* $Author____: LQ$
**
**----------------------------------------------------------------------------**
** MAY BE CHANGED BY USER [Yes/No]: No
**----------------------------------------------------------------------------**
** DESCRIPTION:


**----------------------------------------------------------------------------**
** HISTORY:
V1.0.0:   The initial release


*******************************************************************************/

/*******************************************************************************
**                      Other Header File Inclusion                           **
*******************************************************************************/
#include "OsShell_Schedule_Cfg.h"
#include "TLF35584.h"
#include "TLF35584ErrHdl.h"
#include "Stm_TimeTest.h"
#include "Cpld_Drv.h"
#include "CanSM_Priv.h"
extern void DemEnCon_ID_Update( void );
extern void rba_Reset_Monitor_Proc(void);//FJ 20200820
#define RunTstConfig STD_ON
/*******************************************************************************
**                   Static Local Variables Definition              		  **
*******************************************************************************/
uint16 OsShell_Cntr_BSW_1ms_Task_Core0_u16=0;
uint16 OsShell_Cntr_BSW_10ms_Task_Core0_u16=0;
uint16 OsShell_Cntr_BSW_10ms_Task_Core1_u16=0;
uint16 OsShell_Cntr_BSW_10ms_Task_Core2_u16=0;
uint16 OsShell_Cntr_SWC_1ms_Task_Core0_u16=0;
uint16 OsShell_Cntr_SWC_10ms_Task_Core0_u16=0;
uint16 OsShell_Cntr_SWC_20ms_Task_Core0_u16=0;
uint16 OsShell_Cntr_SWC_50ms_Task_Core0_u16=0;
uint16 OsShell_Cntr_SWC_100ms_Task_Core0_u16=0;
uint16 OsShell_Cntr_SWC_1000ms_Task_Core0_u16=0;
uint16 OsShell_Cntr_SWC_1ms_Task_Core1_u16=0;
uint16 OsShell_Cntr_SWC_10ms_Task_Core1_u16=0;
uint16 OsShell_Cntr_SWC_100ms_Task_Core1_u16=0;
uint16 OsShell_Cntr_Os_Init_Task_Core0_u16=0;
uint16 OsShell_Cntr_Os_Init_Task_Core1_u16=0;
uint16 OsShell_Cntr_Os_Init_Task_Core2_u16=0;
uint16 OsShell_Cntr_BSW_2ms_Task_Core0_u16=0;
uint16 OsShell_Cntr_BSW_5ms_Task_Core0_u16=0;
uint16 OsShell_Cntr_BSW_5ms_Task_Core1_u16=0;
uint16 OsShell_Cntr_SWC_5ms_Task_Core1_u16=0;
uint16 OsShell_Cntr_SWC_20ms_Task_Core1_u16=0;
uint16 OsShell_Cntr_SWC_50ms_Task_Core1_u16=0;
uint16 OsShell_Cntr_SWC_1000ms_Task_Core1_u16=0;
uint16 OsShell_Cntr_BSW_1ms_Task_Core1_u16=0;
uint16 OsShell_Cntr_BSW_Interact_Task_0_Core0_u16=0;
uint16 OsShell_Cntr_BSW_Interact_Task_0_Core1_u16=0;
uint16 OsShell_Cntr_BSW_Interact_Task_0_Core2_u16=0;
uint16 OsShell_Cntr_BSW_Interact_Task_1_Core0_u16=0;
uint16 OsShell_Cntr_BSW_Interact_Task_1_Core1_u16=0;
uint16 OsShell_Cntr_BSW_Interact_Task_1_Core2_u16=0;

uint32 OsShell_Cntr_Idle_Task_Core0_u32=0;
uint32 OsShell_Cntr_Idle_Task_Core1_u32=0;
uint32 OsShell_Cntr_Idle_Task_Core2_u32=0;

static st_STM_TimeType STM0_TimeData_Task[10u];

/*******************************************************************************
**                   Global Variables Definition              		  **
*******************************************************************************/
extern uint32  Xcp_SWC_Timestamp_1ms;

uint32 VAR_STM0_BSW_1ms_Task_Core0_u32;
uint32 VAR_STM0_BSW_2ms_Task_Core0_u32;
uint32 VAR_STM0_BSW_10ms_Task_Core0_u32;
uint32 VAR_STM0_SWC_10ms_Task_Core0_u32;
uint32 VAR_STM0_SWC_20ms_Task_Core0_u32;
uint32 VAR_STM0_SWC_100ms_Task_Core0_u32;
uint32 VAR_STM0_SWC_1000ms_Task_Core0_u32;

/*******************************************************************************
**                 		  Function Source Code            		              **
*******************************************************************************/

/*******************************************************************************
** Function Name	: ActiveLongPeriodTasksCore0
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	£º
** Description	  	:
*******************************************************************************/
void ActiveLongPeriodTasksCore0(void)
{
	static uint16 counter=0;
	if((counter%2)==0)
	{
		ActivateTask(SWC_20ms_Task_Core0);
	}
	if((counter%5)==0)
	{
		ActivateTask(SWC_50ms_Task_Core0);
	}
	if((counter%10)==0)
	{
		ActivateTask(SWC_100ms_Task_Core0);
	}
	if((counter%100)==0)
	{
		ActivateTask(SWC_1000ms_Task_Core0);
	}
	counter++;
	if(counter>=100)
	{
		counter=0;
	}
}
void ActiveLongPeriodTasksCore1(void)
{
	static uint16 counter=0;
	if((counter%2)==0)
	{
		ActivateTask(SWC_20ms_Task_Core1);
	}
	if((counter%5)==0)
	{
		ActivateTask(SWC_50ms_Task_Core1);
	}
	if((counter%10)==0)
	{
		ActivateTask(SWC_100ms_Task_Core1);
	}
	if((counter%100)==0)
	{
		ActivateTask(SWC_1000ms_Task_Core1);
	}
	counter++;
	if(counter>=100)
	{
		counter=0;
	}
}

/*******************************************************************************
** Function Name	: Os_Init_Task_Core0
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	£º
** Description	  	:
*******************************************************************************/
TASK(Os_Init_Task_Core0)
{
	StatusType status;
	OsShell_Cntr_Os_Init_Task_Core0_u16++;

	Rte_task_Os_Init_Task_Core0();

	status = ChainTask(Os_Init_Task_Core1);
}

TASK(Os_Init_Task_Core1)
{
	StatusType status;
	OsShell_Cntr_Os_Init_Task_Core1_u16++;

	Rte_task_Os_Init_Task_Core1();

	status =ChainTask(Os_Init_Task_Core2);
}

TASK(Os_Init_Task_Core2)
{
	StatusType status;
	OsShell_Cntr_Os_Init_Task_Core2_u16++;

	Rte_task_Os_Init_Task_Core2();

	status = TerminateTask();
}

/*******************************************************************************
** Function Name	: BSW_1ms_Task_Core0
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	£º
** Description	  	:
*******************************************************************************/
TASK(BSW_1ms_Task_Core0)
{
	StatusType status;
	Stm_Time_CaptureStart(&STM0_TimeData_Task[0u]);

	OsShell_Cntr_BSW_1ms_Task_Core0_u16++;
	Xcp_SWC_Timestamp_1ms++;
#if 0
#ifdef HIGHTEC_COMPILER
    ETK_Distab13_Process_Rxx(2, 1, 1, 1, 0x0202);/*ETK*/
#endif
#endif

	Rte_task_BSW_1ms_Task_Core0();

	Stm_Time_CaptureStop(&STM0_TimeData_Task[0u]);
	VAR_STM0_BSW_1ms_Task_Core0_u32 = STM0_TimeData_Task[0u].ui32_Interval/100;/*us*/

	status = ChainTask(SWC_1ms_Task_Core0);
}
TASK(BSW_2ms_Task_Core0)
{
	StatusType status;
	Stm_Time_CaptureStart(&STM0_TimeData_Task[1u]);
	OsShell_Cntr_BSW_2ms_Task_Core0_u16++;
	
	Rte_task_BSW_2ms_Task_Core0();

	Stm_Time_CaptureStop(&STM0_TimeData_Task[1u]);
	VAR_STM0_BSW_2ms_Task_Core0_u32 = STM0_TimeData_Task[1u].ui32_Interval/100;/*us*/

	status = TerminateTask();
}

TASK(BSW_5ms_Task_Core0)
{
	StatusType status;
	OsShell_Cntr_BSW_5ms_Task_Core0_u16++;

	/*Rte_task_BSW_5ms_Task_Core0();*/

	status = ChainTask(SWC_5ms_Task_Core0);
}

TASK(BSW_10ms_Task_Core0)
{
	StatusType status;
	Stm_Time_CaptureStart(&STM0_TimeData_Task[2u]);
	OsShell_Cntr_BSW_10ms_Task_Core0_u16++;
	CanSM_CheckTxRxNotification(0);//hlj20210309
	rba_Reset_Monitor_Proc();//FJ 20200820
	DemEnCon_ID_Update();//FJ 20200721
	Rte_task_BSW_10ms_Task_Core0();
	Cpld_State_Management();
#if 0
#ifdef HIGHTEC_COMPILER
	ETK_Distab13_Process_Rxx(3, 1, 2, 2, 0x0303);/*ETK*/
	SER_Cyclic_Handshake_Check_And_Execute();
	if (SER_ETK_Check_PAGE_SWITCH_BY_ECU() == 1) // Page switch requested
	{
		SER_ETK_PAGE_SWITCH_BY_ECU();
	}
#endif
#endif

	Stm_Time_CaptureStop(&STM0_TimeData_Task[2u]);
	VAR_STM0_BSW_10ms_Task_Core0_u32 = STM0_TimeData_Task[2u].ui32_Interval/100;/*us*/

	ActivateTask(BSW_10ms_Task_Core2);
	ChainTask(SWC_10ms_Task_Core0);

}


TASK(SWC_1ms_Task_Core0)
{
	StatusType status;

	OsShell_Cntr_SWC_1ms_Task_Core0_u16++;

	status = TerminateTask();
}


TASK(SWC_5ms_Task_Core0)
{
	StatusType status;

	status = TerminateTask();
}

TASK(SWC_10ms_Task_Core0)
{
	StatusType status;
	Stm_Time_CaptureStart(&STM0_TimeData_Task[3u]);

	OsShell_Cntr_SWC_10ms_Task_Core0_u16++;

	Rte_task_SWC_10ms_Task_Core0();

	Stm_Time_CaptureStop(&STM0_TimeData_Task[3u]);
	VAR_STM0_SWC_10ms_Task_Core0_u32 = STM0_TimeData_Task[3u].ui32_Interval/100;/*us*/

	ActiveLongPeriodTasksCore0();
	status = TerminateTask();
}

TASK(SWC_20ms_Task_Core0)
{
	StatusType status;
	Stm_Time_CaptureStart(&STM0_TimeData_Task[4u]);
	OsShell_Cntr_SWC_20ms_Task_Core0_u16++;

	Rte_task_SWC_20ms_Task_Core0();

	Stm_Time_CaptureStop(&STM0_TimeData_Task[4u]);
	VAR_STM0_SWC_20ms_Task_Core0_u32 = STM0_TimeData_Task[4u].ui32_Interval/100;/*us*/

	status = TerminateTask();
}

TASK(SWC_50ms_Task_Core0)
{
	StatusType status;
	OsShell_Cntr_SWC_50ms_Task_Core0_u16++;

	status = TerminateTask();
}


TASK(SWC_100ms_Task_Core0)
{
	StatusType status;
	Stm_Time_CaptureStart(&STM0_TimeData_Task[5u]);
	OsShell_Cntr_SWC_100ms_Task_Core0_u16++;

	Rte_task_SWC_100ms_Task_Core0();
	LvPower_Manegement();

	Stm_Time_CaptureStop(&STM0_TimeData_Task[5u]);
	VAR_STM0_SWC_100ms_Task_Core0_u32 = STM0_TimeData_Task[45u].ui32_Interval/100;/*us*/

	status = TerminateTask();
}


TASK(SWC_1000ms_Task_Core0)
{
	StatusType status;
	Stm_Time_CaptureStart(&STM0_TimeData_Task[6u]);
	OsShell_Cntr_SWC_1000ms_Task_Core0_u16++;

	Rte_task_SWC_1000ms_Task_Core0();
	SetCanWakeUpflg();              //wq 0709
	Stm_Time_CaptureStop(&STM0_TimeData_Task[6u]);
	VAR_STM0_SWC_1000ms_Task_Core0_u32 = STM0_TimeData_Task[6u].ui32_Interval/100;/*us*/

	status = TerminateTask();
}

/*******************************************************************************
** Function Name	: BSW_1ms_Task_Core1
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	£º
** Description	  	:
*******************************************************************************/
TASK(BSW_1ms_Task_Core1)
{
	StatusType status;
	OsShell_Cntr_BSW_1ms_Task_Core1_u16++;
	
	status = ChainTask(SWC_1ms_Task_Core1);
}

TASK(BSW_5ms_Task_Core1)
{
	StatusType status;
	OsShell_Cntr_BSW_5ms_Task_Core1_u16++;

	status = ChainTask(SWC_5ms_Task_Core1);
}


TASK(BSW_10ms_Task_Core1)
{
	StatusType status;
	OsShell_Cntr_BSW_10ms_Task_Core1_u16++;

	EcuM_MainFunction();
	//rba_Mpu_Sfty_Core1_Test();

	status =ChainTask(SWC_10ms_Task_Core1);
}


TASK(SWC_1ms_Task_Core1)
{
	StatusType status;
	OsShell_Cntr_SWC_1ms_Task_Core1_u16++;

	status = TerminateTask();
}


TASK(SWC_5ms_Task_Core1)
{
	StatusType status;
	OsShell_Cntr_SWC_5ms_Task_Core1_u16++;
//	Pws_WDG_MainFun();/*LQ20201017*/
	status = TerminateTask();
}

TASK(SWC_10ms_Task_Core1)
{
	StatusType status;
	OsShell_Cntr_SWC_10ms_Task_Core1_u16++;

	RE_WdgM_SWC_10ms_Core1_func();

	ActiveLongPeriodTasksCore1();
	status = TerminateTask();
}

TASK(SWC_20ms_Task_Core1)
{
	StatusType status;
	OsShell_Cntr_SWC_20ms_Task_Core1_u16++;

	status = TerminateTask();
}

volatile uint32 TLF35584_State = 0;
TASK(SWC_50ms_Task_Core1)
{
	StatusType status;
	OsShell_Cntr_SWC_50ms_Task_Core1_u16++;

		(void)TLF35584_ServiceFWD();

		(void)TLF35584_ServiceWWD();

	TLF35584_State = TLF35584ErrHdl_MainFunction();


#if(RunTstConfig == STD_ON)
	TstM_Run();
#endif

	status = TerminateTask();
}


TASK(SWC_100ms_Task_Core1)
{
	StatusType status;

	OsShell_Cntr_SWC_100ms_Task_Core1_u16++;
	status = TerminateTask();
}


TASK(SWC_1000ms_Task_Core1)
{
	StatusType status;
	OsShell_Cntr_SWC_1000ms_Task_Core1_u16++;

	status = TerminateTask();
}


/*******************************************************************************
** Function Name	: BSW_10ms_Task_Core2
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	£º
** Description	  	:
*******************************************************************************/
TASK(BSW_10ms_Task_Core2)
{
	StatusType status;
	OsShell_Cntr_BSW_10ms_Task_Core2_u16++;

	EcuM_MainFunction();
	//rba_Mpu_Sfty_Core2_Test();

	status = TerminateTask();
}

/*******************************************************************************
** Function Name	: BSW_Interact_Task_0_Core0
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	£º
** Description	  	:
*******************************************************************************/
TASK(BSW_Interact_Task_0_Core0)
{
	StatusType status;
	OsShell_Cntr_BSW_Interact_Task_0_Core0_u16++;

	status = TerminateTask();
}

TASK(BSW_Interact_Task_0_Core1)
{
	StatusType status;
	OsShell_Cntr_BSW_Interact_Task_0_Core1_u16++;

	status = TerminateTask();
}

TASK(BSW_Interact_Task_0_Core2)
{
	StatusType status;
	OsShell_Cntr_BSW_Interact_Task_0_Core2_u16++;

	status = TerminateTask();
}

TASK(BSW_Interact_Task_1_Core0)
{
	StatusType status;
	OsShell_Cntr_BSW_Interact_Task_1_Core0_u16++;

	status = TerminateTask();
}

TASK(BSW_Interact_Task_1_Core1)
{
	StatusType status;
	OsShell_Cntr_BSW_Interact_Task_1_Core1_u16++;
	status = TerminateTask();
}

TASK(BSW_Interact_Task_1_Core2)
{
	StatusType status;
	OsShell_Cntr_BSW_Interact_Task_1_Core2_u16++;

	status = TerminateTask();
}

TASK(BSW_Idle_Task_Core0)
{
    StatusType status;
    while(1)
    {
        OsShell_Cntr_Idle_Task_Core0_u32++;
        Test_CpuLoadCalc();

        SnapshotDu_MainFunction(); /* 2020-08-12 */
    }
}

TASK(BSW_Idle_Task_Core1)
{
	StatusType status;
	while(1)
	{
		OsShell_Cntr_Idle_Task_Core1_u32++;
		Test_CpuLoadCalc();
	}

}
TASK(BSW_Idle_Task_Core2)
{
	StatusType status;
	while(1)
	{
		OsShell_Cntr_Idle_Task_Core2_u32++;
		Test_CpuLoadCalc();
	}

}
