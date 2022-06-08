/*
 * Os_Cbk.h
 *
 *  Created on: Aug 15, 2017
 *      Author: puy1hc
 */

#ifndef TARGETS_TC275_RTOS_API_OS_CBK_H_
#define TARGETS_TC275_RTOS_API_OS_CBK_H_
#include <Os.h>
#include <Os_DisableInterrupts.h>
#include "Mcal_Compiler.h"
#include "IfxStm_reg.h"
#include "IfxScu_reg.h"
#include "IfxCPU_reg.h"
#include "Irq.h"
#include "EcuM.h"
#define	OS_WRITABLE_START_SEC_VAR_NOINIT_32BIT
#include "Os_MemMap.h"
extern uint32 Os_pretask_starts[OS_NUM_TASKS]; /* count the number of task execution,
 	 	 	 	 	 	 	 	 	 	 not including resuming from preemption */
extern Os_StopwatchTickType Os_posttask_max_exe_time[OS_NUM_TASKS]; /* log maximum execution time of each task */
extern TaskType Os_CurrentTask[OS_NUM_CORES];
extern uint32 Os_task_errs[OS_NUM_TASKS];
#define	OS_WRITABLE_STOP_SEC_VAR_NOINIT_32BIT
#include "Os_MemMap.h"

#define OS_START_SEC_CALLOUT_CODE
#include "Os_MemMap.h"

extern FUNC(void, OS_CALLOUT_CODE) App_Cbk_MemProtection(StatusType ErrorType, TaskType TaskInError, ISRType ISRInError);

#define OS_STOP_SEC_CALLOUT_CODE
#include "Os_MemMap.h"
#endif /* TARGETS_TC275_RTOS_API_OS_CBK_H_ */
