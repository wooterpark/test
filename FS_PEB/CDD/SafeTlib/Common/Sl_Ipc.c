/*******************************************************************************
** Copyright (C) Infineon Technologies (2012)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**  $FILENAME   : Sl_Ipc.c $                                                 **
**                                                                           **
**  $CC VERSION : \main\22 $                                                 **
**                                                                           **
**  $DATE       : 2016-02-16 $                                               **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon AURIX                                                **
**                                                                            **
**  COMPILER  : Tasking                                                       **
**                                                                            **
**  AUTHOR    : SafeTlib Team                                                 **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  TRACEABILITY:                                                             **
**                                                                            **
** Description      : This file contains                                      **
**                 - Mcal library definitions                                 **
**                                                                            **
**                                                                            **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [Yes/No]: No                                       **
**                                                                            **
*******************************************************************************/

/******************************************************************************
**                      Includes                                              *
******************************************************************************/
#include "Platform_Types.h"
#include "Compiler_Cfg.h"
#include "Mcal_TcLib.h"
#include "Sl_Ipc.h"
#include "Mcal_Options.h"

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
#define SL_IPC_REDUNDANT_RESULT   (0xFFFFFFFFU)


/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/



/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/



/*******************************************************************************
**      Global Variable Definitions                                           **
*******************************************************************************/
#if (IFX_SAFETLIB_USED == STD_ON)
#define IFX_APPL_START_SEC_VAR_32BIT_ASIL_B
#include "Ifx_MemMap.h"
#else
#define APPL_START_SEC_VAR_32BIT
#include "MemMap.h"
#endif

/* All the spinlocks to be defined here */
#ifdef __TASKING__
__align(4) static uint32 Sl_SpinLockArr[SL_SPINLOCK_CNT];
__align(4) static uint32 Sl_SpinLockRednArr[SL_SPINLOCK_CNT];
#elif __GNUC__
static uint32 Sl_SpinLockArr[SL_SPINLOCK_CNT] __attribute__ ((aligned(4)));
static uint32 Sl_SpinLockRednArr[SL_SPINLOCK_CNT] __attribute__ ((aligned(4)));
#elif defined _DIABDATA_C_TRICORE_
#if (_DIABDATA_C_TRICORE_ == 1U)
static uint32 Sl_SpinLockArr[SL_SPINLOCK_CNT] __attribute__ ((aligned(4)));
static uint32 Sl_SpinLockRednArr[SL_SPINLOCK_CNT] __attribute__ ((aligned(4)));
#endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
#endif

#if (IFX_SAFETLIB_USED == STD_ON)
#define IFX_APPL_STOP_SEC_VAR_32BIT_ASIL_B
#include "Ifx_MemMap.h"
#else
#define APPL_STOP_SEC_VAR_32BIT
#include "MemMap.h"
#endif

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

#if (IFX_SAFETLIB_USED == STD_ON)
#define IFX_APPL_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
#else
#define APPL_START_SEC_CODE
#include "MemMap.h"
#endif

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : void Sl_SpinLockInit(void)                              **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters(in)   :  None                                                   **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      :                                                         **
**                                                                            **
*******************************************************************************/
void Sl_SpinLockInit()
{
  uint32 Cnt;

  for(Cnt = 0U; Cnt < (uint32)SL_SPINLOCK_CNT; Cnt++)
  {
    Sl_SpinLockArr[Cnt] = 0U;
    /* Redundant copy handling */
    Sl_SpinLockRednArr[Cnt] = (uint32)0xFFFFFFFFU;
  }
}


/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : Std_ReturnType Sl_GetSpinLock                           **
**                    (                                                       **
**                      SlSpnlockId SpinLckID,uint32 Timeout                  **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters(in)   : SpinLckID: Spinlock to be acquired                      **
**                    Timeout: Wait duration for acquisition of SpinLock      **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : E_OK - Release acquired successfully                    **
**                  : E_NOT_OK - Release not acquired successfully due to     **
**                    timeout or wrong parameter                              **
**                                                                            **
** Description      :                                                         **
**                                                                            **
*******************************************************************************/
Std_ReturnType Sl_GetSpinLock(const SlSpnlockId SpinLckID,uint32 Timeout)
{
  Std_ReturnType RetVal;

  RetVal = E_NOT_OK;

  if (SpinLckID < SL_SPINLOCK_CNT)
  {


      RetVal = Mcal_GetSpinLock(&Sl_SpinLockArr[SpinLckID],Timeout);
      if (RetVal == E_OK)
      {
          /* Verify against the redundant copy */
         if (((Sl_SpinLockArr[SpinLckID]-1U) ^ Sl_SpinLockRednArr[SpinLckID])
                          == SL_IPC_REDUNDANT_RESULT)
           {
               Sl_SpinLockRednArr[SpinLckID] = 
                Sl_SpinLockRednArr[SpinLckID] - (uint32)1U;
           }
         else
           {
             RetVal = E_NOT_OK;
           }

      }

  }

  return(RetVal);
}

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : void Sl_ReleaseSpinLock                                 **
**                    (                                                       **
**                      SlSpnlockId SpinLckID                                 **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters(in)   : SpinLckID: Spinlock to be released                      **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      :                                                         **
**                                                                            **
*******************************************************************************/
void Sl_ReleaseSpinLock(SlSpnlockId SpinLckID)
{
  if (SpinLckID < SL_SPINLOCK_CNT)
  {
    /* no check for redundancy required, if corruption happens
     * next acquire will catch the corruption
     */
    Sl_SpinLockRednArr[SpinLckID] = 
                Sl_SpinLockRednArr[SpinLckID] + (uint32)1U;
    /* Reset the SpinLock*/
    Mcal_ReleaseSpinLock(&Sl_SpinLockArr[SpinLckID]);

  }
}

#if (IFX_SAFETLIB_USED == STD_ON)
#define IFX_APPL_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
#else
#define APPL_STOP_SEC_CODE
#include "MemMap.h"
#endif
