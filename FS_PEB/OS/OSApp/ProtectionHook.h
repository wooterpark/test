/*
 * ProtectionHook.h
 *
 *  Created on: Aug 15, 2017
 *      Author: puy1hc
 */

#ifndef TARGETS_TC275_RTOS_OS_SC3_PROAPP_INC_PROTECTIONHOOK_H_
#define TARGETS_TC275_RTOS_OS_SC3_PROAPP_INC_PROTECTIONHOOK_H_

#define	MEM_PROTECTION_LOG_MAX	(20)
typedef	struct {
	uint32 	     cntMemProtection;
	ISRType      isr;
	TaskType     task;
} Os_MemProtectionLog;

#define	OS_WRITABLE_START_SEC_VAR_NOINIT_32BIT
#include "MemMap.h"
extern Os_MemProtectionLog mem_protection_log[MEM_PROTECTION_LOG_MAX];
extern uint32 	    mem_protection_cnt;
#define	OS_WRITABLE_STOP_SEC_VAR_NOINIT_32BIT
#include "MemMap.h"

#endif /* TARGETS_TC275_RTOS_OS_SC3_PROAPP_INC_PROTECTIONHOOK_H_ */
