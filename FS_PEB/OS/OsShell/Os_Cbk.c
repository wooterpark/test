/*
 * Os_Cbk.c
 *
 *  Created on: Jun 27, 2017
 *      Author: ogd1hc
 */

#include "Os_Cbk.h"

#define	OS_WRITABLE_START_SEC_VAR_NOINIT_32BIT
#include "Os_MemMap.h"
uint32 Os_pretask_starts[OS_NUM_TASKS]; /* count the number of task execution,
 	 	 	 	 	 	 	 	 	 	 not including resuming from preemption */
Os_StopwatchTickType Os_posttask_max_exe_time[OS_NUM_TASKS]; /* log maximum execution time of each task */
TaskType Os_CurrentTask[OS_NUM_CORES];
uint32 Os_task_errs[OS_NUM_TASKS];
#define	OS_WRITABLE_STOP_SEC_VAR_NOINIT_32BIT
#include "Os_MemMap.h"


#define OS_START_SEC_CALLOUT_CODE
#include "Os_MemMap.h"

Os_StopwatchTickType Os_Cbk_GetStopwatch(void)
{
	return (Os_StopwatchTickType) STM0_TIM0.U;
}

FUNC(void, OS_CALLOUT_CODE) Os_Cbk_Disable_SystemTimer_ISR(void)
{
	Os_Disable_SystemTimer_ISR();
}
FUNC(void, OS_CALLOUT_CODE) Os_Cbk_Disable_STM_OsCounter_Core2(void)
{
	Os_Disable_STM_OsCounter_Core2();
}
FUNC(void, OS_CALLOUT_CODE) Os_Cbk_Disable_ADC0SR0_ISR(void)
{
	Os_Disable_ADC0SR0_ISR();
}
FUNC(void, OS_CALLOUT_CODE) Os_Cbk_Disable_ADC0SR1_ISR(void)
{
	Os_Disable_ADC0SR1_ISR();
}
FUNC(void, OS_CALLOUT_CODE) Os_Cbk_Disable_ADC1SR1_ISR(void)
{
	Os_Disable_ADC1SR1_ISR();
}

FUNC(void, OS_CALLOUT_CODE) Os_Cbk_Disable_ADC2SR1_ISR(void)
{
	Os_Disable_ADC2SR1_ISR();
}

FUNC(void, OS_CALLOUT_CODE) Os_Cbk_Disable_ADC3SR1_ISR(void)
{
	Os_Disable_ADC3SR1_ISR();
}

FUNC(void, OS_CALLOUT_CODE) Os_Cbk_Disable_ADC4SR1_ISR(void)
{
	Os_Disable_ADC4SR1_ISR();
}

FUNC(void, OS_CALLOUT_CODE) Os_Cbk_Disable_ADC5SR1_ISR(void)
{
	Os_Disable_ADC5SR1_ISR();
}
FUNC(void, OS_CALLOUT_CODE) Os_Cbk_Disable_DSADCSRM4_ISR(void)
{
	Os_Disable_DSADCSRM4_ISR();
}

FUNC(void, OS_CALLOUT_CODE) Os_Cbk_Disable_WdgGptSrvISR(void)
{
    Os_Disable_WdgGptSrvISR();
}

FUNC(void, OS_CALLOUT_CODE) Os_Cbk_Disable_GTMTOM0SR0_ISR(void)
{
	Os_Disable_GTMTOM0SR0_ISR();
}
FUNC(void, OS_CALLOUT_CODE) Os_Cbk_Disable_GTMTOM0SR1_ISR(void)
{
	Os_Disable_GTMTOM0SR1_ISR();
}
FUNC(void, OS_CALLOUT_CODE) Os_Cbk_Disable_GTMTOM0SR7_ISR(void)
{
	Os_Disable_GTMTOM0SR7_ISR();
}

FUNC(void, OS_CALLOUT_CODE) Os_Cbk_Disable_GTMTOM2SR6_ISR(void)
{
	Os_Disable_GTMTOM2SR6_ISR();
}

