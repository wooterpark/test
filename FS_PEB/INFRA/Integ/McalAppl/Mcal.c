
#include "Mcal.h"



#ifdef _TASKING_C_TRICORE_
#if (_TASKING_C_TRICORE_ == 1U)
#define DEBUG()  __debug()
#endif /* #if (_TASKING_C_TRICORE_ == 1U) */
#endif

#ifdef _GNU_C_TRICORE_
#if (_GNU_C_TRICORE_ == 1U)
#define DEBUG() __asm__ volatile ("debug")
#endif /* #if (_GNU_C_TRICORE_ == 1U) */
#endif

#ifdef _DIABDATA_C_TRICORE_
#if (_DIABDATA_C_TRICORE_ == 1U)
#define DEBUG() __debug()
#define __debug _debug
#endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
#endif


/*******************************************************************************
** Syntax           : void Mcal_SafeErrorHandler(uint32 ErrorType)            **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : ErrorType                                               **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This is an Error handler function which can be called   **
                      in two conditions                                       **
** 1. Any detection of inconsistency in copies of relevant global variables   **
**    is reported to the user via the function Mcal_SafeErrorHandler.         **
**    Mcal_SafeErrorHandler shall never return, else it may lead to           **
**    unpredictable behavior.The user is expected to perform the error        **
**    handling in this function.                                              **
**                                                                            **
**    The error reported is MCAL_DIV_INCONSISTENCY:Typical error reactions    **
**    could be to reset the microcontroller (software reset)                  **
**                                                                            **
** 2. Support functions are called to access the protected registers,         **
**    these functions can be called from multiple cores concurrently, a       **
**    spinlock mechanism with timeout is provided. In case, the timeout       **
**    expires, it is reported to the user via Mcal_SafeErrorHandler.          **
**    The user is expected to perform the error handling in this function.    **
**                                                                            **
**    The error reported is MCAL_SPINLOCK_TIMEOUT:Typical error reactions     **
**    could be to the terminate the operating system task or restart the      **
**    partition or reset the microcontroller.                                 **
**                                                                            **
**    This funtion is written here only to avoid build error.                 **
**    The user needs to implement this functionality (Mcal_SafeErrorHandler)  **
**    in a separate file and needs to add this file as part of the build.     **
**                                                                            **                                                                                                                                 **
*******************************************************************************/
#define MCAL_START_SEC_CODE
#include "MemMap.h"
void Mcal_SafeErrorHandler(uint32 ErrorType)
{
  volatile uint32 TimeOut;

  TimeOut = 0U;
  /* User can add the code here */
  UNUSED_PARAMETER(ErrorType)
  /* While loop added for UTP AI00252128 */
  while(TimeOut < 0xFFFFFFFFU)
  {
    TimeOut++;
  }
  /* Control should not reach here. WDG timeout happens before this. */
  DEBUG();

}
#define MCAL_STOP_SEC_CODE
#include "MemMap.h"
