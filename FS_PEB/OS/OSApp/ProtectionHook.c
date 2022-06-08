/**
*
* \file
*
* \brief
*
* Copyright ETAS GmbH, Stuttgart.
*
* This file is covered by the licence and disclaimer document which is attached in
* the software package.
*
* Sample code showing how to determine what fault has occurred, and the source
* of the fault.
*
* \version $Id: ProtectionHook.c 155 2018-03-13 10:15:45Z SDM9FE $
*
******************************************************************************/

#include <Os.h>
#include "ProtectionHook.h"
#include "Os_Cbk.h"
#include "rba_BswSrv.h"
#define	OS_WRITABLE_START_SEC_VAR_NOINIT_32BIT
#include "MemMap.h"
#include "rba_Reset.h"//FJ 20200819
Os_MemProtectionLog mem_protection_log[MEM_PROTECTION_LOG_MAX];
uint32 	    mem_protection_cnt;
#define	OS_WRITABLE_STOP_SEC_VAR_NOINIT_32BIT
#include "MemMap.h"

#define OS_START_SEC_CALLOUT_CODE
#include "MemMap.h"
FUNC(ProtectionReturnType, OS_CALLOUT_CODE) ProtectionHook(StatusType FatalError)
{
  ISRType              ISRInError;
  TaskType             TaskInError;
  ProtectionReturnType action = PRO_SHUTDOWN;
  Os_MemProtectionLog* mpip;
  StatusType Status_Type;
  /*
   * This code sample shows how to determine which Task or
   * ISR was running when the fault occurred.
   */
  RBA_BSWSRV_DEBUG_HALT();
  ISRInError = GetISRID();
  if (ISRInError != INVALID_ISR) 
  {
    /* The fault occurred when ISR 'ISRInError' was running */
  } else 
  {
	  Status_Type = GetTaskID(&TaskInError);
    if (TaskInError != INVALID_TASK) 
	{
      /* The fault occurred when Task 'TaskInError' was running */
    } else 
	{
      /* The fault occurred during StartOS, Os_Cbk_Idle or ShutdownOS */
    }
  }

  switch (FatalError)
  {
    case E_OS_PROTECTION_MEMORY:
      /* A memory protection error has been detected */
		{
			mpip =  &mem_protection_log[mem_protection_cnt % (uint8)MEM_PROTECTION_LOG_MAX];
			mpip->cntMemProtection = mem_protection_cnt;
			mem_protection_cnt++;
			mpip->isr                = ISRInError;
			mpip->task               = TaskInError;
		}
	  App_Cbk_MemProtection(FatalError, TaskInError, ISRInError);
      action = PRO_TERMINATETASKISR;
      rba_Reset_Request(RBA_RESET_GRP_TRAP,RBA_RESET_TRAP_E_OS_PROTECTION_MEMORY,(uint32)0x0000);
      break;

    case E_OS_PROTECTION_TIME:
      /* Task exceeds its execution time budget OR A Category 2 ISR exceeds its execution time */
      action = PRO_TERMINATETASKISR;
      rba_Reset_Request(RBA_RESET_GRP_TRAP,RBA_RESET_TRAP_E_OS_PROTECTION_TIME,(uint32)0x0000);
      break;

    case E_OS_PROTECTION_ARRIVAL:
      /* Task/Category 2 arrives before its timeframe has expired */
      action = PRO_IGNORE; /* This is the only place where PRO_IGNORE is legal */
      rba_Reset_Request(RBA_RESET_GRP_TRAP,RBA_RESET_TRAP_E_OS_PROTECTION_ARRIVAL,(uint32)0x0000);
      break;

    case E_OS_PROTECTION_LOCKED:
      /* Task/Category 2 ISR blocks for too long */
      action = PRO_TERMINATEAPPL;
      rba_Reset_Request(RBA_RESET_GRP_TRAP,RBA_RESET_TRAP_E_OS_PROTECTION_LOCKED,(uint32)0x0000);
      break;

    case E_OS_PROTECTION_EXCEPTION:
      /* Trap occurred */
      action = PRO_SHUTDOWN;
      rba_Reset_Request(RBA_RESET_GRP_TRAP,RBA_RESET_TRAP_E_OS_PROTECTION_EXCEPTION,(uint32)0x0000);
      break;
    default:
      break;
  }
  return action;
}
#define OS_STOP_SEC_CALLOUT_CODE
#include "MemMap.h"