FUNC(void, OS_CALLOUT_CODE) Os_Cbk_Disable_DMACH30SR_ISR(void)
{
	Os_Disable_DMACH30SR_ISR();
}

FUNC(void, OS_CALLOUT_CODE) Os_Cbk_Disable_DMACH31SR_ISR(void)
{
	Os_Disable_DMACH31SR_ISR();
}


FUNC(void, OS_CALLOUT_CODE) Os_Cbk_Disable_QSPI2ERR_ISR(void)
{
	Os_Disable_QSPI2ERR_ISR();
}

FUNC(void, OS_CALLOUT_CODE) Os_Cbk_Disable_GTMATOM3SR2_ISR(void)
{
	Os_Disable_GTMATOM3SR2_ISR();
}

FUNC(void, OS_CALLOUT_CODE) Os_Cbk_Disable_GTMTIM0SR5_ISR(void)
{
	Os_Disable_GTMTIM0SR5_ISR();
}
FUNC(void, OS_OS_CBK_DISABLE_SCUERUSR0_ISR_CODE) Os_Cbk_Disable_SCUERUSR0_ISR(void)
{
	Os_Disable_SCUERUSR0_ISR();
}
FUNC(void, OS_CALLOUT_CODE) Os_Cbk_Disable_NMI_Trap(void)
{
	uint32 CoreID;
	/* MISRA RULE 1.2, 2,2 VIOLATION:  This is a OS Function*/
	CoreID = GetCoreID() ;
	(void)Mcal_ResetCpuENDINIT(-1);
	(void)Mcal_ResetCpuENDINIT( (sint8)CoreID );

	MODULE_SCU.TRAPDIS.B.ESR1T = 0;

	(void)Mcal_SetCpuENDINIT( (sint8)CoreID );
	(void)Mcal_SetCpuENDINIT(-1);
}

/* additional pre-task hook, will not be called when the task resumes from preemption */
FUNC(void, OS_CALLOUT_CODE) Os_Cbk_TaskStart(TaskType task)
{
  Os_pretask_starts[OS_TASKTYPE_TO_INDEX(task)] += 1U;
}

/* additional post-task hook, will not be called when the task is preempted */
FUNC(void, OS_CALLOUT_CODE) Os_Cbk_TaskEnd(TaskType task)
{
  Os_posttask_max_exe_time[OS_TASKTYPE_TO_INDEX(task)] =
		  GetTaskMaxExecutionTime(task) * (uint8)OSSWTICKDURATION; /* in nanoseconds */
}

FUNC(void, OS_CALLOUT_CODE) App_Cbk_MemProtection(StatusType ErrorType, TaskType TaskInError, ISRType ISRInError)
{
	StatusType Status_Type;
	ISRType ISR_Type;
	ISR_Type = ISRInError;
	Status_Type = ErrorType;
	if(TaskInError != INVALID_TASK)
	{
		Os_task_errs[OS_TASKTYPE_TO_INDEX(TaskInError)] += 1U;
	}
}

FUNC(void, OS_CALLOUT_CODE)ShutdownHook(StatusType Error)
{
	StatusType Status_Type;
	Status_Type = Error;
	(void)EcuM_Shutdown();
}


FUNC(void, OS_CALLOUT_CODE) Os_Cbk_Terminated_SystemTimer_ISR(void)
{
	/* Reset the interrupt pending flag */
	STM0_ISCR.B.CMP0IRR = 1;
}


FUNC(void, OS_CALLOUT_CODE) Os_Cbk_Terminated_STM_OsCounter_Core2(void)
{
	/* Reset the interrupt pending flag */
	STM1_ISCR.B.CMP0IRR = 1;
}

FUNC(void, OS_CALLOUT_CODE) Os_Cbk_Terminated_ADC0SR0_ISR(void)
{
	/* Request Clear Bit */
	SRC_VADCG0SR0.B.CLRR = 1;
}
FUNC(void, OS_CALLOUT_CODE) Os_Cbk_Terminated_ADC0SR1_ISR(void)
{
	/* Request Clear Bit */
	SRC_VADCG0SR1.B.CLRR = 1;
}
FUNC(void, OS_CALLOUT_CODE) Os_Cbk_Terminated_ADC1SR1_ISR(void)
{
	/* Request Clear Bit */
	SRC_VADCG1SR1.B.CLRR = 1;
}

