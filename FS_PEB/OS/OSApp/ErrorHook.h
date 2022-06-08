/*
 * ErrorHook.h
 *
 *  Created on: Aug 15, 2017
 *      Author: puy1hc
 */

#ifndef TARGETS_TC275_RTOS_OS_SC3_PROAPP_INC_ERRORHOOK_H_
#define TARGETS_TC275_RTOS_OS_SC3_PROAPP_INC_ERRORHOOK_H_

#define	ERR_LOG_MAX	(20)

typedef	struct {
	uint32 	     errCount;
	StatusType	 errType;
	ISRType      isr;
	TaskType     task;
} Os_ErrorLog;

#define	OS_WRITABLE_START_SEC_VAR_NOINIT_32BIT
#include "MemMap.h"
extern Os_ErrorLog 		err_log[ERR_LOG_MAX];
extern uint32	 	    err_cnt;

#define	OS_WRITABLE_STOP_SEC_VAR_NOINIT_32BIT
#include "MemMap.h"

#endif /* TARGETS_TC275_RTOS_OS_SC3_PROAPP_INC_ERRORHOOK_H_ */