FUNC(void, OS_CALLOUT_CODE) Os_Cbk_Terminated_ADC2SR1_ISR(void)
{
	/* Request Clear Bit */
	SRC_VADCG2SR1.B.CLRR = 1;
}

FUNC(void, OS_CALLOUT_CODE) Os_Cbk_Terminated_ADC3SR1_ISR(void)
{
	/* Request Clear Bit */
	SRC_VADCG3SR1.B.CLRR = 1;
}

FUNC(void, OS_CALLOUT_CODE) Os_Cbk_Terminated_ADC4SR1_ISR(void)
{
	/* Request Clear Bit */
	SRC_VADCG4SR1.B.CLRR = 1;
}
FUNC(void, OS_CALLOUT_CODE) Os_Cbk_Terminated_ADC5SR1_ISR(void)
{
	/* Request Clear Bit */
		SRC_VADCG5SR1.B.CLRR = 1;
}

FUNC(void, OS_CALLOUT_CODE) Os_Cbk_Terminated_DSADCSRM4_ISR(void)
{
	/* Request Clear Bit */
		SRC_DSADCSRM4.B.CLRR = 1;
}
FUNC(void, OS_CALLOUT_CODE) Os_Cbk_Terminated_GTMTOM0SR0_ISR(void)
{
	SRC_GTMTOM00.B.CLRR = 1;
}
FUNC(void, OS_CALLOUT_CODE) Os_Cbk_Terminated_GTMTOM0SR1_ISR(void)
{
	SRC_GTMTOM01.B.CLRR = 1;
}
FUNC(void, OS_CALLOUT_CODE) Os_Cbk_Terminated_GTMTOM0SR7_ISR(void)
{
	/* Request Clear Bit */
	SRC_GTMTOM07.B.CLRR = 1;
}

FUNC(void, OS_CALLOUT_CODE) Os_Cbk_Terminated_GTMTOM2SR6_ISR(void)
{
	/* Request Clear Bit */
	SRC_GTMTOM26.B.CLRR = 1;
}

FUNC(void, OS_CALLOUT_CODE) Os_Cbk_Terminated_WdgGptSrvISR(void)
{
    SRC_GTMATOM30.B.CLRR = 1;
}
FUNC(void, OS_CALLOUT_CODE) Os_Cbk_Terminated_DMACH30SR_ISR(void)
{
	/* Request Clear Bit */
	SRC_DMACH30.B.CLRR = 1;
}

FUNC(void, OS_CALLOUT_CODE) Os_Cbk_Terminated_DMACH31SR_ISR(void)
{
	/* Request Clear Bit */
	SRC_DMACH31.B.CLRR = 1;
}


FUNC(void, OS_CALLOUT_CODE) Os_Cbk_Terminated_QSPI2ERR_ISR(void)
{
	/* Request Clear Bit */
	SRC_QSPI2ERR.B.CLRR = 1;
}

FUNC(void, OS_CALLOUT_CODE) Os_Cbk_Terminated_GTMATOM3SR2_ISR(void)
{
	/* Request Clear Bit */
		SRC_GTMATOM32.B.CLRR = 1;
}

FUNC(void, OS_CALLOUT_CODE) StartupHook_OsAppCore0(void)
{

}

FUNC(void, OS_CALLOUT_CODE) ShutdownHook_OsAppCore0(StatusType Error)
{
	StatusType Status_Type;
	Status_Type = Error;
}

FUNC(void, OS_CALLOUT_CODE) StartupHook_OsAppCore1(void)
{

}

FUNC(void, OS_CALLOUT_CODE) ShutdownHook_OsAppCore1(StatusType Error)
{
	StatusType Status_Type;
	Status_Type = Error;
}


#define OS_STOP_SEC_CALLOUT_CODE
#include "Os_MemMap.h"
